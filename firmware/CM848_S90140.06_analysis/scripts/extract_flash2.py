#!/usr/bin/env python3
"""
Extract extended flash region (0x00500000+) from CM848 e2m file.

The e2m file contains calibration data in a hex dump format. This script
extracts the second flash bank (0x005xxxxx) which contains utility functions
like sensorChannelConfigInit that are called from the main ROM.

Usage:
    python3 extract_flash2.py <input.e2m> <output.bin>
"""

import sys
import re


def extract_flash2(e2m_path: str, output_path: str) -> None:
    """Extract 0x005xxxxx region from e2m file to binary."""

    # Pattern to match hex dump lines: "0xADDRESS | HEX_DATA | ASCII"
    line_pattern = re.compile(r'^(0x[0-9A-Fa-f]+)\s*\|\s*([0-9A-Fa-f]+)')

    # Track address range
    start_addr = None
    end_addr = None
    data_chunks = []

    with open(e2m_path, 'r') as f:
        for line in f:
            match = line_pattern.match(line.strip())
            if not match:
                continue

            addr_str, hex_data = match.groups()
            addr = int(addr_str, 16)

            # Only extract 0x005xxxxx range
            if addr < 0x00500000 or addr >= 0x00600000:
                continue

            # Track range
            if start_addr is None:
                start_addr = addr
            end_addr = addr + len(hex_data) // 2

            # Convert hex string to bytes
            try:
                data = bytes.fromhex(hex_data)
                data_chunks.append((addr, data))
            except ValueError as e:
                print(f"Warning: Invalid hex at {addr_str}: {e}", file=sys.stderr)

    if not data_chunks:
        print("Error: No data found in 0x005xxxxx range", file=sys.stderr)
        sys.exit(1)

    # Sort by address and create contiguous binary
    data_chunks.sort(key=lambda x: x[0])

    # Calculate total size and create output buffer
    base_addr = data_chunks[0][0]
    total_size = end_addr - base_addr
    output_data = bytearray(total_size)

    # Fill in the data
    bytes_written = 0
    for addr, data in data_chunks:
        offset = addr - base_addr
        output_data[offset:offset + len(data)] = data
        bytes_written += len(data)

    # Write output file
    with open(output_path, 'wb') as f:
        f.write(output_data)

    print(f"Extracted extended flash region:")
    print(f"  Source: {e2m_path}")
    print(f"  Output: {output_path}")
    print(f"  Address range: 0x{base_addr:08X} - 0x{end_addr:08X}")
    print(f"  Size: {total_size:,} bytes ({total_size // 1024} KB)")
    print(f"  Data extracted: {bytes_written:,} bytes")


def main():
    if len(sys.argv) != 3:
        print(__doc__)
        print(f"Usage: {sys.argv[0]} <input.e2m> <output.bin>")
        sys.exit(1)

    extract_flash2(sys.argv[1], sys.argv[2])


if __name__ == '__main__':
    main()
