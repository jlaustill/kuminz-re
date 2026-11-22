"""Round 29: MEMORY.md (the PR #53 line) and the typing focus note."""
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
p = M + "MEMORY.md"
t = open(p).read()
t = t.replace("(cm848/egr-flow-delay-model, 161 commits)", "(cm848/egr-flow-delay-model, 163 commits)")
old = "mailbox writer prototypes restore a hidden frame argument); task 046 leads"
new = ("mailbox writer prototypes restore a hidden frame argument) + round 29 (the transfer case low-range detector = "
       "e2m 8C5F / 8C60, was engine_to_vehicle_speed_ratio_*; 9 fault bits named from their setters); task 046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
open(p, "w").write(t)
f = M + "typing_focus_2026_11.md"
note = ("  - Round 29 (2026-11-22, a peer relay): f13aca5 opposite_words.py (e2m min/max, high/low, enable/disable vs the "
        "row name; 29 hits, most were region-vs-check wording) found the transfer case low-range detector by N/V "
        "(e2m 8C5F / 8C60 Tcase NV; the engine_to_vehicle_speed_ratio_* family -> transfer_case_*, "
        "cm848_detectTransferCaseLowRange); 9 fault_<n> bits named from their setters (fault_n_evidence.py: 57-60 "
        "fuel pressure monitors, 308 engine_off_time_stuck_error = e2m Chry_Dat42 = PCI frame 0x42, 342 / 343 "
        "overspeed, 682 / 683 channel 101). Open: faults 22 / 23 / 179 / 180 / 101 / 410 / 524 / 110.\n")
if "Round 29 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("memory updated")
