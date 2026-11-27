"""Round 86 stage B (docs). Idempotent; keeps line endings. usage: apply_r86b_docs.py <repo>
- firmware/CLAUDE.md: two statements stage A made false - the test count (89 -> 104) and the return-only / gap rule,
  which CM550's stack parameter layout now handles by skipping the function with an Error.
- CM550 function_definitions.csv header: the storage hazard the fix design found - a local_variables.csv row that
  retypes a parameter of a placed function resizes its custom storage."""
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
    assert t.count(old) == 1, (rel, old[:60], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


edit("firmware/CLAUDE.md", "./run_tests.sh` — 89 JUnit 5 tests covering ScriptUtils and CsvCommentIndex.",
     "./run_tests.sh` — 104 JUnit 5 tests covering ScriptUtils and CsvCommentIndex.")
edit("firmware/CLAUDE.md",
     "a return-only row is auto-handled (import preserves Ghidra-recovered params, warns on count mismatch) but yields "
     "generic `param_N` names.",
     "a return-only row is auto-handled (import preserves Ghidra-recovered params, warns on count mismatch) but yields "
     "generic `param_N` names. Not on CM550: its `stack_parameter_layout.csv` (PR #53 round 86) places every parameter "
     "from its row, so the importer skips, with an Error, a function that has a return-only row with recovered params "
     "or a gap in its parameter rows.")
edit("firmware/CM550_J90350.00_analysis/output/function_definitions.csv",
     "move.l / movea.l -> a 4-byte type).",
     "move.l / movea.l -> a 4-byte type). Never retype one of these parameters in local_variables.csv: the export then "
     "resizes its custom storage.")
print("round 86 stage B docs applied")
