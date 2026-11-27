"""Gate for round 24 stage E: both .cpp files with every reference to a word of the three fault bit arrays replaced by
an address token (FD / FR / FP + word index), comments stripped, labels canonical, declarations sorted, whitespace
dropped. Old names come from the old global_variables.csv (flat rows, the system_status_flags_t fields by order, the
default labels DAT_ / WORD_ / uRam / _DAT_ of every word address); new ones are <instance>.faults_A_to_B. '&instance'
and '&instance.faults_0_to_15' are the same address. Also prints the piece / underscore census of both files.
usage: prove_r24e.py <old.cpp> <new.cpp> <old global_variables.csv> [--show N]"""
import difflib
import os
import re
import sys

sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/rename_waves")
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402

old_path, new_path, old_globals = sys.argv[1:4]
show = int(sys.argv[sys.argv.index("--show") + 1]) if "--show" in sys.argv else 3
BASES = {0x3fe974: "D", 0x3fe9d8: "R", 0x3fea3c: "P"}
NEW = {"fault_detected_cal": "D", "fault_registered_cal": "R", "fault_previous_pass_cal": "P"}
OLD_FIELDS = ["fault_detected_bits_0_to_15", "fault_detected_bits_16_to_31", "fault_detected_bits_32_to_47",
              "fault_detected_bits_48_to_63", "fault_detected_bits_64_to_79", "fault_detected_bits_80_to_95",
              "fault_detected_bits_96_to_111", "fault_detected_bits_112_to_127", "fault_detected_bits_128_to_143",
              "fault_detected_bits_144_to_159", "fault_detected_bits_160_to_175", "reserved_16",
              "fault_detected_bits_192_to_207", "fault_detected_bits_208_to_223", "reserved_1c", "severity_flags",
              "fault_detected_bits_256_to_271", "fault_detected_bits_272_to_287", "fault_detected_bits_288_to_303",
              "fault_detected_bits_304_to_319", "fault_detected_bits_320_to_335"]


def token(base, a):
    return f"F{BASES[base]}{(a - base) // 2}"


old_map = {}
for w, f in enumerate(OLD_FIELDS):
    old_map[f"system_status_flags_t_003fe974.{f}"] = f"FD{w}"
old_map["system_status_flags_t_003fe974"] = "FD0"
for line in open(old_globals):
    if not line.startswith("0x"):
        continue
    a_str, name = line.split(",", 2)[:2]
    a = int(a_str, 16)
    for base in BASES:
        if base <= a < base + 100 and name and "." not in name:
            old_map[name] = token(base, a)
for base in BASES:
    for a in range(base, base + 100, 2):
        for p in ("DAT_", "WORD_", "uRam", "_DAT_", "BYTE_"):
            old_map[f"{p}{a:08x}"] = token(base, a)


def normalize_tokens(text, mapping):
    for k in sorted(mapping, key=len, reverse=True):
        text = re.sub(r"(?<![A-Za-z0-9_.])" + re.escape(k) + r"(?![A-Za-z0-9_])", mapping[k], text)
    return text


old = open(old_path).read()
new = open(new_path).read()


def census(text):
    code = strip_comments(text)
    return len(re.findall(r"\._\d+_\d+_", code)), len(re.findall(r"(?<![A-Za-z0-9_.>])_[a-z][a-z0-9_]{3,}\b", code))


print("pieces / underscore names: old %d / %d, new %d / %d" % (census(old) + census(new)))
old = normalize_tokens(strip_comments(strip_generated_header(old)), old_map)
new_map = {}
for inst, letter in NEW.items():
    for w in range(50):
        new_map[f"{inst}.faults_{16 * w}_to_{16 * w + 15}"] = f"F{letter}{w}"
    new_map[inst] = f"F{letter}0"
new = normalize_tokens(strip_comments(strip_generated_header(new)), new_map)
old, new = canonical_labels(old), canonical_labels(new)
DECL = re.compile(r"^  [A-Za-z_][\w ]*[\w\*]\s*\**[A-Za-z_]\w*(\[\d+\])?;$")


def functions(text):
    out = {}
    for c in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", c)
        lines = c.split("\n")
        if "{" in lines:
            i = lines.index("{") + 1
            j = i
            while j < len(lines) and DECL.match(lines[j]):
                j += 1
            lines[i:j] = sorted(lines[i:j])
        # one whitespace-free string per function: the decompiler re-wraps lines when name lengths change
        out[m.group(1) if m else "_head"] = re.sub(r"\s+", "", "\n".join(lines))
    return out


fo, fn = functions(old), functions(new)
differ = [f for f in fo if fo[f] != fn.get(f)]
print(f"functions {len(fo)}; differing after the address normalization: {len(differ)}")
for f in differ[:show]:
    print("==", f)
    a, b = fo[f], fn.get(f, "")
    i = next((k for k in range(min(len(a), len(b))) if a[k] != b[k]), min(len(a), len(b)))
    print("   old:", a[max(0, i - 80):i + 120])
    print("   new:", b[max(0, i - 80):i + 120])
print("GATE PASS" if not differ else "GATE: review the differences")
