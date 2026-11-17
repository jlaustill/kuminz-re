"""Classify every token change between two canonical .cpp files into the kinds a typing pass is expected to cause.
usage: stage_b_classify.py old_canon.cpp new_canon.cpp [--show-other N]"""
import collections
import difflib
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
TOKEN = re.compile(r"[A-Za-z_][A-Za-z0-9_]*|0x[0-9a-fA-F]+|\d+|->|[^\sA-Za-z0-9_]")
ENUM = re.compile(r"^(ENGINE_OPERATING_MODE|EGR_VALVE|COMBUSTION_CHI_SOURCE)_[A-Z0-9_]+$")
CASTY = {"(", ")", "short", "word", "sword", "int", "uint", "ushort", "dword", "byte", "char", "undefined2", "undefined4", "*",
         "ENGINE_OPERATING_MODE", "EGR_VALVE_CONTROL_STATE", "COMBUSTION_CHI_SOURCE", "undefined", "ulonglong", "longlong", "bool"}
RENAMES = {"torque_limit_arb_t_0040a2f6", "engine_speed_limit_arbitration", "main_injection_timing_source_code",
           "governor_pid_t_0040af5a", "operating_mode_governor_output", "proportional_gain", "integral_term", "fuel_demand",
           "mode_code", "torque_limit_arb_t", "engine_speed_limit_arbitration_t", "governor_pid_t", "operating_mode_governor_output_t"}


def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], TOKEN.findall(parts[i + 2])) for i in range(1, len(parts), 3)}


def kind(a, b):
    sa, sb = set(a), set(b)
    if any(ENUM.match(t) for t in b) and all(re.fullmatch(r"0x[0-9a-fA-F]+|\d+|-", t) or t in CASTY for t in a):
        return "enum member for a number"
    if (sa | sb) <= CASTY:
        return "cast / type keyword"
    if any(re.fullmatch(r"_\d+_\d+_", t) for t in a + b) and len(a) + len(b) <= 8:
        return "sub-piece <-> split word name"
    if (sa | sb) & RENAMES and len(a) + len(b) <= 8:
        return "struct / instance rename"
    if all(re.fullmatch(r"[A-Za-z]Var\d+|[a-z]+[A-Z]?Var\d+|local_\w+|param_\d+", t) or t in CASTY or t in (";", ",")
           for t in a + b):
        return "decompiler temporary / declaration"
    return "OTHER"


o, n = split(sys.argv[1]), split(sys.argv[2])
show = int(sys.argv[sys.argv.index("--show-other") + 1]) if "--show-other" in sys.argv else 0
counts, per_fn, other = collections.Counter(), collections.defaultdict(collections.Counter), []
for addr in sorted(n):
    if addr not in o or o[addr][1] == n[addr][1]:
        continue
    name, ta, tb = n[addr][0], o[addr][1], n[addr][1]
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ta, tb, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        k = kind(ta[i1:i2], tb[j1:j2])
        counts[k] += 1
        per_fn[name][k] += 1
        if k == "OTHER":
            other.append(f"{name}: {' '.join(ta[max(0, i1 - 4):i2])}  =>  {' '.join(tb[max(0, j1 - 4):j2])}")
print(f"{len(per_fn)} functions; changes by kind: {dict(counts)}")
print(f"functions with OTHER changes: {sum(1 for c in per_fn.values() if c['OTHER'])}")
for line in other[:show]:
    print("  ", line[:230])
