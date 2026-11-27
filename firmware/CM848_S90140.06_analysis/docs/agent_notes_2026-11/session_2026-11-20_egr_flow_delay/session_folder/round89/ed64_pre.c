=== insiteCommandByteDispatcher
void insiteCommandByteDispatcher(void)
{
  undefined4 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 uVar2;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  byte bVar4;
  uint uVar3;
  undefined1 uVar5;
  undefined4 local_a;
  undefined2 local_6;
  uVar1 = _accumulated_amount_of_fuel_used_during_vehicle_operatio_0_0_10000000;
  if (insite_parameter_id < 0x80) {
    if (insite_parameter_id < 0x59) {
      if (insite_parameter_id < 0x54) {
        if (insite_parameter_id == 2) {
          local_6._1_1_ = 0;
          bVar4 = cm550_diagnosticCodeTableSearch((ushort)DAT_008065f7);
          if (bVar4 == 0) {
            bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var,DAT_008065f5));
            if (bVar4 == 0) {
              bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var_00,DAT_008065f3));
              uVar2 = extraout_var_01;
              if (bVar4 != 0) {
                local_6._1_1_ = 0x20;
              }
            }
            else {
              local_6._1_1_ = 0x20;
              uVar2 = extraout_var_00;
            }
          }
          else {
            local_6._1_1_ = 0x20;
            uVar2 = extraout_var;
          }
          bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(uVar2,DAT_0080656d));
          if (bVar4 != 0) {
            local_6._1_1_ = (byte)local_6 | 0x10;
          }
          bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var_02,DAT_008065b1));
          if (bVar4 != 0) {
            local_6._1_1_ = (byte)local_6 | 8;
          }
          bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var_03,DAT_008065cb));
          if (bVar4 != 0) {
            local_6._1_1_ = (byte)local_6 | 4;
          }
          bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var_04,DAT_008065d3));
          if (bVar4 == 0) {
            bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(extraout_var_05,DAT_008065d9));
            uVar2 = extraout_var_06;
            if (bVar4 != 0) {
              local_6._1_1_ = (byte)local_6 | 2;
            }
          }
          else {
            local_6._1_1_ = (byte)local_6 | 2;
            uVar2 = extraout_var_05;
          }
          bVar4 = cm550_diagnosticCodeTableSearch((word)CONCAT31(uVar2,DAT_0080659f));
          if (bVar4 != 0) {
            local_6._1_1_ = (byte)local_6 | 1;
          }
        }
        else if (insite_parameter_id == 3) {
          local_6._1_1_ = (debounced_switch_value_for_switch_16_on_off & 0x80) != 0;
          if ((debounced_switch_value_for_switch_16_on_off & 0x40) != 0) {
            local_6._1_1_ = (byte)local_6 | 2;
          }
          if ((debounced_switch_value_for_switch_16_on_off & 0x20) != 0) {
            local_6._1_1_ = (byte)local_6 | 4;
          }
        }
        else if (insite_parameter_id == 0x1d) {
          local_6._1_1_ = (byte)(((uint)_alternate_throttle_command * 0xfa) / 400);
        }
        else if (insite_parameter_id == 0x1e) {
          if ((ushort)((int)(uint)*(ushort *)
                                   (&filtered_and_linearized_intake_manifold_temperature_50_to_293 +
                                   (short)((ushort)DAT_0080d283 * 3 + (ushort)DAT_0080d283 * 8) * 2)
                      >> 4) < 0x7f) {
            local_6._1_1_ =
                 (byte)((int)(uint)*(ushort *)
                                    (&filtered_and_linearized_intake_manifold_temperature_50_to_293
                                    + (short)((ushort)DAT_0080d283 * 3 + (ushort)DAT_0080d283 * 8) *
                                      2) >> 4);
          }
          else {
            local_6._1_1_ = 0x7f;
          }
        }
        else if (insite_parameter_id == 0x2c) {
          local_6._1_1_ = 0xc0;
          if ((bit_6_which_enables_the_warning_lamp_driver_enable_disable & 4) != 0) {
            local_6._1_1_ = 0xd0;
          }
          if ((bit_6_which_enables_the_warning_lamp_driver_enable_disable & 0x40) != 0) {
            local_6._1_1_ = (byte)local_6 | 4;
          }
          if ((bit_6_which_enables_the_warning_lamp_driver_enable_disable & 2) != 0) {
            local_6._1_1_ = (byte)local_6 | 1;
          }
        }
        else if (insite_parameter_id == 0x2d) {
          local_6._1_1_ = 0xcf;
          if ((bit_6_which_enables_the_warning_lamp_driver_enable_disable & 1) != 0) {
            local_6._1_1_ = 0xcf;
          }
        }
        else if (insite_parameter_id == 0x47) {
          local_6._1_1_ = 0;
          if ((_vp44_sensor_countdown_timer != 0) && (_vp44_sensor_countdown_timer < _DAT_00803c02))
          {
            local_6._1_1_ = 0x80;
          }
          if ((_calibration_feature_enable_flags_word_3 & 2) != 0) {
            local_6._1_1_ = (byte)local_6 | 8;
          }
          if ((_DAT_0080d672 != 0) && ((_calibration_feature_enable_flags_word_3 & 4) != 0)) {
            local_6._1_1_ = (byte)local_6 | 4;
          }
          if ((engine_shutdown_command_flag != 0) && (_vp44_sensor_countdown_timer == 0)) {
            local_6._1_1_ = (byte)local_6 | 2;
          }
          if (_vp44_sensor_warning_active != 0) {
            local_6._1_1_ = (byte)local_6 | 1;
          }
        }
        else if (insite_parameter_id == 0x4a) {
          local_6._1_1_ = (byte)((int)(uint)_DAT_0080a9dc >> 7);
        }
        else {
          if (insite_parameter_id != 0x53) {
            return;
          }
          if (_indicator_as_to_which_algorithm_is_in_control_of_fueling_after_it_1_12 == 10) {
            local_6._1_1_ = 0x80;
          }
          else {
            local_6._1_1_ = 0;
          }
        }
        *(byte *)insite_response_write_pointer = insite_parameter_id;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        *(byte *)insite_response_write_pointer = (byte)local_6;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
      else {
        switch(insite_parameter_id) {
        case 0x54:
          bVar4 = (byte)((int)(uint)_sampled_road_speed_after_it_has_been_filtered_0_255_9961 >> 7);
          break;
        case 0x55:
          bVar4 = 0;
          if (_cruise_control_active_flag != 0) {
            bVar4 = 0x80;
          }
          if ((debounced_switch_value_for_switch_16_on_off & 4) != 0) {
            bVar4 = bVar4 | 0x40;
          }
          if ((debounced_switch_value_for_switch_16_on_off & 8) != 0) {
            bVar4 = bVar4 | 0x20;
          }
          if ((switch_status_cruise_coast_switch_bit_3_on_off & 2) != 0) {
            bVar4 = bVar4 | 0x10;
          }
          if ((switch_status_cruise_coast_switch_bit_3_on_off & 1) != 0) {
            bVar4 = bVar4 | 8;
          }
          if ((switch_status_cruise_coast_switch_bit_3_on_off & 8) != 0) {
            bVar4 = bVar4 | 4;
          }
          if ((switch_status_cruise_coast_switch_bit_3_on_off & 4) != 0) {
            bVar4 = bVar4 | 2;
          }
          if ((switch_status_cruise_coast_switch_bit_3_on_off & 0x10) != 0) {
            bVar4 = bVar4 | 1;
          }
          break;
        case 0x56:
          bVar4 = (byte)((int)(uint)_DAT_0080a9c6 >> 7);
          break;
        case 0x57:
          bVar4 = (byte)((int)(uint)_DAT_00804fc6 >> 7);
          break;
        case 0x58:
          bVar4 = (byte)((int)(uint)_DAT_00807bf6 >> 7);
          break;
        default:
          goto switchD_0000f050_default;
        }
        *(byte *)insite_response_write_pointer = insite_parameter_id;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        *(byte *)insite_response_write_pointer = bVar4;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
    }
    else if (insite_parameter_id < 0x69) {
      switch(insite_parameter_id) {
      case 0x59:
        local_6._1_1_ = 0;
        if (_closed_loop_governor_active_flag != 0) {
          local_6._1_1_ = 0x80;
        }
        if ((debounced_switch_value_for_switch_16_on_off & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x40;
        }
        if ((debounced_switch_value_for_switch_16_on_off & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x20;
        }
        if ((DSPTSESW & 2) != 0) {
          local_6._1_1_ = (byte)local_6 | 0x10;
        }
        if ((DSPTSESW & 1) != 0) {
          local_6._1_1_ = (byte)local_6 | 8;
        }
        if ((DSPTSESW & 8) != 0) {
          local_6._1_1_ = (byte)local_6 | 4;
        }
        if ((DSPTSESW & 4) != 0) {
          local_6._1_1_ = (byte)local_6 | 2;
        }
        if ((DSPTSESW & 0x10) != 0) {
          local_6._1_1_ = (byte)local_6 | 1;
        }
        break;
      default:
        goto switchD_0000f050_default;
      case 0x5b:
        local_6._1_1_ =
             (byte)(((uint)_validated_percent_throttle_commanded_by_driver_0_100 * 0xfa) / 400);
        break;
      case 0x5c:
        local_6._1_1_ = (byte)((int)(uint)_percent_load_at_current_speed >> 7);
        break;
      case 0x61:
        local_6._1_1_ = 0;
        if ((bit_6_which_enables_the_warning_lamp_driver_enable_disable & 0x10) != 0) {
          local_6._1_1_ = 0x80;
        }
        break;
      case 100:
        local_6._1_1_ = (byte)((int)(uint)_flitered_and_linearized_oil_pressure_0_100 >> 6);
        break;
      case 0x66:
        if ((ushort)((int)(uint)_boost_pressure_0_100 >> 4) < 0xff) {
          local_6._1_1_ = (byte)((int)(uint)_boost_pressure_0_100 >> 4);
        }
        else {
          local_6._1_1_ = 0xff;
        }
      }
      *(byte *)insite_response_write_pointer = insite_parameter_id;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(byte *)insite_response_write_pointer = (byte)local_6;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
    }
    else {
      if (insite_parameter_id == 0x69) {
        if (_filtered_and_linearized_intake_manifold_temperature_50_to_293 < 0x1900) {
          uVar5 = 0;
        }
        else {
          uVar5 = (undefined1)
                  ((int)(_filtered_and_linearized_intake_manifold_temperature_50_to_293 - 0x1900) >>
                  7);
        }
      }
      else if (insite_parameter_id == 0x6c) {
        uVar5 = (undefined1)
                ((int)(uint)_filtered_ambient_air_pressure_as_read_and_scaled_from_a_d_algor_0_15 >>
                3);
      }
      else if (insite_parameter_id == 0x6e) {
        if (_filtered_and_linearized_coolant_temperature_50_to_293 < 0x1900) {
          uVar5 = 0;
        }
        else {
          uVar5 = (undefined1)
                  ((int)(_filtered_and_linearized_coolant_temperature_50_to_293 - 0x1900) >> 7);
        }
      }
      else {
        if (insite_parameter_id != 0x79) {
          return;
        }
        switch(_engine_brake_active_cylinder_count) {
        case 0:
          uVar5 = 0;
          break;
        case 1:
        case 2:
          uVar5 = 0x81;
          break;
        case 3:
          uVar5 = 0x82;
          break;
        case 4:
          uVar5 = 0x84;
          break;
        default:
          uVar5 = 0x88;
        }
      }
      *(byte *)insite_response_write_pointer = insite_parameter_id;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(undefined1 *)insite_response_write_pointer = uVar5;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
    }
  }
  else if (insite_parameter_id < 0xc1) {
    if (insite_parameter_id < 0xb9) {
      if (insite_parameter_id == 0x85) {
        local_6 = 0;
      }
      else if ((insite_parameter_id != 0x9c) && (insite_parameter_id != 0x9d)) {
        if (insite_parameter_id == 0xa6) {
          local_6 = CONCAT11(DAT_01000304,DAT_01000303);
        }
        else if (insite_parameter_id == 0xa8) {
          local_6 = (short)((int)(uint)_filtered_and_linearized_battery_voltage_0_40 >> 1) +
                    _filtered_and_linearized_battery_voltage_0_40 * 2;
        }
        else if (insite_parameter_id != 0xaf) {
          if (insite_parameter_id == 0xb6) {
            local_6 = (word)_DAT_00804fa4;
          }
          else if (insite_parameter_id == 0xb7) {
            local_6 = instantaneous_fuel_rate_formatted_for_j1587_broadcast_pid_18_0_284421;
          }
          else {
            if (insite_parameter_id != 0xb8) {
              return;
            }
            local_6 = _DAT_00804fb0;
          }
        }
      }
      *(byte *)insite_response_write_pointer = insite_parameter_id;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(byte *)insite_response_write_pointer = (byte)local_6;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(undefined1 *)insite_response_write_pointer = local_6._0_1_;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
    }
    else {
      switch(insite_parameter_id) {
      case 0xb9:
        local_6 = _DAT_00804fb2;
        break;
      default:
        goto switchD_0000f050_default;
      case 0xbb:
        local_6 = (word)((int)(uint)_DAT_0080dc24 >> 1);
        break;
      case 0xbc:
        local_6 = (word)((int)(uint)_lsg_breakpoint_speed >> 1);
        break;
      case 0xbd:
        local_6 = (word)((int)(uint)engine_overspeed_set_rpm_threshold >> 1);
        break;
      case 0xbe:
        local_6 = (word)((int)(uint)_current_engine_rpm_filtered >> 1);
      }
      *(byte *)insite_response_write_pointer = insite_parameter_id;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(byte *)insite_response_write_pointer = (byte)local_6;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(undefined1 *)insite_response_write_pointer = local_6._0_1_;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
    }
  }
  else if (insite_parameter_id < 0xf4) {
    if (insite_parameter_id == 0xc1) {
      cm550_insiteActiveFaultListBuilder();
      return;
    }
    if (insite_parameter_id == 0xc2) {
      cm550_insiteFaultDetailBuilder();
      return;
    }
    if (insite_parameter_id == 0xc4) {
      *(undefined1 *)insite_response_write_pointer = 0xc4;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      if (((insite_dtc_command_action_byte & 0xc0) == 0x80) ||
         ((insite_dtc_command_action_byte & 0xc0) == 0x40)) {
        *(undefined1 *)insite_response_write_pointer = 2;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
      else if ((insite_dtc_command_action_byte & 0xc0) == 0) {
        if (insite_matched_dtc_fault_code == 0) {
          *(undefined1 *)insite_response_write_pointer = 0;
          insite_response_write_pointer =
               CONCAT31(insite_response_write_pointer._0_3_,
                        (char)insite_response_write_pointer + '\x01');
          goto LAB_0000f6f4;
        }
        *(undefined1 *)insite_response_write_pointer = 5;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
      *(byte *)insite_response_write_pointer = BYTE_0080de25;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      *(byte *)insite_response_write_pointer = insite_dtc_command_action_byte;
      insite_response_write_pointer =
           CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01'
                   );
      if (((insite_dtc_command_action_byte & 0xc0) == 0) && (insite_matched_dtc_fault_code != 0)) {
        bVar4 = 1;
        do {
          *(char *)insite_response_write_pointer = (char)(insite_matched_dtc_fault_code / 100) + '0'
          ;
          insite_matched_dtc_fault_code = (insite_matched_dtc_fault_code % 100) * 10;
          insite_response_write_pointer =
               CONCAT31(insite_response_write_pointer._0_3_,
                        (char)insite_response_write_pointer + '\x01');
          bVar4 = bVar4 + 1;
        } while (bVar4 < 4);
      }
    }
    else {
      if (insite_parameter_id == 0xea) {
        cm550_insiteVersionInfoBuilder();
        return;
      }
      if (insite_parameter_id == 0xeb) {
        uVar3 = _DAT_00804fb4 / 0x708;
        *(undefined1 *)insite_response_write_pointer = 0xeb;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        *(undefined1 *)insite_response_write_pointer = 4;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._3_1_ = (undefined1)uVar3;
        *(undefined1 *)insite_response_write_pointer = (undefined1)local_a;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._2_1_ = (undefined1)(uVar3 >> 8);
        *(undefined1 *)insite_response_write_pointer = local_a._2_1_;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._1_1_ = (undefined1)(uVar3 >> 0x10);
        *(undefined1 *)insite_response_write_pointer = local_a._1_1_;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        *(undefined1 *)insite_response_write_pointer = 0;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
      else {
        if (insite_parameter_id != 0xec) {
          if (insite_parameter_id == 0xed) {
            cm550_insiteCapacityResponseBuilder();
            return;
          }
          if (insite_parameter_id == 0xf3) {
            cm550_FUN_000277e6();
            return;
          }
          return;
        }
        *(undefined1 *)insite_response_write_pointer = 0xec;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        *(undefined1 *)insite_response_write_pointer = 4;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._3_1_ = (undefined1)uVar1;
        *(undefined1 *)insite_response_write_pointer = (undefined1)local_a;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._2_1_ = (undefined1)((uint)uVar1 >> 8);
        *(undefined1 *)insite_response_write_pointer = local_a._2_1_;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
        *(undefined1 *)insite_response_write_pointer = local_a._1_1_;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
        local_a._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
        *(undefined1 *)insite_response_write_pointer = local_a._0_1_;
        insite_response_write_pointer =
             CONCAT31(insite_response_write_pointer._0_3_,
                      (char)insite_response_write_pointer + '\x01');
      }
    }
  }
  else {
    switch(insite_parameter_id) {
    case 0xf4:
      local_a = cm550_scaleByRatio(_DAT_00804fac,10,0x40);
      break;
    case 0xf5:
      local_a = cm550_scaleByRatio(_DAT_00804fa8,10,0x40);
      break;
    default:
      goto switchD_0000f050_default;
    case 0xf7:
      local_a = _DAT_00804fc0 / 0x708;
      break;
    case 0xf8:
      local_a = _DAT_00804fbc / 0x708;
      break;
    case 0xfa:
      local_a = _DAT_00804fa0;
    }
    *(byte *)insite_response_write_pointer = insite_parameter_id;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
    *(undefined1 *)insite_response_write_pointer = 4;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
    *(undefined1 *)insite_response_write_pointer = (undefined1)local_a;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
    *(undefined1 *)insite_response_write_pointer = local_a._2_1_;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
    *(undefined1 *)insite_response_write_pointer = local_a._1_1_;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
    *(undefined1 *)insite_response_write_pointer = local_a._0_1_;
    insite_response_write_pointer =
         CONCAT31(insite_response_write_pointer._0_3_,(char)insite_response_write_pointer + '\x01');
  }
LAB_0000f6f4:
  insite_response_length = insite_parameter_data_size + insite_response_length;
  insite_response_space_available = insite_response_space_available - insite_parameter_data_size;
switchD_0000f050_default:
  return;
}
