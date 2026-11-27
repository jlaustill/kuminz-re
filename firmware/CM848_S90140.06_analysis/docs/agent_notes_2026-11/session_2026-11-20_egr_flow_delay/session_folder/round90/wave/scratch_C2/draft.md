# batch C2 draft (scratch)

0x807d48 JCPKT0RP -> peak_torque_engine_speed_tau_0 word (move.w $807d48,d0 @0x1f43e; add.w d0,d0) J1922 msg 0x46 only; 12800=1600rpm
0x807ed4 ESSXSNEN -> engine_speed_sensor_enable_flags word (move.w @0x17222/0x172fe/0x1a75c/0x1b282/0x1b314) bits 0x1/0xc/0x8; 0x1f
0x807ed8 CSCKES -> engine_running_speed_threshold word (cmp.w $807ed8,d0 @0x1030e bls; @0x1aade bcc) vs ESAVES 0x80ccf2 (misnamed fuel_demand_blend_mode_select); 2400=300rpm
0x807f38 EPMXDQRP -> engine_speed_limit_fault_derate_full_severity word (sub.w $807f38,d0 @0x18f78) CM848 reuse; 15000=1875rpm
0x808084 HSDVCFXA(really HSDVCFYA) -> high_speed_governor_derivative_gain_adjustment_multiplier_values word[14] (move.l #0x808084,(8,a0) @0x1d356) CM848 reuse
0x8080bc HSPPCFXA(really HSPPCFYA) -> high_speed_governor_proportional_gain_adjustment_multiplier_values word[14] (@0x1d36e)
0x8080f4 HSITCFXA(really HSITCFYA) -> high_speed_governor_integral_gain_adjustment_multiplier_values word[14] (@0x1d386)
0x808162 JC39P3RP -> j1939_engine_speed_at_point_3 word (move.w @0xfa86/0xfc74/0xfcde) 9200
0x808164 JC39P4RP -> j1939_engine_speed_at_point_4 word (move.w @0xfc7a/0xfce4/0xfd76/0xfdce) 12800
0x808166 JC39P5RP -> j1939_engine_speed_at_point_5 word (move.w @0xfb0a/0xfc84/0xfd80) 17600
0x80817e JCEGDSRP -> j1939_pgn65247_desired_operating_speed word (move.w @0x1f276 / 0x330ee) 12000
0x8081fa JCHSODES -> j1939_high_idle_override_speed word (move.w @0x1d5c6 / 0x33320) 24000
0x808474 ESASOSTY -> supervisor_chip_overspeed_non_latching_flag byte (cmpi.b #1,$808474 @0x26cb0) 1
0x8088cc PTGNQDTB -> power_take_off_governor_derivative_gain_adjustment_values word[14]
0x808904 PTGNQITB -> power_take_off_governor_integral_gain_adjustment_values word[14]
0x80893c PTGNQPTB -> power_take_off_governor_proportional_gain_adjustment_values word[14]
0x8089aa JCRDISRP -> engine_retarder_configuration_idle_speed word (move.w @0x34128) 8000
0x8089ba JCMXEBRP -> engine_retarder_configuration_maximum_speed word (move.w @0x3414a) 24800
0x809eea SSECTMHE -> executive_timing_header word[4] (move.w #5,$809eea @0x1bf60; a0 base +2/+4/+6 word stores; cmp.w $809eee @0x1bf04)
0x809ef2 SSECTMDX -> executive_frame_timings byte[640] (40 x 16-byte records)
0x80a270 BSTABELM -> injection_timing_before_misfire_limit word (clr.w @0x26aaa; move.w (a2),$80a270 @0x26b1e)
0x80a8fa APAPBA -> alpha_base word
0x80a8fc APAPST -> alpha_state word
0x80a8fe APAFSS -> alpha_air_fuel_control_result word
0x80a900 APFLRTAP -> alpha_fuel_rate_result word
0x80a902 APGVAP -> alpha_on_governor_result word
0x80a904 APLSAP -> alpha_low_speed_governor_result word
0x80a90a APAAPRSS -> alpha_low_ambient_air_pressure_result word
