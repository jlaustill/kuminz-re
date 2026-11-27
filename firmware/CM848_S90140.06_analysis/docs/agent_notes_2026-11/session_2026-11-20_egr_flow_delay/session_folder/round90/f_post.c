=== cm550_FUN_0000ac3c
uint cm550_FUN_0000ac3c(void)
{
  int *piVar1;
  bool bVar2;
  undefined4 in_D0;
  uint uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  ushort *puVar7;
  uVar3 = CONCAT22((short)((uint)in_D0 >> 0x10),_feature_enable_flags_word) & 0xffff0008;
  if (((_feature_enable_flags_word & 8) != 0) && (engine_state != ENGINE_STATE_STOPPED)) {
    if (_duty_cycle_monitor_long_term_map_total_time_0_0_100000_0 == 0) {
      _duty_cycle_mon_approximate_long_term_map_start_0_0_50000_0 =
           _time_that_the_engine_is_not_in_stop_state_0_2_29;
    }
    if ((_short_term_map_1_processing_total_0_500_0 == 0) &&
       ((_short_term_map_2_processing_total_0_500_0 == 0 ||
        (_rpm_control_timer_2 <= _short_term_map_2_processing_total_0_500_0)))) {
      _duty_cycle_mon_approxiamte_short_term_map_1_start_0_0_50000_0 =
           _time_that_the_engine_is_not_in_stop_state_0_2_29;
    }
    else if ((_short_term_map_2_processing_total_0_500_0 == 0) &&
            (_rpm_control_timer_2 <= _short_term_map_1_processing_total_0_500_0)) {
      _duty_cycle_mon_approxiamte_short_term_map_2_start_0_0_50000_0 =
           _time_that_the_engine_is_not_in_stop_state_0_2_29;
    }
    if ((_engine_rpm_primary < duty_cycle_monitor_high_cutoff_engine_speed) &&
       (duty_cycle_monitor_low_cutoff_engine_speed <= _engine_rpm_primary)) {
      _high_rpm_threshold_countdown = _fueling_value_at_100_throttle_0_100;
    }
    else {
      if (_engine_rpm_primary < duty_cycle_monitor_high_cutoff_engine_speed) {
        _DAT_0080002c = duty_cycle_monitor_low_cutoff_engine_speed;
      }
      else {
        _DAT_0080002c = duty_cycle_monitor_high_cutoff_engine_speed;
      }
      _dma_desc1_dest_ptr = _DAT_0080002c;
      if (_alpha_blend_factor == 0x4000) {
        _high_rpm_threshold_countdown = cm550_tableLookup2D(&dma_desc1_source_ptr);
      }
      else if (_alpha_blend_factor == 0) {
        _high_rpm_threshold_countdown = cm550_tableLookup2D((word *)&dma_descriptor_ptr1);
      }
      else {
        previous_engine_rpm = cm550_tableLookup2D(&dma_desc1_source_ptr);
        dma_descriptor_base1 = cm550_tableLookup2D((word *)&dma_descriptor_ptr1);
        _high_rpm_threshold_countdown =
             (short)((uint)_alpha_blend_factor * (uint)previous_engine_rpm >> 0xe) +
             (short)((uint)dma_descriptor_base1 * (0x4000 - (uint)_alpha_blend_factor) >> 0xe);
      }
    }
    if (_high_rpm_threshold_countdown == _frictional_no_load_fueling) {
      _rpm_rate_limit_countdown = (uint)_frictional_load_torque_init;
    }
    else {
      _rpm_rate_limit_countdown =
           (int)(((uint)_current_fuel_demand - (uint)_frictional_no_load_fueling) * 10000) /
           (int)((uint)_high_rpm_threshold_countdown - (uint)_frictional_no_load_fueling);
    }
    if ((int)_rpm_rate_limit_countdown < 0) {
      _duty_cycle_monitor_calculated_load_factor_0_0_130_0 = 0;
      if (_engine_rpm_primary < duty_cycle_monitor_high_cutoff_engine_speed) {
        duty_cycle_monitor_current_operating_map_region_1_50 = 0x31;
      }
      else {
        duty_cycle_monitor_current_operating_map_region_1_50 = 0x32;
      }
    }
    else {
      _duty_cycle_monitor_calculated_load_factor_0_0_130_0 = _rpm_control_timer_1;
      cVar6 = '\b';
      cVar5 = '\x06';
      bVar2 = false;
      bVar4 = 1;
      puVar7 = (ushort *)&rpm_timer_interrupt_threshold_7d20;
      while ((bVar4 < 9 && (!bVar2))) {
        if (_engine_rpm_primary <= *puVar7) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar6 = '\x01';
          }
          else {
            cVar6 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      bVar2 = false;
      bVar4 = 1;
      puVar7 = (ushort *)&intake_temp_frictional_load_threshold;
      while ((bVar4 < 7 && (!bVar2))) {
        if (_rpm_control_timer_1 <= *puVar7) {
          bVar2 = true;
          if (bVar4 == 1) {
            cVar5 = '\x01';
          }
          else {
            cVar5 = bVar4 - 1;
          }
        }
        bVar4 = bVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      duty_cycle_monitor_current_operating_map_region_1_50 = cVar6 + ('\x06' - cVar5) * '\b';
    }
    if (_duty_cycle_monitor_long_term_map_total_time_0_0_100000_0 < 3600000000) {
      piVar1 = (int *)((short)(ushort)duty_cycle_monitor_current_operating_map_region_1_50 * 4 +
                      0x80546e);
      *piVar1 = *piVar1 + 1;
      _duty_cycle_monitor_long_term_map_total_time_0_0_100000_0 =
           _duty_cycle_monitor_long_term_map_total_time_0_0_100000_0 + 1;
    }
    uVar3 = _short_term_map_1_processing_total_0_500_0;
    if ((_short_term_map_1_processing_total_0_500_0 < _rpm_control_timer_2) &&
       (_short_term_map_1_processing_total_0_500_0 != 0)) {
      duty_cycle_monitor_active_short_term_map = 1;
    }
    else if ((_short_term_map_1_processing_total_0_500_0 == 0) &&
            ((_short_term_map_2_processing_total_0_500_0 == 0 ||
             (uVar3 = _short_term_map_2_processing_total_0_500_0,
             _rpm_control_timer_2 <= _short_term_map_2_processing_total_0_500_0)))) {
      duty_cycle_monitor_active_short_term_map = 1;
    }
    else if (_short_term_map_2_processing_total_0_500_0 < _rpm_control_timer_2) {
      duty_cycle_monitor_active_short_term_map = 2;
      uVar3 = _short_term_map_2_processing_total_0_500_0;
    }
    else {
      duty_cycle_monitor_active_short_term_map = 0;
      uVar3 = _short_term_map_2_processing_total_0_500_0;
    }
    if (duty_cycle_monitor_active_short_term_map == 1) {
      uVar3 = (uint)duty_cycle_monitor_current_operating_map_region_1_50;
      piVar1 = (int *)((short)(ushort)duty_cycle_monitor_current_operating_map_region_1_50 * 4 +
                      0x80bada);
      *piVar1 = *piVar1 + 1;
      _short_term_map_1_processing_total_0_500_0 = _short_term_map_1_processing_total_0_500_0 + 1;
      return uVar3;
    }
    if (duty_cycle_monitor_active_short_term_map == 2) {
      uVar3 = (uint)duty_cycle_monitor_current_operating_map_region_1_50;
      piVar1 = (int *)((short)(ushort)duty_cycle_monitor_current_operating_map_region_1_50 * 4 +
                      0x80bba8);
      *piVar1 = *piVar1 + 1;
      _short_term_map_2_processing_total_0_500_0 = _short_term_map_2_processing_total_0_500_0 + 1;
    }
  }
  return uVar3;
}
