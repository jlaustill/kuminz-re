"""Round 93 (read-only): for each mid-function row removed by apply_r93_midbody2.py (read from deleted_functions.csv,
the 'mid-function row' entries), follow the code flow from the holding function's entry - both ways of every Bcc,
the target of every bra, stopping at rts / rte / rtd / jmp - and say whether the flow reaches the instruction just
before the removed address (so the removed address is inside that function and is entered by falling through).
A switch through a jump table (jmp (d16,pc,dn)) ends a path here, so its cases are followed from the table's word
offsets when the table follows the jmp. usage: midbody2_flow_check_r93.py <repo> <m68k.py>"""
import os
import re
import subprocess
import sys

repo, tool = os.path.abspath(sys.argv[1]), sys.argv[2]
rom_path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin")
rom = open(rom_path, "rb").read()
D = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/deleted_functions.csv")
ok = bad = 0
for line in open(D):
    m = re.match(r"^(0x[0-9a-f]+),mid-function row: (\d+) bytes into (\w+) \((0x[0-9a-f]+)\), after '(.*?)'; ", line)
    if not m:
        continue
    a, entry, name = int(m.group(1), 16), int(m.group(4), 16), m.group(3)
    out = subprocess.run([sys.executable, tool, rom_path, f"{entry:x}", f"{a + 0x400:x}"], capture_output=True, text=True, check=True).stdout
    ins = {}
    order = []
    for l in out.splitlines():
        if ":" not in l[:8]:
            continue
        addr = int(l.split(":")[0], 16)
        parts = l.split()
        ins[addr] = (len(parts[1]) // 2, " ".join(parts[2:]))
        order.append(addr)
    seen, todo = set(), [entry]
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
        while x in ins and x not in seen:
            seen.add(x)
            size, text = ins[x]
            op = text.split()[0] if text else ""
            target = re.search(r"\b0x([0-9a-f]+)$", text)
            if op in ("rts", "rte", "rtd"):
                break
            if op.startswith("jmp"):
                # a jump table of word offsets right after 'jmp (table,pc,dn.w)': follow its cases
                t = re.search(r"jmp \(0x([0-9a-f]+),pc", text)
                if t:
                    table = int(t.group(1), 16)
                    k = table
                    while k + 2 <= len(rom):
                        off = int.from_bytes(rom[k:k + 2], "big", signed=True)
                        case = table + off
                        if not (entry <= case < a + 0x400) or case in range(table, k + 2):
                            break
                        todo.append(case)
                        k += 2
                break
            if op.startswith("bra") and target:
                todo.append(int(target.group(1), 16))
                break
            if op[0:1] == "b" and op.split(".")[0] not in ("bsr", "bclr", "bset", "btst", "bchg", "bfextu", "bfexts", "bfins", "bfclr", "bfset", "bftst", "bfffo", "bfchg") and target:
                todo.append(int(target.group(1), 16))
            if op.startswith("dbf") or op.startswith("db"):
                if target:
                    todo.append(int(target.group(1), 16))
            x += size
    before = max(k for k in seen if k < a)
    good = before + ins[before][0] == a
    ok += good
    bad += not good
    print(f"{'inside ' if good else 'NOT REACHED'} 0x{a:05x} from {name} (0x{entry:x}): {len(seen)} instructions followed; before it 0x{before:x} '{ins[before][1][:36]}'")
print(f"{ok} rows are reached by flow from the holding function's entry; {bad} are not")
