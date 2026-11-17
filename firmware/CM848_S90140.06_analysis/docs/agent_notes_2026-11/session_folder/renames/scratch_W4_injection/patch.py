import json

RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_injection.jsonl'
text = open(RES).read()

pairs = [
    (
        "e2m CBL_SOI_Cmd (0x01171B08, 'SOI command after imposing combustion limits') sits at the same offset in its block as 0x40a46e in the 0x40a466 group, with the four CBL words +08/+0A/+0C/+0E = 0x40a46e/470/472/474 and CBL_User_Incr_Flag +18 = 0x40a47e.",
        "e2m block CBL (0x01171B00 = 0x40a466): CBL_SOI_Cmd +08 = 0x40a46e ('SOI command after imposing combustion limits'), CBL_SOI_Max_Limit +0A / CBL_SOI_Min_Limit +0C / CBL_SOI_Ref +0E = 0x40a470 / 472 / 474 and CBL_User_Incr_Flag +18 = 0x40a47e.",
    ),
    (
        "which cm848_updateMainInjectionTimingByDeliveryMode turns into bit 4 of injection_timing_adjustment_flags (e2m Final_Timing_Adjustments_Flag order",
        "which cm848_updateMainInjectionTimingByDeliveryMode turns into mask 4 of injection_timing_adjustment_flags (e2m Final_Timing_Adjustments_Flag order",
    ),
    (
        "(0x20 of fuel_demand_mode_flags -> bit 2 of injection_timing_adjustment_flags = e2m CBO)",
        "(0x20 of fuel_demand_mode_flags -> mask 2 of injection_timing_adjustment_flags = e2m CBO)",
    ),
    (
        "the flag has 26 use sites in 15 functions (",
        "the flag has 26 lines (code and plate text) in 18 functions (",
    ),
    (
        "reads in cm848_calculatePilotInjectionTimingOffset / cm848_updateEngineStatusFlags)",
        "reads in cm848_calculatePilotInjectionTimingOffset / cm848_updateMainInjectionTimingByDeliveryMode, was cm848_updateEngineStatusFlags)",
    ),
    (
        "Dump: fuel_demand_mode_code = 25 (0x19), so 18 applies.",
        "Dump: fuel_demand_mode_code = 25 (0x19), so neither 29 nor 30 is selected there.",
    ),
    (
        "and the TPU channel handler that averages the speed sums. It sits at",
        "and cm848_vehicleSpeedSensorInterruptHandler (0x526f98), which picks engine_rpm_state.reserved_0a or reserved_0c by the flag. It sits at",
    ),
    (
        "Offset anchors checked against code and RAM dump (e2m block = CM848 base):",
        "Offset anchors (e2m block = CM848 base); the ones also confirmed by the code or the RAM dump are CBL +08..+0E and +18, CBR_SOI_Ref and Alpha1..Chi4, CBO +1C / +1E / +20, CBP +02 / +04 / +08 / +0A, FSS +12 and the per-event words, the rest are offset matches only:",
    ),
]
for old, new in pairs:
    n = text.count(old)
    print(n, old[:60])
    if n == 1:
        text = text.replace(old, new)

open(RES, 'w').write(text)
rows = [json.loads(l) for l in open(RES) if l.strip()]
print('rows ok', len(rows))
