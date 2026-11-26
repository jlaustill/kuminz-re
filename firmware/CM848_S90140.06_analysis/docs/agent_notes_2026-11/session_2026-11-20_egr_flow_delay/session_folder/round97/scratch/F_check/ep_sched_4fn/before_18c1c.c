//

short cm550_diagnosticProtectionProcessor
                (word *configuration_pointer,dword state_offset,dword threshold_value)

{
  ushort uVar1;
  short sVar2;
  word wVar3;
  
  uVar1 = *configuration_pointer;
  if ((uVar1 & 1) != 0) {
    sVar2 = cm550_protectionConditionEvaluator(configuration_pointer,(dword *)state_offset,0,0);
    if (sVar2 == 0) {
      *(undefined2 *)(threshold_value + 4) = 0;
    }
    else if ((uVar1 & 0x40) == 0) {
      wVar3 = cm550_protectionPercentageCalculator
                        (**(word **)state_offset,**(word **)(state_offset + 10),
                         **(word **)(state_offset + 0xe));
      *(word *)(threshold_value + 4) = wVar3;
    }
    else {
      *(undefined2 *)(threshold_value + 4) = 0x100;
    }
  }
  sVar2 = 0;
  if ((uVar1 & 2) != 0) {
    sVar2 = cm550_protectionConditionEvaluator(configuration_pointer,(dword *)state_offset,1,0);
    if (sVar2 == 0) {
      *(undefined2 *)(threshold_value + 6) = 0;
      return 0;
    }
    *(undefined2 *)(threshold_value + 6) = 0x100;
  }
  return sVar2;
}



//
