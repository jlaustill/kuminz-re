//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort processDiagnosticLimitStatus(void)

{
  word wVar1;
  ushort uVar2;
  uint uVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  short sVar7;
  cm550_engine_protection_channel_state_t *pcVar8;
  engine_protection_channel_configuration_t *configuration;
  
  if (engine_state == ENGINE_STATE_STOPPED) {
    engine_shutdown_command_flag_previous = 0;
  }
  uVar2 = algorithm_enable_flags_2_cal.engine_protection_shutdown_enable;
  if (((algorithm_enable_flags_2_cal.engine_protection_shutdown_enable == 0) ||
      (engine_state == ENGINE_STATE_SHUTDOWN)) || (engine_state == ENGINE_STATE_STOPPED)) {
    engine_protection_shutdown_approaching_flag = 0;
    uVar5 = 0;
    pcVar8 = engine_protection_channel_state_table;
    do {
      pcVar8->fueling_shutdown_time_count = 0;
      pcVar8->engine_speed_shutdown_time_count = 0;
      uVar2 = 0x2e;
      pcVar8 = pcVar8 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 9);
  }
  else if (engine_shutdown_command_flag_previous == 0) {
    engine_protection_shutdown_approaching_flag = 0;
    configuration = engine_protection_channel_configuration_table;
    pcVar8 = engine_protection_channel_state_table;
    uVar6 = 0x72;
    uVar3 = 0;
    if ((general_counter_1 == 0) && (filtered_engine_speed != 0)) {
      _DAT_00800620 = 1;
    }
    else {
      _DAT_00800620 = 0;
    }
    sVar7 = 0;
    for (; configuration < fault_derate_fuel_limit_by_engine_speed_axis;
        configuration = configuration + 1) {
      uVar2 = configuration->configuration_flags;
      sVar4 = (short)uVar3;
      if (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)uVar6 >> 4)] & 1 << (uVar6 & 0xf)) ==
          0) {
        pcVar8->fueling_shutdown_time_count = 0;
        pcVar8->engine_speed_shutdown_time_count = 0;
      }
      else {
        if ((((int)engine_protection_active_fault_index == uVar3) &&
            (*(short *)((int)&engine_protection_channel_history_table[0].fueling_severity_index +
                       (int)sVar7) == 0)) &&
           (*(short *)((int)&engine_protection_channel_history_table[0].engine_speed_severity_index
                      + (int)sVar7) == 0)) {
          engine_protection_active_fault_index = 0xff;
          engine_protection_consecutive_shutdown_count = 0;
        }
        if (((uVar2 & 0x300) == 0) || (pcVar8->errors_allowed == 0)) {
          pcVar8->fueling_shutdown_time_count = 0;
        }
        else {
          if ((uVar2 & 0x100) == 0) {
            wVar1 = cm550_isEngineProtectionInputPastThreshold(configuration,pcVar8,0,3);
            if (wVar1 == 0) {
              pcVar8->fueling_shutdown_time_count = 0;
              pcVar8->fueling_start_warning_time = 0;
            }
            else {
              incrementDiagnosticCounters((dword)configuration,(dword)pcVar8,0);
            }
          }
          else if (configuration->fueling_shutdown_duration_threshold < pcVar8->fueling_duration) {
            incrementDiagnosticCounters((dword)configuration,(dword)pcVar8,0);
          }
          else {
            pcVar8->fueling_shutdown_time_count = 0;
            pcVar8->fueling_start_warning_time = 0;
          }
          if (pcVar8->fueling_start_warning_time < pcVar8->fueling_shutdown_time_count) {
            engine_protection_shutdown_approaching_flag = 1;
          }
          if ((uint)configuration->shutdown_warning_time + (uint)pcVar8->fueling_start_warning_time
              < (uint)pcVar8->fueling_shutdown_time_count) {
            engine_shutdown_command_flag = 1;
            engine_protection_active_fault_index = sVar4;
          }
        }
        if (((uVar2 & 0xc00) == 0) || (pcVar8->errors_allowed == 0)) {
          pcVar8->engine_speed_shutdown_time_count = 0;
        }
        else {
          if ((uVar2 & 0x400) == 0) {
            wVar1 = cm550_isEngineProtectionInputPastThreshold(configuration,pcVar8,1,3);
            if (wVar1 == 0) {
              pcVar8->engine_speed_shutdown_time_count = 0;
              pcVar8->engine_speed_start_warning_time = 0;
            }
            else {
              incrementDiagnosticCounters((dword)configuration,(dword)pcVar8,1);
            }
          }
          else if (configuration->engine_speed_shutdown_duration_threshold <
                   pcVar8->engine_speed_duration) {
            incrementDiagnosticCounters((dword)configuration,(dword)pcVar8,1);
          }
          else {
            pcVar8->engine_speed_shutdown_time_count = 0;
            pcVar8->engine_speed_start_warning_time = 0;
          }
          if (pcVar8->engine_speed_start_warning_time < pcVar8->engine_speed_shutdown_time_count) {
            engine_protection_shutdown_approaching_flag = 1;
          }
          if ((uint)configuration->shutdown_warning_time +
              (uint)pcVar8->engine_speed_start_warning_time <
              (uint)pcVar8->engine_speed_shutdown_time_count) {
            engine_shutdown_command_flag = 1;
            engine_protection_active_fault_index = sVar4;
          }
        }
      }
      pcVar8 = pcVar8 + 1;
      uVar6 = (uint)(ushort)((short)uVar6 + 4);
      sVar7 = sVar7 + 0x1e;
      uVar3 = (uint)(ushort)(sVar4 + 1);
    }
    if (engine_protection_precrank_shutdown_command_flag != 0 ||
        engine_protection_restart_limitation_shutdown_approaching_flag != 0) {
      engine_protection_shutdown_approaching_flag = 1;
    }
    uVar2 = engine_protection_precrank_shutdown_command_flag |
            engine_protection_restart_limitation_shutdown_command_flag;
    if (uVar2 != 0) {
      engine_shutdown_command_flag = 1;
    }
    if ((engine_shutdown_command_flag != 0) && (engine_shutdown_command_flag_previous == 0)) {
      if (engine_protection_shutdown_total != 0xff) {
        engine_protection_shutdown_total = engine_protection_shutdown_total + 1;
      }
      uVar2 = engine_protection_active_fault_index;
      if (engine_protection_active_fault_index == engine_protection_power_up_shutdown_channel) {
        if (engine_protection_consecutive_shutdown_count != 0xff) {
          engine_protection_consecutive_shutdown_count =
               engine_protection_consecutive_shutdown_count + 1;
        }
      }
      else {
        engine_protection_consecutive_shutdown_count = 1;
      }
    }
    engine_shutdown_command_flag_previous = engine_shutdown_command_flag;
  }
  else {
    engine_shutdown_command_flag = 1;
  }
  general_counter_1 = filtered_engine_speed;
  return uVar2;
}



//
