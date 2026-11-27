"""Round 42 proof: the fault status record struct. For each given function both bodies go to one canonical form:
old (&fault_status_array)[i] / (&fault_status_array)[i * 3] -> FS.flags, *(ushort *)((int)&fault_status_word_array + i)
-> FS.status_word, its address -> &FS.status_word, &fault_status_array -> &FS; new
(&fault_status_records_cal)[i].flags / .status_word -> FS.flags / FS.status_word, &fault_status_records_cal -> &FS.
Then casts dropped, the index set-up (a temporary assigned temp x 3 arithmetic) dropped, temps anonymized, statements
compared. Proves field identity and statement structure, not the index (it is dropped).
usage: prove_status_records.py <old cpp> <new cpp> <function>..."""
import difflib
import re
import sys

old_cpp, new_cpp, names = sys.argv[1], sys.argv[2], sys.argv[3:]


def body(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    s = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    return re.sub(r"\s+", " ", s)


def close(s, i):
    pair = {"(": ")", "[": "]"}
    stack = []
    for k in range(i, len(s)):
        c = s[k]
        if c in pair:
            stack.append(pair[c])
        elif stack and c == stack[-1]:
            stack.pop()
            if not stack:
                return k + 1
    raise ValueError(s[i:i + 80])


def canon_old(s):
    while True:
        m = re.search(r"\(&fault_status_array\)\s?\[", s)
        if not m:
            break
        s = s[:m.start()] + "FS.flags" + s[close(s, m.end() - 1):]
    while True:
        m = re.search(r"\*\(ushort \*\)\(\(int\)&fault_status_word_array \+ ", s)
        if not m:
            break
        e = close(s, m.start() + len("*(ushort *)"))
        s = s[:m.start()] + "FS.status_word" + s[e:]
    while True:
        m = re.search(r"\(ushort \*\)\(\(int\)&fault_status_word_array \+ ", s)
        if not m:
            break
        e = close(s, m.start() + len("(ushort *)"))
        s = s[:m.start()] + "&FS.status_word" + s[e:]
    for base in set(re.findall(r"(\w+) = &fault_status_array;", s)):
        s = s.replace(f"{base} = &fault_status_array;", "")
        s = re.sub(r"\*\(ushort \*\)\(" + base + r" \+ [^;()]*?\+ 1\)", "FS.status_word", s)
        s = re.sub(r"\(ushort \*\)\(" + base + r" \+ [^;()]*?\+ 1\)", "&FS.status_word", s)
        while True:
            m = re.search(r"\b" + base + r"\s?\[", s)
            if not m:
                break
            s = s[:m.start()] + "FS.flags" + s[close(s, m.end() - 1):]
    return s.replace("&fault_status_array", "&FS")


def canon_new(s):
    while True:
        m = re.search(r"\(&fault_status_records_cal\)\s?\[", s)
        if not m:
            break
        s = s[:m.start()] + "FS" + s[close(s, m.end() - 1):]
    s = re.sub(r"FS\s?\.\s?", "FS.", s)
    for base in set(re.findall(r"(\w+) = &fault_status_records_cal;", s)):
        s = s.replace(f"{base} = &fault_status_records_cal;", "")
        while True:
            m = re.search(r"\(&" + base + r"->(flags|status_word)\)\s?\[", s)
            if not m:
                break
            s = s[:m.start()] + "FS." + m.group(1) + s[close(s, m.end() - 1):]
        s = re.sub(r"\(&" + base + r"->status_word \+ [^;()]*\)", "&FS.status_word", s)
        while True:
            m = re.search(r"\b" + base + r"\s?\[", s)
            if not m:
                break
            s = s[:m.start()] + "FS" + s[close(s, m.end() - 1):]
        s = re.sub(r"\b" + base + r"->", "FS.", s)
    s = re.sub(r"FS\s?\.\s?", "FS.", s)
    s = s.replace("&fault_status_records_cal", "&FS")
    return s


TEMP = re.compile(r"\b(?:[a-z]{1,3}Var\d+|[a-z]{1,2}Stack_[0-9a-f]+)\b")


def common(s):
    s = re.sub(r"\((?:u?int|u?short|word|byte|char|ushort \*|byte \*|fault_status_record_t \*)\)", "", s)
    s = re.sub(r"&FS\.flags", "&FS", s)
    s = re.sub(r"(?<=[{;}]) ?(?:const )?[A-Za-z_][A-Za-z0-9_]* \**[A-Za-z_][A-Za-z0-9_.]*(?: \[\d+\])?;", "", s)
    st = [x.strip() for x in re.split(r"(?<=[;{}])", s) if x.strip() and x.strip() != ";"]
    out = []
    for x in st:
        if re.fullmatch(r"(?:[a-z]{1,3}Var\d+|param_\d+) = [^;]* \* 3;", x) and "FS" not in x:
            continue
        x = re.sub(r"\(([a-z]{1,3}Var\d+) = \(([^()]*)\) \* 3,", r"(\1 = \2,", x)
        x = re.sub(r"\(\s*([a-z]{1,3}Var\d+) = [a-z]{1,3}Var\d+ \* 3\s*,\s*", "(", x)
        x = TEMP.sub("T", x)
        for a, b in ((r"\s*,\s*", ","), (r"\s+\)", ")"), (r"\(\s+", "("), (r"\s+\]", "]"), (r"\s+;", ";"),
                     (r"\+ -1\b", "- 1"), (r" +", " ")):
            x = re.sub(a, b, x)
        out.append(x)
    return out


total = 0
for n in names:
    a, b = common(canon_old(body(old_cpp, n))), common(canon_new(body(new_cpp, n)))
    d = [x for x in difflib.unified_diff(a, b, "old", "new", n=0, lineterm="") if x[:1] in "+-" and
         x[:3] not in ("---", "+++")]
    total += len(d)
    print(f"===== {n}: {len(d)} differing ({len(a)} / {len(b)} statements)")
    for x in d[:6]:
        print("  " + x[:180])
print("total differing", total)
