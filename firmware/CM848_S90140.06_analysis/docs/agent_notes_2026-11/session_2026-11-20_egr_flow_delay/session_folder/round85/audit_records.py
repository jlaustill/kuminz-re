"""Write the prefix audit's full records (behavior, hardware, reason, the skeptic's problems) as plain text, one block
per function. usage: audit_records.py <workflow output file> <out.txt>"""
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
with open(sys.argv[2], "w") as out:
    for group in data:
        verdicts = {v["address"]: v for v in group["verdicts"]["verdicts"]}
        for f in group["proposals"]["functions"]:
            v = verdicts.get(f["address"], {})
            out.write(f"== {f['address']} {f['current_name']} -> {v.get('final_name')} "
                      f"[{f['change']}, {f['confidence']}, {v.get('verdict')}]\n")
            out.write("BEHAVIOR: " + f["behavior"] + "\n")
            out.write("HARDWARE: " + f["hardware"] + "\n")
            out.write("REASON: " + f["reason"] + "\n")
            for p in v.get("problems", []):
                out.write("PROBLEM: " + p + "\n")
            out.write("\n")
print("written")
