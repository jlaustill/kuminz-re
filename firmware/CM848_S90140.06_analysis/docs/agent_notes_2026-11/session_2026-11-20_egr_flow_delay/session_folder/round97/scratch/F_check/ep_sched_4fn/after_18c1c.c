//

/* Sets the channel's restart severity indexes in its history record. With configuration flag 0x1
   the fueling one (EP??FLRI, +4) is 0 while the input is inside its fueling threshold, else 0x100
   with flag 0x40, else cm550_interpolateEngineProtectionSeverity of the input between the minimum
   and maximum thresholds. With flag 0x2 the engine speed one (EP??RPRI, +6) is 0 or 0x100. Called
   by updateEngineProtectionRestartSeverity for the recorded shutdown channel. The twin of CM848
   0x50832c: one shared name (was cm550_diagnosticProtectionProcessor /
   cm848_updateEngineProtectionRestartSeverityIndexes). (was cm550_diagnosticProtectionProcessor; PR
   #53 round 97) */

void updateEngineProtectionRestartSeverityIndexes
               (engine_protection_channel_configuration_t *configuration,
               cm550_engine_protection_channel_state_t *state,
               engine_protection_channel_history_t *history)

{
  ushort uVar1;
  word wVar2;
  
  uVar1 = configuration->configuration_flags;
  if ((uVar1 & 1) != 0) {
    wVar2 = cm550_isEngineProtectionInputPastThreshold(configuration,state,0,0);
    if (wVar2 == 0) {
      history->fueling_restart_severity_index = 0;
    }
    else if ((uVar1 & 0x40) == 0) {
      wVar2 = cm550_interpolateEngineProtectionSeverity
                        (*state->input_pointer,*state->minimum_threshold_pointer,
                         *state->maximum_threshold_pointer);
      history->fueling_restart_severity_index = wVar2;
    }
    else {
      history->fueling_restart_severity_index = 0x100;
    }
  }
  if ((uVar1 & 2) != 0) {
    wVar2 = cm550_isEngineProtectionInputPastThreshold(configuration,state,1,0);
    if (wVar2 == 0) {
      history->engine_speed_restart_severity_index = 0;
      return;
    }
    history->engine_speed_restart_severity_index = 0x100;
  }
  return;
}



//
