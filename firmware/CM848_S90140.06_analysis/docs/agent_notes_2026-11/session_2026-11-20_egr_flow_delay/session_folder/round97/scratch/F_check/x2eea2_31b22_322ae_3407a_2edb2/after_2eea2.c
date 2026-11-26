//

/* The PGN 61184 receive handler. registerJ1939DiagnosticServiceDispatcher registers it for 0xef00,
   and the TP.DT handler 0x22c26 also calls it with the reassembled message record 0x8012cc. It
   looks request data byte 0 up in j1939_diagnostic_service_table (j1939_diagnostic_handler_count
   6-byte entries). On a match it runs cm550_validateJ1939DiagnosticRequest and, when that returns
   0xff, calls the entry's handler with the request. Unless the result is 0xff it answers with
   cm550_diagnosticMultiPacketResponseBuilder(request, result), with 0x18 (unknown service) when no
   entry matches. Counterpart of cm848_dispatchJ1939DiagnosticServiceRequest (CM848 0x22128), which
   first drops the response services 0x0c / 0x0d without a reply (was
   cm550_diagnosticServiceDispatcher; PR #53 round 97). (was cm550_diagnosticServiceDispatcher; PR
   #53 round 97) */

void cm550_dispatchJ1939DiagnosticServiceRequest(can_standard_receive_descriptor_t *request)

{
  undefined1 extraout_var;
  undefined2 in_D0w;
  byte bVar1;
  byte bVar2;
  j1939_diagnostic_service_entry_t *pjVar3;
  
  pjVar3 = j1939_diagnostic_service_table;
  bVar1 = 0x18;
  bVar2 = 0;
  do {
    if (j1939_diagnostic_handler_count <= bVar2) {
LAB_0002eeee:
      if (bVar1 != 0xff) {
        cm550_diagnosticMultiPacketResponseBuilder
                  (request,CONCAT11((char)((ushort)in_D0w >> 8),bVar1));
      }
      return;
    }
    in_D0w = CONCAT11((char)((ushort)in_D0w >> 8),pjVar3->service_id);
    if (pjVar3->service_id == *request->data_pointer) {
      bVar1 = cm550_validateJ1939DiagnosticRequest(request);
      in_D0w = CONCAT11(extraout_var,bVar1);
      if (bVar1 == 0xff) {
        in_D0w = (*(code *)pjVar3->handler)((short)request);
        bVar1 = (byte)in_D0w;
      }
      goto LAB_0002eeee;
    }
    pjVar3 = pjVar3 + 1;
    bVar2 = bVar2 + 1;
  } while( true );
}



//
