"""Round 95 (read-only): audit CM848's mpc555_registers.csv against the MPC555 User's Manual (NXP MPC555UM, Appendix A
'Internal Memory Map', from pdftotext -layout), and say what the hwregs stage would do with each row if it ran.
- The manual's tables give 'address access symbol register size'; a symbol ends in _A / _B for the two TPU3 / QADC64
  modules. The parse keeps the first symbol-looking token after the address and the access code.
- A CSV name agrees when its last component matches the manual symbol (prefixes USIU_ / QSMCM_ / MIOS_ / TPUA_ ...
  and the _A / _B suffix are ignored).
- Stage preview (ApplyMPC555Registers' rule): a row is SKIPPED when global_variables.csv names the address, COVERED
  when it falls inside a typed global row's span (the stage would clear that data and split it), else APPLIED.
usage: register_audit_r95.py <repo> <manual.txt> [--list KIND]"""
import csv
import importlib.util
import os
import re
import sys

repo, manual = os.path.abspath(sys.argv[1]), sys.argv[2]
ACCESS = re.compile(r"^(S|U|T|S/U|S/U\d|S\d|U\d|—|-)$")
SYMBOL = re.compile(r"^[A-Z][A-Z0-9_]{1,}$")
by_address = {}
for line in open(manual, errors="replace"):
    m = re.match(r"^\s*0x(2F|30) ([0-9A-F]{4})\b(.*)$", line)
    if not m:
        continue
    address = int(m.group(1) + m.group(2), 16)
    rest = m.group(3).replace("–", " ").split()
    if rest and rest[0] == "0x30":
        continue                                        # a range line: '0x30 4A00 – 0x30 4A7E ...'
    tokens = [t for t in rest if not ACCESS.match(t)]
    symbol = next((t for t in tokens[:2] if SYMBOL.match(t) and not t.startswith("0X")), None)
    if symbol and address not in by_address:
        by_address[address] = symbol
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
spec = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/overlap_check_r94.py"
src = open(spec).read().split("\nrepo = os.path.abspath")[0]
ns = {}
exec(compile(src, spec, "exec"), ns)
rows = []
for line in open(os.path.join(out, "global_variables.csv"), newline="").read().split("\n"):
    parts = line.rstrip("\r").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        rows.append((int(parts[0], 16), parts[1], parts[2]))
named = {a: n for a, n, t in rows if n}
# typed spans: reuse the checker's width rule through its overlaps() helper on a synthetic probe is awkward, so
# recompute: each row's span from its type width (structs / enums / primitives / arrays)
found, _ = ns["overlaps"](repo, "firmware/CM848_S90140.06_analysis/output")
holders = {}
for a, n, t, h in found:
    holders[a] = h


def covering(address):
    """The typed row whose span covers address (not starting at it), from the checker's sweep, or None."""
    return holders.get(address)


registers = []
for r in csv.reader(l for l in open(os.path.join(out, "mpc555_registers.csv"), newline="") if not l.startswith("#")):
    if r and r[0].startswith("0x"):
        registers.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else "", r[3] if len(r) > 3 else ""))
kinds = {}
for address, name, typ, comment in registers:
    manual_symbol = by_address.get(address)
    last = re.sub(r"^(USIU|SIU|QSMCM|MIOS|TPUA|TPUB|QADC64A|QADC64B|TOUCAN_A|TOUCAN_B|TOUCANA|TOUCANB|UIMB|DPTRAM|"
                  r"CMF|L2U|PPC)_", "", name)
    if manual_symbol is None:
        verdict = "not-in-manual-table"
    else:
        base = re.sub(r"_[AB]$", "", manual_symbol)
        verdict = "agrees" if last.upper().replace("_", "") in (base.replace("_", ""),
                                                               manual_symbol.replace("_", "")) else "DIFFERS"
    if address in named:
        stage = "skipped (named " + named[address] + ")"
    elif covering(address):
        stage = "COVERED by " + covering(address)[1]
    else:
        stage = "APPLIED"
    kinds.setdefault(verdict, []).append((address, name, manual_symbol, stage))
for k, v in kinds.items():
    print(f"{k}: {len(v)}")
stages = {}
for v in kinds.values():
    for a, n, s, st in v:
        stages[st.split(" ")[0]] = stages.get(st.split(" ")[0], 0) + 1
print("stage preview:", stages)
if "--list" in sys.argv:
    want = sys.argv[sys.argv.index("--list") + 1]
    for k, v in kinds.items():
        for a, n, s, st in v:
            if want in (k, st.split(" ")[0], "all"):
                print(f"  0x{a:06x} {n:32s} manual {s or '-':14s} {k:20s} {st}")
