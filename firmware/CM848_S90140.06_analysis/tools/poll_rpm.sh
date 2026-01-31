#!/bin/bash
# poll_rpm.sh - Poll CM848 ECU for engine RPM via kuminz-cli
#
# Usage: ./poll_rpm.sh [can_interface]
# Default interface: can0

CAN_IF="${1:-can0}"
KUMINZ_CLI="${2:-/home/linux/code/kuminz-re/kuminz-cli/build/kuminz-cli}"
RPM_ADDR="40B7BA"  # current_engine_rpm address
POLL_INTERVAL=0.5

echo "Polling RPM on $CAN_IF (Ctrl+C to stop)"
echo "Address: 0x$RPM_ADDR (current_engine_rpm)"
echo "Scale: raw × 0.125 = RPM"
echo "-------------------------------------------"

cleanup() {
    exit 0
}
trap cleanup INT TERM

while true; do
    # Read 2 bytes from RPM address
    OUTPUT=$("$KUMINZ_CLI" "$CAN_IF" --read-addr "$RPM_ADDR" 2 2>&1)

    # Extract hex bytes from output line containing the address
    HEX_LINE=$(echo "$OUTPUT" | grep "0040B7BA")

    if [[ -n "$HEX_LINE" ]]; then
        # Extract the two hex bytes (format: "0040B7BA | XX YY")
        RAW_HEX=$(echo "$HEX_LINE" | grep -oE '\| [0-9A-Fa-f]{2} [0-9A-Fa-f]{2}' | awk '{print $2$3}')

        if [[ -n "$RAW_HEX" ]]; then
            # Convert to decimal and apply scale factor (0.125)
            RAW_DEC=$((16#$RAW_HEX))
            RPM=$(echo "scale=1; $RAW_DEC * 0.125" | bc)
            TIMESTAMP=$(date '+%H:%M:%S')
            printf "[%s] RPM: %7.1f  (raw: 0x%04X = %d)\n" "$TIMESTAMP" "$RPM" "$RAW_DEC" "$RAW_DEC"
        fi
    else
        TIMESTAMP=$(date '+%H:%M:%S')
        echo "[$TIMESTAMP] Read failed - check ECU connection"
    fi

    sleep $POLL_INTERVAL
done
