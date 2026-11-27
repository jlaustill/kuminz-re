//

/* Returns 1 when the channel's input is past the threshold picked by is_engine_speed and
   threshold_select. Select 0 is the word at the state's minimum threshold pointer (fueling) or
   engine speed lower limit pointer, 2 the shutdown duration threshold (configuration +0x10 / +0x12)
   and 3 the shutdown severity threshold (+0x20 / +0x22). Configuration flag 0x4 means at or above,
   else below, with unsigned compares. A switch channel (flags 0x30) is past when ((input &
   input_mask) != 0) equals (flag 0x10 != 0). CM848's counterpart compares signed, has select 1 (the
   maximum threshold) and an unwired switch case (was cm550_protectionConditionEvaluator). (was
   cm550_protectionConditionEvaluator; PR #53 round 97) */

word cm550_isEngineProtectionInputPastThreshold
               (engine_protection_channel_configuration_t *configuration,
               cm550_engine_protection_channel_state_t *state,word is_engine_speed,
               word threshold_select)

{
  ushort uVar1;
  ushort uVar2;
  ushort unaff_D3w;
  
  uVar1 = configuration->configuration_flags;
  if ((uVar1 & 0x30) == 0) {
    uVar2 = *state->input_pointer;
    if (is_engine_speed == 0) {
      if (threshold_select == 0) {
        unaff_D3w = *state->minimum_threshold_pointer;
      }
      else if (threshold_select == 2) {
        unaff_D3w = configuration->fueling_shutdown_duration_threshold;
      }
      else if (threshold_select == 3) {
        unaff_D3w = configuration->fueling_shutdown_severity_threshold;
      }
    }
    else if (threshold_select == 0) {
      unaff_D3w = *state->engine_speed_lower_limit_pointer;
    }
    else if (threshold_select == 2) {
      unaff_D3w = configuration->engine_speed_shutdown_duration_threshold;
    }
    else if (threshold_select == 3) {
      unaff_D3w = configuration->engine_speed_shutdown_severity_threshold;
    }
    if ((uVar1 & 4) == 0) {
      if (uVar2 < unaff_D3w) {
        return 1;
      }
    }
    else if (unaff_D3w <= uVar2) {
      return 1;
    }
  }
  else if (((state->input_mask & *state->input_pointer) != 0) == ((uVar1 & 0x10) != 0)) {
    return 1;
  }
  return 0;
}



//
