//

/* PGN 61184 services 15 and 16 (J1939_DIAGNOSTIC_SERVICE_NO_OPERATION_15 / _16), registered by
   registerJ1939BroadcastAndNoOperationServices. It returns 0 (accepted) and does nothing (clr.b d0;
   rts), so the requester gets the positive reply. Twin of CM848 0x509be0 (li r3,0; blr); the boot
   kernel keeps its own cm848_bootDiagnosticServiceAcknowledgeNoOperation (one shared name; no
   function before, was LAB_0001ffd2; PR #53 round 97). (was LAB_0001ffd2; PR #53 round 97) */

byte handleJ1939NoOperationService(void)

{
  return 0;
}



//
