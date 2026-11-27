"""Round 94 (read-only on the journals): collect the finished results of the round 93 naming workflows
(wf_9501d76c-676 and the self-healing relaunch wf_a3305425-84c) per batch - the investigator's proposal, the
describer's roles and a judge's verdicts when one exists - into <outdir>/batch_<id>.json, and say what is missing.
A later journal wins for the same batch and kind. usage: collect_results_r94.py <outdir> <journal.jsonl>..."""
import json
import os
import sys

outdir, journals = sys.argv[1], sys.argv[2:]
found = {}
for journal in journals:
    for line in open(journal):
        try:
            e = json.loads(line)
        except ValueError:
            continue
        if e.get("type") != "result":
            continue
        v = e.get("result") or e.get("value") or {}
        if not isinstance(v, dict) or "batch" not in v:
            continue
        b = str(v["batch"]).strip().split()[0].strip(":")
        kind = "proposal" if "functions" in v else "blind" if "roles" in v else "verdict" if "verdicts" in v else None
        if kind:
            found.setdefault(b, {})[kind] = v
for b in sorted(found):
    data = {"batch": b, **{k: found[b].get(k) for k in ("proposal", "blind", "verdict")}}
    json.dump(data, open(os.path.join(outdir, f"batch_{b}.json"), "w"), indent=1)
    p, bl = data["proposal"], data["blind"]
    print(f"{b}: proposal {'yes (' + str(len(p.get('functions') or [])) + ' functions, ' + str(len(p.get('globals') or [])) + ' globals, ' + str(len(p.get('enum_members') or [])) + ' enum members, ' + str(len(p.get('skipped') or [])) + ' skipped)' if p else 'MISSING'}; "
          f"describer {'yes (' + str(len(bl.get('roles') or [])) + ' roles)' if bl else 'MISSING'}; judge {'yes' if data['verdict'] else 'MISSING'}")
