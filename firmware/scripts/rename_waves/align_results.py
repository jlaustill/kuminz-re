"""Vocabulary pass over agent result files: read <dir>/result_<wave>_<group>.jsonl, write <dir>/aligned_<wave>_<group>.jsonl.
Usage: align_results.py <dir> <wave> <group>... [--swap OLD=NEW]...

- New function names say `initialize`, never `init` (the user's decision, 2026-11-17): cm848_initFoo ->
  cm848_initializeFoo, fooInitBar -> fooInitializeBar. A data name with an `init` word is not rewritten here
  (initial_ or initialization_ depends on the meaning); apply_renames.py's gate rejects it.
- *_axis_offset_cache / *_lookup_cached_offset -> *_cached_axis_offset.
- --swap OLD=NEW replaces OLD in every new name (e.g. a prefix decision:
  --swap exhaust_gas_recirculation_valve_=egr_valve_ --swap ExhaustGasRecirculationValve=EgrValve).
- Every changed name is also replaced, word-bounded, in the plate_comment / evidence / text / comment fields.
- A confirmed function row with a plate comment but no `new` keeps its name (a plate-only refresh).
- `<name>+N` sub-label rows are left out (not identifiers) and listed."""
import json
import os
import re
import sys

SUFFIX = [("_axis_offset_cache", "_cached_axis_offset"), ("_lookup_cached_offset", "_cached_axis_offset")]
INIT_PREFIX = re.compile(r"^((?:[a-z0-9]+_)*)init(?=[A-Z0-9])")
INIT_CAMEL = re.compile(r"(?<=[a-z0-9])Init(?=[A-Z0-9]|$)")


def parse(argv):
    positional, swaps, it = [], [], iter(argv)
    for a in it:
        if a == "--swap":
            old, new = next(it).split("=", 1)
            swaps.append((old, new))
        else:
            positional.append(a)
    return positional, swaps


def fix(name, swaps):
    for o, n in SUFFIX:
        if name.endswith(o):
            name = name[: -len(o)] + n
    for o, n in swaps:
        name = name.replace(o, n)
    name = INIT_PREFIX.sub(r"\1initialize", name)
    return INIT_CAMEL.sub("Initialize", name)


def main():
    (d, wave, *groups), swaps = parse(sys.argv[1:])
    recs, text_map, dropped = {}, {}, []
    for g in groups:
        recs[g] = [json.loads(l) for l in open(os.path.join(d, f"result_{wave}_{g}.jsonl")) if l.strip()]
        for r in recs[g]:
            if r.get("kind") == "function" and r.get("verdict") == "confirmed" and not r.get("new") and r.get("plate_comment"):
                r["new"] = r["old"]
            if r.get("new") and r.get("kind") in ("function", "global", "new_global"):
                n = fix(r["new"], swaps)
                if n != r["new"]:
                    text_map[r["new"]] = n
    pattern = (re.compile(r"\b(" + "|".join(re.escape(k) for k in sorted(text_map, key=len, reverse=True)) + r")\b")
               if text_map else None)
    for g, rs in recs.items():
        out = []
        for r in rs:
            if r.get("kind") == "global" and ("+" in (r.get("old") or "") or "+" in (r.get("new") or "")):
                dropped.append(f"{g}: {r.get('address')} {r.get('old')} -> {r.get('new')}")
                continue
            if r.get("new") in text_map:
                r["new"] = text_map[r["new"]]
            for k in ("plate_comment", "evidence", "text", "comment"):
                if r.get(k) and pattern:
                    r[k] = pattern.sub(lambda m: text_map[m.group(1)], r[k])
            out.append(json.dumps(r))
        open(os.path.join(d, f"aligned_{wave}_{g}.jsonl"), "w").write("\n".join(out) + "\n")
    print("names changed:", len(text_map), "| sub-label rows left out:", len(dropped))
    for x in dropped:
        print("  ", x)


if __name__ == "__main__":
    main()
