"""Round 90 stage C (CM550): apply the naming wave's verified proposals (workflow wf_69f8159d-0ca: an investigator and a
skeptic per batch; only CONFIRMED / AMENDED verdicts are applied, with the skeptic's final name / type / comment).
- group A (no row): a new row in address order;
- groups B / C (an existing placeholder / mnemonic row): the row is renamed and retyped; its old name goes into the
  comment ("was X") so the mnemonic stays findable.
Checks before writing: a final name must be new to global_variables.csv and unique in the wave; an array's span must
not cover another row with a user (rows inside it with no reference in the .cpp are removed and listed); _cal only in
the EEPROM mirror 0x803B0A-0x804155. Refuses (exits 1) on any violation. Idempotent; keeps line endings.
usage: apply_r90c.py <repo> <result.json> <map.csv> <report.txt>"""
import collections
import json
import os
import re
import sys

repo, result_path, map_out, report_out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 90"
G = os.path.join(O, "global_variables.csv")
text = open(G, newline="").read()
lines = text.split("\n")
index = {int(l.split(",")[0], 16): i for i, l in enumerate(lines) if l.startswith("0x")}
names = {l.split(",")[1]: int(l.split(",")[0], 16) for l in lines if l.startswith("0x")}
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
refs = collections.Counter(re.findall(r"\b[A-Za-z_]\w*\b", code))
SIZES = {"byte": 1, "char": 1, "bool": 1, "word": 2, "i16": 2, "short": 2, "dword": 4, "i32": 4, "pointer": 4}


def size_of(typ):
    m = re.match(r"^(\w+)\s*\[(\d+)\]$", typ.strip())
    if m:
        return SIZES.get(m.group(1), 0) * int(m.group(2))
    return SIZES.get(typ.strip(), 0)


data = json.load(open(result_path))
results = data.get("results", data)
apply, problems, report = [], [], []
seen, by_address = {}, {}
# Two of the wave's verdicts named element 0 of a per-channel array: mc68k_processAnalogSensorChannels reads
# *(word *)(&DAT_0080a72e + channel*2) / *(word *)(&DAT_0080a760 + channel*2) when the channel's override bit is set,
# both 25 words (0x80a72e + 50 = 0x80a760), and the unused rows inside sit at the right channel offsets (ambient air
# temperature = channel 7 in both, frequency throttle input supply voltage = raw channel 18).
OVERRIDES = {
    0x80a72e: ("analog_sensor_override_values", "word[25]",
               "The engineering-unit override of each A/D channel: mc68k_processAnalogSensorChannels uses element "
               "[channel] as the channel's filtered_value (skipping its A/D processing) while the channel's bit of 0x803c9e "
               "(channels 0-15) / 0x803ca0 (16-24) is set (e2m 106B +C / +E 'OVERRIDE'). Element 0 is Calterm ADUOIMTP "
               "(12D2 +0 user value for intake manifold temperature); no writer in the dumped ROM (a service-tool value)"),
    0x80a760: ("analog_sensor_raw_override_values", "word[25]",
               "The raw (A/D count) override of each A/D channel: mc68k_processAnalogSensorChannels uses element [channel] "
               "as the channel's adc_raw_value instead of the QADC result while the channel's bit of 0x803cc0 (0-15) / "
               "0x803cc2 (16-24) is set (e2m 106B +2E 'OVERRIDE RAW ENABLE'). Element 0 is Calterm ADIMTPUR (12D3 +0 "
               "intake manifold temperature raw user value); cm550_FUN_00020fac writes it from a priority-arbitrated "
               "client (priority word 0x80a6fc; one source is the J1939 multiplexed byte at 0x80d720)"),
}
for res in results:
    proposals = {p["address"].lower(): p for p in res["proposals"]["proposals"]}
    for v in (res.get("verdicts") or {}).get("verdicts", []):
        if v["verdict"] not in ("CONFIRMED", "AMENDED"):
            report.append(f"{res['batch']} {v['address']} {v['verdict']}: {v.get('reason', '')[:200]}")
            continue
        a = int(v["address"], 16)
        p = proposals.get(v["address"].lower(), {})
        name, typ = v.get("final_name") or p.get("proposed_name"), v.get("final_type") or p.get("proposed_type")
        if a in OVERRIDES:
            name, typ, override_comment = OVERRIDES[a]
            v = dict(v, comment=override_comment)
            report.append(f"{res['batch']} 0x{a:08x}: the verdict's {v.get('final_name')} became {name} {typ} (an array)")
        if a in by_address and by_address[a] != name:
            problems.append(f"0x{a:x}: two names ({by_address[a]} / {name})")
        by_address[a] = name
        if not name or not typ or not size_of(typ):
            problems.append(f"{v['address']}: name / type missing or unknown ({name!r} / {typ!r})")
            continue
        if name in seen and seen[name] != a:
            problems.append(f"{name}: proposed for 0x{seen[name]:x} and 0x{a:x}")
        seen[name] = a
        if name in names and names[name] != a:
            problems.append(f"{name}: already the name of 0x{names[name]:x}")
        if name.endswith("_cal") != (0x803B0A <= a <= 0x804155):
            problems.append(f"{name} @ 0x{a:x}: _cal does not match the EEPROM mirror rule")
        if re.search(r"\binit\b|_init_|_init$|^init_", name):
            problems.append(f"{name}: says init")
        apply.append((a, name, typ, v.get("comment", "").replace("\n", " ").strip(), res["batch"], p.get("current_label", "")))
covered = []
for a, name, typ, comment, batch, old in apply:
    end = a + size_of(typ)
    for b in sorted(index):
        if a < b < end:
            inner = lines[index[b]].split(",")[1]
            if inner and (refs.get(inner) or refs.get("_" + inner)):
                problems.append(f"{name} ({typ}) @ 0x{a:x} covers 0x{b:x} {inner}, which the .cpp references")
            else:
                covered.append(b)
if problems:
    print("REFUSED:\n" + "\n".join(problems))
    sys.exit(1)
renames = []
for a, name, typ, comment, batch, old in sorted(apply):
    old_name = lines[index[a]].split(",")[1] if a in index else ""
    if old_name == name:
        continue
    was = f" (was {old_name}; {R})" if old_name else f" ({R})"
    row = f"0x{a:08x},{name},{typ},{comment}{was}"
    if a in index:
        lines[index[a]] = row
    else:
        after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < a]
        lines.insert(after[-1] + 1, row)
        index = {int(l.split(",")[0], 16): i for i, l in enumerate(lines) if l.startswith("0x")}
    renames.append((f"0x{a:08x}", name, old_name or old))
    report.append(f"{batch} 0x{a:08x} {old_name or old or '(no row)'} -> {name} {typ}")
for b in covered:
    report.append(f"removed 0x{b:08x} {lines[index[b]].split(',')[1]} (inside a new array, no user)")
lines = [l for l in lines if not (l.startswith("0x") and int(l.split(",")[0], 16) in set(covered))]
open(G, "w", newline="").write("\n".join(lines))
with open(map_out, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a, n, o in renames:
        fh.write(f"{a},{n},{o},symbol,1\n")
open(report_out, "w").write("\n".join(report) + "\n")
print(f"applied {len(renames)} rows ({sum(1 for r in renames if r[2] and not r[2].startswith(('DAT_', '_DAT_')))} renames); "
      f"{len(covered)} covered rows removed; report {report_out}")
