//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 protectionStateValidator(word derate_selector)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  short *psVar7;
  
  if (derate_selector == 0) {
    puVar5 = (ushort *)(_bit_pattern_index_result + 0x18);
    uVar4 = *(ushort *)(_protection_config_table_ptr + 0x1a);
    iVar6 = *(int *)(_protection_state_data_ptr + 0x26);
    psVar7 = (short *)(_bit_pattern_index_result + 0x16);
  }
  else {
    puVar5 = (ushort *)(_bit_pattern_index_result + 0x1c);
    uVar4 = *(ushort *)(_protection_config_table_ptr + 0x1c);
    iVar6 = *(int *)(_protection_state_data_ptr + 0x2a);
    psVar7 = (short *)(_bit_pattern_index_result + 0x1a);
  }
  uVar2 = (uint)*(ushort *)
                 (&status_32_word_bit_mapped_system_error_status_word_0_0_1 +
                 (short)((int)(uint)uVar4 >> 4) * 2);
  uVar3 = 0;
  if ((uVar2 & 1 << (uVar4 & 0xf)) != 0) {
    uVar2 = (uint)*(ushort *)
                   (&fault_first_occurrence_flags_word_0 + (short)((int)(uint)uVar4 >> 4) * 2);
    uVar3 = uVar2 & 1 << (uVar4 & 0xf);
    if (uVar3 == 0) {
      uVar1 = ~(1 << (uVar4 & 0xf));
      uVar3 = (uint)uVar1;
      uVar2 = (int)(uint)uVar4 >> 4;
      *(ushort *)(&status_32_word_bit_mapped_system_error_status_word_0_0_1 + (short)uVar2 * 2) =
           uVar1 & *(ushort *)
                    (&status_32_word_bit_mapped_system_error_status_word_0_0_1 + (short)uVar2 * 2);
      if (*psVar7 != 0) {
        *psVar7 = 0;
        *(short *)(iVar6 + 6 + (uint)*puVar5 * 8) =
             key_on_hour_meter._2_2_ - (short)*(undefined4 *)(iVar6 + (uint)*puVar5 * 8);
        *puVar5 = *puVar5 + 1;
        uVar3 = (uint)*puVar5 % 5;
        uVar2 = *puVar5 / 5;
        *puVar5 = (ushort)uVar3;
      }
    }
  }
  return CONCAT44(uVar2,uVar3);
}



//
