//

/* Reads by parameter ID for the PGN 61184 services 0x43 / 0x46 / 0x48. It resolves the e2m block ID
   with cm550_lookupParameterIdAddress (8 = unknown ID), then returns
   readJ1939DiagnosticMemoryAndRespond(request, the ID's address + offset, length). Parameters: the
   request, the ID, the offset and the length. Twin of CM848 0x50c5d0, as
   writeJ1939DiagnosticMemoryByParameterId is of 0x50b1b8 (one shared name; no row before, was
   FUN_000224f4; PR #53 round 97). (was FUN_000224f4; PR #53 round 97) */

byte readJ1939DiagnosticMemoryByParameterId
               (can_standard_receive_descriptor_t *request,word parameter_id,dword offset,
               dword length)

{
  char cVar1;
  byte bVar2;
  dword local_8;
  
  cVar1 = cm550_lookupParameterIdAddress(parameter_id,&local_8);
  if (cVar1 == '\0') {
    bVar2 = readJ1939DiagnosticMemoryAndRespond(request,offset + local_8,length);
  }
  else {
    bVar2 = 8;
  }
  return bVar2;
}



//
