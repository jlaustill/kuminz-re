#!/bin/bash

# Complete CM550 Firmware Export Runner
# This script runs the complete objdump export

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

echo "Starting complete CM550 firmware export using objdump..."
echo "Project directory: $PROJECT_DIR"
echo ""

# Change to project directory
cd "$PROJECT_DIR"

# Run the objdump export
echo "Running objdump analysis..."
"$SCRIPT_DIR/objdump_dump.sh"

# Check if export completed successfully
if [ $? -eq 0 ]; then
    OUTPUT_FILE="$PROJECT_DIR/working/J90280.05.objdump.asm"
    echo ""
    echo "✅ Export completed successfully!"
    echo "📁 Output saved to: $OUTPUT_FILE"
    echo "📊 File size: $(du -h "$OUTPUT_FILE" | cut -f1)"
    echo "📏 Line count: $(wc -l < "$OUTPUT_FILE")"
    echo ""
    echo "🔧 To view the complete export:"
    echo "   less $OUTPUT_FILE"
    echo ""
    echo "🔍 To search for VP44 patterns:"
    echo "   grep -n '0070' $OUTPUT_FILE"
    echo ""
else
    echo "❌ Export failed"
    echo "📁 Check objdump output for errors"
fi

echo "Done."