// Function: sensorChannelTypeB_configInit @ 0x005012dc
//

/* WARNING: Unable to use type for symbol recovery_decrement */
/* review-function-readability reviewed 2026-06-12 - Readability MEDIUM (irreducible
   converging-epilogue gotos + 3 split-remnant scratch temps Ghidra will not let CSV name) Accuracy
   Confidence High. config_ptr typed as sensor_channel_config_t* (7 default/threshold/debounce
   fields render); DAT_003fd8e8 -> governor_temp_protection_disable (now
   oil_pressure_switch_only_cal); 11 locals named; 2 array globals renamed. 13-param PowerPC
   prototype; params 4-6 passed but unused. */

void sensorChannelTypeB_configInit
               (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr,
               word *cached_axis_offset,word *x_axis,word *y_data,dword flags,
               ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit,
               dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr,
               word *fault_status_output_ptr)

{
  ushort uVar1;
  word validation_state;
  dword dispatch_index;
  word sensor_scratch;
  dword ema_result;
  word wVar2;
  dword low_fault_word_index;
  dword high_fault_word_index;
  dword channel_word_index;
  dword debounce_transition_state;
  dword sensor_value;
  uint uVar3;
  word scratch16;
  ushort recovery_decrement;
  
  channel_word_index = (int)channel_index >> 4;
  sensor_value = 1 << (channel_index +
                       (channel_word_index + ((int)channel_index < 0 && (channel_index & 0xf) != 0))
                       * -0x10 & 0x3f);
  high_fault_word_index = (int)high_fault_bit >> 4;
  low_fault_word_index = (int)low_fault_bit >> 4;
  if ((sensor_channel_enable_bits_cal[channel_word_index] & sensor_value) == 0) {
    uVar1 = config_ptr->default_value;
    state_ptr->value = uVar1;
    filter_state_ptr->accumulator = (uint)uVar1 << 0x10;
    ema_result = exponentialMovingAverage((uint)uVar1,filter_state_ptr);
    (&sensor_channel_filtered_output)[channel_index] = (word)ema_result;
    *fault_status_output_ptr = 0x100;
    (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
         (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] &
         ~(ushort)(1 << (high_fault_bit & 0xf));
    (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] =
         (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] &
         ~(ushort)(1 << (high_fault_bit & 0xf));
    (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
         (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] &
         ~(ushort)(1 << (low_fault_bit & 0xf));
    (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] =
         (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] &
         ~(ushort)(1 << (low_fault_bit & 0xf));
    goto LAB_00501b1c;
  }
  if ((sensor_channel_held_value_enable_bits_cal[channel_word_index] & sensor_value) != 0) {
    scratch16 = state_ptr->held_value;
    filter_state_ptr->accumulator = (uint)scratch16 << 0x10;
    (&sensor_channel_filtered_output)[channel_index] = scratch16;
    *fault_status_output_ptr = 0;
    goto LAB_00501b1c;
  }
  if ((((channel_index == 0x15) || (channel_index == 0x2a)) || (channel_index == 0x2b)) ||
     (channel_index == 0x1c)) {
    validation_state = 0;
  }
  else {
    validation_state = sensorChannelConditionValidator(channel_index);
  }
  if ((adc_forced_reading_enable_bits_cal[channel_word_index] & sensor_value) == 0) {
    if (qadc_channel_index_table[channel_index] < 0x81) {
      uVar3 = (uint)qadc_channel_index_table[channel_index];
    }
    else {
      uVar3 = 0;
    }
    wVar2 = *qadc_channel_dispatch_table[uVar3].result_register;
  }
  else {
    wVar2 = (&sensor_channel_diag_override)[channel_index];
  }
  state_ptr->raw_adc_counts = wVar2;
  if (sensor_channel_ratiometric_reference_channel_cal[channel_index] == 0) {
    if ((adc_forced_reading_enable_bits_cal[channel_word_index] & sensor_value) == 0) {
      if (qadc_channel_index_table[channel_index] < 0x81) {
        uVar3 = (uint)qadc_channel_index_table[channel_index];
      }
      else {
        uVar3 = 0;
      }
      uVar3 = (uint)*qadc_channel_dispatch_table[uVar3].result_register;
    }
    else {
      uVar3 = (uint)(&sensor_channel_diag_override)[channel_index];
    }
  }
  else {
    if ((adc_forced_reading_enable_bits_cal[channel_word_index] & sensor_value) == 0) {
      if (qadc_channel_index_table[channel_index] < 0x81) {
        uVar3 = (uint)qadc_channel_index_table[channel_index];
      }
      else {
        uVar3 = 0;
      }
      uVar1 = *qadc_channel_dispatch_table[uVar3].result_register;
    }
    else {
      uVar1 = (&sensor_channel_diag_override)[channel_index];
    }
    if (sensor_channel_ratiometric_reference_channel_cal[channel_index] < 0x81) {
      dispatch_index = (dword)sensor_channel_ratiometric_reference_channel_cal[channel_index];
    }
    else {
      dispatch_index = 0;
    }
    if ((((uint)uVar1 * (uint)sensor_channel_ratio_scale) /
         (uint)(&sensor_channel_filtered_output)[dispatch_index] & 0xffff) < 0x3ff) {
      if ((adc_forced_reading_enable_bits_cal[channel_word_index] & sensor_value) == 0) {
        if (qadc_channel_index_table[channel_index] < 0x81) {
          uVar3 = (uint)qadc_channel_index_table[channel_index];
        }
        else {
          uVar3 = 0;
        }
        uVar1 = *qadc_channel_dispatch_table[uVar3].result_register;
      }
      else {
        uVar1 = (&sensor_channel_diag_override)[channel_index];
      }
      if (sensor_channel_ratiometric_reference_channel_cal[channel_index] < 0x81) {
        uVar3 = (uint)sensor_channel_ratiometric_reference_channel_cal[channel_index];
      }
      else {
        uVar3 = 0;
      }
      uVar3 = ((uint)uVar1 * (uint)sensor_channel_ratio_scale) /
              (uint)(&sensor_channel_filtered_output)[uVar3];
    }
    else {
      uVar3 = 0x3ff;
    }
  }
  state_ptr->lookup_input = (word)uVar3;
  if ((((channel_index != 0x2f) || (cruise_control_switches_learned_flag != 0)) &&
      ((channel_index != 0x47 || (diag_clear_flags_t_003fedfc._0_2_ != 0)))) &&
     ((channel_index != 10 || (oil_pressure_switch_only_cal == 0)))) {
    if ((uint)config_ptr->high_threshold < (uVar3 & 0xffff)) {
      uVar1 = config_ptr->debounce_limit;
      if ((uint)state_ptr->debounce_count < (uint)uVar1) {
        if ((int)(uint)config_ptr->debounce_step <
            (int)((uint)uVar1 - (uint)state_ptr->debounce_count)) {
LAB_005017a8:
          state_ptr->debounce_count = state_ptr->debounce_count + config_ptr->debounce_step;
          debounce_transition_state = 1;
        }
        else {
          state_ptr->debounce_count = uVar1;
          (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
               (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] |
               (ushort)(1 << (high_fault_bit & 0xf));
          (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
               (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] &
               ~(ushort)(1 << (low_fault_bit & 0xf));
          (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] =
               (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] &
               ~(ushort)(1 << (low_fault_bit & 0xf));
          debounce_transition_state = 2;
        }
      }
      else {
        (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] |
             (ushort)(1 << (high_fault_bit & 0xf));
        (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] &
             ~(ushort)(1 << (low_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] &
             ~(ushort)(1 << (low_fault_bit & 0xf));
        debounce_transition_state = 2;
      }
    }
    else if ((uVar3 & 0xffff) < (uint)config_ptr->low_threshold) {
      uVar1 = config_ptr->debounce_limit;
      if ((uint)state_ptr->debounce_count < (uint)uVar1) {
        if ((int)(uint)config_ptr->debounce_step <
            (int)((uint)uVar1 - (uint)state_ptr->debounce_count)) goto LAB_005017a8;
        state_ptr->debounce_count = uVar1;
        (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] |
             (ushort)(1 << (low_fault_bit & 0xf));
        (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        debounce_transition_state = 2;
      }
      else {
        (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] |
             (ushort)(1 << (low_fault_bit & 0xf));
        (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        debounce_transition_state = 2;
      }
    }
    else {
      uVar1 = state_ptr->debounce_count;
      recovery_decrement = config_ptr->recovery_decrement;
      if (uVar1 <= recovery_decrement) {
        state_ptr->debounce_count = 0;
      }
      else {
        state_ptr->debounce_count = uVar1 - recovery_decrement;
      }
      debounce_transition_state = (dword)(uVar1 > recovery_decrement);
      if (state_ptr->debounce_count <= config_ptr->debounce_clear_threshold) {
        (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] =
             (&fault_registered_cal.faults_0_to_15)[high_fault_word_index] &
             ~(ushort)(1 << (high_fault_bit & 0xf));
        (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_detected_cal.faults_0_to_15)[low_fault_word_index] &
             ~(ushort)(1 << (low_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] =
             (&fault_registered_cal.faults_0_to_15)[low_fault_word_index] &
             ~(ushort)(1 << (low_fault_bit & 0xf));
      }
    }
  }
  if (((((uint)(&fault_detected_cal.faults_0_to_15)[high_fault_word_index] &
        1 << (high_fault_bit & 0xf)) == 0) &&
      (((uint)(&fault_detected_cal.faults_0_to_15)[low_fault_word_index] &
       1 << (low_fault_bit & 0xf)) == 0)) && (validation_state != 2)) {
    if ((debounce_transition_state == 1) || (validation_state == 1)) {
      *fault_status_output_ptr = 1;
      goto LAB_00501b1c;
    }
    sensor_scratch =
         lookupTableInterpolation(cached_axis_offset,state_ptr->lookup_input,x_axis,y_data,flags);
    state_ptr->value = sensor_scratch;
    wVar2 = 0;
  }
  else {
    state_ptr->value = config_ptr->default_value;
    wVar2 = 2;
  }
  ema_result = exponentialMovingAverage((uint)state_ptr->value,filter_state_ptr);
  (&sensor_channel_filtered_output)[channel_index] = (word)ema_result;
  *fault_status_output_ptr = wVar2;
LAB_00501b1c:
  *value_output_ptr = (&sensor_channel_filtered_output)[channel_index];
  *default_value_output_ptr = config_ptr->default_value;
  return;
}



//
