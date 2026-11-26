//

/* WARNING: Removing unreachable block (ram,0x00012940) */
/* WARNING: Removing unreachable block (ram,0x00012efe) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* The cylinder balancing calculation, frame 38 of executiveFrameInterruptHandler (once per 200 ms)
   while CBDEN = 1. With a new buffer (CBDSBRF) it forms the six acceleration samples CBDAXB1-6
   (speed buffer n - n+1) and a six-point Fourier analysis (CBDFRC1 / CBDFIC1 / CBDFRC2 / CBDFIC2 /
   CBDFRC3, sin 60 = 866/1000), sets the stop compensation flag CBDSCF from the active trim gain
   table, the speed change (CBDDST) and the engine state, removes the learned dynamics compensation
   (CBDDCT / CBDI2DCT by engine speed, learned while motoring between CBDLSL and CBDUSL, reset by
   CBDDCR) into CBDARC2 / CBDAIC2 and the component 3 adjustment into CBDARC3. It picks the trim
   patterns CBDTI1-3 from the reference vectors, the magnitudes CBDFM1-3 and the trim increments
   (normal or small gain against the threshold table CBDFT), and with CBDCEN set, cam and crank in
   sync, no recent cylinder cutout (CBDDSTM), road speed up to CBDVSTD and coolant / intake
   temperature above CBDCLTP / CBDIMTP it adds the ROM pattern trims to the saved trims (CBDDFTO,
   EEPROM), applies the limits CBDFTMN..CBDFTMX with limit mode CBDLMMD, removes the mean and stores
   them back. Last it writes 0x80a1ac-0x80a1b6 = FLFLAJC1-6 + trim x CBDATG / 100 (trims in firing
   order 1-5-3-6-2-4) and clears CBDSBRF. (was vp44_FUN_000127c2; PR #53 round 96) */

void cm550_calculateCylinderBalanceTrims(void)

{
  short sVar1;
  int iVar2;
  word wVar3;
  int iVar4;
  word wVar5;
  word wVar6;
  ushort uVar7;
  undefined *puVar8;
  short sVar9;
  dword *pdVar10;
  byte *pbVar11;
  short *psVar12;
  word *pwVar13;
  sword *psVar14;
  dword *pdVar15;
  word *pwVar16;
  short *psVar17;
  sdword *psVar18;
  word *pwVar19;
  short *psVar20;
  word *pwVar21;
  
  if (cylinder_balance_enable_flag == 1) {
    if (cylinder_balance_speed_buffer_ready_flag == 1) {
      cylinder_balance_speed_buffer_processed_flag = 1;
      uVar7 = 0;
      pdVar10 = &cylinder_balance_speed_buffer_2;
      pdVar15 = &cylinder_balance_speed_buffer_1;
      psVar18 = &cylinder_balance_acceleration_buffer_1;
      do {
        *psVar18 = *pdVar15 - *pdVar10;
        uVar7 = uVar7 + 1;
        pdVar10 = pdVar10 + 1;
        pdVar15 = pdVar15 + 1;
        psVar18 = psVar18 + 1;
      } while (uVar7 < 6);
      iVar2 = (cylinder_balance_acceleration_buffer_5 + cylinder_balance_acceleration_buffer_1) -
              cylinder_balance_acceleration_buffer_2;
      iVar4 = iVar2 - cylinder_balance_acceleration_buffer_4;
      if (iVar2 < cylinder_balance_acceleration_buffer_4) {
        iVar4 = iVar4 + 1;
      }
      cylinder_balance_fourier_real_component_1 =
           cylinder_balance_acceleration_buffer_6 +
           ((iVar4 >> 1) - cylinder_balance_acceleration_buffer_3);
      cylinder_balance_fourier_imaginary_component_1 =
           cm550_scaleByRatioSigned
                     (((cylinder_balance_acceleration_buffer_2 +
                       cylinder_balance_acceleration_buffer_1) -
                      cylinder_balance_acceleration_buffer_4) -
                      cylinder_balance_acceleration_buffer_5,0x362,1000);
      iVar4 = cm550_scaleByRatioSigned
                        (cylinder_balance_acceleration_buffer_5 +
                         cylinder_balance_acceleration_buffer_4 +
                         cylinder_balance_acceleration_buffer_2 +
                         cylinder_balance_acceleration_buffer_1,0xffffffff,2);
      cylinder_balance_fourier_real_component_2 =
           cylinder_balance_acceleration_buffer_6 + cylinder_balance_acceleration_buffer_3 + iVar4;
      cylinder_balance_fourier_imaginary_component_2 =
           cm550_scaleByRatioSigned
                     (((cylinder_balance_acceleration_buffer_4 +
                       cylinder_balance_acceleration_buffer_1) -
                      cylinder_balance_acceleration_buffer_2) -
                      cylinder_balance_acceleration_buffer_5,0x362,1000);
      cylinder_balance_fourier_real_component_3 =
           (((cylinder_balance_acceleration_buffer_6 +
             cylinder_balance_acceleration_buffer_4 + cylinder_balance_acceleration_buffer_2) -
            cylinder_balance_acceleration_buffer_1) - cylinder_balance_acceleration_buffer_3) -
           cylinder_balance_acceleration_buffer_5;
    }
    cylinder_balance_stop_compensation_lookup.x_input = engine_speed;
    cylinder_balance_stop_compensation_lookup.y_input = cylinder_balance_filtered_fueling;
    cylinder_balance_active_trim_gain =
         cm550_tableLookup2D(&cylinder_balance_stop_compensation_lookup);
    if (100 < cylinder_balance_active_trim_gain) {
      cylinder_balance_active_trim_gain = 100;
    }
    cylinder_balance_engine_speed_change =
         (word)((uint)engine_speed - (uint)cylinder_balance_engine_speed_previous);
    if ((int)((uint)engine_speed - (uint)cylinder_balance_engine_speed_previous) < 0) {
      cylinder_balance_engine_speed_change = -cylinder_balance_engine_speed_change;
    }
    cylinder_balance_engine_speed_previous = engine_speed;
    if ((((cylinder_balance_active_trim_gain < 100) ||
         (cylinder_balance_delta_speed_threshold < cylinder_balance_engine_speed_change)) ||
        (cylinder_balance_speed_buffer_processed_flag == 0)) ||
       (engine_state != ENGINE_STATE_RUNNING)) {
      cylinder_balance_stop_compensation_flag = 1;
    }
    else {
      cylinder_balance_stop_compensation_flag = 0;
    }
    cylinder_balance_speed_buffer_processed_flag = 0;
    cylinder_balance_real_2_dynamics_compensation_lookup.x_input = engine_speed;
    wVar5 = cm550_lookupTableInterpolation(&cylinder_balance_real_2_dynamics_compensation_lookup);
    cylinder_balance_imaginary_2_dynamics_compensation_lookup.x_input = engine_speed;
    wVar6 = cm550_lookupTableInterpolation
                      (&cylinder_balance_imaginary_2_dynamics_compensation_lookup);
    puVar8 = &DAT_00002710 + (cylinder_balance_fourier_real_component_2 - (uint)wVar5);
    if ((int)puVar8 < 0x2711) {
      if ((int)puVar8 < -10000) {
        puVar8 = (undefined *)0xffffd8f0;
      }
    }
    else {
      puVar8 = &DAT_00002710;
    }
    cylinder_balance_adjusted_real_component_2 = (sword)puVar8;
    puVar8 = &DAT_00002710 + (cylinder_balance_fourier_imaginary_component_2 - (uint)wVar6);
    if ((int)puVar8 < 0x2711) {
      if ((int)puVar8 < -10000) {
        puVar8 = (undefined *)0xffffd8f0;
      }
    }
    else {
      puVar8 = &DAT_00002710;
    }
    cylinder_balance_adjusted_imaginary_component_2 = (sword)puVar8;
    cylinder_balance_engine_speed_bin_index = 0;
    uVar7 = 1;
    pwVar13 = cylinder_balance_engine_speed_axis;
    do {
      pwVar13 = pwVar13 + 1;
      if (*pwVar13 <= engine_speed) {
        cylinder_balance_engine_speed_bin_index = uVar7 - 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0xf);
    if (((cylinder_balance_filtered_fueling <= cylinder_balance_motoring_fuel_threshold) &&
        (final_fueling == 0)) &&
       ((cylinder_balance_lower_speed_limit < engine_speed &&
        ((engine_speed < cylinder_balance_upper_speed_limit &&
         (engine_state == ENGINE_STATE_RUNNING)))))) {
      sVar9 = cylinder_balance_adjusted_real_component_2 -
              (short)((int)((uint)cylinder_balance_error_filter_coefficient *
                           (int)cylinder_balance_adjusted_real_component_2) / 10000);
      sVar1 = cylinder_balance_adjusted_imaginary_component_2 -
              (short)((int)((uint)cylinder_balance_error_filter_coefficient *
                           (int)cylinder_balance_adjusted_imaginary_component_2) / 10000);
      cylinder_balance_real_2_dynamics_compensation_values[cylinder_balance_engine_speed_bin_index]
           = sVar9 + cylinder_balance_real_2_dynamics_compensation_previous_values
                     [cylinder_balance_engine_speed_bin_index];
      cylinder_balance_real_2_dynamics_compensation_values
      [cylinder_balance_engine_speed_bin_index + 1] =
           sVar9 + cylinder_balance_real_2_dynamics_compensation_previous_values
                   [cylinder_balance_engine_speed_bin_index + 1];
      cylinder_balance_imaginary_2_dynamics_compensation_values
      [cylinder_balance_engine_speed_bin_index] =
           sVar1 + cylinder_balance_imaginary_2_dynamics_compensation_previous_values
                   [cylinder_balance_engine_speed_bin_index];
      cylinder_balance_imaginary_2_dynamics_compensation_values
      [cylinder_balance_engine_speed_bin_index + 1] =
           sVar1 + cylinder_balance_imaginary_2_dynamics_compensation_previous_values
                   [cylinder_balance_engine_speed_bin_index + 1];
      cylinder_balance_real_2_dynamics_compensation_previous_values
      [cylinder_balance_engine_speed_bin_index] =
           cylinder_balance_real_2_dynamics_compensation_values
           [cylinder_balance_engine_speed_bin_index];
      cylinder_balance_real_2_dynamics_compensation_previous_values
      [cylinder_balance_engine_speed_bin_index + 1] =
           cylinder_balance_real_2_dynamics_compensation_values
           [cylinder_balance_engine_speed_bin_index + 1];
      cylinder_balance_imaginary_2_dynamics_compensation_previous_values
      [cylinder_balance_engine_speed_bin_index] =
           cylinder_balance_imaginary_2_dynamics_compensation_values
           [cylinder_balance_engine_speed_bin_index];
      cylinder_balance_imaginary_2_dynamics_compensation_previous_values
      [cylinder_balance_engine_speed_bin_index + 1] =
           cylinder_balance_imaginary_2_dynamics_compensation_values
           [cylinder_balance_engine_speed_bin_index + 1];
    }
    if (cylinder_balance_dynamic_compensation_reset_enable == 1) {
      uVar7 = 0;
      pwVar13 = cylinder_balance_imaginary_2_dynamics_compensation_previous_values;
      pwVar16 = cylinder_balance_real_2_dynamics_compensation_previous_values;
      pwVar19 = cylinder_balance_imaginary_2_dynamics_compensation_values;
      pwVar21 = cylinder_balance_real_2_dynamics_compensation_values;
      do {
        *pwVar21 = 10000;
        *pwVar19 = 10000;
        *pwVar16 = 10000;
        *pwVar13 = 10000;
        uVar7 = uVar7 + 1;
        pwVar13 = pwVar13 + 1;
        pwVar16 = pwVar16 + 1;
        pwVar19 = pwVar19 + 1;
        pwVar21 = pwVar21 + 1;
      } while (uVar7 < 0x10);
    }
    cylinder_balance_component_3_adjustment_lookup.x_input = engine_speed;
    cylinder_balance_component_3_adjustment_lookup.y_input = cylinder_balance_filtered_fueling;
    wVar5 = cm550_tableLookup2D(&cylinder_balance_component_3_adjustment_lookup);
    cylinder_balance_component_3_adjustment = wVar5 + 0xd8f0;
    cylinder_balance_adjusted_real_component_3 =
         cylinder_balance_fourier_real_component_3._2_2_ - cylinder_balance_component_3_adjustment;
    iVar4 = (cylinder_balance_fourier_imaginary_component_1 *
             cylinder_balance_reference_1_cylinder_1_imaginary +
            cylinder_balance_fourier_real_component_1 * cylinder_balance_reference_1_cylinder_1_real
            ) / 10000;
    cylinder_balance_trim_index_1 = 0;
    uVar7 = 1;
    psVar18 = cylinder_balance_reference_projections;
    do {
      psVar18 = psVar18 + 1;
      if (iVar4 < *psVar18) {
        iVar4 = *psVar18;
        cylinder_balance_trim_index_1 = uVar7;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 6);
    cylinder_balance_reference_projections[0] =
         ((int)cylinder_balance_reference_2_cylinder_1_imaginary *
          (int)cylinder_balance_adjusted_imaginary_component_2 +
         (int)cylinder_balance_reference_2_cylinder_1_real *
         (int)cylinder_balance_adjusted_real_component_2) / 10000;
    cylinder_balance_reference_projections[4] =
         ((int)cylinder_balance_reference_2_cylinder_5_imaginary *
          (int)cylinder_balance_adjusted_imaginary_component_2 +
         (int)cylinder_balance_reference_2_cylinder_5_real *
         (int)cylinder_balance_adjusted_real_component_2) / 10000;
    cylinder_balance_reference_projections[2] =
         ((int)cylinder_balance_reference_2_cylinder_3_imaginary *
          (int)cylinder_balance_adjusted_imaginary_component_2 +
         (int)cylinder_balance_reference_2_cylinder_3_real *
         (int)cylinder_balance_adjusted_real_component_2) / 10000;
    cylinder_balance_reference_projections[5] = -cylinder_balance_reference_projections[0];
    cylinder_balance_reference_projections[1] = -cylinder_balance_reference_projections[4];
    cylinder_balance_reference_projections[3] = -cylinder_balance_reference_projections[2];
    cylinder_balance_trim_index_2 = 0;
    uVar7 = 1;
    psVar18 = cylinder_balance_reference_projections;
    iVar4 = cylinder_balance_reference_projections[0];
    do {
      psVar18 = psVar18 + 1;
      if (iVar4 < *psVar18) {
        iVar4 = *psVar18;
        cylinder_balance_trim_index_2 = uVar7;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 6);
    if (cylinder_balance_adjusted_real_component_3 < 0) {
      cylinder_balance_trim_index_3 = cylinder_balance_reference_3;
    }
    else if (cylinder_balance_reference_3 == 0) {
      cylinder_balance_trim_index_3 = 1;
    }
    else {
      cylinder_balance_trim_index_3 = 0;
    }
    if (cylinder_balance_fourier_real_component_1 < 0) {
      cylinder_balance_absolute_fourier_real_component_1 =
           -cylinder_balance_fourier_real_component_1._2_2_;
    }
    else {
      cylinder_balance_absolute_fourier_real_component_1 =
           cylinder_balance_fourier_real_component_1._2_2_;
    }
    if (cylinder_balance_fourier_imaginary_component_1 < 0) {
      cylinder_balance_absolute_fourier_imaginary_component_1 =
           -cylinder_balance_fourier_imaginary_component_1._2_2_;
    }
    else {
      cylinder_balance_absolute_fourier_imaginary_component_1 =
           cylinder_balance_fourier_imaginary_component_1._2_2_;
    }
    if (cylinder_balance_absolute_fourier_imaginary_component_1 <
        cylinder_balance_absolute_fourier_real_component_1) {
      cylinder_balance_fourier_magnitude_1 = cylinder_balance_absolute_fourier_real_component_1;
    }
    else {
      cylinder_balance_fourier_magnitude_1 = cylinder_balance_absolute_fourier_imaginary_component_1
      ;
    }
    if (15000 < cylinder_balance_fourier_magnitude_1) {
      cylinder_balance_fourier_magnitude_1 = 15000;
    }
    if (cylinder_balance_adjusted_real_component_2 < 0) {
      cylinder_balance_absolute_adjusted_real_component_2 =
           -cylinder_balance_adjusted_real_component_2;
    }
    else {
      cylinder_balance_absolute_adjusted_real_component_2 =
           cylinder_balance_adjusted_real_component_2;
    }
    if (cylinder_balance_adjusted_imaginary_component_2 < 0) {
      cylinder_balance_absolute_adjusted_imaginary_component_2 =
           -cylinder_balance_adjusted_imaginary_component_2;
    }
    else {
      cylinder_balance_absolute_adjusted_imaginary_component_2 =
           cylinder_balance_adjusted_imaginary_component_2;
    }
    if (cylinder_balance_absolute_adjusted_imaginary_component_2 <
        cylinder_balance_absolute_adjusted_real_component_2) {
      iVar4 = (uint)cylinder_balance_magnitude_gain_2 *
              (uint)cylinder_balance_absolute_adjusted_real_component_2;
    }
    else {
      iVar4 = (uint)cylinder_balance_magnitude_gain_2 *
              (uint)cylinder_balance_absolute_adjusted_imaginary_component_2;
    }
    iVar4 = iVar4 / 10;
    if (iVar4 < 0x3a99) {
      if (iVar4 < 0) {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 15000;
    }
    cylinder_balance_fourier_magnitude_2 = (word)iVar4;
    if (cylinder_balance_adjusted_real_component_3 < 0) {
      cylinder_balance_absolute_adjusted_real_component_3 =
           -cylinder_balance_adjusted_real_component_3;
    }
    else {
      cylinder_balance_absolute_adjusted_real_component_3 =
           cylinder_balance_adjusted_real_component_3;
    }
    iVar4 = (int)((uint)cylinder_balance_magnitude_gain_3 *
                 (uint)cylinder_balance_absolute_adjusted_real_component_3) / 10;
    if (iVar4 < 0x3a99) {
      if (iVar4 < 0) {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 15000;
    }
    cylinder_balance_fourier_magnitude_3 = (word)iVar4;
    cylinder_balance_threshold_lookup.x_input = engine_speed;
    cylinder_balance_fourier_threshold =
         cm550_lookupTableInterpolation(&cylinder_balance_threshold_lookup);
    if (cylinder_balance_fourier_threshold < cylinder_balance_fourier_magnitude_1) {
      cylinder_balance_trim_increment_1 = _DAT_008072a6;
    }
    else {
      cylinder_balance_trim_increment_1 = cylinder_balance_trim_gain_1_small;
    }
    wVar5 = cylinder_balance_trim_increment_1;
    if (cylinder_balance_fourier_threshold < cylinder_balance_fourier_magnitude_2) {
      cylinder_balance_trim_increment_2 = _DAT_008072aa;
    }
    else {
      cylinder_balance_trim_increment_2 = cylinder_balance_trim_gain_2_small;
    }
    wVar6 = cylinder_balance_trim_increment_2;
    if (cylinder_balance_fourier_threshold < cylinder_balance_fourier_magnitude_3) {
      cylinder_balance_trim_increment_3 = _DAT_008072ae;
    }
    else {
      cylinder_balance_trim_increment_3 = cylinder_balance_trim_gain_3_small;
    }
    wVar3 = cylinder_balance_trim_increment_3;
    if (cylinder_balance_cutout_disable_timer != 0) {
      cylinder_balance_cutout_disable_timer = cylinder_balance_cutout_disable_timer - 1;
    }
    uVar7 = 0;
    pbVar11 = &flag_to_enable_or_disable_fueling_for_cyl_1_0_to_ff;
    do {
      if (*pbVar11 == 0) {
        cylinder_balance_cutout_disable_timer = cylinder_balance_cutout_disable_time;
        break;
      }
      uVar7 = uVar7 + 1;
      pbVar11 = pbVar11 + 1;
    } while (uVar7 < 6);
    if (((((cylinder_balance_compensation_enable == 1) &&
          (cylinder_balance_stop_compensation_flag == 0)) && (cam_sync_status == 1)) &&
        ((cam_sync_state == 1 && (cylinder_balance_cutout_disable_timer == 0)))) &&
       ((sampled_road_speed_after_it_has_been_filtered_0_255_9961 <=
         cylinder_balance_update_maximum_road_speed &&
        ((cylinder_balance_coolant_temperature_threshold <
          coolant_temperature_sensor_state.filtered_value &&
         (cylinder_balance_intake_manifold_temperature_threshold <
          intake_manifold_temperature_sensor_state.filtered_value)))))) {
      uVar7 = 0;
      psVar12 = (short *)(&DAT_00012626 + (short)(cylinder_balance_trim_index_3 * 0xc));
      psVar17 = (short *)((short)(cylinder_balance_trim_index_2 * 0xc) + 0x125de);
      psVar20 = (short *)((short)(cylinder_balance_trim_index_1 * 0xc) + 0x12596);
      pwVar13 = &cylinder_balance_trim_adjustment_1;
      do {
        *pwVar13 = *psVar12 * wVar3 + *psVar17 * wVar6 + *psVar20 * wVar5;
        uVar7 = uVar7 + 1;
        psVar12 = psVar12 + 1;
        psVar17 = psVar17 + 1;
        psVar20 = psVar20 + 1;
        pwVar13 = pwVar13 + 1;
      } while (uVar7 < 6);
    }
    else {
      uVar7 = 0;
      pwVar13 = &cylinder_balance_trim_adjustment_1;
      do {
        *pwVar13 = 0;
        uVar7 = uVar7 + 1;
        pwVar13 = pwVar13 + 1;
      } while (uVar7 < 6);
    }
    uVar7 = 0;
    pwVar13 = &cylinder_balance_trim_adjustment_1;
    psVar14 = &cylinder_balance_fueling_trim_1;
    do {
      *psVar14 = *pwVar13 + cylinder_balance_saved_fueling_trims_cal[(short)uVar7];
      uVar7 = uVar7 + 1;
      pwVar13 = pwVar13 + 1;
      psVar14 = psVar14 + 1;
    } while (uVar7 < 6);
    uVar7 = 0;
    do {
      if (((int)(uint)cylinder_balance_fueling_trim_maximum <
           (int)(&cylinder_balance_fueling_trim_1)[(short)uVar7]) ||
         ((&cylinder_balance_fueling_trim_1)[(short)uVar7] < cylinder_balance_fueling_trim_minimum))
      {
        cylinder_balance_trim_limits_exceeded_flag = 1;
        uVar7 = 6;
      }
      else if (cylinder_balance_fueling_trim_limit_mode == 0) {
        cylinder_balance_trim_limits_exceeded_flag = 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 6);
    if (cylinder_balance_trim_limits_exceeded_flag == 1) {
      if (cylinder_balance_fueling_trim_limit_mode == 1) {
        uVar7 = 0;
        psVar14 = cylinder_balance_power_up_fueling_trims;
        do {
          cylinder_balance_saved_fueling_trims_cal[(short)uVar7] = *psVar14;
          uVar7 = uVar7 + 1;
          psVar14 = psVar14 + 1;
        } while (uVar7 < 6);
      }
      else if (cylinder_balance_fueling_trim_limit_mode == 2) {
        uVar7 = 0;
        do {
          cylinder_balance_saved_fueling_trims_cal[(short)uVar7] = 0;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 6);
      }
      uVar7 = 0;
      psVar14 = &cylinder_balance_fueling_trim_1;
      do {
        *psVar14 = cylinder_balance_saved_fueling_trims_cal[(short)uVar7];
        uVar7 = uVar7 + 1;
        psVar14 = psVar14 + 1;
      } while (uVar7 < 6);
    }
    if (cylinder_balance_compensation_enable == 0) {
      uVar7 = 0;
      psVar14 = &cylinder_balance_fueling_trim_1;
      do {
        *psVar14 = 0;
        uVar7 = uVar7 + 1;
        psVar14 = psVar14 + 1;
      } while (uVar7 < 6);
    }
    sVar9 = 0;
    uVar7 = 0;
    psVar14 = &cylinder_balance_fueling_trim_1;
    do {
      sVar9 = *psVar14 + sVar9;
      uVar7 = uVar7 + 1;
      psVar14 = psVar14 + 1;
    } while (uVar7 < 6);
    uVar7 = 0;
    psVar14 = &cylinder_balance_fueling_trim_1;
    do {
      iVar4 = (int)*psVar14 - (int)sVar9 / 6;
      if (iVar4 < 0x8000) {
        if (iVar4 < -0x8000) {
          iVar4 = -0x8000;
        }
      }
      else {
        iVar4 = 0x7fff;
      }
      *psVar14 = (short)iVar4;
      uVar7 = uVar7 + 1;
      psVar14 = psVar14 + 1;
    } while (uVar7 < 6);
    uVar7 = 0;
    psVar14 = &cylinder_balance_fueling_trim_1;
    do {
      cylinder_balance_saved_fueling_trims_cal[(short)uVar7] = *psVar14;
      uVar7 = uVar7 + 1;
      psVar14 = psVar14 + 1;
    } while (uVar7 < 6);
    if (cylinder_balance_compensation_enable == 1) {
      if (cylinder_balance_cutout_disable_timer == 0) {
        balanced_cylinder_fueling_offsets[0] =
             added_to_final_fuel_command_for_cylinder_1_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_1 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
        balanced_cylinder_fueling_offsets[1] =
             added_to_final_fuel_command_for_cylinder_2_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_5 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
        balanced_cylinder_fueling_offsets[2] =
             added_to_final_fuel_command_for_cylinder_3_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_3 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
        balanced_cylinder_fueling_offsets[3] =
             added_to_final_fuel_command_for_cylinder_4_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_6 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
        balanced_cylinder_fueling_offsets[4] =
             added_to_final_fuel_command_for_cylinder_5_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_2 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
        balanced_cylinder_fueling_offsets[5] =
             added_to_final_fuel_command_for_cylinder_6_300_to_300 +
             (short)(((int)cylinder_balance_fueling_trim_4 *
                     (int)(short)cylinder_balance_active_trim_gain) / 100);
      }
      else {
        uVar7 = 0;
        psVar14 = balanced_cylinder_fueling_offsets;
        do {
          *psVar14 = 0;
          uVar7 = uVar7 + 1;
          psVar14 = psVar14 + 1;
        } while (uVar7 < 6);
      }
    }
    cylinder_balance_speed_buffer_ready_flag = 0;
  }
  return;
}



//
