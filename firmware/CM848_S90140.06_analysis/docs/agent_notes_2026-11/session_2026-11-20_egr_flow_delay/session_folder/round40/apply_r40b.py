"""Round 40 stage B: feature_selection_bits_cal (EEPROM 0x480) as a bitfield struct. The application only tests it
with masks (0x01 / 0x02 / 0x04 / 0x08 / 0x10); the SCI EEPROM setting path writes the whole byte through a pointer.
A type-only template feature_selection_bits_t (one byte) and the global typed with it. Idempotent.
usage: apply_r40b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "feature_selection_bits_t"
FIELDS = [
    ("power_take_off_cab_governor_enable", 0, 1,
     "mask 0x01: cm848_runPowerTakeOffGovernorStateMachine enters the cab (set / resume) governor only while it is "
     "set (with algorithm_enable_flags_3_cal.power_take_off_enable)"),
    ("power_take_off_remote_governor_enable", 1, 0,
     "mask 0x02: cm848_runPowerTakeOffGovernorStateMachine's remote switch path needs it"),
    ("oil_change_monitor_feature_enable", 2, 0,
     "mask 0x04: cm848_updateOilChangeMonitor runs only while it is set (with "
     "algorithm_enable_flags_12_cal.oil_change_monitor_enable)"),
    ("overdrive_initial_flags_option", 3, 0,
     "mask 0x08: cm848_initializeTransmissionControl starts transmission_control_flags.overdrive_flags with 0x0a while "
     "it is set and 0x08 while it is clear (which overdrive_flags bit 1 is stays unproven)"),
    ("water_in_fuel_sensor_second_configuration", 4, 0,
     "mask 0x10: while it is clear cm848_processWaterInFuelChannel / cm848_initializeWaterInFuelChannel use the "
     "*_feature_bit_4_off_* configuration and tables"),
    ("reserved_bit_5", 5, 0, "mask 0x20: no reader"),
    ("reserved_bit_6", 6, 0, "mask 0x40: no reader"),
    ("reserved_bit_7", 7, 0, "mask 0x80: no reader"),
]
sp = os.path.join(out, "structure_definitions.csv")
s = open(sp).read()
if f"\n{T}," not in s:
    rows = [f'{T},,{n},bitfield:1@{b},{size},"{c} (PR #53 round 40)",,verified' for n, b, size, c in FIELDS]
    s = s.rstrip("\n") + "\n" + "\n".join(rows) + "\n"
    open(sp, "w").write(s)
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read()
old = "0x003fd902,feature_selection_bits_cal,byte,"
new = f"0x003fd902,feature_selection_bits_cal,{T},"
if new not in g:
    assert g.count(old) == 1
    g = g.replace(old, new)
    open(gp, "w").write(g)
print("stage B applied")
