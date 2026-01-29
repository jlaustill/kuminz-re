#!/usr/bin/env python3
"""
Parse e2m calibration files and generate Ghidra-compatible CSVs.

E2M Format:
Name,Unit,BaseAddr,Offset,GroupID,Flags,Type1,Size,?,SignType,Scale,ConvOffset,Min,Max,?,?,Type2,StartVer,EndVer;Description

The description often contains internal variable names in brackets like [VARNAME].
"""

import sys
import re
import csv
from pathlib import Path

# CM848 Memory base addresses (from README)
MEMORY_BASES = {
    'ROM': 0x00000000,
    'RAM': 0x003FA000,
    'EEPROM': 0x01000000,
}

# Group ID to memory region mapping (discovered from e2m analysis)
# These need to be verified against actual firmware
GROUP_TO_REGION = {
    # EEPROM groups (0x00xx)
    '0000': ('EEPROM', 0x0000),  # Software calibration markers
    '0024': ('EEPROM', 0x0000),  # Basic ECM info
    '003E': ('EEPROM', 0x0000),  # Calibration dates
    '0052': ('EEPROM', 0x0000),  # Adjustable parameters
    '003B': ('EEPROM', 0x0000),  # Security
    '0063': ('EEPROM', 0x0000),  # Calibration markers
    '0076': ('EEPROM', 0x0000),  # ECM identifier
    '000E': ('EEPROM', 0x0000),  # PTO parameters
    '0028': ('EEPROM', 0x0000),  # Run time
    # Add more as discovered
}

def parse_e2m_line(line):
    """Parse a single e2m data line."""
    # Skip header and empty lines
    if line.startswith('[') or not line.strip():
        return None

    # Split on semicolon first to get description
    parts = line.split(';', 1)
    if len(parts) < 2:
        return None

    data_part = parts[0]
    description = parts[1].strip() if len(parts) > 1 else ""

    # Split CSV fields
    fields = data_part.split(',')
    if len(fields) < 18:
        return None

    name = fields[0].strip()
    unit = fields[1].strip()
    base_addr = fields[2].strip()
    offset = fields[3].strip()
    group_id = fields[4].strip()
    flags = fields[5].strip()
    type1 = fields[6].strip()
    size = fields[7].strip()
    sign_type = fields[9].strip() if len(fields) > 9 else 'U'
    scale = fields[10].strip() if len(fields) > 10 else '1'

    # Extract internal variable name from description [VARNAME]
    internal_name = None
    match = re.search(r'\[([A-Z0-9_]+)\]', description)
    if match:
        internal_name = match.group(1)

    try:
        base_addr_int = int(base_addr, 16)
        offset_int = int(offset, 16)
        size_int = int(size) if size else 0
    except ValueError:
        return None

    return {
        'name': name,
        'internal_name': internal_name,
        'unit': unit,
        'base_addr': base_addr_int,
        'offset': offset_int,
        'group_id': group_id,
        'flags': flags,
        'size': size_int,
        'sign_type': sign_type,
        'scale': scale,
        'description': description,
    }

def parse_e2m_file(filepath):
    """Parse an entire e2m file."""
    parameters = []
    in_data_section = False

    with open(filepath, 'r', errors='replace') as f:
        for line in f:
            line = line.strip()

            if line == '[Data Records]':
                in_data_section = True
                continue

            if not in_data_section:
                continue

            param = parse_e2m_line(line)
            if param:
                parameters.append(param)

    return parameters

def generate_ghidra_csv(parameters, output_dir):
    """Generate Ghidra-compatible CSVs from parsed parameters."""

    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    # Global variables CSV (for EEPROM/RAM variables)
    variables = []

    # Constants/enums for documentation
    param_docs = []

    for param in parameters:
        # Skip software calibration markers
        if param['name'].startswith('Software_CAL'):
            continue

        # Calculate address (simplified - uses base_addr as EEPROM index)
        # Real address calculation would need the base lookup table
        eeprom_offset = (param['base_addr'] << 8) | param['offset']
        address = MEMORY_BASES['EEPROM'] + eeprom_offset

        # Determine type based on size
        if param['size'] == 1:
            var_type = 'u8' if param['sign_type'] == 'U' else 'i8'
        elif param['size'] == 2:
            var_type = 'u16' if param['sign_type'] == 'U' else 'i16'
        elif param['size'] == 4:
            var_type = 'u32' if param['sign_type'] == 'U' else 'i32'
        else:
            var_type = f'byte[{param["size"]}]' if param['size'] > 0 else 'undefined'

        # Use internal name if available, otherwise clean up the parameter name
        var_name = param['internal_name'] if param['internal_name'] else param['name']
        var_name = var_name.lower()

        # Create comment with full description
        comment = f"{param['name']}"
        if param['unit'] and param['unit'] != 'UNITLESS' and param['unit'] != 'HEX':
            comment += f" [{param['unit']}]"
        if param['description']:
            comment += f" - {param['description'][:80]}"

        variables.append({
            'address': f"0x{address:08X}",
            'name': var_name,
            'type': var_type,
            'comment': comment,
        })

        param_docs.append({
            'parameter': param['name'],
            'internal_name': param['internal_name'] or '',
            'address': f"0x{address:08X}",
            'size': param['size'],
            'unit': param['unit'],
            'scale': param['scale'],
            'description': param['description'],
        })

    # Write global variables CSV
    vars_file = output_dir / 'e2m_variables.csv'
    with open(vars_file, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['address', 'name', 'type', 'comment'])
        writer.writeheader()
        writer.writerows(variables)
    print(f"Wrote {len(variables)} variables to {vars_file}")

    # Write parameter documentation CSV
    docs_file = output_dir / 'e2m_parameters.csv'
    with open(docs_file, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['parameter', 'internal_name', 'address', 'size', 'unit', 'scale', 'description'])
        writer.writeheader()
        writer.writerows(param_docs)
    print(f"Wrote {len(param_docs)} parameter docs to {docs_file}")

    return len(variables)

def main():
    if len(sys.argv) < 3:
        print("Usage: parse_e2m_to_ghidra.py <e2m_file> <output_dir>")
        sys.exit(1)

    e2m_file = sys.argv[1]
    output_dir = sys.argv[2]

    print(f"Parsing {e2m_file}...")
    parameters = parse_e2m_file(e2m_file)
    print(f"Found {len(parameters)} parameters")

    count = generate_ghidra_csv(parameters, output_dir)
    print(f"Generated CSVs with {count} entries")

if __name__ == '__main__':
    main()
