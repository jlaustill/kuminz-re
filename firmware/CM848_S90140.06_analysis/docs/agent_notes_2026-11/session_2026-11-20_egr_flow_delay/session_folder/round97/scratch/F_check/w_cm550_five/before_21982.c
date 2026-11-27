//

undefined4 cm550_diagnosticServiceSecurityValidator(dword message)

{
  byte authentication_result;
  int required_parameter_length;
  byte service_id;
  word message_length;
  
  service_id = **(byte **)(message + 6);
  message_length = *(word *)(message + 4);
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
  authentication_result =
       validateSecurityKey((byte *)(*(int *)(message + 6) + required_parameter_length));
  if (authentication_result == 0) {
    return 0xff;
  }
  return 3;
}



//
