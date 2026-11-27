"""Round 93 tooling: make midbody2_flow_check_r93.py decode again from a jump table case (or any branch target) that
the first linear disassembly did not land on - the table's words decode as instructions and shift the boundaries.
Idempotent. usage: patch_flow_check_r93.py <script>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = '''    seen, todo = set(), [entry]
    while todo:
        x = todo.pop()
        while x in ins and x not in seen:'''
new = '''    seen, todo = set(), [entry]
    while todo:
        x = todo.pop()
        if x not in ins and entry <= x < a + 0x400:      # a target the linear pass did not land on: decode from it
            more = subprocess.run([sys.executable, tool, rom_path, f"{x:x}", f"{a + 0x400:x}"], capture_output=True, text=True, check=True).stdout
            for l in more.splitlines():
                if ":" not in l[:8]:
                    continue
                addr = int(l.split(":")[0], 16)
                parts = l.split()
                if addr in ins and addr != x and ins[addr] == (len(parts[1]) // 2, " ".join(parts[2:])):
                    break                                 # back in step with the first pass
                ins[addr] = (len(parts[1]) // 2, " ".join(parts[2:]))
            order = sorted(ins)
        while x in ins and x not in seen:'''
if new not in s:
    assert s.count(old) == 1
    s = s.replace(old, new)
old2 = '''    before = max(k for k in order if k < a)
    good = before in seen and before + ins[before][0] == a'''
new2 = '''    before = max(k for k in seen if k < a)
    good = before + ins[before][0] == a'''
if new2 not in s:
    assert s.count(old2) == 1
    s = s.replace(old2, new2)
open(p, "w").write(s)
print("patched")
