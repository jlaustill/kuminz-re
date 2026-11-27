"""Round 95 (read-only): every named CM848 global row in the MPC555 register space (USIU 0x2FC000-0x2FFFFF, IMB3
0x300000-0x307FFF) with its .cpp render count and the MPC555 User's Manual symbol at its address (Appendix A
internal memory map, pdftotext -layout; a cell that wraps puts the symbol on a neighbouring line, so the address
line and the two lines around it are searched). DPTRAM (0x302000-0x3037FF) holds firmware variables, not registers.
usage: peripheral_names_audit_r95.py <repo> <manual.txt>"""
import os
import re
import sys

repo, manual = os.path.abspath(sys.argv[1]), sys.argv[2]
lines = open(manual, errors="replace").read().split("\n")
SKIP = {"See", "Reserved", "TPU3", "TPU", "QADC64", "QSMCM", "QSPI", "SCI", "MIOS1", "MPWMSM", "MMCSM", "MDASM",
        "Port", "Test", "Status", "Control", "Register", "Data", "Module", "Interrupt", "Channel", "Host", "Flag",
        "Configuration", "UIMB", "MCPSM", "MPIOSM", "MBISM", "MIRSM", "TouCAN", "Message", "Buffer"}
SYMBOL = re.compile(r"^[A-Z][A-Z0-9]*(_[A-Z0-9]+)*$")
manual_symbols = {}
for i, line in enumerate(lines):
    if i < 48000:                                       # Appendix A starts near line 48200 in this text
        continue
    m = re.match(r"^\s*0x(2F|30) ([0-9A-F]{4})\b(.*)$", line)
    if not m:
        continue
    address = int(m.group(1) + m.group(2), 16)
    found = []
    for j in (i, i - 1, i + 1, i - 2, i + 2):
        if 0 <= j < len(lines):
            text = lines[j] if j == i else re.sub(r"0x(2F|30) [0-9A-F]{4}", "", lines[j])
            for t in re.split(r"[\s,.()]+", text):
                if (SYMBOL.match(t) and t not in SKIP and len(t) >= 3 and not re.match(r"^[0-9A-F]{4}$", t)
                        and t not in ("0X30", "POR") and not t.startswith("0X")):
                    found.append(t)
            if found:
                break
    manual_symbols.setdefault(address, found[:2])
cpp = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
tokens = {}
for m in re.finditer(r"\b[A-Za-z_][A-Za-z0-9_]*\b", cpp):
    tokens[m.group(0)] = tokens.get(m.group(0), 0) + 1
for line in open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv"), newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) < 3 or not parts[0].startswith("0x") or not parts[1]:
        continue
    a = int(parts[0], 16)
    if not (0x2FC000 <= a <= 0x2FFFFF or 0x300000 <= a <= 0x307FFF) or 0x302000 <= a <= 0x3037FF:
        continue
    renders = tokens.get(parts[1], 0) + tokens.get("_" + parts[1], 0)
    print(f"0x{a:06x} {parts[1]:40s} {parts[2]:24s} renders {renders:4d} manual {' / '.join(manual_symbols.get(a, [])) or '-'}")
