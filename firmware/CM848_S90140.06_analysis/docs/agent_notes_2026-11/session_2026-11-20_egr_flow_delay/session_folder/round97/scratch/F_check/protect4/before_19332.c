//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort protectionStateProcessor(word derate_selector)

{
  dword *pdVar1;
  word wVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short *psVar6;
  int iVar7;
  
  if (derate_selector == 0) {
    uVar4 = *(ushort *)(_bit_pattern_index_result + 0x18);
    uVar3 = _protection_config_table_ptr[0xd];
    iVar7 = *(int *)((int)_protection_state_data_ptr + 0x26);
    psVar6 = (short *)(_bit_pattern_index_result + 0x16);
  }
  else {
    uVar4 = *(ushort *)(_bit_pattern_index_result + 0x1c);
    uVar3 = _protection_config_table_ptr[0xe];
    iVar7 = *(int *)((int)_protection_state_data_ptr + 0x2a);
    psVar6 = (short *)(_bit_pattern_index_result + 0x1a);
  }
  if (*psVar6 == 0) {
    *psVar6 = 1;
    pdVar1 = (dword *)(iVar7 + (uint)uVar4 * 8);
    *pdVar1 = key_on_hour_meter;
    *(undefined2 *)((int)pdVar1 + 6) = 0;
    if ((*_protection_config_table_ptr & 8) == 0) {
      *(undefined2 *)(pdVar1 + 1) = 0;
    }
    else {
      *(undefined2 *)(pdVar1 + 1) = 0xffff;
    }
  }
  uVar5 = 1 << (uVar3 & 0xf);
  *(ushort *)
   (&status_32_word_bit_mapped_system_error_status_word_0_0_1 + (short)((int)(uint)uVar3 >> 4) * 2)
       = uVar5 | *(ushort *)
                  (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
                  (short)((int)(uint)uVar3 >> 4) * 2);
  *(ushort *)(&fault_first_occurrence_flags_word_0 + (short)((int)(uint)uVar3 >> 4) * 2) =
       uVar5 | *(ushort *)
                (&fault_first_occurrence_flags_word_0 + (short)((int)(uint)uVar3 >> 4) * 2);
  uVar3 = *_protection_config_table_ptr & 0xc;
  if ((*_protection_config_table_ptr & 0xc) != 0) {
    wVar2 = cm550_protectionCalculationHelper
                      (*(word *)*_protection_state_data_ptr,*(word *)(iVar7 + 4 + (uint)uVar4 * 8),
                       *_protection_config_table_ptr);
    uVar3 = 0;
    if (wVar2 != 0) {
      uVar3 = *(ushort *)*_protection_state_data_ptr;
      *(ushort *)(iVar7 + 4 + (uint)uVar4 * 8) = uVar3;
    }
  }
  return uVar3;
}



//
