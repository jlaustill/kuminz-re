"""Stage 4 (shape): the three 2-D lookup caches as word[2], the void prototypes the asm proves (0x12ad4 / 0x12dc4 /
0x130dc), word returns for the two EGR flow source checks, and the e2m-signed pumping torque words as i16.
Usage: apply_stage4.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
CACHES = {  # first word: (old first, old second @ +2, new name, comment)
    0x003fa1ae: ("diag_state_group5_a_state", "diag_state_group5_b_state", "upstream_egr_corrected_flow_cached_axis_offsets",
                 "Lookup cache: the last x / y axis segment offsets (2 x index) that cm848_dualAxisTableInterpolation "
                 "keeps for upstream_egr_corrected_flow_grid (cm848_calculateUpstreamEgrMassFlow); "
                 "cm848_initializeEgrFlowEstimate presets both to 2. (were diag_state_group5_a_state / "
                 "diag_state_group5_b_state)"),
    0x003fa1b2: ("diag_state_group5_c_state", "diag_state_group5_d_state", "downstream_egr_corrected_flow_cached_axis_offsets",
                 "Lookup cache: the last x / y axis segment offsets (2 x index) that cm848_dualAxisTableInterpolation "
                 "keeps for downstream_egr_corrected_flow_grid (cm848_calculateDownstreamEgrMassFlow); "
                 "cm848_initializeEgrFlowEstimate presets both to 2. (were diag_state_group5_c_state / "
                 "diag_state_group5_d_state)"),
    0x003fa5f2: ("diag_state_group7_a_state", "diag_state_group7_b_state", "nominal_engine_delta_pressure_cached_axis_offsets",
                 "Lookup cache: the last x / y axis segment offsets (2 x index) that cm848_dualAxisTableInterpolation "
                 "keeps for nominal_engine_delta_pressure_grid (cm848_calculatePumpingTorqueAdjustment); "
                 "cm848_initializePumpingTorqueLookupCache presets both to 2. (were diag_state_group7_a_state / "
                 "diag_state_group7_b_state)"),
}
SIGNED = {0x00404ea0: "pumping_torque_maximum", 0x00404ea2: "pumping_torque_minimum",
          0x00404ea4: "pumping_torque_multiplier", 0x00404ea6: "pumping_torque_offset",
          0x00404ea8: "pumping_torque_engine_delta_pressure_deadband", 0x0040a418: "nominal_engine_delta_pressure",
          0x0040a41a: "pumping_torque_adjustment", 0x0040a41c: "pumping_torque_without_offset"}

path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
second = {a + 2: (o2, a) for a, (o1, o2, _, _) in CACHES.items()}
new_lines, done_cache, done_signed, removed = [], 0, 0, 0
for line in lines:
    p = line.split(",", 3)
    a = int(p[0], 16) if p[0].startswith("0x") else None
    if a in CACHES:
        o1, _, new, comment = CACHES[a]
        assert p[1] == o1 and p[2] == "word", p
        line = f"{p[0]},{new},word[2],{comment}"
        done_cache += 1
    elif a in second:
        assert p[1] == second[a][0] and p[2] == "word", p
        removed += 1
        continue
    elif a in SIGNED:
        assert p[1] == SIGNED[a] and p[2] == "word", p
        p[2] = "i16"
        line = ",".join(p)
        done_signed += 1
    new_lines.append(line)
assert (done_cache, removed, done_signed) == (3, 3, 8), (done_cache, removed, done_signed)
open(path, "w").write("\n".join(new_lines))

VOID = {
    0x00012ad4: ("cm848_calculateVolumetricEfficiency",
                 "Takes no parameters: r3 and r4 are written before any read (lis r3 @ 0x12b04, clrlwi r4 @ 0x12b0c); "
                 "the old boost_denominator / base_fueling rows were stale"),
    0x00012dc4: ("cm848_calculateChargeFlowEstimate",
                 "Takes no parameters: it never reads r3 / r4 (its caller cm848_calculateChargeFlows passes none); the "
                 "decompiler only showed two because cm848_calculateVolumetricEfficiency declared them"),
    0x000130dc: ("cm848_calculatePumpingTorqueAdjustment",
                 "Takes no parameters: r3 and r4 are written before any read (lis r3 @ 0x130fc, lis r4 @ 0x13104); the "
                 "old manifold_pressure / rpm rows were stale"),
}
RETURNS = {
    0x00012724: ("cm848_calculateDownstreamEgrFlowSource", "0 PRIMARY / 1 BACKUP (clrlwi r3,r4,16 @ 0x12770)"),
    0x00012778: ("cm848_calculateUpstreamEgrFlowSource", "0 PRIMARY / 1 BACKUP (clrlwi r3,r4,16)"),
}
path = os.path.join(out, "function_definitions.csv")
lines = open(path).read().split("\n")
drop = {0x00012ad4, 0x000130dc}
kept = []
dropped = 0
for line in lines:
    a = int(line.split(",", 1)[0], 16) if line.startswith("0x") else None
    if a in drop:
        dropped += 1
        continue
    assert a not in VOID and a not in RETURNS, line
    kept.append(line)
assert dropped == 4, dropped
rows = [f"0x{a:08x},{name},return,,void,{c}" for a, (name, c) in VOID.items()]
rows += [f"0x{a:08x},{name},return,,word,{c}" for a, (name, c) in RETURNS.items()]
end = len(kept)
while end and kept[end - 1] == "":
    end -= 1
kept[end:end] = rows
open(path, "w").write("\n".join(kept))
print(f"caches {done_cache} (+{removed} second-word rows removed), signed {done_signed}, prototype rows {len(rows)} "
      f"(dropped {dropped} stale parameter rows)")
