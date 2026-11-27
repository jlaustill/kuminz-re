"""Round 20 stage B (types): algorithm_enable_flags_3_t, a word bitfield on algorithm_enable_flags_3_cal (0x3fd5a2), one
bit per e2m 106B +8 record (column 11 is the mask). Every code use is a masked read, so the bits render without
pieces. The ANC bits keep reserved_bit_N names (the e2m never spells ANC out, and no code reads them); bit 8 has no
record but its readers prove it. usage: apply_r20b.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
BITS = {
    3: ("idle_speed_adjust_enable", "e2m 106B +8 Idle_Speed_Adjust_Enable (mask 0x8); no reader in this build"),
    4: ("power_take_off_enable", "e2m PTO_Enable (0x10): the power take-off governor state machine, its fueling and the "
        "PGN 65264 / 65265 broadcasts need it; set on this truck"),
    6: ("cruise_control_enable", "e2m Cruise_Control_Enable (0x40): cruise standby / denied status, PGN 65261 / 65265; set "
        "on this truck"),
    7: ("road_speed_governor_enable", "e2m Road_Speed_Governor_Enable (0x80): cm848_calculateRoadSpeedGovernorFueling gives "
        "no limit (0x1700) while it is clear; PGN 65261; set on this truck"),
    8: ("road_speed_governor_without_droops_below_top_gear", "No e2m record (0x100): while it is set and the drivetrain is not "
        "in top gear, cm848_calculateRoadSpeedGovernorFueling cuts to 0 / no limit at the reference speed and "
        "cm848_selectCruiseGovernorGainSet zeroes the droop delta; clear on this truck"),
    10: ("cruise_governor_droop_enable", "e2m Cruise_RSG_Droop_Enable (0x400); no reader in this build"),
    12: ("reserved_bit_12", "e2m ANC_Fuel_Algorithm_Enable (0x1000); no reader (the ANC stage is compiled out)"),
    13: ("reserved_bit_13", "e2m ANC_Timing_Algorithm_Enable (0x2000); no reader (the ANC stage is compiled out)"),
    14: ("reserved_bit_14", "e2m ANC_Speed_Algorithm_Enable (0x4000); no reader (the ANC stage is compiled out)"),
    15: ("cruise_save_set_speed_at_power_down_enable", "e2m Cruise_Save_Set_Speed_On_Poweroff_Enable (0x8000): "
         "cm848_saveCruiseSetSpeedForPowerDown saves 0 while it is clear; clear on this truck"),
}
rows = ["# algorithm_enable_flags_3_t: algorithm enable flags word 3 (EEPROM 0x120, e2m 106B +8; PR #53 round 20); 0xd0 "
        "in the dump"]
for bit in range(16):
    name, comment = BITS.get(bit, (f"reserved_bit_{bit}", "no e2m record; no reader"))
    assert '"' not in comment
    rows.append(f'algorithm_enable_flags_3_t,,{name},bitfield:1@{bit},{2 if bit == 0 else 0},"{comment}",,verified')
sp = os.path.join(out, "structure_definitions.csv")
t = open(sp).read()
assert "algorithm_enable_flags_3_t" not in t
anchor = t.index("# algorithm_enable_flags_4_t")
open(sp, "w").write(t[:anchor] + "\n".join(rows) + "\n" + t[anchor:])
gp = os.path.join(out, "global_variables.csv")
lines = open(gp).read().split("\n")
k = [i for i, l in enumerate(lines) if l.startswith("0x003fd5a2,algorithm_enable_flags_3_cal,word,")]
assert len(k) == 1
addr, name, typ, comment = lines[k[0]].split(",", 3)
lines[k[0]] = ",".join([addr, name, "algorithm_enable_flags_3_t", comment + " | typed algorithm_enable_flags_3_t in PR #53 round 20 (was word)"])
open(gp, "w").write("\n".join(lines))
print("16-bit struct, 1 row typed")
