"""Remove the blocks that apply_r87c_closing.py's second run duplicated (its guard skipped an edit only when the old
text was gone, but three edits keep the old text inside the new one). Each block must occur exactly twice; the
second copy goes. usage: dedupe_r87c.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")


def drop_second(path, start, end):
    """Delete the second copy of the block that starts with `start` and ends before `end`."""
    t = open(path).read()
    first = t.find(start)
    second = t.find(start, first + 1)
    if second == -1:
        return 0
    stop = t.find(end, second)
    assert stop != -1
    block = t[second:stop]
    assert t[first:first + len(block)] == block, "the copies differ"
    open(path, "w").write(t[:second] + t[stop:])
    return 1


n = 0
n += drop_second(pr, "- [x] Round 87: C: ", "- [x] Round 87: B: ")
n += drop_second(T, "- **Stage C (542184f2), from an advisor review of stages A-B:**", "- **firmware/CLAUDE.md:** stage A")
n += drop_second(T, "  - `emptyStubFunction2` / `emptyStubFunction3` are shared names", "\n## Leads (not in this PR)")
print(n, "duplicates removed")
