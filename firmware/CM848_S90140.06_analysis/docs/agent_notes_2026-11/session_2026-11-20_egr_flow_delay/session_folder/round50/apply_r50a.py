"""Round 50 stage A: two more gap fills, found by access signature (gap_access_signatures.py: every load / store in the
gap lands on a record of its width, lha / lhz agreeing with the record's sign), then read against the code:
  8A7B (10 bytes) 0x4086c8 tiled between 8A2A and 8C49: the TSC1-lost counter's calibrations (PTP = the backup
                  powertrain protection, round 46). The j1939_tsc1_* timing rows join the tsc1_lost_* family.
  1585 (2 bytes)  ROM 0x5c30e tiled between 1052 and 1034: Throttle_Diff_Threshold, where cm848_filterCommandedThrottle
                  ends a throttle transient.
Idempotent.  usage: apply_r50a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp = os.path.join(CM, "output/global_variables.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 50"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def cite(block, off, a):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    size = int(size)
    v = (int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + size], "big") if 0x3FA000 <= a < 0x3FA000 + len(ram)
         else int.from_bytes(rom[a:a + size], "big"))
    if sign == "S" and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "HEX", "") else ""
    return (f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{'signed, ' if sign == 'S' else ''}{float(scale):g} per "
            f"count; {v} = {v * float(scale):.6g} here).")


g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "tsc1_lost_counter" in names:
    print("already applied")
    sys.exit(0)


def index():
    return {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}


idx = index()
mapping = ["address,name,old_label,kind,dims"]


def check(new):
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    names.add(new)


def rename(a, cur, new, text):
    p = g[idx[a]].split(",", 3)
    p += [""] * (4 - len(p))
    assert p[1] == cur, (a, p[1], cur)
    check(new)
    g[idx[a]] = f"{a},{new},{p[2]},{text} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    mapping.append(f"{a},{new},{cur},global,1")


def add(a, new, typ, text, rendered):
    global idx
    assert a not in idx, a
    check(new)
    later = sorted(x for x in idx if int(x, 16) > int(a, 16))
    g.insert(idx[later[0]] if later else len(g), f"{a},{new},{typ},{text} ({R})")
    idx = index()
    if rendered:
        mapping.append(f"{a},{new},{rendered},global,1")


TILE = " The block fills the gap between dumped-table blocks {} and {} exactly."
FN = "cm848_updateParkNeutralFlagAndTsc1Activity"
rename("0x004086c8", "j1939_tsc1_active_duration_reload", "tsc1_lost_time_limit",
       cite(0x8A7B, 0, 0x4086c8) + TILE.format("8A2A", "8C49") + f" {FN}: once tsc1_lost_counter reaches it, "
       "tsc1_lost_management_active_flag is set (PTP mode = the backup powertrain protection)")
add("0x004086ca", "tsc1_lost_counter_initial_value", "word",
    cite(0x8A7B, 2, 0x4086ca) + " The TSC1 start-up function loads tsc1_lost_counter from it (lhz)", "DAT_004086ca")
rename("0x004086cc", "j1939_tsc1_timing_fault_counter_threshold", "tsc1_lost_intermittent_time_limit",
       cite(0x8A7B, 4, 0x4086cc) + f" {FN}: each time tsc1_lost_counter equals it, tsc1_lost_intermittent_count counts")
add("0x004086ce", "tsc1_lost_maximum_intermittent_count", "word",
    cite(0x8A7B, 6, 0x4086ce) + f" {FN}: above it, an intermittent TSC1 also sets tsc1_lost_management_active_flag "
    "(lhz)", "DAT_004086ce")
add("0x004086d0", "park_neutral_status_from_pci_message_0e_enable", "word",
    cite(0x8A7B, 8, 0x4086d0) + " No direct access found (raw lis + displacement scan of the ROM and the live flash2)",
    None)
rename("0x003fcd7a", "j1939_tsc1_active_duration_counter", "tsc1_lost_counter",
       f"e2m 8A7B's 'TSC Lost counter': {FN} counts it up while no TSC1 control is active (or the request timed out) and "
       "down while one is, between 0 and tsc1_lost_time_limit; tsc1_lost_counter_initial_value seeds it at start-up")
rename("0x003fcd7c", "j1939_tsc1_timing_fault_cycle_count", "tsc1_lost_intermittent_count",
       f"{FN} counts it each time tsc1_lost_counter equals tsc1_lost_intermittent_time_limit; above "
       "tsc1_lost_maximum_intermittent_count the TSC1 counts as lost (e2m 8A7B +6)")
add("0x0005c30e", "commanded_throttle_difference_threshold", "i16",
    cite(0x1585, 0, 0x5c30e) + TILE.format("1052", "1034") + " cm848_filterCommandedThrottle ends a throttle transient "
    "once the error is back within +- it (lha x2; a signed record, so i16)", "DAT_0005c30e")
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} map entries")
