=== validateSecurityKey
byte validateSecurityKey(byte *auth_payload_ptr)
{
  bool bVar1;
  byte validation_result;
  byte bVar2;
  char cVar3;
  uint *puVar4;
  byte *pbVar5;
  uint local_12;
  byte extracted_key [6];
  byte hour_meter_bytes [4];
  if (calibration_download_security_key_cal == 0xff) {
    validation_result = 0;
  }
  else if (security_key_failure_count == 0x11) {
    validation_result = 1;
  }
  else {
    unscrambleSecurityKey(auth_payload_ptr,extracted_key);
    bVar2 = 1;
    puVar4 = &local_12;
    pbVar5 = hour_meter_bytes;
    do {
      *(byte *)puVar4 = *pbVar5;
      bVar2 = bVar2 + 1;
      puVar4 = (uint *)((int)puVar4 + 1);
      pbVar5 = pbVar5 + 1;
    } while (bVar2 < 4);
                        if ((key_on_hour_meter & 0xffffff00) - (local_12 & 0xffffff00) < 0x1a) {
      bVar1 = true;
      pbVar5 = extracted_key;
      for (cVar3 = '\0'; (bVar1 && (cVar3 < '\x06')); cVar3 = cVar3 + '\x01') {
                            if (security_master_password_cal[(short)cVar3] != *pbVar5) {
          bVar1 = false;
        }
        pbVar5 = pbVar5 + 1;
      }
      if (bVar1) {
        validation_result = 0;
        security_key_failure_count = 0;
      }
      else {
        validation_result = 1;
        security_key_failure_count = security_key_failure_count + 1;
      }
    }
    else {
      validation_result = 1;
      security_key_failure_count = security_key_failure_count + 1;
    }
  }
  return validation_result;
}
