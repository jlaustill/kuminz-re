#!/usr/bin/env python3
"""
Cross-firmware function fingerprinting between CM550 and CM848.

Compares decompiled functions from two Ghidra exports and finds matching
function pairs using rare constants, shared callees, structural similarity,
and shared global variable references.

Usage:
    python3 cross_firmware_fingerprint.py <cm550_output_dir> <cm848_output_dir> \
        --output firmware/cross_firmware_matches.csv --min-score 15
"""

import argparse
import csv
import os
import re
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field


# ---------------------------------------------------------------------------
# Address ranges to EXCLUDE from constant fingerprinting
# ---------------------------------------------------------------------------

# Constants 0x10-0x2FFFF are ALWAYS kept (algorithm constants, PGN IDs, etc.)
# Only exclude larger values that fall in architecture-specific address ranges.
EXCLUDED_RANGES = [
    (0x00030000, 0x0006FFFF),   # ROM addresses (above algorithm constant range)
    (0x00500000, 0x0053DFFF),   # CM848 Bank 2 Flash
    (0x003F0000, 0x0043FFFF),   # CM848 RAM
    (0x00800000, 0x0080FFFF),   # CM550 RAM + Extended RAM
    (0x01000000, 0x01000FFF),   # EEPROM (both)
    (0x002F0000, 0x00310000),   # MPC555 hardware registers
    (0x00FF0000, 0x00FFFFFF),   # MC68336 hardware registers
]


def is_excluded_address(val):
    """Check if a constant falls in an architecture-specific address range."""
    # Small constants (0x10-0x2FFFF) are always kept as algorithm constants
    if val <= 0x2FFFF:
        return False
    for lo, hi in EXCLUDED_RANGES:
        if lo <= val <= hi:
            return True
    return False


# ---------------------------------------------------------------------------
# C keywords and type casts to skip when extracting callees
# ---------------------------------------------------------------------------

C_KEYWORDS = frozenset([
    'if', 'while', 'for', 'switch', 'return', 'do', 'sizeof',
    'else', 'case', 'break', 'continue', 'goto', 'default',
])

TYPE_CASTS = frozenset([
    'int', 'uint', 'short', 'ushort', 'byte', 'char', 'void', 'long',
    'bool', 'undefined', 'undefined1', 'undefined2', 'undefined4',
    'dword', 'word', 'ulong', 'longlong', 'ulonglong',
    'float', 'double', 'signed', 'unsigned',
])

GHIDRA_PREFIXES = ('CONCAT', 'SUB_', 'FUN_', 'ZEXT', 'SEXT', 'CARRY',
                    'SBORROW', 'SCARRY', 'POPCOUNT', 'LZCOUNT')

CONTROL_FLOW_KW = re.compile(r'\b(if|while|for|switch)\b')

# Regex patterns
FUNC_HEADER_RE = re.compile(
    r'^//\n// Function: (.+?) @ (0x[0-9a-f]+)\n//\n',
    re.MULTILINE
)
HEX_CONST_RE = re.compile(r'\b0x([0-9a-fA-F]+)\b')
DEC_CONST_RE = re.compile(r'(?<![0-9a-zA-Z_])(\d+)(?![0-9a-zA-Z_])')
CALLEE_RE = re.compile(r'\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\(')
LOCAL_VAR_RE = re.compile(
    r'^\s+(?:u?(?:int|short|long|char)|byte|ushort|uint|ulong|dword|word|'
    r'bool|void|undefined[124]?|longlong|ulonglong|float|double)\s+'
    r'[a-zA-Z_]\w*\s*;',
    re.MULTILINE
)
PARAM_RE = re.compile(r'\([^)]*\)')


# ---------------------------------------------------------------------------
# Data structures
# ---------------------------------------------------------------------------

@dataclass
class FunctionFeatures:
    name: str
    address: str
    constants: set = field(default_factory=set)
    callees: set = field(default_factory=set)
    param_count: int = 0
    line_count: int = 0
    control_flow_count: int = 0
    local_var_count: int = 0
    globals_referenced: set = field(default_factory=set)


# ---------------------------------------------------------------------------
# Parser
# ---------------------------------------------------------------------------

def find_ghidra_cpp(output_dir):
    """Find the single .ghidra.cpp file in output_dir."""
    matches = [f for f in os.listdir(output_dir) if f.endswith('.ghidra.cpp')]
    if len(matches) == 0:
        raise FileNotFoundError(f"No .ghidra.cpp file found in {output_dir}")
    if len(matches) > 1:
        raise FileNotFoundError(f"Multiple .ghidra.cpp files: {matches}")
    return os.path.join(output_dir, matches[0])


def parse_functions(filepath):
    """Split a .ghidra.cpp file into individual functions."""
    with open(filepath, 'r') as f:
        content = f.read()

    # Find all function headers
    headers = list(FUNC_HEADER_RE.finditer(content))
    functions = []

    for i, match in enumerate(headers):
        name = match.group(1)
        address = match.group(2)
        body_start = match.end()
        body_end = headers[i + 1].start() if i + 1 < len(headers) else len(content)
        body = content[body_start:body_end]
        functions.append((name, address, body))

    return functions


def load_global_names(output_dir):
    """Load named global variables from global_variables.csv."""
    csv_path = os.path.join(output_dir, 'global_variables.csv')
    names = set()
    if not os.path.exists(csv_path):
        return names
    with open(csv_path, newline='') as f:
        for row in f:
            if row.startswith('#') or row.startswith('address'):
                continue
            parts = row.strip().split(',')
            if len(parts) >= 2:
                name = parts[1].strip()
                # Skip unnamed/placeholder variables
                if (name and not name.startswith('DAT_') and
                        not name.startswith('switchD') and
                        not name.startswith('caseD_') and
                        not name.startswith('default') and
                        not name.startswith('SUB_') and
                        not name.startswith('Ram')):
                    names.add(name)
    return names


# ---------------------------------------------------------------------------
# Feature extraction
# ---------------------------------------------------------------------------

def extract_features(name, address, body, shared_globals):
    """Extract fingerprint features from a function body."""
    feat = FunctionFeatures(name=name, address=address)

    # --- Constants ---
    for m in HEX_CONST_RE.finditer(body):
        val = int(m.group(1), 16)
        if val < 0x10:
            continue
        if is_excluded_address(val):
            continue
        feat.constants.add(val)

    for m in DEC_CONST_RE.finditer(body):
        val = int(m.group(1))
        if val <= 10:
            continue
        if val > 0x2FFFF:
            continue
        if is_excluded_address(val):
            continue
        feat.constants.add(val)

    # --- Callees ---
    for m in CALLEE_RE.finditer(body):
        callee = m.group(1)
        if callee == name:  # Skip self-references
            continue
        if callee in C_KEYWORDS or callee in TYPE_CASTS:
            continue
        if any(callee.startswith(p) for p in GHIDRA_PREFIXES):
            continue
        # Skip DAT_/Ram/USIU references that look like function calls
        if callee.startswith(('DAT_', '_DAT_', 'Ram', 'USIU_', 'UNK_')):
            continue
        feat.callees.add(callee)

    # --- Structure ---
    # Line count
    lines = body.strip().split('\n')
    feat.line_count = len(lines)

    # Parameter count from first line with parentheses
    first_paren = PARAM_RE.search(body)
    if first_paren:
        params_str = first_paren.group(0)[1:-1].strip()
        if params_str == '' or params_str == 'void':
            feat.param_count = 0
        else:
            feat.param_count = params_str.count(',') + 1

    # Control flow keywords
    feat.control_flow_count = len(CONTROL_FLOW_KW.findall(body))

    # Local variables
    feat.local_var_count = len(LOCAL_VAR_RE.findall(body))

    # --- Referenced globals ---
    for gname in shared_globals:
        if gname in body:
            feat.globals_referenced.add(gname)

    return feat


# ---------------------------------------------------------------------------
# Frequency maps and scoring
# ---------------------------------------------------------------------------

def build_frequency_maps(functions_list):
    """Build frequency maps: how many functions use each constant/callee."""
    const_freq = Counter()
    callee_freq = Counter()
    for feat in functions_list:
        for c in feat.constants:
            const_freq[c] += 1
        for c in feat.callees:
            callee_freq[c] += 1
    return const_freq, callee_freq


def compute_score(feat_a, feat_b, rare_consts, rare_callees, common_callees):
    """Compute matching score between two functions."""
    # Shared constants (all, not just rare)
    all_shared_consts = feat_a.constants & feat_b.constants
    shared_rare_consts = all_shared_consts & rare_consts
    shared_common_consts = all_shared_consts - rare_consts
    rare_const_count = len(shared_rare_consts)
    common_const_count = len(shared_common_consts)

    # Constant Jaccard similarity (bonus for high overlap ratio)
    const_union = feat_a.constants | feat_b.constants
    const_jaccard = len(all_shared_consts) / len(const_union) if const_union else 0

    # Shared callees
    shared_calls = feat_a.callees & feat_b.callees
    rare_callee_set = shared_calls & rare_callees
    common_callee_set = shared_calls & common_callees
    rare_callee_count = len(rare_callee_set)
    common_callee_count = len(common_callee_set)

    # Shared globals
    shared_vars = feat_a.globals_referenced & feat_b.globals_referenced
    shared_var_count = len(shared_vars)

    # Structural similarity
    struct_sim = 0
    if feat_a.param_count == feat_b.param_count:
        lc_a, lc_b = feat_a.line_count, feat_b.line_count
        cf_a, cf_b = feat_a.control_flow_count, feat_b.control_flow_count
        max_lc = max(lc_a, lc_b, 1)
        max_cf = max(cf_a, cf_b, 1)
        if abs(lc_a - lc_b) / max_lc <= 0.5 and abs(cf_a - cf_b) / max_cf <= 0.5:
            struct_sim = 1

    score = (rare_const_count * 10 +
             common_const_count * 3 +
             int(const_jaccard * 20) +
             rare_callee_count * 8 +
             common_callee_count * 2 +
             shared_var_count * 5 +
             struct_sim * 3)

    # Build evidence string
    evidence_parts = []
    if shared_rare_consts:
        consts_str = '+'.join(f'0x{c:x}' for c in sorted(shared_rare_consts)[:5])
        if len(shared_rare_consts) > 5:
            consts_str += f'+{len(shared_rare_consts)-5}more'
        evidence_parts.append(f'rare_const:{consts_str}')
    if shared_common_consts:
        evidence_parts.append(f'common_const:{len(shared_common_consts)}')
    if const_jaccard > 0.1:
        evidence_parts.append(f'jaccard:{const_jaccard:.2f}')
    if rare_callee_set:
        calls_str = '+'.join(sorted(rare_callee_set)[:5])
        if len(rare_callee_set) > 5:
            calls_str += f'+{len(rare_callee_set)-5}more'
        evidence_parts.append(f'rare_callee:{calls_str}')
    if common_callee_set:
        evidence_parts.append(f'common_callee:{"+".join(sorted(common_callee_set)[:3])}')
    if shared_vars:
        evidence_parts.append(f'globals:{"+".join(sorted(shared_vars)[:3])}')
    if struct_sim:
        evidence_parts.append('struct:similar')

    return score, ';'.join(evidence_parts)


def determine_action(cm550_name, cm848_name, score):
    """Determine what action to take for a match."""
    if score < 30:
        return 'review'

    cm550_unnamed = cm550_name.startswith('FUN_')
    cm848_unnamed = cm848_name.startswith('FUN_')

    if cm550_unnamed and not cm848_unnamed:
        return f'name_cm550:{cm848_name}'
    elif cm848_unnamed and not cm550_unnamed:
        return f'name_cm848:{cm550_name}'
    elif cm550_unnamed and cm848_unnamed:
        return 'both_unnamed'
    else:
        # Both named differently - pick the longer/more descriptive one
        best = cm550_name if len(cm550_name) >= len(cm848_name) else cm848_name
        return f'rename_both:{best}'


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Cross-firmware function fingerprinting')
    parser.add_argument('cm550_dir', help='CM550 output directory')
    parser.add_argument('cm848_dir', help='CM848 output directory')
    parser.add_argument('--output', default='firmware/cross_firmware_matches.csv',
                        help='Output CSV path')
    parser.add_argument('--min-score', type=int, default=15,
                        help='Minimum score to include')
    args = parser.parse_args()

    # --- Load functions ---
    cm550_cpp = find_ghidra_cpp(args.cm550_dir)
    cm848_cpp = find_ghidra_cpp(args.cm848_dir)

    print(f"Loading CM550: {cm550_cpp}")
    cm550_raw = parse_functions(cm550_cpp)
    print(f"  {len(cm550_raw)} functions")

    print(f"Loading CM848: {cm848_cpp}")
    cm848_raw = parse_functions(cm848_cpp)
    print(f"  {len(cm848_raw)} functions")

    # --- Load shared globals ---
    cm550_globals = load_global_names(args.cm550_dir)
    cm848_globals = load_global_names(args.cm848_dir)
    shared_globals = cm550_globals & cm848_globals
    print(f"Shared global variable names: {len(shared_globals)}")

    # --- Extract features ---
    print("Extracting features...")
    cm550_feats = []
    for name, addr, body in cm550_raw:
        cm550_feats.append(extract_features(name, addr, body, shared_globals))

    cm848_feats = []
    for name, addr, body in cm848_raw:
        cm848_feats.append(extract_features(name, addr, body, shared_globals))

    # --- Build frequency maps ---
    print("Building frequency maps...")
    cm550_const_freq, cm550_callee_freq = build_frequency_maps(cm550_feats)
    cm848_const_freq, cm848_callee_freq = build_frequency_maps(cm848_feats)

    # Rare constants: appear in <5 functions in BOTH firmwares
    rare_consts = set()
    all_consts = set(cm550_const_freq.keys()) | set(cm848_const_freq.keys())
    for c in all_consts:
        if cm550_const_freq.get(c, 0) < 5 and cm848_const_freq.get(c, 0) < 5:
            rare_consts.add(c)

    # Rare callees: called by <20 functions total across both firmwares
    all_callees = set(cm550_callee_freq.keys()) | set(cm848_callee_freq.keys())
    rare_callees = set()
    common_callees = set()
    for c in all_callees:
        total = cm550_callee_freq.get(c, 0) + cm848_callee_freq.get(c, 0)
        if total < 20:
            rare_callees.add(c)
        else:
            common_callees.add(c)

    print(f"Rare constants: {len(rare_consts)}, Rare callees: {len(rare_callees)}, "
          f"Common callees: {len(common_callees)}")

    # --- Skip already-matched functions (same name in both) ---
    cm550_names = {f.name for f in cm550_feats}
    cm848_names = {f.name for f in cm848_feats}
    already_matched = cm550_names & cm848_names
    print(f"Already matched (same name): {len(already_matched)}")

    # --- Scoring ---
    print(f"Scoring {len(cm550_feats)} x {len(cm848_feats)} = "
          f"{len(cm550_feats) * len(cm848_feats):,} comparisons...")

    # Pre-filter: skip functions with no features at all
    cm550_active = [f for f in cm550_feats if f.name not in already_matched]
    cm848_active = [f for f in cm848_feats if f.name not in already_matched]

    # For each CM550 function, find best CM848 match
    # For each CM848 function, find best CM550 match
    best_for_cm550 = {}  # cm550_addr -> (score, evidence, cm848_feat)
    best_for_cm848 = {}  # cm848_addr -> (score, evidence, cm550_feat)

    for fa in cm550_active:
        # Skip tiny stubs (< 5 lines, no constants, no callees)
        if fa.line_count < 5 and not fa.constants and not fa.callees:
            continue

        best_score = 0
        best_evidence = ''
        best_match = None

        for fb in cm848_active:
            # Quick pre-filter: skip if no possible overlap
            if (not (fa.constants & fb.constants) and
                    not (fa.callees & fb.callees) and
                    not (fa.globals_referenced & fb.globals_referenced)):
                continue

            score, evidence = compute_score(fa, fb, rare_consts, rare_callees,
                                            common_callees)
            if score > best_score:
                best_score = score
                best_evidence = evidence
                best_match = fb

        if best_match and best_score >= args.min_score:
            best_for_cm550[fa.address] = (best_score, best_evidence, best_match, fa)

            # Also track best for CM848 side
            existing = best_for_cm848.get(best_match.address)
            if existing is None or best_score > existing[0]:
                best_for_cm848[best_match.address] = (best_score, best_evidence, fa, best_match)

    # --- Resolve conflicts: mutual best matches only ---
    matches = []
    used_cm848 = set()

    # Sort by score descending
    sorted_pairs = sorted(best_for_cm550.items(), key=lambda x: -x[1][0])

    for cm550_addr, (score, evidence, cm848_feat, cm550_feat) in sorted_pairs:
        if cm848_feat.address in used_cm848:
            continue

        # Check if this CM848 function's best match is this CM550 function
        cm848_best = best_for_cm848.get(cm848_feat.address)
        if cm848_best and cm848_best[2].address == cm550_addr:
            # Mutual best match
            action = determine_action(cm550_feat.name, cm848_feat.name, score)
            matches.append({
                'cm550_addr': cm550_feat.address,
                'cm550_name': cm550_feat.name,
                'cm848_addr': cm848_feat.address,
                'cm848_name': cm848_feat.name,
                'score': score,
                'evidence': evidence,
                'action': action,
            })
            used_cm848.add(cm848_feat.address)
        else:
            # One-sided best match - still include but note it
            action = determine_action(cm550_feat.name, cm848_feat.name, score)
            matches.append({
                'cm550_addr': cm550_feat.address,
                'cm550_name': cm550_feat.name,
                'cm848_addr': cm848_feat.address,
                'cm848_name': cm848_feat.name,
                'score': score,
                'evidence': evidence,
                'action': action,
            })
            used_cm848.add(cm848_feat.address)

    # Sort output by score descending
    matches.sort(key=lambda x: -x['score'])

    # --- Write output ---
    os.makedirs(os.path.dirname(args.output) or '.', exist_ok=True)
    with open(args.output, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=[
            'cm550_addr', 'cm550_name', 'cm848_addr', 'cm848_name',
            'score', 'evidence', 'action'
        ])
        writer.writeheader()
        writer.writerows(matches)

    # --- Summary ---
    print(f"\n{'='*60}")
    print(f"Results written to: {args.output}")
    print(f"Total matches: {len(matches)}")

    high = [m for m in matches if m['score'] >= 50]
    medium = [m for m in matches if 30 <= m['score'] < 50]
    low = [m for m in matches if m['score'] < 30]
    print(f"  High confidence (>=50): {len(high)}")
    print(f"  Medium confidence (30-49): {len(medium)}")
    print(f"  Low confidence (<30): {len(low)}")

    actionable = [m for m in matches if m['action'].startswith('name_')]
    print(f"  Actionable (can name): {len(actionable)}")

    # Action breakdown
    action_counts = Counter(
        m['action'].split(':')[0] for m in matches
    )
    print(f"\nAction breakdown:")
    for action, count in sorted(action_counts.items(), key=lambda x: -x[1]):
        print(f"  {action}: {count}")

    # Top matches
    print(f"\nTop 15 matches:")
    print(f"  {'Score':>5}  {'CM550 Name':<40} {'CM848 Name':<40} Action")
    print(f"  {'-'*5}  {'-'*40} {'-'*40} {'-'*20}")
    for m in matches[:15]:
        action_short = m['action'][:20]
        print(f"  {m['score']:>5}  {m['cm550_name']:<40} {m['cm848_name']:<40} {action_short}")


if __name__ == '__main__':
    main()
