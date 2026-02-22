#!/bin/bash
# Complete Firmware Disassembly using objdump
# Generates working2/J90280.05.objdump.asm

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
FIRMWARE_FILE="$PROJECT_DIR/firmware/J90280.05.full.bin"
OUTPUT_FILE="$PROJECT_DIR/working/J90280.05.objdump.asm"

echo "=== CM550 Firmware Complete Disassembly - objdump ==="
echo "Firmware: $FIRMWARE_FILE"
echo "Output: $OUTPUT_FILE"
echo "Started: $(date)"
echo ""

# Create working2 directory
mkdir -p "$PROJECT_DIR/working"

# Check if firmware exists
if [ ! -f "$FIRMWARE_FILE" ]; then
    echo "❌ Error: Firmware file not found: $FIRMWARE_FILE"
    echo "Please run: python3 scripts/hex_to_full_binary.py firmware/J90280.05 firmware/J90280.05.full.bin"
    exit 1
fi

# Check objdump capabilities
echo "Checking objdump capabilities..."
if ! objdump --help | grep -q "m68k\|68000"; then
    echo "⚠️  Warning: This objdump build doesn't support m68k architecture"
    echo "Attempting alternative approach..."
    
    # Try with cross-compilation tools if available
    if command -v m68k-linux-gnu-objdump &> /dev/null; then
        OBJDUMP_CMD="m68k-linux-gnu-objdump"
        echo "✅ Found cross-compiler objdump: $OBJDUMP_CMD"
    elif command -v m68k-elf-objdump &> /dev/null; then
        OBJDUMP_CMD="m68k-elf-objdump"
        echo "✅ Found cross-compiler objdump: $OBJDUMP_CMD"
    else
        echo "❌ Error: No m68k-capable objdump found"
        echo "Install with: sudo apt-get install gcc-m68k-linux-gnu"
        echo "Or use alternative tools: capstone-tool, radare2, etc."
        
        # Create a note file instead
        cat > "$OUTPUT_FILE" << EOF
# CM550 Firmware Disassembly - objdump Method
# Generated: $(date)
# Status: FAILED - No m68k support in objdump
# 
# Error: objdump on this system doesn't support Motorola 68000 architecture
# 
# To fix this issue:
# 1. Install cross-compilation tools: sudo apt-get install gcc-m68k-linux-gnu
# 2. Or use alternative: capstone-tool --arch m68k firmware/J90280.05.full.bin
# 3. Or use radare2: r2 -a m68k firmware/J90280.05.full.bin
#
# Supported architectures in this objdump:
EOF
        objdump --help | grep "supported architectures" -A10 >> "$OUTPUT_FILE"
        exit 1
    fi
else
    OBJDUMP_CMD="objdump"
    echo "✅ Found objdump with m68k support"
fi

echo ""
echo "Starting complete firmware disassembly..."
echo "This will process all 256KB of firmware..."

# Create header
cat > "$OUTPUT_FILE" << EOF
# CM550 Firmware Complete Disassembly - objdump
# Generated: $(date)
# Firmware: J90280.05 (256KB)
# Architecture: Motorola 68000/68020
# Tool: $OBJDUMP_CMD
# Format: address<TAB>bytes<TAB>instruction

EOF

# Perform disassembly
echo "Running objdump disassembly..."
if timeout 300 $OBJDUMP_CMD -D -b binary -m m68k --endian=big "$FIRMWARE_FILE" >> "$OUTPUT_FILE" 2>&1; then
    echo "✅ Disassembly completed successfully!"
else
    echo "❌ Disassembly failed or timed out"
    echo "Check $OUTPUT_FILE for error details"
    exit 1
fi

# Add statistics
echo "" >> "$OUTPUT_FILE"
echo "# === Statistics ===" >> "$OUTPUT_FILE"
echo "# Total lines: $(wc -l < "$OUTPUT_FILE")" >> "$OUTPUT_FILE"
echo "# File size: $(ls -lh "$FIRMWARE_FILE" | awk '{print $5}')" >> "$OUTPUT_FILE"
echo "# Completed: $(date)" >> "$OUTPUT_FILE"

# Summary
LINES=$(wc -l < "$OUTPUT_FILE")
SIZE=$(ls -lh "$OUTPUT_FILE" | awk '{print $5}')

echo ""
echo "=== Disassembly Complete ==="
echo "Output file: $OUTPUT_FILE"
echo "Lines generated: $LINES"
echo "File size: $SIZE"
echo "Completed: $(date)"
echo ""
echo "Next steps:"
echo "1. Search for VP44 patterns: grep -i 'fuel\|vp44\|112' $OUTPUT_FILE"
echo "2. Look for CAN message handlers"
echo "3. Compare with other disassemblers"