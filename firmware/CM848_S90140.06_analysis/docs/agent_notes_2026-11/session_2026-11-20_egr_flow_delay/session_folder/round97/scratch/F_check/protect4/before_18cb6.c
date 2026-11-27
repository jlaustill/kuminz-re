//

ushort cm550_protectionState1DiagnosticValidator(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined *threshold_value;
  word *configuration_pointer;
  undefined *channel_state_record;
  
  uVar1 = algorithm_enable_flags_2_cal.engine_protection_shutdown_enable;
  if (((algorithm_enable_flags_2_cal.engine_protection_shutdown_enable != 0) &&
      (uVar1 = (ushort)algorithm_enable_flags_2_cal & 0x20,
      algorithm_enable_flags_2_cal.engine_protection_restart_enable != 0)) &&
     (engine_protection_active_fault_index != 0xff)) {
    channel_state_record = &protection_system_sensor_data_ptr;
    threshold_value = &coolant_level_fueling_severity_index_0_0_1_0;
    uVar2 = 0x70;
    uVar3 = 0;
    for (configuration_pointer = (word *)&engine_protection_config_table_base;
        configuration_pointer < fault_derate_fuel_limit_by_engine_speed_axis;
        configuration_pointer = configuration_pointer + 0x12) {
      if ((((int)engine_protection_active_fault_index == uVar3) &&
          (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar2 + 2) >> 4)] &
           1 << (uVar2 + 2) % 0x10) != 0)) &&
         (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar2 + 3) >> 4)] &
          1 << (uVar2 + 3) % 0x10) != 0)) {
        cm550_diagnosticProtectionProcessor
                  (configuration_pointer,(dword)channel_state_record,(dword)threshold_value);
        cm550_updateEngineProtectionRestartLimitationCommands
                  ((word)uVar3,channel_state_record,configuration_pointer);
      }
      else {
        *(undefined2 *)(threshold_value + 4) = 0;
        *(undefined2 *)(threshold_value + 6) = 0;
      }
      channel_state_record = channel_state_record + 0x2e;
      uVar1 = 0x1e;
      threshold_value = threshold_value + 0x1e;
      uVar2 = (uint)(ushort)((short)uVar2 + 4);
      uVar3 = (uint)(ushort)((word)uVar3 + 1);
    }
  }
  return uVar1;
}



//
