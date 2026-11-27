"""Round 97 stage F post-step: the apply's '# <type> (N bytes; PR #53 round 97)' header of each R5 struct becomes the
investigator's description (struct_headers_r97f.json) with the round tag. usage: struct_headers_r97f.py <repo>"""
import json
import os
import re
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/structure_definitions.csv")
headers = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/struct_headers_r97f.json"))
t = open(p, newline="").read()
for name, text in headers.items():
    pat = re.compile(rf"^# {re.escape(name)} \((\d+) bytes; PR #53 round 97\)(?=\r?$)", re.M)
    assert len(pat.findall(t)) == 1, name
    text = " ".join(text.split())
    t = pat.sub(lambda m: f"# {name}: {text} (PR #53 round 97)", t)
    print("header", name)
open(p, "w", newline="").write(t)
