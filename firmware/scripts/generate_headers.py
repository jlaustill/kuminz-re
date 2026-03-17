#!/usr/bin/env python3
"""
Generate C header files from Ghidra firmware analysis CSVs.

Produces:
  firmware_types.hpp    - type aliases, structs, enums
  firmware_globals.hpp  - global variable declarations
  firmware_functions.hpp - function declarations

Usage:
  python3 generate_headers.py <output_dir> [--dry-run]
"""

import argparse
import csv
import os
import re
import sys
from collections import OrderedDict


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def find_ghidra_cpp(output_dir):
    """Find the single .ghidra.cpp file in output_dir."""
    matches = [f for f in os.listdir(output_dir) if f.endswith('.ghidra.cpp')]
    if len(matches) == 0:
        raise FileNotFoundError(f"No .ghidra.cpp file found in {output_dir}")
    if len(matches) > 1:
        raise FileNotFoundError(
            f"Multiple .ghidra.cpp files found in {output_dir}: {matches}"
        )
    return os.path.join(output_dir, matches[0])


def write_file(path, content):
    """Write content to path, creating parent dirs as needed."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, 'w') as f:
        f.write(content)


def read_csv_skip_comments(path):
    """Read a CSV file, skipping lines starting with '#' or blank lines."""
    if not os.path.exists(path):
        return []
    with open(path, newline='') as f:
        filtered = (row for row in f if not row.startswith('#') and row.strip())
        reader = csv.DictReader(filtered)
        return list(reader)


# ---------------------------------------------------------------------------
# Type mapping
# ---------------------------------------------------------------------------

TYPE_MAP = {
    'byte':    'uint8_t',
    'word':    'uint16_t',
    'dword':   'uint32_t',
    'short':   'int16_t',
    'int':     'int32_t',
    'char':    'char',
    'uint8_t':  'uint8_t',
    'uint16_t': 'uint16_t',
    'uint32_t': 'uint32_t',
    'int8_t':   'int8_t',
    'int16_t':  'int16_t',
    'int32_t':  'int32_t',
}

TYPE_WIDTHS = {
    'uint8_t':  1,
    'uint16_t': 2,
    'uint32_t': 4,
    'int8_t':   1,
    'int16_t':  2,
    'int32_t':  4,
    'char':     1,
}


def map_type(raw_type):
    """
    Convert a raw CSV type string to a C type string.

    Handles:
      ptr:uint8_t  -> uint8_t *
      byte         -> uint8_t
      word         -> uint16_t
      dword        -> uint32_t
      etc.
    """
    raw_type = raw_type.strip()
    if raw_type.startswith('ptr:'):
        inner = raw_type[4:].strip()
        inner_mapped = TYPE_MAP.get(inner, inner)
        return f'{inner_mapped} *'
    return TYPE_MAP.get(raw_type, raw_type)


def field_declaration(field_name, c_type, size):
    """
    Produce a C field declaration, using arrays when size > base type width.

    e.g.  uint8_t data[5]  when type=uint8_t and size=5
    """
    base_width = TYPE_WIDTHS.get(c_type, None)
    if base_width is not None and size > base_width:
        count = size // base_width
        return f'    {c_type} {field_name}[{count}];'
    return f'    {c_type} {field_name};'


# ---------------------------------------------------------------------------
# Task 2: firmware_types.hpp
# ---------------------------------------------------------------------------

TYPE_ALIAS_PREAMBLE = """\
#pragma once
#include <stdint.h>

// Ghidra primitive type aliases
typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;
typedef uint64_t  undefined8;
typedef uint8_t   byte;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint16_t  word;
typedef uint32_t  dword;
typedef int32_t   bool32;

// Ghidra CONCATxy macros — concatenate x bytes of a with y bytes of b
// e.g. CONCAT22(hi16, lo16) produces a 32-bit value
#define CONCAT11(a, b) ((uint16_t)((uint16_t)((uint8_t)(a)) << 8 | (uint16_t)((uint8_t)(b))))
#define CONCAT12(a, b) ((uint32_t)((uint32_t)((uint8_t)(a)) << 16 | (uint32_t)((uint16_t)(b))))
#define CONCAT13(a, b) ((uint32_t)((uint32_t)((uint8_t)(a)) << 24 | (uint32_t)(b) & 0xFFFFFF))
#define CONCAT14(a, b) ((uint64_t)((uint64_t)((uint8_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))
#define CONCAT21(a, b) ((uint32_t)((uint32_t)((uint16_t)(a)) << 8 | (uint32_t)((uint8_t)(b))))
#define CONCAT22(a, b) ((uint32_t)((uint32_t)((uint16_t)(a)) << 16 | (uint32_t)((uint16_t)(b))))
#define CONCAT24(a, b) ((uint64_t)((uint64_t)((uint16_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))
#define CONCAT31(a, b) ((uint32_t)((uint32_t)(a) << 8 | (uint32_t)((uint8_t)(b))))
#define CONCAT44(a, b) ((uint64_t)((uint64_t)((uint32_t)(a)) << 32 | (uint64_t)((uint32_t)(b))))
"""


def generate_types_header(output_dir):
    """
    Generate firmware_types.hpp from structure_definitions.csv and enums.csv.

    Returns (content_str, stats_dict).
    """
    struct_csv = os.path.join(output_dir, 'structure_definitions.csv')
    enum_csv   = os.path.join(output_dir, 'enums.csv')

    # --- Parse structs -------------------------------------------------------
    struct_rows = read_csv_skip_comments(struct_csv)

    # Group fields by struct name, preserving insertion order
    structs = OrderedDict()
    for row in struct_rows:
        name = row.get('struct_name', '').strip()
        if not name:
            continue
        if name not in structs:
            structs[name] = []
        structs[name].append(row)

    struct_blocks = []
    for struct_name, fields in structs.items():
        lines = [f'typedef struct {{']
        for field in fields:
            field_name = field.get('field_name', '').strip()
            raw_type   = field.get('type', '').strip()
            try:
                size = int(field.get('size', '0').strip() or '0')
            except ValueError:
                size = 0
            comment = field.get('comment', '').strip()

            c_type = map_type(raw_type)
            decl   = field_declaration(field_name, c_type, size)
            if comment:
                lines.append(f'{decl}  /* {comment} */')
            else:
                lines.append(decl)
        lines.append(f'}} {struct_name};')
        struct_blocks.append('\n'.join(lines))

    # --- Parse enums ----------------------------------------------------------
    enum_rows = read_csv_skip_comments(enum_csv)

    enums = OrderedDict()
    for row in enum_rows:
        name = row.get('enum_name', '').strip()
        if not name:
            continue
        if name not in enums:
            enums[name] = []
        enums[name].append(row)

    enum_blocks = []
    for enum_name, members in enums.items():
        lines = [f'typedef enum {{']
        for i, member in enumerate(members):
            member_name = member.get('member_name', '').strip()
            value       = member.get('value', '').strip()
            comment     = member.get('comment', '').strip()
            is_last     = (i == len(members) - 1)
            comma       = '' if is_last else ','
            entry       = f'    {member_name} = {value}{comma}'
            if comment:
                lines.append(f'{entry}  /* {comment} */')
            else:
                lines.append(entry)
        lines.append(f'}} {enum_name};')
        enum_blocks.append('\n'.join(lines))

    # --- Assemble -------------------------------------------------------------
    parts = [TYPE_ALIAS_PREAMBLE]

    if struct_blocks:
        parts.append('/* ---- Structures ---- */')
        parts.append('\n\n'.join(struct_blocks))

    if enum_blocks:
        parts.append('\n/* ---- Enumerations ---- */')
        parts.append('\n\n'.join(enum_blocks))

    content = '\n\n'.join(parts) + '\n'

    stats = {
        'structs': len(structs),
        'struct_fields': len(struct_rows),
        'enums': len(enums),
        'enum_members': len(enum_rows),
    }
    return content, stats


# ---------------------------------------------------------------------------
# Task 3: firmware_globals.hpp
# ---------------------------------------------------------------------------

GLOBALS_TYPE_MAP = {
    'undefined':   'undefined',
    'undefined1':  'undefined1',
    'undefined2':  'undefined2',
    'undefined4':  'undefined4',
    'byte':        'byte',
    'short':       'short',
    'ushort':      'ushort',
    'int':         'int',
    'uint':        'uint',
    'word':        'word',
    'dword':       'dword',
    'pointer':     'void *',
    'undefined *': 'undefined *',
}

GLOBALS_HEADER_PREAMBLE = """\
#pragma once
#include "firmware_types.hpp"

// Global Variable Declarations (from global_variables.csv)
// Ghidra artifact entries (switchD, caseD_, etc.) are excluded.
"""

# Exact names that are Ghidra artifacts and must be excluded
_GLOBALS_EXCLUDE_EXACT = {'switchD', 'default', ''}

def _is_globals_artifact(name):
    """Return True if the name is a Ghidra artifact that should be excluded."""
    if name in _GLOBALS_EXCLUDE_EXACT:
        return True
    if name.startswith('caseD_'):
        return True
    if name.startswith('switchdataD_'):
        return True
    return False


def _map_globals_type(raw_type):
    """Map a CSV type string to a C type for globals declarations."""
    raw_type = raw_type.strip()
    if not raw_type:
        return 'undefined'
    return GLOBALS_TYPE_MAP.get(raw_type, raw_type)


def generate_globals_header(output_dir):
    """
    Generate firmware_globals.hpp from global_variables.csv.

    Returns (content_str, stats_dict).
    """
    csv_path = os.path.join(output_dir, 'global_variables.csv')
    rows = read_csv_skip_comments(csv_path)

    lines = [GLOBALS_HEADER_PREAMBLE]
    declared = 0
    excluded = 0

    for row in rows:
        name    = row.get('name', '').strip()
        address = row.get('address', '').strip()
        raw_type = row.get('type', '').strip()

        if _is_globals_artifact(name):
            excluded += 1
            continue

        c_type = _map_globals_type(raw_type)
        lines.append(f'extern {c_type} {name};  // {address}')
        declared += 1

    content = '\n'.join(lines) + '\n'
    stats = {'declared': declared, 'excluded': excluded}
    return content, stats


# ---------------------------------------------------------------------------
# Task 4: firmware_functions.hpp
# ---------------------------------------------------------------------------

def extract_function_signatures(cpp_path):
    """
    Parse function signatures from a .ghidra.cpp decompiled output file.

    The file structure around each function is:

        //
        // Function: <name> @ <addr>
        //

        [optional /* WARNING: ... */ comment lines]

        <return_type> <name>(<params>)    # may be split across multiple lines

        {

    Returns a list of (name, addr, signature_string) tuples where
    signature_string is the complete single-line signature, e.g.:
        "undefined1 diagMemoryReadWithBaseOffset(dword param_1, ...)"
    """
    with open(cpp_path) as f:
        text = f.read()

    # Split text by function header blocks.
    # Each match produces 3 items in the split: name, addr, body.
    header_pattern = re.compile(
        r'^//\n// Function: (.+?) @ (0x[0-9a-f]+)\n//\n',
        re.MULTILINE,
    )
    parts = header_pattern.split(text)

    # parts layout: [preamble, name0, addr0, body0, name1, addr1, body1, ...]
    names  = parts[1::3]
    addrs  = parts[2::3]
    bodies = parts[3::3]

    results = []
    for name, addr, body in zip(names, addrs, bodies):
        # Everything before the first '\n{' is the signature block.
        brace_idx = body.find('\n{')
        if brace_idx == -1:
            # No opening brace found — skip (shouldn't happen in well-formed output).
            continue
        pre_brace = body[:brace_idx]

        # Strip WARNING comment lines and blank lines.
        # WARNING blocks look like:
        #   /* WARNING: ... */
        # or span two lines:
        #   /* WARNING: ...
        #   */
        # Drop any line whose stripped form starts with '/*' or '*'.
        sig_lines = []
        for line in pre_brace.splitlines():
            stripped = line.strip()
            if not stripped:
                continue
            if stripped.startswith('/*') or stripped.startswith('*'):
                continue
            sig_lines.append(stripped)

        if not sig_lines:
            continue

        # Join multiple lines and collapse interior whitespace.
        signature = ' '.join(sig_lines)
        signature = re.sub(r'\s+', ' ', signature).strip()

        results.append((name, addr, signature))

    return results


def generate_functions_header(output_dir):
    """
    Generate firmware_functions.hpp with forward declarations for all
    functions found in the .ghidra.cpp decompiled output.

    Returns (content_str, stats_dict).
    """
    cpp_path = find_ghidra_cpp(output_dir)
    signatures = extract_function_signatures(cpp_path)

    lines = [
        '#pragma once',
        '#include "firmware_types.hpp"',
        '',
        '// Function Forward Declarations (from decompiled output)',
        '',
    ]

    for _name, addr, sig in signatures:
        lines.append(f'{sig};  // @ {addr}')

    content = '\n'.join(lines) + '\n'

    stats = {'functions': len(signatures)}
    return content, stats


# ---------------------------------------------------------------------------
# Task 5 stub: prepend #includes to .ghidra.cpp
# ---------------------------------------------------------------------------

INCLUDE_BLOCK = """\
#include "firmware_types.hpp"
#include "firmware_globals.hpp"
#include "firmware_functions.hpp"
"""


def prepend_includes(ghidra_cpp_path, dry_run=False):
    """Add #include lines to .ghidra.cpp after the header comments.

    Idempotent — skips if includes are already present.
    Returns dict with 'prepended' bool.
    """
    with open(ghidra_cpp_path) as f:
        content = f.read()

    if '#include "firmware_types.hpp"' in content:
        print(f"\n      Includes already present in {os.path.basename(ghidra_cpp_path)}")
        return {'prepended': False}

    # Insert after the "// Generated: ..." line + blank lines
    match = re.search(r'(// Generated:.*?\n)\n+', content)
    if match:
        insert_pos = match.end()
        new_content = content[:insert_pos] + INCLUDE_BLOCK + '\n' + content[insert_pos:]
    else:
        new_content = INCLUDE_BLOCK + '\n' + content

    if not dry_run:
        with open(ghidra_cpp_path, 'w') as f:
            f.write(new_content)
        print(f"\n      Added #include block to {os.path.basename(ghidra_cpp_path)}")
    return {'prepended': True}


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Generate C header files from Ghidra firmware analysis CSVs.'
    )
    parser.add_argument(
        'output_dir',
        help='Path to the firmware output/ directory containing CSVs and .ghidra.cpp'
    )
    parser.add_argument(
        '--dry-run',
        action='store_true',
        help='Print what would be generated without writing files'
    )
    args = parser.parse_args()

    output_dir = os.path.abspath(args.output_dir)
    if not os.path.isdir(output_dir):
        print(f"ERROR: output_dir does not exist: {output_dir}", file=sys.stderr)
        sys.exit(1)

    # Locate the .ghidra.cpp file
    try:
        ghidra_cpp = find_ghidra_cpp(output_dir)
        print(f"Found .ghidra.cpp: {os.path.basename(ghidra_cpp)}")
    except FileNotFoundError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        sys.exit(1)

    # Determine header output directory (alongside the .ghidra.cpp)
    header_dir = output_dir

    # --- firmware_types.hpp --------------------------------------------------
    print("\n[1/3] Generating firmware_types.hpp ...")
    types_content, types_stats = generate_types_header(output_dir)
    print(f"      Structs: {types_stats['structs']}  ({types_stats['struct_fields']} fields)")
    print(f"      Enums:   {types_stats['enums']}  ({types_stats['enum_members']} members)")

    types_path = os.path.join(header_dir, 'firmware_types.hpp')
    if args.dry_run:
        preview_lines = types_content.splitlines()[:30]
        print(f"\n      --- firmware_types.hpp preview (first 30 lines) ---")
        for line in preview_lines:
            print(f"      {line}")
        if len(types_content.splitlines()) > 30:
            print(f"      ... ({len(types_content.splitlines())} lines total)")
    else:
        write_file(types_path, types_content)
        print(f"      Written: {types_path}")

    # --- firmware_globals.hpp ------------------------------------------------
    print("\n[2/3] Generating firmware_globals.hpp ...")
    globals_content, globals_stats = generate_globals_header(output_dir)
    print(f"      Globals: {globals_stats['declared']} declared, {globals_stats['excluded']} excluded")

    globals_path = os.path.join(header_dir, 'firmware_globals.hpp')
    if args.dry_run:
        print(f"      (dry-run) Would write: {globals_path}")
    else:
        write_file(globals_path, globals_content)
        print(f"      Written: {globals_path}")

    # --- firmware_functions.hpp ----------------------------------------------
    print("\n[3/3] Generating firmware_functions.hpp ...")
    functions_content, functions_stats = generate_functions_header(output_dir)
    print(f"      Functions: {functions_stats['functions']} forward declarations")

    functions_path = os.path.join(header_dir, 'firmware_functions.hpp')
    if args.dry_run:
        print(f"      (dry-run) Would write: {functions_path}")
    else:
        write_file(functions_path, functions_content)
        print(f"      Written: {functions_path}")

    # --- prepend #includes ----------------------------------------------------
    prepend_result = prepend_includes(ghidra_cpp, dry_run=args.dry_run)
    if args.dry_run and prepend_result['prepended']:
        print(f"\n      (dry-run) Would add #include block to {os.path.basename(ghidra_cpp)}")

    print("\nDone.")


if __name__ == '__main__':
    main()
