"""Round 94 (read-only): the security hook's commit reviews for the given commits: the review start (the line that
names the fresh unreviewed sha) and the first commit-review verdict after it that belongs to this session.
usage: security_verdicts_r94.py <session id prefix> <sha prefix>..."""
import re
import sys

session, shas = sys.argv[1], sys.argv[2:]
lines = []
for path in ("/home/linux/.claude/security/log.txt.1", "/home/linux/.claude/security/log.txt"):
    try:
        lines += open(path, errors="replace").read().splitlines()
    except OSError:
        pass
for sha in shas:
    start = next((i for i, l in enumerate(lines) if "fresh unreviewed commit" in l and sha[:8] in l), None)
    if start is None:
        print(f"{sha}: no review start in the log")
        continue
    ts = lines[start][1:24]
    verdict = None
    for j in range(start + 1, min(len(lines), start + 4000)):
        l = lines[j]
        if l.find("Commit review:") >= 0 and not re.search(r"detected git commit|fresh unreviewed|sha\(s\) resolved|stdout had no", l):
            # the verdict line; the next 'Review usage: review=commit' names the session
            usage = next((lines[k] for k in range(j, min(len(lines), j + 5)) if "review=commit" in lines[k]), "")
            if session in usage or not usage:
                verdict = (l[1:24], l.split("Commit review:", 1)[1].strip())
                break
        if "fresh unreviewed commit" in l and sha[:8] not in l and session[:8] in l:
            break
    print(f"{sha}: review started {ts}; " + (f"verdict at {verdict[0]}: {verdict[1]}" if verdict else "no verdict found yet"))
