"""Round 19 stage C (label-only): the ANC pass-through (round 18 lead). The ANC timing stage (e2m 10A4, enables in
106B +8) is compiled out of this build: its RAM words 0x40a04a-0x40a05c have no access. Its output ANC_SOI (10A4 +14,
'Timing output of anc_time; input to CBL') is filled every pass by one function from the off-nominal compensated
reference (1711 +8 CBO_SOI_Ref), with intermediate source 25 (e2m label 19 CBR_SOI), and the combustion limits step
(cm848_applyCombustionTimingLimits) reads it. 'ANC' is not spelled out in the e2m, so the names use the role."""
GLOBALS = [
    ("0x0040a05e", "injection_timing_combustion_limits_input",
     "The timing the combustion limits step starts from (cm848_applyCombustionTimingLimits): the off-nominal "
     "compensated reference, copied each pass by cm848_passCompensatedTimingToCombustionLimits because the ANC stage "
     "is compiled out (e2m 10A4 +14 ANC_SOI 'Timing output of anc_time; input to CBL')"),
    ("0x003fa700", "injection_timing_combustion_limits_input_copy",
     "A write-only copy of injection_timing_combustion_limits_input (no e2m record)"),
    ("0x003fa702", "injection_timing_combustion_limits_input_source",
     "The intermediate source of injection_timing_combustion_limits_input, written as 25 (COMBUSTION_REFERENCE) each pass "
     "(write-only; no e2m record)"),
]
FUNCTIONS = [
    ("0x00017b54", "cm848_passCompensatedTimingToCombustionLimits",
     "The ANC timing stage's place (e2m 10A4; compiled out): copies the off-nominal compensated reference "
     "injection_timing_compensated_reference (1711 +8 CBO_SOI_Ref) into injection_timing_combustion_limits_input "
     "(10A4 +14 ANC_SOI) and its copy, and sets the intermediate source to COMBUSTION_REFERENCE (25, e2m label 19 "
     "CBR_SOI). Task of cm848_periodicTaskSet_auxiliaryControl"),
]
