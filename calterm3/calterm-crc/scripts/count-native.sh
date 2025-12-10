#!/bin/bash
CALTERM_DIR="/home/jlaustill/Software/Calterm III"
native_count=0
for dll in "$CALTERM_DIR"/*.dll; do
    if ! file "$dll" | grep -q "Mono/.Net"; then
        name=$(basename "$dll")
        case "$name" in
            atl110.dll|msvcp110.dll|msvcr110.dll) continue ;;
        esac
        echo "$name"
        native_count=$((native_count + 1))
    fi
done
echo ""
echo "Total native DLLs: $native_count"
