"""Round 32 stage A: the discrete output read-back state.
- struct discrete_output_read_back_counters_t (4 bytes: on / off mismatch counts, high / low fault recovery counts)
  with 11 instances, one per checked output, and a word retry count per output (the first five outputs keep them in
  a run at 0x3fd295; the other six right after their counters, 6-byte slots);
- the 0x3fd284 BYTE_ row becomes a dotted documentation row of engine brake 1's counters; the 0x3fd298 BYTE_ row
  (inside engine brake 1's retry word) goes, its note moves to that word. Both boot-called kernel image addresses
  are covered by named data now, so the thunk stage keeps them as call overrides;
- the check's prototype (parameter names); fault bits 146 / 147. Appends map rows. Idempotent.
usage: apply_r32a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "discrete_output_read_back_counters_t"
OUTPUTS = [  # (counters address, retry address, name, logical output, line, high / low fault bits)
    (0x3fd27f, 0x3fd295, "air_conditioning", 38, 6, 371, 372),
    (0x3fd283, 0x3fd297, "engine_brake_1", 11, 5, 41, 42),
    (0x3fd287, 0x3fd299, "intake_air_heater_1", 43, 9, 295, 294),
    (0x3fd28b, 0x3fd29b, "intake_air_heater_2", 44, 10, 297, 296),
    (0x3fd28f, 0x3fd29d, "lift_pump", 53, 1, 386, 387),
    (0x3fd29f, 0x3fd2a3, "transmission_relay", 16, 22, 136, 137),
    (0x3fd2a5, 0x3fd2a9, "transmission_overdrive", 17, 23, 138, 139),
    (0x3fd2ab, 0x3fd2af, "transmission_torque_converter_clutch", 18, 24, 140, 141),
    (0x3fd2b1, 0x3fd2b5, "cruise_vent", 19, 25, 142, 143),
    (0x3fd2b7, 0x3fd2bb, "cruise_vacuum", 20, 27, 144, 145),
    (0x3fd2bd, 0x3fd2c1, "cruise_servo_supply", 21, 28, 146, 147),
]
FIELDS = [("on_mismatch_count", "commanded on but reads off: passes, up to the debounce threshold, before a retry"),
          ("off_mismatch_count", "commanded off but reads on: passes before the low fault bit sets"),
          ("high_fault_recovery_count", "passes with the read-back agreeing while the high fault is registered; it "
           "clears at the recovery threshold"),
          ("low_fault_recovery_count", "the same for the low fault")]
map_rows = []
# --- structure_definitions.csv: the type, its instances, fault bits 146 / 147
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
if not any(l.startswith(T + ",") for l in lines):
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: one discrete output's read-back check counters (cm848_checkDiscreteOutputReadBack parameters "
                 "5-8); 11 instances (PR #53 round 32)")
    for name, comment in FIELDS:
        lines.append(f"{T},0x{OUTPUTS[0][0]:08x},{name},byte,1,{comment},,verified")
    for c, r, name, out_no, line, hi, lo in OUTPUTS[1:]:
        lines.append(f"{T},0x{c:08x},,,,{name}_output_read_back_check - marker only,,verified")
    lines.append("")
BITS = {146: "cruise_servo_supply_driver_high_control_error", 147: "cruise_servo_supply_driver_low_control_error"}
for i, l in enumerate(lines):
    m = re.match(r"^(fault_bit_words_t,0x003fe974,)fault_(146|147)(,bitfield:1@\d+,[02],)(.*)$", l)
    if m:
        f = int(m.group(2))
        lines[i] = (f"{m.group(1)}{BITS[f]}{m.group(3)}logical output 21 (logical_output_request_bits_16_to_23_t."
                    f"cruise_servo_supply_request; e2m 1577 Cruise_SC_Source_Driver) is checked with this bit by "
                    f"cm848_checkDiscreteOutputReadBack (was fault_{f}; PR #53 round 32) | {m.group(4)}")
        map_rows.append(f"0x003fe974,{BITS[f]},fault_{f},field")
open(sd, "w").write("\n".join(lines))
# --- global_variables.csv
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
note_298 = ""
keep = []
for l in g:
    if l.startswith("0x003fd298,BYTE_003fd298,"):
        note_298 = l.split(",", 3)[3]
        continue
    if l.startswith("0x003fd284,BYTE_003fd284,"):
        old = l.split(",", 3)[3]
        keep.append(f"0x003fd284,engine_brake_1_output_read_back_check.off_mismatch_count,,(was BYTE_003fd284; PR #53 "
                    f"round 32) | earlier note: {old}")
        continue
    keep.append(l)
g = keep
NEW = []
for c, r, name, out_no, line, hi, lo in OUTPUTS:
    NEW.append((c, f"{name}_output_read_back_check", T,
                f"logical output {out_no} (read-back line {line}; faults {hi} / {lo}): its read-back check counters "
                f"(cm848_checkDiscreteOutputReadBack)"))
    extra = f" | TIME-SHARED: {note_298}" if r == 0x3fd297 and note_298 else ""
    NEW.append((r, f"{name}_output_read_back_retry_count", "word",
                f"logical output {out_no}: commanded-on-but-off retries of the output (up to "
                f"auxiliary_driver_toggle_count_limit before fault {hi}){extra}"))
for address, name, typ, comment in NEW:
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"{a},{name},{typ},{comment} (PR #53 round 32)")
    if typ == T:
        for k, (field, _) in enumerate(FIELDS):
            label = "BYTE_003fd284" if address + k == 0x3fd284 else f"DAT_{address + k:08x}"
            map_rows.append(f"0x{address + k:08x},{name}.{field},{label},global")
    else:
        map_rows.append(f"{a},{name},DAT_{address:08x},global")
open(gp, "w").write("\n".join(g))
# --- function_definitions.csv: the check's parameter names
fd = os.path.join(out, "function_definitions.csv")
f = open(fd).read().rstrip("\n").split("\n")
if not any(l.startswith("0x00537c64,") for l in f):
    P = [("logical_output", "int", "the logical output the check reads back"),
         ("read_back_line", "int", "the switch input line wired to the output's read-back"),
         ("high_fault_bit", "int", "set after the retries when commanded on but reads off"),
         ("low_fault_bit", "int", "set when commanded off but reads on"),
         ("on_mismatch_count", "byte*", "discrete_output_read_back_counters_t field"),
         ("off_mismatch_count", "byte*", "discrete_output_read_back_counters_t field"),
         ("high_fault_recovery_count", "byte*", "discrete_output_read_back_counters_t field"),
         ("low_fault_recovery_count", "byte*", "discrete_output_read_back_counters_t field"),
         ("retry_count", "word*", "the output's retry count")]
    f.append("# The discrete output read-back check (PR #53 round 32)")
    for k, (name, typ, comment) in enumerate(P):
        f.append(f"0x00537c64,cm848_checkDiscreteOutputReadBack,{k},{name},{typ},{comment}")
    open(fd, "w").write("\n".join(f) + "\n")
with open(map_path, "a") as fh:
    for r in map_rows:
        fh.write(r + "\n")
print(f"{len(NEW)} rows, {len(map_rows)} map rows")
