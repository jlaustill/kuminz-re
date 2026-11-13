#!/bin/bash
# read_engine_hours.sh - Read the CM848D ECM lifetime run-time counter and
# produce the lifetime-hours seed value for OCT.
#
# WHY (and why this is a READ tool, not a restore tool):
#   HP Tuners flashing wipes the ECM's distance counters, but it does NOT wipe
#   the run-time counter. Verified across four EEPROM dumps - EEPROM 0x30 rises
#   monotonically through both post-HP-Tuners dumps (177,300,018 -> 179,231,674).
#   So there is nothing to restore in the ECM. The e2m "Hour_Meter" at
#   0x01001C00 is a static 72,418,429 in all four dumps - a dead/stale address.
#
#   What actually needs a value is OCT: its EngineHoursTruckLifetime starts
#   "NOT SEEDED". OCT then accumulates ENGINE-RUNNING hours itself (1 s per
#   second while RPM is above its threshold). You seed it once over serial:
#       engineHoursTruckLifetime=<hours>
#   This tool reads the ECM counter and prints exactly that command.
#
# WHAT THE COUNTER IS:
#   EEPROM 0x01000030 (u32 BE) = ecm_runtime_accumulator - ECM KEY-ON time
#   (powered time), not engine-running time, so it is an OVER-estimate of engine
#   hours. It is the best lifetime proxy the truck exposes (true engine-running
#   hours / CMEGTR is not physically reachable over CLIP). Firmware-traced:
#   mpc555_tickTransferTimeoutAndRuntimeCounter (+1 every 40-41 watchdog/PIT
#   ticks), saved by mpc555_keyOnStateMachine at key-off, reloaded at boot.
#   Live mirror: RAM 0x00302012.
#
# SCALE IS UNCONFIRMED. The counter is counts, not seconds. Candidates:
#     0.205 s/count  (PIT 1 MHz, PITC 4999, +1 every 41 ticks) -> firmware-traced
#     0.200 s/count  (e2m Hour_Meter 1/300 min per bit)
#     0.667 s/count  (watchdog 60 Hz, +1 every 40 ticks)
#   That is a ~3x spread (9,850 h vs 32,000 h at 179.2M counts). CONFIRM IT with
#   one timed key cycle before you seed OCT - see --calibrate below.
#
# Usage:
#   ./read_engine_hours.sh <can_interface>                 # read the ECM live
#   ./read_engine_hours.sh <can_interface> --scale 0.205   # pick the s/count
#   ./read_engine_hours.sh --from-raw <u32>                # offline convert (no truck)
#   ./read_engine_hours.sh --calibrate <raw_before> <raw_after> <seconds>
#                                                          # s/count from a timed key cycle

set -euo pipefail
KUMINZ_CLI="${KUMINZ_CLI:-/home/linux/code/kuminz-re/kuminz-cli/build/kuminz-cli}"

KEYON_ADDR="01000030"   # u32 BE lifetime ECM key-on counter (EEPROM)
LIVE_RAM_ADDR="00302012" # live RAM mirror (may be outside the Service 0x4A window)
DEFAULT_SCALE="0.205"    # seconds per count (UNCONFIRMED - see header)

usage() {
    cat <<EOF
CM848D ECM Run-Time / OCT Hours-Seed Tool  (read-only)

Usage:
  $0 <can_interface> [--scale <sec_per_count>]
  $0 --from-raw <u32_counts> [--scale <sec_per_count>]
  $0 --calibrate <raw_before> <raw_after> <elapsed_seconds>

  <can_interface>   CAN interface (e.g. can0) - reads EEPROM 0x${KEYON_ADDR}
  --scale S         seconds per count (default ${DEFAULT_SCALE}, UNCONFIRMED)
  --from-raw N      convert a raw counter value with no truck connected
  --calibrate a b t read two counter values t seconds apart (a before, b after
                    a timed key cycle) and print the measured s/count + hours

The ECM counter is NOT wiped by HP Tuners - do not try to "restore" it.
Seed OCT with the printed value over serial: engineHoursTruckLifetime=<hours>
EOF
    exit 1
}

# hours_for <raw_counts> <sec_per_count>
hours_for() { awk -v r="$1" -v s="$2" 'BEGIN{ printf "%.1f", r*s/3600.0 }'; }

report() {
    local raw="$1" scale="$2"
    local h; h=$(hours_for "$raw" "$scale")
    echo "  Raw counter:    $raw counts (0x$(printf '%08X' "$raw"))"
    echo "  Chosen scale:   ${scale} s/count  ->  ${h} hours"
    echo "  Scale range:    $(hours_for "$raw" 0.200) h @0.200  /  $(hours_for "$raw" 0.205) h @0.205  /  $(hours_for "$raw" 0.667) h @0.667"
    echo
    echo "  Seed OCT (over its serial console), once you trust the scale:"
    echo "      engineHoursTruckLifetime=${h}"
    echo
    echo "  NOTE: this is ECM KEY-ON time (an over-estimate of engine-running"
    echo "  hours). HP Tuners does NOT wipe it, so no ECM write is needed."
}

# ---- calibrate ------------------------------------------------------------
if [ "${1:-}" = "--calibrate" ]; then
    [ $# -eq 4 ] || usage
    A="$2"; B="$3"; T="$4"
    [[ "$A" =~ ^[0-9]+$ && "$B" =~ ^[0-9]+$ && "$T" =~ ^[0-9]+(\.[0-9]+)?$ ]] || { echo "[ERROR] raw values must be integers, seconds a number"; exit 1; }
    awk -v a="$A" -v b="$B" -v t="$T" 'BEGIN{
        d=b-a;
        if (d<=0){ print "[ERROR] after must exceed before (d=" d ")"; exit 1 }
        spc=t/d;
        printf "  Delta:          %d counts over %s s\n", d, t;
        printf "  Measured scale: %.4f s/count  (%.4f counts/s)\n", spc, d/t;
        printf "  => lifetime:    %.1f hours at this scale (for counter b=%d)\n", b*spc/3600.0, b;
        printf "\n  Seed OCT:  engineHoursTruckLifetime=%.1f\n", b*spc/3600.0;
    }'
    exit 0
fi

# ---- offline convert ------------------------------------------------------
if [ "${1:-}" = "--from-raw" ]; then
    [ $# -ge 2 ] || usage
    RAW="$2"; SCALE="$DEFAULT_SCALE"
    [ "${3:-}" = "--scale" ] && SCALE="${4:?}"
    [[ "$RAW" =~ ^[0-9]+$ ]] || RAW=$(( 16#${RAW#0x} ))
    echo "============================================"
    echo "  CM848D ECM run-time (offline convert)"
    echo "============================================"
    report "$RAW" "$SCALE"
    exit 0
fi

# ---- live read ------------------------------------------------------------
[ $# -ge 1 ] || usage
CAN_IF="$1"; shift
SCALE="$DEFAULT_SCALE"
[ "${1:-}" = "--scale" ] && { SCALE="${2:?}"; shift 2; }

[ -x "$KUMINZ_CLI" ] || { echo "[ERROR] kuminz-cli not found at: $KUMINZ_CLI"; exit 1; }

read_u32() {
    local addr="$1" hex
    hex=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$addr" 4 2>/dev/null \
            | tail -1 | tr -d ' \t' | sed -E 's/^0[xX]//' | tr -dc '0-9A-Fa-f') || true
    [ "${#hex}" -ge 8 ] && echo $(( 16#${hex:0:8} )) || echo ""
}

echo "============================================"
echo "  CM848D ECM run-time counter"
echo "============================================"
echo "[*] Reading EEPROM 0x${KEYON_ADDR} (lifetime key-on counter)..."
RAW=$(read_u32 "$KEYON_ADDR")
if [ -z "$RAW" ] || [ "$RAW" -eq 0 ] || [ "$RAW" -eq 4294967295 ]; then
    echo "[ERROR] Could not read a valid counter (got: '${RAW:-none}'). Check the CAN link."
    exit 1
fi
report "$RAW" "$SCALE"

echo
echo "[*] Cross-check - live RAM 0x${LIVE_RAM_ADDR} (may be outside the Service 0x4A window)..."
LIVE=$(read_u32 "$LIVE_RAM_ADDR")
if [ -n "$LIVE" ] && [ "$LIVE" -ne 0 ] && [ "$LIVE" -ne 4294967295 ]; then
    echo "  Live RAM: $LIVE counts (EEPROM lags - it only saves at key-off / periodic flush)"
else
    echo "  (not readable here - fine; the EEPROM value above is the one to use)"
fi

echo
echo "  To CONFIRM the scale: note this counter, idle the engine exactly N minutes,"
echo "  key OFF (let it flush), key ON, read again, then:"
echo "      $0 --calibrate <before> <after> <seconds>"
