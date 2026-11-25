"""Round 93 (read-only): assemble each batch's proposal / blind roles / verdict from the workflow journal(s) into
<outdir>/batch_<id>.json and print a review table: per function the current name, the proposal, the describer's
independent suggestion, and the judge's verdict with its final name; then the globals, the enum members, the skipped
functions and the judge's overall text. Later journals win (a resumed run).
usage: dump_batches_r93.py <outdir> <journal.jsonl>... [--full <batch>]"""
import json
import os
import sys

args = sys.argv[1:]
full = None
if "--full" in args:
    i = args.index("--full")
    full = args[i + 1]
    del args[i:i + 2]
outdir, journals = args[0], args[1:]
props, blinds, verdicts = {}, {}, {}
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
        if "functions" in v:
            props[b] = v
        elif "roles" in v:
            blinds[b] = v
        elif "verdicts" in v:
            verdicts[b] = v


def norm(a):
    try:
        return f"0x{int(str(a).strip(), 16):08x}"
    except ValueError:
        return str(a)


for b in sorted(props):
    p, bl, vd = props[b], blinds.get(b), verdicts.get(b)
    json.dump({"batch": b, "proposal": p, "blind": bl, "verdict": vd}, open(os.path.join(outdir, f"batch_{b}.json"), "w"), indent=1)
    if full and b != full:
        continue
    vi = {}
    for v in (vd or {}).get("verdicts", []):
        vi[(v["kind"], norm(v["address"]) if v["kind"] != "enum_member" else str(v["address"]).replace(" ", ""))] = v
    bi = {norm(r["address"]): r for r in (bl or {}).get("roles", [])}
    print(f"==================== {b}: {len(p.get('functions') or [])} functions, {len(p.get('skipped') or [])} skipped, "
          f"{len(p.get('globals') or [])} globals, {len(p.get('enum_members') or [])} enum members | describer "
          f"{'yes' if bl else 'NO'} | judge {'yes' if vd else 'NO'}")
    w = 400 if full else 150
    for f in p.get("functions") or []:
        a = norm(f["address"])
        v = vi.get(("function", a))
        d = bi.get(a)
        mark = v["verdict"] if v else "NO VERDICT"
        final = (v or {}).get("final_name") or ""
        print(f"  {a[5:]} {f['current_name']} -> {f['proposed_name']} [{f['relation']}{' ' + str(f.get('cm848_address') or '') if f['relation'] != 'standalone' else ''}] ({f['confidence']})")
        print(f"        judge {mark}{'' if not v or final == f['proposed_name'] else ' => ' + final}"
              f"{' [' + str(v.get('final_relation')) + ' ' + str(v.get('final_cm848_address') or '') + ']' if v and v.get('final_relation') and v.get('final_relation') != f['relation'] else ''}"
              f" | describer: {(d or {}).get('suggested_name') or '-'}")
        if full or (v and v["verdict"] != "CONFIRMED"):
            print(f"        role: {f['role'][:w]}")
            if d:
                print(f"        describer role: {d['role'][:w]}")
            if v:
                print(f"        judge: {(v.get('own_role') or '')[:w]} || {v['reason'][:w]}")
                if v.get("final_comment"):
                    print(f"        final comment: {v['final_comment'][:w]}")
    for s in p.get("skipped") or []:
        d = bi.get(norm(s["address"]))
        print(f"  SKIPPED {norm(s['address'])[5:]} {s['current_name']}: {s['reason'][:w]} | describer: {(d or {}).get('suggested_name') or '-'}")
    for g in p.get("globals") or []:
        a = norm(g["address"])
        v = vi.get(("global", a))
        final = (v or {}).get("final_name") or ""
        ftype = (v or {}).get("final_type") or ""
        print(f"  G {g['firmware']} {a} {g['current_name'] or '(no row)'} -> {g['proposed_name']} {g['proposed_type']} ({g['confidence']}) | "
              f"judge {v['verdict'] if v else 'NO VERDICT'}{'' if not v or final == g['proposed_name'] else ' => ' + final}"
              f"{'' if not ftype or ftype == g['proposed_type'] else ' type ' + ftype}")
        if v and (full or v["verdict"] != "CONFIRMED"):
            print(f"        judge: {v['reason'][:w]}")
    for e in p.get("enum_members") or []:
        v = vi.get(("enum_member", f"{e['enum_name']}:{int(e['value'])}"))
        final = (v or {}).get("final_name") or ""
        print(f"  E {e['firmware']} {e['enum_name']} {int(e['value'])} {e['current_member'] or '(new)'} -> {e['proposed_member']} ({e['confidence']}) | "
              f"judge {v['verdict'] if v else 'NO VERDICT'}{'' if not v or final == e['proposed_member'] else ' => ' + final}")
        if v and (full or v["verdict"] != "CONFIRMED"):
            print(f"        judge: {v['reason'][:w]}")
    if vd:
        print(f"  OVERALL: {(vd.get('overall') or '')[:1200 if full else 500]}")
    if full:
        print(f"  NOTES: {(p.get('notes') or '')[:3000]}")
print("batches:", sorted(props), "| described:", sorted(blinds), "| judged:", sorted(verdicts))
