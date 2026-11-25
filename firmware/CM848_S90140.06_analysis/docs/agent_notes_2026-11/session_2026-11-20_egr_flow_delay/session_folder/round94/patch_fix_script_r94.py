"""Round 94 tooling: give fix_refresh_other_r94.py the function_olds set it needs (the old labels of function renames,
the only names the function-name column follows). Idempotent. usage: patch_fix_script_r94.py <fix script>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = 'open(tool, "w").write(s)\nprint("fixed")'
new = '''if "function_olds = set()" not in s:
    a = 'pairs = {"cm550": {}, "cm848": {}}\\n'
    assert s.count(a) == 1
    s = s.replace(a, a + "function_olds = set()     # old labels of function renames: the only ones the function-name column follows\\n")
    b = '            targets = ("cm550", "cm848") if r["address"] and is_function(fw, r["address"]) and not own_only else (fw,)\\n'
    assert s.count(b) == 1
    s = s.replace(b, b + '            if r["address"] and is_function(fw, r["address"]):\\n                function_olds.add(r["old_label"])\\n')
open(tool, "w").write(s)
print("fixed")'''
if new not in s:
    assert s.count(old) == 1
    s = s.replace(old, new)
open(p, "w").write(s)
print("fix script patched")
