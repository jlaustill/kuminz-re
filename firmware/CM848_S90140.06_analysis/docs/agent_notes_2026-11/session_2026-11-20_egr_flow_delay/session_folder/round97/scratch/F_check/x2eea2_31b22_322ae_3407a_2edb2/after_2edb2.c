//

/* Returns how many bytes the ECM's reply for the requested J1587 PID (insite_parameter_id) will
   take, the PID byte included. Values: 2 below PID 128 and 3 below 192. PID 193:
   insite_active_fault_count + 2. PID 194: two bytes per code ((active_j1922_reportable_fault_count
   + insite_fault_change_queue_count) x 2 + 2), or three with insite_full_detail_response_mode
   ((active_j1922_reportable_fault_count + inactive_fault_j1587_reportable_count) x 3 + 2). PID 196:
   4 / 2 / 7 (insite_dtc_command_action_byte & 0xc0 set / no insite_matched_dtc_fault_code /
   otherwise). PID 234: 24, PID 237: 22, PID 243: 31, any other PID: 6. The J1708 request parser
   0x1e956 stores the result in insite_parameter_data_size, and cm550_activeParameterReadFunction
   checks it against the space left in the reply. It takes no argument and returns a byte (was
   cm550_parameterLookupForInsite; PR #53 round 97). (was cm550_parameterLookupForInsite; PR #53
   round 97) */

byte cm550_getJ1587ReplyParameterLength(void)

{
  if (insite_parameter_id < 0x80) {
    return 2;
  }
  if (insite_parameter_id < 0xc0) {
    return 3;
  }
  if (insite_parameter_id == 0xc1) {
    return (char)insite_active_fault_count + 2;
  }
  if (insite_parameter_id == 0xc2) {
    if (insite_full_detail_response_mode == 0) {
      return (insite_fault_change_queue_count + (char)active_j1922_reportable_fault_count) * '\x02'
             + 2;
    }
    return ((char)inactive_fault_j1587_reportable_count + (char)active_j1922_reportable_fault_count)
           * '\x03' + 2;
  }
  if (insite_parameter_id == 0xc4) {
    if ((insite_dtc_command_action_byte & 0xc0) != 0) {
      return 4;
    }
    if (insite_matched_dtc_fault_code == 0) {
      return 2;
    }
    return 7;
  }
  if (insite_parameter_id == 0xea) {
    return 0x18;
  }
  if (insite_parameter_id == 0xed) {
    return 0x16;
  }
  if (insite_parameter_id == 0xf3) {
    return 0x1f;
  }
  return 6;
}



//
