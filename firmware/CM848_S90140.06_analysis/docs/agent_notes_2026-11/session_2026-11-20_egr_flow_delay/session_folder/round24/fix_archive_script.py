"""Route the full CSV copies (pre_r24e_*.csv) of round 24 into the large-files tarball instead of the session folder."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r24/update_large_tar_r24.sh"
t = open(p).read()
old1 = "grep -vE '\\.cpp$|\\.log$|_dry|^o\\.txt$|^n\\.txt$'"
new1 = "grep -vE '\\.cpp$|\\.log$|_dry|^o\\.txt$|^n\\.txt$|^pre_r24e_'"
old2 = 'cp "$W"/r24/build_r24*.log "$W/largetar/"'
new2 = old2 + '\ncp "$W"/r24/pre_r24e_*.csv "$W/largetar/"'
if new1 not in t:
    assert t.count(old1) == 1, t.count(old1)
    t = t.replace(old1, new1)
if new2 not in t:
    assert t.count(old2) == 1
    t = t.replace(old2, new2)
open(p, "w").write(t)
print("archive script updated")
