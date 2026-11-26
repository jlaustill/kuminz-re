//

/* Checks a PGN 61184 request before cm550_dispatchJ1939DiagnosticServiceRequest calls its handler,
   and returns 0xff when the request may go on. Services above 25 always pass. The header length is
   3 for services 4 / 5, 5 for 0x19 and 1 otherwise. For a service marked in the bit table 0x60f98
   while calibration_download_security_key_cal is not 0xff, the length must be the header + 10 (else
   2) and validateSecurityKey must accept the key after the header (else 3). Other services need a
   length of 8 or the header + 10 (else 2). Counterpart of cm848_validateJ1939DiagnosticRequest,
   which returns 0x1a (key missing) when a secured request has length 8 (was
   cm550_diagnosticServiceSecurityValidator; PR #53 round 97). (was
   cm550_diagnosticServiceSecurityValidator; PR #53 round 97) */

byte cm550_validateJ1939DiagnosticRequest(can_standard_receive_descriptor_t *request)

{
  byte authentication_result;
  int required_parameter_length;
  byte service_id;
  word message_length;
  
  service_id = *request->data_pointer;
  message_length = request->length;
  if (0x19 < service_id) {
    return 0xff;
  }
  if ((service_id == 4) || (service_id == 5)) {
    required_parameter_length = 3;
  }
  else if (service_id == 0x19) {
    required_parameter_length = 5;
  }
  else {
    required_parameter_length = 1;
  }
  if ((('\x01' << (service_id & 7) & *(byte *)(((int)(uint)service_id >> 3) + 0x60f98)) == 0) ||
     (calibration_download_security_key_cal == 0xff)) {
    if ((message_length == 8) || ((uint)message_length == required_parameter_length + 10U)) {
      return 0xff;
    }
    return 2;
  }
  if (required_parameter_length + 10U != (uint)message_length) {
    return 2;
  }
  authentication_result = validateSecurityKey(request->data_pointer + required_parameter_length);
  if (authentication_result == 0) {
    return 0xff;
  }
  return 3;
}



//
