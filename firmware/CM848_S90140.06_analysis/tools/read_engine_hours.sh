#!/bin/bash
# read_engine_hours.sh - Read the CM848D ECM's lifetime hour meters and produce
# the engine-hours seed value for OCT.
#
# WHY (and why this is a READ tool, not a restore tool):
#   HP Tuners flashing wipes the ECM's distance counters, but it does NOT wipe
#   the two hour meters at the start of the EEPROM. Verified across four EEPROM
#   dumps (original / before HPT / after HPT 1 / after HPT 2): both rise
#   monotonically through the flashes. So there is nothing to restore in the
#   ECM. (The e2m "Hour_Meter" at 0x01001C00 is a static 72,418,429 in all four
#   dumps - a dead/stale address.)
#
#   What actually needs a value is OCT: its EngineHoursTruckLifetime starts
#   "NOT SEEDED". OCT then accumulates ENGINE-RUNNING hours itself (1 s per
#   second while RPM is above its threshold). You seed it once over serial:
#       engineHoursTruckLifetime=<hours>
#   This tool reads the ECM's ENGINE-RUN hour meter and prints that command.
#
# THE TWO HOUR METERS (firmware-traced, PR #48, 2026-11-15):
#   cm848_advanceHourMeters (flash2 0x506780) runs in phase 0 of the 40-phase
#   main loop, i.e. once every 40 PIT ticks. Each tick is 5 ms (PITC = 4999, a
#   5000-count PIT period at 1 MHz), so ONE COUNT = 0.200 s (hours = counts / 18000).
#   - EEPROM 0x01000042 (u32 BE) = engine_hour_meter_cal - ENGINE-RUNNING time.
#     Counts only while cold_start_phase is not 1 (engine stopped / cranking).
#     Live copy: RAM 0x0040A794 (engine_hour_meter).
#     This is the value to seed OCT with.
#   - EEPROM 0x01000030 (u32 BE) = key_on_hour_meter_cal - ECM KEY-ON time
#     (powered time, an over-estimate of engine hours). Live copy: RAM 0x0040A64C
#     (key_on_hour_meter). The boot ROM keeps its own copy at RAM 0x00302012
#     (+1 every 41 PIT ticks = 0.205 s while in the boot ROM only).
#   Both are loaded at start (cm848_loadHourMetersFromEeprom) and saved back at
#   power-down (cm848_runPowerDownSequence) and before a reflash restart
#   (restartThroughBootRom).
#
# EVIDENCE THAT 0x42 IS ENGINE-RUNNING TIME:
#   during the two HP Tuners flash sessions (key on, engine off) the key-on
#   meter advanced 44.7 min and 19.8 min while the engine-run meter advanced
#   10 counts (2 s) each. The RAM dump (a ~50 min key-on session) shows the same.
#   9,819.5 engine hours vs ~293,000 mi = ~30 mph average.
#
# Usage:
#   ./read_engine_hours.sh <can_interface>                 # read the ECM live
#   ./read_engine_hours.sh <can_interface> --scale 0.200   # override the s/count
#   ./read_engine_hours.sh --from-raw <u32>                # offline convert (no truck)
#   ./read_engine_hours.sh --calibrate <raw_before> <raw_after> <seconds>
#                                                          # check the s/count with a timed run

set -euo pipefail
KUMINZ_CLI="${KUMINZ_CLI:-/home/linux/code/kuminz-re/kuminz-cli/build/kuminz-cli}"

ENGINE_RUN_ADDR="01000042"      # u32 BE lifetime engine-run hour meter (EEPROM)
KEY_ON_ADDR="01000030"          # u32 BE lifetime key-on hour meter (EEPROM)
ENGINE_RUN_LIVE_ADDR="0040A794" # live RAM copy of the engine-run meter
KEY_ON_LIVE_ADDR="0040A64C"     # live RAM copy of the key-on meter
DEFAULT_SCALE="0.200"           # seconds per count (40 PIT ticks of 5 ms)

usage() {
    cat <<EOF
CM848D ECM Hour Meters / OCT Hours-Seed Tool  (read-only)

Usage:
  $0 <can_interface> [--scale <sec_per_count>]
  $0 --from-raw <u32_counts> [--scale <sec_per_count>]
  $0 --calibrate <raw_before> <raw_after> <elapsed_seconds>

  <can_interface>   CAN interface (e.g. can0) - reads EEPROM 0x${ENGINE_RUN_ADDR} (engine run)
                    and 0x${KEY_ON_ADDR} (key on), plus their live RAM copies
  --scale S         seconds per count (default ${DEFAULT_SCALE}, firmware-derived)
  --from-raw N      convert a raw counter value with no truck connected
  --calibrate a b t read the live engine-run meter (RAM 0x${ENGINE_RUN_LIVE_ADDR}) before and
                    after running the engine exactly t seconds and print the measured s/count

The ECM hour meters are NOT wiped by HP Tuners - do not try to "restore" them.
Seed OCT with the printed value over serial: engineHoursTruckLifetime=<hours>
EOF
    exit 1
}

# hours_for <raw_counts> <sec_per_count>
hours_for() { awk -v r="$1" -v s="$2" 'BEGIN{ printf "%.1f", r*s/3600.0 }'; }

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
        printf "  Measured scale: %.4f s/count  (%.4f counts/s; the firmware says 0.200 / 5.0)\n", spc, d/t;
        printf "  => lifetime:    %.1f hours at this scale (for counter b=%d)\n", b*spc/3600.0, b;
    }'
    exit 0
fi

# ---- offline convert ------------------------------------------------------
if [ "${1:-}" = "--from-raw" ]; then
    [ $# -ge 2 ] || usage
    RAW="$2"; SCALE="$DEFAULT_SCALE"
    [ "${3:-}" = "--scale" ] && SCALE="${4:?}"
    [[ "$RAW" =~ ^[0-9]+$ ]] || RAW=$(( 16#${RAW#0x} ))
    echo "  Raw counter: $RAW counts (0x$(printf '%08X' "$RAW")) -> $(hours_for "$RAW" "$SCALE") hours at ${SCALE} s/count"
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

valid() { [ -n "$1" ] && [ "$1" -ne 0 ] && [ "$1" -ne 4294967295 ]; }

echo "============================================"
echo "  CM848D ECM hour meters"
echo "============================================"
ENGINE_RUN=$(read_u32 "$ENGINE_RUN_ADDR")
KEY_ON=$(read_u32 "$KEY_ON_ADDR")
if ! valid "$ENGINE_RUN"; then
    echo "[ERROR] Could not read the engine-run meter at EEPROM 0x${ENGINE_RUN_ADDR} (got: '${ENGINE_RUN:-none}'). Check the CAN link."
    exit 1
fi
ENGINE_HOURS=$(hours_for "$ENGINE_RUN" "$SCALE")
echo "  Engine-run meter (EEPROM 0x${ENGINE_RUN_ADDR}): $ENGINE_RUN counts -> ${ENGINE_HOURS} h at ${SCALE} s/count"
if valid "$KEY_ON"; then
    echo "  Key-on meter     (EEPROM 0x${KEY_ON_ADDR}): $KEY_ON counts -> $(hours_for "$KEY_ON" "$SCALE") h (ECM powered time)"
fi

echo
echo "[*] Live RAM copies (the EEPROM copies are only saved at power-down):"
ENGINE_RUN_LIVE=$(read_u32 "$ENGINE_RUN_LIVE_ADDR")
KEY_ON_LIVE=$(read_u32 "$KEY_ON_LIVE_ADDR")
if valid "$ENGINE_RUN_LIVE"; then
    echo "  Engine-run (RAM 0x${ENGINE_RUN_LIVE_ADDR}): $ENGINE_RUN_LIVE counts -> $(hours_for "$ENGINE_RUN_LIVE" "$SCALE") h"
    ENGINE_HOURS=$(hours_for "$ENGINE_RUN_LIVE" "$SCALE")
fi
valid "$KEY_ON_LIVE" && echo "  Key-on     (RAM 0x${KEY_ON_LIVE_ADDR}): $KEY_ON_LIVE counts -> $(hours_for "$KEY_ON_LIVE" "$SCALE") h"

echo
echo "  Seed OCT (over its serial console) with the engine-run hours:"
echo "      engineHoursTruckLifetime=${ENGINE_HOURS}"
echo
echo "  To CHECK the scale: read RAM 0x${ENGINE_RUN_LIVE_ADDR}, run the engine exactly N seconds,"
echo "  read it again, then:  $0 --calibrate <before> <after> <seconds>   (expect 0.200)"
