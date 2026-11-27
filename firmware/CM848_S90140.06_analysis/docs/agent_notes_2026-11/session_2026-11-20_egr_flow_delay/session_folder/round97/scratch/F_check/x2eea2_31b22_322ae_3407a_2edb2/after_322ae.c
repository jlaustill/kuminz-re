//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds and sends DM1 (PGN 65226) while j1939_dm1_transmit_status is idle. With no active fault it
   sends lamp byte 0 and 0xffffffff (6 bytes). Otherwise it sends cm550_buildJ1939LampStatusByte
   and, for each active_dtc_list slot whose fault definition lacks flag 0x4000, the DTC from the ROM
   table 0x60fac with the FMI, the occurrence count (at most 127) and the conversion method bit
   0x80. It is the 65226 request handler (registered twice, as in CM848) and the body of the
   periodic DM1 broadcast. Counterpart of CM848's DM1 builder, which stops at 20 slots and re-orders
   the DTC bytes. (was j1939HandlePgn65226Dm1ActiveDtc; PR #53 round 96) */

void cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  uint *puVar5;
  
  j1939_dm1_tx_message.status_pointer = &j1939_dm1_transmit_status;
  if ((j1939_dm1_transmit_status & 0xf0) == 0) {
    j1939_dm1_tx_message.header.data_length = 2;
    if (active_dtc_list[0] == 0) {
      DAT_00801f64 = 0;
      _DAT_00801f66 = 0xffffffff;
      j1939_dm1_tx_message.header.data_length = 6;
    }
    else {
      DAT_00801f64 = cm550_buildJ1939LampStatusByte();
      puVar5 = (uint *)&DAT_00801f66;
      for (uVar4 = 1; (byte)uVar4 <= active_dtc_list[0]; uVar4 = (ushort)(byte)((byte)uVar4 + 1)) {
        bVar1 = active_dtc_list[(short)uVar4];
        if ((*(ushort *)
              (&fault_definition_flags_word + (short)((ushort)bVar1 * 2 + (ushort)bVar1) * 2) &
            0x4000) == 0) {
          if ((&fault_count_table[0].occurrence_count)[(short)((ushort)bVar1 * 10)] < 0x80) {
            bVar3 = (&fault_count_table[0].occurrence_count)[(short)((ushort)bVar1 * 10)];
          }
          else {
            bVar3 = 0x7f;
          }
          uVar2 = *(uint *)((short)(ushort)bVar1 * 4 + 0x60fac) & 0xffffe000;
          *puVar5 = CONCAT22((short)(uVar2 >> 0x10),
                             (ushort)bVar3 |
                             (*(byte *)((short)(ushort)bVar1 * 4 + 0x60fae) & 0x1f) << 8 |
                             (ushort)uVar2) | 0x80;
          j1939_dm1_tx_message.header.data_length = j1939_dm1_tx_message.header.data_length + 4;
        }
        puVar5 = puVar5 + 1;
      }
    }
    cm550_sendCanMessage(&j1939_dm1_tx_message);
  }
  return;
}



//
