//

/* The engine protection task scheduler, run at executive frame 15 of 40 (jsr at 0x1bb9a in
   executiveFrameInterruptHandler). With algorithm_enable_flags_2_cal.engine_protection_enable
   (EPEN) clear it sets the outputs to no derate: engine_speed_limit_fault_derate (EPESLM) =
   maximum_rated_engine_speed, fault_derate_fuel_limit (EPFLLM) = fuel_demand_maximum,
   fault_derate_active_flag and engine_protection_shutdown_approaching_flag = 0. Otherwise it runs
   one task per call by engine_protection_task_index (0-4, then 0 again):
   countEngineProtectionOverLimitDurations, updateEngineProtectionRestartSeverity,
   cm550_calculateFaultDerateFuelLimit, cm550_calculateFaultDerateEngineSpeedLimit with
   logEngineProtectionChannelFaults, and processDiagnosticLimitStatus (the shutdown). CM848's
   counterpart cm848_runFaultDerateScheduler also sets engine_protection_timer_state, runs the
   precrank examination every pass and latches the shutdown override in task 1 (was
   cm550_engineProtectionMultiStateSlowCycle40Coordinator). (was
   cm550_engineProtectionMultiStateSlowCycle40Coordinator; PR #53 round 97) */

void cm550_runEngineProtectionScheduler(void)

{
  if (algorithm_enable_flags_2_cal.engine_protection_enable == 0) {
    engine_speed_limit_fault_derate = maximum_rated_engine_speed_0_5000;
    fault_derate_fuel_limit = fuel_demand_maximum;
    fault_derate_active_flag = 0;
    engine_protection_shutdown_approaching_flag = 0;
  }
  else {
    switch(engine_protection_task_index) {
    case ENGINE_PROTECTION_TASK_OVER_LIMIT_DURATIONS:
      countEngineProtectionOverLimitDurations();
      break;
    case ENGINE_PROTECTION_TASK_RESTART_SEVERITY:
      updateEngineProtectionRestartSeverity();
      break;
    case ENGINE_PROTECTION_TASK_FAULT_DERATE_FUEL_LIMIT:
      cm550_calculateFaultDerateFuelLimit();
      break;
    case ENGINE_PROTECTION_TASK_ENGINE_SPEED_LIMIT_AND_FAULT_LOGS:
      cm550_calculateFaultDerateEngineSpeedLimit();
      logEngineProtectionChannelFaults();
      break;
    case ENGINE_PROTECTION_TASK_SHUTDOWN:
      processDiagnosticLimitStatus();
    }
    engine_protection_task_index =
         engine_protection_task_index + ENGINE_PROTECTION_TASK_RESTART_SEVERITY;
    if (ENGINE_PROTECTION_TASK_SHUTDOWN < engine_protection_task_index) {
      engine_protection_task_index = ENGINE_PROTECTION_TASK_OVER_LIMIT_DURATIONS;
      return;
    }
  }
  return;
}



//
