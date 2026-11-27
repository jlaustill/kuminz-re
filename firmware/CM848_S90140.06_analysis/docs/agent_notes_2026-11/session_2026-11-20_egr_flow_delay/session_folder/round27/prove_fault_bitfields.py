"""Round 27 stage B: mask-exact proof of the fault bitfields. Rewrites the new .cpp into the old notation and compares
every function (comments stripped, whitespace removed). Handles the flat layout (<inst>.<bit>) and the nested one
(<inst>.faults_A_to_B.<bit>):
  <bit> == 0 / != 0                  -> (<inst>.faults_A_to_B & M) == 0 / != 0     (M = the bit's own mask)
  <bit> = 1; / = 0;                  -> <inst>.faults_A_to_B = <inst>.faults_A_to_B | M; / & ~M;
  <inst>._<2w>_2_ / <inst>.faults_A_to_B._0_2_   -> <inst>.faults_A_to_B          (word pieces)
then merges a run of same-word clears (x = x & C1; x = x & C2; ...) or sets into one statement (the decompiler
prints one multi-bit and / or of a bitfield word as one store per bit). A bit name that rendered for another bit of
its word comes back with the wrong mask, so it shows as a difference. Masks print as Ghidra prints them (decimal
below 10, hex from 0x10).
usage: prove_fault_bitfields.py <old cpp> <new cpp> <fault_fields.tsv> [--show N]"""
import re
import sys

old_cpp, new_cpp, tsv = sys.argv[1:4]
show = int(sys.argv[sys.argv.index("--show") + 1]) if "--show" in sys.argv else 5
INST = r"(fault_(?:detected|registered|previous_pass)_cal)"
bit_of = {}
for line in open(tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    if int(word) >= 1:
        bit_of[field] = (int(word), int(bit))


def lit(v):
    return str(v) if v < 10 else f"0x{v:x}"


def word_name(w):
    return f"faults_{16 * w}_to_{16 * w + 15}"


NAMES = "|".join(sorted(map(re.escape, bit_of), key=len, reverse=True))
WORD = r"(?:\.faults_\d+_to_\d+)?"          # the nested layout's word field, absent in the flat layout
counts = {"read": 0, "write": 0, "piece": 0, "merged": 0, "other": 0}


def rewrite(text):
    def read(m):
        inst, f, op = m.group(1), m.group(2), m.group(3)
        w, b = bit_of[f]
        counts["read"] += 1
        return f"({inst}.{word_name(w)} & {lit(1 << b)}) {op} 0"

    def write(m):
        inst, f, v = m.group(1), m.group(2), m.group(3)
        w, b = bit_of[f]
        counts["write"] += 1
        if v == "1":
            return f"{inst}.{word_name(w)} = {inst}.{word_name(w)} | {lit(1 << b)};"
        return f"{inst}.{word_name(w)} = {inst}.{word_name(w)} & {lit(0xffff ^ (1 << b))};"

    def outer_piece(m):
        counts["piece"] += 1
        return f"{m.group(1)}.{word_name(int(m.group(2)) // 2)}"

    def nested_piece(m):
        counts["piece"] += 1
        return f"{m.group(1)}.{m.group(2)}"
    def compare(m):
        a, fa, op, b, fb = m.group(1), m.group(2), m.group(3), m.group(4), m.group(5)
        if fa != fb:
            return m.group(0)
        w, k = bit_of[fa]
        counts["read"] += 2
        return f"({a}.{word_name(w)} & {lit(1 << k)}) {op} ({b}.{word_name(w)} & {lit(1 << k)})"
    def read_one(m):
        inst, f, op = m.group(1), m.group(2), m.group(3)
        w, b = bit_of[f]
        counts["read"] += 1
        return f"({inst}.{word_name(w)} & {lit(1 << b)}) {op} {lit(1 << b)}"

    def bit0_value(m):
        inst, f = m.group(1), m.group(2)
        w, b = bit_of[f]
        if b != 0:
            return m.group(0)
        counts["read"] += 1
        return f"{inst}.{word_name(w)} & 1"
    text = re.sub(r"\s+", " ", text)                     # long bit names wrap lines
    text = re.sub(r" ?\. ?(?=[A-Za-z_])", ".", text)     # ... also between 'instance.' and the field name
    text = re.sub(INST + WORD + r"\.(" + NAMES + r") (==|!=) " + INST + WORD + r"\.(" + NAMES + r")\b", compare, text)
    text = re.sub(INST + WORD + r"\.(" + NAMES + r") (==|!=) 0\b", read, text)
    text = re.sub(INST + WORD + r"\.(" + NAMES + r") (==|!=) 1\b", read_one, text)
    text = re.sub(INST + WORD + r"\.(" + NAMES + r") = ([01]) ?;", write, text)
    text = re.sub(INST + r"\.(faults_\d+_to_\d+)\._0_2_", nested_piece, text)
    text = re.sub(INST + r"\._(\d+)_2_", lambda m: outer_piece(m) if int(m.group(2)) % 2 == 0 else m.group(0), text)
    text = re.sub(INST + WORD + r"\.(" + NAMES + r")\b(?! =[^=])", bit0_value, text)   # bit 0 read as a value
    text = re.sub(r"\(ushort\)" + INST + r"\.(faults_\d+_to_\d+)\b", r"\1.\2", text)  # a cast on a word piece
    counts["other"] = len(re.findall(INST + WORD + r"\.(?:" + NAMES + r")\b", text))
    return text


RUN = re.compile(r"((fault_(?:detected|registered|previous_pass)_cal\.faults_\d+_to_\d+)=\2([&|])(0x[0-9a-f]+|\d+);)"
                 r"((?:\2=\2\3(?:0x[0-9a-f]+|\d+);)+)")


def merge_runs(s):
    def merge(m):
        name, op = m.group(2), m.group(3)
        values = [int(m.group(4), 0)] + [int(v, 0) for v in re.findall(re.escape(name) + "=" + re.escape(name) +
                                                                       re.escape(op) + r"(0x[0-9a-f]+|\d+);", m.group(5))]
        acc = 0xffff if op == "&" else 0
        for v in values:
            acc = acc & v if op == "&" else acc | v
        counts["merged"] += len(values) - 1
        return f"{name}={name}{op}{lit(acc)};"
    prev = None
    while prev != s:
        prev, s = s, RUN.sub(merge, s)
    return s


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return "\n".join(l for l in text.split("\n") if not l.lstrip().startswith("//") or l.startswith("// Function:"))


def functions(text, merge):
    text = re.sub(r" ?(// Function: \S+ @ 0x[0-9a-f]+) ?", r"\n\1\n", text)   # the rewrite flattened the lines
    out = {}
    for m in re.finditer(r"^// Function: (\S+ @ 0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", text, re.S | re.M):
        body = re.sub(r"\s+", "", m.group(2))
        out[m.group(1)] = merge_runs(body) if merge else body
    return out


old = functions(strip_comments(open(old_cpp, errors="replace").read()), True)
new = functions(rewrite(strip_comments(open(new_cpp, errors="replace").read())), True)
diff = [f for f in old if f in new and old[f] != new[f]]
missing = sorted(set(old) ^ set(new))
print(f"rewritten: {counts['read']} bit tests, {counts['write']} bit writes, {counts['piece']} word pieces, "
      f"{counts['merged']} per-bit stores merged; bit names left in other forms: {counts['other']}")
print(f"functions: {len(old)} old, {len(new)} new, {len(missing)} not in both, {len(diff)} differ")
for f in diff[:show]:
    a, b = old[f], new[f]
    n = min(len(a), len(b))
    i = next((k for k in range(n) if a[k] != b[k]), n)
    print(f"DIFF {f}\n   old ...{a[max(0, i - 90):i + 130]}\n   new ...{b[max(0, i - 90):i + 130]}")
print("EQUIVALENT" if not diff and not missing else "NOT EQUIVALENT")
