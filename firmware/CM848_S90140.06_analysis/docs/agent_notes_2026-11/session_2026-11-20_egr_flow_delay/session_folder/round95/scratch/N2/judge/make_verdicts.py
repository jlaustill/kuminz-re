"""Build the N2 judge verdicts (judge scratch, read-only for the repo): every proposed global with its verdict,
the amended names and comments applied by exact, asserted replacements, plus the function and prototype verdicts.
usage: python3 make_verdicts.py  (writes verdicts.json)"""
import json
import re
import struct

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ram = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin", "rb").read()
xram = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.extended_ram.bin", "rb").read()


def w(a):
    if 0x800000 <= a < 0x8091c2:
        return struct.unpack(">H", ram[a - 0x800000:a - 0x7ffffe])[0]
    if a >= 0x8092c2:
        return struct.unpack(">H", xram[a - 0x809242:a - 0x809240])[0]
    return None


def l(a):
    return (w(a) << 16) | w(a + 2)


props = json.load(open(J + "proposals_globals.json"))
by = {e["address"]: e for e in props}
summary = {}
for line in open(J + "check_all_out.txt").read().split("=== ")[1:]:
    summary[line.split()[0]] = line

NAME = {
    "0x00800192": "engine_retarder_full_scale_torque_lookup",
    "0x0080020e": "cylinder_pressure_maintenance_timing_per_temperature_degree_lookup",
    "0x00060640": "cylinder_pressure_maintenance_timing_per_temperature_degree_axis",
    "0x0006065c": "cylinder_pressure_maintenance_timing_per_temperature_degree_values",
    "0x008072f4": "cylinder_balance_engine_speed_axis",
    "0x000611d0": "engine_protection_oil_pressure_limit_engine_speed_axis",
}
REPL = {
    "0x00800102": [(
        "writes x_input = the absolute difference between the rate-limited ASG reference and "
        "asg_filtered_reference_speed_0_4500 (0x800108); the result (0x800110, a 1/16384 weight) blends "
        "asg_filtered_reference_speed_0_4500 with asg_reference_speed_working (>> 14).",
        "writes x_input (0x800108) = the absolute difference between the rate-limited ASG reference (0x800116) and "
        "asg_filtered_reference_speed_0_4500; the result (0x800110) is a 1/16384 weight w: "
        "asg_filtered_reference_speed_0_4500 = (asg_filtered_reference_speed_0_4500 x w + asg_reference_speed_working "
        "x (0x4000 - w)) >> 14.")],
    "0x00800184": [
        ("cm550_ioControlBasedFuelCalculator (a2, jsr at 0x10072) points y_values_pointer at",
         "cm550_ioControlBasedFuelCalculator (a2, jsr at 0x10072) rewrites x_axis_pointer each pass, points "
         "y_values_pointer at"),
        ("engine_retarder_reference_torque_lookup's result",
         "engine_retarder_full_scale_torque_lookup's result (the full scale torque; a result below 1 gives 0)")],
    "0x0080024e": [("cylinder_balance_threshold_axis", "cylinder_balance_engine_speed_axis")],
    "0x0080025c": [("cylinder_balance_threshold_axis", "cylinder_balance_engine_speed_axis")],
    "0x0080026a": [("cylinder_balance_threshold_axis", "cylinder_balance_engine_speed_axis")],
    "0x00801a3e": [("engine_protection_oil_pressure_limit_axis", "engine_protection_oil_pressure_limit_engine_speed_axis")],
    "0x00801a4c": [("engine_protection_oil_pressure_limit_axis", "engine_protection_oil_pressure_limit_engine_speed_axis")],
    "0x0006052a": [(
        "the x axis of engine_retarder_torque_lookup / engine_retarder_reference_torque_lookup / "
        "engine_retarder_torque_stage_1_lookup .. _stage_5_lookup;",
        "the x axis of engine_retarder_torque_lookup / engine_retarder_full_scale_torque_lookup / "
        "engine_retarder_torque_stage_1_lookup .. _stage_5_lookup (engine_retarder_full_scale_torque_lookup's input is "
        "its last point, the word at +8);")],
    "0x00060566": [(
        "the y values of engine_retarder_reference_torque_lookup and of engine_retarder_torque_lookup with 6 active "
        "cylinders;",
        "the y values of engine_retarder_full_scale_torque_lookup and of engine_retarder_torque_lookup with 6 active "
        "cylinders; j1939FormatMultiFrameResponse reads its last value (0x6056e, [4]) directly as the full scale torque "
        "of the stage selection unless 0x801e28 is 4;")],
    "0x00801e30": [(
        "(jcomm_req_torque_braking_override_or_limit_value_0_125 x the reference torque / 100)",
        "(jcomm_req_torque_braking_override_or_limit_value_0_125 x the full scale torque 0x801e2c / 100: "
        "engine_retarder_torque_stage_4_values[4] when 0x801e28 is 4, else engine_retarder_torque_stage_6_values[4], "
        "the value CM848 names engine_retarder_full_scale_torque)")],
    "0x00060640": [
        ("the x axis of cylinder_pressure_maintenance_temperature_per_timing_degree_lookup",
         "the engine speed x axis of cylinder_pressure_maintenance_timing_per_temperature_degree_lookup")],
}
FULL = {
    "0x00800192": (
        "The cm550_lookupTableInterpolation record (table_lookup_1d_arguments_t) of x axis "
        "engine_retarder_torque_engine_speed_axis (0x6052a, 13D6 JCBCRPXA) and y values engine_retarder_torque_stage_6_values "
        "(0x60566, 13D5 JC6CTQYA) (pointers from the RAM dump). cm550_throttleTablePointerSetup (0x100da) sets x_axis_offset 2 "
        "and both pointers, and cm550_ioControlBasedFuelCalculator rewrites both pointers each pass (0x10006 / 0x10010). That "
        "function (pea, jsr at 0x1009a) writes x_input = the last point of the engine speed axis (the word at x_axis_pointer + 8), "
        "so the lookup returns the 6 cylinder braking torque at the top speed point: the full scale torque that "
        "engine_retarder_torque_lookup's result x 0x6400 is divided by into "
        "jcomm_ind_retarder_torque_amount_of_torque_provided_by_retarde_0_125 (JCINRDTQ, at most 32000; a result below 1 gives "
        "0). CM848 reads the same value straight from engine_retarder_torque_stage_6_values[4] into "
        "engine_retarder_full_scale_torque. It is not the J1939 reference retarder torque calibration (e2m 10FC +0 JCRFRDTQ, "
        "jcomm_reference_retarder_torque_reference_ret_torque_that_co_0_64255 at 0x8089a6). The rows inside are removed (were "
        "0x800196 cold_start_rpm_snapshot_3 / 0x800198 anc_altitude_table_1_base / 0x80019a anc_altitude_table_1_ptr / "
        "0x80019e cold_start_sensor_sum_saved). (was anc_disable_duration_ptr; PR #53 round 95)"),
    "0x0080020e": (
        "The cm550_lookupTableInterpolation record (table_lookup_1d_arguments_t) of x axis "
        "cylinder_pressure_maintenance_timing_per_temperature_degree_axis (0x60640, 108D CPCS03XA) and y values "
        "cylinder_pressure_maintenance_timing_per_temperature_degree_values (0x6065c, 108E CPCS03YA) (pointers from the RAM "
        "dump). cm550_initLoadTrendingSystem (0x124d2) sets x_axis_offset 2 and both pointers. "
        "cm550_coldStartFuelControlSlowCycle40Coordinator writes x_input = engine_rpm_primary (0x11eca) and looks it up (jsr at "
        "0x122c6) in cylinder pressure method 2 (cylinder_pressure_calculation_method 2), the path it takes when the boost "
        "pressure method cannot run: no absolute pressure (a gauge boost sensor and no ambient air pressure sensor), or bit "
        "0x200 / 0x400 of status_32_word_bit_mapped_system_error_status_word_1_0_1 set (bit 4 / 8 with a gauge boost sensor). "
        "The timing correction is cm550_scaleByRatioSigned(result, intake manifold temperature - "
        "expected_intake_temperature_based_on_mass_fuel_rate_calcula_50_to_293, 0x7800) = result x the temperature error / "
        "0x7800, limited to +-0xaa (+-20 degrees). So the result is crank degrees of timing per degree F of intake manifold "
        "temperature error: CPCS03YA is C/F at 1/2048, the temperature 1/128 F and the timing 0.1171875 degree per count, and "
        "2048 x 128 x 0.1171875 = 30720 = 0x7800. The e2m text 'ratio of deg. F to deg. TVC' reads the other way round; its "
        "unit and the code give timing per temperature degree. The rows inside are removed (were 0x800212 "
        "manifold_temp_table_2_type / 0x800214 manifold_temp_table_2_x_ptr / 0x800218 speed_based_parameter_lookup_result / "
        "0x80021a manifold_temp_table_2_z_ptr). (was manifold_temp_table_1_z_ptr; PR #53 round 95)"),
    "0x0006065c": (
        "e2m 108E +0 CPCS03YA 'DATA AXIS FOR RATIO OF DEG. F TO DEG. TVC TABLE' (C/F at 1/2048): the y values of "
        "cylinder_pressure_maintenance_timing_per_temperature_degree_lookup, crank degrees of timing per degree F of intake "
        "manifold temperature error (cylinder pressure method 2 multiplies the temperature error by the value and divides by "
        "0x7800 = 2048 x 128 x 0.1171875 to get timing counts); ROM beyond the dump (no values): word[14] by the e2m layout "
        "(next record CPDSXA at 0x60678). (new row, was DAT_0006065c; PR #53 round 95)"),
    "0x008072f4": (
        "e2m 8226 +0 CBDTT1 'CYLINDER BALANCING THRESHOLD SPEED VECTOR' (RPM): the engine speed x axis that "
        "cylinder_balance_threshold_lookup, cylinder_balance_real_2_dynamics_compensation_lookup and "
        "cylinder_balance_imaginary_2_dynamics_compensation_lookup share, so it is named for its input; vp44_FUN_000127c2 also "
        "scans its points 1-14 (from 0x8072f6) for rpm_speed_bin_index, the index of the two dynamics compensation tables. "
        "dump: byte count 32, 16 points (3200 .. 15200). (was rpm_breakpoint_table; PR #53 round 95)"),
    "0x000611d0": (
        "e2m 10BC +0 EPO2VSAI 'LOW_ & VERY_LOW_OIL_PRESSURE_TABLES INPUT VARIABLE BREAKPOINT' (RPM): the engine speed x axis "
        "that engine_protection_low_oil_pressure_limit_lookup and engine_protection_very_low_oil_pressure_limit_lookup share, "
        "so it is named for its input; ROM beyond the dump (no values): word[7] by the e2m layout (next record EPO2LOTB at "
        "0x611de). (new row, was DAT_000611d0; PR #53 round 95)"),
}
REASON_AMEND = {
    "0x00800102": "Name, type and record CONFIRMED (dump +2 0x807acc 1326 ASTHPFXA / +8 0x807ad8 1327 ASTHPFYA; CM848 uses the same Calterm tables under this name). Comment fix only: '(0x800108)' followed asg_filtered_reference_speed_0_4500 as if it were its address; 0x800108 is this record's x_input and 0x800116 the rate-limited reference (decompiled 0xc8a0).",
    "0x00800184": "Name, type and record CONFIRMED (dump +2 0x6052a 13D6 / +8 switched 0x60534-0x60566 by the jump table at 0x1002e on engine_brake_active_cylinder_count). Comment updated for the 0x800192 rename (full scale torque) and the per-pass x_axis_pointer write (0xfffe).",
    "0x00800192": "Record CONFIRMED (x_input = *(axis+8) at 0x1008c, 6-cylinder table at 0x10010), name AMENDED: the lookup returns the JC6 table at the axis's last point, the value CM848 names engine_retarder_full_scale_torque (stage_6_values[4]); CM550 also has a different J1939 'reference retarder torque' calibration (10FC JCRFRDTQ, 0x8089a6), so 'reference torque' would mislead.",
    "0x0080020e": "Record CONFIRMED (dump +2 0x60640 CPCS03XA / +8 0x6065c CPCS03YA; x_input engine_rpm_primary 0x11eca). Name AMENDED: cm550_scaleByRatioSigned(a,b,c) = a*b/c, correction = result x (IMT - expected)/0x7800, and 1/2048 x 1/128 / (1/30720) = 0.1171875 degree per count exactly: the table is timing per temperature degree, the inverse of the proposal.",
    "0x00060640": "Table CONFIRMED (CPCS03XA, word[14] by the 28-byte gap to CPCS03YA); name AMENDED to pair with its record (timing per temperature degree, see 0x80020e).",
    "0x0006065c": "Table CONFIRMED (CPCS03YA C/F at 1/2048, word[14] by the gap to CPDSXA); name AMENDED: the code multiplies the IMT error by it to get timing counts, so it holds timing per temperature degree.",
    "0x008072f4": "Table CONFIRMED (CBDTT1, dump count 32 -> word[17], gap 34 to CBDTT2; one unreferenced row inside). Name AMENDED: it is the engine speed axis of three lookups (threshold + both dynamics compensation tables) and of the speed bin scan at 0x12a66; the repo's table grammar names a shared axis for its input, and 'threshold axis' misleads at the dynamics compensation uses.",
    "0x000611d0": "Table CONFIRMED (EPO2VSAI RPM, word[7] by the 14-byte gap to EPO2LOTB). Name AMENDED: the axis is shared by the low and very low oil pressure limit lookups; the table grammar names a shared axis for its input (engine speed).",
    "0x0080024e": "Name, type, record CONFIRMED (dump +2 0x8072f4 CBDTT1 / +8 0x807316 CBDTT2; 0x809230 CBDFT compared with 0x809232-6 CBDFM1-3 to pick CBDTG trim gains). Comment updated for the axis rename only.",
    "0x0080025c": "Name, type, record CONFIRMED (dump +8 0x809e9e 823E CBDDCT; result subtracted from 0x80920e CBDFRC2 into 0x809276 CBDARC2 'adjusted real comp_2', clamp +-10000, decompiled 0x127c2). Comment updated for the axis rename only.",
    "0x0080026a": "Name, type, record CONFIRMED (dump +8 0x809ebe 823F CBDI2DCT; result from 0x809212 CBDFIC2 into 0x809278 CBDAIC2). Comment updated for the axis rename only.",
    "0x00801a3e": "Name, type, record CONFIRMED (dump +2 0x611d0 EPO2VSAI / +8 0x611de EPO2LOTB; result 0x80dabe). Comment updated for the axis rename only.",
    "0x00801a4c": "Name, type, record CONFIRMED (pea (0xe,a2) at 0x2590e with a2 = 0x801a3e; dump +8 0x611ec EPO2VLTB; result 0x80dac0). Comment updated for the axis rename only.",
    "0x0006052a": "Table CONFIRMED (13D6 JCBCRPXA, word[5] by the gap; CM848 same record and name, word[5]). Comment updated for the 0x800192 rename.",
    "0x00060566": "Table CONFIRMED (13D5 JC6CTQYA, word[5]; CM848 same name). Comment updated for the 0x800192 rename and the direct read of [4] at 0x2f690.",
    "0x00801e30": "Name, type, record CONFIRMED (dump +2 0x6052a / +8 0x60534 JC1CTQYA; set-up 0x2faa4; lookup at 0x2f6bc, levels 0x11 / 0). Comment fix: the request is scaled by 0x801e2c = stage_4/6_values[4] (0x2f684 / 0x2f690), CM848's full scale torque, not the J1939 reference retarder torque (JCRFRDTQ).",
}

EXTRA = {
    "0x00807176": " Its address is also the loop end of six 18-byte protection record loops and the parameter ID entry of 10BA (0x3596c): those loop compares will render with the table's name (the CM848 quirk the CLAUDE.md accepts; today they render &load_breakpoint_table).",
    "0x00806d3a": " The one element read, 0x806d3c in cm550_processJ1939WetTankPressure (0x20fbc, the raw override default), will render as axis[1].",
    "0x00060552": " Its last value 0x6055a ([4]) is read directly by j1939FormatMultiFrameResponse (0x2f684) as the full scale torque when 0x801e28 is 4.",
    "0x00809e9e": " Reset to 16 x 10000 (0x12c42, 0x13422) and written at T[i] / T[i+1] (0x12b2e / 0x12b56); the lookup reads +2..+32, so its last point reads CBDI2DCT[0] (quirk noted in the comment).",
    "0x00809ebe": " Same layout as CBDDCT; its lookup's last point reads 0x809ede (SSECTMEA), the quirk the comment notes.",
    "0x00807268": " Replaces the unreferenced row retarder_input_threshold_for_state.",
}
UNUSED = {"0x00800278", "0x00800286", "0x00800294", "0x008005b4"}

verdicts = []
for e in props:
    a = e["address"]
    name = NAME.get(a, e["proposed_name"])
    t = e["proposed_type"]
    comment = ""
    if a in FULL:
        comment = FULL[a]
    elif a in REPL:
        comment = e["comment"]
        for old, new in REPL[a]:
            assert comment.count(old) == 1, (a, old)
            comment = comment.replace(old, new)
    blk = summary[a]
    if a in REASON_AMEND:
        reason = REASON_AMEND[a]
        verdict = "AMENDED"
    elif t == "table_lookup_1d_arguments_t":
        ai = int(a, 16)
        xp, yp = l(ai + 2), l(ai + 8)
        xm = re.search(r"x 0x[0-9a-f]+: e2m \[\('0x([0-9a-f]+)', '([^']+)'", blk)
        ym = re.search(r"y 0x[0-9a-f]+: e2m \[\('0x([0-9a-f]+)', '([^']+)'", blk)
        if 0x80a792 <= ai < 0x80a8f0:
            n = (ai - 0x80a792) // 14
            reason = (f"A/D channel {n}: init 0xbcf0 writes 2 / 0x{xp:x} {xm.group(2)} / 0x{yp:x} {ym.group(2)}; loop 0xb7bc "
                      f"(0x80a792 + 14n) x_input adc_raw_value -> unfiltered_value; per-channel rows as for sensor_state_t; unique.")
        elif a in UNUSED:
            reason = (f"Dump +2 0x{xp:x} {xm.group(2)} / +8 0x{yp:x} {ym.group(2)}; only the cited set-up references it (writes "
                      f"2 and both pointers), no call in the dumped ROM; shape from the set-up, name from its tables (medium); "
                      f"rows inside = the listed frozen rows, unreferenced; unique.")
        else:
            reason = (f"Dump +2 0x{xp:x} {xm.group(2)} / +8 0x{yp:x} {ym.group(2)} = cited tables; the cited set-up and callers "
                      f"hold all its references and each call passes it (disassembled); input / output match the decompilation; "
                      f"rows inside = the listed frozen rows; unique.")
        verdict = "CONFIRMED"
    else:
        mm = re.search(r"e2m at address: \[\('0x([0-9a-f]+)', '\+0', '([^']+)'", blk)
        g = re.search(r"gap (\d+) bytes", blk)
        d = re.search(r"dump byte count (\d+)", blk)
        ins = re.search(r"rows inside \[[^)]*\): (\[.*\])", blk)
        n_inside = len([x for x in json.loads(ins.group(1).replace("'", '"').replace("(", "[").replace(")", "]"))
                        if int(x[0], 16) != int(a, 16)])
        reason = (f"e2m {mm.group(1).upper()} {mm.group(2)}; {g.group(1)}-byte gap to the next record = {t}"
                  + (f", matching the dump's {d.group(1)}-byte count" if d and int(d.group(1)) < 1000 else
                     (" (T record, 16 values)" if d else " (beyond the dump)"))
                  + (f"; {n_inside} unreferenced row{'s' if n_inside > 1 else ''} inside" if n_inside else "; no row inside")
                  + "; unique." + EXTRA.get(a, ""))
        verdict = "CONFIRMED"
    v = {"kind": "global", "firmware": "CM550", "address": a, "verdict": verdict, "final_name": name,
         "final_type": t, "reason": reason}
    if comment:
        v["final_comment"] = comment
    verdicts.append(v)

FUNC_COMMENT = (
    "The CM550 1-D table lookup. Its one stack argument is a 14-byte table_lookup_1d_arguments_t: x_axis_offset (the byte "
    "offset of the point the previous lookup found; the search starts there and the new offset is written back), "
    "x_axis_pointer (byte count word then the points), x_input, y_values_pointer (the value of the point at byte offset n is "
    "at y_values_pointer + n) and no_interpolation_flag. It compares the input (unsigned) with the cached point first: below "
    "it, it clamps to the first point or searches down; at or above it, it clamps to the last point or searches up. Below "
    "the first point it returns the first value, at or above the last point the last value, and otherwise the value at the "
    "point at or below the input, linearly interpolated toward the next value (unsigned mulu / divu, one path per slope "
    "sign) unless no_interpolation_flag is nonzero. Counterpart of CM848's lookupTableInterpolation (0x55ef4: five register "
    "arguments, signed / unsigned / step flags, end points checked before the cache, one signed interpolation). (was "
    "lookupTableInterpolation; PR #53 round 95)")
func = {"kind": "function", "firmware": "CM550", "address": "0x00034de0", "verdict": "AMENDED",
        "final_name": "cm550_lookupTableInterpolation", "final_relation": "counterpart", "final_cm848_address": "0x00055ef4",
        "final_comment": FUNC_COMMENT,
        "own_role": ("Looks up a 1-D table through one 14-byte argument record (movea.l (0xc,a7),a2 at 0x34de4): reads the "
                     "cached byte offset +0, axis +2, input +6, values +8 and the no-interpolation word +0xc (0x34e4a); "
                     "compares the input unsigned with the cached point first (0x34df8), clamps to the first point (0x34e10) "
                     "or the last point (0x34e3c) or searches down / up (0x34e06 / 0x34e24), writes only +0 back (0x34e30 / "
                     "0x34e3e) and returns values[offset] or the linear interpolation in two unsigned mulu.w / divu.w paths "
                     "by slope sign (0x34e66)."),
        "reason": ("Role, record layout and counterpart relation CONFIRMED from the disassembly: CM848 0x55ef4 takes r3 "
                   "cache / r4 input / r5 axis / r6 data / r7 flags (bit 0 signed axis, bit 1 signed data, bit 3 step), "
                   "checks the first point (0x56010) and the last point (0x5604c) before the cache (with a 0 -> 1 guard at "
                   "0x56078) and interpolates once signed (mullw / divw 0x5615c / 0x56168): same purpose, different steps "
                   "and order, so not a twin; cm550_ prefix as for cm550_ / cm848_secondOrderFilter and "
                   "_exponentialMovingAverage; the name is unused. 52 calls (42 jsr + 2 movea.l #0x34de0,a4 x 5). Plate "
                   "comment amended only: 'cached byte offset of the last point' read as the axis's last point, which the "
                   "same comment uses for the high clamp.")}
proto = {"kind": "prototype", "firmware": "CM550", "address": "0x00034de0", "verdict": "CONFIRMED",
         "final_name": "cm550_lookupTableInterpolation",
         "reason": ("One 4-byte stack argument at +4 (read at (0xc,a7) after two pushes); every one of the 52 calls pushes one "
                    "long (pea / move.l aN / move.l (-4,a6) / pea (0xe,a2)) and pops 4 (lea (0x14,a7) after the five a4 "
                    "calls); result d0.w (0x34e44 / 0x34e56 / 0x34e78 / 0x34e92). 'table_lookup_1d_arguments_t *' parses "
                    "(ScriptUtils strips the space before '*'); a return row plus param 0 leaves no gap for "
                    "stack_parameter_layout.csv. Replaces the 12-byte table_interp_args_t* row.")}
out = [func, proto] + verdicts
json.dump(out, open(J + "verdicts.json", "w"), indent=1)
print(len(out), "verdicts;", sum(1 for v in out if v["verdict"] == "AMENDED"), "amended")
