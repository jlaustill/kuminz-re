#!/bin/bash
# update_odometer.sh - Restore the CM848D ECU's internal distance counters
#
# WHY: HP Tuners flashing wipes the ECU's EEPROM runtime data, zeroing the
# distance counters the ECU answers J1939 Vehicle Distance (PGN 65248) with.
# An ELD then reads 0 miles. This tool restores those counters to the real
# mileage on the owner's own truck so the J1939 distance matches the dash
# again. It does NOT change the instrument-cluster odometer and is not a
# rollback tool - it writes the value up to the true reading.
#
# ---------------------------------------------------------------------------
# CORRECTED 2026-11-13 (PR #46). The previous version wrote the WRONG place:
#   * EEPROM 0x0BD8 is the stored ACTIVE DIAGNOSTIC TROUBLE CODE LIST
#     (active_dtc_count + active_dtc_slot_list), not an odometer. Writing a
#     mileage there corrupts the fault memory (e.g. 293,199 mi would set the
#     active-fault count to 139). This tool now refuses to touch 0x0BD8.
#   * EEPROM 0x1A84 is unrelated and past the app's mirrored EEPROM region.
#
# The ECU's real distance counters, verified across four EEPROM dumps (they
# move together and HP Tuners zeroes them):
#   EEPROM 0x08EA  lifetime_distance_pulses   u32, 8000 pulses/mile
#                  -> this is what PGN 65248 (total vehicle distance) reports
#   EEPROM 0x19A6  trip distance copy          u32, same unit
#   EEPROM 0x19CE  lifetime_distance_8_mile_record  4 x u16 ring,
#                  each = lifetime pulses / 64000 (= miles / 8)
#
# Block checksum (EEPROM 0x005C) is SELF-HEALING: the ECU recomputes the
# 16-bit sum of EEPROM 0x08EA-0x1A3D at each engine-start-completion and
# stores it back. After this write the checksum fault (system_faults 0x40)
# may be set until the next key cycle, then the ECU re-stores it. This tool
# therefore does not forge a checksum the ECU would immediately overwrite.
#
# Source for the real mileage:
#   * pass it on the command line, or
#   * --from-dash copies the cluster odometer the ECU already holds in RAM at
#     0x0040B471 (received over PCI header 0x72, u32 pulses, same 8000/mile
#     unit). Confirm that value against the dash before trusting it.
#
# STATUS: the target addresses are proven from the firmware and the four
# dumps; the write itself has NOT been bench-tested. Read-modify-verify and
# keep a fresh EEPROM dump before running.
#
# Usage:
#   ./update_odometer.sh <can_interface> <miles>
#   ./update_odometer.sh <can_interface> --from-dash
#   ./update_odometer.sh <can_interface> <miles> --dry-run
#     e.g.  ./update_odometer.sh can0 293199
#           ./update_odometer.sh can0 --from-dash --dry-run

set -euo pipefail

KUMINZ_CLI="${KUMINZ_CLI:-/home/linux/code/kuminz-re/kuminz-cli/build/kuminz-cli}"

# EEPROM/RAM addresses (CLIP address space: EEPROM = 0x01000000 + offset)
LIFETIME_ADDR="010008EA"   # u32 lifetime_distance_pulses (EEPROM 0x08EA)
TRIP_ADDR="010019A6"       # u32 trip distance copy       (EEPROM 0x19A6)
RING_ADDR="010019CE"       # 4 x u16 eight-mile record    (EEPROM 0x19CE)
CHECKSUM_ADDR="0100005C"   # u16 block checksum (read-only reference)
DTC_LIST_ADDR="01000BD8"   # EEPROM 0x0BD8 = active DTC list - NEVER written
DASH_ODO_RAM="0040B471"    # RAM: cluster odometer (u32 pulses, PCI 0x72)

PULSES_PER_MILE=8000
RING_DIVISOR=64000         # lifetime pulses / 64000 = miles / 8
RING_ENTRIES=4
MAX_MILES=536870           # u32 pulse limit / 8000

usage() {
    cat <<EOF
CM848D ECU Distance-Counter Restore Tool

Usage: $0 <can_interface> <miles | --from-dash> [--dry-run]

  can_interface   CAN interface (e.g. can0)
  miles           Odometer value in whole miles
  --from-dash     Read the cluster odometer the ECU holds in RAM (0x${DASH_ODO_RAM})
                  and use it instead of a typed value
  --dry-run       Show every write without sending anything

Writes (EEPROM offset -> meaning):
  0x08EA  lifetime distance (u32, 8000 pulses/mile) -> J1939 PGN 65248
  0x19A6  trip distance copy (u32)
  0x19CE  eight-mile record ring (4 x u16 = miles/8)

Does NOT write 0x0BD8 (the active DTC list) or the dash cluster.
Max: ${MAX_MILES} miles.
EOF
    exit 1
}

[ $# -lt 2 ] && usage

CAN_IF="$1"; shift
MILES=""
FROM_DASH=0
DRY_RUN=0
for arg in "$@"; do
    case "$arg" in
        --from-dash) FROM_DASH=1 ;;
        --dry-run)   DRY_RUN=1 ;;
        [0-9]*)      MILES="$arg" ;;
        *) echo "[ERROR] Unknown argument: $arg"; usage ;;
    esac
done

if [ ! -x "$KUMINZ_CLI" ]; then
    echo "[ERROR] kuminz-cli not found at: $KUMINZ_CLI"
    echo "        Build it: cd kuminz-cli/build && cmake .. && make -j4"
    exit 1
fi

# Read a u32 (big-endian) at a CLIP/RAM address; echoes the decimal value or empty.
read_u32() {
    local addr="$1" hex
    hex=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$addr" 4 2>/dev/null \
            | tail -1 | tr -d ' \t' | sed -E 's/^0[xX]//' | tr -dc '0-9A-Fa-f') || true
    [ "${#hex}" -ge 8 ] && echo $(( 16#${hex:0:8} )) || echo ""
}

# Resolve the target pulse count.
if [ "$FROM_DASH" -eq 1 ]; then
    echo "[*] Reading the cluster odometer from ECU RAM 0x${DASH_ODO_RAM}..."
    DASH_PULSES=$(read_u32 "$DASH_ODO_RAM")
    if [ -z "$DASH_PULSES" ] || [ "$DASH_PULSES" -eq 0 ]; then
        echo "[ERROR] Could not read a valid dash odometer (got: '${DASH_PULSES:-none}')."
        echo "        The ECU may not have received a PCI 0x72 frame yet. Pass miles instead."
        exit 1
    fi
    RAW_U32=$DASH_PULSES
    MILES=$(( RAW_U32 / PULSES_PER_MILE ))
    echo "    Dash odometer: ~$(printf "%'d" "$MILES") miles (${RAW_U32} pulses)"
    echo "    CONFIRM this matches the physical dash before writing."
else
    if [ -z "$MILES" ]; then
        echo "[ERROR] Provide a mileage or use --from-dash."; usage
    fi
    if ! [[ "$MILES" =~ ^[0-9]+$ ]]; then
        echo "[ERROR] Miles must be a positive integer, got: $MILES"; exit 1
    fi
    if [ "$MILES" -gt "$MAX_MILES" ]; then
        echo "[ERROR] $MILES exceeds max $MAX_MILES miles (u32 pulse limit)"; exit 1
    fi
    RAW_U32=$(( MILES * PULSES_PER_MILE ))
fi

RING_VAL=$(( RAW_U32 / RING_DIVISOR ))
[ "$RING_VAL" -gt 65535 ] && RING_VAL=65535

HI_WORD=$(( (RAW_U32 >> 16) & 0xFFFF ))
LO_WORD=$((  RAW_U32        & 0xFFFF ))
HI_HEX=$(printf "%04X" "$HI_WORD")
LO_HEX=$(printf "%04X" "$LO_WORD")
RING_HEX=$(printf "%04X" "$RING_VAL")

echo "============================================"
echo "  CM848D ECU Distance-Counter Restore"
echo "============================================"
echo "  CAN interface:  $CAN_IF"
echo "  Target:         $(printf "%'d" "$MILES") miles"
echo "  Pulses (u32):   $RAW_U32 (0x$(printf "%08X" "$RAW_U32"))  = 0x${HI_HEX} 0x${LO_HEX}"
echo "  8-mile ring:    $RING_VAL (0x${RING_HEX}) x ${RING_ENTRIES}"
echo
echo "  Writes:"
echo "    lifetime 0x${LIFETIME_ADDR}  <- ${HI_HEX} ${LO_HEX}"
echo "    trip     0x${TRIP_ADDR}  <- ${HI_HEX} ${LO_HEX}"
echo "    ring     0x${RING_ADDR}  <- ${RING_HEX} x ${RING_ENTRIES}"
echo "  Not touched: 0x${DTC_LIST_ADDR} (active DTC list), the dash cluster."
echo "  Checksum 0x${CHECKSUM_ADDR} self-heals at the next engine start."
echo

# Show current values.
echo "[*] Current ECU values:"
CUR_LIFE=$(read_u32 "$LIFETIME_ADDR"); CUR_TRIP=$(read_u32 "$TRIP_ADDR")
[ -n "$CUR_LIFE" ] && echo "    lifetime: ~$(printf "%'d" $(( CUR_LIFE / PULSES_PER_MILE ))) mi (${CUR_LIFE} pulses)" || echo "    lifetime: (read failed)"
[ -n "$CUR_TRIP" ] && echo "    trip:     ~$(printf "%'d" $(( CUR_TRIP / PULSES_PER_MILE ))) mi (${CUR_TRIP} pulses)" || echo "    trip:     (read failed)"
echo

if [ "$DRY_RUN" -eq 1 ]; then
    echo "[DRY RUN] No data sent."
    exit 0
fi

echo "  This overwrites the ECU's internal distance counters (not the dash)."
echo "  Keep a fresh EEPROM dump first. This write path is bench-UNTESTED."
read -p "  Proceed? [y/N] " CONFIRM
[[ "$CONFIRM" =~ ^[yY]$ ]] || { echo "  Aborted."; exit 0; }

# Write a big-endian u16 (4 hex chars) at a CLIP address.
write_u16() {
    local addr="$1" val="$2"
    echo "    write 0x${val} -> 0x${addr}"
    "$KUMINZ_CLI" "$CAN_IF" --write-service4b "$addr" "$val"
    sleep 0.2
}

ring_addr_at() { printf "%08X" $(( 16#${RING_ADDR} + 2 * $1 )); }

echo
echo "[1/3] Lifetime distance (0x${LIFETIME_ADDR})..."
write_u16 "$LIFETIME_ADDR" "$HI_HEX"
write_u16 "$(printf "%08X" $(( 16#${LIFETIME_ADDR} + 2 )))" "$LO_HEX"

echo
echo "[2/3] Trip distance (0x${TRIP_ADDR})..."
write_u16 "$TRIP_ADDR" "$HI_HEX"
write_u16 "$(printf "%08X" $(( 16#${TRIP_ADDR} + 2 )))" "$LO_HEX"

echo
echo "[3/3] Eight-mile record ring (0x${RING_ADDR})..."
for i in $(seq 0 $(( RING_ENTRIES - 1 ))); do
    write_u16 "$(ring_addr_at "$i")" "$RING_HEX"
done

echo
echo "[*] Verifying lifetime distance..."
VERIFY=$(read_u32 "$LIFETIME_ADDR")
if [ -n "$VERIFY" ] && [ "$VERIFY" -eq "$RAW_U32" ]; then
    echo "  [OK] lifetime = $(printf "%'d" $(( VERIFY / PULSES_PER_MILE ))) mi (0x$(printf "%08X" "$VERIFY"))"
    echo
    echo "  Done. Key-cycle the ECU: the block checksum re-stores itself at the"
    echo "  next engine start, and PGN 65248 then reports the restored distance."
else
    echo "  [WARN] Read-back mismatch (got: '${VERIFY:-none}', expected ${RAW_U32})."
    echo "         The ECU may need an authenticated session or a different write"
    echo "         service for EEPROM. Re-dump the EEPROM and compare before retrying."
fi
