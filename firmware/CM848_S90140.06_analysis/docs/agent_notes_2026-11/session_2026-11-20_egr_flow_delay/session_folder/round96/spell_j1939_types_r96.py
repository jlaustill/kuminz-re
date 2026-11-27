"""Round 96 stage C (both firmwares): the J1939 / CAN struct types spell their words out (the naming rule: no invented
abbreviations; J1939 / CAN / PGN stay). j1939_rx_msg_t renders in 91 CM848 lines (function signatures and casts),
j1939_tx_msg_t in both firmwares (the shared 14-byte transmit descriptor), so this is a label-only change of type
tokens. A word-boundary rename over every CSV column of both firmwares' output folders and the current-state docs
(firmware/CLAUDE.md, the CM848 / CM550 docs); a line that holds a history note for an old name ('was <old>') is left
alone and reported. Writes the map for the proofs. Idempotent; keeps line endings. usage: spell_j1939_types_r96.py <repo>"""
import glob
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
MAP = {
    "j1939_rx_msg_t": "j1939_received_message_t",
    "j1939_tx_msg_t": "j1939_transmit_message_t",
    "j1939_msg_hdr_t": "j1939_message_header_t",
    "can_rx_channel_t": "can_receive_channel_t",
    "j1939_ccss_tx_payload_t": "j1939_cruise_control_vehicle_speed_setup_payload_t",
}
PATTERN = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, MAP)) + r")(?![A-Za-z0-9_])")
files = []
for fw in ("firmware/CM550_J90350.00_analysis", "firmware/CM848_S90140.06_analysis"):
    files += glob.glob(os.path.join(repo, fw, "output", "*.csv"))
    files += glob.glob(os.path.join(repo, fw, "docs", "*.md"))
files += [os.path.join(repo, "firmware/CLAUDE.md")]
total, held = 0, []
for p in files:
    t = open(p, newline="").read()
    if not PATTERN.search(t):
        continue
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    n = 0
    for i, l in enumerate(lines):
        if not PATTERN.search(l):
            continue
        if any(re.search(rf"\bwas `?{re.escape(old)}\b", l) for old in MAP):
            held.append(f"{os.path.relpath(p, repo)}:{i + 1}")
            continue
        n += len(PATTERN.findall(l))
        lines[i] = PATTERN.sub(lambda m: MAP[m.group(1)], l)
    if n:
        open(p, "w", newline="").write(E.join(lines))
        print(f"{os.path.relpath(p, repo)}: {n}")
        total += n
print("total", total)
for h in held:
    print("HELD (history note):", h)
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r96c_types.csv"), "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for old, new in MAP.items():
        f.write(f"0x00000000,{new},{old},type,1\n")
