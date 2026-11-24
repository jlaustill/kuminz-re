"""Round 88 stage D docs: the loaders now place the shifted dumps' bytes at their addresses. Idempotent; keeps line
endings. usage: apply_r88d_docs.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    if "\r\n" in t:
        old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


OLD = "`SetupMemoryMap.java` still loads this file at 0x8091C2."
NEW = ("`SetupMemoryMap.java` loads the file's bytes from offset 0x80 at 0x8092C2 and leaves 0x8091C2-0x8092C1 0 "
       "(`ScriptUtils.imageFromDumpWithGaps`, PR #53 round 88; it used to load the file at 0x8091C2, 0x80 too high).")
edit("firmware/CM550_J90350.00_analysis/README.md", OLD, NEW)
edit("firmware/CM550_J90350.00_analysis/docs/memory_map.md", OLD, NEW)
edit("firmware/CLAUDE.md",
     "      CM550's extended RAM dump has the same 0x80 shift (its README).\n",
     "      CM550's extended RAM dump has the same 0x80 shift (its README).\n"
     "    - The build puts the bytes back: `SetupMemoryMapCM848.java` builds the RAM block (0x3FA000-0x43FFFF) with\n"
     "      `ScriptUtils.imageFromDumpWithGaps`, leaving 0x40c200-0x40c27f 0, and `SetupMemoryMap.java` does the same for\n"
     "      CM550's extended RAM.\n")
edit("firmware/CLAUDE.md", "`cd firmware/script_tests && ./run_tests.sh` — 104 JUnit 5 tests",
     "`cd firmware/script_tests && ./run_tests.sh` — 109 JUnit 5 tests")
print("stage D docs applied")
