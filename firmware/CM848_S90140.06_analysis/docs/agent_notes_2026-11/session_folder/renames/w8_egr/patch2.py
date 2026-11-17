import sys

path = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w8_egr/gen_W8_egr_charge.py"
text = open(path).read()
reps = [
    ("Autozero of the EGR delta pressure sensor: fills the 12-word offset filter block at 0x3fa720 (sensor channel 105 value,",
     "Autozero of the EGR delta pressure sensor: fills the offset filter block at 0x3fa720 (12 words and a pointer: sensor channel 105 value,"),
    ("on the 12-word block {0 offset output,", "on the block (12 words and a pointer) {0 offset output,"),
]
for old, new in reps:
    if text.count(old) != 1:
        sys.exit("count %d: %s" % (text.count(old), old[:70]))
    text = text.replace(old, new)

extra = '''
NOTE("EXACT ROW CHANGES FOR THE APPLIER (global_variables.csv address,name,type; the comment of each row is the evidence of its row above, '(was <old>)' appended): "
     "RETYPE + RENAME (the old row exists, its type changes): "
     "0x003fa73e,egr_valve_driver_over_current_clear_timer,word | 0x003fa740,egr_valve_driver_over_current_fault_counter,word | "
     "0x003fa7bc,egr_valve_h_bridge_fault_reset_flag,word | 0x003fa7ca,egr_valve_h_bridge_fault_retry_active_flag,word | "
     "0x003fa7d0,egr_valve_h_bridge_fault_counter_decrement_enabled_flag,word | 0x003fa172,egr_assist_controller_unstaged_output,word | "
     "0x0040a652,egr_delta_pressure_autozero_enable_flag,word | 0x0040a662,egr_delta_pressure_state,word | "
     "0x0040a70a,egr_valve_autozero_enable_flag,word | 0x0040a716,egr_valve_ready_for_autozero_flag,word | "
     "0x004067f2,egr_valve_derivative_filter_coefficient,word | 0x0040a666,egr_valve_position_autozeroed,i16 | "
     "0x0040a6ca,egr_valve_control_state,EGR_VALVE_CONTROL_STATE | 0x003fa78e,egr_valve_control_state_previous,EGR_VALVE_CONTROL_STATE | "
     "0x003fa716,egr_delta_pressure_autozero_offset_filter_state,ema_filter_state_t | 0x003fa750,egr_valve_delta_pressure_filter_state,ema_filter_state_t | 0x003fa790,egr_valve_derivative_filter_state,ema_filter_state_t. "
     "NEW WORD ROWS (new_global rows above; each replaces the '+N' label row named in its DELETE note, which stage 1 of apply_extras.py removes first): "
     "0x003fa7be,egr_valve_h_bridge_inrush_retry_latch_flag,word | 0x003fa7cc,egr_valve_h_bridge_inrush_retry_timer_at_limit_flag,word | 0x003fa7d2,egr_valve_h_bridge_status_a_input_flag,word | "
     "0x003fa174,egr_assist_controller_egr_valve_staged_position,word | 0x0040a664,egr_valve_position_autozero_offset,word. "
     "DELETE rows without a replacement: 0x003fa794 j1939_handler_param_table_index (accumulator half of the ema_filter_state_t at 0x003fa790). "
     "WIDTH PROOF for every retype: all accesses of the first word are halfword (sth / lhz / lha) in xref_addr.py and in the whole-binary load / store scan, none is a dword, and the second word has its own halfword accesses (or none); "
     "inside 0x3F9800-0x3FDB30 the boot-ROM scan 0x0-0x7F5F (low halfword of the address in any load / store / addi / ori, and aligned 32-bit constants equal to the address) found nothing for any of these addresses or for the other 0x3fa7xx words; "
     "0x3fa790 / 0x3fa794 / 0x3fa716 / 0x3fa750 are stored with stw (pointer and accumulator) by the boot inits and used through cm848_signedFirstOrderFilter's struct pointer. "
     "RENDER NOTE: the names of the rows typed ema_filter_state_t / EGR_VALVE_CONTROL_STATE appear in the C output only after the build, and a retyped dword row changes '._0_2_' / '._2_2_' accesses to plain names (a label-only difference).")
'''
marker = "# --- uncertain rows"
if text.count(marker) != 1:
    sys.exit("marker")
text = text.replace(marker, extra + "\n" + marker)
open(path, "w").write(text)
print("patched2")
