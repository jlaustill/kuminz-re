"""Round 94 tooling: apply_r94.py rewrites, in every comment it writes, a proposed name that does not survive - a
judge's AMENDED final name, an override's name, or a REFUTED element's proposal (its current name) - so a plate
comment of one batch never cites a name that another batch's judge changed. The replacements are collected from
all batches before anything is written. Idempotent. usage: patch_apply_r94b.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()


def rep(old, new):
    global s
    if new in s:
        return
    assert s.count(old) == 1, (old[:70], s.count(old))
    s = s.replace(old, new)


rep('''def checked_comment(text, label):
    """A comment must be the comment itself. Round 91 wrote a proposal's 'APPEND to the current comment: ...' in
    place of seven plate comments; such a text refuses the apply."""
    if INSTRUCTION.search(text or ""):
        problems.append(f"{label}: the comment reads like an instruction, not a comment: {text[:80]!r}")
    return text''',
    '''RENAMED_PROPOSALS = {}     # proposed name -> the name that is applied instead (filled before the batches run)


def checked_comment(text, label):
    """A comment must be the comment itself. Round 91 wrote a proposal's 'APPEND to the current comment: ...' in
    place of seven plate comments; such a text refuses the apply. Proposed names that another verdict changed are
    rewritten to the applied name."""
    if INSTRUCTION.search(text or ""):
        problems.append(f"{label}: the comment reads like an instruction, not a comment: {text[:80]!r}")
    for old, new in RENAMED_PROPOSALS.items():
        text = re.sub(rf"\\b{re.escape(old)}\\b", new, text or "")
    return text''')
rep('''for path in batches:
    data = json.load(open(path))''',
    '''for path in batches:      # first pass: the proposed names that will not be applied as proposed
    data = json.load(open(path))
    p0, vd0 = data["proposal"], (data.get("verdict") or {}).get("verdicts", [])
    index0 = verdict_index(vd0)
    for kind, items, keyf in (("function", p0.get("functions") or [], lambda x: ("function", "", norm(x["address"]))),
                              ("global", p0.get("globals") or [], lambda x: ("global", "CM848" if "848" in x["firmware"] else "CM550", norm(x["address"])))):
        for x in items:
            k = keyf(x)
            v0 = index0.get(k)
            ovkey = f"function|{k[2]}" if kind == "function" else f"global|{k[1]}|{k[2]}"
            ov0 = OVERRIDES.get(ovkey, {})
            proposed = x["proposed_name"]
            if ov0.get("drop") or not v0 or v0["verdict"] == "REFUTED":
                final = x["current_name"] if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", x.get("current_name") or "") else None
            else:
                final = ov0.get("name") or clean(v0.get("final_name")) or proposed
            if final and final != proposed and proposed != x.get("current_name"):
                RENAMED_PROPOSALS[proposed] = final
report.append(f"proposed names rewritten in comments: {len(RENAMED_PROPOSALS)}")
for path in batches:
    data = json.load(open(path))''')
open(p, "w").write(s)
print("patched")
