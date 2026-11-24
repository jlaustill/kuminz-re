"""Round 87 stage A (CM550 + CM848): the round 85-86 leads audit (workflow wf_4fa274fc-2d1; 5 investigators, 5 skeptics).
Applies the accepted / amended changes of the twin, CAN chip select 5, speed and restart groups (the EMA group is a
later stage) plus the CM848 half of the 0xc80c twin that the skeptic found (0x26f78 emptyStubFunction4). Plate
comments come from the evidence-backed reasons, with the audit's framing removed. Idempotent; keeps line endings.
usage: apply_r87a.py <repo> <final_changes.tsv> <map550.csv> <map848.csv>"""
import os
import re
import sys

repo, tsv, map550, map848 = os.path.abspath(sys.argv[1]), *sys.argv[2:5]
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
R = "PR #53 round 87"
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]
changes.append(["twins", "CM848", "function", "0x00026f78", "emptyStubFunction4", "ignoreCanTransmitInterrupt", "", "manual",
                "The empty transmit-complete hook (a bare blr): cm848_handleCanMailboxTransmitComplete calls it for every "
                "mailbox except the one whose transmit sends the next queued J1939 frame - the same step as CM550 0x1e056 "
                "and its hook 0xc80c."])
TWIN_OF = {}
by_name = {}
for c in changes:
    by_name.setdefault((c[0], c[5]), []).append(c)
for (group, final), cs in by_name.items():
    fws = {c[1] for c in cs if c[2] == "function"}
    if fws == {"CM550", "CM848"}:
        a550 = next(c[3] for c in cs if c[1] == "CM550")
        a848 = next(c[3] for c in cs if c[1] == "CM848")
        TWIN_OF[("CM550", a550)] = f"CM848 0x{int(a848, 16):x}"
        TWIN_OF[("CM848", a848)] = f"CM550 0x{int(a550, 16):x}"
# the amended CS4 / CS5 hook: the skeptic made it a twin
TWIN_OF[("CM550", "0x0000c80c")] = "CM848 0x26f78"
TWIN_OF[("CM848", "0x00026f78")] = "CM550 0xc80c"


def clean(reason):
    r = " ".join(reason.split())
    r = re.sub(r"^ASKED ITEM( \([^)]*\))?[.:] ", "", r)
    r = re.sub(r"^BEYOND THE ASKED LIST: [^.]*\. ", "", r)
    r = re.sub(r"^(TWIN of CM848 0x[0-9a-f]+\.|Twin of CM848 0x[0-9a-f]+ [^.]*\.|The CM848 half of the [^.:]*[.:]) ?", "", r)
    sentences = [s for s in re.split(r"(?<=[.)]) (?=[A-Z(])", r) if "APPLY" not in s and "falls back" not in s
                 and "ASKED" not in s and not s.startswith("If a reviewer")]
    out = ""
    for s in sentences:
        if len(out) + len(s) > 380 and out:
            break
        out = (out + " " + s).strip()
    return out


maps = {"CM550": [], "CM848": []}
for group, fw, kind, address, current, final, final_type, verdict, reason in changes:
    out_dir = os.path.join(repo, DIRS[fw])
    twin = TWIN_OF.get((fw, address))
    note = f"(was {current}; {R}" + (f"; the twin of {twin}: one shared name)" if twin else ")")
    if kind == "function":
        path = os.path.join(out_dir, "function_renames.csv")
        s = open(path, newline="").read()
        if f"\n{address},{final}," in s:
            continue
        m = re.search(rf"^{address},{re.escape(current)}(,[^\r\n]*)?$", s, re.M)
        assert m, (fw, address, current)
        old_comment = (m.group(1) or "")[1:]
        comment = f"{old_comment} | {note}" if old_comment else f"{clean(reason)} {note}"
        s = s[:m.start()] + f"{address},{final},{comment}" + s[m.end():]
        open(path, "w", newline="").write(s)
        maps[fw].append((address, final, current))
    else:
        path = os.path.join(out_dir, "global_variables.csv")
        s = open(path, newline="").read()
        eol = "\r\n" if "\r\n" in s else "\n"
        if f"{eol}{address},{final}," in s:
            continue
        m = re.search(rf"^{address},([^,\r\n]*),([^,\r\n]*),?([^\r\n]*)$", s, re.M)
        if m:
            old_comment = m.group(3)
            comment = f"{clean(reason)} {note}" if not old_comment else f"{old_comment} | {clean(reason)} {note}"
            s = s[:m.start()] + f"{address},{final},{final_type},{comment}" + s[m.end():]
        else:
            lines = s.split(eol)
            row = f"{address},{final},{final_type},{clean(reason)} {note}"
            for i, l in enumerate(lines):
                if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
                    lines.insert(i, row)
                    break
            s = eol.join(lines)
        open(path, "w", newline="").write(s)
        maps[fw].append((address, final, current))
for fw, path in (("CM550", map550), ("CM848", map848)):
    with open(path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for address, final, current in maps[fw]:
            fh.write(f"{address},{final},{current},function,1\n")
# function_definitions.csv name columns follow the renames
for fw in ("CM550", "CM848"):
    path = os.path.join(repo, DIRS[fw], "function_definitions.csv")
    d = open(path, newline="").read()
    for c in changes:
        if c[1] == fw and c[2] == "function":
            d = re.sub(rf"^({c[3]},){re.escape(c[4])},", rf"\g<1>{c[5]},", d, flags=re.M)
            short = re.sub(r"^(cm848_|cm550_|mc68k_|vp44_)", "", c[4])
            d = re.sub(rf"^({c[3]},){re.escape(short)},", rf"\g<1>{c[5]},", d, flags=re.M)
    open(path, "w", newline="").write(d)
print(f"round 87 stage A applied: CM550 {len(maps['CM550'])}, CM848 {len(maps['CM848'])}")
