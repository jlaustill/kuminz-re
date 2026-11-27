"""Round 11 stage B (types):
- Bitfield structs for the logical output request bytes 1 / 4 / 5 / 6 / 8 / 9 (like logical_output_request_bits_16_to_23_t),
  each bit from its e2m 1577 record (output N = byte N / 8, mask 1 << N % 8; 12A7 +N names the same outputs). A bit
  the code tests gets a descriptive name; a bit nothing reads directly stays reserved_bit_N with its record in the
  comment. Byte 0 stays a byte: cm848_setLogicalOutputRequest / cm848_clearLogicalOutputRequest index the array from
  it. Every access of these bytes is a masked read (no | / & writer).
- The lift pump: the five calibration words and sci_output_status_word typed word, LIFT_PUMP_RUN_REASON (size 2) on
  lift_pump_run_reason.
usage: apply_r11b_types.py <repo>  (writes bitfield_masks_r11b.json next to this script for the proof)"""
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E2M = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
records = {}
for line in open(E2M, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 10 and f[2] == "1577" and f[5] == "S":
        records[(int(f[3], 16), int(f[10], 16))] = f[0]
# byte: (instance row name, struct name, {bit: (field name, use evidence)})
BYTES = {
    1: ("logical_output_request_bits_8_to_15", {
        3: ("engine_brake_driver_1_request", "output 11 (DRB test 13-5D EXHAUST BRAKE): cm848_driveEngineRetarderOutput "
                                             "sets it; cm848_updateEngineRetarderActiveState and "
                                             "cm848_calculateEngineRetarderTorque read it"),
        4: ("engine_brake_driver_2_request", "output 12: cm848_calculateEngineRetarderTorque counts it as a stage"),
        5: ("engine_brake_driver_3_request", "output 13: cm848_calculateEngineRetarderTorque counts it as a stage"),
        6: ("engine_brake_driver_4_request", "output 14: cm848_calculateEngineRetarderTorque counts it as a stage"),
        7: ("engine_brake_driver_5_request", "output 15: cm848_calculateEngineRetarderTorque counts it as a stage"),
    }),
    4: ("logical_output_request_bits_32_to_39", {
        6: ("air_conditioning_clutch_request", "output 38 (DRB test 13-09 A/C CLUTCH RELAY): the A/C clutch control "
                                               "(cm848_controlAirConditioningClutchForBrTruck / ...ForDrTruck) requests "
                                               "it"),
    }),
    5: ("logical_output_request_bits_40_to_47", {
        3: ("intake_air_heater_1_request", "output 43 (DRB test 13-28 INTAKE HEATER #1): the intake air heater "
                                           "preheat / post-heat functions request it"),
        4: ("intake_air_heater_2_request", "output 44 (DRB test 13-29 INTAKE HEATER #2): the intake air heater "
                                           "preheat / post-heat functions request it"),
    }),
    6: ("logical_output_request_bits_48_to_55", {
        5: ("lift_pump_request", "output 53 (DRB test 13-33 FUEL PUMP RELAY / TRANSFER PUMP): cm848_controlLiftPump"),
        6: ("injector_driver_asic_shutoff_request", "output 54: read by the injector and fuel pressure diagnostics "
                                                    "(cm848_evaluateInjectorDiagnostics, "
                                                    "cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit)"),
    }),
    8: ("logical_output_request_bits_64_to_71", {
        3: ("egr_valve_pwm_enable_request", "output 67: read by the EGR valve control (cm848_selectEgrValveControlState, "
                                            "cm848_estimateEgrValveMotorCurrent)"),
        4: ("egr_valve_motor_opening_direction_request", "output 68: read by cm848_estimateEgrValveMotorCurrent"),
        7: ("variable_geometry_turbocharger_motor_closing_direction_request",
            "output 71: read by cm848_estimateVariableGeometryTurbochargerMotorCurrent"),
    }),
    9: ("logical_output_request_bits_72_to_79", {
        0: ("variable_geometry_turbocharger_pwm_enable_request", "output 72: read by the VGT control "
                                                                 "(cm848_selectVariableGeometryTurbochargerControlState)"),
    }),
}
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
masks = {}
struct_rows = []
for byte, (instance, named) in BYTES.items():
    addr = f"0x{0x40c080 + byte:08x}"
    sname = instance + "_t"
    i = next(k for k, l in enumerate(lines) if l.startswith(addr + ","))
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == instance and typ == "byte", (addr, name, typ)
    lines[i] = ",".join([a, name, sname, comment + f" Typed {sname} (round 11): one bitfield per e2m 1577 record."])
    masks[instance] = {}
    for bit in range(8):
        rec = records.get((byte, 1 << bit), "no record")
        out_no = byte * 8 + bit
        if bit in named:
            field, why = named[bit]
            c = f"output {out_no} (mask 0x{1 << bit:02x}): e2m 1577 +{byte} {rec}. {why}"
            masks[instance][field] = 1 << bit
        else:
            field = f"reserved_bit_{bit}"
            c = f"output {out_no} (mask 0x{1 << bit:02x}): e2m 1577 +{byte} {rec}; no direct read or write found"
        assert '"' not in c
        size = 1 if bit == 0 else 0
        struct_rows.append(f'{sname},,{field},bitfield:1@{bit},{size},"{c}",,verified')
open(gv, "w").write("\n".join(lines))
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
for byte, (instance, named) in BYTES.items():
    assert f"\n{instance}_t," not in text
text = text.rstrip("\n") + "\n" + "\n".join(struct_rows) + "\n"
open(sd, "w").write(text)
json.dump(masks, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "bitfield_masks_r11b.json"), "w"),
          indent=1)
print(len(BYTES), "structs,", len(struct_rows), "bitfield rows")
