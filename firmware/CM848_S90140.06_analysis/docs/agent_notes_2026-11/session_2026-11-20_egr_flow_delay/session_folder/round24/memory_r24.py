"""Round 24: the MEMORY.md PR #53 line's round 24 text (in progress -> done + leads)."""
p = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
t = open(p).read()
old = "in progress: the fault bit arrays e2m 1036, 4 struct shapes, TouCAN A registers)"
new = ("the 3 fault bit arrays as fault_bit_words_t e2m 1036, sensor slots 1-4 flat, the throttle dword split; leads: "
       "named fault bits = user call, TouCAN A map, diag_clear_flags_t)")
if new not in t:
    assert t.count(old) == 1
    open(p, "w").write(t.replace(old, new))
print("memory line updated")
