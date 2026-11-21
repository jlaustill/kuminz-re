"""Stage 6 (shape): i16 for the e2m 'S' words of stage 5 that load with lha, and void(void) for
cm848_estimateChargePressure (0x13294: r4 / r3 are written before any read).
Usage: apply_stage6.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
SIGNED = {  # address: (name, the lha that proves it)
    0x0040675a: ("exhaust_pressure_offset", "lha in cm848_calculateEgrDeltaPressures"),
    0x0040675e: ("exhaust_pressure_estimate_egr_valve_position_constant", "lha in cm848_estimateExhaustPressure"),
    0x00406760: ("exhaust_pressure_estimate_engine_speed_constant", "lha in cm848_estimateExhaustPressure"),
    0x00406762: ("exhaust_pressure_estimate_charge_pressure_constant", "lha in cm848_estimateExhaustPressure"),
    0x0040a422: ("charge_pressure_estimate_offset", "lha in cm848_monitorChargePressureInRange"),
    0x0040a624: ("egr_orifice_delta_pressure", "lha in cm848_calculateDownstreamEgrMassFlow"),
    0x0040a628: ("egr_valve_delta_pressure", "lha in cm848_calculateEgrDeltaPressures"),
    0x0040a62c: ("engine_delta_pressure", "lha in cm848_calculatePumpingTorqueAdjustment"),
}
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
done = 0
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if p[0].startswith("0x") and int(p[0], 16) in SIGNED:
        name, proof = SIGNED[int(p[0], 16)]
        assert p[1] == name and p[2] == "word", p
        p[2] = "i16"
        if len(p) > 3:
            p[3] = p[3] + f" | i16: e2m signed, {proof} (2026-11-20)"
        lines[i] = ",".join(p)
        done += 1
assert done == len(SIGNED), done
open(path, "w").write("\n".join(lines))

path = os.path.join(out, "function_definitions.csv")
lines = open(path).read().split("\n")
kept = [l for l in lines if not l.startswith("0x00013294,")]
assert len(lines) - len(kept) == 2, len(lines) - len(kept)
end = len(kept)
while end and kept[end - 1] == "":
    end -= 1
kept[end:end] = ["0x00013294,cm848_estimateChargePressure,return,,void,Takes no parameters: r4 and r3 are written "
                 "before any read (lhz r4 @ 0x132b4, lis r3 @ 0x132b8); the old boost_input / rpm rows were stale"]
open(path, "w").write("\n".join(kept))
print(f"signed {done}, prototype rows: 2 stale removed, 1 void added")
