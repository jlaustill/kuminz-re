"""Round 89 stage A: clean round 88's generated comments and three stale script comments. Idempotent; keeps line
endings. usage: apply_r89a.py <repo>
- CM550 global_variables.csv: drop the "(frozen J90350.00.ghidra.cpp:N)" citations (line numbers of a scratch copy);
  "the frozen CM848 .cpp" -> "the CM848 decompilation"; engine_state's typing note (the skeptic's count: 33 compares).
- CM550 enums.csv: ENGINE_STATE_UNINITIALIZED and the J1939_DIAGNOSTIC_SERVICE rows read as descriptions.
- Scripts: read_engine_hours.sh / ScriptUtilsTest.java / audit_cal_suffixes.py name the round 87-88 names.
- Docs: the two dump notes say what the CLI requested (0x46000 bytes from 0x3FA000; 0x6E3E from 0x8091C2)."""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 88"


def load(rel):
    return open(os.path.join(repo, rel), newline="").read()


def save(rel, text):
    open(os.path.join(repo, rel), "w", newline="").write(text)


def edit(rel, old, new):
    t = load(rel)
    if "\r\n" in t:
        old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
    if new in t and old not in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    save(rel, t.replace(old, new))


G5 = "firmware/CM550_J90350.00_analysis/output/global_variables.csv"
t = load(G5)
t = re.sub(r" \(frozen J90350\.00\.ghidra\.cpp:\d+(?:-\d+)?\)", "", t)
t = t.replace("no reference in the frozen CM848 .cpp", "no reference in the CM848 decompilation")
t = re.sub(r"(^0x0080d0c8,engine_state,ENGINE_STATE,[^\n]*?) \| typed ENGINE_STATE: Type the word[^\n]*$",
           r"\1 | typed ENGINE_STATE (CM848's members): every compare and store in the dumped 256 KB uses only 1-8 - 33 "
           r"absolute cmpi.w #N,$80d0c8 (N = 1 / 2 / 3 / 5 / 6 / 7 / 8), 1 move.w #1 store, 2 copies and 13 "
           r"address-register users (" + R + ")", t, flags=re.M)
save(G5, t)

E5 = "firmware/CM550_J90350.00_analysis/output/enums.csv"
e = load(E5)
e = re.sub(r'^(ENGINE_STATE,0,ENGINE_STATE_UNINITIALIZED,)"New CM550 enum ENGINE_STATE, size 2, with CM848\'s member '
           r'names\. This member exists only for parity with CM848: no CM550 code in the dumped 256 KB compares with or '
           r'stores 0\. \(PR #53 round 88\)",',
           r"\1Zeroed RAM - a member for parity with CM848: no CM550 code in the dumped 256 KB compares engine_state with "
           r"0 or stores 0 (" + R + "),", e, flags=re.M)
e = re.sub(r"CM848's member name for service (\d+)\. ", r"Service \1 (CM848's member name). ", e)
save(E5, e)

edit("firmware/CM848_S90140.06_analysis/tools/read_engine_hours.sh", "(cm848_restartThroughBootRom)", "(restartThroughBootRom)")
t = load("firmware/script_tests/ScriptUtilsTest.java")
t2 = re.sub(r"(void pack_wordThenLong_longNotAligned\(\) \{\s+)// exponentialMovingAverage\b",
            r"\1// cm550_signedFirstOrderFilter", t)
assert t2 != t or "// cm550_signedFirstOrderFilter" in t
save("firmware/script_tests/ScriptUtilsTest.java", t2)
edit("firmware/scripts/audit_cal_suffixes.py", "(the twin of commitEepromMirrorToEeprom in CM848)",
     "(the counterpart of cm848_commitEepromMirrorToEeprom in CM848)")
edit("firmware/CLAUDE.md",
     "    - The cause: clip-core's `ECUReader::readMemoryService4ALarge` skipped a failed 128-byte chunk without padding.\n",
     "    - The cause: clip-core's `ECUReader::readMemoryService4ALarge` skipped a failed 128-byte chunk without padding\n"
     "      (kuminz-cli asks for `CM848_RAM_SIZE` 0x46000 bytes from 0x3FA000; the file holds 0x45F80).\n")
NOTE_OLD = "was read in 128-byte chunks from 0x8091C2, and the dump tool skipped"
NOTE_NEW = ("was read in 128-byte chunks from 0x8091C2 (kuminz-cli asks for 0x8091C2-0x80FFFF, 0x6E3E bytes), and the dump "
            "tool skipped")
for rel in ("firmware/CM550_J90350.00_analysis/README.md", "firmware/CM550_J90350.00_analysis/docs/memory_map.md"):
    edit(rel, NOTE_OLD, NOTE_NEW)
print("round 89 stage A applied")
