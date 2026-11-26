//

/* Task 1 of cm550_runEngineProtectionScheduler. With the engine protection shutdown and restart
   enabled (EPSOEN / EPRYEN) and a shutdown channel recorded (engine_protection_active_fault_index
   not 255), it walks the nine channels (configuration, state and history records, enable bit 112 +
   4n). The recorded channel, when its shutdown and restart bits (+2 / +3) are set, gets
   updateEngineProtectionRestartSeverityIndexes and
   cm550_updateEngineProtectionRestartLimitationCommands. Every other channel, and the recorded one
   while either of those bits is clear, has both restart severity indexes (history +4 / +6) cleared.
   The twin of CM848 0x5084b4: one shared name; only layout constants differ (CM848's enable bits
   start at 128, its state records are 62 bytes and its table has one channel) (was
   cm550_protectionState1DiagnosticValidator / cm848_updateEngineProtectionRestartSeverity). (was
   cm550_protectionState1DiagnosticValidator; PR #53 round 97) */

void updateEngineProtectionRestartSeverity(void)

{
  uint uVar1;
  uint uVar2;
  engine_protection_channel_history_t *history;
  engine_protection_channel_configuration_t *configuration;
  cm550_engine_protection_channel_state_t *state;
  
  if (((algorithm_enable_flags_2_cal.engine_protection_shutdown_enable != 0) &&
      (algorithm_enable_flags_2_cal.engine_protection_restart_enable != 0)) &&
     (engine_protection_active_fault_index != 0xff)) {
    state = engine_protection_channel_state_table;
    history = engine_protection_channel_history_table;
    uVar1 = 0x70;
    uVar2 = 0;
    for (configuration = engine_protection_channel_configuration_table;
        configuration < fault_derate_fuel_limit_by_engine_speed_axis;
        configuration = configuration + 1) {
      if ((((int)engine_protection_active_fault_index == uVar2) &&
          (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 2) >> 4)] &
           1 << (uVar1 + 2) % 0x10) != 0)) &&
         (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 3) >> 4)] &
          1 << (uVar1 + 3) % 0x10) != 0)) {
        updateEngineProtectionRestartSeverityIndexes(configuration,state,history);
        cm550_updateEngineProtectionRestartLimitationCommands((word)uVar2,state,configuration);
      }
      else {
        history->fueling_restart_severity_index = 0;
        history->engine_speed_restart_severity_index = 0;
      }
      state = state + 1;
      history = history + 1;
      uVar1 = (uint)(ushort)((short)uVar1 + 4);
      uVar2 = (uint)(ushort)((word)uVar2 + 1);
    }
  }
  return;
}



//
