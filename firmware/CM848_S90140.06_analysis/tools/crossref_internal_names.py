#!/usr/bin/env python3
"""
Cross-reference internal variable names from e2m with decompiled firmware.
Generates suggestions for naming unnamed RAM variables in Ghidra.
"""

import sys
import re
import csv
from pathlib import Path
from collections import defaultdict

# Known sensor name mappings (from existing decompiled code)
KNOWN_MAPPINGS = {
    '_coolant_temp_sensor': 'ADCLTP',  # Coolant Temperature
    '_oil_pressure_sensor': 'ADOLPR',  # Oil Pressure
    '_boost_pressure_filtered': 'ADBSPR',  # Boost Pressure
    '_intake_air_temp_sensor': 'ADIMTP',  # Intake Manifold Temperature
    '_fuel_demand_fault_flag': 'FSFDFF',  # Fuel System Fault Flag
    '_throttle_position_filtered': 'ADSATH',  # Sampled Throttle
}

# Internal name prefix descriptions
PREFIX_DESCRIPTIONS = {
    'AD': 'A/D Converter (sensor inputs, filtering)',
    'JC': 'J1939 CAN Protocol',
    'HS': 'High Speed / Horsepower System',
    'EP': 'Engine Protection',
    'LS': 'Limiting System',
    'PT': 'Protection / Power Train',
    'AS': 'Acceleration System',
    'FS': 'Fuel System',
    'MX': 'Maximum Limits',
    'CK': 'Check / Crank',
    'DG': 'Diagnostics',
    'TS': 'Throttle System',
    'CT': 'Control',
    'SS': 'Sensor System',
    'ES': 'Engine System',
    'CR': 'Crank Control',
    'SD': 'Shutdown',
    'OC': 'Output Control',
    'VS': 'Vehicle Speed',
}

# Suffix meanings for AD prefix
AD_SUFFIXES = {
    'CC': 'Fault Clear',
    'CS': 'Filter Constant',
    'DT': 'Fault Decrement',
    'HE': 'High Error',
    'HL': 'High Limit',
    'IC': 'Fault Increment',
    'LE': 'Low Error',
    'LL': 'Low Limit',
    'OD': 'Override',
    'SE': 'Fault Set',
    'XA': 'X Axis',
    'YA': 'Y Axis',
    'PZ': 'Priority',
}


def load_internal_names(csv_path):
    """Load internal names from CSV."""
    names = {}
    with open(csv_path, 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            names[row['internal_name']] = {
                'parameter': row['parameter'],
                'description': row['description'],
            }
    return names


def extract_dat_variables(cpp_path):
    """Extract unnamed DAT_ variables from decompiled code."""
    variables = defaultdict(list)

    with open(cpp_path, 'r') as f:
        current_function = None
        for line_num, line in enumerate(f, 1):
            # Track current function
            func_match = re.search(r'// Function: (\w+) @', line)
            if func_match:
                current_function = func_match.group(1)
                continue

            # Find DAT_ references in RAM range
            for match in re.finditer(r'(DAT_003f[a-f0-9]{4}|DAT_0040[a-f0-9]{4})', line):
                var_name = match.group(1)
                variables[var_name].append({
                    'function': current_function,
                    'line': line_num,
                    'context': line.strip()[:100],
                })

    return variables


def find_pattern_matches(variables, internal_names):
    """Find potential matches between DAT_ variables and internal names."""
    matches = []

    for var_name, contexts in variables.items():
        # Get function context
        functions = set(ctx['function'] for ctx in contexts if ctx['function'])

        # Look for clues in function names
        suggestions = []
        for func in functions:
            if not func:
                continue
            func_lower = func.lower()

            # Match based on function name keywords
            if 'coolant' in func_lower or 'temp' in func_lower:
                suggestions.append(('ADCLTP', 'Coolant_Temperature'))
            if 'oil' in func_lower and 'pressure' in func_lower:
                suggestions.append(('ADOLPR', 'Oil_Pressure'))
            if 'boost' in func_lower:
                suggestions.append(('ADBSPR', 'Boost_Pressure'))
            if 'fuel' in func_lower:
                suggestions.append(('FS', 'Fuel_System'))
            if 'protection' in func_lower:
                suggestions.append(('EP', 'Engine_Protection'))
            if 'throttle' in func_lower:
                suggestions.append(('ADSATH', 'Throttle'))
            if 'fault' in func_lower:
                suggestions.append(('DG', 'Diagnostic'))

        if suggestions:
            matches.append({
                'variable': var_name,
                'suggestions': suggestions,
                'contexts': contexts[:3],  # First 3 contexts
            })

    return matches


def generate_report(matches, internal_names, output_path):
    """Generate a cross-reference report."""
    with open(output_path, 'w') as f:
        f.write("# CM848 Internal Names Cross-Reference Report\n\n")
        f.write("Variables from decompiled code matched with e2m internal names.\n\n")

        f.write("## Prefix Reference\n\n")
        for prefix, desc in sorted(PREFIX_DESCRIPTIONS.items()):
            f.write(f"- **{prefix}**: {desc}\n")
        f.write("\n")

        f.write("## Suggested Matches\n\n")

        # Group by suggestion type
        by_type = defaultdict(list)
        for match in matches:
            for prefix, name in match['suggestions']:
                by_type[prefix].append(match)

        for prefix in sorted(by_type.keys()):
            desc = PREFIX_DESCRIPTIONS.get(prefix, 'Unknown')
            f.write(f"### {prefix} - {desc}\n\n")

            seen = set()
            for match in by_type[prefix][:20]:  # Limit to 20 per type
                if match['variable'] in seen:
                    continue
                seen.add(match['variable'])

                f.write(f"**{match['variable']}**\n")
                for ctx in match['contexts'][:2]:
                    f.write(f"  - In `{ctx['function']}`: `{ctx['context'][:60]}...`\n")
                f.write("\n")

        f.write("\n## Statistics\n\n")
        f.write(f"- Total internal names: {len(internal_names)}\n")
        f.write(f"- Variables with suggested matches: {len(matches)}\n")


def main():
    base_dir = Path('/home/linux/code/kuminz-re/firmware/CM848_S90140.06_analysis')

    internal_names_csv = base_dir / 'output' / 'internal_names.csv'
    decompiled_cpp = base_dir / 'output' / 'cm848_rom.ghidra.cpp'
    output_report = base_dir / 'output' / 'internal_names_crossref.md'

    print(f"Loading internal names from {internal_names_csv}...")
    internal_names = load_internal_names(internal_names_csv)
    print(f"Loaded {len(internal_names)} internal names")

    print(f"\nExtracting DAT_ variables from {decompiled_cpp}...")
    variables = extract_dat_variables(decompiled_cpp)
    print(f"Found {len(variables)} unique DAT_ variables in RAM range")

    print("\nFinding pattern matches...")
    matches = find_pattern_matches(variables, internal_names)
    print(f"Found {len(matches)} variables with suggested matches")

    print(f"\nGenerating report at {output_report}...")
    generate_report(matches, internal_names, output_report)
    print("Done!")

    # Print summary of most common matches
    print("\n=== Top Matched Categories ===")
    from collections import Counter
    categories = Counter()
    for match in matches:
        for prefix, _ in match['suggestions']:
            categories[prefix] += 1

    for prefix, count in categories.most_common(10):
        desc = PREFIX_DESCRIPTIONS.get(prefix, 'Unknown')
        print(f"  {prefix}: {count} variables ({desc})")


if __name__ == '__main__':
    main()
