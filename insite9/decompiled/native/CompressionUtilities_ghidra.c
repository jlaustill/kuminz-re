/*
 * Decompiled from: CompressionUtilities.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_100020d0 at 100020d0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_100020d0(int param_1)

{
  int iVar1;
  int *local_20 [3];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_100208c6;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffff38;
  ExceptionList = &pvStack_10;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = 2;
  uStack_7 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0xfefefefe;
  *(undefined ***)(param_1 + 0xc) = CCompressEventSink::vftable;
  *(int *)(param_1 + 0x38) = param_1;
  thunk_FUN_10007390((undefined4 *)(param_1 + 0x3c));
  local_8 = 4;
  thunk_FUN_10007390((undefined4 *)(param_1 + 0x4c));
  local_8 = 6;
  *(undefined1 *)(param_1 + 0x5c) = 0;
  Ordinal_8();
  _local_8 = CONCAT31(uStack_7,8);
  local_20[0] = (int *)0x0;
  iVar1 = thunk_FUN_10007030(local_20,(IID *)&DAT_10028cb0,(LPUNKNOWN)0x0,0x17);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    FUN_1001dca0(iVar1);
  }
  local_8 = 9;
  thunk_FUN_10006fc0((void *)(param_1 + 8),(int)local_20[0]);
  _local_8 = CONCAT31(uStack_7,8);
  if (local_20[0] != (int *)0x0) {
    (**(code **)(*local_20[0] + 8))(local_20[0]);
  }
  FUN_100022b8();
  return;
}



// Function: Catch@100022ab at 100022ab

undefined4 Catch_100022ab(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 7;
  return 0x100022bf;
}



// Function: FUN_100022b8 at 100022b8

undefined4 FUN_100022b8(void)

{
  bool bVar1;
  int iVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 7;
  bVar1 = thunk_FUN_10007ba0(0,(int *)(*(int *)(unaff_EBP + -0x90) + 8));
  if (bVar1) {
    *(undefined2 *)(unaff_EBP + -0x18) = 0;
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x90) + 8;
    *(undefined4 *)(unaff_EBP + -0x9c) = *(undefined4 *)(unaff_EBP + -0x54);
    if (**(int **)(unaff_EBP + -0x50) == 0) {
      FUN_1001dca0(0x80004003);
    }
    *(undefined4 *)(unaff_EBP + -0x9c) = **(undefined4 **)(unaff_EBP + -0x50);
    if (DAT_10033e44 == (undefined4 *)0x0) {
      *(undefined4 *)(unaff_EBP + -0xa0) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0xa0) = *DAT_10033e44;
    }
    iVar2 = (**(code **)(**(int **)(unaff_EBP + -0x9c) + 0x1b4))
                      (*(undefined4 *)(unaff_EBP + -0x9c),*(undefined4 *)(unaff_EBP + -0xa0),
                       unaff_EBP + -0x18);
    if ((iVar2 < 0) || (*(short *)(unaff_EBP + -0x18) == 0)) {
      thunk_FUN_100065c0((void *)(*(int *)(unaff_EBP + -0x90) + 8),0);
    }
    else {
      *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xa4) = *(undefined4 *)(unaff_EBP + -0x5c);
      if (**(int **)(unaff_EBP + -0x58) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xa4) = **(undefined4 **)(unaff_EBP + -0x58);
      (**(code **)(**(int **)(unaff_EBP + -0xa4) + 0x1fc))
                (*(undefined4 *)(unaff_EBP + -0xa4),0x18014);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(*(int *)(unaff_EBP + -0x90) + 8);
      thunk_FUN_10008960((void *)(*(int *)(unaff_EBP + -0x90) + 0xc),
                         *(undefined4 **)(unaff_EBP + -0x60),&DAT_10028c4c);
      thunk_FUN_10003ce0(*(int *)(unaff_EBP + -0x90),6);
      *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(unaff_EBP + -0x68);
      if (**(int **)(unaff_EBP + -100) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xa8) = **(undefined4 **)(unaff_EBP + -100);
      (**(code **)(**(int **)(unaff_EBP + -0xa8) + 0x1e4))(*(undefined4 *)(unaff_EBP + -0xa8),0);
      *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xac) = *(undefined4 *)(unaff_EBP + -0x70);
      if (**(int **)(unaff_EBP + -0x6c) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xac) = **(undefined4 **)(unaff_EBP + -0x6c);
      (**(code **)(**(int **)(unaff_EBP + -0xac) + 0xdc))(*(undefined4 *)(unaff_EBP + -0xac),0);
      *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xb0) = *(undefined4 *)(unaff_EBP + -0x78);
      if (**(int **)(unaff_EBP + -0x74) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xb0) = **(undefined4 **)(unaff_EBP + -0x74);
      (**(code **)(**(int **)(unaff_EBP + -0xb0) + 0x218))(*(undefined4 *)(unaff_EBP + -0xb0),8);
      *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xb4) = *(undefined4 *)(unaff_EBP + -0x80);
      if (**(int **)(unaff_EBP + -0x7c) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xb4) = **(undefined4 **)(unaff_EBP + -0x7c);
      (**(code **)(**(int **)(unaff_EBP + -0xb4) + 0x88))
                (*(undefined4 *)(unaff_EBP + -0xb4),0xffffffff);
      *(int *)(unaff_EBP + -0x84) = *(int *)(unaff_EBP + -0x90) + 8;
      *(undefined4 *)(unaff_EBP + -0xb8) = *(undefined4 *)(unaff_EBP + -0x88);
      if (**(int **)(unaff_EBP + -0x84) == 0) {
        FUN_1001dca0(0x80004003);
      }
      *(undefined4 *)(unaff_EBP + -0xb8) = **(undefined4 **)(unaff_EBP + -0x84);
      (**(code **)(**(int **)(unaff_EBP + -0xb8) + 0x90))
                (*(undefined4 *)(unaff_EBP + -0xb8),0xffffffff);
      DAT_100326f0 = 1;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x90);
}



// Function: FUN_100026e0 at 100026e0

void __fastcall FUN_100026e0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10002700 at 10002700

void __fastcall FUN_10002700(int param_1)

{
  bool bVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10020942;
  local_10 = ExceptionList;
  local_8 = 4;
  ExceptionList = &local_10;
  bVar1 = thunk_FUN_10007ba0(0,(int *)(param_1 + 8));
  if (bVar1) {
    thunk_FUN_100085a0(*(undefined4 **)(param_1 + 8),&DAT_10028c4c,*(undefined4 *)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x34) = 0xfefefefe;
  }
  local_8._0_1_ = 3;
  Ordinal_9(param_1 + 0x60);
  local_8._0_1_ = 5;
  thunk_FUN_100072c0((_Container_base0 *)(param_1 + 0x4c));
  local_8._0_1_ = 6;
  thunk_FUN_100072c0((_Container_base0 *)(param_1 + 0x3c));
  local_8 = (uint)local_8._1_3_ << 8;
  piVar2 = (int *)(param_1 + 8);
  if (*piVar2 != 0) {
    (**(code **)(*(int *)*piVar2 + 8))(*piVar2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002850 at 10002850

undefined4 FUN_10002850(void)

{
  return 0;
}



// Function: FUN_10002860 at 10002860

undefined4 FUN_10002860(int param_1,int param_2)

{
  undefined4 uVar1;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020978;
  local_10 = ExceptionList;
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    ExceptionList = &local_10;
    thunk_FUN_10008b20(&local_14,param_2);
    local_8 = 0;
    thunk_FUN_100067f0((void *)(param_1 + 0x3c),(int *)&local_14);
    local_8 = 0xffffffff;
    if (local_14 != (void *)0x0) {
      thunk_FUN_10008d20(local_14);
    }
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10002900 at 10002900

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_10002900(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int local_80;
  void *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100209a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = thunk_FUN_10007bf0(0,param_1 + 2);
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else {
    local_14 = 0;
    if (param_1[0x10] - param_1[0xf] >> 2 == 0) {
      local_14 = -0x7fffbffb;
    }
    else {
      bVar1 = thunk_FUN_10005a90(param_1);
      if (bVar1) {
        if (param_1[2] == 0) {
          FUN_1001dca0(0x80004003);
        }
        local_14 = (**(code **)(*(int *)param_1[2] + 0x50))();
        if (local_14 < 0) {
          local_14 = -0x7fffbffb;
        }
        else {
          for (local_18 = (int *)param_1[0xf];
              (-1 < local_14 && (local_20 = (int *)param_1[0x10], local_18 != local_20));
              local_18 = local_18 + 1) {
            if (param_1[2] == 0) {
              FUN_1001dca0(0x80004003);
            }
            piVar3 = (int *)param_1[2];
            if (*local_18 == 0) {
              local_80 = 0;
            }
            else {
              local_80 = *(int *)*local_18;
            }
            thunk_FUN_10014b20((int *)&local_24,local_80);
            local_8 = 0;
            local_14 = (**(code **)(*piVar3 + 0x168))();
            local_8 = 0xffffffff;
            if (local_24 != (void *)0x0) {
              thunk_FUN_10008d20(local_24);
              local_24 = (void *)0x0;
            }
          }
        }
      }
      else {
        local_14 = -0x7fffbffb;
      }
    }
    if (-1 < local_14) {
      if (param_1[2] == 0) {
        FUN_1001dca0(0x80004003);
      }
      local_14 = (**(code **)(*(int *)param_1[2] + 0x178))();
      piVar3 = (int *)param_1[2];
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      local_8 = 0xffffffff;
      local_14 = FUN_10005d50(local_14,local_1c,piVar3);
    }
    uVar2 = (-1 < local_14) - 1 & 0x80004005;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10002cc0 at 10002cc0

/* WARNING: Removing unreachable block (ram,0x10003062) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_10002cc0(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100209b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = thunk_FUN_10007bf0(0,param_1 + 2);
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_2 = 1;
    thunk_FUN_10006900(param_1 + 0x13);
    bVar1 = thunk_FUN_10005a90(param_1);
    if (bVar1) {
      bVar1 = thunk_FUN_10005bf0(param_1);
      if (bVar1) {
        if (param_1[2] == 0) {
          FUN_1001dca0(0x80004003);
        }
        local_14 = (**(code **)(*(int *)param_1[2] + 0x50))();
        if (local_14 < 0) {
          local_14 = -0x7fffbffb;
        }
        else if (param_1[0x10] - param_1[0xf] >> 2 == 0) {
          if (param_1[2] == 0) {
            FUN_1001dca0(0x80004003);
          }
          local_14 = (**(code **)(*(int *)param_1[2] + 0x168))();
        }
        else {
          for (local_18 = param_1[0xf]; (-1 < local_14 && (local_18 != param_1[0x10]));
              local_18 = local_18 + 4) {
            if (param_1[2] == 0) {
              FUN_1001dca0(0x80004003);
            }
            local_14 = (**(code **)(*(int *)param_1[2] + 0x168))();
          }
        }
      }
      else {
        local_14 = -0x7fffbffb;
      }
    }
    else {
      local_14 = -0x7fffbffb;
    }
    if (-1 < local_14) {
      if (((char)param_1[0x17] == '\0') || (iVar3 = thunk_FUN_10005180((int)param_1), iVar3 == 1)) {
        if (param_1[2] == 0) {
          FUN_1001dca0(0x80004003);
        }
        iVar3 = (**(code **)(*(int *)param_1[2] + 0x17c))();
        if (iVar3 < 0) {
          local_14 = -0x7fffbffb;
        }
        else {
          piVar4 = (int *)param_1[2];
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 4))(piVar4);
          }
          local_8 = 0xffffffff;
          local_14 = FUN_10005d50(iVar3,0,piVar4);
          if (local_14 < 0) {
            local_14 = -0x7fffbffb;
          }
          else {
            *param_2 = 0;
            (**(code **)(*param_1 + 0x60))(param_1);
          }
        }
      }
      else {
        local_14 = -0x7fffbffb;
      }
    }
    uVar2 = (-1 < local_14) - 1 & 0x80004005;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10003180 at 10003180

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_10003180(int *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  void *local_20;
  char local_19;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100209e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = thunk_FUN_10007bf0(0,param_1 + 2);
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    local_14 = 0;
    local_18 = 0;
    bVar1 = thunk_FUN_10005a90(param_1);
    if (bVar1) {
      if (param_1[2] == 0) {
        FUN_1001dca0(0x80004003);
      }
      local_14 = (**(code **)(*(int *)param_1[2] + 0x50))();
      if (local_14 < 0) {
        local_14 = -0x7fffbffb;
      }
      else {
        if (param_1[2] == 0) {
          FUN_1001dca0(0x80004003);
        }
        piVar3 = (int *)param_1[2];
        thunk_FUN_10014b20((int *)&local_20,param_2);
        local_8 = 0;
        local_14 = (**(code **)(*piVar3 + 0x168))();
        local_19 = local_14 < 0;
        local_8 = 0xffffffff;
        if (local_20 != (void *)0x0) {
          thunk_FUN_10008d20(local_20);
          local_20 = (void *)0x0;
        }
        if (local_19 == '\0') {
          if (param_1[2] == 0) {
            FUN_1001dca0(0x80004003);
          }
          local_14 = (**(code **)(*(int *)param_1[2] + 0x178))();
          if (local_14 < 0) {
            local_14 = -0x7fffbffb;
          }
          else {
            piVar3 = (int *)param_1[2];
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 4))(piVar3);
            }
            local_8 = 0xffffffff;
            local_14 = FUN_10005d50(local_14,local_18,piVar3);
            if (local_14 < 0) {
              local_14 = -0x7fffbffb;
            }
          }
        }
        else {
          local_14 = -0x7fffbffb;
        }
      }
    }
    else {
      local_14 = -0x7fffbffb;
    }
    uVar2 = (-1 < local_14) - 1 & 0x80004005;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100034a0 at 100034a0

/* WARNING: Removing unreachable block (ram,0x100036e3) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_100034a0(int *param_1,int param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100209f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = thunk_FUN_10007bf0(0,param_1 + 2);
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == 0) {
    uVar2 = 0x80004003;
  }
  else if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_3 = 1;
    thunk_FUN_10006900(param_1 + 0x13);
    bVar1 = thunk_FUN_10005a90(param_1);
    if (bVar1) {
      if (param_1[2] == 0) {
        FUN_1001dca0(0x80004003);
      }
      iVar3 = (**(code **)(*(int *)param_1[2] + 0x50))();
      if (iVar3 < 0) {
        local_14 = -0x7fffbffb;
      }
      else {
        if (param_1[2] == 0) {
          FUN_1001dca0(0x80004003);
        }
        iVar3 = (**(code **)(*(int *)param_1[2] + 0x168))();
        if (iVar3 < 0) {
          local_14 = -0x7fffbffb;
        }
        else {
          if (param_1[2] == 0) {
            FUN_1001dca0(0x80004003);
          }
          iVar3 = (**(code **)(*(int *)param_1[2] + 0x17c))();
          if (iVar3 < 0) {
            local_14 = -0x7fffbffb;
          }
          else {
            piVar4 = (int *)param_1[2];
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 4))(piVar4);
            }
            local_8 = 0xffffffff;
            local_14 = FUN_10005d50(iVar3,0,piVar4);
            if (local_14 < 0) {
              local_14 = -0x7fffbffb;
            }
            else {
              *param_3 = 0;
              (**(code **)(*param_1 + 0x60))(param_1);
            }
          }
        }
      }
    }
    else {
      local_14 = -0x7fffbffb;
    }
    uVar2 = (-1 < local_14) - 1 & 0x80004005;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100037b0 at 100037b0

uint FUN_100037b0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 local_8;
  
  if (param_2 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_8 = (-(uint)(*(char *)(param_1 + 0x5c) != '\0') & 0x7fffbffb) + 0x80004005;
    if (-1 < local_8) {
      local_8 = Ordinal_10(param_2,param_1 + 0x60);
    }
    uVar1 = (-1 < local_8) - 1 & 0x80004005;
  }
  return uVar1;
}



// Function: FUN_10003820 at 10003820

int FUN_10003820(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    bVar1 = thunk_FUN_100056c0((int *)(param_1 + 0x4c),param_2);
    iVar2 = (-(uint)bVar1 & 0x7fffbffb) + 0x80004005;
  }
  return iVar2;
}



// Function: FUN_10003870 at 10003870

uint FUN_10003870(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xcc))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003910 at 10003910

uint FUN_10003910(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xd0))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_100039b0 at 100039b0

int FUN_100039b0(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar1) {
    iVar2 = -0x7fff0001;
  }
  else if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    bVar1 = thunk_FUN_100056c0((int *)(param_1 + 0x3c),param_2);
    iVar2 = (-(uint)bVar1 & 0x7fffbffb) + 0x80004005;
  }
  return iVar2;
}



// Function: FUN_10003a20 at 10003a20

undefined4 FUN_10003a20(void *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  bVar1 = thunk_FUN_10007bf0(0,(int *)((int)param_1 + 8));
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    local_c = *(int **)((int)param_1 + 0x40);
    local_14 = *(int **)((int)param_1 + 0x3c);
    local_10 = local_14;
    local_8 = local_c;
    thunk_FUN_10007130((undefined4 *)((int)param_1 + 0x3c),&local_18,local_14,local_c);
    thunk_FUN_10005830(param_1,param_2,(void *)((int)param_1 + 0x3c));
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10003af0 at 10003af0

uint FUN_10003af0(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xc4))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003b90 at 10003b90

uint FUN_10003b90(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 200))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003c30 at 10003c30

uint FUN_10003c30(int param_1,undefined4 *param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_8;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x2c))(piVar1,&local_8);
    if (-1 < iVar4) {
      *param_2 = local_8;
    }
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003ce0 at 10003ce0

uint FUN_10003ce0(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  undefined4 local_8;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if ((param_2 < 10) && (-1 < param_2)) {
      if (*(int *)(param_1 + 8) == 0) {
        FUN_1001dca0(0x80004003);
      }
      piVar1 = *(int **)(param_1 + 8);
      local_8 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2);
    }
    else {
      local_8 = -0x7fffbffb;
    }
    uVar3 = (-1 < local_8) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003da0 at 10003da0

uint FUN_10003da0(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x34))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003e40 at 10003e40

uint FUN_10003e40(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x38))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003ee0 at 10003ee0

uint FUN_10003ee0(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x1e0))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10003f80 at 10003f80

uint FUN_10003f80(int param_1,short param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x1e4))(piVar1,-(uint)(param_2 != 0));
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10004020 at 10004020

uint FUN_10004020(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xb4))(piVar1,param_2);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_100040c0 at 100040c0

uint FUN_100040c0(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  undefined4 local_8;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    local_8 = (**(code **)(*piVar1 + 0xc0))(piVar1,-(uint)(param_2 != 0));
    if (param_2 != 0) {
      if (*(int *)(param_1 + 8) == 0) {
        FUN_1001dca0(0x80004003);
      }
      piVar1 = *(int **)(param_1 + 8);
      local_8 = (**(code **)(*piVar1 + 0xb8))(piVar1,param_2);
    }
    uVar3 = (-1 < local_8) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_100041c0 at 100041c0

undefined4 FUN_100041c0(int param_1,short *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_2 == (short *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x5c);
    *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_100041f0 at 100041f0

undefined4 FUN_100041f0(int param_1,short param_2)

{
  *(bool *)(param_1 + 0x5c) = param_2 != 0;
  return 0;
}



// Function: FUN_10004210 at 10004210

uint FUN_10004210(int param_1,short *param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int local_8;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else if (param_2 == (short *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    local_8 = 0;
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xd8))(piVar1,&local_8);
    if (-1 < iVar4) {
      *param_2 = -(ushort)(local_8 != 0);
    }
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_100042e0 at 100042e0

uint FUN_100042e0(int param_1,short param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0xdc))(piVar1,param_2 != 0);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  return uVar3;
}



// Function: FUN_10004390 at 10004390

undefined4 FUN_10004390(int param_1,undefined4 *param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined1 local_8 [4];
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    (**(code **)(*piVar1 + 0x214))(piVar1,local_8);
    *param_2 = 0;
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_10004430 at 10004430

uint FUN_10004430(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar2) {
    uVar3 = 0x8000ffff;
  }
  else if (param_2 == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      FUN_1001dca0(0x80004003);
    }
    piVar1 = *(int **)(param_1 + 8);
    iVar4 = (**(code **)(*piVar1 + 0x218))(piVar1,8);
    uVar3 = (-1 < iVar4) - 1 & 0x80004005;
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}



// Function: FUN_100044e0 at 100044e0

/* WARNING: Removing unreachable block (ram,0x1000459b) */

undefined4 FUN_100044e0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_60;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020a18;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffff94;
  ExceptionList = &pvStack_10;
  bVar1 = thunk_FUN_10007bf0(0,(int *)(param_1 + 8));
  if (bVar1) {
    uVar2 = 0x8000ffff;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      thunk_FUN_10006900((undefined4 *)(param_1 + 0x4c));
      local_18 = 0;
      local_8 = 1;
      iVar3 = thunk_FUN_10005180(param_1);
      if (iVar3 == 1) {
        if (**(int **)(param_1 + 0x4c) == 0) {
          local_60 = 0;
        }
        else {
          local_60 = thunk_FUN_10008e00((int *)**(int **)(param_1 + 0x4c));
        }
        thunk_FUN_100046a0(&local_18,local_60);
        uVar2 = local_18;
        local_18 = 0;
        *param_2 = uVar2;
      }
      uVar2 = FUN_100045f7();
      return uVar2;
    }
    uVar2 = 0x80004003;
  }
  ExceptionList = pvStack_10;
  return uVar2;
}



// Function: Catch@100045dd at 100045dd

undefined * Catch_100045dd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10004600;
}



// Function: FUN_100045f7 at 100045f7

undefined4 FUN_100045f7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x20);
}



// Function: FUN_100046a0 at 100046a0

int * __thiscall FUN_100046a0(void *this,int param_1)

{
  undefined4 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    if (param_1 == 0) {
      *(undefined4 *)this = 0;
    }
    else {
      uVar1 = Ordinal_2(param_1);
      *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
      if (*this == 0) {
        thunk_FUN_10004720(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_10004720 at 10004720

void FUN_10004720(undefined4 param_1)

{
  undefined4 local_8;
  
  local_8 = param_1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_1002df84);
}



// Function: FUN_10004750 at 10004750

void __fastcall FUN_10004750(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10004770 at 10004770

/* WARNING: Removing unreachable block (ram,0x10004960) */
/* WARNING: Removing unreachable block (ram,0x1000497e) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffedc : 0x1000487c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_10004770(undefined4 param_1,undefined2 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int *piVar3;
  IUnknown *ppvObject;
  void **ppvObject_00;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  IID *local_114;
  undefined1 local_fc [12];
  ULONG local_f0;
  IUnknown *local_ec;
  IUnknown *local_e8;
  ULONG local_d8;
  IUnknown *local_d4;
  HRESULT local_d0;
  IUnknown *local_cc;
  IID *local_c8;
  undefined4 local_c4;
  undefined4 *local_c0;
  HRESULT local_bc;
  void **local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  HRESULT local_a8;
  IID *local_a4;
  undefined4 **local_a0;
  undefined4 *local_9c;
  void **local_98;
  int local_94;
  char *local_90;
  DWORD local_8c;
  int *local_7c;
  undefined1 *local_78;
  void *local_74;
  char *local_70;
  DWORD local_6c;
  undefined2 local_54 [4];
  undefined4 local_4c;
  void **local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_30;
  undefined1 *local_2c;
  int *local_28;
  IUnknown *local_24;
  IID *local_20;
  IUnknown *local_1c;
  ulong local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020aa2;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xfffffee0;
  ExceptionList = &pvStack_10;
  puVar1 = &stack0xfffffee0;
  if ((DAT_10033e34 & 1) == 0) {
    DAT_10033e34 = DAT_10033e34 | 1;
    local_8 = 0;
    ExceptionList = &pvStack_10;
    thunk_FUN_10008b20(&DAT_10033e30,0x10028e18);
    _atexit(FUN_100255b0);
    puVar1 = local_14;
  }
  local_14 = puVar1;
  if ((DAT_10033e34 & 2) == 0) {
    DAT_10033e34 = DAT_10033e34 | 2;
    local_8 = 1;
    thunk_FUN_10008b20(&DAT_10033e2c,0x10028da8);
    _atexit(FUN_10025570);
  }
  local_8 = 2;
  local_70 = "Cummins.MsgManager.1";
  local_28 = (int *)0x0;
  local_6c = thunk_FUN_100073e0("Cummins.MsgManager.1",(LPUNKNOWN)0x0,0x17);
  if (((int)local_6c < 0) && (local_6c != 0x80004002)) {
    FUN_1001dca0(local_6c);
  }
  local_8._0_1_ = 3;
  local_2c = &stack0xfffffedc;
  local_78 = &stack0xfffffedc;
  pvVar7 = DAT_10033e2c;
  puVar1 = &stack0xfffffedc;
  puVar2 = &stack0xfffffedc;
  if (DAT_10033e2c != (void *)0x0) {
    local_74 = DAT_10033e2c;
    InterlockedIncrement((LONG *)((int)DAT_10033e2c + 8));
    puVar1 = local_78;
    puVar2 = local_2c;
  }
  local_2c = puVar2;
  local_78 = puVar1;
  local_8._0_1_ = 4;
  if (local_28 == (int *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_7c = local_28;
  local_8._0_1_ = 3;
  piVar3 = thunk_FUN_10004ed0(local_28,&local_30,(IID *)0x1,(void **)0x0,100,0x20,pvVar7);
  local_8._0_1_ = 5;
  thunk_FUN_10007c40(&local_24,piVar3);
  local_8 = CONCAT31(local_8._1_3_,7);
  thunk_FUN_10006d50(&local_30);
  local_90 = "Cummins.MsgParams.1";
  local_20 = (IID *)0x0;
  local_8c = thunk_FUN_10006a20("Cummins.MsgParams.1",(LPUNKNOWN)0x0,0x17);
  if (((int)local_8c < 0) && (local_8c != 0x80004002)) {
    FUN_1001dca0(local_8c);
  }
  local_54[0] = 3;
  local_4c = param_1;
  local_98 = (void **)local_54;
  local_8 = CONCAT31(local_8._1_3_,9);
  Ordinal_8();
  local_94 = Ordinal_10(&local_44,local_98);
  if (local_94 < 0) {
    FUN_1001dca0(local_94);
  }
  local_8._0_1_ = 10;
  local_a0 = &local_c0;
  local_c0 = DAT_10033e30;
  if (DAT_10033e30 != (undefined4 *)0x0) {
    local_9c = DAT_10033e30;
    InterlockedIncrement(DAT_10033e30 + 2);
  }
  local_8._0_1_ = 0xb;
  if (local_20 == (IID *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_a4 = local_20;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  local_b8 = local_44;
  local_b4 = local_40;
  local_b0 = local_3c;
  local_ac = local_38;
  if (local_c0 == (undefined4 *)0x0) {
    local_114 = (IID *)0x0;
  }
  else {
    local_114 = (IID *)*local_c0;
  }
  local_a8 = (**(code **)(local_20->Data1 + 0x30))((IUnknown *)local_20,local_114,local_44);
  uVar4 = local_40;
  uVar5 = local_3c;
  uVar6 = local_38;
  if (local_a8 < 0) {
    _com_issue_errorex(local_a8,(IUnknown *)local_a4,(_GUID *)&DAT_10028d90);
    uVar4 = local_40;
    uVar5 = local_3c;
    uVar6 = local_38;
  }
  local_bc = local_a8;
  local_8._0_1_ = 10;
  thunk_FUN_10008c50((int *)&local_c0);
  local_8._0_1_ = 9;
  Ordinal_9(&local_44,uVar4,uVar5,uVar6);
  local_8 = CONCAT31(local_8._1_3_,8);
  ppvObject_00 = (void **)local_54;
  local_c4 = Ordinal_9();
  local_c8 = local_20;
  if (local_24 == (IUnknown *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_cc = local_24;
  local_d0 = (*local_24->lpVtbl[6].QueryInterface)(local_24,local_c8,ppvObject_00);
  if (local_d0 < 0) {
    _com_issue_errorex(local_d0,local_cc,(_GUID *)&DAT_10028d7c);
  }
  if (local_24 == (IUnknown *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_d4 = local_24;
  local_d8 = (*local_24->lpVtbl[4].Release)(local_24);
  if ((int)local_d8 < 0) {
    _com_issue_errorex(local_d8,local_d4,(_GUID *)&DAT_10028d7c);
  }
  thunk_FUN_10007d10(&local_1c,(int *)&local_28);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  local_e8 = local_24;
  if (local_1c == (IUnknown *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_ec = local_1c;
  ppvObject = local_e8;
  local_f0 = (*local_1c->lpVtbl[2].AddRef)(local_1c);
  if ((int)local_f0 < 0) {
    _com_issue_errorex(local_f0,local_ec,(_GUID *)&DAT_10028d68);
  }
  if (local_24 == (IUnknown *)0x0) {
    FUN_1001dca0(0x80004003);
  }
  local_fc._8_4_ = local_24;
  local_fc._4_4_ =
       (*local_24->lpVtbl[7].QueryInterface)(local_24,(IID *)local_fc,&ppvObject->lpVtbl);
  if ((int)local_fc._4_4_ < 0) {
    _com_issue_errorex(local_fc._4_4_,(IUnknown *)local_fc._8_4_,(_GUID *)&DAT_10028d7c);
  }
  local_18 = local_fc._0_4_;
  if (local_fc._0_4_ == 1) {
    *param_2 = 0xffff;
  }
  else {
    *param_2 = 0;
  }
  local_8._0_1_ = 8;
  thunk_FUN_100076b0((int *)&local_1c);
  local_8._0_1_ = 7;
  thunk_FUN_10006cf0((int *)&local_20);
  local_8._0_1_ = 3;
  thunk_FUN_10006d20((int *)&local_24);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  FUN_10004d3a();
  return;
}



// Function: Catch@10004d25 at 10004d25

undefined4 Catch_10004d25(void)

{
  int unaff_EBP;
  
  **(undefined2 **)(unaff_EBP + 0xc) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10004d41;
}



// Function: FUN_10004d3a at 10004d3a

void FUN_10004d3a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10004ed0 at 10004ed0

/* WARNING: Removing unreachable block (ram,0x10004f6d) */
/* WARNING: Removing unreachable block (ram,0x10004f75) */

int * __thiscall
FUN_10004ed0(void *this,int *param_1,IID *param_2,void **param_3,undefined4 param_4,
            undefined4 param_5,void *param_6)

{
  undefined4 local_38;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10020af1;
  local_10 = ExceptionList;
  local_8 = 1;
  local_18 = 0;
  if (param_6 == (void *)0x0) {
    local_38 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    local_38 = *param_6;
  }
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  local_14 = (**(code **)(*this + 0x24))(this,param_2,param_3,param_4,param_5,local_38,&local_18);
  if (local_14 < 0) {
    _com_issue_errorex(local_14,(IUnknown *)this,(_GUID *)&DAT_10028e34);
  }
  *param_1 = local_18;
  local_8 = local_8 & 0xffffff00;
  if (param_6 != (void *)0x0) {
    thunk_FUN_10008d20(param_6);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10005000 at 10005000

void __thiscall FUN_10005000(void *this,undefined4 param_1,undefined4 param_2,int *param_3)

{
  short *in_stack_0000003c;
  undefined4 *in_stack_00000048;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020b18;
  local_10 = ExceptionList;
  if ((in_stack_0000003c != (short *)0x0) && (param_3 != (int *)0x0)) {
    ExceptionList = &local_10;
    if (*(char *)((int)this + 0x5c) != '\0') {
      ExceptionList = &local_10;
      *in_stack_00000048 = 1;
    }
    if (*in_stack_0000003c != -1) {
      thunk_FUN_10008b20(&local_14,*param_3);
      local_8 = 0;
      thunk_FUN_100067f0((void *)((int)this + 0x4c),(int *)&local_14);
      local_8 = 0xffffffff;
      if (local_14 != (void *)0x0) {
        thunk_FUN_10008d20(local_14);
      }
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100050c0 at 100050c0

void __thiscall FUN_100050c0(void *this,undefined4 param_1,undefined4 param_2)

{
  Ordinal_10((int)this + 0x60,param_2);
  return;
}



// Function: FUN_100050f0 at 100050f0

void FUN_100050f0(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0x12d:
  case 0x12e:
  case 0x12f:
  case 0x130:
  case 0x13b:
  case 0x13f:
  case 0x144:
  case 0x145:
  case 0x146:
  case 0x147:
  case 0x148:
    DAT_100326f0 = 0;
    break;
  default:
    DAT_100326f0 = 1;
  }
  return;
}



// Function: FUN_10005180 at 10005180

/* WARNING: Removing unreachable block (ram,0x10005235) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __fastcall FUN_10005180(int param_1)

{
  int iVar1;
  int *piVar2;
  void *local_3c;
  undefined1 local_38 [16];
  int *local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10020b60;
  local_10 = ExceptionList;
  local_18 = -1;
  local_14 = (int *)0x0;
  local_8 = 0;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 8) == 0) {
    ExceptionList = &local_10;
    FUN_1001dca0(0x80004003);
  }
  piVar2 = *(int **)(param_1 + 8);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  local_14 = (int *)0x0;
  iVar1 = (**(code **)(*piVar2 + 0x1c4))();
  if ((iVar1 < 0) || (local_1c != 0)) {
    piVar2 = *(int **)(param_1 + 8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10005ef0(local_1c,piVar2);
  }
  else {
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = (int *)0x0;
    if (local_14 == (int *)0x0) {
      FUN_1001dca0(0x80004003);
    }
    iVar1 = (**(code **)*local_14)(local_14,&DAT_10028e48);
    if (-1 < iVar1) {
      if (local_20 == (int *)0x0) {
        FUN_1001dca0(0x80004003);
      }
      (**(code **)(*local_20 + 0x24))(local_20);
      for (local_24 = 1; local_24 <= local_18; local_24 = local_24 + 1) {
        thunk_FUN_10008e60(local_38,local_24,3);
        local_8._0_1_ = 2;
        if (local_20 == (int *)0x0) {
          FUN_1001dca0(0x80004003);
        }
        thunk_FUN_100055e0(local_20,(int *)&local_28);
        local_8 = CONCAT31(local_8._1_3_,4);
        Ordinal_9();
        if (local_28 == (int *)0x0) {
          FUN_1001dca0(0x80004003);
        }
        piVar2 = thunk_FUN_100054d0(local_28,(int *)&local_3c);
        local_8._0_1_ = 5;
        thunk_FUN_10006680((void *)(param_1 + 0x4c),piVar2);
        local_8._0_1_ = 4;
        if (local_3c != (void *)0x0) {
          thunk_FUN_10008d20(local_3c);
          local_3c = (void *)0x0;
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))();
        }
      }
    }
    local_8 = local_8 & 0xffffff00;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))();
    }
  }
  iVar1 = local_18;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_100054d0 at 100054d0

int * __thiscall FUN_100054d0(void *this,int *param_1)

{
  int iVar1;
  void *this_00;
  int *local_30;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020ba4;
  local_10 = ExceptionList;
  local_18 = 0;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  local_14 = (**(code **)(*this + 0x1c))(this,&local_18);
  if (local_14 < 0) {
    _com_issue_errorex(local_14,(IUnknown *)this,(_GUID *)&DAT_10028e5c);
  }
  iVar1 = local_18;
  this_00 = operator_new(0xc);
  local_8 = 1;
  if (this_00 == (void *)0x0) {
    local_30 = (int *)0x0;
  }
  else {
    local_30 = thunk_FUN_10008c90(this_00,iVar1,'\0');
  }
  local_8 = local_8 & 0xffffff00;
  *param_1 = (int)local_30;
  if (*param_1 == 0) {
    FUN_1001dca0(0x8007000e);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100055e0 at 100055e0

/* WARNING: Removing unreachable block (ram,0x1000564f) */
/* WARNING: Removing unreachable block (ram,0x10005657) */

int * __thiscall FUN_100055e0(void *this,int *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020bd9;
  local_10 = ExceptionList;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  iVar1 = (**(code **)(*this + 0x20))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10028e48);
  }
  *param_1 = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100056c0 at 100056c0

/* WARNING: Removing unreachable block (ram,0x1000577e) */

bool FUN_100056c0(int *param_1,int *param_2)

{
  int iVar1;
  int local_38;
  int *local_14;
  int local_10;
  int local_c [2];
  
  local_c[0] = param_1[1] - *param_1 >> 2;
  local_c[1] = 0;
  iVar1 = Ordinal_15(8,1,local_c);
  *param_2 = iVar1;
  if (*param_2 != 0) {
    local_10 = 0;
    for (local_14 = (int *)*param_1; local_14 != (int *)param_1[1]; local_14 = local_14 + 1) {
      if (*local_14 == 0) {
        local_38 = 0;
      }
      else {
        local_38 = thunk_FUN_10008e00((int *)*local_14);
      }
      iVar1 = Ordinal_26(*param_2,&local_10,local_38);
      if (iVar1 < 0) {
        Ordinal_16(*param_2);
        *param_2 = 0;
        break;
      }
      local_10 = local_10 + 1;
    }
  }
  return *param_2 != 0;
}



// Function: FUN_10005830 at 10005830

bool __thiscall FUN_10005830(void *this,int param_1,void *param_2)

{
  void *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020bf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = Ordinal_23(param_1,&local_14,this);
  if (-1 < local_18) {
    for (local_1c = 0; local_1c < *(uint *)(param_1 + 0x10); local_1c = local_1c + 1) {
      thunk_FUN_10008b20(&local_20,*(int *)(local_14 + local_1c * 4));
      local_8 = 0;
      thunk_FUN_100067f0(param_2,(int *)&local_20);
      local_8 = 0xffffffff;
      if (local_20 != (void *)0x0) {
        thunk_FUN_10008d20(local_20);
        local_20 = (void *)0x0;
      }
    }
    Ordinal_24(param_1);
  }
  ExceptionList = local_10;
  return -1 < local_18;
}



// Function: FUN_10005920 at 10005920

void __fastcall FUN_10005920(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *this;
  wchar_t *local_4c;
  int *local_48;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020c23;
  local_10 = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 8) == 0) {
    ExceptionList = &local_10;
    FUN_1001dca0(0x80004003);
  }
  piVar1 = *(int **)(param_1 + 8);
  iVar3 = (**(code **)(*piVar1 + 0xcc))(piVar1,&local_14);
  iVar2 = local_14;
  if (-1 < iVar3) {
    this = operator_new(0xc);
    local_8 = 0;
    if (this == (void *)0x0) {
      local_48 = (int *)0x0;
    }
    else {
      local_48 = thunk_FUN_10008c90(this,iVar2,'\0');
    }
    local_8 = 0xffffffff;
    if (local_48 == (int *)0x0) {
      FUN_1001dca0(0x8007000e);
    }
    local_8 = 1;
    if (local_48 == (int *)0x0) {
      local_4c = (wchar_t *)0x0;
    }
    else {
      local_4c = (wchar_t *)*local_48;
    }
    _wremove(local_4c);
    local_8 = 0xffffffff;
    if (local_48 != (int *)0x0) {
      thunk_FUN_10008d20(local_48);
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005a90 at 10005a90

bool __fastcall FUN_10005a90(int *param_1)

{
  int iVar1;
  void *this;
  int local_4c;
  int local_48;
  int *local_44;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020c53;
  local_10 = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_10;
  (**(code **)(*param_1 + 0x38))(param_1,&local_14);
  iVar1 = local_14;
  this = operator_new(0xc);
  local_8 = 0;
  if (this == (void *)0x0) {
    local_44 = (int *)0x0;
  }
  else {
    local_44 = thunk_FUN_10008c90(this,iVar1,'\0');
  }
  local_8 = 0xffffffff;
  if (local_44 == (int *)0x0) {
    FUN_1001dca0(0x8007000e);
  }
  local_8 = 1;
  if (local_44 == (int *)0x0) {
    local_4c = 0;
  }
  else {
    if (*local_44 == 0) {
      local_48 = 0;
    }
    else {
      local_48 = Ordinal_7(*local_44);
    }
    local_4c = local_48;
  }
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    thunk_FUN_10008d20(local_44);
  }
  ExceptionList = local_10;
  return local_4c != 0;
}



// Function: FUN_10005bf0 at 10005bf0

bool __fastcall FUN_10005bf0(int *param_1)

{
  int iVar1;
  void *this;
  int local_4c;
  int local_48;
  int *local_44;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020c83;
  local_10 = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_10;
  (**(code **)(*param_1 + 0x48))(param_1,&local_14);
  iVar1 = local_14;
  this = operator_new(0xc);
  local_8 = 0;
  if (this == (void *)0x0) {
    local_44 = (int *)0x0;
  }
  else {
    local_44 = thunk_FUN_10008c90(this,iVar1,'\0');
  }
  local_8 = 0xffffffff;
  if (local_44 == (int *)0x0) {
    FUN_1001dca0(0x8007000e);
  }
  local_8 = 1;
  if (local_44 == (int *)0x0) {
    local_4c = 0;
  }
  else {
    if (*local_44 == 0) {
      local_48 = 0;
    }
    else {
      local_48 = Ordinal_7(*local_44);
    }
    local_4c = local_48;
  }
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    thunk_FUN_10008d20(local_44);
  }
  ExceptionList = local_10;
  return local_4c != 0;
}



// Function: FUN_10005d50 at 10005d50

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __cdecl FUN_10005d50(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10020cb0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    ExceptionList = &local_10;
    piVar1 = param_3;
    if (param_3 != (int *)0x0) {
      ExceptionList = &local_10;
      (**(code **)(*param_3 + 4))(param_3);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10005ef0(param_2,piVar1);
  }
  if (param_1 < 0) goto LAB_10005e62;
  if (0x20e < param_2) {
    if ((0x20e < param_2) && ((param_2 < 0x214 || (param_2 == 999)))) goto LAB_10005e52;
    goto LAB_10005e5b;
  }
  if (param_2 == 0x20e) {
    if (DAT_100326f0 == '\x01') {
      param_1 = 0;
      DAT_100326f0 = '\0';
    }
    else {
      param_1 = -0x7fffbffb;
    }
    goto LAB_10005e62;
  }
  if (param_2 < 2) {
    if (param_2 == 1) {
LAB_10005e52:
      param_1 = -0x7fffbffb;
      goto LAB_10005e62;
    }
    if (param_2 == 0) {
      param_1 = 0;
      goto LAB_10005e62;
    }
  }
  else if ((499 < param_2) && (param_2 < 0x20e)) goto LAB_10005e52;
LAB_10005e5b:
  param_1 = -0x7fffbffb;
LAB_10005e62:
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10005ef0 at 10005ef0

void __cdecl FUN_10005ef0(undefined4 param_1,int *param_2)

{
  int iVar1;
  void *this;
  int *local_40;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10020cd3;
  local_10 = ExceptionList;
  local_8 = 0;
  local_18 = 0;
  ExceptionList = &local_10;
  if (param_2 == (int *)0x0) {
    ExceptionList = &local_10;
    FUN_1001dca0(0x80004003);
  }
  (**(code **)(*param_2 + 0x1c0))(param_2,0,param_1,&local_18);
  iVar1 = local_18;
  this = operator_new(0xc);
  local_8._0_1_ = 1;
  if (this == (void *)0x0) {
    local_40 = (int *)0x0;
  }
  else {
    local_40 = thunk_FUN_10008c90(this,iVar1,'\0');
  }
  local_8 = (uint)local_8._1_3_ << 8;
  local_14 = local_40;
  if (local_40 == (int *)0x0) {
    FUN_1001dca0(0x8007000e);
  }
  if (local_14 != (int *)0x0) {
    thunk_FUN_10008d20(local_14);
    local_14 = (int *)0x0;
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006030 at 10006030

void __fastcall FUN_10006030(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006060 at 10006060

void __fastcall FUN_10006060(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006090 at 10006090

void __fastcall FUN_10006090(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100060c0 at 100060c0

void __fastcall FUN_100060c0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100060f0 at 100060f0

undefined4 FUN_100060f0(int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_3 = 0;
    if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) && (param_2[3] == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar2 = 0x80004002;
    }
    else {
      if (((*param_2 == -0x2486896f) && (param_2[1] == 0x11d240e0)) &&
         ((param_2[2] == 0x6000d59b && (param_2[3] == 0x72e32a08)))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        if (((*param_2 == 0) && (param_2[1] == 0)) &&
           ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          if ((((*param_2 == 0x20400) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
             (param_2[3] == 0x46000000)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (!bVar1) {
            if (((*param_2 == param_1[5]) && (param_2[1] == param_1[6])) &&
               ((param_2[2] == param_1[7] && (param_2[3] == param_1[8])))) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            if (!bVar1) {
              return 0x80004002;
            }
          }
        }
      }
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



// Function: FUN_10006340 at 10006340

undefined4 FUN_10006340(void)

{
  return 1;
}



// Function: FUN_10006350 at 10006350

undefined4 FUN_10006350(void)

{
  return 1;
}



// Function: FUN_10006360 at 10006360

undefined4 FUN_10006360(void)

{
  return 0x80004001;
}



// Function: FUN_10006370 at 10006370

undefined4 FUN_10006370(void)

{
  return 0x80004001;
}



// Function: FUN_10006380 at 10006380

undefined4 FUN_10006380(void)

{
  return 0x80004001;
}



// Function: FUN_10006390 at 10006390

undefined4
FUN_10006390(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int *param_6,undefined1 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *local_40;
  undefined4 local_3c [12];
  int *local_c;
  undefined4 *local_8;
  
  local_c = &DAT_10028e88;
  local_40 = (int *)0x0;
  do {
    if (local_c[1] == 0) {
LAB_100063fb:
      if (local_40 == (int *)0x0) {
        uVar2 = 0;
      }
      else {
        if (local_40[5] == 0) {
          local_8 = local_3c;
          iVar1 = (**(code **)(*param_1 + 0x1c))(&DAT_10028c4c,param_2,param_4,local_3c);
          if (iVar1 < 0) {
            return 0;
          }
        }
        else {
          local_8 = (undefined4 *)local_40[5];
        }
        uVar2 = thunk_FUN_10006d80(local_40[4],local_8,param_6,param_7);
      }
      return uVar2;
    }
    if (((*local_c == 1) && (local_c[3] == param_2)) &&
       (iVar1 = memcmp((void *)local_c[1],&DAT_10028c4c,0x10), iVar1 == 0)) {
      local_40 = local_c;
      goto LAB_100063fb;
    }
    local_c = local_c + 6;
  } while( true );
}



// Function: FUN_100064b0 at 100064b0

void FUN_100064b0(undefined4 param_1,undefined4 param_2,undefined2 *param_3)

{
  thunk_FUN_10004770(param_2,param_3);
  return;
}



// Function: FUN_100064d0 at 100064d0

void FUN_100064d0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  thunk_FUN_10005000(*(void **)(param_1 + 0x2c),param_2,param_3,param_4);
  return;
}



// Function: FUN_10006550 at 10006550

void FUN_10006550(int param_1,undefined4 param_2,undefined4 param_3)

{
  thunk_FUN_100050c0(*(void **)(param_1 + 0x2c),param_2,param_3);
  return;
}



// Function: FUN_10006580 at 10006580

void FUN_10006580(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  thunk_FUN_100050f0(param_2,param_3);
  return;
}



// Function: FUN_100065a0 at 100065a0

undefined4 FUN_100065a0(void)

{
  return 0x80004001;
}



// Function: FUN_100065c0 at 100065c0

int * __thiscall FUN_100065c0(void *this,int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    FUN_1001dca0(0x80004003);
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 4))(*this);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_10006650 at 10006650

void __fastcall FUN_10006650(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006680 at 10006680

void __thiscall FUN_10006680(void *this,int *param_1)

{
  int iVar1;
  bool bVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < *(int **)((int)this + 4)) && (*this <= param_1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      thunk_FUN_10007210(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    thunk_FUN_10007de0((int)this + 0xc,*(int **)((int)this + 4),
                       (int *)(*this + ((int)param_1 - iVar1 >> 2) * 4));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  else {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      thunk_FUN_10007210(this,1);
    }
    thunk_FUN_10007de0((int)this + 0xc,*(int **)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  return;
}



// Function: FUN_10006790 at 10006790

void __fastcall FUN_10006790(_Container_base0 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020cf8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_100072c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100067f0 at 100067f0

void __thiscall FUN_100067f0(void *this,int *param_1)

{
  int iVar1;
  bool bVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < *(int **)((int)this + 4)) && (*this <= param_1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      thunk_FUN_10007210(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    thunk_FUN_10007e80((int)this + 0xc,*(int **)((int)this + 4),
                       (int *)(*this + ((int)param_1 - iVar1 >> 2) * 4));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  else {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      thunk_FUN_10007210(this,1);
    }
    thunk_FUN_10007f20((int)this + 0xc,*(int **)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  return;
}



// Function: FUN_10006900 at 10006900

void __fastcall FUN_10006900(undefined4 *param_1)

{
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_c = (int *)param_1[1];
  local_14 = (int *)*param_1;
  local_10 = local_14;
  local_8 = local_c;
  thunk_FUN_10007130(param_1,&local_18,local_14,local_c);
  return;
}



// Function: FUN_10006960 at 10006960

void __fastcall FUN_10006960(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006990 at 10006990

void __fastcall FUN_10006990(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100069c0 at 100069c0

void __fastcall FUN_100069c0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100069f0 at 100069f0

void __fastcall FUN_100069f0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006a20 at 10006a20

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

DWORD FUN_10006a20(LPCSTR param_1,LPUNKNOWN param_2,uint param_3)

{
  int iVar1;
  WCHAR *local_64;
  WCHAR **local_60;
  undefined1 **local_5c [2];
  void *local_54;
  WCHAR **local_50;
  WCHAR *local_4c;
  CLSID local_40;
  DWORD local_30;
  WCHAR **local_28;
  WCHAR *local_24;
  WCHAR **local_20;
  WCHAR **local_1c;
  WCHAR **local_14;
  DWORD local_10;
  int local_c;
  int local_8;
  
  if (param_1 == (LPCSTR)0x0) {
    local_10 = 0x80070057;
  }
  else {
    local_c = lstrlenA(param_1);
    local_c = local_c + 1;
    local_8 = MultiByteToWideChar(0,0,param_1,local_c,(LPWSTR)0x0,0);
    if (local_8 == 0) {
      local_10 = GetLastError();
      if (0 < (int)local_10) {
        local_10 = local_10 & 0xffff | 0x80070000;
      }
    }
    else {
      if (local_8 * 2 + 8U < 0x401) {
        local_1c = &local_64;
        if (&stack0x00000000 != (undefined1 *)0x64) {
          local_1c = (WCHAR **)local_5c;
        }
        local_5c[0] = (undefined1 **)&local_64;
        local_60 = local_1c;
      }
      else {
        local_20 = (WCHAR **)malloc(local_8 * 2 + 8);
        if ((undefined1 ***)local_20 != (undefined1 ***)0x0) {
          *local_20 = (WCHAR *)0xdddd;
          local_20 = (WCHAR **)((undefined1 ***)local_20 + 2);
        }
        local_60 = local_20;
      }
      local_14 = local_60;
      if ((undefined1 ***)local_60 == (undefined1 ***)0x0) {
        local_10 = 0x8007000e;
      }
      else {
        iVar1 = MultiByteToWideChar(0,0,param_1,local_c,(LPWSTR)local_60,local_8);
        if (iVar1 == 0) {
          local_28 = local_14;
          if ((undefined1 ***)local_14 != (undefined1 ***)0x0) {
            local_28 = local_14 + -2;
            local_24 = *local_28;
            if ((undefined1 **)local_24 == (undefined1 **)0xdddd) {
              free(local_28);
            }
          }
          local_10 = GetLastError();
          if (0 < (int)local_10) {
            local_10 = local_10 & 0xffff | 0x80070000;
          }
        }
        else {
          if ((undefined1 ***)local_14 == (undefined1 ***)0x0) {
            local_10 = 0x80070057;
          }
          else {
            if (*(short *)local_14 == 0x7b) {
              local_30 = CLSIDFromString((LPCOLESTR)local_14,&local_40);
            }
            else {
              local_30 = CLSIDFromProgID((LPCOLESTR)local_14,&local_40);
            }
            if ((int)local_30 < 0) {
              local_10 = local_30;
            }
            else {
              local_10 = thunk_FUN_100079a0(local_54,&local_40,param_2,param_3);
            }
          }
          if ((undefined1 ***)local_14 != (undefined1 ***)0x0) {
            local_50 = local_14 + -2;
            local_4c = *local_50;
            if ((undefined1 **)local_4c == (undefined1 **)0xdddd) {
              free(local_50);
            }
          }
        }
      }
    }
  }
  return local_10;
}



// Function: FUN_10006cf0 at 10006cf0

void __fastcall FUN_10006cf0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006d20 at 10006d20

void __fastcall FUN_10006d20(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006d50 at 10006d50

void __fastcall FUN_10006d50(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006d80 at 10006d80

undefined4 FUN_10006d80(undefined4 param_1,undefined4 *param_2,int *param_3,undefined1 *param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  uint local_94;
  undefined1 local_90 [16];
  undefined4 local_80;
  undefined1 **local_7c [2];
  undefined4 local_74;
  undefined1 *local_70 [2];
  undefined1 local_68 [84];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020d1b;
  local_10 = ExceptionList;
  if (*(short *)((int)param_2 + 6) < 0x15) {
    local_14 = -(uint)(*(short *)((int)param_2 + 6) != 0) & (uint)local_68;
    ExceptionList = &local_10;
    for (local_94 = 0; local_94 < (uint)param_3[3]; local_94 = local_94 + 1) {
      if ((local_14 == 0) || (0x13 < *(uint *)(param_3[1] + local_94 * 4))) {
        ExceptionList = pvVar1;
        return 0x80004005;
      }
      *(uint *)(local_14 + *(int *)(param_3[1] + local_94 * 4) * 4) = local_94 * 0x10 + *param_3;
    }
    for (; local_94 < (uint)param_3[2]; local_94 = local_94 + 1) {
      if (local_14 == 0) {
        ExceptionList = pvVar1;
        return 0x80004005;
      }
      *(uint *)((local_14 - 4) + ((int)*(short *)((int)param_2 + 6) - local_94) * 4) =
           local_94 * 0x10 + *param_3;
    }
    local_70[0] = &LAB_1001d6d8;
    local_7c[0] = local_70;
    local_74 = param_1;
    Ordinal_8(local_90);
    local_8 = 0;
    if (param_4 == (undefined1 *)0x0) {
      param_4 = local_90;
    }
    uVar2 = Ordinal_146(local_7c,0,*param_2,*(undefined2 *)(param_2 + 1),
                        (int)*(short *)((int)param_2 + 6),param_2 + 2,local_14,param_4);
    local_8 = 0xffffffff;
    local_80 = uVar2;
    Ordinal_9(local_90);
  }
  else {
    uVar2 = 0x80004005;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10006fc0 at 10006fc0

int * __thiscall FUN_10006fc0(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 4))(*this);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_10007030 at 10007030

int __thiscall FUN_10007030(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  LPUNKNOWN local_c;
  HRESULT local_8;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 8))(*this);
  }
  if ((param_3 & 0x14) == 0) {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028f18,(LPVOID *)this);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028f2c,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,(IID *)&DAT_10028f18,(void **)this);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_10007130 at 10007130

undefined4 * __thiscall FUN_10007130(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *local_38;
  
  if (param_2 != param_3) {
    piVar2 = thunk_FUN_10007fd0(param_3,*(int **)((int)this + 4),param_2);
    piVar1 = *(int **)((int)this + 4);
    for (local_38 = piVar2; local_38 != piVar1; local_38 = local_38 + 1) {
      thunk_FUN_10008550((int)this + 0xc,local_38);
    }
    *(int **)((int)this + 4) = piVar2;
  }
  *param_1 = param_2;
  return param_1;
}



// Function: FUN_10007210 at 10007210

/* WARNING: Removing unreachable block (ram,0x1000723f) */

void __thiscall FUN_10007210(void *this,int param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 4) - *this >> 2;
  if (0x3fffffffU - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
  }
  else {
    uVar1 = uVar1 + param_1;
                    /* WARNING: Load size is inaccurate */
    if ((uint)(*(int *)((int)this + 8) - *this >> 2) < uVar1) {
      uVar1 = thunk_FUN_10007900(this,uVar1);
      thunk_FUN_100076e0(this,uVar1);
    }
  }
  return;
}



// Function: FUN_100072c0 at 100072c0

void __fastcall FUN_100072c0(_Container_base0 *param_1)

{
  int *piVar1;
  int *local_c;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    piVar1 = *(int **)(param_1 + 4);
    for (local_c = *(int **)param_1; local_c != piVar1; local_c = local_c + 1) {
      thunk_FUN_10008550(param_1 + 0xc,local_c);
    }
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10007390 at 10007390

undefined4 * __fastcall FUN_10007390(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_100073d0 at 100073d0

void FUN_100073d0(void)

{
  return;
}



// Function: FUN_100073e0 at 100073e0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

DWORD FUN_100073e0(LPCSTR param_1,LPUNKNOWN param_2,uint param_3)

{
  int iVar1;
  WCHAR *local_64;
  WCHAR **local_60;
  undefined1 **local_5c [2];
  void *local_54;
  WCHAR **local_50;
  WCHAR *local_4c;
  CLSID local_40;
  DWORD local_30;
  WCHAR **local_28;
  WCHAR *local_24;
  WCHAR **local_20;
  WCHAR **local_1c;
  WCHAR **local_14;
  DWORD local_10;
  int local_c;
  int local_8;
  
  if (param_1 == (LPCSTR)0x0) {
    local_10 = 0x80070057;
  }
  else {
    local_c = lstrlenA(param_1);
    local_c = local_c + 1;
    local_8 = MultiByteToWideChar(0,0,param_1,local_c,(LPWSTR)0x0,0);
    if (local_8 == 0) {
      local_10 = GetLastError();
      if (0 < (int)local_10) {
        local_10 = local_10 & 0xffff | 0x80070000;
      }
    }
    else {
      if (local_8 * 2 + 8U < 0x401) {
        local_1c = &local_64;
        if (&stack0x00000000 != (undefined1 *)0x64) {
          local_1c = (WCHAR **)local_5c;
        }
        local_5c[0] = (undefined1 **)&local_64;
        local_60 = local_1c;
      }
      else {
        local_20 = (WCHAR **)malloc(local_8 * 2 + 8);
        if ((undefined1 ***)local_20 != (undefined1 ***)0x0) {
          *local_20 = (WCHAR *)0xdddd;
          local_20 = (WCHAR **)((undefined1 ***)local_20 + 2);
        }
        local_60 = local_20;
      }
      local_14 = local_60;
      if ((undefined1 ***)local_60 == (undefined1 ***)0x0) {
        local_10 = 0x8007000e;
      }
      else {
        iVar1 = MultiByteToWideChar(0,0,param_1,local_c,(LPWSTR)local_60,local_8);
        if (iVar1 == 0) {
          local_28 = local_14;
          if ((undefined1 ***)local_14 != (undefined1 ***)0x0) {
            local_28 = local_14 + -2;
            local_24 = *local_28;
            if ((undefined1 **)local_24 == (undefined1 **)0xdddd) {
              free(local_28);
            }
          }
          local_10 = GetLastError();
          if (0 < (int)local_10) {
            local_10 = local_10 & 0xffff | 0x80070000;
          }
        }
        else {
          if ((undefined1 ***)local_14 == (undefined1 ***)0x0) {
            local_10 = 0x80070057;
          }
          else {
            if (*(short *)local_14 == 0x7b) {
              local_30 = CLSIDFromString((LPCOLESTR)local_14,&local_40);
            }
            else {
              local_30 = CLSIDFromProgID((LPCOLESTR)local_14,&local_40);
            }
            if ((int)local_30 < 0) {
              local_10 = local_30;
            }
            else {
              local_10 = thunk_FUN_10007aa0(local_54,&local_40,param_2,param_3);
            }
          }
          if ((undefined1 ***)local_14 != (undefined1 ***)0x0) {
            local_50 = local_14 + -2;
            local_4c = *local_50;
            if ((undefined1 **)local_4c == (undefined1 **)0xdddd) {
              free(local_50);
            }
          }
        }
      }
    }
  }
  return local_10;
}



// Function: FUN_100076b0 at 100076b0

void __fastcall FUN_100076b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100076e0 at 100076e0

/* WARNING: Removing unreachable block (ram,0x1000771a) */

void __thiscall FUN_100076e0(void *this,uint param_1)

{
  int *piVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020d30;
  pvStack_10 = ExceptionList;
  if (param_1 < 0x40000000) {
                    /* WARNING: Load size is inaccurate */
    if ((uint)(*(int *)((int)this + 8) - *this >> 2) < param_1) {
      ExceptionList = &pvStack_10;
      piVar1 = (int *)thunk_FUN_10008080(param_1);
      local_8 = 0;
                    /* WARNING: Load size is inaccurate */
      thunk_FUN_10008460(*this,*(int **)((int)this + 4),piVar1,(int)this + 0xc);
      FUN_100077c5();
      return;
    }
  }
  else {
    ExceptionList = &pvStack_10;
    std::_Xlength_error("vector<T> too long");
  }
  ExceptionList = pvStack_10;
  return;
}



// Function: Catch@100077a3 at 100077a3

void Catch_100077a3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100077c5 at 100077c5

void FUN_100077c5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x18) =
       *(int *)(*(int *)(unaff_EBP + -0x54) + 4) - **(int **)(unaff_EBP + -0x54) >> 2;
  if (**(int **)(unaff_EBP + -0x54) != 0) {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x54) + 4);
    *(undefined4 *)(unaff_EBP + -0x44) = **(undefined4 **)(unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -0x39) = *(undefined1 *)(unaff_EBP + -0x3a);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x44);
    while (*(int *)(unaff_EBP + -0x40) != *(int *)(unaff_EBP + -0x48)) {
      thunk_FUN_10008550(*(int *)(unaff_EBP + -0x54) + 0xc,*(int **)(unaff_EBP + -0x40));
      *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 4;
    }
    *(int *)(unaff_EBP + -0x50) =
         *(int *)(*(int *)(unaff_EBP + -0x54) + 8) - **(int **)(unaff_EBP + -0x54) >> 2;
    *(undefined4 *)(unaff_EBP + -0x4c) = **(undefined4 **)(unaff_EBP + -0x54);
    operator_delete(*(void **)(unaff_EBP + -0x4c));
  }
  std::_Container_base0::_Orphan_all(*(_Container_base0 **)(unaff_EBP + -0x54));
  *(int *)(*(int *)(unaff_EBP + -0x54) + 8) =
       *(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + 8) * 4;
  *(int *)(*(int *)(unaff_EBP + -0x54) + 4) =
       *(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + -0x18) * 4;
  **(undefined4 **)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10007900 at 10007900

/* WARNING: Removing unreachable block (ram,0x1000792f) */

uint __thiscall FUN_10007900(void *this,uint param_1)

{
  undefined4 local_18;
  undefined4 local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_18 = *(int *)((int)this + 8) - *this >> 2;
  if (0x3fffffff - (local_18 >> 1) < local_18) {
    local_18 = 0;
  }
  else {
    local_18 = (local_18 >> 1) + local_18;
  }
  local_8 = local_18;
  if (local_18 < param_1) {
    local_8 = param_1;
  }
  return local_8;
}



// Function: FUN_100079a0 at 100079a0

int __thiscall FUN_100079a0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  LPUNKNOWN local_c;
  HRESULT local_8;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 8))(*this);
  }
  if ((param_3 & 0x14) == 0) {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028d90,(LPVOID *)this);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028f2c,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,(IID *)&DAT_10028d90,(void **)this);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_10007aa0 at 10007aa0

int __thiscall FUN_10007aa0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  LPUNKNOWN local_c;
  HRESULT local_8;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 8))(*this);
  }
  if ((param_3 & 0x14) == 0) {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028e34,(LPVOID *)this);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028f2c,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,(IID *)&DAT_10028e34,(void **)this);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_10007ba0 at 10007ba0

/* WARNING: Removing unreachable block (ram,0x10007bb8) */

bool __cdecl FUN_10007ba0(int param_1,int *param_2)

{
  if (param_1 != 0) {
    FUN_1001dca0(0x80004003);
  }
  return (bool)('\x01' - (*param_2 == 0));
}



// Function: FUN_10007bf0 at 10007bf0

/* WARNING: Removing unreachable block (ram,0x10007c08) */

bool __cdecl FUN_10007bf0(int param_1,int *param_2)

{
  if (param_1 != 0) {
    FUN_1001dca0(0x80004003);
  }
  return *param_2 == 0;
}



// Function: FUN_10007c40 at 10007c40

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_10007c40(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020d48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = thunk_FUN_10008140(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    FUN_1001dca0(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007d10 at 10007d10

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_10007d10(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020d68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = thunk_FUN_100082d0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    FUN_1001dca0(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007de0 at 10007de0

void __cdecl FUN_10007de0(undefined4 param_1,int *param_2,int *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020d91;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_2 != (int *)0x0) && (ExceptionList = &local_10, *param_2 = *param_3, *param_2 != 0)) {
    InterlockedIncrement((LONG *)(*param_2 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007e80 at 10007e80

void __cdecl FUN_10007e80(undefined4 param_1,int *param_2,int *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020dc1;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_2 != (int *)0x0) && (ExceptionList = &local_10, *param_2 = *param_3, *param_2 != 0)) {
    InterlockedIncrement((LONG *)(*param_2 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007f20 at 10007f20

void __cdecl FUN_10007f20(undefined4 param_1,int *param_2,int *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020df1;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_2 != (int *)0x0) && (ExceptionList = &local_10, *param_2 = *param_3, *param_2 != 0)) {
    InterlockedIncrement((LONG *)(*param_2 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007fd0 at 10007fd0

int * __cdecl FUN_10007fd0(int *param_1,int *param_2,int *param_3)

{
  int *local_24;
  int *local_20;
  
  local_24 = param_3;
  for (local_20 = param_1; local_20 != param_2; local_20 = local_20 + 1) {
    if (local_24 != local_20) {
      if (*local_24 != 0) {
        thunk_FUN_10008d20((void *)*local_24);
        *local_24 = 0;
      }
      *local_24 = *local_20;
      if (*local_24 != 0) {
        InterlockedIncrement((LONG *)(*local_24 + 8));
      }
    }
    local_24 = local_24 + 1;
  }
  return local_24;
}



// Function: FUN_10008080 at 10008080

void * __cdecl FUN_10008080(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020e19;
  local_10 = ExceptionList;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0x3fffffff < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 << 2), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_1002e4e0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10008140 at 10008140

/* WARNING: Removing unreachable block (ram,0x10008169) */

int __thiscall FUN_10008140(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020e38;
  local_10 = ExceptionList;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    ExceptionList = &local_10;
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
      ExceptionList = &local_10;
      *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
      if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        (**(code **)(**this + 4))(*this);
      }
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    local_14 = -0x7fffbffe;
  }
  else {
    ExceptionList = &local_10;
    if (param_1 == (int *)0x0) {
      ExceptionList = &local_10;
      FUN_1001dca0(0x80004003);
    }
    local_14 = (**(code **)*param_1)(param_1,&DAT_10028d7c,&local_18);
    bVar3 = local_14 < 0;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 8))(*this);
    }
    *(uint *)this = bVar3 - 1 & local_18;
  }
  iVar2 = local_14;
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_100082d0 at 100082d0

/* WARNING: Removing unreachable block (ram,0x100082f9) */

int __thiscall FUN_100082d0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020e58;
  local_10 = ExceptionList;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    ExceptionList = &local_10;
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
      ExceptionList = &local_10;
      *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
      if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        (**(code **)(**this + 4))(*this);
      }
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    local_14 = -0x7fffbffe;
  }
  else {
    ExceptionList = &local_10;
    if (param_1 == (int *)0x0) {
      ExceptionList = &local_10;
      FUN_1001dca0(0x80004003);
    }
    local_14 = (**(code **)*param_1)(param_1,&DAT_10028d68,&local_18);
    bVar3 = local_14 < 0;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 8))(*this);
    }
    *(uint *)this = bVar3 - 1 & local_18;
  }
  iVar2 = local_14;
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10008460 at 10008460

void FUN_10008460(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020e70;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    thunk_FUN_10007de0(param_4,param_3,param_1);
    param_3 = param_3 + 1;
  }
  FUN_100084fc();
  return;
}



// Function: FUN_100084c3 at 100084c3

void FUN_100084c3(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    thunk_FUN_10008550(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_100084c3();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100084cc at 100084cc

void FUN_100084cc(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    thunk_FUN_10008550(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_100084c3();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100084fc at 100084fc

undefined4 FUN_100084fc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: FUN_10008550 at 10008550

/* WARNING: Removing unreachable block (ram,0x10008578) */

void __cdecl FUN_10008550(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    thunk_FUN_10008d20((void *)*param_2);
    *param_2 = 0;
  }
  return;
}



// Function: FUN_100085a0 at 100085a0

int FUN_100085a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020eb0;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_1c = (int *)0x0;
    local_14 = (int *)0x0;
    local_8 = 3;
    ExceptionList = &local_10;
    local_18 = (**(code **)*param_1)(param_1,&DAT_10028f68,&local_1c);
    if (-1 < local_18) {
      local_18 = (**(code **)(*local_1c + 0x10))(local_1c,param_2,&local_14);
    }
    if (-1 < local_18) {
      local_18 = (**(code **)(*local_14 + 0x18))(local_14,param_3);
    }
    iVar1 = local_18;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_100086f0 at 100086f0

void __fastcall FUN_100086f0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020ed8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008760 at 10008760

void __fastcall FUN_10008760(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020ef8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100087d0 at 100087d0

void FUN_100087d0(void)

{
  return;
}



// Function: FUN_100087e0 at 100087e0

void FUN_100087e0(void)

{
  return;
}



// Function: FUN_10008830 at 10008830

undefined4 * __thiscall FUN_10008830(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020f38;
  local_10 = ExceptionList;
  if ((param_1 & 2) == 0) {
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    ExceptionList = &local_10;
    Ordinal_6(*this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    ExceptionList = &local_10;
    _eh_vector_destructor_iterator_
              (this,0xc,*(int *)((int)this + -4),(_func_void_void_ptr *)&LAB_100016b8);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008900 at 10008900

void __fastcall FUN_10008900(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020f58;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  Ordinal_6(*param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008960 at 10008960

void __thiscall FUN_10008960(void *this,undefined4 *param_1,undefined4 param_2)

{
  if (*(int *)((int)this + 0x28) != -0x1010102) {
    thunk_FUN_10004720(0x80004005);
  }
  thunk_FUN_100089d0(param_1,this,param_2,(int)this + 0x28);
  return;
}



// Function: FUN_100089d0 at 100089d0

int FUN_100089d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020fa0;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_1c = (int *)0x0;
    local_14 = (int *)0x0;
    local_8 = 3;
    ExceptionList = &local_10;
    local_18 = (**(code **)*param_1)(param_1,&DAT_10028f68,&local_1c);
    if (-1 < local_18) {
      local_18 = (**(code **)(*local_1c + 0x10))(local_1c,param_3,&local_14);
    }
    if (-1 < local_18) {
      local_18 = (**(code **)(*local_14 + 0x14))(local_14,param_2,param_4);
    }
    iVar1 = local_18;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10008b20 at 10008b20

int * __thiscall FUN_10008b20(void *this,int param_1)

{
  int iVar1;
  int *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10020fcb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = (int *)operator_new(0xc);
  local_8 = 0;
  if (local_20 == (int *)0x0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20[1] = 0;
    local_20[2] = 1;
    iVar1 = Ordinal_2(param_1);
    *local_20 = iVar1;
    if ((*local_20 == 0) && (param_1 != 0)) {
      FUN_1001dca0(0x8007000e);
    }
  }
  local_8 = 0xffffffff;
  *(int **)this = local_20;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    FUN_1001dca0(0x8007000e);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10008c10 at 10008c10

void __fastcall FUN_10008c10(int *param_1)

{
  if (*param_1 != 0) {
    thunk_FUN_10008d20((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10008c50 at 10008c50

void __fastcall FUN_10008c50(int *param_1)

{
  if (*param_1 != 0) {
    thunk_FUN_10008d20((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10008c90 at 10008c90

int * __thiscall FUN_10008c90(void *this,int param_1,char param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if ((param_2 == '\0') || (param_1 == 0)) {
    *(int *)this = param_1;
  }
  else {
    uVar1 = Ordinal_149(param_1);
    uVar1 = Ordinal_150(param_1,uVar1);
    *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      FUN_1001dca0(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_10008d20 at 10008d20

LONG __fastcall FUN_10008d20(void *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 8));
  if ((LVar1 == 0) && (param_1 != (void *)0x0)) {
    thunk_FUN_10008d90(param_1,1);
  }
  return LVar1;
}



// Function: FUN_10008d90 at 10008d90

int * __thiscall FUN_10008d90(void *this,uint param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
  }
  if (*(int *)((int)this + 4) != 0) {
    operator_delete__(*(void **)((int)this + 4));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_10008e00 at 10008e00

int __fastcall FUN_10008e00(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = Ordinal_149(*param_1);
    iVar2 = Ordinal_150(*param_1,uVar1);
    if (iVar2 == 0) {
      FUN_1001dca0(0x8007000e);
    }
  }
  return iVar2;
}



// Function: FUN_10008e60 at 10008e60

undefined2 * __thiscall FUN_10008e60(void *this,int param_1,short param_2)

{
  if (((param_2 == 3) || (param_2 == 10)) || (param_2 == 0xb)) {
    if (param_2 == 10) {
      *(undefined2 *)this = 10;
      *(int *)((int)this + 8) = param_1;
    }
    else if (param_2 == 0xb) {
      *(undefined2 *)this = 0xb;
      *(ushort *)((int)this + 8) = -(ushort)(param_1 != 0);
    }
    else {
      *(undefined2 *)this = 3;
      *(int *)((int)this + 8) = param_1;
    }
  }
  else {
    FUN_1001dca0(0x80070057);
  }
  return (undefined2 *)this;
}



// Function: FUN_10008f20 at 10008f20

void __fastcall FUN_10008f20(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10008f40 at 10008f40

void __fastcall FUN_10008f40(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10020fe9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008fa0 at 10008fa0

exception * __thiscall FUN_10008fa0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021009;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10009020 at 10009020

void FUN_10009020(void)

{
  return;
}



// Function: FUN_10009030 at 10009030

void __fastcall FUN_10009030(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10009060 at 10009060

void __fastcall FUN_10009060(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10009090 at 10009090

exception * __thiscall FUN_10009090(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021029;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10009100 at 10009100

void FUN_10009100(int param_1)

{
  thunk_FUN_1000a320((int *)&DAT_10033e94,200,param_1,(int *)0x0);
  return;
}



// Function: FUN_10009130 at 10009130

undefined4 FUN_10009130(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    thunk_FUN_1000f1c0(&DAT_10033e94,0x10033108,param_1,(undefined4 *)&DAT_10028fc8);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    thunk_FUN_1000f2a0(0x10033e94);
  }
  return 1;
}



// Function: FUN_10009190 at 10009190

bool FUN_10009190(void)

{
  return DAT_10033e9c != 0;
}



// Function: FUN_100091b0 at 100091b0

void FUN_100091b0(int *param_1,undefined4 param_2,int *param_3)

{
  thunk_FUN_1000f410(&DAT_10033e94,param_1,param_2,param_3);
  return;
}



// Function: FUN_100091e0 at 100091e0

void FUN_100091e0(void)

{
  thunk_FUN_1000f650(&DAT_10033e94,1,(void *)0x0);
  return;
}



// Function: FUN_10009210 at 10009210

void FUN_10009210(void)

{
  thunk_FUN_100111f0(&DAT_10033e94,1,(void *)0x0);
  return;
}



// Function: FUN_10009240 at 10009240

undefined4 FUN_10009240(void)

{
  return 0;
}



// Function: FUN_10009250 at 10009250

undefined4 FUN_10009250(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002105e;
  pvStack_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &pvStack_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      thunk_FUN_10009bf0(puVar1 + 1);
      *puVar1 = ATL::CComClassFactory::vftable;
      *puVar1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_1000930e();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10009301 at 10009301

undefined4 Catch_10009301(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009315;
}



// Function: FUN_1000930e at 1000930e

undefined4 FUN_1000930e(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x24) = *(undefined4 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x14) + 8;
    DVar1 = thunk_FUN_10009440(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x38));
    *(DWORD *)(unaff_EBP + -0x2c) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x2c)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x38) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x2c);
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009440 at 10009440

DWORD __fastcall FUN_10009440(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  undefined4 local_14;
  undefined4 local_8;
  
  local_8 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    local_14 = GetLastError();
    if (0 < (int)local_14) {
      local_14 = local_14 & 0xffff | 0x80070000;
    }
    local_8 = local_14;
  }
  return local_8;
}



// Function: FUN_100094c0 at 100094c0

undefined4 FUN_100094c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = thunk_FUN_10009630(0,param_2,param_3);
  }
  else {
    local_8 = thunk_FUN_100099b0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10009510 at 10009510

LONG FUN_10009510(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10033e14 + 4))();
  }
  return LVar1;
}



// Function: FUN_10009560 at 10009560

LONG FUN_10009560(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10033e14 + 8))();
  }
  return LVar1;
}



// Function: FUN_100095f0 at 100095f0

int FUN_100095f0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = thunk_FUN_10011900(param_1,(int *)&PTR_DAT_10029070,param_2,param_3);
  return iVar1;
}



// Function: FUN_10009630 at 10009630

undefined4 FUN_10009630(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021088;
  pvStack_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &pvStack_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x70);
    if (puVar1 != (undefined4 *)0x0) {
      thunk_FUN_100020d0((int)puVar1);
      local_8._0_1_ = 1;
      *puVar1 = ATL::CComObject<class_CCompress>::vftable;
      (**(code **)(*DAT_10033e14 + 4))();
      local_8 = (uint)local_8._1_3_ << 8;
    }
    uVar2 = FUN_100096e3();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100096d6 at 100096d6

undefined4 Catch_100096d6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100096ea;
}



// Function: FUN_100096e3 at 100096e3

undefined4 FUN_100096e3(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x14) + 4;
    **(int **)(unaff_EBP + -0x2c) = **(int **)(unaff_EBP + -0x2c) + 1;
    *(undefined4 *)(unaff_EBP + -0x28) = **(undefined4 **)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = thunk_FUN_10002850();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x14) + 4;
    **(int **)(unaff_EBP + -0x34) = **(int **)(unaff_EBP + -0x34) + -1;
    *(undefined4 *)(unaff_EBP + -0x30) = **(undefined4 **)(unaff_EBP + -0x34);
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x90))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009830 at 10009830

undefined4 __fastcall FUN_10009830(undefined4 param_1)

{
  return param_1;
}



// Function: GetTypeInfoCount at 10009850

/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::GetTypeInfoCount(unsigned int *)
   
   Library: Visual Studio */

long CWnd::XAccessible::GetTypeInfoCount(uint *param_1)

{
  long lVar1;
  undefined4 *in_stack_00000008;
  
  if (in_stack_00000008 == (undefined4 *)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    *in_stack_00000008 = 1;
    lVar1 = 0;
  }
  return lVar1;
}



// Function: FUN_10009880 at 10009880

int FUN_10009880(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int local_27c;
  
  if (param_2 == 0) {
    local_27c = thunk_FUN_10011dd0(&PTR_DAT_100335ec,param_3,param_4);
  }
  else {
    local_27c = -0x7ffdfff5;
  }
  return local_27c;
}



// Function: FUN_100098d0 at 100098d0

void FUN_100098d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  thunk_FUN_10011e80(&PTR_DAT_100335ec,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10009910 at 10009910

int FUN_10009910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  if ((DAT_100335f8 == (int *)0x0) || (DAT_10033600 == 0)) {
    local_c = thunk_FUN_10012010(&PTR_DAT_100335ec,param_4);
  }
  local_8 = local_c;
  if (DAT_100335f8 != (int *)0x0) {
    local_8 = (**(code **)(*DAT_100335f8 + 0x2c))
                        (DAT_100335f8,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return local_8;
}



// Function: FUN_100099b0 at 100099b0

undefined4 FUN_100099b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100210ab;
  pvStack_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &pvStack_10;
    *param_3 = 0;
    local_8 = 0;
    this = operator_new(0x78);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      thunk_FUN_10009e20(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_10009a4e();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10009a41 at 10009a41

undefined4 Catch_10009a41(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009a55;
}



// Function: FUN_10009a4e at 10009a4e

undefined4 FUN_10009a4e(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    if (-1 < *(int *)(unaff_EBP + -0x34)) {
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
    }
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x34);
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = thunk_FUN_10002850();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009b60 at 10009b60

undefined4 * __thiscall FUN_10009b60(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100210c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  local_8 = 0xffffffff;
  thunk_FUN_10011bc0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009bf0 at 10009bf0

undefined4 * __fastcall FUN_10009bf0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021103;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  memset(param_1 + 1,0,0x18);
  *(undefined1 *)(param_1 + 7) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009c80 at 10009c80

void FUN_10009c80(void)

{
  return;
}



// Function: FUN_10009c90 at 10009c90

void __fastcall FUN_10009c90(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021128;
  local_10 = ExceptionList;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009d00 at 10009d00

int FUN_10009d00(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + 1;
  return *piVar1;
}



// Function: FUN_10009d50 at 10009d50

int FUN_10009d50(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 1;
  *piVar2 = *piVar2 + -1;
  iVar1 = *piVar2;
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x90))(1);
  }
  return iVar1;
}



// Function: FUN_10009de0 at 10009de0

int FUN_10009de0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = thunk_FUN_10011900(param_1,(int *)&PTR_DAT_10029158,param_2,param_3);
  return iVar1;
}



// Function: FUN_10009e20 at 10009e20

undefined4 * __thiscall FUN_10009e20(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021166;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CCompress>::vftable;
  thunk_FUN_100020d0((int)this + 8);
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CCompress>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_10033e14 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009ef0 at 10009ef0

int FUN_10009ef0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + 1;
  return *piVar1;
}



// Function: FUN_10009f40 at 10009f40

int FUN_10009f40(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 1;
  *piVar2 = *piVar2 + -1;
  iVar1 = *piVar2;
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return iVar1;
}



// Function: FUN_10009fc0 at 10009fc0

int FUN_10009fc0(int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  int local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    *param_3 = 0;
    local_8 = 0;
    if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
       (param_2[3] == 0x46000000)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
    else {
      local_8 = thunk_FUN_10011900((int)(param_1 + 2),(int *)&PTR_DAT_10029158,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_1000a0a0 at 1000a0a0

void FUN_1000a0a0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_1000a0d0 at 1000a0d0

void FUN_1000a0d0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_1000a100 at 1000a100

void FUN_1000a100(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 *)(param_1 + 4),param_2,param_3);
  return;
}



// Function: FUN_1000a140 at 1000a140

undefined4 __fastcall FUN_1000a140(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000a160 at 1000a160

undefined4 * __thiscall FUN_1000a160(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CCompress>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_10033e14 + 8))();
  local_8 = 0xffffffff;
  thunk_FUN_10002700((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000a200 at 1000a200

undefined4 * __thiscall FUN_1000a200(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100211c9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CCompress>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_10033e14 + 8))();
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_10002700((int)this + 8);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000a2d0 at 1000a2d0

void __fastcall FUN_1000a2d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100211e8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  thunk_FUN_10002700(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000a320 at 1000a320

/* WARNING: Removing unreachable block (ram,0x1000a64f) */
/* WARNING: Removing unreachable block (ram,0x1000a374) */

int FUN_1000a320(int *param_1,ushort param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  errno_t eVar3;
  int iVar4;
  long local_b40;
  int local_b28 [2];
  undefined4 local_b20;
  int local_b14;
  wchar_t *local_b10;
  int local_b0c;
  int local_b08 [2];
  undefined4 local_b00;
  int *local_af4;
  undefined4 *local_af0;
  int local_aec;
  int *local_ae4;
  undefined4 *local_ae0;
  int *local_adc;
  undefined4 *local_ad8;
  int *local_ad4;
  int local_ad0;
  LPCWSTR local_acc;
  int local_ac8;
  LPCWSTR local_ac4;
  int local_ac0;
  int local_abc [2];
  undefined4 local_ab4;
  long local_aa4;
  int local_aa0;
  int local_a9c;
  int local_a98;
  int local_a94;
  long local_a90;
  int local_a8c;
  int local_a84;
  WCHAR local_a80;
  undefined2 local_a7e [523];
  WCHAR local_668 [520];
  WCHAR *local_258;
  int local_254;
  wchar_t *local_250;
  int local_24c;
  DWORD local_248;
  undefined **local_244;
  int local_240 [4];
  undefined4 *local_230 [2];
  WCHAR local_228 [260];
  undefined4 local_20;
  HMODULE local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100212b0;
  local_10 = ExceptionList;
  local_244 = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  thunk_FUN_1000f150(local_240);
  local_8 = 1;
  local_24c = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_ad0 = param_4[1];
      local_acc = (LPCWSTR)*param_4;
      if ((local_acc != (LPCWSTR)0x0) && (local_ad0 != 0)) {
        local_ab4 = 3;
        local_abc[0] = 0;
        local_8._0_1_ = 4;
        local_ac4 = local_acc;
        local_ac0 = thunk_FUN_1000aed0(local_acc,local_ad0);
        local_ac8 = (-(uint)(local_ac0 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        thunk_FUN_10012c90(local_abc);
      }
    }
  }
  local_a8c = (**(code **)(*param_1 + 0x14))(&local_244);
  local_24c = local_a8c;
  if (local_a8c < 0) {
    local_244 = ATL::CRegObject::vftable;
    local_8 = 5;
    thunk_FUN_1000ba80((int)&local_244);
    local_ad4 = local_240;
    local_8 = 6;
    thunk_FUN_1000b330(local_ad4);
    local_8 = 0xffffffff;
    thunk_FUN_10012e90(local_ad4);
  }
  else {
    local_20 = 3;
    local_230[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_1c = DAT_100341c4;
    local_248 = GetModuleFileNameW(DAT_100341c4,local_228,0x104);
    if (local_248 == 0) {
      local_a90 = ATL::AtlHresultFromLastError();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_230[0], local_230[0] != (undefined4 *)0x0) {
        local_ad8 = local_230[0];
        local_230[0] = (undefined4 *)*local_230[0];
        free(puVar1);
      }
      local_244 = ATL::CRegObject::vftable;
      local_8 = 8;
      thunk_FUN_1000ba80((int)&local_244);
      local_adc = local_240;
      local_8 = 9;
      thunk_FUN_1000b330(local_adc);
      local_8 = 0xffffffff;
      thunk_FUN_10012e90(local_adc);
      local_a8c = local_a90;
    }
    else if (local_248 == 0x104) {
      local_a94 = -0x7ff8ff86;
      local_8 = CONCAT31(local_8._1_3_,1);
      local_248 = 0x104;
      while (puVar1 = local_230[0], local_230[0] != (undefined4 *)0x0) {
        local_ae0 = local_230[0];
        local_230[0] = (undefined4 *)*local_230[0];
        free(puVar1);
      }
      local_244 = ATL::CRegObject::vftable;
      local_8 = 10;
      thunk_FUN_1000ba80((int)&local_244);
      local_ae4 = local_240;
      local_8 = 0xb;
      thunk_FUN_1000b330(local_ae4);
      local_8 = 0xffffffff;
      thunk_FUN_10012e90(local_ae4);
      local_a8c = local_a94;
    }
    else {
      local_258 = local_228;
      thunk_FUN_1000ada0(local_668,0x208,local_258);
      if ((local_1c == (HMODULE)0x0) ||
         (pHVar2 = GetModuleHandleW((LPCWSTR)0x0), local_1c == pHVar2)) {
        local_a80 = L'\"';
        local_aec = lstrlenW(local_668);
        eVar3 = memcpy_s(local_a7e,0x416,local_668,local_aec * 2 + 2);
        if (eVar3 != 0) {
          local_a98 = -0x7fffbffb;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_230[0], local_230[0] != (undefined4 *)0x0) {
            local_af0 = local_230[0];
            local_230[0] = (undefined4 *)*local_230[0];
            free(puVar1);
          }
          local_244 = ATL::CRegObject::vftable;
          local_8 = 0xc;
          thunk_FUN_1000ba80((int)&local_244);
          local_af4 = local_240;
          local_8 = 0xd;
          thunk_FUN_1000b330(local_af4);
          local_8 = 0xffffffff;
          thunk_FUN_10012e90(local_af4);
          ExceptionList = local_10;
          return local_a98;
        }
        local_a84 = lstrlenW(&local_a80);
        local_a7e[local_a84 + -1] = 0x22;
        local_a7e[local_a84] = 0;
        if (&stack0x00000000 == (undefined1 *)0xa80) {
          local_254 = -0x7ff8ffa9;
        }
        else {
          local_b00 = 3;
          local_b08[0] = 0;
          local_8._0_1_ = 0xe;
          local_b10 = L"Module";
          local_b0c = thunk_FUN_1000aed0(L"Module",(int)&local_a80);
          local_b14 = (-(uint)(local_b0c != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          thunk_FUN_10012c90(local_b08);
          local_254 = local_b14;
        }
      }
      else if (&stack0x00000000 == (undefined1 *)0x668) {
        local_254 = -0x7ff8ffa9;
      }
      else {
        local_b20 = 3;
        local_b28[0] = 0;
        local_8._0_1_ = 0xf;
        iVar4 = thunk_FUN_1000aed0(L"Module",(int)local_668);
        local_8._0_1_ = 7;
        thunk_FUN_10012c90(local_b28);
        local_254 = (-(uint)(iVar4 != 0) & 0x7ff8fff2) + 0x8007000e;
      }
      if (local_254 < 0) {
        local_a9c = local_254;
        local_8 = CONCAT31(local_8._1_3_,1);
        while (puVar1 = local_230[0], local_230[0] != (undefined4 *)0x0) {
          local_230[0] = (undefined4 *)*local_230[0];
          free(puVar1);
        }
        local_8 = 0xffffffff;
        thunk_FUN_1000b460(&local_244);
        local_a8c = local_a9c;
      }
      else {
        local_aa0 = thunk_FUN_1000b540(&local_244,L"Module_Raw",(int)local_668);
        local_254 = local_aa0;
        if (local_aa0 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          thunk_FUN_10012c90((int *)local_230);
          local_8 = 0xffffffff;
          thunk_FUN_1000b460(&local_244);
          local_a8c = local_aa0;
        }
        else {
          local_250 = L"REGISTRY";
          if (param_3 == 0) {
            local_b40 = thunk_FUN_1000b9d0(&local_244,local_258,param_2,L"REGISTRY");
          }
          else {
            local_b40 = thunk_FUN_1000b620(&local_244,local_258,param_2,L"REGISTRY");
          }
          local_24c = local_b40;
          local_aa4 = local_b40;
          local_8 = CONCAT31(local_8._1_3_,1);
          thunk_FUN_10012c90((int *)local_230);
          local_8 = 0xffffffff;
          thunk_FUN_1000b460(&local_244);
          local_a8c = local_aa4;
        }
      }
    }
  }
  ExceptionList = local_10;
  return local_a8c;
}



// Function: AtlHresultFromLastError at 1000ad50

/* Library Function - Single Match
    long __cdecl ATL::AtlHresultFromLastError(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

long __cdecl ATL::AtlHresultFromLastError(void)

{
  undefined4 local_c;
  
  local_c = GetLastError();
  if (0 < (int)local_c) {
    local_c = local_c & 0xffff | 0x80070000;
  }
  return local_c;
}



// Function: FUN_1000ada0 at 1000ada0

void __cdecl FUN_1000ada0(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  uint local_8;
  
  if (param_2 != 0) {
    local_8 = 0;
    for (; (local_8 < param_2 - 1U && (*param_3 != 0)); param_3 = param_3 + 1) {
      *param_1 = *param_3;
      psVar1 = param_1 + 1;
      if ((*param_3 == 0x27) && (local_8 = local_8 + 1, local_8 < param_2 - 1U)) {
        *psVar1 = *param_3;
        psVar1 = param_1 + 2;
      }
      param_1 = psVar1;
      local_8 = local_8 + 1;
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000ae70 at 1000ae70

void __fastcall FUN_1000ae70(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100212f8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1000b330(param_1);
  local_8 = 0xffffffff;
  thunk_FUN_10012e90(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aed0 at 1000aed0

undefined4 FUN_1000aed0(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021320;
  pvStack_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &pvStack_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1001db00(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_1000af62();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000af55 at 1000af55

undefined4 Catch_1000af55(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000af69;
}



// Function: FUN_1000af62 at 1000af62

void FUN_1000af62(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
  iVar2 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x18) = iVar2 * 2 + 2;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar1 = (ulonglong)*(uint *)(unaff_EBP + -0x18) * 2;
  uVar3 = FUN_1001db00(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x34);
  FUN_1000afdd();
  return;
}



// Function: Catch@1000afd0 at 1000afd0

undefined4 Catch_1000afd0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x1000afe4;
}



// Function: FUN_1000afdd at 1000afdd

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_1000afdd(void)

{
  errno_t eVar1;
  int iVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
  if ((*(int *)(unaff_EBP + -0x2c) == 0) || (*(int *)(unaff_EBP + -0x28) == 0)) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x2c);
    eVar1 = memcpy_s(*(void **)(unaff_EBP + -0x40),*(rsize_t *)(unaff_EBP + -0x14),
                     *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x14));
    *(errno_t *)(unaff_EBP + -0x3c) = eVar1;
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x3c);
    switch(*(undefined4 *)(unaff_EBP + -0x7c)) {
    case 0:
    case 0x50:
      break;
    default:
      thunk_FUN_10004720(0x80004005);
      break;
    case 0xc:
      thunk_FUN_10004720(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      thunk_FUN_10004720(0x80070057);
    }
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x28);
    eVar1 = memcpy_s(*(void **)(unaff_EBP + -0x48),*(rsize_t *)(unaff_EBP + -0x18),
                     *(void **)(unaff_EBP + 0xc),*(rsize_t *)(unaff_EBP + -0x18));
    *(errno_t *)(unaff_EBP + -0x44) = eVar1;
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x44);
    switch(*(undefined4 *)(unaff_EBP + -0x80)) {
    case 0:
    case 0x50:
      break;
    default:
      thunk_FUN_10004720(0x80004005);
      break;
    case 0xc:
      thunk_FUN_10004720(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      thunk_FUN_10004720(0x80070057);
    }
    iVar2 = thunk_FUN_10012d00(*(void **)(unaff_EBP + -0x78),(undefined4 *)(unaff_EBP + -0x2c),
                               (undefined4 *)(unaff_EBP + -0x28));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
    }
  }
  if (-1 < *(int *)(unaff_EBP + -0x20)) {
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
  }
  *(uint *)(unaff_EBP + -0x38) = (uint)(-1 < *(int *)(unaff_EBP + -0x20));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x24);
  operator_delete__(*(void **)(unaff_EBP + -0x70));
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x1c);
  operator_delete__(*(void **)(unaff_EBP + -0x74));
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x38);
}



// Function: FUN_1000b330 at 1000b330

undefined4 __fastcall FUN_1000b330(int *param_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < param_1[2]; local_8 = local_8 + 1) {
    if ((local_8 < 0) || (param_1[2] <= local_8)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    operator_delete__(*(void **)(*param_1 + local_8 * 4));
    if ((local_8 < 0) || (param_1[2] <= local_8)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    operator_delete__(*(void **)(param_1[1] + local_8 * 4));
  }
  thunk_FUN_10012e90(param_1);
  return 0;
}



// Function: FUN_1000b430 at 1000b430

undefined4 FUN_1000b430(void)

{
  return 0x80004001;
}



// Function: FUN_1000b440 at 1000b440

undefined4 FUN_1000b440(void)

{
  return 1;
}



// Function: FUN_1000b450 at 1000b450

undefined4 FUN_1000b450(void)

{
  return 0;
}



// Function: FUN_1000b460 at 1000b460

void __fastcall FUN_1000b460(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021343;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  thunk_FUN_1000b330(param_1 + 1);
  local_8 = 1;
  thunk_FUN_1000b330(param_1 + 1);
  local_8 = 0xffffffff;
  thunk_FUN_10012e90(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b500 at 1000b500

undefined4 * __thiscall FUN_1000b500(void *this,uint param_1)

{
  thunk_FUN_1000b460((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b540 at 1000b540

int FUN_1000b540(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021368;
  local_10 = ExceptionList;
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    local_24 = (undefined4 *)0x0;
    local_8 = 0;
    ExceptionList = &local_10;
    iVar2 = thunk_FUN_1000aed0(param_2,param_3);
    iVar2 = (-(uint)(iVar2 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    while (local_24 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_24;
      free(local_24);
      local_24 = puVar1;
    }
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_1000b620 at 1000b620

long FUN_1000b620(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  long lVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021388;
  local_10 = ExceptionList;
  local_24 = (undefined4 *)0x0;
  local_8 = 0;
  ExceptionList = &local_10;
  lVar2 = thunk_FUN_1000b6d0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (local_24 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_24;
    free(local_24);
    local_24 = puVar1;
  }
  ExceptionList = local_10;
  return lVar2;
}



// Function: FUN_1000b6d0 at 1000b6d0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

long FUN_1000b6d0(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  undefined4 *_Memory;
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  long lVar2;
  long local_458;
  undefined1 *local_44c;
  undefined1 auStack_448 [1032];
  undefined4 *local_40;
  undefined4 local_38;
  DWORD local_30;
  undefined4 local_2c;
  HMODULE local_24;
  HGLOBAL local_20;
  LPCWSTR local_1c;
  undefined4 uStack_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100213b3;
  pvStack_10 = ExceptionList;
  uStack_18 = 0x1000b6f3;
  local_14 = &stack0xffffdb60;
  local_38 = 3;
  local_40 = (undefined4 *)0x0;
  local_2c = 0;
  local_44c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_1c = param_1;
  ExceptionList = &pvStack_10;
  local_24 = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_24 == (HMODULE)0x0) {
    local_458 = ATL::AtlHresultFromLastError();
  }
  else {
    hResInfo = FindResourceW(local_24,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      local_458 = ATL::AtlHresultFromLastError();
    }
    else {
      pvVar1 = LoadResource(local_24,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        local_458 = ATL::AtlHresultFromLastError();
      }
      else {
        local_30 = SizeofResource(local_24,hResInfo);
        local_20 = pvVar1;
        if (local_30 <= local_30 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          thunk_FUN_10012ff0(&local_44c,local_30 + 1);
          lVar2 = FUN_1000b81c();
          return lVar2;
        }
        local_458 = -0x7ff8fff2;
      }
    }
  }
  if (local_24 != (HMODULE)0x0) {
    FreeLibrary(local_24);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_44c != auStack_448) {
    thunk_FUN_10013310(&local_44c);
  }
  local_8 = 0xffffffff;
  while (_Memory = local_40, local_40 != (undefined4 *)0x0) {
    local_40 = (undefined4 *)*local_40;
    free(_Memory);
  }
  ExceptionList = pvStack_10;
  return local_458;
}



// Function: Catch@1000b80f at 1000b80f

undefined4 Catch_1000b80f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000b823;
}



// Function: FUN_1000b81c at 1000b81c

undefined4 FUN_1000b81c(void)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + -0x448) == 0) {
    *(undefined4 *)(unaff_EBP + -0x454) = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x46c) = *(undefined4 *)(unaff_EBP + -0x448);
    iVar1 = MultiByteToWideChar(3,0,*(LPCSTR *)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x2c),
                                *(LPWSTR *)(unaff_EBP + -0x46c),*(int *)(unaff_EBP + -0x2c));
    *(int *)(unaff_EBP + -0x44c) = iVar1;
    if (*(int *)(unaff_EBP + -0x44c) == 0) {
      lVar2 = ATL::AtlHresultFromLastError();
      *(long *)(unaff_EBP + -0x454) = lVar2;
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x448) + *(int *)(unaff_EBP + -0x44c) * 2) = 0;
      *(undefined4 *)(unaff_EBP + -0x470) = *(undefined4 *)(unaff_EBP + -0x448);
      iVar1 = thunk_FUN_1000bab0((void *)(unaff_EBP + -0x28),*(LPCWSTR *)(unaff_EBP + -0x470),
                                 *(int *)(unaff_EBP + 0x14));
      *(int *)(unaff_EBP + -0x454) = iVar1;
    }
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -0x45c) = *(undefined4 *)(unaff_EBP + -0x454);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x448) != unaff_EBP + -0x444) {
    thunk_FUN_10013310((undefined4 *)(unaff_EBP + -0x448));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  while (*(int *)(unaff_EBP + -0x3c) != 0) {
    *(undefined4 *)(unaff_EBP + -0x248c) = *(undefined4 *)(unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -0x3c) = **(undefined4 **)(unaff_EBP + -0x3c);
    free(*(void **)(unaff_EBP + -0x248c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x45c);
}



// Function: FUN_1000b9d0 at 1000b9d0

long FUN_1000b9d0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  long lVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100213d8;
  local_10 = ExceptionList;
  local_24 = (undefined4 *)0x0;
  local_8 = 0;
  ExceptionList = &local_10;
  lVar2 = thunk_FUN_1000b6d0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (local_24 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_24;
    free(local_24);
    local_24 = puVar1;
  }
  ExceptionList = local_10;
  return lVar2;
}



// Function: FUN_1000ba80 at 1000ba80

undefined4 FUN_1000ba80(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = thunk_FUN_1000b330((int *)(param_1 + 4));
  return uVar1;
}



// Function: FUN_1000bab0 at 1000bab0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall FUN_1000bab0(void *this,LPCWSTR param_1,int param_2)

{
  undefined4 uVar1;
  HKEY pHVar2;
  WCHAR local_200c [4096];
  int local_c;
  LPVOID local_8;
  
  local_c = 0;
  local_8 = (LPVOID)0x0;
  local_c = thunk_FUN_1000c0f0(this,param_1,&local_8);
  if (-1 < local_c) {
    *(LPVOID *)this = local_8;
    while( true ) {
                    /* WARNING: Load size is inaccurate */
      if ((**this == 0) || (local_c = thunk_FUN_1000bdd0(this,local_200c), local_c < 0))
      goto LAB_1000bc3a;
      pHVar2 = (HKEY)thunk_FUN_1000bcc0(local_200c);
      if (pHVar2 == (HKEY)0x0) break;
      local_c = thunk_FUN_1000bdd0(this,local_200c);
      if (local_c < 0) goto LAB_1000bc3a;
      if (local_200c[0] != L'{') {
        local_c = -0x7ffdfff7;
        goto LAB_1000bc3a;
      }
      if (param_2 == 0) {
        local_c = thunk_FUN_1000cef0(this,local_200c,pHVar2,0,0);
        if (local_c < 0) goto LAB_1000bc3a;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar1 = *this;
        local_c = thunk_FUN_1000cef0(this,local_200c,pHVar2,param_2,0);
        if (local_c < 0) {
          *(undefined4 *)this = uVar1;
          thunk_FUN_1000cef0(this,local_200c,pHVar2,0,0);
          goto LAB_1000bc3a;
        }
      }
      thunk_FUN_1000bd20((undefined4 *)this);
    }
    local_c = -0x7ffdfff7;
LAB_1000bc3a:
    CoTaskMemFree(local_8);
  }
  return local_c;
}



// Function: FUN_1000bcc0 at 1000bcc0

undefined4 __cdecl FUN_1000bcc0(LPCWSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_100292d0)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_100292d4 + local_8 * 8);
}



// Function: FUN_1000bd20 at 1000bd20

void __fastcall FUN_1000bd20(undefined4 *param_1)

{
  bool bVar1;
  LPWSTR pWVar2;
  
  while( true ) {
    switch(*(undefined2 *)*param_1) {
    case 9:
    case 10:
    case 0xd:
    case 0x20:
      bVar1 = true;
      break;
    default:
      bVar1 = false;
    }
    if (!bVar1) break;
    pWVar2 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar2;
  }
  return;
}



// Function: FUN_1000bdd0 at 1000bdd0

undefined4 __thiscall FUN_1000bdd0(void *this,undefined2 *param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int local_20;
  undefined2 *local_18;
  int local_14;
  undefined2 *local_c;
  
  puVar2 = param_1;
  thunk_FUN_1000bd20((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  if (**this == 0) {
    uVar3 = 0x80020009;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (**this == 0x27) {
                    /* WARNING: Load size is inaccurate */
      pWVar4 = CharNextW(*this);
      *(LPWSTR *)this = pWVar4;
                    /* WARNING: Load size is inaccurate */
      while (**this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        if ((**this == 0x27) && (pWVar4 = CharNextW(*this), *pWVar4 != L'\'')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) break;
                    /* WARNING: Load size is inaccurate */
        if (**this == 0x27) {
                    /* WARNING: Load size is inaccurate */
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
        }
                    /* WARNING: Load size is inaccurate */
        local_c = *this;
                    /* WARNING: Load size is inaccurate */
        pWVar4 = CharNextW(*this);
        *(LPWSTR *)this = pWVar4;
                    /* WARNING: Load size is inaccurate */
        iVar5 = *this - (int)local_c >> 1;
        if (puVar2 + 0x1000 <= param_1 + iVar5 + 1) {
          return 0x80020009;
        }
        for (local_14 = 0; local_14 < iVar5; local_14 = local_14 + 1) {
          *param_1 = *local_c;
          param_1 = param_1 + 1;
          local_c = local_c + 1;
        }
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == 0) {
        return 0x80020009;
      }
      *param_1 = 0;
                    /* WARNING: Load size is inaccurate */
      pWVar4 = CharNextW(*this);
      *(LPWSTR *)this = pWVar4;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      while (**this != 0) {
                    /* WARNING: Load size is inaccurate */
        switch(**this) {
        case 9:
        case 10:
        case 0xd:
        case 0x20:
          bVar1 = true;
          break;
        default:
          bVar1 = false;
        }
        if (bVar1) break;
                    /* WARNING: Load size is inaccurate */
        local_18 = *this;
                    /* WARNING: Load size is inaccurate */
        pWVar4 = CharNextW(*this);
        *(LPWSTR *)this = pWVar4;
                    /* WARNING: Load size is inaccurate */
        iVar5 = *this - (int)local_18 >> 1;
        if (puVar2 + 0x1000 <= param_1 + iVar5 + 1) {
          return 0x80020009;
        }
        for (local_20 = 0; local_20 < iVar5; local_20 = local_20 + 1) {
          *param_1 = *local_18;
          param_1 = param_1 + 1;
          local_18 = local_18 + 1;
        }
      }
      *param_1 = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_1000c0f0 at 1000c0f0

int __thiscall FUN_1000c0f0(void *this,LPCWSTR param_1,undefined4 *param_2)

{
  bool bVar1;
  LPVOID pvVar2;
  LPWSTR pWVar3;
  int iVar4;
  undefined4 *puVar5;
  wchar_t *local_144;
  int local_140;
  void *local_13c;
  int local_128;
  LPCWSTR local_124;
  wchar_t *local_120;
  errno_t local_11c;
  errno_t local_118;
  LPCWSTR local_114;
  LPCWSTR local_110;
  void *local_10c;
  undefined4 local_108;
  void *local_dc;
  undefined4 local_d8;
  wchar_t *local_b0;
  int local_9c;
  int local_98;
  int local_94;
  rsize_t local_90;
  LPCWSTR local_8c;
  wchar_t local_88 [34];
  LPCWSTR local_44;
  wchar_t *local_40;
  wchar_t *local_3c;
  wchar_t *local_38;
  char local_31;
  int local_30;
  char local_29;
  undefined4 local_28;
  undefined4 local_24;
  LPVOID local_20;
  char local_19;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100213f8;
  local_10 = ExceptionList;
  if ((param_1 == (LPCWSTR)0x0) || (param_2 == (undefined4 *)0x0)) {
    local_94 = -0x7fffbffd;
  }
  else {
    ExceptionList = &local_10;
    *param_2 = 0;
    local_18 = lstrlenW(param_1);
    local_18 = local_18 << 1;
    thunk_FUN_1000c9a0(&local_28,local_18);
    local_8 = 0;
    if (local_20 == (LPVOID)0x0) {
      local_94 = -0x7ff8fff2;
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_31 = '\0';
      if (&stack0x00000000 == (undefined1 *)0x31) {
        local_30 = -0x7fffbffd;
      }
      else {
        local_31 = DAT_10033e10;
        local_30 = 0;
      }
      if (local_30 < 0) {
        local_98 = local_30;
        local_8 = 0xffffffff;
        CoTaskMemFree(local_20);
        local_94 = local_98;
      }
      else {
        local_14 = 0;
        local_29 = '\0';
        local_19 = '\0';
                    /* WARNING: Load size is inaccurate */
        while (**this != 0) {
          if (local_31 == '\x01') {
            local_3c = L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses";
            local_38 = L"\r\n\t}\r\n}\r\n";
            if (local_14 == 0) {
              local_40 = (wchar_t *)0x0;
                    /* WARNING: Load size is inaccurate */
              local_b0 = *this;
              local_40 = wcsstr(local_b0,L"HKCR");
                    /* WARNING: Load size is inaccurate */
              if ((local_40 != (wchar_t *)0x0) && (local_40 == *this)) {
                    /* WARNING: Load size is inaccurate */
                pWVar3 = CharNextW(*this);
                *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
                pWVar3 = CharNextW(*this);
                *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
                pWVar3 = CharNextW(*this);
                *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
                pWVar3 = CharNextW(*this);
                *(LPWSTR *)this = pWVar3;
                iVar4 = thunk_FUN_1000cde0(&local_28,local_3c);
                if (iVar4 == 0) {
                  local_30 = -0x7ff8fff2;
                  break;
                }
                local_29 = '\x01';
              }
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_19 == '\0') {
                local_19 = '\x01';
              }
              else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                if ((**this == 0x27) && (pWVar3 = CharNextW(*this), *pWVar3 != L'\'')) {
                  bVar1 = true;
                }
                else {
                  bVar1 = false;
                }
                if (bVar1) {
                  local_19 = '\0';
                }
                else {
                    /* WARNING: Load size is inaccurate */
                  pWVar3 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
                  local_dc = *this;
                  local_d8 = 1;
                  iVar4 = thunk_FUN_1000cae0(&local_28,local_dc,1);
                  if (iVar4 == 0) {
                    local_30 = -0x7ff8fff2;
                    break;
                  }
                }
              }
            }
                    /* WARNING: Load size is inaccurate */
            if ((local_19 == '\0') && (**this == 0x7b)) {
              local_14 = local_14 + 1;
            }
                    /* WARNING: Load size is inaccurate */
            if ((((local_19 == '\0') && (**this == 0x7d)) &&
                (local_14 = local_14 + -1, local_14 == 0)) && (local_29 == '\x01')) {
              iVar4 = thunk_FUN_1000cde0(&local_28,local_38);
              if (iVar4 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
              local_29 = '\0';
            }
          }
                    /* WARNING: Load size is inaccurate */
          if (**this == 0x25) {
                    /* WARNING: Load size is inaccurate */
            pWVar3 = CharNextW(*this);
            *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x25) {
                    /* WARNING: Load size is inaccurate */
              local_10c = *this;
              local_108 = 1;
              iVar4 = thunk_FUN_1000cae0(&local_28,local_10c,1);
              if (iVar4 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
            }
            else {
                    /* WARNING: Load size is inaccurate */
              local_114 = *this;
              local_110 = (LPCWSTR)0x0;
              if (local_114 == (LPCWSTR)0x0) {
                local_8c = (LPCWSTR)0x0;
              }
              else {
                for (; *local_114 != L'\0'; local_114 = CharNextW(local_114)) {
                  if (*local_114 == L'%') {
                    local_110 = local_114;
                    break;
                  }
                }
                local_8c = local_110;
              }
              local_110 = local_8c;
              if (local_8c == (LPCWSTR)0x0) {
                local_30 = -0x7ffdfff7;
                break;
              }
                    /* WARNING: Load size is inaccurate */
              if (0x1f < (int)local_8c - *this >> 1) {
                local_30 = -0x7fffbffb;
                break;
              }
                    /* WARNING: Load size is inaccurate */
              local_90 = (int)local_8c - *this >> 1;
                    /* WARNING: Load size is inaccurate */
              local_120 = *this;
              local_118 = wcsncpy_s(local_88,0x20,local_120,local_90);
              switch(local_118) {
              case 0:
              case 0x50:
                break;
              default:
                thunk_FUN_10004720(0x80004005);
                break;
              case 0xc:
                thunk_FUN_10004720(0x8007000e);
                break;
              case 0x16:
              case 0x22:
                thunk_FUN_10004720(0x80070057);
              }
              local_11c = local_118;
              local_144 = local_88;
              local_140 = *(int *)((int)this + 4);
              local_13c = (void *)(local_140 + 4);
              local_128 = thunk_FUN_10013280(local_13c,&local_144);
              if (local_128 == -1) {
                local_124 = (LPCWSTR)0x0;
              }
              else {
                puVar5 = (undefined4 *)thunk_FUN_10012f30(local_13c,local_128);
                local_124 = (LPCWSTR)*puVar5;
              }
              local_44 = local_124;
              if (local_124 == (LPCWSTR)0x0) {
                local_30 = -0x7ffdfff7;
                break;
              }
              iVar4 = thunk_FUN_1000cde0(&local_28,local_124);
              if (iVar4 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
                    /* WARNING: Load size is inaccurate */
              while (*this != local_8c) {
                    /* WARNING: Load size is inaccurate */
                pWVar3 = CharNextW(*this);
                *(LPWSTR *)this = pWVar3;
              }
            }
          }
          else {
                    /* WARNING: Load size is inaccurate */
            iVar4 = thunk_FUN_1000cae0(&local_28,*this,1);
            if (iVar4 == 0) {
              local_30 = -0x7ff8fff2;
              break;
            }
          }
                    /* WARNING: Load size is inaccurate */
          pWVar3 = CharNextW(*this);
          *(LPWSTR *)this = pWVar3;
        }
        pvVar2 = local_20;
        if (-1 < local_30) {
          local_20 = (LPVOID)0x0;
          local_28 = 0;
          local_24 = 0;
          *param_2 = pvVar2;
        }
        local_9c = local_30;
        local_8 = 0xffffffff;
        CoTaskMemFree(local_20);
        local_94 = local_9c;
      }
    }
  }
  ExceptionList = local_10;
  return local_94;
}



// Function: FUN_1000c9a0 at 1000c9a0

undefined4 * __thiscall FUN_1000c9a0(void *this,int param_1)

{
  LPVOID pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = thunk_FUN_1000ca20(*(uint *)((int)this + 4),2);
  *(LPVOID *)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined2 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000ca20 at 1000ca20

/* WARNING: Removing unreachable block (ram,0x1000ca50) */

LPVOID __cdecl FUN_1000ca20(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  if (local_10 == 0) {
    local_14 = (SIZE_T)((ulonglong)param_1 * (ulonglong)param_2);
    local_8 = local_14;
    local_c = 0;
  }
  else {
    local_c = -0x7ff8fdea;
  }
  if (local_c < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemAlloc(local_8);
  }
  return pvVar1;
}



// Function: FUN_1000cac0 at 1000cac0

void __fastcall FUN_1000cac0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_1000cae0 at 1000cae0

undefined4 __thiscall FUN_1000cae0(void *this,void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  errno_t eVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
                    /* WARNING: Load size is inaccurate */
  if ((*this < iVar1) && (param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      while (*(int *)((int)this + 4) <= iVar1) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
      }
      pvVar3 = thunk_FUN_1000cd30(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),2);
      if (pvVar3 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar3;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((*this < 0) || (*(int *)((int)this + 4) <= *this)) ||
       (*(int *)((int)this + 4) < *(int *)((int)this + 4) - *this)) {
      uVar2 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      eVar4 = memcpy_s((void *)(*(int *)((int)this + 8) + *this * 2),
                       (*(int *)((int)this + 4) - *this) * 2,param_1,param_2 << 1);
      switch(eVar4) {
      case 0:
      case 0x50:
        break;
      default:
        thunk_FUN_10004720(0x80004005);
        break;
      case 0xc:
        thunk_FUN_10004720(0x8007000e);
        break;
      case 0x16:
      case 0x22:
        thunk_FUN_10004720(0x80070057);
      }
                    /* WARNING: Load size is inaccurate */
      *(int *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*(int *)((int)this + 8) + *this * 2) = 0;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000cd30 at 1000cd30

/* WARNING: Removing unreachable block (ram,0x1000cd60) */

LPVOID __cdecl FUN_1000cd30(LPVOID param_1,uint param_2,uint param_3)

{
  LPVOID pvVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_10 == 0) {
    local_14 = (SIZE_T)((ulonglong)param_2 * (ulonglong)param_3);
    local_8 = local_14;
    local_c = 0;
  }
  else {
    local_c = -0x7ff8fdea;
  }
  if (local_c < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemRealloc(param_1,local_8);
  }
  return pvVar1;
}



// Function: FUN_1000cde0 at 1000cde0

undefined4 __thiscall FUN_1000cde0(void *this,LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021418;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    local_2c = 0;
  }
  else {
    local_24 = (undefined4 *)0x0;
    local_8 = 0;
    if (param_1 == (LPCWSTR)0x0) {
      local_2c = 0;
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      while (local_24 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*local_24;
        free(local_24);
        local_24 = puVar1;
      }
    }
    else {
      ExceptionList = &local_10;
      iVar2 = lstrlenW(param_1);
      local_2c = thunk_FUN_1000cae0(this,param_1,iVar2);
      local_8 = 0xffffffff;
      while (local_24 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*local_24;
        free(local_24);
        local_24 = puVar1;
      }
    }
  }
  ExceptionList = local_10;
  return local_2c;
}



// Function: FUN_1000cef0 at 1000cef0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall FUN_1000cef0(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  LPCWSTR pWVar4;
  HRESULT HVar5;
  errno_t eVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_22d8;
  LPCWSTR local_22d0;
  LPCWSTR local_22cc;
  undefined4 local_2270;
  undefined4 local_226c;
  undefined4 local_2268;
  int local_2264;
  HKEY local_2260;
  undefined4 local_225c;
  undefined4 local_2258;
  HKEY local_2254;
  undefined4 local_2250;
  undefined4 local_224c;
  WCHAR local_2248 [4096];
  HKEY local_248;
  undefined4 local_244;
  undefined4 local_240;
  uint local_23c;
  wchar_t local_238 [262];
  int local_2c;
  int local_28;
  ulong local_24;
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021464;
  local_10 = ExceptionList;
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  local_8 = 0;
  local_14 = 1;
  local_28 = param_4;
  local_2c = 0;
  ExceptionList = &local_10;
  iVar3 = thunk_FUN_1000bdd0(this,param_1);
  local_2c = iVar3;
  if (iVar3 < 0) {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_20);
    ExceptionList = local_10;
    return iVar3;
  }
LAB_1000cf83:
  if (*param_1 == L'}') goto LAB_1000d8dd;
  local_14 = 1;
  iVar3 = lstrcmpiW(param_1,L"Delete");
  local_23c = (uint)(iVar3 == 0);
  iVar3 = lstrcmpiW(param_1,L"ForceRemove");
  if ((iVar3 == 0) || (local_23c != 0)) {
    local_2c = thunk_FUN_1000bdd0(this,param_1);
    if (-1 < local_2c) {
      if (param_3 == 0) goto LAB_1000d21a;
      local_248 = (HKEY)0x0;
      local_244 = 0;
      local_240 = 0;
      local_8._0_1_ = 1;
      local_22d0 = param_1;
      local_22cc = (LPCWSTR)0x0;
      if (param_1 != (LPCWSTR)0x0) {
        for (; *local_22d0 != L'\0'; local_22d0 = CharNextW(local_22d0)) {
          if (*local_22d0 == L'\\') {
            local_22cc = local_22d0;
            break;
          }
        }
      }
      if (local_22cc != (LPCWSTR)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_248);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        ExceptionList = local_10;
        return -0x7ffdfff7;
      }
      for (local_22d8 = 0; local_22d8 < 0xc; local_22d8 = local_22d8 + 1) {
        iVar3 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10028d00)[local_22d8]);
        if (iVar3 == 0) {
          bVar2 = false;
          goto LAB_1000d12f;
        }
      }
      bVar2 = true;
LAB_1000d12f:
      if (bVar2) {
        local_248 = param_2;
        local_244 = 0;
        local_240 = 0;
        thunk_FUN_1000e230(&local_248,param_1);
        local_248 = (HKEY)0x0;
        local_244 = 0;
        local_240 = 0;
      }
      if (local_23c == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_248);
        goto LAB_1000d21a;
      }
      local_2c = thunk_FUN_1000bdd0(this,param_1);
      if (local_2c < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_248);
      }
      else {
        local_2c = thunk_FUN_1000f0a0(this,param_1);
        if (-1 < local_2c) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_248);
          uVar1 = local_24;
          goto LAB_1000d87a;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_248);
      }
    }
    goto LAB_1000d8dd;
  }
LAB_1000d21a:
  iVar3 = lstrcmpiW(param_1,L"NoRemove");
  if (iVar3 == 0) {
    local_14 = 0;
    local_2c = thunk_FUN_1000bdd0(this,param_1);
    if (local_2c < 0) goto LAB_1000d8dd;
  }
  iVar3 = lstrcmpiW(param_1,L"Val");
  if (iVar3 == 0) {
    local_2c = thunk_FUN_1000bdd0(this,local_2248);
    if ((local_2c < 0) || (local_2c = thunk_FUN_1000bdd0(this,param_1), local_2c < 0))
    goto LAB_1000d8dd;
    if (*param_1 != L'=') {
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_20);
      ExceptionList = local_10;
      return -0x7ffdfff7;
    }
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_2254 = param_2;
      local_2250 = 0;
      local_224c = 0;
      iVar3 = thunk_FUN_1000e530(this,&local_2254,local_2248,param_1);
      local_2254 = (HKEY)0x0;
      local_2250 = 0;
      local_224c = 0;
      local_2c = iVar3;
      if (iVar3 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2254);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        ExceptionList = local_10;
        return iVar3;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2254);
      uVar1 = local_24;
      goto LAB_1000d87a;
    }
    if ((param_4 == 0) && (local_14 != 0)) {
      local_2260 = (HKEY)0x0;
      local_225c = 0;
      local_2258 = 0;
      local_8._0_1_ = 3;
      local_24 = thunk_FUN_1000e090(&local_2260,param_2,(LPCWSTR)0x0,0x20006);
      if (local_24 != 0) {
        local_2c = _HRESULT_FROM_WIN32(local_24);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2260);
        goto LAB_1000d8dd;
      }
      local_24 = RegDeleteValueW(local_2260,local_2248);
      if ((local_24 != 0) && (local_24 != 2)) {
        local_2c = _HRESULT_FROM_WIN32(local_24);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2260);
        goto LAB_1000d8dd;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2260);
    }
    local_2c = thunk_FUN_1000f0a0(this,param_1);
joined_r0x1000d4b1:
    if (local_2c < 0) goto LAB_1000d8dd;
    goto LAB_1000cf83;
  }
  pWVar4 = thunk_FUN_1000e4d0(param_1,L'\\');
  if (pWVar4 != (LPCWSTR)0x0) {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_20);
    ExceptionList = local_10;
    return -0x7ffdfff7;
  }
  if (param_3 == 0) {
    if (param_4 == 0) {
      local_24 = thunk_FUN_1000e090(&local_20,param_2,param_1,0x20019);
    }
    else {
      local_24 = 2;
    }
    if (local_24 != 0) {
      param_4 = 1;
    }
    eVar6 = wcsncpy_s(local_238,0x104,param_1,0xffffffff);
    ATL::AtlCrtErrorCheck(eVar6);
    local_2c = thunk_FUN_1000bdd0(this,param_1);
    if (((local_2c < 0) || (local_2c = thunk_FUN_1000f0a0(this,param_1), local_2c < 0)) ||
       (((*param_1 == L'{' && (iVar3 = lstrlenW(param_1), iVar3 == 1)) &&
        (((local_2c = thunk_FUN_1000cef0(this,param_1,local_20,0,param_4), local_2c < 0 &&
          (param_4 == 0)) || (local_2c = thunk_FUN_1000bdd0(this,param_1), local_2c < 0))))))
    goto LAB_1000d8dd;
    param_4 = local_28;
    if (local_24 == 2) goto LAB_1000cf83;
    if (local_24 != 0) {
      if (local_28 == 0) {
        local_2c = _HRESULT_FROM_WIN32(local_24);
LAB_1000d8dd:
        iVar3 = local_2c;
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        ExceptionList = local_10;
        return iVar3;
      }
      goto LAB_1000cf83;
    }
    if ((local_28 != 0) && (bVar2 = thunk_FUN_1000f040(local_20), CONCAT31(extraout_var,bVar2) != 0)
       ) {
      iVar3 = thunk_FUN_1000efe0(local_238);
      if ((iVar3 != 0) && (local_14 != 0)) {
        thunk_FUN_1000e230(&local_20,local_238);
      }
      goto LAB_1000cf83;
    }
    bVar2 = thunk_FUN_1000f040(local_20);
    local_2264 = CONCAT31(extraout_var_00,bVar2);
    local_24 = ATL::CRegKey::Close((CRegKey *)&local_20);
    if (local_24 != 0) {
      HVar5 = _HRESULT_FROM_WIN32(local_24);
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_20);
      ExceptionList = local_10;
      return HVar5;
    }
    uVar1 = 0;
    if ((local_14 != 0) && (local_2264 == 0)) {
      local_2270 = 0;
      local_226c = 0;
      local_2268 = 0;
      local_8._0_1_ = 4;
      thunk_FUN_1000dd10(&local_2270,param_2);
      local_24 = thunk_FUN_1000dd50(&local_2270,local_238);
      local_2270 = 0;
      local_226c = 0;
      local_2268 = 0;
      if (local_24 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2270);
        uVar1 = local_24;
        goto LAB_1000d87a;
      }
      local_2c = _HRESULT_FROM_WIN32(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2270);
      goto LAB_1000d8dd;
    }
  }
  else {
    local_24 = thunk_FUN_1000e090(&local_20,param_2,param_1,0x2001f);
    if (((local_24 != 0) &&
        (local_24 = thunk_FUN_1000e090(&local_20,param_2,param_1,0x20019), local_24 != 0)) &&
       (local_24 = thunk_FUN_1000dec0(&local_20,param_2,param_1,(LPWSTR)0x0,0,0x2001f,
                                      (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_24 != 0)) {
      HVar5 = _HRESULT_FROM_WIN32(local_24);
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_20);
      ExceptionList = local_10;
      return HVar5;
    }
    local_2c = thunk_FUN_1000bdd0(this,param_1);
    if ((local_2c < 0) ||
       ((uVar1 = local_24, *param_1 == L'=' &&
        (local_2c = thunk_FUN_1000e530(this,&local_20,(LPCWSTR)0x0,param_1), uVar1 = local_24,
        local_2c < 0)))) goto LAB_1000d8dd;
  }
LAB_1000d87a:
  local_24 = uVar1;
  if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
    local_2c = thunk_FUN_1000cef0(this,param_1,local_20,param_3,0);
    if (-1 < local_2c) {
      local_2c = thunk_FUN_1000bdd0(this,param_1);
      goto joined_r0x1000d4b1;
    }
    goto LAB_1000d8dd;
  }
  goto LAB_1000cf83;
}



// Function: AtlCrtErrorCheck at 1000dba0

/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual
   Studio 2012 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    thunk_FUN_10004720(0x80004005);
    break;
  case 0xc:
    thunk_FUN_10004720(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    thunk_FUN_10004720(0x80070057);
  }
  return param_1;
}



// Function: _HRESULT_FROM_WIN32 at 1000dc80

/* Library Function - Single Match
    _HRESULT_FROM_WIN32
   
   Library: Visual Studio */

HRESULT __cdecl _HRESULT_FROM_WIN32(ulong x)

{
  undefined4 local_8;
  
  if ((int)x < 1) {
    local_8 = x;
  }
  else {
    local_8 = x & 0xffff | 0x80070000;
  }
  return local_8;
}



// Function: FUN_1000dcc0 at 1000dcc0

void __fastcall FUN_1000dcc0(int *param_1)

{
  if (*param_1 != 0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_1000dd10 at 1000dd10

void __thiscall FUN_1000dd10(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_1000dd50 at 1000dd50

void __thiscall FUN_1000dd50(void *this,LPCWSTR param_1)

{
  if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
    RegDeleteKeyW(*this,param_1);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    thunk_FUN_1000ddb0(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_1000ddb0 at 1000ddb0

LSTATUS __thiscall FUN_1000ddb0(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: Close at 1000de60

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

long __thiscall ATL::CRegKey::Close(CRegKey *this)

{
  LSTATUS local_8;
  
  local_8 = 0;
  if (*(int *)this != 0) {
    local_8 = RegCloseKey(*(HKEY *)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return local_8;
}



// Function: FUN_1000dec0 at 1000dec0

LSTATUS __thiscall
FUN_1000dec0(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  int *piVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int local_2c;
  LSTATUS local_24;
  DWORD local_10;
  LSTATUS local_c;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(int *)((int)this + 8) == 0) {
    local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,&local_10)
    ;
    goto LAB_1000dfca;
  }
  piVar1 = *(int **)((int)this + 8);
  if (*piVar1 == 0) {
    if (piVar1[1] != 0) {
      local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,
                                 &local_10);
      goto LAB_1000dfca;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      local_2c = 1;
      goto LAB_1000dfca;
    }
    pFVar2 = GetProcAddress(hModule,"RegCreateKeyTransactedW");
    if (pFVar2 != (FARPROC)0x0) {
      local_2c = (*pFVar2)(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,&local_10,
                           *piVar1,0);
      goto LAB_1000dfca;
    }
  }
  local_2c = 1;
LAB_1000dfca:
  local_c = local_2c;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_10;
  }
  if (local_2c == 0) {
    local_24 = 0;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
      local_24 = RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(undefined4 *)((int)this + 4) = 0;
    local_c = local_24;
    *(HKEY *)this = local_8;
  }
  return local_c;
}



// Function: FUN_1000e090 at 1000e090

LSTATUS __thiscall FUN_1000e090(void *this,HKEY param_1,LPCWSTR param_2,REGSAM param_3)

{
  int local_20;
  LSTATUS local_18;
  LSTATUS local_c;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(int *)((int)this + 8) == 0) {
    local_20 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    local_20 = thunk_FUN_1000e170(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_8);
  }
  local_c = local_20;
  if (local_20 == 0) {
    local_18 = 0;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
      local_18 = RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(undefined4 *)((int)this + 4) = 0;
    local_c = local_18;
    *(HKEY *)this = local_8;
  }
  return local_c;
}



// Function: FUN_1000e170 at 1000e170

LSTATUS __thiscall
FUN_1000e170(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExW(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000e230 at 1000e230

LSTATUS __thiscall FUN_1000e230(void *this,LPCWSTR param_1)

{
  LSTATUS LVar1;
  LSTATUS local_23c;
  WCHAR local_230 [258];
  LSTATUS local_2c;
  HKEY local_28;
  undefined4 local_24;
  undefined4 local_20;
  _FILETIME local_1c;
  DWORD local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021488;
  local_10 = ExceptionList;
  local_28 = (HKEY)0x0;
  local_24 = 0;
  local_20 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  LVar1 = thunk_FUN_1000e090(&local_28,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (LVar1 == 0) {
    do {
      local_2c = 0;
      local_14 = 0x100;
      LVar1 = RegEnumKeyExW(local_28,0,local_230,&local_14,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_1c);
      if (LVar1 != 0) {
        if (local_28 != (HKEY)0x0) {
          RegCloseKey(local_28);
          local_28 = (HKEY)0x0;
        }
        local_24 = 0;
        if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
          local_23c = RegDeleteKeyW(*this,param_1);
        }
        else {
                    /* WARNING: Load size is inaccurate */
          local_23c = thunk_FUN_1000ddb0(*(void **)((int)this + 8),*this,param_1);
        }
        local_8 = 0xffffffff;
        if (local_28 == (HKEY)0x0) {
          ExceptionList = local_10;
          return local_23c;
        }
        RegCloseKey(local_28);
        ExceptionList = local_10;
        return local_23c;
      }
      LVar1 = thunk_FUN_1000e230(&local_28,local_230);
    } while (LVar1 == 0);
    local_8 = 0xffffffff;
    if (local_28 != (HKEY)0x0) {
      local_2c = LVar1;
      RegCloseKey(local_28);
    }
  }
  else {
    local_8 = 0xffffffff;
    if (local_28 != (HKEY)0x0) {
      local_2c = LVar1;
      RegCloseKey(local_28);
    }
  }
  ExceptionList = local_10;
  return LVar1;
}



// Function: FUN_1000e4d0 at 1000e4d0

LPCWSTR __cdecl FUN_1000e4d0(LPWSTR param_1,WCHAR param_2)

{
  LPWSTR pWVar1;
  LPCWSTR local_8;
  
  local_8 = (LPCWSTR)0x0;
  if (param_1 == (LPWSTR)0x0) {
    pWVar1 = (LPCWSTR)0x0;
  }
  else {
    for (; (pWVar1 = local_8, *param_1 != L'\0' && (pWVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextW(param_1)) {
    }
  }
  return pWVar1;
}



// Function: FUN_1000e530 at 1000e530

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall FUN_1000e530(void *this,undefined4 *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  undefined4 *_Memory;
  int iVar1;
  LPWSTR pWVar2;
  uint uVar3;
  HRESULT HVar4;
  undefined4 auStack_22cc [6];
  uint local_22b4;
  undefined4 auStack_226c [67];
  uint uStack_2160;
  uint uStack_215c;
  undefined4 uStack_2158;
  undefined4 *puStack_2154;
  undefined4 uStack_214c;
  WCHAR *pWStack_2148;
  uint local_2130;
  undefined4 local_212c [66];
  WCHAR local_2024 [4096];
  int local_24;
  ushort local_20 [2];
  ulong local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100214c1;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffdd10;
  local_20[0] = 0;
  local_1c = 0;
  local_18 = 0;
  ExceptionList = &pvStack_10;
  local_24 = thunk_FUN_1000bdd0(this,local_2024);
  if (-1 < local_24) {
    iVar1 = thunk_FUN_1000ed60(local_2024,local_20);
    if (iVar1 == 0) {
      local_24 = -0x7ffdfff7;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      while (iVar1 = thunk_FUN_1000ef60(**this), iVar1 != 0) {
                    /* WARNING: Load size is inaccurate */
        pWVar2 = CharNextW(*this);
        *(LPWSTR *)this = pWVar2;
      }
      local_24 = thunk_FUN_1000bdd0(this,local_2024);
      if (-1 < local_24) {
        if (local_20[0] < 0x14) {
          if (local_20[0] == 0x13) {
            uStack_214c = 3;
            puStack_2154 = (undefined4 *)0x0;
            local_8 = 3;
            pWStack_2148 = local_2024;
            Ordinal_277(pWStack_2148,0,0,&uStack_2158);
            auStack_22cc[0] = uStack_2158;
            local_1c = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)auStack_22cc,4);
            local_8 = 0xffffffff;
            while (_Memory = puStack_2154, puStack_2154 != (undefined4 *)0x0) {
              puStack_2154 = (undefined4 *)*puStack_2154;
              free(_Memory);
            }
          }
          else if (local_20[0] == 8) {
            local_22b4 = (uint)(&stack0x00000000 != (undefined1 *)0x2024);
            if (local_22b4 == 0) {
              local_1c = 0xd;
            }
            else {
              iVar1 = lstrlenW(local_2024);
              local_1c = RegSetValueExW((HKEY)*param_1,param_2,0,1,(BYTE *)local_2024,iVar1 * 2 + 2)
              ;
            }
          }
          else if (local_20[0] == 0x11) {
            uStack_2160 = lstrlenW(local_2024);
            if ((uStack_2160 & 1) != 0) {
              ExceptionList = pvStack_10;
              return -0x7fffbffb;
            }
            uStack_215c = (int)uStack_2160 / 2;
            auStack_226c[0] = 0;
            local_8 = 5;
            uVar3 = thunk_FUN_10013760(uStack_215c,1);
            thunk_FUN_100133c0(auStack_226c,uVar3);
            HVar4 = FUN_1000e99b();
            return HVar4;
          }
        }
        else if (local_20[0] == 0x4008) {
          iVar1 = lstrlenW(local_2024);
          local_2130 = iVar1 + 2;
          local_212c[0] = 0;
          local_8 = 1;
          uVar3 = thunk_FUN_10013760(local_2130,2);
          thunk_FUN_10013340(local_212c,uVar3);
          HVar4 = FUN_1000e70f();
          return HVar4;
        }
        if (local_1c == 0) {
          local_24 = thunk_FUN_1000bdd0(this,param_3);
          if (-1 < local_24) {
            local_24 = 0;
          }
        }
        else {
          local_18 = 0x204;
          local_24 = _HRESULT_FROM_WIN32(local_1c);
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return local_24;
}



// Function: Catch@1000e702 at 1000e702

undefined4 Catch_1000e702(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000e716;
}



// Function: FUN_1000e70f at 1000e70f

HRESULT FUN_1000e70f(void)

{
  LPWSTR pWVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x2128) == 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0xe;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x2130) = *(undefined4 *)(unaff_EBP + -0x2128);
    *(int *)(unaff_EBP + -0x2134) = unaff_EBP + -0x2020;
    *(undefined4 *)(unaff_EBP + -0x212c) = 0;
    while (**(short **)(unaff_EBP + -0x2134) != 0) {
      pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP + -0x2134));
      *(LPWSTR *)(unaff_EBP + -0x2138) = pWVar1;
      if ((**(short **)(unaff_EBP + -0x2134) == 0x5c) && (**(short **)(unaff_EBP + -0x2138) == 0x30)
         ) {
        **(undefined2 **)(unaff_EBP + -0x2130) = 0;
        *(int *)(unaff_EBP + -0x2130) = *(int *)(unaff_EBP + -0x2130) + 2;
        pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP + -0x2138));
        *(LPWSTR *)(unaff_EBP + -0x2134) = pWVar1;
      }
      else {
        **(undefined2 **)(unaff_EBP + -0x2130) = **(undefined2 **)(unaff_EBP + -0x2134);
        *(int *)(unaff_EBP + -0x2130) = *(int *)(unaff_EBP + -0x2130) + 2;
        *(int *)(unaff_EBP + -0x2134) = *(int *)(unaff_EBP + -0x2134) + 2;
      }
      *(int *)(unaff_EBP + -0x212c) = *(int *)(unaff_EBP + -0x212c) + 1;
    }
    **(undefined2 **)(unaff_EBP + -0x2130) = 0;
    *(int *)(unaff_EBP + -0x2130) = *(int *)(unaff_EBP + -0x2130) + 2;
    **(undefined2 **)(unaff_EBP + -0x2130) = 0;
    *(undefined4 *)(unaff_EBP + -0x22b4) = *(undefined4 *)(unaff_EBP + -0x2128);
    LVar2 = thunk_FUN_1000ecb0(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                               *(LPCWSTR *)(unaff_EBP + -0x22b4));
    *(LSTATUS *)(unaff_EBP + -0x18) = LVar2;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x2128) != unaff_EBP + -0x2124) {
    thunk_FUN_10013390((undefined4 *)(unaff_EBP + -0x2128));
  }
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    uVar4 = thunk_FUN_1000bdd0(*(void **)(unaff_EBP + -0x22d8),*(undefined2 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
    if (*(int *)(unaff_EBP + -0x20) < 0) {
      HVar3 = *(HRESULT *)(unaff_EBP + -0x20);
    }
    else {
      HVar3 = 0;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x204;
    HVar3 = _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return HVar3;
}



// Function: Catch@1000e98e at 1000e98e

undefined4 Catch_1000e98e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x1000e9a2;
}



// Function: FUN_1000e99b at 1000e99b

HRESULT FUN_1000e99b(void)

{
  uint uVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (*(int *)(unaff_EBP + -0x2268) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2270) = 0x80004005;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x2268) != unaff_EBP + -0x2264) {
      thunk_FUN_10013410((undefined4 *)(unaff_EBP + -0x2268));
    }
    HVar3 = *(HRESULT *)(unaff_EBP + -0x2270);
  }
  else {
    memset(*(void **)(unaff_EBP + -0x2268),0,*(size_t *)(unaff_EBP + -0x2158));
    *(undefined4 *)(unaff_EBP + -0x226c) = 0;
    while (*(int *)(unaff_EBP + -0x226c) < *(int *)(unaff_EBP + -0x215c)) {
      *(int *)(unaff_EBP + -0x22e0) =
           *(int *)(unaff_EBP + -0x226c) / 2 + *(int *)(unaff_EBP + -0x2268);
      uVar1 = thunk_FUN_1000eea0(*(ushort *)
                                  (unaff_EBP + -0x2020 + *(int *)(unaff_EBP + -0x226c) * 2));
      **(byte **)(unaff_EBP + -0x22e0) =
           **(byte **)(unaff_EBP + -0x22e0) |
           (byte)((uVar1 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP + -0x226c) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP + -0x226c) = *(int *)(unaff_EBP + -0x226c) + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x22d0) = *(undefined4 *)(unaff_EBP + -0x2268);
    *(undefined4 *)(unaff_EBP + -0x22d4) = **(undefined4 **)(unaff_EBP + 8);
    LVar2 = RegSetValueExW(*(HKEY *)(unaff_EBP + -0x22d4),*(LPCWSTR *)(unaff_EBP + 0xc),0,3,
                           *(BYTE **)(unaff_EBP + -0x22d0),*(DWORD *)(unaff_EBP + -0x2158));
    *(LSTATUS *)(unaff_EBP + -0x18) = LVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x2268) != unaff_EBP + -0x2264) {
      thunk_FUN_10013410((undefined4 *)(unaff_EBP + -0x2268));
    }
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar4 = thunk_FUN_1000bdd0(*(void **)(unaff_EBP + -0x22d8),*(undefined2 **)(unaff_EBP + 0x10))
      ;
      *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
      if (*(int *)(unaff_EBP + -0x20) < 0) {
        HVar3 = *(HRESULT *)(unaff_EBP + -0x20);
      }
      else {
        HVar3 = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x14) = 0x204;
      HVar3 = _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP + -0x18));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return HVar3;
}



// Function: FUN_1000ecb0 at 1000ecb0

LSTATUS __thiscall FUN_1000ecb0(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  int iVar2;
  LPCWSTR local_c;
  DWORD local_8;
  
  if (param_2 == (LPCWSTR)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_8 = 0;
    local_c = param_2;
    do {
      iVar2 = lstrlenW(local_c);
      iVar2 = iVar2 + 1;
      local_c = local_c + iVar2;
      local_8 = local_8 + iVar2 * 2;
    } while (iVar2 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExW(*this,param_1,0,7,(BYTE *)param_2,local_8);
  }
  return LVar1;
}



// Function: FUN_1000ed60 at 1000ed60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000ed60(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100214ee;
  local_10 = ExceptionList;
  if ((DAT_10033e80 & 1) == 0) {
    DAT_10033e80 = DAT_10033e80 | 1;
    _DAT_10033e58 = &DAT_10028950;
    _DAT_10033e5c = 8;
    _DAT_10033e60 = &DAT_1002894c;
    _DAT_10033e64 = 0x4008;
    _DAT_10033e68 = &DAT_10028948;
    _DAT_10033e6c = 0x13;
    _DAT_10033e70 = &DAT_10028944;
    _DAT_10033e74 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  ExceptionList = &local_10;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,*(LPCWSTR *)(&DAT_10033e58 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_10033e5c + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000eea0 at 1000eea0

uint __cdecl FUN_1000eea0(ushort param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    uVar1 = param_1 - 0x30;
    break;
  default:
    uVar1 = 0;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
    uVar1 = param_1 - 0x37;
    break;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    uVar1 = param_1 - 0x57;
  }
  return uVar1;
}



// Function: FUN_1000ef60 at 1000ef60

undefined4 FUN_1000ef60(undefined2 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 9:
  case 10:
  case 0xd:
  case 0x20:
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000efe0 at 1000efe0

undefined4 FUN_1000efe0(LPCWSTR param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xb < local_8) {
      return 1;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10028d00)[local_8]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_1000f040 at 1000f040

bool FUN_1000f040(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_1000f0a0 at 1000f0a0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall FUN_1000f0a0(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_200c [4098];
  int local_8;
  
  local_8 = 0x1000f0ad;
  if (*param_1 == 0x3d) {
    local_8 = thunk_FUN_1000bdd0(this,param_1);
    if (local_8 < 0) {
      return local_8;
    }
    thunk_FUN_1000bd20((undefined4 *)this);
    local_8 = thunk_FUN_1000bdd0(this,local_200c);
    if (local_8 < 0) {
      return local_8;
    }
    iVar1 = thunk_FUN_1000bdd0(this,param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  return 0;
}



// Function: FUN_1000f150 at 1000f150

undefined4 * __fastcall FUN_1000f150(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_1000f1c0 at 1000f1c0

undefined4 __thiscall FUN_1000f1c0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_c;
  int *local_8;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10033e18 = *param_3;
    DAT_10033e1c = param_3[1];
    DAT_10033e20 = param_3[2];
    DAT_10033e24 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_8 = *(int **)((int)this + 0x2c); *local_8 != 0; local_8 = local_8 + 9) {
      (*(code *)local_8[8])(1);
    }
  }
  for (local_c = DAT_10034200; local_c < DAT_10034204; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_1000f2a0 at 1000f2a0

void __fastcall FUN_1000f2a0(int param_1)

{
  int *local_c;
  int *local_8;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_8 = *(int **)(param_1 + 0x2c); *local_8 != 0; local_8 = local_8 + 9) {
      if (local_8[4] != 0) {
        (**(code **)(*(int *)local_8[4] + 8))(local_8[4]);
      }
      local_8[4] = 0;
      (*(code *)local_8[8])(0);
    }
  }
  for (local_c = DAT_10034200; local_c < DAT_10034204; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x20))(0);
    }
  }
  thunk_FUN_1000f370(param_1);
  return;
}



// Function: FUN_1000f370 at 1000f370

void __fastcall FUN_1000f370(int param_1)

{
  undefined4 local_18;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_18 = 0;
      }
      else {
        local_18 = param_1 + 4;
      }
      thunk_FUN_10011b00(local_18);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_1000f410 at 1000f410

/* WARNING: Removing unreachable block (ram,0x1000f505) */
/* WARNING: Removing unreachable block (ram,0x1000f51e) */

int __thiscall FUN_1000f410(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  bool bVar2;
  LPCRITICAL_SECTION local_20;
  undefined1 local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021528;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_14 = 0;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_18 = *(int **)((int)this + 0x2c); *local_18 != 0; local_18 = local_18 + 9) {
      if (local_18[2] != 0) {
        piVar1 = (int *)*local_18;
        if ((((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) && (param_1[2] == piVar1[2])) &&
           (param_1[3] == piVar1[3])) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          if (local_18[4] == 0) {
            thunk_FUN_10013530(&local_20,&DAT_10034208,'\0');
            local_8 = 0;
            EnterCriticalSection(local_20);
            local_1c = 1;
            local_14 = 0;
            if (local_18[4] == 0) {
              local_14 = (*(code *)local_18[2])(local_18[3],&DAT_10028f2c,local_18 + 4);
            }
            local_8 = 0xffffffff;
            thunk_FUN_100135c0(&local_20);
          }
          if (local_18[4] != 0) {
            local_14 = (*(code *)**(undefined4 **)local_18[4])(local_18[4],param_2,param_3);
          }
          break;
        }
      }
    }
  }
  if ((*param_3 == 0) && (local_14 == 0)) {
    local_14 = thunk_FUN_10011690((int *)&DAT_100341f8,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000f650 at 1000f650

int __thiscall FUN_1000f650(void *this,int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  int local_20c;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,(void *)*local_8,0x10), iVar1 == 0)) {
        local_c = (*(code *)local_8[1])(1);
        if (local_c < 0) break;
        iVar1 = 1;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = thunk_FUN_1000f790((GUID *)*local_8,piVar2,iVar1);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_20c = thunk_FUN_100104e0(0x100341f8,param_1,param_2);
    if ((-1 < local_20c) && (DAT_10033e4c != (code *)0x0)) {
      local_20c = (*DAT_10033e4c)(DAT_100341c4);
    }
    local_c = local_20c;
  }
  return local_c;
}



// Function: FUN_1000f790 at 1000f790

/* WARNING: Removing unreachable block (ram,0x1000f7e7) */

int FUN_1000f790(GUID *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  errno_t eVar4;
  wchar_t local_1e8 [128];
  DWORD local_e8;
  HKEY local_e4;
  undefined4 local_e0;
  void *local_dc;
  LSTATUS local_d8;
  HKEY local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  OLECHAR local_c8 [66];
  OLECHAR *local_44;
  undefined4 *local_40;
  undefined4 local_38;
  int *local_2c;
  int *local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021596;
  local_10 = ExceptionList;
  local_2c = (int *)0x0;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
  }
  else {
    if ((((param_1->Data1 == 0) &&
         (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar1 == 0)) &&
        (*(int *)param_1->Data4 == 0)) && (*(int *)(param_1->Data4 + 4) == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      thunk_FUN_100130b0((int *)&local_2c);
    }
    else {
      ExceptionList = &local_10;
      local_24 = CoCreateInstance((IID *)&DAT_1002b510,(LPUNKNOWN)0x0,1,(IID *)&DAT_10029630,
                                  &local_2c);
      if (local_24 < 0) {
        local_8 = 0xffffffff;
        if (local_2c != (int *)0x0) {
          (**(code **)(*local_2c + 8))(local_2c);
        }
      }
      else {
        local_24 = 0;
        for (local_28 = param_2; *local_28 != 0; local_28 = local_28 + 2) {
          puVar2 = (undefined4 *)local_28[1];
          local_20 = *puVar2;
          local_1c = puVar2[1];
          local_18 = puVar2[2];
          local_14 = puVar2[3];
          if (param_3 == 0) {
            if (*local_28 == 1) {
              (**(code **)(*local_2c + 0x18))(local_2c,param_1,1,&local_20);
            }
            else {
              (**(code **)(*local_2c + 0x20))(local_2c,param_1,1,&local_20);
            }
          }
          else {
            if (*local_28 == 1) {
              local_24 = (**(code **)(*local_2c + 0x14))(local_2c,param_1,1,&local_20);
            }
            else {
              local_24 = (**(code **)(*local_2c + 0x1c))(local_2c,param_1,1,&local_20);
            }
            iVar1 = local_24;
            if (local_24 < 0) {
              local_8 = 0xffffffff;
              if (local_2c != (int *)0x0) {
                (**(code **)(*local_2c + 8))(local_2c);
                ExceptionList = local_10;
                return iVar1;
              }
              ExceptionList = local_10;
              return local_24;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_c8,0x40);
          local_38 = 3;
          local_40 = (undefined4 *)0x0;
          local_8._0_1_ = 6;
          local_44 = local_c8;
          if (local_44 != (OLECHAR *)0x0) {
            eVar4 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            ATL::AtlCrtErrorCheck(eVar4);
            eVar4 = wcscat_s(local_1e8,0x80,local_44);
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              thunk_FUN_10004720(0x80004005);
              break;
            case 0xc:
              thunk_FUN_10004720(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              thunk_FUN_10004720(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,L"\\Required Categories");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              thunk_FUN_10004720(0x80004005);
              break;
            case 0xc:
              thunk_FUN_10004720(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              thunk_FUN_10004720(0x80070057);
            }
            local_e4 = (HKEY)0x80000000;
            local_e0 = 0;
            local_dc = (void *)0x0;
            local_d4 = (HKEY)0x0;
            local_d0 = 0;
            local_cc = 0;
            local_8 = CONCAT31(local_8._1_3_,8);
            local_e8 = 0;
            local_d8 = thunk_FUN_1000e090(&local_d4,(HKEY)0x80000000,local_1e8,0x20019);
            if (local_d8 == 0) {
              local_d8 = RegQueryInfoKeyW(local_d4,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_e8,
                                          (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                          (LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
              if (local_d4 != (HKEY)0x0) {
                RegCloseKey(local_d4);
                local_d4 = (HKEY)0x0;
              }
              local_d0 = 0;
              if ((local_d8 == 0) && (local_e8 == 0)) {
                if (local_dc == (void *)0x0) {
                  RegDeleteKeyW(local_e4,local_1e8);
                }
                else {
                  thunk_FUN_1000ddb0(local_dc,local_e4,local_1e8);
                }
              }
            }
            eVar4 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              thunk_FUN_10004720(0x80004005);
              break;
            case 0xc:
              thunk_FUN_10004720(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              thunk_FUN_10004720(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,local_44);
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              thunk_FUN_10004720(0x80004005);
              break;
            case 0xc:
              thunk_FUN_10004720(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              thunk_FUN_10004720(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,L"\\Implemented Categories");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              thunk_FUN_10004720(0x80004005);
              break;
            case 0xc:
              thunk_FUN_10004720(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              thunk_FUN_10004720(0x80070057);
            }
            local_d8 = thunk_FUN_1000e090(&local_d4,local_e4,local_1e8,0x20019);
            if (local_d8 == 0) {
              local_d8 = RegQueryInfoKeyW(local_d4,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_e8,
                                          (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                          (LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
              if (local_d4 != (HKEY)0x0) {
                RegCloseKey(local_d4);
                local_d4 = (HKEY)0x0;
              }
              local_d0 = 0;
              if ((local_d8 == 0) && (local_e8 == 0)) {
                if (local_dc == (void *)0x0) {
                  RegDeleteKeyW(local_e4,local_1e8);
                }
                else {
                  thunk_FUN_1000ddb0(local_dc,local_e4,local_1e8);
                }
              }
            }
            local_8._0_1_ = 7;
            if (local_d4 != (HKEY)0x0) {
              RegCloseKey(local_d4);
              local_d4 = (HKEY)0x0;
            }
            local_d0 = 0;
            local_8._0_1_ = 6;
            if (local_e4 != (HKEY)0x0) {
              RegCloseKey(local_e4);
              local_e4 = (HKEY)0x0;
            }
            local_e0 = 0;
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar2 = local_40, local_40 != (undefined4 *)0x0) {
            local_40 = (undefined4 *)*local_40;
            free(puVar2);
          }
        }
        local_8 = 0xffffffff;
        if (local_2c != (int *)0x0) {
          (**(code **)(*local_2c + 8))(local_2c);
        }
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10010470 at 10010470

void __fastcall FUN_10010470(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100215c8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100104e0 at 100104e0

int FUN_100104e0(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *local_c;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = -0x7ff8ffa9;
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 8); local_c < *(int **)(param_1 + 0xc); local_c = local_c + 1
        ) {
      if ((*local_c != 0) &&
         ((puVar1 = (undefined4 *)*local_c, param_3 == (void *)0x0 ||
          (iVar2 = memcmp(param_3,(void *)*puVar1,0x10), iVar2 == 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        iVar2 = 1;
        piVar3 = (int *)(*(code *)puVar1[7])();
        local_8 = thunk_FUN_1000f790((GUID *)*puVar1,piVar3,iVar2);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = thunk_FUN_10010600(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10010600 at 10010600

int FUN_10010600(HMODULE param_1,LPCWSTR param_2)

{
  rsize_t _MaxCount;
  errno_t eVar1;
  int iVar2;
  HMODULE hModule;
  char local_231;
  wchar_t local_230 [259];
  undefined2 local_2a;
  wchar_t *local_28;
  wchar_t *local_24;
  FARPROC local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021610;
  local_10 = ExceptionList;
  local_1c = 0;
  local_14 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  local_18 = thunk_FUN_10010920(param_1,param_2,&local_1c,&local_14);
  if (-1 < local_18) {
    local_28 = (wchar_t *)0x0;
    local_24 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    local_18 = (**(code **)(*local_14 + 0x24))(local_14,0xffffffff,0,0,0,&local_24);
    if ((-1 < local_18) && (local_24 != (wchar_t *)0x0)) {
      _MaxCount = Ordinal_7(local_24);
      eVar1 = wcsncpy_s(local_230,0x104,local_24,_MaxCount);
      ATL::AtlCrtErrorCheck(eVar1);
      local_2a = 0;
      iVar2 = FUN_100110f0(local_230);
      local_230[iVar2] = L'\0';
      local_28 = local_230;
    }
    local_20 = (FARPROC)0x0;
    local_231 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x231) {
      local_18 = -0x7fffbffd;
    }
    else {
      local_231 = DAT_10033e10;
      local_18 = 0;
    }
    iVar2 = local_18;
    if (local_18 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_1c);
      ExceptionList = local_10;
      return iVar2;
    }
    if ((local_231 == '\x01') &&
       (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
      local_20 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    }
    if (local_20 == (FARPROC)0x0) {
      local_20 = Ordinal_163_exref;
    }
    local_18 = (*local_20)(local_14,local_1c,local_28);
    local_8._0_1_ = 2;
    Ordinal_6(local_24);
  }
  iVar2 = local_18;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_1c);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10010920 at 10010920

/* WARNING: Removing unreachable block (ram,0x10010a13) */

int FUN_10010920(HMODULE param_1,LPCWSTR param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  errno_t eVar3;
  wchar_t local_270 [6];
  uint local_264;
  LPCWSTR local_260;
  uint local_25c;
  WCHAR *local_258;
  int local_254;
  LPCWSTR local_250;
  DWORD local_24c;
  undefined4 *local_248;
  WCHAR local_240 [274];
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002163b;
  local_10 = ExceptionList;
  if ((param_3 == (int *)0x0) || (param_4 == (undefined4 *)0x0)) {
    iVar2 = -0x7fffbffd;
  }
  else {
    ExceptionList = &local_10;
    *param_3 = 0;
    *param_4 = 0;
    local_1c = 3;
    local_248 = (undefined4 *)0x0;
    local_8 = 0;
    local_24c = GetModuleFileNameW(param_1,local_240,0x104);
    if (local_24c == 0) {
      iVar2 = ATL::AtlHresultFromLastError();
      local_8 = 0xffffffff;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
    }
    else if (local_24c == 0x104) {
      local_8 = 0xffffffff;
      local_24c = 0x104;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
      iVar2 = -0x7ff8ff86;
    }
    else {
      local_250 = (LPCWSTR)0x0;
      local_250 = FUN_10011060(local_240);
      if (param_2 != (LPCWSTR)0x0) {
        local_260 = param_2;
        if (param_2 == (LPCWSTR)0x0) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          ExceptionList = local_10;
          return -0x7ff8fff2;
        }
        local_25c = lstrlenW(param_2);
        local_264 = local_24c + local_25c;
        if (((local_264 < local_24c) || (local_264 < local_25c)) || (0x10d < local_264)) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          ExceptionList = local_10;
          return -0x7fffbffb;
        }
        eVar3 = wcscpy_s(local_240 + local_24c,0x10e - local_24c,local_260);
        switch(eVar3) {
        case 0:
        case 0x50:
          break;
        default:
          thunk_FUN_10004720(0x80004005);
          break;
        case 0xc:
          thunk_FUN_10004720(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          thunk_FUN_10004720(0x80070057);
        }
      }
      local_258 = local_240;
      local_254 = Ordinal_161(local_258,param_4);
      if (local_254 < 0) {
        builtin_wcsncpy(local_270,L".tlb",5);
        if (0x104 < ((int)local_250 - (int)local_240 >> 1) + 5U) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          ExceptionList = local_10;
          return -0x7fffbffb;
        }
        eVar3 = wcscpy_s(local_250,0x10e - ((int)local_250 - (int)local_240 >> 1),local_270);
        switch(eVar3) {
        case 0:
        case 0x50:
          break;
        default:
          thunk_FUN_10004720(0x80004005);
          break;
        case 0xc:
          thunk_FUN_10004720(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          thunk_FUN_10004720(0x80070057);
        }
        local_258 = local_240;
        local_254 = Ordinal_161(local_258,param_4);
      }
      if (-1 < local_254) {
        iVar2 = Ordinal_2(local_258);
        *param_3 = iVar2;
        if (*param_3 == 0) {
          local_254 = -0x7ff8fff2;
        }
      }
      iVar2 = local_254;
      local_8 = 0xffffffff;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
    }
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10011060 at 10011060

LPCWSTR __cdecl FUN_10011060(LPWSTR param_1)

{
  LPCWSTR local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    local_8 = (LPCWSTR)0x0;
  }
  else {
    local_8 = (LPCWSTR)0x0;
    for (; *param_1 != L'\0'; param_1 = CharNextW(param_1)) {
      if (*param_1 == L'.') {
        local_8 = param_1;
      }
      else if (*param_1 == L'\\') {
        local_8 = (LPCWSTR)0x0;
      }
    }
    if (local_8 == (LPCWSTR)0x0) {
      local_8 = param_1;
    }
  }
  return local_8;
}



// Function: FUN_100110f0 at 100110f0

int FUN_100110f0(LPWSTR param_1)

{
  WCHAR WVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    iVar2 = 0;
  }
  else {
    local_8 = param_1;
    local_c = param_1;
    while (*local_c != L'\0') {
      pWVar3 = CharNextW(local_c);
      if (((*local_c == L'\\') || (*local_c == L'/')) ||
         (WVar1 = *local_c, local_c = pWVar3, WVar1 == L':')) {
        local_c = pWVar3;
        local_8 = pWVar3;
      }
    }
    iVar2 = (int)local_8 - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_10011180 at 10011180

void __fastcall FUN_10011180(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021658;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100111f0 at 100111f0

int __thiscall FUN_100111f0(void *this,int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  int local_20c;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,(void *)*local_8,0x10), iVar1 == 0)) {
        iVar1 = 0;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = thunk_FUN_1000f790((GUID *)*local_8,piVar2,iVar1);
        if ((local_c < 0) || (local_c = (*(code *)local_8[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_20c = 0;
    if (DAT_10033e50 != (code *)0x0) {
      local_20c = (*DAT_10033e50)();
    }
    if (-1 < local_20c) {
      local_20c = thunk_FUN_10011330(0x100341f8,param_1,param_2);
    }
    local_c = local_20c;
  }
  return local_c;
}



// Function: FUN_10011330 at 10011330

int FUN_10011330(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *local_c;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = -0x7ff8ffa9;
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 8); local_c < *(int **)(param_1 + 0xc); local_c = local_c + 1
        ) {
      if ((*local_c != 0) &&
         ((puVar1 = (undefined4 *)*local_c, param_3 == (void *)0x0 ||
          (iVar2 = memcmp(param_3,(void *)*puVar1,0x10), iVar2 == 0)))) {
        iVar2 = 0;
        piVar3 = (int *)(*(code *)puVar1[7])();
        local_8 = thunk_FUN_1000f790((GUID *)*puVar1,piVar3,iVar2);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = thunk_FUN_10011450(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10011450 at 10011450

int FUN_10011450(HMODULE param_1,LPCWSTR param_2)

{
  int iVar1;
  HMODULE hModule;
  char local_25;
  FARPROC local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021698;
  local_10 = ExceptionList;
  local_1c = 0;
  local_14 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  local_18 = thunk_FUN_10010920(param_1,param_2,&local_1c,&local_14);
  if ((-1 < local_18) &&
     (local_18 = (**(code **)(*local_14 + 0x1c))(local_14,&local_20), -1 < local_18)) {
    local_24 = (FARPROC)0x0;
    local_25 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x25) {
      local_18 = -0x7fffbffd;
    }
    else {
      local_25 = DAT_10033e10;
      local_18 = 0;
    }
    iVar1 = local_18;
    if (local_18 < 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_1c);
      ExceptionList = local_10;
      return iVar1;
    }
    if ((local_25 == '\x01') &&
       (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
      local_24 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    }
    if (local_24 == (FARPROC)0x0) {
      local_24 = Ordinal_186_exref;
    }
    local_18 = (*local_24)(local_20,(uint)*(ushort *)(local_20 + 0x18),
                           (uint)*(ushort *)(local_20 + 0x1a),*(undefined4 *)(local_20 + 0x10),
                           *(undefined4 *)(local_20 + 0x14));
    (**(code **)(*local_14 + 0x30))(local_14,local_20);
  }
  iVar1 = local_18;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_1c);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10011690 at 10011690

/* WARNING: Removing unreachable block (ram,0x100117cb) */
/* WARNING: Removing unreachable block (ram,0x100117e4) */

int FUN_10011690(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  LPCRITICAL_SECTION local_24;
  undefined1 local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100216b8;
  local_10 = ExceptionList;
  if (param_4 == (int *)0x0) {
    local_14 = -0x7fffbffd;
  }
  else {
    ExceptionList = &local_10;
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      local_14 = -0x7ff8ffa9;
    }
    else if (*param_1 == 0) {
      local_14 = -0x7fff0001;
    }
    else {
      local_14 = 0;
      for (local_18 = (int *)param_1[2]; local_18 < (int *)param_1[3]; local_18 = local_18 + 1) {
        if ((*local_18 != 0) && (local_1c = (undefined4 *)*local_18, local_1c[2] != 0)) {
          piVar1 = (int *)*local_1c;
          if ((*param_2 == *piVar1) &&
             (((param_2[1] == piVar1[1] && (param_2[2] == piVar1[2])) && (param_2[3] == piVar1[3])))
             ) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            if (local_1c[4] == 0) {
              thunk_FUN_10013530(&local_24,param_1 + 4,'\0');
              local_8 = 0;
              EnterCriticalSection(local_24);
              local_20 = 1;
              local_14 = 0;
              if (local_1c[4] == 0) {
                local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_10028f2c,local_1c + 4);
              }
              local_8 = 0xffffffff;
              thunk_FUN_100135c0(&local_24);
            }
            if (local_1c[4] != 0) {
              local_14 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_3,param_4);
            }
            break;
          }
        }
      }
      if ((*param_4 == 0) && (local_14 == 0)) {
        local_14 = -0x7ffbfeef;
      }
    }
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10011900 at 10011900

int FUN_10011900(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if ((((*param_3 == 0) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
       (param_3[3] == 0x46000000)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      piVar3 = (int *)(param_1 + param_2[1]);
      (**(code **)(*piVar3 + 4))(piVar3);
      *param_4 = piVar3;
      iVar2 = 0;
    }
    else {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        iVar2 = *param_2;
        if (iVar2 == 0) {
LAB_10011a12:
          if (param_2[2] == 1) {
            piVar3 = (int *)(param_1 + param_2[1]);
            (**(code **)(*piVar3 + 4))(piVar3);
            *param_4 = piVar3;
            return 0;
          }
          iVar4 = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (iVar4 == 0) {
            return 0;
          }
          if ((iVar2 != 0) && (iVar4 < 0)) {
            return iVar4;
          }
        }
        else {
          piVar3 = (int *)*param_2;
          if (((*piVar3 == *param_3) && (piVar3[1] == param_3[1])) &&
             ((piVar3[2] == param_3[2] && (piVar3[3] == param_3[3])))) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) goto LAB_10011a12;
        }
      }
      iVar2 = -0x7fffbffe;
    }
  }
  return iVar2;
}



// Function: FUN_10011b00 at 10011b00

void FUN_10011b00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  
  if (param_1 == 0) {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
  }
  local_c = *(undefined4 **)(param_1 + 8);
  while (local_c != (undefined4 *)0x0) {
    (*(code *)*local_c)(local_c[1]);
    puVar1 = (undefined4 *)local_c[2];
    operator_delete(local_c);
    local_c = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10011ba0 at 10011ba0

undefined4 FUN_10011ba0(void)

{
  return 0;
}



// Function: FUN_10011bb0 at 10011bb0

void FUN_10011bb0(void)

{
  return;
}



// Function: FUN_10011bc0 at 10011bc0

void __fastcall FUN_10011bc0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100216fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 4;
  if (*(char *)(param_1 + 8) != '\0') {
    *(undefined1 *)(param_1 + 8) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011c80 at 10011c80

undefined4 FUN_10011c80(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if (param_2 != 0) {
      if ((((*param_3 == 0) && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
         (param_3[3] == 0x46000000)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        return 0x80040110;
      }
    }
    local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
  }
  return local_8;
}



// Function: FUN_10011d40 at 10011d40

undefined4 FUN_10011d40(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10033e14 + 8))();
  }
  else {
    (**(code **)(*DAT_10033e14 + 4))();
  }
  return 0;
}



// Function: FUN_10011d90 at 10011d90

undefined4 * __thiscall FUN_10011d90(void *this,uint param_1)

{
  thunk_FUN_10011bc0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10011dd0 at 10011dd0

int __thiscall FUN_10011dd0(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    local_8 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_8 = thunk_FUN_10012010(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: FUN_10011e80 at 10011e80

int __thiscall
FUN_10011e80(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_14 = thunk_FUN_10012010(this,param_4);
  }
  local_8 = local_14;
  if (*(int *)((int)this + 0xc) != 0) {
    local_8 = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar1 = lstrlenW((LPCWSTR)*param_2);
      local_10 = *(int *)((int)this + 0x18);
      do {
        local_10 = local_10 + -1;
        if (local_10 < 0) goto LAB_10011f84;
      } while ((iVar1 != *(int *)(*(int *)((int)this + 0x14) + 4 + local_10 * 0xc)) ||
              (iVar2 = memcmp(*(void **)(local_10 * 0xc + *(int *)((int)this + 0x14)),
                              (void *)*param_2,
                              *(int *)(*(int *)((int)this + 0x14) + 4 + local_10 * 0xc) << 1),
              iVar2 != 0));
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_10 * 0xc);
      local_8 = 0;
    }
LAB_10011f84:
    if (local_8 < 0) {
      local_8 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                          (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_8;
}



// Function: FUN_10012010 at 10012010

/* WARNING: Removing unreachable block (ram,0x1001207b) */
/* WARNING: Removing unreachable block (ram,0x10012092) */
/* WARNING: Removing unreachable block (ram,0x100120ce) */
/* WARNING: Removing unreachable block (ram,0x100120ea) */
/* WARNING: Removing unreachable block (ram,0x10012102) */
/* WARNING: Removing unreachable block (ram,0x1001210a) */

int __thiscall FUN_10012010(void *this,undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *_Memory;
  int iVar3;
  undefined1 *puVar4;
  void *pvVar5;
  int local_2a8;
  int *local_254;
  int *local_250;
  int *local_24c;
  undefined4 *local_248;
  WCHAR *local_244;
  undefined4 local_23c;
  WCHAR local_230 [262];
  DWORD local_24;
  int *local_20;
  int local_1c;
  LPCRITICAL_SECTION local_18;
  undefined1 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021796;
  local_10 = ExceptionList;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_18 = (LPCRITICAL_SECTION)(DAT_10033e14 + 0x10);
    local_14 = 0;
    local_8 = 0;
    ExceptionList = &local_10;
    EnterCriticalSection(local_18);
    local_14 = 1;
    local_1c = -0x7fffbffb;
    if (*(int *)((int)this + 0xc) == 0) {
      local_20 = (int *)0x0;
      piVar1 = *(int **)((int)this + 4);
      if ((((DAT_10033e18 == *piVar1) && (DAT_10033e1c == piVar1[1])) && (DAT_10033e20 == piVar1[2])
          ) && (DAT_10033e24 == piVar1[3])) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (((bVar2) && (*(short *)((int)this + 8) == -1)) && (*(short *)((int)this + 10) == -1)) {
        local_24 = GetModuleFileNameW(DAT_100341c4,local_230,0x104);
        if ((local_24 != 0) && (local_24 != 0x104)) {
          local_23c = 3;
          local_248 = (undefined4 *)0x0;
          local_8._0_1_ = 1;
          local_244 = local_230;
          local_1c = Ordinal_161(local_244,&local_20);
          local_8 = (uint)local_8._1_3_ << 8;
          while (_Memory = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(_Memory);
          }
        }
      }
      else {
        local_1c = Ordinal_162(*(undefined4 *)((int)this + 4),*(undefined2 *)((int)this + 8),
                               *(undefined2 *)((int)this + 10),param_1,&local_20);
      }
      if (-1 < local_1c) {
        local_24c = (int *)0x0;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
        local_1c = (**(code **)(*local_20 + 0x18))(local_20,*this,&local_24c);
        if (-1 < local_1c) {
          local_250 = local_24c;
          if (local_24c != (int *)0x0) {
            (**(code **)(*local_24c + 4))(local_24c);
          }
          local_254 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,7);
          iVar3 = (**(code **)*local_24c)(local_24c,&DAT_100296ac,&local_254);
          if (-1 < iVar3) {
            thunk_FUN_100136a0(&local_250,(int *)&local_254);
          }
          piVar1 = local_250;
          local_250 = (int *)0x0;
          *(int **)((int)this + 0xc) = piVar1;
          if (DAT_10033e14 == 0) {
            local_2a8 = 0;
          }
          else {
            local_2a8 = DAT_10033e14 + 4;
          }
          puVar4 = &LAB_100013e3;
          pvVar5 = this;
          thunk_FUN_10012610(local_2a8);
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 5;
          if (local_254 != (int *)0x0) {
            (**(code **)(*local_254 + 8))(local_254,puVar4,pvVar5);
          }
          local_8._0_1_ = 3;
          if (local_250 != (int *)0x0) {
            (**(code **)(*local_250 + 8))(local_250);
          }
        }
        (**(code **)(*local_20 + 8))(local_20);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_24c != (int *)0x0) {
          (**(code **)(*local_24c + 8))(local_24c);
        }
      }
    }
    else {
      local_1c = 0;
    }
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) == 0)) {
      local_1c = thunk_FUN_10012800(this,*(int **)((int)this + 0xc));
    }
    iVar3 = local_1c;
    local_8 = 0xffffffff;
    thunk_FUN_100135c0(&local_18);
  }
  else {
    iVar3 = 0;
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10012610 at 10012610

undefined4 FUN_10012610(int param_1)

{
  undefined4 uVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100217c8;
  pvStack_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  operator_new(0xc);
  uVar1 = FUN_10012679();
  return uVar1;
}



// Function: Catch@1001266c at 1001266c

undefined4 Catch_1001266c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10012680;
}



// Function: FUN_10012679 at 10012679

undefined4 FUN_10012679(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
  }
  else {
    **(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4) = *(undefined4 *)(unaff_EBP + 0x10);
    thunk_FUN_10013530((void *)(unaff_EBP + -0x20),*(int *)(unaff_EBP + 8) + 0xc,'\0');
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x20);
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x3c));
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    if (*(int *)(unaff_EBP + -0x38) < 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x38);
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x1c) = 1;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    if (*(int *)(unaff_EBP + -0x18) < 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x14);
      operator_delete(*(void **)(unaff_EBP + -0x28));
    }
    else {
      *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8) =
           *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8);
      *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8) = *(undefined4 *)(unaff_EBP + -0x14);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    thunk_FUN_100135c0((undefined4 *)(unaff_EBP + -0x20));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10012790 at 10012790

void __fastcall FUN_10012790(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100217e8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012800 at 10012800

undefined4 __thiscall FUN_10012800(void *this,int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint *local_4c;
  int iStack_2c;
  undefined4 *puStack_28;
  int iStack_24;
  uint *local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021813;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffa8;
  ExceptionList = &pvStack_10;
  local_18 = (**(code **)(*param_1 + 0xc))(param_1,&local_1c);
  if (-1 < local_18) {
    local_20 = (uint *)0x0;
    *(uint *)((int)this + 0x18) = (uint)*(ushort *)(local_1c + 0x2c);
    *(undefined4 *)((int)this + 0x14) = 0;
    if (*(int *)((int)this + 0x18) != 0) {
      local_8 = 0;
      uVar1 = *(uint *)((int)this + 0x18);
      uVar6 = -(uint)((int)((ulonglong)uVar1 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar1 * 0xc);
      local_4c = (uint *)FUN_1001db00(-(uint)(0xfffffffb < uVar6) | uVar6 + 4);
      local_8._0_1_ = 1;
      if (local_4c == (uint *)0x0) {
        local_4c = (uint *)0x0;
      }
      else {
        *local_4c = uVar1;
        _eh_vector_constructor_iterator_
                  (local_4c + 1,0xc,uVar1,(_func_void_void_ptr *)&LAB_10001767,
                   (_func_void_void_ptr *)&LAB_100016b8);
        local_4c = local_4c + 1;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      local_20 = local_4c;
      uVar2 = FUN_10012909();
      return uVar2;
    }
    for (iStack_24 = 0; iStack_24 < *(int *)((int)this + 0x18); iStack_24 = iStack_24 + 1) {
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1,iStack_24,&puStack_28);
      if (-1 < iVar3) {
        iStack_2c = 0;
        local_8 = 3;
        iVar4 = (**(code **)(*param_1 + 0x30))(param_1,*puStack_28,&iStack_2c,0,0,0);
        iVar3 = iStack_2c;
        if (-1 < iVar4) {
          iStack_2c = 0;
          piVar5 = (int *)(iStack_24 * 0xc + (int)local_20);
          if (*piVar5 != iVar3) {
            Ordinal_6(*piVar5);
            *piVar5 = iVar3;
          }
          uVar2 = Ordinal_7(*(undefined4 *)((int)local_20 + iStack_24 * 0xc));
          *(undefined4 *)((int)local_20 + 4 + iStack_24 * 0xc) = uVar2;
          *(undefined4 *)((int)local_20 + 8 + iStack_24 * 0xc) = *puStack_28;
        }
        (**(code **)(*param_1 + 0x50))(param_1,puStack_28);
        local_8 = 0xffffffff;
        Ordinal_6(iStack_2c);
      }
    }
    *(uint **)((int)this + 0x14) = local_20;
    (**(code **)(*param_1 + 0x4c))(param_1,local_1c);
  }
  ExceptionList = pvStack_10;
  return 0;
}



// Function: Catch@100128fc at 100128fc

undefined4 Catch_100128fc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10012910;
}



// Function: FUN_10012909 at 10012909

undefined4 FUN_10012909(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    while (*(int *)(unaff_EBP + -0x20) < *(int *)(*(int *)(unaff_EBP + -0x44) + 0x18)) {
      iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x14))
                        (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x20),
                         unaff_EBP + -0x24);
      if (-1 < iVar2) {
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x30))
                          (*(undefined4 *)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + -0x24),
                           unaff_EBP + -0x28,0,0,0);
        if (-1 < iVar2) {
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          *(int *)(unaff_EBP + -0x3c) =
               *(int *)(unaff_EBP + -0x20) * 0xc + *(int *)(unaff_EBP + -0x1c);
          if (**(int **)(unaff_EBP + -0x3c) != *(int *)(unaff_EBP + -0x38)) {
            Ordinal_6(**(undefined4 **)(unaff_EBP + -0x3c));
            **(undefined4 **)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x38);
          }
          *(undefined4 *)(unaff_EBP + -0x40) =
               *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x20) * 0xc);
          uVar1 = Ordinal_7(*(undefined4 *)(unaff_EBP + -0x40));
          *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4 + *(int *)(unaff_EBP + -0x20) * 0xc) =
               uVar1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 8 + *(int *)(unaff_EBP + -0x20) * 0xc) =
               **(undefined4 **)(unaff_EBP + -0x24);
        }
        (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))
                  (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x24));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x28));
      }
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    }
    *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}



// Function: FUN_10012b10 at 10012b10

undefined4 * __fastcall FUN_10012b10(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return param_1;
}



// Function: FUN_10012b80 at 10012b80

void FUN_10012b80(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      thunk_FUN_10008830(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10012c20 at 10012c20

void __fastcall FUN_10012c20(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021858;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012c90 at 10012c90

void __fastcall FUN_10012c90(int *param_1)

{
  void *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    free(_Memory);
  }
  return;
}



// Function: FUN_10012ce0 at 10012ce0

void __fastcall FUN_10012ce0(int *param_1)

{
  thunk_FUN_10012e90(param_1);
  return;
}



// Function: FUN_10012d00 at 10012d00

undefined4 __thiscall FUN_10012d00(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100218a3;
  local_10 = ExceptionList;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  pvVar3 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    *(void **)this = pvVar3;
    pvVar3 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      *(void **)((int)this + 4) = pvVar3;
      iVar2 = *(int *)((int)this + 8);
                    /* WARNING: Load size is inaccurate */
      puVar1 = (undefined4 *)(*this + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = *param_1;
      }
      puVar1 = (undefined4 *)(*(int *)((int)this + 4) + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = *param_2;
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      uVar4 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar4;
}



// Function: FUN_10012e90 at 10012e90

void __fastcall FUN_10012e90(int *param_1)

{
  int local_8;
  
  if (*param_1 != 0) {
    for (local_8 = 0; local_8 < param_1[2]; local_8 = local_8 + 1) {
    }
    free((void *)*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}



// Function: FUN_10012f30 at 10012f30

int __thiscall FUN_10012f30(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: Free at 10012f80

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<void *>::Free(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: ~CTempBuffer<> at 10012fc0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    thunk_FUN_10013310(param_1);
  }
  return;
}



// Function: FUN_10012ff0 at 10012ff0

undefined4 __thiscall FUN_10012ff0(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = thunk_FUN_10013760(param_1,2);
  if (uVar1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    thunk_FUN_10013440(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: ~CTempBuffer<> at 10013050

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    thunk_FUN_10013390(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10013080

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    thunk_FUN_10013410(param_1);
  }
  return;
}



// Function: FUN_100130b0 at 100130b0

void __fastcall FUN_100130b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100130e0 at 100130e0

void __fastcall FUN_100130e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10013110 at 10013110

void __fastcall FUN_10013110(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10013140 at 10013140

void __fastcall FUN_10013140(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100218e3;
  local_10 = ExceptionList;
  local_8 = 3;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100131d0 at 100131d0

void __fastcall FUN_100131d0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10013200 at 10013200

void __fastcall FUN_10013200(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021910;
  local_10 = ExceptionList;
  local_8 = 1;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013280 at 10013280

int __thiscall FUN_10013280(void *this,undefined4 *param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_8) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = lstrcmpiW(*(LPCWSTR *)(*this + local_8 * 4),(LPCWSTR)*param_1);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}



// Function: FUN_10013310 at 10013310

void __fastcall FUN_10013310(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10013340 at 10013340

undefined4 __thiscall FUN_10013340(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    thunk_FUN_10013490(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10013390 at 10013390

void __fastcall FUN_10013390(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_100133c0 at 100133c0

undefined4 __thiscall FUN_100133c0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    thunk_FUN_100134e0(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10013410 at 10013410

void __fastcall FUN_10013410(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10013440 at 10013440

void __thiscall FUN_10013440(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    thunk_FUN_10004720(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10013490 at 10013490

void __thiscall FUN_10013490(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    thunk_FUN_10004720(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_100134e0 at 100134e0

void __thiscall FUN_100134e0(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    thunk_FUN_10004720(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10013530 at 10013530

/* WARNING: Removing unreachable block (ram,0x1001356f) */
/* WARNING: Removing unreachable block (ram,0x1001358b) */

undefined4 * __thiscall FUN_10013530(void *this,undefined4 param_1,char param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  if (param_2 != '\0') {
                    /* WARNING: Load size is inaccurate */
    EnterCriticalSection(*this);
    *(undefined1 *)((int)this + 4) = 1;
  }
  return (undefined4 *)this;
}



// Function: FUN_100135c0 at 100135c0

void __fastcall FUN_100135c0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10013610 at 10013610

/* WARNING: Removing unreachable block (ram,0x10013638) */

undefined4 __fastcall FUN_10013610(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 1;
  return 0;
}



// Function: FUN_10013660 at 10013660

void __fastcall FUN_10013660(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_100136a0 at 100136a0

int __thiscall FUN_100136a0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int local_24;
  
  bVar3 = thunk_FUN_10013810(this,(undefined4 *)*param_1);
  if (bVar3) {
                    /* WARNING: Load size is inaccurate */
    local_24 = *this;
  }
  else {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      local_24 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
      *(undefined4 *)this = 0;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,&DAT_100296c0,this);
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
                    /* WARNING: Load size is inaccurate */
      local_24 = *this;
    }
  }
  return local_24;
}



// Function: FUN_10013760 at 10013760

/* WARNING: Removing unreachable block (ram,0x10013789) */

undefined4 __cdecl FUN_10013760(uint param_1,uint param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  if (local_10 == 0) {
    local_14 = (undefined4)((ulonglong)param_1 * (ulonglong)param_2);
    local_8 = local_14;
    local_c = 0;
  }
  else {
    local_c = -0x7ff8fdea;
  }
  if (local_c < 0) {
    thunk_FUN_10004720(local_c);
  }
  return local_8;
}



// Function: FUN_10013800 at 10013800

void FUN_10013800(void)

{
  return;
}



// Function: FUN_10013810 at 10013810

bool __thiscall FUN_10013810(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021950;
  local_10 = ExceptionList;
                    /* WARNING: Load size is inaccurate */
  if ((*this == 0) && (param_1 == (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*this == 0) || (param_1 == (undefined4 *)0x0)) {
      bVar1 = false;
    }
    else {
      local_14 = (int *)0x0;
      local_18 = (int *)0x0;
      local_8._1_3_ = 0;
      local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      ExceptionList = &local_10;
      (**(code **)**this)(*this,&DAT_10028f2c,&local_14);
      (**(code **)*param_1)(param_1,&DAT_10028f2c,&local_18);
      bVar1 = local_14 == local_18;
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
  }
  ExceptionList = local_10;
  return bVar1;
}



// Function: FUN_10013960 at 10013960

void __fastcall FUN_10013960(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021978;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100139d0 at 100139d0

void __fastcall FUN_100139d0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10013a00 at 10013a00

int __fastcall FUN_10013a00(int param_1)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100219d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset((void *)(param_1 + 0x10),0,0x18);
  local_8 = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10033e14 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar1 = thunk_FUN_10009440((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar1 < 0) {
    DAT_10033e4b = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013af0 at 10013af0

void __fastcall FUN_10013af0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021a06;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1000f370(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013b50 at 10013b50

void __fastcall FUN_10013b50(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10013b70 at 10013b70

void __fastcall FUN_10013b70(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10013b90 at 10013b90

undefined4 __fastcall FUN_10013b90(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10013bb0 at 10013bb0

int __thiscall FUN_10013bb0(void *this,undefined4 *param_1)

{
  int local_8;
  
  if (param_1 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    local_8 = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_8 = CoCreateInstance((IID *)&DAT_10029ff0,(LPUNKNOWN)0x0,1,(IID *)&DAT_10029708,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_8) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_8;
}



// Function: FUN_10013c50 at 10013c50

void FUN_10013c50(void)

{
  return;
}



// Function: FUN_10013ca0 at 10013ca0

undefined4 FUN_10013ca0(void)

{
  return 0x80004005;
}



// Function: FUN_10013cb0 at 10013cb0

undefined4 FUN_10013cb0(void)

{
  return 0x80004005;
}



// Function: FUN_10013cc0 at 10013cc0

void FUN_10013cc0(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  thunk_FUN_10013e30(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10013cf0 at 10013cf0

void FUN_10013cf0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  thunk_FUN_1000a320(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10013d20 at 10013d20

undefined4 * __thiscall FUN_10013d20(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021a66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 2;
  thunk_FUN_1000f370((int)this);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10013dc0 at 10013dc0

void __fastcall FUN_10013dc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021a9e;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  thunk_FUN_1000f370(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013e30 at 10013e30

/* WARNING: Removing unreachable block (ram,0x1001415f) */
/* WARNING: Removing unreachable block (ram,0x10013e84) */

int FUN_10013e30(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  errno_t eVar3;
  int iVar4;
  long local_b4c;
  int local_b30 [2];
  undefined4 local_b28;
  int local_b1c;
  wchar_t *local_b18;
  int local_b14;
  int local_b10 [2];
  undefined4 local_b08;
  int *local_afc;
  undefined4 *local_af8;
  int local_af4;
  int *local_aec;
  undefined4 *local_ae8;
  int *local_ae4;
  undefined4 *local_ae0;
  int *local_adc;
  int local_ad8;
  LPCWSTR local_ad4;
  int local_ad0;
  LPCWSTR local_acc;
  int local_ac8;
  int local_ac4 [2];
  undefined4 local_abc;
  long local_aac;
  int local_aa8;
  int local_aa4;
  int local_aa0;
  int local_a9c;
  long local_a98;
  int local_a94;
  int local_a8c;
  WCHAR local_a88;
  undefined2 local_a86 [523];
  WCHAR local_670 [520];
  WCHAR *local_260;
  int local_25c;
  wchar_t *local_258;
  int local_254;
  DWORD local_250;
  undefined **local_24c;
  int local_248 [4];
  undefined4 *local_238 [2];
  WCHAR local_230 [262];
  undefined4 local_24;
  HMODULE local_20;
  LPCWSTR local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021b86;
  local_10 = ExceptionList;
  local_24c = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  thunk_FUN_1000f150(local_248);
  local_8 = 1;
  local_254 = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_ad8 = param_4[1];
      local_ad4 = (LPCWSTR)*param_4;
      if ((local_ad4 != (LPCWSTR)0x0) && (local_ad8 != 0)) {
        local_abc = 3;
        local_ac4[0] = 0;
        local_8._0_1_ = 4;
        local_acc = local_ad4;
        local_ac8 = thunk_FUN_1000aed0(local_ad4,local_ad8);
        local_ad0 = (-(uint)(local_ac8 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        thunk_FUN_10012c90(local_ac4);
      }
    }
  }
  local_a94 = (**(code **)(*param_1 + 0x14))(&local_24c);
  local_254 = local_a94;
  if (local_a94 < 0) {
    local_24c = ATL::CRegObject::vftable;
    local_8 = 5;
    thunk_FUN_1000ba80((int)&local_24c);
    local_adc = local_248;
    local_8 = 6;
    thunk_FUN_1000b330(local_adc);
    local_8 = 0xffffffff;
    thunk_FUN_10012e90(local_adc);
  }
  else {
    local_24 = 3;
    local_238[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_20 = DAT_100341c4;
    local_250 = GetModuleFileNameW(DAT_100341c4,local_230,0x104);
    if (local_250 == 0) {
      local_a98 = ATL::AtlHresultFromLastError();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
        local_ae0 = local_238[0];
        local_238[0] = (undefined4 *)*local_238[0];
        free(puVar1);
      }
      local_24c = ATL::CRegObject::vftable;
      local_8 = 8;
      thunk_FUN_1000ba80((int)&local_24c);
      local_ae4 = local_248;
      local_8 = 9;
      thunk_FUN_1000b330(local_ae4);
      local_8 = 0xffffffff;
      thunk_FUN_10012e90(local_ae4);
      local_a94 = local_a98;
    }
    else if (local_250 == 0x104) {
      local_a9c = -0x7ff8ff86;
      local_8 = CONCAT31(local_8._1_3_,1);
      local_250 = 0x104;
      while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
        local_ae8 = local_238[0];
        local_238[0] = (undefined4 *)*local_238[0];
        free(puVar1);
      }
      local_24c = ATL::CRegObject::vftable;
      local_8 = 10;
      thunk_FUN_1000ba80((int)&local_24c);
      local_aec = local_248;
      local_8 = 0xb;
      thunk_FUN_1000b330(local_aec);
      local_8 = 0xffffffff;
      thunk_FUN_10012e90(local_aec);
      local_a94 = local_a9c;
    }
    else {
      local_260 = local_230;
      thunk_FUN_1000ada0(local_670,0x208,local_260);
      if ((local_20 == (HMODULE)0x0) ||
         (pHVar2 = GetModuleHandleW((LPCWSTR)0x0), local_20 == pHVar2)) {
        local_a88 = L'\"';
        local_af4 = lstrlenW(local_670);
        eVar3 = memcpy_s(local_a86,0x416,local_670,local_af4 * 2 + 2);
        if (eVar3 != 0) {
          local_aa0 = -0x7fffbffb;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
            local_af8 = local_238[0];
            local_238[0] = (undefined4 *)*local_238[0];
            free(puVar1);
          }
          local_24c = ATL::CRegObject::vftable;
          local_8 = 0xc;
          thunk_FUN_1000ba80((int)&local_24c);
          local_afc = local_248;
          local_8 = 0xd;
          thunk_FUN_1000b330(local_afc);
          local_8 = 0xffffffff;
          thunk_FUN_10012e90(local_afc);
          ExceptionList = local_10;
          return local_aa0;
        }
        local_a8c = lstrlenW(&local_a88);
        local_a86[local_a8c + -1] = 0x22;
        local_a86[local_a8c] = 0;
        if (&stack0x00000000 == (undefined1 *)0xa88) {
          local_25c = -0x7ff8ffa9;
        }
        else {
          local_b08 = 3;
          local_b10[0] = 0;
          local_8._0_1_ = 0xe;
          local_b18 = L"Module";
          local_b14 = thunk_FUN_1000aed0(L"Module",(int)&local_a88);
          local_b1c = (-(uint)(local_b14 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          thunk_FUN_10012c90(local_b10);
          local_25c = local_b1c;
        }
      }
      else if (&stack0x00000000 == (undefined1 *)0x670) {
        local_25c = -0x7ff8ffa9;
      }
      else {
        local_b28 = 3;
        local_b30[0] = 0;
        local_8._0_1_ = 0xf;
        iVar4 = thunk_FUN_1000aed0(L"Module",(int)local_670);
        local_8._0_1_ = 7;
        thunk_FUN_10012c90(local_b30);
        local_25c = (-(uint)(iVar4 != 0) & 0x7ff8fff2) + 0x8007000e;
      }
      if (local_25c < 0) {
        local_aa4 = local_25c;
        local_8 = CONCAT31(local_8._1_3_,1);
        while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
          local_238[0] = (undefined4 *)*local_238[0];
          free(puVar1);
        }
        local_24c = ATL::CRegObject::vftable;
        local_8 = 0x10;
        thunk_FUN_1000ba80((int)&local_24c);
        local_8 = 0x11;
        thunk_FUN_1000b330(local_248);
        local_8 = 0xffffffff;
        thunk_FUN_10012e90(local_248);
        local_a94 = local_aa4;
      }
      else {
        local_aa8 = thunk_FUN_1000b540(&local_24c,L"Module_Raw",(int)local_670);
        local_25c = local_aa8;
        if (local_aa8 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          thunk_FUN_10012c90((int *)local_238);
          local_8 = 0xffffffff;
          thunk_FUN_1000b460(&local_24c);
          local_a94 = local_aa8;
        }
        else {
          local_258 = L"REGISTRY";
          local_18 = param_2;
          if (param_3 == 0) {
            local_b4c = thunk_FUN_100149e0(&local_24c,local_260,param_2,L"REGISTRY");
          }
          else {
            local_b4c = thunk_FUN_100148d0(&local_24c,local_260,param_2,L"REGISTRY");
          }
          local_254 = local_b4c;
          local_aac = local_b4c;
          local_8 = CONCAT31(local_8._1_3_,1);
          thunk_FUN_10012c90((int *)local_238);
          local_8 = 0xffffffff;
          thunk_FUN_1000b460(&local_24c);
          local_a94 = local_aac;
        }
      }
    }
  }
  ExceptionList = local_10;
  return local_a94;
}



// Function: FUN_100148d0 at 100148d0

long FUN_100148d0(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  long local_30;
  undefined4 *local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021bd8;
  local_10 = ExceptionList;
  local_2c = (undefined4 *)0x0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_30 = -0x7ff8ffa9;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  else {
    ExceptionList = &local_10;
    local_30 = thunk_FUN_1000b6d0(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  ExceptionList = local_10;
  return local_30;
}



// Function: FUN_100149e0 at 100149e0

long FUN_100149e0(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  long local_30;
  undefined4 *local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021bf8;
  local_10 = ExceptionList;
  local_2c = (undefined4 *)0x0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_30 = -0x7ff8ffa9;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  else {
    ExceptionList = &local_10;
    local_30 = thunk_FUN_1000b6d0(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  ExceptionList = local_10;
  return local_30;
}



// Function: FUN_10014af0 at 10014af0

void __thiscall FUN_10014af0(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10028f7c,this);
  return;
}



// Function: FUN_10014b20 at 10014b20

int * __cdecl FUN_10014b20(int *param_1,int param_2)

{
  int *piVar1;
  wchar_t *local_6b4;
  int local_634;
  int local_630;
  int local_62c;
  int local_628;
  void *local_624;
  wchar_t local_620 [258];
  int local_41c;
  wchar_t local_418 [4];
  wchar_t local_410 [256];
  wchar_t local_210 [256];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021cbf;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_10033ed4 & 1) == 0) {
    DAT_10033ed4 = DAT_10033ed4 | 1;
    local_8 = 1;
    ExceptionList = &local_10;
    thunk_FUN_10008b20(&DAT_10033ed0,0x10028f80);
    _atexit(FUN_10025770);
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = thunk_FUN_10008b20(&local_624,param_2);
  local_8 = 2;
  if (*piVar1 == 0) {
    local_6b4 = (wchar_t *)0x0;
  }
  else {
    local_6b4 = *(wchar_t **)*piVar1;
  }
  _wsplitpath(local_6b4,local_418,local_620,local_210,local_410);
  local_8 = local_8 & 0xffffff00;
  if (local_624 != (void *)0x0) {
    thunk_FUN_10008d20(local_624);
    local_624 = (void *)0x0;
  }
  thunk_FUN_10008b20(&local_41c,(int)local_418);
  local_8 = 3;
  if (local_418[0] == L'\0') {
    thunk_FUN_10014e80(&local_41c,&DAT_10033ed0);
    if ((local_620[0] == L'\0') ||
       ((*(wchar_t *)PTR_DAT_10033780 != local_620[0] &&
        (*(wchar_t *)PTR_DAT_1003377c != local_620[0])))) {
      thunk_FUN_10008b20(&local_628,(int)PTR_DAT_10033780);
      local_8._0_1_ = 4;
      thunk_FUN_10014e80(&local_41c,&local_628);
      local_8 = CONCAT31(local_8._1_3_,3);
      thunk_FUN_10008c50(&local_628);
    }
  }
  thunk_FUN_10008b20(&local_62c,(int)local_620);
  local_8._0_1_ = 5;
  thunk_FUN_10014e80(&local_41c,&local_62c);
  local_8._0_1_ = 3;
  thunk_FUN_10008c50(&local_62c);
  thunk_FUN_10008b20(&local_630,(int)local_210);
  local_8._0_1_ = 6;
  thunk_FUN_10014e80(&local_41c,&local_630);
  local_8._0_1_ = 3;
  thunk_FUN_10008c50(&local_630);
  thunk_FUN_10008b20(&local_634,(int)local_410);
  local_8._0_1_ = 7;
  thunk_FUN_10014e80(&local_41c,&local_634);
  local_8 = CONCAT31(local_8._1_3_,3);
  thunk_FUN_10008c50(&local_634);
  *param_1 = local_41c;
  if (*param_1 != 0) {
    InterlockedIncrement((LONG *)(*param_1 + 8));
  }
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_10008c50(&local_41c);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10014e80 at 10014e80

int * __thiscall FUN_10014e80(void *this,int *param_1)

{
  void *this_00;
  int *local_58;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021cfb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = operator_new(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_58 = (int *)0x0;
  }
  else {
    local_58 = thunk_FUN_10014f60(this_00,(int *)this,param_1);
  }
  local_8 = 0xffffffff;
  if (local_58 == (int *)0x0) {
    FUN_1001dca0(0x8007000e);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
      thunk_FUN_10008d20(*this);
      *(undefined4 *)this = 0;
    }
    *(int **)this = local_58;
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10014f60 at 10014f60

int * __thiscall FUN_10014f60(void *this,int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *local_44;
  void *local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_30;
  uint local_14;
  void *local_10;
  void *local_c;
  int local_8;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if (*param_1 == 0) {
    local_34 = 0;
  }
  else {
    if (*(int *)*param_1 == 0) {
      local_30 = 0;
    }
    else {
      local_30 = Ordinal_7(*(int *)*param_1);
    }
    local_34 = local_30;
  }
  local_8 = local_34;
  if (*param_2 == 0) {
    local_3c = 0;
  }
  else {
    if (*(int *)*param_2 == 0) {
      local_38 = 0;
    }
    else {
      local_38 = Ordinal_7(*(int *)*param_2);
    }
    local_3c = local_38;
  }
  iVar1 = FUN_100151b0(local_8,local_3c,(int *)&local_14);
  if ((iVar1 < 0) || (iVar1 = FUN_100151e0(local_14,2,&local_14), iVar1 < 0)) {
    FUN_1001dca0(0x8007000e);
  }
  else {
    uVar2 = Ordinal_150(0,(local_8 + local_3c) * 2);
    *(undefined4 *)this = uVar2;
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      if (local_8 + local_3c != 0) {
        FUN_1001dca0(0x8007000e);
      }
    }
    else {
      if (*param_1 == 0) {
        local_40 = (void *)0x0;
      }
      else {
        local_40 = *(void **)*param_1;
      }
      local_10 = local_40;
      if (local_40 != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
        memcpy_s(*this,(local_8 + local_3c) * 2 + 2,local_40,local_8 * 2 + 2);
      }
      if (*param_2 == 0) {
        local_44 = (void *)0x0;
      }
      else {
        local_44 = *(void **)*param_2;
      }
      local_c = local_44;
      if (local_44 != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
        memcpy_s((void *)(*this + local_8 * 2),local_3c * 2 + 2,local_44,local_3c * 2 + 2);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_100151b0 at 100151b0

undefined4 __cdecl FUN_100151b0(int param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (param_1 + param_2 < param_2) {
    uVar1 = 0x80070216;
  }
  else {
    *param_3 = param_1 + param_2;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100151e0 at 100151e0

undefined4 __cdecl FUN_100151e0(uint param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_1 * (ulonglong)param_2);
    *param_3 = local_c;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070216;
  }
  return uVar1;
}



// Function: FUN_10015230 at 10015230

void __cdecl FUN_10015230(undefined2 *param_1,undefined4 *param_2)

{
  size_t sVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_270;
  undefined2 local_26c;
  undefined1 local_268 [16];
  uint local_258;
  LSTATUS local_24c;
  wchar_t local_248;
  undefined1 local_246 [522];
  undefined1 local_3c [28];
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10021d2b;
  local_10 = ExceptionList;
  if (param_1 == (undefined2 *)0x0) {
    return;
  }
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  local_248 = L'\0';
  ExceptionList = &local_10;
  memset(local_246,0,0x206);
  local_20 = 0x208;
  thunk_FUN_1001b390(local_3c,
                     L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\CS\\Locale\\");
  local_8._0_1_ = 1;
  local_24c = thunk_FUN_1000e090(&local_1c,(HKEY)0x80000002,
                                 L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale"
                                 ,0x2001f);
  if (local_24c != 0) goto LAB_100157c3;
  local_24c = thunk_FUN_1001b1b0(&local_1c,L"LanguageExt",(LPBYTE)&local_248,&local_20);
  if (local_24c == 0) {
    thunk_FUN_1001b390(local_268,&local_248);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_258 == 0) {
      sVar1 = wcslen(L"EN");
      thunk_FUN_1001c560(local_268,(undefined4 *)&DAT_10029a74,sVar1);
    }
    uVar3 = DAT_10034010;
    puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10034000);
    uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
    if (uVar3 == 0) {
LAB_10015691:
      local_26c = 0;
      local_270 = 0x4e4;
    }
    else {
      uVar3 = DAT_10034110;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10034100);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033f4c;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033f3c);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033ff4;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033fe4);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_100340f4;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_100340e4);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10034030;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10034020);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033f84;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033f74);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033fbc;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033fac);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10034084;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10034074);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_1003412c;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_1003411c);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033fa0;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033f90);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if (uVar3 == 0) goto LAB_10015691;
      uVar3 = DAT_10033fd8;
      puVar2 = (ushort *)thunk_FUN_1001c3b0((undefined4 *)&DAT_10033fc8);
      uVar3 = thunk_FUN_10019a20(local_268,0,local_258,puVar2,uVar3);
      if ((((uVar3 == 0) || (iVar4 = thunk_FUN_10017400(local_268,DAT_1003401c), iVar4 == 0)) ||
          (iVar4 = thunk_FUN_10017400(local_268,DAT_10034138), iVar4 == 0)) ||
         (iVar4 = thunk_FUN_10017400(local_268,DAT_1003413c), iVar4 == 0)) goto LAB_10015691;
      iVar4 = thunk_FUN_100173a0(local_268,(ushort *)&DAT_10034058);
      if (iVar4 == 0) {
        local_26c = 0xa2;
        local_270 = 0x4e6;
      }
      else {
        iVar4 = thunk_FUN_100173a0(local_268,(ushort *)&DAT_100340c8);
        if (iVar4 == 0) {
          local_26c = 0x86;
          local_270 = 0x3a8;
        }
        else {
          iVar4 = thunk_FUN_100173a0(local_268,(ushort *)&DAT_10034090);
          if (iVar4 == 0) {
            local_26c = 0x80;
            local_270 = 0x3a4;
          }
          else {
            iVar4 = thunk_FUN_100173a0(local_268,(ushort *)&DAT_10033f58);
            if (iVar4 == 0) {
              local_26c = 0x81;
              local_270 = 0x3b5;
            }
            else {
              iVar4 = thunk_FUN_100173a0(local_268,(ushort *)&DAT_1003403c);
              if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
                _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
              }
              local_26c = 0xcc;
              local_270 = 0x4e3;
            }
          }
        }
      }
    }
    *param_1 = local_26c;
    *param_2 = local_270;
    local_8._0_1_ = 1;
    thunk_FUN_1001b430(local_268);
  }
  ATL::CRegKey::Close((CRegKey *)&local_1c);
LAB_100157c3:
  local_8 = (uint)local_8._1_3_ << 8;
  thunk_FUN_1001b430(local_3c);
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_1c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015960 at 10015960

void * __cdecl FUN_10015960(void *param_1,ulong param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [80];
  basic_ios<char,struct_std::char_traits<char>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021d6a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_10017450(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  thunk_FUN_100175e0(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_10017530((int)local_58);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015a20 at 10015a20

void __fastcall FUN_10015a20(int param_1)

{
  thunk_FUN_10017530(param_1 + 0x60);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_10015a50 at 10015a50

void * __cdecl FUN_10015a50(void *param_1,ulong param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [80];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021dba;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_100184a0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  thunk_FUN_10018670(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_100185c0((int)local_58);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015b10 at 10015b10

void __fastcall FUN_10015b10(int param_1)

{
  thunk_FUN_100185c0(param_1 + 0x60);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_10015b40 at 10015b40

void * __cdecl FUN_10015b40(void *param_1,long param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [80];
  basic_ios<char,struct_std::char_traits<char>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021e0a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_10017450(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  thunk_FUN_100175e0(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_10017530((int)local_58);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015c00 at 10015c00

/* WARNING: Removing unreachable block (ram,0x10015c2f) */
/* WARNING: Removing unreachable block (ram,0x10015c4d) */

int * __cdecl FUN_10015c00(int *param_1,int param_2)

{
  int iVar1;
  undefined2 local_20 [4];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10021e51;
  local_10 = ExceptionList;
  local_20[0] = 3;
  local_18 = param_2;
  local_8 = 1;
  ExceptionList = &local_10;
  thunk_FUN_10017220(8,(int)local_20,0,0x409);
  if (local_18 == 0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(local_18);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      thunk_FUN_10004720(0x8007000e);
    }
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015d30 at 10015d30

void * __cdecl FUN_10015d30(void *param_1,long param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [80];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021e9a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_100184a0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  thunk_FUN_10018670(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_100185c0((int)local_58);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015df0 at 10015df0

void * __cdecl FUN_10015df0(void *param_1,float param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [80];
  basic_ios<char,struct_std::char_traits<char>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021eea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_10017450(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  thunk_FUN_100175e0(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_10017530((int)local_58);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015eb0 at 10015eb0

void * __cdecl FUN_10015eb0(void *param_1,float param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [80];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_58 [72];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021f3a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_100184a0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  thunk_FUN_10018670(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  thunk_FUN_100185c0((int)local_58);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015f70 at 10015f70

void * __cdecl FUN_10015f70(void *param_1,undefined4 *param_2)

{
  int *piVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021f81;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = thunk_FUN_10016420(&local_14,param_2);
  local_8 = 1;
  thunk_FUN_100160d0(param_1,(LPCWSTR)*piVar1);
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016020 at 10016020

void * __cdecl FUN_10016020(void *param_1,LPCSTR param_2)

{
  int *piVar1;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021fc1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = thunk_FUN_10016350(&local_14,param_2);
  local_8 = 1;
  thunk_FUN_10016290(param_1,(wchar_t *)*piVar1);
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100160d0 at 100160d0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void * __cdecl FUN_100160d0(void *param_1,LPCWSTR param_2)

{
  char *local_90;
  char *local_8c;
  void *local_88;
  char *local_4c;
  char *local_48;
  int local_44;
  undefined1 local_2d;
  undefined1 *local_2c;
  undefined4 local_24;
  UINT local_1c;
  LPCWSTR local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022001;
  local_10 = ExceptionList;
  local_24 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    local_2c = &local_2d;
    local_88 = param_1;
    local_8 = 1;
    ExceptionList = &local_10;
    thunk_FUN_1001b590(param_1,'\0',0);
  }
  else {
    local_1c = 3;
    local_18 = param_2;
    if (param_2 == (LPCWSTR)0x0) {
      local_8c = (char *)0x0;
      ExceptionList = &local_10;
    }
    else {
      ExceptionList = &local_10;
      local_14 = lstrlenW(param_2);
      local_14 = local_14 + 1;
      if (local_14 < 0x40000000) {
        local_48 = (char *)&local_90;
        local_90 = local_4c;
        if ((&stack0x00000000 == (undefined1 *)0x90) || (local_18 == (LPCWSTR)0x0)) {
          local_90 = (char *)0x0;
          local_48 = (char *)&local_90;
        }
        else {
                    /* WARNING: Ignoring partial resolution of indirect */
          local_90._0_1_ = 0;
          local_44 = WideCharToMultiByte(local_1c,0,local_18,-1,(LPSTR)&local_90,local_14 * 2,
                                         (LPCSTR)0x0,(LPBOOL)0x0);
          if (local_44 == 0) {
            local_90 = (char *)0x0;
          }
          else {
            local_90 = local_48;
          }
        }
      }
      else {
        local_90 = (char *)0x0;
      }
      local_8c = local_90;
    }
    thunk_FUN_1001b290(param_1,local_8c);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016290 at 10016290

void * __cdecl FUN_10016290(void *param_1,wchar_t *param_2)

{
  undefined1 local_2d;
  undefined1 *local_2c;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022041;
  local_10 = ExceptionList;
  local_24 = 0;
  if (param_2 == (wchar_t *)0x0) {
    local_2c = &local_2d;
    local_8 = 1;
    ExceptionList = &local_10;
    thunk_FUN_1001c2a0(param_1,'\0',0);
  }
  else {
    local_1c = 3;
    ExceptionList = &local_10;
    thunk_FUN_1001b390(param_1,param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016350 at 10016350

int * __cdecl FUN_10016350(int *param_1,LPCSTR param_2)

{
  LPWSTR pWVar1;
  LPCSTR local_4c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022079;
  local_10 = ExceptionList;
  if (*(uint *)(param_2 + 0x14) < 0x10) {
    local_4c = param_2;
  }
  else {
    local_4c = *(LPCSTR *)param_2;
  }
  if (local_4c == (LPCSTR)0x0) {
    *param_1 = 0;
  }
  else {
    ExceptionList = &local_10;
    pWVar1 = thunk_FUN_10018060(local_4c,-1);
    *param_1 = (int)pWVar1;
    if (*param_1 == 0) {
      thunk_FUN_10004720(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016420 at 10016420

int * __cdecl FUN_10016420(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100220a9;
  local_10 = ExceptionList;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    ExceptionList = &local_10;
    iVar1 = Ordinal_2(param_2,param_2,0);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      thunk_FUN_10004720(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100164e0 at 100164e0

int __cdecl FUN_100164e0(char param_1)

{
  return -(uint)(param_1 != '\0');
}



// Function: FUN_100164f0 at 100164f0

bool __cdecl FUN_100164f0(char param_1)

{
  return param_1 != '\0';
}



// Function: FUN_10016510 at 10016510

undefined4 __cdecl FUN_10016510(short param_1)

{
  return CONCAT31((int3)(char)((ushort)param_1 >> 8),param_1 == -1);
}



// Function: FUN_10016530 at 10016530

bool __cdecl FUN_10016530(int param_1)

{
  return param_1 != 0;
}



// Function: FUN_10016550 at 10016550

undefined4 __cdecl FUN_10016550(int param_1)

{
  undefined2 local_20 [4];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100220c8;
  local_10 = ExceptionList;
  local_20[0] = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001aca0(local_20,param_1);
  local_8 = 0;
  thunk_FUN_10017220(3,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100165f0 at 100165f0

float10 __cdecl FUN_100165f0(int param_1)

{
  undefined2 local_20 [4];
  float local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100220e8;
  local_10 = ExceptionList;
  local_20[0] = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001aca0(local_20,param_1);
  local_8 = 0;
  thunk_FUN_10017220(4,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10016690 at 10016690

float10 __cdecl FUN_10016690(int param_1)

{
  undefined2 local_20 [4];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022108;
  local_10 = ExceptionList;
  local_20[0] = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001aca0(local_20,param_1);
  local_8 = 0;
  thunk_FUN_10017220(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10016730 at 10016730

void __cdecl FUN_10016730(char *param_1)

{
  char *local_8;
  
  if (*(uint *)(param_1 + 0x14) < 0x10) {
    local_8 = param_1;
  }
  else {
    local_8 = *(char **)param_1;
  }
  atol(local_8);
  return;
}



// Function: FUN_10016770 at 10016770

float10 __cdecl FUN_10016770(LPCSTR param_1)

{
  LPCSTR local_78;
  undefined2 local_20 [4];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022128;
  local_10 = ExceptionList;
  if (*(uint *)(param_1 + 0x14) < 0x10) {
    local_78 = param_1;
  }
  else {
    local_78 = *(LPCSTR *)param_1;
  }
  local_20[0] = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001ad40(local_20,local_78);
  local_8 = 0;
  thunk_FUN_10017220(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10016820 at 10016820

float10 __cdecl FUN_10016820(undefined4 *param_1)

{
  undefined4 *local_30;
  undefined2 local_20 [4];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022148;
  local_10 = ExceptionList;
  if ((uint)param_1[5] < 8) {
    local_30 = param_1;
  }
  else {
    local_30 = (undefined4 *)*param_1;
  }
  local_20[0] = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001aca0(local_20,(int)local_30);
  local_8 = 0;
  thunk_FUN_10017220(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_100168d0 at 100168d0

float10 __cdecl FUN_100168d0(char *param_1)

{
  double dVar1;
  char *local_18;
  
  if (*(uint *)(param_1 + 0x14) < 0x10) {
    local_18 = param_1;
  }
  else {
    local_18 = *(char **)param_1;
  }
  dVar1 = atof(local_18);
  return (float10)(float)dVar1;
}



// Function: FUN_10016920 at 10016920

void __cdecl FUN_10016920(wchar_t *param_1)

{
  wchar_t *local_8;
  
  if (*(uint *)(param_1 + 10) < 8) {
    local_8 = param_1;
  }
  else {
    local_8 = *(wchar_t **)param_1;
  }
  _wtol(local_8);
  return;
}



// Function: FUN_10016960 at 10016960

undefined2 * __cdecl FUN_10016960(undefined2 *param_1,LPCSTR param_2)

{
  LPCSTR local_70;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022179;
  local_10 = ExceptionList;
  if (*(uint *)(param_2 + 0x14) < 0x10) {
    local_70 = param_2;
  }
  else {
    local_70 = *(LPCSTR *)param_2;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  thunk_FUN_1001ad40(param_1,local_70);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100169f0 at 100169f0

undefined2 * __cdecl FUN_100169f0(undefined2 *param_1,undefined4 *param_2)

{
  undefined4 *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100221a9;
  local_10 = ExceptionList;
  if ((uint)param_2[5] < 8) {
    local_1c = param_2;
  }
  else {
    local_1c = (undefined4 *)*param_2;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  thunk_FUN_1001aca0(param_1,(int)local_1c);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016a80 at 10016a80

undefined8 __cdecl FUN_10016a80(SYSTEMTIME *param_1)

{
  BOOL BVar1;
  undefined4 local_18 [3];
  _FILETIME local_c;
  
  BVar1 = SystemTimeToFileTime(param_1,&local_c);
  if (BVar1 == 0) {
    local_18[0] = 0x80004005;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_1002fe28);
  }
  return CONCAT44(local_c.dwHighDateTime,local_c.dwLowDateTime);
}



// Function: FUN_10016ae0 at 10016ae0

undefined4 * __cdecl FUN_10016ae0(undefined4 *param_1,DWORD param_2,DWORD param_3)

{
  BOOL BVar1;
  undefined4 local_20;
  _SYSTEMTIME local_1c;
  FILETIME local_c;
  
  local_c.dwHighDateTime = param_3;
  local_c.dwLowDateTime = param_2;
  BVar1 = FileTimeToSystemTime(&local_c,&local_1c);
  if (BVar1 == 0) {
    local_20 = 0x80004005;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_1002fe28);
  }
  *param_1 = local_1c._0_4_;
  param_1[1] = local_1c._4_4_;
  param_1[2] = local_1c._8_4_;
  param_1[3] = local_1c._12_4_;
  return param_1;
}



// Function: FUN_10016b50 at 10016b50

void __cdecl FUN_10016b50(void *param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  wchar_t *local_48;
  wchar_t *local_28;
  wchar_t *local_10;
  uint local_8;
  
  if (*(uint *)(param_2 + 10) < 8) {
    local_10 = param_2;
  }
  else {
    local_10 = *(wchar_t **)param_2;
  }
  sVar3 = wcslen(local_10);
  for (local_8 = thunk_FUN_1001c040(param_1,(ushort *)local_10,0,sVar3); local_8 != 0xffffffff;
      local_8 = thunk_FUN_1001c040(param_1,(ushort *)local_28,local_8 + iVar1,sVar3)) {
    if (*(uint *)(param_3 + 10) < 8) {
      local_48 = param_3;
    }
    else {
      local_48 = *(wchar_t **)param_3;
    }
    uVar2 = *(uint *)(param_2 + 8);
    sVar3 = wcslen(local_48);
    thunk_FUN_100196b0(param_1,local_8,uVar2,(undefined4 *)local_48,sVar3);
    iVar1 = *(int *)(param_3 + 8);
    if (*(uint *)(param_2 + 10) < 8) {
      local_28 = param_2;
    }
    else {
      local_28 = *(wchar_t **)param_2;
    }
    sVar3 = wcslen(local_28);
  }
  return;
}



// Function: FUN_10016c80 at 10016c80

void * __cdecl FUN_10016c80(void *param_1,undefined4 *param_2,int param_3)

{
  undefined1 local_d5;
  undefined1 *local_d4;
  undefined1 local_c9;
  undefined1 *local_c8;
  uint local_84;
  wchar_t local_80 [14];
  wchar_t local_64 [14];
  undefined4 local_48 [7];
  wchar_t local_2c [14];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022229;
  local_10 = ExceptionList;
  local_84 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001b390(local_64,L"\r\n");
  local_8 = 1;
  thunk_FUN_1001b390(local_80,L"\n");
  local_8._0_1_ = 2;
  thunk_FUN_1001b390(local_2c,L"\r");
  local_c8 = &local_c9;
  local_8._0_1_ = 4;
  thunk_FUN_1001c2a0(local_48,'\0',0);
  thunk_FUN_1001b760(local_48,param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,5);
  thunk_FUN_10016b50(local_48,local_64,local_80);
  thunk_FUN_10016b50(local_48,local_2c,local_80);
  thunk_FUN_10016b50(local_48,local_80,local_64);
  if (param_3 == 1) {
    thunk_FUN_10016b50(local_48,local_64,local_80);
  }
  else if (param_3 == 2) {
    thunk_FUN_10016b50(local_48,local_64,local_2c);
  }
  local_d4 = &local_d5;
  local_8._0_1_ = 6;
  thunk_FUN_1001c2a0(param_1,'\0',0);
  thunk_FUN_1001b660(param_1,local_48);
  local_84 = local_84 | 1;
  local_8._0_1_ = 7;
  thunk_FUN_1001c2a0(local_48,'\x01',0);
  local_8._0_1_ = 8;
  thunk_FUN_1001c2a0(local_2c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,9);
  thunk_FUN_1001c2a0(local_80,'\x01',0);
  local_8 = 10;
  thunk_FUN_1001c2a0(local_64,'\x01',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016eb0 at 10016eb0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void * __cdecl FUN_10016eb0(void *param_1,wchar_t *param_2)

{
  wchar_t *local_c4;
  char *local_b0;
  char local_ac [132];
  uint local_28 [3];
  char *local_1c;
  undefined2 local_18 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002227a;
  local_10 = ExceptionList;
  local_28[1] = 3;
  local_18[0] = 0;
  local_28[0] = 0x4e4;
  ExceptionList = &local_10;
  thunk_FUN_10015230(local_18,local_28);
  if (*(uint *)(param_2 + 10) < 8) {
    local_c4 = param_2;
  }
  else {
    local_c4 = *(wchar_t **)param_2;
  }
  local_b0 = local_ac;
  ATL::CW2AEX<128>::Init((CW2AEX<128> *)&local_b0,local_c4,local_28[0]);
  local_1c = local_b0;
  local_8 = 0;
  if (local_b0 != local_ac) {
    free(local_b0);
  }
  thunk_FUN_1001b290(param_1,local_1c);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017010 at 10017010

void * __cdecl FUN_10017010(void *param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  undefined1 local_2c [28];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100222c9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pwVar1 = (wchar_t *)thunk_FUN_10016290(local_2c,param_2);
  local_8 = 1;
  thunk_FUN_10016eb0(param_1,pwVar1);
  local_8 = 2;
  thunk_FUN_1001c2a0(local_2c,'\x01',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100170c0 at 100170c0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void * __cdecl FUN_100170c0(void *param_1,char *param_2)

{
  char *local_144;
  wchar_t *local_130;
  wchar_t local_12c [130];
  uint local_28 [3];
  wchar_t *local_1c;
  undefined2 local_18 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002230a;
  local_10 = ExceptionList;
  local_28[1] = 3;
  local_18[0] = 0;
  local_28[0] = 0x4e4;
  ExceptionList = &local_10;
  thunk_FUN_10015230(local_18,local_28);
  if (*(uint *)(param_2 + 0x14) < 0x10) {
    local_144 = param_2;
  }
  else {
    local_144 = *(char **)param_2;
  }
  local_130 = local_12c;
  ATL::CA2WEX<128>::Init((CA2WEX<128> *)&local_130,local_144,local_28[0]);
  local_1c = local_130;
  local_8 = 0;
  if (local_130 != local_12c) {
    free(local_130);
  }
  thunk_FUN_1001b390(param_1,local_1c);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017220 at 10017220

void __cdecl FUN_10017220(undefined2 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 local_8;
  
  local_8 = param_3;
  if (param_3 == 0) {
    local_8 = param_2;
  }
  Ordinal_147(local_8,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10017260 at 10017260

long __cdecl FUN_10017260(wchar_t *param_1)

{
  long lVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  wchar_t *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022338;
  local_10 = ExceptionList;
  local_8 = 0;
  uVar2 = 0xfffffc19;
  uVar4 = 0x10;
  ExceptionList = &local_10;
  pwVar3 = param_1;
  lVar1 = wcstol(param_1,&local_14,0x10);
  local_8 = 0xffffffff;
  Ordinal_6(param_1,lVar1,uVar2,pwVar3,lVar1,uVar4);
  ExceptionList = local_10;
  return lVar1;
}



// Function: FUN_10017300 at 10017300

void * __cdecl FUN_10017300(void *param_1,undefined4 param_2)

{
  wchar_t local_1a0 [200];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002236f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  swprintf_s(local_1a0,400,L"%X",param_2);
  thunk_FUN_1001b390(param_1,local_1a0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100173a0 at 100173a0

void __thiscall FUN_100173a0(void *this,ushort *param_1)

{
  ushort *local_28;
  
  if (*(uint *)(param_1 + 10) < 8) {
    local_28 = param_1;
  }
  else {
    local_28 = *(ushort **)param_1;
  }
  thunk_FUN_10019a20(this,0,*(uint *)((int)this + 0x10),local_28,*(uint *)(param_1 + 8));
  return;
}



// Function: FUN_10017400 at 10017400

void __thiscall FUN_10017400(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  thunk_FUN_10019a20(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FUN_10017450 at 10017450

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_10017450(void *this,uint param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100223c4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    ExceptionList = &local_10;
    *(undefined **)this = &DAT_10029bf8;
    *(undefined **)((int)this + 0x10) = &DAT_10029bec;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x60));
    local_8 = 0;
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  thunk_FUN_10019b80((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10017530 at 10017530

void __fastcall FUN_10017530(int param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x60 + *(int *)(*(int *)(param_1 + -0x60) + 4)) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  this = (basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x48);
  *(undefined ***)this =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  thunk_FUN_1001a0b0(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(this);
  local_8 = 0xffffffff;
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x48));
  ExceptionList = local_10;
  return;
}



// Function: FUN_100175e0 at 100175e0

void * __thiscall FUN_100175e0(void *this,void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022439;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_10019d10((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017650 at 10017650

void __fastcall FUN_10017650(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022459;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  local_8 = 0;
  thunk_FUN_1001a0b0(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100176c0 at 100176c0

/* WARNING: Removing unreachable block (ram,0x10017736) */

int __thiscall FUN_100176c0(void *this,int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_c;
  
  if ((((*(uint *)((int)this + 0x40) & 8) != 0) &&
      (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                          ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
      pcVar1 != (char *)0x0)) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 < *(char **)((int)this + 0x3c))) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar1 = *(char **)((int)this + 0x3c);
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar1,pcVar2);
  }
  if (param_1 == -1) {
    local_3c = 0;
  }
  else {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if (pcVar1 != (char *)0x0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      if (pcVar1 < pcVar2) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        *pcVar1 = (char)param_1;
        return param_1;
      }
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      if (pcVar1 == (char *)0x0) {
        local_40 = 0;
      }
      else {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        local_40 = (int)pcVar1 - (int)pcVar2;
      }
      if (local_40 >> 1 < 0x20) {
        local_44 = 0x20;
      }
      else {
        local_44 = local_40 >> 1;
      }
      for (local_c = local_44; (local_c != 0 && (0x7fffffff - local_c < local_40));
          local_c = local_c >> 1) {
      }
      if (local_c == 0) {
        local_3c = -1;
      }
      else {
        local_c = local_40 + local_c;
        pcVar1 = (char *)thunk_FUN_1001d490(local_c);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        if (local_40 == 0) {
          *(char **)((int)this + 0x3c) = pcVar1;
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,
                     pcVar1 + local_c);
          if ((*(uint *)((int)this + 0x40) & 4) == 0) {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,pcVar1,
                       pcVar1 + 1);
          }
          else {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,
                       (char *)0x0,pcVar1);
          }
        }
        else {
          memcpy(pcVar1,pcVar2,local_40);
          *(char **)((int)this + 0x3c) = pcVar1 + (*(int *)((int)this + 0x3c) - (int)pcVar2);
          pcVar5 = pcVar1 + local_c;
          pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar3 = pcVar1 + ((int)pcVar3 - (int)pcVar2);
          pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     pcVar1 + ((int)pcVar4 - (int)pcVar2),pcVar3,pcVar5);
          if ((*(uint *)((int)this + 0x40) & 4) == 0) {
            pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar3 = pcVar3 + 1;
            pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,
                       pcVar1 + ((int)pcVar4 - (int)pcVar2),pcVar3);
          }
          else {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,
                       (char *)0x0,pcVar1);
          }
        }
        if ((*(uint *)((int)this + 0x40) & 1) != 0) {
          operator_delete(pcVar2);
        }
        *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        *pcVar1 = (char)param_1;
        local_3c = param_1;
      }
    }
    else {
      local_3c = -1;
    }
  }
  return local_3c;
}



// Function: FUN_10017a70 at 10017a70

int __thiscall FUN_10017a70(void *this,int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if ((pcVar2 < pcVar1) &&
       (((param_1 == -1 ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
         (char)param_1 == pcVar1[-1])) || ((*(uint *)((int)this + 0x40) & 2) == 0)))) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,-1);
      if (param_1 == -1) {
        return 0;
      }
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      *pcVar1 = (char)param_1;
      return param_1;
    }
  }
  return -1;
}



// Function: FUN_10017b90 at 10017b90

uint __fastcall FUN_10017b90(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
  if (pcVar2 <= pcVar1) {
    if (((*(uint *)(param_1 + 0x40) & 4) == 0) &&
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1),
       pcVar1 != (char *)0x0)) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
      if ((pcVar2 < pcVar1) ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1),
         pcVar1 < *(char **)(param_1 + 0x3c))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
        if (*(char **)(param_1 + 0x3c) < pcVar1) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
          *(char **)(param_1 + 0x3c) = pcVar1;
        }
        pcVar1 = *(char **)(param_1 + 0x3c);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                  (param_1,pcVar4,pcVar2,pcVar1);
        pbVar3 = (byte *)std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        return (uint)*pbVar3;
      }
    }
    return 0xffffffff;
  }
  pbVar3 = (byte *)std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  return (uint)*pbVar3;
}



// Function: FUN_10017cd0 at 10017cd0

uint * __thiscall
FUN_10017cd0(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  if (((param_5 & 1) == 0) ||
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 == (char *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if (param_2 != 0 || param_3 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (param_4 == 2) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        bVar6 = CARRY4(uVar4,param_2);
        param_2 = uVar4 + param_2;
        param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
      }
      else if (param_4 == 1) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = (int)pcVar1 - (int)pcVar2;
        bVar6 = CARRY4(uVar4,param_2);
        param_2 = uVar4 + param_2;
        param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar1 + (param_2 - (int)pcVar2)));
          goto LAB_10017f6e;
        }
      }
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
  }
  else {
    if (param_4 == 2) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      bVar6 = CARRY4(uVar4,param_2);
      param_2 = uVar4 + param_2;
      param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
    }
    else if ((param_4 == 1) && ((param_5 & 2) == 0)) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = (int)pcVar1 - (int)pcVar2;
      bVar6 = CARRY4(uVar4,param_2);
      param_2 = uVar4 + param_2;
      param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
    }
    else if (param_4 != 0) {
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    if (-1 < (int)param_3) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      iVar5 = (int)uVar4 >> 0x1f;
      if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                  ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                   (int)(pcVar1 + (param_2 - (int)pcVar2)));
        if (((param_5 & 2) != 0) &&
           (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
           pcVar1 != (char *)0x0)) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                     pcVar1);
        }
        goto LAB_10017f6e;
      }
    }
    param_2 = *(uint *)_BADOFF_exref;
    param_3 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_10017f6e:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10018060 at 10018060

LPWSTR __cdecl FUN_10018060(LPCSTR param_1,int param_2)

{
  undefined4 *puVar1;
  int cchWideChar;
  int iVar2;
  LPWSTR local_38;
  undefined4 *local_28;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022478;
  local_10 = ExceptionList;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
    local_38 = (LPWSTR)0x0;
  }
  else {
    local_28 = (undefined4 *)0x0;
    local_8 = 0;
    ExceptionList = &local_10;
    cchWideChar = MultiByteToWideChar(3,0,param_1,param_2,(LPWSTR)0x0,0);
    local_1c = cchWideChar;
    if (param_2 == -1) {
      local_1c = cchWideChar + -1;
    }
    local_38 = (LPWSTR)Ordinal_4(0,local_1c);
    if ((local_38 == (LPWSTR)0x0) ||
       (iVar2 = MultiByteToWideChar(3,0,param_1,param_2,local_38,cchWideChar), iVar2 == cchWideChar)
       ) {
      local_8 = 0xffffffff;
      while (local_28 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*local_28;
        free(local_28);
        local_28 = puVar1;
      }
    }
    else {
      Ordinal_6(local_38);
      local_38 = (LPWSTR)0x0;
      local_8 = 0xffffffff;
      while (local_28 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*local_28;
        free(local_28);
        local_28 = puVar1;
      }
    }
  }
  ExceptionList = local_10;
  return local_38;
}



// Function: FUN_100181f0 at 100181f0

uint * __thiscall FUN_100181f0(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint in_stack_00000020;
  uint local_c;
  uint local_8;
  
  local_c = param_4 + param_2;
  local_8 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  if ((local_c != *(uint *)_BADOFF_exref) || (local_8 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if (((in_stack_00000020 & 2) == 0) ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
         pcVar1 == (char *)0x0)) {
        local_c = *(uint *)_BADOFF_exref;
        local_8 = *(uint *)(_BADOFF_exref + 4);
      }
      else {
        if (-1 < (int)local_8) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
          iVar5 = (int)uVar4 >> 0x1f;
          if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (local_c <= uVar4)))) {
            pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                       (int)(pcVar1 + (local_c - (int)pcVar2)));
            goto LAB_100183d6;
          }
        }
        local_c = *(uint *)_BADOFF_exref;
        local_8 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (-1 < (int)local_8) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (local_c <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar1 + (local_c - (int)pcVar2)));
          if (((in_stack_00000020 & 2) != 0) &&
             (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                                 ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
             pcVar1 != (char *)0x0)) {
            pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                       pcVar1);
          }
          goto LAB_100183d6;
        }
      }
      local_c = *(uint *)_BADOFF_exref;
      local_8 = *(uint *)(_BADOFF_exref + 4);
    }
  }
LAB_100183d6:
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_100184a0 at 100184a0

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100184a0(void *this,uint param_1,int param_2)

{
  uint uVar1;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100224cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    ExceptionList = &local_10;
    *(undefined **)this = &DAT_10029cbc;
    *(undefined **)((int)this + 0x10) = &DAT_10029cb0;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x60));
    local_8 = 0;
  }
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
             (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  this_00 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this_00);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined ***)this_00 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  uVar1 = thunk_FUN_1001aac0(param_1);
  thunk_FUN_1001a960(this_00,(void *)0x0,0,uVar1);
  ExceptionList = local_10;
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100185c0 at 100185c0

void __fastcall FUN_100185c0(int param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022510;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x60 + *(int *)(*(int *)(param_1 + -0x60) + 4)) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  thunk_FUN_1001a520(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  local_8 = 0xffffffff;
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018670 at 10018670

void * __thiscall FUN_10018670(void *this,void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022549;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_1001a180((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100186e0 at 100186e0

void __fastcall FUN_100186e0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022569;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  thunk_FUN_1001a520(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018750 at 10018750

/* WARNING: Removing unreachable block (ram,0x100187d6) */

wchar_t __thiscall FUN_10018750(void *this,wchar_t param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  uint local_40;
  uint local_3c;
  uint local_c;
  
  if ((((*(uint *)((int)this + 0x40) & 8) != 0) &&
      (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                          ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
      pwVar1 != (wchar_t *)0x0)) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     pwVar1 < *(wchar_t **)((int)this + 0x3c))) {
    pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    pwVar1 = *(wchar_t **)((int)this + 0x3c);
    pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar3,pwVar1,
               pwVar2);
  }
  if (param_1 == L'\xffff') {
    param_1 = L'\0';
  }
  else {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    if (pwVar1 != (wchar_t *)0x0) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      if (pwVar1 < pwVar2) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        *pwVar1 = param_1;
        return param_1;
      }
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      if (pwVar1 == (wchar_t *)0x0) {
        local_3c = 0;
      }
      else {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        local_3c = (int)pwVar1 - (int)pwVar2 >> 1;
      }
      if (local_3c >> 1 < 0x20) {
        local_40 = 0x20;
      }
      else {
        local_40 = local_3c >> 1;
      }
      for (local_c = local_40; (local_c != 0 && (0x7fffffff - local_c < local_3c));
          local_c = local_c >> 1) {
      }
      if (local_c == 0) {
        param_1 = L'\xffff';
      }
      else {
        local_c = local_3c + local_c;
        pwVar1 = (wchar_t *)thunk_FUN_1001d3d0(local_c);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        if (local_3c == 0) {
          *(wchar_t **)((int)this + 0x3c) = pwVar1;
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                     pwVar1 + local_c);
          if ((*(uint *)((int)this + 0x40) & 4) == 0) {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                       pwVar1,pwVar1 + 1);
          }
          else {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                       (wchar_t *)0x0,pwVar1);
          }
        }
        else {
          memcpy(pwVar1,pwVar2,local_3c << 1);
          *(wchar_t **)((int)this + 0x3c) = pwVar1 + (*(int *)((int)this + 0x3c) - (int)pwVar2 >> 1)
          ;
          pwVar3 = pwVar1 + local_c;
          pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar4 = pwVar1 + ((int)pwVar4 - (int)pwVar2 >> 1);
          pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     pwVar1 + ((int)pwVar5 - (int)pwVar2 >> 1),pwVar4,pwVar3);
          if ((*(uint *)((int)this + 0x40) & 4) == 0) {
            pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar3 = pwVar3 + 1;
            pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                       pwVar1 + ((int)pwVar4 - (int)pwVar2 >> 1),pwVar3);
          }
          else {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                       (wchar_t *)0x0,pwVar1);
          }
        }
        if ((*(uint *)((int)this + 0x40) & 1) != 0) {
          operator_delete(pwVar2);
        }
        *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        *pwVar1 = param_1;
      }
    }
    else {
      param_1 = L'\xffff';
    }
  }
  return param_1;
}



// Function: FUN_10018b50 at 10018b50

wchar_t __thiscall FUN_10018b50(void *this,wchar_t param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if (pwVar1 != (wchar_t *)0x0) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    if ((pwVar2 < pwVar1) &&
       (((param_1 == L'\xffff' ||
         (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
         param_1 == pwVar1[-1])) || ((*(uint *)((int)this + 0x40) & 2) == 0)))) {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,-1);
      if (param_1 == L'\xffff') {
        return L'\0';
      }
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *pwVar1 = param_1;
      return param_1;
    }
  }
  return L'\xffff';
}



// Function: FUN_10018ca0 at 10018ca0

wchar_t __fastcall FUN_10018ca0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  if (pwVar1 == (wchar_t *)0x0) {
    return L'\xffff';
  }
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr(param_1);
  if (pwVar2 <= pwVar1) {
    if (((*(uint *)(param_1 + 0x40) & 4) == 0) &&
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1),
       pwVar1 != (wchar_t *)0x0)) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
      if ((pwVar2 < pwVar1) ||
         (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1),
         pwVar1 < *(wchar_t **)(param_1 + 0x3c))) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
        if (*(wchar_t **)(param_1 + 0x3c) < pwVar1) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
          *(wchar_t **)(param_1 + 0x3c) = pwVar1;
        }
        pwVar1 = *(wchar_t **)(param_1 + 0x3c);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
        pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  (param_1,pwVar3,pwVar2,pwVar1);
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
        return *pwVar1;
      }
    }
    return L'\xffff';
  }
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  return *pwVar1;
}



// Function: FUN_10018e00 at 10018e00

uint * __thiscall
FUN_10018e00(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((pwVar1 != (wchar_t *)0x0) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     *(wchar_t **)((int)this + 0x3c) < pwVar1)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *(wchar_t **)((int)this + 0x3c) = pwVar1;
  }
  if (((param_5 & 1) == 0) ||
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     pwVar1 == (wchar_t *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
       pwVar1 == (wchar_t *)0x0)) {
      if (param_2 != 0 || param_3 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (param_4 == 2) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        uVar5 = iVar4 >> 1;
        bVar7 = CARRY4(uVar5,param_2);
        param_2 = uVar5 + param_2;
        param_3 = (iVar4 >> 0x1f) + param_3 + (uint)bVar7;
      }
      else if (param_4 == 1) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        uVar5 = (int)pwVar1 - (int)pwVar2 >> 1;
        bVar7 = CARRY4(uVar5,param_2);
        param_2 = uVar5 + param_2;
        param_3 = ((int)pwVar1 - (int)pwVar2 >> 0x1f) + param_3 + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        iVar6 = iVar4 >> 0x1f;
        if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar4 >> 1)))))
        {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)pwVar1 - (int)pwVar2 >> 1) + param_2);
          goto LAB_100190ae;
        }
      }
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
  }
  else {
    if (param_4 == 2) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
      uVar5 = iVar4 >> 1;
      bVar7 = CARRY4(uVar5,param_2);
      param_2 = uVar5 + param_2;
      param_3 = (iVar4 >> 0x1f) + param_3 + (uint)bVar7;
    }
    else if ((param_4 == 1) && ((param_5 & 2) == 0)) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      uVar5 = (int)pwVar1 - (int)pwVar2 >> 1;
      bVar7 = CARRY4(uVar5,param_2);
      param_2 = uVar5 + param_2;
      param_3 = ((int)pwVar1 - (int)pwVar2 >> 0x1f) + param_3 + (uint)bVar7;
    }
    else if (param_4 != 0) {
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    if (-1 < (int)param_3) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
      iVar6 = iVar4 >> 0x1f;
      if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar4 >> 1))))) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                   ((int)pwVar1 - (int)pwVar2 >> 1) + param_2);
        if (((param_5 & 2) != 0) &&
           (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
           pwVar1 != (wchar_t *)0x0)) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar3,
                     pwVar2,pwVar1);
        }
        goto LAB_100190ae;
      }
    }
    param_2 = *(uint *)_BADOFF_exref;
    param_3 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_100190ae:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_100191a0 at 100191a0

uint * __thiscall FUN_100191a0(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  uint in_stack_00000020;
  uint local_c;
  uint local_8;
  
  local_c = param_4 + param_2;
  local_8 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((pwVar1 != (wchar_t *)0x0) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     *(wchar_t **)((int)this + 0x3c) < pwVar1)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *(wchar_t **)((int)this + 0x3c) = pwVar1;
  }
  if ((local_c != *(uint *)_BADOFF_exref) || (local_8 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
       pwVar1 == (wchar_t *)0x0)) {
      if (((in_stack_00000020 & 2) == 0) ||
         (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
         pwVar1 == (wchar_t *)0x0)) {
        local_c = *(uint *)_BADOFF_exref;
        local_8 = *(uint *)(_BADOFF_exref + 4);
      }
      else {
        if (-1 < (int)local_8) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
          iVar5 = iVar4 >> 0x1f;
          if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (local_c <= (uint)(iVar4 >> 1))))
             ) {
            pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                       ((int)pwVar1 - (int)pwVar2 >> 1) + local_c);
            goto LAB_1001938e;
          }
        }
        local_c = *(uint *)_BADOFF_exref;
        local_8 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (-1 < (int)local_8) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        iVar5 = iVar4 >> 0x1f;
        if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (local_c <= (uint)(iVar4 >> 1)))))
        {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)pwVar1 - (int)pwVar2 >> 1) + local_c);
          if (((in_stack_00000020 & 2) != 0) &&
             (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                                 ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this
                                 ), pwVar1 != (wchar_t *)0x0)) {
            pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar3,
                       pwVar2,pwVar1);
          }
          goto LAB_1001938e;
        }
      }
      local_c = *(uint *)_BADOFF_exref;
      local_8 = *(uint *)(_BADOFF_exref + 4);
    }
  }
LAB_1001938e:
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10019450 at 10019450

void __fastcall FUN_10019450(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_10019490 at 10019490

void __fastcall FUN_10019490(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_100194d0 at 100194d0

basic_ios<char,struct_std::char_traits<char>_> * __thiscall FUN_100194d0(void *this,uint param_1)

{
  thunk_FUN_10017530((int)this);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x60));
  }
  return (basic_ios<char,struct_std::char_traits<char>_> *)((int)this + -0x60);
}



// Function: FUN_10019530 at 10019530

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10019530(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022589;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  local_8 = 0;
  thunk_FUN_1001a0b0((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_100195c0 at 100195c0

basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100195c0(void *this,uint param_1)

{
  thunk_FUN_100185c0((int)this);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x60));
  }
  return (basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + -0x60);
}



// Function: FUN_10019620 at 10019620

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10019620(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100225a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  thunk_FUN_1001a520((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100196b0 at 100196b0

undefined4 * __thiscall
FUN_100196b0(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  void *local_9c;
  void *local_98;
  void *local_94;
  void *local_90;
  undefined4 *local_8c;
  
  if (param_3 != (undefined4 *)0x0) {
    local_8c = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_8c = *this;
    }
    if ((local_8c <= param_3) &&
       (puVar2 = thunk_FUN_1001c370((undefined4 *)this),
       param_3 < (undefined4 *)((int)puVar2 + *(int *)((int)this + 0x10) * 2))) {
      bVar1 = true;
      goto LAB_10019720;
    }
  }
  bVar1 = false;
LAB_10019720:
  if (bVar1) {
    local_90 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_90 = *this;
    }
    this = thunk_FUN_1001ba10(this,param_1,param_2,(undefined4 *)this,
                              (int)param_3 - (int)local_90 >> 1,param_4);
  }
  else {
    if (*(uint *)((int)this + 0x10) < param_1) {
      std::_Xout_of_range("invalid string position");
    }
    if (*(int *)((int)this + 0x10) - param_1 < param_2) {
      param_2 = *(int *)((int)this + 0x10) - param_1;
    }
    if (-param_4 - 1 <= *(int *)((int)this + 0x10) - param_2) {
      std::_Xlength_error("string too long");
    }
    iVar4 = (*(int *)((int)this + 0x10) - param_2) - param_1;
    if (param_4 < param_2) {
      local_94 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_94 = *this;
      }
      local_98 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_98 = *this;
      }
      memmove((void *)((int)local_98 + param_4 * 2 + param_1 * 2),
              (void *)((int)local_94 + param_2 * 2 + param_1 * 2),iVar4 * 2);
    }
    if ((param_4 != 0) || (param_2 != 0)) {
      uVar3 = (*(int *)((int)this + 0x10) + param_4) - param_2;
      bVar1 = thunk_FUN_1001c6d0(this,uVar3,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          local_9c = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_9c = *this;
          }
          puVar2 = thunk_FUN_1001c370((undefined4 *)this);
          memmove((void *)((int)puVar2 + param_4 * 2 + param_1 * 2),
                  (void *)((int)local_9c + param_2 * 2 + param_1 * 2),iVar4 * 2);
        }
        puVar2 = thunk_FUN_1001c370((undefined4 *)this);
        memcpy((void *)((int)puVar2 + param_1 * 2),param_3,param_4 << 1);
        thunk_FUN_1001c240(this,uVar3);
      }
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10019a20 at 10019a20

uint __thiscall FUN_10019a20(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  uint local_2c;
  uint local_28;
  void *local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  ushort *local_10;
  ushort *local_c;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 < param_4) {
    local_1c = param_2;
  }
  else {
    local_1c = param_4;
  }
  local_24 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    local_24 = *this;
  }
  local_14 = local_1c;
  local_10 = param_3;
  local_c = (ushort *)((int)local_24 + param_1 * 2);
  do {
    if (local_14 == 0) {
      local_18 = 0;
LAB_10019af8:
      if (local_18 == 0) {
        if (param_2 < param_4) {
          local_2c = 0xffffffff;
        }
        else {
          local_2c = (uint)(param_2 != param_4);
        }
        local_28 = local_2c;
      }
      else {
        local_28 = local_18;
      }
      return local_28;
    }
    if (*local_c != *local_10) {
      local_18 = (uint)(*local_10 <= *local_c) * 2 - 1;
      goto LAB_10019af8;
    }
    local_c = local_c + 1;
    local_10 = local_10 + 1;
    local_14 = local_14 - 1;
  } while( true );
}



// Function: FUN_10019b80 at 10019b80

/* WARNING: Removing unreachable block (ram,0x10019be1) */
/* WARNING: Removing unreachable block (ram,0x10019bf3) */
/* WARNING: Removing unreachable block (ram,0x10019c26) */
/* WARNING: Removing unreachable block (ram,0x10019c3b) */
/* WARNING: Removing unreachable block (ram,0x10019c46) */
/* WARNING: Removing unreachable block (ram,0x10019c59) */
/* WARNING: Removing unreachable block (ram,0x10019c51) */
/* WARNING: Removing unreachable block (ram,0x10019c5f) */
/* WARNING: Removing unreachable block (ram,0x10019c81) */
/* WARNING: Removing unreachable block (ram,0x10019c94) */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10019b80(void *this,uint param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100225c9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  local_8 = 0;
  *(undefined ***)this =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  uVar1 = thunk_FUN_1001a8e0(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10019d10 at 10019d10

void * __thiscall FUN_10019d10(void *this,void *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *local_d4;
  undefined1 local_c1;
  undefined1 *local_c0;
  undefined1 local_b5;
  undefined1 *local_b4;
  undefined1 local_a9;
  undefined1 *local_a8;
  uint local_a0;
  char *local_9c;
  undefined1 local_91;
  undefined1 *local_90;
  undefined1 local_85;
  undefined1 *local_84;
  uint local_7c;
  char *local_78;
  undefined1 local_71;
  undefined1 *local_70;
  uint local_68;
  undefined4 local_64 [7];
  undefined4 local_48 [7];
  undefined4 local_2c [7];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022659;
  local_10 = ExceptionList;
  local_68 = 0;
  ExceptionList = &local_10;
  if (((*(uint *)((int)this + 0x40) & 2) == 0) &&
     (ExceptionList = &local_10,
     pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                        ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 != (char *)0x0)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if (*(char **)((int)this + 0x3c) < pcVar1) {
      local_d4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    }
    else {
      local_d4 = *(char **)((int)this + 0x3c);
    }
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_7c = (int)local_d4 - (int)pcVar1;
    local_78 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_70 = &local_71;
    local_8 = 1;
    thunk_FUN_1001b590(local_2c,'\0',0);
    thunk_FUN_1001c400(local_2c,(undefined4 *)local_78,local_7c);
    local_84 = &local_85;
    local_8 = 3;
    thunk_FUN_1001b590(param_1,'\0',0);
    thunk_FUN_1001b490(param_1,local_2c);
    local_68 = local_68 | 1;
    local_8 = 4;
    thunk_FUN_1001b590(local_2c,'\x01',0);
    ExceptionList = local_10;
    return param_1;
  }
  if (((*(uint *)((int)this + 0x40) & 4) == 0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 != (char *)0x0)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_a0 = (int)pcVar2 - (int)pcVar1;
    local_9c = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_90 = &local_91;
    local_8 = 5;
    thunk_FUN_1001b590(local_48,'\0',0);
    thunk_FUN_1001c400(local_48,(undefined4 *)local_9c,local_a0);
    local_a8 = &local_a9;
    local_8 = 7;
    thunk_FUN_1001b590(param_1,'\0',0);
    thunk_FUN_1001b490(param_1,local_48);
    local_68 = local_68 | 1;
    local_8 = 8;
    thunk_FUN_1001b590(local_48,'\x01',0);
    ExceptionList = local_10;
    return param_1;
  }
  local_b4 = &local_b5;
  local_8 = 9;
  thunk_FUN_1001b590(local_64,'\0',0);
  local_c0 = &local_c1;
  local_8 = 0xb;
  thunk_FUN_1001b590(param_1,'\0',0);
  thunk_FUN_1001b490(param_1,local_64);
  local_68 = local_68 | 1;
  local_8 = 0xc;
  thunk_FUN_1001b590(local_64,'\x01',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001a0b0 at 1001a0b0

void __fastcall FUN_1001a0b0(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  
  if ((*(uint *)(param_1 + 0x40) & 1) != 0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
    if (pcVar1 == (char *)0x0) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(param_1);
    }
    std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    operator_delete(pcVar1);
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            (param_1,(char *)0x0,(char *)0x0,(char *)0x0);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setp(param_1,(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  return;
}



// Function: FUN_1001a180 at 1001a180

void * __thiscall FUN_1001a180(void *this,void *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *local_d4;
  undefined1 local_c1;
  undefined1 *local_c0;
  undefined1 local_b5;
  undefined1 *local_b4;
  undefined1 local_a9;
  undefined1 *local_a8;
  uint local_a0;
  wchar_t *local_9c;
  undefined1 local_91;
  undefined1 *local_90;
  undefined1 local_85;
  undefined1 *local_84;
  uint local_7c;
  wchar_t *local_78;
  undefined1 local_71;
  undefined1 *local_70;
  uint local_68;
  undefined4 local_64 [7];
  undefined4 local_48 [7];
  undefined4 local_2c [7];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022709;
  local_10 = ExceptionList;
  local_68 = 0;
  ExceptionList = &local_10;
  if (((*(uint *)((int)this + 0x40) & 2) == 0) &&
     (ExceptionList = &local_10,
     pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                        ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     pwVar1 != (wchar_t *)0x0)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    if (*(wchar_t **)((int)this + 0x3c) < pwVar1) {
      local_d4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    }
    else {
      local_d4 = *(wchar_t **)((int)this + 0x3c);
    }
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    local_7c = (int)local_d4 - (int)pwVar1 >> 1;
    local_78 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    local_70 = &local_71;
    local_8 = 1;
    thunk_FUN_1001c2a0(local_2c,'\0',0);
    thunk_FUN_1001c560(local_2c,(undefined4 *)local_78,local_7c);
    local_84 = &local_85;
    local_8 = 3;
    thunk_FUN_1001c2a0(param_1,'\0',0);
    thunk_FUN_1001b660(param_1,local_2c);
    local_68 = local_68 | 1;
    local_8 = 4;
    thunk_FUN_1001c2a0(local_2c,'\x01',0);
    ExceptionList = local_10;
    return param_1;
  }
  if (((*(uint *)((int)this + 0x40) & 4) == 0) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     pwVar1 != (wchar_t *)0x0)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    local_a0 = (int)pwVar2 - (int)pwVar1 >> 1;
    local_9c = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    local_90 = &local_91;
    local_8 = 5;
    thunk_FUN_1001c2a0(local_48,'\0',0);
    thunk_FUN_1001c560(local_48,(undefined4 *)local_9c,local_a0);
    local_a8 = &local_a9;
    local_8 = 7;
    thunk_FUN_1001c2a0(param_1,'\0',0);
    thunk_FUN_1001b660(param_1,local_48);
    local_68 = local_68 | 1;
    local_8 = 8;
    thunk_FUN_1001c2a0(local_48,'\x01',0);
    ExceptionList = local_10;
    return param_1;
  }
  local_b4 = &local_b5;
  local_8 = 9;
  thunk_FUN_1001c2a0(local_64,'\0',0);
  local_c0 = &local_c1;
  local_8 = 0xb;
  thunk_FUN_1001c2a0(param_1,'\0',0);
  thunk_FUN_1001b660(param_1,local_64);
  local_68 = local_68 | 1;
  local_8 = 0xc;
  thunk_FUN_1001c2a0(local_64,'\x01',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001a520 at 1001a520

void __fastcall FUN_1001a520(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  wchar_t *pwVar1;
  
  if ((*(uint *)(param_1 + 0x40) & 1) != 0) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
    if (pwVar1 == (wchar_t *)0x0) {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr(param_1);
    }
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
    operator_delete(pwVar1);
  }
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
            (param_1,(wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
            (param_1,(wchar_t *)0x0,(wchar_t *)0x0);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  return;
}



// Function: Init at 1001a5f0

/* Library Function - Single Match
    private: void __thiscall ATL::CW2AEX<128>::Init(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

void __thiscall ATL::CW2AEX<128>::Init(CW2AEX<128> *this,wchar_t *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  size_t cbMultiByte;
  bool bVar4;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
    iVar1 = iVar1 + 1;
    thunk_FUN_1001ab40((int *)this,iVar1 * 4,(int)(this + 4),0x80);
    iVar2 = WideCharToMultiByte(param_2,0,param_1,iVar1,*(LPSTR *)this,iVar1 * 4,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    bVar4 = iVar2 == 0;
    if (bVar4) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(param_2,0,param_1,iVar1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        thunk_FUN_1001ab40((int *)this,cbMultiByte,(int)(this + 4),0x80);
        iVar1 = WideCharToMultiByte(param_2,0,param_1,iVar1,*(LPSTR *)this,cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        bVar4 = iVar1 == 0;
      }
    }
    if (bVar4) {
      AtlThrowLastWin32();
    }
  }
  return;
}



// Function: AtlThrowLastWin32 at 1001a740

/* Library Function - Single Match
    void __stdcall ATL::AtlThrowLastWin32(void)
   
   Library: Visual Studio 2005 Debug */

void ATL::AtlThrowLastWin32(void)

{
  undefined4 local_c;
  
  local_c = GetLastError();
  if (0 < (int)local_c) {
    local_c = local_c & 0xffff | 0x80070000;
  }
  thunk_FUN_10004720(local_c);
  return;
}



// Function: Init at 1001a7a0

/* Library Function - Single Match
    private: void __thiscall ATL::CA2WEX<128>::Init(char const *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

void __thiscall ATL::CA2WEX<128>::Init(CA2WEX<128> *this,char *param_1,uint param_2)

{
  int iVar1;
  size_t cbMultiByte;
  DWORD DVar2;
  size_t cchWideChar;
  bool bVar3;
  
  if (param_1 == (char *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
    cbMultiByte = iVar1 + 1;
    thunk_FUN_1001d270((int *)this,cbMultiByte,(int)(this + 4),0x80);
    iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*(LPWSTR *)this,cbMultiByte);
    bVar3 = iVar1 == 0;
    if (bVar3) {
      DVar2 = GetLastError();
      if (DVar2 == 0x7a) {
        cchWideChar = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,(LPWSTR)0x0,0);
        thunk_FUN_1001d270((int *)this,cchWideChar,(int)(this + 4),0x80);
        iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*(LPWSTR *)this,cchWideChar);
        bVar3 = iVar1 == 0;
      }
    }
    if (bVar3) {
      AtlThrowLastWin32();
    }
  }
  return;
}



// Function: FUN_1001a8e0 at 1001a8e0

uint FUN_1001a8e0(uint param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 & 1) == 0) {
    local_8 = 4;
  }
  if ((param_1 & 2) == 0) {
    local_8 = local_8 | 2;
  }
  if ((param_1 & 8) != 0) {
    local_8 = local_8 | 8;
  }
  if ((param_1 & 4) != 0) {
    local_8 = local_8 | 0x10;
  }
  return local_8;
}



// Function: FUN_1001a960 at 1001a960

void __thiscall FUN_1001a960(void *this,void *param_1,uint param_2,undefined4 param_3)

{
  wchar_t *_Dst;
  wchar_t *pwVar1;
  wchar_t *local_24;
  
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = param_3;
  if ((param_2 != 0) && ((*(uint *)((int)this + 0x40) & 6) != 6)) {
    _Dst = (wchar_t *)thunk_FUN_1001d3d0(param_2);
    memcpy(_Dst,param_1,param_2 << 1);
    *(wchar_t **)((int)this + 0x3c) = _Dst + param_2;
    if ((*(uint *)((int)this + 0x40) & 4) == 0) {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,_Dst,_Dst,
                 _Dst + param_2);
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      local_24 = _Dst;
      if ((*(uint *)((int)this + 0x40) & 0x10) != 0) {
        local_24 = _Dst + param_2;
      }
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,_Dst,local_24,
                 _Dst + param_2);
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      if (pwVar1 == (wchar_t *)0x0) {
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,_Dst,
                   (wchar_t *)0x0,_Dst);
      }
    }
    *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  }
  return;
}



// Function: FUN_1001aac0 at 1001aac0

uint FUN_1001aac0(uint param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 & 1) == 0) {
    local_8 = 4;
  }
  if ((param_1 & 2) == 0) {
    local_8 = local_8 | 2;
  }
  if ((param_1 & 8) != 0) {
    local_8 = local_8 | 8;
  }
  if ((param_1 & 4) != 0) {
    local_8 = local_8 | 0x10;
  }
  return local_8;
}



// Function: FUN_1001ab40 at 1001ab40

void __cdecl FUN_1001ab40(int *param_1,size_t param_2,int param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    thunk_FUN_10004720(0x80070057);
  }
  if ((int)param_2 < 0) {
    thunk_FUN_10004720(0x80070057);
  }
  if (param_3 == 0) {
    thunk_FUN_10004720(0x80070057);
  }
  if (*param_1 == param_3) {
    if (param_4 < (int)param_2) {
      pvVar1 = calloc(param_2,1);
      *param_1 = (int)pvVar1;
    }
    else {
      *param_1 = param_3;
    }
  }
  else if (param_4 < (int)param_2) {
    pvVar1 = _recalloc((void *)*param_1,param_2,1);
    if (pvVar1 == (void *)0x0) {
      thunk_FUN_10004720(0x8007000e);
    }
    *param_1 = (int)pvVar1;
  }
  else {
    free((void *)*param_1);
    *param_1 = param_3;
  }
  if (*param_1 == 0) {
    thunk_FUN_10004720(0x8007000e);
  }
  return;
}



// Function: FUN_1001aca0 at 1001aca0

undefined2 * __thiscall FUN_1001aca0(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
    thunk_FUN_10004720(iVar1);
  }
  *(undefined2 *)this = 8;
  uVar2 = Ordinal_2(param_1);
  *(undefined4 *)((int)this + 8) = uVar2;
  if ((*(int *)((int)this + 8) == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    thunk_FUN_10004720(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_1001ad40 at 1001ad40

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x1001ae11) */

undefined2 * __thiscall FUN_1001ad40(void *this,LPCSTR param_1)

{
  int iVar1;
  uint uVar2;
  size_t _Size;
  undefined4 *puVar3;
  undefined4 uVar4;
  longlong lVar5;
  void *pvStack_84;
  LPWSTR local_78;
  LPWSTR local_70;
  LPWSTR local_5c;
  int local_3c;
  uint local_34;
  uint local_30;
  undefined4 *local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022748;
  local_10 = ExceptionList;
  local_24 = (undefined4 *)0x0;
  local_8 = 0;
  ExceptionList = &local_10;
  pvStack_84 = this;
  iVar1 = Ordinal_9();
  if (iVar1 < 0) {
    thunk_FUN_10004720(iVar1);
  }
  *(undefined2 *)this = 8;
  if (param_1 == (LPCSTR)0x0) {
    local_70 = (LPWSTR)0x0;
  }
  else {
    iVar1 = lstrlenA(param_1);
    local_20 = iVar1 + 1;
    lVar5 = __allmul(local_20,(int)local_20 >> 0x1f,2,0);
    local_30 = (uint)((ulonglong)lVar5 >> 0x20);
    if ((((int)local_30 < 1) && ((local_34 = (uint)lVar5, lVar5 < 0 || (local_34 < 0x80000000)))) &&
       ((local_30 < 0x80000000 || ((-2 < (int)local_30 && (0x7fffffff < local_34)))))) {
      local_20 = local_34;
      local_3c = 0;
    }
    else {
      local_3c = -0x7ff8fdea;
    }
    if (local_3c < 0) {
      local_78 = (LPWSTR)0x0;
    }
    else {
      if (((int)local_20 < 0x401) && (uVar2 = thunk_FUN_1001b070(local_20), (uVar2 & 0xff) != 0)) {
        local_5c = (LPWSTR)&pvStack_84;
      }
      else {
        _Size = thunk_FUN_1001d1e0(local_20,8);
        puVar3 = (undefined4 *)malloc(_Size);
        if (puVar3 == (undefined4 *)0x0) {
          local_5c = (LPWSTR)0x0;
        }
        else {
          *puVar3 = 0;
          local_5c = (LPWSTR)(puVar3 + 2);
          local_24 = puVar3;
        }
      }
      if ((local_5c == (LPWSTR)0x0) || (param_1 == (LPCSTR)0x0)) {
        local_78 = (LPWSTR)0x0;
      }
      else {
        *local_5c = L'\0';
        iVar1 = MultiByteToWideChar(3,0,param_1,-1,local_5c,local_20 >> 1);
        if (iVar1 == 0) {
          local_78 = (LPWSTR)0x0;
        }
        else {
          local_78 = local_5c;
        }
      }
    }
    local_70 = local_78;
  }
  uVar4 = Ordinal_2(local_70);
  *(undefined4 *)((int)this + 8) = uVar4;
  if ((*(int *)((int)this + 8) == 0) && (param_1 != (LPCSTR)0x0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    thunk_FUN_10004720(0x8007000e);
  }
  local_8 = 0xffffffff;
  while (local_24 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*local_24;
    free(local_24);
    local_24 = puVar3;
  }
  ExceptionList = local_10;
  return (undefined2 *)this;
}



// Function: FUN_1001b070 at 1001b070

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x1001b0be) */

undefined4 __cdecl FUN_1001b070(int param_1)

{
  uint uVar1;
  uint local_28;
  int local_24;
  
  local_28 = 0;
  uVar1 = -param_1 - 1;
  if (uVar1 < 0x2000) {
    uVar1 = 0x80070216;
    local_24 = -0x7ff8fdea;
  }
  else {
    local_28 = param_1 + 0x2000;
    local_24 = 0;
  }
  if (-1 >= local_24) {
    local_28 = uVar1;
  }
  return CONCAT31((int3)(local_28 >> 8),-1 < local_24);
}



// Function: FUN_1001b1b0 at 1001b1b0

LSTATUS __thiscall FUN_1001b1b0(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  LSTATUS LVar1;
  uint local_c;
  DWORD local_8;
  
  local_c = *param_3 << 1;
  *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
  LVar1 = RegQueryValueExW(*this,param_1,(LPDWORD)0x0,&local_8,param_2,&local_c);
  if (LVar1 == 0) {
    if ((local_8 == 1) || (local_8 == 2)) {
      if (param_2 != (LPBYTE)0x0) {
        if (local_c == 0) {
          param_2[0] = '\0';
          param_2[1] = '\0';
        }
        else if ((local_c % 2 != 0) || (*(short *)(param_2 + ((local_c & 0xfffffffe) - 2)) != 0)) {
          return 0xd;
        }
      }
      *param_3 = local_c >> 1;
      LVar1 = 0;
    }
    else {
      LVar1 = 0xd;
    }
  }
  return LVar1;
}



// Function: FUN_1001b290 at 1001b290

void * __thiscall FUN_1001b290(void *this,char *param_1)

{
  size_t sVar1;
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022768;
  local_10 = ExceptionList;
  local_18 = &local_19;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001b590(this,'\0',0);
  sVar1 = strlen(param_1);
  thunk_FUN_1001c400(this,(undefined4 *)param_1,sVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001b330 at 1001b330

void __fastcall FUN_1001b330(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022788;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001b590(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b390 at 1001b390

void * __thiscall FUN_1001b390(void *this,wchar_t *param_1)

{
  size_t sVar1;
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227a8;
  local_10 = ExceptionList;
  local_18 = &local_19;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(this,'\0',0);
  sVar1 = wcslen(param_1);
  thunk_FUN_1001c560(this,(undefined4 *)param_1,sVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001b430 at 1001b430

void __fastcall FUN_1001b430(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227c8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b490 at 1001b490

/* WARNING: Removing unreachable block (ram,0x1001b4b9) */
/* WARNING: Removing unreachable block (ram,0x1001b4c2) */

undefined4 * __thiscall FUN_1001b490(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    thunk_FUN_1001b590(this,'\x01',0);
    if ((uint)param_1[5] < 0x10) {
      memmove(this,param_1,param_1[4] + 1);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    thunk_FUN_1001b590(param_1,'\0',0);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001b590 at 1001b590

void __thiscall FUN_1001b590(void *this,char param_1,size_t param_2)

{
  void *_Src;
  void *local_18;
  
  if ((param_1 != '\0') && (0xf < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    _Src = *this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2);
    }
    operator_delete(_Src);
  }
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(size_t *)((int)this + 0x10) = param_2;
  local_18 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    local_18 = *this;
  }
  *(undefined1 *)((int)local_18 + param_2) = 0;
  return;
}



// Function: FUN_1001b650 at 1001b650

void FUN_1001b650(void)

{
  return;
}



// Function: FUN_1001b660 at 1001b660

/* WARNING: Removing unreachable block (ram,0x1001b689) */
/* WARNING: Removing unreachable block (ram,0x1001b692) */

undefined4 * __thiscall FUN_1001b660(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    thunk_FUN_1001c2a0(this,'\x01',0);
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,(param_1[4] + 1) * 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    thunk_FUN_1001c2a0(param_1,'\0',0);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001b760 at 1001b760

undefined4 * __thiscall FUN_1001b760(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  void *local_50;
  undefined4 *local_4c;
  void *local_40;
  uint local_8;
  
  if ((uint)param_1[4] < param_2) {
    std::_Xout_of_range("invalid string position");
  }
  local_8 = param_1[4] - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if ((undefined4 *)this == param_1) {
    thunk_FUN_1001b8d0(this,param_2 + local_8,0xffffffff);
    thunk_FUN_1001b8d0(this,0,param_2);
  }
  else {
    bVar1 = thunk_FUN_1001c6d0(this,local_8,'\0');
    if (bVar1) {
      if ((uint)param_1[5] < 8) {
        local_4c = param_1;
      }
      else {
        local_4c = (undefined4 *)*param_1;
      }
      local_40 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_40 = *this;
      }
      memcpy(local_40,(void *)((int)local_4c + param_2 * 2),local_8 << 1);
      *(uint *)((int)this + 0x10) = local_8;
      local_50 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_50 = *this;
      }
      *(undefined2 *)((int)local_50 + local_8 * 2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001b8d0 at 1001b8d0

undefined4 * __thiscall FUN_1001b8d0(void *this,uint param_1,uint param_2)

{
  int iVar1;
  void *local_20;
  void *local_1c;
  void *local_18;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 != 0) {
    local_18 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_18 = *this;
    }
    local_1c = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_1c = *this;
    }
    memmove((void *)((int)local_1c + param_1 * 2),
            (void *)((int)local_18 + param_2 * 2 + param_1 * 2),
            ((*(int *)((int)this + 0x10) - param_1) - param_2) * 2);
    iVar1 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar1;
    local_20 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_20 = *this;
    }
    *(undefined2 *)((int)local_20 + iVar1 * 2) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_1001ba10 at 1001ba10

undefined4 * __thiscall
FUN_1001ba10(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  void *local_74;
  void *local_70;
  void *local_6c;
  void *local_68;
  void *local_64;
  void *local_60;
  void *local_5c;
  void *local_58;
  void *local_54;
  void *local_50;
  void *local_4c;
  void *local_48;
  void *local_44;
  void *local_40;
  void *local_3c;
  void *local_38;
  undefined4 *local_34;
  void *local_30;
  void *local_2c;
  
  if ((*(uint *)((int)this + 0x10) < param_1) || ((uint)param_3[4] < param_4)) {
    std::_Xout_of_range("invalid string position");
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_3[4] - param_4 < param_5) {
    param_5 = param_3[4] - param_4;
  }
  if (-param_5 - 1 <= *(int *)((int)this + 0x10) - param_2) {
    std::_Xlength_error("string too long");
  }
  iVar1 = (*(int *)((int)this + 0x10) - param_2) - param_1;
  uVar4 = (*(int *)((int)this + 0x10) + param_5) - param_2;
  if (*(uint *)((int)this + 0x10) < uVar4) {
    thunk_FUN_1001c6d0(this,uVar4,'\0');
  }
  if ((undefined4 *)this == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        if (param_4 < param_1 + param_2) {
          local_6c = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_6c = *this;
          }
          local_70 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_70 = *this;
          }
          memmove((void *)((int)local_70 + param_1 * 2),(void *)((int)local_6c + param_4 * 2),
                  param_2 << 1);
          local_74 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_74 = *this;
          }
          puVar2 = thunk_FUN_1001c370((undefined4 *)this);
          memmove((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),
                  (void *)((int)local_74 + param_2 * 2 + param_1 * 2),iVar1 * 2);
          puVar2 = thunk_FUN_1001c370((undefined4 *)this);
          puVar3 = thunk_FUN_1001c370((undefined4 *)this);
          memmove((void *)((int)puVar3 + param_2 * 2 + param_1 * 2),
                  (void *)((int)puVar2 + param_5 * 2 + param_4 * 2),(param_5 - param_2) * 2);
        }
        else {
          local_5c = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_5c = *this;
          }
          local_60 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_60 = *this;
          }
          memmove((void *)((int)local_60 + param_5 * 2 + param_1 * 2),
                  (void *)((int)local_5c + param_2 * 2 + param_1 * 2),iVar1 * 2);
          local_64 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_64 = *this;
          }
          local_68 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_68 = *this;
          }
          memmove((void *)((int)local_68 + param_1 * 2),
                  (void *)((int)local_64 + ((param_4 + param_5) - param_2) * 2),param_5 << 1);
        }
      }
      else {
        local_4c = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_4c = *this;
        }
        local_50 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_50 = *this;
        }
        memmove((void *)((int)local_50 + param_5 * 2 + param_1 * 2),
                (void *)((int)local_4c + param_2 * 2 + param_1 * 2),iVar1 * 2);
        local_54 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_54 = *this;
        }
        local_58 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_58 = *this;
        }
        memmove((void *)((int)local_58 + param_1 * 2),(void *)((int)local_54 + param_4 * 2),
                param_5 << 1);
      }
    }
    else {
      local_3c = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_3c = *this;
      }
      local_40 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_40 = *this;
      }
      memmove((void *)((int)local_40 + param_1 * 2),(void *)((int)local_3c + param_4 * 2),
              param_5 << 1);
      local_44 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_44 = *this;
      }
      local_48 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_48 = *this;
      }
      memmove((void *)((int)local_48 + param_5 * 2 + param_1 * 2),
              (void *)((int)local_44 + param_2 * 2 + param_1 * 2),iVar1 * 2);
    }
  }
  else {
    local_2c = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_2c = *this;
    }
    local_30 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_30 = *this;
    }
    memmove((void *)((int)local_30 + param_5 * 2 + param_1 * 2),
            (void *)((int)local_2c + param_2 * 2 + param_1 * 2),iVar1 * 2);
    if ((uint)param_3[5] < 8) {
      local_34 = param_3;
    }
    else {
      local_34 = (undefined4 *)*param_3;
    }
    local_38 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_38 = *this;
    }
    memcpy((void *)((int)local_38 + param_1 * 2),(void *)((int)local_34 + param_4 * 2),param_5 << 1)
    ;
  }
  thunk_FUN_1001c240(this,uVar4);
  return (undefined4 *)this;
}



// Function: FUN_1001c040 at 1001c040

uint __thiscall FUN_1001c040(void *this,ushort *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  void *local_38;
  void *local_34;
  int local_2c;
  uint local_28;
  ushort *local_24;
  ushort *local_20;
  ushort *local_1c;
  int local_18;
  ushort *local_14;
  ushort *local_10;
  int local_8;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar1 = *(int *)((int)this + 0x10) - param_2, param_3 <= uVar1)) {
      local_8 = uVar1 - (param_3 - 1);
      local_34 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_34 = *this;
      }
      local_10 = (ushort *)((int)local_34 + param_2 * 2);
      do {
        local_14 = local_10;
        for (local_18 = local_8; local_18 != 0; local_18 = local_18 + -1) {
          if (*local_14 == *param_1) {
            local_1c = local_14;
            goto LAB_1001c121;
          }
          local_14 = local_14 + 1;
        }
        local_1c = (ushort *)0x0;
LAB_1001c121:
        if (local_1c == (ushort *)0x0) break;
        local_24 = param_1;
        local_20 = local_1c;
        for (local_28 = param_3; local_28 != 0; local_28 = local_28 - 1) {
          if (*local_20 != *local_24) {
            local_2c = (uint)(*local_24 <= *local_20) * 2 + -1;
            goto LAB_1001c19b;
          }
          local_20 = local_20 + 1;
          local_24 = local_24 + 1;
        }
        local_2c = 0;
LAB_1001c19b:
        if (local_2c == 0) {
          local_38 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_38 = *this;
          }
          return (int)local_1c - (int)local_38 >> 1;
        }
        local_8 = local_8 - (((int)local_1c - (int)local_10 >> 1) + 1);
        local_10 = local_1c + 1;
      } while( true );
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_1001c240 at 1001c240

void __thiscall FUN_1001c240(void *this,int param_1)

{
  void *local_10;
  
  *(int *)((int)this + 0x10) = param_1;
  local_10 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    local_10 = *this;
  }
  *(undefined2 *)((int)local_10 + param_1 * 2) = 0;
  return;
}



// Function: FUN_1001c2a0 at 1001c2a0

void __thiscall FUN_1001c2a0(void *this,char param_1,int param_2)

{
  void *_Src;
  void *local_18;
  
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    _Src = *this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2 << 1);
    }
    operator_delete(_Src);
  }
  *(undefined4 *)((int)this + 0x14) = 7;
  *(int *)((int)this + 0x10) = param_2;
  local_18 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    local_18 = *this;
  }
  *(undefined2 *)((int)local_18 + param_2 * 2) = 0;
  return;
}



// Function: FUN_1001c370 at 1001c370

undefined4 * __fastcall FUN_1001c370(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)*param_1;
  }
  return local_c;
}



// Function: FUN_1001c3b0 at 1001c3b0

undefined4 * __fastcall FUN_1001c3b0(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)*param_1;
  }
  return local_c;
}



// Function: FUN_1001c3f0 at 1001c3f0

void FUN_1001c3f0(void)

{
  return;
}



// Function: FUN_1001c400 at 1001c400

undefined4 * __thiscall FUN_1001c400(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  void *local_44;
  void *local_40;
  void *local_3c;
  undefined4 *local_38;
  void *local_2c;
  
  if (param_1 != (undefined4 *)0x0) {
    local_38 = (undefined4 *)this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_38 = *this;
    }
    if (local_38 <= param_1) {
      local_3c = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_3c = *this;
      }
      if (param_1 < (undefined4 *)((int)local_3c + *(int *)((int)this + 0x10))) {
        bVar1 = true;
        goto LAB_1001c463;
      }
    }
  }
  bVar1 = false;
LAB_1001c463:
  if (bVar1) {
    local_40 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_40 = *this;
    }
    this = thunk_FUN_1001c810(this,(undefined4 *)this,(int)param_1 - (int)local_40,param_2);
  }
  else {
    bVar1 = thunk_FUN_1001c960(this,param_2,'\0');
    if (bVar1) {
      local_2c = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_2c = *this;
      }
      memcpy(local_2c,param_1,param_2);
      *(uint *)((int)this + 0x10) = param_2;
      local_44 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_44 = *this;
      }
      *(undefined1 *)((int)local_44 + param_2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001c560 at 1001c560

undefined4 * __thiscall FUN_1001c560(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  void *local_44;
  void *local_40;
  void *local_3c;
  undefined4 *local_38;
  void *local_2c;
  
  if (param_1 != (undefined4 *)0x0) {
    local_38 = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_38 = *this;
    }
    if (local_38 <= param_1) {
      local_3c = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_3c = *this;
      }
      if (param_1 < (undefined4 *)((int)local_3c + *(int *)((int)this + 0x10) * 2)) {
        bVar1 = true;
        goto LAB_1001c5c6;
      }
    }
  }
  bVar1 = false;
LAB_1001c5c6:
  if (bVar1) {
    local_40 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_40 = *this;
    }
    this = thunk_FUN_1001b760(this,(undefined4 *)this,(int)param_1 - (int)local_40 >> 1,param_2);
  }
  else {
    bVar1 = thunk_FUN_1001c6d0(this,param_2,'\0');
    if (bVar1) {
      local_2c = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_2c = *this;
      }
      memcpy(local_2c,param_1,param_2 << 1);
      *(uint *)((int)this + 0x10) = param_2;
      local_44 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_44 = *this;
      }
      *(undefined2 *)((int)local_44 + param_2 * 2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001c6d0 at 1001c6d0

/* WARNING: Removing unreachable block (ram,0x1001c6ee) */
/* WARNING: Removing unreachable block (ram,0x1001c701) */

bool __thiscall FUN_1001c6d0(void *this,uint param_1,char param_2)

{
  undefined2 *local_2c;
  uint local_28;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    thunk_FUN_1001caa0(this,param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      local_2c = (undefined2 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_2c = *this;
      }
      *local_2c = 0;
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_28 = param_1;
    }
    else {
      local_28 = *(uint *)((int)this + 0x10);
    }
    thunk_FUN_1001c2a0(this,'\x01',local_28);
  }
  return param_1 != 0;
}



// Function: FUN_1001c810 at 1001c810

undefined4 * __thiscall FUN_1001c810(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  void *local_50;
  undefined4 *local_4c;
  void *local_40;
  uint local_8;
  
  if ((uint)param_1[4] < param_2) {
    std::_Xout_of_range("invalid string position");
  }
  local_8 = param_1[4] - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if ((undefined4 *)this == param_1) {
    thunk_FUN_1001cdb0(this,param_2 + local_8,0xffffffff);
    thunk_FUN_1001cdb0(this,0,param_2);
  }
  else {
    bVar1 = thunk_FUN_1001c960(this,local_8,'\0');
    if (bVar1) {
      if ((uint)param_1[5] < 0x10) {
        local_4c = param_1;
      }
      else {
        local_4c = (undefined4 *)*param_1;
      }
      local_40 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_40 = *this;
      }
      memcpy(local_40,(void *)((int)local_4c + param_2),local_8);
      *(uint *)((int)this + 0x10) = local_8;
      local_50 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_50 = *this;
      }
      *(undefined1 *)((int)local_50 + local_8) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001c960 at 1001c960

/* WARNING: Removing unreachable block (ram,0x1001c97e) */
/* WARNING: Removing unreachable block (ram,0x1001c991) */

bool __thiscall FUN_1001c960(void *this,uint param_1,char param_2)

{
  undefined1 *local_2c;
  uint local_28;
  
  if (0xfffffffe < param_1) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    thunk_FUN_1001cee0(this,param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      local_2c = (undefined1 *)this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_2c = *this;
      }
      *local_2c = 0;
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_28 = param_1;
    }
    else {
      local_28 = *(size_t *)((int)this + 0x10);
    }
    thunk_FUN_1001b590(this,'\x01',local_28);
  }
  return param_1 != 0;
}



// Function: FUN_1001caa0 at 1001caa0

/* WARNING: Removing unreachable block (ram,0x1001cb4d) */
/* WARNING: Removing unreachable block (ram,0x1001cae3) */
/* WARNING: Removing unreachable block (ram,0x1001cbb2) */
/* WARNING: Removing unreachable block (ram,0x1001cb60) */
/* WARNING: Removing unreachable block (ram,0x1001caf6) */
/* WARNING: Removing unreachable block (ram,0x1001cbcb) */

void __thiscall FUN_1001caa0(void *this,uint param_1)

{
  uint local_1c;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227e0;
  pvStack_10 = ExceptionList;
  local_1c = param_1 | 7;
  if (local_1c < 0x7fffffff) {
    if (local_1c / 3 < *(uint *)((int)this + 0x14) >> 1) {
      if (0x7ffffffe - (*(uint *)((int)this + 0x14) >> 1) < *(uint *)((int)this + 0x14)) {
        local_1c = 0x7ffffffe;
      }
      else {
        local_1c = (*(uint *)((int)this + 0x14) >> 1) + *(int *)((int)this + 0x14);
      }
    }
  }
  else {
    local_1c = param_1;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  thunk_FUN_1001d3d0(local_1c + 1);
  FUN_1001cc62();
  return;
}



// Function: Catch@1001cc09 at 1001cc09

void Catch_1001cc09(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = thunk_FUN_1001d3d0(*(int *)(unaff_EBP + -0x18) + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  FUN_1001cc4e();
  return;
}



// Function: Catch@1001cc2c at 1001cc2c

void Catch_1001cc2c(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001c2a0(*(void **)(unaff_EBP + -0x70),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001cc4e at 1001cc4e

undefined4 FUN_1001cc4e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1001cc69;
}



// Function: FUN_1001cc62 at 1001cc62

void FUN_1001cc62(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if (*(uint *)(*(int *)(unaff_EBP + -0x70) + 0x14) < 8) {
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x70);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x60) = **(undefined4 **)(unaff_EBP + -0x70);
    }
    memcpy(*(void **)(unaff_EBP + -0x14),*(void **)(unaff_EBP + -0x60),
           *(int *)(unaff_EBP + 0xc) << 1);
  }
  thunk_FUN_1001c2a0(*(void **)(unaff_EBP + -0x70),'\x01',0);
  **(undefined4 **)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x70) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined2 *)(unaff_EBP + -0x6c) = 0;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x70) + 0x10) = *(undefined4 *)(unaff_EBP + 0xc);
  if (*(uint *)(*(int *)(unaff_EBP + -0x70) + 0x14) < 8) {
    *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(unaff_EBP + -0x70);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x8c) = **(undefined4 **)(unaff_EBP + -0x70);
  }
  *(undefined2 *)(*(int *)(unaff_EBP + -0x8c) + *(int *)(unaff_EBP + 0xc) * 2) =
       *(undefined2 *)(unaff_EBP + -0x6c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1001cdb0 at 1001cdb0

undefined4 * __thiscall FUN_1001cdb0(void *this,uint param_1,uint param_2)

{
  int iVar1;
  void *local_20;
  void *local_1c;
  void *local_18;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 != 0) {
    local_18 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_18 = *this;
    }
    local_1c = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_1c = *this;
    }
    memmove((void *)((int)local_1c + param_1),(void *)((int)local_18 + param_2 + param_1),
            (*(int *)((int)this + 0x10) - param_1) - param_2);
    iVar1 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar1;
    local_20 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_20 = *this;
    }
    *(undefined1 *)((int)local_20 + iVar1) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_1001cee0 at 1001cee0

/* WARNING: Removing unreachable block (ram,0x1001cf8d) */
/* WARNING: Removing unreachable block (ram,0x1001cf23) */
/* WARNING: Removing unreachable block (ram,0x1001cff2) */
/* WARNING: Removing unreachable block (ram,0x1001cfa0) */
/* WARNING: Removing unreachable block (ram,0x1001cf36) */
/* WARNING: Removing unreachable block (ram,0x1001d00b) */

void __thiscall FUN_1001cee0(void *this,uint param_1)

{
  uint local_1c;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227f0;
  pvStack_10 = ExceptionList;
  local_1c = param_1 | 0xf;
  if (local_1c == 0xffffffff) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)((int)this + 0x14) >> 1) {
    if (-(*(uint *)((int)this + 0x14) >> 1) - 2 < *(uint *)((int)this + 0x14)) {
      local_1c = 0xfffffffe;
    }
    else {
      local_1c = (*(uint *)((int)this + 0x14) >> 1) + *(int *)((int)this + 0x14);
    }
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  thunk_FUN_1001d490(local_1c + 1);
  FUN_1001d0a2();
  return;
}



// Function: Catch@1001d049 at 1001d049

void Catch_1001d049(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = thunk_FUN_1001d490(*(int *)(unaff_EBP + -0x18) + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  FUN_1001d08e();
  return;
}



// Function: Catch@1001d06c at 1001d06c

void Catch_1001d06c(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b590(*(void **)(unaff_EBP + -0x70),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001d08e at 1001d08e

undefined4 FUN_1001d08e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1001d0a9;
}



// Function: FUN_1001d0a2 at 1001d0a2

void FUN_1001d0a2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if (*(uint *)(*(int *)(unaff_EBP + -0x70) + 0x14) < 0x10) {
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x70);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x60) = **(undefined4 **)(unaff_EBP + -0x70);
    }
    memcpy(*(void **)(unaff_EBP + -0x14),*(void **)(unaff_EBP + -0x60),*(size_t *)(unaff_EBP + 0xc))
    ;
  }
  thunk_FUN_1001b590(*(void **)(unaff_EBP + -0x70),'\x01',0);
  **(undefined4 **)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x70) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -0x6a) = 0;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x70) + 0x10) = *(undefined4 *)(unaff_EBP + 0xc);
  if (*(uint *)(*(int *)(unaff_EBP + -0x70) + 0x14) < 0x10) {
    *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(unaff_EBP + -0x70);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x8c) = **(undefined4 **)(unaff_EBP + -0x70);
  }
  *(undefined1 *)(*(int *)(unaff_EBP + -0x8c) + *(int *)(unaff_EBP + 0xc)) =
       *(undefined1 *)(unaff_EBP + -0x6a);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1001d1e0 at 1001d1e0

/* WARNING: Removing unreachable block (ram,0x1001d1fa) */

int __cdecl FUN_1001d1e0(int param_1,uint param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (-param_1 - 1U < param_2) {
    local_c = -0x7ff8fdea;
  }
  else {
    local_8 = param_1 + param_2;
    local_c = 0;
  }
  if (local_c < 0) {
    thunk_FUN_10004720(local_c);
  }
  return local_8;
}



// Function: FUN_1001d270 at 1001d270

void __cdecl FUN_1001d270(int *param_1,size_t param_2,int param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    thunk_FUN_10004720(0x80070057);
  }
  if ((int)param_2 < 0) {
    thunk_FUN_10004720(0x80070057);
  }
  if (param_3 == 0) {
    thunk_FUN_10004720(0x80070057);
  }
  if (*param_1 == param_3) {
    if (param_4 < (int)param_2) {
      pvVar1 = calloc(param_2,2);
      *param_1 = (int)pvVar1;
    }
    else {
      *param_1 = param_3;
    }
  }
  else if (param_4 < (int)param_2) {
    pvVar1 = _recalloc((void *)*param_1,param_2,2);
    if (pvVar1 == (void *)0x0) {
      thunk_FUN_10004720(0x8007000e);
    }
    *param_1 = (int)pvVar1;
  }
  else {
    free((void *)*param_1);
    *param_1 = param_3;
  }
  if (*param_1 == 0) {
    thunk_FUN_10004720(0x8007000e);
  }
  return;
}



// Function: FUN_1001d3d0 at 1001d3d0

void * __cdecl FUN_1001d3d0(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022809;
  local_10 = ExceptionList;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0x7fffffff < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 << 1), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_1002e4e0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1001d490 at 1001d490

void * __cdecl FUN_1001d490(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022829;
  local_10 = ExceptionList;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     (ExceptionList = &local_10, local_14 = operator_new(param_1), local_14 == (void *)0x0)) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_1002e4e0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1001d550 at 1001d550

void FUN_1001d550(void)

{
  return;
}



// Function: FUN_1001d6f9 at 1001d6f9

void __thiscall FUN_1001d6f9(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return;
}



// Function: FUN_1001d70b at 1001d70b

undefined4 __cdecl FUN_1001d70b(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_1001d734 at 1001d734

uint __cdecl FUN_1001d734(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_1001d74c at 1001d74c

void __cdecl FUN_1001d74c(DWORD param_1,DWORD param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: memmove_s at 1001d763

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  errno_t eVar1;
  
  eVar1 = ::memmove_s(param_1,param_2,param_3,param_4);
  AtlCrtErrorCheck(eVar1);
  return;
}



// Function: RemoveAt at 1001d7be

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAt(int)
   
   Library: Visual Studio 2010 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAt(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
         *this,int param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 < 0) || (iVar3 = *(int *)(this + 4), iVar3 <= param_1)) {
    iVar3 = 0;
  }
  else {
    if (param_1 != iVar3 + -1) {
      uVar2 = (iVar3 - param_1) * 4;
      pvVar1 = (void *)(*(int *)this + param_1 * 4);
      Checked::memmove_s(pvVar1,uVar2,(void *)((int)pvVar1 + 4),uVar2 - 4);
    }
    *(int *)(this + 4) = *(int *)(this + 4) + -1;
    iVar3 = 1;
  }
  return iVar3;
}



// Function: FUN_1001d806 at 1001d806

int __thiscall FUN_1001d806(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 4))) {
                    /* WARNING: Load size is inaccurate */
    return *this + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



// Function: FUN_1001d832 at 1001d832

void __thiscall FUN_1001d832(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: RemoveResourceInstance at 1001d898

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::RemoveResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

bool __thiscall
ATL::CAtlBaseModule::RemoveResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x14);
  EnterCriticalSection(lpCriticalSection);
  iVar3 = 0;
  if (0 < *(int *)(this + 0x30)) {
    do {
      if ((iVar3 < 0) || (*(int *)(this + 0x30) <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return (bool)uVar2;
      }
      if (*(HINSTANCE__ **)(*(int *)(this + 0x2c) + iVar3 * 4) == param_1) {
        CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
        RemoveAt((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                  *)(this + 0x2c),iVar3);
        LeaveCriticalSection(lpCriticalSection);
        return true;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0x30));
  }
  LeaveCriticalSection(lpCriticalSection);
  return false;
}



// Function: GetHInstanceAt at 1001d901

/* Library Function - Single Match
    public: struct HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(int)
   
   Library: Visual Studio 2010 Release */

HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(CAtlBaseModule *this,int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  HINSTANCE__ *pHVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x14);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(this + 0x30);
  if ((iVar1 < param_1) || (param_1 < 0)) {
LAB_1001d94f:
    LeaveCriticalSection(lpCriticalSection);
    pHVar2 = (HINSTANCE__ *)0x0;
  }
  else {
    if (param_1 == iVar1) {
      pHVar2 = *(HINSTANCE__ **)(this + 8);
    }
    else {
      if (iVar1 <= param_1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        goto LAB_1001d94f;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: Add at 1001d95e

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::Add(struct HINSTANCE__ * const &)
   
   Library: Visual Studio 2010 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::Add
          (CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,HINSTANCE__ **param_1)

{
  undefined4 *puVar1;
  int iVar2;
  HINSTANCE__ **ppHVar3;
  void *pvVar4;
  int iVar5;
  int extraout_ECX;
  uint _Count;
  undefined8 uVar6;
  
  iVar5 = *(int *)(this + 4);
  iVar2 = *(int *)(this + 8);
  if (iVar5 == iVar2) {
    ppHVar3 = *(HINSTANCE__ ***)this;
    uVar6 = CONCAT44(ppHVar3,iVar2);
    if ((ppHVar3 <= param_1) && (uVar6 = CONCAT44(ppHVar3,iVar2), param_1 < ppHVar3 + iVar2)) {
      uVar6 = thunk_FUN_10004720(0x80004005);
      iVar5 = extraout_ECX;
    }
    if ((int)uVar6 == 0) {
      _Count = 1;
LAB_1001d9a4:
      pvVar4 = _recalloc((void *)((ulonglong)uVar6 >> 0x20),_Count,4);
      if (pvVar4 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar4;
        goto LAB_1001d9b9;
      }
    }
    else {
      _Count = iVar5 * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_1001d9a4;
    }
    iVar5 = 0;
  }
  else {
LAB_1001d9b9:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar5 = 1;
  }
  return iVar5;
}



// Function: AddResourceInstance at 1001da1a

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  iVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
          ::Add((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                 *)(this + 0x2c),&param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return iVar1 != 0;
}



// Function: FUN_1001db00 at 1001db00

void FUN_1001db00(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_1001dc80 at 1001dc80

void FUN_1001dc80(undefined *param_1)

{
  PTR_FUN_10033ca4 = param_1;
  return;
}



// Function: FUN_1001dca0 at 1001dca0

void FUN_1001dca0(undefined4 param_1)

{
  (*(code *)PTR_FUN_10033ca4)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 1001dcc0

/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2010 Release */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  int iVar2;
  void **unaff_ESI;
  undefined4 **local_8;
  
  local_8 = (undefined4 ***)0x0;
  if (param_2 != (IUnknown *)0x0) {
    HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1002b910,&param_2);
    if (-1 < HVar1) {
      HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
      (*param_2->lpVtbl->Release)(param_2);
      if (HVar1 == 0) {
        local_8 = &local_8;
        iVar2 = Ordinal_200(0);
        if (iVar2 != 0) {
          local_8 = (undefined4 ***)0x0;
        }
      }
    }
  }
  (*(code *)PTR_FUN_10033ca4)(param_1);
  return;
}



// Function: _com_dispatch_method at 1001dd40

/* Library Function - Single Match
    long __cdecl _com_dispatch_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2010 Release */

long __cdecl
_com_dispatch_method
          (IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
          ushort *param_6,...)

{
  long lVar1;
  IErrorInfo *local_8;
  
  lVar1 = _com_invoke_helper(param_1,param_2,param_3,param_4,param_5,param_6,&stack0x0000001c,
                             &local_8);
  if (lVar1 < 0) {
    (*(code *)PTR_FUN_10033ca4)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 1001dd90

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2010 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 1001ddc0

/* Library Function - Single Match
    long __cdecl _com_dispatch_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2010 Release */

long __cdecl _com_dispatch_propput(IDispatch *param_1,long param_2,ushort param_3,...)

{
  ushort uVar1;
  long lVar2;
  IErrorInfo *local_c;
  ushort local_8 [2];
  
  local_8[0] = param_3;
  local_8[1] = 0;
  if ((param_3 == 9) || (uVar1 = 4, param_3 == 0xd)) {
    uVar1 = 8;
  }
  lVar2 = _com_invoke_helper(param_1,param_2,uVar1,0,(void *)0x0,local_8,&stack0x00000010,&local_c);
  if (lVar2 < 0) {
    (*(code *)PTR_FUN_10033ca4)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_error at 1001de30

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(long *)(this + 4) = param_1;
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1002b920;
  *(IErrorInfo **)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (**(code **)(*(int *)param_2 + 4))(param_2);
  }
  return this;
}



// Function: FUN_1001dea0 at 1001dea0

void FUN_1001dea0(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__1002b920;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10030a60);
}



// Function: _com_error at 1001dee0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1002b920;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 1001df20

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1002b920;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (*(HLOCAL *)(this + 0xc) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1001df70 at 1001df70

uint FUN_1001df70(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: _com_invoke_helper at 1001df90

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    long __cdecl _com_invoke_helper(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,char *,struct IErrorInfo * *)
   
   Library: Visual Studio 2010 Release */

long __cdecl
_com_invoke_helper(IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
                  ushort *param_6,char *param_7,IErrorInfo **param_8)

{
  ushort uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  long lVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  uint uStack_8c;
  uint local_7c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 *local_44;
  undefined1 *local_40;
  undefined4 *local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_1001eee3;
  local_14 = ExceptionList;
  local_c = DAT_10033cc0 ^ 0x10030a98;
  local_7c = DAT_10033cc0 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_7c;
  ExceptionList = &local_14;
  local_20 = local_7c;
  puVar2 = &local_7c;
  if (param_1 == (IDispatch *)0x0) goto LAB_1001e31e;
  if (param_8 != (IErrorInfo **)0x0) {
    *param_8 = (IErrorInfo *)0x0;
  }
  local_40 = (undefined1 *)0x0;
  local_3c = (undefined4 *)0x0;
  local_38 = 0;
  local_34 = 0;
  puVar2 = &local_7c;
  if (param_6 != (ushort *)0x0) {
    local_38 = lstrlenW((LPCWSTR)param_6);
    puVar2 = (uint *)local_1c;
  }
  local_1c = (undefined1 *)puVar2;
  local_4c = 0xfffffffd;
  if ((param_3 & 0xc) != 0) {
    puVar2 = (uint *)local_1c;
    if (local_38 == 0) goto LAB_1001e31e;
    local_34 = 1;
    local_3c = &local_4c;
  }
  if (local_38 != 0) {
    local_1c = (undefined1 *)&local_7c;
    local_44 = (undefined1 *)&local_7c;
    local_8 = 0xfffffffe;
    uStack_8c = 0x1001e059;
    memset(&local_7c,0,local_38 * 0x10);
    local_40 = (undefined1 *)&local_7c;
    puVar3 = &uStack_8c + local_38 * 4;
    uVar1 = *param_6;
    puVar6 = param_6;
    while (uVar1 != 0) {
      uVar1 = *puVar6;
      uVar10 = uVar1 & 0xf7ff;
      *(ushort *)puVar3 = uVar10;
      if (0x4002 < uVar10) {
        switch(uVar10) {
        case 0x4003:
        case 0x4004:
        case 0x4005:
        case 0x4006:
        case 0x4007:
        case 0x4008:
        case 0x4009:
        case 0x400a:
        case 0x400b:
        case 0x400c:
        case 0x400d:
        case 0x400e:
        case 0x4010:
        case 0x4011:
        case 0x4012:
        case 0x4013:
        case 0x4014:
        case 0x4015:
        case 0x4016:
        case 0x4017:
        case 0x4019:
        case 0x4024:
          break;
        default:
switchD_1001e0ab_caseD_f:
          puVar2 = (uint *)local_1c;
          if ((uVar1 & 0x2000) == 0) goto LAB_1001e31e;
        }
switchD_1001e0ab_caseD_3:
        puVar2 = (uint *)((int)param_7 + 4);
        puVar3[2] = *(uint *)param_7;
        goto LAB_1001e185;
      }
      if (uVar10 == 0x4002) goto switchD_1001e0ab_caseD_3;
      switch(uVar10) {
      case 2:
      case 0x12:
        puVar2 = (uint *)((int)param_7 + 4);
        *(short *)(puVar3 + 2) = (short)*(uint *)param_7;
        break;
      case 3:
      case 8:
      case 9:
      case 10:
      case 0xd:
      case 0x13:
      case 0x16:
      case 0x17:
      case 0x19:
      case 0x24:
        goto switchD_1001e0ab_caseD_3;
      case 4:
        *(undefined2 *)puVar3 = 5;
      case 5:
      case 7:
      case 0x14:
      case 0x15:
        puVar2 = (uint *)((int)param_7 + 8);
        puVar3[2] = *(uint *)param_7;
        puVar3[3] = *(uint *)((int)param_7 + 4);
        break;
      case 6:
        puVar2 = (uint *)((int)param_7 + 4);
        puVar8 = *(uint **)param_7;
        puVar3[2] = *puVar8;
        puVar3[3] = puVar8[1];
        break;
      case 0xb:
        puVar2 = (uint *)((int)param_7 + 4);
        *(ushort *)(puVar3 + 2) = -(ushort)((short)*(uint *)param_7 != 0);
        break;
      case 0xc:
        puVar2 = (uint *)((int)param_7 + 4);
        puVar8 = *(uint **)param_7;
        *puVar3 = *puVar8;
        puVar3[1] = puVar8[1];
        puVar3[2] = puVar8[2];
        puVar3[3] = puVar8[3];
        break;
      case 0xe:
        puVar2 = (uint *)((int)param_7 + 4);
        puVar8 = *(uint **)param_7;
        *puVar3 = *puVar8;
        puVar3[1] = puVar8[1];
        puVar3[2] = puVar8[2];
        puVar3[3] = puVar8[3];
        *(undefined2 *)puVar3 = 0xe;
        break;
      default:
        goto switchD_1001e0ab_caseD_f;
      case 0x10:
      case 0x11:
        puVar2 = (uint *)((int)param_7 + 4);
        *(char *)(puVar3 + 2) = (char)*(uint *)param_7;
      }
LAB_1001e185:
      puVar3 = puVar3 + -4;
      puVar6 = puVar6 + 1;
      param_7 = (char *)puVar2;
      uVar1 = *puVar6;
    }
    puVar3 = &local_7c + local_34 * 4;
    puVar6 = param_6 + (local_38 - local_34) + -1;
    iVar11 = 0;
    puVar2 = &local_7c;
    if (param_6 <= puVar6) {
      while (puVar2 = (uint *)local_44, (*puVar6 & 0xbfff) == 0x80c) {
        puVar8 = puVar3;
        if ((*puVar6 & 0x4000) != 0) {
          puVar8 = (uint *)puVar3[2];
        }
        if (((short)*puVar8 != 10) || (puVar8[2] != 0x80020004)) break;
        iVar11 = iVar11 + 1;
        puVar3 = puVar3 + 4;
        puVar6 = puVar6 + -1;
        if (puVar6 < param_6) break;
      }
    }
    if (iVar11 != 0) {
      uVar9 = 0;
      if (local_34 != 0) {
        do {
          puVar4 = (undefined4 *)((int)puVar2 + uVar9 * 0x10);
          puVar7 = (undefined4 *)((int)puVar2 + (uVar9 + iVar11) * 0x10);
          *puVar7 = *puVar4;
          puVar7[1] = puVar4[1];
          puVar7[2] = puVar4[2];
          puVar7[3] = puVar4[3];
          uVar9 = uVar9 + 1;
        } while (uVar9 < local_34);
      }
      local_38 = local_38 - iVar11;
      local_40 = local_40 + iVar11 * 0x10;
    }
  }
  Ordinal_8();
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_48 = 0xffffffff;
  uStack_8c = -(uint)(param_4 != 0) & (uint)&local_30;
  iVar11 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_1002b924,0,_param_3,&local_40)
  ;
  if (iVar11 < 0) {
    Ordinal_9(&local_30);
    puVar2 = (uint *)local_1c;
    if (iVar11 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_6c,param_8);
      puVar2 = (uint *)local_1c;
    }
    goto LAB_1001e31e;
  }
  puVar2 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_1001e31e;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar11 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar11 < 0)))) {
    Ordinal_9(&local_30);
    puVar2 = (uint *)local_1c;
    goto LAB_1001e31e;
  }
  puVar2 = (uint *)local_1c;
  if (0x4002 < param_4) {
    switch(param_4) {
    case 0x4003:
    case 0x4007:
    case 0x4009:
    case 0x400c:
    case 0x4010:
    case 0x4013:
    case 0x4014:
      goto switchD_1001e363_caseD_3;
    case 0x4004:
    case 0x4006:
    case 0x400a:
    case 0x400d:
    case 0x4011:
    case 0x4015:
    case 0x4016:
    case 0x4019:
switchD_1001e363_caseD_9:
      *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      break;
    default:
switchD_1001e363_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar2 = (uint *)local_1c;
        break;
      }
    case 0x4005:
    case 0x4008:
    case 0x400b:
    case 0x400e:
    case 0x4012:
    case 0x4017:
    case 0x4024:
switchD_1001e363_caseD_a:
      *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
    }
    goto LAB_1001e31e;
  }
  if (param_4 == 0x4002) {
switchD_1001e363_caseD_3:
    *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
  }
  else {
    switch(param_4) {
    case 2:
      *(ushort *)param_5 = CONCAT11(uStack_27,local_28);
      break;
    case 3:
    case 8:
    case 0x16:
      goto switchD_1001e363_caseD_3;
    case 4:
      *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      break;
    case 5:
    case 7:
      *(ulonglong *)param_5 = CONCAT44(uStack_24,CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)));
      break;
    case 6:
    case 0x15:
      *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      *(undefined4 *)((int)param_5 + 4) = uStack_24;
      break;
    case 9:
    case 0xd:
    case 0x17:
      goto switchD_1001e363_caseD_9;
    case 10:
    case 0x13:
    case 0x19:
    case 0x24:
      goto switchD_1001e363_caseD_a;
    case 0xb:
      *(ushort *)param_5 = CONCAT11(uStack_27,local_28);
      break;
    case 0xc:
      *(undefined4 *)param_5 = local_30;
      *(undefined4 *)((int)param_5 + 4) = local_2c;
      *(uint *)((int)param_5 + 8) = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      *(undefined4 *)((int)param_5 + 0xc) = uStack_24;
      break;
    case 0xe:
      *(undefined4 *)param_5 = local_30;
      *(undefined4 *)((int)param_5 + 4) = local_2c;
      *(uint *)((int)param_5 + 8) = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      *(undefined4 *)((int)param_5 + 0xc) = uStack_24;
      break;
    default:
      goto switchD_1001e363_caseD_f;
    case 0x10:
      *(undefined1 *)param_5 = local_28;
      break;
    case 0x11:
      *(undefined1 *)param_5 = local_28;
      break;
    case 0x12:
      *(ushort *)param_5 = CONCAT11(uStack_27,local_28);
      break;
    case 0x14:
      *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
      *(undefined4 *)((int)param_5 + 4) = uStack_24;
    }
  }
LAB_1001e31e:
  local_1c = (undefined1 *)puVar2;
  ExceptionList = local_14;
  lVar5 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar5;
}



// Function: _com_dispatch_raw_method at 1001e560

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2010 Release */

long __cdecl
_com_dispatch_raw_method
          (IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
          ushort *param_6,...)

{
  long lVar1;
  IErrorInfo *local_8;
  
  lVar1 = _com_invoke_helper(param_1,param_2,param_3,param_4,param_5,param_6,&stack0x0000001c,
                             &local_8);
  if (lVar1 < 0) {
    Ordinal_201(0,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_raw_propget at 1001e5b0

/* Library Function - Single Match
    long __stdcall _com_dispatch_raw_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2010 Release */

long _com_dispatch_raw_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_raw_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_raw_propput at 1001e5e0

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2010 Release */

long __cdecl _com_dispatch_raw_propput(IDispatch *param_1,long param_2,ushort param_3,...)

{
  ushort uVar1;
  long lVar2;
  IErrorInfo *local_c;
  ushort local_8 [2];
  
  local_8[0] = param_3;
  local_8[1] = 0;
  if ((param_3 == 9) || (uVar1 = 4, param_3 == 0xd)) {
    uVar1 = 8;
  }
  lVar2 = _com_invoke_helper(param_1,param_2,uVar1,0,(void *)0x0,local_8,&stack0x00000010,&local_c);
  if (lVar2 < 0) {
    Ordinal_201(0,local_c);
  }
  return lVar2;
}



// Function: FUN_1001e650 at 1001e650

int FUN_1001e650(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 1001e680

/* Library Function - Single Match
    long __stdcall _com_handle_excepinfo(struct tagEXCEPINFO &,struct IErrorInfo * *)
   
   Library: Visual Studio 2010 Release */

long _com_handle_excepinfo(tagEXCEPINFO *param_1,IErrorInfo **param_2)

{
  ushort uVar1;
  tagEXCEPINFO *ptVar2;
  IErrorInfo **ppIVar3;
  int iVar4;
  
  ptVar2 = param_1;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  ppIVar3 = param_2;
  param_1 = (tagEXCEPINFO *)0x0;
  if (param_2 != (IErrorInfo **)0x0) {
    iVar4 = Ordinal_202(&param_1);
    if (-1 < iVar4) {
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_10028e70);
      if (*(int *)(ptVar2 + 4) != 0) {
        (**(code **)(*(int *)param_1 + 0x10))(param_1,*(int *)(ptVar2 + 4));
      }
      if (*(int *)(ptVar2 + 8) != 0) {
        (**(code **)(*(int *)param_1 + 0x14))(param_1,*(int *)(ptVar2 + 8));
      }
      if (*(int *)(ptVar2 + 0xc) != 0) {
        (**(code **)(*(int *)param_1 + 0x18))(param_1,*(int *)(ptVar2 + 0xc));
      }
      (**(code **)(*(int *)param_1 + 0x1c))(param_1,*(undefined4 *)(ptVar2 + 0x10));
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_1002b934,ppIVar3);
      if (iVar4 < 0) {
        *ppIVar3 = (IErrorInfo *)0x0;
      }
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
  if (*(int *)(ptVar2 + 4) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 4));
  }
  if (*(int *)(ptVar2 + 8) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 8));
  }
  if (*(int *)(ptVar2 + 0xc) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 0xc));
  }
  uVar1 = *(ushort *)ptVar2;
  if (uVar1 != 0) {
    if (0xfdff < uVar1) {
      return -0x7ffb0001;
    }
    return uVar1 + 0x80040200;
  }
  return *(long *)(ptVar2 + 0x1c);
}



// Function: FID_conflict:`vector_deleting_destructor' at 1001e79b

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CDaoRelationFieldInfo::`vector deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall exception::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::exception::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall logic_error::`vector deleting destructor'(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

type_info * __thiscall FID_conflict__vector_deleting_destructor_(void *this,byte param_1)

{
  type_info *ptVar1;
  
  if ((param_1 & 2) == 0) {
    type_info::_type_info_dtor_internal_method((type_info *)this);
    ptVar1 = (type_info *)this;
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    ptVar1 = (type_info *)((int)this + -4);
    _eh_vector_destructor_iterator_
              (this,0xc,*(int *)ptVar1,type_info::_type_info_dtor_internal_method);
    if ((param_1 & 1) != 0) {
      operator_delete(ptVar1);
    }
  }
  return ptVar1;
}



// Function: __onexit at 1001e7f2

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2010 Release */

_onexit_t __cdecl __onexit(_onexit_t param_1)

{
  _onexit_t p_Var1;
  PVOID pvVar2;
  PVOID *ppvVar3;
  PVOID *ppvVar4;
  PVOID local_24;
  PVOID local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_10030ab8;
  uStack_c = 0x1001e7fe;
  local_20[0] = DecodePointer(DAT_10034584);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10034584);
    local_24 = DecodePointer(DAT_10034574);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10034584 = EncodePointer(local_20[0]);
    DAT_10034574 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001e88a();
  }
  return p_Var1;
}



// Function: FUN_1001e88a at 1001e88a

void FUN_1001e88a(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001e893

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe_16 at 1001e8d0

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2010 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 1001e8e6

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_8
   
   Library: Visual Studio */

uint __alloca_probe_8(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 7;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __ArrayUnwind at 1001e92c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffc8;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffc8);
  }
  return;
}



// Function: `eh_vector_destructor_iterator' at 1001e98a

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_1001e9d5();
  return;
}



// Function: FUN_1001e9d5 at 1001e9d5

void FUN_1001e9d5(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe at 1001ea00

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Library: Visual Studio */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)((int)&stack0x00000000 - (int)in_EAX & ~-(uint)(&stack0x00000000 < in_EAX))
  ;
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1;
      puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = unaff_retaddr;
  return;
}



// Function: `eh_vector_constructor_iterator' at 1001ea44

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  void *in_stack_ffffffcc;
  undefined4 local_20;
  
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*param_4)(in_stack_ffffffcc);
  }
  FUN_1001ea91();
  return;
}



// Function: FUN_1001ea91 at 1001ea91

void FUN_1001ea91(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __allmul at 1001eaf0

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// Function: __CRT_INIT@12 at 1001eb8b

/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 2010 Release */

undefined4 __CRT_INIT_12(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  void *Exchange;
  BOOL BVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int *piVar8;
  
  Exchange = StackBase;
  if (param_2 == (int *)0x0) {
    if (DAT_10034220 < 1) {
      return 0;
    }
    DAT_10034220 = DAT_10034220 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10034564,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10034554 == 2) {
      param_2 = (int *)DecodePointer(DAT_10034584);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10034574);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10034584);
            piVar8 = (int *)DecodePointer(DAT_10034574);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10034574 = (PVOID)encoded_null();
        DAT_10034584 = DAT_10034574;
      }
      DAT_10034554 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10034564,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10034564,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10034554 == 0) {
      DAT_10034554 = 1;
      iVar5 = initterm_e(&DAT_100284c0,&DAT_100286c8);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10028000,&DAT_100283bc);
      DAT_10034554 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10034564,0);
    }
    if ((DAT_10034568 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10034568), BVar2 != 0)) {
      (*DAT_10034568)(param_1,2,param_3);
    }
    DAT_10034220 = DAT_10034220 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001ed95

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001ee35) */
/* WARNING: Removing unreachable block (ram,0x1001ede2) */
/* WARNING: Removing unreachable block (ram,0x1001ee62) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10033cd0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10034220 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = thunk_FUN_10009130(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      thunk_FUN_10009130(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1001eea0();
  return local_20;
}



// Function: FUN_1001eea0 at 1001eea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eea0(void)

{
  _DAT_10033cd0 = 0xffffffff;
  return;
}



// Function: entry at 1001eeab

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: __security_check_cookie at 1001eed4

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10033cc0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FUN_1001eee3 at 1001eee3

void __cdecl
FUN_1001eee3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10033cc0,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __SEH_prolog4 at 1001ef20

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4
   
   Library: Visual Studio */

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  iVar1 = -param_2;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10033cc0 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1001ef65

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __SEH_epilog4
   
   Library: Visual Studio */

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}



// Function: __ValidateImageBase at 1001eff0

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b);
  }
  return 0;
}



// Function: __FindPESection at 1001f030

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2010 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



// Function: __IsNonwritableInCurrentImage at 1001f080

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_1001eee3;
  local_14 = ExceptionList;
  local_c = DAT_10033cc0 ^ 0x10030b60;
  ExceptionList = &local_14;
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_10000000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_10000000,(DWORD_PTR)(pTarget + -0x10000000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}



// Function: ___security_init_cookie at 1001f154

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2010 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  LARGE_INTEGER local_14;
  _FILETIME local_c;
  
  local_c.dwLowDateTime = 0;
  local_c.dwHighDateTime = 0;
  if ((DAT_10033cc0 == 0xbb40e64e) || ((DAT_10033cc0 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10033cc0 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10033cc0 == 0xbb40e64e) {
      DAT_10033cc0 = 0xbb40e64f;
    }
    else if ((DAT_10033cc0 & 0xffff0000) == 0) {
      DAT_10033cc0 = DAT_10033cc0 | (DAT_10033cc0 | 0x4711) << 0x10;
    }
    DAT_10033cc4 = ~DAT_10033cc0;
  }
  else {
    DAT_10033cc4 = ~DAT_10033cc0;
  }
  return;
}



// Function: ___report_gsfailure at 1001f1ef

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___report_gsfailure(void)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 local_32c;
  undefined4 local_328;
  
  _DAT_10034348 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1003434c = &stack0x00000004;
  _DAT_10034288 = 0x10001;
  _DAT_10034230 = 0xc0000409;
  _DAT_10034234 = 1;
  local_32c = DAT_10033cc0;
  local_328 = DAT_10033cc4;
  _DAT_1003423c = unaff_retaddr;
  _DAT_10034314 = in_GS;
  _DAT_10034318 = in_FS;
  _DAT_1003431c = in_ES;
  _DAT_10034320 = in_DS;
  _DAT_10034324 = unaff_EDI;
  _DAT_10034328 = unaff_ESI;
  _DAT_1003432c = unaff_EBX;
  _DAT_10034330 = in_EDX;
  _DAT_10034334 = in_ECX;
  _DAT_10034338 = in_EAX;
  _DAT_1003433c = unaff_EBP;
  DAT_10034340 = unaff_retaddr;
  _DAT_10034344 = in_CS;
  _DAT_10034350 = in_SS;
  DAT_10034280 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1002b964);
  if (DAT_10034280 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: Unwind@10020860 at 10020860

void Unwind_10020860(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@10020868 at 10020868

void Unwind_10020868(void)

{
  thunk_FUN_100087e0();
  return;
}



// Function: Unwind@10020876 at 10020876

void Unwind_10020876(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650((int *)(*(int *)(unaff_EBP + -0x90) + 8));
  return;
}



// Function: Unwind@10020884 at 10020884

void Unwind_10020884(void)

{
  thunk_FUN_100073d0();
  return;
}



// Function: Unwind@1002088c at 1002088c

void Unwind_1002088c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006790((_Container_base0 *)(*(int *)(unaff_EBP + -0x90) + 0x3c));
  return;
}



// Function: Unwind@1002089a at 1002089a

void Unwind_1002089a(void)

{
  thunk_FUN_100073d0();
  return;
}



// Function: Unwind@100208a2 at 100208a2

void Unwind_100208a2(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006790((_Container_base0 *)(*(int *)(unaff_EBP + -0x90) + 0x4c));
  return;
}



// Function: Unwind@100208b0 at 100208b0

void Unwind_100208b0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(*(int *)(unaff_EBP + -0x90) + 0x60);
  return;
}



// Function: Unwind@100208be at 100208be

void Unwind_100208be(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100208f0 at 100208f0

void Unwind_100208f0(void)

{
  thunk_FUN_100087e0();
  return;
}



// Function: Unwind@100208fb at 100208fb

void Unwind_100208fb(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650((int *)(*(int *)(unaff_EBP + -0x5c) + 8));
  return;
}



// Function: Unwind@10020906 at 10020906

void Unwind_10020906(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006790((_Container_base0 *)(*(int *)(unaff_EBP + -0x5c) + 0x3c));
  return;
}



// Function: Unwind@10020911 at 10020911

void Unwind_10020911(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006790((_Container_base0 *)(*(int *)(unaff_EBP + -0x5c) + 0x4c));
  return;
}



// Function: Unwind@1002091c at 1002091c

void Unwind_1002091c(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(*(int *)(unaff_EBP + -0x5c) + 0x60);
  return;
}



// Function: Unwind@10020927 at 10020927

void Unwind_10020927(void)

{
  thunk_FUN_100073d0();
  return;
}



// Function: Unwind@1002092f at 1002092f

void Unwind_1002092f(void)

{
  thunk_FUN_100073d0();
  return;
}



// Function: Unwind@10020937 at 10020937

void Unwind_10020937(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@10020970 at 10020970

void Unwind_10020970(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020990 at 10020990

void Unwind_10020990(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020998 at 10020998

void Unwind_10020998(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100209b0 at 100209b0

void Unwind_100209b0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100209d0 at 100209d0

void Unwind_100209d0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100209d8 at 100209d8

void Unwind_100209d8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100209f0 at 100209f0

void Unwind_100209f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10020a10 at 10020a10

void Unwind_10020a10(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020a30 at 10020a30

void Unwind_10020a30(void)

{
  DAT_10033e34 = DAT_10033e34 & 0xfffffffe;
  return;
}



// Function: Unwind@10020a3e at 10020a3e

void Unwind_10020a3e(void)

{
  DAT_10033e34 = DAT_10033e34 & 0xfffffffd;
  return;
}



// Function: Unwind@10020a4c at 10020a4c

void Unwind_10020a4c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006960((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10020a54 at 10020a54

void Unwind_10020a54(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10020a5c at 10020a5c

void Unwind_10020a5c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006090((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10020a64 at 10020a64

void Unwind_10020a64(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006060((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020a6c at 10020a6c

void Unwind_10020a6c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006030((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10020a74 at 10020a74

void Unwind_10020a74(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@10020a7c at 10020a7c

void Unwind_10020a7c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008f20(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10020a84 at 10020a84

void Unwind_10020a84(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10020a8f at 10020a8f

void Unwind_10020a8f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10020a9a at 10020a9a

void Unwind_10020a9a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006990((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020ad0 at 10020ad0

void Unwind_10020ad0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + 0x1c));
  return;
}



// Function: Unwind@10020ad8 at 10020ad8

void Unwind_10020ad8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    thunk_FUN_10006090(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10020b10 at 10020b10

void Unwind_10020b10(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020b30 at 10020b30

void Unwind_10020b30(void)

{
  int unaff_EBP;
  
  thunk_FUN_100069c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020b38 at 10020b38

void Unwind_10020b38(void)

{
  int unaff_EBP;
  
  thunk_FUN_100069f0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10020b40 at 10020b40

void Unwind_10020b40(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008f20(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@10020b48 at 10020b48

void Unwind_10020b48(void)

{
  int unaff_EBP;
  
  thunk_FUN_100060c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10020b50 at 10020b50

void Unwind_10020b50(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10020b58 at 10020b58

void Unwind_10020b58(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10020b80 at 10020b80

void Unwind_10020b80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020b8b at 10020b8b

void Unwind_10020b8b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    thunk_FUN_10008c10(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10020bc0 at 10020bc0

void Unwind_10020bc0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    thunk_FUN_100060c0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10020bf0 at 10020bf0

void Unwind_10020bf0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10020c10 at 10020c10

void Unwind_10020c10(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10020c1b at 10020c1b

void Unwind_10020c1b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020c40 at 10020c40

void Unwind_10020c40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020c4b at 10020c4b

void Unwind_10020c4b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020c70 at 10020c70

void Unwind_10020c70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020c7b at 10020c7b

void Unwind_10020c7b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020ca0 at 10020ca0

void Unwind_10020ca0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10020ca8 at 10020ca8

void Unwind_10020ca8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020cc0 at 10020cc0

void Unwind_10020cc0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006650((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10020cc8 at 10020cc8

void Unwind_10020cc8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10020cf0 at 10020cf0

void Unwind_10020cf0(void)

{
  thunk_FUN_100073d0();
  return;
}



// Function: Unwind@10020d10 at 10020d10

void Unwind_10020d10(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x8c);
  return;
}



// Function: Unwind@10020d40 at 10020d40

void Unwind_10020d40(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006090(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020d60 at 10020d60

void Unwind_10020d60(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006960(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020d80 at 10020d80

void Unwind_10020d80(void)

{
  thunk_FUN_10009020();
  return;
}



// Function: Unwind@10020db0 at 10020db0

void Unwind_10020db0(void)

{
  thunk_FUN_10009020();
  return;
}



// Function: Unwind@10020de0 at 10020de0

void Unwind_10020de0(void)

{
  thunk_FUN_10009020();
  return;
}



// Function: Unwind@10020e10 at 10020e10

void Unwind_10020e10(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10020e13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10020e30 at 10020e30

void Unwind_10020e30(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006090((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10020e50 at 10020e50

void Unwind_10020e50(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006960((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10020e80 at 10020e80

void Unwind_10020e80(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009030((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020e88 at 10020e88

void Unwind_10020e88(void)

{
  int unaff_EBP;
  
  thunk_FUN_100086f0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020e90 at 10020e90

void Unwind_10020e90(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020e98 at 10020e98

void Unwind_10020e98(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008760((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020ea0 at 10020ea0

void Unwind_10020ea0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020ea8 at 10020ea8

void Unwind_10020ea8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009030((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020ed0 at 10020ed0

void Unwind_10020ed0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009030(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020ef0 at 10020ef0

void Unwind_10020ef0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009060(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f10 at 10020f10

void Unwind_10020f10(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@10020f30 at 10020f30

void Unwind_10020f30(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f50 at 10020f50

void Unwind_10020f50(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f70 at 10020f70

void Unwind_10020f70(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009030((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020f78 at 10020f78

void Unwind_10020f78(void)

{
  int unaff_EBP;
  
  thunk_FUN_100086f0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020f80 at 10020f80

void Unwind_10020f80(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f88 at 10020f88

void Unwind_10020f88(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008760((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f90 at 10020f90

void Unwind_10020f90(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10020f98 at 10020f98

void Unwind_10020f98(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009030((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10020fc0 at 10020fc0

void Unwind_10020fc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10020fe0 at 10020fe0

void Unwind_10020fe0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10020fe3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021000 at 10021000

void Unwind_10021000(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10021003. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021020 at 10021020

void Unwind_10021020(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10021023. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021040 at 10021040

void Unwind_10021040(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002104b at 1002104b

void Unwind_1002104b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013140(*(int *)(unaff_EBP + -0x20) + 4);
  return;
}



// Function: Unwind@10021056 at 10021056

void Unwind_10021056(void)

{
  int unaff_EBP;
  
  thunk_FUN_10011bc0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10021080 at 10021080

void Unwind_10021080(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002700(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100210a0 at 100210a0

void Unwind_100210a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100210c0 at 100210c0

void Unwind_100210c0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10011bc0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100210e0 at 100210e0

void Unwind_100210e0(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@100210e8 at 100210e8

void Unwind_100210e8(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@100210f0 at 100210f0

void Unwind_100210f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009c90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100210f8 at 100210f8

void Unwind_100210f8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013200((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10021120 at 10021120

void Unwind_10021120(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021140 at 10021140

void Unwind_10021140(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@10021148 at 10021148

void Unwind_10021148(void)

{
  thunk_FUN_100087e0();
  return;
}



// Function: Unwind@10021153 at 10021153

void Unwind_10021153(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002700(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002115b at 1002115b

void Unwind_1002115b(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000a2d0(*(int *)(unaff_EBP + -0x18) + 8);
  return;
}



// Function: Unwind@10021180 at 10021180

void Unwind_10021180(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002700(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100211a0 at 100211a0

void Unwind_100211a0(void)

{
  thunk_FUN_100087e0();
  return;
}



// Function: Unwind@100211ab at 100211ab

void Unwind_100211ab(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000a2d0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@100211b6 at 100211b6

void Unwind_100211b6(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002700(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100211be at 100211be

void Unwind_100211be(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@100211e0 at 100211e0

void Unwind_100211e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002700(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021200 at 10021200

void Unwind_10021200(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1002120b at 1002120b

void Unwind_1002120b(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000b460((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10021216 at 10021216

void Unwind_10021216(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10021221 at 10021221

void Unwind_10021221(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xaa4));
  return;
}



// Function: Unwind@1002122c at 1002122c

void Unwind_1002122c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xab8));
  return;
}



// Function: Unwind@10021237 at 10021237

void Unwind_10021237(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10021242 at 10021242

void Unwind_10021242(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xad0));
  return;
}



// Function: Unwind@1002124d at 1002124d

void Unwind_1002124d(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10021258 at 10021258

void Unwind_10021258(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10021263 at 10021263

void Unwind_10021263(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xad8));
  return;
}



// Function: Unwind@1002126e at 1002126e

void Unwind_1002126e(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10021279 at 10021279

void Unwind_10021279(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xae0));
  return;
}



// Function: Unwind@10021284 at 10021284

void Unwind_10021284(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1002128f at 1002128f

void Unwind_1002128f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xaf0));
  return;
}



// Function: Unwind@1002129a at 1002129a

void Unwind_1002129a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xb04));
  return;
}



// Function: Unwind@100212a5 at 100212a5

void Unwind_100212a5(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xb24));
  return;
}



// Function: Unwind@100212f0 at 100212f0

void Unwind_100212f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10021310 at 10021310

void Unwind_10021310(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021318 at 10021318

void Unwind_10021318(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10021330 at 10021330

void Unwind_10021330(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(*(int *)(unaff_EBP + -0x50) + 4));
  return;
}



// Function: Unwind@1002133b at 1002133b

void Unwind_1002133b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10021360 at 10021360

void Unwind_10021360(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10021380 at 10021380

void Unwind_10021380(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100213a0 at 100213a0

void Unwind_100213a0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100213a8 at 100213a8

void Unwind_100213a8(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x448));
  return;
}



// Function: Unwind@100213d0 at 100213d0

void Unwind_100213d0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100213f0 at 100213f0

void Unwind_100213f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000cac0(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@10021410 at 10021410

void Unwind_10021410(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10021430 at 10021430

void Unwind_10021430(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021438 at 10021438

void Unwind_10021438(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021443 at 10021443

void Unwind_10021443(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x2250));
  return;
}



// Function: Unwind@1002144e at 1002144e

void Unwind_1002144e(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@10021459 at 10021459

void Unwind_10021459(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x226c));
  return;
}



// Function: Unwind@10021480 at 10021480

void Unwind_10021480(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100214a0 at 100214a0

void Unwind_100214a0(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2128));
  return;
}



// Function: Unwind@100214ab at 100214ab

void Unwind_100214ab(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x2150));
  return;
}



// Function: Unwind@100214b6 at 100214b6

void Unwind_100214b6(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@100214e0 at 100214e0

void Unwind_100214e0(void)

{
  DAT_10033e80 = DAT_10033e80 & 0xfffffffe;
  return;
}



// Function: Unwind@10021500 at 10021500

void Unwind_10021500(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021520 at 10021520

void Unwind_10021520(void)

{
  int unaff_EBP;
  
  thunk_FUN_100135c0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021540 at 10021540

void Unwind_10021540(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021548 at 10021548

void Unwind_10021548(void)

{
  int unaff_EBP;
  
  thunk_FUN_10010470((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021550 at 10021550

void Unwind_10021550(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021558 at 10021558

void Unwind_10021558(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021560 at 10021560

void Unwind_10021560(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021568 at 10021568

void Unwind_10021568(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021570 at 10021570

void Unwind_10021570(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10021578 at 10021578

void Unwind_10021578(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10021583 at 10021583

void Unwind_10021583(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1002158e at 1002158e

void Unwind_1002158e(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100215c0 at 100215c0

void Unwind_100215c0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100215e0 at 100215e0

void Unwind_100215e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100215e8 at 100215e8

void Unwind_100215e8(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100215f0 at 100215f0

void Unwind_100215f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10011180((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100215f8 at 100215f8

void Unwind_100215f8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10021600 at 10021600

void Unwind_10021600(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021608 at 10021608

void Unwind_10021608(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021630 at 10021630

void Unwind_10021630(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021650 at 10021650

void Unwind_10021650(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021670 at 10021670

void Unwind_10021670(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10021678 at 10021678

void Unwind_10021678(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021680 at 10021680

void Unwind_10021680(void)

{
  int unaff_EBP;
  
  thunk_FUN_10011180((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021688 at 10021688

void Unwind_10021688(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021690 at 10021690

void Unwind_10021690(void)

{
  int unaff_EBP;
  
  thunk_FUN_100130e0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100216b0 at 100216b0

void Unwind_100216b0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100135c0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100216d0 at 100216d0

void Unwind_100216d0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013140(*(int *)(unaff_EBP + -0x18) + 4);
  return;
}



// Function: Unwind@100216db at 100216db

void Unwind_100216db(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@100216e3 at 100216e3

void Unwind_100216e3(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013200((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100216ee at 100216ee

void Unwind_100216ee(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009c90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100216f6 at 100216f6

void Unwind_100216f6(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021720 at 10021720

void Unwind_10021720(void)

{
  int unaff_EBP;
  
  thunk_FUN_100135c0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10021728 at 10021728

void Unwind_10021728(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021733 at 10021733

void Unwind_10021733(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013110((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1002173e at 1002173e

void Unwind_1002173e(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012790((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10021749 at 10021749

void Unwind_10021749(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013110((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@10021754 at 10021754

void Unwind_10021754(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012790((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1002175f at 1002175f

void Unwind_1002175f(void)

{
  int unaff_EBP;
  
  thunk_FUN_100131d0((int *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@1002176a at 1002176a

void Unwind_1002176a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c20((int *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10021775 at 10021775

void Unwind_10021775(void)

{
  int unaff_EBP;
  
  thunk_FUN_100131d0((int *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10021780 at 10021780

void Unwind_10021780(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013110((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1002178b at 1002178b

void Unwind_1002178b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013110((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@100217c0 at 100217c0

void Unwind_100217c0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100135c0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100217e0 at 100217e0

void Unwind_100217e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013110(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021800 at 10021800

void Unwind_10021800(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002180b at 1002180b

void Unwind_1002180b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021830 at 10021830

void Unwind_10021830(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021850 at 10021850

void Unwind_10021850(void)

{
  int unaff_EBP;
  
  thunk_FUN_100131d0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021870 at 10021870

void Unwind_10021870(void)

{
  thunk_FUN_10013800();
  return;
}



// Function: Unwind@10021889 at 10021889

void Unwind_10021889(void)

{
  thunk_FUN_10013800();
  return;
}



// Function: Unwind@100218c0 at 100218c0

void Unwind_100218c0(void)

{
  thunk_FUN_100087d0();
  return;
}



// Function: Unwind@100218c8 at 100218c8

void Unwind_100218c8(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013200((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100218d3 at 100218d3

void Unwind_100218d3(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009c90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100218db at 100218db

void Unwind_100218db(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021900 at 10021900

void Unwind_10021900(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009c90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021908 at 10021908

void Unwind_10021908(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021920 at 10021920

void Unwind_10021920(void)

{
  int unaff_EBP;
  
  thunk_FUN_100139d0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021928 at 10021928

void Unwind_10021928(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013960((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021930 at 10021930

void Unwind_10021930(void)

{
  int unaff_EBP;
  
  thunk_FUN_100139d0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10021938 at 10021938

void Unwind_10021938(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013960((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10021940 at 10021940

void Unwind_10021940(void)

{
  int unaff_EBP;
  
  thunk_FUN_100139d0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10021948 at 10021948

void Unwind_10021948(void)

{
  int unaff_EBP;
  
  thunk_FUN_100139d0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021970 at 10021970

void Unwind_10021970(void)

{
  int unaff_EBP;
  
  thunk_FUN_100139d0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021990 at 10021990

void Unwind_10021990(void)

{
  thunk_FUN_10013af0(0x10033e94);
  return;
}



// Function: Unwind@1002199a at 1002199a

void Unwind_1002199a(void)

{
  thunk_FUN_10013dc0(0x10033e94);
  return;
}



// Function: Unwind@100219c0 at 100219c0

void Unwind_100219c0(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@100219cb at 100219cb

void Unwind_100219cb(void)

{
  thunk_FUN_10013c50();
  return;
}



// Function: Unwind@100219f0 at 100219f0

void Unwind_100219f0(void)

{
  thunk_FUN_10013c50();
  return;
}



// Function: Unwind@100219fb at 100219fb

void Unwind_100219fb(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021a20 at 10021a20

void Unwind_10021a20(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021a40 at 10021a40

void Unwind_10021a40(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013dc0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021a48 at 10021a48

void Unwind_10021a48(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013af0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021a50 at 10021a50

void Unwind_10021a50(void)

{
  thunk_FUN_10013c50();
  return;
}



// Function: Unwind@10021a5b at 10021a5b

void Unwind_10021a5b(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021a80 at 10021a80

void Unwind_10021a80(void)

{
  int unaff_EBP;
  
  thunk_FUN_10013af0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10021a88 at 10021a88

void Unwind_10021a88(void)

{
  thunk_FUN_10013c50();
  return;
}



// Function: Unwind@10021a93 at 10021a93

void Unwind_10021a93(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021ac0 at 10021ac0

void Unwind_10021ac0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021acb at 10021acb

void Unwind_10021acb(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000b460((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10021ad6 at 10021ad6

void Unwind_10021ad6(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021ae1 at 10021ae1

void Unwind_10021ae1(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xaac));
  return;
}



// Function: Unwind@10021aec at 10021aec

void Unwind_10021aec(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xac0));
  return;
}



// Function: Unwind@10021af7 at 10021af7

void Unwind_10021af7(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021b02 at 10021b02

void Unwind_10021b02(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xad8));
  return;
}



// Function: Unwind@10021b0d at 10021b0d

void Unwind_10021b0d(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10021b18 at 10021b18

void Unwind_10021b18(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021b23 at 10021b23

void Unwind_10021b23(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xae0));
  return;
}



// Function: Unwind@10021b2e at 10021b2e

void Unwind_10021b2e(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021b39 at 10021b39

void Unwind_10021b39(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xae8));
  return;
}



// Function: Unwind@10021b44 at 10021b44

void Unwind_10021b44(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021b4f at 10021b4f

void Unwind_10021b4f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xaf8));
  return;
}



// Function: Unwind@10021b5a at 10021b5a

void Unwind_10021b5a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xb0c));
  return;
}



// Function: Unwind@10021b65 at 10021b65

void Unwind_10021b65(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0xb2c));
  return;
}



// Function: Unwind@10021b70 at 10021b70

void Unwind_10021b70(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ae70((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10021b7b at 10021b7b

void Unwind_10021b7b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012ce0(*(int **)(unaff_EBP + -0xb40));
  return;
}



// Function: Unwind@10021bd0 at 10021bd0

void Unwind_10021bd0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021bf0 at 10021bf0

void Unwind_10021bf0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10021c10 at 10021c10

void Unwind_10021c10(void)

{
  thunk_FUN_10013dc0(0x10033e94);
  return;
}



// Function: Unwind@10021c1a at 10021c1a

void Unwind_10021c1a(void)

{
  thunk_FUN_10013af0(0x10033e94);
  return;
}



// Function: Unwind@10021c24 at 10021c24

void Unwind_10021c24(void)

{
  thunk_FUN_10013c50();
  return;
}



// Function: Unwind@10021c2e at 10021c2e

void Unwind_10021c2e(void)

{
  thunk_FUN_10009c80();
  return;
}



// Function: Unwind@10021c50 at 10021c50

void Unwind_10021c50(void)

{
  DAT_10033ed4 = DAT_10033ed4 & 0xfffffffe;
  return;
}



// Function: Unwind@10021c5e at 10021c5e

void Unwind_10021c5e(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x620));
  return;
}



// Function: Unwind@10021c69 at 10021c69

void Unwind_10021c69(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10021c74 at 10021c74

void Unwind_10021c74(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x624));
  return;
}



// Function: Unwind@10021c7f at 10021c7f

void Unwind_10021c7f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x628));
  return;
}



// Function: Unwind@10021c8a at 10021c8a

void Unwind_10021c8a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x62c));
  return;
}



// Function: Unwind@10021c95 at 10021c95

void Unwind_10021c95(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008c10((int *)(unaff_EBP + -0x630));
  return;
}



// Function: Unwind@10021ca0 at 10021ca0

void Unwind_10021ca0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x634) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x634) = *(uint *)(unaff_EBP + -0x634) & 0xfffffffe;
    thunk_FUN_10008c10(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021cf0 at 10021cf0

void Unwind_10021cf0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10021d10 at 10021d10

void Unwind_10021d10(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dcc0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10021d18 at 10021d18

void Unwind_10021d18(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10021d20 at 10021d20

void Unwind_10021d20(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@10021d40 at 10021d40

void Unwind_10021d40(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015a20(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021d4b at 10021d4b

void Unwind_10021d4b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021d90 at 10021d90

void Unwind_10021d90(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015b10(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021d9b at 10021d9b

void Unwind_10021d9b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021de0 at 10021de0

void Unwind_10021de0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015a20(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021deb at 10021deb

void Unwind_10021deb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021e30 at 10021e30

void Unwind_10021e30(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10021e38 at 10021e38

void Unwind_10021e38(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x20) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 0xfffffffe;
    thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021e70 at 10021e70

void Unwind_10021e70(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015b10(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021e7b at 10021e7b

void Unwind_10021e7b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021ec0 at 10021ec0

void Unwind_10021ec0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015a20(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021ecb at 10021ecb

void Unwind_10021ecb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021f10 at 10021f10

void Unwind_10021f10(void)

{
  int unaff_EBP;
  
  thunk_FUN_10015b10(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@10021f1b at 10021f1b

void Unwind_10021f1b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb8) = *(uint *)(unaff_EBP + -0xb8) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021f60 at 10021f60

void Unwind_10021f60(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021f68 at 10021f68

void Unwind_10021f68(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021fa0 at 10021fa0

void Unwind_10021fa0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021fa8 at 10021fa8

void Unwind_10021fa8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10021fe0 at 10021fe0

void Unwind_10021fe0(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10021fe8 at 10021fe8

void Unwind_10021fe8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x20) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022020 at 10022020

void Unwind_10022020(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022028 at 10022028

void Unwind_10022028(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x20) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022060 at 10022060

void Unwind_10022060(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022090 at 10022090

void Unwind_10022090(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_10004750(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100220c0 at 100220c0

void Unwind_100220c0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@100220e0 at 100220e0

void Unwind_100220e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10022100 at 10022100

void Unwind_10022100(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10022120 at 10022120

void Unwind_10022120(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10022140 at 10022140

void Unwind_10022140(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026e0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10022160 at 10022160

void Unwind_10022160(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_100026e0(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022190 at 10022190

void Unwind_10022190(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_100026e0(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100221c0 at 100221c0

void Unwind_100221c0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100221c8 at 100221c8

void Unwind_100221c8(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100221d0 at 100221d0

void Unwind_100221d0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100221d8 at 100221d8

void Unwind_100221d8(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100221e0 at 100221e0

void Unwind_100221e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100221e8 at 100221e8

void Unwind_100221e8(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100221f0 at 100221f0

void Unwind_100221f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x80) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x80) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022209 at 10022209

void Unwind_10022209(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022211 at 10022211

void Unwind_10022211(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022219 at 10022219

void Unwind_10022219(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022221 at 10022221

void Unwind_10022221(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022250 at 10022250

void Unwind_10022250(void)

{
  int unaff_EBP;
  
  thunk_FUN_10019450((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1002225b at 1002225b

void Unwind_1002225b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xb0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xb0) = *(uint *)(unaff_EBP + -0xb0) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100222a0 at 100222a0

void Unwind_100222a0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100222a8 at 100222a8

void Unwind_100222a8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x2c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x2c) = *(uint *)(unaff_EBP + -0x2c) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100222c1 at 100222c1

void Unwind_100222c1(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100222e0 at 100222e0

void Unwind_100222e0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10019490((undefined4 *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@100222eb at 100222eb

void Unwind_100222eb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x130) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x130) = *(uint *)(unaff_EBP + -0x130) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022330 at 10022330

void Unwind_10022330(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004750((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10022350 at 10022350

void Unwind_10022350(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1a0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1a0) = *(uint *)(unaff_EBP + -0x1a0) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022390 at 10022390

void Unwind_10022390(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x100223a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x30) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@100223ad at 100223ad

void Unwind_100223ad(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100223b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x30) + 0x18));
  return;
}



// Function: Unwind@100223b9 at 100223b9

void Unwind_100223b9(void)

{
  int unaff_EBP;
  
  thunk_FUN_10017650((basic_streambuf<char,struct_std::char_traits<char>_> *)
                     (*(int *)(unaff_EBP + -0x30) + 0x18));
  return;
}



// Function: Unwind@100223e0 at 100223e0

void Unwind_100223e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100223e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x1c) + -0x48));
  return;
}



// Function: Unwind@100223ec at 100223ec

void Unwind_100223ec(void)

{
  int unaff_EBP;
  
  thunk_FUN_10017650((basic_streambuf<char,struct_std::char_traits<char>_> *)
                     (*(int *)(unaff_EBP + -0x1c) + -0x48));
  return;
}



// Function: Unwind@100223f7 at 100223f7

void Unwind_100223f7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100223fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022420 at 10022420

void Unwind_10022420(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022450 at 10022450

void Unwind_10022450(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10022453. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022470 at 10022470

void Unwind_10022470(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022490 at 10022490

void Unwind_10022490(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x100224a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x30) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@100224ad at 100224ad

void Unwind_100224ad(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100224b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x30) + 0x18));
  return;
}



// Function: Unwind@100224b9 at 100224b9

void Unwind_100224b9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100224bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100224c2 at 100224c2

void Unwind_100224c2(void)

{
  int unaff_EBP;
  
  thunk_FUN_100186e0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
                     (*(int *)(unaff_EBP + -0x30) + 0x18));
  return;
}



// Function: Unwind@100224f0 at 100224f0

void Unwind_100224f0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100224f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x1c) + -0x48));
  return;
}



// Function: Unwind@100224fc at 100224fc

void Unwind_100224fc(void)

{
  int unaff_EBP;
  
  thunk_FUN_100186e0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
                     (*(int *)(unaff_EBP + -0x1c) + -0x48));
  return;
}



// Function: Unwind@10022507 at 10022507

void Unwind_10022507(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002250a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022530 at 10022530

void Unwind_10022530(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022560 at 10022560

void Unwind_10022560(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10022563. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022580 at 10022580

void Unwind_10022580(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10022583. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100225a0 at 100225a0

void Unwind_100225a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100225a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100225c0 at 100225c0

void Unwind_100225c0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100225c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100225e0 at 100225e0

void Unwind_100225e0(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@100225e8 at 100225e8

void Unwind_100225e8(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b330((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100225f0 at 100225f0

void Unwind_100225f0(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@100225f8 at 100225f8

void Unwind_100225f8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -100) & 1) != 0) {
    *(uint *)(unaff_EBP + -100) = *(uint *)(unaff_EBP + -100) & 0xfffffffe;
    thunk_FUN_1001b330(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10022611 at 10022611

void Unwind_10022611(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022619 at 10022619

void Unwind_10022619(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022621 at 10022621

void Unwind_10022621(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b330((void *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10022629 at 10022629

void Unwind_10022629(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022631 at 10022631

void Unwind_10022631(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022639 at 10022639

void Unwind_10022639(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022641 at 10022641

void Unwind_10022641(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b330((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10022649 at 10022649

void Unwind_10022649(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022651 at 10022651

void Unwind_10022651(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022690 at 10022690

void Unwind_10022690(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022698 at 10022698

void Unwind_10022698(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100226a0 at 100226a0

void Unwind_100226a0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226a8 at 100226a8

void Unwind_100226a8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -100) & 1) != 0) {
    *(uint *)(unaff_EBP + -100) = *(uint *)(unaff_EBP + -100) & 0xfffffffe;
    thunk_FUN_1001b430(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100226c1 at 100226c1

void Unwind_100226c1(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226c9 at 100226c9

void Unwind_100226c9(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226d1 at 100226d1

void Unwind_100226d1(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100226d9 at 100226d9

void Unwind_100226d9(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226e1 at 100226e1

void Unwind_100226e1(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226e9 at 100226e9

void Unwind_100226e9(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100226f1 at 100226f1

void Unwind_100226f1(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001b430((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100226f9 at 100226f9

void Unwind_100226f9(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022701 at 10022701

void Unwind_10022701(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022740 at 10022740

void Unwind_10022740(void)

{
  int unaff_EBP;
  
  thunk_FUN_10012c90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022760 at 10022760

void Unwind_10022760(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@10022780 at 10022780

void Unwind_10022780(void)

{
  thunk_FUN_1001b650();
  return;
}



// Function: Unwind@100227a0 at 100227a0

void Unwind_100227a0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100227c0 at 100227c0

void Unwind_100227c0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022800 at 10022800

void Unwind_10022800(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10022803. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022820 at 10022820

void Unwind_10022820(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10022823. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022840 at 10022840

void Unwind_10022840(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022860 at 10022860

void Unwind_10022860(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022880 at 10022880

void Unwind_10022880(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100228a0 at 100228a0

void Unwind_100228a0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100228c0 at 100228c0

void Unwind_100228c0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100228e0 at 100228e0

void Unwind_100228e0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022900 at 10022900

void Unwind_10022900(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022920 at 10022920

void Unwind_10022920(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022940 at 10022940

void Unwind_10022940(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022960 at 10022960

void Unwind_10022960(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022980 at 10022980

void Unwind_10022980(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100229a0 at 100229a0

void Unwind_100229a0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100229c0 at 100229c0

void Unwind_100229c0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@100229e0 at 100229e0

void Unwind_100229e0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022a00 at 10022a00

void Unwind_10022a00(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022a20 at 10022a20

void Unwind_10022a20(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022a40 at 10022a40

void Unwind_10022a40(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022a60 at 10022a60

void Unwind_10022a60(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022a80 at 10022a80

void Unwind_10022a80(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022aa0 at 10022aa0

void Unwind_10022aa0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: Unwind@10022ac0 at 10022ac0

void Unwind_10022ac0(void)

{
  thunk_FUN_1001c3f0();
  return;
}



// Function: FUN_10023c90 at 10023c90

void FUN_10023c90(void)

{
  thunk_FUN_10008b20(&DAT_10033e38,0x10028f7c);
  _atexit(FUN_10025470);
  return;
}



// Function: FUN_10023cc0 at 10023cc0

void FUN_10023cc0(void)

{
  thunk_FUN_10008b20(&DAT_10033e3c,0x10028f80);
  _atexit(FUN_100254b0);
  return;
}



// Function: FUN_10023cf0 at 10023cf0

void FUN_10023cf0(void)

{
  thunk_FUN_10008b20(&DAT_10033e40,0x10028f84);
  _atexit(FUN_100254f0);
  return;
}



// Function: FUN_10023d20 at 10023d20

void FUN_10023d20(void)

{
  thunk_FUN_10008b20(&DAT_10033e44,0x10028f90);
  _atexit(FUN_10025530);
  return;
}



// Function: FUN_10023d50 at 10023d50

void FUN_10023d50(void)

{
  thunk_FUN_10008b20(&DAT_10033e84,0x10028f7c);
  _atexit(FUN_100255f0);
  return;
}



// Function: FUN_10023d80 at 10023d80

void FUN_10023d80(void)

{
  thunk_FUN_10008b20(&DAT_10033e88,0x10028f80);
  _atexit(FUN_10025630);
  return;
}



// Function: FUN_10023db0 at 10023db0

void FUN_10023db0(void)

{
  thunk_FUN_10008b20(&DAT_10033e8c,0x10028f84);
  _atexit(FUN_10025670);
  return;
}



// Function: FUN_10023de0 at 10023de0

void FUN_10023de0(void)

{
  thunk_FUN_10008b20(&DAT_10033e90,0x10028f90);
  _atexit(FUN_100256b0);
  return;
}



// Function: FUN_10023e10 at 10023e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023e10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100219a4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  thunk_FUN_10013a00(0x10033e94);
  _DAT_10033e94 = ATL::CComModule::vftable;
  _DAT_10033e54 = &DAT_10033e94;
  local_8 = 0xffffffff;
  _atexit(FUN_100256f0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023ea0 at 10023ea0

void FUN_10023ea0(void)

{
  return;
}



// Function: FUN_10023eb0 at 10023eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023eb0(void)

{
  _DAT_100341b8 = Define_the_symbol__ATL_MIXED::Thank_you::vftable;
  return;
}



// Function: FUN_10023ed0 at 10023ed0

void FUN_10023ed0(void)

{
  thunk_FUN_1001b390(&DAT_10033f20,L"\r");
  _atexit(FUN_100257b0);
  return;
}



// Function: FUN_10023f00 at 10023f00

void FUN_10023f00(void)

{
  thunk_FUN_1001b390(&DAT_10033f04,L"\n");
  _atexit(FUN_10025810);
  return;
}



// Function: FUN_10023f30 at 10023f30

void FUN_10023f30(void)

{
  thunk_FUN_1001b390(&DAT_10033ee8,L"\\n");
  _atexit(FUN_10025870);
  return;
}



// Function: FUN_10023f60 at 10023f60

void FUN_10023f60(void)

{
  thunk_FUN_1001b390(&DAT_100340ac,L"\\r");
  _atexit(FUN_100258d0);
  return;
}



// Function: FUN_10023f90 at 10023f90

void FUN_10023f90(void)

{
  thunk_FUN_1001b390(&DAT_10034000,L"EN");
  _atexit(FUN_10025930);
  return;
}



// Function: FUN_10023fc0 at 10023fc0

void FUN_10023fc0(void)

{
  thunk_FUN_1001b390(&DAT_10034100,L"ES");
  _atexit(FUN_10025990);
  return;
}



// Function: FUN_10023ff0 at 10023ff0

void FUN_10023ff0(void)

{
  thunk_FUN_1001b390(&DAT_10033f3c,L"PT");
  _atexit(FUN_100259f0);
  return;
}



// Function: FUN_10024020 at 10024020

void FUN_10024020(void)

{
  thunk_FUN_1001b390(&DAT_10034058,L"TR");
  _atexit(FUN_10025a50);
  return;
}



// Function: FUN_10024050 at 10024050

void FUN_10024050(void)

{
  thunk_FUN_1001b390(&DAT_100340c8,L"ZH");
  _atexit(FUN_10025ab0);
  return;
}



// Function: FUN_10024080 at 10024080

void FUN_10024080(void)

{
  thunk_FUN_1001b390(&DAT_10034090,L"JA");
  _atexit(FUN_10025b10);
  return;
}



// Function: FUN_100240b0 at 100240b0

void FUN_100240b0(void)

{
  thunk_FUN_1001b390(&DAT_100340e4,L"FR");
  _atexit(FUN_10025b70);
  return;
}



// Function: FUN_100240e0 at 100240e0

void FUN_100240e0(void)

{
  thunk_FUN_1001b390(&DAT_10034020,L"DE");
  _atexit(FUN_10025bd0);
  return;
}



// Function: FUN_10024110 at 10024110

void FUN_10024110(void)

{
  thunk_FUN_1001b390(&DAT_10033fe4,L"IT");
  _atexit(FUN_10025c30);
  return;
}



// Function: FUN_10024140 at 10024140

void FUN_10024140(void)

{
  thunk_FUN_1001b390(&DAT_10033f58,L"KO");
  _atexit(FUN_10025c90);
  return;
}



// Function: FUN_10024170 at 10024170

void FUN_10024170(void)

{
  thunk_FUN_1001b390(&DAT_1003403c,L"RU");
  _atexit(FUN_10025cf0);
  return;
}



// Function: FUN_100241a0 at 100241a0

void FUN_100241a0(void)

{
  thunk_FUN_1001b390(&DAT_10033f74,L"DA");
  _atexit(FUN_10025d50);
  return;
}



// Function: FUN_100241d0 at 100241d0

void FUN_100241d0(void)

{
  thunk_FUN_1001b390(&DAT_10033fac,L"NL");
  _atexit(FUN_10025db0);
  return;
}



// Function: FUN_10024200 at 10024200

void FUN_10024200(void)

{
  thunk_FUN_1001b390(&DAT_10034074,L"FI");
  _atexit(FUN_10025e10);
  return;
}



// Function: FUN_10024230 at 10024230

void FUN_10024230(void)

{
  thunk_FUN_1001b390(&DAT_1003411c,L"NO");
  _atexit(FUN_10025e70);
  return;
}



// Function: FUN_10024260 at 10024260

void FUN_10024260(void)

{
  thunk_FUN_1001b390(&DAT_10033f90,L"SV");
  _atexit(FUN_10025ed0);
  return;
}



// Function: FUN_10024290 at 10024290

void FUN_10024290(void)

{
  thunk_FUN_1001b390(&DAT_10033fc8,L"ID");
  _atexit(FUN_10025f30);
  return;
}



// Function: FUN_100242c0 at 100242c0

/* WARNING: Removing unreachable block (ram,0x100242cc) */

void FUN_100242c0(void)

{
  DAT_1003401c = Ordinal_2(&DAT_10029d98);
  if (DAT_1003401c == 0) {
    thunk_FUN_10004720(0x8007000e);
  }
  _atexit(FUN_10025f90);
  return;
}



// Function: FUN_10024330 at 10024330

/* WARNING: Removing unreachable block (ram,0x1002433c) */

void FUN_10024330(void)

{
  DAT_10034138 = Ordinal_2(&DAT_10029da0);
  if (DAT_10034138 == 0) {
    thunk_FUN_10004720(0x8007000e);
  }
  _atexit(FUN_10025fb0);
  return;
}



// Function: FUN_100243a0 at 100243a0

/* WARNING: Removing unreachable block (ram,0x100243ac) */

void FUN_100243a0(void)

{
  DAT_1003413c = Ordinal_2(&DAT_10029da8);
  if (DAT_1003413c == 0) {
    thunk_FUN_10004720(0x8007000e);
  }
  _atexit(FUN_10025fd0);
  return;
}



// Function: FUN_10025470 at 10025470

void FUN_10025470(void)

{
  if (DAT_10033e38 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e38);
    DAT_10033e38 = (void *)0x0;
  }
  return;
}



// Function: FUN_100254b0 at 100254b0

void FUN_100254b0(void)

{
  if (DAT_10033e3c != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e3c);
    DAT_10033e3c = (void *)0x0;
  }
  return;
}



// Function: FUN_100254f0 at 100254f0

void FUN_100254f0(void)

{
  if (DAT_10033e40 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e40);
    DAT_10033e40 = (void *)0x0;
  }
  return;
}



// Function: FUN_10025530 at 10025530

void FUN_10025530(void)

{
  if (DAT_10033e44 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e44);
    DAT_10033e44 = (void *)0x0;
  }
  return;
}



// Function: FUN_10025570 at 10025570

void FUN_10025570(void)

{
  if (DAT_10033e2c != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e2c);
    DAT_10033e2c = (void *)0x0;
  }
  return;
}



// Function: FUN_100255b0 at 100255b0

void FUN_100255b0(void)

{
  if (DAT_10033e30 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e30);
    DAT_10033e30 = (void *)0x0;
  }
  return;
}



// Function: FUN_100255f0 at 100255f0

void FUN_100255f0(void)

{
  if (DAT_10033e84 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e84);
    DAT_10033e84 = (void *)0x0;
  }
  return;
}



// Function: FUN_10025630 at 10025630

void FUN_10025630(void)

{
  if (DAT_10033e88 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e88);
    DAT_10033e88 = (void *)0x0;
  }
  return;
}



// Function: FUN_10025670 at 10025670

void FUN_10025670(void)

{
  if (DAT_10033e8c != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e8c);
    DAT_10033e8c = (void *)0x0;
  }
  return;
}



// Function: FUN_100256b0 at 100256b0

void FUN_100256b0(void)

{
  if (DAT_10033e90 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033e90);
    DAT_10033e90 = (void *)0x0;
  }
  return;
}



// Function: FUN_100256f0 at 100256f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100256f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10021c38;
  local_10 = ExceptionList;
  _DAT_10033e94 = ATL::CComModule::vftable;
  local_8 = 2;
  ExceptionList = &local_10;
  thunk_FUN_1000f370(0x10033e94);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025770 at 10025770

void FUN_10025770(void)

{
  if (DAT_10033ed0 != (void *)0x0) {
    thunk_FUN_10008d20(DAT_10033ed0);
    DAT_10033ed0 = (void *)0x0;
  }
  return;
}



// Function: FUN_100257b0 at 100257b0

void FUN_100257b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002284a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f20,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025810 at 10025810

void FUN_10025810(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002286a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f04,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025870 at 10025870

void FUN_10025870(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002288a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033ee8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100258d0 at 100258d0

void FUN_100258d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100228aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_100340ac,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025930 at 10025930

void FUN_10025930(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100228ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034000,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025990 at 10025990

void FUN_10025990(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100228ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034100,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100259f0 at 100259f0

void FUN_100259f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002290a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f3c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025a50 at 10025a50

void FUN_10025a50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002292a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034058,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025ab0 at 10025ab0

void FUN_10025ab0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002294a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_100340c8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025b10 at 10025b10

void FUN_10025b10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002296a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034090,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025b70 at 10025b70

void FUN_10025b70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002298a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_100340e4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025bd0 at 10025bd0

void FUN_10025bd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100229aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034020,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025c30 at 10025c30

void FUN_10025c30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100229ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033fe4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025c90 at 10025c90

void FUN_10025c90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100229ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f58,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025cf0 at 10025cf0

void FUN_10025cf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a0a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_1003403c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025d50 at 10025d50

void FUN_10025d50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f74,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025db0 at 10025db0

void FUN_10025db0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033fac,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025e10 at 10025e10

void FUN_10025e10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10034074,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025e70 at 10025e70

void FUN_10025e70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_1003411c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025ed0 at 10025ed0

void FUN_10025ed0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022aaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033f90,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025f30 at 10025f30

void FUN_10025f30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022aca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  thunk_FUN_1001c2a0(&DAT_10033fc8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025f90 at 10025f90

void FUN_10025f90(void)

{
  Ordinal_6(DAT_1003401c);
  return;
}



// Function: FUN_10025fb0 at 10025fb0

void FUN_10025fb0(void)

{
  Ordinal_6(DAT_10034138);
  return;
}



// Function: FUN_10025fd0 at 10025fd0

void FUN_10025fd0(void)

{
  Ordinal_6(DAT_1003413c);
  return;
}



