//

/* WARNING: Removing unreachable block (ram,0x000340ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds and sends the RC broadcast (PGN 65249 Retarder Configuration, 19 bytes at 0x803630 through
   the transport protocol, from the retarder source address; retarder queue 1 every 5000 ms from 301
   ms). It runs only while j1939_pgn65249_transmit_status has no 0xf0 bit set. Byte 1 (SPN 901 /
   902) is 3 (compression release at the engine) for two or more engine brake drivers
   (engine_retarder_output_driver_count, 0x8081fe), else 0x14 (exhaust brake). The compare at
   0x340b6 compiles as an assignment (move.w #1,(0x8081fe)): the count is overwritten with 1, a
   count of 0 also gives 0x14 and the 0xff branch is unreachable. Byte 2 (SPN 557) is the control
   method 0xff / 6 / 3 / 2 / 1 for 0 / 1 / 2 / 3 / 6 cylinders per driver (0x808200, e2m 13D8 +2
   JCDR1NCY); other counts leave it. Bytes 3-14 are the first four speed points, each low byte first
   and followed by 125 minus the high byte of its percent torque:
   engine_retarder_configuration_idle_speed with 0x8089b2,
   engine_retarder_configuration_maximum_speed with 0x8089b4, point 3 0x8089ae with 0x8089b6 and
   point 4 0x8089b0 with 0x8089b8. Bytes 15-16 are the peak torque speed 0x8089ac and bytes 17-18
   the reference torque 0x8089a6. Byte 19 (SPN 555, percent torque at peak torque) is never written
   and stays 0xff from cm550_initializePgn65249RetarderConfigurationBuffer. Then
   cm550_sendCanMessage(j1939_pgn65249_tx_message). Counterpart of
   cm848_buildPgn65249RetarderConfigurationMessage, which compares the count with 1 (0x14, else
   0xff) and also fills byte 19. (was vp44CanMessage100ResponseBuilder; PR #53 round 96) */

void cm550_buildPgn65249RetarderConfigurationMessage(void)

{
  byte local_6;
  byte bStack_5;
  
  if ((j1939_pgn65249_transmit_status & 0xf0) == 0) {
    if (engine_retarder_output_driver_count < 2) {
      engine_retarder_output_driver_count = 1;
      j1939_pgn65249_payload.retarder_type_and_location = 0x14;
    }
    else {
      j1939_pgn65249_payload.retarder_type_and_location = 3;
    }
    if (engine_retarder_driver_1_cylinder_count == 0) {
      j1939_pgn65249_payload.retarder_control_method = 0xff;
    }
    else if (engine_retarder_driver_1_cylinder_count == 1) {
      j1939_pgn65249_payload.retarder_control_method = 6;
    }
    else if (engine_retarder_driver_1_cylinder_count == 2) {
      j1939_pgn65249_payload.retarder_control_method = 3;
    }
    else if (engine_retarder_driver_1_cylinder_count == 3) {
      j1939_pgn65249_payload.retarder_control_method = 2;
    }
    else if (engine_retarder_driver_1_cylinder_count == 6) {
      j1939_pgn65249_payload.retarder_control_method = 1;
    }
    bStack_5 = (byte)engine_retarder_configuration_idle_speed;
    j1939_pgn65249_payload.retarder_speed_at_idle_point_1_low_byte = bStack_5;
    local_6 = (byte)(engine_retarder_configuration_idle_speed >> 8);
    j1939_pgn65249_payload.retarder_speed_at_idle_point_1_high_byte = local_6;
    j1939_pgn65249_payload.percent_torque_at_idle_point_1 =
         0x7d - (char)(jcomm_retarder_torque_at_idle_available_torque_that_retarder_0_125 >> 8);
    bStack_5 = (byte)engine_retarder_configuration_maximum_speed;
    j1939_pgn65249_payload.maximum_retarder_speed_point_2_low_byte = bStack_5;
    local_6 = (byte)(engine_retarder_configuration_maximum_speed >> 8);
    j1939_pgn65249_payload.maximum_retarder_speed_point_2_high_byte = local_6;
    j1939_pgn65249_payload.percent_torque_at_maximum_speed_point_2 =
         0x7d - (char)(jcomm_retarder_torque_at_max_speed_available_torque_that_retar_0_125 >> 8);
    bStack_5 = (byte)_DAT_008089ae;
    j1939_pgn65249_payload.retarder_speed_at_point_3_low_byte = bStack_5;
    local_6 = (byte)((ushort)_DAT_008089ae >> 8);
    j1939_pgn65249_payload.retarder_speed_at_point_3_high_byte = local_6;
    j1939_pgn65249_payload.percent_torque_at_point_3 =
         0x7d - (char)(jcomm_retarder_torque_at_pt_3_available_torque_that_retarder_0_125 >> 8);
    bStack_5 = (byte)_DAT_008089b0;
    j1939_pgn65249_payload.retarder_speed_at_point_4_low_byte = bStack_5;
    local_6 = (byte)((ushort)_DAT_008089b0 >> 8);
    j1939_pgn65249_payload.retarder_speed_at_point_4_high_byte = local_6;
    j1939_pgn65249_payload.percent_torque_at_point_4 =
         0x7d - (char)(jcomm_retarder_torque_at_pt_4_available_torque_that_retarder_0_125 >> 8);
    bStack_5 = (byte)_DAT_008089ac;
    j1939_pgn65249_payload.retarder_speed_at_peak_torque_point_5_low_byte = bStack_5;
    local_6 = (byte)((ushort)_DAT_008089ac >> 8);
    j1939_pgn65249_payload.retarder_speed_at_peak_torque_point_5_high_byte = local_6;
    bStack_5 = (byte)jcomm_reference_retarder_torque_reference_ret_torque_that_co_0_64255;
    j1939_pgn65249_payload.reference_retarder_torque_low_byte = bStack_5;
    local_6 = (byte)(jcomm_reference_retarder_torque_reference_ret_torque_that_co_0_64255 >> 8);
    j1939_pgn65249_payload.reference_retarder_torque_high_byte = local_6;
    cm550_sendCanMessage(&j1939_pgn65249_tx_message);
  }
  return;
}



//
