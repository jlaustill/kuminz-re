//

/* Sends the J1939 Acknowledgement (PGN 59392, j1939_pgn59392_tx_message) for a received request.
   The header is 0xe8ff00 with the priority j1939_pgn59392_priority_cal (e2m 1254 +0 JCAKPZ) & 7,
   and it is addressed back to the requester: header byte 2 = the request's source address, byte 3 =
   the address the request went to. Payload byte 1 is the control byte acknowledgement_type (0 =
   ACK, 1 = NACK) and bytes 6-8 are the request's data bytes 1-3 (the requested PGN for a PGN 59904
   request); bytes 2-5 keep the 0xff of cm550_initializePgn59392AcknowledgementBuffer. Callers:
   cm550_j1939HandlePgn65228Dm3ClearInactiveFaults (0 after a DM3),
   cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage (1 for an unsupported test)
   and cm550_dispatchJ1939PgnRequest (1 when no responder matched a request that was not global).
   Counterpart of CM848 0x23dbc, which addresses the same payload to the global address 0xff (was
   cm550_diagnosticCanResponseSender; PR #53 round 97). (was cm550_diagnosticCanResponseSender; PR
   #53 round 97) */

void cm550_sendPgn59392AcknowledgementMessage(can_standard_receive_descriptor_t *request)

{
  byte in_stack_00000009;
  
  j1939_pgn59392_tx_message.header.can_id =
       CONCAT13((char)((j1939_pgn59392_priority_cal & 7) << 2),0xe8ff00);
  j1939_pgn59392_tx_message.header.can_id._2_2_ =
       CONCAT11((char)request->id,*(undefined1 *)((int)&request->id + 2));
  j1939_pgn59392_payload[0] = in_stack_00000009;
  j1939_pgn59392_payload[5] = *request->data_pointer;
  j1939_pgn59392_payload[6] = request->data_pointer[1];
  j1939_pgn59392_payload[7] = request->data_pointer[2];
  cm550_sendCanMessage(&j1939_pgn59392_tx_message);
  return;
}



//
