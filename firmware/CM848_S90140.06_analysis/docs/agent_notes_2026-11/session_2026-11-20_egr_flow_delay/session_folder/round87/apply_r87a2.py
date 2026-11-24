"""Round 87 stage A2: tidy the generated comments and rename one CM848 function the twin rename would make ambiguous.
Idempotent; keeps line endings. usage: apply_r87a2.py <repo> <map550.csv> <map848.csv>
- Drop sentences about the old render ("No row; it renders as DAT_...") and audit framing ("the CM848 row is the next
  change", "One thing for the applier") from the stage A comments; give four twins a description that starts with what
  the function does.
- CM848 0x509b74 cm848_copyROMCalibrationToRAM copies the default J1939 NAMEs (engine / retarder, 4 entries each) and
  source addresses into the working ones - no calibration; next to the twin name copyCalibrationFromRomToRam it would
  mislead, so it becomes cm848_loadDefaultJ1939NamesAndSourceAddresses.
- The markdown docs and firmware/CLAUDE.md that name a renamed CM848 function get the new name (whole-word matches)."""
import os
import re
import sys

repo, map550, map848 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
F = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
     "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
R = "PR #53 round 87"

for fw in ("CM550", "CM848"):
    for name in ("function_renames.csv", "global_variables.csv"):
        p = os.path.join(F[fw], name)
        s = open(p, newline="").read()
        s2 = re.sub(r"No row( today)?; it renders as _?DAT_[0-9a-f]+\. ", "", s)
        s2 = s2.replace(" Shared unprefixed name; the CM848 row is the next change.", "")
        s2 = re.sub(r" If the 0x[0-9a-f]+ [^.]*\.", "", s2)
        s2 = re.sub(r" One thing for the applier: [^.]*\.( [^.(]*\.)?", "", s2)
        if s2 != s:
            open(p, "w", newline="").write(s2)

REWRITE = {
    ("CM550", "0x0001192a"): "Software restart into the boot ROM without a hardware reset (the twin of CM848 0x216fc): only in "
        "engine_state 1. It polls the EEPROM write queue around mc68k_delayTimeBaseTicksWithWatchdogService2 waits (500 / "
        "250 / 50000 ticks) - acknowledges the request on the link its second argument names (0 the J1939 response "
        "frame - 1 the J1708 diagnostic message queue; CM848's case 2 is its SCI byte) - and jumps through the ROM vector "
        "at 0x8",
    ("CM550", "0x0001b876"): "The periodic interrupt timer's handler (the twin of CM848 0xc0a0): each interrupt runs one frame "
        "of the 40-phase executive and times it with the executive timing gatherer. It is not a loop",
    ("CM848", "0x0000c0a0"): "The periodic interrupt timer's dispatched callback (the twin of CM550 0x1b876; the SIU interrupt "
        "dispatcher calls it from table entry 15): it acknowledges the PIT itself (PISCR) and runs one frame of the "
        "40-phase executive. It is not a loop",
    ("CM848", "0x0004bd00"): "Copies the ROM calibration image (ROM 0x64aea) into its RAM copy 0x3feed0-0x40a046 dword by "
        "dword - once at start-up right after clearWorkingRam (the twin of CM550 0x117ec)",
}
for (fw, address), text in REWRITE.items():
    p = os.path.join(F[fw], "function_renames.csv")
    s = open(p, newline="").read()
    m = re.search(rf"^({address},[^,\r\n]+,)([^\r\n]*)$", s, re.M)
    assert m, (fw, address)
    note = re.search(r"\(was [^)]*\)\s*$", m.group(2))
    assert note, (fw, address, m.group(2)[-80:])
    new = f"{text} {note.group(0)}"
    if m.group(2) != new and not m.group(2).startswith(text):
        s = s[:m.start(2)] + new + s[m.end(2):]
        open(p, "w", newline="").write(s)

p = os.path.join(F["CM848"], "function_renames.csv")
s = open(p, newline="").read()
old = "0x00509b74,cm848_copyROMCalibrationToRAM"
new = ("0x00509b74,cm848_loadDefaultJ1939NamesAndSourceAddresses,Copies the default J1939 NAMEs into the working ones "
       "(j1939_default_engine_name -> j1939_engine_name and j1939_default_retarder_name -> j1939_engine_retarder_name - 4 "
       "entries each) and the default engine / retarder source addresses into j1939_source_address / "
       f"j1939_engine_retarder_source_address - no calibration (was cm848_copyROMCalibrationToRAM; {R})")
if new.split(",")[1] not in s:
    m = re.search(rf"^{re.escape(old)}(,[^\r\n]*)?$", s, re.M)
    assert m
    s = s[:m.start()] + new + s[m.end():]
    open(p, "w", newline="").write(s)
with open(map848, "a") as fh:
    fh.write("0x00509b74,cm848_loadDefaultJ1939NamesAndSourceAddresses,cm848_copyROMCalibrationToRAM,function,1\n")

renames = {}
for path in (map550, map848):
    for line in open(path):
        p_ = line.strip().split(",")
        if p_[0].startswith("0x"):
            renames[p_[2]] = p_[1]
DOCS = ["firmware/CLAUDE.md", "firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md",
        "firmware/CM848_S90140.06_analysis/docs/j1939_broadcast_investigation.md"]
for rel in DOCS:
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    t2 = t
    for old_name, new_name in renames.items():
        if old_name.startswith("cm848_") or old_name in ("main_loop", "emptyStubFunction4"):
            t2 = re.sub(rf"(?<![A-Za-z0-9_]){re.escape(old_name)}(?![A-Za-z0-9_])", new_name, t2)
    if t2 != t:
        open(p, "w", newline="").write(t2)
print("round 87 stage A2 applied")
