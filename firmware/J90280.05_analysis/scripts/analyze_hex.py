#!/usr/bin/env python3
"""
Analyze Intel HEX file to determine memory layout for Ghidra import
"""
import sys

def analyze_intel_hex(hex_file):
    """Analyze Intel HEX file and extract memory layout information"""
    
    print(f"# Analyzing Intel HEX file: {hex_file}")
    print("=" * 50)
    
    addresses = []
    data_ranges = []
    current_base = 0
    
    try:
        with open(hex_file, 'r') as f:
            lines = f.readlines()
        
        print(f"Total HEX records: {len(lines)}")
        
        # Parse each record
        for line_num, line in enumerate(lines, 1):
            line = line.strip()
            if not line.startswith(':'):
                continue
                
            try:
                # Parse Intel HEX record: :LLAAAATTDDCC
                byte_count = int(line[1:3], 16)
                address = int(line[3:7], 16)
                record_type = int(line[7:9], 16)
                
                if record_type == 0:  # Data record
                    full_address = current_base + address
                    addresses.append(full_address)
                    data_ranges.append((full_address, full_address + byte_count - 1))
                elif record_type == 4:  # Extended Linear Address
                    if byte_count == 2:
                        current_base = int(line[9:13], 16) << 16
                        print(f"Extended address record: Base = 0x{current_base:08X}")
                elif record_type == 1:  # End of File
                    print(f"End of file record at line {line_num}")
                    
            except (ValueError, IndexError) as e:
                print(f"Warning: Could not parse line {line_num}: {line} ({e})")
                continue
        
        if addresses:
            min_addr = min(addresses)
            max_addr = max(addr + size for addr, size in data_ranges)
            
            print(f"\n# Memory Layout Analysis")
            print("=" * 30)
            print(f"Minimum address: 0x{min_addr:08X}")
            print(f"Maximum address: 0x{max_addr:08X}")
            print(f"Address range:   0x{max_addr - min_addr:08X} ({max_addr - min_addr} bytes)")
            
            # Group consecutive ranges
            data_ranges.sort()
            merged_ranges = []
            for start, end in data_ranges:
                if merged_ranges and start <= merged_ranges[-1][1] + 1:
                    merged_ranges[-1] = (merged_ranges[-1][0], max(merged_ranges[-1][1], end))
                else:
                    merged_ranges.append((start, end))
            
            print(f"\n# Memory Blocks (merged ranges)")
            print("=" * 35)
            for i, (start, end) in enumerate(merged_ranges):
                size = end - start + 1
                print(f"Block {i+1}: 0x{start:08X} - 0x{end:08X} (size: {size} bytes)")
            
            # Check our target addresses
            print(f"\n# VP44 Function Address Analysis")
            print("=" * 40)
            target_functions = [
                (0x6b33, "fuel_temp_processor"),
                (0x8e23, "fuel_temp_calc"),
                (0x983b, "fuel_temp_bit_ops"),
                (0x3624, "vp44_512_rx_handler"),
                (0x936, "vp44_fault_isr"),
                (0x0c47, "vp44_fault_bit_parser"),
                (0x0c6a, "vp44_fault_storage")
            ]
            
            for addr, name in target_functions:
                # Check if address falls in any range
                in_range = any(start <= addr <= end for start, end in merged_ranges)
                status = "✅ FOUND" if in_range else "❌ NOT FOUND"
                print(f"0x{addr:08X} ({name}): {status}")
            
            print(f"\n# Recommended Ghidra Import Settings")
            print("=" * 42)
            print(f"Format: Intel HEX")
            print(f"Architecture: 68000:BE:16:default")
            print(f"Base Address: 0x00000000 (let Ghidra auto-detect)")
            print(f"Image Base: 0x00000000")
            
            if min_addr > 0x10000:
                print(f"Alternative Base: 0x{min_addr:08X}")
                
        else:
            print("No data records found in HEX file")
            
    except FileNotFoundError:
        print(f"Error: File {hex_file} not found")
        return 1
    except Exception as e:
        print(f"Error analyzing file: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 analyze_hex.py <hex_file>")
        print("Example: python3 analyze_hex.py firmware/J90280.05")
        sys.exit(1)
    
    exit_code = analyze_intel_hex(sys.argv[1])
    sys.exit(exit_code)