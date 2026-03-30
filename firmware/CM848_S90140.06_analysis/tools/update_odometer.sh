#!/bin/bash
# update_odometer.sh - Set the CM848D ECU internal odometer value
#
# The ECU maintains its own distance counter in EEPROM at 0x01000BD8 (u32).
# This is separate from the dash odometer (stored in the instrument cluster).
# The ECU odometer resets when HP Tuners flashes a new tune.
#
# EEPROM layout:
#   0x01000BD8: Vehicle_Odometer_Data (u32, scale 0.000125 MI)
#   0x01001A84: Rolls_Odometer circular buffer (u16 x N, every 8 miles)
#
# Usage: ./update_odometer.sh <can_interface> <miles>
#   e.g., ./update_odometer.sh can0 293304
#
# The script writes the main odometer (2 x u16 writes) and updates
# the Rolls_Odometer buffer entry.

set -euo pipefail

KUMINZ_CLI="${KUMINZ_CLI:-/home/linux/code/kuminz-re/kuminz-cli/build/kuminz-cli}"

# EEPROM addresses
ODO_ADDR_HI="01000BD8"   # High word of u32 odometer
ODO_ADDR_LO="01000BDA"   # Low word of u32 odometer
ROLLS_ADDR="01001A84"    # Rolls_Odometer (u16, updates every 8 miles)

# Scale factors
ODO_SCALE="0.000125"     # raw * 0.000125 = miles
ROLLS_DIVISOR=8           # Rolls_Odometer = miles / 8

MAX_MILES=536870          # u32 max (4294967295 * 0.000125)

usage() {
    echo "CM848D ECU Odometer Update Tool"
    echo ""
    echo "Usage: $0 <can_interface> <miles>"
    echo ""
    echo "  can_interface   CAN interface (e.g., can0)"
    echo "  miles           Odometer value in miles (integer)"
    echo ""
    echo "Examples:"
    echo "  $0 can0 293304          # Set to 293,304 miles"
    echo "  $0 can0 150000          # Set to 150,000 miles"
    echo ""
    echo "EEPROM addresses:"
    echo "  0x${ODO_ADDR_HI}: Vehicle odometer (u32, scale ${ODO_SCALE} MI)"
    echo "  0x${ROLLS_ADDR}: Rolls buffer (u16, every ${ROLLS_DIVISOR} miles)"
    echo ""
    echo "Max odometer: ${MAX_MILES} miles (u32 limit)"
    exit 1
}

# Validate arguments
if [ $# -lt 2 ]; then
    usage
fi

CAN_IF="$1"
MILES="$2"

# Validate miles is a positive integer
if ! [[ "$MILES" =~ ^[0-9]+$ ]]; then
    echo "[ERROR] Miles must be a positive integer, got: $MILES"
    exit 1
fi

if [ "$MILES" -gt "$MAX_MILES" ]; then
    echo "[ERROR] $MILES exceeds max odometer value of $MAX_MILES miles"
    exit 1
fi

# Check kuminz-cli exists
if [ ! -x "$KUMINZ_CLI" ]; then
    echo "[ERROR] kuminz-cli not found at: $KUMINZ_CLI"
    echo "        Build it first: cd kuminz-cli/build && cmake .. && make -j4"
    exit 1
fi

# Convert miles to raw u32 value
# raw = miles / 0.000125 = miles * 8000
RAW_U32=$(( MILES * 8000 ))

# Split into high and low u16 words (big-endian)
HI_WORD=$(( (RAW_U32 >> 16) & 0xFFFF ))
LO_WORD=$(( RAW_U32 & 0xFFFF ))

# Calculate Rolls_Odometer value
ROLLS_VAL=$(( MILES / ROLLS_DIVISOR ))
if [ "$ROLLS_VAL" -gt 65535 ]; then
    ROLLS_VAL=65535  # u16 max, wraps
fi

# Format as hex strings (uppercase, no 0x prefix, 4 chars)
HI_HEX=$(printf "%04X" "$HI_WORD")
LO_HEX=$(printf "%04X" "$LO_WORD")
ROLLS_HEX=$(printf "%04X" "$ROLLS_VAL")

echo "============================================"
echo "  CM848D ECU Odometer Update"
echo "============================================"
echo ""
echo "  CAN interface:  $CAN_IF"
echo "  Target mileage: $(printf "%'d" "$MILES") miles"
echo ""
echo "  Raw u32 value:  $RAW_U32 (0x$(printf "%08X" "$RAW_U32"))"
echo "  High word:      0x${HI_HEX} -> EEPROM 0x${ODO_ADDR_HI}"
echo "  Low word:       0x${LO_HEX} -> EEPROM 0x${ODO_ADDR_LO}"
echo "  Rolls value:    $ROLLS_VAL (0x${ROLLS_HEX}) -> EEPROM 0x${ROLLS_ADDR}"
echo ""

# Read current value first
echo "[1/5] Reading current odometer value..."
CURRENT_HI=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$ODO_ADDR_HI" 2 2>/dev/null | tail -1) || true
CURRENT_LO=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$ODO_ADDR_LO" 2 2>/dev/null | tail -1) || true

if [ -n "$CURRENT_HI" ] && [ -n "$CURRENT_LO" ]; then
    echo "  Current raw: 0x${CURRENT_HI}${CURRENT_LO}"
    # Parse current value
    CURRENT_RAW=$(( 16#${CURRENT_HI}${CURRENT_LO} )) 2>/dev/null || CURRENT_RAW=0
    CURRENT_MILES=$(( CURRENT_RAW / 8000 ))
    echo "  Current mileage: ~$(printf "%'d" "$CURRENT_MILES") miles"
else
    echo "  [WARN] Could not read current value (ECU may not be connected)"
fi

echo ""
echo "  WARNING: This will overwrite the ECU's internal odometer."
echo "  The dash odometer (instrument cluster) is NOT affected."
echo ""
read -p "  Proceed with write? [y/N] " CONFIRM
if [[ ! "$CONFIRM" =~ ^[yY]$ ]]; then
    echo "  Aborted."
    exit 0
fi

echo ""
echo "[2/5] Writing high word 0x${HI_HEX} to 0x${ODO_ADDR_HI}..."
"$KUMINZ_CLI" "$CAN_IF" --write-service4b "$ODO_ADDR_HI" "$HI_HEX"
sleep 0.2

echo ""
echo "[3/5] Writing low word 0x${LO_HEX} to 0x${ODO_ADDR_LO}..."
"$KUMINZ_CLI" "$CAN_IF" --write-service4b "$ODO_ADDR_LO" "$LO_HEX"
sleep 0.2

echo ""
echo "[4/5] Writing Rolls_Odometer 0x${ROLLS_HEX} to 0x${ROLLS_ADDR}..."
"$KUMINZ_CLI" "$CAN_IF" --write-service4b "$ROLLS_ADDR" "$ROLLS_HEX"
sleep 0.2

echo ""
echo "[5/5] Verifying write..."
VERIFY_HI=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$ODO_ADDR_HI" 2 2>/dev/null | tail -1) || true
VERIFY_LO=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$ODO_ADDR_LO" 2 2>/dev/null | tail -1) || true

if [ -n "$VERIFY_HI" ] && [ -n "$VERIFY_LO" ]; then
    VERIFY_RAW=$(( 16#${VERIFY_HI}${VERIFY_LO} )) 2>/dev/null || VERIFY_RAW=0
    VERIFY_MILES=$(( VERIFY_RAW / 8000 ))

    if [ "$VERIFY_RAW" -eq "$RAW_U32" ]; then
        echo "  [OK] Verified: $(printf "%'d" "$VERIFY_MILES") miles (0x$(printf "%08X" "$VERIFY_RAW"))"
        echo ""
        echo "  Odometer updated successfully."
        echo "  NOTE: ECU may need a key cycle to reflect the new value on J1939."
    else
        echo "  [WARN] Readback mismatch!"
        echo "    Expected: 0x$(printf "%08X" "$RAW_U32") ($(printf "%'d" "$MILES") mi)"
        echo "    Got:      0x$(printf "%08X" "$VERIFY_RAW") ($(printf "%'d" "$VERIFY_MILES") mi)"
        echo "    The ECU may require authentication or a different write service."
        echo "    Try --write-addr-auth or --write-clip if Service 0x4B fails."
    fi
else
    echo "  [WARN] Could not verify (read-back failed)"
fi
