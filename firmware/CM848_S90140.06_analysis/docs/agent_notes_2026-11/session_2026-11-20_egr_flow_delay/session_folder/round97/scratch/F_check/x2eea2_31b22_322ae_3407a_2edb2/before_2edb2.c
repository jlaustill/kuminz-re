//

undefined2 cm550_parameterLookupForInsite(void)

{
  short sVar1;
  
  if (insite_parameter_id < 0x80) {
    return 2;
  }
  if (insite_parameter_id < 0xc0) {
    return 3;
  }
  if (insite_parameter_id == 0xc1) {
    return CONCAT11((char)(insite_active_fault_count >> 8),(char)insite_active_fault_count + '\x02')
    ;
  }
  if (insite_parameter_id == 0xc2) {
    if (insite_full_detail_response_mode == 0) {
      return CONCAT11((char)(active_j1922_reportable_fault_count >> 8),
                      (insite_fault_change_queue_count + (char)active_j1922_reportable_fault_count)
                      * '\x02' + '\x02');
    }
    sVar1 = (inactive_fault_j1587_reportable_count + active_j1922_reportable_fault_count) * 3;
    return CONCAT11((char)((ushort)sVar1 >> 8),(char)sVar1 + '\x02');
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
