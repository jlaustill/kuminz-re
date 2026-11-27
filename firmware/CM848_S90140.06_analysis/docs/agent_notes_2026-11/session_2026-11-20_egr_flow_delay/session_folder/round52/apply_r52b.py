"""Round 52 stage B: five enums from the value labels of the records stage A cited (merged over the e2m's duplicate
records, which split a long label list in two), each member checked against the code branch that stores it. Every
access is a whole-value compare or store.
  COOLING_FAN_COOLANT_REQUEST_STATE      cooling_fan_coolant_request_state          (8B22 +8)
  COOLING_FAN_SPEED_TARGET_SOURCE        cooling_fan_speed_target_source            (8B22 +E, cm848_selectCoolingFanSpeedTarget)
  COOLING_FAN_DUTY_SOURCE                cooling_fan_duty_source_code               (8B22 +16, cm848_selectCoolingFanDutySource /
                                                                                     cm848_applyCoolingFanDuty)
  ALTERNATOR_FIELD_REGULATOR_STATE       alternator_field_regulator_state + _previous_state (8A60 +10; its labels are in
                                                                                     the description)
  ALTERNATOR_FIELD_LOAD_RESPONSE_STAGE   alternator_field_load_response_stage       (8A60 +16, ditto)
Idempotent.  usage: apply_r52b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 52"
TARGET = "cm848_selectCoolingFanSpeedTarget"
DUTY = "cm848_selectCoolingFanDutySource"
APPLY = "cm848_applyCoolingFanDuty"
ENUMS = {
    "COOLING_FAN_COOLANT_REQUEST_STATE": ("COOLING_FAN_COOLANT_REQUEST_", [
        (0, "BELOW_RAMP", "e2m IDLE: coolant under cooling_fan_coolant_ramp_start_temperature (cooling_fan_coolant_speed_minimum)"),
        (1, "RAMP", "e2m RAMP: the linear ramp from cooling_fan_coolant_ramp_base_speed"),
        (2, "PI_CONTROL", "e2m PI_CNTRL: the PI loop above cooling_fan_coolant_temperature_setpoint"),
        (3, "FULL_SPEED", "e2m COOL_MAX: cooling_fan_coolant_speed_maximum (also on a coolant sensor fault)")]),
    "COOLING_FAN_SPEED_TARGET_SOURCE": ("COOLING_FAN_TARGET_", [
        (0, "BASE_SPEED", f"e2m MIN_DEM: {TARGET} starts from cooling_fan_base_speed"),
        (1, "COOLANT", "e2m COOLANT: cooling_fan_coolant_speed_request"),
        (2, "AIR_CONDITIONING", "e2m AC: cooling_fan_air_conditioning_speed_request"),
        (3, "INTAKE", "e2m IMT: cooling_fan_intake_speed_request"),
        (4, "TRANSMISSION", "e2m TOT: cooling_fan_transmission_speed_request"),
        (5, "HIGH_ENGINE_RPM_RAMP_UP_TARGET", "e2m HIGHSLIP: cooling_fan_high_engine_rpm_ramp_up_target"),
        (6, "HIGH_ENGINE_RPM_RAMP_DOWN_FLOOR", "e2m LOW_SLIP: cooling_fan_high_engine_rpm_ramp_down_floor"),
        (7, "ENGINE_DRIVEN_LIMIT", "e2m MAX_RPM: cooling_fan_engine_driven_speed_limit"),
        (8, "CEILING", "e2m MAX_DEM: cooling_fan_speed_ceiling"),
        (9, "OVERRIDE", "e2m OVERRIDE: cooling_fan_speed_target_override"),
        (10, "THERMOSTAT_MONITOR", "e2m TSTAT: the thermostat monitor holds cooling_fan_base_speed"),
        (11, "HIGH_ENGINE_RPM_RAMPING_DOWN", "e2m LOWRMPDN: cooling_fan_ramp_down_speed stepping down to the floor"),
        (12, "HIGH_ENGINE_RPM_RAMPING_UP", "e2m RAMPUP: cooling_fan_ramp_up_speed stepping up to the ramp-up target"),
        (13, "HIGH_ENGINE_RPM_AT_TARGET", "e2m SLIPTMR: held at the ramp-up target for cooling_fan_ramp_at_target_passes"),
        (14, "HIGH_ENGINE_RPM_RAMP_DOWN_RESUME", "e2m RAMPDN: cooling_fan_ramp_down_resume_speed stepping down"),
        (15, "HIGH_ENGINE_RPM_RAMP_UP_RESUME", "e2m EXLOWSLP: cooling_fan_ramp_up_resume_speed stepping up out of the floor")]),
    "COOLING_FAN_DUTY_SOURCE": ("COOLING_FAN_DUTY_", [
        (0, "CLAMPED_MINIMUM", f"e2m MIN_PWM: {APPLY} clamps the request to cooling_fan_duty_minimum"),
        (1, "FIXED", f"e2m OVERRIDE: {DUTY} uses cooling_fan_fixed_duty"),
        (2, "LOW_ENGINE_RPM", "e2m STOP: under cooling_fan_low_engine_rpm (cooling_fan_low_engine_rpm_duty)"),
        (3, "ENGAGEMENT", "e2m KICKON: cooling_fan_engagement_duty"),
        (4, "BASE_SPEED_TARGET", "e2m MIN_SPD: the target is cooling_fan_base_speed"),
        (5, "CEILING_TARGET", "e2m MAX_SPD: the target is cooling_fan_speed_ceiling off idle (cooling_fan_duty_maximum)"),
        (6, "IDLE_LIMITED", "e2m IDLE_ON: cooling_fan_idle_limited_duty"),
        (7, "IDLE_MINIMUM", "e2m IDLE_OFF: cooling_fan_duty_minimum at idle"),
        (8, "SPEED_CONTROL", "e2m CONTROL: cm848_runCoolingFanSpeedPid"),
        (9, "ACTUATOR_TEST", "e2m TOOL: cooling_fan_actuator_test_duty"),
        (10, "CLAMPED_MAXIMUM", f"e2m MAX_PWM: {APPLY} clamps the request to cooling_fan_duty_maximum"),
        (11, "HOLD", f"e2m PWMDELAY: {APPLY} holds cooling_fan_hold_duty for cooling_fan_hold_passes")]),
    "ALTERNATOR_FIELD_REGULATOR_STATE": ("ALTERNATOR_FIELD_REGULATOR_", [
        (0, "INACTIVE", "e2m 8A60 +10 EVR_Mode 0=INACTIVE"),
        (1, "STARTUP", "e2m 1=STARTUP"),
        (2, "STEADY_STATE", "e2m 2=SS"),
        (3, "LOAD_RESPONSE", "e2m 3=TRANS: the transient mode (alternator_field_load_response_*)")]),
    "ALTERNATOR_FIELD_LOAD_RESPONSE_STAGE": ("ALTERNATOR_FIELD_LOAD_RESPONSE_", [
        (0, "NONE", "e2m 8A60 +16 EVR_Transient_Phase 0=NONE (outside the load response)"),
        (1, "HOLD", "e2m 1=HOLD"),
        (2, "RECOVERY", "e2m 2=RECOVERY")]),
}
ROWS = [("0x0040b29a", "cooling_fan_coolant_request_state", "COOLING_FAN_COOLANT_REQUEST_STATE"),
        ("0x0040b2a0", "cooling_fan_speed_target_source", "COOLING_FAN_SPEED_TARGET_SOURCE"),
        ("0x0040b2a8", "cooling_fan_duty_source_code", "COOLING_FAN_DUTY_SOURCE"),
        ("0x0040b26c", "alternator_field_regulator_state", "ALTERNATOR_FIELD_REGULATOR_STATE"),
        ("0x003fb39c", "alternator_field_regulator_previous_state", "ALTERNATOR_FIELD_REGULATOR_STATE"),
        ("0x0040b272", "alternator_field_load_response_stage", "ALTERNATOR_FIELD_LOAD_RESPONSE_STAGE")]
done = 0
ep = os.path.join(out, "enums.csv")
e = open(ep).read()
for name, (prefix, members) in ENUMS.items():
    if f"\n{name}," in e:
        continue
    e = e if e.endswith("\n") else e + "\n"
    lines = [f"# {name}: from the e2m value labels, each member checked against the branch that stores it ({R})"]
    for v, m, text in members:
        assert "," not in m and '"' not in text
        lines.append(f'{name},{v},{prefix}{m},"{text} ({R})",2')
    e += "\n".join(lines) + "\n"
    done += 1
open(ep, "w").write(e)
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
for a, name, enum in ROWS:
    p = g[idx[a]].split(",", 3)
    assert p[1] == name, (a, p[1])
    if p[2] == enum:
        continue
    assert p[2] == "word", (a, p[2])
    g[idx[a]] = f"{a},{name},{enum},Typed {enum} from the e2m labels ({R}). {p[3]}"
    done += 1
open(gp, "w").write("\n".join(g))
print(f"{done} changes")
