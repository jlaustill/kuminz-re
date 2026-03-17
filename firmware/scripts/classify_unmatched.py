#!/usr/bin/env python3
"""Classify unmatched firmware functions by architecture/fuel-system specificity.

Phase 4 of the cross-firmware convergence pipeline. Analyzes functions that exist
in only one firmware (CM550 or CM848) and classifies them by WHY they're unique:
  - vp44_:   VP44 injection pump specific (CM550 only)
  - mc68k_:  MC68336 hardware specific (CM550 only)
  - hpcr_:   HPCR common rail specific (CM848 only)
  - mpc555_: MPC555 hardware specific (CM848 only)
  - cm550_/cm848_: Unknown reason for uniqueness
"""

import argparse
import csv
import re
import sys
from pathlib import Path


# ---------------------------------------------------------------------------
# Indicator patterns
# ---------------------------------------------------------------------------

# VP44 fuel system (CM550 only)
VP44_PATTERNS = re.compile(
    r'vp44|VP44|injection_pump|fso_circuit|injPump|inj_pump',
    re.IGNORECASE,
)

# HPCR common rail (CM848 only)
HPCR_PATTERNS = re.compile(
    r'rail_pressure|railPressure|injector_pulse|injectorPulse|'
    r'cylinder_balance|cylinderBalance|cbd_|common_rail|commonRail|hpcr|HPCR|'
    r'injectorTrim|injector_trim|fuelRail|fuel_rail',
    re.IGNORECASE,
)

# MC68336 hardware (CM550 only)
# Registers at 0x00FF0000-0x00FFFFFF, TPU/QSM/SIM peripherals
MC68K_PATTERNS = re.compile(
    r'tpu_|qsm_|sim_|tpuram|TPURAM|qspi|QSPI|\bsci\b|SCI_|'
    r'DAT_00ff[0-9a-f]|_DAT_00ff|0x00ff[0-9a-f]{4}|'
    r'mc68|MC68',
    re.IGNORECASE,
)

# MPC555 hardware (CM848 only)
# Registers at 0x002F0000-0x00310000, USIU/QADC/TouCAN
MPC555_PATTERNS = re.compile(
    r'USIU_|QADC64|QADC_|TouCAN|toucan|'
    r'Ram002[0-9a-f]|Ram003[0-9a-f]|'
    r'UIMB|DPTRAM|dptram|'
    r'mpc555|MPC555',
)


# ---------------------------------------------------------------------------
# Parsing helpers
# ---------------------------------------------------------------------------

def load_function_renames(csv_path: Path) -> dict[str, str]:
    """Load function_renames.csv → {address: name}. Skip comments."""
    renames = {}
    with open(csv_path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            if line == 'address,name':
                continue
            parts = line.split(',', 1)
            if len(parts) == 2:
                renames[parts[0].strip()] = parts[1].strip()
    return renames


def parse_functions_from_cpp(cpp_path: Path) -> dict[str, str]:
    """Parse ghidra.cpp into {name@address: body_text}.

    Returns dict keyed by "name@address" with the full function body as value.
    """
    header_re = re.compile(r'^// Function: (\S+) @ (0x[0-9a-fA-F]+)')
    functions = {}
    current_key = None
    body_lines = []

    with open(cpp_path) as f:
        for line in f:
            m = header_re.match(line)
            if m:
                # Save previous function
                if current_key:
                    functions[current_key] = '\n'.join(body_lines)
                name, addr = m.group(1), m.group(2)
                current_key = f"{name}@{addr}"
                body_lines = []
            else:
                body_lines.append(line.rstrip())

    # Save last function
    if current_key:
        functions[current_key] = '\n'.join(body_lines)

    return functions


def split_key(key: str) -> tuple[str, str]:
    """Split 'name@address' → (name, address)."""
    at = key.rfind('@')
    return key[:at], key[at + 1:]


# ---------------------------------------------------------------------------
# Classification
# ---------------------------------------------------------------------------

ALL_PREFIXES = ('vp44_', 'hpcr_', 'mc68k_', 'mpc555_', 'cm550_', 'cm848_')


def classify_cm550(body: str, name: str) -> tuple[str, str, list[str]]:
    """Classify a CM550-only function. Returns (classification, prefix, indicators)."""
    indicators = []

    # Check VP44 indicators
    vp44_hits = VP44_PATTERNS.findall(body) + VP44_PATTERNS.findall(name)
    if vp44_hits:
        indicators = list(set(h.lower() for h in vp44_hits))[:5]
        return 'vp44', 'vp44_', indicators

    # Check MC68336 hardware indicators
    mc68k_hits = MC68K_PATTERNS.findall(body) + MC68K_PATTERNS.findall(name)
    if mc68k_hits:
        indicators = list(set(h.lower() for h in mc68k_hits))[:5]
        return 'mc68k', 'mc68k_', indicators

    return 'unknown', 'cm550_', []


def classify_cm848(body: str, name: str) -> tuple[str, str, list[str]]:
    """Classify a CM848-only function. Returns (classification, prefix, indicators)."""
    indicators = []

    # Check HPCR indicators
    hpcr_hits = HPCR_PATTERNS.findall(body) + HPCR_PATTERNS.findall(name)
    if hpcr_hits:
        indicators = list(set(h.lower() for h in hpcr_hits))[:5]
        return 'hpcr', 'hpcr_', indicators

    # Check MPC555 hardware indicators
    mpc555_hits = MPC555_PATTERNS.findall(body) + MPC555_PATTERNS.findall(name)
    if mpc555_hits:
        indicators = list(set(h.lower() for h in mpc555_hits))[:5]
        return 'mpc555', 'mpc555_', indicators

    return 'unknown', 'cm848_', []


def suggest_name(current_name: str, prefix: str) -> str:
    """Generate suggested prefixed name.

    Rules:
    - Already has correct prefix → keep as-is
    - Starts with FUN_ → prefix + FUN_xxxxxxxx
    - Otherwise → prefix + current_name
    - Don't double-prefix (check both exact prefix and stem like vp44/hpcr/mc68k/mpc555)
    """
    # Already has a known prefix
    if current_name.startswith(prefix):
        return current_name
    for p in ALL_PREFIXES:
        if current_name.startswith(p):
            return current_name  # already prefixed with something

    # Check if name already starts with the stem (e.g., vp44Foo for prefix vp44_)
    stem = prefix.rstrip('_')
    if current_name.lower().startswith(stem.lower()):
        return current_name  # already indicates the subsystem

    return prefix + current_name


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Classify unmatched firmware functions by architecture/fuel-system.'
    )
    parser.add_argument('cm550_dir', type=Path,
                        help='CM550 output directory (contains function_renames.csv and .ghidra.cpp)')
    parser.add_argument('cm848_dir', type=Path,
                        help='CM848 output directory')
    parser.add_argument('--output', '-o', type=Path, default=Path('firmware/classification.csv'),
                        help='Output classification CSV')
    args = parser.parse_args()

    # Locate files
    cm550_csv = args.cm550_dir / 'function_renames.csv'
    cm848_csv = args.cm848_dir / 'function_renames.csv'

    # Find ghidra.cpp files
    cm550_cpps = list(args.cm550_dir.glob('*.ghidra.cpp'))
    cm848_cpps = list(args.cm848_dir.glob('*.ghidra.cpp'))
    if not cm550_cpps:
        sys.exit(f"No .ghidra.cpp found in {args.cm550_dir}")
    if not cm848_cpps:
        sys.exit(f"No .ghidra.cpp found in {args.cm848_dir}")
    cm550_cpp = cm550_cpps[0]
    cm848_cpp = cm848_cpps[0]

    print(f"Loading CM550: {cm550_csv}")
    print(f"Loading CM848: {cm848_csv}")
    print(f"Parsing CM550: {cm550_cpp}")
    print(f"Parsing CM848: {cm848_cpp}")

    # Load renames
    cm550_renames = load_function_renames(cm550_csv)
    cm848_renames = load_function_renames(cm848_csv)

    # Build name sets for cross-checking
    cm550_names = set(cm550_renames.values())
    cm848_names = set(cm848_renames.values())

    # Parse function bodies
    cm550_funcs = parse_functions_from_cpp(cm550_cpp)
    cm848_funcs = parse_functions_from_cpp(cm848_cpp)

    print(f"\nCM550: {len(cm550_renames)} renamed, {len(cm550_funcs)} decompiled")
    print(f"CM848: {len(cm848_renames)} renamed, {len(cm848_funcs)} decompiled")

    # Find shared names (matched functions)
    shared_names = cm550_names & cm848_names
    # Remove FUN_ names from shared set - those aren't real matches
    shared_names = {n for n in shared_names if not n.startswith('FUN_')}

    # Build lookup: function name → body (from parsed cpp)
    cm550_body_by_name = {}
    for key, body in cm550_funcs.items():
        name, addr = split_key(key)
        cm550_body_by_name[name] = body

    cm848_body_by_name = {}
    for key, body in cm848_funcs.items():
        name, addr = split_key(key)
        cm848_body_by_name[name] = body

    # Classify unmatched CM550 functions
    rows = []
    cm550_stats = {'vp44_': 0, 'mc68k_': 0, 'cm550_': 0}

    for addr, name in sorted(cm550_renames.items(), key=lambda x: x[0]):
        # Skip if name is shared with CM848
        if name in shared_names:
            continue

        body = cm550_body_by_name.get(name, '')
        classification, prefix, indicators = classify_cm550(body, name)
        suggested = suggest_name(name, prefix)
        cm550_stats[prefix] = cm550_stats.get(prefix, 0) + 1

        rows.append({
            'firmware': 'cm550',
            'address': addr,
            'current_name': name,
            'classification': classification,
            'prefix': prefix,
            'indicators': '+'.join(indicators),
            'suggested_name': suggested,
        })

    # Also include FUN_ functions from the cpp that aren't in renames
    for key, body in cm550_funcs.items():
        name, addr = split_key(key)
        if name.startswith('FUN_') and addr not in cm550_renames:
            classification, prefix, indicators = classify_cm550(body, name)
            suggested = suggest_name(name, prefix)
            cm550_stats[prefix] = cm550_stats.get(prefix, 0) + 1
            rows.append({
                'firmware': 'cm550',
                'address': addr,
                'current_name': name,
                'classification': classification,
                'prefix': prefix,
                'indicators': '+'.join(indicators),
                'suggested_name': suggested,
            })

    # Classify unmatched CM848 functions
    cm848_stats = {'hpcr_': 0, 'mpc555_': 0, 'cm848_': 0}

    for addr, name in sorted(cm848_renames.items(), key=lambda x: x[0]):
        if name in shared_names:
            continue

        body = cm848_body_by_name.get(name, '')
        classification, prefix, indicators = classify_cm848(body, name)
        suggested = suggest_name(name, prefix)
        cm848_stats[prefix] = cm848_stats.get(prefix, 0) + 1

        rows.append({
            'firmware': 'cm848',
            'address': addr,
            'current_name': name,
            'classification': classification,
            'prefix': prefix,
            'indicators': '+'.join(indicators),
            'suggested_name': suggested,
        })

    # FUN_ functions from CM848 cpp not in renames
    for key, body in cm848_funcs.items():
        name, addr = split_key(key)
        if name.startswith('FUN_') and addr not in cm848_renames:
            classification, prefix, indicators = classify_cm848(body, name)
            suggested = suggest_name(name, prefix)
            cm848_stats[prefix] = cm848_stats.get(prefix, 0) + 1
            rows.append({
                'firmware': 'cm848',
                'address': addr,
                'current_name': name,
                'classification': classification,
                'prefix': prefix,
                'indicators': '+'.join(indicators),
                'suggested_name': suggested,
            })

    # Write output CSV
    args.output.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = ['firmware', 'address', 'current_name', 'classification',
                  'prefix', 'indicators', 'suggested_name']
    with open(args.output, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    print(f"\nWrote {len(rows)} rows to {args.output}")

    # Print stats
    cm550_total = sum(cm550_stats.values())
    cm848_total = sum(cm848_stats.values())

    print(f"\n=== CM550 Unmatched Functions ===")
    print(f"Total: {cm550_total}")
    print(f"  vp44_:   {cm550_stats.get('vp44_', 0)}")
    print(f"  mc68k_:  {cm550_stats.get('mc68k_', 0)}")
    print(f"  cm550_:  {cm550_stats.get('cm550_', 0)}")

    print(f"\n=== CM848 Unmatched Functions ===")
    print(f"Total: {cm848_total}")
    print(f"  hpcr_:   {cm848_stats.get('hpcr_', 0)}")
    print(f"  mpc555_: {cm848_stats.get('mpc555_', 0)}")
    print(f"  cm848_:  {cm848_stats.get('cm848_', 0)}")

    print(f"\n=== Already matched (shared names): {len(shared_names)}")


if __name__ == '__main__':
    main()
