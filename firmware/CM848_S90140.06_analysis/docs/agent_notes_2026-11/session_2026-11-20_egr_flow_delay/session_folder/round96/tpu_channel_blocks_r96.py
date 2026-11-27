"""Round 96 stage B (CM848): every TPU3 channel's 16-byte parameter block is a struct instance.
- The MPC555 TPU3 parameter RAM gives each channel eight words at 0x304100 + 16 x n (TPU-A) / 0x304500 + 16 x n (TPU-B)
  (MPC555UM Section 17). Eight blocks already had a type (tpu3_channel_parameters_t at TPU-A 0, and seven per-channel
  types); the other 24 were plain word rows named TPUA_CHn_PARAMm / TPUB_CHn_PARAMm or nothing (30 words rendered as
  DAT_003041xx / DAT_003045xx, and indexed writes as *(undefined2 *)((int)&DAT_00304152 + param_4)).
- Each untyped block becomes a tpu3_channel_parameters_t instance named tpu_a_channel_<n>_parameters /
  tpu_b_channel_<n>_parameters (the names the typed blocks took in round 95); its PARAMm rows go (they are the fields).
  A row's comment moves to the instance's comment.
- Also: the eight stale documentation rows (stale_doc_rows_r96.py --fix).
Writes the map for the proofs and the refresh. Idempotent; keeps line endings. usage: tpu_channel_blocks_r96.py <repo> <map>"""
import os
import re
import subprocess
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 96"
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
index = {}
for i, l in enumerate(lines):
    parts = l.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        index[int(parts[0], 16)] = i
mapping = []
remove = set()
added = []
for module, base in (("a", 0x304100), ("b", 0x304500)):
    for n in range(16):
        start = base + 16 * n
        name = f"tpu_{module}_channel_{n}_parameters"
        i = index.get(start)
        parts = lines[i].split(",", 3) if i is not None else None
        if parts and parts[2].startswith("tpu"):
            continue                                            # already a typed block (round 95 names)
        notes = []
        for m in range(8):
            a = start + 2 * m
            j = index.get(a)
            if j is None:
                continue
            q = lines[j].split(",", 3)
            if q[1] and ("." in q[1] or "[" in q[1]):
                continue                                        # documentation rows stay
            assert not q[1] or re.match(r"^TPU[AB]_CH\d+_PARAM\d$", q[1]), f"a role-named row inside a block: {lines[j]}"
            if q[1]:
                mapping.append((f"0x{a:08x}", f"{name}.PARAM{m}", q[1]))
            if len(q) > 3 and q[3]:
                notes.append(f"PARAM{m}: {q[3]}")
            if a != start:
                remove.add(j)
        comment = (f"TPU-{module.upper()} channel {n} parameter RAM (0x{start:x}-0x{start + 15:x}; eight words PARAM0-7: "
                   f"their meaning depends on the channel's TPU function) ({R})")
        if notes:
            comment += " | earlier notes: " + " / ".join(notes)
        row = f"0x{start:08x},{name},tpu3_channel_parameters_t,{comment}"
        if i is not None:
            old = parts[1]
            if old and not old.startswith(name):
                comment = comment.replace(f"({R})", f"(was {old}; {R})")
                row = f"0x{start:08x},{name},tpu3_channel_parameters_t,{comment}"
            lines[i] = row
        else:
            added.append((start, row))
lines = [l for j, l in enumerate(lines) if j not in remove]
for start, row in added:
    k = next(k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > start)
    lines.insert(k, row)
open(p, "w", newline="").write(E.join(lines))
print(f"{len(remove)} PARAM rows removed, {len(added)} instances added, {len(mapping)} map rows")
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in mapping:
        f.write(f"{a},{new},{old},symbol,1\n")
subprocess.run([sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), "stale_doc_rows_r96.py"), repo, "--fix"], check=True)
