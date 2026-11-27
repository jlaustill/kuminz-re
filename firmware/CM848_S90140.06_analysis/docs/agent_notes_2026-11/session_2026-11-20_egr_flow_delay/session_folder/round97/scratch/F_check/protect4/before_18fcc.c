//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort processDiagnosticLimitStatus(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  short sVar7;
  dword *state_pointer;
  undefined *puVar8;
  word *threshold_pointer;
  
  if (engine_state == ENGINE_STATE_STOPPED) {
    engine_shutdown_command_flag_previous = 0;
  }
  uVar2 = algorithm_enable_flags_2_cal.engine_protection_shutdown_enable;
  if (((algorithm_enable_flags_2_cal.engine_protection_shutdown_enable == 0) ||
      (engine_state == ENGINE_STATE_SHUTDOWN)) || (engine_state == ENGINE_STATE_STOPPED)) {
    engine_protection_shutdown_approaching_flag = 0;
    uVar5 = 0;
    puVar8 = &protection_system_sensor_data_ptr;
    do {
      *(undefined2 *)(puVar8 + 0x1a) = 0;
      *(undefined2 *)(puVar8 + 0x1c) = 0;
      uVar2 = 0x2e;
      puVar8 = puVar8 + 0x2e;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 9);
  }
  else if (engine_shutdown_command_flag_previous == 0) {
    engine_protection_shutdown_approaching_flag = 0;
    threshold_pointer = (word *)&engine_protection_config_table_base;
    state_pointer = (dword *)&protection_system_sensor_data_ptr;
    uVar6 = 0x72;
    uVar3 = 0;
    if ((general_counter_1 == 0) && (filtered_engine_speed != 0)) {
      _DAT_00800620 = 1;
    }
    else {
      _DAT_00800620 = 0;
    }
    sVar7 = 0;
    for (; threshold_pointer < fault_derate_fuel_limit_by_engine_speed_axis;
        threshold_pointer = threshold_pointer + 0x12) {
      uVar2 = *threshold_pointer;
      sVar4 = (short)uVar3;
      if (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)uVar6 >> 4)] & 1 << (uVar6 & 0xf)) ==
          0) {
        *(undefined2 *)((int)state_pointer + 0x1a) = 0;
        *(undefined2 *)(state_pointer + 7) = 0;
      }
      else {
        if ((((int)engine_protection_active_fault_index == uVar3) &&
            (*(short *)(&coolant_level_fueling_severity_index_0_0_1_0 + sVar7) == 0)) &&
           (*(short *)(&severity_index_for_epf_coolant_level_fault_0_0_1_0 + sVar7) == 0)) {
          engine_protection_active_fault_index = 0xff;
          engine_protection_consecutive_shutdown_count = 0;
        }
        if (((uVar2 & 0x300) == 0) || (*(short *)((int)state_pointer + 0x16) == 0)) {
          *(undefined2 *)((int)state_pointer + 0x1a) = 0;
        }
        else {
          if ((uVar2 & 0x100) == 0) {
            sVar1 = cm550_protectionConditionEvaluator(threshold_pointer,state_pointer,0,3);
            if (sVar1 == 0) {
              *(undefined2 *)((int)state_pointer + 0x1a) = 0;
              *(undefined2 *)((int)state_pointer + 0x1e) = 0;
            }
            else {
              incrementDiagnosticCounters((dword)threshold_pointer,(dword)state_pointer,0);
            }
          }
          else if (threshold_pointer[8] < *(ushort *)((int)state_pointer + 6)) {
            incrementDiagnosticCounters((dword)threshold_pointer,(dword)state_pointer,0);
          }
          else {
            *(undefined2 *)((int)state_pointer + 0x1a) = 0;
            *(undefined2 *)((int)state_pointer + 0x1e) = 0;
          }
          if (*(ushort *)((int)state_pointer + 0x1e) < *(ushort *)((int)state_pointer + 0x1a)) {
            engine_protection_shutdown_approaching_flag = 1;
          }
          if ((uint)threshold_pointer[0xf] + (uint)*(ushort *)((int)state_pointer + 0x1e) <
              (uint)*(ushort *)((int)state_pointer + 0x1a)) {
            engine_shutdown_command_flag = 1;
            engine_protection_active_fault_index = sVar4;
          }
        }
        if (((uVar2 & 0xc00) == 0) || (*(short *)((int)state_pointer + 0x16) == 0)) {
          *(undefined2 *)(state_pointer + 7) = 0;
        }
        else {
          if ((uVar2 & 0x400) == 0) {
            sVar1 = cm550_protectionConditionEvaluator(threshold_pointer,state_pointer,1,3);
            if (sVar1 == 0) {
              *(undefined2 *)(state_pointer + 7) = 0;
              *(undefined2 *)(state_pointer + 8) = 0;
            }
            else {
              incrementDiagnosticCounters((dword)threshold_pointer,(dword)state_pointer,1);
            }
          }
          else if (threshold_pointer[9] < *(ushort *)(state_pointer + 2)) {
            incrementDiagnosticCounters((dword)threshold_pointer,(dword)state_pointer,1);
          }
          else {
            *(undefined2 *)(state_pointer + 7) = 0;
            *(undefined2 *)(state_pointer + 8) = 0;
          }
          if (*(ushort *)(state_pointer + 8) < *(ushort *)(state_pointer + 7)) {
            engine_protection_shutdown_approaching_flag = 1;
          }
          if ((uint)threshold_pointer[0xf] + (uint)*(ushort *)(state_pointer + 8) <
              (uint)*(ushort *)(state_pointer + 7)) {
            engine_shutdown_command_flag = 1;
            engine_protection_active_fault_index = sVar4;
          }
        }
      }
      state_pointer = (dword *)((int)state_pointer + 0x2e);
      uVar6 = (uint)(ushort)((short)uVar6 + 4);
      sVar7 = sVar7 + 0x1e;
      uVar3 = (uint)(ushort)(sVar4 + 1);
    }
    if (_DAT_0080d28a != 0 ||
        epf_shutdown_approaching_command_from_restart_limitat_1_true_0_false != 0) {
      engine_protection_shutdown_approaching_flag = 1;
    }
    uVar2 = _DAT_0080d28a | epf_shutdown_engine_command_from_restart_limitation_a_1_true_0_false;
    if (uVar2 != 0) {
      engine_shutdown_command_flag = 1;
    }
    if ((engine_shutdown_command_flag != 0) && (engine_shutdown_command_flag_previous == 0)) {
      if (_DAT_008058d2 != 0xff) {
        _DAT_008058d2 = _DAT_008058d2 + 1;
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
