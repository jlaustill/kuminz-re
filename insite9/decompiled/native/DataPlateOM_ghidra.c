/*
 * Decompiled from: DataPlateOM.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10001000(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [6];
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019759;
  local_10 = ExceptionList;
  puVar2 = local_44;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = (undefined4 *)(param_1 + 4);
  ExceptionList = &local_10;
  *local_1c = 0;
  local_8 = 0;
  local_18 = (void *)(param_1 + 8);
  local_14 = param_1;
  memset(local_18,0,0x18);
  *(undefined1 *)((int)local_18 + 0x18) = 0;
  local_20 = (undefined4 *)(local_14 + 0x24);
  *local_20 = 0;
  local_24 = (undefined4 *)(local_14 + 0x28);
  *local_24 = 0;
  local_28 = (undefined4 *)(local_14 + 0x2c);
  *local_28 = 0;
  local_2c = (undefined4 *)(local_14 + 0x30);
  *local_2c = 0;
  local_8 = 0xc;
  FUN_100030c0((undefined4 *)(local_14 + 0x34));
  *(undefined4 *)(local_14 + 0x80) = 0;
  *(undefined4 *)(local_14 + 0x84) = 0;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10001150 at 10001150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001150(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a448;
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



// Function: ~CPreserveLastError at 100011d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CPreserveLastError::~CPreserveLastError(void)
   
   Library: Visual Studio 2015 Debug */

void __thiscall ATL::CPreserveLastError::~CPreserveLastError(CPreserveLastError *this)

{
  Ordinal_6(*(undefined4 *)this);
  return;
}



// Function: FUN_10001210 at 10001210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001210(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_40;
  LPCRITICAL_SECTION local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019819;
  local_10 = ExceptionList;
  piVar2 = &local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  local_8._0_1_ = 6;
  local_8._1_3_ = 0;
  ExceptionList = &local_10;
  local_14 = param_1;
  Ordinal_6(*(undefined4 *)(param_1 + 0x84));
  uVar3 = 0x10001265;
  local_18 = (int *)(local_14 + 0x80);
  local_8._0_1_ = 5;
  if (*local_18 != 0) {
    (**(code **)(*(int *)*local_18 + 8))(*local_18,0x10001265);
    uVar3 = 0x100012a0;
  }
  local_8._0_1_ = 4;
  FUN_10003210((undefined4 *)(local_14 + 0x34));
  local_2c = (int *)(local_14 + 0x30);
  local_8._0_1_ = 3;
  if (*local_2c != 0) {
    (**(code **)(*(int *)*local_2c + 8))(*local_2c,uVar3);
    uVar3 = 0x100012e7;
  }
  local_30 = (int *)(local_14 + 0x2c);
  local_8._0_1_ = 2;
  if (*local_30 != 0) {
    (**(code **)(*(int *)*local_30 + 8))(*local_30,uVar3);
    uVar3 = 0x1000131f;
  }
  local_34 = (int *)(local_14 + 0x28);
  local_8._0_1_ = 1;
  if (*local_34 != 0) {
    (**(code **)(*(int *)*local_34 + 8))(*local_34,uVar3);
    uVar3 = 0x10001357;
  }
  local_38 = (int *)(local_14 + 0x24);
  local_8 = (uint)local_8._1_3_ << 8;
  if (*local_38 != 0) {
    (**(code **)(*(int *)*local_38 + 8))(*local_38,uVar3);
  }
  local_40 = local_14 + 4;
  local_3c = (LPCRITICAL_SECTION)(local_14 + 8);
  local_8 = 0x10;
  if (*(char *)(local_14 + 0x20) != '\0') {
    *(undefined1 *)(local_14 + 0x20) = 0;
    DeleteCriticalSection(local_3c);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001410 at 10001410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001410(int param_1)

{
  CoCreateInstance((IID *)&DAT_100239e0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10023680,
                   (LPVOID *)(param_1 + 0x30));
  return;
}



// Function: FUN_10001460 at 10001460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10001610) */
/* WARNING: Removing unreachable block (ram,0x10001634) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10001460(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_fc [4];
  int *local_ec;
  int *local_e8;
  undefined4 *local_e4;
  int *local_e0;
  int *local_dc;
  int *local_d8;
  int *local_d4;
  undefined4 *local_cc;
  wchar_t *local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined4 local_bc;
  int *local_b0;
  undefined1 local_ac [28];
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_78;
  wchar_t *local_6c [3];
  int *local_60 [2];
  int local_58;
  int local_54 [2];
  int *local_4c [3];
  int *local_40 [3];
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100198ea;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_fc;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffef8;
  FUN_10004880(local_28);
  local_34[0] = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  local_d8 = *(int **)(param_1 + 0x28);
  local_bc = *(undefined4 *)(param_1 + 0x84);
  uVar1 = (**(code **)(*local_d8 + 0x30))(local_d8,local_bc,3,local_34);
  uVar5 = 0x1000150a;
  FUN_10004900(local_28,uVar1);
  local_c0 = local_34[0];
  FUN_10003b50(local_40);
  local_8._0_1_ = 4;
  if (local_c0 != (int *)0x0) {
    (**(code **)*local_c0)(local_c0,&DAT_10023690,local_40,uVar5);
    uVar5 = 0x10001556;
  }
  local_4c[0] = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,7);
  local_dc = local_40[0];
  uVar1 = (**(code **)(*local_40[0] + 0x20))(local_40[0],local_4c,uVar5);
  uVar5 = 0x10001593;
  FUN_10004900(local_28,uVar1);
  local_54[0] = 0;
  local_e0 = local_4c[0];
  uVar1 = (**(code **)(*local_4c[0] + 0x20))(local_4c[0],local_54,uVar5);
  uVar5 = 0x100015cd;
  FUN_10004900(local_28,uVar1);
  for (local_58 = 1; local_58 <= local_54[0]; local_58 = local_58 + 1) {
    local_60[0] = (int *)0x0;
    local_90 = CONCAT22(local_90._2_2_,3);
    local_88 = local_58;
    local_e4 = &local_90;
    local_8._0_1_ = 10;
    local_80 = local_90;
    local_78 = local_58;
    local_e8 = local_4c[0];
    uVar1 = (**(code **)(*local_4c[0] + 0x1c))
                      (local_4c[0],local_90,local_8c,local_58,local_84,local_60);
    uVar5 = 0x100016c7;
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 9;
    local_c4 = Ordinal_9(&local_90,uVar5);
    local_6c[0] = (wchar_t *)0x0;
    local_8._0_1_ = 0xb;
    local_ec = local_60[0];
    uVar1 = (**(code **)(*local_60[0] + 0x1c))(local_60[0],local_6c,0x100016ea);
    uVar5 = 0x10001725;
    FUN_10004900(local_28,uVar1);
    local_c8 = local_6c[0];
    local_fc[2] = (int *)FUN_10017710(local_ac,local_6c[0]);
    local_8._0_1_ = 0xc;
    local_fc[3] = local_fc[2];
    uVar4 = FUN_10015ec0((void *)(param_1 + 0x34),(int *)&local_b0,(ushort *)local_fc[2]);
    local_fc[1] = (int *)uVar4;
    local_8._0_1_ = 0xd;
    local_fc[0] = (int *)*local_fc[1];
    local_d4 = local_60[0];
    local_cc = local_fc[1];
    uVar1 = (**(code **)(*local_fc[0] + 0x10))(local_fc[0],local_60[0],uVar5);
    uVar5 = 0x100017d9;
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 0xc;
    if (local_b0 != (int *)0x0) {
      (**(code **)(*local_b0 + 8))(local_b0,uVar5);
      uVar5 = 0x10001814;
    }
    local_8._0_1_ = 0x10;
    FUN_10003620(local_ac,'\x01',0);
    local_8._0_1_ = 9;
    Ordinal_6(local_6c[0],uVar5);
    uVar5 = 0x10001842;
    local_8 = CONCAT31(local_8._1_3_,7);
    if (local_60[0] != (int *)0x0) {
      (**(code **)(*local_60[0] + 8))(local_60[0]);
      uVar5 = 0x10001867;
    }
  }
  local_8._0_1_ = 5;
  if (local_4c[0] != (int *)0x0) {
    (**(code **)(*local_4c[0] + 8))(local_4c[0],uVar5);
    uVar5 = 0x10001891;
  }
  local_8._0_1_ = 3;
  if (local_40[0] != (int *)0x0) {
    (**(code **)(*local_40[0] + 8))(local_40[0],uVar5);
    uVar5 = 0x100018ba;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))(local_34[0],uVar5);
  }
  uVar4 = FUN_100018ee();
  return uVar4;
}



// Function: Catch@100018e1 at 100018e1

undefined4 Catch_100018e1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100018f5;
}



// Function: FUN_100018ee at 100018ee

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100018ee(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0xb0) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xb0);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10001944);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_100019e0 at 100019e0

void FUN_100019e0(undefined4 param_1)

{
  undefined4 local_8;
  
  local_8 = param_1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10026780);
}



// Function: FUN_10001a20 at 10001a20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001a20(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10001a60 at 10001a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001a60(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019910;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001ae0 at 10001ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10001ae0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  int *local_64 [4];
  int local_54;
  undefined4 local_4c [3];
  int local_40;
  int local_3c;
  int *local_34;
  int local_30;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019948;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_64;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff90;
  FUN_10004880(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_30 = 0;
  while( true ) {
    local_54 = param_1 + 0x34;
    FUN_10017510(local_4c,param_1 + 0x38);
    local_40 = *(int *)(local_54 + 0x44);
    local_8._0_1_ = 1;
    local_3c = local_40;
    FUN_10017560(local_4c);
    if (local_40 <= local_30) break;
    uVar4 = FUN_10015df0((void *)(param_1 + 0x34),(int *)&local_34,local_30);
    local_64[1] = (int *)uVar4;
    local_8._0_1_ = 3;
    local_64[0] = (int *)*local_64[1];
    local_64[3] = local_64[1];
    uVar1 = (**(code **)(*local_64[0] + 0x14))(local_64[0]);
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 1;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
    local_30 = local_30 + 1;
  }
  uVar4 = FUN_10001c00();
  return uVar4;
}



// Function: Catch@10001bf3 at 10001bf3

undefined4 Catch_10001bf3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10001c07;
}



// Function: FUN_10001c00 at 10001c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10001c00(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x34);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10001c50);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10001c80 at 10001c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10001c80(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_c8 [4];
  int *local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int *local_a8;
  int *local_a4;
  undefined4 *local_9c;
  int local_98;
  int local_94;
  undefined4 local_8c [3];
  int local_80;
  undefined4 local_74;
  undefined4 local_70;
  int *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int *local_5c;
  int *local_54 [2];
  int *local_4c [2];
  short local_44 [2];
  int local_40;
  char local_39;
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100199c3;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_c8;
  for (iVar2 = 0x2d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff2c;
  FUN_10004880(local_28);
  local_34[0] = (int *)0x0;
  local_8 = 3;
  local_b8 = *(int **)(param_1 + 0x80);
  uVar1 = (**(code **)(*local_b8 + 0x34))(local_b8,local_34);
  uVar5 = 0x10001d12;
  FUN_10004900(local_28,uVar1);
  local_39 = '\0';
  local_40 = 0;
  while( true ) {
    local_98 = param_1 + 0x34;
    FUN_10017510(local_8c,param_1 + 0x38);
    local_94 = *(int *)(local_98 + 0x44);
    local_8._0_1_ = 3;
    local_80 = local_94;
    FUN_10017560(local_8c);
    if (local_94 <= local_40) break;
    uVar4 = FUN_10015df0((void *)(param_1 + 0x34),(int *)local_54,local_40);
    local_c8[3] = (int *)uVar4;
    local_8._0_1_ = 5;
    local_c8[2] = (int *)*local_c8[3];
    local_a4 = local_34[0];
    local_9c = local_c8[3];
    uVar1 = (**(code **)(*local_c8[2] + 0x18))(local_c8[2],local_34[0],local_44);
    uVar5 = 0x10001dfd;
    FUN_10004900(local_28,uVar1);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_54[0] != (int *)0x0) {
      (**(code **)(*local_54[0] + 8))(local_54[0]);
      uVar5 = 0x10001e2f;
    }
    if (local_44[0] == -1) {
      local_39 = '\x01';
    }
    local_40 = local_40 + 1;
  }
  if (local_39 != '\0') {
    local_4c[0] = (int *)0x0;
    local_8._0_1_ = 9;
    local_a8 = local_34[0];
    local_74 = CONCAT22(local_74._2_2_,9);
    local_6c = local_34[0];
    if (local_34[0] != (int *)0x0) {
      (**(code **)(*local_34[0] + 4))(local_34[0],uVar5);
      uVar5 = 0x10001e94;
    }
    local_c8[1] = &local_74;
    local_8._0_1_ = 10;
    local_64 = local_74;
    local_5c = local_6c;
    local_c8[0] = *(int **)(param_1 + 0x28);
    local_b0 = *(undefined4 *)(param_1 + 0x84);
    uVar1 = (**(code **)(*local_c8[0] + 0x34))
                      (local_c8[0],local_b0,2,local_74,local_70,local_6c,local_68,local_4c,uVar5);
    uVar5 = 0x10001f2b;
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 9;
    local_b4 = Ordinal_9(&local_74,uVar5);
    uVar5 = 0x10001f4b;
    local_8._0_1_ = 3;
    if (local_4c[0] != (int *)0x0) {
      (**(code **)(*local_4c[0] + 8))(local_4c[0],0x10001f4b);
      uVar5 = 0x10001f76;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))(local_34[0],uVar5);
  }
  uVar4 = FUN_10001faa();
  return uVar4;
}



// Function: Catch@10001f9d at 10001f9d

undefined4 Catch_10001f9d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10001fb1;
}



// Function: FUN_10001faa at 10001faa

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10001faa(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x74);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10001ffc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10002050 at 10002050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10002050(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019d48;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100020c0 at 100020c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100020c0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 local_c;
  
  piVar1 = (int *)(param_1 + 0x30);
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    *param_2 = *piVar1;
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 4))(*piVar1);
    }
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10002140 at 10002140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong FUN_10002140(int param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  ushort **ppuVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 in_stack_00000018;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *local_90 [4];
  undefined4 local_80;
  ushort *local_7c;
  undefined4 *local_74;
  wchar_t *local_70;
  int *local_68;
  int *local_64;
  undefined1 local_60 [32];
  short local_40 [4];
  wchar_t *local_38;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019a20;
  pvStack_10 = ExceptionList;
  ppuVar2 = local_90;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (ushort *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff64;
  FUN_10004880(local_28);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_40[0] = 0;
  local_70 = (wchar_t *)Ordinal_10(local_40,&stack0x00000008);
  uVar6 = 0x100021a4;
  if ((int)local_70 < 0) {
    local_40[0] = 10;
    local_38 = local_70;
    FUN_100019e0(local_70);
  }
  local_8._0_1_ = 2;
  if (local_40[0] == 8) {
    local_90[2] = (ushort *)FUN_10017710(local_60,local_38);
    local_8._0_1_ = 3;
    local_90[3] = local_90[2];
    uVar3 = FUN_10015ec0((void *)(param_1 + 0x34),(int *)&local_64,local_90[2]);
    local_90[1] = (ushort *)uVar3;
    local_8._0_1_ = 4;
    local_74 = (undefined4 *)local_90[1];
    uVar6 = (**(code **)**(undefined4 **)local_90[1])
                      (*(undefined4 *)local_90[1],&DAT_100236a0,in_stack_00000018);
    uVar5 = 0x10002242;
    FUN_10004900(local_28,uVar6);
    local_8._0_1_ = 3;
    if (local_64 != (int *)0x0) {
      (**(code **)(*local_64 + 8))(local_64,uVar5);
      uVar5 = 0x10002274;
    }
    local_8._0_1_ = 7;
    FUN_10003620(local_60,'\x01',0);
  }
  else {
    uVar5 = FUN_10017a00(0x14,(int)local_40,0,0x409);
    FUN_10004900(local_28,uVar5);
    uVar3 = FUN_10015df0((void *)(param_1 + 0x34),(int *)&local_68,(int)local_38);
    local_90[0] = (ushort *)uVar3;
    local_8._0_1_ = 8;
    local_7c = local_90[0];
    uVar6 = (**(code **)**(undefined4 **)local_90[0])
                      (*(undefined4 *)local_90[0],&DAT_100236a0,in_stack_00000018,uVar6);
    uVar5 = 0x100022f4;
    FUN_10004900(local_28,uVar6);
    local_8._0_1_ = 2;
    if (local_68 != (int *)0x0) {
      (**(code **)(*local_68 + 8))(local_68,uVar5);
      uVar5 = 0x10002326;
    }
  }
  local_8._0_1_ = 1;
  local_80 = Ordinal_9(local_40,uVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100048e0(local_28);
  lVar4 = FUN_10002368(extraout_ECX,extraout_EDX);
  return lVar4;
}



// Function: Catch@1000234e at 1000234e

undefined * Catch_1000234e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x68) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002371;
}



// Function: FUN_10002368 at 10002368

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong __fastcall FUN_10002368(undefined4 param_1,uint param_2)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100023ac);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (ulonglong)param_2 << 0x20;
}



// Function: FUN_100023e0 at 100023e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100028db) */
/* WARNING: Removing unreachable block (ram,0x10002902) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_100023e0(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  HRESULT HVar2;
  ULONG UVar3;
  int iVar4;
  int *extraout_ECX;
  IUnknown **ppIVar5;
  undefined8 uVar6;
  int *piVar7;
  IUnknown *local_1e8 [4];
  IUnknown *local_1d8;
  int *local_1d4;
  int *local_1d0;
  int *local_1cc;
  undefined4 *local_1c8;
  int *local_1c4;
  int *local_1c0;
  int *local_1bc;
  int *local_1b8;
  int *local_1b4;
  int *local_1b0;
  int *local_1ac;
  undefined4 *local_1a8;
  int *local_1a4;
  int *local_1a0;
  int *local_19c;
  void **local_18c;
  undefined1 *local_188;
  IUnknown *local_184;
  int *local_180;
  IID *local_17c;
  void **local_178;
  undefined4 local_174;
  undefined4 local_170;
  int *local_16c;
  int *local_168;
  undefined4 local_164;
  int *local_158;
  undefined4 local_150;
  undefined4 *local_14c;
  int *local_144;
  int *local_13c;
  int local_138;
  int *local_134;
  int local_130;
  undefined1 local_128 [28];
  undefined1 *local_10c;
  undefined4 local_108 [2];
  int local_100;
  undefined4 local_f8;
  int local_f0;
  int local_e8 [2];
  int *local_e0 [3];
  IUnknown *local_d4 [3];
  IID *local_c8;
  void **local_bc;
  int *local_b0;
  int local_a8;
  int local_a4;
  int local_9c [7];
  int *local_80;
  int *local_74 [3];
  int *local_68;
  int *local_5c;
  int *local_50;
  int *local_44;
  int *local_38;
  undefined4 local_30;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019bcf;
  pvStack_10 = ExceptionList;
  ppIVar5 = local_1e8;
  for (iVar4 = 0x75; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppIVar5 = (IUnknown *)&DAT_cccccccc;
    ppIVar5 = ppIVar5 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xfffffe0c;
  FUN_10004880(local_28);
  local_8 = 1;
  local_134 = (int *)(param_1 + 0x24);
  if ((int *)*local_134 == param_2) {
    local_130 = *local_134;
  }
  else {
    FUN_10002ff0(local_134,param_2);
  }
  local_13c = (int *)(param_1 + 0x28);
  if ((int *)*local_13c == param_3) {
    local_138 = *local_13c;
  }
  else {
    FUN_10002ff0(local_13c,param_3);
  }
  local_19c = *(int **)(param_1 + 0x24);
  uVar1 = (**(code **)(*local_19c + 0x3c))();
  FUN_10004900(local_28,uVar1);
  local_144 = *(int **)(param_1 + 0x28);
  uVar6 = FUN_10018060(local_144);
  local_30 = (undefined4)uVar6;
  local_38 = (int *)0x0;
  local_8._0_1_ = 3;
  local_1a0 = *(int **)(param_1 + 0x24);
  uVar1 = (**(code **)(*local_1a0 + 0x44))();
  FUN_10004900(local_28,uVar1);
  local_44 = (int *)0x0;
  local_8._0_1_ = 5;
  local_1a4 = local_38;
  uVar6 = FUN_100175b0(local_e8,5);
  local_1a8 = (undefined4 *)uVar6;
  local_8._0_1_ = 6;
  local_150 = *local_1a8;
  local_14c = local_1a8;
  uVar1 = (**(code **)(*local_1a4 + 0x1c))();
  FUN_10004900(local_28,uVar1);
  local_8._0_1_ = 5;
  Ordinal_6();
  local_50 = (int *)0x0;
  local_8._0_1_ = 8;
  local_1ac = local_44;
  uVar1 = (**(code **)(*local_44 + 0x24))();
  FUN_10004900(local_28,uVar1);
  local_5c = (int *)0x0;
  local_8._0_1_ = 10;
  local_1b0 = *(int **)(param_1 + 0x28);
  uVar1 = (**(code **)(*local_1b0 + 0x40))();
  FUN_10004900(local_28,uVar1);
  local_1b4 = local_5c;
  local_158 = local_50;
  uVar1 = (**(code **)(*local_5c + 0x20))();
  FUN_10004900(local_28,uVar1);
  local_1b8 = *(int **)(param_1 + 0x80);
  uVar1 = (**(code **)(*local_1b8 + 0x20))();
  FUN_10004900(local_28,uVar1);
  local_68 = (int *)0x0;
  local_8._0_1_ = 0xc;
  local_1bc = *(int **)(param_1 + 0x28);
  local_164 = *(undefined4 *)(param_1 + 0x84);
  uVar1 = (**(code **)(*local_1bc + 0x30))();
  FUN_10004900(local_28,uVar1);
  local_168 = local_68;
  FUN_10003b50(local_74);
  local_8._0_1_ = 0xd;
  if (local_168 != (int *)0x0) {
    (**(code **)*local_168)();
  }
  local_80 = (int *)0x0;
  local_8._0_1_ = 0x10;
  local_1c0 = local_74[0];
  uVar1 = (**(code **)(*local_74[0] + 0x20))();
  FUN_10004900(local_28,uVar1);
  local_16c = *(int **)(param_1 + 0x30);
  FUN_10016800(local_9c,local_16c);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  local_a4 = 0;
  local_1c4 = local_80;
  uVar1 = (**(code **)(*local_80 + 0x20))();
  FUN_10004900(local_28,uVar1);
  for (local_a8 = 1; local_a8 <= local_a4; local_a8 = local_a8 + 1) {
    local_b0 = (int *)0x0;
    local_108[0] = CONCAT22(local_108[0]._2_2_,3);
    local_100 = local_a8;
    local_1c8 = local_108;
    local_8._0_1_ = 0x14;
    local_f8 = local_108[0];
    local_f0 = local_a8;
    local_1cc = local_80;
    uVar1 = (**(code **)(*local_80 + 0x1c))();
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 0x13;
    local_170 = Ordinal_9();
    local_bc = (void **)0x0;
    local_8._0_1_ = 0x15;
    local_1d0 = local_b0;
    uVar1 = (**(code **)(*local_b0 + 0x1c))();
    FUN_10004900(local_28,uVar1);
    local_c8 = (IID *)0x0;
    local_8._0_1_ = 0x16;
    local_1d4 = local_b0;
    uVar1 = (**(code **)(*local_b0 + 0x20))();
    FUN_10004900(local_28,uVar1);
    local_d4[0] = (IUnknown *)0x0;
    local_8._0_1_ = 0x18;
    HVar2 = CoCreateInstance((IID *)&DAT_10023a10,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100236b0,local_d4)
    ;
    FUN_10004900(local_28,HVar2);
    local_1d8 = local_d4[0];
    local_174 = *(undefined4 *)(param_1 + 0x28);
    local_178 = local_bc;
    local_17c = local_c8;
    HVar2 = (*local_d4[0]->lpVtbl[1].QueryInterface)(local_d4[0],local_c8,local_bc);
    FUN_10004900(local_28,HVar2);
    local_1e8[3] = local_d4[0];
    local_180 = local_b0;
    UVar3 = (*local_d4[0]->lpVtbl[1].AddRef)(local_d4[0]);
    FUN_10004900(local_28,UVar3);
    local_184 = local_d4[0];
    local_e0[0] = (int *)0x0;
    local_8._0_1_ = 0x1a;
    if (local_d4[0] != (IUnknown *)0x0) {
      (*local_d4[0]->lpVtbl->QueryInterface)(local_d4[0],(IID *)&DAT_100236a0,local_e0);
    }
    local_8._0_1_ = 0x1b;
    FUN_10016b60(local_e0[0]);
    local_10c = &stack0xfffffd20;
    local_188 = &stack0xfffffd20;
    piVar7 = extraout_ECX;
    ATL::CComPtrBase<struct_IUnknown>::CComPtrBase<struct_IUnknown>
              ((CComPtrBase<struct_IUnknown> *)&stack0xfffffd20,local_d4[0]);
    local_1e8[2] = (IUnknown *)local_188;
    local_8._0_1_ = 0x1e;
    local_18c = local_bc;
    local_1e8[0] = (IUnknown *)FUN_10017710(local_128,(wchar_t *)local_bc);
    local_8._0_1_ = 0x20;
    local_1e8[1] = local_1e8[0];
    FUN_100032a0((void *)(param_1 + 0x34),local_1e8[0],piVar7);
    local_8._0_1_ = 0x21;
    FUN_10003620(local_128,'\x01',0);
    local_8._0_1_ = 0x18;
    if (local_e0[0] != (int *)0x0) {
      (**(code **)(*local_e0[0] + 8))();
    }
    local_8._0_1_ = 0x16;
    if (local_d4[0] != (IUnknown *)0x0) {
      (*local_d4[0]->lpVtbl->Release)(local_d4[0]);
    }
    local_8._0_1_ = 0x15;
    Ordinal_6();
    local_8._0_1_ = 0x13;
    Ordinal_6(local_bc,0x10002cd7);
    local_8 = CONCAT31(local_8._1_3_,0x11);
    if (local_b0 != (int *)0x0) {
      (**(code **)(*local_b0 + 8))();
    }
  }
  local_8._0_1_ = 0x10;
  FUN_10016ab0(local_9c);
  local_8._0_1_ = 0xe;
  if (local_80 != (int *)0x0) {
    (**(code **)(*local_80 + 8))();
  }
  local_8._0_1_ = 0xc;
  if (local_74[0] != (int *)0x0) {
    (**(code **)(*local_74[0] + 8))();
  }
  local_8._0_1_ = 10;
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))();
  }
  local_8._0_1_ = 8;
  if (local_5c != (int *)0x0) {
    (**(code **)(*local_5c + 8))();
  }
  local_8._0_1_ = 5;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))();
  }
  local_8._0_1_ = 3;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  uVar6 = FUN_10002e50();
  return uVar6;
}



// Function: Catch@10002e3c at 10002e3c

undefined4 Catch_10002e3c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10002e57;
}



// Function: FUN_10002e50 at 10002e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10002e50(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x128) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x128);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10002ea8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10002ff0 at 10002ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * FUN_10002ff0(int *param_1,int *param_2)

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



// Function: FUN_10003060 at 10003060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003060(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a448;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100030c0 at 100030c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100030c0(undefined4 *param_1)

{
  int iVar1;
  void **ppvVar2;
  undefined1 auStack_6c [24];
  undefined4 *puStack_54;
  void *local_4c [13];
  undefined1 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019bfe;
  local_10 = ExceptionList;
  ppvVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameterConfig>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
             ::vftable;
  local_18 = auStack_6c;
  puStack_54 = param_1;
  local_14 = param_1;
  local_4c[1] = FUN_10003170(auStack_6c,L"CDualCollection CriticalSection Lock");
  local_8 = 0xffffffff;
  local_4c[2] = local_4c[1];
  local_4c[0] = FUN_100172a0(local_14 + 1);
  local_8 = 1;
  puStack_54 = (undefined4 *)0x10003142;
  FUN_100038d0((int)(local_14 + 0xf));
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10003170 at 10003170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10003170(void *this,wchar_t *param_1)

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
  
  puStack_c = &LAB_1001a448;
  local_10 = ExceptionList;
  ppvVar2 = local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_1c = &local_1d;
  local_8 = 0;
  ExceptionList = &local_10;
  local_40[0] = this;
  local_14 = this;
  FUN_10003620(this,'\0',0);
  local_28 = wcslen(param_1);
  FUN_10003dc0(local_14,(undefined4 *)param_1,local_28);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10003210 at 10003210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003210(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_38 [9];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab8e;
  local_10 = ExceptionList;
  ppuVar2 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameterConfig>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
             ::vftable;
  local_38[0] = param_1 + 0xf;
  local_8 = 0;
  local_14 = param_1;
  FUN_10003960(local_38[0]);
  local_8 = 0xffffffff;
  FUN_100173e0(local_14 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100032a0 at 100032a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100032a0(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 **ppuVar5;
  undefined8 uVar6;
  char cVar7;
  undefined4 *local_6c [4];
  void *local_5c;
  undefined1 local_55;
  undefined1 local_54 [36];
  int local_30;
  undefined1 local_2c;
  undefined4 local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019c40;
  local_10 = ExceptionList;
  ppuVar5 = local_6c;
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar5 = (undefined4 *)&DAT_cccccccc;
    ppuVar5 = ppuVar5 + 1;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_10017510(local_20,(int)this + 4);
  local_8._0_1_ = 1;
  local_6c[0] = (undefined4 *)FUN_10004980(local_54,param_1,(int *)&param_2);
  local_8._0_1_ = 2;
  local_5c = (void *)((int)local_14 + 0x3c);
  cVar7 = '\0';
  local_6c[3] = local_6c[0];
  piVar1 = (int *)FUN_10016490(local_5c,local_6c[0]);
  FUN_10004cc0(local_5c,&local_30,piVar1,cVar7);
  local_8._0_1_ = 1;
  FUN_10003570(local_54);
  local_55 = local_2c;
  local_8 = (uint)local_8._1_3_ << 8;
  uVar6 = FUN_10017560(local_20);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    uVar6 = (**(code **)(*param_2 + 8))(param_2);
  }
  uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar2 = CONCAT31((int3)((ulonglong)uVar6 >> 8),local_55);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100033b4);
  ExceptionList = local_10;
  return CONCAT44(uVar4,uVar2);
}



// Function: FUN_100033e0 at 100033e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100033e0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameterConfig>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
       ::vftable;
  local_8 = 0;
  FUN_10003960((void *)((int)this + 0x3c));
  local_8 = 0xffffffff;
  FUN_100173e0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003490 at 10003490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003490(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019c58;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10003960(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003500 at 10003500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003500(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019c78;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10003570(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003570 at 10003570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003570(void *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cbb;
  local_10 = ExceptionList;
  piVar1 = (int *)((int)param_1 + 0x1c);
  local_8 = 0;
  ExceptionList = &local_10;
  if (*piVar1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1);
  }
  local_8 = 4;
  FUN_10003620(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003620 at 10003620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10003620(void *this,char param_1,int param_2)

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



// Function: FUN_100036e0 at 100036e0

void FUN_100036e0(void)

{
  return;
}



// Function: FUN_10003700 at 10003700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10003700(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e72;
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



// Function: FUN_10003780 at 10003780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003780(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e72;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100037e0 at 100037e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_100037e0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cea;
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



// Function: FUN_10003860 at 10003860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003860(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cea;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100038d0 at 100038d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100038d0(int param_1)

{
  int iStack_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019d10;
  local_10 = ExceptionList;
  local_30 = &DAT_cccccccc;
  local_28 = &DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  local_2c = (undefined1 *)&iStack_34;
  local_1c = (undefined1 *)&iStack_34;
  ExceptionList = &local_10;
  iStack_34 = param_1;
  local_14 = param_1;
  FUN_10012f50(param_1);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10003960 at 10003960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003960(void *param_1)

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
  
  puStack_c = &LAB_10019d28;
  local_10 = ExceptionList;
  ppvVar2 = &local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
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
  FUN_100045d0(param_1,&local_44,local_40,local_38);
  local_8 = 0xffffffff;
  local_48 = *(void **)((int)local_14 + 4);
  operator_delete(local_48);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003a20 at 10003a20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10003a20(void *this,int *param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  int *local_44 [2];
  int local_3c;
  ushort *local_38;
  uint local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_10 [2];
  void *local_8;
  
  ppiVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_8 = this;
  local_24 = FUN_100046f0(this,param_2);
  FUN_10016170(local_10,local_24);
  local_28 = *(int *)((int)local_8 + 4);
  local_1c = local_28;
  if (local_10[0] != local_28) {
    local_2c = local_10[0];
    local_38 = (ushort *)(local_10[0] + 0xc);
    local_30 = *(uint *)(local_10[0] + 0x1c);
    local_44[1] = (int *)local_38;
    if (7 < *(uint *)(local_10[0] + 0x20)) {
      local_44[1] = (int *)*(ushort **)local_38;
    }
    uVar1 = FUN_10004fd0(param_2,0,*(uint *)(param_2 + 8),(ushort *)local_44[1],local_30);
    if (-1 < (int)uVar1) {
      local_44[0] = local_10;
      goto LAB_10003af0;
    }
  }
  local_3c = *(int *)((int)local_8 + 4);
  local_44[0] = &local_20;
  local_20 = local_3c;
LAB_10003af0:
  local_18 = local_44[0];
  *param_1 = *local_44[0];
  piVar4 = param_1;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10003b28);
  return CONCAT44(piVar4,param_1);
}



// Function: FUN_10003b50 at 10003b50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003b50(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10003bb0 at 10003bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10003bb0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019d7a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  *(undefined ***)this = std::out_of_range::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10003c30 at 10003c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10003c30(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e72;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10003ca0 at 10003ca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003ca0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019db3;
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



// Function: FUN_10003d40 at 10003d40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003d40(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019dd0;
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



// Function: FUN_10003dc0 at 10003dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003dc0(void *this,undefined4 *param_1,uint param_2)

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
    *ppvVar3 = &DAT_cccccccc;
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
        goto LAB_10003e38;
      }
    }
  }
  local_9 = '\0';
LAB_10003e38:
  local_8 = (undefined4 *)this;
  if (local_9 == '\0') {
    bVar1 = FUN_10004190(this,param_2,'\0');
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
    local_8 = FUN_10003f10(this,(undefined4 *)this,(int)param_1 - (int)local_34[1] >> 1,param_2);
  }
  return local_8;
}



// Function: FUN_10003f10 at 10003f10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003f10(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
    FUN_10004060(local_8,param_2 + local_c,0xffffffff);
    FUN_10004060(local_8,0,param_2);
  }
  else {
    bVar1 = FUN_10004190(local_8,local_c,'\0');
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



// Function: FUN_10004060 at 10004060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004060(void *this,uint param_1,uint param_2)

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



// Function: FUN_10004190 at 10004190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100041cf) */
/* WARNING: Removing unreachable block (ram,0x100041e2) */

bool __thiscall FUN_10004190(void *this,uint param_1,char param_2)

{
  undefined2 *local_28;
  uint local_24;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10004360(this,param_1);
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
    FUN_10003620(this,'\x01',local_24);
  }
  return param_1 != 0;
}



// Function: FUN_100042d0 at 100042d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100042d0(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: CComPtrBase<struct_IUnknown> at 10004310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    protected: __thiscall ATL::CComPtrBase<struct IUnknown>::CComPtrBase<struct IUnknown>(struct
   IUnknown *)
   
   Library: Visual Studio 2012 Debug */

CComPtrBase<struct_IUnknown> * __thiscall
ATL::CComPtrBase<struct_IUnknown>::CComPtrBase<struct_IUnknown>
          (CComPtrBase<struct_IUnknown> *this,IUnknown *param_1)

{
  *(IUnknown **)this = param_1;
  if (*(int *)this != 0) {
    (**(code **)(**(int **)this + 4))(*(undefined4 *)this);
  }
  return this;
}



// Function: FUN_10004360 at 10004360

/* WARNING: Removing unreachable block (ram,0x1000441e) */
/* WARNING: Removing unreachable block (ram,0x100043b4) */
/* WARNING: Removing unreachable block (ram,0x10004480) */
/* WARNING: Removing unreachable block (ram,0x10004431) */
/* WARNING: Removing unreachable block (ram,0x100043c7) */
/* WARNING: Removing unreachable block (ram,0x10004493) */

void __thiscall FUN_10004360(void *this,uint param_1)

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
  
  puStack_c = &LAB_10019de0;
  pvStack_10 = ExceptionList;
  puVar2 = local_64;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
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
        local_34 = 0x7fffffff;
        local_64[2] = 0x7fffffff;
        local_38 = 0x7fffffff;
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
  local_20 = FUN_10004a50(local_1c + 1);
  FUN_10004521();
  return;
}



// Function: Catch@100044c8 at 100044c8

void Catch_100044c8(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = FUN_10004a50(*(int *)(unaff_EBP + -0x18) + 1);
  *(void **)(unaff_EBP + -0x1c) = pvVar1;
  FUN_1000450d();
  return;
}



// Function: Catch@100044eb at 100044eb

void Catch_100044eb(void)

{
  int unaff_EBP;
  
  FUN_10003620(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000450d at 1000450d

undefined4 FUN_1000450d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10004528;
}



// Function: FUN_10004521 at 10004521

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004521(void)

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
  FUN_10003620(*(void **)(unaff_EBP + -0x14),'\x01',0);
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



// Function: FUN_100045d0 at 100045d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100045d0(void *this,int *param_1,int *param_2,int *param_3)

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
    *ppiVar3 = (int *)&DAT_cccccccc;
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
      FUN_10013870(this);
      local_2c = *(int **)((int)local_8 + 4);
      local_30 = (int *)*local_2c;
      *param_1 = (int)local_30;
      piVar2 = local_30;
      goto LAB_100046b0;
    }
  }
  while (param_2 != param_3) {
    local_4c[2] = param_2;
    FUN_10013a30((int *)&param_2);
    local_14 = local_4c[2];
    FUN_10013370(&local_18,local_4c[2]);
  }
  local_4c[0] = param_2;
  *param_1 = (int)param_2;
  piVar2 = param_1;
LAB_100046b0:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100046d4);
  return CONCAT44(piVar2,param_1);
}



// Function: FUN_100046f0 at 100046f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100046f0(void *this,ushort *param_1)

{
  uint uVar1;
  ushort *local_20;
  undefined4 *local_10;
  undefined4 *local_c;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_10 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x2d) == '\0') {
    if (*(uint *)(param_1 + 10) < 8) {
      local_20 = param_1;
    }
    else {
      local_20 = *(ushort **)param_1;
    }
    uVar1 = FUN_10004fd0(local_c + 3,0,local_c[7],local_20,*(uint *)(param_1 + 8));
    if ((int)uVar1 < 0) {
      local_c = (undefined4 *)local_c[2];
    }
    else {
      local_10 = local_c;
      local_c = (undefined4 *)*local_c;
    }
  }
  return local_10;
}



// Function: FUN_100047c0 at 100047c0

void __thiscall FUN_100047c0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x2d) == '\0') {
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



// Function: FUN_10004880 at 10004880

undefined4 * __fastcall FUN_10004880(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return param_1;
}



// Function: FUN_100048e0 at 100048e0

void __fastcall FUN_100048e0(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10004900 at 10004900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10004900(void *this,undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int local_40;
  char *local_3c;
  void *local_8;
  
  piVar2 = &local_40;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  *(undefined4 *)((int)this + 0xc) = param_1;
  local_40 = *(int *)((int)this + 0xc);
  local_3c = (char *)((int)this + 4);
  local_8 = this;
  if ((*local_3c == '\0') && (local_40 < 0)) {
    *local_3c = '\x01';
    FUN_10005120(local_40,*(undefined4 *)((int)this + 8));
  }
  return (int)local_8;
}



// Function: FUN_10004980 at 10004980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10004980(void *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_60 [10];
  undefined1 local_35;
  undefined1 *local_34;
  uint local_30;
  undefined4 local_2c [7];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e29;
  local_10 = ExceptionList;
  ppuVar2 = local_60;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_30 = 0;
  local_34 = &local_35;
  local_60[0] = local_2c;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_10003620(local_2c,'\0',0);
  FUN_10003f10(local_2c,param_2,0,0xffffffff);
  local_60[2] = local_2c;
  local_8 = 2;
  FUN_100165b0(param_1,local_60[2],param_3);
  local_30 = local_30 | 1;
  local_8 = 4;
  FUN_10003620(local_2c,'\x01',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004a50 at 10004a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10004a50(uint param_1)

{
  char *local_24;
  undefined **local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e52;
  local_10 = ExceptionList;
  local_24 = &DAT_cccccccc;
  local_20 = (undefined **)&DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
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
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10026f74);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004b20 at 10004b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004b20(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e72;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004b90 at 10004b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10004b90(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e72;
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



// Function: FUN_10004c10 at 10004c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004c10(void *this,uint param_1)

{
  FUN_100048e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004c50 at 10004c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

exception * __thiscall FUN_10004c50(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e72;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10004cc0 at 10004cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10004d8d) */

undefined8 __thiscall FUN_10004cc0(void *this,int *param_1,int *param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  int **ppiVar3;
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
  ushort *local_c;
  void *local_8;
  
  ppiVar3 = local_98;
  for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_c = (ushort *)(param_2 + 3);
  local_10 = *(int **)(*(int *)((int)this + 4) + 4);
  local_14 = *(int **)((int)this + 4);
  local_15 = '\x01';
  local_8 = this;
  while (*(char *)((int)local_10 + 0x2d) == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      iVar1 = FUN_10004f50(local_c,(ushort *)(local_10 + 3));
      local_15 = iVar1 < 0;
    }
    else {
      iVar1 = FUN_10004f50(local_10 + 3,local_c);
      local_15 = '\x01' - (iVar1 < 0);
    }
    if (local_15 == '\0') {
      local_98[0] = (int *)local_10[2];
    }
    else {
      local_98[0] = (int *)*local_10;
    }
    local_10 = local_98[0];
  }
  FUN_10016170(local_20,local_14);
  if (local_15 != '\0') {
    local_84 = *(undefined4 **)((int)local_8 + 4);
    local_88 = *local_84;
    FUN_10016170(local_30,local_88);
    if (local_20[0] == local_30[0]) {
      local_31 = 1;
      local_8c = FUN_10016190(local_8,&local_38,'\x01',local_14,param_2);
      iVar1 = *local_8c;
      *param_1 = iVar1;
      piVar2 = (int *)CONCAT31((int3)((uint)iVar1 >> 8),local_31);
      *(undefined1 *)(param_1 + 1) = local_31;
      goto LAB_10004f0e;
    }
    FUN_10005510(local_20);
  }
  local_90 = local_20[0];
  iVar1 = FUN_10004f50((void *)(local_20[0] + 0xc),local_c);
  piVar2 = param_1;
  if (iVar1 < 0) {
    local_39 = 1;
    local_98[1] = FUN_10016190(local_8,&local_40,local_15,local_14,param_2);
    *param_1 = *local_98[1];
    *(undefined1 *)(param_1 + 1) = local_39;
  }
  else {
    FUN_10013af0((int)local_8 + 0xd,param_2 + 3);
    operator_delete(param_2);
    local_41 = 0;
    *param_1 = local_20[0];
    *(undefined1 *)(param_1 + 1) = 0;
  }
LAB_10004f0e:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10004f34);
  return CONCAT44(piVar2,param_1);
}



// Function: FUN_10004f50 at 10004f50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10004f50(void *this,ushort *param_1)

{
  ushort *local_24;
  
  if (*(uint *)(param_1 + 10) < 8) {
    local_24 = param_1;
  }
  else {
    local_24 = *(ushort **)param_1;
  }
  FUN_10004fd0(this,0,*(uint *)((int)this + 0x10),local_24,*(uint *)(param_1 + 8));
  return;
}



// Function: FUN_10004fd0 at 10004fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_10004fd0(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
    *puVar2 = (uint)&DAT_cccccccc;
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
LAB_100050c4:
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
      goto LAB_100050c4;
    }
    local_10 = local_10 + 1;
    local_14 = local_14 + 1;
    local_18 = local_18 - 1;
  } while( true );
}



// Function: FUN_10005120 at 10005120

void FUN_10005120(undefined4 param_1,undefined4 param_2)

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
  puStack_c = &LAB_10019e9b;
  pvStack_10 = ExceptionList;
  puVar2 = local_bc;
  for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &pvStack_10;
  FUN_10005220(local_44,param_1,0,param_2,(wchar_t *)&PTR_100237f0,0);
  local_8 = 0;
  FUN_10005430(local_78,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_78,(ThrowInfo *)&DAT_10027004);
}



// Function: FUN_10005220 at 10005220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall
FUN_10005220(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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
  
  puStack_c = &LAB_10019ec3;
  local_10 = ExceptionList;
  ppvVar2 = local_44;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_44[0] = (void *)((int)this + 0x10);
  local_18 = &local_19;
  local_8 = 0;
  local_28 = local_44[0];
  local_14 = (undefined4 *)this;
  FUN_10003620(local_44[0],'\0',0);
  local_8 = 1;
  local_14[1] = param_1;
  local_14[2] = param_2;
  local_14[3] = param_3;
  local_2c = wcslen(param_4);
  FUN_10003dc0(local_14 + 4,(undefined4 *)param_4,local_2c);
  local_14[0xb] = param_5;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10005300 at 10005300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005300(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ee3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003620(param_1 + 4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005390 at 10005390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10005390(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ee3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003620((void *)((int)this + 0x10),'\x01',0);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005430 at 10005430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10005430(void *this,int param_1)

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
  
  puStack_c = &LAB_10019f03;
  local_10 = ExceptionList;
  ppvVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
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
  FUN_10003620(local_4c[0],'\0',0);
  FUN_10003f10(local_4c[1],(undefined4 *)(param_1 + 0x10),0,0xffffffff);
  local_14[0xb] = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10005510 at 10005510

int * __fastcall FUN_10005510(int *param_1)

{
  int *piVar1;
  int local_18;
  
  if (*(char *)(*param_1 + 0x2d) == '\0') {
    if (*(char *)(*(int *)*param_1 + 0x2d) == '\0') {
      local_18 = *(int *)*param_1;
      while (*(char *)(*(int *)(local_18 + 8) + 0x2d) == '\0') {
        local_18 = *(int *)(local_18 + 8);
      }
      *param_1 = local_18;
    }
    else {
      while ((piVar1 = *(int **)(*param_1 + 4), *(char *)((int)piVar1 + 0x2d) == '\0' &&
             (*param_1 == *piVar1))) {
        *param_1 = (int)piVar1;
      }
      if (*(char *)(*param_1 + 0x2d) == '\0') {
        *param_1 = (int)piVar1;
      }
    }
  }
  else {
    *param_1 = *(int *)(*param_1 + 8);
  }
  return param_1;
}



// Function: FUN_100055e0 at 100055e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10005627) */
/* WARNING: Removing unreachable block (ram,0x10005630) */

undefined4 * __thiscall FUN_100055e0(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    FUN_10003620(this,'\x01',0);
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,(param_1[4] + 1) * 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    FUN_10003620(param_1,'\0',0);
  }
  return (undefined4 *)this;
}



// Function: FUN_100056e0 at 100056e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100056e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a1fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 4) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 8),0,0x18);
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100057b0 at 100057b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100057b0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a25c;
  local_10 = ExceptionList;
  piVar1 = (int *)(param_1 + 0x28);
  local_8._1_3_ = 0;
  local_8._0_1_ = 1;
  ExceptionList = &local_10;
  if (*piVar1 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(*(undefined4 *)(param_1 + 0x24));
  local_8 = 7;
  if (*(char *)(param_1 + 0x20) != '\0') {
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100058b0 at 100058b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100058b0(int param_1)

{
  CoCreateInstance((IID *)&DAT_10023a00,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100238cc,
                   (LPVOID *)(param_1 + 0x28));
  return;
}



// Function: FUN_10005900 at 10005900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10005900(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    iVar1 = FUN_10005970((int *)(param_1 + 0x24));
    *param_2 = iVar1;
    if ((*param_2 == 0) && (*(int *)(param_1 + 0x24) != 0)) {
      local_c = 0x8007000e;
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10005970 at 10005970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10005970(int *param_1)

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
    uVar1 = Ordinal_150(*param_1,uVar1,0x100059b4);
  }
  return uVar1;
}



// Function: FUN_100059f0 at 100059f0

void FUN_100059f0(int param_1,int param_2)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a270;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  FUN_10005a80((void *)(param_1 + 0x24),param_2);
  FUN_10005a49();
  return;
}



// Function: Catch@10005a2f at 10005a2f

undefined * Catch_10005a2f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005a52;
}



// Function: FUN_10005a49 at 10005a49

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10005a49(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10005a80 at 10005a80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10005a80(void *this,int param_1)

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
      uVar1 = Ordinal_2(param_1,0x10005aae);
      *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
      if (*this == 0) {
        FUN_100019e0(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_10005b10 at 10005b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10005b10(int param_1,int *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined4 local_38;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a288;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffbc;
  local_28 = &DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  ExceptionList = &pvStack_10;
  FUN_10004880(&local_28);
  local_8 = 1;
  if ((param_2 == (int *)0x0) || (*param_2 != 0)) {
    FUN_10004900(&local_28,0x80004003);
  }
  piVar1 = (int *)(param_1 + 0x28);
  if (param_2 == (int *)0x0) {
    local_38 = 0x80004003;
  }
  else {
    *param_2 = *piVar1;
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 4))(*piVar1);
    }
    local_38 = 0;
  }
  FUN_10004900(&local_28,local_38);
  uVar2 = FUN_10005be7();
  return uVar2;
}



// Function: Catch@10005bda at 10005bda

undefined4 Catch_10005bda(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10005bee;
}



// Function: FUN_10005be7 at 10005be7

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10005be7(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x2c);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10005c34);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10005c50 at 10005c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10005c50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a361;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 4) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 8),0,0x18);
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10005d40 at 10005d40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005d40(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3b1;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_100063d0((_Container_base0 *)(param_1 + 0x24));
  local_8 = 6;
  if (*(char *)(param_1 + 0x20) != '\0') {
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005e20 at 10005e20

undefined4 FUN_10005e20(int param_1,int *param_2)

{
  undefined4 uVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3c0;
  pvStack_10 = ExceptionList;
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  *param_2 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 2;
  uVar1 = FUN_10005e9c();
  return uVar1;
}



// Function: Catch@10005e82 at 10005e82

undefined * Catch_10005e82(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005ea5;
}



// Function: FUN_10005e9c at 10005e9c

undefined4 FUN_10005e9c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10005ec0 at 10005ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10005ec0(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined4 local_38;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a3d8;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffbc;
  local_28 = &DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  ExceptionList = &pvStack_10;
  FUN_10004880(&local_28);
  local_8 = 1;
  if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
    FUN_10004900(&local_28,0x80004003);
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x24) + -4 + param_2 * 4);
  if (param_3 == (int *)0x0) {
    local_38 = 0x80004003;
  }
  else {
    *param_3 = *piVar1;
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 4))(*piVar1);
    }
    local_38 = 0;
  }
  FUN_10004900(&local_28,local_38);
  uVar2 = FUN_10005f9e();
  return uVar2;
}



// Function: Catch@10005f91 at 10005f91

undefined4 Catch_10005f91(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10005fa5;
}



// Function: FUN_10005f9e at 10005f9e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10005f9e(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x2c);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10005fec);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10006010 at 10006010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10006010(int param_1,int *param_2)

{
  undefined1 *puVar1;
  int *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a430;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  local_18 = (int *)&DAT_cccccccc;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  puVar1 = &stack0xffffffcc;
  if (param_2 != (int *)0x0) {
    ExceptionList = &pvStack_10;
    (**(code **)(*param_2 + 4))(param_2);
    puVar1 = local_14;
  }
  local_14 = puVar1;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_18 = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  local_8._0_1_ = 5;
  FUN_10006160((void *)(param_1 + 0x24),&local_18);
  local_8._0_1_ = 2;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_10006130();
  return;
}



// Function: Catch@10006116 at 10006116

undefined * Catch_10006116(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006139;
}



// Function: FUN_10006130 at 10006130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10006130(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10006160 at 10006160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10006160(void *this,undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < *(undefined4 **)((int)this + 4)) && (*this <= param_1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10006320(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10006780((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(*this + ((int)param_1 - iVar1 >> 2) * 4));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  else {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10006320(this,1);
    }
    FUN_10006780((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  return;
}



// Function: FUN_10006260 at 10006260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10006260(_Container_base0 *param_1)

{
  undefined8 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a448;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  uVar1 = FUN_100063d0(param_1);
  ExceptionList = local_10;
  return uVar1;
}



// Function: ~CComPtrBase<> at 100062d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CComPtrBase<struct IAccessor>::~CComPtrBase<struct IAccessor>(void)
    public: __thiscall ATL::CComPtrBase<struct IChapteredRowset>::~CComPtrBase<struct
   IChapteredRowset>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
    public: __thiscall ATL::CComPtrBase<struct IRowset>::~CComPtrBase<struct IRowset>(void)
     6 names - too many to list
   
   Library: Visual Studio 2012 Debug */

void __fastcall ~CComPtrBase<>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10006320 at 10006320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10006361) */

void __thiscall FUN_10006320(void *this,int param_1)

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
      uVar1 = FUN_100066f0(this,uVar1);
      FUN_100064d0(this,uVar1);
    }
  }
  return;
}



// Function: FUN_100063d0 at 100063d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_100063d0(_Container_base0 *param_1)

{
  int iVar1;
  int *piVar2;
  _Container_base0 *p_Var3;
  int local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  undefined1 local_15;
  undefined1 local_d;
  int *local_c;
  _Container_base0 *local_8;
  
  piVar2 = &local_2c;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  local_8 = param_1;
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    local_24 = *(int **)(local_8 + 4);
    local_20 = *(int **)local_8;
    local_d = local_15;
    for (local_c = local_20; local_c != local_24; local_c = local_c + 1) {
      FUN_100069c0(local_8 + 0xc,local_c);
    }
    local_2c = *(int *)(local_8 + 8) - *(int *)local_8 >> 2;
    local_28 = *(void **)local_8;
    operator_delete(local_28);
  }
  *(int *)local_8 = 0;
  *(int *)(local_8 + 4) = 0;
  *(int *)(local_8 + 8) = 0;
  p_Var3 = local_8;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100064b0);
  return CONCAT44(p_Var3,local_8);
}



// Function: FUN_100064d0 at 100064d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000651b) */

undefined8 __thiscall FUN_100064d0(void *this,uint param_1)

{
  void *extraout_EAX;
  int iVar1;
  void *extraout_EDX;
  void *pvVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_64 [10];
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined1 local_2d;
  undefined1 local_25;
  undefined4 local_24;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a460;
  pvStack_10 = ExceptionList;
  puVar3 = local_64;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = &DAT_cccccccc;
    puVar3 = puVar3 + 1;
  }
  local_24 = 0x3fffffff;
  local_64[0] = 0x3fffffff;
  local_18 = (undefined4 *)this;
  if (param_1 < 0x40000000) {
                    /* WARNING: Load size is inaccurate */
    pvVar2 = this;
    ExceptionList = &pvStack_10;
    local_14 = &stack0xffffff90;
    if ((uint)(*(int *)((int)this + 8) - *this >> 2) < param_1) {
      ExceptionList = &pvStack_10;
      local_14 = &stack0xffffff90;
      local_1c = (undefined4 *)FUN_10006820(param_1);
      local_8 = 0;
      local_3c = (undefined4 *)local_18[1];
      local_38 = (undefined4 *)*local_18;
      local_25 = local_2d;
      FUN_100068f0(local_38,local_3c,local_1c,local_18 + 3);
      uVar4 = FUN_100065cf();
      return uVar4;
    }
  }
  else {
    ExceptionList = &pvStack_10;
    local_14 = &stack0xffffff90;
    std::_Xlength_error("vector<T> too long");
    this = extraout_EAX;
    pvVar2 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100066c0);
  ExceptionList = pvStack_10;
  return CONCAT44(pvVar2,this);
}



// Function: Catch@100065ad at 100065ad

void Catch_100065ad(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100065cf at 100065cf

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100065cf(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  int iVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x1c) =
       *(int *)(*(int *)(unaff_EBP + -0x14) + 4) - **(int **)(unaff_EBP + -0x14) >> 2;
  if (**(int **)(unaff_EBP + -0x14) != 0) {
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4);
    *(undefined4 *)(unaff_EBP + -0x50) = **(undefined4 **)(unaff_EBP + -0x14);
    *(undefined1 *)(unaff_EBP + -0x3d) = *(undefined1 *)(unaff_EBP + -0x45);
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x50);
    while (*(int *)(unaff_EBP + -0x3c) != *(int *)(unaff_EBP + -0x54)) {
      FUN_100069c0(*(int *)(unaff_EBP + -0x14) + 0xc,*(int **)(unaff_EBP + -0x3c));
      *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + 4;
    }
    *(int *)(unaff_EBP + -0x5c) =
         *(int *)(*(int *)(unaff_EBP + -0x14) + 8) - **(int **)(unaff_EBP + -0x14) >> 2;
    *(undefined4 *)(unaff_EBP + -0x58) = **(undefined4 **)(unaff_EBP + -0x14);
    operator_delete(*(void **)(unaff_EBP + -0x58));
  }
  std::_Container_base0::_Orphan_all(*(_Container_base0 **)(unaff_EBP + -0x14));
  *(int *)(*(int *)(unaff_EBP + -0x14) + 8) =
       *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + 8) * 4;
  iVar2 = *(int *)(unaff_EBP + -0x14);
  *(int *)(iVar2 + 4) = *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x1c) * 4;
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  *puVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100066c0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(iVar2,puVar1);
}



// Function: FUN_100066f0 at 100066f0

/* WARNING: Removing unreachable block (ram,0x10006733) */

uint __thiscall FUN_100066f0(void *this,uint param_1)

{
  undefined4 local_18;
  undefined4 local_c;
  
                    /* WARNING: Load size is inaccurate */
  local_18 = *(int *)((int)this + 8) - *this >> 2;
  if (0x3fffffff - (local_18 >> 1) < local_18) {
    local_18 = 0;
  }
  else {
    local_18 = (local_18 >> 1) + local_18;
  }
  local_c = local_18;
  if (local_18 < param_1) {
    local_c = param_1;
  }
  return local_c;
}



// Function: FUN_10006780 at 10006780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10006780(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    *param_2 = *param_3;
    *param_3 = 0;
  }
  return;
}



// Function: FUN_10006820 at 10006820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10006820(uint param_1)

{
  char *local_24;
  undefined **local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e52;
  local_10 = ExceptionList;
  local_24 = &DAT_cccccccc;
  local_20 = (undefined **)&DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0x3fffffff < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 << 2), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)&local_20,&local_24);
    local_20 = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10026f74);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100068f0 at 100068f0

void FUN_100068f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4a0;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    FUN_10006780(param_4,param_3,param_1);
    param_3 = param_3 + 1;
  }
  FUN_10006993();
  return;
}



// Function: FUN_1000695a at 1000695a

void FUN_1000695a(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_100069c0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_1000695a();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10006963 at 10006963

void FUN_10006963(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_100069c0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_1000695a();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10006993 at 10006993

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10006993(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: FUN_100069c0 at 100069c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10006a18) */

void __cdecl FUN_100069c0(undefined4 param_1,int *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4c0;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  if (*param_2 != 0) {
    ExceptionList = &local_10;
    (**(code **)(*(int *)*param_2 + 8))(*param_2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006a40 at 10006a40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006a40(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0((int *)&DAT_1002d13c,0x65,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10006a80 at 10006a80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006a80(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0((int *)&DAT_1002d13c,0x67,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10006ac0 at 10006ac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006ac0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0((int *)&DAT_1002d13c,0x66,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10006b00 at 10006b00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006b00(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0((int *)&DAT_1002d13c,0x69,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10006b40 at 10006b40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10006b40(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0((int *)&DAT_1002d13c,0x68,param_1,(int *)0x0);
  return uVar1;
}



// Function: FUN_10006b80 at 10006b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10006b80(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_1000bdd0(&DAT_1002d13c,0x1002c210,param_1,(undefined4 *)&DAT_10023960);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000bec0(0x1002d13c);
  }
  return 1;
}



// Function: DllCanUnloadNow at 10006be0

HRESULT DllCanUnloadNow(void)

{
                    /* 0x6be0  1  DllCanUnloadNow */
  return (uint)(DAT_1002d144 != 0);
}



// Function: DllGetClassObject at 10006c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  undefined8 uVar1;
  
                    /* 0x6c00  2  DllGetClassObject */
  uVar1 = FUN_1000c050((int *)&DAT_1002d13c,(int *)rclsid,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)uVar1;
}



// Function: DllRegisterServer at 10006c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllRegisterServer(void)

{
                    /* 0x6c50  3  DllRegisterServer */
  FUN_1000c280(&DAT_1002d13c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10006c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllUnregisterServer(void)

{
                    /* 0x6c90  4  DllUnregisterServer */
  FUN_1000dc00(&DAT_1002d13c,1,(void *)0x0);
  return;
}



// Function: FUN_10006cd0 at 10006cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10006fec) */
/* WARNING: Removing unreachable block (ram,0x10006d2c) */

undefined8 FUN_10006cd0(int *param_1,ushort param_2,int param_3,int *param_4)

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
  int local_af4;
  LPCWSTR local_af0;
  int local_ae8 [4];
  undefined4 local_ad8;
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
  puStack_c = &LAB_1001a5e8;
  local_10 = ExceptionList;
  pDVar7 = local_b7c;
  for (iVar5 = 0x2db; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pDVar7 = (DWORD)&DAT_cccccccc;
    pDVar7 = pDVar7 + 1;
  }
  local_28 = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  FUN_1000b8e0(local_24);
  local_8 = 1;
  local_30 = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_b00 = param_4[1];
      local_afc = (LPCWSTR)*param_4;
      if ((local_afc != (LPCWSTR)0x0) && (local_b00 != 0)) {
        local_ad8 = 3;
        local_ae8[0] = 0;
        local_8._0_1_ = 4;
        local_af0 = local_afc;
        uVar8 = FUN_10007760(local_24,local_b00,local_afc,local_b00);
        local_af4 = (int)uVar8;
        local_af8 = (-(uint)(local_af4 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10010d20(local_ae8);
      }
    }
  }
  local_30 = (**(code **)(*param_1 + 0x14))(&local_28);
  local_b7c[0] = 0x10006e6e;
  if ((int)local_30 < 0) {
    local_28 = ATL::CRegObject::vftable;
    local_8 = 5;
    local_ab4 = local_30;
    FUN_100083b0((int)&local_28);
    local_b04 = local_24;
    local_8 = 6;
    FUN_10007b60(local_b04);
    local_8 = 0xffffffff;
    FUN_100114f0(local_b04);
    DVar4 = local_ab4;
    uVar6 = extraout_EDX;
  }
  else {
    local_38 = 3;
    local_48[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_260 = DAT_1002dc20;
    local_264 = GetModuleFileNameW(DAT_1002dc20,local_258,0x104);
    if (local_264 == 0) {
      local_ab8 = FUN_100075e0();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b08 = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 8;
      FUN_100083b0((int)&local_28);
      local_b0c = local_24;
      local_8 = 9;
      FUN_10007b60(local_b0c);
      local_8 = 0xffffffff;
      FUN_100114f0(local_b0c);
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
      FUN_100083b0((int)&local_28);
      local_b14 = local_24;
      local_8 = 0xb;
      FUN_10007b60(local_b14);
      local_8 = 0xffffffff;
      FUN_100114f0(local_b14);
      DVar4 = local_abc;
      uVar6 = extraout_EDX_01;
    }
    else {
      local_268 = local_258;
      FUN_10007640(local_67c,0x208,local_268);
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
          FUN_100083b0((int)&local_28);
          local_b20 = local_24;
          local_8 = 0xd;
          FUN_10007b60(local_b20);
          local_8 = 0xffffffff;
          FUN_100114f0(local_b20);
          DVar4 = local_ac0;
          uVar6 = extraout_EDX_02;
          goto LAB_100074bf;
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
          uVar8 = FUN_10007760(local_24,L"Module",L"Module",(int)&local_aa0);
          local_b48 = (int)uVar8;
          local_b24 = (-(uint)(local_b48 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_10010d20(local_b3c);
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
        uVar8 = FUN_10007760(local_24,L"Module",L"Module",(int)local_67c);
        local_b70 = (int)uVar8;
        local_b4c = (-(uint)(local_b70 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8._0_1_ = 7;
        FUN_10010d20(local_b64);
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
        FUN_10007ca0(&local_28);
        DVar4 = local_ac4;
        uVar6 = extraout_EDX_03;
      }
      else {
        uVar8 = FUN_10007db0(local_67c,&local_28,(int)&local_28,0x10023a54,(int)local_67c);
        local_684 = (DWORD)uVar8;
        if ((int)local_684 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_ac8 = local_684;
          FUN_10010d20((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10007ca0(&local_28);
          DVar4 = local_ac8;
          uVar6 = extraout_EDX_04;
        }
        else {
          local_aac = L"REGISTRY";
          if (param_3 == 0) {
            uVar8 = FUN_100082c0(&local_28,local_268,param_2,L"REGISTRY");
            local_b7c[0] = (DWORD)uVar8;
          }
          else {
            uVar8 = FUN_10007ed0(&local_28,local_268,param_2,L"REGISTRY");
            local_b7c[0] = (DWORD)uVar8;
          }
          local_30 = local_b7c[0];
          local_acc = local_b7c[0];
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_10010d20((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10007ca0(&local_28);
          DVar4 = local_acc;
          uVar6 = extraout_EDX_05;
        }
      }
    }
  }
LAB_100074bf:
  uVar9 = (undefined2)DVar4;
  uVar10 = (undefined2)(DVar4 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100074f0);
  ExceptionList = local_10;
  return CONCAT44(uVar6,CONCAT22(uVar10,uVar9));
}



// Function: FUN_100075e0 at 100075e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD FUN_100075e0(void)

{
  undefined4 local_c;
  
  local_c = GetLastError();
  if (0 < (int)local_c) {
    local_c = local_c & 0xffff | 0x80070000;
  }
  return local_c;
}



// Function: FUN_10007640 at 10007640

void __cdecl FUN_10007640(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100076f0 at 100076f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100076f0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a608;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10007b60(param_1);
  local_8 = 0xffffffff;
  FUN_100114f0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007760 at 10007760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10007760(undefined4 param_1,undefined4 param_2,LPCWSTR param_3,int param_4)

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
  puStack_c = &LAB_1001a630;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffff78;
  puVar2 = local_7c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
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
    local_48 = FUN_1001832c(-(uint)((int)((ulonglong)local_20 * 2 >> 0x20) != 0) |
                            (uint)((ulonglong)local_20 * 2));
    local_24 = local_48;
    uVar3 = FUN_1000780c();
    return uVar3;
  }
  uVar4 = 0;
  ExceptionList = &pvStack_10;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007a60);
  ExceptionList = pvStack_10;
  return CONCAT44(param_2,uVar4);
}



// Function: Catch@100077ff at 100077ff

undefined4 Catch_100077ff(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007813;
}



// Function: FUN_1000780c at 1000780c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000780c(void)

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
  uVar3 = FUN_1001832c(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x48);
  uVar4 = FUN_10007890();
  return uVar4;
}



// Function: Catch@10007883 at 10007883

undefined4 Catch_10007883(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x10007897;
}



// Function: FUN_10007890 at 10007890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined8 FUN_10007890(void)

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
      FUN_100019e0(0x80004005);
      break;
    case 0xc:
      FUN_100019e0(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_100019e0(0x80070057);
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
      FUN_100019e0(0x80004005);
      break;
    case 0xc:
      FUN_100019e0(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_100019e0(0x80070057);
    }
    iVar2 = FUN_100112b0(*(void **)(unaff_EBP + -0x14),(undefined4 *)(unaff_EBP + -0x20),
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
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10007a60);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar4,uVar3);
}



// Function: FUN_10007b60 at 10007b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10007b60(int *param_1)

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
  FUN_100114f0(param_1);
  return 0;
}



// Function: FUN_10007c70 at 10007c70

undefined4 FUN_10007c70(void)

{
  return 0x80004001;
}



// Function: FUN_10007c80 at 10007c80

undefined4 FUN_10007c80(void)

{
  return 1;
}



// Function: FUN_10007c90 at 10007c90

undefined4 FUN_10007c90(void)

{
  return 0;
}



// Function: FUN_10007ca0 at 10007ca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10007ca0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a653;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_10007b60(param_1 + 1);
  local_8 = 1;
  FUN_10007b60(param_1 + 1);
  local_8 = 0xffffffff;
  FUN_100114f0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007d50 at 10007d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10007d50(void *this,uint param_1)

{
  FUN_10007ca0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007db0 at 10007db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10007db0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

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
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  ppuVar2 = &local_3c;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
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
    uVar3 = FUN_10007760(param_3 + 4,param_4,(LPCWSTR)param_4,param_5);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007e98);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_10007ed0 at 10007ed0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007ed0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

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
  
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  ppWVar3 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppWVar3 = (LPCWSTR)&DAT_cccccccc;
    ppWVar3 = ppWVar3 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  local_38[2] = param_4;
  ExceptionList = &local_10;
  uVar4 = FUN_10007fc0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (_Memory = local_28, uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20),
        local_38[1] = (LPCWSTR)uVar4, local_28 != (LPCWSTR)0x0) {
    local_38[0] = local_28;
    local_28 = *(LPCWSTR *)local_28;
    free(_Memory);
    uVar4 = CONCAT44(extraout_EDX,local_38[1]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007f94);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_38[1]);
}



// Function: FUN_10007fc0 at 10007fc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10007fc0(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
  
  puStack_c = &LAB_1001a693;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_488;
  for (iVar2 = 0x11d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (undefined4 *)&DAT_cccccccc;
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
    local_38 = FUN_100075e0();
  }
  else {
    local_50 = FindResourceW(local_4c,param_2,param_3);
    if (local_50 == (HRSRC)0x0) {
      local_38 = FUN_100075e0();
    }
    else {
      local_54 = LoadResource(local_4c,local_50);
      if (local_54 == (HGLOBAL)0x0) {
        local_38 = FUN_100075e0();
      }
      else {
        local_58 = SizeofResource(local_4c,local_50);
        local_5c = local_54;
        if (local_58 <= local_58 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10011760(&local_464,local_58 + 1);
          uVar5 = FUN_1000811f();
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
    FUN_100128f0(&local_464);
    puVar3 = extraout_EDX;
  }
  local_8 = 0xffffffff;
  while (_Memory = local_30, DVar1 = DStack_474, local_30 != (undefined4 *)0x0) {
    local_488[0] = local_30;
    local_30 = (undefined4 *)*local_30;
    free(_Memory);
    puVar3 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10008268);
  ExceptionList = pvStack_10;
  return CONCAT44(puVar3,DVar1);
}



// Function: Catch@10008112 at 10008112

undefined4 Catch_10008112(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10008126;
}



// Function: FUN_1000811f at 1000811f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000811f(void)

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
      DVar2 = FUN_100075e0();
      *(DWORD *)(unaff_EBP + -0x34) = DVar2;
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x460) + *(int *)(unaff_EBP + -0x46c) * 2) = 0;
      *(undefined4 *)(unaff_EBP + -0x47c) = *(undefined4 *)(unaff_EBP + -0x460);
      uVar3 = FUN_100083f0((int *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x47c),
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
    FUN_100128f0((undefined4 *)(unaff_EBP + -0x460));
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
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10008268);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(iVar1,uVar4);
}



// Function: FUN_100082c0 at 100082c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100082c0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

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
  
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  ppWVar3 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppWVar3 = (LPCWSTR)&DAT_cccccccc;
    ppWVar3 = ppWVar3 + 1;
  }
  local_18 = 3;
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  local_38[2] = param_4;
  ExceptionList = &local_10;
  uVar4 = FUN_10007fc0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (_Memory = local_28, uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20),
        local_38[1] = (LPCWSTR)uVar4, local_28 != (LPCWSTR)0x0) {
    local_38[0] = local_28;
    local_28 = *(LPCWSTR *)local_28;
    free(_Memory);
    uVar4 = CONCAT44(extraout_EDX,local_38[1]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10008384);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_38[1]);
}



// Function: FUN_100083b0 at 100083b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100083b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10007b60((int *)(param_1 + 4));
  return uVar1;
}



// Function: FUN_100083f0 at 100083f0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_100083f0(int *param_1,undefined4 param_2,LPCWSTR param_3,int param_4)

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
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2014 = 0;
  local_2018 = (LPVOID)0x0;
  local_8 = param_1;
  uVar3 = FUN_100089f0(param_1,param_2,param_3,&local_2018);
  local_2014 = (int)uVar3;
  if (-1 < local_2014) {
    *local_8 = (int)local_2018;
    while( true ) {
      if ((*(short *)*local_8 == 0) ||
         (local_2014 = FUN_10008720(local_8,local_200c), local_2014 < 0)) goto LAB_1000859f;
      local_201c = (HKEY)FUN_10008600(local_200c);
      if (local_201c == (HKEY)0x0) break;
      local_2014 = FUN_10008720(local_8,local_200c);
      if (local_2014 < 0) goto LAB_1000859f;
      if (local_200c[0] != L'{') {
        local_2014 = -0x7ffdfff7;
        goto LAB_1000859f;
      }
      if (param_4 == 0) {
        uVar3 = FUN_100096c0(local_8,local_200c,local_201c,0,0);
        local_2014 = (int)uVar3;
        if (local_2014 < 0) goto LAB_1000859f;
      }
      else {
        local_2020 = *local_8;
        uVar3 = FUN_100096c0(local_8,local_200c,local_201c,param_4,0);
        local_2014 = (int)uVar3;
        if (local_2014 < 0) {
          *local_8 = local_2020;
          FUN_100096c0(local_8,local_200c,local_201c,0,0);
          goto LAB_1000859f;
        }
      }
      FUN_10008670(local_8);
    }
    local_2014 = -0x7ffdfff7;
LAB_1000859f:
    CoTaskMemFree(local_2018);
    uVar3 = CONCAT44(extraout_EDX,local_2014);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100085e4);
  return uVar3;
}



// Function: FUN_10008600 at 10008600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __cdecl FUN_10008600(LPCWSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10023a98)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_10023a9c + local_8 * 8);
}



// Function: FUN_10008670 at 10008670

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10008670(undefined4 *param_1)

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



// Function: FUN_10008720 at 10008720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10008720(void *this,undefined2 *param_1)

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
    *piVar4 = (int)&DAT_cccccccc;
    piVar4 = piVar4 + 1;
  }
  local_8 = (int *)this;
  FUN_10008670((undefined4 *)this);
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



// Function: FUN_100089f0 at 100089f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_100089f0(int *param_1,undefined4 param_2,LPCWSTR param_3,undefined4 *param_4)

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
  puStack_c = &LAB_1001a6a8;
  local_10 = ExceptionList;
  peVar5 = &local_11c;
  for (iVar4 = 0x43; iVar4 != 0; iVar4 = iVar4 + -1) {
    *peVar5 = (errno_t)&DAT_cccccccc;
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
    FUN_10009150(&local_28,local_18);
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
        local_31 = DAT_1002cdb0;
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
                uVar6 = FUN_10009570(&local_28,local_40,local_40);
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
                  iVar4 = FUN_100092b0(&local_28,local_bc,1);
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
              uVar6 = FUN_10009570(&local_28,local_44,local_44);
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
              iVar4 = FUN_100092b0(&local_28,local_c4,1);
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
                FUN_100019e0(0x80004005);
                break;
              case 0xc:
                FUN_100019e0(0x8007000e);
                break;
              case 0x16:
              case 0x22:
                FUN_100019e0(0x80070057);
              }
              local_d4 = local_d0;
              local_f8 = local_94;
              local_f4 = local_14[1];
              local_e8 = (void *)(local_f4 + 4);
              local_ec = FUN_10012040(local_e8,&local_f8);
              if (local_ec == -1) {
                local_f0 = 0;
              }
              else {
                piVar3 = (int *)FUN_100115a0(local_e8,local_ec);
                local_f0 = *piVar3;
              }
              local_9c = local_f0;
              if (local_f0 == 0) {
                local_30 = -0x7ffdfff7;
                break;
              }
              uVar6 = FUN_10009570(&local_28,local_f0,(LPCWSTR)local_f0);
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
            iVar4 = FUN_100092b0(&local_28,local_110,1);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_100090c4);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar4);
}



// Function: FUN_10009150 at 10009150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10009150(void *this,int param_1)

{
  LPVOID pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = FUN_100091c0(*(uint *)((int)this + 4),2);
  *(LPVOID *)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined2 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_100091c0 at 100091c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10009205) */

LPVOID __cdecl FUN_100091c0(uint param_1,uint param_2)

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



// Function: FUN_10009270 at 10009270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009270(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100092b0 at 100092b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_100092b0(void *this,void *param_1,int param_2)

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
      pvVar3 = FUN_100094c0(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),2);
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
        FUN_100019e0(0x80004005);
        break;
      case 0xc:
        FUN_100019e0(0x8007000e);
        break;
      case 0x16:
      case 0x22:
        FUN_100019e0(0x80070057);
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



// Function: FUN_100094c0 at 100094c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10009505) */

LPVOID __cdecl FUN_100094c0(LPVOID param_1,uint param_2,uint param_3)

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



// Function: FUN_10009570 at 10009570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10009570(void *param_1,undefined4 param_2,LPCWSTR param_3)

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
  puStack_c = &LAB_1001a6c8;
  local_10 = ExceptionList;
  ppuVar4 = local_50;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)&DAT_cccccccc;
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
      local_3c = FUN_100092b0(local_14,local_34,iVar3);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009694);
  ExceptionList = local_10;
  return CONCAT44(param_2,uVar2);
}



// Function: FUN_100096c0 at 100096c0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100096c0(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  
  puStack_c = &LAB_1001a714;
  local_10 = ExceptionList;
  ppHVar5 = local_22f0;
  for (iVar3 = 0x8b8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppHVar5 = (HKEY)&DAT_cccccccc;
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
  local_248 = FUN_10008720(this,param_1);
  if (-1 < local_248) {
LAB_10009775:
    if (*param_1 == L'}') goto LAB_1000a174;
    local_240 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_24c = (uint)(iVar3 == 0);
    iVar3 = lstrcmpiW(param_1,L"ForceRemove");
    local_22f0[0] = (HKEY)0x100097cf;
    if ((iVar3 == 0) || (local_24c != 0)) {
      local_248 = FUN_10008720(local_14,param_1);
      if (local_248 < 0) goto LAB_1000a174;
      if (param_3 == 0) goto LAB_10009a3c;
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
          local_22f0[0] = (HKEY)0x1000989a;
        }
      }
      local_22d4 = local_22cc;
      if (local_22cc == (LPCWSTR)0x0) {
        for (local_22d8 = 0; local_22d8 < 0xc; local_22d8 = local_22d8 + 1) {
          iVar3 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10023650)[local_22d8]);
          if (iVar3 == 0) {
            local_22dc = 0;
            goto LAB_1000994b;
          }
        }
        local_22dc = 1;
LAB_1000994b:
        if (local_22dc != 0) {
          local_25c = param_2;
          local_258 = 0;
          local_254 = 0;
          FUN_1000aa10(&local_25c,param_1);
          local_22e0 = local_25c;
          local_25c = (HKEY)0x0;
          local_258 = 0;
          local_254 = 0;
        }
        if (local_24c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
          goto LAB_10009a3c;
        }
        local_248 = FUN_10008720(local_14,param_1);
        if (local_248 < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
        }
        else {
          uVar6 = FUN_1000b810(local_14,extraout_EDX_01,param_1);
          local_248 = (int)uVar6;
          if (-1 < local_248) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::CRegKey::Close((CRegKey *)&local_25c);
            goto LAB_1000a102;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_25c);
        }
        goto LAB_1000a174;
      }
      local_22b0 = -0x7ffdfff7;
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_25c);
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_24);
      iVar3 = local_22b0;
      uVar4 = extraout_EDX_00;
      goto LAB_1000a195;
    }
LAB_10009a3c:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_240 = 0;
      local_248 = FUN_10008720(local_14,param_1);
      if (local_248 < 0) goto LAB_1000a174;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 == 0) {
      local_248 = FUN_10008720(local_14,local_2264);
      if ((local_248 < 0) || (local_248 = FUN_10008720(local_14,param_1), local_248 < 0))
      goto LAB_1000a174;
      if (*param_1 != L'=') {
        local_22b4 = -0x7ffdfff7;
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22b4;
        uVar4 = extraout_EDX_02;
        goto LAB_1000a195;
      }
      if (param_3 != 0) {
        local_8._0_1_ = 2;
        local_2278 = param_2;
        local_2274 = 0;
        local_2270 = 0;
        uVar6 = FUN_1000ad00(local_14,&local_2278,local_2264,param_1);
        local_248 = (int)uVar6;
        local_22f0[3] = local_2278;
        local_2278 = (HKEY)0x0;
        local_2274 = 0;
        local_2270 = 0;
        if (-1 < local_248) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2278);
          goto LAB_1000a102;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        local_22b8 = local_248;
        ATL::CRegKey::Close((CRegKey *)&local_2278);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22b8;
        uVar4 = extraout_EDX_03;
        goto LAB_1000a195;
      }
      pWVar1 = param_1;
      if ((param_4 == 0) && (local_240 != 0)) {
        local_228c = (HKEY)0x0;
        local_2288 = 0;
        local_2284 = 0;
        local_8._0_1_ = 3;
        local_2c = FUN_1000a830(&local_228c,param_2,(LPCWSTR)0x0,0x20006);
        if (local_2c != 0) {
          local_248 = _HRESULT_FROM_WIN32(local_2c);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_228c);
          goto LAB_1000a174;
        }
        local_2c = RegDeleteValueW(local_228c,local_2264);
        if ((local_2c != 0) && (local_2c != 2)) {
          local_248 = _HRESULT_FROM_WIN32(local_2c);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_228c);
          goto LAB_1000a174;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_228c);
        pWVar1 = extraout_EDX_04;
      }
      uVar6 = FUN_1000b810(local_14,pWVar1,param_1);
      local_248 = (int)uVar6;
joined_r0x10009d0c:
      if (local_248 < 0) goto LAB_1000a174;
      goto LAB_10009775;
    }
    pWVar1 = FUN_1000ac90(param_1,L'\\');
    if (pWVar1 != (LPCWSTR)0x0) {
      local_22bc = -0x7ffdfff7;
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_24);
      iVar3 = local_22bc;
      uVar4 = extraout_EDX_05;
      goto LAB_1000a195;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_2c = FUN_1000a830(&local_24,param_2,param_1,0x20019);
      }
      else {
        local_2c = 2;
      }
      if (local_2c != 0) {
        param_4 = 1;
      }
      eVar2 = wcsncpy_s(local_238,0x104,param_1,0xffffffff);
      ATL::AtlCrtErrorCheck(eVar2);
      local_248 = FUN_10008720(local_14,param_1);
      if (local_248 < 0) goto LAB_1000a174;
      uVar6 = FUN_1000b810(local_14,param_1,param_1);
      local_248 = (int)uVar6;
      if (local_248 < 0) goto LAB_1000a174;
      if ((*param_1 == L'{') && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
        uVar6 = FUN_100096c0(local_14,param_1,local_24,0,param_4);
        local_248 = (int)uVar6;
        if (((local_248 < 0) && (param_4 == 0)) ||
           (local_248 = FUN_10008720(local_14,param_1), local_248 < 0)) goto LAB_1000a174;
      }
      param_4 = local_244;
      if (local_2c == 2) goto LAB_10009775;
      if (local_2c != 0) {
        if (local_244 == 0) goto LAB_10009f79;
        goto LAB_10009775;
      }
      if (local_244 != 0) {
        local_22f0[2] = local_24;
        uVar6 = FUN_1000b770(local_24);
        if ((int)uVar6 != 0) {
          iVar3 = FUN_1000b700(local_238);
          if ((iVar3 != 0) && (local_240 != 0)) {
            FUN_1000aa10(&local_24,local_238);
          }
          goto LAB_10009775;
        }
      }
      local_22f0[1] = local_24;
      uVar6 = FUN_1000b770(local_24);
      local_2294 = (int)uVar6;
      local_2c = ATL::CRegKey::Close((CRegKey *)&local_24);
      if (local_2c != 0) {
        local_22c4 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22c4;
        uVar4 = extraout_EDX_07;
        goto LAB_1000a195;
      }
      if ((local_240 != 0) && (local_2294 == 0)) {
        local_22a4 = (HKEY)0x0;
        local_22a0 = 0;
        local_229c = 0;
        local_8._0_1_ = 4;
        FUN_1000a3e0(&local_22a4,param_2);
        local_2c = FUN_1000a420(&local_22a4,local_238);
        local_22f0[0] = local_22a4;
        local_22a4 = (HKEY)0x0;
        local_22a0 = 0;
        local_229c = 0;
        if (local_2c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_22a4);
          goto LAB_1000a102;
        }
        local_248 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_22a4);
        goto LAB_1000a174;
      }
    }
    else {
      local_2c = FUN_1000a830(&local_24,param_2,param_1,0x2001f);
      if (((local_2c != 0) &&
          (local_2c = FUN_1000a830(&local_24,param_2,param_1,0x20019), local_2c != 0)) &&
         (local_2c = FUN_1000a650(&local_24,param_2,param_1,(LPWSTR)0x0,0,0x2001f,
                                  (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_2c != 0)) {
        local_22c0 = _HRESULT_FROM_WIN32(local_2c);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_24);
        iVar3 = local_22c0;
        uVar4 = extraout_EDX_06;
        goto LAB_1000a195;
      }
      local_248 = FUN_10008720(local_14,param_1);
      if (local_248 < 0) goto LAB_1000a174;
      if (*param_1 == L'=') {
        uVar6 = FUN_1000ad00(local_14,&local_24,(LPCWSTR)0x0,param_1);
        local_248 = (int)uVar6;
        if (local_248 < 0) goto LAB_1000a174;
      }
    }
LAB_1000a102:
    if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
      uVar6 = FUN_100096c0(local_14,param_1,local_24,param_3,0);
      local_248 = (int)uVar6;
      if (-1 < local_248) {
        local_248 = FUN_10008720(local_14,param_1);
        goto joined_r0x10009d0c;
      }
      goto LAB_1000a174;
    }
    goto LAB_10009775;
  }
  local_8 = 0xffffffff;
  local_22ac = local_248;
  ATL::CRegKey::Close((CRegKey *)&local_24);
  iVar3 = local_22ac;
  uVar4 = extraout_EDX;
LAB_1000a195:
  uVar7 = (undefined2)uVar4;
  uVar8 = (undefined2)((uint)uVar4 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a1c8);
  ExceptionList = local_10;
  return CONCAT26(uVar8,CONCAT24(uVar7,iVar3));
LAB_10009f79:
  local_248 = _HRESULT_FROM_WIN32(local_2c);
LAB_1000a174:
  local_22c8 = local_248;
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_24);
  iVar3 = local_22c8;
  uVar4 = extraout_EDX_08;
  goto LAB_1000a195;
}



// Function: AtlCrtErrorCheck at 1000a260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Library: Visual Studio 2012 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_100019e0(0x80004005);
    break;
  case 0xc:
    FUN_100019e0(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_100019e0(0x80070057);
  }
  return param_1;
}



// Function: _HRESULT_FROM_WIN32 at 1000a330

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



// Function: FUN_1000a370 at 1000a370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a370(int *param_1)

{
  if (*param_1 != 0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_1000a3e0 at 1000a3e0

void __thiscall FUN_1000a3e0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_1000a420 at 1000a420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000a420(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_1002d114 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1002d110 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_1002d114 = '\x01';
    }
    if (DAT_1002d110 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1002d110)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_1000a510(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_1000a510 at 1000a510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000a510(void *this,HKEY param_1,LPCWSTR param_2)

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
    uVar4 = 0x1000a54b;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0,0x1000a573,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: Close at 1000a5e0

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



// Function: FUN_1000a650 at 1000a650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000a650(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
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
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  local_10 = (HKEY)0x0;
  local_8 = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,&local_c)
    ;
    goto LAB_1000a79e;
  }
  local_20 = *(int **)((int)this + 8);
  local_2c = local_24;
  if (*local_20 == 0) {
    if (local_20[1] != 0) {
      local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,
                                 &local_c);
      goto LAB_1000a79e;
    }
  }
  else {
    local_18 = GetModuleHandleW(L"Advapi32.dll");
    uVar3 = 0x1000a6af;
    if (local_18 == (HMODULE)0x0) {
      local_2c = 1;
      goto LAB_1000a79e;
    }
    local_1c = GetProcAddress(local_18,"RegCreateKeyTransactedW");
    if (local_1c != (FARPROC)0x0) {
      local_2c = (*local_1c)(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,&local_c,
                             *local_20,0,0x1000a6dc,uVar3);
      goto LAB_1000a79e;
    }
  }
  local_2c = 1;
LAB_1000a79e:
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



// Function: FUN_1000a830 at 1000a830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000a830(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

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
    local_18 = FUN_1000a930(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_c);
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



// Function: FUN_1000a930 at 1000a930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000a930(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

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
    uVar4 = 0x1000a96b;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0,0x1000a996,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000aa10 at 1000aa10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_1000aa10(void *this,LPCWSTR param_1)

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
  
  puStack_c = &LAB_1001a728;
  local_10 = ExceptionList;
  pLVar4 = local_264;
  for (iVar2 = 0x95; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pLVar4 = (LSTATUS)&DAT_cccccccc;
    pLVar4 = pLVar4 + 1;
  }
  local_24 = (HKEY)0x0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  local_14 = this;
  LVar1 = FUN_1000a830(&local_24,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  local_2c = LVar1;
  if (LVar1 == 0) {
    do {
      local_40[0] = L'Ā';
      local_40[1] = L'\0';
      LVar1 = RegEnumKeyExW((HKEY)0x0,(DWORD)local_244,local_40,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPWSTR)0x0,local_38,unaff_EDI);
      hKey = (HKEY)0x1000ab0e;
      if (LVar1 != 0) {
        local_264[1] = 0;
        if (local_24 != (HKEY)0x0) {
          local_264[1] = RegCloseKey(local_24);
          hKey = (HKEY)0x1000abab;
          local_24 = (HKEY)0x0;
        }
        local_20 = 0;
        uVar5 = FUN_1000a420(local_14,param_1);
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
        goto LAB_1000ac15;
      }
      uVar5 = FUN_1000aa10(&local_24,local_244);
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
LAB_1000ac15:
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  local_250 = (int)uVar5;
  local_20 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ac48);
  ExceptionList = local_10;
  return CONCAT44(uVar3,iVar2);
}



// Function: FUN_1000ac90 at 1000ac90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCWSTR __cdecl FUN_1000ac90(LPWSTR param_1,WCHAR param_2)

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



// Function: FUN_1000ad00 at 1000ad00

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall
FUN_1000ad00(void *this,undefined4 *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  undefined4 *_Memory;
  LPWSTR pWVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint uVar4;
  undefined4 extraout_EDX_02;
  uint extraout_EDX_03;
  uint extraout_EDX_04;
  uint *puVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
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
  puStack_c = &LAB_1001a761;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffdd48;
  puVar5 = local_22ac;
  for (iVar3 = 0x8a6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = (uint)&DAT_cccccccc;
    puVar5 = puVar5 + 1;
  }
  local_2028[0] = 0;
  local_202c = 0;
  local_2030 = 0;
  ExceptionList = &pvStack_10;
  local_18 = (undefined4 *)this;
  iVar3 = FUN_10008720(this,local_2020);
  uVar4 = extraout_EDX;
  local_1c = iVar3;
  if (-1 < iVar3) {
    iVar3 = FUN_1000b4d0(local_2020,local_2028);
    if (iVar3 == 0) {
      iVar3 = -0x7ffdfff7;
      uVar4 = extraout_EDX_00;
    }
    else {
      while (iVar3 = FUN_1000b690(*(undefined2 *)*local_18), iVar3 != 0) {
        pWVar1 = CharNextW((LPCWSTR)*local_18);
        *local_18 = pWVar1;
      }
      iVar3 = FUN_10008720(local_18,local_2020);
      uVar4 = extraout_EDX_01;
      local_1c = iVar3;
      if (-1 < iVar3) {
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
              iVar3 = lstrlenW(local_2020);
              local_202c = RegSetValueExW((HKEY)*param_1,param_2,0,1,(BYTE *)local_2020,
                                          iVar3 * 2 + 2);
            }
          }
          else if (local_22ac[1] == 0x11) {
            uStack_2174 = lstrlenW(local_2020);
            uVar4 = uStack_2174 & 1;
            if (uVar4 == 0) {
              uStack_2178 = (int)uStack_2174 / 2;
              auStack_2280[0] = 0;
              local_8 = 5;
              puVar2 = FUN_10012cb0(uStack_2178,1);
              FUN_10012940(auStack_2280,(uint)puVar2);
              uVar6 = FUN_1000b1e2(extraout_ECX,extraout_EDX_02);
              return uVar6;
            }
            iVar3 = -0x7fffbffb;
            goto LAB_1000b36c;
          }
        }
        else if (local_22ac[1] == 0x4008) {
          iVar3 = lstrlenW(local_2020);
          local_2034 = iVar3 + 2;
          local_213c[0] = 0;
          local_8 = 1;
          puVar2 = FUN_10012cb0(local_2034,2);
          FUN_10012940(local_213c,(uint)puVar2);
          uVar6 = FUN_1000af17();
          return uVar6;
        }
        if (local_202c == 0) {
          local_1c = FUN_10008720(local_18,param_3);
          iVar3 = local_1c;
          uVar4 = extraout_EDX_04;
          if (-1 < local_1c) {
            iVar3 = 0;
          }
        }
        else {
          local_2030 = 0x204;
          iVar3 = _HRESULT_FROM_WIN32(local_202c);
          uVar4 = extraout_EDX_03;
        }
      }
    }
  }
LAB_1000b36c:
  uVar7 = (undefined2)uVar4;
  uVar8 = (undefined2)(uVar4 >> 0x10);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b3a0);
  ExceptionList = pvStack_10;
  return CONCAT26(uVar8,CONCAT24(uVar7,iVar3));
}



// Function: Catch@1000af0a at 1000af0a

undefined4 Catch_1000af0a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000af1e;
}



// Function: FUN_1000af17 at 1000af17

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000af17(void)

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
    LVar2 = FUN_1000b410(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                         *(BYTE **)(unaff_EBP + -0x2290));
    *(LSTATUS *)(unaff_EBP + -0x2028) = LVar2;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x2138) != unaff_EBP + -0x2134) {
    FUN_100128f0((undefined4 *)(unaff_EBP + -0x2138));
  }
  if (*(int *)(unaff_EBP + -0x2028) == 0) {
    uVar4 = FUN_10008720(*(void **)(unaff_EBP + -0x14),*(undefined2 **)(unaff_EBP + 0x10));
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
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000b3a0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar4,HVar3);
}



// Function: Catch@1000b1d5 at 1000b1d5

undefined4 Catch_1000b1d5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x1000b1e9;
}



// Function: FUN_1000b1e2 at 1000b1e2

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000b1e2(undefined4 param_1,undefined4 param_2)

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
      FUN_100128f0((undefined4 *)(unaff_EBP + -0x227c));
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
      uVar1 = FUN_1000b5f0(*(ushort *)(unaff_EBP + -0x201c + *(int *)(unaff_EBP + -0x2284) * 2));
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
      FUN_100128f0((undefined4 *)(unaff_EBP + -0x227c));
    }
    if (*(int *)(unaff_EBP + -0x2028) == 0) {
      uVar4 = FUN_10008720(*(void **)(unaff_EBP + -0x14),*(undefined2 **)(unaff_EBP + 0x10));
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
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000b3a0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT26(uVar6,CONCAT24(uVar5,HVar3));
}



// Function: FUN_1000b410 at 1000b410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000b410(void *this,LPCWSTR param_1,BYTE *param_2)

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
      L"삃褁\xf045䖋诰\xf84dᒍ襁\xf855䖋诰\xf44dᒍ襁\xf455綃ǰ쥵\xf48b䖋僴䶋儌ݪj喋刈䖋诼儈ᗿ〄ဂ\xf43b軨Î帀쒃㬔\xe8ec캃"
      ;
      local_10 = local_10 + (iVar2 + 1) * 2;
    } while (iVar2 + 1 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExW(*this,param_1,0,7,param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_1000b4d0 at 1000b4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000b4d0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a77e;
  local_10 = ExceptionList;
  if ((DAT_1002d138 & 1) == 0) {
    DAT_1002d138 = DAT_1002d138 | 1;
    _DAT_1002d118 = &DAT_1002355c;
    _DAT_1002d11c = 8;
    _DAT_1002d120 = &DAT_10023558;
    _DAT_1002d124 = 0x4008;
    _DAT_1002d128 = &DAT_10023554;
    _DAT_1002d12c = 0x13;
    _DAT_1002d130 = &DAT_10023550;
    _DAT_1002d134 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  ExceptionList = &local_10;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,*(LPCWSTR *)(&DAT_1002d118 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_1002d11c + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000b5f0 at 1000b5f0

uint __cdecl FUN_1000b5f0(ushort param_1)

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



// Function: FUN_1000b690 at 1000b690

undefined4 FUN_1000b690(undefined2 param_1)

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



// Function: FUN_1000b700 at 1000b700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000b700(LPCWSTR param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xb < local_c) {
      return 1;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10023650)[local_c]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_1000b770 at 1000b770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000b770(HKEY param_1)

{
  LSTATUS LVar1;
  uint uVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  DWORD local_10;
  undefined1 *local_c;
  
  local_c = &DAT_cccccccc;
  local_10 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_10,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 == 0) {
    uVar3 = 0;
    uVar2 = (uint)(local_10 != 0);
  }
  else {
    uVar2 = 0;
    uVar3 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b7f0);
  return CONCAT44(uVar3,uVar2);
}



// Function: FUN_1000b810 at 1000b810

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000b810(undefined4 *param_1,undefined4 param_2,short *param_3)

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
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  if (*param_3 == 0x3d) {
    iVar1 = FUN_10008720(param_1,param_3);
    param_2 = extraout_EDX;
    local_c = iVar1;
    if (iVar1 < 0) goto LAB_1000b89b;
    FUN_10008670(local_8);
    iVar1 = FUN_10008720(local_8,local_2010);
    param_2 = extraout_EDX_00;
    local_c = iVar1;
    if ((iVar1 < 0) ||
       (iVar1 = FUN_10008720(local_8,param_3), param_2 = extraout_EDX_01, local_c = iVar1, iVar1 < 0
       )) goto LAB_1000b89b;
  }
  iVar1 = 0;
LAB_1000b89b:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b8c0);
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_1000b8e0 at 1000b8e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000b8e0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_1000b950 at 1000b950

undefined4 FUN_1000b950(void)

{
  return 0;
}



// Function: FUN_1000b960 at 1000b960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000b960(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a7ae;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_40;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
    FUN_1000bbb0(local_24 + 1);
    *local_24 = ATL::CComClassFactory::vftable;
    *local_24 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
    local_40[1] = local_24;
  }
  local_20 = local_40[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_40[1];
  uVar1 = FUN_1000ba2d();
  return uVar1;
}



// Function: Catch@1000ba20 at 1000ba20

undefined4 Catch_1000ba20(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ba34;
}



// Function: FUN_1000ba2d at 1000ba2d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ba2d(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x24) = *(undefined4 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x30));
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



// Function: FUN_1000bb20 at 1000bb20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_1000bb20(LPCRITICAL_SECTION param_1)

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



// Function: FUN_1000bbb0 at 1000bbb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000bbb0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  memset(param_1 + 1,0,0x18);
  *(undefined1 *)(param_1 + 7) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bc40 at 1000bc40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000bc40(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_1000e950(0,param_2,param_3);
  }
  else {
    local_8 = FUN_1000eb30(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000bc90 at 1000bc90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000bc90(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_1000ecb0(0,param_2,param_3);
  }
  else {
    local_8 = FUN_1000ee90(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000bce0 at 1000bce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000bce0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_1000f010(0,param_2,param_3);
  }
  else {
    local_8 = FUN_1000f310(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000bd30 at 1000bd30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000bd30(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_1000f480(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10010580(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000bd80 at 1000bd80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000bd80(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_10010740(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10010b20(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000bdd0 at 1000bdd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000bdd0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_10;
  int *local_c;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1002d0fc = *param_3;
    DAT_1002d100 = param_3[1];
    DAT_1002d104 = param_3[2];
    DAT_1002d108 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_10 = DAT_1002dc5c; local_10 < DAT_1002dc60; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_1000bec0 at 1000bec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000bec0(int param_1)

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
  for (local_10 = DAT_1002dc5c; local_10 < DAT_1002dc60; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(0);
    }
  }
  FUN_1000bfa0(param_1);
  return;
}



// Function: FUN_1000bfa0 at 1000bfa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000bfa0(int param_1)

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
      FUN_1000e320(local_c);
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



// Function: FUN_1000c050 at 1000c050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000c161) */
/* WARNING: Removing unreachable block (ram,0x1000c17a) */

undefined8 __fastcall
FUN_1000c050(int *param_1,int *param_2,int *param_3,undefined4 param_4,int *param_5)

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
  puStack_c = &LAB_1001a7f8;
  local_10 = ExceptionList;
  piVar3 = local_5c;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = (int)&DAT_cccccccc;
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
            FUN_10012a60(&local_28,&DAT_1002dc64,'\0');
            local_8 = 0;
            local_38 = local_28;
            EnterCriticalSection(local_28);
            param_1 = (int *)0x1000c154;
            local_3c = 0;
            local_24 = 1;
            local_18 = 0;
            if (local_1c[4] == 0) {
              local_18 = (*(code *)local_1c[2])(local_1c[3],&PTR_10023d54,local_1c + 4,0x1000c154);
              param_1 = (int *)0x1000c1b8;
            }
            local_8 = 0xffffffff;
            FUN_10012b00(&local_28);
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
    uVar4 = FUN_1000e0c0(param_3,param_5,(int *)&DAT_1002dc54,param_3,param_4,param_5);
  }
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  local_18 = (int)uVar4;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_1000c264);
  ExceptionList = local_10;
  return CONCAT44(uVar2,local_18);
}



// Function: FUN_1000c280 at 1000c280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000c280(void *this,int param_1,void *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *_Buf2;
  int *local_10;
  int local_c;
  
  puVar3 = &DAT_cccccccc;
  puVar4 = &DAT_cccccccc;
  puVar5 = &DAT_cccccccc;
  puVar6 = &DAT_cccccccc;
  puVar7 = &DAT_cccccccc;
  _Buf2 = &DAT_cccccccc;
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if (param_2 == (void *)0x0) {
LAB_1000c302:
        local_c = (*(code *)local_10[1])(1);
        if (local_c < 0) break;
        uVar2 = (*(code *)local_10[7])(1,0x1000c315,puVar3,puVar4,puVar5,puVar6,puVar7,_Buf2);
        uVar2 = FUN_1000c3c0(*local_10,(int *)((ulonglong)uVar2 >> 0x20),(GUID *)*local_10,
                             (int *)uVar2,0x1000c333);
        local_c = (int)uVar2;
        if (local_c < 0) break;
      }
      else {
        _Buf2 = (undefined1 *)*local_10;
        iVar1 = memcmp(param_2,_Buf2,0x10);
        if (iVar1 == 0) goto LAB_1000c302;
      }
    }
  }
  if (((-1 < local_c) && (local_c = FUN_1000cf70(0x1002dc54,param_1,param_2), -1 < local_c)) &&
     (DAT_1002d0f0 != (code *)0x0)) {
    local_c = (*DAT_1002d0f0)(DAT_1002dc20);
  }
  return local_c;
}



// Function: FUN_1000c3c0 at 1000c3c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000c42b) */

undefined8 __fastcall
FUN_1000c3c0(undefined4 param_1,int *param_2,GUID *param_3,int *param_4,int param_5)

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
  
  puStack_c = &LAB_1001a869;
  local_10 = ExceptionList;
  puVar5 = (undefined4 *)&stack0xfffffd70;
  for (iVar4 = 0xa0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = &DAT_cccccccc;
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
      ~CComPtrBase<>((int *)local_18);
      local_220 = (int *)0x0;
      param_2 = extraout_EDX;
    }
    else {
      ExceptionList = &local_10;
      local_20 = (int *)CoCreateInstance((IID *)&DAT_100247fc,(LPUNKNOWN)0x0,1,(IID *)&DAT_10023dd0,
                                         local_18);
      pWVar7 = (LPCWSTR)0x1000c4ef;
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
              pWVar7 = (LPCWSTR)0x1000c667;
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
              pWVar7 = (LPCWSTR)0x1000c5b0;
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
              goto LAB_1000cca3;
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
              FUN_100019e0(0x80004005);
              break;
            case 0xc:
              FUN_100019e0(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_100019e0(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,L"\\Required Categories");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_100019e0(0x80004005);
              break;
            case 0xc:
              FUN_100019e0(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_100019e0(0x80070057);
            }
            local_1fc = (HKEY)0x80000000;
            local_1f8 = 0;
            local_1f4 = 0;
            local_210 = (HKEY)0x0;
            local_20c = 0;
            local_208 = 0;
            local_8 = CONCAT31(local_8._1_3_,8);
            local_218[0] = 0;
            LVar3 = FUN_1000a830(&local_210,(HKEY)0x80000000,local_1e8,0x20019);
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
                FUN_1000a420(&local_1fc,local_1e8);
              }
            }
            eVar2 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_100019e0(0x80004005);
              break;
            case 0xc:
              FUN_100019e0(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_100019e0(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,local_e4);
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_100019e0(0x80004005);
              break;
            case 0xc:
              FUN_100019e0(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_100019e0(0x80070057);
            }
            eVar2 = wcscat_s(local_1e8,0x80,L"\\Implemented Categories");
            switch(eVar2) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_100019e0(0x80004005);
              break;
            case 0xc:
              FUN_100019e0(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_100019e0(0x80070057);
            }
            pWVar7 = local_1e8;
            LVar3 = FUN_1000a830(&local_210,local_1fc,pWVar7,0x20019);
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
                FUN_1000a420(&local_1fc,local_1e8);
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
LAB_1000cca3:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_1000ccd4);
  ExceptionList = local_10;
  return CONCAT44(param_2,local_220);
}



// Function: FUN_1000cf70 at 1000cf70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000cf70(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *_Buf2;
  int *local_c;
  int local_8;
  
  puVar5 = &DAT_cccccccc;
  puVar6 = &DAT_cccccccc;
  puVar7 = &DAT_cccccccc;
  puVar8 = &DAT_cccccccc;
  _Buf2 = &DAT_cccccccc;
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
          _Buf2 = (undefined1 *)*puVar1;
          iVar2 = memcmp(param_3,_Buf2,0x10);
          if (iVar2 != 0) goto LAB_1000cfb6;
        }
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        piVar3 = (int *)(*(code *)puVar1[7])(1,0x1000d01c,puVar5,puVar6,puVar7,puVar8,_Buf2);
        uVar4 = FUN_1000c3c0(puVar1,(int *)*puVar1,(GUID *)*puVar1,piVar3,0x1000d03a);
        local_8 = (int)uVar4;
        if (local_8 < 0) break;
      }
LAB_1000cfb6:
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      uVar4 = FUN_1000d090(*(HMODULE *)(param_1 + 4),(int *)0x0);
      local_8 = (int)uVar4;
    }
  }
  return local_8;
}



// Function: FUN_1000d090 at 1000d090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000d090(HMODULE param_1,int *param_2)

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
  
  puStack_c = &LAB_1001a8b3;
  local_10 = ExceptionList;
  ppiVar3 = local_274;
  for (iVar2 = 0x99; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_18[0] = 0;
  local_24[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  uVar4 = FUN_1000d440(local_18,param_2,param_1,(LPCWSTR)param_2,local_18,local_24);
  local_2c = (int)uVar4;
  if (-1 < local_2c) {
    local_30 = (wchar_t *)0x0;
    local_248[0] = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    local_274[0] = local_24[0];
    local_2c = (**(code **)(*local_24[0] + 0x24))(local_24[0],0xffffffff,0,0,0,local_248);
    uVar5 = 0x1000d14b;
    if ((-1 < local_2c) && (local_248[0] != (wchar_t *)0x0)) {
      local_264 = Ordinal_7(local_248[0],0x1000d14b);
      local_268 = local_248[0];
      eVar1 = wcsncpy_s(local_23c,0x104,local_248[0],local_264);
      uVar5 = 0x1000d1cd;
      ATL::AtlCrtErrorCheck(eVar1);
      local_36 = 0;
      iVar2 = FUN_1000db60(local_23c);
      local_23c[iVar2] = L'\0';
      local_30 = local_23c;
    }
    local_250 = (FARPROC)0x0;
    local_251 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x251) {
      local_2c = -0x7fffbffd;
    }
    else {
      local_251 = DAT_1002cdb0;
      local_2c = 0;
    }
    if (local_2c < 0) {
      local_25c = local_2c;
      local_8._0_1_ = 2;
      Ordinal_6(local_248[0],uVar5);
      uVar5 = 0x1000d25b;
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_24[0] != (int *)0x0) {
        (**(code **)(*local_24[0] + 8))(local_24[0],0x1000d25b);
        uVar5 = 0x1000d280;
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_18[0],uVar5);
      iVar2 = local_25c;
      uVar5 = extraout_EDX;
      goto LAB_1000d3a7;
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
    Ordinal_6(local_248[0],0x1000d33c);
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
LAB_1000d3a7:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000d3d8);
  ExceptionList = local_10;
  return CONCAT44(uVar5,iVar2);
}



// Function: FUN_1000d440 at 1000d440

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000d546) */

undefined8 __fastcall
FUN_1000d440(undefined4 param_1,int *param_2,HMODULE param_3,LPCWSTR param_4,int *param_5,
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
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  peVar4 = local_2c4;
  for (iVar3 = 0xad; iVar3 != 0; iVar3 = iVar3 + -1) {
    *peVar4 = (errno_t)&DAT_cccccccc;
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
    uVar7 = 0x1000d4ce;
    if (local_254 == (int *)0x0) {
      local_284 = FUN_100075e0();
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
      local_258 = FUN_1000dac0(local_24c);
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
          goto LAB_1000d96d;
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
          goto LAB_1000d96d;
        }
        local_2c4[1] = wcscpy_s(local_24c + (int)local_254,0x10e - (int)local_254,local_25c);
        local_2ac = local_2c4[1];
        switch(local_2c4[1]) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_100019e0(0x80004005);
          break;
        case 0xc:
          FUN_100019e0(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_100019e0(0x80070057);
        }
      }
      local_268 = local_24c;
      uVar5 = Ordinal_161(local_268,param_6);
      local_26c = (DWORD)uVar5;
      uVar6 = 0x1000d795;
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
          goto LAB_1000d96d;
        }
        local_2c4[0] = wcscpy_s(local_258,0x10e - ((int)local_258 - (int)local_24c >> 1),local_27c);
        uVar6 = 0x1000d86d;
        local_2b4 = local_2c4[0];
        switch(local_2c4[0]) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_100019e0(0x80004005);
          break;
        case 0xc:
          FUN_100019e0(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_100019e0(0x80070057);
        }
        local_268 = local_24c;
        uVar5 = Ordinal_161(local_268,param_6,uVar6);
        uVar6 = 0x1000d8e6;
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
LAB_1000d96d:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000d9a0);
  ExceptionList = local_10;
  return CONCAT44(param_2,DVar2);
}



// Function: FUN_1000dac0 at 1000dac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCWSTR __cdecl FUN_1000dac0(LPWSTR param_1)

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



// Function: FUN_1000db60 at 1000db60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000db60(LPWSTR param_1)

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



// Function: FUN_1000dc00 at 1000dc00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000dc00(void *this,int param_1,void *param_2)

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
        uVar3 = FUN_1000c3c0(local_10,(int *)*local_10,(GUID *)*local_10,piVar2,0x1000dc95);
        local_c = (int)uVar3;
        if ((local_c < 0) || (local_c = (*(code *)local_10[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_28 = 0;
    if (DAT_1002d0f4 != (code *)0x0) {
      local_28 = (*DAT_1002d0f4)();
    }
    if (-1 < local_28) {
      local_28 = FUN_1000dd30(0x1002dc54,param_1,param_2);
    }
    local_c = local_28;
  }
  return local_c;
}



// Function: FUN_1000dd30 at 1000dd30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000dd30(int param_1,int param_2,void *param_3)

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
        uVar4 = FUN_1000c3c0(extraout_ECX,piVar1,(GUID *)*piVar1,piVar3,0x1000dddc);
        local_8 = (int)uVar4;
        if ((local_8 < 0) || (local_8 = (*(code *)piVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      uVar4 = FUN_1000de50(*(HMODULE *)(param_1 + 4),(int *)0x0);
      local_8 = (int)uVar4;
    }
  }
  return local_8;
}



// Function: FUN_1000de50 at 1000de50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000de50(HMODULE param_1,int *param_2)

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
  
  puStack_c = &LAB_1001a8e8;
  local_10 = ExceptionList;
  ppiVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)&DAT_cccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_18[0] = 0;
  local_24[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  uVar3 = FUN_1000d440(local_18,param_2,param_1,(LPCWSTR)param_2,local_18,local_24);
  local_2c = (int)uVar3;
  if (-1 < local_2c) {
    local_4c[1] = local_24[0];
    local_2c = (**(code **)(*local_24[0] + 0x1c))(local_24[0],&local_30);
    uVar4 = 0x1000dedc;
    if (-1 < local_2c) {
      local_34 = (FARPROC)0x0;
      local_35 = '\0';
      if (&stack0x00000000 == (undefined1 *)0x35) {
        local_2c = -0x7fffbffd;
      }
      else {
        local_35 = DAT_1002cdb0;
        local_2c = 0;
      }
      if (local_2c < 0) {
        local_40 = local_2c;
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_24[0] != (int *)0x0) {
          (**(code **)(*local_24[0] + 8))(local_24[0]);
          uVar4 = 0x1000df45;
        }
        local_8 = 0xffffffff;
        Ordinal_6(local_18[0],uVar4);
        iVar1 = local_40;
        uVar4 = extraout_EDX;
        goto LAB_1000e051;
      }
      if (local_35 == '\x01') {
        local_3c = GetModuleHandleW(L"OLEAUT32.DLL");
        uVar4 = 0x1000df84;
        if (local_3c != (HMODULE)0x0) {
          local_34 = GetProcAddress(local_3c,"UnRegisterTypeLibForUser");
          uVar4 = 0x1000dfa5;
        }
      }
      if (local_34 == (FARPROC)0x0) {
        local_34 = Ordinal_186_exref;
      }
      local_2c = (*local_34)(local_30,(uint)*(ushort *)(local_30 + 0x18),
                             (uint)*(ushort *)(local_30 + 0x1a),*(undefined4 *)(local_30 + 0x10),
                             *(undefined4 *)(local_30 + 0x14),uVar4);
      local_4c[0] = local_24[0];
      (**(code **)(*local_24[0] + 0x30))(local_24[0],local_30,0x1000dfe5);
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
LAB_1000e051:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000e080);
  ExceptionList = local_10;
  return CONCAT44(uVar4,iVar1);
}



// Function: FUN_1000e0c0 at 1000e0c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000e215) */
/* WARNING: Removing unreachable block (ram,0x1000e22e) */

undefined8 __fastcall
FUN_1000e0c0(undefined4 param_1,int *param_2,int *param_3,int *param_4,undefined4 param_5,
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
  puStack_c = &LAB_1001a7f8;
  local_10 = ExceptionList;
  piVar2 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
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
              FUN_10012a60(&local_28,param_3 + 4,'\0');
              local_8 = 0;
              local_38 = local_28;
              EnterCriticalSection(local_28);
              local_48[3] = 0;
              local_24 = 1;
              local_14 = 0;
              if (local_1c[4] == 0) {
                local_14 = (*(code *)local_1c[2])(local_1c[3],&PTR_10023d54,local_1c + 4,0x1000e208)
                ;
              }
              local_8 = 0xffffffff;
              FUN_10012b00(&local_28);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000e2fc);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_1000e320 at 1000e320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e320(int param_1)

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



// Function: FUN_1000e3d0 at 1000e3d0

void FUN_1000e3d0(void)

{
  return;
}



// Function: FUN_1000e3e0 at 1000e3e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000e3e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a92e;
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



// Function: FUN_1000e4a0 at 1000e4a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e4a0(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_1000e560 at 1000e560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e560(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1002d0f8 + 8))();
  }
  else {
    (**(code **)(*DAT_1002d0f8 + 4))();
  }
  return 0;
}



// Function: FUN_1000e5c0 at 1000e5c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000e5c0(void *this,uint param_1)

{
  FUN_1000e3e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e610 at 1000e610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_1000e610(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1002d0f8 + 4))(0x1000e63a);
  }
  return LVar1;
}



// Function: FUN_1000e680 at 1000e680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_1000e680(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1002d0f8 + 8))(0x1000e6ae);
  }
  return LVar1;
}



// Function: FUN_1000e730 at 1000e730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000e730(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_10023e3c,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000e770 at 1000e770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000e770(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
LAB_1000e8a6:
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
          if (bVar1) goto LAB_1000e8a6;
        }
      }
      iVar2 = -0x7fffbffe;
    }
  }
  return iVar2;
}



// Function: FUN_1000e950 at 1000e950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e950(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a948;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_20 = (undefined4 *)operator_new(0x88);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_10001000((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CDataPlate>::vftable;
    (**(code **)(*DAT_1002d0f8 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_1000ea1e();
  return uVar1;
}



// Function: Catch@1000ea11 at 1000ea11

undefined4 Catch_1000ea11(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ea25;
}



// Function: FUN_1000ea1e at 1000ea1e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ea1e(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x1000ea4d;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
    *(DWORD *)(unaff_EBP + -0x30) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x30)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x2c) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10001410(*(int *)(unaff_EBP + -0x18));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
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
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x24))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_1000eb30 at 1000eb30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000eb30(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a96b;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_24 = operator_new(0x94);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10010e50(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_1000ebe0();
  return uVar1;
}



// Function: Catch@1000ebd3 at 1000ebd3

undefined4 Catch_1000ebd3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ebe7;
}



// Function: FUN_1000ebe0 at 1000ebe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ebe0(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10010f20(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10001410(*(int *)(unaff_EBP + -0x18) + 0xc);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
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



// Function: FUN_1000ecb0 at 1000ecb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ecb0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a988;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_20 = (undefined4 *)operator_new(0x2c);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_100056e0((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CDataPlateGroup>::vftable;
    (**(code **)(*DAT_1002d0f8 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_1000ed7b();
  return uVar1;
}



// Function: Catch@1000ed6e at 1000ed6e

undefined4 Catch_1000ed6e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ed82;
}



// Function: FUN_1000ed7b at 1000ed7b

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ed7b(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x1000edaa;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
    *(DWORD *)(unaff_EBP + -0x30) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x30)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x2c) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x30);
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_100058b0(*(int *)(unaff_EBP + -0x18));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
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



// Function: FUN_1000ee90 at 1000ee90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ee90(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a9ab;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_24 = operator_new(0x38);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10011180(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_1000ef3d();
  return uVar1;
}



// Function: Catch@1000ef30 at 1000ef30

undefined4 Catch_1000ef30(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ef44;
}



// Function: FUN_1000ef3d at 1000ef3d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ef3d(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10010f20(*(int *)(unaff_EBP + -0x18));
    *(DWORD *)(unaff_EBP + -0x14) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_100058b0(*(int *)(unaff_EBP + -0x18) + 0xc);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
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



// Function: FUN_1000f010 at 1000f010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f010(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001a9c8;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_20 = (undefined4 *)operator_new(0x34);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_10005c50((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CDataPlateGroups>::vftable;
    (**(code **)(*DAT_1002d0f8 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_1000f0db();
  return uVar1;
}



// Function: Catch@1000f0ce at 1000f0ce

undefined4 Catch_1000f0ce(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000f0e2;
}



// Function: FUN_1000f0db at 1000f0db

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f0db(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x1000f10a;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
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



// Function: FUN_1000f1f0 at 1000f1f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000f1f0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a9e8;
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
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FUN_1000f2b0);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000f2b0 at 1000f2b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000f2b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a9e8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  Ordinal_6(*param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f310 at 1000f310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f310(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001aa0b;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_24 = operator_new(0x40);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10011690(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_1000f3bd();
  return uVar1;
}



// Function: Catch@1000f3b0 at 1000f3b0

undefined4 Catch_1000f3b0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000f3c4;
}



// Function: FUN_1000f3bd at 1000f3bd

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f3bd(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10010f20(*(int *)(unaff_EBP + -0x18));
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



// Function: FUN_1000f480 at 1000f480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f480(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001aa28;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_20 = (undefined4 *)operator_new(0x44);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_10014d30((int)local_20);
    local_8._0_1_ = 1;
    *local_20 = ATL::CComObject<class_CDataPlateParameter>::vftable;
    local_20[1] = ATL::CComObject<class_CDataPlateParameter>::vftable;
    (**(code **)(*DAT_1002d0f8 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_1000f554();
  return uVar1;
}



// Function: Catch@1000f547 at 1000f547

undefined4 Catch_1000f547(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000f55b;
}



// Function: FUN_1000f554 at 1000f554

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f554(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 8));
    uStack00000004 = 0x1000f583;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 0xc;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
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
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x2c))(1);
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: GetTypeInfoCount at 1000f660

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



// Function: FUN_1000f680 at 1000f680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f680(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 local_20;
  
  if (param_2 == 0) {
    local_20 = FUN_1000f7e0(&PTR_DAT_1002c850,param_3,param_4);
  }
  else {
    local_20 = 0x8002000b;
  }
  return local_20;
}



// Function: FUN_1000f6e0 at 1000f6e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f6e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000f880(&PTR_DAT_1002c850,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000f730 at 1000f730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4
FUN_1000f730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined8 uVar1;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 0;
  if ((DAT_1002c85c == (int *)0x0) || (DAT_1002c864 == 0)) {
    uVar1 = FUN_1000f9f0(&PTR_DAT_1002c850,param_4);
    local_24 = (undefined4)uVar1;
  }
  local_20 = local_24;
  if (DAT_1002c85c != (int *)0x0) {
    local_20 = (**(code **)(*DAT_1002c85c + 0x2c))
                         (DAT_1002c85c,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return local_20;
}



// Function: FUN_1000f7e0 at 1000f7e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000f7e0(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_1000f9f0(this,param_1);
      local_c = (undefined4)uVar1;
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_1000f880 at 1000f880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall
FUN_1000f880(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int local_18;
  int local_14;
  int local_c;
  
  local_18 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar3 = FUN_1000f9f0(this,param_4);
    local_18 = (int)uVar3;
  }
  local_c = local_18;
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar1 = lstrlenW((LPCWSTR)*param_2);
      local_14 = *(int *)((int)this + 0x18);
      do {
        local_14 = local_14 + -1;
        if (local_14 < 0) goto LAB_1000f9a8;
      } while ((iVar1 != *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc)) ||
              (iVar2 = memcmp(*(void **)(local_14 * 0xc + *(int *)((int)this + 0x14)),
                              (void *)*param_2,
                              *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc) << 1),
              iVar2 != 0));
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_14 * 0xc);
      local_c = 0;
    }
LAB_1000f9a8:
    if (local_c < 0) {
      local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                          (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_c;
}



// Function: FUN_1000f9f0 at 1000f9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1000fa68) */
/* WARNING: Removing unreachable block (ram,0x1000fa7f) */
/* WARNING: Removing unreachable block (ram,0x1000fac4) */
/* WARNING: Removing unreachable block (ram,0x1000fae0) */
/* WARNING: Removing unreachable block (ram,0x1000faf8) */
/* WARNING: Removing unreachable block (ram,0x1000fb00) */

undefined8 __thiscall FUN_1000f9f0(void *this,undefined4 param_1)

{
  int iVar1;
  void *extraout_EDX;
  int *piVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int local_2d0 [4];
  int *local_2c0;
  int *local_2b0;
  int *local_2ac;
  undefined4 *local_2a8;
  HMODULE local_2a4;
  int *local_2a0;
  undefined4 local_29c;
  LPCRITICAL_SECTION local_298;
  LPCRITICAL_SECTION local_294;
  int local_28c;
  int *local_280 [3];
  int *local_274 [3];
  int *local_268 [2];
  WCHAR *local_260;
  undefined4 *local_258;
  undefined4 local_248;
  DWORD local_240;
  WCHAR local_238 [262];
  int *local_2c;
  int local_28;
  LPCRITICAL_SECTION local_20;
  undefined1 local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aab6;
  local_10 = ExceptionList;
  piVar2 = local_2d0;
  for (iVar1 = 0xb0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  local_14 = (undefined4 *)this;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_298 = (LPCRITICAL_SECTION)(DAT_1002d0f8 + 0x10);
    local_1c = 0;
    local_8 = 0;
    ExceptionList = &local_10;
    local_294 = local_298;
    local_20 = local_298;
    EnterCriticalSection(local_298);
    local_29c = 0;
    local_1c = 1;
    local_28 = -0x7fffbffb;
    if (local_14[3] == 0) {
      local_2c = (int *)0x0;
      local_2a0 = (int *)local_14[1];
      if ((((DAT_1002d0fc == *local_2a0) && (DAT_1002d100 == local_2a0[1])) &&
          (DAT_1002d104 == local_2a0[2])) && (DAT_1002d108 == local_2a0[3])) {
        local_2d0[1] = 1;
      }
      else {
        local_2d0[1] = 0;
      }
      if (((local_2d0[1] == 0) || (*(short *)(local_14 + 2) != -1)) ||
         (*(short *)((int)local_14 + 10) != -1)) {
        local_28 = Ordinal_162(local_14[1],*(undefined2 *)(local_14 + 2),
                               *(undefined2 *)((int)local_14 + 10),param_1,&local_2c,0x1000fab1);
        uVar6 = 0x1000fcc8;
      }
      else {
        local_2a4 = DAT_1002dc20;
        local_240 = GetModuleFileNameW(DAT_1002dc20,local_238,0x104);
        uVar6 = 0x1000fbea;
        if ((local_240 != 0) && (local_240 != 0x104)) {
          local_248 = 3;
          local_258 = (undefined4 *)0x0;
          local_8._0_1_ = 1;
          local_260 = local_238;
          local_28 = Ordinal_161(local_260,&local_2c,0x1000fbea);
          uVar6 = 0x1000fc4b;
          local_8 = (uint)local_8._1_3_ << 8;
          while (puVar5 = local_258, local_258 != (undefined4 *)0x0) {
            local_2a8 = local_258;
            local_258 = (undefined4 *)*local_258;
            free(puVar5);
            uVar6 = 0x1000fc8e;
          }
        }
      }
      if (-1 < local_28) {
        local_268[0] = (int *)0x0;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        local_28 = (**(code **)(*local_2c + 0x18))(local_2c,*local_14,local_268,uVar6);
        pcVar4 = (code *)0x1000fd0b;
        if (-1 < local_28) {
          local_2ac = local_268[0];
          local_274[0] = local_268[0];
          if (local_268[0] != (int *)0x0) {
            (**(code **)(*local_268[0] + 4))(local_268[0],0x1000fd0b);
            pcVar4 = (code *)0x1000fd56;
          }
          local_280[0] = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,7);
          local_2b0 = local_268[0];
          iVar1 = (**(code **)*local_268[0])(local_268[0],&DAT_10023f34,local_280,pcVar4);
          uVar6 = 0x1000fda4;
          if (-1 < iVar1) {
            FUN_10012bd0(local_274,(int *)local_280);
          }
          piVar2 = local_274[0];
          local_2c0 = local_274[0];
          local_274[0] = (int *)0x0;
          local_14[3] = piVar2;
          local_2d0[3] = DAT_1002d0f8;
          if (DAT_1002d0f8 == 0) {
            local_2d0[0] = 0;
          }
          else {
            local_2d0[0] = DAT_1002d0f8 + 4;
          }
          pcVar4 = FUN_100104e0;
          puVar5 = local_14;
          FUN_1000ffe0(local_14,local_2d0[0],local_2d0[0]);
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 5;
          if (local_280[0] != (int *)0x0) {
            (**(code **)(*local_280[0] + 8))(local_280[0],pcVar4,puVar5,uVar6);
            pcVar4 = (code *)0x1000fe4f;
          }
          local_8._0_1_ = 3;
          if (local_274[0] != (int *)0x0) {
            (**(code **)(*local_274[0] + 8))(local_274[0],pcVar4);
            pcVar4 = (code *)0x1000fe7d;
          }
        }
        (**(code **)(*local_2c + 8))(local_2c,pcVar4);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_268[0] != (int *)0x0) {
          (**(code **)(*local_268[0] + 8))(local_268[0],0x1000fe94);
        }
      }
    }
    else {
      local_28 = 0;
    }
    if ((local_14[3] != 0) && (local_14[5] == 0)) {
      uVar3 = FUN_10010160((int *)local_14[3]);
      local_28 = (int)uVar3;
    }
    local_28c = local_28;
    local_8 = 0xffffffff;
    FUN_10012b00(&local_20);
    iVar1 = local_28c;
    this = extraout_EDX;
  }
  else {
    iVar1 = 0;
    ExceptionList = &local_10;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ff40);
  ExceptionList = local_10;
  return CONCAT44(this,iVar1);
}



// Function: FUN_1000ffe0 at 1000ffe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000ffe0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_44 [5];
  void *local_30;
  void *local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aac8;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffb0;
  puVar2 = local_44;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_3 == 0) {
    ExceptionList = &pvStack_10;
    _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10010144);
    ExceptionList = pvStack_10;
    return CONCAT44(param_2,0x80070057);
  }
  local_18 = 0;
  local_1c = (void *)0x0;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffffb0;
  local_30 = operator_new(0xc);
  local_1c = local_30;
  uVar3 = FUN_10010058(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@1001004b at 1001004b

undefined4 Catch_1001004b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001005f;
}



// Function: FUN_10010058 at 10010058

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10010058(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_EDX;
  int unaff_EBP;
  undefined4 uVar1;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x8007000e;
  }
  else {
    **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4) = *(undefined4 *)(unaff_EBP + 0x10);
    FUN_10012a60((void *)(unaff_EBP + -0x24),*(int *)(unaff_EBP + 8) + 0xc,'\0');
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x24);
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x38));
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    if (*(int *)(unaff_EBP + -0x3c) < 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x3c);
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x20) = 1;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    if (*(int *)(unaff_EBP + -0x14) < 0) {
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x18);
      operator_delete(*(void **)(unaff_EBP + -0x30));
    }
    else {
      *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8) =
           *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8);
      *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8) = *(undefined4 *)(unaff_EBP + -0x18);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10012b00((undefined4 *)(unaff_EBP + -0x24));
    param_2 = extraout_EDX;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10010144);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10010160 at 10010160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010160(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_EDX;
  uint **ppuVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  uint *local_54 [3];
  int iStack_48;
  uint *local_44;
  uint *local_40;
  uint local_3c;
  int aiStack_34 [2];
  undefined4 *puStack_2c;
  int iStack_28;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aaf3;
  pvStack_10 = ExceptionList;
  ppuVar5 = local_54;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar5 = (uint *)&DAT_cccccccc;
    ppuVar5 = ppuVar5 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffffa0;
  uVar6 = (**(code **)(*param_1 + 0xc))(param_1,&local_1c);
  local_20 = (int)uVar6;
  uVar7 = 0x100101b1;
  if (-1 < local_20) {
    local_24 = (uint *)0x0;
    *(uint *)(local_18 + 0x18) = (uint)*(ushort *)(local_1c + 0x2c);
    *(undefined4 *)(local_18 + 0x14) = 0;
    if (*(int *)(local_18 + 0x18) != 0) {
      local_8 = 0;
      local_3c = *(uint *)(local_18 + 0x18);
      uVar4 = -(uint)((int)((ulonglong)local_3c * 0xc >> 0x20) != 0) |
              (uint)((ulonglong)local_3c * 0xc);
      local_44 = (uint *)FUN_1001832c(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
      local_8._0_1_ = 1;
      if (local_44 == (uint *)0x0) {
        local_54[0] = (uint *)0x0;
      }
      else {
        *local_44 = local_3c;
        _eh_vector_constructor_iterator_(local_44 + 1,0xc,local_3c,FUN_10010470,FUN_1000f2b0);
        local_54[0] = local_44 + 1;
      }
      local_40 = local_54[0];
      local_8 = (uint)local_8._1_3_ << 8;
      local_24 = local_54[0];
      uVar6 = FUN_10010283();
      return uVar6;
    }
    for (iStack_28 = 0; iStack_28 < *(int *)(local_18 + 0x18); iStack_28 = iStack_28 + 1) {
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1,iStack_28,&puStack_2c);
      uVar7 = 0x100102f5;
      if (-1 < iVar3) {
        aiStack_34[0] = 0;
        local_8 = 3;
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,*puStack_2c,aiStack_34,0,0,0);
        iVar3 = aiStack_34[0];
        uVar7 = 0x10010332;
        if (-1 < iVar1) {
          iStack_48 = aiStack_34[0];
          aiStack_34[0] = 0;
          local_54[2] = (uint *)(iStack_28 * 0xc + (int)local_24);
          if (*local_54[2] != iVar3) {
            Ordinal_6(*local_54[2],0x10010332);
            uVar7 = 0x10010372;
            *local_54[2] = iStack_48;
          }
          local_54[1] = *(uint **)((int)local_24 + iStack_28 * 0xc);
          uVar2 = Ordinal_7(local_54[1],uVar7);
          uVar7 = 0x1001039c;
          *(undefined4 *)((int)local_24 + 4 + iStack_28 * 0xc) = uVar2;
          *(undefined4 *)((int)local_24 + 8 + iStack_28 * 0xc) = *puStack_2c;
        }
        (**(code **)(*param_1 + 0x50))(param_1,puStack_2c,uVar7);
        local_8 = 0xffffffff;
        Ordinal_6(aiStack_34[0],0x100103d6);
        uVar7 = 0x100103f0;
      }
    }
    *(uint **)(local_18 + 0x14) = local_24;
    (**(code **)(*param_1 + 0x4c))(param_1,local_1c,uVar7);
    uVar6 = CONCAT44(extraout_EDX,local_20);
  }
  uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20);
  local_20 = (int)uVar6;
  uVar2 = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001044c);
  ExceptionList = pvStack_10;
  return CONCAT44(uVar7,uVar2);
}



// Function: Catch@10010276 at 10010276

undefined4 Catch_10010276(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001028a;
}



// Function: FUN_10010283 at 10010283

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010283(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int unaff_EBP;
  undefined4 uVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0x8007000e;
    uVar3 = extraout_EDX;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    while (*(int *)(unaff_EBP + -0x24) < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18)) {
      iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x14))
                        (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x24),
                         unaff_EBP + -0x28);
      if (-1 < iVar2) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x30))
                          (*(undefined4 *)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + -0x28),
                           unaff_EBP + -0x30,0,0,0);
        uVar3 = 0x10010332;
        if (-1 < iVar2) {
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x30);
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(int *)(unaff_EBP + -0x48) =
               *(int *)(unaff_EBP + -0x24) * 0xc + *(int *)(unaff_EBP + -0x20);
          if (**(int **)(unaff_EBP + -0x48) != *(int *)(unaff_EBP + -0x44)) {
            Ordinal_6(**(undefined4 **)(unaff_EBP + -0x48),0x10010332);
            uVar3 = 0x10010372;
            **(undefined4 **)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x44);
          }
          *(undefined4 *)(unaff_EBP + -0x4c) =
               *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x24) * 0xc);
          uVar1 = Ordinal_7(*(undefined4 *)(unaff_EBP + -0x4c),uVar3);
          uVar3 = 0x1001039c;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 4 + *(int *)(unaff_EBP + -0x24) * 0xc) =
               uVar1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 8 + *(int *)(unaff_EBP + -0x24) * 0xc) =
               **(undefined4 **)(unaff_EBP + -0x28);
        }
        (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))
                  (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x28),uVar3);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x30),0x100103d6);
      }
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
    }
    *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x20);
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0;
    uVar3 = extraout_EDX_00;
  }
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001044c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(uVar3,uVar1);
}



// Function: FUN_10010470 at 10010470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10010470(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return param_1;
}



// Function: FUN_100104e0 at 100104e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100104e0(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_1000f1f0(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10010580 at 10010580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010580(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001ab29;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_3c;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)&DAT_cccccccc;
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
  local_24 = (undefined4 *)operator_new(0x50);
  uVar1 = local_8 >> 8;
  if (local_24 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    local_3c[3] = local_24 + 1;
    *local_3c[3] = 0;
    local_8._1_3_ = (uint3)(local_8 >> 8);
    local_8._0_1_ = 3;
    *local_24 = ATL::CComAggObject<class_CDataPlateParameter>::vftable;
    FUN_10013040(local_24 + 3,param_1);
    local_8._0_1_ = 4;
    (**(code **)(*DAT_1002d0f8 + 4))();
    uVar1 = (uint)local_8._1_3_;
    local_3c[1] = local_24;
  }
  local_20 = local_3c[1];
  local_8 = uVar1 << 8;
  local_1c = local_3c[1];
  uVar2 = FUN_1001067a();
  return uVar2;
}



// Function: Catch@1001066d at 1001066d

undefined4 Catch_1001066d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10010681;
}



// Function: FUN_1001067a at 1001067a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001067a(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_100119e0(*(int *)(unaff_EBP + -0x18));
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



// Function: FUN_10010740 at 10010740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010740(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001ab5e;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_20 = (undefined4 *)operator_new(0x70);
  if (local_20 == (undefined4 *)0x0) {
    local_3c[1] = (undefined4 *)0x0;
  }
  else {
    FUN_1000bbb0(local_20 + 1);
    local_8._0_1_ = 1;
    FUN_10010930(local_20 + 9);
    local_8._0_1_ = 3;
    *local_20 = ATL::CComObject<class_CDataPlateParameters>::vftable;
    (**(code **)(*DAT_1002d0f8 + 4))();
    local_8 = (uint)local_8._1_3_ << 8;
    local_3c[1] = local_20;
  }
  local_1c = local_3c[1];
  uVar1 = FUN_10010821();
  return uVar1;
}



// Function: Catch@10010814 at 10010814

undefined4 Catch_10010814(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10010828;
}



// Function: FUN_10010821 at 10010821

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010821(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x18) + 4));
    uStack00000004 = 0x10010850;
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x18) + 8;
    DVar1 = FUN_1000bb20(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
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



// Function: FUN_10010930 at 10010930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10010930(undefined4 *param_1)

{
  int iVar1;
  void **ppvVar2;
  undefined1 auStack_6c [24];
  undefined4 *puStack_54;
  void *local_4c [13];
  undefined1 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019bfe;
  local_10 = ExceptionList;
  ppvVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameter>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
             ::vftable;
  local_18 = auStack_6c;
  puStack_54 = param_1;
  local_14 = param_1;
  local_4c[1] = FUN_10003170(auStack_6c,L"CDualCollection CriticalSection Lock");
  local_8 = 0xffffffff;
  local_4c[2] = local_4c[1];
  local_4c[0] = FUN_100172a0(local_14 + 1);
  local_8 = 1;
  puStack_54 = (undefined4 *)0x100109b2;
  FUN_100038d0((int)(local_14 + 0xf));
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100109e0 at 100109e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100109e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_38 [9];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab8e;
  local_10 = ExceptionList;
  ppuVar2 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameter>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
             ::vftable;
  local_38[0] = param_1 + 0xf;
  local_8 = 0;
  local_14 = param_1;
  FUN_10003960(local_38[0]);
  local_8 = 0xffffffff;
  FUN_100173e0(local_14 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010a70 at 10010a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10010a70(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       CDualCollection<class_ATL::CAdapt<class_ATL::CComPtr<struct_IDataPlateParameter>_>,class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>
       ::vftable;
  local_8 = 0;
  FUN_10003960((void *)((int)this + 0x3c));
  local_8 = 0xffffffff;
  FUN_100173e0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010b20 at 10010b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010b20(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  
  puStack_c = &LAB_1001abdb;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_44;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
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
  local_24 = operator_new(0x7c);
  local_8._0_1_ = 1;
  if (local_24 == (void *)0x0) {
    local_44[1] = (undefined4 *)0x0;
  }
  else {
    local_44[1] = FUN_10011bf0(local_24,param_1);
  }
  local_20 = local_44[1];
  local_8 = (uint)local_8._1_3_ << 8;
  local_1c = local_44[1];
  uVar1 = FUN_10010bcd();
  return uVar1;
}



// Function: Catch@10010bc0 at 10010bc0

undefined4 Catch_10010bc0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10010bd4;
}



// Function: FUN_10010bcd at 10010bcd

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10010bcd(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    DVar1 = FUN_10010f20(*(int *)(unaff_EBP + -0x18));
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



// Function: FUN_10010c90 at 10010c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10010c90(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  local_8 = 0xffffffff;
  FUN_1000e3e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010d20 at 10010d20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10010d20(int *param_1)

{
  void *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    free(_Memory);
  }
  return;
}



// Function: FUN_10010d80 at 10010d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10010d80(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x24))(1,0x10010dae);
  }
  return LVar1;
}



// Function: FUN_10010e10 at 10010e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10010e10(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_10023f80,param_2,param_3);
  return iVar1;
}



// Function: FUN_10010e50 at 10010e50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10010e50(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac36;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlate>::vftable;
  FUN_10001000((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CDataPlate>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_1002d0f8 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010f20 at 10010f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_10010f20(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000bb20((LPCRITICAL_SECTION)(param_1 + 0x14));
  if (-1 < (int)local_c) {
    *(undefined1 *)(param_1 + 0x2c) = 1;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10010f90 at 10010f90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10010f90(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1,0x10010fbe);
  }
  return LVar1;
}



// Function: FUN_10011020 at 10011020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011020(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000e770((int)(param_1 + 3),(int *)&PTR_DAT_10023f80,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_100110f0 at 100110f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100110f0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_10011140 at 10011140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011140(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_10023fe8,param_2,param_3);
  return iVar1;
}



// Function: FUN_10011180 at 10011180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10011180(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateGroup>::vftable;
  FUN_100056e0((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CDataPlateGroup>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_1002d0f8 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011250 at 10011250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10011250(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10011280 at 10011280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10011280(int *param_1)

{
  FUN_100114f0(param_1);
  return;
}



// Function: FUN_100112b0 at 100112b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_100112b0(void *this,undefined4 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001aca3;
  local_10 = ExceptionList;
  puVar4 = local_38;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = &DAT_cccccccc;
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



// Function: FUN_10011420 at 10011420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011420(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000e770((int)(param_1 + 3),(int *)&PTR_DAT_10023fe8,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_100114f0 at 100114f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100114f0(int *param_1)

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



// Function: FUN_100115a0 at 100115a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_100115a0(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: Free at 10011600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<struct tagDBBINDING>::Free(void)
   
   Library: Visual Studio 2012 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10011650 at 10011650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011650(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_10024044,param_2,param_3);
  return iVar1;
}



// Function: FUN_10011690 at 10011690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10011690(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001acd6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateGroups>::vftable;
  FUN_10005c50((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CDataPlateGroups>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_1002d0f8 + 4))();
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011760 at 10011760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10011760(void *this,uint param_1)

{
  undefined1 *puVar1;
  
  puVar1 = FUN_10012cb0(param_1,2);
  if (puVar1 < (undefined1 *)0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10012a00(this,(size_t)puVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: ~CTempBuffer<> at 100117d0

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
    FUN_100128f0(param_1);
  }
  return;
}



// Function: FUN_10011810 at 10011810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011810(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000e770((int)(param_1 + 3),(int *)&PTR_DAT_10024044,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_100118e0 at 100118e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100118e0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10011910 at 10011910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10011910(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x2c))(1,0x1001193e);
  }
  return LVar1;
}



// Function: FUN_100119a0 at 100119a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_100119a0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_10024090,param_2,param_3);
  return iVar1;
}



// Function: FUN_100119e0 at 100119e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

DWORD __fastcall FUN_100119e0(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000bb20((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (-1 < (int)local_c) {
    *(undefined1 *)(param_1 + 0x30) = 1;
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10011a50 at 10011a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011a50(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000e770((int)(param_1 + 3),(int *)&PTR_DAT_10024090,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_10011b20 at 10011b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG FUN_10011b20(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x18))(1,0x10011b4e);
  }
  return LVar1;
}



// Function: FUN_10011bb0 at 10011bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011bb0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000e770(param_1,(int *)&PTR_DAT_100240b4,param_2,param_3);
  return iVar1;
}



// Function: FUN_10011bf0 at 10011bf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10011bf0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_44 [11];
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad06;
  local_10 = ExceptionList;
  ppuVar2 = local_44;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_18 = (undefined4 *)((int)this + 4);
  ExceptionList = &local_10;
  *local_18 = 0;
  local_8 = 1;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateParameters>::vftable;
  local_44[0] = (undefined4 *)((int)this + 0xc);
  local_14 = (undefined4 *)this;
  FUN_10011cc0((int)local_44[0]);
  *local_44[0] = ATL::CComContainedObject<class_CDataPlateParameters>::vftable;
  local_44[0][1] = param_1;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  (**(code **)(*DAT_1002d0f8 + 4))();
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10011cc0 at 10011cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10011cc0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [11];
  undefined4 *local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad49;
  local_10 = ExceptionList;
  puVar2 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = (undefined4 *)(param_1 + 4);
  ExceptionList = &local_10;
  *local_1c = 0;
  local_8 = 0;
  local_18 = (void *)(param_1 + 8);
  local_14 = param_1;
  memset(local_18,0,0x18);
  *(undefined1 *)((int)local_18 + 0x18) = 0;
  local_8 = 4;
  FUN_10010930((undefined4 *)(local_14 + 0x24));
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10011d70 at 10011d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10011d70(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000e770((int)(param_1 + 3),(int *)&PTR_DAT_100240b4,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_10011e40 at 10011e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10011e40(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_10011e90 at 10011e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10011e90(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 *)(param_1 + 4),param_2,param_3);
  return;
}



// Function: FUN_10011ee0 at 10011ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10011ee0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ada8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CDataPlate>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = 0xffffffff;
  FUN_10001210((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011f80 at 10011f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10011f80(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ad89;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlate>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10001210((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012040 at 10012040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10012040(void *this,undefined4 *param_1)

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



// Function: FUN_100120e0 at 100120e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100120e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ada8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10001210(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012140 at 10012140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012140(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001afb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CDataPlateGroup>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = 0xffffffff;
  FUN_100057b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100121e0 at 100121e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100121e0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ade9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateGroup>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_100057b0((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100122a0 at 100122a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100122a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001afb8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_100057b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012300 at 10012300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012300(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ae08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CDataPlateGroups>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = 0xffffffff;
  FUN_10005d40((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100123a0 at 100123a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100123a0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ae49;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateGroups>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10005d40((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012460 at 10012460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012460(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ae08;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10005d40(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100124c0 at 100124c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100124c0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CDataPlateParameter>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CDataPlateParameter>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 8) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = 0xffffffff;
  FUN_10014e60((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012570 at 10012570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012570(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ae89;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateParameter>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10014e60((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012630 at 10012630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012630(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af98;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10014e60(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012690 at 10012690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012690(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CDataPlateParameters>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = 0xffffffff;
  FUN_10012750((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012750 at 10012750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012750(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aed9;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_100109e0((undefined4 *)(param_1 + 0x24));
  local_8 = 5;
  if (*(char *)(param_1 + 0x20) != '\0') {
    *(undefined1 *)(param_1 + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012820 at 10012820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012820(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001af19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CDataPlateParameters>::vftable;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002d0f8 + 8))();
  local_8 = local_8 & 0xffffff00;
  FUN_10012750((int)this + 0xc);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100128f0 at 100128f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100128f0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10012940 at 10012940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10012940(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10012a00(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10012990 at 10012990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012990(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af38;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10012750(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012a00 at 10012a00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10012a00(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    FUN_100019e0(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10012a60 at 10012a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10012aba) */
/* WARNING: Removing unreachable block (ram,0x10012ad6) */

undefined4 * __thiscall FUN_10012a60(void *this,undefined4 param_1,char param_2)

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



// Function: FUN_10012b00 at 10012b00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012b00(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10012b60 at 10012b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10012ba7) */

undefined4 __fastcall FUN_10012b60(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 1;
  return 0;
}



// Function: FUN_10012bd0 at 10012bd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10012bd0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  ulonglong uVar3;
  int local_1c;
  
  uVar3 = FUN_10012d60((int *)this,*param_1,(undefined4 *)*param_1);
  if ((uVar3 & 0xff) == 0) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      local_1c = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
      *(undefined4 *)this = 0;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,&DAT_100240fc,this);
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
                    /* WARNING: Load size is inaccurate */
      local_1c = *this;
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    local_1c = *this;
  }
  return local_1c;
}



// Function: FUN_10012cb0 at 10012cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10012ced) */

undefined1 * __cdecl FUN_10012cb0(uint param_1,uint param_2)

{
  undefined1 *local_14;
  int local_10;
  int local_c;
  undefined1 *local_8;
  
  local_8 = &DAT_cccccccc;
  local_10 = (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20);
  if (local_10 == 0) {
    local_14 = (undefined1 *)((ulonglong)param_1 * (ulonglong)param_2);
    local_8 = local_14;
    local_c = 0;
  }
  else {
    local_c = -0x7ff8fdea;
  }
  if (local_c < 0) {
    FUN_100019e0(local_c);
  }
  return local_8;
}



// Function: FUN_10012d50 at 10012d50

void FUN_10012d50(void)

{
  return;
}



// Function: FUN_10012d60 at 10012d60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10012d60(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint3 uVar2;
  int iVar1;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  int *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  int *local_1c;
  undefined1 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001af80;
  local_10 = ExceptionList;
  puVar5 = &DAT_cccccccc;
  puVar8 = &DAT_cccccccc;
  local_28 = (int *)&DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_1c = (int *)&DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  uVar2 = (uint3)((uint)param_1 >> 8);
  local_14 = param_1;
  if ((*param_1 == 0) && (param_3 == (undefined4 *)0x0)) {
    iVar1 = CONCAT31(uVar2,1);
    ExceptionList = &local_10;
  }
  else if ((*param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    iVar1 = (uint)uVar2 << 8;
    ExceptionList = &local_10;
  }
  else {
    local_1c = (int *)0x0;
    local_28 = (int *)0x0;
    local_8._1_3_ = 0;
    local_8._0_1_ = 3;
    ExceptionList = &local_10;
    (*(code *)**(undefined4 **)*param_1)(*param_1,&PTR_10023d54,&local_1c);
    (**(code **)*param_3)(param_3,&PTR_10023d54,&local_28,0x10012e10);
    uVar3 = CONCAT44(local_28,local_1c);
    uVar4 = 0x10012e2f;
    uVar6 = CONCAT13(local_1c == local_28,(int3)puVar5);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_28 != (int *)0x0) {
      uVar3 = (**(code **)(*local_28 + 8))(local_28,0x10012e2f,local_28,uVar6,puVar8);
      uVar4 = 0x10012e68;
    }
    uVar7 = (undefined1)((uint)uVar6 >> 0x18);
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      uVar3 = (**(code **)(*local_1c + 8))(local_1c,uVar4);
    }
    param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    iVar1 = CONCAT31((int3)((ulonglong)uVar3 >> 8),uVar7);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_10012ec4);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_10012ef0 at 10012ef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10012ef0(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_10012f50 at 10012f50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10012f50(int param_1)

{
  void *pvVar1;
  undefined4 local_14;
  int local_10;
  undefined1 *local_c;
  int local_8;
  
  local_14 = &DAT_cccccccc;
  local_c = &DAT_cccccccc;
  local_10 = (int)&local_14 + 3;
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = param_1;
  pvVar1 = FUN_10013b60(1);
  *(void **)(local_8 + 4) = pvVar1;
  **(undefined4 **)(local_8 + 4) = *(undefined4 *)(local_8 + 4);
  *(undefined4 *)(*(int *)(local_8 + 4) + 4) = *(undefined4 *)(local_8 + 4);
  *(undefined4 *)(*(int *)(local_8 + 4) + 8) = *(undefined4 *)(local_8 + 4);
  *(undefined1 *)(*(int *)(local_8 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(local_8 + 4) + 0x2d) = 1;
  return local_8;
}



// Function: FUN_10012ff0 at 10012ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012ff0(void)

{
  return;
}



// Function: FUN_10013040 at 10013040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10013040(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001af98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10014d30((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CDataPlateParameter>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CDataPlateParameter>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100130c0 at 100130c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100130c0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10013110 at 10013110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10013110(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10013160 at 10013160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10013160(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_100131b0 at 100131b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100131b0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ada8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10001210((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10013220 at 10013220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10013220(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001afb8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_100057b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10013290 at 10013290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10013290(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ae08;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10005d40((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10013300 at 10013300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10013300(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af98;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10014e60((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10013370 at 10013370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * FUN_10013370(undefined4 *param_1,int *param_2)

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
    *ppiVar2 = (int *)&DAT_cccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_1c = param_2;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  local_c = param_2;
  FUN_10013a30((int *)&param_2);
  local_18 = local_c;
  if (*(char *)(*local_c + 0x2d) == '\0') {
    if (*(char *)(local_c[2] + 0x2d) == '\0') {
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
    if (*(char *)((int)local_10 + 0x2d) == '\0') {
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
      if (*(char *)((int)local_10 + 0x2d) == '\0') {
        for (local_24 = local_10; *(char *)(*local_24 + 0x2d) == '\0'; local_24 = (int *)*local_24)
        {
        }
        local_70[1] = local_24;
      }
      local_28 = *(undefined4 **)((int)local_8 + 4);
      *local_28 = local_70[1];
    }
    if (*(int **)(*(int *)((int)local_8 + 4) + 8) == local_c) {
      local_70[0] = local_14;
      if (*(char *)((int)local_10 + 0x2d) == '\0') {
        local_2c = local_10;
        while (*(char *)(local_2c[2] + 0x2d) == '\0') {
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
      if (*(char *)((int)local_10 + 0x2d) == '\0') {
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
    local_40 = local_c + 0xb;
    local_3c = local_18 + 0xb;
    local_35 = (undefined1)*local_3c;
    *(char *)local_3c = (char)*local_40;
    *(undefined1 *)local_40 = local_35;
  }
  if ((char)local_c[0xb] != '\x01') {
LAB_1001380d:
    FUN_10013af0((int)local_8 + 0xd,local_c + 3);
    operator_delete(local_c);
    if (*(int *)((int)local_8 + 8) != 0) {
      *(int *)((int)local_8 + 8) = *(int *)((int)local_8 + 8) + -1;
    }
    *param_1 = param_2;
    return param_1;
  }
LAB_1001361d:
  if ((local_10 == *(int **)(*(int *)((int)local_8 + 4) + 4)) || ((char)local_10[0xb] != '\x01'))
  goto LAB_10013806;
  if (local_10 == (int *)*local_14) {
    local_18 = (int *)local_14[2];
    if ((char)local_18[0xb] == '\0') {
      *(undefined1 *)(local_18 + 0xb) = 1;
      *(undefined1 *)(local_14 + 0xb) = 0;
      FUN_10013970(local_8,(int)local_14);
      local_18 = (int *)local_14[2];
    }
    if (*(char *)((int)local_18 + 0x2d) == '\0') {
      if ((*(char *)(*local_18 + 0x2c) != '\x01') || (*(char *)(local_18[2] + 0x2c) != '\x01')) {
        if (*(char *)(local_18[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*local_18 + 0x2c) = 1;
          *(undefined1 *)(local_18 + 0xb) = 0;
          FUN_100047c0(local_8,local_18);
          local_18 = (int *)local_14[2];
        }
        *(char *)(local_18 + 0xb) = (char)local_14[0xb];
        *(undefined1 *)(local_14 + 0xb) = 1;
        *(undefined1 *)(local_18[2] + 0x2c) = 1;
        FUN_10013970(local_8,(int)local_14);
LAB_10013806:
        *(undefined1 *)(local_10 + 0xb) = 1;
        goto LAB_1001380d;
      }
      *(undefined1 *)(local_18 + 0xb) = 0;
    }
    local_10 = local_14;
  }
  else {
    local_18 = (int *)*local_14;
    if ((char)local_18[0xb] == '\0') {
      *(undefined1 *)(local_18 + 0xb) = 1;
      *(undefined1 *)(local_14 + 0xb) = 0;
      FUN_100047c0(local_8,local_14);
      local_18 = (int *)*local_14;
    }
    if (*(char *)((int)local_18 + 0x2d) == '\0') {
      if ((*(char *)(local_18[2] + 0x2c) != '\x01') || (*(char *)(*local_18 + 0x2c) != '\x01')) {
        if (*(char *)(*local_18 + 0x2c) == '\x01') {
          *(undefined1 *)(local_18[2] + 0x2c) = 1;
          *(undefined1 *)(local_18 + 0xb) = 0;
          FUN_10013970(local_8,(int)local_18);
          local_18 = (int *)*local_14;
        }
        *(char *)(local_18 + 0xb) = (char)local_14[0xb];
        *(undefined1 *)(local_14 + 0xb) = 1;
        *(undefined1 *)(*local_18 + 0x2c) = 1;
        FUN_100047c0(local_8,local_14);
        goto LAB_10013806;
      }
      *(undefined1 *)(local_18 + 0xb) = 0;
      local_10 = local_14;
    }
    else {
      local_10 = local_14;
    }
  }
  local_14 = (int *)local_10[1];
  goto LAB_1001361d;
}



// Function: FUN_10013870 at 10013870

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013870(void *param_1)

{
  FUN_100138f0(param_1,*(undefined4 **)(*(int *)((int)param_1 + 4) + 4));
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 4) = *(undefined4 *)((int)param_1 + 4);
  **(undefined4 **)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 8) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_100138f0 at 100138f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_100138f0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  
  local_c = param_1;
  while (*(char *)((int)local_c + 0x2d) == '\0') {
    FUN_100138f0(this,(undefined4 *)local_c[2]);
    puVar1 = (undefined4 *)*local_c;
    FUN_10013af0((int)this + 0xd,local_c + 3);
    operator_delete(local_c);
    local_c = puVar1;
  }
  return;
}



// Function: FUN_10013970 at 10013970

void __thiscall FUN_10013970(void *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x2d) == '\0') {
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



// Function: FUN_10013a30 at 10013a30

int * __fastcall FUN_10013a30(int *param_1)

{
  int iVar1;
  int *local_18;
  
  if (*(char *)(*param_1 + 0x2d) == '\0') {
    if (*(char *)(*(int *)(*param_1 + 8) + 0x2d) == '\0') {
      for (local_18 = *(int **)(*param_1 + 8); *(char *)(*local_18 + 0x2d) == '\0';
          local_18 = (int *)*local_18) {
      }
      *param_1 = (int)local_18;
    }
    else {
      while ((iVar1 = *(int *)(*param_1 + 4), *(char *)(iVar1 + 0x2d) == '\0' &&
             (*param_1 == *(int *)(iVar1 + 8)))) {
        *param_1 = iVar1;
      }
      *param_1 = iVar1;
    }
  }
  return param_1;
}



// Function: FUN_10013af0 at 10013af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10013b36) */

void __cdecl FUN_10013af0(undefined4 param_1,void *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001afd8;
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  ExceptionList = &local_10;
  FUN_10003570(param_2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013b60 at 10013b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10013b60(uint param_1)

{
  char *local_24;
  undefined **local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e52;
  local_10 = ExceptionList;
  local_24 = &DAT_cccccccc;
  local_20 = (undefined **)&DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((ExceptionList = &local_10, 0x5555555 < param_1 ||
      (ExceptionList = &local_10, local_14 = operator_new(param_1 * 0x30), local_14 == (void *)0x0))
     )) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)&local_20,&local_24);
    local_20 = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10026f74);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013c30 at 10013c30

void FUN_10013c30(int param_1)

{
  FUN_100130c0(param_1 + -4);
  return;
}



// Function: FUN_10013c40 at 10013c40

void FUN_10013c40(int param_1)

{
  FUN_100118e0(param_1 + -4);
  return;
}



// Function: FUN_10013c50 at 10013c50

void FUN_10013c50(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100119a0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10013c60 at 10013c60

void FUN_10013c60(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10013160(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10013c70 at 10013c70

void FUN_10013c70(int param_1)

{
  FUN_10013110(param_1 + -4);
  return;
}



// Function: FUN_10013c80 at 10013c80

void FUN_10013c80(int param_1)

{
  FUN_10011910((int *)(param_1 + -4));
  return;
}



// Function: FUN_10013c90 at 10013c90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10013c90(int param_1)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b026;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset((void *)(param_1 + 0x10),0,0x18);
  local_8 = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1002d0f8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar1 = FUN_1000bb20((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar1 < 0) {
    DAT_1002d0ec = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013d70 at 10013d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013d70(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b046;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_1000bfa0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: AddRef at 10013dd0

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



// Function: AddRef at 10013e10

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



// Function: FUN_10013e50 at 10013e50

undefined4 __fastcall FUN_10013e50(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10013e70 at 10013e70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10013e70(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_1002481c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1002419c,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10013f20 at 10013f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10013f20(void)

{
  return;
}



// Function: FUN_10013f70 at 10013f70

undefined4 FUN_10013f70(void)

{
  return 0x80004005;
}



// Function: FUN_10013f80 at 10013f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10013f80(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_100140f0(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function: FUN_10013fc0 at 10013fc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10013fc0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10006cd0(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function: FUN_10014000 at 10014000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10014000(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b096;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 2;
  FUN_1000bfa0((int)this);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014090 at 10014090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014090(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b0be;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1000bfa0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100140f0 at 100140f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001440c) */
/* WARNING: Removing unreachable block (ram,0x1001414c) */

undefined8 FUN_100140f0(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

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
  int local_af0 [2];
  int local_ae8;
  undefined4 local_adc;
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
  puStack_c = &LAB_1001b17b;
  local_10 = ExceptionList;
  pDVar8 = local_b84;
  for (iVar5 = 0x2dd; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pDVar8 = (DWORD)&DAT_cccccccc;
    pDVar8 = pDVar8 + 1;
  }
  local_28 = ATL::CRegObject::vftable;
  ExceptionList = &local_10;
  FUN_1000b8e0(local_24);
  local_8 = 1;
  local_30 = 0;
  if (param_4 != (int *)0x0) {
    for (; *param_4 != 0; param_4 = param_4 + 2) {
      local_b04 = param_4[1];
      local_b00 = (LPCWSTR)*param_4;
      if ((local_b00 != (LPCWSTR)0x0) && (local_b04 != 0)) {
        local_adc = 3;
        local_af0[0] = 0;
        local_8._0_1_ = 4;
        local_af8 = local_b00;
        uVar9 = FUN_10007760(local_24,local_b04,local_b00,local_b04);
        local_afc = (int)uVar9;
        local_ae8 = (-(uint)(local_afc != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10010d20(local_af0);
      }
    }
  }
  local_30 = (**(code **)(*param_1 + 0x14))(&local_28);
  local_b84[0] = 0x1001428e;
  if ((int)local_30 < 0) {
    local_28 = ATL::CRegObject::vftable;
    local_8 = 5;
    local_ab8 = local_30;
    FUN_100083b0((int)&local_28);
    local_b08 = local_24;
    local_8 = 6;
    FUN_10007b60(local_b08);
    local_8 = 0xffffffff;
    FUN_100114f0(local_b08);
    DVar4 = local_ab8;
    uVar7 = extraout_EDX;
  }
  else {
    local_38 = 3;
    local_48[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_260 = DAT_1002dc20;
    local_264 = GetModuleFileNameW(DAT_1002dc20,local_258,0x104);
    if (local_264 == 0) {
      local_abc = FUN_100075e0();
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_48[0], local_48[0] != (undefined4 *)0x0) {
        local_b0c = local_48[0];
        local_48[0] = (undefined4 *)*local_48[0];
        free(puVar1);
      }
      local_28 = ATL::CRegObject::vftable;
      local_8 = 8;
      FUN_100083b0((int)&local_28);
      local_b10 = local_24;
      local_8 = 9;
      FUN_10007b60(local_b10);
      local_8 = 0xffffffff;
      FUN_100114f0(local_b10);
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
      FUN_100083b0((int)&local_28);
      local_b18 = local_24;
      local_8 = 0xb;
      FUN_10007b60(local_b18);
      local_8 = 0xffffffff;
      FUN_100114f0(local_b18);
      DVar4 = local_ac0;
      uVar7 = extraout_EDX_01;
    }
    else {
      local_268 = local_258;
      FUN_10007640(local_67c,0x208,local_268);
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
          FUN_100083b0((int)&local_28);
          local_b24 = local_24;
          local_8 = 0xd;
          FUN_10007b60(local_b24);
          local_8 = 0xffffffff;
          FUN_100114f0(local_b24);
          DVar4 = local_ac4;
          uVar7 = extraout_EDX_02;
          goto LAB_10014935;
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
          uVar9 = FUN_10007760(local_24,L"Module",L"Module",(int)&local_aa0);
          local_b48 = (int)uVar9;
          local_b4c = (-(uint)(local_b48 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_10010d20(local_b3c);
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
          uVar9 = FUN_10007760(local_24,L"Module",L"Module",(int)local_67c);
          local_b70 = (int)uVar9;
          local_b74 = (-(uint)(local_b70 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_10010d20(local_b64);
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
        FUN_100083b0((int)&local_28);
        local_b7c = local_24;
        local_8 = 0x11;
        FUN_10007b60(local_b7c);
        local_8 = 0xffffffff;
        FUN_100114f0(local_b7c);
        DVar4 = local_ac8;
        uVar7 = extraout_EDX_05;
      }
      else {
        uVar9 = FUN_10007db0(&local_28,pwVar6,(int)&local_28,0x10023a54,(int)local_67c);
        local_684 = (DWORD)uVar9;
        if ((int)local_684 < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_acc = local_684;
          FUN_10010d20((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10007ca0(&local_28);
          DVar4 = local_acc;
          uVar7 = extraout_EDX_06;
        }
        else {
          local_aac = L"REGISTRY";
          local_ab0 = param_2;
          if (param_3 == 0) {
            uVar9 = FUN_10014ba0(local_268,&local_28,&local_28,local_268,param_2,L"REGISTRY");
            local_b84[0] = (DWORD)uVar9;
          }
          else {
            uVar9 = FUN_10014a60(&local_28,param_2,&local_28,local_268,param_2,L"REGISTRY");
            local_b84[0] = (DWORD)uVar9;
          }
          local_30 = local_b84[0];
          local_ad0 = local_b84[0];
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_10010d20((int *)local_48);
          local_8 = 0xffffffff;
          FUN_10007ca0(&local_28);
          DVar4 = local_ad0;
          uVar7 = extraout_EDX_07;
        }
      }
    }
  }
LAB_10014935:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10014968);
  ExceptionList = local_10;
  return CONCAT44(uVar7,DVar4);
}



// Function: FUN_10014a60 at 10014a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10014a60(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,
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
  
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  ppWVar5 = local_44;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppWVar5 = (LPCWSTR)&DAT_cccccccc;
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
    uVar6 = FUN_10007fc0(param_4,param_5,param_6);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10014b74);
  ExceptionList = local_10;
  return CONCAT44(uVar4,pWVar2);
}



// Function: FUN_10014ba0 at 10014ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10014ba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,
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
  
  puStack_c = &LAB_1001a668;
  local_10 = ExceptionList;
  ppWVar5 = local_44;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppWVar5 = (LPCWSTR)&DAT_cccccccc;
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
    uVar6 = FUN_10007fc0(param_4,param_5,param_6);
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
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10014cb4);
  ExceptionList = local_10;
  return CONCAT44(uVar4,pWVar2);
}



// Function: FUN_10014ce0 at 10014ce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10014ce0(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_100237f0);
  return;
}



// Function: FUN_10014d30 at 10014d30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10014d30(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b2aa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = 0;
  memset((void *)(param_1 + 0xc),0,0x18);
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10014e60 at 10014e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014e60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b31a;
  local_10 = ExceptionList;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  ExceptionList = &local_10;
  Ordinal_6(*(undefined4 *)(param_1 + 0x40));
  local_8._0_1_ = 2;
  Ordinal_6(*(undefined4 *)(param_1 + 0x3c),0x10014eb5);
  local_8._0_1_ = 1;
  Ordinal_6(*(undefined4 *)(param_1 + 0x2c),0x10014ecf);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(*(undefined4 *)(param_1 + 0x28),0x10014ee9);
  local_8 = 8;
  if (*(char *)(param_1 + 0x24) != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014f80 at 10014f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10014f80(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    iVar1 = FUN_10005970((int *)(param_1 + 0x28));
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



// Function: FUN_10014ff0 at 10014ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10014ff0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    iVar1 = FUN_10005970((int *)(param_1 + 0x2c));
    *param_2 = iVar1;
    if ((*param_2 == 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      local_c = 0x8007000e;
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10015060 at 10015060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10015060(int param_1,int *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  if (param_2 == (int *)0x0) {
    local_c = 0x80004003;
  }
  else {
    iVar1 = FUN_10005970((int *)(param_1 + 0x3c));
    *param_2 = iVar1;
    if ((*param_2 == 0) && (*(int *)(param_1 + 0x3c) != 0)) {
      local_c = 0x8007000e;
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_100150d0 at 100150d0

void FUN_100150d0(int param_1,int param_2)

{
  int iVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b330;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  FUN_10005a80((void *)(param_1 + 0x3c),param_2);
  iVar1 = Ordinal_314(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),0x400,0);
  if (iVar1 != 1) {
    *(undefined2 *)(param_1 + 0x34) = 0xffff;
  }
  FUN_10015168();
  return;
}



// Function: Catch@1001514e at 1001514e

undefined * Catch_1001514e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015171;
}



// Function: FUN_10015168 at 10015168

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10015168(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_100151a0 at 100151a0

undefined4 FUN_100151a0(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined2 *)(param_1 + 0x30);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100151d0 at 100151d0

undefined4 FUN_100151d0(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined2 *)(param_1 + 0x32);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10015200 at 10015200

undefined4 FUN_10015200(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined2 *)(param_1 + 0x34);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10015230 at 10015230

undefined4 FUN_10015230(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x38);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10015260 at 10015260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10015260(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b348;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffc4;
  local_28 = &DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  ExceptionList = &pvStack_10;
  FUN_10004880(&local_28);
  local_8 = 1;
  FUN_10005a80((void *)(param_1 + 0x24),param_2);
  FUN_10005a80((void *)(param_1 + 0x28),param_3);
  uVar1 = (**(code **)(*param_4 + 0x38))(param_4,param_3,param_1 + 0x2c);
  uVar3 = 0x100152ef;
  FUN_10004900(&local_28,uVar1);
  uVar1 = (**(code **)(*param_4 + 0x3c))(param_4,param_3,param_1 + 0x2e,uVar3);
  FUN_10004900(&local_28,uVar1);
  uVar2 = FUN_10015332();
  return uVar2;
}



// Function: Catch@10015325 at 10015325

undefined4 Catch_10015325(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10015339;
}



// Function: FUN_10015332 at 10015332

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10015332(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x2c);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10015380);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_100153a0 at 100153a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100153a0(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined8 uVar4;
  undefined4 *local_3c [5];
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b368;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffb8;
  ppuVar3 = local_3c;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)&DAT_cccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  FUN_10004880(local_28);
  local_8 = 1;
  local_3c[1] = (undefined4 *)(param_1 + 0x38);
  Ordinal_6(*local_3c[1]);
  *local_3c[1] = 0;
  local_3c[0] = (undefined4 *)(param_1 + 0x3c);
  Ordinal_6(*local_3c[0],0x10015402);
  *local_3c[0] = 0;
  uVar1 = (**(code **)(*param_2 + 0x24))(param_2,param_1 + 0x38,0x10015429);
  FUN_10004900(local_28,uVar1);
  FUN_10015510((void *)(param_1 + 0x3c),(int *)(param_1 + 0x38));
  *(undefined2 *)(param_1 + 0x30) = 0;
  uVar4 = FUN_10015490();
  return uVar4;
}



// Function: Catch@10015476 at 10015476

undefined * Catch_10015476(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10015499;
}



// Function: FUN_10015490 at 10015490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10015490(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x30);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100154f4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10015510 at 10015510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10015510(void *this,int *param_1)

{
  undefined4 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    uVar1 = FUN_10005970(param_1);
    *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
    if ((*param_1 != 0) && (*this == 0)) {
      FUN_100019e0(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_10015590 at 10015590

void FUN_10015590(int param_1)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b380;
  pvStack_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  if (*(short *)(param_1 + 0x30) == -1) {
    ExceptionList = &pvStack_10;
    FUN_10015510((void *)(param_1 + 0x38),(int *)(param_1 + 0x3c));
  }
  FUN_100155f8();
  return;
}



// Function: Catch@100155de at 100155de

undefined * Catch_100155de(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015601;
}



// Function: FUN_100155f8 at 100155f8

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100155f8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10015630 at 10015630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10015630(int param_1,int *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint **ppuVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  uint *local_60 [5];
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b3a0;
  pvStack_10 = ExceptionList;
  ppuVar3 = local_60;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (uint *)&DAT_cccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff94;
  FUN_10004880(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_3 == (undefined2 *)0x0) {
    FUN_10004900(local_28,0x80004003);
  }
  if (*(short *)(param_1 + 0x30) == -1) {
    local_4c = local_4c & 0xffff0000;
    FUN_100157e0(&local_4c,(int *)(param_1 + 0x38));
    local_60[0] = &local_4c;
    local_8._0_1_ = 2;
    local_3c = local_4c;
    local_60[2] = *(uint **)(param_1 + 0x28);
    uVar1 = (**(code **)(*param_2 + 0x24))(param_2,local_60[2],local_4c,local_48,local_44,local_40);
    uVar5 = 0x10015710;
    FUN_10004900(local_28,uVar1);
    local_8._0_1_ = 1;
    local_60[1] = (uint *)Ordinal_9(&local_4c,uVar5);
  }
  *param_3 = *(undefined2 *)(param_1 + 0x30);
  uVar4 = FUN_1001575b();
  return uVar4;
}



// Function: Catch@10015742 at 10015742

undefined * Catch_10015742(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10015764;
}



// Function: FUN_1001575b at 1001575b

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001575b(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x50);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100157c0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_100157e0 at 100157e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined2 * __thiscall FUN_100157e0(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
    FUN_100019e0(iVar1);
  }
  *(undefined2 *)this = 8;
  uVar2 = FUN_10005970(param_1);
  *(undefined4 *)((int)this + 8) = uVar2;
  if ((*(int *)((int)this + 8) == 0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    FUN_100019e0(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_10015880 at 10015880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong __fastcall
FUN_10015880(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  longlong lVar2;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b438;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffc0;
  local_28 = &DAT_cccccccc;
  local_24 = &DAT_cccccccc;
  local_20 = &DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  if (param_4 == (undefined4 *)0x0) {
    ExceptionList = &pvStack_10;
    local_14 = &stack0xffffffc0;
    _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001596c);
    ExceptionList = pvStack_10;
    return CONCAT44(param_2,0x80004003);
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  FUN_10017510(&local_28,param_3 + 0x28);
  uVar1 = *(undefined4 *)(param_3 + 0x68);
  local_8 = local_8 & 0xffffff00;
  local_1c = (undefined1 *)uVar1;
  FUN_10017560(&local_28);
  *param_4 = uVar1;
  lVar2 = FUN_1001592e(extraout_ECX,(uint)param_4);
  return lVar2;
}



// Function: Catch@10015914 at 10015914

undefined * Catch_10015914(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015937;
}



// Function: FUN_1001592e at 1001592e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong __fastcall FUN_1001592e(undefined4 param_1,uint param_2)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001596c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (ulonglong)param_2 << 0x20;
}



// Function: FUN_10015990 at 10015990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong FUN_10015990(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  int **ppiVar3;
  undefined8 uVar4;
  longlong lVar5;
  int *in_stack_00000018;
  undefined4 uVar6;
  int *local_98 [4];
  undefined4 local_88;
  undefined4 local_84;
  int *local_80;
  undefined4 local_78;
  int *local_74;
  wchar_t *local_70;
  int *local_68;
  int *local_64;
  undefined1 local_60 [32];
  short local_40 [4];
  wchar_t *local_38;
  undefined4 local_28 [5];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b4a0;
  pvStack_10 = ExceptionList;
  ppiVar3 = local_98;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_8 = 0;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff5c;
  FUN_10004880(local_28);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_40[0] = 0;
  local_70 = (wchar_t *)Ordinal_10(local_40,&stack0x00000008);
  uVar6 = 0x100159f7;
  if ((int)local_70 < 0) {
    local_40[0] = 10;
    local_38 = local_70;
    FUN_100019e0(local_70);
  }
  local_8._0_1_ = 2;
  if (local_40[0] == 8) {
    local_98[2] = (int *)FUN_10017710(local_60,local_38);
    local_8._0_1_ = 3;
    local_98[3] = local_98[2];
    uVar4 = FUN_10015ec0((void *)(param_1 + 0x24),(int *)&local_64,(ushort *)local_98[2]);
    local_98[1] = (int *)uVar4;
    local_8._0_1_ = 4;
    local_74 = local_98[1];
    if (in_stack_00000018 == (int *)0x0) {
      local_78 = 0x80004003;
    }
    else {
      *in_stack_00000018 = *local_98[1];
      if (*local_98[1] != 0) {
        (**(code **)(*(int *)*local_98[1] + 4))(*local_98[1]);
        uVar6 = 0x10015ab4;
      }
      local_78 = 0;
    }
    FUN_10004900(local_28,local_78);
    local_8._0_1_ = 3;
    if (local_64 != (int *)0x0) {
      (**(code **)(*local_64 + 8))(local_64,uVar6);
      uVar6 = 0x10015af0;
    }
    local_8._0_1_ = 7;
    FUN_10003620(local_60,'\x01',0);
  }
  else {
    uVar1 = FUN_10017a00(3,(int)local_40,0,0x409);
    FUN_10004900(local_28,uVar1);
    uVar4 = FUN_10015df0((void *)(param_1 + 0x24),(int *)&local_68,(int)local_38);
    local_98[0] = (int *)uVar4;
    local_8._0_1_ = 8;
    local_80 = local_98[0];
    if (in_stack_00000018 == (int *)0x0) {
      local_84 = 0x80004003;
    }
    else {
      *in_stack_00000018 = *local_98[0];
      if (*local_98[0] != 0) {
        (**(code **)(*(int *)*local_98[0] + 4))(*local_98[0],uVar6);
        uVar6 = 0x10015b89;
      }
      local_84 = 0;
    }
    FUN_10004900(local_28,local_84);
    local_8._0_1_ = 2;
    if (local_68 != (int *)0x0) {
      (**(code **)(*local_68 + 8))(local_68,uVar6);
      uVar6 = 0x10015bc5;
    }
  }
  local_8._0_1_ = 1;
  local_88 = Ordinal_9(local_40,uVar6);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100048e0(local_28);
  lVar5 = FUN_10015c0a(extraout_ECX,extraout_EDX);
  return lVar5;
}



// Function: Catch@10015bf0 at 10015bf0

undefined * Catch_10015bf0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x68) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015c13;
}



// Function: FUN_10015c0a at 10015c0a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

longlong __fastcall FUN_10015c0a(undefined4 param_1,uint param_2)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10015c4c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (ulonglong)param_2 << 0x20;
}



// Function: FUN_10015c80 at 10015c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff8c : 0x10015cfd */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_10015c80(int param_1,wchar_t *param_2,int *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 **ppuVar4;
  int *piVar5;
  undefined1 *local_64 [8];
  undefined1 *local_44;
  int *local_40;
  undefined1 local_38 [28];
  int *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b4f0;
  pvStack_10 = ExceptionList;
  ppuVar4 = local_64;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = &DAT_cccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  local_8 = 0;
  local_1c = param_3;
  ExceptionList = &pvStack_10;
  local_14 = &stack0xffffff90;
  if (param_3 != (int *)0x0) {
    ExceptionList = &pvStack_10;
    local_14 = &stack0xffffff90;
    (**(code **)(*param_3 + 4))();
  }
  local_8._0_1_ = 2;
  local_18 = &stack0xffffff8c;
  local_44 = &stack0xffffff8c;
  local_40 = local_1c;
  piVar5 = local_1c;
  puVar1 = &stack0xffffff8c;
  puVar2 = &stack0xffffff8c;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 4))(local_1c);
    piVar5 = (int *)0x10015d1d;
    puVar1 = local_44;
    puVar2 = local_18;
  }
  local_18 = puVar2;
  local_44 = puVar1;
  local_64[2] = local_44;
  local_8._0_1_ = 5;
  local_64[0] = (undefined1 *)FUN_10017710(local_38,param_2);
  local_8._0_1_ = 7;
  local_64[1] = local_64[0];
  FUN_100032a0((void *)(param_1 + 0x24),(undefined4 *)local_64[0],piVar5);
  local_8._0_1_ = 8;
  FUN_10003620(local_38,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))();
  }
  FUN_10015db8();
  return;
}



// Function: Catch@10015d9e at 10015d9e

undefined * Catch_10015d9e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x38) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015dc1;
}



// Function: FUN_10015db8 at 10015db8

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10015db8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10015df0 at 10015df0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10015df0(void *this,int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 local_40 [5];
  uint local_2c;
  int local_28 [2];
  undefined4 local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b521;
  local_10 = ExceptionList;
  puVar2 = local_40;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = 0;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_10017510(local_20,(int)this + 4);
  local_8 = 1;
  uVar3 = FUN_100160b0(local_14,local_28,param_2);
  FUN_10015f90(local_14,param_1,*(int *)uVar3);
  local_2c = local_2c | 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10017560(local_20);
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10015ea0);
  ExceptionList = local_10;
  return CONCAT44(uVar4,param_1);
}



// Function: FUN_10015ec0 at 10015ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10015ec0(void *this,int *param_1,ushort *param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 local_4c [8];
  uint local_2c;
  int local_28 [2];
  undefined4 local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b521;
  local_10 = ExceptionList;
  puVar2 = local_4c;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = 0;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_10017510(local_20,(int)this + 4);
  local_8 = 1;
  uVar3 = FUN_10003a20((void *)((int)local_14 + 0x3c),local_28,param_2);
  FUN_10015f90(local_14,param_1,*(int *)uVar3);
  local_2c = local_2c | 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10017560(local_20);
  uVar4 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10015f74);
  ExceptionList = local_10;
  return CONCAT44(uVar4,param_1);
}



// Function: FUN_10015f90 at 10015f90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10015f90(void *this,int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_38 [2];
  char *local_30;
  int local_2c;
  undefined4 local_28;
  undefined **local_24 [3];
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b573;
  local_10 = ExceptionList;
  piVar2 = local_38;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  local_28 = 0;
  local_2c = *(int *)((int)this + 0x40);
  local_18 = local_2c;
  local_14 = this;
  if (param_2 == local_2c) {
    local_30 = "CDualCollection::getItemAtIter() - Unable to find item to retrieve";
    ExceptionList = &local_10;
    std::exception::exception((exception *)local_24,&local_30);
    local_24[0] = std::out_of_range::vftable;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_24,(ThrowInfo *)&DAT_10026cbc);
  }
  local_38[1] = param_2 + 0xc;
  local_38[0] = *(int *)(param_2 + 0x28);
  ExceptionList = &local_10;
  *param_1 = local_38[0];
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100160b0 at 100160b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100160b0(void *this,int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_3c [6];
  int local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int local_10 [2];
  void *local_8;
  
  piVar2 = local_3c;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = (int)&DAT_cccccccc;
    piVar2 = piVar2 + 1;
  }
  piVar2 = *(int **)((int)this + 0x40);
  local_24 = *piVar2;
  local_18 = (int *)0x0;
  local_20 = piVar2;
  local_10[0] = local_24;
  local_8 = this;
  while ((int)local_18 < param_2) {
    local_3c[1] = local_10[0];
    FUN_10013a30(local_10);
    local_1c = local_3c[1];
    piVar2 = (int *)((int)local_18 + 1);
    local_18 = piVar2;
  }
  *param_1 = local_10[0];
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016140);
  return CONCAT44(piVar2,param_1);
}



// Function: FUN_10016170 at 10016170

undefined4 * __thiscall FUN_10016170(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10016190 at 10016190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100161c1) */

undefined4 * __thiscall
FUN_10016190(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    *puVar2 = &DAT_cccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0x7ffffff;
  local_64[0] = 0x7ffffff;
  local_8 = this;
  if (0x7fffffd < *(uint *)((int)this + 8)) {
    FUN_10013af0((int)this + 0xd,param_4 + 3);
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
  while (*(char *)(local_c[1] + 0x2c) == '\0') {
    local_20 = (undefined4 *)(local_c[1] + 4);
    local_24 = (int *)*local_20;
    if (local_c[1] == *local_24) {
      local_28 = (int *)(local_c[1] + 4);
      iVar1 = *(int *)(*local_28 + 8);
      if (*(char *)(iVar1 + 0x2c) == '\0') {
        *(undefined1 *)(local_c[1] + 0x2c) = 1;
        *(undefined1 *)(iVar1 + 0x2c) = 1;
        local_2c = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_2c + 0x2c) = 0;
        local_c = *(int **)(local_c[1] + 4);
      }
      else {
        if (local_c == *(int **)(local_c[1] + 8)) {
          local_c = (int *)local_c[1];
          FUN_10013970(local_8,(int)local_c);
        }
        *(undefined1 *)(local_c[1] + 0x2c) = 1;
        local_38 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_38 + 0x2c) = 0;
        FUN_100047c0(local_8,*(int **)(local_c[1] + 4));
      }
    }
    else {
      local_40 = (undefined4 *)(local_c[1] + 4);
      local_44 = (int *)*local_40;
      iVar1 = *local_44;
      if (*(char *)(iVar1 + 0x2c) == '\0') {
        *(undefined1 *)(local_c[1] + 0x2c) = 1;
        *(undefined1 *)(iVar1 + 0x2c) = 1;
        local_48 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_48 + 0x2c) = 0;
        local_c = *(int **)(local_c[1] + 4);
      }
      else {
        local_4c = (int *)local_c[1];
        if (local_c == (int *)*local_4c) {
          local_c = (int *)local_c[1];
          FUN_100047c0(local_8,local_c);
        }
        *(undefined1 *)(local_c[1] + 0x2c) = 1;
        local_54 = (int *)(local_c[1] + 4);
        *(undefined1 *)(*local_54 + 0x2c) = 0;
        FUN_10013970(local_8,*(int *)(local_c[1] + 4));
      }
    }
  }
  *(undefined1 *)(*(int *)(*(int *)((int)local_8 + 4) + 4) + 0x2c) = 1;
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_10016490 at 10016490

void __thiscall FUN_10016490(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b580;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  puVar1 = FUN_10016540((int)this);
  local_8 = 0;
  FUN_10016690((int)this + 0xd,puVar1 + 3,param_1);
  FUN_10016513();
  return;
}



// Function: Catch@100164f1 at 100164f1

void Catch_100164f1(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10016513 at 10016513

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10016513(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10016540 at 10016540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10016540(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10013b60(1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(puVar1 + 0xb) = 0;
  *(undefined1 *)((int)puVar1 + 0x2d) = 0;
  return puVar1;
}



// Function: FUN_100165b0 at 100165b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100165b0(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b5bb;
  local_10 = ExceptionList;
  local_1c = &DAT_cccccccc;
  local_18 = (int)&local_1c + 3;
  local_8 = 0;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_10003620(this,'\0',0);
  FUN_100055e0(local_14,param_1);
  local_8 = 1;
  piVar1 = (int *)((int)local_14 + 0x1c);
  *piVar1 = *param_2;
  if (*piVar1 != 0) {
    (**(code **)(*(int *)*piVar1 + 4))(*piVar1);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10016690 at 10016690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10016690(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b5e1;
  local_10 = ExceptionList;
  local_8 = 0;
  if (param_2 != (void *)0x0) {
    ExceptionList = &local_10;
    FUN_10016720(param_2,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016720 at 10016720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10016720(void *this,undefined4 *param_1)

{
  undefined4 local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b623;
  local_10 = ExceptionList;
  local_1c = &DAT_cccccccc;
  local_18 = (int)&local_1c + 3;
  local_8 = 0;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_10003620(this,'\0',0);
  FUN_100055e0(local_14,param_1);
  *(undefined4 *)((int)local_14 + 0x1c) = 0;
  *(undefined4 *)((int)local_14 + 0x1c) = param_1[7];
  param_1[7] = 0;
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10016800 at 10016800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10016800(void *this,int *param_1)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *local_a0 [4];
  undefined4 local_90;
  undefined4 *local_8c;
  int local_84;
  int *local_80;
  undefined4 *local_78;
  LPVOID *local_68;
  int local_64;
  undefined4 *local_60;
  undefined1 local_55;
  undefined1 *local_54;
  int local_50;
  undefined4 local_4c [7];
  int local_30;
  undefined4 local_28 [5];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b913;
  local_10 = ExceptionList;
  ppiVar3 = local_a0;
  for (iVar2 = 0x24; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_a0[3] = (int *)((int)this + 4);
  local_54 = &local_55;
  *local_a0[3] = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_60 = local_a0[3];
  local_14 = (int *)this;
  FUN_10016e00(local_a0[3],5);
  local_8._0_1_ = 3;
  if ((int *)*local_14 == param_1) {
    local_64 = *local_14;
  }
  else {
    FUN_10002ff0(local_14,param_1);
  }
  FUN_10004880(local_28);
  local_8._0_1_ = 4;
  for (local_30 = 0; local_30 < 5; local_30 = local_30 + 1) {
    local_68 = (LPVOID *)(local_14[1] + local_30 * 4);
    HVar1 = CoCreateInstance((IID *)&DAT_100239f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10024000,local_68)
    ;
    uVar5 = 0x10016922;
    FUN_10004900(local_28,HVar1);
    FUN_10003170(local_4c,(wchar_t *)(&PTR_u_Vehicle_Information_1002cd14)[local_30]);
    local_8._0_1_ = 5;
    local_78 = (undefined4 *)(local_14[1] + local_30 * 4);
    local_a0[2] = (int *)*local_78;
    local_a0[1] = FUN_100177c0(&local_50,local_4c);
    local_8._0_1_ = 6;
    local_84 = *local_a0[1];
    local_80 = local_a0[1];
    uVar5 = (**(code **)(*local_a0[2] + 0x10))(local_a0[2],local_84,uVar5);
    uVar4 = 0x100169b1;
    FUN_10004900(local_28,uVar5);
    local_8._0_1_ = 5;
    Ordinal_6(local_50,uVar4);
    uVar5 = 0x100169d1;
    local_8._0_1_ = 7;
    FUN_10003620(local_4c,'\x01',0);
    local_8._0_1_ = 4;
    local_a0[0] = (int *)*local_14;
    local_8c = (undefined4 *)(local_14[1] + local_30 * 4);
    local_90 = *local_8c;
    uVar5 = (**(code **)(*local_a0[0] + 0x14))(local_a0[0],local_90,uVar5);
    FUN_10004900(local_28,uVar5);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_100048e0(local_28);
  local_8 = 0xffffffff;
  uVar5 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016a94);
  ExceptionList = local_10;
  return CONCAT44(uVar5,local_14);
}



// Function: FUN_10016ab0 at 10016ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10016ab0(int *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b943;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  uVar2 = FUN_100063d0((_Container_base0 *)(param_1 + 1));
  uVar1 = (undefined4)uVar2;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    uVar1 = (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10016b60 at 10016b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10016b60(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int local_44 [4];
  int local_34 [3];
  undefined4 local_28 [6];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b960;
  local_10 = ExceptionList;
  piVar3 = local_44;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = (int)&DAT_cccccccc;
    piVar3 = piVar3 + 1;
  }
  ExceptionList = &local_10;
  FUN_10004880(local_28);
  local_34[0] = 0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x10))(param_1,local_34);
  uVar5 = 0x10016bc6;
  FUN_10004900(local_28,uVar1);
  local_44[0] = local_34[0];
  uVar4 = FUN_10017880(local_34[0]);
  local_44[2] = (int)uVar4;
  local_44[1] = 0;
  do {
    if (4 < local_44[1]) {
LAB_10016c23:
      local_8 = local_8 & 0xffffff00;
      Ordinal_6(local_34[0],uVar5);
      local_8 = 0xffffffff;
      uVar4 = FUN_100048e0(local_28);
      uVar1 = (undefined4)((ulonglong)uVar4 >> 0x20);
      _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016c78);
      ExceptionList = local_10;
      return CONCAT44(uVar1,(int)uVar4);
    }
    if (local_44[2] <= *(int *)(&DAT_100241f8 + local_44[1] * 4)) {
      FUN_10016cb0(local_44[1],local_34[0],param_1);
      goto LAB_10016c23;
    }
    local_44[1] = local_44[1] + 1;
  } while( true );
}



// Function: FUN_10016cb0 at 10016cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10016cb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_48 [5];
  int *local_34 [3];
  undefined4 local_28 [5];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b990;
  local_10 = ExceptionList;
  ppiVar3 = local_48;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &local_10;
  FUN_10004880(local_28);
  local_34[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_48[3] = (int *)(*(int *)(local_14 + 4) + param_1 * 4);
  local_48[1] = (int *)*local_48[3];
  uVar1 = (**(code **)(*local_48[1] + 0x14))(local_48[1],local_34);
  uVar5 = 0x10016d37;
  FUN_10004900(local_28,uVar1);
  local_48[0] = local_34[0];
  uVar1 = (**(code **)(*local_34[0] + 0x14))(local_34[0],param_2,param_3,uVar5);
  uVar5 = 0x10016d65;
  FUN_10004900(local_28,uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))(local_34[0],uVar5);
  }
  local_8 = 0xffffffff;
  uVar4 = FUN_100048e0(local_28);
  uVar1 = (undefined4)((ulonglong)uVar4 >> 0x20);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016dd0);
  ExceptionList = local_10;
  return CONCAT44(uVar1,(int)uVar4);
}



// Function: FUN_10016e00 at 10016e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10016e00(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_60;
  undefined8 local_5c;
  undefined1 local_51;
  undefined1 local_49;
  int *local_30;
  int local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar3 = &local_60;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = (int)&DAT_cccccccc;
    piVar3 = piVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_8 = (int *)this;
  if (param_1 < (uint)(*(int *)((int)this + 4) - *this >> 2)) {
    local_24 = *(int **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    local_28 = *this;
    local_30 = (int *)(local_28 + param_1 * 4);
    local_1c = local_30;
    local_18 = local_28;
    local_14 = local_30;
    local_10 = local_24;
    local_c = local_24;
    uVar4 = FUN_10016f70(this,&local_20,local_30,local_24);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *(int *)((int)this + 4) - *this >> 2;
    uVar4 = CONCAT44(this,uVar1);
    if (uVar1 < param_1) {
                    /* WARNING: Load size is inaccurate */
      FUN_10006320(this,param_1 - (*(int *)((int)this + 4) - *this >> 2));
      local_60 = param_1 - (local_8[1] - *local_8 >> 2);
      local_5c = CONCAT44(local_5c._4_4_,(undefined4 *)local_8[1]);
      local_49 = local_51;
      FUN_100170e0((undefined4 *)local_8[1],local_60,0,local_8 + 3);
      uVar4 = CONCAT44(local_8,local_8[1]);
      local_8[1] = local_8[1] + (param_1 - (local_8[1] - *local_8 >> 2)) * 4;
    }
  }
  local_60 = 0x10016f31;
  local_5c = uVar4;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016f44);
  return local_5c;
}



// Function: FUN_10016f70 at 10016f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10016f70(void *this,int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int **ppiVar2;
  int *local_6c [2];
  undefined1 local_61;
  undefined1 local_59;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  undefined1 local_41;
  undefined1 local_39;
  int *local_38;
  int *local_34;
  int *local_28;
  int *local_24;
  int *local_1c;
  int *local_10;
  void *local_8;
  
  ppiVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)&DAT_cccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_10 = param_2;
  local_1c = param_3;
  local_8 = this;
  if (param_2 != param_3) {
    local_54 = param_2;
    local_50 = *(int **)((int)this + 4);
    local_4c = param_3;
    local_39 = local_41;
    local_38 = param_2;
    for (local_34 = param_3; local_34 != local_50; local_34 = local_34 + 1) {
      if (local_38 != local_34) {
        FUN_10017200(local_38,local_34);
      }
      local_38 = local_38 + 1;
    }
    local_24 = local_38;
    local_6c[0] = *(int **)((int)local_8 + 4);
    local_59 = local_61;
    for (local_58 = local_38; local_58 != local_6c[0]; local_58 = local_58 + 1) {
      FUN_100069c0((int)local_8 + 0xc,local_58);
    }
    *(int **)((int)local_8 + 4) = local_24;
  }
  local_28 = local_10;
  *param_1 = (int)local_10;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10017090);
  return CONCAT44(local_10,param_1);
}



// Function: FUN_100170e0 at 100170e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100170e0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b9c8;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffd4;
  local_1c = (int *)&DAT_cccccccc;
  local_18 = param_1;
  local_8 = 0;
  ExceptionList = &pvStack_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_1c = (int *)0x0;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 3;
    FUN_10006780(param_4,param_1,&local_1c);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    param_1 = param_1 + 1;
  }
  FUN_100171d7();
  return;
}



// Function: FUN_1001719e at 1001719e

void FUN_1001719e(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 8)) {
    FUN_100069c0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_1001719e();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100171a7 at 100171a7

void FUN_100171a7(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 8)) {
    FUN_100069c0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_1001719e();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100171d7 at 100171d7

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100171d7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10017200 at 10017200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10017200(void *this,int *param_1)

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



// Function: FUN_100172a0 at 100172a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100172a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_48 [8];
  undefined4 *local_28;
  undefined1 local_19;
  undefined1 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bcab;
  local_10 = ExceptionList;
  ppuVar2 = local_48;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)&DAT_cccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = CSyncObjectBase::vftable;
  *param_1 = CCriticalSection::vftable;
  local_48[0] = param_1 + 7;
  local_18 = &local_19;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_28 = local_48[0];
  local_14 = param_1;
  FUN_10003620(local_48[0],'\0',0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10003f10(local_14 + 7,(undefined4 *)&stack0x00000004,0,0xffffffff);
  InitializeCriticalSection((LPCRITICAL_SECTION)(local_14 + 1));
  local_8 = 4;
  FUN_10003620(&stack0x00000004,'\x01',0);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10017380 at 10017380

void __fastcall FUN_10017380(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_100173a0 at 100173a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100173a0(void *this,uint param_1)

{
  FUN_100173e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100173e0 at 100173e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100173e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bcdb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CCriticalSection::vftable;
  local_8 = 1;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  FUN_10003620(param_1 + 7,'\x01',0);
  *param_1 = CSyncObjectBase::vftable;
  ExceptionList = local_10;
  return;
}



// Function: AddRef at 10017490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual long __thiscall ATL::IDocument::AddRef(void)
   
   Library: Visual Studio 2012 Debug */

long __thiscall ATL::IDocument::AddRef(IDocument *this)

{
  long extraout_EAX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 4));
  return extraout_EAX;
}



// Function: AddRef at 100174d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual long __thiscall ATL::IDocument::AddRef(void)
   
   Library: Visual Studio 2012 Debug */

long __thiscall ATL::IDocument::AddRef(IDocument *this)

{
  long extraout_EAX;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 4));
  return extraout_EAX;
}



// Function: FUN_10017510 at 10017510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017510(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**this + 4))();
  *(undefined1 *)((int)this + 4) = 1;
  return (undefined4 *)this;
}



// Function: FUN_10017560 at 10017560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10017560(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    (**(code **)(*(int *)*param_1 + 8))();
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100175b0 at 100175b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10017600) */
/* WARNING: Removing unreachable block (ram,0x1001761e) */

undefined8 __cdecl FUN_100175b0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined2 uVar2;
  undefined2 uStack_46;
  undefined4 uVar3;
  undefined4 local_24;
  undefined1 *local_20;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001bd91;
  local_10 = ExceptionList;
  local_20 = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  local_14 = &DAT_cccccccc;
  local_24 = 0xcccc0003;
  local_1c = param_2;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_10017a00(8,(int)&local_24,0,0x409);
  if (local_1c == 0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(local_1c);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      FUN_100019e0(0x8007000e);
    }
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(&local_24);
  uVar2 = SUB42(param_1,0);
  uStack_46 = (undefined2)((uint)param_1 >> 0x10);
  uVar3 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100176f0);
  ExceptionList = local_10;
  return CONCAT44(uVar3,CONCAT22(uStack_46,uVar2));
}



// Function: FUN_10017710 at 10017710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10017710(void *param_1,wchar_t *param_2)

{
  int iVar1;
  void **ppvVar2;
  void *local_64 [14];
  undefined1 local_29;
  undefined1 *local_28;
  undefined4 local_24;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bdc1;
  local_10 = ExceptionList;
  ppvVar2 = local_64;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = &DAT_cccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_24 = 0;
  if (param_2 == (wchar_t *)0x0) {
    local_28 = &local_29;
    local_64[0] = param_1;
    local_8 = 1;
    ExceptionList = &local_10;
    FUN_10003620(param_1,'\0',0);
  }
  else {
    local_18 = 3;
    ExceptionList = &local_10;
    FUN_10003170(param_1,param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100177c0 at 100177c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __cdecl FUN_100177c0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bde9;
  local_10 = ExceptionList;
  if ((uint)param_2[5] < 8) {
    local_18 = param_2;
  }
  else {
    local_18 = (undefined4 *)*param_2;
  }
  if (local_18 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    ExceptionList = &local_10;
    iVar1 = Ordinal_2(local_18);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      FUN_100019e0(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017880 at 10017880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10017880(int param_1)

{
  undefined1 *puVar1;
  undefined4 extraout_EDX;
  undefined2 uVar2;
  undefined2 uStack_42;
  undefined4 uVar3;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001be08;
  local_10 = ExceptionList;
  local_20 = &DAT_cccccccc;
  local_1c = &DAT_cccccccc;
  local_18 = &DAT_cccccccc;
  local_14 = &DAT_cccccccc;
  local_24 = 0xcccc0000;
  ExceptionList = &local_10;
  FUN_10017950(&local_24,param_1);
  local_8 = 0;
  FUN_10017a00(3,(int)&local_24,0,0x409);
  puVar1 = local_1c;
  local_8 = 0xffffffff;
  Ordinal_9(&local_24);
  uVar2 = SUB42(puVar1,0);
  uStack_42 = (undefined2)((uint)puVar1 >> 0x10);
  uVar3 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10017938);
  ExceptionList = local_10;
  return CONCAT44(uVar3,CONCAT22(uStack_42,uVar2));
}



// Function: FUN_10017950 at 10017950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined2 * __thiscall FUN_10017950(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  uVar2 = 0x1001797b;
  if (iVar1 < 0) {
    FUN_100019e0(iVar1);
  }
  *(undefined2 *)this = 8;
  uVar2 = Ordinal_2(param_1,uVar2);
  *(undefined4 *)((int)this + 8) = uVar2;
  if ((*(int *)((int)this + 8) == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    FUN_100019e0(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_10017a00 at 10017a00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10017a00(undefined2 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 local_8;
  
  local_8 = param_3;
  if (param_3 == 0) {
    local_8 = param_2;
  }
  Ordinal_147(local_8,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10017a50 at 10017a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10017a50(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c0d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_8 = 1;
  FUN_10018130(this,param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017ad0 at 10017ad0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10017c01) */

undefined8 FUN_10017ad0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined4 uVar4;
  int *local_64 [4];
  uint local_54;
  undefined4 local_4c [3];
  int *local_40 [3];
  int *local_34 [3];
  undefined4 local_28 [5];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c151;
  local_10 = ExceptionList;
  ppiVar3 = local_64;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_54 = 0;
  ExceptionList = &local_10;
  FUN_10004880(local_28);
  local_34[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  local_64[2] = (int *)*local_14;
  uVar1 = (**(code **)(*local_64[2] + 0x28))(local_64[2],local_34);
  uVar4 = 0x10017b4f;
  FUN_10004900(local_28,uVar1);
  local_40[0] = (int *)0x0;
  local_8._0_1_ = 5;
  local_64[1] = local_34[0];
  uVar1 = (**(code **)(*local_34[0] + 0x30))(local_34[0],local_40,uVar4);
  uVar4 = 0x10017b88;
  FUN_10004900(local_28,uVar1);
  local_4c[0] = 0;
  local_8._0_1_ = 7;
  local_64[0] = local_40[0];
  uVar1 = (**(code **)(*local_40[0] + 0x24))(local_40[0],local_4c,uVar4);
  uVar4 = 0x10017bc1;
  FUN_10004900(local_28,uVar1);
  *param_1 = 0;
  *param_1 = local_4c[0];
  local_54 = local_54 | 1;
  local_4c[0] = 0;
  local_8._0_1_ = 3;
  if (local_40[0] != (int *)0x0) {
    (**(code **)(*local_40[0] + 8))(local_40[0],uVar4);
    uVar4 = 0x10017c3d;
  }
  local_8._0_1_ = 1;
  if (local_34[0] != (int *)0x0) {
    (**(code **)(*local_34[0] + 8))(local_34[0],uVar4);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100048e0(local_28);
  uVar1 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10017ca0);
  ExceptionList = local_10;
  return CONCAT44(uVar1,param_1);
}



// Function: FUN_10017cf0 at 10017cf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10017e59) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_10017cf0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_78 [5];
  undefined4 *local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int *local_3c [2];
  undefined4 local_34 [3];
  undefined4 local_28 [6];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c1b9;
  local_10 = ExceptionList;
  ppiVar3 = local_78;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  local_60 = 0;
  ExceptionList = &local_10;
  FUN_10004880(local_28);
  local_34[0] = 0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  local_5c = (uint)local_5c._2_2_ << 0x10;
  FUN_10017950(&local_5c,param_2);
  local_78[2] = &local_5c;
  local_8._0_1_ = 4;
  local_4c = local_5c;
  local_48 = local_58;
  local_44 = local_54;
  local_40 = local_50;
  uVar4 = FUN_10017ad0(local_3c);
  local_78[1] = (int *)uVar4;
  local_8._0_1_ = 5;
  local_78[0] = (int *)*local_78[1];
  local_64 = local_78[1];
  uVar1 = (**(code **)(*local_78[0] + 0x1c))
                    (local_78[0],local_4c,local_48,local_44,local_40,local_34);
  uVar5 = 0x10017dda;
  FUN_10004900(local_28,uVar1);
  local_8._0_1_ = 4;
  if (local_3c[0] != (int *)0x0) {
    (**(code **)(*local_3c[0] + 8))(local_3c[0],uVar5);
    uVar5 = 0x10017e08;
  }
  local_8._0_1_ = 3;
  local_78[3] = (int *)Ordinal_9(&local_5c,uVar5);
  *param_1 = 0;
  *param_1 = local_34[0];
  local_60 = local_60 | 1;
  local_34[0] = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100048e0(local_28);
  uVar1 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10017eac);
  ExceptionList = local_10;
  return CONCAT44(uVar1,param_1);
}



// Function: FUN_10017ee0 at 10017ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10017ee0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int **ppiVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int *local_60 [4];
  undefined4 *local_50;
  int local_4c;
  undefined4 local_44;
  int *local_40;
  undefined4 local_3c [2];
  int local_34 [3];
  undefined4 local_28 [5];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c1f0;
  local_10 = ExceptionList;
  ppiVar3 = local_60;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppiVar3 = (int *)&DAT_cccccccc;
    ppiVar3 = ppiVar3 + 1;
  }
  ExceptionList = &local_10;
  FUN_10004880(local_28);
  local_34[0] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_60[2] = (int *)*local_14;
  uVar1 = (**(code **)(*local_60[2] + 0x20))(local_60[2],local_34);
  uVar5 = 0x10017f54;
  FUN_10004900(local_28,uVar1);
  local_3c[0] = 0;
  local_4c = local_34[0];
  uVar4 = FUN_10017cf0(&local_40,local_34[0]);
  local_60[1] = (int *)uVar4;
  local_8._0_1_ = 2;
  local_60[0] = (int *)*local_60[1];
  local_50 = local_60[1];
  (**(code **)(*local_60[0] + 0x38))(local_60[0],local_3c,uVar5);
  uVar1 = 0x10017fb0;
  local_8._0_1_ = 1;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40,0x10017fb0);
    uVar1 = 0x10017fd5;
  }
  local_44 = local_3c[0];
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_34[0],uVar1);
  local_8 = 0xffffffff;
  FUN_100048e0(local_28);
  uVar1 = local_44;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10018030);
  ExceptionList = local_10;
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_10018060 at 10018060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10018060(int *param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c218;
  local_10 = ExceptionList;
  local_18 = (int *)&DAT_cccccccc;
  local_14 = &DAT_cccccccc;
  ExceptionList = &local_10;
  FUN_10017a50(&local_18,param_1);
  local_8 = 0;
  uVar2 = FUN_10017ee0();
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
    uVar1 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001810c);
  ExceptionList = local_10;
  return CONCAT44(uVar1,(int)uVar2);
}



// Function: FUN_10018130 at 10018130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10018130(void *this,int *param_1)

{
  int *local_c;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == param_1) {
                    /* WARNING: Load size is inaccurate */
    local_c = *this;
  }
  else if (this == (void *)0x0) {
    local_c = (int *)0x0;
  }
  else {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**this + 8))(*this);
    }
    *(int **)this = param_1;
    local_c = param_1;
  }
  return local_c;
}



// Function: FUN_100181f2 at 100181f2

void __fastcall FUN_100181f2(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10018211 at 10018211

int __fastcall FUN_10018211(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10018236 at 10018236

void __fastcall FUN_10018236(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_100181f2((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1001824e at 1001824e

undefined4 * __fastcall FUN_1001824e(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_10018211((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1002484c;
  DVar1 = FUN_1000bb20((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)DVar1 < 0) {
    DAT_1002d0ec = 1;
  }
  return param_1;
}



// Function: FUN_1001828e at 1001828e

void __fastcall FUN_1001828e(int *param_1)

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



// Function: FUN_100182d2 at 100182d2

int __fastcall FUN_100182d2(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100182eb at 100182eb

undefined4 * __fastcall FUN_100182eb(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_100182d2((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1002a9e0;
  param_1[3] = &DAT_1002a9e0;
  DVar1 = FUN_1000bb20((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)DVar1 < 0) {
    DAT_1002d0ec = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1001832c at 1001832c

void FUN_1001832c(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __RTC_CheckEsp at 1001834a

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



// Function: _RTC_CheckStackVars at 1001836d

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
      if ((*(undefined1 **)(iVar1 + -4 + param_1) != &DAT_cccccccc) ||
         (*(undefined1 **)(*(int *)(param_2[1] + 4 + iVar2) + iVar1 + param_1) != &DAT_cccccccc)) {
        _RTC_StackFailure(unaff_retaddr,*(char **)(param_2[1] + 8 + iVar2));
      }
      local_8 = local_8 + 1;
      iVar2 = iVar2 + 0xc;
    } while (local_8 < *param_2);
  }
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10018408

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



// Function: __onexit at 1001846c

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
  
  local_8 = &DAT_1002a8d8;
  uStack_c = 0x10018478;
  local_20[0] = DecodePointer(DAT_1002dfd4);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1002dfd4);
    local_24 = DecodePointer(DAT_1002dfd0);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1002dfd4 = EncodePointer(local_20[0]);
    DAT_1002dfd0 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10018504();
  }
  return p_Var1;
}



// Function: FUN_10018504 at 10018504

void FUN_10018504(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001850d

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10018530

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



// Function: __ArrayUnwind at 10018568

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



// Function: `eh_vector_destructor_iterator' at 100185c6

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
  FUN_10018611();
  return;
}



// Function: FUN_10018611 at 10018611

void FUN_10018611(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 10018629

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
  FUN_10018676();
  return;
}



// Function: FUN_10018676 at 10018676

void FUN_10018676(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __alloca_probe_16 at 10018690

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



// Function: __alloca_probe_8 at 100186a6

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



// Function: __CRT_INIT@12 at 10018742

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
    if (DAT_1002dc80 < 1) {
      return 0;
    }
    DAT_1002dc80 = DAT_1002dc80 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002dfc8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002dfc4 == 2) {
      param_2 = (int *)DecodePointer(DAT_1002dfd4);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1002dfd0);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1002dfd4);
            piVar8 = (int *)DecodePointer(DAT_1002dfd0);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1002dfd0 = (PVOID)encoded_null();
        DAT_1002dfd4 = DAT_1002dfd0;
      }
      DAT_1002dfc4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1002dfc8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002dfc8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002dfc4 == 0) {
      DAT_1002dfc4 = 1;
      iVar5 = initterm_e(&DAT_10023420,&DAT_10023428);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100231dc,&DAT_1002341c);
      DAT_1002dfc4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1002dfc8,0);
    }
    if ((DAT_1002dfcc != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1002dfcc), BVar2 != 0)) {
      (*DAT_1002dfcc)(param_1,2,param_3);
    }
    DAT_1002dc80 = DAT_1002dc80 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001894c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100189ec) */
/* WARNING: Removing unreachable block (ram,0x10018999) */
/* WARNING: Removing unreachable block (ram,0x10018a19) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1002cda0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002dc80 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10006b80(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10006b80(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10018a57();
  return local_20;
}



// Function: FUN_10018a57 at 10018a57

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10018a57(void)

{
  _DAT_1002cda0 = 0xffffffff;
  return;
}



// Function: entry at 10018a62

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: DebuggerProbe at 10018a85

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
  
  uStack_c = 0x10018a91;
  local_1d[0] = 0;
  local_38[0] = 0x1001;
  local_30 = local_1d;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,local_38);
  return (uint)local_1d[0];
}



// Function: DebuggerRuntime at 10018ad5

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
  
  uStack_c = 0x10018ae1;
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



// Function: failwithmessage at 10018b37

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
  
  local_8 = DAT_1002cda8 ^ (uint)&stack0xfffffffc;
  local_e3c = (code *)0x0;
  local_e34 = (code *)FUN_10018e8d();
  if (local_e34 == (code *)0x0) {
    local_e3c = (code *)FUN_10018e87();
  }
  cchWideChar = MultiByteToWideChar(0xfde9,0,in_EDX,-1,(LPWSTR)0x0,0);
  if (cchWideChar < 0x200) {
    iVar3 = MultiByteToWideChar(0xfde9,0,in_EDX,-1,local_e30,cchWideChar);
    pwVar6 = local_e30;
    if (iVar3 == 0) goto LAB_10018bc7;
  }
  else {
LAB_10018bc7:
    pwVar6 = L"Runtime Check Error.\n\r Unable to display RTC Message.";
  }
  iVar3 = DebuggerProbe((ulong)unaff_EDI);
  if (iVar3 == 0) {
    bVar2 = true;
  }
  else {
    iVar3 = DebuggerRuntime(*(ulong *)(&DAT_10024b28 + param_2 * 4),local_e38,pwVar6,unaff_EDI);
    if (iVar3 != 0) goto LAB_10018d2e;
    bVar2 = false;
  }
  if ((local_e3c != (code *)0x0) || (local_e34 != (code *)0x0)) {
    if (bVar2) {
      BVar4 = IsDebuggerPresent();
      if (BVar4 != 0) goto LAB_10018d2d;
    }
    FUN_100192ee(local_e38 - 5,local_418,0x104,&local_e38,local_210,0x104);
    if (local_e34 == (code *)0x0) {
      local_e34 = (code *)0x10024be0;
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
LAB_10018d2e:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_10018d2d:
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: _RTC_Failure at 10018d3d

/* Library Function - Single Match
    void __cdecl _RTC_Failure(void *,int)
   
   Library: Visual Studio 2010 Release */

void __cdecl _RTC_Failure(void *param_1,int param_2)

{
  void *pvVar1;
  int unaff_EBP;
  char *unaff_retaddr;
  
  if ((uint)param_2 < 5) {
    pvVar1 = *(void **)(&DAT_1002cd80 + param_2 * 4);
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



// Function: _RTC_StackFailure at 10018d78

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
  
  local_8 = DAT_1002cda8 ^ (uint)&stack0xfffffffc;
  local_40c = param_1;
  if (DAT_1002cd88 != (void *)0xffffffff) {
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
        for (uVar2 = (uint)(pcVar3 + -0x10024b5b) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
          pcVar6 = pcVar6 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar2 = (uint)(pcVar3 + -0x10024b5b) & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar7 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
    }
    failwithmessage(DAT_1002cd88,2,unaff_EBX,unaff_ESI);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018e6b at 10018e6b

undefined4 __cdecl FUN_10018e6b(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_1002dc8c;
  DAT_1002dc88 = 0;
  DAT_1002dc8c = param_1;
  return uVar1;
}



// Function: FUN_10018e87 at 10018e87

undefined4 FUN_10018e87(void)

{
  return DAT_1002dc88;
}



// Function: FUN_10018e8d at 10018e8d

undefined4 FUN_10018e8d(void)

{
  return DAT_1002dc8c;
}



// Function: __SEH_prolog4 at 10018eb0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002cda8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10018ef5

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



// Function: FUN_10018f09 at 10018f09

void __cdecl
FUN_10018f09(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1002cda8,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 10018f90

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



// Function: __FindPESection at 10018fd0

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



// Function: __IsNonwritableInCurrentImage at 10019020

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
  
  pcStack_10 = FUN_10018f09;
  local_14 = ExceptionList;
  local_c = DAT_1002cda8 ^ 0x1002a9c0;
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



// Function: ___security_init_cookie at 100190f4

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
  if ((DAT_1002cda8 == 0xbb40e64e) || ((DAT_1002cda8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1002cda8 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1002cda8 == 0xbb40e64e) {
      DAT_1002cda8 = 0xbb40e64f;
    }
    else if ((DAT_1002cda8 & 0xffff0000) == 0) {
      DAT_1002cda8 = DAT_1002cda8 | (DAT_1002cda8 | 0x4711) << 0x10;
    }
    DAT_1002cdac = ~DAT_1002cda8;
  }
  else {
    DAT_1002cdac = ~DAT_1002cda8;
  }
  return;
}



// Function: FUN_1001918f at 1001918f

void FUN_1001918f(void)

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
  
  local_8 = DAT_1002cda8 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_100192ee at 100192ee

undefined4 __cdecl
FUN_100192ee(uint param_1,undefined2 *param_2,undefined4 param_3,uint *param_4,LPWSTR param_5,
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
  if (DAT_1002dc9d == '\0') {
    if (DAT_1002dc98 != (HMODULE)0x0) {
      return 0;
    }
    if (DAT_1002dc9c == '\0') {
      DAT_1002dc9c = '\x01';
      DAT_1002dc98 = (HMODULE)FUN_1001918f();
    }
    else {
      DAT_1002dc98 = (HMODULE)0x0;
    }
    if (DAT_1002dc98 == (HMODULE)0x0) {
      return 0;
    }
    DAT_1002dc9d = '\x01';
  }
  pFVar5 = GetProcAddress(DAT_1002dc98,"PDBOpenValidate5");
  if ((pFVar5 == (FARPROC)0x0) ||
     (iVar6 = (*pFVar5)(param_5,0,0,0,local_2c,0,0,&local_18), iVar6 == 0)) {
    return 0;
  }
  local_24 = 0;
  iVar6 = (**(code **)*local_18)();
  if ((iVar6 == 0x131a5b5) &&
     (iVar6 = (**(code **)(*local_18 + 0x1c))(0,&DAT_10024e80,&local_20), iVar6 != 0)) {
    iVar6 = (**(code **)(*local_20 + 0x20))(local_8,uVar11,&local_14,0,0,0);
    if (iVar6 != 0) {
      local_c = (int *)0x0;
      cVar1 = (**(code **)(*local_14 + 0x68))(&local_c);
      if ((cVar1 != '\0') && (local_c != (int *)0x0)) {
        puVar10 = (uint *)0x0;
        do {
          iVar6 = (**(code **)(*local_c + 8))();
          if (iVar6 == 0) goto LAB_10019543;
          cVar1 = (**(code **)(*local_c + 0xc))(0,&local_1c,&param_1,&local_28,&local_10,0);
          if (cVar1 == '\0') goto LAB_10019552;
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
LAB_10019543:
            DVar3 = 0;
            pvVar7 = GetProcessHeap();
            HeapFree(pvVar7,DVar3,puVar10);
          }
        }
LAB_10019552:
        (**(code **)*local_c)();
      }
      (**(code **)(*local_14 + 0x40))();
    }
    (**(code **)(*local_20 + 0x38))();
  }
  (**(code **)(*local_18 + 0x28))();
  return local_24;
}



// Function: __security_check_cookie at 10019579

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1002cda8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: ___report_gsfailure at 1001959a

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
  
  _DAT_1002ddb8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1002ddbc = &stack0x00000004;
  _DAT_1002dcf8 = 0x10001;
  _DAT_1002dca0 = 0xc0000409;
  _DAT_1002dca4 = 1;
  local_32c = DAT_1002cda8;
  local_328 = DAT_1002cdac;
  _DAT_1002dcac = unaff_retaddr;
  _DAT_1002dd84 = in_GS;
  _DAT_1002dd88 = in_FS;
  _DAT_1002dd8c = in_ES;
  _DAT_1002dd90 = in_DS;
  _DAT_1002dd94 = unaff_EDI;
  _DAT_1002dd98 = unaff_ESI;
  _DAT_1002dd9c = unaff_EBX;
  _DAT_1002dda0 = in_EDX;
  _DAT_1002dda4 = in_ECX;
  _DAT_1002dda8 = in_EAX;
  _DAT_1002ddac = unaff_EBP;
  DAT_1002ddb0 = unaff_retaddr;
  _DAT_1002ddb4 = in_CS;
  _DAT_1002ddc0 = in_SS;
  DAT_1002dcf0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10024e98);
  if (DAT_1002dcf0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: Unwind@100196b0 at 100196b0

void Unwind_100196b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@100196b8 at 100196b8

void Unwind_100196b8(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@100196c0 at 100196c0

void Unwind_100196c0(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100196c8 at 100196c8

void Unwind_100196c8(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@100196d3 at 100196d3

void Unwind_100196d3(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100196de at 100196de

void Unwind_100196de(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100196e6 at 100196e6

void Unwind_100196e6(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@100196f1 at 100196f1

void Unwind_100196f1(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100196f9 at 100196f9

void Unwind_100196f9(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10019704 at 10019704

void Unwind_10019704(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001970c at 1001970c

void Unwind_1001970c(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10019717 at 10019717

void Unwind_10019717(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001971f at 1001971f

void Unwind_1001971f(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001972a at 1001972a

void Unwind_1001972a(void)

{
  int unaff_EBP;
  
  FUN_10003210((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10019735 at 10019735

void Unwind_10019735(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001973d at 1001973d

void Unwind_1001973d(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}



// Function: Unwind@1001974b at 1001974b

void Unwind_1001974b(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@10019770 at 10019770

void Unwind_10019770(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001977b at 1001977b

void Unwind_1001977b(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@10019786 at 10019786

void Unwind_10019786(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10019791 at 10019791

void Unwind_10019791(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001979c at 1001979c

void Unwind_1001979c(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@100197a7 at 100197a7

void Unwind_100197a7(void)

{
  int unaff_EBP;
  
  FUN_10003210((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@100197b2 at 100197b2

void Unwind_100197b2(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}



// Function: Unwind@100197c0 at 100197c0

void Unwind_100197c0(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@100197ce at 100197ce

void Unwind_100197ce(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100197d6 at 100197d6

void Unwind_100197d6(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100197de at 100197de

void Unwind_100197de(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100197e6 at 100197e6

void Unwind_100197e6(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100197ee at 100197ee

void Unwind_100197ee(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100197f6 at 100197f6

void Unwind_100197f6(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@100197fe at 100197fe

void Unwind_100197fe(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x3c) + 4));
  return;
}



// Function: Unwind@10019809 at 10019809

void Unwind_10019809(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019811 at 10019811

void Unwind_10019811(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019830 at 10019830

void Unwind_10019830(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019838 at 10019838

void Unwind_10019838(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019840 at 10019840

void Unwind_10019840(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019848 at 10019848

void Unwind_10019848(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019850 at 10019850

void Unwind_10019850(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019858 at 10019858

void Unwind_10019858(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019860 at 10019860

void Unwind_10019860(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019868 at 10019868

void Unwind_10019868(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019870 at 10019870

void Unwind_10019870(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019878 at 10019878

void Unwind_10019878(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x8c);
  return;
}



// Function: Unwind@10019883 at 10019883

void Unwind_10019883(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001988b at 1001988b

void Unwind_1001988b(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019896 at 10019896

void Unwind_10019896(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@100198a1 at 100198a1

void Unwind_100198a1(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@100198ac at 100198ac

void Unwind_100198ac(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@100198b7 at 100198b7

void Unwind_100198b7(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@100198c2 at 100198c2

void Unwind_100198c2(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100198ca at 100198ca

void Unwind_100198ca(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100198d2 at 100198d2

void Unwind_100198d2(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100198da at 100198da

void Unwind_100198da(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100198e2 at 100198e2

void Unwind_100198e2(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019900 at 10019900

void Unwind_10019900(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019908 at 10019908

void Unwind_10019908(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019920 at 10019920

void Unwind_10019920(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019928 at 10019928

void Unwind_10019928(void)

{
  int unaff_EBP;
  
  FUN_10017560((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019930 at 10019930

void Unwind_10019930(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019938 at 10019938

void Unwind_10019938(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019940 at 10019940

void Unwind_10019940(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019960 at 10019960

void Unwind_10019960(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019968 at 10019968

void Unwind_10019968(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019970 at 10019970

void Unwind_10019970(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019978 at 10019978

void Unwind_10019978(void)

{
  int unaff_EBP;
  
  FUN_10017560((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10019983 at 10019983

void Unwind_10019983(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001998b at 1001998b

void Unwind_1001998b(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019993 at 10019993

void Unwind_10019993(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001999b at 1001999b

void Unwind_1001999b(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100199a3 at 100199a3

void Unwind_100199a3(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100199ab at 100199ab

void Unwind_100199ab(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x70);
  return;
}



// Function: Unwind@100199b3 at 100199b3

void Unwind_100199b3(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100199bb at 100199bb

void Unwind_100199bb(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100199d0 at 100199d0

void Unwind_100199d0(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100199d8 at 100199d8

void Unwind_100199d8(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@100199e0 at 100199e0

void Unwind_100199e0(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100199e8 at 100199e8

void Unwind_100199e8(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100199f0 at 100199f0

void Unwind_100199f0(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100199f8 at 100199f8

void Unwind_100199f8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019a00 at 10019a00

void Unwind_10019a00(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019a08 at 10019a08

void Unwind_10019a08(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019a10 at 10019a10

void Unwind_10019a10(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019a18 at 10019a18

void Unwind_10019a18(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019a30 at 10019a30

void Unwind_10019a30(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019a38 at 10019a38

void Unwind_10019a38(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019a40 at 10019a40

void Unwind_10019a40(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019a48 at 10019a48

void Unwind_10019a48(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019a50 at 10019a50

void Unwind_10019a50(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019a58 at 10019a58

void Unwind_10019a58(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@10019a63 at 10019a63

void Unwind_10019a63(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019a6b at 10019a6b

void Unwind_10019a6b(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019a73 at 10019a73

void Unwind_10019a73(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019a7b at 10019a7b

void Unwind_10019a7b(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019a83 at 10019a83

void Unwind_10019a83(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019a8b at 10019a8b

void Unwind_10019a8b(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019a93 at 10019a93

void Unwind_10019a93(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019a9b at 10019a9b

void Unwind_10019a9b(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019aa3 at 10019aa3

void Unwind_10019aa3(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019aab at 10019aab

void Unwind_10019aab(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019ab3 at 10019ab3

void Unwind_10019ab3(void)

{
  int unaff_EBP;
  
  FUN_10016ab0((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10019abe at 10019abe

void Unwind_10019abe(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019ac9 at 10019ac9

void Unwind_10019ac9(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019ad4 at 10019ad4

void Unwind_10019ad4(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x104);
  return;
}



// Function: Unwind@10019adf at 10019adf

void Unwind_10019adf(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10019aea at 10019aea

void Unwind_10019aea(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10019af5 at 10019af5

void Unwind_10019af5(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019b00 at 10019b00

void Unwind_10019b00(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019b0b at 10019b0b

void Unwind_10019b0b(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019b16 at 10019b16

void Unwind_10019b16(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019b21 at 10019b21

void Unwind_10019b21(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019b2c at 10019b2c

void Unwind_10019b2c(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x184));
  return;
}



// Function: Unwind@10019b37 at 10019b37

void Unwind_10019b37(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x184));
  return;
}



// Function: Unwind@10019b42 at 10019b42

void Unwind_10019b42(void)

{
  int unaff_EBP;
  
  FUN_10001a60(*(int **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@10019b4d at 10019b4d

void Unwind_10019b4d(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@10019b58 at 10019b58

void Unwind_10019b58(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019b63 at 10019b63

void Unwind_10019b63(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019b6e at 10019b6e

void Unwind_10019b6e(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019b79 at 10019b79

void Unwind_10019b79(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019b84 at 10019b84

void Unwind_10019b84(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019b8f at 10019b8f

void Unwind_10019b8f(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019b97 at 10019b97

void Unwind_10019b97(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019b9f at 10019b9f

void Unwind_10019b9f(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019ba7 at 10019ba7

void Unwind_10019ba7(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019baf at 10019baf

void Unwind_10019baf(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019bb7 at 10019bb7

void Unwind_10019bb7(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019bbf at 10019bbf

void Unwind_10019bbf(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019bc7 at 10019bc7

void Unwind_10019bc7(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019be0 at 10019be0

void Unwind_10019be0(void)

{
  int unaff_EBP;
  
  FUN_10003060(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019be8 at 10019be8

void Unwind_10019be8(void)

{
  int unaff_EBP;
  
  FUN_100173e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019bf3 at 10019bf3

void Unwind_10019bf3(void)

{
  int unaff_EBP;
  
  FUN_10003490((void *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10019c10 at 10019c10

void Unwind_10019c10(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019c18 at 10019c18

void Unwind_10019c18(void)

{
  int unaff_EBP;
  
  FUN_10017560((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c20 at 10019c20

void Unwind_10019c20(void)

{
  int unaff_EBP;
  
  FUN_10003500((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019c28 at 10019c28

void Unwind_10019c28(void)

{
  int unaff_EBP;
  
  FUN_10003570((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019c30 at 10019c30

void Unwind_10019c30(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019c38 at 10019c38

void Unwind_10019c38(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019c50 at 10019c50

void Unwind_10019c50(void)

{
  int unaff_EBP;
  
  FUN_10003960(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c70 at 10019c70

void Unwind_10019c70(void)

{
  int unaff_EBP;
  
  FUN_10003570(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c90 at 10019c90

void Unwind_10019c90(void)

{
  int unaff_EBP;
  
  FUN_10003060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c98 at 10019c98

void Unwind_10019c98(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10019ca3 at 10019ca3

void Unwind_10019ca3(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019cab at 10019cab

void Unwind_10019cab(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019cb3 at 10019cb3

void Unwind_10019cb3(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019cd0 at 10019cd0

void Unwind_10019cd0(void)

{
  int unaff_EBP;
  
  FUN_10003780(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019cd8 at 10019cd8

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10019cd8(void)

{
  int unaff_EBP;
  
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d00 at 10019d00

void Unwind_10019d00(void)

{
  int unaff_EBP;
  
  FUN_100042d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d08 at 10019d08

void Unwind_10019d08(void)

{
  int unaff_EBP;
  
  FUN_10003960(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d20 at 10019d20

void Unwind_10019d20(void)

{
  int unaff_EBP;
  
  FUN_100042d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d40 at 10019d40

void Unwind_10019d40(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d60 at 10019d60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10019d60(void)

{
  int unaff_EBP;
  
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d72 at 10019d72

void Unwind_10019d72(void)

{
  int unaff_EBP;
  
  FUN_10003780(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019d90 at 10019d90

void Unwind_10019d90(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019d98 at 10019d98

void Unwind_10019d98(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019da3 at 10019da3

void Unwind_10019da3(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019dab at 10019dab

void Unwind_10019dab(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019dc0 at 10019dc0

void Unwind_10019dc0(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019dc8 at 10019dc8

void Unwind_10019dc8(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019df0 at 10019df0

void Unwind_10019df0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019df8 at 10019df8

void Unwind_10019df8(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019e00 at 10019e00

void Unwind_10019e00(void)

{
  int unaff_EBP;
  
  FUN_10003570(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019e08 at 10019e08

void Unwind_10019e08(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x2c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x2c) = *(uint *)(unaff_EBP + -0x2c) & 0xfffffffe;
    FUN_10003500(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019e21 at 10019e21

void Unwind_10019e21(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019e40 at 10019e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10019e40(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019e60 at 10019e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10019e60(void)

{
  int unaff_EBP;
  
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e80 at 10019e80

void Unwind_10019e80(void)

{
  int unaff_EBP;
  
  FUN_10005300((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019e88 at 10019e88

void Unwind_10019e88(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019e90 at 10019e90

void Unwind_10019e90(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019eb0 at 10019eb0

void Unwind_10019eb0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019eb8 at 10019eb8

void Unwind_10019eb8(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019ed0 at 10019ed0

void Unwind_10019ed0(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019edb at 10019edb

void Unwind_10019edb(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019ef0 at 10019ef0

void Unwind_10019ef0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019ef8 at 10019ef8

void Unwind_10019ef8(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019f10 at 10019f10

void Unwind_10019f10(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019f30 at 10019f30

void Unwind_10019f30(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019f50 at 10019f50

void Unwind_10019f50(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019f70 at 10019f70

void Unwind_10019f70(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019f90 at 10019f90

void Unwind_10019f90(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019fb0 at 10019fb0

void Unwind_10019fb0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019fd0 at 10019fd0

void Unwind_10019fd0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@10019ff0 at 10019ff0

void Unwind_10019ff0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a010 at 1001a010

void Unwind_1001a010(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a030 at 1001a030

void Unwind_1001a030(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a050 at 1001a050

void Unwind_1001a050(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a070 at 1001a070

void Unwind_1001a070(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a090 at 1001a090

void Unwind_1001a090(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a0b0 at 1001a0b0

void Unwind_1001a0b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a0d0 at 1001a0d0

void Unwind_1001a0d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a0f0 at 1001a0f0

void Unwind_1001a0f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a110 at 1001a110

void Unwind_1001a110(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a130 at 1001a130

void Unwind_1001a130(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a150 at 1001a150

void Unwind_1001a150(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a170 at 1001a170

void Unwind_1001a170(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a190 at 1001a190

void Unwind_1001a190(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a1b0 at 1001a1b0

void Unwind_1001a1b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a1b8 at 1001a1b8

void Unwind_1001a1b8(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a1c0 at 1001a1c0

void Unwind_1001a1c0(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a1c8 at 1001a1c8

void Unwind_1001a1c8(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a1d3 at 1001a1d3

void Unwind_1001a1d3(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a1de at 1001a1de

void Unwind_1001a1de(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001a1e9 at 1001a1e9

void Unwind_1001a1e9(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a1f1 at 1001a1f1

void Unwind_1001a1f1(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001a210 at 1001a210

void Unwind_1001a210(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a21b at 1001a21b

void Unwind_1001a21b(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001a226 at 1001a226

void Unwind_1001a226(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001a231 at 1001a231

void Unwind_1001a231(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a239 at 1001a239

void Unwind_1001a239(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a241 at 1001a241

void Unwind_1001a241(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x1c) + 4));
  return;
}



// Function: Unwind@1001a24c at 1001a24c

void Unwind_1001a24c(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a254 at 1001a254

void Unwind_1001a254(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a280 at 1001a280

void Unwind_1001a280(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a2a0 at 1001a2a0

void Unwind_1001a2a0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a2c0 at 1001a2c0

void Unwind_1001a2c0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a2e0 at 1001a2e0

void Unwind_1001a2e0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a300 at 1001a300

void Unwind_1001a300(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a320 at 1001a320

void Unwind_1001a320(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a328 at 1001a328

void Unwind_1001a328(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a330 at 1001a330

void Unwind_1001a330(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a338 at 1001a338

void Unwind_1001a338(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a343 at 1001a343

void Unwind_1001a343(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a34e at 1001a34e

void Unwind_1001a34e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a356 at 1001a356

undefined8 Unwind_1001a356(void)

{
  int unaff_EBP;
  undefined8 uVar1;
  
  uVar1 = FUN_10006260((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return uVar1;
}



// Function: Unwind@1001a370 at 1001a370

void Unwind_1001a370(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a37b at 1001a37b

undefined8 Unwind_1001a37b(void)

{
  int unaff_EBP;
  undefined8 uVar1;
  
  uVar1 = FUN_10006260((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return uVar1;
}



// Function: Unwind@1001a386 at 1001a386

void Unwind_1001a386(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a38e at 1001a38e

void Unwind_1001a38e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a396 at 1001a396

void Unwind_1001a396(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@1001a3a1 at 1001a3a1

void Unwind_1001a3a1(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a3a9 at 1001a3a9

void Unwind_1001a3a9(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a3d0 at 1001a3d0

void Unwind_1001a3d0(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a3f0 at 1001a3f0

void Unwind_1001a3f0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a3f8 at 1001a3f8

void Unwind_1001a3f8(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a400 at 1001a400

void Unwind_1001a400(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a408 at 1001a408

void Unwind_1001a408(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a410 at 1001a410

void Unwind_1001a410(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a418 at 1001a418

void Unwind_1001a418(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a420 at 1001a420

void Unwind_1001a420(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a428 at 1001a428

void Unwind_1001a428(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a440 at 1001a440

void Unwind_1001a440(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a470 at 1001a470

void Unwind_1001a470(void)

{
  FUN_10012d50();
  return;
}



// Function: Unwind@1001a481 at 1001a481

void Unwind_1001a481(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a489 at 1001a489

void Unwind_1001a489(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a4b0 at 1001a4b0

void Unwind_1001a4b0(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a4b8 at 1001a4b8

void Unwind_1001a4b8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a4d0 at 1001a4d0

void Unwind_1001a4d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a4f0 at 1001a4f0

void Unwind_1001a4f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a510 at 1001a510

void Unwind_1001a510(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a530 at 1001a530

void Unwind_1001a530(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a550 at 1001a550

void Unwind_1001a550(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a558 at 1001a558

void Unwind_1001a558(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a560 at 1001a560

void Unwind_1001a560(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a568 at 1001a568

void Unwind_1001a568(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xacc));
  return;
}



// Function: Unwind@1001a573 at 1001a573

void Unwind_1001a573(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xae4));
  return;
}



// Function: Unwind@1001a57e at 1001a57e

void Unwind_1001a57e(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a586 at 1001a586

void Unwind_1001a586(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb00));
  return;
}



// Function: Unwind@1001a591 at 1001a591

void Unwind_1001a591(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a599 at 1001a599

void Unwind_1001a599(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a5a1 at 1001a5a1

void Unwind_1001a5a1(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb08));
  return;
}



// Function: Unwind@1001a5ac at 1001a5ac

void Unwind_1001a5ac(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a5b4 at 1001a5b4

void Unwind_1001a5b4(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb10));
  return;
}



// Function: Unwind@1001a5bf at 1001a5bf

void Unwind_1001a5bf(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a5c7 at 1001a5c7

void Unwind_1001a5c7(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb1c));
  return;
}



// Function: Unwind@1001a5d2 at 1001a5d2

void Unwind_1001a5d2(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xb38));
  return;
}



// Function: Unwind@1001a5dd at 1001a5dd

void Unwind_1001a5dd(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xb60));
  return;
}



// Function: Unwind@1001a600 at 1001a600

void Unwind_1001a600(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a620 at 1001a620

void Unwind_1001a620(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a628 at 1001a628

void Unwind_1001a628(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001a640 at 1001a640

void Unwind_1001a640(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a64b at 1001a64b

void Unwind_1001a64b(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a660 at 1001a660

void Unwind_1001a660(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a680 at 1001a680

void Unwind_1001a680(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a688 at 1001a688

void Unwind_1001a688(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@1001a6a0 at 1001a6a0

void Unwind_1001a6a0(void)

{
  int unaff_EBP;
  
  FUN_10009270(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001a6c0 at 1001a6c0

void Unwind_1001a6c0(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a6e0 at 1001a6e0

void Unwind_1001a6e0(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a6e8 at 1001a6e8

void Unwind_1001a6e8(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@1001a6f3 at 1001a6f3

void Unwind_1001a6f3(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x2274));
  return;
}



// Function: Unwind@1001a6fe at 1001a6fe

void Unwind_1001a6fe(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x2288));
  return;
}



// Function: Unwind@1001a709 at 1001a709

void Unwind_1001a709(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x22a0));
  return;
}



// Function: Unwind@1001a720 at 1001a720

void Unwind_1001a720(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a740 at 1001a740

void Unwind_1001a740(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2138));
  return;
}



// Function: Unwind@1001a74b at 1001a74b

void Unwind_1001a74b(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x2164));
  return;
}



// Function: Unwind@1001a756 at 1001a756

void Unwind_1001a756(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x227c));
  return;
}



// Function: Unwind@1001a770 at 1001a770

void Unwind_1001a770(void)

{
  DAT_1002d138 = DAT_1002d138 & 0xfffffffe;
  return;
}



// Function: Unwind@1001a790 at 1001a790

void Unwind_1001a790(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a79b at 1001a79b

void Unwind_1001a79b(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x20) + 4);
  return;
}



// Function: Unwind@1001a7a6 at 1001a7a6

void Unwind_1001a7a6(void)

{
  int unaff_EBP;
  
  FUN_1000e3e0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a7c0 at 1001a7c0

void Unwind_1001a7c0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a7c8 at 1001a7c8

void Unwind_1001a7c8(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a7d0 at 1001a7d0

void Unwind_1001a7d0(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a7d8 at 1001a7d8

void Unwind_1001a7d8(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a7f0 at 1001a7f0

void Unwind_1001a7f0(void)

{
  int unaff_EBP;
  
  FUN_10012b00((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a810 at 1001a810

void Unwind_1001a810(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a818 at 1001a818

void Unwind_1001a818(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a820 at 1001a820

void Unwind_1001a820(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a828 at 1001a828

void Unwind_1001a828(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a830 at 1001a830

void Unwind_1001a830(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a838 at 1001a838

void Unwind_1001a838(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a840 at 1001a840

void Unwind_1001a840(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a84b at 1001a84b

void Unwind_1001a84b(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x1f8));
  return;
}



// Function: Unwind@1001a856 at 1001a856

void Unwind_1001a856(void)

{
  int unaff_EBP;
  
  FUN_1000a370((int *)(unaff_EBP + -0x20c));
  return;
}



// Function: Unwind@1001a861 at 1001a861

void Unwind_1001a861(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a880 at 1001a880

void Unwind_1001a880(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a888 at 1001a888

void Unwind_1001a888(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a890 at 1001a890

void Unwind_1001a890(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a898 at 1001a898

void Unwind_1001a898(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001a8a3 at 1001a8a3

void Unwind_1001a8a3(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8ab at 1001a8ab

void Unwind_1001a8ab(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8c0 at 1001a8c0

void Unwind_1001a8c0(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a8c8 at 1001a8c8

void Unwind_1001a8c8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8d0 at 1001a8d0

void Unwind_1001a8d0(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8d8 at 1001a8d8

void Unwind_1001a8d8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8e0 at 1001a8e0

void Unwind_1001a8e0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a900 at 1001a900

void Unwind_1001a900(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a90b at 1001a90b

void Unwind_1001a90b(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a913 at 1001a913

void Unwind_1001a913(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a91e at 1001a91e

void Unwind_1001a91e(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a926 at 1001a926

void Unwind_1001a926(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001a940 at 1001a940

void Unwind_1001a940(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a980 at 1001a980

void Unwind_1001a980(void)

{
  int unaff_EBP;
  
  FUN_100057b0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a9a0 at 1001a9a0

void Unwind_1001a9a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a9c0 at 1001a9c0

void Unwind_1001a9c0(void)

{
  int unaff_EBP;
  
  FUN_10005d40(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a9e0 at 1001a9e0

void Unwind_1001a9e0(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError(*(CPreserveLastError **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa00 at 1001aa00

void Unwind_1001aa00(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001aa20 at 1001aa20

void Unwind_1001aa20(void)

{
  int unaff_EBP;
  
  FUN_10014e60(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aa40 at 1001aa40

void Unwind_1001aa40(void)

{
  int unaff_EBP;
  
  FUN_10012b00((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aa48 at 1001aa48

void Unwind_1001aa48(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@1001aa53 at 1001aa53

void Unwind_1001aa53(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@1001aa5e at 1001aa5e

void Unwind_1001aa5e(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@1001aa69 at 1001aa69

void Unwind_1001aa69(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@1001aa74 at 1001aa74

void Unwind_1001aa74(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@1001aa7f at 1001aa7f

void Unwind_1001aa7f(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1001aa8a at 1001aa8a

void Unwind_1001aa8a(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1001aa95 at 1001aa95

void Unwind_1001aa95(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1001aaa0 at 1001aaa0

void Unwind_1001aaa0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@1001aaab at 1001aaab

void Unwind_1001aaab(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@1001aac0 at 1001aac0

void Unwind_1001aac0(void)

{
  int unaff_EBP;
  
  FUN_10012b00((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001aae0 at 1001aae0

void Unwind_1001aae0(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001aaeb at 1001aaeb

void Unwind_1001aaeb(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ab00 at 1001ab00

void Unwind_1001ab00(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ab0b at 1001ab0b

void Unwind_1001ab0b(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ab13 at 1001ab13

void Unwind_1001ab13(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ab1e at 1001ab1e

void Unwind_1001ab1e(void)

{
  int unaff_EBP;
  
  FUN_10012630(*(int *)(unaff_EBP + -0x20) + 0xc);
  return;
}



// Function: Unwind@1001ab40 at 1001ab40

void Unwind_1001ab40(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x1c) + 4);
  return;
}



// Function: Unwind@1001ab4b at 1001ab4b

void Unwind_1001ab4b(void)

{
  int unaff_EBP;
  
  FUN_100109e0((undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 0x24));
  return;
}



// Function: Unwind@1001ab56 at 1001ab56

void Unwind_1001ab56(void)

{
  int unaff_EBP;
  
  FUN_10012750(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ab70 at 1001ab70

void Unwind_1001ab70(void)

{
  int unaff_EBP;
  
  FUN_100173e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ab7b at 1001ab7b

void Unwind_1001ab7b(void)

{
  int unaff_EBP;
  
  FUN_10003490((void *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001ab86 at 1001ab86

void Unwind_1001ab86(void)

{
  int unaff_EBP;
  
  FUN_10003960(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001aba0 at 1001aba0

void Unwind_1001aba0(void)

{
  int unaff_EBP;
  
  FUN_100173e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001abab at 1001abab

void Unwind_1001abab(void)

{
  int unaff_EBP;
  
  FUN_10003490((void *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001abb6 at 1001abb6

void Unwind_1001abb6(void)

{
  int unaff_EBP;
  
  FUN_10003960(*(void **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001abd0 at 1001abd0

void Unwind_1001abd0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001abf0 at 1001abf0

void Unwind_1001abf0(void)

{
  int unaff_EBP;
  
  FUN_1000e3e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ac10 at 1001ac10

void Unwind_1001ac10(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ac18 at 1001ac18

void Unwind_1001ac18(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ac23 at 1001ac23

void Unwind_1001ac23(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ac2b at 1001ac2b

void Unwind_1001ac2b(void)

{
  int unaff_EBP;
  
  FUN_100120e0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ac40 at 1001ac40

void Unwind_1001ac40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ac48 at 1001ac48

void Unwind_1001ac48(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ac53 at 1001ac53

void Unwind_1001ac53(void)

{
  int unaff_EBP;
  
  FUN_100057b0(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ac5b at 1001ac5b

void Unwind_1001ac5b(void)

{
  int unaff_EBP;
  
  FUN_100122a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ac70 at 1001ac70

void Unwind_1001ac70(void)

{
  FUN_10012d50();
  return;
}



// Function: Unwind@1001ac89 at 1001ac89

void Unwind_1001ac89(void)

{
  FUN_10012d50();
  return;
}



// Function: Unwind@1001acb0 at 1001acb0

void Unwind_1001acb0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001acb8 at 1001acb8

void Unwind_1001acb8(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001acc3 at 1001acc3

void Unwind_1001acc3(void)

{
  int unaff_EBP;
  
  FUN_10005d40(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001accb at 1001accb

void Unwind_1001accb(void)

{
  int unaff_EBP;
  
  FUN_10012460(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ace0 at 1001ace0

void Unwind_1001ace0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ace8 at 1001ace8

void Unwind_1001ace8(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001acf3 at 1001acf3

void Unwind_1001acf3(void)

{
  int unaff_EBP;
  
  FUN_10012750(*(int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001acfb at 1001acfb

void Unwind_1001acfb(void)

{
  int unaff_EBP;
  
  FUN_10012990(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ad10 at 1001ad10

void Unwind_1001ad10(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ad18 at 1001ad18

void Unwind_1001ad18(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ad20 at 1001ad20

void Unwind_1001ad20(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad28 at 1001ad28

void Unwind_1001ad28(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001ad33 at 1001ad33

void Unwind_1001ad33(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001ad3e at 1001ad3e

void Unwind_1001ad3e(void)

{
  int unaff_EBP;
  
  FUN_100109e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001ad60 at 1001ad60

void Unwind_1001ad60(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ad6b at 1001ad6b

void Unwind_1001ad6b(void)

{
  int unaff_EBP;
  
  FUN_100120e0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ad76 at 1001ad76

void Unwind_1001ad76(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad7e at 1001ad7e

void Unwind_1001ad7e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ada0 at 1001ada0

void Unwind_1001ada0(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001adc0 at 1001adc0

void Unwind_1001adc0(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001adcb at 1001adcb

void Unwind_1001adcb(void)

{
  int unaff_EBP;
  
  FUN_100122a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001add6 at 1001add6

void Unwind_1001add6(void)

{
  int unaff_EBP;
  
  FUN_100057b0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001adde at 1001adde

void Unwind_1001adde(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ae00 at 1001ae00

void Unwind_1001ae00(void)

{
  int unaff_EBP;
  
  FUN_10005d40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae20 at 1001ae20

void Unwind_1001ae20(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ae2b at 1001ae2b

void Unwind_1001ae2b(void)

{
  int unaff_EBP;
  
  FUN_10012460(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ae36 at 1001ae36

void Unwind_1001ae36(void)

{
  int unaff_EBP;
  
  FUN_10005d40(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae3e at 1001ae3e

void Unwind_1001ae3e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ae60 at 1001ae60

void Unwind_1001ae60(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001ae6b at 1001ae6b

void Unwind_1001ae6b(void)

{
  int unaff_EBP;
  
  FUN_10012630(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ae76 at 1001ae76

void Unwind_1001ae76(void)

{
  int unaff_EBP;
  
  FUN_10014e60(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae7e at 1001ae7e

void Unwind_1001ae7e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001aea0 at 1001aea0

void Unwind_1001aea0(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001aeab at 1001aeab

void Unwind_1001aeab(void)

{
  int unaff_EBP;
  
  FUN_100109e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001aeb6 at 1001aeb6

void Unwind_1001aeb6(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001aebe at 1001aebe

void Unwind_1001aebe(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x2c) + 4));
  return;
}



// Function: Unwind@1001aec9 at 1001aec9

void Unwind_1001aec9(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001aed1 at 1001aed1

void Unwind_1001aed1(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001aef0 at 1001aef0

void Unwind_1001aef0(void)

{
  FUN_10012ff0();
  return;
}



// Function: Unwind@1001aefb at 1001aefb

void Unwind_1001aefb(void)

{
  int unaff_EBP;
  
  FUN_10012990(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001af06 at 1001af06

void Unwind_1001af06(void)

{
  int unaff_EBP;
  
  FUN_10012750(*(int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001af0e at 1001af0e

void Unwind_1001af0e(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001af30 at 1001af30

void Unwind_1001af30(void)

{
  int unaff_EBP;
  
  FUN_10012750(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af50 at 1001af50

void Unwind_1001af50(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001af58 at 1001af58

void Unwind_1001af58(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001af60 at 1001af60

void Unwind_1001af60(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001af68 at 1001af68

void Unwind_1001af68(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001af70 at 1001af70

void Unwind_1001af70(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001af78 at 1001af78

void Unwind_1001af78(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001af90 at 1001af90

void Unwind_1001af90(void)

{
  int unaff_EBP;
  
  FUN_10014e60(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001afb0 at 1001afb0

void Unwind_1001afb0(void)

{
  int unaff_EBP;
  
  FUN_100057b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001afd0 at 1001afd0

void Unwind_1001afd0(void)

{
  int unaff_EBP;
  
  FUN_10003570(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001aff0 at 1001aff0

void Unwind_1001aff0(void)

{
  FUN_10013d70(0x1002d13c);
  return;
}



// Function: Unwind@1001affa at 1001affa

void Unwind_1001affa(void)

{
  FUN_10014090(0x1002d13c);
  return;
}



// Function: Unwind@1001b010 at 1001b010

void Unwind_1001b010(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b01b at 1001b01b

void Unwind_1001b01b(void)

{
  FUN_10013f20();
  return;
}



// Function: Unwind@1001b030 at 1001b030

void Unwind_1001b030(void)

{
  FUN_10013f20();
  return;
}



// Function: Unwind@1001b03b at 1001b03b

void Unwind_1001b03b(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b050 at 1001b050

void Unwind_1001b050(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b070 at 1001b070

void Unwind_1001b070(void)

{
  int unaff_EBP;
  
  FUN_10014090(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b078 at 1001b078

void Unwind_1001b078(void)

{
  int unaff_EBP;
  
  FUN_10013d70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b080 at 1001b080

void Unwind_1001b080(void)

{
  FUN_10013f20();
  return;
}



// Function: Unwind@1001b08b at 1001b08b

void Unwind_1001b08b(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b0a0 at 1001b0a0

void Unwind_1001b0a0(void)

{
  int unaff_EBP;
  
  FUN_10013d70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b0a8 at 1001b0a8

void Unwind_1001b0a8(void)

{
  FUN_10013f20();
  return;
}



// Function: Unwind@1001b0b3 at 1001b0b3

void Unwind_1001b0b3(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b0d0 at 1001b0d0

void Unwind_1001b0d0(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b0d8 at 1001b0d8

void Unwind_1001b0d8(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b0e0 at 1001b0e0

void Unwind_1001b0e0(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b0e8 at 1001b0e8

void Unwind_1001b0e8(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xad0));
  return;
}



// Function: Unwind@1001b0f3 at 1001b0f3

void Unwind_1001b0f3(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xaec));
  return;
}



// Function: Unwind@1001b0fe at 1001b0fe

void Unwind_1001b0fe(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b106 at 1001b106

void Unwind_1001b106(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb04));
  return;
}



// Function: Unwind@1001b111 at 1001b111

void Unwind_1001b111(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001b119 at 1001b119

void Unwind_1001b119(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b121 at 1001b121

void Unwind_1001b121(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb0c));
  return;
}



// Function: Unwind@1001b12c at 1001b12c

void Unwind_1001b12c(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b134 at 1001b134

void Unwind_1001b134(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb14));
  return;
}



// Function: Unwind@1001b13f at 1001b13f

void Unwind_1001b13f(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b147 at 1001b147

void Unwind_1001b147(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb20));
  return;
}



// Function: Unwind@1001b152 at 1001b152

void Unwind_1001b152(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xb38));
  return;
}



// Function: Unwind@1001b15d at 1001b15d

void Unwind_1001b15d(void)

{
  int unaff_EBP;
  
  FUN_10010d20((int *)(unaff_EBP + -0xb60));
  return;
}



// Function: Unwind@1001b168 at 1001b168

void Unwind_1001b168(void)

{
  int unaff_EBP;
  
  FUN_100076f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b170 at 1001b170

void Unwind_1001b170(void)

{
  int unaff_EBP;
  
  FUN_10011280(*(int **)(unaff_EBP + -0xb78));
  return;
}



// Function: Unwind@1001b190 at 1001b190

void Unwind_1001b190(void)

{
  FUN_10014090(0x1002d13c);
  return;
}



// Function: Unwind@1001b19a at 1001b19a

void Unwind_1001b19a(void)

{
  FUN_10013d70(0x1002d13c);
  return;
}



// Function: Unwind@1001b1a4 at 1001b1a4

void Unwind_1001b1a4(void)

{
  FUN_10013f20();
  return;
}



// Function: Unwind@1001b1ae at 1001b1ae

void Unwind_1001b1ae(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b1d0 at 1001b1d0

void Unwind_1001b1d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b1f0 at 1001b1f0

void Unwind_1001b1f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b210 at 1001b210

void Unwind_1001b210(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b230 at 1001b230

void Unwind_1001b230(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b250 at 1001b250

void Unwind_1001b250(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b258 at 1001b258

void Unwind_1001b258(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b260 at 1001b260

void Unwind_1001b260(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b268 at 1001b268

void Unwind_1001b268(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001b273 at 1001b273

void Unwind_1001b273(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b27e at 1001b27e

void Unwind_1001b27e(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001b289 at 1001b289

void Unwind_1001b289(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001b294 at 1001b294

void Unwind_1001b294(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001b29f at 1001b29f

void Unwind_1001b29f(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001b2c0 at 1001b2c0

void Unwind_1001b2c0(void)

{
  int unaff_EBP;
  
  FUN_10003ca0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b2cb at 1001b2cb

void Unwind_1001b2cb(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001b2d6 at 1001b2d6

void Unwind_1001b2d6(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001b2e1 at 1001b2e1

void Unwind_1001b2e1(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001b2ec at 1001b2ec

void Unwind_1001b2ec(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError
            ((CPreserveLastError *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001b2f7 at 1001b2f7

void Unwind_1001b2f7(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b2ff at 1001b2ff

void Unwind_1001b2ff(void)

{
  int unaff_EBP;
  
  FUN_10003d40((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001b30a at 1001b30a

void Unwind_1001b30a(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b312 at 1001b312

void Unwind_1001b312(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b340 at 1001b340

void Unwind_1001b340(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b360 at 1001b360

void Unwind_1001b360(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b390 at 1001b390

void Unwind_1001b390(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b398 at 1001b398

void Unwind_1001b398(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@1001b3b0 at 1001b3b0

void Unwind_1001b3b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b3d0 at 1001b3d0

void Unwind_1001b3d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b3f0 at 1001b3f0

void Unwind_1001b3f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b410 at 1001b410

void Unwind_1001b410(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b430 at 1001b430

void Unwind_1001b430(void)

{
  int unaff_EBP;
  
  FUN_10017560((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b450 at 1001b450

void Unwind_1001b450(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b458 at 1001b458

void Unwind_1001b458(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001b460 at 1001b460

void Unwind_1001b460(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001b468 at 1001b468

void Unwind_1001b468(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001b470 at 1001b470

void Unwind_1001b470(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001b478 at 1001b478

void Unwind_1001b478(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001b480 at 1001b480

void Unwind_1001b480(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b488 at 1001b488

void Unwind_1001b488(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b490 at 1001b490

void Unwind_1001b490(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b498 at 1001b498

void Unwind_1001b498(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b4b0 at 1001b4b0

void Unwind_1001b4b0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b4b8 at 1001b4b8

void Unwind_1001b4b8(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b4c0 at 1001b4c0

void Unwind_1001b4c0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b4c8 at 1001b4c8

void Unwind_1001b4c8(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b4d0 at 1001b4d0

void Unwind_1001b4d0(void)

{
  int unaff_EBP;
  
  FUN_10001a60(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b4d8 at 1001b4d8

void Unwind_1001b4d8(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b4e0 at 1001b4e0

void Unwind_1001b4e0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b4e8 at 1001b4e8

void Unwind_1001b4e8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b500 at 1001b500

void Unwind_1001b500(void)

{
  int unaff_EBP;
  
  FUN_10017560((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b508 at 1001b508

void Unwind_1001b508(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x28) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x28) = *(uint *)(unaff_EBP + -0x28) & 0xfffffffe;
    FUN_10001a60(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b530 at 1001b530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001b530(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b542 at 1001b542

void Unwind_1001b542(void)

{
  int unaff_EBP;
  
  FUN_10003780((exception *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b54a at 1001b54a

void Unwind_1001b54a(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b552 at 1001b552

void Unwind_1001b552(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b55a at 1001b55a

void Unwind_1001b55a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x24) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffe;
    FUN_10001a60(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b590 at 1001b590

void Unwind_1001b590(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b598 at 1001b598

void Unwind_1001b598(void)

{
  int unaff_EBP;
  
  FUN_10003060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b5a0 at 1001b5a0

void Unwind_1001b5a0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b5a8 at 1001b5a8

void Unwind_1001b5a8(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b5b0 at 1001b5b0

void Unwind_1001b5b0(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001b5d0 at 1001b5d0

void Unwind_1001b5d0(void)

{
  FUN_10012d50();
  return;
}



// Function: Unwind@1001b5f0 at 1001b5f0

void Unwind_1001b5f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b5f8 at 1001b5f8

void Unwind_1001b5f8(void)

{
  int unaff_EBP;
  
  FUN_10003060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b600 at 1001b600

void Unwind_1001b600(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b608 at 1001b608

void Unwind_1001b608(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b610 at 1001b610

void Unwind_1001b610(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001b61b at 1001b61b

void Unwind_1001b61b(void)

{
  int unaff_EBP;
  
  FUN_10003570(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b630 at 1001b630

void Unwind_1001b630(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b650 at 1001b650

void Unwind_1001b650(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b670 at 1001b670

void Unwind_1001b670(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b690 at 1001b690

void Unwind_1001b690(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b6b0 at 1001b6b0

void Unwind_1001b6b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b6d0 at 1001b6d0

void Unwind_1001b6d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b6f0 at 1001b6f0

void Unwind_1001b6f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b710 at 1001b710

void Unwind_1001b710(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b730 at 1001b730

void Unwind_1001b730(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b750 at 1001b750

void Unwind_1001b750(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b770 at 1001b770

void Unwind_1001b770(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b790 at 1001b790

void Unwind_1001b790(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b7b0 at 1001b7b0

void Unwind_1001b7b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b7d0 at 1001b7d0

void Unwind_1001b7d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b7f0 at 1001b7f0

void Unwind_1001b7f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b810 at 1001b810

void Unwind_1001b810(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b830 at 1001b830

void Unwind_1001b830(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b850 at 1001b850

void Unwind_1001b850(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b870 at 1001b870

void Unwind_1001b870(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b890 at 1001b890

void Unwind_1001b890(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b8b0 at 1001b8b0

void Unwind_1001b8b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b8d0 at 1001b8d0

void Unwind_1001b8d0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b8d8 at 1001b8d8

void Unwind_1001b8d8(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b8e0 at 1001b8e0

void Unwind_1001b8e0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b8e8 at 1001b8e8

undefined8 Unwind_1001b8e8(void)

{
  int unaff_EBP;
  undefined8 uVar1;
  
  uVar1 = FUN_10006260((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return uVar1;
}



// Function: Unwind@1001b8f3 at 1001b8f3

void Unwind_1001b8f3(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b8fb at 1001b8fb

void Unwind_1001b8fb(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b903 at 1001b903

void Unwind_1001b903(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b90b at 1001b90b

void Unwind_1001b90b(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b920 at 1001b920

void Unwind_1001b920(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b928 at 1001b928

undefined8 Unwind_1001b928(void)

{
  int unaff_EBP;
  undefined8 uVar1;
  
  uVar1 = FUN_10006260((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return uVar1;
}



// Function: Unwind@1001b933 at 1001b933

void Unwind_1001b933(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001b93b at 1001b93b

void Unwind_1001b93b(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b950 at 1001b950

void Unwind_1001b950(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b958 at 1001b958

void Unwind_1001b958(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b970 at 1001b970

void Unwind_1001b970(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b978 at 1001b978

void Unwind_1001b978(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b980 at 1001b980

void Unwind_1001b980(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b988 at 1001b988

void Unwind_1001b988(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b9a0 at 1001b9a0

void Unwind_1001b9a0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b9a8 at 1001b9a8

void Unwind_1001b9a8(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b9b0 at 1001b9b0

void Unwind_1001b9b0(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b9b8 at 1001b9b8

void Unwind_1001b9b8(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b9c0 at 1001b9c0

void Unwind_1001b9c0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b9e0 at 1001b9e0

void Unwind_1001b9e0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ba00 at 1001ba00

void Unwind_1001ba00(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ba20 at 1001ba20

void Unwind_1001ba20(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ba40 at 1001ba40

void Unwind_1001ba40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ba60 at 1001ba60

void Unwind_1001ba60(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001ba80 at 1001ba80

void Unwind_1001ba80(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001baa0 at 1001baa0

void Unwind_1001baa0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bac0 at 1001bac0

void Unwind_1001bac0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bae0 at 1001bae0

void Unwind_1001bae0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bb00 at 1001bb00

void Unwind_1001bb00(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bb20 at 1001bb20

void Unwind_1001bb20(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bb40 at 1001bb40

void Unwind_1001bb40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bb60 at 1001bb60

void Unwind_1001bb60(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bb80 at 1001bb80

void Unwind_1001bb80(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bba0 at 1001bba0

void Unwind_1001bba0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bbc0 at 1001bbc0

void Unwind_1001bbc0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bbe0 at 1001bbe0

void Unwind_1001bbe0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc00 at 1001bc00

void Unwind_1001bc00(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc20 at 1001bc20

void Unwind_1001bc20(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc40 at 1001bc40

void Unwind_1001bc40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc60 at 1001bc60

void Unwind_1001bc60(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc80 at 1001bc80

void Unwind_1001bc80(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bc88 at 1001bc88

void Unwind_1001bc88(void)

{
  int unaff_EBP;
  
  FUN_10017380(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bc90 at 1001bc90

void Unwind_1001bc90(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bc98 at 1001bc98

void Unwind_1001bc98(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001bca3 at 1001bca3

void Unwind_1001bca3(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bcc0 at 1001bcc0

void Unwind_1001bcc0(void)

{
  int unaff_EBP;
  
  FUN_10017380(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bcc8 at 1001bcc8

void Unwind_1001bcc8(void)

{
  int unaff_EBP;
  
  FUN_10003060((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001bcd3 at 1001bcd3

void Unwind_1001bcd3(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bcf0 at 1001bcf0

void Unwind_1001bcf0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bd10 at 1001bd10

void Unwind_1001bd10(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bd30 at 1001bd30

void Unwind_1001bd30(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bd50 at 1001bd50

void Unwind_1001bd50(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bd70 at 1001bd70

void Unwind_1001bd70(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001bd78 at 1001bd78

void Unwind_1001bd78(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x28) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x28) = *(uint *)(unaff_EBP + -0x28) & 0xfffffffe;
    ATL::CPreserveLastError::~CPreserveLastError(*(CPreserveLastError **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001bda0 at 1001bda0

void Unwind_1001bda0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bda8 at 1001bda8

void Unwind_1001bda8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x20) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 0xfffffffe;
    FUN_10003060(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001bdd0 at 1001bdd0

void Unwind_1001bdd0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ATL::CPreserveLastError::~CPreserveLastError(*(CPreserveLastError **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001be00 at 1001be00

void Unwind_1001be00(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001be20 at 1001be20

void Unwind_1001be20(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001be40 at 1001be40

void Unwind_1001be40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001be60 at 1001be60

void Unwind_1001be60(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001be80 at 1001be80

void Unwind_1001be80(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bea0 at 1001bea0

void Unwind_1001bea0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bec0 at 1001bec0

void Unwind_1001bec0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bee0 at 1001bee0

void Unwind_1001bee0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bf00 at 1001bf00

void Unwind_1001bf00(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bf20 at 1001bf20

void Unwind_1001bf20(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bf40 at 1001bf40

void Unwind_1001bf40(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bf60 at 1001bf60

void Unwind_1001bf60(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bf80 at 1001bf80

void Unwind_1001bf80(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bfa0 at 1001bfa0

void Unwind_1001bfa0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bfc0 at 1001bfc0

void Unwind_1001bfc0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001bfe0 at 1001bfe0

void Unwind_1001bfe0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c000 at 1001c000

void Unwind_1001c000(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c020 at 1001c020

void Unwind_1001c020(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c040 at 1001c040

void Unwind_1001c040(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c060 at 1001c060

void Unwind_1001c060(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c080 at 1001c080

void Unwind_1001c080(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c0a0 at 1001c0a0

void Unwind_1001c0a0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c0c0 at 1001c0c0

void Unwind_1001c0c0(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c0c8 at 1001c0c8

void Unwind_1001c0c8(void)

{
  int unaff_EBP;
  
  FUN_10002050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c0e0 at 1001c0e0

void Unwind_1001c0e0(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c0e8 at 1001c0e8

void Unwind_1001c0e8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c0f0 at 1001c0f0

void Unwind_1001c0f0(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c0f8 at 1001c0f8

void Unwind_1001c0f8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c100 at 1001c100

void Unwind_1001c100(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c108 at 1001c108

void Unwind_1001c108(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001c110 at 1001c110

void Unwind_1001c110(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001c118 at 1001c118

void Unwind_1001c118(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c120 at 1001c120

void Unwind_1001c120(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10002050(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c139 at 1001c139

void Unwind_1001c139(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001c141 at 1001c141

void Unwind_1001c141(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c149 at 1001c149

void Unwind_1001c149(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c160 at 1001c160

void Unwind_1001c160(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c168 at 1001c168

void Unwind_1001c168(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c170 at 1001c170

void Unwind_1001c170(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c178 at 1001c178

void Unwind_1001c178(void)

{
  int unaff_EBP;
  
  FUN_10001a20(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@1001c180 at 1001c180

void Unwind_1001c180(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c188 at 1001c188

void Unwind_1001c188(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c190 at 1001c190

void Unwind_1001c190(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c198 at 1001c198

void Unwind_1001c198(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x5c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x5c) = *(uint *)(unaff_EBP + -0x5c) & 0xfffffffe;
    FUN_10002050(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c1b1 at 1001c1b1

void Unwind_1001c1b1(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c1d0 at 1001c1d0

void Unwind_1001c1d0(void)

{
  int unaff_EBP;
  
  FUN_100048e0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c1d8 at 1001c1d8

void Unwind_1001c1d8(void)

{
  int unaff_EBP;
  
  ATL::CPreserveLastError::~CPreserveLastError((CPreserveLastError *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c1e0 at 1001c1e0

void Unwind_1001c1e0(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c1e8 at 1001c1e8

void Unwind_1001c1e8(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c200 at 1001c200

void Unwind_1001c200(void)

{
  int unaff_EBP;
  
  FUN_10001a60((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c208 at 1001c208

void Unwind_1001c208(void)

{
  int unaff_EBP;
  
  FUN_10002050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c210 at 1001c210

void Unwind_1001c210(void)

{
  int unaff_EBP;
  
  ~CComPtrBase<>((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c230 at 1001c230

void Unwind_1001c230(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c250 at 1001c250

void Unwind_1001c250(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c270 at 1001c270

void Unwind_1001c270(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c290 at 1001c290

void Unwind_1001c290(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c2b0 at 1001c2b0

void Unwind_1001c2b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c2d0 at 1001c2d0

void Unwind_1001c2d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c2f0 at 1001c2f0

void Unwind_1001c2f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c310 at 1001c310

void Unwind_1001c310(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c330 at 1001c330

void Unwind_1001c330(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c350 at 1001c350

void Unwind_1001c350(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c370 at 1001c370

void Unwind_1001c370(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c390 at 1001c390

void Unwind_1001c390(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c3b0 at 1001c3b0

void Unwind_1001c3b0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c3d0 at 1001c3d0

void Unwind_1001c3d0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c3f0 at 1001c3f0

void Unwind_1001c3f0(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c410 at 1001c410

void Unwind_1001c410(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c430 at 1001c430

void Unwind_1001c430(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c450 at 1001c450

void Unwind_1001c450(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c470 at 1001c470

void Unwind_1001c470(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c490 at 1001c490

void Unwind_1001c490(void)

{
  FUN_100036e0();
  return;
}



// Function: Unwind@1001c4b0 at 1001c4b0

void Unwind_1001c4b0(void)

{
  FUN_100036e0();
  return;
}



// Function: FUN_1001c4d0 at 1001c4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c4d0(void)

{
  FUN_10003170(&DAT_1002cdb4,L"\r");
  _atexit(FUN_1001f330);
  return;
}



// Function: FUN_1001c520 at 1001c520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c520(void)

{
  FUN_10003170(&DAT_1002cdd0,L"\n");
  _atexit(FUN_1001f390);
  return;
}



// Function: FUN_1001c570 at 1001c570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c570(void)

{
  FUN_10003170(&DAT_1002cdec,L"\\n");
  _atexit(FUN_1001f3f0);
  return;
}



// Function: FUN_1001c5c0 at 1001c5c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c5c0(void)

{
  FUN_10003170(&DAT_1002ce08,L"\\r");
  _atexit(FUN_1001f450);
  return;
}



// Function: FUN_1001c610 at 1001c610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c610(void)

{
  FUN_10003170(&DAT_1002ce24,L"EN");
  _atexit(FUN_1001f4b0);
  return;
}



// Function: FUN_1001c660 at 1001c660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c660(void)

{
  FUN_10003170(&DAT_1002ce40,L"ES");
  _atexit(FUN_1001f510);
  return;
}



// Function: FUN_1001c6b0 at 1001c6b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c6b0(void)

{
  FUN_10003170(&DAT_1002ce5c,L"PT");
  _atexit(FUN_1001f570);
  return;
}



// Function: FUN_1001c700 at 1001c700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c700(void)

{
  FUN_10003170(&DAT_1002ce78,L"TR");
  _atexit(FUN_1001f5d0);
  return;
}



// Function: FUN_1001c750 at 1001c750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c750(void)

{
  FUN_10003170(&DAT_1002ce94,L"ZH");
  _atexit(FUN_1001f630);
  return;
}



// Function: FUN_1001c7a0 at 1001c7a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c7a0(void)

{
  FUN_10003170(&DAT_1002ceb0,L"JA");
  _atexit(FUN_1001f690);
  return;
}



// Function: FUN_1001c7f0 at 1001c7f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c7f0(void)

{
  FUN_10003170(&DAT_1002cecc,L"FR");
  _atexit(FUN_1001f6f0);
  return;
}



// Function: FUN_1001c840 at 1001c840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c840(void)

{
  FUN_10003170(&DAT_1002cee8,L"DE");
  _atexit(FUN_1001f750);
  return;
}



// Function: FUN_1001c890 at 1001c890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c890(void)

{
  FUN_10003170(&DAT_1002cf04,L"IT");
  _atexit(FUN_1001f7b0);
  return;
}



// Function: FUN_1001c8e0 at 1001c8e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c8e0(void)

{
  FUN_10003170(&DAT_1002cf20,L"KO");
  _atexit(FUN_1001f810);
  return;
}



// Function: FUN_1001c930 at 1001c930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c930(void)

{
  FUN_10003170(&DAT_1002cf3c,L"RU");
  _atexit(FUN_1001f870);
  return;
}



// Function: FUN_1001c980 at 1001c980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c980(void)

{
  FUN_10003170(&DAT_1002cf58,L"DA");
  _atexit(FUN_1001f8d0);
  return;
}



// Function: FUN_1001c9d0 at 1001c9d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001c9d0(void)

{
  FUN_10003170(&DAT_1002cf74,L"NL");
  _atexit(FUN_1001f930);
  return;
}



// Function: FUN_1001ca20 at 1001ca20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ca20(void)

{
  FUN_10003170(&DAT_1002cf90,L"FI");
  _atexit(FUN_1001f990);
  return;
}



// Function: FUN_1001ca70 at 1001ca70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ca70(void)

{
  FUN_10003170(&DAT_1002cfac,L"NO");
  _atexit(FUN_1001f9f0);
  return;
}



// Function: FUN_1001cac0 at 1001cac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cac0(void)

{
  FUN_10003170(&DAT_1002cfc8,L"SV");
  _atexit(FUN_1001fa50);
  return;
}



// Function: FUN_1001cb10 at 1001cb10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cb10(void)

{
  FUN_10003170(&DAT_1002cfe4,L"ID");
  _atexit(FUN_1001fab0);
  return;
}



// Function: FUN_1001cb60 at 1001cb60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001cb6d) */

void FUN_1001cb60(void)

{
  DAT_1002d000 = Ordinal_2(&DAT_10023894);
  if (DAT_1002d000 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_1001fb10);
  return;
}



// Function: FUN_1001cbd0 at 1001cbd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001cbdd) */

void FUN_1001cbd0(void)

{
  DAT_1002d004 = Ordinal_2(&DAT_1002389c);
  if (DAT_1002d004 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_1001fb40);
  return;
}



// Function: FUN_1001cc40 at 1001cc40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001cc4d) */

void FUN_1001cc40(void)

{
  DAT_1002d008 = Ordinal_2(&DAT_100238a4);
  if (DAT_1002d008 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_1001fb70);
  return;
}



// Function: FUN_1001ccb0 at 1001ccb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ccb0(void)

{
  FUN_10003170(&DAT_1002d00c,L"\r");
  _atexit(FUN_1001fba0);
  return;
}



// Function: FUN_1001cd00 at 1001cd00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cd00(void)

{
  FUN_10003170(&DAT_1002d028,L"\n");
  _atexit(FUN_1001fc00);
  return;
}



// Function: FUN_1001cd50 at 1001cd50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cd50(void)

{
  FUN_10003170(&DAT_1002d044,L"\\n");
  _atexit(FUN_1001fc60);
  return;
}



// Function: FUN_1001cda0 at 1001cda0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cda0(void)

{
  FUN_10003170(&DAT_1002d060,L"\\r");
  _atexit(FUN_1001fcc0);
  return;
}



// Function: FUN_1001cdf0 at 1001cdf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cdf0(void)

{
  FUN_10003170(&DAT_1002d07c,L"\r");
  _atexit(FUN_1001fd20);
  return;
}



// Function: FUN_1001ce40 at 1001ce40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ce40(void)

{
  FUN_10003170(&DAT_1002d098,L"\n");
  _atexit(FUN_1001fd80);
  return;
}



// Function: FUN_1001ce90 at 1001ce90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ce90(void)

{
  FUN_10003170(&DAT_1002d0b4,L"\\n");
  _atexit(FUN_1001fde0);
  return;
}



// Function: FUN_1001cee0 at 1001cee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cee0(void)

{
  FUN_10003170(&DAT_1002d0d0,L"\\r");
  _atexit(FUN_1001fe40);
  return;
}



// Function: FUN_1001cf30 at 1001cf30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cf30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b004;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10013c90(0x1002d13c);
  _DAT_1002d13c = ATL::CComModule::vftable;
  _DAT_1002d10c = &DAT_1002d13c;
  local_8 = 0xffffffff;
  _atexit(FUN_1001fea0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001cfc0 at 1001cfc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cfc0(void)

{
  FUN_10003170(&DAT_1002d16c,L"\r");
  _atexit(FUN_1001ff10);
  return;
}



// Function: FUN_1001d010 at 1001d010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d010(void)

{
  FUN_10003170(&DAT_1002d188,L"\n");
  _atexit(FUN_1001ff70);
  return;
}



// Function: FUN_1001d060 at 1001d060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d060(void)

{
  FUN_10003170(&DAT_1002d1a4,L"\\n");
  _atexit(FUN_1001ffd0);
  return;
}



// Function: FUN_1001d0b0 at 1001d0b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d0b0(void)

{
  FUN_10003170(&DAT_1002d1c0,L"\\r");
  _atexit(FUN_10020030);
  return;
}



// Function: FUN_1001d100 at 1001d100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d100(void)

{
  FUN_10003170(&DAT_1002d1dc,L"\r");
  _atexit(FUN_10020090);
  return;
}



// Function: FUN_1001d150 at 1001d150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d150(void)

{
  FUN_10003170(&DAT_1002d1f8,L"\n");
  _atexit(FUN_100200f0);
  return;
}



// Function: FUN_1001d1a0 at 1001d1a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d1a0(void)

{
  FUN_10003170(&DAT_1002d214,L"\\n");
  _atexit(FUN_10020150);
  return;
}



// Function: FUN_1001d1f0 at 1001d1f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d1f0(void)

{
  FUN_10003170(&DAT_1002d230,L"\\r");
  _atexit(FUN_100201b0);
  return;
}



// Function: FUN_1001d240 at 1001d240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d240(void)

{
  FUN_10003170(&DAT_1002d24c,L"\r");
  _atexit(FUN_10020210);
  return;
}



// Function: FUN_1001d290 at 1001d290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d290(void)

{
  FUN_10003170(&DAT_1002d268,L"\n");
  _atexit(FUN_10020270);
  return;
}



// Function: FUN_1001d2e0 at 1001d2e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d2e0(void)

{
  FUN_10003170(&DAT_1002d284,L"\\n");
  _atexit(FUN_100202d0);
  return;
}



// Function: FUN_1001d330 at 1001d330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d330(void)

{
  FUN_10003170(&DAT_1002d2a0,L"\\r");
  _atexit(FUN_10020330);
  return;
}



// Function: FUN_1001d380 at 1001d380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d380(void)

{
  FUN_10003170(&DAT_1002d2bc,L"EN");
  _atexit(FUN_10020390);
  return;
}



// Function: FUN_1001d3d0 at 1001d3d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d3d0(void)

{
  FUN_10003170(&DAT_1002d2d8,L"ES");
  _atexit(FUN_100203f0);
  return;
}



// Function: FUN_1001d420 at 1001d420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d420(void)

{
  FUN_10003170(&DAT_1002d2f4,L"PT");
  _atexit(FUN_10020450);
  return;
}



// Function: FUN_1001d470 at 1001d470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d470(void)

{
  FUN_10003170(&DAT_1002d310,L"TR");
  _atexit(FUN_100204b0);
  return;
}



// Function: FUN_1001d4c0 at 1001d4c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d4c0(void)

{
  FUN_10003170(&DAT_1002d32c,L"ZH");
  _atexit(FUN_10020510);
  return;
}



// Function: FUN_1001d510 at 1001d510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d510(void)

{
  FUN_10003170(&DAT_1002d348,L"JA");
  _atexit(FUN_10020570);
  return;
}



// Function: FUN_1001d560 at 1001d560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d560(void)

{
  FUN_10003170(&DAT_1002d364,L"FR");
  _atexit(FUN_100205d0);
  return;
}



// Function: FUN_1001d5b0 at 1001d5b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d5b0(void)

{
  FUN_10003170(&DAT_1002d380,L"DE");
  _atexit(FUN_10020630);
  return;
}



// Function: FUN_1001d600 at 1001d600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d600(void)

{
  FUN_10003170(&DAT_1002d39c,L"IT");
  _atexit(FUN_10020690);
  return;
}



// Function: FUN_1001d650 at 1001d650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d650(void)

{
  FUN_10003170(&DAT_1002d3b8,L"KO");
  _atexit(FUN_100206f0);
  return;
}



// Function: FUN_1001d6a0 at 1001d6a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d6a0(void)

{
  FUN_10003170(&DAT_1002d3d4,L"RU");
  _atexit(FUN_10020750);
  return;
}



// Function: FUN_1001d6f0 at 1001d6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d6f0(void)

{
  FUN_10003170(&DAT_1002d3f0,L"DA");
  _atexit(FUN_100207b0);
  return;
}



// Function: FUN_1001d740 at 1001d740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d740(void)

{
  FUN_10003170(&DAT_1002d40c,L"NL");
  _atexit(FUN_10020810);
  return;
}



// Function: FUN_1001d790 at 1001d790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d790(void)

{
  FUN_10003170(&DAT_1002d428,L"FI");
  _atexit(FUN_10020870);
  return;
}



// Function: FUN_1001d7e0 at 1001d7e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d7e0(void)

{
  FUN_10003170(&DAT_1002d444,L"NO");
  _atexit(FUN_100208d0);
  return;
}



// Function: FUN_1001d830 at 1001d830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d830(void)

{
  FUN_10003170(&DAT_1002d460,L"SV");
  _atexit(FUN_10020930);
  return;
}



// Function: FUN_1001d880 at 1001d880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d880(void)

{
  FUN_10003170(&DAT_1002d47c,L"ID");
  _atexit(FUN_10020990);
  return;
}



// Function: FUN_1001d8d0 at 1001d8d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001d8dd) */

void FUN_1001d8d0(void)

{
  DAT_1002d498 = Ordinal_2(&DAT_10023894);
  if (DAT_1002d498 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_100209f0);
  return;
}



// Function: FUN_1001d940 at 1001d940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001d94d) */

void FUN_1001d940(void)

{
  DAT_1002d49c = Ordinal_2(&DAT_1002389c);
  if (DAT_1002d49c == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10020a20);
  return;
}



// Function: FUN_1001d9b0 at 1001d9b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001d9bd) */

void FUN_1001d9b0(void)

{
  DAT_1002d4a0 = Ordinal_2(&DAT_100238a4);
  if (DAT_1002d4a0 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10020a50);
  return;
}



// Function: FUN_1001da20 at 1001da20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001da20(void)

{
  FUN_10003170(&DAT_1002d4a4,L"\r");
  _atexit(FUN_10020a80);
  return;
}



// Function: FUN_1001da70 at 1001da70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001da70(void)

{
  FUN_10003170(&DAT_1002d4c0,L"\n");
  _atexit(FUN_10020ae0);
  return;
}



// Function: FUN_1001dac0 at 1001dac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dac0(void)

{
  FUN_10003170(&DAT_1002d4dc,L"\\n");
  _atexit(FUN_10020b40);
  return;
}



// Function: FUN_1001db10 at 1001db10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001db10(void)

{
  FUN_10003170(&DAT_1002d4f8,L"\\r");
  _atexit(FUN_10020ba0);
  return;
}



// Function: FUN_1001db60 at 1001db60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001db60(void)

{
  FUN_10003170(&DAT_1002d514,L"EN");
  _atexit(FUN_10020c00);
  return;
}



// Function: FUN_1001dbb0 at 1001dbb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dbb0(void)

{
  FUN_10003170(&DAT_1002d530,L"ES");
  _atexit(FUN_10020c60);
  return;
}



// Function: FUN_1001dc00 at 1001dc00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dc00(void)

{
  FUN_10003170(&DAT_1002d54c,L"PT");
  _atexit(FUN_10020cc0);
  return;
}



// Function: FUN_1001dc50 at 1001dc50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dc50(void)

{
  FUN_10003170(&DAT_1002d568,L"TR");
  _atexit(FUN_10020d20);
  return;
}



// Function: FUN_1001dca0 at 1001dca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dca0(void)

{
  FUN_10003170(&DAT_1002d584,L"ZH");
  _atexit(FUN_10020d80);
  return;
}



// Function: FUN_1001dcf0 at 1001dcf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dcf0(void)

{
  FUN_10003170(&DAT_1002d5a0,L"JA");
  _atexit(FUN_10020de0);
  return;
}



// Function: FUN_1001dd40 at 1001dd40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dd40(void)

{
  FUN_10003170(&DAT_1002d5bc,L"FR");
  _atexit(FUN_10020e40);
  return;
}



// Function: FUN_1001dd90 at 1001dd90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dd90(void)

{
  FUN_10003170(&DAT_1002d5d8,L"DE");
  _atexit(FUN_10020ea0);
  return;
}



// Function: FUN_1001dde0 at 1001dde0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dde0(void)

{
  FUN_10003170(&DAT_1002d5f4,L"IT");
  _atexit(FUN_10020f00);
  return;
}



// Function: FUN_1001de30 at 1001de30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001de30(void)

{
  FUN_10003170(&DAT_1002d610,L"KO");
  _atexit(FUN_10020f60);
  return;
}



// Function: FUN_1001de80 at 1001de80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001de80(void)

{
  FUN_10003170(&DAT_1002d62c,L"RU");
  _atexit(FUN_10020fc0);
  return;
}



// Function: FUN_1001ded0 at 1001ded0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ded0(void)

{
  FUN_10003170(&DAT_1002d648,L"DA");
  _atexit(FUN_10021020);
  return;
}



// Function: FUN_1001df20 at 1001df20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001df20(void)

{
  FUN_10003170(&DAT_1002d664,L"NL");
  _atexit(FUN_10021080);
  return;
}



// Function: FUN_1001df70 at 1001df70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001df70(void)

{
  FUN_10003170(&DAT_1002d680,L"FI");
  _atexit(FUN_100210e0);
  return;
}



// Function: FUN_1001dfc0 at 1001dfc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dfc0(void)

{
  FUN_10003170(&DAT_1002d69c,L"NO");
  _atexit(FUN_10021140);
  return;
}



// Function: FUN_1001e010 at 1001e010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e010(void)

{
  FUN_10003170(&DAT_1002d6b8,L"SV");
  _atexit(FUN_100211a0);
  return;
}



// Function: FUN_1001e060 at 1001e060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e060(void)

{
  FUN_10003170(&DAT_1002d6d4,L"ID");
  _atexit(FUN_10021200);
  return;
}



// Function: FUN_1001e0b0 at 1001e0b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001e0bd) */

void FUN_1001e0b0(void)

{
  DAT_1002d6f0 = Ordinal_2(&DAT_10023894);
  if (DAT_1002d6f0 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10021260);
  return;
}



// Function: FUN_1001e120 at 1001e120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001e12d) */

void FUN_1001e120(void)

{
  DAT_1002d6f4 = Ordinal_2(&DAT_1002389c);
  if (DAT_1002d6f4 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10021290);
  return;
}



// Function: FUN_1001e190 at 1001e190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001e19d) */

void FUN_1001e190(void)

{
  DAT_1002d6f8 = Ordinal_2(&DAT_100238a4);
  if (DAT_1002d6f8 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_100212c0);
  return;
}



// Function: FUN_1001e200 at 1001e200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e200(void)

{
  FUN_10003170(&DAT_1002d734,L"\r");
  _atexit(FUN_100212f0);
  return;
}



// Function: FUN_1001e250 at 1001e250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e250(void)

{
  FUN_10003170(&DAT_1002d718,L"\n");
  _atexit(FUN_10021350);
  return;
}



// Function: FUN_1001e2a0 at 1001e2a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e2a0(void)

{
  FUN_10003170(&DAT_1002d6fc,L"\\n");
  _atexit(FUN_100213b0);
  return;
}



// Function: FUN_1001e2f0 at 1001e2f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e2f0(void)

{
  FUN_10003170(&DAT_1002d750,L"\\r");
  _atexit(FUN_10021410);
  return;
}



// Function: FUN_1001e340 at 1001e340

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e340(void)

{
  FUN_10003170(&DAT_1002d7a4,L"\r");
  _atexit(FUN_10021470);
  return;
}



// Function: FUN_1001e390 at 1001e390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e390(void)

{
  FUN_10003170(&DAT_1002d788,L"\n");
  _atexit(FUN_100214d0);
  return;
}



// Function: FUN_1001e3e0 at 1001e3e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e3e0(void)

{
  FUN_10003170(&DAT_1002d76c,L"\\n");
  _atexit(FUN_10021530);
  return;
}



// Function: FUN_1001e430 at 1001e430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e430(void)

{
  FUN_10003170(&DAT_1002d930,L"\\r");
  _atexit(FUN_10021590);
  return;
}



// Function: FUN_1001e480 at 1001e480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e480(void)

{
  FUN_10003170(&DAT_1002d884,L"EN");
  _atexit(FUN_100215f0);
  return;
}



// Function: FUN_1001e4d0 at 1001e4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e4d0(void)

{
  FUN_10003170(&DAT_1002d984,L"ES");
  _atexit(FUN_10021650);
  return;
}



// Function: FUN_1001e520 at 1001e520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e520(void)

{
  FUN_10003170(&DAT_1002d7c0,L"PT");
  _atexit(FUN_100216b0);
  return;
}



// Function: FUN_1001e570 at 1001e570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e570(void)

{
  FUN_10003170(&DAT_1002d8dc,L"TR");
  _atexit(FUN_10021710);
  return;
}



// Function: FUN_1001e5c0 at 1001e5c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e5c0(void)

{
  FUN_10003170(&DAT_1002d94c,L"ZH");
  _atexit(FUN_10021770);
  return;
}



// Function: FUN_1001e610 at 1001e610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e610(void)

{
  FUN_10003170(&DAT_1002d914,L"JA");
  _atexit(FUN_100217d0);
  return;
}



// Function: FUN_1001e660 at 1001e660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e660(void)

{
  FUN_10003170(&DAT_1002d968,L"FR");
  _atexit(FUN_10021830);
  return;
}



// Function: FUN_1001e6b0 at 1001e6b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e6b0(void)

{
  FUN_10003170(&DAT_1002d8a4,L"DE");
  _atexit(FUN_10021890);
  return;
}



// Function: FUN_1001e700 at 1001e700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e700(void)

{
  FUN_10003170(&DAT_1002d868,L"IT");
  _atexit(FUN_100218f0);
  return;
}



// Function: FUN_1001e750 at 1001e750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e750(void)

{
  FUN_10003170(&DAT_1002d7dc,L"KO");
  _atexit(FUN_10021950);
  return;
}



// Function: FUN_1001e7a0 at 1001e7a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e7a0(void)

{
  FUN_10003170(&DAT_1002d8c0,L"RU");
  _atexit(FUN_100219b0);
  return;
}



// Function: FUN_1001e7f0 at 1001e7f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e7f0(void)

{
  FUN_10003170(&DAT_1002d7f8,L"DA");
  _atexit(FUN_10021a10);
  return;
}



// Function: FUN_1001e840 at 1001e840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e840(void)

{
  FUN_10003170(&DAT_1002d830,L"NL");
  _atexit(FUN_10021a70);
  return;
}



// Function: FUN_1001e890 at 1001e890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e890(void)

{
  FUN_10003170(&DAT_1002d8f8,L"FI");
  _atexit(FUN_10021ad0);
  return;
}



// Function: FUN_1001e8e0 at 1001e8e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e8e0(void)

{
  FUN_10003170(&DAT_1002d9a0,L"NO");
  _atexit(FUN_10021b30);
  return;
}



// Function: FUN_1001e930 at 1001e930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e930(void)

{
  FUN_10003170(&DAT_1002d814,L"SV");
  _atexit(FUN_10021b90);
  return;
}



// Function: FUN_1001e980 at 1001e980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e980(void)

{
  FUN_10003170(&DAT_1002d84c,L"ID");
  _atexit(FUN_10021bf0);
  return;
}



// Function: FUN_1001e9d0 at 1001e9d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001e9dd) */

void FUN_1001e9d0(void)

{
  DAT_1002d8a0 = Ordinal_2(&DAT_10023894);
  if (DAT_1002d8a0 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10021c50);
  return;
}



// Function: FUN_1001ea40 at 1001ea40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001ea4d) */

void FUN_1001ea40(void)

{
  DAT_1002d9bc = Ordinal_2(&DAT_1002389c);
  if (DAT_1002d9bc == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10021c80);
  return;
}



// Function: FUN_1001eab0 at 1001eab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001eabd) */

void FUN_1001eab0(void)

{
  DAT_1002d9c0 = Ordinal_2(&DAT_100238a4);
  if (DAT_1002d9c0 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10021cb0);
  return;
}



// Function: FUN_1001eb20 at 1001eb20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001eb20(void)

{
  FUN_10003170(&DAT_1002d9c4,L"\r");
  _atexit(FUN_10021ce0);
  return;
}



// Function: FUN_1001eb70 at 1001eb70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001eb70(void)

{
  FUN_10003170(&DAT_1002d9e0,L"\n");
  _atexit(FUN_10021d40);
  return;
}



// Function: FUN_1001ebc0 at 1001ebc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ebc0(void)

{
  FUN_10003170(&DAT_1002d9fc,L"\\n");
  _atexit(FUN_10021da0);
  return;
}



// Function: FUN_1001ec10 at 1001ec10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ec10(void)

{
  FUN_10003170(&DAT_1002da18,L"\\r");
  _atexit(FUN_10021e00);
  return;
}



// Function: FUN_1001ec60 at 1001ec60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ec60(void)

{
  FUN_10003170(&DAT_1002da34,L"EN");
  _atexit(FUN_10021e60);
  return;
}



// Function: FUN_1001ecb0 at 1001ecb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ecb0(void)

{
  FUN_10003170(&DAT_1002da50,L"ES");
  _atexit(FUN_10021ec0);
  return;
}



// Function: FUN_1001ed00 at 1001ed00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ed00(void)

{
  FUN_10003170(&DAT_1002da6c,L"PT");
  _atexit(FUN_10021f20);
  return;
}



// Function: FUN_1001ed50 at 1001ed50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ed50(void)

{
  FUN_10003170(&DAT_1002da88,L"TR");
  _atexit(FUN_10021f80);
  return;
}



// Function: FUN_1001eda0 at 1001eda0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001eda0(void)

{
  FUN_10003170(&DAT_1002daa4,L"ZH");
  _atexit(FUN_10021fe0);
  return;
}



// Function: FUN_1001edf0 at 1001edf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001edf0(void)

{
  FUN_10003170(&DAT_1002dac0,L"JA");
  _atexit(FUN_10022040);
  return;
}



// Function: FUN_1001ee40 at 1001ee40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ee40(void)

{
  FUN_10003170(&DAT_1002dadc,L"FR");
  _atexit(FUN_100220a0);
  return;
}



// Function: FUN_1001ee90 at 1001ee90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ee90(void)

{
  FUN_10003170(&DAT_1002daf8,L"DE");
  _atexit(FUN_10022100);
  return;
}



// Function: FUN_1001eee0 at 1001eee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001eee0(void)

{
  FUN_10003170(&DAT_1002db14,L"IT");
  _atexit(FUN_10022160);
  return;
}



// Function: FUN_1001ef30 at 1001ef30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ef30(void)

{
  FUN_10003170(&DAT_1002db30,L"KO");
  _atexit(FUN_100221c0);
  return;
}



// Function: FUN_1001ef80 at 1001ef80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ef80(void)

{
  FUN_10003170(&DAT_1002db4c,L"RU");
  _atexit(FUN_10022220);
  return;
}



// Function: FUN_1001efd0 at 1001efd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001efd0(void)

{
  FUN_10003170(&DAT_1002db68,L"DA");
  _atexit(FUN_10022280);
  return;
}



// Function: FUN_1001f020 at 1001f020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f020(void)

{
  FUN_10003170(&DAT_1002db84,L"NL");
  _atexit(FUN_100222e0);
  return;
}



// Function: FUN_1001f070 at 1001f070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f070(void)

{
  FUN_10003170(&DAT_1002dba0,L"FI");
  _atexit(FUN_10022340);
  return;
}



// Function: FUN_1001f0c0 at 1001f0c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f0c0(void)

{
  FUN_10003170(&DAT_1002dbbc,L"NO");
  _atexit(FUN_100223a0);
  return;
}



// Function: FUN_1001f110 at 1001f110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f110(void)

{
  FUN_10003170(&DAT_1002dbd8,L"SV");
  _atexit(FUN_10022400);
  return;
}



// Function: FUN_1001f160 at 1001f160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f160(void)

{
  FUN_10003170(&DAT_1002dbf4,L"ID");
  _atexit(FUN_10022460);
  return;
}



// Function: FUN_1001f1b0 at 1001f1b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001f1bd) */

void FUN_1001f1b0(void)

{
  DAT_1002dc10 = Ordinal_2(&DAT_10023894);
  if (DAT_1002dc10 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_100224c0);
  return;
}



// Function: FUN_1001f220 at 1001f220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001f22d) */

void FUN_1001f220(void)

{
  DAT_1002dc14 = Ordinal_2(&DAT_1002389c);
  if (DAT_1002dc14 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_100224f0);
  return;
}



// Function: FUN_1001f290 at 1001f290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x1001f29d) */

void FUN_1001f290(void)

{
  DAT_1002dc18 = Ordinal_2(&DAT_100238a4);
  if (DAT_1002dc18 == 0) {
    FUN_100019e0(0x8007000e);
  }
  _atexit(FUN_10022520);
  return;
}



// Function: FUN_1001f330 at 1001f330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f330(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cdb4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f390 at 1001f390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f390(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cdd0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f3f0 at 1001f3f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f3f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cdec,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f450 at 1001f450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f450(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f7a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce08,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f4b0 at 1001f4b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f4b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f9a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce24,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f510 at 1001f510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f510(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019fba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce40,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f570 at 1001f570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f570(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019fda;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce5c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f5d0 at 1001f5d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f5d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ffa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce78,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f630 at 1001f630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f630(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a01a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ce94,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f690 at 1001f690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f690(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a03a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002ceb0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f6f0 at 1001f6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f6f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a05a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cecc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f750 at 1001f750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f750(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a07a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cee8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f7b0 at 1001f7b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f7b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a09a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf04,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f810 at 1001f810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f810(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a0ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf20,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f870 at 1001f870

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f870(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a0da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf3c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f8d0 at 1001f8d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f8d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a0fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf58,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f930 at 1001f930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f930(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a11a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf74,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f990 at 1001f990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f990(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a13a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cf90,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f9f0 at 1001f9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001f9f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a15a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cfac,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fa50 at 1001fa50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fa50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a17a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cfc8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fab0 at 1001fab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fab0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a19a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002cfe4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fb10 at 1001fb10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fb10(void)

{
  Ordinal_6(DAT_1002d000);
  return;
}



// Function: FUN_1001fb40 at 1001fb40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fb40(void)

{
  Ordinal_6(DAT_1002d004);
  return;
}



// Function: FUN_1001fb70 at 1001fb70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fb70(void)

{
  Ordinal_6(DAT_1002d008);
  return;
}



// Function: FUN_1001fba0 at 1001fba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fba0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d00c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fc00 at 1001fc00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fc00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2ca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d028,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fc60 at 1001fc60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fc60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d044,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fcc0 at 1001fcc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fcc0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a30a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d060,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fd20 at 1001fd20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fd20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d07c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fd80 at 1001fd80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fd80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d098,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fde0 at 1001fde0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fde0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a51a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d0b4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fe40 at 1001fe40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fe40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a53a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d0d0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fea0 at 1001fea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fea0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b1b8;
  local_10 = ExceptionList;
  _DAT_1002d13c = ATL::CComModule::vftable;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_1000bfa0(0x1002d13c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ff10 at 1001ff10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ff10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b1da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d16c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ff70 at 1001ff70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ff70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b1fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d188,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ffd0 at 1001ffd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ffd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b21a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d1a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020030 at 10020030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020030(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b23a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d1c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020090 at 10020090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020090(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d1dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100200f0 at 100200f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100200f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d1f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020150 at 10020150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020150(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d214,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100201b0 at 100201b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100201b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b41a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d230,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020210 at 10020210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020210(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b63a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d24c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020270 at 10020270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020270(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b65a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d268,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100202d0 at 100202d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100202d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b67a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d284,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020330 at 10020330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020330(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b69a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d2a0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020390 at 10020390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020390(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b6ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d2bc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100203f0 at 100203f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100203f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b6da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d2d8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020450 at 10020450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020450(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b6fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d2f4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100204b0 at 100204b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100204b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b71a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d310,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020510 at 10020510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020510(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b73a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d32c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020570 at 10020570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020570(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b75a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d348,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100205d0 at 100205d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100205d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b77a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d364,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020630 at 10020630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020630(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b79a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d380,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020690 at 10020690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020690(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b7ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d39c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100206f0 at 100206f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100206f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b7da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d3b8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020750 at 10020750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020750(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b7fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d3d4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100207b0 at 100207b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100207b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b81a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d3f0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020810 at 10020810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020810(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b83a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d40c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020870 at 10020870

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020870(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b85a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d428,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100208d0 at 100208d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100208d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b87a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d444,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020930 at 10020930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020930(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b89a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d460,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020990 at 10020990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020990(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b8ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d47c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100209f0 at 100209f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100209f0(void)

{
  Ordinal_6(DAT_1002d498);
  return;
}



// Function: FUN_10020a20 at 10020a20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020a20(void)

{
  Ordinal_6(DAT_1002d49c);
  return;
}



// Function: FUN_10020a50 at 10020a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020a50(void)

{
  Ordinal_6(DAT_1002d4a0);
  return;
}



// Function: FUN_10020a80 at 10020a80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020a80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b9ea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d4a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020ae0 at 10020ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020ae0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba0a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d4c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020b40 at 10020b40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020b40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d4dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020ba0 at 10020ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020ba0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d4f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020c00 at 10020c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020c00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d514,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020c60 at 10020c60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020c60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d530,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020cc0 at 10020cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020cc0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001baaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d54c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020d20 at 10020d20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020d20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001baca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d568,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020d80 at 10020d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020d80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001baea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d584,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020de0 at 10020de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020de0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb0a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d5a0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020e40 at 10020e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020e40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d5bc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020ea0 at 10020ea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020ea0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d5d8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020f00 at 10020f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020f00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d5f4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020f60 at 10020f60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020f60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d610,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020fc0 at 10020fc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020fc0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bbaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d62c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021020 at 10021020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021020(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bbca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d648,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021080 at 10021080

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021080(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bbea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d664,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100210e0 at 100210e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100210e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc0a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d680,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021140 at 10021140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021140(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d69c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100211a0 at 100211a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100211a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d6b8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021200 at 10021200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021200(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d6d4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021260 at 10021260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021260(void)

{
  Ordinal_6(DAT_1002d6f0);
  return;
}



// Function: FUN_10021290 at 10021290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021290(void)

{
  Ordinal_6(DAT_1002d6f4);
  return;
}



// Function: FUN_100212c0 at 100212c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100212c0(void)

{
  Ordinal_6(DAT_1002d6f8);
  return;
}



// Function: FUN_100212f0 at 100212f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100212f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bcfa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d734,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021350 at 10021350

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021350(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd1a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d718,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100213b0 at 100213b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100213b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd3a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d6fc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021410 at 10021410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021410(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd5a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d750,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021470 at 10021470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021470(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d7a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100214d0 at 100214d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100214d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d788,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021530 at 10021530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021530(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d76c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021590 at 10021590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021590(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d930,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100215f0 at 100215f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100215f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001beaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d884,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021650 at 10021650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021650(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001beca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d984,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100216b0 at 100216b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100216b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001beea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d7c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021710 at 10021710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021710(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf0a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d8dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021770 at 10021770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021770(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf2a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d94c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100217d0 at 100217d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100217d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf4a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d914,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021830 at 10021830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021830(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf6a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d968,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021890 at 10021890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021890(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf8a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d8a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100218f0 at 100218f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100218f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bfaa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d868,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021950 at 10021950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021950(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bfca;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d7dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100219b0 at 100219b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100219b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bfea;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d8c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021a10 at 10021a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021a10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c00a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d7f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021a70 at 10021a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021a70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c02a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d830,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021ad0 at 10021ad0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ad0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c04a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d8f8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021b30 at 10021b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021b30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c06a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d9a0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021b90 at 10021b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021b90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c08a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d814,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021bf0 at 10021bf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021bf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c0aa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d84c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021c50 at 10021c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021c50(void)

{
  Ordinal_6(DAT_1002d8a0);
  return;
}



// Function: FUN_10021c80 at 10021c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021c80(void)

{
  Ordinal_6(DAT_1002d9bc);
  return;
}



// Function: FUN_10021cb0 at 10021cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021cb0(void)

{
  Ordinal_6(DAT_1002d9c0);
  return;
}



// Function: FUN_10021ce0 at 10021ce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ce0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c23a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d9c4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021d40 at 10021d40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021d40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c25a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d9e0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021da0 at 10021da0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021da0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c27a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002d9fc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021e00 at 10021e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021e00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c29a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002da18,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021e60 at 10021e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021e60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002da34,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021ec0 at 10021ec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021ec0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002da50,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021f20 at 10021f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021f20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002da6c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021f80 at 10021f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021f80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c31a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002da88,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10021fe0 at 10021fe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10021fe0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c33a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002daa4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022040 at 10022040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022040(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c35a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dac0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100220a0 at 100220a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100220a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c37a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dadc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022100 at 10022100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022100(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c39a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002daf8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022160 at 10022160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022160(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c3ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002db14,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100221c0 at 100221c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100221c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c3da;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002db30,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022220 at 10022220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022220(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c3fa;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002db4c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022280 at 10022280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022280(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c41a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002db68,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100222e0 at 100222e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100222e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c43a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002db84,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022340 at 10022340

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022340(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c45a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dba0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100223a0 at 100223a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100223a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c47a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dbbc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022400 at 10022400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022400(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c49a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dbd8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022460 at 10022460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022460(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c4ba;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10003620(&DAT_1002dbf4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100224c0 at 100224c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100224c0(void)

{
  Ordinal_6(DAT_1002dc10);
  return;
}



// Function: FUN_100224f0 at 100224f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100224f0(void)

{
  Ordinal_6(DAT_1002dc14);
  return;
}



// Function: FUN_10022520 at 10022520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10022520(void)

{
  Ordinal_6(DAT_1002dc18);
  return;
}



// Function: FUN_10022543 at 10022543

void FUN_10022543(void)

{
  FUN_10018236(0x1002dc1c);
  return;
}



// Function: FUN_1002254d at 1002254d

void FUN_1002254d(void)

{
  FUN_1001828e((int *)&DAT_1002dc54);
  return;
}



