"""Round 30: MEMORY.md (the PR #53 line) and the typing focus note."""
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
p = M + "MEMORY.md"
t = open(p).read()
t = t.replace("(cm848/egr-flow-delay-model, 163 commits)", "(cm848/egr-flow-delay-model, 165 commits)")
old = "9 fault bits named from their setters); task 046 leads"
new = ("9 fault bits named from their setters) + round 30 (the watchdog fueling monitor = e2m 8A70 / 8B3B / 8B3D, was "
       "fuel_quantity_demand_monitor); task 046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
open(p, "w").write(t)
f = M + "typing_focus_2026_11.md"
note = ("  - Round 30 (2026-11-22, a peer relay): 82b5069 setter_name_scan.py (functions whose name shares no word with the "
        "fault bits they set) found the watchdog fueling monitor (fault 388): cm848_monitorWatchdogFueling + e2m 8A70 "
        "aligned by offset at 0x40894c (4 words match their code use) + 8B3B / 8B3D table. unit_domain_scan.py found "
        "only known e2m drift. Lead: the EC1 (PGN 65251) payload struct (28 bytes LE, 2 instances; xref_addr.py "
        "misses base-register accesses, so pilot-build it).\n")
if "Round 30 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("memory updated")
