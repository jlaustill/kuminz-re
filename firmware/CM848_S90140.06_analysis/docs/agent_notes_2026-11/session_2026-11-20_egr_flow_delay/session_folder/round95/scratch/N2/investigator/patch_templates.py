"""Scratch helper: tighten the comment / evidence templates of gen_output.py (scratch file only)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/gen_output.py"
s = open(p).read()
a = s.index('        comment = (f"The 14-byte table_lookup_1d_arguments_t record of cm550_lookupTableInterpolation that linearizes')
b = s.index('        conf = "high"\n    else:')
new_ad = '''        comment = (f"A/D channel {n} ({ch.replace('_', ' ')}) linearization record (table_lookup_1d_arguments_t, descriptor {n} of the 25 at 0x80a792 + 14n): "
                   f"cm550_initializeAnalogSensorChannels (0xbcf0) sets x_axis_offset 2 / x_axis_pointer {ch}_linearization_axis (0x{xp:x}) / y_values_pointer {ch}_linearization_values (0x{vp:x}); "
                   f"mc68k_processAnalogSensorChannels (jsr at 0xbbb4, 14-byte steps) looks it up with x_input = {ch}_sensor_state.adc_raw_value into its unfiltered_value while fault_active_flag is 0. "
                   + (f"CM848's cache word for the same axis record: {CM848_AD_CACHE[ch]}_linearization_cached_axis_offset. " if ch in CM848_AD_CACHE else "")
                   + f"(new row, was DAT_{rec:08x}; PR #53 round 95)")
        evidence = (f"init: _DAT_{rec:08x} = 2 and the two pointers; loop: local_8 starts at 0x80a792, input_value = adc_raw_value, local_8 += 14 (&local_8[1].x_axis_ptr); "
                    f"dump +0 {r['dump_offset']} / +2 0x{xp:x} / +8 0x{vp:x} / +0xc 0; 25 x 14 bytes end at 0x80a8f0 (adjusted_user_fueling); no rows inside")
'''
s = s[:a] + new_ad + s[b:]
s = s.replace('''return f"{t['name']} (0x{p:x}, e2m {t['e2m']} '{e2m[mn][4]}')"''', '''return f"{t['name']} (0x{p:x}, {t['e2m']})"''')
for old, new in ((", e2m 13D6 JCBCRPXA)", ", 13D6 JCBCRPXA)"), (", e2m 1075 WSIMAI)", ", 1075 WSIMAI)"),
                 (", e2m 10BA EPFLVSAI)", ", 10BA EPFLVSAI)"), (", e2m 10BC EPO2VSAI)", ", 10BC EPO2VSAI)"),
                 (", e2m 8226 CBDTT1)", ", 8226 CBDTT1)"), (", e2m 13D5 JC6CTQYA; re-pointed per call)", ", 13D5 JC6CTQYA in the dump)"),
                 (", e2m 1076 WSTATB)", ", 1076 WSTATB)"), (", e2m 10BB EPFLTB)", ", 10BB EPFLTB)"), ("(e2m 12E2 HSDVCFYA)", "(12E2 HSDVCFYA)")):
    s = s.replace(old, new)
a = s.index('        comment = (f"The 14-byte table_lookup_1d_arguments_t record of cm550_lookupTableInterpolation: x axis')
b = s.index('    out.append({"firmware": "CM550", "address": f"0x{rec:08x}"')
new_rc = '''        comment = (f"The cm550_lookupTableInterpolation record (table_lookup_1d_arguments_t) of x axis {xs} and y values {vs} (pointers from the RAM dump). "
                   f"{setup} sets x_axis_offset 2 and both pointers. {use}. {inside_txt} ({was(r['current_row'], rec)}; PR #53 round 95)")
        if rec in (0x8005b4, 0x800278, 0x800286, 0x800294):
            evidence = (f"dump +0 {r['dump_offset']} / +2 0x{xp:x} / +6 {r['dump_input']} / +8 0x{vp:x} / +0xc 0; abs_refs.py: only the set-up's writes reference it; "
                        f"no decompiled call and none of the 44 references to 0x34de0 passes it")
        else:
            evidence = (f"dump +0 {r['dump_offset']} / +2 0x{xp:x} / +6 {r['dump_input']} / +8 0x{vp:x} / +0xc 0; users.py: the set-up writes +0 / +2 / +8 and the caller +6; "
                        f"abs_refs.py: nothing writes +0xc")
'''
s = s[:a] + new_rc + s[b:]
s = s.replace('''ev = f"ROM 0x{a:x} is above the 0x40000 dump; next_record.py: the next e2m record {NEXT[a][0]} at {NEXT[a][1]} -> {2 * words} bytes = word[{words}]; the record pointer is 0x{a:x} in the RAM dump"''',
              '''ev = f"ROM above the 0x40000 dump; next_record.py: the next e2m record {NEXT[a][0]} at {NEXT[a][1]} -> {2 * words} bytes = word[{words}]"''')
s = s.replace('''ev = f"RAM dump word at 0x{a:x} = {t['dump_count']} (byte count) -> word[{words}]; it ends at the next e2m record ({NEXT[a][0]} at {NEXT[a][1]}); the record pointer is 0x{a:x}; abs_refs.py: 0 references to the rows inside"''',
              '''ev = f"dump word at 0x{a:x} = {t['dump_count']} (byte count) -> word[{words}], ending at the next e2m record {NEXT[a][0]} ({NEXT[a][1]})" + ("; abs_refs.py: 0 references to the rows inside" if t["inside"] else "")''')
open(p, "w").write(s)
print("patched")
