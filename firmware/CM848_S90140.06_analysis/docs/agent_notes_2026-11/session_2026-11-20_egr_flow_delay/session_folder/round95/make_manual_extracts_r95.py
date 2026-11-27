"""Round 95: the MPC555 User's Manual passages the register work cites (NXP MPC555UM, pdftotext -layout of the public
PDF from nxp.com.cn/docs/en/data-sheet/MPC555UM.pdf), so the archive keeps the evidence without the 18 MB PDF.
Each passage is a line range of the text with a heading; runs of spaces are squeezed.
usage: make_manual_extracts_r95.py <mpc555um.txt> <out.txt>"""
import re
import sys

text = open(sys.argv[1], errors="replace").read().split("\n")
RANGES = [
    ("Appendix A, USIU / SIU registers 0x2FC000-0x2FC3FF and CMF 0x2FC800 / 0x2FC840", 48215, 48560),
    ("Appendix A, Table A-7 TPU3 module registers", 48590, 48690),
    ("Appendix A, QADC64 module registers", 48870, 48905),
    ("13.12 QADC64 address map (control registers vs the CCW table and the result areas)", 26940, 27000),
    ("Appendix A, QSMCM registers", 48988, 49030),
    ("Appendix A, MIOS1 registers (MPWMSM / MMCSM / MDASM / MCPSM / interrupt registers)", 49095, 49520),
    ("15.10 MMCSM register map and 15.10.1.3 SCRD", 33975, 34080),
    ("15.11 MDASM register map and 15.11.1.3 SCRD", 34275, 34455),
    ("13.12.2-13.12.9 QACR0 / QACR1 / QACR2 / QASR0", 27185, 27200),
]
out = ["MPC555 User's Manual excerpts for PR #53 round 95 (pdftotext -layout; line numbers refer to that text)", ""]
for title, start, end in RANGES:
    out.append("=" * 100)
    out.append(f"{title} (lines {start}-{end})")
    out.append("=" * 100)
    for line in text[start - 1:end]:
        line = re.sub(r" {3,}", "  ", line.rstrip())
        if line.strip() and "Freescale Semiconductor" not in line:
            out.append(line)
    out.append("")
open(sys.argv[2], "w").write("\n".join(out) + "\n")
print(len(out), "lines")
