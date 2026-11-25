"""Round 92 (read-only): write each finished batch's proposal (and verdicts, when its skeptic ran) from the bitfield
workflow's journal(s) to <outdir>/batch_<id>.json and print a summary per word. Later journals win (a resumed run).
usage: dump_words_r92.py <outdir> <journal.jsonl>..."""
import collections
import json
import os
import sys

outdir, journals = sys.argv[1], sys.argv[2:]
props, verdicts = {}, {}
for journal in journals:
    for line in open(journal):
        try:
            e = json.loads(line)
        except ValueError:
            continue
        if e.get("type") != "result":
            continue
        v = e.get("result") or e.get("value") or {}
        if isinstance(v, dict) and "words" in v:
            props[v["batch"]] = v
        elif isinstance(v, dict) and "verdicts" in v:
            verdicts[v["batch"]] = v
for b in sorted(props):
    json.dump({"proposal": props[b], "verdict": verdicts.get(b)}, open(os.path.join(outdir, f"batch_{b}.json"), "w"), indent=1)
    print(f"== {b} ({'verified' if b in verdicts else 'NOT verified'})")
    for w in props[b]["words"]:
        named = [f for f in w.get("fields") or [] if not f["name"].startswith("reserved_bit")]
        print(f"  word {w['word']:>2} {w['address']} {str(w.get('current_name'))[:44]} -> {w['proposed_name']} "
              f"{w['proposed_type']} {'SHARED' if w.get('shared_with_cm848') else ''} ({len(named)} named bits)")
    for r in props[b].get("cm848_field_renames") or []:
        print(f"  cm848 {r['type_name']} bit {r['bit']}: {r['current_field']} -> {r['proposed_field']}")
    if b in verdicts:
        c = collections.Counter(x["verdict"] for x in verdicts[b]["verdicts"])
        print(f"  verdicts: {dict(c)}")
        for x in verdicts[b]["verdicts"]:
            if x["verdict"] != "CONFIRMED":
                print(f"    {x['verdict']} {x['element']}: {(x.get('amendment') or '')[:300]} || {x['reason'][:200]}")
print("batches:", sorted(props), "verified:", sorted(verdicts))
