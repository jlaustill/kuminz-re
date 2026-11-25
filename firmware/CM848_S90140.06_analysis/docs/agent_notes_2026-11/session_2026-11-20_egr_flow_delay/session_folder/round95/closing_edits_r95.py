"""Round 95 closing edits (each anchor must occur exactly once; idempotent):
- work/tasks/046: the round 95 entry (r95/task046_round95.md, SHA_C filled in) before '## Leads (not in this PR)';
- work/todo.md: the 046 line gains round 95;
- the PR body master (tmp/egr/pr_body.md): the summary's round range, the round 95 block (r95/pr_body_round95.md)
  before '## Test plan', the round 95 test plan lines, and an 'open after round 95' bullet.
usage: closing_edits_r95.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95"
SHA = {"SHA_C": "a6107f03"}
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


entry = fill(open(f"{W}/task046_round95.md").read())


def task(t):
    if "## Done, round 95 (" in t:
        return t
    E = "\r\n" if "\r\n" in t else "\n"
    anchor = E + "## Leads (not in this PR)" + E
    assert t.count(anchor) == 1
    return t.replace(anchor, E + entry.rstrip("\n").replace("\n", E) + E + anchor)


edit(os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md"), task)


def todo(t):
    old = ("every 2D lookup record typed - open: the task 046 leads")
    new = ("every 2D lookup record typed; round 95: CM848's task sets by schedule slot, the MPC555 register blocks against the "
           "manual (the register stage runs again), CM550's last 0x30000-0x34fff placeholders and every 1-D lookup record - "
           "open: the task 046 leads")
    if new in t:
        return t
    assert t.count(old) == 1
    return t.replace(old, new)


edit(os.path.join(repo, "work/todo.md"), todo)
PB = "/home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md"
block = fill(open(f"{W}/pr_body_round95.md").read()).rstrip("\n")
TESTS = """- [x] Round 95: C (the round 95 workflow): both verify DETERMINISTIC; CM550 705 -> 706 functions (0x1fe84) and CM848
  1968 -> 1969 (0x29ecc); the token changes outside the map are typing effects; no function's unaff_ / extraout_ / in_
  / CONCAT count went up; pieces equal in both; local rows 'Skipped: 0'; every new name renders.
- [x] Round 95: B (the register blocks): both verify DETERMINISTIC; no SCRIPT ERROR; the register stage logs Applied 1
  / Skipped 251 named / 36 inside typed data / Failed 0; CM848 changes outside the map only in local declaration order;
  CM550 byte-identical apart from the Generated line.
- [x] Round 95: A (the task sets): CM848 verify DETERMINISTIC; label-only (0 unmapped tokens); statement counts equal.
"""
OPEN = ("- **Open after round 95** (task 046): CM550's J1939 builders that render as `&LAB_...` in the scheduler calls "
        "(no function yet), the boot kernel's CMF step tables named `qadc_*` (0x3fdbb2-0x3fdc1e), the oil change "
        "monitor's boot / application time-shared record 0x3fee34, the QADC CCW tables as arrays, and spelled-out "
        "peripheral type names.\n")


def body(t):
    if "**Round 95.**" not in t:
        assert t.count("\n## Test plan\n") == 1
        t = t.replace("\n## Test plan\n", "\n" + block + "\n\n## Test plan\n")
    if "- [x] Round 95: C" not in t:
        anchor = "- [x] Round 94: F"
        assert t.count(anchor) == 1
        t = t.replace(anchor, TESTS + anchor)
    if "**Open after round 95**" not in t:
        anchor = "## Still open (task 046)\n\n"
        assert t.count(anchor) == 1
        t = t.replace(anchor, anchor + OPEN)
    old = "**Beyond CM848 (rounds 72-94):**"
    if old in t:
        t = t.replace(old, "**Beyond CM848 (rounds 72-95):**")
    return t


edit(PB, body)
print("edited:", *done, sep="\n  ")
