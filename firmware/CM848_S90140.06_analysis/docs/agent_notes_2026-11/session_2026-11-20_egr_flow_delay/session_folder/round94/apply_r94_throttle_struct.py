"""Round 94 stage B (CM550): the commanded throttle state as a struct - CM848's commanded_throttle_state_t for the
same Calterm block (e2m 1047). CM550's block holds 13 words at 0x80aa82; by mnemonic its +0 .. +0x12 are CM848's
fields, +0x14 is CM550's own CTIVIH (inhibit idle validation), +0x16 / +0x18 are CM848's +0x14 / +0x16, and CM848's
two delta words (+0x18 / +0x1a) do not exist here - so its own type, cm550_commanded_throttle_state_t (26 bytes),
with CM848's field names. Every direct ROM access to 0x80aa82-0x80aa9b is a word access (width_census_r93.py; the
rest are movea.l loads of single field addresses). The 11 rows inside the instance are removed and mapped to
their fields. Idempotent; keeps line endings. usage: apply_r94_throttle_struct.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 94"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
BASE, STRUCT, INSTANCE = 0x0080AA82, "cm550_commanded_throttle_state_t", "commanded_throttle_state"
FIELDS = [  # offset, mnemonic, field (CM848's name where the mnemonic is CM848's), CM848 offset or None
    (0x00, "THROTTLE", "commanded_throttle", 0x00), (0x02, "CTTHID", "idle_validation_state", 0x02),
    (0x04, "CTTHSS", "accelerator_off_idle", 0x04), (0x06, "CTTZST", "throttle_transition_state", 0x06),
    (0x08, "CTCBCU", "throttle_minimum_confidence_counter", 0x08), (0x0A, "CTMNSATH", "throttle_minimum", 0x0A),
    (0x0C, "CTALTH", "alternate_throttle", 0x0C), (0x0E, "CTTHSL", "alternate_throttle_priority", 0x0E),
    (0x10, "CTEVTETH", "calculated_commanded_throttle", 0x10), (0x12, "CTALSLST", "selected_alternate_throttle_priority", 0x12),
    (0x14, "CTIVIH", "idle_validation_inhibit_flag", None), (0x16, "FQTHSATH", "sampled_frequency_throttle", 0x14),
    (0x18, "FQTHAC", "frequency_throttle_active_flag", 0x16),
]
desc = {}
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), errors="replace"):
    f = line.split(",")
    if len(f) > 6 and f[2] == "1047" and ";" in line:
        text = line.split(";", 1)[1].strip()
        desc[f[0]] = (text.split("~")[0].strip().rstrip("."), (text.split("~")[1].strip() if "~" in text else ""))


def quote(text):
    text = " ".join(text.split())
    return '"' + text.replace('"', "'") + '"' if ("," in text or '"' in text) else text


S = os.path.join(O, "structure_definitions.csv")
s = open(S, newline="").read()
E = "\r\n" if "\r\n" in s else "\n"
if not re.search(rf"^{STRUCT},,", s, re.M):
    rows = [f"# {STRUCT}: e2m 1047 (26 bytes), the commanded throttle block - CM848's commanded_throttle_state_t with CTIVIH "
            f"inserted at +0x14 and no delta words ({R})"]
    for off, mn, field, off848 in FIELDS:
        d, rng = desc[mn]
        twin = f"CM848's {field} (+0x{off848:x})" if off848 is not None else "CM550 only"
        rows.append(f"{STRUCT},,{field},word,2,{quote(f'e2m 1047 +0x{off:x} {mn} {d!r} ({rng}); {twin}')},,verified")
    s = s.rstrip("\r\n") + E + E + E.join(rows) + E
    open(S, "w", newline="").write(s)
G = os.path.join(O, "global_variables.csv")
lines = open(G, newline="").read().split("\n")
pairs = []
by_off = {off: field for off, _, field, _ in FIELDS}
out = []
for line in lines:
    if line.startswith("0x"):
        a = int(line.split(",")[0], 16)
        if BASE < a < BASE + 26:
            name = line.split(",")[1]
            assert (a - BASE) in by_off, hex(a)
            pairs.append((f"0x{a:08x}", f"{INSTANCE}.{by_off[a - BASE]}", name))
            continue
        if a == BASE:
            parts = line.split(",", 3)
            if parts[1] != INSTANCE:
                pairs.append((parts[0], f"{INSTANCE}.commanded_throttle", parts[1]))
                comment = parts[3] if len(parts) > 3 else ""
                line = (f"{parts[0]},{INSTANCE},{STRUCT},e2m 1047: the commanded throttle block (13 words): the commanded "
                        f"throttle, the idle validation and transition states, the learned throttle minimum, the alternate "
                        f"throttle claim and its priority, the frequency throttle. CM848 keeps the same block as "
                        f"commanded_throttle_state (commanded_throttle_state_t) (was {parts[1]} plus 10 rows for its other "
                        f"words; {R})" + (f" | earlier note: {comment}" if comment else ""))
    out.append(line)
if pairs:
    open(G, "w", newline="").write("\n".join(out))
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, new, old in pairs:
            fh.write(f"{a},{new},{old},symbol,1\n")
print(f"{STRUCT}: {len(FIELDS)} fields; {len(pairs)} rows mapped into the instance")
