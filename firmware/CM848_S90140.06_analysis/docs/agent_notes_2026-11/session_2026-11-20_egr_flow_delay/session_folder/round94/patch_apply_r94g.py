"""Round 94 tooling: apply_r94.py applies CM848-only function renames (proposal cm848_functions[], verdict kind
'cm848_function', override key 'cm848_function|<address>'): the CM848 row is renamed with the plate comment and its
function_definitions / local_variables rows follow. A new name must keep a CM848 prefix (cm848_ / mpc555_ / hpcr_)
unless the verdict calls it a twin; a CM848-only name that equals the old one is reported, not written.
Idempotent. usage: patch_apply_r94g.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
# 1. the first pass (names that will not be applied as proposed) knows the new kind
old1 = '''    for kind, items, keyf in (("function", p0.get("functions") or [], lambda x: ("function", "", norm(x["address"]))),
                              ("global", p0.get("globals") or [], lambda x: ("global", "CM848" if "848" in x["firmware"] else "CM550", norm(x["address"])))):
        for x in items:
            k = keyf(x)
            v0 = index0.get(k)
            ovkey = f"function|{k[2]}" if kind == "function" else f"global|{k[1]}|{k[2]}"'''
new1 = '''    for kind, items, keyf in (("function", p0.get("functions") or [], lambda x: ("function", "", norm(x["address"]))),
                              ("cm848_function", p0.get("cm848_functions") or [], lambda x: ("cm848_function", "", norm(x["address"]))),
                              ("global", p0.get("globals") or [], lambda x: ("global", "CM848" if "848" in x["firmware"] else "CM550", norm(x["address"])))):
        for x in items:
            k = keyf(x)
            v0 = index0.get(k)
            ovkey = f"{kind}|{k[2]}" if kind != "global" else f"global|{k[1]}|{k[2]}"'''
# 2. the loop itself, after the CM550 function loop
old2 = '''            if was is not None:
                report.append(f"{b} CM848 function {twin_address} {was} -> {new} [twin of CM550 {a}]" if was != new
                              else f"{b} CM848 function {twin_address} already {new}")
    # ---------------------------------------------------------------- globals'''
new2 = '''            if was is not None:
                report.append(f"{b} CM848 function {twin_address} {was} -> {new} [twin of CM550 {a}]" if was != new
                              else f"{b} CM848 function {twin_address} already {new}")
    # ---------------------------------------------------------------- CM848-only functions
    for f in p.get("cm848_functions") or []:
        a = norm(f["address"])
        key = ("cm848_function", "", a)
        v = index.get(key)
        used.add(key)
        ov = OVERRIDES.get(f"cm848_function|{a}", {})
        if ov.get("drop"):
            report.append(f"{b} DROPPED CM848 function {a} ({ov['reason']})")
            continue
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{b} SKIP CM848 function {a} {f['current_name']} -> {f['proposed_name']} ({v['verdict'] if v else 'no verdict'})")
            continue
        new = ov.get("name") or clean(v.get("final_name")) or f["proposed_name"]
        plate = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(f.get("plate_comment")), f"{b} CM848 function {a}")
        if not re.match(r"^[A-Za-z][A-Za-z0-9_]*$", new):
            problems.append(f"{b}: CM848 function {a}: bad name {new!r}")
            continue
        twin = "twin" in (ov.get("relation") or clean(v.get("final_relation")) or "").lower()
        if not twin and not re.match(r"^(cm848_|mpc555_|hpcr_)", new):
            problems.append(f"{b}: CM848 function {a} {new}: a CM848-only name keeps a CM848 prefix")
            continue
        was = rename_function("CM848", a, new, lambda o, c: f"{plate} (was {o}; {R})", b)
        if was is not None:
            report.append(f"{b} CM848 function {a} {was} -> {new} [CM848 only]" if was != new else f"{b} CM848 function {a} {new}: name kept")
    # ---------------------------------------------------------------- globals'''
for old, new in ((old1, new1), (old2, new2)):
    if new not in s:
        assert s.count(old) == 1, (old[:60], s.count(old))
        s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
