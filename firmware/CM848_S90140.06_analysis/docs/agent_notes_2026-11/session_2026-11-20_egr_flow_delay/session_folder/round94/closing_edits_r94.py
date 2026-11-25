"""Round 94 closing edits (each anchor must occur exactly once; idempotent):
- work/tasks/046: the round 94 entry (r94/task046_round94.md, commit hashes filled in) before '## Leads (not in this PR)';
- work/todo.md: the 046 line gains round 94;
- the PR body master (tmp/egr/pr_body.md): the summary's round range, the round 94 block (r94/pr_body_round94.md)
  before '## Test plan', the round 94 test plan lines, and an 'open after round 94' bullet;
- the CM550 README's counts (as round 93's update_cm550_readme_r93.py, for round 94).
usage: closing_edits_r94.py <repo>"""
import os
import re
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94"
SHA = {"SHA_E": "2117349b", "SHA_F": "94670245"}
done = []


def fill(text):
    for k, v in SHA.items():
        text = text.replace(k, v)
    return text


def edit(path, fn):
    text = open(path, newline="").read()
    new = fn(text)
    if new != text:
        open(path, "w", newline="").write(new)
        done.append(path)


# 1. task 046
entry = fill(open(f"{W}/task046_round94.md").read())
entry = entry.replace(
    "  not uses. Mixed uses, or none, take the Calterm S/U flag.\n",
    "  not uses. Mixed uses, or none, take the Calterm S/U flag. Result: 3 rows word -> i16, 5 rows i16 -> word, and\n"
    "  active_fault_list_count i16 -> word (4 signed and 2 unsigned uses).\n")


def task(t):
    if "## Done, round 94 (" in t:
        return t
    E = "\r\n" if "\r\n" in t else "\n"
    anchor = E + "## Leads (not in this PR)" + E
    assert t.count(anchor) == 1
    return t.replace(anchor, E + entry.rstrip("\n").replace("\n", E) + E + anchor)


edit(os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md"), task)


# 2. todo
def todo(t):
    old = "round 93: 52 mid-function rows removed, freeze frame struct, task sets by schedule slot, 1943 rows typed - open: the task 046 leads"
    new = ("round 93: 52 mid-function rows removed, freeze frame struct, task sets by schedule slot, 1943 rows typed; round 94: "
           "the judged naming batches (110 CM550 functions, 33 twins, CM848's 17 bare 'protection' / 'init' names), CM550's "
           "0x148a-byte EEPROM image and _cal window, every 2D lookup record typed - open: the task 046 leads")
    if new in t:
        return t
    assert t.count(old) == 1
    return t.replace(old, new)


edit(os.path.join(repo, "work/todo.md"), todo)
# 3. the PR body master
PB = "/home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md"
block = fill(open(f"{W}/pr_body_round94.md").read()).rstrip("\n")
TESTS = """- [x] Round 94: F (cleanups): both verify DETERMINISTIC; `prove_r94f.py`: only the six functions' local names change
  (CM848 also swaps two declarations in `cm848_checkPciMessageTimeouts`); every other function is byte-identical; the
  build logs show 'Skipped: 0' local rows in both.
- [x] Round 94: E (the leads batches): both verify DETERMINISTIC; CM550 704 -> 705 functions (the new 0x33d38 row);
  the token changes outside the map are typing effects (classified); pieces 494 = 494; CM848 changes outside the map
  only in the duty cycle axes; no old name left in the code.
- [x] Round 94: D (the EEPROM image): both verify DETERMINISTIC; label-only (0 unmapped tokens); `_cal` audit 0 hard /
  0 soft; kuminz-cli and clip-core build and clip-core's test passes.
- [x] Round 94: C (round 93's batches): both verify DETERMINISTIC; CM848 label-only; CM550 typing effects classified,
  five statement count changes explained, pieces 496 -> 494 (the two new are the expected low-word reads).
- [x] Round 94: B (the throttle struct): CM550 verify DETERMINISTIC; every token change in the map; statement counts
  equal.
- [x] Round 94: A (the sign rule): CM550 verify DETERMINISTIC; 13 functions changed by casts only; statement counts
  equal.
"""
OPEN = ("- **Open after round 94** (task 046): prototype rows for `scheduleJ1939PeriodicMessage` and `cm550_tableLookup2D`, "
        "the 1-D `table_interp_args_t` records, five record-shaped RAM blocks with no reader in the dumped ROM (they need the "
        "0x40000+ dump), CM848's other task sets by slot, and a CM550 EEPROM re-dump at 0x148a bytes.\n")


def body(t):
    if "**Round 94.**" not in t:
        assert t.count("\n## Test plan\n") == 1
        t = t.replace("\n## Test plan\n", "\n" + block + "\n\n## Test plan\n")
    if "- [x] Round 94: F" not in t:
        anchor = "- [x] Round 93: typing:"
        assert t.count(anchor) == 1
        t = t.replace(anchor, TESTS + anchor)
    if "**Open after round 94**" not in t:
        anchor = "## Still open (task 046)\n\n"
        assert t.count(anchor) == 1
        t = t.replace(anchor, anchor + OPEN)
    old = "**Beyond CM848 (rounds 72-93):**"
    if old in t:
        t = t.replace(old, "**Beyond CM848 (rounds 72-94):**")
    return t


edit(PB, body)
# 4. the CM550 README counts
script = open("/home/linux/.claude/jobs/374b0424/tmp/w15/r93/update_cm550_readme_r93.py").read()
script = script.replace("Counted from the CSVs for PR #53 round 93 (2026-11-24):", "Counted from the CSVs for PR #53 round 94 (2026-11-25):")
open(f"{W}/update_cm550_readme_r94.py", "w").write(script.replace("Round 93 closing", "Round 94 closing (from round 93's script)"))
out = subprocess.run([sys.executable, f"{W}/update_cm550_readme_r94.py", repo], capture_output=True, text=True)
print(out.stdout.strip() or out.stderr.strip())
print("edited:", done)
