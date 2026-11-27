"""Round 86 stage A rows (CM550 function_definitions.csv) for the stack parameter layout. Idempotent.
usage: apply_r86a_rows.py <repo> <proposed_rows.csv>
- The round 85 fix design's proposed rows (research/fix-design/proposed_rows.csv): wave 0 replaces the parameter rows of
  the functions the 2-byte layout would otherwise misplace (return rows kept); wave 1 adds three new prototypes. Each
  row's comment cites the load that fixes its width and offset.
- Applied with: the function name from function_renames.csv (the current name); two names corrected (0x142d4's
  calc_mode is not a mode - it is added to 0x80052C and subtracted from the lookup result - so lookup_result_offset;
  0x1cb76's rpm_index is stored to the tables' throttle input words, so throttle_input); the history notes as PR #53
  round 86; the phantom 0x32244 row deleted (its body reads no stack argument and its caller pushes nothing);
  0x34bf8's parameter named tick_count like its twin's."""
import csv
import io
import os
import re
import sys

repo, proposed_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
D5, F5 = os.path.join(O5, "function_definitions.csv"), os.path.join(O5, "function_renames.csv")
R = "PR #53 round 86"

names = {}
for line in open(F5, newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if p[0].startswith("0x") and len(p) > 1:
        names[p[0].lower()] = p[1]

proposed = {}
order = []
for r in csv.reader(l for l in open(proposed_path, newline="") if l.strip() and not l.startswith("#")):
    if not r or not r[0].startswith("0x"):
        continue
    address = r[0].lower()
    if address not in proposed:
        proposed[address] = []
        order.append(address)
    proposed[address].append(r)

RENAMED = {("0x000142d4", "1"): ("lookup_result_offset", "calc_mode - not a mode"),
           ("0x0001cb76", "1"): ("throttle_input", "rpm_index")}


def tidy(comment, address, index):
    c = comment.replace(", ", "; ").replace(",", ";")
    c = re.sub(r"\s*\(?new - name to review; round 85\)?", f" (new; {R})", c)
    c = re.sub(r"\(name to review\)\s*", "", c)
    c = c.replace("name to review; ", "").replace("; the name needs a review", "")
    c = re.sub(r"round 85\)", f"{R})", c)
    if (address, index) in RENAMED:
        c = re.sub(r"\(was [^)]*\)", "", c).strip().replace("; not a mode", "")
        c = f"{c} (was {RENAMED[(address, index)][1]}; {R})"
    return c.strip()


text = open(D5, newline="").read()
eol = "\r\n" if "\r\n" in text else "\n"
lines = text.split(eol)
out = []
placed = set()
for line in lines:
    p = line.split(",", 5)
    address = p[0].lower() if p and p[0].startswith("0x") else None
    if address == "0x00032244" and len(p) > 2 and p[2] != "return":
        continue                                     # the phantom dtc_count row
    if address in proposed and len(p) > 2 and p[2] != "return":
        if address not in placed:                    # replace this function's parameter rows in place, once
            placed.add(address)
            for r in proposed[address]:
                if r[2] == "return":
                    continue
                name = RENAMED.get((address, r[2]), (r[3], None))[0]
                out.append(",".join([r[0], names.get(address, r[1]), r[2], name, r[4],
                                     tidy(r[5] if len(r) > 5 else "", address, r[2])]))
        continue
    if address == "0x00034bf8" and len(p) > 3 and p[3] == "timer_ticks":
        p[3] = "tick_count"
        line = ",".join(p)
    out.append(line)
new_functions = [a for a in order if a not in placed]
if new_functions and f"# Stack parameter layout: new prototypes ({R})" not in text:
    while out and out[-1] == "":
        out.pop()
    out.append(f"# Stack parameter layout: new prototypes ({R})")
    for address in new_functions:
        for r in proposed[address]:
            out.append(",".join([r[0], names.get(address, r[1]), r[2], RENAMED.get((address, r[2]), (r[3], None))[0],
                                 r[4], tidy(r[5] if len(r) > 5 else "", address, r[2])]))
    out.append("")
result = eol.join(out)
header_note = ("# CM550 parameters are placed by stack_parameter_layout.csv (PR #53 round 86): give every parameter a row "
               "(a function with a gap is skipped) and declare the width the callee loads (move.w -> ushort; move.b at "
               "the odd byte -> byte; move.l / movea.l -> a 4-byte type).")
if header_note not in result:
    result = result.replace("# Defines parameter names and types for improved decompilation readability",
                            "# Defines parameter names and types for improved decompilation readability" + eol + header_note, 1)
if result != text:
    open(D5, "w", newline="").write(result)
print(f"replaced {len(placed)} functions' parameter rows, added {len(new_functions)} new prototypes")
