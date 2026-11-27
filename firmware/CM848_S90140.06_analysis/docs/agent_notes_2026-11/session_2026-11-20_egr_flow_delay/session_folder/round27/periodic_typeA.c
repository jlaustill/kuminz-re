// Function: sensorChannelConfigInit @ 0x00500234
//

void sensorChannelConfigInit
               (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr,
               word *cached_axis_offset,word *x_axis,word *y_data,dword flags,
               ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit,
               dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr,
               word *fault_status_output_ptr)

{
  ushort uVar1;
  ushort uVar2;
  short sVar4;
  uint uVar3;
  word wVar5;
  word wVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  
  iVar9 = (int)channel_index >> 4;
  uVar11 = 1 << (channel_index +
                 (iVar9 + (uint)((int)channel_index < 0 && (channel_index & 0xf) != 0)) * -0x10 &
                0x3f);
  iVar8 = (int)high_fault_bit >> 4;
  iVar7 = (int)low_fault_bit >> 4;
  if ((sensor_channel_enable_bits_cal[iVar9] & uVar11) == 0) {
    wVar5 = config_ptr->default_value;
    state_ptr->value = wVar5;
    filter_state_ptr->accumulator = (int)(short)wVar5 << 0x10;
    (&sensor_channel_filtered_output)[channel_index] = wVar5;
    *fault_status_output_ptr = 0x100;
    (&fault_detected_cal.faults_0_to_15)[iVar8] =
         (&fault_detected_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
    (&fault_registered_cal.faults_0_to_15)[iVar8] =
         (&fault_registered_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
    (&fault_detected_cal.faults_0_to_15)[iVar7] =
         (&fault_detected_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
    (&fault_registered_cal.faults_0_to_15)[iVar7] =
         (&fault_registered_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
    goto LAB_00500a1c;
  }
  if ((sensor_channel_held_value_enable_bits_cal[iVar9] & uVar11) != 0) {
    wVar5 = state_ptr->held_value;
    filter_state_ptr->accumulator = (int)(short)wVar5 << 0x10;
    (&sensor_channel_filtered_output)[channel_index] = wVar5;
    *fault_status_output_ptr = 0;
    goto LAB_00500a1c;
  }
  if ((((channel_index == 0x15) || (channel_index == 0x2a)) || (channel_index == 0x2b)) ||
     (channel_index == 0x1c)) {
    sVar4 = 0;
  }
  else {
    sVar4 = sensorChannelConditionValidator(channel_index);
  }
  if ((adc_forced_reading_enable_bits_cal[iVar9] & uVar11) == 0) {
    if (qadc_channel_index_table[channel_index] < 0x81) {
      uVar3 = (uint)qadc_channel_index_table[channel_index];
    }
    else {
      uVar3 = 0;
    }
    wVar5 = *qadc_channel_dispatch_table[uVar3].result_register;
  }
  else {
    wVar5 = (&sensor_channel_diag_override)[channel_index];
  }
  state_ptr->raw_adc_counts = wVar5;
  if (sensor_channel_ratiometric_reference_channel_cal[channel_index] == 0) {
    if ((adc_forced_reading_enable_bits_cal[iVar9] & uVar11) == 0) {
      if (qadc_channel_index_table[channel_index] < 0x81) {
        uVar11 = (uint)qadc_channel_index_table[channel_index];
      }
      else {
        uVar11 = 0;
      }
      uVar11 = (uint)*qadc_channel_dispatch_table[uVar11].result_register;
    }
    else {
      uVar11 = (uint)(&sensor_channel_diag_override)[channel_index];
    }
  }
  else {
    if ((adc_forced_reading_enable_bits_cal[iVar9] & uVar11) == 0) {
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
    if ((((uint)uVar1 * (uint)sensor_channel_ratio_scale) /
         (uint)(&sensor_channel_filtered_output)[uVar3] & 0xffff) < 0x3ff) {
      if ((adc_forced_reading_enable_bits_cal[iVar9] & uVar11) == 0) {
        if (qadc_channel_index_table[channel_index] < 0x81) {
          uVar11 = (uint)qadc_channel_index_table[channel_index];
        }
        else {
          uVar11 = 0;
        }
        uVar1 = *qadc_channel_dispatch_table[uVar11].result_register;
      }
      else {
        uVar1 = (&sensor_channel_diag_override)[channel_index];
      }
      if (sensor_channel_ratiometric_reference_channel_cal[channel_index] < 0x81) {
        uVar11 = (uint)sensor_channel_ratiometric_reference_channel_cal[channel_index];
      }
      else {
        uVar11 = 0;
      }
      uVar11 = ((uint)uVar1 * (uint)sensor_channel_ratio_scale) /
               (uint)(&sensor_channel_filtered_output)[uVar11];
    }
    else {
      uVar11 = 0x3ff;
    }
  }
  state_ptr->lookup_input = (word)uVar11;
  if ((uint)config_ptr->high_threshold < (uVar11 & 0xffff)) {
    uVar1 = config_ptr->debounce_limit;
    if ((uint)state_ptr->debounce_count < (uint)uVar1) {
      if ((int)(uint)config_ptr->debounce_step <
          (int)((uint)uVar1 - (uint)state_ptr->debounce_count)) {
LAB_005006b4:
        state_ptr->debounce_count = state_ptr->debounce_count + config_ptr->debounce_step;
        cVar10 = '\x01';
      }
      else {
        state_ptr->debounce_count = uVar1;
        (&fault_detected_cal.faults_0_to_15)[iVar8] =
             (&fault_detected_cal.faults_0_to_15)[iVar8] | (ushort)(1 << (high_fault_bit & 0xf));
        (&fault_detected_cal.faults_0_to_15)[iVar7] =
             (&fault_detected_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
        (&fault_registered_cal.faults_0_to_15)[iVar7] =
             (&fault_registered_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
        cVar10 = '\x02';
      }
    }
    else {
      (&fault_detected_cal.faults_0_to_15)[iVar8] =
           (&fault_detected_cal.faults_0_to_15)[iVar8] | (ushort)(1 << (high_fault_bit & 0xf));
      (&fault_detected_cal.faults_0_to_15)[iVar7] =
           (&fault_detected_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
      (&fault_registered_cal.faults_0_to_15)[iVar7] =
           (&fault_registered_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
      cVar10 = '\x02';
    }
  }
  else if ((uVar11 & 0xffff) < (uint)config_ptr->low_threshold) {
    uVar1 = config_ptr->debounce_limit;
    if ((uint)state_ptr->debounce_count < (uint)uVar1) {
      if ((int)(uint)config_ptr->debounce_step <
          (int)((uint)uVar1 - (uint)state_ptr->debounce_count)) goto LAB_005006b4;
      state_ptr->debounce_count = uVar1;
      (&fault_detected_cal.faults_0_to_15)[iVar7] =
           (&fault_detected_cal.faults_0_to_15)[iVar7] | (ushort)(1 << (low_fault_bit & 0xf));
      (&fault_detected_cal.faults_0_to_15)[iVar8] =
           (&fault_detected_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      (&fault_registered_cal.faults_0_to_15)[iVar8] =
           (&fault_registered_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      cVar10 = '\x02';
    }
    else {
      (&fault_detected_cal.faults_0_to_15)[iVar7] =
           (&fault_detected_cal.faults_0_to_15)[iVar7] | (ushort)(1 << (low_fault_bit & 0xf));
      (&fault_detected_cal.faults_0_to_15)[iVar8] =
           (&fault_detected_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      (&fault_registered_cal.faults_0_to_15)[iVar8] =
           (&fault_registered_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      cVar10 = '\x02';
    }
  }
  else {
    uVar1 = state_ptr->debounce_count;
    uVar2 = config_ptr->recovery_decrement;
    if (uVar1 <= uVar2) {
      state_ptr->debounce_count = 0;
    }
    else {
      state_ptr->debounce_count = uVar1 - uVar2;
    }
    cVar10 = uVar1 > uVar2;
    if (state_ptr->debounce_count <= config_ptr->debounce_clear_threshold) {
      (&fault_detected_cal.faults_0_to_15)[iVar8] =
           (&fault_detected_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      (&fault_registered_cal.faults_0_to_15)[iVar8] =
           (&fault_registered_cal.faults_0_to_15)[iVar8] & ~(ushort)(1 << (high_fault_bit & 0xf));
      (&fault_detected_cal.faults_0_to_15)[iVar7] =
           (&fault_detected_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
      (&fault_registered_cal.faults_0_to_15)[iVar7] =
           (&fault_registered_cal.faults_0_to_15)[iVar7] & ~(ushort)(1 << (low_fault_bit & 0xf));
    }
  }
  if (((((uint)(&fault_detected_cal.faults_0_to_15)[iVar8] & 1 << (high_fault_bit & 0xf)) == 0) &&
      (((uint)(&fault_detected_cal.faults_0_to_15)[iVar7] & 1 << (low_fault_bit & 0xf)) == 0)) &&
     (sVar4 != 2)) {
    if ((cVar10 == '\x01') || (sVar4 == 1)) {
      *fault_status_output_ptr = 1;
      goto LAB_00500a1c;
    }
    wVar5 = lookupTableInterpolation(cached_axis_offset,state_ptr->lookup_input,x_axis,y_data,flags)
    ;
    state_ptr->value = wVar5;
    wVar5 = 0;
  }
  else {
    state_ptr->value = config_ptr->default_value;
    wVar5 = 2;
  }
  wVar6 = cm848_signedFirstOrderFilter((int)(short)state_ptr->value,filter_state_ptr);
  (&sensor_channel_filtered_output)[channel_index] = wVar6;
  *fault_status_output_ptr = wVar5;
LAB_00500a1c:
  *value_output_ptr = (&sensor_channel_filtered_output)[channel_index];
  *default_value_output_ptr = config_ptr->default_value;
  return;
}



//
