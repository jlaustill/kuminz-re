/*
 * Decompiled from: dclj1708.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_6f661000 at 6f661000

void FUN_6f661000(void)

{
  FUN_6f66100f();
  FUN_6f66101e();
  return;
}



// Function: FUN_6f66100f at 6f66100f

void FUN_6f66100f(void)

{
  FUN_6f662b90(&DAT_6f665570);
  return;
}



// Function: FUN_6f66101e at 6f66101e

void FUN_6f66101e(void)

{
  FUN_6f66322a(FUN_6f661030);
  return;
}



// Function: FUN_6f661030 at 6f661030

void FUN_6f661030(void)

{
  FUN_6f662b9e();
  return;
}



// Function: RX1708 at 6f66103f

size_t __cdecl RX1708(void *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  uint local_18;
  int local_14;
  size_t local_10;
  byte local_c;
  int local_8;
  
                    /* 0x103f  6  RX1708 */
  local_10 = 0;
  local_8 = 0;
  local_18 = local_18 & 0xffff0000;
  uVar2 = FUN_6f661ab0();
  if (uVar2 == 0) {
    local_10 = 0;
  }
  else {
    local_14 = FUN_6f661f3d(DAT_6f66558c,5);
    if (local_14 == -1) {
      FUN_6f661f5f(DAT_6f66558c,(ushort *)&local_18);
      if ((local_18 & 4) != 0) {
        FUN_6f661ef6(DAT_6f66558c,0);
      }
    }
    else {
      local_c = (byte)local_14;
      if (DAT_6f665598 == 0) {
        iVar3 = FUN_6f661457((byte)local_14,&DAT_6f665558,DAT_6f665428);
        if (iVar3 != 0) {
          DAT_6f665598 = 1;
        }
      }
      else if (DAT_6f665598 == 2) {
        if (DAT_6f665428 == 0) {
          if (DAT_6f6655a0 == DAT_6f6655a4) {
            DAT_6f665598 = 1;
          }
          else {
            DAT_6f665598 = 1;
            FUN_6f6614a7();
          }
        }
        else {
          DAT_6f665598 = 0;
        }
        while ((DAT_6f665598 == 0 && (DAT_6f6655a0 != DAT_6f6655a4))) {
          FUN_6f6614a7();
          if ((DAT_6f6655a0 != DAT_6f6655a4) &&
             (iVar3 = FUN_6f661457((&DAT_6f66542c)[DAT_6f6655a0],&DAT_6f665558,DAT_6f665428),
             iVar3 != 0)) {
            DAT_6f665598 = 1;
          }
        }
      }
      if (DAT_6f665598 == 1) {
        (&DAT_6f66542c)[DAT_6f6655a4] = local_c;
        local_8 = 1;
        iVar3 = FUN_6f6614ef();
        while ((iVar3 == 0 && (FUN_6f6614a7(), DAT_6f6655a0 != DAT_6f6655a4))) {
          iVar3 = FUN_6f661457((&DAT_6f66542c)[DAT_6f6655a0],&DAT_6f665558,DAT_6f665428);
        }
      }
    }
    if ((DAT_6f6655a8 != DAT_6f6655a4) && (DAT_6f665598 == 1)) {
      do {
        do {
          while( true ) {
            if ((local_8 != 0) && (DAT_6f6655a8 != DAT_6f6655a0)) {
              DAT_6f6655ac = DAT_6f6655a0;
              DAT_6f6655a8 = DAT_6f6655a0;
            }
            local_8 = 0;
            if (DAT_6f6655a8 == DAT_6f6655ac) {
              DAT_6f66559c = (&DAT_6f66542c)[DAT_6f6655ac];
            }
            bVar1 = FUN_6f66157b();
            if ((CONCAT31(extraout_var,bVar1) == 0) || (DAT_6f6655a4 == DAT_6f6655ac)) {
              FUN_6f66153d();
              return 0;
            }
            if (((DAT_6f6655ac - DAT_6f6655a0) + 300) % 300 <= param_2) break;
            do {
              FUN_6f6614a7();
              if (DAT_6f6655a0 == DAT_6f6655a4) break;
              iVar3 = FUN_6f661457((&DAT_6f66542c)[DAT_6f6655a0],&DAT_6f665558,DAT_6f665428);
            } while (iVar3 == 0);
            iVar3 = FUN_6f662cae(&DAT_6f665570,DAT_6f6655a0,DAT_6f6655a0);
            if (iVar3 == 0) {
              FUN_6f662ba9(&DAT_6f665570,300);
            }
          }
          DAT_6f66559c = DAT_6f66559c + (&DAT_6f66542c)[DAT_6f6655ac];
        } while ((DAT_6f66559c == '\0') &&
                (iVar3 = FUN_6f662cae(&DAT_6f665570,DAT_6f6655a8,DAT_6f6655ac), iVar3 != 0));
        if ((DAT_6f66559c == '\0') &&
           (iVar3 = FUN_6f661457((&DAT_6f66542c)[DAT_6f6655a8],&DAT_6f665558,DAT_6f665428),
           iVar3 != 0)) {
          FUN_6f662c17(&DAT_6f665570,DAT_6f6655a8,DAT_6f6655ac);
          FUN_6f662c41(&DAT_6f665570,DAT_6f6655a8,DAT_6f6655ac);
          local_10 = FUN_6f6613da(param_1,&DAT_6f66542c,DAT_6f6655a8,DAT_6f6655ac);
        }
      } while (DAT_6f66559c != '\0');
    }
  }
  return local_10;
}



// Function: FUN_6f6613da at 6f6613da

size_t __cdecl FUN_6f6613da(void *param_1,void *param_2,uint param_3,uint param_4)

{
  undefined4 local_8;
  
  if (param_3 < param_4) {
    local_8 = param_4 - param_3;
    memcpy(param_1,(void *)((int)param_2 + param_3),local_8);
  }
  else {
    local_8 = 300 - param_3;
    memcpy(param_1,(void *)((int)param_2 + param_3),local_8);
    if (param_4 != 0) {
      memcpy((void *)((int)param_1 + local_8),param_2,param_4);
      local_8 = local_8 + param_4;
    }
  }
  return local_8;
}



// Function: FUN_6f661457 at 6f661457

undefined4 __cdecl FUN_6f661457(byte param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else if ((param_3 == 0) || (pvVar1 = memchr(param_2,(uint)param_1,param_3), pvVar1 != (void *)0x0)
          ) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_6f6614a7 at 6f6614a7

bool FUN_6f6614a7(void)

{
  bool bVar1;
  
  bVar1 = DAT_6f6655a0 != DAT_6f6655a4;
  if (bVar1) {
    DAT_6f6655a0 = (DAT_6f6655a0 + 1) % 300;
    DAT_6f6655a8 = DAT_6f6655a0;
    DAT_6f6655ac = DAT_6f6655a0;
  }
  return bVar1;
}



// Function: FUN_6f6614ef at 6f6614ef

undefined4 FUN_6f6614ef(void)

{
  undefined4 uVar1;
  
  if ((DAT_6f6655a4 == DAT_6f6655a0) &&
     ((DAT_6f6655a0 != DAT_6f6655a8 || (DAT_6f6655a0 != DAT_6f6655ac)))) {
    uVar1 = 0;
  }
  else {
    DAT_6f6655a4 = (DAT_6f6655a4 + 1) % 300;
    uVar1 = 1;
  }
  return uVar1;
}



// Function: FUN_6f66153d at 6f66153d

bool FUN_6f66153d(void)

{
  bool bVar1;
  
  bVar1 = DAT_6f6655a8 != DAT_6f6655a4;
  if (bVar1) {
    DAT_6f6655a8 = (DAT_6f6655a8 + 1) % 300;
    DAT_6f6655ac = DAT_6f6655a8;
  }
  return bVar1;
}



// Function: FUN_6f66157b at 6f66157b

bool FUN_6f66157b(void)

{
  bool bVar1;
  
  bVar1 = DAT_6f6655ac != DAT_6f6655a4;
  if (bVar1) {
    DAT_6f6655ac = (DAT_6f6655ac + 1) % 300;
  }
  return bVar1;
}



// Function: TX1708 at 6f6615ad

int __cdecl TX1708(void *param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined3 extraout_var;
  int iVar7;
  short sVar8;
  ushort uVar9;
  int local_14;
  uint local_10;
  uint local_8;
  
                    /* 0x15ad  8  TX1708 */
  local_14 = 0xff00;
  sVar4 = 0;
  uVar5 = FUN_6f661ab0();
  if (uVar5 == 0) {
    local_14 = 0;
  }
  else {
    if ((param_1 == (void *)0x0) || ((int)param_2 < 1)) {
      FUN_6f661ef6(DAT_6f66558c,0);
      local_14 = 0;
    }
    else {
      memcpy(&DAT_6f665228,param_1,param_2);
      cVar1 = FUN_6f661a5a(0x6f665228,param_2);
      (&DAT_6f665228)[param_2] = cVar1;
      param_2 = param_2 + 1;
      sVar4 = 5;
    }
    while ((sVar4 != 0 && (local_14 != 0))) {
      FUN_6f661ef6(DAT_6f66558c,0);
      iVar6 = FUN_6f6624e0();
      sVar8 = 5;
      do {
        FUN_6f662393(DAT_6f665590);
        bVar2 = FUN_6f6623bf(DAT_6f665590);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          sVar8 = 5;
        }
        else {
          sVar8 = sVar8 + -1;
        }
      } while ((sVar8 != 0) && (uVar5 = FUN_6f6624e0(), uVar5 < iVar6 + 0x6eU));
      if (sVar8 == 0) {
        iVar6 = FUN_6f6624e0();
        do {
          iVar7 = FUN_6f661f17(DAT_6f66558c,&DAT_6f665228,param_2);
          if (iVar7 != 0) break;
          uVar5 = FUN_6f6624e0();
        } while (uVar5 < iVar6 + 0x14U);
        local_8 = 0;
        iVar6 = FUN_6f6624e0();
        local_10 = iVar6 + 0x32;
        do {
          uVar5 = FUN_6f661f3d(DAT_6f66558c,5);
          if (uVar5 != 0xffffffff) {
            if ((local_8 != 0) && ((byte)(&DAT_6f665228)[local_8] != uVar5)) {
              uVar9 = 0;
              do {
                uVar9 = uVar9 + 1;
                uVar3 = (short)local_8 - 1;
                local_8 = (uint)uVar3;
                if (uVar3 == 0) break;
                iVar6 = memcmp(&DAT_6f665228,&DAT_6f665228 + uVar9,(uint)uVar3);
              } while (iVar6 != 0);
              local_10 = local_10 + (uint)uVar9 * -0x32;
            }
            if ((byte)(&DAT_6f665228)[local_8] == uVar5) {
              local_8 = (uint)(ushort)((short)local_8 + 1);
              local_10 = local_10 + 0x32;
            }
          }
        } while (((int)local_8 < (int)param_2) && (uVar5 = FUN_6f6624e0(), uVar5 < local_10));
        if (local_8 == param_2) {
          local_14 = 0;
        }
        else {
          local_14 = 0xff01;
        }
      }
      else {
        local_14 = 0xff01;
      }
      if (local_14 != 0) {
        sVar4 = sVar4 + -1;
      }
    }
  }
  return local_14;
}



// Function: MON_1708 at 6f66182c

/* void __cdecl MON_1708(char,char *,int) */

void __cdecl MON_1708(char param_1,char *param_2,int param_3)

{
                    /* 0x182c  1  ?MON_1708@@YAXDPADH@Z */
  if (param_2 == (char *)0x0) {
    DAT_6f665428 = 0;
  }
  else {
    memcpy(&DAT_6f665558,param_2,param_3);
    DAT_6f665428 = param_3;
  }
  DAT_6f665598 = (uint)(DAT_6f665428 == 0);
  DAT_6f6655a4 = 0;
  DAT_6f6655a0 = 0;
  DAT_6f6655ac = 0;
  DAT_6f6655a8 = 0;
  DAT_6f66559c = 0;
  FUN_6f662ba9(&DAT_6f665570,300);
  if (DAT_6f66558c != (void *)0x0) {
    FUN_6f661ef6(DAT_6f66558c,0);
  }
  return;
}



// Function: MON1708 at 6f6618ca

void __cdecl MON1708(char param_1,char *param_2)

{
  undefined4 local_8;
  
                    /* 0x18ca  4  MON1708 */
  local_8 = 0;
  if (param_2 != (char *)0x0) {
    local_8 = strlen(param_2);
  }
  MON_1708(param_1,param_2,local_8);
  return;
}



// Function: CTS1708 at 6f661902

bool CTS1708(void)

{
  bool bVar1;
  uint uVar2;
  
                    /* 0x1902  2  CTS1708 */
  uVar2 = FUN_6f661ab0();
  if (uVar2 == 0) {
    bVar1 = false;
  }
  else {
    FUN_6f662393(DAT_6f665590);
    bVar1 = FUN_6f6623bf(DAT_6f665590);
  }
  return bVar1;
}



// Function: SET_PORT_1708 at 6f661933

undefined4 __cdecl SET_PORT_1708(int param_1)

{
  undefined4 local_8;
  
                    /* 0x1933  7  SET_PORT_1708 */
  local_8 = 0;
  if (param_1 < 8) {
    if (DAT_6f665020 == -1) {
      DAT_6f665020 = param_1;
      local_8 = 1;
    }
    else {
      DAT_6f665594 = DAT_6f665594 + '\x01';
      local_8 = 1;
    }
  }
  return local_8;
}



// Function: REMOVE_PORT_1708 at 6f66197b

void REMOVE_PORT_1708(void)

{
                    /* 0x197b  5  REMOVE_PORT_1708 */
  if (DAT_6f665594 == '\0') {
    DAT_6f665020 = 0xffffffff;
    DAT_6f665584 = 0;
    if (DAT_6f665590 != (void *)0x0) {
      FUN_6f661e90(DAT_6f665590,1);
    }
    DAT_6f665590 = (void *)0x0;
    if (DAT_6f66558c != (undefined4 *)0x0) {
      (**(code **)*DAT_6f66558c)(1);
    }
    DAT_6f66558c = (undefined4 *)0x0;
    if (DAT_6f665588 != (int *)0x0) {
      (**(code **)(*DAT_6f665588 + 0xc))(1);
    }
    DAT_6f665588 = (int *)0x0;
  }
  else {
    DAT_6f665594 = DAT_6f665594 + -1;
  }
  return;
}



// Function: FUN_6f661a5a at 6f661a5a

char __cdecl FUN_6f661a5a(int param_1,uint param_2)

{
  byte bVar1;
  undefined4 local_c;
  
  bVar1 = 0;
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    bVar1 = bVar1 + *(char *)(param_1 + local_c);
  }
  return ~bVar1 + 1;
}



// Function: FUN_6f661ab0 at 6f661ab0

uint FUN_6f661ab0(void)

{
  bool bVar1;
  short sVar2;
  void *pvVar3;
  undefined3 extraout_var;
  undefined4 *local_a0;
  void *local_90;
  undefined4 *local_8c;
  int *local_88;
  ushort local_1c [2];
  short local_18;
  undefined2 uStack_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_6f66343c;
  local_10 = ExceptionList;
  local_14 = 0;
  local_1c[0] = 0;
  ExceptionList = &local_10;
  sVar2 = FUN_6f662806();
  _local_18 = CONCAT22(uStack_16,sVar2);
  if (sVar2 != DAT_6f665584) {
    if (DAT_6f665590 != (void *)0x0) {
      FUN_6f661e90(DAT_6f665590,1);
    }
    DAT_6f665590 = (void *)0x0;
    if (DAT_6f66558c != (undefined4 *)0x0) {
      (**(code **)*DAT_6f66558c)(1);
    }
    DAT_6f66558c = (undefined4 *)0x0;
    if (DAT_6f665588 != (int *)0x0) {
      (**(code **)(*DAT_6f665588 + 0xc))(1);
    }
    DAT_6f665588 = (int *)0x0;
  }
  if (DAT_6f665588 == (int *)0x0) {
    if ((-1 < DAT_6f665020) && (DAT_6f665020 < 8)) {
      pvVar3 = operator_new(0x410);
      local_8 = 0;
      if (pvVar3 == (void *)0x0) {
        local_88 = (int *)0x0;
      }
      else {
        local_88 = FUN_6f66201c(pvVar3,DAT_6f665020);
      }
      local_8 = 0xffffffff;
      DAT_6f665588 = local_88;
      if (local_88 != (int *)0x0) {
        pvVar3 = operator_new(8);
        local_8 = 1;
        if (pvVar3 == (void *)0x0) {
          local_8c = (undefined4 *)0x0;
        }
        else {
          local_8c = FUN_6f661ec0(pvVar3,DAT_6f665588);
        }
        local_8 = 0xffffffff;
        DAT_6f66558c = local_8c;
        if ((local_8c != (undefined4 *)0x0) &&
           (bVar1 = FUN_6f661f5f(local_8c,local_1c), CONCAT31(extraout_var,bVar1) == 0)) {
          pvVar3 = operator_new(8);
          local_8 = 2;
          if (pvVar3 == (void *)0x0) {
            local_90 = (void *)0x0;
          }
          else {
            local_90 = (void *)FUN_6f66236a(pvVar3,(int)DAT_6f66558c);
          }
          local_8 = 0xffffffff;
          DAT_6f665590 = local_90;
          local_14 = (uint)(local_90 != (void *)0x0);
        }
      }
      if (local_14 == 0) {
        if (DAT_6f665590 != (void *)0x0) {
          FUN_6f661e90(DAT_6f665590,1);
        }
        DAT_6f665590 = (void *)0x0;
        if (DAT_6f66558c != (undefined4 *)0x0) {
          (**(code **)*DAT_6f66558c)(1);
        }
        DAT_6f66558c = (undefined4 *)0x0;
        if (DAT_6f665588 != (int *)0x0) {
          (**(code **)(*DAT_6f665588 + 0xc))(1);
        }
        DAT_6f665588 = (int *)0x0;
      }
      else {
        DAT_6f665584 = local_18;
        pvVar3 = operator_new(8);
        local_8 = 3;
        if (pvVar3 == (void *)0x0) {
          local_a0 = (undefined4 *)0x0;
        }
        else {
          local_a0 = FUN_6f662243(pvVar3,DAT_6f66558c);
        }
        local_8 = 0xffffffff;
        FUN_6f662279(local_a0,0x2580,'N',8,1);
        FUN_6f6623d8();
        if (local_a0 != (undefined4 *)0x0) {
          (**(code **)*local_a0)(1);
        }
      }
    }
  }
  else {
    local_14 = 1;
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_6f661e90 at 6f661e90

void * __thiscall FUN_6f661e90(void *this,uint param_1)

{
  FUN_6f662388();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_6f661ec0 at 6f661ec0

undefined4 * __thiscall FUN_6f661ec0(void *this,undefined4 param_1)

{
  *(undefined ***)this = &PTR_FUN_6f6640e0;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_6f661ee2 at 6f661ee2

void __fastcall FUN_6f661ee2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_6f6640e0;
  return;
}



// Function: FUN_6f661ef6 at 6f661ef6

void __thiscall FUN_6f661ef6(void *this,undefined4 param_1)

{
  (**(code **)**(undefined4 **)((int)this + 4))(param_1);
  return;
}



// Function: FUN_6f661f17 at 6f661f17

void __thiscall FUN_6f661f17(void *this,undefined4 param_1,undefined4 param_2)

{
  (**(code **)(**(int **)((int)this + 4) + 4))(param_1,param_2);
  return;
}



// Function: FUN_6f661f3d at 6f661f3d

void __thiscall FUN_6f661f3d(void *this,undefined4 param_1)

{
  (**(code **)(**(int **)((int)this + 4) + 8))(param_1);
  return;
}



// Function: FUN_6f661f5f at 6f661f5f

bool __thiscall FUN_6f661f5f(void *this,ushort *param_1)

{
  BOOL BVar1;
  ushort local_c;
  DWORD local_8;
  
  local_8 = 0;
  local_c = 0;
  BVar1 = ClearCommError(*(HANDLE *)(*(int *)((int)this + 4) + 8),&local_8,(LPCOMSTAT)0x0);
  if (BVar1 != 0) {
    if ((local_8 & 0x10) != 0) {
      local_c = 0x10;
    }
    if ((local_8 & 4) != 0) {
      local_c = local_c | 1;
    }
    if ((local_8 & 8) != 0) {
      local_c = local_c | 2;
    }
    if ((local_8 & 1) != 0) {
      local_c = local_c | 4;
    }
    if ((local_8 & 2) != 0) {
      local_c = local_c | 8;
    }
    *param_1 = local_c;
  }
  return BVar1 == 0;
}



// Function: FUN_6f66201c at 6f66201c

undefined4 * __thiscall FUN_6f66201c(void *this,undefined4 param_1)

{
  HANDLE pvVar1;
  _COMMTIMEOUTS local_1c;
  LPCSTR local_8;
  
  FUN_6f662450((undefined4 *)this);
  *(undefined ***)this = &PTR_FUN_6f6640e8;
  local_8 = (LPCSTR)0x0;
  *(undefined4 *)((int)this + 4) = param_1;
  switch(*(undefined4 *)((int)this + 4)) {
  case 0:
    local_8 = &DAT_6f665070;
    break;
  case 1:
    local_8 = &DAT_6f665078;
    break;
  case 2:
    local_8 = &DAT_6f665080;
    break;
  case 3:
    local_8 = &DAT_6f665088;
    break;
  case 4:
    local_8 = &DAT_6f665090;
    break;
  case 5:
    local_8 = &DAT_6f665098;
    break;
  case 6:
    local_8 = &DAT_6f6650a0;
    break;
  case 7:
    local_8 = &DAT_6f6650a8;
  }
  if (local_8 != (LPCSTR)0x0) {
    pvVar1 = CreateFileA(local_8,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    *(HANDLE *)((int)this + 8) = pvVar1;
    local_1c.ReadIntervalTimeout = 0xffffffff;
    local_1c.ReadTotalTimeoutMultiplier = 0;
    local_1c.ReadTotalTimeoutConstant = 0;
    local_1c.WriteTotalTimeoutMultiplier = 0;
    local_1c.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(*(HANDLE *)((int)this + 8),&local_1c);
  }
  return (undefined4 *)this;
}



// Function: FUN_6f662127 at 6f662127

void __fastcall FUN_6f662127(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_6f6640e8;
  CloseHandle((HANDLE)param_1[2]);
  return;
}



// Function: FUN_6f662148 at 6f662148

undefined4 __fastcall FUN_6f662148(int param_1)

{
  PurgeComm(*(HANDLE *)(param_1 + 8),8);
  return 1;
}



// Function: FUN_6f662169 at 6f662169

bool __thiscall FUN_6f662169(void *this,LPCVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD local_8;
  
  local_8 = param_2;
  BVar1 = WriteFile(*(HANDLE *)((int)this + 8),param_1,param_2,&local_8,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    local_8 = 0;
  }
  return local_8 == param_2;
}



// Function: FUN_6f6621b1 at 6f6621b1

uint __thiscall FUN_6f6621b1(void *this,DWORD param_1)

{
  BOOL BVar1;
  _COMMTIMEOUTS local_24;
  byte local_10 [4];
  uint local_c;
  DWORD local_8;
  
  local_c = 0xffffffff;
  if (param_1 == 0) {
    local_24.ReadIntervalTimeout = 0xffffffff;
    local_24.ReadTotalTimeoutMultiplier = 0;
  }
  else {
    local_24.ReadIntervalTimeout = param_1;
    local_24.ReadTotalTimeoutMultiplier = param_1;
  }
  local_24.ReadTotalTimeoutConstant = 0;
  SetCommTimeouts(*(HANDLE *)((int)this + 8),&local_24);
  BVar1 = ReadFile(*(HANDLE *)((int)this + 8),local_10,1,&local_8,(LPOVERLAPPED)0x0);
  if ((BVar1 == 0) || (local_8 != 1)) {
    local_c = 0xffffffff;
  }
  else {
    local_c = (uint)local_10[0];
  }
  return local_c;
}



// Function: FUN_6f662243 at 6f662243

undefined4 * __thiscall FUN_6f662243(void *this,undefined4 param_1)

{
  *(undefined **)this = &DAT_6f66410c;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_6f662265 at 6f662265

void __fastcall FUN_6f662265(undefined4 *param_1)

{
  *param_1 = &DAT_6f66410c;
  return;
}



// Function: FUN_6f662279 at 6f662279

undefined4 __thiscall
FUN_6f662279(void *this,undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  BOOL BVar1;
  char local_8c [100];
  int local_28;
  undefined4 local_24;
  _DCB local_20;
  
  local_28 = FUN_6f6624a0(*(int *)((int)this + 4));
  local_24 = 0;
  if (local_28 != 0) {
    sprintf(local_8c,s_baud__ld_parity__c_data__d_stop__6f6650b0,param_1,(int)param_2,param_3,
            param_4);
    BVar1 = GetCommState(*(HANDLE *)(local_28 + 8),&local_20);
    if (BVar1 != 0) {
      BVar1 = BuildCommDCBA(local_8c,&local_20);
      if (BVar1 != 0) {
        local_20._8_4_ = local_20._8_4_ & 0xffff80c3 | 0x1010;
        SetCommState(*(HANDLE *)(local_28 + 8),&local_20);
      }
    }
  }
  return local_24;
}



// Function: FUN_6f66236a at 6f66236a

int __thiscall FUN_6f66236a(void *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_6f6624a0(param_1);
  *(undefined4 *)((int)this + 4) = uVar1;
  return (int)this;
}



// Function: FUN_6f662388 at 6f662388

void FUN_6f662388(void)

{
  return;
}



// Function: FUN_6f662393 at 6f662393

void __fastcall FUN_6f662393(LPDWORD param_1)

{
  BOOL BVar1;
  
  BVar1 = GetCommModemStatus(*(HANDLE *)(param_1[1] + 8),param_1);
  if (BVar1 == 0) {
    *param_1 = 0;
  }
  return;
}



// Function: FUN_6f6623bf at 6f6623bf

bool __fastcall FUN_6f6623bf(uint *param_1)

{
  return (*param_1 & 0x10) != 0;
}



// Function: FUN_6f6623d8 at 6f6623d8

void FUN_6f6623d8(void)

{
  return;
}



// Function: FUN_6f6623f0 at 6f6623f0

undefined4 * __thiscall FUN_6f6623f0(void *this,uint param_1)

{
  FUN_6f661ee2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_6f662420 at 6f662420

undefined4 * __thiscall FUN_6f662420(void *this,uint param_1)

{
  FUN_6f662127((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_6f662450 at 6f662450

undefined4 * __fastcall FUN_6f662450(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_6f6640fc;
  return param_1;
}



// Function: FUN_6f662470 at 6f662470

undefined4 * __thiscall FUN_6f662470(void *this,uint param_1)

{
  FUN_6f662265((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_6f6624a0 at 6f6624a0

undefined4 __fastcall FUN_6f6624a0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_6f6624c0 at 6f6624c0

undefined4 FUN_6f6624c0(void)

{
  return 1;
}



// Function: FUN_6f6624ca at 6f6624ca

undefined4 FUN_6f6624ca(void)

{
  return 0;
}



// Function: J1708_VERSION at 6f6624d1

undefined2 J1708_VERSION(void)

{
                    /* 0x24d1  3  J1708_VERSION */
  return DAT_6f6650f4;
}



// Function: FUN_6f6624e0 at 6f6624e0

void FUN_6f6624e0(void)

{
  GetTickCount();
  return;
}



// Function: FUN_6f6624eb at 6f6624eb

void FUN_6f6624eb(void)

{
  return;
}



// Function: FUN_6f6624f0 at 6f6624f0

void __cdecl
FUN_6f6624f0(undefined4 *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  
  ftime(&local_10);
  *param_1 = local_10;
  *param_2 = local_c;
  *param_3 = local_a;
  *param_4 = local_8;
  return;
}



// Function: FUN_6f66252d at 6f66252d

void FUN_6f66252d(void)

{
  while (DAT_6f6655b0 != 0) {
    FUN_6f6624eb();
  }
  DAT_6f6655b0 = 1;
  return;
}



// Function: FUN_6f66254d at 6f66254d

void FUN_6f66254d(void)

{
  DAT_6f6655b0 = 0;
  return;
}



// Function: FUN_6f66255b at 6f66255b

undefined4 __cdecl FUN_6f66255b(char *param_1,int *param_2,short param_3)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  int local_328;
  undefined4 local_324;
  char local_320 [264];
  char local_218 [264];
  undefined4 local_110;
  char local_10c [264];
  
  local_110 = 0;
  local_324 = 0;
  if (param_1 != (char *)0x0) {
    local_324 = strlen(param_1);
  }
  while ((0 < (int)local_324 &&
         ((iVar1 = isspace((int)param_1[local_324 - 1]), iVar1 != 0 ||
          (param_1[local_324 - 1] == '\\'))))) {
    local_324 = local_324 - 1;
  }
  while ((0 < (int)local_324 && (iVar1 = isspace((int)*param_1), iVar1 != 0))) {
    param_1 = param_1 + 1;
    local_324 = local_324 - 1;
  }
  if (local_324 == 0) {
    param_1 = &DAT_6f6650f8;
    local_324 = 1;
  }
  else {
    strncpy(local_218,param_1,local_324);
    param_1 = local_218;
    local_218[local_324] = '\0';
  }
  if (param_1[1] == ':') {
    local_328 = toupper((int)*param_1);
    local_328 = local_328 + -0x41;
  }
  else {
    local_328 = _getdrive();
  }
  pcVar2 = _getdcwd(local_328 + 1,local_10c,0x104);
  if (pcVar2 == (char *)0x0) {
    local_110 = 0x1b;
  }
  else {
    iVar1 = _chdir(param_1);
    if (iVar1 == 0) {
      pcVar2 = _getdcwd(local_328 + 1,local_320,0x104);
      if (pcVar2 == (char *)0x0) {
        local_110 = 0x1a;
      }
      else {
        local_324 = strlen(local_320);
        if (local_320[local_324 - 1] != '\\') {
          local_320[local_324] = '\\';
          local_320[local_324 + 1] = '\0';
          local_324 = local_324 + 1;
        }
        if (*param_2 == 0) {
          pvVar3 = operator_new(local_324 + 1);
          *param_2 = (int)pvVar3;
          if (*param_2 == 0) {
            local_110 = 2;
          }
          else {
            strcpy((char *)*param_2,local_320);
          }
        }
        else if ((int)param_3 < (int)local_324) {
          local_110 = 9;
        }
        else {
          strcpy((char *)*param_2,local_320);
        }
      }
      _chdir(local_10c);
    }
    else {
      local_110 = 0x1b;
    }
  }
  return local_110;
}



// Function: FUN_6f662806 at 6f662806

void FUN_6f662806(void)

{
  _getpid();
  return;
}



// Function: FUN_6f662811 at 6f662811

uint __cdecl FUN_6f662811(short param_1)

{
  uint uVar1;
  
  uVar1 = _close((int)param_1);
  return uVar1;
}



// Function: FUN_6f66282e at 6f66282e

void __cdecl FUN_6f66282e(short param_1)

{
  _eof((int)param_1);
  return;
}



// Function: FUN_6f662841 at 6f662841

undefined2 __cdecl FUN_6f662841(char *param_1,ushort param_2)

{
  undefined2 uVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  
  if ((param_2 & 0x4000) == 0) {
    uVar3 = 0x8000;
  }
  else {
    uVar3 = 0x4000;
  }
  if ((param_2 & 0x200) != 0) {
    param_2 = param_2 | 0x100;
    uVar3 = uVar3 | 0x200;
  }
  if ((param_2 & 0x800) != 0) {
    uVar3 = uVar3 | 8;
  }
  if ((param_2 & 0x100) == 0) {
    if ((param_2 & 1) == 0) {
      if ((param_2 & 2) == 0) {
        if ((param_2 & 4) != 0) {
          uVar3 = uVar3 | 2;
        }
      }
      else {
        uVar3 = uVar3 | 1;
      }
    }
    iVar2 = _sopen(param_1,(int)(short)uVar3,0x20,uVar3,0xffff,0);
    uVar1 = (undefined2)iVar2;
  }
  else {
    if ((param_2 & 1) == 0) {
      if ((param_2 & 2) == 0) {
        sVar4 = 0x180;
      }
      else {
        sVar4 = 0x80;
      }
    }
    else {
      sVar4 = 0x100;
    }
    iVar2 = _sopen(param_1,(int)(short)(uVar3 | 0x102),0x20,(int)sVar4);
    uVar1 = (undefined2)iVar2;
  }
  return uVar1;
}



// Function: FUN_6f662982 at 6f662982

long __cdecl FUN_6f662982(short param_1)

{
  long lVar1;
  
  lVar1 = _lseek((int)param_1,0,1);
  return lVar1;
}



// Function: FUN_6f6629a2 at 6f6629a2

uint __cdecl FUN_6f6629a2(short param_1,void *param_2,short param_3)

{
  uint uVar1;
  
  uVar1 = _read((int)param_1,param_2,(int)param_3);
  return uVar1;
}



// Function: FUN_6f6629c9 at 6f6629c9

int __cdecl FUN_6f6629c9(short param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_8;
  
  local_c = 0;
  local_8 = 0x7fff;
  while (local_8 == 0x7fff) {
    if ((int)param_3 < 0x7fff) {
      local_10 = param_3;
    }
    else {
      local_10 = 0x7fff;
    }
    iVar1 = _read((int)param_1,param_2,local_10);
    local_8 = (short)iVar1;
    param_2 = (void *)((int)param_2 + (int)local_8);
    param_3 = param_3 - (int)local_8;
    local_c = local_c + local_8;
  }
  if (local_8 == -1) {
    local_c = -1;
  }
  return local_c;
}



// Function: FUN_6f662a56 at 6f662a56

long __cdecl FUN_6f662a56(short param_1,long param_2,short param_3)

{
  long lVar1;
  
  lVar1 = _lseek((int)param_1,param_2,(int)param_3);
  return lVar1;
}



// Function: FUN_6f662a7b at 6f662a7b

void __cdecl FUN_6f662a7b(short param_1)

{
  _filelength((int)param_1);
  return;
}



// Function: FUN_6f662a8e at 6f662a8e

void __cdecl FUN_6f662a8e(char *param_1)

{
  _unlink(param_1);
  return;
}



// Function: FUN_6f662aa0 at 6f662aa0

uint __cdecl FUN_6f662aa0(short param_1,void *param_2,short param_3)

{
  uint uVar1;
  
  uVar1 = _write((int)param_1,param_2,(int)param_3);
  return uVar1;
}



// Function: FUN_6f662ac7 at 6f662ac7

int __cdecl FUN_6f662ac7(short param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_8;
  
  local_c = 0;
  local_8 = 0x7fff;
  while (local_8 == 0x7fff) {
    if ((int)param_3 < 0x7fff) {
      local_10 = param_3;
    }
    else {
      local_10 = 0x7fff;
    }
    iVar1 = _write((int)param_1,param_2,local_10);
    local_8 = (short)iVar1;
    param_2 = (void *)((int)param_2 + (int)local_8);
    param_3 = param_3 - (int)local_8;
    local_c = local_c + local_8;
  }
  if (local_8 == -1) {
    local_c = -1;
  }
  return local_c;
}



// Function: FUN_6f662b54 at 6f662b54

undefined4 __cdecl FUN_6f662b54(short param_1)

{
  int iVar1;
  undefined1 local_2c [28];
  undefined4 local_10;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = fstat((int)param_1,local_2c);
  if (iVar1 == 0) {
    local_8 = local_10;
  }
  return local_8;
}



// Function: FUN_6f662b90 at 6f662b90

undefined4 __fastcall FUN_6f662b90(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_6f662b9e at 6f662b9e

void FUN_6f662b9e(void)

{
  return;
}



// Function: FUN_6f662ba9 at 6f662ba9

void __thiscall FUN_6f662ba9(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return;
}



// Function: FUN_6f662be6 at 6f662be6

undefined4 __fastcall FUN_6f662be6(int *param_1)

{
  undefined4 local_c;
  
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}



// Function: FUN_6f662c17 at 6f662c17

void __thiscall FUN_6f662c17(void *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_6f662be6((int *)this);
  if (iVar1 == 0) {
    *(int *)this = param_1;
    *(int *)((int)this + 4) = param_2;
  }
  return;
}



// Function: FUN_6f662c41 at 6f662c41

uint __thiscall FUN_6f662c41(void *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_6f662be6((int *)this);
  if (uVar1 != 0) {
    *(int *)((int)this + 8) = param_1;
    *(int *)((int)this + 0xc) = param_2;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    uVar2 = (*(int *)((int)this + 4) - *this) + *(int *)((int)this + 0x10);
    uVar1 = uVar2 / *(uint *)((int)this + 0x10);
    if (uVar2 % *(uint *)((int)this + 0x10) <
        (uint)((param_2 - *this) + *(int *)((int)this + 0x10)) % *(uint *)((int)this + 0x10)) {
      *(int *)((int)this + 4) = param_2;
    }
  }
  return uVar1;
}



// Function: FUN_6f662cae at 6f662cae

undefined4 __thiscall FUN_6f662cae(void *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  
  iVar2 = FUN_6f662be6((int *)this);
                    /* WARNING: Load size is inaccurate */
  if ((iVar2 == 0) ||
     ((uint)((*(int *)((int)this + 8) - *this) + *(int *)((int)this + 0x10)) %
      *(uint *)((int)this + 0x10) <
      (uint)((*(int *)((int)this + 8) - param_1) + *(int *)((int)this + 0x10)) %
      *(uint *)((int)this + 0x10))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (param_1 == *(int *)((int)this + 8)) {
    if ((bVar1) &&
       ((uint)((param_2 - *(int *)((int)this + 8)) + *(int *)((int)this + 0x10)) %
        *(uint *)((int)this + 0x10) <=
        (uint)((*(int *)((int)this + 0xc) - *(int *)((int)this + 8)) + *(int *)((int)this + 0x10)) %
        *(uint *)((int)this + 0x10))) {
      local_14 = 1;
    }
    else {
      local_14 = 0;
    }
    local_8 = local_14;
  }
  else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if ((bVar1) &&
       ((uint)((param_2 - *this) + *(int *)((int)this + 0x10)) % *(uint *)((int)this + 0x10) <=
        (uint)((*(int *)((int)this + 4) - *this) + *(int *)((int)this + 0x10)) %
        *(uint *)((int)this + 0x10))) {
      local_18 = 1;
    }
    else {
      local_18 = 0;
    }
    local_8 = local_18;
  }
  return local_8;
}



// Function: FUN_6f662dd0 at 6f662dd0

undefined4 * __thiscall FUN_6f662dd0(void *this,undefined4 param_1)

{
  FILE *pFVar1;
  
  FUN_6f661ec0(this,param_1);
  pFVar1 = fopen("d:\\temp\\datafile.txt",&DAT_6f665118);
  *(FILE **)((int)this + 8) = pFVar1;
  pFVar1 = fopen("d:\\temp\\unittest.log",&DAT_6f66511c);
  *(FILE **)((int)this + 0xc) = pFVar1;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x11c) = 0;
  *(undefined4 *)((int)this + 0x120) = 0;
  *(undefined ***)this = &PTR_FUN_6f664144;
  if (*(int *)((int)this + 0xc) != 0) {
    fprintf(*(FILE **)((int)this + 0xc),s_Simulated_Serial_Port_created_6f665120);
    if (*(int *)((int)this + 8) == 0) {
      fprintf(*(FILE **)((int)this + 0xc),s_No_data_file_was_found_at__s_6f665140,
              "d:\\temp\\datafile.txt");
    }
    fflush(*(FILE **)((int)this + 0xc));
  }
  return (undefined4 *)this;
}



// Function: FUN_6f662eb2 at 6f662eb2

void __fastcall FUN_6f662eb2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_6f664144;
  if (param_1[3] != 0) {
    fprintf((FILE *)param_1[3],s_Simulated_Serial_Port_destroyed_6f665160);
    fclose((FILE *)param_1[3]);
    fclose((FILE *)param_1[2]);
  }
  FUN_6f661ee2(param_1);
  return;
}



// Function: FUN_6f662f0e at 6f662f0e

void __thiscall FUN_6f662f0e(void *this,void *param_1,size_t param_2)

{
  fprintf(*(FILE **)((int)this + 0xc),s_Message_to_be_echoed_is__d_bytes_6f665184,param_2);
  memcpy((void *)((int)this + 0x1c),param_1,param_2);
  *(size_t *)((int)this + 0x11c) = param_2;
  *(undefined4 *)((int)this + 0x120) = 0;
  *(undefined4 *)((int)this + 0x14) = 1;
  return;
}



// Function: FUN_6f662f6e at 6f662f6e

uint __fastcall FUN_6f662f6e(int param_1)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = -1;
  if ((*(int *)(param_1 + 0x11c) == 0) || (*(uint *)(param_1 + 0x11c) <= *(uint *)(param_1 + 0x120))
     ) {
    if ((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x14) == 0)) {
      local_8 = 0xffffffff;
    }
    else {
      if (*(int *)(param_1 + 8) != 0) {
        do {
          local_8 = fgetc(*(FILE **)(param_1 + 8));
          if (local_8 == -1) break;
          iVar1 = isspace(local_8);
        } while (iVar1 != 0);
        if (local_8 != -1) {
          do {
            iVar1 = tolower(local_8);
            if ((iVar1 < 0x30) || (0x39 < iVar1)) {
              if ((iVar1 < 0x61) || (0x66 < iVar1)) {
                fprintf(*(FILE **)(param_1 + 0xc),s_Answer_sent_6f6651a8,local_c);
                *(undefined4 *)(param_1 + 0x14) = 0;
                return 0xffffffff;
              }
              bVar2 = (byte)(local_c << 4) | (char)iVar1 + 0x9fU;
            }
            else {
              bVar2 = (byte)(local_c << 4) | (char)iVar1 - 0x30U;
            }
            local_c = (uint)bVar2;
            local_8 = fgetc(*(FILE **)(param_1 + 8));
          } while ((local_8 != -1) && (iVar1 = isspace(local_8), iVar1 == 0));
        }
        if (local_8 == -1) {
          if (*(int *)(param_1 + 0x10) == 0) {
            *(undefined4 *)(param_1 + 0x10) = 1;
            fprintf(*(FILE **)(param_1 + 0xc),s_EOF_found_in_data_stream_in__s_6f6651c0,
                    "d:\\temp\\datafile.txt");
            fprintf(*(FILE **)(param_1 + 0xc),s_There_were__lu_data_bytes_retrie_6f6651e4,
                    *(undefined4 *)(param_1 + 0x18));
          }
        }
        else {
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
          fprintf(*(FILE **)(param_1 + 0xc),s__02hx_6f6651b8,local_c);
        }
      }
      fflush(*(FILE **)(param_1 + 0xc));
      bVar3 = local_8 == -1;
      local_8 = local_c;
      if (bVar3) {
        local_8 = 0xffffffff;
      }
    }
  }
  else {
    local_8 = (uint)*(byte *)(param_1 + 0x1c + *(int *)(param_1 + 0x120));
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + 1;
    if (*(int *)(param_1 + 0x120) == *(int *)(param_1 + 0x11c)) {
      *(undefined4 *)(param_1 + 0x11c) = 0;
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
  }
  return local_8;
}



// Function: FUN_6f6631d0 at 6f6631d0

undefined4 * __thiscall FUN_6f6631d0(void *this,uint param_1)

{
  FUN_6f662eb2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_6f6631fe at 6f6631fe

void __cdecl FUN_6f6631fe(_onexit_t param_1)

{
  if (DAT_6f6655c4 == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_6f6655c4,&DAT_6f6655c0);
  return;
}



// Function: FUN_6f66322a at 6f66322a

int __cdecl FUN_6f66322a(_onexit_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_6f6631fe(param_1);
  return (iVar1 != 0) - 1;
}



// Function: FUN_6f663288 at 6f663288

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6f663288(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    if (0 < DAT_6f6655b4) {
      DAT_6f6655b4 = DAT_6f6655b4 + -1;
      goto LAB_6f66329e;
    }
LAB_6f6632c6:
    uVar1 = 0;
  }
  else {
LAB_6f66329e:
    _DAT_6f6655b8 = *(undefined4 *)_adjust_fdiv_exref;
    if (param_2 == 1) {
      DAT_6f6655c4 = (undefined4 *)malloc(0x80);
      if (DAT_6f6655c4 == (undefined4 *)0x0) goto LAB_6f6632c6;
      *DAT_6f6655c4 = 0;
      DAT_6f6655c0 = DAT_6f6655c4;
      initterm(&DAT_6f665000,&DAT_6f665008);
      DAT_6f6655b4 = DAT_6f6655b4 + 1;
    }
    else if ((param_2 == 0) &&
            (_Memory = DAT_6f6655c4, puVar2 = DAT_6f6655c0, DAT_6f6655c4 != (undefined4 *)0x0)) {
      while (puVar2 = puVar2 + -1, _Memory <= puVar2) {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          _Memory = DAT_6f6655c4;
        }
      }
      free(_Memory);
      DAT_6f6655c4 = (undefined4 *)0x0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



// Function: entry at 6f663333

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_6f6655b4;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_6f66337b;
    if ((DAT_6f6655bc != (code *)0x0) &&
       (iVar2 = (*DAT_6f6655bc)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_6f663288(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_6f66337b:
  iVar2 = FUN_6f6633e2(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_6f663288(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_6f663288(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_6f6655bc != (code *)0x0) {
      iVar2 = (*DAT_6f6655bc)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



// Function: FUN_6f6633e2 at 6f6633e2

undefined4 FUN_6f6633e2(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_6f6655bc == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



// Function: Unwind@6f663410 at 6f663410

void Unwind_6f663410(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@6f66341b at 6f66341b

void Unwind_6f66341b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@6f663426 at 6f663426

void Unwind_6f663426(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@6f663431 at 6f663431

void Unwind_6f663431(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



