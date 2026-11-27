"""Round 97 stage D (both firmwares): the last 11 struct types with abbreviations spell their words out (from round 96 stage C) (the naming rule: no invented
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
    "can_std_rx_desc_t": "can_standard_receive_descriptor_t",
    "diag_service_request_t": "diagnostic_service_request_t",
    "diag_tp_state_t": "diagnostic_transport_protocol_state_t",
    "diag_transfer_state_t": "diagnostic_transfer_state_t",
    "j1939_tx_msg_buffer_t": "j1939_transmit_message_buffer_t",
    "j1939_vp44_msg_t": "j1939_vp44_message_t",
    "param_lookup_args_t": "parameter_lookup_arguments_t",
    "sensor_config_t": "sensor_configuration_t",
    "diag_clear_flags_t": "diagnostic_clear_flags_t",
    "diag_write_request_state_t": "diagnostic_write_request_state_t",
    "sensor_channel_config_t": "sensor_channel_configuration_t",
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
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r97d_types.csv"), "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for old, new in MAP.items():
        f.write(f"0x00000000,{new},{old},type,1\n")
