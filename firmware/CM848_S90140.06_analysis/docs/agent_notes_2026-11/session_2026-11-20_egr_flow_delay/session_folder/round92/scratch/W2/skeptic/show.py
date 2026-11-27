"""Skeptic: print the verdict elements whose name starts with one of the given prefixes, one JSON object per line
(the exact text to submit), or the overall text with 'overall'. usage: show.py <prefix>... | overall"""
import json
import os
import sys

d = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "verdict_W2.json")))
if sys.argv[1] == "overall":
    print(d["overall"])
else:
    for v in d["verdicts"]:
        el = v["element"]
        for pre in sys.argv[1:]:
            if el == pre or el.startswith(pre + " "):
                print(json.dumps(v, ensure_ascii=False))
                break
