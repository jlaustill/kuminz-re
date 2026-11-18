import sys

path = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w8_egr/gen_W8_egr_charge.py"
text = open(path).read()
reps = []


def R(old, new):
    reps.append((old, new))


# 1. limiter plate: the real selection of the offsets
R("takes the largest of the COT / turbocharger speed derate offsets (or only the speed one when the filter-active trim is set) with the delta pressure offset while the EGR fraction is on, and limits the mass charge flow command to charge_mass_flow_filtered - 2 x that offset into mass_charge_flow_limited_command (charge_flow_derate_active_flag when it limited);",
  "takes the larger of the turbocharger speed and the COT derate offsets (only the COT one while the throttle_rate_filter_active_flag_cal trim is non-zero), floors it at -6400 while the EGR fraction is off and otherwise also takes the larger of it and the delta pressure offset, and when a derate flag is active limits the mass charge flow command to charge_mass_flow_filtered - 2 x that offset into mass_charge_flow_limited_command (charge_flow_derate_active_flag when it limited);")
# 2. EAC output plate
R("integral accumulator (Q16) += error x the adjusted integral gain x 655 between the integral limits, presettable;",
  "integral accumulator (Q16) += (error x the adjusted integral gain >> 10) x 655 between the integral limits, preset while the preset is active or the controller is overridden;")
# 3. turbo speed threshold evidence
R("fuel_demand_quantity is therefore the filtered turbocharger speed (strong lead, see the note). Dump 1920... see note.",
  "fuel_demand_quantity is therefore the filtered turbocharger speed (strong lead, see the note). Dump 1500 (12 KRPM).")
# 4. 0x40a390 evidence
R("the second output of the rotation (sin x mass flow error + cos x EGR fraction error / 1.28); no reader outside this module in the 0x40a.. controllers. e2m: CSE_Xform_Error_2 (+0x02, 'for turbocharger control').",
  "the second output of the rotation (sin x mass flow error + cos x EGR fraction error / 1.28); its only reader is cm848_calculateWastegateDutyRequest (three reads), the turbocharger-side controller, as the e2m name says. e2m: CSE_Xform_Error_2 (+0x02, 'transformed for turbocharger control'). Dump 220.")
# 5. override value reader
R("code: replaces the scheduled angle while throttle_rate_override_flag is 1 (only reader cm848_selectChargeSystemTransformAngle).",
  "code: replaces the scheduled angle while charge_system_transform_angle_override_enable_cal is 1 (read in cm848_selectChargeSystemTransformAngle in the C output; the instruction scanner finds no tracked access). Dump 35840 (0x8c00).")
# 6. type note (1) and (1b)
R("(1) 0x004067f2,egr_valve_derivative_filter_coefficient,word,...: byte -> word. Dump 0x80 as a byte; the ROM word is 0x8000 hmm - see (1b). ",
  "(1) 0x004067f2,egr_valve_derivative_filter_coefficient,word,...: byte -> word. The cell holds 0x8000 (32768 = 0.5 in 1/65536) and the byte row shows only its high byte 0x80; the first-order filter reads it through the pointer stored at 0x3fa790 (so xref_addr.py shows no access); e2m C_EGA_Der_Dtime_Cnst has scale 1.52588E-05 = 1/65536, a 16-bit filter constant exactly like sensor_channel_config_t.filter_coefficient (word); the VGT twin 0x407720 has the same fault (byte row, word value 0x8000). ")
R("NOTE(\"TYPE ROW (1b), the 0x4067f2 coefficient: the first-order filter reads the coefficient through the pointer stored at 0x3fa790 (no direct access, so the scanner shows none). The ROM cell is 0x80 followed by the low byte of the next cell; as a word the dump reads 0x8000 hmm: peek 0x4067f2:w says 32768? - the Q16 coefficient (weight of the previous value 32768 / 65536 = 0.5) is a word exactly like every other ema coefficient in sensor_channel_config_t.filter_coefficient (word, 1/65536); a byte value 128 would be the high byte of that word. So the row type is wrong: byte -> word. The VGT twin 0x407720 has the same fault.\")\n", "")
# 7. stale note wording
R("the refresh step has to rewrite the plates / comments that cite the 20 old names renamed here",
  "the refresh step has to rewrite the plates / comments that cite the old names renamed here")

for old, new in reps:
    if text.count(old) != 1:
        sys.exit("pattern count %d: %s" % (text.count(old), old[:80]))
    text = text.replace(old, new)

# extra rows inserted before the uncertain block
extra = '''
G("0x003fd7d6", "throttle_rate_override_flag", "charge_system_transform_angle_override_enable_cal",
  "code: EEPROM mirror: read only by cm848_selectChargeSystemTransformAngle; 1 selects charge_system_transform_angle_override_value instead of the scheduled angle. No e2m trim name found for it (it sits right before T_EAC_User_Override / T_EAC_Preset_Enable).")
G("0x004067e2", "", "egr_valve_position_command_diagnostic_filter_constant",
  "code: the coefficient cell the filter state egr_valve_position_command_diagnostic_filter_state points at (stored by cm848_initializeEgrValvePositionControlDiagnostic): weight of the previous value of the filtered final position command in 1/65536 (dump 33647 = 0.513). The row has the type word; only the name is missing.")
'''
marker = "# --- uncertain rows"
if text.count(marker) != 1:
    sys.exit("marker")
text = text.replace(marker, extra + "\n" + marker)
open(path, "w").write(text)
print("patched")
