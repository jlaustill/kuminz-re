//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint cm550_diagnosticProtectionEvaluator(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  word *threshold_pointer;
  
  uVar4 = (ushort)algorithm_enable_flags_2_cal & 0x10;
  if (((((algorithm_enable_flags_2_cal.engine_protection_enable != 0) &&
        (uVar4 = algorithm_enable_flags_2_cal.engine_protection_shutdown_enable,
        algorithm_enable_flags_2_cal.engine_protection_shutdown_enable != 0)) &&
       (uVar4 = (ushort)algorithm_enable_flags_2_cal & 0x20,
       algorithm_enable_flags_2_cal.engine_protection_restart_enable != 0)) &&
      ((engine_protection_active_fault_index != 0xff && (engine_protection_active_fault_index != 3))
      )) && (uVar4 = (uint)engine_protection_consecutive_shutdown_count,
            max_number_of_shutdowns_before_restart_is_not_allowed_0_255 <=
            engine_protection_consecutive_shutdown_count)) {
    threshold_pointer =
         (word *)(&engine_protection_config_table_base + engine_protection_active_fault_index * 0x24
                 );
    iVar2 = engine_protection_active_fault_index * 0x2e;
    uVar1 = engine_protection_active_fault_index * 4 + 0x70;
    uVar4 = 0;
    if ((((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 2) >> 4)] &
         1 << (uVar1 + 2) % 0x10) != 0) &&
       (uVar4 = 0,
       ((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 3) >> 4)] &
       1 << (uVar1 + 3) % 0x10) != 0)) {
      uVar1 = *threshold_pointer;
      uVar3 = 0;
      if ((uVar1 & 1) != 0) {
        uVar3 = cm550_protectionConditionEvaluator
                          (threshold_pointer,(dword *)(&protection_system_sensor_data_ptr + iVar2),0
                           ,0);
        if ((short)uVar3 != 0) {
          *(undefined2 *)
           (&coolant_level_system_error_detected_before_cranking_i_1_true_0_false + iVar2) = 1;
          _DAT_0080d28a = 1;
        }
      }
      uVar4 = CONCAT22((short)((uint)uVar3 >> 0x10),uVar1) & 0xffff0002;
      if ((uVar1 & 2) != 0) {
        uVar4 = cm550_protectionConditionEvaluator
                          (threshold_pointer,(dword *)(&protection_system_sensor_data_ptr + iVar2),1
                           ,0);
        if ((short)uVar4 != 0) {
          *(undefined2 *)
           (&coolant_level_system_error_detected_before_cranking_i_1_true_0_false + iVar2) = 1;
          _DAT_0080d28a = 1;
        }
      }
    }
  }
  return uVar4;
}



//
