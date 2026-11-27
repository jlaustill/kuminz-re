Draft C3 proposals (scratch)

0x80a930 ASALPHA -> master_slave_final_override_alpha word (CM848 0x40a885 same e2m MSFNAP); calculateAlpha move.w $80a930,(a2) @0xc39a
0x80a93c ASRSSTX6 -> all_speed_governor_reset_state_fuel_demand_correction word (CM848 0x40a214); move.w $80a93c,d5 @0xcb84, move.w $80a958,$80a93c @0xd160
0x80a958 ASAPSTX6 -> all_speed_governor_application_reset_state_fuel_demand_correction word (CM848 0x40a230)
0x80a976 ASMXFL -> all_speed_governor_fueling word (CM848 0x40a1b4)
0x80a9da EB39CNID -> engine_retarder_j1939_control_device word (CM848 0x40a27c); cmpi.w #1/#3/#2,(a3) a3=0x80a9da @0x3394c..
0x80bad7 DCMNSHNU -> duty_cycle_monitor_active_short_term_map byte; move.b #1/#2,(a4), clr.b, cmpi.b
0x80bad8 DCSHPR01 -> duty_cycle_monitor_short_term_processing_map_1_byte_length word (header 204 = 51 dwords at 0x80bada)
0x80bba6 DCSHPR02 -> duty_cycle_monitor_short_term_processing_map_2_byte_length word
0x80bcd5 DSPTSESW -> power_take_off_switch_state_bits byte
0x80bcd9 DSUSEBSW -> switch_9_to_16_override_values byte
0x80bd03 DSFMCHFB -> auxiliary_driver_feedback_bits byte
0x80d0cc CMSYSS -> cam_sync_state byte
0x80d0ce CMSYRSFG -> cam_cycle_reset_flag byte
0x80d0d0 CMSYBKSS -> cam_sync_backup_state byte (medium; read-only)
0x80d288 EPESLM -> engine_speed_limit_fault_derate word (CM848 0x40a780)
0x80d334 FSLMDSST -> requested_fueling_state word (CM848 0x40a2d4)
0x80d358 JCFSTLFG -> j1939_torque_and_load_not_available_flag word (CM848 0x40a336)
0x80d664 HSINRFST -> engine_speed_limit_limiting_source_number_snapshot word (CM848 0x40a318)
0x80d714 JCCMTHMU -> multiplexed_accelerator_pedal_position byte (EEC2 PGN 61443 byte 2)
0x80da28 JCEVRPP2 -> j1939_determined_engine_speed_at_point_2 word (CM848 0x40ad9c)
0x80da54 JCHII1OD -> high_idle_override_active_flag word (CM848 field)
0x80da68 JCEGNETY -> engine_control_network_type word
0x80da6a JCOGNETY -> out_of_gear_network_type word (CM848 field)
0x80de3e DRTKODMD -> tachometer_override_enable_flag word
0x80ded0 FSLMAHST -> fuel_demand_minimum_tracked_state word (CM848 0x40afb4)
0x80ded4 FSDSFLST -> user_fueling_state word (CM848 engine_operating_mode, but that name is taken in CM550 by 0x80c810)
