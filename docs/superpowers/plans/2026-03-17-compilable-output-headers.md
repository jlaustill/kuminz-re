# Phase 1: Compilable Output Headers — Implementation Plan

> **For agentic workers:** REQUIRED: Use superpowers:subagent-driven-development (if subagents available) or superpowers:executing-plans to implement this plan. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Generate `.hpp` header files from existing CSVs and decompiled output so each firmware's `.ghidra.cpp` has proper type definitions, global declarations, and forward declarations — the scaffolding for eventually-compilable output.

**Architecture:** A single Python script (`generate_headers.py`) reads the CSV knowledge database and parses function signatures from the `.ghidra.cpp` file, producing three `.hpp` files per firmware. The script is firmware-agnostic — it takes paths as arguments and works identically for CM550 and CM848.

**Tech Stack:** Python 3 (standard library only — csv, re, os, argparse)

---

## File Structure

| File | Responsibility |
|------|---------------|
| `firmware/scripts/generate_headers.py` | Main script — reads CSVs + `.ghidra.cpp`, writes 3 `.hpp` files, prepends `#include` to `.cpp` |
| `<fw>/output/firmware_types.hpp` | Ghidra type aliases + struct definitions + enum definitions |
| `<fw>/output/firmware_globals.hpp` | `extern` declarations for all named global variables |
| `<fw>/output/firmware_functions.hpp` | Forward declarations for all decompiled functions |

Where `<fw>` = `firmware/CM550_J90350.00_analysis` or `firmware/CM848_S90140.06_analysis`.

---

## Chunk 1: Core Script + Type Header

### Task 1: Create script skeleton with argument parsing

**Files:**
- Create: `firmware/scripts/generate_headers.py`

- [ ] **Step 1: Write the script skeleton**

```python
#!/usr/bin/env python3
"""Generate .hpp header files from Ghidra CSV exports and decompiled output.

Usage:
    python3 generate_headers.py <output_dir>

Where <output_dir> contains:
    - global_variables.csv
    - structure_definitions.csv
    - enums.csv
    - *.ghidra.cpp (exactly one)
"""

import argparse
import csv
import os
import re
import sys
from collections import OrderedDict


def parse_args():
    parser = argparse.ArgumentParser(
        description='Generate .hpp headers from Ghidra CSV exports')
    parser.add_argument('output_dir',
                        help='Path to firmware output/ directory containing CSVs and .ghidra.cpp')
    parser.add_argument('--dry-run', action='store_true',
                        help='Print what would be generated without writing files')
    return parser.parse_args()


def find_ghidra_cpp(output_dir):
    """Find the single .ghidra.cpp file in the output directory."""
    candidates = [f for f in os.listdir(output_dir) if f.endswith('.ghidra.cpp')]
    if len(candidates) != 1:
        print(f"Error: expected exactly 1 .ghidra.cpp in {output_dir}, found {len(candidates)}",
              file=sys.stderr)
        sys.exit(1)
    return os.path.join(output_dir, candidates[0])


def main():
    args = parse_args()
    output_dir = os.path.abspath(args.output_dir)

    if not os.path.isdir(output_dir):
        print(f"Error: {output_dir} is not a directory", file=sys.stderr)
        sys.exit(1)

    cpp_path = find_ghidra_cpp(output_dir)
    firmware_name = os.path.basename(cpp_path).replace('.ghidra.cpp', '')
    print(f"Firmware: {firmware_name}")
    print(f"Output dir: {output_dir}")

    # Phase 1: Generate firmware_types.hpp
    types_content = generate_types_header(output_dir)

    # Phase 2: Generate firmware_globals.hpp
    globals_content = generate_globals_header(output_dir)

    # Phase 3: Generate firmware_functions.hpp
    functions_content = generate_functions_header(cpp_path)

    if args.dry_run:
        print(f"\n--- firmware_types.hpp ({types_content.count(chr(10))} lines) ---")
        print(types_content[:500] + "\n...")
        print(f"\n--- firmware_globals.hpp ({globals_content.count(chr(10))} lines) ---")
        print(globals_content[:500] + "\n...")
        print(f"\n--- firmware_functions.hpp ({functions_content.count(chr(10))} lines) ---")
        print(functions_content[:500] + "\n...")
    else:
        write_file(os.path.join(output_dir, 'firmware_types.hpp'), types_content)
        write_file(os.path.join(output_dir, 'firmware_globals.hpp'), globals_content)
        write_file(os.path.join(output_dir, 'firmware_functions.hpp'), functions_content)
        prepend_includes(cpp_path)
        print("Done.")


def write_file(path, content):
    with open(path, 'w') as f:
        f.write(content)
    print(f"  Wrote {path} ({content.count(chr(10))} lines)")


if __name__ == '__main__':
    main()
```

- [ ] **Step 2: Verify script runs with --help**

Run: `python3 firmware/scripts/generate_headers.py --help`
Expected: Usage message showing `output_dir` argument and `--dry-run` flag.

- [ ] **Step 3: Commit skeleton**

```bash
git add firmware/scripts/generate_headers.py
git commit -m "feat: Add generate_headers.py skeleton for compilable firmware output"
```

---

### Task 2: Implement firmware_types.hpp generation

**Files:**
- Modify: `firmware/scripts/generate_headers.py`

This task adds the `generate_types_header()` function that produces the type aliases, struct definitions, and enum definitions.

- [ ] **Step 1: Add Ghidra type alias block**

Add this function to the script:

```python
GHIDRA_TYPE_PREAMBLE = """\
#pragma once

// =============================================================================
// Ghidra Primitive Type Aliases
// =============================================================================
// These map Ghidra's decompiler output types to C types.
// "undefined" types are placeholders — they'll get proper types as RE progresses.

#include <stdint.h>

typedef uint8_t   undefined;    // Ghidra default — unknown size, assume byte
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;
typedef uint64_t  undefined8;
typedef uint8_t   byte;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint16_t  word;
typedef uint32_t  dword;
typedef int32_t   bool32;       // Ghidra uses int-sized bool in some contexts

"""
```

- [ ] **Step 2: Add struct parser**

Reads `structure_definitions.csv` and emits C struct typedefs. The CSV format is:
`struct_name,address,field_name,type,size,comment,dependency,Status`

Multiple rows share the same `struct_name` — each row is one field.

```python
# Map CSV types to C types
STRUCT_TYPE_MAP = {
    'byte': 'uint8_t',
    'word': 'uint16_t',
    'dword': 'uint32_t',
    'uint8_t': 'uint8_t',
    'uint16_t': 'uint16_t',
    'uint32_t': 'uint32_t',
    'int8_t': 'int8_t',
    'int16_t': 'int16_t',
    'int32_t': 'int32_t',
    'short': 'int16_t',
    'int': 'int32_t',
    'char': 'char',
}


def parse_structs(output_dir):
    """Parse structure_definitions.csv into ordered dict of struct_name -> [fields]."""
    csv_path = os.path.join(output_dir, 'structure_definitions.csv')
    if not os.path.exists(csv_path):
        return OrderedDict()

    structs = OrderedDict()
    with open(csv_path, newline='') as f:
        reader = csv.DictReader(
            (row for row in f if not row.startswith('#')),
            fieldnames=['struct_name', 'address', 'field_name', 'type', 'size', 'comment', 'dependency', 'Status']
        )
        next(reader)  # skip CSV header
        for row in reader:
            name = row['struct_name'].strip()
            if not name:
                continue
            if name not in structs:
                structs[name] = []
            field_type = row['type'].strip()
            # Handle pointer types like "ptr:uint8_t"
            if field_type.startswith('ptr:'):
                inner = STRUCT_TYPE_MAP.get(field_type[4:], field_type[4:])
                c_type = f'{inner} *'
            else:
                c_type = STRUCT_TYPE_MAP.get(field_type, field_type if field_type else 'undefined')
            size = int(row['size']) if row['size'].strip() else 0
            # Arrays: if size > type width, emit as array
            type_widths = {'uint8_t': 1, 'int8_t': 1, 'char': 1,
                           'uint16_t': 2, 'int16_t': 2,
                           'uint32_t': 4, 'int32_t': 4}
            base_width = type_widths.get(c_type.replace(' *', ''), 0)
            array_count = 0
            if base_width > 0 and size > base_width and '*' not in c_type:
                array_count = size // base_width

            structs[name].append({
                'field_name': row['field_name'].strip(),
                'c_type': c_type,
                'array_count': array_count,
                'comment': row['comment'].strip() if row.get('comment') else '',
            })
    return structs


def emit_structs(structs):
    """Generate C struct typedef strings."""
    lines = []
    lines.append('// =============================================================================')
    lines.append('// Structure Definitions (from structure_definitions.csv)')
    lines.append('// =============================================================================\n')
    for struct_name, fields in structs.items():
        lines.append(f'typedef struct {{')
        for field in fields:
            arr = f'[{field["array_count"]}]' if field['array_count'] > 0 else ''
            comment = f'  // {field["comment"]}' if field['comment'] else ''
            lines.append(f'    {field["c_type"]} {field["field_name"]}{arr};{comment}')
        lines.append(f'}} {struct_name};\n')
    return '\n'.join(lines)
```

- [ ] **Step 3: Add enum parser**

Reads `enums.csv`. Format: `enum_name,value,member_name,comment,size`
Multiple rows per enum.

```python
def parse_enums(output_dir):
    """Parse enums.csv into ordered dict of enum_name -> [members]."""
    csv_path = os.path.join(output_dir, 'enums.csv')
    if not os.path.exists(csv_path):
        return OrderedDict()

    enums = OrderedDict()
    with open(csv_path, newline='') as f:
        reader = csv.DictReader(
            (row for row in f if not row.startswith('#')),
            fieldnames=['enum_name', 'value', 'member_name', 'comment', 'size']
        )
        next(reader)  # skip CSV header
        for row in reader:
            name = row['enum_name'].strip()
            if not name:
                continue
            if name not in enums:
                enums[name] = []
            enums[name].append({
                'member': row['member_name'].strip(),
                'value': row['value'].strip(),
                'comment': row['comment'].strip() if row.get('comment') else '',
            })
    return enums


def emit_enums(enums):
    """Generate C enum typedef strings."""
    lines = []
    lines.append('// =============================================================================')
    lines.append('// Enum Definitions (from enums.csv)')
    lines.append('// =============================================================================\n')
    for enum_name, members in enums.items():
        lines.append(f'typedef enum {{')
        for i, m in enumerate(members):
            comma = ',' if i < len(members) - 1 else ''
            comment = f'  // {m["comment"]}' if m['comment'] else ''
            lines.append(f'    {m["member"]} = {m["value"]}{comma}{comment}')
        lines.append(f'}} {enum_name};\n')
    return '\n'.join(lines)
```

- [ ] **Step 4: Wire it together in generate_types_header()**

```python
def generate_types_header(output_dir):
    """Generate firmware_types.hpp content."""
    parts = [GHIDRA_TYPE_PREAMBLE]

    structs = parse_structs(output_dir)
    if structs:
        parts.append(emit_structs(structs))
        print(f"  Types: {len(structs)} structs")

    enums = parse_enums(output_dir)
    if enums:
        parts.append(emit_enums(enums))
        print(f"  Types: {len(enums)} enums")

    return '\n'.join(parts) + '\n'
```

- [ ] **Step 5: Test with --dry-run on CM848**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM848_S90140.06_analysis/output --dry-run`
Expected: Output showing struct count (~40), enum count, and first 500 chars of firmware_types.hpp.

- [ ] **Step 6: Test with --dry-run on CM550**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM550_J90350.00_analysis/output --dry-run`
Expected: Similar output with CM550's structs and enums.

- [ ] **Step 7: Commit**

```bash
git add firmware/scripts/generate_headers.py
git commit -m "feat: Add firmware_types.hpp generation (structs + enums + type aliases)"
```

---

## Chunk 2: Globals Header

### Task 3: Implement firmware_globals.hpp generation

**Files:**
- Modify: `firmware/scripts/generate_headers.py`

- [ ] **Step 1: Add globals parser with artifact filtering**

```python
# Ghidra artifact patterns to exclude from globals header
GLOBALS_EXCLUDE_PATTERNS = re.compile(
    r'^(switchD|caseD_|switchdataD_|default)$'
)

# Type mapping from CSV type column to C declaration type
GLOBALS_TYPE_MAP = {
    'undefined': 'undefined',
    'undefined1': 'undefined1',
    'undefined2': 'undefined2',
    'undefined4': 'undefined4',
    'byte': 'byte',
    'short': 'short',
    'ushort': 'ushort',
    'int': 'int',
    'uint': 'uint',
    'word': 'word',
    'dword': 'dword',
    'pointer': 'void *',
    'undefined *': 'undefined *',
    '': 'undefined',  # missing type defaults to undefined
}


def generate_globals_header(output_dir):
    """Generate firmware_globals.hpp from global_variables.csv."""
    csv_path = os.path.join(output_dir, 'global_variables.csv')
    if not os.path.exists(csv_path):
        return '#pragma once\n// No global_variables.csv found\n'

    lines = [
        '#pragma once',
        '#include "firmware_types.hpp"',
        '',
        '// =============================================================================',
        '// Global Variable Declarations (from global_variables.csv)',
        '// =============================================================================',
        '// Ghidra artifact entries (switchD, caseD_, etc.) are excluded.',
        '// Variables with "_" prefix have overlapping symbols at the same address.',
        '',
    ]

    included = 0
    excluded = 0
    struct_typed = 0

    with open(csv_path, newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            name = row['name'].strip()
            addr = row['address'].strip()
            raw_type = row.get('type', '').strip()
            comment = row.get('comment', '').strip()

            # Skip Ghidra artifacts
            if GLOBALS_EXCLUDE_PATTERNS.match(name):
                excluded += 1
                continue

            # Skip empty names
            if not name:
                excluded += 1
                continue

            # Map type
            c_type = GLOBALS_TYPE_MAP.get(raw_type)
            if c_type is None:
                # Could be a struct type (e.g., "uds_response_t") — use as-is
                c_type = raw_type
                struct_typed += 1

            # Build declaration
            addr_comment = f'// {addr}'
            if comment:
                addr_comment += f' - {comment}'
            lines.append(f'extern {c_type} {name};  {addr_comment}')
            included += 1

    lines.append('')
    print(f"  Globals: {included} declared, {excluded} artifacts excluded, {struct_typed} struct-typed")
    return '\n'.join(lines) + '\n'
```

- [ ] **Step 2: Test with --dry-run on CM550**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM550_J90350.00_analysis/output --dry-run`
Expected: Shows ~5700+ declared, ~400+ excluded (switchD/caseD artifacts).

- [ ] **Step 3: Test with --dry-run on CM848**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM848_S90140.06_analysis/output --dry-run`
Expected: Shows ~4600+ declared, ~800+ excluded.

- [ ] **Step 4: Commit**

```bash
git add firmware/scripts/generate_headers.py
git commit -m "feat: Add firmware_globals.hpp generation with artifact filtering"
```

---

## Chunk 3: Functions Header + Include Prepend

### Task 4: Implement firmware_functions.hpp generation

**Files:**
- Modify: `firmware/scripts/generate_headers.py`

- [ ] **Step 1: Add function signature parser**

Handles both single-line and multi-line signatures, skipping WARNING comments.

```python
def extract_function_signatures(cpp_path):
    """Parse function signatures from .ghidra.cpp file.

    Returns list of (name, address, signature_line) tuples.
    Handles:
    - Single-line: "void foo(int x)"
    - Multi-line: "undefined1\\nfoo(int x, int y)"  (Ghidra wraps long param lists)
    - WARNING comments between // block and signature
    """
    with open(cpp_path) as f:
        text = f.read()

    # Split by function header comments
    # Pattern: //\n// Function: <name> @ <addr>\n//\n
    parts = re.split(
        r'^//\n// Function: (.+?) @ (0x[0-9a-f]+)\n//\n',
        text,
        flags=re.MULTILINE
    )

    signatures = []
    # parts layout: [preamble, name1, addr1, body1, name2, addr2, body2, ...]
    for i in range(1, len(parts) - 2, 3):
        name = parts[i]
        addr = parts[i + 1]
        body = parts[i + 2]

        # Find everything before the opening brace
        brace_match = re.search(r'\n\{', body)
        if not brace_match:
            continue
        before_brace = body[:brace_match.start()]

        # Strip WARNING comments and blank lines
        sig_lines = []
        for line in before_brace.strip().split('\n'):
            stripped = line.strip()
            if not stripped:
                continue
            if stripped.startswith('/*') or stripped.startswith('*'):
                continue
            sig_lines.append(stripped)

        if not sig_lines:
            continue

        # Reassemble signature (join multi-line, collapse whitespace)
        raw_sig = ' '.join(sig_lines)
        raw_sig = re.sub(r'\s+', ' ', raw_sig).strip()

        signatures.append((name, addr, raw_sig))

    return signatures


def generate_functions_header(cpp_path):
    """Generate firmware_functions.hpp from decompiled .ghidra.cpp."""
    signatures = extract_function_signatures(cpp_path)

    lines = [
        '#pragma once',
        '#include "firmware_types.hpp"',
        '',
        '// =============================================================================',
        '// Function Forward Declarations (from decompiled output)',
        '// =============================================================================',
        '',
    ]

    for name, addr, sig in signatures:
        # Append semicolon to make it a declaration
        lines.append(f'{sig};  // @ {addr}')

    lines.append('')
    print(f"  Functions: {len(signatures)} forward declarations")
    return '\n'.join(lines) + '\n'
```

- [ ] **Step 2: Test with --dry-run on CM550**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM550_J90350.00_analysis/output --dry-run`
Expected: Shows ~773 forward declarations. First few should look like:
`short huffmanTreeBuilder(int param_1);  // @ 0x00003640`

- [ ] **Step 3: Test with --dry-run on CM848**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM848_S90140.06_analysis/output --dry-run`
Expected: Shows ~2244 forward declarations. Multi-line signatures should be properly collapsed.

- [ ] **Step 4: Commit**

```bash
git add firmware/scripts/generate_headers.py
git commit -m "feat: Add firmware_functions.hpp generation with multi-line signature handling"
```

---

### Task 5: Add #include prepend to .ghidra.cpp

**Files:**
- Modify: `firmware/scripts/generate_headers.py`

- [ ] **Step 1: Add prepend_includes function**

Inserts `#include` lines after the existing comment header, idempotently (won't double-add).

```python
INCLUDE_BLOCK = """\
#include "firmware_types.hpp"
#include "firmware_globals.hpp"
#include "firmware_functions.hpp"
"""


def prepend_includes(cpp_path):
    """Add #include lines to the .ghidra.cpp file after the header comments.

    Idempotent — skips if includes are already present.
    """
    with open(cpp_path) as f:
        content = f.read()

    if '#include "firmware_types.hpp"' in content:
        print(f"  Includes already present in {os.path.basename(cpp_path)}")
        return

    # Insert after the "// Generated: ..." line and blank lines
    # Pattern: header comment block ends with two blank lines before first function
    match = re.search(r'(// Generated:.*?\n)\n+', content)
    if match:
        insert_pos = match.end()
        new_content = content[:insert_pos] + INCLUDE_BLOCK + '\n' + content[insert_pos:]
    else:
        # Fallback: insert at the very top
        new_content = INCLUDE_BLOCK + '\n' + content

    with open(cpp_path, 'w') as f:
        f.write(new_content)
    print(f"  Added #include block to {os.path.basename(cpp_path)}")
```

- [ ] **Step 2: Test on CM550 (full run, not dry-run)**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM550_J90350.00_analysis/output`
Expected: Creates 3 `.hpp` files in output/ and modifies `.ghidra.cpp`.

Verify includes were added:
Run: `head -10 firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp`
Expected: Shows `#include "firmware_types.hpp"` etc. after the Generated line.

- [ ] **Step 3: Verify idempotency**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM550_J90350.00_analysis/output`
Expected: "Includes already present" message. File unchanged.

- [ ] **Step 4: Test on CM848 (full run)**

Run: `python3 firmware/scripts/generate_headers.py firmware/CM848_S90140.06_analysis/output`
Expected: Creates 3 `.hpp` files and modifies CM848's `.ghidra.cpp`.

- [ ] **Step 5: Commit all generated files**

```bash
git add firmware/scripts/generate_headers.py
git add firmware/CM550_J90350.00_analysis/output/firmware_types.hpp
git add firmware/CM550_J90350.00_analysis/output/firmware_globals.hpp
git add firmware/CM550_J90350.00_analysis/output/firmware_functions.hpp
git add firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp
git add firmware/CM848_S90140.06_analysis/output/firmware_types.hpp
git add firmware/CM848_S90140.06_analysis/output/firmware_globals.hpp
git add firmware/CM848_S90140.06_analysis/output/firmware_functions.hpp
git add firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
git commit -m "feat: Generate compilable output headers for both firmwares

Phase 1 of cross-firmware convergence pipeline.
- firmware_types.hpp: Ghidra type aliases + structs + enums
- firmware_globals.hpp: extern declarations for all named globals
- firmware_functions.hpp: forward declarations from decompiled output
- .ghidra.cpp: #include preamble added"
```

---

## Chunk 4: Validation

### Task 6: Syntax validation with gcc

**Files:**
- No new files — validation only

- [ ] **Step 1: Attempt gcc syntax check on CM550**

Run: `cd firmware/CM550_J90350.00_analysis/output && gcc -fsyntax-only -c J90350.00.ghidra.cpp 2>&1 | head -30`
Expected: Errors should be only type-related (unknown types, undeclared identifiers from Ghidra quirks), NOT syntax errors (missing semicolons, malformed declarations). Count total errors.

- [ ] **Step 2: Attempt gcc syntax check on CM848**

Run: `cd firmware/CM848_S90140.06_analysis/output && gcc -fsyntax-only -c cm848_rom.ghidra.cpp 2>&1 | head -30`
Expected: Same — type errors acceptable, syntax errors not.

- [ ] **Step 3: Spot-check generated headers**

Manually review a few entries in each header:
- `firmware_types.hpp`: Do struct fields match the CSV? Are enum values correct?
- `firmware_globals.hpp`: Are switchD/caseD entries excluded? Are addresses in comments?
- `firmware_functions.hpp`: Do multi-line signatures collapse correctly? Do FUN_ unnamed functions get declarations too?

- [ ] **Step 4: Count stats and log results**

Run:
```bash
echo "=== CM550 ==="
wc -l firmware/CM550_J90350.00_analysis/output/firmware_types.hpp
wc -l firmware/CM550_J90350.00_analysis/output/firmware_globals.hpp
wc -l firmware/CM550_J90350.00_analysis/output/firmware_functions.hpp
echo "=== CM848 ==="
wc -l firmware/CM848_S90140.06_analysis/output/firmware_types.hpp
wc -l firmware/CM848_S90140.06_analysis/output/firmware_globals.hpp
wc -l firmware/CM848_S90140.06_analysis/output/firmware_functions.hpp
```

Expected approximate line counts:
- CM550: types ~200, globals ~5800, functions ~780
- CM848: types ~400, globals ~4700, functions ~2250

---

## Notes for Implementer

**CSV parsing gotchas:**
- Comment lines start with `#` — skip them when parsing
- `structure_definitions.csv` header row: `struct_name,address,field_name,type,size,comment,dependency,Status`
- `enums.csv` header row: `enum_name,value,member_name,comment,size`
- `global_variables.csv` header row: `address,name,type,comment`
- Some enum entries have no `size` column value — handle gracefully
- CM550 struct CSV has a large comment block at the top (skip lines starting with `#`)

**Signature parsing gotchas:**
- CM848 has 60 multi-line signatures where return type and function name are on separate lines
- Example: `undefined1\ndiagMemoryReadWithBaseOffset(dword param_1, ...)`
- The parser must join these into one line: `undefined1 diagMemoryReadWithBaseOffset(dword param_1, ...)`
- WARNING comments appear between `//` header and signature — always skip `/* ... */` lines
- CM550 has 1 multi-line signature, CM848 has 60

**Relevant docs:**
- Spec: `docs/superpowers/specs/2026-03-17-cross-firmware-convergence-pipeline-design.md`
- Firmware CLAUDE.md: `firmware/CLAUDE.md` (CSV formats, workflow)
- Existing export script: `firmware/scripts/ExportAnalysis.java` (reference for current output format)
