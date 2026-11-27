"""Round 58 stage A: the last 12 protection_* globals (none in CM550, none in either CLAUDE.md), named from their code.
- Accesses come from scan_accesses_v2.py: D-form loads / stores / addi in both banks with lis / addi / ori / mr base
  tracking. It sees "lbz r11,19(r31)" off a struct base but not computed or loaded pointers, so "no other access
  found" is the claim, never "unused".
- The time-shared rows (the boot kernel's CMF / flash parameters inside the logical output line map) keep their kernel
  names and the kernel role leads the two renamed rows' comments; no retype (the line table's words and the polarity
  bytes overlap kernel rows).
- Two junk documentation rows are deleted: protection_b_state_t_003feebc.protection_b_pad_01 / _03 named the low bytes
  of exhaust_brake_switch_learned_flag_cal / executive_timing_overflow_count_cal (both accessed only as words) after a
  struct type that no longer exists; they rendered nowhere.
Idempotent.  usage: apply_r58a.py <repo> <map.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows  # noqa: E402

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 58"
fr_path = os.path.join(OUT, "function_renames.csv")
fr = open(fr_path).read()
if "cm848_initializeFrictionTorqueLookupCache," in fr:
    print("already applied")
    sys.exit(0)
rec = Records(repo)
g = Rows(repo, R)
SCAN = "no other access found by scan_accesses_v2.py (a base-tracking scan of both banks; computed pointers can escape it)"
SPARE = ("Set to 2 - the lookup cache start value - by cm848_initializeAllSpeedGovernorVariables (sth at {}) beside the "
         "lookup cache at 0x3fa0f0; " + SCAN + " and the RAM dump holds 2: likely the caches of lookups this build "
         "leaves out. In the time-shared ROM-to-RAM window.")
LINE = "logical_output_line_cal"
RENAMES = [
    ("0x003fa0f2", "protection_diag_state_a", "all_speed_governor_spare_word_1", None, None, SPARE.format("0xfaf0")),
    ("0x003fa0f4", "protection_diag_state_b", "all_speed_governor_spare_word_2", None, None, SPARE.format("0xfaf8")),
    ("0x003fa0f6", "protection_diag_state_c", "all_speed_governor_spare_word_3", None, None, SPARE.format("0xfb00")),
    ("0x003fdbd2", "protection_event_output_polarity_bits_cal", "logical_output_line_active_low_bits_cal", None, None,
     "TIME-SHARED: the boot reflash kernel uses the low half as its CMF high-voltage pulse step count "
     "(mpc555_initHardwareConfig / mpc555_cmfApplyHighVoltagePulse / mpc555_cmfEraseBlocks render ._0_2_ / ._2_2_). "
     f"Application: bit N (byte N / 8 - bit N % 8) set = logical output N is active low: "
     f"cm848_setLogicalOutputAndDriveLine drives its line ({LINE}[N]) low for on and cm848_clearLogicalOutputAndDriveLine "
     "drives it high for off; cm848_applyLogicalOutputRequests reads it too. The array spans 10 bytes to 0x3fdbdb (80 "
     "outputs) over the kernel's cmf_control_base / cmf_control_pulse_value rows, so this row stays a dword. Dump bytes "
     "00 00 1f 00 00 00 00 c0 00 00: outputs 16-20 / 62 / 63 are active low."),
    ("0x003fdbdc", "protection_event_output_line_cal", LINE, None, None,
     "TIME-SHARED: the boot reflash kernel's CMF parameters (0x3fdbde-0x3fdc2b) and flash poll settings (to 0x3fdc39) "
     f"sit inside this table, and their rows keep the kernel names. Application: {LINE}[N] = the discrete output line "
     "driven for logical output N (0 = none; 80 words to 0x3fdc7b): cm848_setLogicalOutputAndDriveLine / "
     "cm848_clearLogicalOutputAndDriveLine / cm848_applyLogicalOutputRequests / cm848_refreshOutputPortsAndReadback / "
     "cm848_checkDiscreteOutputReadBack / cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63 read it. Dump: "
     "entries 17 / 18 / 62 / 63 = lines 153 / 156 / 158 / 159. Nothing about protection events."),
    ("0x003fdc58", "qadc_adc_enable_flag", "logical_output_62_line_cal", None, None,
     f"Entry 62 of {LINE} (0x3fdbdc + 2 x 62), past the kernel's range, so it carries its own name: "
     "cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63 reads it (lhz 124(r6) at 0x4f0fc); " + SCAN +
     ". Dump: line 158 (0x9e). Nothing QADC about it (round 40 left it as a lead without evidence)."),
    ("0x0040b0fb", "protection_status_flags_b", "transmission_diagnostic_flags_6", 0x8C19, 0x13,
     "Bit 0 is set at the end of every cm848_selectTransmissionTemperatureInUse pass (lbz / stb 19(r31) off the 8C19 "
     "base 0x40b0e8 at 0x3f5a4 / 0x3f5ac); " + SCAN + ". 8C19 sits at 0x40b0e8 (round 9; +12 / +14 / +16 agree)."),
    ("0x003fd0b8", "protection_crank_event_counter", "injector_driver_booster_recharge_off_delay_counter", None, None,
     "Passes with the engine STOPPED (cm848_monitorFuelSystemHardwareShutdown; 0xffff while it is not stopped wraps to "
     "0 on the first stopped pass). At injector_driver_booster_recharge_off_delay (e2m 8041 +26 "
     "HPCR_Booster_Recharge_Off_Delay 'Time limit for booster cap to recharge without engine speed and key on') it "
     "clears bit 15 of TPUA_CH4_PARAM0 / tpu_channel_control.PARAM0 - the booster recharge stops - and "
     "fuel_system_hardware_shutdown_check_enable_flag. cm848_initializeInjectionHardware zeroes it. Dump: 9920 (key on "
     "with the engine stopped long past the delay)."),
    ("0x003fd0ba", "tpu_protection_enable_flag", "fuel_system_hardware_shutdown_check_enable_flag", None, None,
     "Enables the shutdown-time check of the booster capacitor QADC channels 54 / 55 against "
     "fuel_system_hardware_shutdown_error_threshold in cm848_monitorFuelSystemHardwareShutdown (engine SHUTDOWN with no "
     "cylinder cutout). 1 from cm848_initializeInjectionHardware; 0 once injector_driver_booster_recharge_off_delay_counter "
     "reaches the recharge-off delay (the capacitor is no longer recharged); 1 again on a RUNNING pass. Dump: 0."),
    ("0x003fd182", "protection_group29_coolant_temp_snapshot", "coolant_temperature_sensor_performance_snapshot_coolant_temperature",
     None, None,
     "coolant_temperature_sensor_filtered when the P0116 monitor (cm848_checkCoolantTemperatureSensorPerformance) takes "
     "its snapshot - with the intake manifold and battery temperatures beside it; the monitor compares it later (lha "
     "at 0x52e074 / 0x52e0a4)."),
    ("0x003fd188", "protection_group29_startup_timer_count", "coolant_temperature_sensor_performance_start_delay_countdown",
     None, None,
     "Loaded from coolant_temperature_sensor_performance_start_delay by "
     "cm848_initializeCoolantTemperatureSensorPerformanceMonitor; counts down while positive before the P0116 monitor "
     "runs; 0xffff once the snapshot is taken or the test ends. Dump: 10."),
    ("0x003fcbfa", "protection_rpm_correction_cached_axis_offsets",
     "combustion_torque_by_fuel_quantity_friction_cached_axis_offsets", None, None,
     "The x / y lookup cache of the three combustion_torque_by_fuel_quantity lookups in "
     "cm848_calculateFrictionNoLoadAndNetMachineTorque (the grid's other user cm848_calculateNetCombustionTorque keeps "
     "combustion_torque_by_fuel_quantity_cached_axis_offsets); cm848_initializeFrictionTorqueLookupCache sets both words "
     "to 2."),
]
for a, cur, new, block, off, text in RENAMES:
    g.rename(rec, a, cur, new, block, off, text)
for a, rendered, new, text in [
        ("0x003fd184", "DAT_003fd184", "coolant_temperature_sensor_performance_snapshot_intake_manifold_temperature",
         "intake_manifold_temperature_sensor_filtered at the P0116 monitor's snapshot (sth at 0x52df90); " + SCAN + "."),
        ("0x003fd186", "DAT_003fd186", "coolant_temperature_sensor_performance_snapshot_battery_temperature",
         "battery_temperature_sensor_filtered at the P0116 monitor's snapshot (sth at 0x52df84); " + SCAN + ".")]:
    g.add_text(a, new, "word", text, rendered)
# the two junk documentation rows
for a, name in (("0x003feebd", "protection_b_state_t_003feebc.protection_b_pad_01"),
                ("0x003feebf", "protection_b_state_t_003feebc.protection_b_pad_03")):
    p = g.row(a)
    assert p[1] == name and p[2] == "" and p[3] == "", p
    del g.g[g.idx[a]]
    g.reindex()
g.save(map_path)

FUNCS = [
    ("0x0052dd28", "cm848_initialization_group22_state", "cm848_initializeCoolantTemperatureSensorPerformanceMonitor",
     "Boot (cm848_applicationMain): the initializer of cm848_checkCoolantTemperatureSensorPerformance (P0116) - state "
     "0 - the start delay countdown from coolant_temperature_sensor_performance_start_delay - the snapshot dwell count / "
     "soak conditions flag / precheck flag cleared"),
    ("0x0050ebf0", "cm848_initThrottleRateFilterState", "cm848_initializeFrictionTorqueLookupCache",
     "Boot (cm848_applicationMain): sets both words of combustion_torque_by_fuel_quantity_friction_cached_axis_offsets "
     "to 2 (the lookup cache start) for cm848_calculateFrictionNoLoadAndNetMachineTorque just before it in ROM. Nothing "
     "about a throttle rate filter"),
    ("0x0004f0dc", "cm848_checkProtectionModeFlags", "cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63",
     "From cm848_applyLogicalOutputRequests: when logical outputs 17 and 62 both have lines (logical_output_line_cal) "
     "output 62 follows the overdrive solenoid request (17) and when 18 and 63 both have lines output 63 follows the "
     "converter clutch solenoid request (18) - both at priority 0. Active on this truck: lines 153 / 158 and 156 / 159. "
     "Entry 17 renders as the kernel's time-shared name qadc_queue_timing_config._0_2_"),
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
print(f"{len(RENAMES)} renamed, 2 added, 2 junk rows deleted, {len(FUNCS)} functions")
