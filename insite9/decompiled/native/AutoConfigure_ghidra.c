/*
 * Decompiled from: AutoConfigure.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

bool __cdecl FUN_10001000(byte *param_1,byte *param_2)

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



// Function: FUN_10001070 at 10001070

void FUN_10001070(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10033210);
}



// Function: FUN_10001090 at 10001090

void __cdecl FUN_10001090(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  case 0xc:
    FUN_10001070(0x8007000e);
  case 0x16:
  case 0x22:
    FUN_10001070(0x80070057);
  default:
    FUN_10001070(0x80004005);
    return;
  }
}



// Function: FUN_10001150 at 10001150

uint __fastcall FUN_10001150(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
    if (0 < (int)uVar2) {
      return uVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10001180 at 10001180

void __fastcall FUN_10001180(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001190 at 10001190

int FUN_10001190(void)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  LPWSTR pWVar2;
  LPCWSTR unaff_EBX;
  LPCWSTR pWVar3;
  
  if (unaff_EBX == (LPCWSTR)0x0) {
    return 0;
  }
  WVar1 = *unaff_EBX;
  lpsz = unaff_EBX;
  pWVar3 = unaff_EBX;
  while (WVar1 != L'\0') {
    pWVar2 = CharNextW(lpsz);
    WVar1 = *lpsz;
    if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
      pWVar3 = pWVar2;
    }
    lpsz = pWVar2;
    WVar1 = *pWVar2;
  }
  return (int)pWVar3 - (int)unaff_EBX >> 1;
}



// Function: DllCanUnloadNow at 100011e0

HRESULT DllCanUnloadNow(void)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x11e0  1  DllCanUnloadNow */
  uVar1 = FUN_100136c0();
  if (uVar1 == 0) {
    iVar2 = (**(code **)(DAT_1003afa8 + 0xc))();
    uVar1 = (uint)(iVar2 != 0);
  }
  return uVar1;
}



// Function: FUN_10001200 at 10001200

int __fastcall FUN_10001200(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  ((LPCRITICAL_SECTION)(param_1 + 0x10))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1003af94 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_1003af88 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10001270 at 10001270

undefined4 FUN_10001270(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_100136f0(param_1,param_2);
  if ((iVar1 != 0) && ((param_2 != 1 || (DAT_1003af88 == '\0')))) {
    return 1;
  }
  return 0;
}



// Function: DllGetClassObject at 100012b0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  
                    /* 0x12b0  2  DllGetClassObject */
  iVar1 = FUN_10013680(rclsid,riid,ppv);
  if (iVar1 == 0) {
    return 0;
  }
  HVar2 = Ordinal_15(&DAT_1003b050,rclsid,riid,ppv);
  return HVar2;
}



// Function: FUN_100012f0 at 100012f0

int FUN_100012f0(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = Ordinal_61(&local_8);
  if (-1 < iVar2) {
    if (param_4 != (int *)0x0) {
      iVar2 = *param_4;
      while (iVar2 != 0) {
        (**(code **)(*local_8 + 0xc))(local_8,iVar2,param_4[1]);
        piVar1 = param_4 + 2;
        param_4 = param_4 + 2;
        iVar2 = *piVar1;
      }
    }
    iVar2 = (**(code **)(*param_1 + 0x14))(local_8);
    if (-1 < iVar2) {
      iVar2 = Ordinal_23(DAT_1003b07c,param_2,param_3,0,local_8);
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}



// Function: FUN_10001390 at 10001390

int FUN_10001390(int param_1,uint param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  undefined4 local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  iVar1 = Ordinal_56(param_1,param_2,&local_c,&local_8);
  if (iVar1 < 0) goto LAB_10001467;
  iVar1 = (**(code **)(*local_8 + 0x1c))(local_8,&param_1);
  if (iVar1 < 0) goto LAB_10001467;
  param_2 = param_2 & 0xffffff;
  iVar1 = Ordinal_68((int)&param_2 + 3);
  if (iVar1 < 0) {
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
    Ordinal_6(local_c);
    return iVar1;
  }
  if (param_2._3_1_ == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_10001439;
    pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar2 == (FARPROC)0x0) goto LAB_10001439;
  }
  else {
LAB_10001439:
    pFVar2 = Ordinal_186_exref;
  }
  iVar1 = (*pFVar2)(param_1,(uint)*(ushort *)(param_1 + 0x18),(uint)*(ushort *)(param_1 + 0x1a),
                    *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  (**(code **)(*local_8 + 0x30))(local_8,param_1);
LAB_10001467:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  Ordinal_6(local_c);
  return iVar1;
}



// Function: FUN_10001490 at 10001490

void FUN_10001490(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  rsize_t rVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  wchar_t *pwVar4;
  undefined4 local_220;
  wchar_t *local_21c;
  int *local_218;
  char local_211;
  wchar_t local_210 [259];
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_220 = 0;
  local_218 = (int *)0x0;
  iVar1 = Ordinal_56(param_1,param_2,&local_220,&local_218);
  if (iVar1 < 0) goto LAB_100015f1;
  local_21c = (wchar_t *)0x0;
  pwVar4 = (wchar_t *)0x0;
  iVar1 = (**(code **)(*local_218 + 0x24))(local_218,0xffffffff,0,0,0,&local_21c);
  if ((-1 < iVar1) && (local_21c != (wchar_t *)0x0)) {
    rVar2 = Ordinal_7(local_21c);
    FUN_10001090(local_210,0x104,local_21c,rVar2);
    pwVar4 = local_210;
    local_a = 0;
    iVar1 = FUN_10001190();
    local_210[iVar1] = L'\0';
  }
  local_211 = '\0';
  iVar1 = Ordinal_68(&local_211);
  if (iVar1 < 0) {
    Ordinal_6(local_21c);
    if (local_218 != (int *)0x0) {
      (**(code **)(*local_218 + 8))(local_218);
    }
    Ordinal_6(local_220);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (local_211 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_100015cc;
    pFVar3 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_100015cc;
  }
  else {
LAB_100015cc:
    pFVar3 = Ordinal_163_exref;
  }
  (*pFVar3)(local_218,local_220,pwVar4);
  Ordinal_6(local_21c);
LAB_100015f1:
  if (local_218 != (int *)0x0) {
    (**(code **)(*local_218 + 8))(local_218);
  }
  Ordinal_6(local_220);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001630 at 10001630

int FUN_10001630(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return -0x7ff8ffa9;
  }
  piVar4 = *(int **)(param_1 + 8);
  iVar5 = 0;
  if (piVar4 < *(int **)(param_1 + 0xc)) {
    do {
      puVar1 = (undefined4 *)*piVar4;
      if ((puVar1 != (undefined4 *)0x0) &&
         ((param_3 == (byte *)0x0 ||
          (bVar2 = FUN_10001000(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar5 = (*(code *)puVar1[1])(1);
        if (iVar5 < 0) {
          return iVar5;
        }
        uVar3 = (*(code *)puVar1[7])(1);
        iVar5 = Ordinal_49(*puVar1,uVar3);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0xc));
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if (param_2 != 0) {
    iVar5 = FUN_10001490(*(undefined4 *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_100016c0 at 100016c0

int FUN_100016c0(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return -0x7ff8ffa9;
  }
  piVar4 = *(int **)(param_1 + 8);
  iVar5 = 0;
  if (piVar4 < *(int **)(param_1 + 0xc)) {
    do {
      puVar1 = (undefined4 *)*piVar4;
      if ((puVar1 != (undefined4 *)0x0) &&
         ((param_3 == (byte *)0x0 ||
          (bVar2 = FUN_10001000(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        uVar3 = (*(code *)puVar1[7])(0);
        iVar5 = Ordinal_49(*puVar1,uVar3);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = (*(code *)puVar1[1])(0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0xc));
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if (param_2 != 0) {
    iVar5 = FUN_10001390(*(int *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_10001750 at 10001750

int __fastcall FUN_10001750(int param_1)

{
  int *piVar1;
  
  FUN_10001200(param_1);
  DAT_1003af98 = 0x8db70c04;
  DAT_1003af9c = 0x4f133f33;
  DAT_1003afa0 = 0xaff24ca0;
  DAT_1003afa4 = 0xf2122a72;
  piVar1 = DAT_1003b058;
  if (DAT_1003b058 < DAT_1003b05c) {
    do {
      if (*piVar1 != 0) {
        (**(code **)(*piVar1 + 0x20))(1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 < DAT_1003b05c);
  }
  return param_1;
}



// Function: FUN_100017b0 at 100017b0

void __fastcall FUN_100017b0(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_1003b058;
  if (DAT_1003b058 < DAT_1003b05c) {
    do {
      if (*piVar1 != 0) {
        (**(code **)(*piVar1 + 0x20))(0);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 < DAT_1003b05c);
  }
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_10001820 at 10001820

void FUN_10001820(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",L"{039A6375-8A36-4D9F-83E7-E604A65CA2E2}");
  return;
}



// Function: FUN_10001840 at 10001840

void __fastcall FUN_10001840(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10001850 at 10001850

void __fastcall FUN_10001850(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10001860 at 10001860

undefined4 __fastcall FUN_10001860(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001870 at 10001870

HRESULT __thiscall FUN_10001870(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10031d78,(LPUNKNOWN)0x0,1,(IID *)&DAT_100283c8,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_100018d0 at 100018d0

void * __thiscall FUN_100018d0(void *this,byte param_1)

{
  FUN_100017b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10001900 at 10001900

int FUN_10001900(int param_1)

{
  LCID Locale;
  int iVar1;
  wchar_t *local_14;
  wchar_t *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  local_14 = L"APPID";
  local_10 = L"{039A6375-8A36-4D9F-83E7-E604A65CA2E2}";
  local_c = 0;
  local_8 = 0;
  iVar1 = FUN_100012f0(DAT_1003af94,0x65,1,(int *)&local_14);
  if (((-1 < iVar1) && (iVar1 = FUN_10001630(0x1003b050,param_1,(byte *)0x0), -1 < iVar1)) &&
     (DAT_1003af8c != (code *)0x0)) {
    iVar1 = (*DAT_1003af8c)(DAT_1003b07c);
  }
  SetThreadLocale(Locale);
  return iVar1;
}



// Function: FUN_10001990 at 10001990

int FUN_10001990(int param_1)

{
  LCID Locale;
  int iVar1;
  wchar_t *local_14;
  wchar_t *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  if (DAT_1003af90 != (code *)0x0) {
    iVar1 = (*DAT_1003af90)();
    if (iVar1 < 0) goto LAB_100019cd;
  }
  iVar1 = FUN_100016c0(0x1003b050,param_1,(byte *)0x0);
LAB_100019cd:
  if (-1 < iVar1) {
    local_14 = L"APPID";
    local_10 = L"{039A6375-8A36-4D9F-83E7-E604A65CA2E2}";
    local_c = 0;
    local_8 = 0;
    iVar1 = FUN_100012f0(DAT_1003af94,0x65,0,(int *)&local_14);
  }
  SetThreadLocale(Locale);
  return iVar1;
}



// Function: DllRegisterServer at 10001a10

void DllRegisterServer(void)

{
  int iVar1;
  
                    /* 0x1a10  3  DllRegisterServer */
  iVar1 = FUN_10001900(1);
  if (-1 < iVar1) {
    FUN_10013710();
    return;
  }
  return;
}



// Function: DllUnregisterServer at 10001a30

void DllUnregisterServer(void)

{
  int iVar1;
  
                    /* 0x1a30  4  DllUnregisterServer */
  iVar1 = FUN_10001990(1);
  if (-1 < iVar1) {
    iVar1 = FUN_10013710();
    if (-1 < iVar1) {
      FUN_10013750();
      return;
    }
  }
  return;
}



// Function: FUN_10001a50 at 10001a50

undefined4 FUN_10001a50(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1003a120 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (7 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10001ab0 at 10001ab0

void __fastcall FUN_10001ab0(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



// Function: FUN_10001ac0 at 10001ac0

void __thiscall FUN_10001ac0(void *this,undefined4 param_1,undefined4 param_2)

{
  if (this != (void *)0x0) {
    Ordinal_58((int)this + 4,param_1,param_2);
    return;
  }
  Ordinal_58(0,param_1,param_2);
  return;
}



// Function: ~_com_error at 10001b30

/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Library: Visual Studio 2010 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = vftable;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (*(HLOCAL *)(this + 0xc) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  return;
}



// Function: `scalar_deleting_destructor' at 10001b60

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = vftable;
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



// Function: FUN_10001bb0 at 10001bb0

exception * __thiscall FUN_10001bb0(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001be0 at 10001be0

void __cdecl FUN_10001be0(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 * 2);
  return;
}



// Function: FUN_10001c00 at 10001c00

void __fastcall FUN_10001c00(int *param_1)

{
  int iVar1;
  int *_Memory;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
    iVar1 = *param_1;
  }
  return;
}



// Function: FUN_10001c30 at 10001c30

exception * __thiscall FUN_10001c30(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  return (exception *)this;
}



// Function: FUN_10001c50 at 10001c50

undefined4 __thiscall FUN_10001c50(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uStack_38;
  int local_24;
  uint *local_20;
  int local_1c;
  uint *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022443;
  local_10 = ExceptionList;
  uStack_38 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  iVar3 = (**(code **)(*param_1 + 0xc))(param_1,&local_24);
  if (-1 < iVar3) {
    uVar4 = (uint)*(ushort *)(local_24 + 0x2c);
    local_20 = (uint *)0x0;
    *(uint *)((int)this + 0x18) = uVar4;
    *(undefined4 *)((int)this + 0x14) = 0;
    if (uVar4 != 0) {
      local_8 = 0;
      local_20 = (uint *)FUN_1002175a(-(uint)(0xfffffffb < uVar4 * 0xc) | uVar4 * 0xc + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 == (uint *)0x0) {
        puVar5 = (uint *)0x0;
      }
      else {
        puVar5 = local_20 + 1;
        *local_20 = uVar4;
        _eh_vector_constructor_iterator_
                  (puVar5,0xc,uVar4,(_func_void_void_ptr *)&LAB_10001b10,FUN_10001180);
      }
      local_8 = 0xffffffff;
      local_20 = puVar5;
      if (puVar5 == (uint *)0x0) {
        (**(code **)(*piVar1 + 0x4c))(piVar1,local_24);
        ExceptionList = local_10;
        return 0x8007000e;
      }
    }
    local_1c = 0;
    puVar5 = local_20;
    if (0 < *(int *)((int)this + 0x18)) {
      do {
        iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,local_1c,&local_18);
        if (-1 < iVar3) {
          param_1 = (int *)0x0;
          local_8 = 3;
          iVar3 = (**(code **)(*piVar1 + 0x30))(piVar1,*local_18,&param_1,0,0,0);
          piVar2 = param_1;
          if (-1 < iVar3) {
            param_1 = (int *)0x0;
            if ((int *)*puVar5 != piVar2) {
              Ordinal_6((int *)*puVar5);
              *puVar5 = (uint)piVar2;
            }
            uVar4 = Ordinal_7(*puVar5);
            puVar5[1] = uVar4;
            puVar5[2] = *local_18;
          }
          (**(code **)(*piVar1 + 0x50))(piVar1,local_18);
          local_8 = 0xffffffff;
          Ordinal_6(param_1);
        }
        local_1c = local_1c + 1;
        puVar5 = puVar5 + 3;
      } while (local_1c < *(int *)((int)this + 0x18));
    }
    *(uint **)((int)this + 0x14) = local_20;
    (**(code **)(*piVar1 + 0x4c))(piVar1,local_24);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch_All@10001dea at 10001dea

undefined * Catch_All_10001dea(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10001df7;
}



// Function: FUN_10001e20 at 10001e20

void FUN_10001e20(int param_1)

{
  int *piVar1;
  void *pvVar2;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    pvVar2 = *(void **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (pvVar2 != (void *)0x0) {
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10001180);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10001e80 at 10001e80

undefined4 * __thiscall FUN_10001e80(void *this,LPCSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100251bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0xc);
  local_8 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 1;
    uVar2 = ConvertStringToBSTR(param_1);
    *puVar1 = uVar2;
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001f10 at 10001f10

undefined4 * __thiscall FUN_10001f10(void *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002246b;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = Ordinal_2(param_1,uVar1);
    *piVar2 = iVar3;
    if ((iVar3 == 0) && (param_1 != 0)) {
      _com_issue_error(-0x7ff8fff2);
    }
  }
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001fc0 at 10001fc0

void __fastcall FUN_10001fc0(int param_1)

{
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



// Function: FUN_10001fe0 at 10001fe0

void __thiscall FUN_10001fe0(void *this,int param_1)

{
  *(int *)((int)this + 0x10) = param_1;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  *(undefined2 *)((int)this + param_1 * 2) = 0;
  return;
}



// Function: FUN_10002000 at 10002000

void * FUN_10002000(char *param_1)

{
  void *pvVar1;
  undefined **local_10 [3];
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x80000000) &&
     (pvVar1 = operator_new((int)param_1 * 2), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_10002060 at 10002060

bool __thiscall FUN_10002060(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int *local_8;
  
  piVar2 = param_1;
                    /* WARNING: Load size is inaccurate */
  puVar1 = *this;
  if (puVar1 == (undefined4 *)0x0) {
    if (param_1 == (int *)0x0) {
      return true;
    }
  }
  else if (param_1 != (int *)0x0) {
    param_1 = (int *)0x0;
    local_8 = (int *)0x0;
    (**(code **)*puVar1)(puVar1,&DAT_10028450,&param_1);
    (**(code **)*piVar2)(piVar2,&DAT_10028450,&local_8);
    bVar3 = param_1 == local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    return bVar3;
  }
  return false;
}



// Function: FUN_100020f0 at 100020f0

undefined4 FUN_100020f0(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 != 0) &&
       ((((*param_3 != 0 || (param_3[1] != 0)) || (param_3[2] != 0xc0)) ||
        (param_3[3] != 0x46000000)))) {
      return 0x80040110;
    }
    uVar1 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
  }
  return uVar1;
}



// Function: FUN_10002150 at 10002150

undefined4 FUN_10002150(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_1003af94 + 4))();
    return 0;
  }
  (**(code **)(*DAT_1003af94 + 8))();
  return 0;
}



// Function: FUN_10002180 at 10002180

DWORD __fastcall FUN_10002180(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x20),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  *(undefined1 *)(param_1 + 0x38) = 1;
  if ((int)DVar2 < 0) {
    return DVar2;
  }
  return 0;
}



// Function: FUN_100021c0 at 100021c0

void __fastcall FUN_100021c0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100021e0 at 100021e0

undefined4 * __thiscall FUN_100021e0(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002220 at 10002220

int * __thiscall FUN_10002220(void *this,uint param_1,uint param_2)

{
  void *pvVar1;
  uint extraout_EAX;
  uint uVar2;
  int iVar3;
  uint extraout_ECX;
  void *pvVar4;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    param_1 = extraout_ECX;
  }
  uVar2 = uVar2 - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  if (param_2 != 0) {
    pvVar4 = this;
    pvVar1 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar1 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1 * 2),(void *)((int)pvVar1 + (param_1 + param_2) * 2),
            (uVar2 - param_2) * 2);
    iVar3 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar3;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + iVar3 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + iVar3 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_100022b0 at 100022b0

void __thiscall FUN_100022b0(void *this,uint param_1)

{
  uint uVar1;
  uint *puVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_38;
  undefined **local_28 [3];
  char *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022490;
  local_10 = ExceptionList;
  uStack_38 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  uVar5 = param_1 | 7;
  if (uVar5 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar4 = uVar1 >> 1;
    param_1 = uVar5;
    if ((uVar5 / 3 < uVar4) && (param_1 = uVar4 + uVar1, 0x7ffffffe - uVar4 < uVar1)) {
      param_1 = 0x7ffffffe;
    }
  }
  uVar5 = param_1 + 1;
  local_8 = 0;
  local_18 = this;
  puVar2 = &uStack_38;
  if ((uVar5 != 0) &&
     ((puVar2 = &uStack_38, 0x7fffffff < uVar5 ||
      (pvVar3 = operator_new(uVar5 * 2), puVar2 = (uint *)local_14, pvVar3 == (void *)0x0)))) {
    local_14 = (undefined1 *)puVar2;
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_1c);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_10033244);
  }
  local_14 = (undefined1 *)puVar2;
  FUN_10002397();
  return;
}



// Function: Catch_All@1000236b at 1000236b

undefined * Catch_All_1000236b(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10002000((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  return &DAT_1000238e;
}



// Function: FUN_10002397 at 10002397

void FUN_10002397(void)

{
  undefined4 *_Src;
  int iVar1;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 != 0) {
    _Src = unaff_EDI;
    if (7 < (uint)unaff_EDI[5]) {
      _Src = (undefined4 *)*unaff_EDI;
    }
    memcpy(unaff_EBX,_Src,iVar1 * 2);
    iVar1 = *(int *)(unaff_EBP + 0xc);
  }
  if (7 < (uint)unaff_EDI[5]) {
    operator_delete((void *)*unaff_EDI);
    iVar1 = *(int *)(unaff_EBP + 0xc);
  }
  *unaff_EDI = unaff_EBX;
  unaff_EDI[5] = unaff_ESI;
  unaff_EDI[4] = iVar1;
  if (7 < unaff_ESI) {
    unaff_EDI = unaff_EBX;
  }
  *(undefined2 *)((int)unaff_EDI + iVar1 * 2) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch_All@100023f7 at 100023f7

void Catch_All_100023f7(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10002430 at 10002430

undefined4 __thiscall FUN_10002430(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_10002060(this,(int *)*param_1);
  if (!bVar1) {
    uVar2 = Ordinal_31(this,*param_1,&DAT_1002847c);
    return uVar2;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10002470 at 10002470

LONG FUN_10002470(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1003af94 + 4))();
  }
  return LVar1;
}



// Function: FUN_100024a0 at 100024a0

LONG FUN_100024a0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
      return 0;
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1003af94 + 8))();
  }
  return LVar1;
}



// Function: FUN_100024f0 at 100024f0

void FUN_100024f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_100284a8,param_2,param_3);
  return;
}



// Function: FUN_10002510 at 10002510

undefined4 * __thiscall FUN_10002510(void *this,byte param_1)

{
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002550 at 10002550

void __thiscall FUN_10002550(void *this,undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar3;
  int iVar4;
  int *local_22c;
  int *local_228;
  int *local_224;
  int *local_220;
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_100224dc;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000279b;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)DAT_1003af94 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_22c = (int *)0x0;
    if (((((DAT_1003af98 == *piVar1) && (DAT_1003af9c == piVar1[1])) && (DAT_1003afa0 == piVar1[2]))
        && ((DAT_1003afa4 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_1003b07c,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10002776;
      local_220 = (int *)0x0;
      iVar4 = Ordinal_161(local_21c,&local_22c);
      FUN_10001c00((int *)&local_220);
    }
    else {
      iVar4 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                          param_1,&local_22c,uVar2);
    }
    if (-1 < iVar4) {
      local_224 = (int *)0x0;
                    /* WARNING: Load size is inaccurate */
      local_8._0_1_ = 1;
      iVar4 = (**(code **)(*local_22c + 0x18))(local_22c,*this,&local_224);
      if (-1 < iVar4) {
        local_228 = local_224;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 4))(local_224);
        }
        local_220 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar4 = (**(code **)*local_224)(local_224,&DAT_10028440,&local_220);
        if (-1 < iVar4) {
          FUN_10002430(&local_228,&local_220);
        }
        *(int **)((int)this + 0xc) = local_228;
        local_228 = (int *)0x0;
        FUN_10001ac0(DAT_1003af94,FUN_10001e20,this);
        local_8._0_1_ = 2;
        if (local_220 != (int *)0x0) {
          (**(code **)(*local_220 + 8))(local_220);
        }
        local_8._0_1_ = 1;
        if (local_228 != (int *)0x0) {
          (**(code **)(*local_228 + 8))(local_228);
        }
      }
      (**(code **)(*local_22c + 8))(local_22c);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_224 != (int *)0x0) {
        (**(code **)(*local_224 + 8))(local_224);
      }
    }
  }
LAB_10002776:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_10001c50(this,*(int **)((int)this + 0xc));
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_1000279b:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100027c0 at 100027c0

void __fastcall FUN_100027c0(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_100027f0 at 100027f0

bool __thiscall FUN_100027f0(void *this,uint param_1,char param_2)

{
  uint uVar1;
  void *extraout_ECX;
  void *pvVar2;
  uint uVar3;
  
  pvVar2 = this;
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    pvVar2 = extraout_ECX;
  }
  uVar1 = *(uint *)((int)this + 0x14);
  if (uVar1 < param_1) {
    FUN_100022b0(pvVar2,param_1);
    return param_1 != 0;
  }
  if ((param_2 != '\0') && (param_1 < 8)) {
    uVar3 = *(uint *)((int)this + 0x10);
    if (param_1 < *(uint *)((int)this + 0x10)) {
      uVar3 = param_1;
    }
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
      if (uVar3 != 0) {
        memcpy(this,pvVar2,uVar3 * 2);
      }
      operator_delete(pvVar2);
    }
    *(uint *)((int)this + 0x10) = uVar3;
    *(undefined4 *)((int)this + 0x14) = 7;
    *(undefined2 *)((int)this + uVar3 * 2) = 0;
    return param_1 != 0;
  }
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    *(undefined2 *)this = 0;
  }
  return param_1 != 0;
}



// Function: FUN_100028b0 at 100028b0

int __fastcall FUN_100028b0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002253f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  local_8 = 0;
  FUN_100146d0((undefined4 *)(param_1 + 0x30));
  local_8._0_1_ = 1;
  FUN_1000b130((void *)(param_1 + 0x3c),(undefined4 *)(param_1 + 0x30));
  ((LPCRITICAL_SECTION)(param_1 + 0x104))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x118) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x104),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      FUN_10001070(DVar2);
    }
  }
  ((LPCRITICAL_SECTION)(param_1 + 0x11c))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  *(undefined4 *)(param_1 + 0x130) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x11c),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      FUN_10001070(DVar2);
    }
  }
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 7;
  *(undefined2 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x168) = 7;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined2 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x184) = 7;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined2 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 7;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined2 *)(param_1 + 0x18c) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002a10 at 10002a10

void FUN_10002a10(undefined4 param_1)

{
  FUN_100012f0(DAT_1003af94,0x66,param_1,(int *)0x0);
  return;
}



// Function: FUN_10002a30 at 10002a30

undefined4 FUN_10002a30(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD DVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022560;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  piVar1 = (int *)operator_new(0x28);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    *(undefined1 *)(piVar1 + 8) = 0;
    *piVar1 = (int)ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) {
    ExceptionList = local_10;
    return 0x8007000e;
  }
  DVar5 = 0;
  piVar1[9] = param_1;
  BVar2 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar1 + 2),0);
  if (BVar2 == 0) {
    DVar5 = GetLastError();
    if (0 < (int)DVar5) {
      DVar5 = DVar5 & 0xffff | 0x80070000;
    }
    if ((int)DVar5 < 0) goto LAB_10002b17;
  }
  *(undefined1 *)(piVar1 + 8) = 1;
  if ((-1 < (int)DVar5) && (iVar3 = (**(code **)*piVar1)(piVar1,param_2,param_3), iVar3 == 0)) {
    ExceptionList = local_10;
    return 0;
  }
LAB_10002b17:
  (**(code **)(*piVar1 + 0x14))(1);
  uVar4 = FUN_10002b2d();
  return uVar4;
}



// Function: Catch_All@10002b24 at 10002b24

undefined * Catch_All_10002b24(void)

{
  return &DAT_10002b2a;
}



// Function: FUN_10002b2d at 10002b2d

void FUN_10002b2d(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002b50 at 10002b50

void __fastcall FUN_10002b50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10022596;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (7 < *(uint *)(param_1 + 0x1a0)) {
    operator_delete(*(void **)(param_1 + 0x18c));
  }
  *(undefined4 *)(param_1 + 0x1a0) = 7;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined2 *)(param_1 + 0x18c) = 0;
  if (7 < *(uint *)(param_1 + 0x184)) {
    operator_delete(*(void **)(param_1 + 0x170));
  }
  *(undefined4 *)(param_1 + 0x184) = 7;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined2 *)(param_1 + 0x170) = 0;
  if (7 < *(uint *)(param_1 + 0x168)) {
    operator_delete(*(void **)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0x168) = 7;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined2 *)(param_1 + 0x154) = 0;
  if (7 < *(uint *)(param_1 + 0x14c)) {
    operator_delete(*(void **)(param_1 + 0x138));
  }
  *(undefined4 *)(param_1 + 0x14c) = 7;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined2 *)(param_1 + 0x138) = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  FUN_1000b220(param_1 + 0x3c);
  local_8 = local_8 & 0xffffff00;
  FUN_10014400((int *)(param_1 + 0x30));
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002c90 at 10002c90

void __fastcall FUN_10002c90(int param_1)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  uint uStack_8;
  
  puStack_c = &LAB_10022596;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  uStack_8 = 1;
  if (7 < *(uint *)(param_1 + 0x1a0)) {
    operator_delete(*(void **)(param_1 + 0x18c));
  }
  *(undefined4 *)(param_1 + 0x1a0) = 7;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined2 *)(param_1 + 0x18c) = 0;
  if (7 < *(uint *)(param_1 + 0x184)) {
    operator_delete(*(void **)(param_1 + 0x170));
  }
  *(undefined4 *)(param_1 + 0x184) = 7;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined2 *)(param_1 + 0x170) = 0;
  if (7 < *(uint *)(param_1 + 0x168)) {
    operator_delete(*(void **)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0x168) = 7;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined2 *)(param_1 + 0x154) = 0;
  if (7 < *(uint *)(param_1 + 0x14c)) {
    operator_delete(*(void **)(param_1 + 0x138));
  }
  *(undefined4 *)(param_1 + 0x14c) = 7;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined2 *)(param_1 + 0x138) = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x104));
  FUN_1000b220(param_1 + 0x3c);
  uStack_8 = uStack_8 & 0xffffff00;
  FUN_10014400((int *)(param_1 + 0x30));
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = pvStack_10;
  return;
}



// Function: FUN_10002ca0 at 10002ca0

undefined4 FUN_10002ca0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10002cc0 at 10002cc0

void FUN_10002cc0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10002ce0 at 10002ce0

void FUN_10002ce0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10002d00 at 10002d00

void FUN_10002d00(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_10002d20 at 10002d20

void FUN_10002d20(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002d00(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10002d30 at 10002d30

void FUN_10002d30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002d00(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10002d40 at 10002d40

void FUN_10002d40(int param_1)

{
  FUN_10002ce0(param_1 + -4);
  return;
}



// Function: FUN_10002d50 at 10002d50

void FUN_10002d50(int param_1)

{
  FUN_10002ce0(param_1 + -8);
  return;
}



// Function: FUN_10002d60 at 10002d60

void FUN_10002d60(int param_1)

{
  FUN_10002ce0(param_1 + -0xc);
  return;
}



// Function: FUN_10002d70 at 10002d70

void FUN_10002d70(int param_1)

{
  FUN_10002cc0(param_1 + -4);
  return;
}



// Function: FUN_10002d80 at 10002d80

void FUN_10002d80(int param_1)

{
  FUN_10002cc0(param_1 + -8);
  return;
}



// Function: FUN_10002d90 at 10002d90

void FUN_10002d90(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002d00(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10002da0 at 10002da0

void FUN_10002da0(int param_1)

{
  FUN_10002cc0(param_1 + -0xc);
  return;
}



// Function: FUN_10002db0 at 10002db0

undefined4 __thiscall
FUN_10002db0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  uVar2 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar2 = FUN_10002550(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar3 = lstrlenW((LPCWSTR)*param_2);
      iVar9 = *(int *)((int)this + 0x18) + -1;
      if (-1 < iVar9) {
        iVar4 = iVar9 * 0xc;
        piVar5 = (int *)(iVar4 + 4 + *(int *)((int)this + 0x14));
        do {
          if (iVar3 == *piVar5) {
            piVar8 = (int *)*param_2;
            puVar1 = (undefined4 *)(iVar4 + *(int *)((int)this + 0x14));
            piVar7 = (int *)*puVar1;
            for (uVar6 = puVar1[1] * 2; 3 < uVar6; uVar6 = uVar6 - 4) {
              if (*piVar7 != *piVar8) goto LAB_10002e7e;
              piVar8 = piVar8 + 1;
              piVar7 = piVar7 + 1;
            }
            if ((uVar6 == 0) ||
               (((char)*piVar8 == (char)*piVar7 &&
                ((uVar6 < 2 ||
                 ((*(char *)((int)piVar8 + 1) == *(char *)((int)piVar7 + 1) &&
                  ((uVar6 < 3 || (*(char *)((int)piVar8 + 2) == *(char *)((int)piVar7 + 2)))))))))))
            {
              *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + iVar9 * 0xc);
              return 0;
            }
          }
LAB_10002e7e:
          piVar5 = piVar5 + -3;
          iVar4 = iVar4 + -0xc;
          iVar9 = iVar9 + -1;
        } while (-1 < iVar9);
      }
    }
    uVar2 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                      (*(int **)((int)this + 0xc),param_2,param_3,param_5);
  }
  return uVar2;
}



// Function: FUN_10002ed0 at 10002ed0

void __fastcall FUN_10002ed0(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10002f20 at 10002f20

ULONG __thiscall FUN_10002f20(void *this,int *param_1,int *param_2)

{
  int iVar1;
  ULONG UVar2;
  LONG LVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100225d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *param_2;
  }
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  UVar2 = (**(code **)(*this + 0x1c))(this,iVar1,iVar4);
  if ((int)UVar2 < 0) {
    _com_issue_errorex(UVar2,(IUnknown *)this,(_GUID *)&DAT_1002856c);
  }
  if (((param_1 != (int *)0x0) && (LVar3 = InterlockedDecrement(param_1 + 2), LVar3 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete__((void *)param_1[1]);
    }
    operator_delete(param_1);
  }
  if (((param_2 != (int *)0x0) && (LVar3 = InterlockedDecrement(param_2 + 2), LVar3 == 0)) &&
     (param_2 != (int *)0x0)) {
    if (*param_2 != 0) {
      Ordinal_6(*param_2);
    }
    if ((void *)param_2[1] != (void *)0x0) {
      operator_delete__((void *)param_2[1]);
    }
    operator_delete(param_2);
  }
  ExceptionList = local_10;
  return UVar2;
}



// Function: FUN_10003030 at 10003030

int * __thiscall FUN_10003030(void *this,int *param_1,uint param_2,uint param_3)

{
  size_t _Size;
  void *_Dst;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_1[4];
  piVar1 = param_1;
  if (uVar2 < param_2) {
    std::_Xout_of_range("invalid string position");
    piVar1 = extraout_ECX;
  }
  uVar2 = uVar2 - param_2;
  if (param_3 < uVar2) {
    uVar2 = param_3;
  }
  if ((int *)this == piVar1) {
    FUN_10002220(this,uVar2 + param_2,0xffffffff);
    FUN_10002220(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_100022b0(this,uVar2);
    piVar1 = param_1;
    if (uVar2 == 0) {
      return (int *)this;
    }
  }
  else if (uVar2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined2 *)this = 0;
    return (int *)this;
  }
  if (7 < (uint)piVar1[5]) {
    piVar1 = (int *)*piVar1;
  }
  _Dst = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    _Dst = *this;
  }
  _Size = uVar2 * 2;
  memcpy(_Dst,(void *)((int)piVar1 + param_2 * 2),_Size);
  *(uint *)((int)this + 0x10) = uVar2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)(_Size + (int)this) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return (int *)this;
}



// Function: FUN_10003130 at 10003130

int * __thiscall FUN_10003130(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  size_t _Size;
  int *piVar2;
  void *pvVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar2 = (int *)this;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar3 = this;
      if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      if (param_1 < (int *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2)) {
        pvVar3 = this;
        if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
          pvVar3 = *this;
        }
        piVar2 = FUN_10003030(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_100022b0(this,param_2);
    if (param_2 == 0) {
      return (int *)this;
    }
  }
  else if (param_2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined2 *)this = 0;
    return (int *)this;
  }
  pvVar3 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar3 = *this;
  }
  _Size = param_2 * 2;
  memcpy(pvVar3,param_1,_Size);
  *(uint *)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)(_Size + (int)this) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return (int *)this;
}



// Function: FUN_10003230 at 10003230

undefined4 FUN_10003230(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  LONG LVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  void *extraout_ECX_02;
  void *this;
  uint uStack_4c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022623;
  local_10 = ExceptionList;
  uStack_4c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4c;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xfc));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x100285b8);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar4,piVar1);
  FUN_10001f10(&local_18,param_2);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_1000b8b0((void *)(param_1 + 0x34),(int *)&local_18);
  if (local_18 != (int *)0x0) {
    LVar3 = InterlockedDecrement(local_18 + 2);
    if ((LVar3 == 0) && (local_18 != (int *)0x0)) {
      if (*local_18 != 0) {
        Ordinal_6();
      }
      if ((void *)local_18[1] != (void *)0x0) {
        operator_delete__((void *)local_18[1]);
      }
      operator_delete(local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xfc));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10003385 at 10003385

undefined1 * Catch_10003385(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureComponent.cpp",0x51,
                       "CAutoConfigureComponent::AutoDetectAdapterConfiguration",0x6dd8928c,
                       0x4cd9a30c,0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_100033d0;
}



// Function: Catch_All@100033ef at 100033ef

undefined1 * Catch_All_100033ef(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"AutoConfigureComponent.cpp",0x51,
                       "CAutoConfigureComponent::AutoDetectAdapterConfiguration",0x6dd8928c,
                       0x4cd9a30c,0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x10003455;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_100033d0;
}



// Function: FUN_10003460 at 10003460

undefined4 FUN_10003460(int param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002266b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x100286f0);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar3,piVar1);
  FUN_10007cd0((int *)(param_1 + 0x34));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000355c at 1000355c

undefined1 * Catch_1000355c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureComponent.cpp",0x62,
                       "CAutoConfigureComponent::Cancel",0x6dd8928c,0x4cd9a30c,0xdfac5497,0x2a362ef3
                      );
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_100035a7;
}



// Function: Catch_All@100035c6 at 100035c6

undefined1 * Catch_All_100035c6(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"AutoConfigureComponent.cpp",0x62,
                       "CAutoConfigureComponent::Cancel",0x6dd8928c,0x4cd9a30c,0xdfac5497,0x2a362ef3
                      );
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x1000362c;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_100035a7;
}



// Function: FUN_10003640 at 10003640

uint FUN_10003640(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  int *piVar2;
  int iVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100226bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xf8);
  EnterCriticalSection(lpCriticalSection);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar2 = iVar3;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa8,0x10028770);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar4,piVar2);
  switch(*(undefined4 *)(param_1 + 0x128)) {
  case 0:
  case 1:
    FUN_10006f50((void *)(param_1 + 0x30),(int *)(param_1 + 300));
    break;
  case 99:
    FUN_10006ef0((void *)(param_1 + 0x30),(int *)(param_1 + 0x164));
    FUN_10006f10((void *)(param_1 + 0x30),(int *)(param_1 + 0x180));
    break;
  case 0xffffffff:
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return 0x80070057;
  }
  FUN_10006f30((void *)(param_1 + 0x30),(int *)(param_1 + 0x148));
  cVar1 = FUN_1000bc90(*(int *)(param_1 + 0x128));
  *(undefined4 *)(param_1 + 0x128) = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return (uint)(cVar1 == '\0');
}



// Function: Catch@100037d5 at 100037d5

undefined1 * Catch_100037d5(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x1c),"AutoConfigureComponent.cpp",0x86,
                       "CAutoConfigureComponent::ValidateAdapterConfiguration",0x6dd8928c,0x4cd9a30c
                       ,0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_10003823;
}



// Function: Catch_All@10003842 at 10003842

undefined1 * Catch_All_10003842(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x34) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x34),"AutoConfigureComponent.cpp",0x86,
                       "CAutoConfigureComponent::ValidateAdapterConfiguration",0x6dd8928c,0x4cd9a30c
                       ,0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x100038ab;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &LAB_10003823;
}



// Function: FUN_10003930 at 10003930

undefined4 FUN_10003930(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002270b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x100));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x10028808);
  this = *(void **)(param_1 + 0x30);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar3,piVar1);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x100));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10003a2d at 10003a2d

undefined1 * Catch_10003a2d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureComponent.cpp",0x9d,
                       "CAutoConfigureComponent::put_Group",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_10003a7b;
}



// Function: Catch_All@10003a9a at 10003a9a

undefined1 * Catch_All_10003a9a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"AutoConfigureComponent.cpp",0x9d,
                       "CAutoConfigureComponent::put_Group",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x10003b03;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_10003a7b;
}



// Function: FUN_10003b10 at 10003b10

undefined4 FUN_10003b10(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002275b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x10028878);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar3,piVar1);
  *(undefined4 *)(param_1 + 0x128) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10003c10 at 10003c10

undefined1 * Catch_10003c10(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureComponent.cpp",0x120,
                       "CAutoConfigureComponent::put_DLAType",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_10003c5e;
}



// Function: Catch_All@10003c7d at 10003c7d

undefined1 * Catch_All_10003c7d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"AutoConfigureComponent.cpp",0x120,
                       "CAutoConfigureComponent::put_DLAType",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x10003ce6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_10003c5e;
}



// Function: FUN_10003cf0 at 10003cf0

undefined4 FUN_10003cf0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1003a5d8 == (int *)0x0) {
    uVar1 = FUN_10002550(&PTR_DAT_1003a5cc,param_3);
  }
  *param_4 = DAT_1003a5d8;
  if (DAT_1003a5d8 != (int *)0x0) {
    (**(code **)(*DAT_1003a5d8 + 4))(DAT_1003a5d8);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10003d50 at 10003d50

void FUN_10003d50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1003a5d8 == (int *)0x0) || (DAT_1003a5e0 == 0)) {
    FUN_10002550(&PTR_DAT_1003a5cc,param_4);
  }
  if (DAT_1003a5d8 != (int *)0x0) {
    (**(code **)(*DAT_1003a5d8 + 0x2c))
              (DAT_1003a5d8,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10003db0 at 10003db0

undefined4 FUN_10003db0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1003a5f4 == (int *)0x0) {
    uVar1 = FUN_10002550(&PTR_DAT_1003a5e8,param_3);
  }
  *param_4 = DAT_1003a5f4;
  if (DAT_1003a5f4 != (int *)0x0) {
    (**(code **)(*DAT_1003a5f4 + 4))(DAT_1003a5f4);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10003e10 at 10003e10

undefined4 FUN_10003e10(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1003a610 == (int *)0x0) {
    uVar1 = FUN_10002550(&PTR_DAT_1003a604,param_3);
  }
  *param_4 = DAT_1003a610;
  if (DAT_1003a610 != (int *)0x0) {
    (**(code **)(*DAT_1003a610 + 4))(DAT_1003a610);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10003e70 at 10003e70

void FUN_10003e70(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_10003e90 at 10003e90

LONG FUN_10003e90(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_10003ec0 at 10003ec0

void FUN_10003ec0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10028998,param_2,param_3);
  return;
}



// Function: FUN_10003ee0 at 10003ee0

void FUN_10003ee0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003ec0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10003ef0 at 10003ef0

void FUN_10003ef0(int param_1)

{
  FUN_10003e90((int *)(param_1 + -4));
  return;
}



// Function: FUN_10003f00 at 10003f00

void FUN_10003f00(int param_1)

{
  FUN_10003e90((int *)(param_1 + -8));
  return;
}



// Function: FUN_10003f10 at 10003f10

void FUN_10003f10(int param_1)

{
  FUN_10003e90((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10003f20 at 10003f20

void FUN_10003f20(int param_1)

{
  FUN_10003e70(param_1 + -4);
  return;
}



// Function: FUN_10003f30 at 10003f30

void FUN_10003f30(int param_1)

{
  FUN_10003e70(param_1 + -8);
  return;
}



// Function: FUN_10003f40 at 10003f40

void FUN_10003f40(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003ec0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10003f50 at 10003f50

void FUN_10003f50(int param_1)

{
  FUN_10003e70(param_1 + -0xc);
  return;
}



// Function: FUN_10003f60 at 10003f60

void FUN_10003f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003ec0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10003f70 at 10003f70

undefined4 * __thiscall FUN_10003f70(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002278b;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CAutoConfigureComponent>::vftable;
  FUN_100028b0((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 0x10) =
       ATL::CComContainedObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 0x14) =
       ATL::CComContainedObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 0x18) =
       ATL::CComContainedObject<class_CAutoConfigureComponent>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 0;
  (**(code **)(*DAT_1003af94 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10004000 at 10004000

undefined4 FUN_10004000(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  uVar1 = Ordinal_32(param_1 + 3,&PTR_DAT_10028998,param_2,param_3);
  return uVar1;
}



// Function: FUN_10004070 at 10004070

void FUN_10004070(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10004090 at 10004090

LONG FUN_10004090(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_100040c0 at 100040c0

undefined4 * __thiscall FUN_100040c0(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<class_CAutoConfigureComponent>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<class_CAutoConfigureComponent>::vftable;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1003af94 + 8))();
  FUN_10002b50((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004120 at 10004120

undefined4 * __thiscall FUN_10004120(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227bb;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CAutoConfigureComponent>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  local_8 = 0;
  (**(code **)(*DAT_1003af94 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10002b50((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100041a0 at 100041a0

void FUN_100041a0(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022803;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffb0,0x10028a78);
  this = *(void **)(param_1 + 0x30);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(this,piVar3,piVar1);
  iVar2 = FUN_10002db0(&PTR_DAT_1003a5e8,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x10000;
    ExceptionList = local_10;
    return;
  }
  iVar2 = FUN_10002db0(&PTR_DAT_1003a5cc,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x20000;
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@100042cb at 100042cb

undefined * Catch_100042cb(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x1c),"AutoConfigureComponent.cpp",0xf0,
                       "CAutoConfigureComponent::GetIDsOfNames",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  return &DAT_10004319;
}



// Function: Catch_All@10004330 at 10004330

undefined * Catch_All_10004330(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x2c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x2c),"AutoConfigureComponent.cpp",0xf0,
                       "CAutoConfigureComponent::GetIDsOfNames",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  uStack0000001c = 0x10004399;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return &DAT_10004319;
}



// Function: FUN_100043a0 at 100043a0

void FUN_100043a0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  if ((param_2 & 0xffff0000) == 0x10000) {
    if ((DAT_1003a5f4 == (int *)0x0) || (DAT_1003a5fc == 0)) {
      FUN_10002550(&PTR_DAT_1003a5e8,param_4);
    }
    if (DAT_1003a5f4 != (int *)0x0) {
      (**(code **)(*DAT_1003a5f4 + 0x2c))
                (DAT_1003a5f4,param_1 + 4,param_2 & 0xffff,param_5,param_6,param_7,param_8,param_9);
    }
  }
  else if ((param_2 & 0xffff0000) == 0x20000) {
    FUN_10003d50(param_1,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  return;
}



// Function: FUN_10004450 at 10004450

undefined4 FUN_10004450(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD DVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022820;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  piVar1 = (int *)operator_new(0x1a8);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_100028b0((int)piVar1);
    *piVar1 = (int)ATL::CComObject<class_CAutoConfigureComponent>::vftable;
    piVar1[1] = (int)ATL::CComObject<class_CAutoConfigureComponent>::vftable;
    piVar1[2] = (int)ATL::CComObject<class_CAutoConfigureComponent>::vftable;
    piVar1[3] = (int)ATL::CComObject<class_CAutoConfigureComponent>::vftable;
    (**(code **)(*DAT_1003af94 + 4))();
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) {
    ExceptionList = local_10;
    return 0x8007000e;
  }
  InterlockedIncrement(piVar1 + 4);
  DVar5 = 0;
  BVar2 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar1 + 5),0);
  if (BVar2 == 0) {
    DVar5 = GetLastError();
    if (0 < (int)DVar5) {
      DVar5 = DVar5 & 0xffff | 0x80070000;
    }
    if ((int)DVar5 < 0) goto LAB_1000454e;
  }
  *(undefined1 *)(piVar1 + 0xb) = 1;
  if (-1 < (int)DVar5) {
    piVar1[0x4d] = -1;
    DVar5 = 0;
  }
LAB_1000454e:
  InterlockedDecrement(piVar1 + 4);
  if ((DVar5 == 0) && (iVar3 = (**(code **)*piVar1)(piVar1,param_2,param_3), iVar3 == 0)) {
    ExceptionList = local_10;
    return 0;
  }
  (**(code **)(*piVar1 + 0x10))(1);
  uVar4 = FUN_10004587();
  return uVar4;
}



// Function: Catch_All@1000457e at 1000457e

undefined * Catch_All_1000457e(void)

{
  return &DAT_10004584;
}



// Function: FUN_10004587 at 10004587

void FUN_10004587(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100045a0 at 100045a0

undefined4 FUN_100045a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  code *pcVar1;
  void *this;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002284b;
  local_10 = ExceptionList;
  piVar5 = (int *)0x0;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x1b4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    piVar5 = FUN_10003f70(this,param_1);
  }
  local_8 = 0xffffffff;
  if (piVar5 == (int *)0x0) {
    ExceptionList = local_10;
    return 0x8007000e;
  }
  DVar2 = FUN_10002180((int)piVar5);
  if (-1 < (int)DVar2) {
    pcVar1 = *(code **)*piVar5;
    piVar5[0x50] = -1;
    iVar3 = (*pcVar1)(piVar5,param_2,param_3);
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return 0;
    }
  }
  (**(code **)(*piVar5 + 0xc))(1);
  uVar4 = FUN_10004669();
  return uVar4;
}



// Function: Catch_All@10004660 at 10004660

undefined * Catch_All_10004660(void)

{
  return &DAT_10004666;
}



// Function: FUN_10004669 at 10004669

void FUN_10004669(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10004680 at 10004680

void FUN_10004680(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_100043a0(param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_10004690 at 10004690

void FUN_10004690(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_100043a0(param_1 + -8,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_100046a0 at 100046a0

void FUN_100046a0(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  FUN_100041a0(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100046b0 at 100046b0

void FUN_100046b0(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  FUN_100041a0(param_1 + -8,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100046c0 at 100046c0

undefined2 * __thiscall FUN_100046c0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)this = 0;
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10003130(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return (undefined2 *)this;
}



// Function: FUN_10004710 at 10004710

undefined4 * __thiscall FUN_10004710(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(undefined4 *)((int)this + 0x14) = 7;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined2 *)this = 0;
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,param_1[4] * 2 + 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    param_1[5] = 7;
    param_1[4] = 0;
    *(undefined2 *)param_1 = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_10004790 at 10004790

void FUN_10004790(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10004450(0,param_2,param_3);
    return;
  }
  FUN_100045a0(param_1,param_2,param_3);
  return;
}



// Function: FUN_100047c0 at 100047c0

void FUN_100047c0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003a11c);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004850 at 10004850

void FUN_10004850(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *piVar4;
  void *extraout_ECX_00;
  void *this;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100228a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x100));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar4 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x10028c40);
  this = *(void **)(param_1 + 0x30);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar4,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100047c0();
    local_8._0_1_ = 5;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x2c),300,0x80004003,0x10028c40,L"AutoConfigureComponent.cpp",
                 (undefined1 *)0xb4,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x34);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x100));
  FUN_100049fb();
  return;
}



// Function: Catch@100049a2 at 100049a2

undefined * Catch_100049a2(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureComponent.cpp",0xb9,
                       "CAutoConfigureComponent::get_Group",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_100049f0;
}



// Function: FUN_100049fb at 100049fb

void FUN_100049fb(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004a13;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10004a19 at 10004a19

undefined * Catch_All_10004a19(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureComponent.cpp",0xb9,
                       "CAutoConfigureComponent::get_Group",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10004a82;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_100049f0;
}



// Function: FUN_10004a90 at 10004a90

void FUN_10004a90(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  LONG LVar5;
  int *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  uint uStack_60;
  int *local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002290b;
  local_10 = ExceptionList;
  uStack_60 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = uStack_60;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar3 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x10028cc8);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar3,piVar1);
  piVar3 = FUN_10001f10(&local_38,(int)local_38);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1001f420((undefined2 *)local_34,piVar3);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10004710((void *)(param_1 + 300),puVar4);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  piVar3 = local_38;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  if (local_38 != (int *)0x0) {
    LVar5 = InterlockedDecrement(local_38 + 2);
    if ((LVar5 == 0) && (piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_10004c6d();
  return;
}



// Function: Catch@10004c14 at 10004c14

undefined * Catch_10004c14(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureComponent.cpp",0x133,
                       "CAutoConfigureComponent::put_Port",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10004c62;
}



// Function: FUN_10004c6d at 10004c6d

void FUN_10004c6d(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004c85;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10004c8b at 10004c8b

undefined * Catch_All_10004c8b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureComponent.cpp",0x133,
                       "CAutoConfigureComponent::put_Port",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10004cf4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10004c62;
}



// Function: FUN_10004d00 at 10004d00

void FUN_10004d00(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  LONG LVar5;
  int *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  uint uStack_60;
  int *local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002296b;
  local_10 = ExceptionList;
  uStack_60 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = uStack_60;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar3 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x10028d58);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar3,piVar1);
  piVar3 = FUN_10001f10(&local_38,(int)local_38);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1001f420((undefined2 *)local_34,piVar3);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10004710((void *)(param_1 + 0x148),puVar4);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  piVar3 = local_38;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  if (local_38 != (int *)0x0) {
    LVar5 = InterlockedDecrement(local_38 + 2);
    if ((LVar5 == 0) && (piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_10004edd();
  return;
}



// Function: Catch@10004e84 at 10004e84

undefined * Catch_10004e84(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureComponent.cpp",0x146,
                       "CAutoConfigureComponent::put_Protocol",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10004ed2;
}



// Function: FUN_10004edd at 10004edd

void FUN_10004edd(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004ef5;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10004efb at 10004efb

undefined * Catch_All_10004efb(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureComponent.cpp",0x146,
                       "CAutoConfigureComponent::put_Protocol",0x6dd8928c,0x4cd9a30c,0xdfac5497,
                       0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10004f64;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10004ed2;
}



// Function: FUN_10004f70 at 10004f70

void FUN_10004f70(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  LONG LVar5;
  int *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  uint uStack_60;
  int *local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100229cb;
  local_10 = ExceptionList;
  uStack_60 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = uStack_60;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar3 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x10028df8);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar3,piVar1);
  piVar3 = FUN_10001f10(&local_38,(int)local_38);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1001f420((undefined2 *)local_34,piVar3);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10004710((void *)(param_1 + 0x164),puVar4);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  piVar3 = local_38;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  if (local_38 != (int *)0x0) {
    LVar5 = InterlockedDecrement(local_38 + 2);
    if ((LVar5 == 0) && (piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_1000514d();
  return;
}



// Function: Catch@100050f4 at 100050f4

undefined * Catch_100050f4(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureComponent.cpp",0x159,
                       "CAutoConfigureComponent::put_RP1210INIFile",0x6dd8928c,0x4cd9a30c,0xdfac5497
                       ,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10005142;
}



// Function: FUN_1000514d at 1000514d

void FUN_1000514d(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10005165;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1000516b at 1000516b

undefined * Catch_All_1000516b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureComponent.cpp",0x159,
                       "CAutoConfigureComponent::put_RP1210INIFile",0x6dd8928c,0x4cd9a30c,0xdfac5497
                       ,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x100051d4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10005142;
}



// Function: FUN_100051e0 at 100051e0

void FUN_100051e0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  LONG LVar5;
  int *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  uint uStack_60;
  int *local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022a2b;
  local_10 = ExceptionList;
  uStack_60 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = uStack_60;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar3 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureComponent.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x10028eb0);
  this = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar3,piVar1);
  piVar3 = FUN_10001f10(&local_38,(int)local_38);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1001f420((undefined2 *)local_34,piVar3);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10004710((void *)(param_1 + 0x180),puVar4);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  piVar3 = local_38;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
  if (local_38 != (int *)0x0) {
    LVar5 = InterlockedDecrement(local_38 + 2);
    if ((LVar5 == 0) && (piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_100053bd();
  return;
}



// Function: Catch@10005364 at 10005364

undefined * Catch_10005364(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureComponent.cpp",0x16c,
                       "CAutoConfigureComponent::put_RP1210DeviceID",0x6dd8928c,0x4cd9a30c,
                       0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_100053b2;
}



// Function: FUN_100053bd at 100053bd

void FUN_100053bd(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100053d5;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@100053db at 100053db

undefined * Catch_All_100053db(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureComponent.cpp",0x16c,
                       "CAutoConfigureComponent::put_RP1210DeviceID",0x6dd8928c,0x4cd9a30c,
                       0xdfac5497,0x2a362ef3);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10005444;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_100053b2;
}



// Function: FUN_10005450 at 10005450

void FUN_10005450(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  FUN_1000c7a0(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10005460 at 10005460

void FUN_10005460(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_1000ed90(param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_10005470 at 10005470

void FUN_10005470(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_1000c9a0(param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_10005480 at 10005480

void FUN_10005480(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  FUN_1000eb90(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10005490 at 10005490

undefined4 FUN_10005490(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + param_4);
  uVar2 = 0x80004002;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
  }
  return uVar2;
}



// Function: FUN_100054c0 at 100054c0

void FUN_100054c0(void)

{
  return;
}



// Function: FUN_100054d0 at 100054d0

void FUN_100054d0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_100054f0 at 100054f0

LONG FUN_100054f0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_10005520 at 10005520

undefined4 * __thiscall FUN_10005520(void *this,byte param_1)

{
  int *piVar1;
  
  *(undefined ***)this = ATL::CComObject<class_CConnectionProperties>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CConnectionProperties>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<class_CConnectionProperties>::vftable;
  *(undefined4 *)((int)this + 0xc) = 0xc0000001;
  piVar1 = *(int **)((int)this + 0x134);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 0x134) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*DAT_1003af94 + 8))();
  FUN_1000e540((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005590 at 10005590

undefined4 * __thiscall FUN_10005590(void *this,byte param_1)

{
  int *piVar1;
  
  *(undefined ***)this = ATL::CComObject<class_CConnectionCollection>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CConnectionCollection>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<class_CConnectionCollection>::vftable;
  *(undefined4 *)((int)this + 0xc) = 0xc0000001;
  piVar1 = *(int **)((int)this + 0x60);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 0x60) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*DAT_1003af94 + 8))();
  FUN_1000d760((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005600 at 10005600

uint __thiscall FUN_10005600(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  uint extraout_EAX;
  ushort *puVar1;
  undefined4 *extraout_ECX;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
  }
  if (uVar2 - param_1 < param_2) {
    param_2 = uVar2 - param_1;
  }
  uVar2 = param_2;
  if (param_4 <= param_2) {
    uVar2 = param_4;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  puVar1 = (ushort *)((int)this + param_1 * 2);
  do {
    if (uVar2 == 0) {
LAB_10005668:
      if (param_4 <= param_2) {
        return (uint)(param_2 != param_4);
      }
      return 0xffffffff;
    }
    if (*puVar1 != *param_3) {
      uVar2 = (-(uint)(*puVar1 < *param_3) & 0xfffffffe) + 1;
      if (uVar2 != 0) {
        return uVar2;
      }
      goto LAB_10005668;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10005690 at 10005690

void FUN_10005690(int param_1)

{
  FUN_100054f0((int *)(param_1 + -4));
  return;
}



// Function: FUN_100056a0 at 100056a0

void FUN_100056a0(int param_1)

{
  FUN_100054d0(param_1 + -4);
  return;
}



// Function: FUN_100056b0 at 100056b0

void FUN_100056b0(int param_1)

{
  FUN_100054d0(param_1 + -8);
  return;
}



// Function: FUN_100056c0 at 100056c0

void FUN_100056c0(int param_1)

{
  FUN_100054f0((int *)(param_1 + -8));
  return;
}



// Function: FUN_100056d0 at 100056d0

int __fastcall FUN_100056d0(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_100056f0 at 100056f0

void FUN_100056f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_100290d8,param_2,param_3);
  return;
}



// Function: FUN_10005710 at 10005710

void FUN_10005710(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10029130,param_2,param_3);
  return;
}



// Function: FUN_10005730 at 10005730

void * FUN_10005730(char *param_1)

{
  void *pvVar1;
  undefined **local_10 [3];
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x924924a) &&
     (pvVar1 = operator_new((int)param_1 * 0x1c), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_10005790 at 10005790

DWORD FUN_10005790(undefined4 *param_1)

{
  int *piVar1;
  BOOL BVar2;
  LPUNKNOWN punkOuter;
  DWORD DVar3;
  LPUNKNOWN *ppunkMarshal;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a50;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  DVar3 = 0x8007000e;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  piVar1 = (int *)operator_new(0x138);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_1000e3f0((int)piVar1);
    *piVar1 = (int)ATL::CComObject<class_CConnectionProperties>::vftable;
    piVar1[1] = (int)ATL::CComObject<class_CConnectionProperties>::vftable;
    piVar1[2] = (int)ATL::CComObject<class_CConnectionProperties>::vftable;
    (**(code **)(*DAT_1003af94 + 4))();
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) goto code_r0x100058c0;
  InterlockedIncrement(piVar1 + 3);
  DVar3 = 0;
  BVar2 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar1 + 4),0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar3) goto LAB_10005870;
  }
  else {
LAB_10005870:
    *(undefined1 *)(piVar1 + 10) = 1;
    if (-1 < (int)DVar3) {
      ppunkMarshal = (LPUNKNOWN *)(piVar1 + 0x4d);
      punkOuter = (LPUNKNOWN)(**(code **)(*piVar1 + 0x10))();
      DVar3 = CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
      if (-1 < (int)DVar3) {
        DVar3 = 0;
      }
    }
  }
  InterlockedDecrement(piVar1 + 3);
  if (DVar3 != 0) {
    (**(code **)(*piVar1 + 0x14))(1);
    DVar3 = FUN_100058c0();
    return DVar3;
  }
code_r0x100058c0:
  *param_1 = piVar1;
  ExceptionList = local_10;
  return DVar3;
}



// Function: Catch_All@100058b4 at 100058b4

undefined * Catch_All_100058b4(void)

{
  return &DAT_100058ba;
}



// Function: FUN_100058c0 at 100058c0

void FUN_100058c0(void)

{
  int unaff_EBP;
  undefined4 unaff_ESI;
  
  **(undefined4 **)(unaff_EBP + 8) = unaff_ESI;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100058e0 at 100058e0

DWORD FUN_100058e0(undefined4 *param_1)

{
  int *piVar1;
  BOOL BVar2;
  LPUNKNOWN punkOuter;
  DWORD DVar3;
  LPUNKNOWN *ppunkMarshal;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022a70;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  DVar3 = 0x8007000e;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  piVar1 = (int *)operator_new(100);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_1000d5d0((int)piVar1);
    *piVar1 = (int)ATL::CComObject<class_CConnectionCollection>::vftable;
    piVar1[1] = (int)ATL::CComObject<class_CConnectionCollection>::vftable;
    piVar1[2] = (int)ATL::CComObject<class_CConnectionCollection>::vftable;
    (**(code **)(*DAT_1003af94 + 4))();
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) goto code_r0x10005a0a;
  InterlockedIncrement(piVar1 + 3);
  DVar3 = 0;
  BVar2 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar1 + 4),0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar3) goto LAB_100059bd;
  }
  else {
LAB_100059bd:
    *(undefined1 *)(piVar1 + 10) = 1;
    if (-1 < (int)DVar3) {
      ppunkMarshal = (LPUNKNOWN *)(piVar1 + 0x18);
      punkOuter = (LPUNKNOWN)(**(code **)(*piVar1 + 0x10))();
      DVar3 = CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
      if (-1 < (int)DVar3) {
        DVar3 = 0;
      }
    }
  }
  InterlockedDecrement(piVar1 + 3);
  if (DVar3 != 0) {
    (**(code **)(*piVar1 + 0x14))(1);
    DVar3 = FUN_10005a0a();
    return DVar3;
  }
code_r0x10005a0a:
  *param_1 = piVar1;
  ExceptionList = local_10;
  return DVar3;
}



// Function: Catch_All@100059fe at 100059fe

undefined * Catch_All_100059fe(void)

{
  return &DAT_10005a04;
}



// Function: FUN_10005a0a at 10005a0a

void FUN_10005a0a(void)

{
  int unaff_EBP;
  undefined4 unaff_ESI;
  
  **(undefined4 **)(unaff_EBP + 8) = unaff_ESI;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10005a30 at 10005a30

void FUN_10005a30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100056f0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10005a40 at 10005a40

void FUN_10005a40(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100056f0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10005a50 at 10005a50

void FUN_10005a50(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005710(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10005a60 at 10005a60

void FUN_10005a60(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005710(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10005a70 at 10005a70

int * __thiscall FUN_10005a70(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  uint extraout_EAX;
  uint uVar1;
  int extraout_EAX_00;
  int iVar2;
  void *pvVar3;
  uint extraout_ECX;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *extraout_EDX;
  undefined4 *extraout_EDX_00;
  undefined4 *extraout_EDX_01;
  
  uVar1 = param_1[4];
  uVar4 = param_2;
  puVar5 = param_1;
  if (uVar1 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar1 = extraout_EAX;
    uVar4 = extraout_ECX;
    puVar5 = extraout_EDX;
  }
  if (uVar1 - uVar4 < param_3) {
    param_3 = uVar1 - uVar4;
  }
  iVar2 = *(int *)((int)this + 0x10);
  if (-iVar2 - 1U <= param_3) {
    std::_Xlength_error("string too long");
    iVar2 = extraout_EAX_00;
    puVar5 = extraout_EDX_00;
  }
  if (param_3 != 0) {
    uVar1 = iVar2 + param_3;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
      puVar5 = extraout_EDX_01;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_100022b0(this,uVar1);
      puVar5 = param_1;
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined2 *)this = 0;
      return (int *)this;
    }
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    memcpy((void *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2),
           (void *)((int)puVar5 + param_2 * 2),param_3 * 2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar1 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar1 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_10005b80 at 10005b80

void __fastcall FUN_10005b80(undefined4 *param_1)

{
  if (7 < (uint)param_1[0x36]) {
    operator_delete((void *)param_1[0x31]);
  }
  param_1[0x36] = 7;
  param_1[0x35] = 0;
  *(undefined2 *)(param_1 + 0x31) = 0;
  if (7 < (uint)param_1[0x2f]) {
    operator_delete((void *)param_1[0x2a]);
  }
  param_1[0x2f] = 7;
  param_1[0x2e] = 0;
  *(undefined2 *)(param_1 + 0x2a) = 0;
  if (7 < (uint)param_1[0x28]) {
    operator_delete((void *)param_1[0x23]);
  }
  param_1[0x28] = 7;
  param_1[0x27] = 0;
  *(undefined2 *)(param_1 + 0x23) = 0;
  if (7 < (uint)param_1[0x21]) {
    operator_delete((void *)param_1[0x1c]);
  }
  param_1[0x21] = 7;
  param_1[0x20] = 0;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  if (7 < (uint)param_1[0x1a]) {
    operator_delete((void *)param_1[0x15]);
  }
  param_1[0x1a] = 7;
  param_1[0x19] = 0;
  *(undefined2 *)(param_1 + 0x15) = 0;
  if (7 < (uint)param_1[0x13]) {
    operator_delete((void *)param_1[0xe]);
  }
  param_1[0x13] = 7;
  param_1[0x12] = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  if (7 < (uint)param_1[0xc]) {
    operator_delete((void *)param_1[7]);
  }
  param_1[0xc] = 7;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[4] = 0;
  param_1[5] = 7;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10005cc0 at 10005cc0

void __fastcall FUN_10005cc0(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10005cf0 at 10005cf0

int * __thiscall FUN_10005cf0(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  void *pvVar4;
  int *extraout_EDX;
  int *extraout_EDX_00;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar2 = (int *)this;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar4 = this;
      if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_1 < (int *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2)) {
        pvVar4 = this;
        if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        piVar2 = FUN_10005a70(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
        return piVar2;
      }
    }
  }
  iVar3 = *(int *)((int)this + 0x10);
  piVar2 = param_1;
  if (-iVar3 - 1U <= param_2) {
    std::_Xlength_error("string too long");
    iVar3 = extraout_EAX;
    piVar2 = extraout_EDX;
  }
  if (param_2 != 0) {
    uVar1 = iVar3 + param_2;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
      piVar2 = extraout_EDX_00;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_100022b0(this,uVar1);
      piVar2 = param_1;
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined2 *)this = 0;
      return (int *)this;
    }
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2),piVar2,param_2 * 2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar1 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar1 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_10005e10 at 10005e10

ULONG __thiscall
FUN_10005e10(void *this,int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  ULONG UVar2;
  LONG LVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022aa0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (param_4 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *param_4;
  }
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  UVar2 = (**(code **)(*this + 0x20))(this,iVar1,param_2,param_3,iVar4);
  if ((int)UVar2 < 0) {
    _com_issue_errorex(UVar2,(IUnknown *)this,(_GUID *)&DAT_1002856c);
  }
  if (((param_1 != (int *)0x0) && (LVar3 = InterlockedDecrement(param_1 + 2), LVar3 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete__((void *)param_1[1]);
    }
    operator_delete(param_1);
  }
  if (((param_4 != (int *)0x0) && (LVar3 = InterlockedDecrement(param_4 + 2), LVar3 == 0)) &&
     (param_4 != (int *)0x0)) {
    if (*param_4 != 0) {
      Ordinal_6(*param_4);
    }
    if ((void *)param_4[1] != (void *)0x0) {
      operator_delete__((void *)param_4[1]);
    }
    operator_delete(param_4);
  }
  ExceptionList = local_10;
  return UVar2;
}



// Function: FUN_10005f20 at 10005f20

undefined4 __thiscall FUN_10005f20(void *this,void *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar4;
  uint uVar5;
  short *psVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022b19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x10029208);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar7,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x100291a8);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar7,uVar8,uVar9,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX_05;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffffac,0x100291a8);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar4,piVar7,piVar2);
  psVar6 = (short *)PTR_DAT_1003a6ec;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_10005600(param_1,0,*(uint *)((int)param_1 + 0x10),(ushort *)PTR_DAT_1003a6ec,
                       (int)psVar6 - (int)(PTR_DAT_1003a6ec + 2) >> 1);
  if (uVar5 != 0) {
    psVar6 = (short *)PTR_DAT_1003a6f0;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    uVar5 = FUN_10005600(param_1,0,*(uint *)((int)param_1 + 0x10),(ushort *)PTR_DAT_1003a6f0,
                         (int)psVar6 - (int)(PTR_DAT_1003a6f0 + 2) >> 1);
    if (uVar5 != 0) {
      ExceptionList = local_10;
      return uVar5 & 0xffffff00;
    }
  }
  ExceptionList = local_10;
  return CONCAT31((int3)(uVar5 >> 8),1);
}



// Function: Catch@10006177 at 10006177

undefined4 Catch_10006177(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureManager.cpp",0x39a,
               "CAutoConfigure::checkProtocolSupportForINLINEII",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return 0x100061c2;
}



// Function: Catch_All@100061d8 at 100061d8

undefined4 Catch_All_100061d8(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x30),"AutoConfigureManager.cpp",0x39a,
               "CAutoConfigure::checkProtocolSupportForINLINEII",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000623f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x100061c2;
}



// Function: FUN_10006250 at 10006250

undefined4 __thiscall FUN_10006250(void *this,void *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar4;
  short *psVar5;
  uint uVar6;
  uint3 uVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022b99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x100293c0);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar8,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x10029360);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar8,uVar9,uVar10,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar8 = extraout_ECX_05;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar8 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffffac,0x10029360);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar4,piVar8,piVar2);
  psVar5 = (short *)PTR_DAT_1003a6f0;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  uVar6 = FUN_10005600(param_1,0,*(uint *)((int)param_1 + 0x10),(ushort *)PTR_DAT_1003a6f0,
                       (int)psVar5 - (int)(PTR_DAT_1003a6f0 + 2) >> 1);
  uVar7 = (uint3)(uVar6 >> 8);
  if (uVar6 == 0) {
    ExceptionList = local_10;
    return CONCAT31(uVar7,1);
  }
  ExceptionList = local_10;
  return (uint)uVar7 << 8;
}



// Function: Catch@10006478 at 10006478

undefined4 Catch_10006478(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureManager.cpp",0x3b4,
               "CAutoConfigure::checkProtocolSupportForINLINE",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return 0x100064c3;
}



// Function: Catch_All@100064d9 at 100064d9

undefined4 Catch_All_100064d9(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x30),"AutoConfigureManager.cpp",0x3b4,
               "CAutoConfigure::checkProtocolSupportForINLINE",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x10006540;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x100064c3;
}



// Function: FUN_10006550 at 10006550

void __thiscall FUN_10006550(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022c19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x100293c0);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x10029540);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_05;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffffac,0x100294f0);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 9;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  *(int *)((int)this + 0x2c) = param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000675c at 1000675c

undefined1 * Catch_1000675c(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureManager.cpp",0x3cc,
               "CAutoConfigure::setAutoConfigureState",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_100067a7;
}



// Function: Catch_All@100067bb at 100067bb

undefined4 Catch_All_100067bb(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x30),"AutoConfigureManager.cpp",0x3cc,
               "CAutoConfigure::setAutoConfigureState",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10006822;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x10006748;
}



// Function: FUN_10006830 at 10006830

int * __fastcall FUN_10006830(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022c99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffa8,0x10029658);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa0,0x10029608);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_05;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffffa8,0x100295b8);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 9;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  ExceptionList = local_10;
  return param_1 + 0xb;
}



// Function: Catch@10006a2a at 10006a2a

undefined * Catch_10006a2a(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x24),"AutoConfigureManager.cpp",0x3e0,
               "CAutoConfigure::getAutoConfigureState",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10006a75;
}



// Function: Catch_All@10006a77 at 10006a77

undefined4 Catch_All_10006a77(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x34) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x34),"AutoConfigureManager.cpp",0x3e0,
               "CAutoConfigure::getAutoConfigureState",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10006ade;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return 0x10006a12;
}



// Function: FUN_10006af0 at 10006af0

void __fastcall FUN_10006af0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022d19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x100297e8);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x10029798);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_05;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffffac,0x10029748);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 9;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  if (param_1[10] != 0) {
    FUN_1001ddc0(param_1[10]);
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@10006cef at 10006cef

undefined1 * Catch_10006cef(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureManager.cpp",0x400,
               "CAutoConfigure::cancelRP1210Detection",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_10006d3a;
}



// Function: Catch_All@10006d4c at 10006d4c

undefined4 Catch_All_10006d4c(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x30),"AutoConfigureManager.cpp",0x400,
               "CAutoConfigure::cancelRP1210Detection",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10006db3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x10006cdd;
}



// Function: FUN_10006dc0 at 10006dc0

undefined4 FUN_10006dc0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1003aa3c == (int *)0x0) {
    uVar1 = FUN_10002550(&PTR_DAT_1003aa30,param_3);
  }
  *param_4 = DAT_1003aa3c;
  if (DAT_1003aa3c != (int *)0x0) {
    (**(code **)(*DAT_1003aa3c + 4))(DAT_1003aa3c);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006e20 at 10006e20

undefined4 FUN_10006e20(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1003aa58 == (int *)0x0) {
    uVar1 = FUN_10002550(&PTR_DAT_1003aa4c,param_3);
  }
  *param_4 = DAT_1003aa58;
  if (DAT_1003aa58 != (int *)0x0) {
    (**(code **)(*DAT_1003aa58 + 4))(DAT_1003aa58);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006e80 at 10006e80

void __thiscall FUN_10006e80(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_10015a60(this,1);
    }
    if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
                    /* WARNING: Load size is inaccurate */
      **(undefined4 **)((int)this + 4) =
           *(undefined4 *)(*this + ((int)param_1 - (int)puVar2 >> 2) * 4);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
      return;
    }
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_10015a60(this,1);
    }
    if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
      **(undefined4 **)((int)this + 4) = *param_1;
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}



// Function: FUN_10006ef0 at 10006ef0

void __thiscall FUN_10006ef0(void *this,int *param_1)

{
  FUN_10003030((void *)((int)this + 0x58),param_1,0,0xffffffff);
  return;
}



// Function: FUN_10006f10 at 10006f10

void __thiscall FUN_10006f10(void *this,int *param_1)

{
  FUN_10003030((void *)((int)this + 0x74),param_1,0,0xffffffff);
  return;
}



// Function: FUN_10006f30 at 10006f30

void __thiscall FUN_10006f30(void *this,int *param_1)

{
  FUN_10003030((void *)((int)this + 0x90),param_1,0,0xffffffff);
  return;
}



// Function: FUN_10006f50 at 10006f50

void __thiscall FUN_10006f50(void *this,int *param_1)

{
  FUN_10003030((void *)((int)this + 0xac),param_1,0,0xffffffff);
  return;
}



// Function: FUN_10006f70 at 10006f70

void __fastcall FUN_10006f70(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022d7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffb0,0x10029930);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa8,0x100298d8);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  for (iVar2 = 0; iVar2 < param_1[0x13] - param_1[0x12] >> 2; iVar2 = iVar2 + 1) {
    if (*(int *)(param_1[0x12] + iVar2 * 4) != 0) {
      (**(code **)(**(int **)(param_1[0x12] + iVar2 * 4) + 8))();
      *(undefined4 *)(param_1[0x12] + iVar2 * 4) = 0;
    }
  }
  pvVar3 = (void *)param_1[0x12];
  if (pvVar3 != (void *)param_1[0x13]) {
    memmove(pvVar3,(void *)param_1[0x13],0);
    param_1[0x13] = (int)pvVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000713b at 1000713b

undefined1 * Catch_1000713b(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x1c),"AutoConfigureManager.cpp",0x416,
               "CAutoConfigure::clearConnectionCollection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &LAB_10007186;
}



// Function: Catch_All@10007198 at 10007198

undefined4 Catch_All_10007198(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x2c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x2c),"AutoConfigureManager.cpp",0x416,
               "CAutoConfigure::clearConnectionCollection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x100071ff;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return 0x10007129;
}



// Function: FUN_10007210 at 10007210

/* WARNING: Removing unreachable block (ram,0x100075fb) */

void FUN_10007210(undefined4 *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *extraout_EAX_00;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  short *psVar9;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  uint uStack_a4;
  int *local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10022e11;
  local_10 = ExceptionList;
  uStack_a4 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a4;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_a4;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff4c,0x10029a80);
  piVar8 = local_70;
  pvVar6 = *(void **)(*local_70 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  GetCurrentThreadId();
  local_70 = (int *)&stack0xffffff50;
  piVar2 = extraout_ECX_02;
  puVar4 = (undefined4 *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0;
    puVar4[2] = 1;
    uVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *puVar4 = uVar5;
  }
  piVar7 = local_70;
  local_8 = (uint)local_8._1_3_ << 8;
  *local_70 = (int)puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff4c,0x10029a28);
  pvVar6 = *(void **)(*piVar8 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  piVar7 = (int *)FUN_1000e0e0(piVar8 + 9);
  FUN_10005790(&local_70);
  piVar8 = (int *)FUN_1001f330(piVar8 + 0x2b);
  local_6c = (void *)((uint)local_6c._2_2_ << 0x10);
  local_58 = 7;
  local_5c = 0;
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_6c,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8._0_1_ = 7;
  FUN_1000f740(local_70,&local_6c);
  local_8._0_1_ = 0;
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  psVar9 = (short *)PTR_u_INLINE_INLINE_I_1003a6fc;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_34,(int *)PTR_u_INLINE_INLINE_I_1003a6fc,
               (int)psVar9 - (int)(PTR_u_INLINE_INLINE_I_1003a6fc + 2) >> 1);
  local_8._0_1_ = 8;
  piVar8 = (int *)FUN_1001f330(&local_34);
  local_50 = (void *)((uint)local_50._2_2_ << 0x10);
  local_3c = 7;
  local_40 = 0;
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_50,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_1000f2c0(local_70,&local_50);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  local_8 = local_8 & 0xffffff00;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  psVar9 = (short *)PTR_u_INLINE_INLINE_I_1003a6fc;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_6c,(int *)PTR_u_INLINE_INLINE_I_1003a6fc,
               (int)psVar9 - (int)(PTR_u_INLINE_INLINE_I_1003a6fc + 2) >> 1);
  local_8._0_1_ = 10;
  FUN_1000f500(local_70,&local_6c);
  local_8._0_1_ = 0;
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  piVar8 = (int *)FUN_1001f330(param_1);
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_34,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8._0_1_ = 0xb;
  FUN_1000f980(local_70,&local_34);
  local_8._0_1_ = 0;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  local_3c = 7;
  local_40 = 0;
  psVar9 = (short *)PTR_u_Cummins__Inc__1003a6f8;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_50,(int *)PTR_u_Cummins__Inc__1003a6f8,
               (int)psVar9 - (int)(PTR_u_Cummins__Inc__1003a6f8 + 2) >> 1);
  piVar2 = local_70;
  local_8._0_1_ = 0xc;
  FUN_1000f080(local_70,&local_50);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  (**(code **)(*piVar7 + 4))();
  (**(code **)(piVar2[2] + 0x30))();
  (**(code **)*piVar7)();
  (**(code **)(*piVar2 + 0x14))(1);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100075ff at 100075ff

undefined4 Catch_100075ff(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x90),"AutoConfigureManager.cpp",0x107,
               "CAutoConfigure::validateINLINEConnection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  return 0x1000764d;
}



// Function: Catch_All@1000766d at 1000766d

undefined4 Catch_All_1000766d(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x8c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x88) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x84) = 0;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10020630((void *)(unaff_EBP + -0x8c),"AutoConfigureManager.cpp",0x107,
               "CAutoConfigure::validateINLINEConnection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  uStack0000001c = 0x100076e3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return 0x1000764d;
}



// Function: FUN_100076f0 at 100076f0

/* WARNING: Removing unreachable block (ram,0x10007adb) */

void FUN_100076f0(undefined4 *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *extraout_EAX_00;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  short *psVar9;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  uint uStack_a4;
  int *local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10022eb1;
  local_10 = ExceptionList;
  uStack_a4 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a4;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_a4;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff4c,0x10029b60);
  piVar8 = local_70;
  pvVar6 = *(void **)(*local_70 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  GetCurrentThreadId();
  local_70 = (int *)&stack0xffffff50;
  piVar2 = extraout_ECX_02;
  puVar4 = (undefined4 *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0;
    puVar4[2] = 1;
    uVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *puVar4 = uVar5;
  }
  piVar7 = local_70;
  local_8 = (uint)local_8._1_3_ << 8;
  *local_70 = (int)puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff4c,0x10029b08);
  pvVar6 = *(void **)(*piVar8 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  piVar7 = (int *)FUN_1000de30(piVar8 + 9);
  FUN_10005790(&local_70);
  piVar8 = (int *)FUN_1001f330(piVar8 + 0x2b);
  local_6c = (void *)((uint)local_6c._2_2_ << 0x10);
  local_58 = 7;
  local_5c = 0;
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_6c,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8._0_1_ = 7;
  FUN_1000f740(local_70,&local_6c);
  local_8._0_1_ = 0;
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  psVar9 = (short *)PTR_u_INLINE_II_1003a700;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_34,(int *)PTR_u_INLINE_II_1003a700,
               (int)psVar9 - (int)(PTR_u_INLINE_II_1003a700 + 2) >> 1);
  local_8._0_1_ = 8;
  piVar8 = (int *)FUN_1001f330(&local_34);
  local_50 = (void *)((uint)local_50._2_2_ << 0x10);
  local_3c = 7;
  local_40 = 0;
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_50,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_1000f2c0(local_70,&local_50);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  local_8 = local_8 & 0xffffff00;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  psVar9 = (short *)PTR_u_INLINE_II_1003a700;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_6c,(int *)PTR_u_INLINE_II_1003a700,
               (int)psVar9 - (int)(PTR_u_INLINE_II_1003a700 + 2) >> 1);
  local_8._0_1_ = 10;
  FUN_1000f500(local_70,&local_6c);
  local_8._0_1_ = 0;
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  piVar8 = (int *)FUN_1001f330(param_1);
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  piVar2 = piVar8;
  do {
    iVar3 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_34,piVar8,(int)piVar2 - ((int)piVar8 + 2) >> 1);
  local_8._0_1_ = 0xb;
  FUN_1000f980(local_70,&local_34);
  local_8._0_1_ = 0;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  local_3c = 7;
  local_40 = 0;
  psVar9 = (short *)PTR_u_Cummins__Inc__1003a6f8;
  do {
    sVar1 = *psVar9;
    psVar9 = psVar9 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_50,(int *)PTR_u_Cummins__Inc__1003a6f8,
               (int)psVar9 - (int)(PTR_u_Cummins__Inc__1003a6f8 + 2) >> 1);
  piVar2 = local_70;
  local_8._0_1_ = 0xc;
  FUN_1000f080(local_70,&local_50);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  (**(code **)(*piVar7 + 4))();
  (**(code **)(piVar2[2] + 0x30))();
  (**(code **)*piVar7)();
  (**(code **)(*piVar2 + 0x14))(1);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10007adf at 10007adf

undefined4 Catch_10007adf(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x90),"AutoConfigureManager.cpp",0x131,
               "CAutoConfigure::validateINLINEIIConnection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  return 0x10007b2d;
}



// Function: Catch_All@10007b4d at 10007b4d

undefined4 Catch_All_10007b4d(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x8c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x88) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x84) = 0;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10020630((void *)(unaff_EBP + -0x8c),"AutoConfigureManager.cpp",0x131,
               "CAutoConfigure::validateINLINEIIConnection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  uStack0000001c = 0x10007bc3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return 0x10007b2d;
}



// Function: FUN_10007bd0 at 10007bd0

void __cdecl FUN_10007bd0(undefined4 param_1,undefined4 *param_2)

{
  if (7 < (uint)param_2[5]) {
    operator_delete((void *)*param_2);
  }
  param_2[5] = 7;
  param_2[4] = 0;
  *(undefined2 *)param_2 = 0;
  return;
}



// Function: FUN_10007c00 at 10007c00

void __cdecl FUN_10007c00(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    do {
      if (7 < (uint)param_1[5]) {
        operator_delete((void *)*param_1);
      }
      param_1[5] = 7;
      param_1[4] = 0;
      *(undefined2 *)param_1 = 0;
      param_1 = param_1 + 7;
    } while (param_1 != param_2);
  }
  return;
}



// Function: FUN_10007c40 at 10007c40

void FUN_10007c40(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003a6e8);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007cd0 at 10007cd0

void __fastcall FUN_10007cd0(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar4;
  IUnknownVtbl *pIVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar6;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022f41;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x10029c04);
  pvVar4 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_03;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff88,0x10029bd4);
  pvVar4 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX_05;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffff88,0x10029c04);
  pvVar4 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  FUN_10006af0(param_1);
  FUN_10006550(param_1,3);
  pIVar5 = (IUnknownVtbl *)FUN_10007c40();
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar5 + 0x14))->lpVtbl) {
    pIVar5 = ((IUnknown *)pIVar5)->lpVtbl;
  }
  FUN_10014b60((void *)*param_1,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar5,(int *)0x4);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10007f1c at 10007f1c

undefined * Catch_10007f1c(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"AutoConfigureManager.cpp",0x9e,
               "CAutoConfigure::Cancel",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10007f67;
}



// Function: Catch_All@10007f69 at 10007f69

undefined4 Catch_All_10007f69(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10020630((void *)(unaff_EBP + -0x50),"AutoConfigureManager.cpp",0x9e,"CAutoConfigure::Cancel",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10007fd0;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x10007f00;
}



// Function: FUN_10007fe0 at 10007fe0

void __fastcall FUN_10007fe0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  wchar_t *pwVar4;
  int iVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar6;
  uint uStack_80;
  int *local_54;
  void *local_50;
  uint local_3c;
  void *local_34;
  undefined2 local_28;
  undefined2 uStack_26;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022fc6;
  local_10 = ExceptionList;
  uStack_80 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_80;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_80;
  GetCurrentThreadId();
  local_54 = (int *)&stack0xffffff74;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff70,0x10029cf0);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar6,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_54 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  local_54 = (int *)&stack0xffffff70;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff70,0x10029c98);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar6,piVar1);
  FUN_100058e0(&local_54);
  if (local_54 == (int *)0x0) {
    pwVar4 = (wchar_t *)FUN_10007c40();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar4 + 10)) {
      pwVar4 = *(wchar_t **)pwVar4;
    }
    FUN_10015000((void *)*param_1,0x42f,0x80004005,0x10029c98,L"AutoConfigureManager.cpp",
                 (undefined1 *)0x1b7,pwVar4);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  for (iVar2 = 0; iVar2 < param_1[0x13] - param_1[0x12] >> 2; iVar2 = iVar2 + 1) {
    Ordinal_8();
    _local_28 = CONCAT22(uStack_26,9);
    iVar5 = (**(code **)**(undefined4 **)(param_1[0x12] + iVar2 * 4))();
    if (iVar5 < 0) {
      pwVar4 = (wchar_t *)FUN_10007c40();
      local_8._0_1_ = 8;
      if (7 < *(uint *)(pwVar4 + 10)) {
        pwVar4 = *(wchar_t **)pwVar4;
      }
      FUN_10015000((void *)*param_1,0x431,0x80004005,0x10029c98,L"AutoConfigureManager.cpp",
                   (undefined1 *)0x1c7,pwVar4);
      local_8._0_1_ = 0;
      if (7 < local_3c) {
        operator_delete(local_50);
      }
    }
    FUN_1000d810();
  }
  iVar2 = (**(code **)*local_54)();
  if (iVar2 < 0) {
    pwVar4 = (wchar_t *)FUN_10007c40();
    local_8._0_1_ = 9;
    if (7 < *(uint *)(pwVar4 + 10)) {
      pwVar4 = *(wchar_t **)pwVar4;
    }
    FUN_10015000((void *)*param_1,0x430,0x80004005,0x10029c98,L"AutoConfigureManager.cpp",
                 (undefined1 *)0x1d3,pwVar4);
    if (7 < local_3c) {
      operator_delete(local_50);
    }
  }
  ExceptionList = local_10;
  uStack_80 = 0x100082e8;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100082ee at 100082ee

undefined * Catch_100082ee(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x6c),"AutoConfigureManager.cpp",0x1d6,
               "CAutoConfigure::updateConnectionCollection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_10008339;
}



// Function: Catch_All@1000833b at 1000833b

undefined4 Catch_All_1000833b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x68) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -100) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x60) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x68),"AutoConfigureManager.cpp",0x1d6,
               "CAutoConfigure::updateConnectionCollection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x100083a2;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x68));
  return 0x100082d0;
}



// Function: FUN_100083b0 at 100083b0

void FUN_100083b0(void)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  IUnknownVtbl *pIVar3;
  void *extraout_EAX_02;
  void *pvVar4;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar5;
  int *extraout_ECX_08;
  int *extraout_ECX_09;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_70;
  undefined1 local_60 [32];
  int *local_40;
  int *local_3c;
  int *local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023079;
  local_10 = ExceptionList;
  uStack_70 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_70;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_70;
  GetCurrentThreadId();
  local_38 = (int *)&stack0xffffff84;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_3c = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_01;
  }
  local_3c = (int *)&stack0xffffff80;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff80,0x10029e9c);
  pvVar4 = *(void **)(*local_40 + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar5,piVar1);
  GetCurrentThreadId();
  local_3c = (int *)&stack0xffffff84;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_38 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_04;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_38 = (int *)&stack0xffffff78;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff78,0x10029e64);
  pvVar4 = *(void **)(*local_40 + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar5,uVar6,uVar7,piVar1);
  GetCurrentThreadId();
  local_3c = (int *)&stack0xffffff84;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  local_38 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX_05;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_07;
  }
  local_38 = (int *)&stack0xffffff80;
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffff80,0x10029e64);
  pvVar4 = *(void **)(*local_40 + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar5,piVar1);
  pIVar3 = (IUnknownVtbl *)FUN_10007c40();
  local_8._0_1_ = 10;
  if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
    pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
  }
  FUN_10014b60((void *)*local_40,(IUnknown *)0x439,(undefined1 *)0x0,(IUnknown *)pIVar3,(int *)0x4);
  local_8._0_1_ = 0;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  if ((local_40[6] - local_40[5] & 0xfffffffcU) == 0) {
    FUN_10015910(local_60,*local_40);
    local_8._0_1_ = 0xb;
    FUN_10016c60(local_60,(uint *)(local_40 + 5));
    if ((local_40[6] - local_40[5] & 0xfffffffcU) == 0) {
      pIVar3 = (IUnknownVtbl *)FUN_10007c40();
      local_8._0_1_ = 0xc;
      if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
        pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
      }
      FUN_10014d70((void *)*local_40,0x408,0x20,(IUnknown *)pIVar3,
                   (IUnknown *)L"CProtocol::GetProtocols",(int *)0x4,(IID *)0x0,
                   (int *)L"AutoConfigureManager.cpp",(undefined1 *)0x23a);
      local_8._0_1_ = 0xb;
      if (7 < local_20) {
        operator_delete(local_34);
      }
      GetCurrentThreadId();
      local_3c = (int *)&stack0xffffff84;
      piVar5 = extraout_ECX_08;
      FUN_10001e80(&stack0xffffff84,"AutoConfigureManager.cpp");
      uVar7 = 4;
      uVar6 = 0;
      local_38 = (int *)&stack0xffffff78;
      local_8._0_1_ = 0xd;
      piVar1 = extraout_ECX_09;
      FUN_10001f10(&stack0xffffff78,0x10029df0);
      pvVar4 = *(void **)(*local_40 + 4);
      local_8._0_1_ = 0xe;
      if (pvVar4 == (void *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pvVar4 = extraout_EAX_02;
      }
      local_8._0_1_ = 0xb;
      FUN_10005e10(pvVar4,piVar1,uVar6,uVar7,piVar5);
    }
    local_8._0_1_ = 0;
    FUN_10015930((int)local_60);
  }
  pIVar3 = (IUnknownVtbl *)FUN_10007c40();
  local_8 = CONCAT31(local_8._1_3_,0xf);
  if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
    pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
  }
  FUN_10014b60((void *)*local_40,(IUnknown *)0x439,(undefined1 *)0xa,(IUnknown *)pIVar3,(int *)0x4);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10008720 at 10008720

undefined * Catch_10008720(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x50),"AutoConfigureManager.cpp",0x246,
               "CAutoConfigure::detectPorts",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1000876b;
}



// Function: Catch_All@1000876d at 1000876d

undefined4 Catch_All_1000876d(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x4c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_10020630((void *)(unaff_EBP + -0x4c),"AutoConfigureManager.cpp",0x246,
               "CAutoConfigure::detectPorts",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x100087d4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return 0x10008704;
}



// Function: FUN_100087e0 at 100087e0

void __thiscall FUN_100087e0(void *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar4;
  IUnknownVtbl *pIVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023109;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff8c,0x10029f50);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar8 = 4;
  uVar7 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff84,0x10029f00);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar6,uVar7,uVar8,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX_05;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffff8c,0x10029f00);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  if (param_1 == 0) {
    pIVar5 = (IUnknownVtbl *)FUN_10007c40();
    local_8._0_1_ = 10;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar5 + 0x14))->lpVtbl) {
      pIVar5 = ((IUnknown *)pIVar5)->lpVtbl;
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10014b60(*this,(IUnknown *)0x43a,(undefined1 *)0x0,(IUnknown *)pIVar5,(int *)0x4);
  }
  else {
    pIVar5 = (IUnknownVtbl *)FUN_10007c40();
    local_8._0_1_ = 0xb;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar5 + 0x14))->lpVtbl) {
      pIVar5 = ((IUnknown *)pIVar5)->lpVtbl;
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10014b60(*this,(IUnknown *)0x43e,(undefined1 *)0x41,(IUnknown *)pIVar5,(int *)0x4);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  FUN_1001e590(param_1,(uint *)((int)this + 0x48));
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10008a71 at 10008a71

undefined * Catch_10008a71(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x50),"AutoConfigureManager.cpp",0x270,
               "CAutoConfigure::detectRP1210Adapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10008abc;
}



// Function: Catch_All@10008abe at 10008abe

undefined4 Catch_All_10008abe(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x4c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10020630((void *)(unaff_EBP + -0x4c),"AutoConfigureManager.cpp",0x270,
               "CAutoConfigure::detectRP1210Adapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10008b25;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return 0x10008a53;
}



// Function: FUN_10008b30 at 10008b30

/* WARNING: Removing unreachable block (ram,0x100093c3) */

void FUN_10008b30(void)

{
  short sVar1;
  void **ppvVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  wchar_t *pwVar10;
  int *piVar11;
  short *psVar12;
  uint extraout_EAX_02;
  char *pcVar13;
  uint extraout_EAX_03;
  IUnknownVtbl *pIVar14;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  ushort *puVar15;
  void **extraout_ECX_08;
  void **ppvVar16;
  char *pcVar17;
  void **extraout_ECX_09;
  void **ppvVar18;
  void **extraout_EDX;
  int extraout_EDX_00;
  undefined1 *puVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint uStack_100;
  undefined1 *local_e8;
  int local_dc;
  int local_d8;
  undefined1 *local_d4;
  int local_d0;
  int *local_cc;
  void *local_c8;
  int *local_c4;
  IUnknownVtbl local_c0;
  uint local_ac;
  void *local_a4 [4];
  undefined4 local_94;
  uint local_90;
  undefined4 local_88;
  uint local_78;
  uint local_74;
  undefined4 local_6c;
  uint local_5c;
  uint local_58;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023210;
  local_10 = ExceptionList;
  uStack_100 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_100;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_100;
  GetCurrentThreadId();
  local_d4 = &stack0xfffffef4;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_cc = piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_cc = (int *)&stack0xfffffef0;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffef0,0x1002a0c0);
  pvVar6 = *(void **)(*local_c4 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar8,piVar4);
  GetCurrentThreadId();
  local_d4 = &stack0xfffffef4;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_cc = piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar23 = 4;
  uVar22 = 2;
  local_cc = (int *)&stack0xfffffee8;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffee8,0x1002a070);
  pvVar6 = *(void **)(*local_c4 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar6,piVar8,uVar22,uVar23,piVar4);
  GetCurrentThreadId();
  local_d4 = &stack0xfffffef4;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  local_cc = piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX_05;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_07;
  }
  local_cc = (int *)&stack0xfffffef0;
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xfffffef0,0x1002a070);
  pvVar6 = *(void **)(*local_c4 + 4);
  local_8._0_1_ = 9;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar8,piVar4);
  piVar4 = local_c4;
  uVar9 = 0;
  for (uVar20 = 0; uVar20 < (uint)((piVar4[2] - piVar4[1]) / 0x1c); uVar20 = uVar20 + 1) {
    uVar7 = FUN_10005f20(piVar4,(void *)(piVar4[1] + uVar20 * 0x1c));
    if ((char)uVar7 == '\x01') {
      uVar9 = uVar7 & 0xff;
    }
  }
  if ((char)uVar9 == '\x01') {
    local_e8 = (undefined1 *)0x19;
    FUN_10007c40();
    local_8._0_1_ = 10;
    pIVar14 = (IUnknownVtbl *)local_c0.QueryInterface;
    if (local_ac < 8) {
      pIVar14 = &local_c0;
    }
    FUN_10014b60((void *)*piVar4,(IUnknown *)0x43b,(undefined1 *)0x19,(IUnknown *)pIVar14,(int *)0x4
                );
    iVar5 = (piVar4[2] - piVar4[1]) / 0x1c;
    puVar19 = (undefined1 *)(piVar4[6] - piVar4[5] >> 2);
    local_cc = (int *)(0x14 / (longlong)(iVar5 * (int)puVar19));
    local_58 = 7;
    local_5c = 0;
    local_6c = (ushort *)((uint)local_6c._2_2_ << 0x10);
    local_d4 = puVar19;
    FUN_10003130(&local_6c,(int *)&DAT_1002a064,3);
    local_8._0_1_ = 0xb;
    local_74 = 7;
    local_78 = 0;
    local_88 = (ushort *)((uint)local_88._2_2_ << 0x10);
    FUN_10003130(&local_88,(int *)L"COM Port Auto Detect",0x14);
    local_8._0_1_ = 0xc;
    for (local_d0 = 0; local_d0 < (int)puVar19; local_d0 = local_d0 + 1) {
      iVar21 = local_d0 * 4;
      piVar8 = FUN_100152c0(*(int **)(piVar4[5] + iVar21));
      puVar15 = local_6c;
      if (local_58 < 8) {
        puVar15 = (ushort *)&local_6c;
      }
      uVar9 = FUN_10005600(piVar8,0,piVar8[4],puVar15,local_5c);
      if (uVar9 != 0) {
        piVar8 = FUN_100152c0(*(int **)(piVar4[5] + iVar21));
        puVar15 = local_88;
        if (local_74 < 8) {
          puVar15 = (ushort *)&local_88;
        }
        uVar9 = FUN_10005600(piVar8,0,piVar8[4],puVar15,local_78);
        if (uVar9 != 0) {
          for (local_dc = 0; local_dc < iVar5; local_dc = local_dc + 1) {
            local_d8 = local_dc * 0x1c;
            uVar22 = FUN_10005f20(piVar4,(void *)(piVar4[1] + local_d8));
            if ((char)uVar22 == '\x01') {
              piVar4 = (int *)FUN_1000de30(local_c4 + 9);
              FUN_10005790(&local_c8);
              if (local_c8 == (void *)0x0) {
                pwVar10 = (wchar_t *)FUN_10007c40();
                local_8._0_1_ = 0xd;
                if (7 < *(uint *)(pwVar10 + 10)) {
                  pwVar10 = *(wchar_t **)pwVar10;
                }
                FUN_10015000((void *)*local_c4,0x443,0x80004005,0x1002a070,
                             L"AutoConfigureManager.cpp",(undefined1 *)0x2c3,pwVar10);
                local_8._0_1_ = 0xc;
                if (7 < local_20) {
                  operator_delete(local_34[0]);
                }
              }
              piVar8 = FUN_100152c0(*(int **)(local_c4[5] + local_d0 * 4));
              piVar11 = (int *)FUN_1001f330(piVar8);
              local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
              local_3c = 7;
              local_40 = 0;
              piVar8 = piVar11;
              do {
                iVar21 = *piVar8;
                piVar8 = (int *)((int)piVar8 + 2);
              } while ((short)iVar21 != 0);
              FUN_10003130(local_50,piVar11,(int)piVar8 - ((int)piVar11 + 2) >> 1);
              local_8._0_1_ = 0xe;
              FUN_1000f740(local_c8,(int *)local_50);
              local_8._0_1_ = 0xc;
              if (7 < local_3c) {
                operator_delete(local_50[0]);
              }
              local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
              local_3c = 7;
              local_40 = 0;
              local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
              local_20 = 7;
              local_24 = 0;
              psVar12 = (short *)PTR_u_INLINE_II_1003a700;
              do {
                sVar1 = *psVar12;
                psVar12 = psVar12 + 1;
              } while (sVar1 != 0);
              FUN_10003130(local_34,(int *)PTR_u_INLINE_II_1003a700,
                           (int)psVar12 - (int)(PTR_u_INLINE_II_1003a700 + 2) >> 1);
              local_8._0_1_ = 0xf;
              piVar11 = (int *)FUN_1001f330(local_34);
              local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
              local_90 = 7;
              local_94 = 0;
              piVar8 = piVar11;
              do {
                iVar21 = *piVar8;
                piVar8 = (int *)((int)piVar8 + 2);
              } while ((short)iVar21 != 0);
              FUN_10003130(local_a4,piVar11,(int)piVar8 - ((int)piVar11 + 2) >> 1);
              local_8 = CONCAT31(local_8._1_3_,0x10);
              FUN_1000f2c0(local_c8,(int *)local_a4);
              if (7 < local_90) {
                operator_delete(local_a4[0]);
              }
              local_90 = 7;
              local_94 = 0;
              local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
              local_8._0_1_ = 0xc;
              if (7 < local_20) {
                operator_delete(local_34[0]);
              }
              local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
              local_20 = 7;
              local_24 = 0;
              local_3c = 7;
              local_40 = 0;
              local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
              psVar12 = (short *)PTR_u_INLINE_II_1003a700;
              do {
                sVar1 = *psVar12;
                psVar12 = psVar12 + 1;
              } while (sVar1 != 0);
              FUN_10003130(local_50,(int *)PTR_u_INLINE_II_1003a700,
                           (int)psVar12 - (int)(PTR_u_INLINE_II_1003a700 + 2) >> 1);
              local_8._0_1_ = 0x11;
              FUN_1000f500(local_c8,(int *)local_50);
              local_8._0_1_ = 0xc;
              if (7 < local_3c) {
                operator_delete(local_50[0]);
              }
              piVar11 = (int *)FUN_1001f330((undefined4 *)(local_c4[1] + local_d8));
              local_20 = 7;
              local_24 = 0;
              local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
              piVar8 = piVar11;
              do {
                iVar21 = *piVar8;
                piVar8 = (int *)((int)piVar8 + 2);
              } while ((short)iVar21 != 0);
              FUN_10003130(local_34,piVar11,(int)piVar8 - ((int)piVar11 + 2) >> 1);
              local_8._0_1_ = 0x12;
              FUN_1000f980(local_c8,(int *)local_34);
              local_8._0_1_ = 0xc;
              if (7 < local_20) {
                operator_delete(local_34[0]);
              }
              local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
              local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
              local_20 = 7;
              local_24 = 0;
              local_90 = 7;
              local_94 = 0;
              psVar12 = (short *)PTR_u_Cummins__Inc__1003a6f8;
              do {
                sVar1 = *psVar12;
                psVar12 = psVar12 + 1;
              } while (sVar1 != 0);
              FUN_10003130(local_a4,(int *)PTR_u_Cummins__Inc__1003a6f8,
                           (int)psVar12 - (int)(PTR_u_Cummins__Inc__1003a6f8 + 2) >> 1);
              pvVar6 = local_c8;
              local_8._0_1_ = 0x13;
              FUN_1000f080(local_c8,(int *)local_a4);
              local_8._0_1_ = 0xc;
              if (7 < local_90) {
                operator_delete(local_a4[0]);
              }
              piVar8 = local_c4;
              cVar3 = FUN_10015740(*(int **)(local_c4[5] + local_d0 * 4));
              if (cVar3 == '\x01') {
                (**(code **)(*piVar4 + 4))();
              }
              else {
                local_d8 = 2;
                FUN_1000e8f0(pvVar6,&local_d8);
              }
              ppvVar2 = (void **)piVar8[0x13];
              if ((&local_c8 < ppvVar2) && (ppvVar18 = (void **)piVar8[0x12], ppvVar18 <= &local_c8)
                 ) {
                ppvVar16 = (void **)piVar8[0x14];
                iVar21 = (int)&local_c8 - (int)ppvVar18;
                if (ppvVar2 == ppvVar16) {
                  uVar9 = (int)ppvVar2 - (int)ppvVar18 >> 2;
                  if (0x3ffffffe < uVar9) {
                    std::_Xlength_error("vector<T> too long");
                    uVar9 = extraout_EAX_02;
                    ppvVar16 = extraout_ECX_08;
                    ppvVar18 = extraout_EDX;
                  }
                  pcVar13 = (char *)(uVar9 + 1);
                  pcVar17 = (char *)((int)ppvVar16 - (int)ppvVar18 >> 2);
                  if (pcVar17 < pcVar13) {
                    if ((char *)(0x3fffffff - ((uint)pcVar17 >> 1)) < pcVar17) {
                      pcVar17 = (char *)0x0;
                    }
                    else {
                      pcVar17 = pcVar17 + ((uint)pcVar17 >> 1);
                    }
                    if (pcVar17 < pcVar13) {
                      pcVar17 = pcVar13;
                    }
                    FUN_100159d0(piVar8 + 0x12,pcVar17);
                  }
                }
                if ((undefined4 *)piVar8[0x13] != (undefined4 *)0x0) {
                  *(undefined4 *)piVar8[0x13] = *(undefined4 *)(piVar8[0x12] + (iVar21 >> 2) * 4);
                }
              }
              else {
                ppvVar18 = (void **)piVar8[0x14];
                if (ppvVar2 == ppvVar18) {
                  iVar21 = piVar8[0x12];
                  uVar9 = (int)ppvVar2 - iVar21 >> 2;
                  if (0x3ffffffe < uVar9) {
                    std::_Xlength_error("vector<T> too long");
                    uVar9 = extraout_EAX_03;
                    ppvVar18 = extraout_ECX_09;
                    iVar21 = extraout_EDX_00;
                  }
                  pcVar13 = (char *)(uVar9 + 1);
                  pcVar17 = (char *)((int)ppvVar18 - iVar21 >> 2);
                  if (pcVar17 < pcVar13) {
                    if ((char *)(0x3fffffff - ((uint)pcVar17 >> 1)) < pcVar17) {
                      pcVar17 = (char *)0x0;
                    }
                    else {
                      pcVar17 = pcVar17 + ((uint)pcVar17 >> 1);
                    }
                    if (pcVar17 < pcVar13) {
                      pcVar17 = pcVar13;
                    }
                    FUN_100159d0(piVar8 + 0x12,pcVar17);
                    pvVar6 = local_c8;
                  }
                }
                if ((undefined4 *)piVar8[0x13] != (undefined4 *)0x0) {
                  *(undefined4 *)piVar8[0x13] = pvVar6;
                }
              }
              piVar8[0x13] = piVar8[0x13] + 4;
              (**(code **)(*(int *)((int)local_c8 + 8) + 0x30))();
              if (piVar4 != (int *)0x0) {
                (**(code **)*piVar4)();
              }
            }
            piVar4 = local_c4;
            local_e8 = local_e8 + (int)local_cc;
            pIVar14 = (IUnknownVtbl *)local_c0.QueryInterface;
            if (local_ac < 8) {
              pIVar14 = &local_c0;
            }
            FUN_10014b60((void *)*local_c4,(IUnknown *)0x43b,local_e8,(IUnknown *)pIVar14,(int *)0x4
                        );
            piVar8 = FUN_10006830(piVar4);
            if (*piVar8 == 3) {
              pIVar14 = (IUnknownVtbl *)FUN_10007c40();
              local_8._0_1_ = 0x14;
              if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar14 + 0x14))->lpVtbl) {
                pIVar14 = ((IUnknown *)pIVar14)->lpVtbl;
              }
              FUN_10014b60((void *)*piVar4,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar14,
                           (int *)0x4);
              if (7 < local_20) {
                operator_delete(local_34[0]);
              }
              if (7 < local_74) {
                operator_delete(local_88);
              }
              local_74 = 7;
              local_78 = 0;
              local_88 = (ushort *)((uint)local_88 & 0xffff0000);
              if (7 < local_58) {
                operator_delete(local_6c);
              }
              goto LAB_100094ba;
            }
            puVar19 = local_d4;
          }
        }
      }
      piVar8 = FUN_10006830(piVar4);
      if (*piVar8 == 3) {
        pIVar14 = (IUnknownVtbl *)FUN_10007c40();
        local_8._0_1_ = 0x15;
        if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar14 + 0x14))->lpVtbl) {
          pIVar14 = ((IUnknown *)pIVar14)->lpVtbl;
        }
        FUN_10014b60((void *)*piVar4,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar14,
                     (int *)0x4);
        if (7 < local_20) {
          operator_delete(local_34[0]);
        }
        if (7 < local_74) {
          operator_delete(local_88);
        }
        local_74 = 7;
        local_78 = 0;
        local_88 = (ushort *)((uint)local_88 & 0xffff0000);
        if (7 < local_58) {
          operator_delete(local_6c);
        }
LAB_100094ba:
        local_58 = 7;
        local_5c = 0;
        local_6c = (ushort *)((uint)local_6c._2_2_ << 0x10);
        if (local_ac < 8) goto LAB_100094d7;
        goto LAB_100094cf;
      }
    }
    if (7 < local_74) {
      operator_delete(local_88);
    }
    local_74 = 7;
    local_78 = 0;
    local_88 = (ushort *)((uint)local_88 & 0xffff0000);
    if (7 < local_58) {
      operator_delete(local_6c);
    }
    local_58 = 7;
    local_5c = 0;
    local_6c = (ushort *)((uint)local_6c & 0xffff0000);
    if (7 < local_ac) {
LAB_100094cf:
      local_58 = 7;
      local_5c = 0;
      operator_delete(local_c0.QueryInterface);
    }
  }
LAB_100094d7:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000960f at 1000960f

undefined * Catch_1000960f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0xec),"AutoConfigureManager.cpp",0x2fa,
               "CAutoConfigure::detectINLINEIIAdapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b)
  ;
  return &DAT_1000965d;
}



// Function: Catch_All@10009662 at 10009662

undefined4 Catch_All_10009662(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x40) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FUN_10020630((void *)(unaff_EBP + -0x40),"AutoConfigureManager.cpp",0x2fa,
               "CAutoConfigure::detectINLINEIIAdapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b)
  ;
  uStack0000001c = 0x100096c9;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return 0x100094d7;
}



// Function: FUN_100096d0 at 100096d0

/* WARNING: Removing unreachable block (ram,0x10009eae) */

void FUN_100096d0(void)

{
  short sVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  wchar_t *pwVar10;
  int *piVar11;
  int *piVar12;
  short *psVar13;
  IUnknownVtbl *pIVar14;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  ushort *puVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  uint uStack_fc;
  undefined1 *local_e0;
  int local_d4;
  void *local_cc;
  int *local_c8;
  char local_c1;
  IUnknownVtbl local_c0;
  uint local_ac;
  void *local_a4 [4];
  undefined4 local_94;
  uint local_90;
  undefined4 local_88;
  uint local_78;
  uint local_74;
  undefined4 local_6c;
  uint local_5c;
  uint local_58;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023320;
  local_10 = ExceptionList;
  uStack_fc = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_fc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_fc;
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffef4,0x1002a200);
  pvVar6 = *(void **)(*local_c8 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar8,piVar4);
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar19 = 4;
  uVar18 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffeec,0x1002a1b0);
  pvVar6 = *(void **)(*local_c8 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar6,piVar8,uVar18,uVar19,piVar4);
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar8 = extraout_ECX_05;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar8 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_07;
  }
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xfffffef4,0x1002a1b0);
  pvVar6 = *(void **)(*local_c8 + 4);
  local_8._0_1_ = 9;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar8,piVar4);
  piVar4 = local_c8;
  uVar9 = 0;
  for (uVar17 = 0; uVar17 < (uint)((piVar4[2] - piVar4[1]) / 0x1c); uVar17 = uVar17 + 1) {
    uVar7 = FUN_10006250(piVar4,(void *)(piVar4[1] + uVar17 * 0x1c));
    if ((char)uVar7 == '\x01') {
      uVar9 = uVar7 & 0xff;
    }
  }
  if ((char)uVar9 == '\x01') {
    local_e0 = (undefined1 *)0x2d;
    FUN_10007c40();
    local_8._0_1_ = 10;
    pIVar14 = (IUnknownVtbl *)local_c0.QueryInterface;
    if (local_ac < 8) {
      pIVar14 = &local_c0;
    }
    FUN_10014b60((void *)*piVar4,(IUnknown *)0x43c,(undefined1 *)0x2d,(IUnknown *)pIVar14,(int *)0x4
                );
    iVar5 = (piVar4[2] - piVar4[1]) / 0x1c;
    iVar16 = piVar4[6] - piVar4[5] >> 2;
    local_74 = 7;
    local_78 = 0;
    local_88 = (ushort *)((uint)local_88._2_2_ << 0x10);
    FUN_10003130(&local_88,(int *)&DAT_1002a064,3);
    local_8._0_1_ = 0xb;
    local_58 = 7;
    local_5c = 0;
    local_6c = (ushort *)((uint)local_6c._2_2_ << 0x10);
    FUN_10003130(&local_6c,(int *)L"COM Port Auto Detect",0x14);
    local_8._0_1_ = 0xc;
    local_c1 = '\0';
    local_c8 = (int *)0x0;
    while (((int)local_c8 < iVar16 && (local_c1 == '\0'))) {
      iVar2 = (int)local_c8 * 4;
      piVar8 = FUN_100152c0(*(int **)(piVar4[5] + iVar2));
      puVar15 = local_88;
      if (local_74 < 8) {
        puVar15 = (ushort *)&local_88;
      }
      uVar9 = FUN_10005600(piVar8,0,piVar8[4],puVar15,local_78);
      if (uVar9 != 0) {
        piVar8 = FUN_100152c0(*(int **)(piVar4[5] + iVar2));
        puVar15 = local_6c;
        if (local_58 < 8) {
          puVar15 = (ushort *)&local_6c;
        }
        uVar9 = FUN_10005600(piVar8,0,piVar8[4],puVar15,local_5c);
        if (uVar9 != 0) {
          local_d4 = 0;
          while ((local_d4 < iVar5 && (local_c1 == '\0'))) {
            cVar3 = FUN_10015740(*(int **)(piVar4[5] + (int)local_c8 * 4));
            if (cVar3 != '\0') {
              uVar18 = FUN_10006250(piVar4,(void *)(piVar4[1] + local_d4 * 0x1c));
              if ((char)uVar18 == '\x01') {
                piVar8 = (int *)FUN_1000e0e0(piVar4 + 9);
                FUN_10005790(&local_cc);
                if (local_cc == (void *)0x0) {
                  pwVar10 = (wchar_t *)FUN_10007c40();
                  local_8._0_1_ = 0xd;
                  if (7 < *(uint *)(pwVar10 + 10)) {
                    pwVar10 = *(wchar_t **)pwVar10;
                  }
                  FUN_10015000((void *)*piVar4,0x443,0x80004005,0x1002a1b0,
                               L"AutoConfigureManager.cpp",(undefined1 *)0x354,pwVar10);
                  local_8._0_1_ = 0xc;
                  if (7 < local_20) {
                    operator_delete(local_34[0]);
                  }
                }
                piVar11 = FUN_100152c0(*(int **)(piVar4[5] + (int)local_c8 * 4));
                piVar12 = (int *)FUN_1001f330(piVar11);
                local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
                local_3c = 7;
                local_40 = 0;
                piVar11 = piVar12;
                do {
                  iVar2 = *piVar11;
                  piVar11 = (int *)((int)piVar11 + 2);
                } while ((short)iVar2 != 0);
                FUN_10003130(local_50,piVar12,(int)piVar11 - ((int)piVar12 + 2) >> 1);
                local_8._0_1_ = 0xe;
                FUN_1000f740(local_cc,(int *)local_50);
                local_8._0_1_ = 0xc;
                if (7 < local_3c) {
                  operator_delete(local_50[0]);
                }
                local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
                local_40 = 0;
                local_24 = 0;
                local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
                local_3c = 7;
                local_20 = 7;
                psVar13 = (short *)PTR_u_INLINE_INLINE_I_1003a6fc;
                do {
                  sVar1 = *psVar13;
                  psVar13 = psVar13 + 1;
                } while (sVar1 != 0);
                FUN_10003130(local_34,(int *)PTR_u_INLINE_INLINE_I_1003a6fc,
                             (int)psVar13 - (int)(PTR_u_INLINE_INLINE_I_1003a6fc + 2) >> 1);
                local_8._0_1_ = 0xf;
                piVar12 = (int *)FUN_1001f330(local_34);
                local_90 = 7;
                local_94 = 0;
                local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
                piVar11 = piVar12;
                do {
                  iVar2 = *piVar11;
                  piVar11 = (int *)((int)piVar11 + 2);
                } while ((short)iVar2 != 0);
                FUN_10003130(local_a4,piVar12,(int)piVar11 - ((int)piVar12 + 2) >> 1);
                local_8 = CONCAT31(local_8._1_3_,0x10);
                FUN_1000f2c0(local_cc,(int *)local_a4);
                if (7 < local_90) {
                  operator_delete(local_a4[0]);
                }
                local_90 = 7;
                local_94 = 0;
                local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
                local_8._0_1_ = 0xc;
                if (7 < local_20) {
                  operator_delete(local_34[0]);
                }
                local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
                local_24 = 0;
                local_40 = 0;
                local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
                local_20 = 7;
                local_3c = 7;
                psVar13 = (short *)PTR_u_INLINE_INLINE_I_1003a6fc;
                do {
                  sVar1 = *psVar13;
                  psVar13 = psVar13 + 1;
                } while (sVar1 != 0);
                FUN_10003130(local_50,(int *)PTR_u_INLINE_INLINE_I_1003a6fc,
                             (int)psVar13 - (int)(PTR_u_INLINE_INLINE_I_1003a6fc + 2) >> 1);
                local_8._0_1_ = 0x11;
                FUN_1000f500(local_cc,(int *)local_50);
                local_8._0_1_ = 0xc;
                if (7 < local_3c) {
                  operator_delete(local_50[0]);
                }
                piVar12 = (int *)FUN_1001f330((undefined4 *)(piVar4[1] + local_d4 * 0x1c));
                local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
                local_20 = 7;
                local_24 = 0;
                piVar11 = piVar12;
                do {
                  iVar2 = *piVar11;
                  piVar11 = (int *)((int)piVar11 + 2);
                } while ((short)iVar2 != 0);
                FUN_10003130(local_34,piVar12,(int)piVar11 - ((int)piVar12 + 2) >> 1);
                local_8._0_1_ = 0x12;
                FUN_1000f980(local_cc,(int *)local_34);
                local_8._0_1_ = 0xc;
                if (7 < local_20) {
                  operator_delete(local_34[0]);
                }
                local_a4[0] = (void *)((uint)local_a4[0] & 0xffff0000);
                local_20 = 7;
                local_90 = 7;
                local_24 = 0;
                local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
                local_94 = 0;
                psVar13 = (short *)PTR_u_Cummins__Inc__1003a6f8;
                do {
                  sVar1 = *psVar13;
                  psVar13 = psVar13 + 1;
                } while (sVar1 != 0);
                FUN_10003130(local_a4,(int *)PTR_u_Cummins__Inc__1003a6f8,
                             (int)psVar13 - (int)(PTR_u_Cummins__Inc__1003a6f8 + 2) >> 1);
                local_8._0_1_ = 0x13;
                FUN_1000f080(local_cc,(int *)local_a4);
                local_8._0_1_ = 0xc;
                if (7 < local_90) {
                  operator_delete(local_a4[0]);
                }
                (**(code **)(*piVar8 + 4))();
                FUN_10006e80(piVar4 + 0x12,&local_cc);
                (**(code **)(*(int *)((int)local_cc + 8) + 0x30))();
                (**(code **)*piVar8)();
              }
            }
            local_e0 = local_e0 + (int)(0x14 / (longlong)(iVar5 * iVar16));
            pIVar14 = (IUnknownVtbl *)local_c0.QueryInterface;
            if (local_ac < 8) {
              pIVar14 = &local_c0;
            }
            FUN_10014b60((void *)*piVar4,(IUnknown *)0x43c,local_e0,(IUnknown *)pIVar14,(int *)0x4);
            piVar8 = FUN_10006830(piVar4);
            if (*piVar8 == 3) {
              pIVar14 = (IUnknownVtbl *)FUN_10007c40();
              local_8._0_1_ = 0x14;
              if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar14 + 0x14))->lpVtbl) {
                pIVar14 = ((IUnknown *)pIVar14)->lpVtbl;
              }
              FUN_10014b60((void *)*piVar4,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar14,
                           (int *)0x4);
              if (7 < local_20) {
                operator_delete(local_34[0]);
              }
              if (7 < local_58) {
                operator_delete(local_6c);
              }
              local_58 = 7;
              local_5c = 0;
              local_6c = (ushort *)((uint)local_6c & 0xffff0000);
              if (7 < local_74) {
                operator_delete(local_88);
              }
              goto LAB_10009f9a;
            }
            local_d4 = local_d4 + 1;
          }
        }
      }
      piVar8 = FUN_10006830(piVar4);
      if (*piVar8 == 3) {
        pIVar14 = (IUnknownVtbl *)FUN_10007c40();
        local_8._0_1_ = 0x15;
        if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar14 + 0x14))->lpVtbl) {
          pIVar14 = ((IUnknown *)pIVar14)->lpVtbl;
        }
        FUN_10014b60((void *)*piVar4,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar14,
                     (int *)0x4);
        if (7 < local_20) {
          operator_delete(local_34[0]);
        }
        if (7 < local_58) {
          operator_delete(local_6c);
        }
        local_58 = 7;
        local_5c = 0;
        local_6c = (ushort *)((uint)local_6c & 0xffff0000);
        if (7 < local_74) {
          operator_delete(local_88);
        }
LAB_10009f9a:
        local_74 = 7;
        local_78 = 0;
        local_88 = (ushort *)((uint)local_88._2_2_ << 0x10);
        if (local_ac < 8) goto LAB_10009fba;
        goto LAB_10009fb2;
      }
      local_c8 = (int *)((int)local_c8 + 1);
    }
    if (7 < local_58) {
      operator_delete(local_6c);
    }
    local_58 = 7;
    local_5c = 0;
    local_6c = (ushort *)((uint)local_6c & 0xffff0000);
    if (7 < local_74) {
      operator_delete(local_88);
    }
    local_74 = 7;
    local_78 = 0;
    local_88 = (ushort *)((uint)local_88 & 0xffff0000);
    if (7 < local_ac) {
LAB_10009fb2:
      local_74 = 7;
      local_78 = 0;
      operator_delete(local_c0.QueryInterface);
    }
  }
LAB_10009fba:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000a0e9 at 1000a0e9

undefined * Catch_1000a0e9(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0xe8),"AutoConfigureManager.cpp",0x382,
               "CAutoConfigure::detectINLINEAdapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1000a137;
}



// Function: Catch_All@1000a13c at 1000a13c

undefined4 Catch_All_1000a13c(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x40) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FUN_10020630((void *)(unaff_EBP + -0x40),"AutoConfigureManager.cpp",0x382,
               "CAutoConfigure::detectINLINEAdapters",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1000a1a3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return 0x10009fba;
}



// Function: FUN_1000a1b0 at 1000a1b0

void __fastcall FUN_1000a1b0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  wchar_t *pwVar5;
  int *piVar6;
  void *extraout_EAX_01;
  void *pvVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_44;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100233c4;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar3 = iVar4;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff84,0x1002a458);
  pvVar7 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar7,piVar6,piVar3);
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar3 = iVar4;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff7c,0x1002a3f8);
  pvVar7 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar7,piVar6,uVar8,uVar9,piVar3);
  if ((param_1[0x13] - param_1[0x12] & 0xfffffffcU) == 0) {
    pwVar5 = (wchar_t *)FUN_10007c40();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar5 + 10)) {
      pwVar5 = *(wchar_t **)pwVar5;
    }
    FUN_10015000((void *)*param_1,0x12f,0x80004005,0x1002a398,L"AutoConfigureManager.cpp",
                 (undefined1 *)0x42c,pwVar5);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  for (iVar4 = 0; iVar4 < param_1[0x13] - param_1[0x12] >> 2; iVar4 = iVar4 + 1) {
    iVar1 = *(int *)(param_1[0x12] + iVar4 * 4);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x30))();
      if (local_44 == 1) goto LAB_1000a4f6;
    }
  }
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 8;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar3 = iVar4;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  uVar9 = 4;
  uVar8 = 2;
  local_8._0_1_ = 9;
  piVar6 = (int *)operator_new(0xc);
  local_8 = CONCAT31(local_8._1_3_,10);
  if (piVar6 != (int *)0x0) {
    piVar6[1] = 0;
    piVar6[2] = 1;
    iVar4 = Ordinal_2(
                     L"CAutoConfigure::checkAdapterDetectionFailure, failed to detected dataling adapters."
                     );
    *piVar6 = iVar4;
    if (iVar4 != 0) goto LAB_1000a468;
    _com_issue_error(-0x7ff8fff2);
  }
  piVar6 = (int *)0x0;
LAB_1000a468:
  local_8._0_1_ = 9;
  if (piVar6 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  pvVar7 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 0xb;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX_01;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar7,piVar6,uVar8,uVar9,piVar3);
  pwVar5 = (wchar_t *)FUN_10007c40();
  local_8._0_1_ = 0xc;
  if (7 < *(uint *)(pwVar5 + 10)) {
    pwVar5 = *(wchar_t **)pwVar5;
  }
  FUN_10015000((void *)*param_1,0x12f,0x80004005,0x1002a398,L"AutoConfigureManager.cpp",
               (undefined1 *)0x448,pwVar5);
  if (7 < local_20) {
    operator_delete(local_34);
  }
LAB_1000a4f6:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000a512 at 1000a512

undefined * Catch_1000a512(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"AutoConfigureManager.cpp",1099,
               "CAutoConfigure::checkAdapterDetectionFailure",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1000a55d;
}



// Function: Catch_All@1000a55f at 1000a55f

undefined4 Catch_All_1000a55f(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10020630((void *)(unaff_EBP + -0x50),"AutoConfigureManager.cpp",1099,
               "CAutoConfigure::checkAdapterDetectionFailure",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000a5c6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x1000a4f6;
}



// Function: FUN_1000a5d0 at 1000a5d0

undefined4 * __cdecl FUN_1000a5d0(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023409;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  local_8 = 0;
  piVar4 = param_3;
  do {
    iVar2 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 2);
  } while ((short)iVar2 != 0);
  uVar1 = param_1[4];
  uVar5 = ((int)piVar4 - ((int)param_3 + 2) >> 1) + param_2[4];
  if (((uVar1 <= uVar5) && (param_1[5] != uVar5)) &&
     (bVar3 = FUN_100027f0(param_1,uVar5,'\x01'), bVar3)) {
    param_1[4] = uVar1;
    puVar6 = param_1;
    if (7 < (uint)param_1[5]) {
      puVar6 = (undefined4 *)*param_1;
    }
    *(undefined2 *)((int)puVar6 + uVar1 * 2) = 0;
  }
  FUN_10005a70(param_1,param_2,0,0xffffffff);
  piVar4 = param_3;
  do {
    iVar2 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 2);
  } while ((short)iVar2 != 0);
  FUN_10005cf0(param_1,param_3,(int)piVar4 - ((int)param_3 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a6c0 at 1000a6c0

undefined4 * __cdecl FUN_1000a6c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    if (param_3 != param_1) {
      if (7 < (uint)param_3[5]) {
        operator_delete((void *)*param_3);
      }
      param_3[5] = 7;
      param_3[4] = 0;
      *(undefined2 *)param_3 = 0;
      if ((uint)param_1[5] < 8) {
        memmove(param_3,param_1,param_1[4] * 2 + 2);
      }
      else {
        *param_3 = *param_1;
        *param_1 = 0;
      }
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_1[5] = 7;
      param_1[4] = 0;
      *(undefined2 *)param_1 = 0;
    }
    param_1 = param_1 + 7;
    param_3 = param_3 + 7;
  } while (param_1 != param_2);
  return param_3;
}



// Function: FUN_1000a750 at 1000a750

/* WARNING: Removing unreachable block (ram,0x1000ab07) */

void FUN_1000a750(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  uint uStack_198;
  int *local_174;
  int local_170 [7];
  int local_154 [7];
  undefined4 local_138 [7];
  int local_11c [14];
  undefined4 local_e4 [14];
  int local_ac [7];
  undefined1 local_90 [92];
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100234b6;
  local_10 = ExceptionList;
  uStack_198 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_198;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_198;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffe58,0x1002a5b8);
  pvVar3 = *(void **)(*local_174 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffe58,0x1002a560);
  piVar5 = local_174;
  pvVar3 = *(void **)(*local_174 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  FUN_1001afc0(local_90,(char *)*piVar5);
  local_8._0_1_ = 7;
  piVar1 = FUN_1000a5d0(&local_34,piVar5 + 0x16,(int *)L".ini");
  local_8._0_1_ = 8;
  FUN_100194d0(local_90,piVar1);
  local_8._0_1_ = 7;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  FUN_1001be40();
  FUN_10019390(local_90,(undefined2 *)local_170,piVar5 + 0x1d);
  local_8._0_1_ = 9;
  piVar4 = (int *)FUN_1000db70(piVar5 + 9,local_11c,local_170);
  FUN_10005790(&local_174);
  FUN_1000f080(local_174,local_ac);
  piVar5 = (int *)FUN_1001f330(local_138);
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  piVar1 = piVar5;
  do {
    iVar2 = *piVar1;
    piVar1 = (int *)((int)piVar1 + 2);
  } while ((short)iVar2 != 0);
  FUN_10003130(&local_34,piVar5,(int)piVar1 - ((int)piVar5 + 2) >> 1);
  piVar1 = local_174;
  local_8._0_1_ = 10;
  FUN_1000f2c0(local_174,&local_34);
  local_8._0_1_ = 9;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  FUN_1000f500(piVar1,local_154);
  piVar5 = (int *)FUN_1001f330(local_e4);
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  piVar1 = piVar5;
  do {
    iVar2 = *piVar1;
    piVar1 = (int *)((int)piVar1 + 2);
  } while ((short)iVar2 != 0);
  FUN_10003130(&local_34,piVar5,(int)piVar1 - ((int)piVar5 + 2) >> 1);
  local_8._0_1_ = 0xb;
  FUN_1000f740(local_174,&local_34);
  local_8._0_1_ = 9;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  piVar5 = (int *)FUN_1001f330(param_1);
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  piVar1 = piVar5;
  do {
    iVar2 = *piVar1;
    piVar1 = (int *)((int)piVar1 + 2);
  } while ((short)iVar2 != 0);
  FUN_10003130(&local_34,piVar5,(int)piVar1 - ((int)piVar5 + 2) >> 1);
  local_8._0_1_ = 0xc;
  FUN_1000f980(local_174,&local_34);
  local_8._0_1_ = 9;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  (**(code **)(*piVar4 + 4))();
  (**(code **)(local_174[2] + 0x30))();
  (**(code **)*piVar4)();
  (**(code **)(*local_174 + 0x14))(1);
  FUN_10005b80(local_170);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1001a600((int)local_90);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000ab53 at 1000ab53

undefined * Catch_1000ab53(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x184),"AutoConfigureManager.cpp",0x160,
               "CAutoConfigure::validateRP1210Connection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  return &DAT_1000aba1;
}



// Function: Catch_All@1000aba3 at 1000aba3

undefined4 Catch_All_1000aba3(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureManager.cpp",0x160,
               "CAutoConfigure::validateRP1210Connection",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  uStack0000001c = 0x1000ac0a;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x1000ab33;
}



// Function: FUN_1000ac10 at 1000ac10

void __fastcall FUN_1000ac10(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  IUnknownVtbl *pIVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uStack_60;
  void *local_34 [5];
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023559;
  local_10 = ExceptionList;
  uStack_60 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_60;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff90,0x1002a698);
  pvVar4 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar8 = 4;
  uVar7 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff88,0x1002a640);
  pvVar4 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar6,uVar7,uVar8,piVar1);
  piVar1 = FUN_10006830(param_1);
  if (*piVar1 == 3) {
    pIVar3 = (IUnknownVtbl *)FUN_10007c40();
    local_8 = CONCAT31(local_8._1_3_,7);
LAB_1000ad8f:
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
      pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
    }
    FUN_10014b60((void *)*param_1,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar3,(int *)0x4
                );
  }
  else {
    pvVar4 = operator_new(0x40);
    local_8._0_1_ = 8;
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = FUN_1001dd50(pvVar4,*param_1,param_1 + 9,param_1 + 1,param_1 + 5);
    }
    local_8._0_1_ = 0;
    param_1[10] = (int)puVar5;
    FUN_10006f70(param_1);
    FUN_100083b0();
    piVar1 = FUN_10006830(param_1);
    if (*piVar1 == 3) {
      pIVar3 = (IUnknownVtbl *)FUN_10007c40();
      local_8 = CONCAT31(local_8._1_3_,9);
      goto LAB_1000ad8f;
    }
    FUN_100087e0(param_1,0);
    piVar1 = FUN_10006830(param_1);
    if (*piVar1 != 3) {
      FUN_10008b30();
      piVar1 = FUN_10006830(param_1);
      if (*piVar1 == 3) {
        pIVar3 = (IUnknownVtbl *)FUN_10007c40();
        local_8 = CONCAT31(local_8._1_3_,0xb);
      }
      else {
        FUN_100096d0();
        piVar1 = FUN_10006830(param_1);
        if (*piVar1 != 3) {
          FUN_100087e0(param_1,1);
          pIVar3 = (IUnknownVtbl *)FUN_10007c40();
          local_8._0_1_ = 0xd;
          if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
            pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
          }
          FUN_10014b60((void *)*param_1,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar3,
                       (int *)0x4);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100027c0(local_34);
          pvVar4 = (void *)param_1[10];
          if (pvVar4 != (void *)0x0) {
            FUN_1001ddb0((int)pvVar4);
            operator_delete(pvVar4);
            param_1[10] = 0;
          }
          FUN_10006550(param_1,1);
          goto LAB_1000adb8;
        }
        pIVar3 = (IUnknownVtbl *)FUN_10007c40();
        local_8 = CONCAT31(local_8._1_3_,0xc);
      }
      if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
        pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
      }
      FUN_10014b60((void *)*param_1,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar3,
                   (int *)0x4);
      FUN_100027c0(local_34);
      goto LAB_1000adb8;
    }
    pIVar3 = (IUnknownVtbl *)FUN_10007c40();
    local_8 = CONCAT31(local_8._1_3_,10);
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
      pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
    }
    FUN_10014b60((void *)*param_1,(IUnknown *)0x43d,(undefined1 *)0x64,(IUnknown *)pIVar3,(int *)0x4
                );
  }
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
LAB_1000adb8:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000af67 at 1000af67

undefined * Catch_1000af67(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x4c),"AutoConfigureManager.cpp",0x215,
               "CAutoConfigure::executeAutoConfigureProcess",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1000afb2;
}



// Function: Catch_All@1000afb7 at 1000afb7

undefined4 Catch_All_1000afb7(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x48) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x44) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_10020630((void *)(unaff_EBP + -0x48),"AutoConfigureManager.cpp",0x215,
               "CAutoConfigure::executeAutoConfigureProcess",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000b01e;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return 0x1000adb8;
}



// Function: FUN_1000b030 at 1000b030

undefined2 * __cdecl FUN_1000b030(undefined4 *param_1,undefined4 *param_2,undefined2 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_10023591;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    local_8 = 1;
    if (param_3 != (undefined2 *)0x0) {
      *(undefined4 *)(param_3 + 10) = 7;
      *(undefined4 *)(param_3 + 8) = 0;
      *param_3 = 0;
      FUN_10004710(param_3,param_1);
    }
    param_3 = param_3 + 0xe;
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch_All@1000b0a5 at 1000b0a5

void Catch_All_1000b0a5(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(unaff_EBP + -0x14);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  if (puVar3 != puVar1) {
    uVar2 = *(undefined4 *)(unaff_EBP + 0x14);
    do {
      FUN_10007bd0(uVar2,puVar3);
      puVar3 = puVar3 + 7;
    } while (puVar3 != puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b0e0 at 1000b0e0

void __fastcall FUN_1000b0e0(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10007c00(*(undefined4 **)param_1,*(undefined4 **)(param_1 + 4));
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000b130 at 1000b130

undefined4 * __thiscall FUN_1000b130(void *this,undefined4 param_1)

{
  BOOL BVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100235c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_8 = 1;
  FUN_1000dad0((void *)((int)this + 0x24),param_1);
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 1;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 7;
  *(undefined2 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x88) = 7;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined2 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0xa4) = 7;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined2 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0xc0) = 7;
  *(undefined4 *)((int)this + 0xbc) = 0;
  *(undefined2 *)((int)this + 0xac) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((int)this + 0x30),0);
  if (BVar1 == 0) {
    GetLastError();
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000b220 at 1000b220

void __fastcall FUN_1000b220(int param_1)

{
  _Container_base0 *this;
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002364e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar3 = 0;
  local_8 = 7;
  if (0 < (int)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) & 0xfffffffcU)) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4) != 0) {
        pvVar1 = *(void **)(*(int *)(param_1 + 0x14) + iVar3 * 4);
        if (pvVar1 != (void *)0x0) {
          FUN_10015290((int)pvVar1);
          operator_delete(pvVar1);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar3 * 4) = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2);
  }
  pvVar1 = *(void **)(param_1 + 0x14);
  if (pvVar1 != *(void **)(param_1 + 0x18)) {
    memmove(pvVar1,*(void **)(param_1 + 0x18),0);
    *(void **)(param_1 + 0x18) = pvVar1;
  }
  pvVar1 = *(void **)(param_1 + 0x28);
  if (pvVar1 != (void *)0x0) {
    FUN_1001ddb0((int)pvVar1);
    operator_delete(pvVar1);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (7 < *(uint *)(param_1 + 0xc0)) {
    operator_delete(*(void **)(param_1 + 0xac));
  }
  *(undefined4 *)(param_1 + 0xc0) = 7;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined2 *)(param_1 + 0xac) = 0;
  if (7 < *(uint *)(param_1 + 0xa4)) {
    operator_delete(*(void **)(param_1 + 0x90));
  }
  *(undefined4 *)(param_1 + 0xa4) = 7;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined2 *)(param_1 + 0x90) = 0;
  if (7 < *(uint *)(param_1 + 0x88)) {
    operator_delete(*(void **)(param_1 + 0x74));
  }
  *(undefined4 *)(param_1 + 0x88) = 7;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined2 *)(param_1 + 0x74) = 0;
  if (7 < *(uint *)(param_1 + 0x6c)) {
    operator_delete(*(void **)(param_1 + 0x58));
  }
  *(undefined4 *)(param_1 + 0x6c) = 7;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined2 *)(param_1 + 0x58) = 0;
  local_8._0_1_ = 2;
  if (*(int *)(param_1 + 0x48) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x48));
    operator_delete(*(void **)(param_1 + 0x48));
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  local_8._0_1_ = 1;
  FUN_100054c0();
  local_8 = (uint)local_8._1_3_ << 8;
  if (*(int *)(param_1 + 0x14) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x14));
    operator_delete(*(void **)(param_1 + 0x14));
  }
  this = (_Container_base0 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_8 = 0xffffffff;
  if (*(int *)this != 0) {
    std::_Container_base0::_Orphan_all(this);
    puVar2 = *(undefined4 **)(param_1 + 8);
    for (puVar4 = *(undefined4 **)this; puVar4 != puVar2; puVar4 = puVar4 + 7) {
      if (7 < (uint)puVar4[5]) {
        operator_delete((void *)*puVar4);
      }
      puVar4[5] = 7;
      puVar4[4] = 0;
      *(undefined2 *)puVar4 = 0;
    }
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b480 at 1000b480

void __thiscall FUN_1000b480(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  int *piVar3;
  void *extraout_EAX_00;
  void *pvVar4;
  undefined4 *puVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_90;
  undefined1 local_58 [36];
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100236be;
  local_10 = ExceptionList;
  uStack_90 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_90;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff60,0x1002a798);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)&stack0xffffff64;
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar3 = iVar2;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar1 = extraout_ECX_02;
  }
  uVar7 = 4;
  uVar6 = 0;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff58,0x1002a718);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar1,uVar6,uVar7,piVar3);
  puVar5 = *(undefined4 **)((int)this + 8);
  if (*(undefined4 **)((int)this + 4) != puVar5) {
    puVar5 = FUN_1000a6c0(puVar5,puVar5,*(undefined4 **)((int)this + 4));
    FUN_10007c00(puVar5,*(undefined4 **)((int)this + 8));
    *(undefined4 **)((int)this + 8) = puVar5;
  }
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)*param_1;
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  piVar3 = piVar1;
  do {
    iVar2 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 2);
  } while ((short)iVar2 != 0);
  FUN_10003130(&local_34,piVar1,(int)piVar3 - ((int)piVar1 + 2) >> 1);
                    /* WARNING: Load size is inaccurate */
  local_8._0_1_ = 7;
  FUN_10017660(local_58,*this,&local_34);
  local_8._0_1_ = 9;
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  FUN_10017b70((int *)((int)this + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10017110((int)local_58);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b6bd at 1000b6bd

undefined * Catch_1000b6bd(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x7c),"AutoConfigureManager.cpp",0x19d,
               "CAutoConfigure::setProtocols",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1000b708;
}



// Function: Catch_All@1000b70a at 1000b70a

undefined4 Catch_All_1000b70a(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x78) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x74) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x78),"AutoConfigureManager.cpp",0x19d,
               "CAutoConfigure::setProtocols",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1000b771;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x78));
  return 0x1000b69f;
}



// Function: FUN_1000b780 at 1000b780

void __thiscall FUN_1000b780(void *this,char *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100236f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    puVar3 = (undefined2 *)FUN_10005730(param_1);
                    /* WARNING: Load size is inaccurate */
    local_8 = 0;
    FUN_1000b030(*this,*(undefined4 **)((int)this + 4),puVar3);
                    /* WARNING: Load size is inaccurate */
    puVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    local_8 = 0xffffffff;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10007c00(puVar1,*(undefined4 **)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined2 **)((int)this + 8) = puVar3 + (int)param_1 * 0xe;
    *(undefined2 **)((int)this + 4) = puVar3 + ((iVar2 - (int)puVar1) / 0x1c) * 0xe;
    *(undefined2 **)this = puVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch_All@1000b893 at 1000b893

void Catch_All_1000b893(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b8b0 at 1000b8b0

void __thiscall FUN_1000b8b0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002374e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002a898);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffac,0x1002a838);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  piVar1 = FUN_10006830((int *)this);
  if ((*piVar1 != 1) && (piVar1 = FUN_10006830((int *)this), *piVar1 != 3)) {
    ExceptionList = local_10;
    return;
  }
  FUN_1000b480(this,param_1);
  FUN_10006550(this,2);
  FUN_1000ac10((int *)this);
  FUN_10007fe0((int *)this);
  FUN_1000a1b0((int *)this);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000ba53 at 1000ba53

undefined1 * Catch_1000ba53(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"AutoConfigureManager.cpp",0x84,
               "CAutoConfigure::AutoDetectAdapterConfiguration",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &LAB_1000ba9e;
}



// Function: Catch_All@1000bab2 at 1000bab2

undefined4 Catch_All_1000bab2(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"AutoConfigureManager.cpp",0x84,
               "CAutoConfigure::AutoDetectAdapterConfiguration",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000bb19;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000ba3f;
}



// Function: FUN_1000bb20 at 1000bb20

void __thiscall FUN_1000bb20(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  char *pcVar3;
  void *extraout_ECX;
  char *pcVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = (*(int *)((int)this + 4) - iVar1) / 0x1c;
  if (0x9249249U - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  pcVar4 = (char *)(uVar2 + param_1);
  pcVar3 = (char *)((*(int *)((int)this + 8) - iVar1) / 0x1c);
  if (pcVar3 < pcVar4) {
    if ((char *)(0x9249249 - ((uint)pcVar3 >> 1)) < pcVar3) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = pcVar3 + ((uint)pcVar3 >> 1);
    }
    if (pcVar3 < pcVar4) {
      pcVar3 = pcVar4;
    }
    FUN_1000b780(this,pcVar3);
  }
  return;
}



// Function: FUN_1000bba0 at 1000bba0

void __thiscall FUN_1000bba0(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100257b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < piVar1) && (piVar2 = *this, piVar2 <= param_1)) {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_1000bb20(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (int *)(*this + (((int)param_1 - (int)piVar2) / 0x1c) * 0x1c);
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000bc6b;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  else {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_1000bb20(this,1);
    }
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000bc6b;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  FUN_10003030(this_00,param_1,0,0xffffffff);
LAB_1000bc6b:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bc90 at 1000bc90

void FUN_1000bc90(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar6;
  uint uVar7;
  short *psVar8;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar9;
  undefined4 *puVar10;
  uint uStack_84;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 local_60;
  int *local_58;
  char local_51;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100237ce;
  local_10 = ExceptionList;
  uStack_84 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_84;
  ExceptionList = &local_10;
  local_8 = 0;
  local_51 = '\0';
  local_18 = uStack_84;
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar9 = extraout_ECX;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar9 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar9 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff6c,0x1002ab08);
  pvVar6 = *(void **)(*local_58 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar9,piVar4);
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar9 = extraout_ECX_02;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("AutoConfigureManager.cpp");
    *piVar4 = iVar5;
    piVar9 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar9 = extraout_ECX_04;
  }
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff6c,0x1002aaa8);
  pvVar6 = *(void **)(*local_58 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar9,piVar4);
  local_68 = (undefined4 *)0x0;
  local_64 = (undefined4 *)0x0;
  local_60 = 0;
  local_8._0_1_ = 7;
  psVar8 = (short *)PTR_u_Auto_Detect_1003a6f4;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  uVar7 = FUN_10005600(local_58 + 0x24,0,local_58[0x28],(ushort *)PTR_u_Auto_Detect_1003a6f4,
                       (int)psVar8 - (int)(PTR_u_Auto_Detect_1003a6f4 + 2) >> 1);
  if (uVar7 == 0) {
    local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
    local_20 = 7;
    local_24 = 0;
    psVar8 = (short *)PTR_DAT_1003a6f0;
    do {
      sVar1 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar1 != 0);
    FUN_10003130(local_34,(int *)PTR_DAT_1003a6f0,(int)psVar8 - (int)(PTR_DAT_1003a6f0 + 2) >> 1);
    local_8._0_1_ = 8;
    FUN_1000bba0(&local_68,(int *)local_34);
    local_8._0_1_ = 7;
    if (7 < local_20) {
      operator_delete(local_34[0]);
    }
    local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
    local_50 = (void *)((uint)local_50._2_2_ << 0x10);
    local_20 = 7;
    local_24 = 0;
    local_3c = 7;
    local_40 = 0;
    psVar8 = (short *)PTR_DAT_1003a6ec;
    do {
      sVar1 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar1 != 0);
    FUN_10003130(&local_50,(int *)PTR_DAT_1003a6ec,(int)psVar8 - (int)(PTR_DAT_1003a6ec + 2) >> 1);
    local_8._0_1_ = 9;
    FUN_1000bba0(&local_68,&local_50);
    local_8._0_1_ = 7;
    uVar3 = (undefined1)local_8;
    if (7 < local_3c) {
      operator_delete(local_50);
      uVar3 = (undefined1)local_8;
    }
  }
  else {
    FUN_1000bba0(&local_68,local_58 + 0x24);
    uVar3 = (undefined1)local_8;
  }
  while ((local_8._0_1_ = uVar3, local_51 == '\0' &&
         (iVar5 = (int)local_64 - (int)local_68 >> 0x1f,
         ((int)local_64 - (int)local_68) / 0x1c + iVar5 != iVar5))) {
    local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
    local_20 = 7;
    local_24 = 0;
    FUN_10003030(local_34,local_64 + -7,0,0xffffffff);
    puVar2 = local_64;
    local_8 = CONCAT31(local_8._1_3_,10);
    if (local_68 != local_64) {
      puVar10 = local_64 + -7;
      if (7 < (uint)local_64[-2]) {
        operator_delete((void *)*puVar10);
      }
      puVar2[-2] = 7;
      puVar2[-3] = 0;
      *(undefined2 *)puVar10 = 0;
      local_64 = local_64 + -7;
    }
    if (param_1 == 0) {
      local_51 = FUN_10007210(local_34);
    }
    else if (param_1 == 1) {
      local_51 = FUN_100076f0(local_34);
    }
    else if (param_1 == 99) {
      local_51 = FUN_1000a750(local_34);
    }
    local_8._0_1_ = 7;
    uVar3 = (undefined1)local_8;
    local_8._0_1_ = 7;
    if (7 < local_20) {
      operator_delete(local_34[0]);
      uVar3 = (undefined1)local_8;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_68 != (undefined4 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_68);
    puVar2 = local_64;
    for (puVar10 = local_68; puVar10 != puVar2; puVar10 = puVar10 + 7) {
      if (7 < (uint)puVar10[5]) {
        operator_delete((void *)*puVar10);
      }
      puVar10[5] = 7;
      puVar10[4] = 0;
      *(undefined2 *)puVar10 = 0;
    }
    operator_delete(local_68);
  }
  FUN_1000c07c();
  return;
}



// Function: Catch@1000c02f at 1000c02f

undefined * Catch_1000c02f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x70),"AutoConfigureManager.cpp",0xdd,
               "CAutoConfigure::ValidateAdapterConfiguration",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  return &DAT_1000c07a;
}



// Function: FUN_1000c07c at 1000c07c

void FUN_1000c07c(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000c094;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1000c09a at 1000c09a

undefined * Catch_All_1000c09a(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10020630((void *)(unaff_EBP + -0x24),"AutoConfigureManager.cpp",0xdd,
               "CAutoConfigure::ValidateAdapterConfiguration",0x692997ca,0x4adcc8fd,0x4050fb8c,
               0xe4de2323);
  uStack0000001c = 0x1000c101;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_1000c07a;
}



// Function: FUN_1000c110 at 1000c110

void __thiscall FUN_1000c110(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = CConnection::vftable;
  *(undefined4 *)((int)this + 0x1c) = 7;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined2 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x38) = 7;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined2 *)((int)this + 0x24) = 0;
  return;
}



// Function: FUN_1000c150 at 1000c150

void __fastcall FUN_1000c150(undefined4 *param_1)

{
  *param_1 = CConnection::vftable;
  if (7 < (uint)param_1[0xe]) {
    operator_delete((void *)param_1[9]);
  }
  param_1[0xe] = 7;
  param_1[0xd] = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  if (7 < (uint)param_1[7]) {
    operator_delete((void *)param_1[2]);
  }
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}



// Function: FUN_1000c1b0 at 1000c1b0

undefined4 * __thiscall FUN_1000c1b0(void *this,byte param_1)

{
  FUN_1000c150((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c1e0 at 1000c1e0

void FUN_1000c1e0(void *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *extraout_EAX_00;
  void *pvVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar7;
  undefined4 uVar8;
  uint uStack_50;
  undefined4 local_30 [4];
  int *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023846;
  local_10 = ExceptionList;
  uStack_50 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_50;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  local_1c = (undefined4 *)&stack0xffffffa4;
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_20 = piVar2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("Connection.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_20 = (int *)&stack0xffffffa0;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffa0,0x1002ac50);
  puVar1 = local_18;
  pvVar6 = *(void **)(*(int *)((int)local_18 + 4) + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  GetCurrentThreadId();
  local_20 = (int *)&stack0xffffffa4;
  local_18 = (undefined4 *)&stack0xffffffa4;
  piVar2 = extraout_ECX_02;
  puVar4 = (undefined4 *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_1c = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
    piVar7 = extraout_ECX_03;
  }
  else {
    puVar4[1] = 0;
    puVar4[2] = 1;
    uVar5 = ConvertStringToBSTR("Connection.cpp");
    *puVar4 = uVar5;
    piVar7 = extraout_ECX_04;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  *local_18 = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_05;
  }
  uVar8 = 4;
  uVar5 = 2;
  local_1c = (undefined4 *)&stack0xffffff98;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff98,0x1002abe8);
  pvVar6 = *(void **)(*(int *)((int)puVar1 + 4) + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar6,piVar7,uVar5,uVar8,piVar2);
  FUN_10012470(local_30,*(undefined4 *)((int)puVar1 + 4));
  local_8._0_1_ = 7;
  FUN_10012fd0(local_30,param_1,(undefined4 *)((int)puVar1 + 8));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100123b0(local_30);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000c36f at 1000c36f

undefined1 * Catch_1000c36f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"Connection.cpp",0x4d,"CConnection::CheckAvailability",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_1000c3b7;
}



// Function: Catch_All@1000c3cb at 1000c3cb

undefined4 Catch_All_1000c3cb(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x3c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x38) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10020630((void *)(unaff_EBP + -0x3c),"Connection.cpp",0x4d,"CConnection::CheckAvailability",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1000c42f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return 0x1000c35b;
}



// Function: FUN_1000c440 at 1000c440

undefined4 FUN_1000c440(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1003aa88 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (7 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1000c490 at 1000c490

void __fastcall FUN_1000c490(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_1000c4a0 at 1000c4a0

void * FUN_1000c4a0(IMAGE_DOS_HEADER *param_1)

{
  void *pvVar1;
  undefined **local_10 [3];
  
  if (param_1 == (IMAGE_DOS_HEADER *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < &IMAGE_DOS_HEADER_10000000) &&
     (pvVar1 = operator_new((int)param_1 << 4), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (IMAGE_DOS_HEADER *)0x0;
  std::exception::exception((exception *)local_10,(char **)&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_1000c500 at 1000c500

int FUN_1000c500(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  iVar2 = param_3;
  puStack_c = &LAB_10023881;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  do {
    if (param_1 == param_2) {
      ExceptionList = local_10;
      return param_3;
    }
    local_8 = 1;
    if (param_3 != 0) {
      Ordinal_8(param_3);
      iVar1 = Ordinal_10(param_3,param_1);
      if (iVar1 < 0) {
        _com_issue_error(iVar1);
        if (iVar2 != param_3) {
          do {
            Ordinal_9(iVar2);
            iVar2 = iVar2 + 0x10;
          } while (iVar2 != param_3);
        }
                    /* WARNING: Subroutine does not return */
        _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
      }
    }
    param_3 = param_3 + 0x10;
    param_1 = param_1 + 0x10;
  } while( true );
}



// Function: FUN_1000c540 at 1000c540

int FUN_1000c540(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  do {
    if (unaff_EDI == *(int *)(unaff_EBP + 0xc)) {
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return unaff_ESI;
    }
    *(int *)(unaff_EBP + 8) = unaff_ESI;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (unaff_ESI != unaff_EBX) {
      Ordinal_8(unaff_ESI);
      iVar2 = Ordinal_10(unaff_ESI,unaff_EDI);
      if (iVar2 < unaff_EBX) {
        _com_issue_error(iVar2);
        iVar1 = *(int *)(unaff_EBP + 0x10);
        for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
          Ordinal_9(iVar2);
        }
                    /* WARNING: Subroutine does not return */
        _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
      }
    }
    unaff_ESI = unaff_ESI + 0x10;
    *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
    *(int *)(unaff_EBP + 0x10) = unaff_ESI;
    unaff_EDI = unaff_EDI + 0x10;
  } while( true );
}



// Function: Catch_All@1000c569 at 1000c569

void Catch_All_1000c569(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
    Ordinal_9(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000c5c0 at 1000c5c0

undefined4 FUN_1000c5c0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100238cb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x44));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x1002ad98);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar3,piVar1);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x44));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000c6bb at 1000c6bb

undefined1 * Catch_1000c6bb(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionCollection.cpp",0xaa,
                       "CConnectionCollection::put_Group",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_1000c709;
}



// Function: Catch_All@1000c728 at 1000c728

undefined1 * Catch_All_1000c728(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"ConnectionCollection.cpp",0xaa,
                       "CConnectionCollection::put_Group",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x1000c791;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_1000c709;
}



// Function: FUN_1000c7a0 at 1000c7a0

void FUN_1000c7a0(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023913;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffb0,0x1002ae20);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(this,piVar3,piVar1);
  iVar2 = FUN_10002db0(&PTR_DAT_1003aa4c,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x10000;
    ExceptionList = local_10;
    return;
  }
  iVar2 = FUN_10002db0(&PTR_DAT_1003a5cc,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x20000;
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000c8c8 at 1000c8c8

undefined * Catch_1000c8c8(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x1c),"ConnectionCollection.cpp",0x7b,
                       "CConnectionCollection::GetIDsOfNames",0x9724030,0x416cda36,0x22972999,
                       0x3171e154);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  return &DAT_1000c913;
}



// Function: Catch_All@1000c92a at 1000c92a

undefined * Catch_All_1000c92a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x2c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x2c),"ConnectionCollection.cpp",0x7b,
                       "CConnectionCollection::GetIDsOfNames",0x9724030,0x416cda36,0x22972999,
                       0x3171e154);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  uStack0000001c = 0x1000c990;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return &DAT_1000c913;
}



// Function: FUN_1000c9a0 at 1000c9a0

void FUN_1000c9a0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  if ((param_2 & 0xffff0000) == 0x10000) {
    if ((DAT_1003aa58 == (int *)0x0) || (DAT_1003aa60 == 0)) {
      FUN_10002550(&PTR_DAT_1003aa4c,param_4);
    }
    if (DAT_1003aa58 != (int *)0x0) {
      (**(code **)(*DAT_1003aa58 + 0x2c))
                (DAT_1003aa58,param_1 + 4,param_2 & 0xffff,param_5,param_6,param_7,param_8,param_9);
    }
  }
  else if ((param_2 & 0xffff0000) == 0x20000) {
    FUN_10003d50(param_1,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  return;
}



// Function: FUN_1000ca50 at 1000ca50

void __fastcall FUN_1000ca50(_Container_base0 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    iVar1 = *(int *)(param_1 + 4);
    for (iVar2 = *(int *)param_1; iVar2 != iVar1; iVar2 = iVar2 + 0x10) {
      Ordinal_9(iVar2);
    }
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000caa0 at 1000caa0

void __thiscall FUN_1000caa0(void *this,IMAGE_DOS_HEADER *param_1)

{
  int iVar1;
  IMAGE_DOS_HEADER *extraout_EAX;
  IMAGE_DOS_HEADER *pIVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pIVar2 = param_1;
  if ((IMAGE_DOS_HEADER *)0xfffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
    pIVar2 = extraout_EAX;
  }
                    /* WARNING: Load size is inaccurate */
  if ((IMAGE_DOS_HEADER *)(*(int *)((int)this + 8) - *this >> 4) < pIVar2) {
    pvVar3 = FUN_1000c4a0(pIVar2);
                    /* WARNING: Load size is inaccurate */
    local_8 = 0;
    FUN_1000c500(*this,*(int *)((int)this + 4),(int)pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    iVar5 = *this;
    uVar4 = iVar1 - iVar5;
    local_8 = 0xffffffff;
    if (iVar5 != 0) {
      for (; iVar5 != iVar1; iVar5 = iVar5 + 0x10) {
        Ordinal_9();
      }
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x10 + (int)pvVar3);
    *(uint *)((int)this + 4) = (uVar4 & 0xfffffff0) + (int)pvVar3;
    *(void **)this = pvVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch_All@1000cb8e at 1000cb8e

void Catch_All_1000cb8e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000cbb0 at 1000cbb0

void FUN_1000cbb0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003aa84);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cc40 at 1000cc40

void FUN_1000cc40(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *piVar4;
  void *extraout_ECX_00;
  void *this;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023983;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x44));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar4 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002b090);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar4,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 5;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x28),300,0x80004003,0x1002b018,L"ConnectionCollection.cpp",
                 (undefined1 *)0xc1,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x44));
  FUN_1000cde8();
  return;
}



// Function: Catch@1000cd8f at 1000cd8f

undefined * Catch_1000cd8f(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionCollection.cpp",0xc5,
                       "CConnectionCollection::get_Group",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_1000cddd;
}



// Function: FUN_1000cde8 at 1000cde8

void FUN_1000cde8(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000ce00;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1000ce06 at 1000ce06

undefined * Catch_All_1000ce06(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionCollection.cpp",0xc5,
                       "CConnectionCollection::get_Group",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x1000ce6f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_1000cddd;
}



// Function: FUN_1000ce80 at 1000ce80

void FUN_1000ce80(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023a0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002b208);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002b188);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if ((param_2 < 0) || (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30) >> 4 < param_2)) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3ea,0x80070057,0x1002b148,L"ConnectionCollection.cpp",
                 (undefined1 *)0xdf,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  if (param_3 == 0) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 9;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002b148,L"ConnectionCollection.cpp",
                 (undefined1 *)0xe8,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  iVar2 = Ordinal_10();
  if (iVar2 < 0) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 10;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3eb,iVar2,0x1002b10c,L"ConnectionCollection.cpp",
                 (undefined1 *)0xf2,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  FUN_1000d18f();
  return;
}



// Function: Catch@1000d136 at 1000d136

undefined * Catch_1000d136(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionCollection.cpp",0xf5,
                       "CConnectionCollection::get_Item",0x9724030,0x416cda36,0x22972999,0x3171e154)
  ;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_1000d184;
}



// Function: FUN_1000d18f at 1000d18f

void FUN_1000d18f(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d1a7;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1000d1ad at 1000d1ad

undefined * Catch_All_1000d1ad(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionCollection.cpp",0xf5,
                       "CConnectionCollection::get_Item",0x9724030,0x416cda36,0x22972999,0x3171e154)
  ;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x1000d216;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_1000d184;
}



// Function: FUN_1000d220 at 1000d220

void FUN_1000d220(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023a8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002b360);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002b32c);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (int *)0x0) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002b2e8,L"ConnectionCollection.cpp",
                 (undefined1 *)0x10e,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  *param_2 = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30) >> 4;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
  FUN_1000d45f();
  return;
}



// Function: Catch@1000d406 at 1000d406

undefined * Catch_1000d406(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionCollection.cpp",0x113,
                       "CConnectionCollection::get_Count",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_1000d454;
}



// Function: FUN_1000d45f at 1000d45f

void FUN_1000d45f(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d477;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1000d47d at 1000d47d

undefined * Catch_All_1000d47d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionCollection.cpp",0x113,
                       "CConnectionCollection::get_Count",0x9724030,0x416cda36,0x22972999,0x3171e154
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x1000d4e6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_1000d454;
}



// Function: FUN_1000d500 at 1000d500

void __thiscall FUN_1000d500(void *this,int *param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != param_3) {
    iVar1 = *(int *)((int)this + 4);
    iVar4 = param_2;
    if (param_3 != iVar1) {
      do {
        iVar3 = Ordinal_10(iVar4,param_3);
        if (iVar3 < 0) {
          _com_issue_error(iVar3);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        param_3 = param_3 + 0x10;
        iVar4 = iVar4 + 0x10;
      } while (param_3 != iVar1);
    }
    iVar1 = *(int *)((int)this + 4);
    for (iVar3 = iVar4; iVar3 != iVar1; iVar3 = iVar3 + 0x10) {
      Ordinal_9(iVar3);
    }
    *(int *)((int)this + 4) = iVar4;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000d570 at 1000d570

void __thiscall FUN_1000d570(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_EAX;
  IMAGE_DOS_HEADER *pIVar3;
  void *extraout_ECX;
  int extraout_EDX;
  IMAGE_DOS_HEADER *pIVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = *(int *)((int)this + 4) - iVar1 >> 4;
  if (0xfffffffU - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
    param_1 = extraout_EDX;
  }
  pIVar3 = (IMAGE_DOS_HEADER *)(uVar2 + param_1);
  pIVar4 = (IMAGE_DOS_HEADER *)(*(int *)((int)this + 8) - iVar1 >> 4);
  if (pIVar4 < pIVar3) {
    if ((IMAGE_DOS_HEADER *)(0xfffffff - ((uint)pIVar4 >> 1)) < pIVar4) {
      pIVar4 = (IMAGE_DOS_HEADER *)0x0;
    }
    else {
      pIVar4 = (IMAGE_DOS_HEADER *)(pIVar4->e_magic + ((uint)pIVar4 >> 1));
    }
    if (pIVar4 < pIVar3) {
      pIVar4 = pIVar3;
    }
    FUN_1000caa0(this,pIVar4);
  }
  return;
}



// Function: FUN_1000d5d0 at 1000d5d0

/* WARNING: Removing unreachable block (ram,0x1000d677) */

int __fastcall FUN_1000d5d0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023ae1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  local_8 = 0;
  FUN_100146d0((undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  ((LPCRITICAL_SECTION)(param_1 + 0x48))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x48),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      FUN_10001070(DVar2);
    }
  }
  *(undefined4 *)(param_1 + 0x60) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000d6a0 at 1000d6a0

void __thiscall FUN_1000d6a0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023b22;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = *(uint *)((int)this + 4);
  if (uVar4 <= param_1) goto LAB_1000d71a;
                    /* WARNING: Load size is inaccurate */
  uVar1 = *this;
  if (param_1 < uVar1) goto LAB_1000d71a;
  if (uVar4 == *(uint *)((int)this + 8)) {
    FUN_1000d570(this,1);
  }
  iVar3 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  param_1 = (param_1 - uVar1 & 0xfffffff0) + *this;
  local_8 = 0;
  while (iVar3 != 0) {
    Ordinal_8(iVar3,uVar2);
    iVar3 = Ordinal_10(iVar3,param_1);
    if (-1 < iVar3) break;
    _com_issue_error(iVar3);
    uVar4 = extraout_EAX;
LAB_1000d71a:
    if (uVar4 == *(uint *)((int)this + 8)) {
      FUN_1000d570(this,1);
    }
    iVar3 = *(int *)((int)this + 4);
    local_8 = 1;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d760 at 1000d760

void __fastcall FUN_1000d760(int param_1)

{
  int *piVar1;
  uint uVar2;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023b77;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 4;
  local_14 = param_1;
  if ((*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38) & 0xfffffff0U) != 0) {
    FUN_1000d500((void *)(param_1 + 0x38),&local_18,*(int *)(param_1 + 0x38),
                 *(int *)(param_1 + 0x3c));
  }
  piVar1 = *(int **)(param_1 + 0x60);
  local_8._0_1_ = 3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  local_8._0_1_ = 1;
  FUN_1000ca50((_Container_base0 *)(param_1 + 0x38));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10014400((int *)(param_1 + 0x2c));
  if (*(char *)(param_1 + 0x28) != '\0') {
    *(undefined1 *)(param_1 + 0x28) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d810 at 1000d810

void FUN_1000d810(void)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_64;
  undefined1 local_54 [20];
  int *local_40;
  int *local_3c;
  int local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023bee;
  local_10 = ExceptionList;
  uStack_64 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_64;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_64;
  GetCurrentThreadId();
  local_40 = (int *)&stack0xffffff90;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_3c = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_3c = (int *)&stack0xffffff8c;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff8c,0x1002b450);
  pvVar5 = *(void **)(local_38 + 0x30);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  local_3c = (int *)&stack0xffffff90;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_40 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionCollection.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_40 = (int *)&stack0xffffff84;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff84,0x1002b3e0);
  pvVar5 = *(void **)(local_38 + 0x30);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  Ordinal_8();
  local_8._0_1_ = 7;
  iVar2 = Ordinal_11();
  if (iVar2 < 0) {
    pwVar3 = (wchar_t *)FUN_1000cbb0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(local_38 + 0x2c),0x3eb,iVar2,0x1002b10c,L"ConnectionCollection.cpp",
                 (undefined1 *)0x12d,pwVar3);
    local_8._0_1_ = 7;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  FUN_1000d6a0((void *)(local_38 + 0x38),(uint)local_54);
  Ordinal_9();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000da0d at 1000da0d

undefined * Catch_1000da0d(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x40),"ConnectionCollection.cpp",0x132,
               "CConnectionCollection::Add",0x993ab1f9,0x4b7e2cb3,0xb86034ad,0xd5745f09);
  return &DAT_1000da58;
}



// Function: Catch_All@1000da5a at 1000da5a

undefined4 Catch_All_1000da5a(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionCollection.cpp",0x132,
               "CConnectionCollection::Add",0x993ab1f9,0x4b7e2cb3,0xb86034ad,0xd5745f09);
  uStack0000001c = 0x1000dac1;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x1000d9ef;
}



// Function: FUN_1000dad0 at 1000dad0

void __thiscall FUN_1000dad0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_1000dae0 at 1000dae0

void FUN_1000dae0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003aa90);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000db70 at 1000db70

void __thiscall FUN_1000db70(void *this,int *param_1,int *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023c71;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff80,0x1002b5b0);
                    /* WARNING: Load size is inaccurate */
  pvVar5 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar8,piVar3);
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff78,0x1002b560);
                    /* WARNING: Load size is inaccurate */
  pvVar5 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar8,uVar9,uVar10,piVar3);
  pvVar5 = operator_new(0x7c);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    puVar6 = FUN_10018580(pvVar5,*this,param_1,param_2);
  }
  local_8._0_1_ = 0;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 0;
  if (puVar6 == (undefined4 *)0x0) {
    pwVar7 = (wchar_t *)FUN_1000dae0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar7 + 10)) {
      pwVar7 = *(wchar_t **)pwVar7;
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10015000(*this,0x41b,0x80004005,0x1002b4d8,L"ConnectionFactory.cpp",(undefined1 *)0x51,
                 pwVar7);
    uVar1 = (undefined1)local_8;
    if (7 < local_20) {
      operator_delete(local_34);
      uVar1 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar1;
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000dd74 at 1000dd74

undefined * Catch_1000dd74(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x5c),"ConnectionFactory.cpp",0x54,
               "CConnectionFactory::CreateRP1210Connection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1000ddbc;
}



// Function: Catch_All@1000ddbe at 1000ddbe

undefined4 Catch_All_1000ddbe(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x58) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10020630((void *)(unaff_EBP + -0x58),"ConnectionFactory.cpp",0x54,
               "CConnectionFactory::CreateRP1210Connection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000de22;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x58));
  return 0x1000dd53;
}



// Function: FUN_1000de30 at 1000de30

void __fastcall FUN_1000de30(int *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023cf1;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002b7e8);
  pvVar5 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar8,piVar3);
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002b798);
  pvVar5 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar8,uVar9,uVar10,piVar3);
  pvVar5 = operator_new(0x44);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = FUN_10013fc0(pvVar5,*param_1);
  }
  local_8._0_1_ = 0;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 0;
  if (puVar6 == (undefined4 *)0x0) {
    pwVar7 = (wchar_t *)FUN_1000dae0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar7 + 10)) {
      pwVar7 = *(wchar_t **)pwVar7;
    }
    FUN_10015000((void *)*param_1,0x41c,0x80004005,0x1002b738,L"ConnectionFactory.cpp",
                 (undefined1 *)0x70,pwVar7);
    uVar1 = (undefined1)local_8;
    if (7 < local_20) {
      operator_delete(local_34);
      uVar1 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar1;
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000e01e at 1000e01e

undefined * Catch_1000e01e(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionFactory.cpp",0x73,
               "CConnectionFactory::CreateINLINEIIConnection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1000e066;
}



// Function: Catch_All@1000e068 at 1000e068

undefined4 Catch_All_1000e068(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionFactory.cpp",0x73,
               "CConnectionFactory::CreateINLINEIIConnection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000e0cc;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x1000dfff;
}



// Function: FUN_1000e0e0 at 1000e0e0

void __fastcall FUN_1000e0e0(int *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023d71;
  local_10 = ExceptionList;
  uVar2 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002b878);
  pvVar5 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar8,piVar3);
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("ConnectionFactory.cpp");
    *piVar3 = iVar4;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002b798);
  pvVar5 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar8,uVar9,uVar10,piVar3);
  pvVar5 = operator_new(0x44);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = FUN_10013790(pvVar5,*param_1);
  }
  local_8._0_1_ = 0;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 0;
  if (puVar6 == (undefined4 *)0x0) {
    pwVar7 = (wchar_t *)FUN_1000dae0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar7 + 10)) {
      pwVar7 = *(wchar_t **)pwVar7;
    }
    FUN_10015000((void *)*param_1,0x41c,0x80004005,0x1002b738,L"ConnectionFactory.cpp",
                 (undefined1 *)0x8f,pwVar7);
    uVar1 = (undefined1)local_8;
    if (7 < local_20) {
      operator_delete(local_34);
      uVar1 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar1;
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000e2d7 at 1000e2d7

undefined * Catch_1000e2d7(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionFactory.cpp",0x92,
               "CConnectionFactory::CreateINLINEConnection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1000e322;
}



// Function: Catch_All@1000e324 at 1000e324

undefined4 Catch_All_1000e324(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionFactory.cpp",0x92,
               "CConnectionFactory::CreateINLINEConnection",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1000e38b;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x1000e2b8;
}



// Function: FUN_1000e3a0 at 1000e3a0

undefined4 FUN_1000e3a0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1003aa98 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (7 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1000e3f0 at 1000e3f0

/* WARNING: Removing unreachable block (ram,0x1000e51e) */

int __fastcall FUN_1000e3f0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023e1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  local_8 = 0;
  FUN_100146d0((undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x4c) = 7;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined2 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x68) = 7;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined2 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x84) = 7;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined2 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 7;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 7;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined2 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 7;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined2 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 7;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined2 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0x114) = 7;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined2 *)(param_1 + 0x100) = 0;
  ((LPCRITICAL_SECTION)(param_1 + 0x11c))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  local_8 = CONCAT31(local_8._1_3_,9);
  *(undefined4 *)(param_1 + 0x130) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x11c),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      FUN_10001070(DVar2);
    }
  }
  *(undefined4 *)(param_1 + 0x134) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e540 at 1000e540

void __fastcall FUN_1000e540(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023e4b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)(param_1 + 0x134);
  local_8 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11c));
  if (7 < *(uint *)(param_1 + 0x114)) {
    operator_delete(*(void **)(param_1 + 0x100));
  }
  *(undefined4 *)(param_1 + 0x114) = 7;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined2 *)(param_1 + 0x100) = 0;
  if (7 < *(uint *)(param_1 + 0xf8)) {
    operator_delete(*(void **)(param_1 + 0xe4));
  }
  *(undefined4 *)(param_1 + 0xf8) = 7;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined2 *)(param_1 + 0xe4) = 0;
  if (7 < *(uint *)(param_1 + 0xdc)) {
    operator_delete(*(void **)(param_1 + 200));
  }
  *(undefined4 *)(param_1 + 0xdc) = 7;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined2 *)(param_1 + 200) = 0;
  if (7 < *(uint *)(param_1 + 0xbc)) {
    operator_delete(*(void **)(param_1 + 0xa8));
  }
  *(undefined4 *)(param_1 + 0xbc) = 7;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined2 *)(param_1 + 0xa8) = 0;
  if (7 < *(uint *)(param_1 + 0xa0)) {
    operator_delete(*(void **)(param_1 + 0x8c));
  }
  *(undefined4 *)(param_1 + 0xa0) = 7;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)(param_1 + 0x8c) = 0;
  if (7 < *(uint *)(param_1 + 0x84)) {
    operator_delete(*(void **)(param_1 + 0x70));
  }
  *(undefined4 *)(param_1 + 0x84) = 7;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined2 *)(param_1 + 0x70) = 0;
  if (7 < *(uint *)(param_1 + 0x68)) {
    operator_delete(*(void **)(param_1 + 0x54));
  }
  *(undefined4 *)(param_1 + 0x68) = 7;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined2 *)(param_1 + 0x54) = 0;
  if (7 < *(uint *)(param_1 + 0x4c)) {
    operator_delete(*(void **)(param_1 + 0x38));
  }
  *(undefined4 *)(param_1 + 0x4c) = 7;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined2 *)(param_1 + 0x38) = 0;
  FUN_10014400((int *)(param_1 + 0x2c));
  if (*(char *)(param_1 + 0x28) != '\0') {
    *(undefined1 *)(param_1 + 0x28) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e710 at 1000e710

undefined4 FUN_1000e710(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023e9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x118));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa4,0x1002b8f8);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002f20(this,piVar3,piVar1);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x118));
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000e80d at 1000e80d

undefined1 * Catch_1000e80d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0xa5,
                       "CConnectionProperties::put_Group",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  return &LAB_1000e85b;
}



// Function: Catch_All@1000e87a at 1000e87a

undefined1 * Catch_All_1000e87a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x38) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x38),"ConnectionProperties.cpp",0xa5,
                       "CConnectionProperties::put_Group",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uStack0000001c = 0x1000e8e3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &LAB_1000e85b;
}



// Function: FUN_1000e8f0 at 1000e8f0

void __thiscall FUN_1000e8f0(void *this,undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023efe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002ba00);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002b988);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  *(undefined4 *)((int)this + 0xc4) = *param_1;
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000ea5a at 1000ea5a

undefined1 * Catch_1000ea5a(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x265,
               "CConnectionProperties::SetConnectionState",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  return &LAB_1000eaa5;
}



// Function: Catch_All@1000eab9 at 1000eab9

undefined4 Catch_All_1000eab9(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x265,
               "CConnectionProperties::SetConnectionState",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  uStack0000001c = 0x1000eb20;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000ea46;
}



// Function: FUN_1000eb30 at 1000eb30

int * __thiscall FUN_1000eb30(void *this,undefined2 param_1)

{
  undefined2 *puVar1;
  
  if (*(int *)((int)this + 0x14) == 0) {
    FUN_100022b0(this,1);
  }
  puVar1 = (undefined2 *)this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    puVar1 = *this;
  }
  *puVar1 = param_1;
  *(undefined4 *)((int)this + 0x10) = 1;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + 2) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(*this + 2) = 0;
  return (int *)this;
}



// Function: FUN_1000eb90 at 1000eb90

void FUN_1000eb90(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *extraout_ECX_02;
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023f43;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffb0,0x1002bad8);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_02;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(this,piVar3,piVar1);
  iVar2 = FUN_10002db0(&PTR_DAT_1003aa30,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x10000;
    ExceptionList = local_10;
    return;
  }
  iVar2 = FUN_10002db0(&PTR_DAT_1003a5cc,param_2,param_3,param_4,param_5,param_6);
  if (-1 < iVar2) {
    *param_6 = *param_6 | 0x20000;
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000ecb8 at 1000ecb8

undefined * Catch_1000ecb8(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x1c),"ConnectionProperties.cpp",0x76,
                       "CConnectionProperties::GetIDsOfNames",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  return &DAT_1000ed03;
}



// Function: Catch_All@1000ed1a at 1000ed1a

undefined * Catch_All_1000ed1a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x2c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x28) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x2c),"ConnectionProperties.cpp",0x76,
                       "CConnectionProperties::GetIDsOfNames",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  uStack0000001c = 0x1000ed80;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return &DAT_1000ed03;
}



// Function: FUN_1000ed90 at 1000ed90

void FUN_1000ed90(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  if ((param_2 & 0xffff0000) == 0x10000) {
    if ((DAT_1003aa3c == (int *)0x0) || (DAT_1003aa44 == 0)) {
      FUN_10002550(&PTR_DAT_1003aa30,param_4);
    }
    if (DAT_1003aa3c != (int *)0x0) {
      (**(code **)(*DAT_1003aa3c + 0x2c))
                (DAT_1003aa3c,param_1 + 4,param_2 & 0xffff,param_5,param_6,param_7,param_8,param_9);
    }
  }
  else if ((param_2 & 0xffff0000) == 0x20000) {
    FUN_10003d50(param_1,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return;
  }
  return;
}



// Function: FUN_1000ee40 at 1000ee40

void __thiscall FUN_1000ee40(void *this,void *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023f9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002bcf0);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002bcd0);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030(param_1,(int *)((int)this + 0xa8),0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000efb1 at 1000efb1

undefined1 * Catch_1000efb1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",500,
               "CConnectionProperties::GetProtocol",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000effc;
}



// Function: Catch_All@1000f010 at 1000f010

undefined4 Catch_All_1000f010(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",500,
               "CConnectionProperties::GetProtocol",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x1000f077;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000ef9d;
}



// Function: FUN_1000f080 at 1000f080

void __thiscall FUN_1000f080(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023ffe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002bdd0);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002bd88);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0x38),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000f1ee at 1000f1ee

undefined1 * Catch_1000f1ee(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x206,
               "CConnectionProperties::SetVendor",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000f239;
}



// Function: Catch_All@1000f24d at 1000f24d

undefined4 Catch_All_1000f24d(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x206,
               "CConnectionProperties::SetVendor",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x1000f2b4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000f1da;
}



// Function: FUN_1000f2c0 at 1000f2c0

void __thiscall FUN_1000f2c0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002405e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002be98);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002be70);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0x54),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000f42e at 1000f42e

undefined1 * Catch_1000f42e(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x219,
               "CConnectionProperties::SetDeviceType",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000f479;
}



// Function: Catch_All@1000f48d at 1000f48d

undefined4 Catch_All_1000f48d(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x219,
               "CConnectionProperties::SetDeviceType",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x1000f4f4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000f41a;
}



// Function: FUN_1000f500 at 1000f500

void __thiscall FUN_1000f500(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100240be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002bf80);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002bf4c);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0x70),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000f66e at 1000f66e

undefined1 * Catch_1000f66e(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x22c,
               "CConnectionProperties::SetDeviceDescription",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  return &LAB_1000f6b9;
}



// Function: Catch_All@1000f6cd at 1000f6cd

undefined4 Catch_All_1000f6cd(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x22c,
               "CConnectionProperties::SetDeviceDescription",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  uStack0000001c = 0x1000f734;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000f65a;
}



// Function: FUN_1000f740 at 1000f740

void __thiscall FUN_1000f740(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002411e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002c068);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002c044);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0x8c),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000f8b1 at 1000f8b1

undefined1 * Catch_1000f8b1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x23f,
               "CConnectionProperties::SetPortW",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000f8fc;
}



// Function: Catch_All@1000f910 at 1000f910

undefined4 Catch_All_1000f910(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x23f,
               "CConnectionProperties::SetPortW",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x1000f977;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000f89d;
}



// Function: FUN_1000f980 at 1000f980

void __thiscall FUN_1000f980(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002417e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002c118);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002c0fc);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0xa8),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000faf1 at 1000faf1

undefined1 * Catch_1000faf1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x252,
               "CConnectionProperties::SetProtocol",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000fb3c;
}



// Function: Catch_All@1000fb50 at 1000fb50

undefined4 Catch_All_1000fb50(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x252,
               "CConnectionProperties::SetProtocol",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x1000fbb7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000fadd;
}



// Function: FUN_1000fbc0 at 1000fbc0

void __thiscall FUN_1000fbc0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100241de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002c260);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002c1c8);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 200),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000fd31 at 1000fd31

undefined1 * Catch_1000fd31(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x278,
               "CConnectionProperties::SetConnectionDescription",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  return &LAB_1000fd7c;
}



// Function: Catch_All@1000fd90 at 1000fd90

undefined4 Catch_All_1000fd90(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x278,
               "CConnectionProperties::SetConnectionDescription",0x398e65ba,0x42ca4788,0x527d4183,
               0xf59a9cc4);
  uStack0000001c = 0x1000fdf7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000fd1d;
}



// Function: FUN_1000fe20 at 1000fe20

void __thiscall FUN_1000fe20(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002423e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002c358);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002c338);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0xe4),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000ff91 at 1000ff91

undefined1 * Catch_1000ff91(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x28b,
               "CConnectionProperties::SetDeviceID",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &LAB_1000ffdc;
}



// Function: Catch_All@1000fff0 at 1000fff0

undefined4 Catch_All_1000fff0(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x28b,
               "CConnectionProperties::SetDeviceID",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x10010057;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1000ff7d;
}



// Function: FUN_10010060 at 10010060

void __thiscall FUN_10010060(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar3;
  void *extraout_ECX_06;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002429e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002c440);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar3,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_05;
  }
  uVar6 = 4;
  uVar5 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002c414);
  pvVar4 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_ECX_06;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar3,uVar5,uVar6,piVar1);
  FUN_10003030((void *)((int)this + 0x100),param_1,0,0xffffffff);
  ExceptionList = local_10;
  return;
}



// Function: Catch@100101d1 at 100101d1

undefined1 * Catch_100101d1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"ConnectionProperties.cpp",0x29e,
               "CConnectionProperties::SetVendorSpecificRP1210INIFileName",0x398e65ba,0x42ca4788,
               0x527d4183,0xf59a9cc4);
  return &LAB_1001021c;
}



// Function: Catch_All@10010230 at 10010230

undefined4 Catch_All_10010230(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"ConnectionProperties.cpp",0x29e,
               "CConnectionProperties::SetVendorSpecificRP1210INIFileName",0x398e65ba,0x42ca4788,
               0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x10010297;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x100101bd;
}



// Function: FUN_100102a0 at 100102a0

void FUN_100102a0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003aa94);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010330 at 10010330

void FUN_10010330(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *piVar4;
  void *extraout_ECX_00;
  void *this;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100242f3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x118));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar4 = (int *)&stack0xffffff94;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002c568);
  this = *(void **)(param_1 + 0x2c);
  local_8._0_1_ = 4;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(this,piVar4,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 5;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x28),0x3e9,0x80004003,0x1002c4f0,L"ConnectionProperties.cpp",
                 (undefined1 *)0xbc,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x118));
  FUN_100104db();
  return;
}



// Function: Catch@10010482 at 10010482

undefined * Catch_10010482(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0xc0,
                       "CConnectionProperties::get_Group",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_100104d0;
}



// Function: FUN_100104db at 100104db

void FUN_100104db(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100104f3;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@100104f9 at 100104f9

undefined * Catch_All_100104f9(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0xc0,
                       "CConnectionProperties::get_Group",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10010562;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_100104d0;
}



// Function: FUN_10010570 at 10010570

void FUN_10010570(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002436e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002c650);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002c62c);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002c5e8,L"ConnectionProperties.cpp",
                 (undefined1 *)0xd9,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0x30));
  *param_2 = uVar6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_100107bc();
  return;
}



// Function: Catch@10010763 at 10010763

undefined * Catch_10010763(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0xdd,
                       "CConnectionProperties::get_Vendor",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_100107b1;
}



// Function: FUN_100107bc at 100107bc

void FUN_100107bc(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100107d4;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@100107da at 100107da

undefined * Catch_All_100107da(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0xdd,
                       "CConnectionProperties::get_Vendor",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10010843;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_100107b1;
}



// Function: FUN_10010850 at 10010850

void FUN_10010850(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100243ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002c758);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002c734);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002c6e8,L"ConnectionProperties.cpp",
                 (undefined1 *)0xf6,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0x4c));
  *param_2 = uVar6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_10010a9c();
  return;
}



// Function: Catch@10010a43 at 10010a43

undefined * Catch_10010a43(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0xfb,
                       "CConnectionProperties::get_DeviceType",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10010a91;
}



// Function: FUN_10010a9c at 10010a9c

void FUN_10010a9c(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10010ab4;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10010aba at 10010aba

undefined * Catch_All_10010aba(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0xfb,
                       "CConnectionProperties::get_DeviceType",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10010b23;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10010a91;
}



// Function: FUN_10010b30 at 10010b30

void FUN_10010b30(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002446e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002c898);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002c864);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002c808,L"ConnectionProperties.cpp",
                 (undefined1 *)0x117,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0x68));
  *param_2 = uVar6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_10010d7c();
  return;
}



// Function: Catch@10010d23 at 10010d23

undefined * Catch_10010d23(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0x11b,
                       "CConnectionProperties::get_DeviceDescription",0x62ab33e7,0x435fb57c,
                       0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10010d71;
}



// Function: FUN_10010d7c at 10010d7c

void FUN_10010d7c(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10010d94;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10010d9a at 10010d9a

undefined * Catch_All_10010d9a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0x11b,
                       "CConnectionProperties::get_DeviceDescription",0x62ab33e7,0x435fb57c,
                       0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10010e03;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10010d71;
}



// Function: FUN_10010e20 at 10010e20

void FUN_10010e20(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100244ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002c9c8);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002c990);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002c950,L"ConnectionProperties.cpp",
                 (undefined1 *)0x135,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0x84));
  *param_2 = uVar6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_1001106e();
  return;
}



// Function: Catch@10011015 at 10011015

undefined * Catch_10011015(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0x139,
                       "CConnectionProperties::get_Port",0x62ab33e7,0x435fb57c,0x403ce995,0xf6f3dbed
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10011063;
}



// Function: FUN_1001106e at 1001106e

void FUN_1001106e(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011086;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1001108c at 1001108c

undefined * Catch_All_1001108c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0x139,
                       "CConnectionProperties::get_Port",0x62ab33e7,0x435fb57c,0x403ce995,0xf6f3dbed
                      );
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x100110f5;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10011063;
}



// Function: FUN_10011100 at 10011100

void FUN_10011100(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002456e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002cae0);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002ca98);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002ca50,L"ConnectionProperties.cpp",
                 (undefined1 *)0x152,pwVar3);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0xa0));
  *param_2 = uVar6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_1001134e();
  return;
}



// Function: Catch@100112f5 at 100112f5

undefined * Catch_100112f5(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0x156,
                       "CConnectionProperties::get_Protocol",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10011343;
}



// Function: FUN_1001134e at 1001134e

void FUN_1001134e(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011366;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1001136c at 1001136c

undefined * Catch_All_1001136c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0x156,
                       "CConnectionProperties::get_Protocol",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x100113d5;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10011343;
}



// Function: FUN_100113e0 at 100113e0

void FUN_100113e0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100245ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffff90,0x1002cbe8);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffff88,0x1002cbbc);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 8;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002cb78,L"ConnectionProperties.cpp",
                 (undefined1 *)0x171,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0xbc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x114));
  FUN_1001161e();
  return;
}



// Function: Catch@100115c5 at 100115c5

undefined * Catch_100115c5(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x4c),"ConnectionProperties.cpp",0x175,
                       "CConnectionProperties::get_State",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10011613;
}



// Function: FUN_1001161e at 1001161e

void FUN_1001161e(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011636;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@1001163c at 1001163c

undefined * Catch_All_1001163c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0x175,
                       "CConnectionProperties::get_State",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x100116a5;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return &DAT_10011613;
}



// Function: FUN_100116b0 at 100116b0

void FUN_100116b0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024666;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002cd60);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002cd20);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002ccb8,L"ConnectionProperties.cpp",
                 (undefined1 *)0x18e,pwVar3);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0xc0));
  *param_2 = uVar6;
  FUN_100118cc();
  return;
}



// Function: Catch@1001187b at 1001187b

undefined * Catch_1001187b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionProperties.cpp",0x192,
                       "CConnectionProperties::get_ConfigurationDescription",0x62ab33e7,0x435fb57c,
                       0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_100118c9;
}



// Function: FUN_100118cc at 100118cc

void FUN_100118cc(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100118e4;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@100118ea at 100118ea

undefined * Catch_All_100118ea(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionProperties.cpp",0x192,
                       "CConnectionProperties::get_ConfigurationDescription",0x62ab33e7,0x435fb57c,
                       0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10011953;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return &DAT_100118c9;
}



// Function: FUN_10011960 at 10011960

void FUN_10011960(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100246d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002ce98);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002ce78);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002ce30,L"ConnectionProperties.cpp",
                 (undefined1 *)0x1ab,pwVar3);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0xdc));
  *param_2 = uVar6;
  FUN_10011b7c();
  return;
}



// Function: Catch@10011b2b at 10011b2b

undefined * Catch_10011b2b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionProperties.cpp",0x1af,
                       "CConnectionProperties::get_DeviceID",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10011b79;
}



// Function: FUN_10011b7c at 10011b7c

void FUN_10011b7c(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011b94;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10011b9a at 10011b9a

undefined * Catch_All_10011b9a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionProperties.cpp",0x1af,
                       "CConnectionProperties::get_DeviceID",0x62ab33e7,0x435fb57c,0x403ce995,
                       0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10011c03;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return &DAT_10011b79;
}



// Function: FUN_10011c10 at 10011c10

void FUN_10011c10(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024746;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002cfc0);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002cf98);
  pvVar5 = *(void **)(param_1 + 0x28);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  if (param_2 == (undefined4 *)0x0) {
    pwVar3 = (wchar_t *)FUN_100102a0();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000((void *)(param_1 + 0x24),0x3e9,0x80004003,0x1002cf48,L"ConnectionProperties.cpp",
                 (undefined1 *)0x1c8,pwVar3);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  uVar6 = FUN_1001f330((undefined4 *)(param_1 + 0xf8));
  *param_2 = uVar6;
  FUN_10011e2c();
  return;
}



// Function: Catch@10011ddb at 10011ddb

undefined * Catch_10011ddb(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionProperties.cpp",0x1cc,
                       "CConnectionProperties::get_VendorSpecificRP1210INIFileName",0x62ab33e7,
                       0x435fb57c,0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  return &DAT_10011e29;
}



// Function: FUN_10011e2c at 10011e2c

void FUN_10011e2c(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011e44;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch_All@10011e4a at 10011e4a

undefined * Catch_All_10011e4a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  uVar1 = FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionProperties.cpp",0x1cc,
                       "CConnectionProperties::get_VendorSpecificRP1210INIFileName",0x62ab33e7,
                       0x435fb57c,0x403ce995,0xf6f3dbed);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  uStack0000001c = 0x10011eb3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return &DAT_10011e29;
}



// Function: FUN_10011ed0 at 10011ed0

undefined2 * __thiscall FUN_10011ed0(void *this,undefined2 *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 *this_00;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100247c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_8 = 1;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xffffffa8,0x1002d0b8);
  pvVar5 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 4;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 0;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xffffffa0,0x1002d070);
  pvVar5 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 7;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  this_00 = (undefined4 *)((int)this + 0x8c);
  uVar3 = FUN_10005600(this_00,0,*(uint *)((int)this + 0x9c),(ushort *)&DAT_1002d068,3);
  if (uVar3 != 0xffffffff) {
    if (7 < *(uint *)((int)this + 0xa0)) {
      this_00 = (undefined4 *)*this_00;
    }
    FUN_1000eb30(param_1,*(undefined2 *)((int)this_00 + *(int *)((int)this + 0x9c) * 2 + -2));
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: Catch@1001208f at 1001208f

undefined * Catch_1001208f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x24),"ConnectionProperties.cpp",0x2b7,
               "CConnectionProperties::parsePortNumber",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4)
  ;
  return &DAT_100120da;
}



// Function: Catch_All@100120dc at 100120dc

undefined4 Catch_All_100120dc(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x34) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10020630((void *)(unaff_EBP + -0x34),"ConnectionProperties.cpp",0x2b7,
               "CConnectionProperties::parsePortNumber",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4)
  ;
  uStack0000001c = 0x10012143;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return 0x10012078;
}



// Function: FUN_10012150 at 10012150

void __thiscall FUN_10012150(void *this,void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar4;
  void *extraout_ECX_06;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_68;
  void *local_34 [5];
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024836;
  local_10 = ExceptionList;
  uStack_68 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_68;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_68;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002d158);
  pvVar5 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_02;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_03;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("ConnectionProperties.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_04;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_05;
  }
  uVar7 = 4;
  uVar6 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002d134);
  pvVar5 = *(void **)((int)this + 0x30);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar4,uVar6,uVar7,piVar1);
  puVar3 = (undefined4 *)FUN_10011ed0(this,(undefined2 *)local_34);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10004710(param_1,puVar3);
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100122ec at 100122ec

undefined * Catch_100122ec(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"ConnectionProperties.cpp",0x1e1,
               "CConnectionProperties::GetPortNumber",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  return &DAT_10012337;
}



// Function: Catch_All@10012339 at 10012339

undefined4 Catch_All_10012339(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10020630((void *)(unaff_EBP + -0x50),"ConnectionProperties.cpp",0x1e1,
               "CConnectionProperties::GetPortNumber",0x398e65ba,0x42ca4788,0x527d4183,0xf59a9cc4);
  uStack0000001c = 0x100123a0;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x100122ce;
}



// Function: FUN_100123b0 at 100123b0

void __fastcall FUN_100123b0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CDeviceControlWrapper::vftable;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100123d0 at 100123d0

HRESULT __thiscall FUN_100123d0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_1002d1d4,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028450,&param_2);
    if (HVar2 < 0) goto LAB_10012454;
    HVar2 = OleRun(param_2);
    if (-1 < HVar2) {
      HVar2 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1002d1d4,(void **)this);
    }
    (*param_2->lpVtbl->Release)(param_2);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10012454:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10012470 at 10012470

void __thiscall FUN_10012470(void *this,undefined4 param_1)

{
  *(undefined ***)this = CDeviceControlWrapper::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_1;
  return;
}



// Function: FUN_10012490 at 10012490

undefined4 * __thiscall FUN_10012490(void *this,byte param_1)

{
  int *piVar1;
  
  *(undefined ***)this = CDeviceControlWrapper::vftable;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100124d0 at 100124d0

undefined4 * __thiscall FUN_100124d0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002486b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  if (*(int *)((int)this + 8) != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0x14))
              (*(int **)((int)this + 8),&local_14,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  }
  uVar1 = local_14;
  puVar2 = (undefined4 *)operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0;
    puVar2[2] = 1;
    *puVar2 = uVar1;
  }
  local_8 = 0xffffffff;
  *param_1 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10012570 at 10012570

ULONG __thiscall FUN_10012570(void *this,int *param_1)

{
  int iVar1;
  ULONG UVar2;
  LONG LVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024898;
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
  UVar2 = (**(code **)(*this + 0x28))(this,iVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if ((int)UVar2 < 0) {
    _com_issue_errorex(UVar2,(IUnknown *)this,(_GUID *)&DAT_1002d1e4);
  }
  if (param_1 != (int *)0x0) {
    LVar3 = InterlockedDecrement(param_1 + 2);
    if ((LVar3 == 0) && (param_1 != (int *)0x0)) {
      if (*param_1 != 0) {
        Ordinal_6(*param_1);
      }
      if ((void *)param_1[1] != (void *)0x0) {
        operator_delete__((void *)param_1[1]);
      }
      operator_delete(param_1);
    }
  }
  ExceptionList = local_10;
  return UVar2;
}



// Function: FUN_10012620 at 10012620

void FUN_10012620(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003aaa0);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100126b0 at 100126b0

void __fastcall FUN_100126b0(int param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *this;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  uint uStack_54;
  int *local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100248fb;
  local_10 = ExceptionList;
  uStack_54 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_54;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("DeviceControlWrapper.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff9c,0x1002d2f8);
  this = *(void **)(*(int *)(param_1 + 8) + 4);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(this,piVar4,piVar1);
  local_38 = (int *)0x0;
  local_8._0_1_ = 4;
  iVar2 = FUN_10021340(&local_38,4);
  if (iVar2 < 0) {
    pwVar3 = (wchar_t *)FUN_10012620();
    local_8._0_1_ = 5;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000(*(void **)(param_1 + 8),0x411,0x80004005,0x1002d250,L"DeviceControlWrapper.cpp",
                 (undefined1 *)0xc1,pwVar3);
    local_8._0_1_ = 4;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 8))();
  }
  *(undefined4 *)(param_1 + 4) = 0;
  iVar2 = (**(code **)*local_38)();
  if (iVar2 < 0) {
    pwVar3 = (wchar_t *)FUN_10012620();
    local_8._0_1_ = 6;
    if (7 < *(uint *)(pwVar3 + 10)) {
      pwVar3 = *(wchar_t **)pwVar3;
    }
    FUN_10015000(*(void **)(param_1 + 8),0x411,0x80004005,0x1002d250,L"DeviceControlWrapper.cpp",
                 (undefined1 *)0xc9,pwVar3);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  ExceptionList = local_10;
  uStack_54 = 0x1001289b;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001289f at 1001289f

undefined * Catch_1001289f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x3c),"DeviceControlWrapper.cpp",0xcc,
               "CDeviceControlWrapper::createInstanceOfDCLDeviceComponent",0x3ed7ac9c,0x46d59d92,
               0x81b10189,0x696e973b);
  return &DAT_100128ea;
}



// Function: Catch_All@100128ec at 100128ec

undefined4 Catch_All_100128ec(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x24),"DeviceControlWrapper.cpp",0xcc,
               "CDeviceControlWrapper::createInstanceOfDCLDeviceComponent",0x3ed7ac9c,0x46d59d92,
               0x81b10189,0x696e973b);
  uStack0000001c = 0x10012953;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x10012883;
}



// Function: FUN_10012960 at 10012960

void __thiscall FUN_10012960(void *this,void *param_1)

{
  HRESULT HVar1;
  wchar_t *pwVar2;
  uint uStack_58;
  void *local_44;
  uint local_30;
  CLSID local_28;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024930;
  local_10 = ExceptionList;
  uStack_58 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_58;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_58;
  HVar1 = CLSIDFromProgID(L"Cummins.CPPReadRequest.1",&local_28);
  if (-1 < HVar1) {
    HVar1 = FUN_100123d0(param_1,&local_28,(LPUNKNOWN)0x0,0x17);
    if (-1 < HVar1) goto LAB_10012a11;
  }
  pwVar2 = (wchar_t *)FUN_10012620();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < *(uint *)(pwVar2 + 10)) {
    pwVar2 = *(wchar_t **)pwVar2;
  }
  FUN_10015000(*(void **)((int)this + 8),0x44d,0x80004005,0x1002d3c0,L"DeviceControlWrapper.cpp",
               (undefined1 *)0x13a,pwVar2);
  if (7 < local_30) {
    operator_delete(local_44);
  }
LAB_10012a11:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10012a2f at 10012a2f

undefined * Catch_10012a2f(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x44),"DeviceControlWrapper.cpp",0x13d,
               "CDeviceControlWrapper::createInstanceOfCCPRequest",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_10012a7a;
}



// Function: Catch_All@10012a7c at 10012a7c

undefined4 Catch_All_10012a7c(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10020630((void *)(unaff_EBP + -0x24),"DeviceControlWrapper.cpp",0x13d,
               "CDeviceControlWrapper::createInstanceOfCCPRequest",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x10012ae3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x10012a11;
}



// Function: FUN_10012af0 at 10012af0

void FUN_10012af0(undefined4 param_1,ulong param_2,int *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  void *this;
  IUnknownVtbl *pIVar1;
  _func_5021 *p_Var2;
  void *extraout_EAX;
  void *this_00;
  IUnknown *extraout_EAX_00;
  IUnknown *extraout_EAX_01;
  ULONG UVar3;
  IUnknown *extraout_EAX_02;
  IUnknown *extraout_EAX_03;
  HRESULT HVar4;
  IUnknown *extraout_EAX_04;
  IUnknown *extraout_EAX_05;
  IUnknown *extraout_EAX_06;
  int iVar5;
  int extraout_EAX_07;
  int *extraout_EAX_08;
  int *piVar6;
  IUnknown *extraout_EAX_09;
  IUnknown *pIVar7;
  wchar_t *pwVar8;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  IUnknown *extraout_EDX;
  IUnknown IVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int **ppiVar13;
  uint uStack_80;
  int *local_5c;
  IUnknownVtbl *local_58;
  void *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined1 local_40 [4];
  int *local_3c;
  IUnknown *local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002499b;
  local_10 = ExceptionList;
  uStack_80 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_80;
  ExceptionList = &local_10;
  local_40 = (undefined1  [4])param_2;
  local_3c = param_3;
  local_18 = uStack_80;
  GetCurrentThreadId();
  local_38 = (IUnknown *)&stack0xffffff74;
  pIVar1 = (IUnknownVtbl *)operator_new(0xc);
  local_8 = 0;
  local_58 = pIVar1;
  if (pIVar1 == (IUnknownVtbl *)0x0) {
    IVar9.lpVtbl = (IUnknownVtbl *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    pIVar1->AddRef = (_func_5022 *)0x0;
    pIVar1->Release = (_func_5023 *)0x1;
    p_Var2 = (_func_5021 *)ConvertStringToBSTR("DeviceControlWrapper.cpp");
    pIVar1->QueryInterface = p_Var2;
    piVar6 = extraout_ECX_00;
    IVar9.lpVtbl = pIVar1;
  }
  local_8 = 0xffffffff;
  if (IVar9.lpVtbl == (IUnknownVtbl *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_58 = (IUnknownVtbl *)&stack0xffffff70;
  local_8 = 1;
  FUN_10001f10(&stack0xffffff70,0x1002d488);
  this = local_54;
  this_00 = *(void **)(*(int *)((int)local_54 + 8) + 4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_EAX;
  }
  local_8 = 0xffffffff;
  FUN_10002f20(this_00,piVar6,(int *)IVar9.lpVtbl);
  Ordinal_8();
  local_8 = 3;
  Ordinal_8();
  local_8 = CONCAT31(local_8._1_3_,4);
  if (*(int *)((int)this + 4) == 0) goto LAB_10012ebe;
  local_38 = (IUnknown *)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_10012960(this,&local_38);
  piVar6 = local_3c;
  iVar5 = *local_3c;
  pIVar7 = local_38;
  if (iVar5 == 4) {
    if (local_38 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pIVar7 = extraout_EAX_00;
    }
    p_Var2 = (_func_5021 *)pIVar7->lpVtbl[0xb].Release;
LAB_10012c6b:
    UVar3 = (*p_Var2)(pIVar7);
    if ((int)UVar3 < 0) {
      _com_issue_errorex(UVar3,pIVar7,(_GUID *)&DAT_1002d1d4);
    }
  }
  else if ((iVar5 == 1) || (iVar5 == 3)) {
    if (local_38 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pIVar7 = extraout_EAX_01;
    }
    p_Var2 = pIVar7->lpVtbl[9].QueryInterface;
    goto LAB_10012c6b;
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_02;
  }
  IVar9.lpVtbl = (IUnknownVtbl *)*piVar6;
  UVar3 = (*pIVar7->lpVtbl[9].Release)(pIVar7);
  if ((int)UVar3 < 0) {
    _com_issue_errorex(UVar3,local_38,(_GUID *)&DAT_1002d1d4);
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_03;
  }
  HVar4 = (*pIVar7->lpVtbl[6].QueryInterface)
                    (pIVar7,(IID *)*param_4,&(IVar9.lpVtbl)->QueryInterface);
  if (HVar4 < 0) {
    _com_issue_errorex(HVar4,local_38,(_GUID *)&DAT_1002d1d4);
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_04;
  }
  IVar9.lpVtbl = (IUnknownVtbl *)*param_5;
  UVar3 = (*pIVar7->lpVtbl[2].Release)(pIVar7);
  if ((int)UVar3 < 0) {
    _com_issue_errorex(UVar3,local_38,(_GUID *)&DAT_1002d1d4);
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_05;
  }
  UVar3 = (*pIVar7->lpVtbl[10].AddRef)(pIVar7);
  if ((int)UVar3 < 0) {
    _com_issue_errorex(UVar3,local_38,(_GUID *)&DAT_1002d1d4);
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_06;
  }
  ppiVar13 = &local_3c;
  local_3c = (int *)0x0;
  UVar3 = (*pIVar7->lpVtbl[5].Release)(pIVar7);
  if ((int)UVar3 < 0) {
    _com_issue_errorex(UVar3,pIVar7,(_GUID *)&DAT_1002d1f4);
  }
  local_5c = local_3c;
  local_58 = (IUnknownVtbl *)0x0;
  local_50 = CONCAT22(local_50._2_2_,0x2011);
  iVar5 = Ordinal_15(0x11,1,&local_5c,ppiVar13);
  pIVar7 = local_38;
  local_48 = iVar5;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    iVar5 = extraout_EAX_07;
    pIVar7 = extraout_EDX;
  }
  uVar10 = local_50;
  UVar3 = (*pIVar7->lpVtbl[6].Release)(pIVar7);
  uVar11 = local_4c;
  uVar12 = local_44;
  if ((int)UVar3 < 0) {
    _com_issue_errorex(UVar3,local_38,(_GUID *)&DAT_1002d1d4);
    uVar11 = local_4c;
    uVar12 = local_44;
  }
  piVar6 = *(int **)((int)local_54 + 4);
  if (piVar6 == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar6 = extraout_EAX_08;
  }
  iVar5 = (**(code **)(*piVar6 + 0x2c))(piVar6,local_38,uVar10,uVar11,iVar5,uVar12);
  if (iVar5 < 0) {
    _com_issue_errorex(iVar5,local_38,(_GUID *)&DAT_1002d1d4);
  }
  pIVar7 = local_38;
  if (local_38 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar7 = extraout_EAX_09;
  }
  HVar4 = (*pIVar7->lpVtbl[5].QueryInterface)
                    (pIVar7,(IID *)local_40,&(IVar9.lpVtbl)->QueryInterface);
  if (HVar4 < 0) {
    _com_issue_errorex(HVar4,pIVar7,(_GUID *)&DAT_1002d1f4);
  }
  if (local_48 != 0) {
    Ordinal_16();
    local_48 = 0;
  }
  if (local_40 != (undefined1  [4])0x1) {
    pwVar8 = (wchar_t *)FUN_10012620();
    local_8 = CONCAT31(local_8._1_3_,6);
    if (7 < *(uint *)(pwVar8 + 10)) {
      pwVar8 = *(wchar_t **)pwVar8;
    }
    FUN_10015000(*(void **)((int)local_54 + 8),0x44e,0x80004005,0x1002d250,
                 L"DeviceControlWrapper.cpp",(undefined1 *)0x115,pwVar8);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (local_38 != (IUnknown *)0x0) {
    (*local_38->lpVtbl->Release)(local_38);
  }
LAB_10012ebe:
  Ordinal_9();
  ExceptionList = local_10;
  uStack_80 = 0x10012ee0;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10012ee6 at 10012ee6

undefined * Catch_10012ee6(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x44) != 0) {
    Ordinal_16(*(int *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
  }
  FUN_10020630(*(void **)(unaff_EBP + -0x6c),"DeviceControlWrapper.cpp",0x120,
               "CDeviceControlWrapper::readDeviceCPPData",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_10012f46;
}



// Function: Catch_All@10012f4b at 10012f4b

undefined4 Catch_All_10012f4b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  if (*(int *)(unaff_EBP + -0x44) != 0) {
    Ordinal_16(*(int *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
  }
  *(undefined ***)(unaff_EBP + -0x60) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x60),"DeviceControlWrapper.cpp",0x12a,
               "CDeviceControlWrapper::readDeviceCPPData",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x10012fc3;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x60));
  return 0x10012ebe;
}



// Function: FUN_10012fd0 at 10012fd0

void __thiscall FUN_10012fd0(void *this,void *param_1,undefined4 *param_2)

{
  IUnknown *This;
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  void *extraout_EAX_02;
  undefined4 *puVar3;
  ULONG UVar4;
  void *extraout_EAX_03;
  int *extraout_EAX_04;
  void *extraout_EAX_05;
  void *pvVar5;
  int *piVar6;
  HRESULT HVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *extraout_ECX_08;
  void *extraout_ECX_09;
  int *extraout_ECX_10;
  int *extraout_ECX_11;
  int *extraout_ECX_12;
  int *extraout_ECX_13;
  undefined4 uVar8;
  IID *riid;
  undefined4 uVar9;
  void **ppvObject;
  uint uStack_98;
  undefined4 local_74;
  int local_70;
  void *local_6c;
  undefined4 *local_68;
  void *local_64;
  IID *local_60;
  int local_5c;
  undefined1 *local_58;
  int *local_54 [8];
  undefined4 local_34;
  int local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10024a84;
  local_10 = ExceptionList;
  uStack_98 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_6c = param_1;
  local_68 = param_2;
  local_8 = 0;
  local_64 = this;
  local_18 = uStack_98;
  GetCurrentThreadId();
  local_58 = &stack0xffffff5c;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_54[0] = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("DeviceControlWrapper.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_54[0] = (int *)&stack0xffffff58;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff58,0x1002d9a8);
  pvVar5 = *(void **)(*(int *)((int)this + 8) + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar6,piVar1);
  GetCurrentThreadId();
  local_58 = &stack0xffffff5c;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_54[0] = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("DeviceControlWrapper.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_54[0] = (int *)&stack0xffffff50;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff50,0x1002abe8);
  pvVar5 = *(void **)(*(int *)((int)this + 8) + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar5,piVar6,uVar8,uVar9,piVar1);
  FUN_100126b0((int)this);
  puVar3 = *(undefined4 **)((int)this + 4);
  local_60 = (IID *)0x0;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7fffbffd);
    puVar3 = extraout_EAX_01;
  }
  (**(code **)*puVar3)();
  ppvObject = *(void ***)(*(int *)((int)this + 8) + 8);
  riid = local_60;
  (**(code **)(local_60->Data1 + 0x20))();
  if (local_60 != (IID *)0x0) {
    (**(code **)(local_60->Data1 + 8))();
    local_60 = (IID *)0x0;
  }
  local_8._0_1_ = 7;
  GetCurrentThreadId();
  local_58 = &stack0xffffff48;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 8;
  local_54[0] = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar6 = extraout_ECX_05;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("DeviceControlWrapper.cpp");
    *piVar1 = iVar2;
    piVar6 = extraout_ECX_06;
  }
  local_8._0_1_ = 7;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_07;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_54[0] = (int *)&stack0xffffff3c;
  local_8._0_1_ = 9;
  FUN_10001f10(&stack0xffffff3c,0x1002d8a8);
  pvVar5 = *(void **)(*(int *)((int)this + 8) + 4);
  local_8._0_1_ = 10;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_02;
  }
  local_8._0_1_ = 7;
  FUN_10005e10(pvVar5,piVar6,uVar8,uVar9,piVar1);
  local_5c = 0;
  FUN_1000e8f0(local_6c,&local_5c);
  puVar3 = local_68;
  if (7 < (uint)local_68[5]) {
    puVar3 = (undefined4 *)*local_68;
  }
  local_58 = &stack0xffffff50;
  piVar1 = extraout_ECX_08;
  FUN_10001f10(&stack0xffffff50,(int)puVar3);
  pvVar5 = *(void **)((int)this + 4);
  local_8._0_1_ = 0xb;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_ECX_09;
  }
  local_8._0_1_ = 7;
  UVar4 = FUN_10012570(pvVar5,piVar1);
  if (-1 < (int)UVar4) {
    GetCurrentThreadId();
    local_58 = &stack0xffffff48;
    piVar6 = extraout_ECX_10;
    FUN_10001e80(&stack0xffffff48,"DeviceControlWrapper.cpp");
    uVar9 = 4;
    uVar8 = 2;
    local_54[0] = (int *)&stack0xffffff3c;
    local_8._0_1_ = 0xc;
    piVar1 = extraout_ECX_11;
    FUN_10001f10(&stack0xffffff3c,0x1002d7b0);
    pvVar5 = *(void **)(*(int *)((int)this + 8) + 4);
    local_8._0_1_ = 0xd;
    if (pvVar5 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar5 = extraout_EAX_03;
    }
    local_8._0_1_ = 7;
    FUN_10005e10(pvVar5,piVar1,uVar8,uVar9,piVar6);
    local_54[0] = (int *)0x0;
    local_58 = (undefined1 *)0x0;
    local_74 = 2;
    local_68 = (undefined4 *)0xc8;
    Ordinal_8();
    pvVar5 = local_64;
    local_8 = CONCAT31(local_8._1_3_,0xe);
    local_70 = 1;
    FUN_10012af0(&local_58,(ulong)local_54,&local_70,&local_74,&local_68);
    piVar1 = *(int **)((int)pvVar5 + 4);
    local_5c = 0;
    if (piVar1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar1 = extraout_EAX_04;
    }
    iVar2 = (**(code **)(*piVar1 + 0x38))();
    if (-1 < iVar2) {
      GetCurrentThreadId();
      local_58 = &stack0xffffff3c;
      piVar6 = extraout_ECX_12;
      FUN_10001e80(&stack0xffffff3c,"DeviceControlWrapper.cpp");
      uVar9 = 4;
      uVar8 = 2;
      local_54[0] = (int *)&stack0xffffff30;
      local_8._0_1_ = 0xf;
      piVar1 = extraout_ECX_13;
      FUN_10001f10(&stack0xffffff30,0x1002d688);
      pvVar5 = *(void **)(*(int *)((int)pvVar5 + 8) + 4);
      local_8._0_1_ = 0x10;
      if (pvVar5 == (void *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pvVar5 = extraout_EAX_05;
      }
      local_8._0_1_ = 0xe;
      FUN_10005e10(pvVar5,piVar1,uVar8,uVar9,piVar6);
      piVar1 = FUN_10001f10(&local_58,local_5c);
      local_8._0_1_ = 0x11;
      if ((undefined4 *)*piVar1 == (undefined4 *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = *(int **)*piVar1;
      }
      local_20 = 7;
      local_24 = 0;
      local_34 = (void *)((uint)local_34._2_2_ << 0x10);
      piVar6 = piVar1;
      do {
        iVar2 = *piVar6;
        piVar6 = (int *)((int)piVar6 + 2);
      } while ((short)iVar2 != 0);
      FUN_10003130(&local_34,piVar1,(int)piVar6 - ((int)piVar1 + 2) >> 1);
      local_8 = CONCAT31(local_8._1_3_,0x13);
      FUN_10002ed0(&local_58);
      if (local_5c != 0) {
        Ordinal_6();
        local_5c = 0;
      }
      pvVar5 = local_6c;
      if (local_24 != 0) {
        FUN_1000fbc0(local_6c,&local_34);
        local_54[0] = (int *)0x1;
        FUN_1000e8f0(pvVar5,local_54);
      }
      if (7 < local_20) {
        operator_delete(local_34);
      }
    }
    local_8._0_1_ = 7;
    Ordinal_9();
    this = local_64;
  }
  This = *(IUnknown **)((int)this + 4);
  if (This == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  HVar7 = (*This->lpVtbl[4].QueryInterface)(This,riid,ppvObject);
  if (HVar7 < 0) {
    _com_issue_errorex(HVar7,This,(_GUID *)&DAT_1002d1e4);
  }
  Sleep(100);
  ExceptionList = local_10;
  uStack_98 = 0x10013487;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001348d at 1001348d

undefined * Catch_1001348d(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *extraout_EAX;
  void *pvVar3;
  int *piVar4;
  int *extraout_EAX_00;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int unaff_EBP;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  GetCurrentThreadId();
  *(undefined1 **)(unaff_EBP + -0x54) = &stack0xfffffff4;
  piVar7 = extraout_ECX;
  FUN_10001e80(&stack0xfffffff4,"DeviceControlWrapper.cpp");
  uVar6 = 4;
  uVar5 = 2;
  *(undefined1 **)(unaff_EBP + -0x50) = &stack0xffffffe8;
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  piVar4 = extraout_ECX_00;
  FUN_10001f10(&stack0xffffffe8,0x1002d578);
  iVar1 = *(int *)(unaff_EBP + -0x60);
  pvVar3 = *(void **)(*(int *)(iVar1 + 8) + 4);
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar7);
  piVar4 = FUN_100124d0((void *)(unaff_EBP + -0x84),(undefined4 *)(unaff_EBP + -0x54));
  puVar2 = (undefined4 *)*piVar4;
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  if (puVar2 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)*puVar2;
  }
  FUN_100046c0((void *)(unaff_EBP + -0x4c),piVar4);
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x54));
  piVar4 = *(int **)(iVar1 + 4);
  if (piVar4 != (int *)0x0) {
    if (piVar4 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar4 = extraout_EAX_00;
    }
    (**(code **)(*piVar4 + 0x30))();
  }
  pvVar3 = *(void **)(unaff_EBP + -0x68);
  FUN_1000fbc0(pvVar3,(int *)(unaff_EBP + -0x4c));
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  FUN_1000e8f0(pvVar3,(undefined4 *)(unaff_EBP + -0x50));
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x84));
  return &DAT_1001357f;
}



// Function: Catch_All@10013584 at 10013584

undefined4 Catch_All_10013584(void)

{
  int *extraout_EAX;
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x60) + 4);
  if (piVar1 != (int *)0x0) {
    if (piVar1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar1 = extraout_EAX;
    }
    (**(code **)(*piVar1 + 0x30))(piVar1);
  }
  OutputDebugStringW(L"Catch All Block - CDeviceControlWrapper::OpenDevice()\r\n");
  return 0x10013467;
}



// Function: Catch@100135bf at 100135bf

undefined * Catch_100135bf(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x74),"DeviceControlWrapper.cpp",0xa1,
               "CDeviceControlWrapper::OpenDevice",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1001360a;
}



// Function: Catch_All@1001360f at 1001360f

undefined4 Catch_All_1001360f(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FUN_10020630((void *)(unaff_EBP + -0x24),"DeviceControlWrapper.cpp",0xa1,
               "CDeviceControlWrapper::OpenDevice",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10013676;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x10013467;
}



// Function: FUN_10013680 at 10013680

void FUN_10013680(IID *param_1,IID *param_2,void **param_3)

{
  CLSID *pclsid;
  
  if (**(int **)(PTR_PTR_1003ace8 + 4) == 0) {
    pclsid = (CLSID *)0x0;
  }
  else {
    pclsid = *(CLSID **)**(int **)(PTR_PTR_1003ace8 + 4);
  }
  NdrDllGetClassObject
            (param_1,param_2,param_3,(ProxyFileInfo **)&PTR_PTR_1003ace8,pclsid,
             (CStdPSFactoryBuffer *)&DAT_1003afd4);
  return;
}



// Function: FUN_100136c0 at 100136c0

void FUN_100136c0(void)

{
  NdrDllCanUnloadNow((CStdPSFactoryBuffer *)&DAT_1003afd4);
  return;
}



// Function: FUN_100136d0 at 100136d0

void FUN_100136d0(IRpcStubBuffer *param_1)

{
  NdrCStdStubBuffer2_Release(param_1,(IPSFactoryBuffer *)&DAT_1003afd4);
  return;
}



// Function: FUN_100136f0 at 100136f0

void FUN_100136f0(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_1003afe4 = param_1;
  }
  return;
}



// Function: FUN_10013710 at 10013710

void FUN_10013710(void)

{
  if (**(int **)(PTR_PTR_1003ace8 + 4) != 0) {
    NdrDllRegisterProxy(DAT_1003afe4,(ProxyFileInfo **)&PTR_PTR_1003ace8,
                        *(CLSID **)**(int **)(PTR_PTR_1003ace8 + 4));
    return;
  }
  NdrDllRegisterProxy(DAT_1003afe4,(ProxyFileInfo **)&PTR_PTR_1003ace8,(CLSID *)0x0);
  return;
}



// Function: FUN_10013750 at 10013750

void FUN_10013750(void)

{
  if (**(int **)(PTR_PTR_1003ace8 + 4) != 0) {
    NdrDllUnregisterProxy
              (DAT_1003afe4,(ProxyFileInfo **)&PTR_PTR_1003ace8,
               *(CLSID **)**(int **)(PTR_PTR_1003ace8 + 4));
    return;
  }
  NdrDllUnregisterProxy(DAT_1003afe4,(ProxyFileInfo **)&PTR_PTR_1003ace8,(CLSID *)0x0);
  return;
}



// Function: FUN_10013790 at 10013790

undefined4 * __thiscall FUN_10013790(void *this,undefined4 param_1)

{
  FUN_1000c110(this,param_1);
  *(undefined ***)this = CInlineConnection::vftable;
  return (undefined4 *)this;
}



// Function: FUN_100137b0 at 100137b0

undefined4 * __thiscall FUN_100137b0(void *this,byte param_1)

{
  *(undefined ***)this = CInlineConnection::vftable;
  FUN_1000c150((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100137e0 at 100137e0

uint __thiscall FUN_100137e0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar3 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar3)) {
      iVar7 = uVar3 + (1 - param_3);
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      puVar1 = (ushort *)((int)pvVar4 + param_2 * 2);
      for (; iVar7 != 0; iVar7 = iVar7 + (-1 - (iVar5 >> 1))) {
        puVar2 = puVar1;
        iVar5 = iVar7;
        while (*puVar2 != *param_1) {
          puVar2 = puVar2 + 1;
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) goto LAB_1001383c;
        }
        if (puVar2 == (ushort *)0x0) break;
        puVar6 = puVar2;
        puVar8 = param_1;
        uVar3 = param_3;
        if (param_3 == 0) {
LAB_10013865:
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)puVar2 - (int)this >> 1;
        }
        while (*puVar6 == *puVar8) {
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
          uVar3 = uVar3 - 1;
          if (uVar3 == 0) goto LAB_10013865;
        }
        if ((-(uint)(*puVar6 < *puVar8) & 0xfffffffe) == 0xffffffff) goto LAB_10013865;
        iVar5 = (int)puVar2 - (int)puVar1;
        puVar1 = puVar2 + 1;
      }
    }
LAB_1001383c:
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_100138a0 at 100138a0

int * __thiscall
FUN_100138a0(void *this,uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

{
  code *pcVar1;
  uint uVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  undefined2 *puVar3;
  void *pvVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  uint extraout_ECX;
  uint uVar8;
  
  uVar7 = *(uint *)((int)this + 0x10);
  if ((uVar7 < param_1) || ((uint)param_3[4] < param_4)) {
    std::_Xout_of_range("invalid string position");
    pcVar1 = (code *)swi(3);
    piVar6 = (int *)(*pcVar1)();
    return piVar6;
  }
  uVar2 = uVar7 - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  uVar8 = param_3[4] - param_4;
  if (uVar8 < param_5) {
    param_5 = uVar8;
  }
  uVar7 = uVar7 - param_2;
  if (-param_5 - 1 <= uVar7) {
    std::_Xlength_error("string too long");
    uVar2 = extraout_EAX;
    uVar7 = extraout_ECX;
  }
  uVar2 = uVar2 - param_2;
  uVar7 = uVar7 + param_5;
  if (*(uint *)((int)this + 0x10) < uVar7) {
    uVar8 = uVar7;
    if (0x7ffffffe < uVar7) {
      std::_Xlength_error("string too long");
      uVar8 = extraout_EAX_00;
    }
    if (*(uint *)((int)this + 0x14) < uVar8) {
      FUN_100022b0(this,uVar7);
    }
    else if (uVar8 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      puVar3 = (undefined2 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        puVar3 = *this;
      }
      *puVar3 = 0;
    }
  }
  if ((int *)this == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        uVar8 = param_2 + param_1;
        if (param_4 < uVar8) {
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001be0((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),
                       param_2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001be0((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                       (void *)((int)pvVar4 + uVar8 * 2),uVar2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          uVar2 = param_5 - param_2;
          pvVar4 = (void *)((int)pvVar4 + (param_4 + param_5) * 2);
          pvVar5 = (void *)((int)pvVar5 + uVar8 * 2);
        }
        else {
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001be0((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                       (void *)((int)pvVar4 + uVar8 * 2),uVar2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          pvVar4 = (void *)((int)pvVar4 + ((param_4 - param_2) + param_5) * 2);
          pvVar5 = (void *)((int)pvVar5 + param_1 * 2);
          uVar2 = param_5;
        }
      }
      else {
        pvVar5 = this;
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
          pvVar4 = *this;
        }
        FUN_10001be0((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                     (void *)((int)pvVar4 + (param_2 + param_1) * 2),uVar2);
        if (*(uint *)((int)this + 0x14) < 8) {
          pvVar4 = (void *)((int)this + param_4 * 2);
          pvVar5 = (void *)((int)this + param_1 * 2);
          uVar2 = param_5;
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar4 = (void *)(*this + param_4 * 2);
          pvVar5 = (void *)(*this + param_1 * 2);
          uVar2 = param_5;
        }
      }
    }
    else {
      pvVar5 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
        pvVar4 = *this;
      }
      FUN_10001be0((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),param_5);
      pvVar5 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
        pvVar4 = *this;
      }
      pvVar4 = (void *)((int)pvVar4 + (param_2 + param_1) * 2);
      pvVar5 = (void *)((int)pvVar5 + (param_1 + param_5) * 2);
    }
    FUN_10001be0(pvVar5,pvVar4,uVar2);
  }
  else {
    pvVar5 = this;
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
      pvVar4 = *this;
    }
    memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),
            (void *)((int)pvVar4 + (param_2 + param_1) * 2),uVar2 * 2);
    if (7 < (uint)param_3[5]) {
      param_3 = (int *)*param_3;
    }
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)((int)pvVar4 + param_1 * 2),(void *)((int)param_3 + param_4 * 2),param_5 * 2);
  }
  *(uint *)((int)this + 0x10) = uVar7;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)(*this + uVar7 * 2) = 0;
    return (int *)this;
  }
  *(undefined2 *)((int)this + uVar7 * 2) = 0;
  return (int *)this;
}



// Function: FUN_10013bd0 at 10013bd0

void __thiscall FUN_10013bd0(void *this,void *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar4;
  uint uVar5;
  short *psVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uStack_a0;
  undefined4 local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024b09;
  local_10 = ExceptionList;
  uStack_a0 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a0;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_a0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("InlineConnection.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff50,0x1002e948);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar7,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("InlineConnection.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff48,0x1002e8e0);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar7,uVar8,uVar9,piVar2);
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  psVar6 = (short *)PTR_u_<dclDeviceConfiguration><protoco_1003acfc;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_34,(int *)PTR_u_<dclDeviceConfiguration><protoco_1003acfc,
               (int)psVar6 - (int)(PTR_u_<dclDeviceConfiguration><protoco_1003acfc + 2) >> 1);
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50._2_2_ << 0x10);
  local_8._0_1_ = 8;
  FUN_1000ee40(param_1,&local_50);
  psVar6 = (short *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003acf0;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003acf0,0,
                       (int)psVar6 - (int)(PTR_u_ID_PROTOCOL_NAME_BEGIN_1003acf0 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003afe8,&local_50,0,0xffffffff);
  psVar6 = (short *)PTR_u_ID_PROTOCOL_NAME_END_1003acf4;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PROTOCOL_NAME_END_1003acf4,0,
                       (int)psVar6 - (int)(PTR_u_ID_PROTOCOL_NAME_END_1003acf4 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003afec,&local_50,0,0xffffffff);
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_10012150(param_1,&local_6c);
  psVar6 = (short *)PTR_u_ID_PORT_NUMBER_1003acf8;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PORT_NUMBER_1003acf8,0,
                       (int)psVar6 - (int)(PTR_u_ID_PORT_NUMBER_1003acf8 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003aff0,&local_6c,0,0xffffffff);
  FUN_10003030((void *)((int)this + 8),&local_34,0,0xffffffff);
  FUN_1000c1e0(param_1);
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10013eee at 10013eee

undefined * Catch_10013eee(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x8c),"InlineConnection.cpp",0x56,
               "CInlineConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10013f39;
}



// Function: Catch_All@10013f3b at 10013f3b

undefined4 Catch_All_10013f3b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x88) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x84) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x88),"InlineConnection.cpp",0x56,
               "CInlineConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10013fab;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x88));
  return 0x10013ed0;
}



// Function: FUN_10013fc0 at 10013fc0

undefined4 * __thiscall FUN_10013fc0(void *this,undefined4 param_1)

{
  FUN_1000c110(this,param_1);
  *(undefined ***)this = CInlineIIConnection::vftable;
  return (undefined4 *)this;
}



// Function: FUN_10013fe0 at 10013fe0

undefined4 * __thiscall FUN_10013fe0(void *this,byte param_1)

{
  *(undefined ***)this = CInlineIIConnection::vftable;
  FUN_1000c150((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014010 at 10014010

void __thiscall FUN_10014010(void *this,void *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar4;
  uint uVar5;
  short *psVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uStack_a0;
  undefined4 local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024b99;
  local_10 = ExceptionList;
  uStack_a0 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a0;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_a0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("InlineIIConnection.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff50,0x1002ee10);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar7,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("InlineIIConnection.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff48,0x1002edb8);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar7,uVar8,uVar9,piVar2);
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  psVar6 = (short *)PTR_u_<dclDeviceConfiguration><protoco_1003ad2c;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_34,(int *)PTR_u_<dclDeviceConfiguration><protoco_1003ad2c,
               (int)psVar6 - (int)(PTR_u_<dclDeviceConfiguration><protoco_1003ad2c + 2) >> 1);
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50._2_2_ << 0x10);
  local_8._0_1_ = 8;
  FUN_1000ee40(param_1,&local_50);
  psVar6 = (short *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ad20;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ad20,0,
                       (int)psVar6 - (int)(PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ad20 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003aff4,&local_50,0,0xffffffff);
  psVar6 = (short *)PTR_u_ID_PROTOCOL_NAME_END_1003ad24;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PROTOCOL_NAME_END_1003ad24,0,
                       (int)psVar6 - (int)(PTR_u_ID_PROTOCOL_NAME_END_1003ad24 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003aff8,&local_50,0,0xffffffff);
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_10012150(param_1,&local_6c);
  psVar6 = (short *)PTR_u_ID_PORT_NUMBER_1003ad28;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar5 = FUN_100137e0(&local_34,(ushort *)PTR_u_ID_PORT_NUMBER_1003ad28,0,
                       (int)psVar6 - (int)(PTR_u_ID_PORT_NUMBER_1003ad28 + 2) >> 1);
  FUN_100138a0(&local_34,uVar5,DAT_1003affc,&local_6c,0,0xffffffff);
  FUN_10003030((void *)((int)this + 8),&local_34,0,0xffffffff);
  FUN_1000c1e0(param_1);
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  local_3c = 7;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffff0000);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001432e at 1001432e

undefined * Catch_1001432e(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x8c),"InlineIIConnection.cpp",0x57,
               "CInlineIIConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b)
  ;
  return &DAT_10014379;
}



// Function: Catch_All@1001437b at 1001437b

undefined4 Catch_All_1001437b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x88) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x84) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x88),"InlineIIConnection.cpp",0x57,
               "CInlineIIConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b)
  ;
  uStack0000001c = 0x100143eb;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x88));
  return 0x10014310;
}



// Function: FUN_10014400 at 10014400

void __fastcall FUN_10014400(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10014430 at 10014430

HRESULT __thiscall FUN_10014430(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_1002ef48,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028450,&param_2);
    if (HVar2 < 0) goto LAB_100144b4;
    HVar2 = OleRun(param_2);
    if (-1 < HVar2) {
      HVar2 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1002ef48,(void **)this);
    }
    (*param_2->lpVtbl->Release)(param_2);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_100144b4:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_100144d0 at 100144d0

HRESULT __thiscall FUN_100144d0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_1002856c,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10028450,&param_2);
    if (HVar2 < 0) goto LAB_10014554;
    HVar2 = OleRun(param_2);
    if (-1 < HVar2) {
      HVar2 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1002856c,(void **)this);
    }
    (*param_2->lpVtbl->Release)(param_2);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10014554:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10014570 at 10014570

int __thiscall FUN_10014570(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *local_8;
  
  local_8 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar2 = -0x7fffbffe;
  }
  else {
    iVar2 = (**(code **)*param_1)(param_1,&DAT_1002ef58,&local_8);
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    uVar3 = (iVar2 < 0) - 1 & (uint)local_8;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(uint *)this = uVar3;
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar2;
}



// Function: FUN_100145f0 at 100145f0

int __thiscall FUN_100145f0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *local_8;
  
  local_8 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar2 = -0x7fffbffe;
  }
  else {
    iVar2 = (**(code **)*param_1)(param_1,&DAT_1002ef68,&local_8);
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    uVar3 = (iVar2 < 0) - 1 & (uint)local_8;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(uint *)this = uVar3;
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar2;
}



// Function: FUN_10014670 at 10014670

void __thiscall FUN_10014670(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x1c))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002ef48);
    *param_1 = 0;
    return;
  }
  *param_1 = 0;
  return;
}



// Function: FUN_100146d0 at 100146d0

void __fastcall FUN_100146d0(undefined4 *param_1)

{
  long lVar1;
  CLSID local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024be3;
  local_10 = ExceptionList;
  local_14 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  local_8 = 1;
  lVar1 = CLSIDFromProgID(L"Cummins.Logger.1",&local_24);
  if (lVar1 < 0) {
LAB_10014741:
    _com_issue_errorex(lVar1,(IUnknown *)param_1[1],(_GUID *)&DAT_1002856c);
  }
  else {
    lVar1 = FUN_100144d0(param_1 + 1,&local_24,(LPUNKNOWN)0x0,0x17);
    if (lVar1 < 0) goto LAB_10014741;
  }
  lVar1 = CLSIDFromProgID(L"Cummins.MsgManager.1",&local_24);
  if (-1 < lVar1) {
    lVar1 = FUN_10014430(param_1,&local_24,(LPUNKNOWN)0x0,0x17);
    if (-1 < lVar1) goto LAB_10014781;
  }
  _com_issue_errorex(lVar1,(IUnknown *)param_1[1],(_GUID *)&DAT_1002856c);
LAB_10014781:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100147a0 at 100147a0

void FUN_100147a0(undefined4 param_1,void *param_2)

{
  undefined4 uStack00000018;
  uint in_stack_0000001c;
  void *in_stack_00000024;
  undefined4 uStack00000034;
  uint in_stack_00000038;
  void *in_stack_00000040;
  uint in_stack_00000054;
  
  if (7 < in_stack_0000001c) {
    operator_delete(param_2);
  }
  uStack00000018 = 0;
  if (7 < in_stack_00000038) {
    operator_delete(in_stack_00000024);
  }
  uStack00000034 = 0;
  if (7 < in_stack_00000054) {
    operator_delete(in_stack_00000040);
  }
  return;
}



// Function: FUN_10014810 at 10014810

undefined4 * __thiscall FUN_10014810(void *this,undefined4 *param_1)

{
  int iVar1;
  LONG LVar2;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024c28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x28))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002ef48);
  }
  *param_1 = 0;
  if (((in_stack_00000018 != (int *)0x0) &&
      (LVar2 = InterlockedDecrement(in_stack_00000018 + 2), LVar2 == 0)) &&
     (in_stack_00000018 != (int *)0x0)) {
    if (*in_stack_00000018 != 0) {
      Ordinal_6(*in_stack_00000018);
    }
    if ((void *)in_stack_00000018[1] != (void *)0x0) {
      operator_delete__((void *)in_stack_00000018[1]);
    }
    operator_delete(in_stack_00000018);
  }
  if (((in_stack_0000001c != (int *)0x0) &&
      (LVar2 = InterlockedDecrement(in_stack_0000001c + 2), LVar2 == 0)) &&
     (in_stack_0000001c != (int *)0x0)) {
    if (*in_stack_0000001c != 0) {
      Ordinal_6(*in_stack_0000001c);
    }
    if ((void *)in_stack_0000001c[1] != (void *)0x0) {
      operator_delete__((void *)in_stack_0000001c[1]);
    }
    operator_delete(in_stack_0000001c);
  }
  if (((in_stack_00000024 != (int *)0x0) &&
      (LVar2 = InterlockedDecrement(in_stack_00000024 + 2), LVar2 == 0)) &&
     (in_stack_00000024 != (int *)0x0)) {
    if (*in_stack_00000024 != 0) {
      Ordinal_6(*in_stack_00000024);
    }
    if ((void *)in_stack_00000024[1] != (void *)0x0) {
      operator_delete__((void *)in_stack_00000024[1]);
    }
    operator_delete(in_stack_00000024);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10014990 at 10014990

void __thiscall FUN_10014990(void *this,IUnknown *param_1,int *param_2,int *param_3)

{
  IUnknown *pIVar1;
  int *piVar2;
  int iVar3;
  ULONG UVar4;
  LONG LVar5;
  void *extraout_ECX;
  void *this_00;
  int *piVar6;
  IUnknown IVar7;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024c78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f10(&local_14,(int)param_2);
                    /* WARNING: Load size is inaccurate */
  this_00 = *this;
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_ECX;
  }
  piVar2 = (int *)FUN_10014670(this_00,&local_18);
  IVar7.lpVtbl = (IUnknownVtbl *)*piVar2;
  param_1 = (IUnknown *)&stack0xffffffd0;
  local_8 = CONCAT31(local_8._1_3_,1);
  param_3 = (int *)0x0;
  pIVar1 = (IUnknown *)&stack0xffffffd0;
  if (IVar7.lpVtbl != (IUnknownVtbl *)0x0) {
    (**(code **)((IVar7.lpVtbl)->QueryInterface + 4))();
    pIVar1 = param_1;
  }
  param_1 = pIVar1;
  iVar3 = FUN_10014570(&param_3,(int *)IVar7.lpVtbl);
  if ((iVar3 < 0) && (iVar3 != -0x7fffbffe)) {
    _com_issue_error(iVar3);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  piVar2 = param_3;
  param_2 = (int *)0x0;
  if (param_3 != (int *)0x0) {
    (**(code **)*param_3)();
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  (**(code **)(*param_2 + 0x50))();
                    /* WARNING: Load size is inaccurate */
  piVar6 = *this;
  param_1 = (IUnknown *)0x0;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))(piVar6);
  }
  iVar3 = FUN_100145f0(&param_1,piVar6);
  if ((iVar3 < 0) && (iVar3 != -0x7fffbffe)) {
    _com_issue_error(iVar3);
  }
  pIVar1 = param_1;
  local_8 = CONCAT31(local_8._1_3_,5);
  if (param_1 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar4 = (*pIVar1->lpVtbl[2].AddRef)(pIVar1);
  if ((int)UVar4 < 0) {
    _com_issue_errorex(UVar4,pIVar1,(_GUID *)&DAT_1002ef68);
  }
  local_8._0_1_ = 4;
  (*pIVar1->lpVtbl->Release)(pIVar1);
  local_8._0_1_ = 3;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  if ((local_14 != (int *)0x0) && (LVar5 = InterlockedDecrement(local_14 + 2), LVar5 == 0)) {
    if (*local_14 != 0) {
      Ordinal_6(*local_14);
    }
    if ((void *)local_14[1] != (void *)0x0) {
      operator_delete__((void *)local_14[1]);
    }
    operator_delete(local_14);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014b60 at 10014b60

void __thiscall
FUN_10014b60(void *this,IUnknown *param_1,undefined1 *param_2,IUnknown *param_3,int *param_4)

{
  IUnknown *pIVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  HRESULT HVar5;
  ULONG UVar6;
  LONG LVar7;
  void *extraout_ECX;
  void *this_00;
  IUnknown IVar8;
  int *piVar9;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024cc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f10(&local_14,(int)param_3);
                    /* WARNING: Load size is inaccurate */
  this_00 = *this;
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_ECX;
  }
  piVar3 = (int *)FUN_10014670(this_00,&local_18);
  IVar8.lpVtbl = (IUnknownVtbl *)*piVar3;
  param_1 = (IUnknown *)&stack0xffffffd4;
  local_8 = CONCAT31(local_8._1_3_,1);
  param_4 = (int *)0x0;
  pIVar1 = (IUnknown *)&stack0xffffffd4;
  if (IVar8.lpVtbl != (IUnknownVtbl *)0x0) {
    (**(code **)((IVar8.lpVtbl)->QueryInterface + 4))();
    pIVar1 = param_1;
  }
  param_1 = pIVar1;
  iVar4 = FUN_10014570(&param_4,(int *)IVar8.lpVtbl);
  if ((iVar4 < 0) && (iVar4 != -0x7fffbffe)) {
    _com_issue_error(iVar4);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  piVar3 = param_4;
  param_3 = (IUnknown *)0x0;
  if (param_4 != (int *)0x0) {
    (**(code **)*param_4)(param_4);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (local_14 == (int *)0x0) {
    IVar8.lpVtbl = (IUnknownVtbl *)0x0;
  }
  else {
    IVar8.lpVtbl = (IUnknownVtbl *)*local_14;
  }
  (*param_3->lpVtbl[6].Release)(param_3);
  pIVar1 = param_3;
  HVar5 = (*param_3->lpVtbl[9].QueryInterface)(param_3,(IID *)0x64,&(IVar8.lpVtbl)->QueryInterface);
  if (HVar5 < 0) {
    _com_issue_errorex(HVar5,pIVar1,(_GUID *)&DAT_1002ef78);
  }
  pIVar1 = param_3;
  UVar6 = (*param_3->lpVtbl[8].AddRef)(param_3);
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar1,(_GUID *)&DAT_1002ef78);
  }
                    /* WARNING: Load size is inaccurate */
  piVar9 = *this;
  param_2 = &stack0xffffffd0;
  param_1 = (IUnknown *)0x0;
  puVar2 = &stack0xffffffd0;
  if (piVar9 != (int *)0x0) {
    (**(code **)(*piVar9 + 4))(piVar9);
    puVar2 = param_2;
  }
  param_2 = puVar2;
  iVar4 = FUN_100145f0(&param_1,piVar9);
  if ((iVar4 < 0) && (iVar4 != -0x7fffbffe)) {
    _com_issue_error(iVar4);
  }
  pIVar1 = param_1;
  local_8 = CONCAT31(local_8._1_3_,5);
  if (param_1 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar6 = (*pIVar1->lpVtbl[2].AddRef)(pIVar1);
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar1,(_GUID *)&DAT_1002ef68);
  }
  local_8._0_1_ = 4;
  (*pIVar1->lpVtbl->Release)(pIVar1);
  local_8._0_1_ = 3;
  if (param_3 != (IUnknown *)0x0) {
    (*param_3->lpVtbl->Release)(param_3);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  if (local_14 != (int *)0x0) {
    LVar7 = InterlockedDecrement(local_14 + 2);
    if (LVar7 == 0) {
      if (*local_14 != 0) {
        Ordinal_6(*local_14);
      }
      if ((void *)local_14[1] != (void *)0x0) {
        operator_delete__((void *)local_14[1]);
      }
      operator_delete(local_14);
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014d70 at 10014d70

void __thiscall
FUN_10014d70(void *this,undefined4 param_1,undefined4 param_2,IUnknown *param_3,IUnknown *param_4,
            int *param_5,IID *param_6,int *param_7,undefined1 *param_8)

{
  IUnknown *This;
  IUnknown *pIVar1;
  undefined1 *puVar2;
  void **ppvObject;
  int *piVar3;
  int iVar4;
  IID *extraout_EAX;
  IID *riid;
  HRESULT HVar5;
  ULONG UVar6;
  LONG LVar7;
  void *extraout_ECX;
  void *this_00;
  IUnknown IVar8;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024d38;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_1003af5c ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  FUN_10001f10(&local_14,(int)param_3);
  local_8 = 0;
  FUN_10001f10(&local_18,(int)param_4);
  piVar3 = param_7;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10001f10(&param_7,(int)param_7);
  param_3 = (IUnknown *)&stack0xffffffd0;
  pIVar1 = (IUnknown *)&stack0xffffffd0;
  if (param_7 != (int *)0x0) {
    InterlockedIncrement(param_7 + 2);
    pIVar1 = param_3;
  }
  param_3 = pIVar1;
  param_4 = (IUnknown *)&stack0xffffffc8;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10001f10(&stack0xffffffc8,(int)piVar3);
  param_8 = &stack0xffffffc4;
  puVar2 = &stack0xffffffc4;
  if (local_14 != (int *)0x0) {
    InterlockedIncrement(local_14 + 2);
    puVar2 = param_8;
  }
  param_8 = puVar2;
                    /* WARNING: Load size is inaccurate */
  this_00 = *this;
  local_8._0_1_ = 5;
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_ECX;
  }
  local_8._0_1_ = 2;
  piVar3 = FUN_10014810(this_00,&param_5);
  IVar8.lpVtbl = (IUnknownVtbl *)*piVar3;
  param_4 = (IUnknown *)&stack0xffffffd4;
  local_8 = CONCAT31(local_8._1_3_,6);
  param_3 = (IUnknown *)0x0;
  pIVar1 = (IUnknown *)&stack0xffffffd4;
  if (IVar8.lpVtbl != (IUnknownVtbl *)0x0) {
    (**(code **)((IVar8.lpVtbl)->QueryInterface + 4))();
    pIVar1 = param_4;
  }
  param_4 = pIVar1;
  iVar4 = FUN_10014570(&param_3,(int *)IVar8.lpVtbl);
  if ((iVar4 < 0) && (iVar4 != -0x7fffbffe)) {
    _com_issue_error(iVar4);
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  if (param_5 != (int *)0x0) {
    (**(code **)(*param_5 + 8))();
  }
  pIVar1 = param_3;
  if (param_6 != (IID *)0x0) {
    riid = param_6;
    if (param_3 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      riid = extraout_EAX;
    }
    HVar5 = (*pIVar1->lpVtbl[6].QueryInterface)(pIVar1,riid,ppvObject);
    if (HVar5 < 0) {
      _com_issue_errorex(HVar5,pIVar1,(_GUID *)&DAT_1002ef58);
    }
  }
                    /* WARNING: Load size is inaccurate */
  IVar8.lpVtbl = *this;
  param_8 = &stack0xffffffd4;
  param_4 = (IUnknown *)0x0;
  puVar2 = &stack0xffffffd4;
  if (IVar8.lpVtbl != (IUnknownVtbl *)0x0) {
    (**(code **)((IVar8.lpVtbl)->QueryInterface + 4))();
    puVar2 = param_8;
  }
  param_8 = puVar2;
  iVar4 = FUN_100145f0(&param_4,(int *)IVar8.lpVtbl);
  if ((iVar4 < 0) && (iVar4 != -0x7fffbffe)) {
    _com_issue_error(iVar4);
  }
  This = param_4;
  local_8 = CONCAT31(local_8._1_3_,9);
  if (param_4 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar6 = (*This->lpVtbl[2].AddRef)(This);
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,This,(_GUID *)&DAT_1002ef68);
  }
  local_8._0_1_ = 8;
  (*This->lpVtbl->Release)(This);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (pIVar1 != (IUnknown *)0x0) {
    (*pIVar1->lpVtbl->Release)(pIVar1);
  }
  piVar3 = param_7;
  if (param_7 != (int *)0x0) {
    LVar7 = InterlockedDecrement(param_7 + 2);
    if (LVar7 == 0) {
      if (*piVar3 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
  }
  if (local_18 != (int *)0x0) {
    LVar7 = InterlockedDecrement(local_18 + 2);
    if (LVar7 == 0) {
      if (*local_18 != 0) {
        Ordinal_6();
      }
      if ((void *)local_18[1] != (void *)0x0) {
        operator_delete__((void *)local_18[1]);
      }
      operator_delete(local_18);
    }
  }
  if (local_14 != (int *)0x0) {
    LVar7 = InterlockedDecrement(local_14 + 2);
    if (LVar7 == 0) {
      if (*local_14 != 0) {
        Ordinal_6();
      }
      if ((void *)local_14[1] != (void *)0x0) {
        operator_delete__((void *)local_14[1]);
      }
      operator_delete(local_14);
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015000 at 10015000

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl
FUN_10015000(void *param_1,undefined4 param_2,undefined4 param_3,int param_4,LPCWSTR param_5,
            undefined1 *param_6,wchar_t *param_7)

{
  int iVar1;
  IUnknown *pIVar2;
  int iVar3;
  uchar *puVar4;
  LONG LVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  void *this;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  undefined4 uStackY_258;
  undefined4 uVar9;
  undefined4 uVar10;
  uint local_234;
  int *local_220;
  undefined1 *local_21c;
  int *local_218;
  IUnknown local_214 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024d8c;
  local_10 = ExceptionList;
  local_234 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_234;
  FUN_10001f10(&local_220,param_4);
  local_8 = 0;
  FUN_10001f10(&local_218,(int)param_5);
  local_8._0_1_ = 1;
  local_214[0].lpVtbl._0_2_ = 0;
  memset((void *)((int)&local_214[0].lpVtbl + 2),0,0x1fc);
  _vsnwprintf((wchar_t *)local_214,0xfe,param_7,&stack0x00000020);
  GetCurrentThreadId();
  local_21c = &stack0xfffffdc0;
  piVar6 = extraout_ECX;
  FUN_10001f10(&stack0xfffffdc0,(int)param_5);
  uVar10 = 2;
  uVar9 = 2;
  local_8._0_1_ = 2;
  piVar8 = extraout_ECX_00;
  FUN_10001f10(&stack0xfffffdb4,(int)local_214);
  this = *(void **)((int)param_1 + 4);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX_01;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005e10(this,piVar8,uVar9,uVar10,piVar6);
  piVar8 = local_218;
  if (local_218 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)*local_218;
  }
  if (local_220 == (int *)0x0) {
    pIVar2 = (IUnknown *)0x0;
  }
  else {
    pIVar2 = (IUnknown *)*local_220;
  }
  uStackY_258 = 0x10015124;
  FUN_10014d70(param_1,param_2,0x20,local_214,pIVar2,(int *)0x2,(IID *)0x0,piVar6,param_6);
  iVar3 = lstrlenW((LPCWSTR)local_214);
  iVar3 = iVar3 + 1;
  if (iVar3 < 0x40000000) {
    iVar1 = iVar3 * -2;
    piVar8 = local_218;
    if (&stack0x00000000 == (undefined1 *)0x234) goto LAB_1001517b;
    *(undefined4 *)(&stack0xfffffdc8 + iVar1) = 0;
    *(undefined4 *)(&stack0xfffffdc4 + iVar1) = 0;
    *(int *)(&stack0xfffffdc0 + iVar1) = iVar3 * 2;
    *(uint **)(&stack0xfffffdbc + iVar1) = &local_234;
    *(undefined4 *)(&stack0xfffffdb8 + iVar1) = 0xffffffff;
    *(IUnknown **)(&stack0xfffffdb4 + iVar1) = local_214;
    *(undefined4 *)(&stack0xfffffdb0 + iVar1) = 0;
    *(undefined4 *)(&stack0xfffffdac + iVar1) = 3;
    local_234 = local_234 & 0xffffff00;
    *(undefined4 *)((int)&uStackY_258 + iVar1) = 0x10015165;
    iVar3 = WideCharToMultiByte(*(UINT *)(&stack0xfffffdac + iVar1),
                                *(DWORD *)(&stack0xfffffdb0 + iVar1),
                                *(LPCWSTR *)(&stack0xfffffdb4 + iVar1),
                                *(int *)(&stack0xfffffdb8 + iVar1),
                                *(LPSTR *)(&stack0xfffffdbc + iVar1),
                                *(int *)(&stack0xfffffdc0 + iVar1),
                                *(LPCSTR *)(&stack0xfffffdc4 + iVar1),
                                *(LPBOOL *)(&stack0xfffffdc8 + iVar1));
    pcVar7 = (char *)(-(uint)(iVar3 != 0) & (uint)&local_234);
    piVar8 = local_218;
  }
  else {
LAB_1001517b:
    pcVar7 = (char *)0x0;
  }
  if (param_5 != (LPCWSTR)0x0) {
    iVar3 = lstrlenW(param_5);
    if (iVar3 + 1 < 0x40000000) {
      local_21c = (undefined1 *)((iVar3 + 1) * 2);
      piVar8 = local_218;
      if (&stack0x00000000 != (undefined1 *)0x234) {
        local_234 = local_234 & 0xffffff00;
        uStackY_258 = 0x100151bf;
        iVar3 = WideCharToMultiByte(3,0,param_5,-1,(LPSTR)&local_234,(int)local_21c,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        puVar4 = (uchar *)(-(uint)(iVar3 != 0) & (uint)&local_234);
        piVar8 = local_218;
        goto LAB_100151d5;
      }
    }
  }
  puVar4 = (uchar *)0x0;
LAB_100151d5:
  FUN_100212d0(puVar4,param_6,param_3,&DAT_100318b8,pcVar7);
  if ((piVar8 != (int *)0x0) && (LVar5 = InterlockedDecrement(piVar8 + 2), LVar5 == 0)) {
    if (*piVar8 != 0) {
      Ordinal_6();
    }
    if ((void *)piVar8[1] != (void *)0x0) {
      operator_delete__((void *)piVar8[1]);
    }
    operator_delete(piVar8);
  }
  if ((local_220 != (int *)0x0) && (LVar5 = InterlockedDecrement(local_220 + 2), LVar5 == 0)) {
    if (*local_220 != 0) {
      Ordinal_6();
    }
    if ((void *)local_220[1] != (void *)0x0) {
      operator_delete__((void *)local_220[1]);
    }
    operator_delete(local_220);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015290 at 10015290

void __fastcall FUN_10015290(int param_1)

{
  if (7 < *(uint *)(param_1 + 0x18)) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  return;
}



// Function: FUN_100152c0 at 100152c0

int * __fastcall FUN_100152c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10024dfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002f030);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 0;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002efe8);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  ExceptionList = local_10;
  return param_1 + 1;
}



// Function: Catch@10015424 at 10015424

undefined * Catch_10015424(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"Port.cpp",0x41,"CPort::GetPort",0x3ed7ac9c,0x46d59d92,
               0x81b10189,0x696e973b);
  return &DAT_1001546c;
}



// Function: Catch_All@1001546e at 1001546e

undefined4 Catch_All_1001546e(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"Port.cpp",0x41,"CPort::GetPort",0x3ed7ac9c,0x46d59d92,
               0x81b10189,0x696e973b);
  uStack0000001c = 0x100154d2;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1001540c;
}



// Function: FUN_100154e0 at 100154e0

void __thiscall FUN_100154e0(void *this,char param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10024e5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x1002f0e0);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 0;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x1002f088);
                    /* WARNING: Load size is inaccurate */
  pvVar3 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  if (param_1 == '\0') {
    *(undefined1 *)((int)this + 0x20) = 1;
  }
  else if (param_1 == '\x01') {
    *(undefined1 *)((int)this + 0x20) = 0;
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001566d at 1001566d

undefined1 * Catch_1001566d(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"Port.cpp",0x98,"CPort::SetPortAvailability",0x3ed7ac9c
               ,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_100156b8;
}



// Function: Catch_All@100156cc at 100156cc

undefined4 Catch_All_100156cc(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"Port.cpp",0x98,"CPort::SetPortAvailability",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10015733;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1001563e;
}



// Function: FUN_10015740 at 10015740

undefined1 __fastcall FUN_10015740(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024eb6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_00;
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8 = 1;
  FUN_10001f10(&stack0xffffffc8,0x1002f170);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX;
  }
  local_8 = 0xffffffff;
  FUN_10002f20(pvVar3,piVar4,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8 = 3;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar4 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Port.cpp");
    *piVar1 = iVar2;
    piVar4 = extraout_ECX_03;
  }
  local_8 = 0xffffffff;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_04;
  }
  uVar6 = 4;
  uVar5 = 0;
  local_8 = 4;
  FUN_10001f10(&stack0xffffffc0,0x1002f120);
  pvVar3 = *(void **)(*param_1 + 4);
  local_8 = CONCAT31(local_8._1_3_,5);
  if (pvVar3 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar3 = extraout_EAX_00;
  }
  local_8 = 0xffffffff;
  FUN_10005e10(pvVar3,piVar4,uVar5,uVar6,piVar1);
  ExceptionList = local_10;
  return (char)param_1[8];
}



// Function: FUN_100158d0 at 100158d0

undefined4 * __thiscall FUN_100158d0(void *this,undefined4 param_1,int *param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 0x18) = 7;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  FUN_10003030((undefined2 *)((int)this + 4),param_2,0,0xffffffff);
  *(undefined1 *)((int)this + 0x20) = 1;
  return (undefined4 *)this;
}



// Function: FUN_10015910 at 10015910

void __thiscall FUN_10015910(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10015930 at 10015930

void __fastcall FUN_10015930(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



// Function: FUN_10015970 at 10015970

void * FUN_10015970(char *param_1)

{
  void *pvVar1;
  undefined **local_10 [3];
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x40000000) &&
     (pvVar1 = operator_new((int)param_1 * 4), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_100159d0 at 100159d0

void __thiscall FUN_100159d0(void *this,char *param_1)

{
  void *pvVar1;
  int iVar2;
  char *extraout_EAX;
  char *pcVar3;
  void *_Dst;
  
  pcVar3 = param_1;
  if ((char *)0x3fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
    pcVar3 = extraout_EAX;
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)(*(int *)((int)this + 8) - *this >> 2) < pcVar3) {
    _Dst = FUN_10015970(pcVar3);
                    /* WARNING: Load size is inaccurate */
    memmove(_Dst,*this,(*(int *)((int)this + 4) - (int)*this >> 2) * 4);
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)this = _Dst;
    *(void **)((int)this + 8) = (void *)((int)_Dst + (int)param_1 * 4);
    *(void **)((int)this + 4) = (void *)((int)_Dst + (iVar2 - (int)pvVar1 >> 2) * 4);
  }
  return;
}



// Function: FUN_10015a60 at 10015a60

void __thiscall FUN_10015a60(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_EAX;
  char *pcVar3;
  void *extraout_ECX;
  int extraout_EDX;
  char *pcVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = *(int *)((int)this + 4) - iVar1 >> 2;
  if (0x3fffffffU - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
    param_1 = extraout_EDX;
  }
  pcVar3 = (char *)(uVar2 + param_1);
  pcVar4 = (char *)(*(int *)((int)this + 8) - iVar1 >> 2);
  if (pcVar4 < pcVar3) {
    if ((char *)(0x3fffffff - ((uint)pcVar4 >> 1)) < pcVar4) {
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = pcVar4 + ((uint)pcVar4 >> 1);
    }
    if (pcVar4 < pcVar3) {
      pcVar4 = pcVar3;
    }
    FUN_100159d0(this,pcVar4);
  }
  return;
}



// Function: FUN_10015ac0 at 10015ac0

void FUN_10015ac0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003ad54);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015b50 at 10015b50

void FUN_10015b50(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar4;
  HRESULT HVar5;
  wchar_t *pwVar6;
  LONG LVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar8;
  LPVOID *ppv;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uStack_64;
  int *local_3c;
  int *local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024f3e;
  local_10 = ExceptionList;
  uStack_64 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_64;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_64;
  GetCurrentThreadId();
  local_3c = (int *)&stack0xffffff90;
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar8 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("Ports.cpp");
    *piVar2 = iVar3;
    piVar8 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff8c,0x1002f220);
  pvVar4 = *(void **)(*local_38 + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar8,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_3c = piVar2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar8 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("Ports.cpp");
    *piVar2 = iVar3;
    piVar8 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar8 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 1;
  local_3c = (int *)&stack0xffffff84;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff84,0x1002f1f0);
  piVar1 = local_38;
  pvVar4 = *(void **)(*local_38 + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar8,uVar9,uVar10,piVar2);
  ppv = (LPVOID *)(piVar1 + 1);
  HVar5 = CoCreateInstance((IID *)&DAT_10031a48,(LPUNKNOWN)0x0,1,(IID *)&DAT_10031978,ppv);
  if ((HVar5 < 0) && (*ppv != (LPVOID)0x0)) {
    pwVar6 = (wchar_t *)FUN_10015ac0();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar6 + 10)) {
      pwVar6 = *(wchar_t **)pwVar6;
    }
    FUN_10015000((void *)*local_38,0x3fd,HVar5,0x1002f220,L"Ports.cpp",(undefined1 *)0x94,pwVar6);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  piVar2 = FUN_10001f10(&local_3c,0x1002f1c4);
  local_8._0_1_ = 8;
  if ((undefined4 *)*piVar2 == (undefined4 *)0x0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *(undefined4 *)*piVar2;
  }
                    /* WARNING: Load size is inaccurate */
  piVar8 = local_38 + 2;
  iVar3 = (**(code **)(**ppv + 0xc))(*ppv,uVar9,0);
  piVar2 = local_3c;
  local_8._0_1_ = 0;
  if (local_3c != (int *)0x0) {
    LVar7 = InterlockedDecrement(local_3c + 2);
    if ((LVar7 == 0) && (piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        Ordinal_6(*piVar2);
      }
      if ((void *)piVar2[1] != (void *)0x0) {
        operator_delete__((void *)piVar2[1]);
      }
      operator_delete(piVar2);
    }
  }
  if ((iVar3 < 0) && (*piVar8 != 0)) {
    pwVar6 = (wchar_t *)FUN_10015ac0();
    local_8._0_1_ = 9;
    if (7 < *(uint *)(pwVar6 + 10)) {
      pwVar6 = *(wchar_t **)pwVar6;
    }
    FUN_10015000((void *)*local_38,0x3fe,iVar3,0x1002f220,L"Ports.cpp",(undefined1 *)0xa7,pwVar6);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  HVar5 = CoSetProxyBlanket((IUnknown *)*piVar8,10,0,(OLECHAR *)0x0,3,3,
                            (RPC_AUTH_IDENTITY_HANDLE)0x0,0);
  if (HVar5 < 0) {
    pwVar6 = (wchar_t *)FUN_10015ac0();
    local_8._0_1_ = 10;
    if (7 < *(uint *)(pwVar6 + 10)) {
      pwVar6 = *(wchar_t **)pwVar6;
    }
    FUN_10015000((void *)*local_38,0x3fe,HVar5,0x1002f220,L"Ports.cpp",(undefined1 *)0xba,pwVar6);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10015e86 at 10015e86

undefined * Catch_10015e86(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x50),"Ports.cpp",0xbd,"CPorts::initialiseWMILibrary",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10015ed1;
}



// Function: Catch_All@10015ed3 at 10015ed3

undefined4 Catch_All_10015ed3(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x4c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10020630((void *)(unaff_EBP + -0x4c),"Ports.cpp",0xbd,"CPorts::initialiseWMILibrary",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10015f3a;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return 0x10015e6a;
}



// Function: FUN_10015f50 at 10015f50

void FUN_10015f50(uint *param_1)

{
  wchar_t wVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  int **ppiVar4;
  uint *this;
  int *piVar5;
  int iVar6;
  void *extraout_EAX;
  void *extraout_EAX_00;
  DWORD DVar7;
  void *pvVar8;
  uint *puVar9;
  wchar_t *pwVar10;
  uint uVar11;
  uint extraout_EAX_01;
  char *pcVar12;
  uint uVar13;
  uint extraout_EAX_02;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar14;
  int **extraout_ECX_05;
  int **ppiVar15;
  char *pcVar16;
  int **extraout_ECX_06;
  int **ppiVar17;
  int **extraout_EDX;
  uint extraout_EDX_00;
  undefined4 uVar18;
  undefined4 uVar19;
  uint uStack_100;
  uint *local_d8 [2];
  uint local_d0;
  int *local_cc;
  void *local_c8 [4];
  undefined4 local_b8;
  uint local_b4;
  wchar_t local_ac [64];
  wchar_t local_2c;
  undefined1 local_2a [18];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10025039;
  local_10 = ExceptionList;
  uStack_100 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_100;
  ExceptionList = &local_10;
  local_d0 = 0;
  local_d8[0] = param_1;
  local_8 = 0;
  local_18 = uStack_100;
  GetCurrentThreadId();
  local_cc = (int *)&stack0xfffffef4;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar14 = extraout_ECX;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("Ports.cpp");
    *piVar5 = iVar6;
    piVar14 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar14 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffef0,0x1002f2f4);
  pvVar8 = *(void **)(*local_d8[1] + 4);
  local_8._0_1_ = 3;
  if (pvVar8 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar8 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar8,piVar14,piVar5);
  GetCurrentThreadId();
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_cc = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar14 = extraout_ECX_02;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("Ports.cpp");
    *piVar5 = iVar6;
    piVar14 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar14 = extraout_ECX_04;
  }
  uVar19 = 4;
  uVar18 = 1;
  local_cc = (int *)&stack0xfffffee8;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffee8,0x1002f2c4);
  pvVar8 = *(void **)(*local_d8[1] + 4);
  local_8._0_1_ = 6;
  if (pvVar8 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar8 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar8,piVar14,uVar18,uVar19,piVar5);
  this = local_d8[0];
  local_cc = (int *)0x1;
LAB_100160f4:
  do {
    if ((int *)0x8 < local_cc) break;
    swprintf_s(&local_2c,10,L"COM%d");
    swprintf_s(local_ac,0x40,L"");
    DVar7 = QueryDosDeviceW(&local_2c,local_ac,0x80);
    if ((DVar7 != 0) && (local_ac[0] != L'\0')) {
      pvVar8 = operator_new(0x24);
      local_8._0_1_ = 7;
      if (pvVar8 == (void *)0x0) {
        puVar9 = (uint *)0x0;
      }
      else {
        pwVar10 = &local_2c;
        local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
        local_b4 = 7;
        local_b8 = 0;
        do {
          wVar1 = *pwVar10;
          pwVar10 = pwVar10 + 1;
        } while (wVar1 != L'\0');
        FUN_10003130(local_c8,(int *)&local_2c,(int)pwVar10 - (int)local_2a >> 1);
        local_d0 = local_d0 | 1;
        local_8 = CONCAT31(local_8._1_3_,8);
        puVar9 = FUN_100158d0(pvVar8,*local_d8[1],(int *)local_c8);
      }
      local_8 = 0;
      local_d8[0] = puVar9;
      if (((local_d0 & 1) != 0) && (local_d0 = local_d0 & 0xfffffffe, 7 < local_b4)) {
        operator_delete(local_c8[0]);
      }
      if (puVar9 == (uint *)0x0) {
        pwVar10 = (wchar_t *)FUN_10015ac0();
        local_8._0_1_ = 10;
        if (7 < *(uint *)(pwVar10 + 10)) {
          pwVar10 = *(wchar_t **)pwVar10;
        }
        FUN_10015000((void *)*local_d8[1],0x401,0x80004005,0x1002f2f4,L"Ports.cpp",
                     (undefined1 *)0xf1,pwVar10);
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_b4) {
          operator_delete(local_c8[0]);
        }
      }
      ppuVar2 = (uint **)this[1];
      if ((local_d8 < ppuVar2) && (ppuVar3 = (uint **)*this, ppuVar3 <= local_d8)) {
        if (ppuVar2 == (uint **)this[2]) {
          FUN_10015a60(this,1);
        }
        if ((undefined4 *)this[1] != (undefined4 *)0x0) {
          *(undefined4 *)this[1] = *(undefined4 *)(*this + ((int)local_d8 - (int)ppuVar3 >> 2) * 4);
          this[1] = this[1] + 4;
          local_cc = (int *)((int)local_cc + 1);
          goto LAB_100160f4;
        }
      }
      else {
        if (ppuVar2 == (uint **)this[2]) {
          FUN_10015a60(this,1);
        }
        if ((undefined4 *)this[1] != (undefined4 *)0x0) {
          *(undefined4 *)this[1] = puVar9;
        }
      }
      this[1] = this[1] + 4;
    }
    local_cc = (int *)((int)local_cc + 1);
  } while( true );
  pvVar8 = operator_new(0x24);
  local_8._0_1_ = 0xb;
  if (pvVar8 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    local_b4 = 7;
    local_b8 = 0;
    local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
    FUN_10003130(local_c8,(int *)L"COM Port Auto Detect",0x14);
    local_d0 = local_d0 | 2;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    piVar5 = FUN_100158d0(pvVar8,*local_d8[1],(int *)local_c8);
  }
  local_8 = 0;
  local_cc = piVar5;
  if (((local_d0 & 2) != 0) && (7 < local_b4)) {
    operator_delete(local_c8[0]);
  }
  if (piVar5 == (int *)0x0) {
    pwVar10 = (wchar_t *)FUN_10015ac0();
    local_8._0_1_ = 0xe;
    if (7 < *(uint *)(pwVar10 + 10)) {
      pwVar10 = *(wchar_t **)pwVar10;
    }
    FUN_10015000((void *)*local_d8[1],0x401,0x80004005,0x1002f284,L"Ports.cpp",(undefined1 *)0x103,
                 pwVar10);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_b4) {
      operator_delete(local_c8[0]);
    }
  }
  ppiVar4 = (int **)this[1];
  if (&local_cc < ppiVar4) {
    ppiVar17 = (int **)*this;
    if (ppiVar17 <= &local_cc) {
      ppiVar15 = (int **)this[2];
      iVar6 = (int)&local_cc - (int)ppiVar17;
      if (ppiVar4 == ppiVar15) {
        uVar11 = (int)ppiVar4 - (int)ppiVar17 >> 2;
        if (0x3ffffffe < uVar11) {
          std::_Xlength_error("vector<T> too long");
          uVar11 = extraout_EAX_01;
          ppiVar15 = extraout_ECX_05;
          ppiVar17 = extraout_EDX;
        }
        pcVar12 = (char *)(uVar11 + 1);
        pcVar16 = (char *)((int)ppiVar15 - (int)ppiVar17 >> 2);
        if (pcVar16 < pcVar12) {
          if ((char *)(0x3fffffff - ((uint)pcVar16 >> 1)) < pcVar16) {
            pcVar16 = (char *)0x0;
          }
          else {
            pcVar16 = pcVar16 + ((uint)pcVar16 >> 1);
          }
          if (pcVar16 < pcVar12) {
            pcVar16 = pcVar12;
          }
          FUN_100159d0(this,pcVar16);
        }
      }
      if ((undefined4 *)this[1] != (undefined4 *)0x0) {
        *(undefined4 *)this[1] = *(undefined4 *)(*this + (iVar6 >> 2) * 4);
      }
      goto LAB_10016477;
    }
  }
  ppiVar17 = (int **)this[2];
  if (ppiVar4 == ppiVar17) {
    uVar11 = *this;
    uVar13 = (int)((int)ppiVar4 - uVar11) >> 2;
    if (0x3ffffffe < uVar13) {
      std::_Xlength_error("vector<T> too long");
      uVar13 = extraout_EAX_02;
      ppiVar17 = extraout_ECX_06;
      uVar11 = extraout_EDX_00;
    }
    pcVar12 = (char *)(uVar13 + 1);
    pcVar16 = (char *)((int)((int)ppiVar17 - uVar11) >> 2);
    if (pcVar16 < pcVar12) {
      if ((char *)(0x3fffffff - ((uint)pcVar16 >> 1)) < pcVar16) {
        pcVar16 = (char *)0x0;
      }
      else {
        pcVar16 = pcVar16 + ((uint)pcVar16 >> 1);
      }
      if (pcVar16 < pcVar12) {
        pcVar16 = pcVar12;
      }
      FUN_100159d0(this,pcVar16);
    }
  }
  if ((undefined4 *)this[1] != (undefined4 *)0x0) {
    *(undefined4 *)this[1] = piVar5;
  }
LAB_10016477:
  this[1] = this[1] + 4;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100164f1 at 100164f1

undefined * Catch_100164f1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0xec),"Ports.cpp",0x107,"CPorts::getSerialPorts",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1001653f;
}



// Function: Catch_All@10016544 at 10016544

undefined4 Catch_All_10016544(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0xe8) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0xe4) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0xe0) = 0;
  *(undefined4 *)(unaff_EBP + -0xdc) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_10020630((void *)(unaff_EBP + -0xe8),"Ports.cpp",0x107,"CPorts::getSerialPorts",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x100165bd;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xe8));
  return 0x1001647b;
}



// Function: FUN_100165d0 at 100165d0

/* WARNING: Type propagation algorithm not settling */

void FUN_100165d0(uint *param_1)

{
  uint **ppuVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  void *extraout_EAX;
  void *extraout_EAX_00;
  LONG LVar6;
  IUnknownVtbl *pIVar7;
  uint *puVar8;
  uint uVar9;
  void *pvVar10;
  wchar_t *pwVar11;
  uint uVar12;
  uint extraout_EAX_01;
  char *pcVar13;
  uint extraout_EAX_02;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar14;
  uint **extraout_ECX_05;
  uint **ppuVar15;
  char *pcVar16;
  uint **extraout_ECX_06;
  uint **ppuVar17;
  uint **extraout_EDX;
  uint extraout_EDX_00;
  undefined4 uVar18;
  undefined4 uVar19;
  uint uStack_94;
  int local_6c;
  uint local_68;
  int *local_64;
  int *local_60;
  uint *local_5c [3];
  void *local_50 [5];
  uint local_3c;
  void *local_34 [3];
  undefined1 local_28 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1002510d;
  local_10 = ExceptionList;
  uStack_94 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_94;
  ExceptionList = &local_10;
  local_68 = 0;
  local_5c[0] = param_1;
  local_8 = 0;
  local_18 = uStack_94;
  GetCurrentThreadId();
  local_5c[2] = (uint *)&stack0xffffff60;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_5c[1] = (uint *)piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar14 = extraout_ECX;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("Ports.cpp");
    *piVar4 = iVar5;
    piVar14 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar14 = extraout_ECX_01;
  }
  local_5c[1] = (uint *)&stack0xffffff5c;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff5c,0x1002f408);
  pvVar10 = *(void **)(*local_60 + 4);
  local_8._0_1_ = 3;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar10,piVar14,piVar4);
  GetCurrentThreadId();
  local_5c[2] = (uint *)&stack0xffffff60;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_5c[1] = (uint *)piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar14 = extraout_ECX_02;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("Ports.cpp");
    *piVar4 = iVar5;
    piVar14 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar14 = extraout_ECX_04;
  }
  uVar19 = 4;
  uVar18 = 2;
  local_5c[1] = (uint *)&stack0xffffff54;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff54,0x1002f3e4);
  piVar3 = local_60;
  pvVar10 = *(void **)(*local_60 + 4);
  local_8._0_1_ = 6;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar10,piVar14,uVar18,uVar19,piVar4);
  local_64 = (int *)0x0;
  FUN_10001f10(local_5c + 1,0x1002f3ac);
  local_8._0_1_ = 7;
  FUN_10001f10(local_5c + 2,0x1002f3a4);
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar5 = (**(code **)(*(int *)piVar3[2] + 0x50))();
  puVar8 = local_5c[2];
  if (local_5c[2] != (uint *)0x0) {
    LVar6 = InterlockedDecrement((LONG *)(local_5c[2] + 2));
    if ((LVar6 == 0) && (puVar8 != (uint *)0x0)) {
      if (*puVar8 != 0) {
        Ordinal_6(*puVar8);
      }
      if ((void *)puVar8[1] != (void *)0x0) {
        operator_delete__((void *)puVar8[1]);
      }
      operator_delete(puVar8);
    }
    local_5c[2] = (uint *)0x0;
  }
  puVar8 = local_5c[1];
  local_8 = local_8 & 0xffffff00;
  if (((local_5c[1] != (uint *)0x0) &&
      (LVar6 = InterlockedDecrement((LONG *)(local_5c[1] + 2)), LVar6 == 0)) &&
     (puVar8 != (uint *)0x0)) {
    if (*puVar8 != 0) {
      Ordinal_6(*puVar8);
    }
    if ((void *)puVar8[1] != (void *)0x0) {
      operator_delete__((void *)puVar8[1]);
    }
    operator_delete(puVar8);
  }
  if (iVar5 < 0) {
    pIVar7 = (IUnknownVtbl *)FUN_10015ac0();
    local_8._0_1_ = 9;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar7 + 0x14))->lpVtbl) {
      pIVar7 = ((IUnknown *)pIVar7)->lpVtbl;
    }
    FUN_10014d70((void *)*local_60,0x400,0x20,(IUnknown *)pIVar7,
                 (IUnknown *)L"CPorts::detectUSBPort()",(int *)0x4,(IID *)0x0,(int *)L"Ports.cpp",
                 (undefined1 *)0x11e);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_20) {
      operator_delete(local_34[0]);
    }
  }
  bVar2 = false;
  local_6c = 0;
  while (puVar8 = local_5c[0], local_64 != (int *)0x0) {
    local_5c[1] = (uint *)0x0;
    (**(code **)(*local_64 + 0x10))(local_64,0xffffffff,1,local_5c + 1,&local_6c);
    if (local_6c == 0) break;
    Ordinal_8(local_28);
    (**(code **)(*local_5c[1] + 0x10))(local_5c[1],L"DeviceID",0,local_28,0,0);
    uVar12 = local_20;
    puVar8 = (uint *)operator_new(0xc);
    local_8 = CONCAT31(local_8._1_3_,10);
    if (puVar8 == (uint *)0x0) {
LAB_1001690e:
      puVar8 = (uint *)0x0;
    }
    else {
      puVar8[1] = 0;
      puVar8[2] = 1;
      uVar9 = Ordinal_2(uVar12);
      *puVar8 = uVar9;
      if ((uVar9 == 0) && (uVar12 != 0)) {
        _com_issue_error(-0x7ff8fff2);
        goto LAB_1001690e;
      }
    }
    local_8 = local_8 & 0xffffff00;
    local_5c[2] = puVar8;
    if (puVar8 == (uint *)0x0) {
      _com_issue_error(-0x7ff8fff2);
    }
    local_8._0_1_ = 0xb;
    FUN_1001f420((undefined2 *)local_50,(int *)(local_5c + 2));
    puVar8 = local_5c[2];
    local_8 = CONCAT31(local_8._1_3_,0xd);
    if (local_5c[2] != (uint *)0x0) {
      LVar6 = InterlockedDecrement((LONG *)(local_5c[2] + 2));
      if ((LVar6 == 0) && (puVar8 != (uint *)0x0)) {
        if (*puVar8 != 0) {
          Ordinal_6(*puVar8);
        }
        if ((void *)puVar8[1] != (void *)0x0) {
          operator_delete__((void *)puVar8[1]);
        }
        operator_delete(puVar8);
      }
      local_5c[2] = (uint *)0x0;
    }
    Ordinal_9(local_28);
    if (local_5c[1] != (uint *)0x0) {
      (**(code **)(*local_5c[1] + 8))(local_5c[1]);
      local_5c[1] = (uint *)0x0;
    }
    bVar2 = true;
    local_8 = local_8 & 0xffffff00;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
  }
  if (bVar2) {
    pvVar10 = operator_new(0x24);
    local_8._0_1_ = 0xe;
    if (pvVar10 == (void *)0x0) {
      local_5c[0] = (uint *)0x0;
    }
    else {
      local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
      local_20 = 7;
      local_24 = 0;
      FUN_10003130(local_34,(int *)&DAT_1002a064,3);
      local_68 = local_68 | 1;
      local_8 = CONCAT31(local_8._1_3_,0xf);
      local_5c[0] = FUN_100158d0(pvVar10,*local_60,(int *)local_34);
    }
    local_8 = 0;
    local_5c[2] = local_5c[0];
    if (((local_68 & 1) != 0) && (7 < local_20)) {
      operator_delete(local_34[0]);
    }
    if (local_5c[2] == (uint *)0x0) {
      pwVar11 = (wchar_t *)FUN_10015ac0();
      local_8._0_1_ = 0x11;
      if (7 < *(uint *)(pwVar11 + 10)) {
        pwVar11 = *(wchar_t **)pwVar11;
      }
      FUN_10015000((void *)*local_60,0x401,0x80004005,0x1002f338,L"Ports.cpp",(undefined1 *)0x149,
                   pwVar11);
      local_8 = (uint)local_8._1_3_ << 8;
      if (7 < local_3c) {
        operator_delete(local_50[0]);
      }
    }
    ppuVar1 = (uint **)puVar8[1];
    if ((local_5c < ppuVar1) && (ppuVar17 = (uint **)*puVar8, ppuVar17 <= local_5c)) {
      ppuVar15 = (uint **)puVar8[2];
      iVar5 = (int)local_5c - (int)ppuVar17;
      if (ppuVar1 == ppuVar15) {
        uVar12 = (int)ppuVar1 - (int)ppuVar17 >> 2;
        if (0x3ffffffe < uVar12) {
          std::_Xlength_error("vector<T> too long");
          uVar12 = extraout_EAX_01;
          ppuVar15 = extraout_ECX_05;
          ppuVar17 = extraout_EDX;
        }
        pcVar13 = (char *)(uVar12 + 1);
        pcVar16 = (char *)((int)ppuVar15 - (int)ppuVar17 >> 2);
        if (pcVar16 < pcVar13) {
          if ((char *)(0x3fffffff - ((uint)pcVar16 >> 1)) < pcVar16) {
            pcVar16 = (char *)0x0;
          }
          else {
            pcVar16 = pcVar16 + ((uint)pcVar16 >> 1);
          }
          if (pcVar16 < pcVar13) {
            pcVar16 = pcVar13;
          }
          FUN_100159d0(puVar8,pcVar16);
        }
      }
      if ((undefined4 *)puVar8[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar8[1] = *(undefined4 *)(*puVar8 + (iVar5 >> 2) * 4);
      }
    }
    else {
      ppuVar17 = (uint **)puVar8[2];
      if (ppuVar1 == ppuVar17) {
        uVar12 = *puVar8;
        uVar9 = (int)((int)ppuVar1 - uVar12) >> 2;
        if (0x3ffffffe < uVar9) {
          std::_Xlength_error("vector<T> too long");
          uVar9 = extraout_EAX_02;
          ppuVar17 = extraout_ECX_06;
          uVar12 = extraout_EDX_00;
        }
        pcVar13 = (char *)(uVar9 + 1);
        pcVar16 = (char *)((int)((int)ppuVar17 - uVar12) >> 2);
        if (pcVar16 < pcVar13) {
          if ((char *)(0x3fffffff - ((uint)pcVar16 >> 1)) < pcVar16) {
            pcVar16 = (char *)0x0;
          }
          else {
            pcVar16 = pcVar16 + ((uint)pcVar16 >> 1);
          }
          if (pcVar16 < pcVar13) {
            pcVar16 = pcVar13;
          }
          FUN_100159d0(puVar8,pcVar16);
        }
      }
      if ((undefined4 *)puVar8[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar8[1] = local_5c[2];
      }
    }
    puVar8[1] = puVar8[1] + 4;
  }
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 8))(local_64);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10016b9b at 10016b9b

undefined * Catch_10016b9b(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x80),"Ports.cpp",0x150,"CPorts::getUSBPort",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10016be6;
}



// Function: Catch_All@10016be8 at 10016be8

undefined4 Catch_All_10016be8(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x7c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  FUN_10020630((void *)(unaff_EBP + -0x7c),"Ports.cpp",0x150,"CPorts::getUSBPort",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10016c4f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return 0x10016b7d;
}



// Function: FUN_10016c60 at 10016c60

void __thiscall FUN_10016c60(void *this,uint *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  int *piVar4;
  void *extraout_EAX_00;
  void *pvVar5;
  wchar_t *pwVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10025186;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar4 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("Ports.cpp");
    *piVar2 = iVar3;
    piVar4 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar4 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x1002f558);
                    /* WARNING: Load size is inaccurate */
  pvVar5 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar4,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)&stack0xffffff8c;
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar3 = ConvertStringToBSTR("Ports.cpp");
    *piVar4 = iVar3;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar2 = extraout_ECX_02;
  }
  uVar8 = 4;
  uVar7 = 2;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x1002f4b8);
                    /* WARNING: Load size is inaccurate */
  pvVar5 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar5,piVar2,uVar7,uVar8,piVar4);
  FUN_10015b50();
  FUN_100165d0(param_1);
  FUN_10015f50(param_1);
  if ((param_1[1] - *param_1 & 0xfffffffc) == 0) {
    pwVar6 = (wchar_t *)FUN_10015ac0();
    local_8._0_1_ = 7;
    if (7 < *(uint *)(pwVar6 + 10)) {
      pwVar6 = *(wchar_t **)pwVar6;
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10015000(*this,0x402,0x80004005,0x1002f48c,L"Ports.cpp",(undefined1 *)0x56,pwVar6);
    if (7 < local_20) {
      operator_delete(local_34);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10016e4c at 10016e4c

undefined * Catch_10016e4c(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"Ports.cpp",0x59,"CPorts::DetectPorts",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10016e94;
}



// Function: Catch_All@10016e96 at 10016e96

undefined4 Catch_All_10016e96(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10020630((void *)(unaff_EBP + -0x50),"Ports.cpp",0x59,"CPorts::DetectPorts",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10016efa;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x10016e2e;
}



// Function: FUN_10016f00 at 10016f00

uint __thiscall FUN_10016f00(void *this,undefined4 *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
                    /* WARNING: Load size is inaccurate */
  uVar5 = Ordinal_7(*this);
  uVar6 = Ordinal_7(*param_1);
  uVar7 = uVar5;
  if (uVar6 < uVar5) {
    uVar7 = uVar6;
  }
                    /* WARNING: Load size is inaccurate */
  puVar3 = *this;
  puVar4 = (ushort *)*param_1;
  while (puVar2 = puVar4, puVar1 = puVar3, uVar7 != 0) {
    uVar7 = uVar7 - 1;
    puVar3 = puVar1 + 1;
    puVar4 = puVar2 + 1;
    if (*puVar1 != *puVar2) {
      return (uint)*puVar1 - (uint)*puVar2;
    }
  }
  if (uVar6 <= uVar5) {
    return (uint)(uVar5 != uVar6);
  }
  return 0xffffffff;
}



// Function: FUN_10016f90 at 10016f90

void * __thiscall FUN_10016f90(void *this,void *param_1)

{
  int iVar1;
  undefined1 local_18 [16];
  undefined4 local_8;
  
  local_8 = 0;
  Ordinal_8(local_18);
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x78))(this,local_18);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002f654);
  }
  memcpy_s(param_1,0x10,local_18,0x10);
  return param_1;
}



// Function: FUN_10016ff0 at 10016ff0

void __fastcall FUN_10016ff0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10017000 at 10017000

void __thiscall FUN_10017000(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_8 = 0;
  iVar1 = (**(code **)(*this + 0x30))(this,&local_8);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002f654);
    *param_1 = local_8;
    return;
  }
  *param_1 = local_8;
  return;
}



// Function: FUN_10017050 at 10017050

void __thiscall FUN_10017050(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x1c))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002f664);
    *param_1 = 0;
    return;
  }
  *param_1 = 0;
  return;
}



// Function: FUN_100170b0 at 100170b0

void __thiscall FUN_100170b0(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_8 = 0;
  iVar1 = (**(code **)(*this + 0xb4))(this,&local_8);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002f644);
    *param_1 = local_8;
    return;
  }
  *param_1 = local_8;
  return;
}



// Function: FUN_10017110 at 10017110

void __fastcall FUN_10017110(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (7 < *(uint *)(param_1 + 0x18)) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  return;
}



// Function: FUN_10017150 at 10017150

int * __thiscall FUN_10017150(void *this,uint param_1,int *param_2,uint param_3,uint param_4)

{
  code *pcVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  uint extraout_ECX;
  uint uVar6;
  
  uVar6 = *(uint *)((int)this + 0x10);
  if ((param_1 <= uVar6) && (param_3 <= (uint)param_2[4])) {
    uVar2 = param_2[4] - param_3;
    if (uVar2 < param_4) {
      param_4 = uVar2;
    }
    if (-uVar6 - 1 <= param_4) {
      std::_Xlength_error("string too long");
      uVar6 = extraout_ECX;
    }
    if (param_4 != 0) {
      uVar6 = uVar6 + param_4;
      if (0x7ffffffe < uVar6) {
        std::_Xlength_error("string too long");
      }
      if (*(uint *)((int)this + 0x14) < uVar6) {
        FUN_100022b0(this,uVar6);
        if (uVar6 == 0) {
          return (int *)this;
        }
      }
      else if (uVar6 == 0) {
        *(undefined4 *)((int)this + 0x10) = 0;
        if (*(uint *)((int)this + 0x14) < 8) {
          *(undefined2 *)this = 0;
          return (int *)this;
        }
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      pvVar3 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
        pvVar4 = *this;
      }
      FUN_10001be0((void *)((int)pvVar3 + (param_1 + param_4) * 2),
                   (void *)((int)pvVar4 + param_1 * 2),*(int *)((int)this + 0x10) - param_1);
      if ((int *)this == param_2) {
        uVar2 = param_3 + param_4;
        if (param_3 <= param_1) {
          uVar2 = param_3;
        }
        if (*(uint *)((int)this + 0x14) < 8) {
          FUN_10001be0((void *)((int)this + param_1 * 2),(void *)((int)this + uVar2 * 2),param_4);
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          FUN_10001be0((void *)(*this + param_1 * 2),(void *)(*this + uVar2 * 2),param_4);
        }
      }
      else {
        if (7 < (uint)param_2[5]) {
          param_2 = (int *)*param_2;
        }
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        memcpy((void *)((int)pvVar4 + param_1 * 2),(void *)((int)param_2 + param_3 * 2),param_4 * 2)
        ;
      }
      FUN_10001fe0(this,uVar6);
    }
    return (int *)this;
  }
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  piVar5 = (int *)(*pcVar1)();
  return piVar5;
}



// Function: FUN_100172d0 at 100172d0

int * __thiscall FUN_100172d0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  LONG LVar3;
  
  if ((int *)this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if (piVar1 != (int *)0x0) {
      LVar3 = InterlockedDecrement(piVar1 + 2);
      if ((LVar3 == 0) && (piVar1 != (int *)0x0)) {
        if (*piVar1 != 0) {
          Ordinal_6(*piVar1);
        }
        if ((void *)piVar1[1] != (void *)0x0) {
          operator_delete__((void *)piVar1[1]);
        }
        operator_delete(piVar1);
      }
      *(undefined4 *)this = 0;
    }
    iVar2 = *param_1;
    *(int *)this = iVar2;
    if (iVar2 != 0) {
      InterlockedIncrement((LONG *)(iVar2 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_10017340 at 10017340

int * __thiscall FUN_10017340(void *this,int param_1)

{
  uint uVar1;
  LONG LVar2;
  int *piVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100251bb;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  if (param_1 != 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = **this;
    }
    if (iVar4 == param_1) {
      return (int *)this;
    }
  }
                    /* WARNING: Load size is inaccurate */
  piVar3 = *this;
  ExceptionList = &local_10;
  if (piVar3 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar3 + 2);
    if ((LVar2 == 0) && (piVar3 != (int *)0x0)) {
      if (*piVar3 != 0) {
        Ordinal_6(*piVar3,uVar1);
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        operator_delete__((void *)piVar3[1]);
      }
      operator_delete(piVar3);
    }
    *(undefined4 *)this = 0;
  }
  piVar3 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar3 != (int *)0x0) {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = Ordinal_2(param_1);
    *piVar3 = iVar4;
    if ((iVar4 != 0) || (param_1 == 0)) goto LAB_1001740f;
    _com_issue_error(-0x7ff8fff2);
  }
  piVar3 = (int *)0x0;
LAB_1001740f:
  local_8 = 0xffffffff;
  *(int **)this = piVar3;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10017440 at 10017440

void * __thiscall FUN_10017440(void *this,short *param_1)

{
  int iVar1;
  short local_20 [4];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100251e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*param_1 == 8) {
    FUN_10017340(this,*(int *)(param_1 + 4));
  }
  else {
    Ordinal_8(local_20,DAT_1003af5c ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if ((local_20 != param_1) || (local_20[0] != 8)) {
      iVar1 = Ordinal_12(local_20,param_1,0,8);
      if (iVar1 < 0) {
        _com_issue_error(iVar1);
      }
    }
    FUN_10017340(this,local_18);
    Ordinal_9(local_20);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100174f0 at 100174f0

undefined4 * __thiscall FUN_100174f0(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_1002486b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x1c))(this,&local_14,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_1002f654);
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
  local_8 = 0xffffffff;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100175a0 at 100175a0

undefined4 __thiscall FUN_100175a0(void *this,int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025218;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar2 = (**(code **)(*this + 0x104))(this,iVar2,&local_14,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_1002f644);
    iVar2 = extraout_EAX;
  }
  uVar1 = (undefined2)local_14;
  if (param_1 != (int *)0x0) {
    iVar2 = InterlockedDecrement(param_1 + 2);
    if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
      if (*param_1 != 0) {
        Ordinal_6(*param_1);
      }
      if ((void *)param_1[1] != (void *)0x0) {
        operator_delete__((void *)param_1[1]);
      }
      operator_delete(param_1);
      iVar2 = extraout_EAX_00;
    }
  }
  ExceptionList = local_10;
  return CONCAT22((short)((uint)iVar2 >> 0x10),uVar1);
}



// Function: FUN_10017660 at 10017660

undefined4 * __thiscall FUN_10017660(void *this,undefined4 param_1,int *param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 0x18) = 7;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  FUN_10003030((undefined2 *)((int)this + 4),param_2,0,0xffffffff);
  *(undefined4 *)((int)this + 0x20) = 0;
  return (undefined4 *)this;
}



// Function: FUN_100176a0 at 100176a0

void FUN_100176a0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003ad58);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017730 at 10017730

void __thiscall FUN_10017730(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100257b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000bb20(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)(*this + (((int)param_1 - (int)puVar2) / 0x1c) * 0x1c);
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined2 *)0x0) goto LAB_100177f3;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000bb20(this,1);
    }
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined2 *)0x0) goto LAB_100177f3;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  FUN_10004710(this_00,param_1);
LAB_100177f3:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017810 at 10017810

void __thiscall FUN_10017810(void *this,int *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  IUnknownVtbl *pIVar3;
  void *extraout_EAX_01;
  void *pvVar4;
  int *piVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_6c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002529e;
  local_10 = ExceptionList;
  uStack_6c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_6c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_6c;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Protocol.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff84,0x1002f758);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar5,piVar1);
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("Protocol.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_04;
  }
  uVar7 = 4;
  uVar6 = 0;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff7c,0x1002f730);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar5,uVar6,uVar7,piVar1);
  if (((int *)*param_1 != (int *)0x0) && (*(int *)*param_1 != 0)) {
    iVar2 = Ordinal_7();
    if (iVar2 != 0) {
      if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = *(int **)*param_1;
      }
      local_20 = 7;
      local_24 = 0;
      local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
      piVar5 = piVar1;
      do {
        iVar2 = *piVar5;
        piVar5 = (int *)((int)piVar5 + 2);
      } while ((short)iVar2 != 0);
      FUN_10003130(local_34,piVar1,(int)piVar5 - ((int)piVar1 + 2) >> 1);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_10017730(param_2,local_34);
      if (7 < local_20) {
        operator_delete(local_34[0]);
      }
      goto LAB_10017a35;
    }
  }
  pIVar3 = (IUnknownVtbl *)FUN_100176a0();
  local_8._0_1_ = 7;
  if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
    pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
  }
                    /* WARNING: Load size is inaccurate */
  FUN_10014d70(*this,0x40a,0x20,(IUnknown *)pIVar3,(IUnknown *)L"CProtocol::validateProtocol",
               (int *)0x4,(IID *)0x0,(int *)L"Protocol.cpp",(undefined1 *)0xca);
  local_8._0_1_ = 0;
  if (7 < local_20) {
    operator_delete(local_34[0]);
  }
  GetCurrentThreadId();
  piVar5 = extraout_ECX_05;
  FUN_10001e80(&stack0xffffff88,"Protocol.cpp");
  uVar7 = 4;
  uVar6 = 0;
  local_8._0_1_ = 8;
  piVar1 = extraout_ECX_06;
  FUN_10001f10(&stack0xffffff7c,0x1002f690);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 9;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar4,piVar1,uVar6,uVar7,piVar5);
LAB_10017a35:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10017ab1 at 10017ab1

undefined * Catch_10017ab1(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x58),"Protocol.cpp",0xe5,"CProtocol::validateProtocol",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10017afc;
}



// Function: Catch_All@10017b01 at 10017b01

undefined4 Catch_All_10017b01(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x54) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x50) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10020630((void *)(unaff_EBP + -0x54),"Protocol.cpp",0xe5,"CProtocol::validateProtocol",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10017b68;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x54));
  return 0x10017a35;
}



// Function: FUN_10017b70 at 10017b70

void FUN_10017b70(int *param_1)

{
  short sVar1;
  IUnknown *This;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  HRESULT HVar5;
  wchar_t *pwVar6;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  ushort **ppuVar7;
  uint uVar8;
  IUnknownVtbl *pIVar9;
  void *extraout_EAX_04;
  void *pvVar10;
  IUnknown *extraout_EAX_05;
  IUnknown *pIVar11;
  ULONG UVar12;
  undefined4 *puVar13;
  LONG LVar14;
  short *psVar15;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar16;
  int *extraout_ECX_08;
  void *extraout_ECX_09;
  int *extraout_ECX_10;
  int *extraout_ECX_11;
  void *extraout_ECX_12;
  int *extraout_ECX_13;
  IUnknown *extraout_ECX_14;
  void **ppvObject;
  IUnknown *this;
  undefined4 uVar17;
  undefined4 uVar18;
  uint uStack_a4;
  undefined1 local_90 [16];
  int local_80;
  int local_7c;
  int *local_78;
  int *local_74;
  IUnknown *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int *local_60;
  IUnknown *local_5c;
  int *local_58;
  int *local_54;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100253a7;
  local_10 = ExceptionList;
  uStack_a4 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a4;
  ExceptionList = &local_10;
  local_64 = param_1;
  local_8 = 0;
  local_18 = uStack_a4;
  GetCurrentThreadId();
  local_60 = (int *)&stack0xffffff50;
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_54 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar16 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("Protocol.cpp");
    *piVar3 = iVar4;
    piVar16 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar16 = extraout_ECX_01;
  }
  local_54 = (int *)&stack0xffffff4c;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff4c,0x1002f890);
  pvVar10 = *(void **)(*local_58 + 4);
  local_8._0_1_ = 3;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar10,piVar16,piVar3);
  GetCurrentThreadId();
  local_60 = (int *)&stack0xffffff50;
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_54 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar16 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("Protocol.cpp");
    *piVar3 = iVar4;
    piVar16 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar16 = extraout_ECX_04;
  }
  uVar18 = 4;
  iVar4 = 2;
  local_54 = (int *)&stack0xffffff44;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff44,0x1002f850);
  pvVar10 = *(void **)(*local_58 + 4);
  local_8._0_1_ = 6;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar10,piVar16,iVar4,uVar18,piVar3);
  GetCurrentThreadId();
  local_60 = (int *)&stack0xffffff50;
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 7;
  local_54 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar16 = extraout_ECX_05;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("Protocol.cpp");
    *piVar3 = iVar4;
    piVar16 = extraout_ECX_06;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar16 = extraout_ECX_07;
  }
  uVar18 = 4;
  iVar4 = 0;
  local_54 = (int *)&stack0xffffff44;
  local_8._0_1_ = 8;
  FUN_10001f10(&stack0xffffff44,0x1002f7f8);
  piVar2 = local_58;
  pvVar10 = *(void **)(*local_58 + 4);
  local_8._0_1_ = 9;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX_01;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar10,piVar16,iVar4,uVar18,piVar3);
  piVar3 = (int *)piVar2[8];
  ppvObject = (void **)(piVar2 + 8);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  HVar5 = CoCreateInstance((IID *)&DAT_1002f634,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10028450,&local_5c);
  if (-1 < HVar5) {
    HVar5 = OleRun(local_5c);
    if (-1 < HVar5) {
      HVar5 = (*local_5c->lpVtbl->QueryInterface)(local_5c,(IID *)&DAT_1002f644,ppvObject);
    }
    (*local_5c->lpVtbl->Release)(local_5c);
    if (-1 < HVar5) goto LAB_10017e1a;
  }
  *ppvObject = (void *)0x0;
  if (HVar5 < 0) {
    pwVar6 = (wchar_t *)FUN_100176a0();
    local_8._0_1_ = 10;
    if (7 < *(uint *)(pwVar6 + 10)) {
      pwVar6 = *(wchar_t **)pwVar6;
    }
    FUN_10015000((void *)*local_58,0x407,0x80004005,0x10029e34,L"Protocol.cpp",(undefined1 *)0x55,
                 pwVar6);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_20) {
      operator_delete(local_34[0]);
    }
  }
LAB_10017e1a:
  piVar3 = (int *)*ppvObject;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar3 = extraout_EAX_02;
  }
  (**(code **)(*piVar3 + 0x110))();
  piVar3 = (int *)*ppvObject;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar3 = extraout_EAX_03;
  }
  (**(code **)(*piVar3 + 0x120))();
  piVar3 = local_58;
  if ((*ppvObject != (void *)0x0) && (local_58[5] != 0)) {
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    piVar16 = local_58 + 1;
    local_3c = 7;
    local_40 = 0;
    FUN_10003030(local_50,piVar16,0,0xffffffff);
    local_8._0_1_ = 0xb;
    ppuVar7 = (ushort **)DAT_1003ad84;
    if (DAT_1003ad98 < 8) {
      ppuVar7 = &DAT_1003ad84;
    }
    uVar8 = FUN_100137e0(local_50,(ushort *)ppuVar7,0,DAT_1003ad94);
    FUN_10017150(local_50,uVar8,&DAT_1003ad68,0,0xffffffff);
    if (7 < (uint)piVar3[6]) {
      piVar16 = (int *)*piVar16;
    }
    local_60 = (int *)&stack0xffffff48;
    piVar3 = extraout_ECX_08;
    FUN_10001f10(&stack0xffffff48,(int)piVar16);
    pvVar10 = *ppvObject;
    local_8._0_1_ = 0xc;
    if (pvVar10 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar10 = extraout_ECX_09;
    }
    local_8._0_1_ = 0xb;
    uVar18 = FUN_100175a0(pvVar10,piVar3);
    if ((short)uVar18 == 0) {
      pIVar9 = (IUnknownVtbl *)FUN_100176a0();
      local_8._0_1_ = 0xd;
      if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar9 + 0x14))->lpVtbl) {
        pIVar9 = ((IUnknown *)pIVar9)->lpVtbl;
      }
      FUN_10014d70((void *)*local_58,0x408,0x20,(IUnknown *)pIVar9,
                   (IUnknown *)L"CProtocol::GetProtocols",(int *)0x4,(IID *)0x0,
                   (int *)L"Protocol.cpp",(undefined1 *)0x76);
      local_8._0_1_ = 0xb;
      if (7 < local_20) {
        operator_delete(local_34[0]);
      }
      GetCurrentThreadId();
      local_60 = (int *)&stack0xffffff40;
      piVar16 = extraout_ECX_10;
      FUN_10001e80(&stack0xffffff40,"Protocol.cpp");
      uVar17 = 4;
      uVar18 = 0;
      local_54 = (int *)&stack0xffffff34;
      local_8._0_1_ = 0xe;
      piVar3 = extraout_ECX_11;
      FUN_10001f10(&stack0xffffff34,0x10029df0);
      pvVar10 = *(void **)(*local_58 + 4);
      local_8._0_1_ = 0xf;
      if (pvVar10 == (void *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pvVar10 = extraout_EAX_04;
      }
      local_8._0_1_ = 0xb;
      FUN_10005e10(pvVar10,piVar3,uVar18,uVar17,piVar16);
    }
    else {
      pvVar10 = *ppvObject;
      if (pvVar10 == (void *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pvVar10 = extraout_ECX_12;
      }
      FUN_100170b0(pvVar10,(ulong *)&local_54);
      local_8._0_1_ = 0x10;
      piVar3 = local_54;
      if (local_54 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar3 = extraout_ECX_13;
      }
      FUN_10017000(piVar3,(ulong *)&local_70);
      local_5c = (IUnknown *)0x0;
      local_6c = (int *)0x0;
      local_68 = (int *)0x0;
      local_8._0_1_ = 0x14;
      iVar4 = 0;
      while( true ) {
        piVar3 = local_6c;
        pIVar11 = local_70;
        local_80 = iVar4;
        if (local_70 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar11 = extraout_EAX_05;
        }
        local_7c = 0;
        UVar12 = (*pIVar11->lpVtbl[2].Release)(pIVar11);
        if ((int)UVar12 < 0) {
          _com_issue_errorex(UVar12,pIVar11,(_GUID *)&DAT_1002f664);
        }
        piVar16 = local_68;
        if (local_7c <= iVar4) break;
        pIVar11 = local_70;
        if (local_70 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar11 = extraout_ECX_14;
        }
        puVar13 = (undefined4 *)FUN_10017050(pIVar11,&local_60);
        This = local_5c;
        pIVar11 = (IUnknown *)*puVar13;
        this = local_5c;
        if (local_5c != pIVar11) {
          local_5c = pIVar11;
          if (pIVar11 != (IUnknown *)0x0) {
            (*pIVar11->lpVtbl->AddRef)(pIVar11);
          }
          this = pIVar11;
          if (This != (IUnknown *)0x0) {
            (*This->lpVtbl->Release)(This);
          }
        }
        if (local_60 != (int *)0x0) {
          (**(code **)(*local_60 + 8))();
        }
        if (this == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        piVar3 = FUN_100174f0(this,&local_74);
        FUN_100172d0(&local_68,piVar3);
        piVar3 = local_74;
        if (local_74 != (int *)0x0) {
          LVar14 = InterlockedDecrement(local_74 + 2);
          if ((LVar14 == 0) && (piVar3 != (int *)0x0)) {
            if (*piVar3 != 0) {
              Ordinal_6();
            }
            if ((void *)piVar3[1] != (void *)0x0) {
              operator_delete__((void *)piVar3[1]);
            }
            operator_delete(piVar3);
          }
          local_74 = (int *)0x0;
        }
        puVar13 = FUN_10001f10(&local_78,(int)PTR_u_Protocol_1003ad64);
        piVar3 = (int *)*puVar13;
        if (local_68 == piVar3) {
          uVar8 = 0;
        }
        else if (local_68 == (int *)0x0) {
          if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
            iVar4 = Ordinal_7();
            if (iVar4 != 0) {
              uVar8 = 0xffffffff;
              goto LAB_10018150;
            }
          }
          uVar8 = 0;
        }
        else if (piVar3 == (int *)0x0) {
          if (*local_68 != 0) {
            iVar4 = Ordinal_7();
            if (iVar4 != 0) {
              uVar8 = 1;
              goto LAB_10018150;
            }
          }
          uVar8 = 0;
        }
        else {
          uVar8 = FUN_10016f00(local_68,piVar3);
        }
LAB_10018150:
        piVar3 = local_78;
        if (local_78 != (int *)0x0) {
          LVar14 = InterlockedDecrement(local_78 + 2);
          if ((LVar14 == 0) && (piVar3 != (int *)0x0)) {
            if (*piVar3 != 0) {
              Ordinal_6();
            }
            if ((void *)piVar3[1] != (void *)0x0) {
              operator_delete__((void *)piVar3[1]);
            }
            operator_delete(piVar3);
          }
          local_78 = (int *)0x0;
        }
        if (uVar8 != 0) {
          pIVar9 = (IUnknownVtbl *)FUN_100176a0();
          local_8._0_1_ = 0x15;
          if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar9 + 0x14))->lpVtbl) {
            pIVar9 = ((IUnknown *)pIVar9)->lpVtbl;
          }
          FUN_10014d70((void *)*local_58,0x409,0x20,(IUnknown *)pIVar9,
                       (IUnknown *)L"CProtocol::validateProtocol",(int *)0x4,(IID *)0x0,
                       (int *)L"Protocol.cpp",(undefined1 *)0xa3);
          local_8._0_1_ = 0x14;
          if (7 < local_20) {
            operator_delete(local_34[0]);
          }
        }
        psVar15 = (short *)FUN_10016f90(local_5c,local_90);
        local_8._0_1_ = 0x16;
        FUN_10017440(&local_6c,psVar15);
        local_8._0_1_ = 0x14;
        Ordinal_9();
        FUN_10017810(local_58,(int *)&local_6c,local_64);
        iVar4 = local_80 + 1;
      }
      if (local_68 != (int *)0x0) {
        LVar14 = InterlockedDecrement(local_68 + 2);
        if (LVar14 == 0) {
          if (*piVar16 != 0) {
            Ordinal_6();
          }
          if ((void *)piVar16[1] != (void *)0x0) {
            operator_delete__((void *)piVar16[1]);
          }
          operator_delete(piVar16);
        }
      }
      if (piVar3 != (int *)0x0) {
        LVar14 = InterlockedDecrement(piVar3 + 2);
        if (LVar14 == 0) {
          if (*piVar3 != 0) {
            Ordinal_6();
          }
          if ((void *)piVar3[1] != (void *)0x0) {
            operator_delete__((void *)piVar3[1]);
          }
          operator_delete(piVar3);
        }
      }
      local_8._0_1_ = 0x11;
      if (local_5c != (IUnknown *)0x0) {
        (*local_5c->lpVtbl->Release)(local_5c);
      }
      local_8._0_1_ = 0x10;
      if (local_70 != (IUnknown *)0x0) {
        (*local_70->lpVtbl->Release)(local_70);
      }
      local_8._0_1_ = 0xb;
      if (local_54 != (int *)0x0) {
        (**(code **)(*local_54 + 8))();
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
  }
  iVar4 = local_64[1] - *local_64 >> 0x1f;
  if ((local_64[1] - *local_64) / 0x1c + iVar4 == iVar4) {
    local_20 = 7;
    local_24 = 0;
    local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
    psVar15 = (short *)PTR_DAT_1003ad5c;
    do {
      sVar1 = *psVar15;
      psVar15 = psVar15 + 1;
    } while (sVar1 != 0);
    FUN_10003130(local_34,(int *)PTR_DAT_1003ad5c,(int)psVar15 - (int)(PTR_DAT_1003ad5c + 2) >> 1);
    local_8._0_1_ = 0x17;
    FUN_1000bba0(local_64,(int *)local_34);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34[0]);
    }
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    local_20 = 7;
    local_24 = 0;
    local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
    local_3c = 7;
    local_40 = 0;
    psVar15 = (short *)PTR_DAT_1003ad60;
    do {
      sVar1 = *psVar15;
      psVar15 = psVar15 + 1;
    } while (sVar1 != 0);
    FUN_10003130(local_50,(int *)PTR_DAT_1003ad60,(int)psVar15 - (int)(PTR_DAT_1003ad60 + 2) >> 1);
    local_8 = CONCAT31(local_8._1_3_,0x18);
    FUN_1000bba0(local_64,(int *)local_50);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001841b at 1001841b

undefined * Catch_1001841b(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x90),"Protocol.cpp",0xb6,"CProtocol::GetProtocols",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10018469;
}



// Function: Catch_All@1001846b at 1001846b

undefined4 Catch_All_1001846b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x8c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x88) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x84) = 0;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  FUN_10020630((void *)(unaff_EBP + -0x8c),"Protocol.cpp",0xb6,"CProtocol::GetProtocols",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x100184e1;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return 0x100183fd;
}



// Function: FUN_100184f0 at 100184f0

void __fastcall FUN_100184f0(undefined4 *param_1)

{
  *param_1 = CRP1210Connection::vftable;
  if (7 < (uint)param_1[0x1d]) {
    operator_delete((void *)param_1[0x18]);
  }
  param_1[0x1d] = 7;
  param_1[0x1c] = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  if (7 < (uint)param_1[0x16]) {
    operator_delete((void *)param_1[0x11]);
  }
  param_1[0x16] = 7;
  param_1[0x15] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  FUN_1000c150(param_1);
  return;
}



// Function: FUN_10018550 at 10018550

undefined4 * __thiscall FUN_10018550(void *this,byte param_1)

{
  FUN_100184f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10018580 at 10018580

undefined4 * __thiscall FUN_10018580(void *this,undefined4 param_1,int *param_2,int *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100253e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000c110(this,param_1);
  *(undefined ***)this = CRP1210Connection::vftable;
  *(undefined4 *)((int)this + 0x58) = 7;
  *(undefined4 *)((int)this + 0x54) = 0;
  local_8 = 0;
  *(undefined2 *)((int)this + 0x44) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x44),param_2,0,0xffffffff);
  *(undefined4 *)((int)this + 0x74) = 7;
  *(undefined4 *)((int)this + 0x70) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined2 *)((int)this + 0x60) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x60),param_3,0,0xffffffff);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10018620 at 10018620

/* WARNING: Removing unreachable block (ram,0x10018a29) */

void __thiscall FUN_10018620(void *this,void *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  LONG LVar7;
  short *psVar8;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uStack_78;
  int *local_54;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025466;
  local_10 = ExceptionList;
  uStack_78 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_78;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_78;
  GetCurrentThreadId();
  local_54 = (int *)&stack0xffffff7c;
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar5 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210Connection.cpp");
    *piVar2 = iVar3;
    piVar5 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff78,0x1002fe08);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar5,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_54 = piVar2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar5 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210Connection.cpp");
    *piVar2 = iVar3;
    piVar5 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 2;
  local_54 = (int *)&stack0xffffff70;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff70,0x1002fdb8);
  pvVar4 = *(void **)(*(int *)((int)this + 4) + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar5,uVar9,uVar10,piVar2);
  local_50 = (void *)((uint)local_50._2_2_ << 0x10);
  local_3c = 7;
  local_40 = 0;
  psVar8 = (short *)PTR_u_<dclDeviceConfiguration><protoco_1003adb0;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_50,(int *)PTR_u_<dclDeviceConfiguration><protoco_1003adb0,
               (int)psVar8 - (int)(PTR_u_<dclDeviceConfiguration><protoco_1003adb0 + 2) >> 1);
  local_8._0_1_ = 7;
  (**(code **)(*(int *)((int)param_1 + 8) + 0x2c))();
  piVar2 = FUN_10001f10(&local_54,0);
  local_8._0_1_ = 8;
  if ((undefined4 *)*piVar2 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)*piVar2;
  }
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  piVar5 = piVar2;
  do {
    iVar3 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_34,piVar2,(int)piVar5 - ((int)piVar2 + 2) >> 1);
  local_8 = CONCAT31(local_8._1_3_,9);
  psVar8 = (short *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ada0;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  uVar6 = FUN_100137e0(&local_50,(ushort *)PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ada0,0,
                       (int)psVar8 - (int)(PTR_u_ID_PROTOCOL_NAME_BEGIN_1003ada0 + 2) >> 1);
  FUN_100138a0(&local_50,uVar6,DAT_1003b000,&local_34,0,0xffffffff);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  piVar2 = local_54;
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_8._0_1_ = 7;
  if (((local_54 != (int *)0x0) && (LVar7 = InterlockedDecrement(local_54 + 2), LVar7 == 0)) &&
     (piVar2 != (int *)0x0)) {
    if (*piVar2 != 0) {
      Ordinal_6();
    }
    if ((void *)piVar2[1] != (void *)0x0) {
      operator_delete__((void *)piVar2[1]);
    }
    operator_delete(piVar2);
  }
  piVar2 = FUN_10001f10(&local_54,0);
  local_8._0_1_ = 10;
  if ((undefined4 *)*piVar2 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)*piVar2;
  }
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_20 = 7;
  local_24 = 0;
  piVar5 = piVar2;
  do {
    iVar3 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 2);
  } while ((short)iVar3 != 0);
  FUN_10003130(&local_34,piVar2,(int)piVar5 - ((int)piVar2 + 2) >> 1);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  psVar8 = (short *)PTR_u_ID_PROTOCOL_NAME_END_1003ada4;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  uVar6 = FUN_100137e0(&local_50,(ushort *)PTR_u_ID_PROTOCOL_NAME_END_1003ada4,0,
                       (int)psVar8 - (int)(PTR_u_ID_PROTOCOL_NAME_END_1003ada4 + 2) >> 1);
  FUN_100138a0(&local_50,uVar6,DAT_1003b004,&local_34,0,0xffffffff);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  piVar2 = local_54;
  local_20 = 7;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,7);
  if (local_54 != (int *)0x0) {
    LVar7 = InterlockedDecrement(local_54 + 2);
    if ((LVar7 == 0) && (piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        Ordinal_6();
      }
      if ((void *)piVar2[1] != (void *)0x0) {
        operator_delete__((void *)piVar2[1]);
      }
      operator_delete(piVar2);
    }
    local_54 = (int *)0x0;
  }
  psVar8 = (short *)PTR_u_ID_DRIVER_DLL_NAME_1003ada8;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  uVar6 = FUN_100137e0(&local_50,(ushort *)PTR_u_ID_DRIVER_DLL_NAME_1003ada8,0,
                       (int)psVar8 - (int)(PTR_u_ID_DRIVER_DLL_NAME_1003ada8 + 2) >> 1);
  FUN_100138a0(&local_50,uVar6,DAT_1003b008,(int *)((int)this + 0x44),0,0xffffffff);
  psVar8 = (short *)PTR_u_ID_SERVICE_ID_1003adac;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  uVar6 = FUN_100137e0(&local_50,(ushort *)PTR_u_ID_SERVICE_ID_1003adac,0,
                       (int)psVar8 - (int)(PTR_u_ID_SERVICE_ID_1003adac + 2) >> 1);
  FUN_100138a0(&local_50,uVar6,DAT_1003b00c,(int *)((int)this + 0x60),0,0xffffffff);
  FUN_10003030((void *)((int)this + 8),&local_50,0,0xffffffff);
  FUN_1000c1e0(param_1);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10018a7d at 10018a7d

undefined * Catch_10018a7d(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -100),"RP1210Connection.cpp",0x5f,
               "CRP1210Connection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_10018ac5;
}



// Function: Catch_All@10018ac7 at 10018ac7

undefined4 Catch_All_10018ac7(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x24) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10020630((void *)(unaff_EBP + -0x24),"RP1210Connection.cpp",0x5f,
               "CRP1210Connection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x10018b2b;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return 0x10018a5f;
}



// Function: FUN_10018b40 at 10018b40

void __cdecl FUN_10018b40(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x45);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x45);
  }
  return;
}



// Function: FUN_10018b60 at 10018b60

void __cdecl FUN_10018b60(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x45);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}



// Function: FUN_10018b80 at 10018b80

void __fastcall FUN_10018b80(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0x45) != '\0') {
    *param_1 = puVar2[2];
    return;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0x45) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0x45) == '\0');
      *param_1 = iVar4;
      return;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0x45);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0x45);
    }
    if (*(char *)(*param_1 + 0x45) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar5;
  return;
}



// Function: FUN_10018be0 at 10018be0

int __thiscall FUN_10018be0(void *this,short *param_1,uint param_2,int param_3)

{
  void *pvVar1;
  void *pvVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  
  if ((param_3 != 0) && (param_2 < *(uint *)((int)this + 0x10))) {
    pvVar1 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar1 = *this;
    }
    pvVar2 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
    }
    for (psVar3 = (short *)((int)pvVar2 + param_2 * 2);
        psVar3 < (short *)((int)pvVar1 + *(uint *)((int)this + 0x10) * 2); psVar3 = psVar3 + 1) {
      psVar4 = param_1;
      iVar5 = param_3;
      do {
        if (*psVar4 == *psVar3) {
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)psVar3 - (int)this >> 1;
        }
        psVar4 = psVar4 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return -1;
}



// Function: FUN_10018c70 at 10018c70

void __fastcall FUN_10018c70(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10018c80 at 10018c80

uint __thiscall FUN_10018c80(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (*(int *)((int)this + 8) - *this) / 0xe0;
  if (0x1249249 - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (uVar1 < param_1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Function: FUN_10018cc0 at 10018cc0

void __fastcall FUN_10018cc0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x45) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x45) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x45);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x45);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x45);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x45);
    }
    *param_1 = iVar2;
  }
  return;
}



// Function: FUN_10018d10 at 10018d10

void __thiscall FUN_10018d10(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x45) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 4) + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// Function: FUN_10018d70 at 10018d70

void __thiscall FUN_10018d70(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x45) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 4) + 4)) {
    *(int *)(*(int *)((int)this + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// Function: FUN_10018dd0 at 10018dd0

void * FUN_10018dd0(char *param_1)

{
  void *pvVar1;
  undefined **local_10 [3];
  
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x124924a) &&
     (pvVar1 = operator_new((int)param_1 * 0xe0), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_10018e30 at 10018e30

void __fastcall FUN_10018e30(undefined2 *param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  *(undefined4 *)(param_1 + 0x26) = 7;
  *(undefined4 *)(param_1 + 0x24) = 0;
  param_1[0x1c] = 0;
  *(undefined4 *)(param_1 + 0x34) = 7;
  *(undefined4 *)(param_1 + 0x32) = 0;
  param_1[0x2a] = 0;
  *(undefined4 *)(param_1 + 0x42) = 7;
  *(undefined4 *)(param_1 + 0x40) = 0;
  param_1[0x38] = 0;
  *(undefined4 *)(param_1 + 0x50) = 7;
  *(undefined4 *)(param_1 + 0x4e) = 0;
  param_1[0x46] = 0;
  *(undefined4 *)(param_1 + 0x5e) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  param_1[0x54] = 0;
  *(undefined4 *)(param_1 + 0x6c) = 7;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  param_1[0x62] = 0;
  return;
}



// Function: FUN_10018eb0 at 10018eb0

bool FUN_10018eb0(void *param_1,ushort *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_2 + 8);
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(ushort **)param_2;
  }
  uVar2 = FUN_10005600(param_1,0,*(uint *)((int)param_1 + 0x10),param_2,*puVar1);
  return (int)uVar2 < 0;
}



// Function: FUN_10018ee0 at 10018ee0

undefined4 * __thiscall FUN_10018ee0(void *this,ushort *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x45);
  puVar2 = *(undefined4 **)((int)this + 4);
  while (cVar1 == '\0') {
    puVar3 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      puVar3 = *(ushort **)param_1;
    }
    uVar4 = FUN_10005600(puVar5 + 3,0,puVar5[7],puVar3,*(uint *)(param_1 + 8));
    if ((int)uVar4 < 0) {
      puVar6 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0x45);
  }
  return puVar2;
}



// Function: FUN_10018f40 at 10018f40

void __fastcall FUN_10018f40(undefined4 *param_1)

{
  if (7 < (uint)param_1[0xc]) {
    operator_delete((void *)param_1[7]);
  }
  param_1[0xc] = 7;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10018fa0 at 10018fa0

int * __thiscall FUN_10018fa0(void *this,uint param_1,int *param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int *extraout_EAX;
  void *pvVar2;
  uint extraout_ECX;
  uint uVar3;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  uint extraout_EDX;
  int *piVar5;
  uint uVar6;
  
  if (param_3 != (int *)0x0) {
    uVar6 = *(uint *)((int)this + 0x14);
    piVar1 = (int *)this;
    if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
    }
    if (piVar1 <= param_3) {
      pvVar2 = this;
      if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      if (param_3 < (int *)((int)pvVar2 + *(int *)((int)this + 0x10) * 2)) {
        pvVar2 = this;
        if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
          pvVar2 = *this;
        }
        piVar1 = FUN_100138a0(this,param_1,(uint)param_2,(int *)this,(int)param_3 - (int)pvVar2 >> 1
                              ,param_4);
        return piVar1;
      }
    }
  }
  uVar6 = *(uint *)((int)this + 0x10);
  uVar3 = param_1;
  if (uVar6 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar3 = extraout_ECX;
    uVar6 = extraout_EDX;
  }
  piVar1 = (int *)(uVar6 - uVar3);
  piVar5 = param_2;
  if (piVar1 < param_2) {
    piVar5 = piVar1;
  }
  piVar4 = (int *)param_4;
  if (-param_4 - 1 <= uVar6 - (int)piVar5) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_EAX;
    piVar4 = extraout_ECX_00;
  }
  if (piVar4 < piVar5) {
    pvVar2 = this;
    param_2 = (int *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      param_2 = *this;
      pvVar2 = *this;
    }
    memmove((void *)((int)param_2 + (param_1 + (int)piVar4) * 2),
            (void *)((int)pvVar2 + (param_1 + (int)piVar5) * 2),((int)piVar1 - (int)piVar5) * 2);
    piVar4 = (int *)param_4;
  }
  if ((piVar4 != (int *)0x0) || (piVar5 != (int *)0x0)) {
    uVar6 = (*(int *)((int)this + 0x10) - (int)piVar5) + (int)piVar4;
    if (0x7ffffffe < uVar6) {
      std::_Xlength_error("string too long");
      piVar4 = extraout_ECX_01;
    }
    if (*(uint *)((int)this + 0x14) < uVar6) {
      FUN_100022b0(this,uVar6);
      piVar4 = (int *)param_4;
      if (uVar6 == 0) {
        return (int *)this;
      }
    }
    else if (uVar6 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (*(uint *)((int)this + 0x14) < 8) {
        *(undefined2 *)this = 0;
        return (int *)this;
      }
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    if (piVar5 < piVar4) {
      pvVar2 = this;
      param_2 = (int *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_2 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      FUN_10001be0((void *)((int)pvVar2 + (param_1 + (int)piVar4) * 2),
                   (void *)((int)param_2 + (param_1 + (int)piVar5) * 2),(int)piVar1 - (int)piVar5);
      piVar4 = (int *)param_4;
    }
    pvVar2 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
    }
    memcpy((void *)((int)pvVar2 + param_1 * 2),param_3,(int)piVar4 * 2);
    *(uint *)((int)this + 0x10) = uVar6;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar6 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar6 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_10019190 at 10019190

void * __thiscall FUN_10019190(void *this,int *param_1)

{
  FUN_10003030(this,param_1,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0x1c),param_1 + 7,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0x38),param_1 + 0xe,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0x54),param_1 + 0x15,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0x70),param_1 + 0x1c,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0x8c),param_1 + 0x23,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0xa8),param_1 + 0x2a,0,0xffffffff);
  FUN_10003030((void *)((int)this + 0xc4),param_1 + 0x31,0,0xffffffff);
  return this;
}



// Function: FUN_10019230 at 10019230

undefined2 * __thiscall FUN_10019230(void *this,int *param_1)

{
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100254e0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)this = 0;
  FUN_10003030(this,param_1,0,0xffffffff);
  *(undefined4 *)((int)this + 0x30) = 7;
  *(undefined4 *)((int)this + 0x2c) = 0;
  local_8 = 0;
  *(undefined2 *)((int)this + 0x1c) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x1c),param_1 + 7,0,0xffffffff);
  *(undefined4 *)((int)this + 0x4c) = 7;
  *(undefined4 *)((int)this + 0x48) = 0;
  local_8._0_1_ = 1;
  *(undefined2 *)((int)this + 0x38) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x38),param_1 + 0xe,0,0xffffffff);
  *(undefined4 *)((int)this + 0x68) = 7;
  *(undefined4 *)((int)this + 100) = 0;
  local_8._0_1_ = 2;
  *(undefined2 *)((int)this + 0x54) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x54),param_1 + 0x15,0,0xffffffff);
  *(undefined4 *)((int)this + 0x84) = 7;
  *(undefined4 *)((int)this + 0x80) = 0;
  local_8._0_1_ = 3;
  *(undefined2 *)((int)this + 0x70) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x70),param_1 + 0x1c,0,0xffffffff);
  *(undefined4 *)((int)this + 0xa0) = 7;
  *(undefined4 *)((int)this + 0x9c) = 0;
  local_8._0_1_ = 4;
  *(undefined2 *)((int)this + 0x8c) = 0;
  FUN_10003030((undefined2 *)((int)this + 0x8c),param_1 + 0x23,0,0xffffffff);
  *(undefined4 *)((int)this + 0xbc) = 7;
  *(undefined4 *)((int)this + 0xb8) = 0;
  local_8._0_1_ = 5;
  *(undefined2 *)((int)this + 0xa8) = 0;
  FUN_10003030((undefined2 *)((int)this + 0xa8),param_1 + 0x2a,0,0xffffffff);
  *(undefined4 *)((int)this + 0xd8) = 7;
  *(undefined4 *)((int)this + 0xd4) = 0;
  local_8 = CONCAT31(local_8._1_3_,6);
  *(undefined2 *)((int)this + 0xc4) = 0;
  FUN_10003030((undefined2 *)((int)this + 0xc4),param_1 + 0x31,0,0xffffffff);
  *unaff_FS_OFFSET = local_10;
  return (undefined2 *)this;
}



// Function: FUN_10019390 at 10019390

undefined2 * __thiscall FUN_10019390(void *this,undefined2 *param_1,void *param_2)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025519;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10018e30(param_1);
  local_8 = 0;
  puVar3 = *(ushort **)((int)this + 0x3c);
  if (puVar3 == *(ushort **)((int)this + 0x40)) {
    ExceptionList = local_10;
    return param_1;
  }
  do {
    puVar1 = puVar3;
    if (7 < *(uint *)(puVar3 + 10)) {
      puVar1 = *(ushort **)puVar3;
    }
    uVar2 = FUN_100137e0(param_2,puVar1,0,*(uint *)(puVar3 + 8));
    if (uVar2 != 0xffffffff) {
      FUN_10019190(param_1,(int *)puVar3);
    }
    puVar3 = puVar3 + 0x70;
  } while (puVar3 != *(ushort **)((int)this + 0x40));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10019440 at 10019440

void FUN_10019440(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003add8);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100194d0 at 100194d0

void __thiscall FUN_100194d0(void *this,int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar4;
  IUnknownVtbl *pIVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar6;
  undefined4 in_stack_ffffff44;
  ushort uVar7;
  undefined2 auStack_a0 [8];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uVar8;
  undefined4 uVar9;
  void *local_34;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar7 = (ushort)((uint)in_stack_ffffff44 >> 0x10);
  puStack_c = &LAB_10025596;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x10030148);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar6,piVar2);
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar9 = 4;
  uVar8 = 1;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff80,0x100300f0);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar6,uVar8,uVar9,piVar2);
  if (param_1[4] == 0) {
    pIVar5 = (IUnknownVtbl *)FUN_10019440();
    local_8._0_1_ = 7;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar5 + 0x14))->lpVtbl) {
      pIVar5 = ((IUnknown *)pIVar5)->lpVtbl;
    }
                    /* WARNING: Load size is inaccurate */
    uStack_8c = 0x10019693;
    FUN_10014d70(*this,0x427,0x20,(IUnknown *)pIVar5,(IUnknown *)L"CRP1210IniFile::SetFileName ()",
                 (int *)0x4,(IID *)0x0,(int *)L"RP1210IniFile.cpp",(undefined1 *)0x52);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
    FUN_10019440();
    uStack_8c = 7;
    uStack_90 = 0;
    local_8._0_1_ = 8;
    auStack_a0[0] = 0;
    FUN_10003130(auStack_a0,(int *)L"CRP1210IniFile::SetFileName ()",0x1e);
    local_8._0_1_ = 9;
    pvVar4 = (void *)((uint)uVar7 << 0x10);
    FUN_10003130(&stack0xffffff44,(int *)L"RP1210IniFile.cpp",0x11);
    local_8._0_1_ = 0;
    FUN_100147a0(0x54,pvVar4);
  }
  else {
    FUN_10003030((void *)((int)this + 4),param_1,0,0xffffffff);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10019715 at 10019715

undefined * Catch_10019715(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"RP1210IniFile.cpp",0x5a,"CRP1210IniFile::SetFileName",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1001975d;
}



// Function: Catch_All@10019762 at 10019762

undefined4 Catch_All_10019762(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10020630((void *)(unaff_EBP + -0x50),"RP1210IniFile.cpp",0x5a,"CRP1210IniFile::SetFileName",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x100197c6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x1001963a;
}



// Function: FUN_100197d0 at 100197d0

void __cdecl FUN_100197d0(undefined4 param_1,undefined4 *param_2)

{
  if (7 < (uint)param_2[0xc]) {
    operator_delete((void *)param_2[7]);
  }
  param_2[0xc] = 7;
  param_2[0xb] = 0;
  *(undefined2 *)(param_2 + 7) = 0;
  if (7 < (uint)param_2[5]) {
    operator_delete((void *)*param_2);
  }
  param_2[5] = 7;
  param_2[4] = 0;
  *(undefined2 *)param_2 = 0;
  return;
}



// Function: FUN_10019830 at 10019830

void __thiscall
FUN_10019830(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint extraout_EAX;
  uint uVar4;
  int *piVar5;
  void *extraout_ECX;
  int *piVar6;
  int *piVar7;
  
  uVar4 = *(uint *)((int)this + 8);
  if (0x4924922 < uVar4) {
    FUN_100197d0((int)this + 0xd,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
    uVar4 = extraout_EAX;
    this = extraout_ECX;
  }
  *(uint *)((int)this + 8) = uVar4 + 1;
  param_4[1] = (int)param_3;
  if (param_3 == *(undefined4 **)((int)this + 4)) {
    (*(undefined4 **)((int)this + 4))[1] = param_4;
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
      **(int **)((int)this + 4) = (int)param_4;
    }
  }
  cVar1 = *(char *)(param_4[1] + 0x44);
  piVar5 = param_4;
  do {
    if (cVar1 != '\0') {
      iVar2 = *(int *)(*(int *)((int)this + 4) + 4);
      *param_1 = param_4;
      *(undefined1 *)(iVar2 + 0x44) = 1;
      return;
    }
    piVar6 = (int *)piVar5[1];
    piVar7 = (int *)piVar6[1];
    if (piVar6 == (int *)*piVar7) {
      iVar2 = piVar7[2];
      if (*(char *)(iVar2 + 0x44) == '\0') {
        *(undefined1 *)(piVar6 + 0x11) = 1;
        *(undefined1 *)(iVar2 + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar6[2]) {
          piVar5 = (int *)piVar6[2];
          piVar6[2] = *piVar5;
          if (*(char *)(*piVar5 + 0x45) == '\0') {
            *(int **)(*piVar5 + 4) = piVar6;
          }
          piVar5[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int **)(*(int *)((int)this + 4) + 4) = piVar5;
          }
          else {
            piVar7 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar7) {
              *piVar7 = (int)piVar5;
            }
            else {
              piVar7[2] = (int)piVar5;
            }
          }
          *piVar5 = (int)piVar6;
          piVar6[1] = (int)piVar5;
          piVar5 = piVar6;
        }
        *(undefined1 *)(piVar5[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)*piVar6;
        *piVar6 = piVar7[2];
        if (*(char *)(piVar7[2] + 0x45) == '\0') {
          *(int **)(piVar7[2] + 4) = piVar6;
        }
        piVar7[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
          piVar7[2] = (int)piVar6;
        }
        else {
          piVar3 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar3[2]) {
            piVar3[2] = (int)piVar7;
            piVar7[2] = (int)piVar6;
          }
          else {
            *piVar3 = (int)piVar7;
            piVar7[2] = (int)piVar6;
          }
        }
LAB_10019a35:
        piVar6[1] = (int)piVar7;
      }
    }
    else {
      iVar2 = *piVar7;
      if (*(char *)(iVar2 + 0x44) != '\0') {
        if (piVar5 == (int *)*piVar6) {
          iVar2 = *piVar6;
          *piVar6 = *(int *)(iVar2 + 8);
          if (*(char *)(*(int *)(iVar2 + 8) + 0x45) == '\0') {
            *(int **)(*(int *)(iVar2 + 8) + 4) = piVar6;
          }
          *(int *)(iVar2 + 4) = piVar6[1];
          if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int *)(*(int *)((int)this + 4) + 4) = iVar2;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)piVar5[2]) {
              piVar5[2] = iVar2;
            }
            else {
              *piVar5 = iVar2;
            }
          }
          *(int **)(iVar2 + 8) = piVar6;
          piVar6[1] = iVar2;
          piVar5 = piVar6;
        }
        *(undefined1 *)(piVar5[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)piVar6[2];
        piVar6[2] = *piVar7;
        if (*(char *)(*piVar7 + 0x45) == '\0') {
          *(int **)(*piVar7 + 4) = piVar6;
        }
        piVar7[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
        }
        else {
          piVar3 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar3) {
            *piVar3 = (int)piVar7;
          }
          else {
            piVar3[2] = (int)piVar7;
          }
        }
        *piVar7 = (int)piVar6;
        goto LAB_10019a35;
      }
      *(undefined1 *)(piVar6 + 0x11) = 1;
      *(undefined1 *)(iVar2 + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    cVar1 = *(char *)(piVar5[1] + 0x44);
  } while( true );
}



// Function: FUN_10019a60 at 10019a60

void * __cdecl FUN_10019a60(int *param_1,int *param_2,void *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_100255d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x38) {
    local_8 = 1;
    if (param_3 != (void *)0x0) {
      FUN_10019230(param_3,param_1);
    }
    param_3 = (void *)((int)param_3 + 0xe0);
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch_All@10019acc at 10019acc

void Catch_All_10019acc(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  for (puVar2 = *(undefined4 **)(unaff_EBP + -0x14); puVar2 != puVar1; puVar2 = puVar2 + 0x38) {
    FUN_10005b80(puVar2);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10019b10 at 10019b10

void FUN_10019b10(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_10019b10((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0xf]) {
      operator_delete((void *)param_1[10]);
    }
    param_1[0xf] = 7;
    param_1[0xe] = 0;
    *(undefined2 *)(param_1 + 10) = 0;
    if (7 < (uint)param_1[8]) {
      operator_delete((void *)param_1[3]);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}



// Function: FUN_10019ba0 at 10019ba0

void __thiscall FUN_10019ba0(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x45) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10018cc0((int *)&param_2);
  piVar6 = (int *)*piVar2;
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
    piVar5 = piVar6;
    if ((*(char *)(piVar2[2] + 0x45) == '\0') && (piVar5 = (int *)param_2[2], param_2 != piVar2)) {
      piVar6[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar6 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar6 = (int *)param_2[1];
        if (*(char *)((int)piVar5 + 0x45) == '\0') {
          piVar5[1] = (int)piVar6;
        }
        *piVar6 = (int)piVar5;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
        *(int **)(*(int *)((int)this + 4) + 4) = param_2;
      }
      else {
        piVar3 = (int *)piVar2[1];
        if ((int *)*piVar3 == piVar2) {
          *piVar3 = (int)param_2;
        }
        else {
          piVar3[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[0x11];
      *(char *)(param_2 + 0x11) = (char)piVar2[0x11];
      *(char *)(piVar2 + 0x11) = (char)iVar1;
      goto LAB_10019cc0;
    }
  }
  else {
    piVar5 = (int *)piVar2[2];
  }
  piVar6 = (int *)piVar2[1];
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    piVar5[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar6 == piVar2) {
    *piVar6 = (int)piVar5;
  }
  else {
    piVar6[2] = (int)piVar5;
  }
  if ((int *)**(int **)((int)this + 4) == piVar2) {
    piVar3 = piVar6;
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      piVar3 = (int *)FUN_10018b60(piVar5);
    }
    **(undefined4 **)((int)this + 4) = piVar3;
  }
  if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      uVar4 = FUN_10018b40((int)piVar5);
      *(undefined4 *)(*(int *)((int)this + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
LAB_10019cc0:
  if ((char)piVar2[0x11] == '\x01') {
    if (piVar5 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        if ((char)piVar5[0x11] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_10018d10(this,(int)piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(*piVar3 + 0x44) != '\x01') || (*(char *)(piVar3[2] + 0x44) != '\x01')) {
              if (*(char *)(piVar3[2] + 0x44) == '\x01') {
                *(undefined1 *)(*piVar3 + 0x44) = 1;
                *(undefined1 *)(piVar3 + 0x11) = 0;
                FUN_10018d70(this,piVar3);
                piVar3 = (int *)piVar6[2];
              }
              *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
              *(undefined1 *)(piVar6 + 0x11) = 1;
              *(undefined1 *)(piVar3[2] + 0x44) = 1;
              FUN_10018d10(this,(int)piVar6);
              break;
            }
LAB_10019d86:
            *(undefined1 *)(piVar3 + 0x11) = 0;
          }
        }
        else {
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_10018d70(this,piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(piVar3[2] + 0x44) == '\x01') && (*(char *)(*piVar3 + 0x44) == '\x01'))
            goto LAB_10019d86;
            if (*(char *)(*piVar3 + 0x44) == '\x01') {
              *(undefined1 *)(piVar3[2] + 0x44) = 1;
              *(undefined1 *)(piVar3 + 0x11) = 0;
              FUN_10018d10(this,(int)piVar3);
              piVar3 = (int *)*piVar6;
            }
            *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
            *(undefined1 *)(piVar6 + 0x11) = 1;
            *(undefined1 *)(*piVar3 + 0x44) = 1;
            FUN_10018d70(this,piVar6);
            break;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)((int)this + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x11) = 1;
  }
  if (7 < (uint)piVar2[0xf]) {
    operator_delete((void *)piVar2[10]);
  }
  piVar2[0xf] = 7;
  piVar2[0xe] = 0;
  *(undefined2 *)(piVar2 + 10) = 0;
  if (7 < (uint)piVar2[8]) {
    operator_delete((void *)piVar2[3]);
  }
  piVar2[8] = 7;
  piVar2[7] = 0;
  *(undefined2 *)(piVar2 + 3) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10019e40 at 10019e40

void __thiscall FUN_10019e40(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  ushort *this_00;
  undefined4 *puVar6;
  bool local_8;
  
  puVar4 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  this_00 = (ushort *)(param_2 + 3);
  cVar1 = *(char *)((int)puVar4 + 0x45);
  local_8 = true;
  puVar2 = *(undefined4 **)((int)this + 4);
  while (cVar1 == '\0') {
    if ((char)param_3 == '\0') {
      puVar5 = (ushort *)(puVar4 + 3);
      if (7 < (uint)puVar4[8]) {
        puVar5 = *(ushort **)puVar5;
      }
      uVar3 = FUN_10005600(this_00,0,param_2[7],puVar5,puVar4[7]);
      local_8 = (int)uVar3 < 0;
    }
    else {
      puVar5 = this_00;
      if (7 < (uint)param_2[8]) {
        puVar5 = *(ushort **)this_00;
      }
      uVar3 = FUN_10005600(puVar4 + 3,0,puVar4[7],puVar5,param_2[7]);
      local_8 = -1 < (int)uVar3;
    }
    if (local_8 == false) {
      puVar6 = (undefined4 *)puVar4[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar4;
    }
    puVar2 = puVar4;
    puVar4 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0x45);
  }
  param_3 = puVar2;
  if (local_8 != false) {
    if (puVar2 == (undefined4 *)**(int **)((int)this + 4)) {
      local_8 = true;
      goto LAB_10019ee3;
    }
    FUN_10018b80((int *)&param_3);
  }
  puVar4 = param_3;
  puVar5 = this_00;
  if (7 < (uint)param_2[8]) {
    puVar5 = *(ushort **)this_00;
  }
  uVar3 = FUN_10005600(param_3 + 3,0,param_3[7],puVar5,param_2[7]);
  if (-1 < (int)uVar3) {
    FUN_100197d0((int)this + 0xd,(undefined4 *)this_00);
    operator_delete(param_2);
    *param_1 = puVar4;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10019ee3:
  puVar4 = (undefined4 *)FUN_10019830(this,&param_3,local_8,puVar2,param_2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10019f70 at 10019f70

void FUN_10019f70(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    do {
      FUN_10005b80(param_1);
      param_1 = param_1 + 0x38;
    } while (param_1 != param_2);
  }
  return;
}



// Function: FUN_10019fa0 at 10019fa0

void __thiscall FUN_10019fa0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)((int)this + 4);
  local_8 = this;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_10019b10((int *)piVar2[1]);
    *(int *)(*(int *)((int)this + 4) + 4) = *(int *)((int)this + 4);
    *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *(undefined4 *)((int)this + 8) = 0;
    *param_1 = **(undefined4 **)((int)this + 4);
    return;
  }
  if (param_2 != param_3) {
    do {
      piVar2 = param_2;
      if (*(char *)((int)param_2 + 0x45) == '\0') {
        piVar3 = (int *)param_2[2];
        if (*(char *)((int)piVar3 + 0x45) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x45);
          param_2 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x45);
            param_2 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(param_2[1] + 0x45);
          piVar4 = (int *)param_2[1];
          piVar3 = param_2;
          while ((param_2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_2[2]))) {
            cVar1 = *(char *)(param_2[1] + 0x45);
            piVar4 = (int *)param_2[1];
            piVar3 = param_2;
          }
        }
      }
      FUN_10019ba0(this,&local_8,piVar2);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1001a060 at 1001a060

undefined4 * __thiscall FUN_1001a060(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  ushort *this_00;
  int *piVar1;
  int *piVar2;
  bool bVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_c [2];
  
  piVar2 = param_3;
  piVar1 = *(int **)((int)this + 4);
  this_00 = (ushort *)(param_3 + 3);
  if (*(int *)((int)this + 8) == 0) {
    FUN_10019830(this,param_1,'\x01',piVar1,param_3);
    return param_1;
  }
  if (param_2 == (int *)*piVar1) {
    puVar4 = (ushort *)(param_2 + 3);
    if (7 < (uint)param_2[8]) {
      puVar4 = *(ushort **)puVar4;
    }
    uVar5 = FUN_10005600(this_00,0,param_3[7],puVar4,param_2[7]);
    if ((int)uVar5 < 0) {
      FUN_10019830(this,param_1,'\x01',param_2,piVar2);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    bVar3 = FUN_10018eb0((void *)(piVar1[2] + 0xc),this_00);
    if (bVar3) {
      FUN_10019830(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),piVar2);
      return param_1;
    }
  }
  else {
    bVar3 = FUN_10018eb0(this_00,(ushort *)(param_2 + 3));
    if (bVar3) {
      param_3 = param_2;
      FUN_10018b80((int *)&param_3);
      bVar3 = FUN_10018eb0(param_3 + 3,this_00);
      if (bVar3) {
        if (*(char *)(param_3[2] + 0x45) == '\0') {
          FUN_10019830(this,param_1,'\x01',param_2,piVar2);
          return param_1;
        }
        FUN_10019830(this,param_1,'\0',param_3,piVar2);
        return param_1;
      }
    }
    bVar3 = FUN_10018eb0(param_2 + 3,this_00);
    if (bVar3) {
      param_3 = param_2;
      FUN_10018cc0((int *)&param_3);
      if ((param_3 == *(int **)((int)this + 4)) ||
         (bVar3 = FUN_10018eb0(this_00,(ushort *)(param_3 + 3)), bVar3)) {
        if (*(char *)(param_2[2] + 0x45) == '\0') {
          FUN_10019830(this,param_1,'\x01',param_3,piVar2);
          return param_1;
        }
        FUN_10019830(this,param_1,'\0',param_2,piVar2);
        return param_1;
      }
    }
  }
  puVar6 = (undefined4 *)FUN_10019e40(this,local_c,piVar2,(undefined4 *)0x0);
  *param_1 = *puVar6;
  return param_1;
}



// Function: FUN_1001a220 at 1001a220

void __thiscall FUN_1001a220(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != param_3) {
    puVar2 = (undefined4 *)FUN_1001c0f0(param_3,*(int **)((int)this + 4),param_2);
    puVar1 = *(undefined4 **)((int)this + 4);
    for (puVar3 = puVar2; puVar3 != puVar1; puVar3 = puVar3 + 0x38) {
      FUN_10005b80(puVar3);
    }
    *(undefined4 **)((int)this + 4) = puVar2;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1001a290 at 1001a290

void __fastcall FUN_1001a290(_Container_base0 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    puVar1 = *(undefined4 **)(param_1 + 4);
    for (puVar2 = *(undefined4 **)param_1; puVar2 != puVar1; puVar2 = puVar2 + 0x38) {
      FUN_10005b80(puVar2);
    }
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1001a2e0 at 1001a2e0

void __thiscall FUN_1001a2e0(void *this,char *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100255f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((char *)0x1249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0xe0) < param_1) {
    pvVar2 = FUN_10018dd0(param_1);
                    /* WARNING: Load size is inaccurate */
    local_8 = 0;
    FUN_10019a60(*this,*(int **)((int)this + 4),pvVar2);
    puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    puVar4 = *this;
    iVar3 = (int)puVar1 - (int)puVar4;
    local_8 = 0xffffffff;
    if (puVar4 != (undefined4 *)0x0) {
      for (; puVar4 != puVar1; puVar4 = puVar4 + 0x38) {
        FUN_10005b80(puVar4);
      }
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0xe0 + (int)pvVar2);
    *(void **)((int)this + 4) = (void *)((iVar3 / 0xe0) * 0xe0 + (int)pvVar2);
    *(void **)this = pvVar2;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch_All@1001a3f7 at 1001a3f7

void Catch_All_1001a3f7(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001a410 at 1001a410

undefined4 * __thiscall FUN_1001a410(void *this,int *param_1)

{
  undefined4 *puVar1;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025629;
  local_10 = ExceptionList;
  uStack_3c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0x48);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)((int)this + 4);
    puVar1[1] = *(undefined4 *)((int)this + 4);
    local_20 = puVar1 + 3;
    puVar1[2] = *(undefined4 *)((int)this + 4);
    *(undefined2 *)(puVar1 + 0x11) = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (local_20 != (undefined4 *)0x0) {
      puVar1[8] = 7;
      puVar1[7] = 0;
      *(undefined2 *)local_20 = 0;
      local_1c = local_20;
      FUN_10003030(local_20,param_1,0,0xffffffff);
      puVar1[0xf] = 7;
      puVar1[0xe] = 0;
      local_8 = CONCAT31(local_8._1_3_,2);
      *(undefined2 *)(puVar1 + 10) = 0;
      FUN_10004710(puVar1 + 10,param_1 + 7);
    }
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (int *)0x0;
  std::exception::exception((exception *)local_2c,(char **)&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10033244);
}



// Function: Catch_All@1001a4d4 at 1001a4d4

void Catch_All_1001a4d4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001a520 at 1001a520

void __thiscall FUN_1001a520(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  char *pcVar3;
  void *extraout_ECX;
  char *pcVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = (*(int *)((int)this + 4) - iVar1) / 0xe0;
  if (0x1249249U - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  pcVar4 = (char *)(uVar2 + param_1);
  pcVar3 = (char *)((*(int *)((int)this + 8) - iVar1) / 0xe0);
  if (pcVar3 < pcVar4) {
    if ((char *)(0x1249249 - ((uint)pcVar3 >> 1)) < pcVar3) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = pcVar3 + ((uint)pcVar3 >> 1);
    }
    if (pcVar3 < pcVar4) {
      pcVar3 = pcVar4;
    }
    FUN_1001a2e0(this,pcVar3);
  }
  return;
}



// Function: FUN_1001a5a0 at 1001a5a0

void __fastcall FUN_1001a5a0(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_10019fa0(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001a600 at 1001a600

void __fastcall FUN_1001a600(int param_1)

{
  undefined4 local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100256b4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  local_14 = param_1;
  FUN_1001a220((void *)(param_1 + 0x3c),&local_18,*(int **)(param_1 + 0x3c),
               *(int **)(param_1 + 0x40));
  FUN_10019b10(*(int **)(*(int *)(param_1 + 0x50) + 4));
  *(int *)(*(int *)(param_1 + 0x50) + 4) = *(int *)(param_1 + 0x50);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(int *)(*(int *)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x54) = 0;
  local_8._0_1_ = 4;
  local_18 = (void *)(param_1 + 0x4c);
  FUN_10019fa0((void *)(param_1 + 0x4c),&local_1c,(int *)**(int **)(param_1 + 0x50),
               *(int **)(param_1 + 0x50));
  operator_delete(*(void **)(param_1 + 0x50));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1001a290((_Container_base0 *)(param_1 + 0x3c));
  if (7 < *(uint *)(param_1 + 0x34)) {
    operator_delete(*(void **)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x34) = 7;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x20) = 0;
  if (7 < *(uint *)(param_1 + 0x18)) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001a700 at 1001a700

void __thiscall FUN_1001a700(void *this,undefined2 *param_1,undefined4 *param_2)

{
  LPCWSTR pWVar1;
  short sVar2;
  WCHAR WVar3;
  undefined4 *puVar4;
  undefined2 *this_00;
  int *piVar5;
  int iVar6;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar7;
  LPCWSTR pWVar8;
  WCHAR *pWVar9;
  short *psVar10;
  uint uVar11;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar12;
  LPCWSTR pWVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint local_28c;
  undefined4 *local_26c;
  int *local_268;
  undefined4 *local_264;
  undefined4 *local_260;
  undefined4 local_25c;
  undefined2 *local_254;
  undefined4 local_250;
  int *local_240;
  uint local_23c;
  undefined4 local_234;
  undefined4 local_224;
  uint local_220;
  WCHAR local_218;
  undefined1 local_216 [510];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025766;
  local_10 = ExceptionList;
  local_28c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&local_28c;
  ExceptionList = &local_10;
  local_254 = param_1;
  local_26c = param_2;
  local_18 = local_28c;
  FUN_10018e30(param_1);
  local_8 = 1;
  GetCurrentThreadId();
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  local_268 = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar12 = extraout_ECX;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar5 = iVar6;
    piVar12 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar12 = extraout_ECX_01;
  }
  local_268 = (int *)&stack0xfffffd64;
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xfffffd64,0x100302cc);
                    /* WARNING: Load size is inaccurate */
  pvVar7 = *(void **)(*this + 4);
  local_8._0_1_ = 4;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar7,piVar12,piVar5);
  GetCurrentThreadId();
  local_268 = (int *)&stack0xfffffd68;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar12 = extraout_ECX_02;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar5 = iVar6;
    piVar12 = extraout_ECX_03;
  }
  local_8._0_1_ = 1;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar12 = extraout_ECX_04;
  }
  uVar15 = 4;
  uVar14 = 1;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xfffffd5c,0x10030250);
                    /* WARNING: Load size is inaccurate */
  pvVar7 = *(void **)(*this + 4);
  local_8._0_1_ = 7;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX_00;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar7,piVar12,uVar14,uVar15,piVar5);
  local_234 = (LPCWSTR)((uint)local_234._2_2_ << 0x10);
  local_220 = 7;
  local_224 = 0;
  psVar10 = (short *)PTR_u_DeviceInformation_1003adf8;
  do {
    sVar2 = *psVar10;
    psVar10 = psVar10 + 1;
  } while (sVar2 != 0);
  FUN_10003130(&local_234,(int *)PTR_u_DeviceInformation_1003adf8,
               (int)psVar10 - (int)(PTR_u_DeviceInformation_1003adf8 + 2) >> 1);
  local_8._0_1_ = 8;
  FUN_10005a70(&local_234,local_26c,0,0xffffffff);
  pWVar1 = (LPCWSTR)((int)this + 4);
  pWVar8 = pWVar1;
  if (7 < *(uint *)((int)this + 0x18)) {
    pWVar8 = *(LPCWSTR *)pWVar1;
  }
  GetPrivateProfileStringW
            ((LPCWSTR)PTR_u_VendorInformation_1003ade4,(LPCWSTR)PTR_u_Name_1003ae08,
             (LPCWSTR)PTR_DAT_1003add4,&local_218,0x100,pWVar8);
  this_00 = local_254;
  pWVar9 = &local_218;
  do {
    WVar3 = *pWVar9;
    pWVar9 = pWVar9 + 1;
  } while (WVar3 != L'\0');
  FUN_10003130(local_254 + 0x62,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
  pWVar8 = pWVar1;
  if (7 < *(uint *)((int)this + 0x18)) {
    pWVar8 = *(LPCWSTR *)pWVar1;
  }
  pWVar13 = local_234;
  if (local_220 < 8) {
    pWVar13 = (LPCWSTR)&local_234;
  }
  GetPrivateProfileStringW
            (pWVar13,(LPCWSTR)PTR_u_DeviceID_1003adfc,(LPCWSTR)PTR_DAT_1003add4,&local_218,0x100,
             pWVar8);
  pWVar9 = &local_218;
  do {
    WVar3 = *pWVar9;
    pWVar9 = pWVar9 + 1;
  } while (WVar3 != L'\0');
  FUN_10003130(this_00,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
  pWVar8 = pWVar1;
  if (7 < *(uint *)((int)this + 0x18)) {
    pWVar8 = *(LPCWSTR *)pWVar1;
  }
  pWVar13 = local_234;
  if (local_220 < 8) {
    pWVar13 = (LPCWSTR)&local_234;
  }
  GetPrivateProfileStringW
            (pWVar13,(LPCWSTR)PTR_u_DeviceName_1003ae04,(LPCWSTR)PTR_DAT_1003add4,&local_218,0x100,
             pWVar8);
  pWVar9 = &local_218;
  do {
    WVar3 = *pWVar9;
    pWVar9 = pWVar9 + 1;
  } while (WVar3 != L'\0');
  FUN_10003130(this_00 + 0x1c,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
  pWVar8 = pWVar1;
  if (7 < *(uint *)((int)this + 0x18)) {
    pWVar8 = *(LPCWSTR *)pWVar1;
  }
  pWVar13 = local_234;
  if (local_220 < 8) {
    pWVar13 = (LPCWSTR)&local_234;
  }
  GetPrivateProfileStringW
            (pWVar13,(LPCWSTR)PTR_u_DeviceDescription_1003ae00,(LPCWSTR)PTR_DAT_1003add4,&local_218,
             0x100,pWVar8);
  pWVar9 = &local_218;
  do {
    WVar3 = *pWVar9;
    pWVar9 = pWVar9 + 1;
  } while (WVar3 != L'\0');
  piVar5 = (int *)(this_00 + 0xe);
  FUN_10003130(piVar5,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
  local_264 = (undefined4 *)0x0;
  local_260 = (undefined4 *)0x0;
  local_25c = 0;
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_1001f480(piVar5,0x2c,&local_264);
  puVar4 = local_264;
  if ((((int)local_260 - (int)local_264) / 0x1c == 2) &&
     (iVar6 = FUN_10018be0(piVar5,(short *)&DAT_1003024c,0,1), iVar6 != -1)) {
    FUN_10003030(local_254 + 0x46,puVar4 + 7,0,0xffffffff);
  }
  else {
    psVar10 = (short *)PTR_u_Unavailable_1003addc;
    do {
      sVar2 = *psVar10;
      psVar10 = psVar10 + 1;
    } while (sVar2 != 0);
    FUN_10003130(local_254 + 0x46,(int *)PTR_u_Unavailable_1003addc,
                 (int)psVar10 - (int)(PTR_u_Unavailable_1003addc + 2) >> 1);
  }
  local_250 = (void *)((uint)local_250._2_2_ << 0x10);
  local_23c = 7;
  local_240 = (int *)0x0;
  FUN_10003030(&local_250,(int *)pWVar1,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,10);
  local_26c = (undefined4 *)0x2e;
  uVar11 = FUN_100137e0(&local_250,(ushort *)&local_26c,0,1);
  psVar10 = (short *)PTR_DAT_1003ade0;
  do {
    sVar2 = *psVar10;
    psVar10 = psVar10 + 1;
  } while (sVar2 != 0);
  FUN_10018fa0(&local_250,uVar11 + 1,local_240,(int *)PTR_DAT_1003ade0,
               (int)psVar10 - (int)(PTR_DAT_1003ade0 + 2) >> 1);
  FUN_10003030(local_254 + 0x2a,&local_250,0,0xffffffff);
  if (7 < local_23c) {
    operator_delete(local_250);
  }
  local_23c = 7;
  local_240 = (int *)0x0;
  local_250 = (void *)((uint)local_250 & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,8);
  if (local_264 != (undefined4 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_264);
    FUN_10007c00(local_264,local_260);
    operator_delete(local_264);
  }
  local_264 = (undefined4 *)0x0;
  local_260 = (undefined4 *)0x0;
  local_25c = 0;
  if (7 < local_220) {
    operator_delete(local_234);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001acd7 at 1001acd7

undefined * Catch_1001acd7(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x278),"RP1210IniFile.cpp",0x123,
               "CRP1210IniFile::getDeviceInfo",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1001ad25;
}



// Function: Catch_All@1001ad27 at 1001ad27

undefined4 Catch_All_1001ad27(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x260) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x25c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -600) = 0;
  *(undefined4 *)(unaff_EBP + -0x254) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10020630((void *)(unaff_EBP + -0x260),"RP1210IniFile.cpp",0x123,
               "CRP1210IniFile::getDeviceInfo",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1001ada0;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x260));
  return 0x1001acb3;
}



// Function: FUN_1001adb0 at 1001adb0

void ** __thiscall FUN_1001adb0(void *this,void **param_1)

{
  void **ppvVar1;
  void **ppvVar2;
  void *this_00;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100257b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppvVar1 = *(void ***)((int)this + 4);
  ppvVar2 = (void **)ExceptionList;
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < ppvVar1) && (ppvVar2 = *this, ppvVar2 <= param_1)) {
    iVar3 = (int)param_1 - (int)ppvVar2;
    ppvVar2 = (void **)(iVar3 * -0x6db6db6d);
    if (ppvVar1 == *(void ***)((int)this + 8)) {
      ppvVar2 = (void **)FUN_1001a520(this,1);
    }
    this_00 = *(void **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    param_1 = (void **)((iVar3 / 0xe0) * 0xe0 + *this);
    local_8 = 0;
  }
  else {
    if (ppvVar1 == *(void ***)((int)this + 8)) {
      ppvVar2 = (void **)FUN_1001a520(this,1);
    }
    this_00 = *(void **)((int)this + 4);
    local_8 = 1;
  }
  if (this_00 != (void *)0x0) {
    ppvVar2 = (void **)FUN_10019230(this_00,(int *)param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0xe0;
  ExceptionList = local_10;
  return ppvVar2;
}



// Function: FUN_1001ae70 at 1001ae70

void __thiscall FUN_1001ae70(void *this,ushort *param_1)

{
  int *piVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_6c;
  void *local_68 [4];
  undefined4 local_58;
  uint local_54;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100257e8;
  local_10 = ExceptionList;
  local_14 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = FUN_10018ee0(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    puVar2 = (ushort *)(piVar1 + 3);
    if (7 < (uint)piVar1[8]) {
      puVar2 = *(ushort **)puVar2;
    }
    uVar3 = FUN_10005600(param_1,0,*(uint *)(param_1 + 8),puVar2,piVar1[7]);
    if (-1 < (int)uVar3) goto LAB_1001af9c;
  }
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (void *)((uint)local_68[0] & 0xffff0000);
  local_38 = 7;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_8 = 0;
  local_3c = 0;
  FUN_10003030(local_4c,(int *)param_1,0,0xffffffff);
  local_8._0_1_ = 1;
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  FUN_10004710(&local_30,local_68);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar4 = FUN_1001a410(this,(int *)local_4c);
  FUN_1001a060(this,&local_6c,piVar1,piVar4);
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  if (7 < local_54) {
    operator_delete(local_68[0]);
  }
LAB_1001af9c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001afc0 at 1001afc0

undefined4 * __thiscall FUN_1001afc0(void *this,char *param_1)

{
  short sVar1;
  undefined *puVar2;
  short *psVar3;
  void *pvVar4;
  undefined **local_20 [3];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar2 = PTR_u_CMNS32_ini_1003ae0c;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025831;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(char **)this = param_1;
  *(undefined4 *)((int)this + 0x18) = 7;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  param_1 = puVar2 + 2;
  psVar3 = (short *)puVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_14 = this;
  FUN_10003130((undefined2 *)((int)this + 4),(int *)puVar2,(int)psVar3 - (int)param_1 >> 1);
  *(undefined4 *)((int)this + 0x34) = 7;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined2 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  local_8 = 2;
  *(undefined4 *)((int)this + 0x54) = 0;
  pvVar4 = operator_new(0x48);
  if (pvVar4 != (void *)0x0) {
    *(void **)((int)this + 0x50) = pvVar4;
    *(void **)pvVar4 = pvVar4;
    *(int *)(*(int *)((int)this + 0x50) + 4) = *(int *)((int)this + 0x50);
    *(int *)(*(int *)((int)this + 0x50) + 8) = *(int *)((int)this + 0x50);
    *(undefined1 *)(*(int *)((int)this + 0x50) + 0x44) = 1;
    *(undefined1 *)(*(int *)((int)this + 0x50) + 0x45) = 1;
    ExceptionList = local_10;
    return (undefined4 *)this;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_20,&param_1);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_20,(ThrowInfo *)&DAT_10033244);
}



// Function: FUN_1001b0c0 at 1001b0c0

void FUN_1001b0c0(void)

{
  WCHAR WVar1;
  short sVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  void *extraout_EAX;
  void *extraout_EAX_00;
  short *psVar7;
  LPCWSTR pWVar8;
  WCHAR *pWVar9;
  ushort *puVar10;
  uint uVar11;
  int **ppiVar12;
  undefined4 ****ppppuVar13;
  void *pvVar14;
  IUnknownVtbl *pIVar15;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar16;
  LPCWSTR ***ppppWVar17;
  undefined4 *puVar18;
  int in_stack_fffffcd4;
  ushort uVar19;
  int aiStack_310 [4];
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined4 uVar20;
  undefined4 uVar21;
  uint uStack_2d8;
  undefined4 *local_2c4;
  undefined4 *local_2c0;
  undefined4 local_2bc;
  int *local_2b4;
  int *local_2b0;
  int *local_2ac;
  int *local_2a8;
  undefined4 local_2a4;
  undefined4 local_294;
  uint local_290;
  void *local_288 [4];
  undefined4 local_278;
  uint local_274;
  LPCWSTR **local_26c [4];
  undefined4 local_25c;
  uint local_258;
  void *local_250 [4];
  uint local_240;
  uint local_23c;
  undefined4 ***local_234 [4];
  undefined4 local_224;
  uint local_220;
  WCHAR local_218;
  undefined1 local_216 [510];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar19 = (ushort)((uint)in_stack_fffffcd4 >> 0x10);
  puStack_c = &LAB_10025906;
  local_10 = ExceptionList;
  uStack_2d8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2d8;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_2d8;
  GetCurrentThreadId();
  local_2b4 = (int *)&stack0xfffffd1c;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_2a8 = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar16 = extraout_ECX;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar5 = iVar6;
    piVar16 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar16 = extraout_ECX_01;
  }
  local_2a8 = (int *)&stack0xfffffd18;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffd18,0x10030418);
  pvVar14 = *(void **)(*local_2ac + 4);
  local_8._0_1_ = 3;
  if (pvVar14 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar14 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar14,piVar16,piVar5);
  GetCurrentThreadId();
  local_2b4 = (int *)&stack0xfffffd1c;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_2a8 = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar16 = extraout_ECX_02;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar5 = iVar6;
    piVar16 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar16 = extraout_ECX_04;
  }
  uVar21 = 4;
  uVar20 = 1;
  local_2a8 = (int *)&stack0xfffffd10;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffd10,0x10030398);
  piVar4 = local_2ac;
  pvVar14 = *(void **)(*local_2ac + 4);
  local_8._0_1_ = 6;
  if (pvVar14 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar14 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar14,piVar16,uVar20,uVar21,piVar5);
  FUN_10019b10(*(int **)(piVar4[0x14] + 4));
  *(int *)(piVar4[0x14] + 4) = piVar4[0x14];
  *(int *)piVar4[0x14] = piVar4[0x14];
  *(int *)(piVar4[0x14] + 8) = piVar4[0x14];
  pWVar8 = (LPCWSTR)(piVar4 + 1);
  piVar4[0x15] = 0;
  if (7 < (uint)piVar4[6]) {
    pWVar8 = *(LPCWSTR *)pWVar8;
  }
  GetPrivateProfileStringW
            ((LPCWSTR)PTR_u_VendorInformation_1003ade4,(LPCWSTR)PTR_u_Protocols_1003adec,
             (LPCWSTR)PTR_DAT_1003add4,&local_218,0x100,pWVar8);
  pWVar9 = &local_218;
  local_290 = 7;
  local_294 = 0;
  local_2a4 = (void *)((uint)local_2a4._2_2_ << 0x10);
  do {
    WVar1 = *pWVar9;
    pWVar9 = pWVar9 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(&local_2a4,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
  local_2c4 = (undefined4 *)0x0;
  local_2c0 = (undefined4 *)0x0;
  local_2bc = 0;
  local_8._0_1_ = 8;
  FUN_1001f480(&local_2a4,0x2c,&local_2c4);
  iVar6 = (int)local_2c0 - (int)local_2c4 >> 0x1f;
  if (((int)local_2c0 - (int)local_2c4) / 0x1c + iVar6 == iVar6) {
    pIVar15 = (IUnknownVtbl *)FUN_10019440();
    local_8._0_1_ = 0xd;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar15 + 0x14))->lpVtbl) {
      pIVar15 = ((IUnknown *)pIVar15)->lpVtbl;
    }
    uStack_2fc = 0x1001b6e7;
    FUN_10014d70((void *)*piVar4,0x428,0x20,(IUnknown *)pIVar15,
                 (IUnknown *)L"CRP1210IniFile::setProtocolVsDeviceIDsMap",(int *)0x4,(IID *)0x0,
                 (int *)L"RP1210IniFile.cpp",(undefined1 *)0xab);
    local_8._0_1_ = 8;
    if (7 < local_274) {
      operator_delete(local_288[0]);
    }
    local_2b4 = (int *)&stack0xfffffd0c;
    FUN_10019440();
    local_2a8 = aiStack_310;
    uStack_2fc = 7;
    uStack_300 = 0;
    local_8._0_1_ = 0xe;
    aiStack_310[0]._0_2_ = 0;
    FUN_10003130(aiStack_310,(int *)L"CRP1210IniFile::setProtocolVsDeviceIDsMap ()",0x2c);
    local_2b0 = (int *)&stack0xfffffcd4;
    local_8._0_1_ = 0xf;
    pvVar14 = (void *)((uint)uVar19 << 0x10);
    FUN_10003130(&stack0xfffffcd4,(int *)L"RP1210IniFile.cpp",0x11);
    local_8._0_1_ = 8;
    FUN_100147a0(0xad,pvVar14);
  }
  else {
    for (iVar6 = 0; iVar6 < ((int)local_2c0 - (int)local_2c4) / 0x1c; iVar6 = iVar6 + 1) {
      local_26c[0] = (LPCWSTR **)((uint)local_26c[0] & 0xffff0000);
      local_258 = 7;
      local_25c = 0;
      psVar7 = (short *)PTR_u_ProtocolInformation_1003adf0;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_10003130(local_26c,(int *)PTR_u_ProtocolInformation_1003adf0,
                   (int)psVar7 - (int)(PTR_u_ProtocolInformation_1003adf0 + 2) >> 1);
      local_8._0_1_ = 9;
      FUN_10005a70(local_26c,local_2c4 + iVar6 * 7,0,0xffffffff);
      pWVar8 = (LPCWSTR)(local_2ac + 1);
      if (7 < (uint)local_2ac[6]) {
        pWVar8 = *(LPCWSTR *)pWVar8;
      }
      ppppWVar17 = (LPCWSTR ***)local_26c[0];
      if (local_258 < 8) {
        ppppWVar17 = local_26c;
      }
      GetPrivateProfileStringW
                ((LPCWSTR)ppppWVar17,(LPCWSTR)PTR_u_Devices_1003ade8,(LPCWSTR)PTR_DAT_1003add4,
                 &local_218,0x100,pWVar8);
      local_234[0] = (undefined4 ***)((uint)local_234[0] & 0xffff0000);
      pWVar9 = &local_218;
      local_220 = 7;
      local_224 = 0;
      do {
        WVar1 = *pWVar9;
        pWVar9 = pWVar9 + 1;
      } while (WVar1 != L'\0');
      FUN_10003130(local_234,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
      pWVar8 = (LPCWSTR)(local_2ac + 1);
      local_8._0_1_ = 10;
      if (7 < (uint)local_2ac[6]) {
        pWVar8 = *(LPCWSTR *)pWVar8;
      }
      ppppWVar17 = (LPCWSTR ***)local_26c[0];
      if (local_258 < 8) {
        ppppWVar17 = local_26c;
      }
      GetPrivateProfileStringW
                ((LPCWSTR)ppppWVar17,(LPCWSTR)PTR_u_ProtocolString_1003adf4,
                 (LPCWSTR)PTR_DAT_1003add4,&local_218,0x100,pWVar8);
      local_250[0] = (void *)((uint)local_250[0] & 0xffff0000);
      pWVar9 = &local_218;
      local_23c = 7;
      local_240 = 0;
      do {
        WVar1 = *pWVar9;
        pWVar9 = pWVar9 + 1;
      } while (WVar1 != L'\0');
      FUN_10003130(local_250,(int *)&local_218,(int)pWVar9 - (int)local_216 >> 1);
      piVar5 = local_2ac;
      local_2b0 = local_2ac + 0x13;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      local_2a8 = FUN_10018ee0(local_2b0,(ushort *)local_250);
      if (local_2a8 == (int *)local_2b0[1]) {
LAB_1001b533:
        local_2b4 = (int *)local_2b0[1];
        ppiVar12 = &local_2b4;
      }
      else {
        puVar10 = (ushort *)(local_2a8 + 3);
        if (7 < (uint)local_2a8[8]) {
          puVar10 = *(ushort **)puVar10;
        }
        uVar11 = FUN_10005600(local_250,0,local_240,puVar10,local_2a8[7]);
        if ((int)uVar11 < 0) goto LAB_1001b533;
        ppiVar12 = &local_2a8;
      }
      if (*ppiVar12 != (int *)piVar5[0x14]) {
        local_274 = 7;
        local_8._0_1_ = 0xc;
        local_278 = 0;
        local_288[0] = (void *)((uint)local_288[0] & 0xffff0000);
        piVar5 = FUN_10005a70(local_288,*ppiVar12 + 10,0,0xffffffff);
        piVar5 = FUN_10005cf0(piVar5,(int *)&DAT_1003024c,1);
        FUN_10005a70(piVar5,local_234,0,0xffffffff);
        local_224 = 0;
        ppppuVar13 = (undefined4 ****)local_234[0];
        if (local_220 < 8) {
          ppppuVar13 = local_234;
        }
        *(undefined2 *)ppppuVar13 = 0;
        FUN_10003030(local_234,(int *)local_288,0,0xffffffff);
        local_8 = CONCAT31(local_8._1_3_,0xb);
        if (7 < local_274) {
          operator_delete(local_288[0]);
        }
      }
      pvVar14 = (void *)FUN_1001ae70(local_2b0,(ushort *)local_250);
      FUN_10003030(pvVar14,(int *)local_234,0,0xffffffff);
      if (7 < local_23c) {
        operator_delete(local_250[0]);
      }
      local_23c = 7;
      local_240 = 0;
      local_250[0] = (void *)((uint)local_250[0] & 0xffff0000);
      if (7 < local_220) {
        operator_delete(local_234[0]);
      }
      local_220 = 7;
      local_224 = 0;
      local_234[0] = (undefined4 ***)((uint)local_234[0] & 0xffff0000);
      local_8._0_1_ = 8;
      if (7 < local_258) {
        operator_delete(local_26c[0]);
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,7);
  if (local_2c4 != (undefined4 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2c4);
    puVar3 = local_2c0;
    for (puVar18 = local_2c4; puVar18 != puVar3; puVar18 = puVar18 + 7) {
      if (7 < (uint)puVar18[5]) {
        operator_delete((void *)*puVar18);
      }
      puVar18[5] = 7;
      puVar18[4] = 0;
      *(undefined2 *)puVar18 = 0;
    }
    operator_delete(local_2c4);
  }
  local_2c4 = (undefined4 *)0x0;
  local_2c0 = (undefined4 *)0x0;
  local_2bc = 0;
  if (7 < local_290) {
    operator_delete(local_2a4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001b81e at 1001b81e

undefined * Catch_1001b81e(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x2c4),"RP1210IniFile.cpp",0xb3,
               "CRP1210IniFile::setProtocolVsDeviceIDsMap",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001b86c;
}



// Function: Catch_All@1001b86e at 1001b86e

undefined4 Catch_All_1001b86e(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x224) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x220) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x21c) = 0;
  *(undefined4 *)(unaff_EBP + -0x218) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_10020630((void *)(unaff_EBP + -0x224),"RP1210IniFile.cpp",0xb3,
               "CRP1210IniFile::setProtocolVsDeviceIDsMap",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001b8e7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x224));
  return 0x1001b802;
}



// Function: FUN_1001b8f0 at 1001b8f0

void FUN_1001b8f0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uStack_250;
  undefined4 *local_228;
  undefined4 *local_224;
  undefined4 local_220;
  int *local_218;
  int *local_214;
  undefined4 local_210 [56];
  void *local_130 [4];
  undefined4 local_120;
  undefined4 local_11c;
  undefined2 local_114;
  undefined4 local_104;
  undefined4 local_100;
  undefined2 local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined2 local_dc;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined2 local_c0 [8];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined2 local_a4;
  undefined4 local_94;
  undefined4 local_90;
  undefined2 local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100259b4;
  local_10 = ExceptionList;
  uStack_250 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_250;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_250;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_214 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar3 = iVar4;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_214 = (int *)&stack0xfffffda0;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffda0,0x10030508);
  pvVar5 = *(void **)(*local_218 + 4);
  local_8._0_1_ = 3;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar5,piVar6,piVar3);
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_214 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar6 = extraout_ECX_02;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar3 = iVar4;
    piVar6 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_04;
  }
  uVar10 = 4;
  uVar9 = 1;
  local_214 = (int *)&stack0xfffffd98;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffd98,0x100304a0);
  piVar2 = local_218;
  pvVar5 = *(void **)(*local_218 + 4);
  local_8._0_1_ = 6;
  if (pvVar5 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar5 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar5,piVar6,uVar9,uVar10,piVar3);
  local_214 = *(int **)piVar2[0x14];
  do {
    while( true ) {
      do {
        piVar3 = local_214;
        if (local_214 == (int *)local_218[0x14]) {
          ExceptionList = local_10;
          __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
          return;
        }
        local_3c = 7;
        local_40 = 0;
        local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
        FUN_10003030(local_50,local_214 + 3,0,0xffffffff);
        local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
        local_8._0_1_ = 7;
        local_20 = 7;
        local_24 = 0;
        FUN_10003030(local_34,piVar3 + 10,0,0xffffffff);
        local_228 = (undefined4 *)0x0;
        local_224 = (undefined4 *)0x0;
        local_220 = 0;
        local_8 = CONCAT31(local_8._1_3_,9);
        FUN_1001f480((int *)local_34,0x2c,&local_228);
        iVar4 = (int)local_224 - (int)local_228 >> 0x1f;
        if (((int)local_224 - (int)local_228) / 0x1c + iVar4 != iVar4) {
          for (iVar4 = 0; iVar4 < ((int)local_224 - (int)local_228) / 0x1c; iVar4 = iVar4 + 1) {
            local_11c = 7;
            local_120 = 0;
            local_130[0]._0_2_ = 0;
            local_100 = 7;
            local_104 = 0;
            local_114 = 0;
            local_e4 = 7;
            local_e8 = 0;
            local_f8 = 0;
            local_c8 = 7;
            local_cc = 0;
            local_dc = 0;
            local_ac = 7;
            local_b0 = 0;
            local_c0[0] = 0;
            local_90 = 7;
            local_94 = 0;
            local_a4 = 0;
            local_74 = 7;
            local_78 = 0;
            local_88 = 0;
            local_58 = 7;
            local_5c = 0;
            local_6c = 0;
            local_8._0_1_ = 10;
            piVar3 = (int *)FUN_1001a700(local_218,(undefined2 *)local_210,local_228 + iVar4 * 7);
            local_8._0_1_ = 0xb;
            FUN_10019190(local_130,piVar3);
            local_8 = CONCAT31(local_8._1_3_,10);
            FUN_10005b80(local_210);
            FUN_10003030(local_c0,(int *)local_50,0,0xffffffff);
            FUN_1001adb0(local_218 + 0xf,local_130);
            FUN_10005b80(local_130);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,8);
        if (local_228 != (undefined4 *)0x0) {
          std::_Container_base0::_Orphan_all((_Container_base0 *)&local_228);
          puVar1 = local_224;
          for (puVar7 = local_228; puVar7 != puVar1; puVar7 = puVar7 + 7) {
            if (7 < (uint)puVar7[5]) {
              operator_delete((void *)*puVar7);
            }
            puVar7[5] = 7;
            puVar7[4] = 0;
            *(undefined2 *)puVar7 = 0;
          }
          operator_delete(local_228);
        }
        local_228 = (undefined4 *)0x0;
        local_224 = (undefined4 *)0x0;
        local_220 = 0;
        if (7 < local_20) {
          operator_delete(local_34[0]);
        }
        local_20 = 7;
        local_24 = 0;
        local_34[0] = (void *)((uint)local_34[0] & 0xffff0000);
        local_8 = local_8 & 0xffffff00;
        if (7 < local_3c) {
          operator_delete(local_50[0]);
        }
      } while (*(char *)((int)local_214 + 0x45) != '\0');
      piVar3 = (int *)local_214[2];
      piVar6 = local_214;
      if (*(char *)(local_214[2] + 0x45) != '\0') break;
      do {
        local_214 = piVar3;
        piVar3 = (int *)*local_214;
      } while (*(char *)(*local_214 + 0x45) == '\0');
    }
    do {
      local_214 = (int *)piVar6[1];
      if (*(char *)((int)local_214 + 0x45) != '\0') break;
      bVar8 = piVar6 == (int *)local_214[2];
      piVar6 = local_214;
    } while (bVar8);
  } while( true );
}



// Function: Catch@1001bd52 at 1001bd52

undefined4 Catch_1001bd52(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x23c),"RP1210IniFile.cpp",0xde,
               "CRP1210IniFile::readDeviceInfoForAllDeviceIDs",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return 0x1001bda0;
}



// Function: Catch_All@1001bdbc at 1001bdbc

undefined4 Catch_All_1001bdbc(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x238) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x234) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x230) = 0;
  *(undefined4 *)(unaff_EBP + -0x22c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10020630((void *)(unaff_EBP + -0x238),"RP1210IniFile.cpp",0xde,
               "CRP1210IniFile::readDeviceInfoForAllDeviceIDs",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001be35;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x238));
  return 0x1001bda0;
}



// Function: FUN_1001be40 at 1001be40

void FUN_1001be40(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *extraout_EAX_00;
  void *pvVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar7;
  undefined4 uVar8;
  uint uStack_44;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10025a1e;
  local_10 = ExceptionList;
  uStack_44 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  local_1c = (undefined4 *)&stack0xffffffb0;
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_20 = piVar2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *piVar2 = iVar3;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_20 = (int *)&stack0xffffffac;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x100305d0);
  piVar1 = local_18;
  pvVar6 = *(void **)(*local_18 + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar7,piVar2);
  GetCurrentThreadId();
  local_20 = (int *)&stack0xffffffb0;
  local_18 = (int *)&stack0xffffffb0;
  piVar2 = extraout_ECX_02;
  puVar4 = (undefined4 *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_1c = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
    piVar7 = extraout_ECX_03;
  }
  else {
    puVar4[1] = 0;
    puVar4[2] = 1;
    uVar5 = ConvertStringToBSTR("RP1210IniFile.cpp");
    *puVar4 = uVar5;
    piVar7 = extraout_ECX_04;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  *local_18 = (int)puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_05;
  }
  uVar8 = 4;
  uVar5 = 1;
  local_1c = (undefined4 *)&stack0xffffffa4;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffffa4,0x10030580);
  pvVar6 = *(void **)(*piVar1 + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005e10(pvVar6,piVar7,uVar5,uVar8,piVar2);
  FUN_1001a220(piVar1 + 0xf,&local_20,(int *)piVar1[0xf],(int *)piVar1[0x10]);
  FUN_1001b0c0();
  FUN_1001b8f0();
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001bfc2 at 1001bfc2

undefined1 * Catch_1001bfc2(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"RP1210IniFile.cpp",0x6c,"CRP1210IniFile::ReadFile",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_1001c00a;
}



// Function: Catch_All@1001c01c at 1001c01c

undefined4 Catch_All_1001c01c(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10020630((void *)(unaff_EBP + -0x30),"RP1210IniFile.cpp",0x6c,"CRP1210IniFile::ReadFile",
               0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1001c080;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1001bfb0;
}



// Function: FUN_1001c090 at 1001c090

undefined4 __thiscall FUN_1001c090(void *this,char *param_1)

{
  void *pvVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if ((char *)0x1249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
  pvVar1 = FUN_10018dd0(param_1);
  *(void **)((int)this + 8) = (void *)((int)param_1 * 0xe0 + (int)pvVar1);
  *(void **)this = pvVar1;
  *(void **)((int)this + 4) = pvVar1;
  return CONCAT31((int3)((uint)pvVar1 >> 8),1);
}



// Function: FUN_1001c0f0 at 1001c0f0

void * __cdecl FUN_1001c0f0(int *param_1,int *param_2,void *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != param_2) {
    piVar2 = param_1 + 0xe;
    do {
      FUN_10003030(param_3,piVar2 + -0xe,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0x1c),piVar2 + -7,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0x38),piVar2,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0x54),piVar2 + 7,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0x70),piVar2 + 0xe,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0x8c),piVar2 + 0x15,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0xa8),piVar2 + 0x1c,0,0xffffffff);
      FUN_10003030((void *)((int)param_3 + 0xc4),piVar2 + 0x23,0,0xffffffff);
      piVar1 = piVar2 + 0x2a;
      param_3 = (void *)((int)param_3 + 0xe0);
      piVar2 = piVar2 + 0x38;
    } while (piVar1 != param_2);
    return param_3;
  }
  return param_3;
}



// Function: FUN_1001c1c0 at 1001c1c0

void FUN_1001c1c0(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003ae14);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001c250 at 1001c250

void * __cdecl FUN_1001c250(int *param_1,int *param_2,void *param_3)

{
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_10025a51;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x38) {
    local_8 = 1;
    if (param_3 != (void *)0x0) {
      FUN_10019230(param_3,param_1);
    }
    param_3 = (void *)((int)param_3 + 0xe0);
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}



// Function: Catch_All@1001c2c1 at 1001c2c1

void Catch_All_1001c2c1(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  for (puVar2 = *(undefined4 **)(unaff_EBP + -0x14); puVar2 != puVar1; puVar2 = puVar2 + 0x38) {
    FUN_10005b80(puVar2);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001c300 at 1001c300

void __cdecl FUN_1001c300(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *this;
  int *piVar5;
  int *piVar6;
  int *this_00;
  int *unaff_FS_OFFSET;
  int local_f8;
  int local_f4 [56];
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025a7b;
  local_10 = *unaff_FS_OFFSET;
  local_14 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  iVar2 = ((int)param_3 - (int)param_1) / 0xe0;
  iVar1 = (param_2 - (int)param_1) / 0xe0;
  iVar4 = iVar1;
  local_f8 = iVar2;
  while (iVar3 = iVar4, iVar3 != 0) {
    iVar4 = local_f8 % iVar3;
    local_f8 = iVar3;
  }
  if ((local_f8 < iVar2) && (0 < local_f8)) {
    piVar6 = param_1 + local_f8 * 0x38;
    do {
      piVar5 = param_1;
      this_00 = piVar6;
      if (piVar6 + iVar1 * 0x38 != param_3) {
        piVar5 = piVar6 + iVar1 * 0x38;
      }
      do {
        this = piVar5;
        FUN_10019230(local_f4,this_00);
        local_8 = 0;
        FUN_10019190(this_00,this);
        FUN_10019190(this,local_f4);
        local_8 = 0xffffffff;
        FUN_10005b80(local_f4);
        iVar2 = ((int)param_3 - (int)this) / 0xe0;
        if (iVar1 < iVar2) {
          piVar5 = this + iVar1 * 0x38;
        }
        else {
          piVar5 = param_1 + (iVar1 - iVar2) * 0x38;
        }
        this_00 = this;
      } while (piVar5 != piVar6);
      piVar6 = piVar6 + -0x38;
      local_f8 = local_f8 + -1;
    } while (0 < local_f8);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001c4b0 at 1001c4b0

void FUN_1001c4b0(int *param_1,int *param_2,void *param_3)

{
  FUN_10019a60(param_1,param_2,param_3);
  return;
}



// Function: FUN_1001c4e0 at 1001c4e0

int * __cdecl FUN_1001c4e0(int *param_1,int *param_2,int *param_3)

{
  if (param_1 == param_2) {
    return param_1;
  }
  if (param_2 != param_3) {
    FUN_1001c300(param_1,(int)param_2,param_3);
    return param_1 + (((int)param_3 - (int)param_2) / 0xe0) * 0x38;
  }
  return param_1;
}



// Function: FUN_1001c540 at 1001c540

int * __thiscall FUN_1001c540(void *this,int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int extraout_EAX;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  void *pvVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025ab0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar8 = (int *)(((int)param_3 - (int)param_2) * -0x6db6db6d);
  uVar3 = ((int)param_3 - (int)param_2) / 0xe0;
  if (uVar3 != 0) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    iVar4 = (*(int *)((int)this + 4) - iVar1) / 0xe0;
    if (0x1249249U - iVar4 < uVar3) {
      std::_Xlength_error("vector<T> too long");
      iVar4 = extraout_EAX;
    }
    if ((uint)((*(int *)((int)this + 8) - iVar1) / 0xe0) < iVar4 + uVar3) {
      pcVar5 = (char *)FUN_10018c80(this,iVar4 + uVar3);
      pvVar6 = FUN_10018dd0(pcVar5);
                    /* WARNING: Load size is inaccurate */
      local_8 = 0;
      pvVar7 = FUN_10019a60(*this,param_1,pvVar6);
      pvVar7 = FUN_1001c250(param_2,param_3,pvVar7);
      FUN_10019a60(param_1,*(int **)((int)this + 4),pvVar7);
                    /* WARNING: Load size is inaccurate */
      puVar2 = *this;
      iVar1 = *(int *)((int)this + 4);
      local_8 = 0xffffffff;
      if (puVar2 != (undefined4 *)0x0) {
        FUN_10019f70(puVar2,*(undefined4 **)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
        operator_delete(*this);
      }
      std::_Container_base0::_Orphan_all((_Container_base0 *)this);
      piVar8 = (int *)((int)pcVar5 * 0xe0 + (int)pvVar6);
      *(int **)((int)this + 8) = piVar8;
      *(void **)((int)this + 4) =
           (void *)((uVar3 + (iVar1 - (int)puVar2) / 0xe0) * 0xe0 + (int)pvVar6);
      *(void **)this = pvVar6;
      ExceptionList = local_10;
      return piVar8;
    }
    FUN_1001c250(param_2,param_3,*(void **)((int)this + 4));
    piVar8 = FUN_1001c4e0(param_1,*(int **)((int)this + 4),*(int **)((int)this + 4) + uVar3 * 0x38);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + uVar3 * 0xe0;
  }
  ExceptionList = local_10;
  return piVar8;
}



// Function: Catch_All@1001c6cd at 1001c6cd

void Catch_All_1001c6cd(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  FUN_10019f70(puVar1,*(undefined4 **)(unaff_EBP + -0x14));
  operator_delete(puVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001c740 at 1001c740

void __fastcall FUN_1001c740(int param_1)

{
  FUN_1001a290((_Container_base0 *)(param_1 + 4));
  return;
}



// Function: FUN_1001c750 at 1001c750

_Container_base0 * __thiscall FUN_1001c750(void *this,_Container_base0 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  _Container_base0 *p_Var5;
  undefined4 *puVar6;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  
  p_Var5 = param_1;
  if ((_Container_base0 *)this != param_1) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    iVar9 = *(int *)(p_Var5 + 4) - *(int *)p_Var5;
    iVar3 = iVar9 >> 0x1f;
    iVar9 = iVar9 / 0xe0 + iVar3;
    uVar10 = iVar9 - iVar3;
    if (iVar9 == iVar3) {
                    /* WARNING: Load size is inaccurate */
      FUN_1001a220(this,&param_1,*this,*(int **)((int)this + 4));
      return (_Container_base0 *)this;
    }
                    /* WARNING: Load size is inaccurate */
    puVar2 = *this;
    uVar4 = (*(int *)((int)this + 4) - (int)puVar2) / 0xe0;
    if (uVar10 <= uVar4) {
      puVar6 = (undefined4 *)FUN_1001c0f0(*(int **)param_1,*(int **)(param_1 + 4),puVar2);
      puVar2 = *(undefined4 **)((int)this + 4);
      for (; puVar6 != puVar2; puVar6 = puVar6 + 0x38) {
        FUN_10005b80(puVar6);
      }
                    /* WARNING: Load size is inaccurate */
      *(int *)((int)this + 4) = ((*(int *)(param_1 + 4) - *(int *)param_1) / 0xe0) * 0xe0 + *this;
      return (_Container_base0 *)this;
    }
    if (uVar10 <= (uint)((*(int *)((int)this + 8) - (int)puVar2) / 0xe0)) {
      piVar1 = *(int **)param_1 + uVar4 * 0x38;
      FUN_1001c0f0(*(int **)param_1,piVar1,puVar2);
      pvVar7 = FUN_10019a60(piVar1,*(int **)(param_1 + 4),*(void **)((int)this + 4));
      *(void **)((int)this + 4) = pvVar7;
      return (_Container_base0 *)this;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_10019f70(puVar2,*(undefined4 **)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    p_Var5 = param_1;
    uVar8 = FUN_1001c090(this,(char *)((*(int *)(param_1 + 4) - *(int *)param_1) / 0xe0));
    if ((char)uVar8 != '\0') {
                    /* WARNING: Load size is inaccurate */
      uVar8 = FUN_1001c4b0(*(int **)p_Var5,*(int **)(p_Var5 + 4),*this);
      *(undefined4 *)((int)this + 4) = uVar8;
    }
  }
  return (_Container_base0 *)this;
}



// Function: FUN_1001c8f0 at 1001c8f0

void __thiscall
FUN_1001c8f0(void *this,int param_1,int *param_2,int *param_3,int *param_4,void *param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  ushort *puVar10;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar11;
  int iVar12;
  ushort ****ppppuVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uStack_1b4;
  int local_16c;
  void *local_168 [28];
  ushort ***local_f8 [4];
  uint local_e8;
  uint local_e4;
  ushort ***local_dc [4];
  uint local_cc;
  uint local_c8;
  undefined1 local_a4 [28];
  undefined4 local_88;
  undefined4 local_78;
  uint local_74;
  undefined4 local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  uint local_40;
  uint local_3c;
  undefined4 local_34;
  uint local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025b51;
  local_10 = ExceptionList;
  uStack_1b4 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1b4;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_1b4;
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar11 = extraout_ECX;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar4 = iVar5;
    piVar11 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar11 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffe3c,0x10030760);
                    /* WARNING: Load size is inaccurate */
  pvVar6 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar6,piVar11,piVar4);
  GetCurrentThreadId();
  piVar4 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    piVar11 = extraout_ECX_02;
  }
  else {
    piVar4[1] = 0;
    piVar4[2] = 1;
    iVar5 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar4 = iVar5;
    piVar11 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar4 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar11 = extraout_ECX_04;
  }
  uVar16 = 4;
  uVar15 = 1;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffe34,0x100306c8);
                    /* WARNING: Load size is inaccurate */
  pvVar6 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar6 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar6 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar6,piVar11,uVar15,uVar16,piVar4);
  iVar5 = param_3[1];
  iVar14 = *param_3;
  iVar2 = (param_2[1] - *param_2) / 0x1c;
  iVar3 = (param_4[1] - *param_4) / 0xe0;
  local_3c = 7;
  local_40 = 0;
  local_50 = (ushort *)((uint)local_50._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  local_34 = (ushort *)((uint)local_34._2_2_ << 0x10);
  FUN_10018e30((undefined2 *)local_168);
  local_8._0_1_ = 9;
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c._2_2_ << 0x10);
  FUN_10003130(&local_6c,(int *)L"COM Port Auto Detect",0x14);
  local_88 = (void *)((uint)local_88._2_2_ << 0x10);
  local_8._0_1_ = 10;
  local_74 = 7;
  local_78 = 0;
  FUN_10003130(&local_88,(int *)L"Auto Detect",0xb);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  if (param_1 == 0) {
    for (local_16c = param_1; local_16c < (iVar5 - iVar14) / 0x1c; local_16c = local_16c + 1) {
      FUN_10003030(&local_50,(int *)(*param_3 + local_16c * 0x1c),0,0xffffffff);
      for (iVar12 = 0; iVar12 < iVar2; iVar12 = iVar12 + 1) {
        FUN_10003030(&local_34,(int *)(*param_2 + iVar12 * 0x1c),0,0xffffffff);
        for (iVar7 = 0; iVar7 < iVar3; iVar7 = iVar7 + 1) {
          FUN_10019190(local_168,(int *)(iVar7 * 0xe0 + *param_4));
          psVar9 = (short *)PTR_u_Cummins_1003ae1c;
          do {
            sVar1 = *psVar9;
            psVar9 = psVar9 + 1;
          } while (sVar1 != 0);
          uVar8 = FUN_100137e0(local_a4,(ushort *)PTR_u_Cummins_1003ae1c,0,
                               (int)psVar9 - (int)(PTR_u_Cummins_1003ae1c + 2) >> 1);
          if (uVar8 != 0xffffffff) {
            puVar10 = local_50;
            if (local_3c < 8) {
              puVar10 = (ushort *)&local_50;
            }
            uVar8 = local_40;
            if (local_cc < local_40) {
              uVar8 = local_cc;
            }
            ppppuVar13 = (ushort ****)local_dc[0];
            if (local_c8 < 8) {
              ppppuVar13 = local_dc;
            }
            for (; uVar8 != 0; uVar8 = uVar8 - 1) {
              if (*(ushort *)ppppuVar13 != *puVar10) {
                if ((-(uint)(*(ushort *)ppppuVar13 < *puVar10) & 0xfffffffe) != 0xffffffff)
                goto LAB_1001cd53;
                break;
              }
              ppppuVar13 = (ushort ****)((int)ppppuVar13 + 2);
              puVar10 = puVar10 + 1;
            }
            if ((local_40 <= local_cc) && (local_cc == local_40)) {
              puVar10 = local_34;
              if (local_20 < 8) {
                puVar10 = (ushort *)&local_34;
              }
              uVar8 = local_24;
              if (local_e8 < local_24) {
                uVar8 = local_e8;
              }
              ppppuVar13 = (ushort ****)local_f8[0];
              if (local_e4 < 8) {
                ppppuVar13 = local_f8;
              }
              for (; uVar8 != 0; uVar8 = uVar8 - 1) {
                if (*(ushort *)ppppuVar13 != *puVar10) {
                  if ((-(uint)(*(ushort *)ppppuVar13 < *puVar10) & 0xfffffffe) != 0xffffffff)
                  goto LAB_1001cd53;
                  break;
                }
                ppppuVar13 = (ushort ****)((int)ppppuVar13 + 2);
                puVar10 = puVar10 + 1;
              }
              if ((local_24 <= local_e8) && (local_e8 == local_24)) {
                psVar9 = (short *)PTR_u_Cummins__Inc__1003ae18;
                do {
                  sVar1 = *psVar9;
                  psVar9 = psVar9 + 1;
                } while (sVar1 != 0);
                FUN_10003130(local_a4,(int *)PTR_u_Cummins__Inc__1003ae18,
                             (int)psVar9 - (int)(PTR_u_Cummins__Inc__1003ae18 + 2) >> 1);
                FUN_1001adb0(param_5,local_168);
              }
            }
          }
LAB_1001cd53:
        }
      }
    }
  }
  else if (param_1 == 1) {
    for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
      FUN_10003030(&local_34,(int *)(*param_2 + iVar5 * 0x1c),0,0xffffffff);
      for (iVar14 = 0; iVar14 < iVar3; iVar14 = iVar14 + 1) {
        FUN_10019190(local_168,(int *)(iVar14 * 0xe0 + *param_4));
        psVar9 = (short *)PTR_u_Cummins_1003ae1c;
        do {
          sVar1 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar1 != 0);
        uVar8 = FUN_100137e0(local_a4,(ushort *)PTR_u_Cummins_1003ae1c,0,
                             (int)psVar9 - (int)(PTR_u_Cummins_1003ae1c + 2) >> 1);
        if (uVar8 == 0xffffffff) {
          puVar10 = local_34;
          if (local_20 < 8) {
            puVar10 = (ushort *)&local_34;
          }
          uVar8 = FUN_10005600(local_f8,0,local_e8,puVar10,local_24);
          if (uVar8 == 0) {
            FUN_1001adb0(param_5,local_168);
          }
        }
      }
    }
  }
  if (7 < local_74) {
    operator_delete(local_88);
  }
  local_74 = 7;
  local_78 = 0;
  local_88 = (void *)((uint)local_88 & 0xffff0000);
  if (7 < local_58) {
    operator_delete(local_6c);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffff0000);
  FUN_10005b80(local_168);
  if (7 < local_20) {
    operator_delete(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (ushort *)((uint)local_34 & 0xffff0000);
  if (7 < local_3c) {
    operator_delete(local_50);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001cf24 at 1001cf24

undefined * Catch_1001cf24(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x1a0),"RP1210IniFileReader.cpp",0x106,
               "CRP1210IniFileReader::getRP1210DataForDetectedPortsAndProtocols",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  return &DAT_1001cf72;
}



// Function: Catch_All@1001cf74 at 1001cf74

undefined4 Catch_All_1001cf74(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x19c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x198) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x194) = 0;
  *(undefined4 *)(unaff_EBP + -400) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10020630((void *)(unaff_EBP + -0x19c),"RP1210IniFileReader.cpp",0x106,
               "CRP1210IniFileReader::getRP1210DataForDetectedPortsAndProtocols",0x3ed7ac9c,
               0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1001cfed;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x19c));
  return 0x1001cf06;
}



// Function: FUN_1001d000 at 1001d000

void __thiscall FUN_1001d000(void *this,int param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *extraout_EAX_00;
  IUnknownVtbl *pIVar3;
  void *extraout_EAX_01;
  void *pvVar4;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar5;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  undefined4 in_stack_ffffff3c;
  ushort uVar6;
  undefined2 auStack_a8 [8];
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uStack_70;
  int *local_38;
  void *local_34;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar6 = (ushort)((uint)in_stack_ffffff3c >> 0x10);
  puStack_c = &LAB_10025bee;
  local_10 = ExceptionList;
  uStack_70 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_70;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_70;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_38 = piVar1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_01;
  }
  local_38 = (int *)&stack0xffffff80;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff80,0x10030cc8);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 3;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar4,piVar5,piVar1);
  GetCurrentThreadId();
  local_38 = (int *)&stack0xffffff84;
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar5 = extraout_ECX_02;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar1 = iVar2;
    piVar5 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar5 = extraout_ECX_04;
  }
  uVar8 = 4;
  uVar7 = 1;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xffffff78,0x10030c84);
                    /* WARNING: Load size is inaccurate */
  pvVar4 = *(void **)(*this + 4);
  local_8._0_1_ = 6;
  if (pvVar4 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar4 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar4,piVar5,uVar7,uVar8,piVar1);
  FUN_1001a220(param_4,&local_38,(int *)*param_4,(int *)param_4[1]);
  FUN_1001c8f0(this,param_1,param_2,param_3,(int *)((int)this + 4),param_4);
  iVar2 = param_4[1] - *param_4 >> 0x1f;
  if ((param_4[1] - *param_4) / 0xe0 + iVar2 == iVar2) {
    pIVar3 = (IUnknownVtbl *)FUN_1001c1c0();
    local_8._0_1_ = 7;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
      pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
    }
                    /* WARNING: Load size is inaccurate */
    uStack_94 = 0x1001d1e8;
    FUN_10014d70(*this,0x425,0x20,(IUnknown *)pIVar3,
                 (IUnknown *)L"CRP1210IniFileReader::getRP1210DeviceInformation",(int *)0x4,
                 (IID *)0x0,(int *)L"RP1210IniFileReader.cpp",(undefined1 *)0x5e);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
    GetCurrentThreadId();
    local_38 = (int *)&stack0xffffff84;
    piVar5 = extraout_ECX_05;
    FUN_10001e80(&stack0xffffff84,"RP1210IniFileReader.cpp");
    uVar8 = 4;
    uVar7 = 1;
    local_8._0_1_ = 8;
    piVar1 = extraout_ECX_06;
    FUN_10001f10(&stack0xffffff78,0x10030b38);
                    /* WARNING: Load size is inaccurate */
    pvVar4 = *(void **)(*this + 4);
    local_8._0_1_ = 9;
    if (pvVar4 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar4 = extraout_EAX_01;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10005e10(pvVar4,piVar1,uVar7,uVar8,piVar5);
  }
  else {
    pIVar3 = (IUnknownVtbl *)FUN_1001c1c0();
    local_8._0_1_ = 10;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar3 + 0x14))->lpVtbl) {
      pIVar3 = ((IUnknown *)pIVar3)->lpVtbl;
    }
                    /* WARNING: Load size is inaccurate */
    uStack_94 = 0x1001d2a4;
    FUN_10014d70(*this,0x427,0x20,(IUnknown *)pIVar3,
                 (IUnknown *)L"CRP1210IniFileReader::GetRP1210DeviceInformation",(int *)0x4,
                 (IID *)0x0,(int *)L"RP1210IniFileReader.cpp",(undefined1 *)0x66);
    local_8._0_1_ = 0;
    if (7 < local_20) {
      operator_delete(local_34);
    }
    local_38 = (int *)&stack0xffffff74;
    FUN_1001c1c0();
    uStack_94 = 7;
    uStack_98 = 0;
    local_8._0_1_ = 0xb;
    auStack_a8[0] = 0;
    FUN_10003130(auStack_a8,(int *)L"CRP1210IniFileReader::GetRP1210DeviceInformation ()",0x33);
    local_8._0_1_ = 0xc;
    pvVar4 = (void *)((uint)uVar6 << 0x10);
    FUN_10003130(&stack0xffffff3c,(int *)L"RP1210IniFileReader.cpp",0x17);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_100147a0(0x68,pvVar4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001d326 at 1001d326

undefined * Catch_1001d326(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x5c),"RP1210IniFileReader.cpp",0x6d,
               "CRP1210IniFileReader::GetRP1210DeviceInformation",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001d36e;
}



// Function: Catch_All@1001d373 at 1001d373

undefined4 Catch_All_1001d373(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x58) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10020630((void *)(unaff_EBP + -0x58),"RP1210IniFileReader.cpp",0x6d,
               "CRP1210IniFileReader::GetRP1210DeviceInformation",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001d3d7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x58));
  return 0x1001d24e;
}



// Function: FUN_1001d3e0 at 1001d3e0

void __thiscall FUN_1001d3e0(void *this,int *param_1)

{
  short sVar1;
  WCHAR WVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar7;
  short *psVar8;
  HANDLE pvVar9;
  LPCWSTR pWVar10;
  WCHAR *pWVar11;
  IUnknownVtbl *pIVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uStack_8d4;
  _WIN32_FIND_DATAW local_88c;
  undefined4 local_63c;
  undefined4 local_62c;
  uint local_628;
  undefined4 local_620;
  undefined4 local_610;
  uint local_60c;
  void *local_604 [4];
  undefined4 local_5f4;
  uint local_5f0;
  undefined4 local_5e8;
  undefined4 local_5d8;
  uint local_5d4;
  undefined4 local_5cc;
  undefined4 local_5bc;
  uint local_5b8;
  undefined1 local_5b0 [400];
  WCHAR local_420;
  undefined1 local_41e [510];
  WCHAR local_220;
  undefined1 local_21e [518];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025ce1;
  local_10 = ExceptionList;
  uStack_8d4 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_8d4;
  ExceptionList = &local_10;
  local_18 = uStack_8d4;
  _eh_vector_constructor_iterator_
            (local_5b0,0x10,0x19,(_func_void_void_ptr *)&LAB_100056e0,FUN_1000b0e0);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  GetCurrentThreadId();
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 2;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar13 = extraout_ECX;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar5 = iVar6;
    piVar13 = extraout_ECX_00;
  }
  local_8._0_1_ = 1;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar13 = extraout_ECX_01;
  }
  local_8._0_1_ = 3;
  FUN_10001f10(&stack0xfffff71c,0x10030ec0);
                    /* WARNING: Load size is inaccurate */
  pvVar7 = *(void **)(*this + 4);
  local_8._0_1_ = 4;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX;
  }
  local_8._0_1_ = 1;
  FUN_10002f20(pvVar7,piVar13,piVar5);
  GetCurrentThreadId();
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar13 = extraout_ECX_02;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210IniFileReader.cpp");
    *piVar5 = iVar6;
    piVar13 = extraout_ECX_03;
  }
  local_8._0_1_ = 1;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar13 = extraout_ECX_04;
  }
  uVar15 = 4;
  uVar14 = 1;
  local_8._0_1_ = 6;
  FUN_10001f10(&stack0xfffff714,0x10030c84);
                    /* WARNING: Load size is inaccurate */
  pvVar7 = *(void **)(*this + 4);
  local_8._0_1_ = 7;
  if (pvVar7 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar7 = extraout_EAX_00;
  }
  local_8._0_1_ = 1;
  FUN_10005e10(pvVar7,piVar13,uVar14,uVar15,piVar5);
  GetWindowsDirectoryW(&local_220,0x104);
  local_63c = (void *)((uint)local_63c._2_2_ << 0x10);
  local_628 = 7;
  local_62c = 0;
  psVar8 = (short *)PTR_u_RP121032_ini_1003ae20;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_63c,(int *)PTR_u_RP121032_ini_1003ae20,
               (int)psVar8 - (int)(PTR_u_RP121032_ini_1003ae20 + 2) >> 1);
  local_620 = (void *)((uint)local_620._2_2_ << 0x10);
  local_8._0_1_ = 8;
  local_60c = 7;
  local_610 = 0;
  psVar8 = (short *)PTR_DAT_1003ae24;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_10003130(&local_620,(int *)PTR_DAT_1003ae24,(int)psVar8 - (int)(PTR_DAT_1003ae24 + 2) >> 1);
  pWVar11 = &local_220;
  local_8._0_1_ = 9;
  local_5d4 = 7;
  local_5d8 = 0;
  local_5e8 = (void *)((uint)local_5e8._2_2_ << 0x10);
  do {
    WVar2 = *pWVar11;
    pWVar11 = pWVar11 + 1;
  } while (WVar2 != L'\0');
  FUN_10003130(&local_5e8,(int *)&local_220,(int)pWVar11 - (int)local_21e >> 1);
  local_8._0_1_ = 10;
  psVar8 = (short *)PTR_DAT_1003ae24;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  piVar5 = FUN_10005cf0(&local_5e8,(int *)PTR_DAT_1003ae24,
                        (int)psVar8 - (int)(PTR_DAT_1003ae24 + 2) >> 1);
  local_5cc = (LPCWSTR)((uint)local_5cc._2_2_ << 0x10);
  local_5b8 = 7;
  local_5bc = 0;
  FUN_10003030(&local_5cc,piVar5,0,0xffffffff);
  local_8._0_1_ = 0xb;
  piVar5 = FUN_10005a70(&local_5e8,&local_63c,0,0xffffffff);
  FUN_10003030(&local_5cc,piVar5,0,0xffffffff);
  pWVar10 = local_5cc;
  if (local_5b8 < 8) {
    pWVar10 = (LPCWSTR)&local_5cc;
  }
  pvVar9 = FindFirstFileW(pWVar10,&local_88c);
  if (pvVar9 != (HANDLE)0xffffffff) {
    pWVar10 = local_5cc;
    if (local_5b8 < 8) {
      pWVar10 = (LPCWSTR)&local_5cc;
    }
    GetPrivateProfileStringW
              ((LPCWSTR)PTR_u_RP1210Support_1003ae30,(LPCWSTR)PTR_u_APIImplementations_1003ae34,
               (LPCWSTR)PTR_DAT_1003ae10,&local_420,0x100,pWVar10);
    local_604[0] = (void *)((uint)local_604[0] & 0xffff0000);
    pWVar11 = &local_420;
    local_5f0 = 7;
    local_5f4 = 0;
    do {
      WVar2 = *pWVar11;
      pWVar11 = pWVar11 + 1;
    } while (WVar2 != L'\0');
    FUN_10003130(local_604,(int *)&local_420,(int)pWVar11 - (int)local_41e >> 1);
    local_8._0_1_ = 0xc;
    FUN_1001f480((int *)local_604,0x2c,param_1);
    iVar6 = param_1[1];
    iVar3 = *param_1;
    iVar4 = iVar6 - iVar3 >> 0x1f;
    local_8._0_1_ = 0xb;
    if (7 < local_5f0) {
      operator_delete(local_604[0]);
    }
    if ((iVar6 - iVar3) / 0x1c + iVar4 != iVar4) goto LAB_1001d84b;
  }
  pIVar12 = (IUnknownVtbl *)FUN_1001c1c0();
  local_8._0_1_ = 0xf;
  if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar12 + 0x14))->lpVtbl) {
    pIVar12 = ((IUnknown *)pIVar12)->lpVtbl;
  }
                    /* WARNING: Load size is inaccurate */
  FUN_10014d70(*this,0x426,0x20,(IUnknown *)pIVar12,
               (IUnknown *)L"CRP1210IniFileReader::getAllRP1210DriverINIFiles",(int *)0x4,(IID *)0x0
               ,(int *)L"RP1210IniFileReader.cpp",(undefined1 *)0xaa);
  if (7 < local_5f0) {
    operator_delete(local_604[0]);
  }
LAB_1001d84b:
  if (7 < local_5b8) {
    operator_delete(local_5cc);
  }
  local_5b8 = 7;
  local_5bc = 0;
  local_5cc = (LPCWSTR)((uint)local_5cc & 0xffff0000);
  if (7 < local_5d4) {
    operator_delete(local_5e8);
  }
  local_5d4 = 7;
  local_5d8 = 0;
  local_5e8 = (void *)((uint)local_5e8 & 0xffff0000);
  if (7 < local_60c) {
    operator_delete(local_620);
  }
  local_60c = 7;
  local_610 = 0;
  local_620 = (void *)((uint)local_620 & 0xffff0000);
  if (7 < local_628) {
    operator_delete(local_63c);
  }
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(local_5b0,0x10,0x19,FUN_1000b0e0);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001d926 at 1001d926

undefined * Catch_1001d926(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x8a0),"RP1210IniFileReader.cpp",0xad,
               "CRP1210IniFileReader::getAllRP1210DriverINIFiles",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001d974;
}



// Function: Catch_All@1001d979 at 1001d979

undefined4 Catch_All_1001d979(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x5bc) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x5b8) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x5b4) = 0;
  *(undefined4 *)(unaff_EBP + -0x5b0) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_10020630((void *)(unaff_EBP + -0x5bc),"RP1210IniFileReader.cpp",0xad,
               "CRP1210IniFileReader::getAllRP1210DriverINIFiles",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001d9f2;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x5bc));
  return 0x1001d8e6;
}



// Function: FUN_1001da00 at 1001da00

void __fastcall FUN_1001da00(undefined4 *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  short *psVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *local_b4;
  undefined4 *local_b0;
  undefined4 local_ac;
  int *local_a4;
  int *local_a0;
  undefined4 local_9c;
  int local_94;
  int local_90;
  undefined1 local_8c [60];
  _Container_base0 local_50 [32];
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025d39;
  local_10 = ExceptionList;
  local_14 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b4 = (undefined4 *)0x0;
  local_b0 = (undefined4 *)0x0;
  local_ac = 0;
  local_8 = 0;
  cVar4 = FUN_1001d3e0(param_1,(int *)&local_b4);
  if (cVar4 == '\x01') {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    local_8._0_1_ = cVar4;
    FUN_1001afc0(local_8c,(char *)*param_1);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1001a220(param_1 + 1,&local_90,(int *)param_1[1],(int *)param_1[2]);
    local_90 = 0;
    if (0 < ((int)local_b0 - (int)local_b4) / 0x1c) {
      local_94 = 0;
      do {
        local_a4 = (int *)0x0;
        local_a0 = (int *)0x0;
        local_9c = 0;
        local_8._0_1_ = 3;
        FUN_10003030(local_30,(int *)(local_94 + (int)local_b4),0,0xffffffff);
        psVar5 = (short *)PTR_DAT_1003ae28;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_10005cf0(local_30,(int *)PTR_DAT_1003ae28,(int)psVar5 - (int)(PTR_DAT_1003ae28 + 2) >> 1
                    );
        psVar5 = (short *)PTR_DAT_1003ae2c;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_10005cf0(local_30,(int *)PTR_DAT_1003ae2c,(int)psVar5 - (int)(PTR_DAT_1003ae2c + 2) >> 1
                    );
        FUN_100194d0(local_8c,(int *)local_30);
        FUN_1001be40();
        FUN_1001c750(&local_a4,local_50);
        FUN_1001c540(param_1 + 1,(int *)param_1[2],local_a4,local_a0);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_a4 != (int *)0x0) {
          std::_Container_base0::_Orphan_all((_Container_base0 *)&local_a4);
          piVar3 = local_a0;
          for (piVar6 = local_a4; piVar6 != piVar3; piVar6 = piVar6 + 0x38) {
            FUN_10005b80(piVar6);
          }
          operator_delete(local_a4);
        }
        local_90 = local_90 + 1;
        local_94 = local_94 + 0x1c;
        local_a4 = (int *)0x0;
        local_a0 = (int *)0x0;
        local_9c = 0;
      } while (local_90 < ((int)local_b0 - (int)local_b4) / 0x1c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_1001a600((int)local_8c);
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  local_8 = 0xffffffff;
  if (local_b4 != (undefined4 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_b4);
    puVar2 = local_b0;
    for (puVar7 = local_b4; puVar7 != puVar2; puVar7 = puVar7 + 7) {
      if (7 < (uint)puVar7[5]) {
        operator_delete((void *)*puVar7);
      }
      puVar7[5] = 7;
      puVar7[4] = 0;
      *(undefined2 *)puVar7 = 0;
    }
    operator_delete(local_b4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001dcf0 at 1001dcf0

undefined4 * __thiscall FUN_1001dcf0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025d7b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_8 = 0;
  FUN_1001da00((undefined4 *)this);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001dd50 at 1001dd50

undefined4 * __thiscall
FUN_1001dd50(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  BOOL BVar1;
  
  *(undefined4 *)this = param_3;
  *(undefined4 *)((int)this + 4) = param_4;
  *(undefined1 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = param_2;
  *(undefined4 *)((int)this + 0x28) = param_1;
  FUN_1001dcf0((void *)((int)this + 0x2c),param_1);
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)((int)this + 0xc),0);
  if (BVar1 == 0) {
    GetLastError();
  }
  return (undefined4 *)this;
}



// Function: FUN_1001ddb0 at 1001ddb0

void __fastcall FUN_1001ddb0(int param_1)

{
  FUN_1001c740(param_1 + 0x2c);
  return;
}



// Function: FUN_1001ddc0 at 1001ddc0

void __fastcall FUN_1001ddc0(int param_1)

{
  int *piVar1;
  int iVar2;
  void *extraout_EAX;
  void *this;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10025dc3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  GetCurrentThreadId();
  piVar1 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
    piVar3 = extraout_ECX;
  }
  else {
    piVar1[1] = 0;
    piVar1[2] = 1;
    iVar2 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar1 = iVar2;
    piVar3 = extraout_ECX_00;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar3 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffffac,0x10031000);
  this = *(void **)(*(int *)(param_1 + 0x28) + 4);
  local_8._0_1_ = 3;
  if (this == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_EAX;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002f20(this,piVar3,piVar1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 8) = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001dea9 at 1001dea9

undefined1 * Catch_1001dea9(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x20),"RP1210ServiceConnection.cpp",0x129,
               "CRP1210ServiceConnection::Cancel",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  return &LAB_1001def4;
}



// Function: Catch_All@1001df06 at 1001df06

undefined4 Catch_All_1001df06(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x30) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10020630((void *)(unaff_EBP + -0x30),"RP1210ServiceConnection.cpp",0x129,
               "CRP1210ServiceConnection::Cancel",0x3ed7ac9c,0x46d59d92,0x81b10189,0x696e973b);
  uStack0000001c = 0x1001df6d;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return 0x1001de97;
}



// Function: FUN_1001df80 at 1001df80

undefined2 * __thiscall FUN_1001df80(void *this,undefined2 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *param_1 = 0;
  FUN_10003030(param_1,(int *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_1001dfc0 at 1001dfc0

void __thiscall FUN_1001dfc0(void *this,ushort *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  void *extraout_EAX;
  void *this_00;
  uint uVar5;
  ushort *puVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar7;
  uint uStack_68;
  int local_3c;
  undefined4 local_34;
  uint local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025e0b;
  local_10 = ExceptionList;
  uStack_68 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_68;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_68;
  GetCurrentThreadId();
  piVar3 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar3[1] = 0;
    piVar3[2] = 1;
    iVar4 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar3 = iVar4;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar3 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x10031090);
  this_00 = *(void **)(*(int *)((int)this + 0x28) + 4);
  local_8._0_1_ = 3;
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(this_00,piVar7,piVar3);
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  bVar1 = true;
  local_20 = 7;
  local_24 = 0;
  FUN_10003130(&local_34,(int *)&DAT_1002a064,3);
  local_8 = CONCAT31(local_8._1_3_,4);
  local_3c = 0;
  do {
    while( true ) {
      piVar3 = *(int **)((int)this + 4);
      if ((piVar3[1] - *piVar3 >> 2 <= local_3c) || (!bVar1)) {
        if (7 < local_20) {
          operator_delete(local_34);
        }
        ExceptionList = local_10;
        __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
        return;
      }
      piVar3 = FUN_100152c0(*(int **)(*piVar3 + local_3c * 4));
      puVar6 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar6 = *(ushort **)param_1;
      }
      uVar5 = FUN_10005600(piVar3,0,piVar3[4],puVar6,*(uint *)(param_1 + 8));
      if (uVar5 == 0) break;
LAB_1001e15c:
      puVar6 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar6 = *(ushort **)param_1;
      }
      uVar5 = FUN_10005600(&local_34,0,local_24,puVar6,*(uint *)(param_1 + 8));
      if (uVar5 == 0) {
        bVar1 = false;
      }
LAB_1001e185:
      local_3c = local_3c + 1;
    }
    puVar6 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      puVar6 = *(ushort **)param_1;
    }
    uVar5 = FUN_10005600(&local_34,0,local_24,puVar6,*(uint *)(param_1 + 8));
    if (uVar5 == 0) goto LAB_1001e15c;
    bVar1 = false;
    cVar2 = FUN_10015740(*(int **)(**(int **)((int)this + 4) + local_3c * 4));
    if (cVar2 != '\x01') goto LAB_1001e185;
    local_3c = local_3c + 1;
  } while( true );
}



// Function: Catch@1001e1c3 at 1001e1c3

undefined * Catch_1001e1c3(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x54),"RP1210ServiceConnection.cpp",0x160,
               "CRP1210ServiceConnection::isPortAvailabe",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001e20e;
}



// Function: Catch_All@1001e210 at 1001e210

undefined4 Catch_All_1001e210(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x50) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10020630((void *)(unaff_EBP + -0x50),"RP1210ServiceConnection.cpp",0x160,
               "CRP1210ServiceConnection::isPortAvailabe",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001e277;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return 0x1001e1a2;
}



// Function: FUN_1001e280 at 1001e280

void __thiscall FUN_1001e280(void *this,undefined4 param_1,ushort *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  void *extraout_EAX;
  void *this_00;
  uint uVar4;
  ushort *puVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar6;
  uint uStack_68;
  undefined4 local_34;
  uint local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025e5b;
  local_10 = ExceptionList;
  uStack_68 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_68;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_68;
  GetCurrentThreadId();
  piVar2 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
    piVar6 = extraout_ECX;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar2 = iVar3;
    piVar6 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar6 = extraout_ECX_01;
  }
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xffffff88,0x10031118);
  this_00 = *(void **)(*(int *)((int)this + 0x28) + 4);
  iVar3 = 0;
  local_8._0_1_ = 3;
  if (this_00 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(this_00,piVar6,piVar2);
  local_34 = (void *)((uint)local_34._2_2_ << 0x10);
  bVar1 = true;
  local_20 = 7;
  local_24 = 0;
  FUN_10003130(&local_34,(int *)&DAT_1002a064,3);
  local_8 = CONCAT31(local_8._1_3_,4);
  while ((piVar2 = *(int **)((int)this + 4), iVar3 < piVar2[1] - *piVar2 >> 2 && (bVar1))) {
    piVar2 = FUN_100152c0(*(int **)(*piVar2 + iVar3 * 4));
    puVar5 = param_2;
    if (7 < *(uint *)(param_2 + 10)) {
      puVar5 = *(ushort **)param_2;
    }
    uVar4 = FUN_10005600(piVar2,0,piVar2[4],puVar5,*(uint *)(param_2 + 8));
    if (uVar4 == 0) {
      puVar5 = param_2;
      if (7 < *(uint *)(param_2 + 10)) {
        puVar5 = *(ushort **)param_2;
      }
      uVar4 = FUN_10005600(&local_34,0,local_24,puVar5,*(uint *)(param_2 + 8));
      if (uVar4 != 0) {
        bVar1 = false;
        FUN_100154e0(*(void **)(**(int **)((int)this + 4) + iVar3 * 4),'\x01');
      }
    }
    iVar3 = iVar3 + 1;
  }
  if (7 < local_20) {
    operator_delete(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001e43a at 1001e43a

undefined * Catch_1001e43a(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x50),"RP1210ServiceConnection.cpp",0x189,
               "CRP1210ServiceConnection::setPortAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001e485;
}



// Function: Catch_All@1001e487 at 1001e487

undefined4 Catch_All_1001e487(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x4c) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10020630((void *)(unaff_EBP + -0x4c),"RP1210ServiceConnection.cpp",0x189,
               "CRP1210ServiceConnection::setPortAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001e4ee;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return 0x1001e41c;
}



// Function: FUN_1001e500 at 1001e500

void FUN_1001e500(void)

{
  WCHAR WVar1;
  HMODULE hInstance;
  WCHAR *pWVar2;
  undefined2 *unaff_ESI;
  UINT uID;
  int cchBufferMax;
  WCHAR local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  cchBufferMax = 0x100;
  pWVar2 = &local_208;
  hInstance = GetModuleHandleW((LPCWSTR)PTR_u_AutoConfigure_1003ae38);
  LoadStringW(hInstance,uID,pWVar2,cchBufferMax);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pWVar2 = &local_208;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_10003130(unaff_ESI,(int *)&local_208,(int)pWVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001e590 at 1001e590

/* WARNING: Removing unreachable block (ram,0x1001eeb4) */

void FUN_1001e590(int param_1,uint *param_2)

{
  short sVar1;
  void **ppvVar2;
  undefined1 uVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  void *extraout_EAX;
  void *extraout_EAX_00;
  int *piVar7;
  void *extraout_EAX_01;
  IUnknownVtbl *pIVar8;
  undefined4 *puVar9;
  void *extraout_EAX_02;
  void *pvVar10;
  wchar_t *pwVar11;
  short *psVar12;
  ushort *****pppppuVar13;
  uint uVar14;
  uint extraout_EAX_03;
  char *pcVar15;
  uint uVar16;
  uint extraout_EAX_04;
  undefined4 *puVar17;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  void **extraout_ECX_08;
  void **ppvVar18;
  char *pcVar19;
  void **extraout_ECX_09;
  void **ppvVar20;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  void **extraout_EDX;
  uint extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined8 uVar21;
  ulonglong uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  IUnknown *pIVar25;
  undefined1 *puVar26;
  uint uStack_1ec;
  undefined4 *local_1b8;
  undefined4 *local_1b4;
  undefined4 local_1b0;
  void *local_1a8;
  int *local_1a4;
  undefined1 *local_1a0;
  undefined4 *local_19c;
  undefined4 *local_198;
  undefined4 local_194;
  int *local_18c;
  undefined4 *local_188;
  int local_184 [7];
  int local_168 [7];
  int local_14c [7];
  int local_130 [7];
  int local_114 [7];
  ushort local_f8 [28];
  int local_c0 [7];
  void *local_a4;
  uint local_90;
  void *local_88 [4];
  undefined4 local_78;
  uint local_74;
  ushort ****local_6c [4];
  uint local_5c;
  uint local_58;
  IUnknownVtbl *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  IUnknownVtbl local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10025fa3;
  local_10 = ExceptionList;
  uStack_1ec = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1ec;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_1ec;
  GetCurrentThreadId();
  local_1a0 = &stack0xfffffe08;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 1;
  local_18c = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar7 = extraout_ECX;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar5 = iVar6;
    piVar7 = extraout_ECX_00;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_01;
  }
  local_18c = (int *)&stack0xfffffe04;
  local_8._0_1_ = 2;
  FUN_10001f10(&stack0xfffffe04,0x10031398);
  pvVar10 = *(void **)(local_188[10] + 4);
  local_8._0_1_ = 3;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX;
  }
  local_8._0_1_ = 0;
  FUN_10002f20(pvVar10,piVar7,piVar5);
  GetCurrentThreadId();
  local_1a0 = &stack0xfffffe08;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 4;
  local_18c = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    piVar7 = extraout_ECX_02;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar5 = iVar6;
    piVar7 = extraout_ECX_03;
  }
  local_8._0_1_ = 0;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    piVar7 = extraout_ECX_04;
  }
  uVar24 = 4;
  uVar23 = 2;
  local_18c = (int *)&stack0xfffffdfc;
  local_8._0_1_ = 5;
  FUN_10001f10(&stack0xfffffdfc,0x10031340);
  puVar17 = local_188;
  pvVar10 = *(void **)(local_188[10] + 4);
  local_8._0_1_ = 6;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX_00;
  }
  local_8._0_1_ = 0;
  FUN_10005e10(pvVar10,piVar7,uVar23,uVar24,piVar5);
  local_1b8 = (undefined4 *)0x0;
  local_1b4 = (undefined4 *)0x0;
  local_1b0 = 0;
  local_8._0_1_ = 7;
  for (iVar6 = 0; piVar5 = (int *)puVar17[1], iVar6 < piVar5[1] - *piVar5 >> 2; iVar6 = iVar6 + 1) {
    piVar5 = FUN_100152c0(*(int **)(*piVar5 + iVar6 * 4));
    FUN_1000bba0(&local_1b8,piVar5);
  }
  GetCurrentThreadId();
  local_1a0 = &stack0xfffffe08;
  piVar5 = (int *)operator_new(0xc);
  local_8._0_1_ = 8;
  local_18c = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5[1] = 0;
    piVar5[2] = 1;
    iVar6 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
    *piVar5 = iVar6;
  }
  local_8._0_1_ = 7;
  if (piVar5 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  uVar24 = 4;
  uVar23 = 1;
  local_18c = (int *)&stack0xfffffdfc;
  local_8._0_1_ = 9;
  piVar7 = (int *)operator_new(0xc);
  local_8 = CONCAT31(local_8._1_3_,10);
  local_1a4 = piVar7;
  if (piVar7 != (int *)0x0) {
    piVar7[1] = 0;
    piVar7[2] = 1;
    iVar6 = Ordinal_2(L"Check if RP1210 devices are installed and their device configuration");
    *piVar7 = iVar6;
    if (iVar6 != 0) goto LAB_1001e801;
    _com_issue_error(-0x7ff8fff2);
  }
  piVar7 = (int *)0x0;
LAB_1001e801:
  local_8._0_1_ = 9;
  if (piVar7 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  pvVar10 = *(void **)(local_188[10] + 4);
  local_8._0_1_ = 0xb;
  if (pvVar10 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar10 = extraout_EAX_01;
  }
  local_8._0_1_ = 7;
  FUN_10005e10(pvVar10,piVar7,uVar23,uVar24,piVar5);
  puVar17 = local_188;
  local_19c = (undefined4 *)0x0;
  local_198 = (undefined4 *)0x0;
  local_194 = 0;
  local_8._0_1_ = 0xc;
  FUN_1001d000(local_188 + 0xb,param_1,(int *)*local_188,(int *)&local_1b8,(int *)&local_19c);
  if (*(char *)(puVar17 + 2) == '\0') {
    local_18c = (int *)(((int)local_198 - (int)local_19c) / 0xe0);
    if (local_18c != (int *)0x0) {
      local_20 = 7;
      local_24 = 0;
      local_34.QueryInterface = (_func_5021 *)((uint)local_34.QueryInterface & 0xffff0000);
      local_8._0_1_ = 0xf;
      uVar3 = (undefined1)local_8;
      local_8._0_1_ = 0xf;
      if (param_1 == 0) {
        puVar9 = (undefined4 *)FUN_1001e500();
        local_8._0_1_ = 0x10;
        FUN_10004710(&local_34,puVar9);
        local_8 = CONCAT31(local_8._1_3_,0xf);
        if (7 < local_3c) {
          operator_delete(local_50[0]);
        }
        pIVar8 = (IUnknownVtbl *)local_34.QueryInterface;
        if (local_20 < 8) {
          pIVar8 = &local_34;
        }
        puVar26 = (undefined1 *)0xa;
        pIVar25 = (IUnknown *)0x43a;
      }
      else {
        local_8._0_1_ = uVar3;
        puVar9 = (undefined4 *)FUN_1001e500();
        local_8._0_1_ = 0x11;
        FUN_10004710(&local_34,puVar9);
        local_8 = CONCAT31(local_8._1_3_,0xf);
        if (7 < local_3c) {
          operator_delete(local_50[0]);
        }
        pIVar8 = (IUnknownVtbl *)local_34.QueryInterface;
        if (local_20 < 8) {
          pIVar8 = &local_34;
        }
        puVar26 = (undefined1 *)0x4b;
        pIVar25 = (IUnknown *)0x43e;
      }
      FUN_10014b60((void *)puVar17[10],pIVar25,puVar26,(IUnknown *)pIVar8,(int *)0x4);
      GetCurrentThreadId();
      local_1a0 = &stack0xfffffe08;
      piVar5 = (int *)operator_new(0xc);
      local_8._0_1_ = 0x12;
      local_1a4 = piVar5;
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
        piVar7 = extraout_ECX_05;
      }
      else {
        piVar5[1] = 0;
        piVar5[2] = 1;
        iVar6 = ConvertStringToBSTR("RP1210ServiceConnection.cpp");
        *piVar5 = iVar6;
        piVar7 = extraout_ECX_06;
      }
      local_8._0_1_ = 0xf;
      if (piVar5 == (int *)0x0) {
        _com_issue_error(-0x7ff8fff2);
        piVar7 = extraout_ECX_07;
      }
      uVar24 = 4;
      uVar23 = 1;
      local_8._0_1_ = 0x13;
      local_1a4 = (int *)&stack0xfffffdfc;
      FUN_10001f10(&stack0xfffffdfc,0x100311a8);
      pvVar10 = *(void **)(puVar17[10] + 4);
      local_8._0_1_ = 0x14;
      if (pvVar10 == (void *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pvVar10 = extraout_EAX_02;
      }
      local_8 = CONCAT31(local_8._1_3_,0xf);
      FUN_10005e10(pvVar10,piVar7,uVar23,uVar24,piVar5);
      local_1a4 = (int *)0x0;
LAB_1001eb73:
      pIVar8 = (IUnknownVtbl *)local_34.QueryInterface;
      uVar14 = local_20;
      if ((int)local_1a4 < (int)local_18c) {
        FUN_10019230(local_184,local_19c + (int)local_1a4 * 0x38);
        local_8._0_1_ = 0x15;
        piVar5 = (int *)FUN_1000db70((void *)puVar17[9],local_130,local_184);
        FUN_10005790(&local_1a8);
        pvVar10 = local_1a8;
        if (local_1a8 == (void *)0x0) {
          pwVar11 = (wchar_t *)FUN_1001e500();
          local_8._0_1_ = 0x16;
          if (7 < *(uint *)(pwVar11 + 10)) {
            pwVar11 = *(wchar_t **)pwVar11;
          }
          FUN_10015000((void *)local_188[10],0x443,0x80004005,0x10031220,
                       L"RP1210ServiceConnection.cpp",(undefined1 *)0xcb,pwVar11);
          local_8._0_1_ = 0x15;
          if (7 < local_90) {
            operator_delete(local_a4);
          }
        }
        FUN_1000f080(pvVar10,local_c0);
        FUN_1000f2c0(pvVar10,local_14c);
        FUN_1000f500(pvVar10,local_168);
        FUN_1000f740(pvVar10,(int *)local_f8);
        FUN_1000f980(pvVar10,local_114);
        FUN_1000fe20(pvVar10,local_184);
        local_88[0] = (void *)((uint)local_88[0] & 0xffff0000);
        local_74 = 7;
        local_78 = 0;
        FUN_10003030(local_88,local_130,0,0xffffffff);
        local_6c[0] = (ushort ****)((uint)local_6c[0] & 0xffff0000);
        local_8._0_1_ = 0x17;
        local_58 = 7;
        local_5c = 0;
        psVar12 = (short *)PTR_DAT_1003ae3c;
        do {
          sVar1 = *psVar12;
          psVar12 = psVar12 + 1;
        } while (sVar1 != 0);
        FUN_10003130(local_6c,(int *)PTR_DAT_1003ae3c,
                     (int)psVar12 - (int)(PTR_DAT_1003ae3c + 2) >> 1);
        local_8._0_1_ = 0x18;
        psVar12 = (short *)PTR_DAT_1003ae40;
        do {
          sVar1 = *psVar12;
          psVar12 = psVar12 + 1;
        } while (sVar1 != 0);
        FUN_10005cf0(local_6c,(int *)PTR_DAT_1003ae40,
                     (int)psVar12 - (int)(PTR_DAT_1003ae40 + 2) >> 1);
        pppppuVar13 = (ushort *****)local_6c[0];
        if (local_58 < 8) {
          pppppuVar13 = local_6c;
        }
        uVar14 = FUN_100137e0(local_88,(ushort *)pppppuVar13,0,local_5c);
        FUN_1001df80(local_88,(undefined2 *)local_50,0,uVar14);
        local_8 = CONCAT31(local_8._1_3_,0x19);
        FUN_10010060(pvVar10,(int *)local_50);
        cVar4 = FUN_1001dfc0(local_188,local_f8);
        if ((cVar4 == '\0') && (param_1 == 0)) {
          local_1a0 = (undefined1 *)0x2;
          FUN_1000e8f0(pvVar10,&local_1a0);
        }
        else {
          (**(code **)(*piVar5 + 4))();
        }
        ppvVar2 = (void **)param_2[1];
        if ((&local_1a8 < ppvVar2) && (ppvVar20 = (void **)*param_2, ppvVar20 <= &local_1a8)) {
          ppvVar18 = (void **)param_2[2];
          iVar6 = (int)&local_1a8 - (int)ppvVar20;
          if (ppvVar2 == ppvVar18) {
            uVar14 = (int)ppvVar2 - (int)ppvVar20 >> 2;
            if (0x3ffffffe < uVar14) {
              std::_Xlength_error("vector<T> too long");
              uVar14 = extraout_EAX_03;
              ppvVar18 = extraout_ECX_08;
              ppvVar20 = extraout_EDX;
            }
            pcVar15 = (char *)(uVar14 + 1);
            pcVar19 = (char *)((int)ppvVar18 - (int)ppvVar20 >> 2);
            if (pcVar19 < pcVar15) {
              if ((char *)(0x3fffffff - ((uint)pcVar19 >> 1)) < pcVar19) {
                pcVar19 = (char *)0x0;
              }
              else {
                pcVar19 = pcVar19 + ((uint)pcVar19 >> 1);
              }
              if (pcVar19 < pcVar15) {
                pcVar19 = pcVar15;
              }
              FUN_100159d0(param_2,pcVar19);
              pvVar10 = local_1a8;
            }
          }
          if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_2[1] = *(undefined4 *)(*param_2 + (iVar6 >> 2) * 4);
          }
        }
        else {
          ppvVar20 = (void **)param_2[2];
          if (ppvVar2 == ppvVar20) {
            uVar14 = *param_2;
            uVar16 = (int)((int)ppvVar2 - uVar14) >> 2;
            if (0x3ffffffe < uVar16) {
              std::_Xlength_error("vector<T> too long");
              uVar16 = extraout_EAX_04;
              ppvVar20 = extraout_ECX_09;
              uVar14 = extraout_EDX_00;
            }
            pcVar15 = (char *)(uVar16 + 1);
            pcVar19 = (char *)((int)((int)ppvVar20 - uVar14) >> 2);
            if (pcVar19 < pcVar15) {
              if ((char *)(0x3fffffff - ((uint)pcVar19 >> 1)) < pcVar19) {
                pcVar19 = (char *)0x0;
              }
              else {
                pcVar19 = pcVar19 + ((uint)pcVar19 >> 1);
              }
              if (pcVar19 < pcVar15) {
                pcVar19 = pcVar15;
              }
              FUN_100159d0(param_2,pcVar19);
            }
          }
          if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_2[1] = pvVar10;
          }
        }
        param_2[1] = param_2[1] + 4;
        uVar21 = (**(code **)(*(int *)((int)pvVar10 + 8) + 0x30))();
        uVar24 = (undefined4)((ulonglong)uVar21 >> 0x20);
        uVar23 = extraout_ECX_10;
        if (piVar5 != (int *)0x0) {
          (**(code **)*piVar5)();
          uVar23 = extraout_ECX_11;
          uVar24 = extraout_EDX_01;
        }
        if (param_1 == 0) {
          pIVar8 = (IUnknownVtbl *)local_34.QueryInterface;
          if (local_20 < 8) {
            pIVar8 = &local_34;
          }
          piVar5 = (int *)0x4;
          uVar22 = FUN_10021a20(uVar23,uVar24);
          puVar26 = (undefined1 *)uVar22;
          pvVar10 = (void *)local_188[10];
          pIVar25 = (IUnknown *)0x43a;
        }
        else {
          puVar17 = (undefined4 *)FUN_1001e500();
          local_8._0_1_ = 0x1a;
          FUN_10004710(&local_34,puVar17);
          local_8 = CONCAT31(local_8._1_3_,0x19);
          uVar23 = extraout_ECX_12;
          uVar24 = extraout_EDX_02;
          if (7 < local_90) {
            operator_delete(local_a4);
            uVar23 = extraout_ECX_13;
            uVar24 = extraout_EDX_03;
          }
          pIVar8 = (IUnknownVtbl *)local_34.QueryInterface;
          if (local_20 < 8) {
            pIVar8 = &local_34;
          }
          piVar5 = (int *)0x4;
          uVar22 = FUN_10021a20(uVar23,uVar24);
          puVar26 = (undefined1 *)uVar22;
          pvVar10 = (void *)local_188[10];
          pIVar25 = (IUnknown *)0x43e;
        }
        FUN_10014b60(pvVar10,pIVar25,puVar26,(IUnknown *)pIVar8,piVar5);
        if (*(char *)(local_188 + 2) == '\0') goto LAB_1001f0f9;
        if (7 < local_3c) {
          operator_delete(local_50[0]);
        }
        local_3c = 7;
        local_40 = 0;
        local_50[0] = (IUnknownVtbl *)((uint)local_50[0] & 0xffff0000);
        if (7 < local_58) {
          operator_delete(local_6c[0]);
        }
        local_58 = 7;
        local_5c = 0;
        local_6c[0] = (ushort ****)((uint)local_6c[0] & 0xffff0000);
        if (7 < local_74) {
          operator_delete(local_88[0]);
        }
        local_88[0] = (void *)((uint)local_88[0] & 0xffff0000);
        local_74 = 7;
        local_78 = 0;
        FUN_10005b80(local_184);
        if (7 < local_20) {
          operator_delete(local_34.QueryInterface);
        }
        local_20 = 7;
        local_24 = 0;
        local_34.QueryInterface = (_func_5021 *)((uint)local_34.QueryInterface & 0xffff0000);
        local_8._0_1_ = 7;
        if (local_19c != (undefined4 *)0x0) {
          std::_Container_base0::_Orphan_all((_Container_base0 *)&local_19c);
          puVar17 = local_198;
          for (puVar9 = local_19c; puVar9 != puVar17; puVar9 = puVar9 + 0x38) {
            FUN_10005b80(puVar9);
          }
          operator_delete(local_19c);
        }
        local_19c = (undefined4 *)0x0;
        local_198 = (undefined4 *)0x0;
        local_194 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_1b8 == (undefined4 *)0x0) goto LAB_1001f0db;
        std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1b8);
        puVar17 = local_1b4;
        for (puVar9 = local_1b8; puVar9 != puVar17; puVar9 = puVar9 + 7) {
          if (7 < (uint)puVar9[5]) {
            operator_delete((void *)*puVar9);
          }
          puVar9[5] = 7;
          puVar9[4] = 0;
          *(undefined2 *)puVar9 = 0;
        }
        goto LAB_1001f0d3;
      }
      goto joined_r0x1001f188;
    }
    pIVar8 = (IUnknownVtbl *)FUN_1001e500();
    local_8._0_1_ = 0xd;
    if ((IUnknownVtbl *)0x7 < ((IUnknown *)((int)pIVar8 + 0x14))->lpVtbl) {
      pIVar8 = ((IUnknown *)pIVar8)->lpVtbl;
    }
    FUN_10014d70((void *)puVar17[10],0x412,0x20,(IUnknown *)pIVar8,
                 (IUnknown *)L"CRP1210ServiceConnection::CheckAvailability",(int *)0x4,(IID *)0x0,
                 (int *)L"RP1210ServiceConnection.cpp",(undefined1 *)0x8f);
    local_8._0_1_ = 0xc;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    piVar5 = (int *)FUN_1001e500();
    local_8 = CONCAT31(local_8._1_3_,0xe);
    if (7 < (uint)piVar5[5]) {
      piVar5 = (int *)*piVar5;
    }
    FUN_10014990((void *)puVar17[10],(IUnknown *)0x412,piVar5,(int *)0x1);
    pIVar8 = local_50[0];
    uVar14 = local_3c;
joined_r0x1001f188:
    if (7 < uVar14) {
      operator_delete(pIVar8);
    }
    local_8._0_1_ = 7;
    if (local_19c != (undefined4 *)0x0) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)&local_19c);
      puVar17 = local_198;
      for (puVar9 = local_19c; puVar9 != puVar17; puVar9 = puVar9 + 0x38) {
        FUN_10005b80(puVar9);
      }
      operator_delete(local_19c);
    }
    local_19c = (undefined4 *)0x0;
    local_198 = (undefined4 *)0x0;
    local_194 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1b8 != (undefined4 *)0x0) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1b8);
      puVar17 = local_1b4;
      for (puVar9 = local_1b8; puVar9 != puVar17; puVar9 = puVar9 + 7) {
        if (7 < (uint)puVar9[5]) {
          operator_delete((void *)*puVar9);
        }
        puVar9[5] = 7;
        puVar9[4] = 0;
        *(undefined2 *)puVar9 = 0;
      }
LAB_1001f0d3:
      operator_delete(local_1b8);
    }
  }
  else {
    local_8._0_1_ = 7;
    if (local_19c != (undefined4 *)0x0) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)&local_19c);
      puVar17 = local_198;
      for (puVar9 = local_19c; puVar9 != puVar17; puVar9 = puVar9 + 0x38) {
        FUN_10005b80(puVar9);
      }
      operator_delete(local_19c);
    }
    local_19c = (undefined4 *)0x0;
    local_198 = (undefined4 *)0x0;
    local_194 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1b8 != (undefined4 *)0x0) {
      std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1b8);
      FUN_10007c00(local_1b8,local_1b4);
      operator_delete(local_1b8);
    }
  }
LAB_1001f0db:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_1001f0f9:
  if (7 < local_3c) {
    operator_delete(local_50[0]);
  }
  local_3c = 7;
  local_40 = 0;
  local_50[0] = (IUnknownVtbl *)((uint)local_50[0] & 0xffff0000);
  if (7 < local_58) {
    operator_delete(local_6c[0]);
  }
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = (ushort ****)((uint)local_6c[0] & 0xffff0000);
  if (7 < local_74) {
    operator_delete(local_88[0]);
  }
  local_88[0] = (void *)((uint)local_88[0] & 0xffff0000);
  local_74 = 7;
  local_78 = 0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  FUN_10005b80(local_184);
  local_1a4 = (int *)((int)local_1a4 + 1);
  puVar17 = local_188;
  goto LAB_1001eb73;
}



// Function: Catch@1001f258 at 1001f258

undefined * Catch_1001f258(void)

{
  int unaff_EBP;
  
  FUN_10020630(*(void **)(unaff_EBP + -0x1d8),"RP1210ServiceConnection.cpp",0x117,
               "CRP1210ServiceConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  return &DAT_1001f2a6;
}



// Function: Catch_All@1001f2ab at 1001f2ab

undefined4 Catch_All_1001f2ab(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  *(undefined ***)(unaff_EBP + -0x1d4) = _com_error::vftable;
  *(undefined4 *)(unaff_EBP + -0x1d0) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -0x1cc) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c8) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FUN_10020630((void *)(unaff_EBP + -0x1d4),"RP1210ServiceConnection.cpp",0x117,
               "CRP1210ServiceConnection::CheckAvailability",0x3ed7ac9c,0x46d59d92,0x81b10189,
               0x696e973b);
  uStack0000001c = 0x1001f324;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1d4));
  return 0x1001f0db;
}



// Function: FUN_1001f330 at 1001f330

undefined4 __cdecl FUN_1001f330(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (param_1 == (undefined4 *)0x0) {
    Ordinal_6(0);
    return 0;
  }
  iVar1 = Ordinal_2(param_1);
  if (iVar1 == 0) {
    FUN_10001070(0x8007000e);
  }
  uVar2 = Ordinal_149(iVar1);
  uVar2 = Ordinal_150(iVar1,uVar2);
  Ordinal_6(iVar1);
  return uVar2;
}



// Function: FUN_1001f390 at 1001f390

void __cdecl FUN_1001f390(short *param_1)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_EDI;
  
  if (*(int *)(param_1 + 8) != 0) {
    unaff_EDI = 8;
    do {
      psVar1 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        psVar1 = *(short **)param_1;
      }
      if (*psVar1 != 0x20) goto LAB_1001f3d0;
      FUN_10002220(param_1,0,1);
    } while (*(int *)(param_1 + 8) != 0);
  }
  std::_Xout_of_range("invalid string position");
LAB_1001f3d0:
  uVar2 = *(uint *)(param_1 + 8);
  uVar3 = uVar2 - 1;
  if (uVar3 < uVar2) {
    do {
      psVar1 = param_1;
      if (unaff_EDI <= *(uint *)(param_1 + 10)) {
        psVar1 = *(short **)param_1;
      }
      if (psVar1[uVar3] != 0x20) {
        return;
      }
      FUN_10002220(param_1,uVar2 - 1,0xffffffff);
      uVar2 = *(uint *)(param_1 + 8);
      uVar3 = uVar2 - 1;
    } while (uVar3 < uVar2);
  }
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1001f420 at 1001f420

undefined2 * __cdecl FUN_1001f420(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if ((undefined4 *)*param_2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)*param_2;
  }
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  piVar2 = piVar3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10003130(param_1,piVar3,(int)piVar2 - ((int)piVar3 + 2) >> 1);
  return param_1;
}



// Function: FUN_1001f480 at 1001f480

void __cdecl FUN_1001f480(int *param_1,ushort param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  int local_74;
  uint local_6c;
  void *local_68 [5];
  uint local_54;
  undefined4 local_4c;
  int local_3c;
  uint local_38;
  undefined4 local_30;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10025fe8;
  local_10 = ExceptionList;
  local_14 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)param_3[1];
  if ((undefined4 *)*param_3 != puVar2) {
    puVar2 = FUN_1000a6c0(puVar2,puVar2,(undefined4 *)*param_3);
    FUN_10007c00(puVar2,(undefined4 *)param_3[1]);
    param_3[1] = puVar2;
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (ushort *)((uint)local_4c._2_2_ << 0x10);
  FUN_10003030(&local_4c,param_1,0,0xffffffff);
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_8 = 1;
  if (local_3c != 0) {
    local_6c = (uint)param_2;
    if (local_3c == 0) goto LAB_1001f59c;
    do {
      local_74 = local_3c;
      if (local_3c != 0) {
        puVar8 = local_4c;
        if (local_38 < 8) {
          puVar8 = (ushort *)&local_4c;
        }
        for (; puVar3 = puVar8, iVar6 = local_74, local_74 != 0;
            local_74 = local_74 + (-1 - (iVar6 >> 1))) {
          while (*puVar3 != param_2) {
            iVar6 = iVar6 + -1;
            puVar3 = puVar3 + 1;
            if (iVar6 == 0) goto LAB_1001f59c;
          }
          if (puVar3 == (ushort *)0x0) break;
          iVar6 = 1;
          puVar9 = &local_6c;
          puVar7 = puVar3;
          while (*puVar7 == (ushort)*puVar9) {
            puVar7 = puVar7 + 1;
            puVar9 = (uint *)((int)puVar9 + 2);
            iVar6 = iVar6 + -1;
            if (iVar6 == 0) goto LAB_1001f581;
          }
          if ((-(uint)(*puVar7 < (ushort)*puVar9) & 0xfffffffe) == 0xffffffff) {
LAB_1001f581:
            puVar8 = local_4c;
            if (local_38 < 8) {
              puVar8 = (ushort *)&local_4c;
            }
            uVar4 = (int)puVar3 - (int)puVar8 >> 1;
            if (uVar4 != 0xffffffff) {
              puVar2 = (undefined4 *)FUN_1001df80(&local_4c,(undefined2 *)local_68,0,uVar4);
              if (&local_30 != puVar2) {
                if (7 < local_1c) {
                  operator_delete(local_30);
                }
                local_1c = 7;
                local_20 = 0;
                local_30 = (void *)((uint)local_30 & 0xffff0000);
                if ((uint)puVar2[5] < 8) {
                  memmove(&local_30,puVar2,(puVar2[4] + 1) * 2);
                }
                else {
                  local_30 = (void *)*puVar2;
                  *puVar2 = 0;
                }
                local_20 = puVar2[4];
                local_1c = puVar2[5];
                puVar2[5] = 7;
                puVar2[4] = 0;
                *(undefined2 *)puVar2 = 0;
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              if (7 < local_54) {
                operator_delete(local_68[0]);
              }
              FUN_10002220(&local_4c,0,uVar4 + 1);
              FUN_1001f390((short *)&local_30);
              if (local_20 != 0) {
                FUN_1000bba0(param_3,&local_30);
              }
              goto LAB_1001f6c8;
            }
            break;
          }
          iVar6 = (int)puVar3 - (int)puVar8;
          puVar8 = puVar3 + 1;
        }
      }
LAB_1001f59c:
      FUN_1001f390((short *)&local_4c);
      FUN_1000bba0(param_3,&local_4c);
      psVar5 = (short *)PTR_DAT_1003af24;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10003130(&local_4c,(int *)PTR_DAT_1003af24,(int)psVar5 - (int)(PTR_DAT_1003af24 + 2) >> 1)
      ;
LAB_1001f6c8:
    } while (local_3c != 0);
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _com_issue_error at 1001f730

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2010 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_1003af28)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 1001f750

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
    HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_10028a1c,&param_2);
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
  (*(code *)PTR_FUN_1003af28)(param_1);
  return;
}



// Function: ConvertStringToBSTR at 1001f7d0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __stdcall _com_util::ConvertStringToBSTR(char const *)
    wchar_t * __stdcall _com_util::ConvertStringToBSTR(char const *)
   
   Library: Visual Studio 2010 Release */

void ConvertStringToBSTR(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  int cchWideChar;
  DWORD DVar3;
  LPWSTR lpWideCharStr;
  uint local_3c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_10021e5c;
  local_14 = ExceptionList;
  local_c = DAT_1003af5c ^ 0x10038330;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_14;
  local_3c = uVar1;
  if (param_1 != (LPCSTR)0x0) {
    iVar2 = lstrlenA(param_1);
    cchWideChar = MultiByteToWideChar(0,0,param_1,iVar2 + 1,(LPWSTR)0x0,0);
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
    }
    iVar2 = MultiByteToWideChar(0,0,param_1,iVar2 + 1,lpWideCharStr,cchWideChar);
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



// Function: FUN_1001f950 at 1001f950

void FUN_1001f950(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = _com_error::vftable;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1003834c);
}



// Function: _com_error at 1001f990

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

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



// Function: AtlMultiply<int> at 1001f9d0

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Library: Visual Studio 2010 Release */

long __cdecl ATL::AtlMultiply<int>(int *param_1,int param_2,int param_3)

{
  if ((int)((ulonglong)((longlong)param_2 * (longlong)param_3 + 0x80000000) >> 0x20) != 0) {
    return -0x7ff8fdea;
  }
  *param_1 = (int)((longlong)param_2 * (longlong)param_3);
  return 0;
}



// Function: FUN_1001fa00 at 1001fa00

uint FUN_1001fa00(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  
  if ((param_1 != (LPWSTR)0x0) && (param_2 != (LPCSTR)0x0)) {
    *param_1 = L'\0';
    iVar1 = MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
    return -(uint)(iVar1 != 0) & (uint)param_1;
  }
  return 0;
}



// Function: FUN_1001fa40 at 1001fa40

void __fastcall FUN_1001fa40(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10031b5c);
  }
  return;
}



// Function: FUN_1001fa70 at 1001fa70

void __fastcall FUN_1001fa70(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10031b5c);
  }
  return;
}



// Function: FUN_1001faa0 at 1001faa0

ULONG __fastcall FUN_1001faa0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10031b5c);
  }
  return UVar1;
}



// Function: FUN_1001fad0 at 1001fad0

undefined4 __cdecl FUN_1001fad0(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: AtlAdd<> at 1001fb00

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

undefined4 __cdecl AtlAdd<>(int *param_1,int param_2,uint param_3)

{
  if (-param_2 - 1U < param_3) {
    return 0x80070216;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// Function: FUN_1001fb30 at 1001fb30

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_1001fb30(int param_1)

{
  int iVar1;
  uint local_38;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_10021e5c;
  local_14 = ExceptionList;
  local_c = DAT_1003af5c ^ 0x10038380;
  local_38 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_38;
  ExceptionList = &local_14;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_38;
  iVar1 = AtlAdd<>(&local_28,param_1,0x2000);
  if (iVar1 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = (undefined1 *)((int)&local_38 - local_28);
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fbf0 at 1001fbf0

void __fastcall FUN_1001fbf0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026018;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fc40 at 1001fc40

undefined4 * __thiscall FUN_1001fc40(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (-param_1 - 1U < 8) {
    puVar1 = (undefined4 *)FUN_10001070(0x80070216);
  }
  else {
    puVar1 = (undefined4 *)malloc(param_1 + 8);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
                    /* WARNING: Load size is inaccurate */
  *puVar1 = *this;
  *(undefined4 **)this = puVar1;
  return puVar1 + 2;
}



// Function: FUN_1001fc90 at 1001fc90

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1001fc90(IID *param_1,uint param_2,int param_3,int param_4,undefined4 param_5,int param_6,
                 HINSTANCE param_7)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  errno_t eVar5;
  uint uVar6;
  LPWSTR pWVar7;
  int *_Memory;
  uint local_440;
  LPOLESTR local_428;
  int local_424;
  int *local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002608d;
  local_10 = ExceptionList;
  local_440 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (int *)0x0;
  local_424 = param_4;
  local_41c = (int *)0x0;
  local_8 = 0;
  local_414[0] = '\0';
  local_14 = local_440;
  if ((param_2 & 0xffff0000) == 0) {
    iVar4 = LoadStringA(param_7,param_2 & 0xffff,local_414,0x400);
    if (iVar4 == 0) {
      eVar5 = strcpy_s(local_414,0x400,"Unknown Error");
      switch(eVar5) {
      case 0:
      case 0x50:
        break;
      case 0xc:
        FUN_10001070(0x8007000e);
      case 0x16:
      case 0x22:
        FUN_10001070(0x80070057);
      default:
        FUN_10001070(0x80004005);
      }
    }
    iVar4 = lstrlenA(local_414);
    uVar6 = iVar4 + 1;
    uVar2 = uVar6 * 2;
    if ((((int)uVar6 >> 0x1f) << 1 | uVar6 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_1001fb30(uVar2), cVar3 != '\0')) {
        pWVar7 = (LPWSTR)&local_440;
      }
      else {
        pWVar7 = (LPWSTR)FUN_1001fc40(&local_41c,uVar2);
        _Memory = local_41c;
      }
      param_2 = FUN_1001fa00(pWVar7,local_414,uVar6 & 0x7fffffff,3);
      if (param_2 != 0) goto LAB_1001fe1b;
    }
    local_8 = 0xffffffff;
    while (_Memory != (int *)0x0) {
      piVar1 = (int *)*_Memory;
      local_41c = piVar1;
      free(_Memory);
      _Memory = piVar1;
    }
  }
  else {
LAB_1001fe1b:
    local_418 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar4 = Ordinal_202(&local_418);
    if (-1 < iVar4) {
      local_420 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*local_418 + 0xc))(local_418,param_5);
      ProgIDFromCLSID(param_1,&local_428);
      if (local_428 != (LPOLESTR)0x0) {
        (**(code **)(*local_418 + 0x10))(local_418,local_428);
      }
      if ((param_3 != 0) && (local_424 != 0)) {
        (**(code **)(*local_418 + 0x1c))(local_418,param_3);
        (**(code **)(*local_418 + 0x18))(local_418,local_424);
      }
      CoTaskMemFree(local_428);
      (**(code **)(*local_418 + 0x14))(local_418,param_2);
      iVar4 = (**(code **)*local_418)(local_418,&DAT_10031918,&local_420);
      if (-1 < iVar4) {
        Ordinal_201(0,local_420);
      }
      local_8._0_1_ = 2;
      if (local_420 != (int *)0x0) {
        (**(code **)(*local_420 + 8))(local_420);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_418 != (int *)0x0) {
      (**(code **)(*local_418 + 8))(local_418);
    }
    local_8 = 0xffffffff;
    while (_Memory != (int *)0x0) {
      piVar1 = (int *)*_Memory;
      local_41c = piVar1;
      free(_Memory);
      _Memory = piVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020000 at 10020000

int __thiscall FUN_10020000(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100260c8;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10031918,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    uVar1 = (iVar3 < 0) - 1 & (uint)local_14;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(uint *)this = uVar1;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_100200d0 at 100200d0

int __thiscall FUN_100200d0(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100260c8;
  local_10 = ExceptionList;
  uVar1 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10031b7c,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    uVar1 = (iVar3 < 0) - 1 & (uint)local_14;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(uint *)this = uVar1;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_100201a0 at 100201a0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100201a0(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  LPWSTR pWVar7;
  int *_Memory;
  uint local_2c;
  uint local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100260f8;
  local_10 = ExceptionList;
  local_2c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (int *)0x0;
  local_14 = local_2c;
  if (param_2 == (LPCSTR)0x0) goto LAB_1002031e;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar3 = lstrlenA(param_2);
  uVar4 = iVar3 + 1;
  uVar5 = uVar4 * 2;
  if ((((int)uVar4 >> 0x1f) << 1 | uVar4 >> 0x1f) + (uint)(0x7fffffff < uVar5) == 0) {
    if (((int)uVar5 < 0x401) && (cVar2 = FUN_1001fb30(uVar5), cVar2 != '\0')) {
      pWVar7 = (LPWSTR)&local_2c;
    }
    else {
      pWVar7 = (LPWSTR)FUN_1001fc40(&local_18,uVar5);
      _Memory = local_18;
    }
    uVar5 = FUN_1001fa00(pWVar7,param_2,uVar4 & 0x7fffffff,3);
    if (uVar5 != 0) {
      uVar4 = 0;
      if (param_4 == (LPCSTR)0x0) {
LAB_100202f2:
        FUN_1001fc90(param_1,uVar5,param_3,uVar4,param_5,param_6,(HINSTANCE)0x0);
        local_8 = 0xffffffff;
        FUN_10001c00((int *)&local_18);
      }
      else {
        iVar3 = lstrlenA(param_4);
        local_1c = iVar3 + 1;
        lVar6 = ATL::AtlMultiply<int>((int *)&local_1c,local_1c,2);
        uVar4 = local_1c;
        if (-1 < lVar6) {
          if (((int)local_1c < 0x401) && (cVar2 = FUN_1001fb30(local_1c), cVar2 != '\0')) {
            pWVar7 = (LPWSTR)&local_2c;
          }
          else {
            pWVar7 = (LPWSTR)FUN_1001fc40(&local_18,uVar4);
          }
          uVar4 = FUN_1001fa00(pWVar7,param_4,uVar4 >> 1,3);
          if (uVar4 != 0) goto LAB_100202f2;
        }
        local_8 = 0xffffffff;
        FUN_10001c00((int *)&local_18);
      }
      goto LAB_1002031e;
    }
  }
  local_8 = 0xffffffff;
  while (_Memory != (int *)0x0) {
    piVar1 = (int *)*_Memory;
    local_18 = piVar1;
    free(_Memory);
    _Memory = piVar1;
  }
LAB_1002031e:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020340 at 10020340

void __thiscall FUN_10020340(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026128;
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
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10031b5c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10020400 at 10020400

void __thiscall FUN_10020400(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026128;
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
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10031b5c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100204c0 at 100204c0

undefined4 * __thiscall FUN_100204c0(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_10026174;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_10031b5c);
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



// Function: FUN_10020570 at 10020570

HRESULT __thiscall FUN_10020570(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10026198;
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
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_1003af5c ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10031b5c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10020630 at 10020630

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10020630(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  LPSTR pCVar2;
  HRESULT HVar3;
  void *extraout_ECX;
  void *this;
  uint uStack_207c;
  int *local_2048;
  LPUNKNOWN local_2044;
  undefined4 local_2040;
  void *local_203c;
  undefined4 local_2038;
  undefined4 local_2034;
  undefined4 local_2030;
  undefined4 local_202c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026276;
  local_10 = ExceptionList;
  uStack_207c = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2040 = param_2;
  local_2038 = param_5;
  local_2034 = param_6;
  local_2030 = param_7;
  local_202c = param_8;
  local_18 = uStack_207c;
  FUN_100124d0(param_1,&local_2048);
  local_8 = 0;
  if ((local_2048 != (int *)0x0) && (piVar1 = local_2048 + 1, *piVar1 == 0)) {
    pCVar2 = FUN_10022310((LPCWSTR)*local_2048);
    *piVar1 = (int)pCVar2;
  }
  local_203c = (void *)0x0;
  HVar3 = CoCreateInstance((IID *)&DAT_10031b9c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10028450,&local_2044
                          );
  if (-1 < HVar3) {
    HVar3 = OleRun(local_2044);
    if (-1 < HVar3) {
      HVar3 = (*local_2044->lpVtbl->QueryInterface)(local_2044,(IID *)&DAT_10031b6c,&local_203c);
    }
    (*local_2044->lpVtbl->Release)(local_2044);
    if (-1 < HVar3) goto LAB_10020766;
  }
  local_203c = (void *)0x0;
  if ((HVar3 < 0) && (HVar3 != -0x7fffbffe)) {
    _com_issue_error(HVar3);
  }
LAB_10020766:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  if (local_2048 != (int *)0x0) {
    InterlockedIncrement(local_2048 + 2);
  }
  local_8._0_1_ = 3;
  this = local_203c;
  if (local_203c == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    this = extraout_ECX;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10020570(this,local_2048);
  local_8 = 1;
  FUN_100208bf();
  return;
}



// Function: Catch@100207c0 at 100207c0

undefined * Catch_100207c0(void)

{
  LPCSTR extraout_EAX;
  LPCSTR pCVar1;
  IUnknown *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int unaff_EBP;
  int *piVar3;
  IUnknown *pIVar2;
  
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX;
  }
  FUN_1001faa0(pIVar2);
  pCVar1 = *(LPCSTR *)(unaff_EBP + -0x2054);
  piVar3 = extraout_ECX_00;
  if (pCVar1 != (LPCSTR)0x0) goto LAB_1002083d;
  *(undefined1 *)(unaff_EBP + -0x2014) = 0;
  piVar3 = (int *)0x1fff;
  memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
  FUN_1001fad0((ushort)*(undefined4 *)(unaff_EBP + -0x2050),(LPSTR)(unaff_EBP + -0x2014));
  *(undefined1 **)(unaff_EBP + -0x2048) = &stack0xfffffffc;
  FUN_10001e80(&stack0xfffffffc,(LPCSTR)(unaff_EBP + -0x2014));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  do {
    if (*(void **)(unaff_EBP + -0x2038) != (void *)0x0) {
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_10020340(*(void **)(unaff_EBP + -0x2038),piVar3);
      if (*(IUnknown **)(unaff_EBP + -0x2038) != (IUnknown *)0x0) {
        FUN_1001fa70(*(IUnknown **)(unaff_EBP + -0x2038));
        *(undefined1 **)(unaff_EBP + -0x2048) = &stack0xfffffffc;
        piVar3 = extraout_ECX_02;
        FUN_10001e80(&stack0xfffffffc,"");
        *(undefined1 *)(unaff_EBP + -4) = 7;
        if (*(void **)(unaff_EBP + -0x2038) != (void *)0x0) {
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_10020400(*(void **)(unaff_EBP + -0x2038),piVar3);
          if (*(IUnknown **)(unaff_EBP + -0x2038) != (IUnknown *)0x0) {
            FUN_1001fa40(*(IUnknown **)(unaff_EBP + -0x2038));
            *(undefined4 *)(unaff_EBP + -4) = 1;
            return &DAT_100208b9;
          }
        }
      }
    }
    _com_issue_error(-0x7fffbffd);
    pCVar1 = extraout_EAX;
    piVar3 = extraout_ECX_01;
LAB_1002083d:
    *(undefined1 **)(unaff_EBP + -0x2048) = &stack0xfffffffc;
    FUN_10001e80(&stack0xfffffffc,pCVar1);
    *(undefined1 *)(unaff_EBP + -4) = 6;
  } while( true );
}



// Function: FUN_100208bf at 100208bf

/* WARNING: Removing unreachable block (ram,0x10020c58) */

undefined * FUN_100208bf(void)

{
  void *pvVar1;
  IUnknown *pIVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  LPCSTR extraout_EAX;
  uchar *puVar6;
  ULONG UVar7;
  int *piVar8;
  int iVar9;
  LONG LVar10;
  LPSTR pCVar11;
  undefined *puVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  uchar *_Str;
  uint unaff_EBP;
  LPCSTR pCVar13;
  int unaff_EDI;
  undefined4 uStack00000004;
  int iVar14;
  
  _Str = *(uchar **)(unaff_EBP - 0x203c);
  *(undefined4 *)(unaff_EBP - 0x2024) = 0;
  *(undefined4 *)(unaff_EBP - 0x2020) = 0;
  *(undefined4 *)(unaff_EBP - 0x201c) = 0;
  *(undefined4 *)(unaff_EBP - 0x2018) = 0;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 8) + 4))();
  }
  piVar8 = *(int **)(unaff_EDI + 8);
  *(int **)(unaff_EBP - 0x204c) = piVar8;
  *(int **)(unaff_EBP - 0x2048) = piVar8;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  if (piVar8 != (int *)0x0) {
    if (piVar8 == (int *)0x0) goto LAB_10020833;
    (**(code **)(*piVar8 + 0xc))();
  }
  puVar6 = _mbsrchr(_Str,0x2f);
  if (puVar6 == (uchar *)0x0) {
    puVar6 = _mbsrchr(_Str,0x5c);
  }
  else {
    puVar6 = puVar6 + 1;
  }
  if (puVar6 != (uchar *)0x0) {
    _Str = puVar6 + 1;
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) goto LAB_10020833;
  UVar7 = (*pIVar2->lpVtbl[8].Release)(pIVar2);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar2,(_GUID *)&DAT_10031b5c);
  }
  *(undefined1 **)(unaff_EBP - 0x2054) = &stack0xfffffffc;
  iVar14 = 0x1002099c;
  piVar8 = (int *)operator_new(0xc);
  *(int **)(unaff_EBP - 0x203c) = piVar8;
  *(undefined1 *)(unaff_EBP - 4) = 9;
  if (piVar8 == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8[1] = 0;
    piVar8[2] = 1;
    iVar14 = 0x100209c9;
    iVar9 = ConvertStringToBSTR(*(LPCSTR *)(unaff_EBP - 0x2058));
    *piVar8 = iVar9;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  if (piVar8 != (int *)0x0) {
    *(undefined1 *)(unaff_EBP - 4) = 10;
    pvVar1 = *(void **)(unaff_EBP - 0x2038);
    if (pvVar1 == (void *)0x0) goto LAB_10020833;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    FUN_10020340(pvVar1,piVar8);
    *(undefined1 **)(unaff_EBP - 0x2058) = &stack0xfffffffc;
    iVar14 = 0x10020a0e;
    piVar8 = (int *)operator_new(0xc);
    *(int **)(unaff_EBP - 0x2054) = piVar8;
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8[1] = 0;
      piVar8[2] = 1;
      iVar14 = 0x10020a35;
      iVar9 = ConvertStringToBSTR((LPCSTR)_Str);
      *piVar8 = iVar9;
    }
    *(undefined1 *)(unaff_EBP - 4) = 8;
    if (piVar8 != (int *)0x0) {
      *(undefined1 *)(unaff_EBP - 4) = 0xc;
      pvVar1 = *(void **)(unaff_EBP - 0x2038);
      if (pvVar1 == (void *)0x0) goto LAB_10020833;
      *(undefined1 *)(unaff_EBP - 4) = 8;
      FUN_10020400(pvVar1,piVar8);
      pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
      if (pIVar2 == (IUnknown *)0x0) goto LAB_10020833;
      UVar7 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar2,(_GUID *)&DAT_10031b5c);
      }
      pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
      if (pIVar2 == (IUnknown *)0x0) goto LAB_10020833;
      uVar3 = *(undefined4 *)(unaff_EBP - 0x2050);
      UVar7 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar2,(_GUID *)&DAT_10031b5c);
      }
      if (*(char *)(unaff_EBP + 0x28) != '\0') {
        *(undefined4 *)(unaff_EBP - 0x2040) = 0;
        *(undefined1 *)(unaff_EBP - 4) = 0xd;
        if (*(int **)(unaff_EBP - 0x2040) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP - 0x2040) + 8))();
        }
        *(undefined4 *)(unaff_EBP - 0x2040) = 0;
        Ordinal_202();
        if (*(int **)(unaff_EBP - 0x2040) == (int *)0x0) goto LAB_10020833;
        (**(code **)(**(int **)(unaff_EBP - 0x2040) + 0xc))();
        piVar8 = *(int **)(unaff_EBP - 0x2040);
        if (piVar8 == (int *)0x0) goto LAB_10020833;
        if (*(void **)(unaff_EBP - 0x2038) == (void *)0x0) goto LAB_10020833;
        FUN_100204c0(*(void **)(unaff_EBP - 0x2038),(undefined4 *)(unaff_EBP - 0x203c));
        *(undefined1 *)(unaff_EBP - 4) = 0xe;
        (**(code **)(*piVar8 + 0x14))();
        *(undefined1 *)(unaff_EBP - 4) = 0xd;
        piVar8 = *(int **)(unaff_EBP - 0x203c);
        if (piVar8 != (int *)0x0) {
          LVar10 = InterlockedDecrement(piVar8 + 2);
          if ((LVar10 == 0) && (piVar8 != (int *)0x0)) {
            if (*piVar8 != 0) {
              Ordinal_6();
            }
            if ((void *)piVar8[1] != (void *)0x0) {
              operator_delete((void *)piVar8[1]);
            }
            operator_delete(piVar8);
          }
          *(undefined4 *)(unaff_EBP - 0x203c) = 0;
        }
        *(undefined4 *)(unaff_EBP - 0x203c) = 0;
        *(undefined1 **)(unaff_EBP - 0x2058) = &stack0xfffffff4;
        piVar8 = *(int **)(unaff_EBP - 0x2040);
        piVar4 = *(int **)(unaff_EBP - 0x2040);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 4))(piVar4);
        }
        *(undefined1 *)(unaff_EBP - 4) = 0xf;
        *(undefined1 *)(unaff_EBP - 4) = 0xd;
        iVar14 = FUN_10020000((void *)(unaff_EBP - 0x203c),piVar8);
        if ((iVar14 < 0) && (iVar14 != -0x7fffbffe)) goto LAB_10020829;
        *(undefined1 *)(unaff_EBP - 4) = 0x10;
        piVar8 = *(int **)(unaff_EBP - 0x203c);
        if (piVar8 != (int *)0x0) {
          if (piVar8 == (int *)0x0) goto LAB_10020833;
          (**(code **)(*piVar8 + 4))();
          *(undefined ***)(unaff_EBP - 0x2068) = _com_error::vftable;
          *(undefined4 *)(unaff_EBP - 0x2064) = uVar3;
          *(int **)(unaff_EBP - 0x2060) = piVar8;
          *(undefined4 *)(unaff_EBP - 0x205c) = 0;
                    /* WARNING: Subroutine does not return */
          _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_1003834c);
        }
        *(undefined1 *)(unaff_EBP - 4) = 0xd;
        *(undefined1 *)(unaff_EBP - 4) = 8;
        if (*(int **)(unaff_EBP - 0x2040) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP - 0x2040) + 8))();
        }
      }
      if (*(void **)(unaff_EBP - 0x2038) == (void *)0x0) goto LAB_10020833;
      piVar8 = FUN_100204c0(*(void **)(unaff_EBP - 0x2038),(undefined4 *)(unaff_EBP - 0x203c));
      *(undefined1 *)(unaff_EBP - 4) = 0x11;
      puVar5 = (undefined4 *)*piVar8;
      if (puVar5 == (undefined4 *)0x0) {
        pCVar13 = (LPCSTR)0x0;
      }
      else {
        if (puVar5[1] == 0) {
          pCVar11 = FUN_10022310((LPCWSTR)*puVar5);
          puVar5[1] = pCVar11;
        }
        pCVar13 = (LPCSTR)puVar5[1];
      }
      FUN_100201a0((IID *)(unaff_EBP - 0x2034),pCVar13,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar3);
      *(undefined1 *)(unaff_EBP - 4) = 8;
      piVar8 = *(int **)(unaff_EBP - 0x203c);
      if (piVar8 != (int *)0x0) {
        LVar10 = InterlockedDecrement(piVar8 + 2);
        if ((LVar10 == 0) && (piVar8 != (int *)0x0)) {
          if (*piVar8 != 0) {
            Ordinal_6();
          }
          if ((void *)piVar8[1] != (void *)0x0) {
            operator_delete((void *)piVar8[1]);
          }
          operator_delete(piVar8);
        }
        *(undefined4 *)(unaff_EBP - 0x203c) = 0;
      }
      *(undefined1 *)(unaff_EBP - 4) = 1;
      if (*(int **)(unaff_EBP - 0x204c) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP - 0x204c) + 8))();
      }
      *(undefined1 *)(unaff_EBP - 4) = 0;
      if (*(int **)(unaff_EBP - 0x2038) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP - 0x2038) + 8))();
      }
      *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
      piVar8 = *(int **)(unaff_EBP - 0x2044);
      if (piVar8 != (int *)0x0) {
        LVar10 = InterlockedDecrement(piVar8 + 2);
        if ((LVar10 == 0) && (piVar8 != (int *)0x0)) {
          if (*piVar8 != 0) {
            Ordinal_6();
          }
          if ((void *)piVar8[1] != (void *)0x0) {
            operator_delete((void *)piVar8[1]);
          }
          operator_delete(piVar8);
        }
        *(undefined4 *)(unaff_EBP - 0x2044) = 0;
      }
      ExceptionList = *(void **)(unaff_EBP - 0xc);
      uStack00000004 = 0x10020dad;
      puVar12 = (undefined *)__security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
      return puVar12;
    }
  }
LAB_10020829:
  do {
    _com_issue_error(iVar14);
    *(undefined1 **)(unaff_EBP - 0x2048) = &stack0xfffffff4;
    piVar8 = extraout_ECX;
    FUN_10001e80(&stack0xfffffff4,extraout_EAX);
    *(undefined1 *)(unaff_EBP - 4) = 6;
    pvVar1 = *(void **)(unaff_EBP - 0x2038);
    if (pvVar1 != (void *)0x0) {
      *(undefined1 *)(unaff_EBP - 4) = 4;
      FUN_10020340(pvVar1,piVar8);
      if (*(IUnknown **)(unaff_EBP - 0x2038) != (IUnknown *)0x0) {
        FUN_1001fa70(*(IUnknown **)(unaff_EBP - 0x2038));
        *(undefined1 **)(unaff_EBP - 0x2048) = &stack0xfffffff4;
        piVar8 = extraout_ECX_00;
        FUN_10001e80(&stack0xfffffff4,"");
        *(undefined1 *)(unaff_EBP - 4) = 7;
        pvVar1 = *(void **)(unaff_EBP - 0x2038);
        if (pvVar1 != (void *)0x0) {
          *(undefined1 *)(unaff_EBP - 4) = 4;
          FUN_10020400(pvVar1,piVar8);
          if (*(IUnknown **)(unaff_EBP - 0x2038) != (IUnknown *)0x0) {
            FUN_1001fa40(*(IUnknown **)(unaff_EBP - 0x2038));
            *(undefined4 *)(unaff_EBP - 4) = 1;
            return &DAT_100208b9;
          }
        }
      }
    }
LAB_10020833:
    iVar14 = -0x7fffbffd;
  } while( true );
}



// Function: FUN_10020dc0 at 10020dc0

/* WARNING: Removing unreachable block (ram,0x10020fa5) */

void __cdecl
FUN_10020dc0(uchar *param_1,undefined4 param_2,IUnknown *param_3,undefined4 param_4,int param_5,
            byte *param_6,undefined4 param_7,undefined4 param_8,LPCSTR param_9)

{
  byte bVar1;
  IID *pIVar2;
  int *piVar3;
  void **ppvObject;
  HRESULT HVar4;
  int iVar5;
  int *extraout_EAX;
  IUnknown *extraout_EAX_00;
  IUnknown *extraout_EAX_01;
  ULONG UVar6;
  IUnknown *extraout_EAX_02;
  IUnknown *extraout_EAX_03;
  IUnknown *extraout_EAX_04;
  _func_5022 *p_Var7;
  uchar *puVar8;
  IUnknown *extraout_EAX_05;
  int *piVar9;
  LONG LVar10;
  IUnknown *extraout_EAX_06;
  IUnknown *pIVar11;
  int *extraout_EAX_07;
  IUnknownVtbl *pIVar12;
  byte *pbVar13;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  IUnknown *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  IUnknown *extraout_ECX_06;
  IUnknown *extraout_ECX_07;
  int *extraout_ECX_08;
  bool bVar14;
  undefined **local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  int *local_28;
  IID *local_24;
  LPUNKNOWN local_20;
  int *local_1c;
  int *local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100262fb;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_1003af5c ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10031b9c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10028450,&local_20);
  if (HVar4 < 0) {
LAB_10020e4b:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_10031b6c,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_10020e4b;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar13 = PTR_s_APPEND_1003af40;
  do {
    bVar1 = *param_6;
    bVar14 = bVar1 < *pbVar13;
    if (bVar1 != *pbVar13) {
LAB_10020e90:
      iVar5 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
      goto LAB_10020e95;
    }
    if (bVar1 == 0) break;
    bVar1 = param_6[1];
    bVar14 = bVar1 < pbVar13[1];
    if (bVar1 != pbVar13[1]) goto LAB_10020e90;
    param_6 = param_6 + 2;
    pbVar13 = pbVar13 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_10020e95:
  if (iVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      local_28 = (int *)&stack0xffffffb4;
      piVar9 = local_18;
      piVar3 = (int *)&stack0xffffffb4;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 4))(local_18);
        piVar3 = local_28;
      }
      local_28 = piVar3;
      local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
      iVar5 = FUN_100200d0(&local_1c,piVar9);
      if ((iVar5 < 0) && (iVar5 != -0x7fffbffe)) {
        _com_issue_error(iVar5);
      }
      local_24 = (IID *)0x0;
      piVar9 = local_18;
      if (local_18 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar9 = extraout_EAX;
      }
      (**(code **)(*piVar9 + 0x14))(piVar9);
      pIVar2 = local_24;
      if (local_24 != (IID *)0x0) {
        local_28 = (int *)operator_new(0xc);
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        if (local_28 == (int *)0x0) {
          local_28 = (int *)0x0;
        }
        else {
          local_28[1] = 0;
          local_28[2] = 1;
          *local_28 = (int)pIVar2;
        }
        local_8._0_1_ = 2;
        if (local_28 == (int *)0x0) {
          _com_issue_error(-0x7ff8fff2);
        }
        local_8._0_1_ = 5;
        pIVar11 = local_14;
        if (local_14 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar11 = extraout_EAX_00;
        }
        (*pIVar11->lpVtbl[9].QueryInterface)(pIVar11,local_24,ppvObject);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002ed0(&local_28);
      }
    }
  }
  if (local_1c == (int *)0x0) {
    local_1c = (int *)0x0;
    Ordinal_202();
    local_28 = (int *)&stack0xffffffb4;
    piVar9 = local_1c;
    piVar3 = (int *)&stack0xffffffb4;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 4))(local_1c);
      piVar3 = local_28;
    }
    local_28 = piVar3;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
    iVar5 = FUN_10020000(&local_18,piVar9);
    if ((iVar5 < 0) && (iVar5 != -0x7fffbffe)) {
      _com_issue_error(iVar5);
    }
  }
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
  local_20 = (LPUNKNOWN)0x0;
  local_8 = CONCAT31(local_8._1_3_,7);
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_EAX_01;
  }
  UVar6 = (*pIVar11->lpVtbl[8].Release)(pIVar11);
  piVar9 = extraout_ECX;
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar11,(_GUID *)&DAT_10031b5c);
    piVar9 = extraout_ECX_00;
  }
  if (param_5 == 1) {
    pIVar11 = local_14;
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pIVar11 = extraout_EAX_04;
    }
    p_Var7 = (_func_5022 *)pIVar11->lpVtbl[9].Release;
  }
  else {
    if (param_5 != 2) {
      if (param_5 != 3) goto LAB_100210c5;
      pIVar11 = local_14;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
        pIVar11 = extraout_EAX_02;
      }
      UVar6 = (*pIVar11->lpVtbl[9].Release)(pIVar11);
      if ((int)UVar6 < 0) {
        _com_issue_errorex(UVar6,pIVar11,(_GUID *)&DAT_10031b6c);
      }
    }
    pIVar11 = local_14;
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pIVar11 = extraout_EAX_03;
    }
    p_Var7 = pIVar11->lpVtbl[10].AddRef;
    param_3 = pIVar11;
  }
  UVar6 = (*p_Var7)(param_3);
  piVar9 = extraout_ECX_01;
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar11,(_GUID *)&DAT_10031b6c);
    piVar9 = extraout_ECX_02;
  }
LAB_100210c5:
  local_28 = (int *)&stack0xffffffb4;
  FUN_10001e80(&stack0xffffffb4,param_9);
  local_8._0_1_ = 8;
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_ECX_03;
  }
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10020340(pIVar11,piVar9);
  puVar8 = _mbsrchr(param_1,0x2f);
  if (puVar8 == (uchar *)0x0) {
    puVar8 = _mbsrchr(param_1,0x5c);
    piVar9 = extraout_ECX_05;
  }
  else {
    puVar8 = puVar8 + 1;
    piVar9 = extraout_ECX_04;
  }
  if (puVar8 != (uchar *)0x0) {
    param_1 = puVar8 + 1;
  }
  local_28 = (int *)&stack0xffffffb4;
  FUN_10001e80(&stack0xffffffb4,(LPCSTR)param_1);
  local_8._0_1_ = 9;
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_ECX_06;
  }
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10020400(pIVar11,piVar9);
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_EAX_05;
  }
  UVar6 = (*pIVar11->lpVtbl[4].Release)(pIVar11);
  if ((int)UVar6 < 0) {
    _com_issue_errorex(UVar6,pIVar11,(_GUID *)&DAT_10031b5c);
  }
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_ECX_07;
  }
  piVar9 = FUN_100204c0(pIVar11,&local_24);
  local_8._0_1_ = 10;
  FUN_100172d0(&local_20,piVar9);
  pIVar2 = local_24;
  local_8 = CONCAT31(local_8._1_3_,7);
  if (local_24 != (IID *)0x0) {
    LVar10 = InterlockedDecrement((LONG *)local_24->Data4);
    if ((LVar10 == 0) && (pIVar2 != (IID *)0x0)) {
      if (pIVar2->Data1 != 0) {
        Ordinal_6(pIVar2->Data1);
      }
      if (*(void **)&pIVar2->Data2 != (void *)0x0) {
        operator_delete(*(void **)&pIVar2->Data2);
      }
      operator_delete(pIVar2);
    }
    local_24 = (IID *)0x0;
  }
  pIVar11 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar11 = extraout_EAX_06;
  }
  (*pIVar11->lpVtbl->Release)(pIVar11);
  local_14 = (IUnknown *)0x0;
  piVar9 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar9 = extraout_EAX_07;
  }
  (**(code **)(*piVar9 + 0xc))(piVar9,param_8);
  piVar9 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar9 = extraout_ECX_08;
  }
  if (local_20 == (LPUNKNOWN)0x0) {
    pIVar12 = (IUnknownVtbl *)0x0;
  }
  else {
    pIVar12 = local_20->lpVtbl;
  }
  (**(code **)(*piVar9 + 0x14))(piVar9,pIVar12);
  Ordinal_201(0,local_18);
  local_38 = _com_error::vftable;
  local_34 = param_7;
  local_30 = local_18;
  local_2c = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 4))(local_18);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_38,(ThrowInfo *)&DAT_1003834c);
}



// Function: FUN_100212d0 at 100212d0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl
FUN_100212d0(uchar *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char *param_5)

{
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,param_5,&stack0x00000018);
  FUN_10020dc0(param_1,param_2,(IUnknown *)0x0,0,0,(byte *)0x10031bac,param_3,param_4,local_1008);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10021340 at 10021340

void __cdecl FUN_10021340(undefined4 param_1,undefined4 param_2)

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
  
  puStack_c = &LAB_10026330;
  local_10 = ExceptionList;
  uStack_44 = DAT_1003af5c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  iVar3 = 0;
  local_2c = 0;
  local_8 = 1;
  local_18 = uStack_44;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1003b02c);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1003b02c);
  pcVar2 = Ordinal_6_exref;
  switch(param_2) {
  case 0:
    unaff_EBX = CLSIDFromProgID(DAT_1003b04c,&local_28);
    uVar5 = 0x13;
    pwVar4 = L"8*YUPW\',*H \\(EB_T*A";
    break;
  case 1:
    unaff_EBX = CLSIDFromProgID(DAT_1003b044,&local_28);
    uVar5 = 9;
    pwVar4 = L"?!- PNZVR";
    break;
  case 2:
    unaff_EBX = CLSIDFromProgID(DAT_1003b048,&local_28);
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
      goto LAB_100213ee;
    }
    goto LAB_100213cf;
  case 4:
    iVar3 = Ordinal_4(L"?!- PNZVR",9);
    pcVar2 = Ordinal_6_exref;
    if (iVar3 == 0) goto LAB_100213cf;
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
    goto LAB_100213ee;
  case 5:
    iVar3 = Ordinal_4(L"8$\\u,-}TQJ#",0xb);
    pcVar2 = Ordinal_6_exref;
    if (iVar3 == 0) goto LAB_100213cf;
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
    goto LAB_100213ee;
  default:
    goto switchD_100213a2_default;
  }
  iVar3 = Ordinal_4(pwVar4,uVar5);
  if (iVar3 == 0) {
LAB_100213cf:
    FUN_10001070(0x8007000e);
  }
  pcVar2 = Ordinal_6_exref;
  Ordinal_6(0);
  local_2c = iVar3;
  Ordinal_6(0);
  if (-1 < unaff_EBX) {
LAB_100213ee:
    local_30 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    HVar1 = CoGetClassObject(&local_28,1,(LPVOID)0x0,(IID *)&DAT_10031dc8,&local_30);
    if (-1 < HVar1) {
      (**(code **)(*local_30 + 0x1c))(local_30,0,0,&DAT_10031db8,iVar3,param_1);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
  }
switchD_100213a2_default:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1003b02c);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1003b02c);
  (*pcVar2)(iVar3);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch_All@100215b7 at 100215b7

undefined * Catch_All_100215b7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x30) = 0x80004005;
  return &DAT_100215c4;
}



// Function: FUN_10021620 at 10021620

void __fastcall FUN_10021620(int *param_1)

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



// Function: FUN_10021664 at 10021664

int __fastcall FUN_10021664(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1002167d at 1002167d

undefined4 * __fastcall FUN_1002167d(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10021664((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &PTR_PTR_100387e8;
  param_1[3] = &DAT_100387ec;
  uVar1 = FUN_10001150((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_1003af88 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_100216be at 100216be

void __fastcall FUN_100216be(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_100216dd at 100216dd

int __fastcall FUN_100216dd(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10021702 at 10021702

void __fastcall FUN_10021702(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_100216be((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1002171a at 1002171a

undefined4 * __fastcall FUN_1002171a(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_100216dd((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10031df8;
  uVar1 = FUN_10001150((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_1003af88 = 1;
  }
  return param_1;
}



// Function: FUN_1002175a at 1002175a

void FUN_1002175a(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10021772

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



// Function: __security_check_cookie at 100217be

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1003af5c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __onexit at 100217cd

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
  
  local_8 = &DAT_100386c8;
  uStack_c = 0x100217d9;
  local_20[0] = DecodePointer(DAT_1003b3f8);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1003b3f8);
    local_24 = DecodePointer(DAT_1003b3f4);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1003b3f8 = EncodePointer(local_20[0]);
    DAT_1003b3f4 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10021865();
  }
  return p_Var1;
}



// Function: FUN_10021865 at 10021865

void FUN_10021865(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1002186e

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: `eh_vector_constructor_iterator' at 100218aa

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
  FUN_100218f7();
  return;
}



// Function: FUN_100218f7 at 100218f7

void FUN_100218f7(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 10021916

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



// Function: `eh_vector_destructor_iterator' at 10021974

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
  FUN_100219bf();
  return;
}



// Function: FUN_100219bf at 100219bf

void FUN_100219bf(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe_16 at 100219e0

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



// Function: __alloca_probe_8 at 100219f6

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



// Function: FUN_10021a20 at 10021a20

ulonglong __fastcall FUN_10021a20(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  if (DAT_1003b3ec == 0) {
    uVar1 = (ulonglong)ROUND(in_ST0);
    local_20 = (uint)uVar1;
    fStack_1c = (float)(uVar1 >> 0x20);
    fVar3 = (float)in_ST0;
    if ((local_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
      if ((int)fVar3 < 0) {
        uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
      }
      else {
        uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
        uVar1 = CONCAT44((int)fStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,(int)in_ST0);
}



// Function: __CRT_INIT@12 at 10021b19

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
    if (DAT_1003b0b0 < 1) {
      return 0;
    }
    DAT_1003b0b0 = DAT_1003b0b0 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1003b3e8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1003b3e4 == 2) {
      param_2 = (int *)DecodePointer(DAT_1003b3f8);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1003b3f4);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1003b3f8);
            piVar8 = (int *)DecodePointer(DAT_1003b3f4);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1003b3f4 = (PVOID)encoded_null();
        DAT_1003b3f8 = DAT_1003b3f4;
      }
      DAT_1003b3e4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1003b3e8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1003b3e8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1003b3e4 == 0) {
      DAT_1003b3e4 = 1;
      iVar5 = initterm_e(&DAT_100282cc,&DAT_100282d8);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10028258,&DAT_100282c8);
      DAT_1003b3e4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1003b3e8,0);
    }
    if ((DAT_1003b3f0 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1003b3f0), BVar2 != 0)) {
      (*DAT_1003b3f0)(param_1,2,param_3);
    }
    DAT_1003b0b0 = DAT_1003b0b0 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10021d23

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10021dc3) */
/* WARNING: Removing unreachable block (ram,0x10021d70) */
/* WARNING: Removing unreachable block (ram,0x10021df0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1003af70 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1003b0b0 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(param_3,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10001270(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10001270(param_3,0);
      __CRT_INIT_12(param_3,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10021e2e();
  return local_20;
}



// Function: FUN_10021e2e at 10021e2e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021e2e(void)

{
  _DAT_1003af70 = 0xffffffff;
  return;
}



// Function: entry at 10021e39

void entry(int *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: FUN_10021e5c at 10021e5c

void __cdecl
FUN_10021e5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1003af5c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe at 10021e90

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



// Function: ___report_gsfailure at 10021ebb

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
  
  _DAT_1003b1d0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1003b1d4 = &stack0x00000004;
  _DAT_1003b110 = 0x10001;
  _DAT_1003b0b8 = 0xc0000409;
  _DAT_1003b0bc = 1;
  local_32c = DAT_1003af5c;
  local_328 = DAT_1003af60;
  _DAT_1003b0c4 = unaff_retaddr;
  _DAT_1003b19c = in_GS;
  _DAT_1003b1a0 = in_FS;
  _DAT_1003b1a4 = in_ES;
  _DAT_1003b1a8 = in_DS;
  _DAT_1003b1ac = unaff_EDI;
  _DAT_1003b1b0 = unaff_ESI;
  _DAT_1003b1b4 = unaff_EBX;
  _DAT_1003b1b8 = in_EDX;
  _DAT_1003b1bc = in_ECX;
  _DAT_1003b1c0 = in_EAX;
  _DAT_1003b1c4 = unaff_EBP;
  DAT_1003b1c8 = unaff_retaddr;
  _DAT_1003b1cc = in_CS;
  _DAT_1003b1d8 = in_SS;
  DAT_1003b108 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10031e14);
  if (DAT_1003b108 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10021ff0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1003af5c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10022035

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



// Function: __ValidateImageBase at 100220c0

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



// Function: __FindPESection at 10022100

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



// Function: __IsNonwritableInCurrentImage at 10022150

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
  
  pcStack_10 = FUN_10021e5c;
  local_14 = ExceptionList;
  local_c = DAT_1003af5c ^ 0x10038770;
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



// Function: ___security_init_cookie at 10022224

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
  if ((DAT_1003af5c == 0xbb40e64e) || ((DAT_1003af5c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1003af5c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1003af5c == 0xbb40e64e) {
      DAT_1003af5c = 0xbb40e64f;
    }
    else if ((DAT_1003af5c & 0xffff0000) == 0) {
      DAT_1003af5c = DAT_1003af5c | (DAT_1003af5c | 0x4711) << 0x10;
    }
    DAT_1003af60 = ~DAT_1003af5c;
  }
  else {
    DAT_1003af60 = ~DAT_1003af5c;
  }
  return;
}



// Function: FUN_10022310 at 10022310

LPSTR FUN_10022310(LPCWSTR param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  uint cbMultiByte;
  DWORD DVar3;
  LPSTR lpMultiByteStr;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026360;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return (LPSTR)0x0;
  }
  pWVar2 = param_1;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  iVar4 = ((int)pWVar2 - (int)(param_1 + 1) >> 1) + 1;
  ExceptionList = &local_10;
  cbMultiByte = WideCharToMultiByte(0,0,param_1,iVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (cbMultiByte == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    _com_issue_error(DVar3);
  }
  local_8 = 0;
  lpMultiByteStr = (LPSTR)operator_new(cbMultiByte);
  local_8 = 0xffffffff;
  if (lpMultiByteStr == (LPSTR)0x0) {
    _com_issue_error(-0x7ff8fff2);
    return "h\x0e";
  }
  iVar4 = WideCharToMultiByte(0,0,param_1,iVar4,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar4 == 0) {
    operator_delete(lpMultiByteStr);
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    _com_issue_error(DVar3);
  }
  ExceptionList = local_10;
  return lpMultiByteStr;
}



// Function: Catch_All@100223cd at 100223cd

undefined4 Catch_All_100223cd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100223c3;
}



// Function: Unwind@10022430 at 10022430

void Unwind_10022430(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002243b at 1002243b

void Unwind_1002243b(void)

{
  int unaff_EBP;
  
  FUN_10001180((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10022460 at 10022460

void Unwind_10022460(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100224b0 at 100224b0

void Unwind_100224b0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x230));
  return;
}



// Function: Unwind@100224bb at 100224bb

void Unwind_100224bb(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100224c6 at 100224c6

void Unwind_100224c6(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100224d1 at 100224d1

void Unwind_100224d1(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10022510 at 10022510

void Unwind_10022510(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1002251b at 1002251b

void Unwind_1002251b(void)

{
  int unaff_EBP;
  
  FUN_10014400((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10022526 at 10022526

void Unwind_10022526(void)

{
  int unaff_EBP;
  
  FUN_1000b220(*(int *)(unaff_EBP + -0x10) + 0x3c);
  return;
}



// Function: Unwind@10022531 at 10022531

void Unwind_10022531(void)

{
  int unaff_EBP;
  
  FUN_10001ab0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x104));
  return;
}



// Function: Unwind@10022580 at 10022580

void Unwind_10022580(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1002258b at 1002258b

void Unwind_1002258b(void)

{
  int unaff_EBP;
  
  FUN_10014400((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@100225c0 at 100225c0

void Unwind_100225c0(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100225c8 at 100225c8

void Unwind_100225c8(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100225f0 at 100225f0

void Unwind_100225f0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100225f8 at 100225f8

void Unwind_100225f8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022603 at 10022603

void Unwind_10022603(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002260b at 1002260b

void Unwind_1002260b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022613 at 10022613

void Unwind_10022613(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002261b at 1002261b

void Unwind_1002261b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022640 at 10022640

void Unwind_10022640(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10022648 at 10022648

void Unwind_10022648(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022653 at 10022653

void Unwind_10022653(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002265b at 1002265b

void Unwind_1002265b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022663 at 10022663

void Unwind_10022663(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022690 at 10022690

void Unwind_10022690(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022698 at 10022698

void Unwind_10022698(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100226a3 at 100226a3

void Unwind_100226a3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100226ab at 100226ab

void Unwind_100226ab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100226b3 at 100226b3

void Unwind_100226b3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100226e0 at 100226e0

void Unwind_100226e0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100226e8 at 100226e8

void Unwind_100226e8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100226f3 at 100226f3

void Unwind_100226f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100226fb at 100226fb

void Unwind_100226fb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022703 at 10022703

void Unwind_10022703(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022730 at 10022730

void Unwind_10022730(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10022738 at 10022738

void Unwind_10022738(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022743 at 10022743

void Unwind_10022743(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002274b at 1002274b

void Unwind_1002274b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022753 at 10022753

void Unwind_10022753(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022780 at 10022780

void Unwind_10022780(void)

{
  int unaff_EBP;
  
  FUN_10002c90(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100227b0 at 100227b0

void Unwind_100227b0(void)

{
  int unaff_EBP;
  
  FUN_10002c90(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100227e0 at 100227e0

void Unwind_100227e0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100227eb at 100227eb

void Unwind_100227eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100227f3 at 100227f3

void Unwind_100227f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100227fb at 100227fb

void Unwind_100227fb(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10022840 at 10022840

void Unwind_10022840(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10022870 at 10022870

void Unwind_10022870(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10022878 at 10022878

void Unwind_10022878(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022883 at 10022883

void Unwind_10022883(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002288b at 1002288b

void Unwind_1002288b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022893 at 10022893

void Unwind_10022893(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002289b at 1002289b

void Unwind_1002289b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100228d0 at 100228d0

void Unwind_100228d0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100228d8 at 100228d8

void Unwind_100228d8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100228e3 at 100228e3

void Unwind_100228e3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100228eb at 100228eb

void Unwind_100228eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100228f3 at 100228f3

void Unwind_100228f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100228fb at 100228fb

void Unwind_100228fb(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022903 at 10022903

void Unwind_10022903(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022930 at 10022930

void Unwind_10022930(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10022938 at 10022938

void Unwind_10022938(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022943 at 10022943

void Unwind_10022943(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002294b at 1002294b

void Unwind_1002294b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022953 at 10022953

void Unwind_10022953(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002295b at 1002295b

void Unwind_1002295b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022963 at 10022963

void Unwind_10022963(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022990 at 10022990

void Unwind_10022990(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10022998 at 10022998

void Unwind_10022998(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100229a3 at 100229a3

void Unwind_100229a3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100229ab at 100229ab

void Unwind_100229ab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100229b3 at 100229b3

void Unwind_100229b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100229bb at 100229bb

void Unwind_100229bb(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100229c3 at 100229c3

void Unwind_100229c3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100229f0 at 100229f0

void Unwind_100229f0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100229f8 at 100229f8

void Unwind_100229f8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022a03 at 10022a03

void Unwind_10022a03(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10022a0b at 10022a0b

void Unwind_10022a0b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022a13 at 10022a13

void Unwind_10022a13(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022a1b at 10022a1b

void Unwind_10022a1b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022a23 at 10022a23

void Unwind_10022a23(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022a90 at 10022a90

void Unwind_10022a90(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@10022a98 at 10022a98

void Unwind_10022a98(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10022ac0 at 10022ac0

void Unwind_10022ac0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022acb at 10022acb

void Unwind_10022acb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022ad3 at 10022ad3

void Unwind_10022ad3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022adb at 10022adb

void Unwind_10022adb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022ae6 at 10022ae6

void Unwind_10022ae6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022aee at 10022aee

void Unwind_10022aee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022af6 at 10022af6

void Unwind_10022af6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b01 at 10022b01

void Unwind_10022b01(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b09 at 10022b09

void Unwind_10022b09(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b11 at 10022b11

void Unwind_10022b11(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022b40 at 10022b40

void Unwind_10022b40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b4b at 10022b4b

void Unwind_10022b4b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b53 at 10022b53

void Unwind_10022b53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b5b at 10022b5b

void Unwind_10022b5b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b66 at 10022b66

void Unwind_10022b66(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b6e at 10022b6e

void Unwind_10022b6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b76 at 10022b76

void Unwind_10022b76(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b81 at 10022b81

void Unwind_10022b81(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b89 at 10022b89

void Unwind_10022b89(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022b91 at 10022b91

void Unwind_10022b91(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022bc0 at 10022bc0

void Unwind_10022bc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022bcb at 10022bcb

void Unwind_10022bcb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022bd3 at 10022bd3

void Unwind_10022bd3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022bdb at 10022bdb

void Unwind_10022bdb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022be6 at 10022be6

void Unwind_10022be6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022bee at 10022bee

void Unwind_10022bee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022bf6 at 10022bf6

void Unwind_10022bf6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022c01 at 10022c01

void Unwind_10022c01(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c09 at 10022c09

void Unwind_10022c09(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022c11 at 10022c11

void Unwind_10022c11(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022c40 at 10022c40

void Unwind_10022c40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c4b at 10022c4b

void Unwind_10022c4b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022c53 at 10022c53

void Unwind_10022c53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c5b at 10022c5b

void Unwind_10022c5b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022c66 at 10022c66

void Unwind_10022c66(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c6e at 10022c6e

void Unwind_10022c6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022c76 at 10022c76

void Unwind_10022c76(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c81 at 10022c81

void Unwind_10022c81(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022c89 at 10022c89

void Unwind_10022c89(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022c91 at 10022c91

void Unwind_10022c91(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022cc0 at 10022cc0

void Unwind_10022cc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022ccb at 10022ccb

void Unwind_10022ccb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022cd3 at 10022cd3

void Unwind_10022cd3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022cdb at 10022cdb

void Unwind_10022cdb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022ce6 at 10022ce6

void Unwind_10022ce6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022cee at 10022cee

void Unwind_10022cee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022cf6 at 10022cf6

void Unwind_10022cf6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022d01 at 10022d01

void Unwind_10022d01(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022d09 at 10022d09

void Unwind_10022d09(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022d11 at 10022d11

void Unwind_10022d11(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022d40 at 10022d40

void Unwind_10022d40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022d4b at 10022d4b

void Unwind_10022d4b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10022d53 at 10022d53

void Unwind_10022d53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022d5b at 10022d5b

void Unwind_10022d5b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10022d66 at 10022d66

void Unwind_10022d66(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022d6e at 10022d6e

void Unwind_10022d6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10022d76 at 10022d76

void Unwind_10022d76(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10022da0 at 10022da0

void Unwind_10022da0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022dab at 10022dab

void Unwind_10022dab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022db3 at 10022db3

void Unwind_10022db3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022dbb at 10022dbb

void Unwind_10022dbb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022dc6 at 10022dc6

void Unwind_10022dc6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022dce at 10022dce

void Unwind_10022dce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022dd6 at 10022dd6

void Unwind_10022dd6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10022dde at 10022dde

void Unwind_10022dde(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022de6 at 10022de6

void Unwind_10022de6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022dee at 10022dee

void Unwind_10022dee(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10022df6 at 10022df6

void Unwind_10022df6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022dfe at 10022dfe

void Unwind_10022dfe(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022e06 at 10022e06

void Unwind_10022e06(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10022e40 at 10022e40

void Unwind_10022e40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022e4b at 10022e4b

void Unwind_10022e4b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022e53 at 10022e53

void Unwind_10022e53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022e5b at 10022e5b

void Unwind_10022e5b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022e66 at 10022e66

void Unwind_10022e66(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10022e6e at 10022e6e

void Unwind_10022e6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10022e76 at 10022e76

void Unwind_10022e76(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10022e7e at 10022e7e

void Unwind_10022e7e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022e86 at 10022e86

void Unwind_10022e86(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022e8e at 10022e8e

void Unwind_10022e8e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10022e96 at 10022e96

void Unwind_10022e96(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022e9e at 10022e9e

void Unwind_10022e9e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022ea6 at 10022ea6

void Unwind_10022ea6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10022ee0 at 10022ee0

void Unwind_10022ee0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022eeb at 10022eeb

void Unwind_10022eeb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10022ef3 at 10022ef3

void Unwind_10022ef3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022efb at 10022efb

void Unwind_10022efb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022f06 at 10022f06

void Unwind_10022f06(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022f0e at 10022f0e

void Unwind_10022f0e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022f16 at 10022f16

void Unwind_10022f16(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022f21 at 10022f21

void Unwind_10022f21(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022f29 at 10022f29

void Unwind_10022f29(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10022f31 at 10022f31

void Unwind_10022f31(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022f39 at 10022f39

void Unwind_10022f39(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10022f70 at 10022f70

void Unwind_10022f70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10022f7b at 10022f7b

void Unwind_10022f7b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10022f83 at 10022f83

void Unwind_10022f83(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10022f8b at 10022f8b

void Unwind_10022f8b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10022f96 at 10022f96

void Unwind_10022f96(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10022f9e at 10022f9e

void Unwind_10022f9e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10022fa6 at 10022fa6

void Unwind_10022fa6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10022fae at 10022fae

void Unwind_10022fae(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022fb6 at 10022fb6

void Unwind_10022fb6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10022fbe at 10022fbe

void Unwind_10022fbe(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10022ff0 at 10022ff0

void Unwind_10022ff0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10022ffb at 10022ffb

void Unwind_10022ffb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023003 at 10023003

void Unwind_10023003(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002300b at 1002300b

void Unwind_1002300b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023016 at 10023016

void Unwind_10023016(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002301e at 1002301e

void Unwind_1002301e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023026 at 10023026

void Unwind_10023026(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023031 at 10023031

void Unwind_10023031(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023039 at 10023039

void Unwind_10023039(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023041 at 10023041

void Unwind_10023041(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023049 at 10023049

void Unwind_10023049(void)

{
  int unaff_EBP;
  
  FUN_10015930(unaff_EBP + -0x5c);
  return;
}



// Function: Unwind@10023051 at 10023051

void Unwind_10023051(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023059 at 10023059

void Unwind_10023059(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023061 at 10023061

void Unwind_10023061(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023069 at 10023069

void Unwind_10023069(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023071 at 10023071

void Unwind_10023071(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100230a0 at 100230a0

void Unwind_100230a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100230ab at 100230ab

void Unwind_100230ab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100230b3 at 100230b3

void Unwind_100230b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100230bb at 100230bb

void Unwind_100230bb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100230c6 at 100230c6

void Unwind_100230c6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100230ce at 100230ce

void Unwind_100230ce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100230d6 at 100230d6

void Unwind_100230d6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100230e1 at 100230e1

void Unwind_100230e1(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100230e9 at 100230e9

void Unwind_100230e9(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100230f1 at 100230f1

void Unwind_100230f1(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100230f9 at 100230f9

void Unwind_100230f9(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023101 at 10023101

void Unwind_10023101(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10023130 at 10023130

void Unwind_10023130(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1002313e at 1002313e

void Unwind_1002313e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10023149 at 10023149

void Unwind_10023149(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10023154 at 10023154

void Unwind_10023154(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10023162 at 10023162

void Unwind_10023162(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1002316d at 1002316d

void Unwind_1002316d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10023178 at 10023178

void Unwind_10023178(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10023186 at 10023186

void Unwind_10023186(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10023191 at 10023191

void Unwind_10023191(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1002319c at 1002319c

void Unwind_1002319c(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@100231a7 at 100231a7

void Unwind_100231a7(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100231af at 100231af

void Unwind_100231af(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100231ba at 100231ba

void Unwind_100231ba(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100231c2 at 100231c2

void Unwind_100231c2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100231ca at 100231ca

void Unwind_100231ca(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100231d2 at 100231d2

void Unwind_100231d2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100231dd at 100231dd

void Unwind_100231dd(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100231e5 at 100231e5

void Unwind_100231e5(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100231ed at 100231ed

void Unwind_100231ed(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100231f8 at 100231f8

void Unwind_100231f8(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023200 at 10023200

void Unwind_10023200(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023208 at 10023208

void Unwind_10023208(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023240 at 10023240

void Unwind_10023240(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1002324e at 1002324e

void Unwind_1002324e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@10023259 at 10023259

void Unwind_10023259(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@10023264 at 10023264

void Unwind_10023264(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@10023272 at 10023272

void Unwind_10023272(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1002327d at 1002327d

void Unwind_1002327d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@10023288 at 10023288

void Unwind_10023288(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@10023296 at 10023296

void Unwind_10023296(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@100232a1 at 100232a1

void Unwind_100232a1(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@100232ac at 100232ac

void Unwind_100232ac(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@100232b7 at 100232b7

void Unwind_100232b7(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100232c2 at 100232c2

void Unwind_100232c2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100232ca at 100232ca

void Unwind_100232ca(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100232d2 at 100232d2

void Unwind_100232d2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100232da at 100232da

void Unwind_100232da(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100232e2 at 100232e2

void Unwind_100232e2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100232ed at 100232ed

void Unwind_100232ed(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100232f5 at 100232f5

void Unwind_100232f5(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100232fd at 100232fd

void Unwind_100232fd(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10023308 at 10023308

void Unwind_10023308(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023310 at 10023310

void Unwind_10023310(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023318 at 10023318

void Unwind_10023318(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023350 at 10023350

void Unwind_10023350(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002335b at 1002335b

void Unwind_1002335b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023363 at 10023363

void Unwind_10023363(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002336b at 1002336b

void Unwind_1002336b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023376 at 10023376

void Unwind_10023376(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002337e at 1002337e

void Unwind_1002337e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023386 at 10023386

void Unwind_10023386(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002338e at 1002338e

void Unwind_1002338e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023399 at 10023399

void Unwind_10023399(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100233a1 at 100233a1

void Unwind_100233a1(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100233ac at 100233ac

void Unwind_100233ac(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100233b4 at 100233b4

void Unwind_100233b4(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100233bc at 100233bc

void Unwind_100233bc(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100233f0 at 100233f0

void Unwind_100233f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100027c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10023430 at 10023430

void Unwind_10023430(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@1002343e at 1002343e

void Unwind_1002343e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x174));
  return;
}



// Function: Unwind@10023449 at 10023449

void Unwind_10023449(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@10023454 at 10023454

void Unwind_10023454(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x174));
  return;
}



// Function: Unwind@10023462 at 10023462

void Unwind_10023462(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@1002346d at 1002346d

void Unwind_1002346d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x174));
  return;
}



// Function: Unwind@10023478 at 10023478

void Unwind_10023478(void)

{
  int unaff_EBP;
  
  FUN_1001a600(unaff_EBP + -0x8c);
  return;
}



// Function: Unwind@10023483 at 10023483

void Unwind_10023483(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002348b at 1002348b

void Unwind_1002348b(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10023496 at 10023496

void Unwind_10023496(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002349e at 1002349e

void Unwind_1002349e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100234a6 at 100234a6

void Unwind_100234a6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100234ae at 100234ae

void Unwind_100234ae(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100234e0 at 100234e0

void Unwind_100234e0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100234eb at 100234eb

void Unwind_100234eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100234f3 at 100234f3

void Unwind_100234f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100234fb at 100234fb

void Unwind_100234fb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023506 at 10023506

void Unwind_10023506(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002350e at 1002350e

void Unwind_1002350e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023516 at 10023516

void Unwind_10023516(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002351e at 1002351e

void Unwind_1002351e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023529 at 10023529

void Unwind_10023529(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023531 at 10023531

void Unwind_10023531(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023539 at 10023539

void Unwind_10023539(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023541 at 10023541

void Unwind_10023541(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023549 at 10023549

void Unwind_10023549(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023551 at 10023551

void Unwind_10023551(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10023580 at 10023580

void Unwind_10023580(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@100235b0 at 100235b0

void Unwind_100235b0(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100235bb at 100235bb

void Unwind_100235bb(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@100235f0 at 100235f0

void Unwind_100235f0(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100235fb at 100235fb

void Unwind_100235fb(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((_Container_base0 *)(*(int *)(unaff_EBP + -0x14) + 0x14));
  return;
}



// Function: Unwind@10023606 at 10023606

void Unwind_10023606(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10023611 at 10023611

void Unwind_10023611(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((_Container_base0 *)(*(int *)(unaff_EBP + -0x14) + 0x48));
  return;
}



// Function: Unwind@1002361c at 1002361c

void Unwind_1002361c(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x58));
  return;
}



// Function: Unwind@10023627 at 10023627

void Unwind_10023627(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x74));
  return;
}



// Function: Unwind@10023632 at 10023632

void Unwind_10023632(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x90));
  return;
}



// Function: Unwind@10023640 at 10023640

void Unwind_10023640(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xac));
  return;
}



// Function: Unwind@10023670 at 10023670

void Unwind_10023670(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1002367b at 1002367b

void Unwind_1002367b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10023683 at 10023683

void Unwind_10023683(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1002368b at 1002368b

void Unwind_1002368b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10023696 at 10023696

void Unwind_10023696(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1002369e at 1002369e

void Unwind_1002369e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100236a6 at 100236a6

void Unwind_100236a6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100236ae at 100236ae

void Unwind_100236ae(void)

{
  int unaff_EBP;
  
  FUN_10017110(unaff_EBP + -0x54);
  return;
}



// Function: Unwind@100236b6 at 100236b6

void Unwind_100236b6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10023710 at 10023710

void Unwind_10023710(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002371b at 1002371b

void Unwind_1002371b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023723 at 10023723

void Unwind_10023723(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002372b at 1002372b

void Unwind_1002372b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023736 at 10023736

void Unwind_10023736(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002373e at 1002373e

void Unwind_1002373e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023746 at 10023746

void Unwind_10023746(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023770 at 10023770

void Unwind_10023770(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1002377b at 1002377b

void Unwind_1002377b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10023783 at 10023783

void Unwind_10023783(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1002378b at 1002378b

void Unwind_1002378b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10023796 at 10023796

void Unwind_10023796(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1002379e at 1002379e

void Unwind_1002379e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100237a6 at 100237a6

void Unwind_100237a6(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100237ae at 100237ae

void Unwind_100237ae(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100237b6 at 100237b6

void Unwind_100237b6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100237be at 100237be

void Unwind_100237be(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100237c6 at 100237c6

void Unwind_100237c6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10023800 at 10023800

void Unwind_10023800(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002380b at 1002380b

void Unwind_1002380b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023813 at 10023813

void Unwind_10023813(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002381b at 1002381b

void Unwind_1002381b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023826 at 10023826

void Unwind_10023826(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002382e at 1002382e

void Unwind_1002382e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023836 at 10023836

void Unwind_10023836(void)

{
  int unaff_EBP;
  
  FUN_100123b0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002383e at 1002383e

void Unwind_1002383e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023870 at 10023870

void Unwind_10023870(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@100238a0 at 100238a0

void Unwind_100238a0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100238a8 at 100238a8

void Unwind_100238a8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100238b3 at 100238b3

void Unwind_100238b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100238bb at 100238bb

void Unwind_100238bb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100238c3 at 100238c3

void Unwind_100238c3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100238f0 at 100238f0

void Unwind_100238f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100238fb at 100238fb

void Unwind_100238fb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023903 at 10023903

void Unwind_10023903(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002390b at 1002390b

void Unwind_1002390b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023950 at 10023950

void Unwind_10023950(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023958 at 10023958

void Unwind_10023958(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023963 at 10023963

void Unwind_10023963(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002396b at 1002396b

void Unwind_1002396b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023973 at 10023973

void Unwind_10023973(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002397b at 1002397b

void Unwind_1002397b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100239b0 at 100239b0

void Unwind_100239b0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100239b8 at 100239b8

void Unwind_100239b8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100239c3 at 100239c3

void Unwind_100239c3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100239cb at 100239cb

void Unwind_100239cb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100239d3 at 100239d3

void Unwind_100239d3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100239de at 100239de

void Unwind_100239de(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100239e6 at 100239e6

void Unwind_100239e6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100239ee at 100239ee

void Unwind_100239ee(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100239f6 at 100239f6

void Unwind_100239f6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100239fe at 100239fe

void Unwind_100239fe(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023a06 at 10023a06

void Unwind_10023a06(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10023a40 at 10023a40

void Unwind_10023a40(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10023a48 at 10023a48

void Unwind_10023a48(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023a53 at 10023a53

void Unwind_10023a53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023a5b at 10023a5b

void Unwind_10023a5b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023a63 at 10023a63

void Unwind_10023a63(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023a6e at 10023a6e

void Unwind_10023a6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023a76 at 10023a76

void Unwind_10023a76(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023a7e at 10023a7e

void Unwind_10023a7e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023a86 at 10023a86

void Unwind_10023a86(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10023ac0 at 10023ac0

void Unwind_10023ac0(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10023acb at 10023acb

void Unwind_10023acb(void)

{
  int unaff_EBP;
  
  FUN_10014400((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023ad6 at 10023ad6

void Unwind_10023ad6(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ca50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10023b00 at 10023b00

void Unwind_10023b00(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10023b11 at 10023b11

void Unwind_10023b11(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10023b40 at 10023b40

void Unwind_10023b40(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10023b4b at 10023b4b

void Unwind_10023b4b(void)

{
  int unaff_EBP;
  
  FUN_10014400((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023b56 at 10023b56

void Unwind_10023b56(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000ca50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10023b61 at 10023b61

void Unwind_10023b61(void)

{
  int unaff_EBP;
  
  FUN_10001ab0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@10023b6c at 10023b6c

void Unwind_10023b6c(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@10023ba0 at 10023ba0

void Unwind_10023ba0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023bab at 10023bab

void Unwind_10023bab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023bb3 at 10023bb3

void Unwind_10023bb3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023bbb at 10023bbb

void Unwind_10023bbb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023bc6 at 10023bc6

void Unwind_10023bc6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023bce at 10023bce

void Unwind_10023bce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023bd6 at 10023bd6

void Unwind_10023bd6(void)

{
  int unaff_EBP;
  
  FUN_1000c490(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@10023bde at 10023bde

void Unwind_10023bde(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023be6 at 10023be6

void Unwind_10023be6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10023c20 at 10023c20

void Unwind_10023c20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023c2b at 10023c2b

void Unwind_10023c2b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023c33 at 10023c33

void Unwind_10023c33(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023c3b at 10023c3b

void Unwind_10023c3b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023c46 at 10023c46

void Unwind_10023c46(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023c4e at 10023c4e

void Unwind_10023c4e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023c56 at 10023c56

void Unwind_10023c56(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023c61 at 10023c61

void Unwind_10023c61(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023c69 at 10023c69

void Unwind_10023c69(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10023ca0 at 10023ca0

void Unwind_10023ca0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023cab at 10023cab

void Unwind_10023cab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023cb3 at 10023cb3

void Unwind_10023cb3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023cbb at 10023cbb

void Unwind_10023cbb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023cc6 at 10023cc6

void Unwind_10023cc6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023cce at 10023cce

void Unwind_10023cce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023cd6 at 10023cd6

void Unwind_10023cd6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023ce1 at 10023ce1

void Unwind_10023ce1(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023ce9 at 10023ce9

void Unwind_10023ce9(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10023d20 at 10023d20

void Unwind_10023d20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023d2b at 10023d2b

void Unwind_10023d2b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023d33 at 10023d33

void Unwind_10023d33(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023d3b at 10023d3b

void Unwind_10023d3b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023d46 at 10023d46

void Unwind_10023d46(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023d4e at 10023d4e

void Unwind_10023d4e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023d56 at 10023d56

void Unwind_10023d56(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023d61 at 10023d61

void Unwind_10023d61(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023d69 at 10023d69

void Unwind_10023d69(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10023da0 at 10023da0

void Unwind_10023da0(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10023dab at 10023dab

void Unwind_10023dab(void)

{
  int unaff_EBP;
  
  FUN_10014400((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023db6 at 10023db6

void Unwind_10023db6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10023dc1 at 10023dc1

void Unwind_10023dc1(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@10023dcc at 10023dcc

void Unwind_10023dcc(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@10023dd7 at 10023dd7

void Unwind_10023dd7(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@10023de5 at 10023de5

void Unwind_10023de5(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa8));
  return;
}



// Function: Unwind@10023df3 at 10023df3

void Unwind_10023df3(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 200));
  return;
}



// Function: Unwind@10023e01 at 10023e01

void Unwind_10023e01(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe4));
  return;
}



// Function: Unwind@10023e0f at 10023e0f

void Unwind_10023e0f(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x100));
  return;
}



// Function: Unwind@10023e40 at 10023e40

void Unwind_10023e40(void)

{
  int unaff_EBP;
  
  FUN_10001fc0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10023e70 at 10023e70

void Unwind_10023e70(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10023e78 at 10023e78

void Unwind_10023e78(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023e83 at 10023e83

void Unwind_10023e83(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023e8b at 10023e8b

void Unwind_10023e8b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023e93 at 10023e93

void Unwind_10023e93(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023ec0 at 10023ec0

void Unwind_10023ec0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023ecb at 10023ecb

void Unwind_10023ecb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023ed3 at 10023ed3

void Unwind_10023ed3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023edb at 10023edb

void Unwind_10023edb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023ee6 at 10023ee6

void Unwind_10023ee6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023eee at 10023eee

void Unwind_10023eee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023ef6 at 10023ef6

void Unwind_10023ef6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023f20 at 10023f20

void Unwind_10023f20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023f2b at 10023f2b

void Unwind_10023f2b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023f33 at 10023f33

void Unwind_10023f33(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023f3b at 10023f3b

void Unwind_10023f3b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023f60 at 10023f60

void Unwind_10023f60(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023f6b at 10023f6b

void Unwind_10023f6b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023f73 at 10023f73

void Unwind_10023f73(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023f7b at 10023f7b

void Unwind_10023f7b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023f86 at 10023f86

void Unwind_10023f86(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023f8e at 10023f8e

void Unwind_10023f8e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023f96 at 10023f96

void Unwind_10023f96(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023fc0 at 10023fc0

void Unwind_10023fc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023fcb at 10023fcb

void Unwind_10023fcb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023fd3 at 10023fd3

void Unwind_10023fd3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023fdb at 10023fdb

void Unwind_10023fdb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023fe6 at 10023fe6

void Unwind_10023fe6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023fee at 10023fee

void Unwind_10023fee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023ff6 at 10023ff6

void Unwind_10023ff6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024020 at 10024020

void Unwind_10024020(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002402b at 1002402b

void Unwind_1002402b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024033 at 10024033

void Unwind_10024033(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002403b at 1002403b

void Unwind_1002403b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024046 at 10024046

void Unwind_10024046(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002404e at 1002404e

void Unwind_1002404e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024056 at 10024056

void Unwind_10024056(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024080 at 10024080

void Unwind_10024080(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002408b at 1002408b

void Unwind_1002408b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024093 at 10024093

void Unwind_10024093(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002409b at 1002409b

void Unwind_1002409b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100240a6 at 100240a6

void Unwind_100240a6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100240ae at 100240ae

void Unwind_100240ae(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100240b6 at 100240b6

void Unwind_100240b6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100240e0 at 100240e0

void Unwind_100240e0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100240eb at 100240eb

void Unwind_100240eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100240f3 at 100240f3

void Unwind_100240f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100240fb at 100240fb

void Unwind_100240fb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024106 at 10024106

void Unwind_10024106(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002410e at 1002410e

void Unwind_1002410e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024116 at 10024116

void Unwind_10024116(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024140 at 10024140

void Unwind_10024140(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002414b at 1002414b

void Unwind_1002414b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024153 at 10024153

void Unwind_10024153(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002415b at 1002415b

void Unwind_1002415b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024166 at 10024166

void Unwind_10024166(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002416e at 1002416e

void Unwind_1002416e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024176 at 10024176

void Unwind_10024176(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100241a0 at 100241a0

void Unwind_100241a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100241ab at 100241ab

void Unwind_100241ab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100241b3 at 100241b3

void Unwind_100241b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100241bb at 100241bb

void Unwind_100241bb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100241c6 at 100241c6

void Unwind_100241c6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100241ce at 100241ce

void Unwind_100241ce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100241d6 at 100241d6

void Unwind_100241d6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024200 at 10024200

void Unwind_10024200(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002420b at 1002420b

void Unwind_1002420b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024213 at 10024213

void Unwind_10024213(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002421b at 1002421b

void Unwind_1002421b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024226 at 10024226

void Unwind_10024226(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002422e at 1002422e

void Unwind_1002422e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024236 at 10024236

void Unwind_10024236(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024260 at 10024260

void Unwind_10024260(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002426b at 1002426b

void Unwind_1002426b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024273 at 10024273

void Unwind_10024273(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002427b at 1002427b

void Unwind_1002427b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024286 at 10024286

void Unwind_10024286(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002428e at 1002428e

void Unwind_1002428e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024296 at 10024296

void Unwind_10024296(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100242c0 at 100242c0

void Unwind_100242c0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100242c8 at 100242c8

void Unwind_100242c8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100242d3 at 100242d3

void Unwind_100242d3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100242db at 100242db

void Unwind_100242db(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100242e3 at 100242e3

void Unwind_100242e3(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100242eb at 100242eb

void Unwind_100242eb(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024320 at 10024320

void Unwind_10024320(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10024328 at 10024328

void Unwind_10024328(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024333 at 10024333

void Unwind_10024333(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002433b at 1002433b

void Unwind_1002433b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024343 at 10024343

void Unwind_10024343(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002434e at 1002434e

void Unwind_1002434e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024356 at 10024356

void Unwind_10024356(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002435e at 1002435e

void Unwind_1002435e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024366 at 10024366

void Unwind_10024366(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100243a0 at 100243a0

void Unwind_100243a0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100243a8 at 100243a8

void Unwind_100243a8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100243b3 at 100243b3

void Unwind_100243b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100243bb at 100243bb

void Unwind_100243bb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100243c3 at 100243c3

void Unwind_100243c3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100243ce at 100243ce

void Unwind_100243ce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100243d6 at 100243d6

void Unwind_100243d6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100243de at 100243de

void Unwind_100243de(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100243e6 at 100243e6

void Unwind_100243e6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024420 at 10024420

void Unwind_10024420(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10024428 at 10024428

void Unwind_10024428(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024433 at 10024433

void Unwind_10024433(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002443b at 1002443b

void Unwind_1002443b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024443 at 10024443

void Unwind_10024443(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002444e at 1002444e

void Unwind_1002444e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024456 at 10024456

void Unwind_10024456(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002445e at 1002445e

void Unwind_1002445e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024466 at 10024466

void Unwind_10024466(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100244a0 at 100244a0

void Unwind_100244a0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100244a8 at 100244a8

void Unwind_100244a8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100244b3 at 100244b3

void Unwind_100244b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100244bb at 100244bb

void Unwind_100244bb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100244c3 at 100244c3

void Unwind_100244c3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100244ce at 100244ce

void Unwind_100244ce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100244d6 at 100244d6

void Unwind_100244d6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100244de at 100244de

void Unwind_100244de(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100244e6 at 100244e6

void Unwind_100244e6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024520 at 10024520

void Unwind_10024520(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10024528 at 10024528

void Unwind_10024528(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024533 at 10024533

void Unwind_10024533(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002453b at 1002453b

void Unwind_1002453b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024543 at 10024543

void Unwind_10024543(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002454e at 1002454e

void Unwind_1002454e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024556 at 10024556

void Unwind_10024556(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002455e at 1002455e

void Unwind_1002455e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024566 at 10024566

void Unwind_10024566(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100245a0 at 100245a0

void Unwind_100245a0(void)

{
  int unaff_EBP;
  
  FUN_100021c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100245a8 at 100245a8

void Unwind_100245a8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100245b3 at 100245b3

void Unwind_100245b3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100245bb at 100245bb

void Unwind_100245bb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100245c3 at 100245c3

void Unwind_100245c3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100245ce at 100245ce

void Unwind_100245ce(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100245d6 at 100245d6

void Unwind_100245d6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100245de at 100245de

void Unwind_100245de(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100245e6 at 100245e6

void Unwind_100245e6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024620 at 10024620

void Unwind_10024620(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002462b at 1002462b

void Unwind_1002462b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024633 at 10024633

void Unwind_10024633(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002463b at 1002463b

void Unwind_1002463b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024646 at 10024646

void Unwind_10024646(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002464e at 1002464e

void Unwind_1002464e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024656 at 10024656

void Unwind_10024656(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002465e at 1002465e

void Unwind_1002465e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024690 at 10024690

void Unwind_10024690(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002469b at 1002469b

void Unwind_1002469b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100246a3 at 100246a3

void Unwind_100246a3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100246ab at 100246ab

void Unwind_100246ab(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100246b6 at 100246b6

void Unwind_100246b6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100246be at 100246be

void Unwind_100246be(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100246c6 at 100246c6

void Unwind_100246c6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100246ce at 100246ce

void Unwind_100246ce(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024700 at 10024700

void Unwind_10024700(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002470b at 1002470b

void Unwind_1002470b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024713 at 10024713

void Unwind_10024713(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002471b at 1002471b

void Unwind_1002471b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024726 at 10024726

void Unwind_10024726(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002472e at 1002472e

void Unwind_1002472e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024736 at 10024736

void Unwind_10024736(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002473e at 1002473e

void Unwind_1002473e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024770 at 10024770

void Unwind_10024770(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_100027c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024789 at 10024789

void Unwind_10024789(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024794 at 10024794

void Unwind_10024794(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002479c at 1002479c

void Unwind_1002479c(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100247a4 at 100247a4

void Unwind_100247a4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100247af at 100247af

void Unwind_100247af(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100247b7 at 100247b7

void Unwind_100247b7(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100247bf at 100247bf

void Unwind_100247bf(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100247f0 at 100247f0

void Unwind_100247f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100247fb at 100247fb

void Unwind_100247fb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024803 at 10024803

void Unwind_10024803(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002480b at 1002480b

void Unwind_1002480b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024816 at 10024816

void Unwind_10024816(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002481e at 1002481e

void Unwind_1002481e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024826 at 10024826

void Unwind_10024826(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002482e at 1002482e

void Unwind_1002482e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024860 at 10024860

void Unwind_10024860(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024890 at 10024890

void Unwind_10024890(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100248c0 at 100248c0

void Unwind_100248c0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100248cb at 100248cb

void Unwind_100248cb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100248d3 at 100248d3

void Unwind_100248d3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100248db at 100248db

void Unwind_100248db(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100248e3 at 100248e3

void Unwind_100248e3(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100248eb at 100248eb

void Unwind_100248eb(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100248f3 at 100248f3

void Unwind_100248f3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024920 at 10024920

void Unwind_10024920(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024928 at 10024928

void Unwind_10024928(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024960 at 10024960

void Unwind_10024960(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1002496b at 1002496b

void Unwind_1002496b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10024973 at 10024973

void Unwind_10024973(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1002497b at 1002497b

void Unwind_1002497b(void)

{
  int unaff_EBP;
  
  FUN_1000c490(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@10024983 at 10024983

void Unwind_10024983(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002498b at 1002498b

void Unwind_1002498b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024993 at 10024993

void Unwind_10024993(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100249c0 at 100249c0

void Unwind_100249c0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100249cb at 100249cb

void Unwind_100249cb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100249d3 at 100249d3

void Unwind_100249d3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100249db at 100249db

void Unwind_100249db(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100249e6 at 100249e6

void Unwind_100249e6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100249ee at 100249ee

void Unwind_100249ee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100249f6 at 100249f6

void Unwind_100249f6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024a01 at 10024a01

void Unwind_10024a01(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a09 at 10024a09

void Unwind_10024a09(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024a11 at 10024a11

void Unwind_10024a11(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a19 at 10024a19

void Unwind_10024a19(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a21 at 10024a21

void Unwind_10024a21(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024a29 at 10024a29

void Unwind_10024a29(void)

{
  int unaff_EBP;
  
  FUN_1000c490(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10024a31 at 10024a31

void Unwind_10024a31(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a39 at 10024a39

void Unwind_10024a39(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024a41 at 10024a41

void Unwind_10024a41(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a49 at 10024a49

void Unwind_10024a49(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024a51 at 10024a51

void Unwind_10024a51(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10024a5c at 10024a5c

void Unwind_10024a5c(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a64 at 10024a64

void Unwind_10024a64(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024a6c at 10024a6c

void Unwind_10024a6c(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024a74 at 10024a74

void Unwind_10024a74(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024a7c at 10024a7c

void Unwind_10024a7c(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024ab0 at 10024ab0

void Unwind_10024ab0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024abb at 10024abb

void Unwind_10024abb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024ac3 at 10024ac3

void Unwind_10024ac3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024acb at 10024acb

void Unwind_10024acb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024ad6 at 10024ad6

void Unwind_10024ad6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024ade at 10024ade

void Unwind_10024ade(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024ae6 at 10024ae6

void Unwind_10024ae6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024aee at 10024aee

void Unwind_10024aee(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024af6 at 10024af6

void Unwind_10024af6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10024afe at 10024afe

void Unwind_10024afe(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10024b40 at 10024b40

void Unwind_10024b40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024b4b at 10024b4b

void Unwind_10024b4b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024b53 at 10024b53

void Unwind_10024b53(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024b5b at 10024b5b

void Unwind_10024b5b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024b66 at 10024b66

void Unwind_10024b66(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10024b6e at 10024b6e

void Unwind_10024b6e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024b76 at 10024b76

void Unwind_10024b76(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024b7e at 10024b7e

void Unwind_10024b7e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024b86 at 10024b86

void Unwind_10024b86(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10024b8e at 10024b8e

void Unwind_10024b8e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10024bd0 at 10024bd0

void Unwind_10024bd0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024bd8 at 10024bd8

void Unwind_10024bd8(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(*(int *)(unaff_EBP + -0x24) + 4));
  return;
}



// Function: Unwind@10024c10 at 10024c10

void Unwind_10024c10(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0x28));
  return;
}



// Function: Unwind@10024c18 at 10024c18

void Unwind_10024c18(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@10024c20 at 10024c20

void Unwind_10024c20(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0x1c));
  return;
}



// Function: Unwind@10024c50 at 10024c50

void Unwind_10024c50(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024c58 at 10024c58

void Unwind_10024c58(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024c60 at 10024c60

void Unwind_10024c60(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10024c68 at 10024c68

void Unwind_10024c68(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10024c70 at 10024c70

void Unwind_10024c70(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024ca0 at 10024ca0

void Unwind_10024ca0(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024ca8 at 10024ca8

void Unwind_10024ca8(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024cb0 at 10024cb0

void Unwind_10024cb0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@10024cb8 at 10024cb8

void Unwind_10024cb8(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10024cc0 at 10024cc0

void Unwind_10024cc0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024cf0 at 10024cf0

void Unwind_10024cf0(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024cf8 at 10024cf8

void Unwind_10024cf8(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024d00 at 10024d00

void Unwind_10024d00(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@10024d08 at 10024d08

void Unwind_10024d08(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10024d10 at 10024d10

void Unwind_10024d10(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@10024d18 at 10024d18

void Unwind_10024d18(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@10024d20 at 10024d20

void Unwind_10024d20(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@10024d28 at 10024d28

void Unwind_10024d28(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10024d30 at 10024d30

void Unwind_10024d30(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@10024d60 at 10024d60

void Unwind_10024d60(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10024d6b at 10024d6b

void Unwind_10024d6b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x214));
  return;
}



// Function: Unwind@10024d76 at 10024d76

void Unwind_10024d76(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@10024d81 at 10024d81

void Unwind_10024d81(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10024dc0 at 10024dc0

void Unwind_10024dc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024dcb at 10024dcb

void Unwind_10024dcb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024dd3 at 10024dd3

void Unwind_10024dd3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024ddb at 10024ddb

void Unwind_10024ddb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024de6 at 10024de6

void Unwind_10024de6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024dee at 10024dee

void Unwind_10024dee(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024df6 at 10024df6

void Unwind_10024df6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024e20 at 10024e20

void Unwind_10024e20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024e2b at 10024e2b

void Unwind_10024e2b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024e33 at 10024e33

void Unwind_10024e33(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024e3b at 10024e3b

void Unwind_10024e3b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024e46 at 10024e46

void Unwind_10024e46(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024e4e at 10024e4e

void Unwind_10024e4e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024e56 at 10024e56

void Unwind_10024e56(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024e80 at 10024e80

void Unwind_10024e80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024e8b at 10024e8b

void Unwind_10024e8b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024e93 at 10024e93

void Unwind_10024e93(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024e9b at 10024e9b

void Unwind_10024e9b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024ea6 at 10024ea6

void Unwind_10024ea6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024eae at 10024eae

void Unwind_10024eae(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024ee0 at 10024ee0

void Unwind_10024ee0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024eeb at 10024eeb

void Unwind_10024eeb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10024ef3 at 10024ef3

void Unwind_10024ef3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024efb at 10024efb

void Unwind_10024efb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10024f06 at 10024f06

void Unwind_10024f06(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024f0e at 10024f0e

void Unwind_10024f0e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10024f16 at 10024f16

void Unwind_10024f16(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024f1e at 10024f1e

void Unwind_10024f1e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10024f26 at 10024f26

void Unwind_10024f26(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024f2e at 10024f2e

void Unwind_10024f2e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10024f36 at 10024f36

void Unwind_10024f36(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024f70 at 10024f70

void Unwind_10024f70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10024f7e at 10024f7e

void Unwind_10024f7e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10024f89 at 10024f89

void Unwind_10024f89(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10024f94 at 10024f94

void Unwind_10024f94(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10024fa2 at 10024fa2

void Unwind_10024fa2(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10024fad at 10024fad

void Unwind_10024fad(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -200));
  return;
}



// Function: Unwind@10024fb8 at 10024fb8

void Unwind_10024fb8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10024fc6 at 10024fc6

void Unwind_10024fc6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xcc) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xcc) = *(uint *)(unaff_EBP + -0xcc) & 0xfffffffe;
    FUN_100027c0((undefined4 *)(unaff_EBP + -0xc4));
    return;
  }
  return;
}



// Function: Unwind@10024fe8 at 10024fe8

void Unwind_10024fe8(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10024ff3 at 10024ff3

void Unwind_10024ff3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10025001 at 10025001

void Unwind_10025001(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xcc) & 2) != 0) {
    *(uint *)(unaff_EBP + -0xcc) = *(uint *)(unaff_EBP + -0xcc) & 0xfffffffd;
    FUN_100027c0((undefined4 *)(unaff_EBP + -0xc4));
    return;
  }
  return;
}



// Function: Unwind@10025023 at 10025023

void Unwind_10025023(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1002502e at 1002502e

void Unwind_1002502e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@10025070 at 10025070

void Unwind_10025070(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1002507b at 1002507b

void Unwind_1002507b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025083 at 10025083

void Unwind_10025083(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1002508b at 1002508b

void Unwind_1002508b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10025096 at 10025096

void Unwind_10025096(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1002509e at 1002509e

void Unwind_1002509e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100250a6 at 100250a6

void Unwind_100250a6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100250ae at 100250ae

void Unwind_100250ae(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100250b6 at 100250b6

void Unwind_100250b6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100250be at 100250be

void Unwind_100250be(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100250c9 at 100250c9

void Unwind_100250c9(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100250d1 at 100250d1

void Unwind_100250d1(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100250d9 at 100250d9

void Unwind_100250d9(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100250e4 at 100250e4

void Unwind_100250e4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -100) & 1) != 0) {
    *(uint *)(unaff_EBP + -100) = *(uint *)(unaff_EBP + -100) & 0xfffffffe;
    FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
    return;
  }
  return;
}



// Function: Unwind@100250fd at 100250fd

void Unwind_100250fd(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025105 at 10025105

void Unwind_10025105(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10025140 at 10025140

void Unwind_10025140(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002514b at 1002514b

void Unwind_1002514b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10025153 at 10025153

void Unwind_10025153(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002515b at 1002515b

void Unwind_1002515b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10025166 at 10025166

void Unwind_10025166(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002516e at 1002516e

void Unwind_1002516e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10025176 at 10025176

void Unwind_10025176(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002517e at 1002517e

void Unwind_1002517e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100251b0 at 100251b0

void Unwind_100251b0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100251e0 at 100251e0

void Unwind_100251e0(void)

{
  int unaff_EBP;
  
  FUN_1000c490(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10025210 at 10025210

void Unwind_10025210(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10025240 at 10025240

void Unwind_10025240(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002524b at 1002524b

void Unwind_1002524b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025253 at 10025253

void Unwind_10025253(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002525b at 1002525b

void Unwind_1002525b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025266 at 10025266

void Unwind_10025266(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002526e at 1002526e

void Unwind_1002526e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025276 at 10025276

void Unwind_10025276(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002527e at 1002527e

void Unwind_1002527e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025286 at 10025286

void Unwind_10025286(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002528e at 1002528e

void Unwind_1002528e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025296 at 10025296

void Unwind_10025296(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100252d0 at 100252d0

void Unwind_100252d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100252db at 100252db

void Unwind_100252db(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100252e3 at 100252e3

void Unwind_100252e3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100252eb at 100252eb

void Unwind_100252eb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100252f6 at 100252f6

void Unwind_100252f6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100252fe at 100252fe

void Unwind_100252fe(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025306 at 10025306

void Unwind_10025306(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025311 at 10025311

void Unwind_10025311(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10025319 at 10025319

void Unwind_10025319(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025321 at 10025321

void Unwind_10025321(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025329 at 10025329

void Unwind_10025329(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025331 at 10025331

void Unwind_10025331(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10025339 at 10025339

void Unwind_10025339(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025341 at 10025341

void Unwind_10025341(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10025349 at 10025349

void Unwind_10025349(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025351 at 10025351

void Unwind_10025351(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025359 at 10025359

void Unwind_10025359(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10025361 at 10025361

void Unwind_10025361(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10025369 at 10025369

void Unwind_10025369(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10025371 at 10025371

void Unwind_10025371(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10025379 at 10025379

void Unwind_10025379(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025381 at 10025381

void Unwind_10025381(void)

{
  int unaff_EBP;
  
  FUN_1000c490(unaff_EBP + -0x8c);
  return;
}



// Function: Unwind@1002538c at 1002538c

void Unwind_1002538c(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025394 at 10025394

void Unwind_10025394(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1002539c at 1002539c

void Unwind_1002539c(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100253d0 at 100253d0

void Unwind_100253d0(void)

{
  int unaff_EBP;
  
  FUN_1000c150(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100253d8 at 100253d8

void Unwind_100253d8(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@10025400 at 10025400

void Unwind_10025400(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1002540b at 1002540b

void Unwind_1002540b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025413 at 10025413

void Unwind_10025413(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1002541b at 1002541b

void Unwind_1002541b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025426 at 10025426

void Unwind_10025426(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1002542e at 1002542e

void Unwind_1002542e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025436 at 10025436

void Unwind_10025436(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1002543e at 1002543e

void Unwind_1002543e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025446 at 10025446

void Unwind_10025446(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002544e at 1002544e

void Unwind_1002544e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025456 at 10025456

void Unwind_10025456(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002545e at 1002545e

void Unwind_1002545e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10025490 at 10025490

void Unwind_10025490(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10025498 at 10025498

void Unwind_10025498(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@100254a3 at 100254a3

void Unwind_100254a3(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@100254ae at 100254ae

void Unwind_100254ae(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@100254b9 at 100254b9

void Unwind_100254b9(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@100254c4 at 100254c4

void Unwind_100254c4(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@100254d2 at 100254d2

void Unwind_100254d2(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa8));
  return;
}



// Function: Unwind@10025500 at 10025500

void Unwind_10025500(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005b80(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10025540 at 10025540

void Unwind_10025540(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002554b at 1002554b

void Unwind_1002554b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025553 at 10025553

void Unwind_10025553(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002555b at 1002555b

void Unwind_1002555b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025566 at 10025566

void Unwind_10025566(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002556e at 1002556e

void Unwind_1002556e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025576 at 10025576

void Unwind_10025576(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002557e at 1002557e

void Unwind_1002557e(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025586 at 10025586

void Unwind_10025586(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002558e at 1002558e

void Unwind_1002558e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100255c0 at 100255c0

void Unwind_100255c0(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10025610 at 10025610

void Unwind_10025610(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10025621 at 10025621

void Unwind_10025621(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10025650 at 10025650

void Unwind_10025650(void)

{
  int unaff_EBP;
  
  FUN_10018c70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10025680 at 10025680

void Unwind_10025680(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002568b at 1002568b

void Unwind_1002568b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10025696 at 10025696

void Unwind_10025696(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001a290((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@100256a1 at 100256a1

void Unwind_100256a1(void)

{
  int unaff_EBP;
  
  FUN_1001a5a0((void *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@100256ac at 100256ac

void Unwind_100256ac(void)

{
  int unaff_EBP;
  
  FUN_10018c70(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100256d0 at 100256d0

void Unwind_100256d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x274) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x274) = *(uint *)(unaff_EBP + -0x274) & 0xfffffffe;
    FUN_10005b80(*(undefined4 **)(unaff_EBP + -0x250));
    return;
  }
  return;
}



// Function: Unwind@100256f2 at 100256f2

void Unwind_100256f2(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@10025700 at 10025700

void Unwind_10025700(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@1002570b at 1002570b

void Unwind_1002570b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@10025716 at 10025716

void Unwind_10025716(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@10025724 at 10025724

void Unwind_10025724(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@1002572f at 1002572f

void Unwind_1002572f(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@1002573a at 1002573a

void Unwind_1002573a(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x230));
  return;
}



// Function: Unwind@10025745 at 10025745

void Unwind_10025745(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@10025750 at 10025750

void Unwind_10025750(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1002575b at 1002575b

void Unwind_1002575b(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@10025790 at 10025790

void Unwind_10025790(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@100257a1 at 100257a1

void Unwind_100257a1(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@100257d0 at 100257d0

void Unwind_100257d0(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100257d8 at 100257d8

void Unwind_100257d8(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100257e0 at 100257e0

void Unwind_100257e0(void)

{
  int unaff_EBP;
  
  FUN_10018f40((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10025810 at 10025810

void Unwind_10025810(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002581b at 1002581b

void Unwind_1002581b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10025826 at 10025826

void Unwind_10025826(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001a290((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10025850 at 10025850

void Unwind_10025850(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@1002585e at 1002585e

void Unwind_1002585e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2b0));
  return;
}



// Function: Unwind@10025869 at 10025869

void Unwind_10025869(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@10025874 at 10025874

void Unwind_10025874(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@10025882 at 10025882

void Unwind_10025882(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2b0));
  return;
}



// Function: Unwind@1002588d at 1002588d

void Unwind_1002588d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@10025898 at 10025898

void Unwind_10025898(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@100258a3 at 100258a3

void Unwind_100258a3(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x2c0));
  return;
}



// Function: Unwind@100258ae at 100258ae

void Unwind_100258ae(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x268));
  return;
}



// Function: Unwind@100258b9 at 100258b9

void Unwind_100258b9(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x230));
  return;
}



// Function: Unwind@100258c4 at 100258c4

void Unwind_100258c4(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@100258cf at 100258cf

void Unwind_100258cf(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@100258da at 100258da

void Unwind_100258da(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@100258e5 at 100258e5

void Unwind_100258e5(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x2b0));
  return;
}



// Function: Unwind@100258f0 at 100258f0

void Unwind_100258f0(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@100258fb at 100258fb

void Unwind_100258fb(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10025930 at 10025930

void Unwind_10025930(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x210));
  return;
}



// Function: Unwind@1002593e at 1002593e

void Unwind_1002593e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10025949 at 10025949

void Unwind_10025949(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x210));
  return;
}



// Function: Unwind@10025954 at 10025954

void Unwind_10025954(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x210));
  return;
}



// Function: Unwind@10025962 at 10025962

void Unwind_10025962(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1002596d at 1002596d

void Unwind_1002596d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x210));
  return;
}



// Function: Unwind@10025978 at 10025978

void Unwind_10025978(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025980 at 10025980

void Unwind_10025980(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025988 at 10025988

void Unwind_10025988(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10025993 at 10025993

void Unwind_10025993(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1002599e at 1002599e

void Unwind_1002599e(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -0x20c));
  return;
}



// Function: Unwind@100259a9 at 100259a9

void Unwind_100259a9(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@100259e0 at 100259e0

void Unwind_100259e0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100259eb at 100259eb

void Unwind_100259eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100259f3 at 100259f3

void Unwind_100259f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100259fb at 100259fb

void Unwind_100259fb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10025a06 at 10025a06

void Unwind_10025a06(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10025a0e at 10025a0e

void Unwind_10025a0e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10025a16 at 10025a16

void Unwind_10025a16(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025a40 at 10025a40

void Unwind_10025a40(void)

{
  FUN_100054c0();
  return;
}



// Function: Unwind@10025a70 at 10025a70

void Unwind_10025a70(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@10025ad0 at 10025ad0

void Unwind_10025ad0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10025ade at 10025ade

void Unwind_10025ade(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@10025ae9 at 10025ae9

void Unwind_10025ae9(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10025af4 at 10025af4

void Unwind_10025af4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10025b02 at 10025b02

void Unwind_10025b02(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@10025b0d at 10025b0d

void Unwind_10025b0d(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10025b18 at 10025b18

void Unwind_10025b18(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025b20 at 10025b20

void Unwind_10025b20(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025b28 at 10025b28

void Unwind_10025b28(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -0x164));
  return;
}



// Function: Unwind@10025b33 at 10025b33

void Unwind_10025b33(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10025b3b at 10025b3b

void Unwind_10025b3b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10025b46 at 10025b46

void Unwind_10025b46(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x19c));
  return;
}



// Function: Unwind@10025b80 at 10025b80

void Unwind_10025b80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025b8b at 10025b8b

void Unwind_10025b8b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025b93 at 10025b93

void Unwind_10025b93(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025b9b at 10025b9b

void Unwind_10025b9b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025ba6 at 10025ba6

void Unwind_10025ba6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025bae at 10025bae

void Unwind_10025bae(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025bb6 at 10025bb6

void Unwind_10025bb6(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025bbe at 10025bbe

void Unwind_10025bbe(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025bc6 at 10025bc6

void Unwind_10025bc6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025bce at 10025bce

void Unwind_10025bce(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025bd6 at 10025bd6

void Unwind_10025bd6(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10025bde at 10025bde

void Unwind_10025bde(void)

{
  int unaff_EBP;
  
  FUN_100027c0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025be6 at 10025be6

void Unwind_10025be6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10025c20 at 10025c20

void Unwind_10025c20(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(unaff_EBP + -0x5ac),0x10,0x19,FUN_1000b0e0);
  return;
}



// Function: Unwind@10025c36 at 10025c36

void Unwind_10025c36(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x898));
  return;
}



// Function: Unwind@10025c44 at 10025c44

void Unwind_10025c44(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x894));
  return;
}



// Function: Unwind@10025c4f at 10025c4f

void Unwind_10025c4f(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x898));
  return;
}



// Function: Unwind@10025c5a at 10025c5a

void Unwind_10025c5a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x894));
  return;
}



// Function: Unwind@10025c68 at 10025c68

void Unwind_10025c68(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x898));
  return;
}



// Function: Unwind@10025c73 at 10025c73

void Unwind_10025c73(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x894));
  return;
}



// Function: Unwind@10025c7e at 10025c7e

void Unwind_10025c7e(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x638));
  return;
}



// Function: Unwind@10025c89 at 10025c89

void Unwind_10025c89(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x61c));
  return;
}



// Function: Unwind@10025c94 at 10025c94

void Unwind_10025c94(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x5e4));
  return;
}



// Function: Unwind@10025c9f at 10025c9f

void Unwind_10025c9f(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x5c8));
  return;
}



// Function: Unwind@10025caa at 10025caa

void Unwind_10025caa(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x600));
  return;
}



// Function: Unwind@10025cb5 at 10025cb5

void Unwind_10025cb5(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x8b0));
  return;
}



// Function: Unwind@10025cc0 at 10025cc0

void Unwind_10025cc0(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x8c0));
  return;
}



// Function: Unwind@10025ccb at 10025ccb

void Unwind_10025ccb(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x600));
  return;
}



// Function: Unwind@10025cd6 at 10025cd6

void Unwind_10025cd6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x5bc));
  return;
}



// Function: Unwind@10025d10 at 10025d10

void Unwind_10025d10(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10025d1b at 10025d1b

void Unwind_10025d1b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10025d23 at 10025d23

void Unwind_10025d23(void)

{
  int unaff_EBP;
  
  FUN_1001a600(unaff_EBP + -0x88);
  return;
}



// Function: Unwind@10025d2e at 10025d2e

void Unwind_10025d2e(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001a290((_Container_base0 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10025d70 at 10025d70

void Unwind_10025d70(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001a290((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10025da0 at 10025da0

void Unwind_10025da0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10025dab at 10025dab

void Unwind_10025dab(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10025db3 at 10025db3

void Unwind_10025db3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10025dbb at 10025dbb

void Unwind_10025dbb(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025de0 at 10025de0

void Unwind_10025de0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10025deb at 10025deb

void Unwind_10025deb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10025df3 at 10025df3

void Unwind_10025df3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10025dfb at 10025dfb

void Unwind_10025dfb(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025e03 at 10025e03

void Unwind_10025e03(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10025e30 at 10025e30

void Unwind_10025e30(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10025e3b at 10025e3b

void Unwind_10025e3b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10025e43 at 10025e43

void Unwind_10025e43(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10025e4b at 10025e4b

void Unwind_10025e4b(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025e53 at 10025e53

void Unwind_10025e53(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025e80 at 10025e80

void Unwind_10025e80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025e8e at 10025e8e

void Unwind_10025e8e(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x19c));
  return;
}



// Function: Unwind@10025e99 at 10025e99

void Unwind_10025e99(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025ea4 at 10025ea4

void Unwind_10025ea4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025eb2 at 10025eb2

void Unwind_10025eb2(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x19c));
  return;
}



// Function: Unwind@10025ebd at 10025ebd

void Unwind_10025ebd(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025ec8 at 10025ec8

void Unwind_10025ec8(void)

{
  int unaff_EBP;
  
  FUN_1000b0e0((_Container_base0 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@10025ed3 at 10025ed3

void Unwind_10025ed3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025ee1 at 10025ee1

void Unwind_10025ee1(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x19c));
  return;
}



// Function: Unwind@10025eec at 10025eec

void Unwind_10025eec(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1a0));
  return;
}



// Function: Unwind@10025efa at 10025efa

void Unwind_10025efa(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@10025f05 at 10025f05

void Unwind_10025f05(void)

{
  int unaff_EBP;
  
  thunk_FUN_1001a290((_Container_base0 *)(unaff_EBP + -0x198));
  return;
}



// Function: Unwind@10025f10 at 10025f10

void Unwind_10025f10(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025f18 at 10025f18

void Unwind_10025f18(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025f20 at 10025f20

void Unwind_10025f20(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10025f28 at 10025f28

void Unwind_10025f28(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025f30 at 10025f30

void Unwind_10025f30(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025f38 at 10025f38

void Unwind_10025f38(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1a0));
  return;
}



// Function: Unwind@10025f46 at 10025f46

void Unwind_10025f46(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x19c));
  return;
}



// Function: Unwind@10025f51 at 10025f51

void Unwind_10025f51(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x1a0));
  return;
}



// Function: Unwind@10025f5c at 10025f5c

void Unwind_10025f5c(void)

{
  int unaff_EBP;
  
  FUN_10005b80((undefined4 *)(unaff_EBP + -0x180));
  return;
}



// Function: Unwind@10025f67 at 10025f67

void Unwind_10025f67(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10025f72 at 10025f72

void Unwind_10025f72(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10025f7d at 10025f7d

void Unwind_10025f7d(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10025f85 at 10025f85

void Unwind_10025f85(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10025f8d at 10025f8d

void Unwind_10025f8d(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10025f98 at 10025f98

void Unwind_10025f98(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1d4));
  return;
}



// Function: Unwind@10025fd0 at 10025fd0

void Unwind_10025fd0(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10025fd8 at 10025fd8

void Unwind_10025fd8(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10025fe0 at 10025fe0

void Unwind_10025fe0(void)

{
  int unaff_EBP;
  
  FUN_100027c0((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10026010 at 10026010

void Unwind_10026010(void)

{
  int unaff_EBP;
  
  FUN_10016ff0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10026040 at 10026040

void Unwind_10026040(void)

{
  int unaff_EBP;
  
  FUN_10001c00((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1002604b at 1002604b

void Unwind_1002604b(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10026056 at 10026056

void Unwind_10026056(void)

{
  int unaff_EBP;
  
  FUN_1001fbf0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10026061 at 10026061

void Unwind_10026061(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@1002606c at 1002606c

void Unwind_1002606c(void)

{
  int unaff_EBP;
  
  FUN_1001fbf0((int *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@10026077 at 10026077

void Unwind_10026077(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@10026082 at 10026082

void Unwind_10026082(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@100260c0 at 100260c0

void Unwind_100260c0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100260f0 at 100260f0

void Unwind_100260f0(void)

{
  int unaff_EBP;
  
  FUN_10001c00((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10026120 at 10026120

void Unwind_10026120(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10026150 at 10026150

void Unwind_10026150(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002615b at 1002615b

void Unwind_1002615b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10002ed0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10026190 at 10026190

void Unwind_10026190(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100261c0 at 100261c0

void Unwind_100261c0(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@100261cb at 100261cb

void Unwind_100261cb(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@100261d6 at 100261d6

void Unwind_100261d6(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@100261e1 at 100261e1

void Unwind_100261e1(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@100261ec at 100261ec

void Unwind_100261ec(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@100261f7 at 100261f7

void Unwind_100261f7(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@10026202 at 10026202

void Unwind_10026202(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@1002620d at 1002620d

void Unwind_1002620d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1002621b at 1002621b

void Unwind_1002621b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2054));
  return;
}



// Function: Unwind@10026226 at 10026226

void Unwind_10026226(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x2054));
  return;
}



// Function: Unwind@10026234 at 10026234

void Unwind_10026234(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x2058));
  return;
}



// Function: Unwind@1002623f at 1002623f

void Unwind_1002623f(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@1002624a at 1002624a

void Unwind_1002624a(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@10026255 at 10026255

void Unwind_10026255(void)

{
  int unaff_EBP;
  
  FUN_10016ff0(*(int **)(unaff_EBP + -0x2058));
  return;
}



// Function: Unwind@10026260 at 10026260

void Unwind_10026260(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1002626b at 1002626b

void Unwind_1002626b(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@100262a0 at 100262a0

void Unwind_100262a0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100262a8 at 100262a8

void Unwind_100262a8(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100262b0 at 100262b0

void Unwind_100262b0(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100262b8 at 100262b8

void Unwind_100262b8(void)

{
  int unaff_EBP;
  
  FUN_10016ff0(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262c0 at 100262c0

void Unwind_100262c0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262cb at 100262cb

void Unwind_100262cb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262d3 at 100262d3

void Unwind_100262d3(void)

{
  int unaff_EBP;
  
  FUN_10016ff0(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262db at 100262db

void Unwind_100262db(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100262e3 at 100262e3

void Unwind_100262e3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262eb at 100262eb

void Unwind_100262eb(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(undefined4 **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100262f3 at 100262f3

void Unwind_100262f3(void)

{
  int unaff_EBP;
  
  FUN_10002ed0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10026320 at 10026320

void Unwind_10026320(void)

{
  int unaff_EBP;
  
  FUN_10001180((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10026328 at 10026328

void Unwind_10026328(void)

{
  int unaff_EBP;
  
  FUN_10016ff0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: FUN_100267f0 at 100267f0

void FUN_100267f0(void)

{
  FUN_100017b0(0x1003afa8);
  return;
}



// Function: FUN_10026800 at 10026800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10026800(void)

{
  if (7 < DAT_1003ad7c) {
    operator_delete(DAT_1003ad68);
  }
  DAT_1003ad7c = 7;
  _DAT_1003ad78 = 0;
  DAT_1003ad68 = (void *)((uint)DAT_1003ad68 & 0xffff0000);
  return;
}



// Function: FUN_10026840 at 10026840

void FUN_10026840(void)

{
  if (7 < DAT_1003ad98) {
    operator_delete(DAT_1003ad84);
  }
  DAT_1003ad98 = 7;
  DAT_1003ad94 = 0;
  DAT_1003ad84 = (void *)((uint)DAT_1003ad84 & 0xffff0000);
  return;
}



// Function: FUN_10026880 at 10026880

void FUN_10026880(void)

{
  Ordinal_9(&DAT_1003af30);
  return;
}



// Function: FUN_10026890 at 10026890

void FUN_10026890(void)

{
  Ordinal_6(DAT_1003b04c);
  return;
}



// Function: FUN_100268a0 at 100268a0

void FUN_100268a0(void)

{
  Ordinal_6(DAT_1003b044);
  return;
}



// Function: FUN_100268b0 at 100268b0

void FUN_100268b0(void)

{
  Ordinal_6(DAT_1003b048);
  return;
}



// Function: FUN_100268bd at 100268bd

void FUN_100268bd(void)

{
  FUN_10021620((int *)&DAT_1003b050);
  return;
}



// Function: FUN_100268c7 at 100268c7

void FUN_100268c7(void)

{
  FUN_10021702(0x1003b078);
  return;
}



// Function: FUN_100268e0 at 100268e0

void FUN_100268e0(void)

{
  Ordinal_9(&DAT_1003af30);
  return;
}



// Function: FUN_10027000 at 10027000

undefined4 FUN_10027000(byte *param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  int local_28;
  int local_20;
  int local_18;
  int local_10;
  int local_8;
  
  local_8 = -1;
  iVar1 = 0x10;
  bVar4 = false;
  bVar5 = true;
  local_10 = 0;
  pbVar2 = param_1;
  pbVar3 = PTR_DAT_1003aba8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar5) {
    local_10 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  }
  if (local_10 < 1) {
    if (local_10 == 0) {
      local_8 = 4;
      goto LAB_1002713d;
    }
  }
  else {
    local_8 = 1;
  }
  iVar1 = 0x10;
  bVar4 = false;
  bVar5 = true;
  local_18 = 0;
  pbVar2 = param_1;
  pbVar3 = *(byte **)((&PTR_PTR_1002e25c)[local_8] + 4);
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar5) {
    local_18 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  }
  if ((local_18 < 0) || (local_8 = local_8 + 2, local_18 != 0)) {
    iVar1 = 0x10;
    bVar4 = false;
    bVar5 = true;
    local_20 = 0;
    pbVar2 = param_1;
    pbVar3 = *(byte **)((&PTR_PTR_1002e258)[local_8] + 4);
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pbVar2 < *pbVar3;
      bVar5 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    if (!bVar5) {
      local_20 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
    }
    if ((local_20 < 0) || (local_8 = local_8 + 1, local_20 != 0)) {
      local_8 = local_8 + 1;
      if (local_8 < 5) {
        iVar1 = 0x10;
        bVar4 = false;
        bVar5 = true;
        local_28 = 0;
        pbVar2 = *(byte **)((&PTR_PTR_1002e254)[local_8] + 4);
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *param_1 < *pbVar2;
          bVar5 = *param_1 == *pbVar2;
          param_1 = param_1 + 1;
          pbVar2 = pbVar2 + 1;
        } while (bVar5);
        if (!bVar5) {
          local_28 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
        }
        if (local_28 == 0) goto LAB_1002713d;
      }
      return 0;
    }
  }
LAB_1002713d:
  *param_2 = local_8;
  return 1;
}



