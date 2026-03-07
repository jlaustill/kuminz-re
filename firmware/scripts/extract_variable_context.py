#!/usr/bin/env python3
"""Extract per-variable context from Ghidra decompiled output.

Usage:
    python3 extract_variable_context.py <ghidra_cpp> <ram_prefix> <min_refs> <output_dir>

Example:
    python3 extract_variable_context.py J90350.00.ghidra.cpp 0080 10 context_tier1/
    python3 extract_variable_context.py cm848_rom.ghidra.cpp 0040 5 context_tier2/

Output per batch:
    context_tier1/batch_00.txt  - function bodies + variable list for agent consumption
    context_tier1/batch_01.txt
    ...
    context_tier1/manifest.csv  - batch_id,variable_address,ref_count
"""
import re
import sys
import os
from collections import Counter


def split_into_functions(content):
    """Split decompiled output into individual functions."""
    fn_pattern = re.compile(r'^(\w[\w\s\*]+\s+\w+\(.*?\))\s*\n\{', re.MULTILINE)
    starts = [m.start() for m in fn_pattern.finditer(content)]
    functions = []
    for i, start in enumerate(starts):
        end = starts[i + 1] if i + 1 < len(starts) else len(content)
        fn_text = content[start:end].rstrip()
        functions.append(fn_text)
    return functions


def find_unnamed_ram_vars(content, ram_prefix, min_refs):
    """Find all DAT_{prefix}xxxx variables with min_refs+ references."""
    pattern = f'DAT_{ram_prefix}[0-9a-f]+'
    all_refs = re.findall(pattern, content)
    counts = Counter(all_refs)
    return {var: count for var, count in counts.items() if count >= min_refs}


def build_var_function_index(variables, functions):
    """Map each variable to the list of function indices that reference it."""
    var_fns = {}
    for var in variables:
        var_fns[var] = []
        for j, body in enumerate(functions):
            if var in body:
                var_fns[var].append(j)
    return var_fns


def cluster_by_cooccurrence(variables, var_fns, max_cluster_size=15):
    """Group variables that share functions, capping cluster size."""
    remaining = set(variables)
    clusters = []
    while remaining:
        seed = min(remaining)
        cluster = [seed]
        remaining.remove(seed)
        cluster_fns = set(var_fns[seed])
        for var in sorted(remaining):
            if set(var_fns[var]) & cluster_fns:
                cluster.append(var)
                cluster_fns |= set(var_fns[var])
                if len(cluster) >= max_cluster_size:
                    break
        remaining -= set(cluster)
        clusters.append(cluster)
    return clusters


def write_batch(batch_id, cluster, var_fns, var_counts, functions, output_dir):
    """Write a batch file with variable list and deduplicated function bodies."""
    path = os.path.join(output_dir, f'batch_{batch_id:02d}.txt')

    # Collect all unique function indices for this batch
    all_fn_indices = set()
    for var in cluster:
        all_fn_indices.update(var_fns[var])

    with open(path, 'w') as f:
        f.write("=== VARIABLES TO NAME ===\n")
        for var in cluster:
            addr = '0x' + var[4:]
            f.write(f"{addr}  ({var_counts[var]} references)\n")
        f.write(f"\nTotal: {len(cluster)} variables\n")
        f.write("\n=== FUNCTION BODIES (deduplicated) ===\n\n")

        for j in sorted(all_fn_indices):
            body = functions[j]
            vars_here = [v for v in cluster if j in var_fns[v]]
            f.write(f"// Variables in this function: {', '.join(vars_here)}\n")
            f.write(body)
            f.write("\n\n")

    return path


def main():
    if len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} <ghidra_cpp> <ram_prefix> <min_refs> <output_dir>")
        sys.exit(1)

    cpp_file = sys.argv[1]
    ram_prefix = sys.argv[2]
    min_refs = int(sys.argv[3])
    output_dir = sys.argv[4]

    print(f"Reading {cpp_file}...")
    with open(cpp_file) as f:
        content = f.read()

    print("Splitting into functions...")
    functions = split_into_functions(content)
    print(f"  Found {len(functions)} functions")

    print(f"Finding unnamed DAT_{ram_prefix}xxxx with {min_refs}+ refs...")
    variables = find_unnamed_ram_vars(content, ram_prefix, min_refs)
    print(f"  Found {len(variables)} variables")

    if not variables:
        print("No variables found. Done.")
        return

    print("Building variable-function index...")
    var_fns = build_var_function_index(variables, functions)

    print("Clustering by co-occurrence...")
    clusters = cluster_by_cooccurrence(variables, var_fns, max_cluster_size=15)
    print(f"  Created {len(clusters)} batches")

    os.makedirs(output_dir, exist_ok=True)

    manifest_path = os.path.join(output_dir, 'manifest.csv')
    with open(manifest_path, 'w') as f:
        f.write("batch_id,variable_address,ref_count\n")
        for i, cluster in enumerate(clusters):
            for var in cluster:
                addr = '0x' + var[4:]
                f.write(f"{i},{addr},{variables[var]}\n")

    for i, cluster in enumerate(clusters):
        all_fn_indices = set()
        for var in cluster:
            all_fn_indices.update(var_fns[var])
        total_lines = sum(len(functions[j].split('\n')) for j in all_fn_indices)

        path = write_batch(i, cluster, var_fns, variables, functions, output_dir)
        print(f"  Batch {i:2d}: {len(cluster):2d} vars, {len(all_fn_indices):3d} fns, {total_lines:5d} lines -> {path}")

    print(f"\nManifest: {manifest_path}")
    print(f"Total: {len(variables)} variables in {len(clusters)} batches")


if __name__ == '__main__':
    main()
