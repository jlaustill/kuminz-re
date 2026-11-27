"""Round 94 tooling: derive apply_r94.py from round 93's apply_r93.py. The proposals were made against copies frozen
before round 93; since then the live CSVs gained round 93's changes. The new apply reconciles:
- R = round 94; overrides from overrides_r94.json;
- a function proposal for a row that round 93 removed (deleted_functions.csv, 'PR #53 round 93') is a reported skip,
  not a refusal;
- a global proposal for an address strictly inside a live row's span (a struct / array instance or a wider row) is a
  reported skip;
- the type: when the live row is no longer 'undefined', the live type is kept if the proposed type has the same width
  and is not more specific (an enum / struct of the same width replaces a plain integer); a different width keeps the
  live type and is reported. The name is applied either way.
usage: make_apply_r94.py <apply_r93.py> <apply_r94.py>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (old[:70], s.count(old))
    s = s.replace(old, new)


rep('R = "PR #53 round 93"', 'R = "PR #53 round 94"')
rep('"overrides_r93.json"', '"overrides_r94.json"')
rep('''report, problems, maps = [], [], {"CM550": [], "CM848": []}''',
    '''report, problems, maps = [], [], {"CM550": [], "CM848": []}
REMOVED = {}            # round 93 removed these function rows (mid-function rows): address -> its deletion entry
for fw in DIRS:
    for line in read(os.path.join(DIRS[fw], "deleted_functions.csv")).split("\\n"):
        if line.startswith("0x") and "PR #53 round 93" in line:
            REMOVED[(fw, norm(line.split(",")[0]))] = line.split(",", 1)[1][:120]
PRIMITIVE_WIDTH = {"byte": 1, "sbyte": 1, "char": 1, "uchar": 1, "bool": 1, "i8": 1, "undefined1": 1,
                   "word": 2, "short": 2, "ushort": 2, "i16": 2, "u16": 2, "undefined2": 2,
                   "dword": 4, "int": 4, "uint": 4, "long": 4, "ulong": 4, "i32": 4, "u32": 4, "pointer": 4, "undefined4": 4}
WIDTH = {}
for fw in DIRS:
    widths = dict(PRIMITIVE_WIDTH)
    for row in csv.reader(state[fw]["enums.csv"].splitlines()):
        if len(row) > 4 and not row[0].startswith("#") and row[4].strip().isdigit():
            widths[row[0]] = int(row[4])
    sizes = {}
    for row in csv.reader(state[fw]["structure_definitions.csv"].splitlines()):
        if len(row) > 4 and row[0] and not row[0].startswith("#") and row[0] != "struct_name" and row[4].strip().isdigit():
            sizes[row[0]] = sizes.get(row[0], 0) + int(row[4])
    widths.update(sizes)
    WIDTH[fw] = widths


def type_width(fw, typ):
    m = re.match(r"^([A-Za-z0-9_]+)\\s*(\\*)?\\s*(?:\\[(\\d+)\\])?$", typ.strip())
    if not m:
        return None
    if m.group(2):
        return 4 * int(m.group(3) or 1)
    w = WIDTH[fw].get(m.group(1))
    return None if w is None else w * int(m.group(3) or 1)


def spans(fw):
    """(start, end, name, type) of every live global row wider than one byte."""
    out = []
    for line in state[fw]["global_variables.csv"].split("\\n"):
        parts = line.split(",", 3)
        if len(parts) > 2 and parts[0].startswith("0x"):
            w = type_width(fw, parts[2])
            if w and w > 1:
                a = int(parts[0], 16)
                out.append((a, a + w, parts[1], parts[2]))
    return out''')
rep('''        m = function_row("CM550", a)
        if not m:
            problems.append(f"{b}: CM550 {a} has no function_renames.csv row")
            continue''',
    '''        m = function_row("CM550", a)
        if not m:
            if ("CM550", a) in REMOVED:
                report.append(f"{b} SKIP function {a} {f['current_name']} -> {new}: round 93 removed the row ({REMOVED[('CM550', a)]})")
            else:
                problems.append(f"{b}: CM550 {a} has no function_renames.csv row")
            continue''')
rep('''        lines = state[fw]["global_variables.csv"].split("\\n")
        idx = next((i for i, l in enumerate(lines) if l[:10].lower() == a and l[10:11] == ","), None)
        old, old_type, old_comment = "", "", ""
        if idx is not None:
            parts = lines[idx].split(",", 3)
            old, old_type, old_comment = parts[1], parts[2], (parts[3] if len(parts) > 3 else "")
        if idx is not None and old == new and old_type == typ:
            continue''',
    '''        inside = [sp for sp in spans(fw) if sp[0] < int(a, 16) < sp[1]]
        if inside:
            report.append(f"{b} SKIP global {fw} {a} {new}: inside the live row {inside[0][2]} ({inside[0][3]} at 0x{inside[0][0]:x})")
            continue
        lines = state[fw]["global_variables.csv"].split("\\n")
        idx = next((i for i, l in enumerate(lines) if l[:10].lower() == a and l[10:11] == ","), None)
        old, old_type, old_comment = "", "", ""
        if idx is not None:
            parts = lines[idx].split(",", 3)
            old, old_type, old_comment = parts[1], parts[2], (parts[3] if len(parts) > 3 else "")
        if idx is not None and old_type not in ("", "undefined") and old_type != typ:
            w_old, w_new = type_width(fw, old_type), type_width(fw, typ)
            specific = typ not in PRIMITIVE_WIDTH and old_type in PRIMITIVE_WIDTH
            if w_old is not None and w_old == w_new and specific:
                report.append(f"{b} TYPE {fw} {a}: {old_type} -> {typ} (same width, more specific)")
            else:
                report.append(f"{b} TYPE KEPT {fw} {a} {new}: live {old_type} (proposal {typ}{'' if w_old == w_new else ', a different width'})")
                typ = old_type
        if idx is not None and old == new and old_type == typ:
            continue''')
open(out, "w").write(s)
print("apply_r94.py written")
