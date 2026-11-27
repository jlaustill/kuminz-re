"""For each address: the current global_variables.csv name and type, its e2m record (the ECU's parameter table) and
up to N code lines (with their function) that use the name. For verifying hand renames quickly.
usage: evidence_W15.py <repo> <lines per row> <0xADDR>..."""
import os
import re
import subprocess
import sys

repo, per = os.path.abspath(sys.argv[1]), int(sys.argv[2])
fw = os.path.join(repo, "firmware")
out = os.path.join(fw, "CM848_S90140.06_analysis", "output")
rows = {}
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        a, name, typ = (line.split(",", 3) + ["", ""])[:3]
        rows[int(a, 16)] = (name, typ)
cpp_lines = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read().split("\n")
function_at, current, in_block = [], "", False
for line in cpp_lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append("" if in_block or line.strip().startswith("/*") else current)
    if "/*" in line and "*/" not in line.split("/*", 1)[1]:
        in_block = True
    elif in_block and "*/" in line:
        in_block = False
for arg in sys.argv[3:]:
    a = int(arg, 16)
    name, typ = rows.get(a, ("(no row)", ""))
    e2m = subprocess.run([sys.executable, os.path.join(fw, "scripts", "e2m_block_addresses.py"), "--address", arg],
                         capture_output=True, text=True, cwd=fw).stdout.strip().split("\n")[0]
    e2m = re.sub(r" -> .*?; ?", " | ", e2m)[:150]
    print(f"{a:#x} {name} [{typ}] e2m: {e2m or '-'}")
    if name and name != "(no row)":
        pattern = re.compile(r"(?<![A-Za-z0-9])_?" + re.escape(name) + r"(?![A-Za-z0-9_])")
        shown = 0
        for i, line in enumerate(cpp_lines):
            s = line.strip()
            if function_at[i] and not s.startswith(("//", "/*", "*")) and pattern.search(s):
                print(f"    {function_at[i]}: {s[:130]}")
                shown += 1
                if shown >= per:
                    break
