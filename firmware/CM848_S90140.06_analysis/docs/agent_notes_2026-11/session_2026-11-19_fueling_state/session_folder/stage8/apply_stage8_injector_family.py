"""Stage 8 follow-up: finish the e2m 80B9 injector diagnostic family. Wave 13 (bin 3) renamed the four bits bytes from
letters to meanings (a = open circuit, b = short to ground, c = short to battery, d = fast decay); their debounce counters
and limits kept the letters, so a reader could no longer pair them. cm848_evaluateInjectorDiagnostics passes each bits
byte to cm848_evaluateInjectorDiagnosticFault with the counter and limit of the same letter (open_circuit with a,
short_to_battery with c, short_to_ground with b, fast_decay with d), so the letter -> meaning map carries over.
Writes gate_input_stage8_injector.jsonl (for the repo gate), then with --apply renames the rows (repo form:
"<comment> (was <old>) | earlier note: <old comment>") and appends the rows to map_stage8.csv.
usage: apply_stage8_injector_family.py <stage8 dir> <CM848 output dir> [--apply]"""
import json
import os
import sys

here, out = sys.argv[1:3]
MEANING = {"a": "open_circuit", "b": "short_to_ground", "c": "short_to_battery", "d": "fast_decay"}
ROWS = {"0x003fb6fc": ("a", "count"), "0x003fb6fe": ("c", "count"), "0x003fb700": ("b", "count"),
        "0x003fb702": ("d", "count"), "0x00409a8a": ("d", "limit"), "0x00409a8c": ("a", "limit"),
        "0x00409a8e": ("b", "limit"), "0x00409a90": ("c", "limit")}
WHAT = {"count": "Debounce counter", "limit": "Debounce limit"}
renames = []
for address, (letter, kind) in ROWS.items():
    old = f"injector_diagnostic_bits_{letter}_debounce_{kind}"
    new = f"injector_diagnostic_bits_{MEANING[letter]}_debounce_{kind}"
    evidence = (f"{WHAT[kind]} of injector_diagnostic_bits_{MEANING[letter]} (e2m 80B9, the bits byte that was letter "
                f"{letter}): cm848_evaluateInjectorDiagnostics passes them together to "
                f"cm848_evaluateInjectorDiagnosticFault.")
    renames.append({"kind": "global", "verdict": "confirmed", "address": address, "old": old, "new": new,
                    "evidence": evidence})
with open(os.path.join(here, "gate_input_stage8_injector.jsonl"), "w") as f:
    f.write("".join(json.dumps(r) + "\n" for r in renames))
if "--apply" not in sys.argv:
    print(f"wrote {len(renames)} gate rows")
    sys.exit(0)
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
for r in renames:
    i = index[r["address"]]
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == r["old"], (r["address"], name)
    lines[i] = ",".join([a, r["new"], typ, f"{r['evidence']} (was {r['old']})" + (f" | earlier note: {comment}" if comment else "")])
open(path, "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage8.csv"), "a") as f:
    for r in renames:
        f.write(f"{r['address']},{r['new']},{r['old']},global\n")
print(f"applied {len(renames)} renames")
