"""Round 25: append the round to the MEMORY.md PR #53 line."""
p = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
t = open(p).read()
old = "leads: named fault bits = user call, TouCAN A map, diag_clear_flags_t); task 046 leads"
new = ("leads: named fault bits = user call, TouCAN A map, diag_clear_flags_t) + round 25 (TRANSMISSION_SELECTED_GEAR "
       "SPN 524, the TouCAN A register map at 0x307080, the executive frame timing records e2m 12A6, the boot kernel "
       "response messages); task 046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(p, "w").write(t.replace(old, new))
print("memory line updated")
