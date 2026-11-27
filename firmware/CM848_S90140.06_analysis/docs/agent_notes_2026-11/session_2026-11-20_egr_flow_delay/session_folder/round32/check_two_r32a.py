"""Round 32: confirm the two remaining differences.
- cm848_checkDiscreteOutputReadBack: the old body with param_1..param_9 renamed to the prototype's names (and the
  uint parameter keyword as dword) equals the new body;
- mpc555_tickTransferTimeoutAndRuntimeCounter: equal once the local declarations are sorted.
usage: check_two_r32a.py <old flat cpp> <new flat cpp>"""
import re
import sys

old_t, new_t = open(sys.argv[1]).read(), open(sys.argv[2]).read()


def body(t, name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    return re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)


P = ["logical_output", "read_back_line", "high_fault_bit", "low_fault_bit", "on_mismatch_count", "off_mismatch_count",
     "high_fault_recovery_count", "low_fault_recovery_count", "retry_count"]
a = body(old_t, "diag_faultMatch_outputCheck_update").replace("diag_faultMatch_outputCheck_update",
                                                             "cm848_checkDiscreteOutputReadBack")
for k in range(9, 0, -1):
    a = re.sub(rf"\bparam_{k}\b", P[k - 1], a)
a = re.sub(r"\s+", "", a)
a = a.replace("uintlogical_output", "dwordlogical_output").replace("uintread_back_line", "dwordread_back_line")
a = a.replace("uinthigh_fault_bit", "dwordhigh_fault_bit").replace("uintlow_fault_bit", "dwordlow_fault_bit")
a = a.replace("ushort*retry_count", "word*retry_count")
b = re.sub(r"\s+", "", body(new_t, "cm848_checkDiscreteOutputReadBack"))
print("check function equal after the parameter renames:", a == b)
if a != b:
    i = next(k for k in range(min(len(a), len(b))) if a[k] != b[k])
    print("  old ..." + a[max(0, i - 80):i + 120] + "\n  new ..." + b[max(0, i - 80):i + 120])


def sorted_decls(s):
    m = re.match(r"(.*?\{)((?:[a-z_0-9]+\*?[A-Za-z_0-9]+;)+)(.*)", s)
    if not m:
        return s
    decls = sorted(re.findall(r"[a-z_0-9]+\*?[A-Za-z_0-9]+;", m.group(2)))
    return m.group(1) + "".join(decls) + m.group(3)


x, y = (sorted_decls(re.sub(r"\s+", "", body(t, "mpc555_tickTransferTimeoutAndRuntimeCounter")))
        for t in (old_t, new_t))
print("tick function equal with sorted declarations:", x == y)
