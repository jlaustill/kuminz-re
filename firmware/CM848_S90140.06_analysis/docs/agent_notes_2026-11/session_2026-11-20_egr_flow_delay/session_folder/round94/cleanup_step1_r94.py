"""Round 94 task #41, step 1 (CSV edits; a build follows to read the raw auto-names):
- every local_variables.csv row of the six functions whose rows no longer match (the build log's 'Variable X not
  found' warnings) is moved to r94/cleanup_local_rows_r94.csv (CM550 clearWorkingRam / unscrambleSecurityKey; CM848
  cm848_validateBootSecurityKey / mpc555_keyOnStateMachine / cm848_copyBootKernelToRam /
  mpc555_generateSerialChallenge), so the next build shows each body's own auto-names (rows match those, not the
  names after other rows applied);
- CM550: the 22 global rows that start inside another typed row and have no reference of their own (0 renders; the
  wide row's accesses are whole: sub.l / add.l on 0x80d03e, move.l on 0x80dca2; the struct instances 0x803036 /
  0x80cc4e already cover the field rows) are removed.
The name sync is a separate script (sync_definition_names_r94.py). Idempotent. usage: cleanup_step1_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
OUT = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/cleanup_local_rows_r94.csv"
FUNCTIONS = {"CM550": {0x2e9ac, 0x2fbd8}, "CM848": set()}
CM848_NAMES = {"cm848_validateBootSecurityKey", "mpc555_keyOnStateMachine", "cm848_copyBootKernelToRam",
               "mpc555_generateSerialChallenge"}
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
OVERLAP_ROWS = [0x800f69, 0x803037, 0x803038, 0x803039, 0x80303a, 0x80303e, 0x80303f, 0x803040, 0x803041, 0x803042,
                0x803043, 0x80cc50, 0x80cc52, 0x80cc54, 0x80cc56, 0x80cc58, 0x80cc5a, 0x80cc5e, 0x80d040, 0x80d40f,
                0x80dc9b, 0x80dca5]
saved = []
for fw, d in DIRS.items():
    path = os.path.join(repo, d, "local_variables.csv")
    text = open(path, newline="").read()
    E = "\r\n" if "\r\n" in text else "\n"
    kept = []
    for line in text.split(E):
        p = line.split(",")
        if line.startswith("0x") and (int(p[0], 16) in FUNCTIONS[fw] or (fw == "CM848" and p[1] in CM848_NAMES)):
            saved.append(f"{fw},{line}")
            continue
        kept.append(line)
    open(path, "w", newline="").write(E.join(kept))
if saved:          # a second run finds nothing to move and keeps the first run's file
    open(OUT, "w").write("firmware,function_address,function_name,old_name,new_name,type,comment\n" + "\n".join(saved) + "\n")
print(f"local rows set aside: {len(saved)} -> {OUT}")
path = os.path.join(repo, DIRS["CM550"], "global_variables.csv")
text = open(path, newline="").read()
E = "\r\n" if "\r\n" in text else "\n"
removed, kept = [], []
for line in text.split(E):
    if line.startswith("0x") and int(line.split(",")[0], 16) in OVERLAP_ROWS:
        removed.append(line.split(",")[0] + " " + line.split(",")[1])
        continue
    kept.append(line)
open(path, "w", newline="").write(E.join(kept))
print(f"CM550 global rows removed: {len(removed)}")
