"""Round 15: for each call of the four sensor channel functions, print channel_index (argument 8), the high / low fault
bits (9 / 10) with their DTCs (fault n -> ROM 0x5985a slot -> obd_dtc_code_table), and the value / default / fault
status outputs (11 / 12 / 13) plus the state (2) and tables (4 / 5), so a channel's rows are proved by the call.
usage: channel_calls_r15.py <cpp> <rom.bin> [channel ...]"""
import re
import struct
import sys

cpp, rom_path = sys.argv[1], sys.argv[2]
want = {int(x) for x in sys.argv[3:]}
rom = open(rom_path, "rb").read()
text = open(cpp).read()
FUNCS = ("sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit",
         "sensorChannelTypeB_update")


def dtc(fault):
    slot = struct.unpack(">h", rom[0x5985a + 2 * fault:0x5985a + 2 * fault + 2])[0]
    if not 0 <= slot < 170:
        return "-"
    code = struct.unpack(">H", rom[0x5b57c + 2 * slot:0x5b57c + 2 * slot + 2])[0]
    return f"P{code:04X}"


def num(s):
    s = s.strip()
    try:
        return int(s, 0)
    except ValueError:
        return None


for m in re.finditer(rf"\b({'|'.join(FUNCS)})\s*\(", text):
    i, depth = m.end(), 1
    while depth:
        depth += {"(": 1, ")": -1}.get(text[i], 0)
        i += 1
    body = text[m.end():i - 1]
    args, depth, cur = [], 0, ""
    for ch in body:
        if ch == "," and depth == 0:
            args.append(cur.strip())
            cur = ""
            continue
        depth += {"(": 1, ")": -1}.get(ch, 0)
        cur += ch
    args.append(cur.strip())
    if len(args) < 13:
        continue
    ch = num(args[7])
    if ch is None or (want and ch not in want):
        continue
    hi, lo = num(args[8]), num(args[9])
    clean = [re.sub(r"\s+", " ", a.replace("&", "")) for a in args]
    print(f"ch {ch:3d} {m.group(1)[:22]:22s} hi {hi} {dtc(hi) if hi is not None else ''} lo {lo} "
          f"{dtc(lo) if lo is not None else ''} | value {clean[10]} | default {clean[11]} | status {clean[12]} | "
          f"state {clean[1]} | x {clean[3]} | y {clean[4]} | config {clean[0]} | cache {clean[2]} | filter {clean[6]}")
