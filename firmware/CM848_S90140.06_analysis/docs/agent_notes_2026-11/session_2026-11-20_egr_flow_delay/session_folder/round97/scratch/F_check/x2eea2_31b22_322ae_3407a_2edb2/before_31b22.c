//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cm550_diagnosticCanResponseSender
               (can_standard_receive_descriptor_t *request,word acknowledgement_type)

{
  j1939_pgn59392_tx_message.header.can_id = CONCAT13((char)((_DAT_00803f4e & 7) << 2),0xe8ff00);
  j1939_pgn59392_tx_message.header.can_id._2_2_ =
       CONCAT11((char)request->id,*(undefined1 *)((int)&request->id + 2));
  DAT_00801eb2 = (undefined1)acknowledgement_type;
  DAT_00801eb7 = *request->data_pointer;
  DAT_00801eb8 = request->data_pointer[1];
  DAT_00801eb9 = request->data_pointer[2];
  cm550_sendCanMessage(&j1939_pgn59392_tx_message);
  return;
}



//
