//

void cm550_diagnosticServiceDispatcher(dword message)

{
  undefined2 in_D0w;
  char cVar1;
  byte bVar2;
  j1939_diagnostic_service_entry_t *pjVar3;
  
  pjVar3 = j1939_diagnostic_service_table;
  cVar1 = '\x18';
  bVar2 = 0;
  do {
    if (j1939_diagnostic_handler_count <= bVar2) {
LAB_0002eeee:
      if (cVar1 != -1) {
        cm550_diagnosticMultiPacketResponseBuilder
                  ((can_standard_receive_descriptor_t *)message,
                   CONCAT11((char)((ushort)in_D0w >> 8),cVar1));
      }
      return;
    }
    in_D0w = CONCAT11((char)((ushort)in_D0w >> 8),pjVar3->service_id);
    if (pjVar3->service_id == **(J1939_DIAGNOSTIC_SERVICE **)(message + 6)) {
      in_D0w = cm550_diagnosticServiceSecurityValidator(message);
      cVar1 = (char)in_D0w;
      if (cVar1 == -1) {
        in_D0w = (*(code *)pjVar3->handler)((short)message);
        cVar1 = (char)in_D0w;
      }
      goto LAB_0002eeee;
    }
    pjVar3 = pjVar3 + 1;
    bVar2 = bVar2 + 1;
  } while( true );
}



//
