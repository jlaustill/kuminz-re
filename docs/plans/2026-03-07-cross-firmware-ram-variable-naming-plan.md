# Cross-Firmware RAM Variable Naming - Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Name unnamed DAT_ RAM variables in CM550 and CM848D decompiled output with consistent names, accuracy-first.

**Architecture:** Python script extracts per-variable context (full function bodies) from decompiled output, groups variables into batches by co-occurrence, dispatches parallel naming agents. Results filtered by confidence, applied to CSV, cross-validated between firmwares.

**Tech Stack:** Python 3 (context extraction), bash (Ghidra pipeline), Claude agents (naming)

---

### Task 1: Build context extraction script

**Files:**
- Create: `firmware/scripts/extract_variable_context.py`

**Step 1: Write the extraction script**

This script takes a decompiled `.ghidra.cpp` file and a RAM address prefix, then for each unnamed `DAT_` variable with N+ references, extracts all function bodies that reference it.

```python
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
from collections import Counter, defaultdict

def split_into_functions(content):
    """Split decompiled output into individual functions."""
    fn_pattern = re.compile(r'^(\w[\w\s\*]+\s+\w+\(.*?\))\s*\n\{', re.MULTILINE)
    starts = [m.start() for m in fn_pattern.finditer(content)]
    functions = []
    for i, start in enumerate(starts):
        end = starts[i+1] if i+1 < len(starts) else len(content)
        fn_text = content[start:end].rstrip()
        sig = fn_text.split('\n')[0]
        functions.append((sig, fn_text))
    return functions

def find_unnamed_ram_vars(content, ram_prefix, min_refs):
    """Find all DAT_{prefix}xxxx variables with min_refs+ references."""
    pattern = f'DAT_{ram_prefix}[0-9a-f]+'
    all_refs = re.findall(pattern, content)
    counts = Counter(all_refs)
    return {var: count for var, count in counts.items() if count >= min_refs}

def build_var_function_index(variables, functions):
    """Map each variable to the set of function indices that reference it."""
    var_fns = {}
    for var in variables:
        var_fns[var] = []
        for j, (sig, body) in enumerate(functions):
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
        # Header: which variables to name
        f.write("=== VARIABLES TO NAME ===\n")
        for var in cluster:
            addr = '0x' + var[4:]  # DAT_0080abcd -> 0x0080abcd
            f.write(f"{addr}  ({var_counts[var]} references)\n")
        f.write(f"\nTotal: {len(cluster)} variables\n")
        f.write("\n=== FUNCTION BODIES (deduplicated) ===\n\n")

        # Write each function body once, sorted by index
        for j in sorted(all_fn_indices):
            sig, body = functions[j]
            # Mark which batch variables appear in this function
            vars_here = [v for v in cluster if j in var_fns[v]]
            f.write(f"// Variables in this function: {', '.join(vars_here)}\n")
            f.write(body)
            f.write("\n\n")

    return path

def main():
    if len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} <ghidra_cpp> <ram_prefix> <min_refs> <output_dir>")
        sys.exit(1)

    cpp_file, ram_prefix, min_refs, output_dir = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4]

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

    # Write manifest
    manifest_path = os.path.join(output_dir, 'manifest.csv')
    with open(manifest_path, 'w') as f:
        f.write("batch_id,variable_address,ref_count\n")
        for i, cluster in enumerate(clusters):
            for var in cluster:
                addr = '0x' + var[4:]
                f.write(f"{i},{addr},{variables[var]}\n")

    # Write batch files
    for i, cluster in enumerate(clusters):
        all_fn_indices = set()
        for var in cluster:
            all_fn_indices.update(var_fns[var])
        total_lines = sum(len(functions[j][1].split('\n')) for j in all_fn_indices)

        path = write_batch(i, cluster, var_fns, variables, functions, output_dir)
        print(f"  Batch {i:2d}: {len(cluster):2d} vars, {len(all_fn_indices):3d} fns, {total_lines:5d} lines -> {path}")

    print(f"\nManifest: {manifest_path}")
    print(f"Total: {len(variables)} variables in {len(clusters)} batches")

if __name__ == '__main__':
    main()
```

**Step 2: Test the script on CM550 Tier 1**

Run: `cd firmware/CM550_J90350.00_analysis/output && python3 ../../scripts/extract_variable_context.py J90350.00.ghidra.cpp 0080 10 context_tier1/`

Expected: Creates `context_tier1/` with batch files and manifest.csv. ~176 variables in ~12-15 batches.

**Step 3: Verify batch content quality**

Manually inspect `context_tier1/batch_00.txt`:
- Variables listed at top with reference counts
- Function bodies contain the listed DAT_ variables
- Named variables visible as context clues

**Step 4: Commit**

```bash
git add firmware/scripts/extract_variable_context.py
git commit -m "firmware: Add variable context extraction script for naming campaigns"
```

---

### Task 2: Extract CM550 Tier 1 context

**Files:**
- Create: `firmware/CM550_J90350.00_analysis/output/context_tier1/` (batch files + manifest)

**Step 1: Run extraction**

```bash
cd firmware/CM550_J90350.00_analysis/output
python3 ../../scripts/extract_variable_context.py J90350.00.ghidra.cpp 0080 10 context_tier1/
```

**Step 2: Review batch sizes**

Check that no batch exceeds ~120K estimated tokens (~10,000 lines). If any do, reduce `max_cluster_size` in the script and re-run.

**Step 3: Spot-check 2-3 batches**

Read first 50 lines of 2-3 batch files to verify context quality.

---

### Task 3: Dispatch Tier 1 naming agents

**Prerequisite:** Task 2 complete.

For each batch file in `context_tier1/`, dispatch a parallel agent with this prompt structure:

```
You are naming unnamed RAM variables in Cummins CM550 ECU firmware (MC68336, VP44 fuel injection).
The decompiled output is from Ghidra. RAM is at 0x0080xxxx.

RULES:
- Accuracy is the TOP priority. A wrong name is worse than no name.
- Use snake_case (e.g., fuel_demand_filtered, sensor_channel3_raw)
- Use decimal numbers in names, not hex
- If you cannot confidently determine what a variable does, set confidence to "low"
- Base names on HOW the variable is used across ALL functions shown, not just one occurrence
- Look at co-occurring named variables for domain context
- Common domains: fuel/timing/governor/throttle/boost/protection/fault/j1939/sensor/engine

EXISTING NAMING PATTERNS (use these when applicable):
- fuel_demand_*, fuel_limit_*, fuel_timing_*
- engine_speed_*, engine_state_*, engine_mode_*
- throttle_position_*, boost_pressure_*
- governor_speed_*, governor_mode_*
- sensor_channel*_*, protection_*, fault_*
- j1939_*, can_message_*, diagnostic_*

OUTPUT FORMAT - one CSV line per variable:
address,proposed_name,confidence,reasoning

Confidence levels:
- high: Clear from multiple usage contexts what this variable represents
- medium: Likely correct but only 1-2 strong contextual clues
- low: Uncertain - DO NOT propose a name, just note what you observed

[BATCH CONTENT HERE]
```

Each agent reads its batch file and outputs CSV lines. Collect all results into `context_tier1/results/`.

**Step: Merge results**

Concatenate all agent CSV outputs into `context_tier1/all_results.csv`.

**Step: Filter by confidence**

```bash
# High confidence - apply automatically
grep ",high," context_tier1/all_results.csv > context_tier1/apply.csv
# Medium confidence - manual review
grep ",medium," context_tier1/all_results.csv > context_tier1/review.csv
# Low confidence - skip
grep ",low," context_tier1/all_results.csv > context_tier1/skipped.csv
wc -l context_tier1/apply.csv context_tier1/review.csv context_tier1/skipped.csv
```

---

### Task 4: Apply Tier 1 high-confidence names to CM550

**Prerequisite:** Task 3 complete, results reviewed.

**Step 1: Check for naming conflicts**

```bash
# Check proposed names don't collide with existing names
cut -d, -f2 context_tier1/apply.csv | sort | uniq -d  # duplicates in results
cut -d, -f2 context_tier1/apply.csv | while read name; do
    grep -q ",$name," global_variables.csv && echo "COLLISION: $name"
done
```

**Step 2: Append to global_variables.csv**

```bash
# Add each high-confidence variable to CSV
while IFS=, read -r addr name confidence reasoning; do
    echo "${addr},${name},undefined," >> global_variables.csv
done < context_tier1/apply.csv
```

**Step 3: Import and re-export**

```bash
cd ../ghidra
./analyze.sh import
./analyze.sh export
```

**Step 4: Verify in decompiled output**

Spot-check 5-10 renamed variables in the new `J90350.00.ghidra.cpp` — confirm the names appear correctly and make sense in context.

**Step 5: Commit**

```bash
git add ../output/global_variables.csv ../output/J90350.00.ghidra.cpp
git commit -m "firmware(CM550): Name Tier 1 RAM variables (10+ refs) - N high-confidence"
```

---

### Task 5: Extract and process CM550 Tier 2 (5-9 refs)

**Same workflow as Tasks 2-4, but with min_refs=5 and max_refs filter.**

**Step 1: Extract context**

```bash
cd firmware/CM550_J90350.00_analysis/output
python3 ../../scripts/extract_variable_context.py J90350.00.ghidra.cpp 0080 5 context_tier2/
# Note: this will include Tier 1 vars again. Filter manifest to only 5-9 ref vars.
```

The script needs a max_refs parameter, or filter the manifest post-extraction to exclude already-named Tier 1 variables. Since Tier 1 names were already applied and re-exported, the decompiled output will no longer contain those DAT_ symbols — they'll appear as named variables. So re-running extraction on the updated `.ghidra.cpp` naturally excludes Tier 1.

**Step 2-4: Dispatch agents, filter results, apply names**

Same as Tasks 3-4 but for Tier 2 batches.

**Step 5: Commit**

```bash
git commit -m "firmware(CM550): Name Tier 2 RAM variables (5-9 refs) - N high-confidence"
```

---

### Task 6: Name CM848 remaining RAM variables (21 vars, 5+ refs)

**Step 1: Extract context**

```bash
cd firmware/CM848_S90140.06_analysis/output
python3 ../../scripts/extract_variable_context.py cm848_rom.ghidra.cpp 0040 5 context_ram/
```

**Step 2: Single agent dispatch**

21 variables is small enough for a single agent. Include the CM550 naming conventions list as additional context so the agent prefers consistent names.

**Step 3: Apply and verify**

Same import/export/verify cycle as Task 4.

**Step 4: Commit**

```bash
git commit -m "firmware(CM848): Name remaining RAM variables (5+ refs) - N high-confidence"
```

---

### Task 7: Cross-firmware validation

**Prerequisite:** Tasks 4-6 complete.

**Step 1: Find shared variable names**

```bash
comm -12 \
  <(grep -v "^#\|^address" CM550_J90350.00_analysis/output/global_variables.csv | awk -F, '{print $2}' | grep -v "DAT_\|BYTE_\|caseD_\|switchD\|default\|SUB_\|PTR_" | sort -u) \
  <(grep -v "^#\|^address" CM848_S90140.06_analysis/output/global_variables.csv | awk -F, '{print $2}' | grep -v "DAT_\|BYTE_\|caseD_\|switchD\|default\|SUB_\|PTR_" | sort -u)
```

**Step 2: For each shared name, check function context**

For each variable name that appears in both firmwares, verify they serve the same purpose by checking which functions reference them.

**Step 3: Produce cross_firmware_variable_map.csv**

```csv
cm550_address,cm848_address,name,match_type,evidence
0x0080abcd,0x0040ef12,fuel_demand_filtered,confirmed,both in fuel_limit_arbitrator
0x0080dcba,0x0040aabb,throttle_position_raw,confirmed,both in governor init
0x0080eeee,,vp44_timing_accumulator,cm550_unique,VP44-specific
,0x00401234,cbd_cylinder_trim_1,cm848_unique,common-rail-specific
```

**Step 4: Report summary**

Count: confirmed matches, CM550-unique, CM848-unique, name collisions (same name different purpose).

**Step 5: Commit**

```bash
git add docs/cross_firmware_variable_map.csv
git commit -m "docs: Add cross-firmware variable mapping (N confirmed matches)"
```

---

### Task 8: Update project tracking

**Step 1: Update work/todo.md**

Add the new task entry and mark status.

**Step 2: Update MEMORY.md**

Record campaign results: counts, coverage percentages, cross-firmware match count.
