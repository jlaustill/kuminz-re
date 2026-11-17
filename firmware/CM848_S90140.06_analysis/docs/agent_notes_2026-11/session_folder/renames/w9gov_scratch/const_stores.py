"""For a data address list every store with the constant (li) or source that feeds it.
usage: const_stores.py 0xADDR [0xADDR ...]
Built on firmware/scripts/disasm_func + xref_addr (importing them; read-only)."""
import os
import re
import sys

SCRIPTS = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/scripts'
sys.path.insert(0, SCRIPTS)
import disasm_func as D      # noqa: E402
import xref_addr as X        # noqa: E402

LI = re.compile(r"\bli\s+r(\d+),(-?\d+)")
LIS = re.compile(r"\blis\s+r(\d+),(-?\d+)")
ADDI = re.compile(r"\baddi\s+r(\d+),r(\d+),(-?\d+)")
LOAD = re.compile(r"\b(lha|lhz|lwz|lbz|lbzx|lhzx|lhax)\s+r(\d+),")
STORE = re.compile(r"\b(sth|stw|stb|sthx|stwx|stbx)\s+r(\d+),")
ASM = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+){4}\s*(\S+)\s*(.*)$")


def main():
    funcs = D.function_table()
    for a in sys.argv[1:]:
        addr = int(a, 16)
        name, refs = X.referencing_functions(addr)
        print(f"## 0x{addr:08x} {name}")
        for start, fname in refs:
            s, stop = D.func_window(start, funcs)
            lines, _ = D.objdump(s, stop)
            hits, _ = D.find_accesses(lines, addr)
            for kind, text, w in hits:
                if kind != 'store':
                    continue
                m = STORE.search(text)
                if not m:
                    print(f"  {fname}: {text}")
                    continue
                reg = int(m.group(2))
                idx = None
                for i, ln in enumerate(lines):
                    if ln.strip() == text.split('  [')[0].strip() or text.split('  [')[0].strip() in ln:
                        idx = i
                        break
                src = '???'
                if idx is not None:
                    for j in range(idx - 1, max(idx - 60, -1), -1):
                        ln = lines[j]
                        m1 = LI.search(ln)
                        if m1 and int(m1.group(1)) == reg:
                            src = f"li {m1.group(2)}"
                            break
                        m2 = LOAD.search(ln)
                        if m2 and int(m2.group(2)) == reg:
                            src = f"loaded: {ln.strip()}"
                            break
                        m3 = ADDI.search(ln)
                        if m3 and int(m3.group(1)) == reg:
                            src = f"addi: {ln.strip()}"
                            break
                        # any other write to the register ends the search
                        m4 = re.search(r"\b(?:mr|add|subf|ori|andi\.?|rlwinm|extsh|mullw|divw)\s+r%d," % reg, ln)
                        if m4:
                            src = f"computed: {ln.strip()}"
                            break
                addr_in = text.split(':')[0].strip()
                print(f"  {fname} @{addr_in}: {text.split('\t')[-1].strip()}  <= {src}")


main()
