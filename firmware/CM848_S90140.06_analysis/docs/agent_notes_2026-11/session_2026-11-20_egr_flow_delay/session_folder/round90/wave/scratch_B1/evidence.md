# Batch B1 scratch evidence (CM550 J90350.00)

All 20 rows = the Y-axis (output values) of the A/D linearization lookup of channels 3-24 (minus 7/8, batch C).
cm550_initializeAnalogSensorChannels @0xbcf0: a5=0x80a792; per channel n: move.w #2,(14n,a5) [current_index],
move.l #X,(14n+2,a5) [x_axis_ptr], move.l #Y,(14n+8,a5) [y_axis_ptr]. 25 descriptors, 14-byte stride.
mc68k_processAnalogSensorChannels @0xb7bc walks descriptor n with sensor_state_t n / sensor_config_t n:
input_value = adc_raw_value; unfiltered_value = lookupTableInterpolation(descriptor).
lookupTableInterpolation @0x34de0: X[0] = byte length (move.w (a0),a1; adda.l a0,a1); Y read as
move.w (a1) / move.w (2,a1) with a1 = y_axis_ptr + byte index (>= 2); cmp.w + bcs, mulu/divu -> unsigned words.
Y+0 = its own byte-length word (== X+0 in every dump table); never read by the interpolator.

Layout (X then Y, packed; each = 1 + len/2 words; dump header == size-2 in all 25):
ch0 IMT    X 0x806d3a w26  Y 0x806d6e w26
ch1 FT     X 0x806da2 w22  Y 0x806dce w22
ch2 CV     X 0x806dfa w9   Y 0x806e0c w9
ch3 FP     X 0x806e1e w3   Y 0x806e24 w3   (0,1023)
ch4 OLPR   X 0x806e2a w6   Y 0x806e36 w6   (0,0,0,13184,13184)
ch5 BSPR   X 0x806e42 w5   Y 0x806e4c w5   (0,0,6438,6438)
ch6 CLTP   X 0x806e56 w26  Y 0x806e8a w26
ch7 AAT    X 0x806ebe w9   Y 0x806ed0 w9   (row ADAATXA - batch C)
ch8 POTP   X 0x806ee2 w3   Y 0x806ee8 w3   (row ADPOTPXA - batch C)
ch9 EP     X 0x806eee w3   Y 0x806ef4 w3   (0,16)
ch10 SATH  X 0x806efa w7   Y 0x806f08 w7   (0,0,400,400,0,0)
ch11 ROTH  X 0x806f16 w7   Y 0x806f24 w7   (0,0,400,400,0,0)
ch12 AAPR  X 0x806f32 w5   Y 0x806f3c w5   (629,629,1924,1924)
ch13 BTVT  X 0x806f46 w3   Y 0x806f4c w3   (0,307)
ch14 ESSV  X 0x806f52 w3   Y 0x806f58 w3   (0,6)
ch15 THSV  X 0x806f5e w3   Y 0x806f64 w3   (0,6)
ch16 VHSV  X 0x806f6a w3   Y 0x806f70 w3   (0,6)
ch17 ECSV  X 0x806f76 w3   Y 0x806f7c w3   (0,6)
ch18 FTSV  X 0x806f82 w3   Y 0x806f88 w3   (0,48)
ch19 CR    X 0x806f8e w19  Y 0x806fb4 w19  (0,0,4,4,1,1,4,4,2,2,4,4,3,3,4,4,5,5)
ch20 WF    X 0x806fda w9   Y 0x806fec w9   (0,0,1,1,2,2,2,2)
ch21 EGCF  X 0x806ffe w4   Y 0x807006 w4   (0,32,32)
ch22 PSSV  X 0x80700e w3   Y 0x807014 w3   (0,16)
ch23 HBSV  X 0x80701a w3   Y 0x807020 w3   (0,55)
ch24 OCSV  X 0x807026 w3   Y 0x80702c w3   (0,22)

Live check (extended RAM descriptors + sensor_state_t): table(adc_raw_value) == unfiltered_value for ch 2, 3, 5, 13 (355->106 = 13.25 V),
14-17 (853->5), 19 (980->4), 20 (1023->2), 23 (464->24), 24 (728->15).

Rows inside tables (stale, no code user): 0x806fb6 shutdown_protection_param_1, 0x806fb8 shutdown_protection_param_2 (inside ch19 Y);
0x806fa0-0x806fb2 timing_protection_* / fuel_* / timing_blend_threshold (inside ch19 X); 0x806d40-0x806e14 linearization_table_chNN_* (6-byte grid
assumption, inside ch0-ch2 tables); 0x806e1a fuel_limit_rpm_error_offset + 0x806e1c diagnostic_exit_limit inside ch2 Y;
0x806e1e diagnostic_transition_limit = ch3 X axis (its only use is the x_axis_ptr store).
