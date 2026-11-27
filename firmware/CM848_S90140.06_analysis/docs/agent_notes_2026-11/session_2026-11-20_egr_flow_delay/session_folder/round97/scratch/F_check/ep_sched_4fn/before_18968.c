//

uint cm550_protectionConditionEvaluator
               (word *threshold_pointer,dword *state_pointer,word threshold_set_select,
               word sensor_value)

{
  ushort uVar1;
  ushort uVar2;
  uint in_D0;
  uint uVar3;
  ushort unaff_D3w;
  
  uVar1 = *threshold_pointer;
  if ((uVar1 & 0x30) == 0) {
    uVar2 = *(ushort *)*state_pointer;
    if (threshold_set_select == 0) {
      if (sensor_value == 0) {
        unaff_D3w = **(ushort **)((int)state_pointer + 10);
      }
      else if (sensor_value == 2) {
        unaff_D3w = threshold_pointer[8];
      }
      else if (sensor_value == 3) {
        unaff_D3w = threshold_pointer[0x10];
      }
    }
    else if (sensor_value == 0) {
      unaff_D3w = **(ushort **)((int)state_pointer + 0x12);
    }
    else if (sensor_value == 2) {
      unaff_D3w = threshold_pointer[9];
    }
    else if (sensor_value == 3) {
      unaff_D3w = threshold_pointer[0x11];
    }
    uVar3 = in_D0 & 0xffff0000;
    if ((uVar1 & 4) == 0) {
      if (uVar2 < unaff_D3w) {
        return 1;
      }
    }
    else if (unaff_D3w <= uVar2) {
      return 1;
    }
  }
  else {
    uVar3 = (byte)-((*(ushort *)(state_pointer + 1) & *(ushort *)*state_pointer) != 0) & 1;
    if (uVar3 == ((byte)-((uVar1 & 0x10) != 0) & 1)) {
      return 1;
    }
  }
  return uVar3 & 0xffff0000;
}



//
