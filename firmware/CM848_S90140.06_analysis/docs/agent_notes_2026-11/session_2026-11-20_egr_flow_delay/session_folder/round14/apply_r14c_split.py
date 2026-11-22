"""Round 14 stage C (types): the dword governor_speed_limit_exceeded_flag at 0x3faf7a is two words. Every access is a
halfword (sth @ 0x291f0 / lhz @ 0x29a8c for +0, sth @ 0x29c5c / lhz @ 0x2981c for +2); the decompile read them as
._0_2_ / ._2_2_ pieces. The legacy offcut row 'governor_speed_limit_exceeded_flag+2' at 0x3faf7c becomes the second
word. Its own build: the range is inside the RAM copy of dispatchCanMessageHandlers (0x3fae3c-0x3fafd0), where
scalar widths are the cautioned case. String edits (global_variables.csv takes commas unquoted).
usage: apply_r14c_split.py <repo> <proof_map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gv = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(gv).read().split("\n")
OLD = "governor_speed_limit_exceeded_flag"
NEW = {
    "0x003faf7a": ("low_speed_governor_extended_idle_conditions_flag",
        "Word (sth @ 0x291f0, lhz @ 0x29a8c): 1 while the extended idle conditions hold - "
        "cm848_selectLowSpeedGovernorDesiredReferenceSpeed: the LSG in control, the engine running in park or neutral, "
        "the battery below low_speed_governor_extended_idle_battery_temperature and the coolant below "
        "low_speed_governor_extended_idle_coolant_temperature, the brake switch (11) and switch 2 off, the intake "
        "manifold temperature at or below low_speed_governor_extended_idle_intake_manifold_temperature, the "
        "accelerator at idle and the vehicle speed at or below low_speed_governor_extended_idle_road_speed; "
        "low_speed_governor_extended_idle_timer counts while it is 1, and the slew's extended idle status needs it "
        f"(was the low half of {OLD}, a dword; round 14)"),
    "0x003faf7c": ("low_speed_governor_base_reference_speed_boot_copy",
        "Word (sth @ 0x29c5c in cm848_initializeLowSpeedGovernorReferenceSpeed, lhz @ 0x2981c): "
        "low_speed_governor_base_reference_speed_cal as it was at boot. While the EEPROM value differs from it (a "
        "tool changed the idle speed), the desired speed is the base (state 5) - only the initializer writes it "
        f"(was the high half of {OLD}, and the legacy row {OLD}+2; round 14)"),
}
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in NEW:
        addr, name, typ, comment = (l.split(",", 3) + ["", "", ""])[:4]
        if a == "0x003faf7a":
            assert name == OLD and typ == "dword", (name, typ)
        else:
            assert name == OLD + "+2" and typ == "", (name, typ)
        new, text = NEW[a]
        lines[i] = ",".join([addr, new, "word", text + (f" | earlier note: {comment}" if comment else "")])
        done += 1
assert done == 2, done
open(gv, "w").write("\n".join(lines))
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind\n")
    f.write(f"0x003faf7a,{NEW['0x003faf7a'][0]},{OLD}._0_2_,global\n")
    f.write(f"0x003faf7c,{NEW['0x003faf7c'][0]},{OLD}._2_2_,global\n")
print("split into two words; proof map written")
