"""Round 9 stage A: name the unnamed 8BB5 / 8BBB words and the controller's integral term. A row with an empty name gets
the name (its type stays); a missing row is inserted with an empty type, so only the label changes (the importer applies
a name and a type separately). Each new name goes into the map with its DAT_ label for the label-only proof.
String edits only: global_variables.csv takes commas unquoted.
usage: apply_r9a_new.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")


def b5(off, rec, desc, extra=""):
    return f"e2m 8BB5 +{off} {rec} ('{desc}')" + (f": {extra}" if extra else "")


def bb(off, rec, desc, extra=""):
    return f"e2m 8BBB +{off} {rec} ('{desc}')" + (f": {extra}" if extra else "")


CAL = "cm848_calibrateGovernorPressureSensorOffset"
P = "cm848_calculateGovernorPressureProportionalTerm"
NEW = [
    ("0x00408ae0", "governor_pressure_offset_calibration_interval_time",
     b5("00", "RE_Between_Cal_Timer_Max", "Determines how long the delay will be before another cal will be allowed",
        f"3000 = 30 s; reloads governor_pressure_offset_calibration_interval_timer ({CAL})")),
    ("0x00408ae4", "governor_pressure_offset_calibration_minimum_engine_speed",
     b5("04", "RE_Cal_ERPM_Min", "The minimum engine speed for governor pressure sensor calibration", "3200 = 400 rpm")),
    ("0x00408ae6", "governor_pressure_offset_calibration_time",
     b5("06", "RE_Cal_Timer_Max", "Duration of 100% duty cycle during cal of sensor zero pressure offset",
        "49 = 0.49 s; reloads governor_pressure_offset_calibration_timer")),
    ("0x00408aea", "governor_pressure_offset_calibration_initial_delay_time",
     b5("0A", "RE_Init_Cal_Delay_Max", "Timer at CRANK to RUN transition which causes delay to first sensor cal",
        "51 = 0.51 s; reloads governor_pressure_offset_calibration_initial_delay_timer")),
    ("0x00408aee", "governor_pressure_derivative_gain_denominator",
     b5("0E", "RE_K_D_Den", "PID constant - denominator for the derivative term in gov pres control",
        "400; cm848_calculateGovernorPressureDerivativeTerm")),
    ("0x00408af2", "governor_pressure_relaxation_maximum_error",
     b5("12", "RE_Max_Pressure_Delta", "Maximum value of error between governor set and actual",
        "signed dword, -128 = -1 psi; with governor_pressure_target 0 and the error above it, "
        "cm848_controlGovernorPressureSolenoid relaxes the solenoid duty")),
    ("0x00408af6", "governor_pressure_offset_calibration_maximum_vehicle_speed",
     b5("16", "RE_MPHX2_Max_Cal", "Road speed above which no gov pres sensor cal is allowed", "5120 = 20 mph")),
    ("0x00408af8", "governor_pressure_offset_calibration_maximum_output_speed",
     b5("18", "RE_OSS_Max_Cal", "Output shaft speed above which no gov pres sensor cal is allowed", "1600 = 200 rpm")),
    ("0x00408afa", "governor_pressure_proportional_gain_0_denominator",
     b5("1A", "RE_PID_Error_Brkpt_0_Den", "prop gain denominator if error < brkpt_1 and trans temp above "
        "RE_PID_Switch_Temperature", f"200; {P}")),
    ("0x00408afc", "governor_pressure_proportional_gain_0_numerator",
     b5("1C", "RE_PID_Error_Brkpt_0_Num", "prop gain numerator if error < brkpt_1 (warm)", "10")),
    ("0x00408afe", "governor_pressure_proportional_error_breakpoint_1",
     b5("1E", "RE_PID_Error_Brkpt_1", "Abs val of error for 1st prop step gain (warm)", "384 = 3 psi")),
    ("0x00408b00", "governor_pressure_proportional_gain_1_denominator",
     b5("20", "RE_PID_Error_Brkpt_1_Den", "prop gain denominator between brkpt_1 and brkpt_2 (warm)", "200")),
    ("0x00408b02", "governor_pressure_proportional_gain_1_numerator",
     b5("22", "RE_PID_Error_Brkpt_1_Num", "prop gain numerator between brkpt_1 and brkpt_2 (warm)", "10")),
    ("0x00408b04", "governor_pressure_proportional_error_breakpoint_2",
     b5("24", "RE_PID_Error_Brkpt_2", "Abs val of error for 2nd prop step gain (warm)", "1280 = 10 psi")),
    ("0x00408b06", "governor_pressure_proportional_gain_2_denominator",
     b5("26", "RE_PID_Error_Brkpt_2_Den", "prop gain denominator above brkpt_2 (warm)", "200")),
    ("0x00408b08", "governor_pressure_proportional_gain_2_numerator",
     b5("28", "RE_PID_Error_Brkpt_2_Num", "prop gain numerator above brkpt_2 (warm)", "10")),
    ("0x00408b0a", "governor_pressure_cold_proportional_gain_3_denominator",
     b5("2A", "RE_PID_Error_Brkpt_3_Den", "prop gain denominator if error < brkpt_4 and trans temp below "
        "RE_PID_Switch_Temperature", "200")),
    ("0x00408b0c", "governor_pressure_cold_proportional_gain_3_numerator",
     b5("2C", "RE_PID_Error_Brkpt_3_Num", "prop gain numerator if error < brkpt_4 (cold)", "8")),
    ("0x00408b0e", "governor_pressure_cold_proportional_error_breakpoint_4",
     b5("2E", "RE_PID_Error_Brkpt_4", "Abs val of error for 1st prop step gain (cold)", "384 = 3 psi")),
    ("0x00408b10", "governor_pressure_cold_proportional_gain_4_denominator",
     b5("30", "RE_PID_Error_Brkpt_4_Den", "prop gain denominator between brkpt_4 and brkpt_5 (cold)", "200")),
    ("0x00408b12", "governor_pressure_cold_proportional_gain_4_numerator",
     b5("32", "RE_PID_Error_Brkpt_4_Num", "prop gain numerator between brkpt_4 and brkpt_5 (cold)", "8")),
    ("0x00408b14", "governor_pressure_cold_proportional_error_breakpoint_5",
     b5("34", "RE_PID_Error_Brkpt_5", "Abs val of error for 2nd prop step gain (cold)", "1280 = 10 psi")),
    ("0x00408b16", "governor_pressure_cold_proportional_gain_5_denominator",
     b5("36", "RE_PID_Error_Brkpt_5_Den", "prop gain denominator above brkpt_5 (cold)", "200")),
    ("0x00408b18", "governor_pressure_cold_proportional_gain_5_numerator",
     b5("38", "RE_PID_Error_Brkpt_5_Num", "prop gain numerator above brkpt_5 (cold)", "8")),
    ("0x00408b1a", "governor_pressure_integral_gain_denominator",
     b5("3A", "RE_PID_Error_Sum_Den", "Denominator of the integral gain constant for gov pres control",
        "16000; cm848_applyGovernorPressureIntegralTerm")),
    ("0x00408b1e", "governor_pressure_solenoid_relaxed_minimum_duty",
     b5("3E", "RE_PID_Minimum_Relaxed", "Min value of VFS solenoid duty cycle in relaxation conditions",
        "10240 = 40 %; cm848_controlGovernorPressureSolenoid")),
    ("0x00408b20", "governor_pressure_solenoid_relax_factor",
     b5("40", "RE_PID_Relax_Factor", "Value used to adjust VFS on time in relaxation conditions", "3")),
    ("0x00408b22", "governor_pressure_cold_gain_switch_temperature",
     b5("42", "RE_PID_Switch_Temperature", "Trans temp at which switch from cold to normal prop gains",
        f"2048 = 32 F; {P}")),
    ("0x00408b24", "governor_pressure_offset_calibration_maximum_throttle",
     b5("44", "RE_TPS_Max_Cal", "Max value of TPS for which gov pres sensor cal is allowed", "666")),
    ("0x00408b26", "governor_pressure_offset_calibration_method",
     b5("46", "RE_Trans_Pressure_Offset_Method", "Method to determine gov pres offset; 0=RE method, 1=amb pressure",
        "1 here: the calibration takes the barometric pressure as the zero (a byte)")),
    ("0x00408b2c", "governor_pressure_solenoid_duty_maximum",
     b5("4C", "RE_VFS_PWM_Maximum", "Max value of VFS solenoid duty cycle",
        "25293 = 98.8 % (0x6400 = 100 %); cm848_limitGovernorPressureSolenoidDuty")),
    ("0x00408b2e", "governor_pressure_solenoid_duty_minimum",
     b5("4E", "RE_VFS_PWM_Minimum", "Min value of VFS solenoid duty cycle",
        "205 = 0.8 %; also cm848_sciCommand37Callback")),
    ("0x00408b34", "governor_pressure_controller_initial_output",
     "The governor pressure controller's start value: 12800 = 50 % duty; cm848_initializeGovernorPressureControl loads "
     "governor_pressure_controller_output with it. 8BB5 +54, past the 11.45 block's last record"),
    ("0x004077f6", "transmission_lockup_delay_4_3_time",
     bb("00", "RE_Lockup_Delay_4_3_Max", "Timer value used to delay lockup",
        "120 = 1.2 s; cm848_processOverdriveSwitchAndShift reloads transmission_lockup_timers.lockup_delay_4_3_timer "
        "with it at a 4-3 downshift (not in overheat, overdrive switch not off)")),
    ("0x004077fa", "transmission_3_4_transition_time",
     bb("04", "RE_Transition_3_4_Timer_Max", "Timer value used to delay ratio calc after engaging overdrive",
        "400 = 4 s; reloads transmission_3_4_transition_timer")),
    ("0x004077fc", "transmission_overdrive_upshift_inhibit_time",
     bb("06", "RE_Upshift_3_4_Inhibit_Timer_Max", "Timer value used to delay OD upshifts",
        "25 = 250 ms; reloads transmission_overdrive_upshift_inhibit_timer")),
    ("0x00407800", "transmission_lockup_delay_4_3_overdrive_off_time",
     bb("0A", "RE_Lockup_Delay_4_3_Max_OD_Off", "Timer value used to delay lockup when using OD switch",
        "120; the 4-3 lockup delay with overdrive_control_flags bit 5")),
    ("0x00407802", "transmission_cruise_resume_downshift_delay_time",
     bb("0C", "RE_Cruise_Resume_Downshift_Timer_Max", "Time used to delay a 4-3 downshift in cruise resume mode",
        "150 = 1.5 s; cm848_processOverdriveSwitchAndShift")),
    ("0x00407804", "transmission_cruise_resume_downshift_speed_difference",
     bb("0E", "RE_Cruise_Set_Speed_Difference_Downshift", "road speed < cruise setpoint - this, 4-3 downshift",
        "2560 = 10 mph")),
    ("0x00407806", "transmission_cruise_resume_upshift_speed_difference",
     bb("10", "RE_Cruise_Set_Speed_Difference_Upshift", "road speed > cruise setpoint - this, allow 3-4 upshift",
        "512 = 2 mph")),
    ("0x00407808", "transmission_cruise_resume_downshift_engine_speed",
     bb("12", "RE_Cruise_Set_Speed_RPM_Downshift", "Target ENGRPM to allow 4-3 downshift during cruise resume",
        "15200 = 1900 rpm")),
    ("0x0040780a", "transmission_cruise_resume_upshift_engine_speed",
     bb("14", "RE_Cruise_Set_Speed_RPM_Upshift", "Target ENGRPM to allow 3-4 upshift after cruise resume",
        "24000 = 3000 rpm")),
    ("0x0040b594", "governor_pressure_integral_term",
     "The governor pressure controller's integral term: governor_pressure_error_sum / "
     "governor_pressure_integral_gain_denominator, clamped to +-0x6400, every integral period "
     "(cm848_applyGovernorPressureIntegralTerm)"),
]
lines = open(p).read().split("\n")
index = {}
for i, l in enumerate(lines):
    m = re.match(r"^(0x[0-9a-f]{8}),", l)
    if m:
        index.setdefault(m.group(1), i)
filled, inserted, maps = 0, 0, []
for addr, name, comment in NEW:
    assert '"' not in comment and "," not in name
    if addr in index:
        a, n, t, c = (lines[index[addr]].split(",", 3) + ["", ""])[:4]
        assert n == "", (addr, n)
        lines[index[addr]] = ",".join([a, name, t, comment + (f" | earlier note: {c}" if c else "")])
        filled += 1
    else:
        k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > int(addr, 16))
        lines.insert(k, ",".join([addr, name, "", comment]))
        index = {re.match(r"^(0x[0-9a-f]{8}),", l).group(1): i for i, l in enumerate(lines)
                 if re.match(r"^0x[0-9a-f]{8},", l)}
        inserted += 1
    maps.append(f"{addr},{name},DAT_{addr[2:]},global")
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
print(f"filled {filled}, inserted {inserted}")
