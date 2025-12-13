/*
 * Decompiled from: SFDataLoaders.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000111b) */
/* WARNING: Removing unreachable block (ram,0x10001089) */
/* WARNING: Removing unreachable block (ram,0x1000127c) */
/* WARNING: Removing unreachable block (ram,0x10001323) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10001000(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *extraout_EDX;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *local_160 [4];
  undefined4 local_150;
  int *local_14c;
  undefined4 local_148;
  int *local_144;
  int *local_140;
  undefined4 local_13c;
  int *local_138;
  undefined4 local_134;
  int local_130;
  int *local_12c;
  undefined4 *local_128;
  int *local_120;
  int local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int *local_104;
  int *local_100;
  int *local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int *local_ec;
  int *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  int *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  int *local_c8;
  int local_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  int local_b0;
  undefined1 *local_ac;
  int *local_a4 [3];
  int *local_98;
  int local_8c [3];
  int local_80 [3];
  int local_74 [5];
  int *local_60;
  int *local_54;
  int local_48 [3];
  int local_3c [5];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_e0 = (uint)local_e0._2_2_ << 0x10;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d439;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_160;
  for (iVar2 = 0x53; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffe94;
  FUN_10002600(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_1001a120(local_3c);
  local_8._0_1_ = 2;
  FUN_1001a220(local_3c,extraout_EDX,param_2);
  local_48[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar7 = local_48;
  local_ac = &stack0xfffffe8c;
  local_e8 = (int *)&stack0xfffffe8c;
  iVar2 = Ordinal_2();
  iVar6 = 0x100010ab;
  *local_e8 = iVar2;
  if (*local_e8 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_138 = local_e8;
  local_8._0_1_ = 3;
  uVar4 = FUN_1001b1b0(iVar6,piVar7);
  local_13c = (undefined4)uVar4;
  FUN_10002680(local_28,local_13c);
  local_54 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,6);
  local_b0 = Ordinal_2();
  if (local_b0 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_ec = &local_b0;
  local_8._0_1_ = 7;
  local_f0 = local_b0;
  uVar1 = (**(code **)(*param_2 + 0x90))();
  FUN_10002680(local_28,uVar1);
  local_8._0_1_ = 6;
  Ordinal_6();
  local_60 = (int *)0x0;
  local_8._0_1_ = 9;
  while( true ) {
    local_140 = local_54;
    uVar1 = (**(code **)(*local_54 + 0x24))();
    local_f4 = FUN_10002680(local_28,uVar1);
    local_f8 = *(int *)(local_f4 + 0xc);
    if (local_f8 != 0) break;
    FUN_1001a120(local_74);
    local_8._0_1_ = 10;
    local_fc = local_60;
    uVar4 = FUN_1001a220(local_74,local_60,local_60);
    FUN_10002680(local_28,(int)uVar4);
    local_80[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    piVar7 = local_80;
    local_b4 = &stack0xfffffe68;
    local_100 = (int *)&stack0xfffffe68;
    iVar2 = Ordinal_2(L"dsComparisonID");
    iVar6 = 0x1000129e;
    *local_100 = iVar2;
    if (*local_100 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_144 = local_100;
    local_8._0_1_ = 0xb;
    uVar4 = FUN_1001b1b0(iVar6,piVar7);
    local_148 = (undefined4)uVar4;
    FUN_10002680(local_28,local_148);
    local_8c[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0xd);
    piVar7 = local_8c;
    local_104 = (int *)&stack0xfffffe68;
    local_b8 = &stack0xfffffe68;
    iVar2 = Ordinal_2(L"dsMessageID");
    iVar6 = 0x10001345;
    *local_104 = iVar2;
    if (*local_104 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_14c = local_104;
    local_8._0_1_ = 0xd;
    uVar4 = FUN_1001b1b0(iVar6,piVar7);
    local_150 = (undefined4)uVar4;
    FUN_10002680(local_28,local_150);
    FUN_100019d0(&local_c0,local_8c);
    local_114 = &local_c0;
    local_8._0_1_ = 0x10;
    FUN_100019d0(&local_bc,local_80);
    local_160[3] = &local_bc;
    local_8 = CONCAT31(local_8._1_3_,0x12);
    uVar4 = FUN_10002140((void *)(param_1 + 0x2c),local_160[3]);
    local_110 = (int *)uVar4;
    if (local_110 != local_114) {
      FUN_10001a30(local_110,local_114);
    }
    local_8._0_1_ = 0x10;
    Ordinal_6();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    Ordinal_6(local_c0);
    piVar7 = local_60;
    uVar1 = 0x10001462;
    local_118 = local_60;
    if (local_60 != (int *)0x0) {
      local_60 = (int *)0x0;
      (**(code **)(*piVar7 + 8))(piVar7,0x10001462);
      uVar1 = 0x10001498;
    }
    local_8._0_1_ = 0xb;
    Ordinal_6(local_8c[0],uVar1);
    local_8._0_1_ = 10;
    Ordinal_6(local_80[0],0x100014b2);
    local_8._0_1_ = 9;
    FUN_1001a190(local_74);
  }
  local_98 = (int *)0x0;
  local_8._0_1_ = 0x16;
  local_120 = (int *)(param_1 + 0x28);
  if ((int *)*local_120 == param_3) {
    local_11c = *local_120;
  }
  else {
    FUN_10001960(local_120,param_3);
  }
  local_160[2] = *(int **)(param_1 + 0x28);
  uVar1 = (**(code **)(*local_160[2] + 0x3c))();
  uVar5 = 0x10001575;
  FUN_10002680(local_28,uVar1);
  local_128 = (undefined4 *)(**(code **)(*(int *)(param_1 + -4) + 0x14))(uVar5);
  uVar1 = 0x10001598;
  FUN_100023d0(local_a4);
  local_8._0_1_ = 0x17;
  if (local_128 != (undefined4 *)0x0) {
    (**(code **)*local_128)(local_128,&DAT_10026560,local_a4,uVar1);
    uVar1 = 0x100015de;
  }
  local_8._0_1_ = 0x18;
  local_12c = local_a4[0];
  local_e0 = CONCAT22(local_e0._2_2_,0xd);
  local_d8 = local_a4[0];
  if (local_a4[0] != (int *)0x0) {
    (**(code **)(*local_a4[0] + 4))(local_a4[0],uVar1);
    uVar1 = 0x1000162c;
  }
  local_160[1] = &local_e0;
  local_8._0_1_ = 0x19;
  local_d0 = local_e0;
  local_c8 = local_d8;
  local_160[0] = local_98;
  local_130 = local_48[0];
  uVar1 = (**(code **)(*local_98 + 0x28))
                    (local_98,local_48[0],local_e0,local_dc,local_d8,local_d4,uVar1);
  uVar5 = 0x100016c6;
  FUN_10002680(local_28,uVar1);
  local_8._0_1_ = 0x18;
  local_134 = Ordinal_9(&local_e0,uVar5);
  uVar1 = 0x100016e9;
  local_8._0_1_ = 0x16;
  if (local_a4[0] != (int *)0x0) {
    (**(code **)(*local_a4[0] + 8))(local_a4[0],0x100016e9);
    uVar1 = 0x10001721;
  }
  local_8._0_1_ = 9;
  if (local_98 != (int *)0x0) {
    (**(code **)(*local_98 + 8))(local_98,uVar1);
    uVar1 = 0x1000174f;
  }
  local_8._0_1_ = 6;
  if (local_60 != (int *)0x0) {
    (**(code **)(*local_60 + 8))(local_60,uVar1);
    uVar1 = 0x10001774;
  }
  local_8._0_1_ = 3;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54,uVar1);
    uVar1 = 0x10001799;
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_48[0],uVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1001a190(local_3c);
  uVar4 = FUN_100017cb();
  return uVar4;
}



// Function: Catch@100017be at 100017be

undefined4 Catch_100017be(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100017d2;
}



// Function: FUN_100017cb at 100017cb

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100017cb(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0xe0) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xe0);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10001824);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10001920 at 10001920

void FUN_10001920(undefined4 param_1)

{
  undefined4 local_8;
  
  local_8 = param_1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10029b08);
}



// Function: FUN_10001960 at 10001960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * FUN_10001960(int *param_1,int *param_2)

{
  if (param_1 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    if (*param_1 != 0) {
      (**(code **)(*(int *)*param_1 + 8))(*param_1);
    }
    *param_1 = (int)param_2;
  }
  return param_2;
}



// Function: FUN_100019d0 at 100019d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_100019d0(void *this,int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001a90(param_1);
  *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
  if ((*param_1 != 0) && (*this == 0)) {
    FUN_10001920(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_10001a30 at 10001a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10001a30(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_10001a90 at 10001a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10001a90(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    uVar1 = Ordinal_150(0,0);
  }
  else {
    uVar1 = Ordinal_149(*param_1);
    uVar1 = Ordinal_150(*param_1,uVar1,0x10001ad4);
  }
  return uVar1;
}



// Function: FUN_10001b10 at 10001b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001b10(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001b50 at 10001b50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001b50(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10001b90 at 10001b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001b90(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d458;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  Ordinal_6(*param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001bf0 at 10001bf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001bf0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fbc0;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001c70 at 10001c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10001c70(int param_1,short *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_a8 [4];
  undefined4 local_98;
  undefined4 *local_94;
  undefined4 local_90;
  undefined4 *local_8c;
  int local_88;
  int local_84;
  int *local_80;
  undefined4 *local_7c;
  int local_70;
  int local_6c;
  int *local_64 [3];
  undefined1 local_58 [8];
  undefined4 *local_50;
  int local_40 [3];
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d4d0;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_a8;
  for (iVar2 = 0x25; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff4c;
  FUN_10002600(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_2 == (short *)0x0) {
    FUN_10002680(local_28,0x80004003);
  }
  local_34[0] = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  local_a8[2] = *(int **)(param_1 + 0x2c);
  uVar1 = (**(code **)(*local_a8[2] + 0x3c))(local_a8[2],local_34);
  uVar5 = 0x10001d12;
  FUN_10002680(local_28,uVar1);
  local_40[0] = 0;
  *param_2 = -1;
  local_7c = (undefined4 *)(param_1 + 0x28);
  Ordinal_6(*local_7c,uVar5);
  uVar1 = 0x10001d49;
  *local_7c = 0;
  local_80 = *(int **)(param_1 + 0x34);
  local_84 = *local_80;
  local_6c = local_84;
  local_40[0] = local_84;
  while( true ) {
    local_88 = *(int *)(param_1 + 0x34);
    local_70 = local_88;
    if ((local_40[0] == local_88) || (*param_2 != -1)) goto LAB_10001f54;
    Ordinal_8(local_58,uVar1);
    local_8._0_1_ = 4;
    local_a8[1] = local_34[0];
    local_8c = (undefined4 *)(local_40[0] + 0xc);
    local_90 = *local_8c;
    uVar1 = (**(code **)(*local_34[0] + 0x24))(local_34[0],local_90,local_58,0x10001dd0);
    uVar5 = 0x10001e1f;
    FUN_10002680(local_28,uVar1);
    local_94 = local_50;
    local_64[0] = (int *)0x0;
    local_8._0_1_ = 6;
    if (local_50 != (undefined4 *)0x0) {
      (**(code **)*local_50)(local_50,&DAT_100265cc,local_64,uVar5);
      uVar5 = 0x10001e6e;
    }
    local_8._0_1_ = 7;
    local_a8[0] = local_64[0];
    uVar1 = (**(code **)(*local_64[0] + 0xc))(local_64[0],param_2,uVar5);
    uVar5 = 0x10001e9c;
    FUN_10002680(local_28,uVar1);
    if (*param_2 == 0) break;
    local_8._0_1_ = 4;
    if (local_64[0] != (int *)0x0) {
      (**(code **)(*local_64[0] + 8))(local_64[0],uVar5);
      uVar5 = 0x10001f32;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_a8[3] = (int *)Ordinal_9(local_58,uVar5);
    uVar1 = 0x10001f49;
    FUN_100024d0(local_40);
  }
  FUN_10002050((void *)(param_1 + 0x28),(int *)(local_40[0] + 0x10));
  local_8._0_1_ = 4;
  if (local_64[0] != (int *)0x0) {
    (**(code **)(*local_64[0] + 8))(local_64[0]);
    uVar5 = 0x10001eea;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  local_98 = Ordinal_9(local_58,uVar5);
  uVar1 = 0x10001f01;
LAB_10001f54:
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))(local_34[0],uVar1);
  }
  uVar4 = FUN_10001f88();
  return uVar4;
}



// Function: Catch@10001f7b at 10001f7b

undefined4 Catch_10001f7b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10001f8f;
}



// Function: FUN_10001f88 at 10001f88

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10001f88(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x70);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10001fd8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10002050 at 10002050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10002050(void *this,int *param_1)

{
  undefined4 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    uVar1 = FUN_10001a90(param_1);
    *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
    if ((*param_1 != 0) && (*this == 0)) {
      FUN_10001920(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_100020d0 at 100020d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100020d0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    iVar1 = FUN_10001a90((int *)(param_1 + 0x28));
    *param_2 = iVar1;
    if ((*param_2 == 0) && (*(int *)(param_1 + 0x28) != 0)) {
      local_c = 0x8007000e;
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10002140 at 10002140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10002140(void *this,undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 **ppuVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined4 *local_50 [4];
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 *local_24;
  undefined4 *local_1c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d548;
  local_10 = ExceptionList;
  ppuVar4 = local_50;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  ExceptionList = &local_10;
  local_14 = this;
  local_3c = FUN_10002430(this,param_1);
  local_40 = *(undefined4 **)((int)local_14 + 4);
  local_24 = local_40;
  local_1c = local_3c;
  if (local_3c != local_40) {
    local_50[3] = local_3c;
    uVar5 = Ordinal_314(*param_1,local_3c[3],0x400,0);
    uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) goto LAB_100022c9;
  }
  local_34 = local_1c;
  local_30 = 0;
  local_50[2] = &local_30;
  local_2c = *param_1;
  *param_1 = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  FUN_10002590(&local_28,local_50[2]);
  local_50[1] = &local_2c;
  local_8._0_1_ = 6;
  piVar1 = (int *)FUN_10004550(local_14,local_50[1]);
  FUN_10002740(local_14,&local_38,local_34,piVar1);
  local_1c = local_38;
  local_50[0] = &local_28;
  local_8._0_1_ = 8;
  Ordinal_6(local_28);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_2c,0x1000228d);
  local_8 = 0xffffffff;
  Ordinal_6(local_30,0x100022a8);
  uVar3 = extraout_EDX;
LAB_100022c9:
  puVar6 = local_1c + 4;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_100022fc);
  ExceptionList = local_10;
  return CONCAT44(uVar3,puVar6);
}



// Function: FUN_10002320 at 10002320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10002320(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d58b;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  Ordinal_6(param_1[1]);
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,0x10002385);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100023d0 at 100023d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100023d0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002430 at 10002430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10002430(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *local_10;
  undefined4 *local_c;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_10 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x15) == '\0') {
    iVar1 = Ordinal_314(local_c[3],*param_1,0x400,0);
    if (iVar1 == 0) {
      local_c = (undefined4 *)local_c[2];
    }
    else {
      local_10 = local_c;
      local_c = (undefined4 *)*local_c;
    }
  }
  return local_10;
}



// Function: FUN_100024d0 at 100024d0

int * __fastcall FUN_100024d0(int *param_1)

{
  int iVar1;
  int *local_18;
  
  if (*(char *)(*param_1 + 0x15) == '\0') {
    if (*(char *)(*(int *)(*param_1 + 8) + 0x15) == '\0') {
      for (local_18 = *(int **)(*param_1 + 8); *(char *)(*local_18 + 0x15) == '\0';
          local_18 = (int *)*local_18) {
      }
      *param_1 = (int)local_18;
    }
    else {
      while ((iVar1 = *(int *)(*param_1 + 4), *(char *)(iVar1 + 0x15) == '\0' &&
             (*param_1 == *(int *)(iVar1 + 8)))) {
        *param_1 = iVar1;
      }
      *param_1 = iVar1;
    }
  }
  return param_1;
}



// Function: FUN_10002590 at 10002590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10002590(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *param_1 = 0;
  return (undefined4 *)this;
}



// Function: FUN_10002600 at 10002600

undefined4 * __fastcall FUN_10002600(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return param_1;
}



// Function: FID_conflict:~CRectTracker at 10002660

/* Library Function - Multiple Matches With Different Base Names
    protected: virtual __thiscall CDialogImpl::~CDialogImpl(void)
    public: virtual __thiscall ATL::CFixedStringMgr::~CFixedStringMgr(void)
    public: virtual __thiscall CGlobalUtils::~CGlobalUtils(void)
    public: virtual __thiscall CMFCControlBarImpl::~CMFCControlBarImpl(void)
     15 names - too many to list
   
   Library: Visual Studio 2012 Debug */

void __fastcall FID_conflict__CRectTracker(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10002680 at 10002680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10002680(void *this,undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int local_40;
  char *local_3c;
  void *local_8;
  
  piVar2 = &local_40;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  *(undefined4 *)((int)this + 0xc) = param_1;
  local_40 = *(int *)((int)this + 0xc);
  local_3c = (char *)((int)this + 4);
  local_8 = this;
  if ((*local_3c == '\0') && (local_40 < 0)) {
    *local_3c = '\x01';
    FUN_100035c0(local_40,*(undefined4 *)((int)this + 8));
  }
  return (int)local_8;
}



// Function: FID_conflict:`scalar_deleting_destructor' at 10002700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    protected: virtual void * __thiscall CDialogImpl::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall ATL::CFixedStringMgr::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall CGlobalUtils::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall CMFCControlBarImpl::`scalar deleting destructor'(unsigned int)
     15 names - too many to list
   
   Library: Visual Studio 2012 Debug */

undefined4 * __thiscall FID_conflict__scalar_deleting_destructor_(void *this,uint param_1)

{
  FID_conflict__CRectTracker((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002740 at 10002740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100027b2) */
/* WARNING: Removing unreachable block (ram,0x10002839) */
/* WARNING: Removing unreachable block (ram,0x100028dc) */
/* WARNING: Removing unreachable block (ram,0x10002913) */
/* WARNING: Removing unreachable block (ram,0x10002954) */
/* WARNING: Removing unreachable block (ram,0x1000298e) */
/* WARNING: Removing unreachable block (ram,0x1000296e) */
/* WARNING: Removing unreachable block (ram,0x100029b1) */
/* WARNING: Removing unreachable block (ram,0x100029e8) */
/* WARNING: Removing unreachable block (ram,0x10002a27) */
/* WARNING: Removing unreachable block (ram,0x10002a5a) */
/* WARNING: Removing unreachable block (ram,0x10002a94) */
/* WARNING: Removing unreachable block (ram,0x10002a74) */
/* WARNING: Removing unreachable block (ram,0x10002ab4) */
/* WARNING: Removing unreachable block (ram,0x1000286a) */
/* WARNING: Removing unreachable block (ram,0x100028b3) */
/* WARNING: Removing unreachable block (ram,0x100028d7) */
/* WARNING: Removing unreachable block (ram,0x100027e5) */
/* WARNING: Removing unreachable block (ram,0x10002812) */
/* WARNING: Removing unreachable block (ram,0x10002830) */
/* WARNING: Removing unreachable block (ram,0x10002ab8) */

undefined8 __thiscall FUN_10002740(void *this,undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined8 uVar4;
  undefined4 *local_150 [4];
  undefined4 *local_140;
  undefined4 *local_13c;
  undefined4 *local_138;
  undefined4 *local_134;
  int *local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 local_124;
  undefined4 *local_120;
  int local_40;
  int local_3c [2];
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c [4];
  char local_19;
  undefined4 *local_14 [2];
  int *local_c;
  void *local_8;
  
  ppuVar3 = local_150;
  for (iVar1 = 0x53; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  local_c = param_3 + 3;
  local_14[0] = (undefined4 *)0x0;
  local_19 = '\0';
  local_40 = *(int *)((int)this + 8);
  local_8 = this;
  if (local_40 == 0) {
    FUN_10003140(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    uVar2 = extraout_EDX;
    goto LAB_10002de4;
  }
  local_120 = *(undefined4 **)((int)this + 4);
  local_124 = *local_120;
  FUN_10002e30(local_2c,local_124);
  if (param_2 == local_2c[0]) {
    local_128 = param_2;
    iVar1 = Ordinal_314(*local_c,param_2[3],0x400,0);
    if (iVar1 == 0) {
      FUN_10003140(local_8,param_1,'\x01',param_2,param_3);
      uVar2 = extraout_EDX_00;
      goto LAB_10002de4;
    }
  }
  else {
    local_12c = *(undefined4 *)((int)local_8 + 4);
    FUN_10002e30(&local_30,local_12c);
    if (param_2 == local_30) {
      local_130 = (int *)(*(int *)((int)local_8 + 4) + 8);
      local_134 = (undefined4 *)(*local_130 + 0xc);
      iVar1 = Ordinal_314(*local_134,*local_c,0x400,0);
      if (iVar1 == 0) {
        FUN_10003140(local_8,param_1,'\0',*(undefined4 **)(*(int *)((int)local_8 + 4) + 8),param_3);
        uVar2 = extraout_EDX_01;
        goto LAB_10002de4;
      }
    }
    else {
      local_138 = param_2;
      iVar1 = Ordinal_314(*local_c,param_2[3],0x400,0);
      if (iVar1 == 0) {
        local_14[0] = param_2;
        FUN_10004480((int *)local_14);
        local_13c = local_14[0];
        iVar1 = Ordinal_314(local_14[0][3],*local_c,0x400,0);
        if (iVar1 == 0) {
          local_140 = local_14[0];
          if (*(char *)(local_14[0][2] + 0x15) == '\0') {
            FUN_10003140(local_8,param_1,'\x01',param_2,param_3);
            uVar2 = extraout_EDX_03;
          }
          else {
            FUN_10003140(local_8,param_1,'\0',local_14[0],param_3);
            uVar2 = extraout_EDX_02;
          }
          goto LAB_10002de4;
        }
      }
      local_150[3] = param_2;
      iVar1 = Ordinal_314(param_2[3],*local_c,0x400,0);
      if (iVar1 == 0) {
        local_14[0] = param_2;
        local_150[2] = *(undefined4 **)((int)local_8 + 4);
        FUN_10002e30(&local_34,local_150[2]);
        FUN_100024d0((int *)local_14);
        if (local_14[0] != local_34) {
          local_150[1] = local_14[0];
          iVar1 = Ordinal_314(*local_c,local_14[0][3],0x400,0);
          if (iVar1 != 0) goto LAB_10002dc5;
        }
        local_150[0] = param_2;
        if (*(char *)(param_2[2] + 0x15) == '\0') {
          FUN_10003140(local_8,param_1,'\x01',local_14[0],param_3);
          uVar2 = extraout_EDX_05;
        }
        else {
          FUN_10003140(local_8,param_1,'\0',param_2,param_3);
          uVar2 = extraout_EDX_04;
        }
        goto LAB_10002de4;
      }
    }
  }
LAB_10002dc5:
  uVar4 = FUN_10002e50(local_8,local_3c,param_3,local_19);
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  *param_1 = *(undefined4 *)uVar4;
LAB_10002de4:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10002e0c);
  return CONCAT44(uVar2,param_1);
}



// Function: FUN_10002e30 at 10002e30

undefined4 * __thiscall FUN_10002e30(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10002e50 at 10002e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10002f35) */

undefined8 __thiscall FUN_10002e50(void *this,int *param_1,int *param_2,char param_3)

{
  int iVar1;
  int **ppiVar2;
  bool bVar3;
  int *piVar4;
  int *local_98 [2];
  int local_90;
  int *local_8c;
  undefined4 local_88;
  undefined4 *local_84;
  undefined1 local_41;
  undefined4 local_40;
  undefined1 local_39;
  undefined4 local_38;
  undefined1 local_31;
  int local_30 [4];
  int local_20 [2];
  char local_15;
  int *local_14;
  int *local_10;
  int *local_c;
  void *local_8;
  
  ppiVar2 = local_98;
  for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = param_2 + 3;
  local_10 = *(int **)(*(int *)((int)this + 4) + 4);
  local_14 = *(int **)((int)this + 4);
  local_15 = '\x01';
  local_8 = this;
  while (*(char *)((int)local_10 + 0x15) == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      iVar1 = Ordinal_314(*local_c,local_10[3],0x400,0);
      bVar3 = iVar1 != 0;
    }
    else {
      iVar1 = Ordinal_314(local_10[3],*local_c,0x400,0);
      bVar3 = iVar1 == 0;
    }
    local_15 = '\x01' - bVar3;
    if (local_15 == '\0') {
      local_98[0] = (int *)local_10[2];
    }
    else {
      local_98[0] = (int *)*local_10;
    }
    local_10 = local_98[0];
  }
  FUN_10002e30(local_20,local_14);
  if (local_15 != '\0') {
    local_84 = *(undefined4 **)((int)local_8 + 4);
    local_88 = *local_84;
    FUN_10002e30(local_30,local_88);
    if (local_20[0] == local_30[0]) {
      local_31 = 1;
      local_8c = FUN_10003140(local_8,&local_38,'\x01',local_14,param_2);
      *param_1 = *local_8c;
      *(undefined1 *)(param_1 + 1) = local_31;
      goto LAB_100030c0;
    }
    FUN_10004480(local_20);
  }
  local_90 = local_20[0];
  iVar1 = Ordinal_314(*(undefined4 *)(local_20[0] + 0xc),*local_c,0x400,0);
  if (iVar1 == 0) {
    local_39 = 1;
    local_98[1] = FUN_10003140(local_8,&local_40,local_15,local_14,param_2);
    *param_1 = *local_98[1];
    *(undefined1 *)(param_1 + 1) = local_39;
  }
  else {
    FUN_10003110((int)local_8 + 0xd,param_2 + 3);
    operator_delete(param_2);
    local_41 = 0;
    *param_1 = local_20[0];
    *(undefined1 *)(param_1 + 1) = 0;
  }
LAB_100030c0:
  piVar4 = param_1;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100030e8);
  return CONCAT44(piVar4,param_1);
}



// Function: FUN_10003110 at 10003110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10003110(undefined4 param_1,undefined4 *param_2)

{
  FUN_10004600(param_2);
  return;
}



// Function: FUN_10003140 at 10003140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10003171) */

undefined4 * __thiscall
FUN_10003140(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [4];
  int *local_54;
  int *local_4c;
  int *local_48;
  int *local_44;
  undefined4 *local_40;
  int *local_38;
  int *local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int *local_c;
  void *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0x1fffffff;
  local_64[0] = 0x1fffffff;
  local_8 = this;
  if (0x1ffffffd < *(uint *)((int)this + 8)) {
    FUN_10003110((int)this + 0xd,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)local_8 + 8) = *(int *)((int)local_8 + 8) + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)((int)local_8 + 4)) {
    *(int **)(*(int *)((int)local_8 + 4) + 4) = param_4;
    local_14 = *(undefined4 **)((int)local_8 + 4);
    *local_14 = param_4;
    *(int **)(*(int *)((int)local_8 + 4) + 8) = param_4;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_4;
    if (param_3 == *(undefined4 **)(*(int *)((int)local_8 + 4) + 8)) {
      *(int **)(*(int *)((int)local_8 + 4) + 8) = param_4;
    }
  }
  else {
    *param_3 = param_4;
    local_18 = *(int **)((int)local_8 + 4);
    if (param_3 == (undefined4 *)*local_18) {
      local_1c = *(undefined4 **)((int)local_8 + 4);
      *local_1c = param_4;
    }
  }
  local_c = param_4;
  while (*(char *)(local_c[1] + 0x14) == '\0') {
    local_20 = (undefined4 *)(local_c[1] + 4);
    local_24 = (int *)*local_20;
    if (local_c[1] == *local_24) {
      local_28 = (int *)(local_c[1] + 4);
      iVar1 = *(int *)(*local_28 + 8);
      if (*(char *)(iVar1 + 0x14) == '\0') {
        *(undefined1 *)(local_c[1] + 0x14) = 1;
        *(undefined1 *)(iVar1 + 0x14) = 1;
        local_2c = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_2c + 0x14) = 0;
        local_c = *(int **)(local_c[1] + 4);
      }
      else {
        if (local_c == *(int **)(local_c[1] + 8)) {
          local_c = (int *)local_c[1];
          FUN_10003440(local_8,(int)local_c);
        }
        *(undefined1 *)(local_c[1] + 0x14) = 1;
        local_38 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_38 + 0x14) = 0;
        FUN_10003500(local_8,*(int **)(local_c[1] + 4));
      }
    }
    else {
      local_40 = (undefined4 *)(local_c[1] + 4);
      local_44 = (int *)*local_40;
      iVar1 = *local_44;
      if (*(char *)(iVar1 + 0x14) == '\0') {
        *(undefined1 *)(local_c[1] + 0x14) = 1;
        *(undefined1 *)(iVar1 + 0x14) = 1;
        local_48 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_48 + 0x14) = 0;
        local_c = *(int **)(local_c[1] + 4);
      }
      else {
        local_4c = (int *)local_c[1];
        if (local_c == (int *)*local_4c) {
          local_c = (int *)local_c[1];
          FUN_10003500(local_8,local_c);
        }
        *(undefined1 *)(local_c[1] + 0x14) = 1;
        local_54 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_54 + 0x14) = 0;
        FUN_10003440(local_8,*(int *)(local_c[1] + 4));
      }
    }
  }
  *(undefined1 *)(*(int *)(*(int *)((int)local_8 + 4) + 4) + 0x14) = 1;
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_10003440 at 10003440

void __thiscall FUN_10003440(void *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 4) + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar1;
  }
  else if (param_1 == **(int **)(param_1 + 4)) {
    **(int **)(param_1 + 4) = (int)piVar1;
  }
  else {
    *(int **)(*(int *)(param_1 + 4) + 8) = piVar1;
  }
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// Function: FUN_10003500 at 10003500

void __thiscall FUN_10003500(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x15) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 4) + 4)) {
    *(int *)(*(int *)((int)this + 4) + 4) = iVar1;
  }
  else if (param_1 == *(int **)(param_1[1] + 8)) {
    *(int *)(param_1[1] + 8) = iVar1;
  }
  else {
    *(int *)param_1[1] = iVar1;
  }
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// Function: FUN_100035c0 at 100035c0

void FUN_100035c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_bc [17];
  undefined1 local_78 [52];
  undefined1 local_44 [52];
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d5db;
  pvStack_10 = ExceptionList;
  puVar2 = local_bc;
  for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &pvStack_10;
  FUN_100036c0(local_44,param_1,0,param_2,(wchar_t *)&PTR_10026604,0);
  local_8 = 0;
  FUN_100043a0(local_78,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_78,(ThrowInfo *)&DAT_10029d24);
}



// Function: FUN_100036c0 at 100036c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall
FUN_100036c0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
            undefined4 param_5)

{
  int iVar1;
  void **ppvVar2;
  void *local_44 [6];
  size_t local_2c;
  void *local_28;
  undefined1 local_19;
  undefined1 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d603;
  local_10 = ExceptionList;
  ppvVar2 = local_44;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_44[0] = (void *)((int)this + 0x10);
  local_18 = &local_19;
  local_8 = 0;
  local_28 = local_44[0];
  local_14 = (undefined4 *)this;
  FUN_10003930(local_44[0],'\0',0);
  local_8 = 1;
  local_14[1] = param_1;
  local_14[2] = param_2;
  local_14[3] = param_3;
  local_2c = wcslen(param_4);
  FUN_100039f0(local_14 + 4,(undefined4 *)param_4,local_2c);
  local_14[0xb] = param_5;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100037a0 at 100037a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100037a0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d623;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003930(param_1 + 4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003830 at 10003830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003830(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d623;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003930((void *)((int)this + 0x10),'\x01',0);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100038d0 at 100038d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100038d0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f4a8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003930 at 10003930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10003930(void *this,char param_1,int param_2)

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



// Function: FUN_100039f0 at 100039f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100039f0(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  void *local_34 [5];
  undefined4 *local_20;
  char local_9;
  undefined4 *local_8;
  
  ppvVar3 = local_34;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    local_34[3] = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_34[3] = *this;
    }
    if (local_34[3] <= param_1) {
      local_34[2] = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_34[2] = *this;
      }
      if (param_1 < (undefined4 *)((int)local_34[2] + *(int *)((int)this + 0x10) * 2)) {
        local_9 = '\x01';
        goto LAB_10003a68;
      }
    }
  }
  local_9 = '\0';
LAB_10003a68:
  local_8 = (undefined4 *)this;
  if (local_9 == '\0') {
    bVar1 = FUN_10003dc0(this,param_2,'\0');
    if (bVar1) {
      if ((uint)local_8[5] < 8) {
        local_20 = local_8;
      }
      else {
        local_20 = (undefined4 *)*local_8;
      }
      memcpy(local_20,param_1,param_2 << 1);
      local_8[4] = param_2;
      if ((uint)local_8[5] < 8) {
        local_34[0] = local_8;
      }
      else {
        local_34[0] = (void *)*local_8;
      }
      *(undefined2 *)((int)local_34[0] + param_2 * 2) = 0;
    }
  }
  else {
    local_34[1] = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_34[1] = *this;
    }
    local_8 = FUN_10003b40(this,(undefined4 *)this,(int)param_1 - (int)local_34[1] >> 1,param_2);
  }
  return local_8;
}



// Function: FUN_10003b40 at 10003b40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003b40(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_38 [9];
  int local_14;
  uint local_10;
  uint local_c;
  undefined4 *local_8;
  
  ppuVar3 = local_38;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  local_10 = param_1[4];
  local_8 = (undefined4 *)this;
  if (local_10 < param_2) {
    std::_Xout_of_range("invalid string position");
  }
  local_14 = param_1[4];
  local_c = local_14 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if (local_8 == param_1) {
    FUN_10003c90(local_8,param_2 + local_c,0xffffffff);
    FUN_10003c90(local_8,0,param_2);
  }
  else {
    bVar1 = FUN_10003dc0(local_8,local_c,'\0');
    if (bVar1) {
      if ((uint)param_1[5] < 8) {
        local_38[1] = param_1;
      }
      else {
        local_38[1] = (undefined4 *)*param_1;
      }
      if ((uint)local_8[5] < 8) {
        local_38[3] = local_8;
      }
      else {
        local_38[3] = (undefined4 *)*local_8;
      }
      memcpy(local_38[3],(void *)((int)local_38[1] + param_2 * 2),local_c << 1);
      local_8[4] = local_c;
      if ((uint)local_8[5] < 8) {
        local_38[0] = local_8;
      }
      else {
        local_38[0] = (undefined4 *)*local_8;
      }
      *(undefined2 *)((int)local_38[0] + local_c * 2) = 0;
    }
  }
  return local_8;
}



// Function: FUN_10003c90 at 10003c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003c90(void *this,uint param_1,uint param_2)

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



// Function: FUN_10003dc0 at 10003dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10003dff) */
/* WARNING: Removing unreachable block (ram,0x10003e12) */

bool __thiscall FUN_10003dc0(void *this,uint param_1,char param_2)

{
  undefined2 *local_28;
  uint local_24;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10003f00(this,param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      local_28 = (undefined2 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_28 = *this;
      }
      *local_28 = 0;
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_24 = param_1;
    }
    else {
      local_24 = *(uint *)((int)this + 0x10);
    }
    FUN_10003930(this,'\x01',local_24);
  }
  return param_1 != 0;
}



// Function: FUN_10003f00 at 10003f00

/* WARNING: Removing unreachable block (ram,0x10003fbe) */
/* WARNING: Removing unreachable block (ram,0x10003f54) */
/* WARNING: Removing unreachable block (ram,0x10004020) */
/* WARNING: Removing unreachable block (ram,0x10003fd1) */
/* WARNING: Removing unreachable block (ram,0x10003f67) */
/* WARNING: Removing unreachable block (ram,0x10004033) */

void __thiscall FUN_10003f00(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [11];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  uint local_1c;
  void *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d630;
  pvStack_10 = ExceptionList;
  puVar2 = local_64;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = param_1 | 7;
  local_28 = 0x7fffffff;
  local_64[6] = 0x7fffffff;
  local_24 = 0x7fffffff;
  local_64[5] = 0x7ffffffe;
  if (local_1c < 0x7fffffff) {
    if (local_1c / 3 < *(uint *)((int)this + 0x14) >> 1) {
      local_30 = 0x7fffffff;
      local_64[4] = 0x7fffffff;
      local_2c = 0x7fffffff;
      local_64[3] = 0x7ffffffe;
      if (0x7ffffffe - (*(uint *)((int)this + 0x14) >> 1) < *(uint *)((int)this + 0x14)) {
        local_38 = 0x7fffffff;
        local_64[2] = 0x7fffffff;
        local_34 = 0x7fffffff;
        local_64[1] = 0x7ffffffe;
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
  local_18 = this;
  local_14 = &stack0xffffff90;
  local_20 = FUN_10004170(local_1c + 1);
  FUN_100040c1();
  return;
}



// Function: Catch@10004068 at 10004068

void Catch_10004068(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = FUN_10004170(*(int *)(unaff_EBP + -0x18) + 1);
  *(void **)(unaff_EBP + -0x1c) = pvVar1;
  FUN_100040ad();
  return;
}



// Function: Catch@1000408b at 1000408b

void Catch_1000408b(void)

{
  int unaff_EBP;
  
  FUN_10003930(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100040ad at 100040ad

undefined4 FUN_100040ad(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x100040c8;
}



// Function: FUN_100040c1 at 100040c1

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100040c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if (*(uint *)(*(int *)(unaff_EBP + -0x14) + 0x14) < 8) {
      *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x14);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x3c) = **(undefined4 **)(unaff_EBP + -0x14);
    }
    memcpy(*(void **)(unaff_EBP + -0x1c),*(void **)(unaff_EBP + -0x3c),
           *(int *)(unaff_EBP + 0xc) << 1);
  }
  FUN_10003930(*(void **)(unaff_EBP + -0x14),'\x01',0);
  **(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined2 *)(unaff_EBP + -0x42) = 0;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10) = *(undefined4 *)(unaff_EBP + 0xc);
  if (*(uint *)(*(int *)(unaff_EBP + -0x14) + 0x14) < 8) {
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x14);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x60) = **(undefined4 **)(unaff_EBP + -0x14);
  }
  *(undefined2 *)(*(int *)(unaff_EBP + -0x60) + *(int *)(unaff_EBP + 0xc) * 2) =
       *(undefined2 *)(unaff_EBP + -0x42);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10004170 at 10004170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10004170(uint param_1)

{
  char *local_24;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d652;
  local_10 = ExceptionList;
  local_24 = (char *)0xcccccccc;
  local_20 = (undefined **)0xcccccccc;
  local_1c = 0xcccccccc;
  local_18 = 0xcccccccc;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0x7fffffff < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 << 1), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)&local_20,&local_24);
    local_20 = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10029e88);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004240 at 10004240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004240(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d672;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100042b0 at 100042b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_100042b0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d672;
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



// Function: FUN_10004330 at 10004330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10004330(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d672;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_100043a0 at 100043a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100043a0(void *this,int param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_4c [12];
  undefined1 local_19;
  undefined1 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d693;
  local_10 = ExceptionList;
  ppvVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  local_4c[0] = (void *)((int)this + 0x10);
  local_18 = &local_19;
  local_8 = 0;
  local_4c[1] = local_4c[0];
  local_14 = (undefined4 *)this;
  FUN_10003930(local_4c[0],'\0',0);
  FUN_10003b40(local_4c[1],(undefined4 *)(param_1 + 0x10),0,0xffffffff);
  local_14[0xb] = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004480 at 10004480

int * __fastcall FUN_10004480(int *param_1)

{
  int *piVar1;
  int local_18;
  
  if (*(char *)(*param_1 + 0x15) == '\0') {
    if (*(char *)(*(int *)*param_1 + 0x15) == '\0') {
      local_18 = *(int *)*param_1;
      while (*(char *)(*(int *)(local_18 + 8) + 0x15) == '\0') {
        local_18 = *(int *)(local_18 + 8);
      }
      *param_1 = local_18;
    }
    else {
      while ((piVar1 = *(int **)(*param_1 + 4), *(char *)((int)piVar1 + 0x15) == '\0' &&
             (*param_1 == *piVar1))) {
        *param_1 = (int)piVar1;
      }
      if (*(char *)(*param_1 + 0x15) == '\0') {
        *param_1 = (int)piVar1;
      }
    }
  }
  else {
    *param_1 = *(int *)(*param_1 + 8);
  }
  return param_1;
}



// Function: FUN_10004550 at 10004550

void __thiscall FUN_10004550(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d6a0;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  puVar1 = FUN_10004750((int)this);
  local_8 = 0;
  FUN_10004890((int)this + 0xd,puVar1 + 3,param_1);
  FUN_100045d3();
  return;
}



// Function: Catch@100045b1 at 100045b1

void Catch_100045b1(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100045d3 at 100045d3

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100045d3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10004600 at 10004600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10004683) */

void __cdecl FUN_10004600(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d6db;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  Ordinal_6(param_1[1]);
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,0x10004659);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100046b0 at 100046b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100046b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d713;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  Ordinal_6(param_1[1]);
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,0x1000470e);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004750 at 10004750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10004750(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100047c0(1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(puVar1 + 5) = 0;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  return puVar1;
}



// Function: FUN_100047c0 at 100047c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_100047c0(uint param_1)

{
  char *local_24;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d652;
  local_10 = ExceptionList;
  local_24 = (char *)0xcccccccc;
  local_20 = (undefined **)0xcccccccc;
  local_1c = 0xcccccccc;
  local_18 = 0xcccccccc;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0xaaaaaaa < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 * 0x18), local_14 == (void *)0x0))
     )) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)&local_20,&local_24);
    local_20 = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10029e88);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004890 at 10004890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10004890(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    *param_3 = 0;
    param_2[1] = param_3[1];
    param_3[1] = 0;
  }
  return;
}



// Function: FUN_10004960 at 10004960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10004960(void *this,wchar_t *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_40 [6];
  size_t local_28;
  undefined1 local_1d;
  undefined1 *local_1c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f4a8;
  local_10 = ExceptionList;
  ppvVar2 = local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_1c = &local_1d;
  local_8 = 0;
  ExceptionList = &local_10;
  local_40[0] = this;
  local_14 = this;
  FUN_10003930(this,'\0',0);
  local_28 = wcslen(param_1);
  FUN_100039f0(local_14,(undefined4 *)param_1,local_28);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004a00 at 10004a00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10004b23) */

undefined8 __cdecl FUN_10004a00(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined4 uVar4;
  int *local_58 [2];
  uint local_50;
  undefined4 local_48 [3];
  int *local_3c [3];
  int *local_30 [3];
  undefined4 local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d871;
  local_10 = ExceptionList;
  ppiVar3 = local_58;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_50 = 0;
  ExceptionList = &local_10;
  FUN_10002600(local_24);
  local_30[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  uVar1 = (**(code **)(*param_2 + 0x44))(param_2,local_30);
  uVar4 = 0x10004a6c;
  FUN_10002680(local_24,uVar1);
  local_58[1] = local_30[0];
  local_3c[0] = (int *)0x0;
  local_8._0_1_ = 5;
  if (local_30[0] != (int *)0x0) {
    (**(code **)*local_30[0])(local_30[0],&DAT_10026658,local_3c,uVar4);
    uVar4 = 0x10004aaf;
  }
  local_48[0] = 0;
  local_8._0_1_ = 8;
  local_58[0] = local_3c[0];
  uVar1 = (**(code **)(*local_3c[0] + 0x3c))(local_3c[0],local_48,uVar4);
  uVar4 = 0x10004ae3;
  FUN_10002680(local_24,uVar1);
  *param_1 = 0;
  *param_1 = local_48[0];
  local_50 = local_50 | 1;
  local_48[0] = 0;
  local_8._0_1_ = 3;
  if (local_3c[0] != (int *)0x0) {
    (**(code **)(*local_3c[0] + 8))(local_3c[0],uVar4);
    uVar4 = 0x10004b63;
  }
  local_8._0_1_ = 1;
  if (local_30[0] != (int *)0x0) {
    (**(code **)(*local_30[0] + 8))(local_30[0],uVar4);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__CRectTracker(local_24);
  uVar1 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_10004bc4);
  ExceptionList = local_10;
  return CONCAT44(uVar1,param_1);
}



// Function: FUN_10004c30 at 10004c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __cdecl FUN_10004c30(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined4 uVar4;
  int *local_b8 [4];
  int *local_a8;
  int *local_a4;
  int *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_74 [2];
  int *local_6c [3];
  int *local_60 [3];
  int *local_54 [3];
  int *local_48 [3];
  int local_3c [3];
  int *local_30 [3];
  undefined4 local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d913;
  local_10 = ExceptionList;
  ppiVar3 = local_b8;
  for (iVar2 = 0x2a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &local_10;
  FUN_10002600(local_24);
  local_30[0] = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  uVar1 = (**(code **)(*param_1 + 0x54))(param_1,local_30);
  uVar4 = 0x10004c9b;
  FUN_10002680(local_24,uVar1);
  local_3c[0] = 0;
  local_8._0_1_ = 3;
  local_a0 = local_30[0];
  uVar1 = (**(code **)(*local_30[0] + 0x20))(local_30[0],local_3c,uVar4);
  uVar4 = 0x10004cd9;
  FUN_10002680(local_24,uVar1);
  local_48[0] = (int *)0x0;
  local_8._0_1_ = 5;
  local_a4 = local_30[0];
  uVar1 = (**(code **)(*local_30[0] + 0x28))(local_30[0],local_48,uVar4);
  uVar4 = 0x10004d1b;
  FUN_10002680(local_24,uVar1);
  local_54[0] = (int *)0x0;
  local_8._0_1_ = 7;
  local_a8 = local_48[0];
  uVar1 = (**(code **)(*local_48[0] + 0x30))(local_48[0],local_54,uVar4);
  uVar4 = 0x10004d5d;
  FUN_10002680(local_24,uVar1);
  local_60[0] = (int *)0x0;
  local_8._0_1_ = 9;
  local_b8[3] = local_54[0];
  uVar1 = (**(code **)(*local_54[0] + 0x24))(local_54[0],local_60,uVar4);
  uVar4 = 0x10004d9f;
  FUN_10002680(local_24,uVar1);
  local_6c[0] = (int *)0x0;
  local_8._0_1_ = 0xb;
  local_94 = (uint)local_94._2_2_ << 0x10;
  FUN_10005050(&local_94,local_3c);
  local_b8[2] = &local_94;
  local_8._0_1_ = 0xc;
  local_84 = local_94;
  local_b8[1] = local_60[0];
  uVar1 = (**(code **)(*local_60[0] + 0x1c))
                    (local_60[0],local_94,local_90,local_8c,local_88,local_6c,uVar4);
  uVar4 = 0x10004e42;
  FUN_10002680(local_24,uVar1);
  local_8._0_1_ = 0xb;
  local_9c = Ordinal_9(&local_94,uVar4);
  local_b8[0] = local_6c[0];
  uVar1 = (**(code **)(*local_6c[0] + 0x38))(local_6c[0],local_74,0x10004e65);
  uVar4 = 0x10004e95;
  FUN_10002680(local_24,uVar1);
  local_98 = local_74[0];
  local_8._0_1_ = 9;
  if (local_6c[0] != (int *)0x0) {
    (**(code **)(*local_6c[0] + 8))(local_6c[0],uVar4);
    uVar4 = 0x10004ecc;
  }
  local_8._0_1_ = 7;
  if (local_60[0] != (int *)0x0) {
    (**(code **)(*local_60[0] + 8))(local_60[0],uVar4);
    uVar4 = 0x10004ef1;
  }
  local_8._0_1_ = 5;
  if (local_54[0] != (int *)0x0) {
    (**(code **)(*local_54[0] + 8))(local_54[0],uVar4);
    uVar4 = 0x10004f16;
  }
  local_8._0_1_ = 3;
  if (local_48[0] != (int *)0x0) {
    (**(code **)(*local_48[0] + 8))(local_48[0],uVar4);
    uVar4 = 0x10004f3b;
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_3c[0],uVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_30[0] != (int *)0x0) {
    (**(code **)(*local_30[0] + 8))(local_30[0],0x10004f52);
  }
  local_8 = 0xffffffff;
  FID_conflict__CRectTracker(local_24);
  uVar1 = local_98;
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10004fbc);
  ExceptionList = local_10;
  return CONCAT44(uVar4,uVar1);
}



// Function: FUN_10005050 at 10005050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined2 * __thiscall FUN_10005050(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
    FUN_10001920(iVar1);
  }
  *(undefined2 *)this = 8;
  uVar2 = FUN_10001a90(param_1);
  *(undefined4 *)((int)this + 8) = uVar2;
  if ((*(int *)((int)this + 8) == 0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    FUN_10001920(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 100050f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10005140 at 10005140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000523e) */
/* WARNING: Removing unreachable block (ram,0x1000539f) */
/* WARNING: Removing unreachable block (ram,0x10005446) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10005140(undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *local_1bc [4];
  int *local_1ac;
  int *local_1a8;
  int *local_1a4;
  int *local_1a0;
  int *local_19c;
  int *local_198;
  undefined4 local_194;
  int *local_190;
  undefined4 local_18c;
  int *local_188;
  int *local_184;
  int *local_180;
  int *local_17c;
  int *local_178;
  undefined4 local_174;
  int local_170;
  undefined4 *local_16c;
  undefined4 local_168;
  int local_164;
  int *local_160;
  int *local_15c;
  int *local_158;
  int *local_154;
  int local_150;
  int local_14c;
  int local_148;
  int *local_144;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  uint local_124;
  int local_114;
  undefined1 *local_110;
  undefined1 *local_10c;
  int local_108;
  int local_104 [2];
  int local_fc;
  int local_f0 [2];
  int local_e8;
  int local_e4 [2];
  int *local_dc [3];
  int *local_d0 [3];
  undefined4 local_c4 [3];
  int *local_b8 [3];
  int *local_ac [3];
  int *local_a0 [3];
  int *local_94;
  int local_88 [3];
  int local_7c [3];
  int local_70 [5];
  int *local_5c;
  int *local_50;
  int *local_44;
  undefined4 local_3c;
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001db57;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_1bc;
  for (iVar2 = 0x6a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffe38;
  FUN_10002600(local_28);
  local_34[0] = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  uVar4 = FUN_10004a00(local_104,param_3);
  local_180 = (int *)uVar4;
  local_8._0_1_ = 4;
  local_17c = local_180;
  FUN_10005e70(local_34,local_180);
  local_8._0_1_ = 3;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(local_104);
  uVar4 = FUN_10004c30(param_3);
  local_3c = (undefined4)uVar4;
  local_44 = (int *)0x0;
  local_8._0_1_ = 7;
  uVar1 = (**(code **)(*param_3 + 0x3c))();
  FUN_10002680(local_28,uVar1);
  local_50 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,9);
  local_108 = Ordinal_2();
  if (local_108 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_144 = &local_108;
  local_8._0_1_ = 10;
  local_148 = local_108;
  uVar1 = (**(code **)(*param_2 + 0x90))();
  FUN_10002680(local_28,uVar1);
  local_8._0_1_ = 9;
  Ordinal_6();
  local_5c = (int *)0x0;
  local_8._0_1_ = 0xc;
  while( true ) {
    local_184 = local_50;
    uVar1 = (**(code **)(*local_50 + 0x24))();
    local_14c = FUN_10002680(local_28,uVar1);
    local_150 = *(int *)(local_14c + 0xc);
    if (local_150 != 0) break;
    FUN_1001a120(local_70);
    local_8._0_1_ = 0xd;
    local_154 = local_5c;
    uVar4 = FUN_1001a220(local_70,local_5c,local_5c);
    FUN_10002680(local_28,(int)uVar4);
    local_7c[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0xe);
    piVar8 = local_7c;
    local_10c = &stack0xfffffe00;
    local_158 = (int *)&stack0xfffffe00;
    iVar2 = Ordinal_2(L"parameterID");
    iVar7 = 0x100053c1;
    *local_158 = iVar2;
    if (*local_158 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_188 = local_158;
    local_8._0_1_ = 0xe;
    uVar4 = FUN_1001b1b0(iVar7,piVar8);
    local_18c = (undefined4)uVar4;
    FUN_10002680(local_28,local_18c);
    local_88[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0x10);
    piVar8 = local_88;
    local_15c = (int *)&stack0xfffffe00;
    local_110 = &stack0xfffffe00;
    iVar2 = Ordinal_2(L"dsPrefix");
    iVar7 = 0x10005468;
    *local_15c = iVar2;
    if (*local_15c == 0) {
      FUN_10001920(0x8007000e);
    }
    local_190 = local_15c;
    local_8._0_1_ = 0x10;
    uVar4 = FUN_1001b1b0(iVar7,piVar8);
    local_194 = (undefined4)uVar4;
    FUN_10002680(local_28,local_194);
    local_94 = (int *)0x0;
    local_8._0_1_ = 0x13;
    uVar1 = (**(code **)(*param_3 + 0x44))();
    uVar6 = 0x100054f0;
    FUN_10002680(local_28,uVar1);
    local_a0[0] = (int *)0x0;
    local_8._0_1_ = 0x15;
    local_160 = local_94;
    uVar1 = (**(code **)*local_94)(local_94,&DAT_10026658,local_a0,uVar6);
    uVar6 = 0x1000553f;
    FUN_10002680(local_28,uVar1);
    local_ac[0] = (int *)0x0;
    local_8._0_1_ = 0x17;
    local_198 = local_a0[0];
    uVar1 = (**(code **)(*local_a0[0] + 0x2c))(local_a0[0],local_ac,uVar6);
    uVar6 = 0x1000558a;
    FUN_10002680(local_28,uVar1);
    local_b8[0] = (int *)0x0;
    local_8._0_1_ = 0x19;
    local_19c = local_34[0];
    local_164 = local_7c[0];
    uVar1 = (**(code **)(*local_34[0] + 0x1c))(local_34[0],local_7c[0],local_3c,local_b8,uVar6);
    uVar6 = 0x100055e6;
    FUN_10002680(local_28,uVar1);
    local_c4[0] = 0;
    local_8._0_1_ = 0x1a;
    local_1a0 = local_b8[0];
    uVar1 = (**(code **)(*local_b8[0] + 0x28))(local_b8[0],local_c4,uVar6);
    uVar6 = 0x1000562d;
    FUN_10002680(local_28,uVar1);
    local_d0[0] = (int *)0x0;
    local_8._0_1_ = 0x1c;
    local_1a4 = local_ac[0];
    local_168 = local_c4[0];
    uVar1 = (**(code **)(*local_ac[0] + 0x1c))(local_ac[0],local_c4[0],local_d0,uVar6);
    uVar6 = 0x1000568b;
    FUN_10002680(local_28,uVar1);
    local_dc[0] = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x1e);
    local_1a8 = local_d0[0];
    uVar1 = (**(code **)(*local_d0[0] + 0x1c))(local_d0[0],local_dc,uVar6);
    uVar6 = 0x100056d6;
    FUN_10002680(local_28,uVar1);
    local_1ac = local_dc[0];
    uVar1 = (**(code **)(*local_dc[0] + 0x20))(local_dc[0],local_e4,uVar6);
    uVar6 = 0x1000570f;
    FUN_10002680(local_28,uVar1);
    for (local_e8 = 0; piVar8 = local_5c, local_e8 < local_e4[0]; local_e8 = local_e8 + 1) {
      local_f0[0] = 0;
      local_8 = CONCAT31(local_8._1_3_,0x1f);
      local_1bc[3] = local_dc[0];
      uVar1 = (**(code **)(*local_dc[0] + 0x1c))(local_dc[0],local_e8,local_f0);
      FUN_10002680(local_28,uVar1);
      local_fc = FUN_10001a90(local_88);
      if ((local_88[0] != 0) && (local_fc == 0)) {
        FUN_10001920(0x8007000e);
      }
      local_8._0_1_ = 0x20;
      uVar4 = FUN_10019e90(&local_114,local_e8);
      local_1bc[2] = (int *)uVar4;
      local_8._0_1_ = 0x21;
      local_16c = local_1bc[2];
      uVar5 = FUN_10005db0(*local_1bc[2]);
      FUN_10002680(local_28,(int)uVar5);
      local_8._0_1_ = 0x20;
      Ordinal_6(local_114);
      uVar1 = 0x1000583b;
      local_134 = local_134 & 0xffff0000;
      FUN_10005050(&local_134,local_f0);
      local_1bc[1] = (int *)&local_134;
      local_8._0_1_ = 0x22;
      local_124 = local_134;
      local_1bc[0] = local_44;
      local_170 = local_fc;
      uVar1 = (**(code **)(*local_44 + 0x28))
                        (local_44,local_fc,local_134,local_130,local_12c,local_128,uVar1);
      uVar6 = 0x100058f0;
      FUN_10002680(local_28,uVar1);
      local_8._0_1_ = 0x20;
      local_174 = Ordinal_9(&local_134,uVar6);
      local_8._0_1_ = 0x1f;
      Ordinal_6(local_fc,0x10005913);
      local_8 = CONCAT31(local_8._1_3_,0x1e);
      Ordinal_6(local_f0[0],0x10005933);
      uVar6 = 0x1000594d;
    }
    local_178 = local_5c;
    if (local_5c != (int *)0x0) {
      local_5c = (int *)0x0;
      (**(code **)(*piVar8 + 8))(piVar8,uVar6);
      uVar6 = 0x10005988;
    }
    local_8._0_1_ = 0x1c;
    if (local_dc[0] != (int *)0x0) {
      (**(code **)(*local_dc[0] + 8))(local_dc[0],uVar6);
      uVar6 = 0x100059b6;
    }
    local_8._0_1_ = 0x1a;
    if (local_d0[0] != (int *)0x0) {
      (**(code **)(*local_d0[0] + 8))(local_d0[0],uVar6);
      uVar6 = 0x100059e4;
    }
    local_8._0_1_ = 0x19;
    Ordinal_6(local_c4[0],uVar6);
    uVar1 = 0x100059fe;
    local_8._0_1_ = 0x17;
    if (local_b8[0] != (int *)0x0) {
      (**(code **)(*local_b8[0] + 8))(local_b8[0],0x100059fe);
      uVar1 = 0x10005a2c;
    }
    local_8._0_1_ = 0x15;
    if (local_ac[0] != (int *)0x0) {
      (**(code **)(*local_ac[0] + 8))(local_ac[0],uVar1);
      uVar1 = 0x10005a5a;
    }
    local_8._0_1_ = 0x13;
    if (local_a0[0] != (int *)0x0) {
      (**(code **)(*local_a0[0] + 8))(local_a0[0],uVar1);
      uVar1 = 0x10005a88;
    }
    local_8._0_1_ = 0x10;
    if (local_94 != (int *)0x0) {
      (**(code **)(*local_94 + 8))(local_94,uVar1);
      uVar1 = 0x10005ab6;
    }
    local_8._0_1_ = 0xe;
    Ordinal_6(local_88[0],uVar1);
    local_8._0_1_ = 0xd;
    Ordinal_6(local_7c[0],0x10005ad0);
    local_8._0_1_ = 0xc;
    FUN_1001a190(local_70);
  }
  local_8._0_1_ = 9;
  if (local_5c != (int *)0x0) {
    (**(code **)(*local_5c + 8))();
  }
  local_8._0_1_ = 7;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))();
  }
  local_8._0_1_ = 3;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))();
  }
  uVar4 = FUN_10005bab();
  return uVar4;
}



// Function: Catch@10005b8e at 10005b8e

undefined * Catch_10005b8e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x134) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005bb4;
}



// Function: FUN_10005bab at 10005bab

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10005bab(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x138) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x138);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10005c1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10005db0 at 10005db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

ulonglong FUN_10005db0(undefined4 param_1)

{
  ulonglong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_10 = 0xcccccccc;
  local_c = 0xcccccccc;
  uVar1 = Ordinal_7(param_1);
  if ((int)uVar1 == 0) {
    uVar1 = uVar1 & 0xffffffff00000000;
  }
  else {
    local_10 = 0;
    uVar1 = Ordinal_313(*local_8,param_1,&local_10,0x10005de1);
    if (-1 < (int)uVar1) {
      Ordinal_6(*local_8);
      uVar1 = CONCAT44(local_8,(int)uVar1);
      *local_8 = local_10;
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10005e54);
  return uVar1;
}



// Function: FUN_10005e70 at 10005e70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10005e70(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 8))(*this);
    }
    *(int *)this = *param_1;
    *param_1 = 0;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005f10 at 10005f10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 FUN_10005f10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_18;
  
  iVar1 = Ordinal_7(param_1);
  iVar2 = Ordinal_7(param_2,0x10005f41);
  iVar3 = Ordinal_7(param_3,0x10005f57);
  if (((((iVar1 < 1) || (iVar2 != 0)) || (iVar3 != 0)) &&
      (((iVar1 != 0 || (iVar2 < 1)) || (iVar3 != 0)))) &&
     (((iVar1 != 0 || (iVar2 != 0)) || (iVar3 < 1)))) {
    local_18 = 0;
  }
  else {
    local_18 = 1;
  }
  return local_18;
}



// Function: FUN_10005fd0 at 10005fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10006833) */
/* WARNING: Removing unreachable block (ram,0x100066eb) */
/* WARNING: Removing unreachable block (ram,0x100065a9) */
/* WARNING: Removing unreachable block (ram,0x10006467) */
/* WARNING: Removing unreachable block (ram,0x10006325) */
/* WARNING: Removing unreachable block (ram,0x100061e3) */
/* WARNING: Removing unreachable block (ram,0x100060b0) */
/* WARNING: Removing unreachable block (ram,0x1000614d) */
/* WARNING: Removing unreachable block (ram,0x1000628f) */
/* WARNING: Removing unreachable block (ram,0x100063d1) */
/* WARNING: Removing unreachable block (ram,0x10006513) */
/* WARNING: Removing unreachable block (ram,0x10006655) */
/* WARNING: Removing unreachable block (ram,0x1000679a) */
/* WARNING: Removing unreachable block (ram,0x100068de) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10005fd0(int param_1,int *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *extraout_EDX;
  int **ppiVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *local_1dc [4];
  undefined4 local_1cc;
  int *local_1c8;
  char local_1c1;
  int *local_1c0;
  undefined4 local_1bc;
  int *local_1b8;
  char local_1b1;
  int *local_1b0;
  undefined4 local_1ac;
  int *local_1a8;
  char local_1a1;
  int *local_1a0;
  undefined4 local_19c;
  int *local_198;
  char local_191;
  int *local_190;
  undefined4 local_18c;
  int *local_188;
  char local_181;
  int *local_180;
  undefined4 local_17c;
  int *local_178;
  char local_171;
  int *local_170;
  undefined4 local_16c;
  int *local_168;
  undefined4 local_164;
  int *local_160;
  undefined4 *local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int *local_140;
  int *local_13c;
  int *local_138;
  int *local_134;
  int *local_130;
  int *local_12c;
  int *local_128;
  int *local_124;
  int *local_120;
  int *local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int *local_10c;
  undefined4 local_104;
  undefined4 local_100;
  int *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int *local_ec;
  undefined1 *local_e4;
  undefined1 *local_e0;
  undefined1 *local_dc;
  undefined1 *local_d8;
  undefined1 *local_d4;
  undefined1 *local_d0;
  undefined1 *local_cc;
  undefined1 *local_c8;
  undefined1 *local_c4;
  undefined1 *local_c0;
  undefined1 *local_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  undefined1 *local_b0;
  int *local_a8 [3];
  int *local_9c;
  int local_90 [3];
  int local_84 [3];
  int local_78 [3];
  int local_6c [3];
  int local_60 [3];
  int local_54 [3];
  int local_48 [3];
  int local_3c [5];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001df58;
  pvStack_10 = ExceptionList;
  ppiVar5 = local_1dc;
  for (iVar4 = 0x72; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar5 = (int *)0xcccccccc;
    ppiVar5 = ppiVar5 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffe18;
  FUN_10002600(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  uVar2 = (**(code **)(*param_3 + 0x54))();
  FUN_10002680(local_28,uVar2);
  uVar2 = (**(code **)(*param_3 + 0x3c))();
  FUN_10002680(local_28,uVar2);
  FUN_1001a120(local_3c);
  local_8._0_1_ = 2;
  uVar6 = FUN_1001a220(local_3c,extraout_EDX,param_2);
  FUN_10002680(local_28,(int)uVar6);
  local_48[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar3 = local_48;
  local_b0 = &stack0xfffffdf8;
  local_10c = (int *)&stack0xfffffdf8;
  iVar4 = Ordinal_2(L"dsComparisonID");
  iVar8 = 0x100060d2;
  *local_10c = iVar4;
  if (*local_10c == 0) {
    FUN_10001920(0x8007000e);
  }
  local_168 = local_10c;
  local_8._0_1_ = 3;
  uVar6 = FUN_1001b1b0(iVar8,piVar3);
  local_16c = (undefined4)uVar6;
  FUN_10002680(local_28,local_16c);
  local_54[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  local_b4 = &stack0xfffffdfc;
  local_110 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x1000616f;
  *local_110 = iVar4;
  if (*local_110 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_170 = local_110;
  local_8 = CONCAT31(local_8._1_3_,5);
  local_171 = FUN_1001a410(iVar8);
  if (local_171 != '\0') {
    piVar3 = local_54;
    local_b8 = &stack0xfffffdf8;
    local_114 = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(&DAT_100267dc);
    iVar8 = 0x10006205;
    *local_114 = iVar4;
    if (*local_114 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_178 = local_114;
    local_8 = CONCAT31(local_8._1_3_,5);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_17c = (undefined4)uVar6;
    FUN_10002680(local_28,local_17c);
    FUN_10002050((void *)(param_1 + 0x2c),local_54);
  }
  local_60[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,8);
  local_bc = &stack0xfffffdfc;
  local_118 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x100062b1;
  *local_118 = iVar4;
  if (*local_118 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_180 = local_118;
  local_8 = CONCAT31(local_8._1_3_,8);
  local_181 = FUN_1001a410(iVar8);
  if (local_181 != '\0') {
    piVar3 = local_60;
    local_c0 = &stack0xfffffdf8;
    local_11c = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(L"lhsParam");
    iVar8 = 0x10006347;
    *local_11c = iVar4;
    if (*local_11c == 0) {
      FUN_10001920(0x8007000e);
    }
    local_188 = local_11c;
    local_8 = CONCAT31(local_8._1_3_,8);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_18c = (undefined4)uVar6;
    FUN_10002680(local_28,local_18c);
    FUN_10002050((void *)(param_1 + 0x30),local_60);
  }
  local_6c[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_c4 = &stack0xfffffdfc;
  local_120 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x100063f3;
  *local_120 = iVar4;
  if (*local_120 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_190 = local_120;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_191 = FUN_1001a410(iVar8);
  if (local_191 != '\0') {
    piVar3 = local_6c;
    local_c8 = &stack0xfffffdf8;
    local_124 = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(L"lhsDS");
    iVar8 = 0x10006489;
    *local_124 = iVar4;
    if (*local_124 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_198 = local_124;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_19c = (undefined4)uVar6;
    FUN_10002680(local_28,local_19c);
    FUN_10002050((void *)(param_1 + 0x3c),local_6c);
  }
  local_78[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,0xe);
  local_cc = &stack0xfffffdfc;
  local_128 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x10006535;
  *local_128 = iVar4;
  if (*local_128 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_1a0 = local_128;
  local_8 = CONCAT31(local_8._1_3_,0xe);
  local_1a1 = FUN_1001a410(iVar8);
  if (local_1a1 != '\0') {
    piVar3 = local_78;
    local_d0 = &stack0xfffffdf8;
    local_12c = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(&DAT_100267b4);
    iVar8 = 0x100065cb;
    *local_12c = iVar4;
    if (*local_12c == 0) {
      FUN_10001920(0x8007000e);
    }
    local_1a8 = local_12c;
    local_8 = CONCAT31(local_8._1_3_,0xe);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_1ac = (undefined4)uVar6;
    FUN_10002680(local_28,local_1ac);
    FUN_10002050((void *)(param_1 + 0x34),local_78);
  }
  local_84[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,0x11);
  local_d4 = &stack0xfffffdfc;
  local_130 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x10006677;
  *local_130 = iVar4;
  if (*local_130 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_1b0 = local_130;
  local_8 = CONCAT31(local_8._1_3_,0x11);
  local_1b1 = FUN_1001a410(iVar8);
  if (local_1b1 != '\0') {
    piVar3 = local_84;
    local_d8 = &stack0xfffffdf8;
    local_134 = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(L"rhsParam");
    iVar8 = 0x1000670d;
    *local_134 = iVar4;
    if (*local_134 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_1b8 = local_134;
    local_8 = CONCAT31(local_8._1_3_,0x11);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_1bc = (undefined4)uVar6;
    FUN_10002680(local_28,local_1bc);
    FUN_10002050((void *)(param_1 + 0x38),local_84);
  }
  local_90[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,0x14);
  local_dc = &stack0xfffffdfc;
  local_138 = (int *)&stack0xfffffdfc;
  iVar4 = Ordinal_2();
  iVar8 = 0x100067bc;
  *local_138 = iVar4;
  if (*local_138 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_1c0 = local_138;
  local_8 = CONCAT31(local_8._1_3_,0x14);
  local_1c1 = FUN_1001a410(iVar8);
  if (local_1c1 != '\0') {
    piVar3 = local_90;
    local_e0 = &stack0xfffffdf8;
    local_13c = (int *)&stack0xfffffdf8;
    iVar4 = Ordinal_2(L"rhsDS");
    iVar8 = 0x10006855;
    *local_13c = iVar4;
    if (*local_13c == 0) {
      FUN_10001920(0x8007000e);
    }
    local_1c8 = local_13c;
    local_8 = CONCAT31(local_8._1_3_,0x14);
    uVar6 = FUN_1001b1b0(iVar8,piVar3);
    local_1cc = (undefined4)uVar6;
    FUN_10002680(local_28,local_1cc);
    FUN_10002050((void *)(param_1 + 0x40),local_90);
  }
  piVar3 = (int *)(param_1 + 0x44);
  local_e4 = &stack0xfffffdf8;
  local_140 = (int *)&stack0xfffffdf8;
  iVar4 = Ordinal_2(&DAT_1002678c);
  iVar8 = 0x10006900;
  *local_140 = iVar4;
  if (*local_140 == 0) {
    FUN_10001920(0x8007000e);
  }
  local_1dc[3] = local_140;
  local_8 = CONCAT31(local_8._1_3_,0x14);
  uVar6 = FUN_1001b1b0(iVar8,piVar3);
  local_1dc[2] = (int *)uVar6;
  FUN_10002680(local_28,local_1dc[2]);
  local_144 = local_90[0];
  local_148 = local_84[0];
  local_14c = local_78[0];
  cVar1 = FUN_10005f10(local_78[0],local_84[0],local_90[0]);
  if (cVar1 != '\0') {
    local_150 = local_6c[0];
    local_154 = local_60[0];
    local_158 = local_54[0];
    cVar1 = FUN_10005f10(local_54[0],local_60[0],local_6c[0]);
    if (cVar1 != '\0') goto LAB_100069ec;
  }
  FUN_10002680(local_28,0x80004005);
LAB_100069ec:
  local_9c = (int *)0x0;
  local_8._0_1_ = 0x19;
  uVar2 = (**(code **)(*param_3 + 0x3c))();
  uVar7 = 0x10006a1c;
  FUN_10002680(local_28,uVar2);
  local_15c = (undefined4 *)(**(code **)(*(int *)(param_1 + -4) + 0x10))(uVar7);
  uVar2 = 0x10006a3f;
  local_a8[0] = (int *)0x0;
  local_8._0_1_ = 0x1b;
  if (local_15c != (undefined4 *)0x0) {
    (**(code **)*local_15c)(local_15c,&DAT_100265cc,local_a8,0x10006a3f);
    uVar2 = 0x10006a88;
  }
  local_8._0_1_ = 0x1c;
  local_160 = local_a8[0];
  local_104 = CONCAT22(local_104._2_2_,0xd);
  local_fc = local_a8[0];
  if (local_a8[0] != (int *)0x0) {
    (**(code **)(*local_a8[0] + 4))(local_a8[0],uVar2);
    uVar2 = 0x10006ad6;
  }
  local_1dc[1] = &local_104;
  local_8._0_1_ = 0x1d;
  local_f4 = local_104;
  local_ec = local_fc;
  local_1dc[0] = local_9c;
  (**(code **)(*local_9c + 0x28))(local_9c,local_48[0],local_104,local_100,local_fc,local_f8,uVar2);
  local_8._0_1_ = 0x1c;
  local_164 = Ordinal_9(&local_104,0x10006b64);
  uVar2 = 0x10006b7e;
  local_8._0_1_ = 0x19;
  if (local_a8[0] != (int *)0x0) {
    (**(code **)(*local_a8[0] + 8))(local_a8[0],0x10006b7e);
    uVar2 = 0x10006bb6;
  }
  local_8._0_1_ = 0x14;
  if (local_9c != (int *)0x0) {
    (**(code **)(*local_9c + 8))(local_9c,uVar2);
    uVar2 = 0x10006be4;
  }
  local_8._0_1_ = 0x11;
  Ordinal_6(local_90[0],uVar2);
  local_8._0_1_ = 0xe;
  Ordinal_6(local_84[0],0x10006bfe);
  local_8._0_1_ = 0xb;
  Ordinal_6(local_78[0],0x10006c15);
  local_8._0_1_ = 8;
  Ordinal_6(local_6c[0],0x10006c2c);
  local_8._0_1_ = 5;
  Ordinal_6(local_60[0],0x10006c43);
  local_8._0_1_ = 3;
  Ordinal_6(local_54[0],0x10006c5a);
  local_8._0_1_ = 2;
  Ordinal_6(local_48[0],0x10006c71);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1001a190(local_3c);
  uVar6 = FUN_10006ca3();
  return uVar6;
}



// Function: Catch@10006c96 at 10006c96

undefined4 Catch_10006c96(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10006caa;
}



// Function: FUN_10006ca3 at 10006ca3

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006ca3(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x104) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x104);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10006cfc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10006de0 at 10006de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006de0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_EDX;
  int **ppiVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *local_b8 [4];
  undefined1 *local_a8;
  undefined4 local_a0;
  undefined1 *local_9c;
  int *local_98;
  char *local_94 [2];
  undefined4 local_8c;
  undefined **local_88 [4];
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined1 local_60 [8];
  undefined4 local_58;
  int *local_48 [2];
  int local_40;
  int *local_38 [2];
  undefined4 local_30;
  undefined4 local_28 [5];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dfdd;
  local_10 = ExceptionList;
  ppiVar2 = local_b8;
  for (iVar1 = 0x2a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  ExceptionList = &local_10;
  FUN_10002600(local_28);
  local_8 = 0;
  iVar1 = Ordinal_7(param_2);
  if (iVar1 == 0) {
    iVar1 = Ordinal_7(param_3,0x10006e39);
    if (iVar1 == 0) {
      uVar3 = FUN_1001a000(param_1);
      local_30 = (undefined4)uVar3;
    }
    else {
      Ordinal_8(local_78,0x10007041);
      local_8._0_1_ = 0xb;
      local_b8[0] = *(int **)(local_14 + 0x2c);
      uVar5 = (**(code **)(*local_b8[0] + 0x24))(local_b8[0],param_3,local_78,0x1000705c);
      uVar4 = 0x1000709d;
      FUN_10002680(local_28,uVar5);
      local_a8 = local_78;
      uVar5 = Ordinal_12(local_78,local_a8,0,3,uVar4);
      uVar4 = 0x100070e0;
      FUN_10002680(local_28,uVar5);
      local_30 = local_70;
      local_8 = (uint)local_8._1_3_ << 8;
      local_b8[3] = (int *)Ordinal_9(local_78,uVar4);
    }
  }
  else {
    local_38[0] = (int *)0x0;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 2;
    local_b8[2] = *(int **)(local_14 + 0x28);
    local_40 = (**(code **)(*local_b8[2] + 0x30))(local_b8[2],param_2,1,local_38);
    uVar5 = 0x10006e8f;
    if (local_40 < 0) {
      local_94[0] = "Automatically handled error reading from ECM services.";
      std::exception::exception((exception *)local_88,local_94);
      local_88[0] = std::runtime_error::vftable;
      local_8 = CONCAT31(local_8._1_3_,2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_88,(ThrowInfo *)&DAT_1002a9f8);
    }
    local_98 = local_38[0];
    local_48[0] = (int *)0x0;
    local_8._0_1_ = 5;
    if (local_38[0] != (int *)0x0) {
      (**(code **)*local_38[0])(local_38[0],&DAT_100267e4,local_48,0x10006e8f);
      uVar5 = 0x10006f27;
    }
    local_8._0_1_ = 6;
    Ordinal_8(local_60,uVar5);
    local_8._0_1_ = 7;
    local_b8[1] = local_48[0];
    uVar5 = (**(code **)(*local_48[0] + 0x28))(local_48[0],local_60,0x10006f3e);
    uVar4 = 0x10006f6c;
    FUN_10002680(local_28,uVar5);
    local_9c = local_60;
    uVar5 = Ordinal_12(local_60,local_9c,0,3,uVar4);
    uVar4 = 0x10006faf;
    FUN_10002680(local_28,uVar5);
    local_30 = local_58;
    local_8._0_1_ = 6;
    local_a0 = Ordinal_9(local_60,uVar4);
    uVar5 = 0x10006fd5;
    local_8._0_1_ = 2;
    if (local_48[0] != (int *)0x0) {
      (**(code **)(*local_48[0] + 8))(local_48[0],0x10006fd5);
      uVar5 = 0x10007004;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_38[0] != (int *)0x0) {
      (**(code **)(*local_38[0] + 8))(local_38[0],uVar5);
    }
  }
  local_8c = local_30;
  local_8 = 0xffffffff;
  FID_conflict__CRectTracker(local_28);
  uVar5 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000716c);
  ExceptionList = local_10;
  return CONCAT44(uVar5,local_8c);
}



// Function: FUN_100071e0 at 100071e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_100071e0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d672;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10007260 at 10007260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10007260(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d672;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100072c0 at 100072c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_100072c0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d672;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::runtime_error::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10007330 at 10007330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __fastcall FUN_10007330(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined8 uVar5;
  
  uVar5 = FUN_10006de0(*(int *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34),
                       *(undefined4 *)(param_1 + 0x40));
  iVar2 = (int)uVar5;
  uVar5 = FUN_10006de0(*(int *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
                       *(undefined4 *)(param_1 + 0x44));
  iVar3 = (int)uVar5;
  cVar1 = FUN_10007470((void *)(param_1 + 0x48),0x10026884);
  if (cVar1 == '\0') {
    cVar1 = FUN_10007470((void *)(param_1 + 0x48),0x10026868);
    if (cVar1 == '\0') {
      cVar1 = FUN_10007470((void *)(param_1 + 0x48),0x1002684c);
      if (cVar1 == '\0') {
        cVar1 = FUN_10007470((void *)(param_1 + 0x48),0x10026838);
        if (cVar1 == '\0') {
          bVar4 = false;
        }
        else {
          bVar4 = iVar2 < iVar3;
        }
      }
      else {
        bVar4 = iVar3 < iVar2;
      }
    }
    else {
      bVar4 = iVar2 != iVar3;
    }
  }
  else {
    bVar4 = iVar2 == iVar3;
  }
  return bVar4;
}



// Function: FUN_10007470 at 10007470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

char __thiscall FUN_10007470(void *this,int param_1)

{
  int iVar1;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dff8;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    local_1c = 0;
    ExceptionList = &local_10;
  }
  else {
    ExceptionList = &local_10;
    local_1c = Ordinal_2(param_1);
    if (local_1c == 0) {
      FUN_10001920(0x8007000e);
    }
  }
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,local_1c,0x400,0);
  local_8 = 0xffffffff;
  Ordinal_6(local_1c);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007558);
  ExceptionList = local_10;
  return '\x01' - (iVar1 != 1);
}



// Function: FUN_10007580 at 10007580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007580(int param_1,undefined2 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e010;
  pvStack_10 = ExceptionList;
  if (param_2 == (undefined2 *)0x0) {
    return 0x80004003;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  bVar1 = FUN_10007330(param_1);
  iVar2 = FUN_10019ff0(bVar1);
  *param_2 = (short)iVar2;
  uVar3 = FUN_100075e4();
  return uVar3;
}



// Function: Catch@100075cf at 100075cf

undefined4 Catch_100075cf(void)

{
  int unaff_EBP;
  
  **(undefined2 **)(unaff_EBP + 0xc) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100075eb;
}



// Function: FUN_100075e4 at 100075e4

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100075e4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10007610 at 10007610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000770e) */
/* WARNING: Removing unreachable block (ram,0x1000786f) */
/* WARNING: Removing unreachable block (ram,0x10007916) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10007610(undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  int iVar5;
  int *piVar6;
  int *local_130 [4];
  undefined4 local_120;
  int *local_11c;
  undefined4 local_118;
  int *local_114;
  int *local_110;
  int *local_10c;
  int *local_108;
  int *local_104;
  undefined4 local_100;
  int *local_fc;
  int *local_f8;
  int *local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int *local_e4;
  uint local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  uint local_c4;
  undefined1 *local_b4;
  undefined1 *local_b0;
  int local_ac;
  int local_a8 [2];
  int local_a0 [3];
  int *local_94;
  int local_88 [3];
  int local_7c [3];
  int local_70 [5];
  int *local_5c;
  int *local_50;
  int *local_44;
  undefined4 local_3c;
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e3b1;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_130;
  for (iVar2 = 0x47; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffec4;
  FUN_10002600(local_28);
  local_34[0] = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  uVar4 = FUN_10004a00(local_a8,param_3);
  local_10c = (int *)uVar4;
  local_8._0_1_ = 4;
  local_108 = local_10c;
  FUN_10005e70(local_34,local_10c);
  local_8._0_1_ = 3;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(local_a8);
  uVar4 = FUN_10004c30(param_3);
  local_3c = (undefined4)uVar4;
  local_44 = (int *)0x0;
  local_8._0_1_ = 7;
  uVar1 = (**(code **)(*param_3 + 0x3c))();
  FUN_10002680(local_28,uVar1);
  local_50 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,9);
  local_ac = Ordinal_2();
  if (local_ac == 0) {
    FUN_10001920(0x8007000e);
  }
  local_e4 = &local_ac;
  local_8._0_1_ = 10;
  local_e8 = local_ac;
  uVar1 = (**(code **)(*param_2 + 0x90))();
  FUN_10002680(local_28,uVar1);
  local_8._0_1_ = 9;
  Ordinal_6();
  local_5c = (int *)0x0;
  local_8._0_1_ = 0xc;
  while( true ) {
    local_110 = local_50;
    uVar1 = (**(code **)(*local_50 + 0x24))();
    local_ec = FUN_10002680(local_28,uVar1);
    local_f0 = *(int *)(local_ec + 0xc);
    if (local_f0 != 0) break;
    FUN_1001a120(local_70);
    local_8._0_1_ = 0xd;
    local_f4 = local_5c;
    uVar4 = FUN_1001a220(local_70,local_5c,local_5c);
    FUN_10002680(local_28,(int)uVar4);
    local_7c[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0xe);
    piVar6 = local_7c;
    local_b0 = &stack0xfffffe8c;
    local_f8 = (int *)&stack0xfffffe8c;
    iVar2 = Ordinal_2(L"parameterID");
    iVar5 = 0x10007891;
    *local_f8 = iVar2;
    if (*local_f8 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_114 = local_f8;
    local_8._0_1_ = 0xe;
    uVar4 = FUN_1001b1b0(iVar5,piVar6);
    local_118 = (undefined4)uVar4;
    FUN_10002680(local_28,local_118);
    local_88[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0x10);
    piVar6 = local_88;
    local_fc = (int *)&stack0xfffffe8c;
    local_b4 = &stack0xfffffe8c;
    iVar2 = Ordinal_2(L"dsName");
    iVar5 = 0x10007938;
    *local_fc = iVar2;
    if (*local_fc == 0) {
      FUN_10001920(0x8007000e);
    }
    local_11c = local_fc;
    local_8._0_1_ = 0x10;
    uVar4 = FUN_1001b1b0(iVar5,piVar6);
    local_120 = (undefined4)uVar4;
    FUN_10002680(local_28,local_120);
    local_94 = (int *)0x0;
    local_8._0_1_ = 0x13;
    local_130[3] = local_34[0];
    (**(code **)(*local_34[0] + 0x1c))(local_34[0],local_7c[0]);
    local_a0[0] = 0;
    local_8._0_1_ = 0x14;
    local_130[2] = local_94;
    (**(code **)(*local_94 + 0x2c))(local_94,local_a0,0x100079d7);
    uVar1 = 0x10007a15;
    local_d4 = local_d4 & 0xffff0000;
    FUN_10005050(&local_d4,local_a0);
    local_130[1] = (int *)&local_d4;
    local_8._0_1_ = 0x15;
    local_c4 = local_d4;
    local_130[0] = local_44;
    (**(code **)(*local_44 + 0x28))(local_44,local_88[0],local_d4,local_d0,local_cc,local_c8,uVar1);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    local_100 = Ordinal_9(&local_d4,0x10007abe);
    piVar6 = local_5c;
    uVar1 = 0x10007ad8;
    local_104 = local_5c;
    if (local_5c != (int *)0x0) {
      local_5c = (int *)0x0;
      (**(code **)(*piVar6 + 8))(piVar6,0x10007ad8);
      uVar1 = 0x10007b14;
    }
    local_8._0_1_ = 0x13;
    Ordinal_6(local_a0[0],uVar1);
    uVar1 = 0x10007b2e;
    local_8._0_1_ = 0x10;
    if (local_94 != (int *)0x0) {
      (**(code **)(*local_94 + 8))(local_94,0x10007b2e);
      uVar1 = 0x10007b5c;
    }
    local_8._0_1_ = 0xe;
    Ordinal_6(local_88[0],uVar1);
    local_8._0_1_ = 0xd;
    Ordinal_6(local_7c[0],0x10007b76);
    local_8._0_1_ = 0xc;
    FUN_1001a190(local_70);
  }
  local_8._0_1_ = 9;
  if (local_5c != (int *)0x0) {
    (**(code **)(*local_5c + 8))();
  }
  local_8._0_1_ = 7;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))();
  }
  local_8._0_1_ = 3;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))();
  }
  uVar4 = FUN_10007c51();
  return uVar4;
}



// Function: Catch@10007c34 at 10007c34

undefined * Catch_10007c34(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0xd4) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10007c5a;
}



// Function: FUN_10007c51 at 10007c51

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007c51(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0xd8) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xd8);
  _RTC_CheckStackVars(unaff_EBP,(int *)&LAB_10007cc4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10007dc0 at 10007dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007dc0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050((int *)&DAT_10030324,0x65,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10007e00 at 10007e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007e00(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050((int *)&DAT_10030324,0x66,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10007e40 at 10007e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007e40(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050((int *)&DAT_10030324,0x67,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10007e80 at 10007e80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007e80(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050((int *)&DAT_10030324,0x68,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10007ec0 at 10007ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007ec0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050((int *)&DAT_10030324,0x69,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10007f00 at 10007f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007f00(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_1000ccd0(&DAT_10030324,0x1002f1c8,param_1,(undefined4 *)&DAT_10026960);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000cdc0(0x10030324);
  }
  return 1;
}



// Function: DllCanUnloadNow at 10007f60

HRESULT DllCanUnloadNow(void)

{
                    /* 0x7f60  1  DllCanUnloadNow */
  return (uint)(DAT_1003032c != 0);
}



// Function: DllGetClassObject at 10007f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  undefined8 uVar1;
  
                    /* 0x7f80  2  DllGetClassObject */
  uVar1 = FUN_1000cf50((int *)&DAT_10030324,(int *)rclsid,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)uVar1;
}



// Function: DllRegisterServer at 10007fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllRegisterServer(void)

{
                    /* 0x7fd0  3  DllRegisterServer */
  FUN_1000d180(&DAT_10030324,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10008010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllUnregisterServer(void)

{
                    /* 0x8010  4  DllUnregisterServer */
  FUN_1000eb00(&DAT_10030324,1,(void *)0x0);
  return;
}



// Function: FUN_10008050 at 10008050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000836c) */
/* WARNING: Removing unreachable block (ram,0x100080ac) */

undefined8 FUN_10008050(int *param_1,ushort param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  errno_t eVar3;
  DWORD DVar4;
  int iVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 uVar6;
  DWORD *pDVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  DWORD local_b7c [2];
  undefined4 *local_b74;
  int local_b70;
  wchar_t *local_b6c;
  int local_b64 [4];
  undefined4 local_b54;
  DWORD local_b4c;
  int local_b48;
  wchar_t *local_b44;
  int local_b3c [4];
  undefined4 local_b2c;
  DWORD local_b24;
  int *local_b20;
  undefined4 *local_b1c;
  int local_b18;
  int *local_b14;
  undefined4 *local_b10;
  int *local_b0c;
  undefined4 *local_b08;
  int *local_b04;
  int local_b00;
  LPCWSTR local_afc;
  int local_af8;
  LPCWSTR local_af4;
  int local_aec [4];
  undefined4 local_adc;
  int local_ad4;
  DWORD local_acc;
  DWORD local_ac8;
  DWORD local_ac4;
  DWORD local_ac0;
  DWORD local_abc;
  DWORD local_ab8;
  DWORD local_ab4;
  wchar_t *local_aac;
  int local_aa8;
  WCHAR local_aa0;
  undefined2 local_a9e [525];
  DWORD local_684;
  WCHAR local_67c [522];
  WCHAR *local_268;
  DWORD local_264;
  HMODULE local_260;
  WCHAR local_258 [264];
  undefined4 *local_48 [4];
  undefined4 local_38;
  DWORD local_30;
  undefined **local_28;
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e4d8;
  local_10 = ExceptionList;
  pDVar7 = local_b7c;
  for (iVar5 = 0x2db; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pDVar7 = 0xcccccccc;
    pDVar7 = pDVar7 + 1;
  }
  local_28 = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  FUN_1000cc60(local_24);
  local_8 = 1;
  local_30 = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_b00 = param_4[1];
      local_afc = (LPCWSTR)*param_4;
      if ((local_afc != (LPCWSTR)0x0) && (local_b00 != 0)) {
        local_adc = 3;
        local_aec[0] = 0;
        local_8._0_1_ = 4;
        local_af4 = local_afc;
        uVar8 = FUN_10008ae0(local_24,local_b00,local_afc,local_b00);
        local_af8 = (int)uVar8;
        local_ad4 = (-(uint)(local_af8 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_1000fa30(local_aec);
      }
    }
  }
  local_30 = (**(code **)(*param_1 + 0x14))(&local_28);
  local_b7c[0] = 0x100081ee;
  if ((int)local_30 < 0) {
    local_28 = ATL::CRegObject::vftable;
    local_8 = 5;
    local_ab4 = local_30;
    FUN_10009730((int)&local_28);
    local_b04 = local_24;
    local_8 = 6;
    FUN_10008ee0(local_b04);
    local_8 = 0xffffffff;
    FUN_1000fc30(local_b04);
    DVar4 = local_ab4;
    uVar6 = extraout_EDX;
  }
  else {
    local_38 = 3;
    local_48[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_260 = DAT_100308e8;
    local_264 = GetModuleFileNameW(DAT_100308e8,local_258,0x104);
    if (local_264 == 0) {
      local_ab8 = FUN_10008960();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b08 = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 8;
      FUN_10009730((int)&local_28);
      local_b0c = local_24;
      local_8 = 9;
      FUN_10008ee0(local_b0c);
      local_8 = 0xffffffff;
      FUN_1000fc30(local_b0c);
      DVar4 = local_ab8;
      uVar6 = extraout_EDX_00;
    }
    else if (local_264 == 0x104) {
      local_b7c[1] = 0x8007007a;
      local_abc = 0x8007007a;
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b10 = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 10;
      FUN_10009730((int)&local_28);
      local_b14 = local_24;
      local_8 = 0xb;
      FUN_10008ee0(local_b14);
      local_8 = 0xffffffff;
      FUN_1000fc30(local_b14);
      DVar4 = local_abc;
      uVar6 = extraout_EDX_01;
    }
    else {
      local_268 = local_258;
      FUN_100089c0(local_67c,0x208,local_268);
      if ((local_260 == (HMODULE)0x0) ||
         (pHVar2 = GetModuleHandleW((LPCWSTR)0x0), local_260 == pHVar2)) {
        local_aa0 = L'\"';
        local_b18 = lstrlenW(local_67c);
        eVar3 = memcpy_s(local_a9e,0x416,local_67c,local_b18 * 2 + 2);
        if (eVar3 != 0) {
          local_ac0 = 0x80004005;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
            local_b1c = local_48[0];
            local_48[0] = (undefined4 *)*local_48[0];
            free(puVar1);
          }
          local_28 = ATL::CRegObject::vftable;
          local_8 = 0xc;
          FUN_10009730((int)&local_28);
          local_b20 = local_24;
          local_8 = 0xd;
          FUN_10008ee0(local_b20);
          local_8 = 0xffffffff;
          FUN_1000fc30(local_b20);
          DVar4 = local_ac0;
          uVar6 = extraout_EDX_02;
          goto LAB_1000883f;
        }
        local_aa8 = lstrlenW(&local_aa0);
        local_a9e[local_aa8 + -1] = 0x22;
        local_a9e[local_aa8] = 0;
        if (&stack0x00000000 == (undefined1 *)0xaa0) {
          local_684 = 0x80070057;
        }
        else {
          local_b2c = 3;
          local_b3c[0] = 0;
          local_8._0_1_ = 0xe;
          local_b44 = L"Module";
          uVar8 = FUN_10008ae0(local_24,L"Module",L"Module",(int)&local_aa0);
          local_b48 = (int)uVar8;
          local_b24 = (-(uint)(local_b48 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_1000fa30(local_b3c);
          local_684 = local_b24;
        }
      }
      else if (&stack0x00000000 == (undefined1 *)0x67c) {
        local_684 = 0x80070057;
      }
      else {
        local_b54 = 3;
        local_b64[0] = 0;
        local_8._0_1_ = 0xf;
        local_b6c = L"Module";
        uVar8 = FUN_10008ae0(local_24,L"Module",L"Module",(int)local_67c);
        local_b70 = (int)uVar8;
        local_b4c = (-(uint)(local_b70 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8._0_1_ = 7;
        FUN_1000fa30(local_b64);
        local_684 = local_b4c;
      }
      if ((int)local_684 < 0) {
        local_ac4 = local_684;
        local_8 = CONCAT31(local_8._1_3_,1);
        while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
          local_b74 = local_48[0];
          local_48[0] = (undefined4 *)*local_48[0];
          free(puVar1);
        }
        local_8 = 0xffffffff;
        FUN_10009020(&local_28);
        DVar4 = local_ac4;
        uVar6 = extraout_EDX_03;
      }
      else {
        uVar8 = FUN_10009130(local_67c,&local_28,(int)&local_28,0x10026a34,(int)local_67c);
        local_684 = (DWORD)uVar8;
        if ((int)local_684 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_ac8 = local_684;
          FUN_1000fa30((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10009020(&local_28);
          DVar4 = local_ac8;
          uVar6 = extraout_EDX_04;
        }
        else {
          local_aac = L"REGISTRY";
          if (param_3 == 0) {
            uVar8 = FUN_10009640(&local_28,local_268,param_2,L"REGISTRY");
            local_b7c[0] = (DWORD)uVar8;
          }
          else {
            uVar8 = FUN_10009250(&local_28,local_268,param_2,L"REGISTRY");
            local_b7c[0] = (DWORD)uVar8;
          }
          local_30 = local_b7c[0];
          local_acc = local_b7c[0];
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_1000fa30((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10009020(&local_28);
          DVar4 = local_acc;
          uVar6 = extraout_EDX_05;
        }
      }
    }
  }
LAB_1000883f:
  uVar9 = (undefined2)DVar4;
  uVar10 = (undefined2)(DVar4 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10008870);
  ExceptionList = local_10;
  return CONCAT44(uVar6,CONCAT22(uVar10,uVar9));
}



// Function: FUN_10008960 at 10008960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD FUN_10008960(void)

{
  undefined4 local_c;
  
  local_c = GetLastError();
  if (0 < (int)local_c) {
    local_c = local_c & 0xffff | 0x80070000;
  }
  return local_c;
}



// Function: FUN_100089c0 at 100089c0

void __cdecl FUN_100089c0(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10008a70 at 10008a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10008a70(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e4f8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10008ee0(param_1);
  local_8 = 0xffffffff;
  FUN_1000fc30(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008ae0 at 10008ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10008ae0(undefined4 param_1,undefined4 param_2,LPCWSTR param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 local_7c [13];
  undefined4 local_48;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e520;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffff78;
  puVar2 = local_7c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = param_1;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != 0)) {
    local_1c = 0;
    ExceptionList = &pvStack_10;
    local_14 = &stack0xffffff78;
    iVar1 = lstrlenW(param_3);
    local_20 = iVar1 * 2 + 2;
    local_24 = 0;
    local_8 = 0;
    local_48 = FUN_1001bfe6(-(uint)((int)((ulonglong)local_20 * 2 >> 0x20) != 0) |
                            (uint)((ulonglong)local_20 * 2));
    local_24 = local_48;
    uVar3 = FUN_10008b8c();
    return uVar3;
  }
  uVar4 = 0;
  ExceptionList = &pvStack_10;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10008de0);
  ExceptionList = pvStack_10;
  return CONCAT44(param_2,uVar4);
}



// Function: Catch@10008b7f at 10008b7f

undefined4 Catch_10008b7f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10008b93;
}



// Function: FUN_10008b8c at 10008b8c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10008b8c(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined8 uVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x20);
  iVar2 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x30) = iVar2 * 2 + 2;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar1 = (ulonglong)*(uint *)(unaff_EBP + -0x30) * 2;
  uVar3 = FUN_1001bfe6(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x48);
  uVar4 = FUN_10008c10();
  return uVar4;
}



// Function: Catch@10008c03 at 10008c03

undefined4 Catch_10008c03(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x10008c17;
}



// Function: FUN_10008c10 at 10008c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined8 FUN_10008c10(void)

{
  errno_t eVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int unaff_EBP;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x34);
  if ((*(int *)(unaff_EBP + -0x20) == 0) || (*(int *)(unaff_EBP + -0x34) == 0)) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x20);
    eVar1 = memcpy_s(*(void **)(unaff_EBP + -0x54),*(rsize_t *)(unaff_EBP + -0x1c),
                     *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x1c));
    *(errno_t *)(unaff_EBP + -0x50) = eVar1;
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x50);
    switch(*(undefined4 *)(unaff_EBP + -0x74)) {
    case 0:
    case 0x50:
      break;
    default:
      FUN_10001920(0x80004005);
      break;
    case 0xc:
      FUN_10001920(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_10001920(0x80070057);
    }
    *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x34);
    eVar1 = memcpy_s(*(void **)(unaff_EBP + -0x5c),*(rsize_t *)(unaff_EBP + -0x30),
                     *(void **)(unaff_EBP + 0xc),*(rsize_t *)(unaff_EBP + -0x30));
    *(errno_t *)(unaff_EBP + -0x58) = eVar1;
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x58);
    switch(*(undefined4 *)(unaff_EBP + -0x78)) {
    case 0:
    case 0x50:
      break;
    default:
      FUN_10001920(0x80004005);
      break;
    case 0xc:
      FUN_10001920(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_10001920(0x80070057);
    }
    iVar2 = FUN_1000fac0(*(void **)(unaff_EBP + -0x14),(undefined4 *)(unaff_EBP + -0x20),
                         (undefined4 *)(unaff_EBP + -0x34));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
    }
  }
  if (-1 < *(int *)(unaff_EBP + -0x18)) {
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  }
  *(uint *)(unaff_EBP + -0x4c) = (uint)(-1 < *(int *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x3c);
  operator_delete__(*(void **)(unaff_EBP + -0x6c));
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x28);
  operator_delete__(*(void **)(unaff_EBP + -0x70));
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  uVar3 = *(undefined4 *)(unaff_EBP + -0x4c);
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10008de0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar4,uVar3);
}



// Function: FUN_10008ee0 at 10008ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10008ee0(int *param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < param_1[2]; local_c = local_c + 1) {
    if ((local_c < 0) || (param_1[2] <= local_c)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    operator_delete__(*(void **)(*param_1 + local_c * 4));
    if ((local_c < 0) || (param_1[2] <= local_c)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    operator_delete__(*(void **)(param_1[1] + local_c * 4));
  }
  FUN_1000fc30(param_1);
  return 0;
}



// Function: FUN_10008ff0 at 10008ff0

undefined4 FUN_10008ff0(void)

{
  return 0x80004001;
}



// Function: FUN_10009000 at 10009000

undefined4 FUN_10009000(void)

{
  return 1;
}



// Function: FUN_10009010 at 10009010

undefined4 FUN_10009010(void)

{
  return 0;
}



// Function: FUN_10009020 at 10009020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009020(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e543;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_10008ee0(param_1 + 1);
  local_8 = 1;
  FUN_10008ee0(param_1 + 1);
  local_8 = 0xffffffff;
  FUN_1000fc30(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100090d0 at 100090d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100090d0(void *this,uint param_1)

{
  FUN_10009020((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009130 at 10009130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10009130(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 *_Memory;
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 **ppuVar2;
  undefined8 uVar3;
  undefined4 *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 *local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  ppuVar2 = &local_3c;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  if ((param_4 == 0) || (param_5 == 0)) {
    iVar1 = -0x7ff8ffa9;
    ExceptionList = &local_10;
  }
  else {
    local_18 = 3;
    local_28 = (undefined4 *)0x0;
    local_8 = 0;
    local_30 = param_4;
    ExceptionList = &local_10;
    uVar3 = FUN_10008ae0(param_3 + 4,param_4,(LPCWSTR)param_4,param_5);
    local_38 = (-(uint)((int)uVar3 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    while( true ) {
      _Memory = local_28;
      param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
      local_34 = (undefined4)uVar3;
      iVar1 = local_38;
      if (local_28 == (undefined4 *)0x0) break;
      local_3c = local_28;
      local_28 = (undefined4 *)*local_28;
      free(_Memory);
      uVar3 = CONCAT44(extraout_EDX,local_34);
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009218);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_10009250 at 10009250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009250(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  LPCWSTR _Memory;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  LPCWSTR *ppWVar3;
  undefined8 uVar4;
  LPCWSTR local_38 [4];
  LPCWSTR local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  ppWVar3 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppWVar3 = (LPCWSTR)0xcccccccc;
    ppWVar3 = ppWVar3 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  local_38[2] = param_4;
  ExceptionList = &local_10;
  uVar4 = FUN_10009340(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (_Memory = local_28, uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20),
        local_38[1] = (LPCWSTR)uVar4, local_28 != (LPCWSTR)0x0) {
    local_38[0] = local_28;
    local_28 = *(LPCWSTR *)local_28;
    free(_Memory);
    uVar4 = CONCAT44(extraout_EDX,local_38[1]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009314);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_38[1]);
}



// Function: FUN_10009340 at 10009340

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009340(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  DWORD DVar1;
  undefined4 *_Memory;
  int iVar2;
  undefined1 *extraout_EDX;
  undefined1 *puVar3;
  undefined1 *extraout_EDX_00;
  undefined4 **ppuVar4;
  undefined8 uVar5;
  undefined4 *local_488 [5];
  DWORD DStack_474;
  LPCWSTR local_46c;
  undefined1 *local_464;
  undefined1 auStack_460 [1028];
  HGLOBAL local_5c;
  DWORD local_58;
  HGLOBAL local_54;
  HRSRC local_50;
  HMODULE local_4c;
  undefined4 local_44;
  DWORD local_38;
  undefined4 *local_30;
  undefined4 local_20;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e563;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_488;
  for (iVar2 = 0x11d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  local_20 = 3;
  local_30 = (undefined4 *)0x0;
  local_44 = 0;
  local_464 = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_46c = param_1;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffb6c;
  local_4c = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_4c == (HMODULE)0x0) {
    local_38 = FUN_10008960();
  }
  else {
    local_50 = FindResourceW(local_4c,param_2,param_3);
    if (local_50 == (HRSRC)0x0) {
      local_38 = FUN_10008960();
    }
    else {
      local_54 = LoadResource(local_4c,local_50);
      if (local_54 == (HGLOBAL)0x0) {
        local_38 = FUN_10008960();
      }
      else {
        local_58 = SizeofResource(local_4c,local_50);
        local_5c = local_54;
        if (local_58 <= local_58 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10013040(&local_464,local_58 + 1);
          uVar5 = FUN_1000949f();
          return uVar5;
        }
        local_38 = 0x8007000e;
      }
    }
  }
  if (local_4c != (HMODULE)0x0) {
    FreeLibrary(local_4c);
  }
  DStack_474 = local_38;
  local_8 = (uint)local_8._1_3_ << 8;
  puVar3 = auStack_460;
  if (local_464 != puVar3) {
    FUN_100148f0(&local_464);
    puVar3 = extraout_EDX;
  }
  local_8 = 0xffffffff;
  while (_Memory = local_30, DVar1 = DStack_474, local_30 != (undefined4 *)0x0) {
    local_488[0] = local_30;
    local_30 = (undefined4 *)*local_30;
    free(_Memory);
    puVar3 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100095e8);
  ExceptionList = pvStack_10;
  return CONCAT44(puVar3,DVar1);
}



// Function: Catch@10009492 at 10009492

undefined4 Catch_10009492(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x100094a6;
}



// Function: FUN_1000949f at 1000949f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000949f(void)

{
  int iVar1;
  DWORD DVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int unaff_EBP;
  undefined8 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + -0x460) == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x478) = *(undefined4 *)(unaff_EBP + -0x460);
    iVar1 = MultiByteToWideChar(3,0,*(LPCSTR *)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x54),
                                *(LPWSTR *)(unaff_EBP + -0x478),*(int *)(unaff_EBP + -0x54));
    *(int *)(unaff_EBP + -0x46c) = iVar1;
    if (*(int *)(unaff_EBP + -0x46c) == 0) {
      DVar2 = FUN_10008960();
      *(DWORD *)(unaff_EBP + -0x34) = DVar2;
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x460) + *(int *)(unaff_EBP + -0x46c) * 2) = 0;
      *(undefined4 *)(unaff_EBP + -0x47c) = *(undefined4 *)(unaff_EBP + -0x460);
      uVar3 = FUN_10009770((int *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x47c),
                           (LPCWSTR)*(undefined4 *)(unaff_EBP + -0x47c),*(int *)(unaff_EBP + 0x14));
      *(int *)(unaff_EBP + -0x34) = (int)uVar3;
    }
  }
  if (*(int *)(unaff_EBP + -0x48) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP + -0x48));
  }
  *(undefined4 *)(unaff_EBP + -0x470) = *(undefined4 *)(unaff_EBP + -0x34);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  iVar1 = unaff_EBP + -0x45c;
  if (*(int *)(unaff_EBP + -0x460) != iVar1) {
    FUN_100148f0((undefined4 *)(unaff_EBP + -0x460));
    iVar1 = extraout_EDX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  while (*(int *)(unaff_EBP + -0x2c) != 0) {
    *(undefined4 *)(unaff_EBP + -0x484) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x2c) = **(undefined4 **)(unaff_EBP + -0x2c);
    free(*(void **)(unaff_EBP + -0x484));
    iVar1 = extraout_EDX_00;
  }
  uVar4 = *(undefined4 *)(unaff_EBP + -0x470);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100095e8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(iVar1,uVar4);
}



// Function: FUN_10009640 at 10009640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009640(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  LPCWSTR _Memory;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  LPCWSTR *ppWVar3;
  undefined8 uVar4;
  LPCWSTR local_38 [4];
  LPCWSTR local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  ppWVar3 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppWVar3 = (LPCWSTR)0xcccccccc;
    ppWVar3 = ppWVar3 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  local_38[2] = param_4;
  ExceptionList = &local_10;
  uVar4 = FUN_10009340(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (_Memory = local_28, uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20),
        local_38[1] = (LPCWSTR)uVar4, local_28 != (LPCWSTR)0x0) {
    local_38[0] = local_28;
    local_28 = *(LPCWSTR *)local_28;
    free(_Memory);
    uVar4 = CONCAT44(extraout_EDX,local_38[1]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009704);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_38[1]);
}



// Function: FUN_10009730 at 10009730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10009730(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10008ee0((int *)(param_1 + 4));
  return uVar1;
}



// Function: FUN_10009770 at 10009770

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10009770(int *param_1,undefined4 param_2,LPCWSTR param_3,int param_4)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_2038 [6];
  int local_2020;
  HKEY local_201c;
  LPVOID local_2018;
  int local_2014;
  WCHAR local_200c [4098];
  int *local_8;
  
  puVar2 = local_2038;
  for (iVar1 = 0x80d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2014 = 0;
  local_2018 = (LPVOID)0x0;
  local_8 = param_1;
  uVar3 = FUN_10009d70(param_1,param_2,param_3,&local_2018);
  local_2014 = (int)uVar3;
  if (-1 < local_2014) {
    *local_8 = (int)local_2018;
    while( true ) {
      if ((*(short *)*local_8 == 0) ||
         (local_2014 = FUN_10009aa0(local_8,local_200c), local_2014 < 0)) goto LAB_1000991f;
      local_201c = (HKEY)FUN_10009980(local_200c);
      if (local_201c == (HKEY)0x0) break;
      local_2014 = FUN_10009aa0(local_8,local_200c);
      if (local_2014 < 0) goto LAB_1000991f;
      if (local_200c[0] != L'{') {
        local_2014 = -0x7ffdfff7;
        goto LAB_1000991f;
      }
      if (param_4 == 0) {
        uVar3 = FUN_1000aa40(local_8,local_200c,local_201c,0,0);
        local_2014 = (int)uVar3;
        if (local_2014 < 0) goto LAB_1000991f;
      }
      else {
        local_2020 = *local_8;
        uVar3 = FUN_1000aa40(local_8,local_200c,local_201c,param_4,0);
        local_2014 = (int)uVar3;
        if (local_2014 < 0) {
          *local_8 = local_2020;
          FUN_1000aa40(local_8,local_200c,local_201c,0,0);
          goto LAB_1000991f;
        }
      }
      FUN_100099f0(local_8);
    }
    local_2014 = -0x7ffdfff7;
LAB_1000991f:
    CoTaskMemFree(local_2018);
    uVar3 = CONCAT44(extraout_EDX,local_2014);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009964);
  return uVar3;
}



// Function: FUN_10009980 at 10009980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __cdecl FUN_10009980(LPCWSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10026a78)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_10026a7c + local_8 * 8);
}



// Function: FUN_100099f0 at 100099f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100099f0(undefined4 *param_1)

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



// Function: FUN_10009aa0 at 10009aa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10009aa0(void *this,undefined2 *param_1)

{
  undefined4 uVar1;
  LPWSTR pWVar2;
  int iVar3;
  int *piVar4;
  int local_34 [4];
  int local_24;
  int local_20;
  undefined2 *local_1c;
  int local_18;
  int local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  int *local_8;
  
  piVar4 = local_34;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = -0x33333334;
    piVar4 = piVar4 + 1;
  }
  local_8 = (int *)this;
  FUN_100099f0((undefined4 *)this);
  if (*(short *)*local_8 == 0) {
    uVar1 = 0x80020009;
  }
  else {
    local_c = param_1;
    if (*(short *)*local_8 == 0x27) {
      pWVar2 = CharNextW((LPCWSTR)*local_8);
      *local_8 = (int)pWVar2;
      while (*(short *)*local_8 != 0) {
        if ((*(short *)*local_8 == 0x27) &&
           (pWVar2 = CharNextW((LPCWSTR)*local_8), *pWVar2 != L'\'')) {
          local_34[1] = 1;
        }
        else {
          local_34[1] = 0;
        }
        if (local_34[1] != 0) break;
        if (*(short *)*local_8 == 0x27) {
          pWVar2 = CharNextW((LPCWSTR)*local_8);
          *local_8 = (int)pWVar2;
        }
        local_10 = (undefined2 *)*local_8;
        pWVar2 = CharNextW((LPCWSTR)*local_8);
        *local_8 = (int)pWVar2;
        local_14 = *local_8 - (int)local_10 >> 1;
        if (local_c + 0x1000 <= param_1 + local_14 + 1) {
          return 0x80020009;
        }
        for (local_18 = 0; local_18 < local_14; local_18 = local_18 + 1) {
          *param_1 = *local_10;
          param_1 = param_1 + 1;
          local_10 = local_10 + 1;
        }
      }
      if (*(short *)*local_8 == 0) {
        return 0x80020009;
      }
      *param_1 = 0;
      pWVar2 = CharNextW((LPCWSTR)*local_8);
      *local_8 = (int)pWVar2;
    }
    else {
      while (*(short *)*local_8 != 0) {
        local_34[0] = *(ushort *)*local_8 - 9;
        switch(*(ushort *)*local_8) {
        case 9:
        case 10:
        case 0xd:
        case 0x20:
          local_34[2] = 1;
          break;
        default:
          local_34[2] = 0;
        }
        if (local_34[2] != 0) break;
        local_1c = (undefined2 *)*local_8;
        pWVar2 = CharNextW((LPCWSTR)*local_8);
        *local_8 = (int)pWVar2;
        local_20 = *local_8 - (int)local_1c >> 1;
        if (local_c + 0x1000 <= param_1 + local_20 + 1) {
          return 0x80020009;
        }
        for (local_24 = 0; local_24 < local_20; local_24 = local_24 + 1) {
          *param_1 = *local_1c;
          param_1 = param_1 + 1;
          local_1c = local_1c + 1;
        }
      }
      *param_1 = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10009d70 at 10009d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10009d70(int *param_1,undefined4 param_2,LPCWSTR param_3,undefined4 *param_4)

{
  LPVOID pvVar1;
  LPWSTR pWVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  errno_t *peVar5;
  undefined8 uVar6;
  errno_t local_11c;
  int local_118;
  LPVOID local_114;
  void *local_110;
  undefined4 local_10c;
  wchar_t *local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  void *local_e8;
  wchar_t *local_d8;
  errno_t local_d4;
  errno_t local_d0;
  LPCWSTR local_cc;
  LPCWSTR local_c8;
  void *local_c4;
  undefined4 local_c0;
  void *local_bc;
  undefined4 local_b8;
  wchar_t *local_b4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  wchar_t local_94 [34];
  rsize_t local_50;
  LPCWSTR local_4c;
  wchar_t *local_48;
  wchar_t *local_44;
  wchar_t *local_40;
  char local_3a;
  char local_39;
  int local_38;
  char local_31;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  LPVOID local_20;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e578;
  local_10 = ExceptionList;
  peVar5 = &local_11c;
  for (iVar4 = 0x43; iVar4 != 0; iVar4 = iVar4 + -1) {
    *peVar5 = -0x33333334;
    peVar5 = peVar5 + 1;
  }
  local_14 = param_1;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (undefined4 *)0x0)) {
    iVar4 = -0x7fffbffd;
    ExceptionList = &local_10;
  }
  else {
    ExceptionList = &local_10;
    *param_4 = 0;
    local_18 = lstrlenW(param_3);
    local_18 = local_18 << 1;
    FUN_1000a4d0(&local_28,local_18);
    local_8 = 0;
    if (local_20 == (LPVOID)0x0) {
      local_a0 = -0x7ff8fff2;
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
      iVar4 = local_a0;
      param_2 = extraout_EDX;
    }
    else {
      *local_14 = (int)param_3;
      local_31 = '\0';
      if (&stack0x00000000 == (undefined1 *)0x31) {
        local_30 = -0x7fffbffd;
      }
      else {
        local_31 = DAT_1002fcd0;
        local_30 = 0;
      }
      if (local_30 < 0) {
        local_a4 = local_30;
        local_8 = 0xffffffff;
        CoTaskMemFree(local_20);
        iVar4 = local_a4;
        param_2 = extraout_EDX_00;
      }
      else {
        local_38 = 0;
        local_39 = '\0';
        local_3a = '\0';
        while (*(short *)*local_14 != 0) {
          if (local_31 == '\x01') {
            local_40 = L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses";
            local_44 = L"\r\n\t}\r\n}\r\n";
            if (local_38 == 0) {
              local_48 = (wchar_t *)0x0;
              local_b4 = (wchar_t *)*local_14;
              local_48 = wcsstr(local_b4,L"HKCR");
              if ((local_48 != (wchar_t *)0x0) && (local_48 == (wchar_t *)*local_14)) {
                pWVar2 = CharNextW((LPCWSTR)*local_14);
                *local_14 = (int)pWVar2;
                pWVar2 = CharNextW((LPCWSTR)*local_14);
                *local_14 = (int)pWVar2;
                pWVar2 = CharNextW((LPCWSTR)*local_14);
                *local_14 = (int)pWVar2;
                pWVar2 = CharNextW((LPCWSTR)*local_14);
                *local_14 = (int)pWVar2;
                uVar6 = FUN_1000a8f0(&local_28,local_40,local_40);
                if ((int)uVar6 == 0) {
                  local_30 = -0x7ff8fff2;
                  break;
                }
                local_39 = '\x01';
              }
            }
            if (*(short *)*local_14 == 0x27) {
              if (local_3a == '\0') {
                local_3a = '\x01';
              }
              else {
                if ((*(short *)*local_14 == 0x27) &&
                   (pWVar2 = CharNextW((LPCWSTR)*local_14), *pWVar2 != L'\'')) {
                  local_118 = 1;
                }
                else {
                  local_118 = 0;
                }
                if (local_118 == 0) {
                  pWVar2 = CharNextW((LPCWSTR)*local_14);
                  *local_14 = (int)pWVar2;
                  local_bc = (void *)*local_14;
                  local_b8 = 1;
                  iVar4 = FUN_1000a630(&local_28,local_bc,1);
                  if (iVar4 == 0) {
                    local_30 = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_3a = '\0';
                }
              }
            }
            if ((local_3a == '\0') && (*(short *)*local_14 == 0x7b)) {
              local_38 = local_38 + 1;
            }
            if ((((local_3a == '\0') && (*(short *)*local_14 == 0x7d)) &&
                (local_38 = local_38 + -1, local_38 == 0)) && (local_39 == '\x01')) {
              uVar6 = FUN_1000a8f0(&local_28,local_44,local_44);
              if ((int)uVar6 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
              local_39 = '\0';
            }
          }
          if (*(short *)*local_14 == 0x25) {
            pWVar2 = CharNextW((LPCWSTR)*local_14);
            *local_14 = (int)pWVar2;
            if (*(short *)*local_14 == 0x25) {
              local_c4 = (void *)*local_14;
              local_c0 = 1;
              iVar4 = FUN_1000a630(&local_28,local_c4,1);
              if (iVar4 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_cc = (LPCWSTR)*local_14;
              local_c8 = (LPCWSTR)0x0;
              if (local_cc == (LPCWSTR)0x0) {
                local_4c = (LPCWSTR)0x0;
              }
              else {
                for (; *local_cc != L'\0'; local_cc = CharNextW(local_cc)) {
                  if (*local_cc == L'%') {
                    local_c8 = local_cc;
                    break;
                  }
                }
                local_4c = local_c8;
              }
              local_c8 = local_4c;
              if (local_4c == (LPCWSTR)0x0) {
                local_30 = -0x7ffdfff7;
                break;
              }
              if (0x1f < (int)local_4c - *local_14 >> 1) {
                local_30 = -0x7fffbffb;
                break;
              }
              local_50 = (int)local_4c - *local_14 >> 1;
              local_d8 = (wchar_t *)*local_14;
              local_11c = wcsncpy_s(local_94,0x20,local_d8,local_50);
              local_d0 = local_11c;
              switch(local_11c) {
              case 0:
              case 0x50:
                break;
              default:
                FUN_10001920(0x80004005);
                break;
              case 0xc:
                FUN_10001920(0x8007000e);
                break;
              case 0x16:
              case 0x22:
                FUN_10001920(0x80070057);
              }
              local_d4 = local_d0;
              local_f8 = local_94;
              local_f4 = local_14[1];
              local_e8 = (void *)(local_f4 + 4);
              local_ec = FUN_10014850(local_e8,&local_f8);
              if (local_ec == -1) {
                local_f0 = 0;
              }
              else {
                piVar3 = (int *)FUN_1000fe00(local_e8,local_ec);
                local_f0 = *piVar3;
              }
              local_9c = local_f0;
              if (local_f0 == 0) {
                local_30 = -0x7ffdfff7;
                break;
              }
              uVar6 = FUN_1000a8f0(&local_28,local_f0,(LPCWSTR)local_f0);
              if ((int)uVar6 == 0) {
                local_30 = -0x7ff8fff2;
                break;
              }
              while ((LPCWSTR)*local_14 != local_4c) {
                pWVar2 = CharNextW((LPCWSTR)*local_14);
                *local_14 = (int)pWVar2;
              }
            }
          }
          else {
            local_110 = (void *)*local_14;
            local_10c = 1;
            iVar4 = FUN_1000a630(&local_28,local_110,1);
            if (iVar4 == 0) {
              local_30 = -0x7ff8fff2;
              break;
            }
          }
          pWVar2 = CharNextW((LPCWSTR)*local_14);
          *local_14 = (int)pWVar2;
        }
        pvVar1 = local_20;
        if (-1 < local_30) {
          local_114 = local_20;
          local_20 = (LPVOID)0x0;
          local_28 = 0;
          local_24 = 0;
          *param_4 = pvVar1;
        }
        local_a8 = local_30;
        local_8 = 0xffffffff;
        CoTaskMemFree(local_20);
        iVar4 = local_a8;
        param_2 = extraout_EDX_01;
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a444);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar4);
}



// Function: FUN_1000a4d0 at 1000a4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000a4d0(void *this,int param_1)

{
  LPVOID pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = FUN_1000a540(*(uint *)((int)this + 4),2);
  *(LPVOID *)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined2 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a540 at 1000a540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000a585) */

LPVOID __cdecl FUN_1000a540(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_10 = (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  if (local_10 == 0) {
    local_14 = (SIZE_T)((ulonglong)param_1 * (ulonglong)param_2);
    local_c = local_14;
    local_8 = 0;
  }
  else {
    local_8 = -0x7ff8fdea;
  }
  if (local_8 < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemAlloc(local_c);
  }
  return pvVar1;
}



// Function: FUN_1000a5f0 at 1000a5f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a5f0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_1000a630 at 1000a630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000a630(void *this,void *param_1,int param_2)

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
      pvVar3 = FUN_1000a840(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),2);
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
        FUN_10001920(0x80004005);
        break;
      case 0xc:
        FUN_10001920(0x8007000e);
        break;
      case 0x16:
      case 0x22:
        FUN_10001920(0x80070057);
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



// Function: FUN_1000a840 at 1000a840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000a885) */

LPVOID __cdecl FUN_1000a840(LPVOID param_1,uint param_2,uint param_3)

{
  LPVOID pvVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_10 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_10 == 0) {
    local_14 = (SIZE_T)((ulonglong)param_2 * (ulonglong)param_3);
    local_c = local_14;
    local_8 = 0;
  }
  else {
    local_8 = -0x7ff8fdea;
  }
  if (local_8 < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemRealloc(param_1,local_c);
  }
  return pvVar1;
}



// Function: FUN_1000a8f0 at 1000a8f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000a8f0(void *param_1,undefined4 param_2,LPCWSTR param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 **ppuVar4;
  undefined4 *local_50 [4];
  undefined4 *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  LPCWSTR local_34;
  undefined4 *local_2c;
  undefined4 local_1c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e598;
  local_10 = ExceptionList;
  ppuVar4 = local_50;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  local_14 = param_1;
  if (param_3 == (LPCWSTR)0x0) {
    uVar2 = 0;
    ExceptionList = &local_10;
  }
  else {
    local_1c = 3;
    local_2c = (undefined4 *)0x0;
    local_8 = 0;
    local_34 = param_3;
    if (param_3 == (LPCWSTR)0x0) {
      local_38 = 0;
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      while (puVar1 = local_2c, uVar2 = local_38, local_2c != (undefined4 *)0x0) {
        local_40 = local_2c;
        local_2c = (undefined4 *)*local_2c;
        free(puVar1);
        param_2 = extraout_EDX;
      }
    }
    else {
      ExceptionList = &local_10;
      iVar3 = lstrlenW(param_3);
      local_3c = FUN_1000a630(local_14,local_34,iVar3);
      local_8 = 0xffffffff;
      param_2 = extraout_EDX_00;
      while (puVar1 = local_2c, uVar2 = local_3c, local_2c != (undefined4 *)0x0) {
        local_50[0] = local_2c;
        local_2c = (undefined4 *)*local_2c;
        free(puVar1);
        param_2 = extraout_EDX_01;
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000aa14);
  ExceptionList = local_10;
  return CONCAT44(param_2,uVar2);
}



// Function: FUN_1000aa40 at 1000aa40

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_1000aa40(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  LPCWSTR pWVar1;
  errno_t eVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  LPCWSTR extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 uVar4;
  HKEY *ppHVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  HKEY local_22f0 [4];
  HKEY local_22e0;
  int local_22dc;
  int local_22d8;
  LPCWSTR local_22d4;
  LPCWSTR local_22d0;
  LPCWSTR local_22cc;
  int local_22c8;
  int local_22c4;
  int local_22c0;
  int local_22bc;
  int local_22b8;
  int local_22b4;
  int local_22b0;
  int local_22ac;
  HKEY local_22a4;
  undefined4 local_22a0;
  undefined4 local_229c;
  int local_2294;
  HKEY local_228c;
  undefined4 local_2288;
  undefined4 local_2284;
  HKEY local_2278;
  undefined4 local_2274;
  undefined4 local_2270;
  WCHAR local_2264 [4100];
  HKEY local_25c;
  undefined4 local_258;
  undefined4 local_254;
  uint local_24c;
  int local_248;
  int local_244;
  int local_240;
  wchar_t local_238 [262];
  ulong local_2c;
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e5e4;
  local_10 = ExceptionList;
  ppHVar5 = local_22f0;
  for (iVar3 = 0x8b8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppHVar5 = (HKEY)0xcccccccc;
    ppHVar5 = ppHVar5 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_240 = 1;
  local_244 = param_4;
  local_248 = 0;
  ExceptionList = &local_10;
  local_14 = (undefined4 *)this;
  local_248 = FUN_10009aa0(this,param_1);
  if (-1 < local_248) {
LAB_1000aaf5:
    if (*param_1 == L'}') goto LAB_1000b4f4;
    local_240 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_24c = (uint)(iVar3 == 0);
    iVar3 = lstrcmpiW(param_1,L"ForceRemove");
    local_22f0[0] = (HKEY)0x1000ab4f;
    if ((iVar3 == 0) || (local_24c != 0)) {
      local_248 = FUN_10009aa0(local_14,param_1);
      if (local_248 < 0) goto LAB_1000b4f4;
      if (param_3 == 0) goto LAB_1000adbc;
      local_25c = (HKEY)0x0;
      local_258 = 0;
      local_254 = 0;
      local_8._0_1_ = 1;
      local_22d0 = param_1;
      local_22cc = (LPCWSTR)0x0;
      if (param_1 != (LPCWSTR)0x0) {
        while (*local_22d0 != L'\0') {
          if (*local_22d0 == L'\\') {
            local_22cc = local_22d0;
            break;
          }
          local_22d0 = CharNextW(local_22d0);
          local_22f0[0] = (HKEY)0x1000ac1a;
        }
      }
      local_22d4 = local_22cc;
      if (local_22cc == (LPCWSTR)0x0) {
        for (local_22d8 = 0; local_22d8 < 0xc; local_22d8 = local_22d8 + 1) {
          iVar3 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10026530)[local_22d8]);
          if (iVar3 == 0) {
            local_22dc = 0;
            goto LAB_1000accb;
          }
        }
        local_22dc = 1;
LAB_1000accb:
        if (local_22dc != 0) {
          local_25c = param_2;
          local_258 = 0;
          local_254 = 0;
          FUN_1000bd90(&local_25c,param_1);
          local_22e0 = local_25c;
          local_25c = (HKEY)0x0;
          local_258 = 0;
          local_254 = 0;
        }
        if (local_24c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
          goto LAB_1000adbc;
        }
        local_248 = FUN_10009aa0(local_14,param_1);
        if (local_248 < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
        }
        else {
          uVar6 = FUN_1000cb90(local_14,extraout_EDX_01,param_1);
          local_248 = (int)uVar6;
          if (-1 < local_248) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::CRegKey::Close((CRegKey *)&local_25c);
            goto LAB_1000b482;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
        }
        goto LAB_1000b4f4;
      }
      local_22b0 = -0x7ffdfff7;
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_25c);
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_24);
      iVar3 = local_22b0;
      uVar4 = extraout_EDX_00;
      goto LAB_1000b515;
    }
LAB_1000adbc:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_240 = 0;
      local_248 = FUN_10009aa0(local_14,param_1);
      if (local_248 < 0) goto LAB_1000b4f4;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 == 0) {
      local_248 = FUN_10009aa0(local_14,local_2264);
      if ((local_248 < 0) || (local_248 = FUN_10009aa0(local_14,param_1), local_248 < 0))
      goto LAB_1000b4f4;
      if (*param_1 != L'=') {
        local_22b4 = -0x7ffdfff7;
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22b4;
        uVar4 = extraout_EDX_02;
        goto LAB_1000b515;
      }
      if (param_3 != 0) {
        local_8._0_1_ = 2;
        local_2278 = param_2;
        local_2274 = 0;
        local_2270 = 0;
        uVar6 = FUN_1000c080(local_14,&local_2278,local_2264,param_1);
        local_248 = (int)uVar6;
        local_22f0[3] = local_2278;
        local_2278 = (HKEY)0x0;
        local_2274 = 0;
        local_2270 = 0;
        if (-1 < local_248) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2278);
          goto LAB_1000b482;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        local_22b8 = local_248;
        ATL::CRegKey::Close((CRegKey *)&local_2278);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22b8;
        uVar4 = extraout_EDX_03;
        goto LAB_1000b515;
      }
      pWVar1 = param_1;
      if ((param_4 == 0) && (local_240 != 0)) {
        local_228c = (HKEY)0x0;
        local_2288 = 0;
        local_2284 = 0;
        local_8._0_1_ = 3;
        local_2c = FUN_1000bbb0(&local_228c,param_2,(LPCWSTR)0x0,0x20006);
        if (local_2c != 0) {
          local_248 = _HRESULT_FROM_WIN32(local_2c);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_228c);
          goto LAB_1000b4f4;
        }
        local_2c = RegDeleteValueW(local_228c,local_2264);
        if ((local_2c != 0) && (local_2c != 2)) {
          local_248 = _HRESULT_FROM_WIN32(local_2c);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_228c);
          goto LAB_1000b4f4;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_228c);
        pWVar1 = extraout_EDX_04;
      }
      uVar6 = FUN_1000cb90(local_14,pWVar1,param_1);
      local_248 = (int)uVar6;
joined_r0x1000b08c:
      if (local_248 < 0) goto LAB_1000b4f4;
      goto LAB_1000aaf5;
    }
    pWVar1 = FUN_1000c010(param_1,L'\\');
    if (pWVar1 != (LPCWSTR)0x0) {
      local_22bc = -0x7ffdfff7;
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_24);
      iVar3 = local_22bc;
      uVar4 = extraout_EDX_05;
      goto LAB_1000b515;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_2c = FUN_1000bbb0(&local_24,param_2,param_1,0x20019);
      }
      else {
        local_2c = 2;
      }
      if (local_2c != 0) {
        param_4 = 1;
      }
      eVar2 = wcsncpy_s(local_238,0x104,param_1,0xffffffff);
      ATL::AtlCrtErrorCheck(eVar2);
      local_248 = FUN_10009aa0(local_14,param_1);
      if (local_248 < 0) goto LAB_1000b4f4;
      uVar6 = FUN_1000cb90(local_14,param_1,param_1);
      local_248 = (int)uVar6;
      if (local_248 < 0) goto LAB_1000b4f4;
      if ((*param_1 == L'{') && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
        uVar6 = FUN_1000aa40(local_14,param_1,local_24,0,param_4);
        local_248 = (int)uVar6;
        if (((local_248 < 0) && (param_4 == 0)) ||
           (local_248 = FUN_10009aa0(local_14,param_1), local_248 < 0)) goto LAB_1000b4f4;
      }
      param_4 = local_244;
      if (local_2c == 2) goto LAB_1000aaf5;
      if (local_2c != 0) {
        if (local_244 == 0) goto LAB_1000b2f9;
        goto LAB_1000aaf5;
      }
      if (local_244 != 0) {
        local_22f0[2] = local_24;
        uVar6 = FUN_1000caf0(local_24);
        if ((int)uVar6 != 0) {
          iVar3 = FUN_1000ca80(local_238);
          if ((iVar3 != 0) && (local_240 != 0)) {
            FUN_1000bd90(&local_24,local_238);
          }
          goto LAB_1000aaf5;
        }
      }
      local_22f0[1] = local_24;
      uVar6 = FUN_1000caf0(local_24);
      local_2294 = (int)uVar6;
      local_2c = ATL::CRegKey::Close((CRegKey *)&local_24);
      if (local_2c != 0) {
        local_22c4 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22c4;
        uVar4 = extraout_EDX_07;
        goto LAB_1000b515;
      }
      if ((local_240 != 0) && (local_2294 == 0)) {
        local_22a4 = (HKEY)0x0;
        local_22a0 = 0;
        local_229c = 0;
        local_8._0_1_ = 4;
        FUN_1000b760(&local_22a4,param_2);
        local_2c = FUN_1000b7a0(&local_22a4,local_238);
        local_22f0[0] = local_22a4;
        local_22a4 = (HKEY)0x0;
        local_22a0 = 0;
        local_229c = 0;
        if (local_2c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_22a4);
          goto LAB_1000b482;
        }
        local_248 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_22a4);
        goto LAB_1000b4f4;
      }
    }
    else {
      local_2c = FUN_1000bbb0(&local_24,param_2,param_1,0x2001f);
      if (((local_2c != 0) &&
          (local_2c = FUN_1000bbb0(&local_24,param_2,param_1,0x20019), local_2c != 0)) &&
         (local_2c = FUN_1000b9d0(&local_24,param_2,param_1,(LPWSTR)0x0,0,0x2001f,
                                  (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_2c != 0)) {
        local_22c0 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22c0;
        uVar4 = extraout_EDX_06;
        goto LAB_1000b515;
      }
      local_248 = FUN_10009aa0(local_14,param_1);
      if (local_248 < 0) goto LAB_1000b4f4;
      if (*param_1 == L'=') {
        uVar6 = FUN_1000c080(local_14,&local_24,(LPCWSTR)0x0,param_1);
        local_248 = (int)uVar6;
        if (local_248 < 0) goto LAB_1000b4f4;
      }
    }
LAB_1000b482:
    if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
      uVar6 = FUN_1000aa40(local_14,param_1,local_24,param_3,0);
      local_248 = (int)uVar6;
      if (-1 < local_248) {
        local_248 = FUN_10009aa0(local_14,param_1);
        goto joined_r0x1000b08c;
      }
      goto LAB_1000b4f4;
    }
    goto LAB_1000aaf5;
  }
  local_8 = 0xffffffff;
  local_22ac = local_248;
  ATL::CRegKey::Close((CRegKey *)&local_24);
  iVar3 = local_22ac;
  uVar4 = extraout_EDX;
LAB_1000b515:
  uVar7 = (undefined2)uVar4;
  uVar8 = (undefined2)((uint)uVar4 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b548);
  ExceptionList = local_10;
  return CONCAT26(uVar8,CONCAT24(uVar7,iVar3));
LAB_1000b2f9:
  local_248 = _HRESULT_FROM_WIN32(local_2c);
LAB_1000b4f4:
  local_22c8 = local_248;
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_24);
  iVar3 = local_22c8;
  uVar4 = extraout_EDX_08;
  goto LAB_1000b515;
}



// Function: AtlCrtErrorCheck at 1000b5e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10001920(0x80004005);
    break;
  case 0xc:
    FUN_10001920(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10001920(0x80070057);
  }
  return param_1;
}



// Function: _HRESULT_FROM_WIN32 at 1000b6b0

/* Library Function - Single Match
    _HRESULT_FROM_WIN32
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

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



// Function: FUN_1000b6f0 at 1000b6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000b6f0(int *param_1)

{
  if (*param_1 != 0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_1000b760 at 1000b760

void __thiscall FUN_1000b760(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_1000b7a0 at 1000b7a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000b7a0(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_100302fc == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_100302f8 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_100302fc = '\x01';
    }
    if (DAT_100302f8 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_100302f8)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_1000b890(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_1000b890 at 1000b890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000b890(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    uVar4 = 0x1000b8cb;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0,0x1000b8f3,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: Close at 1000b960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

long __thiscall ATL::CRegKey::Close(CRegKey *this)

{
  LSTATUS local_c;
  
  local_c = 0;
  if (*(int *)this != 0) {
    local_c = RegCloseKey(*(HKEY *)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return local_c;
}



// Function: FUN_1000b9d0 at 1000b9d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000b9d0(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_2c;
  LSTATUS local_28;
  int local_24;
  int *local_20;
  FARPROC local_1c;
  HMODULE local_18;
  LSTATUS local_14;
  HKEY local_10;
  DWORD local_c;
  int *local_8;
  
  piVar2 = &local_2c;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  local_10 = (HKEY)0x0;
  local_8 = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,&local_c)
    ;
    goto LAB_1000bb1e;
  }
  local_20 = *(int **)((int)this + 8);
  local_2c = local_24;
  if (*local_20 == 0) {
    if (local_20[1] != 0) {
      local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,
                                 &local_c);
      goto LAB_1000bb1e;
    }
  }
  else {
    local_18 = GetModuleHandleW(L"Advapi32.dll");
    uVar3 = 0x1000ba2f;
    if (local_18 == (HMODULE)0x0) {
      local_2c = 1;
      goto LAB_1000bb1e;
    }
    local_1c = GetProcAddress(local_18,"RegCreateKeyTransactedW");
    if (local_1c != (FARPROC)0x0) {
      local_2c = (*local_1c)(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,&local_c,
                             *local_20,0,0x1000ba5c,uVar3);
      goto LAB_1000bb1e;
    }
  }
  local_2c = 1;
LAB_1000bb1e:
  local_14 = local_2c;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_c;
  }
  if (local_2c == 0) {
    local_28 = 0;
    if (*local_8 != 0) {
      local_28 = RegCloseKey((HKEY)*local_8);
      *local_8 = 0;
    }
    local_8[1] = 0;
    local_14 = local_28;
    *local_8 = (int)local_10;
    local_8[1] = param_5 & 0x300;
  }
  return local_14;
}



// Function: FUN_1000bbb0 at 1000bbb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000bbb0(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int local_18;
  LSTATUS local_14;
  LSTATUS local_10;
  HKEY local_c;
  int *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_18 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_c);
  }
  else {
    local_18 = FUN_1000bcb0(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_c);
  }
  local_10 = local_18;
  if (local_18 == 0) {
    local_14 = 0;
    if (*local_8 != 0) {
      local_14 = RegCloseKey((HKEY)*local_8);
      *local_8 = 0;
    }
    local_8[1] = 0;
    local_10 = local_14;
    *local_8 = (int)local_c;
    local_8[1] = param_3 & 0x300;
  }
  return local_10;
}



// Function: FUN_1000bcb0 at 1000bcb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000bcb0(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExW(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    uVar4 = 0x1000bceb;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0,0x1000bd16,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000bd90 at 1000bd90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_1000bd90(void *this,LPCWSTR param_1)

{
  LSTATUS LVar1;
  int iVar2;
  LSTATUS extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  PFILETIME unaff_EDI;
  LSTATUS *pLVar4;
  undefined8 uVar5;
  HKEY hKey;
  LSTATUS local_264 [5];
  int local_250;
  LSTATUS local_24c;
  WCHAR local_244 [258];
  WCHAR local_40 [4];
  DWORD local_38 [3];
  LSTATUS local_2c;
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e5f8;
  local_10 = ExceptionList;
  pLVar4 = local_264;
  for (iVar2 = 0x95; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pLVar4 = -0x33333334;
    pLVar4 = pLVar4 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  local_14 = this;
  LVar1 = FUN_1000bbb0(&local_24,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  local_2c = LVar1;
  if (LVar1 == 0) {
    do {
      local_40[0] = L'Ā';
      local_40[1] = L'\0';
      LVar1 = RegEnumKeyExW((HKEY)0x0,(DWORD)local_244,local_40,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPWSTR)0x0,local_38,unaff_EDI);
      hKey = (HKEY)0x1000be8e;
      if (LVar1 != 0) {
        local_264[1] = 0;
        if (local_24 != (HKEY)0x0) {
          local_264[1] = RegCloseKey(local_24);
          hKey = (HKEY)0x1000bf2b;
          local_24 = (HKEY)0x0;
        }
        local_20 = 0;
        uVar5 = FUN_1000b7a0(local_14,param_1);
        local_264[4] = (LSTATUS)uVar5;
        local_8 = 0xffffffff;
        local_264[0] = 0;
        if (local_24 != (HKEY)0x0) {
          local_264[0] = RegCloseKey(hKey);
          uVar5 = CONCAT44(extraout_EDX_01,local_264[4]);
          local_24 = (HKEY)0x0;
        }
        local_264[4] = (LSTATUS)uVar5;
        uVar5 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),local_250);
        iVar2 = local_264[4];
        goto LAB_1000bf95;
      }
      uVar5 = FUN_1000bd90(&local_24,local_244);
      local_2c = (LSTATUS)uVar5;
    } while (local_2c == 0);
    local_8 = 0xffffffff;
    local_264[2] = 0;
    if (local_24 != (HKEY)0x0) {
      local_250 = local_2c;
      local_264[2] = RegCloseKey(local_24);
      uVar5 = CONCAT44(extraout_EDX_00,local_250);
      local_24 = (HKEY)0x0;
    }
    local_250 = (int)uVar5;
    iVar2 = local_250;
  }
  else {
    local_8 = 0xffffffff;
    local_264[3] = 0;
    local_24c = LVar1;
    if (local_24 != (HKEY)0x0) {
      local_264[3] = RegCloseKey(local_24);
      local_24 = (HKEY)0x0;
      LVar1 = extraout_EDX;
    }
    uVar5 = CONCAT44(LVar1,local_250);
    iVar2 = local_24c;
  }
LAB_1000bf95:
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  local_250 = (int)uVar5;
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000bfc8);
  ExceptionList = local_10;
  return CONCAT44(uVar3,iVar2);
}



// Function: FUN_1000c010 at 1000c010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCWSTR __cdecl FUN_1000c010(LPWSTR param_1,WCHAR param_2)

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



// Function: FUN_1000c080 at 1000c080

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall
FUN_1000c080(void *this,undefined4 *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  undefined4 *_Memory;
  LPWSTR pWVar1;
  int iVar2;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint uVar3;
  undefined4 extraout_EDX_02;
  uint extraout_EDX_03;
  uint extraout_EDX_04;
  uint *puVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  uint local_22ac [4];
  undefined4 *puStack_229c;
  undefined4 auStack_2298 [2];
  uint local_2290;
  undefined4 auStack_2280 [66];
  uint uStack_2178;
  uint uStack_2174;
  WCHAR *pWStack_2170;
  undefined4 *puStack_2168;
  undefined4 uStack_2158;
  undefined4 auStack_2150 [5];
  undefined4 local_213c [66];
  uint local_2034;
  undefined4 local_2030;
  ulong local_202c;
  ushort local_2028 [4];
  WCHAR local_2020 [4098];
  int local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e631;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffdd48;
  puVar4 = local_22ac;
  for (iVar2 = 0x8a6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_2028[0] = 0;
  local_202c = 0;
  local_2030 = 0;
  ExceptionList = &pvStack_10;
  local_18 = (undefined4 *)this;
  iVar2 = FUN_10009aa0(this,local_2020);
  uVar3 = extraout_EDX;
  local_1c = iVar2;
  if (-1 < iVar2) {
    iVar2 = FUN_1000c850(local_2020,local_2028);
    if (iVar2 == 0) {
      iVar2 = -0x7ffdfff7;
      uVar3 = extraout_EDX_00;
    }
    else {
      while (iVar2 = FUN_1000ca10(*(undefined2 *)*local_18), iVar2 != 0) {
        pWVar1 = CharNextW((LPCWSTR)*local_18);
        *local_18 = pWVar1;
      }
      iVar2 = FUN_10009aa0(local_18,local_2020);
      uVar3 = extraout_EDX_01;
      local_1c = iVar2;
      if (-1 < iVar2) {
        local_22ac[1] = (uint)local_2028[0];
        if (local_22ac[1] < 0x14) {
          if (local_22ac[1] == 0x13) {
            uStack_2158 = 3;
            puStack_2168 = (undefined4 *)0x0;
            local_8 = 3;
            pWStack_2170 = local_2020;
            Ordinal_277(pWStack_2170,0,0,(short)auStack_2150);
            auStack_2298[0] = auStack_2150[0];
            local_202c = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)auStack_2298,4);
            local_8 = 0xffffffff;
            while (_Memory = puStack_2168, puStack_2168 != (undefined4 *)0x0) {
              puStack_229c = puStack_2168;
              puStack_2168 = (undefined4 *)*puStack_2168;
              free(_Memory);
            }
          }
          else if (local_22ac[1] == 8) {
            local_2290 = (uint)(&stack0x00000000 != (undefined1 *)0x2020);
            if (local_2290 == 0) {
              local_202c = 0xd;
            }
            else {
              iVar2 = lstrlenW(local_2020);
              local_202c = RegSetValueExW((HKEY)*param_1,param_2,0,1,(BYTE *)local_2020,
                                          iVar2 * 2 + 2);
            }
          }
          else if (local_22ac[1] == 0x11) {
            uStack_2174 = lstrlenW(local_2020);
            uVar3 = uStack_2174 & 1;
            if (uVar3 == 0) {
              uStack_2178 = (int)uStack_2174 / 2;
              auStack_2280[0] = 0;
              local_8 = 5;
              uVar3 = FUN_10014af0(uStack_2178,1);
              FUN_10014940(auStack_2280,uVar3);
              uVar5 = FUN_1000c562(extraout_ECX,extraout_EDX_02);
              return uVar5;
            }
            iVar2 = -0x7fffbffb;
            goto LAB_1000c6ec;
          }
        }
        else if (local_22ac[1] == 0x4008) {
          iVar2 = lstrlenW(local_2020);
          local_2034 = iVar2 + 2;
          local_213c[0] = 0;
          local_8 = 1;
          uVar3 = FUN_10014af0(local_2034,2);
          FUN_10014940(local_213c,uVar3);
          uVar5 = FUN_1000c297();
          return uVar5;
        }
        if (local_202c == 0) {
          local_1c = FUN_10009aa0(local_18,param_3);
          iVar2 = local_1c;
          uVar3 = extraout_EDX_04;
          if (-1 < local_1c) {
            iVar2 = 0;
          }
        }
        else {
          local_2030 = 0x204;
          iVar2 = _HRESULT_FROM_WIN32(local_202c);
          uVar3 = extraout_EDX_03;
        }
      }
    }
  }
LAB_1000c6ec:
  uVar6 = (undefined2)uVar3;
  uVar7 = (undefined2)(uVar3 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000c720);
  ExceptionList = pvStack_10;
  return CONCAT26(uVar7,CONCAT24(uVar6,iVar2));
}



// Function: Catch@1000c28a at 1000c28a

undefined4 Catch_1000c28a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000c29e;
}



// Function: FUN_1000c297 at 1000c297

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000c297(void)

{
  LPWSTR pWVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x2138) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2028) = 0xe;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x2140) = *(undefined4 *)(unaff_EBP + -0x2138);
    *(int *)(unaff_EBP + -0x2144) = unaff_EBP + -0x201c;
    *(undefined4 *)(unaff_EBP + -0x2030) = 0;
    while (**(short **)(unaff_EBP + -0x2144) != 0) {
      pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP + -0x2144));
      *(LPWSTR *)(unaff_EBP + -0x2148) = pWVar1;
      if ((**(short **)(unaff_EBP + -0x2144) == 0x5c) && (**(short **)(unaff_EBP + -0x2148) == 0x30)
         ) {
        **(undefined2 **)(unaff_EBP + -0x2140) = 0;
        *(int *)(unaff_EBP + -0x2140) = *(int *)(unaff_EBP + -0x2140) + 2;
        pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP + -0x2148));
        *(LPWSTR *)(unaff_EBP + -0x2144) = pWVar1;
      }
      else {
        **(undefined2 **)(unaff_EBP + -0x2140) = **(undefined2 **)(unaff_EBP + -0x2144);
        *(int *)(unaff_EBP + -0x2140) = *(int *)(unaff_EBP + -0x2140) + 2;
        *(int *)(unaff_EBP + -0x2144) = *(int *)(unaff_EBP + -0x2144) + 2;
      }
      *(int *)(unaff_EBP + -0x2030) = *(int *)(unaff_EBP + -0x2030) + 1;
    }
    **(undefined2 **)(unaff_EBP + -0x2140) = 0;
    *(int *)(unaff_EBP + -0x2140) = *(int *)(unaff_EBP + -0x2140) + 2;
    **(undefined2 **)(unaff_EBP + -0x2140) = 0;
    *(undefined4 *)(unaff_EBP + -0x2290) = *(undefined4 *)(unaff_EBP + -0x2138);
    LVar2 = FUN_1000c790(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                         *(BYTE **)(unaff_EBP + -0x2290));
    *(LSTATUS *)(unaff_EBP + -0x2028) = LVar2;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x2138) != unaff_EBP + -0x2134) {
    FUN_100148f0((undefined4 *)(unaff_EBP + -0x2138));
  }
  if (*(int *)(unaff_EBP + -0x2028) == 0) {
    uVar4 = FUN_10009aa0(*(void **)(unaff_EBP + -0x14),*(undefined2 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
    uVar4 = extraout_EDX_00;
    if (*(int *)(unaff_EBP + -0x18) < 0) {
      HVar3 = *(HRESULT *)(unaff_EBP + -0x18);
    }
    else {
      HVar3 = 0;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x202c) = 0x204;
    HVar3 = _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP + -0x2028));
    uVar4 = extraout_EDX;
  }
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000c720);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar4,HVar3);
}



// Function: Catch@1000c555 at 1000c555

undefined4 Catch_1000c555(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x1000c569;
}



// Function: FUN_1000c562 at 1000c562

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000c562(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int unaff_EBP;
  undefined2 uVar5;
  undefined2 uVar6;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (*(int *)(unaff_EBP + -0x227c) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2288) = 0x80004005;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x227c) != unaff_EBP + -0x2278) {
      FUN_100148f0((undefined4 *)(unaff_EBP + -0x227c));
      param_2 = extraout_EDX;
    }
    HVar3 = *(HRESULT *)(unaff_EBP + -0x2288);
  }
  else {
    memset(*(void **)(unaff_EBP + -0x227c),0,*(size_t *)(unaff_EBP + -0x2174));
    *(undefined4 *)(unaff_EBP + -0x2284) = 0;
    while (*(int *)(unaff_EBP + -0x2284) < *(int *)(unaff_EBP + -0x2170)) {
      *(int *)(unaff_EBP + -0x22a8) =
           *(int *)(unaff_EBP + -0x2284) / 2 + *(int *)(unaff_EBP + -0x227c);
      uVar1 = FUN_1000c970(*(ushort *)(unaff_EBP + -0x201c + *(int *)(unaff_EBP + -0x2284) * 2));
      **(byte **)(unaff_EBP + -0x22a8) =
           **(byte **)(unaff_EBP + -0x22a8) |
           (byte)((uVar1 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP + -0x2284) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP + -0x2284) = *(int *)(unaff_EBP + -0x2284) + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x229c) = *(undefined4 *)(unaff_EBP + -0x227c);
    *(undefined4 *)(unaff_EBP + -0x22a0) = **(undefined4 **)(unaff_EBP + 8);
    LVar2 = RegSetValueExW(*(HKEY *)(unaff_EBP + -0x22a0),*(LPCWSTR *)(unaff_EBP + 0xc),0,3,
                           *(BYTE **)(unaff_EBP + -0x229c),*(DWORD *)(unaff_EBP + -0x2174));
    *(LSTATUS *)(unaff_EBP + -0x2028) = LVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x227c) != unaff_EBP + -0x2278) {
      FUN_100148f0((undefined4 *)(unaff_EBP + -0x227c));
    }
    if (*(int *)(unaff_EBP + -0x2028) == 0) {
      uVar4 = FUN_10009aa0(*(void **)(unaff_EBP + -0x14),*(undefined2 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
      param_2 = extraout_EDX_01;
      if (*(int *)(unaff_EBP + -0x18) < 0) {
        HVar3 = *(HRESULT *)(unaff_EBP + -0x18);
      }
      else {
        HVar3 = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x202c) = 0x204;
      HVar3 = _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP + -0x2028));
      param_2 = extraout_EDX_00;
    }
  }
  uVar5 = (undefined2)param_2;
  uVar6 = (undefined2)((uint)param_2 >> 0x10);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000c720);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT26(uVar6,CONCAT24(uVar5,HVar3));
}



// Function: FUN_1000c790 at 1000c790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000c790(void *this,LPCWSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  LPCWSTR lpString;
  undefined4 local_10;
  
  lpString = (LPCWSTR)(uint)(param_2 != (BYTE *)0x0);
  if (lpString == (LPCWSTR)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_10 = 0;
    do {
      iVar2 = lstrlenW(lpString);
      lpString = 
      L"삃褁\xf045䖋诰\xf84dᒍ襁\xf855䖋诰\xf44dᒍ襁\xf455綃ǰ쥵\xf48b䖋僴䶋儌ݪj喋刈䖋诼儈ᗿ怄ဂ\xf43b싨÷帀쒃㬔\xe8ec\xf7b7"
      ;
      local_10 = local_10 + (iVar2 + 1) * 2;
    } while (iVar2 + 1 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExW(*this,param_1,0,7,param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_1000c850 at 1000c850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000c850(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e64e;
  local_10 = ExceptionList;
  if ((DAT_10030320 & 1) == 0) {
    DAT_10030320 = DAT_10030320 | 1;
    _DAT_10030300 = &DAT_1002650c;
    _DAT_10030304 = 8;
    _DAT_10030308 = &DAT_10026508;
    _DAT_1003030c = 0x4008;
    _DAT_10030310 = &DAT_10026504;
    _DAT_10030314 = 0x13;
    _DAT_10030318 = &DAT_10026500;
    _DAT_1003031c = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  ExceptionList = &local_10;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,*(LPCWSTR *)(&DAT_10030300 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_10030304 + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000c970 at 1000c970

uint __cdecl FUN_1000c970(ushort param_1)

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



// Function: FUN_1000ca10 at 1000ca10

undefined4 FUN_1000ca10(undefined2 param_1)

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



// Function: FUN_1000ca80 at 1000ca80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ca80(LPCWSTR param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xb < local_c) {
      return 1;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10026530)[local_c]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_1000caf0 at 1000caf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000caf0(HKEY param_1)

{
  LSTATUS LVar1;
  uint uVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  DWORD local_10 [3];
  
  local_10[1] = 0xcccccccc;
  local_10[0] = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_10,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 == 0) {
    uVar3 = 0;
    uVar2 = (uint)(local_10[0] != 0);
  }
  else {
    uVar2 = 0;
    uVar3 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000cb70);
  return CONCAT44(uVar3,uVar2);
}



// Function: FUN_1000cb90 at 1000cb90

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000cb90(undefined4 *param_1,undefined4 param_2,short *param_3)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *puVar2;
  undefined4 local_201c [3];
  undefined2 local_2010 [4098];
  int local_c;
  undefined4 *local_8;
  
  puVar2 = local_201c;
  for (iVar1 = 0x806; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  if (*param_3 == 0x3d) {
    iVar1 = FUN_10009aa0(param_1,param_3);
    param_2 = extraout_EDX;
    local_c = iVar1;
    if (iVar1 < 0) goto LAB_1000cc1b;
    FUN_100099f0(local_8);
    iVar1 = FUN_10009aa0(local_8,local_2010);
    param_2 = extraout_EDX_00;
    local_c = iVar1;
    if ((iVar1 < 0) ||
       (iVar1 = FUN_10009aa0(local_8,param_3), param_2 = extraout_EDX_01, local_c = iVar1, iVar1 < 0
       )) goto LAB_1000cc1b;
  }
  iVar1 = 0;
LAB_1000cc1b:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_1000cc40);
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_1000cc60 at 1000cc60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000cc60(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_1000ccd0 at 1000ccd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_1000ccd0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_10;
  int *local_c;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_100302e4 = *param_3;
    _DAT_100302e8 = param_3[1];
    _DAT_100302ec = param_3[2];
    _DAT_100302f0 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_10 = DAT_10030924; local_10 < DAT_10030928; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_1000cdc0 at 1000cdc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000cdc0(int param_1)

{
  int *local_10;
  int *local_c;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_c = *(int **)(param_1 + 0x2c); *local_c != 0; local_c = local_c + 9) {
      if (local_c[4] != 0) {
        (**(code **)(*(int *)local_c[4] + 8))(local_c[4]);
      }
      local_c[4] = 0;
      (*(code *)local_c[8])(0);
    }
  }
  for (local_10 = DAT_10030924; local_10 < DAT_10030928; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(0);
    }
  }
  FUN_1000cea0(param_1);
  return;
}



// Function: FUN_1000cea0 at 1000cea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000cea0(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_c = 0;
      }
      else {
        local_c = param_1 + 4;
      }
      FUN_1000f220(local_c);
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



// Function: FUN_1000cf50 at 1000cf50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000d061) */
/* WARNING: Removing unreachable block (ram,0x1000d07a) */

undefined8 __fastcall
FUN_1000cf50(int *param_1,int *param_2,int *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int *extraout_EDX;
  undefined4 uVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_5c [8];
  undefined4 local_3c;
  LPCRITICAL_SECTION local_38;
  int *local_30;
  LPCRITICAL_SECTION local_28;
  undefined1 local_24;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e778;
  local_10 = ExceptionList;
  piVar3 = local_5c;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  ExceptionList = &local_10;
  *param_5 = 0;
  local_18 = 0;
  local_14 = param_1;
  if (param_1[0xb] != 0) {
    param_2 = param_1;
    for (local_1c = (int *)param_1[0xb]; *local_1c != 0; local_1c = local_1c + 9) {
      param_2 = local_1c;
      if (local_1c[2] != 0) {
        local_30 = (int *)*local_1c;
        if ((((*param_3 == *local_30) && (param_3[1] == local_30[1])) && (param_3[2] == local_30[2])
            ) && (param_3[3] == local_30[3])) {
          local_5c[0] = 1;
        }
        else {
          local_5c[0] = 0;
        }
        param_2 = param_3;
        if (local_5c[0] != 0) {
          param_2 = local_1c;
          if (local_1c[4] == 0) {
            FUN_100149f0(&local_28,&DAT_1003092c,'\0');
            local_8 = 0;
            local_38 = local_28;
            EnterCriticalSection(local_28);
            param_1 = (int *)0x1000d054;
            local_3c = 0;
            local_24 = 1;
            local_18 = 0;
            if (local_1c[4] == 0) {
              local_18 = (*(code *)local_1c[2])(local_1c[3],&DAT_10026cfc,local_1c + 4,0x1000d054);
              param_1 = (int *)0x1000d0b8;
            }
            local_8 = 0xffffffff;
            FUN_10014a90(&local_28);
            param_2 = extraout_EDX;
          }
          if (local_1c[4] != 0) {
            uVar4 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_4,param_5,param_1);
            param_2 = (int *)((ulonglong)uVar4 >> 0x20);
            local_18 = (int)uVar4;
          }
          break;
        }
      }
    }
  }
  uVar4 = CONCAT44(param_2,local_18);
  if ((*param_5 == 0) && (uVar4 = CONCAT44(param_2,local_18), local_18 == 0)) {
    uVar4 = FUN_1000efc0(param_3,param_5,(int *)&DAT_1003091c,param_3,param_4,param_5);
  }
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  local_18 = (int)uVar4;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000d164);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_18);
}



// Function: FUN_1000d180 at 1000d180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000d180(void *this,int param_1,void *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *_Buf2;
  int *local_10;
  int local_c;
  
  uVar3 = 0xcccccccc;
  uVar4 = 0xcccccccc;
  uVar5 = 0xcccccccc;
  uVar6 = 0xcccccccc;
  uVar7 = 0xcccccccc;
  _Buf2 = (void *)0xcccccccc;
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if (param_2 == (void *)0x0) {
LAB_1000d202:
        local_c = (*(code *)local_10[1])(1);
        if (local_c < 0) break;
        uVar2 = (*(code *)local_10[7])(1,0x1000d215,uVar3,uVar4,uVar5,uVar6,uVar7,_Buf2);
        uVar2 = FUN_1000d2c0(*local_10,(int *)((ulonglong)uVar2 >> 0x20),(GUID *)*local_10,
                             (int *)uVar2,0x1000d233);
        local_c = (int)uVar2;
        if (local_c < 0) break;
      }
      else {
        _Buf2 = (void *)*local_10;
        iVar1 = memcmp(param_2,_Buf2,0x10);
        if (iVar1 == 0) goto LAB_1000d202;
      }
    }
  }
  if (((-1 < local_c) && (local_c = FUN_1000de70(0x1003091c,param_1,param_2), -1 < local_c)) &&
     (DAT_100302d8 != (code *)0x0)) {
    local_c = (*DAT_100302d8)(DAT_100308e8);
  }
  return local_c;
}



// Function: FUN_1000d2c0 at 1000d2c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000d32b) */

undefined8 __fastcall
FUN_1000d2c0(undefined4 param_1,int *param_2,GUID *param_3,int *param_4,int param_5)

{
  bool bVar1;
  errno_t eVar2;
  LSTATUS LVar3;
  int iVar4;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *extraout_EDX_01;
  int *extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  int *extraout_EDX_05;
  int *extraout_EDX_06;
  int *extraout_EDX_07;
  int *extraout_EDX_08;
  int *extraout_EDX_09;
  int *extraout_EDX_10;
  int *extraout_EDX_11;
  int *extraout_EDX_12;
  int *extraout_EDX_13;
  undefined4 *puVar5;
  undefined8 uVar6;
  LPCWSTR pWVar7;
  int *local_220;
  DWORD local_218 [2];
  HKEY local_210;
  undefined4 local_20c;
  undefined4 local_208;
  HKEY local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  wchar_t local_1e8 [130];
  OLECHAR *local_e4;
  undefined4 *local_dc;
  undefined4 local_cc;
  OLECHAR local_c0 [68];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_24;
  int *local_20;
  int *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e6b9;
  local_10 = ExceptionList;
  puVar5 = (undefined4 *)&stack0xfffffd70;
  for (iVar4 = 0xa0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_18[0] = (int *)0x0;
  local_8 = 1;
  if (param_4 == (int *)0x0) {
    local_220 = (int *)0x0;
    local_8 = 0xffffffff;
    local_18[0] = (int *)0x0;
    ExceptionList = &local_10;
  }
  else {
    if ((((param_3->Data1 == 0) &&
         (iVar4._0_2_ = param_3->Data2, iVar4._2_2_ = param_3->Data3, iVar4 == 0)) &&
        (*(int *)param_3->Data4 == 0)) && (*(int *)(param_3->Data4 + 4) == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)local_18);
      local_220 = (int *)0x0;
      param_2 = extraout_EDX;
    }
    else {
      ExceptionList = &local_10;
      local_20 = (int *)CoCreateInstance((IID *)&DAT_10027de0,(LPUNKNOWN)0x0,1,(IID *)&DAT_10026d78,
                                         local_18);
      pWVar7 = (LPCWSTR)0x1000d3ef;
      if ((int)local_20 < 0) {
        local_8 = 0xffffffff;
        param_2 = extraout_EDX_00;
        if (local_18[0] != (int *)0x0) {
          (**(code **)(*local_18[0] + 8))(local_18[0]);
          param_2 = extraout_EDX_01;
        }
        local_220 = (int *)0x0;
      }
      else {
        local_20 = (int *)0x0;
        param_2 = param_4;
        for (local_24 = param_4; *local_24 != 0; local_24 = local_24 + 2) {
          puVar5 = (undefined4 *)local_24[1];
          local_38 = *puVar5;
          local_34 = puVar5[1];
          local_30 = puVar5[2];
          local_2c = puVar5[3];
          if (param_5 == 0) {
            if (*local_24 == 1) {
              (**(code **)(*local_18[0] + 0x18))(local_18[0],param_3,1,&local_38);
              uVar6 = CONCAT44(extraout_EDX_03,local_20);
              pWVar7 = (LPCWSTR)0x1000d567;
            }
            else {
              (**(code **)(*local_18[0] + 0x20))(local_18[0],param_3,1,&local_38);
              uVar6 = CONCAT44(extraout_EDX_04,local_20);
              pWVar7 = L"䶋菠ࣁ䶉\xe9e0ﺞ\xffff綃\x10蔏ַ";
            }
          }
          else {
            if (*local_24 == 1) {
              uVar6 = (**(code **)(*local_18[0] + 0x14))(local_18[0],param_3,1,&local_38);
              pWVar7 = (LPCWSTR)0x1000d4b0;
            }
            else {
              uVar6 = (**(code **)(*local_18[0] + 0x1c))(local_18[0],param_3,1,&local_38);
              pWVar7 = L"䖉菤\xe47d紀謿\xe455閉﷘\xffff䗇׼";
            }
            local_20 = (int *)uVar6;
            local_220 = local_20;
            if ((int)local_20 < 0) {
              local_8 = 0xffffffff;
              param_2 = local_20;
              if (local_18[0] != (int *)0x0) {
                (**(code **)(*local_18[0] + 8))(local_18[0]);
                param_2 = extraout_EDX_02;
              }
              goto LAB_1000dba3;
            }
          }
          param_2 = (int *)((ulonglong)uVar6 >> 0x20);
          local_20 = (int *)uVar6;
        }
        if (param_5 == 0) {
          StringFromGUID2(param_3,local_c0,0x40);
          local_cc = 3;
          local_dc = (undefined4 *)0x0;
          local_8._0_1_ = 6;
          local_e4 = local_c0;
          param_2 = extraout_EDX_05;
          if (local_e4 != (OLECHAR *)0x0) {
            eVar2 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            ATL::AtlCrtErrorCheck(eVar2);
            eVar2 = wcscat_s(local_1e8,0x80,local_e4);
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001920(0x80004005);
              break;
            case 0xc:
              FUN_10001920(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001920(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,L"\\Required Categories");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001920(0x80004005);
              break;
            case 0xc:
              FUN_10001920(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001920(0x80070057);
            }
            local_1fc = (HKEY)0x80000000;
            local_1f8 = 0;
            local_1f4 = 0;
            local_210 = (HKEY)0x0;
            local_20c = 0;
            local_208 = 0;
            local_8 = CONCAT31(local_8._1_3_,8);
            local_218[0] = 0;
            LVar3 = FUN_1000bbb0(&local_210,(HKEY)0x80000000,local_1e8,0x20019);
            if (LVar3 == 0) {
              LVar3 = RegQueryInfoKeyW(local_210,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_218,
                                       (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
              if (local_210 != (HKEY)0x0) {
                RegCloseKey(local_210);
                local_210 = (HKEY)0x0;
              }
              local_20c = 0;
              if ((LVar3 == 0) && (local_218[0] == 0)) {
                FUN_1000b7a0(&local_1fc,local_1e8);
              }
            }
            eVar2 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001920(0x80004005);
              break;
            case 0xc:
              FUN_10001920(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001920(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,local_e4);
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001920(0x80004005);
              break;
            case 0xc:
              FUN_10001920(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001920(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,L"\\Implemented Categories");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001920(0x80004005);
              break;
            case 0xc:
              FUN_10001920(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001920(0x80070057);
            }
            pWVar7 = local_1e8;
            LVar3 = FUN_1000bbb0(&local_210,local_1fc,pWVar7,0x20019);
            param_2 = extraout_EDX_06;
            if (LVar3 == 0) {
              LVar3 = RegQueryInfoKeyW(local_210,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_218,
                                       (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
              pWVar7 = L"薉﷨\xffff藇ﶨ\xffff";
              param_2 = extraout_EDX_07;
              if (local_210 != (HKEY)0x0) {
                RegCloseKey(local_210);
                pWVar7 = L"薉ﶨ\xffff藇ﷴ\xffff";
                local_210 = (HKEY)0x0;
                param_2 = extraout_EDX_08;
              }
              local_20c = 0;
              if ((LVar3 == 0) && (local_218[0] == 0)) {
                FUN_1000b7a0(&local_1fc,local_1e8);
                param_2 = extraout_EDX_09;
              }
            }
            local_8._0_1_ = 7;
            if (local_210 != (HKEY)0x0) {
              RegCloseKey(local_210);
              pWVar7 = L"薉ﶤ\xffff藇ﷴ\xffff";
              local_210 = (HKEY)0x0;
              param_2 = extraout_EDX_10;
            }
            local_20c = 0;
            local_8._0_1_ = 6;
            if (local_1fc != (HKEY)0x0) {
              RegCloseKey(local_1fc);
              pWVar7 = L"薉ﶠ\xffff藇\xfe08\xffff";
              local_1fc = (HKEY)0x0;
              param_2 = extraout_EDX_11;
            }
            local_1f8 = 0;
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar5 = local_dc, local_dc != (undefined4 *)0x0) {
            local_dc = (undefined4 *)*local_dc;
            free(puVar5);
            pWVar7 = L"싫藇﷔\xffff";
            param_2 = extraout_EDX_12;
          }
        }
        local_8 = 0xffffffff;
        if (local_18[0] != (int *)0x0) {
          (**(code **)(*local_18[0] + 8))(local_18[0],pWVar7);
          param_2 = extraout_EDX_13;
        }
        local_220 = (int *)0x0;
      }
    }
  }
LAB_1000dba3:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000dbd4);
  ExceptionList = local_10;
  return CONCAT44(param_2,local_220);
}



// Function: FUN_1000de70 at 1000de70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000de70(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *_Buf2;
  int *local_c;
  int local_8;
  
  uVar5 = 0xcccccccc;
  uVar6 = 0xcccccccc;
  uVar7 = 0xcccccccc;
  uVar8 = 0xcccccccc;
  _Buf2 = (void *)0xcccccccc;
  if (param_1 == 0) {
    local_8 = -0x7ff8ffa9;
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 8); local_c < *(int **)(param_1 + 0xc); local_c = local_c + 1
        ) {
      if (*local_c != 0) {
        puVar1 = (undefined4 *)*local_c;
        if (param_3 != (void *)0x0) {
          _Buf2 = (void *)*puVar1;
          iVar2 = memcmp(param_3,_Buf2,0x10);
          if (iVar2 != 0) goto LAB_1000deb6;
        }
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        piVar3 = (int *)(*(code *)puVar1[7])(1,0x1000df1c,uVar5,uVar6,uVar7,uVar8,_Buf2);
        uVar4 = FUN_1000d2c0(puVar1,(int *)*puVar1,(GUID *)*puVar1,piVar3,0x1000df3a);
        local_8 = (int)uVar4;
        if (local_8 < 0) break;
      }
LAB_1000deb6:
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      uVar4 = FUN_1000df90(*(HMODULE *)(param_1 + 4),(int *)0x0);
      local_8 = (int)uVar4;
    }
  }
  return local_8;
}



// Function: FUN_1000df90 at 1000df90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000df90(HMODULE param_1,int *param_2)

{
  errno_t eVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_274 [3];
  wchar_t *local_268;
  rsize_t local_264;
  int local_260;
  int local_25c;
  HMODULE local_258;
  char local_251;
  FARPROC local_250;
  wchar_t *local_248 [3];
  wchar_t local_23c [259];
  undefined2 local_36;
  wchar_t *local_30;
  int local_2c;
  int *local_24 [3];
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e703;
  local_10 = ExceptionList;
  ppiVar3 = local_274;
  for (iVar2 = 0x99; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_18[0] = 0;
  local_24[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  uVar4 = FUN_1000e340(local_18,param_2,param_1,(LPCWSTR)param_2,local_18,local_24);
  local_2c = (int)uVar4;
  if (-1 < local_2c) {
    local_30 = (wchar_t *)0x0;
    local_248[0] = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    local_274[0] = local_24[0];
    local_2c = (**(code **)(*local_24[0] + 0x24))(local_24[0],0xffffffff,0,0,0,local_248);
    uVar5 = 0x1000e04b;
    if ((-1 < local_2c) && (local_248[0] != (wchar_t *)0x0)) {
      local_264 = Ordinal_7(local_248[0],0x1000e04b);
      local_268 = local_248[0];
      eVar1 = wcsncpy_s(local_23c,0x104,local_248[0],local_264);
      uVar5 = 0x1000e0cd;
      ATL::AtlCrtErrorCheck(eVar1);
      local_36 = 0;
      iVar2 = FUN_1000ea60(local_23c);
      local_23c[iVar2] = L'\0';
      local_30 = local_23c;
    }
    local_250 = (FARPROC)0x0;
    local_251 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x251) {
      local_2c = -0x7fffbffd;
    }
    else {
      local_251 = DAT_1002fcd0;
      local_2c = 0;
    }
    if (local_2c < 0) {
      local_25c = local_2c;
      local_8._0_1_ = 2;
      Ordinal_6(local_248[0],uVar5);
      uVar5 = 0x1000e15b;
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_24[0] != (int *)0x0) {
        (**(code **)(*local_24[0] + 8))(local_24[0],0x1000e15b);
        uVar5 = 0x1000e180;
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_18[0],uVar5);
      iVar2 = local_25c;
      uVar5 = extraout_EDX;
      goto LAB_1000e2a7;
    }
    if (local_251 == '\x01') {
      local_258 = GetModuleHandleW(L"OLEAUT32.DLL");
      if (local_258 != (HMODULE)0x0) {
        local_250 = GetProcAddress(local_258,"RegisterTypeLibForUser");
      }
    }
    if (local_250 == (FARPROC)0x0) {
      local_250 = Ordinal_163_exref;
    }
    local_274[2] = (int *)local_18[0];
    local_274[1] = local_24[0];
    local_2c = (*local_250)(local_24[0],local_18[0],local_30);
    local_8._0_1_ = 2;
    Ordinal_6(local_248[0],0x1000e23c);
  }
  local_260 = local_2c;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_24[0] != (int *)0x0) {
    (**(code **)(*local_24[0] + 8))(local_24[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18[0]);
  iVar2 = local_260;
  uVar5 = extraout_EDX_00;
LAB_1000e2a7:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000e2d8);
  ExceptionList = local_10;
  return CONCAT44(uVar5,iVar2);
}



// Function: FUN_1000e340 at 1000e340

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000e446) */

undefined8 __fastcall
FUN_1000e340(undefined4 param_1,int *param_2,HMODULE param_3,LPCWSTR param_4,int *param_5,
            undefined4 *param_6)

{
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *extraout_EDX_01;
  int *extraout_EDX_02;
  int *extraout_EDX_03;
  int *extraout_EDX_04;
  int *extraout_EDX_05;
  int *extraout_EDX_06;
  errno_t *peVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  errno_t local_2c4 [3];
  undefined4 *local_2b8;
  errno_t local_2b4;
  undefined4 *local_2b0;
  errno_t local_2ac;
  undefined4 *local_2a8;
  undefined4 *local_2a4;
  undefined4 *local_2a0;
  undefined4 *local_29c;
  DWORD local_298;
  DWORD local_294;
  DWORD local_290;
  DWORD local_28c;
  DWORD local_288;
  DWORD local_284;
  wchar_t local_27c [8];
  DWORD local_26c;
  WCHAR *local_268;
  int *local_264;
  int *local_260;
  LPCWSTR local_25c;
  LPCWSTR local_258;
  int *local_254;
  WCHAR local_24c [274];
  undefined4 *local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  peVar4 = local_2c4;
  for (iVar3 = 0xad; iVar3 != 0; iVar3 = iVar3 + -1) {
    *peVar4 = -0x33333334;
    peVar4 = peVar4 + 1;
  }
  if ((param_5 == (int *)0x0) || (param_6 == (undefined4 *)0x0)) {
    DVar2 = 0x80004003;
    ExceptionList = &local_10;
  }
  else {
    ExceptionList = &local_10;
    *param_5 = 0;
    *param_6 = 0;
    local_18 = 3;
    local_28 = (undefined4 *)0x0;
    local_8 = 0;
    local_254 = (int *)GetModuleFileNameW(param_3,local_24c,0x104);
    uVar7 = 0x1000e3ce;
    if (local_254 == (int *)0x0) {
      local_284 = FUN_10008960();
      local_8 = 0xffffffff;
      param_2 = extraout_EDX;
      while (puVar1 = local_28, DVar2 = local_284, local_28 != (undefined4 *)0x0) {
        local_29c = local_28;
        local_28 = (undefined4 *)*local_28;
        free(puVar1);
        param_2 = extraout_EDX_00;
      }
    }
    else if (local_254 == (int *)0x104) {
      param_2 = (int *)0x7a;
      local_2c4[2] = 0x8007007a;
      local_288 = 0x8007007a;
      local_8 = 0xffffffff;
      while (puVar1 = local_28, DVar2 = local_288, local_28 != (undefined4 *)0x0) {
        local_2a0 = local_28;
        local_28 = (undefined4 *)*local_28;
        free(puVar1);
        param_2 = extraout_EDX_01;
      }
    }
    else {
      local_258 = (LPCWSTR)0x0;
      local_258 = FUN_1000e9c0(local_24c);
      if (param_4 != (LPCWSTR)0x0) {
        local_25c = param_4;
        if (param_4 == (LPCWSTR)0x0) {
          local_28c = 0x8007000e;
          local_8 = 0xffffffff;
          param_2 = extraout_EDX_02;
          while (puVar1 = local_28, DVar2 = local_28c, local_28 != (undefined4 *)0x0) {
            local_2a4 = local_28;
            local_28 = (undefined4 *)*local_28;
            free(puVar1);
            param_2 = extraout_EDX_03;
          }
          goto LAB_1000e86d;
        }
        local_260 = (int *)lstrlenW(param_4);
        param_2 = (int *)((int)local_254 + (int)local_260);
        local_264 = param_2;
        if (((param_2 < local_254) || (param_2 < local_260)) || ((int *)0x10d < param_2)) {
          local_290 = 0x80004005;
          local_8 = 0xffffffff;
          while (puVar1 = local_28, DVar2 = local_290, local_28 != (undefined4 *)0x0) {
            local_2a8 = local_28;
            local_28 = (undefined4 *)*local_28;
            free(puVar1);
            param_2 = extraout_EDX_04;
          }
          goto LAB_1000e86d;
        }
        local_2c4[1] = wcscpy_s(local_24c + (int)local_254,0x10e - (int)local_254,local_25c);
        local_2ac = local_2c4[1];
        switch(local_2c4[1]) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_10001920(0x80004005);
          break;
        case 0xc:
          FUN_10001920(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_10001920(0x80070057);
        }
      }
      local_268 = local_24c;
      uVar5 = Ordinal_161(local_268,param_6);
      local_26c = (DWORD)uVar5;
      uVar6 = 0x1000e695;
      if ((int)local_26c < 0) {
        builtin_wcsncpy(local_27c,L".tlb",5);
        param_2 = (int *)((uint)((ulonglong)uVar5 >> 0x20) & 0xffff0000);
        if (0x104 < ((int)local_258 - (int)local_24c >> 1) + 5U) {
          local_294 = 0x80004005;
          local_8 = 0xffffffff;
          while (puVar1 = local_28, DVar2 = local_294, local_28 != (undefined4 *)0x0) {
            local_2b0 = local_28;
            local_28 = (undefined4 *)*local_28;
            free(puVar1);
            param_2 = extraout_EDX_05;
          }
          goto LAB_1000e86d;
        }
        local_2c4[0] = wcscpy_s(local_258,0x10e - ((int)local_258 - (int)local_24c >> 1),local_27c);
        uVar6 = 0x1000e76d;
        local_2b4 = local_2c4[0];
        switch(local_2c4[0]) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_10001920(0x80004005);
          break;
        case 0xc:
          FUN_10001920(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_10001920(0x80070057);
        }
        local_268 = local_24c;
        uVar5 = Ordinal_161(local_268,param_6,uVar6);
        uVar6 = 0x1000e7e6;
      }
      param_2 = (int *)((ulonglong)uVar5 >> 0x20);
      local_26c = (DWORD)uVar5;
      if (-1 < (int)local_26c) {
        iVar3 = Ordinal_2(local_268,uVar6,uVar7);
        *param_5 = iVar3;
        param_2 = param_5;
        if (*param_5 == 0) {
          local_26c = 0x8007000e;
        }
      }
      local_298 = local_26c;
      local_8 = 0xffffffff;
      while (puVar1 = local_28, DVar2 = local_298, local_28 != (undefined4 *)0x0) {
        local_2b8 = local_28;
        local_28 = (undefined4 *)*local_28;
        free(puVar1);
        param_2 = extraout_EDX_06;
      }
    }
  }
LAB_1000e86d:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000e8a0);
  ExceptionList = local_10;
  return CONCAT44(param_2,DVar2);
}



// Function: FUN_1000e9c0 at 1000e9c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCWSTR __cdecl FUN_1000e9c0(LPWSTR param_1)

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



// Function: FUN_1000ea60 at 1000ea60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000ea60(LPWSTR param_1)

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



// Function: FUN_1000eb00 at 1000eb00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000eb00(void *this,int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int local_28;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,(void *)*local_10,0x10), iVar1 == 0))
      {
        piVar2 = (int *)(*(code *)local_10[7])(0);
        uVar3 = FUN_1000d2c0(local_10,(int *)*local_10,(GUID *)*local_10,piVar2,0x1000eb95);
        local_c = (int)uVar3;
        if ((local_c < 0) || (local_c = (*(code *)local_10[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_28 = 0;
    if (DAT_100302dc != (code *)0x0) {
      local_28 = (*DAT_100302dc)();
    }
    if (-1 < local_28) {
      local_28 = FUN_1000ec30(0x1003091c,param_1,param_2);
    }
    local_c = local_28;
  }
  return local_c;
}



// Function: FUN_1000ec30 at 1000ec30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000ec30(int param_1,int param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined8 uVar4;
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
         ((piVar1 = (int *)*local_c, param_3 == (void *)0x0 ||
          (iVar2 = memcmp(param_3,(void *)*piVar1,0x10), iVar2 == 0)))) {
        piVar3 = (int *)(*(code *)piVar1[7])(0);
        uVar4 = FUN_1000d2c0(extraout_ECX,piVar1,(GUID *)*piVar1,piVar3,0x1000ecdc);
        local_8 = (int)uVar4;
        if ((local_8 < 0) || (local_8 = (*(code *)piVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      uVar4 = FUN_1000ed50(*(HMODULE *)(param_1 + 4),(int *)0x0);
      local_8 = (int)uVar4;
    }
  }
  return local_8;
}



// Function: FUN_1000ed50 at 1000ed50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000ed50(HMODULE param_1,int *param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int **ppiVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  int *local_4c [2];
  int local_44;
  int local_40;
  HMODULE local_3c;
  char local_35;
  FARPROC local_34;
  int local_30;
  int local_2c;
  int *local_24 [3];
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e758;
  local_10 = ExceptionList;
  ppiVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_18[0] = 0;
  local_24[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  uVar3 = FUN_1000e340(local_18,param_2,param_1,(LPCWSTR)param_2,local_18,local_24);
  local_2c = (int)uVar3;
  if (-1 < local_2c) {
    local_4c[1] = local_24[0];
    local_2c = (**(code **)(*local_24[0] + 0x1c))(local_24[0],&local_30);
    uVar4 = 0x1000eddc;
    if (-1 < local_2c) {
      local_34 = (FARPROC)0x0;
      local_35 = '\0';
      if (&stack0x00000000 == (undefined1 *)0x35) {
        local_2c = -0x7fffbffd;
      }
      else {
        local_35 = DAT_1002fcd0;
        local_2c = 0;
      }
      if (local_2c < 0) {
        local_40 = local_2c;
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_24[0] != (int *)0x0) {
          (**(code **)(*local_24[0] + 8))(local_24[0]);
          uVar4 = 0x1000ee45;
        }
        local_8 = 0xffffffff;
        Ordinal_6(local_18[0],uVar4);
        iVar1 = local_40;
        uVar4 = extraout_EDX;
        goto LAB_1000ef51;
      }
      if (local_35 == '\x01') {
        local_3c = GetModuleHandleW(L"OLEAUT32.DLL");
        uVar4 = 0x1000ee84;
        if (local_3c != (HMODULE)0x0) {
          local_34 = GetProcAddress(local_3c,"UnRegisterTypeLibForUser");
          uVar4 = 0x1000eea5;
        }
      }
      if (local_34 == (FARPROC)0x0) {
        local_34 = Ordinal_186_exref;
      }
      local_2c = (*local_34)(local_30,(uint)*(ushort *)(local_30 + 0x18),
                             (uint)*(ushort *)(local_30 + 0x1a),*(undefined4 *)(local_30 + 0x10),
                             *(undefined4 *)(local_30 + 0x14),uVar4);
      local_4c[0] = local_24[0];
      (**(code **)(*local_24[0] + 0x30))(local_24[0],local_30,0x1000eee5);
    }
  }
  local_44 = local_2c;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_24[0] != (int *)0x0) {
    (**(code **)(*local_24[0] + 8))(local_24[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18[0]);
  iVar1 = local_44;
  uVar4 = extraout_EDX_00;
LAB_1000ef51:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ef80);
  ExceptionList = local_10;
  return CONCAT44(uVar4,iVar1);
}



// Function: FUN_1000efc0 at 1000efc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000f115) */
/* WARNING: Removing unreachable block (ram,0x1000f12e) */

undefined8 __fastcall
FUN_1000efc0(undefined4 param_1,int *param_2,int *param_3,int *param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  int *extraout_EDX;
  int *piVar2;
  undefined8 uVar3;
  int local_48 [4];
  LPCRITICAL_SECTION local_38;
  int *local_30;
  LPCRITICAL_SECTION local_28;
  undefined1 local_24;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e778;
  local_10 = ExceptionList;
  piVar2 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  if (param_6 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
    ExceptionList = &local_10;
  }
  else {
    ExceptionList = &local_10;
    *param_6 = 0;
    if (param_3 == (int *)0x0) {
      iVar1 = -0x7ff8ffa9;
    }
    else if (*param_3 == 0) {
      iVar1 = -0x7fff0001;
    }
    else {
      local_14 = 0;
      for (local_18 = (int *)param_3[2]; param_2 = param_3, local_18 < (int *)param_3[3];
          local_18 = local_18 + 1) {
        if ((*local_18 != 0) && (local_1c = (undefined4 *)*local_18, local_1c[2] != 0)) {
          param_2 = (int *)*local_1c;
          if ((*param_4 == *param_2) &&
             (((param_4[1] == param_2[1] && (param_4[2] == param_2[2])) &&
              (param_4[3] == param_2[3])))) {
            local_48[0] = 1;
          }
          else {
            local_48[0] = 0;
          }
          local_30 = param_2;
          if (local_48[0] != 0) {
            if (local_1c[4] == 0) {
              FUN_100149f0(&local_28,param_3 + 4,'\0');
              local_8 = 0;
              local_38 = local_28;
              EnterCriticalSection(local_28);
              local_48[3] = 0;
              local_24 = 1;
              local_14 = 0;
              if (local_1c[4] == 0) {
                local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_10026cfc,local_1c + 4,0x1000f108)
                ;
              }
              local_8 = 0xffffffff;
              FUN_10014a90(&local_28);
              param_2 = extraout_EDX;
            }
            if (local_1c[4] != 0) {
              uVar3 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_5,param_6);
              param_2 = (int *)((ulonglong)uVar3 >> 0x20);
              local_14 = (int)uVar3;
            }
            break;
          }
        }
      }
      iVar1 = local_14;
      if ((*param_6 == 0) && (local_14 == 0)) {
        local_14 = -0x7ffbfeef;
        iVar1 = local_14;
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000f1fc);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_1000f220 at 1000f220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f220(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
  }
  local_8 = *(undefined4 **)(param_1 + 8);
  while (local_8 != (undefined4 *)0x0) {
    (*(code *)*local_8)(local_8[1]);
    puVar1 = (undefined4 *)local_8[2];
    operator_delete(local_8);
    local_8 = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000f2d0 at 1000f2d0

undefined4 FUN_1000f2d0(void)

{
  return 0;
}



// Function: FUN_1000f2e0 at 1000f2e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f2e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_40 [7];
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e7ae;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_40;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb4;
  local_24 = (undefined4 *)operator_new(0x28);
  local_8._0_1_ = 1;
  if (local_24 == (undefined4 *)0x0) {
    local_40[1] = (undefined4 *)0x0;
  }
  else {
    FUN_1000f530(local_24 + 1);
    *local_24 = ATL::CComClassFactory::vftable;
    *local_24 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
    local_40[1] = local_24;
  }
  local_20 = local_40[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_40[1];
  uVar1 = FUN_1000f3ad();
  return uVar1;
}



// Function: Catch@1000f3a0 at 1000f3a0

undefined4 Catch_1000f3a0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000f3b4;
}



// Function: FUN_1000f3ad at 1000f3ad

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f3ad(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x24) = *(undefined4 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x30));
    *(DWORD *)(unaff_EBP + -0x34) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x34)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x30) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x34);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_1000f4a0 at 1000f4a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_1000f4a0(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  undefined4 local_14;
  undefined4 local_c;
  
  local_c = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    local_14 = GetLastError();
    if (0 < (int)local_14) {
      local_14 = local_14 & 0xffff | 0x80070000;
    }
    local_c = local_14;
  }
  return local_c;
}



// Function: FUN_1000f530 at 1000f530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000f530(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e7e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  memset(param_1 + 1,0,0x18);
  *(undefined1 *)(param_1 + 7) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f5c0 at 1000f5c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000f5c0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f4a8;
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



// Function: FUN_1000f640 at 1000f640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f640(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10010080(0,param_2,param_3);
  }
  else {
    local_8 = FUN_100130b0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f690 at 1000f690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f690(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10013280(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10013650(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f6e0 at 1000f6e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f6e0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10013810(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10013d70(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f730 at 1000f730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f730(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10013f30(0,param_2,param_3);
  }
  else {
    local_8 = FUN_100141f0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f780 at 1000f780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f780(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10014360(0,param_2,param_3);
  }
  else {
    local_8 = FUN_100145d0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f7d0 at 1000f7d0

void FUN_1000f7d0(void)

{
  return;
}



// Function: FUN_1000f7f0 at 1000f7f0

void FUN_1000f7f0(void)

{
  return;
}



// Function: FUN_1000f800 at 1000f800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000f800(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e81e;
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



// Function: FUN_1000f8c0 at 1000f8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f8c0(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_1000f980 at 1000f980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f980(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_100302e0 + 8))();
  }
  else {
    (**(code **)(*DAT_100302e0 + 4))();
  }
  return 0;
}



// Function: FUN_1000f9e0 at 1000f9e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000f9e0(void *this,uint param_1)

{
  FUN_1000f800((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000fa30 at 1000fa30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fa30(int *param_1)

{
  void *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    free(_Memory);
  }
  return;
}



// Function: FUN_1000fa90 at 1000fa90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fa90(int *param_1)

{
  FUN_1000fc30(param_1);
  return;
}



// Function: FUN_1000fac0 at 1000fac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000fac0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_38 [8];
  void *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e863;
  local_10 = ExceptionList;
  puVar4 = local_38;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  local_14 = (int *)this;
  local_18 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (local_18 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    *local_14 = (int)local_18;
    pvVar2 = _recalloc((void *)local_14[1],local_14[2] + 1,4);
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      local_14[1] = (int)pvVar2;
      iVar3 = local_14[2];
      puVar4 = (undefined4 *)(*local_14 + iVar3 * 4);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *param_1;
      }
      puVar4 = (undefined4 *)(local_14[1] + iVar3 * 4);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *param_2;
      }
      local_14[2] = local_14[2] + 1;
      uVar1 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_1000fc30 at 1000fc30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fc30(int *param_1)

{
  int local_c;
  
  if (*param_1 != 0) {
    for (local_c = 0; local_c < param_1[2]; local_c = local_c + 1) {
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



// Function: FUN_1000fce0 at 1000fce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_1000fce0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_100302e0 + 4))(0x1000fd0a);
  }
  return LVar1;
}



// Function: FUN_1000fd50 at 1000fd50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_1000fd50(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_100302e0 + 8))(0x1000fd7e);
  }
  return LVar1;
}



// Function: FUN_1000fe00 at 1000fe00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000fe00(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: FUN_1000fe60 at 1000fe60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000fe60(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000fea0(param_1,(int *)&PTR_DAT_10026e1c,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000fea0 at 1000fea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000fea0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
LAB_1000ffd6:
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
          if (bVar1) goto LAB_1000ffd6;
        }
      }
      iVar2 = -0x7fffbffe;
    }
  }
  return iVar2;
}



// Function: FUN_10010080 at 10010080

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010080(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_54 [10];
  undefined4 *local_2c;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001e883;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_54;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffa0;
  local_20 = (undefined4 *)operator_new(0x2c);
  if (local_20 == (undefined4 *)0x0) {
    local_54[1] = (undefined4 *)0x0;
  }
  else {
    FUN_1000f530(local_20 + 3);
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_2c = local_20 + 1;
    local_20[2] = 0;
    local_8._0_1_ = 2;
    *local_20 = ATL::CComObject<class_CSFStringLoader>::vftable;
    local_20[1] = ATL::CComObject<class_CSFStringLoader>::vftable;
    (**(code **)(*DAT_100302e0 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_54[1] = local_20;
  }
  local_1c = local_54[1];
  uVar1 = FUN_1001016f();
  return uVar1;
}



// Function: Catch@10010162 at 10010162

undefined4 Catch_10010162(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10010176;
}



// Function: FUN_1001016f at 1001016f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001016f(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined8 uVar3;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 0xc));
    uStack00000004 = 0x1001019e;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x18) + 0x10;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x30));
    *(DWORD *)(unaff_EBP + -0x34) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x34)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x30) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x34);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar3 = FUN_10010280();
      *(int *)(unaff_EBP + -0x14) = (int)uVar3;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 0xc));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10010280 at 10010280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010280(void)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined1 **ppuVar2;
  undefined4 uVar3;
  undefined1 auStack_d4 [16];
  undefined4 uStack_c4;
  undefined1 *local_b4 [6];
  undefined1 *local_9c;
  undefined1 local_8d;
  undefined1 *local_8c;
  undefined1 local_6d;
  undefined1 *local_6c;
  undefined4 local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined4 local_58 [9];
  undefined1 local_34 [32];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e8cb;
  local_10 = ExceptionList;
  ppuVar2 = local_b4;
  for (iVar1 = 0x29; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined1 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_6c = &local_6d;
  local_b4[3] = local_34;
  local_8 = 0;
  uStack_c4 = 0x100102d8;
  ExceptionList = &local_10;
  FUN_10003930(local_34,'\0',0);
  local_8 = 1;
  FUN_10004960(local_58,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{6DB2D17C-7414-49F0-91AC-8CE1DCD0BFFC}"
              );
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_64 = auStack_d4;
  local_b4[2] = auStack_d4;
  local_9c = auStack_d4;
  local_8c = &local_8d;
  local_8._0_1_ = 3;
  FUN_10003930(auStack_d4,'\0',0);
  FUN_10003b40(local_9c,local_58,0,0xffffffff);
  local_b4[1] = local_9c;
  local_8._0_1_ = 2;
  local_b4[0] = (undefined1 *)(**(code **)(*(int *)(local_14 + 4) + 0x3c))();
  local_68 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  local_60 = local_b4[0];
  FUN_10003930(local_58,'\x01',0);
  local_8 = 6;
  FUN_10003930(local_34,'\x01',0);
  local_8 = 0xffffffff;
  uVar3 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100103e0);
  ExceptionList = local_10;
  return CONCAT44(uVar3,local_68);
}



// Function: FUN_10010420 at 10010420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010420(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 extraout_EDX;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 auStack_200 [5];
  undefined4 uStack_1ec;
  uint local_1d8 [2];
  undefined1 *local_1d0;
  undefined1 *local_1cc;
  undefined1 *local_1c8;
  DWORD local_1c4;
  undefined1 *local_1c0;
  undefined1 *local_1bc;
  undefined4 *local_1b8;
  undefined1 *local_1b4;
  undefined4 *local_1b0;
  undefined1 *local_1ac;
  undefined1 local_1a1;
  undefined1 *local_1a0;
  undefined1 local_195;
  undefined1 *local_194;
  LPCWSTR local_190;
  size_t local_174;
  wchar_t *local_170;
  size_t local_16c;
  size_t local_15c;
  int local_158;
  int local_154;
  LPCWSTR local_150;
  LPCWSTR local_14c;
  undefined1 *local_148;
  undefined1 local_13d;
  undefined1 *local_13c;
  undefined1 local_131;
  undefined1 *local_130;
  undefined1 local_125;
  undefined1 *local_124;
  undefined1 local_119;
  undefined1 *local_118;
  uint local_114;
  undefined1 *local_110;
  undefined1 local_10c [28];
  undefined1 local_f0 [28];
  undefined1 *local_d4;
  undefined1 local_cc [36];
  undefined1 local_a8 [32];
  DWORD local_88;
  undefined4 local_80 [4];
  int local_70;
  undefined1 local_5c [36];
  undefined4 local_38 [8];
  HMODULE local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e9bf;
  local_10 = ExceptionList;
  puVar3 = local_1d8;
  for (iVar2 = 0x72; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = (HMODULE)0x0;
  local_118 = &local_119;
  local_1b0 = local_38;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  uStack_1ec = 0x1001048a;
  ExceptionList = &local_10;
  FUN_10003930(local_38,'\0',0);
  local_124 = &local_125;
  local_1b4 = local_5c;
  local_8._0_1_ = 3;
  uStack_1ec = 0x100104b3;
  FUN_10003930(local_5c,'\0',0);
  local_130 = &local_131;
  local_1b8 = local_80;
  local_8._0_1_ = 5;
  uStack_1ec = 0x100104dc;
  FUN_10003930(local_80,'\0',0);
  local_88 = 0;
  local_d4 = (undefined1 *)auStack_200;
  local_1bc = (undefined1 *)auStack_200;
  local_148 = (undefined1 *)auStack_200;
  local_13c = &local_13d;
  local_8._0_1_ = 7;
  FUN_10003930(auStack_200,'\0',0);
  FUN_10003b40(local_148,(undefined4 *)&stack0x00000004,0,0xffffffff);
  local_1c0 = local_148;
  local_8 = CONCAT31(local_8._1_3_,6);
  local_1c4 = (**(code **)(*local_14 + 0x40))();
  local_88 = local_1c4;
  local_14c = (LPCWSTR)FUN_10012f70(local_38);
  local_18 = LoadLibraryW(local_14c);
  if ((local_88 != 0) || (local_18 == (HMODULE)0x0)) {
    local_88 = (**(code **)(*local_14 + 0x28))();
    auStack_200[0] = 0x100105c9;
    local_150 = (LPCWSTR)FUN_10012f70(local_38);
    local_18 = LoadLibraryW(local_150);
  }
  if ((local_88 == 0) && (local_18 != (HMODULE)0x0)) goto LAB_10010822;
  local_88 = (**(code **)(*local_14 + 0x14))();
  if (local_88 == 0) {
    local_154 = local_70;
    DVar1 = 0;
    if (local_70 == 0) goto LAB_10010644;
  }
  else {
LAB_10010644:
    local_88 = (**(code **)(*local_14 + 0x10))();
    if ((local_88 != 0) || (local_158 = local_70, DVar1 = local_88, local_70 == 0)) {
      local_15c = wcslen(L"EN");
      FUN_100039f0(local_80,(undefined4 *)&DAT_100266cc,local_15c);
      DVar1 = local_88;
    }
  }
  local_88 = DVar1;
  FUN_10004960(local_a8,L"_");
  local_8._0_1_ = 9;
  local_170 = (wchar_t *)FUN_10012f70(local_80);
  local_16c = wcslen(local_170);
  FUN_10014d10(local_a8,(undefined4 *)local_170,local_16c);
  local_174 = wcslen(L".");
  FUN_10014d10(local_a8,(undefined4 *)&DAT_10026f94,local_174);
  FUN_10004960(local_f0,L"_EN.");
  local_8._0_1_ = 10;
  (**(code **)(*local_14 + 0x38))();
  local_8._0_1_ = 0xb;
  FUN_10003930(local_f0,'\x01',0);
  local_8._0_1_ = 9;
  FUN_10004960(local_10c,L"_en.");
  local_8._0_1_ = 0xc;
  (**(code **)(*local_14 + 0x38))(local_38,local_10c);
  auStack_200[0] = 0x100107cd;
  local_8._0_1_ = 0xd;
  FUN_10003930(local_10c,'\x01',0);
  local_8._0_1_ = 9;
  local_190 = (LPCWSTR)FUN_10012f70(local_38);
  local_18 = LoadLibraryW(local_190);
  local_8._0_1_ = 0xe;
  FUN_10003930(local_a8,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,6);
LAB_10010822:
  if (local_18 == (HMODULE)0x0) {
    local_88 = GetLastError();
  }
  else {
    (**(code **)(*local_14 + 0x20))();
    local_14[1] = 1;
  }
  local_194 = &local_195;
  local_1c8 = local_cc;
  local_8._0_1_ = 0xf;
  FUN_10003930(local_cc,'\0',0);
  local_110 = &stack0xfffffdd8;
  local_1cc = &stack0xfffffdd8;
  local_1ac = &stack0xfffffdd8;
  local_1a0 = &local_1a1;
  local_8._0_1_ = 0x11;
  FUN_10003930(&stack0xfffffdd8,'\0',0);
  FUN_10003b40(local_1ac,(undefined4 *)&stack0x00000004,0,0xffffffff);
  local_1d0 = local_1ac;
  local_8._0_1_ = 0x10;
  local_1d8[1] = (**(code **)(*local_14 + 0x44))();
  local_1d8[0] = local_1d8[1];
  if (0 < (int)local_1d8[1]) {
    local_1d8[0] = local_1d8[1] & 0xffff | 0x80070000;
  }
  local_114 = local_1d8[0];
  local_8._0_1_ = 0x13;
  local_88 = local_1d8[1];
  FUN_10003930(local_cc,'\x01',0);
  local_8._0_1_ = 0x14;
  FUN_10003930(local_80,'\x01',0);
  local_8._0_1_ = 0x15;
  FUN_10003930(local_5c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,0x16);
  FUN_10003930(local_38,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100038d0(&stack0x00000004);
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10010a00);
  ExceptionList = local_10;
  return CONCAT44(uVar4,local_114);
}



// Function: FUN_10010a90 at 10010a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010a90(LPCWSTR param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  LPCWSTR **pppWVar2;
  undefined8 uVar3;
  uint in_stack_00000018;
  void *in_stack_00000020;
  undefined4 uVar4;
  LPCWSTR *local_260 [2];
  LSTATUS local_258;
  size_t local_248;
  int local_244;
  LSTATUS local_240;
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001e9e8;
  local_10 = ExceptionList;
  pppWVar2 = local_260;
  for (iVar1 = 0x94; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar2 = (LPCWSTR *)0xcccccccc;
    pppWVar2 = pppWVar2 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 1;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  if (in_stack_00000018 < 8) {
    local_260[0] = &param_1;
  }
  else {
    local_260[0] = (LPCWSTR *)param_1;
  }
  local_240 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_260[0],0x2001f);
  if (local_240 == 0) {
    uVar3 = FUN_10010c90(&local_24,L"ResourceDLL",(LPBYTE)&local_234,local_23c);
    local_240 = (LSTATUS)uVar3;
  }
  if ((local_240 == 0) && (local_23c[0] != 0)) {
    local_248 = wcslen(&local_234);
    FUN_100039f0(in_stack_00000020,(undefined4 *)&local_234,local_248);
  }
  local_244 = local_240;
  local_8 = local_8 & 0xffffff00;
  local_258 = 0;
  if (local_24 != (HKEY)0x0) {
    local_258 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
  }
  local_20 = 0;
  local_8 = 2;
  FUN_10003930(&param_1,'\x01',0);
  local_8 = 0xffffffff;
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10010c54);
  ExceptionList = local_10;
  return CONCAT44(uVar4,local_244);
}



// Function: FUN_10010c90 at 10010c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10010c90(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  LSTATUS LVar1;
  uint *extraout_EDX;
  uint *puVar2;
  uint local_20 [3];
  DWORD local_14 [3];
  void *local_8;
  
  local_20[1] = 0xcccccccc;
  local_20[2] = 0xcccccccc;
  local_14[0] = 0xcccccccc;
  local_14[1] = 0xcccccccc;
  local_14[2] = 0xcccccccc;
  local_20[0] = *param_3 << 1;
  *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  local_14[2] = RegQueryValueExW(*this,param_1,(LPDWORD)0x0,local_14,param_2,local_20);
  LVar1 = local_14[2];
  puVar2 = extraout_EDX;
  if (local_14[2] == 0) {
    if ((local_14[0] == 1) || (local_14[0] == 2)) {
      if (param_2 != (LPBYTE)0x0) {
        if (local_20[0] == 0) {
          param_2[0] = '\0';
          param_2[1] = '\0';
        }
        else {
          puVar2 = (uint *)(local_20[0] % 2);
          if ((puVar2 != (uint *)0x0) ||
             (puVar2 = (uint *)(local_20[0] >> 1), *(short *)(param_2 + (int)puVar2 * 2 + -2) != 0))
          {
            LVar1 = 0xd;
            goto LAB_10010d64;
          }
        }
      }
      *param_3 = local_20[0] >> 1;
      LVar1 = 0;
      puVar2 = param_3;
    }
    else {
      LVar1 = 0xd;
      puVar2 = extraout_EDX;
    }
  }
LAB_10010d64:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10010d88);
  return CONCAT44(puVar2,LVar1);
}



// Function: FUN_10010dc0 at 10010dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010dc0(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  LPCWSTR **pppWVar3;
  undefined8 uVar4;
  LPCWSTR *local_294;
  LSTATUS local_290;
  size_t local_280;
  size_t local_27c;
  int local_268;
  LSTATUS local_264;
  LPCWSTR *local_25c [5];
  uint local_248;
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ea1e;
  local_10 = ExceptionList;
  pppWVar3 = &local_294;
  for (iVar1 = 0xa1; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar3 = (LPCWSTR *)0xcccccccc;
    pppWVar3 = pppWVar3 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  FUN_10004960(local_25c,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_27c = wcslen(L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}");
  FUN_10014d10(local_25c,(undefined4 *)L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}",local_27c);
  if (local_248 < 8) {
    local_294 = (LPCWSTR *)local_25c;
  }
  else {
    local_294 = local_25c[0];
  }
  local_264 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_294,0x2001f);
  if (local_264 == 0) {
    uVar4 = FUN_10010c90(&local_24,L"ResourceDLL",(LPBYTE)&local_234,local_23c);
    local_264 = (LSTATUS)uVar4;
  }
  if ((local_264 == 0) && (local_23c[0] != 0)) {
    local_280 = wcslen(&local_234);
    FUN_100039f0(param_1,(undefined4 *)&local_234,local_280);
  }
  local_268 = local_264;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10003930(local_25c,'\x01',0);
  local_8 = 0xffffffff;
  local_290 = 0;
  uVar2 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_290 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar2 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10010fd0);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_268);
}



// Function: FUN_10011020 at 10011020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10011020(LPCWSTR param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  LPCWSTR **pppWVar2;
  undefined8 uVar3;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 uVar4;
  LPCWSTR *local_464 [3];
  LSTATUS local_458;
  int local_454;
  LSTATUS local_450;
  uint local_44c [2];
  BYTE local_444 [528];
  BYTE local_234 [528];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001e9e8;
  local_10 = ExceptionList;
  pppWVar2 = local_464;
  for (iVar1 = 0x115; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar2 = (LPCWSTR *)0xcccccccc;
    pppWVar2 = pppWVar2 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 1;
  local_234[0] = '\0';
  local_234[1] = '\0';
  ExceptionList = &local_10;
  memset(local_234 + 2,0,0x206);
  local_444[0] = '\0';
  local_444[1] = '\0';
  memset(local_444 + 2,0,0x206);
  local_44c[0] = 0x208;
  if (in_stack_00000018 < 8) {
    local_464[0] = &param_1;
  }
  else {
    local_464[0] = (LPCWSTR *)param_1;
  }
  local_450 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_464[0],0x2001f);
  if (local_450 == 0) {
    uVar3 = FUN_10010c90(&local_24,L"XMLResource",local_234,local_44c);
    local_450 = (LSTATUS)uVar3;
    local_44c[0] = 0x208;
  }
  FUN_10010c90(&local_24,L"FriendlyName",local_444,local_44c);
  if ((local_450 == 0) && (local_44c[0] != 0)) {
    local_450 = (**(code **)(*local_14 + 0xc))(local_234,in_stack_00000020);
  }
  local_454 = local_450;
  local_8 = local_8 & 0xffffff00;
  local_458 = 0;
  if (local_24 != (HKEY)0x0) {
    local_458 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
  }
  local_20 = 0;
  local_8 = 2;
  FUN_10003930(&param_1,'\x01',0);
  local_8 = 0xffffffff;
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10011218);
  ExceptionList = local_10;
  return CONCAT44(uVar4,local_454);
}



// Function: FUN_10011260 at 10011260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10011260(void)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint local_174;
  LPCWSTR **local_170;
  undefined4 *local_16c;
  undefined4 *local_168;
  LPCWSTR **local_164;
  size_t local_15c;
  size_t local_158;
  LPCWSTR local_154;
  size_t local_138;
  wchar_t *local_134;
  size_t local_130;
  size_t local_120;
  int local_11c;
  int local_118;
  LPCWSTR local_114;
  LPCWSTR local_110;
  undefined1 local_105;
  undefined1 *local_104;
  undefined1 local_f9;
  undefined1 *local_f8;
  undefined1 local_ed;
  undefined1 *local_ec;
  uint local_e8;
  undefined1 local_e4 [28];
  undefined1 local_c8 [32];
  undefined1 local_a8 [32];
  uint local_88;
  undefined4 local_80 [4];
  int local_70;
  undefined4 local_5c [9];
  LPCWSTR **local_38 [5];
  uint local_24;
  HMODULE local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eaba;
  local_10 = ExceptionList;
  puVar3 = &local_174;
  for (iVar2 = 0x59; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = (HMODULE)0x0;
  local_ec = &local_ed;
  local_164 = (LPCWSTR **)local_38;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(local_38,'\0',0);
  local_f8 = &local_f9;
  local_168 = local_5c;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10003930(local_5c,'\0',0);
  local_104 = &local_105;
  local_16c = local_80;
  local_8._0_1_ = 4;
  FUN_10003930(local_80,'\0',0);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_88 = 0;
  local_88 = (**(code **)(*local_14 + 0x24))(local_38);
  uVar5 = 0x10011343;
  local_110 = (LPCWSTR)FUN_10012f70(local_38);
  local_18 = LoadLibraryW(local_110);
  uVar4 = 0x1001136d;
  if ((local_88 == 0) && (local_18 != (HMODULE)0x0)) goto LAB_100116c2;
  local_88 = (**(code **)(*local_14 + 0x28))(local_38,0x1001136d,uVar5);
  uVar5 = 0x1001139d;
  local_114 = (LPCWSTR)FUN_10012f70(local_38);
  local_18 = LoadLibraryW(local_114);
  uVar4 = 0x100113c7;
  if ((local_88 == 0) && (local_18 != (HMODULE)0x0)) goto LAB_100116c2;
  local_88 = (**(code **)(*local_14 + 0x14))(local_80,0x100113c7,uVar5);
  if (local_88 == 0) {
    local_118 = local_70;
    uVar1 = 0;
    if (local_70 == 0) goto LAB_10011418;
  }
  else {
LAB_10011418:
    local_88 = (**(code **)(*local_14 + 0x10))(local_80,0x100113f7);
    if ((local_88 != 0) || (local_11c = local_70, uVar1 = local_88, local_70 == 0)) {
      local_120 = wcslen(L"EN");
      FUN_100039f0(local_80,(undefined4 *)&DAT_100266cc,local_120);
      uVar1 = local_88;
    }
  }
  local_88 = uVar1;
  FUN_10004960(local_a8,L"_");
  local_8._0_1_ = 6;
  local_134 = (wchar_t *)FUN_10012f70(local_80);
  local_130 = wcslen(local_134);
  uVar5 = 0x100114bf;
  FUN_10014d10(local_a8,(undefined4 *)local_134,local_130);
  local_138 = wcslen(L".");
  uVar4 = 0x100114f5;
  FUN_10014d10(local_a8,(undefined4 *)&DAT_10026f94,local_138);
  FUN_10004960(local_c8,L"_EN.");
  local_8._0_1_ = 7;
  (**(code **)(*local_14 + 0x38))(local_38,local_c8,local_a8,uVar4,uVar5);
  uVar4 = 0x1001154e;
  local_8._0_1_ = 8;
  FUN_10003930(local_c8,'\x01',0);
  local_8._0_1_ = 6;
  FUN_10004960(local_e4,L"_en.");
  local_8._0_1_ = 9;
  (**(code **)(*local_14 + 0x38))(local_38,local_e4,local_a8,uVar4);
  uVar5 = 0x100115a1;
  local_8._0_1_ = 10;
  FUN_10003930(local_e4,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,6);
  local_154 = (LPCWSTR)FUN_10012f70(local_38);
  local_18 = LoadLibraryW(local_154);
  uVar4 = 0x100115dc;
  if ((local_88 != 0) || (local_18 == (HMODULE)0x0)) {
    local_88 = (**(code **)(*local_14 + 0x30))(local_5c,0x100115dc,uVar5);
    uVar4 = 0x1001160c;
    if (local_88 == 0) {
      FUN_10003b40(local_38,local_5c,0,0xffffffff);
      local_158 = wcslen(L"Res_");
      FUN_10014d10(local_38,(undefined4 *)L"Res_",local_158);
      FUN_10014ba0(local_38,local_80,0,0xffffffff);
      local_15c = wcslen(L".dll");
      uVar4 = 0x10011691;
      FUN_10014d10(local_38,(undefined4 *)L".dll",local_15c);
    }
  }
  local_8._0_1_ = 0xb;
  FUN_10003930(local_a8,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,5);
LAB_100116c2:
  if (local_18 == (HMODULE)0x0) {
    if (local_24 < 8) {
      local_170 = (LPCWSTR **)local_38;
    }
    else {
      local_170 = local_38[0];
    }
    local_18 = LoadLibraryW((LPCWSTR)local_170);
    if (local_18 == (HMODULE)0x0) {
      local_88 = GetLastError();
    }
    else {
      (**(code **)(*local_14 + 0x20))(local_18,0x100116f8);
      local_14[1] = 1;
    }
  }
  else {
    (**(code **)(*local_14 + 0x20))(local_18,uVar4);
    local_14[1] = 1;
  }
  if ((int)local_88 < 1) {
    local_174 = local_88;
  }
  else {
    local_174 = local_88 & 0xffff | 0x80070000;
  }
  local_e8 = local_174;
  local_8._0_1_ = 0xc;
  FUN_10003930(local_80,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_10003930(local_5c,'\x01',0);
  local_8 = 0xe;
  FUN_10003930(local_38,'\x01',0);
  local_8 = 0xffffffff;
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_1001181c);
  ExceptionList = local_10;
  return CONCAT44(uVar4,local_e8);
}



// Function: FUN_10011890 at 10011890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10011890(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0x80004005;
  local_10 = 1;
  if ((DAT_100308ec != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) {
    local_10 = FreeLibrary(DAT_100308ec);
  }
  if (local_10 == 1) {
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10011910 at 10011910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10011910(wchar_t *param_1,undefined4 param_2)

{
  int iVar1;
  void **ppvVar2;
  void *local_58 [9];
  undefined1 local_34 [28];
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001eae0;
  local_10 = ExceptionList;
  ppvVar2 = local_58;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  local_58[0] = FUN_10004960(local_34,param_1);
  local_8 = 0;
  local_58[1] = local_58[0];
  local_18 = (**(code **)(*local_14 + 8))(local_58[0],param_2);
  local_8 = 1;
  FUN_10003930(local_34,'\x01',0);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100119c0 at 100119c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100119c0(undefined4 *param_1,void *param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  wchar_t ***pppwVar2;
  undefined4 uVar3;
  wchar_t **local_d4 [9];
  wchar_t **local_b0;
  size_t local_ac;
  undefined4 local_a8;
  ushort local_a4 [2];
  undefined4 local_a0;
  ushort local_9c [2];
  uint local_98;
  undefined1 local_8d;
  undefined1 *local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  undefined1 local_75;
  undefined1 *local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_5c [8];
  int local_3c;
  wchar_t **local_34 [4];
  uint local_24;
  uint local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eb20;
  local_10 = ExceptionList;
  pppwVar2 = local_d4;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppwVar2 = (wchar_t **)0xcccccccc;
    pppwVar2 = pppwVar2 + 1;
  }
  local_74 = &local_75;
  local_d4[1] = (wchar_t **)local_34;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(local_34,'\0',0);
  local_8 = 1;
  local_3c = (**(code **)(*local_14 + 0x14))(local_34);
  if ((local_3c != 0) || (local_80 = local_24, iVar1 = 0, local_24 == 0)) {
    local_3c = (**(code **)(*local_14 + 0x10))(local_34,0x10011a3a);
    if ((local_3c != 0) || (local_84 = local_24, iVar1 = local_3c, local_24 == 0)) {
      FUN_10003b40(param_2,param_1,0,0xffffffff);
      iVar1 = local_3c;
    }
  }
  local_3c = iVar1;
  if ((local_3c == 0) && (local_88 = local_24, local_24 != 0)) {
    local_8c = &local_8d;
    local_d4[0] = (wchar_t **)local_5c;
    local_8._0_1_ = 2;
    FUN_10003930(local_5c,'\0',0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_10003b40(local_5c,param_1,0,0xffffffff);
    local_98 = local_24;
    local_64 = local_24;
    local_a0 = 0xffffffff;
    local_9c[0] = 0x5f;
    local_68 = FUN_10015730(local_5c,local_9c,0xffffffff,1);
    local_a8 = 0xffffffff;
    local_a4[0] = 0x2e;
    local_6c = FUN_10015730(local_5c,local_a4,0xffffffff,1);
    if ((local_68 != 0xffffffff) && ((local_6c - local_68) - 1 == local_64)) {
      if (local_20 < 8) {
        local_b0 = (wchar_t **)local_34;
      }
      else {
        local_b0 = local_34[0];
      }
      local_ac = wcslen((wchar_t *)local_b0);
      FUN_10014eb0(local_5c,local_68 + 1,local_64,(int *)local_b0,local_ac);
    }
    FUN_10003b40(param_2,local_5c,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_10003930(local_5c,'\x01',0);
  }
  local_70 = local_3c;
  local_8 = 5;
  FUN_10003930(local_34,'\x01',0);
  local_8 = 0xffffffff;
  uVar3 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10011c54);
  ExceptionList = local_10;
  return CONCAT44(uVar3,local_70);
}



// Function: FUN_10011c90 at 10011c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10011c90(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  LPCWSTR **pppWVar3;
  undefined8 uVar4;
  LPCWSTR *local_294;
  LSTATUS local_290;
  size_t local_280;
  size_t local_27c;
  int local_268;
  LSTATUS local_264;
  LPCWSTR *local_25c [5];
  uint local_248;
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ea1e;
  local_10 = ExceptionList;
  pppWVar3 = &local_294;
  for (iVar1 = 0xa1; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar3 = (LPCWSTR *)0xcccccccc;
    pppWVar3 = pppWVar3 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  FUN_10004960(local_25c,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\");
  local_8 = CONCAT31(local_8._1_3_,1);
  local_27c = wcslen(L"Locale");
  FUN_10014d10(local_25c,(undefined4 *)L"Locale",local_27c);
  if (local_248 < 8) {
    local_294 = (LPCWSTR *)local_25c;
  }
  else {
    local_294 = local_25c[0];
  }
  local_264 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_294,0x2001f);
  if (local_264 == 0) {
    uVar4 = FUN_10010c90(&local_24,L"LanguageExt",(LPBYTE)&local_234,local_23c);
    local_264 = (LSTATUS)uVar4;
  }
  if ((local_264 == 0) && (local_23c[0] != 0)) {
    local_280 = wcslen(&local_234);
    FUN_100039f0(param_1,(undefined4 *)&local_234,local_280);
  }
  local_268 = local_264;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10003930(local_25c,'\x01',0);
  local_8 = 0xffffffff;
  local_290 = 0;
  uVar2 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_290 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar2 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10011ea0);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_268);
}



// Function: FUN_10011ef0 at 10011ef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10011ef0(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  LPCWSTR **pppWVar3;
  undefined8 uVar4;
  LPCWSTR *local_2bc;
  LSTATUS local_2b8;
  size_t local_2b0;
  size_t local_2ac;
  size_t local_2a8;
  int local_28c;
  LSTATUS local_288;
  LPCWSTR *local_280 [5];
  uint local_26c;
  undefined4 local_25c [8];
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eb64;
  local_10 = ExceptionList;
  pppWVar3 = &local_2bc;
  for (iVar1 = 0xab; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar3 = (LPCWSTR *)0xcccccccc;
    pppWVar3 = pppWVar3 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  FUN_10004960(local_25c,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10004960(local_280,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10014ba0(local_280,local_25c,0,0xffffffff);
  local_2a8 = wcslen(L"\\AddIns\\");
  FUN_10014d10(local_280,(undefined4 *)L"\\AddIns\\",local_2a8);
  local_2ac = wcslen(L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}");
  FUN_10014d10(local_280,(undefined4 *)L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}",local_2ac);
  if (local_26c < 8) {
    local_2bc = (LPCWSTR *)local_280;
  }
  else {
    local_2bc = local_280[0];
  }
  local_288 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_2bc,0x2001f);
  if (local_288 == 0) {
    uVar4 = FUN_10010c90(&local_24,L"LanguageExt",(LPBYTE)&local_234,local_23c);
    local_288 = (LSTATUS)uVar4;
  }
  if ((local_288 == 0) && (local_23c[0] != 0)) {
    local_2b0 = wcslen(&local_234);
    FUN_100039f0(param_1,(undefined4 *)&local_234,local_2b0);
  }
  local_28c = local_288;
  local_8._0_1_ = 3;
  FUN_10003930(local_280,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10003930(local_25c,'\x01',0);
  local_8 = 0xffffffff;
  local_2b8 = 0;
  uVar2 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_2b8 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar2 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10012178);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_28c);
}



// Function: FUN_100121e0 at 100121e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100121e0(void)

{
  uint uVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  wchar_t **ppwVar4;
  undefined4 uVar5;
  wchar_t *local_8c [8];
  size_t local_6c;
  size_t local_60;
  uint local_5c;
  undefined1 local_4d;
  undefined1 *local_4c;
  ushort local_46;
  ushort local_44;
  ushort local_40;
  int local_3c;
  wchar_t local_34 [8];
  uint local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eb88;
  local_10 = ExceptionList;
  ppwVar4 = local_8c;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppwVar4 = (wchar_t *)0xcccccccc;
    ppwVar4 = ppwVar4 + 1;
  }
  local_4c = &local_4d;
  local_8c[0] = local_34;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(local_34,'\0',0);
  local_8 = 1;
  local_3c = 0;
  local_3c = (**(code **)(*local_14 + 0x10))(local_34);
  if ((local_3c != 0) || (local_5c = local_24, local_24 == 0)) {
    local_60 = wcslen(L"EN");
    FUN_100039f0(local_34,(undefined4 *)&DAT_100266cc,local_60);
  }
  local_44 = 0;
  local_40 = 0;
  do {
    if ((&PTR_DAT_1002f140)[local_40] == (undefined *)0x0) {
LAB_10012323:
      local_46 = local_44;
      local_8 = 2;
      FUN_10003930(local_34,'\x01',0);
      local_8 = 0xffffffff;
      uVar2 = CONCAT22(extraout_var,local_46);
      uVar5 = extraout_EDX;
      _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10012378);
      ExceptionList = local_10;
      return CONCAT44(uVar5,uVar2);
    }
    local_8c[2] = (wchar_t *)(&PTR_DAT_1002f140)[local_40];
    local_6c = wcslen(local_8c[2]);
    uVar1 = FUN_10018310(local_34,0,local_24,(ushort *)local_8c[2],local_6c);
    if (uVar1 == 0) {
      local_44 = local_40;
      goto LAB_10012323;
    }
    local_40 = local_40 + 1;
  } while( true );
}



// Function: FUN_100123a0 at 100123a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined2 __fastcall FUN_100123a0(int *param_1)

{
  ushort uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_100269c0 + (uint)uVar1 * 2);
}



// Function: FUN_10012400 at 10012400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012400(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10030948);
    InterlockedExchange(&DAT_100308ec,param_1);
    DAT_100308e8 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10030948);
  }
  return;
}



// Function: FUN_10012480 at 10012480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10012480(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  LPCWSTR **pppWVar3;
  undefined8 uVar4;
  LPCWSTR *local_2bc;
  LSTATUS local_2b8;
  size_t local_2b0;
  size_t local_2ac;
  size_t local_2a8;
  int local_28c;
  LSTATUS local_288;
  LPCWSTR *local_280 [5];
  uint local_26c;
  undefined4 local_25c [8];
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eb64;
  local_10 = ExceptionList;
  pppWVar3 = &local_2bc;
  for (iVar1 = 0xab; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar3 = (LPCWSTR *)0xcccccccc;
    pppWVar3 = pppWVar3 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  FUN_10004960(local_25c,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10004960(local_280,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10014ba0(local_280,local_25c,0,0xffffffff);
  local_2a8 = wcslen(L"\\AddIns\\");
  FUN_10014d10(local_280,(undefined4 *)L"\\AddIns\\",local_2a8);
  local_2ac = wcslen(L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}");
  FUN_10014d10(local_280,(undefined4 *)L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}",local_2ac);
  if (local_26c < 8) {
    local_2bc = (LPCWSTR *)local_280;
  }
  else {
    local_2bc = local_280[0];
  }
  local_288 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_2bc,0x2001f);
  if (local_288 == 0) {
    uVar4 = FUN_10010c90(&local_24,L"ResourceDLL",(LPBYTE)&local_234,local_23c);
    local_288 = (LSTATUS)uVar4;
  }
  if ((local_288 == 0) && (local_23c[0] != 0)) {
    local_2b0 = wcslen(&local_234);
    FUN_100039f0(param_1,(undefined4 *)&local_234,local_2b0);
  }
  local_28c = local_288;
  local_8._0_1_ = 3;
  FUN_10003930(local_280,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10003930(local_25c,'\x01',0);
  local_8 = 0xffffffff;
  local_2b8 = 0;
  uVar2 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_2b8 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar2 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10012708);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_28c);
}



// Function: FUN_10012770 at 10012770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10012770(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  LPCWSTR ****pppppWVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  LPCWSTR ***local_498;
  LSTATUS local_494;
  size_t local_48c;
  int local_478;
  LSTATUS local_474;
  LPCWSTR ***local_46c [5];
  uint local_458;
  uint local_44c [2];
  BYTE local_444 [528];
  BYTE local_234 [528];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ebbe;
  local_10 = ExceptionList;
  pppppWVar2 = &local_498;
  for (iVar1 = 0x122; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppppWVar2 = (LPCWSTR ***)0xcccccccc;
    pppppWVar2 = pppppWVar2 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234[0] = '\0';
  local_234[1] = '\0';
  ExceptionList = &local_10;
  memset(local_234 + 2,0,0x206);
  local_444[0] = '\0';
  local_444[1] = '\0';
  memset(local_444 + 2,0,0x206);
  local_44c[0] = 0x208;
  FUN_10004960(local_46c,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_48c = wcslen(L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}");
  uVar4 = 0x10012836;
  FUN_10014d10(local_46c,(undefined4 *)L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}",local_48c);
  if (local_458 < 8) {
    local_498 = (LPCWSTR ***)local_46c;
  }
  else {
    local_498 = local_46c[0];
  }
  local_474 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_498,0x2001f);
  if (local_474 == 0) {
    uVar3 = FUN_10010c90(&local_24,L"XMLResource",local_234,local_44c);
    local_474 = (LSTATUS)uVar3;
    local_44c[0] = 0x208;
  }
  FUN_10010c90(&local_24,L"FriendlyName",local_444,local_44c);
  if ((local_474 == 0) && (local_44c[0] != 0)) {
    local_474 = (**(code **)(*local_14 + 0xc))(local_234,param_1,uVar4);
  }
  local_478 = local_474;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10003930(local_46c,'\x01',0);
  local_8 = 0xffffffff;
  local_494 = 0;
  uVar4 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_494 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar4 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100129b4);
  ExceptionList = local_10;
  return CONCAT44(uVar4,local_478);
}



// Function: FUN_10012a10 at 10012a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10012a10(void *param_1)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  LPCWSTR **pppWVar3;
  undefined8 uVar4;
  LPCWSTR *local_294;
  LSTATUS local_290;
  size_t local_280;
  size_t local_27c;
  int local_268;
  LSTATUS local_264;
  LPCWSTR *local_25c [5];
  uint local_248;
  uint local_23c [2];
  wchar_t local_234;
  undefined1 local_232 [526];
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ea1e;
  local_10 = ExceptionList;
  pppWVar3 = &local_294;
  for (iVar1 = 0xa1; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pppWVar3 = (LPCWSTR *)0xcccccccc;
    pppWVar3 = pppWVar3 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  local_234 = L'\0';
  ExceptionList = &local_10;
  memset(local_232,0,0x206);
  local_23c[0] = 0x208;
  FUN_10004960(local_25c,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_27c = wcslen(L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}");
  FUN_10014d10(local_25c,(undefined4 *)L"{73903FF3-7327-47E2-9ED9-FBF4A86B6FCB}",local_27c);
  if (local_248 < 8) {
    local_294 = (LPCWSTR *)local_25c;
  }
  else {
    local_294 = local_25c[0];
  }
  local_264 = FUN_1000bbb0(&local_24,(HKEY)0x80000002,(LPCWSTR)local_294,0x2001f);
  if (local_264 == 0) {
    uVar4 = FUN_10010c90(&local_24,L"BaseName",(LPBYTE)&local_234,local_23c);
    local_264 = (LSTATUS)uVar4;
  }
  if ((local_264 == 0) && (local_23c[0] != 0)) {
    local_280 = wcslen(&local_234);
    FUN_100039f0(param_1,(undefined4 *)&local_234,local_280);
  }
  local_268 = local_264;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10003930(local_25c,'\x01',0);
  local_8 = 0xffffffff;
  local_290 = 0;
  uVar2 = extraout_EDX;
  if (local_24 != (HKEY)0x0) {
    local_290 = RegCloseKey(local_24);
    local_24 = (HKEY)0x0;
    uVar2 = extraout_EDX_00;
  }
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10012c20);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_268);
}



// Function: FUN_10012c70 at 10012c70

undefined4 FUN_10012c70(void)

{
  return DAT_100308ec;
}



// Function: FUN_10012c90 at 10012c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012c90(void *param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t **ppwVar2;
  wchar_t *local_38 [4];
  size_t local_28;
  uint local_24;
  wchar_t *local_20;
  size_t local_1c;
  int local_18;
  wchar_t *local_14;
  size_t local_10;
  uint local_c;
  
  ppwVar2 = local_38;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppwVar2 = (wchar_t *)0xcccccccc;
    ppwVar2 = ppwVar2 + 1;
  }
  if (*(uint *)(param_2 + 10) < 8) {
    local_14 = param_2;
  }
  else {
    local_14 = *(wchar_t **)param_2;
  }
  local_10 = wcslen(local_14);
  for (local_c = FUN_10012dc0(param_1,(ushort *)local_14,0,local_10); local_c != 0xffffffff;
      local_c = FUN_10012dc0(param_1,(ushort *)local_20,local_c + local_18,local_1c)) {
    if (*(uint *)(param_3 + 10) < 8) {
      local_38[0] = param_3;
    }
    else {
      local_38[0] = *(wchar_t **)param_3;
    }
    local_24 = *(uint *)(param_2 + 8);
    local_28 = wcslen(local_38[0]);
    FUN_10014eb0(param_1,local_c,local_24,(int *)local_38[0],local_28);
    local_18 = *(int *)(param_3 + 8);
    if (*(uint *)(param_2 + 10) < 8) {
      local_20 = param_2;
    }
    else {
      local_20 = *(wchar_t **)param_2;
    }
    local_1c = wcslen(local_20);
  }
  return;
}



// Function: FUN_10012dc0 at 10012dc0

uint __thiscall FUN_10012dc0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  void **ppvVar3;
  void *local_38 [2];
  int local_30;
  uint local_2c;
  ushort *local_28;
  ushort *local_24;
  ushort *local_20;
  int local_1c;
  ushort *local_18;
  ushort *local_14;
  int local_c;
  
  ppvVar3 = local_38;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar2 = *(int *)((int)this + 0x10) - param_2, param_3 <= uVar2)) {
      local_c = uVar2 - (param_3 - 1);
      local_38[1] = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_38[1] = *this;
      }
      local_14 = (ushort *)((int)local_38[1] + param_2 * 2);
      do {
        local_18 = local_14;
        for (local_1c = local_c; local_1c != 0; local_1c = local_1c + -1) {
          if (*local_18 == *param_1) {
            local_20 = local_18;
            goto LAB_10012eb3;
          }
          local_18 = local_18 + 1;
        }
        local_20 = (ushort *)0x0;
LAB_10012eb3:
        if (local_20 == (ushort *)0x0) break;
        local_28 = param_1;
        local_24 = local_20;
        for (local_2c = param_3; local_2c != 0; local_2c = local_2c - 1) {
          if (*local_24 != *local_28) {
            local_30 = (uint)(*local_28 <= *local_24) * 2 + -1;
            goto LAB_10012f2d;
          }
          local_24 = local_24 + 1;
          local_28 = local_28 + 1;
        }
        local_30 = 0;
LAB_10012f2d:
        if (local_30 == 0) {
          local_38[0] = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            local_38[0] = *this;
          }
          return (int)local_20 - (int)local_38[0] >> 1;
        }
        local_c = local_c - (((int)local_20 - (int)local_14 >> 1) + 1);
        local_14 = local_20 + 1;
      } while( true );
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_10012f70 at 10012f70

undefined4 * __fastcall FUN_10012f70(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)*param_1;
  }
  return local_c;
}



// Function: Free at 10012fb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned short>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: ~CTempBuffer<> at 10013000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100148f0(param_1);
  }
  return;
}



// Function: FUN_10013040 at 10013040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10013040(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10014af0(param_1,2);
  if (uVar1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10014990(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100130b0 at 100130b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100130b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 *local_44 [5];
  undefined4 *local_30;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ebf9;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_44;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb0;
  local_24 = (undefined4 *)operator_new(0x38);
  uVar1 = local_8 >> 8;
  if (local_24 == (undefined4 *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_30 = local_24 + 1;
    *local_30 = 0;
    local_8._1_3_ = (uint3)(local_8 >> 8);
    local_8._0_1_ = 3;
    *local_24 = ATL::CComAggObject<class_CSFStringLoader>::vftable;
    FUN_10017e70(local_24 + 3,param_1);
    local_8._0_1_ = 4;
    (**(code **)(*DAT_100302e0 + 4))();
    uVar1 = (uint)local_8._1_3_;
    local_44[1] = local_24;
  }
  local_20 = local_44[1];
  local_8 = uVar1 << 8;
  local_1c = local_44[1];
  uVar2 = FUN_100131aa();
  return uVar2;
}



// Function: Catch@1001319d at 1001319d

undefined4 Catch_1001319d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100131b1;
}



// Function: FUN_100131aa at 100131aa

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100131aa(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined8 uVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10015b40(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar3 = FUN_10010280();
      *(int *)(unaff_EBP + -0x14) = (int)uVar3;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10013280 at 10013280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013280(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_3c [7];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ec18;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb8;
  local_20 = (undefined4 *)operator_new(0x4c);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_10013460((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CParameterComparer>::vftable;
    local_20[1] = ATL::CComObject<class_CParameterComparer>::vftable;
    (**(code **)(*DAT_100302e0 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_10013354();
  return uVar1;
}



// Function: Catch@10013347 at 10013347

undefined4 Catch_10013347(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001335b;
}



// Function: FUN_10013354 at 10013354

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013354(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 8));
    uStack00000004 = 0x10013383;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 0xc;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
    *(DWORD *)(unaff_EBP + -0x30) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x30)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x2c) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 8));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10013460 at 10013460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10013460(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [9];
  undefined4 *local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ecc9;
  local_10 = ExceptionList;
  puVar2 = local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = (undefined4 *)(param_1 + 8);
  ExceptionList = &local_10;
  *local_1c = 0;
  local_8 = 0;
  local_18 = (void *)(param_1 + 0xc);
  local_14 = param_1;
  FUN_100135c0(local_18);
  *(undefined4 *)(local_14 + 0x28) = 0;
  *(undefined4 *)(local_14 + 0x2c) = 0;
  *(undefined4 *)(local_14 + 0x30) = 0;
  *(undefined4 *)(local_14 + 0x34) = 0;
  *(undefined4 *)(local_14 + 0x38) = 0;
  *(undefined4 *)(local_14 + 0x3c) = 0;
  *(undefined4 *)(local_14 + 0x40) = 0;
  *(undefined4 *)(local_14 + 0x44) = 0;
  *(undefined4 *)(local_14 + 0x48) = 0;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100135c0 at 100135c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __fastcall FUN_100135c0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f4a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013630 at 10013630

undefined4 __fastcall FUN_10013630(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013650 at 10013650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013650(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 *local_3c [6];
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ed09;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_3c;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb8;
  local_24 = (undefined4 *)operator_new(0x58);
  uVar1 = local_8 >> 8;
  if (local_24 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    local_3c[3] = local_24 + 1;
    *local_3c[3] = 0;
    local_8._1_3_ = (uint3)(local_8 >> 8);
    local_8._0_1_ = 3;
    *local_24 = ATL::CComAggObject<class_CParameterComparer>::vftable;
    FUN_10018090(local_24 + 3,param_1);
    local_8._0_1_ = 4;
    (**(code **)(*DAT_100302e0 + 4))();
    uVar1 = (uint)local_8._1_3_;
    local_3c[1] = local_24;
  }
  local_20 = local_3c[1];
  local_8 = uVar1 << 8;
  local_1c = local_3c[1];
  uVar2 = FUN_1001374a();
  return uVar2;
}



// Function: Catch@1001373d at 1001373d

undefined4 Catch_1001373d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10013751;
}



// Function: FUN_1001374a at 1001374a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001374a(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10015e50(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10013810 at 10013810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013810(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_3c [7];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ed28;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb8;
  local_20 = (undefined4 *)operator_new(0x40);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_100139f0((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CConditionSetChecker>::vftable;
    local_20[1] = ATL::CComObject<class_CConditionSetChecker>::vftable;
    (**(code **)(*DAT_100302e0 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_100138e4();
  return uVar1;
}



// Function: Catch@100138d7 at 100138d7

undefined4 Catch_100138d7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100138eb;
}



// Function: FUN_100138e4 at 100138e4

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100138e4(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 8));
    uStack00000004 = 0x10013913;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 0xc;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
    *(DWORD *)(unaff_EBP + -0x30) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x30)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x2c) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 8));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x18))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100139f0 at 100139f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100139f0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ed97;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 0xc),0,0x18);
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  local_8 = 7;
  FUN_10013be0(param_1 + 0x30);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013ae0 at 10013ae0

undefined4 __fastcall FUN_10013ae0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013b00 at 10013b00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013b00(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d5a8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013b70 at 10013b70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013b70(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001edb8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10013c70(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013be0 at 10013be0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10013be0(int param_1)

{
  int aiStack_34 [2];
  undefined1 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ede0;
  local_10 = ExceptionList;
  aiStack_34[1] = 0xcccccccc;
  local_28 = 0xcccccccc;
  local_24 = 0xcccccccc;
  local_20 = 0xcccccccc;
  local_18 = 0xcccccccc;
  local_2c = (undefined1 *)aiStack_34;
  local_1c = (undefined1 *)aiStack_34;
  ExceptionList = &local_10;
  aiStack_34[0] = param_1;
  local_14 = param_1;
  FUN_100159e0(param_1);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013c70 at 10013c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013c70(void *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001edf8;
  local_10 = ExceptionList;
  ppvVar2 = &local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_8 = 0;
  local_38 = *(int **)((int)param_1 + 4);
  local_1c = *(undefined4 **)((int)param_1 + 4);
  local_40 = (int *)*local_1c;
  ExceptionList = &local_10;
  local_3c = local_40;
  local_34 = local_38;
  local_20 = local_40;
  local_18 = local_38;
  local_14 = param_1;
  FUN_100158c0(param_1,&local_44,local_40,local_38);
  local_8 = 0xffffffff;
  local_48 = *(void **)((int)local_14 + 4);
  operator_delete(local_48);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013d30 at 10013d30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013d30(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10013d70 at 10013d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013d70(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 *local_3c [6];
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ee39;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_3c;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb8;
  local_24 = (undefined4 *)operator_new(0x4c);
  uVar1 = local_8 >> 8;
  if (local_24 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    local_3c[3] = local_24 + 1;
    *local_3c[3] = 0;
    local_8._1_3_ = (uint3)(local_8 >> 8);
    local_8._0_1_ = 3;
    *local_24 = ATL::CComAggObject<class_CConditionSetChecker>::vftable;
    FUN_100181b0(local_24 + 3,param_1);
    local_8._0_1_ = 4;
    (**(code **)(*DAT_100302e0 + 4))();
    uVar1 = (uint)local_8._1_3_;
    local_3c[1] = local_24;
  }
  local_20 = local_3c[1];
  local_8 = uVar1 << 8;
  local_1c = local_3c[1];
  uVar2 = FUN_10013e6a();
  return uVar2;
}



// Function: Catch@10013e5d at 10013e5d

undefined4 Catch_10013e5d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10013e71;
}



// Function: FUN_10013e6a at 10013e6a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013e6a(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10015e50(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10013f30 at 10013f30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013f30(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_40 [5];
  undefined4 *local_2c;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ee76;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_40;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb4;
  local_20 = (undefined4 *)operator_new(0x28);
  if (local_20 == (undefined4 *)0x0) {
    local_40[1] = (undefined4 *)0x0;
  }
  else {
    FUN_1000f530(local_20 + 1);
    local_2c = local_20 + 9;
    *local_2c = 0;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 4;
    *local_20 = ATL::CComObject<class_CParameterNameLoader>::vftable;
    (**(code **)(*DAT_100302e0 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_40[1] = local_20;
  }
  local_1c = local_40[1];
  uVar1 = FUN_1001401c();
  return uVar1;
}



// Function: Catch@1001400f at 1001400f

undefined4 Catch_1001400f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10014023;
}



// Function: FUN_1001401c at 1001401c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001401c(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x1001404b;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x30));
    *(DWORD *)(unaff_EBP + -0x34) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x34)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x30) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x34);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10014130 at 10014130

undefined4 __fastcall FUN_10014130(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014150 at 10014150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014150(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eea3;
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



// Function: FUN_100141f0 at 100141f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100141f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_44 [8];
  void *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001eebb;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb0;
  local_24 = operator_new(0x34);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10016090(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_1001429d();
  return uVar1;
}



// Function: Catch@10014290 at 10014290

undefined4 Catch_10014290(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100142a4;
}



// Function: FUN_1001429d at 1001429d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001429d(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10016410(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10014360 at 10014360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10014360(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_40 [5];
  undefined4 *local_2c;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001eef6;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_40;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb4;
  local_20 = (undefined4 *)operator_new(0x24);
  if (local_20 == (undefined4 *)0x0) {
    local_40[1] = (undefined4 *)0x0;
  }
  else {
    local_2c = local_20 + 1;
    *local_2c = 0;
    local_8._0_1_ = 1;
    FUN_10014560(local_20 + 2);
    local_8._0_1_ = 4;
    *local_20 = ATL::CComObject<class_CEnumerationValueLister>::vftable;
    (**(code **)(*DAT_100302e0 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_40[1] = local_20;
  }
  local_1c = local_40[1];
  uVar1 = FUN_1001444c();
  return uVar1;
}



// Function: Catch@1001443f at 1001443f

undefined4 Catch_1001443f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10014453;
}



// Function: FUN_1001444c at 1001444c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001444c(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x1001447b;
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000f4a0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x30));
    *(DWORD *)(unaff_EBP + -0x34) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x34)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x30) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x34);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10014560 at 10014560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __fastcall FUN_10014560(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ef10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100145d0 at 100145d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100145d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_44 [8];
  void *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ef2b;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = pvStack_10;
    return 0x80004003;
  }
  ExceptionList = &pvStack_10;
  *param_3 = 0;
  local_18 = 0x8007000e;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  local_14 = &stack0xffffffb0;
  local_24 = operator_new(0x30);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10016300(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_1001467d();
  return uVar1;
}



// Function: Catch@10014670 at 10014670

undefined4 Catch_10014670(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10014684;
}



// Function: FUN_1001467d at 1001467d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001467d(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10016410(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10014740 at 10014740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014740(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ef50;
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



// Function: FUN_100147c0 at 100147c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100147c0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ef68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  local_8 = 0xffffffff;
  FUN_1000f800((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014850 at 10014850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10014850(void *this,undefined4 *param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_c) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = lstrcmpiW(*(LPCWSTR *)(*this + local_c * 4),(LPCWSTR)*param_1);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return local_c;
}



// Function: FUN_100148f0 at 100148f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100148f0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10014940 at 10014940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10014940(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10014990(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10014990 at 10014990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10014990(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    FUN_10001920(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_100149f0 at 100149f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10014a4a) */
/* WARNING: Removing unreachable block (ram,0x10014a66) */

undefined4 * __thiscall FUN_100149f0(void *this,undefined4 param_1,char param_2)

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



// Function: FUN_10014a90 at 10014a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014a90(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10014af0 at 10014af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10014b2d) */

undefined4 __cdecl FUN_10014af0(uint param_1,uint param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0xcccccccc;
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
    FUN_10001920(local_c);
  }
  return local_8;
}



// Function: FUN_10014b90 at 10014b90

void FUN_10014b90(void)

{
  return;
}



// Function: FUN_10014ba0 at 10014ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10014ba0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  void *local_28;
  void *local_24;
  undefined4 *local_20;
  
  if ((uint)param_1[4] < param_2) {
    std::_Xout_of_range("invalid string position");
  }
  if (param_1[4] - param_2 < param_3) {
    param_3 = param_1[4] - param_2;
  }
  if (-*(int *)((int)this + 0x10) - 1U <= param_3) {
    std::_Xlength_error("string too long");
  }
  if (param_3 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_3;
    bVar1 = FUN_10003dc0(this,uVar2,'\0');
    if (bVar1) {
      if ((uint)param_1[5] < 8) {
        local_20 = param_1;
      }
      else {
        local_20 = (undefined4 *)*param_1;
      }
      local_24 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_24 = *this;
      }
      memcpy((void *)((int)local_24 + *(int *)((int)this + 0x10) * 2),
             (void *)((int)local_20 + param_2 * 2),param_3 << 1);
      *(uint *)((int)this + 0x10) = uVar2;
      local_28 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_28 = *this;
      }
      *(undefined2 *)((int)local_28 + uVar2 * 2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10014d10 at 10014d10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10014d10(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  void *local_3c [4];
  undefined4 *local_2c;
  void *local_24;
  undefined4 uStack_10;
  uint local_c;
  undefined4 *local_8;
  
  ppvVar3 = local_3c;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    local_2c = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_2c = *this;
    }
    if (local_2c <= param_1) {
      local_3c[3] = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_3c[3] = *this;
      }
      if (param_1 < (undefined4 *)((int)local_3c[3] + *(int *)((int)this + 0x10) * 2)) {
        uStack_10 = CONCAT13(1,(undefined3)uStack_10);
        goto LAB_10014d89;
      }
    }
  }
  uStack_10 = uStack_10 & 0xffffff;
LAB_10014d89:
  local_8 = (undefined4 *)this;
  if (uStack_10._3_1_ == '\0') {
    if (-*(int *)((int)this + 0x10) - 1U <= param_2) {
      std::_Xlength_error("string too long");
    }
    if (param_2 != 0) {
      local_c = local_8[4] + param_2;
      bVar1 = FUN_10003dc0(local_8,local_c,'\0');
      if (bVar1) {
        if ((uint)local_8[5] < 8) {
          local_3c[1] = local_8;
        }
        else {
          local_3c[1] = (void *)*local_8;
        }
        local_24 = (void *)((int)local_3c[1] + local_8[4] * 2);
        memcpy(local_24,param_1,param_2 << 1);
        local_8[4] = local_c;
        if ((uint)local_8[5] < 8) {
          local_3c[0] = local_8;
        }
        else {
          local_3c[0] = (void *)*local_8;
        }
        *(undefined2 *)((int)local_3c[0] + local_c * 2) = 0;
      }
    }
  }
  else {
    local_3c[2] = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_3c[2] = *this;
    }
    local_8 = FUN_10014ba0(this,(undefined4 *)this,(int)param_1 - (int)local_3c[2] >> 1,param_2);
  }
  return local_8;
}



// Function: FUN_10014eb0 at 10014eb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10014eb0(void *this,uint param_1,uint param_2,int *param_3,uint param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int **ppiVar4;
  int *local_90 [4];
  int *local_80;
  void *local_7c;
  void *local_78;
  char local_11;
  uint local_10;
  int local_c;
  int *local_8;
  
  ppiVar4 = local_90;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar4 = (int *)0xcccccccc;
    ppiVar4 = ppiVar4 + 1;
  }
  local_8 = (int *)this;
  if (param_3 != (int *)0x0) {
    local_80 = (int *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_80 = *this;
    }
    if ((local_80 <= param_3) &&
       (puVar2 = FUN_10012f70((undefined4 *)this), param_3 < (int *)((int)puVar2 + local_8[4] * 2)))
    {
      local_11 = '\x01';
      goto LAB_10014f1b;
    }
  }
  local_11 = '\0';
LAB_10014f1b:
  if (local_11 == '\0') {
    if ((uint)local_8[4] < param_1) {
      std::_Xout_of_range("invalid string position");
    }
    if (local_8[4] - param_1 < param_2) {
      param_2 = local_8[4] - param_1;
    }
    if (-param_4 - 1 <= local_8[4] - param_2) {
      std::_Xlength_error("string too long");
    }
    local_c = (local_8[4] - param_2) - param_1;
    if (param_4 < param_2) {
      if ((uint)local_8[5] < 8) {
        local_90[2] = local_8;
      }
      else {
        local_90[2] = (int *)*local_8;
      }
      if ((uint)local_8[5] < 8) {
        local_90[1] = local_8;
      }
      else {
        local_90[1] = (int *)*local_8;
      }
      memmove((void *)((int)local_90[1] + param_4 * 2 + param_1 * 2),
              (void *)((int)local_90[2] + param_2 * 2 + param_1 * 2),local_c * 2);
    }
    if ((param_4 != 0) || (param_2 != 0)) {
      local_10 = (local_8[4] + param_4) - param_2;
      bVar1 = FUN_10003dc0(local_8,local_10,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          if ((uint)local_8[5] < 8) {
            local_90[0] = local_8;
          }
          else {
            local_90[0] = (int *)*local_8;
          }
          puVar2 = FUN_10012f70(local_8);
          local_78 = (void *)((int)puVar2 + param_4 * 2 + param_1 * 2);
          memmove(local_78,(void *)((int)local_90[0] + param_2 * 2 + param_1 * 2),local_c << 1);
        }
        puVar2 = FUN_10012f70(local_8);
        local_7c = (void *)((int)puVar2 + param_1 * 2);
        memcpy(local_7c,param_3,param_4 << 1);
        FUN_100156d0(local_8,local_10);
      }
    }
  }
  else {
    if ((uint)local_8[5] < 8) {
      local_90[3] = local_8;
    }
    else {
      local_90[3] = (int *)*local_8;
    }
    local_8 = FUN_10015150(local_8,param_1,param_2,local_8,(int)param_3 - (int)local_90[3] >> 1,
                           param_4);
  }
  return local_8;
}



// Function: FUN_10015150 at 10015150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall
FUN_10015150(void *this,uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int **ppiVar3;
  int *local_74 [4];
  int *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  ppiVar3 = local_74;
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_8 = (int *)this;
  if ((*(uint *)((int)this + 0x10) < param_1) || (local_18 = param_3[4], local_18 < param_4)) {
    std::_Xout_of_range("invalid string position");
  }
  if (local_8[4] - param_1 < param_2) {
    param_2 = local_8[4] - param_1;
  }
  local_1c = param_3[4];
  local_c = local_1c - param_4;
  if (local_c < param_5) {
    param_5 = local_c;
  }
  if (-param_5 - 1 <= local_8[4] - param_2) {
    std::_Xlength_error("string too long");
  }
  local_10 = (local_8[4] - param_2) - param_1;
  local_14 = (local_8[4] + param_5) - param_2;
  if ((uint)local_8[4] < local_14) {
    FUN_10003dc0(local_8,local_14,'\0');
  }
  if (local_8 == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        if (param_4 < param_1 + param_2) {
          if ((uint)local_8[5] < 8) {
            local_74[2] = local_8;
          }
          else {
            local_74[2] = (int *)*local_8;
          }
          if ((uint)local_8[5] < 8) {
            local_74[1] = local_8;
          }
          else {
            local_74[1] = (int *)*local_8;
          }
          memmove((void *)((int)local_74[1] + param_1 * 2),(void *)((int)local_74[2] + param_4 * 2),
                  param_2 << 1);
          if ((uint)local_8[5] < 8) {
            local_74[0] = local_8;
          }
          else {
            local_74[0] = (int *)*local_8;
          }
          puVar1 = FUN_10012f70(local_8);
          local_20 = (void *)((int)puVar1 + param_5 * 2 + param_1 * 2);
          memmove(local_20,(void *)((int)local_74[0] + param_2 * 2 + param_1 * 2),local_10 << 1);
          puVar1 = FUN_10012f70(local_8);
          local_28 = (void *)((int)puVar1 + param_5 * 2 + param_4 * 2);
          puVar1 = FUN_10012f70(local_8);
          local_24 = (void *)((int)puVar1 + param_2 * 2 + param_1 * 2);
          memmove(local_24,local_28,(param_5 - param_2) * 2);
        }
        else {
          if ((uint)local_8[5] < 8) {
            local_5c = local_8;
          }
          else {
            local_5c = (int *)*local_8;
          }
          if ((uint)local_8[5] < 8) {
            local_60 = local_8;
          }
          else {
            local_60 = (int *)*local_8;
          }
          memmove((void *)((int)local_60 + param_5 * 2 + param_1 * 2),
                  (void *)((int)local_5c + param_2 * 2 + param_1 * 2),local_10 << 1);
          if ((uint)local_8[5] < 8) {
            local_64 = local_8;
          }
          else {
            local_64 = (int *)*local_8;
          }
          if ((uint)local_8[5] < 8) {
            local_74[3] = local_8;
          }
          else {
            local_74[3] = (int *)*local_8;
          }
          memmove((void *)((int)local_74[3] + param_1 * 2),
                  (void *)((int)local_64 + ((param_4 + param_5) - param_2) * 2),param_5 << 1);
        }
      }
      else {
        if ((uint)local_8[5] < 8) {
          local_4c = local_8;
        }
        else {
          local_4c = (int *)*local_8;
        }
        if ((uint)local_8[5] < 8) {
          local_50 = local_8;
        }
        else {
          local_50 = (int *)*local_8;
        }
        memmove((void *)((int)local_50 + param_5 * 2 + param_1 * 2),
                (void *)((int)local_4c + param_2 * 2 + param_1 * 2),local_10 << 1);
        if ((uint)local_8[5] < 8) {
          local_54 = local_8;
        }
        else {
          local_54 = (int *)*local_8;
        }
        if ((uint)local_8[5] < 8) {
          local_58 = local_8;
        }
        else {
          local_58 = (int *)*local_8;
        }
        memmove((void *)((int)local_58 + param_1 * 2),(void *)((int)local_54 + param_4 * 2),
                param_5 << 1);
      }
    }
    else {
      if ((uint)local_8[5] < 8) {
        local_3c = local_8;
      }
      else {
        local_3c = (int *)*local_8;
      }
      if ((uint)local_8[5] < 8) {
        local_40 = local_8;
      }
      else {
        local_40 = (int *)*local_8;
      }
      memmove((void *)((int)local_40 + param_1 * 2),(void *)((int)local_3c + param_4 * 2),
              param_5 << 1);
      if ((uint)local_8[5] < 8) {
        local_44 = local_8;
      }
      else {
        local_44 = (int *)*local_8;
      }
      if ((uint)local_8[5] < 8) {
        local_48 = local_8;
      }
      else {
        local_48 = (int *)*local_8;
      }
      memmove((void *)((int)local_48 + param_5 * 2 + param_1 * 2),
              (void *)((int)local_44 + param_2 * 2 + param_1 * 2),local_10 << 1);
    }
  }
  else {
    if ((uint)local_8[5] < 8) {
      local_2c = local_8;
    }
    else {
      local_2c = (int *)*local_8;
    }
    if ((uint)local_8[5] < 8) {
      local_30 = local_8;
    }
    else {
      local_30 = (int *)*local_8;
    }
    memmove((void *)((int)local_30 + param_5 * 2 + param_1 * 2),
            (void *)((int)local_2c + param_2 * 2 + param_1 * 2),local_10 << 1);
    if ((uint)param_3[5] < 8) {
      local_34 = param_3;
    }
    else {
      local_34 = (int *)*param_3;
    }
    if ((uint)local_8[5] < 8) {
      local_38 = local_8;
    }
    else {
      local_38 = (int *)*local_8;
    }
    memcpy((void *)((int)local_38 + param_1 * 2),(void *)((int)local_34 + param_4 * 2),param_5 << 1)
    ;
  }
  FUN_100156d0(local_8,local_14);
  return local_8;
}



// Function: FUN_100156d0 at 100156d0

void __thiscall FUN_100156d0(void *this,int param_1)

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



// Function: FUN_10015730 at 10015730

uint __thiscall FUN_10015730(void *this,ushort *param_1,uint param_2,uint param_3)

{
  int iVar1;
  ushort **ppuVar2;
  ushort *local_30;
  void *local_2c;
  void *local_28;
  uint local_24;
  int local_1c;
  uint local_18;
  ushort *local_14;
  ushort *local_10;
  ushort *local_c;
  
  ppuVar2 = &local_30;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (ushort *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  if (param_3 == 0) {
    if (*(uint *)((int)this + 0x10) <= param_2) {
      param_2 = *(uint *)((int)this + 0x10);
    }
  }
  else {
    if (param_3 <= *(uint *)((int)this + 0x10)) {
      if (param_2 < *(int *)((int)this + 0x10) - param_3) {
        local_24 = param_2;
      }
      else {
        local_24 = *(int *)((int)this + 0x10) - param_3;
      }
      local_28 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_28 = *this;
      }
      local_c = (ushort *)((int)local_28 + local_24 * 2);
      do {
        if (*local_c == *param_1) {
          local_14 = param_1;
          local_10 = local_c;
          for (local_18 = param_3; local_18 != 0; local_18 = local_18 - 1) {
            if (*local_10 != *local_14) {
              local_1c = (uint)(*local_14 <= *local_10) * 2 + -1;
              goto LAB_1001585e;
            }
            local_10 = local_10 + 1;
            local_14 = local_14 + 1;
          }
          local_1c = 0;
LAB_1001585e:
          if (local_1c == 0) {
            local_2c = this;
            if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
              local_2c = *this;
            }
            return (int)local_c - (int)local_2c >> 1;
          }
        }
        local_30 = (ushort *)this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_30 = *this;
        }
        if (local_c == local_30) break;
        local_c = local_c + -1;
      } while( true );
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_100158c0 at 100158c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100158c0(void *this,int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int **ppiVar3;
  int *local_4c [7];
  int *local_30;
  int *local_2c;
  int *local_24;
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  void *local_8;
  
  ppiVar3 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_1c = *(int **)((int)this + 4);
  local_20 = (int *)*local_1c;
  local_c = local_20;
  local_8 = this;
  if (param_2 == local_20) {
    local_24 = *(int **)((int)this + 4);
    local_10 = local_24;
    if (param_3 == local_24) {
      FUN_10017da0(this);
      local_2c = *(int **)((int)local_8 + 4);
      local_30 = (int *)*local_2c;
      *param_1 = (int)local_30;
      piVar2 = local_30;
      goto LAB_100159a0;
    }
  }
  while (param_2 != param_3) {
    local_4c[2] = param_2;
    FUN_100024d0((int *)&param_2);
    local_14 = local_4c[2];
    FUN_100178a0(&local_18,local_4c[2]);
  }
  local_4c[0] = param_2;
  *param_1 = (int)param_2;
  piVar2 = param_1;
LAB_100159a0:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_100159c4);
  return CONCAT44(piVar2,param_1);
}



// Function: FUN_100159e0 at 100159e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100159e0(int param_1)

{
  void *pvVar1;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_14 = 0xcccccccc;
  local_c = 0xcccccccc;
  local_10 = (int)&local_14 + 3;
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = param_1;
  pvVar1 = FUN_100047c0(1);
  *(void **)(local_8 + 4) = pvVar1;
  **(undefined4 **)(local_8 + 4) = *(undefined4 *)(local_8 + 4);
  *(undefined4 *)(*(int *)(local_8 + 4) + 4) = *(undefined4 *)(local_8 + 4);
  *(undefined4 *)(*(int *)(local_8 + 4) + 8) = *(undefined4 *)(local_8 + 4);
  *(undefined1 *)(*(int *)(local_8 + 4) + 0x14) = 1;
  *(undefined1 *)(*(int *)(local_8 + 4) + 0x15) = 1;
  return local_8;
}



// Function: FUN_10015a80 at 10015a80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015a80(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_10015ab0 at 10015ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10015ab0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1,0x10015ade);
  }
  return LVar1;
}



// Function: FUN_10015b40 at 10015b40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_10015b40(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 0x1c));
  if (-1 < (int)local_c) {
    *(undefined1 *)(param_1 + 0x34) = 1;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10015bb0 at 10015bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015bb0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10015be0 at 10015be0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10015be0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1,0x10015c0e);
  }
  return LVar1;
}



// Function: FUN_10015c70 at 10015c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015c70(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000fea0(param_1,(int *)&PTR_DAT_10027254,param_2,param_3);
  return iVar1;
}



// Function: FUN_10015cb0 at 10015cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015cb0(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000fea0((int)(param_1 + 3),(int *)&PTR_DAT_10027254,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_10015d80 at 10015d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10015d80(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x18))(1,0x10015dae);
  }
  return LVar1;
}



// Function: FUN_10015e10 at 10015e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015e10(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000fea0(param_1,(int *)&PTR_DAT_100272d0,param_2,param_3);
  return iVar1;
}



// Function: FUN_10015e50 at 10015e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_10015e50(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (-1 < (int)local_c) {
    *(undefined1 *)(param_1 + 0x30) = 1;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10015ec0 at 10015ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10015ec0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1,0x10015eee);
  }
  return LVar1;
}



// Function: FUN_10015f50 at 10015f50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015f50(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000fea0((int)(param_1 + 3),(int *)&PTR_DAT_100272d0,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_10016020 at 10016020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016020(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10016050 at 10016050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10016050(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000fea0(param_1,(int *)&PTR_DAT_10027324,param_2,param_3);
  return iVar1;
}



// Function: FUN_10016090 at 10016090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016090(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001efa6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CParameterNameLoader>::vftable;
  FUN_10016160((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CParameterNameLoader>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_100302e0 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016160 at 10016160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10016160(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001eff1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 4) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 8),0,0x18);
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016220 at 10016220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016220(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 *)(param_1 + 4),param_2,param_3);
  return;
}



// Function: FUN_10016270 at 10016270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10016270(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1,0x1001629e);
  }
  return LVar1;
}



// Function: FUN_10016300 at 10016300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016300(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001f054;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEnumerationValueLister>::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  local_8 = 2;
  uStack_7 = 0;
  memset((void *)((int)this + 0x14),0,0x18);
  *(undefined1 *)((int)this + 0x2c) = 0;
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CEnumerationValueLister>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  _local_8 = CONCAT31(uStack_7,8);
  (**(code **)(*DAT_100302e0 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016410 at 10016410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_10016410(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 0x14));
  if (-1 < (int)local_c) {
    *(undefined1 *)(param_1 + 0x2c) = 1;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10016480 at 10016480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10016480(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000fea0((int)(param_1 + 3),(int *)&PTR_DAT_10027324,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_10016550 at 10016550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016550(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_100165a0 at 100165a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100165a0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_100165f0 at 100165f0

undefined4 __fastcall FUN_100165f0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10016610 at 10016610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016610(void *this,uint param_1)

{
  FUN_10016660((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016660 at 10016660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016660(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f096;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CSFStringLoader>::vftable;
  param_1[1] = ATL::CComObject<class_CSFStringLoader>::vftable;
  local_8 = 0;
  param_1[3] = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = 5;
  if (*(char *)(param_1 + 10) != '\0') {
    *(undefined1 *)(param_1 + 10) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016760 at 10016760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016760(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f0ce;
  local_10 = ExceptionList;
  local_8 = 4;
  if (*(char *)(param_1 + 0x28) != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)(param_1 + 0x28) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016820 at 10016820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016820(void *this,uint param_1)

{
  FUN_10016870((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016870 at 10016870

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016870(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f137;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CSFStringLoader>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),7);
  if (*(char *)(param_1 + 0xd) != '\0') {
    *(undefined1 *)(param_1 + 0xd) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016970 at 10016970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016970(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f096;
  local_10 = ExceptionList;
  local_8 = 5;
  if (*(char *)(param_1 + 0x28) != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)(param_1 + 0x28) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016a30 at 10016a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016a30(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f158;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CParameterComparer>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CParameterComparer>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 8) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = 0xffffffff;
  FUN_10016af0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016af0 at 10016af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016af0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001f211;
  local_10 = ExceptionList;
  local_8._0_1_ = 8;
  local_8._1_3_ = 0;
  ExceptionList = &local_10;
  Ordinal_6(*(undefined4 *)(param_1 + 0x48));
  local_8._0_1_ = 7;
  Ordinal_6(*(undefined4 *)(param_1 + 0x44),0x10016b44);
  local_8._0_1_ = 6;
  Ordinal_6(*(undefined4 *)(param_1 + 0x40),0x10016b5e);
  local_8._0_1_ = 5;
  Ordinal_6(*(undefined4 *)(param_1 + 0x3c),0x10016b78);
  local_8._0_1_ = 4;
  Ordinal_6(*(undefined4 *)(param_1 + 0x38),0x10016b92);
  local_8._0_1_ = 3;
  Ordinal_6(*(undefined4 *)(param_1 + 0x34),0x10016bac);
  local_8._0_1_ = 2;
  Ordinal_6(*(undefined4 *)(param_1 + 0x30),0x10016bc6);
  uVar2 = 0x10016be0;
  piVar1 = (int *)(param_1 + 0x2c);
  local_8._0_1_ = 1;
  if (*piVar1 != 0) {
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1,0x10016be0);
    uVar2 = 0x10016c18;
  }
  piVar1 = (int *)(param_1 + 0x28);
  local_8 = (uint)local_8._1_3_ << 8;
  if (*piVar1 != 0) {
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1,uVar2);
  }
  local_8 = 0xf;
  if (*(char *)(param_1 + 0x24) != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016cd0 at 10016cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016cd0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001f249;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CParameterComparer>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10016af0((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016da0 at 10016da0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016da0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f158;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10016af0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016e00 at 10016e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10016e00(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f328;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CConditionSetChecker>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CConditionSetChecker>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 8) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = 0xffffffff;
  FUN_10016ec0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016ec0 at 10016ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016ec0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001f2c7;
  local_10 = ExceptionList;
  local_8._1_3_ = 0;
  local_8._0_1_ = 5;
  ExceptionList = &local_10;
  FUN_10017010((void *)(param_1 + 0x30));
  local_8._0_1_ = 2;
  operator_delete(*(void **)(param_1 + 0x34));
  piVar1 = (int *)(param_1 + 0x2c);
  local_8._0_1_ = 1;
  if (*piVar1 != 0) {
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(*(undefined4 *)(param_1 + 0x28));
  local_8 = 10;
  if (*(char *)(param_1 + 0x24) != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017010 at 10017010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10017010(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_40 [6];
  int *local_28;
  undefined4 *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  void *local_8;
  
  puVar2 = local_40;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = *(int **)((int)param_1 + 4);
  local_24 = *(undefined4 **)((int)param_1 + 4);
  local_28 = (int *)*local_24;
  local_18 = local_28;
  local_14 = local_28;
  local_10 = local_20;
  local_c = local_20;
  local_8 = param_1;
  uVar3 = FUN_100158c0(param_1,&local_1c,local_28,local_20);
  return uVar3;
}



// Function: FUN_10017080 at 10017080

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017080(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001f309;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CConditionSetChecker>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10016ec0((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017150 at 10017150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10017150(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f328;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10016ec0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100171c0 at 100171c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100171c0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f348;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CParameterNameLoader>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = 0xffffffff;
  FUN_10017270((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017270 at 10017270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10017270(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f3a1;
  local_10 = ExceptionList;
  piVar1 = (int *)(param_1 + 0x24);
  local_8 = 0;
  ExceptionList = &local_10;
  if (*piVar1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1);
  }
  local_8 = 6;
  if (*(char *)(param_1 + 0x20) != '\0') {
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017360 at 10017360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017360(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001f3d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CParameterNameLoader>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10017270((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017430 at 10017430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10017430(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f348;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10017270(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017490 at 10017490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017490(void *this,uint param_1)

{
  FUN_100174e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100174e0 at 100174e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100174e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f426;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CEnumerationValueLister>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = 5;
  if (*(char *)(param_1 + 8) != '\0') {
    *(undefined1 *)(param_1 + 8) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100175d0 at 100175d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100175d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e81e;
  local_10 = ExceptionList;
  local_8 = 4;
  if (*(char *)(param_1 + 0x20) != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017690 at 10017690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017690(void *this,uint param_1)

{
  FUN_100176e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100176e0 at 100176e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100176e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f487;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CEnumerationValueLister>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_100302e0 + 8))();
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),7);
  if (*(char *)(param_1 + 0xb) != '\0') {
    *(undefined1 *)(param_1 + 0xb) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100177e0 at 100177e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100177e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f426;
  local_10 = ExceptionList;
  local_8 = 5;
  if (*(char *)(param_1 + 0x20) != '\0') {
    ExceptionList = &local_10;
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100178a0 at 100178a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * FUN_100178a0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int **ppiVar2;
  int *local_70 [12];
  int *local_40;
  int *local_3c;
  undefined1 local_35;
  undefined4 *local_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 *local_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  void *local_8;
  
  ppiVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_1c = param_2;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  local_c = param_2;
  FUN_100024d0((int *)&param_2);
  local_18 = local_c;
  if (*(char *)(*local_c + 0x15) == '\0') {
    if (*(char *)(local_c[2] + 0x15) == '\0') {
      local_18 = param_2;
      local_10 = (int *)param_2[2];
    }
    else {
      local_10 = (int *)*local_c;
    }
  }
  else {
    local_10 = (int *)local_c[2];
  }
  if (local_18 == local_c) {
    local_14 = (int *)local_c[1];
    if (*(char *)((int)local_10 + 0x15) == '\0') {
      local_10[1] = (int)local_14;
    }
    if (*(int **)(*(int *)((int)local_8 + 4) + 4) == local_c) {
      *(int **)(*(int *)((int)local_8 + 4) + 4) = local_10;
    }
    else if ((int *)*local_14 == local_c) {
      *local_14 = (int)local_10;
    }
    else {
      local_14[2] = (int)local_10;
    }
    local_20 = *(undefined4 **)((int)local_8 + 4);
    if ((int *)*local_20 == local_c) {
      local_70[1] = local_14;
      if (*(char *)((int)local_10 + 0x15) == '\0') {
        for (local_24 = local_10; *(char *)(*local_24 + 0x15) == '\0'; local_24 = (int *)*local_24)
        {
        }
        local_70[1] = local_24;
      }
      local_28 = *(undefined4 **)((int)local_8 + 4);
      *local_28 = local_70[1];
    }
    if (*(int **)(*(int *)((int)local_8 + 4) + 8) == local_c) {
      local_70[0] = local_14;
      if (*(char *)((int)local_10 + 0x15) == '\0') {
        local_2c = local_10;
        while (*(char *)(local_2c[2] + 0x15) == '\0') {
          local_2c = (int *)local_2c[2];
        }
        local_70[0] = local_2c;
      }
      *(int **)(*(int *)((int)local_8 + 4) + 8) = local_70[0];
    }
  }
  else {
    *(int **)(*local_c + 4) = local_18;
    *local_18 = *local_c;
    if (local_18 == (int *)local_c[2]) {
      local_14 = local_18;
    }
    else {
      local_14 = (int *)local_18[1];
      if (*(char *)((int)local_10 + 0x15) == '\0') {
        local_10[1] = (int)local_14;
      }
      *local_14 = (int)local_10;
      local_18[2] = local_c[2];
      *(int **)(local_c[2] + 4) = local_18;
    }
    if (*(int **)(*(int *)((int)local_8 + 4) + 4) == local_c) {
      *(int **)(*(int *)((int)local_8 + 4) + 4) = local_18;
    }
    else {
      local_30 = (undefined4 *)local_c[1];
      if ((int *)*local_30 == local_c) {
        local_34 = (undefined4 *)local_c[1];
        *local_34 = local_18;
      }
      else {
        *(int **)(local_c[1] + 8) = local_18;
      }
    }
    local_18[1] = local_c[1];
    local_40 = local_c + 5;
    local_3c = local_18 + 5;
    local_35 = (undefined1)*local_3c;
    *(char *)local_3c = (char)*local_40;
    *(undefined1 *)local_40 = local_35;
  }
  if ((char)local_c[5] != '\x01') {
LAB_10017d3d:
    FUN_10003110((int)local_8 + 0xd,local_c + 3);
    operator_delete(local_c);
    if (*(int *)((int)local_8 + 8) != 0) {
      *(int *)((int)local_8 + 8) = *(int *)((int)local_8 + 8) + -1;
    }
    *param_1 = param_2;
    return param_1;
  }
LAB_10017b4d:
  if ((local_10 == *(int **)(*(int *)((int)local_8 + 4) + 4)) || ((char)local_10[5] != '\x01'))
  goto LAB_10017d36;
  if (local_10 == (int *)*local_14) {
    local_18 = (int *)local_14[2];
    if ((char)local_18[5] == '\0') {
      *(undefined1 *)(local_18 + 5) = 1;
      *(undefined1 *)(local_14 + 5) = 0;
      FUN_10003440(local_8,(int)local_14);
      local_18 = (int *)local_14[2];
    }
    if (*(char *)((int)local_18 + 0x15) == '\0') {
      if ((*(char *)(*local_18 + 0x14) != '\x01') || (*(char *)(local_18[2] + 0x14) != '\x01')) {
        if (*(char *)(local_18[2] + 0x14) == '\x01') {
          *(undefined1 *)(*local_18 + 0x14) = 1;
          *(undefined1 *)(local_18 + 5) = 0;
          FUN_10003500(local_8,local_18);
          local_18 = (int *)local_14[2];
        }
        *(char *)(local_18 + 5) = (char)local_14[5];
        *(undefined1 *)(local_14 + 5) = 1;
        *(undefined1 *)(local_18[2] + 0x14) = 1;
        FUN_10003440(local_8,(int)local_14);
LAB_10017d36:
        *(undefined1 *)(local_10 + 5) = 1;
        goto LAB_10017d3d;
      }
      *(undefined1 *)(local_18 + 5) = 0;
    }
    local_10 = local_14;
  }
  else {
    local_18 = (int *)*local_14;
    if ((char)local_18[5] == '\0') {
      *(undefined1 *)(local_18 + 5) = 1;
      *(undefined1 *)(local_14 + 5) = 0;
      FUN_10003500(local_8,local_14);
      local_18 = (int *)*local_14;
    }
    if (*(char *)((int)local_18 + 0x15) == '\0') {
      if ((*(char *)(local_18[2] + 0x14) != '\x01') || (*(char *)(*local_18 + 0x14) != '\x01')) {
        if (*(char *)(*local_18 + 0x14) == '\x01') {
          *(undefined1 *)(local_18[2] + 0x14) = 1;
          *(undefined1 *)(local_18 + 5) = 0;
          FUN_10003440(local_8,(int)local_18);
          local_18 = (int *)*local_14;
        }
        *(char *)(local_18 + 5) = (char)local_14[5];
        *(undefined1 *)(local_14 + 5) = 1;
        *(undefined1 *)(*local_18 + 0x14) = 1;
        FUN_10003500(local_8,local_14);
        goto LAB_10017d36;
      }
      *(undefined1 *)(local_18 + 5) = 0;
      local_10 = local_14;
    }
    else {
      local_10 = local_14;
    }
  }
  local_14 = (int *)local_10[1];
  goto LAB_10017b4d;
}



// Function: FUN_10017da0 at 10017da0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10017da0(void *param_1)

{
  FUN_10018290(param_1,*(undefined4 **)(*(int *)((int)param_1 + 4) + 4));
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 4) = *(undefined4 *)((int)param_1 + 4);
  **(undefined4 **)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 8) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10017e20 at 10017e20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10017e20(void)

{
  return;
}



// Function: FUN_10017e70 at 10017e70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017e70(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f4c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10017ef0((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CSFStringLoader>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CSFStringLoader>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017ef0 at 10017ef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10017ef0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f50e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 0x10),0,0x18);
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017fa0 at 10017fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10017fa0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10017ff0 at 10017ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10017ff0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10018040 at 10018040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10018040(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_10018090 at 10018090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10018090(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [11];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f158;
  local_10 = ExceptionList;
  puVar2 = local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_14 = (undefined4 *)this;
  FUN_10013460((int)this);
  *local_14 = ATL::CComContainedObject<class_CParameterComparer>::vftable;
  local_14[1] = ATL::CComContainedObject<class_CParameterComparer>::vftable;
  local_14[2] = param_1;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10018110 at 10018110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10018110(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10018160 at 10018160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10018160(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_100181b0 at 100181b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100181b0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f328;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100139f0((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CConditionSetChecker>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CConditionSetChecker>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10018240 at 10018240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10018240(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10018290 at 10018290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10018290(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  
  local_c = param_1;
  while (*(char *)((int)local_c + 0x15) == '\0') {
    FUN_10018290(this,(undefined4 *)local_c[2]);
    puVar1 = (undefined4 *)*local_c;
    FUN_10003110((int)this + 0xd,local_c + 3);
    operator_delete(local_c);
    local_c = puVar1;
  }
  return;
}



// Function: FUN_10018310 at 10018310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_10018310(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint local_2c [2];
  undefined4 *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  ushort *local_14;
  ushort *local_10;
  undefined4 *local_8;
  
  puVar2 = local_2c;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)this;
  if (*(uint *)((int)this + 0x10) < param_1) {
    std::_Xout_of_range("invalid string position");
  }
  if (local_8[4] - param_1 < param_2) {
    param_2 = local_8[4] - param_1;
  }
  if (param_2 < param_4) {
    local_20 = param_2;
  }
  else {
    local_20 = param_4;
  }
  if ((uint)local_8[5] < 8) {
    local_24 = local_8;
  }
  else {
    local_24 = (undefined4 *)*local_8;
  }
  local_18 = local_20;
  local_14 = param_3;
  local_10 = (ushort *)((int)local_24 + param_1 * 2);
  do {
    if (local_18 == 0) {
      local_1c = 0;
LAB_10018404:
      if (local_1c == 0) {
        if (param_2 < param_4) {
          local_2c[0] = 0xffffffff;
        }
        else {
          local_2c[0] = (uint)(param_2 != param_4);
        }
        local_2c[1] = local_2c[0];
      }
      else {
        local_2c[1] = local_1c;
      }
      return local_2c[1];
    }
    if (*local_10 != *local_14) {
      local_1c = (uint)(*local_14 <= *local_10) * 2 - 1;
      goto LAB_10018404;
    }
    local_10 = local_10 + 1;
    local_14 = local_14 + 1;
    local_18 = local_18 - 1;
  } while( true );
}



// Function: FUN_10018460 at 10018460

void FUN_10018460(int param_1)

{
  FUN_10018110(param_1 + -4);
  return;
}



// Function: FUN_10018470 at 10018470

void FUN_10018470(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10015c70(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10018480 at 10018480

void FUN_10018480(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10015e10(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10018490 at 10018490

void FUN_10018490(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10018240(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100184a0 at 100184a0

void FUN_100184a0(int param_1)

{
  FUN_10015be0((int *)(param_1 + -4));
  return;
}



// Function: FUN_100184b0 at 100184b0

void FUN_100184b0(int param_1)

{
  FUN_10018160(param_1 + -4);
  return;
}



// Function: FUN_100184c0 at 100184c0

void FUN_100184c0(int param_1)

{
  FUN_10015d80((int *)(param_1 + -4));
  return;
}



// Function: FUN_100184d0 at 100184d0

void FUN_100184d0(int param_1)

{
  FUN_10015bb0(param_1 + -4);
  return;
}



// Function: FUN_100184e0 at 100184e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100184e0(int param_1)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f556;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset((void *)(param_1 + 0x10),0,0x18);
  local_8 = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_100302e0 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar1 = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar1 < 0) {
    DAT_100302d4 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100185c0 at 100185c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100185c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f576;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_1000cea0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: AddRef at 10018620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual long __thiscall ATL::IDocument::AddRef(void)
   
   Library: Visual Studio 2012 Debug */

long __thiscall ATL::IDocument::AddRef(IDocument *this)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(this + 8));
  return LVar1;
}



// Function: AddRef at 10018660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual long __thiscall ATL::IDocument::AddRef(void)
   
   Library: Visual Studio 2012 Debug */

long __thiscall ATL::IDocument::AddRef(IDocument *this)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(this + 8));
  return LVar1;
}



// Function: FUN_100186a0 at 100186a0

undefined4 __fastcall FUN_100186a0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100186c0 at 100186c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_100186c0(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_10027e00,(LPUNKNOWN)0x0,1,(IID *)&DAT_100274b8,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10018770 at 10018770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10018770(void)

{
  return;
}



// Function: FUN_100187c0 at 100187c0

undefined4 FUN_100187c0(void)

{
  return 0x80004005;
}



// Function: FUN_100187d0 at 100187d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100187d0(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10018940(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function: FUN_10018810 at 10018810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10018810(int *param_1,ushort param_2,int param_3,int *param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10008050(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function: FUN_10018850 at 10018850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10018850(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f5c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 2;
  FUN_1000cea0((int)this);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100188e0 at 100188e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100188e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f5ee;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1000cea0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018940 at 10018940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10018c5c) */
/* WARNING: Removing unreachable block (ram,0x1001899c) */

undefined8 FUN_10018940(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  errno_t eVar3;
  DWORD DVar4;
  int iVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  wchar_t *pwVar6;
  wchar_t *extraout_EDX_03;
  wchar_t *extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 uVar7;
  DWORD *pDVar8;
  undefined8 uVar9;
  DWORD local_b84 [2];
  int *local_b7c;
  undefined4 *local_b78;
  DWORD local_b74;
  int local_b70;
  wchar_t *local_b6c;
  int local_b64 [4];
  undefined4 local_b54;
  DWORD local_b4c;
  int local_b48;
  wchar_t *local_b44;
  int local_b3c [4];
  undefined4 local_b2c;
  int *local_b24;
  undefined4 *local_b20;
  int local_b1c;
  int *local_b18;
  undefined4 *local_b14;
  int *local_b10;
  undefined4 *local_b0c;
  int *local_b08;
  int local_b04;
  LPCWSTR local_b00;
  int local_afc;
  LPCWSTR local_af8;
  int local_af0 [4];
  undefined4 local_ae0;
  int local_ad8;
  DWORD local_ad0;
  DWORD local_acc;
  DWORD local_ac8;
  DWORD local_ac4;
  DWORD local_ac0;
  DWORD local_abc;
  DWORD local_ab8;
  LPCWSTR local_ab0;
  wchar_t *local_aac;
  int local_aa8;
  WCHAR local_aa0;
  undefined2 local_a9e [525];
  DWORD local_684;
  WCHAR local_67c [522];
  WCHAR *local_268;
  DWORD local_264;
  HMODULE local_260;
  WCHAR local_258 [264];
  undefined4 *local_48 [4];
  undefined4 local_38;
  DWORD local_30;
  undefined **local_28;
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f6ab;
  local_10 = ExceptionList;
  pDVar8 = local_b84;
  for (iVar5 = 0x2dd; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pDVar8 = 0xcccccccc;
    pDVar8 = pDVar8 + 1;
  }
  local_28 = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  FUN_1000cc60(local_24);
  local_8 = 1;
  local_30 = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_b04 = param_4[1];
      local_b00 = (LPCWSTR)*param_4;
      if ((local_b00 != (LPCWSTR)0x0) && (local_b04 != 0)) {
        local_ae0 = 3;
        local_af0[0] = 0;
        local_8._0_1_ = 4;
        local_af8 = local_b00;
        uVar9 = FUN_10008ae0(local_24,local_b04,local_b00,local_b04);
        local_afc = (int)uVar9;
        local_ad8 = (-(uint)(local_afc != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_1000fa30(local_af0);
      }
    }
  }
  local_30 = (**(code **)(*param_1 + 0x14))(&local_28);
  local_b84[0] = 0x10018ade;
  if ((int)local_30 < 0) {
    local_28 = ATL::CRegObject::vftable;
    local_8 = 5;
    local_ab8 = local_30;
    FUN_10009730((int)&local_28);
    local_b08 = local_24;
    local_8 = 6;
    FUN_10008ee0(local_b08);
    local_8 = 0xffffffff;
    FUN_1000fc30(local_b08);
    DVar4 = local_ab8;
    uVar7 = extraout_EDX;
  }
  else {
    local_38 = 3;
    local_48[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_260 = DAT_100308e8;
    local_264 = GetModuleFileNameW(DAT_100308e8,local_258,0x104);
    if (local_264 == 0) {
      local_abc = FUN_10008960();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b0c = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 8;
      FUN_10009730((int)&local_28);
      local_b10 = local_24;
      local_8 = 9;
      FUN_10008ee0(local_b10);
      local_8 = 0xffffffff;
      FUN_1000fc30(local_b10);
      DVar4 = local_abc;
      uVar7 = extraout_EDX_00;
    }
    else if (local_264 == 0x104) {
      local_b84[1] = 0x8007007a;
      local_ac0 = 0x8007007a;
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b14 = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 10;
      FUN_10009730((int)&local_28);
      local_b18 = local_24;
      local_8 = 0xb;
      FUN_10008ee0(local_b18);
      local_8 = 0xffffffff;
      FUN_1000fc30(local_b18);
      DVar4 = local_ac0;
      uVar7 = extraout_EDX_01;
    }
    else {
      local_268 = local_258;
      FUN_100089c0(local_67c,0x208,local_268);
      if ((local_260 == (HMODULE)0x0) ||
         (pHVar2 = GetModuleHandleW((LPCWSTR)0x0), local_260 == pHVar2)) {
        local_aa0 = L'\"';
        local_b1c = lstrlenW(local_67c);
        eVar3 = memcpy_s(local_a9e,0x416,local_67c,local_b1c * 2 + 2);
        if (eVar3 != 0) {
          local_ac4 = 0x80004005;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
            local_b20 = local_48[0];
            local_48[0] = (undefined4 *)*local_48[0];
            free(puVar1);
          }
          local_28 = ATL::CRegObject::vftable;
          local_8 = 0xc;
          FUN_10009730((int)&local_28);
          local_b24 = local_24;
          local_8 = 0xd;
          FUN_10008ee0(local_b24);
          local_8 = 0xffffffff;
          FUN_1000fc30(local_b24);
          DVar4 = local_ac4;
          uVar7 = extraout_EDX_02;
          goto LAB_10019185;
        }
        local_aa8 = lstrlenW(&local_aa0);
        local_a9e[local_aa8 + -1] = 0x22;
        local_a9e[local_aa8] = 0;
        pwVar6 = L"Module";
        if (&stack0x00000000 == (undefined1 *)0xaa0) {
          local_684 = 0x80070057;
        }
        else {
          local_b2c = 3;
          local_b3c[0] = 0;
          local_8._0_1_ = 0xe;
          local_b44 = L"Module";
          uVar9 = FUN_10008ae0(local_24,L"Module",L"Module",(int)&local_aa0);
          local_b48 = (int)uVar9;
          local_b4c = (-(uint)(local_b48 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_1000fa30(local_b3c);
          local_684 = local_b4c;
          pwVar6 = extraout_EDX_03;
        }
      }
      else {
        pwVar6 = L"Module";
        if (&stack0x00000000 == (undefined1 *)0x67c) {
          local_684 = 0x80070057;
        }
        else {
          local_b54 = 3;
          local_b64[0] = 0;
          local_8._0_1_ = 0xf;
          local_b6c = L"Module";
          uVar9 = FUN_10008ae0(local_24,L"Module",L"Module",(int)local_67c);
          local_b70 = (int)uVar9;
          local_b74 = (-(uint)(local_b70 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_1000fa30(local_b64);
          local_684 = local_b74;
          pwVar6 = extraout_EDX_04;
        }
      }
      if ((int)local_684 < 0) {
        local_ac8 = local_684;
        local_8 = CONCAT31(local_8._1_3_,1);
        while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
          local_b78 = local_48[0];
          local_48[0] = (undefined4 *)*local_48[0];
          free(puVar1);
        }
        local_28 = ATL::CRegObject::vftable;
        local_8 = 0x10;
        FUN_10009730((int)&local_28);
        local_b7c = local_24;
        local_8 = 0x11;
        FUN_10008ee0(local_b7c);
        local_8 = 0xffffffff;
        FUN_1000fc30(local_b7c);
        DVar4 = local_ac8;
        uVar7 = extraout_EDX_05;
      }
      else {
        uVar9 = FUN_10009130(&local_28,pwVar6,(int)&local_28,0x10026a34,(int)local_67c);
        local_684 = (DWORD)uVar9;
        if ((int)local_684 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_acc = local_684;
          FUN_1000fa30((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10009020(&local_28);
          DVar4 = local_acc;
          uVar7 = extraout_EDX_06;
        }
        else {
          local_aac = L"REGISTRY";
          local_ab0 = param_2;
          if (param_3 == 0) {
            uVar9 = FUN_100193f0(local_268,&local_28,&local_28,local_268,param_2,L"REGISTRY");
            local_b84[0] = (DWORD)uVar9;
          }
          else {
            uVar9 = FUN_100192b0(&local_28,param_2,&local_28,local_268,param_2,L"REGISTRY");
            local_b84[0] = (DWORD)uVar9;
          }
          local_30 = local_b84[0];
          local_ad0 = local_b84[0];
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_1000fa30((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10009020(&local_28);
          DVar4 = local_ad0;
          uVar7 = extraout_EDX_07;
        }
      }
    }
  }
LAB_10019185:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100191b8);
  ExceptionList = local_10;
  return CONCAT44(uVar7,DVar4);
}



// Function: FUN_100192b0 at 100192b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_100192b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,
            LPCWSTR param_5,LPCWSTR param_6)

{
  LPCWSTR pWVar1;
  LPCWSTR pWVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar4;
  LPCWSTR *ppWVar5;
  undefined8 uVar6;
  LPCWSTR local_44 [5];
  LPCWSTR local_30;
  LPCWSTR local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  ppWVar5 = local_44;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppWVar5 = (LPCWSTR)0xcccccccc;
    ppWVar5 = ppWVar5 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  if ((param_5 == (LPCWSTR)0x0) || (param_6 == (LPCWSTR)0x0)) {
    local_44[3] = (LPCWSTR)0x80070057;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    while (pWVar1 = local_28, uVar6 = CONCAT44(param_2,local_44[2]), pWVar2 = local_44[3],
          local_28 != (LPCWSTR)0x0) {
      local_44[1] = local_28;
      local_28 = *(LPCWSTR *)local_28;
      free(pWVar1);
      param_2 = extraout_EDX;
    }
  }
  else {
    local_30 = param_5;
    local_44[4] = param_6;
    ExceptionList = &local_10;
    uVar6 = FUN_10009340(param_4,param_5,param_6);
    local_8 = 0xffffffff;
    while (pWVar1 = local_28, local_44[2] = (LPCWSTR)uVar6, pWVar2 = local_44[2],
          local_28 != (LPCWSTR)0x0) {
      local_44[0] = local_28;
      local_28 = *(LPCWSTR *)local_28;
      free(pWVar1);
      uVar6 = CONCAT44(extraout_EDX_00,local_44[2]);
    }
  }
  uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
  local_44[2] = (LPCWSTR)uVar6;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_100193c4);
  ExceptionList = local_10;
  return CONCAT44(uVar4,pWVar2);
}



// Function: FUN_100193f0 at 100193f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_100193f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,
            LPCWSTR param_5,LPCWSTR param_6)

{
  LPCWSTR pWVar1;
  LPCWSTR pWVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar4;
  LPCWSTR *ppWVar5;
  undefined8 uVar6;
  LPCWSTR local_44 [5];
  LPCWSTR local_30;
  LPCWSTR local_28;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  ppWVar5 = local_44;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppWVar5 = (LPCWSTR)0xcccccccc;
    ppWVar5 = ppWVar5 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  if ((param_5 == (LPCWSTR)0x0) || (param_6 == (LPCWSTR)0x0)) {
    local_44[3] = (LPCWSTR)0x80070057;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    while (pWVar1 = local_28, uVar6 = CONCAT44(param_2,local_44[2]), pWVar2 = local_44[3],
          local_28 != (LPCWSTR)0x0) {
      local_44[1] = local_28;
      local_28 = *(LPCWSTR *)local_28;
      free(pWVar1);
      param_2 = extraout_EDX;
    }
  }
  else {
    local_30 = param_5;
    local_44[4] = param_6;
    ExceptionList = &local_10;
    uVar6 = FUN_10009340(param_4,param_5,param_6);
    local_8 = 0xffffffff;
    while (pWVar1 = local_28, local_44[2] = (LPCWSTR)uVar6, pWVar2 = local_44[2],
          local_28 != (LPCWSTR)0x0) {
      local_44[0] = local_28;
      local_28 = *(LPCWSTR *)local_28;
      free(pWVar1);
      uVar6 = CONCAT44(extraout_EDX_00,local_44[2]);
    }
  }
  uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
  local_44[2] = (LPCWSTR)uVar6;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10019504);
  ExceptionList = local_10;
  return CONCAT44(uVar4,pWVar2);
}



// Function: FUN_10019530 at 10019530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10019530(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_10026604);
  return;
}



// Function: FUN_10019580 at 10019580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10019615) */
/* WARNING: Removing unreachable block (ram,0x1001975d) */
/* WARNING: Removing unreachable block (ram,0x100197f3) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10019580(undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  int *local_fc [4];
  undefined4 local_ec;
  int *local_e8;
  int *local_e4;
  int *local_dc;
  undefined4 local_d8;
  int local_d4;
  int local_d0;
  uint local_cc;
  int *local_c8;
  int *local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int *local_b4;
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined1 *local_8c;
  undefined1 *local_88;
  int local_84 [2];
  int local_7c [2];
  uint local_74 [2];
  int local_6c [3];
  int local_60 [5];
  int *local_4c;
  int *local_40;
  int *local_34;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f811;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_fc;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)0xcccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffef8;
  FUN_10002600(local_28);
  local_34 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  uVar1 = (**(code **)(*param_3 + 0x3c))();
  FUN_10002680(local_28,uVar1);
  local_40 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  local_84[0] = Ordinal_2();
  if (local_84[0] == 0) {
    FUN_10001920(0x8007000e);
  }
  local_b4 = local_84;
  local_8._0_1_ = 6;
  local_b8 = local_84[0];
  uVar1 = (**(code **)(*param_2 + 0x90))();
  FUN_10002680(local_28,uVar1);
  local_8._0_1_ = 5;
  Ordinal_6();
  local_4c = (int *)0x0;
  local_8._0_1_ = 8;
  while( true ) {
    local_e4 = local_40;
    uVar1 = (**(code **)(*local_40 + 0x24))();
    local_bc = FUN_10002680(local_28,uVar1);
    local_c0 = *(int *)(local_bc + 0xc);
    if (local_c0 != 0) break;
    FUN_1001a120(local_60);
    local_8._0_1_ = 9;
    FUN_1001a220(local_60,local_4c,local_4c);
    local_6c[0] = 0;
    local_7c[0] = 0;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    puVar7 = local_74;
    local_88 = &stack0xfffffec0;
    local_c4 = (int *)&stack0xfffffec0;
    iVar2 = Ordinal_2(L"stringID");
    iVar6 = 0x1001977f;
    *local_c4 = iVar2;
    if (*local_c4 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_e8 = local_c4;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    uVar4 = FUN_1001b780(iVar6,puVar7);
    local_ec = (undefined4)uVar4;
    FUN_10002680(local_28,local_ec);
    piVar8 = local_6c;
    local_c8 = (int *)&stack0xfffffec0;
    local_8c = &stack0xfffffec0;
    iVar2 = Ordinal_2(L"dsName");
    iVar6 = 0x10019815;
    *local_c8 = iVar2;
    if (*local_c8 == 0) {
      FUN_10001920(0x8007000e);
    }
    local_fc[3] = local_c8;
    local_8._0_1_ = 0xb;
    uVar4 = FUN_1001b1b0(iVar6,piVar8);
    local_fc[2] = (int *)uVar4;
    FUN_10002680(local_28,local_fc[2]);
    local_cc = local_74[0];
    Ordinal_6();
    local_7c[0] = 0;
    FUN_10019b80(local_cc,local_7c);
    local_d0 = local_7c[0];
    local_ac = local_ac & 0xffff0000;
    FUN_10019de0(&local_ac,local_7c[0]);
    local_fc[1] = (int *)&local_ac;
    local_8._0_1_ = 0xe;
    local_9c = local_ac;
    local_fc[0] = local_34;
    local_d4 = local_6c[0];
    uVar1 = (**(code **)(*local_34 + 0x28))
                      (local_34,local_6c[0],local_ac,local_a8,local_a4,local_a0);
    uVar5 = 0x1001995e;
    FUN_10002680(local_28,uVar1);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    local_d8 = Ordinal_9(&local_ac,uVar5);
    piVar8 = local_4c;
    uVar1 = 0x10019981;
    local_dc = local_4c;
    if (local_4c != (int *)0x0) {
      local_4c = (int *)0x0;
      (**(code **)(*piVar8 + 8))(piVar8,0x10019981);
      uVar1 = 0x100199bd;
    }
    local_8._0_1_ = 10;
    Ordinal_6(local_7c[0],uVar1);
    local_8._0_1_ = 9;
    Ordinal_6(local_6c[0],0x100199d4);
    local_8._0_1_ = 8;
    FUN_1001a190(local_60);
  }
  local_8._0_1_ = 5;
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 8))();
  }
  local_8._0_1_ = 3;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))();
  }
  uVar4 = FUN_10019a7a();
  return uVar4;
}



// Function: Catch@10019a6d at 10019a6d

undefined4 Catch_10019a6d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10019a81;
}



// Function: FUN_10019a7a at 10019a7a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10019a7a(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  undefined4 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0xdc) = *(undefined4 *)(unaff_EBP + -0x18);
  if (*(int *)(unaff_EBP + -0xdc) == 1) {
    FUN_10002680((void *)(unaff_EBP + -0x24),0);
  }
  *(undefined4 *)(unaff_EBP + -0xac) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xac);
  uVar2 = extraout_EDX;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10019aec);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar2,uVar1);
}



// Function: FUN_10019b80 at 10019b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10019b80(uint param_1,int *param_2)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = FUN_10019bf0(param_1);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_2 = iVar2;
  }
  return *param_2 != 0;
}



// Function: FUN_10019bf0 at 10019bf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

ATLSTRINGRESOURCEIMAGE * __cdecl FUN_10019bf0(uint param_1)

{
  int local_10;
  HINSTANCE__ *local_c;
  ATLSTRINGRESOURCEIMAGE *local_8;
  
  local_8 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  local_c = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100308e4,0);
  local_10 = 1;
  while ((local_c != (HINSTANCE__ *)0x0 && (local_8 == (ATLSTRINGRESOURCEIMAGE *)0x0))) {
    local_8 = ATL::AtlGetStringResourceImage(local_c,param_1);
    local_c = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100308e4,local_10);
    local_10 = local_10 + 1;
  }
  return local_8;
}



// Function: AtlGetStringResourceImage at 10019c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::AtlGetStringResourceImage(struct
   HINSTANCE__ *,unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

ATLSTRINGRESOURCEIMAGE * __cdecl ATL::AtlGetStringResourceImage(HINSTANCE__ *param_1,uint param_2)

{
  HRSRC pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 == (HRSRC)0x0) {
    pAVar2 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  else {
    pAVar2 = _AtlGetStringResourceImage(param_1,pHVar1,param_2);
  }
  return pAVar2;
}



// Function: _AtlGetStringResourceImage at 10019cf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::_AtlGetStringResourceImage(struct
   HINSTANCE__ *,struct HRSRC__ *,unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

ATLSTRINGRESOURCEIMAGE * __cdecl
ATL::_AtlGetStringResourceImage(HINSTANCE__ *param_1,HRSRC__ *param_2,uint param_3)

{
  HGLOBAL hResData;
  DWORD DVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  uint local_18;
  ATLSTRINGRESOURCEIMAGE *local_8;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    local_8 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  else {
    local_8 = (ATLSTRINGRESOURCEIMAGE *)LockResource(hResData);
    if (local_8 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
      local_8 = (ATLSTRINGRESOURCEIMAGE *)0x0;
    }
    else {
      DVar1 = SizeofResource(param_1,param_2);
      pAVar2 = local_8 + DVar1;
      local_18 = param_3 & 0xf;
      for (; (local_18 != 0 && (local_8 < pAVar2));
          local_8 = local_8 + (uint)*(ushort *)local_8 * 2 + 2) {
        local_18 = local_18 - 1;
      }
      if (local_8 < pAVar2) {
        if (*(ushort *)local_8 == 0) {
          local_8 = (ATLSTRINGRESOURCEIMAGE *)0x0;
        }
      }
      else {
        local_8 = (ATLSTRINGRESOURCEIMAGE *)0x0;
      }
    }
  }
  return local_8;
}



// Function: FUN_10019de0 at 10019de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined2 * __thiscall FUN_10019de0(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  uVar2 = 0x10019e0b;
  if (iVar1 < 0) {
    FUN_10001920(iVar1);
  }
  *(undefined2 *)this = 8;
  uVar2 = Ordinal_2(param_1,uVar2);
  *(undefined4 *)((int)this + 8) = uVar2;
  if ((*(int *)((int)this + 8) == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    FUN_10001920(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_10019e90 at 10019e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10019ee0) */
/* WARNING: Removing unreachable block (ram,0x10019efe) */

undefined8 __cdecl FUN_10019e90(int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined2 uVar2;
  undefined2 uStack_46;
  undefined4 uVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001f8c1;
  local_10 = ExceptionList;
  local_20 = 0xcccccccc;
  local_18 = 0xcccccccc;
  local_14 = 0xcccccccc;
  local_24 = 0xcccc0003;
  local_1c = param_2;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1001a0d0(8,(int)&local_24,0,0x409);
  if (local_1c == 0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(local_1c);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      FUN_10001920(0x8007000e);
    }
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(&local_24);
  uVar2 = SUB42(param_1,0);
  uStack_46 = (undefined2)((uint)param_1 >> 0x10);
  uVar3 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10019fd0);
  ExceptionList = local_10;
  return CONCAT44(uVar3,CONCAT22(uStack_46,uVar2));
}



// Function: FUN_10019ff0 at 10019ff0

int __cdecl FUN_10019ff0(char param_1)

{
  return -(uint)(param_1 != '\0');
}



// Function: FUN_1001a000 at 1001a000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_1001a000(int param_1)

{
  undefined4 extraout_EDX;
  undefined2 uVar1;
  undefined2 uStack_42;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f8d8;
  local_10 = ExceptionList;
  local_20 = 0xcccccccc;
  local_1c = 0xcccccccc;
  local_18 = 0xcccccccc;
  local_14 = 0xcccccccc;
  local_24 = 0xcccc0000;
  ExceptionList = &local_10;
  FUN_10019de0(&local_24,param_1);
  local_8 = 0;
  FUN_1001a0d0(3,(int)&local_24,0,0x409);
  uVar2 = local_1c;
  local_8 = 0xffffffff;
  Ordinal_9(&local_24);
  uVar1 = (undefined2)uVar2;
  uStack_42 = (undefined2)((uint)uVar2 >> 0x10);
  uVar2 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001a0b8);
  ExceptionList = local_10;
  return CONCAT44(uVar2,CONCAT22(uStack_42,uVar1));
}



// Function: FUN_1001a0d0 at 1001a0d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1001a0d0(undefined2 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 local_8;
  
  local_8 = param_3;
  if (param_3 == 0) {
    local_8 = param_2;
  }
  Ordinal_147(local_8,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_1001a120 at 1001a120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1001a120(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  return param_1;
}



// Function: FUN_1001a190 at 1001a190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a190(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fbc0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  if (param_1[1] != 0) {
    ExceptionList = &local_10;
    FUN_1001a380(param_1);
  }
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001a220 at 1001a220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1001a220(int *param_1,int *param_2,int *param_3)

{
  int *extraout_EDX;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001fbe8;
  local_10 = ExceptionList;
  if (param_3 == (int *)0x0) {
    ExceptionList = &local_10;
    param_1[1] = 0;
    local_18 = 0x80004003;
  }
  else if (*param_1 == 0) {
    ExceptionList = &local_10;
    if (param_3 != (int *)0x0) {
      ExceptionList = &local_10;
      (**(code **)(*param_3 + 4))(param_3);
    }
    local_8 = 1;
    if ((param_1 != (int *)0x0) && (*param_1 = (int)param_3, param_3 != (int *)0x0)) {
      (**(code **)(*param_3 + 4))(param_3);
    }
    param_1[1] = 1;
    local_18 = 0;
    local_8 = 0xffffffff;
    param_2 = param_1;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
      param_2 = extraout_EDX;
    }
  }
  else {
    local_18 = 0x80004003;
    param_2 = (int *)0x0;
    ExceptionList = &local_10;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001a360);
  ExceptionList = local_10;
  return CONCAT44(param_2,local_18);
}



// Function: FUN_1001a380 at 1001a380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1001a380(int *param_1)

{
  int *piVar1;
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0x80004003;
  }
  else {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      *param_1 = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    param_1[1] = 0;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_1001a410 at 1001a410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001a49a) */
/* WARNING: Removing unreachable block (ram,0x1001a4c2) */

void FUN_1001a410(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int local_a8;
  int *local_a4;
  undefined ***local_a0;
  undefined ***local_9c;
  int *local_98;
  undefined4 local_94;
  int *local_90;
  int local_84;
  undefined4 *local_80;
  int *local_7c;
  undefined1 *local_74;
  undefined **local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [36];
  undefined1 local_34 [20];
  int local_20;
  undefined1 local_19;
  int *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001fc48;
  pvStack_10 = ExceptionList;
  piVar2 = &local_a8;
  for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  local_19 = 0;
  local_20 = 0;
  local_8 = 1;
  uStack_7 = 0;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff4c;
  Ordinal_8();
  local_8 = 2;
  if (*local_18 != 0) {
    puVar4 = local_34;
    local_74 = &stack0xffffff3c;
    local_90 = (int *)&stack0xffffff3c;
    puVar5 = puVar4;
    iVar1 = FUN_10001a90(&param_1);
    *local_90 = iVar1;
    if ((param_1 != 0) && (*local_90 == 0)) {
      FUN_10001920(0x8007000e);
    }
    local_a4 = local_90;
    local_8 = 2;
    uVar3 = FUN_1001a9f0(local_18,puVar4,puVar5);
    local_a8 = (int)uVar3;
    local_19 = -1 < local_a8;
    _local_8 = CONCAT31(uStack_7,1);
    local_20 = local_a8;
    local_94 = Ordinal_9();
    FUN_1001a671();
    return;
  }
  local_98 = &local_84;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0x80004003;
  local_6c = CGenericExceptionEx::vftable;
  local_80 = &local_5c;
  local_5c = 0;
  local_8 = 5;
  local_7c = local_98;
  FUN_10002050(&local_5c,&local_84);
  local_8 = 2;
  Ordinal_6();
  local_a0 = &local_6c;
  _local_8 = CONCAT31(uStack_7,6);
  local_9c = local_a0;
  FUN_1001a8c0(local_58,(int)local_a0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_58,(ThrowInfo *)&DAT_1002d0a0);
}



// Function: Catch@1001a646 at 1001a646

undefined4 Catch_1001a646(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 0xc);
  *(undefined1 *)(unaff_EBP + -0x15) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001a678;
}



// Function: Catch@1001a660 at 1001a660

undefined4 Catch_1001a660(void)

{
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -0x15) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001a678;
}



// Function: FUN_1001a671 at 1001a671

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 FUN_1001a671(void)

{
  undefined1 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0x71) = *(undefined1 *)(unaff_EBP + -0x15);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined1 *)(unaff_EBP + -0x71);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001a6cc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}



// Function: FUN_1001a700 at 1001a700

void __fastcall FUN_1001a700(undefined4 *param_1)

{
  *param_1 = CGenericException::vftable;
  return;
}



// Function: FUN_1001a720 at 1001a720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1001a720(void *this,uint param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001a760 at 1001a760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a760(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fc73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CGenericExceptionEx::vftable;
  local_8 = 0;
  Ordinal_6(param_1[4]);
  *param_1 = CGenericException::vftable;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001a7e0 at 1001a7e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1001a7e0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fc73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CGenericExceptionEx::vftable;
  local_8 = 0;
  Ordinal_6(*(undefined4 *)((int)this + 0x10));
  local_8 = 0xffffffff;
  *(undefined ***)this = CGenericException::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001a870 at 1001a870

undefined4 * __thiscall FUN_1001a870(void *this,int param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return (undefined4 *)this;
}



// Function: FUN_1001a8c0 at 1001a8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1001a8c0(void *this,int param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fc73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  local_8 = 0;
  *(undefined ***)this = CGenericExceptionEx::vftable;
  iVar1 = FUN_10001a90((int *)(param_1 + 0x10));
  *(int *)((int)this + 0x10) = iVar1;
  if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)((int)this + 0x10) == 0)) {
    FUN_10001920(0x8007000e);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: GdiplusStartupInput at 1001a9b0

/* Library Function - Single Match
    public: __thiscall Gdiplus::GdiplusStartupInput::GdiplusStartupInput(void (__stdcall*)(enum
   Gdiplus::DebugEventLevel,char *),int,int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

GdiplusStartupInput * __thiscall
Gdiplus::GdiplusStartupInput::GdiplusStartupInput
          (GdiplusStartupInput *this,_func_void_DebugEventLevel_char_ptr *param_1,int param_2,
          int param_3)

{
  *(undefined ***)this = CGenericException::vftable;
  *(int *)(this + 4) = param_3;
  *(int *)(this + 8) = param_2;
  *(_func_void_DebugEventLevel_char_ptr **)(this + 0xc) = param_1;
  return this;
}



// Function: FUN_1001a9f0 at 1001a9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001ad92) */
/* WARNING: Removing unreachable block (ram,0x1001adc0) */
/* WARNING: Removing unreachable block (ram,0x1001af84) */
/* WARNING: Removing unreachable block (ram,0x1001afb2) */
/* WARNING: Removing unreachable block (ram,0x1001ac1b) */
/* WARNING: Removing unreachable block (ram,0x1001ac49) */
/* WARNING: Removing unreachable block (ram,0x1001aa86) */
/* WARNING: Removing unreachable block (ram,0x1001aab4) */

undefined8 __thiscall FUN_1001a9f0(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined ****ppppuVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined ***local_168 [2];
  int *local_160;
  int *local_15c;
  int *local_158;
  undefined ***local_154;
  int *local_150;
  undefined ***local_14c;
  int *local_148;
  int *local_144;
  undefined ***local_140;
  int *local_13c;
  int local_138;
  undefined4 *local_134;
  int *local_130;
  undefined4 local_12c;
  undefined ***local_128;
  int local_124;
  undefined4 *local_120;
  int *local_11c;
  undefined ***local_118;
  int local_114;
  undefined4 *local_110;
  int *local_10c;
  undefined ***local_104;
  int local_100;
  undefined4 *local_fc;
  int *local_f8;
  undefined **local_ec [4];
  undefined4 local_dc;
  undefined1 local_d8 [24];
  undefined **local_c0 [4];
  undefined4 local_b0;
  undefined **local_ac [4];
  undefined1 local_9c [8];
  undefined **local_94 [4];
  undefined4 local_84;
  undefined **local_80 [4];
  undefined1 local_70 [8];
  undefined **local_68 [4];
  undefined4 local_58;
  undefined **local_54 [4];
  undefined1 local_44 [20];
  int *local_30 [3];
  int *local_24 [2];
  _func_void_DebugEventLevel_char_ptr *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001fdcb;
  pvStack_10 = ExceptionList;
  ppppuVar2 = local_168;
  for (iVar1 = 0x55; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppppuVar2 = (undefined ***)0xcccccccc;
    ppppuVar2 = ppppuVar2 + 1;
  }
  local_1c = (_func_void_DebugEventLevel_char_ptr *)0x0;
  local_24[0] = (int *)0x0;
  local_30[0] = (int *)0x0;
  uStack_7 = 0;
  local_8 = 5;
                    /* WARNING: Load size is inaccurate */
  local_18 = this;
  if (*this == 0) {
    local_13c = &local_100;
    uStack_7 = 0;
    local_1c = (_func_void_DebugEventLevel_char_ptr *)0x0;
    local_24[0] = (int *)0x0;
    local_30[0] = (int *)0x0;
    local_100 = 0;
    local_8 = 6;
    ExceptionList = &pvStack_10;
    local_f8 = local_13c;
    local_14 = &stack0xfffffe8c;
    Gdiplus::GdiplusStartupInput::GdiplusStartupInput
              ((GdiplusStartupInput *)local_68,(_func_void_DebugEventLevel_char_ptr *)0x80004003,0,0
              );
    local_68[0] = CGenericExceptionEx::vftable;
    local_fc = &local_58;
    local_58 = 0;
    local_8 = 8;
    FUN_10002050(&local_58,&local_100);
    local_8 = 5;
    Ordinal_6(local_100);
    local_140 = local_68;
    local_8 = 9;
    local_104 = local_140;
    FUN_1001a870(local_54,(int)local_140);
    local_8 = 10;
    local_54[0] = CGenericExceptionEx::vftable;
    FUN_100019d0(local_44,(int *)(local_104 + 4));
    _local_8 = CONCAT31(uStack_7,9);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1002d0a0);
  }
                    /* WARNING: Load size is inaccurate */
  local_144 = *this;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffe8c;
  local_1c = (_func_void_DebugEventLevel_char_ptr *)
             (**(code **)(*local_144 + 0x44))(local_144,local_24);
  if ((int)local_1c < 0) {
    local_148 = &local_114;
    local_114 = 0;
    local_8 = 0xe;
    local_10c = local_148;
    Gdiplus::GdiplusStartupInput::GdiplusStartupInput((GdiplusStartupInput *)local_94,local_1c,0,0);
    local_94[0] = CGenericExceptionEx::vftable;
    local_110 = &local_84;
    local_84 = 0;
    local_8 = 0x10;
    FUN_10002050(&local_84,&local_114);
    local_8 = 5;
    Ordinal_6(local_114);
    local_14c = local_94;
    local_8 = 0x11;
    local_118 = local_14c;
    FUN_1001a870(local_80,(int)local_14c);
    local_8 = 0x12;
    local_80[0] = CGenericExceptionEx::vftable;
    FUN_100019d0(local_70,(int *)(local_118 + 4));
    _local_8 = CONCAT31(uStack_7,0x11);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_80,(ThrowInfo *)&DAT_1002d0a0);
  }
  if (local_24[0] != (int *)0x0) {
    local_158 = local_24[0];
    local_12c = param_1;
    local_1c = (_func_void_DebugEventLevel_char_ptr *)
               (**(code **)(*local_24[0] + 0x1c))(local_24[0],param_1,local_30,0x1001abf0);
    if (local_1c == (_func_void_DebugEventLevel_char_ptr *)0x0) {
      local_15c = local_30[0];
      local_1c = (_func_void_DebugEventLevel_char_ptr *)
                 (**(code **)(*local_30[0] + 0x20))(local_30[0],param_2,0x1001af22);
      uVar4 = 0x1001af59;
      if ((int)local_1c < 0) {
        local_160 = &local_138;
        local_138 = 0;
        local_8 = 0x1e;
        local_130 = local_160;
        Gdiplus::GdiplusStartupInput::GdiplusStartupInput
                  ((GdiplusStartupInput *)local_ec,local_1c,0,0);
        local_ec[0] = CGenericExceptionEx::vftable;
        local_134 = &local_dc;
        local_dc = 0;
        local_8 = 0x20;
        FUN_10002050(&local_dc,&local_138);
        local_8 = 5;
        Ordinal_6(local_138,uVar4);
        local_168[0] = local_ec;
        _local_8 = CONCAT31(uStack_7,0x21);
        local_168[1] = local_168[0];
        FUN_1001a8c0(local_d8,(int)local_168[0]);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_d8,(ThrowInfo *)&DAT_1002d0a0);
      }
    }
    else {
      local_1c = (_func_void_DebugEventLevel_char_ptr *)0x80004005;
    }
    local_8 = 3;
    FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)local_30);
    _local_8 = CONCAT31(uStack_7,1);
    FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)local_24);
    uVar3 = FUN_1001b100();
    return uVar3;
  }
  local_150 = &local_124;
  local_124 = 0;
  local_8 = 0x16;
  local_11c = local_150;
  Gdiplus::GdiplusStartupInput::GdiplusStartupInput
            ((GdiplusStartupInput *)local_c0,(_func_void_DebugEventLevel_char_ptr *)0x80004003,0,0);
  local_c0[0] = CGenericExceptionEx::vftable;
  local_120 = &local_b0;
  local_b0 = 0;
  local_8 = 0x18;
  FUN_10002050(&local_b0,&local_124);
  local_8 = 5;
  Ordinal_6(local_124);
  local_154 = local_c0;
  local_8 = 0x19;
  local_128 = local_154;
  FUN_1001a870(local_ac,(int)local_154);
  local_8 = 0x1a;
  local_ac[0] = CGenericExceptionEx::vftable;
  FUN_100019d0(local_9c,(int *)(local_128 + 4));
  _local_8 = CONCAT31(uStack_7,0x19);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_ac,(ThrowInfo *)&DAT_1002d0a0);
}



// Function: Catch@1001b0ae at 1001b0ae

undefined4 Catch_1001b0ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc);
  **(undefined2 **)(unaff_EBP + 0xc) = 10;
  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001b107;
}



// Function: Catch@1001b0d8 at 1001b0d8

undefined4 Catch_1001b0d8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  **(undefined2 **)(unaff_EBP + 0xc) = 10;
  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001b107;
}



// Function: FUN_1001b100 at 1001b100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001b100(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xf0);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001b164);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_1001b1b0 at 1001b1b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001b479) */
/* WARNING: Removing unreachable block (ram,0x1001b4a7) */
/* WARNING: Removing unreachable block (ram,0x1001b24a) */
/* WARNING: Removing unreachable block (ram,0x1001b278) */

undefined8 FUN_1001b1b0(int param_1,int *param_2)

{
  int iVar1;
  undefined ****ppppuVar2;
  undefined8 uVar3;
  short *psVar4;
  short *psVar5;
  undefined ***local_f0;
  int *local_ec;
  int local_e8;
  int *local_e4;
  undefined ***local_e0;
  undefined ***local_dc;
  int *local_d8;
  undefined4 local_d4;
  undefined ***local_d0;
  int local_cc;
  undefined4 *local_c8;
  int *local_c4;
  int local_c0;
  int *local_bc;
  int local_b8;
  undefined4 *local_b4;
  int *local_b0;
  undefined **local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined **local_90 [4];
  undefined1 local_80 [4];
  undefined1 *local_7c;
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60 [36];
  short local_3c [4];
  int local_34;
  int local_24 [2];
  int local_1c;
  int *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001fe88;
  pvStack_10 = ExceptionList;
  ppppuVar2 = &local_f0;
  for (iVar1 = 0x37; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppppuVar2 = (undefined ***)0xcccccccc;
    ppppuVar2 = ppppuVar2 + 1;
  }
  local_1c = 0;
  local_24[0] = 0;
  uStack_7 = 0;
  local_8 = 2;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff04;
  Ordinal_8();
  _local_8 = CONCAT31(uStack_7,3);
  if (*local_18 == 0) {
    local_d8 = &local_b8;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0x80004003;
    local_74 = CGenericExceptionEx::vftable;
    local_b4 = &local_64;
    local_64 = 0;
    local_8 = 6;
    local_b0 = local_d8;
    FUN_10002050(&local_64,&local_b8);
    local_8 = 3;
    Ordinal_6();
    local_e0 = &local_74;
    _local_8 = CONCAT31(uStack_7,7);
    local_dc = local_e0;
    FUN_1001a8c0(local_60,(int)local_e0);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_60,(ThrowInfo *)&DAT_1002d0a0);
  }
  psVar4 = local_3c;
  local_7c = &stack0xfffffef4;
  local_bc = (int *)&stack0xfffffef4;
  psVar5 = psVar4;
  iVar1 = FUN_10001a90(&param_1);
  *local_bc = iVar1;
  if ((param_1 != 0) && (*local_bc == 0)) {
    FUN_10001920(0x8007000e);
  }
  local_e4 = local_bc;
  uStack_7 = (undefined3)((uint)_local_8 >> 8);
  local_8 = 3;
  uVar3 = FUN_1001a9f0(local_18,psVar4,psVar5);
  local_e8 = (int)uVar3;
  if (local_e8 == 0) {
    local_1c = local_e8;
    if (local_3c[0] != 8) {
      local_ec = &local_cc;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0x80004005;
      local_a4 = CGenericExceptionEx::vftable;
      local_c8 = &local_94;
      local_94 = 0;
      local_8 = 0xd;
      local_c4 = local_ec;
      FUN_10002050(&local_94,&local_cc);
      local_8 = 3;
      Ordinal_6();
      local_f0 = &local_a4;
      local_8 = 0xe;
      local_d0 = local_f0;
      FUN_1001a870(local_90,(int)local_f0);
      local_8 = 0xf;
      local_90[0] = CGenericExceptionEx::vftable;
      FUN_100019d0(local_80,(int *)(local_d0 + 4));
      _local_8 = CONCAT31(uStack_7,0xe);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_90,(ThrowInfo *)&DAT_1002d0a0);
    }
    if (((*param_2 != 0) && (*param_2 != -0x33333334)) && (*param_2 != -0x33333334)) {
      Ordinal_6();
    }
    FUN_1001b6f0(local_24,local_34);
    iVar1 = local_24[0];
    local_c0 = local_24[0];
    local_24[0] = 0;
    *param_2 = iVar1;
  }
  else {
    local_1c = -0x7fffbffb;
  }
  _local_8 = CONCAT31(uStack_7,2);
  local_d4 = Ordinal_9();
  uVar3 = FUN_1001b632();
  return uVar3;
}



// Function: Catch@1001b608 at 1001b608

undefined4 Catch_1001b608(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1001b639;
}



// Function: Catch@1001b61e at 1001b61e

undefined4 Catch_1001b61e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1001b639;
}



// Function: FUN_1001b632 at 1001b632

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001b632(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8),0x1001b659);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xa8);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001b6ac);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_1001b6f0 at 1001b6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_1001b6f0(void *this,int param_1)

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
      uVar1 = Ordinal_2(param_1,0x1001b71e);
      *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
      if (*this == 0) {
        FUN_10001920(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_1001b780 at 1001b780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001b9f8) */
/* WARNING: Removing unreachable block (ram,0x1001ba26) */
/* WARNING: Removing unreachable block (ram,0x1001bb79) */
/* WARNING: Removing unreachable block (ram,0x1001bba7) */
/* WARNING: Removing unreachable block (ram,0x1001b80f) */
/* WARNING: Removing unreachable block (ram,0x1001b83d) */

undefined8 FUN_1001b780(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined ****ppppuVar2;
  undefined8 uVar3;
  short *psVar4;
  short *psVar5;
  undefined ***local_12c [2];
  int *local_124;
  undefined ***local_120;
  int *local_11c;
  int local_118;
  int *local_114;
  undefined ***local_110;
  undefined ***local_10c;
  int *local_108;
  undefined4 local_104;
  int local_100;
  undefined4 *local_fc;
  int *local_f8;
  undefined ***local_f4;
  int local_f0;
  undefined4 *local_ec;
  int *local_e8;
  int *local_e4;
  int local_d8;
  undefined4 *local_d4;
  int *local_d0;
  undefined **local_c4 [4];
  undefined4 local_b4;
  undefined1 local_b0 [24];
  undefined **local_98 [4];
  undefined4 local_88;
  undefined **local_84 [4];
  undefined1 local_74 [4];
  undefined1 *local_70;
  undefined **local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54 [36];
  short local_30 [4];
  undefined4 local_28;
  _func_void_DebugEventLevel_char_ptr *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001ff69;
  pvStack_10 = ExceptionList;
  ppppuVar2 = local_12c;
  for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppppuVar2 = (undefined ***)0xcccccccc;
    ppppuVar2 = ppppuVar2 + 1;
  }
  local_1c = (_func_void_DebugEventLevel_char_ptr *)0x0;
  local_8 = 1;
  uStack_7 = 0;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffec8;
  Ordinal_8();
  _local_8 = CONCAT31(uStack_7,2);
  if (*local_18 == 0) {
    local_108 = &local_d8;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0x80004003;
    local_68 = CGenericExceptionEx::vftable;
    local_d4 = &local_58;
    local_58 = 0;
    local_8 = 5;
    local_d0 = local_108;
    FUN_10002050(&local_58,&local_d8);
    local_8 = 2;
    Ordinal_6();
    local_110 = &local_68;
    _local_8 = CONCAT31(uStack_7,6);
    local_10c = local_110;
    FUN_1001a8c0(local_54,(int)local_110);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1002d0a0);
  }
  psVar4 = local_30;
  local_70 = &stack0xfffffeb8;
  local_e4 = (int *)&stack0xfffffeb8;
  psVar5 = psVar4;
  iVar1 = FUN_10001a90(&param_1);
  *local_e4 = iVar1;
  if ((param_1 != 0) && (*local_e4 == 0)) {
    FUN_10001920(0x8007000e);
  }
  local_114 = local_e4;
  uStack_7 = (undefined3)((uint)_local_8 >> 8);
  local_8 = 2;
  uVar3 = FUN_1001a9f0(local_18,psVar4,psVar5);
  local_118 = (int)uVar3;
  if (local_118 == 0) {
    local_1c = (_func_void_DebugEventLevel_char_ptr *)local_118;
    if (local_30[0] != 8) {
      local_124 = &local_100;
      local_8 = 0x12;
      local_f8 = local_124;
      Gdiplus::GdiplusStartupInput::GdiplusStartupInput
                ((GdiplusStartupInput *)local_c4,(_func_void_DebugEventLevel_char_ptr *)0x80004005,0
                 ,0);
      local_c4[0] = CGenericExceptionEx::vftable;
      local_fc = &local_b4;
      local_b4 = 0;
      local_8 = 0x14;
      FUN_10002050(&local_b4,&local_100);
      local_8 = 2;
      Ordinal_6();
      local_12c[0] = local_c4;
      _local_8 = CONCAT31(uStack_7,0x15);
      local_12c[1] = local_12c[0];
      FUN_1001a8c0(local_b0,(int)local_12c[0]);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_b0,(ThrowInfo *)&DAT_1002d0a0);
    }
    local_1c = (_func_void_DebugEventLevel_char_ptr *)FUN_1001a0d0(3,(int)local_30,0,0x409);
    if ((int)local_1c < 0) {
      local_11c = &local_f0;
      local_8 = 10;
      local_e8 = local_11c;
      Gdiplus::GdiplusStartupInput::GdiplusStartupInput
                ((GdiplusStartupInput *)local_98,local_1c,0,0);
      local_98[0] = CGenericExceptionEx::vftable;
      local_ec = &local_88;
      local_88 = 0;
      local_8 = 0xc;
      FUN_10002050(&local_88,&local_f0);
      local_8 = 2;
      Ordinal_6();
      local_120 = local_98;
      local_8 = 0xd;
      local_f4 = local_120;
      FUN_1001a870(local_84,(int)local_120);
      local_8 = 0xe;
      local_84[0] = CGenericExceptionEx::vftable;
      FUN_100019d0(local_74,(int *)(local_f4 + 4));
      _local_8 = CONCAT31(uStack_7,0xd);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_84,(ThrowInfo *)&DAT_1002d0a0);
    }
    *param_2 = local_28;
  }
  else {
    local_1c = (_func_void_DebugEventLevel_char_ptr *)0x80004005;
  }
  _local_8 = CONCAT31(uStack_7,1);
  local_104 = Ordinal_9();
  uVar3 = FUN_1001bccb();
  return uVar3;
}



// Function: Catch@1001bca1 at 1001bca1

undefined4 Catch_1001bca1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001bcd2;
}



// Function: Catch@1001bcb7 at 1001bcb7

undefined4 Catch_1001bcb7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001bcd2;
}



// Function: FUN_1001bccb at 1001bccb

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001bccb(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -200) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(unaff_EBP + -200);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001bd2c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_1001bd64 at 1001bd64

int __fastcall FUN_1001bd64(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1001bd89 at 1001bd89

void __fastcall FUN_1001bd89(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 1001bda1

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
LAB_1001bdef:
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
        goto LAB_1001bdef;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_1001bdfe at 1001bdfe

undefined4 * __fastcall FUN_1001bdfe(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_1001bd64((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10027e30;
  DVar1 = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)DVar1 < 0) {
    DAT_100302d4 = 1;
  }
  return param_1;
}



// Function: FUN_1001be3e at 1001be3e

void __fastcall FUN_1001be3e(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (*param_1 != 0) {
    piVar3 = (int *)param_1[2];
    if (piVar3 < (int *)param_1[3]) {
      do {
        iVar1 = *piVar3;
        if (iVar1 != 0) {
          piVar2 = *(int **)(iVar1 + 0x10);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 < (int *)param_1[3]);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1001be82 at 1001be82

int __fastcall FUN_1001be82(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1001be9b at 1001be9b

undefined4 * __fastcall FUN_1001be9b(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_1001be82((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1002d9e8;
  param_1[3] = &DAT_1002d9e8;
  DVar1 = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)DVar1 < 0) {
    DAT_100302d4 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 1001bedc

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleInit(struct ATL::_ATL_WIN_MODULE70 *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long ATL::AtlWinModuleInit(_ATL_WIN_MODULE70 *param_1)

{
  DWORD DVar1;
  
  if ((param_1 == (_ATL_WIN_MODULE70 *)0x0) || (*(int *)param_1 != 0x2c)) {
    DVar1 = 0x80070057;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    DVar1 = FUN_1000f4a0((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return DVar1;
}



// Function: RemoveAll at 1001bf04

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CSimpleArray<unsigned short,class
   ATL::CSimpleArrayEqualHelper<unsigned short> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<unsigned long,class
   ATL::CSimpleArrayEqualHelper<unsigned long> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlControlSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlControlSink *> >::RemoveAll(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __fastcall RemoveAll(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1001bf23 at 1001bf23

int __fastcall FUN_1001bf23(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 1001bf48

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_1001bf55:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_1001bf55;
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x24)) {
        do {
          if ((iVar3 < 0) || (*(int *)(param_1 + 0x24) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pcVar1 = (code *)swi(3);
            lVar2 = (*pcVar1)();
            return lVar2;
          }
          UnregisterClassA((LPCSTR)(uint)*(ushort *)(*(int *)(param_1 + 0x20) + iVar3 * 2),param_2);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x24));
      }
      RemoveAll((undefined4 *)(param_1 + 0x20));
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      *(undefined4 *)param_1 = 0;
    }
    lVar2 = 0;
  }
  return lVar2;
}



// Function: FUN_1001bfbe at 1001bfbe

_ATL_WIN_MODULE70 * __fastcall FUN_1001bfbe(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_1001bf23((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_100302d4 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_1001bfe6 at 1001bfe6

void FUN_1001bfe6(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __RTC_CheckEsp at 1001bffe

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __RTC_CheckEsp
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined8 __fastcall __RTC_CheckEsp(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  bool in_ZF;
  void *unaff_retaddr;
  
  if (in_ZF) {
    return CONCAT44(param_2,in_EAX);
  }
  _RTC_Failure(unaff_retaddr,0);
  return CONCAT44(param_2,in_EAX);
}



// Function: _RTC_CheckStackVars at 1001c021

/* Library Function - Single Match
    @_RTC_CheckStackVars@8
   
   Library: Visual Studio 2010 Release
   __fastcall _RTC_CheckStackVars,8 */

void __fastcall _RTC_CheckStackVars(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  void *unaff_retaddr;
  int local_8;
  
  iVar2 = 0;
  local_8 = 0;
  if (0 < *param_2) {
    do {
      iVar1 = *(int *)(param_2[1] + iVar2);
      if ((*(int *)(iVar1 + -4 + param_1) != -0x33333334) ||
         (*(int *)(*(int *)(param_2[1] + 4 + iVar2) + iVar1 + param_1) != -0x33333334)) {
        _RTC_StackFailure(unaff_retaddr,*(char **)(param_2[1] + 8 + iVar2));
      }
      local_8 = local_8 + 1;
      iVar2 = iVar2 + 0xc;
    } while (local_8 < *param_2);
  }
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1001c0bc

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



// Function: __onexit at 1001c120

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
  
  local_8 = &DAT_1002d900;
  uStack_c = 0x1001c12c;
  local_20[0] = DecodePointer(DAT_10030ccc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10030ccc);
    local_24 = DecodePointer(DAT_10030cc8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10030ccc = EncodePointer(local_20[0]);
    DAT_10030cc8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001c1b8();
  }
  return p_Var1;
}



// Function: FUN_1001c1b8 at 1001c1b8

void FUN_1001c1b8(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001c1c1

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 1001c1f0

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



// Function: __ArrayUnwind at 1001c22e

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



// Function: `eh_vector_destructor_iterator' at 1001c28c

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
  FUN_1001c2d7();
  return;
}



// Function: FUN_1001c2d7 at 1001c2d7

void FUN_1001c2d7(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe_16 at 1001c2f0

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 1001c306

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



// Function: __CRT_INIT@12 at 1001c3a2

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
    if (DAT_10030974 < 1) {
      return 0;
    }
    DAT_10030974 = DAT_10030974 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030cc0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030cbc == 2) {
      param_2 = (int *)DecodePointer(DAT_10030ccc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10030cc8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10030ccc);
            piVar8 = (int *)DecodePointer(DAT_10030cc8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10030cc8 = (PVOID)encoded_null();
        DAT_10030ccc = DAT_10030cc8;
      }
      DAT_10030cbc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10030cc0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030cc0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030cbc == 0) {
      DAT_10030cbc = 1;
      iVar5 = initterm_e(&DAT_100263d0,&DAT_100263d8);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100261e8,&DAT_100263cc);
      DAT_10030cbc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10030cc0,0);
    }
    if ((DAT_10030cc4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10030cc4), BVar2 != 0)) {
      (*DAT_10030cc4)(param_1,2,param_3);
    }
    DAT_10030974 = DAT_10030974 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001c5ac

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001c64c) */
/* WARNING: Removing unreachable block (ram,0x1001c5f9) */
/* WARNING: Removing unreachable block (ram,0x1001c679) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1002fcc0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10030974 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10007f00(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10007f00(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1001c6b7();
  return local_20;
}



// Function: FUN_1001c6b7 at 1001c6b7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c6b7(void)

{
  _DAT_1002fcc0 = 0xffffffff;
  return;
}



// Function: entry at 1001c6c2

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: DebuggerProbe at 1001c6e5

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerProbe(unsigned long)
   
   Library: Visual Studio 2010 Release */

int __cdecl DebuggerProbe(ulong param_1)

{
  ULONG_PTR local_38 [2];
  byte *local_30;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x1001c6f1;
  local_1d[0] = 0;
  local_38[0] = 0x1001;
  local_30 = local_1d;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,local_38);
  return (uint)local_1d[0];
}



// Function: DebuggerRuntime at 1001c735

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerRuntime(unsigned long,int,void *,wchar_t const *)
   
   Library: Visual Studio 2010 Release */

int __cdecl DebuggerRuntime(ulong param_1,int param_2,void *param_3,wchar_t *param_4)

{
  ULONG_PTR local_38 [2];
  ulong local_30;
  int local_2c;
  byte *local_28;
  void *local_24;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x1001c741;
  local_1d[0] = 0;
  local_38[0] = 0x1002;
  local_30 = param_1;
  local_2c = param_2;
  local_28 = local_1d;
  local_24 = param_3;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,local_38);
  return (uint)local_1d[0];
}



// Function: failwithmessage at 1001c797

/* Library Function - Single Match
    void __cdecl failwithmessage(void *,int,int,char const *)
   
   Library: Visual Studio 2010 Release */

void __cdecl failwithmessage(void *param_1,int param_2,int param_3,char *param_4)

{
  code *pcVar1;
  bool bVar2;
  uint cchWideChar;
  int iVar3;
  BOOL BVar4;
  char *pcVar5;
  LPCSTR in_EDX;
  wchar_t *unaff_EDI;
  wchar_t *pwVar6;
  code *local_e3c;
  uint local_e38;
  code *local_e34;
  WCHAR local_e30 [512];
  undefined1 local_a30 [780];
  CHAR local_724 [780];
  WCHAR local_418 [260];
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_1002fcc8 ^ (uint)&stack0xfffffffc;
  local_e3c = (code *)0x0;
  local_e34 = (code *)FUN_1001caed();
  if (local_e34 == (code *)0x0) {
    local_e3c = (code *)FUN_1001cae7();
  }
  cchWideChar = MultiByteToWideChar(0xfde9,0,in_EDX,-1,(LPWSTR)0x0,0);
  if (cchWideChar < 0x200) {
    iVar3 = MultiByteToWideChar(0xfde9,0,in_EDX,-1,local_e30,cchWideChar);
    pwVar6 = local_e30;
    if (iVar3 == 0) goto LAB_1001c827;
  }
  else {
LAB_1001c827:
    pwVar6 = L"Runtime Check Error.\n\r Unable to display RTC Message.";
  }
  iVar3 = DebuggerProbe((ulong)unaff_EDI);
  if (iVar3 == 0) {
    bVar2 = true;
  }
  else {
    iVar3 = DebuggerRuntime(*(ulong *)(&DAT_10028108 + param_2 * 4),local_e38,pwVar6,unaff_EDI);
    if (iVar3 != 0) goto LAB_1001c98e;
    bVar2 = false;
  }
  if ((local_e3c != (code *)0x0) || (local_e34 != (code *)0x0)) {
    if (bVar2) {
      BVar4 = IsDebuggerPresent();
      if (BVar4 != 0) goto LAB_1001c98d;
    }
    FUN_1001cf4e(local_e38 - 5,local_418,0x104,&local_e38,local_210,0x104);
    if (local_e34 == (code *)0x0) {
      local_e34 = (code *)0x100281c0;
      iVar3 = WideCharToMultiByte(0xfde9,0,local_418,-1,local_a30,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        local_e34 = (code *)local_a30;
      }
      iVar3 = WideCharToMultiByte(0xfde9,0,local_210,-1,local_724,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      pcVar5 = local_724;
      if (iVar3 == 0) {
        pcVar5 = "Unknown Module Name";
      }
      iVar3 = (*local_e3c)(param_1,local_e34,local_e38,pcVar5,"Run-Time Check Failure #%d - %s",
                           param_2,in_EDX);
    }
    else {
      iVar3 = (*local_e34)(param_1,local_418,local_e38,local_210,L"Run-Time Check Failure #%d - %s",
                           param_2,pwVar6);
    }
    if (iVar3 != 1) {
LAB_1001c98e:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_1001c98d:
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: _RTC_Failure at 1001c99d

/* Library Function - Single Match
    void __cdecl _RTC_Failure(void *,int)
   
   Library: Visual Studio 2010 Release */

void __cdecl _RTC_Failure(void *param_1,int param_2)

{
  void *pvVar1;
  int unaff_EBP;
  char *unaff_retaddr;
  
  if ((uint)param_2 < 5) {
    pvVar1 = *(void **)(&DAT_1002fca0 + param_2 * 4);
  }
  else {
    pvVar1 = (void *)0x1;
    param_2 = 5;
  }
  if (pvVar1 != (void *)0xffffffff) {
    failwithmessage(pvVar1,param_2,unaff_EBP,unaff_retaddr);
  }
  return;
}



// Function: _RTC_StackFailure at 1001c9d8

/* Library Function - Single Match
    void __cdecl _RTC_StackFailure(void *,char const *)
   
   Library: Visual Studio 2010 Release */

void __cdecl _RTC_StackFailure(void *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int unaff_EBX;
  char *unaff_ESI;
  char *pcVar6;
  char *pcVar7;
  undefined4 local_40c;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_1002fcc8 ^ (uint)&stack0xfffffffc;
  local_40c = param_1;
  if (DAT_1002fca8 != (void *)0xffffffff) {
    if (*param_2 != '\0') {
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 + (0x2d - (int)(param_2 + 1)) < (char *)0x401) {
        iVar4 = 0;
        do {
          cVar1 = "Stack around the variable \'"[iVar4];
          local_408[iVar4] = cVar1;
          iVar4 = iVar4 + 1;
          pcVar3 = param_2;
        } while (cVar1 != '\0');
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        uVar2 = (int)pcVar3 - (int)param_2;
        pcVar3 = (char *)((int)&local_40c + 3);
        do {
          pcVar7 = pcVar3 + 1;
          pcVar3 = pcVar3 + 1;
        } while (*pcVar7 != '\0');
        for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
          param_2 = param_2 + 4;
          pcVar3 = pcVar3 + 4;
        }
        for (uVar2 = uVar2 & 3; pcVar7 = "\' was corrupted.", uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar3 = *param_2;
          param_2 = param_2 + 1;
          pcVar3 = pcVar3 + 1;
        }
        do {
          pcVar3 = pcVar7;
          pcVar7 = pcVar3 + 1;
        } while (*pcVar3 != '\0');
        pcVar7 = (char *)((int)&local_40c + 3);
        do {
          pcVar6 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar6 != '\0');
        pcVar6 = "\' was corrupted.";
        for (uVar2 = (uint)(pcVar3 + -0x1002813b) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
          pcVar6 = pcVar6 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar2 = (uint)(pcVar3 + -0x1002813b) & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar7 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
    }
    failwithmessage(DAT_1002fca8,2,unaff_EBX,unaff_ESI);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001cacb at 1001cacb

undefined4 __cdecl FUN_1001cacb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10030980;
  DAT_1003097c = 0;
  DAT_10030980 = param_1;
  return uVar1;
}



// Function: FUN_1001cae7 at 1001cae7

undefined4 FUN_1001cae7(void)

{
  return DAT_1003097c;
}



// Function: FUN_1001caed at 1001caed

undefined4 FUN_1001caed(void)

{
  return DAT_10030980;
}



// Function: __SEH_prolog4 at 1001cb10

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002fcc8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1001cb55

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



// Function: FUN_1001cb69 at 1001cb69

void __cdecl
FUN_1001cb69(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1002fcc8,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 1001cbf0

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



// Function: __FindPESection at 1001cc30

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



// Function: __IsNonwritableInCurrentImage at 1001cc80

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
  
  pcStack_10 = FUN_1001cb69;
  local_14 = ExceptionList;
  local_c = DAT_1002fcc8 ^ 0x1002d9c8;
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



// Function: ___security_init_cookie at 1001cd54

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
  if ((DAT_1002fcc8 == 0xbb40e64e) || ((DAT_1002fcc8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1002fcc8 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1002fcc8 == 0xbb40e64e) {
      DAT_1002fcc8 = 0xbb40e64f;
    }
    else if ((DAT_1002fcc8 & 0xffff0000) == 0) {
      DAT_1002fcc8 = DAT_1002fcc8 | (DAT_1002fcc8 | 0x4711) << 0x10;
    }
    DAT_1002fccc = ~DAT_1002fcc8;
  }
  else {
    DAT_1002fccc = ~DAT_1002fcc8;
  }
  return;
}



// Function: FUN_1001cdef at 1001cdef

void FUN_1001cdef(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  FARPROC pFVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  wchar_t *pwVar6;
  WCHAR *pWVar7;
  int local_220;
  FARPROC local_21c;
  undefined4 local_218;
  uint local_214;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_1002fcc8 ^ (uint)&stack0xfffffffc;
  hModule = LoadLibraryW(L"ADVAPI32.DLL");
  if ((((hModule != (HMODULE)0x0) &&
       (local_21c = GetProcAddress(hModule,"RegOpenKeyExW"), local_21c != (FARPROC)0x0)) &&
      (pFVar1 = GetProcAddress(hModule,"RegQueryValueExW"), pFVar1 != (FARPROC)0x0)) &&
     (pFVar2 = GetProcAddress(hModule,"RegCloseKey"), pFVar2 != (FARPROC)0x0)) {
    iVar3 = (*local_21c)(0x80000002,L"SOFTWARE\\Microsoft\\VisualStudio\\10.0\\Setup\\VS",0,1,
                         &local_218);
    if (iVar3 == 0) {
      local_214 = 0x208;
      iVar3 = (*pFVar1)(local_218,L"EnvironmentDirectory",0,&local_220,local_210,&local_214);
      (*pFVar2)(local_218);
      FreeLibrary(hModule);
      if (((iVar3 == 0) && (local_220 == 1)) &&
         (((local_214 & 1) == 0 && (uVar4 = local_214 >> 1, 1 < uVar4)))) {
        if (local_210[uVar4 - 1] == L'\0') {
          uVar5 = uVar4 - 1;
          if (local_210[uVar4 - 2] != L'\\') {
            local_210[uVar4 - 1] = L'\\';
            uVar5 = uVar4;
          }
          if ((0xd < -uVar5 - 1) && (uVar5 + 0xd < 0x105)) {
            pwVar6 = L"MSPDB100.DLL";
            pWVar7 = local_210 + uVar5;
            for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
              *(undefined4 *)pWVar7 = *(undefined4 *)pwVar6;
              pwVar6 = pwVar6 + 2;
              pWVar7 = pWVar7 + 2;
            }
            *pWVar7 = *pwVar6;
            LoadLibraryW(local_210);
          }
        }
      }
    }
    else {
      FreeLibrary(hModule);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001cf4e at 1001cf4e

undefined4 __cdecl
FUN_1001cf4e(uint param_1,undefined2 *param_2,undefined4 param_3,uint *param_4,LPWSTR param_5,
            DWORD param_6)

{
  char cVar1;
  SIZE_T SVar2;
  DWORD DVar3;
  int *piVar4;
  FARPROC pFVar5;
  int iVar6;
  HANDLE pvVar7;
  uint uVar8;
  LPCVOID lpAddress;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  _MEMORY_BASIC_INFORMATION local_48;
  undefined1 local_2c [4];
  int local_28;
  undefined4 local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  *param_4 = 0;
  *param_2 = 0;
  lpAddress = (LPCVOID)(param_1 - 1);
  SVar2 = VirtualQuery(lpAddress,&local_48,0x1c);
  if ((((SVar2 == 0) ||
       (DVar3 = GetModuleFileNameW((HMODULE)local_48.AllocationBase,param_5,param_6), DVar3 == 0))
      || ((short)*(int *)local_48.AllocationBase != 0x5a4d)) ||
     ((((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused < 1 ||
      (piVar4 = (int *)((int)(int *)local_48.AllocationBase +
                       ((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused), *piVar4 != 0x4550)
      ))) {
    return 0;
  }
  uVar8 = (uint)*(ushort *)((int)piVar4 + 6);
  puVar10 = (uint *)(*(ushort *)(piVar4 + 5) + 0x24 + (int)piVar4);
  uVar9 = (int)lpAddress - (int)local_48.AllocationBase;
  uVar11 = 0;
  local_8 = 0;
  if (uVar8 != 0) {
    do {
      if ((*puVar10 <= uVar9) && (uVar11 = uVar9 - *puVar10, uVar9 < puVar10[-1])) break;
      local_8 = local_8 + 1;
      puVar10 = puVar10 + 10;
    } while (local_8 < uVar8);
  }
  if (local_8 == uVar8) {
    return 0;
  }
  local_8 = local_8 + 1;
  if (DAT_10030991 == '\0') {
    if (DAT_1003098c != (HMODULE)0x0) {
      return 0;
    }
    if (DAT_10030990 == '\0') {
      DAT_10030990 = '\x01';
      DAT_1003098c = (HMODULE)FUN_1001cdef();
    }
    else {
      DAT_1003098c = (HMODULE)0x0;
    }
    if (DAT_1003098c == (HMODULE)0x0) {
      return 0;
    }
    DAT_10030991 = '\x01';
  }
  pFVar5 = GetProcAddress(DAT_1003098c,"PDBOpenValidate5");
  if ((pFVar5 == (FARPROC)0x0) ||
     (iVar6 = (*pFVar5)(param_5,0,0,0,local_2c,0,0,&local_18), iVar6 == 0)) {
    return 0;
  }
  local_24 = 0;
  iVar6 = (**(code **)*local_18)();
  if ((iVar6 == 0x131a5b5) &&
     (iVar6 = (**(code **)(*local_18 + 0x1c))(0,&DAT_10028460,&local_20), iVar6 != 0)) {
    iVar6 = (**(code **)(*local_20 + 0x20))(local_8,uVar11,&local_14,0,0,0);
    if (iVar6 != 0) {
      local_c = (int *)0x0;
      cVar1 = (**(code **)(*local_14 + 0x68))(&local_c);
      if ((cVar1 != '\0') && (local_c != (int *)0x0)) {
        puVar10 = (uint *)0x0;
        do {
          iVar6 = (**(code **)(*local_c + 8))();
          if (iVar6 == 0) goto LAB_1001d1a3;
          cVar1 = (**(code **)(*local_c + 0xc))(0,&local_1c,&param_1,&local_28,&local_10,0);
          if (cVar1 == '\0') goto LAB_1001d1b2;
        } while ((((param_1 & 0xffff) != local_8) || (uVar11 < local_1c)) ||
                (local_1c + local_28 <= uVar11));
        if ((local_10 != 0) && (local_10 < 0x1fffffff)) {
          SVar2 = local_10 << 3;
          DVar3 = 0;
          pvVar7 = GetProcessHeap();
          puVar10 = (uint *)HeapAlloc(pvVar7,DVar3,SVar2);
          if (puVar10 != (uint *)0x0) {
            cVar1 = (**(code **)(*local_c + 0xc))(&local_8,0,0,0,&local_10,puVar10);
            if ((cVar1 != '\0') && (*puVar10 <= uVar11 - local_1c)) {
              uVar8 = 1;
              if (1 < local_10) {
                do {
                  if (uVar11 - local_1c < puVar10[uVar8 * 2]) break;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < local_10);
              }
              *param_4 = puVar10[uVar8 * 2 + -1] & 0xffffff;
              cVar1 = (**(code **)(*local_14 + 0x70))(local_8,param_2,&param_3,0,0,0);
              if (cVar1 != '\0') {
                local_24 = 1;
              }
            }
LAB_1001d1a3:
            DVar3 = 0;
            pvVar7 = GetProcessHeap();
            HeapFree(pvVar7,DVar3,puVar10);
          }
        }
LAB_1001d1b2:
        (**(code **)*local_c)();
      }
      (**(code **)(*local_14 + 0x40))();
    }
    (**(code **)(*local_20 + 0x38))();
  }
  (**(code **)(*local_18 + 0x28))();
  return local_24;
}



// Function: __security_check_cookie at 1001d1d9

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1002fcc8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: ___report_gsfailure at 1001d1fa

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
  
  _DAT_10030ab0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10030ab4 = &stack0x00000004;
  _DAT_100309f0 = 0x10001;
  _DAT_10030998 = 0xc0000409;
  _DAT_1003099c = 1;
  local_32c = DAT_1002fcc8;
  local_328 = DAT_1002fccc;
  _DAT_100309a4 = unaff_retaddr;
  _DAT_10030a7c = in_GS;
  _DAT_10030a80 = in_FS;
  _DAT_10030a84 = in_ES;
  _DAT_10030a88 = in_DS;
  _DAT_10030a8c = unaff_EDI;
  _DAT_10030a90 = unaff_ESI;
  _DAT_10030a94 = unaff_EBX;
  _DAT_10030a98 = in_EDX;
  _DAT_10030a9c = in_ECX;
  _DAT_10030aa0 = in_EAX;
  _DAT_10030aa4 = unaff_EBP;
  DAT_10030aa8 = unaff_retaddr;
  _DAT_10030aac = in_CS;
  _DAT_10030ab8 = in_SS;
  DAT_100309e8 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10028478);
  if (DAT_100309e8 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: Unwind@1001d310 at 1001d310

void Unwind_1001d310(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d318 at 1001d318

void Unwind_1001d318(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d320 at 1001d320

void Unwind_1001d320(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d328 at 1001d328

void Unwind_1001d328(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001d333 at 1001d333

void Unwind_1001d333(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d33b at 1001d33b

void Unwind_1001d33b(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d343 at 1001d343

void Unwind_1001d343(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001d34e at 1001d34e

void Unwind_1001d34e(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d356 at 1001d356

void Unwind_1001d356(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d35e at 1001d35e

void Unwind_1001d35e(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001d366 at 1001d366

void Unwind_1001d366(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001d36e at 1001d36e

void Unwind_1001d36e(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001d379 at 1001d379

void Unwind_1001d379(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001d384 at 1001d384

void Unwind_1001d384(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001d38f at 1001d38f

void Unwind_1001d38f(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001d39a at 1001d39a

void Unwind_1001d39a(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001d3a5 at 1001d3a5

void Unwind_1001d3a5(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001d3b0 at 1001d3b0

void Unwind_1001d3b0(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001d3bb at 1001d3bb

void Unwind_1001d3bb(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001d3c6 at 1001d3c6

void Unwind_1001d3c6(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001d3d1 at 1001d3d1

void Unwind_1001d3d1(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001d3dc at 1001d3dc

void Unwind_1001d3dc(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001d3e7 at 1001d3e7

void Unwind_1001d3e7(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001d3f2 at 1001d3f2

void Unwind_1001d3f2(void)

{
  int unaff_EBP;
  
  FUN_10001bf0((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001d3fd at 1001d3fd

void Unwind_1001d3fd(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0xdc);
  return;
}



// Function: Unwind@1001d408 at 1001d408

void Unwind_1001d408(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001d413 at 1001d413

void Unwind_1001d413(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001d41e at 1001d41e

void Unwind_1001d41e(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001d429 at 1001d429

void Unwind_1001d429(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d431 at 1001d431

void Unwind_1001d431(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d450 at 1001d450

void Unwind_1001d450(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d470 at 1001d470

void Unwind_1001d470(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d478 at 1001d478

void Unwind_1001d478(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d480 at 1001d480

void Unwind_1001d480(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d488 at 1001d488

void Unwind_1001d488(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x54);
  return;
}



// Function: Unwind@1001d490 at 1001d490

void Unwind_1001d490(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d498 at 1001d498

void Unwind_1001d498(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4a0 at 1001d4a0

void Unwind_1001d4a0(void)

{
  int unaff_EBP;
  
  FUN_10001bf0((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4a8 at 1001d4a8

void Unwind_1001d4a8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4b0 at 1001d4b0

void Unwind_1001d4b0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4b8 at 1001d4b8

void Unwind_1001d4b8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4c0 at 1001d4c0

void Unwind_1001d4c0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001d4c8 at 1001d4c8

void Unwind_1001d4c8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d4e0 at 1001d4e0

void Unwind_1001d4e0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d4e8 at 1001d4e8

void Unwind_1001d4e8(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d4f0 at 1001d4f0

void Unwind_1001d4f0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d4f8 at 1001d4f8

void Unwind_1001d4f8(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d500 at 1001d500

void Unwind_1001d500(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d508 at 1001d508

void Unwind_1001d508(void)

{
  int unaff_EBP;
  
  FUN_100046b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d510 at 1001d510

void Unwind_1001d510(void)

{
  int unaff_EBP;
  
  FUN_10002320((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d518 at 1001d518

void Unwind_1001d518(void)

{
  int unaff_EBP;
  
  FUN_100046b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d520 at 1001d520

void Unwind_1001d520(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d528 at 1001d528

void Unwind_1001d528(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d530 at 1001d530

void Unwind_1001d530(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001d538 at 1001d538

void Unwind_1001d538(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d540 at 1001d540

void Unwind_1001d540(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d560 at 1001d560

void Unwind_1001d560(void)

{
  int unaff_EBP;
  
  FUN_100046b0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d568 at 1001d568

void Unwind_1001d568(void)

{
  int unaff_EBP;
  
  FUN_10001b90(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d570 at 1001d570

void Unwind_1001d570(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d57b at 1001d57b

void Unwind_1001d57b(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d583 at 1001d583

void Unwind_1001d583(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d5a0 at 1001d5a0

void Unwind_1001d5a0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d5c0 at 1001d5c0

void Unwind_1001d5c0(void)

{
  int unaff_EBP;
  
  FUN_100037a0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d5c8 at 1001d5c8

void Unwind_1001d5c8(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d5d0 at 1001d5d0

void Unwind_1001d5d0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d5f0 at 1001d5f0

void Unwind_1001d5f0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d5f8 at 1001d5f8

void Unwind_1001d5f8(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001d610 at 1001d610

void Unwind_1001d610(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001d61b at 1001d61b

void Unwind_1001d61b(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d640 at 1001d640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d640(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d660 at 1001d660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d660(void)

{
  int unaff_EBP;
  
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d680 at 1001d680

void Unwind_1001d680(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d688 at 1001d688

void Unwind_1001d688(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001d6b0 at 1001d6b0

void Unwind_1001d6b0(void)

{
  int unaff_EBP;
  
  FUN_100046b0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001d6b8 at 1001d6b8

void Unwind_1001d6b8(void)

{
  int unaff_EBP;
  
  FUN_10001b90(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001d6c0 at 1001d6c0

void Unwind_1001d6c0(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@1001d6cb at 1001d6cb

void Unwind_1001d6cb(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d6d3 at 1001d6d3

void Unwind_1001d6d3(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001d6f0 at 1001d6f0

void Unwind_1001d6f0(void)

{
  int unaff_EBP;
  
  FUN_10001b90(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d6f8 at 1001d6f8

void Unwind_1001d6f8(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d703 at 1001d703

void Unwind_1001d703(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d70b at 1001d70b

void Unwind_1001d70b(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d720 at 1001d720

void Unwind_1001d720(void)

{
  FUN_10014b90();
  return;
}



// Function: Unwind@1001d731 at 1001d731

void Unwind_1001d731(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d739 at 1001d739

void Unwind_1001d739(void)

{
  int unaff_EBP;
  
  FUN_10001b90(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d741 at 1001d741

void Unwind_1001d741(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d749 at 1001d749

void Unwind_1001d749(void)

{
  int unaff_EBP;
  
  FUN_10001b90((undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4));
  return;
}



// Function: Unwind@1001d754 at 1001d754

void Unwind_1001d754(void)

{
  int unaff_EBP;
  
  FUN_100046b0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d770 at 1001d770

void Unwind_1001d770(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d790 at 1001d790

void Unwind_1001d790(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d7b0 at 1001d7b0

void Unwind_1001d7b0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d7d0 at 1001d7d0

void Unwind_1001d7d0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d7f0 at 1001d7f0

void Unwind_1001d7f0(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001d7f8 at 1001d7f8

void Unwind_1001d7f8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d800 at 1001d800

void Unwind_1001d800(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d808 at 1001d808

void Unwind_1001d808(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d810 at 1001d810

void Unwind_1001d810(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d818 at 1001d818

void Unwind_1001d818(void)

{
  int unaff_EBP;
  
  FUN_10001bf0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d820 at 1001d820

void Unwind_1001d820(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d828 at 1001d828

void Unwind_1001d828(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d830 at 1001d830

void Unwind_1001d830(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001d838 at 1001d838

void Unwind_1001d838(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x4c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x4c) = *(uint *)(unaff_EBP + -0x4c) & 0xfffffffe;
    FUN_10013b00(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001d851 at 1001d851

void Unwind_1001d851(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d859 at 1001d859

void Unwind_1001d859(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d861 at 1001d861

void Unwind_1001d861(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d869 at 1001d869

void Unwind_1001d869(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d880 at 1001d880

void Unwind_1001d880(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001d888 at 1001d888

void Unwind_1001d888(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d890 at 1001d890

void Unwind_1001d890(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d898 at 1001d898

void Unwind_1001d898(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d8a0 at 1001d8a0

void Unwind_1001d8a0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d8a8 at 1001d8a8

void Unwind_1001d8a8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d8b0 at 1001d8b0

void Unwind_1001d8b0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d8b8 at 1001d8b8

void Unwind_1001d8b8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d8c0 at 1001d8c0

void Unwind_1001d8c0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d8c8 at 1001d8c8

void Unwind_1001d8c8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d8d0 at 1001d8d0

void Unwind_1001d8d0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001d8d8 at 1001d8d8

void Unwind_1001d8d8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001d8e0 at 1001d8e0

void Unwind_1001d8e0(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x90);
  return;
}



// Function: Unwind@1001d8eb at 1001d8eb

void Unwind_1001d8eb(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001d8f3 at 1001d8f3

void Unwind_1001d8f3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001d8fb at 1001d8fb

void Unwind_1001d8fb(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d903 at 1001d903

void Unwind_1001d903(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001d90b at 1001d90b

void Unwind_1001d90b(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001d920 at 1001d920

void Unwind_1001d920(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d940 at 1001d940

void Unwind_1001d940(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d960 at 1001d960

void Unwind_1001d960(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d980 at 1001d980

void Unwind_1001d980(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001d9a0 at 1001d9a0

void Unwind_1001d9a0(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d9a8 at 1001d9a8

void Unwind_1001d9a8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d9b0 at 1001d9b0

void Unwind_1001d9b0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d9b8 at 1001d9b8

void Unwind_1001d9b8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001d9c3 at 1001d9c3

void Unwind_1001d9c3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001d9ce at 1001d9ce

void Unwind_1001d9ce(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d9d6 at 1001d9d6

void Unwind_1001d9d6(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d9de at 1001d9de

void Unwind_1001d9de(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001d9e6 at 1001d9e6

void Unwind_1001d9e6(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001d9ee at 1001d9ee

void Unwind_1001d9ee(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x104));
  return;
}



// Function: Unwind@1001d9f9 at 1001d9f9

void Unwind_1001d9f9(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001da01 at 1001da01

void Unwind_1001da01(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001da09 at 1001da09

void Unwind_1001da09(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001da11 at 1001da11

void Unwind_1001da11(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001da19 at 1001da19

void Unwind_1001da19(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@1001da24 at 1001da24

void Unwind_1001da24(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001da2f at 1001da2f

void Unwind_1001da2f(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@1001da3a at 1001da3a

void Unwind_1001da3a(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001da45 at 1001da45

void Unwind_1001da45(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001da50 at 1001da50

void Unwind_1001da50(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001da5b at 1001da5b

void Unwind_1001da5b(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001da66 at 1001da66

void Unwind_1001da66(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001da71 at 1001da71

void Unwind_1001da71(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001da7c at 1001da7c

void Unwind_1001da7c(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001da87 at 1001da87

void Unwind_1001da87(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001da92 at 1001da92

void Unwind_1001da92(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1001da9d at 1001da9d

void Unwind_1001da9d(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001daa8 at 1001daa8

void Unwind_1001daa8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001dab3 at 1001dab3

void Unwind_1001dab3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001dabe at 1001dabe

void Unwind_1001dabe(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001dac9 at 1001dac9

void Unwind_1001dac9(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1001dad4 at 1001dad4

void Unwind_1001dad4(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@1001dadf at 1001dadf

void Unwind_1001dadf(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1001daea at 1001daea

void Unwind_1001daea(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x130);
  return;
}



// Function: Unwind@1001daf5 at 1001daf5

void Unwind_1001daf5(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001db00 at 1001db00

void Unwind_1001db00(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001db0b at 1001db0b

void Unwind_1001db0b(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001db16 at 1001db16

void Unwind_1001db16(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001db21 at 1001db21

void Unwind_1001db21(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001db2c at 1001db2c

void Unwind_1001db2c(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001db37 at 1001db37

void Unwind_1001db37(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001db3f at 1001db3f

void Unwind_1001db3f(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001db47 at 1001db47

void Unwind_1001db47(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001db4f at 1001db4f

void Unwind_1001db4f(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001db70 at 1001db70

void Unwind_1001db70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001db90 at 1001db90

void Unwind_1001db90(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dbb0 at 1001dbb0

void Unwind_1001dbb0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dbd0 at 1001dbd0

void Unwind_1001dbd0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dbf0 at 1001dbf0

void Unwind_1001dbf0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dc10 at 1001dc10

void Unwind_1001dc10(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dc30 at 1001dc30

void Unwind_1001dc30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dc50 at 1001dc50

void Unwind_1001dc50(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dc70 at 1001dc70

void Unwind_1001dc70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dc90 at 1001dc90

void Unwind_1001dc90(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dcb0 at 1001dcb0

void Unwind_1001dcb0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dcd0 at 1001dcd0

void Unwind_1001dcd0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dcf0 at 1001dcf0

void Unwind_1001dcf0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dd10 at 1001dd10

void Unwind_1001dd10(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dd30 at 1001dd30

void Unwind_1001dd30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dd50 at 1001dd50

void Unwind_1001dd50(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dd70 at 1001dd70

void Unwind_1001dd70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001dd90 at 1001dd90

void Unwind_1001dd90(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ddb0 at 1001ddb0

void Unwind_1001ddb0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ddd0 at 1001ddd0

void Unwind_1001ddd0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ddf0 at 1001ddf0

void Unwind_1001ddf0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001de10 at 1001de10

void Unwind_1001de10(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001de18 at 1001de18

void Unwind_1001de18(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001de20 at 1001de20

void Unwind_1001de20(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001de28 at 1001de28

void Unwind_1001de28(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001de33 at 1001de33

void Unwind_1001de33(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001de3b at 1001de3b

void Unwind_1001de3b(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001de46 at 1001de46

void Unwind_1001de46(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001de51 at 1001de51

void Unwind_1001de51(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001de59 at 1001de59

void Unwind_1001de59(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001de64 at 1001de64

void Unwind_1001de64(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001de6f at 1001de6f

void Unwind_1001de6f(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001de77 at 1001de77

void Unwind_1001de77(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1001de82 at 1001de82

void Unwind_1001de82(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001de8d at 1001de8d

void Unwind_1001de8d(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001de95 at 1001de95

void Unwind_1001de95(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1001dea0 at 1001dea0

void Unwind_1001dea0(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001deab at 1001deab

void Unwind_1001deab(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001deb3 at 1001deb3

void Unwind_1001deb3(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001debe at 1001debe

void Unwind_1001debe(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001dec9 at 1001dec9

void Unwind_1001dec9(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001ded4 at 1001ded4

void Unwind_1001ded4(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001dedf at 1001dedf

void Unwind_1001dedf(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001deea at 1001deea

void Unwind_1001deea(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@1001def5 at 1001def5

void Unwind_1001def5(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001df00 at 1001df00

void Unwind_1001df00(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001df0b at 1001df0b

void Unwind_1001df0b(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001df16 at 1001df16

void Unwind_1001df16(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001df21 at 1001df21

void Unwind_1001df21(void)

{
  int unaff_EBP;
  
  FUN_10001bf0((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001df2c at 1001df2c

void Unwind_1001df2c(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x100);
  return;
}



// Function: Unwind@1001df37 at 1001df37

void Unwind_1001df37(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001df42 at 1001df42

void Unwind_1001df42(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001df4d at 1001df4d

void Unwind_1001df4d(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001df70 at 1001df70

void Unwind_1001df70(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001df78 at 1001df78

void Unwind_1001df78(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001df80 at 1001df80

void Unwind_1001df80(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001df88 at 1001df88

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001df88(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001df9d at 1001df9d

void Unwind_1001df9d(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001dfa5 at 1001dfa5

void Unwind_1001dfa5(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001dfad at 1001dfad

void Unwind_1001dfad(void)

{
  int unaff_EBP;
  
  FUN_10001bf0((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001dfb5 at 1001dfb5

void Unwind_1001dfb5(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x5c);
  return;
}



// Function: Unwind@1001dfbd at 1001dfbd

void Unwind_1001dfbd(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001dfc5 at 1001dfc5

void Unwind_1001dfc5(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001dfcd at 1001dfcd

void Unwind_1001dfcd(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001dfd5 at 1001dfd5

void Unwind_1001dfd5(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x74);
  return;
}



// Function: Unwind@1001dff0 at 1001dff0

void Unwind_1001dff0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e020 at 1001e020

void Unwind_1001e020(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e040 at 1001e040

void Unwind_1001e040(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e060 at 1001e060

void Unwind_1001e060(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e080 at 1001e080

void Unwind_1001e080(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e0a0 at 1001e0a0

void Unwind_1001e0a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e0c0 at 1001e0c0

void Unwind_1001e0c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e0e0 at 1001e0e0

void Unwind_1001e0e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e100 at 1001e100

void Unwind_1001e100(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e120 at 1001e120

void Unwind_1001e120(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e140 at 1001e140

void Unwind_1001e140(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e160 at 1001e160

void Unwind_1001e160(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e180 at 1001e180

void Unwind_1001e180(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e1a0 at 1001e1a0

void Unwind_1001e1a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e1c0 at 1001e1c0

void Unwind_1001e1c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e1e0 at 1001e1e0

void Unwind_1001e1e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e200 at 1001e200

void Unwind_1001e200(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e220 at 1001e220

void Unwind_1001e220(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e240 at 1001e240

void Unwind_1001e240(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e260 at 1001e260

void Unwind_1001e260(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e280 at 1001e280

void Unwind_1001e280(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e2a0 at 1001e2a0

void Unwind_1001e2a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e2c0 at 1001e2c0

void Unwind_1001e2c0(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001e2c8 at 1001e2c8

void Unwind_1001e2c8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e2d0 at 1001e2d0

void Unwind_1001e2d0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e2d8 at 1001e2d8

void Unwind_1001e2d8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001e2e3 at 1001e2e3

void Unwind_1001e2e3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001e2ee at 1001e2ee

void Unwind_1001e2ee(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001e2f6 at 1001e2f6

void Unwind_1001e2f6(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001e2fe at 1001e2fe

void Unwind_1001e2fe(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001e306 at 1001e306

void Unwind_1001e306(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001e30e at 1001e30e

void Unwind_1001e30e(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001e319 at 1001e319

void Unwind_1001e319(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001e321 at 1001e321

void Unwind_1001e321(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001e329 at 1001e329

void Unwind_1001e329(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001e331 at 1001e331

void Unwind_1001e331(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001e339 at 1001e339

void Unwind_1001e339(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001e344 at 1001e344

void Unwind_1001e344(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001e34f at 1001e34f

void Unwind_1001e34f(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001e35a at 1001e35a

void Unwind_1001e35a(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001e365 at 1001e365

void Unwind_1001e365(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001e370 at 1001e370

void Unwind_1001e370(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001e37b at 1001e37b

void Unwind_1001e37b(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0xd0);
  return;
}



// Function: Unwind@1001e386 at 1001e386

void Unwind_1001e386(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001e391 at 1001e391

void Unwind_1001e391(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001e399 at 1001e399

void Unwind_1001e399(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001e3a1 at 1001e3a1

void Unwind_1001e3a1(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001e3a9 at 1001e3a9

void Unwind_1001e3a9(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e3c0 at 1001e3c0

void Unwind_1001e3c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e3e0 at 1001e3e0

void Unwind_1001e3e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e400 at 1001e400

void Unwind_1001e400(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e420 at 1001e420

void Unwind_1001e420(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e440 at 1001e440

void Unwind_1001e440(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e448 at 1001e448

void Unwind_1001e448(void)

{
  int unaff_EBP;
  
  FUN_10009020((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001e450 at 1001e450

void Unwind_1001e450(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e458 at 1001e458

void Unwind_1001e458(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xacc));
  return;
}



// Function: Unwind@1001e463 at 1001e463

void Unwind_1001e463(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xae8));
  return;
}



// Function: Unwind@1001e46e at 1001e46e

void Unwind_1001e46e(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e476 at 1001e476

void Unwind_1001e476(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb00));
  return;
}



// Function: Unwind@1001e481 at 1001e481

void Unwind_1001e481(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001e489 at 1001e489

void Unwind_1001e489(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e491 at 1001e491

void Unwind_1001e491(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb08));
  return;
}



// Function: Unwind@1001e49c at 1001e49c

void Unwind_1001e49c(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e4a4 at 1001e4a4

void Unwind_1001e4a4(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb10));
  return;
}



// Function: Unwind@1001e4af at 1001e4af

void Unwind_1001e4af(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e4b7 at 1001e4b7

void Unwind_1001e4b7(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb1c));
  return;
}



// Function: Unwind@1001e4c2 at 1001e4c2

void Unwind_1001e4c2(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xb38));
  return;
}



// Function: Unwind@1001e4cd at 1001e4cd

void Unwind_1001e4cd(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xb60));
  return;
}



// Function: Unwind@1001e4f0 at 1001e4f0

void Unwind_1001e4f0(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e510 at 1001e510

void Unwind_1001e510(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001e518 at 1001e518

void Unwind_1001e518(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001e530 at 1001e530

void Unwind_1001e530(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001e53b at 1001e53b

void Unwind_1001e53b(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e550 at 1001e550

void Unwind_1001e550(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e558 at 1001e558

void Unwind_1001e558(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@1001e570 at 1001e570

void Unwind_1001e570(void)

{
  int unaff_EBP;
  
  FUN_1000a5f0(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001e590 at 1001e590

void Unwind_1001e590(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001e5b0 at 1001e5b0

void Unwind_1001e5b0(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e5b8 at 1001e5b8

void Unwind_1001e5b8(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@1001e5c3 at 1001e5c3

void Unwind_1001e5c3(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x2274));
  return;
}



// Function: Unwind@1001e5ce at 1001e5ce

void Unwind_1001e5ce(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x2288));
  return;
}



// Function: Unwind@1001e5d9 at 1001e5d9

void Unwind_1001e5d9(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x22a0));
  return;
}



// Function: Unwind@1001e5f0 at 1001e5f0

void Unwind_1001e5f0(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e610 at 1001e610

void Unwind_1001e610(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2138));
  return;
}



// Function: Unwind@1001e61b at 1001e61b

void Unwind_1001e61b(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x2164));
  return;
}



// Function: Unwind@1001e626 at 1001e626

void Unwind_1001e626(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x227c));
  return;
}



// Function: Unwind@1001e640 at 1001e640

void Unwind_1001e640(void)

{
  DAT_10030320 = DAT_10030320 & 0xfffffffe;
  return;
}



// Function: Unwind@1001e660 at 1001e660

void Unwind_1001e660(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e668 at 1001e668

void Unwind_1001e668(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e670 at 1001e670

void Unwind_1001e670(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e678 at 1001e678

void Unwind_1001e678(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e680 at 1001e680

void Unwind_1001e680(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e688 at 1001e688

void Unwind_1001e688(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e690 at 1001e690

void Unwind_1001e690(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001e69b at 1001e69b

void Unwind_1001e69b(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x1f8));
  return;
}



// Function: Unwind@1001e6a6 at 1001e6a6

void Unwind_1001e6a6(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20c));
  return;
}



// Function: Unwind@1001e6b1 at 1001e6b1

void Unwind_1001e6b1(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e6d0 at 1001e6d0

void Unwind_1001e6d0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e6d8 at 1001e6d8

void Unwind_1001e6d8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e6e0 at 1001e6e0

void Unwind_1001e6e0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e6e8 at 1001e6e8

void Unwind_1001e6e8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001e6f3 at 1001e6f3

void Unwind_1001e6f3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e6fb at 1001e6fb

void Unwind_1001e6fb(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e710 at 1001e710

void Unwind_1001e710(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001e730 at 1001e730

void Unwind_1001e730(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e738 at 1001e738

void Unwind_1001e738(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e740 at 1001e740

void Unwind_1001e740(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e748 at 1001e748

void Unwind_1001e748(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e750 at 1001e750

void Unwind_1001e750(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e770 at 1001e770

void Unwind_1001e770(void)

{
  int unaff_EBP;
  
  FUN_10014a90((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001e790 at 1001e790

void Unwind_1001e790(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e79b at 1001e79b

void Unwind_1001e79b(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x20) + 4);
  return;
}



// Function: Unwind@1001e7a6 at 1001e7a6

void Unwind_1001e7a6(void)

{
  int unaff_EBP;
  
  FUN_1000f800(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e7c0 at 1001e7c0

void Unwind_1001e7c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e7c8 at 1001e7c8

void Unwind_1001e7c8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e7d0 at 1001e7d0

void Unwind_1001e7d0(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e7d8 at 1001e7d8

void Unwind_1001e7d8(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001e7f0 at 1001e7f0

void Unwind_1001e7f0(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001e7fb at 1001e7fb

void Unwind_1001e7fb(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e803 at 1001e803

void Unwind_1001e803(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001e80e at 1001e80e

void Unwind_1001e80e(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e816 at 1001e816

void Unwind_1001e816(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e830 at 1001e830

void Unwind_1001e830(void)

{
  FUN_10014b90();
  return;
}



// Function: Unwind@1001e849 at 1001e849

void Unwind_1001e849(void)

{
  FUN_10014b90();
  return;
}



// Function: Unwind@1001e870 at 1001e870

void Unwind_1001e870(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x1c) + 0xc);
  return;
}



// Function: Unwind@1001e87b at 1001e87b

void Unwind_1001e87b(void)

{
  int unaff_EBP;
  
  FUN_10016760(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e890 at 1001e890

void Unwind_1001e890(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e898 at 1001e898

void Unwind_1001e898(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e8a0 at 1001e8a0

void Unwind_1001e8a0(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001e8a8 at 1001e8a8

void Unwind_1001e8a8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e8b3 at 1001e8b3

void Unwind_1001e8b3(void)

{
  int unaff_EBP;
  
  FUN_100038d0(*(void **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001e8bb at 1001e8bb

void Unwind_1001e8bb(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e8c3 at 1001e8c3

void Unwind_1001e8c3(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e8e0 at 1001e8e0

void Unwind_1001e8e0(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001e8e8 at 1001e8e8

void Unwind_1001e8e8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e8f0 at 1001e8f0

void Unwind_1001e8f0(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001e8f8 at 1001e8f8

void Unwind_1001e8f8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e900 at 1001e900

void Unwind_1001e900(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001e908 at 1001e908

void Unwind_1001e908(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e910 at 1001e910

void Unwind_1001e910(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001e918 at 1001e918

void Unwind_1001e918(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e923 at 1001e923

void Unwind_1001e923(void)

{
  int unaff_EBP;
  
  FUN_100038d0(*(void **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001e92e at 1001e92e

void Unwind_1001e92e(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001e939 at 1001e939

void Unwind_1001e939(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1001e944 at 1001e944

void Unwind_1001e944(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e94f at 1001e94f

void Unwind_1001e94f(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@1001e95a at 1001e95a

void Unwind_1001e95a(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e965 at 1001e965

void Unwind_1001e965(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e970 at 1001e970

void Unwind_1001e970(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e97b at 1001e97b

void Unwind_1001e97b(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1001e986 at 1001e986

void Unwind_1001e986(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e991 at 1001e991

void Unwind_1001e991(void)

{
  int unaff_EBP;
  
  FUN_100038d0(*(void **)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@1001e99c at 1001e99c

void Unwind_1001e99c(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e9a7 at 1001e9a7

void Unwind_1001e9a7(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e9af at 1001e9af

void Unwind_1001e9af(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e9b7 at 1001e9b7

void Unwind_1001e9b7(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001e9d0 at 1001e9d0

void Unwind_1001e9d0(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001e9d8 at 1001e9d8

void Unwind_1001e9d8(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e9e0 at 1001e9e0

void Unwind_1001e9e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea00 at 1001ea00

void Unwind_1001ea00(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ea08 at 1001ea08

void Unwind_1001ea08(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@1001ea13 at 1001ea13

void Unwind_1001ea13(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea30 at 1001ea30

void Unwind_1001ea30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea38 at 1001ea38

void Unwind_1001ea38(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ea40 at 1001ea40

void Unwind_1001ea40(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea48 at 1001ea48

void Unwind_1001ea48(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001ea50 at 1001ea50

void Unwind_1001ea50(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea58 at 1001ea58

void Unwind_1001ea58(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001ea60 at 1001ea60

void Unwind_1001ea60(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001ea6b at 1001ea6b

void Unwind_1001ea6b(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001ea76 at 1001ea76

void Unwind_1001ea76(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea81 at 1001ea81

void Unwind_1001ea81(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@1001ea8c at 1001ea8c

void Unwind_1001ea8c(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ea97 at 1001ea97

void Unwind_1001ea97(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eaa2 at 1001eaa2

void Unwind_1001eaa2(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eaaa at 1001eaaa

void Unwind_1001eaaa(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eab2 at 1001eab2

void Unwind_1001eab2(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ead0 at 1001ead0

void Unwind_1001ead0(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ead8 at 1001ead8

void Unwind_1001ead8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eaf0 at 1001eaf0

void Unwind_1001eaf0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eaf8 at 1001eaf8

void Unwind_1001eaf8(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001eb00 at 1001eb00

void Unwind_1001eb00(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb08 at 1001eb08

void Unwind_1001eb08(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001eb10 at 1001eb10

void Unwind_1001eb10(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb18 at 1001eb18

void Unwind_1001eb18(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb30 at 1001eb30

void Unwind_1001eb30(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001eb38 at 1001eb38

void Unwind_1001eb38(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@1001eb43 at 1001eb43

void Unwind_1001eb43(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1001eb4e at 1001eb4e

void Unwind_1001eb4e(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb59 at 1001eb59

void Unwind_1001eb59(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb70 at 1001eb70

void Unwind_1001eb70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eb78 at 1001eb78

void Unwind_1001eb78(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001eb80 at 1001eb80

void Unwind_1001eb80(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eba0 at 1001eba0

void Unwind_1001eba0(void)

{
  int unaff_EBP;
  
  FUN_1000b6f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001eba8 at 1001eba8

void Unwind_1001eba8(void)

{
  int unaff_EBP;
  
  FUN_100038d0((void *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@1001ebb3 at 1001ebb3

void Unwind_1001ebb3(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ebd0 at 1001ebd0

void Unwind_1001ebd0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ebdb at 1001ebdb

void Unwind_1001ebdb(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ebe3 at 1001ebe3

void Unwind_1001ebe3(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001ebee at 1001ebee

void Unwind_1001ebee(void)

{
  int unaff_EBP;
  
  FUN_10016970(*(int *)(unaff_EBP + -0x20) + 0xc);
  return;
}



// Function: Unwind@1001ec10 at 1001ec10

void Unwind_1001ec10(void)

{
  int unaff_EBP;
  
  FUN_10016af0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ec30 at 1001ec30

void Unwind_1001ec30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ec38 at 1001ec38

void Unwind_1001ec38(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ec40 at 1001ec40

void Unwind_1001ec40(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001ec4b at 1001ec4b

void Unwind_1001ec4b(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001ec56 at 1001ec56

void Unwind_1001ec56(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ec5e at 1001ec5e

void Unwind_1001ec5e(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001ec69 at 1001ec69

void Unwind_1001ec69(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ec71 at 1001ec71

void Unwind_1001ec71(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001ec7c at 1001ec7c

void Unwind_1001ec7c(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001ec87 at 1001ec87

void Unwind_1001ec87(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001ec92 at 1001ec92

void Unwind_1001ec92(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001ec9d at 1001ec9d

void Unwind_1001ec9d(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001eca8 at 1001eca8

void Unwind_1001eca8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001ecb3 at 1001ecb3

void Unwind_1001ecb3(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@1001ecbe at 1001ecbe

void Unwind_1001ecbe(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1001ece0 at 1001ece0

void Unwind_1001ece0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001eceb at 1001eceb

void Unwind_1001eceb(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ecf3 at 1001ecf3

void Unwind_1001ecf3(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001ecfe at 1001ecfe

void Unwind_1001ecfe(void)

{
  int unaff_EBP;
  
  FUN_10016da0(*(int *)(unaff_EBP + -0x20) + 0xc);
  return;
}



// Function: Unwind@1001ed20 at 1001ed20

void Unwind_1001ed20(void)

{
  int unaff_EBP;
  
  FUN_10016ec0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ed40 at 1001ed40

void Unwind_1001ed40(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ed48 at 1001ed48

void Unwind_1001ed48(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ed50 at 1001ed50

void Unwind_1001ed50(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ed58 at 1001ed58

void Unwind_1001ed58(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001ed63 at 1001ed63

void Unwind_1001ed63(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001ed6e at 1001ed6e

void Unwind_1001ed6e(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001ed79 at 1001ed79

void Unwind_1001ed79(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ed81 at 1001ed81

void Unwind_1001ed81(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001ed8c at 1001ed8c

void Unwind_1001ed8c(void)

{
  int unaff_EBP;
  
  FUN_10013b70((void *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001edb0 at 1001edb0

void Unwind_1001edb0(void)

{
  int unaff_EBP;
  
  FUN_10013c70(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001edd0 at 1001edd0

void Unwind_1001edd0(void)

{
  int unaff_EBP;
  
  FUN_10013d30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001edd8 at 1001edd8

void Unwind_1001edd8(void)

{
  int unaff_EBP;
  
  FUN_10013c70(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001edf0 at 1001edf0

void Unwind_1001edf0(void)

{
  int unaff_EBP;
  
  FUN_10013d30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ee10 at 1001ee10

void Unwind_1001ee10(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ee1b at 1001ee1b

void Unwind_1001ee1b(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ee23 at 1001ee23

void Unwind_1001ee23(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001ee2e at 1001ee2e

void Unwind_1001ee2e(void)

{
  int unaff_EBP;
  
  FUN_10017150(*(int *)(unaff_EBP + -0x20) + 0xc);
  return;
}



// Function: Unwind@1001ee50 at 1001ee50

void Unwind_1001ee50(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x1c) + 4);
  return;
}



// Function: Unwind@1001ee5b at 1001ee5b

void Unwind_1001ee5b(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ee63 at 1001ee63

void Unwind_1001ee63(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x1c) + 0x24));
  return;
}



// Function: Unwind@1001ee6e at 1001ee6e

void Unwind_1001ee6e(void)

{
  int unaff_EBP;
  
  FUN_10017270(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ee80 at 1001ee80

void Unwind_1001ee80(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ee88 at 1001ee88

void Unwind_1001ee88(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ee93 at 1001ee93

void Unwind_1001ee93(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ee9b at 1001ee9b

void Unwind_1001ee9b(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eeb0 at 1001eeb0

void Unwind_1001eeb0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001eed0 at 1001eed0

void Unwind_1001eed0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001eed8 at 1001eed8

void Unwind_1001eed8(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x28) + 4));
  return;
}



// Function: Unwind@1001eee3 at 1001eee3

void Unwind_1001eee3(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x1c) + 4);
  return;
}



// Function: Unwind@1001eeee at 1001eeee

void Unwind_1001eeee(void)

{
  int unaff_EBP;
  
  FUN_100175d0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ef00 at 1001ef00

void Unwind_1001ef00(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ef08 at 1001ef08

void Unwind_1001ef08(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ef20 at 1001ef20

void Unwind_1001ef20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ef40 at 1001ef40

void Unwind_1001ef40(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ef48 at 1001ef48

void Unwind_1001ef48(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ef60 at 1001ef60

void Unwind_1001ef60(void)

{
  int unaff_EBP;
  
  FUN_1000f800(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ef80 at 1001ef80

void Unwind_1001ef80(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ef88 at 1001ef88

void Unwind_1001ef88(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001ef93 at 1001ef93

void Unwind_1001ef93(void)

{
  int unaff_EBP;
  
  FUN_10017270(*(int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ef9b at 1001ef9b

void Unwind_1001ef9b(void)

{
  int unaff_EBP;
  
  FUN_10017430(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001efb0 at 1001efb0

void Unwind_1001efb0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001efb8 at 1001efb8

void Unwind_1001efb8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001efc0 at 1001efc0

void Unwind_1001efc0(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001efc8 at 1001efc8

void Unwind_1001efc8(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001efd3 at 1001efd3

void Unwind_1001efd3(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001efde at 1001efde

void Unwind_1001efde(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001efe6 at 1001efe6

void Unwind_1001efe6(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001f000 at 1001f000

void Unwind_1001f000(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f008 at 1001f008

void Unwind_1001f008(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f013 at 1001f013

void Unwind_1001f013(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f01b at 1001f01b

void Unwind_1001f01b(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f023 at 1001f023

void Unwind_1001f023(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001f02b at 1001f02b

void Unwind_1001f02b(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x1c) + 4));
  return;
}



// Function: Unwind@1001f036 at 1001f036

void Unwind_1001f036(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x20) + 4);
  return;
}



// Function: Unwind@1001f041 at 1001f041

void Unwind_1001f041(void)

{
  int unaff_EBP;
  
  FUN_100175d0(*(int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f049 at 1001f049

void Unwind_1001f049(void)

{
  int unaff_EBP;
  
  FUN_100177e0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f060 at 1001f060

void Unwind_1001f060(void)

{
  int unaff_EBP;
  
  FUN_10016760(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f068 at 1001f068

void Unwind_1001f068(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f073 at 1001f073

void Unwind_1001f073(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f07b at 1001f07b

void Unwind_1001f07b(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f086 at 1001f086

void Unwind_1001f086(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f08e at 1001f08e

void Unwind_1001f08e(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f0a0 at 1001f0a0

void Unwind_1001f0a0(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f0ab at 1001f0ab

void Unwind_1001f0ab(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f0b3 at 1001f0b3

void Unwind_1001f0b3(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f0be at 1001f0be

void Unwind_1001f0be(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f0c6 at 1001f0c6

void Unwind_1001f0c6(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f0e0 at 1001f0e0

void Unwind_1001f0e0(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f0eb at 1001f0eb

void Unwind_1001f0eb(void)

{
  int unaff_EBP;
  
  FUN_10016970(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f0f6 at 1001f0f6

void Unwind_1001f0f6(void)

{
  int unaff_EBP;
  
  FUN_10016760(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001f0fe at 1001f0fe

void Unwind_1001f0fe(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x1c) + 0xc);
  return;
}



// Function: Unwind@1001f109 at 1001f109

void Unwind_1001f109(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f111 at 1001f111

void Unwind_1001f111(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f11c at 1001f11c

void Unwind_1001f11c(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f124 at 1001f124

void Unwind_1001f124(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f12c at 1001f12c

void Unwind_1001f12c(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f150 at 1001f150

void Unwind_1001f150(void)

{
  int unaff_EBP;
  
  FUN_10016af0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f170 at 1001f170

void Unwind_1001f170(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001f17b at 1001f17b

void Unwind_1001f17b(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001f186 at 1001f186

void Unwind_1001f186(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001f191 at 1001f191

void Unwind_1001f191(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001f19c at 1001f19c

void Unwind_1001f19c(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001f1a7 at 1001f1a7

void Unwind_1001f1a7(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001f1b2 at 1001f1b2

void Unwind_1001f1b2(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001f1bd at 1001f1bd

void Unwind_1001f1bd(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001f1c8 at 1001f1c8

void Unwind_1001f1c8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@1001f1d3 at 1001f1d3

void Unwind_1001f1d3(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1001f1de at 1001f1de

void Unwind_1001f1de(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f1e6 at 1001f1e6

void Unwind_1001f1e6(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001f1ee at 1001f1ee

void Unwind_1001f1ee(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f1f6 at 1001f1f6

void Unwind_1001f1f6(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x20) + 4));
  return;
}



// Function: Unwind@1001f201 at 1001f201

void Unwind_1001f201(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001f209 at 1001f209

void Unwind_1001f209(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f220 at 1001f220

void Unwind_1001f220(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f22b at 1001f22b

void Unwind_1001f22b(void)

{
  int unaff_EBP;
  
  FUN_10016da0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f236 at 1001f236

void Unwind_1001f236(void)

{
  int unaff_EBP;
  
  FUN_10016af0(*(int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f23e at 1001f23e

void Unwind_1001f23e(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f260 at 1001f260

void Unwind_1001f260(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001f26b at 1001f26b

void Unwind_1001f26b(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001f276 at 1001f276

void Unwind_1001f276(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001f281 at 1001f281

void Unwind_1001f281(void)

{
  int unaff_EBP;
  
  FUN_10013b70((void *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001f28c at 1001f28c

void Unwind_1001f28c(void)

{
  int unaff_EBP;
  
  FUN_10013c70(*(void **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f294 at 1001f294

void Unwind_1001f294(void)

{
  int unaff_EBP;
  
  FUN_10013d30(*(int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f29c at 1001f29c

void Unwind_1001f29c(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001f2a4 at 1001f2a4

void Unwind_1001f2a4(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f2ac at 1001f2ac

void Unwind_1001f2ac(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@1001f2b7 at 1001f2b7

void Unwind_1001f2b7(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001f2bf at 1001f2bf

void Unwind_1001f2bf(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f2e0 at 1001f2e0

void Unwind_1001f2e0(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f2eb at 1001f2eb

void Unwind_1001f2eb(void)

{
  int unaff_EBP;
  
  FUN_10017150(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f2f6 at 1001f2f6

void Unwind_1001f2f6(void)

{
  int unaff_EBP;
  
  FUN_10016ec0(*(int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f2fe at 1001f2fe

void Unwind_1001f2fe(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f320 at 1001f320

void Unwind_1001f320(void)

{
  int unaff_EBP;
  
  FUN_10016ec0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f340 at 1001f340

void Unwind_1001f340(void)

{
  int unaff_EBP;
  
  FUN_10017270(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f360 at 1001f360

void Unwind_1001f360(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001f36b at 1001f36b

void Unwind_1001f36b(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001f376 at 1001f376

void Unwind_1001f376(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f37e at 1001f37e

void Unwind_1001f37e(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f386 at 1001f386

void Unwind_1001f386(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x1c) + 4));
  return;
}



// Function: Unwind@1001f391 at 1001f391

void Unwind_1001f391(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001f399 at 1001f399

void Unwind_1001f399(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f3b0 at 1001f3b0

void Unwind_1001f3b0(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f3bb at 1001f3bb

void Unwind_1001f3bb(void)

{
  int unaff_EBP;
  
  FUN_10017430(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f3c6 at 1001f3c6

void Unwind_1001f3c6(void)

{
  int unaff_EBP;
  
  FUN_10017270(*(int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f3ce at 1001f3ce

void Unwind_1001f3ce(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f3f0 at 1001f3f0

void Unwind_1001f3f0(void)

{
  int unaff_EBP;
  
  FUN_100175d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f3f8 at 1001f3f8

void Unwind_1001f3f8(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001f403 at 1001f403

void Unwind_1001f403(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f40b at 1001f40b

void Unwind_1001f40b(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f416 at 1001f416

void Unwind_1001f416(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f41e at 1001f41e

void Unwind_1001f41e(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f430 at 1001f430

void Unwind_1001f430(void)

{
  FUN_10017e20();
  return;
}



// Function: Unwind@1001f43b at 1001f43b

void Unwind_1001f43b(void)

{
  int unaff_EBP;
  
  FUN_100177e0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f446 at 1001f446

void Unwind_1001f446(void)

{
  int unaff_EBP;
  
  FUN_100175d0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001f44e at 1001f44e

void Unwind_1001f44e(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x1c) + 4);
  return;
}



// Function: Unwind@1001f459 at 1001f459

void Unwind_1001f459(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f461 at 1001f461

void Unwind_1001f461(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f46c at 1001f46c

void Unwind_1001f46c(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f474 at 1001f474

void Unwind_1001f474(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f47c at 1001f47c

void Unwind_1001f47c(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f4a0 at 1001f4a0

void Unwind_1001f4a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f4c0 at 1001f4c0

void Unwind_1001f4c0(void)

{
  int unaff_EBP;
  
  FUN_10016760(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f4e0 at 1001f4e0

void Unwind_1001f4e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f4e8 at 1001f4e8

void Unwind_1001f4e8(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f4f0 at 1001f4f0

void Unwind_1001f4f0(void)

{
  int unaff_EBP;
  
  FUN_1000f5c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001f4f8 at 1001f4f8

void Unwind_1001f4f8(void)

{
  int unaff_EBP;
  
  FUN_10014740((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001f503 at 1001f503

void Unwind_1001f503(void)

{
  int unaff_EBP;
  
  FUN_10014150(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001f520 at 1001f520

void Unwind_1001f520(void)

{
  FUN_100185c0(0x10030324);
  return;
}



// Function: Unwind@1001f52a at 1001f52a

void Unwind_1001f52a(void)

{
  FUN_100188e0(0x10030324);
  return;
}



// Function: Unwind@1001f540 at 1001f540

void Unwind_1001f540(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f54b at 1001f54b

void Unwind_1001f54b(void)

{
  FUN_10018770();
  return;
}



// Function: Unwind@1001f560 at 1001f560

void Unwind_1001f560(void)

{
  FUN_10018770();
  return;
}



// Function: Unwind@1001f56b at 1001f56b

void Unwind_1001f56b(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f580 at 1001f580

void Unwind_1001f580(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f5a0 at 1001f5a0

void Unwind_1001f5a0(void)

{
  int unaff_EBP;
  
  FUN_100188e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f5a8 at 1001f5a8

void Unwind_1001f5a8(void)

{
  int unaff_EBP;
  
  FUN_100185c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f5b0 at 1001f5b0

void Unwind_1001f5b0(void)

{
  FUN_10018770();
  return;
}



// Function: Unwind@1001f5bb at 1001f5bb

void Unwind_1001f5bb(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f5d0 at 1001f5d0

void Unwind_1001f5d0(void)

{
  int unaff_EBP;
  
  FUN_100185c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001f5d8 at 1001f5d8

void Unwind_1001f5d8(void)

{
  FUN_10018770();
  return;
}



// Function: Unwind@1001f5e3 at 1001f5e3

void Unwind_1001f5e3(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f600 at 1001f600

void Unwind_1001f600(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f608 at 1001f608

void Unwind_1001f608(void)

{
  int unaff_EBP;
  
  FUN_10009020((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f610 at 1001f610

void Unwind_1001f610(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f618 at 1001f618

void Unwind_1001f618(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xad0));
  return;
}



// Function: Unwind@1001f623 at 1001f623

void Unwind_1001f623(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xaec));
  return;
}



// Function: Unwind@1001f62e at 1001f62e

void Unwind_1001f62e(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f636 at 1001f636

void Unwind_1001f636(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb04));
  return;
}



// Function: Unwind@1001f641 at 1001f641

void Unwind_1001f641(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001f649 at 1001f649

void Unwind_1001f649(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f651 at 1001f651

void Unwind_1001f651(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb0c));
  return;
}



// Function: Unwind@1001f65c at 1001f65c

void Unwind_1001f65c(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f664 at 1001f664

void Unwind_1001f664(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb14));
  return;
}



// Function: Unwind@1001f66f at 1001f66f

void Unwind_1001f66f(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f677 at 1001f677

void Unwind_1001f677(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb20));
  return;
}



// Function: Unwind@1001f682 at 1001f682

void Unwind_1001f682(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xb38));
  return;
}



// Function: Unwind@1001f68d at 1001f68d

void Unwind_1001f68d(void)

{
  int unaff_EBP;
  
  FUN_1000fa30((int *)(unaff_EBP + -0xb60));
  return;
}



// Function: Unwind@1001f698 at 1001f698

void Unwind_1001f698(void)

{
  int unaff_EBP;
  
  FUN_10008a70((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001f6a0 at 1001f6a0

void Unwind_1001f6a0(void)

{
  int unaff_EBP;
  
  FUN_1000fa90(*(int **)(unaff_EBP + -0xb78));
  return;
}



// Function: Unwind@1001f6c0 at 1001f6c0

void Unwind_1001f6c0(void)

{
  FUN_100188e0(0x10030324);
  return;
}



// Function: Unwind@1001f6ca at 1001f6ca

void Unwind_1001f6ca(void)

{
  FUN_100185c0(0x10030324);
  return;
}



// Function: Unwind@1001f6d4 at 1001f6d4

void Unwind_1001f6d4(void)

{
  FUN_10018770();
  return;
}



// Function: Unwind@1001f6de at 1001f6de

void Unwind_1001f6de(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f700 at 1001f700

void Unwind_1001f700(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f720 at 1001f720

void Unwind_1001f720(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f740 at 1001f740

void Unwind_1001f740(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f760 at 1001f760

void Unwind_1001f760(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f780 at 1001f780

void Unwind_1001f780(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001f788 at 1001f788

void Unwind_1001f788(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001f790 at 1001f790

void Unwind_1001f790(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001f798 at 1001f798

void Unwind_1001f798(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001f7a0 at 1001f7a0

void Unwind_1001f7a0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001f7a8 at 1001f7a8

void Unwind_1001f7a8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001f7b0 at 1001f7b0

void Unwind_1001f7b0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001f7b8 at 1001f7b8

void Unwind_1001f7b8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001f7c0 at 1001f7c0

void Unwind_1001f7c0(void)

{
  int unaff_EBP;
  
  FUN_1001a190((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001f7c8 at 1001f7c8

void Unwind_1001f7c8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001f7d0 at 1001f7d0

void Unwind_1001f7d0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001f7d8 at 1001f7d8

void Unwind_1001f7d8(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001f7e3 at 1001f7e3

void Unwind_1001f7e3(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001f7ee at 1001f7ee

void Unwind_1001f7ee(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0xa8);
  return;
}



// Function: Unwind@1001f7f9 at 1001f7f9

void Unwind_1001f7f9(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001f801 at 1001f801

void Unwind_1001f801(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001f809 at 1001f809

void Unwind_1001f809(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001f820 at 1001f820

void Unwind_1001f820(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f840 at 1001f840

void Unwind_1001f840(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f860 at 1001f860

void Unwind_1001f860(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f880 at 1001f880

void Unwind_1001f880(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f8a0 at 1001f8a0

void Unwind_1001f8a0(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001f8a8 at 1001f8a8

void Unwind_1001f8a8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x28) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x28) = *(uint *)(unaff_EBP + -0x28) & 0xfffffffe;
    FUN_10001b10(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001f8d0 at 1001f8d0

void Unwind_1001f8d0(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001f8f0 at 1001f8f0

void Unwind_1001f8f0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f910 at 1001f910

void Unwind_1001f910(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f930 at 1001f930

void Unwind_1001f930(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f950 at 1001f950

void Unwind_1001f950(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f970 at 1001f970

void Unwind_1001f970(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f990 at 1001f990

void Unwind_1001f990(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f9b0 at 1001f9b0

void Unwind_1001f9b0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f9d0 at 1001f9d0

void Unwind_1001f9d0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001f9f0 at 1001f9f0

void Unwind_1001f9f0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fa10 at 1001fa10

void Unwind_1001fa10(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fa30 at 1001fa30

void Unwind_1001fa30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fa50 at 1001fa50

void Unwind_1001fa50(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fa70 at 1001fa70

void Unwind_1001fa70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fa90 at 1001fa90

void Unwind_1001fa90(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fab0 at 1001fab0

void Unwind_1001fab0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fad0 at 1001fad0

void Unwind_1001fad0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001faf0 at 1001faf0

void Unwind_1001faf0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fb10 at 1001fb10

void Unwind_1001fb10(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fb30 at 1001fb30

void Unwind_1001fb30(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fb50 at 1001fb50

void Unwind_1001fb50(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fb70 at 1001fb70

void Unwind_1001fb70(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001fb90 at 1001fb90

void Unwind_1001fb90(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001fb98 at 1001fb98

void Unwind_1001fb98(void)

{
  int unaff_EBP;
  
  FUN_10013b00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001fbb0 at 1001fbb0

void Unwind_1001fbb0(void)

{
  int unaff_EBP;
  
  FUN_10013b00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001fbb8 at 1001fbb8

void Unwind_1001fbb8(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001fbd0 at 1001fbd0

void Unwind_1001fbd0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001fbd8 at 1001fbd8

void Unwind_1001fbd8(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001fbe0 at 1001fbe0

void Unwind_1001fbe0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001fc00 at 1001fc00

void Unwind_1001fc00(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001fc08 at 1001fc08

void Unwind_1001fc08(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1001fc10 at 1001fc10

void Unwind_1001fc10(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001fc18 at 1001fc18

void Unwind_1001fc18(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001fc20 at 1001fc20

void Unwind_1001fc20(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001fc28 at 1001fc28

void Unwind_1001fc28(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001fc30 at 1001fc30

void Unwind_1001fc30(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001fc38 at 1001fc38

void Unwind_1001fc38(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001fc40 at 1001fc40

void Unwind_1001fc40(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001fc60 at 1001fc60

void Unwind_1001fc60(void)

{
  int unaff_EBP;
  
  FUN_1001a700(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001fc68 at 1001fc68

void Unwind_1001fc68(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001fc80 at 1001fc80

void Unwind_1001fc80(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001fc88 at 1001fc88

void Unwind_1001fc88(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001fc90 at 1001fc90

void Unwind_1001fc90(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001fc98 at 1001fc98

void Unwind_1001fc98(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001fca0 at 1001fca0

void Unwind_1001fca0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001fca8 at 1001fca8

void Unwind_1001fca8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@1001fcb3 at 1001fcb3

void Unwind_1001fcb3(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fcbb at 1001fcbb

void Unwind_1001fcbb(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001fcc3 at 1001fcc3

void Unwind_1001fcc3(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fccb at 1001fccb

void Unwind_1001fccb(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001fcd3 at 1001fcd3

void Unwind_1001fcd3(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001fcdb at 1001fcdb

void Unwind_1001fcdb(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fce3 at 1001fce3

void Unwind_1001fce3(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001fceb at 1001fceb

void Unwind_1001fceb(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1001fcf6 at 1001fcf6

void Unwind_1001fcf6(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001fd01 at 1001fd01

void Unwind_1001fd01(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001fd09 at 1001fd09

void Unwind_1001fd09(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001fd14 at 1001fd14

void Unwind_1001fd14(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001fd1c at 1001fd1c

void Unwind_1001fd1c(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001fd24 at 1001fd24

void Unwind_1001fd24(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001fd2f at 1001fd2f

void Unwind_1001fd2f(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001fd37 at 1001fd37

void Unwind_1001fd37(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x120));
  return;
}



// Function: Unwind@1001fd42 at 1001fd42

void Unwind_1001fd42(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001fd4d at 1001fd4d

void Unwind_1001fd4d(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001fd58 at 1001fd58

void Unwind_1001fd58(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001fd63 at 1001fd63

void Unwind_1001fd63(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001fd6e at 1001fd6e

void Unwind_1001fd6e(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001fd79 at 1001fd79

void Unwind_1001fd79(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001fd84 at 1001fd84

void Unwind_1001fd84(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001fd8f at 1001fd8f

void Unwind_1001fd8f(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@1001fd9a at 1001fd9a

void Unwind_1001fd9a(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@1001fda5 at 1001fda5

void Unwind_1001fda5(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001fdb0 at 1001fdb0

void Unwind_1001fdb0(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@1001fdbb at 1001fdbb

void Unwind_1001fdbb(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001fdc3 at 1001fdc3

void Unwind_1001fdc3(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001fde0 at 1001fde0

void Unwind_1001fde0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001fde8 at 1001fde8

void Unwind_1001fde8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001fdf0 at 1001fdf0

void Unwind_1001fdf0(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001fdf8 at 1001fdf8

void Unwind_1001fdf8(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001fe03 at 1001fe03

void Unwind_1001fe03(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001fe0b at 1001fe0b

void Unwind_1001fe0b(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001fe13 at 1001fe13

void Unwind_1001fe13(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001fe1b at 1001fe1b

void Unwind_1001fe1b(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001fe23 at 1001fe23

void Unwind_1001fe23(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001fe2b at 1001fe2b

void Unwind_1001fe2b(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001fe33 at 1001fe33

void Unwind_1001fe33(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1001fe3e at 1001fe3e

void Unwind_1001fe3e(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001fe49 at 1001fe49

void Unwind_1001fe49(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001fe54 at 1001fe54

void Unwind_1001fe54(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001fe5f at 1001fe5f

void Unwind_1001fe5f(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001fe6a at 1001fe6a

void Unwind_1001fe6a(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001fe72 at 1001fe72

void Unwind_1001fe72(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001fe7d at 1001fe7d

void Unwind_1001fe7d(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001fea0 at 1001fea0

void Unwind_1001fea0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001fea8 at 1001fea8

void Unwind_1001fea8(void)

{
  int unaff_EBP;
  
  FUN_10001b50(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001feb0 at 1001feb0

void Unwind_1001feb0(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001febb at 1001febb

void Unwind_1001febb(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fec3 at 1001fec3

void Unwind_1001fec3(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001fecb at 1001fecb

void Unwind_1001fecb(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fed3 at 1001fed3

void Unwind_1001fed3(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001fedb at 1001fedb

void Unwind_1001fedb(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001fee3 at 1001fee3

void Unwind_1001fee3(void)

{
  int unaff_EBP;
  
  FUN_10001b10(*(undefined4 **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001feeb at 1001feeb

void Unwind_1001feeb(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1001fef6 at 1001fef6

void Unwind_1001fef6(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001ff01 at 1001ff01

void Unwind_1001ff01(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001ff0c at 1001ff0c

void Unwind_1001ff0c(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001ff17 at 1001ff17

void Unwind_1001ff17(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001ff1f at 1001ff1f

void Unwind_1001ff1f(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001ff27 at 1001ff27

void Unwind_1001ff27(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001ff32 at 1001ff32

void Unwind_1001ff32(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001ff3d at 1001ff3d

void Unwind_1001ff3d(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@1001ff48 at 1001ff48

void Unwind_1001ff48(void)

{
  int unaff_EBP;
  
  FUN_1001a700((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1001ff53 at 1001ff53

void Unwind_1001ff53(void)

{
  int unaff_EBP;
  
  FUN_10001b10((undefined4 *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001ff5e at 1001ff5e

void Unwind_1001ff5e(void)

{
  int unaff_EBP;
  
  FUN_1001a760((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1001ff80 at 1001ff80

void Unwind_1001ff80(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ffa0 at 1001ffa0

void Unwind_1001ffa0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ffc0 at 1001ffc0

void Unwind_1001ffc0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@1001ffe0 at 1001ffe0

void Unwind_1001ffe0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020000 at 10020000

void Unwind_10020000(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020020 at 10020020

void Unwind_10020020(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020040 at 10020040

void Unwind_10020040(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020060 at 10020060

void Unwind_10020060(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020080 at 10020080

void Unwind_10020080(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100200a0 at 100200a0

void Unwind_100200a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100200c0 at 100200c0

void Unwind_100200c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100200e0 at 100200e0

void Unwind_100200e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020100 at 10020100

void Unwind_10020100(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020120 at 10020120

void Unwind_10020120(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020140 at 10020140

void Unwind_10020140(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020160 at 10020160

void Unwind_10020160(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020180 at 10020180

void Unwind_10020180(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100201a0 at 100201a0

void Unwind_100201a0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100201c0 at 100201c0

void Unwind_100201c0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@100201e0 at 100201e0

void Unwind_100201e0(void)

{
  FUN_1000f7d0();
  return;
}



// Function: Unwind@10020200 at 10020200

void Unwind_10020200(void)

{
  FUN_1000f7d0();
  return;
}



// Function: FUN_10020220 at 10020220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020220(void)

{
  FUN_10004960(&DAT_1002fcd4,L"\r");
  _atexit(FUN_100228b0);
  return;
}



// Function: FUN_10020270 at 10020270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020270(void)

{
  FUN_10004960(&DAT_1002fcf0,L"\n");
  _atexit(FUN_10022910);
  return;
}



// Function: FUN_100202c0 at 100202c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100202c0(void)

{
  FUN_10004960(&DAT_1002fd0c,L"\\n");
  _atexit(FUN_10022970);
  return;
}



// Function: FUN_10020310 at 10020310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020310(void)

{
  FUN_10004960(&DAT_1002fd28,L"\\r");
  _atexit(FUN_100229d0);
  return;
}



// Function: FUN_10020360 at 10020360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020360(void)

{
  FUN_10004960(&DAT_1002fd44,L"\r");
  _atexit(FUN_10022a30);
  return;
}



// Function: FUN_100203b0 at 100203b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100203b0(void)

{
  FUN_10004960(&DAT_1002fd60,L"\n");
  _atexit(FUN_10022a90);
  return;
}



// Function: FUN_10020400 at 10020400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020400(void)

{
  FUN_10004960(&DAT_1002fd7c,L"\\n");
  _atexit(FUN_10022af0);
  return;
}



// Function: FUN_10020450 at 10020450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020450(void)

{
  FUN_10004960(&DAT_1002fd98,L"\\r");
  _atexit(FUN_10022b50);
  return;
}



// Function: FUN_100204a0 at 100204a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100204a0(void)

{
  FUN_10004960(&DAT_1002fdb4,L"\r");
  _atexit(FUN_10022bb0);
  return;
}



// Function: FUN_100204f0 at 100204f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100204f0(void)

{
  FUN_10004960(&DAT_1002fdd0,L"\n");
  _atexit(FUN_10022c10);
  return;
}



// Function: FUN_10020540 at 10020540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020540(void)

{
  FUN_10004960(&DAT_1002fdec,L"\\n");
  _atexit(FUN_10022c70);
  return;
}



// Function: FUN_10020590 at 10020590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020590(void)

{
  FUN_10004960(&DAT_1002fe08,L"\\r");
  _atexit(FUN_10022cd0);
  return;
}



// Function: FUN_100205e0 at 100205e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100205e0(void)

{
  FUN_10004960(&DAT_1002fe24,L"EN");
  _atexit(FUN_10022d30);
  return;
}



// Function: FUN_10020630 at 10020630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020630(void)

{
  FUN_10004960(&DAT_1002fe40,L"ES");
  _atexit(FUN_10022d90);
  return;
}



// Function: FUN_10020680 at 10020680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020680(void)

{
  FUN_10004960(&DAT_1002fe5c,L"PT");
  _atexit(FUN_10022df0);
  return;
}



// Function: FUN_100206d0 at 100206d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100206d0(void)

{
  FUN_10004960(&DAT_1002fe78,L"TR");
  _atexit(FUN_10022e50);
  return;
}



// Function: FUN_10020720 at 10020720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020720(void)

{
  FUN_10004960(&DAT_1002fe94,L"ZH");
  _atexit(FUN_10022eb0);
  return;
}



// Function: FUN_10020770 at 10020770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020770(void)

{
  FUN_10004960(&DAT_1002feb0,L"JA");
  _atexit(FUN_10022f10);
  return;
}



// Function: FUN_100207c0 at 100207c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100207c0(void)

{
  FUN_10004960(&DAT_1002fecc,L"FR");
  _atexit(FUN_10022f70);
  return;
}



// Function: FUN_10020810 at 10020810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020810(void)

{
  FUN_10004960(&DAT_1002fee8,L"DE");
  _atexit(FUN_10022fd0);
  return;
}



// Function: FUN_10020860 at 10020860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020860(void)

{
  FUN_10004960(&DAT_1002ff04,L"IT");
  _atexit(FUN_10023030);
  return;
}



// Function: FUN_100208b0 at 100208b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100208b0(void)

{
  FUN_10004960(&DAT_1002ff20,L"KO");
  _atexit(FUN_10023090);
  return;
}



// Function: FUN_10020900 at 10020900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020900(void)

{
  FUN_10004960(&DAT_1002ff3c,L"RU");
  _atexit(FUN_100230f0);
  return;
}



// Function: FUN_10020950 at 10020950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020950(void)

{
  FUN_10004960(&DAT_1002ff58,L"DA");
  _atexit(FUN_10023150);
  return;
}



// Function: FUN_100209a0 at 100209a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100209a0(void)

{
  FUN_10004960(&DAT_1002ff74,L"NL");
  _atexit(FUN_100231b0);
  return;
}



// Function: FUN_100209f0 at 100209f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100209f0(void)

{
  FUN_10004960(&DAT_1002ff90,L"FI");
  _atexit(FUN_10023210);
  return;
}



// Function: FUN_10020a40 at 10020a40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020a40(void)

{
  FUN_10004960(&DAT_1002ffac,L"NO");
  _atexit(FUN_10023270);
  return;
}



// Function: FUN_10020a90 at 10020a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020a90(void)

{
  FUN_10004960(&DAT_1002ffc8,L"SV");
  _atexit(FUN_100232d0);
  return;
}



// Function: FUN_10020ae0 at 10020ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020ae0(void)

{
  FUN_10004960(&DAT_1002ffe4,L"ID");
  _atexit(FUN_10023330);
  return;
}



// Function: FUN_10020b30 at 10020b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10020b3d) */

void FUN_10020b30(void)

{
  DAT_10030000 = Ordinal_2(&DAT_10026754);
  if (DAT_10030000 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10023390);
  return;
}



// Function: FUN_10020ba0 at 10020ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10020bad) */

void FUN_10020ba0(void)

{
  DAT_10030004 = Ordinal_2(&DAT_1002675c);
  if (DAT_10030004 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_100233c0);
  return;
}



// Function: FUN_10020c10 at 10020c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10020c1d) */

void FUN_10020c10(void)

{
  DAT_10030008 = Ordinal_2(&DAT_10026764);
  if (DAT_10030008 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_100233f0);
  return;
}



// Function: FUN_10020c80 at 10020c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020c80(void)

{
  FUN_10004960(&DAT_1003000c,L"\r");
  _atexit(FUN_10023420);
  return;
}



// Function: FUN_10020cd0 at 10020cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020cd0(void)

{
  FUN_10004960(&DAT_10030028,L"\n");
  _atexit(FUN_10023480);
  return;
}



// Function: FUN_10020d20 at 10020d20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020d20(void)

{
  FUN_10004960(&DAT_10030044,L"\\n");
  _atexit(FUN_100234e0);
  return;
}



// Function: FUN_10020d70 at 10020d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020d70(void)

{
  FUN_10004960(&DAT_10030060,L"\\r");
  _atexit(FUN_10023540);
  return;
}



// Function: FUN_10020dc0 at 10020dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020dc0(void)

{
  FUN_10004960(&DAT_1003007c,L"EN");
  _atexit(FUN_100235a0);
  return;
}



// Function: FUN_10020e10 at 10020e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020e10(void)

{
  FUN_10004960(&DAT_10030098,L"ES");
  _atexit(FUN_10023600);
  return;
}



// Function: FUN_10020e60 at 10020e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020e60(void)

{
  FUN_10004960(&DAT_100300b4,L"PT");
  _atexit(FUN_10023660);
  return;
}



// Function: FUN_10020eb0 at 10020eb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020eb0(void)

{
  FUN_10004960(&DAT_100300d0,L"TR");
  _atexit(FUN_100236c0);
  return;
}



// Function: FUN_10020f00 at 10020f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020f00(void)

{
  FUN_10004960(&DAT_100300ec,L"ZH");
  _atexit(FUN_10023720);
  return;
}



// Function: FUN_10020f50 at 10020f50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020f50(void)

{
  FUN_10004960(&DAT_10030108,L"JA");
  _atexit(FUN_10023780);
  return;
}



// Function: FUN_10020fa0 at 10020fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020fa0(void)

{
  FUN_10004960(&DAT_10030124,L"FR");
  _atexit(FUN_100237e0);
  return;
}



// Function: FUN_10020ff0 at 10020ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020ff0(void)

{
  FUN_10004960(&DAT_10030140,L"DE");
  _atexit(FUN_10023840);
  return;
}



// Function: FUN_10021040 at 10021040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021040(void)

{
  FUN_10004960(&DAT_1003015c,L"IT");
  _atexit(FUN_100238a0);
  return;
}



// Function: FUN_10021090 at 10021090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021090(void)

{
  FUN_10004960(&DAT_10030178,L"KO");
  _atexit(FUN_10023900);
  return;
}



// Function: FUN_100210e0 at 100210e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100210e0(void)

{
  FUN_10004960(&DAT_10030194,L"RU");
  _atexit(FUN_10023960);
  return;
}



// Function: FUN_10021130 at 10021130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021130(void)

{
  FUN_10004960(&DAT_100301b0,L"DA");
  _atexit(FUN_100239c0);
  return;
}



// Function: FUN_10021180 at 10021180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021180(void)

{
  FUN_10004960(&DAT_100301cc,L"NL");
  _atexit(FUN_10023a20);
  return;
}



// Function: FUN_100211d0 at 100211d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100211d0(void)

{
  FUN_10004960(&DAT_100301e8,L"FI");
  _atexit(FUN_10023a80);
  return;
}



// Function: FUN_10021220 at 10021220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021220(void)

{
  FUN_10004960(&DAT_10030204,L"NO");
  _atexit(FUN_10023ae0);
  return;
}



// Function: FUN_10021270 at 10021270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021270(void)

{
  FUN_10004960(&DAT_10030220,L"SV");
  _atexit(FUN_10023b40);
  return;
}



// Function: FUN_100212c0 at 100212c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100212c0(void)

{
  FUN_10004960(&DAT_1003023c,L"ID");
  _atexit(FUN_10023ba0);
  return;
}



// Function: FUN_10021310 at 10021310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002131d) */

void FUN_10021310(void)

{
  DAT_10030258 = Ordinal_2(&DAT_10026754);
  if (DAT_10030258 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10023c00);
  return;
}



// Function: FUN_10021380 at 10021380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002138d) */

void FUN_10021380(void)

{
  DAT_1003025c = Ordinal_2(&DAT_1002675c);
  if (DAT_1003025c == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10023c30);
  return;
}



// Function: FUN_100213f0 at 100213f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100213fd) */

void FUN_100213f0(void)

{
  DAT_10030260 = Ordinal_2(&DAT_10026764);
  if (DAT_10030260 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10023c60);
  return;
}



// Function: FUN_10021460 at 10021460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021460(void)

{
  FUN_10004960(&DAT_10030264,L"\r");
  _atexit(FUN_10023c90);
  return;
}



// Function: FUN_100214b0 at 100214b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100214b0(void)

{
  FUN_10004960(&DAT_10030280,L"\n");
  _atexit(FUN_10023cf0);
  return;
}



// Function: FUN_10021500 at 10021500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021500(void)

{
  FUN_10004960(&DAT_1003029c,L"\\n");
  _atexit(FUN_10023d50);
  return;
}



// Function: FUN_10021550 at 10021550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021550(void)

{
  FUN_10004960(&DAT_100302b8,L"\\r");
  _atexit(FUN_10023db0);
  return;
}



// Function: FUN_100215a0 at 100215a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100215a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f534;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100184e0(0x10030324);
  _DAT_10030324 = ATL::CComModule::vftable;
  _DAT_100302f4 = &DAT_10030324;
  local_8 = 0xffffffff;
  _atexit(FUN_10023e10);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021630 at 10021630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021630(void)

{
  FUN_10004960(&DAT_10030354,L"\r");
  _atexit(FUN_10023e80);
  return;
}



// Function: FUN_10021680 at 10021680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021680(void)

{
  FUN_10004960(&DAT_10030370,L"\n");
  _atexit(FUN_10023ee0);
  return;
}



// Function: FUN_100216d0 at 100216d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100216d0(void)

{
  FUN_10004960(&DAT_1003038c,L"\\n");
  _atexit(FUN_10023f40);
  return;
}



// Function: FUN_10021720 at 10021720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021720(void)

{
  FUN_10004960(&DAT_100303a8,L"\\r");
  _atexit(FUN_10023fa0);
  return;
}



// Function: FUN_10021770 at 10021770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021770(void)

{
  FUN_10004960(&DAT_100303c4,L"\r");
  _atexit(FUN_10024000);
  return;
}



// Function: FUN_100217c0 at 100217c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100217c0(void)

{
  FUN_10004960(&DAT_100303e0,L"\n");
  _atexit(FUN_10024060);
  return;
}



// Function: FUN_10021810 at 10021810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021810(void)

{
  FUN_10004960(&DAT_100303fc,L"\\n");
  _atexit(FUN_100240c0);
  return;
}



// Function: FUN_10021860 at 10021860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021860(void)

{
  FUN_10004960(&DAT_10030418,L"\\r");
  _atexit(FUN_10024120);
  return;
}



// Function: FUN_100218b0 at 100218b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100218b0(void)

{
  FUN_10004960(&DAT_1003046c,L"\r");
  _atexit(FUN_10024180);
  return;
}



// Function: FUN_10021900 at 10021900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021900(void)

{
  FUN_10004960(&DAT_10030450,L"\n");
  _atexit(FUN_100241e0);
  return;
}



// Function: FUN_10021950 at 10021950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021950(void)

{
  FUN_10004960(&DAT_10030434,L"\\n");
  _atexit(FUN_10024240);
  return;
}



// Function: FUN_100219a0 at 100219a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100219a0(void)

{
  FUN_10004960(&DAT_100305f8,L"\\r");
  _atexit(FUN_100242a0);
  return;
}



// Function: FUN_100219f0 at 100219f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100219f0(void)

{
  FUN_10004960(&DAT_1003054c,L"EN");
  _atexit(FUN_10024300);
  return;
}



// Function: FUN_10021a40 at 10021a40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021a40(void)

{
  FUN_10004960(&DAT_1003064c,L"ES");
  _atexit(FUN_10024360);
  return;
}



// Function: FUN_10021a90 at 10021a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021a90(void)

{
  FUN_10004960(&DAT_10030488,L"PT");
  _atexit(FUN_100243c0);
  return;
}



// Function: FUN_10021ae0 at 10021ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ae0(void)

{
  FUN_10004960(&DAT_100305a4,L"TR");
  _atexit(FUN_10024420);
  return;
}



// Function: FUN_10021b30 at 10021b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021b30(void)

{
  FUN_10004960(&DAT_10030614,L"ZH");
  _atexit(FUN_10024480);
  return;
}



// Function: FUN_10021b80 at 10021b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021b80(void)

{
  FUN_10004960(&DAT_100305dc,L"JA");
  _atexit(FUN_100244e0);
  return;
}



// Function: FUN_10021bd0 at 10021bd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021bd0(void)

{
  FUN_10004960(&DAT_10030630,L"FR");
  _atexit(FUN_10024540);
  return;
}



// Function: FUN_10021c20 at 10021c20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021c20(void)

{
  FUN_10004960(&DAT_1003056c,L"DE");
  _atexit(FUN_100245a0);
  return;
}



// Function: FUN_10021c70 at 10021c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021c70(void)

{
  FUN_10004960(&DAT_10030530,L"IT");
  _atexit(FUN_10024600);
  return;
}



// Function: FUN_10021cc0 at 10021cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021cc0(void)

{
  FUN_10004960(&DAT_100304a4,L"KO");
  _atexit(FUN_10024660);
  return;
}



// Function: FUN_10021d10 at 10021d10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021d10(void)

{
  FUN_10004960(&DAT_10030588,L"RU");
  _atexit(FUN_100246c0);
  return;
}



// Function: FUN_10021d60 at 10021d60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021d60(void)

{
  FUN_10004960(&DAT_100304c0,L"DA");
  _atexit(FUN_10024720);
  return;
}



// Function: FUN_10021db0 at 10021db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021db0(void)

{
  FUN_10004960(&DAT_100304f8,L"NL");
  _atexit(FUN_10024780);
  return;
}



// Function: FUN_10021e00 at 10021e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021e00(void)

{
  FUN_10004960(&DAT_100305c0,L"FI");
  _atexit(FUN_100247e0);
  return;
}



// Function: FUN_10021e50 at 10021e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021e50(void)

{
  FUN_10004960(&DAT_10030668,L"NO");
  _atexit(FUN_10024840);
  return;
}



// Function: FUN_10021ea0 at 10021ea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ea0(void)

{
  FUN_10004960(&DAT_100304dc,L"SV");
  _atexit(FUN_100248a0);
  return;
}



// Function: FUN_10021ef0 at 10021ef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ef0(void)

{
  FUN_10004960(&DAT_10030514,L"ID");
  _atexit(FUN_10024900);
  return;
}



// Function: FUN_10021f40 at 10021f40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10021f4d) */

void FUN_10021f40(void)

{
  DAT_10030568 = Ordinal_2(&DAT_10026754);
  if (DAT_10030568 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10024960);
  return;
}



// Function: FUN_10021fb0 at 10021fb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10021fbd) */

void FUN_10021fb0(void)

{
  DAT_10030684 = Ordinal_2(&DAT_1002675c);
  if (DAT_10030684 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10024990);
  return;
}



// Function: FUN_10022020 at 10022020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002202d) */

void FUN_10022020(void)

{
  DAT_10030688 = Ordinal_2(&DAT_10026764);
  if (DAT_10030688 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_100249c0);
  return;
}



// Function: FUN_10022090 at 10022090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022090(void)

{
  FUN_10004960(&DAT_1003068c,L"\r");
  _atexit(FUN_100249f0);
  return;
}



// Function: FUN_100220e0 at 100220e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100220e0(void)

{
  FUN_10004960(&DAT_100306a8,L"\n");
  _atexit(FUN_10024a50);
  return;
}



// Function: FUN_10022130 at 10022130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022130(void)

{
  FUN_10004960(&DAT_100306c4,L"\\n");
  _atexit(FUN_10024ab0);
  return;
}



// Function: FUN_10022180 at 10022180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022180(void)

{
  FUN_10004960(&DAT_100306e0,L"\\r");
  _atexit(FUN_10024b10);
  return;
}



// Function: FUN_100221d0 at 100221d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100221d0(void)

{
  FUN_10004960(&DAT_100306fc,L"EN");
  _atexit(FUN_10024b70);
  return;
}



// Function: FUN_10022220 at 10022220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022220(void)

{
  FUN_10004960(&DAT_10030718,L"ES");
  _atexit(FUN_10024bd0);
  return;
}



// Function: FUN_10022270 at 10022270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022270(void)

{
  FUN_10004960(&DAT_10030734,L"PT");
  _atexit(FUN_10024c30);
  return;
}



// Function: FUN_100222c0 at 100222c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100222c0(void)

{
  FUN_10004960(&DAT_10030750,L"TR");
  _atexit(FUN_10024c90);
  return;
}



// Function: FUN_10022310 at 10022310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022310(void)

{
  FUN_10004960(&DAT_1003076c,L"ZH");
  _atexit(FUN_10024cf0);
  return;
}



// Function: FUN_10022360 at 10022360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022360(void)

{
  FUN_10004960(&DAT_10030788,L"JA");
  _atexit(FUN_10024d50);
  return;
}



// Function: FUN_100223b0 at 100223b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100223b0(void)

{
  FUN_10004960(&DAT_100307a4,L"FR");
  _atexit(FUN_10024db0);
  return;
}



// Function: FUN_10022400 at 10022400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022400(void)

{
  FUN_10004960(&DAT_100307c0,L"DE");
  _atexit(FUN_10024e10);
  return;
}



// Function: FUN_10022450 at 10022450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022450(void)

{
  FUN_10004960(&DAT_100307dc,L"IT");
  _atexit(FUN_10024e70);
  return;
}



// Function: FUN_100224a0 at 100224a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100224a0(void)

{
  FUN_10004960(&DAT_100307f8,L"KO");
  _atexit(FUN_10024ed0);
  return;
}



// Function: FUN_100224f0 at 100224f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100224f0(void)

{
  FUN_10004960(&DAT_10030814,L"RU");
  _atexit(FUN_10024f30);
  return;
}



// Function: FUN_10022540 at 10022540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022540(void)

{
  FUN_10004960(&DAT_10030830,L"DA");
  _atexit(FUN_10024f90);
  return;
}



// Function: FUN_10022590 at 10022590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022590(void)

{
  FUN_10004960(&DAT_1003084c,L"NL");
  _atexit(FUN_10024ff0);
  return;
}



// Function: FUN_100225e0 at 100225e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100225e0(void)

{
  FUN_10004960(&DAT_10030868,L"FI");
  _atexit(FUN_10025050);
  return;
}



// Function: FUN_10022630 at 10022630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022630(void)

{
  FUN_10004960(&DAT_10030884,L"NO");
  _atexit(FUN_100250b0);
  return;
}



// Function: FUN_10022680 at 10022680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022680(void)

{
  FUN_10004960(&DAT_100308a0,L"SV");
  _atexit(FUN_10025110);
  return;
}



// Function: FUN_100226d0 at 100226d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100226d0(void)

{
  FUN_10004960(&DAT_100308bc,L"ID");
  _atexit(FUN_10025170);
  return;
}



// Function: FUN_10022720 at 10022720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002272d) */

void FUN_10022720(void)

{
  DAT_100308d8 = Ordinal_2(&DAT_10026754);
  if (DAT_100308d8 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_100251d0);
  return;
}



// Function: FUN_10022790 at 10022790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002279d) */

void FUN_10022790(void)

{
  DAT_100308dc = Ordinal_2(&DAT_1002675c);
  if (DAT_100308dc == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10025200);
  return;
}



// Function: FUN_10022800 at 10022800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1002280d) */

void FUN_10022800(void)

{
  DAT_100308e0 = Ordinal_2(&DAT_10026764);
  if (DAT_100308e0 == 0) {
    FUN_10001920(0x8007000e);
  }
  _atexit(FUN_10025230);
  return;
}



// Function: FUN_100228b0 at 100228b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100228b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d77a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fcd4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022910 at 10022910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022910(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d79a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fcf0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022970 at 10022970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022970(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd0c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100229d0 at 100229d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100229d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd28,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022a30 at 10022a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022a30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d92a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd44,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022a90 at 10022a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022a90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d94a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd60,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022af0 at 10022af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022af0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d96a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd7c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022b50 at 10022b50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022b50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d98a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fd98,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022bb0 at 10022bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022bb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001db7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fdb4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022c10 at 10022c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022c10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001db9a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fdd0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022c70 at 10022c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022c70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dbba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fdec,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022cd0 at 10022cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022cd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dbda;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe08,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022d30 at 10022d30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022d30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dbfa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe24,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022d90 at 10022d90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022d90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe40,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022df0 at 10022df0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022df0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe5c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022e50 at 10022e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022e50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe78,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022eb0 at 10022eb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022eb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fe94,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022f10 at 10022f10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022f10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc9a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002feb0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022f70 at 10022f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022f70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dcba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fecc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022fd0 at 10022fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022fd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dcda;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002fee8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023030 at 10023030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023030(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dcfa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff04,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023090 at 10023090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023090(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff20,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100230f0 at 100230f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100230f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff3c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023150 at 10023150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023150(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff58,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100231b0 at 100231b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100231b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff74,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023210 at 10023210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023210(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd9a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ff90,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023270 at 10023270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023270(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ddba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ffac,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100232d0 at 100232d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100232d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ddda;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ffc8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023330 at 10023330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023330(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ddfa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1002ffe4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023390 at 10023390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023390(void)

{
  Ordinal_6(DAT_10030000);
  return;
}



// Function: FUN_100233c0 at 100233c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100233c0(void)

{
  Ordinal_6(DAT_10030004);
  return;
}



// Function: FUN_100233f0 at 100233f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100233f0(void)

{
  Ordinal_6(DAT_10030008);
  return;
}



// Function: FUN_10023420 at 10023420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023420(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e02a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003000c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023480 at 10023480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023480(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e04a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030028,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100234e0 at 100234e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100234e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e06a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030044,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023540 at 10023540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023540(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e08a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030060,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100235a0 at 100235a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100235a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003007c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023600 at 10023600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023600(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030098,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023660 at 10023660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023660(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100300b4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100236c0 at 100236c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100236c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e10a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100300d0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023720 at 10023720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023720(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e12a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100300ec,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023780 at 10023780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023780(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e14a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030108,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100237e0 at 100237e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100237e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e16a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030124,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023840 at 10023840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023840(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e18a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030140,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100238a0 at 100238a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100238a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e1aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003015c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023900 at 10023900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023900(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e1ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030178,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023960 at 10023960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023960(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e1ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030194,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100239c0 at 100239c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100239c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e20a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100301b0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023a20 at 10023a20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023a20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e22a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100301cc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023a80 at 10023a80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023a80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e24a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100301e8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023ae0 at 10023ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023ae0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e26a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030204,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023b40 at 10023b40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023b40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e28a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030220,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023ba0 at 10023ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023ba0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e2aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003023c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023c00 at 10023c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023c00(void)

{
  Ordinal_6(DAT_10030258);
  return;
}



// Function: FUN_10023c30 at 10023c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023c30(void)

{
  Ordinal_6(DAT_1003025c);
  return;
}



// Function: FUN_10023c60 at 10023c60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023c60(void)

{
  Ordinal_6(DAT_10030260);
  return;
}



// Function: FUN_10023c90 at 10023c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023c90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e3ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030264,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023cf0 at 10023cf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023cf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e3ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030280,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023d50 at 10023d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023d50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e40a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003029c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023db0 at 10023db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023db0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e42a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100302b8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023e10 at 10023e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023e10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f6e8;
  local_10 = ExceptionList;
  _DAT_10030324 = ATL::CComModule::vftable;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_1000cea0(0x10030324);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023e80 at 10023e80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023e80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f70a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030354,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023ee0 at 10023ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023ee0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f72a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030370,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023f40 at 10023f40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023f40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f74a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003038c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10023fa0 at 10023fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10023fa0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f76a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100303a8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024000 at 10024000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024000(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f82a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100303c4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024060 at 10024060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024060(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f84a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100303e0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100240c0 at 100240c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100240c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f86a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100303fc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024120 at 10024120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024120(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f88a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030418,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024180 at 10024180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024180(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f8fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003046c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100241e0 at 100241e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100241e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f91a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030450,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024240 at 10024240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024240(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f93a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030434,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100242a0 at 100242a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100242a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f95a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100305f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024300 at 10024300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024300(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f97a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003054c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024360 at 10024360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024360(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f99a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003064c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100243c0 at 100243c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100243c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f9ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030488,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024420 at 10024420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024420(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f9da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100305a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024480 at 10024480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024480(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f9fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030614,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100244e0 at 100244e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100244e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fa1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100305dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024540 at 10024540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024540(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fa3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030630,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100245a0 at 100245a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100245a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fa5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003056c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024600 at 10024600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024600(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fa7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030530,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024660 at 10024660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024660(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fa9a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100304a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100246c0 at 100246c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100246c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001faba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030588,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024720 at 10024720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024720(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fada;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100304c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024780 at 10024780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024780(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fafa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100304f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100247e0 at 100247e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100247e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fb1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100305c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024840 at 10024840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024840(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fb3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030668,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100248a0 at 100248a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100248a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fb5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100304dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024900 at 10024900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024900(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001fb7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030514,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024960 at 10024960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024960(void)

{
  Ordinal_6(DAT_10030568);
  return;
}



// Function: FUN_10024990 at 10024990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024990(void)

{
  Ordinal_6(DAT_10030684);
  return;
}



// Function: FUN_100249c0 at 100249c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100249c0(void)

{
  Ordinal_6(DAT_10030688);
  return;
}



// Function: FUN_100249f0 at 100249f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100249f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ff8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003068c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024a50 at 10024a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024a50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ffaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100306a8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024ab0 at 10024ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024ab0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ffca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100306c4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024b10 at 10024b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024b10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ffea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100306e0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024b70 at 10024b70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024b70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002000a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100306fc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024bd0 at 10024bd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024bd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002002a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030718,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024c30 at 10024c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024c30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002004a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030734,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024c90 at 10024c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024c90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002006a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030750,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024cf0 at 10024cf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024cf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002008a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003076c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024d50 at 10024d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024d50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100200aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030788,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024db0 at 10024db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024db0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100200ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100307a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024e10 at 10024e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024e10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100200ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100307c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024e70 at 10024e70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024e70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002010a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100307dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024ed0 at 10024ed0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024ed0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002012a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100307f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024f30 at 10024f30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024f30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002014a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030814,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024f90 at 10024f90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024f90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002016a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030830,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024ff0 at 10024ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10024ff0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002018a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_1003084c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025050 at 10025050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10025050(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100201aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030868,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100250b0 at 100250b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100250b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100201ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_10030884,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025110 at 10025110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10025110(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100201ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100308a0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025170 at 10025170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10025170(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002020a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003930(&DAT_100308bc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100251d0 at 100251d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100251d0(void)

{
  Ordinal_6(DAT_100308d8);
  return;
}



// Function: FUN_10025200 at 10025200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10025200(void)

{
  Ordinal_6(DAT_100308dc);
  return;
}



// Function: FUN_10025230 at 10025230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10025230(void)

{
  Ordinal_6(DAT_100308e0);
  return;
}



// Function: FUN_10025253 at 10025253

void FUN_10025253(void)

{
  FUN_1001bd89(0x100308e4);
  return;
}



// Function: FUN_1002525d at 1002525d

void FUN_1002525d(void)

{
  FUN_1001be3e((int *)&DAT_1003091c);
  return;
}



// Function: FUN_10025267 at 10025267

void FUN_10025267(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_10030944,DAT_100308e8);
  RemoveAll((undefined4 *)&DAT_10030964);
  return;
}



