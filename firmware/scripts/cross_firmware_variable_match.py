#!/usr/bin/env python3
"""Cross-firmware variable matching via shared function co-occurrence.

Matches variables between CM550 and CM848 firmwares by analyzing which
variables appear together in functions that share the same name across
both firmwares. Variables that co-occur in the same shared functions
are likely the same logical variable at different architecture-specific
addresses.

Usage:
    python3 cross_firmware_variable_match.py \
        firmware/CM550_J90350.00_analysis/output \
        firmware/CM848_S90140.06_analysis/output \
        --output firmware/cross_firmware_variable_matches.csv
"""

import argparse
import csv
import re
import sys
from collections import defaultdict
from pathlib import Path


# Patterns to skip - these are not meaningful variable names
SKIP_PATTERNS = re.compile(
    r'^(DAT_|switchD|caseD_|default$|Ram0|SUB_|FUN_|BYTE_|CONCAT|switchdataD_)'
)


def load_global_variables(csv_path):
    """Load global_variables.csv, return dict of name -> type and set of named variables."""
    variables = {}  # name -> type
    with open(csv_path, 'r') as f:
        reader = csv.DictReader(
            (row for row in f if not row.startswith('#')),
        )
        for row in reader:
            name = row['name'].strip()
            var_type = row.get('type', '').strip()
            addr = row['address'].strip()
            if name and not SKIP_PATTERNS.match(name):
                variables[name] = {'type': var_type, 'address': addr}
    return variables


def parse_function_bodies(cpp_path, variable_names):
    """Parse decompiled C and build function_name -> set of variable names referenced.

    Uses '// Function: name @ addr' comments to delimit function boundaries.
    Only matches variables at word boundaries to avoid partial matches.
    """
    func_vars = {}  # function_name -> set of variable names
    current_func = None
    current_body_lines = []

    # Build a regex that matches any variable name at word boundaries.
    # Sort by length descending so longer names match first.
    sorted_names = sorted(variable_names, key=len, reverse=True)

    # For large name sets, use a set lookup approach instead of one giant regex
    # (faster for thousands of names)
    name_set = set(sorted_names)

    # Precompile word-char pattern
    word_char = re.compile(r'[a-zA-Z0-9_]')

    func_comment_re = re.compile(r'^// Function: (\S+) @')

    with open(cpp_path, 'r') as f:
        lines = f.readlines()

    def extract_vars_from_body(body_text, name_set):
        """Extract variable names from a function body using word boundary matching."""
        found = set()
        # Tokenize: split on non-identifier characters
        tokens = re.split(r'[^a-zA-Z0-9_]+', body_text)
        token_set = set(tokens)
        # Intersect with known variable names
        found = token_set & name_set
        return found

    for line in lines:
        m = func_comment_re.match(line)
        if m:
            # Save previous function
            if current_func is not None and current_body_lines:
                body = '\n'.join(current_body_lines)
                func_vars[current_func] = extract_vars_from_body(body, name_set)
            current_func = m.group(1)
            current_body_lines = []
        elif current_func is not None:
            current_body_lines.append(line)

    # Don't forget the last function
    if current_func is not None and current_body_lines:
        body = '\n'.join(current_body_lines)
        func_vars[current_func] = extract_vars_from_body(body, name_set)

    return func_vars


def jaccard_name_similarity(name1, name2):
    """Compute Jaccard similarity of underscore-split name tokens."""
    tokens1 = set(name1.lower().split('_'))
    tokens2 = set(name2.lower().split('_'))
    # Remove empty tokens
    tokens1.discard('')
    tokens2.discard('')
    if not tokens1 or not tokens2:
        return 0.0
    intersection = tokens1 & tokens2
    union = tokens1 | tokens2
    return len(intersection) / len(union)


def pick_more_descriptive_name(name1, name2):
    """Pick the more descriptive variable name based on heuristics."""
    # More underscores = more descriptive segments
    parts1 = len(name1.split('_'))
    parts2 = len(name2.split('_'))
    if parts1 != parts2:
        return name1 if parts1 > parts2 else name2
    # Longer name is usually more descriptive
    if len(name1) != len(name2):
        return name1 if len(name1) > len(name2) else name2
    # Alphabetical tiebreak
    return min(name1, name2)


def main():
    parser = argparse.ArgumentParser(
        description='Match variables across CM550/CM848 firmwares by shared function co-occurrence'
    )
    parser.add_argument('cm550_output', help='Path to CM550 output directory')
    parser.add_argument('cm848_output', help='Path to CM848 output directory')
    parser.add_argument('--output', '-o', default='firmware/cross_firmware_variable_matches.csv',
                        help='Output CSV path')
    args = parser.parse_args()

    cm550_dir = Path(args.cm550_output)
    cm848_dir = Path(args.cm848_output)

    # Locate files
    cm550_cpp = cm550_dir / 'J90350.00.ghidra.cpp'
    cm848_cpp = cm848_dir / 'cm848_rom.ghidra.cpp'
    cm550_vars_csv = cm550_dir / 'global_variables.csv'
    cm848_vars_csv = cm848_dir / 'global_variables.csv'

    for f in [cm550_cpp, cm848_cpp, cm550_vars_csv, cm848_vars_csv]:
        if not f.exists():
            print(f'ERROR: File not found: {f}', file=sys.stderr)
            sys.exit(1)

    # Step 1: Load variable databases
    print('Loading variable databases...')
    cm550_vars = load_global_variables(cm550_vars_csv)
    cm848_vars = load_global_variables(cm848_vars_csv)
    print(f'  CM550: {len(cm550_vars)} named variables')
    print(f'  CM848: {len(cm848_vars)} named variables')

    # Find already-shared names (to exclude from results)
    already_shared = set(cm550_vars.keys()) & set(cm848_vars.keys())
    print(f'  Already shared names: {len(already_shared)}')

    # Step 1b: Build variable usage maps from decompiled C
    print('Parsing CM550 decompiled output...')
    cm550_func_vars = parse_function_bodies(cm550_cpp, set(cm550_vars.keys()))
    print(f'  CM550: {len(cm550_func_vars)} functions parsed')

    print('Parsing CM848 decompiled output...')
    cm848_func_vars = parse_function_bodies(cm848_cpp, set(cm848_vars.keys()))
    print(f'  CM848: {len(cm848_func_vars)} functions parsed')

    # Step 2: Find shared function names
    shared_functions = set(cm550_func_vars.keys()) & set(cm848_func_vars.keys())
    # Filter to only functions present in both with at least one named variable each
    shared_functions = {
        f for f in shared_functions
        if cm550_func_vars[f] and cm848_func_vars[f]
    }
    print(f'  Shared functions with variables in both: {len(shared_functions)}')

    # Build reverse maps: variable -> set of shared functions it appears in
    cm550_var_to_shared_funcs = defaultdict(set)
    cm848_var_to_shared_funcs = defaultdict(set)

    for func_name in shared_functions:
        for var in cm550_func_vars[func_name]:
            if var not in already_shared:
                cm550_var_to_shared_funcs[var].add(func_name)
        for var in cm848_func_vars[func_name]:
            if var not in already_shared:
                cm848_var_to_shared_funcs[var].add(func_name)

    print(f'  CM550 variables in shared functions: {len(cm550_var_to_shared_funcs)}')
    print(f'  CM848 variables in shared functions: {len(cm848_var_to_shared_funcs)}')

    # Step 3: Score variable pairs
    # Only compare variables that co-occur in at least one shared function
    print('Scoring variable pairs...')

    # Build per-shared-function pair index for efficiency
    # For each shared function, create candidate pairs
    pair_shared_funcs = defaultdict(set)  # (cm550_var, cm848_var) -> set of shared funcs

    for func_name in shared_functions:
        cm550_in_func = cm550_func_vars[func_name] - already_shared
        cm848_in_func = cm848_func_vars[func_name] - already_shared
        for v550 in cm550_in_func:
            if v550 in cm550_var_to_shared_funcs:
                for v848 in cm848_in_func:
                    if v848 in cm848_var_to_shared_funcs:
                        pair_shared_funcs[(v550, v848)].add(func_name)

    print(f'  Candidate pairs: {len(pair_shared_funcs)}')

    # Score each pair
    scored_pairs = []
    for (v550, v848), shared_funcs in pair_shared_funcs.items():
        shared_function_count = len(shared_funcs)

        # Exclusive function bonus: do they appear in the same set of shared functions?
        exclusive_function_bonus = 0
        if cm550_var_to_shared_funcs[v550] == cm848_var_to_shared_funcs[v848]:
            exclusive_function_bonus = 1

        # Name similarity bonus
        sim = jaccard_name_similarity(v550, v848)
        similar_name_bonus = 1 if sim > 0.3 else 0

        # Type matching bonus
        same_type_bonus = 0
        t550 = cm550_vars[v550]['type']
        t848 = cm848_vars[v848]['type']
        if t550 and t848 and t550 == t848:
            same_type_bonus = 1

        score = (
            shared_function_count * 10 +
            exclusive_function_bonus * 5 +
            similar_name_bonus * 3 +
            same_type_bonus * 2
        )

        scored_pairs.append({
            'cm550_var': v550,
            'cm848_var': v848,
            'score': score,
            'shared_functions': '+'.join(sorted(shared_funcs)),
            'shared_count': shared_function_count,
            'name_similarity': round(sim, 2),
        })

    # Step 4: Select best matches (mutual best match)
    print('Selecting best matches...')

    # Sort by score descending
    scored_pairs.sort(key=lambda x: x['score'], reverse=True)

    # For each CM550 var, keep best CM848 match
    best_for_cm550 = {}
    for pair in scored_pairs:
        v550 = pair['cm550_var']
        if v550 not in best_for_cm550:
            best_for_cm550[v550] = pair

    # For each CM848 var, keep best CM550 match
    best_for_cm848 = {}
    for pair in scored_pairs:
        v848 = pair['cm848_var']
        if v848 not in best_for_cm848:
            best_for_cm848[v848] = pair

    # Keep only mutual best matches (or resolve conflicts by higher score)
    final_matches = {}
    used_cm550 = set()
    used_cm848 = set()

    for pair in scored_pairs:
        v550 = pair['cm550_var']
        v848 = pair['cm848_var']

        if v550 in used_cm550 or v848 in used_cm848:
            continue

        # Check if this is the best match for both sides
        is_best_550 = best_for_cm550.get(v550) == pair
        is_best_848 = best_for_cm848.get(v848) == pair

        if is_best_550 and is_best_848:
            final_matches[(v550, v848)] = pair
            used_cm550.add(v550)
            used_cm848.add(v848)

    # Also include non-mutual but high-score matches where the other side has no better option
    for pair in scored_pairs:
        v550 = pair['cm550_var']
        v848 = pair['cm848_var']
        if v550 in used_cm550 or v848 in used_cm848:
            continue
        is_best_550 = best_for_cm550.get(v550) == pair
        is_best_848 = best_for_cm848.get(v848) == pair
        if is_best_550 or is_best_848:
            final_matches[(v550, v848)] = pair
            used_cm550.add(v550)
            used_cm848.add(v848)

    # Step 5: Determine action and write output
    results = []
    for (v550, v848), pair in final_matches.items():
        score = pair['score']

        if score >= 20:
            chosen = pick_more_descriptive_name(v550, v848)
            if chosen == v550 and chosen == v848:
                action = f'rename_both:{chosen}'
            elif chosen == v550:
                action = f'rename_cm848:{chosen}'
            elif chosen == v848:
                action = f'rename_cm550:{chosen}'
            else:
                action = f'rename_both:{chosen}'
        else:
            action = 'review'

        results.append({
            'cm550_addr': cm550_vars[v550]['address'],
            'cm550_name': v550,
            'cm848_addr': cm848_vars[v848]['address'],
            'cm848_name': v848,
            'score': score,
            'shared_functions': pair['shared_functions'],
            'action': action,
        })

    # Sort by score descending
    results.sort(key=lambda x: x['score'], reverse=True)

    # Write output
    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)

    with open(output_path, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=[
            'cm550_addr', 'cm550_name', 'cm848_addr', 'cm848_name',
            'score', 'shared_functions', 'action'
        ])
        writer.writeheader()
        writer.writerows(results)

    # Print summary
    print(f'\n=== Results ===')
    print(f'Total matches: {len(results)}')
    high_conf = [r for r in results if r['score'] >= 20]
    review = [r for r in results if r['score'] < 20]
    print(f'High confidence (score >= 20): {len(high_conf)}')
    print(f'Needs review (score < 20): {len(review)}')

    print(f'\nTop 15 matches:')
    print(f'{"Score":>5}  {"CM550 Variable":<45} {"CM848 Variable":<45} {"Action"}')
    print(f'{"-"*5}  {"-"*45} {"-"*45} {"-"*30}')
    for r in results[:15]:
        print(f'{r["score"]:>5}  {r["cm550_name"]:<45} {r["cm848_name"]:<45} {r["action"]}')

    if review:
        print(f'\nBottom 5 (review):')
        for r in results[-5:]:
            print(f'{r["score"]:>5}  {r["cm550_name"]:<45} {r["cm848_name"]:<45} {r["shared_functions"][:60]}')

    print(f'\nOutput written to: {output_path}')


if __name__ == '__main__':
    main()
