"""Round 27 stage B: statement-level diff of one function, the old .cpp against the new .cpp rewritten into the old
notation by prove_fault_bitfields.py (imported). Statements are split at ';', '{' and '}'.
usage: diff_function_r27b.py <old cpp> <new cpp> <fault_fields.tsv> <function name>..."""
import difflib
import importlib.util
import re
import sys

old_cpp, new_cpp, tsv = sys.argv[1:4]
names = sys.argv[4:]
sys.argv = [sys.argv[0], old_cpp, new_cpp, tsv, "--show", "0"]
spec = importlib.util.spec_from_file_location("p", "/home/linux/.claude/jobs/374b0424/tmp/w15/r27/prove_fault_bitfields.py")
p = importlib.util.module_from_spec(spec)
import io
import contextlib
with contextlib.redirect_stdout(io.StringIO()):
    spec.loader.exec_module(p)
for name in names:
    key = next(k for k in p.old if k.startswith(name + " @"))
    a = [s for s in re.split(r"(?<=[;{}])", p.old[key]) if s]
    b = [s for s in re.split(r"(?<=[;{}])", p.new[key]) if s]
    print(f"=== {key}")
    for line in difflib.unified_diff(a, b, "old", "new", n=1, lineterm=""):
        if not line.startswith(("---", "+++")):
            print("   " + line[:240])
