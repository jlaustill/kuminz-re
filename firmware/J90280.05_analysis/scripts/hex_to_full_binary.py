#!/usr/bin/env python3
"""
Convert Intel HEX to full binary with complete address space
This creates a binary file that includes all address ranges, filling gaps with 0xFF
"""

import sys
import os

def hex_to_full_binary(hex_file, bin_file, start_addr=0x0, end_addr=0x40000):
    """Convert Intel HEX to binary with full address space"""
    
    print(f"Converting {hex_file} to full binary...")
    print(f"Address range: 0x{start_addr:08X} - 0x{end_addr:08X}")
    
    # Initialize with 0xFF (common for EPROM/Flash)
    data = [0xFF] * (end_addr - start_addr)
    current_base = 0
    data_count = 0
    
    try:
        with open(hex_file, 'r') as f:
            for line_num, line in enumerate(f, 1):
                line = line.strip()
                if not line.startswith(':'):
                    continue
                    
                try:
                    byte_count = int(line[1:3], 16)
                    address = int(line[3:7], 16)
                    record_type = int(line[7:9], 16)
                    
                    if record_type == 0:  # Data record
                        full_addr = current_base + address
                        if start_addr <= full_addr < end_addr:
                            for i in range(byte_count):
                                if full_addr + i < end_addr:
                                    data[full_addr + i - start_addr] = int(line[9 + i*2:11 + i*2], 16)
                                    data_count += 1
                    elif record_type == 4:  # Extended Linear Address
                        if byte_count == 2:
                            current_base = int(line[9:13], 16) << 16
                            print(f"  Extended address: 0x{current_base:08X}")
                    elif record_type == 1:  # End of file
                        print(f"  End of file at line {line_num}")
                        
                except (ValueError, IndexError) as e:
                    print(f"Warning: Could not parse line {line_num}: {line} ({e})")
                    continue
        
        # Write binary file
        with open(bin_file, 'wb') as f:
            f.write(bytes(data))
        
        print(f"✅ Success!")
        print(f"   Output: {bin_file}")
        print(f"   Size: {len(data)} bytes ({len(data)/1024:.1f} KB)")
        print(f"   Data bytes written: {data_count}")
        print(f"   Fill bytes (0xFF): {len(data) - data_count}")
        
        # Show memory usage
        print(f"\n📊 Memory Usage:")
        ranges = []
        in_data = False
        range_start = None
        
        for i, byte_val in enumerate(data):
            addr = start_addr + i
            if byte_val != 0xFF and not in_data:
                range_start = addr
                in_data = True
            elif byte_val == 0xFF and in_data:
                ranges.append((range_start, addr - 1))
                in_data = False
        
        if in_data:
            ranges.append((range_start, start_addr + len(data) - 1))
        
        for i, (start, end) in enumerate(ranges):
            size = end - start + 1
            print(f"   Block {i+1}: 0x{start:08X} - 0x{end:08X} ({size} bytes)")
        
        return 0
        
    except FileNotFoundError:
        print(f"❌ Error: File {hex_file} not found")
        return 1
    except Exception as e:
        print(f"❌ Error: {e}")
        return 1

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 hex_to_full_binary.py <input.hex> <output.bin> [start_addr] [end_addr]")
        print("")
        print("Examples:")
        print("  python3 hex_to_full_binary.py firmware/J90280.05 firmware/J90280.05.bin")
        print("  python3 hex_to_full_binary.py firmware/J90280.05 firmware/J90280.05.bin 0x0 0x80000")
        print("")
        print("Default address range: 0x00000000 - 0x00040000 (256KB)")
        return 1
    
    hex_file = sys.argv[1]
    bin_file = sys.argv[2]
    start_addr = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0x0
    end_addr = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0x40000
    
    # Create output directory if needed
    os.makedirs(os.path.dirname(bin_file), exist_ok=True)
    
    return hex_to_full_binary(hex_file, bin_file, start_addr, end_addr)

if __name__ == "__main__":
    sys.exit(main())