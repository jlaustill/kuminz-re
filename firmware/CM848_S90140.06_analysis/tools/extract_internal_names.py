#!/usr/bin/env python3
"""
Extract internal variable names from e2m files and create a searchable reference.
Internal names appear in descriptions as [VARNAME] and often match firmware symbols.
"""

import sys
import re
import csv
from pathlib import Path
from collections import defaultdict

def extract_internal_names(e2m_file):
    """Extract internal names and their associated parameters."""
    names = defaultdict(list)

    with open(e2m_file, 'r', errors='replace') as f:
        for line in f:
            # Look for [VARNAME] pattern in the line
            matches = re.findall(r'\[([A-Z0-9_]+)\]', line)
            if not matches:
                continue

            # Parse the parameter name (first field before comma)
            parts = line.split(',')
            if not parts:
                continue

            param_name = parts[0].strip()

            # Get description (after semicolon)
            desc_match = line.split(';', 1)
            description = desc_match[1].strip() if len(desc_match) > 1 else ""

            for internal_name in matches:
                names[internal_name].append({
                    'parameter': param_name,
                    'description': description,
                    'line': line.strip()[:200],
                })

    return names

def generate_reference(names, output_dir):
    """Generate reference files."""
    output_dir = Path(output_dir)

    # CSV of internal names -> parameter mappings
    csv_file = output_dir / 'internal_names.csv'
    with open(csv_file, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['internal_name', 'parameter', 'description'])
        for name, entries in sorted(names.items()):
            for entry in entries:
                writer.writerow([name, entry['parameter'], entry['description'][:200]])

    print(f"Wrote {csv_file}")

    # Markdown reference document
    md_file = output_dir / 'internal_names_reference.md'
    with open(md_file, 'w') as f:
        f.write("# CM848 Internal Variable Names Reference\n\n")
        f.write("These internal names from e2m calibration files may match firmware symbols.\n\n")
        f.write(f"**Total unique names:** {len(names)}\n\n")

        # Group by prefix
        prefixes = defaultdict(list)
        for name in names:
            prefix = re.match(r'^([A-Z]+)', name)
            if prefix:
                prefixes[prefix.group(1)].append(name)
            else:
                prefixes['_OTHER'].append(name)

        f.write("## Names by Prefix\n\n")
        for prefix in sorted(prefixes.keys()):
            f.write(f"### {prefix} ({len(prefixes[prefix])} names)\n\n")
            for name in sorted(prefixes[prefix])[:20]:  # Limit to 20 per prefix
                entries = names[name]
                desc = entries[0]['description'][:100] if entries else ""
                f.write(f"- **{name}**: {desc}\n")
            if len(prefixes[prefix]) > 20:
                f.write(f"- ... and {len(prefixes[prefix]) - 20} more\n")
            f.write("\n")

    print(f"Wrote {md_file}")

    # Simple list for grep searching
    list_file = output_dir / 'internal_names.txt'
    with open(list_file, 'w') as f:
        for name in sorted(names.keys()):
            f.write(f"{name}\n")

    print(f"Wrote {list_file}")

    return len(names)

def main():
    if len(sys.argv) < 3:
        print("Usage: extract_internal_names.py <e2m_file> <output_dir>")
        sys.exit(1)

    e2m_file = sys.argv[1]
    output_dir = sys.argv[2]

    print(f"Extracting internal names from {e2m_file}...")
    names = extract_internal_names(e2m_file)
    print(f"Found {len(names)} unique internal names")

    count = generate_reference(names, output_dir)
    print(f"Generated reference with {count} entries")

if __name__ == '__main__':
    main()
