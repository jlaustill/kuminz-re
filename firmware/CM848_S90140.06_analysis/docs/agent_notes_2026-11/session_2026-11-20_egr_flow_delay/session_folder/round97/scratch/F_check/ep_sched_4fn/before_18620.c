//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint cm550_engineProtectionMultiStateSlowCycle40Coordinator(void)

{
  undefined4 in_D0;
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)in_D0 >> 0x10),algorithm_enable_flags_2_cal) & 0xffff0010;
  if (algorithm_enable_flags_2_cal.engine_protection_enable == 0) {
    engine_speed_limit_fault_derate = maximum_rated_engine_speed_0_5000;
    fault_derate_fuel_limit = fuel_demand_maximum;
    fault_derate_active_flag = 0;
    engine_protection_shutdown_approaching_flag = 0;
  }
  else {
    uVar1 = (uint)_engine_protection_state_phase_index;
    switch(uVar1) {
    case 0:
      uVar1 = protectionState0FaultDurationCounter();
      break;
    case 1:
      uVar1 = cm550_protectionState1DiagnosticValidator();
      break;
    case 2:
      uVar1 = cm550_calculateFaultDerateFuelLimit();
      break;
    case 3:
      cm550_calculateFaultDerateEngineSpeedLimit();
      uVar1 = cm550_protectionState3bRpmMonitor();
      break;
    case 4:
      uVar1 = processDiagnosticLimitStatus();
    }
    _engine_protection_state_phase_index = _engine_protection_state_phase_index + 1;
    if (4 < _engine_protection_state_phase_index) {
      _engine_protection_state_phase_index = 0;
      return uVar1;
    }
  }
  return uVar1;
}



//
