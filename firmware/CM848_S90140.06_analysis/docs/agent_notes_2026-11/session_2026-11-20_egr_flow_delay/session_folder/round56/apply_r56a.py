"""Round 56 stage A: the last protection_* names are the discrete output overrides (e2m 8B5B / 8C29) and two
legacy helpers.
- e2m 8B5B (12 bytes: the override priority word + 5 enable / value byte pairs) and 8C29 (6 more pairs) are not in the
  parameter ID table. They tile the gap between 8A79 (coolant_overheat_level_time_limits - ends at 0x408787) and 8A5F
  (round 52 - starts at 0x4087a0) exactly, and every pair is passed with the logical output its e2m record names: the
  output's own module and its round 32 read-back check use the same number.
- The 11 pairs become discrete_output_override_t instances named from the round 32 read-back stems; the previous-pass
  enable words at 0x3fcde0 (not in block order) take the same stems.
- The decimal suffix trap: protection_fault_enable_event11 is logical output 11 (0xb) but protection_event_11_reset
  drives output 0x11 (17). The output table below comes from the call arguments in the decompile and is asserted.
Idempotent.  usage: apply_r56a.py <repo> <map.csv> <params.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows  # noqa: E402

repo, map_path, params_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 56"
fr_path = os.path.join(OUT, "function_renames.csv")
fr = open(fr_path).read()
if "cm848_applyDiscreteOutputOverride," in fr:
    print("already applied")
    sys.exit(0)
cpp = open(os.path.join(OUT, "cm848_rom.ghidra.cpp")).read()
i = cpp.index("// Function: protection_fault_snapshot_update @")
body = cpp[i:cpp.index("// Function: ", i + 10)]
calls = re.findall(r"engine_protection_faultSeverity_manage\s*\(\s*(0x[0-9a-f]+),\s*(\w+),\s*(\w+),\s*(\w+)\)", body)
assert len(calls) == 11, calls

rec = Records(repo)
g = Rows(repo, R)
stems = {}
for line in g.g:
    p = line.split(",", 3)
    if len(p) == 4 and p[1].endswith("_output_read_back_check"):
        stems[int(re.search(r"logical output (\d+)", p[3]).group(1))] = p[1][:-len("_output_read_back_check")]
assert len(stems) == 11, stems
E2M = {11: (0x8B5B, 0x2, "Engine_Brake_Driver_1"), 38: (0x8B5B, 0x4, "AC_Discrete_Output"),
       43: (0x8B5B, 0x6, "Cold_Start_Aid_1_Driver"), 44: (0x8B5B, 0x8, "Cold_Start_Aid_2_Driver"),
       53: (0x8B5B, 0xA, "Lift_Pump_Driver"), 21: (0x8C29, 0x0, "Cruise_SC_Source_Driver"),
       20: (0x8C29, 0x2, "Cruise_Vacuum_Driver"), 19: (0x8C29, 0x4, "Cruise_Vent_Driver"),
       17: (0x8C29, 0x6, "Transmission_Overdrive_Driver"), 18: (0x8C29, 0x8, "Transmission_TCC_Driver"),
       16: (0x8C29, 0xA, "Transmission_VFS_Battery_Driver")}
BASE = {0x8B5B: 0x408788, 0x8C29: 0x408794}
by_name = {line.split(",")[1]: line[:10] for line in g.g if line.startswith("0x")}
PLACEMENT = ("e2m 8B5B and 8C29 are not in the parameter ID table. They are placed by tiling - between 8A79 "
             "(coolant_overheat_level_time_limits - ends at 0x408787) and 8A5F (round 52 - starts at 0x4087a0) the "
             "12 bytes of 8B5B and then the 12 of 8C29 fill the gap exactly - and by meaning: "
             "cm848_applyDiscreteOutputOverrides passes every enable / value pair with the logical output its e2m record "
             "names (the output's own module and its round 32 read-back check use the same number).")
params = ["function,old,new"]

# the priority word
g.rename(rec, "0x00408788", "protection_fault_severity_code", "discrete_output_override_priority", 0x8B5B, 0,
         "The priority cm848_applyDiscreteOutputOverride requests each overridden output with - "
         "cm848_setLogicalOutputRequest / cm848_clearLogicalOutputRequest write only when it is at least the output's "
         "stored request priority - and whose low byte it compares with that priority on release (lhz). "
         + PLACEMENT)
LIFT_PUMP = (" This is the driver-level override. The lift pump module's own override is lift_pump_override_enable / "
             "lift_pump_override_state (e2m 8A6F) - which cm848_controlLiftPump applies.")
for hex_out, enable_name, value_label, previous_name in calls:
    out = int(hex_out, 16)
    assert enable_name == f"protection_fault_enable_event{out}", (hex_out, enable_name)
    assert previous_name == f"protection_fault_prevEnable_event{out}", (hex_out, previous_name)
    block, off, driver = E2M[out]
    a = BASE[block] + off
    assert by_name[enable_name] == f"0x{a:08x}", (enable_name, by_name[enable_name], hex(a))
    assert value_label == f"DAT_{a + 1:08x}" and not g.has(f"0x{a + 1:08x}"), (value_label, hex(a))
    assert rec.recs[(block, off)][0] == f"{driver}_Override_N", rec.recs[(block, off)]
    assert rec.recs[(block, off + 1)][0] == f"{driver}_User_Value_N", rec.recs[(block, off + 1)]
    stem = stems[out]
    instance = f"{stem}_output_override"
    g.check(instance)
    p = g.row(f"0x{a:08x}")
    assert p[1] == enable_name and p[2] == "byte", p
    text = (f"{rec.cite(block, off, a)} {rec.cite(block, off + 1, a + 1)} Logical output {out}'s discrete output "
            f"override ({stem}_output_read_back_check checks the same output): cm848_applyDiscreteOutputOverrides passes "
            f".enable and .value to cm848_applyDiscreteOutputOverride (lbz each).{LIFT_PUMP if out == 53 else ''}")
    g.g[g.idx[f"0x{a:08x}"]] = (f"0x{a:08x},{instance},discrete_output_override_t,{text} (was {enable_name} and "
                                f"{value_label}; {R}) | earlier note: {p[3]}")
    g.mapping.append(f"0x{a:08x},{instance}.enable,{enable_name},global,1")
    g.mapping.append(f"0x{a + 1:08x},{instance}.value,{value_label},global,1")
    pa = by_name[previous_name]
    assert g.row(pa)[2] == "word", g.row(pa)
    g.rename(rec, pa, previous_name, f"{instance}_enable_previous", None, None,
             f"The {stem} output override's .enable from the previous pass (logical output {out}): "
             "cm848_applyDiscreteOutputOverrides copies it after each pass and cm848_applyDiscreteOutputOverride "
             "releases the override's request priority on its falling edge - zeroed at boot by "
             "cm848_initializeDiscreteOutputOverrides (lhz / sth).")
# the lift pump module's own override: point at the driver-level one
k = g.idx[by_name["lift_pump_override_enable"]]
note = " Not the driver-level discrete output override lift_pump_output_override (e2m 8B5B +A / +B; PR #53 round 56)."
if note not in g.g[k]:
    g.g[k] = g.g[k].rstrip() + note
g.save(map_path)

# the struct type
sp = os.path.join(OUT, "structure_definitions.csv")
s = open(sp).read()
assert "discrete_output_override_t" not in s and s.endswith("\n")
s += ('discrete_output_override_t,,enable,byte,1,"A discrete output override\'s enable (e2m 8B5B / 8C29 '
      '<driver>_Override_N; 0 = not overridden): while it is set cm848_applyDiscreteOutputOverride requests the output '
      'from value at discrete_output_override_priority (PR #53 round 56)",,verified\n'
      'discrete_output_override_t,,value,byte,1,"The overridden output\'s requested state (e2m <driver>_User_Value_N): '
      'nonzero = on / 0 = off (PR #53 round 56)",,verified\n')
open(sp, "w").write(s)

# the functions
FUNCS = [
    ("0x00510978", "protection_event_11_reset", "cm848_initializeOverdriveSwitchAndShift",
     "Boot (cm848_applicationMain after cm848_initializeTransmissionControl): the initializer of "
     "cm848_processOverdriveSwitchAndShift - requests the overdrive solenoid (logical output 17) off at priority 0 and "
     "clears the converter clutch (bit 1) and overdrive (bit 2) solenoid test requests in "
     "transmission_shift_strategy_flags.service_test_request_flags - the two bits cm848_processOverdriveSwitchAndShift "
     "tests. The old name read output 0x11 as event 11"),
    ("0x00514048", "protection_accumulator_update", "cm848_addCoolantOverheatLevelTimersToTotals",
     "Power-down step of cm848_applicationMain and cm848_restartApplicationWithoutReset (after the healed fault "
     "clean-up and before cm848_saveCruiseSetSpeedForPowerDown): adds the five coolant_overheat_level_timers (e2m 8A72 "
     "+14..+24 CT_Derate_Timer1-5) to their lifetime totals in the EEPROM mirror at 0x3fee04 (e2m 8A73 "
     "CT_Derate_Timer1-5_Total - a dword per level). The totals stay untyped: the boot kernel's eeprom_shadow_header "
     "shares those addresses (round 53)"),
    ("0x0051408c", "engine_protection_faultSeverity_manage", "cm848_applyDiscreteOutputOverride",
     "One discrete output override (e2m 8B5B / 8C29). Parameters: param_1 = the logical output / param_2 = the "
     "override's .enable / param_3 = its .value / param_4 = the .enable of the previous pass (no prototype row: one "
     "naming them put a (uint) cast on all 33 call arguments of cm848_applyDiscreteOutputOverrides with any of "
     "dword / int32_t / undefined4). While param_2 is set it requests the output on (param_3 nonzero) or off (0) at "
     "discrete_output_override_priority through cm848_setLogicalOutputRequest / cm848_clearLogicalOutputRequest "
     "(each writes only when that priority is at least the output's stored request priority). When the enable falls "
     "(param_2 0 with param_4 set) it zeroes the output's request priority if it still equals the override priority "
     "- it leaves the request bit alone - so the output's own module takes over again. Called by "
     "cm848_applyDiscreteOutputOverrides"),
    ("0x00514108", "protection_fault_snapshot_update", "cm848_applyDiscreteOutputOverrides",
     "Periodic (cm848_periodicTaskGroup38_calibration17): applies the 11 discrete output overrides of e2m 8B5B / 8C29 "
     "through cm848_applyDiscreteOutputOverride - engine brake 1 (logical output 11) / air conditioning (38) / intake "
     "air heaters 1 and 2 (43 / 44) / lift pump (53) / cruise servo supply / vacuum / vent (21 / 20 / 19) / "
     "transmission overdrive (17) / torque converter clutch (18) / transmission relay (16) - then copies each .enable "
     "into its _enable_previous word"),
    ("0x00514394", "protection_fault_snapshot_initialize", "cm848_initializeDiscreteOutputOverrides",
     "Boot (cm848_applicationMain): zeroes the _enable_previous words of the 11 discrete output overrides "
     "(cm848_applyDiscreteOutputOverrides)"),
]
original = fr
mapping = []
for a, cur, new, plate in FUNCS:
    m = re.search(rf"^{a},{cur}(,[^\n]*)?$", fr, re.M)
    assert m, (a, cur)
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate, (a, plate[:60])
    old_plate = (m.group(1) or ",")[1:].strip()
    text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    fr = fr[:m.start()] + f"{a},{new},{text}" + fr[m.end():]
    mapping.append(f"{a},{new},{cur},function,1")
open(fr_path, "w").write(fr)
with open(map_path, "a") as fh:
    fh.write("\n".join(mapping) + "\n")

# No prototype for the per-output helper. Three builds committed one naming logical_output / override_enable /
# override_value / override_enable_previous: with dword, int32_t and undefined4 each one put a (uint) cast on all 33
# call arguments of cm848_applyDiscreteOutputOverrides (11 -> 44 casts; the callee rendered clean). A committed
# parameter locks the call's argument types; a cast per line was the reason round 51 rejected its bitfields. The plate
# names the parameters instead, and params.csv stays empty (prove_r56.sh then applies no parameter renames).
with open(params_path, "w") as fh:
    fh.write("\n".join(params) + "\n")
print(f"{len(calls)} overrides, {len(FUNCS)} functions, no prototype")
