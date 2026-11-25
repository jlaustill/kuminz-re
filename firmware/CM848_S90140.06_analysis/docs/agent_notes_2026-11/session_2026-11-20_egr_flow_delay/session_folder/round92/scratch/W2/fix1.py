"""One-off exact replacements in build_result.py (each must match exactly once)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W2/build_result.py"
s = open(p).read()
pairs = [
    ("w8 = channel_word(W8_CHANNELS, 112)", "w8 = channel_word(W8_CHANNELS, 128)"),
    ("it has no direct reader, so CM848 has no", "it has no direct reader; so CM848 has no"),
    ("0x163be (andi.w #2", "0x16396 (andi.w #2"),
    ("0x16396 (andi.w #4", "0x163be (andi.w #4"),
    ("0x16396 #4 and 0x163be #2", "0x16396 #2 and 0x163be #4"),
    ("15 reads (move.w + andi):", "12 absolute reads (move.w + andi; the .cpp shows 15 tests because two pairs of "
                                  "overlapping function entries share code):"),
]
for old, new in pairs:
    assert s.count(old) == 1, (old, s.count(old))
    s = s.replace(old, new)
open(p, "w").write(s)
print("ok")
