/*
 * Decompiled from: KernelServiceProvider.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_2c;
  undefined4 local_28 [5];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10017d83;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CKernelInit::vftable;
  FUN_100027e0((int)(param_1 + 1));
  local_8 = 0;
  local_2c = 0;
  while( true ) {
    iVar1 = memcmp((&PTR_DAT_1001c8b0)[local_2c * 2],&DAT_1001d618,0x10);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)(&PTR_DAT_1001c8b0)[local_2c * 2];
    FUN_10016190(local_28,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    local_8._0_1_ = 1;
    puVar2 = (undefined4 *)FUN_10002850(param_1 + 1,local_28);
    *puVar2 = (&PTR_FUN_1001c8b4)[local_2c * 2];
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10016220(local_28);
    local_2c = local_2c + 1;
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001110 at 10001110

undefined4 * __thiscall FUN_10001110(void *this,uint param_1)

{
  FUN_10001190((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001140 at 10001140

void __fastcall FUN_10001140(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017db8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002980(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001190 at 10001190

void __fastcall FUN_10001190(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017df3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CKernelInit::vftable;
  local_8 = 0xffffffff;
  FUN_10002980(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001200 at 10001200

void __cdecl FUN_10001200(undefined4 *param_1)

{
  FUN_10003040(&DAT_1002470c,param_1,0,0xffffffff);
  return;
}



// Function: FUN_10001220 at 10001220

void __thiscall FUN_10001220(void *this,void *param_1,undefined4 param_2)

{
  longlong lVar1;
  size_t sVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  LPCOLESTR *local_374;
  undefined1 local_35d;
  undefined1 *local_35c;
  HKEY local_354;
  LPCWSTR local_348;
  size_t local_344;
  undefined1 local_33d;
  undefined1 *local_33c;
  undefined4 local_334;
  wchar_t *local_330;
  LPWSTR local_32c;
  int local_328;
  int local_324;
  int local_320;
  char local_319;
  wchar_t *local_318;
  LPWSTR local_314;
  uint local_30c;
  undefined4 local_308;
  int local_304;
  DWORD local_300 [2];
  DWORD local_2f8 [2];
  uint local_2f0;
  wchar_t *local_2ec;
  DWORD local_2e8;
  CLSID local_2e4;
  _FILETIME local_2d4;
  DWORD local_2cc;
  DWORD local_2c8;
  DWORD local_2c4;
  LPWSTR local_2c0;
  LPCOLESTR *local_2bc [5];
  uint local_2a8;
  WCHAR local_2a0;
  undefined1 local_29e [514];
  undefined4 local_9c;
  undefined4 local_98 [7];
  LSTATUS local_7c;
  HKEY local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c [5];
  undefined4 local_58 [5];
  undefined4 local_44 [5];
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017e82;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_9c = 0x80004005;
  DAT_10024698 = param_2;
  local_78 = (HKEY)0x0;
  local_74 = 0;
  local_70 = 0;
  local_33c = &local_33d;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10003400(local_98,'\0',0);
  FUN_10003040(local_98,&DAT_1002470c,0,0xffffffff);
  local_8._0_1_ = 2;
  local_344 = wcslen(L"\\ksp\\initialize");
  FUN_10002ed0(local_98,(undefined4 *)L"\\ksp\\initialize",local_344);
  local_348 = (LPCWSTR)FUN_100034a0(local_98);
  local_7c = FUN_10001950(&local_78,(HKEY)0x80000002,local_348,0x2001f);
  if (local_7c == 0) {
    local_2e8 = 0;
    local_2d4.dwLowDateTime = 0;
    local_2d4.dwHighDateTime = 0;
    local_2a0 = L'\0';
    memset(local_29e,0,0x1fe);
    local_2c8 = 0;
    local_2cc = 0;
    local_2c4 = 0;
    local_354 = local_78;
    local_7c = RegQueryInfoKeyW(local_78,&local_2a0,&local_2e8,(LPDWORD)0x0,&local_2e8,&local_2e8,
                                &local_2e8,&local_2c8,&local_2cc,&local_2c4,&local_2e8,&local_2d4);
    lVar1 = (ulonglong)(local_2cc + 1) * 2;
    local_314 = (LPWSTR)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    lVar1 = (ulonglong)(local_2c4 + 1) * 2;
    local_2c0 = local_314;
    local_318 = (wchar_t *)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
    ;
    local_35c = &local_35d;
    local_8._0_1_ = 3;
    local_2ec = local_318;
    FUN_10003400(local_2bc,'\0',0);
    local_8._0_1_ = 4;
    local_2e4.Data1 = 0;
    local_2e4.Data2 = 0;
    local_2e4.Data3 = 0;
    local_2e4.Data4[0] = '\0';
    local_2e4.Data4[1] = '\0';
    local_2e4.Data4[2] = '\0';
    local_2e4.Data4[3] = '\0';
    local_2e4.Data4[4] = '\0';
    local_2e4.Data4[5] = '\0';
    local_2e4.Data4[6] = '\0';
    local_2e4.Data4[7] = '\0';
    local_2f0 = 0;
    while ((local_2f0 < local_2c8 && ((local_7c == 0xea || (local_7c == 0))))) {
      local_304 = 0;
      local_2f8[0] = local_2cc + 1;
      local_300[0] = local_2c4 + 1;
      local_7c = RegEnumValueW(local_78,local_2f0,local_2c0,local_2f8,(LPDWORD)0x0,&local_2e8,
                               (LPBYTE)local_2ec,local_300);
      sVar2 = wcslen(local_2ec);
      FUN_10003510(local_2bc,(undefined4 *)local_2ec,sVar2);
      sVar2 = wcslen(L"!");
      local_30c = FUN_10003260(local_2bc,(ushort *)&DAT_1001c934,0,sVar2);
      local_30c = local_30c + 1;
      puVar3 = (undefined4 *)FUN_10002750(local_2bc,local_30,0,local_30c);
      local_8._0_1_ = 5;
      FUN_10002cd0(local_2bc,puVar3);
      local_8._0_1_ = 6;
      FUN_10003400(local_30,'\x01',0);
      local_8._0_1_ = 4;
      local_308 = 3;
      if (local_2a8 < 8) {
        local_374 = (LPCOLESTR *)local_2bc;
      }
      else {
        local_374 = local_2bc[0];
      }
      CLSIDFromString((LPCOLESTR)local_374,&local_2e4);
      sVar2 = wcslen(L" - Initializing this CLSID");
      FUN_10002ed0(local_2bc,(undefined4 *)L" - Initializing this CLSID",sVar2);
      FUN_10016190(local_44,local_2e4.Data1,local_2e4._4_4_,local_2e4.Data4._0_4_,
                   local_2e4.Data4._4_4_);
      local_8._0_1_ = 7;
      local_324 = *(int *)((int)this + 8);
      piVar4 = FUN_10002a20((void *)((int)this + 4),&local_320,local_44);
      local_319 = '\x01' - (*piVar4 == local_324);
      local_8._0_1_ = 4;
      FUN_10016220(local_44);
      if (local_319 == '\0') {
        local_9c = 0;
      }
      else {
        FUN_10016190(local_58,local_2e4.Data1,local_2e4._4_4_,local_2e4.Data4._0_4_,
                     local_2e4.Data4._4_4_);
        local_8._0_1_ = 8;
        piVar4 = FUN_10002ac0(param_1,&local_328,local_58);
        local_304 = *(int *)(*piVar4 + 0x20);
        local_8._0_1_ = 4;
        FUN_10016220(local_58);
        if (local_304 == 0) {
          local_9c = 0x80004005;
        }
        else {
          FUN_10016190(local_6c,local_2e4.Data1,local_2e4._4_4_,local_2e4.Data4._0_4_,
                       local_2e4.Data4._4_4_);
          local_8._0_1_ = 9;
          iVar5 = local_304;
          puVar3 = (undefined4 *)FUN_10002850((void *)((int)this + 4),local_6c);
          local_9c = (*(code *)*puVar3)(iVar5);
          local_8._0_1_ = 4;
          FUN_10016220(local_6c);
        }
      }
      local_2f0 = local_2f0 + 1;
    }
    local_32c = local_2c0;
    operator_delete__(local_2c0);
    local_330 = local_2ec;
    operator_delete__(local_2ec);
    if (local_78 != (HKEY)0x0) {
      RegCloseKey(local_78);
      local_78 = (HKEY)0x0;
    }
    local_74 = 0;
    local_8._0_1_ = 10;
    FUN_10003400(local_2bc,'\x01',0);
  }
  local_334 = local_9c;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_10003400(local_98,'\x01',0);
  local_8 = 0xffffffff;
  if (local_78 != (HKEY)0x0) {
    RegCloseKey(local_78);
    local_78 = (HKEY)0x0;
  }
  local_74 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001910 at 10001910

void __fastcall FUN_10001910(int *param_1)

{
  if (*param_1 != 0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10001950 at 10001950

LSTATUS __thiscall FUN_10001950(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

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
    local_20 = FUN_10001a10(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_8);
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
    *(uint *)((int)this + 4) = param_3 & 0x300;
  }
  return local_c;
}



// Function: FUN_10001a10 at 10001a10

LSTATUS __thiscall
FUN_10001a10(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

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



// Function: FUN_10001ab0 at 10001ab0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_10001ab0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uStack_80;
  undefined4 **local_54;
  int local_4c;
  int *local_48;
  undefined4 **local_44 [5];
  uint local_30;
  uint local_28;
  undefined4 local_24 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10017ee8;
  local_10 = ExceptionList;
  uStack_80 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_80;
  ExceptionList = &local_10;
  local_28 = uStack_80;
  FUN_10004400(local_24);
  local_48 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  uVar2 = (**(code **)*param_1)(param_1,&DAT_1001c8a0,&local_48);
  FUN_10004470(local_24,uVar2);
  FUN_10004500(local_44,&DAT_1002470c,L"\\aif");
  piVar1 = local_48;
  local_8._0_1_ = 4;
  if (local_30 < 8) {
    local_54 = local_44;
  }
  else {
    local_54 = local_44[0];
  }
  if ((undefined4 ***)local_54 == (undefined4 ***)0x0) {
    local_4c = 0;
  }
  else {
    local_4c = Ordinal_2(local_54);
    if (local_4c == 0) {
      FUN_10001c50(0x8007000e);
    }
  }
  local_8._0_1_ = 5;
  uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,local_4c,DAT_10024698);
  FUN_10004470(local_24,uVar2);
  local_8._0_1_ = 4;
  Ordinal_6(local_4c);
  local_8._0_1_ = 6;
  FUN_10003400(local_44,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))(local_48);
  }
  FUN_10001c0a();
  return;
}



// Function: Catch@10001bfd at 10001bfd

undefined4 Catch_10001bfd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10001c11;
}



// Function: FUN_10001c0a at 10001c0a

void FUN_10001c0a(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  *(undefined4 *)(unaff_EBP - 0x4c) = *(undefined4 *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10004450((undefined4 *)(unaff_EBP - 0x20));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10001c41;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x24) ^ unaff_EBP);
  return;
}



// Function: FUN_10001c50 at 10001c50

void FUN_10001c50(undefined4 param_1)

{
  undefined4 local_8;
  
  local_8 = param_1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10020488);
}



// Function: FUN_10001c80 at 10001c80

void __fastcall FUN_10001c80(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001ca0 at 10001ca0

void __fastcall FUN_10001ca0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017f18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001d00 at 10001d00

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_10001d00(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uStack_50;
  undefined4 **local_34;
  int local_2c;
  int *local_28;
  undefined4 local_24 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10017f68;
  local_10 = ExceptionList;
  uStack_50 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_50;
  ExceptionList = &local_10;
  FUN_10004400(local_24);
  local_28 = (int *)0x0;
  local_8 = 3;
  uVar2 = (**(code **)*param_1)(param_1,&DAT_1001c998,&local_28);
  FUN_10004470(local_24,uVar2);
  piVar1 = local_28;
  if (DAT_10024720 < 8) {
    local_34 = &DAT_1002470c;
  }
  else {
    local_34 = (undefined4 **)DAT_1002470c;
  }
  if (local_34 == (undefined4 **)0x0) {
    local_2c = 0;
  }
  else {
    local_2c = Ordinal_2(local_34);
    if (local_2c == 0) {
      FUN_10001c50(0x8007000e);
    }
  }
  local_8._0_1_ = 4;
  uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,local_2c,DAT_10024698);
  FUN_10004470(local_24,uVar2);
  local_8._0_1_ = 3;
  Ordinal_6(local_2c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  FUN_10001e37();
  return;
}



// Function: Catch@10001e23 at 10001e23

undefined4 Catch_10001e23(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10001e3e;
}



// Function: FUN_10001e37 at 10001e37

undefined4 FUN_10001e37(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10004450((undefined4 *)(unaff_EBP + -0x20));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x2c);
}



// Function: FUN_10001e70 at 10001e70

void __cdecl FUN_10001e70(undefined4 *param_1)

{
  LPCWSTR ***local_ac;
  DWORD local_98 [3];
  DWORD local_8c [3];
  DWORD local_80 [5];
  size_t local_6c;
  undefined1 local_65;
  undefined1 *local_64;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  LPCWSTR ***local_48 [5];
  uint local_34;
  uint local_2c;
  LSTATUS local_28;
  HKEY local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017fc8;
  local_10 = ExceptionList;
  local_2c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_14 = (int *)0x0;
  local_8 = 1;
  local_18 = (**(code **)*param_1)(param_1,&DAT_1001c9ec,&local_14,local_2c);
  if (-1 < local_18) {
    local_24 = (HKEY)0x0;
    local_20 = 0;
    local_1c = 0;
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_64 = &local_65;
    local_8._0_1_ = 3;
    FUN_10003400(local_48,'\0',0);
    FUN_10003040(local_48,&DAT_1002470c,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,4);
    local_6c = wcslen(L"\\ts");
    FUN_10002ed0(local_48,(undefined4 *)&DAT_1001c9e4,local_6c);
    if (local_34 < 8) {
      local_ac = (LPCWSTR ***)local_48;
    }
    else {
      local_ac = local_48[0];
    }
    local_28 = FUN_10001950(&local_24,(HKEY)0x80000002,(LPCWSTR)local_ac,0x2001f);
    if (local_28 == 0) {
      local_4c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_80[1] = 0;
      local_80[0] = 4;
      local_8c[2] = RegQueryValueExW(local_24,L"MaxThreads",(LPDWORD)0x0,local_80 + 1,
                                     (LPBYTE)&local_4c,local_80);
      local_50 = local_4c;
      local_8c[1] = 0;
      local_8c[0] = 4;
      local_98[2] = RegQueryValueExW(local_24,L"TimeOut",(LPDWORD)0x0,local_8c + 1,(LPBYTE)&local_4c
                                     ,local_8c);
      local_54 = local_4c;
      local_98[1] = 0;
      local_98[0] = 4;
      RegQueryValueExW(local_24,L"PoolSize",(LPDWORD)0x0,local_98 + 1,(LPBYTE)&local_4c,local_98);
      local_58 = local_4c;
      if (local_24 != (HKEY)0x0) {
        RegCloseKey(local_24);
        local_24 = (HKEY)0x0;
      }
      local_20 = 0;
      local_18 = (**(code **)(*local_14 + 0x1c))(local_14,&local_58);
    }
    else {
      local_18 = -0x7fffbffb;
    }
    local_8._0_1_ = 5;
    FUN_10003400(local_48,'\x01',0);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_24 != (HKEY)0x0) {
      RegCloseKey(local_24);
      local_24 = (HKEY)0x0;
    }
    local_20 = 0;
  }
  local_5c = local_18;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_2c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002150 at 10002150

void __fastcall FUN_10002150(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10017ff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100021b0 at 100021b0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl FUN_100021b0(undefined4 *param_1)

{
  int *piVar1;
  size_t sVar2;
  undefined4 **local_54;
  undefined1 local_49;
  undefined1 *local_48;
  int local_40;
  int local_3c;
  undefined4 **local_38 [5];
  uint local_24;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018058;
  local_10 = ExceptionList;
  local_1c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_14 = (int *)0x0;
  local_8 = 1;
  local_18 = (**(code **)*param_1)(param_1,&DAT_1001c998,&local_14,local_1c);
  if (-1 < local_18) {
    local_48 = &local_49;
    local_8._0_1_ = 2;
    FUN_10003400(local_38,'\0',0);
    FUN_10003040(local_38,&DAT_1002470c,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,3);
    sVar2 = wcslen(L"\\tss");
    FUN_10002ed0(local_38,(undefined4 *)L"\\tss",sVar2);
    piVar1 = local_14;
    if (local_24 < 8) {
      local_54 = local_38;
    }
    else {
      local_54 = local_38[0];
    }
    if ((undefined4 ***)local_54 == (undefined4 ***)0x0) {
      local_3c = 0;
    }
    else {
      local_3c = Ordinal_2(local_54);
      if (local_3c == 0) {
        FUN_10001c50(0x8007000e);
      }
    }
    local_8._0_1_ = 4;
    local_18 = (**(code **)(*piVar1 + 0xc))(piVar1,local_3c,0);
    local_8._0_1_ = 3;
    Ordinal_6(local_3c);
    local_8._0_1_ = 5;
    FUN_10003400(local_38,'\x01',0);
  }
  local_40 = local_18;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_1c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002350 at 10002350

undefined4 __cdecl FUN_10002350(undefined4 *param_1)

{
  undefined4 uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)*param_1)
                    (param_1,&DAT_1001ca08,&local_14,DAT_10024664 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_100023f0 at 100023f0

void __fastcall FUN_100023f0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100180c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002450 at 10002450

undefined4 __cdecl FUN_10002450(undefined4 *param_1)

{
  undefined4 uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018108;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_1001ca18,&local_14,DAT_10024664 ^ (uint)&stack0xfffffffc);
  uVar1 = (**(code **)(*local_14 + 0x1c))(local_14);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10002500 at 10002500

void __fastcall FUN_10002500(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018138;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002560 at 10002560

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl FUN_10002560(undefined4 *param_1)

{
  int *piVar1;
  undefined4 **local_50;
  undefined1 local_49;
  undefined1 *local_48;
  undefined4 local_40;
  int local_3c;
  undefined4 **local_38 [5];
  uint local_24;
  uint local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018198;
  local_10 = ExceptionList;
  local_1c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_14 = (int *)0x0;
  local_8 = 1;
  local_18 = (**(code **)*param_1)(param_1,&DAT_1001c998,&local_14,local_1c);
  local_48 = &local_49;
  local_8._0_1_ = 2;
  FUN_10003400(local_38,'\0',0);
  FUN_10003040(local_38,&DAT_1002470c,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10002da0(local_38,(undefined4 *)&DAT_10024728,0,0xffffffff);
  piVar1 = local_14;
  if (local_24 < 8) {
    local_50 = local_38;
  }
  else {
    local_50 = local_38[0];
  }
  if ((undefined4 ***)local_50 == (undefined4 ***)0x0) {
    local_3c = 0;
  }
  else {
    local_3c = Ordinal_2(local_50);
    if (local_3c == 0) {
      FUN_10001c50(0x8007000e);
    }
  }
  local_8._0_1_ = 4;
  local_18 = (**(code **)(*piVar1 + 0xc))(piVar1,local_3c,DAT_10024698);
  local_8._0_1_ = 3;
  Ordinal_6(local_3c);
  local_40 = local_18;
  local_8._0_1_ = 5;
  FUN_10003400(local_38,'\x01',0);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_1c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100026f0 at 100026f0

void __fastcall FUN_100026f0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100181c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(param_1,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002750 at 10002750

void * __thiscall FUN_10002750(void *this,void *param_1,uint param_2,uint param_3)

{
  undefined1 local_21;
  undefined1 *local_20;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018211;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  local_20 = &local_21;
  local_8 = 1;
  FUN_10003400(param_1,'\0',0);
  FUN_10003040(param_1,(undefined4 *)this,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100027e0 at 100027e0

int __fastcall FUN_100027e0(int param_1)

{
  int iStack_4c;
  uint uStack_48;
  int local_40;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018240;
  local_10 = ExceptionList;
  uStack_48 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined1 *)&iStack_4c;
  local_1c = (undefined1 *)&iStack_4c;
  iStack_4c = param_1;
  local_40 = param_1;
  FUN_10003890(param_1);
  ExceptionList = local_10;
  return local_40;
}



// Function: FUN_10002850 at 10002850

void __thiscall FUN_10002850(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 local_2c [5];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018288;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = FUN_10003820(this,(int)param_1);
  local_34 = *(undefined4 **)((int)this + 4);
  if (local_30 != local_34) {
    cVar1 = FUN_100162b0(param_1,(int)(local_30 + 3));
    if (cVar1 == '\0') goto LAB_10002952;
  }
  local_38 = 0;
  local_3c = local_30;
  FUN_100161d0(local_2c,(int)param_1);
  local_18 = local_38;
  local_8 = 2;
  piVar2 = (int *)FUN_10005950(this,(int)local_2c);
  FUN_100049d0(this,(int *)&local_40,local_3c,piVar2);
  local_30 = local_40;
  local_8 = 0xffffffff;
  FUN_10016220(local_2c);
LAB_10002952:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002980 at 10002980

void __fastcall FUN_10002980(void *param_1)

{
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100182b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = *(int **)((int)param_1 + 4);
  local_20 = (int *)**(undefined4 **)((int)param_1 + 4);
  local_1c = local_20;
  local_14 = local_18;
  FUN_10003740(param_1,&local_24,local_20,local_18);
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a20 at 10002a20

int * __thiscall FUN_10002a20(void *this,int *param_1,void *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *local_34;
  int local_14;
  int local_10;
  int local_8;
  
  puVar2 = FUN_10003820(this,(int)param_2);
  FUN_10004140(&local_8,puVar2);
  local_10 = *(int *)((int)this + 4);
  if (local_8 != local_10) {
    cVar1 = FUN_100162b0(param_2,local_8 + 0xc);
    if (cVar1 == '\0') {
      local_34 = &local_8;
      goto LAB_10002aa2;
    }
  }
  local_34 = &local_14;
LAB_10002aa2:
  *param_1 = *local_34;
  return param_1;
}



// Function: FUN_10002ac0 at 10002ac0

int * __thiscall FUN_10002ac0(void *this,int *param_1,void *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *local_34;
  int local_14;
  int local_10;
  int local_8;
  
  puVar2 = FUN_10003910(this,(int)param_2);
  FUN_10004160(&local_8,puVar2);
  local_10 = *(int *)((int)this + 4);
  if (local_8 != local_10) {
    cVar1 = FUN_100162b0(param_2,local_8 + 0xc);
    if (cVar1 == '\0') {
      local_34 = &local_8;
      goto LAB_10002b42;
    }
  }
  local_34 = &local_14;
LAB_10002b42:
  *param_1 = *local_34;
  return param_1;
}



// Function: FUN_10002b60 at 10002b60

void __fastcall FUN_10002b60(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002b90 at 10002b90

void __fastcall FUN_10002b90(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002bc0 at 10002bc0

void __fastcall FUN_10002bc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002bf0 at 10002bf0

void __fastcall FUN_10002bf0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002c20 at 10002c20

void __fastcall FUN_10002c20(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100182f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002c80

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018318;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002cd0 at 10002cd0

/* WARNING: Removing unreachable block (ram,0x10002cf9) */
/* WARNING: Removing unreachable block (ram,0x10002d02) */

undefined4 * __thiscall FUN_10002cd0(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    FUN_10003400(this,'\x01',0);
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,(param_1[4] + 1) * 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    FUN_10003400(param_1,'\0',0);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002da0 at 10002da0

undefined4 * __thiscall FUN_10002da0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  void *local_34;
  void *local_30;
  undefined4 *local_2c;
  
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
    bVar1 = FUN_10003640(this,uVar2,'\0');
    if (bVar1) {
      if ((uint)param_1[5] < 8) {
        local_2c = param_1;
      }
      else {
        local_2c = (undefined4 *)*param_1;
      }
      local_30 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_30 = *this;
      }
      memcpy((void *)((int)local_30 + *(int *)((int)this + 0x10) * 2),
             (void *)((int)local_2c + param_2 * 2),param_3 << 1);
      *(uint *)((int)this + 0x10) = uVar2;
      local_34 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_34 = *this;
      }
      *(undefined2 *)((int)local_34 + uVar2 * 2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10002ed0 at 10002ed0

undefined4 * __thiscall FUN_10002ed0(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  void *local_4c;
  void *local_48;
  void *local_44;
  void *local_40;
  undefined4 *local_3c;
  
  if (param_1 != (undefined4 *)0x0) {
    local_3c = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_3c = *this;
    }
    if (local_3c <= param_1) {
      local_40 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_40 = *this;
      }
      if (param_1 < (undefined4 *)((int)local_40 + *(int *)((int)this + 0x10) * 2)) {
        bVar1 = true;
        goto LAB_10002f36;
      }
    }
  }
  bVar1 = false;
LAB_10002f36:
  if (bVar1) {
    local_44 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_44 = *this;
    }
    this = FUN_10002da0(this,(undefined4 *)this,(int)param_1 - (int)local_44 >> 1,param_2);
  }
  else {
    if (-*(int *)((int)this + 0x10) - 1U <= param_2) {
      std::_Xlength_error("string too long");
    }
    if (param_2 != 0) {
      uVar2 = *(int *)((int)this + 0x10) + param_2;
      bVar1 = FUN_10003640(this,uVar2,'\0');
      if (bVar1) {
        local_48 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_48 = *this;
        }
        memcpy((void *)((int)local_48 + *(int *)((int)this + 0x10) * 2),param_1,param_2 << 1);
        *(uint *)((int)this + 0x10) = uVar2;
        local_4c = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          local_4c = *this;
        }
        *(undefined2 *)((int)local_4c + uVar2 * 2) = 0;
      }
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10003040 at 10003040

undefined4 * __thiscall FUN_10003040(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10003160(this,param_2 + local_8,0xffffffff);
    FUN_10003160(this,0,param_2);
  }
  else {
    bVar1 = FUN_10003640(this,local_8,'\0');
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



// Function: FUN_10003160 at 10003160

undefined4 * __thiscall FUN_10003160(void *this,uint param_1,uint param_2)

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



// Function: FUN_10003260 at 10003260

uint __thiscall FUN_10003260(void *this,ushort *param_1,uint param_2,uint param_3)

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
            goto LAB_10003341;
          }
          local_14 = local_14 + 1;
        }
        local_1c = (ushort *)0x0;
LAB_10003341:
        if (local_1c == (ushort *)0x0) break;
        local_24 = param_1;
        local_20 = local_1c;
        for (local_28 = param_3; local_28 != 0; local_28 = local_28 - 1) {
          if (*local_20 != *local_24) {
            local_2c = (uint)(*local_24 <= *local_20) * 2 + -1;
            goto LAB_100033bb;
          }
          local_20 = local_20 + 1;
          local_24 = local_24 + 1;
        }
        local_2c = 0;
LAB_100033bb:
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



// Function: FUN_10003400 at 10003400

void __thiscall FUN_10003400(void *this,char param_1,int param_2)

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



// Function: FUN_100034a0 at 100034a0

undefined4 * __fastcall FUN_100034a0(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)*param_1;
  }
  return local_c;
}



// Function: FUN_100034d0 at 100034d0

void FUN_100034d0(void)

{
  return;
}



// Function: FUN_100034e0 at 100034e0

void __fastcall FUN_100034e0(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10003510 at 10003510

undefined4 * __thiscall FUN_10003510(void *this,undefined4 *param_1,uint param_2)

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
        goto LAB_10003576;
      }
    }
  }
  bVar1 = false;
LAB_10003576:
  if (bVar1) {
    local_40 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      local_40 = *this;
    }
    this = FUN_10003040(this,(undefined4 *)this,(int)param_1 - (int)local_40 >> 1,param_2);
  }
  else {
    bVar1 = FUN_10003640(this,param_2,'\0');
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



// Function: FUN_10003640 at 10003640

/* WARNING: Removing unreachable block (ram,0x1000365e) */
/* WARNING: Removing unreachable block (ram,0x10003671) */

bool __thiscall FUN_10003640(void *this,uint param_1,char param_2)

{
  undefined2 *local_2c;
  uint local_28;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10003980(this,param_1);
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
    FUN_10003400(this,'\x01',local_28);
  }
  return param_1 != 0;
}



// Function: FUN_10003740 at 10003740

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_10003740(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)**(int **)((int)param_1 + 4);
  if ((param_3 == local_8) && (local_c = *(int **)((int)param_1 + 4), param_4 == local_c)) {
    FUN_100040e0(param_1);
    *param_2 = **(undefined4 **)((int)param_1 + 4);
    return param_2;
  }
  while (piVar1 = param_3, param_3 != param_4) {
    FUN_10004350((int *)&param_3);
    local_10 = piVar1;
    FUN_10003c00(param_1,&local_14,piVar1);
  }
  *param_2 = param_3;
  return param_2;
}



// Function: FUN_10003820 at 10003820

undefined4 * __thiscall FUN_10003820(void *this,int param_1)

{
  char cVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_8 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x25) == '\0') {
    cVar1 = FUN_100162b0(local_c + 3,param_1);
    if (cVar1 == '\0') {
      local_8 = local_c;
      local_c = (undefined4 *)*local_c;
    }
    else {
      local_c = (undefined4 *)local_c[2];
    }
  }
  return local_8;
}



// Function: FUN_10003890 at 10003890

int __fastcall FUN_10003890(int param_1)

{
  void *pvVar1;
  undefined1 local_d;
  undefined1 *local_c;
  
  local_c = &local_d;
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10004690(1);
  *(void **)(param_1 + 4) = pvVar1;
  **(undefined4 **)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x24) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x25) = 1;
  return param_1;
}



// Function: FUN_10003910 at 10003910

undefined4 * __thiscall FUN_10003910(void *this,int param_1)

{
  char cVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_8 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x25) == '\0') {
    cVar1 = FUN_100162b0(local_c + 3,param_1);
    if (cVar1 == '\0') {
      local_8 = local_c;
      local_c = (undefined4 *)*local_c;
    }
    else {
      local_c = (undefined4 *)local_c[2];
    }
  }
  return local_8;
}



// Function: FUN_10003980 at 10003980

/* WARNING: Removing unreachable block (ram,0x10003a37) */
/* WARNING: Removing unreachable block (ram,0x100039cd) */
/* WARNING: Removing unreachable block (ram,0x10003a9c) */
/* WARNING: Removing unreachable block (ram,0x10003a4a) */
/* WARNING: Removing unreachable block (ram,0x100039e0) */
/* WARNING: Removing unreachable block (ram,0x10003ab5) */

void __thiscall FUN_10003980(void *this,uint param_1)

{
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018340;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
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
  FUN_10004810(local_1c + 1);
  FUN_10003b4c();
  return;
}



// Function: Catch@10003af3 at 10003af3

void Catch_10003af3(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = FUN_10004810(*(int *)(unaff_EBP + -0x18) + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  FUN_10003b38();
  return;
}



// Function: Catch@10003b16 at 10003b16

void Catch_10003b16(void)

{
  int unaff_EBP;
  
  FUN_10003400(*(void **)(unaff_EBP + -0x70),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10003b38 at 10003b38

undefined4 FUN_10003b38(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10003b53;
}



// Function: FUN_10003b4c at 10003b4c

void FUN_10003b4c(void)

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
  FUN_10003400(*(void **)(unaff_EBP + -0x70),'\x01',0);
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



// Function: FUN_10003c00 at 10003c00

undefined4 * __thiscall FUN_10003c00(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *local_88;
  int *local_84;
  int *local_28;
  int *local_20;
  int *local_14;
  int *local_10;
  int *local_c;
  
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  piVar2 = param_2;
  FUN_10004350((int *)&param_2);
  local_10 = piVar2;
  if (*(char *)(*piVar2 + 0x25) == '\0') {
    if (*(char *)(piVar2[2] + 0x25) == '\0') {
      local_10 = param_2;
      local_c = (int *)param_2[2];
    }
    else {
      local_c = (int *)*piVar2;
    }
  }
  else {
    local_c = (int *)piVar2[2];
  }
  if (local_10 == piVar2) {
    local_14 = (int *)piVar2[1];
    if (*(char *)((int)local_c + 0x25) == '\0') {
      local_c[1] = (int)local_14;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_c;
    }
    else if ((int *)*local_14 == piVar2) {
      *local_14 = (int)local_c;
    }
    else {
      local_14[2] = (int)local_c;
    }
    if ((int *)**(int **)((int)this + 4) == piVar2) {
      local_84 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        for (local_20 = local_c; *(char *)(*local_20 + 0x25) == '\0'; local_20 = (int *)*local_20) {
        }
        local_84 = local_20;
      }
      **(int **)((int)this + 4) = (int)local_84;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      local_88 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_28 = local_c;
        while (*(char *)(local_28[2] + 0x25) == '\0') {
          local_28 = (int *)local_28[2];
        }
        local_88 = local_28;
      }
      *(int **)(*(int *)((int)this + 4) + 8) = local_88;
    }
  }
  else {
    *(int **)(*piVar2 + 4) = local_10;
    *local_10 = *piVar2;
    if (local_10 == (int *)piVar2[2]) {
      local_14 = local_10;
    }
    else {
      local_14 = (int *)local_10[1];
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_c[1] = (int)local_14;
      }
      *local_14 = (int)local_c;
      local_10[2] = piVar2[2];
      *(int **)(piVar2[2] + 4) = local_10;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_10;
    }
    else if (*(int **)piVar2[1] == piVar2) {
      *(int **)piVar2[1] = local_10;
    }
    else {
      *(int **)(piVar2[1] + 8) = local_10;
    }
    local_10[1] = piVar2[1];
    iVar1 = local_10[9];
    *(char *)(local_10 + 9) = (char)piVar2[9];
    *(char *)(piVar2 + 9) = (char)iVar1;
  }
  if ((char)piVar2[9] != '\x01') {
LAB_1000408d:
    FUN_10004620((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return param_1;
  }
LAB_10003e9d:
  if ((local_c == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)local_c[9] != '\x01'))
  goto LAB_10004086;
  if (local_c == (int *)*local_14) {
    local_10 = (int *)local_14[2];
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_100041f0(this,(int)local_14);
      local_10 = (int *)local_14[2];
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(*local_10 + 0x24) != '\x01') || (*(char *)(local_10[2] + 0x24) != '\x01')) {
        if (*(char *)(local_10[2] + 0x24) == '\x01') {
          *(undefined1 *)(*local_10 + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_100042a0(this,local_10);
          local_10 = (int *)local_14[2];
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(local_10[2] + 0x24) = 1;
        FUN_100041f0(this,(int)local_14);
LAB_10004086:
        *(undefined1 *)(local_c + 9) = 1;
        goto LAB_1000408d;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  else {
    local_10 = (int *)*local_14;
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_100042a0(this,local_14);
      local_10 = (int *)*local_14;
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(local_10[2] + 0x24) != '\x01') || (*(char *)(*local_10 + 0x24) != '\x01')) {
        if (*(char *)(*local_10 + 0x24) == '\x01') {
          *(undefined1 *)(local_10[2] + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_100041f0(this,(int)local_10);
          local_10 = (int *)*local_14;
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(*local_10 + 0x24) = 1;
        FUN_100042a0(this,local_14);
        goto LAB_10004086;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  local_c = local_14;
  local_14 = (int *)local_14[1];
  goto LAB_10003e9d;
}



// Function: FUN_100040e0 at 100040e0

void __fastcall FUN_100040e0(void *param_1)

{
  FUN_10004180(param_1,*(undefined4 **)(*(int *)((int)param_1 + 4) + 4));
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 4) = *(undefined4 *)((int)param_1 + 4);
  **(undefined4 **)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 8) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10004140 at 10004140

undefined4 * __thiscall FUN_10004140(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10004160 at 10004160

undefined4 * __thiscall FUN_10004160(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10004180 at 10004180

void __thiscall FUN_10004180(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = param_1;
  while (*(char *)((int)local_8 + 0x25) == '\0') {
    FUN_10004180(this,(undefined4 *)local_8[2]);
    puVar1 = (undefined4 *)*local_8;
    FUN_10004620((int)this + 0xd,local_8 + 3);
    operator_delete(local_8);
    local_8 = puVar1;
  }
  return;
}



// Function: FUN_100041f0 at 100041f0

void __thiscall FUN_100041f0(void *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x25) == '\0') {
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



// Function: FUN_100042a0 at 100042a0

void __thiscall FUN_100042a0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x25) == '\0') {
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



// Function: FUN_10004350 at 10004350

int * __fastcall FUN_10004350(int *param_1)

{
  int iVar1;
  int *local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)(*param_1 + 8) + 0x25) == '\0') {
      for (local_14 = *(int **)(*param_1 + 8); *(char *)(*local_14 + 0x25) == '\0';
          local_14 = (int *)*local_14) {
      }
      *param_1 = (int)local_14;
    }
    else {
      while ((iVar1 = *(int *)(*param_1 + 4), *(char *)(iVar1 + 0x25) == '\0' &&
             (*param_1 == *(int *)(iVar1 + 8)))) {
        *param_1 = iVar1;
      }
      *param_1 = iVar1;
    }
  }
  return param_1;
}



// Function: FUN_10004400 at 10004400

undefined4 * __fastcall FUN_10004400(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return param_1;
}



// Function: FUN_10004450 at 10004450

void __fastcall FUN_10004450(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10004470 at 10004470

int __thiscall FUN_10004470(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (*(int *)((int)this + 0xc) < 0)) {
    *(char *)((int)this + 4) = '\x01';
    FUN_10005520(*(int *)((int)this + 0xc),*(undefined4 *)((int)this + 8));
  }
  return (int)this;
}



// Function: FUN_10004500 at 10004500

void __cdecl FUN_10004500(void *param_1,undefined4 *param_2,wchar_t *param_3)

{
  size_t sVar1;
  undefined1 local_71;
  undefined1 *local_70;
  size_t local_60;
  int local_44;
  undefined1 local_3d;
  undefined1 *local_3c;
  uint local_34;
  undefined4 local_30 [7];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10018399;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0;
  local_3c = &local_3d;
  local_8 = 1;
  FUN_10003400(local_30,'\0',0);
  local_8 = 2;
  local_44 = param_2[4];
  sVar1 = wcslen(param_3);
  FUN_10004950(local_30,sVar1 + local_44);
  FUN_10002da0(local_30,param_2,0,0xffffffff);
  local_60 = wcslen(param_3);
  FUN_10002ed0(local_30,(undefined4 *)param_3,local_60);
  local_70 = &local_71;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10003400(param_1,'\0',0);
  FUN_10002cd0(param_1,local_30);
  local_34 = local_34 | 1;
  local_8 = 4;
  FUN_10003400(local_30,'\x01',0);
  local_8 = local_8 & 0xffffff00;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004620 at 10004620

/* WARNING: Removing unreachable block (ram,0x10004666) */

void __cdecl FUN_10004620(undefined4 param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100183d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004690 at 10004690

void * __cdecl FUN_10004690(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100183f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x6666666 < param_1 || (local_14 = operator_new(param_1 * 0x28), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004740 at 10004740

void __fastcall FUN_10004740(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018429;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100047a0 at 100047a0

exception * __thiscall FUN_100047a0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018459;
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



// Function: FUN_10004810 at 10004810

void * __cdecl FUN_10004810(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018489;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x7fffffff < param_1 || (local_14 = operator_new(param_1 << 1), local_14 == (void *)0x0)))) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100048c0 at 100048c0

undefined4 * __thiscall FUN_100048c0(void *this,uint param_1)

{
  FUN_10004450((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100048f0 at 100048f0

exception * __thiscall FUN_100048f0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100184b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10004950 at 10004950

void __thiscall FUN_10004950(void *this,uint param_1)

{
  int iVar1;
  bool bVar2;
  void *local_28;
  
  if ((*(uint *)((int)this + 0x10) <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    iVar1 = *(int *)((int)this + 0x10);
    bVar2 = FUN_10003640(this,param_1,'\x01');
    if (bVar2) {
      *(int *)((int)this + 0x10) = iVar1;
      local_28 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        local_28 = *this;
      }
      *(undefined2 *)((int)local_28 + iVar1 * 2) = 0;
    }
  }
  return;
}



// Function: FUN_100049d0 at 100049d0

/* WARNING: Removing unreachable block (ram,0x10004a39) */
/* WARNING: Removing unreachable block (ram,0x10004ab8) */
/* WARNING: Removing unreachable block (ram,0x10004b57) */
/* WARNING: Removing unreachable block (ram,0x10004b7d) */
/* WARNING: Removing unreachable block (ram,0x10004bad) */
/* WARNING: Removing unreachable block (ram,0x10004bea) */
/* WARNING: Removing unreachable block (ram,0x10004bc7) */
/* WARNING: Removing unreachable block (ram,0x10004c10) */
/* WARNING: Removing unreachable block (ram,0x10004c36) */
/* WARNING: Removing unreachable block (ram,0x10004c7b) */
/* WARNING: Removing unreachable block (ram,0x10004c9d) */
/* WARNING: Removing unreachable block (ram,0x10004cda) */
/* WARNING: Removing unreachable block (ram,0x10004cb7) */
/* WARNING: Removing unreachable block (ram,0x10004cfd) */
/* WARNING: Removing unreachable block (ram,0x10004aef) */
/* WARNING: Removing unreachable block (ram,0x10004b28) */
/* WARNING: Removing unreachable block (ram,0x10004b52) */
/* WARNING: Removing unreachable block (ram,0x10004a72) */
/* WARNING: Removing unreachable block (ram,0x10004a8e) */
/* WARNING: Removing unreachable block (ram,0x10004aaf) */
/* WARNING: Removing unreachable block (ram,0x10004d01) */

int * __thiscall FUN_100049d0(void *this,int *param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int local_30 [2];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20 [4];
  int *local_10;
  char local_9;
  undefined4 *local_8;
  
  local_10 = param_3 + 3;
  local_8 = (undefined4 *)0x0;
  local_9 = '\0';
  if (*(int *)((int)this + 8) == 0) {
    FUN_10005240(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
  }
  else {
    FUN_10004140(local_20,**(undefined4 **)((int)this + 4));
    if (param_2 == local_20[0]) {
      cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
      if (cVar1 != '\0') {
        FUN_10005240(this,param_1,'\x01',param_2,param_3);
        return param_1;
      }
    }
    else {
      FUN_10004140(&local_24,*(undefined4 *)((int)this + 4));
      if (param_2 == local_24) {
        cVar1 = FUN_100162b0((void *)(*(int *)(*(int *)((int)this + 4) + 8) + 0xc),(int)local_10);
        if (cVar1 != '\0') {
          FUN_10005240(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),param_3);
          return param_1;
        }
      }
      else {
        cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_10005890((int *)&local_8);
          cVar1 = FUN_100162b0(local_8 + 3,(int)local_10);
          if (cVar1 != '\0') {
            if (*(char *)(local_8[2] + 0x25) != '\0') {
              FUN_10005240(this,param_1,'\0',local_8,param_3);
              return param_1;
            }
            FUN_10005240(this,param_1,'\x01',param_2,param_3);
            return param_1;
          }
        }
        cVar1 = FUN_100162b0(param_2 + 3,(int)local_10);
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_10004140(&local_28,*(undefined4 *)((int)this + 4));
          FUN_10004350((int *)&local_8);
          if ((local_8 == local_28) ||
             (cVar1 = FUN_100162b0(local_10,(int)(local_8 + 3)), cVar1 != '\0')) {
            if (*(char *)(param_2[2] + 0x25) != '\0') {
              FUN_10005240(this,param_1,'\0',param_2,param_3);
              return param_1;
            }
            FUN_10005240(this,param_1,'\x01',local_8,param_3);
            return param_1;
          }
        }
      }
    }
    piVar2 = FUN_10005000(this,local_30,param_3,local_9);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_10005000 at 10005000

/* WARNING: Removing unreachable block (ram,0x100050b0) */

int * __thiscall FUN_10005000(void *this,int *param_1,int *param_2,char param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_98;
  undefined4 local_34;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined1 local_25;
  int local_24 [3];
  int local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  char local_5;
  
  local_14 = param_2 + 3;
  local_10 = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_c = *(undefined4 **)((int)this + 4);
  local_5 = '\x01';
  while (*(char *)((int)local_10 + 0x25) == '\0') {
    local_c = local_10;
    if (param_3 == '\0') {
      local_5 = FUN_100162b0(local_14,(int)(local_10 + 3));
    }
    else {
      cVar1 = FUN_100162b0(local_10 + 3,(int)local_14);
      local_5 = '\x01' - (cVar1 != '\0');
    }
    if (local_5 == '\0') {
      local_98 = (undefined4 *)local_10[2];
    }
    else {
      local_98 = (undefined4 *)*local_10;
    }
    local_10 = local_98;
  }
  FUN_10004140(&local_18,local_c);
  if (local_5 != '\0') {
    FUN_10004140(local_24,**(undefined4 **)((int)this + 4));
    if (local_18 == local_24[0]) {
      local_25 = 1;
      piVar2 = FUN_10005240(this,&local_2c,'\x01',local_c,param_2);
      *param_1 = *piVar2;
      *(undefined1 *)(param_1 + 1) = local_25;
      return param_1;
    }
    FUN_10005890(&local_18);
  }
  cVar1 = FUN_100162b0((void *)(local_18 + 0xc),(int)local_14);
  if (cVar1 == '\0') {
    FUN_10004620((int)this + 0xd,param_2 + 3);
    operator_delete(param_2);
    *param_1 = local_18;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    local_2d = 1;
    piVar2 = FUN_10005240(this,&local_34,local_5,local_c,param_2);
    *param_1 = *piVar2;
    *(undefined1 *)(param_1 + 1) = local_2d;
  }
  return param_1;
}



// Function: FUN_10005240 at 10005240

/* WARNING: Removing unreachable block (ram,0x1000525e) */

undefined4 * __thiscall
FUN_10005240(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int *local_8;
  
  if (0xaaaaaa8 < *(uint *)((int)this + 8)) {
    FUN_10004620((int)this + 0xd,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)((int)this + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = param_4;
    **(undefined4 **)((int)this + 4) = param_4;
    *(int **)(*(int *)((int)this + 4) + 8) = param_4;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_4;
    if (param_3 == *(undefined4 **)(*(int *)((int)this + 4) + 8)) {
      *(int **)(*(int *)((int)this + 4) + 8) = param_4;
    }
  }
  else {
    *param_3 = param_4;
    if (param_3 == (undefined4 *)**(int **)((int)this + 4)) {
      **(undefined4 **)((int)this + 4) = param_4;
    }
  }
  local_8 = param_4;
  while (*(char *)(local_8[1] + 0x24) == '\0') {
    if (local_8[1] == **(int **)(local_8[1] + 4)) {
      iVar1 = *(int *)(*(int *)(local_8[1] + 4) + 8);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)(local_8[1] + 8)) {
          local_8 = (int *)local_8[1];
          FUN_100041f0(this,(int)local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_100042a0(this,*(int **)(local_8[1] + 4));
      }
    }
    else {
      iVar1 = **(int **)(local_8[1] + 4);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)local_8[1]) {
          local_8 = (int *)local_8[1];
          FUN_100042a0(this,local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_100041f0(this,*(int *)(local_8[1] + 4));
      }
    }
  }
  *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x24) = 1;
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_10005520 at 10005520

void FUN_10005520(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [48];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100184fb;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100055e0(local_74,param_1,0,param_2,(wchar_t *)&PTR_1001caa0,0);
  local_8 = 0;
  FUN_100057c0(local_44,(int)local_74);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_44,(ThrowInfo *)&DAT_10020b20);
}



// Function: FUN_100055e0 at 100055e0

undefined4 * __thiscall
FUN_100055e0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
            undefined4 param_5)

{
  size_t sVar1;
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018543;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_18 = &local_19;
  local_8 = 0;
  FUN_10003400((void *)((int)this + 0x10),'\0',0);
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  sVar1 = wcslen(param_4);
  FUN_10003510((void *)((int)this + 0x10),(undefined4 *)param_4,sVar1);
  *(undefined4 *)((int)this + 0x2c) = param_5;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100056b0 at 100056b0

void __fastcall FUN_100056b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018573;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003400(param_1 + 4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005730 at 10005730

undefined4 * __thiscall FUN_10005730(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100185a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_8 = 1;
  FUN_10003400((void *)((int)this + 0x10),'\x01',0);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100057c0 at 100057c0

undefined4 * __thiscall FUN_100057c0(void *this,int param_1)

{
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100185d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  local_18 = &local_19;
  local_8 = 0;
  FUN_10003400((void *)((int)this + 0x10),'\0',0);
  FUN_10003040((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005890 at 10005890

int * __fastcall FUN_10005890(int *param_1)

{
  int *piVar1;
  int local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)*param_1 + 0x25) == '\0') {
      local_14 = *(int *)*param_1;
      while (*(char *)(*(int *)(local_14 + 8) + 0x25) == '\0') {
        local_14 = *(int *)(local_14 + 8);
      }
      *param_1 = local_14;
    }
    else {
      while ((piVar1 = *(int **)(*param_1 + 4), *(char *)((int)piVar1 + 0x25) == '\0' &&
             (*param_1 == *piVar1))) {
        *param_1 = (int)piVar1;
      }
      if (*(char *)(*param_1 + 0x25) == '\0') {
        *param_1 = (int)piVar1;
      }
    }
  }
  else {
    *param_1 = *(int *)(*param_1 + 8);
  }
  return param_1;
}



// Function: FUN_10005950 at 10005950

void __thiscall FUN_10005950(void *this,int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100185f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = FUN_100059f0((int)this);
  local_8 = 0;
  FUN_10005a40((int)this + 0xd,puVar1 + 3,param_1);
  FUN_100059cf();
  return;
}



// Function: Catch@100059ad at 100059ad

void Catch_100059ad(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100059cf at 100059cf

undefined4 FUN_100059cf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100059f0 at 100059f0

undefined4 * __fastcall FUN_100059f0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10004690(1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(puVar1 + 9) = 0;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  return puVar1;
}



// Function: FUN_10005a40 at 10005a40

void __cdecl FUN_10005a40(undefined4 param_1,void *param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018631;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (void *)0x0) {
    FUN_100161d0(param_2,param_3);
    *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005ad0 at 10005ad0

void FUN_10005ad0(void)

{
  return;
}



// Function: FUN_10005ae0 at 10005ae0

void * __thiscall FUN_10005ae0(void *this,wchar_t *param_1)

{
  size_t sVar1;
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &local_19;
  local_8 = 0;
  FUN_10003400(this,'\0',0);
  sVar1 = wcslen(param_1);
  FUN_10003510(this,(undefined4 *)param_1,sVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10005b70 at 10005b70

void FUN_10005b70(int param_1)

{
  FUN_10005c80((int *)&DAT_1002480c,0x65,param_1,(int *)0x0);
  return;
}



// Function: FUN_10005ba0 at 10005ba0

undefined4 FUN_10005ba0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10009e00(&DAT_1002480c,0x10024140,param_1,(undefined4 *)&DAT_1001cbf4);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10009eb0(0x1002480c);
  }
  return 1;
}



// Function: DllCanUnloadNow at 10005bf0

HRESULT DllCanUnloadNow(void)

{
                    /* 0x5bf0  1  DllCanUnloadNow */
  return (uint)(DAT_10024814 != 0);
}



// Function: DllGetClassObject at 10005c10

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x5c10  2  DllGetClassObject */
  iVar1 = FUN_10009fd0(&DAT_1002480c,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: DllRegisterServer at 10005c40

void DllRegisterServer(void)

{
                    /* 0x5c40  3  DllRegisterServer */
  FUN_1000a1b0(&DAT_1002480c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10005c60

void DllUnregisterServer(void)

{
                    /* 0x5c60  4  DllUnregisterServer */
  FUN_1000b7e0(&DAT_1002480c,1,(void *)0x0);
  return;
}



// Function: FUN_10005c80 at 10005c80

/* WARNING: Removing unreachable block (ram,0x10005fbc) */
/* WARNING: Removing unreachable block (ram,0x10005ce1) */

void FUN_10005c80(int *param_1,ushort param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  HMODULE pHVar3;
  errno_t eVar4;
  int iVar5;
  int local_b48;
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
  int local_aac;
  int local_aa8;
  int local_aa4;
  undefined4 local_aa0;
  undefined4 local_a9c;
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
  uint local_24;
  undefined4 local_20;
  HMODULE local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018880;
  local_10 = ExceptionList;
  uVar2 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24c = ATL::CRegObject::vftable;
  local_24 = uVar2;
  FUN_10009b40(local_248);
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
        local_ac8 = FUN_10006600(local_ad4,local_ad8);
        local_ad0 = (-(uint)(local_ac8 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_1000e680(local_ac4);
      }
    }
  }
  local_254 = (**(code **)(*param_1 + 0x14))(&local_24c,uVar2);
  if (local_254 < 0) {
    local_24c = ATL::CRegObject::vftable;
    local_8 = 5;
    local_a94 = local_254;
    FUN_10006fc0((int)&local_24c);
    local_adc = local_248;
    local_8 = 6;
    FUN_10006980(local_adc);
    local_8 = 0xffffffff;
    FUN_1000e860(local_adc);
  }
  else {
    local_20 = 3;
    local_238[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_1c = DAT_10024930;
    local_250 = GetModuleFileNameW(DAT_10024930,local_230,0x104);
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
      FUN_10006fc0((int)&local_24c);
      local_ae4 = local_248;
      local_8 = 9;
      FUN_10006980(local_ae4);
      local_8 = 0xffffffff;
      FUN_1000e860(local_ae4);
    }
    else if (local_250 == 0x104) {
      local_a9c = 0x8007007a;
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
        local_ae8 = local_238[0];
        local_238[0] = (undefined4 *)*local_238[0];
        free(puVar1);
      }
      local_24c = ATL::CRegObject::vftable;
      local_8 = 10;
      FUN_10006fc0((int)&local_24c);
      local_aec = local_248;
      local_8 = 0xb;
      FUN_10006980(local_aec);
      local_8 = 0xffffffff;
      FUN_1000e860(local_aec);
    }
    else {
      local_260 = local_230;
      FUN_10006500(local_670,0x208,local_260);
      if ((local_1c == (HMODULE)0x0) ||
         (pHVar3 = GetModuleHandleW((LPCWSTR)0x0), local_1c == pHVar3)) {
        local_a88 = L'\"';
        local_af4 = lstrlenW(local_670);
        eVar4 = memcpy_s(local_a86,0x416,local_670,local_af4 * 2 + 2);
        if (eVar4 != 0) {
          local_aa0 = 0x80004005;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
            local_af8 = local_238[0];
            local_238[0] = (undefined4 *)*local_238[0];
            free(puVar1);
          }
          local_24c = ATL::CRegObject::vftable;
          local_8 = 0xc;
          FUN_10006fc0((int)&local_24c);
          local_afc = local_248;
          local_8 = 0xd;
          FUN_10006980(local_afc);
          local_8 = 0xffffffff;
          FUN_1000e860(local_afc);
          goto LAB_100064a4;
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
          local_b14 = FUN_10006600(L"Module",(int)&local_a88);
          local_b1c = (-(uint)(local_b14 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_1000e680(local_b10);
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
        iVar5 = FUN_10006600(L"Module",(int)local_670);
        local_8._0_1_ = 7;
        FUN_1000e680(local_b30);
        local_25c = (-(uint)(iVar5 != 0) & 0x7ff8fff2) + 0x8007000e;
      }
      if (local_25c < 0) {
        local_aa4 = local_25c;
        local_8 = CONCAT31(local_8._1_3_,1);
        while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
          local_238[0] = (undefined4 *)*local_238[0];
          free(puVar1);
        }
        local_8 = 0xffffffff;
        FUN_10006a80(&local_24c);
      }
      else {
        local_25c = FUN_10006b40(&local_24c,L"Module_Raw",(int)local_670);
        if (local_25c < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_aa8 = local_25c;
          FUN_1000e680((int *)local_238);
          local_8 = 0xffffffff;
          FUN_10006a80(&local_24c);
        }
        else {
          local_258 = L"REGISTRY";
          if (param_3 == 0) {
            local_b48 = FUN_10006f20(&local_24c,local_260,param_2,L"REGISTRY");
          }
          else {
            local_b48 = FUN_10006c00(&local_24c,local_260,param_2,L"REGISTRY");
          }
          local_254 = local_b48;
          local_aac = local_b48;
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_1000e680((int *)local_238);
          local_8 = 0xffffffff;
          FUN_10006a80(&local_24c);
        }
      }
    }
  }
LAB_100064a4:
  ExceptionList = local_10;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: AtlHresultFromLastError at 100064c0

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



// Function: FUN_10006500 at 10006500

void __cdecl FUN_10006500(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100065a0 at 100065a0

void __fastcall FUN_100065a0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100188b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10006980(param_1);
  local_8 = 0xffffffff;
  FUN_1000e860(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006600 at 10006600

undefined4 FUN_10006600(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100188f0;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_1000669c();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000668f at 1000668f

undefined4 Catch_1000668f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100066a3;
}



// Function: FUN_1000669c at 1000669c

void FUN_1000669c(void)

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
  uVar3 = FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x34);
  FUN_10006717();
  return;
}



// Function: Catch@1000670a at 1000670a

undefined4 Catch_1000670a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x1000671e;
}



// Function: FUN_10006717 at 10006717

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_10006717(void)

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
      FUN_10001c50(0x80004005);
      break;
    case 0xc:
      FUN_10001c50(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_10001c50(0x80070057);
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
      FUN_10001c50(0x80004005);
      break;
    case 0xc:
      FUN_10001c50(0x8007000e);
      break;
    case 0x16:
    case 0x22:
      FUN_10001c50(0x80070057);
    }
    iVar2 = FUN_1000e710(*(void **)(unaff_EBP + -0x78),(undefined4 *)(unaff_EBP + -0x2c),
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



// Function: FUN_10006980 at 10006980

undefined4 __fastcall FUN_10006980(int *param_1)

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
  FUN_1000e860(param_1);
  return 0;
}



// Function: FUN_10006a50 at 10006a50

undefined4 FUN_10006a50(void)

{
  return 0x80004001;
}



// Function: FUN_10006a60 at 10006a60

undefined4 FUN_10006a60(void)

{
  return 1;
}



// Function: FUN_10006a70 at 10006a70

undefined4 FUN_10006a70(void)

{
  return 0;
}



// Function: FUN_10006a80 at 10006a80

void __fastcall FUN_10006a80(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018923;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_10006980(param_1 + 1);
  local_8 = 1;
  FUN_10006980(param_1 + 1);
  local_8 = 0xffffffff;
  FUN_1000e860(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006b10 at 10006b10

undefined4 * __thiscall FUN_10006b10(void *this,uint param_1)

{
  FUN_10006a80((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006b40 at 10006b40

int FUN_10006b40(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018948;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    local_24 = (undefined4 *)0x0;
    local_8 = 0;
    iVar2 = FUN_10006600(param_2,param_3);
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



// Function: FUN_10006c00 at 10006c00

undefined4 FUN_10006c00(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018978;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = (undefined4 *)0x0;
  local_8 = 0;
  uVar2 = FUN_10006ca0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (local_24 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_24;
    free(local_24);
    local_24 = puVar1;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10006ca0 at 10006ca0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10006ca0(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  undefined4 *_Memory;
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  uint uStack_24a8;
  undefined1 *local_44c;
  undefined1 auStack_448 [1028];
  uint local_44;
  undefined4 *local_40;
  undefined4 local_38;
  DWORD local_30;
  undefined4 local_2c;
  HMODULE local_24;
  HGLOBAL local_20;
  LPCWSTR local_1c;
  undefined4 uStack_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100189b3;
  local_10 = ExceptionList;
  uStack_18 = 0x10006cbc;
  uStack_24a8 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_24a8;
  ExceptionList = &local_10;
  local_38 = 3;
  local_40 = (undefined4 *)0x0;
  local_2c = 0;
  local_44c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_1c = param_1;
  local_44 = uStack_24a8;
  local_24 = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_24 == (HMODULE)0x0) {
    ATL::AtlHresultFromLastError();
  }
  else {
    hResInfo = FindResourceW(local_24,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      ATL::AtlHresultFromLastError();
    }
    else {
      pvVar1 = LoadResource(local_24,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        ATL::AtlHresultFromLastError();
      }
      else {
        local_30 = SizeofResource(local_24,hResInfo);
        local_20 = pvVar1;
        if (local_30 <= local_30 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000e970(&local_44c,local_30 + 1);
          FUN_10006df9();
          return;
        }
      }
    }
  }
  if (local_24 != (HMODULE)0x0) {
    FreeLibrary(local_24);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_44c != auStack_448) {
    FUN_1000ebc0(&local_44c);
  }
  local_8 = 0xffffffff;
  while (_Memory = local_40, local_40 != (undefined4 *)0x0) {
    local_40 = (undefined4 *)*local_40;
    free(_Memory);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_44 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10006dec at 10006dec

undefined4 Catch_10006dec(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10006e00;
}



// Function: FUN_10006df9 at 10006df9

void FUN_10006df9(void)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  if (*(int *)(unaff_EBP - 0x448) == 0) {
    *(undefined4 *)(unaff_EBP - 0x454) = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x46c) = *(undefined4 *)(unaff_EBP - 0x448);
    iVar1 = MultiByteToWideChar(3,0,*(LPCSTR *)(unaff_EBP - 0x1c),*(int *)(unaff_EBP - 0x2c),
                                *(LPWSTR *)(unaff_EBP - 0x46c),*(int *)(unaff_EBP - 0x2c));
    *(int *)(unaff_EBP - 0x44c) = iVar1;
    if (*(int *)(unaff_EBP - 0x44c) == 0) {
      lVar2 = ATL::AtlHresultFromLastError();
      *(long *)(unaff_EBP - 0x454) = lVar2;
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x448) + *(int *)(unaff_EBP - 0x44c) * 2) = 0;
      *(undefined4 *)(unaff_EBP - 0x470) = *(undefined4 *)(unaff_EBP - 0x448);
      uVar3 = FUN_10006fe0((void *)(unaff_EBP - 0x28),*(LPCWSTR *)(unaff_EBP - 0x470),
                           *(int *)(unaff_EBP + 0x14));
      *(undefined4 *)(unaff_EBP - 0x454) = uVar3;
    }
  }
  if (*(int *)(unaff_EBP - 0x20) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x20));
  }
  *(undefined4 *)(unaff_EBP - 0x45c) = *(undefined4 *)(unaff_EBP - 0x454);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x448) != unaff_EBP - 0x444) {
    FUN_1000ebc0((undefined4 *)(unaff_EBP - 0x448));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  while (*(int *)(unaff_EBP - 0x3c) != 0) {
    *(undefined4 *)(unaff_EBP - 0x2490) = *(undefined4 *)(unaff_EBP - 0x3c);
    *(undefined4 *)(unaff_EBP - 0x3c) = **(undefined4 **)(unaff_EBP - 0x3c);
    free(*(void **)(unaff_EBP - 0x2490));
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10006f18;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x40) ^ unaff_EBP);
  return;
}



// Function: FUN_10006f20 at 10006f20

undefined4 FUN_10006f20(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100189e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = (undefined4 *)0x0;
  local_8 = 0;
  uVar2 = FUN_10006ca0(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  while (local_24 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_24;
    free(local_24);
    local_24 = puVar1;
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10006fc0 at 10006fc0

undefined4 FUN_10006fc0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10006980((int *)(param_1 + 4));
  return uVar1;
}



// Function: FUN_10006fe0 at 10006fe0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006fe0(void *this,LPCWSTR param_1,int param_2)

{
  undefined4 uVar1;
  HKEY pHVar2;
  WCHAR local_2014 [4098];
  uint local_10;
  int local_c;
  LPVOID local_8;
  
  local_10 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_c = 0;
  local_8 = (LPVOID)0x0;
  local_c = FUN_10007500(this,param_1,&local_8);
  if (-1 < local_c) {
    *(LPVOID *)this = local_8;
    while( true ) {
                    /* WARNING: Load size is inaccurate */
      if ((**this == 0) || (local_c = FUN_10007280(this,local_2014), local_c < 0))
      goto LAB_10007174;
      pHVar2 = (HKEY)FUN_100071a0(local_2014);
      if (pHVar2 == (HKEY)0x0) break;
      local_c = FUN_10007280(this,local_2014);
      if (local_c < 0) goto LAB_10007174;
      if (local_2014[0] != L'{') {
        local_c = -0x7ffdfff7;
        goto LAB_10007174;
      }
      if (param_2 == 0) {
        local_c = FUN_10008080(this,local_2014,pHVar2,0,0);
        if (local_c < 0) goto LAB_10007174;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar1 = *this;
        local_c = FUN_10008080(this,local_2014,pHVar2,param_2,0);
        if (local_c < 0) {
          *(undefined4 *)this = uVar1;
          FUN_10008080(this,local_2014,pHVar2,0,0);
          goto LAB_10007174;
        }
      }
      FUN_100071f0((undefined4 *)this);
    }
    local_c = -0x7ffdfff7;
LAB_10007174:
    CoTaskMemFree(local_8);
  }
  __security_check_cookie(local_10 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100071a0 at 100071a0

undefined4 __cdecl FUN_100071a0(LPCWSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1001ccd0)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_1001ccd4 + local_8 * 8);
}



// Function: FUN_100071f0 at 100071f0

void __fastcall FUN_100071f0(undefined4 *param_1)

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



// Function: FUN_10007280 at 10007280

undefined4 __thiscall FUN_10007280(void *this,undefined2 *param_1)

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
  FUN_100071f0((undefined4 *)this);
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



// Function: FUN_10007500 at 10007500

void __thiscall FUN_10007500(void *this,LPCWSTR param_1,undefined4 *param_2)

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
  undefined4 local_94;
  rsize_t local_90;
  LPCWSTR local_8c;
  wchar_t local_88 [32];
  uint local_48;
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
  puStack_c = &LAB_10018a18;
  local_10 = ExceptionList;
  local_48 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    local_18 = lstrlenW(param_1);
    local_18 = local_18 << 1;
    FUN_10007c10(&local_28,local_18);
    local_8 = 0;
    if (local_20 == (LPVOID)0x0) {
      local_94 = 0x8007000e;
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
        local_31 = DAT_10024750;
        local_30 = 0;
      }
      if (local_30 < 0) {
        local_98 = local_30;
        local_8 = 0xffffffff;
        CoTaskMemFree(local_20);
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
                iVar4 = FUN_10007f90(&local_28,local_3c);
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
                  iVar4 = FUN_10007d10(&local_28,local_dc,1);
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
              iVar4 = FUN_10007f90(&local_28,local_38);
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
              iVar4 = FUN_10007d10(&local_28,local_10c,1);
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
                FUN_10001c50(0x80004005);
                break;
              case 0xc:
                FUN_10001c50(0x8007000e);
                break;
              case 0x16:
              case 0x22:
                FUN_10001c50(0x80070057);
              }
              local_11c = local_118;
              local_144 = local_88;
              local_140 = *(int *)((int)this + 4);
              local_13c = (void *)(local_140 + 4);
              local_128 = FUN_1000eb50(local_13c,&local_144);
              if (local_128 == -1) {
                local_124 = (LPCWSTR)0x0;
              }
              else {
                puVar5 = (undefined4 *)FUN_1000e8e0(local_13c,local_128);
                local_124 = (LPCWSTR)*puVar5;
              }
              local_44 = local_124;
              if (local_124 == (LPCWSTR)0x0) {
                local_30 = -0x7ffdfff7;
                break;
              }
              iVar4 = FUN_10007f90(&local_28,local_124);
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
            iVar4 = FUN_10007d10(&local_28,*this,1);
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
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_48 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007c10 at 10007c10

undefined4 * __thiscall FUN_10007c10(void *this,int param_1)

{
  LPVOID pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = FUN_10007c70(*(uint *)((int)this + 4),2);
  *(LPVOID *)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined2 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_10007c70 at 10007c70

/* WARNING: Removing unreachable block (ram,0x10007ca0) */

LPVOID __cdecl FUN_10007c70(uint param_1,uint param_2)

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



// Function: FUN_10007cf0 at 10007cf0

void __fastcall FUN_10007cf0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10007d10 at 10007d10

undefined4 __thiscall FUN_10007d10(void *this,void *param_1,int param_2)

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
      pvVar3 = FUN_10007ef0(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),2);
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
        FUN_10001c50(0x80004005);
        break;
      case 0xc:
        FUN_10001c50(0x8007000e);
        break;
      case 0x16:
      case 0x22:
        FUN_10001c50(0x80070057);
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



// Function: FUN_10007ef0 at 10007ef0

/* WARNING: Removing unreachable block (ram,0x10007f20) */

LPVOID __cdecl FUN_10007ef0(LPVOID param_1,uint param_2,uint param_3)

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



// Function: FUN_10007f90 at 10007f90

undefined4 __thiscall FUN_10007f90(void *this,LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018a48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == (LPCWSTR)0x0) {
    local_2c = 0;
  }
  else {
    local_24 = (undefined4 *)0x0;
    local_8 = 0;
    if (param_1 == (LPCWSTR)0x0) {
      local_2c = 0;
      local_8 = 0xffffffff;
      while (local_24 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*local_24;
        free(local_24);
        local_24 = puVar1;
      }
    }
    else {
      iVar2 = lstrlenW(param_1);
      local_2c = FUN_10007d10(this,param_1,iVar2);
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



// Function: FUN_10008080 at 10008080

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008080(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  LPCWSTR pWVar3;
  errno_t eVar4;
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
  wchar_t local_238 [260];
  uint local_30;
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
  
  puStack_c = &LAB_10018aa4;
  local_10 = ExceptionList;
  local_30 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  local_8 = 0;
  local_14 = 1;
  local_28 = param_4;
  local_2c = 0;
  local_2c = FUN_10007280(this,param_1);
  if (-1 < local_2c) {
LAB_10008120:
    if (*param_1 == L'}') goto LAB_10008a7a;
    local_14 = 1;
    iVar2 = lstrcmpiW(param_1,L"Delete");
    local_23c = (uint)(iVar2 == 0);
    iVar2 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar2 == 0) || (local_23c != 0)) {
      local_2c = FUN_10007280(this,param_1);
      if (local_2c < 0) goto LAB_10008a7a;
      if (param_3 == 0) goto LAB_100083b7;
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
      if (local_22cc == (LPCWSTR)0x0) {
        for (local_22d8 = 0; local_22d8 < 0xc; local_22d8 = local_22d8 + 1) {
          iVar2 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_1001cc44)[local_22d8]);
          if (iVar2 == 0) {
            bVar1 = false;
            goto LAB_100082cc;
          }
        }
        bVar1 = true;
LAB_100082cc:
        if (bVar1) {
          local_248 = param_2;
          local_244 = 0;
          local_240 = 0;
          FUN_10008f00(&local_248,param_1);
          local_248 = (HKEY)0x0;
          local_244 = 0;
          local_240 = 0;
        }
        if (local_23c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_248);
          goto LAB_100083b7;
        }
        local_2c = FUN_10007280(this,param_1);
        if (local_2c < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_248);
        }
        else {
          local_2c = FUN_10009aa0(this,param_1);
          if (-1 < local_2c) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::CRegKey::Close((CRegKey *)&local_248);
            goto LAB_10008a17;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_248);
        }
        goto LAB_10008a7a;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_248);
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_20);
      goto LAB_10008a98;
    }
LAB_100083b7:
    iVar2 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar2 == 0) {
      local_14 = 0;
      local_2c = FUN_10007280(this,param_1);
      if (local_2c < 0) goto LAB_10008a7a;
    }
    iVar2 = lstrcmpiW(param_1,L"Val");
    if (iVar2 == 0) {
      local_2c = FUN_10007280(this,local_2248);
      if ((local_2c < 0) || (local_2c = FUN_10007280(this,param_1), local_2c < 0))
      goto LAB_10008a7a;
      if (*param_1 != L'=') {
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        goto LAB_10008a98;
      }
      if (param_3 != 0) {
        local_8._0_1_ = 2;
        local_2254 = param_2;
        local_2250 = 0;
        local_224c = 0;
        local_2c = FUN_10009150(this,&local_2254,local_2248,param_1);
        local_2254 = (HKEY)0x0;
        local_2250 = 0;
        local_224c = 0;
        if (-1 < local_2c) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2254);
          goto LAB_10008a17;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2254);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        goto LAB_10008a98;
      }
      if ((param_4 == 0) && (local_14 != 0)) {
        local_2260 = (HKEY)0x0;
        local_225c = 0;
        local_2258 = 0;
        local_8._0_1_ = 3;
        local_24 = FUN_10001950(&local_2260,param_2,(LPCWSTR)0x0,0x20006);
        if (local_24 != 0) {
          local_2c = _HRESULT_FROM_WIN32(local_24);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2260);
          goto LAB_10008a7a;
        }
        local_24 = RegDeleteValueW(local_2260,local_2248);
        if ((local_24 != 0) && (local_24 != 2)) {
          local_2c = _HRESULT_FROM_WIN32(local_24);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2260);
          goto LAB_10008a7a;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2260);
      }
      local_2c = FUN_10009aa0(this,param_1);
joined_r0x1000864e:
      if (local_2c < 0) goto LAB_10008a7a;
      goto LAB_10008120;
    }
    pWVar3 = FUN_10009100(param_1,L'\\');
    if (pWVar3 != (LPCWSTR)0x0) {
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_20);
      goto LAB_10008a98;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_24 = FUN_10001950(&local_20,param_2,param_1,0x20019);
      }
      else {
        local_24 = 2;
      }
      if (local_24 != 0) {
        param_4 = 1;
      }
      eVar4 = wcsncpy_s(local_238,0x104,param_1,0xffffffff);
      ATL::AtlCrtErrorCheck(eVar4);
      local_2c = FUN_10007280(this,param_1);
      if (((local_2c < 0) || (local_2c = FUN_10009aa0(this,param_1), local_2c < 0)) ||
         (((*param_1 == L'{' && (iVar2 = lstrlenW(param_1), iVar2 == 1)) &&
          (((local_2c = FUN_10008080(this,param_1,local_20,0,param_4), local_2c < 0 &&
            (param_4 == 0)) || (local_2c = FUN_10007280(this,param_1), local_2c < 0))))))
      goto LAB_10008a7a;
      param_4 = local_28;
      if (local_24 == 2) goto LAB_10008120;
      if (local_24 != 0) {
        if (local_28 == 0) goto LAB_10008894;
        goto LAB_10008120;
      }
      if ((local_28 != 0) && (bVar1 = FUN_10009a50(local_20), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar2 = FUN_10009a00(local_238);
        if ((iVar2 != 0) && (local_14 != 0)) {
          FUN_10008f00(&local_20,local_238);
        }
        goto LAB_10008120;
      }
      bVar1 = FUN_10009a50(local_20);
      local_2264 = CONCAT31(extraout_var_00,bVar1);
      local_24 = ATL::CRegKey::Close((CRegKey *)&local_20);
      if (local_24 != 0) {
        _HRESULT_FROM_WIN32(local_24);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        goto LAB_10008a98;
      }
      if ((local_14 != 0) && (local_2264 == 0)) {
        local_2270 = 0;
        local_226c = 0;
        local_2268 = 0;
        local_8._0_1_ = 4;
        FUN_10008bb0(&local_2270,param_2);
        local_24 = FUN_10008bf0(&local_2270,local_238);
        local_2270 = 0;
        local_226c = 0;
        local_2268 = 0;
        if (local_24 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2270);
          goto LAB_10008a17;
        }
        local_2c = _HRESULT_FROM_WIN32(local_24);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_2270);
        goto LAB_10008a7a;
      }
    }
    else {
      local_24 = FUN_10001950(&local_20,param_2,param_1,0x2001f);
      if (((local_24 != 0) &&
          (local_24 = FUN_10001950(&local_20,param_2,param_1,0x20019), local_24 != 0)) &&
         (local_24 = FUN_10008d80(&local_20,param_2,param_1,(LPWSTR)0x0,0,0x2001f,
                                  (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_24 != 0)) {
        _HRESULT_FROM_WIN32(local_24);
        local_8 = 0xffffffff;
        ATL::CRegKey::Close((CRegKey *)&local_20);
        goto LAB_10008a98;
      }
      local_2c = FUN_10007280(this,param_1);
      if ((local_2c < 0) ||
         ((*param_1 == L'=' &&
          (local_2c = FUN_10009150(this,&local_20,(LPCWSTR)0x0,param_1), local_2c < 0))))
      goto LAB_10008a7a;
    }
LAB_10008a17:
    if (((param_3 != 0) && (*param_1 == L'{')) && (iVar2 = lstrlenW(param_1), iVar2 == 1)) {
      local_2c = FUN_10008080(this,param_1,local_20,param_3,0);
      if (-1 < local_2c) {
        local_2c = FUN_10007280(this,param_1);
        goto joined_r0x1000864e;
      }
      goto LAB_10008a7a;
    }
    goto LAB_10008120;
  }
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_20);
LAB_10008a98:
  ExceptionList = local_10;
  __security_check_cookie(local_30 ^ (uint)&stack0xfffffffc);
  return;
LAB_10008894:
  local_2c = _HRESULT_FROM_WIN32(local_24);
LAB_10008a7a:
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_20);
  goto LAB_10008a98;
}



// Function: AtlCrtErrorCheck at 10008ac0

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
    FUN_10001c50(0x80004005);
    break;
  case 0xc:
    FUN_10001c50(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10001c50(0x80070057);
  }
  return param_1;
}



// Function: _HRESULT_FROM_WIN32 at 10008b70

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



// Function: FUN_10008bb0 at 10008bb0

void __thiscall FUN_10008bb0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10008bf0 at 10008bf0

void __thiscall FUN_10008bf0(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10024770 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1002476c = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10024770 = '\x01';
    }
    if (DAT_1002476c == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1002476c)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_10008ca0(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10008ca0 at 10008ca0

LSTATUS __thiscall FUN_10008ca0(void *this,HKEY param_1,LPCWSTR param_2)

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



// Function: Close at 10008d30

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



// Function: FUN_10008d80 at 10008d80

LSTATUS __thiscall
FUN_10008d80(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
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
    goto LAB_10008e8a;
  }
  piVar1 = *(int **)((int)this + 8);
  if (*piVar1 == 0) {
    if (piVar1[1] != 0) {
      local_2c = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,
                                 &local_10);
      goto LAB_10008e8a;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      local_2c = 1;
      goto LAB_10008e8a;
    }
    pFVar2 = GetProcAddress(hModule,"RegCreateKeyTransactedW");
    if (pFVar2 != (FARPROC)0x0) {
      local_2c = (*pFVar2)(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,&local_10,
                           *piVar1,0);
      goto LAB_10008e8a;
    }
  }
  local_2c = 1;
LAB_10008e8a:
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
    *(uint *)((int)this + 4) = param_5 & 0x300;
  }
  return local_c;
}



// Function: FUN_10008f00 at 10008f00

void __thiscall FUN_10008f00(void *this,LPCWSTR param_1)

{
  LSTATUS LVar1;
  WCHAR local_230 [256];
  uint local_30;
  LSTATUS local_2c;
  HKEY local_28;
  undefined4 local_24;
  undefined4 local_20;
  _FILETIME local_1c;
  DWORD local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018ad8;
  local_10 = ExceptionList;
  local_30 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = (HKEY)0x0;
  local_24 = 0;
  local_20 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  local_2c = FUN_10001950(&local_28,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (local_2c == 0) {
    do {
      local_14 = 0x100;
      LVar1 = RegEnumKeyExW(local_28,0,local_230,&local_14,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_1c);
      if (LVar1 != 0) {
        if (local_28 != (HKEY)0x0) {
          RegCloseKey(local_28);
          local_28 = (HKEY)0x0;
        }
        local_24 = 0;
        FUN_10008bf0(this,param_1);
        local_8 = 0xffffffff;
        if (local_28 != (HKEY)0x0) {
          RegCloseKey(local_28);
          local_28 = (HKEY)0x0;
        }
        goto LAB_100090db;
      }
      local_2c = FUN_10008f00(&local_28,local_230);
    } while (local_2c == 0);
    local_8 = 0xffffffff;
    if (local_28 != (HKEY)0x0) {
      RegCloseKey(local_28);
      local_28 = (HKEY)0x0;
    }
  }
  else {
    local_8 = 0xffffffff;
    if (local_28 != (HKEY)0x0) {
      RegCloseKey(local_28);
      local_28 = (HKEY)0x0;
    }
  }
LAB_100090db:
  local_24 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_30 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009100 at 10009100

LPCWSTR __cdecl FUN_10009100(LPWSTR param_1,WCHAR param_2)

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



// Function: FUN_10009150 at 10009150

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10009150(void *this,undefined4 *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  undefined4 *_Memory;
  int iVar1;
  LPWSTR pWVar2;
  uint uVar3;
  uint uStack_22fc;
  undefined4 auStack_22d4 [6];
  uint local_22bc;
  undefined4 auStack_2274 [67];
  uint uStack_2168;
  uint uStack_2164;
  undefined4 uStack_2160;
  undefined4 *puStack_215c;
  undefined4 uStack_2154;
  WCHAR *pWStack_2150;
  uint local_2138;
  undefined4 local_2134 [66];
  WCHAR local_202c [4098];
  uint local_28;
  int local_24;
  ushort local_20 [2];
  ulong local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018b21;
  local_10 = ExceptionList;
  uStack_22fc = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_22fc;
  ExceptionList = &local_10;
  local_20[0] = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = uStack_22fc;
  local_24 = FUN_10007280(this,local_202c);
  if ((-1 < local_24) && (iVar1 = FUN_100097f0(local_202c,local_20), iVar1 != 0)) {
                    /* WARNING: Load size is inaccurate */
    while (iVar1 = FUN_100099a0(**this), iVar1 != 0) {
                    /* WARNING: Load size is inaccurate */
      pWVar2 = CharNextW(*this);
      *(LPWSTR *)this = pWVar2;
    }
    local_24 = FUN_10007280(this,local_202c);
    if (-1 < local_24) {
      if (local_20[0] < 0x14) {
        if (local_20[0] == 0x13) {
          uStack_2154 = 3;
          puStack_215c = (undefined4 *)0x0;
          local_8 = 3;
          pWStack_2150 = local_202c;
          Ordinal_277(pWStack_2150,0,0,&uStack_2160);
          auStack_22d4[0] = uStack_2160;
          local_1c = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)auStack_22d4,4);
          local_8 = 0xffffffff;
          while (_Memory = puStack_215c, puStack_215c != (undefined4 *)0x0) {
            puStack_215c = (undefined4 *)*puStack_215c;
            free(_Memory);
          }
        }
        else if (local_20[0] == 8) {
          local_22bc = (uint)(&stack0x00000000 != (undefined1 *)0x202c);
          if (local_22bc == 0) {
            local_1c = 0xd;
          }
          else {
            iVar1 = lstrlenW(local_202c);
            local_1c = RegSetValueExW((HKEY)*param_1,param_2,0,1,(BYTE *)local_202c,iVar1 * 2 + 2);
          }
        }
        else if (local_20[0] == 0x11) {
          uStack_2168 = lstrlenW(local_202c);
          if ((uStack_2168 & 1) == 0) {
            uStack_2164 = (int)uStack_2168 / 2;
            auStack_2274[0] = 0;
            local_8 = 5;
            uVar3 = FUN_1000ee40(uStack_2164,1);
            FUN_1000ec60(auStack_2274,uVar3);
            FUN_100095c8();
            return;
          }
          goto LAB_10009740;
        }
      }
      else if (local_20[0] == 0x4008) {
        iVar1 = lstrlenW(local_202c);
        local_2138 = iVar1 + 2;
        local_2134[0] = 0;
        local_8 = 1;
        uVar3 = FUN_1000ee40(local_2138,2);
        FUN_1000ebf0(local_2134,uVar3);
        FUN_1000933c();
        return;
      }
      if (local_1c == 0) {
        local_24 = FUN_10007280(this,param_3);
      }
      else {
        local_18 = 0x204;
        _HRESULT_FROM_WIN32(local_1c);
      }
    }
  }
LAB_10009740:
  ExceptionList = local_10;
  __security_check_cookie(local_28 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000932f at 1000932f

undefined4 Catch_1000932f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009343;
}



// Function: FUN_1000933c at 1000933c

void FUN_1000933c(void)

{
  LPWSTR pWVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x2130) == 0) {
    *(undefined4 *)(unaff_EBP - 0x18) = 0xe;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x2138) = *(undefined4 *)(unaff_EBP - 0x2130);
    *(uint *)(unaff_EBP - 0x213c) = unaff_EBP - 0x2028;
    *(undefined4 *)(unaff_EBP - 0x2134) = 0;
    while (**(short **)(unaff_EBP - 0x213c) != 0) {
      pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP - 0x213c));
      *(LPWSTR *)(unaff_EBP - 0x2140) = pWVar1;
      if ((**(short **)(unaff_EBP - 0x213c) == 0x5c) && (**(short **)(unaff_EBP - 0x2140) == 0x30))
      {
        **(undefined2 **)(unaff_EBP - 0x2138) = 0;
        *(int *)(unaff_EBP - 0x2138) = *(int *)(unaff_EBP - 0x2138) + 2;
        pWVar1 = CharNextW(*(LPCWSTR *)(unaff_EBP - 0x2140));
        *(LPWSTR *)(unaff_EBP - 0x213c) = pWVar1;
      }
      else {
        **(undefined2 **)(unaff_EBP - 0x2138) = **(undefined2 **)(unaff_EBP - 0x213c);
        *(int *)(unaff_EBP - 0x2138) = *(int *)(unaff_EBP - 0x2138) + 2;
        *(int *)(unaff_EBP - 0x213c) = *(int *)(unaff_EBP - 0x213c) + 2;
      }
      *(int *)(unaff_EBP - 0x2134) = *(int *)(unaff_EBP - 0x2134) + 1;
    }
    **(undefined2 **)(unaff_EBP - 0x2138) = 0;
    *(int *)(unaff_EBP - 0x2138) = *(int *)(unaff_EBP - 0x2138) + 2;
    **(undefined2 **)(unaff_EBP - 0x2138) = 0;
    *(undefined4 *)(unaff_EBP - 0x22bc) = *(undefined4 *)(unaff_EBP - 0x2130);
    LVar2 = FUN_10009760(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                         *(LPCWSTR *)(unaff_EBP - 0x22bc));
    *(LSTATUS *)(unaff_EBP - 0x18) = LVar2;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2130) != unaff_EBP - 0x212c) {
    FUN_1000ec30((undefined4 *)(unaff_EBP - 0x2130));
  }
  if (*(int *)(unaff_EBP - 0x18) == 0) {
    uVar3 = FUN_10007280(*(void **)(unaff_EBP - 0x22e0),*(undefined2 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x20) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x14) = 0x204;
    _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP - 0x18));
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10009758;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x24) ^ unaff_EBP);
  return;
}



// Function: Catch@100095bb at 100095bb

undefined4 Catch_100095bb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x100095cf;
}



// Function: FUN_100095c8 at 100095c8

void FUN_100095c8(void)

{
  uint uVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  if (*(int *)(unaff_EBP - 0x2270) == 0) {
    *(undefined4 *)(unaff_EBP - 0x2278) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2270) != unaff_EBP - 0x226c) {
      FUN_1000eca0((undefined4 *)(unaff_EBP - 0x2270));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2270),0,*(size_t *)(unaff_EBP - 0x2160));
    *(undefined4 *)(unaff_EBP - 0x2274) = 0;
    while (*(int *)(unaff_EBP - 0x2274) < *(int *)(unaff_EBP - 0x2164)) {
      *(int *)(unaff_EBP - 0x22e8) = *(int *)(unaff_EBP - 0x2274) / 2 + *(int *)(unaff_EBP - 0x2270)
      ;
      uVar1 = FUN_10009900(*(ushort *)((unaff_EBP - 0x2028) + *(int *)(unaff_EBP - 0x2274) * 2));
      **(byte **)(unaff_EBP - 0x22e8) =
           **(byte **)(unaff_EBP - 0x22e8) |
           (byte)((uVar1 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x2274) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x2274) = *(int *)(unaff_EBP - 0x2274) + 1;
    }
    *(undefined4 *)(unaff_EBP - 0x22d8) = *(undefined4 *)(unaff_EBP - 0x2270);
    *(undefined4 *)(unaff_EBP - 0x22dc) = **(undefined4 **)(unaff_EBP + 8);
    LVar2 = RegSetValueExW(*(HKEY *)(unaff_EBP - 0x22dc),*(LPCWSTR *)(unaff_EBP + 0xc),0,3,
                           *(BYTE **)(unaff_EBP - 0x22d8),*(DWORD *)(unaff_EBP - 0x2160));
    *(LSTATUS *)(unaff_EBP - 0x18) = LVar2;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2270) != unaff_EBP - 0x226c) {
      FUN_1000eca0((undefined4 *)(unaff_EBP - 0x2270));
    }
    if (*(int *)(unaff_EBP - 0x18) == 0) {
      uVar3 = FUN_10007280(*(void **)(unaff_EBP - 0x22e0),*(undefined2 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x20) = uVar3;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x14) = 0x204;
      _HRESULT_FROM_WIN32(*(ulong *)(unaff_EBP - 0x18));
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10009758;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x24) ^ unaff_EBP);
  return;
}



// Function: FUN_10009760 at 10009760

LSTATUS __thiscall FUN_10009760(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_100097f0 at 100097f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100097f0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018b5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_10024794 & 1) == 0) {
    DAT_10024794 = DAT_10024794 | 1;
    _DAT_10024774 = &DAT_1001cbf0;
    _DAT_10024778 = 8;
    _DAT_1002477c = &DAT_1001cbec;
    _DAT_10024780 = 0x4008;
    _DAT_10024784 = &DAT_1001cbe8;
    _DAT_10024788 = 0x13;
    _DAT_1002478c = &DAT_1001cbe4;
    _DAT_10024790 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,*(LPCWSTR *)(&DAT_10024774 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_10024778 + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_10009900 at 10009900

uint __cdecl FUN_10009900(ushort param_1)

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



// Function: FUN_100099a0 at 100099a0

undefined4 FUN_100099a0(undefined2 param_1)

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



// Function: FUN_10009a00 at 10009a00

undefined4 FUN_10009a00(LPCWSTR param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xb < local_8) {
      return 1;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_1001cc44)[local_8]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_10009a50 at 10009a50

bool FUN_10009a50(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10009aa0 at 10009aa0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10009aa0(void *this,short *param_1)

{
  undefined2 local_200c [4096];
  uint local_c;
  int local_8;
  
  local_8 = 0x10009aad;
  local_c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (local_8 = FUN_10007280(this,param_1), -1 < local_8)) {
    FUN_100071f0((undefined4 *)this);
    local_8 = FUN_10007280(this,local_200c);
    if (-1 < local_8) {
      local_8 = FUN_10007280(this,param_1);
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009b40 at 10009b40

undefined4 * __fastcall FUN_10009b40(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10009bb0 at 10009bb0

undefined4 FUN_10009bb0(void)

{
  return 0;
}



// Function: FUN_10009bc0 at 10009bc0

undefined4 FUN_10009bc0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10018bce;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000c700(puVar1 + 1);
      *puVar1 = ATL::CComClassFactory::vftable;
      *puVar1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10009c88();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10009c7b at 10009c7b

undefined4 Catch_10009c7b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009c8f;
}



// Function: FUN_10009c88 at 10009c88

undefined4 FUN_10009c88(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x24) = *(undefined4 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x14) + 8;
    DVar1 = FUN_10009d60(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x38));
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



// Function: FUN_10009d60 at 10009d60

DWORD __fastcall FUN_10009d60(LPCRITICAL_SECTION param_1)

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



// Function: FUN_10009dc0 at 10009dc0

undefined4 FUN_10009dc0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_1000c2f0(0,param_2,param_3);
  }
  else {
    local_8 = FUN_1000c4e0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10009e00 at 10009e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_10009e00(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_c;
  int *local_8;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_10024758 = *param_3;
    _DAT_1002475c = param_3[1];
    _DAT_10024760 = param_3[2];
    _DAT_10024764 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_8 = *(int **)((int)this + 0x2c); *local_8 != 0; local_8 = local_8 + 9) {
      (*(code *)local_8[8])(1);
    }
  }
  for (local_c = DAT_1002496c; local_c < DAT_10024970; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10009eb0 at 10009eb0

void __fastcall FUN_10009eb0(int param_1)

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
  for (local_c = DAT_1002496c; local_c < DAT_10024970; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x20))(0);
    }
  }
  FUN_10009f50(param_1);
  return;
}



// Function: FUN_10009f50 at 10009f50

void __fastcall FUN_10009f50(int param_1)

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
      FUN_1000bd90(local_18);
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



// Function: FUN_10009fd0 at 10009fd0

/* WARNING: Removing unreachable block (ram,0x1000a0cf) */
/* WARNING: Removing unreachable block (ram,0x1000a0e8) */

int __thiscall FUN_10009fd0(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  LPCRITICAL_SECTION local_20;
  undefined1 local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018bf8;
  local_10 = ExceptionList;
  uVar3 = DAT_10024664 ^ (uint)&stack0xfffffffc;
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
            FUN_1000ed90(&local_20,&DAT_10024974,'\0');
            local_8 = 0;
            EnterCriticalSection(local_20);
            local_1c = 1;
            local_14 = 0;
            if (local_18[4] == 0) {
              local_14 = (*(code *)local_18[2])(local_18[3],&PTR_1001cf58,local_18 + 4);
            }
            local_8 = 0xffffffff;
            FUN_1000ee00(&local_20);
          }
          if (local_18[4] != 0) {
            local_14 = (*(code *)**(undefined4 **)local_18[4])(local_18[4],param_2,param_3,uVar3);
          }
          break;
        }
      }
    }
  }
  if ((*param_3 == 0) && (local_14 == 0)) {
    local_14 = FUN_1000bb90((int *)&DAT_10024964,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000a1b0 at 1000a1b0

int __thiscall FUN_1000a1b0(void *this,int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  int local_210;
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
        local_c = FUN_1000a2b0((GUID *)*local_8,piVar2,iVar1);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_210 = FUN_1000ad10(0x10024964,param_1,param_2);
    if ((-1 < local_210) && (DAT_10024748 != (code *)0x0)) {
      local_210 = (*DAT_10024748)(DAT_10024930);
    }
    local_c = local_210;
  }
  return local_c;
}



// Function: FUN_1000a2b0 at 1000a2b0

/* WARNING: Removing unreachable block (ram,0x1000a314) */

void FUN_1000a2b0(GUID *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  errno_t eVar4;
  wchar_t local_1e8 [128];
  DWORD local_e8;
  HKEY local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  LSTATUS local_d8;
  HKEY local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  OLECHAR local_c8 [64];
  OLECHAR *local_48;
  undefined4 *local_44;
  undefined4 local_3c;
  int *local_30;
  int *local_2c;
  HRESULT local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018c76;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_30 = (int *)0x0;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
    local_8 = 0xffffffff;
    puStack_c = &LAB_10018c76;
    local_30 = (int *)0x0;
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
    ExceptionList = &local_10;
    if (bVar3) {
      local_8 = 0xffffffff;
      FUN_1000ea00((int *)&local_30);
    }
    else {
      local_28 = CoCreateInstance((IID *)&DAT_1001ed78,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001cfd4,
                                  &local_30);
      if (local_28 < 0) {
        local_8 = 0xffffffff;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
      else {
        local_28 = 0;
        for (local_2c = param_2; *local_2c != 0; local_2c = local_2c + 2) {
          puVar2 = (undefined4 *)local_2c[1];
          local_24 = *puVar2;
          local_20 = puVar2[1];
          local_1c = puVar2[2];
          local_18 = puVar2[3];
          if (param_3 == 0) {
            if (*local_2c == 1) {
              (**(code **)(*local_30 + 0x18))(local_30,param_1,1,&local_24);
            }
            else {
              (**(code **)(*local_30 + 0x20))(local_30,param_1,1,&local_24);
            }
          }
          else {
            if (*local_2c == 1) {
              local_28 = (**(code **)(*local_30 + 0x14))(local_30,param_1,1,&local_24);
            }
            else {
              local_28 = (**(code **)(*local_30 + 0x1c))(local_30,param_1,1,&local_24);
            }
            if (local_28 < 0) {
              local_8 = 0xffffffff;
              if (local_30 != (int *)0x0) {
                (**(code **)(*local_30 + 8))(local_30);
              }
              goto LAB_1000aa9f;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_c8,0x40);
          local_3c = 3;
          local_44 = (undefined4 *)0x0;
          local_8._0_1_ = 6;
          local_48 = local_c8;
          if (local_48 != (OLECHAR *)0x0) {
            eVar4 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            ATL::AtlCrtErrorCheck(eVar4);
            eVar4 = wcscat_s(local_1e8,0x80,local_48);
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001c50(0x80004005);
              break;
            case 0xc:
              FUN_10001c50(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001c50(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,L"\\Required Categories");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001c50(0x80004005);
              break;
            case 0xc:
              FUN_10001c50(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001c50(0x80070057);
            }
            local_e4 = (HKEY)0x80000000;
            local_e0 = 0;
            local_dc = 0;
            local_d4 = (HKEY)0x0;
            local_d0 = 0;
            local_cc = 0;
            local_8 = CONCAT31(local_8._1_3_,8);
            local_e8 = 0;
            local_d8 = FUN_10001950(&local_d4,(HKEY)0x80000000,local_1e8,0x20019);
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
                FUN_10008bf0(&local_e4,local_1e8);
              }
            }
            eVar4 = wcscpy_s(local_1e8,0x80,L"CLSID\\");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001c50(0x80004005);
              break;
            case 0xc:
              FUN_10001c50(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001c50(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,local_48);
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001c50(0x80004005);
              break;
            case 0xc:
              FUN_10001c50(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001c50(0x80070057);
            }
            eVar4 = wcscat_s(local_1e8,0x80,L"\\Implemented Categories");
            switch(eVar4) {
            case 0:
            case 0x50:
              break;
            default:
              FUN_10001c50(0x80004005);
              break;
            case 0xc:
              FUN_10001c50(0x8007000e);
              break;
            case 0x16:
            case 0x22:
              FUN_10001c50(0x80070057);
            }
            local_d8 = FUN_10001950(&local_d4,local_e4,local_1e8,0x20019);
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
                FUN_10008bf0(&local_e4,local_1e8);
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
          while (puVar2 = local_44, local_44 != (undefined4 *)0x0) {
            local_44 = (undefined4 *)*local_44;
            free(puVar2);
          }
        }
        local_8 = 0xffffffff;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
    }
  }
LAB_1000aa9f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000acb0 at 1000acb0

void __fastcall FUN_1000acb0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018ca8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ad10 at 1000ad10

int FUN_1000ad10(int param_1,int param_2,void *param_3)

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
        local_8 = FUN_1000a2b0((GUID *)*puVar1,piVar3,iVar2);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_1000ae00(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
    }
  }
  return local_8;
}



// Function: FUN_1000ae00 at 1000ae00

void FUN_1000ae00(HMODULE param_1,LPCWSTR param_2)

{
  uint uVar1;
  rsize_t _MaxCount;
  errno_t eVar2;
  int iVar3;
  HMODULE hModule;
  char local_239;
  wchar_t local_238 [259];
  undefined2 local_32;
  uint local_2c;
  wchar_t *local_28;
  wchar_t *local_24;
  FARPROC local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10018d00;
  local_10 = ExceptionList;
  uVar1 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0;
  local_14 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_2c = uVar1;
  local_18 = FUN_1000b0a0(param_1,param_2,&local_1c,&local_14);
  if (-1 < local_18) {
    local_28 = (wchar_t *)0x0;
    local_24 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    local_18 = (**(code **)(*local_14 + 0x24))(local_14,0xffffffff,0,0,0,&local_24,uVar1);
    if ((-1 < local_18) && (local_24 != (wchar_t *)0x0)) {
      _MaxCount = Ordinal_7(local_24);
      eVar2 = wcsncpy_s(local_238,0x104,local_24,_MaxCount);
      ATL::AtlCrtErrorCheck(eVar2);
      local_32 = 0;
      iVar3 = FUN_1000b710(local_238);
      local_238[iVar3] = L'\0';
      local_28 = local_238;
    }
    local_20 = (FARPROC)0x0;
    local_239 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x239) {
      local_18 = -0x7fffbffd;
    }
    else {
      local_239 = DAT_10024750;
      local_18 = 0;
    }
    if (local_18 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_1c);
      goto LAB_1000b07c;
    }
    if (local_239 == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule != (HMODULE)0x0) {
        local_20 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      }
    }
    if (local_20 == (FARPROC)0x0) {
      local_20 = Ordinal_163_exref;
    }
    local_18 = (*local_20)(local_14,local_1c,local_28);
    local_8._0_1_ = 2;
    Ordinal_6(local_24);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_1c);
LAB_1000b07c:
  ExceptionList = local_10;
  __security_check_cookie(local_2c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b0a0 at 1000b0a0

/* WARNING: Removing unreachable block (ram,0x1000b1a0) */

void FUN_1000b0a0(HMODULE param_1,LPCWSTR param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  errno_t eVar3;
  int iVar4;
  wchar_t local_270 [6];
  uint local_264;
  LPCWSTR local_260;
  uint local_25c;
  WCHAR *local_258;
  int local_254;
  LPCWSTR local_250;
  DWORD local_24c;
  undefined4 *local_248;
  WCHAR local_240 [272];
  uint local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018d3b;
  local_10 = ExceptionList;
  uVar2 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = uVar2;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_1c = 3;
    local_248 = (undefined4 *)0x0;
    local_8 = 0;
    local_24c = GetModuleFileNameW(param_1,local_240,0x104);
    if (local_24c == 0) {
      ATL::AtlHresultFromLastError();
      local_8 = 0xffffffff;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
    }
    else if (local_24c == 0x104) {
      local_8 = 0xffffffff;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
    }
    else {
      local_250 = (LPCWSTR)0x0;
      local_250 = FUN_1000b690(local_240);
      if (param_2 != (LPCWSTR)0x0) {
        local_260 = param_2;
        if (param_2 == (LPCWSTR)0x0) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          goto LAB_1000b5a0;
        }
        local_25c = lstrlenW(param_2);
        local_264 = local_24c + local_25c;
        if (((local_264 < local_24c) || (local_264 < local_25c)) || (0x10d < local_264)) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          goto LAB_1000b5a0;
        }
        eVar3 = wcscpy_s(local_240 + local_24c,0x10e - local_24c,local_260);
        switch(eVar3) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_10001c50(0x80004005);
          break;
        case 0xc:
          FUN_10001c50(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_10001c50(0x80070057);
        }
      }
      local_258 = local_240;
      local_254 = Ordinal_161(local_258,param_4,uVar2);
      if (local_254 < 0) {
        builtin_wcsncpy(local_270,L".tlb",5);
        if (0x104 < ((int)local_250 - (int)local_240 >> 1) + 5U) {
          local_8 = 0xffffffff;
          while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
            local_248 = (undefined4 *)*local_248;
            free(puVar1);
          }
          goto LAB_1000b5a0;
        }
        eVar3 = wcscpy_s(local_250,0x10e - ((int)local_250 - (int)local_240 >> 1),local_270);
        switch(eVar3) {
        case 0:
        case 0x50:
          break;
        default:
          FUN_10001c50(0x80004005);
          break;
        case 0xc:
          FUN_10001c50(0x8007000e);
          break;
        case 0x16:
        case 0x22:
          FUN_10001c50(0x80070057);
        }
        local_258 = local_240;
        local_254 = Ordinal_161(local_258,param_4);
      }
      if (-1 < local_254) {
        iVar4 = Ordinal_2(local_258);
        *param_3 = iVar4;
        if (*param_3 == 0) {
          local_254 = -0x7ff8fff2;
        }
      }
      local_8 = 0xffffffff;
      while (puVar1 = local_248, local_248 != (undefined4 *)0x0) {
        local_248 = (undefined4 *)*local_248;
        free(puVar1);
      }
    }
  }
LAB_1000b5a0:
  ExceptionList = local_10;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b690 at 1000b690

LPCWSTR __cdecl FUN_1000b690(LPWSTR param_1)

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



// Function: FUN_1000b710 at 1000b710

int FUN_1000b710(LPWSTR param_1)

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



// Function: FUN_1000b780 at 1000b780

void __fastcall FUN_1000b780(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018d78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b7e0 at 1000b7e0

int __thiscall FUN_1000b7e0(void *this,int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  int local_210;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,(void *)*local_8,0x10), iVar1 == 0)) {
        iVar1 = 0;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = FUN_1000a2b0((GUID *)*local_8,piVar2,iVar1);
        if ((local_c < 0) || (local_c = (*(code *)local_8[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_210 = 0;
    if (DAT_1002474c != (code *)0x0) {
      local_210 = (*DAT_1002474c)();
    }
    if (-1 < local_210) {
      local_210 = FUN_1000b8e0(0x10024964,param_1,param_2);
    }
    local_c = local_210;
  }
  return local_c;
}



// Function: FUN_1000b8e0 at 1000b8e0

int FUN_1000b8e0(int param_1,int param_2,void *param_3)

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
        local_8 = FUN_1000a2b0((GUID *)*puVar1,piVar3,iVar2);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_1000b9c0(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
    }
  }
  return local_8;
}



// Function: FUN_1000b9c0 at 1000b9c0

int FUN_1000b9c0(HMODULE param_1,LPCWSTR param_2)

{
  int iVar1;
  uint uVar2;
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
  
  puStack_c = &LAB_10018dc8;
  local_10 = ExceptionList;
  uVar2 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0;
  local_14 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_18 = FUN_1000b0a0(param_1,param_2,&local_1c,&local_14);
  if ((-1 < local_18) &&
     (local_18 = (**(code **)(*local_14 + 0x1c))(local_14,&local_20,uVar2), -1 < local_18)) {
    local_24 = (FARPROC)0x0;
    local_25 = '\0';
    if (&stack0x00000000 == (undefined1 *)0x25) {
      local_18 = -0x7fffbffd;
    }
    else {
      local_25 = DAT_10024750;
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



// Function: FUN_1000bb90 at 1000bb90

/* WARNING: Removing unreachable block (ram,0x1000bcd5) */
/* WARNING: Removing unreachable block (ram,0x1000bcee) */

int FUN_1000bb90(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  LPCRITICAL_SECTION local_24;
  undefined1 local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018df8;
  local_10 = ExceptionList;
  uVar3 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_4 == (int *)0x0) {
    local_14 = -0x7fffbffd;
  }
  else {
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
              FUN_1000ed90(&local_24,param_1 + 4,'\0');
              local_8 = 0;
              EnterCriticalSection(local_24);
              local_20 = 1;
              local_14 = 0;
              if (local_1c[4] == 0) {
                local_14 = (*(code *)local_1c[2])(local_1c[3],&PTR_1001cf58,local_1c + 4);
              }
              local_8 = 0xffffffff;
              FUN_1000ee00(&local_24);
            }
            if (local_1c[4] != 0) {
              local_14 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_3,param_4,uVar3);
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



// Function: FUN_1000bd90 at 1000bd90

void FUN_1000bd90(int param_1)

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



// Function: FUN_1000be10 at 1000be10

undefined4 FUN_1000be10(void)

{
  return 0;
}



// Function: FUN_1000be20 at 1000be20

void FUN_1000be20(void)

{
  return;
}



// Function: FUN_1000be30 at 1000be30

void __fastcall FUN_1000be30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e4e;
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



// Function: FUN_1000bed0 at 1000bed0

void FUN_1000bed0(void)

{
  return;
}



// Function: FUN_1000bee0 at 1000bee0

void __fastcall FUN_1000bee0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bf50 at 1000bf50

void FUN_1000bf50(void)

{
  return;
}



// Function: FUN_1000bf60 at 1000bf60

undefined4 FUN_1000bf60(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_1000c000 at 1000c000

undefined4 FUN_1000c000(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10024754 + 8))();
  }
  else {
    (**(code **)(*DAT_10024754 + 4))();
  }
  return 0;
}



// Function: FUN_1000c040 at 1000c040

undefined4 * __thiscall FUN_1000c040(void *this,uint param_1)

{
  FUN_1000be30((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c070 at 1000c070

LONG FUN_1000c070(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10024754 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000c0b0 at 1000c0b0

LONG FUN_1000c0b0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10024754 + 8))();
  }
  return LVar1;
}



// Function: FUN_1000c120 at 1000c120

int FUN_1000c120(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000c150(param_1,(int *)&PTR_DAT_1001d040,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000c150 at 1000c150

int FUN_1000c150(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
LAB_1000c262:
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
          if (bVar1) goto LAB_1000c262;
        }
      }
      iVar2 = -0x7fffbffe;
    }
  }
  return iVar2;
}



// Function: FUN_1000c2f0 at 1000c2f0

undefined4 FUN_1000c2f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10018ea8;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x230);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000fd30((int)puVar1);
      local_8._0_1_ = 1;
      *puVar1 = ATL::CComObject<class_CKernelServiceProvider>::vftable;
      puVar1[1] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
      puVar1[2] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
      puVar1[3] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
      (**(code **)(*DAT_10024754 + 4))();
      local_8 = (uint)local_8._1_3_ << 8;
    }
    uVar2 = FUN_1000c3ce();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000c3c1 at 1000c3c1

undefined4 Catch_1000c3c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c3d5;
}



// Function: FUN_1000c3ce at 1000c3ce

undefined4 FUN_1000c3ce(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(unaff_EBP + -0x14) + 0x1a0));
    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x14) + 0x1a4;
    DVar1 = FUN_10009d60(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x34));
    *(DWORD *)(unaff_EBP + -0x28) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x28)) {
      *(undefined1 *)(*(int *)(unaff_EBP + -0x34) + 0x18) = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x28);
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_10011230();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    InterlockedDecrement((LONG *)(*(int *)(unaff_EBP + -0x14) + 0x1a0));
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      }
      else {
        uVar2 = (*(code *)**(undefined4 **)(*(int *)(unaff_EBP + -0x20) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000c4c0 at 1000c4c0

int __fastcall FUN_1000c4c0(int param_1)

{
  return param_1 + *(int *)(DAT_10024798 + 4);
}



// Function: FUN_1000c4e0 at 1000c4e0

undefined4 FUN_1000c4e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10018ef9;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar2 = (undefined4 *)operator_new(0x23c);
    uVar1 = local_8 >> 8;
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0;
      local_8._1_3_ = (uint3)(local_8 >> 8);
      local_8._0_1_ = 3;
      *puVar2 = ATL::CComAggObject<class_CKernelServiceProvider>::vftable;
      FUN_1000cf40(puVar2 + 3,param_1);
      local_8._0_1_ = 4;
      (**(code **)(*DAT_10024754 + 4))();
      uVar1 = (uint)local_8._1_3_;
    }
    local_8 = uVar1 << 8;
    uVar3 = FUN_1000c5cf();
    return uVar3;
  }
  return 0x80004003;
}



// Function: Catch@1000c5c2 at 1000c5c2

undefined4 Catch_1000c5c2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c5d6;
}



// Function: FUN_1000c5cf at 1000c5cf

undefined4 FUN_1000c5cf(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    DVar1 = FUN_1000c830(*(int *)(unaff_EBP + -0x14));
    *(DWORD *)(unaff_EBP + -0x18) = DVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_10011230();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
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
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000c680 at 1000c680

undefined4 * __thiscall FUN_1000c680(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  local_8 = 0xffffffff;
  FUN_1000be30((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c700 at 1000c700

undefined4 * __fastcall FUN_1000c700(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018f73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  memset(param_1 + 1,0,0x18);
  *(undefined1 *)(param_1 + 7) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c780 at 1000c780

void FUN_1000c780(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x1a0));
  return;
}



// Function: FUN_1000c7a0 at 1000c7a0

LONG FUN_1000c7a0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x1a0));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_1000c800 at 1000c800

int FUN_1000c800(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000c150(param_1,DAT_10024798,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000c830 at 1000c830

DWORD __fastcall FUN_1000c830(int param_1)

{
  undefined4 local_8;
  
  local_8 = FUN_10009d60((LPCRITICAL_SECTION)(param_1 + 0x1b0));
  if (-1 < (int)local_8) {
    *(undefined1 *)(param_1 + 0x1c8) = 1;
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_1000c880 at 1000c880

void FUN_1000c880(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_1000c8a0 at 1000c8a0

LONG FUN_1000c8a0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_1000c900 at 1000c900

int FUN_1000c900(int *param_1,int *param_2,undefined4 *param_3)

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
      local_8 = FUN_1000c150((int)(param_1 + 3),DAT_10024798,param_2,param_3);
    }
  }
  return local_8;
}



// Function: FUN_1000c9b0 at 1000c9b0

void __fastcall FUN_1000c9b0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019050;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._1_3_ = 0;
  local_8._0_1_ = 8;
  FUN_10003400((void *)(param_1 + 0x214),'\x01',0);
  local_8._0_1_ = 10;
  FUN_1000d110((void *)(param_1 + 0x204));
  local_8._0_1_ = 5;
  operator_delete(*(void **)(param_1 + 0x208));
  local_8._0_1_ = 4;
  FUN_10015e10((undefined4 *)(param_1 + 0x1e8));
  local_8._0_1_ = 3;
  FUN_10001190((undefined4 *)(param_1 + 0x1d4));
  local_8._0_1_ = 0xc;
  FUN_1000d080((void *)(param_1 + 0x1c4));
  local_8._0_1_ = 2;
  operator_delete(*(void **)(param_1 + 0x1c8));
  piVar1 = (int *)(param_1 + 0x1c0);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*piVar1 != 0) {
    (**(code **)(*(int *)*piVar1 + 8))(*piVar1);
  }
  *(undefined ***)(param_1 + 0xc) = CComRuntimeAggregator<class_CKernelServiceProvider,100>::vftable
  ;
  local_8 = 0x11;
  if (*(char *)(param_1 + 0x1bc) != '\0') {
    *(undefined1 *)(param_1 + 0x1bc) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1a4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cb40 at 1000cb40

void __fastcall FUN_1000cb40(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019078;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cba0 at 1000cba0

void __fastcall FUN_1000cba0(undefined4 *param_1)

{
  *param_1 = CComRuntimeAggregator<class_CKernelServiceProvider,100>::vftable;
  return;
}



// Function: FUN_1000cbc0 at 1000cbc0

undefined4 * __thiscall FUN_1000cbc0(void *this,uint param_1)

{
  *(undefined ***)this = CComRuntimeAggregator<class_CKernelServiceProvider,100>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000cbf0 at 1000cbf0

undefined4 * __thiscall FUN_1000cbf0(void *this,uint param_1)

{
  FUN_1000cc20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000cc20 at 1000cc20

void __fastcall FUN_1000cc20(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100190c9;
  local_10 = ExceptionList;
  uVar1 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CKernelServiceProvider>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  FUN_10011240((int)(param_1 + 3));
  (**(code **)(*DAT_10024754 + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_1000c9b0((int)(param_1 + 3));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ccc0 at 1000ccc0

void __fastcall FUN_1000ccc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100190f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000c9b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cd10 at 1000cd10

void __fastcall FUN_1000cd10(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019128;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000cdb0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cd60 at 1000cd60

void __fastcall FUN_1000cd60(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019158;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000ce50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cdb0 at 1000cdb0

void __fastcall FUN_1000cdb0(void *param_1)

{
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = *(int **)((int)param_1 + 4);
  local_20 = (int *)**(undefined4 **)((int)param_1 + 4);
  local_1c = local_20;
  local_14 = local_18;
  FUN_1000d1a0(param_1,&local_24,local_20,local_18);
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ce50 at 1000ce50

void __fastcall FUN_1000ce50(void *param_1)

{
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100191b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = *(int **)((int)param_1 + 4);
  local_20 = (int *)**(undefined4 **)((int)param_1 + 4);
  local_1c = local_20;
  local_14 = local_18;
  FUN_1000d280(param_1,&local_24,local_20,local_18);
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cef0 at 1000cef0

void FUN_1000cef0(void)

{
  return;
}



// Function: FUN_1000cf40 at 1000cf40

undefined4 * __thiscall FUN_1000cf40(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019218;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000fd30((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CKernelServiceProvider>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CKernelServiceProvider>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CKernelServiceProvider>::vftable;
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CKernelServiceProvider>::vftable;
  *(undefined4 *)((int)this + 0x1a0) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000cfd0 at 1000cfd0

void FUN_1000cfd0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x1a0) + 4))(*(undefined4 *)(param_1 + 0x1a0));
  return;
}



// Function: FUN_1000d000 at 1000d000

void FUN_1000d000(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x1a0) + 8))(*(undefined4 *)(param_1 + 0x1a0));
  return;
}



// Function: FUN_1000d030 at 1000d030

void FUN_1000d030(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x1a0))(*(undefined4 *)(param_1 + 0x1a0),param_2,param_3);
  return;
}



// Function: FUN_1000d060 at 1000d060

undefined4 __fastcall FUN_1000d060(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1a0);
}



// Function: FUN_1000d080 at 1000d080

void __fastcall FUN_1000d080(void *param_1)

{
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_c = *(int **)((int)param_1 + 4);
  local_14 = (int *)**(undefined4 **)((int)param_1 + 4);
  local_10 = local_14;
  local_8 = local_c;
  FUN_1000d1a0(param_1,&local_18,local_14,local_c);
  return;
}



// Function: FUN_1000d0e0 at 1000d0e0

void __fastcall FUN_1000d0e0(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1000d110 at 1000d110

void __fastcall FUN_1000d110(void *param_1)

{
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_c = *(int **)((int)param_1 + 4);
  local_14 = (int *)**(undefined4 **)((int)param_1 + 4);
  local_10 = local_14;
  local_8 = local_c;
  FUN_1000d280(param_1,&local_18,local_14,local_c);
  return;
}



// Function: FUN_1000d170 at 1000d170

void __fastcall FUN_1000d170(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1000d1a0 at 1000d1a0

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000d1a0(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)**(int **)((int)param_1 + 4);
  if ((param_3 == local_8) && (local_c = *(int **)((int)param_1 + 4), param_4 == local_c)) {
    FUN_1000d840(param_1);
    *param_2 = **(undefined4 **)((int)param_1 + 4);
    return param_2;
  }
  while (piVar1 = param_3, param_3 != param_4) {
    FUN_1000e180((int *)&param_3);
    local_10 = piVar1;
    FUN_1000d360(param_1,&local_14,piVar1);
  }
  *param_2 = param_3;
  return param_2;
}



// Function: FUN_1000d280 at 1000d280

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000d280(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)**(int **)((int)param_1 + 4);
  if ((param_3 == local_8) && (local_c = *(int **)((int)param_1 + 4), param_4 == local_c)) {
    FUN_1000dd80(param_1);
    *param_2 = **(undefined4 **)((int)param_1 + 4);
    return param_2;
  }
  while (piVar1 = param_3, param_3 != param_4) {
    FUN_1000e230((int *)&param_3);
    local_10 = piVar1;
    FUN_1000d8a0(param_1,&local_14,piVar1);
  }
  *param_2 = param_3;
  return param_2;
}



// Function: FUN_1000d360 at 1000d360

undefined4 * __thiscall FUN_1000d360(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *local_88;
  int *local_84;
  int *local_28;
  int *local_20;
  int *local_14;
  int *local_10;
  int *local_c;
  
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  piVar2 = param_2;
  FUN_1000e180((int *)&param_2);
  local_10 = piVar2;
  if (*(char *)(*piVar2 + 0x25) == '\0') {
    if (*(char *)(piVar2[2] + 0x25) == '\0') {
      local_10 = param_2;
      local_c = (int *)param_2[2];
    }
    else {
      local_c = (int *)*piVar2;
    }
  }
  else {
    local_c = (int *)piVar2[2];
  }
  if (local_10 == piVar2) {
    local_14 = (int *)piVar2[1];
    if (*(char *)((int)local_c + 0x25) == '\0') {
      local_c[1] = (int)local_14;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_c;
    }
    else if ((int *)*local_14 == piVar2) {
      *local_14 = (int)local_c;
    }
    else {
      local_14[2] = (int)local_c;
    }
    if ((int *)**(int **)((int)this + 4) == piVar2) {
      local_84 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        for (local_20 = local_c; *(char *)(*local_20 + 0x25) == '\0'; local_20 = (int *)*local_20) {
        }
        local_84 = local_20;
      }
      **(int **)((int)this + 4) = (int)local_84;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      local_88 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_28 = local_c;
        while (*(char *)(local_28[2] + 0x25) == '\0') {
          local_28 = (int *)local_28[2];
        }
        local_88 = local_28;
      }
      *(int **)(*(int *)((int)this + 4) + 8) = local_88;
    }
  }
  else {
    *(int **)(*piVar2 + 4) = local_10;
    *local_10 = *piVar2;
    if (local_10 == (int *)piVar2[2]) {
      local_14 = local_10;
    }
    else {
      local_14 = (int *)local_10[1];
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_c[1] = (int)local_14;
      }
      *local_14 = (int)local_c;
      local_10[2] = piVar2[2];
      *(int **)(piVar2[2] + 4) = local_10;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_10;
    }
    else if (*(int **)piVar2[1] == piVar2) {
      *(int **)piVar2[1] = local_10;
    }
    else {
      *(int **)(piVar2[1] + 8) = local_10;
    }
    local_10[1] = piVar2[1];
    iVar1 = local_10[9];
    *(char *)(local_10 + 9) = (char)piVar2[9];
    *(char *)(piVar2 + 9) = (char)iVar1;
  }
  if ((char)piVar2[9] != '\x01') {
LAB_1000d7ed:
    FUN_1000e2e0((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return param_1;
  }
LAB_1000d5fd:
  if ((local_c == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)local_c[9] != '\x01'))
  goto LAB_1000d7e6;
  if (local_c == (int *)*local_14) {
    local_10 = (int *)local_14[2];
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_1000de50(this,(int)local_14);
      local_10 = (int *)local_14[2];
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(*local_10 + 0x24) != '\x01') || (*(char *)(local_10[2] + 0x24) != '\x01')) {
        if (*(char *)(local_10[2] + 0x24) == '\x01') {
          *(undefined1 *)(*local_10 + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_1000df00(this,local_10);
          local_10 = (int *)local_14[2];
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(local_10[2] + 0x24) = 1;
        FUN_1000de50(this,(int)local_14);
LAB_1000d7e6:
        *(undefined1 *)(local_c + 9) = 1;
        goto LAB_1000d7ed;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  else {
    local_10 = (int *)*local_14;
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_1000df00(this,local_14);
      local_10 = (int *)*local_14;
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(local_10[2] + 0x24) != '\x01') || (*(char *)(*local_10 + 0x24) != '\x01')) {
        if (*(char *)(*local_10 + 0x24) == '\x01') {
          *(undefined1 *)(local_10[2] + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_1000de50(this,(int)local_10);
          local_10 = (int *)*local_14;
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(*local_10 + 0x24) = 1;
        FUN_1000df00(this,local_14);
        goto LAB_1000d7e6;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  local_c = local_14;
  local_14 = (int *)local_14[1];
  goto LAB_1000d5fd;
}



// Function: FUN_1000d840 at 1000d840

void __fastcall FUN_1000d840(void *param_1)

{
  FUN_1000dde0(param_1,*(undefined4 **)(*(int *)((int)param_1 + 4) + 4));
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 4) = *(undefined4 *)((int)param_1 + 4);
  **(undefined4 **)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 8) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000d8a0 at 1000d8a0

undefined4 * __thiscall FUN_1000d8a0(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *local_88;
  int *local_84;
  int *local_28;
  int *local_20;
  int *local_14;
  int *local_10;
  int *local_c;
  
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  piVar2 = param_2;
  FUN_1000e230((int *)&param_2);
  local_10 = piVar2;
  if (*(char *)(*piVar2 + 0x25) == '\0') {
    if (*(char *)(piVar2[2] + 0x25) == '\0') {
      local_10 = param_2;
      local_c = (int *)param_2[2];
    }
    else {
      local_c = (int *)*piVar2;
    }
  }
  else {
    local_c = (int *)piVar2[2];
  }
  if (local_10 == piVar2) {
    local_14 = (int *)piVar2[1];
    if (*(char *)((int)local_c + 0x25) == '\0') {
      local_c[1] = (int)local_14;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_c;
    }
    else if ((int *)*local_14 == piVar2) {
      *local_14 = (int)local_c;
    }
    else {
      local_14[2] = (int)local_c;
    }
    if ((int *)**(int **)((int)this + 4) == piVar2) {
      local_84 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        for (local_20 = local_c; *(char *)(*local_20 + 0x25) == '\0'; local_20 = (int *)*local_20) {
        }
        local_84 = local_20;
      }
      **(int **)((int)this + 4) = (int)local_84;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      local_88 = local_14;
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_28 = local_c;
        while (*(char *)(local_28[2] + 0x25) == '\0') {
          local_28 = (int *)local_28[2];
        }
        local_88 = local_28;
      }
      *(int **)(*(int *)((int)this + 4) + 8) = local_88;
    }
  }
  else {
    *(int **)(*piVar2 + 4) = local_10;
    *local_10 = *piVar2;
    if (local_10 == (int *)piVar2[2]) {
      local_14 = local_10;
    }
    else {
      local_14 = (int *)local_10[1];
      if (*(char *)((int)local_c + 0x25) == '\0') {
        local_c[1] = (int)local_14;
      }
      *local_14 = (int)local_c;
      local_10[2] = piVar2[2];
      *(int **)(piVar2[2] + 4) = local_10;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = local_10;
    }
    else if (*(int **)piVar2[1] == piVar2) {
      *(int **)piVar2[1] = local_10;
    }
    else {
      *(int **)(piVar2[1] + 8) = local_10;
    }
    local_10[1] = piVar2[1];
    iVar1 = local_10[9];
    *(char *)(local_10 + 9) = (char)piVar2[9];
    *(char *)(piVar2 + 9) = (char)iVar1;
  }
  if ((char)piVar2[9] != '\x01') {
LAB_1000dd2d:
    FUN_1000e350((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return param_1;
  }
LAB_1000db3d:
  if ((local_c == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)local_c[9] != '\x01'))
  goto LAB_1000dd26;
  if (local_c == (int *)*local_14) {
    local_10 = (int *)local_14[2];
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_1000e020(this,(int)local_14);
      local_10 = (int *)local_14[2];
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(*local_10 + 0x24) != '\x01') || (*(char *)(local_10[2] + 0x24) != '\x01')) {
        if (*(char *)(local_10[2] + 0x24) == '\x01') {
          *(undefined1 *)(*local_10 + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_1000e0d0(this,local_10);
          local_10 = (int *)local_14[2];
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(local_10[2] + 0x24) = 1;
        FUN_1000e020(this,(int)local_14);
LAB_1000dd26:
        *(undefined1 *)(local_c + 9) = 1;
        goto LAB_1000dd2d;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  else {
    local_10 = (int *)*local_14;
    if ((char)local_10[9] == '\0') {
      *(undefined1 *)(local_10 + 9) = 1;
      *(undefined1 *)(local_14 + 9) = 0;
      FUN_1000e0d0(this,local_14);
      local_10 = (int *)*local_14;
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') {
      if ((*(char *)(local_10[2] + 0x24) != '\x01') || (*(char *)(*local_10 + 0x24) != '\x01')) {
        if (*(char *)(*local_10 + 0x24) == '\x01') {
          *(undefined1 *)(local_10[2] + 0x24) = 1;
          *(undefined1 *)(local_10 + 9) = 0;
          FUN_1000e020(this,(int)local_10);
          local_10 = (int *)*local_14;
        }
        *(char *)(local_10 + 9) = (char)local_14[9];
        *(undefined1 *)(local_14 + 9) = 1;
        *(undefined1 *)(*local_10 + 0x24) = 1;
        FUN_1000e0d0(this,local_14);
        goto LAB_1000dd26;
      }
      *(undefined1 *)(local_10 + 9) = 0;
    }
  }
  local_c = local_14;
  local_14 = (int *)local_14[1];
  goto LAB_1000db3d;
}



// Function: FUN_1000dd80 at 1000dd80

void __fastcall FUN_1000dd80(void *param_1)

{
  FUN_1000dfb0(param_1,*(undefined4 **)(*(int *)((int)param_1 + 4) + 4));
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 4) = *(undefined4 *)((int)param_1 + 4);
  **(undefined4 **)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(*(int *)((int)param_1 + 4) + 8) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000dde0 at 1000dde0

void __thiscall FUN_1000dde0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = param_1;
  while (*(char *)((int)local_8 + 0x25) == '\0') {
    FUN_1000dde0(this,(undefined4 *)local_8[2]);
    puVar1 = (undefined4 *)*local_8;
    FUN_1000e2e0((int)this + 0xd,local_8 + 3);
    operator_delete(local_8);
    local_8 = puVar1;
  }
  return;
}



// Function: FUN_1000de50 at 1000de50

void __thiscall FUN_1000de50(void *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x25) == '\0') {
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



// Function: FUN_1000df00 at 1000df00

void __thiscall FUN_1000df00(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x25) == '\0') {
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



// Function: FUN_1000dfb0 at 1000dfb0

void __thiscall FUN_1000dfb0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = param_1;
  while (*(char *)((int)local_8 + 0x25) == '\0') {
    FUN_1000dfb0(this,(undefined4 *)local_8[2]);
    puVar1 = (undefined4 *)*local_8;
    FUN_1000e350((int)this + 0xd,local_8 + 3);
    operator_delete(local_8);
    local_8 = puVar1;
  }
  return;
}



// Function: FUN_1000e020 at 1000e020

void __thiscall FUN_1000e020(void *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x25) == '\0') {
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



// Function: FUN_1000e0d0 at 1000e0d0

void __thiscall FUN_1000e0d0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x25) == '\0') {
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



// Function: FUN_1000e180 at 1000e180

int * __fastcall FUN_1000e180(int *param_1)

{
  int iVar1;
  int *local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)(*param_1 + 8) + 0x25) == '\0') {
      for (local_14 = *(int **)(*param_1 + 8); *(char *)(*local_14 + 0x25) == '\0';
          local_14 = (int *)*local_14) {
      }
      *param_1 = (int)local_14;
    }
    else {
      while ((iVar1 = *(int *)(*param_1 + 4), *(char *)(iVar1 + 0x25) == '\0' &&
             (*param_1 == *(int *)(iVar1 + 8)))) {
        *param_1 = iVar1;
      }
      *param_1 = iVar1;
    }
  }
  return param_1;
}



// Function: FUN_1000e230 at 1000e230

int * __fastcall FUN_1000e230(int *param_1)

{
  int iVar1;
  int *local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)(*param_1 + 8) + 0x25) == '\0') {
      for (local_14 = *(int **)(*param_1 + 8); *(char *)(*local_14 + 0x25) == '\0';
          local_14 = (int *)*local_14) {
      }
      *param_1 = (int)local_14;
    }
    else {
      while ((iVar1 = *(int *)(*param_1 + 4), *(char *)(iVar1 + 0x25) == '\0' &&
             (*param_1 == *(int *)(iVar1 + 8)))) {
        *param_1 = iVar1;
      }
      *param_1 = iVar1;
    }
  }
  return param_1;
}



// Function: FUN_1000e2e0 at 1000e2e0

/* WARNING: Removing unreachable block (ram,0x1000e326) */

void __cdecl FUN_1000e2e0(undefined4 param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019250;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e350 at 1000e350

/* WARNING: Removing unreachable block (ram,0x1000e396) */

void __cdecl FUN_1000e350(undefined4 param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019280;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_2);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 1000e3c0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100192a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 1000e410

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100192d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e460 at 1000e460

void FUN_1000e460(int param_1)

{
  FUN_1000c7a0(param_1 + -4);
  return;
}



// Function: FUN_1000e470 at 1000e470

void FUN_1000e470(int param_1)

{
  FUN_1000c7a0(param_1 + -8);
  return;
}



// Function: FUN_1000e480 at 1000e480

void FUN_1000e480(int param_1)

{
  FUN_1000d000(param_1 + -4);
  return;
}



// Function: FUN_1000e490 at 1000e490

void FUN_1000e490(int param_1)

{
  FUN_1000c780(param_1 + -4);
  return;
}



// Function: FUN_1000e4a0 at 1000e4a0

void FUN_1000e4a0(int param_1)

{
  FUN_1000d000(param_1 + -8);
  return;
}



// Function: FUN_1000e4b0 at 1000e4b0

void __thiscall FUN_1000e4b0(void *this,uint param_1)

{
  FUN_1000e4c0((void *)((int)this + -0xc),param_1);
  return;
}



// Function: FUN_1000e4c0 at 1000e4c0

undefined4 * __thiscall FUN_1000e4c0(void *this,uint param_1)

{
  FUN_1000e4f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e4f0 at 1000e4f0

void __fastcall FUN_1000e4f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019308;
  local_10 = ExceptionList;
  uVar1 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CKernelServiceProvider>::vftable;
  param_1[1] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
  param_1[2] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
  param_1[3] = ATL::CComObject<class_CKernelServiceProvider>::vftable;
  local_8 = 0;
  param_1[0x68] = 0xc0000001;
  FUN_10011240((int)param_1);
  (**(code **)(*DAT_10024754 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000c9b0((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e590 at 1000e590

void FUN_1000e590(int param_1)

{
  FUN_1000c780(param_1 + -8);
  return;
}



// Function: FUN_1000e5a0 at 1000e5a0

void FUN_1000e5a0(int param_1)

{
  FUN_1000cfd0(param_1 + -4);
  return;
}



// Function: FUN_1000e5b0 at 1000e5b0

void FUN_1000e5b0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c800(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000e5c0 at 1000e5c0

void __thiscall FUN_1000e5c0(void *this,uint param_1)

{
  FUN_1000e5d0((void *)((int)this + -0xc),param_1);
  return;
}



// Function: FUN_1000e5d0 at 1000e5d0

void * __thiscall FUN_1000e5d0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019338;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000c9b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000e640 at 1000e640

void FUN_1000e640(int param_1)

{
  FUN_1000cfd0(param_1 + -8);
  return;
}



// Function: FUN_1000e650 at 1000e650

void FUN_1000e650(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c800(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000e660 at 1000e660

void FUN_1000e660(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000d030(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000e670 at 1000e670

void FUN_1000e670(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000d030(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000e680 at 1000e680

void __fastcall FUN_1000e680(int *param_1)

{
  void *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    free(_Memory);
  }
  return;
}



// Function: FUN_1000e6c0 at 1000e6c0

void __fastcall FUN_1000e6c0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000e6f0 at 1000e6f0

void __fastcall FUN_1000e6f0(int *param_1)

{
  FUN_1000e860(param_1);
  return;
}



// Function: FUN_1000e710 at 1000e710

undefined4 __thiscall FUN_1000e710(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019393;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
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



// Function: FUN_1000e860 at 1000e860

void __fastcall FUN_1000e860(int *param_1)

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



// Function: FUN_1000e8e0 at 1000e8e0

int __thiscall FUN_1000e8e0(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: Free at 1000e920

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



// Function: ~CTempBuffer<> at 1000e950

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
    FUN_1000ebc0(param_1);
  }
  return;
}



// Function: FUN_1000e970 at 1000e970

undefined4 __thiscall FUN_1000e970(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000ee40(param_1,2);
  if (uVar1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_1000ecd0(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: ~CTempBuffer<> at 1000e9c0

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
    FUN_1000ec30(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 1000e9e0

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
    FUN_1000eca0(param_1);
  }
  return;
}



// Function: FUN_1000ea00 at 1000ea00

void __fastcall FUN_1000ea00(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000ea30 at 1000ea30

void __fastcall FUN_1000ea30(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000ea60 at 1000ea60

void __fastcall FUN_1000ea60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100193d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000eae0 at 1000eae0

void __fastcall FUN_1000eae0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000eb50 at 1000eb50

int __thiscall FUN_1000eb50(void *this,undefined4 *param_1)

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



// Function: FUN_1000ebc0 at 1000ebc0

void __fastcall FUN_1000ebc0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000ebf0 at 1000ebf0

undefined4 __thiscall FUN_1000ebf0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_1000ed10(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000ec30 at 1000ec30

void __fastcall FUN_1000ec30(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000ec60 at 1000ec60

undefined4 __thiscall FUN_1000ec60(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_1000ed50(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000eca0 at 1000eca0

void __fastcall FUN_1000eca0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000ecd0 at 1000ecd0

void __thiscall FUN_1000ecd0(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    FUN_10001c50(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_1000ed10 at 1000ed10

void __thiscall FUN_1000ed10(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    FUN_10001c50(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_1000ed50 at 1000ed50

void __thiscall FUN_1000ed50(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    FUN_10001c50(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_1000ed90 at 1000ed90

/* WARNING: Removing unreachable block (ram,0x1000edcf) */
/* WARNING: Removing unreachable block (ram,0x1000edeb) */

undefined4 * __thiscall FUN_1000ed90(void *this,undefined4 param_1,char param_2)

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



// Function: FUN_1000ee00 at 1000ee00

void __fastcall FUN_1000ee00(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000ee40 at 1000ee40

/* WARNING: Removing unreachable block (ram,0x1000ee69) */

undefined4 __cdecl FUN_1000ee40(uint param_1,uint param_2)

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
    FUN_10001c50(local_c);
  }
  return local_8;
}



// Function: FUN_1000eec0 at 1000eec0

void FUN_1000eec0(void)

{
  return;
}



// Function: FUN_1000eed0 at 1000eed0

int __fastcall FUN_1000eed0(int param_1)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019466;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  memset((void *)(param_1 + 0x10),0,0x18);
  local_8 = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10024754 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar1 = FUN_10009d60((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar1 < 0) {
    DAT_10024744 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000efa0 at 1000efa0

void __fastcall FUN_1000efa0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100194a6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10009f50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f000 at 1000f000

void __fastcall FUN_1000f000(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000f020 at 1000f020

void __fastcall FUN_1000f020(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000f040 at 1000f040

undefined4 __fastcall FUN_1000f040(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1000f060 at 1000f060

int __thiscall FUN_1000f060(void *this,undefined4 *param_1)

{
  int local_8;
  
  if (param_1 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    local_8 = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_8 = CoCreateInstance((IID *)&DAT_1001d858,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001d160,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_8) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_8;
}



// Function: FUN_1000f0e0 at 1000f0e0

void FUN_1000f0e0(void)

{
  return;
}



// Function: FUN_1000f130 at 1000f130

undefined4 FUN_1000f130(void)

{
  return 0x80004005;
}



// Function: FUN_1000f140 at 1000f140

undefined4 FUN_1000f140(void)

{
  return 0x80004005;
}



// Function: FUN_1000f150 at 1000f150

void FUN_1000f150(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  FUN_1000f2a0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000f180 at 1000f180

void FUN_1000f180(int *param_1,ushort param_2,int param_3,int *param_4)

{
  FUN_10005c80(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000f1b0 at 1000f1b0

undefined4 * __thiscall FUN_1000f1b0(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019526;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 2;
  FUN_10009f50((int)this);
  local_8 = 0xffffffff;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000f240 at 1000f240

void __fastcall FUN_1000f240(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001956e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10009f50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f2a0 at 1000f2a0

/* WARNING: Removing unreachable block (ram,0x1000f5dc) */
/* WARNING: Removing unreachable block (ram,0x1000f301) */

void FUN_1000f2a0(int *param_1,LPCWSTR param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  HMODULE pHVar3;
  errno_t eVar4;
  int iVar5;
  int local_b4c;
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
  int local_aac;
  int local_aa8;
  int local_aa4;
  undefined4 local_aa0;
  undefined4 local_a9c;
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
  WCHAR local_230 [260];
  uint local_28;
  undefined4 local_24;
  HMODULE local_20;
  LPCWSTR local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019656;
  local_10 = ExceptionList;
  uVar2 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24c = ATL::CRegObject::vftable;
  local_28 = uVar2;
  FUN_10009b40(local_248);
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
        local_ac8 = FUN_10006600(local_ad4,local_ad8);
        local_ad0 = (-(uint)(local_ac8 != 0) & 0x7ff8fff2) + 0x8007000e;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_1000e680(local_ac4);
      }
    }
  }
  local_254 = (**(code **)(*param_1 + 0x14))(&local_24c,uVar2);
  if (local_254 < 0) {
    local_24c = ATL::CRegObject::vftable;
    local_8 = 5;
    local_a94 = local_254;
    FUN_10006fc0((int)&local_24c);
    local_adc = local_248;
    local_8 = 6;
    FUN_10006980(local_adc);
    local_8 = 0xffffffff;
    FUN_1000e860(local_adc);
  }
  else {
    local_24 = 3;
    local_238[0] = (undefined4 *)0x0;
    local_8._0_1_ = 7;
    local_20 = DAT_10024930;
    local_250 = GetModuleFileNameW(DAT_10024930,local_230,0x104);
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
      FUN_10006fc0((int)&local_24c);
      local_ae4 = local_248;
      local_8 = 9;
      FUN_10006980(local_ae4);
      local_8 = 0xffffffff;
      FUN_1000e860(local_ae4);
    }
    else if (local_250 == 0x104) {
      local_a9c = 0x8007007a;
      local_8 = CONCAT31(local_8._1_3_,1);
      while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
        local_ae8 = local_238[0];
        local_238[0] = (undefined4 *)*local_238[0];
        free(puVar1);
      }
      local_24c = ATL::CRegObject::vftable;
      local_8 = 10;
      FUN_10006fc0((int)&local_24c);
      local_aec = local_248;
      local_8 = 0xb;
      FUN_10006980(local_aec);
      local_8 = 0xffffffff;
      FUN_1000e860(local_aec);
    }
    else {
      local_260 = local_230;
      FUN_10006500(local_670,0x208,local_260);
      if ((local_20 == (HMODULE)0x0) ||
         (pHVar3 = GetModuleHandleW((LPCWSTR)0x0), local_20 == pHVar3)) {
        local_a88 = L'\"';
        local_af4 = lstrlenW(local_670);
        eVar4 = memcpy_s(local_a86,0x416,local_670,local_af4 * 2 + 2);
        if (eVar4 != 0) {
          local_aa0 = 0x80004005;
          local_8 = CONCAT31(local_8._1_3_,1);
          while (puVar1 = local_238[0], local_238[0] != (undefined4 *)0x0) {
            local_af8 = local_238[0];
            local_238[0] = (undefined4 *)*local_238[0];
            free(puVar1);
          }
          local_24c = ATL::CRegObject::vftable;
          local_8 = 0xc;
          FUN_10006fc0((int)&local_24c);
          local_afc = local_248;
          local_8 = 0xd;
          FUN_10006980(local_afc);
          local_8 = 0xffffffff;
          FUN_1000e860(local_afc);
          goto LAB_1000fb17;
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
          local_b14 = FUN_10006600(L"Module",(int)&local_a88);
          local_b1c = (-(uint)(local_b14 != 0) & 0x7ff8fff2) + 0x8007000e;
          local_8._0_1_ = 7;
          FUN_1000e680(local_b10);
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
        iVar5 = FUN_10006600(L"Module",(int)local_670);
        local_8._0_1_ = 7;
        FUN_1000e680(local_b30);
        local_25c = (-(uint)(iVar5 != 0) & 0x7ff8fff2) + 0x8007000e;
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
        FUN_10006fc0((int)&local_24c);
        local_8 = 0x11;
        FUN_10006980(local_248);
        local_8 = 0xffffffff;
        FUN_1000e860(local_248);
      }
      else {
        local_25c = FUN_10006b40(&local_24c,L"Module_Raw",(int)local_670);
        if (local_25c < 0) {
          local_8 = CONCAT31(local_8._1_3_,1);
          local_aa8 = local_25c;
          FUN_1000e680((int *)local_238);
          local_8 = 0xffffffff;
          FUN_10006a80(&local_24c);
        }
        else {
          local_258 = L"REGISTRY";
          local_18 = param_2;
          if (param_3 == 0) {
            local_b4c = FUN_1000fc20(&local_24c,local_260,param_2,L"REGISTRY");
          }
          else {
            local_b4c = FUN_1000fb40(&local_24c,local_260,param_2,L"REGISTRY");
          }
          local_254 = local_b4c;
          local_aac = local_b4c;
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_1000e680((int *)local_238);
          local_8 = 0xffffffff;
          FUN_10006a80(&local_24c);
        }
      }
    }
  }
LAB_1000fb17:
  ExceptionList = local_10;
  __security_check_cookie(local_28 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fb40 at 1000fb40

undefined4 FUN_1000fb40(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  undefined4 local_30;
  undefined4 *local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019688;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_2c = (undefined4 *)0x0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_30 = 0x80070057;
    local_8 = 0xffffffff;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  else {
    local_30 = FUN_10006ca0(param_2,param_3,param_4);
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



// Function: FUN_1000fc20 at 1000fc20

undefined4 FUN_1000fc20(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 *puVar1;
  undefined4 local_30;
  undefined4 *local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100196b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_2c = (undefined4 *)0x0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_30 = 0x80070057;
    local_8 = 0xffffffff;
    while (local_2c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*local_2c;
      free(local_2c);
      local_2c = puVar1;
    }
  }
  else {
    local_30 = FUN_10006ca0(param_2,param_3,param_4);
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



// Function: FUN_1000fd00 at 1000fd00

void __thiscall FUN_1000fd00(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_1001caa0,this);
  return;
}



// Function: FUN_1000fd30 at 1000fd30

int __fastcall FUN_1000fd30(int param_1)

{
  undefined1 local_4d;
  undefined1 *local_4c;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019890;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)(param_1 + 0x1a0);
  *local_18 = 0;
  local_8 = 0;
  local_14 = (void *)(param_1 + 0x1a4);
  memset(local_14,0,0x18);
  *(undefined1 *)((int)local_14 + 0x18) = 0;
  local_1c = (undefined4 *)(param_1 + 0xc);
  *local_1c = CComRuntimeAggregator<class_CKernelServiceProvider,100>::vftable;
  local_20 = (undefined4 *)(param_1 + 0x1c0);
  *local_20 = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 7;
  FUN_10011850(param_1 + 0x1c4);
  local_8._0_1_ = 8;
  FUN_10001000((undefined4 *)(param_1 + 0x1d4));
  local_8._0_1_ = 9;
  FUN_10015cd0((undefined4 *)(param_1 + 0x1e8));
  local_8._0_1_ = 10;
  *(undefined2 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  FUN_10011a90(param_1 + 0x204);
  local_4c = &local_4d;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_10003400((void *)(param_1 + 0x214),'\0',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fe80 at 1000fe80

undefined4 FUN_1000fe80(undefined4 param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      return 1;
    }
    if ((((*(int *)PTR_DAT_100245a8 == *param_2) && (*(int *)(PTR_DAT_100245a8 + 4) == param_2[1]))
        && (*(int *)(PTR_DAT_100245a8 + 8) == param_2[2])) &&
       (*(int *)(PTR_DAT_100245a8 + 0xc) == param_2[3])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    bVar1 = true;
  }
  return 0;
}



// Function: FUN_1000ff20 at 1000ff20

void FUN_1000ff20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uStack_dc;
  undefined4 local_c0;
  size_t local_bc;
  undefined1 local_b5;
  undefined1 *local_b4;
  void *local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_3c;
  undefined4 local_38 [7];
  uint local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100198c8;
  local_10 = ExceptionList;
  uStack_dc = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_dc;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_8 = 0;
  local_5c = *(int **)(param_1 + 0x1c4);
  local_60 = *local_5c;
  local_3c = local_60;
  local_1c = uStack_dc;
  while( true ) {
    local_68 = *(int *)(param_1 + 0x1c4);
    local_54 = local_68;
    if (local_3c == local_68) break;
    local_6c = *(int *)(param_1 + 0x1c4);
    local_58 = local_6c;
    if (local_3c != local_6c) {
      local_70 = local_3c + 0xc;
      local_74 = (void *)(local_3c + 0xc);
      iVar1 = *(int *)(local_3c + 0x20);
      puVar2 = (undefined4 *)FUN_10011b00((void *)(param_1 + 0x200),local_74);
      *puVar2 = *(undefined4 *)(param_1 + 0xc + iVar1 * 4);
    }
    local_64 = local_3c;
    FUN_1000e180(&local_3c);
    local_50 = local_64;
  }
  local_18 = 0;
  local_b4 = &local_b5;
  local_8._0_1_ = 1;
  FUN_10003400(local_38,'\0',0);
  FUN_10003040(local_38,(undefined4 *)&DAT_100248dc,0,0xffffffff);
  local_8._0_1_ = 2;
  local_bc = wcslen(L"\\system\\kernel");
  FUN_10002ed0(local_38,(undefined4 *)L"\\system\\kernel",local_bc);
  FUN_10001200(local_38);
  local_18 = FUN_10001220((void *)(param_1 + 0x1d0),(void *)(param_1 + 0x200),
                          *(undefined4 *)(param_1 + 0x1fc));
  if (local_18 < 0) {
    local_c0 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_c0,(ThrowInfo *)&DAT_10021ec4);
  }
  local_8._0_1_ = 3;
  FUN_10003400(local_38,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10010126();
  return;
}



// Function: Catch@100100fa at 100100fa

undefined4 Catch_100100fa(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001012d;
}



// Function: Catch@10010110 at 10010110

undefined4 Catch_10010110(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x48));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001012d;
}



// Function: FUN_10010126 at 10010126

void FUN_10010126(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10010148;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x18) ^ unaff_EBP);
  return;
}



// Function: FUN_10010150 at 10010150

void FUN_10010150(int param_1)

{
  uint uStack_3c;
  undefined4 local_2c [5];
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198f0;
  local_10 = ExceptionList;
  uStack_3c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_8 = 0;
  local_18 = FUN_10015e80((void *)(param_1 + 0x1e4),(void *)(param_1 + 0x200));
  if (local_18 < 0) {
    local_2c[0] = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10021ec4);
  }
  FUN_100101ed();
  return;
}



// Function: Catch@100101c1 at 100101c1

undefined4 Catch_100101c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100101f4;
}



// Function: Catch@100101d7 at 100101d7

undefined4 Catch_100101d7(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100101f4;
}



// Function: FUN_100101ed at 100101ed

undefined4 FUN_100101ed(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10010210 at 10010210

void FUN_10010210(int param_1,wchar_t *param_2,undefined4 param_3)

{
  size_t sVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019910;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1f8) = param_3;
  sVar1 = wcslen(param_2);
  FUN_10003510(&DAT_100248dc,(undefined4 *)param_2,sVar1);
  FUN_10011330((int *)(param_1 + 4));
  FUN_100102be();
  return;
}



// Function: Catch@10010292 at 10010292

undefined4 Catch_10010292(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x28) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100102c5;
}



// Function: Catch@100102a8 at 100102a8

undefined4 Catch_100102a8(void)

{
  int unaff_EBP;
  
  std::exception::~exception((exception *)(unaff_EBP + -0x34));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100102c5;
}



// Function: FUN_100102be at 100102be

undefined4 FUN_100102be(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100102e0 at 100102e0

void FUN_100102e0(void)

{
  size_t sVar1;
  LPCWSTR *local_2a0;
  LSTATUS local_280;
  undefined1 local_261;
  undefined1 *local_260;
  DWORD local_258;
  DWORD local_254;
  _FILETIME local_250;
  WCHAR local_248;
  undefined1 local_246 [514];
  DWORD local_44;
  LSTATUS local_40;
  LPCWSTR *local_3c [5];
  uint local_28;
  uint local_20;
  HKEY local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019950;
  local_10 = ExceptionList;
  local_20 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = 0;
  local_1c = (HKEY)0x0;
  local_18 = 0;
  local_14 = 0;
  local_260 = &local_261;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10003400(local_3c,'\0',0);
  FUN_10003040(local_3c,(undefined4 *)&DAT_100248dc,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  sVar1 = wcslen(L"\\system\\kernel\\ksp\\aggregate");
  FUN_10002ed0(local_3c,(undefined4 *)L"\\system\\kernel\\ksp\\aggregate",sVar1);
  if (local_28 < 8) {
    local_2a0 = (LPCWSTR *)local_3c;
  }
  else {
    local_2a0 = local_3c[0];
  }
  local_40 = FUN_10001950(&local_1c,(HKEY)0x80000002,(LPCWSTR)local_2a0,0x2001f);
  if (local_40 == 0) {
    local_254 = 0;
    local_250.dwLowDateTime = 0;
    local_250.dwHighDateTime = 0;
    local_248 = L'\0';
    memset(local_246,0,0x1fe);
    local_40 = RegQueryInfoKeyW(local_1c,&local_248,&local_254,(LPDWORD)0x0,&local_254,&local_254,
                                &local_254,&local_44,&local_254,&local_254,&local_254,&local_250);
    local_280 = 0;
    if (local_1c != (HKEY)0x0) {
      local_280 = RegCloseKey(local_1c);
      local_1c = (HKEY)0x0;
    }
    local_18 = 0;
    local_40 = local_280;
  }
  local_258 = local_44;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10003400(local_3c,'\x01',0);
  local_8 = 0xffffffff;
  if (local_1c != (HKEY)0x0) {
    RegCloseKey(local_1c);
    local_1c = (HKEY)0x0;
  }
  local_18 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010520 at 10010520

void __cdecl FUN_10010520(void *param_1)

{
  longlong lVar1;
  size_t sVar2;
  undefined4 *puVar3;
  LSTATUS local_330;
  LPCOLESTR *local_328;
  undefined1 local_30d;
  undefined1 *local_30c;
  HKEY local_304;
  LPCWSTR local_2f8;
  size_t local_2f4;
  undefined1 local_2ed;
  undefined1 *local_2ec;
  wchar_t *local_2e4;
  LPWSTR local_2e0;
  wchar_t *local_2dc;
  LPWSTR local_2d8;
  uint local_2d0;
  undefined4 local_2cc;
  HRESULT local_2c8;
  uint local_2c4;
  DWORD local_2c0;
  DWORD local_2bc [3];
  uint local_2b0;
  wchar_t *local_2ac;
  IID local_2a8;
  DWORD local_298;
  _FILETIME local_294;
  DWORD local_28c;
  DWORD local_288;
  DWORD local_284;
  LPWSTR local_280;
  LPCOLESTR *local_27c [5];
  uint local_268;
  WCHAR local_260;
  undefined1 local_25e [514];
  LSTATUS local_5c;
  undefined4 local_58 [7];
  HKEY local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100199d1;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = (HKEY)0x0;
  local_38 = 0;
  local_34 = 0;
  local_2ec = &local_2ed;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10003400(local_58,'\0',0);
  FUN_10003040(local_58,(undefined4 *)&DAT_100248dc,0,0xffffffff);
  local_8._0_1_ = 2;
  local_2f4 = wcslen(L"\\system\\kernel\\ksp\\aggregate");
  FUN_10002ed0(local_58,(undefined4 *)L"\\system\\kernel\\ksp\\aggregate",local_2f4);
  local_2f8 = (LPCWSTR)FUN_100034a0(local_58);
  local_5c = FUN_10001950(&local_3c,(HKEY)0x80000002,local_2f8,0x2001f);
  if (local_5c == 0) {
    local_298 = 0;
    local_294.dwLowDateTime = 0;
    local_294.dwHighDateTime = 0;
    local_260 = L'\0';
    memset(local_25e,0,0x1fe);
    local_288 = 0;
    local_28c = 0;
    local_284 = 0;
    local_304 = local_3c;
    local_5c = RegQueryInfoKeyW(local_3c,&local_260,&local_298,(LPDWORD)0x0,&local_298,&local_298,
                                &local_298,&local_288,&local_28c,&local_284,&local_298,&local_294);
    lVar1 = (ulonglong)(local_28c + 1) * 2;
    local_2d8 = (LPWSTR)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    lVar1 = (ulonglong)(local_284 + 1) * 2;
    local_280 = local_2d8;
    local_2dc = (wchar_t *)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
    ;
    local_30c = &local_30d;
    local_8._0_1_ = 3;
    local_2ac = local_2dc;
    FUN_10003400(local_27c,'\0',0);
    local_8._0_1_ = 4;
    local_2a8.Data1 = 0;
    local_2a8.Data2 = 0;
    local_2a8.Data3 = 0;
    local_2a8.Data4[0] = '\0';
    local_2a8.Data4[1] = '\0';
    local_2a8.Data4[2] = '\0';
    local_2a8.Data4[3] = '\0';
    local_2a8.Data4[4] = '\0';
    local_2a8.Data4[5] = '\0';
    local_2a8.Data4[6] = '\0';
    local_2a8.Data4[7] = '\0';
    local_2b0 = 0;
    while ((local_2b0 < local_288 && ((local_5c == 0xea || (local_5c == 0))))) {
      local_2bc[0] = local_28c + 1;
      local_2c0 = local_284 + 1;
      local_5c = RegEnumValueW(local_3c,local_2b0,local_280,local_2bc,(LPDWORD)0x0,&local_298,
                               (LPBYTE)local_2ac,&local_2c0);
      sVar2 = wcslen(local_2ac);
      FUN_10003510(local_27c,(undefined4 *)local_2ac,sVar2);
      sVar2 = wcslen(L"!");
      local_2d0 = FUN_10003260(local_27c,(ushort *)&DAT_1001c934,0,sVar2);
      local_2d0 = local_2d0 + 1;
      sVar2 = wcslen(L"!");
      local_2c4 = FUN_10003260(local_27c,(ushort *)&DAT_1001c934,local_2d0,sVar2);
      puVar3 = (undefined4 *)FUN_10002750(local_27c,local_30,local_2d0,local_2c4 - local_2d0);
      local_8._0_1_ = 5;
      FUN_10002cd0(local_27c,puVar3);
      local_8._0_1_ = 6;
      FUN_10003400(local_30,'\x01',0);
      local_8._0_1_ = 4;
      local_2cc = 3;
      if (local_268 < 8) {
        local_328 = (LPCOLESTR *)local_27c;
      }
      else {
        local_328 = local_27c[0];
      }
      local_2c8 = IIDFromString((LPCOLESTR)local_328,&local_2a8);
      if (-1 < local_2c8) {
        FUN_10011c30(param_1,&local_2a8.Data1);
      }
      local_2b0 = local_2b0 + 1;
    }
    local_2e0 = local_280;
    operator_delete__(local_280);
    local_2e4 = local_2ac;
    operator_delete__(local_2ac);
    local_330 = 0;
    if (local_3c != (HKEY)0x0) {
      local_330 = RegCloseKey(local_3c);
      local_3c = (HKEY)0x0;
    }
    local_38 = 0;
    local_5c = local_330;
    local_8._0_1_ = 7;
    FUN_10003400(local_27c,'\x01',0);
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_10003400(local_58,'\x01',0);
  local_8 = 0xffffffff;
  if (local_3c != (HKEY)0x0) {
    RegCloseKey(local_3c);
    local_3c = (HKEY)0x0;
  }
  local_38 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010a70 at 10010a70

void __thiscall FUN_10010a70(void *this,int *param_1)

{
  longlong lVar1;
  size_t sVar2;
  undefined4 *puVar3;
  LPCOLESTR lpsz;
  int *piVar4;
  uint *puVar5;
  LPUNKNOWN pIVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  LSTATUS local_40c;
  undefined1 local_351;
  undefined1 *local_350;
  HKEY local_348;
  LPCWSTR local_33c;
  size_t local_338;
  undefined1 local_331;
  undefined1 *local_330;
  HRESULT local_328;
  wchar_t *local_324;
  LPWSTR local_320;
  int local_31c;
  int local_318;
  wchar_t *local_314;
  LPWSTR local_310;
  uint local_308;
  undefined4 local_304;
  IUnknown *local_300;
  DWORD local_2fc;
  DWORD local_2f8 [3];
  uint local_2ec;
  wchar_t *local_2e8;
  DWORD local_2e4;
  CLSID local_2e0;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  _FILETIME local_2bc;
  DWORD local_2b4;
  DWORD local_2b0;
  DWORD local_2ac;
  LPWSTR local_2a8;
  undefined4 local_2a4 [7];
  WCHAR local_288;
  undefined1 local_286 [510];
  HRESULT local_88;
  LSTATUS local_84;
  undefined4 local_80 [7];
  HKEY local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58 [5];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019a7a;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = -0x7fffbffb;
  local_64 = (HKEY)0x0;
  local_60 = 0;
  local_5c = 0;
  local_330 = &local_331;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10003400(local_80,'\0',0);
  FUN_10003040(local_80,(undefined4 *)&DAT_100248dc,0,0xffffffff);
  local_8._0_1_ = 2;
  local_338 = wcslen(L"\\system\\kernel\\ksp\\aggregate");
  FUN_10002ed0(local_80,(undefined4 *)L"\\system\\kernel\\ksp\\aggregate",local_338);
  local_33c = (LPCWSTR)FUN_100034a0(local_80);
  local_84 = FUN_10001950(&local_64,(HKEY)0x80000002,local_33c,0x2001f);
  if (local_84 == 0) {
    local_2e4 = 0;
    local_2bc.dwLowDateTime = 0;
    local_2bc.dwHighDateTime = 0;
    local_288 = L'\0';
    memset(local_286,0,0x1fe);
    local_2b0 = 0;
    local_2b4 = 0;
    local_2ac = 0;
    local_348 = local_64;
    local_84 = RegQueryInfoKeyW(local_64,&local_288,&local_2e4,(LPDWORD)0x0,&local_2e4,&local_2e4,
                                &local_2e4,&local_2b0,&local_2b4,&local_2ac,&local_2e4,&local_2bc);
    lVar1 = (ulonglong)(local_2b4 + 1) * 2;
    local_310 = (LPWSTR)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    lVar1 = (ulonglong)(local_2ac + 1) * 2;
    local_2a8 = local_310;
    local_314 = (wchar_t *)FUN_100171f3(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
    ;
    local_350 = &local_351;
    local_8._0_1_ = 3;
    local_2e8 = local_314;
    FUN_10003400(local_2a4,'\0',0);
    local_8._0_1_ = 4;
    local_2e0.Data1 = 0;
    local_2e0.Data2 = 0;
    local_2e0.Data3 = 0;
    local_2e0.Data4[0] = '\0';
    local_2e0.Data4[1] = '\0';
    local_2e0.Data4[2] = '\0';
    local_2e0.Data4[3] = '\0';
    local_2e0.Data4[4] = '\0';
    local_2e0.Data4[5] = '\0';
    local_2e0.Data4[6] = '\0';
    local_2e0.Data4[7] = '\0';
    FUN_10016120(&local_2d0);
    local_8._0_1_ = 5;
    local_2ec = 0;
    while ((local_2ec < local_2b0 && ((local_84 == 0xea || (local_84 == 0))))) {
      local_300 = (IUnknown *)0x0;
      local_8._0_1_ = 7;
      local_2f8[0] = local_2b4 + 1;
      local_2fc = local_2ac + 1;
      local_84 = RegEnumValueW(local_64,local_2ec,local_2a8,local_2f8,(LPDWORD)0x0,&local_2e4,
                               (LPBYTE)local_2e8,&local_2fc);
      sVar2 = wcslen(local_2e8);
      FUN_10003510(local_2a4,(undefined4 *)local_2e8,sVar2);
      sVar2 = wcslen(L"!");
      local_308 = FUN_10003260(local_2a4,(ushort *)&DAT_1001c934,0,sVar2);
      puVar3 = (undefined4 *)FUN_10002750(local_2a4,local_30,0,local_308);
      local_8._0_1_ = 8;
      FUN_10002cd0(local_2a4,puVar3);
      local_8._0_1_ = 9;
      FUN_10003400(local_30,'\x01',0);
      local_8._0_1_ = 7;
      local_304 = 3;
      lpsz = (LPCOLESTR)FUN_100034a0(local_2a4);
      local_88 = CLSIDFromString(lpsz,&local_2e0);
      if (-1 < local_88) {
        FUN_10016190(&local_44,local_2e0.Data1,local_2e0._4_4_,local_2e0.Data4._0_4_,
                     local_2e0.Data4._4_4_);
        local_2cc = local_40;
        local_2c8 = local_3c;
        local_2c4 = local_38;
        local_2c0 = local_34;
        local_8._0_1_ = 7;
        FUN_10016220(&local_44);
        local_31c = *(int *)((int)this + 0x1bc);
        piVar4 = FUN_100119f0((void *)((int)this + 0x1b8),&local_318,&local_2d0);
        if (*piVar4 == local_31c) {
          puVar5 = (uint *)FUN_100118c0((void *)((int)this + 0x1b8),&local_2d0);
          *puVar5 = local_2ec;
          uVar7 = local_2e0.Data1;
          uVar8 = local_2e0._4_4_;
          uVar9 = local_2e0.Data4._0_4_;
          uVar10 = local_2e0.Data4._4_4_;
          pIVar6 = (LPUNKNOWN)(**(code **)(*(int *)((int)this + -0xc) + 0x10))();
          local_88 = FUN_10016b30(&local_300,pIVar6,uVar7,uVar8,uVar9,uVar10);
          if (-1 < local_88) {
            FUN_10011d10(param_1,(int *)&local_300);
          }
        }
        else {
          FUN_10016190(local_58,local_2e0.Data1,local_2e0._4_4_,local_2e0.Data4._0_4_,
                       local_2e0.Data4._4_4_);
          local_8 = CONCAT31(local_8._1_3_,0xb);
          piVar4 = (int *)FUN_100118c0((void *)((int)this + 0x1b8),local_58);
          piVar4 = (int *)(*param_1 + *piVar4 * 4);
          if (local_300 != (IUnknown *)*piVar4) {
            ATL::AtlComPtrAssign(&local_300,(IUnknown *)*piVar4);
          }
          local_8._0_1_ = 7;
          FUN_10016220(local_58);
          (*local_300->lpVtbl->AddRef)(local_300);
          FUN_10011d10(param_1,(int *)&local_300);
        }
      }
      local_8._0_1_ = 5;
      if (local_300 != (IUnknown *)0x0) {
        (*local_300->lpVtbl->Release)(local_300);
      }
      local_2ec = local_2ec + 1;
    }
    local_320 = local_2a8;
    operator_delete__(local_2a8);
    local_324 = local_2e8;
    operator_delete__(local_2e8);
    local_88 = 0;
    local_40c = 0;
    if (local_64 != (HKEY)0x0) {
      local_40c = RegCloseKey(local_64);
      local_64 = (HKEY)0x0;
    }
    local_60 = 0;
    local_84 = local_40c;
    local_8._0_1_ = 4;
    FUN_10016220(&local_2d0);
    local_8._0_1_ = 2;
    FUN_100026f0(local_2a4);
  }
  local_328 = local_88;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100026f0(local_80);
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_64);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: AtlComPtrAssign at 100111e0

/* Library Function - Single Match
    struct IUnknown * __stdcall ATL::AtlComPtrAssign(struct IUnknown * *,struct IUnknown *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

IUnknown * ATL::AtlComPtrAssign(IUnknown **param_1,IUnknown *param_2)

{
  if (param_1 == (IUnknown **)0x0) {
    param_2 = (IUnknown *)0x0;
  }
  else {
    if (param_2 != (IUnknown *)0x0) {
      (*param_2->lpVtbl->AddRef)(param_2);
    }
    if (*param_1 != (IUnknown *)0x0) {
      (*(*param_1)->lpVtbl->Release)(*param_1);
    }
    *param_1 = param_2;
  }
  return param_2;
}



// Function: FUN_10011230 at 10011230

undefined4 FUN_10011230(void)

{
  return 0;
}



// Function: FUN_10011240 at 10011240

void __fastcall FUN_10011240(int param_1)

{
  FUN_100117f0(param_1 + 0xc);
  return;
}



// Function: FUN_10011260 at 10011260

void __cdecl FUN_10011260(void *param_1)

{
  undefined1 local_55;
  undefined1 *local_54;
  undefined1 local_3d;
  undefined1 *local_3c;
  uint local_34;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10019ae9;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0;
  local_3c = &local_3d;
  local_8 = 1;
  FUN_10003400(local_30,'\0',0);
  local_54 = &local_55;
  local_8 = 3;
  FUN_10003400(param_1,'\0',0);
  FUN_10003040(param_1,(undefined4 *)&DAT_100248dc,0,0xffffffff);
  local_34 = local_34 | 1;
  local_8 = 4;
  FUN_10003400(local_30,'\x01',0);
  local_8 = local_8 & 0xffffff00;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10011330 at 10011330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_10011330(int *param_1)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_cd;
  undefined1 *local_cc;
  undefined4 *local_c4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 *local_84;
  undefined4 local_80;
  undefined4 *local_7c;
  undefined1 local_75;
  undefined1 *local_74;
  int *local_6c;
  int *local_68;
  int local_64;
  void *local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  code *local_2c;
  int local_28;
  undefined **local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10019b68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = &PTR_DAT_1001d17c;
  if ((DAT_10024868 & 1) == 0) {
    DAT_10024868 = DAT_10024868 | 1;
    local_8 = 0;
    FUN_10012950((_Container_base12 *)&DAT_10024850);
    local_8 = local_8 & 0xffffff00;
    _atexit(FUN_1001b1b0);
  }
  local_8 = 0xffffffff;
  for (local_14 = 0; local_24[local_14 * 3] != (undefined *)0x0; local_14 = local_14 + 1) {
    FUN_10012a60(&DAT_10024850,local_24 + local_14 * 3);
  }
  ppuVar1 = local_24 + local_14 * 3;
  local_20 = *ppuVar1;
  local_1c = ppuVar1[1];
  local_18 = ppuVar1[2];
  if ((DAT_10024868 & 2) == 0) {
    DAT_10024868 = DAT_10024868 | 2;
    local_74 = &local_75;
    DAT_10024840 = 0;
    DAT_10024844 = 0;
    _DAT_10024848 = 0;
    local_8 = 2;
    _atexit(FUN_1001b160);
    local_8 = 0xffffffff;
  }
  local_7c = FUN_10011f20(&DAT_10024840,&local_80);
  local_7c = (undefined4 *)*local_7c;
  local_84 = FUN_10011ef0(&DAT_10024840,&local_88);
  local_84 = (undefined4 *)*local_84;
  FUN_100124c0(&DAT_10024840,&local_8c,local_84,local_7c);
  FUN_10010520(&DAT_10024840);
  local_38 = 0;
  local_3c = DAT_10024840;
  while( true ) {
    local_94 = DAT_10024844;
    local_5c = DAT_10024844;
    if (local_3c == DAT_10024844) break;
    local_30 = local_38 * 4 + 0x10;
    local_34 = local_3c;
    local_2c = FUN_10011eb0;
    FUN_10012a60(&DAT_10024850,&local_34);
    local_38 = local_38 + 1;
    local_90 = local_3c;
    local_58 = local_3c;
    local_3c = local_3c + 0x10;
  }
  FUN_10012a60(&DAT_10024850,&local_20);
  if (DAT_1002483c != (void *)0x0) {
    local_60 = DAT_1002483c;
    operator_delete(DAT_1002483c);
  }
  local_98 = DAT_10024860;
  DAT_1002483c = (void *)FUN_100171f3(-(uint)((int)((ulonglong)DAT_10024860 * 0xc >> 0x20) != 0) |
                                      (uint)((ulonglong)DAT_10024860 * 0xc));
  local_9c = DAT_10024860;
  local_64 = (int)DAT_1002483c;
  local_14 = DAT_10024860;
  while( true ) {
    local_14 = local_14 - 1;
    local_a0 = DAT_10024860;
    if (DAT_10024860 == 0) break;
    local_c4 = (undefined4 *)FUN_100129b0(&DAT_10024850);
    puVar2 = (undefined4 *)(local_14 * 0xc + (int)DAT_1002483c);
    *puVar2 = *local_c4;
    puVar2[1] = local_c4[1];
    puVar2[2] = local_c4[2];
    FUN_10012b80(0x10024850);
  }
  DAT_10024798 = (int)DAT_1002483c;
  local_28 = 0x80004005;
  for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
    param_1[local_14 + 1] = 0;
  }
  uVar3 = (**(code **)(*param_1 + 4))();
  if (uVar3 < 0x65) {
    local_cc = &local_cd;
    local_4c = (int *)0x0;
    local_48 = (int *)0x0;
    local_44 = 0;
    local_8 = 5;
    local_28 = (**(code **)(*param_1 + 8))(&local_4c,&local_4c);
    if ((local_28 < 0) ||
       (iVar5 = (int)local_48 - (int)local_4c, iVar4 = (**(code **)(*param_1 + 4))(),
       iVar5 >> 2 != iVar4)) {
      local_28 = -0x7fffbffb;
    }
    else {
      local_50 = 0;
      for (local_54 = local_4c; local_6c = local_48, local_54 != local_48; local_54 = local_54 + 1)
      {
        iVar4 = *local_54;
        *local_54 = 0;
        param_1[local_50 + 1] = iVar4;
        local_50 = local_50 + 1;
        local_68 = local_54;
      }
    }
    local_8 = 6;
    FUN_10012890((_Container_base0 *)&local_4c);
  }
  else {
    local_28 = -0x7fffbffb;
  }
  ExceptionList = local_10;
  return local_28;
}



// Function: FUN_100117f0 at 100117f0

undefined4 __fastcall FUN_100117f0(int param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    if (*(int *)(param_1 + 4 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(param_1 + 4 + local_8 * 4) + 8))
                (*(undefined4 *)(param_1 + 4 + local_8 * 4));
    }
  }
  return 0;
}



// Function: FUN_10011850 at 10011850

int __fastcall FUN_10011850(int param_1)

{
  int iStack_4c;
  uint uStack_48;
  int local_40;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019ba0;
  local_10 = ExceptionList;
  uStack_48 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined1 *)&iStack_4c;
  local_1c = (undefined1 *)&iStack_4c;
  iStack_4c = param_1;
  local_40 = param_1;
  FUN_10012190(param_1);
  ExceptionList = local_10;
  return local_40;
}



// Function: FUN_100118c0 at 100118c0

void __thiscall FUN_100118c0(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 local_2c [5];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019be8;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = FUN_10012120(this,(int)param_1);
  local_34 = *(undefined4 **)((int)this + 4);
  if (local_30 != local_34) {
    cVar1 = FUN_100162b0(param_1,(int)(local_30 + 3));
    if (cVar1 == '\0') goto LAB_100119c2;
  }
  local_38 = 0;
  local_3c = local_30;
  FUN_100161d0(local_2c,(int)param_1);
  local_18 = local_38;
  local_8 = 2;
  piVar2 = (int *)FUN_10015550(this,(int)local_2c);
  FUN_10013d30(this,(int *)&local_40,local_3c,piVar2);
  local_30 = local_40;
  local_8 = 0xffffffff;
  FUN_10016220(local_2c);
LAB_100119c2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100119f0 at 100119f0

int * __thiscall FUN_100119f0(void *this,int *param_1,void *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *local_34;
  int local_14;
  int local_10;
  int local_8;
  
  puVar2 = FUN_10012120(this,(int)param_2);
  FUN_10012e30(&local_8,puVar2);
  local_10 = *(int *)((int)this + 4);
  if (local_8 != local_10) {
    cVar1 = FUN_100162b0(param_2,local_8 + 0xc);
    if (cVar1 == '\0') {
      local_34 = &local_8;
      goto LAB_10011a72;
    }
  }
  local_34 = &local_14;
LAB_10011a72:
  *param_1 = *local_34;
  return param_1;
}



// Function: FUN_10011a90 at 10011a90

int __fastcall FUN_10011a90(int param_1)

{
  int iStack_4c;
  uint uStack_48;
  int local_40;
  undefined1 *local_1c;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019c20;
  local_10 = ExceptionList;
  uStack_48 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined1 *)&iStack_4c;
  local_1c = (undefined1 *)&iStack_4c;
  iStack_4c = param_1;
  local_40 = param_1;
  FUN_10012280(param_1);
  ExceptionList = local_10;
  return local_40;
}



// Function: FUN_10011b00 at 10011b00

void __thiscall FUN_10011b00(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 local_2c [5];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019c68;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = FUN_10012210(this,(int)param_1);
  local_34 = *(undefined4 **)((int)this + 4);
  if (local_30 != local_34) {
    cVar1 = FUN_100162b0(param_1,(int)(local_30 + 3));
    if (cVar1 == '\0') goto LAB_10011c02;
  }
  local_38 = 0;
  local_3c = local_30;
  FUN_100161d0(local_2c,(int)param_1);
  local_18 = local_38;
  local_8 = 2;
  piVar2 = (int *)FUN_100155f0(this,(int)local_2c);
  FUN_10014360(this,(int *)&local_40,local_3c,piVar2);
  local_30 = local_40;
  local_8 = 0xffffffff;
  FUN_10016220(local_2c);
LAB_10011c02:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10011c30 at 10011c30

void __thiscall FUN_10011c30(void *this,undefined4 *param_1)

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
      FUN_10011f50(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10013560((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(((int)param_1 - iVar1 >> 4) * 0x10 + *this));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  }
  else {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10011f50(this,1);
    }
    FUN_100135e0((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  }
  return;
}



// Function: FUN_10011d10 at 10011d10

void __thiscall FUN_10011d10(void *this,int *param_1)

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
      FUN_10012030(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10013670((int)this + 0xc,*(int **)((int)this + 4),
                 (int *)(*this + ((int)param_1 - iVar1 >> 2) * 4));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  else {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10012030(this,1);
    }
    FUN_10013710((int)this + 0xc,*(int **)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  return;
}



// Function: FUN_10011df0 at 10011df0

void __fastcall FUN_10011df0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011e50 at 10011e50

void __fastcall FUN_10011e50(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011eb0 at 10011eb0

undefined4 FUN_10011eb0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  local_c = 0x80004002;
  puVar1 = *(undefined4 **)(param_1 + param_4);
  if (puVar1 != (undefined4 *)0x0) {
    local_c = (**(code **)*puVar1)(puVar1,param_2,param_3);
  }
  return local_c;
}



// Function: FUN_10011ef0 at 10011ef0

undefined4 * __thiscall FUN_10011ef0(void *this,undefined4 *param_1)

{
                    /* WARNING: Load size is inaccurate */
  *param_1 = *this;
  return param_1;
}



// Function: FUN_10011f20 at 10011f20

undefined4 * __thiscall FUN_10011f20(void *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)((int)this + 4);
  return param_1;
}



// Function: FUN_10011f50 at 10011f50

/* WARNING: Removing unreachable block (ram,0x10011f7f) */

void __thiscall FUN_10011f50(void *this,int param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 4) - *this >> 4;
  if (0xfffffffU - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
  }
  else {
    uVar1 = uVar1 + param_1;
                    /* WARNING: Load size is inaccurate */
    if ((uint)(*(int *)((int)this + 8) - *this >> 4) < uVar1) {
      uVar1 = FUN_100125c0(this,uVar1);
      FUN_10012300(this,uVar1);
    }
  }
  return;
}



// Function: FUN_10011fe0 at 10011fe0

void __fastcall FUN_10011fe0(_Container_base0 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10012890(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012030 at 10012030

/* WARNING: Removing unreachable block (ram,0x1001205f) */

void __thiscall FUN_10012030(void *this,int param_1)

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
      uVar1 = FUN_10012810(this,uVar1);
      FUN_10012650(this,uVar1);
    }
  }
  return;
}



// Function: FUN_100120c0 at 100120c0

void __fastcall FUN_100120c0(_Container_base12 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019d28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10012c30((int)param_1);
  local_8 = 0xffffffff;
  FUN_10012d00(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012120 at 10012120

undefined4 * __thiscall FUN_10012120(void *this,int param_1)

{
  char cVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_8 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x25) == '\0') {
    cVar1 = FUN_100162b0(local_c + 3,param_1);
    if (cVar1 == '\0') {
      local_8 = local_c;
      local_c = (undefined4 *)*local_c;
    }
    else {
      local_c = (undefined4 *)local_c[2];
    }
  }
  return local_8;
}



// Function: FUN_10012190 at 10012190

int __fastcall FUN_10012190(int param_1)

{
  void *pvVar1;
  undefined1 local_d;
  undefined1 *local_c;
  
  local_c = &local_d;
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_100137e0(1);
  *(void **)(param_1 + 4) = pvVar1;
  **(undefined4 **)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x24) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x25) = 1;
  return param_1;
}



// Function: FUN_10012210 at 10012210

undefined4 * __thiscall FUN_10012210(void *this,int param_1)

{
  char cVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_8 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)local_c + 0x25) == '\0') {
    cVar1 = FUN_100162b0(local_c + 3,param_1);
    if (cVar1 == '\0') {
      local_8 = local_c;
      local_c = (undefined4 *)*local_c;
    }
    else {
      local_c = (undefined4 *)local_c[2];
    }
  }
  return local_8;
}



// Function: FUN_10012280 at 10012280

int __fastcall FUN_10012280(int param_1)

{
  void *pvVar1;
  undefined1 local_d;
  undefined1 *local_c;
  
  local_c = &local_d;
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10013890(1);
  *(void **)(param_1 + 4) = pvVar1;
  **(undefined4 **)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x24) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x25) = 1;
  return param_1;
}



// Function: FUN_10012300 at 10012300

/* WARNING: Removing unreachable block (ram,0x10012344) */

void __thiscall FUN_10012300(void *this,uint param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019d50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 0x10000000) {
                    /* WARNING: Load size is inaccurate */
    if ((uint)(*(int *)((int)this + 8) - *this >> 4) < param_1) {
      puVar1 = (undefined4 *)FUN_10013940(param_1);
      local_8 = 0;
                    /* WARNING: Load size is inaccurate */
      FUN_100158f0(*this,*(undefined4 **)((int)this + 4),puVar1,(int)this + 0xc);
      FUN_100123ef();
      return;
    }
  }
  else {
    std::_Xlength_error("vector<T> too long");
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@100123cd at 100123cd

void Catch_100123cd(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100123ef at 100123ef

void FUN_100123ef(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x18) =
       *(int *)(*(int *)(unaff_EBP + -0x54) + 4) - **(int **)(unaff_EBP + -0x54) >> 4;
  if (**(int **)(unaff_EBP + -0x54) != 0) {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x54) + 4);
    *(undefined4 *)(unaff_EBP + -0x44) = **(undefined4 **)(unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -0x39) = *(undefined1 *)(unaff_EBP + -0x3a);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x44);
    while (*(int *)(unaff_EBP + -0x40) != *(int *)(unaff_EBP + -0x48)) {
      FUN_10015a90();
      *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 0x10;
    }
    *(int *)(unaff_EBP + -0x50) =
         *(int *)(*(int *)(unaff_EBP + -0x54) + 8) - **(int **)(unaff_EBP + -0x54) >> 4;
    *(undefined4 *)(unaff_EBP + -0x4c) = **(undefined4 **)(unaff_EBP + -0x54);
    operator_delete(*(void **)(unaff_EBP + -0x4c));
  }
  std::_Container_base0::_Orphan_all(*(_Container_base0 **)(unaff_EBP + -0x54));
  *(int *)(*(int *)(unaff_EBP + -0x54) + 8) =
       *(int *)(unaff_EBP + 8) * 0x10 + *(int *)(unaff_EBP + -0x14);
  *(int *)(*(int *)(unaff_EBP + -0x54) + 4) =
       *(int *)(unaff_EBP + -0x18) * 0x10 + *(int *)(unaff_EBP + -0x14);
  **(undefined4 **)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100124c0 at 100124c0

undefined4 * __thiscall
FUN_100124c0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *local_34;
  undefined4 *local_20;
  undefined4 *local_1c;
  
  if (param_2 != param_3) {
    puVar1 = *(undefined4 **)((int)this + 4);
    local_20 = param_2;
    for (local_1c = param_3; local_1c != puVar1; local_1c = local_1c + 4) {
      *local_20 = *local_1c;
      local_20[1] = local_1c[1];
      local_20[2] = local_1c[2];
      local_20[3] = local_1c[3];
      local_20 = local_20 + 4;
    }
    puVar1 = *(undefined4 **)((int)this + 4);
    for (local_34 = local_20; local_34 != puVar1; local_34 = local_34 + 4) {
      FUN_10015a90();
    }
    *(undefined4 **)((int)this + 4) = local_20;
  }
  *param_1 = param_2;
  return param_1;
}



// Function: FUN_100125c0 at 100125c0

/* WARNING: Removing unreachable block (ram,0x100125ef) */

uint __thiscall FUN_100125c0(void *this,uint param_1)

{
  undefined4 local_18;
  undefined4 local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_18 = *(int *)((int)this + 8) - *this >> 4;
  if (0xfffffff - (local_18 >> 1) < local_18) {
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



// Function: FUN_10012640 at 10012640

void FUN_10012640(void)

{
  return;
}



// Function: FUN_10012650 at 10012650

/* WARNING: Removing unreachable block (ram,0x10012694) */

void __thiscall FUN_10012650(void *this,uint param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019d70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 0x40000000) {
                    /* WARNING: Load size is inaccurate */
    if ((uint)(*(int *)((int)this + 8) - *this >> 2) < param_1) {
      puVar1 = (undefined4 *)FUN_100139f0(param_1);
      local_8 = 0;
                    /* WARNING: Load size is inaccurate */
      FUN_100159c0(*this,*(undefined4 **)((int)this + 4),puVar1,(int)this + 0xc);
      FUN_1001273f();
      return;
    }
  }
  else {
    std::_Xlength_error("vector<T> too long");
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001271d at 1001271d

void Catch_1001271d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001273f at 1001273f

void FUN_1001273f(void)

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
      FUN_10015aa0(*(int *)(unaff_EBP + -0x54) + 0xc,*(int **)(unaff_EBP + -0x40));
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



// Function: FUN_10012810 at 10012810

/* WARNING: Removing unreachable block (ram,0x1001283f) */

uint __thiscall FUN_10012810(void *this,uint param_1)

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



// Function: FUN_10012890 at 10012890

void __fastcall FUN_10012890(_Container_base0 *param_1)

{
  int *piVar1;
  int *local_c;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    piVar1 = *(int **)(param_1 + 4);
    for (local_c = *(int **)param_1; local_c != piVar1; local_c = local_c + 1) {
      FUN_10015aa0(param_1 + 0xc,local_c);
    }
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10012940 at 10012940

void FUN_10012940(void)

{
  return;
}



// Function: FUN_10012950 at 10012950

_Container_base12 * __fastcall FUN_10012950(_Container_base12 *param_1)

{
  _Container_base12 *p_Stack_48;
  uint uStack_44;
  _Container_base12 *local_3c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019d98;
  local_10 = ExceptionList;
  uStack_44 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (undefined1 *)&p_Stack_48;
  local_18 = (undefined1 *)&p_Stack_48;
  p_Stack_48 = param_1;
  local_3c = param_1;
  FUN_100132b0(param_1);
  ExceptionList = local_10;
  return local_3c;
}



// Function: FUN_100129b0 at 100129b0

undefined4 __fastcall FUN_100129b0(void *param_1)

{
  undefined4 *this;
  int *piVar1;
  undefined4 uVar2;
  int local_2c [3];
  undefined4 local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019df0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = FUN_10012e50(param_1,local_20);
  local_8 = 0;
  piVar1 = FUN_10013370(this,local_2c,1);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar2 = FUN_100134e0(piVar1);
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10012a50 at 10012a50

void FUN_10012a50(void)

{
  return;
}



// Function: FUN_10012a60 at 10012a60

void __thiscall FUN_10012a60(void *this,undefined4 *param_1)

{
  void *pvVar1;
  undefined4 local_c;
  
  std::_Container_base12::_Orphan_all((_Container_base12 *)this);
  if (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 1U) {
    FUN_10012f00(this,1);
  }
  local_c = *(int *)((int)this + 0xc) + *(int *)((int)this + 0x10);
  if (*(uint *)((int)this + 8) <= local_c) {
    local_c = local_c - *(int *)((int)this + 8);
  }
  if (*(int *)(*(int *)((int)this + 4) + local_c * 4) == 0) {
    pvVar1 = FUN_10013b20(1);
    *(void **)(*(int *)((int)this + 4) + local_c * 4) = pvVar1;
  }
  FUN_10013730((int)this + 0x14,*(undefined4 **)(*(int *)((int)this + 4) + local_c * 4),param_1);
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  return;
}



// Function: FUN_10012b80 at 10012b80

void __fastcall FUN_10012b80(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100137b0();
    iVar1 = *(int *)(param_1 + 0x10) + -1;
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return;
}



// Function: FUN_10012c30 at 10012c30

void __fastcall FUN_10012c30(int param_1)

{
  undefined4 local_8;
  
  while (*(int *)(param_1 + 0x10) != 0) {
    FUN_10012b80(param_1);
  }
  local_8 = *(int *)(param_1 + 8);
  while (local_8 != 0) {
    local_8 = local_8 + -1;
    if (*(int *)(*(int *)(param_1 + 4) + local_8 * 4) != 0) {
      operator_delete(*(void **)(*(int *)(param_1 + 4) + local_8 * 4));
      FUN_100137c0();
    }
  }
  if (*(int *)(param_1 + 4) != 0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



// Function: FUN_10012d00 at 10012d00

void __fastcall FUN_10012d00(_Container_base12 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  std::_Container_base12::_Orphan_all(param_1);
  FUN_100137d0();
  operator_delete(*(void **)param_1);
  *(undefined4 *)param_1 = 0;
  local_8 = 0xffffffff;
  std::_Container_base12::~_Container_base12(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012d90 at 10012d90

void FUN_10012d90(void)

{
  return;
}



// Function: FUN_10012de0 at 10012de0

void FUN_10012de0(void)

{
  return;
}



// Function: FUN_10012e30 at 10012e30

undefined4 * __thiscall FUN_10012e30(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10012e50 at 10012e50

undefined4 * __thiscall FUN_10012e50(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)this + 0xc);
  iVar2 = *(int *)((int)this + 0x10);
  *param_1 = 0;
  param_1[1] = 0;
  if (this != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
  }
  param_1[2] = iVar1 + iVar2;
  return param_1;
}



// Function: FUN_10012f00 at 10012f00

/* WARNING: Removing unreachable block (ram,0x10012f27) */
/* WARNING: Removing unreachable block (ram,0x10012f8b) */

void __thiscall FUN_10012f00(void *this,uint param_1)

{
  undefined4 *_Dst;
  void *pvVar1;
  int iVar2;
  uint local_a0;
  undefined4 *local_9c;
  uint local_70;
  undefined4 *local_6c;
  int local_60;
  undefined4 *local_5c;
  uint local_c;
  
  if (0x15555555U - *(int *)((int)this + 8) < param_1) {
    std::_Xlength_error("deque<T> too long");
  }
  local_c = *(uint *)((int)this + 8) >> 1;
  if (local_c < 8) {
    local_c = 8;
  }
  if ((param_1 < local_c) && (*(uint *)((int)this + 8) <= 0x15555555 - local_c)) {
    param_1 = local_c;
  }
  local_70 = *(uint *)((int)this + 0xc);
  _Dst = (undefined4 *)FUN_10013bd0(*(int *)((int)this + 8) + param_1);
  pvVar1 = (void *)(*(int *)((int)this + 4) + local_70 * 4);
  iVar2 = (*(int *)((int)this + 4) + *(int *)((int)this + 8) * 4) - (int)pvVar1 >> 2;
  pvVar1 = memmove(_Dst + local_70,pvVar1,iVar2 << 2);
  pvVar1 = (void *)((int)pvVar1 + iVar2 * 4);
  if (param_1 < local_70) {
    memmove(pvVar1,*(void **)((int)this + 4),
            ((int)((*(int *)((int)this + 4) + param_1 * 4) - (int)*(void **)((int)this + 4)) >> 2)
            << 2);
    pvVar1 = (void *)(*(int *)((int)this + 4) + param_1 * 4);
    iVar2 = (int)((*(int *)((int)this + 4) + local_70 * 4) - (int)pvVar1) >> 2;
    pvVar1 = memmove(_Dst,pvVar1,iVar2 << 2);
    local_9c = (undefined4 *)((int)pvVar1 + iVar2 * 4);
    for (local_a0 = param_1; local_a0 != 0; local_a0 = local_a0 - 1) {
      *local_9c = 0;
      local_9c = local_9c + 1;
    }
  }
  else {
    iVar2 = (int)((*(int *)((int)this + 4) + local_70 * 4) - (int)*(void **)((int)this + 4)) >> 2;
    pvVar1 = memmove(pvVar1,*(void **)((int)this + 4),iVar2 << 2);
    local_5c = (undefined4 *)((int)pvVar1 + iVar2 * 4);
    for (local_60 = param_1 - local_70; local_6c = _Dst, local_60 != 0; local_60 = local_60 + -1) {
      *local_5c = 0;
      local_5c = local_5c + 1;
    }
    for (; local_70 != 0; local_70 = local_70 - 1) {
      *local_6c = 0;
      local_6c = local_6c + 1;
    }
  }
  if (*(int *)((int)this + 4) != 0) {
    operator_delete(*(void **)((int)this + 4));
  }
  *(undefined4 **)((int)this + 4) = _Dst;
  *(uint *)((int)this + 8) = *(int *)((int)this + 8) + param_1;
  return;
}



// Function: FUN_100132b0 at 100132b0

_Container_base12 * __fastcall FUN_100132b0(_Container_base12 *param_1)

{
  void *pvVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019ef9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Container_base12::_Container_base12(param_1);
  local_8 = 0;
  pvVar1 = FUN_10013c80(1);
  *(void **)param_1 = pvVar1;
  local_1c = 0;
  local_18 = 0;
  FUN_10013aa0(&local_11,*(undefined4 **)param_1,&local_1c);
  **(undefined4 **)param_1 = param_1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013370 at 10013370

int * __thiscall FUN_10013370(void *this,int *param_1,int param_2)

{
  int *local_1c [2];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f61;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10013440(local_1c,(int *)this);
  *param_1 = 0;
  param_1[1] = 0;
  if (((int *)*param_1 != local_1c[0]) && ((int *)*local_1c[0] != (int *)0x0)) {
    *param_1 = *(int *)*local_1c[0];
  }
  param_1[2] = local_14 - param_2;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013440 at 10013440

int * __thiscall FUN_10013440(void *this,int *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*this != *param_1) && (*(undefined4 **)*param_1 != (undefined4 *)0x0)) {
    *(undefined4 *)this = **(undefined4 **)*param_1;
  }
  *(int *)((int)this + 8) = param_1[2];
  return (int *)this;
}



// Function: FUN_100134e0 at 100134e0

undefined4 __fastcall FUN_100134e0(int *param_1)

{
  int local_18;
  uint local_8;
  
  if (*param_1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = *(int *)*param_1;
  }
  local_8 = param_1[2];
  if (*(uint *)(local_18 + 8) <= local_8) {
    local_8 = local_8 - *(int *)(local_18 + 8);
  }
  return *(undefined4 *)(*(int *)(local_18 + 4) + local_8 * 4);
}



// Function: FUN_10013560 at 10013560

void __cdecl FUN_10013560(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
  }
  return;
}



// Function: FUN_100135e0 at 100135e0

void __cdecl FUN_100135e0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
  }
  return;
}



// Function: FUN_10013670 at 10013670

void __cdecl FUN_10013670(undefined4 param_1,int *param_2,int *param_3)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a029;
  local_10 = ExceptionList;
  uVar1 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((param_2 != (int *)0x0) && (*param_2 = *param_3, *param_2 != 0)) {
    (**(code **)(*(int *)*param_2 + 4))(*param_2,uVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013710 at 10013710

void __cdecl FUN_10013710(undefined4 param_1,int *param_2,int *param_3)

{
  FUN_10015690(param_2,param_3);
  return;
}



// Function: FUN_10013730 at 10013730

void __cdecl FUN_10013730(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
  }
  return;
}



// Function: FUN_100137b0 at 100137b0

void FUN_100137b0(void)

{
  return;
}



// Function: FUN_100137c0 at 100137c0

void FUN_100137c0(void)

{
  return;
}



// Function: FUN_100137d0 at 100137d0

void FUN_100137d0(void)

{
  return;
}



// Function: FUN_100137e0 at 100137e0

void * __cdecl FUN_100137e0(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a089;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x6666666 < param_1 || (local_14 = operator_new(param_1 * 0x28), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013890 at 10013890

void * __cdecl FUN_10013890(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a0b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x6666666 < param_1 || (local_14 = operator_new(param_1 * 0x28), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013940 at 10013940

void * __cdecl FUN_10013940(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a0e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0xfffffff < param_1 || (local_14 = operator_new(param_1 << 4), local_14 == (void *)0x0)))) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100139f0 at 100139f0

void * __cdecl FUN_100139f0(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a119;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3fffffff < param_1 || (local_14 = operator_new(param_1 << 2), local_14 == (void *)0x0)))) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013aa0 at 10013aa0

void __cdecl FUN_10013aa0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    *param_2 = *param_3;
    param_2[1] = uVar1;
  }
  return;
}



// Function: FUN_10013b20 at 10013b20

void * __cdecl FUN_10013b20(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a179;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x15555555 < param_1 || (local_14 = operator_new(param_1 * 0xc), local_14 == (void *)0x0))))
  {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013bd0 at 10013bd0

void * __cdecl FUN_10013bd0(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a1a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3fffffff < param_1 || (local_14 = operator_new(param_1 << 2), local_14 == (void *)0x0)))) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013c80 at 10013c80

void * __cdecl FUN_10013c80(uint param_1)

{
  char *local_24;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a1d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x1fffffff < param_1 || (local_14 = operator_new(param_1 << 3), local_14 == (void *)0x0)))) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_24);
    local_20[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_100209f0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10013d30 at 10013d30

/* WARNING: Removing unreachable block (ram,0x10013d99) */
/* WARNING: Removing unreachable block (ram,0x10013e18) */
/* WARNING: Removing unreachable block (ram,0x10013eb7) */
/* WARNING: Removing unreachable block (ram,0x10013edd) */
/* WARNING: Removing unreachable block (ram,0x10013f0d) */
/* WARNING: Removing unreachable block (ram,0x10013f4a) */
/* WARNING: Removing unreachable block (ram,0x10013f27) */
/* WARNING: Removing unreachable block (ram,0x10013f70) */
/* WARNING: Removing unreachable block (ram,0x10013f96) */
/* WARNING: Removing unreachable block (ram,0x10013fdb) */
/* WARNING: Removing unreachable block (ram,0x10013ffd) */
/* WARNING: Removing unreachable block (ram,0x1001403a) */
/* WARNING: Removing unreachable block (ram,0x10014017) */
/* WARNING: Removing unreachable block (ram,0x1001405d) */
/* WARNING: Removing unreachable block (ram,0x10013e4f) */
/* WARNING: Removing unreachable block (ram,0x10013e88) */
/* WARNING: Removing unreachable block (ram,0x10013eb2) */
/* WARNING: Removing unreachable block (ram,0x10013dd2) */
/* WARNING: Removing unreachable block (ram,0x10013dee) */
/* WARNING: Removing unreachable block (ram,0x10013e0f) */
/* WARNING: Removing unreachable block (ram,0x10014061) */

int * __thiscall FUN_10013d30(void *this,int *param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int local_30 [2];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20 [4];
  int *local_10;
  char local_9;
  undefined4 *local_8;
  
  local_10 = param_3 + 3;
  local_8 = (undefined4 *)0x0;
  local_9 = '\0';
  if (*(int *)((int)this + 8) == 0) {
    FUN_10014bd0(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
  }
  else {
    FUN_10012e30(local_20,**(undefined4 **)((int)this + 4));
    if (param_2 == local_20[0]) {
      cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
      if (cVar1 != '\0') {
        FUN_10014bd0(this,param_1,'\x01',param_2,param_3);
        return param_1;
      }
    }
    else {
      FUN_10012e30(&local_24,*(undefined4 *)((int)this + 4));
      if (param_2 == local_24) {
        cVar1 = FUN_100162b0((void *)(*(int *)(*(int *)((int)this + 4) + 8) + 0xc),(int)local_10);
        if (cVar1 != '\0') {
          FUN_10014bd0(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),param_3);
          return param_1;
        }
      }
      else {
        cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_100153d0((int *)&local_8);
          cVar1 = FUN_100162b0(local_8 + 3,(int)local_10);
          if (cVar1 != '\0') {
            if (*(char *)(local_8[2] + 0x25) != '\0') {
              FUN_10014bd0(this,param_1,'\0',local_8,param_3);
              return param_1;
            }
            FUN_10014bd0(this,param_1,'\x01',param_2,param_3);
            return param_1;
          }
        }
        cVar1 = FUN_100162b0(param_2 + 3,(int)local_10);
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_10012e30(&local_28,*(undefined4 *)((int)this + 4));
          FUN_1000e180((int *)&local_8);
          if ((local_8 == local_28) ||
             (cVar1 = FUN_100162b0(local_10,(int)(local_8 + 3)), cVar1 != '\0')) {
            if (*(char *)(param_2[2] + 0x25) != '\0') {
              FUN_10014bd0(this,param_1,'\0',param_2,param_3);
              return param_1;
            }
            FUN_10014bd0(this,param_1,'\x01',local_8,param_3);
            return param_1;
          }
        }
      }
    }
    piVar2 = FUN_10014990(this,local_30,param_3,local_9);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_10014360 at 10014360

/* WARNING: Removing unreachable block (ram,0x100143c9) */
/* WARNING: Removing unreachable block (ram,0x10014448) */
/* WARNING: Removing unreachable block (ram,0x100144e7) */
/* WARNING: Removing unreachable block (ram,0x1001450d) */
/* WARNING: Removing unreachable block (ram,0x1001453d) */
/* WARNING: Removing unreachable block (ram,0x1001457a) */
/* WARNING: Removing unreachable block (ram,0x10014557) */
/* WARNING: Removing unreachable block (ram,0x100145a0) */
/* WARNING: Removing unreachable block (ram,0x100145c6) */
/* WARNING: Removing unreachable block (ram,0x1001460b) */
/* WARNING: Removing unreachable block (ram,0x1001462d) */
/* WARNING: Removing unreachable block (ram,0x1001466a) */
/* WARNING: Removing unreachable block (ram,0x10014647) */
/* WARNING: Removing unreachable block (ram,0x1001468d) */
/* WARNING: Removing unreachable block (ram,0x1001447f) */
/* WARNING: Removing unreachable block (ram,0x100144b8) */
/* WARNING: Removing unreachable block (ram,0x100144e2) */
/* WARNING: Removing unreachable block (ram,0x10014402) */
/* WARNING: Removing unreachable block (ram,0x1001441e) */
/* WARNING: Removing unreachable block (ram,0x1001443f) */
/* WARNING: Removing unreachable block (ram,0x10014691) */

int * __thiscall FUN_10014360(void *this,int *param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int local_30 [2];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20 [4];
  int *local_10;
  char local_9;
  undefined4 *local_8;
  
  local_10 = param_3 + 3;
  local_8 = (undefined4 *)0x0;
  local_9 = '\0';
  if (*(int *)((int)this + 8) == 0) {
    FUN_100150f0(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
  }
  else {
    FUN_10004160(local_20,**(undefined4 **)((int)this + 4));
    if (param_2 == local_20[0]) {
      cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
      if (cVar1 != '\0') {
        FUN_100150f0(this,param_1,'\x01',param_2,param_3);
        return param_1;
      }
    }
    else {
      FUN_10004160(&local_24,*(undefined4 *)((int)this + 4));
      if (param_2 == local_24) {
        cVar1 = FUN_100162b0((void *)(*(int *)(*(int *)((int)this + 4) + 8) + 0xc),(int)local_10);
        if (cVar1 != '\0') {
          FUN_100150f0(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),param_3);
          return param_1;
        }
      }
      else {
        cVar1 = FUN_100162b0(local_10,(int)(param_2 + 3));
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_10015490((int *)&local_8);
          cVar1 = FUN_100162b0(local_8 + 3,(int)local_10);
          if (cVar1 != '\0') {
            if (*(char *)(local_8[2] + 0x25) != '\0') {
              FUN_100150f0(this,param_1,'\0',local_8,param_3);
              return param_1;
            }
            FUN_100150f0(this,param_1,'\x01',param_2,param_3);
            return param_1;
          }
        }
        cVar1 = FUN_100162b0(param_2 + 3,(int)local_10);
        if (cVar1 != '\0') {
          local_8 = param_2;
          FUN_10004160(&local_28,*(undefined4 *)((int)this + 4));
          FUN_1000e230((int *)&local_8);
          if ((local_8 == local_28) ||
             (cVar1 = FUN_100162b0(local_10,(int)(local_8 + 3)), cVar1 != '\0')) {
            if (*(char *)(param_2[2] + 0x25) != '\0') {
              FUN_100150f0(this,param_1,'\0',param_2,param_3);
              return param_1;
            }
            FUN_100150f0(this,param_1,'\x01',local_8,param_3);
            return param_1;
          }
        }
      }
    }
    piVar2 = FUN_10014eb0(this,local_30,param_3,local_9);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_10014990 at 10014990

/* WARNING: Removing unreachable block (ram,0x10014a40) */

int * __thiscall FUN_10014990(void *this,int *param_1,int *param_2,char param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_98;
  undefined4 local_34;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined1 local_25;
  int local_24 [3];
  int local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  char local_5;
  
  local_14 = param_2 + 3;
  local_10 = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_c = *(undefined4 **)((int)this + 4);
  local_5 = '\x01';
  while (*(char *)((int)local_10 + 0x25) == '\0') {
    local_c = local_10;
    if (param_3 == '\0') {
      local_5 = FUN_100162b0(local_14,(int)(local_10 + 3));
    }
    else {
      cVar1 = FUN_100162b0(local_10 + 3,(int)local_14);
      local_5 = '\x01' - (cVar1 != '\0');
    }
    if (local_5 == '\0') {
      local_98 = (undefined4 *)local_10[2];
    }
    else {
      local_98 = (undefined4 *)*local_10;
    }
    local_10 = local_98;
  }
  FUN_10012e30(&local_18,local_c);
  if (local_5 != '\0') {
    FUN_10012e30(local_24,**(undefined4 **)((int)this + 4));
    if (local_18 == local_24[0]) {
      local_25 = 1;
      piVar2 = FUN_10014bd0(this,&local_2c,'\x01',local_c,param_2);
      *param_1 = *piVar2;
      *(undefined1 *)(param_1 + 1) = local_25;
      return param_1;
    }
    FUN_100153d0(&local_18);
  }
  cVar1 = FUN_100162b0((void *)(local_18 + 0xc),(int)local_14);
  if (cVar1 == '\0') {
    FUN_1000e2e0((int)this + 0xd,param_2 + 3);
    operator_delete(param_2);
    *param_1 = local_18;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    local_2d = 1;
    piVar2 = FUN_10014bd0(this,&local_34,local_5,local_c,param_2);
    *param_1 = *piVar2;
    *(undefined1 *)(param_1 + 1) = local_2d;
  }
  return param_1;
}



// Function: FUN_10014bd0 at 10014bd0

/* WARNING: Removing unreachable block (ram,0x10014bee) */

undefined4 * __thiscall
FUN_10014bd0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int *local_8;
  
  if (0xaaaaaa8 < *(uint *)((int)this + 8)) {
    FUN_1000e2e0((int)this + 0xd,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)((int)this + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = param_4;
    **(undefined4 **)((int)this + 4) = param_4;
    *(int **)(*(int *)((int)this + 4) + 8) = param_4;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_4;
    if (param_3 == *(undefined4 **)(*(int *)((int)this + 4) + 8)) {
      *(int **)(*(int *)((int)this + 4) + 8) = param_4;
    }
  }
  else {
    *param_3 = param_4;
    if (param_3 == (undefined4 *)**(int **)((int)this + 4)) {
      **(undefined4 **)((int)this + 4) = param_4;
    }
  }
  local_8 = param_4;
  while (*(char *)(local_8[1] + 0x24) == '\0') {
    if (local_8[1] == **(int **)(local_8[1] + 4)) {
      iVar1 = *(int *)(*(int *)(local_8[1] + 4) + 8);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)(local_8[1] + 8)) {
          local_8 = (int *)local_8[1];
          FUN_1000de50(this,(int)local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_1000df00(this,*(int **)(local_8[1] + 4));
      }
    }
    else {
      iVar1 = **(int **)(local_8[1] + 4);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)local_8[1]) {
          local_8 = (int *)local_8[1];
          FUN_1000df00(this,local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_1000de50(this,*(int *)(local_8[1] + 4));
      }
    }
  }
  *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x24) = 1;
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_10014eb0 at 10014eb0

/* WARNING: Removing unreachable block (ram,0x10014f60) */

int * __thiscall FUN_10014eb0(void *this,int *param_1,int *param_2,char param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 *local_98;
  undefined4 local_34;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined1 local_25;
  int local_24 [3];
  int local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  char local_5;
  
  local_14 = param_2 + 3;
  local_10 = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  local_c = *(undefined4 **)((int)this + 4);
  local_5 = '\x01';
  while (*(char *)((int)local_10 + 0x25) == '\0') {
    local_c = local_10;
    if (param_3 == '\0') {
      local_5 = FUN_100162b0(local_14,(int)(local_10 + 3));
    }
    else {
      cVar1 = FUN_100162b0(local_10 + 3,(int)local_14);
      local_5 = '\x01' - (cVar1 != '\0');
    }
    if (local_5 == '\0') {
      local_98 = (undefined4 *)local_10[2];
    }
    else {
      local_98 = (undefined4 *)*local_10;
    }
    local_10 = local_98;
  }
  FUN_10004160(&local_18,local_c);
  if (local_5 != '\0') {
    FUN_10004160(local_24,**(undefined4 **)((int)this + 4));
    if (local_18 == local_24[0]) {
      local_25 = 1;
      piVar2 = FUN_100150f0(this,&local_2c,'\x01',local_c,param_2);
      *param_1 = *piVar2;
      *(undefined1 *)(param_1 + 1) = local_25;
      return param_1;
    }
    FUN_10015490(&local_18);
  }
  cVar1 = FUN_100162b0((void *)(local_18 + 0xc),(int)local_14);
  if (cVar1 == '\0') {
    FUN_1000e350((int)this + 0xd,param_2 + 3);
    operator_delete(param_2);
    *param_1 = local_18;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    local_2d = 1;
    piVar2 = FUN_100150f0(this,&local_34,local_5,local_c,param_2);
    *param_1 = *piVar2;
    *(undefined1 *)(param_1 + 1) = local_2d;
  }
  return param_1;
}



// Function: FUN_100150f0 at 100150f0

/* WARNING: Removing unreachable block (ram,0x1001510e) */

undefined4 * __thiscall
FUN_100150f0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int *local_8;
  
  if (0xaaaaaa8 < *(uint *)((int)this + 8)) {
    FUN_1000e350((int)this + 0xd,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)((int)this + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = param_4;
    **(undefined4 **)((int)this + 4) = param_4;
    *(int **)(*(int *)((int)this + 4) + 8) = param_4;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_4;
    if (param_3 == *(undefined4 **)(*(int *)((int)this + 4) + 8)) {
      *(int **)(*(int *)((int)this + 4) + 8) = param_4;
    }
  }
  else {
    *param_3 = param_4;
    if (param_3 == (undefined4 *)**(int **)((int)this + 4)) {
      **(undefined4 **)((int)this + 4) = param_4;
    }
  }
  local_8 = param_4;
  while (*(char *)(local_8[1] + 0x24) == '\0') {
    if (local_8[1] == **(int **)(local_8[1] + 4)) {
      iVar1 = *(int *)(*(int *)(local_8[1] + 4) + 8);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)(local_8[1] + 8)) {
          local_8 = (int *)local_8[1];
          FUN_1000e020(this,(int)local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_1000e0d0(this,*(int **)(local_8[1] + 4));
      }
    }
    else {
      iVar1 = **(int **)(local_8[1] + 4);
      if (*(char *)(iVar1 + 0x24) == '\0') {
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(iVar1 + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        local_8 = *(int **)(local_8[1] + 4);
      }
      else {
        if (local_8 == *(int **)local_8[1]) {
          local_8 = (int *)local_8[1];
          FUN_1000e0d0(this,local_8);
        }
        *(undefined1 *)(local_8[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(local_8[1] + 4) + 0x24) = 0;
        FUN_1000e020(this,*(int *)(local_8[1] + 4));
      }
    }
  }
  *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x24) = 1;
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_100153d0 at 100153d0

int * __fastcall FUN_100153d0(int *param_1)

{
  int *piVar1;
  int local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)*param_1 + 0x25) == '\0') {
      local_14 = *(int *)*param_1;
      while (*(char *)(*(int *)(local_14 + 8) + 0x25) == '\0') {
        local_14 = *(int *)(local_14 + 8);
      }
      *param_1 = local_14;
    }
    else {
      while ((piVar1 = *(int **)(*param_1 + 4), *(char *)((int)piVar1 + 0x25) == '\0' &&
             (*param_1 == *piVar1))) {
        *param_1 = (int)piVar1;
      }
      if (*(char *)(*param_1 + 0x25) == '\0') {
        *param_1 = (int)piVar1;
      }
    }
  }
  else {
    *param_1 = *(int *)(*param_1 + 8);
  }
  return param_1;
}



// Function: FUN_10015490 at 10015490

int * __fastcall FUN_10015490(int *param_1)

{
  int *piVar1;
  int local_14;
  
  if (*(char *)(*param_1 + 0x25) == '\0') {
    if (*(char *)(*(int *)*param_1 + 0x25) == '\0') {
      local_14 = *(int *)*param_1;
      while (*(char *)(*(int *)(local_14 + 8) + 0x25) == '\0') {
        local_14 = *(int *)(local_14 + 8);
      }
      *param_1 = local_14;
    }
    else {
      while ((piVar1 = *(int **)(*param_1 + 4), *(char *)((int)piVar1 + 0x25) == '\0' &&
             (*param_1 == *piVar1))) {
        *param_1 = (int)piVar1;
      }
      if (*(char *)(*param_1 + 0x25) == '\0') {
        *param_1 = (int)piVar1;
      }
    }
  }
  else {
    *param_1 = *(int *)(*param_1 + 8);
  }
  return param_1;
}



// Function: FUN_10015550 at 10015550

void __thiscall FUN_10015550(void *this,int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a200;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = FUN_10015730((int)this);
  local_8 = 0;
  FUN_100157d0((int)this + 0xd,puVar1 + 3,param_1);
  FUN_100155cf();
  return;
}



// Function: Catch@100155ad at 100155ad

void Catch_100155ad(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100155cf at 100155cf

undefined4 FUN_100155cf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100155f0 at 100155f0

void __thiscall FUN_100155f0(void *this,int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a220;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = FUN_10015780((int)this);
  local_8 = 0;
  FUN_10015860((int)this + 0xd,puVar1 + 3,param_1);
  FUN_1001566f();
  return;
}



// Function: Catch@1001564d at 1001564d

void Catch_1001564d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001566f at 1001566f

undefined4 FUN_1001566f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10015690 at 10015690

void __cdecl FUN_10015690(int *param_1,int *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a259;
  local_10 = ExceptionList;
  uVar1 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((param_1 != (int *)0x0) && (*param_1 = *param_2, *param_1 != 0)) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1,uVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015730 at 10015730

undefined4 * __fastcall FUN_10015730(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100137e0(1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(puVar1 + 9) = 0;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  return puVar1;
}



// Function: FUN_10015780 at 10015780

undefined4 * __fastcall FUN_10015780(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10013890(1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(puVar1 + 9) = 0;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  return puVar1;
}



// Function: FUN_100157d0 at 100157d0

void __cdecl FUN_100157d0(undefined4 param_1,void *param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (void *)0x0) {
    FUN_100161d0(param_2,param_3);
    *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015860 at 10015860

void __cdecl FUN_10015860(undefined4 param_1,void *param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (void *)0x0) {
    FUN_100161d0(param_2,param_3);
    *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100158f0 at 100158f0

void FUN_100158f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a300;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_10015b10(param_4,param_3,param_1);
    param_3 = param_3 + 4;
  }
  FUN_10015996();
  return;
}



// Function: FUN_1001595d at 1001595d

void FUN_1001595d(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x10;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10015a90();
    FUN_1001595d();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10015966 at 10015966

void FUN_10015966(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10015a90();
    FUN_1001595d();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10015996 at 10015996

undefined4 FUN_10015996(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: FUN_100159c0 at 100159c0

void FUN_100159c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a320;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    FUN_10015b90(param_4,param_3,param_1);
    param_3 = param_3 + 1;
  }
  FUN_10015a66();
  return;
}



// Function: FUN_10015a2d at 10015a2d

void FUN_10015a2d(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10015aa0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_10015a2d();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10015a36 at 10015a36

void FUN_10015a36(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10015aa0(*(undefined4 *)(unaff_EBP + 0x14),*(int **)(unaff_EBP + -0x14));
    FUN_10015a2d();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10015a66 at 10015a66

undefined4 FUN_10015a66(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: FUN_10015a90 at 10015a90

void FUN_10015a90(void)

{
  return;
}



// Function: FUN_10015aa0 at 10015aa0

/* WARNING: Removing unreachable block (ram,0x10015af1) */

void __cdecl FUN_10015aa0(undefined4 param_1,int *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a348;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*param_2 != 0) {
    (**(code **)(*(int *)*param_2 + 8))(*param_2,DAT_10024664 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015b10 at 10015b10

void __cdecl FUN_10015b10(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
  }
  return;
}



// Function: FUN_10015b90 at 10015b90

void __cdecl FUN_10015b90(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    *param_2 = *param_3;
    *param_3 = 0;
  }
  return;
}



// Function: FUN_10015c20 at 10015c20

void __fastcall FUN_10015c20(_Container_base0 *param_1)

{
  int iVar1;
  int local_c;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    iVar1 = *(int *)(param_1 + 4);
    for (local_c = *(int *)param_1; local_c != iVar1; local_c = local_c + 0x10) {
      FUN_10015a90();
    }
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10015cd0 at 10015cd0

void __fastcall FUN_10015cd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_2c;
  undefined4 local_28 [5];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a573;
  local_10 = ExceptionList;
  local_14 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CKernelShutdown::vftable;
  FUN_100027e0((int)(param_1 + 1));
  local_8 = 0;
  local_2c = 0;
  while( true ) {
    iVar1 = memcmp((&PTR_DAT_1001d274)[local_2c * 2],&DAT_1001d618,0x10);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)(&PTR_DAT_1001d274)[local_2c * 2];
    FUN_10016190(local_28,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    local_8._0_1_ = 1;
    puVar2 = (undefined4 *)FUN_10002850(param_1 + 1,local_28);
    *puVar2 = (&PTR_FUN_1001d278)[local_2c * 2];
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10016220(local_28);
    local_2c = local_2c + 1;
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015de0 at 10015de0

undefined4 * __thiscall FUN_10015de0(void *this,uint param_1)

{
  FUN_10015e10((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10015e10 at 10015e10

void __fastcall FUN_10015e10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a5b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CKernelShutdown::vftable;
  local_8 = 0xffffffff;
  FUN_10002980(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015e80 at 10015e80

void __thiscall FUN_10015e80(void *this,void *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30 [5];
  uint local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a5d8;
  local_10 = ExceptionList;
  local_1c = DAT_10024664 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0x80004005;
  local_18 = **(int **)((int)this + 8);
  while( true ) {
    local_38 = *(int *)((int)this + 8);
    if (local_18 == local_38) break;
    FUN_100161d0(local_30,local_18 + 0xc);
    local_8 = 0;
    local_40 = *(int *)((int)param_1 + 4);
    piVar2 = FUN_10002ac0(param_1,&local_3c,local_30);
    if (*piVar2 != local_40) {
      piVar2 = FUN_10002ac0(param_1,&local_44,local_30);
      uVar4 = *(undefined4 *)(*piVar2 + 0x20);
      puVar3 = (undefined4 *)FUN_10002850((void *)((int)this + 4),local_30);
      local_14 = (*(code *)*puVar3)(uVar4);
    }
    local_8 = 0xffffffff;
    FUN_10016220(local_30);
    iVar1 = local_18;
    FUN_10004350(&local_18);
    local_34 = iVar1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_1c ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016000 at 10016000

undefined4 FUN_10016000(void)

{
  return 0;
}



// Function: FUN_10016010 at 10016010

undefined4 * __thiscall FUN_10016010(void *this,uint param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a608;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) == 0) {
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this,DAT_10024664 ^ (uint)&stack0xfffffffc);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FUN_100160c0);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100160c0 at 100160c0

void __fastcall FUN_100160c0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a638;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_10024664 ^ (uint)&stack0xfffffffc);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016110 at 10016110

void FUN_10016110(void)

{
  return;
}



// Function: FUN_10016120 at 10016120

undefined4 * __fastcall FUN_10016120(undefined4 *param_1)

{
  *param_1 = CFCComGUID::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10016160 at 10016160

undefined4 * __thiscall FUN_10016160(void *this,uint param_1)

{
  FUN_10016220((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016190 at 10016190

undefined4 * __thiscall
FUN_10016190(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined ***)this = CFCComGUID::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_4;
  return (undefined4 *)this;
}



// Function: FUN_100161d0 at 100161d0

undefined4 * __thiscall FUN_100161d0(void *this,int param_1)

{
  *(undefined ***)this = CFCComGUID::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return (undefined4 *)this;
}



// Function: FUN_10016220 at 10016220

void __fastcall FUN_10016220(undefined4 *param_1)

{
  *param_1 = CFCComGUID::vftable;
  return;
}



// Function: FUN_10016240 at 10016240

undefined4 * __thiscall FUN_10016240(void *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)((int)this + 4);
  param_1[1] = *(undefined4 *)((int)this + 8);
  param_1[2] = *(undefined4 *)((int)this + 0xc);
  param_1[3] = *(undefined4 *)((int)this + 0x10);
  return param_1;
}



// Function: FUN_10016270 at 10016270

bool __thiscall FUN_10016270(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = memcmp((void *)((int)this + 4),(void *)(param_1 + 4),0x10);
  return iVar1 == 0;
}



// Function: FUN_100162b0 at 100162b0

void __thiscall FUN_100162b0(void *this,int param_1)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  int local_6c;
  uint local_64 [11];
  bool local_35;
  uint local_34 [11];
  uint local_8;
  
  local_8 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_34[0] = *(uint *)((int)this + 4);
  local_34[1] = (uint)*(ushort *)((int)this + 8);
  local_34[2] = (uint)*(ushort *)((int)this + 10);
  local_34[3] = (uint)*(byte *)((int)this + 0xc);
  local_34[4] = (uint)*(byte *)((int)this + 0xd);
  local_34[5] = (uint)*(byte *)((int)this + 0xe);
  local_34[6] = (uint)*(byte *)((int)this + 0xf);
  local_34[7] = (uint)*(byte *)((int)this + 0x10);
  local_34[8] = (uint)*(byte *)((int)this + 0x11);
  local_34[9] = (uint)*(byte *)((int)this + 0x12);
  local_34[10] = (uint)*(byte *)((int)this + 0x13);
  local_64[0] = *(uint *)(param_1 + 4);
  local_64[1] = (uint)*(ushort *)(param_1 + 8);
  local_64[2] = (uint)*(ushort *)(param_1 + 10);
  local_64[3] = (uint)*(byte *)(param_1 + 0xc);
  local_64[4] = (uint)*(byte *)(param_1 + 0xd);
  local_64[5] = (uint)*(byte *)(param_1 + 0xe);
  local_64[6] = (uint)*(byte *)(param_1 + 0xf);
  local_64[7] = (uint)*(byte *)(param_1 + 0x10);
  local_64[8] = (uint)*(byte *)(param_1 + 0x11);
  local_64[9] = (uint)*(byte *)(param_1 + 0x12);
  local_64[10] = (uint)*(byte *)(param_1 + 0x13);
  local_35 = false;
  local_6c = 0;
  bVar3 = false;
  while (((local_6c < 0xb && (local_35 == false)) && (!bVar3))) {
    local_35 = local_34[local_6c] < local_64[local_6c];
    puVar1 = local_34 + local_6c;
    puVar2 = local_64 + local_6c;
    local_6c = local_6c + 1;
    bVar3 = *puVar2 < *puVar1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016410 at 10016410

undefined4 * __thiscall
FUN_10016410(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001a686;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  *(undefined ***)this = CFCDualGUID::vftable;
  _eh_vector_constructor_iterator_((void *)((int)this + 4),0x14,2,FUN_10016120,FUN_10016220);
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_4;
  *(undefined4 *)((int)this + 0x14) = param_5;
  *(undefined4 *)((int)this + 0x1c) = param_7;
  *(undefined4 *)((int)this + 0x20) = param_8;
  *(undefined4 *)((int)this + 0x24) = param_9;
  *(undefined4 *)((int)this + 0x28) = param_10;
  local_8 = local_8 & 0xffffff00;
  FUN_10016220(&param_1);
  local_8 = 0xffffffff;
  FUN_10016220(&param_6);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100164f0 at 100164f0

undefined4 * __thiscall FUN_100164f0(void *this,uint param_1)

{
  FUN_10016520((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016520 at 10016520

void __fastcall FUN_10016520(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a6c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CFCDualGUID::vftable;
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1 + 1,0x14,2,FUN_10016220);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016590 at 10016590

undefined4 __thiscall FUN_10016590(void *this,int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined1 local_c;
  
  bVar1 = FUN_10016270((void *)((int)this + 4),param_1 + 4);
  uVar2 = CONCAT31(extraout_var,bVar1);
  if (bVar1) {
    bVar1 = FUN_10016270((void *)((int)this + 0x18),param_1 + 0x18);
    uVar2 = (uint)bVar1;
    if (uVar2 != 0) {
      local_c = 1;
      goto LAB_100165db;
    }
  }
  local_c = 0;
LAB_100165db:
  return CONCAT31((int3)(uVar2 >> 8),local_c);
}



// Function: FUN_100165f0 at 100165f0

undefined1 __thiscall FUN_100165f0(void *this,int param_1)

{
  char cVar1;
  
  cVar1 = FUN_100162b0((void *)((int)this + 4),param_1 + 4);
  if ((cVar1 != '\0') &&
     (cVar1 = FUN_100162b0((void *)((int)this + 0x18),param_1 + 0x18), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}



// Function: GetClassID at 10016650

/* Library Function - Single Match
    public: struct _GUID __thiscall CPropertySet::GetClassID(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_GUID * __thiscall CPropertySet::GetClassID(CPropertySet *this,_GUID *__return_storage_ptr__)

{
  undefined4 uVar1;
  
  __return_storage_ptr__->Data1 = *(ulong *)(this + 8);
  uVar1 = *(undefined4 *)(this + 0xc);
  __return_storage_ptr__->Data2 = (short)uVar1;
  __return_storage_ptr__->Data3 = (short)((uint)uVar1 >> 0x10);
  *(undefined4 *)__return_storage_ptr__->Data4 = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(__return_storage_ptr__->Data4 + 4) = *(undefined4 *)(this + 0x14);
  return __return_storage_ptr__;
}



// Function: FUN_10016680 at 10016680

undefined4 * __thiscall FUN_10016680(void *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)((int)this + 0x1c);
  param_1[1] = *(undefined4 *)((int)this + 0x20);
  param_1[2] = *(undefined4 *)((int)this + 0x24);
  param_1[3] = *(undefined4 *)((int)this + 0x28);
  return param_1;
}



// Function: FUN_100166c0 at 100166c0

bool __cdecl FUN_100166c0(byte *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0x10;
  do {
    if (*(int *)param_1 != *(int *)param_2) {
      iVar2 = (uint)*param_1 - (uint)*param_2;
      if (((iVar2 == 0) && (iVar2 = (uint)param_1[1] - (uint)param_2[1], iVar2 == 0)) &&
         (iVar2 = (uint)param_1[2] - (uint)param_2[2], iVar2 == 0)) {
        iVar2 = (uint)param_1[3] - (uint)param_2[3];
      }
      return (iVar2 >> 0x1f | 1U) == 0;
    }
    uVar1 = uVar1 - 4;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  } while (3 < uVar1);
  return true;
}



// Function: FUN_10016730 at 10016730

void __thiscall FUN_10016730(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10016750 at 10016750

int * __thiscall FUN_10016750(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_100167e0 at 100167e0

int * __thiscall FUN_100167e0(void *this,int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  
  uVar4 = param_1 == 0;
  if (param_1 < 0) {
    param_1 = FUN_10001c50(0x80070057);
  }
  if ((bool)uVar4) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar2 = Ordinal_4(param_2,param_1);
    *(int *)this = iVar2;
    if (iVar2 == 0) {
      FUN_10001c50(0x8007000e);
      pcVar1 = (code *)swi(3);
      piVar3 = (int *)(*pcVar1)();
      return piVar3;
    }
  }
  return (int *)this;
}



// Function: FUN_10016830 at 10016830

int * __thiscall FUN_10016830(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar2 = Ordinal_2(param_1);
    *(int *)this = iVar2;
    if (iVar2 == 0) {
      FUN_10001c50(0x8007000e);
      pcVar1 = (code *)swi(3);
      piVar3 = (int *)(*pcVar1)();
      return piVar3;
    }
  }
  return (int *)this;
}



// Function: FUN_10016860 at 10016860

void __fastcall FUN_10016860(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10016880 at 10016880

void __cdecl FUN_10016880(undefined4 param_1,undefined4 param_2)

{
  HRESULT HVar1;
  HRESULT unaff_EBX;
  code *pcVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  uint uStack_44;
  int *local_30;
  int local_2c;
  CLSID local_28;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a700;
  local_10 = ExceptionList;
  uStack_44 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  iVar3 = 0;
  local_2c = 0;
  local_8 = 1;
  local_18 = uStack_44;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  pcVar2 = Ordinal_6_exref;
  switch(param_2) {
  case 0:
    unaff_EBX = CLSIDFromProgID(DAT_10024928,&local_28);
    uVar5 = 0x13;
    pwVar4 = L"8*YUPW\',*H \\(EB_T*A";
    break;
  case 1:
    unaff_EBX = CLSIDFromProgID(DAT_10024920,&local_28);
    uVar5 = 9;
    pwVar4 = L"?!- PNZVR";
    break;
  case 2:
    unaff_EBX = CLSIDFromProgID(DAT_10024924,&local_28);
    uVar5 = 0xb;
    pwVar4 = L"8$\\u,-}TQJ#";
    break;
  case 3:
    iVar3 = Ordinal_4(L"8*YUPW\',*H \\(EB_T*A",0x13);
    pcVar2 = Ordinal_6_exref;
    if (iVar3 != 0) {
      Ordinal_6(0);
      local_2c = iVar3;
      Ordinal_6(0);
      local_28.Data1 = 0xe7390aef;
      local_28.Data2 = 0xc3e5;
      local_28.Data3 = 0x11d5;
      local_28.Data4[0] = 0xa0;
      local_28.Data4[1] = 0xf1;
      local_28.Data4[2] = '\0';
      local_28.Data4[3] = '\x04';
      local_28.Data4[4] = 0xac;
      local_28.Data4[5] = 0x96;
      local_28.Data4[6] = '1';
      local_28.Data4[7] = 0xb0;
      goto LAB_1001692e;
    }
    goto LAB_1001690f;
  case 4:
    iVar3 = Ordinal_4(L"?!- PNZVR",9);
    pcVar2 = Ordinal_6_exref;
    if (iVar3 == 0) goto LAB_1001690f;
    Ordinal_6(0);
    local_2c = iVar3;
    Ordinal_6(0);
    local_28.Data1 = 0xbad58357;
    local_28.Data2 = 0xc7b8;
    local_28.Data3 = 0x11d5;
    local_28.Data4[0] = 0x9f;
    local_28.Data4[1] = 0xf6;
    local_28.Data4[2] = 0xff;
    local_28.Data4[3] = 0xff;
    local_28.Data4[4] = 0xff;
    local_28.Data4[5] = '\0';
    local_28.Data4[6] = '\0';
    local_28.Data4[7] = '\0';
    goto LAB_1001692e;
  case 5:
    iVar3 = Ordinal_4(L"8$\\u,-}TQJ#",0xb);
    pcVar2 = Ordinal_6_exref;
    if (iVar3 == 0) goto LAB_1001690f;
    Ordinal_6(0);
    local_2c = iVar3;
    Ordinal_6(0);
    local_28.Data1 = 0xe07ec490;
    local_28.Data2 = 0xf301;
    local_28.Data3 = 0x11d5;
    local_28.Data4[0] = 0xa5;
    local_28.Data4[1] = 'M';
    local_28.Data4[2] = '\0';
    local_28.Data4[3] = '`';
    local_28.Data4[4] = 0x94;
    local_28.Data4[5] = 0xeb;
    local_28.Data4[6] = 'b';
    local_28.Data4[7] = '\x1f';
    goto LAB_1001692e;
  default:
    goto switchD_100168e2_default;
  }
  iVar3 = Ordinal_4(pwVar4,uVar5);
  if (iVar3 == 0) {
LAB_1001690f:
    FUN_10001c50(0x8007000e);
  }
  pcVar2 = Ordinal_6_exref;
  Ordinal_6(0);
  local_2c = iVar3;
  Ordinal_6(0);
  if (-1 < unaff_EBX) {
LAB_1001692e:
    local_30 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    HVar1 = CoGetClassObject(&local_28,1,(LPVOID)0x0,(IID *)&DAT_1001f1b8,&local_30);
    if (-1 < HVar1) {
      (**(code **)(*local_30 + 0x1c))(local_30,0,0,&DAT_1001f148,iVar3,param_1);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
  }
switchD_100168e2_default:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  (*pcVar2)(iVar3);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch_All@10016af7 at 10016af7

undefined * Catch_All_10016af7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x30) = 0x80004005;
  return &DAT_10016b04;
}



// Function: FUN_10016b30 at 10016b30

void __cdecl
FUN_10016b30(LPVOID *param_1,LPUNKNOWN param_2,ulong param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  HRESULT HVar2;
  uint uStack_44;
  int local_34;
  int *local_2c;
  IID local_28;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a740;
  local_10 = ExceptionList;
  uStack_44 = DAT_10024664 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  local_28.Data1 = param_3;
  local_28.Data4._4_4_ = param_6;
  local_28._4_4_ = param_4;
  local_28.Data4._0_4_ = param_5;
  local_34 = 0;
  local_8 = 1;
  local_18 = uStack_44;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  bVar1 = FUN_100166c0(&DAT_1001d584,(byte *)&local_28);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    CoCreateInstance(&local_28,param_2,0x17,(IID *)&DAT_1001f148,param_1);
  }
  else {
    local_34 = Ordinal_4(L"/.V[0RZ1CDCAeS_B_!#^.^\'&CD!",0x1b);
    if (local_34 == 0) {
      FUN_10001c50(0x8007000e);
    }
    Ordinal_6(0);
    Ordinal_6(0);
    local_2c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    HVar2 = CoGetClassObject(&local_28,1,(LPVOID)0x0,(IID *)&DAT_1001f1b8,&local_2c);
    if (-1 < HVar2) {
      (**(code **)(*local_2c + 0x1c))(local_2c,param_2,0,&DAT_1001f148,local_34,param_1);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))(local_2c);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_10024908);
  Ordinal_6(local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch_All@10016c34 at 10016c34

undefined * Catch_All_10016c34(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x80004005;
  return &DAT_10016c41;
}



// Function: FUN_10016dd1 at 10016dd1

void __thiscall FUN_10016dd1(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return;
}



// Function: FUN_10016de3 at 10016de3

undefined4 __cdecl FUN_10016de3(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10016ded at 10016ded

void __fastcall FUN_10016ded(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10016e0c at 10016e0c

uint __cdecl FUN_10016e0c(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10016e24 at 10016e24

void __cdecl FUN_10016e24(DWORD param_1,DWORD param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: memmove_s at 10016e3b

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



// Function: RemoveAt at 10016ebe

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



// Function: FUN_10016f06 at 10016f06

int __thiscall FUN_10016f06(void *this,int param_1)

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



// Function: FUN_10016f32 at 10016f32

void __thiscall FUN_10016f32(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: FUN_10016f53 at 10016f53

int __fastcall FUN_10016f53(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10016f80 at 10016f80

void __fastcall FUN_10016f80(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10016ded((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: RemoveResourceInstance at 10016f98

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



// Function: GetHInstanceAt at 10017001

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
LAB_1001704f:
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
        goto LAB_1001704f;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: Add at 1001705e

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
      uVar6 = FUN_10001c50(0x80004005);
      iVar5 = extraout_ECX;
    }
    if ((int)uVar6 == 0) {
      _Count = 1;
LAB_100170a4:
      pvVar4 = _recalloc((void *)((ulonglong)uVar6 >> 0x20),_Count,4);
      if (pvVar4 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar4;
        goto LAB_100170b9;
      }
    }
    else {
      _Count = iVar5 * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_100170a4;
    }
    iVar5 = 0;
  }
  else {
LAB_100170b9:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar5 = 1;
  }
  return iVar5;
}



// Function: FUN_100170da at 100170da

undefined4 * __fastcall FUN_100170da(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_10016f53((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1001f418;
  DVar1 = FUN_10009d60((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)DVar1 < 0) {
    DAT_10024744 = 1;
  }
  return param_1;
}



// Function: AddResourceInstance at 1001711a

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



// Function: FUN_1001714f at 1001714f

void __fastcall FUN_1001714f(int *param_1)

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



// Function: FUN_10017193 at 10017193

int __fastcall FUN_10017193(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100171ad at 100171ad

undefined4 * __fastcall FUN_100171ad(undefined4 *param_1)

{
  DWORD DVar1;
  
  FUN_10017193((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10022fa0;
  param_1[3] = &DAT_10022fa0;
  DVar1 = FUN_10009d60((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)DVar1 < 0) {
    DAT_10024744 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_100171f3 at 100171f3

void FUN_100171f3(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 10017234

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10024664) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 1001724e

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



// Function: __onexit at 100172e2

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
  
  local_8 = &DAT_10022ed8;
  uStack_c = 0x100172ee;
  local_20[0] = DecodePointer(DAT_10024ccc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10024ccc);
    local_24 = DecodePointer(DAT_10024cc8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10024ccc = EncodePointer(local_20[0]);
    DAT_10024cc8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001737a();
  }
  return p_Var1;
}



// Function: FUN_1001737a at 1001737a

void FUN_1001737a(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10017383

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 100173b0

/* WARNING: This is an inlined function */

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



// Function: __ArrayUnwind at 10017418

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



// Function: `eh_vector_destructor_iterator' at 10017476

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
  FUN_100174c1();
  return;
}



// Function: FUN_100174c1 at 100174c1

void FUN_100174c1(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 100174d9

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
  FUN_10017526();
  return;
}



// Function: FUN_10017526 at 10017526

void FUN_10017526(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __CRT_INIT@12 at 10017593

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
    if (DAT_1002498c < 1) {
      return 0;
    }
    DAT_1002498c = DAT_1002498c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10024cc0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10024cbc == 2) {
      param_2 = (int *)DecodePointer(DAT_10024ccc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10024cc8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10024ccc);
            piVar8 = (int *)DecodePointer(DAT_10024cc8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10024cc8 = (PVOID)encoded_null();
        DAT_10024ccc = DAT_10024cc8;
      }
      DAT_10024cbc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10024cc0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10024cc0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10024cbc == 0) {
      DAT_10024cbc = 1;
      iVar5 = initterm_e(&DAT_1001c260,&DAT_1001c268);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001c1d0,&DAT_1001c25c);
      DAT_10024cbc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10024cc0,0);
    }
    if ((DAT_10024cc4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10024cc4), BVar2 != 0)) {
      (*DAT_10024cc4)(param_1,2,param_3);
    }
    DAT_1002498c = DAT_1002498c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001779d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001783d) */
/* WARNING: Removing unreachable block (ram,0x100177ea) */
/* WARNING: Removing unreachable block (ram,0x1001786a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10024690 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002498c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10005ba0(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10005ba0(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100178a8();
  return local_20;
}



// Function: FUN_100178a8 at 100178a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100178a8(void)

{
  _DAT_10024690 = 0xffffffff;
  return;
}



// Function: entry at 100178b3

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 100178dc

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
  
  _DAT_10024aa8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10024aac = &stack0x00000004;
  _DAT_100249e8 = 0x10001;
  _DAT_10024990 = 0xc0000409;
  _DAT_10024994 = 1;
  local_32c = DAT_10024664;
  local_328 = DAT_10024668;
  _DAT_1002499c = unaff_retaddr;
  _DAT_10024a74 = in_GS;
  _DAT_10024a78 = in_FS;
  _DAT_10024a7c = in_ES;
  _DAT_10024a80 = in_DS;
  _DAT_10024a84 = unaff_EDI;
  _DAT_10024a88 = unaff_ESI;
  _DAT_10024a8c = unaff_EBX;
  _DAT_10024a90 = in_EDX;
  _DAT_10024a94 = in_ECX;
  _DAT_10024a98 = in_EAX;
  _DAT_10024a9c = unaff_EBP;
  DAT_10024aa0 = unaff_retaddr;
  _DAT_10024aa4 = in_CS;
  _DAT_10024ab0 = in_SS;
  DAT_100249e0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1001f434);
  if (DAT_100249e0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10017a00

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10024664 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10017a45

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



// Function: FUN_10017a59 at 10017a59

void __cdecl
FUN_10017a59(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10024664,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 10017af0

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



// Function: __FindPESection at 10017b30

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



// Function: __IsNonwritableInCurrentImage at 10017b80

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
  
  pcStack_10 = FUN_10017a59;
  local_14 = ExceptionList;
  local_c = DAT_10024664 ^ 0x10022f80;
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



// Function: ___security_init_cookie at 10017c54

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
  if ((DAT_10024664 == 0xbb40e64e) || ((DAT_10024664 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10024664 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10024664 == 0xbb40e64e) {
      DAT_10024664 = 0xbb40e64f;
    }
    else if ((DAT_10024664 & 0xffff0000) == 0) {
      DAT_10024664 = DAT_10024664 | (DAT_10024664 | 0x4711) << 0x10;
    }
    DAT_10024668 = ~DAT_10024664;
  }
  else {
    DAT_10024668 = ~DAT_10024664;
  }
  return;
}



// Function: Unwind@10017d70 at 10017d70

void Unwind_10017d70(void)

{
  int unaff_EBP;
  
  FUN_10001140((void *)(*(int *)(unaff_EBP + -0x7c) + 4));
  return;
}



// Function: Unwind@10017d7b at 10017d7b

void Unwind_10017d7b(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017db0 at 10017db0

void Unwind_10017db0(void)

{
  int unaff_EBP;
  
  FUN_10002980(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10017de0 at 10017de0

void Unwind_10017de0(void)

{
  int unaff_EBP;
  
  FUN_10001140((void *)(*(int *)(unaff_EBP + -0x5c) + 4));
  return;
}



// Function: Unwind@10017deb at 10017deb

void Unwind_10017deb(void)

{
  int unaff_EBP;
  
  FUN_10002980(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10017e10 at 10017e10

void Unwind_10017e10(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10017e18 at 10017e18

void Unwind_10017e18(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017e23 at 10017e23

void Unwind_10017e23(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10017e2e at 10017e2e

void Unwind_10017e2e(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017e39 at 10017e39

void Unwind_10017e39(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2b8));
  return;
}



// Function: Unwind@10017e44 at 10017e44

void Unwind_10017e44(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10017e4c at 10017e4c

void Unwind_10017e4c(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017e54 at 10017e54

void Unwind_10017e54(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10017e5c at 10017e5c

void Unwind_10017e5c(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10017e64 at 10017e64

void Unwind_10017e64(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10017e6c at 10017e6c

void Unwind_10017e6c(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017e77 at 10017e77

void Unwind_10017e77(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017eb0 at 10017eb0

void Unwind_10017eb0(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017eb8 at 10017eb8

void Unwind_10017eb8(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10017ec0 at 10017ec0

void Unwind_10017ec0(void)

{
  int unaff_EBP;
  
  FUN_10001ca0((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10017ec8 at 10017ec8

void Unwind_10017ec8(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10017ed0 at 10017ed0

void Unwind_10017ed0(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10017ed8 at 10017ed8

void Unwind_10017ed8(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017ee0 at 10017ee0

void Unwind_10017ee0(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10017f10 at 10017f10

void Unwind_10017f10(void)

{
  int unaff_EBP;
  
  FUN_10002b60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017f40 at 10017f40

void Unwind_10017f40(void)

{
  int unaff_EBP;
  
  FUN_10004450((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017f48 at 10017f48

void Unwind_10017f48(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017f50 at 10017f50

void Unwind_10017f50(void)

{
  int unaff_EBP;
  
  FUN_10001ca0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017f58 at 10017f58

void Unwind_10017f58(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10017f60 at 10017f60

void Unwind_10017f60(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017f90 at 10017f90

void Unwind_10017f90(void)

{
  int unaff_EBP;
  
  FUN_10002b90((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017f98 at 10017f98

void Unwind_10017f98(void)

{
  int unaff_EBP;
  
  FUN_10002150((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017fa0 at 10017fa0

void Unwind_10017fa0(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017fa8 at 10017fa8

void Unwind_10017fa8(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017fb0 at 10017fb0

void Unwind_10017fb0(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10017fb8 at 10017fb8

void Unwind_10017fb8(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10017fc0 at 10017fc0

void Unwind_10017fc0(void)

{
  int unaff_EBP;
  
  FUN_10002b90((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017ff0 at 10017ff0

void Unwind_10017ff0(void)

{
  int unaff_EBP;
  
  FUN_10002b90(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018020 at 10018020

void Unwind_10018020(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018028 at 10018028

void Unwind_10018028(void)

{
  int unaff_EBP;
  
  FUN_10001ca0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018030 at 10018030

void Unwind_10018030(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018038 at 10018038

void Unwind_10018038(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10018040 at 10018040

void Unwind_10018040(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10018048 at 10018048

void Unwind_10018048(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018050 at 10018050

void Unwind_10018050(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018080 at 10018080

void Unwind_10018080(void)

{
  int unaff_EBP;
  
  FUN_10002bc0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018088 at 10018088

void Unwind_10018088(void)

{
  int unaff_EBP;
  
  FUN_100023f0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018090 at 10018090

void Unwind_10018090(void)

{
  int unaff_EBP;
  
  FUN_10002bc0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180c0 at 100180c0

void Unwind_100180c0(void)

{
  int unaff_EBP;
  
  FUN_10002bc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180f0 at 100180f0

void Unwind_100180f0(void)

{
  int unaff_EBP;
  
  FUN_10002bf0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180f8 at 100180f8

void Unwind_100180f8(void)

{
  int unaff_EBP;
  
  FUN_10002500((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018100 at 10018100

void Unwind_10018100(void)

{
  int unaff_EBP;
  
  FUN_10002bf0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018130 at 10018130

void Unwind_10018130(void)

{
  int unaff_EBP;
  
  FUN_10002bf0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018160 at 10018160

void Unwind_10018160(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018168 at 10018168

void Unwind_10018168(void)

{
  int unaff_EBP;
  
  FUN_10001ca0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018170 at 10018170

void Unwind_10018170(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018178 at 10018178

void Unwind_10018178(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10018180 at 10018180

void Unwind_10018180(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10018188 at 10018188

void Unwind_10018188(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018190 at 10018190

void Unwind_10018190(void)

{
  int unaff_EBP;
  
  FUN_10002b60((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100181c0 at 100181c0

void Unwind_100181c0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100181f0 at 100181f0

void Unwind_100181f0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100181f8 at 100181f8

void Unwind_100181f8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100026f0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018230 at 10018230

void Unwind_10018230(void)

{
  int unaff_EBP;
  
  FUN_100034e0(*(int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10018238 at 10018238

void Unwind_10018238(void)

{
  int unaff_EBP;
  
  FUN_10002980(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10018260 at 10018260

void Unwind_10018260(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018268 at 10018268

void Unwind_10018268(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018270 at 10018270

void Unwind_10018270(void)

{
  int unaff_EBP;
  
  FUN_10002c20((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018278 at 10018278

void Unwind_10018278(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018280 at 10018280

void Unwind_10018280(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100182b0 at 100182b0

void Unwind_100182b0(void)

{
  int unaff_EBP;
  
  FUN_100034e0(*(int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100182e0 at 100182e0

void Unwind_100182e0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100182e8 at 100182e8

void Unwind_100182e8(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018310 at 10018310

void Unwind_10018310(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018360 at 10018360

void Unwind_10018360(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018368 at 10018368

void Unwind_10018368(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018370 at 10018370

void Unwind_10018370(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018378 at 10018378

void Unwind_10018378(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_100026f0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018391 at 10018391

void Unwind_10018391(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100183c0 at 100183c0

void Unwind_100183c0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100183c8 at 100183c8

void Unwind_100183c8(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100183f0 at 100183f0

void Unwind_100183f0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100183f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018420 at 10018420

void Unwind_10018420(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018423. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018450 at 10018450

void Unwind_10018450(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018453. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018480 at 10018480

void Unwind_10018480(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018483. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100184b0 at 100184b0

void Unwind_100184b0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100184b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184e0 at 100184e0

void Unwind_100184e0(void)

{
  int unaff_EBP;
  
  FUN_100056b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100184e8 at 100184e8

void Unwind_100184e8(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100184f0 at 100184f0

void Unwind_100184f0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018530 at 10018530

void Unwind_10018530(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018538 at 10018538

void Unwind_10018538(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x54) + 0x10));
  return;
}



// Function: Unwind@10018560 at 10018560

void Unwind_10018560(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x20) + 0x10));
  return;
}



// Function: Unwind@1001856b at 1001856b

void Unwind_1001856b(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018590 at 10018590

void Unwind_10018590(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x20) + 0x10));
  return;
}



// Function: Unwind@1001859b at 1001859b

void Unwind_1001859b(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100185c0 at 100185c0

void Unwind_100185c0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100185c8 at 100185c8

void Unwind_100185c8(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x58) + 0x10));
  return;
}



// Function: Unwind@10018610 at 10018610

void Unwind_10018610(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@10018621 at 10018621

void Unwind_10018621(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018629 at 10018629

void Unwind_10018629(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018650 at 10018650

void Unwind_10018650(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018680 at 10018680

void Unwind_10018680(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100186b0 at 100186b0

void Unwind_100186b0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100186e0 at 100186e0

void Unwind_100186e0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018710 at 10018710

void Unwind_10018710(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018740 at 10018740

void Unwind_10018740(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10018770 at 10018770

void Unwind_10018770(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100187a0 at 100187a0

void Unwind_100187a0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100187d0 at 100187d0

void Unwind_100187d0(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100187db at 100187db

void Unwind_100187db(void)

{
  int unaff_EBP;
  
  FUN_10006a80((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@100187e6 at 100187e6

void Unwind_100187e6(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100187f1 at 100187f1

void Unwind_100187f1(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xaac));
  return;
}



// Function: Unwind@100187fc at 100187fc

void Unwind_100187fc(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xac0));
  return;
}



// Function: Unwind@10018807 at 10018807

void Unwind_10018807(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018812 at 10018812

void Unwind_10018812(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xad8));
  return;
}



// Function: Unwind@1001881d at 1001881d

void Unwind_1001881d(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10018828 at 10018828

void Unwind_10018828(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018833 at 10018833

void Unwind_10018833(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xae0));
  return;
}



// Function: Unwind@1001883e at 1001883e

void Unwind_1001883e(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018849 at 10018849

void Unwind_10018849(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xae8));
  return;
}



// Function: Unwind@10018854 at 10018854

void Unwind_10018854(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001885f at 1001885f

void Unwind_1001885f(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xaf8));
  return;
}



// Function: Unwind@1001886a at 1001886a

void Unwind_1001886a(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xb0c));
  return;
}



// Function: Unwind@10018875 at 10018875

void Unwind_10018875(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xb2c));
  return;
}



// Function: Unwind@100188b0 at 100188b0

void Unwind_100188b0(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100188e0 at 100188e0

void Unwind_100188e0(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100188e8 at 100188e8

void Unwind_100188e8(void)

{
  int unaff_EBP;
  
  Free((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018910 at 10018910

void Unwind_10018910(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(*(int *)(unaff_EBP + -0x50) + 4));
  return;
}



// Function: Unwind@1001891b at 1001891b

void Unwind_1001891b(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10018940 at 10018940

void Unwind_10018940(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018970 at 10018970

void Unwind_10018970(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100189a0 at 100189a0

void Unwind_100189a0(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100189a8 at 100189a8

void Unwind_100189a8(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x448));
  return;
}



// Function: Unwind@100189e0 at 100189e0

void Unwind_100189e0(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018a10 at 10018a10

void Unwind_10018a10(void)

{
  int unaff_EBP;
  
  FUN_10007cf0(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@10018a40 at 10018a40

void Unwind_10018a40(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018a70 at 10018a70

void Unwind_10018a70(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018a78 at 10018a78

void Unwind_10018a78(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018a83 at 10018a83

void Unwind_10018a83(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x2250));
  return;
}



// Function: Unwind@10018a8e at 10018a8e

void Unwind_10018a8e(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@10018a99 at 10018a99

void Unwind_10018a99(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x226c));
  return;
}



// Function: Unwind@10018ad0 at 10018ad0

void Unwind_10018ad0(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018b00 at 10018b00

void Unwind_10018b00(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2130));
  return;
}



// Function: Unwind@10018b0b at 10018b0b

void Unwind_10018b0b(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x2158));
  return;
}



// Function: Unwind@10018b16 at 10018b16

void Unwind_10018b16(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x2270));
  return;
}



// Function: Unwind@10018b50 at 10018b50

void Unwind_10018b50(void)

{
  DAT_10024794 = DAT_10024794 & 0xfffffffe;
  return;
}



// Function: Unwind@10018b80 at 10018b80

void Unwind_10018b80(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018bb0 at 10018bb0

void Unwind_10018bb0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018bbb at 10018bbb

void Unwind_10018bbb(void)

{
  int unaff_EBP;
  
  FUN_1000ea60(*(int *)(unaff_EBP + -0x20) + 4);
  return;
}



// Function: Unwind@10018bc6 at 10018bc6

void Unwind_10018bc6(void)

{
  int unaff_EBP;
  
  FUN_1000be30(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018bf0 at 10018bf0

void Unwind_10018bf0(void)

{
  int unaff_EBP;
  
  FUN_1000ee00((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018c20 at 10018c20

void Unwind_10018c20(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c28 at 10018c28

void Unwind_10018c28(void)

{
  int unaff_EBP;
  
  FUN_1000acb0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c30 at 10018c30

void Unwind_10018c30(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c38 at 10018c38

void Unwind_10018c38(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c40 at 10018c40

void Unwind_10018c40(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c48 at 10018c48

void Unwind_10018c48(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c50 at 10018c50

void Unwind_10018c50(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10018c58 at 10018c58

void Unwind_10018c58(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10018c63 at 10018c63

void Unwind_10018c63(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10018c6e at 10018c6e

void Unwind_10018c6e(void)

{
  int unaff_EBP;
  
  FUN_1000ea00((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018ca0 at 10018ca0

void Unwind_10018ca0(void)

{
  int unaff_EBP;
  
  FUN_1000ea00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018cd0 at 10018cd0

void Unwind_10018cd0(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018cd8 at 10018cd8

void Unwind_10018cd8(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018ce0 at 10018ce0

void Unwind_10018ce0(void)

{
  int unaff_EBP;
  
  FUN_1000b780((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018ce8 at 10018ce8

void Unwind_10018ce8(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018cf0 at 10018cf0

void Unwind_10018cf0(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018cf8 at 10018cf8

void Unwind_10018cf8(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d30 at 10018d30

void Unwind_10018d30(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018d70 at 10018d70

void Unwind_10018d70(void)

{
  int unaff_EBP;
  
  FUN_1000ea30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018da0 at 10018da0

void Unwind_10018da0(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018da8 at 10018da8

void Unwind_10018da8(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018db0 at 10018db0

void Unwind_10018db0(void)

{
  int unaff_EBP;
  
  FUN_1000b780((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018db8 at 10018db8

void Unwind_10018db8(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018dc0 at 10018dc0

void Unwind_10018dc0(void)

{
  int unaff_EBP;
  
  FUN_1000ea30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018df0 at 10018df0

void Unwind_10018df0(void)

{
  int unaff_EBP;
  
  FUN_1000ee00((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018e20 at 10018e20

void Unwind_10018e20(void)

{
  int unaff_EBP;
  
  FUN_1000ea60(*(int *)(unaff_EBP + -0x18) + 4);
  return;
}



// Function: Unwind@10018e2b at 10018e2b

void Unwind_10018e2b(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@10018e33 at 10018e33

void Unwind_10018e33(void)

{
  int unaff_EBP;
  
  FUN_1000eae0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10018e3e at 10018e3e

void Unwind_10018e3e(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e46 at 10018e46

void Unwind_10018e46(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10018e70 at 10018e70

void Unwind_10018e70(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10018ea0 at 10018ea0

void Unwind_10018ea0(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018ed0 at 10018ed0

void Unwind_10018ed0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018edb at 10018edb

void Unwind_10018edb(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@10018ee3 at 10018ee3

void Unwind_10018ee3(void)

{
  FUN_1000cef0();
  return;
}



// Function: Unwind@10018eee at 10018eee

void Unwind_10018eee(void)

{
  int unaff_EBP;
  
  FUN_1000ccc0(*(int *)(unaff_EBP + -0x20) + 0xc);
  return;
}



// Function: Unwind@10018f20 at 10018f20

void Unwind_10018f20(void)

{
  int unaff_EBP;
  
  FUN_1000be30(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018f50 at 10018f50

void Unwind_10018f50(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@10018f58 at 10018f58

void Unwind_10018f58(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10018f60 at 10018f60

void Unwind_10018f60(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f68 at 10018f68

void Unwind_10018f68(void)

{
  int unaff_EBP;
  
  FUN_1000eae0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10018f90 at 10018f90

void Unwind_10018f90(void)

{
  int unaff_EBP;
  
  FUN_1000ea60(*(int *)(unaff_EBP + -0x6c) + 0x1a0);
  return;
}



// Function: Unwind@10018f9e at 10018f9e

void Unwind_10018f9e(void)

{
  int unaff_EBP;
  
  FUN_1000cba0((undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 0xc));
  return;
}



// Function: Unwind@10018fa9 at 10018fa9

void Unwind_10018fa9(void)

{
  int unaff_EBP;
  
  FUN_1000cb40((int *)(*(int *)(unaff_EBP + -0x6c) + 0x1c0));
  return;
}



// Function: Unwind@10018fb7 at 10018fb7

void Unwind_10018fb7(void)

{
  int unaff_EBP;
  
  FUN_1000cd10((void *)(*(int *)(unaff_EBP + -0x6c) + 0x1c4));
  return;
}



// Function: Unwind@10018fc5 at 10018fc5

void Unwind_10018fc5(void)

{
  int unaff_EBP;
  
  FUN_10001190((undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 0x1d4));
  return;
}



// Function: Unwind@10018fd3 at 10018fd3

void Unwind_10018fd3(void)

{
  int unaff_EBP;
  
  FUN_10015e10((undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 0x1e8));
  return;
}



// Function: Unwind@10018fe1 at 10018fe1

void Unwind_10018fe1(void)

{
  int unaff_EBP;
  
  FUN_1000cd60((void *)(*(int *)(unaff_EBP + -0x6c) + 0x204));
  return;
}



// Function: Unwind@10018fef at 10018fef

void Unwind_10018fef(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x6c) + 0x214));
  return;
}



// Function: Unwind@10018ffd at 10018ffd

void Unwind_10018ffd(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019005 at 10019005

void Unwind_10019005(void)

{
  int unaff_EBP;
  
  FUN_1000ce50(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001900d at 1001900d

void Unwind_1001900d(void)

{
  int unaff_EBP;
  
  FUN_1000d170(*(int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019015 at 10019015

void Unwind_10019015(void)

{
  int unaff_EBP;
  
  FUN_1000cdb0(*(void **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001901d at 1001901d

void Unwind_1001901d(void)

{
  int unaff_EBP;
  
  FUN_1000d0e0(*(int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019025 at 10019025

void Unwind_10019025(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001902d at 1001902d

void Unwind_1001902d(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@10019035 at 10019035

void Unwind_10019035(void)

{
  int unaff_EBP;
  
  FUN_1000eae0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x68) + 4));
  return;
}



// Function: Unwind@10019040 at 10019040

void Unwind_10019040(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019048 at 10019048

void Unwind_10019048(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019070 at 10019070

void Unwind_10019070(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100190a0 at 100190a0

void Unwind_100190a0(void)

{
  FUN_1000cef0();
  return;
}



// Function: Unwind@100190ab at 100190ab

void Unwind_100190ab(void)

{
  int unaff_EBP;
  
  FUN_1000ccc0(*(int *)(unaff_EBP + -0x44) + 0xc);
  return;
}



// Function: Unwind@100190b6 at 100190b6

void Unwind_100190b6(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100190be at 100190be

void Unwind_100190be(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@100190f0 at 100190f0

void Unwind_100190f0(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019120 at 10019120

void Unwind_10019120(void)

{
  int unaff_EBP;
  
  FUN_1000cdb0(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019150 at 10019150

void Unwind_10019150(void)

{
  int unaff_EBP;
  
  FUN_1000ce50(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019180 at 10019180

void Unwind_10019180(void)

{
  int unaff_EBP;
  
  FUN_1000d0e0(*(int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100191b0 at 100191b0

void Unwind_100191b0(void)

{
  int unaff_EBP;
  
  FUN_1000d170(*(int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100191e0 at 100191e0

void Unwind_100191e0(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@10019210 at 10019210

void Unwind_10019210(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019240 at 10019240

void Unwind_10019240(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019248 at 10019248

void Unwind_10019248(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019270 at 10019270

void Unwind_10019270(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019278 at 10019278

void Unwind_10019278(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100192a0 at 100192a0

void Unwind_100192a0(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100192d0 at 100192d0

void Unwind_100192d0(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019300 at 10019300

void Unwind_10019300(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019330 at 10019330

void Unwind_10019330(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019360 at 10019360

void Unwind_10019360(void)

{
  FUN_1000eec0();
  return;
}



// Function: Unwind@10019379 at 10019379

void Unwind_10019379(void)

{
  FUN_1000eec0();
  return;
}



// Function: Unwind@100193b0 at 100193b0

void Unwind_100193b0(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@100193b8 at 100193b8

void Unwind_100193b8(void)

{
  int unaff_EBP;
  
  FUN_1000eae0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100193c3 at 100193c3

void Unwind_100193c3(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100193cb at 100193cb

void Unwind_100193cb(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@100193f0 at 100193f0

void Unwind_100193f0(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100193f8 at 100193f8

void Unwind_100193f8(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019420 at 10019420

void Unwind_10019420(void)

{
  FUN_1000efa0(0x1002480c);
  return;
}



// Function: Unwind@1001942a at 1001942a

void Unwind_1001942a(void)

{
  FUN_1000f240(0x1002480c);
  return;
}



// Function: Unwind@10019450 at 10019450

void Unwind_10019450(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@1001945b at 1001945b

void Unwind_1001945b(void)

{
  FUN_1000f0e0();
  return;
}



// Function: Unwind@10019490 at 10019490

void Unwind_10019490(void)

{
  FUN_1000f0e0();
  return;
}



// Function: Unwind@1001949b at 1001949b

void Unwind_1001949b(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@100194d0 at 100194d0

void Unwind_100194d0(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019500 at 10019500

void Unwind_10019500(void)

{
  int unaff_EBP;
  
  FUN_1000f240(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019508 at 10019508

void Unwind_10019508(void)

{
  int unaff_EBP;
  
  FUN_1000efa0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019510 at 10019510

void Unwind_10019510(void)

{
  FUN_1000f0e0();
  return;
}



// Function: Unwind@1001951b at 1001951b

void Unwind_1001951b(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019550 at 10019550

void Unwind_10019550(void)

{
  int unaff_EBP;
  
  FUN_1000efa0(*(int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019558 at 10019558

void Unwind_10019558(void)

{
  FUN_1000f0e0();
  return;
}



// Function: Unwind@10019563 at 10019563

void Unwind_10019563(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019590 at 10019590

void Unwind_10019590(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001959b at 1001959b

void Unwind_1001959b(void)

{
  int unaff_EBP;
  
  FUN_10006a80((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@100195a6 at 100195a6

void Unwind_100195a6(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100195b1 at 100195b1

void Unwind_100195b1(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xaac));
  return;
}



// Function: Unwind@100195bc at 100195bc

void Unwind_100195bc(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xac0));
  return;
}



// Function: Unwind@100195c7 at 100195c7

void Unwind_100195c7(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100195d2 at 100195d2

void Unwind_100195d2(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xad8));
  return;
}



// Function: Unwind@100195dd at 100195dd

void Unwind_100195dd(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@100195e8 at 100195e8

void Unwind_100195e8(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100195f3 at 100195f3

void Unwind_100195f3(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xae0));
  return;
}



// Function: Unwind@100195fe at 100195fe

void Unwind_100195fe(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10019609 at 10019609

void Unwind_10019609(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xae8));
  return;
}



// Function: Unwind@10019614 at 10019614

void Unwind_10019614(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001961f at 1001961f

void Unwind_1001961f(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xaf8));
  return;
}



// Function: Unwind@1001962a at 1001962a

void Unwind_1001962a(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xb0c));
  return;
}



// Function: Unwind@10019635 at 10019635

void Unwind_10019635(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0xb2c));
  return;
}



// Function: Unwind@10019640 at 10019640

void Unwind_10019640(void)

{
  int unaff_EBP;
  
  FUN_100065a0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001964b at 1001964b

void Unwind_1001964b(void)

{
  int unaff_EBP;
  
  FUN_1000e6f0(*(int **)(unaff_EBP + -0xb40));
  return;
}



// Function: Unwind@10019680 at 10019680

void Unwind_10019680(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100196b0 at 100196b0

void Unwind_100196b0(void)

{
  int unaff_EBP;
  
  FUN_1000e680((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100196e0 at 100196e0

void Unwind_100196e0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019710 at 10019710

void Unwind_10019710(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019740 at 10019740

void Unwind_10019740(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019770 at 10019770

void Unwind_10019770(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100197a0 at 100197a0

void Unwind_100197a0(void)

{
  FUN_1000f240(0x1002480c);
  return;
}



// Function: Unwind@100197aa at 100197aa

void Unwind_100197aa(void)

{
  FUN_1000efa0(0x1002480c);
  return;
}



// Function: Unwind@100197b4 at 100197b4

void Unwind_100197b4(void)

{
  FUN_1000f0e0();
  return;
}



// Function: Unwind@100197be at 100197be

void Unwind_100197be(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@100197f0 at 100197f0

void Unwind_100197f0(void)

{
  FUN_1000bf50();
  return;
}



// Function: Unwind@100197f8 at 100197f8

void Unwind_100197f8(void)

{
  FUN_1000bed0();
  return;
}



// Function: Unwind@10019800 at 10019800

void Unwind_10019800(void)

{
  int unaff_EBP;
  
  FUN_1000bee0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019808 at 10019808

void Unwind_10019808(void)

{
  int unaff_EBP;
  
  FUN_1000eae0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019813 at 10019813

void Unwind_10019813(void)

{
  int unaff_EBP;
  
  FUN_1000ea60(*(int *)(unaff_EBP + -0x60) + 0x1a0);
  return;
}



// Function: Unwind@10019821 at 10019821

void Unwind_10019821(void)

{
  int unaff_EBP;
  
  FUN_1000cba0((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 0xc));
  return;
}



// Function: Unwind@1001982c at 1001982c

void Unwind_1001982c(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019834 at 10019834

void Unwind_10019834(void)

{
  int unaff_EBP;
  
  FUN_1000cb40((int *)(*(int *)(unaff_EBP + -0x60) + 0x1c0));
  return;
}



// Function: Unwind@10019842 at 10019842

void Unwind_10019842(void)

{
  int unaff_EBP;
  
  FUN_1000cd10((void *)(*(int *)(unaff_EBP + -0x60) + 0x1c4));
  return;
}



// Function: Unwind@10019850 at 10019850

void Unwind_10019850(void)

{
  int unaff_EBP;
  
  FUN_10001190((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 0x1d4));
  return;
}



// Function: Unwind@1001985e at 1001985e

void Unwind_1001985e(void)

{
  int unaff_EBP;
  
  FUN_10015e10((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 0x1e8));
  return;
}



// Function: Unwind@1001986c at 1001986c

void Unwind_1001986c(void)

{
  int unaff_EBP;
  
  FUN_1000cd60((void *)(*(int *)(unaff_EBP + -0x60) + 0x204));
  return;
}



// Function: Unwind@1001987a at 1001987a

void Unwind_1001987a(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019882 at 10019882

void Unwind_10019882(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(*(int *)(unaff_EBP + -0x60) + 0x214));
  return;
}



// Function: Unwind@100198b0 at 100198b0

void Unwind_100198b0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100198b8 at 100198b8

void Unwind_100198b8(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100198c0 at 100198c0

void Unwind_100198c0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019930 at 10019930

void Unwind_10019930(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019938 at 10019938

void Unwind_10019938(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019940 at 10019940

void Unwind_10019940(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019948 at 10019948

void Unwind_10019948(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019980 at 10019980

void Unwind_10019980(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019988 at 10019988

void Unwind_10019988(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019990 at 10019990

void Unwind_10019990(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019998 at 10019998

void Unwind_10019998(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100199a3 at 100199a3

void Unwind_100199a3(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x278));
  return;
}



// Function: Unwind@100199ae at 100199ae

void Unwind_100199ae(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100199b6 at 100199b6

void Unwind_100199b6(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100199be at 100199be

void Unwind_100199be(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@100199c9 at 100199c9

void Unwind_100199c9(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019a00 at 10019a00

void Unwind_10019a00(void)

{
  int unaff_EBP;
  
  FUN_10001910((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019a08 at 10019a08

void Unwind_10019a08(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019a10 at 10019a10

void Unwind_10019a10(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019a18 at 10019a18

void Unwind_10019a18(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019a23 at 10019a23

void Unwind_10019a23(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@10019a2e at 10019a2e

void Unwind_10019a2e(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x2cc));
  return;
}



// Function: Unwind@10019a39 at 10019a39

void Unwind_10019a39(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0((int *)(unaff_EBP + -0x2fc));
  return;
}



// Function: Unwind@10019a44 at 10019a44

void Unwind_10019a44(void)

{
  int unaff_EBP;
  
  FUN_1000cb40((int *)(unaff_EBP + -0x2fc));
  return;
}



// Function: Unwind@10019a4f at 10019a4f

void Unwind_10019a4f(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019a57 at 10019a57

void Unwind_10019a57(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019a5f at 10019a5f

void Unwind_10019a5f(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019a67 at 10019a67

void Unwind_10019a67(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019a6f at 10019a6f

void Unwind_10019a6f(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0((int *)(unaff_EBP + -0x2fc));
  return;
}



// Function: Unwind@10019ab0 at 10019ab0

void Unwind_10019ab0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019ab8 at 10019ab8

void Unwind_10019ab8(void)

{
  int unaff_EBP;
  
  FUN_100026f0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019ac0 at 10019ac0

void Unwind_10019ac0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019ac8 at 10019ac8

void Unwind_10019ac8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_100026f0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019ae1 at 10019ae1

void Unwind_10019ae1(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@10019b20 at 10019b20

void Unwind_10019b20(void)

{
  DAT_10024868 = DAT_10024868 & 0xfffffffe;
  return;
}



// Function: Unwind@10019b2e at 10019b2e

void Unwind_10019b2e(void)

{
  FUN_100120c0((_Container_base12 *)&DAT_10024850);
  return;
}



// Function: Unwind@10019b38 at 10019b38

void Unwind_10019b38(void)

{
  DAT_10024868 = DAT_10024868 & 0xfffffffd;
  return;
}



// Function: Unwind@10019b46 at 10019b46

void Unwind_10019b46(void)

{
  FUN_10012640();
  return;
}



// Function: Unwind@10019b50 at 10019b50

void Unwind_10019b50(void)

{
  FUN_10012940();
  return;
}



// Function: Unwind@10019b58 at 10019b58

void Unwind_10019b58(void)

{
  int unaff_EBP;
  
  FUN_10011fe0((_Container_base0 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019b60 at 10019b60

void Unwind_10019b60(void)

{
  FUN_10012940();
  return;
}



// Function: Unwind@10019b90 at 10019b90

void Unwind_10019b90(void)

{
  int unaff_EBP;
  
  FUN_1000d0e0(*(int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019b98 at 10019b98

void Unwind_10019b98(void)

{
  int unaff_EBP;
  
  FUN_1000cdb0(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019bc0 at 10019bc0

void Unwind_10019bc0(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019bc8 at 10019bc8

void Unwind_10019bc8(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019bd0 at 10019bd0

void Unwind_10019bd0(void)

{
  int unaff_EBP;
  
  FUN_10011df0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019bd8 at 10019bd8

void Unwind_10019bd8(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019be0 at 10019be0

void Unwind_10019be0(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c10 at 10019c10

void Unwind_10019c10(void)

{
  int unaff_EBP;
  
  FUN_1000d170(*(int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019c18 at 10019c18

void Unwind_10019c18(void)

{
  int unaff_EBP;
  
  FUN_1000ce50(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019c40 at 10019c40

void Unwind_10019c40(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c48 at 10019c48

void Unwind_10019c48(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c50 at 10019c50

void Unwind_10019c50(void)

{
  int unaff_EBP;
  
  FUN_10011e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c58 at 10019c58

void Unwind_10019c58(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c60 at 10019c60

void Unwind_10019c60(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019c90 at 10019c90

void Unwind_10019c90(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c98 at 10019c98

void Unwind_10019c98(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019cc0 at 10019cc0

void Unwind_10019cc0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019cc8 at 10019cc8

void Unwind_10019cc8(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019cf0 at 10019cf0

void Unwind_10019cf0(void)

{
  FUN_10012940();
  return;
}



// Function: Unwind@10019d20 at 10019d20

void Unwind_10019d20(void)

{
  int unaff_EBP;
  
  FUN_10012d00(*(_Container_base12 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019d90 at 10019d90

void Unwind_10019d90(void)

{
  int unaff_EBP;
  
  FUN_10012d00(*(_Container_base12 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019dc0 at 10019dc0

void Unwind_10019dc0(void)

{
  FUN_10012d90();
  return;
}



// Function: Unwind@10019dc8 at 10019dc8

void Unwind_10019dc8(void)

{
  FUN_10012d90();
  return;
}



// Function: Unwind@10019dd0 at 10019dd0

void Unwind_10019dd0(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019dd8 at 10019dd8

void Unwind_10019dd8(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019de0 at 10019de0

void Unwind_10019de0(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019de8 at 10019de8

void Unwind_10019de8(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019e10 at 10019e10

void Unwind_10019e10(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019e40 at 10019e40

void Unwind_10019e40(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019e48 at 10019e48

void Unwind_10019e48(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019e70 at 10019e70

void Unwind_10019e70(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019ea0 at 10019ea0

void Unwind_10019ea0(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019ea8 at 10019ea8

void Unwind_10019ea8(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019eb0 at 10019eb0

void Unwind_10019eb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10012d90();
    return;
  }
  return;
}



// Function: Unwind@10019ef0 at 10019ef0

void Unwind_10019ef0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019ef3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019f20 at 10019f20

void Unwind_10019f20(void)

{
  FUN_10012d90();
  return;
}



// Function: Unwind@10019f28 at 10019f28

void Unwind_10019f28(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019f30 at 10019f30

void Unwind_10019f30(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019f38 at 10019f38

void Unwind_10019f38(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_10012d90();
    return;
  }
  return;
}



// Function: Unwind@10019f51 at 10019f51

void Unwind_10019f51(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019f59 at 10019f59

void Unwind_10019f59(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019f80 at 10019f80

void Unwind_10019f80(void)

{
  FUN_10012a50();
  return;
}



// Function: Unwind@10019f88 at 10019f88

void Unwind_10019f88(void)

{
  FUN_10012de0();
  return;
}



// Function: Unwind@10019fb0 at 10019fb0

void Unwind_10019fb0(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@10019fe0 at 10019fe0

void Unwind_10019fe0(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a010 at 1001a010

void Unwind_1001a010(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a021 at 1001a021

void Unwind_1001a021(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a050 at 1001a050

void Unwind_1001a050(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a080 at 1001a080

void Unwind_1001a080(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a083. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a0b0 at 1001a0b0

void Unwind_1001a0b0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a0b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a0e0 at 1001a0e0

void Unwind_1001a0e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a0e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a110 at 1001a110

void Unwind_1001a110(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a113. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a140 at 1001a140

void Unwind_1001a140(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a170 at 1001a170

void Unwind_1001a170(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a173. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a1a0 at 1001a1a0

void Unwind_1001a1a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a1a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a1d0 at 1001a1d0

void Unwind_1001a1d0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a1d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a240 at 1001a240

void Unwind_1001a240(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a251 at 1001a251

void Unwind_1001a251(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a280 at 1001a280

void Unwind_1001a280(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a291 at 1001a291

void Unwind_1001a291(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a299 at 1001a299

void Unwind_1001a299(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2c0 at 1001a2c0

void Unwind_1001a2c0(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a2d1 at 1001a2d1

void Unwind_1001a2d1(void)

{
  int unaff_EBP;
  
  FUN_10016220(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2d9 at 1001a2d9

void Unwind_1001a2d9(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a340 at 1001a340

void Unwind_1001a340(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a370 at 1001a370

void Unwind_1001a370(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a3a0 at 1001a3a0

void Unwind_1001a3a0(void)

{
  FUN_10005ad0();
  return;
}



// Function: Unwind@1001a3b1 at 1001a3b1

void Unwind_1001a3b1(void)

{
  int unaff_EBP;
  
  FUN_1000e6c0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a3e0 at 1001a3e0

void Unwind_1001a3e0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a410 at 1001a410

void Unwind_1001a410(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a440 at 1001a440

void Unwind_1001a440(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a470 at 1001a470

void Unwind_1001a470(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a4a0 at 1001a4a0

void Unwind_1001a4a0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a4d0 at 1001a4d0

void Unwind_1001a4d0(void)

{
  FUN_100034d0();
  return;
}



// Function: Unwind@1001a500 at 1001a500

void Unwind_1001a500(void)

{
  FUN_10012640();
  return;
}



// Function: Unwind@1001a530 at 1001a530

void Unwind_1001a530(void)

{
  FUN_100120c0((_Container_base12 *)&DAT_10024850);
  return;
}



// Function: Unwind@1001a53a at 1001a53a

void Unwind_1001a53a(void)

{
  FUN_10012d00((_Container_base12 *)&DAT_10024850);
  return;
}



// Function: Unwind@1001a560 at 1001a560

void Unwind_1001a560(void)

{
  int unaff_EBP;
  
  FUN_10001140((void *)(*(int *)(unaff_EBP + -0x7c) + 4));
  return;
}



// Function: Unwind@1001a56b at 1001a56b

void Unwind_1001a56b(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a5a0 at 1001a5a0

void Unwind_1001a5a0(void)

{
  int unaff_EBP;
  
  FUN_10001140((void *)(*(int *)(unaff_EBP + -0x5c) + 4));
  return;
}



// Function: Unwind@1001a5ab at 1001a5ab

void Unwind_1001a5ab(void)

{
  int unaff_EBP;
  
  FUN_10002980(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a5d0 at 1001a5d0

void Unwind_1001a5d0(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a600 at 1001a600

void Unwind_1001a600(void)

{
  int unaff_EBP;
  
  FUN_10001c80(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a630 at 1001a630

void Unwind_1001a630(void)

{
  int unaff_EBP;
  
  FUN_10001c80(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a660 at 1001a660

void Unwind_1001a660(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + 0x1c));
  return;
}



// Function: Unwind@1001a668 at 1001a668

void Unwind_1001a668(void)

{
  int unaff_EBP;
  
  FUN_10016220((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a670 at 1001a670

void Unwind_1001a670(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x1c) + 4),0x14,2,FUN_10016220);
  return;
}



// Function: Unwind@1001a6b0 at 1001a6b0

void Unwind_1001a6b0(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x10) + 4),0x14,2,FUN_10016220);
  return;
}



// Function: Unwind@1001a6f0 at 1001a6f0

void Unwind_1001a6f0(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a6f8 at 1001a6f8

void Unwind_1001a6f8(void)

{
  int unaff_EBP;
  
  FUN_10016860((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a730 at 1001a730

void Unwind_1001a730(void)

{
  int unaff_EBP;
  
  FUN_10001c80((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a738 at 1001a738

void Unwind_1001a738(void)

{
  int unaff_EBP;
  
  FUN_10016860((int *)(unaff_EBP + -0x28));
  return;
}



// Function: FUN_1001a770 at 1001a770

void FUN_1001a770(void)

{
  FUN_10005ae0(&DAT_1002469c,L"\r");
  _atexit(FUN_1001ac40);
  return;
}



// Function: FUN_1001a7a0 at 1001a7a0

void FUN_1001a7a0(void)

{
  FUN_10005ae0(&DAT_100246b8,L"\n");
  _atexit(FUN_1001ac90);
  return;
}



// Function: FUN_1001a7d0 at 1001a7d0

void FUN_1001a7d0(void)

{
  FUN_10005ae0(&DAT_100246d4,L"\\n");
  _atexit(FUN_1001ace0);
  return;
}



// Function: FUN_1001a800 at 1001a800

void FUN_1001a800(void)

{
  FUN_10005ae0(&DAT_100246f0,L"\\r");
  _atexit(FUN_1001ad30);
  return;
}



// Function: FUN_1001a830 at 1001a830

void FUN_1001a830(void)

{
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001868a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &local_19;
  local_8 = 0;
  FUN_10003400(&DAT_1002470c,'\0',0);
  local_8 = 0xffffffff;
  _atexit(FUN_1001ad80);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001a8a0 at 1001a8a0

void FUN_1001a8a0(void)

{
  FUN_10005ae0(&DAT_10024728,L"\\AL");
  _atexit(FUN_1001add0);
  return;
}



// Function: FUN_1001a8d0 at 1001a8d0

void FUN_1001a8d0(void)

{
  FUN_10005ae0(&DAT_1002479c,L"\r");
  _atexit(FUN_1001ae20);
  return;
}



// Function: FUN_1001a900 at 1001a900

void FUN_1001a900(void)

{
  FUN_10005ae0(&DAT_100247b8,L"\n");
  _atexit(FUN_1001ae70);
  return;
}



// Function: FUN_1001a930 at 1001a930

void FUN_1001a930(void)

{
  FUN_10005ae0(&DAT_100247d4,L"\\n");
  _atexit(FUN_1001aec0);
  return;
}



// Function: FUN_1001a960 at 1001a960

void FUN_1001a960(void)

{
  FUN_10005ae0(&DAT_100247f0,L"\\r");
  _atexit(FUN_1001af10);
  return;
}



// Function: FUN_1001a990 at 1001a990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001a990(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019434;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000eed0(0x1002480c);
  _DAT_1002480c = ATL::CComModule::vftable;
  _DAT_10024768 = &DAT_1002480c;
  local_8 = 0xffffffff;
  _atexit(FUN_1001af60);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001aa10 at 1001aa10

void FUN_1001aa10(void)

{
  DAT_10024798 = &PTR_DAT_1001d17c;
  return;
}



// Function: FUN_1001aa20 at 1001aa20

void FUN_1001aa20(void)

{
  FUN_10005ae0(&DAT_1002486c,L"\r");
  _atexit(FUN_1001afd0);
  return;
}



// Function: FUN_1001aa50 at 1001aa50

void FUN_1001aa50(void)

{
  FUN_10005ae0(&DAT_10024888,L"\n");
  _atexit(FUN_1001b020);
  return;
}



// Function: FUN_1001aa80 at 1001aa80

void FUN_1001aa80(void)

{
  FUN_10005ae0(&DAT_100248a4,L"\\n");
  _atexit(FUN_1001b070);
  return;
}



// Function: FUN_1001aab0 at 1001aab0

void FUN_1001aab0(void)

{
  FUN_10005ae0(&DAT_100248c0,L"\\r");
  _atexit(FUN_1001b0c0);
  return;
}



// Function: FUN_1001aae0 at 1001aae0

void FUN_1001aae0(void)

{
  undefined1 local_19;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3ea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &local_19;
  local_8 = 0;
  FUN_10003400(&DAT_100248dc,'\0',0);
  local_8 = 0xffffffff;
  _atexit(FUN_1001b110);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ab50 at 1001ab50

void FUN_1001ab50(void)

{
  DAT_10024798 = &PTR_DAT_1001d17c;
  return;
}



// Function: FUN_1001ab60 at 1001ab60

void FUN_1001ab60(void)

{
  return;
}



// Function: FUN_1001ab70 at 1001ab70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ab70(void)

{
  _DAT_10024900 = Define_the_symbol__ATL_MIXED::Thank_you::vftable;
  return;
}



// Function: FUN_1001ac40 at 1001ac40

void FUN_1001ac40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100186ba;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_1002469c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ac90 at 1001ac90

void FUN_1001ac90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100186ea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100246b8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ace0 at 1001ace0

void FUN_1001ace0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001871a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100246d4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ad30 at 1001ad30

void FUN_1001ad30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001874a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100246f0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ad80 at 1001ad80

void FUN_1001ad80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001877a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_1002470c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001add0 at 1001add0

void FUN_1001add0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100187aa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_10024728,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ae20 at 1001ae20

void FUN_1001ae20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100196ea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_1002479c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ae70 at 1001ae70

void FUN_1001ae70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001971a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100247b8,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001aec0 at 1001aec0

void FUN_1001aec0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001974a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100247d4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001af10 at 1001af10

void FUN_1001af10(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001977a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100247f0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001af60 at 1001af60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001af60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100197c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_1002480c = ATL::CComModule::vftable;
  local_8 = 2;
  FUN_10009f50(0x1002480c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001afd0 at 1001afd0

void FUN_1001afd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a41a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_1002486c,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b020 at 1001b020

void FUN_1001b020(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a44a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_10024888,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b070 at 1001b070

void FUN_1001b070(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a47a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100248a4,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b0c0 at 1001b0c0

void FUN_1001b0c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4aa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100248c0,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b110 at 1001b110

void FUN_1001b110(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4da;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003400(&DAT_100248dc,'\x01',0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b160 at 1001b160

void FUN_1001b160(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a50a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10015c20((_Container_base0 *)&DAT_10024840);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b1b0 at 1001b1b0

void FUN_1001b1b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a544;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10012c30(0x10024850);
  local_8 = 0xffffffff;
  FUN_10012d00((_Container_base12 *)&DAT_10024850);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001b210 at 1001b210

void FUN_1001b210(void)

{
  Ordinal_6(DAT_10024928);
  return;
}



// Function: FUN_1001b220 at 1001b220

void FUN_1001b220(void)

{
  Ordinal_6(DAT_10024920);
  return;
}



// Function: FUN_1001b230 at 1001b230

void FUN_1001b230(void)

{
  Ordinal_6(DAT_10024924);
  return;
}



// Function: FUN_1001b23d at 1001b23d

void FUN_1001b23d(void)

{
  FUN_10016f80(0x1002492c);
  return;
}



// Function: FUN_1001b247 at 1001b247

void FUN_1001b247(void)

{
  FUN_1001714f((int *)&DAT_10024964);
  return;
}



