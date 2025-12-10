/*
 * Decompiled from: SymbolicTreeObj.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001000(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001050 at 10001050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001050(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025948;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10001000(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100010d0 at 100010d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100010d0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if ((param_1 & 2) == 0) {
    FUN_10001050((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(local_c);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FUN_10001050);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)local_c + -4));
    }
    local_c = (undefined4 *)((int)local_c + -4);
  }
  return local_c;
}



// Function: FUN_10001170 at 10001170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10001170(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: FUN_100011c0 at 100011c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100011c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10001210(param_1);
  return local_c;
}



// Function: FUN_10001210 at 10001210

undefined4 __fastcall FUN_10001210(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10001240 at 10001240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001240(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 extraout_EDX;
  ulonglong uVar3;
  undefined *puVar4;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar1 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)FUN_10005d30(param_1);
  uVar3 = FUN_100099f0(local_c,extraout_EDX,puVar1);
  if ((uVar3 & 0xff) == 0) {
    puVar4 = &DAT_100297f8;
    puVar1 = (undefined4 *)FUN_10005d30(param_1);
    FUN_10006970(local_c,puVar1,puVar4);
  }
  else {
    FUN_10005d60(local_c);
  }
  return;
}



// Function: FUN_100012c0 at 100012c0

undefined4 FUN_100012c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0xcccccc01;
}



// Function: FUN_100012f0 at 100012f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100012f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [12];
  undefined1 local_c9 [197];
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003970(local_d5);
  FUN_10003970(local_c9);
  FUN_100012c0();
  return;
}



// Function: FUN_10001350 at 10001350

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool FUN_10001350(void)

{
  char cVar1;
  int iVar2;
  bool *pbVar3;
  bool local_c8 [196];
  
  pbVar3 = local_c8;
  for (iVar2 = 0x31; iVar2 != 0; iVar2 = iVar2 + -1) {
    pbVar3[0] = true;
    pbVar3[1] = true;
    pbVar3[2] = true;
    pbVar3[3] = true;
    pbVar3 = pbVar3 + 4;
  }
  cVar1 = FUN_100012f0();
  return cVar1 == '\0';
}



// Function: FUN_100013c0 at 100013c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __cdecl FUN_100013c0(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (-param_2 - 1U < param_3) {
    uVar1 = FUN_1000f730(0x216);
  }
  else {
    *param_1 = param_2 + param_3;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10001420 at 10001420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10001420(int param_1,uint param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  uint local_18;
  int local_c [2];
  
  puVar3 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = FUN_100013c0(local_c,param_1,param_2);
  uVar2 = extraout_EDX;
  if ((int)local_18 < 0) {
    FUN_10006cf0(local_18);
    uVar2 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000148c);
  return CONCAT44(uVar2,local_c[0]);
}



// Function: FUN_100014b0 at 100014b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __cdecl FUN_100014b0(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 local_d4 [49];
  undefined8 local_10;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  lVar4 = __allmul(param_2,(int)param_2 >> 0x1f,param_3,(int)param_3 >> 0x1f);
  local_10._4_4_ = (uint)((ulonglong)lVar4 >> 0x20);
  if ((((int)local_10._4_4_ < 1) &&
      ((local_10._0_4_ = (uint)lVar4, lVar4 < 0 || ((uint)local_10 < 0x80000000)))) &&
     ((local_10._4_4_ < 0x80000000 || ((-2 < (int)local_10._4_4_ && (0x7fffffff < (uint)local_10))))
     )) {
    *param_1 = (uint)local_10;
    uVar1 = 0;
  }
  else {
    local_10 = lVar4;
    uVar1 = FUN_1000f730(0x216);
  }
  return uVar1;
}



// Function: FUN_10001540 at 10001540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001540(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  (**(code **)*param_1)(param_1,&DAT_10029818,param_2);
  return;
}



// Function: FUN_100015a0 at 100015a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_100015a0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)0x0;
  if ((param_1 != 0) && (local_c = operator_new(param_1), local_c == (void *)0x0)) {
    std::_Xbad_alloc();
  }
  return local_c;
}



// Function: FUN_10001610 at 10001610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001610(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x7fffffff < param_1 || (local_c = operator_new(param_1 << 1), local_c == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_c;
}



// Function: FUN_10001690 at 10001690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001690(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3fffffff < param_1 || (local_c = operator_new(param_1 << 2), local_c == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_c;
}



// Function: FUN_10001710 at 10001710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001710(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x1fffffff < param_1 || (local_c = operator_new(param_1 << 3), local_c == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_c;
}



// Function: FUN_10001790 at 10001790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001790(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3fffffff < param_1 || (local_c = operator_new(param_1 << 2), local_c == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_c;
}



// Function: FUN_10001810 at 10001810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001810(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0;
  undefined1 local_c9;
  
  puVar2 = &local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10001900(param_3,param_2);
  local_c9 = (undefined1)uVar3;
  FUN_10001880();
  return;
}



// Function: FUN_10001880 at 10001880

void FUN_10001880(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100018b0 at 100018b0

undefined4 * __cdecl FUN_100018b0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = *param_3;
    param_1 = param_1 + 1;
  }
  return param_1;
}



// Function: FUN_10001900 at 10001900

undefined8 __fastcall FUN_10001900(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined1 local_9;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000193c);
  return CONCAT44(param_2,CONCAT31(0xcccccc,local_9));
}



// Function: FUN_10001960 at 10001960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001960(void *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = param_2 - (int)param_1 >> 2;
  pvVar1 = memmove(param_3,param_1,local_c << 2);
  return (void *)((int)pvVar1 + local_c * 4);
}



// Function: FUN_100019d0 at 100019d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100019d0(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_d0[1] = 0;
  FUN_100018b0(param_1,param_2,local_d0 + 1);
  return;
}



// Function: FUN_10001a30 at 10001a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall
FUN_10001a30(undefined4 param_1,undefined4 param_2,void *param_3,int param_4,void *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0;
  undefined1 local_c9;
  
  puVar2 = &local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10001900(param_3,param_2);
  local_c9 = (undefined1)uVar3;
  FUN_10001960(param_3,param_4,param_5);
  return;
}



// Function: FUN_10001aa0 at 10001aa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001aa0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0;
  undefined1 local_c9;
  
  puVar2 = &local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10001900(param_3,param_2);
  local_c9 = (undefined1)uVar3;
  FUN_10001b20();
  FUN_100019d0(param_3,param_4);
  return;
}



// Function: FUN_10001b20 at 10001b20

undefined4 FUN_10001b20(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_10001b50 at 10001b50

undefined4 __cdecl FUN_10001b50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10001b80 at 10001b80

undefined4 __cdecl FUN_10001b80(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10001bb0 at 10001bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001bb0(void *param_1)

{
  int *piVar1;
  int iVar2;
  int local_100 [4];
  undefined1 local_f0 [12];
  int local_e4;
  undefined1 local_d8 [204];
  void *local_c;
  
  piVar1 = local_100;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = -0x33333334;
    piVar1 = piVar1 + 1;
  }
  local_c = param_1;
  piVar1 = (int *)FUN_1000cbc0(param_1,local_f0);
  local_100[1] = *piVar1;
  piVar1 = (int *)FUN_1000c430(local_c,local_d8);
  local_e4 = *piVar1;
  FUN_1000f4a0(local_e4,local_100[1]);
  return;
}



// Function: FUN_10001c40 at 10001c40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001c40(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_10002550(param_2);
  FUN_10001d70(local_c,param_1,uVar1);
  return;
}



// Function: FUN_10001ca0 at 10001ca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001ca0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_f8 [5];
  undefined4 *local_e4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025984;
  local_10 = ExceptionList;
  puVar1 = local_f8;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = (undefined4 *)FUN_10005430(4,param_1);
  local_8 = 0;
  if (local_e4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_10002550(param_2);
    *local_e4 = *puVar1;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001d70 at 10001d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10001d70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_10002550(param_3);
  FUN_10001ca0(param_2,uVar1);
  return;
}



// Function: FUN_10001dc0 at 10001dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001dc0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_10002580(param_2);
  FUN_10001ef0(local_c,param_1,uVar1);
  return;
}



// Function: FUN_10001e20 at 10001e20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001e20(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_f8 [5];
  undefined4 *local_e4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100259c4;
  local_10 = ExceptionList;
  puVar1 = local_f8;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = (undefined4 *)FUN_10005430(4,param_1);
  local_8 = 0;
  if (local_e4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_10002580(param_2);
    *local_e4 = *puVar1;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001ef0 at 10001ef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10001ef0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_10002580(param_3);
  FUN_10001e20(param_2,uVar1);
  return;
}



// Function: FUN_10001f40 at 10001f40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001f40(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_100025e0(param_2);
  FUN_10002070(local_c,param_1,uVar1);
  return;
}



// Function: FUN_10001fa0 at 10001fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001fa0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_f8 [5];
  undefined4 *local_e4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025a04;
  local_10 = ExceptionList;
  puVar2 = local_f8;
  for (iVar3 = 0x3a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = (undefined4 *)FUN_10005430(8,param_1);
  local_8 = 0;
  if (local_e4 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_100025e0(param_2);
    uVar1 = puVar2[1];
    *local_e4 = *puVar2;
    local_e4[1] = uVar1;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002070 at 10002070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10002070(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_100025e0(param_3);
  FUN_10001fa0(param_2,uVar1);
  return;
}



// Function: FUN_100020c0 at 100020c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100020c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_100025b0(param_2);
  FUN_10002120(local_c,param_1,uVar1);
  return;
}



// Function: FUN_10002120 at 10002120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10002120(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  piVar1 = (int *)FUN_100025b0(param_3);
  FUN_1000c5d0(param_2,piVar1);
  return;
}



// Function: FUN_10002170 at 10002170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10002170(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100021f0();
  return;
}



// Function: FUN_100021c0 at 100021c0

void FUN_100021c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100021f0 at 100021f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100021f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100021c0();
  return;
}



// Function: FUN_10002230 at 10002230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10002230(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100022b0();
  return;
}



// Function: FUN_10002280 at 10002280

void FUN_10002280(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100022b0 at 100022b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100022b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10002280();
  return;
}



// Function: FUN_100022f0 at 100022f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100022f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10002370();
  return;
}



// Function: FUN_10002340 at 10002340

void FUN_10002340(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10002370 at 10002370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10002370(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10002340();
  return;
}



// Function: FUN_100023b0 at 100023b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100023b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10002430();
  return;
}



// Function: FUN_10002400 at 10002400

void FUN_10002400(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10002430 at 10002430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10002430(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10002400();
  return;
}



// Function: FUN_10002470 at 10002470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10002470(void *this,void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_10002510(this,param_1);
  return;
}



// Function: FUN_100024c0 at 100024c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100024c0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10006290(param_1,0);
  return;
}



// Function: FUN_10002510 at 10002510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10002510(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100024c0(param_2);
  return;
}



// Function: FUN_10002550 at 10002550

undefined4 __cdecl FUN_10002550(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10002580 at 10002580

undefined4 __cdecl FUN_10002580(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100025b0 at 100025b0

undefined4 __cdecl FUN_100025b0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100025e0 at 100025e0

undefined4 __cdecl FUN_100025e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10002610 at 10002610

undefined4 __cdecl FUN_10002610(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10002640 at 10002640

undefined4 * __fastcall FUN_10002640(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002680 at 10002680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10002680(void *this,undefined4 param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  undefined4 *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  local_c = (undefined4 *)this;
  if (param_2 != '\0') {
    local_18 = FUN_10009e80((undefined4 *)this);
    if (local_18 < 0) {
      FUN_10006cf0(local_18);
    }
  }
  return local_c;
}



// Function: FUN_100026f0 at 100026f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100026f0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025a38;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fc40((int)param_1);
  local_8 = 0;
  *local_18 = ATL::CComObject<class_CSymbolicTreeNode>::vftable;
  local_18[1] = ATL::CComObject<class_CSymbolicTreeNode>::vftable;
  (**(code **)(*DAT_1003387c + 4))(uVar1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100027a0 at 100027a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100027a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025a68;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002cb0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002820 at 10002820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10002820(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025a98;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10002cf0(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100028a0 at 100028a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100028a0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025ac8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10002d60(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002920 at 10002920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002920(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025af8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002dd0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100029a0 at 100029a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100029a0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025b28;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10002e10(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002a20 at 10002a20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002a20(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025b58;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002e80(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002aa0 at 10002aa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002aa0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025b88;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002ec0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002b20 at 10002b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10002b20(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025bb8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10002f00(this,*param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002bb0 at 10002bb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002bb0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025be8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002f70(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002c30 at 10002c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002c30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025c18;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002fb0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10002cb0 at 10002cb0

undefined4 * __fastcall FUN_10002cb0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002cf0 at 10002cf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10002cf0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  local_c = (int *)this;
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 4))(*this);
  }
  return local_c;
}



// Function: FUN_10002d60 at 10002d60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10002d60(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  local_c = (int *)this;
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 4))(*this);
  }
  return local_c;
}



// Function: FUN_10002dd0 at 10002dd0

undefined4 * __fastcall FUN_10002dd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002e10 at 10002e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10002e10(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  local_c = (int *)this;
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 4))(*this);
  }
  return local_c;
}



// Function: FUN_10002e80 at 10002e80

undefined4 * __fastcall FUN_10002e80(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002ec0 at 10002ec0

undefined4 * __fastcall FUN_10002ec0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002f00 at 10002f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10002f00(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  local_c = (int *)this;
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 4))(*this);
  }
  return local_c;
}



// Function: FUN_10002f70 at 10002f70

undefined4 * __fastcall FUN_10002f70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002fb0 at 10002fb0

undefined4 * __fastcall FUN_10002fb0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002ff0 at 10002ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10002ff0(void *this,undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025c48;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_100027a0((undefined4 *)this);
  local_8 = 0;
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)*param_1)(param_1,&DAT_1002a324,local_18,uVar1);
    if (iVar2 < 0) {
      *local_18 = 0;
    }
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100030a0 at 100030a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100030a0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025c78;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10002820(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003120 at 10003120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10003120(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025ca8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_100028a0(this,*param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100031b0 at 100031b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100031b0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025cd8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_100028a0(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003230 at 10003230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003230(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025d08;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002920(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100032b0 at 100032b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100032b0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025d38;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_100029a0(this,param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003330 at 10003330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003330(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025d68;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10002a20(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100033b0 at 100033b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

_Container_base12 * __fastcall FUN_100033b0(_Container_base12 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  _Container_base12 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025d98;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10003570(param_1);
  local_8 = 0;
  FUN_1000a310();
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003440 at 10003440

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003440(void *this,undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025dc8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_10003fb0((undefined4 *)this);
  local_8 = 0;
  FUN_1000b7b0(local_18,extraout_EDX,param_2);
  local_18[2] = param_1;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100034e0 at 100034e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100034e0(void *this,undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025df8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10003440(this,param_1,param_2);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003570 at 10003570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

_Container_base12 * __fastcall FUN_10003570(_Container_base12 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  _Container_base12 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025e32;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  std::_Container_base12::_Container_base12(param_1);
  *(undefined4 *)(local_18 + 4) = 0;
  *(undefined4 *)(local_18 + 8) = 0;
  *(undefined4 *)(local_18 + 0xc) = 0;
  *(undefined4 *)(local_18 + 0x10) = 0;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003620 at 10003620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10003620(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10003760(param_1);
  return local_c;
}



// Function: FUN_10003670 at 10003670

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10003670(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100037b0(param_1);
  return local_c;
}



// Function: FUN_100036c0 at 100036c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * FUN_100036c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000a1f0();
  *local_c = param_1;
  return local_c;
}



// Function: FUN_10003710 at 10003710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10003710(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100036c0(param_1);
  return local_c;
}



// Function: FUN_10003760 at 10003760

int __fastcall FUN_10003760(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_100037b0 at 100037b0

int __fastcall FUN_100037b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_10003800 at 10003800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10003800(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10003940(param_1);
  return local_c;
}



// Function: FUN_10003850 at 10003850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10003850(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100039a0(param_1);
  return local_c;
}



// Function: FUN_100038a0 at 100038a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100038a0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100039d0(param_1);
  return local_c;
}



// Function: FUN_100038f0 at 100038f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100038f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10003a00(param_1);
  return local_c;
}



// Function: FUN_10003940 at 10003940

undefined4 __fastcall FUN_10003940(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10003970 at 10003970

undefined4 __fastcall FUN_10003970(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100039a0 at 100039a0

undefined4 __fastcall FUN_100039a0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100039d0 at 100039d0

undefined4 __fastcall FUN_100039d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10003a00 at 10003a00

undefined4 __fastcall FUN_10003a00(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10003a30 at 10003a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_10003a30(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [201];
  void *local_c;
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003940(local_d5);
  FUN_10003620((int)local_c);
  FUN_1000b800(local_c,'\0',0);
  FUN_1000c070(param_1);
  return local_c;
}



// Function: FUN_10003aa0 at 10003aa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10003aa0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_10003670((int)this);
  FUN_1000b8d0(local_c,'\0',0);
  FUN_1000c1d0(param_1,param_2,param_3);
  return local_c;
}



// Function: FUN_10003b10 at 10003b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_10003b10(wchar_t *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [201];
  void *local_c;
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100039a0(local_d5);
  FUN_10003670((int)local_c);
  FUN_1000b8d0(local_c,'\0',0);
  FUN_1000c2b0(param_1);
  return local_c;
}



// Function: FUN_10003b80 at 10003b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_10003b80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [201];
  void *local_c;
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100039a0(local_d5);
  FUN_10003670((int)local_c);
  FUN_1000b8d0(local_c,'\0',0);
  return local_c;
}



// Function: FUN_10003be0 at 10003be0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

_Container_base12 * FUN_10003be0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e8;
  undefined1 local_e1 [201];
  _Container_base12 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025e58;
  local_10 = ExceptionList;
  puVar2 = &local_e8;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  FUN_10003a00(local_e1);
  FUN_100033b0(local_18);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003c70 at 10003c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10003c70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025e88;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  FUN_10003be0();
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003cf0 at 10003cf0

undefined4 * __thiscall FUN_10003cf0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10003d30 at 10003d30

undefined4 * __fastcall FUN_10003d30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10003d70 at 10003d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10003d70(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  local_c = (undefined4 *)this;
  uVar1 = ConvertStringToBSTR(param_1);
  *local_c = uVar1;
  return local_c;
}



// Function: FUN_10003dd0 at 10003dd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10003dd0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  local_c = (int *)this;
  iVar1 = Ordinal_2(param_1);
  *local_c = iVar1;
  if ((*local_c == 0) && (param_1 != 0)) {
    _com_issue_error(-0x7ff8fff2);
  }
  return local_c;
}



// Function: FUN_10003e50 at 10003e50

undefined4 * __fastcall FUN_10003e50(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_10003e90 at 10003e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003e90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025eb8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_100042d0(param_1);
  *local_18 = std::_Generic_error_category::vftable;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003f20 at 10003f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003f20(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025ee8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10003e90(param_1);
  *local_18 = std::_Iostream_error_category::vftable;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10003fb0 at 10003fb0

undefined4 * __fastcall FUN_10003fb0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_10003ff0 at 10003ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10003ff0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025f18;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10003e90(param_1);
  *local_18 = std::_System_error_category::vftable;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10004080 at 10004080

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * FUN_10004080(LPCSTR param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_f8 [5];
  void *local_e4;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025f4e;
  local_10 = ExceptionList;
  ppuVar2 = local_f8;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = (void *)FUN_10005460(0xc);
  local_8 = 0;
  if (local_e4 == (void *)0x0) {
    local_f8[0] = (undefined4 *)0x0;
  }
  else {
    local_f8[0] = FUN_10003d70(local_e4,param_1);
  }
  local_f8[2] = local_f8[0];
  local_8 = 0xffffffff;
  *local_18 = (int)local_f8[0];
  if (*local_18 == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10004160 at 10004160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * FUN_10004160(int param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_f8 [5];
  void *local_e4;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025f7e;
  local_10 = ExceptionList;
  ppiVar2 = local_f8;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = (void *)FUN_10005460(0xc);
  local_8 = 0;
  if (local_e4 == (void *)0x0) {
    local_f8[0] = (int *)0x0;
  }
  else {
    local_f8[0] = FUN_10003dd0(local_e4,param_1);
  }
  local_f8[2] = local_f8[0];
  local_8 = 0xffffffff;
  *local_18 = (int)local_f8[0];
  if (*local_18 == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10004240 at 10004240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004240(void *this,undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined ***)this = _com_error::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_c = (undefined4 *)this;
  if ((*(int *)((int)this + 8) != 0) && (param_3 != '\0')) {
    (**(code **)(**(int **)((int)this + 8) + 4))(*(undefined4 *)((int)this + 8));
  }
  return local_c;
}



// Function: FUN_100042d0 at 100042d0

undefined4 * __fastcall FUN_100042d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = std::error_category::vftable;
  return param_1;
}



// Function: FUN_10004310 at 10004310

undefined4 * __thiscall FUN_10004310(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  return (undefined4 *)this;
}



// Function: FUN_10004350 at 10004350

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10004350(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025fa8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10003d30(param_1);
  local_18[1] = 0;
  local_18[2] = 0xffffffff;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100043e0 at 100043e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100043e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; local_c = param_1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (*local_c != 0) {
    local_18 = (void *)*local_c;
    *local_c = *(int *)*local_c;
    FUN_10007b20(local_18);
  }
  return;
}



// Function: FUN_10004450 at 10004450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004450(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(char *)(param_1 + 1) != '\0') {
    local_c = param_1;
    FUN_1000a150(param_1);
  }
  return;
}



// Function: FUN_100044a0 at 100044a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100044a0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025fd8;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CSymbolicTreeNode>::vftable;
  param_1[1] = ATL::CComObject<class_CSymbolicTreeNode>::vftable;
  local_8 = 0;
  param_1[2] = 0xc0000001;
  local_18 = param_1;
  FUN_10010880();
  (**(code **)(*DAT_1003387c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10010090((int)local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004560 at 10004560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004560(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026008;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100048e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100045e0 at 100045e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100045e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026038;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004940(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004660 at 10004660

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004660(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026068;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100049a0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100046e0 at 100046e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100046e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026098;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004a00(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004760 at 10004760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004760(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100260c8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004a60(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100047e0 at 100047e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100047e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100260f8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004ac0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004860 at 10004860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004860(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026128;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004b20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100048e0 at 100048e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100048e0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004940 at 10004940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004940(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100049a0 at 100049a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100049a0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004a00 at 10004a00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004a00(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004a60 at 10004a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004a60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004ac0 at 10004ac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004ac0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004b20 at 10004b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004b20(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004b80 at 10004b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004b80(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026158;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004560(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004c00 at 10004c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004c00(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026188;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100045e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004c80 at 10004c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004c80(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100261b8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10004660(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004d00 at 10004d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004d00(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100261e8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100046e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004d80 at 10004d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004d80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  _Container_base12 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026218;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000ad10();
  local_8 = 0xffffffff;
  FUN_10004f00(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004e00 at 10004e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004e00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026248;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10005270();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004e80 at 10004e80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004e80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026278;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004e00();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004f00 at 10004f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004f00(_Container_base12 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  _Container_base12 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100262b2;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  std::_Container_base12::~_Container_base12(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004f90 at 10004f90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004f90(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000b800(param_1,'\x01',0);
  return;
}



// Function: FUN_10004fe0 at 10004fe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10004fe0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000b8d0(param_1,'\x01',0);
  return;
}



// Function: FUN_10005030 at 10005030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10005030(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100262d8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000b9a0();
  local_8 = 0xffffffff;
  FUN_10004d80();
  ExceptionList = local_10;
  return;
}



// Function: FUN_100050b0 at 100050b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100050b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026308;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10005030();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005130 at 10005130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005130(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000ac20(param_1);
  return;
}



// Function: FUN_10005170 at 10005170

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005170(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026338;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100053f0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100051f0 at 100051f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100051f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026368;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10005170(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005270 at 10005270

void FUN_10005270(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100052a0 at 100052a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100052a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026398;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10005170(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005320 at 10005320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005320(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000acb0(param_1);
  return;
}



// Function: FUN_10005360 at 10005360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005360(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = _com_error::vftable;
  local_c = param_1;
  if (param_1[2] != 0) {
    (**(code **)(*(int *)param_1[2] + 8))(param_1[2]);
  }
  if (local_c[3] != 0) {
    LocalFree((HLOCAL)local_c[3]);
  }
  return;
}



// Function: FUN_100053f0 at 100053f0

void __fastcall FUN_100053f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = std::error_category::vftable;
  return;
}



// Function: FUN_10005430 at 10005430

undefined4 __cdecl FUN_10005430(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}



// Function: FUN_10005460 at 10005460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10005460(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_new(param_1);
  return;
}



// Function: FUN_100054a0 at 100054a0

void FUN_100054a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100054d0 at 100054d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100054d0(int *param_1)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  undefined4 *puVar4;
  void *local_f0 [3];
  int local_e4 [51];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100263cb;
  local_10 = ExceptionList;
  ppvVar3 = local_f0;
  for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  ExceptionList = &local_10;
  iVar2 = FUN_10005cd0(param_1);
  bVar1 = FUN_10005b20(local_18,iVar2);
  if (bVar1) {
    puVar4 = local_18;
    local_f0[0] = FUN_10003120(local_e4,param_1);
    local_8 = 0;
    local_f0[1] = local_f0[0];
    FUN_1000a100(local_f0[0],puVar4);
    local_8 = 0xffffffff;
    FUN_10004c80(local_e4);
  }
  FUN_10005cd0(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100055a0 at 100055a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_100055a0(void *this,int param_1)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  undefined4 *puVar4;
  void *local_f0 [3];
  int local_e4 [51];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100263fb;
  local_10 = ExceptionList;
  ppvVar3 = local_f0;
  for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  bVar1 = FUN_10005b20(this,param_1);
  if (bVar1) {
    puVar4 = local_18;
    local_f0[0] = FUN_100031b0(local_e4,param_1);
    local_8 = 0;
    local_f0[1] = local_f0[0];
    FUN_1000a100(local_f0[0],puVar4);
    local_8 = 0xffffffff;
    FUN_10004c80(local_e4);
  }
  FUN_10005cd0(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005670 at 10005670

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100056de) */

void * __thiscall FUN_10005670(void *this,void *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_124;
  undefined1 local_11d [12];
  undefined1 local_111 [24];
  undefined1 local_f9 [12];
  undefined1 local_ed [9];
  undefined1 local_e4 [12];
  undefined1 local_d8 [204];
  void *local_c;
  
  puVar2 = &local_124;
  for (iVar3 = 0x48; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if (this != param_1) {
    FUN_1000b8d0(this,'\x01',0);
    FUN_1000ae90(local_11d);
    FUN_1000ae90(local_111);
    FUN_10001350();
    FUN_1000ae90(local_f9);
    FUN_1000ae90(local_ed);
    bVar1 = FUN_10001350();
    if (bVar1) {
      FUN_1000cbc0(param_1,local_e4);
      FUN_1000c430(param_1,local_d8);
      FUN_10001bb0(local_c);
    }
    else {
      puVar2 = (undefined4 *)FUN_10002610(param_1);
      FUN_1000a3c0(local_c,puVar2);
    }
  }
  return local_c;
}



// Function: FUN_10005790 at 10005790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100057ee) */

undefined4 * __thiscall FUN_10005790(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_f4;
  undefined1 local_ed [12];
  undefined1 local_e1 [213];
  undefined4 *local_c;
  
  puVar2 = &local_f4;
  for (iVar1 = 0x3c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if ((undefined4 *)this != param_1) {
    FUN_1000ae90(local_ed);
    FUN_1000ae90(local_e1);
    FUN_10001350();
    FUN_1000c180(param_1);
  }
  return local_c;
}



// Function: FUN_10005840 at 10005840

bool __thiscall FUN_10005840(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_100058a0 at 100058a0

bool __thiscall FUN_100058a0(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10005900 at 10005900

bool __thiscall FUN_10005900(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10005960 at 10005960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool FUN_10005960(int *param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [200];
  int *local_c;
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  FUN_1000a710();
  return *local_c == *param_1;
}



// Function: FUN_100059d0 at 100059d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_100059d0(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [200];
  int *local_c;
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  local_c = (int *)this;
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *local_c == 0;
}



// Function: FUN_10005a40 at 10005a40

bool __thiscall FUN_10005a40(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  return this == (void *)param_1;
}



// Function: FUN_10005a90 at 10005a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 FUN_10005a90(undefined4 *param_1)

{
  bool bVar1;
  void *this;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_d4 [50];
  undefined4 *local_c;
  
  puVar4 = local_d4;
  for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  iVar3 = FUN_1000c5a0((int)param_1);
  this = (void *)FUN_1000c5a0((int)local_c);
  bVar1 = FUN_10005a40(this,iVar3);
  if (bVar1) {
    iVar3 = FUN_1000f700(local_c);
    iVar2 = FUN_1000f700(param_1);
    if (iVar3 == iVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10005b20 at 10005b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_10005b20(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [200];
  void *local_c;
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  local_c = this;
  local_d4[0] = FUN_10005840(this,param_1);
  local_d4[0] = !local_d4[0];
  return local_d4[0];
}



// Function: FUN_10005b90 at 10005b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_10005b90(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [200];
  void *local_c;
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  local_c = this;
  local_d4[0] = FUN_100058a0(this,param_1);
  local_d4[0] = !local_d4[0];
  return local_d4[0];
}



// Function: FUN_10005c00 at 10005c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_10005c00(void *this,int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [200];
  void *local_c;
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  local_c = this;
  local_d4[0] = FUN_100059d0(this,param_1);
  local_d4[0] = !local_d4[0];
  return local_d4[0];
}



// Function: FUN_10005c70 at 10005c70

undefined4 __fastcall FUN_10005c70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005ca0 at 10005ca0

undefined4 __fastcall FUN_10005ca0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005cd0 at 10005cd0

undefined4 __fastcall FUN_10005cd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005d00 at 10005d00

undefined4 __fastcall FUN_10005d00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005d30 at 10005d30

undefined4 __fastcall FUN_10005d30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005d60 at 10005d60

undefined4 __fastcall FUN_10005d60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005d90 at 10005d90

undefined4 __fastcall FUN_10005d90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005dc0 at 10005dc0

undefined4 __fastcall FUN_10005dc0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005df0 at 10005df0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10005df0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_d4 [50];
  int *local_c;
  
  puVar1 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  if (*param_1 == 0) {
    local_d4[0] = 0;
  }
  else {
    local_c = param_1;
    puVar1 = (undefined4 *)FUN_100094f0(*param_1);
    local_d4[0] = *puVar1;
  }
  return local_d4[0];
}



// Function: FUN_10005e60 at 10005e60

undefined4 __fastcall FUN_10005e60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005e90 at 10005e90

undefined4 __fastcall FUN_10005e90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005ec0 at 10005ec0

undefined4 __fastcall FUN_10005ec0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005ef0 at 10005ef0

undefined4 __fastcall FUN_10005ef0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10005f20 at 10005f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10005f20(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_f4 [55];
  void *local_18;
  int *local_c;
  
  puVar3 = local_f4;
  for (iVar2 = 0x3c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = param_1;
  local_18 = (void *)FUN_1000af20(param_1);
  uVar1 = FUN_1000aee0(local_18,local_c[2]);
  return *(int *)(*(int *)((int)local_18 + 4) + uVar1 * 4) + ((uint)local_c[2] % 4) * 4;
}



// Function: FUN_10005fa0 at 10005fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10005fa0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10005f20(param_1);
  return;
}



// Function: FUN_10005fe0 at 10005fe0

undefined4 __fastcall FUN_10005fe0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10006010 at 10006010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10006010(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10005fe0(param_1);
  return;
}



// Function: FUN_10006050 at 10006050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10006050(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000a710();
  return *local_c - *param_1 >> 1;
}



// Function: FUN_100060b0 at 100060b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_100060b0(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [52];
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_dc[1] = *this;
  local_c = this;
  FUN_10006050(param_1);
  return;
}



// Function: FUN_10006110 at 10006110

undefined4 __fastcall FUN_10006110(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10006140 at 10006140

undefined4 __fastcall FUN_10006140(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10006170 at 10006170

undefined4 __fastcall FUN_10006170(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100061a0 at 100061a0

undefined4 __fastcall FUN_100061a0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100061d0 at 100061d0

undefined4 __fastcall FUN_100061d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10006200 at 10006200

undefined4 __fastcall FUN_10006200(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10006230 at 10006230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10006230(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100044a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10006290 at 10006290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10006290(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (int *)this;
  FUN_10004c80((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100062f0 at 100062f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_100062f0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (int *)this;
  FUN_10005130((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10006350 at 10006350

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10006350(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10005170((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100063b0 at 100063b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100063b0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100051f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10006410 at 10006410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10006410(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100052a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10006470 at 10006470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10006470(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10005360((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100064d0 at 100064d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100064d0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100053f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10006530 at 10006530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10006530(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009760((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000656f at 1000656f

void FUN_1000656f(int param_1)

{
  FUN_10006530(param_1 + -4);
  return;
}



// Function: FUN_10006580 at 10006580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10006580(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int local_d4 [50];
  void *local_c;
  
  piVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  if (this == (void *)0x0) {
    local_d4[0] = 0;
  }
  else {
    local_d4[0] = (int)this + 4;
  }
  local_c = this;
  uVar3 = FUN_10006ba0(param_2,param_1,local_d4[0],param_1,param_2);
  return uVar3;
}



// Function: CSymbolicTreeComponent_AddToTree at 100065f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeComponent_AddToTree(int param_1,int param_2)

{
  uint *puVar1;
  IUnknown *pIVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  int **ppiVar5;
  undefined8 uVar6;
  _GUID *p_Var7;
  uint uStack_13c;
  int *local_12c [65];
  long local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026428;
  local_10 = ExceptionList;
  ppiVar5 = local_12c;
  for (iVar3 = 0x46; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar5 = (int *)0xcccccccc;
    ppiVar5 = ppiVar5 + 1;
  }
  uStack_13c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_13c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_13c;
  if (param_2 == 0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  local_12c[0] = (int *)FUN_10005ec0((undefined4 *)(param_1 + 0x24));
  uVar6 = (**(code **)(*local_12c[0] + 0x1c))(local_12c[0],param_2,3);
  local_28 = (long)uVar6;
  uVar4 = extraout_ECX;
  if (local_28 < 0) {
    p_Var7 = (_GUID *)&DAT_1002a34c;
    pIVar2 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x24));
    _com_issue_errorex(local_28,pIVar2,p_Var7);
    uVar6 = CONCAT44(extraout_EDX,local_28);
    uVar4 = extraout_ECX_00;
  }
  local_28 = (long)uVar6;
  uVar6 = FUN_1000678f(uVar4,(int)((ulonglong)uVar6 >> 0x20));
  return uVar6;
}



// Function: Catch@100066c6 at 100066c6

undefined * Catch_100066c6(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x30),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330e8 + 0x12,"CSymbolicTreeComponent::AddToTree",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x120) = uVar2;
  return &DAT_100067a9;
}



// Function: Catch@1000671a at 1000671a

undefined * Catch_1000671a(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x48),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x48),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330e8 + 0x12,"CSymbolicTreeComponent::AddToTree",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10006783;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x48));
  return &DAT_10006798;
}



// Function: FUN_1000678f at 1000678f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000678f(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100067f0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10006820 at 10006820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10006820(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  undefined4 *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10001420(param_1,8);
  local_18 = (undefined4 *)FUN_100068a0((size_t)uVar3);
  if (local_18 == (undefined4 *)0x0) {
    iVar1 = 0;
  }
  else {
    *local_18 = *local_c;
    *local_c = local_18;
    iVar1 = FUN_10007b70((int)local_18);
  }
  return iVar1;
}



// Function: FUN_100068a0 at 100068a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100068a0(size_t param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  malloc(param_1);
  return;
}



// Function: FUN_100068f0 at 100068f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPWSTR FUN_100068f0(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 == (LPWSTR)0x0) || (param_2 == (LPCSTR)0x0)) {
    param_1 = (LPWSTR)0x0;
  }
  else {
    *param_1 = L'\0';
    iVar1 = MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
    if (iVar1 == 0) {
      param_1 = (LPWSTR)0x0;
    }
  }
  return param_1;
}



// Function: FUN_10006970 at 10006970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10006970(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    local_c = (int *)*param_1;
    if ((param_2 == (undefined4 *)0x0) ||
       (iVar1 = (**(code **)*param_2)(param_2,param_3,param_1), iVar1 < 0)) {
      *param_1 = 0;
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
    }
    return *param_1;
  }
  return 0;
}



// Function: FUN_10006a10 at 10006a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10006a10(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint local_f8 [50];
  int *local_30;
  uint local_24;
  int local_18;
  int *local_c;
  
  puVar2 = local_f8;
  for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_18 = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    local_18 = -0x7fffbffd;
  }
  else {
    iVar1 = FUN_10009650(param_3);
    if (iVar1 == 0) {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        local_f8[0] = (uint)(*param_2 == 0);
        local_24 = local_f8[0];
        if ((local_f8[0] != 0) || (iVar1 = FUN_1000f790((int *)*param_2,param_3), iVar1 != 0)) {
          if (param_2[2] == 1) {
            local_30 = (int *)(param_1 + param_2[1]);
            (**(code **)(*local_30 + 4))(local_30);
            *param_4 = local_30;
            return 0;
          }
          local_18 = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (local_18 == 0) {
            return 0;
          }
          if ((local_24 == 0) && (local_18 < 0)) goto LAB_10006b72;
        }
      }
      local_18 = -0x7fffbffe;
LAB_10006b72:
      *param_4 = 0;
    }
    else {
      local_c = (int *)(param_1 + param_2[1]);
      (**(code **)(*local_c + 4))(local_c);
      *param_4 = local_c;
      local_18 = 0;
    }
  }
  return local_18;
}



// Function: FUN_10006ba0 at 10006ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10006ba0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 **ppuVar2;
  undefined8 uVar3;
  undefined4 *local_110 [4];
  undefined4 *local_100;
  undefined4 local_34 [4];
  undefined4 *local_24;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026458;
  local_10 = ExceptionList;
  ppuVar2 = local_110;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
  if (param_3 == 0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_18 = 0;
    uVar3 = FUN_10024096(0xc);
    param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    local_110[1] = (undefined4 *)uVar3;
    local_24 = local_110[1];
    if (local_110[1] == (undefined4 *)0x0) {
      local_18 = -0x7ff8fff2;
      iVar1 = local_18;
    }
    else {
      *local_110[1] = param_4;
      local_110[1][1] = param_5;
      FUN_10002680(local_34,param_3 + 0xc,'\0');
      local_8 = 0;
      local_18 = FUN_10009e80(local_34);
      if (local_18 < 0) {
        local_100 = local_24;
        operator_delete(local_24);
      }
      else {
        local_24[2] = *(undefined4 *)(param_3 + 8);
        *(undefined4 **)(param_3 + 8) = local_24;
      }
      local_8 = 0xffffffff;
      FUN_10004450(local_34);
      iVar1 = local_18;
      param_2 = extraout_EDX;
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10006cd0);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_10006cf0 at 10006cf0

/* WARNING: Type propagation algorithm not settling */

void FUN_10006cf0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_dc [4];
  undefined1 local_cc [200];
  
  puVar1 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  puVar1 = FUN_10003cf0(local_cc,param_1);
  local_dc[1] = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_dc + 1,(ThrowInfo *)&DAT_1002f938);
}



// Function: FUN_10006d50 at 10006d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPSTR FUN_10006d50(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    param_1 = (LPSTR)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      param_1 = (LPSTR)0x0;
    }
  }
  return param_1;
}



// Function: FUN_10006de0 at 10006de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10006de0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    local_c = (int *)this;
    Ordinal_6(*this);
    *local_c = param_1;
  }
  return;
}



// Function: FUN_10006e40 at 10006e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10006e40(int param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_ec [5];
  void *local_d8;
  int local_c;
  
  ppvVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  if (param_1 != 0) {
    local_c = param_1;
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(local_c + 0xc) = 0;
    local_ec[2] = *(void **)(local_c + 0x14);
    if (local_ec[2] != (void *)0x0) {
      local_d8 = local_ec[2];
      FUN_100010d0(local_ec[2],3);
    }
    *(undefined4 *)(local_c + 0x14) = 0;
  }
  return;
}



// Function: FUN_10006f00 at 10006f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10006f00(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      local_c = this;
      (**(code **)(**this + 4))(*this);
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006f80 at 10006f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10006f80(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  uint uStack_130;
  undefined4 *local_120 [5];
  undefined4 *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026495;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  uStack_130 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_130;
  ExceptionList = &local_10;
  if (param_1 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_1 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (undefined4 *)FUN_10024096(0x3c);
  local_8._0_1_ = 1;
  if (local_10c == (undefined4 *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    uStack_130 = 0;
    local_120[0] = FUN_100026f0(local_10c);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_10007051();
  return uVar1;
}



// Function: Catch@1000704b at 1000704b

undefined * Catch_1000704b(void)

{
  return &DAT_1000705a;
}



// Function: FUN_10007051 at 10007051

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007051(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined8 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1000a0d0();
    FUN_100097b0(*(int *)(unaff_EBP + -0x24));
    uVar1 = FUN_1000a4d0(*(int *)(unaff_EBP + -0x24) + 8);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = CSymbolicTreeNode_FinalConstruct();
      *(int *)(unaff_EBP + -0x18) = (int)uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_10009800(*(int *)(unaff_EBP + -0x24));
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar1;
      }
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
    }
  }
  **(undefined4 **)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x24);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10007150 at 10007150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10007150(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined4 *puVar4;
  void **ppvVar5;
  undefined4 local_e8 [49];
  LPUNKNOWN local_24 [3];
  HRESULT local_18;
  void **local_c;
  
  puVar4 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_c = (void **)this;
  FUN_1000b750((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppvVar5 = local_c;
    pIVar1 = (IID *)FUN_10008d00();
    local_18 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppvVar5);
    uVar3 = extraout_EDX_01;
  }
  else {
    local_18 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029418,local_24);
    uVar3 = extraout_EDX;
    if (-1 < local_18) {
      local_18 = OleRun(local_24[0]);
      if (-1 < local_18) {
        ppvVar5 = local_c;
        pIVar1 = (IID *)FUN_10008d00();
        local_18 = (*local_24[0]->lpVtbl->QueryInterface)(local_24[0],pIVar1,ppvVar5);
      }
      (*local_24[0]->lpVtbl->Release)(local_24[0]);
      uVar3 = extraout_EDX_00;
    }
  }
  if (local_18 < 0) {
    *local_c = (void *)0x0;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007270);
  return CONCAT44(uVar3,local_18);
}



// Function: FUN_10007290 at 10007290

undefined8 FUN_10007290(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  uint uStack_178;
  int local_168 [74];
  int local_40;
  undefined4 local_34 [3];
  int local_28 [3];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100264d8;
  local_10 = ExceptionList;
  piVar2 = local_168;
  for (iVar1 = 0x55; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  uStack_178 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_178;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  if (param_3 == (undefined4 *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
  }
  else {
    *param_3 = 0;
    local_14 = (undefined1 *)&uStack_178;
  }
  local_28[0] = 0;
  FUN_10003230(local_34);
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  local_40 = FUN_10006f80(local_28);
  if (local_40 < 0) {
    _com_issue_error(local_40);
  }
  if (local_28[0] == 0) {
    local_168[0] = 0;
  }
  else {
    local_168[0] = local_28[0] + 4;
  }
  FUN_100055a0(local_34,local_168[0]);
  uVar3 = CSymbolicTreeComponent_CreateNode();
  return uVar3;
}



// Function: Catch@1000737a at 1000737a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Catch_1000737a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x150) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x15c) = *(undefined4 *)(unaff_EBP + -0x150);
  if (*(int *)(unaff_EBP + -0x15c) == 0) {
    *(undefined4 *)(unaff_EBP + -0x164) = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x15c) + 0x10))(1);
    *(undefined4 *)(unaff_EBP + -0x164) = uVar1;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: CSymbolicTreeComponent_CreateNode at 100073d7

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeComponent_CreateNode(void)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int unaff_EBP;
  undefined8 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_100032b0((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    uVar1 = FUN_10005d00((undefined4 *)(unaff_EBP + -0x48));
    uVar1 = (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x24) + 4) + 0x50))
                      (*(int *)(unaff_EBP + -0x24) + 4,uVar1);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (*(int *)(unaff_EBP + -0x18) < 0) {
      FUN_10021d70((uchar *)
                   "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                  );
    }
    else {
      uVar1 = FUN_10007660((undefined4 *)(unaff_EBP + -0x30));
      **(undefined4 **)(unaff_EBP + 0x10) = uVar1;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004d00((int *)(unaff_EBP + -0x48));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_10004c80((int *)(unaff_EBP + -0x30));
  uVar2 = FUN_10007544(extraout_ECX,extraout_EDX);
  return uVar2;
}



// Function: Catch@1000747b at 1000747b

undefined * Catch_1000747b(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x54),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f4 + 0x32,"CSymbolicTreeComponent::CreateNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x144) = uVar2;
  return &DAT_1000755e;
}



// Function: Catch@100074cf at 100074cf

undefined * Catch_100074cf(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x6c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 6;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x6c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f4 + 0x32,"CSymbolicTreeComponent::CreateNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x138) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uStack0000001c = 0x10007538;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return &DAT_1000754d;
}



// Function: FUN_10007544 at 10007544

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10007544(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100075a4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10007610 at 10007610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10007610(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10007660 at 10007660

undefined4 __fastcall FUN_10007660(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_100076a0 at 100076a0

undefined4 __fastcall FUN_100076a0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_100076e0 at 100076e0

undefined4 __fastcall FUN_100076e0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10007720 at 10007720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10007720(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 local_18;
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = this;
    local_18 = FUN_10008da0(this,param_1);
  }
  return local_18;
}



// Function: CSymbolicTreeComponent_FinalConstruct at 10007790

undefined8 __fastcall CSymbolicTreeComponent_FinalConstruct(int param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int *piVar2;
  undefined8 uVar3;
  uint uStack_178;
  int local_168 [71];
  int local_4c;
  int local_40 [3];
  int local_34;
  undefined4 local_28;
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026508;
  local_10 = ExceptionList;
  piVar2 = local_168;
  for (iVar1 = 0x55; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  uStack_178 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_178;
  ExceptionList = &local_10;
  local_28 = 0;
  local_8 = 0;
  local_1c = param_1;
  uVar3 = FUN_10007150((void *)(param_1 + 0x2c),(IID *)&DAT_10029748,(LPUNKNOWN)0x0,0x17);
  local_34 = (int)uVar3;
  if (local_34 < 0) {
    _com_issue_error(local_34);
  }
  local_40[0] = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_4c = FUN_10006f80(local_40);
  if (local_4c < 0) {
    _com_issue_error(local_4c);
  }
  if (local_40[0] == 0) {
    local_168[0] = 0;
  }
  else {
    local_168[0] = local_40[0] + 4;
  }
  FUN_100055a0((void *)(local_1c + 0x28),local_168[0]);
  uVar3 = CSymbolicTreeComponent_FinalConstruct(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@10007862 at 10007862

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Catch_10007862(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x138) = *(undefined4 *)(unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + -0x144) = *(undefined4 *)(unaff_EBP + -0x138);
  if (*(int *)(unaff_EBP + -0x144) == 0) {
    *(undefined4 *)(unaff_EBP + -0x164) = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x144) + 0x10))(1);
    *(undefined4 *)(unaff_EBP + -0x164) = uVar1;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: CSymbolicTreeComponent_FinalConstruct at 100078bf

undefined8 __fastcall CSymbolicTreeComponent_FinalConstruct(undefined4 param_1,undefined4 param_2)

{
  int unaff_EBP;
  undefined8 uVar1;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_1000799d(param_1,param_2);
  return uVar1;
}



// Function: Catch@100078d4 at 100078d4

undefined * Catch_100078d4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x54),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330e4 + 0x19,"CSymbolicTreeComponent::FinalConstruct",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x15c) = uVar2;
  return &DAT_100079b7;
}



// Function: Catch@10007928 at 10007928

undefined * Catch_10007928(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x6c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x6c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330e4 + 0x19,"CSymbolicTreeComponent::FinalConstruct",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x150) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x10007991;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return &DAT_100079a6;
}



// Function: FUN_1000799d at 1000799d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000799d(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x24);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100079fc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10007a40 at 10007a40

undefined8 __fastcall FUN_10007a40(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  uint uStack_fc;
  undefined4 local_ec [52];
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026530;
  local_10 = ExceptionList;
  puVar5 = local_ec;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uStack_fc = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_fc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = param_1;
  bVar1 = FUN_10005b20((void *)(param_1 + 0x28),0);
  uVar3 = extraout_ECX;
  uVar4 = extraout_EDX;
  if (bVar1) {
    uVar6 = FUN_1000ed90((undefined4 *)(local_1c + 0x28));
    uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
    uVar3 = extraout_ECX_00;
  }
  uVar6 = FUN_10007ac5(uVar3,uVar4);
  return uVar6;
}



// Function: Catch@10007ab2 at 10007ab2

undefined * Catch_10007ab2(void)

{
  int unaff_EBP;
  
  FUN_10005c00((void *)(*(int *)(unaff_EBP + -0x18) + 0x2c),0);
  return &DAT_10007ace;
}



// Function: FUN_10007ac5 at 10007ac5

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10007ac5(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10007b08);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,in_EAX);
}



// Function: FUN_10007b20 at 10007b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10007b20(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  free(param_1);
  return;
}



// Function: FUN_10007b70 at 10007b70

int __fastcall FUN_10007b70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1 + 8;
}



// Function: CSymbolicTreeComponent_GetDataByID at 10007ba0

undefined8 CSymbolicTreeComponent_GetDataByID(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 extraout_EDX_00;
  int **ppiVar4;
  undefined8 uVar5;
  int *piVar6;
  uint uStack_158;
  int *local_148 [3];
  int local_13c [69];
  undefined4 local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026563;
  local_10 = ExceptionList;
  ppiVar4 = local_148;
  for (iVar1 = 0x4d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar4 = (int *)0xcccccccc;
    ppiVar4 = ppiVar4 + 1;
  }
  uStack_158 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_158;
  ExceptionList = &local_10;
  local_1c = 0;
  local_28 = 0x4fffffff;
  local_8 = 0;
  if (param_4 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
  }
  else {
    *param_4 = 0;
    local_14 = (undefined1 *)&uStack_158;
  }
  if (((int)param_3 < 0) || (0x4fffffff < (int)param_3)) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
  }
  if (param_2 == 0) {
    uVar5 = FUN_1000db10(param_3,param_4);
    uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar2 = extraout_ECX_00;
  }
  else {
    piVar6 = param_4;
    local_148[0] = (int *)FUN_100031b0(local_13c,param_2);
    local_8._0_1_ = 1;
    local_148[1] = local_148[0];
    FUN_1000d6e0(param_3,local_148[0],piVar6);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10004c80(local_13c);
    uVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
  }
  if (*param_4 == 0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
    uVar2 = extraout_ECX_01;
    uVar3 = extraout_EDX_00;
  }
  uVar5 = FUN_10007dd3(uVar2,uVar3);
  return uVar5;
}



// Function: Catch@10007d04 at 10007d04

undefined * Catch_10007d04(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x30),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f8 + 0x2e,"CSymbolicTreeComponent::GetDataByID",*puVar1,puVar1[1])
  ;
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  *(undefined4 *)(unaff_EBP + -300) = *(undefined4 *)(unaff_EBP + -0x3c);
  return &DAT_10007ded;
}



// Function: Catch@10007d5e at 10007d5e

undefined * Catch_10007d5e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x54),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x54),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f8 + 0x35,"CSymbolicTreeComponent::GetDataByID",*puVar1,puVar1[1])
  ;
  *(undefined4 *)(unaff_EBP + -0x120) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10007dc7;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x54));
  return &DAT_10007ddc;
}



// Function: FUN_10007dd3 at 10007dd3

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10007dd3(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10007e34);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeComponent_GetDataByName at 10007e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void CSymbolicTreeComponent_GetDataByName(int param_1,wchar_t *param_2,int *param_3)

{
  IUnknown *pIVar1;
  size_t sVar2;
  int iVar3;
  LPSTR *ppCVar4;
  _GUID *p_Var5;
  LPSTR local_178;
  int local_174;
  LPSTR local_170;
  LPSTR local_16c;
  undefined4 local_8c [15];
  wchar_t *local_50;
  UINT local_44;
  int local_38;
  int local_2c;
  undefined4 local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026598;
  local_10 = ExceptionList;
  ppCVar4 = &local_178;
  for (iVar3 = 0x59; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppCVar4 = (LPSTR)0xcccccccc;
    ppCVar4 = ppCVar4 + 1;
  }
  local_18 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xfffffe78;
  ExceptionList = &local_10;
  local_8c[0] = 0;
  local_20 = 0;
  local_8 = 0;
  if (param_3 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
  }
  else {
    *param_3 = 0;
    local_14 = &stack0xfffffe78;
  }
  if ((param_2 == (wchar_t *)0x0) || (iVar3 = Ordinal_7(param_2), iVar3 == 0)) {
    local_2c = FUN_10006f00((void *)(param_1 + 0x24),param_3);
    if (local_2c < 0) {
      p_Var5 = (_GUID *)&DAT_1002a34c;
      pIVar1 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x24));
      _com_issue_errorex(local_2c,pIVar1,p_Var5);
    }
  }
  else {
    FUN_1000d210(param_2,(undefined4 *)(param_1 + 0x24),param_3);
    if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
      local_44 = FUN_1000a4a0();
      local_50 = param_2;
      if (param_2 == (wchar_t *)0x0) {
        local_16c = (LPSTR)0x0;
      }
      else {
        sVar2 = wcslen(param_2);
        local_38 = sVar2 + 1;
        if (local_38 < 0x40000000) {
          local_174 = local_38 * 2 + 0x24;
          local_178 = &stack0xfffffe78;
          local_14 = &stack0xfffffe78;
          _RTC_AllocaHelper(&stack0xfffffe78,local_174,local_8c);
          local_178 = local_178 + 0x20;
          local_170 = FUN_10006d50(local_178,local_50,local_38 << 1,local_44);
        }
        else {
          local_170 = (LPSTR)0x0;
        }
        local_16c = local_170;
      }
      FUN_10021d70((uchar *)
                   "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                  );
    }
  }
  FUN_10008136();
  return;
}



// Function: Catch@1000806d at 1000806d

undefined * Catch_1000806d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -100),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330ec + 0x2a,"CSymbolicTreeComponent::GetDataByName",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x160) = uVar2;
  return &DAT_10008150;
}



// Function: Catch@100080c1 at 100080c1

undefined * Catch_100080c1(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x7c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x7c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330ec + 0x2a,"CSymbolicTreeComponent::GetDataByName",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x154) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x1000812a;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x7c));
  return &DAT_1000813f;
}



// Function: FUN_10008136 at 10008136

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10008136(void)

{
  uint uVar1;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_100081a0,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x88));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x178) = 0x10008197;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: CSymbolicTreeComponent_GetDataByPathName at 100081e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void CSymbolicTreeComponent_GetDataByPathName(int *param_1,int param_2,wchar_t *param_3,int *param_4)

{
  bool bVar1;
  IUnknown *pIVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  wchar_t *_Str2;
  wchar_t *_Str1;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  LPSTR *ppCVar8;
  _GUID *p_Var9;
  int *piVar10;
  uint uStack_2b0;
  LPSTR local_2a0;
  int local_29c;
  int *local_298;
  int *local_294;
  undefined1 local_28c [248];
  undefined4 local_194 [15];
  wchar_t *local_158;
  UINT local_14c;
  int local_140;
  int local_134;
  int local_128 [3];
  int local_11c;
  int local_110 [3];
  undefined4 local_104 [8];
  uint local_e4;
  int local_d8;
  undefined4 local_cc [3];
  int local_c0 [3];
  int local_b4;
  int local_a8 [3];
  long local_9c;
  int local_90 [3];
  int local_84 [3];
  uint local_78;
  undefined4 local_6c [8];
  undefined4 local_4c [8];
  int local_2c [3];
  undefined4 local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026643;
  local_10 = ExceptionList;
  ppCVar8 = &local_2a0;
  for (iVar7 = 0xa3; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppCVar8 = (LPSTR)0xcccccccc;
    ppCVar8 = ppCVar8 + 1;
  }
  uStack_2b0 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2b0;
  ExceptionList = &local_10;
  local_194[0] = 0;
  local_20 = 0;
  local_8 = 0;
  local_18 = uStack_2b0;
  if (param_4 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                );
  }
  else {
    *param_4 = 0;
    local_14 = (undefined1 *)&uStack_2b0;
  }
  if (param_1 == (int *)0x4) {
    local_294 = (int *)0x0;
  }
  else {
    local_294 = param_1;
  }
  FUN_100030a0(local_2c,(int)local_294);
  local_8._0_1_ = 1;
  FUN_10003b10(param_3);
  local_8._0_1_ = 2;
  FUN_10003b80();
  local_8._0_1_ = 3;
  local_78 = FUN_1000cfc0(L".",0);
  if (local_78 == 0xffffffff) {
    FUN_10005790(local_6c,local_4c);
  }
  else {
    local_298 = (int *)FUN_1000f5f0(local_28c,0,local_78);
    local_8._0_1_ = 4;
    local_294 = local_298;
    FUN_10005670(local_6c,local_298);
    local_8._0_1_ = 3;
    FUN_10004fe0(local_28c);
  }
  FUN_100031b0(local_84,param_2);
  local_8 = CONCAT31(local_8._1_3_,5);
  bVar1 = FUN_10005840(local_84,0);
  if (bVar1) {
    FUN_100054d0(param_1 + 9);
  }
  FUN_10003230(local_90);
  local_8 = CONCAT31(local_8._1_3_,6);
  local_294 = (int *)FUN_10005ec0(local_84);
  FUN_10006110(local_90);
  local_9c = (**(code **)(*local_294 + 0x34))();
  if (local_9c < 0) {
    p_Var9 = (_GUID *)&DAT_1002a34c;
    pIVar2 = (IUnknown *)FUN_10005cd0(local_84);
    _com_issue_errorex(local_9c,pIVar2,p_Var9);
  }
  do {
    bVar1 = FUN_10005b20(local_90,0);
    if (!bVar1) {
LAB_10008717:
      if ((param_4 != (int *)0x0) && (*param_4 == 0)) {
        local_14c = FUN_1000a4a0();
        local_158 = param_3;
        if (param_3 == (wchar_t *)0x0) {
          local_294 = (int *)0x0;
        }
        else {
          sVar6 = wcslen(param_3);
          local_140 = sVar6 + 1;
          if (local_140 < 0x40000000) {
            local_29c = local_140 * 2 + 0x24;
            local_2a0 = &stack0xfffffd44;
            local_14 = &stack0xfffffd44;
            _RTC_AllocaHelper(&stack0xfffffd44,local_29c,local_194);
            local_2a0 = local_2a0 + 0x20;
            local_298 = (int *)FUN_10006d50(local_2a0,local_158,local_140 << 1,local_14c);
          }
          else {
            local_298 = (int *)0x0;
          }
          local_294 = local_298;
        }
        FUN_10021d70((uchar *)
                     "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                    );
      }
      local_8._0_1_ = 5;
      FUN_10004c80(local_90);
      local_8._0_1_ = 3;
      FUN_10004c80(local_84);
      local_8._0_1_ = 2;
      FUN_10004fe0(local_6c);
      local_8._0_1_ = 1;
      FUN_10004fe0(local_4c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10004c00(local_2c);
      FUN_10008952();
      return;
    }
    FUN_10003330(local_a8);
    local_8 = CONCAT31(local_8._1_3_,7);
    local_294 = (int *)FUN_10005ec0(local_90);
    uVar3 = FUN_10006140(local_a8);
    local_b4 = (**(code **)(*local_294 + 0x4c))(local_294,uVar3);
    if (local_b4 < 0) {
      p_Var9 = (_GUID *)&DAT_1002a34c;
      pIVar2 = (IUnknown *)FUN_10005cd0(local_90);
      _com_issue_errorex(local_b4,pIVar2,p_Var9);
    }
    puVar4 = (undefined4 *)FUN_10005d00(local_a8);
    FUN_10002ff0(local_c0,puVar4);
    local_8._0_1_ = 8;
    FUN_10003d30(local_cc);
    local_8 = CONCAT31(local_8._1_3_,9);
    local_294 = (int *)FUN_10005e60(local_c0);
    uVar3 = FUN_10006200(local_cc);
    local_d8 = (**(code **)(*local_294 + 0x1c))(local_294,uVar3);
    if (local_d8 < 0) {
      p_Var9 = (_GUID *)&DAT_1002a324;
      pIVar2 = (IUnknown *)FUN_10005c70(local_c0);
      _com_issue_errorex(local_d8,pIVar2,p_Var9);
    }
    _Str2 = (wchar_t *)FUN_10005dc0(local_cc);
    _Str1 = (wchar_t *)FUN_1000c530(local_6c);
    iVar7 = wcscmp(_Str1,_Str2);
    if (iVar7 == 0) {
      if (local_78 == 0xffffffff) {
        if (param_4 != (int *)0x0) {
          iVar7 = FUN_10007660(local_90);
          *param_4 = iVar7;
        }
        local_8._0_1_ = 8;
        FUN_10001000(local_cc);
        local_8._0_1_ = 7;
        FUN_10004b80(local_c0);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_10004d00(local_a8);
        goto LAB_10008717;
      }
      iVar7 = FUN_1000e150((int)local_4c);
      local_e4 = iVar7 - (local_78 + 1);
      FUN_1000f5f0(local_104,local_78 + 1,local_e4);
      local_8._0_1_ = 10;
      iVar7 = FUN_1000c530(local_104);
      FUN_10004160(iVar7);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      local_294 = (int *)FUN_10005e90(local_2c);
      piVar10 = param_4;
      uVar3 = FUN_10005df0(local_110);
      uVar5 = FUN_10005cd0(local_90);
      local_11c = (**(code **)(*local_294 + 0x20))(local_294,uVar5,uVar3,piVar10);
      if (local_11c < 0) {
        p_Var9 = (_GUID *)&DAT_1002a468;
        pIVar2 = (IUnknown *)FUN_10005ca0(local_2c);
        _com_issue_errorex(local_11c,pIVar2,p_Var9);
      }
      local_8._0_1_ = 10;
      FUN_10005320(local_110);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_10004fe0(local_104);
    }
    FUN_10003230(local_128);
    local_8 = CONCAT31(local_8._1_3_,0xc);
    local_294 = (int *)FUN_10005ec0(local_90);
    uVar3 = FUN_10006110(local_128);
    local_134 = (**(code **)(*local_294 + 0x24))(local_294,uVar3);
    if (local_134 < 0) {
      p_Var9 = (_GUID *)&DAT_1002a34c;
      pIVar2 = (IUnknown *)FUN_10005cd0(local_90);
      _com_issue_errorex(local_134,pIVar2,p_Var9);
    }
    FUN_100054d0(local_128);
    local_8._0_1_ = 9;
    FUN_10004c80(local_128);
    local_8._0_1_ = 8;
    FUN_10001000(local_cc);
    local_8._0_1_ = 7;
    FUN_10004b80(local_c0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_10004d00(local_a8);
  } while( true );
}



// Function: Catch@1000887d at 1000887d

undefined * Catch_1000887d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x16c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f0 + 0x70,"CSymbolicTreeComponent::GetDataByPathName",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x268) = uVar2;
  return &DAT_1000896c;
}



// Function: Catch@100088d4 at 100088d4

undefined * Catch_100088d4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x184),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  puVar1 = (undefined8 *)FUN_10008d70();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x184),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreecomponent.cpp"
                       ,DAT_100330f0 + 0x70,"CSymbolicTreeComponent::GetDataByPathName",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x25c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  uStack0000001c = 0x10008946;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x184));
  return &DAT_1000895b;
}



// Function: FUN_10008952 at 10008952

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10008952(void)

{
  uint uVar1;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_100089bc,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 400));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x2a0) = 0x100089b3;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_10008b00 at 10008b00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10008b00(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10008b60(&PTR_DAT_100330c8,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008b60 at 10008b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall
FUN_10008b60(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  size_t _Size;
  void *_Buf1;
  int iVar1;
  undefined4 *puVar2;
  void *_Buf2;
  undefined4 local_f4 [49];
  int local_30;
  size_t local_24;
  int local_18;
  void *local_c;
  
  puVar2 = local_f4;
  for (iVar1 = 0x3c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  local_18 = FUN_10007720(this,param_4);
  if (*(int *)((int)local_c + 0xc) != 0) {
    local_18 = -0x7fffbffb;
    if ((*(int *)((int)local_c + 0x14) != 0) && (param_3 == 1)) {
      local_24 = FUN_1000e9c0((wchar_t *)*param_2);
      local_30 = *(int *)((int)local_c + 0x18);
      do {
        do {
          local_30 = local_30 + -1;
          if (local_30 < 0) goto LAB_10008c7b;
        } while (local_24 != *(size_t *)(*(int *)((int)local_c + 0x14) + 4 + local_30 * 0xc));
        _Size = *(int *)(*(int *)((int)local_c + 0x14) + 4 + local_30 * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_10005dc0((undefined4 *)(local_30 * 0xc + *(int *)((int)local_c + 0x14)))
        ;
        iVar1 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar1 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)local_c + 0x14) + 8 + local_30 * 0xc);
      local_18 = 0;
    }
LAB_10008c7b:
    if (local_18 < 0) {
      local_18 = (**(code **)(**(int **)((int)local_c + 0xc) + 0x28))
                           (*(undefined4 *)((int)local_c + 0xc),param_2,param_3,param_5);
    }
  }
  return local_18;
}



// Function: FUN_10008cd0 at 10008cd0

undefined * FUN_10008cd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_10029618;
}



// Function: FUN_10008d00 at 10008d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10008d00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10008cd0();
  return;
}



// Function: FUN_10008d40 at 10008d40

undefined4 __fastcall FUN_10008d40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10008d70 at 10008d70

undefined * FUN_10008d70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_1002ac54;
}



// Function: FUN_10008da0 at 10008da0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10008da0(void *this,undefined4 param_1)

{
  char cVar1;
  HMODULE hModule;
  size_t sVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  LPWSTR *ppWVar8;
  undefined8 uVar9;
  CHAR *lpFilename;
  DWORD nSize;
  LPWSTR local_2d0 [2];
  int local_2c8;
  LPWSTR local_2c4;
  LPWSTR local_2c0;
  int local_2b8;
  undefined4 local_2ac;
  int local_2a0;
  _RTC_ALLOCA_NODE *local_1d4 [3];
  int local_1c8 [3];
  int local_1bc [3];
  int local_1b0 [3];
  LPWSTR local_1a4;
  int local_198 [3];
  char *local_18c;
  UINT local_174;
  uint local_168 [3];
  DWORD local_15c;
  CHAR local_150 [268];
  int *local_44 [3];
  int local_38;
  undefined4 local_2c [4];
  undefined4 *local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100266a4;
  local_10 = ExceptionList;
  ppWVar8 = local_2d0;
  for (iVar7 = 0xb0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppWVar8 = (LPWSTR)0xcccccccc;
    ppWVar8 = ppWVar8 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1d4[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_1c = (undefined4 *)this;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10002680(local_2c,(int)DAT_1003387c + 0x10,'\0');
    local_8 = 0;
    local_38 = FUN_10009e80(local_2c);
    if (local_38 < 0) {
      local_8 = 0xffffffff;
      local_2b8 = local_38;
      FUN_10004450(local_2c);
    }
    else {
      local_38 = -0x7fffbffb;
      if (local_1c[3] == 0) {
        local_44[0] = (int *)0x0;
        iVar7 = FUN_1000f790((int *)&DAT_10033880,(int *)local_1c[1]);
        if (((iVar7 == 0) || (*(short *)(local_1c + 2) != -1)) ||
           (*(short *)((int)local_1c + 10) != -1)) {
          local_38 = Ordinal_162(local_1c[1],*(undefined2 *)(local_1c + 2),
                                 *(undefined2 *)((int)local_1c + 10),param_1);
        }
        else {
          nSize = 0x104;
          lpFilename = local_150;
          hModule = (HMODULE)FUN_10008d40(0x1003391c);
          local_15c = GetModuleFileNameA(hModule,lpFilename,nSize);
          if ((local_15c != 0) && (local_15c != 0x104)) {
            local_174 = FUN_1000a4a0();
            FUN_10002640(local_198);
            local_8._0_1_ = 1;
            local_18c = local_150;
            if (local_18c == (char *)0x0) {
              local_2c0 = (LPWSTR)0x0;
            }
            else {
              sVar2 = strlen(local_18c);
              local_168[0] = sVar2 + 1;
              uVar3 = FUN_100014b0(local_168,local_168[0],2);
              if ((int)uVar3 < 0) {
                local_2c4 = (LPWSTR)0x0;
              }
              else {
                if (((int)local_168[0] < 0x401) &&
                   (cVar1 = FUN_1000a520(local_168[0]), cVar1 != '\0')) {
                  local_2c8 = local_168[0] + 0x24;
                  local_2d0[1] = (LPWSTR)&stack0xfffffd1c;
                  _RTC_AllocaHelper(&stack0xfffffd1c,local_2c8,local_1d4);
                  local_2d0[0] = (LPWSTR)((int)local_2d0[1] + 0x20);
                  local_2d0[1] = local_2d0[0];
                }
                else {
                  local_2d0[0] = (LPWSTR)FUN_10006820(local_168[0]);
                }
                local_2c4 = FUN_100068f0(local_2d0[0],local_18c,local_168[0] >> 1,local_174);
              }
              local_2c0 = local_2c4;
            }
            local_1a4 = local_2c0;
            if (local_2c0 == (LPWSTR)0x0) {
              local_2ac = 0x8007000e;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100043e0(local_198);
              local_8 = 0xffffffff;
              FUN_10004450(local_2c);
              goto LAB_10009243;
            }
            local_38 = Ordinal_161(local_2c0,local_44);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100043e0(local_198);
          }
        }
        if (-1 < local_38) {
          FUN_10002bb0(local_1b0);
          local_8._0_1_ = 2;
          uVar4 = FUN_100061a0(local_1b0);
          local_38 = (**(code **)(*local_44[0] + 0x18))(local_44[0],*local_1c,uVar4);
          uVar4 = 0x1000912a;
          if (-1 < local_38) {
            FUN_10002b20(local_1bc,local_1b0);
            local_8._0_1_ = 3;
            FUN_10002aa0(local_1c8);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar5 = FUN_10006170(local_1c8);
            puVar6 = (undefined4 *)FUN_10005ef0(local_1b0);
            iVar7 = FUN_10001540(puVar6,uVar5);
            if (-1 < iVar7) {
              FUN_10001240(local_1c8);
            }
            uVar5 = FUN_100076a0(local_1bc);
            local_1c[3] = uVar5;
            FUN_10006580(DAT_1003387c,FUN_10006e40,local_1c);
            local_8._0_1_ = 3;
            FUN_10004760(local_1c8);
            local_8._0_1_ = 2;
            FUN_100047e0(local_1bc);
          }
          (**(code **)(*local_44[0] + 8))(local_44[0],uVar4);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100047e0(local_1b0);
        }
      }
      else {
        local_38 = 0;
      }
      if ((local_1c[3] != 0) && (local_1c[5] == 0)) {
        uVar9 = FUN_10009b60((int *)local_1c[3]);
        local_38 = (int)uVar9;
      }
      local_2a0 = local_38;
      local_8 = 0xffffffff;
      FUN_10004450(local_2c);
    }
  }
LAB_10009243:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10009280,local_1d4[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009360 at 10009360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10009360(void *this,undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 local_18;
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_2 == (undefined4 *)0x0) {
    local_18 = 0x80004003;
  }
  else {
    local_18 = 0;
    local_c = this;
    if (*(int *)((int)this + 0xc) == 0) {
      local_18 = FUN_10008da0(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)local_c + 0xc);
    if (*(int *)((int)local_c + 0xc) != 0) {
      (**(code **)(**(int **)((int)local_c + 0xc) + 4))(*(undefined4 *)((int)local_c + 0xc));
      local_18 = 0;
    }
  }
  return local_18;
}



// Function: FUN_10009400 at 10009400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10009400(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009450(&PTR_DAT_100330c8,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009450 at 10009450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10009450(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == 0) {
    local_c = this;
    uVar1 = FUN_10009360(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100094b0 at 100094b0

undefined4 FUN_100094b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100094f0 at 100094f0

undefined4 __fastcall FUN_100094f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10009520 at 10009520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10009520(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_10009570 at 10009570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __fastcall FUN_10009570(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_dc [49];
  uint local_18;
  LPCRITICAL_SECTION local_c;
  
  puVar4 = local_dc;
  for (iVar3 = 0x36; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = 0;
  local_c = param_1;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    local_18 = FUN_1000f730(DVar2);
  }
  return local_18;
}



// Function: FUN_100095f0 at 100095f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __fastcall FUN_100095f0(LPCRITICAL_SECTION param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [52];
  LPCRITICAL_SECTION local_c;
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = param_1;
  uVar1 = FUN_10009570(param_1);
  if (-1 < (int)uVar1) {
    *(undefined1 *)&local_c[1].DebugInfo = 1;
  }
  return uVar1;
}



// Function: FUN_10009650 at 10009650

undefined4 FUN_10009650(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    local_c8[0] = 1;
  }
  else {
    local_c8[0] = 0;
  }
  return local_c8[0];
}



// Function: FUN_100096e0 at 100096e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100096e0(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  while( true ) {
    if (local_c != 0) {
      return 1;
    }
    iVar1 = FUN_1000f790((int *)PTR_DAT_10033000,param_2);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_10009760 at 10009760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009760(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LONG *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10009520(param_1);
  return;
}



// Function: FUN_100097b0 at 100097b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100097b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10009760((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10009800 at 10009800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009800(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100098a0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10009850 at 10009850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10009850(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_10006a10(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_100098a0 at 100098a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100098a0(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LONG *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10007610(param_1);
  return;
}



// Function: FUN_100098e0 at 100098e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100098e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009950(&PTR_DAT_100330c8,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10009950 at 10009950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall
FUN_10009950(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 local_18;
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  local_18 = FUN_10007720(this,param_4);
  if (*(int *)((int)local_c + 0xc) != 0) {
    local_18 = (**(code **)(**(int **)((int)local_c + 0xc) + 0x2c))
                         (*(undefined4 *)((int)local_c + 0xc),param_1,param_2,param_5,param_6,
                          param_7,param_8,param_9);
  }
  return local_18;
}



// Function: FUN_100099f0 at 100099f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_100099f0(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 local_100;
  undefined1 local_f9;
  int local_30 [3];
  int local_24 [3];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100266e0;
  local_10 = ExceptionList;
  puVar4 = &local_100;
  for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  if ((*param_1 == 0) && (param_3 == (undefined4 *)0x0)) {
    uVar1 = CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  else if ((*param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    uVar1 = (uint)param_1 & 0xffffff00;
  }
  else {
    FUN_10002c30(local_24);
    local_8 = 0;
    FUN_10002c30(local_30);
    local_8._0_1_ = 1;
    uVar2 = FUN_100061d0(local_24);
    (*(code *)**(undefined4 **)*local_18)(*local_18,&DAT_10029418,uVar2,uVar1);
    uVar6 = 0x10009a9f;
    uVar2 = FUN_100061d0(local_30);
    (**(code **)*param_3)(param_3,&DAT_10029418,uVar2,uVar6);
    iVar3 = FUN_10005d90(local_30);
    local_f9 = FUN_10005900(local_24,iVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10004860(local_30);
    local_8 = 0xffffffff;
    uVar5 = FUN_10004860(local_24);
    param_2 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar1 = CONCAT31((int3)((ulonglong)uVar5 >> 8),local_f9);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009b30);
  ExceptionList = local_10;
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10009b60 at 10009b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009b60(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint **ppuVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *local_14c [2];
  uint local_144;
  uint *local_138;
  uint *local_12c;
  undefined4 local_60 [3];
  uint *local_54 [3];
  int local_48;
  uint *local_3c;
  int local_30;
  int local_24 [3];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002671d;
  local_10 = ExceptionList;
  ppuVar4 = local_14c;
  for (iVar2 = 0x4f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (uint *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  ExceptionList = &local_10;
  piVar9 = param_1;
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,local_24,DAT_10033838 ^ (uint)&stack0xfffffffc);
  local_30 = (int)uVar5;
  if (-1 < local_30) {
    local_3c = (uint *)0x0;
    *(uint *)(local_18 + 0x18) = (uint)*(ushort *)(local_24[0] + 0x2c);
    *(undefined4 *)(local_18 + 0x14) = 0;
    if (*(int *)(local_18 + 0x18) != 0) {
      local_144 = *(uint *)(local_18 + 0x18);
      uVar3 = -(uint)((int)((ulonglong)local_144 * 0xc >> 0x20) != 0) |
              (uint)((ulonglong)local_144 * 0xc);
      local_12c = (uint *)FUN_100240c4(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
      local_8 = 0;
      if (local_12c == (uint *)0x0) {
        local_14c[0] = (uint *)0x0;
      }
      else {
        *local_12c = local_144;
        _eh_vector_constructor_iterator_(local_12c + 1,0xc,local_144,FUN_10004350,FUN_10001050);
        local_14c[0] = local_12c + 1;
      }
      local_138 = local_14c[0];
      local_8 = 0xffffffff;
      local_3c = local_14c[0];
      if (local_14c[0] == (uint *)0x0) {
        (**(code **)(*param_1 + 0x4c))(param_1,local_24[0]);
        uVar5 = CONCAT44(extraout_EDX,local_30);
        uVar1 = 0x8007000e;
        goto LAB_10009e09;
      }
    }
    for (local_48 = 0; local_48 < *(int *)(local_18 + 0x18); local_48 = local_48 + 1) {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1,local_48,local_54);
      piVar9 = (int *)0x10009d19;
      if (-1 < iVar2) {
        FUN_10003d30(local_60);
        local_8 = 1;
        uVar8 = 0;
        uVar7 = 0;
        uVar6 = 0;
        uVar1 = FUN_10006200(local_60);
        iVar2 = (**(code **)(*param_1 + 0x30))(param_1,*local_54[0],uVar1,uVar6,uVar7,uVar8);
        uVar1 = 0x10009d5c;
        if (-1 < iVar2) {
          iVar2 = FUN_100076e0(local_60);
          FUN_10006de0(local_3c + local_48 * 3,iVar2);
          uVar1 = FUN_10005dc0(local_3c + local_48 * 3);
          uVar3 = Ordinal_7(uVar1);
          uVar1 = 0x10009d95;
          local_3c[local_48 * 3 + 1] = uVar3;
          local_3c[local_48 * 3 + 2] = *local_54[0];
        }
        (**(code **)(*param_1 + 0x50))(param_1,local_54[0],uVar1);
        piVar9 = (int *)0x10009dcf;
        local_8 = 0xffffffff;
        FUN_10001000(local_60);
      }
    }
    *(uint **)(local_18 + 0x14) = local_3c;
    (**(code **)(*param_1 + 0x4c))(param_1,local_24[0],piVar9);
    uVar5 = CONCAT44(extraout_EDX_00,local_30);
  }
  uVar1 = 0;
LAB_10009e09:
  uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);
  local_30 = (int)uVar5;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009e3c);
  ExceptionList = local_10;
  return CONCAT44(uVar6,uVar1);
}



// Function: FUN_10009e80 at 10009e80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10009e80(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [52];
  undefined4 *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  iVar1 = FUN_10009ee0((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(local_c + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10009ee0 at 10009ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10009ee0(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LPCRITICAL_SECTION local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_10009f30 at 10009f30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10009f30(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000b4b0(param_2,param_3);
  return;
}



// Function: FUN_10009f74 at 10009f74

void FUN_10009f74(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009f30(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10009f80 at 10009f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10009f80(int *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_ec [5];
  int *local_d8;
  int local_c;
  
  ppiVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = FUN_100098a0(param_1 + 2);
  if (local_c == 0) {
    local_d8 = param_1;
    local_ec[2] = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x10))(1);
    }
  }
  return local_c;
}



// Function: FUN_1000a019 at 1000a019

void FUN_1000a019(int param_1)

{
  FUN_10009f80((int *)(param_1 + -4));
  return;
}



// Function: FUN_1000a030 at 1000a030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG __fastcall FUN_1000a030(void *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_f8 [5];
  void *local_e4;
  LONG local_18;
  void *local_c;
  
  ppvVar2 = local_f8;
  for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_c = param_1;
  local_18 = InterlockedDecrement((LONG *)((int)param_1 + 8));
  if (local_18 == 0) {
    local_e4 = local_c;
    local_f8[2] = local_c;
    if (local_c != (void *)0x0) {
      FUN_100062f0(local_c,1);
    }
  }
  return local_18;
}



// Function: FUN_1000a0d0 at 1000a0d0

void FUN_1000a0d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000a100 at 1000a100

void __thiscall FUN_1000a100(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  uVar1 = *this;
  *(undefined4 *)this = *param_1;
  *param_1 = uVar1;
  return;
}



// Function: FUN_1000a150 at 1000a150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a150(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000a1a0((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(local_c + 1) = 0;
  return;
}



// Function: FUN_1000a1a0 at 1000a1a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000a1a0(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LPCRITICAL_SECTION local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000a1f0 at 1000a1f0

void FUN_1000a1f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000a220 at 1000a220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000a220(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *extraout_EAX;
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined4 local_f4 [49];
  undefined4 local_30;
  _Lockit local_24 [12];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026752;
  local_10 = ExceptionList;
  puVar2 = local_f4;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  if (param_3 == (undefined4 *)0x0) {
    std::_Lockit::_Lockit(local_24,3);
    local_8 = 0;
    FUN_1000b6c0();
    local_8 = 0xffffffff;
    std::_Lockit::~_Lockit(local_24);
    param_1 = extraout_EAX;
    param_2 = extraout_EDX;
  }
  else {
    local_30 = *param_3;
    *param_1 = local_30;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a2e8);
  ExceptionList = local_10;
  return CONCAT44(param_2,param_1);
}



// Function: FUN_1000a310 at 1000a310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000a310(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_ec [53];
  undefined1 local_15 [9];
  undefined4 *local_c;
  
  puVar2 = local_ec;
  for (iVar3 = 0x3a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100038a0(local_15);
  uVar1 = FUN_1000bd60(1);
  *local_c = uVar1;
  puVar2 = FUN_10003e50(local_ec + 1);
  FUN_10001f40(*local_c,puVar2);
  *(undefined4 **)*local_c = local_c;
  puVar2 = local_c;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a394);
  return CONCAT44(puVar2,local_c);
}



// Function: FUN_1000a3c0 at 1000a3c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000a3c0(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [201];
  void *local_c;
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if ((uint)param_1[5] < 8) {
    FUN_1000e8c0(this,param_1,param_1[4] + 1);
  }
  else {
    puVar2 = param_1;
    FUN_1000ae90(local_d5);
    FUN_10001dc0(this,puVar2);
    *param_1 = 0;
  }
  *(undefined4 *)((int)local_c + 0x10) = param_1[4];
  *(undefined4 *)((int)local_c + 0x14) = param_1[5];
  FUN_1000b8d0(param_1,'\0',0);
  return;
}



// Function: FUN_1000a470 at 1000a470

undefined4 FUN_1000a470(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1000a4a0 at 1000a4a0

undefined4 FUN_1000a4a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 3;
}



// Function: FUN_1000a4d0 at 1000a4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a4d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100095f0((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000a520 at 1000a520

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_1000a520(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 **ppuVar4;
  uint local_140;
  undefined1 *local_130;
  int local_12c;
  _RTC_ALLOCA_NODE *local_58 [3];
  undefined1 *local_4c;
  uint local_40;
  int local_34 [3];
  undefined1 local_25;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  undefined *local_c;
  undefined4 local_8;
  
  local_c = &DAT_1002e6d0;
  pcStack_10 = FUN_1002418c;
  local_14 = ExceptionList;
  ppuVar4 = &local_130;
  for (iVar3 = 0x45; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined1 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  local_c = (undefined *)((uint)local_c ^ DAT_10033838);
  local_140 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_140;
  ExceptionList = &local_14;
  local_58[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_25 = 1;
  local_8 = 0;
  local_34[0] = 0;
  local_20 = local_140;
  local_40 = FUN_100013c0(local_34,param_1,0x2000);
  if ((int)local_40 < 0) {
    local_25 = 0;
  }
  else {
    local_12c = local_34[0] + 0x24;
    iVar3 = -(local_34[0] + 0x24);
    local_130 = (undefined1 *)((int)&local_140 + iVar3);
    local_1c = (undefined1 *)((int)&local_140 + iVar3);
    *(_RTC_ALLOCA_NODE ***)(&stack0xfffffebc + iVar3) = local_58;
    iVar2 = local_12c;
    puVar1 = local_130;
    *(undefined4 *)(&stack0xfffffeb8 + iVar3) = 0x1000a5dd;
    _RTC_AllocaHelper(puVar1,iVar2,*(undefined4 **)(&stack0xfffffebc + iVar3));
    local_130 = local_130 + 0x20;
    local_4c = local_130;
  }
  local_8 = 0xfffffffe;
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000a684,local_58[0]);
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a6e0 at 1000a6e0

void FUN_1000a6e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000a710 at 1000a710

void FUN_1000a710(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000a740 at 1000a740

undefined8 FUN_1000a740(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c;
  undefined1 local_115 [225];
  undefined4 local_34;
  uint local_28;
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026770;
  local_10 = ExceptionList;
  puVar3 = &local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_28 = param_1 | 0xf;
  uVar1 = FUN_1000e490();
  if (uVar1 < local_28) {
    local_28 = param_1;
  }
  else if (local_28 / 3 < *(uint *)(local_1c + 0x14) >> 1) {
    iVar2 = FUN_1000e490();
    if (iVar2 - (*(uint *)(local_1c + 0x14) >> 1) < *(uint *)(local_1c + 0x14)) {
      local_28 = FUN_1000e490();
    }
    else {
      local_28 = (*(uint *)(local_1c + 0x14) >> 1) + *(int *)(local_1c + 0x14);
    }
  }
  local_8 = 0;
  uVar1 = local_28 + 1;
  FUN_1000ae40(local_115);
  local_34 = FUN_1000bc70(uVar1);
  uVar4 = FUN_1000a87f();
  return uVar4;
}



// Function: Catch@1000a81f at 1000a81f

void Catch_1000a81f(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = *(int *)(unaff_EBP + -0x24) + 1;
  FUN_1000ae40(unaff_EBP + -0x105);
  uVar2 = FUN_1000bc70(uVar1);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  FUN_1000a869();
  return;
}



// Function: Catch@1000a84e at 1000a84e

void Catch_1000a84e(void)

{
  int unaff_EBP;
  
  FUN_1000b800(*(void **)(unaff_EBP + -0x18),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000a869 at 1000a869

undefined * FUN_1000a869(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000a888;
}



// Function: FUN_1000a87f at 1000a87f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000a87f(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined8 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    sVar4 = *(size_t *)(unaff_EBP + 0xc);
    puVar1 = FUN_1000b500(*(undefined4 **)(unaff_EBP + -0x18));
    FUN_1000c650(*(void **)(unaff_EBP + -0x30),puVar1,sVar4);
  }
  FUN_1000b800(*(void **)(unaff_EBP + -0x18),'\x01',0);
  iVar5 = unaff_EBP + -0x30;
  uVar3 = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_1000ae40(unaff_EBP + -0xf9);
  FUN_10001c40(uVar3,iVar5);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14) = *(undefined4 *)(unaff_EBP + -0x24);
  uVar2 = FUN_1000ab40(*(void **)(unaff_EBP + -0x18),*(int *)(unaff_EBP + 0xc));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000a920);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_1000a940 at 1000a940

undefined8 FUN_1000a940(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c;
  undefined1 local_115 [225];
  undefined4 local_34;
  uint local_28;
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026790;
  local_10 = ExceptionList;
  puVar3 = &local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_28 = param_1 | 7;
  uVar1 = FUN_1000e510();
  if (uVar1 < local_28) {
    local_28 = param_1;
  }
  else if (local_28 / 3 < *(uint *)(local_1c + 0x14) >> 1) {
    iVar2 = FUN_1000e510();
    if (iVar2 - (*(uint *)(local_1c + 0x14) >> 1) < *(uint *)(local_1c + 0x14)) {
      local_28 = FUN_1000e510();
    }
    else {
      local_28 = (*(uint *)(local_1c + 0x14) >> 1) + *(int *)(local_1c + 0x14);
    }
  }
  local_8 = 0;
  uVar1 = local_28 + 1;
  FUN_1000ae90(local_115);
  local_34 = FUN_1000bcc0(uVar1);
  uVar4 = FUN_1000aa7f();
  return uVar4;
}



// Function: Catch@1000aa1f at 1000aa1f

void Catch_1000aa1f(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = *(int *)(unaff_EBP + -0x24) + 1;
  FUN_1000ae90(unaff_EBP + -0x105);
  uVar2 = FUN_1000bcc0(uVar1);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  FUN_1000aa69();
  return;
}



// Function: Catch@1000aa4e at 1000aa4e

void Catch_1000aa4e(void)

{
  int unaff_EBP;
  
  FUN_1000b8d0(*(void **)(unaff_EBP + -0x18),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000aa69 at 1000aa69

undefined * FUN_1000aa69(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000aa88;
}



// Function: FUN_1000aa7f at 1000aa7f

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000aa7f(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    iVar4 = *(int *)(unaff_EBP + 0xc);
    puVar1 = FUN_1000b5e0(*(undefined4 **)(unaff_EBP + -0x18));
    FUN_1000c6c0(*(void **)(unaff_EBP + -0x30),puVar1,iVar4);
  }
  FUN_1000b8d0(*(void **)(unaff_EBP + -0x18),'\x01',0);
  iVar4 = unaff_EBP + -0x30;
  uVar3 = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_1000ae90(unaff_EBP + -0xf9);
  FUN_10001dc0(uVar3,iVar4);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14) = *(undefined4 *)(unaff_EBP + -0x24);
  uVar2 = FUN_1000abb0(*(void **)(unaff_EBP + -0x18),*(int *)(unaff_EBP + 0xc));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000ab20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_1000ab40 at 1000ab40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000ab40(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 local_dc;
  undefined1 local_d5 [201];
  void *local_c;
  
  puVar1 = &local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_d5[0] = 0;
  *(int *)((int)this + 0x10) = param_1;
  puVar3 = local_d5;
  local_c = this;
  puVar1 = FUN_1000b500((undefined4 *)this);
  FUN_1000c3c0((undefined1 *)((int)puVar1 + param_1),puVar3);
  return;
}



// Function: FUN_1000abb0 at 1000abb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000abb0(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 local_dc;
  undefined2 local_d6 [101];
  void *local_c;
  
  puVar1 = &local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_d6[0] = 0;
  *(int *)((int)this + 0x10) = param_1;
  puVar3 = local_d6;
  local_c = this;
  puVar1 = FUN_1000b5e0((undefined4 *)this);
  FUN_1000c3f0((undefined2 *)((int)puVar1 + param_1 * 2),puVar3);
  return;
}



// Function: FUN_1000ac20 at 1000ac20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000ac20(int *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_dc [52];
  int *local_c;
  
  ppvVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_c = param_1;
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *local_c = 0;
  }
  if (local_c[1] != 0) {
    local_dc[1] = (void *)local_c[1];
    operator_delete__(local_dc[1]);
    local_c[1] = 0;
  }
  return;
}



// Function: FUN_1000acb0 at 1000acb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000acb0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    FUN_1000a030((void *)*param_1);
    *local_c = 0;
  }
  return;
}



// Function: FUN_1000ad10 at 1000ad10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000ad10(void)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined1 local_15 [9];
  _Container_base12 *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100038a0(local_15);
  std::_Container_base12::_Orphan_all(local_c);
  FUN_100023b0();
  FUN_1000c820(*(void **)local_c);
  *(undefined4 *)local_c = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ad9c);
  return CONCAT44(extraout_EDX,local_c);
}



// Function: FUN_1000adc0 at 1000adc0

undefined ** FUN_1000adc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &PTR_DAT_1002a53c;
}



// Function: FUN_1000adf0 at 1000adf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000adf0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100038f0(param_1);
  return param_1;
}



// Function: FUN_1000ae40 at 1000ae40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ae40(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003800(param_1);
  return param_1;
}



// Function: FUN_1000ae90 at 1000ae90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000ae90(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003850(param_1);
  return param_1;
}



// Function: FUN_1000aee0 at 1000aee0

uint __thiscall FUN_1000aee0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1 >> 2 & *(int *)((int)this + 8) - 1U;
}



// Function: FUN_1000af20 at 1000af20

undefined4 __fastcall FUN_1000af20(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d4 [52];
  
  puVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 == 0) {
    local_d4[0] = 0;
  }
  else {
    local_d4[0] = *(undefined4 *)*param_1;
  }
  return local_d4[0];
}



// Function: FUN_1000af80 at 1000af80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool FUN_1000af80(uint param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint local_d4 [50];
  void *local_c;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_1000e490();
  if (uVar1 < param_1) {
    FUN_1000bae0();
  }
  if (*(uint *)((int)local_c + 0x14) < param_1) {
    FUN_1000a740(param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      FUN_1000ab40(local_c,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)local_c + 0x10)) {
      local_d4[0] = param_1;
    }
    else {
      local_d4[0] = *(size_t *)((int)local_c + 0x10);
    }
    FUN_1000b800(local_c,'\x01',local_d4[0]);
  }
  return param_1 != 0;
}



// Function: FUN_1000b070 at 1000b070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool FUN_1000b070(uint param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint local_d4 [50];
  void *local_c;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_1000e510();
  if (uVar1 < param_1) {
    FUN_1000bb30();
  }
  if (*(uint *)((int)local_c + 0x14) < param_1) {
    FUN_1000a940(param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      FUN_1000abb0(local_c,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)local_c + 0x10)) {
      local_d4[0] = param_1;
    }
    else {
      local_d4[0] = *(uint *)((int)local_c + 0x10);
    }
    FUN_1000b8d0(local_c,'\x01',local_d4[0]);
  }
  return param_1 != 0;
}



// Function: FUN_1000b160 at 1000b160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000b160(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint local_11c [2];
  undefined1 local_111 [201];
  void *local_48;
  void *local_3c;
  uint local_30;
  uint local_24;
  undefined1 local_15 [9];
  int local_c;
  
  puVar3 = local_11c;
  for (iVar2 = 0x46; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_1000adf0(local_111);
  FUN_100011c0(local_15);
  if (*(int *)(local_c + 8) == 0) {
    local_11c[0] = 1;
  }
  else {
    local_11c[0] = *(uint *)(local_c + 8);
  }
  for (local_24 = local_11c[0]; (local_24 - *(int *)(local_c + 8) < param_1 || (local_24 < 8));
      local_24 = local_24 << 1) {
    uVar1 = FUN_1000e590();
    if ((uVar1 >> 2) - local_24 < local_24) {
      FUN_1000bb80();
    }
  }
  uVar1 = local_24 - *(int *)(local_c + 8);
  local_30 = *(uint *)(local_c + 0xc) >> 2;
  local_3c = (void *)FUN_1000bd10(*(int *)(local_c + 8) + uVar1);
  local_48 = (void *)((int)local_3c + local_30 * 4);
  iVar2 = *(int *)(local_c + 4) + local_30 * 4;
  local_48 = (void *)FUN_10001a30(iVar2,*(int *)(local_c + 4),(void *)iVar2,
                                  *(int *)(local_c + 4) + *(int *)(local_c + 8) * 4,local_48);
  if (uVar1 < local_30) {
    iVar2 = *(int *)(local_c + 4) + uVar1 * 4;
    FUN_10001a30(*(undefined4 *)(local_c + 4),iVar2,(void *)*(undefined4 *)(local_c + 4),iVar2,
                 local_48);
    local_48 = (void *)FUN_10001a30(*(int *)(local_c + 4),uVar1,
                                    (void *)(*(int *)(local_c + 4) + uVar1 * 4),
                                    *(int *)(local_c + 4) + local_30 * 4,local_3c);
    FUN_10001aa0(uVar1,local_48,(undefined4 *)local_48,uVar1);
  }
  else {
    iVar2 = *(int *)(local_c + 4) + local_30 * 4;
    local_48 = (void *)FUN_10001a30(*(undefined4 *)(local_c + 4),iVar2,
                                    (void *)*(undefined4 *)(local_c + 4),iVar2,local_48);
    FUN_10001aa0(uVar1 - local_30,local_48,(undefined4 *)local_48,uVar1 - local_30);
    FUN_10001aa0(local_30,local_3c,(undefined4 *)local_3c,local_30);
  }
  FUN_10001810(*(int *)(local_c + 4),local_30,*(int *)(local_c + 4) + local_30 * 4);
  if (*(int *)(local_c + 4) != 0) {
    FUN_1000c7d0(*(void **)(local_c + 4));
  }
  *(void **)(local_c + 4) = local_3c;
  *(uint *)(local_c + 8) = *(int *)(local_c + 8) + uVar1;
  iVar2 = local_c;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b3b0);
  return CONCAT44(iVar2,local_c);
}



// Function: FUN_1000b3d0 at 1000b3d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_1000b3d0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar1 = (undefined4 *)0xcccccccc;
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 != (undefined4 *)0x0) &&
     (local_c = (undefined4 *)this, puVar1 = FUN_1000b500((undefined4 *)this), puVar1 <= param_1)) {
    puVar1 = FUN_1000b500(local_c);
    puVar1 = (undefined4 *)((int)puVar1 + local_c[4]);
    if (param_1 < puVar1) {
      return CONCAT31((int3)((uint)puVar1 >> 8),1);
    }
  }
  return (uint)puVar1 & 0xffffff00;
}



// Function: FUN_1000b440 at 1000b440

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_1000b440(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar1 = (undefined4 *)0xcccccccc;
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 != (undefined4 *)0x0) &&
     (local_c = (undefined4 *)this, puVar1 = FUN_1000b5e0((undefined4 *)this), puVar1 <= param_1)) {
    puVar1 = FUN_1000b5e0(local_c);
    puVar1 = (undefined4 *)((int)puVar1 + local_c[4] * 2);
    if (param_1 < puVar1) {
      return CONCAT31((int3)((uint)puVar1 >> 8),1);
    }
  }
  return (uint)puVar1 & 0xffffff00;
}



// Function: FUN_1000b4b0 at 1000b4b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000b4b0(int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  ppuVar1 = FUN_1000adc0();
  FUN_10009850(local_c,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_1000b500 at 1000b500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000b500(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_d4 [50];
  undefined4 *local_c;
  
  ppuVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_d4[0] = param_1;
  if (0xf < (uint)param_1[5]) {
    local_c = param_1;
    local_d4[0] = (undefined4 *)FUN_10001b50(*param_1);
  }
  return local_d4[0];
}



// Function: FUN_1000b570 at 1000b570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000b570(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_d4 [50];
  undefined4 *local_c;
  
  ppuVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_d4[0] = param_1;
  if (0xf < (uint)param_1[5]) {
    local_c = param_1;
    local_d4[0] = (undefined4 *)FUN_10001b50(*param_1);
  }
  return local_d4[0];
}



// Function: FUN_1000b5e0 at 1000b5e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000b5e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_d4 [50];
  undefined4 *local_c;
  
  ppuVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_d4[0] = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = param_1;
    local_d4[0] = (undefined4 *)FUN_10001b80(*param_1);
  }
  return local_d4[0];
}



// Function: FUN_1000b650 at 1000b650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000b650(undefined4 *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_d4 [50];
  undefined4 *local_c;
  
  ppuVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  local_d4[0] = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = param_1;
    local_d4[0] = (undefined4 *)FUN_10001b80(*param_1);
  }
  return local_d4[0];
}



// Function: FUN_1000b6c0 at 1000b6c0

void FUN_1000b6c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000b6f0 at 1000b6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __cdecl FUN_1000b6f0(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_c8 [49];
  
  piVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  if (param_1 == 0) {
    local_c8[0] = 0;
  }
  else {
    local_c8[0] = FUN_10006050((int *)&stack0x00000008);
  }
  return local_c8[0];
}



// Function: FUN_1000b750 at 1000b750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000b750(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000b7b0 at 1000b7b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_1000b7b0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  uVar3 = FUN_1000a220(param_1,param_2,param_3);
  return uVar3;
}



// Function: FUN_1000b800 at 1000b800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000b800(void *this,char param_1,size_t param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  undefined4 local_f4;
  undefined1 local_ed [12];
  undefined1 local_e1 [201];
  void *local_18;
  void *local_c;
  
  puVar3 = &local_f4;
  for (iVar2 = 0x3c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = this;
  if ((param_1 != '\0') && (0xf < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    local_18 = *this;
    FUN_1000ae40(local_ed);
    FUN_10002170();
    if (param_2 != 0) {
      sVar4 = param_2;
      pvVar1 = (void *)FUN_10001b50(local_18);
      FUN_1000c650(local_c,pvVar1,sVar4);
    }
    pvVar1 = local_18;
    FUN_1000ae40(local_e1);
    FUN_1000c730(pvVar1);
  }
  *(undefined4 *)((int)local_c + 0x14) = 0xf;
  FUN_1000ab40(local_c,param_2);
  return;
}



// Function: FUN_1000b8d0 at 1000b8d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000b8d0(void *this,char param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_f4;
  undefined1 local_ed [12];
  undefined1 local_e1 [201];
  void *local_18;
  void *local_c;
  
  puVar3 = &local_f4;
  for (iVar2 = 0x3c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = this;
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    local_18 = *this;
    FUN_1000ae90(local_ed);
    FUN_10002230();
    if (param_2 != 0) {
      iVar2 = param_2;
      pvVar1 = (void *)FUN_10001b80(local_18);
      FUN_1000c6c0(local_c,pvVar1,iVar2);
    }
    pvVar1 = local_18;
    FUN_1000ae90(local_e1);
    FUN_1000c780(pvVar1);
  }
  *(undefined4 *)((int)local_c + 0x14) = 7;
  FUN_1000abb0(local_c,param_2);
  return;
}



// Function: FUN_1000b9a0 at 1000b9a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000b9a0(void)

{
  bool bVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 local_10c;
  undefined1 local_105 [12];
  undefined1 local_f9 [12];
  undefined1 local_ed [201];
  int local_24;
  undefined1 local_15 [9];
  void *local_c;
  
  puVar3 = &local_10c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_1000adf0(local_105);
  FUN_100011c0(local_15);
  while (bVar1 = FUN_1000cb30((int)local_c), !bVar1) {
    FUN_1000ea60(local_c);
  }
  local_24 = *(int *)((int)local_c + 8);
  iVar2 = extraout_EDX;
  while (local_24 != 0) {
    local_24 = local_24 + -1;
    iVar2 = *(int *)((int)local_c + 4);
    if (*(int *)(iVar2 + local_24 * 4) != 0) {
      pvVar4 = *(void **)(*(int *)((int)local_c + 4) + local_24 * 4);
      FUN_1000adf0(local_f9);
      FUN_1000c870(pvVar4);
      FUN_1000adf0(local_ed);
      FUN_100022f0();
      iVar2 = extraout_EDX_00;
    }
  }
  if (*(int *)((int)local_c + 4) != 0) {
    FUN_1000c7d0(*(void **)((int)local_c + 4));
    iVar2 = extraout_EDX_01;
  }
  *(undefined4 *)((int)local_c + 8) = 0;
  *(undefined4 *)((int)local_c + 4) = 0;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000bac0);
  return CONCAT44(iVar2,local_c);
}



// Function: FUN_1000bae0 at 1000bae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bae0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1000bb30 at 1000bb30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bb30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1000bb80 at 1000bb80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bb80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::_Xlength_error("deque<T> too long");
  return;
}



// Function: FUN_1000bbd0 at 1000bbd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bbd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1000bc20 at 1000bc20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bc20(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1000bc70 at 1000bc70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bc70(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000be00(param_1);
  return;
}



// Function: FUN_1000bcc0 at 1000bcc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bcc0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000be50(param_1);
  return;
}



// Function: FUN_1000bd10 at 1000bd10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bd10(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000bea0(param_1);
  return;
}



// Function: FUN_1000bd60 at 1000bd60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bd60(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000bef0(param_1);
  return;
}



// Function: FUN_1000bdb0 at 1000bdb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bdb0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000bf40(param_1);
  return;
}



// Function: FUN_1000be00 at 1000be00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000be00(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100015a0(param_1);
  return;
}



// Function: FUN_1000be50 at 1000be50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000be50(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10001610(param_1);
  return;
}



// Function: FUN_1000bea0 at 1000bea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bea0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10001690(param_1);
  return;
}



// Function: FUN_1000bef0 at 1000bef0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bef0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10001710(param_1);
  return;
}



// Function: FUN_1000bf40 at 1000bf40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bf40(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10001790(param_1);
  return;
}



// Function: FUN_1000bf90 at 1000bf90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * FUN_1000bf90(undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 local_dc [49];
  uint local_18;
  undefined4 *local_c;
  
  puVar3 = local_dc;
  for (iVar5 = 0x36; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = FUN_1000f590((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000bbd0();
  }
  iVar5 = FUN_1000f590((int)param_1);
  local_18 = iVar5 - param_2;
  if (param_3 < local_18) {
    local_18 = param_3;
  }
  if (local_c == param_1) {
    FUN_1000cd10(local_c,param_2 + local_18);
    FUN_1000cd70(local_c,0,param_2);
  }
  else {
    bVar1 = FUN_1000af80(local_18,'\0');
    if (bVar1) {
      uVar2 = local_18;
      puVar3 = FUN_1000b570(param_1);
      pvVar4 = (void *)((int)puVar3 + param_2);
      puVar3 = FUN_1000b500(local_c);
      FUN_1000c650(puVar3,pvVar4,uVar2);
      FUN_1000ab40(local_c,local_18);
    }
  }
  return local_c;
}



// Function: FUN_1000c070 at 1000c070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c070(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_1000e180(param_1);
  FUN_1000c0d0(local_c,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_1000c0d0 at 1000c0d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000c0d0(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar3 = local_d0;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (undefined4 *)this;
  uVar2 = FUN_1000b3d0(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_1000af80(param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_1000b500(local_c);
      FUN_1000c650(puVar3,param_1,uVar2);
      FUN_1000ab40(local_c,param_2);
    }
  }
  else {
    puVar3 = FUN_1000b500(local_c);
    local_c = FUN_1000bf90(local_c,(int)param_1 - (int)puVar3,param_2);
  }
  return local_c;
}



// Function: FUN_1000c180 at 1000c180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c180(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000c1d0(param_1,0,0xffffffff);
  return;
}



// Function: FUN_1000c1d0 at 1000c1d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * FUN_1000c1d0(undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_dc [49];
  uint local_18;
  undefined4 *local_c;
  
  puVar3 = local_dc;
  for (iVar4 = 0x36; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = FUN_1000f5c0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000bc20();
  }
  iVar4 = FUN_1000f5c0((int)param_1);
  local_18 = iVar4 - param_2;
  if (param_3 < local_18) {
    local_18 = param_3;
  }
  if (local_c == param_1) {
    FUN_1000ce30(local_c,param_2 + local_18);
    FUN_1000ce90(local_c,0,param_2);
  }
  else {
    bVar1 = FUN_1000b070(local_18,'\0');
    if (bVar1) {
      uVar2 = local_18;
      puVar3 = FUN_1000b650(param_1);
      pvVar5 = (void *)((int)puVar3 + param_2 * 2);
      puVar3 = FUN_1000b5e0(local_c);
      FUN_1000c6c0(puVar3,pvVar5,uVar2);
      FUN_1000abb0(local_c,local_18);
    }
  }
  return local_c;
}



// Function: FUN_1000c2b0 at 1000c2b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c2b0(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_1000e1e0(param_1);
  FUN_1000c310(local_c,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_1000c310 at 1000c310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000c310(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar3 = local_d0;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (undefined4 *)this;
  uVar2 = FUN_1000b440(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_1000b070(param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_1000b5e0(local_c);
      FUN_1000c6c0(puVar3,param_1,uVar2);
      FUN_1000abb0(local_c,param_2);
    }
  }
  else {
    puVar3 = FUN_1000b5e0(local_c);
    local_c = FUN_1000c1d0(local_c,(int)param_1 - (int)puVar3 >> 1,param_2);
  }
  return local_c;
}



// Function: FUN_1000c3c0 at 1000c3c0

void __cdecl FUN_1000c3c0(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = *param_2;
  return;
}



// Function: FUN_1000c3f0 at 1000c3f0

void __cdecl FUN_1000c3f0(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = *param_2;
  return;
}



// Function: FUN_1000c430 at 1000c430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000c430(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar1 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = this;
  puVar1 = FUN_1000b5e0((undefined4 *)this);
  FUN_10003710(puVar1);
  return param_1;
}



// Function: FUN_1000c490 at 1000c490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000c490(void *this,void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e8 [52];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100267cf;
  local_10 = ExceptionList;
  puVar2 = local_e8;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e8[1] = 0;
  local_18 = this;
  FUN_100034e0(param_1,*(undefined4 *)((int)this + 0xc),(undefined4 *)this);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c530 at 1000c530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000c530(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000b650(param_1);
  return;
}



// Function: FUN_1000c570 at 1000c570

undefined4 __fastcall FUN_1000c570(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000c5a0 at 1000c5a0

undefined4 __fastcall FUN_1000c5a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000c5d0 at 1000c5d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c5d0(undefined4 param_1,int *param_2)

{
  int iVar1;
  void **ppvVar2;
  void *local_e0 [55];
  
  ppvVar2 = local_e0;
  for (iVar1 = 0x37; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_e0[2] = (void *)FUN_10005430(4,param_1);
  if (local_e0[2] != (void *)0x0) {
    FUN_10003120(local_e0[2],param_2);
  }
  return;
}



// Function: FUN_1000c650 at 1000c650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000c650(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void **ppvVar2;
  void *local_c8 [49];
  
  ppvVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  if (param_3 == 0) {
    local_c8[0] = param_1;
  }
  else {
    local_c8[0] = memcpy(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_1000c6c0 at 1000c6c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000c6c0(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  void **ppvVar2;
  void *local_c8 [49];
  
  ppvVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  if (param_3 == 0) {
    local_c8[0] = param_1;
  }
  else {
    local_c8[0] = (void *)FUN_1000f8b0(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_1000c730 at 1000c730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c730(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000c8c0(param_1);
  return;
}



// Function: FUN_1000c780 at 1000c780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c780(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000c910(param_1);
  return;
}



// Function: FUN_1000c7d0 at 1000c7d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c7d0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000c960(param_1);
  return;
}



// Function: FUN_1000c820 at 1000c820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c820(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000c9b0(param_1);
  return;
}



// Function: FUN_1000c870 at 1000c870

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c870(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000ca00(param_1);
  return;
}



// Function: FUN_1000c8c0 at 1000c8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c8c0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_delete(param_1);
  return;
}



// Function: FUN_1000c910 at 1000c910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c910(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_delete(param_1);
  return;
}



// Function: FUN_1000c960 at 1000c960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c960(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_delete(param_1);
  return;
}



// Function: FUN_1000c9b0 at 1000c9b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c9b0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_delete(param_1);
  return;
}



// Function: FUN_1000ca00 at 1000ca00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000ca00(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  operator_delete(param_1);
  return;
}



// Function: FUN_1000ca50 at 1000ca50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_1000ca50(void *param_1,int param_2)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_d0 [51];
  
  puVar4 = local_d0;
  for (iVar3 = 0x33; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  pcVar1 = std::_Syserror_map(param_2);
  if (pcVar1 == (char *)0x0) {
    puVar2 = FUN_1000f6a0();
    FUN_10004310(param_1,param_2,puVar2);
  }
  else {
    puVar2 = FUN_1000d1e0();
    FUN_10004310(param_1,param_2,puVar2);
  }
  return param_1;
}



// Function: FUN_1000cae0 at 1000cae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000cae0(void *this,void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_10004310(param_1,param_2,this);
  return param_1;
}



// Function: FUN_1000cb30 at 1000cb30

bool __fastcall FUN_1000cb30(int param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  return *(int *)(param_1 + 0x10) == 0;
}



// Function: FUN_1000cb80 at 1000cb80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000cb80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000cb30(param_1);
  return;
}



// Function: FUN_1000cbc0 at 1000cbc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000cbc0(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar1 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = this;
  puVar1 = FUN_1000b5e0((undefined4 *)this);
  FUN_10003710((int)puVar1 + *(int *)((int)local_c + 0x10) * 2);
  return param_1;
}



// Function: FUN_1000cc20 at 1000cc20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 FUN_1000cc20(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d4 [50];
  void *local_c;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_1000c570((int)param_1);
  bVar1 = FUN_10005a40(local_c,iVar2);
  if ((bVar1) && (iVar2 = FUN_1000f6d0(param_1), iVar2 == param_2)) {
    return 1;
  }
  return 0;
}



// Function: FUN_1000cca0 at 1000cca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000cca0(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e0;
  undefined1 local_dc [208];
  void *local_c;
  
  puVar2 = &local_e0;
  for (iVar1 = 0x37; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = this;
  (**(code **)(*this + 0xc))(local_dc,param_1,param_2);
  FUN_10005a90((undefined4 *)0x1000cce8);
  return;
}



// Function: FUN_1000cd10 at 1000cd10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000cd10(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000bbd0();
  }
  FUN_1000ab40(local_c,param_1);
  return local_c;
}



// Function: FUN_1000cd70 at 1000cd70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000cd70(void *this,uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_e8 [49];
  int local_24;
  void *local_18;
  undefined4 *local_c;
  
  puVar1 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = (undefined4 *)this;
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000bbd0();
  }
  if (param_2 < local_c[4] - param_1) {
    if (param_2 != 0) {
      puVar1 = FUN_1000b500(local_c);
      local_18 = (void *)((int)puVar1 + param_1);
      local_24 = local_c[4] - param_2;
      FUN_1000e850(local_18,(void *)((int)local_18 + param_2),local_24 - param_1);
      FUN_1000ab40(local_c,local_24);
    }
  }
  else {
    FUN_1000ab40(local_c,param_1);
  }
  return local_c;
}



// Function: FUN_1000ce30 at 1000ce30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000ce30(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000bc20();
  }
  FUN_1000abb0(local_c,param_1);
  return local_c;
}



// Function: FUN_1000ce90 at 1000ce90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000ce90(void *this,uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_e8 [49];
  int local_24;
  void *local_18;
  undefined4 *local_c;
  
  puVar1 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = (undefined4 *)this;
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000bc20();
  }
  if (param_2 < local_c[4] - param_1) {
    if (param_2 != 0) {
      puVar1 = FUN_1000b5e0(local_c);
      local_18 = (void *)((int)puVar1 + param_1 * 2);
      local_24 = local_c[4] - param_2;
      FUN_1000e8c0(local_18,(void *)((int)local_18 + param_2 * 2),local_24 - param_1);
      FUN_1000abb0(local_c,local_24);
    }
  }
  else {
    FUN_1000abb0(local_c,param_1);
  }
  return local_c;
}



// Function: FUN_1000cf50 at 1000cf50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

short * __cdecl FUN_1000cf50(short *param_1,int param_2,short *param_3)

{
  int iVar1;
  short **ppsVar2;
  short *local_c8 [49];
  
  ppsVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppsVar2 = (short *)0xcccccccc;
    ppsVar2 = ppsVar2 + 1;
  }
  if (param_2 == 0) {
    local_c8[0] = (short *)0x0;
  }
  else {
    local_c8[0] = FUN_1000f850(param_1,*param_3,param_2);
  }
  return local_c8[0];
}



// Function: FUN_1000cfc0 at 1000cfc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000cfc0(wchar_t *param_1,uint param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_1000e1e0(param_1);
  FUN_1000d020(local_c,param_1,param_2,sVar1);
  return;
}



// Function: FUN_1000d020 at 1000d020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000d020(void *this,short *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  short *psVar2;
  int iVar3;
  undefined4 local_e8 [49];
  short *local_24;
  short *local_18;
  undefined4 *local_c;
  
  puVar1 = local_e8;
  for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  if ((param_3 != 0) && (param_2 < *(uint *)((int)this + 0x10))) {
    local_c = (undefined4 *)this;
    puVar1 = FUN_1000b650((undefined4 *)this);
    local_18 = (short *)((int)puVar1 + local_c[4] * 2);
    puVar1 = FUN_1000b650(local_c);
    for (local_24 = (short *)((int)puVar1 + param_2 * 2); local_24 < local_18;
        local_24 = local_24 + 1) {
      psVar2 = FUN_1000cf50(param_1,param_3,local_24);
      if (psVar2 != (short *)0x0) {
        puVar1 = FUN_1000b650(local_c);
        return (int)local_24 - (int)puVar1 >> 1;
      }
    }
  }
  return -1;
}



// Function: FUN_1000d0e0 at 1000d0e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000d0e0(void *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_104 [6];
  undefined1 local_ec [212];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100267fb;
  local_10 = ExceptionList;
  ppiVar2 = local_104;
  for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  local_104[0] = (int *)FUN_1000c490(param_1,local_ec);
  local_8 = 0;
  local_104[1] = local_104[0];
  local_104[3] = (int *)FUN_10005fa0(local_104[0]);
  local_8 = 0xffffffff;
  FUN_10004e80();
  ExceptionList = local_10;
  return local_104[3];
}



// Function: FUN_1000d1a0 at 1000d1a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d1a0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000d0e0(param_1);
  return;
}



// Function: FUN_1000d1e0 at 1000d1e0

undefined * FUN_1000d1e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_100338b0;
}



// Function: FUN_1000d210 at 1000d210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000d210(wchar_t *param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  undefined4 *puVar5;
  wchar_t *_Str2;
  int *piVar6;
  int iVar7;
  int **ppiVar8;
  undefined8 uVar9;
  _GUID *p_Var10;
  int *local_180 [50];
  long local_b8;
  long local_ac;
  int local_a0 [3];
  int local_94 [3];
  long local_88;
  undefined4 local_7c [3];
  int local_70 [3];
  long local_64;
  int local_58 [3];
  long local_4c;
  int local_40 [3];
  undefined1 local_34 [36];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002685e;
  local_10 = ExceptionList;
  ppiVar8 = local_180;
  for (iVar7 = 0x5c; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppiVar8 = (int *)0xcccccccc;
    ppiVar8 = ppiVar8 + 1;
  }
  ExceptionList = &local_10;
  FUN_10003c70();
  local_8 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  FUN_10003230(local_40);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_180[0] = (int *)FUN_10005ec0(param_2);
  uVar3 = FUN_10006110(local_40);
  local_4c = (**(code **)(*local_180[0] + 0x34))(local_180[0],uVar3);
  if (local_4c < 0) {
    p_Var10 = (_GUID *)&DAT_1002a34c;
    pIVar4 = (IUnknown *)FUN_10005cd0(param_2);
    _com_issue_errorex(local_4c,pIVar4,p_Var10);
  }
  do {
    bVar1 = FUN_10005b20(local_40,0);
    if (!bVar1) {
LAB_1000d5cd:
      while( true ) {
        cVar2 = FUN_1000cb80((int)local_34);
        if (cVar2 != '\0') break;
        FUN_1000ea20(local_34);
      }
      local_8 = local_8 & 0xffffff00;
      FUN_10004c80(local_40);
      local_8 = 0xffffffff;
      uVar9 = FUN_100050b0();
      _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000d634);
      ExceptionList = local_10;
      return uVar9;
    }
    FUN_10003330(local_58);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_180[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006140(local_58);
    local_64 = (**(code **)(*local_180[0] + 0x4c))(local_180[0],uVar3);
    if (local_64 < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_64,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005b90(local_58,0);
    if (bVar1) {
      puVar5 = (undefined4 *)FUN_10005d00(local_58);
      FUN_10002ff0(local_70,puVar5);
      local_8._0_1_ = 3;
      FUN_10003d30(local_7c);
      local_8 = CONCAT31(local_8._1_3_,4);
      local_180[0] = (int *)FUN_10005e60(local_70);
      uVar3 = FUN_10006200(local_7c);
      local_88 = (**(code **)(*local_180[0] + 0x1c))(local_180[0],uVar3);
      if (local_88 < 0) {
        p_Var10 = (_GUID *)&DAT_1002a324;
        pIVar4 = (IUnknown *)FUN_10005c70(local_70);
        _com_issue_errorex(local_88,pIVar4,p_Var10);
      }
      _Str2 = (wchar_t *)FUN_10005dc0(local_7c);
      iVar7 = _wcsicmp(param_1,_Str2);
      if (iVar7 == 0) {
        if (param_3 != (undefined4 *)0x0) {
          uVar3 = FUN_10007660(local_40);
          *param_3 = uVar3;
        }
        local_8._0_1_ = 3;
        FUN_10001000(local_7c);
        local_8._0_1_ = 2;
        FUN_10004b80(local_70);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10004d00(local_58);
        goto LAB_1000d5cd;
      }
      local_8._0_1_ = 3;
      FUN_10001000(local_7c);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10004b80(local_70);
    }
    FUN_10003230(local_94);
    local_8._0_1_ = 5;
    FUN_10003230(local_a0);
    local_8 = CONCAT31(local_8._1_3_,6);
    local_180[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006110(local_94);
    local_ac = (**(code **)(*local_180[0] + 0x34))(local_180[0],uVar3);
    if (local_ac < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_ac,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005b20(local_94,0);
    if (bVar1) {
      FUN_1000ec00(local_34,local_94);
    }
    local_180[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006110(local_a0);
    local_b8 = (**(code **)(*local_180[0] + 0x24))(local_180[0],uVar3);
    if (local_b8 < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_b8,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005840(local_a0,0);
    if (bVar1) {
      cVar2 = FUN_1000cb80((int)local_34);
      if (cVar2 == '\0') {
        piVar6 = (int *)FUN_1000d1a0(local_34);
        FUN_100054d0(piVar6);
        FUN_1000ea20(local_34);
      }
    }
    FUN_100054d0(local_a0);
    local_8._0_1_ = 5;
    FUN_10004c80(local_a0);
    local_8._0_1_ = 2;
    FUN_10004c80(local_94);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10004d00(local_58);
  } while( true );
}



// Function: FUN_1000d6e0 at 1000d6e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000d6e0(int param_1,int *param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int **ppiVar8;
  undefined8 uVar9;
  _GUID *p_Var10;
  int *local_174 [50];
  long local_ac;
  long local_a0;
  int local_94 [3];
  int local_88 [3];
  long local_7c;
  int local_70 [3];
  int local_64 [3];
  long local_58;
  int local_4c [3];
  int local_40 [3];
  undefined1 local_34 [36];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100268b6;
  local_10 = ExceptionList;
  ppiVar8 = local_174;
  for (iVar7 = 0x59; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppiVar8 = (int *)0xcccccccc;
    ppiVar8 = ppiVar8 + 1;
  }
  ExceptionList = &local_10;
  FUN_10003c70();
  local_8 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  FUN_10003230(local_40);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100054d0(param_2);
  do {
    bVar1 = FUN_10005b20(local_40,0);
    if (!bVar1) {
LAB_1000da04:
      while( true ) {
        cVar2 = FUN_1000cb80((int)local_34);
        if (cVar2 != '\0') break;
        FUN_1000ea20(local_34);
      }
      local_8 = local_8 & 0xffffff00;
      FUN_10004c80(local_40);
      local_8 = 0xffffffff;
      uVar9 = FUN_100050b0();
      _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000da6c);
      ExceptionList = local_10;
      return uVar9;
    }
    FUN_10003330(local_4c);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_174[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006140(local_4c);
    local_58 = (**(code **)(*local_174[0] + 0x4c))(local_174[0],uVar3);
    if (local_58 < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_58,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005b90(local_4c,0);
    if (bVar1) {
      puVar5 = (undefined4 *)FUN_10005d00(local_4c);
      FUN_10002ff0(local_64,puVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_174[0] = (int *)FUN_10005e60(local_64);
      local_7c = (**(code **)(*local_174[0] + 0xec))(local_174[0],local_70);
      if (local_7c < 0) {
        p_Var10 = (_GUID *)&DAT_1002a324;
        pIVar4 = (IUnknown *)FUN_10005c70(local_64);
        _com_issue_errorex(local_7c,pIVar4,p_Var10);
      }
      if (local_70[0] == param_1) {
        FUN_10006f00(local_40,param_3);
        local_8._0_1_ = 2;
        FUN_10004b80(local_64);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10004d00(local_4c);
        goto LAB_1000da04;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10004b80(local_64);
    }
    FUN_10003230(local_88);
    local_8._0_1_ = 4;
    FUN_10003230(local_94);
    local_8 = CONCAT31(local_8._1_3_,5);
    local_174[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006110(local_88);
    local_a0 = (**(code **)(*local_174[0] + 0x34))(local_174[0],uVar3);
    if (local_a0 < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_a0,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005b20(local_88,0);
    if (bVar1) {
      FUN_1000ec00(local_34,local_88);
    }
    local_174[0] = (int *)FUN_10005ec0(local_40);
    uVar3 = FUN_10006110(local_94);
    local_ac = (**(code **)(*local_174[0] + 0x24))(local_174[0],uVar3);
    if (local_ac < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_40);
      _com_issue_errorex(local_ac,pIVar4,p_Var10);
    }
    bVar1 = FUN_10005840(local_94,0);
    if (bVar1) {
      cVar2 = FUN_1000cb80((int)local_34);
      if (cVar2 == '\0') {
        piVar6 = (int *)FUN_1000d1a0(local_34);
        FUN_100054d0(piVar6);
        FUN_1000ea20(local_34);
      }
    }
    FUN_100054d0(local_94);
    local_8._0_1_ = 4;
    FUN_10004c80(local_94);
    local_8._0_1_ = 2;
    FUN_10004c80(local_88);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10004d00(local_4c);
  } while( true );
}



// Function: FUN_1000db10 at 1000db10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000db10(uint param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  IUnknown *pIVar5;
  undefined4 *puVar6;
  int iVar7;
  int **ppiVar8;
  undefined8 uVar9;
  _GUID *p_Var10;
  int *local_1ec [3];
  int local_1e0 [3];
  int local_1d4 [51];
  long local_108;
  int local_fc [3];
  long local_f0;
  long local_e4;
  undefined4 local_d8 [3];
  long local_cc;
  uint local_c0 [3];
  int local_b4 [3];
  long local_a8;
  int local_9c [3];
  long local_90;
  int local_84 [3];
  int local_78 [3];
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_54;
  int local_48;
  int local_3c;
  int local_30;
  uint local_24;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026932;
  local_10 = ExceptionList;
  ppiVar8 = local_1ec;
  for (iVar7 = 0x77; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppiVar8 = (int *)0xcccccccc;
    ppiVar8 = ppiVar8 + 1;
  }
  uVar2 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = param_1 & 0xf0000000;
  local_30 = 0;
  local_3c = 0;
  local_48 = 0;
  local_54 = 0x20000000;
  local_60 = 0x30000000;
  local_6c = 0x40000000;
  if (local_24 == 0x20000000) {
    local_30 = 1;
  }
  else if (local_24 == 0x30000000) {
    local_3c = 1;
  }
  else if (local_24 == 0x40000000) {
    local_48 = 1;
  }
  FUN_10003230(local_78);
  local_8 = 0;
  if (local_3c == 0) {
    uVar3 = FUN_10006110(local_78);
    local_1ec[0] = FUN_10004080("ConfigFile");
    local_8._0_1_ = 2;
    local_1ec[1] = local_1ec[0];
    uVar4 = FUN_10005df0(local_1ec[0]);
    (**(code **)(*(int *)(local_18 + 4) + 0x1c))(local_18 + 4,uVar4,uVar3,uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10005320(local_1d4);
  }
  else {
    uVar3 = FUN_10006110(local_78);
    local_1ec[0] = FUN_10004080("ConfigGroups");
    local_8._0_1_ = 1;
    local_1ec[1] = local_1ec[0];
    uVar4 = FUN_10005df0(local_1ec[0]);
    (**(code **)(*(int *)(local_18 + 4) + 0x1c))(local_18 + 4,uVar4,uVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10005320(local_1e0);
  }
  bVar1 = FUN_10005b20(local_78,0);
  if (bVar1) {
    FUN_10003230(local_84);
    local_8 = CONCAT31(local_8._1_3_,3);
    local_1ec[1] = (int *)FUN_10005ec0(local_78);
    uVar3 = FUN_10006110(local_84);
    local_90 = (**(code **)(*local_1ec[1] + 0x34))(local_1ec[1],uVar3);
    if (local_90 < 0) {
      p_Var10 = (_GUID *)&DAT_1002a34c;
      pIVar5 = (IUnknown *)FUN_10005cd0(local_78);
      _com_issue_errorex(local_90,pIVar5,p_Var10);
    }
    while( true ) {
      bVar1 = FUN_10005b20(local_84,0);
      if (!bVar1) break;
      if ((local_30 != 0) || (local_48 != 0)) {
        FUN_1000d6e0(param_1,local_84,param_2);
        break;
      }
      FUN_10003330(local_9c);
      local_8 = CONCAT31(local_8._1_3_,4);
      local_1ec[1] = (int *)FUN_10005ec0(local_84);
      uVar3 = FUN_10006140(local_9c);
      local_a8 = (**(code **)(*local_1ec[1] + 0x4c))(local_1ec[1],uVar3);
      if (local_a8 < 0) {
        p_Var10 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0(local_84);
        _com_issue_errorex(local_a8,pIVar5,p_Var10);
      }
      bVar1 = FUN_10005b90(local_9c,0);
      if (bVar1) {
        puVar6 = (undefined4 *)FUN_10005d00(local_9c);
        FUN_10002ff0(local_b4,puVar6);
        local_8 = CONCAT31(local_8._1_3_,5);
        local_1ec[1] = (int *)FUN_10005e60(local_b4);
        local_cc = (**(code **)(*local_1ec[1] + 0xec))(local_1ec[1],local_c0);
        uVar3 = 0x1000de30;
        if (local_cc < 0) {
          p_Var10 = (_GUID *)&DAT_1002a324;
          pIVar5 = (IUnknown *)FUN_10005c70(local_b4);
          _com_issue_errorex(local_cc,pIVar5,p_Var10);
        }
        FUN_10003d30(local_d8);
        local_8 = CONCAT31(local_8._1_3_,6);
        local_1ec[1] = (int *)FUN_10005e60(local_b4);
        uVar4 = FUN_10006200(local_d8);
        local_e4 = (**(code **)(*local_1ec[1] + 0x1c))(local_1ec[1],uVar4,uVar3);
        if (local_e4 < 0) {
          p_Var10 = (_GUID *)&DAT_1002a324;
          pIVar5 = (IUnknown *)FUN_10005c70(local_b4);
          _com_issue_errorex(local_e4,pIVar5,p_Var10);
        }
        if (local_c0[0] == param_1) {
          local_f0 = FUN_10006f00(local_84,param_2);
          if (local_f0 < 0) {
            p_Var10 = (_GUID *)&DAT_1002a34c;
            pIVar5 = (IUnknown *)FUN_10005cd0(local_84);
            _com_issue_errorex(local_f0,pIVar5,p_Var10);
          }
          local_8._0_1_ = 5;
          FUN_10001000(local_d8);
          local_8._0_1_ = 4;
          FUN_10004b80(local_b4);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_10004d00(local_9c);
          break;
        }
        local_8._0_1_ = 5;
        FUN_10001000(local_d8);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_10004b80(local_b4);
      }
      local_8._0_1_ = 3;
      FUN_10004d00(local_9c);
      FUN_10003230(local_fc);
      local_8 = CONCAT31(local_8._1_3_,7);
      local_1ec[1] = (int *)FUN_10005ec0(local_84);
      uVar3 = FUN_10006110(local_fc);
      local_108 = (**(code **)(*local_1ec[1] + 0x24))(local_1ec[1],uVar3);
      if (local_108 < 0) {
        p_Var10 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0(local_84);
        _com_issue_errorex(local_108,pIVar5,p_Var10);
      }
      FUN_100054d0(local_fc);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_10004c80(local_fc);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10004c80(local_84);
  }
  local_8 = 0xffffffff;
  uVar9 = FUN_10004c80(local_78);
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000e050);
  ExceptionList = local_10;
  return uVar9;
}



// Function: FUN_1000e0f0 at 1000e0f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e0f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [209];
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000ae90(local_d5);
  FUN_10003970(param_1);
  return param_1;
}



// Function: FUN_1000e150 at 1000e150

undefined4 __fastcall FUN_1000e150(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000e180 at 1000e180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_1000e180(char *param_1)

{
  int iVar1;
  size_t *psVar2;
  size_t local_c8 [49];
  
  psVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *psVar2 = 0xcccccccc;
    psVar2 = psVar2 + 1;
  }
  if (*param_1 == '\0') {
    local_c8[0] = 0;
  }
  else {
    local_c8[0] = strlen(param_1);
  }
  return local_c8[0];
}



// Function: FUN_1000e1e0 at 1000e1e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_1000e1e0(wchar_t *param_1)

{
  int iVar1;
  size_t *psVar2;
  size_t local_c8 [49];
  
  psVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *psVar2 = 0xcccccccc;
    psVar2 = psVar2 + 1;
  }
  if (*param_1 == L'\0') {
    local_c8[0] = 0;
  }
  else {
    local_c8[0] = wcslen(param_1);
  }
  return local_c8[0];
}



// Function: FUN_1000e250 at 1000e250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e250(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e3d0();
  return;
}



// Function: FUN_1000e2a0 at 1000e2a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e2a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e410();
  return;
}



// Function: FUN_1000e2f0 at 1000e2f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e2f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e450();
  return;
}



// Function: FUN_1000e340 at 1000e340

undefined4 FUN_1000e340(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



// Function: FUN_1000e370 at 1000e370

undefined4 FUN_1000e370(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x7fffffff;
}



// Function: FUN_1000e3a0 at 1000e3a0

undefined4 FUN_1000e3a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x3fffffff;
}



// Function: FUN_1000e3d0 at 1000e3d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e3d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e340();
  return;
}



// Function: FUN_1000e410 at 1000e410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e370();
  return;
}



// Function: FUN_1000e450 at 1000e450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e450(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000e3a0();
  return;
}



// Function: FUN_1000e490 at 1000e490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000e490(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_ec [2];
  undefined1 local_e1 [221];
  
  piVar3 = local_ec;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  FUN_1000ae40(local_e1);
  uVar1 = FUN_1000e250();
  if (uVar1 < 2) {
    local_ec[0] = 1;
  }
  else {
    local_ec[0] = uVar1 - 1;
  }
  return local_ec[0];
}



// Function: FUN_1000e510 at 1000e510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000e510(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_ec [2];
  undefined1 local_e1 [221];
  
  piVar3 = local_ec;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  FUN_1000ae90(local_e1);
  uVar1 = FUN_1000e2a0();
  if (uVar1 < 2) {
    local_ec[0] = 1;
  }
  else {
    local_ec[0] = uVar1 - 1;
  }
  return local_ec[0];
}



// Function: FUN_1000e590 at 1000e590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e590(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc;
  undefined1 local_d5 [209];
  
  puVar2 = &local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000adf0(local_d5);
  FUN_1000e2f0();
  return;
}



// Function: FUN_1000e5e0 at 1000e5e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e5e0(undefined4 param_1,int param_2)

{
  int iVar1;
  char **ppcVar2;
  char *local_f8 [53];
  char *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002696f;
  local_10 = ExceptionList;
  ppcVar2 = local_f8;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar2 = (char *)0xcccccccc;
    ppcVar2 = ppcVar2 + 1;
  }
  ExceptionList = &local_10;
  local_f8[2] = (char *)0x0;
  local_24 = std::_Syserror_map(param_2);
  local_f8[0] = local_24;
  if (local_24 == (char *)0x0) {
    local_f8[0] = "unknown error";
  }
  FUN_10003a30(local_f8[0]);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e6b0 at 1000e6b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e6b0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e8 [54];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100269af;
  local_10 = ExceptionList;
  puVar2 = local_e8;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e8[1] = 0;
  if (param_2 == 1) {
    FUN_10003a30("iostream stream error");
  }
  else {
    FUN_1000e5e0(param_1,param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e780 at 1000e780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000e780(undefined4 param_1,int param_2)

{
  int iVar1;
  char **ppcVar2;
  char *local_f8 [53];
  char *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100269ef;
  local_10 = ExceptionList;
  ppcVar2 = local_f8;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar2 = (char *)0xcccccccc;
    ppcVar2 = ppcVar2 + 1;
  }
  ExceptionList = &local_10;
  local_f8[2] = (char *)0x0;
  local_24 = std::_Winerror_map(param_2);
  local_f8[0] = local_24;
  if (local_24 == (char *)0x0) {
    local_f8[0] = "unknown error";
  }
  FUN_10003a30(local_f8[0]);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e850 at 1000e850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000e850(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void **ppvVar2;
  void *local_c8 [49];
  
  ppvVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  if (param_3 == 0) {
    local_c8[0] = param_1;
  }
  else {
    local_c8[0] = memmove(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_1000e8c0 at 1000e8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000e8c0(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  void **ppvVar2;
  void *local_c8 [49];
  
  ppvVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  if (param_3 == 0) {
    local_c8[0] = param_1;
  }
  else {
    local_c8[0] = (void *)FUN_1000f900(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_1000e930 at 1000e930

char * FUN_1000e930(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return "generic";
}



// Function: FUN_1000e960 at 1000e960

char * FUN_1000e960(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return "iostream";
}



// Function: FUN_1000e990 at 1000e990

char * FUN_1000e990(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return "system";
}



// Function: FUN_1000e9c0 at 1000e9c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_1000e9c0(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcslen(param_1);
  }
  return sVar1;
}



// Function: FUN_1000ea20 at 1000ea20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000ea20(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000eb30(param_1);
  return;
}



// Function: FUN_1000ea60 at 1000ea60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000ea60(void *param_1)

{
  bool bVar1;
  void *this;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 local_f8 [2];
  undefined1 local_ed [201];
  uint local_24;
  uint local_18;
  void *local_c;
  
  puVar3 = local_f8;
  for (iVar2 = 0x3d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = param_1;
  bVar1 = FUN_1000cb30((int)param_1);
  if (!bVar1) {
    local_18 = *(int *)((int)local_c + 0xc) + -1 + *(int *)((int)local_c + 0x10);
    local_24 = FUN_1000aee0(local_c,local_18);
    pvVar4 = (void *)(*(int *)(*(int *)((int)local_c + 4) + local_24 * 4) + (local_18 % 4) * 4);
    this = (void *)FUN_1000adf0(local_ed);
    FUN_10002470(this,pvVar4);
    iVar2 = *(int *)((int)local_c + 0x10) + -1;
    *(int *)((int)local_c + 0x10) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)((int)local_c + 0xc) = 0;
    }
  }
  return;
}



// Function: FUN_1000eb30 at 1000eb30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000eb30(void *param_1)

{
  bool bVar1;
  void *this;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 local_ec [2];
  undefined1 local_e1 [201];
  uint local_18;
  void *local_c;
  
  puVar3 = local_ec;
  for (iVar2 = 0x3a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = param_1;
  bVar1 = FUN_1000cb30((int)param_1);
  if (!bVar1) {
    local_18 = FUN_1000aee0(local_c,*(uint *)((int)local_c + 0xc));
    pvVar4 = (void *)(*(int *)(*(int *)((int)local_c + 4) + local_18 * 4) +
                     (*(uint *)((int)local_c + 0xc) % 4) * 4);
    this = (void *)FUN_1000adf0(local_e1);
    FUN_10002470(this,pvVar4);
    iVar2 = *(int *)((int)local_c + 0x10) + -1;
    *(int *)((int)local_c + 0x10) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)((int)local_c + 0xc) = 0;
    }
    else {
      *(int *)((int)local_c + 0xc) = *(int *)((int)local_c + 0xc) + 1;
    }
  }
  return;
}



// Function: FUN_1000ec00 at 1000ec00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000ec00(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_1000ec50(this,param_1);
  return;
}



// Function: FUN_1000ec50 at 1000ec50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000ec50(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_100;
  undefined1 local_f9 [12];
  undefined1 local_ed [201];
  uint local_24;
  uint local_18;
  void *local_c;
  
  puVar3 = &local_100;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = this;
  std::_Container_base12::_Orphan_all((_Container_base12 *)this);
  if (((uint)(*(int *)((int)local_c + 0xc) + *(int *)((int)local_c + 0x10)) % 4 == 0) &&
     (*(uint *)((int)local_c + 8) <= *(int *)((int)local_c + 0x10) + 4U >> 2)) {
    FUN_1000b160(1);
  }
  *(uint *)((int)local_c + 0xc) =
       *(int *)((int)local_c + 8) * 4 - 1U & *(uint *)((int)local_c + 0xc);
  local_18 = *(int *)((int)local_c + 0xc) + *(int *)((int)local_c + 0x10);
  local_24 = FUN_1000aee0(local_c,local_18);
  if (*(int *)(*(int *)((int)local_c + 4) + local_24 * 4) == 0) {
    uVar4 = 4;
    FUN_1000adf0(local_f9);
    uVar1 = FUN_1000bdb0(uVar4);
    *(undefined4 *)(*(int *)((int)local_c + 4) + local_24 * 4) = uVar1;
  }
  iVar2 = *(int *)(*(int *)((int)local_c + 4) + local_24 * 4) + (local_18 % 4) * 4;
  FUN_1000adf0(local_ed);
  FUN_100020c0(iVar2,param_1);
  *(int *)((int)local_c + 0x10) = *(int *)((int)local_c + 0x10) + 1;
  return;
}



// Function: FUN_1000ed90 at 1000ed90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000ed90(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  int iVar5;
  undefined4 extraout_EDX;
  int **ppiVar6;
  undefined8 uVar7;
  _GUID *p_Var8;
  int *local_11c [50];
  long local_54;
  long local_48;
  int local_3c [3];
  long local_30;
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026a20;
  local_10 = ExceptionList;
  ppiVar6 = local_11c;
  for (iVar5 = 0x43; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppiVar6 = (int *)0xcccccccc;
    ppiVar6 = ppiVar6 + 1;
  }
  uVar2 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar1 = FUN_10005840(param_1,0);
  uVar7 = CONCAT44(extraout_EDX,(uint)bVar1);
  if (bVar1 == 0) {
    FUN_10003230(local_24);
    local_8 = 0;
    local_11c[0] = (int *)FUN_10005ec0(param_1);
    uVar3 = FUN_10006110(local_24);
    local_30 = (**(code **)(*local_11c[0] + 0x34))(local_11c[0],uVar3,uVar2);
    uVar3 = 0x1000ee2b;
    if (local_30 < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(param_1);
      _com_issue_errorex(local_30,pIVar4,p_Var8);
    }
    while (iVar5 = FUN_10005cd0(local_24), iVar5 != 0) {
      FUN_10003230(local_3c);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_11c[0] = (int *)FUN_10005ec0(local_24);
      uVar3 = FUN_10006110(local_3c);
      local_48 = (**(code **)(*local_11c[0] + 0x24))(local_11c[0],uVar3);
      uVar3 = 0x1000ee9b;
      if (local_48 < 0) {
        p_Var8 = (_GUID *)&DAT_1002a34c;
        pIVar4 = (IUnknown *)FUN_10005cd0(local_24);
        _com_issue_errorex(local_48,pIVar4,p_Var8);
      }
      FUN_1000ed90(local_24);
      FUN_100054d0(local_3c);
      local_8 = local_8 & 0xffffff00;
      FUN_10004c80(local_3c);
    }
    local_11c[0] = (int *)FUN_10005ec0(param_1);
    local_54 = (**(code **)(*local_11c[0] + 0x20))(local_11c[0],uVar3);
    if (local_54 < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(param_1);
      _com_issue_errorex(local_54,pIVar4,p_Var8);
    }
    local_8 = 0xffffffff;
    uVar7 = FUN_10004c80(local_24);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ef70);
  ExceptionList = local_10;
  return uVar7;
}



// Function: FUN_1000efa0 at 1000efa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall
FUN_1000efa0(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 local_f4 [49];
  uint local_30;
  int local_24;
  uint local_18;
  undefined4 *local_c;
  
  puVar2 = local_f4;
  for (iVar3 = 0x3c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if (param_1 <= *(uint *)((int)this + 0x10)) {
    uVar1 = FUN_1000f5c0((int)param_3);
    if (param_4 <= uVar1) goto LAB_1000efe3;
  }
  FUN_1000bc20();
LAB_1000efe3:
  if (local_c[4] - param_1 < param_2) {
    param_2 = local_c[4] - param_1;
  }
  iVar3 = FUN_1000f5c0((int)param_3);
  local_18 = iVar3 - param_4;
  if (local_18 < param_5) {
    param_5 = local_18;
  }
  if (-param_5 - 1 <= local_c[4] - param_2) {
    FUN_1000bb30();
  }
  local_24 = (local_c[4] - param_2) - param_1;
  local_30 = (local_c[4] + param_5) - param_2;
  if ((uint)local_c[4] < local_30) {
    FUN_1000b070(local_30,'\0');
  }
  if (local_c == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        if (param_4 < param_1 + param_2) {
          uVar1 = param_2;
          puVar2 = FUN_1000b5e0(local_c);
          pvVar4 = (void *)((int)puVar2 + param_4 * 2);
          puVar2 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar2 + param_1 * 2),pvVar4,uVar1);
          iVar3 = local_24;
          puVar2 = FUN_1000b5e0(local_c);
          pvVar4 = (void *)((int)puVar2 + param_2 * 2 + param_1 * 2);
          puVar2 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),pvVar4,iVar3);
          iVar3 = param_5 - param_2;
          puVar2 = FUN_1000b5e0(local_c);
          pvVar4 = (void *)((int)puVar2 + param_5 * 2 + param_4 * 2);
          puVar2 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar2 + param_2 * 2 + param_1 * 2),pvVar4,iVar3);
        }
        else {
          iVar3 = local_24;
          puVar2 = FUN_1000b5e0(local_c);
          pvVar4 = (void *)((int)puVar2 + param_2 * 2 + param_1 * 2);
          puVar2 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),pvVar4,iVar3);
          uVar1 = param_5;
          puVar2 = FUN_1000b5e0(local_c);
          pvVar4 = (void *)((int)puVar2 + ((param_4 + param_5) - param_2) * 2);
          puVar2 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar2 + param_1 * 2),pvVar4,uVar1);
        }
      }
      else {
        iVar3 = local_24;
        puVar2 = FUN_1000b5e0(local_c);
        pvVar4 = (void *)((int)puVar2 + param_2 * 2 + param_1 * 2);
        puVar2 = FUN_1000b5e0(local_c);
        FUN_1000e8c0((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),pvVar4,iVar3);
        puVar2 = FUN_1000b5e0(local_c);
        pvVar4 = (void *)((int)puVar2 + param_4 * 2);
        puVar2 = FUN_1000b5e0(local_c);
        FUN_1000e8c0((void *)((int)puVar2 + param_1 * 2),pvVar4,param_5);
      }
    }
    else {
      uVar1 = param_5;
      puVar2 = FUN_1000b5e0(local_c);
      pvVar4 = (void *)((int)puVar2 + param_4 * 2);
      puVar2 = FUN_1000b5e0(local_c);
      FUN_1000e8c0((void *)((int)puVar2 + param_1 * 2),pvVar4,uVar1);
      iVar3 = local_24;
      puVar2 = FUN_1000b5e0(local_c);
      pvVar4 = (void *)((int)puVar2 + param_2 * 2 + param_1 * 2);
      puVar2 = FUN_1000b5e0(local_c);
      FUN_1000e8c0((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),pvVar4,iVar3);
    }
  }
  else {
    iVar3 = local_24;
    puVar2 = FUN_1000b5e0(local_c);
    pvVar4 = (void *)((int)puVar2 + param_2 * 2 + param_1 * 2);
    puVar2 = FUN_1000b5e0(local_c);
    FUN_1000e8c0((void *)((int)puVar2 + param_5 * 2 + param_1 * 2),pvVar4,iVar3);
    puVar2 = FUN_1000b650(param_3);
    pvVar4 = (void *)((int)puVar2 + param_4 * 2);
    puVar2 = FUN_1000b5e0(local_c);
    FUN_1000c6c0((void *)((int)puVar2 + param_1 * 2),pvVar4,param_5);
  }
  FUN_1000abb0(local_c,local_30);
  return local_c;
}



// Function: FUN_1000f2f0 at 1000f2f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall
FUN_1000f2f0(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_e8 [49];
  uint local_24;
  int local_18;
  undefined4 *local_c;
  
  puVar3 = local_e8;
  for (iVar4 = 0x39; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (undefined4 *)this;
  uVar2 = FUN_1000b440(this,param_3);
  if ((uVar2 & 0xff) == 0) {
    if ((uint)local_c[4] < param_1) {
      FUN_1000bc20();
    }
    if (local_c[4] - param_1 < param_2) {
      param_2 = local_c[4] - param_1;
    }
    if (-param_4 - 1 <= local_c[4] - param_2) {
      FUN_1000bb30();
    }
    iVar4 = (local_c[4] - param_2) - param_1;
    local_18 = iVar4;
    if (param_4 < param_2) {
      puVar3 = FUN_1000b5e0(local_c);
      pvVar5 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
      puVar3 = FUN_1000b5e0(local_c);
      FUN_1000e8c0((void *)((int)puVar3 + param_4 * 2 + param_1 * 2),pvVar5,iVar4);
    }
    if ((param_4 != 0) || (param_2 != 0)) {
      local_24 = (local_c[4] + param_4) - param_2;
      bVar1 = FUN_1000b070(local_24,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          iVar4 = local_18;
          puVar3 = FUN_1000b5e0(local_c);
          pvVar5 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
          puVar3 = FUN_1000b5e0(local_c);
          FUN_1000e8c0((void *)((int)puVar3 + param_4 * 2 + param_1 * 2),pvVar5,iVar4);
        }
        puVar3 = FUN_1000b5e0(local_c);
        FUN_1000c6c0((void *)((int)puVar3 + param_1 * 2),param_3,param_4);
        FUN_1000abb0(local_c,local_24);
      }
    }
  }
  else {
    puVar3 = FUN_1000b5e0(local_c);
    local_c = FUN_1000efa0(local_c,param_1,param_2,local_c,(int)param_3 - (int)puVar3 >> 1,param_4);
  }
  return local_c;
}



// Function: FUN_1000f4a0 at 1000f4a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_1000f4a0(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_100 [4];
  undefined1 local_f0 [12];
  undefined4 local_e4;
  undefined1 local_d8 [204];
  void *local_c;
  
  puVar2 = local_100;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  bVar1 = FUN_10005960((int *)&stack0x00000010);
  if (bVar1) {
    puVar2 = (undefined4 *)FUN_1000c430(local_c,local_f0);
    local_100[1] = *puVar2;
    uVar3 = FUN_1000b6f0(param_2);
    uVar4 = FUN_1000b6f0(param_1);
    FUN_1000ce90(local_c,uVar4,uVar3);
  }
  else {
    puVar2 = (undefined4 *)FUN_1000c430(local_c,local_d8);
    local_e4 = *puVar2;
    uVar3 = FUN_100060b0(&stack0x00000010,(int *)&stack0x0000000c);
    puVar2 = (undefined4 *)FUN_10006010((undefined4 *)&stack0x0000000c);
    uVar4 = FUN_1000b6f0(param_2);
    uVar5 = FUN_1000b6f0(param_1);
    FUN_1000f2f0(local_c,uVar5,uVar4,puVar2,uVar3);
  }
  return local_c;
}



// Function: FUN_1000f590 at 1000f590

undefined4 __fastcall FUN_1000f590(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000f5c0 at 1000f5c0

undefined4 __fastcall FUN_1000f5c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000f5f0 at 1000f5f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_1000f5f0(void *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_f4;
  undefined1 local_ed [9];
  undefined4 local_e4;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026a5f;
  local_10 = ExceptionList;
  puVar2 = &local_f4;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_e4 = 0;
  FUN_1000e0f0(local_ed);
  FUN_10003aa0(param_1,local_18,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f6a0 at 1000f6a0

undefined * FUN_1000f6a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_100338b8;
}



// Function: FUN_1000f6d0 at 1000f6d0

undefined4 __fastcall FUN_1000f6d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_1000f700 at 1000f700

undefined4 __fastcall FUN_1000f700(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_1000f730 at 1000f730

uint __cdecl FUN_1000f730(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((int)param_1 < 1) {
    local_c8[0] = param_1;
  }
  else {
    local_c8[0] = param_1 & 0xffff | 0x80070000;
  }
  return local_c8[0];
}



// Function: FUN_1000f790 at 1000f790

undefined4 __cdecl FUN_1000f790(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    local_c8[0] = 1;
  }
  else {
    local_c8[0] = 0;
  }
  return local_c8[0];
}



// Function: FUN_1000f850 at 1000f850

short * __cdecl FUN_1000f850(short *param_1,short param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while( true ) {
    if (param_3 == 0) {
      return (short *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  }
  return param_1;
}



// Function: FUN_1000f8b0 at 1000f8b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000f8b0(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  memcpy(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_1000f900 at 1000f900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000f900(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  memmove(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_1000f960 at 1000f960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000f960(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026a93;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fb70(param_1);
  local_8 = 0;
  FUN_1000faa0(local_18 + 1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000f9f0 at 1000f9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000f9f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fd20(param_1);
  return local_c;
}



// Function: FUN_1000fa40 at 1000fa40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000fa40(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = 0;
  local_c = (undefined4 *)this;
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return local_c;
}



// Function: FUN_1000faa0 at 1000faa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __fastcall FUN_1000faa0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026ac8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fbb0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000fb20 at 1000fb20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __fastcall FUN_1000fb20(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  memset(param_1,0,0x18);
  return local_c;
}



// Function: FUN_1000fb70 at 1000fb70

undefined4 * __fastcall FUN_1000fb70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000fbb0 at 1000fbb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __fastcall FUN_1000fbb0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026af8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fb20(param_1);
  *(undefined1 *)((int)local_18 + 0x18) = 0;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000fc40 at 1000fc40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_1000fc40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026b62;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000f960((undefined4 *)(param_1 + 8));
  local_8 = 0;
  FUN_1000fdc0(local_18);
  FUN_1000f9f0(local_18 + 4);
  FUN_10002920((undefined4 *)(local_18 + 0x28));
  local_8._0_1_ = 1;
  FUN_10002920((undefined4 *)(local_18 + 0x2c));
  local_8._0_1_ = 2;
  FUN_10002920((undefined4 *)(local_18 + 0x30));
  local_8._0_1_ = 3;
  FUN_10002920((undefined4 *)(local_18 + 0x34));
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10002a20((undefined4 *)(local_18 + 0x38));
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000fd20 at 1000fd20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000fd20(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fd70(param_1);
  return local_c;
}



// Function: FUN_1000fd70 at 1000fd70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000fd70(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fe10(param_1);
  return local_c;
}



// Function: FUN_1000fdc0 at 1000fdc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000fdc0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fe10(param_1);
  return local_c;
}



// Function: FUN_1000fe10 at 1000fe10

undefined4 __fastcall FUN_1000fe10(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_1000fe40 at 1000fe40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fe40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026b93;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = param_1;
  FUN_1000ff10((LPCRITICAL_SECTION)(param_1 + 4));
  local_8 = 0xffffffff;
  FUN_1000ffc0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000fed0 at 1000fed0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fed0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000b750(param_1);
  return;
}



// Function: FUN_1000ff10 at 1000ff10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000ff10(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  LPCRITICAL_SECTION local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026bc8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_1000fff0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ff90 at 1000ff90

void FUN_1000ff90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000ffc0 at 1000ffc0

void FUN_1000ffc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1000fff0 at 1000fff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000fff0(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  LPCRITICAL_SECTION local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026bf8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = param_1;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    CSymbolicTreeNode_get_ChildCount(param_1);
  }
  local_8 = 0xffffffff;
  FUN_1000ff90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010090 at 10010090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10010090(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026c62;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8._0_1_ = 4;
  local_8._1_3_ = 0;
  local_18 = param_1;
  FUN_100046e0((int *)(param_1 + 0x38));
  local_8._0_1_ = 3;
  FUN_10004660((int *)(local_18 + 0x34));
  local_8._0_1_ = 2;
  FUN_10004660((int *)(local_18 + 0x30));
  local_8._0_1_ = 1;
  FUN_10004660((int *)(local_18 + 0x2c));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004660((int *)(local_18 + 0x28));
  local_8 = 0xffffffff;
  FUN_1000fe40(local_18 + 8);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010160 at 10010160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10010160(void *this,int param_1)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  undefined4 *puVar4;
  void *local_f0 [3];
  int local_e4 [51];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026c8b;
  local_10 = ExceptionList;
  ppvVar3 = local_f0;
  for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  bVar1 = FUN_10005b20(this,param_1);
  if (bVar1) {
    puVar4 = local_18;
    local_f0[0] = FUN_100028a0(local_e4,param_1);
    local_8 = 0;
    local_f0[1] = local_f0[0];
    FUN_1000a100(local_f0[0],puVar4);
    local_8 = 0xffffffff;
    FUN_10004660(local_e4);
  }
  FUN_10005cd0(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010230 at 10010230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10010230(void *this,int param_1)

{
  bool bVar1;
  int iVar2;
  void **ppvVar3;
  undefined4 *puVar4;
  void *local_f0 [3];
  int local_e4 [51];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026cbb;
  local_10 = ExceptionList;
  ppvVar3 = local_f0;
  for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  bVar1 = FUN_10005b90(this,param_1);
  if (bVar1) {
    puVar4 = local_18;
    local_f0[0] = FUN_100029a0(local_e4,param_1);
    local_8 = 0;
    local_f0[1] = local_f0[0];
    FUN_100111b0(local_f0[0],puVar4);
    local_8 = 0xffffffff;
    FUN_100046e0(local_e4);
  }
  FUN_10005d00(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010300 at 10010300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10010300(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
                    /* WARNING: Load size is inaccurate */
    if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      local_c = this;
      (**(code **)(**this + 4))(*this);
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: CSymbolicTreeNode_DetachNode at 10010380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_DetachNode(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  IUnknown *pIVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int **ppiVar5;
  undefined8 uVar6;
  _GUID *p_Var7;
  uint uStack_154;
  int *local_144 [65];
  long local_40;
  long local_34;
  long local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026ce8;
  local_10 = ExceptionList;
  ppiVar5 = local_144;
  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar5 = (int *)0xcccccccc;
    ppiVar5 = ppiVar5 + 1;
  }
  uStack_154 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_154;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  bVar1 = FUN_10005b20((void *)(param_1 + 0x2c),0);
  if (bVar1) {
    local_144[0] = (int *)FUN_10005ec0((undefined4 *)(param_1 + 0x2c));
    uVar2 = FUN_10005cd0((undefined4 *)(param_1 + 0x30));
    local_28 = (**(code **)(*local_144[0] + 0x28))(local_144[0],uVar2);
    uStack_154 = 0x1001041d;
    if (local_28 < 0) {
      p_Var7 = (_GUID *)&DAT_1002a34c;
      pIVar3 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x2c));
      _com_issue_errorex(local_28,pIVar3,p_Var7);
    }
  }
  else {
    bVar1 = FUN_10005b20((void *)(param_1 + 0x24),0);
    if (bVar1) {
      local_144[0] = (int *)FUN_10005ec0((undefined4 *)(param_1 + 0x24));
      uVar2 = FUN_10005cd0((undefined4 *)(param_1 + 0x30));
      local_34 = (**(code **)(*local_144[0] + 0x38))(local_144[0],uVar2);
      uStack_154 = 0x10010490;
      if (local_34 < 0) {
        p_Var7 = (_GUID *)&DAT_1002a34c;
        pIVar3 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x24));
        _com_issue_errorex(local_34,pIVar3,p_Var7);
      }
    }
  }
  bVar1 = FUN_10005b20((void *)(param_1 + 0x30),0);
  if (bVar1) {
    local_144[0] = (int *)FUN_10005ec0((undefined4 *)(param_1 + 0x30));
    uVar2 = FUN_10005cd0((undefined4 *)(param_1 + 0x2c));
    local_40 = (**(code **)(*local_144[0] + 0x30))(local_144[0],uVar2);
    uStack_154 = 0x10010501;
    if (local_40 < 0) {
      p_Var7 = (_GUID *)&DAT_1002a34c;
      pIVar3 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x30));
      _com_issue_errorex(local_40,pIVar3,p_Var7);
    }
  }
  FUN_10010160((void *)(param_1 + 0x2c),0);
  FUN_10010160((void *)(param_1 + 0x30),0);
  FUN_10010160((void *)(param_1 + 0x24),0);
  uVar6 = CSymbolicTreeNode_FinalConstruct(extraout_ECX,extraout_EDX);
  return uVar6;
}



// Function: Catch@10010550 at 10010550

undefined * Catch_10010550(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x48),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033344 + 0x25,"CSymbolicTreeNode::DetachNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x138) = uVar2;
  return &DAT_10010633;
}



// Function: Catch@100105a4 at 100105a4

undefined * Catch_100105a4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x60),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x60),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033344 + 0x25,"CSymbolicTreeNode::DetachNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -300) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x1001060d;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return &DAT_10010622;
}



// Function: CSymbolicTreeNode_FinalConstruct at 10010619

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_FinalConstruct(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10010678);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_FinalConstruct at 100106a0

undefined8 CSymbolicTreeNode_FinalConstruct(void)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint uStack_144;
  undefined4 local_134 [64];
  int local_34;
  undefined4 local_28;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026d18;
  local_10 = ExceptionList;
  puVar4 = local_134;
  for (iVar2 = 0x48; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uStack_144 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_144;
  ExceptionList = &local_10;
  local_28 = 0;
  local_8 = 0;
  bVar1 = FUN_100059d0(&DAT_100338c4,0);
  uVar5 = CONCAT44(extraout_EDX,local_34);
  uVar3 = extraout_ECX;
  if (bVar1) {
    uVar5 = FUN_10007150(&DAT_100338c4,(IID *)&DAT_10029748,(LPUNKNOWN)0x0,0x17);
    local_34 = (int)uVar5;
    uVar3 = extraout_ECX_00;
    if (local_34 < 0) {
      _com_issue_error(local_34);
      uVar5 = CONCAT44(extraout_EDX_00,local_34);
      uVar3 = extraout_ECX_01;
    }
  }
  local_34 = (int)uVar5;
  uVar5 = FUN_100107fa(uVar3,(int)((ulonglong)uVar5 >> 0x20));
  return uVar5;
}



// Function: Catch@10010731 at 10010731

undefined * Catch_10010731(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003333c + 0xb,"CSymbolicTreeNode::FinalConstruct",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -300) = uVar2;
  return &DAT_10010814;
}



// Function: Catch@10010785 at 10010785

undefined * Catch_10010785(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x54),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x54),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003333c + 0xb,"CSymbolicTreeNode::FinalConstruct",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x120) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100107ee;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x54));
  return &DAT_10010803;
}



// Function: FUN_100107fa at 100107fa

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_100107fa(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x24);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10010858);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10010880 at 10010880

void FUN_10010880(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100108b0 at 100108b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100108b0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  (**(code **)*param_1)(param_1,&DAT_1002ac24,param_2);
  return;
}



// Function: FUN_10010910 at 10010910

undefined * FUN_10010910(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_1002ac64;
}



// Function: CSymbolicTreeNode_InsertNode at 10010940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_InsertNode(IID *param_1,IUnknown *param_2,IID *param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  void **ppvVar3;
  IID *pIVar4;
  IUnknown *pIVar5;
  int iVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar7;
  IID **ppIVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  _GUID *p_Var11;
  IID *local_1f8 [65];
  ULONG local_f4;
  long local_e8;
  ULONG local_dc;
  HRESULT local_d0;
  ULONG local_c4;
  long local_b8;
  HRESULT local_ac;
  HRESULT local_a0;
  long local_94;
  ULONG local_88;
  ULONG local_7c;
  ULONG local_70;
  ULONG local_64;
  long local_58;
  ULONG local_4c;
  long local_40;
  IID *local_34;
  IID *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026d4b;
  local_10 = ExceptionList;
  ppIVar8 = local_1f8;
  for (iVar6 = 0x79; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppIVar8 = (IID *)0xcccccccc;
    ppIVar8 = ppIVar8 + 1;
  }
  ppvVar3 = (void **)(DAT_10033838 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xfffffdf8;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &stack0xfffffdf8;
  if (param_2 == (IUnknown *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = local_14;
  }
  local_14 = puVar1;
  if (param_1 == (IID *)0x4) {
    local_1f8[0] = (IID *)0x0;
  }
  else {
    local_1f8[0] = param_1;
  }
  pIVar4 = local_1f8[0];
  local_34 = local_1f8[0];
  local_1f8[0] = param_3;
  if (param_3 == (IID *)0x1) {
    local_40 = (*param_2->lpVtbl[4].QueryInterface)(param_2,pIVar4,ppvVar3);
    if (local_40 < 0) {
      p_Var11 = (_GUID *)&DAT_1002a34c;
      pIVar5 = (IUnknown *)FUN_10005cd0(&param_1[3].Data1);
      _com_issue_errorex(local_40,pIVar5,p_Var11);
    }
    pIVar4 = (IID *)FUN_10005cd0((undefined4 *)&param_1[2].Data2);
    local_28 = pIVar4;
    local_4c = (*param_2->lpVtbl[5].AddRef)(param_2);
    uVar10 = 0x10010a78;
    if ((int)local_4c < 0) {
      p_Var11 = (_GUID *)&DAT_1002a34c;
      pIVar5 = (IUnknown *)FUN_10005cd0(&param_1[3].Data1);
      _com_issue_errorex(local_4c,pIVar5,p_Var11);
    }
    bVar2 = FUN_10005b20(param_1 + 3,0);
    if (bVar2) {
      local_1f8[0] = (IID *)FUN_10005ec0(&param_1[3].Data1);
      local_58 = (**(code **)(local_1f8[0]->Data1 + 0x30))(local_1f8[0],param_2,uVar10,pIVar4);
      if (local_58 < 0) {
        p_Var11 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0(&param_1[3].Data1);
        _com_issue_errorex(local_58,pIVar5,p_Var11);
      }
      local_28 = (IID *)FUN_10005cd0(&param_1[3].Data1);
      local_64 = (*param_2->lpVtbl[3].AddRef)(param_2);
      if ((int)local_64 < 0) {
        _com_issue_errorex(local_64,param_2,(_GUID *)&DAT_1002a34c);
      }
    }
    else {
      local_70 = (*param_2->lpVtbl[3].AddRef)(param_2);
      if ((int)local_70 < 0) {
        _com_issue_errorex(local_70,param_2,(_GUID *)&DAT_1002a34c);
      }
    }
    FUN_10010160(param_1 + 3,(int)param_2);
    uVar10 = extraout_ECX;
    uVar7 = extraout_EDX;
  }
  else if (param_3 == (IID *)0x2) {
    local_7c = (*param_2->lpVtbl[3].AddRef)(param_2);
    if ((int)local_7c < 0) {
      p_Var11 = (_GUID *)&DAT_1002a34c;
      pIVar5 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1[2].Data4 + 4));
      _com_issue_errorex(local_7c,pIVar5,p_Var11);
    }
    pIVar4 = (IID *)FUN_10005cd0((undefined4 *)&param_1[2].Data2);
    local_28 = pIVar4;
    local_88 = (*param_2->lpVtbl[5].AddRef)(param_2);
    ppvVar3 = (void **)0x10010bfd;
    if ((int)local_88 < 0) {
      p_Var11 = (_GUID *)&DAT_1002a34c;
      pIVar5 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1[2].Data4 + 4));
      _com_issue_errorex(local_88,pIVar5,p_Var11);
    }
    bVar2 = FUN_10005b20(param_1[2].Data4 + 4,0);
    if (bVar2) {
      local_1f8[0] = (IID *)FUN_10005ec0((undefined4 *)(param_1[2].Data4 + 4));
      local_94 = (**(code **)(local_1f8[0]->Data1 + 0x28))(local_1f8[0],param_2,ppvVar3,pIVar4);
      ppvVar3 = (void **)0x10010c73;
      if (local_94 < 0) {
        p_Var11 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1[2].Data4 + 4));
        _com_issue_errorex(local_94,pIVar5,p_Var11);
      }
      local_28 = (IID *)FUN_10005cd0((undefined4 *)(param_1[2].Data4 + 4));
      local_a0 = (*param_2->lpVtbl[4].QueryInterface)(param_2,local_28,ppvVar3);
      if (local_a0 < 0) {
        _com_issue_errorex(local_a0,param_2,(_GUID *)&DAT_1002a34c);
      }
    }
    else {
      local_ac = (*param_2->lpVtbl[4].QueryInterface)(param_2,(IID *)0x0,ppvVar3);
      uVar10 = 0x10010d0a;
      if (local_ac < 0) {
        _com_issue_errorex(local_ac,param_2,(_GUID *)&DAT_1002a34c);
      }
      local_1f8[0] = (IID *)FUN_10005ec0((undefined4 *)&param_1[2].Data2);
      local_b8 = (**(code **)(local_1f8[0]->Data1 + 0x38))(local_1f8[0],param_2,uVar10);
      if (local_b8 < 0) {
        p_Var11 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0((undefined4 *)&param_1[2].Data2);
        _com_issue_errorex(local_b8,pIVar5,p_Var11);
      }
    }
    FUN_10010160(param_1[2].Data4 + 4,(int)param_2);
    uVar10 = extraout_ECX_00;
    uVar7 = extraout_EDX_00;
  }
  else if (param_3 == (IID *)0x3) {
    local_c4 = (*param_2->lpVtbl[5].AddRef)(param_2);
    ppvVar3 = (void **)0x10010dbb;
    if ((int)local_c4 < 0) {
      _com_issue_errorex(local_c4,param_2,(_GUID *)&DAT_1002a34c);
    }
    local_d0 = (*param_2->lpVtbl[4].QueryInterface)(param_2,(IID *)0x0,ppvVar3);
    if (local_d0 < 0) {
      _com_issue_errorex(local_d0,param_2,(_GUID *)&DAT_1002a34c);
    }
    bVar2 = FUN_10005b20(param_1[2].Data4,0);
    if (bVar2) {
      pIVar4 = (IID *)FUN_10005cd0((undefined4 *)param_1[2].Data4);
      local_28 = pIVar4;
      local_dc = (*param_2->lpVtbl[3].AddRef)(param_2);
      uVar10 = 0x10010e5d;
      if ((int)local_dc < 0) {
        _com_issue_errorex(local_dc,param_2,(_GUID *)&DAT_1002a34c);
      }
      local_1f8[0] = (IID *)FUN_10005ec0((undefined4 *)param_1[2].Data4);
      local_e8 = (**(code **)(local_1f8[0]->Data1 + 0x30))(local_1f8[0],param_2,uVar10,pIVar4);
      if (local_e8 < 0) {
        p_Var11 = (_GUID *)&DAT_1002a34c;
        pIVar5 = (IUnknown *)FUN_10005cd0((undefined4 *)param_1[2].Data4);
        _com_issue_errorex(local_e8,pIVar5,p_Var11);
      }
    }
    else {
      local_f4 = (*param_2->lpVtbl[3].AddRef)(param_2);
      if ((int)local_f4 < 0) {
        _com_issue_errorex(local_f4,param_2,(_GUID *)&DAT_1002a34c);
      }
    }
    FUN_10010160(param_1[2].Data4,(int)param_2);
    uVar10 = extraout_ECX_01;
    uVar7 = extraout_EDX_01;
  }
  else {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    uVar10 = extraout_ECX_02;
    uVar7 = extraout_EDX_02;
  }
  uVar9 = CSymbolicTreeNode_InsertNode(uVar10,uVar7);
  return uVar9;
}



// Function: Catch@10010f59 at 10010f59

undefined * Catch_10010f59(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0xfc),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033340 + 0x6f,"CSymbolicTreeNode::InsertNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x1ec) = uVar2;
  return &DAT_10011048;
}



// Function: Catch@10010fb0 at 10010fb0

undefined * Catch_10010fb0(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x114),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x114),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033340 + 0x6f,"CSymbolicTreeNode::InsertNode",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x1e0) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10011022;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x114));
  return &DAT_10011037;
}



// Function: CSymbolicTreeNode_InsertNode at 1001102e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_InsertNode(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001108c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_100110c0 at 100110c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100110c0(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  while( true ) {
    if (local_c != 0) {
      return 1;
    }
    iVar1 = FUN_1000f790((int *)PTR_DAT_10033334,param_2);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_10011140 at 10011140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10011140(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = (int *)*param_1;
  if (local_18 != (int *)0x0) {
    *param_1 = 0;
    local_c = param_1;
    (**(code **)(*local_18 + 8))(local_18);
  }
  return;
}



// Function: FUN_100111b0 at 100111b0

void __thiscall FUN_100111b0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  uVar1 = *this;
  *(undefined4 *)this = *param_1;
  *param_1 = uVar1;
  return;
}



// Function: CSymbolicTreeNode_get_ChildCount at 10011200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall CSymbolicTreeNode_get_ChildCount(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LPCRITICAL_SECTION local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: CSymbolicTreeNode_get_ChildCount at 10011250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_get_ChildCount(int param_1,undefined4 *param_2)

{
  uint *puVar1;
  bool bVar2;
  IUnknown *pIVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int **ppiVar6;
  undefined8 uVar7;
  _GUID *p_Var8;
  uint uStack_13c;
  int *local_12c [65];
  long local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026d78;
  local_10 = ExceptionList;
  ppiVar6 = local_12c;
  for (iVar4 = 0x46; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar6 = (int *)0xcccccccc;
    ppiVar6 = ppiVar6 + 1;
  }
  uStack_13c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_13c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_13c;
  if (param_2 == (undefined4 *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  *param_2 = 0;
  bVar2 = FUN_10005b20((void *)(param_1 + 0x28),0);
  uVar7 = CONCAT44(extraout_EDX,local_28);
  uVar5 = extraout_ECX;
  if (bVar2) {
    local_12c[0] = (int *)FUN_10005ec0((undefined4 *)(param_1 + 0x28));
    uVar7 = (**(code **)(*local_12c[0] + 0x44))(local_12c[0],param_2);
    local_28 = (long)uVar7;
    uStack_13c = 0x10011319;
    uVar5 = extraout_ECX_00;
    if (local_28 < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar3 = (IUnknown *)FUN_10005cd0((undefined4 *)(param_1 + 0x28));
      _com_issue_errorex(local_28,pIVar3,p_Var8);
      uVar7 = CONCAT44(extraout_EDX_00,local_28);
      uVar5 = extraout_ECX_01;
    }
  }
  local_28 = (long)uVar7;
  uVar7 = CSymbolicTreeNode_get_Data(uVar5,(int)((ulonglong)uVar7 >> 0x20));
  return uVar7;
}



// Function: Catch@10011341 at 10011341

undefined * Catch_10011341(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x30),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003334c + 0x15,"CSymbolicTreeNode::get_ChildCount",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x120) = uVar2;
  return &DAT_10011424;
}



// Function: Catch@10011395 at 10011395

undefined * Catch_10011395(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x48),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x48),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003334c + 0x15,"CSymbolicTreeNode::get_ChildCount",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100113fe;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x48));
  return &DAT_10011413;
}



// Function: CSymbolicTreeNode_get_Data at 1001140a

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Data(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011468);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Data at 10011490

undefined8 CSymbolicTreeNode_get_Data(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026da8;
  local_10 = ExceptionList;
  puVar3 = local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FUN_10010300((void *)(param_1 + 0x34),param_2);
  uVar4 = CSymbolicTreeNode_get_FirstChild(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@1001151e at 1001151e

undefined * Catch_1001151e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033378 + 0xe,"CSymbolicTreeNode::get_Data",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10011601;
}



// Function: Catch@10011572 at 10011572

undefined * Catch_10011572(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033378 + 0xe,"CSymbolicTreeNode::get_Data",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100115db;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_100115f0;
}



// Function: CSymbolicTreeNode_get_FirstChild at 100115e7

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_FirstChild(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011648);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_FirstChild at 10011670

undefined8 CSymbolicTreeNode_get_FirstChild(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026dd8;
  local_10 = ExceptionList;
  puVar3 = local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FUN_10006f00((void *)(param_1 + 0x28),param_2);
  uVar4 = CSymbolicTreeNode_get_Head(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@100116fe at 100116fe

undefined * Catch_100116fe(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033358 + 0xf,"CSymbolicTreeNode::get_FirstChild",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_100117e1;
}



// Function: Catch@10011752 at 10011752

undefined * Catch_10011752(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033358 + 0xf,"CSymbolicTreeNode::get_FirstChild",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100117bb;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_100117d0;
}



// Function: CSymbolicTreeNode_get_Head at 100117c7

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Head(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011828);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Head at 10011850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_get_Head(int param_1,int *param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int **ppiVar6;
  undefined8 uVar7;
  _GUID *p_Var8;
  uint uStack_154;
  int *local_144 [65];
  long local_40;
  int local_34 [3];
  int local_28 [3];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026e18;
  local_10 = ExceptionList;
  ppiVar6 = local_144;
  for (iVar5 = 0x4c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppiVar6 = (int *)0xcccccccc;
    ppiVar6 = ppiVar6 + 1;
  }
  uStack_154 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_154;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_154;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  *param_2 = 0;
  iVar5 = FUN_10005cd0((undefined4 *)(param_1 + 0x28));
  FUN_100031b0(local_28,iVar5);
  local_8._0_1_ = 1;
  FUN_10003230(local_34);
  local_8 = CONCAT31(local_8._1_3_,2);
  bVar2 = FUN_10005b20(local_28,0);
  if (bVar2) {
    local_144[0] = (int *)FUN_10005ec0(local_28);
    uVar3 = FUN_10006110(local_34);
    local_40 = (**(code **)(*local_144[0] + 0x34))(local_144[0],uVar3);
    uStack_154 = 0x1001193c;
    if (local_40 < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_28);
      _com_issue_errorex(local_40,pIVar4,p_Var8);
    }
    FUN_10006f00(local_34,param_2);
  }
  local_8._0_1_ = 1;
  FUN_10004c80(local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004c80(local_28);
  uVar7 = CSymbolicTreeNode_get_Next(extraout_ECX,extraout_EDX);
  return uVar7;
}



// Function: Catch@10011985 at 10011985

undefined * Catch_10011985(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x48),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033360 + 0x1a,"CSymbolicTreeNode::get_Head",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x138) = uVar2;
  return &DAT_10011a68;
}



// Function: Catch@100119d9 at 100119d9

undefined * Catch_100119d9(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x60),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x60),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033360 + 0x1a,"CSymbolicTreeNode::get_Head",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -300) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x10011a42;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return &DAT_10011a57;
}



// Function: CSymbolicTreeNode_get_Next at 10011a4e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Next(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011aac);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Next at 10011b00

undefined8 CSymbolicTreeNode_get_Next(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026e48;
  local_10 = ExceptionList;
  puVar3 = local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FUN_10006f00((void *)(param_1 + 0x30),param_2);
  uVar4 = CSymbolicTreeNode_get_Parent(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@10011b8e at 10011b8e

undefined * Catch_10011b8e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033368 + 0xf,"CSymbolicTreeNode::get_Next",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10011c71;
}



// Function: Catch@10011be2 at 10011be2

undefined * Catch_10011be2(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033368 + 0xf,"CSymbolicTreeNode::get_Next",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10011c4b;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10011c60;
}



// Function: CSymbolicTreeNode_get_Parent at 10011c57

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Parent(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011cb8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Parent at 10011ce0

undefined8 CSymbolicTreeNode_get_Parent(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026e78;
  local_10 = ExceptionList;
  puVar3 = local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FUN_10006f00((void *)(param_1 + 0x24),param_2);
  uVar4 = CSymbolicTreeNode_get_Previous(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@10011d6e at 10011d6e

undefined * Catch_10011d6e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033350 + 0x10,"CSymbolicTreeNode::get_Parent",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10011e51;
}



// Function: Catch@10011dc2 at 10011dc2

undefined * Catch_10011dc2(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033350 + 0x10,"CSymbolicTreeNode::get_Parent",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10011e2b;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10011e40;
}



// Function: CSymbolicTreeNode_get_Previous at 10011e37

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Previous(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011e98);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Previous at 10011ec0

undefined8 CSymbolicTreeNode_get_Previous(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026ea8;
  local_10 = ExceptionList;
  puVar3 = local_11c;
  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FUN_10006f00((void *)(param_1 + 0x2c),param_2);
  uVar4 = CSymbolicTreeNode_get_SiblingCount(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@10011f4e at 10011f4e

undefined * Catch_10011f4e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033370 + 0xf,"CSymbolicTreeNode::get_Previous",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10012031;
}



// Function: Catch@10011fa2 at 10011fa2

undefined * Catch_10011fa2(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033370 + 0xf,"CSymbolicTreeNode::get_Previous",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x1001200b;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10012020;
}



// Function: CSymbolicTreeNode_get_SiblingCount at 10012017

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_SiblingCount(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012078);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_SiblingCount at 100120a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_get_SiblingCount(int param_1,int *param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int **ppiVar6;
  undefined8 uVar7;
  _GUID *p_Var8;
  uint uStack_160;
  int *local_150 [65];
  long local_4c;
  int local_40 [3];
  int local_34 [3];
  int local_28 [3];
  int local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026ef0;
  local_10 = ExceptionList;
  ppiVar6 = local_150;
  for (iVar5 = 0x4f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppiVar6 = (int *)0xcccccccc;
    ppiVar6 = ppiVar6 + 1;
  }
  uStack_160 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_160;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_160;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  *param_2 = 0;
  FUN_10003230(local_28);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar3 = FUN_10006110(local_28);
  local_1c = (**(code **)(*(int *)(param_1 + -4) + 0x18))(param_1 + -4,uVar3);
  if (local_1c < 0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
  }
  FUN_10003120(local_34,local_28);
  local_8._0_1_ = 2;
  while( true ) {
    bVar2 = FUN_10005b20(local_34,0);
    if (!bVar2) break;
    FUN_10003230(local_40);
    local_8 = CONCAT31(local_8._1_3_,3);
    *param_2 = *param_2 + 1;
    local_150[0] = (int *)FUN_10005ec0(local_34);
    uVar3 = FUN_10006110(local_40);
    local_4c = (**(code **)(*local_150[0] + 0x24))(local_150[0],uVar3);
    if (local_4c < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_34);
      _com_issue_errorex(local_4c,pIVar4,p_Var8);
    }
    FUN_100054d0(local_40);
    local_8._0_1_ = 2;
    FUN_10004c80(local_40);
  }
  local_8._0_1_ = 1;
  FUN_10004c80(local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004c80(local_28);
  uVar7 = CSymbolicTreeNode_get_Tail(extraout_ECX,extraout_EDX);
  return uVar7;
}



// Function: Catch@1001224d at 1001224d

undefined * Catch_1001224d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x54),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033348 + 0x25,"CSymbolicTreeNode::get_SiblingCount",*puVar1,puVar1[1])
  ;
  *(undefined4 *)(unaff_EBP + -0x144) = uVar2;
  return &DAT_10012330;
}



// Function: Catch@100122a1 at 100122a1

undefined * Catch_100122a1(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x6c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x6c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033348 + 0x25,"CSymbolicTreeNode::get_SiblingCount",*puVar1,puVar1[1])
  ;
  *(undefined4 *)(unaff_EBP + -0x138) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x1001230a;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return &DAT_1001231f;
}



// Function: CSymbolicTreeNode_get_Tail at 10012316

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_get_Tail(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012374);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_get_Tail at 100123e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CSymbolicTreeNode_get_Tail(int param_1,int *param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int **ppiVar6;
  undefined8 uVar7;
  _GUID *p_Var8;
  uint uStack_154;
  int *local_144 [65];
  int local_40;
  int local_34 [3];
  int local_28 [3];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10026f28;
  local_10 = ExceptionList;
  ppiVar6 = local_144;
  for (iVar5 = 0x4c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppiVar6 = (int *)0xcccccccc;
    ppiVar6 = ppiVar6 + 1;
  }
  uStack_154 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_154;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  puVar1 = &uStack_154;
  if (param_2 == (int *)0x0) {
    FUN_10021d70((uchar *)
                 "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                );
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  iVar5 = FUN_10005cd0((undefined4 *)(param_1 + 0x34));
  FUN_100031b0(local_28,iVar5);
  local_8._0_1_ = 1;
  if (param_1 == 0) {
    local_144[0] = (int *)0x0;
  }
  else {
    local_144[0] = (int *)(param_1 + 4);
  }
  FUN_100031b0(local_34,(int)local_144[0]);
  local_8._0_1_ = 2;
  while (bVar2 = FUN_10005b20(local_28,0), bVar2) {
    FUN_100054d0(local_28);
    FUN_10011140(local_28);
    local_144[0] = (int *)FUN_10005ec0(local_34);
    uVar3 = FUN_10006110(local_28);
    local_40 = (**(code **)(*local_144[0] + 0x24))(local_144[0],uVar3);
    uStack_154 = 0x100124fc;
    if (local_40 < 0) {
      p_Var8 = (_GUID *)&DAT_1002a34c;
      pIVar4 = (IUnknown *)FUN_10005cd0(local_34);
      _com_issue_errorex(local_40,pIVar4,p_Var8);
    }
  }
  FUN_10006f00(local_34,param_2);
  local_8._0_1_ = 1;
  FUN_10004c80(local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004c80(local_28);
  uVar7 = CSymbolicTreeNode_put_Data(extraout_ECX,extraout_EDX);
  return uVar7;
}



// Function: Catch@10012547 at 10012547

undefined * Catch_10012547(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x48),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033364 + 0x1b,"CSymbolicTreeNode::get_Tail",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x138) = uVar2;
  return &DAT_1001262a;
}



// Function: Catch@1001259b at 1001259b

undefined * Catch_1001259b(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x60),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x60),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033364 + 0x1b,"CSymbolicTreeNode::get_Tail",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -300) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x10012604;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return &DAT_10012619;
}



// Function: CSymbolicTreeNode_put_Data at 10012610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_put_Data(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012670);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_put_Data at 100126c0

undefined8 CSymbolicTreeNode_put_Data(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026f58;
  local_10 = ExceptionList;
  puVar2 = local_11c;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  FUN_10010230((void *)(param_1 + 0x34),param_2);
  uVar3 = CSymbolicTreeNode_put_FirstChild(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@10012723 at 10012723

undefined * Catch_10012723(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003337c + 8,"CSymbolicTreeNode::put_Data",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10012806;
}



// Function: Catch@10012777 at 10012777

undefined * Catch_10012777(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003337c + 8,"CSymbolicTreeNode::put_Data",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100127e0;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_100127f5;
}



// Function: CSymbolicTreeNode_put_FirstChild at 100127ec

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_put_FirstChild(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001284c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_put_FirstChild at 10012880

undefined8 CSymbolicTreeNode_put_FirstChild(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026f88;
  local_10 = ExceptionList;
  puVar2 = local_11c;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  FUN_10010160((void *)(param_1 + 0x28),param_2);
  uVar3 = CSymbolicTreeNode_put_Next(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@100128e3 at 100128e3

undefined * Catch_100128e3(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003335c + 9,"CSymbolicTreeNode::put_FirstChild",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_100129c6;
}



// Function: Catch@10012937 at 10012937

undefined * Catch_10012937(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003335c + 9,"CSymbolicTreeNode::put_FirstChild",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100129a0;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_100129b5;
}



// Function: CSymbolicTreeNode_put_Next at 100129ac

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_put_Next(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012a0c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_put_Next at 10012a40

undefined8 CSymbolicTreeNode_put_Next(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026fb8;
  local_10 = ExceptionList;
  puVar2 = local_11c;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  FUN_10010160((void *)(param_1 + 0x30),param_2);
  uVar3 = CSymbolicTreeNode_put_Parent(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@10012aa3 at 10012aa3

undefined * Catch_10012aa3(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003336c + 9,"CSymbolicTreeNode::put_Next",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10012b86;
}



// Function: Catch@10012af7 at 10012af7

undefined * Catch_10012af7(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_1003336c + 9,"CSymbolicTreeNode::put_Next",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10012b60;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10012b75;
}



// Function: CSymbolicTreeNode_put_Parent at 10012b6c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_put_Parent(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012bcc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_put_Parent at 10012c00

undefined8 CSymbolicTreeNode_put_Parent(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026ff8;
  local_10 = ExceptionList;
  puVar2 = local_11c;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  FUN_10010160((void *)(param_1 + 0x24),param_2);
  uVar3 = CSymbolicTreeNode_put_Previous(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@10012c63 at 10012c63

undefined * Catch_10012c63(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033354 + 8,"CSymbolicTreeNode::put_Parent",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10012d46;
}



// Function: Catch@10012cb7 at 10012cb7

undefined * Catch_10012cb7(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033354 + 8,"CSymbolicTreeNode::put_Parent",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10012d20;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10012d35;
}



// Function: CSymbolicTreeNode_put_Previous at 10012d2c

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CSymbolicTreeNode_put_Previous(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012d8c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CSymbolicTreeNode_put_Previous at 10012dc0

undefined8 CSymbolicTreeNode_put_Previous(int param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_12c;
  undefined4 local_11c [64];
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027028;
  local_10 = ExceptionList;
  puVar2 = local_11c;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_12c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12c;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  FUN_10010160((void *)(param_1 + 0x2c),param_2);
  uVar3 = FUN_10012eec(extraout_ECX,extraout_EDX);
  return uVar3;
}



// Function: Catch@10012e23 at 10012e23

undefined * Catch_10012e23(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0(*(void **)(unaff_EBP + -0x24),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033374 + 9,"CSymbolicTreeNode::put_Previous",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_10012f06;
}



// Function: Catch@10012e77 at 10012e77

undefined * Catch_10012e77(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10004240((void *)(unaff_EBP + -0x3c),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10010910();
  uVar2 = FUN_100215a0((void *)(unaff_EBP + -0x3c),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\symbolictree\\symbolictreenode.cpp"
                       ,DAT_10033374 + 9,"CSymbolicTreeNode::put_Previous",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x108) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10012ee0;
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return &DAT_10012ef5;
}



// Function: FUN_10012eec at 10012eec

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10012eec(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012f4c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10012f80 at 10012f80

undefined4 FUN_10012f80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_10012fb0 at 10012fb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012fb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001fc30((int *)&DAT_100338ec,0x65,param_1,(int *)0x0);
  return;
}



// Function: FUN_10013000 at 10013000

undefined4 FUN_10013000(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_10013030 at 10013030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10013030(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001fc30((int *)&DAT_100338ec,0x66,param_1,(int *)0x0);
  return;
}



// Function: FUN_10013080 at 10013080

void FUN_10013080(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_100130b0 at 100130b0

undefined4 FUN_100130b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_100130e0 at 100130e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100130e0(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  uint uStack_130;
  undefined4 *local_120 [5];
  undefined4 *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10027a45;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  uStack_130 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_130;
  ExceptionList = &local_10;
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_3 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (undefined4 *)FUN_10024096(0x28);
  local_8._0_1_ = 1;
  if (local_10c == (undefined4 *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    uStack_130 = param_1;
    local_120[0] = FUN_10013a50(local_10c);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_100131b3();
  return uVar1;
}



// Function: Catch@100131ad at 100131ad

undefined * Catch_100131ad(void)

{
  return &DAT_100131bc;
}



// Function: FUN_100131b3 at 100131b3

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100131b3(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1001e750(*(void **)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 8));
    FUN_1001ac00();
    uVar1 = FUN_1000a4d0(*(int *)(unaff_EBP + -0x24) + 4);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10019ff0();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_1001ac80();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x24))
                        (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100132d0 at 100132d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100132d0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == 0) {
    local_c8[0] = FUN_10019750(0,param_2,param_3);
  }
  else {
    local_c8[0] = FUN_10019370(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_10013340 at 10013340

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10013340(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == 0) {
    local_c8[0] = FUN_10019930(0,param_2,param_3);
  }
  else {
    local_c8[0] = FUN_10019560(param_1,param_2,param_3);
  }
  return local_c8[0];
}



// Function: FUN_100133b0 at 100133b0

undefined4 __cdecl FUN_100133b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}



// Function: FUN_100133e0 at 100133e0

undefined4 __cdecl FUN_100133e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}



// Function: FUN_10013410 at 10013410

void FUN_10013410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10013440 at 10013440

void FUN_10013440(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10013470 at 10013470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __cdecl FUN_10013470(undefined4 *param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_d4 [49];
  undefined8 local_10;
  
  puVar4 = local_d4;
  for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  lVar1 = (ulonglong)param_2 * (ulonglong)param_3;
  local_10._4_4_ = (int)((ulonglong)lVar1 >> 0x20);
  if (local_10._4_4_ == 0) {
    local_10._0_4_ = (undefined4)lVar1;
    *param_1 = (undefined4)local_10;
    uVar2 = 0;
  }
  else {
    local_10 = lVar1;
    uVar2 = FUN_1000f730(0x216);
  }
  return uVar2;
}



// Function: FUN_100134e0 at 100134e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __cdecl FUN_100134e0(undefined4 *param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_d4 [49];
  undefined8 local_10;
  
  puVar4 = local_d4;
  for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  lVar1 = (ulonglong)param_2 * (ulonglong)param_3;
  local_10._4_4_ = (int)((ulonglong)lVar1 >> 0x20);
  if (local_10._4_4_ == 0) {
    local_10._0_4_ = (undefined4)lVar1;
    *param_1 = (undefined4)local_10;
    uVar2 = 0;
  }
  else {
    local_10 = lVar1;
    uVar2 = FUN_1000f730(0x216);
  }
  return uVar2;
}



// Function: FUN_10013550 at 10013550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10013550(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  uint local_18;
  undefined4 local_c [2];
  
  puVar3 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = FUN_10013470(local_c,param_1,param_2);
  uVar2 = extraout_EDX;
  if ((int)local_18 < 0) {
    FUN_10006cf0(local_18);
    uVar2 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100135bc);
  return CONCAT44(uVar2,local_c[0]);
}



// Function: FUN_100135e0 at 100135e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_100135e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027058;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10013f00(param_1);
  local_8 = 0;
  FUN_1001ab80();
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013660 at 10013660

undefined4 * __fastcall FUN_10013660(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100136a0 at 100136a0

undefined4 * __fastcall FUN_100136a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100136e0 at 100136e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100136e0(void *this,undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027096;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_1000fe10(this);
  FUN_10013ae0(local_18 + 1);
  local_8 = 0;
  *local_18 = ATL::CComAggObject<class_CSymbolicTreeComponent>::vftable;
  FUN_10013860(local_18 + 3,param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_1003387c + 4))(uVar1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100137a0 at 100137a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100137a0(void *this,undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100270d6;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_1000fe10(this);
  FUN_10013ae0(local_18 + 1);
  local_8 = 0;
  *local_18 = ATL::CComAggObject<class_CSymbolicTreeNode>::vftable;
  FUN_10013900(local_18 + 3,param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_1003387c + 4))(uVar1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013860 at 10013860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10013860(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027108;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_10014390((int)this);
  *local_18 = ATL::CComContainedObject<class_CSymbolicTreeComponent>::vftable;
  local_18[1] = ATL::CComContainedObject<class_CSymbolicTreeComponent>::vftable;
  local_18[2] = param_1;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013900 at 10013900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10013900(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027138;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  FUN_1000fc40((int)this);
  *local_18 = ATL::CComContainedObject<class_CSymbolicTreeNode>::vftable;
  local_18[1] = ATL::CComContainedObject<class_CSymbolicTreeNode>::vftable;
  local_18[2] = param_1;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100139a0 at 100139a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100139a0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027168;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10014390((int)param_1);
  local_8 = 0;
  *local_18 = ATL::CComObject<class_CSymbolicTreeComponent>::vftable;
  local_18[1] = ATL::CComObject<class_CSymbolicTreeComponent>::vftable;
  (**(code **)(*DAT_1003387c + 4))(uVar1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013a50 at 10013a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10013a50(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027198;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10013fe0(param_1);
  *local_18 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013ae0 at 10013ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10013ae0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100271c8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fb70(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013b60 at 10013b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10013b60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100271f8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10013c60(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013be0 at 10013be0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10013be0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027228;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10013ca0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013c60 at 10013c60

undefined4 * __fastcall FUN_10013c60(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013ca0 at 10013ca0

undefined4 * __fastcall FUN_10013ca0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013ce0 at 10013ce0

undefined4 * __fastcall FUN_10013ce0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10013d30 at 10013d30

undefined4 * __fastcall FUN_10013d30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013d70 at 10013d70

undefined4 * __fastcall FUN_10013d70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013db0 at 10013db0

undefined4 * __fastcall FUN_10013db0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013df0 at 10013df0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10013df0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10014440(param_1);
  return local_c;
}



// Function: FUN_10013e40 at 10013e40

undefined4 * __thiscall FUN_10013e40(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10013e80 at 10013e80

undefined4 * __thiscall FUN_10013e80(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10013ec0 at 10013ec0

undefined4 * __fastcall FUN_10013ec0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013f00 at 10013f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10013f00(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002725b;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10014530(param_1 + 4);
  local_8 = 0;
  *(undefined4 *)(local_18 + 4) = 0;
  *(undefined4 *)(local_18 + 0xc) = 0;
  *(undefined4 *)(local_18 + 8) = 0;
  DAT_1003387c = local_18;
  *(undefined4 *)(local_18 + 0x28) = 0;
  uVar1 = FUN_10009570((LPCRITICAL_SECTION)(local_18 + 0x10));
  if ((int)uVar1 < 0) {
    DAT_10033890 = 1;
  }
  else {
    *(undefined4 *)(local_18 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10013fe0 at 10013fe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10013fe0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002728b;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10014490(param_1);
  FUN_1000f960(local_18 + 1);
  *local_18 = ATL::CComClassFactory::vftable;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10014070 at 10014070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10014070(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100272b8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_100135e0((int)param_1);
  *local_18 = ATL::CComModule::vftable;
  _DAT_10033894 = local_18;
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10014100 at 10014100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10014100(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100272e8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_10013ce0(param_1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10014180 at 10014180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10014180(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  local_c = (undefined4 *)this;
  uVar3 = FUN_100170a0(*(uint *)((int)this + 4),1);
  local_c[2] = (int)uVar3;
  if (local_c[2] != 0) {
    *(undefined1 *)local_c[2] = 0;
  }
  return local_c;
}



// Function: FUN_10014210 at 10014210

undefined4 * __thiscall FUN_10014210(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return (undefined4 *)this;
}



// Function: FUN_10014260 at 10014260

undefined4 * __thiscall FUN_10014260(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100142b0 at 100142b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_100142b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002731b;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_100144e0(param_1);
  *local_18 = ATL::CRegObject::vftable;
  FUN_10014100(local_18 + 1);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10014340 at 10014340

undefined4 * __thiscall FUN_10014340(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)this = 0;
  return (undefined4 *)this;
}



// Function: FUN_10014390 at 10014390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10014390(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027361;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000f960((undefined4 *)(param_1 + 8));
  local_8 = 0;
  FUN_1000fdc0(local_18);
  FUN_10013df0(local_18 + 4);
  FUN_10003230((undefined4 *)(local_18 + 0x28));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10013ec0((undefined4 *)(local_18 + 0x2c));
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10014440 at 10014440

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10014440(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fd70(param_1);
  return local_c;
}



// Function: FUN_10014490 at 10014490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10014490(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fe10(param_1);
  return local_c;
}



// Function: FUN_100144e0 at 100144e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100144e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1000fe10(param_1);
  return local_c;
}



// Function: FUN_10014530 at 10014530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10014530(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002738b;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_1000fb20((void *)(param_1 + 0xc));
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100145b0 at 100145b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100145b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100273b8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10014e00(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014630 at 10014630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014630(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1001a1d0(param_1);
  return;
}



// Function: FUN_10014670 at 10014670

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014670(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1001a230(param_1);
  return;
}



// Function: FUN_100146b0 at 100146b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100146b0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100273f6;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CSymbolicTreeComponent>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  local_18 = param_1;
  FUN_1001a070();
  (**(code **)(*DAT_1003387c + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_10014830((int)(local_18 + 3));
  local_8 = 0xffffffff;
  FUN_10014a90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014770 at 10014770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014770(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10027436;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CSymbolicTreeNode>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  local_18 = param_1;
  FUN_1001a0c0();
  (**(code **)(*DAT_1003387c + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_100148b0((int)(local_18 + 3));
  local_8 = 0xffffffff;
  FUN_10014a90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014830 at 10014830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014830(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027468;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10015140(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100148b0 at 100148b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100148b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027498;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10010090(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014930 at 10014930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014930(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100274c8;
  local_10 = ExceptionList;
  puVar3 = local_dc;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CSymbolicTreeComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CSymbolicTreeComponent>::vftable;
  local_8 = 0;
  param_1[2] = 0xc0000001;
  local_18 = param_1;
  FUN_10007a40((int)param_1);
  (**(code **)(*DAT_1003387c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10015140((int)local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100149f0 at 100149f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100149f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100274f8;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  local_18 = param_1;
  FUN_1001a110();
  local_8 = 0xffffffff;
  FUN_10014e90(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014a90 at 10014a90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10014a90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027528;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000ffc0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014b10 at 10014b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014b10(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027558;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10014c10(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014b90 at 10014b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014b90(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027588;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_10014c70(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014c10 at 10014c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014c10(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10014c70 at 10014c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014c70(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    local_c = param_1;
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10014cd0 at 10014cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014cd0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1001d8f0(param_1);
  return;
}



// Function: FUN_10014d10 at 10014d10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014d10(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((int *)*param_1 != param_1 + 1) {
    local_c = param_1;
    FUN_1001a290(param_1);
  }
  return;
}



// Function: FUN_10014d60 at 10014d60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014d60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((int *)*param_1 != param_1 + 1) {
    local_c = param_1;
    FUN_1001a2e0(param_1);
  }
  return;
}



// Function: FUN_10014db0 at 10014db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014db0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((int *)*param_1 != param_1 + 1) {
    local_c = param_1;
    FUN_1001a330(param_1);
  }
  return;
}



// Function: FUN_10014e00 at 10014e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014e00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100275bb;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = param_1;
  FUN_1001e9e0(param_1);
  local_8 = 0xffffffff;
  FUN_100151e0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014e90 at 10014e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014e90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100275eb;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_1000fe40((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014f20 at 10014f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014f20(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027618;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  local_18 = param_1;
  FUN_100145b0((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014fa0 at 10014fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014fa0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027648;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = param_1;
  FUN_100190b0(param_1);
  local_8 = 0xffffffff;
  FUN_10014cd0(local_18);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015020 at 10015020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015020(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10015070 at 10015070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015070(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100191c0(param_1);
  return;
}



// Function: FUN_100150b0 at 100150b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100150b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002767b;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  local_18 = param_1;
  FUN_10019160((int)param_1);
  local_8 = 0xffffffff;
  FUN_10014fa0(local_18 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015140 at 10015140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015140(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100276c1;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = param_1;
  FUN_1000fed0((int *)(param_1 + 0x2c));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004c80((int *)(local_18 + 0x28));
  local_8 = 0xffffffff;
  FUN_1000fe40(local_18 + 8);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100151e0 at 100151e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100151e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [51];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100276eb;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000ff90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015260 at 10015260

bool __fastcall FUN_10015260(int *param_1)

{
  int iVar1;
  bool *pbVar2;
  bool local_d4 [208];
  
  pbVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = true;
    pbVar2[1] = true;
    pbVar2[2] = true;
    pbVar2[3] = true;
    pbVar2 = pbVar2 + 4;
  }
  return *param_1 == 0;
}



// Function: FUN_100152b0 at 100152b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100152b0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10015260(param_1);
  return;
}



// Function: FUN_10015300 at 10015300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __fastcall FUN_10015300(int *param_1)

{
  char cVar1;
  int iVar2;
  bool *pbVar3;
  bool local_d4 [200];
  int *local_c;
  
  pbVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    pbVar3[0] = true;
    pbVar3[1] = true;
    pbVar3[2] = true;
    pbVar3[3] = true;
    pbVar3 = pbVar3 + 4;
  }
  local_c = param_1;
  cVar1 = FUN_100152b0(param_1);
  return cVar1 == '\0';
}



// Function: FUN_10015370 at 10015370

undefined4 __fastcall FUN_10015370(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_100153a0 at 100153a0

undefined4 __fastcall FUN_100153a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_100153d0 at 100153d0

undefined4 __fastcall FUN_100153d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10015400 at 10015400

undefined4 __fastcall FUN_10015400(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10015430 at 10015430

undefined4 __fastcall FUN_10015430(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10015460 at 10015460

undefined4 __fastcall FUN_10015460(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_10015490 at 10015490

undefined4 __fastcall FUN_10015490(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *param_1;
}



// Function: FUN_100154c0 at 100154c0

undefined4 __fastcall FUN_100154c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_100154f0 at 100154f0

undefined4 __fastcall FUN_100154f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



// Function: FUN_10015520 at 10015520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015520(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100146b0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10015580 at 10015580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015580(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10014770((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100155e0 at 100155e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100155e0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_100148b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10015640 at 10015640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015640(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10014930((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100156a0 at 100156a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100156a0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100149f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10015700 at 10015700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015700(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10014e90((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10015760 at 10015760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015760(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_10014f20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_100157c0 at 100157c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100157c0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  FUN_100150b0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(local_c);
  }
  return local_c;
}



// Function: FUN_10015820 at 10015820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10015820(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_e8 [49];
  void *local_24;
  void *local_18;
  undefined4 *local_c;
  
  puVar3 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = (undefined4 *)this;
  local_18 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (local_18 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    *local_c = local_18;
    local_24 = _recalloc((void *)local_c[1],local_c[2] + 1,4);
    if (local_24 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      local_c[1] = local_24;
      FUN_1001ad40(local_c,local_c[2],param_1,param_2);
      local_c[2] = local_c[2] + 1;
      uVar1 = 1;
    }
  }
  return uVar1;
}



// Function: FUN_10015900 at 10015900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10015900(void *param_1,undefined4 param_2,char *param_3,wchar_t *param_4)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  uint *puVar4;
  uint local_158 [2];
  void *local_150;
  void *local_144;
  uint local_138;
  undefined4 local_6c [3];
  void *local_60 [3];
  uint local_54;
  undefined4 local_48 [3];
  void *local_3c [3];
  uint local_30;
  int local_24;
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027720;
  local_10 = ExceptionList;
  puVar4 = local_158;
  for (iVar3 = 0x52; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  if ((param_3 == (char *)0x0) || (param_4 == (wchar_t *)0x0)) {
    uVar2 = 0;
  }
  else {
    local_24 = 0;
    sVar1 = strlen(param_3);
    local_30 = sVar1 + 1;
    local_3c[0] = (void *)0x0;
    local_150 = (void *)FUN_100240c4(local_30);
    local_3c[0] = local_150;
    FUN_10013660(local_48);
    local_8 = 0;
    FUN_10018ea0(local_48,local_3c[0]);
    sVar1 = FUN_1000e9c0(param_4);
    local_54 = sVar1 * 2 + 2;
    local_60[0] = (void *)0x0;
    local_144 = (void *)FUN_100240c4(-(uint)((int)((ulonglong)local_54 * 2 >> 0x20) != 0) |
                                     (uint)((ulonglong)local_54 * 2));
    local_60[0] = local_144;
    FUN_100136a0(local_6c);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10018ee0(local_6c,local_60[0]);
    if ((local_3c[0] == (void *)0x0) || (local_60[0] == (void *)0x0)) {
      local_24 = -0x7ff8fff2;
    }
    else {
      FUN_100200b0(local_3c[0],local_30,param_3,local_30);
      FUN_100200b0(local_60[0],local_54,param_4,local_54);
      iVar3 = FUN_10015820(local_18,local_3c,local_60);
      if (iVar3 == 0) {
        local_24 = -0x7ff8fff2;
      }
    }
    if (-1 < local_24) {
      FUN_10019cd0(local_48);
      FUN_10019d10(local_6c);
    }
    local_158[0] = (uint)(-1 < local_24);
    local_138 = local_158[0];
    local_8 = local_8 & 0xffffff00;
    FUN_10014670(local_6c);
    local_8 = 0xffffffff;
    FUN_10014630(local_48);
    uVar2 = local_138;
    param_2 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10015b0c);
  ExceptionList = local_10;
  return CONCAT44(param_2,uVar2);
}



// Function: FUN_10015b60 at 10015b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10015b60(LPCSTR param_1)

{
  LPSTR pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_dc [49];
  int *local_18;
  void *local_c;
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  pCVar1 = CharNextA(param_1);
  local_18 = (int *)(pCVar1 + -(int)param_1);
  uVar4 = FUN_10016ea0(local_c,param_1,local_18);
  return uVar4;
}



// Function: FUN_10015bd0 at 10015bd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015bd0(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [51];
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  puVar1 = FUN_1001a3c0();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",puVar1);
  return;
}



// Function: FUN_10015c30 at 10015c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015c30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001abb0((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10015c70 at 10015c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015c70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001abb0((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10015cb0 at 10015cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015cb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b4f0((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10015cef at 10015cef

void FUN_10015cef(int param_1)

{
  FUN_10015cb0(param_1 + -4);
  return;
}



// Function: FUN_10015d00 at 10015d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015d00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b4f0((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10015d3f at 10015d3f

void FUN_10015d3f(int param_1)

{
  FUN_10015d00(param_1 + -4);
  return;
}



// Function: FUN_10015d50 at 10015d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015d50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009760((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10015d8f at 10015d8f

void FUN_10015d8f(int param_1)

{
  FUN_10015d50(param_1 + -4);
  return;
}



// Function: FUN_10015da0 at 10015da0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015da0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = FUN_10009760((LONG *)(param_1 + 4));
  if (local_c == 2) {
    (**(code **)(*DAT_1003387c + 4))();
  }
  return local_c;
}



// Function: FUN_10015e10 at 10015e10

undefined4 FUN_10015e10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 1;
}



// Function: FUN_10015e40 at 10015e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10015e40(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  char cVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  LPSTR extraout_EDX;
  LPSTR pCVar6;
  LPSTR *ppCVar7;
  undefined8 uVar8;
  LPSTR local_160 [2];
  int local_158;
  LPSTR local_154;
  char *local_150;
  undefined4 local_148;
  char *local_13c;
  _RTC_ALLOCA_NODE *local_70 [3];
  int local_64;
  char *local_58;
  int local_4c [6];
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027748;
  local_10 = ExceptionList;
  ppCVar7 = local_160;
  for (iVar5 = 0x54; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70[0] = (_RTC_ALLOCA_NODE *)0x0;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    FUN_1001b080();
    local_28 = FUN_1000a4a0();
    FUN_10002640(local_4c);
    local_8 = 0;
    local_34 = param_2;
    if (param_2 == (wchar_t *)0x0) {
      local_150 = (char *)0x0;
      pCVar6 = extraout_EDX;
    }
    else {
      sVar3 = wcslen(param_2);
      local_1c[0] = sVar3 + 1;
      uVar4 = FUN_100014b0(local_1c,local_1c[0],2);
      if ((int)uVar4 < 0) {
        local_154 = (LPSTR)0x0;
      }
      else {
        if (((int)local_1c[0] < 0x401) && (cVar2 = FUN_1000a520(local_1c[0]), cVar2 != '\0')) {
          local_158 = local_1c[0] + 0x24;
          iVar5 = -(local_1c[0] + 0x24);
          local_160[1] = &stack0xfffffe8c;
          *(_RTC_ALLOCA_NODE ***)((int)local_160 + iVar5 + -0x18) = local_70;
          iVar1 = local_158;
          pCVar6 = local_160[1];
          *(undefined4 *)((int)local_160 + iVar5 + -0x1c) = 0x10015f69;
          _RTC_AllocaHelper(pCVar6,iVar1,*(undefined4 **)((int)local_160 + iVar5 + -0x18));
          local_160[0] = local_160[1] + 0x20;
          local_160[1] = local_160[0];
        }
        else {
          local_160[0] = (LPSTR)FUN_10006820(local_1c[0]);
        }
        local_154 = FUN_10006d50(local_160[0],local_34,local_1c[0],local_28);
      }
      local_150 = local_154;
      pCVar6 = local_154;
    }
    local_58 = local_150;
    if (local_150 == (char *)0x0) {
      local_148 = 0x8007000e;
      local_8 = 0xffffffff;
      FUN_100043e0(local_4c);
    }
    else {
      uVar8 = FUN_10015900((void *)(param_1 + 4),pCVar6,local_150,param_3);
      local_64 = (int)uVar8;
      FUN_1001ebe0();
      if (local_64 == 0) {
        local_150 = (char *)0x8007000e;
      }
      else {
        local_150 = (char *)0x0;
      }
      local_13c = local_150;
      local_8 = 0xffffffff;
      FUN_100043e0(local_4c);
    }
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10016080,local_70[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100160e0 at 100160e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_100160e0(void *this,wchar_t *param_1)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  LPSTR *ppCVar8;
  undefined8 uVar9;
  LPSTR local_160 [2];
  int local_158;
  LPSTR local_154;
  char *local_150;
  undefined4 local_148;
  undefined4 local_13c;
  _RTC_ALLOCA_NODE *local_70 [3];
  char *local_64;
  int local_58 [6];
  wchar_t *local_40;
  UINT local_34;
  uint local_28 [3];
  void *local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027778;
  local_10 = ExceptionList;
  ppCVar8 = local_160;
  for (iVar7 = 0x54; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppCVar8 = (LPSTR)0xcccccccc;
    ppCVar8 = ppCVar8 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_1c = this;
  if (param_1 != (wchar_t *)0x0) {
    local_34 = FUN_1000a4a0();
    FUN_10002640(local_58);
    local_8 = 0;
    local_40 = param_1;
    if (param_1 == (wchar_t *)0x0) {
      local_150 = (char *)0x0;
    }
    else {
      sVar4 = wcslen(param_1);
      local_28[0] = sVar4 + 1;
      uVar5 = FUN_100014b0(local_28,local_28[0],2);
      if ((int)uVar5 < 0) {
        local_154 = (LPSTR)0x0;
      }
      else {
        if (((int)local_28[0] < 0x401) && (cVar3 = FUN_1000a520(local_28[0]), cVar3 != '\0')) {
          local_158 = local_28[0] + 0x24;
          iVar7 = -(local_28[0] + 0x24);
          local_160[1] = &stack0xfffffe8c;
          *(_RTC_ALLOCA_NODE ***)((int)local_160 + iVar7 + -0x18) = local_70;
          iVar2 = local_158;
          pCVar1 = local_160[1];
          *(undefined4 *)((int)local_160 + iVar7 + -0x1c) = 0x100161fa;
          _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_160 + iVar7 + -0x18));
          local_160[0] = local_160[1] + 0x20;
          local_160[1] = local_160[0];
        }
        else {
          local_160[0] = (LPSTR)FUN_10006820(local_28[0]);
        }
        local_154 = FUN_10006d50(local_160[0],local_40,local_28[0],local_34);
      }
      local_150 = local_154;
    }
    local_64 = local_150;
    if (local_150 == (char *)0x0) {
      local_148 = 0;
      local_8 = 0xffffffff;
      FUN_100043e0(local_58);
    }
    else {
      piVar6 = (int *)strlen(local_150);
      uVar9 = FUN_10016ea0(local_1c,local_64,piVar6);
      local_13c = (undefined4)uVar9;
      local_8 = 0xffffffff;
      FUN_100043e0(local_58);
    }
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_100162e8,local_70[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016350 at 10016350

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_10016350(void *this,void *param_1,LPCSTR param_2,undefined1 *param_3)

{
  LPWSTR pWVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPCSTR unaff_EDI;
  LPWSTR *ppWVar7;
  uint uStack_1424;
  LPWSTR local_1414 [2];
  int iStack_140c;
  LPWSTR pWStack_1408;
  LPWSTR local_1404;
  undefined4 uStack_13fc;
  _RTC_ALLOCA_NODE *local_1324 [6];
  undefined4 auStack_130c [67];
  uint uStack_1200;
  size_t sStack_11f4;
  LPWSTR pWStack_11e8;
  int aiStack_11dc [3];
  BYTE *pBStack_11d0;
  UINT UStack_11b8;
  uint auStack_11ac [15];
  undefined4 local_1170 [67];
  uint local_1064;
  undefined4 local_1058;
  uint local_104c;
  ushort local_1040 [6];
  BYTE local_1034 [4104];
  int local_2c;
  undefined4 *local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100277c1;
  local_10 = ExceptionList;
  ppWVar7 = local_1414;
  for (iVar6 = 0x500; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  uStack_1424 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1424;
  ExceptionList = &local_10;
  local_1324[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_1040[0] = 0;
  local_104c = 0;
  local_1058 = 0;
  local_20 = (undefined4 *)this;
  local_18 = uStack_1424;
  local_2c = FUN_1001b190(this,local_1034);
  if (-1 < local_2c) {
    iVar6 = FUN_1001fcd0((LPCSTR)local_1034,local_1040);
    if (iVar6 == 0) {
      FUN_1001a380();
    }
    else {
      FUN_1001e880(local_20);
      local_2c = FUN_1001b190(local_20,local_1034);
      if (-1 < local_2c) {
        local_1404 = (LPWSTR)(uint)local_1040[0];
        if (local_1404 < (LPWSTR)0x14) {
          if (local_1404 == (LPWSTR)0x13) {
            UStack_11b8 = FUN_1000a4a0();
            FUN_10002640(aiStack_11dc);
            local_8 = 3;
            pBStack_11d0 = local_1034;
            if (pBStack_11d0 == (BYTE *)0x0) {
              local_1404 = (LPWSTR)0x0;
            }
            else {
              sVar4 = strlen((char *)pBStack_11d0);
              auStack_11ac[0] = sVar4 + 1;
              uVar5 = FUN_100014b0(auStack_11ac,auStack_11ac[0],2);
              if ((int)uVar5 < 0) {
                pWStack_1408 = (LPWSTR)0x0;
              }
              else {
                if (((int)auStack_11ac[0] < 0x401) &&
                   (cVar3 = FUN_1000a520(auStack_11ac[0]), cVar3 != '\0')) {
                  iStack_140c = auStack_11ac[0] + 0x24;
                  iVar6 = -(auStack_11ac[0] + 0x24);
                  local_14 = (undefined1 *)&uStack_1424;
                  local_1414[1] = (LPWSTR)&uStack_1424;
                  *(_RTC_ALLOCA_NODE ***)((int)local_1414 + iVar6 + -0x14) = local_1324;
                  iVar2 = iStack_140c;
                  pWVar1 = local_1414[1];
                  *(undefined4 *)((int)local_1414 + iVar6 + -0x18) = 0x1001679a;
                  _RTC_AllocaHelper((undefined1 *)pWVar1,iVar2,
                                    *(undefined4 **)((int)local_1414 + iVar6 + -0x14));
                  local_1414[0] = (LPWSTR)((int)local_1414[1] + 0x20);
                  local_1414[1] = local_1414[0];
                }
                else {
                  local_1414[0] = (LPWSTR)FUN_10006820(auStack_11ac[0]);
                }
                pWStack_1408 = FUN_100068f0(local_1414[0],(LPCSTR)pBStack_11d0,auStack_11ac[0] >> 1,
                                            UStack_11b8);
              }
              local_1404 = pWStack_1408;
            }
            pWStack_11e8 = local_1404;
            if (local_1404 == (LPWSTR)0x0) {
              uStack_13fc = 0x8007000e;
              local_8 = 0xffffffff;
              FUN_100043e0(aiStack_11dc);
              goto LAB_10016a72;
            }
            Ordinal_277(local_1404,0);
            uStack_1424 = 0x10016859;
            local_104c = FUN_1001e570(param_1,param_2);
            local_8 = 0xffffffff;
            FUN_100043e0(aiStack_11dc);
          }
          else if (local_1404 == (LPWSTR)0x8) {
            local_104c = FUN_1001e6a0(param_2,local_1034,1);
          }
          else if (local_1404 == (LPWSTR)0x11) {
            sStack_11f4 = strlen((char *)local_1034);
            if ((sStack_11f4 & 1) == 0) {
              uStack_1200 = (int)sStack_11f4 / 2;
              FUN_10013db0(auStack_130c);
              local_8 = 5;
              FUN_10016c10(uStack_1200);
              FUN_100168f4();
              return;
            }
            goto LAB_10016a72;
          }
        }
        else if (local_1404 == (LPWSTR)0x4008) {
          sVar4 = strlen((char *)local_1034);
          local_1064 = sVar4 + 2;
          FUN_10013d30(local_1170);
          local_8 = 1;
          FUN_10016b70(local_1064);
          FUN_100164ef(unaff_EDI);
          return;
        }
        if (local_104c == 0) {
          local_2c = FUN_1001b190(local_20,param_3);
        }
        else {
          local_1058 = 0x204;
          FUN_10017950(local_104c);
        }
      }
    }
  }
LAB_10016a72:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10016ab0,local_1324[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100164e9 at 100164e9

undefined * Catch_100164e9(void)

{
  return &DAT_100164f8;
}



// Function: FUN_100164ef at 100164ef

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_100164ef(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  LPSTR pCVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  LSTATUS LVar7;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  iVar2 = FUN_100153a0((undefined4 *)(unaff_EBP - 0x116c));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1048) = 0xe;
  }
  else {
    uVar3 = FUN_100153a0((undefined4 *)(unaff_EBP - 0x116c));
    *(undefined4 *)(unaff_EBP - 0x1178) = uVar3;
    *(uint *)(unaff_EBP - 0x1184) = unaff_EBP - 0x1030;
    *(undefined4 *)(unaff_EBP - 0x1060) = 0;
    while (**(char **)(unaff_EBP - 0x1184) != '\0') {
      pCVar4 = CharNextA(param_1);
      param_1 = (LPCSTR)0x10016560;
      *(LPSTR *)(unaff_EBP - 0x1190) = pCVar4;
      if ((**(char **)(unaff_EBP - 0x1184) == '\\') && (**(char **)(unaff_EBP - 0x1190) == '0')) {
        **(undefined1 **)(unaff_EBP - 0x1178) = 0;
        *(int *)(unaff_EBP - 0x1178) = *(int *)(unaff_EBP - 0x1178) + 1;
        pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1190));
        *(LPSTR *)(unaff_EBP - 0x1184) = pCVar4;
      }
      else {
        **(undefined1 **)(unaff_EBP - 0x1178) = **(undefined1 **)(unaff_EBP - 0x1184);
        BVar5 = IsDBCSLeadByte(**(BYTE **)(unaff_EBP - 0x1184));
        if (BVar5 != 0) {
          *(int *)(unaff_EBP - 0x1178) = *(int *)(unaff_EBP - 0x1178) + 1;
          *(int *)(unaff_EBP - 0x1184) = *(int *)(unaff_EBP - 0x1184) + 1;
          if (**(char **)(unaff_EBP - 0x1184) == '\0') break;
          **(undefined1 **)(unaff_EBP - 0x1178) = **(undefined1 **)(unaff_EBP - 0x1184);
        }
        *(int *)(unaff_EBP - 0x1178) = *(int *)(unaff_EBP - 0x1178) + 1;
        *(int *)(unaff_EBP - 0x1184) = *(int *)(unaff_EBP - 0x1184) + 1;
      }
      *(int *)(unaff_EBP - 0x1060) = *(int *)(unaff_EBP - 0x1060) + 1;
    }
    **(undefined1 **)(unaff_EBP - 0x1178) = 0;
    *(int *)(unaff_EBP - 0x1178) = *(int *)(unaff_EBP - 0x1178) + 1;
    **(undefined1 **)(unaff_EBP - 0x1178) = 0;
    pBVar6 = (BYTE *)FUN_100153a0((undefined4 *)(unaff_EBP - 0x116c));
    LVar7 = FUN_1001e5d0(*(LPCSTR *)(unaff_EBP + 0xc),pBVar6);
    *(LSTATUS *)(unaff_EBP - 0x1048) = LVar7;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10014d10((int *)(unaff_EBP - 0x116c));
  if (*(int *)(unaff_EBP - 0x1048) == 0) {
    uVar3 = FUN_1001b190(*(void **)(unaff_EBP - 0x1c),*(undefined1 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x28) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x1054) = 0x204;
    FUN_10017950(*(uint *)(unaff_EBP - 0x1048));
  }
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_10016ab0,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x1320));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1414) = 0x10016aa7;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: Catch@100168ee at 100168ee

undefined * Catch_100168ee(void)

{
  return &DAT_100168fd;
}



// Function: FUN_100168f4 at 100168f4

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_100168f4(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  BYTE *lpData;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint unaff_EBP;
  LPCSTR lpValueName;
  DWORD Reserved;
  DWORD dwType;
  size_t _Size;
  DWORD cbData;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  iVar1 = FUN_10015400((undefined4 *)(unaff_EBP - 0x1308));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x13ec) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    FUN_10014db0((int *)(unaff_EBP - 0x1308));
  }
  else {
    _Size = *(size_t *)(unaff_EBP - 0x11fc);
    iVar1 = 0;
    _Dst = (void *)FUN_10015400((undefined4 *)(unaff_EBP - 0x1308));
    memset(_Dst,iVar1,_Size);
    *(undefined4 *)(unaff_EBP - 0x1314) = 0;
    while (*(int *)(unaff_EBP - 0x1314) < *(int *)(unaff_EBP - 0x11f0)) {
      iVar1 = FUN_10015400((undefined4 *)(unaff_EBP - 0x1308));
      *(int *)(unaff_EBP - 0x1400) = iVar1 + *(int *)(unaff_EBP - 0x1314) / 2;
      uVar2 = FUN_10018ff0(*(char *)((unaff_EBP - 0x1030) + *(int *)(unaff_EBP - 0x1314)));
      **(byte **)(unaff_EBP - 0x1400) =
           **(byte **)(unaff_EBP - 0x1400) |
           (byte)((uVar2 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x1314) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x1314) = *(int *)(unaff_EBP - 0x1314) + 1;
    }
    cbData = *(DWORD *)(unaff_EBP - 0x11fc);
    lpData = (BYTE *)FUN_10015400((undefined4 *)(unaff_EBP - 0x1308));
    dwType = 3;
    Reserved = 0;
    lpValueName = *(LPCSTR *)(unaff_EBP + 0xc);
    hKey = (HKEY)FUN_10015430(*(undefined4 **)(unaff_EBP + 8));
    LVar3 = RegSetValueExA(hKey,lpValueName,Reserved,dwType,lpData,cbData);
    *(LSTATUS *)(unaff_EBP - 0x1048) = LVar3;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    FUN_10014db0((int *)(unaff_EBP - 0x1308));
    if (*(int *)(unaff_EBP - 0x1048) == 0) {
      uVar4 = FUN_1001b190(*(void **)(unaff_EBP - 0x1c),*(undefined1 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x28) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x1054) = 0x204;
      FUN_10017950(*(uint *)(unaff_EBP - 0x1048));
    }
  }
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_10016ab0,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x1320));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar2 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1414) = 0x10016aa7;
  __security_check_cookie(uVar2 ^ unaff_EBP);
  return;
}



// Function: FUN_10016b70 at 10016b70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016b70(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10013550(param_1,1);
  FUN_10016c60(local_c,(uint)uVar3);
  return;
}



// Function: FUN_10016bc0 at 10016bc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016bc0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10013550(param_1,1);
  FUN_10016cc0(local_c,(uint)uVar3);
  return;
}



// Function: FUN_10016c10 at 10016c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016c10(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_10013550(param_1,1);
  FUN_10016d20(local_c,(uint)uVar3);
  return;
}



// Function: FUN_10016c60 at 10016c60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10016c60(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10016d80(param_1);
  }
  return *local_c;
}



// Function: FUN_10016cc0 at 10016cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10016cc0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if (param_1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10016de0(param_1);
  }
  return *local_c;
}



// Function: FUN_10016d20 at 10016d20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10016d20(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (undefined4 *)this;
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10016e40(param_1);
  }
  return *local_c;
}



// Function: FUN_10016d80 at 10016d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016d80(size_t param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = FUN_100068a0(param_1);
  if (local_18 == 0) {
    FUN_10006cf0(0x8007000e);
  }
  *local_c = local_18;
  return;
}



// Function: FUN_10016de0 at 10016de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016de0(size_t param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = FUN_100068a0(param_1);
  if (local_18 == 0) {
    FUN_10006cf0(0x8007000e);
  }
  *local_c = local_18;
  return;
}



// Function: FUN_10016e40 at 10016e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016e40(size_t param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = FUN_100068a0(param_1);
  if (local_18 == 0) {
    FUN_10006cf0(0x8007000e);
  }
  *local_c = local_18;
  return;
}



// Function: FUN_10016ea0 at 10016ea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10016ea0(void *this,void *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_e8 [49];
  int local_24;
  int local_18;
  int *local_c;
  
  puVar4 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_18 = *this + 1 + (int)param_2;
                    /* WARNING: Load size is inaccurate */
  piVar3 = param_2;
  if ((*this < local_18) && ((int)param_2 < local_18)) {
    local_c = (int *)this;
    if (*(int *)((int)this + 4) <= local_18) {
      while (*(int *)((int)this + 4) <= local_18) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          uVar1 = 0;
          goto LAB_10016fcb;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
        piVar3 = (int *)this;
      }
      uVar5 = FUN_10017140(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),1);
      piVar3 = (int *)((ulonglong)uVar5 >> 0x20);
      local_24 = (int)uVar5;
      if (local_24 == 0) {
        uVar1 = 0;
        goto LAB_10016fcb;
      }
      local_c[2] = local_24;
    }
    if (((*local_c < 0) || (piVar3 = (int *)*local_c, local_c[1] <= (int)piVar3)) ||
       (piVar3 = (int *)(local_c[1] - *local_c), local_c[1] < (int)piVar3)) {
      uVar1 = 0;
    }
    else {
      FUN_100200b0((void *)(local_c[2] + *local_c),local_c[1] - *local_c,param_1,(rsize_t)param_2);
      *local_c = *local_c + (int)param_2;
      *(undefined1 *)(local_c[2] + *local_c) = 0;
      uVar1 = 1;
      piVar3 = local_c;
    }
  }
  else {
    uVar1 = 0;
  }
LAB_10016fcb:
  return CONCAT44(piVar3,uVar1);
}



// Function: FUN_10016ff0 at 10016ff0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10016ff0(int param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_e8 [52];
  undefined4 *local_18;
  undefined4 *local_c;
  
  ppuVar2 = local_e8;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  if (param_1 == 0) {
    FUN_1001ff10(0xc0000005,1);
  }
  local_c = *(undefined4 **)(param_1 + 8);
  local_18 = (undefined4 *)0x0;
  while (local_c != (undefined4 *)0x0) {
    (*(code *)*local_c)(local_c[1]);
    local_18 = (undefined4 *)local_c[2];
    local_e8[1] = local_c;
    operator_delete(local_c);
    local_c = local_18;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_100170a0 at 100170a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_100170a0(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_dc [49];
  SIZE_T local_18 [3];
  uint local_c;
  
  puVar4 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18[0] = 0;
  local_c = FUN_100134e0(local_18,param_1,param_2);
  if ((int)local_c < 0) {
    pvVar1 = (LPVOID)0x0;
    uVar3 = extraout_EDX;
  }
  else {
    pvVar1 = CoTaskMemAlloc(local_18[0]);
    uVar3 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10017120);
  return CONCAT44(uVar3,pvVar1);
}



// Function: FUN_10017140 at 10017140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10017140(LPVOID param_1,uint param_2,uint param_3)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_dc [49];
  SIZE_T local_18 [3];
  uint local_c;
  
  puVar4 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18[0] = 0;
  local_c = FUN_100134e0(local_18,param_2,param_3);
  if ((int)local_c < 0) {
    pvVar1 = (LPVOID)0x0;
    uVar3 = extraout_EDX;
  }
  else {
    pvVar1 = CoTaskMemRealloc(param_1,local_18[0]);
    uVar3 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_100171c4);
  return CONCAT44(uVar3,pvVar1);
}



// Function: FUN_100171e0 at 100171e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_100171e0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,undefined4 param_5,
            int *param_6)

{
  uint uVar1;
  PVOID pvVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_128 [49];
  undefined4 *local_64;
  PVOID local_58 [3];
  undefined4 local_4c [4];
  int *local_3c;
  undefined4 *local_30;
  int *local_24;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100277f8;
  local_10 = ExceptionList;
  puVar5 = local_128;
  for (iVar3 = 0x46; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_6 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    *param_6 = 0;
    if (param_3 == (int *)0x0) {
      iVar3 = -0x7ff8ffa9;
    }
    else if (*param_3 == 0) {
      iVar3 = -0x7fff0001;
    }
    else {
      local_18 = 0;
      for (local_24 = (int *)param_3[2]; uVar6 = CONCAT44(param_2,local_18),
          local_24 < (int *)param_3[3]; local_24 = local_24 + 1) {
        if (((*local_24 != 0) && (local_30 = (undefined4 *)*local_24, local_30[2] != 0)) &&
           (iVar3 = FUN_1000f790(param_4,(int *)*local_30), param_2 = extraout_EDX, iVar3 != 0)) {
          local_3c = (int *)local_30[4];
          uVar4 = extraout_EDX;
          if (*local_3c == 0) {
            FUN_10002680(local_4c,param_3 + 4,'\0');
            local_8 = 0;
            local_18 = FUN_10009e80(local_4c);
            if (local_18 < 0) {
              local_8 = 0xffffffff;
              FUN_10004450(local_4c);
              uVar6 = CONCAT44(extraout_EDX_00,local_18);
              break;
            }
            if (*local_3c == 0) {
              local_18 = (*(code *)local_30[2])(local_30[3],&DAT_10029418,local_58,uVar1);
              uVar1 = 0x10017338;
              if (-1 < local_18) {
                pvVar2 = EncodePointer(local_58[0]);
                uVar1 = 0x10017354;
                *local_3c = (int)pvVar2;
              }
            }
            local_8 = 0xffffffff;
            FUN_10004450(local_4c);
            uVar4 = extraout_EDX_01;
          }
          uVar6 = CONCAT44(uVar4,local_18);
          if (*local_3c != 0) {
            local_64 = (undefined4 *)DecodePointer((PVOID)*local_3c);
            uVar6 = (**(code **)*local_64)(local_64,param_5,param_6,0x10017385,uVar1);
          }
          break;
        }
      }
      param_2 = (undefined4)((ulonglong)uVar6 >> 0x20);
      local_18 = (int)uVar6;
      iVar3 = local_18;
      if ((*param_6 == 0) && (local_18 == 0)) {
        local_18 = -0x7ffbfeef;
        iVar3 = local_18;
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100173fc);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar3);
}



// Function: FUN_10017430 at 10017430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10017430(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_e8 [49];
  undefined4 *local_24;
  int *local_18;
  int local_c;
  
  puVar4 = local_e8;
  for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == 0) {
    local_c = -0x7ff8ffa9;
  }
  else {
    local_c = 0;
    for (local_18 = *(int **)(param_1 + 8); local_18 < *(int **)(param_1 + 0xc);
        local_18 = local_18 + 1) {
      if ((*local_18 != 0) &&
         ((local_24 = (undefined4 *)*local_18, param_3 == (void *)0x0 ||
          (bVar1 = FUN_100204d0(param_3,(void *)*local_24), CONCAT31(extraout_var,bVar1) != 0)))) {
        local_c = (*(code *)local_24[1])(1);
        if (local_c < 0) break;
        piVar2 = (int *)(*(code *)local_24[6])(1,0x100174c5);
        local_c = FUN_10018120((GUID *)*local_24,piVar2,0x100174e3);
        if (local_c < 0) break;
      }
    }
    if ((-1 < local_c) && (param_2 != 0)) {
      local_c = FUN_10018890(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_c;
}



// Function: FUN_10017540 at 10017540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10017540(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_e8 [49];
  undefined4 *local_24;
  int *local_18;
  int local_c;
  
  puVar4 = local_e8;
  for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == 0) {
    local_c = -0x7ff8ffa9;
  }
  else {
    local_c = 0;
    for (local_18 = *(int **)(param_1 + 8); local_18 < *(int **)(param_1 + 0xc);
        local_18 = local_18 + 1) {
      if ((*local_18 != 0) &&
         ((local_24 = (undefined4 *)*local_18, param_3 == (void *)0x0 ||
          (bVar1 = FUN_100204d0(param_3,(void *)*local_24), CONCAT31(extraout_var,bVar1) != 0)))) {
        piVar2 = (int *)(*(code *)local_24[6])(0);
        local_c = FUN_10018120((GUID *)*local_24,piVar2,0x100175d5);
        if ((local_c < 0) || (local_c = (*(code *)local_24[1])(0), local_c < 0)) break;
      }
    }
    if ((-1 < local_c) && (param_2 != 0)) {
      uVar5 = FUN_10018c20(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
      local_c = (int)uVar5;
    }
  }
  return local_c;
}



// Function: FUN_10017650 at 10017650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __cdecl FUN_10017650(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c8[0] = param_1;
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10006cf0(0x80004005);
    break;
  case 0xc:
    FUN_10006cf0(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10006cf0(0x80070057);
  }
  return param_1;
}



// Function: FUN_10017740 at 10017740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCSTR __cdecl FUN_10017740(LPSTR param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_d4 [200];
  LPCSTR local_c;
  
  pcVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar3[0] = -0x34;
    pcVar3[1] = -0x34;
    pcVar3[2] = -0x34;
    pcVar3[3] = -0x34;
    pcVar3 = pcVar3 + 4;
  }
  if (param_1 == (LPSTR)0x0) {
    local_c = (LPCSTR)0x0;
  }
  else {
    local_c = (LPCSTR)0x0;
    for (; *param_1 != '\0'; param_1 = CharNextA(param_1)) {
      cVar1 = *param_1;
      local_d4[0] = cVar1;
      if (cVar1 == '.') {
        local_c = param_1;
      }
      else if (cVar1 == '\\') {
        local_c = (LPCSTR)0x0;
      }
    }
    if (local_c == (LPCSTR)0x0) {
      local_c = param_1;
    }
  }
  return local_c;
}



// Function: FUN_10017800 at 10017800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10017800(LPWSTR param_1)

{
  WCHAR WVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_e8 [49];
  LPWSTR local_24;
  LPWSTR local_18;
  LPWSTR local_c;
  
  puVar3 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == (LPWSTR)0x0) {
    iVar2 = 0;
  }
  else {
    local_c = param_1;
    local_18 = param_1;
    while (*local_18 != L'\0') {
      local_24 = CharNextW(local_18);
      if (((*local_18 == L'\\') || (*local_18 == L'/')) ||
         (WVar1 = *local_18, local_18 = local_24, WVar1 == L':')) {
        local_18 = local_24;
        local_c = local_24;
      }
    }
    iVar2 = (int)local_c - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_100178b0 at 100178b0

undefined4 FUN_100178b0(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_100338a0;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10017900 at 10017900

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10017900(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  DWORD local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = GetLastError();
  FUN_1000f730(local_c);
  return;
}



// Function: FUN_10017950 at 10017950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10017950(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000f730(param_1);
  return;
}



// Function: FUN_10017990 at 10017990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10017990(HMODULE param_1,wchar_t *param_2,int *param_3,undefined4 *param_4)

{
  LPWSTR pWVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPWSTR *ppWVar7;
  LPWSTR local_318 [2];
  int local_310;
  LPWSTR local_30c;
  LPWSTR local_308;
  undefined4 local_300;
  uint local_2f4;
  undefined4 local_2e8;
  undefined4 local_2dc;
  undefined4 local_2d0;
  undefined4 local_2c4;
  undefined4 local_2b8;
  int local_2ac;
  _RTC_ALLOCA_NODE *local_1e0 [3];
  char local_1d4 [16];
  int local_1c4;
  LPWSTR local_1b8;
  uint local_1ac;
  size_t local_1a0;
  LPWSTR local_194;
  LPCSTR local_188;
  undefined4 local_17c;
  DWORD local_170;
  CHAR local_164 [280];
  int local_4c [3];
  char *local_40;
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027828;
  local_10 = ExceptionList;
  ppWVar7 = local_318;
  for (iVar6 = 0xc2; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1e0[0] = (_RTC_ALLOCA_NODE *)0x0;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_28 = FUN_1000a4a0();
    FUN_10002640(local_4c);
    local_8 = 0;
    local_170 = GetModuleFileNameA(param_1,local_164,0x104);
    if (local_170 == 0) {
      local_300 = FUN_10017900();
      local_8 = 0xffffffff;
      local_17c = local_300;
      FUN_100043e0(local_4c);
    }
    else if (local_170 == 0x104) {
      local_2f4 = FUN_1000f730(0x7a);
      local_8 = 0xffffffff;
      FUN_100043e0(local_4c);
    }
    else {
      local_188 = (LPCSTR)0x0;
      local_188 = FUN_10017740(local_164);
      if (param_2 != (wchar_t *)0x0) {
        local_34 = param_2;
        if (param_2 == (wchar_t *)0x0) {
          local_308 = (LPWSTR)0x0;
        }
        else {
          sVar4 = wcslen(param_2);
          local_1c[0] = sVar4 + 1;
          uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
          if ((int)uVar5 < 0) {
            local_30c = (LPWSTR)0x0;
          }
          else {
            if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000a520(local_1c[0]), cVar3 != '\0')) {
              local_310 = local_1c[0] + 0x24;
              iVar6 = -(local_1c[0] + 0x24);
              local_318[1] = (LPWSTR)&stack0xfffffcd0;
              *(_RTC_ALLOCA_NODE ***)((int)local_318 + iVar6 + -0x1c) = local_1e0;
              iVar2 = local_310;
              pWVar1 = local_318[1];
              *(undefined4 *)((int)local_318 + iVar6 + -0x20) = 0x10017b86;
              _RTC_AllocaHelper((undefined1 *)pWVar1,iVar2,
                                *(undefined4 **)((int)local_318 + iVar6 + -0x1c));
              local_318[0] = (LPWSTR)((int)local_318[1] + 0x20);
              local_318[1] = local_318[0];
            }
            else {
              local_318[0] = (LPWSTR)FUN_10006820(local_1c[0]);
            }
            local_30c = (LPWSTR)FUN_10006d50((LPSTR)local_318[0],local_34,local_1c[0],local_28);
          }
          local_308 = local_30c;
        }
        local_194 = local_308;
        if (local_308 == (LPWSTR)0x0) {
          local_2e8 = 0x8007000e;
          local_8 = 0xffffffff;
          FUN_100043e0(local_4c);
          goto LAB_10018057;
        }
        local_1a0 = strlen((char *)local_308);
        local_1ac = local_170 + local_1a0;
        if (((local_1ac < local_170) || (local_1ac < local_1a0)) || (0x10d < local_1ac)) {
          local_2dc = 0x80004005;
          local_8 = 0xffffffff;
          FUN_100043e0(local_4c);
          goto LAB_10018057;
        }
        FUN_10020200(local_164 + local_170,0x10e - local_170,(char *)local_194);
      }
      local_40 = local_164;
      if (local_40 == (char *)0x0) {
        local_308 = (LPWSTR)0x0;
      }
      else {
        sVar4 = strlen(local_40);
        local_1c[0] = sVar4 + 1;
        uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
        if ((int)uVar5 < 0) {
          local_30c = (LPWSTR)0x0;
        }
        else {
          if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000a520(local_1c[0]), cVar3 != '\0')) {
            local_310 = local_1c[0] + 0x24;
            local_318[1] = (LPWSTR)&stack0xfffffcd0;
            _RTC_AllocaHelper(&stack0xfffffcd0,local_310,local_1e0);
            local_318[0] = (LPWSTR)((int)local_318[1] + 0x20);
            local_318[1] = local_318[0];
          }
          else {
            local_318[0] = (LPWSTR)FUN_10006820(local_1c[0]);
          }
          local_30c = FUN_100068f0(local_318[0],local_40,local_1c[0] >> 1,local_28);
        }
        local_308 = local_30c;
      }
      local_1b8 = local_308;
      if (local_308 == (LPWSTR)0x0) {
        local_2d0 = 0x8007000e;
        local_8 = 0xffffffff;
        FUN_100043e0(local_4c);
      }
      else {
        local_1c4 = Ordinal_161();
        if (local_1c4 < 0) {
          builtin_strncpy(local_1d4,".tlb",5);
          if ((char *)0x104 < local_188 + (5 - (int)local_164)) {
            local_2c4 = 0x80004005;
            local_8 = 0xffffffff;
            FUN_100043e0(local_4c);
            goto LAB_10018057;
          }
          FUN_10020200(local_188,0x10e - ((int)local_188 - (int)local_164),local_1d4);
          local_40 = local_164;
          if (local_40 == (char *)0x0) {
            local_308 = (LPWSTR)0x0;
          }
          else {
            sVar4 = strlen(local_40);
            local_1c[0] = sVar4 + 1;
            uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
            if ((int)uVar5 < 0) {
              local_30c = (LPWSTR)0x0;
            }
            else {
              if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000a520(local_1c[0]), cVar3 != '\0'))
              {
                local_310 = local_1c[0] + 0x24;
                local_318[1] = (LPWSTR)&stack0xfffffcd0;
                _RTC_AllocaHelper(&stack0xfffffcd0,local_310,local_1e0);
                local_318[0] = (LPWSTR)((int)local_318[1] + 0x20);
                local_318[1] = local_318[0];
              }
              else {
                local_318[0] = (LPWSTR)FUN_10006820(local_1c[0]);
              }
              local_30c = FUN_100068f0(local_318[0],local_40,local_1c[0] >> 1,local_28);
            }
            local_308 = local_30c;
          }
          local_1b8 = local_308;
          if (local_308 == (LPWSTR)0x0) {
            local_2b8 = 0x8007000e;
            local_8 = 0xffffffff;
            FUN_100043e0(local_4c);
            goto LAB_10018057;
          }
          local_1c4 = Ordinal_161();
        }
        if (-1 < local_1c4) {
          iVar6 = Ordinal_2();
          *param_3 = iVar6;
          if (*param_3 == 0) {
            local_1c4 = -0x7ff8fff2;
            (**(code **)(*(int *)*param_4 + 8))();
            *param_4 = 0;
          }
        }
        local_2ac = local_1c4;
        local_8 = 0xffffffff;
        FUN_100043e0(local_4c);
      }
    }
  }
LAB_10018057:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10018094,local_1e0[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018120 at 10018120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10018120(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  LPVOID *ppv;
  size_t sVar3;
  uint uVar4;
  HKEY pHVar5;
  int iVar6;
  LPSTR *ppCVar7;
  undefined8 uVar8;
  LPSTR pCVar9;
  LPDWORD pDVar10;
  LPDWORD pDVar11;
  DWORD *pDVar12;
  LPDWORD pDVar13;
  LPDWORD pDVar14;
  LPDWORD pDVar15;
  LPDWORD pDVar16;
  LPDWORD pDVar17;
  char *pcVar18;
  LPDWORD pDVar19;
  REGSAM RVar20;
  PFILETIME p_Var21;
  LPSTR local_304 [2];
  int local_2fc;
  int *local_2f8;
  int *local_2f4;
  undefined4 local_2ec;
  undefined4 local_2e0;
  undefined4 local_2d4;
  int local_2c8;
  undefined4 local_2bc;
  _RTC_ALLOCA_NODE *local_1f0 [3];
  int local_1e4;
  DWORD local_1d8 [3];
  int local_1cc [5];
  int local_1b8 [5];
  char local_1a4 [136];
  int *local_11c;
  int local_110 [6];
  wchar_t *local_f8;
  UINT local_ec;
  uint local_e0 [3];
  OLECHAR local_d4 [68];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int *local_34;
  HRESULT local_28;
  int local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027879;
  local_10 = ExceptionList;
  ppCVar7 = local_304;
  for (iVar6 = 0xbd; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1f0[0] = (_RTC_ALLOCA_NODE *)0x0;
  FUN_10013b60(local_1c);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    local_2ec = 0;
    local_8 = 0xffffffff;
    FUN_10014b10(local_1c);
  }
  else {
    iVar6 = FUN_1000f790((int *)param_1,(int *)&DAT_1002b878);
    if (iVar6 == 0) {
      ppv = (LPVOID *)FUN_100154c0(local_1c);
      local_28 = CoCreateInstance((IID *)&DAT_1002c5c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_10029828,ppv);
      if (local_28 < 0) {
        local_2d4 = 0;
        local_8 = 0xffffffff;
        FUN_10014b10(local_1c);
      }
      else {
        local_28 = 0;
        for (local_34 = param_2; *local_34 != 0; local_34 = local_34 + 2) {
          puVar1 = (undefined4 *)local_34[1];
          local_4c = *puVar1;
          local_48 = puVar1[1];
          local_44 = puVar1[2];
          local_40 = puVar1[3];
          if (param_3 == 0) {
            if (*local_34 == 1) {
              local_2f4 = (int *)FUN_10015460(local_1c);
              (**(code **)(*local_2f4 + 0x18))(local_2f4,param_1,1,&local_4c);
            }
            else {
              local_2f4 = (int *)FUN_10015460(local_1c);
              (**(code **)(*local_2f4 + 0x20))(local_2f4,param_1,1,&local_4c);
            }
          }
          else {
            if (*local_34 == 1) {
              local_2f4 = (int *)FUN_10015460(local_1c);
              local_28 = (**(code **)(*local_2f4 + 0x14))(local_2f4,param_1,1,&local_4c);
            }
            else {
              local_2f4 = (int *)FUN_10015460(local_1c);
              local_28 = (**(code **)(*local_2f4 + 0x1c))(local_2f4,param_1,1,&local_4c);
            }
            if (local_28 < 0) {
              local_2c8 = local_28;
              local_8 = 0xffffffff;
              FUN_10014b10(local_1c);
              goto LAB_10018769;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_d4,0x40);
          local_ec = FUN_1000a4a0();
          FUN_10002640(local_110);
          local_8._0_1_ = 1;
          local_f8 = local_d4;
          if (local_f8 == (wchar_t *)0x0) {
            local_2f4 = (int *)0x0;
          }
          else {
            sVar3 = wcslen(local_f8);
            local_e0[0] = sVar3 + 1;
            uVar4 = FUN_100014b0(local_e0,local_e0[0],2);
            if ((int)uVar4 < 0) {
              local_2f8 = (int *)0x0;
            }
            else {
              if (((int)local_e0[0] < 0x401) && (cVar2 = FUN_1000a520(local_e0[0]), cVar2 != '\0'))
              {
                local_2fc = local_e0[0] + 0x24;
                local_304[1] = &stack0xfffffce8;
                _RTC_AllocaHelper(&stack0xfffffce8,local_2fc,local_1f0);
                local_304[0] = local_304[1] + 0x20;
                local_304[1] = local_304[0];
              }
              else {
                local_304[0] = (LPSTR)FUN_10006820(local_e0[0]);
              }
              local_2f8 = (int *)FUN_10006d50(local_304[0],local_f8,local_e0[0],local_ec);
            }
            local_2f4 = local_2f8;
          }
          local_11c = local_2f4;
          if (local_2f4 != (int *)0x0) {
            FUN_10020200(local_1a4,0x80,"CLSID\\");
            FUN_100201a0(local_1a4,0x80,(char *)local_11c);
            FUN_100201a0(local_1a4,0x80,"\\Required Categories");
            FUN_10014210(local_1b8,0x80000000);
            local_8._0_1_ = 2;
            FUN_10014260(local_1cc,0);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_1d8[0] = 0;
            RVar20 = 0x20019;
            pcVar18 = local_1a4;
            pHVar5 = (HKEY)FUN_10015430(local_1b8);
            uVar8 = FUN_1001b400(local_1cc,pHVar5,pcVar18,RVar20);
            local_1e4 = (int)uVar8;
            if (local_1e4 == 0) {
              p_Var21 = (PFILETIME)0x0;
              pDVar19 = (LPDWORD)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = local_1d8;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pCVar9 = (LPSTR)0x0;
              pHVar5 = (HKEY)FUN_10015430(local_1cc);
              local_1e4 = RegQueryInfoKeyA(pHVar5,pCVar9,pDVar10,pDVar11,pDVar12,pDVar13,pDVar14,
                                           pDVar15,pDVar16,pDVar17,pDVar19,p_Var21);
              FUN_100191c0(local_1cc);
              if ((local_1e4 == 0) && (local_1d8[0] == 0)) {
                FUN_10019bf0(local_1b8,local_1a4);
              }
            }
            FUN_10020200(local_1a4,0x80,"CLSID\\");
            FUN_100201a0(local_1a4,0x80,(char *)local_11c);
            FUN_100201a0(local_1a4,0x80,"\\Implemented Categories");
            RVar20 = 0x20019;
            pcVar18 = local_1a4;
            pHVar5 = (HKEY)FUN_10015430(local_1b8);
            uVar8 = FUN_1001b400(local_1cc,pHVar5,pcVar18,RVar20);
            local_1e4 = (int)uVar8;
            if (local_1e4 == 0) {
              p_Var21 = (PFILETIME)0x0;
              pDVar19 = (LPDWORD)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = local_1d8;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pCVar9 = (LPSTR)0x0;
              pHVar5 = (HKEY)FUN_10015430(local_1cc);
              local_1e4 = RegQueryInfoKeyA(pHVar5,pCVar9,pDVar10,pDVar11,pDVar12,pDVar13,pDVar14,
                                           pDVar15,pDVar16,pDVar17,pDVar19,p_Var21);
              FUN_100191c0(local_1cc);
              if ((local_1e4 == 0) && (local_1d8[0] == 0)) {
                FUN_10019bf0(local_1b8,local_1a4);
              }
            }
            local_8._0_1_ = 2;
            FUN_10015070(local_1cc);
            local_8._0_1_ = 1;
            FUN_10015070(local_1b8);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100043e0(local_110);
        }
        local_2bc = 0;
        local_8 = 0xffffffff;
        FUN_10014b10(local_1c);
      }
    }
    else {
      local_2e0 = 0;
      local_8 = 0xffffffff;
      FUN_10014b10(local_1c);
    }
  }
LAB_10018769:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_100187a4,local_1f0[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018890 at 10018890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x100189d7) */

void FUN_10018890(HMODULE param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  rsize_t rVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int **ppiVar9;
  wchar_t *pwVar10;
  int *local_378 [5];
  uint local_364;
  int local_358;
  int local_34c;
  HMODULE local_280;
  char local_271 [9];
  FARPROC local_268;
  wchar_t *local_25c [3];
  wchar_t local_250 [259];
  undefined2 uStack_4a;
  wchar_t *local_40;
  int local_34;
  int local_28 [3];
  undefined4 local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100278cb;
  local_10 = ExceptionList;
  ppiVar9 = local_378;
  for (iVar8 = 0xda; iVar8 != 0; iVar8 = iVar8 + -1) {
    *ppiVar9 = (int *)0xcccccccc;
    ppiVar9 = ppiVar9 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10003d30(local_1c);
  local_8 = 0;
  FUN_10013be0(local_28);
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)FUN_100154f0(local_28);
  piVar3 = (int *)FUN_10006200(local_1c);
  local_34 = FUN_10017990(param_1,param_2,piVar3,puVar2);
  if (-1 < local_34) {
    local_40 = (wchar_t *)0x0;
    FUN_10003d30(local_25c);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_378[0] = (int *)FUN_10015490(local_28);
    uVar4 = FUN_10006200(local_25c);
    local_34 = (**(code **)(*local_378[0] + 0x24))(local_378[0],0xffffffff,0,0,0,uVar4);
    uVar4 = 0x1001896c;
    if ((-1 < local_34) && (bVar1 = FUN_10015300((int *)local_25c), bVar1)) {
      rVar5 = FUN_1001afe0(local_25c);
      FUN_100202c0(local_250,0x104,local_25c[0],rVar5);
      local_378[2] = (int *)0x206;
      uStack_4a = 0;
      iVar8 = FUN_10017800(local_250);
      local_364 = iVar8 << 1;
      if (0x207 < local_364) {
        ___report_rangecheckfailure();
      }
      *(undefined2 *)((int)local_250 + local_364) = 0;
      local_40 = local_250;
    }
    local_268 = (FARPROC)0x0;
    local_271[0] = '\0';
    local_34 = FUN_100178b0(local_271);
    if (local_34 < 0) {
      local_8._0_1_ = 1;
      local_358 = local_34;
      FUN_10001000(local_25c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10014b90(local_28);
      local_8 = 0xffffffff;
      FUN_10001000(local_1c);
      goto LAB_10018b5e;
    }
    if (local_271[0] == '\x01') {
      local_280 = GetModuleHandleW(L"OLEAUT32.DLL");
      uVar4 = 0x10018ab9;
      if (local_280 != (HMODULE)0x0) {
        local_268 = GetProcAddress(local_280,"RegisterTypeLibForUser");
        uVar4 = 0x10018ae3;
      }
    }
    if (local_268 == (FARPROC)0x0) {
      local_268 = Ordinal_163_exref;
    }
    pwVar10 = local_40;
    uVar6 = FUN_10005dc0(local_1c);
    uVar7 = FUN_10015370(local_28);
    local_34 = (*local_268)(uVar7,uVar6,pwVar10,uVar4);
    local_8._0_1_ = 1;
    FUN_10001000(local_25c);
  }
  local_34c = local_34;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10014b90(local_28);
  local_8 = 0xffffffff;
  FUN_10001000(local_1c);
LAB_10018b5e:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10018b9c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018c20 at 10018c20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10018c20(HMODULE param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int **ppiVar4;
  undefined4 uVar5;
  int *local_140 [2];
  int local_138;
  int local_12c;
  HMODULE local_60;
  char local_51 [9];
  FARPROC local_48;
  int local_3c [3];
  int local_30;
  int local_24 [3];
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027910;
  local_10 = ExceptionList;
  ppiVar4 = local_140;
  for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar4 = (int *)0xcccccccc;
    ppiVar4 = ppiVar4 + 1;
  }
  ExceptionList = &local_10;
  FUN_10003d30(local_18);
  local_8 = 0;
  FUN_10013be0(local_24);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_100154f0(local_24);
  piVar2 = (int *)FUN_10006200(local_18);
  local_30 = FUN_10017990(param_1,param_2,piVar2,puVar1);
  if (-1 < local_30) {
    local_140[0] = (int *)FUN_10015490(local_24);
    local_30 = (**(code **)(*local_140[0] + 0x1c))(local_140[0],local_3c);
    uVar5 = 0x10018cd3;
    if (-1 < local_30) {
      local_48 = (FARPROC)0x0;
      local_51[0] = '\0';
      local_30 = FUN_100178b0(local_51);
      if (local_30 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        local_138 = local_30;
        FUN_10014b90(local_24);
        local_8 = 0xffffffff;
        FUN_10001000(local_18);
        iVar3 = local_138;
        uVar5 = extraout_EDX;
        goto LAB_10018e05;
      }
      if (local_51[0] == '\x01') {
        local_60 = GetModuleHandleW(L"OLEAUT32.DLL");
        uVar5 = 0x10018d49;
        if (local_60 != (HMODULE)0x0) {
          local_48 = GetProcAddress(local_60,"UnRegisterTypeLibForUser");
          uVar5 = 0x10018d6a;
        }
      }
      if (local_48 == (FARPROC)0x0) {
        local_48 = Ordinal_186_exref;
      }
      local_30 = (*local_48)(local_3c[0],(uint)*(ushort *)(local_3c[0] + 0x18),
                             (uint)*(ushort *)(local_3c[0] + 0x1a),
                             *(undefined4 *)(local_3c[0] + 0x10),*(undefined4 *)(local_3c[0] + 0x14)
                             ,uVar5);
      uVar5 = 0x10018da9;
      local_140[0] = (int *)FUN_10015490(local_24);
      (**(code **)(*local_140[0] + 0x30))(local_140[0],local_3c[0],uVar5);
    }
  }
  local_12c = local_30;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10014b90(local_24);
  local_8 = 0xffffffff;
  FUN_10001000(local_18);
  iVar3 = local_12c;
  uVar5 = extraout_EDX_00;
LAB_10018e05:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10018e38);
  ExceptionList = local_10;
  return CONCAT44(uVar5,iVar3);
}



// Function: FUN_10018ea0 at 10018ea0

void __thiscall FUN_10018ea0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10018ee0 at 10018ee0

void __thiscall FUN_10018ee0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10018f20 at 10018f20

void __thiscall FUN_10018f20(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10018f70 at 10018f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10018f70(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = 0;
  while( true ) {
    if (0xb < local_18) {
      return 1;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_s_AppID_1002a1cc)[local_18]);
    if (iVar1 == 0) break;
    local_18 = local_18 + 1;
  }
  return 0;
}



// Function: FUN_10018ff0 at 10018ff0

uint __cdecl FUN_10018ff0(char param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c8 [49];
  
  puVar3 = local_c8;
  for (iVar2 = 0x31; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  switch(param_1) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    uVar1 = (int)param_1 - 0x30;
    break;
  default:
    uVar1 = 0;
    break;
  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
    uVar1 = (int)param_1 - 0x37;
    break;
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
    uVar1 = (int)param_1 - 0x57;
  }
  return uVar1;
}



// Function: FUN_100190b0 at 100190b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100190b0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void **ppvVar3;
  void *local_f4 [4];
  void *local_e4;
  int local_18;
  int *local_c;
  
  ppvVar3 = local_f4;
  for (iVar2 = 0x3c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppvVar3 = (void *)0xcccccccc;
    ppvVar3 = ppvVar3 + 1;
  }
  local_18 = 0;
  local_c = param_1;
  while( true ) {
    iVar2 = FUN_1001a790((int)local_c);
    if (iVar2 <= local_18) break;
    puVar1 = (undefined4 *)FUN_1001a6f0(local_c,local_18);
    local_f4[1] = (void *)*puVar1;
    operator_delete__(local_f4[1]);
    puVar1 = (undefined4 *)FUN_1001a850(local_c,local_18);
    local_e4 = (void *)*puVar1;
    operator_delete__(local_e4);
    local_18 = local_18 + 1;
  }
  FUN_1001d8f0(local_c);
  return 0;
}



// Function: FUN_10019160 at 10019160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019160(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b080();
  local_c = FUN_100190b0((int *)(param_1 + 4));
  FUN_1001ebe0();
  return local_c;
}



// Function: FUN_100191c0 at 100191c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __fastcall FUN_100191c0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  LSTATUS local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = 0;
  local_c = param_1;
  if (*param_1 != 0) {
    local_18 = RegCloseKey((HKEY)*param_1);
    *local_c = 0;
  }
  local_c[1] = 0;
  return local_18;
}



// Function: FUN_10019240 at 10019240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall
FUN_10019240(void *this,HKEY param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar2;
  int *piVar3;
  int local_f8 [50];
  LSTATUS local_30;
  HKEY local_24 [3];
  DWORD local_18 [3];
  int *local_c;
  
  piVar3 = local_f8;
  for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  local_24[0] = (HKEY)0x0;
  local_c = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_f8[0] = RegCreateKeyExA(param_1,param_2,0,param_3,param_4,param_5,param_6,local_24,
                                  local_18);
    uVar2 = extraout_EDX_00;
  }
  else {
    local_f8[0] = FUN_1001bfe0(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,
                               param_6,local_24,local_18);
    uVar2 = extraout_EDX;
  }
  local_30 = local_f8[0];
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_18[0];
  }
  if (local_f8[0] == 0) {
    local_30 = FUN_100191c0(local_c);
    *local_c = (int)local_24[0];
    uVar2 = extraout_EDX_01;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001933c);
  return CONCAT44(uVar2,local_30);
}



// Function: FUN_10019370 at 10019370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019370(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_120 [5];
  void *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10027945;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  local_14 = &stack0xfffffed0;
  ExceptionList = &local_10;
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_3 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (void *)FUN_10024096(0x3c);
  local_8._0_1_ = 1;
  if (local_10c == (void *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    local_120[0] = FUN_100136e0(local_10c,param_1);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_10019443();
  return uVar1;
}



// Function: Catch@1001943d at 1001943d

undefined * Catch_1001943d(void)

{
  return &DAT_1001944c;
}



// Function: FUN_10019443 at 10019443

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019443(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined8 uVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1000a0d0();
    FUN_1001ac00();
    iVar1 = FUN_1001fe00(*(int *)(unaff_EBP + -0x24));
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar3 = FUN_10019f50();
      *(int *)(unaff_EBP + -0x18) = (int)uVar3;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    FUN_1001ac80();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x24))
                        (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10019560 at 10019560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019560(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined4 *local_120 [5];
  void *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10027985;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  local_14 = &stack0xfffffed0;
  ExceptionList = &local_10;
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_3 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (void *)FUN_10024096(0x48);
  local_8._0_1_ = 1;
  if (local_10c == (void *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    local_120[0] = FUN_100137a0(local_10c,param_1);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_10019633();
  return uVar1;
}



// Function: Catch@1001962d at 1001962d

undefined * Catch_1001962d(void)

{
  return &DAT_1001963c;
}



// Function: FUN_10019633 at 10019633

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019633(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined8 uVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1000a0d0();
    FUN_1001ac00();
    iVar1 = FUN_1001fe60(*(int *)(unaff_EBP + -0x24));
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar3 = FUN_10019fa0();
      *(int *)(unaff_EBP + -0x18) = (int)uVar3;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    FUN_1001ac80();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x24))
                        (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10019750 at 10019750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019750(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  uint uStack_130;
  undefined4 *local_120 [5];
  undefined4 *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100279c5;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  uStack_130 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_130;
  ExceptionList = &local_10;
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_3 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (undefined4 *)FUN_10024096(0x30);
  local_8._0_1_ = 1;
  if (local_10c == (undefined4 *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    uStack_130 = param_1;
    local_120[0] = FUN_100139a0(local_10c);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_10019823();
  return uVar1;
}



// Function: Catch@1001981d at 1001981d

undefined * Catch_1001981d(void)

{
  return &DAT_1001982c;
}



// Function: FUN_10019823 at 10019823

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019823(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined8 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1000a0d0();
    FUN_1001ac30(*(int *)(unaff_EBP + -0x24));
    uVar1 = FUN_1000a4d0(*(int *)(unaff_EBP + -0x24) + 8);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = CSymbolicTreeComponent_FinalConstruct(*(int *)(unaff_EBP + -0x24));
      *(int *)(unaff_EBP + -0x18) = (int)uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_1001acb0(*(int *)(unaff_EBP + -0x24));
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x24))
                        (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10019930 at 10019930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019930(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 **ppuVar3;
  uint uStack_130;
  undefined4 *local_120 [5];
  undefined4 *local_10c;
  undefined4 *local_28;
  undefined4 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10027a05;
  local_10 = ExceptionList;
  ppuVar3 = local_120;
  for (iVar2 = 0x43; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar3 = (undefined4 *)0xcccccccc;
    ppuVar3 = ppuVar3 + 1;
  }
  uStack_130 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_130;
  ExceptionList = &local_10;
  if (param_3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_3 = 0;
  local_1c = 0x8007000e;
  local_28 = (undefined4 *)0x0;
  local_8 = 0;
  local_10c = (undefined4 *)FUN_10024096(0x3c);
  local_8._0_1_ = 1;
  if (local_10c == (undefined4 *)0x0) {
    local_120[0] = (undefined4 *)0x0;
  }
  else {
    uStack_130 = param_1;
    local_120[0] = FUN_100026f0(local_10c);
  }
  local_120[2] = local_120[0];
  local_8 = (uint)local_8._1_3_ << 8;
  local_28 = local_120[0];
  uVar1 = FUN_10019a03();
  return uVar1;
}



// Function: Catch@100199fd at 100199fd

undefined * Catch_100199fd(void)

{
  return &DAT_10019a0c;
}



// Function: FUN_10019a03 at 10019a03

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019a03(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined8 uVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    FUN_1000a0d0();
    FUN_100097b0(*(int *)(unaff_EBP + -0x24));
    uVar1 = FUN_1000a4d0(*(int *)(unaff_EBP + -0x24) + 8);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = CSymbolicTreeNode_FinalConstruct();
      *(int *)(unaff_EBP + -0x18) = (int)uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000a470();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_10009800(*(int *)(unaff_EBP + -0x24));
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x24))
                        (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0xf0) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0xfc) = *(undefined4 *)(unaff_EBP + -0xf0);
      if (*(int *)(unaff_EBP + -0xfc) == 0) {
        *(undefined4 *)(unaff_EBP + -0x11c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0xfc) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x11c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10019b10 at 10019b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10019b10(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = FUN_10009650(param_3), iVar1 != 0)) {
      local_c = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_c = 0x80040110;
    }
  }
  return local_c;
}



// Function: FUN_10019ba0 at 10019ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10019ba0(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10019bf0 at 10019bf0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10019bf0(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
    RegDeleteKeyA(*this,param_1);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_1001c0f0(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10019c70 at 10019c70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10019c70(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = this;
  RegDeleteValueA(*this,param_1);
  return;
}



// Function: FUN_10019cd0 at 10019cd0

undefined4 __fastcall FUN_10019cd0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10019d10 at 10019d10

undefined4 __fastcall FUN_10019d10(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10019d50 at 10019d50

undefined4 __fastcall FUN_10019d50(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = param_1[2];
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}



// Function: FUN_10019db0 at 10019db0

undefined4 __fastcall FUN_10019db0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [54];
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *param_1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return uVar1;
}



// Function: FUN_10019e10 at 10019e10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10019e10(undefined4 *param_1)

{
  LPSTR pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d4 [50];
  undefined4 *local_c;
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((*(char *)*param_1 == '\'') &&
     (local_c = param_1, pCVar1 = CharNextA((LPCSTR)*param_1), *pCVar1 != '\'')) {
    return 1;
  }
  return 0;
}



// Function: FUN_10019e90 at 10019e90

void __cdecl FUN_10019e90(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  uint local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 != 0) {
    local_c = 0;
    for (; (local_c < param_2 - 1U && (*param_3 != 0)); param_3 = param_3 + 1) {
      *param_1 = *param_3;
      psVar1 = param_1 + 1;
      if ((*param_3 == 0x27) && (local_c = local_c + 1, local_c < param_2 - 1U)) {
        *psVar1 = *param_3;
        psVar1 = param_1 + 2;
      }
      param_1 = psVar1;
      local_c = local_c + 1;
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10019f50 at 10019f50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10019f50(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10019ff0();
  uVar3 = CSymbolicTreeComponent_FinalConstruct(local_c + 0xc);
  return uVar3;
}



// Function: FUN_10019fa0 at 10019fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10019fa0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10019ff0();
  uVar3 = CSymbolicTreeNode_FinalConstruct();
  return uVar3;
}



// Function: FUN_10019ff0 at 10019ff0

undefined4 FUN_10019ff0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1001a020 at 1001a020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001a020(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001aa60();
  return;
}



// Function: FUN_1001a070 at 1001a070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001a070(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001a110();
  uVar3 = FUN_10007a40(local_c + 0xc);
  return uVar3;
}



// Function: FUN_1001a0c0 at 1001a0c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001a0c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001a110();
  FUN_10010880();
  return;
}



// Function: FUN_1001a110 at 1001a110

void FUN_1001a110(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1001a140 at 1001a140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001a140(void *this,undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_dc [49];
  int local_18;
  int *local_c;
  
  puVar3 = local_dc;
  for (iVar2 = 0x36; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = 0;
  local_c = (int *)this;
  while( true ) {
    if (local_c[2] <= local_18) {
      return -1;
    }
    bVar1 = FUN_1001aee0(*(LPCSTR *)(*local_c + local_18 * 4),(LPCSTR)*param_1);
    if (bVar1) break;
    local_18 = local_18 + 1;
  }
  return local_18;
}



// Function: FUN_1001a1d0 at 1001a1d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a1d0(undefined4 *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_dc [52];
  undefined4 *local_c;
  
  ppvVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_dc[1] = (void *)*param_1;
  local_c = param_1;
  operator_delete__(local_dc[1]);
  *local_c = 0;
  return;
}



// Function: FUN_1001a230 at 1001a230

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a230(undefined4 *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_dc [52];
  undefined4 *local_c;
  
  ppvVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar2 = (void *)0xcccccccc;
    ppvVar2 = ppvVar2 + 1;
  }
  local_dc[1] = (void *)*param_1;
  local_c = param_1;
  operator_delete__(local_dc[1]);
  *local_c = 0;
  return;
}



// Function: FUN_1001a290 at 1001a290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a290(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10007b20((void *)*param_1);
  return;
}



// Function: FUN_1001a2e0 at 1001a2e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a2e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10007b20((void *)*param_1);
  return;
}



// Function: FUN_1001a330 at 1001a330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001a330(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10007b20((void *)*param_1);
  return;
}



// Function: FUN_1001a380 at 1001a380

undefined4 FUN_1001a380(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x80020009;
}



// Function: FUN_1001a3c0 at 1001a3c0

undefined * FUN_1001a3c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &DAT_1002afd0;
}



// Function: FUN_1001a3f0 at 1001a3f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_1001a3f0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_104 [49];
  undefined4 local_40 [4];
  int *local_30;
  int local_24;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027a78;
  local_10 = ExceptionList;
  puVar4 = local_104;
  for (iVar2 = 0x3d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_5 = 0;
  local_24 = 0;
  local_18 = param_1;
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_30 = *(int **)(param_1 + 0x2c); *local_30 != 0; local_30 = local_30 + 9) {
      if ((local_30[2] != 0) &&
         (iVar2 = FUN_1000f790(param_3,(int *)*local_30), param_2 = extraout_EDX, iVar2 != 0)) {
        if (local_30[4] == 0) {
          FUN_10002680(local_40,&DAT_10033964,'\0');
          local_8 = 0;
          local_24 = FUN_10009e80(local_40);
          if (local_24 < 0) {
            local_8 = 0xffffffff;
            FUN_10004450(local_40);
            param_2 = extraout_EDX_00;
            break;
          }
          if (local_30[4] == 0) {
            local_24 = (*(code *)local_30[2])(local_30[3],&DAT_10029418,local_30 + 4,uVar1);
            uVar1 = 0x1001a4f9;
          }
          local_8 = 0xffffffff;
          FUN_10004450(local_40);
          param_2 = extraout_EDX_01;
        }
        if (local_30[4] != 0) {
          uVar5 = (*(code *)**(undefined4 **)local_30[4])(local_30[4],param_4,param_5,uVar1);
          param_2 = (undefined4)((ulonglong)uVar5 >> 0x20);
          local_24 = (int)uVar5;
        }
        break;
      }
    }
  }
  uVar5 = CONCAT44(param_2,local_24);
  if ((*param_5 == 0) && (uVar5 = CONCAT44(param_2,local_24), local_24 == 0)) {
    uVar5 = FUN_100171e0(param_4,param_3,(int *)&DAT_10033954,param_3,param_4,param_5);
  }
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  local_24 = (int)uVar5;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001a5a8);
  ExceptionList = local_10;
  return CONCAT44(uVar3,local_24);
}



// Function: FUN_1001a5d0 at 1001a5d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001a5d0(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == (undefined4 *)0x0) {
    local_18 = -0x7fffbffd;
  }
  else {
    local_18 = 0;
    local_c = this;
    if (*(int *)((int)this + 0x28) == 0) {
      local_18 = CoCreateInstance((IID *)&DAT_1002bab8,(LPUNKNOWN)0x0,1,(IID *)&DAT_10029474,
                                  (LPVOID *)((int)this + 0x28));
      this = (void *)0x1001a634;
    }
    if (-1 < local_18) {
      *param_1 = *(undefined4 *)((int)local_c + 0x28);
      (**(code **)(**(int **)((int)local_c + 0x28) + 4))(*(undefined4 *)((int)local_c + 0x28),this);
    }
  }
  return local_18;
}



// Function: FUN_1001a690 at 1001a690

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001a690(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10008b60(&PTR_DAT_10033500,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1001a6f0 at 1001a6f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001a6f0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (int *)this;
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    FUN_1001ff10(0xc000008c,1);
  }
  return *local_c + param_1 * 4;
}



// Function: FUN_1001a760 at 1001a760

undefined4 __fastcall FUN_1001a760(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1001a790 at 1001a790

undefined4 __fastcall FUN_1001a790(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1001a7c0 at 1001a7c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001a7c0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009450(&PTR_DAT_10033500,param_2,param_3,param_4);
  return;
}



// Function: FUN_1001a810 at 1001a810

undefined4 FUN_1001a810(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1001a850 at 1001a850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001a850(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    FUN_1001ff10(0xc000008c,1);
  }
  return *(int *)((int)local_c + 4) + param_1 * 4;
}



// Function: FUN_1001a8c0 at 1001a8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __cdecl FUN_1001a8c0(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  uint local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  while( true ) {
    if (0xd < local_c) {
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_1002ad48)[local_c * 2]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return *(undefined4 *)(&DAT_1002ad4c + local_c * 8);
}



// Function: FUN_1001a940 at 1001a940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1001a940(HKEY param_1)

{
  LSTATUS LVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  uint *puVar4;
  undefined4 uVar5;
  uint local_e0 [50];
  DWORD local_18 [5];
  
  puVar4 = local_e0;
  for (iVar3 = 0x37; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18[0] = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_18,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 == 0) {
    local_e0[0] = (uint)(local_18[0] != 0);
    uVar2 = local_e0[0];
  }
  else {
    uVar2 = 0;
  }
  uVar5 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001a9e8);
  return CONCAT44(uVar5,uVar2);
}



// Function: FUN_1001aa10 at 1001aa10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001aa10(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_1001aa60 at 1001aa60

undefined4 FUN_1001aa60(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1001aa90 at 1001aa90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_1001aa90(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e8 [49];
  int *local_24;
  int *local_18;
  void *local_c;
  
  puVar2 = local_e8;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    _DAT_10033880 = *param_3;
    _DAT_10033884 = param_3[1];
    _DAT_10033888 = param_3[2];
    _DAT_1003388c = param_3[3];
  }
  local_c = this;
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_18 = *(int **)((int)this + 0x2c); *local_18 != 0; local_18 = local_18 + 9) {
      (*(code *)local_18[8])(1);
    }
  }
  for (local_24 = DAT_1003395c; local_24 < DAT_10033960; local_24 = local_24 + 1) {
    if (*local_24 != 0) {
      (**(code **)(*local_24 + 0x1c))(1);
    }
  }
  return 0;
}



// Function: FUN_1001ab80 at 1001ab80

void FUN_1001ab80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1001abb0 at 1001abb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001abb0(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LONG *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_1001aa10(param_1);
  return;
}



// Function: FUN_1001ac00 at 1001ac00

void FUN_1001ac00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1001ac30 at 1001ac30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001ac30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10009760((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1001ac80 at 1001ac80

void FUN_1001ac80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_1001acb0 at 1001acb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001acb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_100098a0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1001ad00 at 1001ad00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001ad00(LONG *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  LONG *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10019ba0(param_1);
  return;
}



// Function: FUN_1001ad40 at 1001ad40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001ad40(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 *local_110 [5];
  void *local_fc;
  void *local_e4;
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027ad9;
  local_10 = ExceptionList;
  ppuVar2 = local_110;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (undefined4 *)0xcccccccc;
    ppuVar2 = ppuVar2 + 1;
  }
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_18 = this;
  local_fc = (void *)FUN_100133b0(4,*this + param_1 * 4);
  local_8 = 0;
  if (local_fc == (void *)0x0) {
    local_110[0] = (undefined4 *)0x0;
  }
  else {
    local_110[0] = FUN_10013e40(local_fc,param_2);
  }
  local_110[2] = local_110[0];
  local_8 = 0xffffffff;
  local_e4 = (void *)FUN_100133e0(4,*(int *)((int)local_18 + 4) + param_1 * 4);
  local_8 = 1;
  if (local_e4 != (void *)0x0) {
    FUN_10013e80(local_e4,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ae70 at 1001ae70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ae70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10009950(&PTR_DAT_10033500,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1001aee0 at 1001aee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_1001aee0(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = lstrcmpiA(param_1,param_2);
  return iVar1 == 0;
}



// Function: FUN_1001af40 at 1001af40

undefined4 FUN_1001af40(undefined1 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d4 [52];
  
  puVar3 = local_d4;
  for (iVar2 = 0x34; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
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



// Function: FUN_1001afe0 at 1001afe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001afe0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_1001b030 at 1001b030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001b030(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10009520((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1001b080 at 1001b080

undefined4 FUN_1001b080(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1001b0b0 at 1001b0b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001b0b0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_2 == 0) {
    (**(code **)(*DAT_1003387c + 8))();
  }
  else {
    (**(code **)(*DAT_1003387c + 4))();
  }
  return 0;
}



// Function: FUN_1001b130 at 1001b130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1001b130(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_dc [49];
  int local_18;
  void *local_c;
  
  puVar2 = local_dc;
  for (iVar3 = 0x36; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  local_18 = FUN_1001a140(this,param_1);
  if (local_18 == -1) {
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_1001a850(local_c,local_18);
    uVar1 = *puVar2;
  }
  return uVar1;
}



// Function: FUN_1001b190 at 1001b190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1001b190(void *this,undefined1 *param_1)

{
  undefined4 uVar1;
  LPSTR pCVar2;
  int iVar3;
  undefined4 *puVar4;
  LPCSTR pCVar5;
  undefined4 local_124 [49];
  int local_60;
  int local_54;
  undefined1 *local_48;
  int local_3c;
  int local_30;
  undefined1 *local_24;
  undefined1 *local_18;
  int *local_c;
  
  puVar4 = local_124;
  for (iVar3 = 0x48; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  pCVar5 = (LPCSTR)0x1001b1bb;
  local_c = (int *)this;
  FUN_1001e880((undefined4 *)this);
  if (*(char *)*local_c == '\0') {
    uVar1 = FUN_1001a380();
  }
  else {
    local_18 = param_1;
    if (*(char *)*local_c == '\'') {
      pCVar2 = CharNextA((LPCSTR)*local_c);
      pCVar5 = (LPCSTR)0x1001b205;
      *local_c = (int)pCVar2;
      while ((*(char *)*local_c != '\0' && (iVar3 = FUN_10019e10(local_c), iVar3 == 0))) {
        if (*(char *)*local_c == '\'') {
          pCVar2 = CharNextA((LPCSTR)*local_c);
          pCVar5 = (LPCSTR)0x1001b24c;
          *local_c = (int)pCVar2;
        }
        local_24 = (undefined1 *)*local_c;
        pCVar2 = CharNextA(pCVar5);
        pCVar5 = (LPCSTR)0x1001b26e;
        *local_c = (int)pCVar2;
        local_30 = *local_c - (int)local_24;
        if (local_18 + 0x1000 <= param_1 + local_30 + 1) {
          uVar1 = FUN_1001a380();
          return uVar1;
        }
        for (local_3c = 0; local_3c < local_30; local_3c = local_3c + 1) {
          *param_1 = *local_24;
          param_1 = param_1 + 1;
          local_24 = local_24 + 1;
        }
      }
      if (*(char *)*local_c == '\0') {
        uVar1 = FUN_1001a380();
        return uVar1;
      }
      *param_1 = 0;
      pCVar2 = CharNextA((LPCSTR)*local_c);
      *local_c = (int)pCVar2;
    }
    else {
      while ((*(char *)*local_c != '\0' &&
             (iVar3 = FUN_1001af40(*(undefined1 *)*local_c), iVar3 == 0))) {
        local_48 = (undefined1 *)*local_c;
        pCVar2 = CharNextA(pCVar5);
        pCVar5 = (LPCSTR)0x1001b36c;
        *local_c = (int)pCVar2;
        local_54 = *local_c - (int)local_48;
        if (local_18 + 0x1000 <= param_1 + local_54 + 1) {
          uVar1 = FUN_1001a380();
          return uVar1;
        }
        for (local_60 = 0; local_60 < local_54; local_60 = local_60 + 1) {
          *param_1 = *local_48;
          param_1 = param_1 + 1;
          local_48 = local_48 + 1;
        }
      }
      *param_1 = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1001b400 at 1001b400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_1001b400(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar2;
  int *piVar3;
  int local_ec [50];
  LSTATUS local_24;
  HKEY local_18 [3];
  int *local_c;
  
  piVar3 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  local_18[0] = (HKEY)0x0;
  local_c = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_ec[0] = RegOpenKeyExA(param_1,param_2,0,param_3,local_18);
    uVar2 = extraout_EDX_00;
  }
  else {
    local_ec[0] = FUN_1001c1d0(*(void **)((int)this + 8),param_1,param_2,0,param_3,local_18);
    uVar2 = extraout_EDX;
  }
  local_24 = local_ec[0];
  if (local_ec[0] == 0) {
    local_24 = FUN_100191c0(local_c);
    *local_c = (int)local_18[0];
    uVar2 = extraout_EDX_01;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&LAB_1001b4d0);
  return CONCAT44(uVar2,local_24);
}



// Function: FUN_1001b4f0 at 1001b4f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001b4f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_1001b550 at 1001b550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001b550(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  local_c = this;
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_1001b5b0 at 1001b5b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001b5b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_1001b610 at 1001b610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001b610(void *this,char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  LPSTR pCVar2;
  undefined4 uVar3;
  int iVar4;
  LPCSTR unaff_EBX;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_1d0 [4];
  int local_1c0;
  int local_1b4;
  wchar_t *local_e8;
  uchar local_dc [40];
  size_t local_b4;
  LPCSTR local_a8;
  int local_9c;
  wchar_t *local_90;
  wchar_t *local_84;
  char local_75;
  char local_69;
  int local_60;
  char local_51 [9];
  int local_48;
  undefined4 local_3c [2];
  int local_34;
  int local_28;
  int *local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027b08;
  local_10 = ExceptionList;
  puVar5 = local_1d0;
  for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = (int *)this;
  if ((param_1 != (char *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    sVar1 = strlen(param_1);
    local_28 = sVar1 << 1;
    FUN_10014180(local_3c,local_28);
    local_8 = 0;
    if (local_34 == 0) {
      local_1d0[1] = 0x8007000e;
      local_8 = 0xffffffff;
      FUN_10015020((int)local_3c);
    }
    else {
      *local_1c = (int)param_1;
      local_48 = 0;
      local_51[0] = '\0';
      local_48 = FUN_100178b0(local_51);
      if (local_48 < 0) {
        local_8 = 0xffffffff;
        local_1c0 = local_48;
        FUN_10015020((int)local_3c);
      }
      else {
        local_60 = 0;
        local_69 = '\0';
        local_75 = '\0';
        while (*(char *)*local_1c != '\0') {
          if (local_51[0] == '\x01') {
            local_84 = L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses";
            local_90 = L"\r\n\t}\r\n}\r\n";
            if (local_60 == 0) {
              local_9c = 0;
              local_9c = FUN_10020060((uchar *)*local_1c,"HKCR");
              if ((local_9c != 0) && (local_9c == *local_1c)) {
                pCVar2 = CharNextA(unaff_EBX);
                unaff_EBX = (LPCSTR)0x1001b7a7;
                *local_1c = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_1c);
                *local_1c = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_1c);
                *local_1c = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_1c);
                *local_1c = (int)pCVar2;
                iVar4 = FUN_100160e0(local_3c,local_84);
                if (iVar4 == 0) {
                  local_48 = -0x7ff8fff2;
                  break;
                }
                local_69 = '\x01';
              }
            }
            if (*(char *)*local_1c == '\'') {
              if (local_75 == '\0') {
                local_75 = '\x01';
              }
              else {
                iVar4 = FUN_10019e10(local_1c);
                if (iVar4 == 0) {
                  pCVar2 = CharNextA((LPCSTR)*local_1c);
                  *local_1c = (int)pCVar2;
                  uVar6 = FUN_10015b60((LPCSTR)*local_1c);
                  if ((int)uVar6 == 0) {
                    local_48 = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_75 = '\0';
                }
              }
            }
            if ((local_75 == '\0') && (*(char *)*local_1c == '{')) {
              local_60 = local_60 + 1;
            }
            if ((((local_75 == '\0') && (*(char *)*local_1c == '}')) &&
                (local_60 = local_60 + -1, local_60 == 0)) && (local_69 == '\x01')) {
              iVar4 = FUN_100160e0(local_3c,local_90);
              if (iVar4 == 0) {
                local_48 = -0x7ff8fff2;
                break;
              }
              local_69 = '\0';
            }
          }
          if (*(char *)*local_1c == '%') {
            pCVar2 = CharNextA((LPCSTR)*local_1c);
            *local_1c = (int)pCVar2;
            if (*(char *)*local_1c == '%') {
              uVar6 = FUN_10015b60((LPCSTR)*local_1c);
              if ((int)uVar6 == 0) {
                local_48 = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_a8 = FUN_1001e8f0((LPSTR)*local_1c,'%');
              if (local_a8 == (LPCSTR)0x0) {
                local_48 = FUN_1001a380();
                break;
              }
              if (0x1f < (int)local_a8 - *local_1c) {
                local_48 = -0x7fffbffb;
                break;
              }
              local_b4 = (int)local_a8 - *local_1c;
              FUN_10020260(local_dc,0x20,(uchar *)*local_1c,local_b4);
              local_e8 = (wchar_t *)FUN_1001e970();
              if (local_e8 == (wchar_t *)0x0) {
                local_48 = FUN_1001a380();
                break;
              }
              iVar4 = FUN_100160e0(local_3c,local_e8);
              if (iVar4 == 0) {
                local_48 = -0x7ff8fff2;
                break;
              }
              while ((LPCSTR)*local_1c != local_a8) {
                pCVar2 = CharNextA((LPCSTR)*local_1c);
                *local_1c = (int)pCVar2;
              }
            }
          }
          else {
            uVar6 = FUN_10015b60((LPCSTR)*local_1c);
            if ((int)uVar6 == 0) {
              local_48 = -0x7ff8fff2;
              break;
            }
          }
          pCVar2 = CharNextA((LPCSTR)*local_1c);
          *local_1c = (int)pCVar2;
        }
        if (-1 < local_48) {
          uVar3 = FUN_10019d50(local_3c);
          *param_2 = uVar3;
        }
        local_1b4 = local_48;
        local_8 = 0xffffffff;
        FUN_10015020((int)local_3c);
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001bae8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001bb30 at 1001bb30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001bb30(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    *param_3 = 0;
    local_c = 0;
    iVar1 = FUN_10009650(param_2);
    if (iVar1 == 0) {
      local_c = FUN_10020010(param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_c;
}



// Function: FUN_1001bbd0 at 1001bbd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001bbd0(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  undefined4 local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_3 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    *param_3 = 0;
    local_c = 0;
    iVar1 = FUN_10009650(param_2);
    if (iVar1 == 0) {
      local_c = FUN_1000b4b0(param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_c;
}



// Function: FUN_1001bc70 at 1001bc70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001bc70(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b550((void *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_1001bcb7 at 1001bcb7

void FUN_1001bcb7(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1001bc70(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1001bcd0 at 1001bcd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001bcd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b550((void *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_1001bd17 at 1001bd17

void FUN_1001bd17(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1001bcd0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1001bd30 at 1001bd30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001bd30(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10020010(param_2,param_3);
  return;
}



// Function: FUN_1001bd74 at 1001bd74

void FUN_1001bd74(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1001bd30(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1001bd80 at 1001bd80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001bd80(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001ffc0(param_2,param_3);
  return;
}



// Function: FUN_1001bdd0 at 1001bdd0

undefined4 FUN_1001bdd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x80004001;
}



// Function: FUN_1001be00 at 1001be00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001be00(LPCSTR param_1)

{
  PFILETIME lpftLastWriteTime;
  LSTATUS LVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_248 [4];
  int local_238;
  undefined4 local_22c;
  CHAR local_160 [264];
  CHAR local_58 [12];
  DWORD local_4c [4];
  int local_3c;
  int local_30 [5];
  undefined4 *local_1c;
  PFILETIME local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027b38;
  local_10 = ExceptionList;
  piVar3 = local_248;
  for (iVar2 = 0x8e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  lpftLastWriteTime = (PFILETIME)(DAT_10033838 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_14 = lpftLastWriteTime;
  FUN_10014260(local_30,0);
  local_8 = 0;
  uVar4 = FUN_1001b400(local_30,(HKEY)*local_1c,param_1,local_1c[1] | 0x2001f);
  local_3c = (int)uVar4;
  if (local_3c == 0) {
    do {
      local_58[0] = '\0';
      local_58[1] = '\x01';
      local_58[2] = '\0';
      local_58[3] = '\0';
      LVar1 = RegEnumKeyExA((HKEY)0x0,(DWORD)local_160,local_58,(LPDWORD)0x0,(LPDWORD)0x0,(LPSTR)0x0
                            ,local_4c,lpftLastWriteTime);
      lpftLastWriteTime = (PFILETIME)0x1001bed2;
      if (LVar1 != 0) {
        FUN_100191c0(local_30);
        local_22c = FUN_10019bf0(local_1c,param_1);
        local_8 = 0xffffffff;
        FUN_10015070(local_30);
        goto LAB_1001bf46;
      }
      local_3c = FUN_1001be00(local_160);
    } while (local_3c == 0);
    local_8 = 0xffffffff;
    local_238 = local_3c;
    FUN_10015070(local_30);
  }
  else {
    local_8 = 0xffffffff;
    local_248[1] = local_3c;
    FUN_10015070(local_30);
  }
LAB_1001bf46:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001bf84);
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001bfe0 at 1001bfe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1001bfe0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,LPSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_e8 [49];
  FARPROC local_24;
  HMODULE local_18;
  undefined4 *local_c;
  
  puVar3 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = (undefined4 *)this;
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar1 = RegCreateKeyExA(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar1;
    }
  }
  else {
    local_18 = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1001c023;
    if (local_18 == (HMODULE)0x0) {
      return 1;
    }
    local_24 = GetProcAddress(local_18,"RegCreateKeyTransactedA");
    if (local_24 != (FARPROC)0x0) {
      iVar2 = (*local_24)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                          *local_c,0,0x1001c04e,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1001c0f0 at 1001c0f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1001c0f0(void *this,HKEY param_1,LPCSTR param_2)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_e8 [49];
  FARPROC local_24;
  HMODULE local_18;
  undefined4 *local_c;
  
  puVar3 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = (undefined4 *)this;
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar1 = RegDeleteKeyA(param_1,param_2);
      return LVar1;
    }
  }
  else {
    local_18 = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1001c12f;
    if (local_18 == (HMODULE)0x0) {
      return 1;
    }
    local_24 = GetProcAddress(local_18,"RegDeleteKeyTransactedA");
    if (local_24 != (FARPROC)0x0) {
      iVar2 = (*local_24)(param_1,param_2,0,0,*local_c,0,0x1001c157,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1001c1d0 at 1001c1d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1001c1d0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_e8 [49];
  FARPROC local_24;
  HMODULE local_18;
  undefined4 *local_c;
  
  puVar3 = local_e8;
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = (undefined4 *)this;
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar1 = RegOpenKeyExA(param_1,param_2,param_3,param_4,param_5);
      return LVar1;
    }
  }
  else {
    local_18 = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1001c20f;
    if (local_18 == (HMODULE)0x0) {
      return 1;
    }
    local_24 = GetProcAddress(local_18,"RegOpenKeyTransactedA");
    if (local_24 != (FARPROC)0x0) {
      iVar2 = (*local_24)(param_1,param_2,param_3,param_4,param_5,*local_c,0,0x1001c23a,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1001c2c0 at 1001c2c0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001c2c0(void *this,char *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_110c [49];
  undefined4 local_1048;
  HKEY local_103c;
  LPVOID local_1030 [3];
  int local_1024;
  uchar local_1018 [4104];
  undefined4 *local_10;
  uint local_8;
  
  puVar2 = local_110c;
  for (iVar1 = 0x442; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_1024 = 0;
  local_1030[0] = (LPVOID)0x0;
  local_10 = (undefined4 *)this;
  local_1024 = FUN_1001b610(this,param_1,local_1030);
  if (-1 < local_1024) {
    *local_10 = local_1030[0];
    while( true ) {
      if ((*(char *)*local_10 == '\0') ||
         (local_1024 = FUN_1001b190(local_10,local_1018), local_1024 < 0)) goto LAB_1001c495;
      local_103c = (HKEY)FUN_1001a8c0((LPCSTR)local_1018);
      if (local_103c == (HKEY)0x0) break;
      local_1024 = FUN_1001b190(local_10,local_1018);
      if (local_1024 < 0) goto LAB_1001c495;
      if (local_1018[0] != '{') {
        local_1024 = FUN_1001a380();
        goto LAB_1001c495;
      }
      if (param_2 == 0) {
        local_1024 = FUN_1001cb70(local_1018,local_103c,0,0);
        if (local_1024 < 0) goto LAB_1001c495;
      }
      else {
        local_1048 = *local_10;
        local_1024 = FUN_1001cb70(local_1018,local_103c,param_2,0);
        if (local_1024 < 0) {
          *local_10 = local_1048;
          FUN_1001cb70(local_1018,local_103c,0,0);
          goto LAB_1001c495;
        }
      }
      FUN_1001e880(local_10);
    }
    local_1024 = FUN_1001a380();
LAB_1001c495:
    CoTaskMemFree(local_1030[0]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001c4e4);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001c520 at 1001c520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001c520(wchar_t *param_1,LPCSTR param_2,LPCSTR param_3)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPSTR *ppCVar7;
  uint uStack_5d8;
  LPSTR local_5c8 [2];
  int local_5c0;
  LPSTR local_5bc;
  LPCSTR local_5b8;
  undefined4 local_5b0;
  undefined4 uStack_5a4;
  _RTC_ALLOCA_NODE *local_4d8 [3];
  LPCSTR local_4cc;
  int local_4c0 [259];
  HGLOBAL local_b4;
  DWORD local_a8;
  HGLOBAL local_9c;
  HRSRC local_90;
  HMODULE local_84;
  undefined1 local_78 [16];
  undefined4 local_68;
  int local_5c [6];
  wchar_t *local_44;
  UINT local_38;
  uint local_2c [3];
  undefined4 local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027b73;
  local_10 = ExceptionList;
  ppCVar7 = local_5c8;
  for (iVar6 = 0x16d; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  uStack_5d8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_5d8;
  ExceptionList = &local_10;
  local_4d8[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_18 = uStack_5d8;
  local_38 = FUN_1000a4a0();
  FUN_10002640(local_5c);
  local_8 = 0;
  FUN_10014340(local_78,local_20);
  FUN_10013d70(local_4c0);
  local_8._0_1_ = 1;
  local_44 = param_1;
  if (param_1 == (wchar_t *)0x0) {
    local_5b8 = (LPCSTR)0x0;
    goto LAB_1001c6a6;
  }
  sVar4 = wcslen(param_1);
  local_2c[0] = sVar4 + 1;
  uVar5 = FUN_100014b0(local_2c,local_2c[0],2);
  if ((int)uVar5 < 0) {
    local_5bc = (LPSTR)0x0;
  }
  else {
    if ((int)local_2c[0] < 0x401) {
      cVar3 = FUN_1000a520(local_2c[0]);
      if (cVar3 == '\0') goto LAB_1001c66a;
      local_5c0 = local_2c[0] + 0x24;
      iVar6 = -(local_2c[0] + 0x24);
      local_5c8[1] = &stack0xfffffa24;
      local_14 = &stack0xfffffa24;
      *(_RTC_ALLOCA_NODE ***)((int)local_5c8 + iVar6 + -0x18) = local_4d8;
      iVar2 = local_5c0;
      pCVar1 = local_5c8[1];
      *(undefined4 *)((int)local_5c8 + iVar6 + -0x1c) = 0x1001c655;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_5c8 + iVar6 + -0x18));
      local_5c8[0] = local_5c8[1] + 0x20;
      local_5c8[1] = local_5c8[0];
    }
    else {
LAB_1001c66a:
      local_5c8[0] = (LPSTR)FUN_10006820(local_2c[0]);
    }
    local_5bc = FUN_10006d50(local_5c8[0],local_44,local_2c[0],local_38);
  }
  local_5b8 = local_5bc;
LAB_1001c6a6:
  local_4cc = local_5b8;
  if (local_5b8 == (LPCSTR)0x0) {
    local_5b0 = 0x8007000e;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10014d60(local_4c0);
    local_8 = 0xffffffff;
    FUN_100043e0(local_5c);
  }
  else {
    local_84 = LoadLibraryExA(local_5b8,(HANDLE)0x0,0x60);
    if (local_84 == (HMODULE)0x0) {
      local_84 = LoadLibraryExA(local_4cc,(HANDLE)0x0,2);
    }
    if (local_84 == (HMODULE)0x0) {
      local_68 = FUN_10017900();
    }
    else {
      local_90 = FindResourceA(local_84,param_2,param_3);
      if (local_90 == (HRSRC)0x0) {
        local_68 = FUN_10017900();
      }
      else {
        local_9c = LoadResource(local_84,local_90);
        if (local_9c == (HGLOBAL)0x0) {
          local_68 = FUN_10017900();
        }
        else {
          local_a8 = SizeofResource(local_84,local_90);
          local_b4 = local_9c;
          if (local_a8 <= local_a8 + 1) {
            local_8 = CONCAT31(local_8._1_3_,2);
            FUN_10016bc0(local_a8 + 1);
            FUN_1001c818();
            return;
          }
          local_68 = 0x8007000e;
        }
      }
    }
    if (local_84 != (HMODULE)0x0) {
      FreeLibrary(local_84);
    }
    uStack_5a4 = local_68;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10014d60(local_4c0);
    local_8 = 0xffffffff;
    FUN_100043e0(local_5c);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001c91c,local_4d8[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001c812 at 1001c812

undefined * Catch_1001c812(void)

{
  return &DAT_1001c821;
}



// Function: FUN_1001c818 at 1001c818

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001c818(void)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint unaff_EBP;
  rsize_t rVar6;
  void *pvVar7;
  rsize_t rVar8;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  iVar2 = FUN_100153d0((undefined4 *)(unaff_EBP - 0x4bc));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 100) = 0x8007000e;
  }
  else {
    rVar8 = *(rsize_t *)(unaff_EBP - 0xa4);
    pvVar7 = *(void **)(unaff_EBP - 0xb0);
    rVar6 = *(rsize_t *)(unaff_EBP - 0xa4);
    pvVar3 = (void *)FUN_100153d0((undefined4 *)(unaff_EBP - 0x4bc));
    FUN_100200b0(pvVar3,rVar6,pvVar7,rVar8);
    iVar2 = FUN_100153d0((undefined4 *)(unaff_EBP - 0x4bc));
    *(undefined1 *)(iVar2 + *(int *)(unaff_EBP - 0xa4)) = 0;
    iVar2 = *(int *)(unaff_EBP + 0x14);
    pcVar4 = (char *)FUN_100153d0((undefined4 *)(unaff_EBP - 0x4bc));
    uVar5 = FUN_1001c2c0((void *)(unaff_EBP - 0x74),pcVar4,iVar2);
    *(undefined4 *)(unaff_EBP - 100) = uVar5;
  }
  if (*(int *)(unaff_EBP - 0x80) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x80));
  }
  *(undefined4 *)(unaff_EBP - 0x5a0) = *(undefined4 *)(unaff_EBP - 100);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_10014d60((int *)(unaff_EBP - 0x4bc));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_100043e0((int *)(unaff_EBP - 0x58));
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_1001c91c,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x4d4));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x5c8) = 0x1001c914;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_1001c9a0 at 1001c9a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001c9a0(int param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = 0;
  local_18 = FUN_1001ca30(&DAT_10033954,param_1,param_2);
  if ((-1 < local_18) && (DAT_10033898 != (code *)0x0)) {
    local_18 = (*DAT_10033898)(DAT_10033920);
  }
  return local_18;
}



// Function: FUN_1001ca30 at 1001ca30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001ca30(void *this,int param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_10017430((int)this,param_1,param_2);
  return;
}



// Function: FUN_1001ca80 at 1001ca80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001ca80(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_e8 [49];
  int *local_24;
  int local_18;
  void *local_c;
  
  puVar4 = local_e8;
  for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = 0;
  local_24 = *(int **)((int)this + 0x2c);
  local_c = this;
  if (local_24 != (int *)0x0) {
    for (; *local_24 != 0; local_24 = local_24 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_100204d0(param_2,(void *)*local_24), CONCAT31(extraout_var,bVar1) != 0)) {
        local_18 = (*(code *)local_24[1])(1);
        if (local_18 < 0) break;
        piVar2 = (int *)(*(code *)local_24[7])(1,0x1001cafd);
        local_18 = FUN_10018120((GUID *)*local_24,piVar2,0x1001cb1b);
        if (local_18 < 0) break;
      }
    }
  }
  if (-1 < local_18) {
    local_18 = FUN_1001c9a0(param_1,param_2);
  }
  return local_18;
}



// Function: FUN_1001cb70 at 1001cb70

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001cb70(uchar *param_1,HKEY param_2,int param_3,int param_4)

{
  LPCSTR lpString1;
  LPCSTR pCVar1;
  HKEY pHVar2;
  size_t sVar3;
  int iVar4;
  LPCSTR unaff_EDI;
  uint *puVar5;
  undefined8 uVar6;
  uint local_1304 [5];
  undefined4 local_12f0;
  undefined4 local_12e4;
  int local_12d8;
  undefined4 local_12cc;
  undefined4 local_12c0;
  undefined4 local_12b4;
  int local_12a8;
  int local_11dc [5];
  int local_11c8;
  int local_11bc [5];
  int local_11a8 [5];
  CHAR local_1194 [4104];
  int local_18c [5];
  uint local_178;
  int local_16c;
  int local_160;
  int local_154;
  uchar local_148 [268];
  uint local_3c;
  HKEY local_30 [5];
  void *local_1c;
  LPCSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027bd4;
  local_10 = ExceptionList;
  puVar5 = local_1304;
  for (iVar4 = 0x4bd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  lpString1 = (LPCSTR)(DAT_10033838 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_14 = lpString1;
  FUN_10014260(local_30,0);
  local_8 = 0;
  local_154 = 1;
  local_160 = param_4;
  local_16c = 0;
  local_16c = FUN_1001b190(local_1c,param_1);
  if (-1 < local_16c) {
LAB_1001cc28:
    if (*param_1 == '}') goto LAB_1001d46e;
    local_154 = 1;
    iVar4 = lstrcmpiA(lpString1,unaff_EDI);
    unaff_EDI = (LPCSTR)0x1001cc5a;
    local_1304[0] = (uint)(iVar4 == 0);
    local_178 = local_1304[0];
    iVar4 = lstrcmpiA((LPCSTR)param_1,"ForceRemove");
    lpString1 = (LPCSTR)0x1001cc99;
    if ((iVar4 == 0) || (local_178 != 0)) {
      local_16c = FUN_1001b190(local_1c,param_1);
      if (local_16c < 0) goto LAB_1001d46e;
      if (param_3 == 0) goto LAB_1001cdf6;
      FUN_10014260(local_18c,0);
      local_8._0_1_ = 1;
      pCVar1 = FUN_1001e8f0((LPSTR)param_1,'\\');
      if (pCVar1 == (LPCSTR)0x0) {
        iVar4 = FUN_10018f70((LPCSTR)param_1);
        if (iVar4 != 0) {
          FUN_10018f20(local_18c,param_2);
          FUN_1001be00((LPCSTR)param_1);
          FUN_10019db0(local_18c);
        }
        if (local_178 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_18c);
          goto LAB_1001cdf6;
        }
        local_16c = FUN_1001b190(local_1c,param_1);
        if (local_16c < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_18c);
        }
        else {
          local_16c = FUN_1001e790(local_1c,(char *)param_1);
          if (-1 < local_16c) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_10015070(local_18c);
            goto LAB_1001d403;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_18c);
        }
        goto LAB_1001d46e;
      }
      local_12f0 = FUN_1001a380();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10015070(local_18c);
      local_8 = 0xffffffff;
      FUN_10015070((int *)local_30);
      goto LAB_1001d48f;
    }
LAB_1001cdf6:
    iVar4 = lstrcmpiA((LPCSTR)param_1,"NoRemove");
    if (iVar4 == 0) {
      local_154 = 0;
      local_16c = FUN_1001b190(local_1c,param_1);
      if (local_16c < 0) goto LAB_1001d46e;
    }
    iVar4 = lstrcmpiA((LPCSTR)param_1,"Val");
    lpString1 = (LPCSTR)0x1001ce56;
    if (iVar4 == 0) {
      local_16c = FUN_1001b190(local_1c,local_1194);
      if ((local_16c < 0) || (local_16c = FUN_1001b190(local_1c,param_1), local_16c < 0))
      goto LAB_1001d46e;
      if (*param_1 != '=') {
        local_12e4 = FUN_1001a380();
        local_8 = 0xffffffff;
        FUN_10015070((int *)local_30);
        goto LAB_1001d48f;
      }
      if (param_3 != 0) {
        FUN_10014260(local_11a8,0);
        local_8._0_1_ = 2;
        FUN_10018f20(local_11a8,param_2);
        local_16c = FUN_10016350(local_1c,local_11a8,local_1194,param_1);
        FUN_10019db0(local_11a8);
        if (-1 < local_16c) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_11a8);
          goto LAB_1001d403;
        }
        local_12d8 = local_16c;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10015070(local_11a8);
        local_8 = 0xffffffff;
        FUN_10015070((int *)local_30);
        goto LAB_1001d48f;
      }
      if ((param_4 == 0) && (local_154 != 0)) {
        FUN_10014260(local_11bc,0);
        local_8._0_1_ = 3;
        uVar6 = FUN_1001b400(local_11bc,param_2,(LPCSTR)0x0,0x20006);
        local_3c = (uint)uVar6;
        if (local_3c != 0) {
          local_16c = FUN_10017950(local_3c);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_11bc);
          goto LAB_1001d46e;
        }
        local_3c = FUN_10019c70(local_11bc,local_1194);
        if ((local_3c != 0) && (local_3c != 2)) {
          local_16c = FUN_10017950(local_3c);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_11bc);
          goto LAB_1001d46e;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10015070(local_11bc);
      }
      local_16c = FUN_1001e790(local_1c,(char *)param_1);
joined_r0x1001d063:
      if (local_16c < 0) goto LAB_1001d46e;
      goto LAB_1001cc28;
    }
    pCVar1 = FUN_1001e8f0((LPSTR)param_1,'\\');
    if (pCVar1 != (LPCSTR)0x0) {
      local_12cc = FUN_1001a380();
      local_8 = 0xffffffff;
      FUN_10015070((int *)local_30);
      goto LAB_1001d48f;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        uVar6 = FUN_1001b400(local_30,param_2,(LPCSTR)param_1,0x20019);
        local_3c = (uint)uVar6;
      }
      else {
        local_3c = 2;
      }
      if (local_3c != 0) {
        param_4 = 1;
      }
      FUN_10020260(local_148,0x104,param_1,0xffffffff);
      local_16c = FUN_1001b190(local_1c,param_1);
      if (((local_16c < 0) || (local_16c = FUN_1001e790(local_1c,(char *)param_1), local_16c < 0))
         || (((*param_1 == '{' && (sVar3 = strlen((char *)param_1), sVar3 == 1)) &&
             (((local_16c = FUN_1001cb70(param_1,local_30[0],0,param_4), local_16c < 0 &&
               (param_4 == 0)) || (local_16c = FUN_1001b190(local_1c,param_1), local_16c < 0))))))
      goto LAB_1001d46e;
      param_4 = local_160;
      if (local_3c == 2) goto LAB_1001cc28;
      if (local_3c != 0) {
        if (local_160 == 0) goto LAB_1001d2bf;
        goto LAB_1001cc28;
      }
      if (local_160 != 0) {
        pHVar2 = (HKEY)FUN_10015430(local_30);
        uVar6 = FUN_1001a940(pHVar2);
        if ((int)uVar6 != 0) {
          iVar4 = FUN_10018f70((LPCSTR)local_148);
          if ((iVar4 != 0) && (local_154 != 0)) {
            FUN_1001be00((LPCSTR)local_148);
          }
          goto LAB_1001cc28;
        }
      }
      pHVar2 = (HKEY)FUN_10015430(local_30);
      uVar6 = FUN_1001a940(pHVar2);
      local_11c8 = (int)uVar6;
      local_3c = FUN_100191c0((int *)local_30);
      if (local_3c != 0) {
        local_12b4 = FUN_10017950(local_3c);
        local_8 = 0xffffffff;
        FUN_10015070((int *)local_30);
        goto LAB_1001d48f;
      }
      if ((local_154 != 0) && (local_11c8 == 0)) {
        FUN_10014260(local_11dc,0);
        local_8._0_1_ = 4;
        FUN_10018f20(local_11dc,param_2);
        local_3c = FUN_10019bf0(local_11dc,(LPCSTR)local_148);
        FUN_10019db0(local_11dc);
        if (local_3c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10015070(local_11dc);
          goto LAB_1001d403;
        }
        local_16c = FUN_10017950(local_3c);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10015070(local_11dc);
        goto LAB_1001d46e;
      }
    }
    else {
      uVar6 = FUN_1001b400(local_30,param_2,(LPCSTR)param_1,0x2001f);
      local_3c = (uint)uVar6;
      if (local_3c != 0) {
        uVar6 = FUN_1001b400(local_30,param_2,(LPCSTR)param_1,0x20019);
        local_3c = (uint)uVar6;
        if (local_3c != 0) {
          uVar6 = FUN_10019240(local_30,param_2,(LPCSTR)param_1,(LPSTR)0x0,0,0x2001f,
                               (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0);
          local_3c = (uint)uVar6;
          if (local_3c != 0) {
            local_12c0 = FUN_10017950(local_3c);
            local_8 = 0xffffffff;
            FUN_10015070((int *)local_30);
            goto LAB_1001d48f;
          }
        }
      }
      local_16c = FUN_1001b190(local_1c,param_1);
      if ((local_16c < 0) ||
         ((*param_1 == '=' &&
          (local_16c = FUN_10016350(local_1c,local_30,(LPCSTR)0x0,param_1), local_16c < 0))))
      goto LAB_1001d46e;
    }
LAB_1001d403:
    if (((param_3 != 0) && (*param_1 == '{')) && (sVar3 = strlen((char *)param_1), sVar3 == 1)) {
      local_16c = FUN_1001cb70(param_1,local_30[0],param_3,0);
      if (-1 < local_16c) {
        local_16c = FUN_1001b190(local_1c,param_1);
        goto joined_r0x1001d063;
      }
      goto LAB_1001d46e;
    }
    goto LAB_1001cc28;
  }
  local_8 = 0xffffffff;
  local_1304[2] = local_16c;
  FUN_10015070((int *)local_30);
LAB_1001d48f:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001d4cc);
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_1001d2bf:
  local_16c = FUN_10017950(local_3c);
LAB_1001d46e:
  local_12a8 = local_16c;
  local_8 = 0xffffffff;
  FUN_10015070((int *)local_30);
  goto LAB_1001d48f;
}



// Function: FUN_1001d570 at 1001d570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001d570(int *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_ec [5];
  int *local_d8;
  int local_c;
  
  ppiVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = FUN_1001ad00(param_1 + 1);
  if (local_c == 0) {
    local_d8 = param_1;
    local_ec[2] = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xc))(1);
    }
  }
  return local_c;
}



// Function: FUN_1001d610 at 1001d610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001d610(int *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_ec [5];
  int *local_d8;
  int local_c;
  
  ppiVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = FUN_1001ad00(param_1 + 1);
  if (local_c == 0) {
    local_d8 = param_1;
    local_ec[2] = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xc))(1);
    }
  }
  return local_c;
}



// Function: FUN_1001d6b0 at 1001d6b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d6b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b5b0((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_1001d6ef at 1001d6ef

void FUN_1001d6ef(int param_1)

{
  FUN_1001d6b0(param_1 + -4);
  return;
}



// Function: FUN_1001d700 at 1001d700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001d700(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b5b0((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_1001d73f at 1001d73f

void FUN_1001d73f(int param_1)

{
  FUN_1001d700(param_1 + -4);
  return;
}



// Function: FUN_1001d750 at 1001d750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001d750(int *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_ec [5];
  int *local_d8;
  int local_c;
  
  ppiVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = FUN_100098a0(param_1 + 2);
  if (local_c == 0) {
    local_d8 = param_1;
    local_ec[2] = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x10))(1);
    }
  }
  return local_c;
}



// Function: FUN_1001d7e9 at 1001d7e9

void FUN_1001d7e9(int param_1)

{
  FUN_1001d750((int *)(param_1 + -4));
  return;
}



// Function: FUN_1001d800 at 1001d800

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001d800(int *param_1)

{
  int iVar1;
  int **ppiVar2;
  int *local_ec [5];
  int *local_d8;
  int local_c;
  
  ppiVar2 = local_ec;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppiVar2 = (int *)0xcccccccc;
    ppiVar2 = ppiVar2 + 1;
  }
  local_c = FUN_100098a0(param_1 + 1);
  if (local_c == 0) {
    local_d8 = param_1;
    local_ec[2] = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (local_c == 1) {
    (**(code **)(*DAT_1003387c + 8))();
  }
  return local_c;
}



// Function: FUN_1001d8c0 at 1001d8c0

undefined4 FUN_1001d8c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1001d8f0 at 1001d8f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001d8f0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int *local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  if (*param_1 != 0) {
    for (local_18 = 0; local_18 < param_1[2]; local_18 = local_18 + 1) {
    }
    free((void *)*param_1);
    *local_c = 0;
  }
  if (local_c[1] != 0) {
    free((void *)local_c[1]);
    local_c[1] = 0;
  }
  local_c[2] = 0;
  return;
}



// Function: FUN_1001d9b0 at 1001d9b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001d9b0(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_154 [2];
  int local_14c;
  LPSTR local_148;
  LPCSTR local_144;
  undefined4 local_13c;
  undefined4 local_130;
  _RTC_ALLOCA_NODE *local_64 [3];
  LPCSTR local_58;
  int local_4c [6];
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027c08;
  local_10 = ExceptionList;
  ppCVar7 = local_154;
  for (iVar6 = 0x51; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_64[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_28 = FUN_1000a4a0();
  FUN_10002640(local_4c);
  local_8 = 0;
  local_34 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_144 = (LPCSTR)0x0;
    goto LAB_1001db09;
  }
  sVar4 = wcslen(param_4);
  local_1c[0] = sVar4 + 1;
  uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
  if ((int)uVar5 < 0) {
    local_148 = (LPSTR)0x0;
  }
  else {
    if ((int)local_1c[0] < 0x401) {
      cVar3 = FUN_1000a520(local_1c[0]);
      if (cVar3 == '\0') goto LAB_1001dacd;
      local_14c = local_1c[0] + 0x24;
      iVar6 = -(local_1c[0] + 0x24);
      local_154[1] = &stack0xfffffe98;
      *(_RTC_ALLOCA_NODE ***)((int)local_154 + iVar6 + -0x18) = local_64;
      iVar2 = local_14c;
      pCVar1 = local_154[1];
      *(undefined4 *)((int)local_154 + iVar6 + -0x1c) = 0x1001dab8;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_154 + iVar6 + -0x18));
      local_154[0] = local_154[1] + 0x20;
      local_154[1] = local_154[0];
    }
    else {
LAB_1001dacd:
      local_154[0] = (LPSTR)FUN_10006820(local_1c[0]);
    }
    local_148 = FUN_10006d50(local_154[0],local_34,local_1c[0],local_28);
  }
  local_144 = local_148;
LAB_1001db09:
  local_58 = local_144;
  if (local_144 == (LPCSTR)0x0) {
    local_13c = 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  else {
    local_130 = FUN_1001c520(param_2,(LPCSTR)(uint)param_3,local_144);
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001dba4,local_64[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001dc00 at 1001dc00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001dc00(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_16c [2];
  int local_164;
  LPSTR local_160;
  LPSTR local_15c;
  undefined4 local_154;
  undefined4 local_148;
  undefined4 local_13c;
  _RTC_ALLOCA_NODE *local_70 [3];
  LPCSTR local_64;
  LPSTR local_58;
  int local_4c [6];
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027c38;
  local_10 = ExceptionList;
  ppCVar7 = local_16c;
  for (iVar6 = 0x57; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_28 = FUN_1000a4a0();
  FUN_10002640(local_4c);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_154 = 0x80070057;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
    goto LAB_1001def4;
  }
  local_34 = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_15c = (LPSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_3);
    local_1c[0] = sVar4 + 1;
    uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
    if ((int)uVar5 < 0) {
      local_160 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000a520(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1001dd4d;
        local_164 = local_1c[0] + 0x24;
        iVar6 = -(local_1c[0] + 0x24);
        local_16c[1] = &stack0xfffffe80;
        *(_RTC_ALLOCA_NODE ***)((int)local_16c + iVar6 + -0x18) = local_70;
        iVar2 = local_164;
        pCVar1 = local_16c[1];
        *(undefined4 *)((int)local_16c + iVar6 + -0x1c) = 0x1001dd38;
        _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_16c + iVar6 + -0x18));
        local_16c[0] = local_16c[1] + 0x20;
        local_16c[1] = local_16c[0];
      }
      else {
LAB_1001dd4d:
        local_16c[0] = (LPSTR)FUN_10006820(local_1c[0]);
      }
      local_160 = FUN_10006d50(local_16c[0],local_34,local_1c[0],local_28);
    }
    local_15c = local_160;
  }
  local_58 = local_15c;
  local_34 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_15c = (LPCSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_4);
    local_1c[0] = sVar4 + 1;
    uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
    if ((int)uVar5 < 0) {
      local_160 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000a520(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1001de51;
        local_164 = local_1c[0] + 0x24;
        local_16c[1] = &stack0xfffffe80;
        _RTC_AllocaHelper(&stack0xfffffe80,local_164,local_70);
        local_16c[0] = local_16c[1] + 0x20;
        local_16c[1] = local_16c[0];
      }
      else {
LAB_1001de51:
        local_16c[0] = (LPSTR)FUN_10006820(local_1c[0]);
      }
      local_160 = FUN_10006d50(local_16c[0],local_34,local_1c[0],local_28);
    }
    local_15c = local_160;
  }
  local_64 = local_15c;
  if ((local_58 == (LPCSTR)0x0) || (local_15c == (LPCSTR)0x0)) {
    local_148 = 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  else {
    local_13c = FUN_1001c520(param_2,local_58,local_15c);
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
LAB_1001def4:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001df2c,local_70[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001df90 at 1001df90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001df90(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_154 [2];
  int local_14c;
  LPSTR local_148;
  LPCSTR local_144;
  undefined4 local_13c;
  undefined4 local_130;
  _RTC_ALLOCA_NODE *local_64 [3];
  LPCSTR local_58;
  int local_4c [6];
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027c68;
  local_10 = ExceptionList;
  ppCVar7 = local_154;
  for (iVar6 = 0x51; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_64[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_28 = FUN_1000a4a0();
  FUN_10002640(local_4c);
  local_8 = 0;
  local_34 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_144 = (LPCSTR)0x0;
    goto LAB_1001e0e9;
  }
  sVar4 = wcslen(param_4);
  local_1c[0] = sVar4 + 1;
  uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
  if ((int)uVar5 < 0) {
    local_148 = (LPSTR)0x0;
  }
  else {
    if ((int)local_1c[0] < 0x401) {
      cVar3 = FUN_1000a520(local_1c[0]);
      if (cVar3 == '\0') goto LAB_1001e0ad;
      local_14c = local_1c[0] + 0x24;
      iVar6 = -(local_1c[0] + 0x24);
      local_154[1] = &stack0xfffffe98;
      *(_RTC_ALLOCA_NODE ***)((int)local_154 + iVar6 + -0x18) = local_64;
      iVar2 = local_14c;
      pCVar1 = local_154[1];
      *(undefined4 *)((int)local_154 + iVar6 + -0x1c) = 0x1001e098;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_154 + iVar6 + -0x18));
      local_154[0] = local_154[1] + 0x20;
      local_154[1] = local_154[0];
    }
    else {
LAB_1001e0ad:
      local_154[0] = (LPSTR)FUN_10006820(local_1c[0]);
    }
    local_148 = FUN_10006d50(local_154[0],local_34,local_1c[0],local_28);
  }
  local_144 = local_148;
LAB_1001e0e9:
  local_58 = local_144;
  if (local_144 == (LPCSTR)0x0) {
    local_13c = 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  else {
    local_130 = FUN_1001c520(param_2,(LPCSTR)(uint)param_3,local_144);
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001e184,local_64[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001e1e0 at 1001e1e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001e1e0(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_16c [2];
  int local_164;
  LPSTR local_160;
  LPSTR local_15c;
  undefined4 local_154;
  undefined4 local_148;
  undefined4 local_13c;
  _RTC_ALLOCA_NODE *local_70 [3];
  LPCSTR local_64;
  LPSTR local_58;
  int local_4c [6];
  wchar_t *local_34;
  UINT local_28;
  uint local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027c98;
  local_10 = ExceptionList;
  ppCVar7 = local_16c;
  for (iVar6 = 0x57; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_28 = FUN_1000a4a0();
  FUN_10002640(local_4c);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_154 = 0x80070057;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
    goto LAB_1001e4d4;
  }
  local_34 = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_15c = (LPSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_3);
    local_1c[0] = sVar4 + 1;
    uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
    if ((int)uVar5 < 0) {
      local_160 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000a520(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1001e32d;
        local_164 = local_1c[0] + 0x24;
        iVar6 = -(local_1c[0] + 0x24);
        local_16c[1] = &stack0xfffffe80;
        *(_RTC_ALLOCA_NODE ***)((int)local_16c + iVar6 + -0x18) = local_70;
        iVar2 = local_164;
        pCVar1 = local_16c[1];
        *(undefined4 *)((int)local_16c + iVar6 + -0x1c) = 0x1001e318;
        _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_16c + iVar6 + -0x18));
        local_16c[0] = local_16c[1] + 0x20;
        local_16c[1] = local_16c[0];
      }
      else {
LAB_1001e32d:
        local_16c[0] = (LPSTR)FUN_10006820(local_1c[0]);
      }
      local_160 = FUN_10006d50(local_16c[0],local_34,local_1c[0],local_28);
    }
    local_15c = local_160;
  }
  local_58 = local_15c;
  local_34 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_15c = (LPCSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_4);
    local_1c[0] = sVar4 + 1;
    uVar5 = FUN_100014b0(local_1c,local_1c[0],2);
    if ((int)uVar5 < 0) {
      local_160 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000a520(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1001e431;
        local_164 = local_1c[0] + 0x24;
        local_16c[1] = &stack0xfffffe80;
        _RTC_AllocaHelper(&stack0xfffffe80,local_164,local_70);
        local_16c[0] = local_16c[1] + 0x20;
        local_16c[1] = local_16c[0];
      }
      else {
LAB_1001e431:
        local_16c[0] = (LPSTR)FUN_10006820(local_1c[0]);
      }
      local_160 = FUN_10006d50(local_16c[0],local_34,local_1c[0],local_28);
    }
    local_15c = local_160;
  }
  local_64 = local_15c;
  if ((local_58 == (LPCSTR)0x0) || (local_15c == (LPCSTR)0x0)) {
    local_148 = 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
  else {
    local_13c = FUN_1001c520(param_2,local_58,local_15c);
    local_8 = 0xffffffff;
    FUN_100043e0(local_4c);
  }
LAB_1001e4d4:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001e50c,local_70[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001e570 at 1001e570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001e570(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_c = this;
  RegSetValueExA(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_1001e5d0 at 1001e5d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS FUN_1001e5d0(LPCSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  uint *puVar4;
  uint local_104 [50];
  uint local_3c;
  int local_30;
  DWORD local_24;
  BYTE *local_18;
  undefined4 *local_c;
  
  puVar4 = local_104;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_104[0] = (uint)(param_2 != (BYTE *)0x0);
  local_3c = local_104[0];
  if (local_104[0] == 0) {
    LVar1 = 0xd;
  }
  else {
    local_24 = 0;
    local_18 = param_2;
    do {
      sVar2 = strlen((char *)local_18);
      local_30 = sVar2 + 1;
      local_18 = local_18 + local_30;
      local_24 = local_24 + local_30;
    } while (local_30 != 1);
    LVar1 = RegSetValueExA((HKEY)*local_c,param_1,0,7,param_2,local_24);
  }
  return LVar1;
}



// Function: FUN_1001e6a0 at 1001e6a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS FUN_1001e6a0(LPCSTR param_1,BYTE *param_2,DWORD param_3)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  uint *puVar4;
  uint local_e0 [50];
  uint local_18;
  undefined4 *local_c;
  
  puVar4 = local_e0;
  for (iVar3 = 0x37; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_e0[0] = (uint)(param_2 != (BYTE *)0x0);
  local_18 = local_e0[0];
  if (local_e0[0] == 0) {
    LVar1 = 0xd;
  }
  else {
    sVar2 = strlen((char *)param_2);
    LVar1 = RegSetValueExA((HKEY)*local_c,param_1,0,param_3,param_2,sVar2 + 1);
  }
  return LVar1;
}



// Function: FUN_1001e750 at 1001e750

void __thiscall FUN_1001e750(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_1001e790 at 1001e790

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001e790(void *this,char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_10e8 [49];
  undefined1 local_1024 [4104];
  int local_1c;
  undefined4 *local_10;
  uint local_8;
  
  puVar2 = local_10e8;
  for (iVar1 = 0x439; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_10 = (undefined4 *)this;
  if ((*param_1 == '=') && (local_1c = FUN_1001b190(this,param_1), -1 < local_1c)) {
    FUN_1001e880(local_10);
    local_1c = FUN_1001b190(local_10,local_1024);
    if (-1 < local_1c) {
      local_1c = FUN_1001b190(local_10,param_1);
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001e858);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001e880 at 1001e880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001e880(undefined4 *param_1)

{
  LPSTR pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  undefined4 *local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; local_c = param_1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  while (iVar2 = FUN_1001af40(*(undefined1 *)*local_c), iVar2 != 0) {
    pCVar1 = CharNextA((LPCSTR)*local_c);
    *local_c = pCVar1;
  }
  return;
}



// Function: FUN_1001e8f0 at 1001e8f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCSTR __cdecl FUN_1001e8f0(LPSTR param_1,char param_2)

{
  LPSTR pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  LPCSTR local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (LPCSTR)0x0;
  if (param_1 == (LPSTR)0x0) {
    pCVar1 = (LPCSTR)0x0;
  }
  else {
    for (; (pCVar1 = local_c, *param_1 != '\0' && (pCVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextA(param_1)) {
    }
  }
  return pCVar1;
}



// Function: FUN_1001e970 at 1001e970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1001e970(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  undefined4 local_18;
  int local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001b080();
  local_18 = FUN_1001b130((void *)(local_c + 4),(undefined4 *)&stack0x00000004);
  FUN_1001ebe0();
  return local_18;
}



// Function: FUN_1001e9e0 at 1001e9e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001e9e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_d4 [50];
  int local_c;
  
  piVar2 = local_d4;
  for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = -0x33333334;
    piVar2 = piVar2 + 1;
  }
  if (*(int *)(param_1 + 4) != 0) {
    local_c = param_1;
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_d4[0] = 0;
      }
      else {
        local_d4[0] = param_1 + 4;
      }
      FUN_10016ff0(local_d4[0]);
      *(undefined4 *)(local_c + 0xc) = 0;
    }
    if (*(int *)(local_c + 0x28) != 0) {
      (**(code **)(**(int **)(local_c + 0x28) + 8))(*(undefined4 *)(local_c + 0x28));
    }
    CSymbolicTreeNode_get_ChildCount((LPCRITICAL_SECTION)(local_c + 0x10));
    *(undefined4 *)(local_c + 4) = 0;
  }
  return;
}



// Function: FUN_1001eaa0 at 1001eaa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001eaa0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_e8 [49];
  int *local_24;
  int *local_18;
  int local_c;
  
  puVar2 = local_e8;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_18 = *(int **)(param_1 + 0x2c); *local_18 != 0; local_18 = local_18 + 9) {
      if (local_18[4] != 0) {
        (**(code **)(*(int *)local_18[4] + 8))(local_18[4]);
      }
      local_18[4] = 0;
      (*(code *)local_18[8])(0);
    }
  }
  for (local_24 = DAT_1003395c; local_24 < DAT_10033960; local_24 = local_24 + 1) {
    if (*local_24 != 0) {
      (**(code **)(*local_24 + 0x1c))(0);
    }
  }
  FUN_1001e9e0(local_c);
  return;
}



// Function: FUN_1001eb90 at 1001eb90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1001eb90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  FUN_10007610((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1001ebe0 at 1001ebe0

undefined4 FUN_1001ebe0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// Function: FUN_1001ec10 at 1001ec10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1001ec10(int param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = 0;
  if (DAT_1003389c != (code *)0x0) {
    local_18 = (*DAT_1003389c)();
  }
  if (-1 < local_18) {
    local_18 = FUN_1001ec90(&DAT_10033954,param_1,param_2);
  }
  return local_18;
}



// Function: FUN_1001ec90 at 1001ec90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1001ec90(void *this,int param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [49];
  void *local_c;
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = this;
  FUN_10017540((int)this,param_1,param_2);
  return;
}



// Function: FUN_1001ece0 at 1001ece0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1001ece0(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_e8 [49];
  int *local_24;
  int local_18;
  void *local_c;
  
  puVar4 = local_e8;
  for (iVar3 = 0x39; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = 0;
  local_24 = *(int **)((int)this + 0x2c);
  local_c = this;
  if (local_24 != (int *)0x0) {
    for (; *local_24 != 0; local_24 = local_24 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_100204d0(param_2,(void *)*local_24), CONCAT31(extraout_var,bVar1) != 0)) {
        piVar2 = (int *)(*(code *)local_24[7])(0);
        local_18 = FUN_10018120((GUID *)*local_24,piVar2,0x1001ed5d);
        if ((local_18 < 0) || (local_18 = (*(code *)local_24[1])(0), local_18 < 0)) break;
      }
    }
  }
  if (-1 < local_18) {
    local_18 = FUN_1001ec10(param_1,param_2);
  }
  return local_18;
}



// Function: FUN_1001edd0 at 1001edd0

undefined4 FUN_1001edd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x80004005;
}



// Function: FUN_1001ee00 at 1001ee00

undefined4 FUN_1001ee00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return 0x80004005;
}



// Function: FUN_1001ee30 at 1001ee30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1001ee30(int *param_1,ushort param_2,int param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  uint uVar4;
  HMODULE pHVar5;
  int iVar6;
  LPWSTR *ppWVar7;
  LPCSTR lpModuleName;
  LPWSTR local_b5c [2];
  int local_b54;
  LPWSTR local_b50;
  LPWSTR local_b4c;
  LPWSTR local_b44;
  LPWSTR local_b38;
  undefined4 local_b2c;
  uint local_b20;
  undefined4 local_b14;
  undefined4 local_b08;
  uint local_afc;
  int local_af0;
  int local_ae4;
  LPWSTR local_ad8;
  _RTC_ALLOCA_NODE *local_a0c [3];
  wchar_t *local_a00;
  size_t local_9f4;
  wchar_t local_9e8;
  undefined1 local_9e6 [1054];
  int local_5c8;
  wchar_t local_5bc [524];
  LPWSTR local_1a4;
  DWORD local_198;
  HMODULE local_18c;
  CHAR local_180 [268];
  int local_74 [3];
  char *local_68;
  UINT local_50;
  uint local_44 [3];
  LPWSTR local_38;
  undefined4 local_2c [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027cd0;
  local_10 = ExceptionList;
  ppWVar7 = local_b5c;
  for (iVar6 = 0x2d3; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a0c[0] = (_RTC_ALLOCA_NODE *)0x0;
  FUN_100142b0(local_2c);
  local_8 = 0;
  local_38 = (LPWSTR)FUN_1001a020();
  if ((int)local_38 < 0) {
    local_8 = 0xffffffff;
    local_b44 = local_38;
    FUN_100150b0(local_2c);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10015e40((int)local_2c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_38 = (LPWSTR)(**(code **)(*param_1 + 0x14))(local_2c);
    if ((int)local_38 < 0) {
      local_8 = 0xffffffff;
      local_b38 = local_38;
      FUN_100150b0(local_2c);
    }
    else {
      local_50 = FUN_1000a4a0();
      FUN_10002640(local_74);
      local_8._0_1_ = 1;
      local_18c = (HMODULE)FUN_10008d40(0x1003391c);
      local_198 = GetModuleFileNameA(local_18c,local_180,0x104);
      lpModuleName = (LPCSTR)0x1001ef7c;
      if (local_198 == 0) {
        local_b2c = FUN_10017900();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100043e0(local_74);
        local_8 = 0xffffffff;
        FUN_100150b0(local_2c);
      }
      else if (local_198 == 0x104) {
        local_b20 = FUN_1000f730(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100043e0(local_74);
        local_8 = 0xffffffff;
        FUN_100150b0(local_2c);
      }
      else {
        local_1a4 = (LPWSTR)0x0;
        local_68 = local_180;
        if (local_68 == (char *)0x0) {
          local_b4c = (LPWSTR)0x0;
        }
        else {
          sVar3 = strlen(local_68);
          local_44[0] = sVar3 + 1;
          uVar4 = FUN_100014b0(local_44,local_44[0],2);
          if ((int)uVar4 < 0) {
            local_b50 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_44[0] < 0x401) && (cVar1 = FUN_1000a520(local_44[0]), cVar1 != '\0')) {
              local_b54 = local_44[0] + 0x24;
              local_b5c[1] = (LPWSTR)&stack0xfffff494;
              _RTC_AllocaHelper(&stack0xfffff494,local_b54,local_a0c);
              local_b5c[0] = (LPWSTR)((int)local_b5c[1] + 0x20);
              local_b5c[1] = local_b5c[0];
            }
            else {
              local_b5c[0] = (LPWSTR)FUN_10006820(local_44[0]);
            }
            local_b50 = FUN_100068f0(local_b5c[0],local_68,local_44[0] >> 1,local_50);
          }
          local_b4c = local_b50;
        }
        local_1a4 = local_b4c;
        if (local_b4c == (LPWSTR)0x0) {
          local_b14 = 0x8007000e;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100043e0(local_74);
          local_8 = 0xffffffff;
          FUN_100150b0(local_2c);
        }
        else {
          FUN_10019e90(local_5bc,0x208,local_b4c);
          if ((local_18c == (HMODULE)0x0) ||
             (pHVar5 = GetModuleHandleA(lpModuleName), local_18c == pHVar5)) {
            local_9e8 = L'\"';
            bVar2 = FUN_10020110(local_9e6,0x20b,local_5bc);
            if (!bVar2) {
              local_b08 = 0x80004005;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100043e0(local_74);
              local_8 = 0xffffffff;
              FUN_100150b0(local_2c);
              goto LAB_1001f39b;
            }
            local_9f4 = FUN_1000e9c0(&local_9e8);
            *(undefined2 *)(local_9e6 + local_9f4 * 2 + -2) = 0x22;
            local_afc = local_9f4 * 2 + 2;
            if (0x417 < local_afc) {
              ___report_rangecheckfailure();
            }
            *(undefined2 *)(local_9e6 + (local_afc - 2)) = 0;
            local_5c8 = FUN_10015e40((int)local_2c,L"Module",&local_9e8);
          }
          else {
            local_5c8 = FUN_10015e40((int)local_2c,L"Module",local_5bc);
          }
          if (local_5c8 < 0) {
            local_af0 = local_5c8;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100043e0(local_74);
            local_8 = 0xffffffff;
            FUN_100150b0(local_2c);
          }
          else {
            local_5c8 = FUN_10015e40((int)local_2c,L"Module_Raw",local_5bc);
            if (local_5c8 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              local_ae4 = local_5c8;
              FUN_100043e0(local_74);
              local_8 = 0xffffffff;
              FUN_100150b0(local_2c);
            }
            else {
              local_a00 = L"REGISTRY";
              if (param_3 == 0) {
                local_b4c = (LPWSTR)FUN_1001df90(local_2c,local_1a4,param_2,L"REGISTRY");
              }
              else {
                local_b4c = (LPWSTR)FUN_1001d9b0(local_2c,local_1a4,param_2,L"REGISTRY");
              }
              local_38 = local_b4c;
              local_ad8 = local_b4c;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100043e0(local_74);
              local_8 = 0xffffffff;
              FUN_100150b0(local_2c);
            }
          }
        }
      }
    }
  }
LAB_1001f39b:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001f3d8,local_a0c[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f490 at 1001f490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1001f490(int *param_1,char *param_2,int param_3,int *param_4)

{
  bool bVar1;
  char cVar2;
  HMODULE pHVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  LPWSTR *ppWVar7;
  LPCSTR lpModuleName;
  LPWSTR local_b74 [2];
  int local_b6c;
  LPWSTR local_b68;
  LPWSTR local_b64;
  LPWSTR local_b5c;
  LPWSTR local_b50;
  undefined4 local_b44;
  uint local_b38;
  undefined4 local_b2c;
  undefined4 local_b20;
  uint local_b14;
  int local_b08;
  int local_afc;
  undefined4 local_af0;
  LPWSTR local_ae4;
  _RTC_ALLOCA_NODE *local_a18 [3];
  wchar_t *local_a0c;
  wchar_t *local_a00;
  size_t local_9f4;
  wchar_t local_9e8;
  undefined1 local_9e6 [1054];
  int local_5c8;
  wchar_t local_5bc [524];
  LPWSTR local_1a4;
  DWORD local_198;
  HMODULE local_18c;
  CHAR local_180 [268];
  int local_74 [3];
  char *local_68;
  UINT local_50;
  uint local_44 [3];
  LPWSTR local_38;
  undefined4 local_2c [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027d10;
  local_10 = ExceptionList;
  ppWVar7 = local_b74;
  for (iVar6 = 0x2d9; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  local_14 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a18[0] = (_RTC_ALLOCA_NODE *)0x0;
  FUN_100142b0(local_2c);
  local_8 = 0;
  local_38 = (LPWSTR)FUN_1001a020();
  if ((int)local_38 < 0) {
    local_8 = 0xffffffff;
    local_b5c = local_38;
    FUN_100150b0(local_2c);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10015e40((int)local_2c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_38 = (LPWSTR)(**(code **)(*param_1 + 0x14))(local_2c);
    if ((int)local_38 < 0) {
      local_8 = 0xffffffff;
      local_b50 = local_38;
      FUN_100150b0(local_2c);
    }
    else {
      local_50 = FUN_1000a4a0();
      FUN_10002640(local_74);
      local_8._0_1_ = 1;
      local_18c = (HMODULE)FUN_10008d40(0x1003391c);
      local_198 = GetModuleFileNameA(local_18c,local_180,0x104);
      lpModuleName = (LPCSTR)0x1001f5dc;
      if (local_198 == 0) {
        local_b44 = FUN_10017900();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100043e0(local_74);
        local_8 = 0xffffffff;
        FUN_100150b0(local_2c);
      }
      else if (local_198 == 0x104) {
        local_b38 = FUN_1000f730(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100043e0(local_74);
        local_8 = 0xffffffff;
        FUN_100150b0(local_2c);
      }
      else {
        local_1a4 = (LPWSTR)0x0;
        local_68 = local_180;
        if (local_68 == (char *)0x0) {
          local_b64 = (LPWSTR)0x0;
        }
        else {
          sVar4 = strlen(local_68);
          local_44[0] = sVar4 + 1;
          uVar5 = FUN_100014b0(local_44,local_44[0],2);
          if ((int)uVar5 < 0) {
            local_b68 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_44[0] < 0x401) && (cVar2 = FUN_1000a520(local_44[0]), cVar2 != '\0')) {
              local_b6c = local_44[0] + 0x24;
              local_b74[1] = (LPWSTR)&stack0xfffff47c;
              _RTC_AllocaHelper(&stack0xfffff47c,local_b6c,local_a18);
              local_b74[0] = (LPWSTR)((int)local_b74[1] + 0x20);
              local_b74[1] = local_b74[0];
            }
            else {
              local_b74[0] = (LPWSTR)FUN_10006820(local_44[0]);
            }
            local_b68 = FUN_100068f0(local_b74[0],local_68,local_44[0] >> 1,local_50);
          }
          local_b64 = local_b68;
        }
        local_1a4 = local_b64;
        if (local_b64 == (LPWSTR)0x0) {
          local_b2c = 0x8007000e;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100043e0(local_74);
          local_8 = 0xffffffff;
          FUN_100150b0(local_2c);
        }
        else {
          FUN_10019e90(local_5bc,0x208,local_b64);
          if ((local_18c == (HMODULE)0x0) ||
             (pHVar3 = GetModuleHandleA(lpModuleName), local_18c == pHVar3)) {
            local_9e8 = L'\"';
            bVar1 = FUN_10020110(local_9e6,0x20b,local_5bc);
            if (!bVar1) {
              local_b20 = 0x80004005;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100043e0(local_74);
              local_8 = 0xffffffff;
              FUN_100150b0(local_2c);
              goto LAB_1001fb3c;
            }
            local_9f4 = FUN_1000e9c0(&local_9e8);
            *(undefined2 *)(local_9e6 + local_9f4 * 2 + -2) = 0x22;
            local_b14 = local_9f4 * 2 + 2;
            if (0x417 < local_b14) {
              ___report_rangecheckfailure();
            }
            *(undefined2 *)(local_9e6 + (local_b14 - 2)) = 0;
            local_5c8 = FUN_10015e40((int)local_2c,L"Module",&local_9e8);
          }
          else {
            local_5c8 = FUN_10015e40((int)local_2c,L"Module",local_5bc);
          }
          if (local_5c8 < 0) {
            local_b08 = local_5c8;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100043e0(local_74);
            local_8 = 0xffffffff;
            FUN_100150b0(local_2c);
          }
          else {
            local_5c8 = FUN_10015e40((int)local_2c,L"Module_Raw",local_5bc);
            if (local_5c8 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              local_afc = local_5c8;
              FUN_100043e0(local_74);
              local_8 = 0xffffffff;
              FUN_100150b0(local_2c);
            }
            else {
              local_a00 = L"REGISTRY";
              local_68 = param_2;
              if (param_2 == (char *)0x0) {
                local_b64 = (wchar_t *)0x0;
              }
              else {
                sVar4 = strlen(param_2);
                local_44[0] = sVar4 + 1;
                uVar5 = FUN_100014b0(local_44,local_44[0],2);
                if ((int)uVar5 < 0) {
                  local_b68 = (LPWSTR)0x0;
                }
                else {
                  if (((int)local_44[0] < 0x401) &&
                     (cVar2 = FUN_1000a520(local_44[0]), cVar2 != '\0')) {
                    local_b6c = local_44[0] + 0x24;
                    local_b74[1] = (LPWSTR)&stack0xfffff47c;
                    _RTC_AllocaHelper(&stack0xfffff47c,local_b6c,local_a18);
                    local_b74[0] = (LPWSTR)((int)local_b74[1] + 0x20);
                    local_b74[1] = local_b74[0];
                  }
                  else {
                    local_b74[0] = (LPWSTR)FUN_10006820(local_44[0]);
                  }
                  local_b68 = FUN_100068f0(local_b74[0],local_68,local_44[0] >> 1,local_50);
                }
                local_b64 = local_b68;
              }
              local_a0c = local_b64;
              if (local_b64 == (wchar_t *)0x0) {
                local_af0 = 0x8007000e;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_100043e0(local_74);
                local_8 = 0xffffffff;
                FUN_100150b0(local_2c);
              }
              else {
                if (param_3 == 0) {
                  local_b64 = (LPWSTR)FUN_1001e1e0(local_2c,local_1a4,local_b64,local_a00);
                }
                else {
                  local_b64 = (LPWSTR)FUN_1001dc00(local_2c,local_1a4,local_b64,local_a00);
                }
                local_38 = local_b64;
                local_ae4 = local_b64;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_100043e0(local_74);
                local_8 = 0xffffffff;
                FUN_100150b0(local_2c);
              }
            }
          }
        }
      }
    }
  }
LAB_1001fb3c:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1001fb78,local_a18[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fc30 at 1001fc30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fc30(int *param_1,ushort param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001ee30(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1001fc80 at 1001fc80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fc80(int *param_1,char *param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001f490(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1001fcd0 at 1001fcd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1001fcd0(LPCSTR param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027d4e;
  local_10 = ExceptionList;
  puVar2 = local_dc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  if ((DAT_100338e8 & 1) == 0) {
    DAT_100338e8 = DAT_100338e8 | 1;
    _DAT_100338c8 = &DAT_10029904;
    _DAT_100338cc = 8;
    _DAT_100338d0 = &DAT_1002990c;
    _DAT_100338d4 = 0x4008;
    _DAT_100338d8 = &DAT_10029924;
    _DAT_100338dc = 0x13;
    _DAT_100338e0 = &DAT_1002992c;
    _DAT_100338e4 = 0x11;
    local_8 = 0xffffffff;
  }
  local_18 = 0;
  while( true ) {
    if (3 < local_18) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,*(LPCSTR *)(&DAT_100338c8 + local_18 * 8));
    if (iVar1 == 0) break;
    local_18 = local_18 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_100338cc + local_18 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1001fe00 at 1001fe00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_1001fe00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  local_18 = FUN_1000a4d0(param_1 + 0x14);
  if (-1 < local_18) {
    local_18 = FUN_1001fec0();
  }
  return local_18;
}



// Function: FUN_1001fe60 at 1001fe60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_1001fe60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [49];
  int local_18;
  int local_c;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  local_18 = FUN_1000a4d0(param_1 + 0x14);
  if (-1 < local_18) {
    local_18 = FUN_1001fec0();
  }
  return local_18;
}



// Function: FUN_1001fec0 at 1001fec0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001fec0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001aa60();
  return;
}



// Function: FUN_1001ff10 at 1001ff10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1001ff10(DWORD param_1,DWORD param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_1001ff60 at 1001ff60

undefined ** FUN_1001ff60(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &PTR_DAT_1002afac;
}



// Function: FUN_1001ff90 at 1001ff90

undefined ** FUN_1001ff90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return &PTR_DAT_1002afd4;
}



// Function: FUN_1001ffc0 at 1001ffc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ffc0(int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  ppuVar1 = FUN_1001ff60();
  FUN_10009850(local_c,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10020010 at 10020010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10020010(int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [49];
  int local_c;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  ppuVar1 = FUN_1001ff90();
  FUN_10009850(local_c,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10020060 at 10020060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10020060(uchar *param_1,uchar *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100205a0(param_1,param_2);
  return;
}



// Function: FUN_100200b0 at 100200b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100200b0(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  FUN_10017650(eVar1);
  return;
}



// Function: FUN_10020110 at 10020110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10020110(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  int iVar3;
  bool *pbVar4;
  bool local_c8 [196];
  
  pbVar4 = local_c8;
  for (iVar3 = 0x31; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = true;
    pbVar4[1] = true;
    pbVar4[2] = true;
    pbVar4[3] = true;
    pbVar4 = pbVar4 + 4;
  }
  sVar1 = FUN_1000e9c0(param_3);
  eVar2 = memcpy_s(param_1,param_2 << 1,param_3,sVar1 * 2 + 2);
  return eVar2 == 0;
}



// Function: FUN_100201a0 at 100201a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100201a0(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  eVar1 = strcat_s(param_1,param_2,param_3);
  FUN_10017650(eVar1);
  return;
}



// Function: FUN_10020200 at 10020200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10020200(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  eVar1 = strcpy_s(param_1,param_2,param_3);
  FUN_10017650(eVar1);
  return;
}



// Function: FUN_10020260 at 10020260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10020260(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_10020540(param_1,param_2,param_3,param_4);
  FUN_10017650(uVar1);
  return;
}



// Function: FUN_100202c0 at 100202c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100202c0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c4 [48];
  
  puVar3 = local_c4;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  FUN_10017650(eVar1);
  return;
}



// Function: DllCanUnloadNow at 10020320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  uint *puVar2;
  uint local_c8 [49];
  
                    /* 0x20320  1  DllCanUnloadNow */
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_1001a760(0x100338ec);
  local_c8[0] = (uint)(iVar1 != 0);
  return local_c8[0];
}



// Function: DllGetClassObject at 10020380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_c4 [48];
  
                    /* 0x20380  2  DllGetClassObject */
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uVar3 = FUN_1001a3f0(0x100338ec,rclsid,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)uVar3;
}



// Function: FUN_100203d0 at 100203d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100203d0(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_2 == 1) {
    FUN_1001aa90(&DAT_100338ec,0x10033380,param_1,(undefined4 *)&DAT_1002ac74);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1001eaa0(0x100338ec);
  }
  return 1;
}



// Function: DllRegisterServer at 10020450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllRegisterServer(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
                    /* 0x20450  3  DllRegisterServer */
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001ca80(&DAT_100338ec,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10020490

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllUnregisterServer(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
                    /* 0x20490  4  DllUnregisterServer */
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1001ece0(&DAT_100338ec,1,(void *)0x0);
  return;
}



// Function: FUN_100204d0 at 100204d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_100204d0(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c8 [49];
  
  puVar2 = local_c8;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}



// Function: FUN_10020540 at 10020540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10020540(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100205a0 at 100205a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_100205a0(uchar *param_1,uchar *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _mbsstr(param_1,param_2);
  return;
}



// Function: FUN_100205f0 at 100205f0

undefined4 * __thiscall FUN_100205f0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027d78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_100207d0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10020670 at 10020670

int * __thiscall FUN_10020670(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_100206a0 at 100206a0

int * __thiscall FUN_100206a0(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_100206d0 at 100206d0

void * __thiscall FUN_100206d0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027da8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_100207d0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10020750 at 10020750

void * __thiscall FUN_10020750(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027dd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_10020890(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100207d0 at 100207d0

int __thiscall FUN_100207d0(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027e08;
  local_10 = ExceptionList;
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_100295a8,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10020890 at 10020890

int __thiscall FUN_10020890(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027e38;
  local_10 = ExceptionList;
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_1002b18c,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10020950 at 10020950

undefined4 * __fastcall FUN_10020950(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100209a0 at 100209a0

undefined4 * __fastcall FUN_100209a0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10020a10 at 10020a10

undefined4 * __thiscall FUN_10020a10(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_100223c0(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return (undefined4 *)this;
}



// Function: FUN_10020a50 at 10020a50

int * __thiscall FUN_10020a50(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10020a80 at 10020a80

int * __thiscall FUN_10020a80(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10020aa0 at 10020aa0

undefined4 * __thiscall FUN_10020aa0(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10020ae0 at 10020ae0

int * __thiscall FUN_10020ae0(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10031470);
  }
  return (int *)this;
}



// Function: FUN_10020b40 at 10020b40

int * __thiscall FUN_10020b40(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10031470);
}



// Function: FUN_10020b80 at 10020b80

int * __thiscall FUN_10020b80(void *this,int param_1,char param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if ((param_2 == '\0') || (param_1 == 0)) {
    *(int *)this = param_1;
  }
  else {
    uVar2 = Ordinal_149(param_1);
    iVar3 = Ordinal_150(param_1,uVar2);
    *(int *)this = iVar3;
    if (iVar3 == 0) {
      _com_issue_error(-0x7ff8fff2);
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
  }
  return (int *)this;
}



// Function: FUN_10020bd0 at 10020bd0

int * __thiscall FUN_10020bd0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  return (int *)this;
}



// Function: FUN_10020c00 at 10020c00

undefined4 * __thiscall FUN_10020c00(void *this,int param_1,char param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027ecb;
  local_10 = ExceptionList;
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    if ((param_2 != '\0') && (param_1 != 0)) {
      uVar3 = Ordinal_149(param_1,uVar1);
      iVar4 = Ordinal_150(param_1,uVar3);
      *piVar2 = iVar4;
      if (iVar4 != 0) goto LAB_10020c82;
      _com_issue_error(-0x7ff8fff2);
    }
    *piVar2 = param_1;
  }
LAB_10020c82:
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: _com_error at 10020cc0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Library: Visual Studio 2012 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: FUN_10020d00 at 10020d00

void __fastcall FUN_10020d00(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027ef8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10033838 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020d50 at 10020d50

void __fastcall FUN_10020d50(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10027f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10033838 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020da0 at 10020da0

void __fastcall FUN_10020da0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10020db0 at 10020db0

void __fastcall FUN_10020db0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10020dc0 at 10020dc0

void __fastcall FUN_10020dc0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10020dd0 at 10020dd0

void __fastcall FUN_10020dd0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10020de0 at 10020de0

void __fastcall FUN_10020de0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10020df0 at 10020df0

int * __thiscall FUN_10020df0(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10031470);
  }
  return (int *)this;
}



// Function: FUN_10020e50 at 10020e50

int * __thiscall FUN_10020e50(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10031470);
}



// Function: FUN_10020e90 at 10020e90

int * __thiscall FUN_10020e90(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
    FUN_1000acb0((int *)this);
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_10020ec0 at 10020ec0

uint __thiscall FUN_10020ec0(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this == 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10020ee0 at 10020ee0

uint __thiscall FUN_10020ee0(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this == 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10020f00 at 10020f00

uint __thiscall FUN_10020f00(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10020f20 at 10020f20

uint __thiscall FUN_10020f20(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10020fd0 at 10020fd0

void __fastcall FUN_10020fd0(int *param_1)

{
  code *pcVar1;
  
  if (*param_1 != 0) {
    return;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_10021050 at 10021050

int * __fastcall FUN_10021050(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10021070 at 10021070

int * __fastcall FUN_10021070(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10021090 at 10021090

ULONG __fastcall FUN_10021090(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002b15c);
  }
  return UVar1;
}



// Function: FUN_100210d0 at 100210d0

void FUN_100210d0(IID *param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_100210f0(param_1,param_2,0,(LPCSTR)0x0,param_3,param_4);
  return;
}



// Function: FUN_100210f0 at 100210f0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100210f0(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char *pcVar1;
  undefined4 *puVar2;
  char cVar3;
  LPWSTR pWVar4;
  LPWSTR pWVar5;
  uint uVar6;
  LPCSTR pCVar7;
  undefined4 *_Memory;
  uint local_30;
  char *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10027f58;
  local_10 = ExceptionList;
  local_30 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_30;
  if (param_2 == (LPCSTR)0x0) goto LAB_10021266;
  _Memory = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_8 = 0;
  pCVar7 = param_2;
  do {
    cVar3 = *pCVar7;
    pCVar7 = pCVar7 + 1;
  } while (cVar3 != '\0');
  pcVar1 = pCVar7 + (1 - (int)(param_2 + 1));
  uVar6 = (int)pcVar1 * 2;
  if ((((int)pcVar1 >> 0x1f) << 1 | (uint)pcVar1 >> 0x1f) + (uint)(0x7fffffff < uVar6) == 0) {
    if (((int)uVar6 < 0x401) && (cVar3 = FUN_1000a520(uVar6), cVar3 != '\0')) {
      pWVar4 = (LPWSTR)&local_30;
    }
    else {
      pWVar4 = (LPWSTR)FUN_10006820(uVar6);
      _Memory = local_18;
    }
    pWVar4 = FUN_100068f0(pWVar4,param_2,(uint)pcVar1 & 0x7fffffff,3);
    if (pWVar4 != (LPWSTR)0x0) {
      pWVar5 = (LPWSTR)0x0;
      if (param_4 == (LPCSTR)0x0) {
LAB_10021224:
        FUN_10021290(param_1,pWVar4,param_3,(int)pWVar5,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        pCVar7 = param_4;
        do {
          cVar3 = *pCVar7;
          pCVar7 = pCVar7 + 1;
        } while (cVar3 != '\0');
        local_1c = pCVar7 + (1 - (int)(param_4 + 1));
        uVar6 = FUN_100014b0((uint *)&local_1c,(uint)local_1c,2);
        pcVar1 = local_1c;
        if (-1 < (int)uVar6) {
          if (((int)local_1c < 0x401) && (cVar3 = FUN_1000a520((int)local_1c), cVar3 != '\0')) {
            pWVar5 = (LPWSTR)&local_30;
          }
          else {
            pWVar5 = (LPWSTR)FUN_10006820((int)pcVar1);
            _Memory = local_18;
          }
          pWVar5 = FUN_100068f0(pWVar5,param_4,(uint)pcVar1 >> 1,3);
          if (pWVar5 != (LPWSTR)0x0) goto LAB_10021224;
        }
      }
    }
  }
  local_8 = 0xffffffff;
  while (_Memory != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_Memory;
    local_18 = puVar2;
    free(_Memory);
    _Memory = puVar2;
  }
LAB_10021266:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021290 at 10021290

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10021290(IID *param_1,LPWSTR param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  errno_t eVar5;
  LPWSTR pWVar6;
  char *pcVar7;
  int *_Memory;
  uint local_440;
  LPOLESTR local_424;
  int *local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10027fcd;
  local_10 = ExceptionList;
  local_440 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (int *)0x0;
  local_420 = (int *)0x0;
  local_8 = 0;
  local_414[0] = '\0';
  local_14 = local_440;
  if (((uint)param_2 & 0xffff0000) == 0) {
    local_41c = (int *)((uint)param_2 & 0xffff);
    iVar4 = LoadStringA(param_7,(UINT)local_41c,local_414,0x400);
    if (iVar4 == 0) {
      eVar5 = strcpy_s(local_414,0x400,"Unknown Error");
      FUN_10017650(eVar5);
    }
    pcVar7 = local_414;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    pcVar7 = pcVar7 + (1 - (int)(local_414 + 1));
    uVar2 = (int)pcVar7 * 2;
    if ((((int)pcVar7 >> 0x1f) << 1 | (uint)pcVar7 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_1000a520(uVar2), cVar3 != '\0')) {
        pWVar6 = (LPWSTR)&local_440;
      }
      else {
        pWVar6 = (LPWSTR)FUN_10006820(uVar2);
        _Memory = local_420;
      }
      param_2 = FUN_100068f0(pWVar6,local_414,(uint)pcVar7 & 0x7fffffff,3);
      if (param_2 != (LPWSTR)0x0) goto LAB_100213ef;
    }
    local_8 = 0xffffffff;
    FUN_100043e0((int *)&local_420);
  }
  else {
LAB_100213ef:
    local_418 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar4 = Ordinal_202(&local_418);
    if (-1 < iVar4) {
      local_41c = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*local_418 + 0xc))(local_418,param_5);
      ProgIDFromCLSID(param_1,&local_424);
      if (local_424 != (LPOLESTR)0x0) {
        (**(code **)(*local_418 + 0x10))(local_418,local_424);
      }
      if ((param_3 != 0) && (param_4 != 0)) {
        (**(code **)(*local_418 + 0x1c))(local_418,param_3);
        (**(code **)(*local_418 + 0x18))(local_418,param_4);
      }
      CoTaskMemFree(local_424);
      (**(code **)(*local_418 + 0x14))(local_418,param_2);
      iVar4 = (**(code **)*local_418)(local_418,&DAT_100295a8,&local_41c);
      if (-1 < iVar4) {
        Ordinal_201(0,local_41c);
      }
      local_8._0_1_ = 2;
      if (local_41c != (int *)0x0) {
        (**(code **)(*local_41c + 8))(local_41c);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_418 != (int *)0x0) {
      (**(code **)(*local_418 + 8))(local_418);
    }
    local_8 = 0xffffffff;
    while (_Memory != (int *)0x0) {
      piVar1 = (int *)*_Memory;
      local_420 = piVar1;
      free(_Memory);
      _Memory = piVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021560 at 10021560

void __thiscall FUN_10021560(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int *)this = param_1;
  return;
}



// Function: FUN_10021580 at 10021580

void __thiscall FUN_10021580(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int *)this = param_1;
  return;
}



// Function: FUN_100215a0 at 100215a0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_100215a0(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  int *piVar1;
  undefined1 *puVar2;
  LPSTR pCVar3;
  HRESULT HVar4;
  void *this;
  uint uStack_207c;
  LPUNKNOWN local_2054;
  undefined1 *local_2050;
  int *local_204c;
  undefined4 local_2048;
  undefined4 local_2044;
  undefined4 local_2040;
  void *local_203c;
  undefined8 local_2038;
  undefined8 local_2030;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002808f;
  local_10 = ExceptionList;
  uStack_207c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2044 = param_2;
  local_2048 = param_4;
  local_2038 = param_5;
  local_2030 = param_6;
  local_2040 = *(undefined4 *)((int)param_1 + 4);
  local_18 = uStack_207c;
  FUN_10022450(param_1,&local_204c);
  piVar1 = local_204c;
  local_8 = 0;
  if ((local_204c != (int *)0x0) && (local_204c[1] == 0)) {
    pCVar3 = ConvertBSTRToString((LPCWSTR)*local_204c);
    piVar1[1] = (int)pCVar3;
  }
  local_203c = (void *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_1002b17c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10029418,&local_2054
                          );
  if (-1 < HVar4) {
    HVar4 = OleRun(local_2054);
    if (-1 < HVar4) {
      HVar4 = (*local_2054->lpVtbl->QueryInterface)(local_2054,(IID *)&DAT_1002b16c,&local_203c);
    }
    (*local_2054->lpVtbl->Release)(local_2054);
    if (-1 < HVar4) goto LAB_100216d2;
  }
  local_203c = (void *)0x0;
  if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
    _com_issue_error(HVar4);
  }
LAB_100216d2:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_2050 = &stack0xffffdf80;
  puVar2 = &stack0xffffdf80;
  if (local_204c != (int *)0x0) {
    InterlockedIncrement(local_204c + 2);
    puVar2 = local_2050;
  }
  local_2050 = puVar2;
  local_8._0_1_ = 3;
  this = (void *)FUN_10020fd0((int *)&local_203c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100229e0(this,local_204c);
  local_8 = 1;
  FUN_10021865();
  return;
}



// Function: Catch@10021725 at 10021725

undefined * Catch_10021725(void)

{
  IUnknown *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  void *extraout_ECX_02;
  IUnknown *extraout_ECX_03;
  int *extraout_ECX_04;
  void *extraout_ECX_05;
  void *pvVar1;
  IUnknown *extraout_ECX_06;
  IUnknown *pIVar2;
  int unaff_EBP;
  int *piVar3;
  
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX;
  }
  FUN_10021090(pIVar2);
  if (*(LPCSTR *)(unaff_EBP + -0x2058) == (LPCSTR)0x0) {
    *(undefined1 *)(unaff_EBP + -0x2014) = 0;
    piVar3 = (int *)0x1fff;
    memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
    FUN_100226d0((ushort)*(undefined4 *)(unaff_EBP + -0x203c),(LPSTR)(unaff_EBP + -0x2014));
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    FUN_10004080((LPCSTR)(unaff_EBP + -0x2014));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_01;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10022760(pvVar1,piVar3);
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    piVar3 = extraout_ECX_00;
    FUN_10004080(*(LPCSTR *)(unaff_EBP + -0x2058));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_02;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10022760(pvVar1,piVar3);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_03;
  }
  FUN_10022820(pIVar2);
  *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
  piVar3 = extraout_ECX_04;
  FUN_10004080("");
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pvVar1 = *(void **)(unaff_EBP + -0x2038);
  if (pvVar1 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar1 = extraout_ECX_05;
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10022850(pvVar1,piVar3);
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_06;
  }
  FUN_10022910(pIVar2);
  return &DAT_10021852;
}



// Function: FUN_10021865 at 10021865

/* WARNING: Removing unreachable block (ram,0x10021b12) */

void FUN_10021865(void)

{
  int *piVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  uchar *puVar4;
  ULONG UVar5;
  int *extraout_EAX;
  int *piVar6;
  int *piVar7;
  LPSTR pCVar8;
  LPCSTR pCVar9;
  undefined4 uVar10;
  LONG LVar11;
  int *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  int *extraout_ECX_02;
  void *extraout_ECX_03;
  void *extraout_ECX_04;
  void *pvVar12;
  undefined4 uVar13;
  void *extraout_ECX_05;
  uchar *unaff_EBX;
  uint unaff_EBP;
  int unaff_EDI;
  undefined4 uStack00000004;
  
  *(undefined8 *)(unaff_EBP - 0x2024) = 0;
  *(undefined8 *)(unaff_EBP - 0x201c) = 0;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 8) + 4))();
  }
  piVar1 = *(int **)(unaff_EDI + 8);
  *(int **)(unaff_EBP - 0x204c) = piVar1;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  if (piVar1 != (int *)0x0) {
    if (piVar1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    (**(code **)(*piVar1 + 0xc))(piVar1);
  }
  puVar4 = _mbsrchr(unaff_EBX,0x2f);
  if (puVar4 == (uchar *)0x0) {
    puVar4 = _mbsrchr(unaff_EBX,0x5c);
  }
  else {
    puVar4 = puVar4 + 1;
  }
  if (puVar4 != (uchar *)0x0) {
    unaff_EBX = puVar4 + 1;
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[8].Release)(pIVar2);
  piVar7 = extraout_ECX;
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002b15c);
    piVar7 = extraout_ECX_00;
  }
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  FUN_10004080(*(LPCSTR *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 9;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_01;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10022760(pvVar12,piVar7);
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  piVar7 = extraout_ECX_02;
  FUN_10004080((LPCSTR)unaff_EBX);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_03;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10022850(pvVar12,piVar7);
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002b15c);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  uVar10 = *(undefined4 *)(unaff_EBP - 0x203c);
  uVar13 = uVar10;
  UVar5 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002b15c);
  }
  if (*(char *)(unaff_EBP + 0x28) != '\0') {
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7,uVar13);
    }
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    Ordinal_202(unaff_EBP - 0x203c);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar7 = extraout_EAX;
    }
    (**(code **)(*piVar7 + 0xc))(piVar7,unaff_EBP - 0x2024);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    pvVar12 = *(void **)(unaff_EBP - 0x2038);
    if (pvVar12 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar12 = extraout_ECX_04;
    }
    piVar6 = FUN_100225b0(pvVar12,(undefined4 *)(unaff_EBP - 0x2040));
    *(undefined1 *)(unaff_EBP - 4) = 0xc;
    if ((undefined4 *)*piVar6 == (undefined4 *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)*piVar6;
    }
    (**(code **)(*piVar7 + 0x14))(piVar7,uVar13);
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_10005320((int *)(unaff_EBP - 0x2040));
    FUN_100205f0((void *)(unaff_EBP - 0x2040),(int *)(unaff_EBP - 0x203c));
    *(undefined1 *)(unaff_EBP - 4) = 0xd;
    piVar7 = *(int **)(unaff_EBP - 0x2040);
    if (piVar7 != (int *)0x0) {
      if (piVar7 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      *(undefined ***)(unaff_EBP - 0x2068) = _com_error::vftable;
      *(undefined4 *)(unaff_EBP - 0x2064) = uVar10;
      *(int **)(unaff_EBP - 0x2060) = piVar7;
      *(undefined4 *)(unaff_EBP - 0x205c) = 0;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_10031470);
    }
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7);
    }
  }
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_05;
  }
  piVar7 = FUN_100225b0(pvVar12,(undefined4 *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 0xe;
  puVar3 = (undefined4 *)*piVar7;
  if (puVar3 == (undefined4 *)0x0) {
    pCVar9 = (LPCSTR)0x0;
  }
  else {
    if (puVar3[1] == 0) {
      pCVar8 = ConvertBSTRToString((LPCWSTR)*puVar3);
      puVar3[1] = pCVar8;
    }
    pCVar9 = (LPCSTR)puVar3[1];
  }
  uVar10 = FUN_100210f0((IID *)(unaff_EBP - 0x2034),pCVar9,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar10);
  *(undefined4 *)(unaff_EBP - 0x2040) = uVar10;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  piVar7 = *(int **)(unaff_EBP - 0x2044);
  if (piVar7 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar7 + 2);
    if ((LVar11 == 0) && (piVar7 != (int *)0x0)) {
      if (*piVar7 != 0) {
        Ordinal_6(*piVar7);
        *piVar7 = 0;
      }
      if ((void *)piVar7[1] != (void *)0x0) {
        operator_delete((void *)piVar7[1]);
        piVar7[1] = 0;
      }
      operator_delete(piVar7);
    }
    *(undefined4 *)(unaff_EBP - 0x2044) = 0;
  }
  *(undefined1 *)(unaff_EBP - 4) = 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP - 4) = 0;
  piVar1 = *(int **)(unaff_EBP - 0x2038);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP - 0x2048);
  if (piVar1 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar1 + 2);
    if ((LVar11 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
        *piVar1 = 0;
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete((void *)piVar1[1]);
        piVar1[1] = 0;
      }
      operator_delete(piVar1);
    }
    *(undefined4 *)(unaff_EBP - 0x2048) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack00000004 = 0x10021c87;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10021c90 at 10021c90

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10021c90(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_10021ed0(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021d00 at 10021d00

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10021d00(uchar *param_1)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_10021ed0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021d70 at 10021d70

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10021d70(uchar *param_1)

{
  char *in_stack_00000014;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000014,&stack0x00000018);
  FUN_10021ed0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021de0 at 10021de0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10021de0(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_10021ed0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021e50 at 10021e50

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10021e50(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_10021ed0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021ed0 at 10021ed0

/* WARNING: Removing unreachable block (ram,0x1002209e) */

void __cdecl FUN_10021ed0(uchar *param_1)

{
  byte bVar1;
  IID *pIVar2;
  int *piVar3;
  void **ppvObject;
  HRESULT HVar4;
  uint uVar5;
  int *extraout_EAX;
  IUnknown *extraout_EAX_00;
  int iVar6;
  ULONG UVar7;
  uchar *puVar8;
  undefined4 **ppuVar9;
  IUnknown *extraout_EAX_01;
  IUnknown *pIVar10;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int *piVar11;
  byte *pbVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  IUnknown *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  IUnknown *extraout_ECX_07;
  IUnknown *extraout_ECX_08;
  undefined4 uVar13;
  undefined4 *puVar14;
  bool bVar15;
  int in_stack_00000014;
  byte *in_stack_00000018;
  undefined4 in_stack_00000020;
  LPCSTR in_stack_00000024;
  undefined **local_3c [2];
  int *local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 *local_28;
  IID *local_24;
  LPUNKNOWN local_20;
  int *local_1c;
  int *local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10028113;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_10033838 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_1002b17c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10029418,&local_20);
  if (HVar4 < 0) {
LAB_10021f64:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_1002b16c,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_10021f64;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar12 = PTR_s_APPEND_1003381c;
  do {
    bVar1 = *in_stack_00000018;
    bVar15 = bVar1 < *pbVar12;
    if (bVar1 != *pbVar12) {
LAB_10021fb0:
      uVar5 = -(uint)bVar15 | 1;
      goto LAB_10021fb5;
    }
    if (bVar1 == 0) break;
    bVar1 = in_stack_00000018[1];
    bVar15 = bVar1 < pbVar12[1];
    if (bVar1 != pbVar12[1]) goto LAB_10021fb0;
    in_stack_00000018 = in_stack_00000018 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_10021fb5:
  if (uVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      FUN_10020750(&local_1c,(int *)&local_18);
      local_24 = (IID *)0x0;
      piVar11 = local_18;
      if (local_18 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar11 = extraout_EAX;
      }
      (**(code **)(*piVar11 + 0x14))(piVar11);
      pIVar2 = local_24;
      if (local_24 != (IID *)0x0) {
        local_2c = (int *)operator_new(0xc);
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        if (local_2c == (int *)0x0) {
          local_2c = (int *)0x0;
        }
        else {
          local_2c[1] = 0;
          local_2c[2] = 1;
          *local_2c = (int)pIVar2;
        }
        local_8._0_1_ = 2;
        if (local_2c == (int *)0x0) {
          _com_issue_error(-0x7ff8fff2);
        }
        local_8._0_1_ = 4;
        pIVar10 = local_14;
        if (local_14 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar10 = extraout_EAX_00;
        }
        (*pIVar10->lpVtbl[9].QueryInterface)(pIVar10,local_24,ppvObject);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10005320((int *)&local_2c);
      }
    }
  }
  if (local_1c == (int *)0x0) {
    local_1c = (int *)0x0;
    Ordinal_202();
    local_2c = (int *)&stack0xffffffb4;
    piVar11 = local_1c;
    piVar3 = (int *)&stack0xffffffb4;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 4))(local_1c);
      piVar3 = local_2c;
    }
    local_2c = piVar3;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
    iVar6 = FUN_100207d0(&local_18,piVar11);
    if ((iVar6 < 0) && (iVar6 != -0x7fffbffe)) {
      _com_issue_error(iVar6);
    }
  }
  pIVar10 = local_14;
  if (local_1c == (int *)0x0) {
    local_8._0_1_ = 1;
    if (local_14 != (IUnknown *)0x0) {
      (*local_14->lpVtbl->Release)(local_14);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    ExceptionList = local_10;
    return;
  }
  puVar14 = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[8].Release)(pIVar10);
  piVar11 = extraout_ECX;
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002b15c);
    piVar11 = extraout_ECX_00;
  }
  pIVar10 = local_14;
  if (in_stack_00000014 == 1) {
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
    piVar11 = extraout_ECX_02;
  }
  else {
    if (in_stack_00000014 != 2) {
      if (in_stack_00000014 != 3) goto LAB_100221af;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002b16c);
      }
    }
    pIVar10 = local_14;
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[10].AddRef)(pIVar10);
    piVar11 = extraout_ECX_01;
  }
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002b16c);
    piVar11 = extraout_ECX_03;
  }
LAB_100221af:
  local_2c = (int *)&stack0xffffffb4;
  FUN_10004080(in_stack_00000024);
  local_8._0_1_ = 7;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_04;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10022760(pIVar10,piVar11);
  puVar8 = _mbsrchr(param_1,0x2f);
  if (puVar8 == (uchar *)0x0) {
    puVar8 = _mbsrchr(param_1,0x5c);
    piVar11 = extraout_ECX_06;
  }
  else {
    puVar8 = puVar8 + 1;
    piVar11 = extraout_ECX_05;
  }
  if (puVar8 != (uchar *)0x0) {
    param_1 = puVar8 + 1;
  }
  local_2c = (int *)&stack0xffffffb4;
  FUN_10004080((LPCSTR)param_1);
  local_8._0_1_ = 8;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_07;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10022850(pIVar10,piVar11);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[4].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002b15c);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[5].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002b15c);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_08;
  }
  ppuVar9 = (undefined4 **)FUN_100225b0(pIVar10,&local_2c);
  local_8._0_1_ = 9;
  if (&local_28 != ppuVar9) {
    FUN_1000acb0((int *)&local_28);
    puVar14 = *ppuVar9;
    local_28 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      InterlockedIncrement(puVar14 + 2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10005320((int *)&local_2c);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_EAX_01;
  }
  (*pIVar10->lpVtbl->Release)(pIVar10);
  local_14 = (IUnknown *)0x0;
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_02;
  }
  (**(code **)(*piVar11 + 0xc))(piVar11,in_stack_00000020);
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_03;
  }
  if (puVar14 == (undefined4 *)0x0) {
    uVar13 = 0;
  }
  else {
    uVar13 = *puVar14;
  }
  (**(code **)(*piVar11 + 0x14))(piVar11,uVar13);
  Ordinal_201(0,local_18);
  local_3c[0] = _com_error::vftable;
  local_34 = local_18;
  local_30 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 4))(local_18);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_3c,(ThrowInfo *)&DAT_10031470);
}



// Function: FUN_100223c0 at 100223c0

HRESULT __thiscall FUN_100223c0(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_1002b16c,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10029418,&param_3);
    if (HVar2 < 0) goto LAB_10022439;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_1002b16c,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10022439:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10022450 at 10022450

undefined4 * __thiscall FUN_10022450(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10028154;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  local_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,&local_14,DAT_10033838 ^ (uint)&stack0xfffffffc);
  }
  uVar2 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar2;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022510 at 10022510

undefined4 __fastcall FUN_10022510(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_10022590 at 10022590

undefined4 __fastcall FUN_10022590(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_100225b0 at 100225b0

undefined4 * __thiscall FUN_100225b0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10028194;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_10033838 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_1002b15c);
  }
  uVar1 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar1;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022670 at 10022670

uint __cdecl FUN_10022670(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10022690 at 10022690

uchar * __cdecl FUN_10022690(uchar *param_1)

{
  uchar *puVar1;
  
  puVar1 = _mbsrchr(param_1,0x2f);
  if (puVar1 == (uchar *)0x0) {
    puVar1 = _mbsrchr(param_1,0x5c);
  }
  else {
    puVar1 = puVar1 + 1;
  }
  if (puVar1 == (uchar *)0x0) {
    return param_1;
  }
  return puVar1 + 1;
}



// Function: FUN_100226d0 at 100226d0

undefined4 __cdecl FUN_100226d0(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: FUN_10022700 at 10022700

void __fastcall FUN_10022700(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002b16c);
  }
  return;
}



// Function: FUN_10022730 at 10022730

void __fastcall FUN_10022730(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002b16c);
  }
  return;
}



// Function: FUN_10022760 at 10022760

void __thiscall FUN_10022760(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100281b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_10033838 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002b15c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022820 at 10022820

void __fastcall FUN_10022820(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002b15c);
  }
  return;
}



// Function: FUN_10022850 at 10022850

void __thiscall FUN_10022850(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100281e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_10033838 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002b15c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10022910 at 10022910

void __fastcall FUN_10022910(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002b15c);
  }
  return;
}



// Function: FUN_10022940 at 10022940

void __fastcall FUN_10022940(int *param_1)

{
  int *piVar1;
  code *pcVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
    return;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



// Function: FUN_100229e0 at 100229e0

HRESULT __thiscall FUN_100229e0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10028218;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_10033838 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002b15c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10022ab0 at 10022ab0

void __cdecl FUN_10022ab0(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  FUN_10017650(eVar1);
  return;
}



// Function: FUN_10022ad0 at 10022ad0

void FUN_10022ad0(uchar *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x10022ad4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsrchr(param_1,param_2);
  return;
}



// Function: CAtlBaseModule at 10022c51

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  uint uVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_1002ce08;
  uVar1 = FUN_10009570((LPCRITICAL_SECTION)(this + 0x14));
  if ((int)uVar1 < 0) {
    DAT_10033890 = 1;
  }
  return this;
}



// Function: FUN_10022c8f at 10022c8f

undefined4 * __thiscall FUN_10022c8f(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 10022c9f

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(void)
   
   Library: Visual Studio 2012 Release */

_ATL_BASE_MODULE70 * __thiscall
ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(_ATL_BASE_MODULE70 *this)

{
  memset(this + 0x14,0,0x18);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  return this;
}



// Function: ~CAtlBaseModule at 10022cc7

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
  RemoveAll((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
             *)(this + 0x2c));
  return;
}



// Function: operator[] at 10022ce5

/* Library Function - Single Match
    public: struct HINSTANCE__ * & __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::operator[](int)
   
   Library: Visual Studio 2012 Release */

HINSTANCE__ ** __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
operator[](CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,int param_1)

{
  code *pcVar1;
  HINSTANCE__ **ppHVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)(this + 4))) {
    return (HINSTANCE__ **)(*(int *)this + param_1 * 4);
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  ppHVar2 = (HINSTANCE__ **)(*pcVar1)();
  return ppHVar2;
}



// Function: Add at 10022d0f

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::Add(struct HINSTANCE__ * const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::Add
          (CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,HINSTANCE__ **param_1)

{
  undefined4 *puVar1;
  HINSTANCE__ **_Memory;
  code *pcVar2;
  void *pvVar3;
  int iVar4;
  uint _Count;
  
  iVar4 = *(int *)(this + 8);
  if (*(int *)(this + 4) == iVar4) {
    _Memory = *(HINSTANCE__ ***)this;
    if ((_Memory <= param_1) && (param_1 < _Memory + iVar4)) {
      FUN_10006cf0(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_10022d46:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_10022d5b;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_10022d46;
    }
    iVar4 = 0;
  }
  else {
LAB_10022d5b:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 10022d87

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(struct HINSTANCE__ *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

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



// Function: GetHInstanceAt at 10022dba

/* Library Function - Single Match
    public: struct HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(CAtlBaseModule *this,int param_1)

{
  HINSTANCE__ **ppHVar1;
  HINSTANCE__ *pHVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  if ((*(int *)(this + 0x30) < param_1) || (param_1 < 0)) {
    pHVar2 = (HINSTANCE__ *)0x0;
  }
  else if (param_1 == *(int *)(this + 0x30)) {
    pHVar2 = *(HINSTANCE__ **)(this + 8);
  }
  else {
    ppHVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
              ::operator[]((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                            *)(this + 0x2c),param_1);
    pHVar2 = *ppHVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return pHVar2;
}



// Function: InternalSetAtIndex at 10022e03

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CSimpleArray<unsigned long,class
   ATL::CSimpleArrayEqualHelper<unsigned long> >::InternalSetAtIndex(int,unsigned long const &)
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::InternalSetAtIndex(int,struct HINSTANCE__ *
   const &)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlControlSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlControlSink *> >::InternalSetAtIndex(int,class
   CDHtmlControlSink * const &)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlElementEventSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlElementEventSink *> >::InternalSetAtIndex(int,class
   CDHtmlElementEventSink * const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall InternalSetAtIndex(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: RemoveAll at 10022e1d

/* Library Function - Single Match
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAll(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAll(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
          *this)

{
  if (*(int *)this != 0) {
    free(*(void **)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// Function: RemoveAt at 10022e3a

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAt(int)
   
   Library: Visual Studio 2012 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAt(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
         *this,int param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 < 0) || (iVar2 = *(int *)(this + 4), iVar2 <= param_1)) {
    iVar2 = 0;
  }
  else {
    if (param_1 != iVar2 + -1) {
      uVar3 = (iVar2 - param_1) * 4;
      pvVar1 = (void *)(*(int *)this + param_1 * 4);
      Checked::memmove_s(pvVar1,uVar3,(void *)((int)pvVar1 + 4),uVar3 - 4);
    }
    *(int *)(this + 4) = *(int *)(this + 4) + -1;
    iVar2 = 1;
  }
  return iVar2;
}



// Function: RemoveResourceInstance at 10022e82

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::RemoveResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2012 Release */

bool __thiscall
ATL::CAtlBaseModule::RemoveResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  HINSTANCE__ **ppHVar1;
  bool bVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  bVar2 = false;
  iVar3 = 0;
  if (0 < *(int *)(this + 0x30)) {
    do {
      ppHVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                ::operator[]((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                              *)(this + 0x2c),iVar3);
      if (*ppHVar1 == param_1) {
        CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
        RemoveAt((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                  *)(this + 0x2c),iVar3);
        bVar2 = true;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0x30));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return bVar2;
}



// Function: memmove_s at 10022edf

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  errno_t eVar1;
  
  eVar1 = ::memmove_s(param_1,param_2,param_3,param_4);
  FUN_10017650(eVar1);
  return;
}



// Function: CAtlComModule at 10022efe

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  uint uVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_100316a0;
  *(undefined **)(this + 0xc) = &DAT_100316a0;
  uVar1 = FUN_10009570((LPCRITICAL_SECTION)(this + 0x10));
  if ((int)uVar1 < 0) {
    DAT_10033890 = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 10022f3d

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 10022f5a

/* Library Function - Single Match
    public: void __thiscall ATL::CAtlComModule::Term(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall ATL::CAtlComModule::Term(CAtlComModule *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if (*(int *)this != 0) {
    piVar3 = *(int **)(this + 8);
    if (piVar3 < *(int **)(this + 0xc)) {
      do {
        if ((*piVar3 != 0) && (piVar1 = *(int **)(*piVar3 + 0x10), *piVar1 != 0)) {
          piVar2 = (int *)DecodePointer((PVOID)*piVar1);
          (**(code **)(*piVar2 + 8))(piVar2);
          *piVar1 = 0;
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 < *(int **)(this + 0xc));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x10));
    *(undefined4 *)this = 0;
  }
  return;
}



// Function: `vector_constructor_iterator' at 10022fa4

/* Library Function - Single Match
    void __stdcall `vector constructor iterator'(void *,unsigned int,int,void * (__thiscall*)(void
   *))
   
   Library: Visual Studio 2012 Release */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_ptr_void_ptr *param_4)

{
  int iVar1;
  void *unaff_EDI;
  
  for (iVar1 = param_3 + -1; -1 < iVar1; iVar1 = iVar1 + -1) {
    (*param_4)(unaff_EDI);
  }
  return;
}



// Function: `vector_destructor_iterator' at 10022fc3

/* Library Function - Single Match
    void __stdcall `vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  return;
}



// Function: _com_dispatch_method at 10022ff0

/* Library Function - Single Match
    long __cdecl _com_dispatch_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2012 Release */

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
    (*(code *)PTR_FUN_10033820)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 10023030

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 10023050

/* Library Function - Single Match
    long __cdecl _com_dispatch_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2012 Release */

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
    (*(code *)PTR_FUN_10033820)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 100230b0

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_10033820)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 100230d0

/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2012 Release */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 **ppuVar3;
  void **unaff_ESI;
  undefined4 **local_8;
  
  local_8 = (undefined4 **)0x0;
  ppuVar3 = (undefined4 **)0x0;
  if ((param_2 != (IUnknown *)0x0) &&
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1002a43c,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_10033820)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_10033820)(param_1);
  return;
}



// Function: FUN_10023150 at 10023150

void FUN_10023150(undefined *param_1)

{
  PTR_FUN_10033820 = param_1;
  return;
}



// Function: _variant_t at 10023160

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_1002317f;
    if (param_2 != 0xb) {
      _com_issue_error(-0x7ff8ffa9);
      pcVar1 = (code *)swi(3);
      p_Var2 = (_variant_t *)(*pcVar1)();
      return p_Var2;
    }
  }
  if (param_2 != 10) {
    if (param_2 == 0xb) {
      *(undefined2 *)this = 0xb;
      *(ushort *)(this + 8) = -(ushort)(param_1 != 0);
      return this;
    }
    *(undefined2 *)this = 3;
    *(long *)(this + 8) = param_1;
    return this;
  }
LAB_1002317f:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 100231f0

/* Library Function - Multiple Matches With Same Base Name
    char * __stdcall _com_util::ConvertBSTRToString(unsigned short *)
    char * __stdcall _com_util::ConvertBSTRToString(wchar_t *)
   
   Library: Visual Studio 2012 Release */

LPSTR ConvertBSTRToString(LPCWSTR param_1)

{
  WCHAR WVar1;
  code *pcVar2;
  uint cbMultiByte;
  DWORD DVar3;
  LPSTR pCVar4;
  int iVar5;
  LPCWSTR pWVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10028240;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return (LPSTR)0x0;
  }
  pWVar6 = param_1;
  do {
    WVar1 = *pWVar6;
    pWVar6 = pWVar6 + 1;
  } while (WVar1 != L'\0');
  iVar5 = ((int)pWVar6 - (int)(param_1 + 1) >> 1) + 1;
  ExceptionList = &local_10;
  cbMultiByte = WideCharToMultiByte(0,0,param_1,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (cbMultiByte == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    _com_issue_error(DVar3);
  }
  local_8 = 0;
  pCVar4 = (LPSTR)operator_new(cbMultiByte);
  local_8 = 0xffffffff;
  if (pCVar4 != (LPSTR)0x0) {
    iVar5 = WideCharToMultiByte(0,0,param_1,iVar5,pCVar4,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar5 == 0) {
      operator_delete(pCVar4);
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    ExceptionList = local_10;
    return pCVar4;
  }
  _com_issue_error(-0x7ff8fff2);
  pcVar2 = (code *)swi(3);
  pCVar4 = (LPSTR)(*pcVar2)();
  return pCVar4;
}



// Function: Catch_All@100232f3 at 100232f3

undefined * Catch_All_100232f3(void)

{
  return &DAT_100232f9;
}



// Function: ConvertStringToBSTR at 10023310

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __stdcall _com_util::ConvertStringToBSTR(char const *)
    wchar_t * __stdcall _com_util::ConvertStringToBSTR(char const *)
   
   Library: Visual Studio 2012 Release */

void ConvertStringToBSTR(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  int cchWideChar;
  DWORD DVar3;
  LPWSTR lpWideCharStr;
  int extraout_EAX;
  uint local_3c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_1002418c;
  local_14 = ExceptionList;
  local_c = DAT_10033838 ^ 0x100314a8;
  uVar1 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_14;
  local_3c = uVar1;
  if (param_1 != (LPCSTR)0x0) {
    iVar2 = lstrlenA(param_1);
    iVar2 = iVar2 + 1;
    cchWideChar = MultiByteToWideChar(0,0,param_1,iVar2,(LPWSTR)0x0,0);
    if (cchWideChar == 0) {
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    local_8 = 0;
    if (cchWideChar < 0x1000) {
      lpWideCharStr = (LPWSTR)&local_3c;
    }
    else {
      lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2);
    }
    local_8 = 0xfffffffe;
    if (lpWideCharStr == (LPWSTR)0x0) {
      _com_issue_error(-0x7ff8fff2);
      iVar2 = extraout_EAX;
    }
    iVar2 = MultiByteToWideChar(0,0,param_1,iVar2,lpWideCharStr,cchWideChar);
    if (iVar2 == 0) {
      if (0xfff < cchWideChar) {
        free(lpWideCharStr);
      }
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    iVar2 = Ordinal_2(lpWideCharStr);
    if (0xfff < cchWideChar) {
      free(lpWideCharStr);
    }
    if (iVar2 == 0) {
      _com_issue_error(-0x7ff8fff2);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10023490 at 10023490

uint FUN_10023490(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100234b0 at 100234b0

void FUN_100234b0(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_c = param_2;
  local_14 = _com_error::vftable;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10031470);
}



// Function: _com_dispatch_raw_method at 100234e0

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2012 Release */

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



// Function: _com_dispatch_raw_propget at 10023520

/* Library Function - Single Match
    long __stdcall _com_dispatch_raw_propget(struct IDispatch *,long,unsigned short,void *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

long _com_dispatch_raw_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_raw_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_raw_propput at 10023540

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2012 Release */

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



// Function: _com_invoke_helper at 100235a0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    long __cdecl _com_invoke_helper(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,char *,struct IErrorInfo * *)
   
   Library: Visual Studio 2012 Release */

long __cdecl
_com_invoke_helper(IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
                  ushort *param_6,char *param_7,IErrorInfo **param_8)

{
  ushort uVar1;
  short *psVar2;
  long lVar3;
  ushort uVar4;
  short *psVar5;
  undefined4 *puVar6;
  int *piVar7;
  ushort *puVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  uint *puVar15;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  uint uStack_9c;
  uint local_8c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ushort *local_4c;
  uint *local_48;
  undefined1 *local_44;
  undefined4 *local_40;
  int local_3c;
  uint local_38;
  undefined4 *local_34;
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
  pcStack_10 = FUN_1002418c;
  local_14 = ExceptionList;
  local_c = DAT_10033838 ^ 0x10031520;
  local_8c = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_10023915;
  if (param_8 != (IErrorInfo **)0x0) {
    *param_8 = (IErrorInfo *)0x0;
  }
  local_44 = (undefined1 *)0x0;
  local_40 = (undefined4 *)0x0;
  local_3c = 0;
  local_38 = 0;
  puVar15 = &local_8c;
  if (param_6 != (ushort *)0x0) {
    local_3c = lstrlenW((LPCWSTR)param_6);
    puVar15 = (uint *)local_1c;
  }
  local_1c = (undefined1 *)puVar15;
  local_54 = 0xfffffffd;
  if ((param_3 & 0xc) != 0) {
    puVar15 = (uint *)local_1c;
    if (local_3c == 0) goto LAB_10023915;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x1002366c;
    memset(&local_8c,0,local_3c * 0x10);
    local_44 = (undefined1 *)&local_8c;
    local_4c = param_6;
    puVar10 = &uStack_9c + local_3c * 4;
    local_48 = puVar10;
    puVar15 = &local_8c;
    if (*param_6 != 0) {
      piVar14 = (int *)(&stack0xffffff6c + local_3c * 0x10);
      piVar7 = (int *)(param_7 + -4);
      local_48 = (uint *)0x5;
      local_50 = 0xe;
      piVar11 = (int *)(param_7 + -8);
      do {
        uVar1 = *local_4c;
        uVar4 = uVar1 & 0xf7ff;
        *(ushort *)puVar10 = uVar4;
        if (0x4002 < uVar4) {
          switch(uVar4) {
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
switchD_100236e5_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_10023915;
          }
switchD_100236e5_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_100237d0;
        }
        if (uVar4 == 0x4002) goto switchD_100236e5_caseD_3;
        switch(uVar4) {
        case 2:
        case 0x12:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(short *)piVar14 = (short)*piVar7;
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
          goto switchD_100236e5_caseD_3;
        case 4:
          *(ushort *)puVar10 = 5;
        case 5:
        case 7:
          piVar12 = piVar11 + 2;
          piVar7 = piVar7 + 2;
          *(undefined8 *)piVar14 = *(undefined8 *)piVar12;
          break;
        case 6:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          piVar11 = (int *)*piVar7;
          *piVar14 = *piVar11;
          piVar14[1] = piVar11[1];
          break;
        case 0xb:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(ushort *)piVar14 = -(ushort)((short)*piVar7 != 0);
          break;
        case 0xc:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          puVar15 = (uint *)*piVar7;
          *puVar10 = *puVar15;
          puVar10[1] = puVar15[1];
          puVar10[2] = puVar15[2];
          puVar10[3] = puVar15[3];
          break;
        case 0xe:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          puVar15 = (uint *)*piVar7;
          *puVar10 = *puVar15;
          puVar10[1] = puVar15[1];
          puVar10[2] = puVar15[2];
          puVar10[3] = puVar15[3];
          *(ushort *)puVar10 = 0xe;
          break;
        default:
          goto switchD_100236e5_caseD_f;
        case 0x10:
        case 0x11:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(char *)piVar14 = (char)*piVar7;
          break;
        case 0x14:
        case 0x15:
          piVar12 = piVar11 + 2;
          piVar7 = piVar7 + 2;
          *piVar14 = *piVar12;
          piVar14[1] = piVar11[3];
        }
LAB_100237d0:
        puVar10 = puVar10 + -4;
        piVar14 = piVar14 + -4;
        local_4c = local_4c + 1;
        piVar11 = piVar12;
        puVar15 = local_34;
      } while (*local_4c != 0);
    }
    psVar5 = (short *)(puVar15 + local_38 * 4);
    puVar8 = param_6 + (local_3c - local_38) + -1;
    iVar13 = 0;
    if (param_6 <= puVar8) {
      while (puVar15 = local_34, (*puVar8 & 0xbfff) == 0x80c) {
        psVar2 = psVar5;
        if ((*puVar8 & 0x4000) != 0) {
          psVar2 = *(short **)(psVar5 + 4);
        }
        if ((*psVar2 != 10) || (*(int *)(psVar2 + 4) != -0x7ffdfffc)) break;
        iVar13 = iVar13 + 1;
        psVar5 = psVar5 + 8;
        puVar8 = puVar8 + -1;
        if (puVar8 < param_6) break;
      }
    }
    if (iVar13 != 0) {
      uVar9 = 0;
      if (local_38 != 0) {
        puVar6 = puVar15 + iVar13 * 4;
        do {
          *puVar6 = *puVar15;
          puVar6[1] = puVar15[1];
          puVar6[2] = puVar15[2];
          puVar6[3] = puVar15[3];
          uVar9 = uVar9 + 1;
          puVar15 = puVar15 + 4;
          puVar6 = puVar6 + 4;
        } while (uVar9 < local_38);
      }
      local_3c = local_3c - iVar13;
      local_44 = local_44 + iVar13 * 0x10;
    }
  }
  Ordinal_8();
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0xffffffff;
  uStack_9c = -(uint)(param_4 != 0) & (uint)&local_30;
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_100293c4,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_10023915;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_10023915;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_10023915;
  }
  puVar15 = (uint *)local_1c;
  if (param_4 < 0x4003) {
    if (param_4 != 0x4002) {
      switch(param_4) {
      case 2:
      case 0xb:
      case 0x12:
        *(ushort *)param_5 = CONCAT11(uStack_27,local_28);
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
        goto switchD_100239bf_caseD_3;
      case 4:
        *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        break;
      case 5:
      case 7:
        *(ulonglong *)param_5 = CONCAT44(uStack_24,CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)))
        ;
        break;
      case 6:
      case 0x14:
      case 0x15:
        *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        *(undefined4 *)((int)param_5 + 4) = uStack_24;
        break;
      case 0xc:
      case 0xe:
        *(undefined4 *)param_5 = local_30;
        *(undefined4 *)((int)param_5 + 4) = local_2c;
        *(uint *)((int)param_5 + 8) = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        *(undefined4 *)((int)param_5 + 0xc) = uStack_24;
        break;
      default:
        goto switchD_100239bf_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_10023915;
    }
  }
  else {
    switch(param_4) {
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
switchD_100239bf_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_10023915;
      }
    }
  }
switchD_100239bf_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_10023915:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_10023b50 at 10023b50

int FUN_10023b50(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 10023b80

/* Library Function - Single Match
    long __stdcall _com_handle_excepinfo(struct tagEXCEPINFO &,struct IErrorInfo * *)
   
   Library: Visual Studio 2012 Release */

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
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_10029464);
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
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_100295a8,ppIVar3);
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



// Function: `eh_vector_destructor_iterator' at 10023c76

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_10023cd5();
  return;
}



// Function: FUN_10023cd5 at 10023cd5

void FUN_10023cd5(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  void *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_ESI,unaff_EBX,unaff_EDI,*(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: FUN_10023ce5 at 10023ce5

undefined4 __cdecl FUN_10023ce5(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 10023cfe

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

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



// Function: __security_check_cookie at 10023d62

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10033838) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: _RTC_AllocaHelper at 10023d71

/* Library Function - Single Match
    @_RTC_AllocaHelper@12
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019
   __fastcall _RTC_AllocaHelper,12 */

void __fastcall _RTC_AllocaHelper(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (((param_1 != (undefined1 *)0x0) && (param_2 != 0)) &&
     (iVar1 = param_2, puVar2 = param_1, param_3 != (undefined4 *)0x0)) {
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0xcc;
      puVar2 = puVar2 + 1;
    }
    *(undefined4 *)(param_1 + 4) = *param_3;
    *(int *)(param_1 + 0xc) = param_2;
    *param_3 = param_1;
  }
  return;
}



// Function: _RTC_CheckStackVars2 at 10023da3

/* Library Function - Single Match
    @_RTC_CheckStackVars2@12
   
   Library: Visual Studio 2012 Release
   __fastcall _RTC_CheckStackVars2,12 */

void __fastcall _RTC_CheckStackVars2(int param_1,int *param_2,_RTC_ALLOCA_NODE *param_3)

{
  int iVar1;
  _RTC_ALLOCA_NODE *p_Var2;
  int iVar3;
  void *unaff_retaddr;
  int local_8;
  
  if ((param_2 != (int *)0x0) && (local_8 = 0, 0 < *param_2)) {
    iVar3 = 0;
    do {
      iVar1 = param_2[1];
      if ((*(int *)(*(int *)(iVar3 + iVar1) + -4 + param_1) != -0x33333334) ||
         (*(int *)(*(int *)(iVar3 + 4 + iVar1) + *(int *)(iVar3 + iVar1) + param_1) != -0x33333334))
      {
        _RTC_StackFailure(unaff_retaddr,*(char **)(iVar3 + 8 + iVar1));
      }
      local_8 = local_8 + 1;
      iVar3 = iVar3 + 0xc;
    } while (local_8 < *param_2);
  }
  iVar3 = 0;
  p_Var2 = param_3;
  if (param_3 != (_RTC_ALLOCA_NODE *)0x0) {
    do {
      p_Var2 = *(_RTC_ALLOCA_NODE **)(p_Var2 + 4);
      iVar3 = iVar3 + 1;
    } while (p_Var2 != (_RTC_ALLOCA_NODE *)0x0);
    for (; param_3 != (_RTC_ALLOCA_NODE *)0x0; param_3 = *(_RTC_ALLOCA_NODE **)(param_3 + 4)) {
      if ((((*(int *)param_3 != -0x33333334) || (*(int *)(param_3 + 0x14) != -0x33333334)) ||
          (*(int *)(param_3 + 0x18) != -0x33333334)) || (*(int *)(param_3 + 0x1c) != -0x33333334)) {
        _RTC_AllocaFailure(unaff_retaddr,param_3,iVar3);
      }
      if (*(int *)(param_3 + *(int *)(param_3 + 0xc) + -4) != -0x33333334) {
        _RTC_AllocaFailure(unaff_retaddr,param_3,iVar3);
      }
      iVar3 = iVar3 + -1;
    }
  }
  return;
}



// Function: _RTC_CheckStackVars at 10023e67

/* Library Function - Single Match
    @_RTC_CheckStackVars@8
   
   Library: Visual Studio 2012 Release
   __fastcall _RTC_CheckStackVars,8 */

void __fastcall _RTC_CheckStackVars(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *unaff_retaddr;
  
  iVar2 = 0;
  if (0 < *param_2) {
    iVar3 = 0;
    do {
      iVar1 = param_2[1];
      if ((*(int *)(*(int *)(iVar3 + iVar1) + -4 + param_1) != -0x33333334) ||
         (*(int *)(*(int *)(iVar3 + 4 + iVar1) + *(int *)(iVar3 + iVar1) + param_1) != -0x33333334))
      {
        _RTC_StackFailure(unaff_retaddr,*(char **)(iVar3 + 8 + iVar1));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < *param_2);
  }
  return;
}



// Function: __RTC_CheckEsp at 10023ebd

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __RTC_CheckEsp
   
   Library: Visual Studio 2012 Release */

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



// Function: `eh_vector_constructor_iterator' at 10023f20

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  int iVar1;
  void *in_stack_ffffffcc;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*param_4)(in_stack_ffffffcc);
  }
  FUN_10023f78();
  return;
}



// Function: FUN_10023f78 at 10023f78

void FUN_10023f78(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  void *unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_EDI,unaff_EBX,unaff_ESI,*(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 10023fd0

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2012 Release */

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
  
  local_8 = &DAT_100315a0;
  uStack_c = 0x10023fdc;
  local_20[0] = DecodePointer(DAT_10033d10);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10033d10);
    local_24 = DecodePointer(DAT_10033d0c);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10033d10 = EncodePointer(local_20[0]);
    DAT_10033d0c = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1002406c();
  }
  return p_Var1;
}



// Function: FUN_1002406c at 1002406c

void FUN_1002406c(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10024075

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_10024096 at 10024096

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10024096(uint param_1)

{
  operator_new(param_1);
  FUN_100240be();
  return;
}



// Function: Catch_All@100240b1 at 100240b1

undefined * Catch_All_100240b1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_100240bb;
}



// Function: FUN_100240be at 100240be

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100240be(void)

{
  return;
}



// Function: FUN_100240c4 at 100240c4

void FUN_100240c4(uint param_1)

{
  FUN_10024096(param_1);
  return;
}



// Function: FUN_100240cd at 100240cd

void __cdecl FUN_100240cd(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100240db at 100240db

void __cdecl FUN_100240db(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __allmul at 10024120

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



// Function: __alloca_probe_16 at 10024160

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2012 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 10024176

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



// Function: FUN_1002418c at 1002418c

void __cdecl
FUN_1002418c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10033838,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 100241bf

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CDaoRelationFieldInfo::`vector deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

type_info * __thiscall FID_conflict__vector_deleting_destructor_(void *this,byte param_1)

{
  type_info *ptVar1;
  
  if ((param_1 & 2) == 0) {
    type_info::~type_info((type_info *)this);
    ptVar1 = (type_info *)this;
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    ptVar1 = (type_info *)((int)this + -4);
    _eh_vector_destructor_iterator_(this,0xc,*(int *)ptVar1,type_info::~type_info);
    if ((param_1 & 1) != 0) {
      operator_delete(ptVar1);
    }
  }
  return ptVar1;
}



// Function: ___raise_securityfailure at 10024210

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_10033cdc = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_10033cdc == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 1002424d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_gsfailure(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10033ab8 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10033ac0 = (undefined4)uVar9;
  _DAT_10033ad0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10033ad4 = &stack0x00000004;
  _DAT_10033a10 = 0x10001;
  _DAT_100339c0 = 0xc0000409;
  _DAT_100339c4 = 1;
  _DAT_100339d0 = 1;
  DAT_100339d4 = 2;
  _DAT_100339cc = unaff_retaddr;
  _DAT_10033a9c = in_GS;
  _DAT_10033aa0 = in_FS;
  _DAT_10033aa4 = in_ES;
  _DAT_10033aa8 = in_DS;
  _DAT_10033aac = unaff_EDI;
  _DAT_10033ab0 = unaff_ESI;
  _DAT_10033ab4 = unaff_EBX;
  _DAT_10033abc = uVar3;
  _DAT_10033ac4 = unaff_EBP;
  DAT_10033ac8 = unaff_retaddr;
  _DAT_10033acc = in_CS;
  _DAT_10033ad8 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1002cedc);
  return;
}



// Function: ___report_rangecheckfailure at 10024346

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 10024352

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_securityfailure(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10033ab8 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10033ac0 = (undefined4)uVar9;
  _DAT_10033ad0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10033ad4 = &param_1;
  _DAT_100339c0 = 0xc0000409;
  _DAT_100339c4 = 1;
  _DAT_100339d0 = 1;
  DAT_100339d4 = param_1;
  _DAT_100339cc = unaff_retaddr;
  _DAT_10033a9c = in_GS;
  _DAT_10033aa0 = in_FS;
  _DAT_10033aa4 = in_ES;
  _DAT_10033aa8 = in_DS;
  _DAT_10033aac = unaff_EDI;
  _DAT_10033ab0 = unaff_ESI;
  _DAT_10033ab4 = unaff_EBX;
  _DAT_10033abc = uVar3;
  _DAT_10033ac4 = unaff_EBP;
  DAT_10033ac8 = unaff_retaddr;
  _DAT_10033acc = in_CS;
  _DAT_10033ad8 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1002cedc);
  return;
}



// Function: ___report_securityfailureEx at 10024420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_securityfailureEx
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_securityfailureEx(undefined4 param_1,uint param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  uint local_8;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10033ad0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10033ad4 = &param_1;
  _DAT_100339c0 = 0xc0000409;
  _DAT_100339c4 = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_100339d0 = param_2 + 1;
  DAT_100339d4 = param_1;
  _DAT_100339cc = unaff_retaddr;
  _DAT_10033a9c = in_GS;
  _DAT_10033aa0 = in_FS;
  _DAT_10033aa4 = in_ES;
  _DAT_10033aa8 = in_DS;
  _DAT_10033aac = unaff_EDI;
  _DAT_10033ab0 = unaff_ESI;
  _DAT_10033ab4 = unaff_EBX;
  _DAT_10033abc = uVar3;
  _DAT_10033ac4 = unaff_EBP;
  DAT_10033ac8 = unaff_retaddr;
  _DAT_10033acc = in_CS;
  _DAT_10033ad8 = in_SS;
  for (local_8 = 0; _DAT_10033ab8 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_10033ac0 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_100339d8 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_10033ab8,_DAT_10033ac0);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1002cedc);
  return;
}



// Function: __alloca_probe at 10024560

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



// Function: __CRT_INIT@12 at 100245de

/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 2012 Release */

undefined4 __CRT_INIT_12(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  void *pvVar2;
  void *pvVar3;
  int *_Memory;
  int *piVar4;
  PVOID pvVar5;
  code *pcVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  BOOL BVar10;
  
  if (param_2 == (int *)0x0) {
    if (DAT_10033ce0 < 1) {
      return 0;
    }
    DAT_10033ce0 = DAT_10033ce0 + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10033d00 != (void *)0x0) {
        pvVar3 = DAT_10033d00;
        pvVar2 = DAT_10033d00;
      }
      DAT_10033d00 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_10024631;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_10024631:
    if (DAT_10033d04 == 2) {
      _Memory = (int *)DecodePointer(DAT_10033d10);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10033d0c);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10033d10);
            piVar8 = (int *)DecodePointer(DAT_10033d0c);
            if ((param_2 != piVar7) || (_Memory = param_3, param_1 != piVar8)) {
              piVar4 = piVar8;
              _Memory = piVar7;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        if (_Memory != (int *)0xffffffff) {
          free(_Memory);
        }
        DAT_10033d0c = EncodePointer((PVOID)0x0);
        DAT_10033d10 = DAT_10033d0c;
      }
      DAT_10033d04 = 0;
      if (!bVar1) {
        LOCK();
        DAT_10033d00 = (void *)0x0;
        UNLOCK();
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10033d00 != (void *)0x0) {
        pvVar3 = DAT_10033d00;
        pvVar2 = DAT_10033d00;
      }
      DAT_10033d00 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_1002474c;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_1002474c:
    if (DAT_10033d04 == 0) {
      DAT_10033d04 = 1;
      iVar9 = initterm_e(&DAT_10029268,&DAT_10029274);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_10029230,&DAT_10029264);
      DAT_10033d04 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_10033d00 = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_10033d08 != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10033d08), BVar10 != 0)) {
      (*DAT_10033d08)(param_1,2,param_3);
    }
    DAT_10033ce0 = DAT_10033ce0 + 1;
  }
  return 1;
}



// Function: entry at 100247d3

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 100247f6

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100248a7) */
/* WARNING: Removing unreachable block (ram,0x1002483d) */
/* WARNING: Removing unreachable block (ram,0x100248d9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_10033874 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10033ce0 == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_100203d0(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_100203d0(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_1002491e();
  return uVar1;
}



// Function: FUN_1002491e at 1002491e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002491e(void)

{
  _DAT_10033874 = 0xffffffff;
  return;
}



// Function: __SEH_prolog4 at 10024950

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10033838 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10024995

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



// Function: DebuggerProbe at 100249a9

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerProbe(unsigned long)
   
   Library: Visual Studio 2012 Release */

int __cdecl DebuggerProbe(ulong param_1)

{
  ULONG_PTR local_38;
  ulong local_34;
  byte *local_30;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x100249b5;
  local_1d[0] = 0;
  local_38 = 0x1001;
  local_34 = param_1;
  local_30 = local_1d;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,&local_38);
  return (uint)local_1d[0];
}



// Function: DebuggerRuntime at 10024a0b

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerRuntime(unsigned long,int,void *,wchar_t const *)
   
   Library: Visual Studio 2012 Release */

int __cdecl DebuggerRuntime(ulong param_1,int param_2,void *param_3,wchar_t *param_4)

{
  ULONG_PTR local_38;
  ulong local_34;
  int local_30;
  void *local_2c;
  byte *local_28;
  wchar_t *local_24;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x10024a17;
  local_1d[0] = 0;
  local_38 = 0x1002;
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = local_1d;
  local_24 = param_4;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,&local_38);
  return (uint)local_1d[0];
}



// Function: _RTC_AllocaFailure at 10024a7f

/* Library Function - Single Match
    void __cdecl _RTC_AllocaFailure(void *,struct _RTC_ALLOCA_NODE *,int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_AllocaFailure(void *param_1,_RTC_ALLOCA_NODE *param_2,int param_3)

{
  int iVar1;
  HMODULE hModule;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined *puVar8;
  CHAR local_144 [244];
  char local_50 [52];
  char local_1c [20];
  uint local_8;
  
  iVar1 = DAT_10033870;
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  if (DAT_10033870 != -1) {
    hModule = LoadLibraryExW(L"user32.dll",(HANDLE)0x0,0x800);
    if ((((hModule == (HMODULE)0x0) &&
         ((DVar2 = GetLastError(), DVar2 != 0x57 ||
          (hModule = LoadLibraryW(L"user32.dll"), hModule == (HMODULE)0x0)))) ||
        (DAT_10033ce4 = GetProcAddress(hModule,"wsprintfA"), hModule == (HMODULE)0x0)) ||
       ((param_2 == (_RTC_ALLOCA_NODE *)0x0 || (DAT_10033ce4 == (FARPROC)0x0)))) {
      failwithmessage(param_1,iVar1,4,
                      "Stack area around _alloca memory reserved by this function is corrupted\n");
    }
    else {
      (*DAT_10033ce4)(local_144,"%s%s%p%s%ld%s%d%s",
                      "Stack area around _alloca memory reserved by this function is corrupted",
                      "\nAddress: 0x",param_2 + 0x20,"\nSize: ",*(int *)(param_2 + 0xc) + -0x24,
                      "\nAllocation number within this function: ",param_3,"\nData: <");
      _getMemBlockDataString
                (local_1c,local_50,(char *)(param_2 + 0x20),*(int *)(param_2 + 0xc) - 0x24);
      pcVar7 = local_50;
      puVar8 = &DAT_1002d47c;
      puVar6 = &DAT_1002d480;
      pcVar5 = local_1c;
      pcVar4 = "%s%s%s%s";
      iVar3 = lstrlenA(local_144);
      (*DAT_10033ce4)(local_144 + iVar3,pcVar4,pcVar5,puVar6,pcVar7,puVar8);
      failwithmessage(param_1,iVar1,4,local_144);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _RTC_Failure at 10024bd6

/* Library Function - Single Match
    void __cdecl _RTC_Failure(void *,int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_Failure(void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((uint)param_2 < 5) {
    iVar1 = *(int *)(&DAT_10033860 + param_2 * 4);
    pcVar2 = (&PTR_s_The_value_of_ESP_was_not_properl_1002cf54)[param_2];
  }
  else {
    pcVar2 = "Unknown Runtime Check Error\n\r";
    iVar1 = 1;
    param_2 = 5;
  }
  if (iVar1 != -1) {
    failwithmessage(param_1,iVar1,param_2,pcVar2);
  }
  return;
}



// Function: _RTC_StackFailure at 10024c12

/* Library Function - Single Match
    void __cdecl _RTC_StackFailure(void *,char const *)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_StackFailure(void *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 local_40c;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_40c = param_1;
  if (DAT_10033868 == -1) goto LAB_10024cf2;
  if (*param_2 == '\0') {
LAB_10024cd4:
    pcVar2 = "Stack corrupted near unknown variable";
  }
  else {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((char *)0x400 < pcVar2 + (0x2d - (int)(param_2 + 1))) goto LAB_10024cd4;
    pcVar2 = local_408;
    iVar3 = 0;
    do {
      cVar1 = "Stack around the variable \'"[iVar3];
      local_408[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      pcVar5 = param_2;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)param_2;
    pcVar5 = (char *)((int)&local_40c + 3);
    do {
      pcVar7 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar7 != '\0');
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_2;
      param_2 = param_2 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = "\' was corrupted.";
    do {
      pcVar7 = pcVar5;
      pcVar5 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    pcVar5 = (char *)((int)&local_40c + 3);
    do {
      pcVar8 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = "\' was corrupted.";
    for (uVar6 = (uint)(pcVar7 + -0x1002cf03) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = (uint)(pcVar7 + -0x1002cf03) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  failwithmessage(param_1,DAT_10033868,2,pcVar2);
LAB_10024cf2:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _getMemBlockDataString at 10024cfe

/* Library Function - Single Match
    void __cdecl _getMemBlockDataString(char *,char *,char *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _getMemBlockDataString(char *param_1,char *param_2,char *param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0;
  pcVar3 = param_2;
  pcVar5 = param_1;
  while( true ) {
    uVar2 = param_4;
    if (0xf < param_4) {
      uVar2 = 0x10;
    }
    if (uVar2 <= uVar4) break;
    cVar1 = pcVar5[(int)param_3 - (int)param_1];
    (*DAT_10033ce4)(pcVar3,"%.2X ",cVar1);
    *pcVar5 = cVar1;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 3;
    pcVar5 = pcVar5 + 1;
  }
  param_1[uVar4] = '\0';
  param_2[uVar4 * 3] = '\0';
  return;
}



// Function: failwithmessage at 10024d67

/* Library Function - Single Match
    void __cdecl failwithmessage(void *,int,int,char const *)
   
   Library: Visual Studio 2012 Release */

void __cdecl failwithmessage(void *param_1,int param_2,int param_3,char *param_4)

{
  bool bVar1;
  code *pcVar2;
  uint cchWideChar;
  int iVar3;
  BOOL BVar4;
  char *pcVar5;
  char *pcVar6;
  int local_e40;
  code *local_e3c;
  char *local_e38;
  wchar_t *local_e34;
  WCHAR local_e30 [512];
  CHAR local_a30 [780];
  CHAR local_724 [780];
  wchar_t local_418 [260];
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  local_e3c = (code *)0x0;
  local_e38 = param_4;
  pcVar2 = (code *)FUN_10025034();
  if (pcVar2 == (code *)0x0) {
    local_e3c = (code *)FUN_1002502e();
  }
  cchWideChar = MultiByteToWideChar(0xfde9,0,local_e38,-1,(LPWSTR)0x0,0);
  if (cchWideChar < 0x200) {
    iVar3 = MultiByteToWideChar(0xfde9,0,local_e38,-1,local_e30,cchWideChar);
    if (iVar3 == 0) goto LAB_10024dfb;
    local_e34 = local_e30;
  }
  else {
LAB_10024dfb:
    local_e34 = L"Runtime Check Error.\n\r Unable to display RTC Message.";
  }
  iVar3 = DebuggerProbe(0x1002);
  if (iVar3 == 0) {
    bVar1 = true;
  }
  else {
    iVar3 = DebuggerRuntime(param_3,*(int *)(&DAT_1002cf6c + param_3 * 4),param_1,local_e34);
    if (iVar3 != 0) goto LAB_10024f40;
    bVar1 = false;
  }
  if ((local_e3c != (code *)0x0) || (pcVar2 != (code *)0x0)) {
    if (bVar1) {
      BVar4 = IsDebuggerPresent();
      if (BVar4 != 0) goto LAB_10024f3f;
    }
    _RTC_GetSrcLine((uchar *)((int)param_1 + -5),local_210,0x104,&local_e40,local_418,0x104);
    if (pcVar2 == (code *)0x0) {
      pcVar6 = "Unknown Filename";
      iVar3 = WideCharToMultiByte(0xfde9,0,local_210,-1,local_724,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        pcVar6 = local_724;
      }
      pcVar5 = "Unknown Module Name";
      iVar3 = WideCharToMultiByte(0xfde9,0,local_418,-1,local_a30,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        pcVar5 = local_a30;
      }
      iVar3 = (*local_e3c)(param_2,pcVar6,local_e40,pcVar5,"Run-Time Check Failure #%d - %s",param_3
                           ,local_e38);
    }
    else {
      iVar3 = (*pcVar2)(param_2,local_210,local_e40,local_418,L"Run-Time Check Failure #%d - %s",
                        param_3,local_e34);
    }
    if (iVar3 != 1) {
LAB_10024f40:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_10024f3f:
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



// Function: __RTC_UninitUse at 10024f4f

/* Library Function - Single Match
    __RTC_UninitUse
   
   Library: Visual Studio 2012 Release */

void __cdecl __RTC_UninitUse(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  void *unaff_retaddr;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  if (DAT_1003386c == -1) goto LAB_10025022;
  if (param_1 == (char *)0x0) {
LAB_10025007:
    pcVar2 = "A variable is being used without being initialized.";
  }
  else {
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((char *)0x400 < pcVar2 + (0x3a - (int)(param_1 + 1))) goto LAB_10025007;
    pcVar2 = local_408;
    iVar3 = 0;
    do {
      cVar1 = "The variable \'"[iVar3];
      local_408[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      pcVar5 = param_1;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)param_1;
    pcVar5 = &stack0xfffffbf7;
    do {
      pcVar7 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar7 != '\0');
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = "\' is being used without being initialized.";
    do {
      pcVar7 = pcVar5;
      pcVar5 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    pcVar5 = &stack0xfffffbf7;
    do {
      pcVar8 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = "\' is being used without being initialized.";
    for (uVar6 = (uint)(pcVar7 + -0x1002cf27) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = (uint)(pcVar7 + -0x1002cf27) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  failwithmessage(unaff_retaddr,DAT_1003386c,3,pcVar2);
LAB_10025022:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002502e at 1002502e

undefined4 FUN_1002502e(void)

{
  return DAT_10033ce8;
}



// Function: FUN_10025034 at 10025034

undefined4 FUN_10025034(void)

{
  return DAT_10033cec;
}



// Function: FUN_1002503a at 1002503a

undefined * __cdecl FUN_1002503a(uint param_1)

{
  if (param_1 < 5) {
    return (&PTR_s_Stack_pointer_corruption_1002d4c4)[param_1];
  }
  return (undefined *)0x0;
}



// Function: FUN_10025056 at 10025056

undefined4 __cdecl FUN_10025056(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10033ce8;
  DAT_10033cec = 0;
  DAT_10033ce8 = param_1;
  return uVar1;
}



// Function: FUN_10025070 at 10025070

undefined4 __cdecl FUN_10025070(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10033cec;
  DAT_10033ce8 = 0;
  DAT_10033cec = param_1;
  return uVar1;
}



// Function: __RTC_SetErrorType at 1002508a

/* Library Function - Single Match
    __RTC_SetErrorType
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl __RTC_SetErrorType(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 5) {
    uVar1 = *(undefined4 *)(&DAT_10033860 + param_1 * 4);
    *(undefined4 *)(&DAT_10033860 + param_1 * 4) = param_2;
    return uVar1;
  }
  return 0xffffffff;
}



// Function: __EH_epilog3 at 100250cc

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __EH_epilog3
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_epilog3(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-3];
  *unaff_EBP = unaff_retaddr;
  return;
}



// Function: __EH_prolog3_catch at 10025167

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3_catch
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3_catch(int param_1)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  iVar1 = -param_1;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10033838 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __FindPESection at 10025200

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2012 Release */

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



// Function: __IsNonwritableInCurrentImage at 10025250

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2012 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_1002418c;
  local_14 = ExceptionList;
  local_c = DAT_10033838 ^ 0x10031680;
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



// Function: __ValidateImageBase at 10025310

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  uint uVar1;
  
  if (*(short *)pImageBase != 0x5a4d) {
    return 0;
  }
  uVar1 = 0;
  if (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550) {
    uVar1 = (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b)
    ;
  }
  return uVar1;
}



// Function: ___security_init_cookie at 10025341

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2012 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;
  
  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  if ((DAT_10033838 == 0xbb40e64e) || ((DAT_10033838 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_10033838 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_10033838 == 0xbb40e64e) {
      DAT_10033838 = 0xbb40e64f;
    }
    else if ((DAT_10033838 & 0xffff0000) == 0) {
      DAT_10033838 = DAT_10033838 | (DAT_10033838 | 0x4711) << 0x10;
    }
    DAT_1003383c = ~DAT_10033838;
  }
  else {
    DAT_1003383c = ~DAT_10033838;
  }
  return;
}



// Function: GetPdbDllFromInstallPath at 10025452

/* Library Function - Single Match
    struct HINSTANCE__ * __cdecl GetPdbDllFromInstallPath(void)
   
   Library: Visual Studio 2012 Release */

HINSTANCE__ * __cdecl GetPdbDllFromInstallPath(void)

{
  HMODULE pHVar1;
  DWORD DVar2;
  FARPROC pFVar3;
  FARPROC pFVar4;
  int iVar5;
  HINSTANCE__ *pHVar6;
  uint uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  WCHAR *pWVar10;
  int local_220;
  FARPROC local_21c;
  undefined4 local_218;
  uint local_214;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_10033838 ^ (uint)&stack0xfffffffc;
  pHVar1 = LoadLibraryExW(L"ADVAPI32.DLL",(HANDLE)0x0,0x800);
  if ((((pHVar1 != (HMODULE)0x0) ||
       ((DVar2 = GetLastError(), DVar2 == 0x57 &&
        (pHVar1 = LoadLibraryW(L"ADVAPI32.DLL"), pHVar1 != (HMODULE)0x0)))) &&
      (pFVar3 = GetProcAddress(pHVar1,"RegOpenKeyExW"), pFVar3 != (FARPROC)0x0)) &&
     ((local_21c = GetProcAddress(pHVar1,"RegQueryValueExW"), local_21c != (FARPROC)0x0 &&
      (pFVar4 = GetProcAddress(pHVar1,"RegCloseKey"), pFVar4 != (FARPROC)0x0)))) {
    iVar5 = (*pFVar3)(0x80000002,L"SOFTWARE\\Microsoft\\VisualStudio\\11.0\\Setup\\VS",0,1,
                      &local_218);
    if (iVar5 == 0) {
      local_214 = 0x208;
      iVar5 = (*local_21c)(local_218,L"EnvironmentDirectory",0,&local_220,local_210,&local_214);
      (*pFVar4)(local_218);
      FreeLibrary(pHVar1);
      if ((((iVar5 == 0) && (local_220 == 1)) && ((local_214 & 1) == 0)) &&
         ((uVar7 = local_214 >> 1, 1 < uVar7 && (uVar8 = uVar7 - 1, local_210[uVar8] == L'\0')))) {
        if (local_210[uVar7 - 2] != L'\\') {
          local_210[uVar8] = L'\\';
          uVar8 = uVar7;
        }
        if ((0xd < -uVar8 - 1) && (uVar8 + 0xd < 0x105)) {
          pwVar9 = L"MSPDB110.DLL";
          pWVar10 = local_210 + uVar8;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pWVar10 = *(undefined4 *)pwVar9;
            pwVar9 = pwVar9 + 2;
            pWVar10 = pWVar10 + 2;
          }
          *pWVar10 = *pwVar9;
          pHVar1 = LoadLibraryExW(local_210,(HANDLE)0x0,0x900);
          if ((pHVar1 == (HMODULE)0x0) && (DVar2 = GetLastError(), DVar2 == 0x57)) {
            LoadLibraryExW(local_210,(HANDLE)0x0,8);
          }
        }
      }
    }
    else {
      FreeLibrary(pHVar1);
    }
  }
  pHVar6 = (HINSTANCE__ *)__security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return pHVar6;
}



// Function: _RTC_GetSrcLine at 10025605

/* Library Function - Single Match
    int __cdecl _RTC_GetSrcLine(unsigned char *,wchar_t *,unsigned long,int *,wchar_t *,unsigned
   long)
   
   Library: Visual Studio 2012 Release */

int __cdecl
_RTC_GetSrcLine(uchar *param_1,wchar_t *param_2,ulong param_3,int *param_4,wchar_t *param_5,
               ulong param_6)

{
  char cVar1;
  SIZE_T SVar2;
  DWORD DVar3;
  uint *puVar4;
  FARPROC pFVar5;
  int iVar6;
  HANDLE pvVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uchar *lpAddress;
  uint uVar11;
  int iVar12;
  uint uVar13;
  _MEMORY_BASIC_INFORMATION local_48;
  undefined1 local_2c [4];
  undefined4 local_28;
  int local_24;
  int *local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  *param_4 = 0;
  *param_2 = L'\0';
  lpAddress = param_1 + -1;
  SVar2 = VirtualQuery(lpAddress,&local_48,0x1c);
  if ((((SVar2 == 0) ||
       (DVar3 = GetModuleFileNameW((HMODULE)local_48.AllocationBase,param_5,param_6), DVar3 == 0))
      || ((short)*(int *)local_48.AllocationBase != 0x5a4d)) ||
     ((((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused < 1 ||
      (piVar8 = (int *)((int)(int *)local_48.AllocationBase +
                       ((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused), *piVar8 != 0x4550)
      ))) {
    return 0;
  }
  uVar9 = (uint)*(ushort *)((int)piVar8 + 6);
  uVar11 = (int)lpAddress - (int)local_48.AllocationBase;
  uVar10 = 0;
  uVar13 = 0;
  if (uVar9 != 0) {
    puVar4 = (uint *)(*(ushort *)(piVar8 + 5) + 0x24 + (int)piVar8);
    do {
      if ((*puVar4 <= uVar11) && (uVar10 = uVar11 - *puVar4, uVar11 < puVar4[-1])) break;
      uVar13 = uVar13 + 1;
      puVar4 = puVar4 + 10;
    } while (uVar13 < uVar9);
  }
  if (uVar13 == uVar9) {
    return 0;
  }
  if (DAT_10033cfd == '\0') {
    if (DAT_10033cf8 != (HMODULE)0x0) {
      return 0;
    }
    if (DAT_10033cfc == '\0') {
      DAT_10033cfc = '\x01';
      DAT_10033cf8 = GetPdbDllFromInstallPath();
    }
    else {
      DAT_10033cf8 = (HMODULE)0x0;
    }
    if (DAT_10033cf8 == (HMODULE)0x0) {
      return 0;
    }
    DAT_10033cfd = '\x01';
  }
  pFVar5 = GetProcAddress(DAT_10033cf8,"PDBOpenValidate5");
  if (pFVar5 != (FARPROC)0x0) {
    iVar12 = 0;
    iVar6 = (*pFVar5)(param_5,0,0,0,local_2c,0,0,&local_14);
    if (iVar6 != 0) {
      local_1c = 0;
      iVar6 = (**(code **)*local_14)();
      if ((iVar6 == 0x1329141) &&
         (iVar6 = (**(code **)(*local_14 + 0x1c))(0,&DAT_1002d6bc,&local_20), iVar6 != 0)) {
        iVar6 = (**(code **)(*local_20 + 0x20))(uVar13 + 1,uVar10,&local_10,0,0,0);
        if (iVar6 != 0) {
          local_8 = (int *)0x0;
          cVar1 = (**(code **)(*local_10 + 0x68))(&local_8);
          if ((cVar1 != '\0') && (local_8 != (int *)0x0)) {
            puVar4 = (uint *)0x0;
            do {
              iVar12 = (**(code **)(*local_8 + 8))();
              if (iVar12 == 0) goto LAB_100257bd;
              cVar1 = (**(code **)(*local_8 + 0xc))(0,&local_18,&param_1,&local_24,&local_c,0);
              if (cVar1 == '\0') goto LAB_100257cc;
            } while (((((uint)param_1 & 0xffff) != uVar13 + 1) || (uVar10 < local_18)) ||
                    (local_24 + local_18 <= uVar10));
            if ((local_c != 0) && (local_c < 0x1fffffff)) {
              SVar2 = local_c << 3;
              DVar3 = 0;
              pvVar7 = GetProcessHeap();
              puVar4 = (uint *)HeapAlloc(pvVar7,DVar3,SVar2);
              if (puVar4 != (uint *)0x0) {
                cVar1 = (**(code **)(*local_8 + 0xc))(&local_28,0,0,0,&local_c,puVar4);
                if ((cVar1 != '\0') && (*puVar4 <= uVar10 - local_18)) {
                  uVar9 = 1;
                  if (1 < local_c) {
                    do {
                      if (uVar10 - local_18 < puVar4[uVar9 * 2]) break;
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < local_c);
                  }
                  *param_4 = puVar4[uVar9 * 2 + -1] & 0xffffff;
                  cVar1 = (**(code **)(*local_10 + 0x70))(local_28,param_2,&param_3,0,0,0);
                  if (cVar1 != '\0') {
                    local_1c = 1;
                  }
                }
LAB_100257bd:
                DVar3 = 0;
                pvVar7 = GetProcessHeap();
                HeapFree(pvVar7,DVar3,puVar4);
              }
            }
LAB_100257cc:
            (**(code **)*local_8)();
            iVar12 = local_1c;
          }
          (**(code **)(*local_10 + 0x40))();
        }
        (**(code **)(*local_20 + 0x38))();
      }
      (**(code **)(*local_14 + 0x2c))();
      return iVar12;
    }
  }
  return 0;
}



// Function: Unwind@10025940 at 10025940

void Unwind_10025940(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025970 at 10025970

void Unwind_10025970(void)

{
  FUN_100054a0();
  return;
}



// Function: Unwind@100259b0 at 100259b0

void Unwind_100259b0(void)

{
  FUN_100054a0();
  return;
}



// Function: Unwind@100259f0 at 100259f0

void Unwind_100259f0(void)

{
  FUN_100054a0();
  return;
}



// Function: Unwind@10025a30 at 10025a30

void Unwind_10025a30(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025a60 at 10025a60

void Unwind_10025a60(void)

{
  int unaff_EBP;
  
  FUN_100048e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025a90 at 10025a90

void Unwind_10025a90(void)

{
  int unaff_EBP;
  
  FUN_10004940(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025ac0 at 10025ac0

void Unwind_10025ac0(void)

{
  int unaff_EBP;
  
  FUN_100049a0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025af0 at 10025af0

void Unwind_10025af0(void)

{
  int unaff_EBP;
  
  FUN_100049a0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025b20 at 10025b20

void Unwind_10025b20(void)

{
  int unaff_EBP;
  
  FUN_10004a00(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025b50 at 10025b50

void Unwind_10025b50(void)

{
  int unaff_EBP;
  
  FUN_10004a00(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025b80 at 10025b80

void Unwind_10025b80(void)

{
  int unaff_EBP;
  
  FUN_10004a60(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025bb0 at 10025bb0

void Unwind_10025bb0(void)

{
  int unaff_EBP;
  
  FUN_10004ac0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025be0 at 10025be0

void Unwind_10025be0(void)

{
  int unaff_EBP;
  
  FUN_10004ac0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025c10 at 10025c10

void Unwind_10025c10(void)

{
  int unaff_EBP;
  
  FUN_10004b20(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025c40 at 10025c40

void Unwind_10025c40(void)

{
  int unaff_EBP;
  
  FUN_10004560(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025c70 at 10025c70

void Unwind_10025c70(void)

{
  int unaff_EBP;
  
  FUN_100045e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025ca0 at 10025ca0

void Unwind_10025ca0(void)

{
  int unaff_EBP;
  
  FUN_10004660(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025cd0 at 10025cd0

void Unwind_10025cd0(void)

{
  int unaff_EBP;
  
  FUN_10004660(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025d00 at 10025d00

void Unwind_10025d00(void)

{
  int unaff_EBP;
  
  FUN_10004660(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025d30 at 10025d30

void Unwind_10025d30(void)

{
  int unaff_EBP;
  
  FUN_100046e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025d60 at 10025d60

void Unwind_10025d60(void)

{
  int unaff_EBP;
  
  FUN_100046e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025d90 at 10025d90

void Unwind_10025d90(void)

{
  int unaff_EBP;
  
  FUN_10004f00(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025dc0 at 10025dc0

void Unwind_10025dc0(void)

{
  FUN_10005270();
  return;
}



// Function: Unwind@10025df0 at 10025df0

void Unwind_10025df0(void)

{
  FUN_10004e00();
  return;
}



// Function: Unwind@10025e20 at 10025e20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10025e20(void)

{
  int unaff_EBP;
  
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025e50 at 10025e50

void Unwind_10025e50(void)

{
  FUN_10004d80();
  return;
}



// Function: Unwind@10025e80 at 10025e80

void Unwind_10025e80(void)

{
  FUN_10005030();
  return;
}



// Function: Unwind@10025eb0 at 10025eb0

void Unwind_10025eb0(void)

{
  int unaff_EBP;
  
  FUN_100053f0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025ee0 at 10025ee0

void Unwind_10025ee0(void)

{
  int unaff_EBP;
  
  FUN_10005170(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025f10 at 10025f10

void Unwind_10025f10(void)

{
  int unaff_EBP;
  
  FUN_10005170(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025f40 at 10025f40

void Unwind_10025f40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10025f70 at 10025f70

void Unwind_10025f70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10025fa0 at 10025fa0

void Unwind_10025fa0(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025fd0 at 10025fd0

void Unwind_10025fd0(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026000 at 10026000

void Unwind_10026000(void)

{
  int unaff_EBP;
  
  FUN_100048e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026030 at 10026030

void Unwind_10026030(void)

{
  int unaff_EBP;
  
  FUN_10004940(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026060 at 10026060

void Unwind_10026060(void)

{
  int unaff_EBP;
  
  FUN_100049a0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026090 at 10026090

void Unwind_10026090(void)

{
  int unaff_EBP;
  
  FUN_10004a00(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100260c0 at 100260c0

void Unwind_100260c0(void)

{
  int unaff_EBP;
  
  FUN_10004a60(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100260f0 at 100260f0

void Unwind_100260f0(void)

{
  int unaff_EBP;
  
  FUN_10004ac0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026120 at 10026120

void Unwind_10026120(void)

{
  int unaff_EBP;
  
  FUN_10004b20(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026150 at 10026150

void Unwind_10026150(void)

{
  int unaff_EBP;
  
  FUN_10004560(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026180 at 10026180

void Unwind_10026180(void)

{
  int unaff_EBP;
  
  FUN_100045e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100261b0 at 100261b0

void Unwind_100261b0(void)

{
  int unaff_EBP;
  
  FUN_10004660(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100261e0 at 100261e0

void Unwind_100261e0(void)

{
  int unaff_EBP;
  
  FUN_100046e0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026210 at 10026210

void Unwind_10026210(void)

{
  int unaff_EBP;
  
  FUN_10004f00(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026240 at 10026240

void Unwind_10026240(void)

{
  FUN_10005270();
  return;
}



// Function: Unwind@10026270 at 10026270

void Unwind_10026270(void)

{
  FUN_10004e00();
  return;
}



// Function: Unwind@100262a0 at 100262a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_100262a0(void)

{
  int unaff_EBP;
  
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100262d0 at 100262d0

void Unwind_100262d0(void)

{
  FUN_10004d80();
  return;
}



// Function: Unwind@10026300 at 10026300

void Unwind_10026300(void)

{
  FUN_10005030();
  return;
}



// Function: Unwind@10026330 at 10026330

void Unwind_10026330(void)

{
  int unaff_EBP;
  
  FUN_100053f0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026360 at 10026360

void Unwind_10026360(void)

{
  int unaff_EBP;
  
  FUN_10005170(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026390 at 10026390

void Unwind_10026390(void)

{
  int unaff_EBP;
  
  FUN_10005170(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100263c0 at 100263c0

void Unwind_100263c0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@100263f0 at 100263f0

void Unwind_100263f0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10026420 at 10026420

void Unwind_10026420(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10026450 at 10026450

void Unwind_10026450(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10026480 at 10026480

void Unwind_10026480(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@100264c0 at 100264c0

void Unwind_100264c0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100264c8 at 100264c8

void Unwind_100264c8(void)

{
  int unaff_EBP;
  
  FUN_10004d00((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100264d0 at 100264d0

void Unwind_100264d0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10026500 at 10026500

void Unwind_10026500(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10026550 at 10026550

void Unwind_10026550(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1002655b at 1002655b

void Unwind_1002655b(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10026590 at 10026590

void Unwind_10026590(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100265c0 at 100265c0

void Unwind_100265c0(void)

{
  int unaff_EBP;
  
  FUN_10004c00((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100265c8 at 100265c8

void Unwind_100265c8(void)

{
  int unaff_EBP;
  
  FUN_10004fe0((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100265d0 at 100265d0

void Unwind_100265d0(void)

{
  int unaff_EBP;
  
  FUN_10004fe0((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100265d8 at 100265d8

void Unwind_100265d8(void)

{
  int unaff_EBP;
  
  FUN_10004fe0((void *)(unaff_EBP + -0x288));
  return;
}



// Function: Unwind@100265e3 at 100265e3

void Unwind_100265e3(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100265eb at 100265eb

void Unwind_100265eb(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100265f6 at 100265f6

void Unwind_100265f6(void)

{
  int unaff_EBP;
  
  FUN_10004d00((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10026601 at 10026601

void Unwind_10026601(void)

{
  int unaff_EBP;
  
  FUN_10004b80((int *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1002660c at 1002660c

void Unwind_1002660c(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10026617 at 10026617

void Unwind_10026617(void)

{
  int unaff_EBP;
  
  FUN_10004fe0((void *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@10026622 at 10026622

void Unwind_10026622(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@1002662d at 1002662d

void Unwind_1002662d(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@10026638 at 10026638

void Unwind_10026638(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x184));
  return;
}



// Function: Unwind@10026670 at 10026670

void Unwind_10026670(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10026678 at 10026678

void Unwind_10026678(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x194));
  return;
}



// Function: Unwind@10026683 at 10026683

void Unwind_10026683(void)

{
  int unaff_EBP;
  
  FUN_100047e0((int *)(unaff_EBP + -0x1ac));
  return;
}



// Function: Unwind@1002668e at 1002668e

void Unwind_1002668e(void)

{
  int unaff_EBP;
  
  FUN_100047e0((int *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10026699 at 10026699

void Unwind_10026699(void)

{
  int unaff_EBP;
  
  FUN_10004760((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@100266d0 at 100266d0

void Unwind_100266d0(void)

{
  int unaff_EBP;
  
  FUN_10004860((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100266d8 at 100266d8

void Unwind_100266d8(void)

{
  int unaff_EBP;
  
  FUN_10004860((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10026700 at 10026700

void Unwind_10026700(void)

{
  int unaff_EBP;
  
  FUN_100240db(*(void **)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@10026715 at 10026715

void Unwind_10026715(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10026740 at 10026740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_10026740(void)

{
  int unaff_EBP;
  
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100267b0 at 100267b0

void Unwind_100267b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xe0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xe0) = *(uint *)(unaff_EBP + -0xe0) & 0xfffffffe;
    FUN_10004e80();
    return;
  }
  return;
}



// Function: Unwind@100267f0 at 100267f0

void Unwind_100267f0(void)

{
  FUN_10004e80();
  return;
}



// Function: Unwind@10026820 at 10026820

void Unwind_10026820(void)

{
  FUN_100050b0();
  return;
}



// Function: Unwind@10026828 at 10026828

void Unwind_10026828(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026830 at 10026830

void Unwind_10026830(void)

{
  int unaff_EBP;
  
  FUN_10004d00((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10026838 at 10026838

void Unwind_10026838(void)

{
  int unaff_EBP;
  
  FUN_10004b80((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10026840 at 10026840

void Unwind_10026840(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10026848 at 10026848

void Unwind_10026848(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10026853 at 10026853

void Unwind_10026853(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10026880 at 10026880

void Unwind_10026880(void)

{
  FUN_100050b0();
  return;
}



// Function: Unwind@10026888 at 10026888

void Unwind_10026888(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026890 at 10026890

void Unwind_10026890(void)

{
  int unaff_EBP;
  
  FUN_10004d00((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10026898 at 10026898

void Unwind_10026898(void)

{
  int unaff_EBP;
  
  FUN_10004b80((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100268a0 at 100268a0

void Unwind_100268a0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100268ab at 100268ab

void Unwind_100268ab(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100268e0 at 100268e0

void Unwind_100268e0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100268e8 at 100268e8

void Unwind_100268e8(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x1dc));
  return;
}



// Function: Unwind@100268f3 at 100268f3

void Unwind_100268f3(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x1d0));
  return;
}



// Function: Unwind@100268fe at 100268fe

void Unwind_100268fe(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10026906 at 10026906

void Unwind_10026906(void)

{
  int unaff_EBP;
  
  FUN_10004d00((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10026911 at 10026911

void Unwind_10026911(void)

{
  int unaff_EBP;
  
  FUN_10004b80((int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1002691c at 1002691c

void Unwind_1002691c(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@10026927 at 10026927

void Unwind_10026927(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10026950 at 10026950

void Unwind_10026950(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xec) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xec) = *(uint *)(unaff_EBP + -0xec) & 0xfffffffe;
    FUN_10004f90(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10026990 at 10026990

void Unwind_10026990(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xe0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xe0) = *(uint *)(unaff_EBP + -0xe0) & 0xfffffffe;
    FUN_10004f90(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100269d0 at 100269d0

void Unwind_100269d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xec) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xec) = *(uint *)(unaff_EBP + -0xec) & 0xfffffffe;
    FUN_10004f90(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10026a10 at 10026a10

void Unwind_10026a10(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10026a18 at 10026a18

void Unwind_10026a18(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10026a40 at 10026a40

void Unwind_10026a40(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xe0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xe0) = *(uint *)(unaff_EBP + -0xe0) & 0xfffffffe;
    FUN_10004fe0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10026a80 at 10026a80

void Unwind_10026a80(void)

{
  FUN_1000ffc0();
  return;
}



// Function: Unwind@10026a88 at 10026a88

void Unwind_10026a88(void)

{
  int unaff_EBP;
  
  FUN_1000ff10((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10026ac0 at 10026ac0

void Unwind_10026ac0(void)

{
  int unaff_EBP;
  
  FUN_1000fff0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026af0 at 10026af0

void Unwind_10026af0(void)

{
  FUN_1000ff90();
  return;
}



// Function: Unwind@10026b20 at 10026b20

void Unwind_10026b20(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@10026b2b at 10026b2b

void Unwind_10026b2b(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x28));
  return;
}



// Function: Unwind@10026b36 at 10026b36

void Unwind_10026b36(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x2c));
  return;
}



// Function: Unwind@10026b41 at 10026b41

void Unwind_10026b41(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x30));
  return;
}



// Function: Unwind@10026b4c at 10026b4c

void Unwind_10026b4c(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x34));
  return;
}



// Function: Unwind@10026b57 at 10026b57

void Unwind_10026b57(void)

{
  int unaff_EBP;
  
  FUN_100046e0((int *)(*(int *)(unaff_EBP + -0x14) + 0x38));
  return;
}



// Function: Unwind@10026b80 at 10026b80

void Unwind_10026b80(void)

{
  FUN_1000ffc0();
  return;
}



// Function: Unwind@10026b88 at 10026b88

void Unwind_10026b88(void)

{
  int unaff_EBP;
  
  FUN_1000ff10((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10026bc0 at 10026bc0

void Unwind_10026bc0(void)

{
  int unaff_EBP;
  
  FUN_1000fff0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026bf0 at 10026bf0

void Unwind_10026bf0(void)

{
  FUN_1000ff90();
  return;
}



// Function: Unwind@10026c20 at 10026c20

void Unwind_10026c20(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@10026c2b at 10026c2b

void Unwind_10026c2b(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x28));
  return;
}



// Function: Unwind@10026c36 at 10026c36

void Unwind_10026c36(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x2c));
  return;
}



// Function: Unwind@10026c41 at 10026c41

void Unwind_10026c41(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x30));
  return;
}



// Function: Unwind@10026c4c at 10026c4c

void Unwind_10026c4c(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(*(int *)(unaff_EBP + -0x14) + 0x34));
  return;
}



// Function: Unwind@10026c57 at 10026c57

void Unwind_10026c57(void)

{
  int unaff_EBP;
  
  FUN_100046e0((int *)(*(int *)(unaff_EBP + -0x14) + 0x38));
  return;
}



// Function: Unwind@10026c80 at 10026c80

void Unwind_10026c80(void)

{
  int unaff_EBP;
  
  FUN_10004660((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10026cb0 at 10026cb0

void Unwind_10026cb0(void)

{
  int unaff_EBP;
  
  FUN_100046e0((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10026ce0 at 10026ce0

void Unwind_10026ce0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10026d10 at 10026d10

void Unwind_10026d10(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10026d40 at 10026d40

void Unwind_10026d40(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10026d70 at 10026d70

void Unwind_10026d70(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10026da0 at 10026da0

void Unwind_10026da0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026dd0 at 10026dd0

void Unwind_10026dd0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026e00 at 10026e00

void Unwind_10026e00(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10026e08 at 10026e08

void Unwind_10026e08(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10026e10 at 10026e10

void Unwind_10026e10(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10026e40 at 10026e40

void Unwind_10026e40(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026e70 at 10026e70

void Unwind_10026e70(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026ea0 at 10026ea0

void Unwind_10026ea0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026ed0 at 10026ed0

void Unwind_10026ed0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10026ed8 at 10026ed8

void Unwind_10026ed8(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10026ee0 at 10026ee0

void Unwind_10026ee0(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026ee8 at 10026ee8

void Unwind_10026ee8(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10026f10 at 10026f10

void Unwind_10026f10(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10026f18 at 10026f18

void Unwind_10026f18(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10026f20 at 10026f20

void Unwind_10026f20(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10026f50 at 10026f50

void Unwind_10026f50(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026f80 at 10026f80

void Unwind_10026f80(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026fb0 at 10026fb0

void Unwind_10026fb0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10026ff0 at 10026ff0

void Unwind_10026ff0(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10027020 at 10027020

void Unwind_10027020(void)

{
  int unaff_EBP;
  
  FUN_10005360((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10027050 at 10027050

void Unwind_10027050(void)

{
  int unaff_EBP;
  
  FUN_10014e00(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027080 at 10027080

void Unwind_10027080(void)

{
  FUN_10014a90();
  return;
}



// Function: Unwind@1002708b at 1002708b

void Unwind_1002708b(void)

{
  int unaff_EBP;
  
  FUN_10014830(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}



// Function: Unwind@100270c0 at 100270c0

void Unwind_100270c0(void)

{
  FUN_10014a90();
  return;
}



// Function: Unwind@100270cb at 100270cb

void Unwind_100270cb(void)

{
  int unaff_EBP;
  
  FUN_100148b0(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}



// Function: Unwind@10027100 at 10027100

void Unwind_10027100(void)

{
  int unaff_EBP;
  
  FUN_10015140(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027130 at 10027130

void Unwind_10027130(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027160 at 10027160

void Unwind_10027160(void)

{
  int unaff_EBP;
  
  FUN_10015140(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027190 at 10027190

void Unwind_10027190(void)

{
  int unaff_EBP;
  
  FUN_10014e90(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100271c0 at 100271c0

void Unwind_100271c0(void)

{
  FUN_1000ffc0();
  return;
}



// Function: Unwind@100271f0 at 100271f0

void Unwind_100271f0(void)

{
  int unaff_EBP;
  
  FUN_10014c10(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027220 at 10027220

void Unwind_10027220(void)

{
  int unaff_EBP;
  
  FUN_10014c70(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027250 at 10027250

void Unwind_10027250(void)

{
  FUN_100151e0();
  return;
}



// Function: Unwind@10027280 at 10027280

void Unwind_10027280(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 4);
  return;
}



// Function: Unwind@100272b0 at 100272b0

void Unwind_100272b0(void)

{
  int unaff_EBP;
  
  FUN_100145b0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100272e0 at 100272e0

void Unwind_100272e0(void)

{
  int unaff_EBP;
  
  FUN_10014cd0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027310 at 10027310

void Unwind_10027310(void)

{
  int unaff_EBP;
  
  FUN_10014fa0((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10027340 at 10027340

void Unwind_10027340(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@1002734b at 1002734b

void Unwind_1002734b(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(*(int *)(unaff_EBP + -0x14) + 0x28));
  return;
}



// Function: Unwind@10027356 at 10027356

void Unwind_10027356(void)

{
  int unaff_EBP;
  
  FUN_1000fed0((int *)(*(int *)(unaff_EBP + -0x14) + 0x2c));
  return;
}



// Function: Unwind@10027380 at 10027380

void Unwind_10027380(void)

{
  FUN_1000ff90();
  return;
}



// Function: Unwind@100273b0 at 100273b0

void Unwind_100273b0(void)

{
  int unaff_EBP;
  
  FUN_10014e00(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100273e0 at 100273e0

void Unwind_100273e0(void)

{
  FUN_10014a90();
  return;
}



// Function: Unwind@100273eb at 100273eb

void Unwind_100273eb(void)

{
  int unaff_EBP;
  
  FUN_10014830(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}



// Function: Unwind@10027420 at 10027420

void Unwind_10027420(void)

{
  FUN_10014a90();
  return;
}



// Function: Unwind@1002742b at 1002742b

void Unwind_1002742b(void)

{
  int unaff_EBP;
  
  FUN_100148b0(*(int *)(unaff_EBP + -0x14) + 0xc);
  return;
}



// Function: Unwind@10027460 at 10027460

void Unwind_10027460(void)

{
  int unaff_EBP;
  
  FUN_10015140(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027490 at 10027490

void Unwind_10027490(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100274c0 at 100274c0

void Unwind_100274c0(void)

{
  int unaff_EBP;
  
  FUN_10015140(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100274f0 at 100274f0

void Unwind_100274f0(void)

{
  int unaff_EBP;
  
  FUN_10014e90(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027520 at 10027520

void Unwind_10027520(void)

{
  FUN_1000ffc0();
  return;
}



// Function: Unwind@10027550 at 10027550

void Unwind_10027550(void)

{
  int unaff_EBP;
  
  FUN_10014c10(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027580 at 10027580

void Unwind_10027580(void)

{
  int unaff_EBP;
  
  FUN_10014c70(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100275b0 at 100275b0

void Unwind_100275b0(void)

{
  FUN_100151e0();
  return;
}



// Function: Unwind@100275e0 at 100275e0

void Unwind_100275e0(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 4);
  return;
}



// Function: Unwind@10027610 at 10027610

void Unwind_10027610(void)

{
  int unaff_EBP;
  
  FUN_100145b0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027640 at 10027640

void Unwind_10027640(void)

{
  int unaff_EBP;
  
  FUN_10014cd0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027670 at 10027670

void Unwind_10027670(void)

{
  int unaff_EBP;
  
  FUN_10014fa0((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100276a0 at 100276a0

void Unwind_100276a0(void)

{
  int unaff_EBP;
  
  FUN_1000fe40(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@100276ab at 100276ab

void Unwind_100276ab(void)

{
  int unaff_EBP;
  
  FUN_10004c80((int *)(*(int *)(unaff_EBP + -0x14) + 0x28));
  return;
}



// Function: Unwind@100276b6 at 100276b6

void Unwind_100276b6(void)

{
  int unaff_EBP;
  
  FUN_1000fed0((int *)(*(int *)(unaff_EBP + -0x14) + 0x2c));
  return;
}



// Function: Unwind@100276e0 at 100276e0

void Unwind_100276e0(void)

{
  FUN_1000ff90();
  return;
}



// Function: Unwind@10027710 at 10027710

void Unwind_10027710(void)

{
  int unaff_EBP;
  
  FUN_10014630((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10027718 at 10027718

void Unwind_10027718(void)

{
  int unaff_EBP;
  
  FUN_10014670((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10027740 at 10027740

void Unwind_10027740(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027770 at 10027770

void Unwind_10027770(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100277a0 at 100277a0

void Unwind_100277a0(void)

{
  int unaff_EBP;
  
  FUN_10014d10((int *)(unaff_EBP + -0x116c));
  return;
}



// Function: Unwind@100277ab at 100277ab

void Unwind_100277ab(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x11d8));
  return;
}



// Function: Unwind@100277b6 at 100277b6

void Unwind_100277b6(void)

{
  int unaff_EBP;
  
  FUN_10014db0((int *)(unaff_EBP + -0x1308));
  return;
}



// Function: Unwind@100277f0 at 100277f0

void Unwind_100277f0(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027820 at 10027820

void Unwind_10027820(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027850 at 10027850

void Unwind_10027850(void)

{
  int unaff_EBP;
  
  FUN_10014b10((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10027858 at 10027858

void Unwind_10027858(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@10027863 at 10027863

void Unwind_10027863(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@1002786e at 1002786e

void Unwind_1002786e(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@100278b0 at 100278b0

void Unwind_100278b0(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100278b8 at 100278b8

void Unwind_100278b8(void)

{
  int unaff_EBP;
  
  FUN_10014b90((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100278c0 at 100278c0

void Unwind_100278c0(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10027900 at 10027900

void Unwind_10027900(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027908 at 10027908

void Unwind_10027908(void)

{
  int unaff_EBP;
  
  FUN_10014b90((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10027930 at 10027930

void Unwind_10027930(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@10027970 at 10027970

void Unwind_10027970(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@100279b0 at 100279b0

void Unwind_100279b0(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@100279f0 at 100279f0

void Unwind_100279f0(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@10027a30 at 10027a30

void Unwind_10027a30(void)

{
  int unaff_EBP;
  
  FUN_100240cd(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@10027a70 at 10027a70

void Unwind_10027a70(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10027aa0 at 10027aa0

void Unwind_10027aa0(void)

{
  FUN_10013410();
  return;
}



// Function: Unwind@10027abc at 10027abc

void Unwind_10027abc(void)

{
  FUN_10013440();
  return;
}



// Function: Unwind@10027b00 at 10027b00

void Unwind_10027b00(void)

{
  int unaff_EBP;
  
  FUN_10015020(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10027b30 at 10027b30

void Unwind_10027b30(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10027b60 at 10027b60

void Unwind_10027b60(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10027b68 at 10027b68

void Unwind_10027b68(void)

{
  int unaff_EBP;
  
  FUN_10014d60((int *)(unaff_EBP + -0x4bc));
  return;
}



// Function: Unwind@10027ba0 at 10027ba0

void Unwind_10027ba0(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10027ba8 at 10027ba8

void Unwind_10027ba8(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10027bb3 at 10027bb3

void Unwind_10027bb3(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x11a4));
  return;
}



// Function: Unwind@10027bbe at 10027bbe

void Unwind_10027bbe(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x11b8));
  return;
}



// Function: Unwind@10027bc9 at 10027bc9

void Unwind_10027bc9(void)

{
  int unaff_EBP;
  
  FUN_10015070((int *)(unaff_EBP + -0x11d8));
  return;
}



// Function: Unwind@10027c00 at 10027c00

void Unwind_10027c00(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027c30 at 10027c30

void Unwind_10027c30(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027c60 at 10027c60

void Unwind_10027c60(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027c90 at 10027c90

void Unwind_10027c90(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10027cc0 at 10027cc0

void Unwind_10027cc0(void)

{
  int unaff_EBP;
  
  FUN_100150b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10027cc8 at 10027cc8

void Unwind_10027cc8(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10027d00 at 10027d00

void Unwind_10027d00(void)

{
  int unaff_EBP;
  
  FUN_100150b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10027d08 at 10027d08

void Unwind_10027d08(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10027d40 at 10027d40

void Unwind_10027d40(void)

{
  DAT_100338e8 = DAT_100338e8 & 0xfffffffe;
  return;
}



// Function: Unwind@10027d70 at 10027d70

void Unwind_10027d70(void)

{
  int unaff_EBP;
  
  FUN_10020dd0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027da0 at 10027da0

void Unwind_10027da0(void)

{
  int unaff_EBP;
  
  FUN_10020dd0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027dd0 at 10027dd0

void Unwind_10027dd0(void)

{
  int unaff_EBP;
  
  FUN_10020de0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027e00 at 10027e00

void Unwind_10027e00(void)

{
  int unaff_EBP;
  
  FUN_10020dd0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10027e30 at 10027e30

void Unwind_10027e30(void)

{
  int unaff_EBP;
  
  FUN_10020de0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10027e60 at 10027e60

void Unwind_10027e60(void)

{
  int unaff_EBP;
  
  FUN_10020da0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027e90 at 10027e90

void Unwind_10027e90(void)

{
  int unaff_EBP;
  
  FUN_10020db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027ec0 at 10027ec0

void Unwind_10027ec0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027ef0 at 10027ef0

void Unwind_10027ef0(void)

{
  int unaff_EBP;
  
  FUN_10020da0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027f20 at 10027f20

void Unwind_10027f20(void)

{
  int unaff_EBP;
  
  FUN_10020db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10027f50 at 10027f50

void Unwind_10027f50(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10027f80 at 10027f80

void Unwind_10027f80(void)

{
  int unaff_EBP;
  
  FUN_100043e0((int *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@10027f8b at 10027f8b

void Unwind_10027f8b(void)

{
  int unaff_EBP;
  
  FUN_10020da0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10027f96 at 10027f96

void Unwind_10027f96(void)

{
  int unaff_EBP;
  
  FUN_10020d00((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10027fa1 at 10027fa1

void Unwind_10027fa1(void)

{
  int unaff_EBP;
  
  FUN_10020db0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10027fac at 10027fac

void Unwind_10027fac(void)

{
  int unaff_EBP;
  
  FUN_10020d50((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10027fb7 at 10027fb7

void Unwind_10027fb7(void)

{
  int unaff_EBP;
  
  FUN_10020db0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10027fc2 at 10027fc2

void Unwind_10027fc2(void)

{
  int unaff_EBP;
  
  FUN_10020da0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10028000 at 10028000

void Unwind_10028000(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@1002800b at 1002800b

void Unwind_1002800b(void)

{
  int unaff_EBP;
  
  FUN_10020dc0((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@10028016 at 10028016

void Unwind_10028016(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10028021 at 10028021

void Unwind_10028021(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1002802c at 1002802c

void Unwind_1002802c(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10028037 at 10028037

void Unwind_10028037(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10028042 at 10028042

void Unwind_10028042(void)

{
  int unaff_EBP;
  
  FUN_10020de0((int *)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1002804d at 1002804d

void Unwind_1002804d(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10028058 at 10028058

void Unwind_10028058(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10028063 at 10028063

void Unwind_10028063(void)

{
  int unaff_EBP;
  
  FUN_10020dd0((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1002806e at 1002806e

void Unwind_1002806e(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10028079 at 10028079

void Unwind_10028079(void)

{
  int unaff_EBP;
  
  FUN_10020de0((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10028084 at 10028084

void Unwind_10028084(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@100280c0 at 100280c0

void Unwind_100280c0(void)

{
  int unaff_EBP;
  
  FUN_10020dd0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100280c8 at 100280c8

void Unwind_100280c8(void)

{
  int unaff_EBP;
  
  FUN_10020de0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100280d0 at 100280d0

void Unwind_100280d0(void)

{
  int unaff_EBP;
  
  FUN_10020dc0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100280d8 at 100280d8

void Unwind_100280d8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100280e3 at 100280e3

void Unwind_100280e3(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100280eb at 100280eb

void Unwind_100280eb(void)

{
  int unaff_EBP;
  
  FUN_10020dd0(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100280f3 at 100280f3

void Unwind_100280f3(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100280fb at 100280fb

void Unwind_100280fb(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10028103 at 10028103

void Unwind_10028103(void)

{
  int unaff_EBP;
  
  FUN_10005320(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002810b at 1002810b

void Unwind_1002810b(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10028130 at 10028130

void Unwind_10028130(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002813b at 1002813b

void Unwind_1002813b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10005320(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10028170 at 10028170

void Unwind_10028170(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002817b at 1002817b

void Unwind_1002817b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10005320(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100281b0 at 100281b0

void Unwind_100281b0(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100281e0 at 100281e0

void Unwind_100281e0(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10028210 at 10028210

void Unwind_10028210(void)

{
  int unaff_EBP;
  
  FUN_10005320((int *)(unaff_EBP + 8));
  return;
}



// Function: FUN_10028280 at 10028280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028280(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003e90((undefined4 *)&DAT_100338b0);
  _atexit(FUN_10028550);
  return;
}



// Function: FUN_100282d0 at 100282d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100282d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003f20((undefined4 *)&DAT_100338b4);
  _atexit(FUN_10028590);
  return;
}



// Function: FUN_10028320 at 10028320

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028320(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10003ff0((undefined4 *)&DAT_100338b8);
  _atexit(FUN_100285d0);
  return;
}



// Function: FUN_10028370 at 10028370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028370(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::locale::id::id((id *)&DAT_100338bc,0);
  return;
}



// Function: FUN_100283c0 at 100283c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100283c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  std::locale::id::id((id *)&DAT_100338c0,0);
  return;
}



// Function: FUN_10028410 at 10028410

void FUN_10028410(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10028440 at 10028440

void FUN_10028440(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_d0 [51];
  
  puVar2 = local_d0;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return;
}



// Function: FUN_10028470 at 10028470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028470(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000fa40(&DAT_100338c4,0);
  _atexit(FUN_10028610);
  return;
}



// Function: FUN_100284c0 at 100284c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100284c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10014070((undefined4 *)&DAT_100338ec);
  _atexit(FUN_10028650);
  return;
}



// Function: FUN_10028550 at 10028550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028550(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10005170((undefined4 *)&DAT_100338b0);
  return;
}



// Function: FUN_10028590 at 10028590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028590(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100051f0((undefined4 *)&DAT_100338b4);
  return;
}



// Function: FUN_100285d0 at 100285d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100285d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_100052a0((undefined4 *)&DAT_100338b8);
  return;
}



// Function: FUN_10028610 at 10028610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028610(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_1000fed0((int *)&DAT_100338c4);
  return;
}



// Function: FUN_10028650 at 10028650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10028650(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c4 [48];
  
  puVar2 = local_c4;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_10014f20((undefined4 *)&DAT_100338ec);
  return;
}



// Function: FUN_1002868c at 1002868c

void FUN_1002868c(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_1003391c);
  return;
}



// Function: FUN_10028696 at 10028696

void FUN_10028696(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_10033954);
  return;
}



// Function: FUN_100286a0 at 100286a0

void FUN_100286a0(void)

{
  Ordinal_9(&DAT_10033828);
  return;
}



