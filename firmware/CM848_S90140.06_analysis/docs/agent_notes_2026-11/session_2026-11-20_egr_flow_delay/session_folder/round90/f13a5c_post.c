=== cm550_FUN_00013a5c
undefined * cm550_FUN_00013a5c(void)
{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  byte bVar5;
  ushort uVar4;
  byte bVar6;
  short sVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  puVar1 = (undefined *)(_feature_enable_flags_word & 0x20);
  if ((((_feature_enable_flags_word & 0x20) == 0) && (_trending_trigger_detected_flag != 1)) &&
     (_snapshot_capture_active_flag != 1)) {
    if (DAT_00800372 == '\0') {
      uVar4 = 0;
      puVar9 = &fuel_demand_blend_input;
      do {
        *puVar9 = 0;
        uVar4 = uVar4 + 1;
        puVar9 = puVar9 + 1;
      } while (uVar4 < 400);
      _data_record_buffer_write_ptr = &fuel_demand_blend_input;
      DAT_00800372 = '\x01';
    }
  }
  else {
    if ((DAT_00800352 == '\0') && (_snapshot_capture_active_flag == 0)) {
      DAT_00800352 = '\x01';
      cm550_FUN_00013e12();
      bVar6 = 0;
      trending_valid_channel_count = 0;
      sVar7 = 0;
      for (bVar5 = 0; puVar1 = (undefined *)(uint)bVar5, puVar1 < (undefined *)(uint)_DAT_00803dc8;
          bVar5 = bVar5 + 1) {
        bVar6 = (char)*(undefined2 *)((int)&datalogger_data_1_length_cal + (int)sVar7) + bVar6;
        if (bVar6 < 0xb) {
          trending_valid_channel_count = trending_valid_channel_count + 1;
        }
        sVar7 = sVar7 + 6;
      }
      _data_record_buffer_write_ptr = &fuel_demand_blend_input;
    }
    if (scheduler_phase_execution_time != '\0') {
      scheduler_phase_execution_time = '\0';
      if (_trending_trigger_detected_flag != 0) {
        _snapshot_capture_active_flag = 1;
        puVar1 = _data_record_buffer_write_ptr + -0x800374;
        _DAT_00800522 = SUB42(puVar1,0);
        _DAT_00800524 = key_on_hour_meter;
        DAT_00800528 = DAT_0080bac7;
        DAT_00800529 = DAT_0080bac9;
        data_record_byte_counter = '\0';
      }
      uVar4 = 0;
      while (bVar6 = (byte)uVar4, bVar6 < trending_valid_channel_count) {
        puVar2 = (undefined *)0x0;
        while( true ) {
          puVar1 = (undefined *)
                   (uint)*(ushort *)((int)&datalogger_data_1_length_cal + (int)(short)(uVar4 * 6));
          cVar3 = (char)puVar2;
          if (puVar1 <= puVar2) break;
          *_data_record_buffer_write_ptr = puVar2[*(int *)(&DAT_00800508 + (short)(uVar4 << 2))];
          _data_record_buffer_write_ptr = _data_record_buffer_write_ptr + 1;
          if (_data_record_buffer_write_ptr == &data_record_buffer_write_ptr) {
            _data_record_buffer_write_ptr = &fuel_demand_blend_input;
          }
          if ((_snapshot_capture_active_flag == 1) &&
             (data_record_byte_counter = data_record_byte_counter + '\x01',
             data_record_byte_counter == -0x38)) {
            cVar3 = (char)*(undefined2 *)
                           ((int)&datalogger_data_1_length_cal + (int)(short)(uVar4 * 6));
            DAT_0080052a = '\x01';
          }
          puVar2 = (undefined *)(uint)(byte)(cVar3 + 1);
        }
        if ((_snapshot_capture_active_flag == 1) && (data_record_byte_counter == -0x38)) {
          bVar6 = trending_valid_channel_count;
        }
        uVar4 = (ushort)(byte)(bVar6 + 1);
      }
      DAT_00800372 = '\0';
      if ((_snapshot_capture_active_flag == 1) && (DAT_0080052a != '\0')) {
        if (_DAT_008052fa == 0) {
          uVar8 = 0x804fca;
          _DAT_008052ea = _DAT_00800522;
          _DAT_008052ec = _DAT_00800524;
          DAT_008052f0 = DAT_00800528;
          DAT_008052f1 = DAT_00800529;
          _DAT_008052fa = 1;
        }
        else {
          uVar8 = 0x80515a;
          _DAT_008052f2 = _DAT_00800522;
          _DAT_008052f4 = _DAT_00800524;
          DAT_008052f8 = DAT_00800528;
          DAT_008052f9 = DAT_00800529;
          _DAT_008052fc = 1;
        }
        puVar1 = (undefined *)cm550_FUN_00014292(&fuel_demand_blend_input,uVar8);
        _snapshot_capture_active_flag = 0;
        DAT_0080052a = '\0';
      }
    }
  }
  return puVar1;
}
