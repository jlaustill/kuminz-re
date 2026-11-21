"""Every function that builds a J1939 CAN header (CONCAT13(priority << 2, 0xPPSSAA) or a literal 0x18xxxxxx-style
id), with the PGN the constant encodes (PDU1: PF < 240, the PS byte is a destination and not part of the PGN), the
priority word it uses and the descriptor it fills. Flags functions whose name names a different PGN or none.
usage: j1939_header_pgns.py <cpp>"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read()
for chunk in re.split(r"(?m)^(?=// Function: )", cpp):
    m = re.match(r"// Function: (\S+) @ (\S+)", chunk)
    if not m:
        continue
    name, address = m.groups()
    body = re.sub(r"\s+", " ", chunk)
    for h in re.finditer(r"CONCAT13\(\(\(byte\)([A-Za-z0-9_.]+) & 7\) << 2,0x([0-9a-f]{5,6})\)", body):
        prio, const = h.group(1), int(h.group(2), 16)
        pf, ps = (const >> 16) & 0xff, (const >> 8) & 0xff
        pgn = (pf << 8) | (ps if pf >= 240 else 0)
        dest = "" if pf >= 240 else f" (to 0x{ps:02x})"
        target = re.search(r"([A-Za-z0-9_]+)\.header\.can_id = CONCAT13\(\(\(byte\)" + re.escape(prio), body)
        named = str(pgn) in name
        print(f"{'  ' if named else '? '}{address} {name}: PGN {pgn}{dest} prio {prio} -> "
              f"{target.group(1) if target else '?'}")
