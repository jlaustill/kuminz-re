//

/* For the current channel (engine_protection_current_configuration / _state / _history, stepped by
   logEngineProtectionChannelFaults), records an active fueling (is_engine_speed 0) or engine speed
   (1) fault. The first time (log flag EP??FLFG / RPFG clear) it opens the entry at the log index
   (EP??FLIN / RPIN) of the channel's fault log: occurrence_time = key_on_hour_meter, duration 0,
   and the extreme preset to 0xffff (configuration flag 0x8) or 0. Then, with interrupts masked, it
   sets the fault bit (configuration +0x1a / +0x1c, EP??FLFU / RPFU) in 0x806000 and 0x806040, and
   with flags 0xc it keeps the input's extreme in the entry. CM848's counterpart presets 0x7fff /
   0x8000, sets one fault array and copies the entry into the state (was protectionStateProcessor).
   (was protectionStateProcessor; PR #53 round 97) */

void cm550_recordEngineProtectionFaultLogEntry(word is_engine_speed)

{
  engine_protection_fault_log_entry_t *peVar1;
  word wVar2;
  word wVar3;
  ushort uVar4;
  word *pwVar5;
  engine_protection_fault_log_entry_t *peVar6;
  
  if (is_engine_speed == 0) {
    wVar3 = engine_protection_current_history->fueling_fault_log_index;
    wVar2 = engine_protection_current_configuration->fueling_fault_index;
    peVar6 = engine_protection_current_state->fueling_fault_log_pointer;
    pwVar5 = &engine_protection_current_history->fueling_fault_log_flag;
  }
  else {
    wVar3 = engine_protection_current_history->engine_speed_fault_log_index;
    wVar2 = engine_protection_current_configuration->engine_speed_fault_index;
    peVar6 = engine_protection_current_state->engine_speed_fault_log_pointer;
    pwVar5 = &engine_protection_current_history->engine_speed_fault_log_flag;
  }
  if (*pwVar5 == 0) {
    *pwVar5 = 1;
    peVar1 = peVar6 + wVar3;
    peVar1->occurrence_time = key_on_hour_meter;
    peVar1->duration = 0;
    if ((engine_protection_current_configuration->configuration_flags & 8) == 0) {
      peVar1->extreme_value = 0;
    }
    else {
      peVar1->extreme_value = 0xffff;
    }
  }
  uVar4 = 1 << (wVar2 & 0xf);
  *(ushort *)
   (&status_32_word_bit_mapped_system_error_status_word_0_0_1 + (short)((int)(uint)wVar2 >> 4) * 2)
       = uVar4 | *(ushort *)
                  (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
                  (short)((int)(uint)wVar2 >> 4) * 2);
  *(ushort *)(&fault_first_occurrence_flags_word_0 + (short)((int)(uint)wVar2 >> 4) * 2) =
       uVar4 | *(ushort *)
                (&fault_first_occurrence_flags_word_0 + (short)((int)(uint)wVar2 >> 4) * 2);
  if ((engine_protection_current_configuration->configuration_flags & 0xc) != 0) {
    wVar2 = cm550_isEngineProtectionInputMoreExtreme
                      (*engine_protection_current_state->input_pointer,peVar6[wVar3].extreme_value,
                       engine_protection_current_configuration->configuration_flags);
    if (wVar2 != 0) {
      peVar6[wVar3].extreme_value = *engine_protection_current_state->input_pointer;
    }
  }
  return;
}



//
