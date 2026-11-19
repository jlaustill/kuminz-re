"""Stage 5b (fix forward on PR #52): the EMO auxiliary emission control device (AECD) family.

Stage 5 named the three AECD flags *_emission_control_active_flag. An AECD relaxes the emission control (it puts its
NOx emission level cap into the max-select of fuel_demandMin_maxSelect_rateLimit), so that name reads backwards. The
family already has wave 9's condensation_protection_active_flag / condensation_protection_emission_level_cap, so the
words follow it, with the condition from the e2m AECD name:
- 19B2 / 19B3 Engine Starting and Warmup Protection;
- 19B0 / 19B1 Extended Idle and PTO Protection (the timer runs only while the low speed governor or the power take-off
  governor has the fueling);
- 19A1-19A4 extreme ambient overheat protection (a coolant hysteresis 217 / 222 degF; the old names called it a cold
  start boost override).
EL = emission level: the same family's C_EMO_Condensation_AECD_Cap is the "NOx cap value to be used when condensation
triggers EGR off". It also adds the four ROM calibrations the code reads, renames the three update functions, and
fixes three plate shorthand tokens. Writes map_stage5b.csv for the proof.
usage: apply_stage5b_aecd.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
OFF = "algorithm_enable_flags_20_cal"
CAP_NOTE = ("EL = emission level: the same family's C_EMO_Condensation_AECD_Cap is the 'NOx cap value to be used when "
            "condensation triggers EGR off'")

GLOBALS = {  # address: (old name, new name, new type or None, new comment)
    "0x0040a5f4": ("engine_start_emission_control_active_flag", "engine_start_warmup_protection_active_flag", None,
                   "e2m 19B3 +0 EMO_Engine_Start_AECD_Active 'Indication of Engine Starting and Warmup Protection AECD "
                   f"active': 1 while {OFF} bit 0x1000 is set and engine_is_starting_flag is 1 (CRANKING / JUMP_START). "
                   "An auxiliary emission control device: while active it puts its NOx emission level cap into the "
                   "max-select of fuel_demandMin_maxSelect_rateLimit. The bit is clear on this truck (0x0100) "
                   "(was cold_start_phase26_fuel_mode_flag)"),
    "0x0040a5f6": ("engine_start_emission_level_cap", "engine_start_warmup_protection_emission_level_cap", None,
                   "e2m 19B3 +2 EMO_Engine_Start_Cap_EL 'Cap EL output from Engine Starting and Warmup Protection AECD "
                   "active' (1/1024): engine_start_warmup_protection_emission_level_cap_when_active while "
                   "engine_start_warmup_protection_active_flag is 1, else 0; fuel_demandMin_maxSelect_rateLimit takes the "
                   f"largest of it and the other AECD caps. {CAP_NOTE} (was fuel_coldStart_phase26_demand_floor)"),
    "0x0040a5f8": ("extended_idle_emission_control_active_flag", "extended_idle_protection_active_flag", None,
                   "e2m 19B1 +0 EMO_Extended_Idle_AECD_Active 'Indication of Extended Idle and PTO Protection AECD "
                   "active': 1 once extended_idle_timer reaches extended_idle_time_threshold "
                   "(was cold_start_phase3_fuel_mode_count_met_flag)"),
    "0x0040a5fa": ("extended_idle_emission_level_cap", "extended_idle_protection_emission_level_cap", None,
                   "e2m 19B1 +2 EMO_Extended_Idle_Cap_EL 'Cap EL output from Extended Idle and PTO Protection active' "
                   "(1/1024): extended_idle_protection_emission_level_cap_when_active while "
                   "extended_idle_protection_active_flag is 1, else 0 - an input of the max-select in "
                   f"fuel_demandMin_maxSelect_rateLimit. {CAP_NOTE} (was cold_start_phase3_fuel_demand_floor)"),
    "0x0040a5fc": ("extreme_ambient_emission_control_active_flag", "extreme_ambient_overheat_protection_active_flag",
                   None,
                   "e2m 19A4 +0 EMO_Extreme_Amb_AECD_Active 'EMO extreme ambient AECD active': 1 while "
                   f"{OFF} bit 0x200 is set and extreme_ambient_coolant_temperature_high_flag is 1. The bit is clear on "
                   "this truck (was cold_start_boost_override_active_flag)"),
    "0x0040a5fe": ("extreme_ambient_emission_level_cap", "extreme_ambient_overheat_protection_emission_level_cap", None,
                   "e2m 19A4 +2 EMO_Extreme_Amb_Cap_EL 'Extreme ambient overheat cap value' (1/1024): the "
                   "coolant_temperature_selected lookup of extreme_ambient_overheat_protection_cap_axis / _values while "
                   "extreme_ambient_overheat_protection_active_flag is 1, else 0 - an input of the max-select in "
                   f"fuel_demandMin_maxSelect_rateLimit. {CAP_NOTE} (was cold_start_boost_override_fuel_demand)"),
    "0x003fbc9c": ("extended_idle_timer", "extended_idle_timer", None,
                   "The extended idle time (0.1 s, the unit of its threshold): +2 per pass up to "
                   f"extended_idle_time_threshold while {OFF} bit 0x800 is set, engine_is_active_flag is 1 and the low "
                   "speed governor or the power take-off governor has the fueling "
                   "(fuel_demand_arbitrated_state_snapshot); 0 otherwise. The bit is clear on this truck (no e2m record) "
                   "(was cold_start_phase3_fuel_mode_count)"),
    "0x00406570": ("extended_idle_time_threshold", "extended_idle_time_threshold", None,
                   "e2m 19B0 +2 C_EMO_Extended_Idle_Timer 'Engine is Extended Idle if it is idling more than this "
                   "calibrated time limit' (0.1 s; 3000 = 300 s here) - ROM copy, no _cal "
                   "(was cold_start_phase3_fuel_mode_count_max)"),
    "0x003fbca2": ("cold_start_boost_demand_above_threshold_flag", "extreme_ambient_coolant_temperature_high_flag",
                   None,
                   "The extreme ambient overheat hysteresis: 1 once coolant_temperature_selected reaches "
                   "extreme_ambient_overheat_protection_on_coolant_temperature (222 degF here), 0 again at or below "
                   "extreme_ambient_overheat_protection_off_coolant_temperature (217 degF) - no e2m record "
                   "(was cold_start_boost_demand_above_threshold_flag)"),
    "0x00406576": ("cold_start_override_fuel_demand_floor_axis", "extreme_ambient_overheat_protection_cap_axis", None,
                   "Lookup table - x axis of 16 breakpoints after its byte-length word - read by "
                   "cm848_updateColdStartBoostOverrideFuelDemand - e2m 19A2 C_EMO_Cap_Coolant_Tmptr_Axis (1/64 degF, "
                   "signed: -50 to 250 degF in 20 degF steps here) (was cold_start_override_fuel_demand_floor_axis)"),
    "0x00406598": ("cold_start_override_fuel_demand_floor_values", "extreme_ambient_overheat_protection_cap_values", None,
                   "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word - read by "
                   "cm848_updateColdStartBoostOverrideFuelDemand - e2m 19A3 C_EMO_Extreme_Amb_Cap_Table 'Extreme "
                   "ambient overheat cap table' (1/1024; all 1.0 here) (was cold_start_override_fuel_demand_floor_values)"),
}
NEW_ROWS = [  # (after this address, address, name, type, comment)
    ("0x00406570", "0x0040656c", "engine_start_warmup_protection_emission_level_cap_when_active", "word",
     "e2m 19B2 +0 C_EMO_Engine_Start_Cap_EL 'Cap EL calibration of Engine Starting and Warmup Protection AECD active' "
     "(1/1024; 1024 = 1.0 here): read once (lhz) by cm848_updateEngineStartWarmupProtection - ROM copy, no _cal "
     "(new row 2026-11-19)"),
    ("0x0040656c", "0x0040656e", "extended_idle_protection_emission_level_cap_when_active", "word",
     "e2m 19B0 +0 C_EMO_Extended_Idle_Cap_EL 'Cap EL calibration of Extended Idle and PTO Protection AECD' (1/1024; "
     "1024 = 1.0 here): read once (lhz) by cm848_updateExtendedIdleProtection - ROM copy, no _cal (new row 2026-11-19)"),
    ("0x0040656e", "0x00406572", "extreme_ambient_overheat_protection_off_coolant_temperature", "i16",
     "e2m 19A1 +0 C_EMO_Extreme_Amb_AECD_Off_Thd 'Low CT threshold to enable extreme ambient overheat protection' "
     "(1/64 degF, lha; 13888 = 217 degF here): extreme_ambient_coolant_temperature_high_flag clears at or below it - "
     "ROM copy, no _cal (new row 2026-11-19)"),
    ("0x00406572", "0x00406574", "extreme_ambient_overheat_protection_on_coolant_temperature", "i16",
     "e2m 19A1 +2 C_EMO_Extreme_Amb_AECD_On_Thd 'High CT threshold to enable extreme ambient overheat protection' "
     "(1/64 degF, lha; 14208 = 222 degF here): extreme_ambient_coolant_temperature_high_flag sets at or above it - "
     "ROM copy, no _cal (new row 2026-11-19)"),
]
FUNCTIONS = {  # address: (old name, new name, plate comment)
    "0x005055a0": ("fuel_coldStart_phase26_flagUpdate", "cm848_updateEngineStartWarmupProtection",
                   "The e2m EMO Engine Starting and Warmup Protection AECD (blocks 19B2 / 19B3): "
                   f"engine_start_warmup_protection_active_flag is 1 while {OFF} bit 0x1000 is set and "
                   "engine_is_starting_flag is 1 (CRANKING / JUMP_START); then "
                   "engine_start_warmup_protection_emission_level_cap = "
                   "engine_start_warmup_protection_emission_level_cap_when_active (1.0 here), else 0. The bit is clear "
                   "on this truck (0x0100), so it never activates (was fuel_coldStart_phase26_flagUpdate)"),
    "0x00505600": ("governor_coldStart_fuelModeCounter_update", "cm848_updateExtendedIdleProtection",
                   "The e2m EMO Extended Idle and PTO Protection AECD (blocks 19B0 / 19B1): extended_idle_timer counts up "
                   f"by 2 per pass to extended_idle_time_threshold (3000 = 300 s here) while {OFF} bit 0x800 is set, "
                   "engine_is_active_flag is 1 and fuel_demand_arbitrated_state_snapshot is "
                   "FUELING_STATE_LOW_SPEED_GOVERNOR or FUELING_STATE_POWER_TAKE_OFF, and is 0 otherwise; "
                   "extended_idle_protection_active_flag is 1 once it reaches the threshold, and then "
                   "extended_idle_protection_emission_level_cap = "
                   "extended_idle_protection_emission_level_cap_when_active (1.0 here), else 0. The bit is clear on this "
                   "truck (was governor_coldStart_fuelModeCounter_update)"),
    "0x005056f8": ("cm848_updateColdStartBoostOverrideFuelDemand", "cm848_updateExtremeAmbientOverheatProtection",
                   "The e2m EMO extreme ambient overheat protection AECD (blocks 19A1-19A4), a hot-coolant protection: "
                   "extreme_ambient_coolant_temperature_high_flag sets at coolant_temperature_selected >= "
                   "extreme_ambient_overheat_protection_on_coolant_temperature (222 degF) and clears at <= "
                   "extreme_ambient_overheat_protection_off_coolant_temperature (217 degF); with "
                   f"{OFF} bit 0x200 it makes extreme_ambient_overheat_protection_active_flag 1, and "
                   "extreme_ambient_overheat_protection_emission_level_cap is the coolant temperature lookup of "
                   "extreme_ambient_overheat_protection_cap_axis / _values (C_EMO_Extreme_Amb_Cap_Table, all 1.0 here) "
                   "while active, else 0. The bit is clear on this truck (was "
                   "cm848_updateColdStartBoostOverrideFuelDemand, before that fuel_demandBoost_overrideFlag_lookup)"),
}
TEXT = [  # (file, exact old text, new text)
    ("function_renames.csv", "(fuel_pressure_setpoint_base_map / _map_1 to _map_4)",
     "(fuel_pressure_setpoint_base_map_grid and fuel_pressure_setpoint_map_1_grid to fuel_pressure_setpoint_map_4_grid)"),
    ("function_renames.csv", "answers a request in pci_receive_message_0 (header 68 6A",
     "answers a request in pci_receive_message_table[0] (header 68 6A"),
    ("function_renames.csv", "with pci_transmit_message_8 (header 48 6B)",
     "with pci_transmit_message_table[8] (header 48 6B)"),
    ("global_variables.csv",
     "the other protection floors (cold start phase 2.6 / 3, boost override, sensor validation, cylinder check, blend)",
     "the other AECD caps and floors (the engine start and warmup / extended idle / extreme ambient overheat protection "
     "caps, sensor validation, cylinder check, blend)"),
]


def rows(path):
    return open(path, newline="").read().split("\n")


def write(path, lines):
    open(path, "w", newline="").write("\n".join(lines))


path = os.path.join(OUT, "global_variables.csv")
lines = rows(path)
index = {line.split(",", 1)[0]: i for i, line in enumerate(lines) if line.startswith("0x")}
for address, (old, new, new_type, comment) in GLOBALS.items():
    i = index[address]
    a, name, typ, _ = lines[i].split(",", 3)
    assert name == old, (address, name, old)
    lines[i] = ",".join([a, new, new_type or typ, comment])
for after, address, name, typ, comment in NEW_ROWS:
    assert address not in index, address
    i = next(k for k, line in enumerate(lines) if line.split(",", 1)[0] == after)
    lines.insert(i + 1, ",".join([address, name, typ, comment]))
write(path, lines)

path = os.path.join(OUT, "function_renames.csv")
lines = rows(path)
for address, (old, new, plate) in FUNCTIONS.items():
    i = next(k for k, line in enumerate(lines) if line.split(",", 1)[0] == address)
    parts = lines[i].split(",", 2)
    assert parts[1] == old, (address, parts[1], old)
    lines[i] = ",".join([address, new, plate])
write(path, lines)
for name in ("function_definitions.csv", "local_variables.csv"):
    text = open(os.path.join(OUT, name)).read()
    assert not any(f"{address}," in text for address in FUNCTIONS), name

for name, old, new in TEXT:
    path = os.path.join(OUT, name)
    text = open(path, newline="").read()
    assert text.count(old) == 1, (name, old[:50], text.count(old))
    open(path, "w", newline="").write(text.replace(old, new))

with open(os.path.join(here, "map_stage5b.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, (old, new, _) in FUNCTIONS.items():
        f.write(f"{address},{new},{old},function\n")
    for address, (old, new, *_rest) in GLOBALS.items():
        if old != new:
            f.write(f"{address},{new},{old},global\n")
    for _after, address, name, *_rest in NEW_ROWS:
        f.write(f"{address},{name},DAT_{int(address, 16):08x},global\n")
print(f"stage 5b: {len(FUNCTIONS)} functions, {sum(o != n for o, n, *_ in GLOBALS.values())} renamed globals, "
      f"{len(NEW_ROWS)} new rows, {len(TEXT)} text fixes")
