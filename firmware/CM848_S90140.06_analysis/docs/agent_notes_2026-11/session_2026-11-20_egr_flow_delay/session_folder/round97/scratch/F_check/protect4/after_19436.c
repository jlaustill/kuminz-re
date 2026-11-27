//

/* For the current channel's fueling (is_engine_speed 0) or engine speed (1) fault: when its fault
   bit is set in 0x806000 and clear in 0x806040, it clears the 0x806000 bit (interrupts masked). If
   the log entry is open (log flag set), it closes it: the flag is cleared, duration =
   key_on_hour_meter - occurrence_time (low words) and the log index advances modulo 5. CM848's
   counterpart waits for the registered bit, clears both the detected and registered bits and copies
   the entry into the state (was protectionStateValidator). (was protectionStateValidator; PR #53
   round 97) */

void cm550_closeEngineProtectionFaultLogEntry(word is_engine_speed)

{
  word wVar1;
  word *pwVar2;
  engine_protection_fault_log_entry_t *peVar3;
  word *pwVar4;
  
  if (is_engine_speed == 0) {
    pwVar2 = &engine_protection_current_history->fueling_fault_log_index;
    wVar1 = engine_protection_current_configuration->fueling_fault_index;
    peVar3 = engine_protection_current_state->fueling_fault_log_pointer;
    pwVar4 = &engine_protection_current_history->fueling_fault_log_flag;
  }
  else {
    pwVar2 = &engine_protection_current_history->engine_speed_fault_log_index;
    wVar1 = engine_protection_current_configuration->engine_speed_fault_index;
    peVar3 = engine_protection_current_state->engine_speed_fault_log_pointer;
    pwVar4 = &engine_protection_current_history->engine_speed_fault_log_flag;
  }
  if (((uint)*(ushort *)
              (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
              (short)((int)(uint)wVar1 >> 4) * 2) & 1 << (wVar1 & 0xf)) != 0) {
    if (((uint)*(ushort *)
                (&fault_first_occurrence_flags_word_0 + (short)((int)(uint)wVar1 >> 4) * 2) &
        1 << (wVar1 & 0xf)) == 0) {
      *(ushort *)
       (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
       (short)((int)(uint)wVar1 >> 4) * 2) =
           ~(1 << (wVar1 & 0xf)) &
           *(ushort *)
            (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
            (short)((int)(uint)wVar1 >> 4) * 2);
      if (*pwVar4 != 0) {
        *pwVar4 = 0;
        peVar3[*pwVar2].duration = key_on_hour_meter._2_2_ - (short)peVar3[*pwVar2].occurrence_time;
        *pwVar2 = *pwVar2 + 1;
        *pwVar2 = *pwVar2 % 5;
      }
    }
  }
  return;
}



//
