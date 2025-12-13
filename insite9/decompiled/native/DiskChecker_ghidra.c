/*
 * Decompiled from: DiskChecker.dll
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

undefined4 * __fastcall FUN_10001070(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d558;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000b910((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CILDiskChecker>::vftable;
  param_1[1] = ATL::CComObject<class_CILDiskChecker>::vftable;
  (**(code **)(*DAT_10015ba8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100010e0 at 100010e0

undefined4 FUN_100010e0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10001100 at 10001100

undefined2 __fastcall FUN_10001100(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_100104b0 + (uVar1 & 0xffff) * 2);
}



// Function: FUN_10001120 at 10001120

bool __cdecl FUN_10001120(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10001150 at 10001150

void __fastcall FUN_10001150(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d3e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000b890(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100011a0 at 100011a0

void FUN_100011a0(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10011b14);
}



// Function: FUN_100011c0 at 100011c0

void __cdecl FUN_100011c0(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
}



// Function: FUN_10001280 at 10001280

void __cdecl FUN_10001280(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
}



// Function: FUN_10001330 at 10001330

void __cdecl FUN_10001330(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
}



// Function: FUN_100013f0 at 100013f0

void __cdecl FUN_100013f0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
}



// Function: FUN_100014a0 at 100014a0

uint __fastcall FUN_100014a0(LPCRITICAL_SECTION param_1)

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



// Function: FUN_100014d0 at 100014d0

void __fastcall FUN_100014d0(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100014f0 at 100014f0

DWORD FUN_100014f0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001510 at 10001510

uint __cdecl FUN_10001510(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10001530 at 10001530

void __fastcall FUN_10001530(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001540 at 10001540

int __thiscall
FUN_10001540(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,LPWSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x100015a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegCreateKeyExW(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedW");
      if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
        iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                          *this,0);
        return iVar2;
      }
    }
  }
  return 1;
}



// Function: FUN_100015c0 at 100015c0

int __thiscall FUN_100015c0(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x1000160a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
      if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
        iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
        return iVar2;
      }
    }
  }
  return 1;
}



// Function: FUN_10001620 at 10001620

undefined4 FUN_10001620(int *param_1)

{
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    return 1;
  }
  return 0;
}



// Function: FUN_10001660 at 10001660

undefined4 __fastcall FUN_10001660(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001670 at 10001670

void __cdecl FUN_10001670(short *param_1,int param_2,short *param_3)

{
  uint uVar1;
  short *psVar2;
  
  if (param_2 != 0) {
    uVar1 = 0;
    psVar2 = param_1;
    if (param_2 != 1) {
      do {
        psVar2 = param_1;
        if (*param_3 == 0) break;
        *param_1 = *param_3;
        psVar2 = param_1 + 1;
        if ((*param_3 == 0x27) && (uVar1 = uVar1 + 1, uVar1 < param_2 - 1U)) {
          *psVar2 = 0x27;
          psVar2 = param_1 + 2;
        }
        uVar1 = uVar1 + 1;
        param_3 = param_3 + 1;
        param_1 = psVar2;
      } while (uVar1 < param_2 - 1U);
    }
    *psVar2 = 0;
  }
  return;
}



// Function: FUN_100016d0 at 100016d0

void __thiscall FUN_100016d0(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    FUN_100015c0(*(void **)((int)this + 8),*this,param_1);
    return;
  }
  if (DAT_10015bc4 == '\0') {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_10015bc0 = GetProcAddress(hModule,"RegDeleteKeyExW");
    }
    DAT_10015bc4 = '\x01';
  }
  if (DAT_10015bc0 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
    (*DAT_10015bc0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    return;
  }
                    /* WARNING: Load size is inaccurate */
  RegDeleteKeyW(*this,param_1);
  return;
}



// Function: FUN_10001750 at 10001750

void __fastcall FUN_10001750(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    return;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10001780 at 10001780

void __thiscall
FUN_10001780(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
            LPSECURITY_ATTRIBUTES param_6,undefined4 *param_7)

{
  int iVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(void **)((int)this + 8) == (void *)0x0) {
    iVar1 = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,
                            (LPDWORD)&param_6);
  }
  else {
    iVar1 = FUN_10001540(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,param_6
                         ,&local_8,(LPDWORD)&param_6);
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_6;
  }
  if (iVar1 == 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this != (HKEY)0x0) {
      RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_5 & 0x300;
  }
  return;
}



// Function: FUN_10001820 at 10001820

void __thiscall FUN_10001820(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_1000188a:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_1000188a;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_1000189f;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_1000189f;
      }
    }
    iVar2 = 1;
  }
LAB_1000189f:
  if (iVar2 == 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this != (HKEY)0x0) {
      RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_3 & 0x300;
  }
  return;
}



// Function: FUN_100018d0 at 100018d0

LSTATUS __thiscall FUN_100018d0(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  LPDWORD lpcbData;
  LSTATUS LVar1;
  uint uVar2;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
  }
                    /* WARNING: Load size is inaccurate */
  param_3 = (LPDWORD)0x0;
  LVar1 = RegQueryValueExW(*this,param_2,(LPDWORD)0x0,(LPDWORD)&param_3,param_1,lpcbData);
  if (param_1 == (LPBYTE)0x0) {
    return LVar1;
  }
  uVar2 = *lpcbData;
  if (uVar2 == 0) {
LAB_10001946:
    param_1[0] = '\0';
    param_1[1] = '\0';
    return LVar1;
  }
  if (param_3 != (LPDWORD)0x0) {
    if (param_3 < (LPDWORD)0x3) {
      if (((uVar2 & 1) == 0) && (*(short *)(param_1 + ((uVar2 & 0xfffffffe) - 2)) == 0)) {
        return LVar1;
      }
      param_1[0] = '\0';
      param_1[1] = '\0';
      return 0xd;
    }
    if (param_3 == (LPDWORD)0x7) {
      if ((((uVar2 & 1) == 0) && (uVar2 = uVar2 >> 1, uVar2 != 0)) &&
         (*(short *)(param_1 + uVar2 * 2 + -2) == 0)) {
        if (uVar2 < 2) {
          return LVar1;
        }
        if (*(short *)(param_1 + uVar2 * 2 + -4) == 0) {
          return LVar1;
        }
      }
      LVar1 = 0xd;
      goto LAB_10001946;
    }
  }
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: FUN_10001980 at 10001980

LSTATUS __thiscall FUN_10001980(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  uint uVar1;
  LPBYTE pBVar2;
  uint *puVar3;
  LSTATUS LVar4;
  
  puVar3 = param_3;
  pBVar2 = param_2;
  uVar1 = *param_3;
  *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
  param_3 = (uint *)(uVar1 * 2);
  LVar4 = RegQueryValueExW(*this,param_1,(LPDWORD)0x0,(LPDWORD)&param_2,param_2,(LPDWORD)&param_3);
  if (LVar4 == 0) {
    if ((param_2 != (LPBYTE)0x1) && (param_2 != (LPBYTE)0x2)) {
      return 0xd;
    }
    if (pBVar2 != (LPBYTE)0x0) {
      if (param_3 == (uint *)0x0) {
        pBVar2[0] = '\0';
        pBVar2[1] = '\0';
      }
      else {
        if (((uint)param_3 & 1) != 0) {
          return 0xd;
        }
        if (*(short *)(pBVar2 + (((uint)param_3 & 0xfffffffe) - 2)) != 0) {
          return 0xd;
        }
      }
    }
    *puVar3 = (uint)param_3 >> 1;
    LVar4 = 0;
  }
  return LVar4;
}



// Function: FUN_10001a00 at 10001a00

void __thiscall FUN_10001a00(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExW(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_10001a20 at 10001a20

LSTATUS __thiscall FUN_10001a20(void *this,LPCWSTR param_1,LPCWSTR param_2,DWORD param_3)

{
  int iVar1;
  LSTATUS LVar2;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0xd;
  }
  iVar1 = lstrlenW(param_2);
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegSetValueExW(*this,param_1,0,param_3,(BYTE *)param_2,iVar1 * 2 + 2);
  return LVar2;
}



// Function: FUN_10001a60 at 10001a60

LSTATUS __thiscall FUN_10001a60(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  int iVar1;
  LSTATUS LVar2;
  LPCWSTR lpString;
  DWORD cbData;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0xd;
  }
  cbData = 0;
  lpString = param_2;
  do {
    iVar1 = lstrlenW(lpString);
    iVar1 = iVar1 + 1;
    lpString = lpString + iVar1;
    cbData = cbData + iVar1 * 2;
  } while (iVar1 != 1);
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegSetValueExW(*this,param_1,0,7,(BYTE *)param_2,cbData);
  return LVar2;
}



// Function: FUN_10001ac0 at 10001ac0

undefined4 __fastcall FUN_10001ac0(undefined4 *param_1)

{
  LPWSTR pWVar1;
  
  if (*(LPCWSTR)*param_1 == L'\'') {
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    if (*pWVar1 != L'\'') {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10001af0 at 10001af0

void __fastcall FUN_10001af0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10001b00 at 10001b00

undefined4 __thiscall FUN_10001b00(void *this,void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LPVOID pvVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
  if ((*this < iVar1) && (param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      do {
        iVar2 = *(int *)((int)this + 4);
        if (0x3fffffff < iVar2) {
          return 0;
        }
        iVar3 = iVar2 * 2;
        *(int *)((int)this + 4) = iVar3;
      } while (iVar3 <= iVar1);
      if (iVar3 < 0) {
        return 0;
      }
      pvVar4 = CoTaskMemRealloc(*(LPVOID *)((int)this + 8),iVar2 * 4);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100011c0((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
                   param_2 * 2);
                    /* WARNING: Load size is inaccurate */
      *(int *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*(int *)((int)this + 8) + *this * 2) = 0;
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10001bb0 at 10001bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001bb0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d41e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_10015be8 & 1) == 0) {
    DAT_10015be8 = DAT_10015be8 | 1;
    DAT_10015bcc = 8;
    DAT_10015bc8 = &DAT_100103c4;
    DAT_10015bd0 = &DAT_100103c0;
    _DAT_10015bd4 = 0x4008;
    _DAT_10015bd8 = &DAT_100103bc;
    _DAT_10015bdc = 0x13;
    _DAT_10015be0 = &DAT_100103b8;
    _DAT_10015be4 = 0x11;
  }
  local_8 = 0xffffffff;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_10015bc8)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_10015bcc)[uVar2 * 4];
      ExceptionList = local_10;
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10001ca0 at 10001ca0

uint __cdecl FUN_10001ca0(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  uVar1 = uVar2 - 0x30;
  switch(uVar2) {
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
    goto switchD_10001cb6_caseD_30;
  default:
    uVar1 = uVar1 & 0xffffff00;
switchD_10001cb6_caseD_30:
    return uVar1;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
    return uVar2 - 0x37;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    return uVar2 - 0x57;
  }
}



// Function: FUN_10001d20 at 10001d20

LPCWSTR __cdecl FUN_10001d20(LPCWSTR param_1,WCHAR param_2)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  
  if (param_1 == (LPCWSTR)0x0) {
    return param_1;
  }
  WVar1 = *param_1;
  pWVar2 = (LPCWSTR)0x0;
  if (WVar1 != L'\0') {
    while (pWVar2 = param_1, WVar1 != param_2) {
      param_1 = CharNextW(param_1);
      WVar1 = *param_1;
      if (WVar1 == L'\0') {
        return (LPCWSTR)0x0;
      }
    }
  }
  return pWVar2;
}



// Function: FUN_10001d70 at 10001d70

void __fastcall FUN_10001d70(undefined4 *param_1)

{
  LPWSTR pWVar1;
  
  do {
    switch(*(LPCWSTR)*param_1) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      pWVar1 = CharNextW((LPCWSTR)*param_1);
      *param_1 = pWVar1;
      break;
    default:
      return;
    }
  } while( true );
}



// Function: FUN_10001dd0 at 10001dd0

undefined4 __thiscall FUN_10001dd0(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  LPWSTR pWVar3;
  short *psVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  code *pcVar8;
  int iVar9;
  
  FUN_10001d70((undefined4 *)this);
  pcVar8 = CharNextW_exref;
                    /* WARNING: Load size is inaccurate */
  WVar1 = **this;
  if (WVar1 == L'\0') {
    return 0x80020009;
  }
  puVar7 = param_1;
  if (WVar1 == L'\'') {
    pWVar3 = CharNextW(*this);
    *(LPWSTR *)this = pWVar3;
    WVar1 = *pWVar3;
    while( true ) {
                    /* WARNING: Load size is inaccurate */
      if ((WVar1 == L'\0') ||
         ((**this == 0x27 && (psVar4 = (short *)(*pcVar8)(*this), *psVar4 != 0x27)))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == 0) {
          return 0x80020009;
        }
        *puVar7 = 0;
                    /* WARNING: Load size is inaccurate */
        uVar5 = (*pcVar8)(*this);
        *(undefined4 *)this = uVar5;
        return 0;
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == 0x27) {
        uVar5 = (*pcVar8)(*this);
        *(undefined4 *)this = uVar5;
      }
                    /* WARNING: Load size is inaccurate */
      pWVar2 = *this;
      pWVar3 = CharNextW(pWVar2);
      *(LPWSTR *)this = pWVar3;
      iVar6 = (int)pWVar3 - (int)pWVar2 >> 1;
      if (param_1 + 0x1000 <= puVar7 + iVar6 + 1) break;
      if (0 < iVar6) {
        iVar9 = (int)pWVar2 - (int)puVar7;
        do {
          *puVar7 = *(undefined2 *)(iVar9 + (int)puVar7);
          puVar7 = puVar7 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
                    /* WARNING: Load size is inaccurate */
      WVar1 = **this;
      pcVar8 = CharNextW_exref;
    }
    return 0x80020009;
  }
  do {
                    /* WARNING: Load size is inaccurate */
    pWVar2 = *this;
    switch(*pWVar2) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      goto switchD_10001ec4_caseD_9;
    }
    pWVar3 = CharNextW(pWVar2);
    *(LPWSTR *)this = pWVar3;
    iVar6 = (int)pWVar3 - (int)pWVar2 >> 1;
    if (param_1 + 0x1000 <= puVar7 + iVar6 + 1) {
      return 0x80020009;
    }
    if (0 < iVar6) {
      iVar9 = (int)pWVar2 - (int)puVar7;
      do {
        *puVar7 = *(undefined2 *)(iVar9 + (int)puVar7);
        puVar7 = puVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
                    /* WARNING: Load size is inaccurate */
  } while (**this != 0);
switchD_10001ec4_caseD_9:
  *puVar7 = 0;
  return 0;
}



// Function: FUN_10001f40 at 10001f40

undefined4 FUN_10001f40(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10010510;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10010540);
  return 1;
}



// Function: FUN_10001f80 at 10001f80

bool FUN_10001f80(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 != 0) {
    return false;
  }
  return local_8 != 0;
}



// Function: FUN_10001fd0 at 10001fd0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10001fd0(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10001dd0(this,param_1), -1 < iVar1)) {
    FUN_10001d70((undefined4 *)this);
    iVar1 = FUN_10001dd0(this,local_2008);
    if (-1 < iVar1) {
      FUN_10001dd0(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002040 at 10002040

void FUN_10002040(void)

{
  WCHAR WVar1;
  LPCWSTR in_EAX;
  
  if (in_EAX != (LPCWSTR)0x0) {
    WVar1 = *in_EAX;
    while (WVar1 != L'\0') {
      in_EAX = CharNextW(in_EAX);
      WVar1 = *in_EAX;
    }
    return;
  }
  return;
}



// Function: FUN_10002080 at 10002080

int FUN_10002080(void)

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



// Function: FUN_100020d0 at 100020d0

undefined4 __thiscall FUN_100020d0(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10015bac = *param_3;
    DAT_10015bb0 = param_3[1];
    DAT_10015bb4 = param_3[2];
    DAT_10015bb8 = param_3[3];
  }
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      iVar1 = *param_1;
    }
  }
  piVar2 = DAT_10015ca0;
  if (DAT_10015ca0 < DAT_10015ca4) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_10015ca4);
  }
  return 0;
}



// Function: FUN_10002150 at 10002150

int FUN_10002150(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  if (param_4 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_4 = 0;
  iVar2 = FUN_10001620(param_3);
  if (iVar2 != 0) {
    piVar3 = (int *)(param_2[1] + param_1);
    (**(code **)(*piVar3 + 4))(piVar3);
    *param_4 = piVar3;
    return 0;
  }
  pcVar1 = (code *)param_2[2];
  do {
    if (pcVar1 == (code *)0x0) {
      return -0x7fffbffe;
    }
    piVar3 = (int *)*param_2;
    if ((piVar3 == (int *)0x0) ||
       ((((*piVar3 == *param_3 && (piVar3[1] == param_3[1])) && (piVar3[2] == param_3[2])) &&
        (piVar3[3] == param_3[3])))) {
      if (pcVar1 == (code *)0x1) {
        piVar3 = (int *)(param_2[1] + param_1);
        (**(code **)(*piVar3 + 4))(piVar3);
        *param_4 = piVar3;
        return 0;
      }
      iVar2 = (*pcVar1)(param_1,param_3,param_4,param_2[1]);
      if (iVar2 == 0) {
        return 0;
      }
      if ((piVar3 != (int *)0x0) && (iVar2 < 0)) {
        return iVar2;
      }
    }
    pcVar1 = (code *)param_2[5];
    param_2 = param_2 + 3;
  } while( true );
}



// Function: FUN_10002240 at 10002240

void FUN_10002240(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  while (puVar2 != (undefined4 *)0x0) {
    (*(code *)*puVar2)(puVar2[1]);
    puVar1 = (undefined4 *)puVar2[2];
    operator_delete(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_100022b0 at 100022b0

void __fastcall FUN_100022b0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_10002300 at 10002300

void __fastcall FUN_10002300(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d448;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_10015b6c ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002350 at 10002350

void __fastcall FUN_10002350(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d479;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100023a0 at 100023a0

exception * __thiscall FUN_100023a0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d4a9;
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



// Function: FUN_10002400 at 10002400

void __cdecl FUN_10002400(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 * 2);
  return;
}



// Function: FUN_10002420 at 10002420

void __fastcall FUN_10002420(int *param_1)

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



// Function: FUN_10002450 at 10002450

void __fastcall FUN_10002450(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002460 at 10002460

void __fastcall FUN_10002460(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100024b0 at 100024b0

void __fastcall FUN_100024b0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_100024c0 at 100024c0

undefined4 * __fastcall FUN_100024c0(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}



// Function: FUN_100024d0 at 100024d0

void __thiscall FUN_100024d0(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10002500 at 10002500

void FUN_10002500(void)

{
  return;
}



// Function: FUN_10002510 at 10002510

void * __cdecl FUN_10002510(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d509;
  local_10 = ExceptionList;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < (char *)0x80000000) &&
     (pvVar1 = operator_new((int)param_1 * 2), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10011c24);
}



// Function: FUN_100025a0 at 100025a0

exception * __thiscall FUN_100025a0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d4a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10002600 at 10002600

void FUN_10002600(void)

{
  if (DAT_10015c3c != (HMODULE)0x0) {
    FreeLibrary(DAT_10015c3c);
  }
  return;
}



// Function: FUN_10002620 at 10002620

undefined4 __fastcall FUN_10002620(int param_1)

{
  BOOL BVar1;
  
  if ((DAT_10015c3c != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) {
    BVar1 = FreeLibrary(DAT_10015c3c);
    if (BVar1 != 1) {
      return 0x80004005;
    }
  }
  return 0;
}



// Function: FUN_10002650 at 10002650

void FUN_10002650(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10015c70);
    InterlockedExchange(&DAT_10015c3c,param_1);
    DAT_10015c38 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10015c70);
  }
  return;
}



// Function: FUN_10002690 at 10002690

undefined4 FUN_10002690(void)

{
  return DAT_10015c3c;
}



// Function: FUN_100026a0 at 100026a0

uint __thiscall FUN_100026a0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  void *pvVar4;
  ushort *puVar5;
  uint uVar6;
  ushort *puVar7;
  
  uVar6 = *(uint *)((int)this + 0x10);
  if (param_3 == 0) {
    if (param_2 < uVar6) {
      return param_2;
    }
  }
  else {
    if (param_3 <= uVar6) {
      uVar2 = uVar6 - param_3;
      if (param_2 < uVar6 - param_3) {
        uVar2 = param_2;
      }
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      puVar7 = (ushort *)((int)pvVar4 + uVar2 * 2);
      uVar1 = *param_1;
      do {
        if (*puVar7 == uVar1) {
          puVar3 = puVar7;
          puVar5 = param_1;
          uVar6 = param_3;
          if (param_3 == 0) {
LAB_10002724:
            if (*(uint *)((int)this + 0x14) < 8) {
              return (int)puVar7 - (int)this >> 1;
            }
                    /* WARNING: Load size is inaccurate */
            return (int)puVar7 - *this >> 1;
          }
          while (*puVar3 == *puVar5) {
            uVar6 = uVar6 - 1;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
            if (uVar6 == 0) goto LAB_10002724;
          }
          if ((-(uint)(*puVar3 < *puVar5) & 0xfffffffe) == 0xffffffff) goto LAB_10002724;
        }
        puVar3 = (ushort *)FUN_100024c0((undefined4 *)this);
        if (puVar7 == puVar3) break;
        puVar7 = puVar7 + -1;
      } while( true );
    }
    uVar6 = 0xffffffff;
  }
  return uVar6;
}



// Function: FUN_10002780 at 10002780

int FUN_10002780(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d530;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10001070(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_1000282a();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_1000282a();
  return iVar2;
}



// Function: Catch@10002814 at 10002814

undefined * Catch_10002814(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002821;
}



// Function: FUN_1000282a at 1000282a

int FUN_1000282a(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[3] = unaff_ESI[3] + 1;
    unaff_ESI[3] = unaff_ESI[3] + -1;
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI != 0) {
      (**(code **)(*unaff_ESI + 0x40))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10002870 at 10002870

undefined4 FUN_10002870(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: FUN_10002880 at 10002880

int FUN_10002880(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 3;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[3];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x40))(1);
  }
  return iVar2;
}



// Function: FUN_100028b0 at 100028b0

void FUN_100028b0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10002150(param_1,(int *)&PTR_DAT_10010614,param_2,param_3);
  return;
}



// Function: FUN_100028d0 at 100028d0

void FUN_100028d0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_100028f0 at 100028f0

void FUN_100028f0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_10002910 at 10002910

void FUN_10002910(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))(*(undefined4 **)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_10002930 at 10002930

undefined4 * __thiscall FUN_10002930(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d558;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CILDiskChecker>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CILDiskChecker>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0xc) = 0xc0000001;
  (**(code **)(*DAT_10015ba8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000b890((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100029c0 at 100029c0

uint __thiscall FUN_100029c0(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_10002a28:
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
      goto LAB_10002a28;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10002a50 at 10002a50

int __fastcall FUN_10002a50(int param_1)

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
  DAT_10015ba8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_10015b98 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10002ac0 at 10002ac0

void __fastcall FUN_10002ac0(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002240(param_1 + 4);
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



// Function: FUN_10002b10 at 10002b10

void __fastcall FUN_10002b10(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d588;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002240(param_1 + 4);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002b90 at 10002b90

void __fastcall FUN_10002b90(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10002bb0 at 10002bb0

void __thiscall FUN_10002bb0(void *this,LPCWSTR param_1)

{
  int iVar1;
  _FILETIME local_230;
  LPCWSTR local_228;
  DWORD local_224;
  HKEY local_220;
  undefined4 local_21c;
  undefined4 local_218;
  WCHAR local_214 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d5bb;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = param_1;
  local_220 = (HKEY)0x0;
  local_21c = 0;
  local_218 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = FUN_10001820(&local_220,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    local_224 = 0x100;
    iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          &local_230);
    while (iVar1 == 0) {
      iVar1 = FUN_10002bb0(&local_220,local_214);
      if (iVar1 != 0) goto LAB_10002c1f;
      local_224 = 0x100;
      iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
    }
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
    local_21c = 0;
    FUN_100016d0(this,local_228);
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  else {
LAB_10002c1f:
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  local_21c = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002d40 at 10002d40

undefined4 __fastcall FUN_10002d40(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[2]) {
    do {
      if (((iVar3 < 0) || (param_1[2] <= iVar3)) ||
         (operator_delete__(*(void **)(*param_1 + iVar3 * 4)), param_1[2] <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      operator_delete__(*(void **)(param_1[1] + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[2]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return 0;
}



// Function: FUN_10002dd0 at 10002dd0

void __thiscall FUN_10002dd0(void *this,LPCWSTR param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d5f8;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar1 = lstrlenW(param_1);
  FUN_10001b00(this,param_1,iVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002e50 at 10002e50

void FUN_10002e50(int param_1)

{
  FUN_10002d40((int *)(param_1 + 4));
  return;
}



// Function: FUN_10002e70 at 10002e70

void FUN_10002e70(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int local_240;
  WCHAR local_23c [270];
  wchar_t local_20 [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d62b;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000303d;
  *param_3 = 0;
  *param_4 = 0;
  local_240 = 0;
  local_8 = 0;
  DVar3 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar3 == 0) {
    FUN_100014f0();
  }
  else {
    if (DVar3 == 0x104) {
      local_8 = 0xffffffff;
      FUN_10002420(&local_240);
      goto LAB_1000303d;
    }
    pwVar4 = (wchar_t *)FUN_10002040();
    if (param_2 != (LPCWSTR)0x0) {
      uVar5 = lstrlenW(param_2);
      uVar1 = uVar5 + DVar3;
      if (((DVar3 <= uVar1) && (uVar5 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_10001280(local_23c + DVar3,0x10e - DVar3,param_2);
        goto LAB_10002f80;
      }
LAB_1000301f:
      local_8 = 0xffffffff;
      FUN_10002420(&local_240);
      goto LAB_1000303d;
    }
LAB_10002f80:
    iVar6 = Ordinal_161(local_23c,param_4,uVar2);
    if (iVar6 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar6 = (int)pwVar4 - (int)local_23c >> 1;
      if (0x104 < iVar6 + 5U) goto LAB_1000301f;
      FUN_10001280(pwVar4,0x10e - iVar6,local_20);
      iVar6 = Ordinal_161(local_23c,param_4);
      if (iVar6 < 0) goto LAB_10002eef;
    }
    uVar7 = Ordinal_2(local_23c);
    *param_3 = uVar7;
  }
LAB_10002eef:
  local_8 = 0xffffffff;
  FUN_10002420(&local_240);
LAB_1000303d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003060 at 10003060

void __fastcall FUN_10003060(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10015b6c ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100030b0 at 100030b0

void __fastcall FUN_100030b0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x2c);
  if (piVar5 != (int *)0x0) {
    iVar1 = *piVar5;
    while (iVar1 != 0) {
      piVar2 = (int *)piVar5[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar5[4] = 0;
      (*(code *)piVar5[8])(0);
      piVar5 = piVar5 + 9;
      iVar1 = *piVar5;
    }
  }
  piVar5 = DAT_10015ca0;
  if (DAT_10015ca0 < DAT_10015ca4) {
    do {
      if (*piVar5 != 0) {
        (**(code **)(*piVar5 + 0x20))(0);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < DAT_10015ca4);
  }
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if ((undefined4 *)(param_1 + 4) == (undefined4 *)0x0) {
        RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = *(undefined4 **)(param_1 + 0xc);
      while (puVar4 != (undefined4 *)0x0) {
        (*(code *)*puVar4)(puVar4[1]);
        puVar3 = (undefined4 *)puVar4[2];
        operator_delete(puVar4);
        puVar4 = puVar3;
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar5 = *(int **)(param_1 + 0x28);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))(piVar5);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_100031a0 at 100031a0

undefined4 __thiscall FUN_100031a0(void *this,int *param_1)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  uint uStack_38;
  int local_24;
  uint *local_20;
  int *piStack_1c;
  uint *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar4 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d6a3;
  local_10 = ExceptionList;
  uStack_38 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  iVar6 = (**(code **)(*param_1 + 0xc))(param_1,&local_24);
  if (-1 < iVar6) {
    local_18 = (uint *)0x0;
    uVar2 = *(ushort *)(local_24 + 0x2c);
    *(uint *)((int)this + 0x18) = (uint)uVar2;
    *(undefined4 *)((int)this + 0x14) = 0;
    if (uVar2 != 0) {
      local_8 = 0;
      uVar3 = *(uint *)((int)this + 0x18);
      uVar8 = -(uint)((int)((ulonglong)uVar3 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar3 * 0xc);
      local_20 = (uint *)FUN_1000c932(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_100022b0,FUN_10002300);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_10003281();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_10003281();
      return uVar7;
    }
    local_20 = (uint *)0x0;
    if (0 < *(int *)((int)this + 0x18)) {
      piVar9 = (int *)0x0;
      do {
        iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4,local_20,&piStack_1c);
        if (-1 < iVar6) {
          param_1 = (int *)0x0;
          local_8 = 3;
          iVar6 = (**(code **)(*piVar4 + 0x30))(piVar4,*piStack_1c,&param_1,0,0,0);
          piVar5 = param_1;
          if (-1 < iVar6) {
            param_1 = (int *)0x0;
            if ((int *)*piVar9 != piVar5) {
              Ordinal_6((int *)*piVar9);
              *piVar9 = (int)piVar5;
            }
            iVar6 = Ordinal_7(*piVar9);
            piVar9[1] = iVar6;
            piVar9[2] = *piStack_1c;
          }
          (**(code **)(*piVar4 + 0x50))(piVar4,piStack_1c);
          local_8 = 0xffffffff;
          Ordinal_6(param_1);
        }
        local_20 = (uint *)((int)local_20 + 1);
        piVar9 = piVar9 + 3;
      } while ((int)local_20 < *(int *)((int)this + 0x18));
    }
    *(uint **)((int)this + 0x14) = local_18;
    (**(code **)(*piVar4 + 0x4c))(piVar4,local_24);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10003271 at 10003271

undefined * Catch_10003271(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000327e;
}



// Function: FUN_10003281 at 10003281

undefined4 FUN_10003281(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar3;
  
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    (**(code **)(*unaff_EBX + 0x4c))();
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (0 < *(int *)(iVar2 + 0x18)) {
    piVar3 = *(int **)(unaff_EBP + -0x14);
    do {
      iVar1 = (**(code **)(*unaff_EBX + 0x14))();
      if (-1 < iVar1) {
        *(undefined4 *)(unaff_EBP + 8) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        iVar1 = (**(code **)(*unaff_EBX + 0x30))();
        if (-1 < iVar1) {
          iVar2 = *(int *)(unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + 8) = 0;
          if (*piVar3 != iVar2) {
            Ordinal_6(*piVar3);
            *piVar3 = iVar2;
          }
          iVar2 = Ordinal_7(*piVar3);
          piVar3[1] = iVar2;
          piVar3[2] = **(int **)(unaff_EBP + -0x18);
          iVar2 = *(int *)(unaff_EBP + -0x24);
        }
        (**(code **)(*unaff_EBX + 0x50))();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
      }
      iVar1 = *(int *)(unaff_EBP + -0x1c) + 1;
      *(int *)(unaff_EBP + -0x1c) = iVar1;
      piVar3 = piVar3 + 3;
    } while (iVar1 < *(int *)(iVar2 + 0x18));
  }
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EBP + -0x14);
  (**(code **)(*unaff_EBX + 0x4c))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10003390 at 10003390

void FUN_10003390(int param_1)

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
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10002300);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100033f0 at 100033f0

void __fastcall FUN_100033f0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}



// Function: FUN_10003430 at 10003430

undefined4 __thiscall FUN_10003430(void *this,undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)((int)this + 8)) {
                    /* WARNING: Load size is inaccurate */
    while (iVar2 = lstrcmpiW(*(LPCWSTR *)(*this + iVar4 * 4),(LPCWSTR)*param_1), iVar2 != 0) {
      iVar4 = iVar4 + 1;
      if (*(int *)((int)this + 8) <= iVar4) {
        return 0;
      }
    }
    if (iVar4 != -1) {
      if ((-1 < iVar4) && (iVar4 < *(int *)((int)this + 8))) {
        return *(undefined4 *)(*(int *)((int)this + 4) + iVar4 * 4);
      }
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return 0;
}



// Function: FUN_100034a0 at 100034a0

void __fastcall FUN_100034a0(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100034c0 at 100034c0

void __fastcall FUN_100034c0(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100024b0(param_1);
    return;
  }
  return;
}



// Function: FUN_100034d0 at 100034d0

void __fastcall FUN_100034d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d6d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003530 at 10003530

uint __thiscall FUN_10003530(void *this,ushort *param_1,uint param_2,uint param_3)

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
          if (iVar5 == 0) goto LAB_1000358c;
        }
        if (puVar2 == (ushort *)0x0) break;
        puVar6 = puVar2;
        puVar8 = param_1;
        uVar3 = param_3;
        if (param_3 == 0) {
LAB_100035b5:
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
          if (uVar3 == 0) goto LAB_100035b5;
        }
        if ((-(uint)(*puVar6 < *puVar8) & 0xfffffffe) == 0xffffffff) goto LAB_100035b5;
        iVar5 = (int)puVar2 - (int)puVar1;
        puVar1 = puVar2 + 1;
      }
    }
LAB_1000358c:
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_100035f0 at 100035f0

void __fastcall FUN_100035f0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10003610 at 10003610

bool __thiscall FUN_10003610(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d720;
  local_10 = ExceptionList;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (param_1 == (undefined4 *)0x0) {
      return true;
    }
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_18 = (int *)0x0;
    local_14 = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
                    /* WARNING: Load size is inaccurate */
    ExceptionList = &local_10;
    (**(code **)**this)(*this,&DAT_10010958,&local_18,DAT_10015b6c ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&DAT_10010958,&local_14);
    bVar1 = local_18 == local_14;
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    ExceptionList = local_10;
    return bVar1;
  }
  return false;
}



// Function: DllCanUnloadNow at 10003700

HRESULT DllCanUnloadNow(void)

{
                    /* 0x3700  1  DllCanUnloadNow */
  FUN_10002600();
  return (uint)(DAT_10015bf4 != 0);
}



// Function: FUN_10003720 at 10003720

undefined4 * __thiscall FUN_10003720(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d753;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CILDiskChecker>::vftable;
  FUN_1000b910((int)this + 8);
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CILDiskChecker>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CILDiskChecker>::vftable;
  *(undefined4 *)((int)this + 0x14) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_10015ba8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100037b0 at 100037b0

undefined4 FUN_100037b0(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_100037c0 at 100037c0

int FUN_100037c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[1];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return iVar2;
}



// Function: FUN_100037f0 at 100037f0

int FUN_100037f0(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  iVar1 = FUN_10002150((int)(param_1 + 2),(int *)&PTR_DAT_10010614,param_2,param_3);
  return iVar1;
}



// Function: FUN_10003860 at 10003860

undefined4 * __thiscall FUN_10003860(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d783;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CILDiskChecker>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_10015ba8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000b890((int)this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100038f0 at 100038f0

void __fastcall FUN_100038f0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003900 at 10003900

void __fastcall FUN_10003900(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003910 at 10003910

HRESULT __thiscall FUN_10003910(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10011038,(LPUNKNOWN)0x0,1,(IID *)&DAT_100109a8,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_10003970 at 10003970

undefined4 FUN_10003970(void)

{
  return 0x80004005;
}



// Function: FUN_10003980 at 10003980

void FUN_10003980(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_100109b8);
  return;
}



// Function: FUN_100039a0 at 100039a0

undefined4 * __thiscall FUN_100039a0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d7b0;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 4) != 0) {
    if (*(int *)((int)this + 0xc) != 0) {
      FUN_10002240((int)this + 4);
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    piVar1 = *(int **)((int)this + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003a40 at 10003a40

void __fastcall FUN_10003a40(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10002d40(param_1);
  local_8 = 0xffffffff;
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003ac0 at 10003ac0

void __fastcall FUN_10003ac0(undefined4 *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d813;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  piVar1 = param_1 + 1;
  FUN_10002d40(piVar1);
  local_8 = 1;
  FUN_10002d40(piVar1);
  local_8 = 0xffffffff;
  if ((void *)*piVar1 != (void *)0x0) {
    free((void *)*piVar1);
    *piVar1 = 0;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  param_1[3] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003b60 at 10003b60

undefined4 FUN_10003b60(void)

{
  return 0x80004001;
}



// Function: FUN_10003b70 at 10003b70

undefined4 FUN_10003b70(void)

{
  return 1;
}



// Function: FUN_10003b80 at 10003b80

undefined4 FUN_10003b80(void)

{
  return 0;
}



// Function: FUN_10003b90 at 10003b90

undefined4 * __thiscall FUN_10003b90(void *this,byte param_1)

{
  FUN_10003ac0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003bc0 at 10003bc0

void __thiscall FUN_10003bc0(void *this,LPCWSTR param_1,undefined4 *param_2)

{
  WCHAR WVar1;
  undefined2 *puVar2;
  wchar_t *pwVar3;
  LPWSTR pWVar4;
  int iVar5;
  LPCWSTR pWVar6;
  rsize_t rVar7;
  LPCWSTR pWVar8;
  wchar_t *local_78;
  undefined4 *local_74;
  undefined4 local_70;
  int local_6c;
  undefined2 *local_68;
  int local_64;
  char local_5d;
  undefined4 local_5c;
  char local_56;
  char local_55;
  wchar_t local_54 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d838;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = param_2;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    local_6c = lstrlenW(param_1);
    local_6c = local_6c * 2;
    if (local_6c < 100) {
      local_6c = 1000;
    }
    local_70 = 0;
    if (local_6c < 0) {
      local_68 = (undefined2 *)0x0;
    }
    else {
      local_68 = (undefined2 *)CoTaskMemAlloc(local_6c * 2);
    }
    if (local_68 != (undefined2 *)0x0) {
      *local_68 = 0;
    }
    local_8 = 0;
    if (local_68 == (undefined2 *)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5c = 0;
      local_64 = 0;
      local_56 = '\0';
      local_55 = '\0';
      WVar1 = *param_1;
      puVar2 = local_68;
      local_5d = DAT_10015ba4;
      while (WVar1 != L'\0') {
        local_68 = puVar2;
        if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (((local_64 != 0) || (pwVar3 = wcsstr(*this,L"HKCR"), pwVar3 == (wchar_t *)0x0)) ||
             (pwVar3 != *this)) {
LAB_10003cea:
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_55 == '\0') {
                local_55 = '\x01';
                goto LAB_10003d69;
              }
              iVar5 = FUN_10001ac0((undefined4 *)this);
              if (iVar5 == 0) {
                    /* WARNING: Load size is inaccurate */
                pWVar4 = CharNextW(*this);
                *(LPWSTR *)this = pWVar4;
                iVar5 = FUN_10001b00(&local_70,pWVar4,1);
                if (iVar5 == 0) goto LAB_10003e36;
                goto LAB_10003d2d;
              }
              local_55 = '\0';
            }
            else {
LAB_10003d2d:
              if (local_55 != '\0') goto LAB_10003d69;
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x7b) {
              local_64 = local_64 + 1;
            }
            if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
               (local_56 == '\x01')) {
              iVar5 = FUN_10002dd0(&local_70,L"\r\n\t}\r\n}\r\n");
              if (iVar5 == 0) goto LAB_10003e36;
              local_56 = '\0';
            }
            goto LAB_10003d69;
          }
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          iVar5 = FUN_10002dd0(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
          if (iVar5 != 0) {
            local_56 = '\x01';
            goto LAB_10003cea;
          }
LAB_10003e36:
          local_5c = 0x8007000e;
          goto LAB_10003e20;
        }
LAB_10003d69:
                    /* WARNING: Load size is inaccurate */
        pWVar6 = *this;
        if (*pWVar6 == L'%') {
          pWVar6 = CharNextW(pWVar6);
          *(LPCWSTR *)this = pWVar6;
          if (*pWVar6 == L'%') goto LAB_10003ded;
          pWVar6 = FUN_10001d20(pWVar6,L'%');
          if (pWVar6 == (LPCWSTR)0x0) {
LAB_10003e3f:
            local_5c = 0x80020009;
            goto LAB_10003e20;
          }
                    /* WARNING: Load size is inaccurate */
          rVar7 = (int)pWVar6 - (int)*this >> 1;
          if (0x1f < (int)rVar7) {
            local_5c = 0x80004005;
            goto LAB_10003e20;
          }
          FUN_10001330(local_54,0x20,*this,rVar7);
          local_78 = local_54;
          pWVar8 = (LPCWSTR)FUN_10003430((void *)(*(int *)((int)this + 4) + 4),&local_78);
          if (pWVar8 == (LPCWSTR)0x0) goto LAB_10003e3f;
          iVar5 = FUN_10002dd0(&local_70,pWVar8);
          if (iVar5 == 0) goto LAB_10003e36;
                    /* WARNING: Load size is inaccurate */
          pWVar8 = *this;
          while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
            pWVar8 = CharNextW(*this);
            *(LPCWSTR *)this = pWVar8;
          }
        }
        else {
LAB_10003ded:
          iVar5 = FUN_10001b00(&local_70,pWVar6,1);
          if (iVar5 == 0) goto LAB_10003e36;
        }
                    /* WARNING: Load size is inaccurate */
        pWVar4 = CharNextW(*this);
        *(LPWSTR *)this = pWVar4;
        puVar2 = local_68;
        WVar1 = *pWVar4;
      }
      local_68 = (undefined2 *)0x0;
      local_70 = 0;
      local_6c = 0;
      *local_74 = puVar2;
LAB_10003e20:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003e80 at 10003e80

/* WARNING: Removing unreachable block (ram,0x10003edc) */
/* WARNING: Removing unreachable block (ram,0x10003f29) */

void FUN_10003e80(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int iVar3;
  code *pcVar4;
  LSTATUS LVar5;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  HKEY local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  DWORD local_1ac;
  int *local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  OLECHAR local_194 [64];
  wchar_t local_114 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d8ce;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1a8 = (int *)0x0;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
    local_8 = 0xffffffff;
  }
  else if ((((param_1->Data1 == 0) &&
            (iVar3._0_2_ = param_1->Data2, iVar3._2_2_ = param_1->Data3, iVar3 == 0)) &&
           (*(int *)param_1->Data4 == 0)) && (*(int *)(param_1->Data4 + 4) == 0)) {
    local_8 = 0xffffffff;
  }
  else {
    HVar2 = CoCreateInstance((IID *)&DAT_10011048,(LPUNKNOWN)0x0,1,(IID *)&DAT_10010aa4,&local_1a8);
    if (HVar2 < 0) {
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
    else {
      iVar3 = *param_2;
      while (iVar3 != 0) {
        puVar1 = (undefined4 *)param_2[1];
        local_1a4 = *puVar1;
        local_1a0 = puVar1[1];
        local_19c = puVar1[2];
        local_198 = puVar1[3];
        iVar3 = *local_1a8;
        if (param_3 == 0) {
          if (*param_2 == 1) {
            pcVar4 = *(code **)(iVar3 + 0x18);
          }
          else {
            pcVar4 = *(code **)(iVar3 + 0x20);
          }
          (*pcVar4)(local_1a8,param_1,1,&local_1a4);
        }
        else {
          if (*param_2 == 1) {
            pcVar4 = *(code **)(iVar3 + 0x14);
          }
          else {
            pcVar4 = *(code **)(iVar3 + 0x1c);
          }
          iVar3 = (*pcVar4)();
          if (iVar3 < 0) {
            local_8 = 0xffffffff;
            if (local_1a8 != (int *)0x0) {
              (**(code **)(*local_1a8 + 8))(local_1a8);
            }
            goto LAB_100041f0;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_194,0x40);
        local_1c8 = 0;
        local_8._0_1_ = 6;
        FUN_10001280(local_114,0x80,L"CLSID\\");
        FUN_100013f0(local_114,0x80,local_194);
        FUN_100013f0(local_114,0x80,L"\\Required Categories");
        local_1c4 = 0x80000000;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = (HKEY)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8 = CONCAT31(local_8._1_3_,8);
        local_1ac = 0;
        iVar3 = FUN_10001820(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_10001750(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_100016d0(&local_1c4,local_114);
          }
        }
        FUN_10001280(local_114,0x80,L"CLSID\\");
        FUN_100013f0(local_114,0x80,local_194);
        FUN_100013f0(local_114,0x80,L"\\Implemented Categories");
        iVar3 = FUN_10001820(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_10001750(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_100016d0(&local_1c4,local_114);
          }
        }
        local_8._0_1_ = 7;
        FUN_10002b90(&local_1b8);
        local_8._0_1_ = 6;
        FUN_10002b90(&local_1c4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10002420(&local_1c8);
      }
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
  }
LAB_100041f0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004230 at 10004230

int FUN_10004230(HMODULE param_1,LPCWSTR param_2)

{
  uint uVar1;
  int iVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000d920;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar2 = FUN_10002e70(param_1,param_2,&local_18,&local_14);
  if (iVar2 < 0) goto LAB_100042ec;
  iVar2 = (**(code **)(*local_14 + 0x1c))(local_14,&param_2,uVar1);
  if (iVar2 < 0) goto LAB_100042ec;
  if (DAT_10015ba4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_100042be;
    pFVar3 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_100042be;
  }
  else {
LAB_100042be:
    pFVar3 = Ordinal_186_exref;
  }
  iVar2 = (*pFVar3)(param_2,(uint)(ushort)param_2[0xc],(uint)(ushort)param_2[0xd],
                    *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 10));
  (**(code **)(*local_14 + 0x30))(local_14,param_2);
LAB_100042ec:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10004330 at 10004330

void FUN_10004330(HMODULE param_1,LPCWSTR param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  rsize_t rVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  wchar_t *pwVar6;
  undefined4 local_228;
  wchar_t *local_224;
  int *local_220;
  wchar_t local_21c [259];
  undefined2 local_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000d977;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = 0;
  local_220 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_14 = uVar2;
  iVar3 = FUN_10002e70(param_1,param_2,&local_228,&local_220);
  uVar1 = local_228;
  if (iVar3 < 0) goto LAB_1000445f;
  pwVar6 = (wchar_t *)0x0;
  local_224 = (wchar_t *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(*local_220 + 0x24))(local_220,0xffffffff,0,0,0,&local_224,uVar2);
  if ((-1 < iVar3) && (local_224 != (wchar_t *)0x0)) {
    rVar4 = Ordinal_7(local_224);
    FUN_10001330(local_21c,0x104,local_224,rVar4);
    pwVar6 = local_21c;
    local_16 = 0;
    iVar3 = FUN_10002080();
    local_21c[iVar3] = L'\0';
  }
  if (DAT_10015ba4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_1000443c;
    pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar5 == (FARPROC)0x0) goto LAB_1000443c;
  }
  else {
LAB_1000443c:
    pFVar5 = Ordinal_163_exref;
  }
  (*pFVar5)(local_220,uVar1,pwVar6);
  local_8._0_1_ = 2;
  Ordinal_6(local_224);
LAB_1000445f:
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_220 != (int *)0x0) {
    (**(code **)(*local_220 + 8))(local_220);
  }
  local_8 = 0xffffffff;
  Ordinal_6(uVar1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100044b0 at 100044b0

int FUN_100044b0(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
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
        iVar6 = 1;
        iVar5 = (*(code *)puVar1[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)puVar1[7])(1);
        iVar5 = FUN_10003e80((GUID *)*puVar1,piVar3,iVar6);
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
    iVar5 = FUN_10004330(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10004540 at 10004540

int FUN_10004540(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
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
        iVar5 = 0;
        piVar3 = (int *)(*(code *)puVar1[7])();
        iVar5 = FUN_10003e80((GUID *)*puVar1,piVar3,iVar5);
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
    iVar5 = FUN_10004230(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_100045d0 at 100045d0

int FUN_100045d0(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  LPCRITICAL_SECTION local_18;
  undefined1 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar3 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dc08;
  local_10 = ExceptionList;
  uVar4 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  if (param_4 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_4 = 0;
  if (param_1 == (int *)0x0) {
    ExceptionList = pvVar3;
    return -0x7ff8ffa9;
  }
  if (*param_1 == 0) {
    ExceptionList = pvVar3;
    return -0x7fff0001;
  }
  puVar5 = (undefined4 *)param_1[2];
  while( true ) {
    if ((undefined4 *)param_1[3] <= puVar5) {
      ExceptionList = pvVar3;
      return -0x7ffbfeef;
    }
    puVar1 = (undefined4 *)*puVar5;
    if ((((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) &&
        (piVar2 = (int *)*puVar1, *param_2 == *piVar2)) &&
       (((param_2[1] == piVar2[1] && (param_2[2] == piVar2[2])) && (param_2[3] == piVar2[3]))))
    break;
    puVar5 = puVar5 + 1;
  }
  piVar2 = puVar1 + 4;
  iVar6 = 0;
  if (*piVar2 == 0) {
    local_18 = (LPCRITICAL_SECTION)(param_1 + 4);
    local_14 = 0;
    local_8 = 0;
    EnterCriticalSection(local_18);
    local_14 = 1;
    if (*piVar2 == 0) {
      iVar6 = (*(code *)puVar1[2])(puVar1[3],&DAT_10010958,piVar2);
    }
    local_8 = 0xffffffff;
    FUN_100035f0(&local_18);
  }
  if (*piVar2 != 0) {
    iVar6 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,param_3,param_4,uVar4);
  }
  if (*param_4 == 0) {
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return -0x7ffbfeef;
    }
    ExceptionList = local_10;
    return iVar6;
  }
  ExceptionList = local_10;
  return iVar6;
}



// Function: FUN_10004730 at 10004730

undefined4 FUN_10004730(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d9a8;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  local_8 = 0xffffffff;
  uVar1 = FUN_100047ae();
  return uVar1;
}



// Function: Catch@1000479b at 1000479b

undefined * Catch_1000479b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100047a8;
}



// Function: FUN_100047ae at 100047ae

undefined4 FUN_100047ae(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  *unaff_ESI = *(undefined4 *)(unaff_EBP + 0xc);
  unaff_ESI[1] = *(undefined4 *)(unaff_EBP + 0x10);
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EBX + 0xc);
  *(LPCRITICAL_SECTION *)(unaff_EBP + -0x1c) = lpCriticalSection;
  *(undefined1 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(unaff_EBP + -0x18) = 1;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  unaff_ESI[2] = *(undefined4 *)(unaff_EBX + 8);
  *(undefined4 **)(unaff_EBX + 8) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  *(undefined1 *)(unaff_EBP + -0x18) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10004830 at 10004830

void __fastcall FUN_10004830(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d9ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 8) != '\0') {
    *(undefined1 *)(param_1 + 8) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100048a0 at 100048a0

undefined4 FUN_100048a0(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_10004900 at 10004900

undefined4 FUN_10004900(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_10015ba8 + 4))();
    return 0;
  }
  (**(code **)(*DAT_10015ba8 + 8))();
  return 0;
}



// Function: FUN_10004930 at 10004930

undefined4 * __thiscall FUN_10004930(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000da2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100049b0 at 100049b0

undefined4 __thiscall FUN_100049b0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000da83;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar2 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar2 != (void *)0x0) {
    *(void **)this = pvVar2;
    pvVar2 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar2 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar2;
      iVar1 = *(int *)((int)this + 8) * 4;
                    /* WARNING: Load size is inaccurate */
      puVar3 = (undefined4 *)(*this + iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)this + 4) + iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_2;
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10004a90 at 10004a90

int __thiscall FUN_10004a90(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x401) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100024d0(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004ae0 at 10004ae0

int __thiscall FUN_10004ae0(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100024d0(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004b30 at 10004b30

/* WARNING: Removing unreachable block (ram,0x10004b42) */

int __thiscall FUN_10004b30(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100024d0(this,param_1);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004b70 at 10004b70

void __fastcall FUN_10004b70(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10004ba0 at 10004ba0

int * __thiscall FUN_10004ba0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10004c30 at 10004c30

void __thiscall FUN_10004c30(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000daa0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = uVar2 + uVar1, 0x7ffffffe - uVar2 < uVar1)) {
      param_1 = 0x7ffffffe;
    }
  }
  local_8 = 0;
  FUN_10002510((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10004cf0();
  return;
}



// Function: Catch@10004cbe at 10004cbe

undefined * Catch_10004cbe(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10002510((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10004ce7;
}



// Function: FUN_10004cf0 at 10004cf0

void FUN_10004cf0(void)

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



// Function: Catch@10004d51 at 10004d51

void Catch_10004d51(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10004d80 at 10004d80

int __thiscall FUN_10004d80(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = FUN_10003610(this,(undefined4 *)*param_1);
  if (!bVar3) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    *(undefined4 *)this = 0;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_10010b20,this);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004de0 at 10004de0

int * FUN_10004de0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dacb;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x2c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10003720(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10004e96();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10004e96();
  return piVar1;
}



// Function: Catch@10004e81 at 10004e81

undefined * Catch_10004e81(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004e8e;
}



// Function: FUN_10004e96 at 10004e96

int * FUN_10004e96(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)(**(code **)*unaff_ESI)();
    if (unaff_EDI != unaff_EBX) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10004ed0 at 10004ed0

void __fastcall FUN_10004ed0(int param_1)

{
  if (param_1 != 0) {
    FUN_10004730(param_1 + 4);
    return;
  }
  FUN_10004730(0);
  return;
}



// Function: FUN_10004f00 at 10004f00

undefined4 FUN_10004f00(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000db00;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1000c932(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    local_8 = 0xffffffff;
    uVar3 = FUN_10004f96();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10004f84 at 10004f84

undefined * Catch_10004f84(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004f91;
}



// Function: FUN_10004f96 at 10004f96

void FUN_10004f96(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -0x18) = unaff_EBX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x18) = unaff_EDI;
  iVar3 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
  uVar1 = iVar3 * 2 + 2;
  *(uint *)(unaff_EBP + -0x24) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar2 = (ulonglong)uVar1 * 2;
  uVar4 = FUN_1000c932(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10004ffa();
  return;
}



// Function: Catch@10004fe4 at 10004fe4

undefined * Catch_10004fe4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10004ff1;
}



// Function: FUN_10004ffa at 10004ffa

bool FUN_10004ffa(void)

{
  int iVar1;
  void *unaff_EBX;
  int unaff_EBP;
  rsize_t unaff_ESI;
  void *unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(void **)(unaff_EBP + -0x24) = unaff_EBX;
  if ((unaff_EDI != (void *)0x0) && (unaff_EBX != (void *)0x0)) {
    FUN_100011c0(unaff_EDI,*(rsize_t *)(unaff_EBP + -0x28),*(void **)(unaff_EBP + 8),
                 *(rsize_t *)(unaff_EBP + -0x28));
    FUN_100011c0(unaff_EBX,unaff_ESI,*(void **)(unaff_EBP + 0xc),unaff_ESI);
    iVar1 = FUN_100049b0(*(void **)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x1c));
    if (iVar1 != 0) {
      unaff_EBX = (void *)0x0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      goto LAB_10005053;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
LAB_10005053:
  iVar1 = *(int *)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(unaff_EBX);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -1 < iVar1;
}



// Function: FUN_100050b0 at 100050b0

int FUN_100050b0(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000db28;
  local_10 = ExceptionList;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    local_8 = 0;
    ExceptionList = &local_10;
    iVar1 = FUN_10004f00(param_2,param_3);
    ExceptionList = local_10;
    return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_10005140 at 10005140

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_10005140(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_2144;
  uint local_2128;
  void *local_2124;
  uint local_2120 [66];
  WCHAR local_2018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000db71;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2120[0] = 0;
  local_18 = uStack_2144;
  iVar1 = FUN_10001dd0(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10001bb0(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_100054c7;
  FUN_10001d70((undefined4 *)this);
  iVar1 = FUN_10001dd0(this,local_2018);
  if (iVar1 < 0) goto LAB_100054c7;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 < 0x14) {
    if (uVar2 == 0x13) {
      local_2124 = (void *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      uVar2 = FUN_10001a00(param_1,param_2);
      local_8 = 0xffffffff;
      FUN_10002420((int *)&local_2124);
    }
    else {
      if (uVar2 != 8) {
        if (uVar2 == 0x11) {
          local_2128 = lstrlenW(local_2018);
          if ((local_2128 & 1) == 0) {
            local_2120[0] = (int)local_2128 / 2;
            local_2120[1] = 0;
            local_8 = 5;
            FUN_10004b30(local_2120 + 1,local_2120[0]);
            local_8 = 4;
            FUN_1000528c();
            return;
          }
          goto LAB_100054c7;
        }
        goto LAB_100054ab;
      }
      uVar2 = FUN_10001a20(param_1,param_2,local_2018,1);
    }
    if (uVar2 != 0) {
      FUN_10001510(uVar2);
      goto LAB_100054c7;
    }
  }
  else if (uVar2 == 0x4008) {
    iVar1 = lstrlenW(local_2018);
    local_2120[1] = 0;
    local_8 = 1;
    FUN_10004ae0(local_2120 + 1,iVar1 + 2);
    local_8 = 0;
    FUN_10005403();
    return;
  }
LAB_100054ab:
  FUN_10001dd0(this,param_3);
LAB_100054c7:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10005271 at 10005271

undefined * Catch_10005271(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000527e;
}



// Function: FUN_1000528c at 1000528c

void FUN_1000528c(void)

{
  uint uVar1;
  void *pvVar2;
  int unaff_EBX;
  uint unaff_EBP;
  void *unaff_ESI;
  DWORD unaff_EDI;
  byte *pbVar3;
  undefined4 uStack0000000c;
  
  if (*(void **)(unaff_EBP - 0x2118) == unaff_ESI) {
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_100024b0((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),(int)unaff_ESI,unaff_EDI);
    if ((int)unaff_ESI < unaff_EBX) {
      do {
        pbVar3 = (byte *)(((uint)unaff_ESI >> 1) + *(int *)(unaff_EBP - 0x2118));
        uVar1 = FUN_10001ca0(*(ushort *)((unaff_EBP - 0x2014) + (int)unaff_ESI * 2));
        *pbVar3 = *pbVar3 | (char)uVar1 << (((byte)unaff_ESI & 1) * -4 + 4 & 0x1f);
        unaff_ESI = (void *)((int)unaff_ESI + 1);
      } while ((int)unaff_ESI < unaff_EBX);
      unaff_ESI = (void *)0x0;
      unaff_EDI = *(DWORD *)(unaff_EBP - 0x211c);
    }
    pvVar2 = (void *)RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP - 0x2120),
                                    *(LPCWSTR *)(unaff_EBP - 0x212c),(DWORD)unaff_ESI,3,
                                    *(BYTE **)(unaff_EBP - 0x2118),unaff_EDI);
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_100024b0((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (pvVar2 == unaff_ESI) {
      FUN_10001dd0(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_10001510((uint)pvVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100054df;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100053f4 at 100053f4

undefined * Catch_100053f4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005401;
}



// Function: FUN_10005403 at 10005403

void FUN_10005403(void)

{
  WCHAR WVar1;
  LPWSTR lpsz;
  LPCWSTR lpsz_00;
  WCHAR *pWVar2;
  uint unaff_EBP;
  WCHAR *unaff_ESI;
  undefined4 uStack0000000c;
  
  pWVar2 = *(WCHAR **)(unaff_EBP - 0x2118);
  if (pWVar2 == unaff_ESI) {
    pWVar2 = (WCHAR *)0xe;
  }
  else {
    lpsz_00 = (LPCWSTR)(unaff_EBP - 0x2014);
    WVar1 = *(WCHAR *)(unaff_EBP - 0x2014);
    while (WVar1 != L'\0') {
      lpsz = CharNextW(lpsz_00);
      if ((*lpsz_00 == L'\\') && (*lpsz == L'0')) {
        *pWVar2 = L'\0';
        lpsz_00 = CharNextW(lpsz);
      }
      else {
        *pWVar2 = *lpsz_00;
        lpsz_00 = lpsz_00 + 1;
      }
      pWVar2 = pWVar2 + 1;
      WVar1 = *lpsz_00;
    }
    pWVar2[0] = L'\0';
    pWVar2[1] = L'\0';
    pWVar2 = (WCHAR *)FUN_10001a60(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x212c),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_ESI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_100024b0((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_ESI) {
    FUN_10001dd0(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_10001510((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100054df;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100054f0 at 100054f0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100054f0(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  WCHAR WVar1;
  HKEY pHVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  LPCWSTR pWVar6;
  uint uVar7;
  errno_t eVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  HKEY *ppHVar9;
  undefined **ppuVar10;
  HKEY local_226c;
  undefined4 local_2268;
  undefined4 local_2264;
  HKEY local_2260;
  undefined4 local_225c;
  undefined4 local_2258;
  int local_2254;
  HKEY local_2250;
  undefined4 local_224c;
  undefined4 local_2248;
  int local_2244;
  HKEY local_2240;
  undefined4 local_223c;
  undefined4 local_2238;
  HKEY local_2234;
  uint local_2230;
  HKEY local_222c;
  undefined4 local_2228;
  undefined4 local_2224;
  void *local_2220;
  WCHAR local_221c [4096];
  wchar_t local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000dbd7;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2234 = param_2;
  local_222c = (HKEY)0x0;
  local_2228 = 0;
  local_2224 = 0;
  local_8 = 0;
  local_2254 = param_4;
  local_2220 = this;
  iVar4 = FUN_10001dd0(this,param_1);
  if (iVar4 < 0) {
    local_8 = 0xffffffff;
  }
  else {
    if (*param_1 != L'}') {
LAB_10005580:
      local_2244 = 1;
      iVar4 = lstrcmpiW(param_1,L"Delete");
      local_2230 = (uint)(iVar4 == 0);
      iVar5 = lstrcmpiW(param_1,L"ForceRemove");
      if ((iVar5 != 0) && ((iVar4 == 0) == 0)) {
LAB_10005712:
        iVar4 = lstrcmpiW(param_1,L"NoRemove");
        if (iVar4 == 0) {
          local_2244 = 0;
          iVar4 = FUN_10001dd0(local_2220,param_1);
          if (iVar4 < 0) goto LAB_10005bcf;
        }
        iVar4 = lstrcmpiW(param_1,L"Val");
        if (iVar4 == 0) {
          iVar4 = FUN_10001dd0(local_2220,local_221c);
          if ((-1 < iVar4) && (iVar4 = FUN_10001dd0(local_2220,param_1), -1 < iVar4)) {
            if (*param_1 != L'=') {
LAB_10005ba8:
              local_8 = 0xffffffff;
              FUN_10002b90(&local_222c);
              goto LAB_10005bf5;
            }
            if (param_3 != 0) {
              local_8._0_1_ = 2;
              local_2250 = local_2234;
              local_224c = 0;
              local_2248 = 0;
              iVar4 = FUN_10005140(local_2220,&local_2250,local_221c,param_1);
              local_2250 = (HKEY)0x0;
              local_224c = 0;
              local_2248 = 0;
              if (-1 < iVar4) {
                local_8 = (uint)local_8._1_3_ << 8;
                local_224c = 0;
                goto LAB_100056b0;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_10002b90(&local_2250);
              goto LAB_10005c21;
            }
            if ((param_4 == 0) && (local_2244 != 0)) {
              local_226c = (HKEY)0x0;
              local_2268 = 0;
              local_2264 = 0;
              local_8._0_1_ = 3;
              uVar7 = FUN_10001820(&local_226c,local_2234,(LPCWSTR)0x0,0x20006);
              pHVar2 = local_226c;
              if ((uVar7 != 0) ||
                 ((uVar7 = RegDeleteValueW(local_226c,local_221c), uVar7 != 0 && (uVar7 != 2)))) {
                FUN_10001510(uVar7);
                local_8 = (uint)local_8._1_3_ << 8;
                ppHVar9 = &local_226c;
                goto LAB_10005bca;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (pHVar2 != (HKEY)0x0) {
                RegCloseKey(pHVar2);
                local_226c = (HKEY)0x0;
              }
              local_2268 = 0;
            }
            iVar4 = FUN_10001fd0(local_2220,param_1);
LAB_100056f0:
            if (-1 < iVar4) goto LAB_100056fa;
          }
        }
        else {
          WVar1 = *param_1;
          pWVar6 = param_1;
          pHVar2 = local_2234;
          while (local_2234 = pHVar2, WVar1 != L'\0') {
            if (WVar1 == L'\\') {
              if (pWVar6 != (LPCWSTR)0x0) goto LAB_10005ba8;
              break;
            }
            pWVar6 = CharNextW(pWVar6);
            pHVar2 = local_2234;
            WVar1 = *pWVar6;
          }
          if (param_3 == 0) {
            if (param_4 == 0) {
              local_2230 = FUN_10001820(&local_222c,pHVar2,param_1,0x20019);
              if (local_2230 == 0) goto LAB_10005989;
            }
            else {
              local_2230 = 2;
            }
            param_4 = 1;
LAB_10005989:
            eVar8 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
            switch(eVar8) {
            case 0:
            case 0x50:
              goto switchD_100059b1_caseD_0;
            default:
                    /* WARNING: Subroutine does not return */
              FUN_100011a0(0x80004005);
            case 0xc:
                    /* WARNING: Subroutine does not return */
              FUN_100011a0(0x8007000e);
            case 0x16:
            case 0x22:
                    /* WARNING: Subroutine does not return */
              FUN_100011a0(0x80070057);
            }
          }
          iVar4 = FUN_10001820(&local_222c,pHVar2,param_1,0x2001f);
          if (((iVar4 != 0) &&
              (iVar4 = FUN_10001820(&local_222c,pHVar2,param_1,0x20019), iVar4 != 0)) &&
             (uVar7 = FUN_10001780(&local_222c,pHVar2,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar7 != 0))
          goto LAB_10005c50;
          iVar4 = FUN_10001dd0(local_2220,param_1);
          if ((-1 < iVar4) &&
             ((*param_1 != L'=' ||
              (iVar4 = FUN_10005140(local_2220,&local_222c,(LPCWSTR)0x0,param_1), -1 < iVar4)))) {
LAB_100056b0:
            if ((*param_1 != L'{') || (iVar4 = lstrlenW(param_1), iVar4 != 1)) goto LAB_100056fa;
            iVar4 = FUN_100054f0(local_2220,param_1,local_222c,param_3,0);
            if (-1 < iVar4) {
              iVar4 = FUN_10001dd0(local_2220,param_1);
              goto LAB_100056f0;
            }
          }
        }
        goto LAB_10005bcf;
      }
      iVar4 = FUN_10001dd0(local_2220,param_1);
      if (-1 < iVar4) {
        if (param_3 == 0) goto LAB_10005712;
        local_2240 = (HKEY)0x0;
        local_223c = 0;
        local_2238 = 0;
        local_8._0_1_ = 1;
        WVar1 = *param_1;
        pWVar6 = param_1;
        while (WVar1 != L'\0') {
          if (WVar1 == L'\\') {
            if (pWVar6 != (LPCWSTR)0x0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_10002b90(&local_2240);
              goto LAB_10005ba8;
            }
            break;
          }
          pWVar6 = CharNextW(pWVar6);
          WVar1 = *pWVar6;
        }
        ppuVar10 = &PTR_u_AppID_10010510;
        do {
          iVar4 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar10);
          if (iVar4 == 0) goto LAB_1000566f;
          ppuVar10 = ppuVar10 + 1;
        } while ((int)ppuVar10 < 0x10010540);
        local_2240 = local_2234;
        local_223c = 0;
        local_2238 = 0;
        FUN_10002bb0(&local_2240,param_1);
        local_2240 = (HKEY)0x0;
        local_223c = 0;
        local_2238 = 0;
LAB_1000566f:
        if (local_2230 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_10005712;
        }
        iVar4 = FUN_10001dd0(local_2220,param_1);
        if ((-1 < iVar4) && (iVar4 = FUN_10001fd0(local_2220,param_1), -1 < iVar4)) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_100056b0;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_2240;
        goto LAB_10005bca;
      }
    }
LAB_10005bcf:
    local_8 = 0xffffffff;
    if (local_222c != (HKEY)0x0) {
      RegCloseKey(local_222c);
      local_222c = (HKEY)0x0;
    }
  }
  local_2228 = 0;
LAB_10005bf5:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
switchD_100059b1_caseD_0:
  iVar4 = FUN_10001dd0(local_2220,param_1);
  if (((iVar4 < 0) || (iVar4 = FUN_10001fd0(local_2220,param_1), iVar4 < 0)) ||
     (((*param_1 == L'{' && (iVar4 = lstrlenW(param_1), iVar4 == 1)) &&
      (((iVar4 = FUN_100054f0(local_2220,param_1,local_222c,0,param_4), iVar4 < 0 && (param_4 == 0))
       || (iVar4 = FUN_10001dd0(local_2220,param_1), iVar4 < 0)))))) goto LAB_10005bcf;
  param_4 = local_2254;
  if (local_2230 != 2) {
    if (local_2230 == 0) {
      if ((local_2254 == 0) || (bVar3 = FUN_10001f80(local_222c), CONCAT31(extraout_var,bVar3) == 0)
         ) {
        bVar3 = FUN_10001f80(local_222c);
        local_2230 = CONCAT31(extraout_var_00,bVar3);
        uVar7 = 0;
        if (local_222c != (HKEY)0x0) {
          uVar7 = RegCloseKey(local_222c);
          local_222c = (HKEY)0x0;
        }
        local_2228 = 0;
        if (uVar7 != 0) {
LAB_10005c50:
          FUN_10001510(uVar7);
LAB_10005c21:
          local_8 = 0xffffffff;
          FUN_10002b90(&local_222c);
          goto LAB_10005bf5;
        }
        if ((local_2244 != 0) && (local_2230 == 0)) {
          local_8._0_1_ = 4;
          local_2260 = local_2234;
          local_225c = 0;
          local_2258 = 0;
          uVar7 = FUN_100016d0(&local_2260,local_21c);
          local_2260 = (HKEY)0x0;
          local_225c = 0;
          local_2258 = 0;
          if (uVar7 != 0) {
            FUN_10001510(uVar7);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar9 = &local_2260;
LAB_10005bca:
            FUN_10002b90(ppHVar9);
            goto LAB_10005bcf;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10002b90(&local_2260);
        }
      }
      else {
        iVar4 = FUN_10001f40(local_21c);
        if ((iVar4 != 0) && (local_2244 != 0)) {
          FUN_10002bb0(&local_222c,local_21c);
        }
      }
    }
    else if (local_2254 == 0) {
      FUN_10001510(local_2230);
      goto LAB_10005bcf;
    }
  }
LAB_100056fa:
  if (*param_1 == L'}') goto LAB_10005bcf;
  goto LAB_10005580;
}



// Function: FUN_10005d00 at 10005d00

int __thiscall FUN_10005d00(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dc08;
  local_10 = ExceptionList;
  uVar3 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 0;
  *param_3 = 0;
  puVar5 = *(undefined4 **)((int)this + 0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    piVar2 = (int *)*puVar5;
    while (piVar2 != (int *)0x0) {
      if ((((puVar5[2] != 0) && (*param_1 == *piVar2)) && (param_1[1] == piVar2[1])) &&
         ((param_1[2] == piVar2[2] && (param_1[3] == piVar2[3])))) {
        piVar2 = puVar5 + 4;
        if (puVar5[4] == 0) {
          local_8 = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10015ca8);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&DAT_10010958,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10015ca8);
        }
        if (*piVar2 != 0) {
          iVar4 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,param_2,param_3,uVar3);
        }
        if ((*param_3 != 0) || (iVar4 != 0)) {
          ExceptionList = local_10;
          return iVar4;
        }
        break;
      }
      puVar1 = puVar5 + 9;
      puVar5 = puVar5 + 9;
      piVar2 = (int *)*puVar1;
    }
  }
  iVar4 = FUN_100045d0((int *)&DAT_10015c98,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: FUN_10005e30 at 10005e30

void __thiscall FUN_10005e30(void *this,undefined4 param_1)

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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dca9;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_100060a3;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10015ba8 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_10015bac == *piVar1) && (DAT_10015bb0 == piVar1[1])) && (DAT_10015bb4 == piVar1[2]))
        && ((DAT_10015bb8 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_10015c38,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10006071;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002420((int *)&local_220);
    }
    else {
      iVar4 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                          param_1,&local_228,uVar2);
    }
    if (-1 < iVar4) {
      local_22c = (int *)0x0;
      local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
      iVar4 = (**(code **)(*local_228 + 0x18))(local_228,*this,&local_22c);
      if (-1 < iVar4) {
        local_224 = local_22c;
        if (local_22c != (int *)0x0) {
          (**(code **)(*local_22c + 4))(local_22c);
        }
        local_220 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_1001093c,&local_220);
        if (-1 < iVar4) {
          FUN_10004d80(&local_224,(int *)&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_10004ed0(DAT_10015ba8);
        local_8._0_1_ = 5;
        if (local_220 != (int *)0x0) {
          (**(code **)(*local_220 + 8))(local_220);
        }
        local_8._0_1_ = 3;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224);
        }
      }
      (**(code **)(*local_228 + 8))(local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_22c != (int *)0x0) {
        (**(code **)(*local_22c + 8))(local_22c);
      }
    }
  }
LAB_10006071:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_100031a0(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_100060a3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100060d0 at 100060d0

int * __thiscall FUN_100060d0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
      FUN_10004c30(this,uVar1);
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



// Function: DllGetClassObject at 100061e0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x61e0  2  DllGetClassObject */
  iVar1 = FUN_10005d00(&DAT_10015bec,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_100061f0 at 100061f0

void FUN_100061f0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10002780(0,param_2,param_3);
    return;
  }
  FUN_10004de0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10006220 at 10006220

void __fastcall FUN_10006220(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *param_1 = ATL::CComClassFactory::vftable;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return;
}



// Function: FUN_100062b0 at 100062b0

LONG FUN_100062b0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10015ba8 + 4))();
  }
  return LVar1;
}



// Function: FUN_100062e0 at 100062e0

LONG FUN_100062e0(int *param_1)

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
    (**(code **)(*DAT_10015ba8 + 8))();
  }
  return LVar1;
}



// Function: FUN_10006330 at 10006330

void FUN_10006330(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10002150(param_1,(int *)&PTR_DAT_10010b4c,param_2,param_3);
  return;
}



// Function: FUN_10006350 at 10006350

undefined4 * __thiscall FUN_10006350(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dd56;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100063e0 at 100063e0

int * __thiscall FUN_100063e0(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_100060d0(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
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
      FUN_10004c30(this,uVar1);
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



// Function: FUN_10006500 at 10006500

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006500(void *this,LPCWSTR param_1,int param_2)

{
  WCHAR WVar1;
  HKEY pHVar2;
  undefined4 uVar3;
  LPCWSTR lpsz;
  int iVar4;
  LPWSTR pWVar5;
  uint uVar6;
  WCHAR *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_200c = (WCHAR *)0x0;
  iVar4 = FUN_10003bc0(this,param_1,&local_200c);
  if (iVar4 < 0) {
LAB_10006615:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(WCHAR **)this = local_200c;
  WVar1 = *local_200c;
joined_r0x1000654e:
  if ((WVar1 == L'\0') || (iVar4 = FUN_10001dd0(this,local_2008), iVar4 < 0)) goto LAB_10006606;
  uVar6 = 0;
  while (iVar4 = lstrcmpiW(local_2008,(LPCWSTR)(&PTR_u_HKCR_10010750)[uVar6 * 2]), iVar4 != 0) {
    uVar6 = uVar6 + 1;
    if (0xd < uVar6) goto LAB_10006606;
  }
  pHVar2 = (HKEY)(&DAT_10010754)[uVar6 * 2];
  if (((pHVar2 == (HKEY)0x0) || (iVar4 = FUN_10001dd0(this,local_2008), iVar4 < 0)) ||
     (local_2008[0] != L'{')) goto LAB_10006606;
  if (param_2 == 0) {
    iVar4 = FUN_100054f0(this,local_2008,pHVar2,0,0);
    if (iVar4 < 0) goto LAB_10006606;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *this;
    iVar4 = FUN_100054f0(this,local_2008,pHVar2,param_2,0);
    if (iVar4 < 0) {
      *(undefined4 *)this = uVar3;
      FUN_100054f0(this,local_2008,pHVar2,0,0);
LAB_10006606:
      CoTaskMemFree(local_200c);
      goto LAB_10006615;
    }
  }
  do {
                    /* WARNING: Load size is inaccurate */
    lpsz = *this;
    switch(*lpsz) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      pWVar5 = CharNextW(lpsz);
      *(LPWSTR *)this = pWVar5;
      break;
    default:
      goto switchD_10006654_caseD_b;
    }
  } while( true );
switchD_10006654_caseD_b:
  WVar1 = *lpsz;
  goto joined_r0x1000654e;
}



// Function: FUN_100066a0 at 100066a0

int __thiscall FUN_100066a0(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10001000(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10003e80((GUID *)*piVar4,piVar3,iVar6);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      pbVar2 = (byte *)piVar4[9];
      piVar4 = piVar4 + 9;
    } while (pbVar2 != (byte *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = FUN_100044b0(0x10015c98,param_1,param_2);
  if ((-1 < iVar5) && (DAT_10015b9c != (code *)0x0)) {
    iVar5 = (*DAT_10015b9c)(DAT_10015c38);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_10006740 at 10006740

int __thiscall FUN_10006740(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10001000(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10003e80((GUID *)*piVar4,piVar3,iVar5);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = (*(code *)piVar4[1])(0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      pbVar2 = (byte *)piVar4[9];
      piVar4 = piVar4 + 9;
    } while (pbVar2 != (byte *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if ((DAT_10015ba0 != (code *)0x0) && (iVar5 = (*DAT_10015ba0)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_10004540(0x10015c98,param_1,param_2);
  return iVar5;
}



// Function: FUN_100067d0 at 100067d0

undefined4 __thiscall
FUN_100067d0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_10005e30(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_1000689e;
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
LAB_1000689e:
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



// Function: FUN_100068f0 at 100068f0

int * __thiscall FUN_100068f0(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_10004ba0(this,uVar2 + param_2,0xffffffff);
    FUN_10004ba0(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10004c30(this,uVar2);
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



// Function: FUN_100069f0 at 100069f0

int * __thiscall
FUN_100069f0(void *this,uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

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
      FUN_10004c30(this,uVar7);
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
          FUN_10002400((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),
                       param_2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10002400((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
          FUN_10002400((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
        FUN_10002400((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
      FUN_10002400((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),param_5);
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
    FUN_10002400(pvVar5,pvVar4,uVar2);
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



// Function: FUN_10006d20 at 10006d20

int * __thiscall FUN_10006d20(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_100068f0(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10004c30(this,param_2);
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



// Function: DllRegisterServer at 10006e20

void DllRegisterServer(void)

{
                    /* 0x6e20  3  DllRegisterServer */
  FUN_100066a0(&DAT_10015bec,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 10006e30

void DllUnregisterServer(void)

{
                    /* 0x6e30  4  DllUnregisterServer */
  FUN_10006740(&DAT_10015bec,1,(byte *)0x0);
  return;
}



// Function: FUN_10006e40 at 10006e40

undefined4 FUN_10006e40(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10015570 == (int *)0x0) {
    uVar1 = FUN_10005e30(&PTR_DAT_10015564,param_3);
  }
  *param_4 = DAT_10015570;
  if (DAT_10015570 != (int *)0x0) {
    (**(code **)(*DAT_10015570 + 4))(DAT_10015570);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006ea0 at 10006ea0

void FUN_10006ea0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100067d0(&PTR_DAT_10015564,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006ed0 at 10006ed0

void FUN_10006ed0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_10015570 == (int *)0x0) || (DAT_10015578 == 0)) {
    FUN_10005e30(&PTR_DAT_10015564,param_4);
  }
  if (DAT_10015570 != (int *)0x0) {
    (**(code **)(*DAT_10015570 + 0x2c))
              (DAT_10015570,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10006f30 at 10006f30

DWORD FUN_10006f30(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dd8b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006220(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10006fd6();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006fc3 at 10006fc3

undefined * Catch_10006fc3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006fd0;
}



// Function: FUN_10006fd6 at 10006fd6

DWORD FUN_10006fd6(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10007033;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000700b;
  }
  else {
LAB_1000700b:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_10007033;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10007033:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10007050 at 10007050

int * __thiscall FUN_10007050(void *this,uint param_1,int *param_2,int *param_3,uint param_4)

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
        piVar1 = FUN_100069f0(this,param_1,(uint)param_2,(int *)this,(int)param_3 - (int)pvVar2 >> 1
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
      FUN_10004c30(this,uVar6);
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
      FUN_10002400((void *)((int)pvVar2 + (param_1 + (int)piVar4) * 2),
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



// Function: FUN_10007240 at 10007240

void FUN_10007240(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  DWORD DVar2;
  uint uStack_444;
  undefined1 *local_41c;
  undefined1 auStack_418 [1024];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000ddc6;
  local_10 = ExceptionList;
  uStack_444 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_444;
  ExceptionList = &local_10;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = uStack_444;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    FUN_100014f0();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      FUN_100014f0();
    }
    else {
      pvVar1 = LoadResource(hModule,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        FUN_100014f0();
      }
      else {
        DVar2 = SizeofResource(hModule,hResInfo);
        if (DVar2 <= DVar2 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10004a90(&local_41c,DVar2 + 1);
          local_8 = 1;
          FUN_1000734d();
          return;
        }
      }
    }
    FreeLibrary(hModule);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_100024b0(&local_41c);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000732e at 1000732e

undefined * Catch_1000732e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000733b;
}



// Function: FUN_1000734d at 1000734d

void FUN_1000734d(void)

{
  int iVar1;
  LPCSTR unaff_EBX;
  uint unaff_EBP;
  HMODULE unaff_ESI;
  int unaff_EDI;
  undefined4 uStack0000000c;
  
  if (*(LPWSTR *)(unaff_EBP - 0x418) != (LPWSTR)0x0) {
    iVar1 = MultiByteToWideChar(3,0,unaff_EBX,unaff_EDI,*(LPWSTR *)(unaff_EBP - 0x418),unaff_EDI);
    if (iVar1 == 0) {
      FUN_100014f0();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x418) + iVar1 * 2) = 0;
      FUN_10006500((void *)(unaff_EBP - 0x42c),*(LPCWSTR *)(unaff_EBP - 0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(unaff_ESI);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x418) != unaff_EBP - 0x414) {
    FUN_100024b0((undefined4 *)(unaff_EBP - 0x418));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100073e0;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100073f0 at 100073f0

void FUN_100073f0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ddf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007240(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007450 at 10007450

undefined4 FUN_10007450(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ddf8;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10007240(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_100074d0 at 100074d0

void FUN_100074d0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ddf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007240(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007530 at 10007530

undefined4 FUN_10007530(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ddf8;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10007240(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_100075b0 at 100075b0

void FUN_100075b0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  HMODULE pHVar3;
  void **ppvVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  DWORD DVar8;
  HMODULE pHVar9;
  WCHAR *pWVar10;
  undefined **local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  int *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000de57;
  local_10 = ExceptionList;
  uVar6 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_a48 = param_1;
  local_a5c = ATL::CRegObject::vftable;
  local_a58 = 0;
  local_a54 = 0;
  local_a50 = 0;
  local_8 = 2;
  ppvVar4 = &local_10;
  local_14 = uVar6;
  if (param_4 != (undefined4 *)0x0) {
    pWVar2 = (LPCWSTR)*param_4;
    while (ExceptionList = ppvVar4, ppvVar4 = (void **)ExceptionList, pWVar2 != (LPCWSTR)0x0) {
      if ((pWVar2 != (LPCWSTR)0x0) && (param_4[1] != 0)) {
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        FUN_10004f00(pWVar2,param_4[1]);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      puVar1 = param_4 + 2;
      param_4 = param_4 + 2;
      ppvVar4 = (void **)ExceptionList;
      pWVar2 = (LPCWSTR)*puVar1;
    }
  }
  ExceptionList = ppvVar4;
  iVar7 = (**(code **)(*local_a48 + 0x14))(&local_a5c,uVar6);
  pHVar3 = DAT_10015c38;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_10015c38,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_100014f0();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002420((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10003ac0(&local_a5c);
        goto LAB_10007829;
      }
      FUN_10001670(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001120(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002420((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10003ac0(&local_a5c);
          goto LAB_10007829;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_100050b0(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_100050b0(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10007530(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10007450(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002420((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10003ac0(&local_a5c);
LAB_10007829:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007850 at 10007850

void FUN_10007850(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  HMODULE pHVar3;
  void **ppvVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  DWORD DVar8;
  HMODULE pHVar9;
  WCHAR *pWVar10;
  undefined **local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  int *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000deb7;
  local_10 = ExceptionList;
  uVar6 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_a48 = param_1;
  local_a5c = ATL::CRegObject::vftable;
  local_a58 = 0;
  local_a54 = 0;
  local_a50 = 0;
  local_8 = 2;
  ppvVar4 = &local_10;
  local_14 = uVar6;
  if (param_4 != (undefined4 *)0x0) {
    pWVar2 = (LPCWSTR)*param_4;
    while (ExceptionList = ppvVar4, ppvVar4 = (void **)ExceptionList, pWVar2 != (LPCWSTR)0x0) {
      if ((pWVar2 != (LPCWSTR)0x0) && (param_4[1] != 0)) {
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        FUN_10004f00(pWVar2,param_4[1]);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      puVar1 = param_4 + 2;
      param_4 = param_4 + 2;
      ppvVar4 = (void **)ExceptionList;
      pWVar2 = (LPCWSTR)*puVar1;
    }
  }
  ExceptionList = ppvVar4;
  iVar7 = (**(code **)(*local_a48 + 0x14))(&local_a5c,uVar6);
  pHVar3 = DAT_10015c38;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_10015c38,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_100014f0();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002420((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10003ac0(&local_a5c);
        goto LAB_10007ab3;
      }
      FUN_10001670(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001120(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002420((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10003ac0(&local_a5c);
          goto LAB_10007ab3;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_100050b0(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_100050b0(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_100074d0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100073f0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002420((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10003ac0(&local_a5c);
LAB_10007ab3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007ad0 at 10007ad0

void __thiscall FUN_10007ad0(void *this,uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007050(this,param_1,param_2,param_3,(int)piVar2 - ((int)param_3 + 2) >> 1);
  return;
}



// Function: FUN_10007b10 at 10007b10

void __thiscall FUN_10007b10(void *this,int *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int ***pppiVar4;
  bool bVar5;
  ushort local_50 [2];
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  int **local_30 [4];
  int *local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000def0;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = (int *)0x0;
  local_30[0] = (int **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x14))(local_30,local_14);
  if (iVar1 == 0) {
    bVar5 = local_20 == (int *)0x0;
    if (bVar5) goto LAB_10007b73;
  }
  else {
LAB_10007b73:
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x10))(local_30);
    if (iVar1 == 0) {
      bVar5 = local_20 == (int *)0x0;
      if (!bVar5) goto LAB_10007ba3;
    }
    FUN_100068f0(param_2,param_1,0,0xffffffff);
    if (iVar1 != 0) goto LAB_10007c5e;
    bVar5 = local_20 == (int *)0x0;
  }
LAB_10007ba3:
  if (!bVar5) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_100068f0(local_4c,param_1,0,0xffffffff);
    local_50[0] = 0x5f;
    local_50[1] = 0;
    uVar2 = FUN_100026a0(local_4c,local_50,0xffffffff,1);
    local_50[0] = 0x2e;
    local_50[1] = 0;
    uVar3 = FUN_100026a0(local_4c,local_50,0xffffffff,1);
    if ((uVar2 != 0xffffffff) && ((int *)((uVar3 - uVar2) + -1) == local_20)) {
      pppiVar4 = (int ***)local_30[0];
      if (local_1c < 8) {
        pppiVar4 = local_30;
      }
      FUN_10007ad0(local_4c,uVar2 + 1,local_20,(int *)pppiVar4);
    }
    FUN_100068f0(param_2,(int *)local_4c,0,0xffffffff);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
LAB_10007c5e:
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = (int *)0x0;
  local_30[0] = (int **)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007cb0 at 10007cb0

void FUN_10007cb0(void *param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort *puVar5;
  int *piVar6;
  ushort *puVar7;
  
  puVar7 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    puVar7 = *(ushort **)param_2;
  }
  puVar5 = puVar7;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  } while (uVar1 != 0);
  for (uVar3 = FUN_10003530(param_1,puVar7,0,(int)puVar5 - (int)(puVar7 + 1) >> 1);
      uVar3 != 0xffffffff;
      uVar3 = FUN_10003530(param_1,puVar5,param_3[4] + uVar3,(int)puVar7 - (int)(puVar5 + 1) >> 1))
  {
    piVar4 = FUN_100024c0(param_3);
    piVar6 = piVar4;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar2 != 0);
    FUN_10007050(param_1,uVar3,*(int **)(param_2 + 8),piVar4,(int)piVar6 - ((int)piVar4 + 2) >> 1);
    puVar5 = (ushort *)FUN_100024c0((undefined4 *)param_2);
    puVar7 = puVar5;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != 0);
  }
  return;
}



// Function: FUN_10007d70 at 10007d70

void FUN_10007d70(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_100075b0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007d80 at 10007d80

void FUN_10007d80(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10007850(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007d90 at 10007d90

undefined2 * __thiscall FUN_10007d90(void *this,int *param_1)

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
  FUN_10006d20(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return (undefined2 *)this;
}



// Function: FUN_10007de0 at 10007de0

void FUN_10007de0(int param_1)

{
  FUN_10007850((int *)&DAT_10015bec,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10007e00 at 10007e00

void FUN_10007e00(void)

{
  short sVar1;
  int iVar2;
  LSTATUS LVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  int ****ppppiVar7;
  LPCWSTR ***ppppWVar8;
  HMODULE Value;
  HKEY pHVar9;
  HKEY local_498;
  undefined4 local_494;
  undefined4 local_490;
  HKEY local_48c;
  undefined4 local_488;
  undefined4 local_484;
  ushort local_480 [2];
  DWORD local_47c;
  LPCWSTR **local_478 [4];
  undefined4 local_468;
  uint local_464;
  int ***local_45c [4];
  int *local_44c;
  uint local_448;
  LPCWSTR **local_440 [4];
  undefined4 local_430;
  uint local_42c;
  undefined4 local_424;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000df57;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48c = (HKEY)0x0;
  local_488 = 0;
  local_484 = 0;
  local_42c = 7;
  local_430 = 0;
  local_440[0] = (LPCWSTR **)((uint)local_440[0] & 0xffff0000);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_478[0] = (LPCWSTR **)((uint)local_478[0] & 0xffff0000);
  local_464 = 7;
  local_468 = 0;
  FUN_10006d20(local_478,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8._0_1_ = 2;
  FUN_100063e0(local_478,(int *)L"{86E56377-F2C2-4256-B4B7-3806FA495328}",0x26);
  ppppWVar8 = (LPCWSTR ***)local_478[0];
  if (local_464 < 8) {
    ppppWVar8 = local_478;
  }
  iVar2 = FUN_10001820(&local_48c,(HKEY)0x80000002,(LPCWSTR)ppppWVar8,0x2001f);
  pHVar9 = local_48c;
  if (iVar2 == 0) {
    local_47c = 0x208;
    LVar3 = FUN_100018d0(&local_48c,(LPBYTE)&local_424,L"ResourceDLL",&local_47c);
    if (LVar3 == 0) {
      local_498 = (HKEY)0x0;
      local_494 = 0;
      local_490 = 0;
      local_8._0_1_ = 3;
      iVar2 = FUN_10001820(&local_498,(HKEY)0x80000002,
                           L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",
                           0x2001f);
      pHVar9 = local_498;
      if (iVar2 == 0) {
        local_448 = 7;
        local_44c = (int *)0x0;
        local_45c[0] = (int ***)((uint)local_45c[0] & 0xffff0000);
        local_8 = CONCAT31(local_8._1_3_,4);
        local_47c = 0x208;
        LVar3 = FUN_100018d0(&local_498,(LPBYTE)&local_21c,L"LanguageExt",&local_47c);
        if (LVar3 == 0) {
          psVar4 = (short *)&local_424;
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          FUN_10006d20(local_440,&local_424,(int)psVar4 - ((int)&local_424 + 2) >> 1);
          psVar4 = (short *)&local_21c;
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          FUN_10006d20(local_45c,&local_21c,(int)psVar4 - ((int)&local_21c + 2) >> 1);
          local_480[0] = 0x5f;
          local_480[1] = 0;
          uVar5 = FUN_100026a0(local_440,local_480,0xffffffff,1);
          local_480[0] = 0x2e;
          local_480[1] = 0;
          uVar6 = FUN_100026a0(local_440,local_480,0xffffffff,1);
          if ((uVar5 != 0xffffffff) && ((int *)((uVar6 - uVar5) + -1) == local_44c)) {
            ppppiVar7 = (int ****)local_45c[0];
            if (local_448 < 8) {
              ppppiVar7 = local_45c;
            }
            FUN_10007ad0(local_440,uVar5 + 1,local_44c,(int *)ppppiVar7);
          }
        }
        if (local_498 != (HKEY)0x0) {
          RegCloseKey(local_498);
          local_498 = (HKEY)0x0;
        }
        pHVar9 = local_498;
        local_494 = 0;
        local_8._0_1_ = 3;
        if (7 < local_448) {
          operator_delete(local_45c[0]);
        }
        local_448 = 7;
        local_44c = (int *)0x0;
        local_45c[0] = (int ***)((uint)local_45c[0] & 0xffff0000);
      }
      local_8._0_1_ = 2;
      if (pHVar9 != (HKEY)0x0) {
        RegCloseKey(pHVar9);
        local_498 = (HKEY)0x0;
      }
      local_494 = 0;
    }
    if (local_48c != (HKEY)0x0) {
      RegCloseKey(local_48c);
      local_48c = (HKEY)0x0;
    }
    pHVar9 = local_48c;
    local_488 = 0;
    ppppWVar8 = (LPCWSTR ***)local_440[0];
    if (local_42c < 8) {
      ppppWVar8 = local_440;
    }
    Value = LoadLibraryW((LPCWSTR)ppppWVar8);
    if (Value != (HMODULE)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10015c70);
      InterlockedExchange(&DAT_10015c3c,(LONG)Value);
      DAT_10015c38 = Value;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10015c70);
    }
  }
  local_8._0_1_ = 1;
  if (7 < local_464) {
    operator_delete(local_478[0]);
  }
  local_464 = 7;
  local_468 = 0;
  local_478[0] = (LPCWSTR **)((uint)local_478[0] & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_42c) {
    operator_delete(local_440[0]);
  }
  local_42c = 7;
  local_430 = 0;
  local_440[0] = (LPCWSTR **)((uint)local_440[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (pHVar9 != (HKEY)0x0) {
    RegCloseKey(pHVar9);
    local_48c = (HKEY)0x0;
  }
  local_488 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100081f0 at 100081f0

void __fastcall FUN_100081f0(int *param_1)

{
  short sVar1;
  int iVar2;
  HMODULE pHVar3;
  int ****ppppiVar4;
  LPCWSTR ***ppppWVar5;
  int ****ppppiVar6;
  int local_c0;
  void *local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  int ***local_4c [4];
  int local_3c;
  uint local_38;
  LPCWSTR **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000dfb6;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_a8 = 7;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = 2;
  iVar2 = (**(code **)(*param_1 + 0x24))(local_30,local_14);
  ppppWVar5 = (LPCWSTR ***)local_30[0];
  if (local_1c < 8) {
    ppppWVar5 = local_30;
  }
  pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
  if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
    iVar2 = (**(code **)(*param_1 + 0x28))(local_30);
    ppppWVar5 = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      ppppWVar5 = local_30;
    }
    pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
    if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
      iVar2 = (**(code **)(*param_1 + 0x14))(local_4c);
      if (((iVar2 != 0) || (local_c0 = 0, local_3c == 0)) &&
         ((local_c0 = (**(code **)(*param_1 + 0x10))(local_4c), local_c0 != 0 || (local_3c == 0))))
      {
        FUN_10006d20(local_4c,(int *)&DAT_10010448,2);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68._2_2_ << 0x10);
      FUN_10006d20(&local_68,(int *)&DAT_10010d64,1);
      local_8._0_1_ = 3;
      ppppiVar6 = (int ****)local_4c[0];
      if (local_38 < 8) {
        ppppiVar6 = local_4c;
      }
      ppppiVar4 = ppppiVar6;
      do {
        sVar1 = *(short *)ppppiVar4;
        ppppiVar4 = (int ****)((int)ppppiVar4 + 2);
      } while (sVar1 != 0);
      FUN_100063e0(&local_68,(int *)ppppiVar6,(int)ppppiVar4 - ((int)ppppiVar6 + 2) >> 1);
      FUN_100063e0(&local_68,(int *)&DAT_10010d60,1);
      local_84 = (void *)((uint)local_84._2_2_ << 0x10);
      local_70 = 7;
      local_74 = 0;
      FUN_10006d20(&local_84,(int *)L"_EN.",4);
      local_8._0_1_ = 4;
      (**(code **)(*param_1 + 0x38))(local_30,&local_84,&local_68);
      local_8._0_1_ = 3;
      if (7 < local_70) {
        operator_delete(local_84);
      }
      local_84 = (void *)((uint)local_84 & 0xffff0000);
      local_70 = 7;
      local_74 = 0;
      local_8c = 7;
      local_90 = 0;
      local_a0 = (void *)((uint)local_a0._2_2_ << 0x10);
      FUN_10006d20(&local_a0,(int *)L"_en.",4);
      local_8._0_1_ = 5;
      (**(code **)(*param_1 + 0x38))(local_30,&local_a0,&local_68);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (7 < local_8c) {
        operator_delete(local_a0);
      }
      local_8c = 7;
      local_90 = 0;
      local_a0 = (void *)((uint)local_a0 & 0xffff0000);
      ppppWVar5 = (LPCWSTR ***)local_30[0];
      if (local_1c < 8) {
        ppppWVar5 = local_30;
      }
      pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
      if (((local_c0 != 0) || (pHVar3 == (HMODULE)0x0)) &&
         (iVar2 = (**(code **)(*param_1 + 0x30))(local_bc), iVar2 == 0)) {
        FUN_100068f0(local_30,(int *)local_bc,0,0xffffffff);
        FUN_100063e0(local_30,(int *)L"Res_",4);
        FUN_100060d0(local_30,local_4c,0,0xffffffff);
        FUN_100063e0(local_30,(int *)L".dll",4);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (7 < local_54) {
        operator_delete(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68 & 0xffff0000);
      if (pHVar3 == (HMODULE)0x0) {
        ppppWVar5 = (LPCWSTR ***)local_30[0];
        if (local_1c < 8) {
          ppppWVar5 = local_30;
        }
        pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
        if (pHVar3 == (HMODULE)0x0) {
          GetLastError();
          goto LAB_10008524;
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x20))(pHVar3);
  param_1[1] = 1;
LAB_10008524:
  local_8._0_1_ = 1;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_a8) {
    operator_delete(local_bc[0]);
  }
  local_a8 = 7;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100085e0 at 100085e0

void __thiscall FUN_100085e0(void *this,int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dfe8;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar3 = param_1;
  do {
    iVar1 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 2);
  } while ((short)iVar1 != 0);
  local_14 = uVar2;
  FUN_10006d20(local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 8))(local_30,param_2,uVar2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100086b0 at 100086b0

void FUN_100086b0(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000e026;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10006d20(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\",
               0x36);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100063e0(&local_238,(int *)L"Locale",6);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10001820(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10001980(&local_244,L"LanguageExt",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10006d20(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008860 at 10008860

void FUN_10008860(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  HKEY local_264;
  undefined4 local_260;
  undefined4 local_25c;
  uint local_258;
  undefined4 local_254;
  undefined4 local_244;
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e071;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_264 = (HKEY)0x0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_258 = 0x208;
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254._2_2_ << 0x10);
  FUN_10006d20(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10006d20(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100060d0(&local_238,&local_254,0,0xffffffff);
  FUN_100063e0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_100063e0(&local_238,(int *)L"86E56377-F2C2-4256-B4B7-3806FA495328",0x24);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10001820(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10001980(&local_264,L"LanguageExt",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10006d20(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8._0_1_ = 1;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_240) {
    operator_delete(local_254);
  }
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_264 != (HKEY)0x0) {
    RegCloseKey(local_264);
    local_264 = (HKEY)0x0;
  }
  local_260 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008aa0 at 10008aa0

void __fastcall FUN_10008aa0(int *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined **ppuVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  void *local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e0a8;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  iVar3 = (**(code **)(*param_1 + 0x10))(local_30,local_14);
  if ((iVar3 != 0) || (local_20 == 0)) {
    FUN_10006d20(local_30,(int *)&DAT_10010448,2);
  }
  uVar7 = 0;
  if (PTR_DAT_10015000 != (undefined *)0x0) {
    ppuVar4 = &PTR_DAT_10015000;
    do {
      puVar2 = (ushort *)*ppuVar4;
      puVar5 = puVar2;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
      } while (uVar1 != 0);
      uVar6 = FUN_100029c0(local_30,0,local_20,puVar2,(int)puVar5 - (int)(puVar2 + 1) >> 1);
      if (uVar6 == 0) break;
      uVar7 = uVar7 + 1;
      ppuVar4 = &PTR_DAT_10015000 + (uVar7 & 0xffff);
    } while ((&PTR_DAT_10015000)[uVar7 & 0xffff] != (undefined *)0x0);
  }
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008bb0 at 10008bb0

void FUN_10008bb0(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  HKEY local_264;
  undefined4 local_260;
  undefined4 local_25c;
  uint local_258;
  undefined4 local_254;
  undefined4 local_244;
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e071;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_264 = (HKEY)0x0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_258 = 0x208;
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254._2_2_ << 0x10);
  FUN_10006d20(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10006d20(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100060d0(&local_238,&local_254,0,0xffffffff);
  FUN_100063e0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_100063e0(&local_238,(int *)L"86E56377-F2C2-4256-B4B7-3806FA495328",0x24);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10001820(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10001980(&local_264,L"ResourceDLL",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10006d20(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8._0_1_ = 1;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_240) {
    operator_delete(local_254);
  }
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_264 != (HKEY)0x0) {
    RegCloseKey(local_264);
    local_264 = (HKEY)0x0;
  }
  local_260 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008df0 at 10008df0

void FUN_10008df0(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000e026;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10006d20(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100063e0(&local_238,(int *)L"86E56377-F2C2-4256-B4B7-3806FA495328",0x24);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10001820(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10001980(&local_244,L"ResourceDLL",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10006d20(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008fa0 at 10008fa0

void __thiscall FUN_10008fa0(void *this,undefined4 param_1)

{
  LPCWSTR pWVar1;
  int iVar2;
  HKEY local_450;
  undefined4 local_44c;
  undefined4 local_448;
  uint local_444;
  undefined4 local_440;
  undefined4 local_430;
  uint local_42c;
  BYTE local_424 [520];
  BYTE local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000e0e6;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_450 = (HKEY)0x0;
  local_44c = 0;
  local_448 = 0;
  local_8 = 0;
  local_21c[0] = '\0';
  local_21c[1] = '\0';
  memset(local_21c + 2,0,0x206);
  local_424[0] = '\0';
  local_424[1] = '\0';
  memset(local_424 + 2,0,0x206);
  local_444 = 0x208;
  local_42c = 7;
  local_430 = 0;
  local_440 = (LPCWSTR)((uint)local_440._2_2_ << 0x10);
  FUN_10006d20(&local_440,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100063e0(&local_440,(int *)L"86E56377-F2C2-4256-B4B7-3806FA495328",0x24);
  pWVar1 = local_440;
  if (local_42c < 8) {
    pWVar1 = (LPCWSTR)&local_440;
  }
  iVar2 = FUN_10001820(&local_450,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_10001980(&local_450,L"XMLResource",local_21c,&local_444);
    local_444 = 0x208;
  }
  FUN_10001980(&local_450,L"FriendlyName",local_424,&local_444);
  if ((iVar2 == 0) && (local_444 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(local_21c,param_1);
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_42c) {
    operator_delete(local_440);
  }
  local_42c = 7;
  local_430 = 0;
  local_440 = (LPCWSTR)((uint)local_440 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_450 != (HKEY)0x0) {
    RegCloseKey(local_450);
    local_450 = (HKEY)0x0;
  }
  local_44c = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009190 at 10009190

void FUN_10009190(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000e026;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10006d20(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100063e0(&local_238,(int *)L"86E56377-F2C2-4256-B4B7-3806FA495328",0x24);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10001820(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10001980(&local_244,L"BaseName",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10006d20(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009340 at 10009340

undefined4 FUN_10009340(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_100020d0(&DAT_10015bec,(int *)&PTR_DAT_10015088,param_1,(undefined4 *)&DAT_10010480);
    DisableThreadLibraryCalls(param_1);
    FUN_10007e00();
    return 1;
  }
  if (param_2 == 0) {
    FUN_100030b0(0x10015bec);
  }
  FUN_10007e00();
  return 1;
}



// Function: FUN_100093a0 at 100093a0

undefined4 FUN_100093a0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  return 0;
}



// Function: Catch@10009419 at 10009419

undefined4 Catch_10009419(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009402;
}



// Function: FUN_10009430 at 10009430

undefined4 FUN_10009430(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return 0;
}



// Function: Catch@1000948a at 1000948a

undefined4 Catch_1000948a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009473;
}



// Function: FUN_100094a0 at 100094a0

uint __cdecl FUN_100094a0(HMODULE param_1,HRSRC param_2,uint param_3)

{
  HGLOBAL hResData;
  ushort *puVar1;
  DWORD DVar2;
  ushort *puVar3;
  uint uVar4;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    return 0;
  }
  puVar1 = (ushort *)LockResource(hResData);
  if (puVar1 != (ushort *)0x0) {
    DVar2 = SizeofResource(param_1,param_2);
    puVar3 = (ushort *)(DVar2 + (int)puVar1);
    for (uVar4 = param_3 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar3 <= puVar1) {
        return 0;
      }
      puVar1 = puVar1 + *puVar1 + 1;
    }
    if (puVar1 < puVar3) {
      return -(uint)(*puVar1 != 0) & (uint)puVar1;
    }
  }
  return 0;
}



// Function: FUN_10009510 at 10009510

uint __cdecl FUN_10009510(uint param_1)

{
  HMODULE hModule;
  HRSRC pHVar1;
  uint uVar2;
  int local_8;
  
  uVar2 = 0;
  hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10015c34,0);
  local_8 = 1;
  while ((hModule != (HMODULE)0x0 && (uVar2 == 0))) {
    pHVar1 = FindResourceW(hModule,(LPCWSTR)((param_1 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
    if (pHVar1 != (HRSRC)0x0) {
      uVar2 = FUN_100094a0(hModule,pHVar1,param_1);
    }
    hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10015c34,local_8);
    local_8 = local_8 + 1;
  }
  return uVar2;
}



// Function: FUN_10009580 at 10009580

void __cdecl FUN_10009580(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x2d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x2d);
  }
  return;
}



// Function: FUN_100095a0 at 100095a0

void __cdecl FUN_100095a0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x2d);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_100095c0 at 100095c0

void __fastcall FUN_100095c0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x2d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x2d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x2d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x2d);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x2d);
    }
    *param_1 = iVar2;
  }
  return;
}



// Function: FUN_10009610 at 10009610

void __fastcall FUN_10009610(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10009620 at 10009620

undefined4 * __thiscall FUN_10009620(void *this,byte param_1)

{
  FUN_10009610((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009650 at 10009650

void __fastcall FUN_10009650(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0x2d) != '\0') {
    *param_1 = puVar2[2];
    return;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0x2d) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0x2d) == '\0');
      *param_1 = iVar4;
      return;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0x2d);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0x2d);
    }
    if (*(char *)(*param_1 + 0x2d) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar5;
  return;
}



// Function: FUN_100096b0 at 100096b0

bool __thiscall FUN_100096b0(void *this,uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  puVar1 = (undefined2 *)FUN_10009510(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    iVar2 = Ordinal_4(puVar1 + 1,*puVar1);
    *(int *)this = iVar2;
    return iVar2 != 0;
  }
  *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
  return *this != 0;
}



// Function: FUN_10009700 at 10009700

bool __thiscall FUN_10009700(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e1b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(param_1,DAT_10015b6c ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,iVar2,0x400,0);
  local_8 = 0xffffffff;
  Ordinal_6(iVar2);
  ExceptionList = local_10;
  return iVar1 == 1;
}



// Function: FUN_10009790 at 10009790

void __fastcall FUN_10009790(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_100097a0 at 100097a0

void __thiscall FUN_100097a0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x2d) == '\0') {
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



// Function: FUN_10009800 at 10009800

void __thiscall FUN_10009800(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x2d) == '\0') {
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



// Function: FUN_10009860 at 10009860

int * __cdecl FUN_10009860(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e1f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2,DAT_10015b6c ^ (uint)&stack0xfffffffc,0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100098e0 at 100098e0

void __fastcall FUN_100098e0(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10009900 at 10009900

void __fastcall FUN_10009900(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e22b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (7 < *(uint *)(param_1 + 0x18)) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009970 at 10009970

void __fastcall FUN_10009970(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e25b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 0xffffffff;
  if (7 < (uint)param_1[9]) {
    operator_delete((void *)param_1[4]);
  }
  param_1[9] = 7;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_100099e0 at 100099e0

undefined4 * __thiscall FUN_100099e0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e25b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_8 = 0xffffffff;
  if (7 < *(uint *)((int)this + 0x24)) {
    operator_delete(*(void **)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009a60 at 10009a60

void __fastcall FUN_10009a60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e293;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (7 < *(uint *)(param_1 + 0x18)) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009ad0 at 10009ad0

void __thiscall FUN_10009ad0(void *this,undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x2d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x2d) == '\0');
  }
  if ((puVar3 != *(undefined4 **)((int)this + 4)) && ((int)puVar3[3] <= *param_2)) {
    *param_1 = puVar3;
    return;
  }
  *param_1 = *(undefined4 **)((int)this + 4);
  return;
}



// Function: FUN_10009b40 at 10009b40

undefined4 FUN_10009b40(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  piVar1 = param_3;
  puStack_c = &LAB_1000e2b8;
  local_10 = ExceptionList;
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  piVar2 = (int *)FUN_10009ad0((void *)(param_1 + 0x14),&param_3,&param_2);
  if (*piVar2 == *(int *)(param_1 + 0x18)) {
    local_18 = 0x80004005;
  }
  else {
    piVar2 = FUN_10009860((int *)&param_3,(undefined4 *)(*piVar2 + 0x10));
    *piVar1 = *piVar2;
    local_8 = local_8 & 0xffffff00;
    Ordinal_6(param_3);
    local_18 = 0;
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: Catch@10009bf9 at 10009bf9

undefined4 Catch_10009bf9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009be2;
}



// Function: FUN_10009c10 at 10009c10

undefined2 * __thiscall FUN_10009c10(void *this,undefined2 *param_1,uint param_2,uint param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e2f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100068f0(param_1,(int *)this,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009c90 at 10009c90

undefined4 * __thiscall FUN_10009c90(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e32b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  FUN_100068f0((undefined2 *)((int)this + 0x10),(int *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009d20 at 10009d20

undefined4 * __thiscall FUN_10009d20(void *this,undefined4 *param_1)

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



// Function: FUN_10009da0 at 10009da0

undefined2 * __cdecl FUN_10009da0(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e369;
  local_10 = ExceptionList;
  if (param_2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    return param_1;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10006d20(param_1,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009e50 at 10009e50

void __cdecl FUN_10009e50(undefined4 param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e3a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (7 < *(uint *)(param_2 + 0x18)) {
    operator_delete(*(void **)(param_2 + 4));
  }
  *(undefined4 *)(param_2 + 0x18) = 7;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009ec0 at 10009ec0

void __thiscall
FUN_10009ec0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
  if (0x7fffffd < uVar4) {
    FUN_10009e50((int)this + 0xd,(int)(param_4 + 3));
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
  cVar1 = *(char *)(param_4[1] + 0x2c);
  piVar5 = param_4;
  do {
    if (cVar1 != '\0') {
      iVar2 = *(int *)(*(int *)((int)this + 4) + 4);
      *param_1 = param_4;
      *(undefined1 *)(iVar2 + 0x2c) = 1;
      return;
    }
    piVar6 = (int *)piVar5[1];
    piVar7 = (int *)piVar6[1];
    if (piVar6 == (int *)*piVar7) {
      iVar2 = piVar7[2];
      if (*(char *)(iVar2 + 0x2c) == '\0') {
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(iVar2 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar6[2]) {
          piVar5 = (int *)piVar6[2];
          piVar6[2] = *piVar5;
          if (*(char *)(*piVar5 + 0x2d) == '\0') {
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
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)*piVar6;
        *piVar6 = piVar7[2];
        if (*(char *)(piVar7[2] + 0x2d) == '\0') {
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
LAB_1000a0c5:
        piVar6[1] = (int)piVar7;
      }
    }
    else {
      iVar2 = *piVar7;
      if (*(char *)(iVar2 + 0x2c) != '\0') {
        if (piVar5 == (int *)*piVar6) {
          iVar2 = *piVar6;
          *piVar6 = *(int *)(iVar2 + 8);
          if (*(char *)(*(int *)(iVar2 + 8) + 0x2d) == '\0') {
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
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)piVar6[2];
        piVar6[2] = *piVar7;
        if (*(char *)(*piVar7 + 0x2d) == '\0') {
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
        goto LAB_1000a0c5;
      }
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(iVar2 + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    cVar1 = *(char *)(piVar5[1] + 0x2c);
  } while( true );
}



// Function: FUN_1000a0f0 at 1000a0f0

void __thiscall FUN_1000a0f0(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_100095c0((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar6 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) == '\0') && (piVar6 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar6 + 0x2d) == '\0') {
          piVar6[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar6;
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
      iVar1 = param_2[0xb];
      *(char *)(param_2 + 0xb) = (char)piVar2[0xb];
      *(char *)(piVar2 + 0xb) = (char)iVar1;
      goto LAB_1000a20b;
    }
  }
  else {
    piVar6 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  if ((int *)**(int **)((int)this + 4) == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      piVar3 = (int *)FUN_100095a0(piVar6);
    }
    **(undefined4 **)((int)this + 4) = piVar3;
  }
  iVar1 = *(int *)((int)this + 4);
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      uVar4 = FUN_10009580((int)piVar6);
      *(undefined4 *)(iVar1 + 8) = uVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_1000a20b:
  if ((char)piVar2[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_100097a0(this,(int)piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_10009800(this,piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
              *(undefined1 *)(piVar3 + 0xb) = 1;
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              FUN_100097a0(this,(int)piVar3);
              break;
            }
LAB_1000a2d1:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_10009800(this,piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
            goto LAB_1000a2d1;
            if (*(char *)(*piVar5 + 0x2c) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_100097a0(this,(int)piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
            *(undefined1 *)(piVar3 + 0xb) = 1;
            *(undefined1 *)(*piVar5 + 0x2c) = 1;
            FUN_10009800(this,piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  FUN_10009e50((int)this + 0xd,(int)(piVar2 + 3));
  operator_delete(piVar2);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000a360 at 1000a360

void __thiscall FUN_1000a360(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_1000a360(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10009e50((int)this + 0xd,(int)(param_1 + 3));
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000a3b0 at 1000a3b0

void __thiscall FUN_1000a3b0(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool local_8;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  local_8 = true;
  if (*(char *)((int)puVar2[1] + 0x2d) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      if (param_3 == '\0') {
        local_8 = param_2[3] < (int)puVar2[3];
      }
      else {
        local_8 = param_2[3] <= (int)puVar2[3];
      }
      if (local_8 == false) {
        puVar1 = (undefined4 *)puVar2[2];
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
      }
    } while (*(char *)((int)puVar1 + 0x2d) == '\0');
  }
  _param_3 = puVar2;
  if (local_8 != false) {
    if (puVar2 == (undefined4 *)**(int **)((int)this + 4)) {
      puVar2 = (undefined4 *)FUN_10009ec0(this,(undefined4 *)&param_3,'\x01',puVar2,param_2);
      *param_1 = *puVar2;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_10009650((int *)&param_3);
  }
  puVar1 = _param_3;
  if ((int)_param_3[3] < param_2[3]) {
    puVar2 = (undefined4 *)FUN_10009ec0(this,(undefined4 *)&param_3,local_8,puVar2,param_2);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  FUN_10009e50((int)this + 0xd,(int)(param_2 + 3));
  operator_delete(param_2);
  *param_1 = puVar1;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_1000a4a0 at 1000a4a0

undefined4 * __thiscall FUN_1000a4a0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 local_c [2];
  
  piVar2 = param_3;
  piVar1 = *(int **)((int)this + 4);
  if (*(int *)((int)this + 8) == 0) {
    FUN_10009ec0(this,param_1,'\x01',piVar1,param_3);
    return param_1;
  }
  if (param_2 == (int *)*piVar1) {
    if (param_3[3] < param_2[3]) {
      FUN_10009ec0(this,param_1,'\x01',param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if ((int)((undefined4 *)piVar1[2])[3] < param_3[3]) {
      FUN_10009ec0(this,param_1,'\0',(undefined4 *)piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    if (param_3[3] < param_2[3]) {
      param_3 = param_2;
      FUN_10009650((int *)&param_3);
      if (param_3[3] < piVar2[3]) {
        if (*(char *)(param_3[2] + 0x2d) != '\0') {
          FUN_10009ec0(this,param_1,'\0',param_3,piVar2);
          return param_1;
        }
        FUN_10009ec0(this,param_1,'\x01',param_2,piVar2);
        return param_1;
      }
    }
    if (param_2[3] < piVar2[3]) {
      param_3 = param_2;
      FUN_100095c0((int *)&param_3);
      if ((param_3 == *(int **)((int)this + 4)) || (piVar2[3] < param_3[3])) {
        if (*(char *)(param_2[2] + 0x2d) != '\0') {
          FUN_10009ec0(this,param_1,'\0',param_2,piVar2);
          return param_1;
        }
        FUN_10009ec0(this,param_1,'\x01',param_3,piVar2);
        return param_1;
      }
    }
  }
  puVar3 = (undefined4 *)FUN_1000a3b0(this,local_c,piVar2,'\0');
  *param_1 = *puVar3;
  return param_1;
}



// Function: FUN_1000a600 at 1000a600

void FUN_1000a600(undefined4 param_1,undefined4 param_2)

{
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined **local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e3d8;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8 = 0;
  local_40 = param_1;
  local_3c = 0;
  local_38 = param_2;
  FUN_10006d20(local_34,(int *)&DAT_100109b8,0);
  local_18 = 0;
  local_8 = 1;
  local_6c = local_3c;
  local_70 = local_40;
  local_74 = CComErrorHandlerException::vftable;
  local_68 = local_38;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  FUN_100068f0(local_64,(int *)local_34,0,0xffffffff);
  local_48 = local_18;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_74,(ThrowInfo *)&DAT_10012c80);
}



// Function: FUN_1000a6d0 at 1000a6d0

void FUN_1000a6d0(undefined2 *param_1,uint param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uStack_54;
  int *local_3c;
  undefined1 local_35;
  undefined4 local_34 [7];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e429;
  local_10 = ExceptionList;
  uStack_54 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_3c = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_18 = uStack_54;
  bVar2 = FUN_100096b0(&local_3c,param_2);
  piVar1 = local_3c;
  if (!bVar2) {
    local_35 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_35,(ThrowInfo *)&DAT_10012cf0);
  }
  puVar3 = (undefined4 *)FUN_10007d90(local_34,local_3c);
  local_8._0_1_ = 3;
  FUN_10009d20(param_1,puVar3);
  local_8._0_1_ = 2;
  FUN_10004b70(local_34);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(piVar1);
  local_8 = 0;
  FUN_1000a795();
  return;
}



// Function: Catch@1000a785 at 1000a785

undefined * Catch_1000a785(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000a792;
}



// Function: FUN_1000a795 at 1000a795

void FUN_1000a795(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000a7af;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000a7c0 at 1000a7c0

void __thiscall FUN_1000a7c0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)((int)this + 4);
  local_8 = this;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_1000a360(this,(int *)piVar2[1]);
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
      if (*(char *)((int)param_2 + 0x2d) == '\0') {
        piVar3 = (int *)param_2[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          param_2 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            param_2 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(param_2[1] + 0x2d);
          piVar4 = (int *)param_2[1];
          piVar3 = param_2;
          while ((param_2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_2[2]))) {
            cVar1 = *(char *)(param_2[1] + 0x2d);
            piVar4 = (int *)param_2[1];
            piVar3 = param_2;
          }
        }
      }
      FUN_1000a0f0(this,&local_8,piVar2);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000a880 at 1000a880

void __thiscall FUN_1000a880(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 < 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_1000a600(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_1000a8b0 at 1000a8b0

uint FUN_1000a8b0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  HRESULT HVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_2c [4];
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e490;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098e0(local_2c);
  local_1c = 0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar3 = CoCreateInstance((IID *)&DAT_10010f20,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10010f30,&local_18);
  FUN_1000a880(local_2c,HVar3);
  piVar1 = local_18;
  local_14 = (int *)0x0;
  local_8._0_1_ = 4;
  piVar4 = FUN_10009860((int *)&param_1,param_1);
  local_8._0_1_ = 5;
  iVar5 = (**(code **)(*piVar1 + 0x4c))(piVar1,*piVar4,&local_14,uVar2);
  FUN_1000a880(local_2c,iVar5);
  local_8._0_1_ = 4;
  Ordinal_6(param_1);
  (**(code **)(*local_14 + 0x4c))(local_14,&local_1c);
  param_1 = (undefined4 *)CONCAT13((short)local_1c == -1,param_1._0_3_);
  local_8._0_1_ = 2;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)(**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return CONCAT31((int3)((uint)local_18 >> 8),param_1._3_1_);
}



// Function: FUN_1000a9b0 at 1000a9b0

uint FUN_1000a9b0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  HRESULT HVar3;
  int *piVar4;
  int iVar5;
  short sVar6;
  undefined4 local_2c [4];
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e4f0;
  local_10 = ExceptionList;
  uVar2 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098e0(local_2c);
  sVar6 = 0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar3 = CoCreateInstance((IID *)&DAT_10010f20,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10010f30,&local_18);
  FUN_1000a880(local_2c,HVar3);
  piVar1 = local_18;
  local_14 = (int *)0x0;
  local_8._0_1_ = 4;
  piVar4 = FUN_10009860((int *)&param_1,param_1);
  local_8._0_1_ = 5;
  iVar5 = (**(code **)(*piVar1 + 0x4c))(piVar1,*piVar4,&local_14,uVar2);
  FUN_1000a880(local_2c,iVar5);
  local_8._0_1_ = 4;
  Ordinal_6(param_1);
  iVar5 = (**(code **)(*local_14 + 0x28))(local_14,&local_1c);
  FUN_1000a880(local_2c,iVar5);
  if (local_1c == 1) {
    sVar6 = -1;
  }
  param_1 = (undefined4 *)CONCAT13(sVar6 == -1,param_1._0_3_);
  local_8._0_1_ = 2;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)(**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return CONCAT31((int3)((uint)local_18 >> 8),param_1._3_1_);
}



// Function: FUN_1000aac0 at 1000aac0

void FUN_1000aac0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  HRESULT HVar3;
  undefined2 *this;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  undefined4 local_74 [4];
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e5b8;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098e0(local_74);
  local_64 = 0;
  local_54 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar3 = CoCreateInstance((IID *)&DAT_10010f20,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10010f30,&local_54);
  FUN_1000a880(local_74,HVar3);
  local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  FUN_100068f0(&local_30,param_1,0,0xffffffff);
  local_8._0_1_ = 3;
  this = FUN_10009c10(&local_30,(undefined2 *)local_4c,local_20 - 1,local_20);
  local_8._0_1_ = 4;
  puVar8 = DAT_100157e0;
  if (DAT_100157f4 < 8) {
    puVar8 = (ushort *)&DAT_100157e0;
  }
  uVar4 = FUN_100029c0(this,0,*(uint *)(this + 8),puVar8,DAT_100157f0);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  if (uVar4 != 0) {
    FUN_100060d0(&local_30,&DAT_100157e0,0,0xffffffff);
  }
  FUN_100060d0(&local_30,&DAT_100157fc,0,0xffffffff);
  piVar2 = local_54;
  local_5c = 0;
  if (local_1c < 8) {
    puVar7 = &local_30;
LAB_1000ad30:
    local_50 = (int *)Ordinal_2(puVar7);
    if (local_50 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  else {
    puVar7 = local_30;
    if (local_30 != (undefined4 *)0x0) goto LAB_1000ad30;
    local_50 = (int *)0x0;
  }
  piVar1 = local_50;
  local_8._0_1_ = 5;
  iVar5 = (**(code **)(*piVar2 + 0x44))(piVar2,local_50,&local_5c);
  FUN_1000a880(local_74,iVar5);
  local_8._0_1_ = 3;
  Ordinal_6(piVar1);
  piVar2 = local_54;
  local_50 = (int *)0x0;
  if ((short)local_5c != 0) {
    local_8._0_1_ = 0x10;
    if (local_1c < 8) {
      puVar7 = &local_30;
LAB_1000aec9:
      local_60 = Ordinal_2(puVar7);
      if (local_60 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
    }
    else {
      puVar7 = local_30;
      if (local_30 != (undefined4 *)0x0) goto LAB_1000aec9;
      local_60 = 0;
    }
    iVar5 = local_60;
    local_8._0_1_ = 0x11;
    iVar6 = (**(code **)(*piVar2 + 0x50))(piVar2,local_60,&local_50);
    FUN_1000a880(local_74,iVar6);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    Ordinal_6(iVar5);
    (**(code **)(*local_50 + 0x54))(local_50,0xffffffff);
    piVar2 = local_54;
    if (local_1c < 8) {
      puVar7 = &local_30;
LAB_1000aeea:
      local_60 = Ordinal_2(puVar7);
      if (local_60 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
    }
    else {
      puVar7 = local_30;
      if (local_30 != (undefined4 *)0x0) goto LAB_1000aeea;
      local_60 = 0;
    }
    iVar5 = local_60;
    local_8._0_1_ = 0x12;
    iVar6 = (**(code **)(*piVar2 + 0x44))(piVar2,local_60,&local_5c);
    FUN_1000a880(local_74,iVar6);
    local_8._0_1_ = 0x10;
    Ordinal_6(iVar5);
    if ((short)local_5c == 0) {
      local_64 = 0xffffffff;
    }
    goto LAB_1000ae4a;
  }
  local_8._0_1_ = 7;
  if (local_1c < 8) {
    puVar7 = &local_30;
LAB_1000ad51:
    local_58 = (int *)Ordinal_2(puVar7);
    if (local_58 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  else {
    puVar7 = local_30;
    if (local_30 != (undefined4 *)0x0) goto LAB_1000ad51;
    local_58 = (int *)0x0;
  }
  piVar1 = local_58;
  local_8._0_1_ = 8;
  iVar5 = (**(code **)(*piVar2 + 0x78))(piVar2,local_58,0,0,&local_50);
  FUN_1000a880(local_74,iVar5);
  local_8 = CONCAT31(local_8._1_3_,7);
  Ordinal_6(piVar1);
  piVar2 = local_54;
  if (local_1c < 8) {
    puVar7 = &local_30;
LAB_1000ad72:
    local_58 = (int *)Ordinal_2(puVar7);
    if (local_58 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  else {
    puVar7 = local_30;
    if (local_30 != (undefined4 *)0x0) goto LAB_1000ad72;
    local_58 = (int *)0x0;
  }
  piVar1 = local_58;
  local_8._0_1_ = 9;
  iVar5 = (**(code **)(*piVar2 + 0x44))(piVar2,local_58,&local_5c);
  FUN_1000a880(local_74,iVar5);
  local_8._0_1_ = 7;
  Ordinal_6(piVar1);
  piVar2 = local_54;
  if ((short)local_5c != -1) goto LAB_1000ae4a;
  local_64 = 0xffffffff;
  local_58 = (int *)0x0;
  local_8._0_1_ = 0xb;
  if (local_1c < 8) {
    puVar7 = &local_30;
LAB_1000ad93:
    local_60 = Ordinal_2(puVar7);
    if (local_60 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  else {
    puVar7 = local_30;
    if (local_30 != (undefined4 *)0x0) goto LAB_1000ad93;
    local_60 = 0;
  }
  iVar5 = local_60;
  local_8._0_1_ = 0xc;
  iVar6 = (**(code **)(*piVar2 + 0x50))(piVar2,local_60,&local_58);
  FUN_1000a880(local_74,iVar6);
  local_8._0_1_ = 0xb;
  Ordinal_6(iVar5);
  (**(code **)(*local_50 + 0x4c))(local_50);
  (**(code **)(*local_58 + 0x54))(local_58,0xffffffff);
  local_8._0_1_ = 7;
  if (local_58 != (int *)0x0) {
    (**(code **)(*local_58 + 8))(local_58);
  }
LAB_1000ae4a:
  local_8._0_1_ = 3;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))(local_50);
  }
  local_8._0_1_ = 2;
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (undefined4 *)((uint)local_30 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000af10 at 1000af10

void FUN_1000af10(undefined4 param_1,int *param_2,short *param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uStack_48;
  undefined4 local_34 [7];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e5e8;
  local_10 = ExceptionList;
  uStack_48 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = uStack_48;
  puVar1 = &uStack_48;
  if (param_3 != (short *)0x0) {
    local_8 = 0;
    puVar2 = (undefined4 *)FUN_10009da0((undefined2 *)local_34,param_2);
    local_8._0_1_ = 1;
    uVar3 = FUN_1000a8b0(puVar2);
    *param_3 = -(ushort)((uVar3 & 0xff) != 0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10004b70(local_34);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000afae at 1000afae

undefined4 Catch_1000afae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000af8d;
}



// Function: FUN_1000afd0 at 1000afd0

void FUN_1000afd0(undefined4 param_1,int *param_2,short *param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uStack_48;
  undefined4 local_34 [7];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e618;
  local_10 = ExceptionList;
  uStack_48 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = uStack_48;
  puVar1 = &uStack_48;
  if (param_3 != (short *)0x0) {
    local_8 = 0;
    puVar2 = (undefined4 *)FUN_10009da0((undefined2 *)local_34,param_2);
    local_8._0_1_ = 1;
    uVar3 = FUN_1000a9b0(puVar2);
    *param_3 = -(ushort)((uVar3 & 0xff) != 0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10004b70(local_34);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b06e at 1000b06e

undefined4 Catch_1000b06e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000b04d;
}



// Function: FUN_1000b090 at 1000b090

void FUN_1000b090(undefined4 param_1,int *param_2,short *param_3)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  uint uStack_48;
  undefined4 local_34 [7];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e648;
  local_10 = ExceptionList;
  uStack_48 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = uStack_48;
  puVar1 = &uStack_48;
  if (param_3 != (short *)0x0) {
    local_8 = 0;
    piVar3 = (int *)FUN_10009da0((undefined2 *)local_34,param_2);
    local_8._0_1_ = 1;
    cVar2 = FUN_1000aac0(piVar3);
    *param_3 = -(ushort)(cVar2 != '\0');
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10004b70(local_34);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b12e at 1000b12e

undefined4 Catch_1000b12e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000b10d;
}



// Function: FUN_1000b150 at 1000b150

/* WARNING: Removing unreachable block (ram,0x1000b1c4) */
/* WARNING: Removing unreachable block (ram,0x1000b1e8) */

void FUN_1000b150(int param_1,int *param_2,undefined2 *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  ushort *puVar6;
  LPCWSTR ****pppppWVar7;
  uint uVar8;
  LPCWSTR ****pppppWVar9;
  code *pcVar10;
  uint uStack_98;
  int local_84;
  int *local_80;
  int local_7c [2];
  undefined2 *local_74;
  int *local_70;
  undefined4 local_6c [7];
  LPCWSTR ***local_50 [4];
  undefined4 local_40;
  uint local_3c;
  LPCWSTR ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e6b0;
  local_10 = ExceptionList;
  uStack_98 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  local_80 = param_2;
  local_74 = param_3;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (LPCWSTR ***)((uint)local_34[0] & 0xffff0000);
  local_3c = 7;
  local_40 = 0;
  local_50[0] = (LPCWSTR ***)((uint)local_50[0] & 0xffff0000);
  local_18 = uStack_98;
  if (param_3 == (undefined2 *)0x0) {
    local_8 = 0xffffffff;
    puStack_c = &LAB_1000e6b0;
    local_3c = 7;
    local_40 = 0;
    local_20 = 7;
    local_24 = 0;
    local_14 = (undefined1 *)&uStack_98;
  }
  else {
    local_8._1_3_ = 0;
    local_70 = (int *)0x0;
    local_8._0_1_ = 3;
    ExceptionList = &local_10;
    iVar3 = Ordinal_2(&DAT_10010f88);
    local_84 = iVar3;
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
    local_8._0_1_ = 4;
    bVar1 = FUN_10009700(&local_84,(int)local_80);
    local_8._0_1_ = 3;
    Ordinal_6(iVar3);
    if (bVar1) {
      FUN_100096b0(&local_70,0x19);
      puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_6c,local_70);
      local_8._0_1_ = 5;
      FUN_10009d20(local_34,puVar4);
      local_8._0_1_ = 3;
      FUN_10004b70(local_6c);
      FUN_100096b0(&local_70,0xf);
      piVar5 = local_70;
      puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_6c,local_70);
      local_8._0_1_ = 6;
      FUN_10009d20(local_50,puVar4);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_10004b70(local_6c);
      pcVar10 = MessageBoxW_exref;
      pppppWVar9 = (LPCWSTR ****)local_50[0];
      if (local_3c < 8) {
        pppppWVar9 = local_50;
      }
      pppppWVar7 = (LPCWSTR ****)local_34[0];
      if (local_20 < 8) {
        pppppWVar7 = local_34;
      }
      iVar3 = MessageBoxW(*(HWND *)(param_1 + 0x10),(LPCWSTR)pppppWVar7,(LPCWSTR)pppppWVar9,1);
      *local_74 = 0;
    }
    else {
      local_7c[1] = 0x12;
      piVar5 = (int *)FUN_10009ad0((void *)(param_1 + 0x14),local_7c,local_7c + 1);
      if (*piVar5 != *(int *)(param_1 + 0x18)) {
        FUN_100068f0(local_34,(int *)(*piVar5 + 0x10),0,0xffffffff);
      }
      local_7c[0] = 0;
      piVar5 = (int *)FUN_10009ad0((void *)(param_1 + 0x14),local_7c + 1,local_7c);
      if (*piVar5 != *(int *)(param_1 + 0x18)) {
        FUN_100068f0(local_50,(int *)(*piVar5 + 0x10),0,0xffffffff);
      }
      puVar6 = DAT_10015834;
      if (DAT_10015848 < 8) {
        puVar6 = (ushort *)&DAT_10015834;
      }
      uVar8 = FUN_10003530(local_34,puVar6,0,DAT_10015844);
      piVar5 = (int *)FUN_10009da0((undefined2 *)local_6c,local_80);
      local_8._0_1_ = 7;
      FUN_100069f0(local_34,uVar8,DAT_10015844,piVar5,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_10004b70(local_6c);
      pcVar10 = MessageBoxW_exref;
      pppppWVar9 = (LPCWSTR ****)local_50[0];
      if (local_3c < 8) {
        pppppWVar9 = local_50;
      }
      pppppWVar7 = (LPCWSTR ****)local_34[0];
      if (local_20 < 8) {
        pppppWVar7 = local_34;
      }
      iVar3 = MessageBoxW(*(HWND *)(param_1 + 0x10),(LPCWSTR)pppppWVar7,(LPCWSTR)pppppWVar9,1);
      *local_74 = 0;
      piVar5 = local_70;
    }
    if (iVar3 == 1) {
      uVar8 = FUN_1000a8b0(&DAT_10015818);
      if ((((char)uVar8 == '\x01') && (uVar8 = FUN_1000a9b0(&DAT_10015818), (char)uVar8 != '\0')) &&
         (cVar2 = FUN_1000aac0(&DAT_10015818), cVar2 != '\0')) {
        *local_74 = 0xffff;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      Ordinal_6(piVar5);
      local_8 = 0;
      if (7 < local_3c) {
        operator_delete(local_50[0]);
      }
      local_3c = 7;
      local_40 = 0;
      local_50[0] = (LPCWSTR ***)((uint)local_50[0] & 0xffff0000);
      local_8 = 0xffffffff;
      if (7 < local_20) {
        operator_delete(local_34[0]);
      }
      local_20 = 7;
      local_24 = 0;
      local_34[0] = (LPCWSTR ***)((uint)local_34[0] & 0xffff0000);
    }
    else {
      puVar4 = (undefined4 *)FUN_1000a6d0((undefined2 *)local_6c,0x1f);
      local_8._0_1_ = 8;
      FUN_10009d20(local_34,puVar4);
      local_8._0_1_ = 3;
      FUN_10004b70(local_6c);
      pppppWVar9 = (LPCWSTR ****)local_50[0];
      if (local_3c < 8) {
        pppppWVar9 = local_50;
      }
      pppppWVar7 = (LPCWSTR ****)local_34[0];
      if (local_20 < 8) {
        pppppWVar7 = local_34;
      }
      (*pcVar10)(*(undefined4 *)(param_1 + 0x10),pppppWVar7,pppppWVar9,0);
      local_8._0_1_ = 2;
      Ordinal_6(piVar5);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10004b70(local_50);
      local_8 = 0xffffffff;
      FUN_10004b70(local_34);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b51f at 1000b51f

undefined4 Catch_1000b51f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000b4e1;
}



// Function: FUN_1000b530 at 1000b530

undefined4 FUN_1000b530(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  uint uStack_3c;
  undefined4 local_2c [4];
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e708;
  local_10 = ExceptionList;
  uStack_3c = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  FUN_100098e0(local_2c);
  piVar1 = param_3;
  if (param_3 == (int *)0x0) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_18 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  HVar2 = CoCreateInstance((IID *)&DAT_10010f20,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10010f30,&local_18);
  FUN_1000a880(local_2c,HVar2);
  param_3 = (int *)0x0;
  local_8._0_1_ = 5;
  iVar3 = (**(code **)(*local_18 + 0x4c))(local_18,param_2,&param_3);
  FUN_1000a880(local_2c,iVar3);
  iVar3 = (**(code **)(*param_3 + 0x34))(param_3,piVar1);
  FUN_1000a880(local_2c,iVar3);
  local_1c = 0;
  local_8._0_1_ = 3;
  FUN_10003060((int *)&param_3);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10003060((int *)&local_18);
  ExceptionList = local_10;
  return local_1c;
}



// Function: Catch@1000b636 at 1000b636

undefined4 Catch_1000b636(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000b618;
}



// Function: FUN_1000b650 at 1000b650

void __cdecl FUN_1000b650(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e754;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[6] = 7;
    param_2[5] = 0;
    *(undefined2 *)(param_2 + 1) = 0;
    FUN_10009d20(param_2 + 1,param_3 + 1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b6d0 at 1000b6d0

void __fastcall FUN_1000b6d0(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e778;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000a7c0(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b740 at 1000b740

undefined4 * __thiscall FUN_1000b740(void *this,char *param_1)

{
  undefined4 *puVar1;
  uint uStack_34;
  undefined **local_24 [3];
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e7a9;
  local_10 = ExceptionList;
  uStack_34 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0x30);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)((int)this + 4);
    puVar1[1] = *(undefined4 *)((int)this + 4);
    puVar1[2] = *(undefined4 *)((int)this + 4);
    *(undefined2 *)(puVar1 + 0xb) = 0;
    local_8 = 1;
    FUN_1000b650((int)this + 0xd,puVar1 + 3,(undefined4 *)param_1);
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_24,&param_1);
  local_24[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_24,(ThrowInfo *)&DAT_10011c24);
}



// Function: Catch@1000b7cf at 1000b7cf

void Catch_1000b7cf(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b820 at 1000b820

void __fastcall FUN_1000b820(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e7e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  local_14 = param_1;
  FUN_1000a7c0(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b890 at 1000b890

void __fastcall FUN_1000b890(int param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e81b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (void *)(param_1 + 0x14);
  local_8 = 2;
  FUN_1000a7c0(local_14,&local_18,(int *)**(int **)(param_1 + 0x18),*(int **)(param_1 + 0x18));
  local_8 = 0xffffffff;
  operator_delete(*(void **)(param_1 + 0x18));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b910 at 1000b910

void __fastcall FUN_1000b910(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *this;
  char cVar6;
  undefined **local_6c [3];
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int *local_54;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  char local_34 [4];
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eb3c;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  this = (int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_60 = param_1;
  local_54 = this;
  local_14 = uVar1;
  pvVar2 = operator_new(0x30);
  if (pvVar2 != (void *)0x0) {
    *(void **)(param_1 + 0x18) = pvVar2;
    *(void **)pvVar2 = pvVar2;
    *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);
    *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
    *(undefined1 *)(*(int *)(param_1 + 0x18) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x18) + 0x2d) = 1;
    local_54 = (int *)0x0;
    local_8 = 4;
    Ordinal_6(0,uVar1);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x15);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 5;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    local_34[0] = '\x03';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 8;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 5;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x9c59);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0xb;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x04';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0xe;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0xb;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x13);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x11;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x05';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x14;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x11;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x20);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x17;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x06';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x1a;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x17;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x22);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x1d;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\a';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x20;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x1d;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x21);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x23;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\b';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x26;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x23;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x12);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x29;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\v';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x2c;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x29;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x17);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x2f;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\f';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x32;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x2f;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x18);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x35;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\r';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x38;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x35;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x19);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x3b;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x0e';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x3e;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x3b;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x1b);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x41;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x0f';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x44;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x41;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    Ordinal_6(local_54);
    local_54 = (int *)0x0;
    puVar3 = (undefined2 *)FUN_10009510(0x1c);
    if (puVar3 == (undefined2 *)0x0) {
      local_54 = (int *)0x0;
    }
    else {
      local_54 = (int *)Ordinal_4(puVar3 + 1,*puVar3);
    }
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x47;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x10';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x4a;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x47;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8._0_1_ = 4;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    local_3c = 7;
    local_40 = 0;
    FUN_100096b0(&local_54,0x16);
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x4d;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x11';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x50;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x4d;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8._0_1_ = 4;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    local_3c = 7;
    local_40 = 0;
    FUN_100096b0(&local_54,0x1d);
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x53;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\x12';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x56;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x53;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8._0_1_ = 4;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    local_3c = 7;
    local_40 = 0;
    FUN_100096b0(&local_54,0xc);
    puVar4 = (undefined4 *)FUN_10009da0((undefined2 *)local_50,local_54);
    local_8._0_1_ = 0x59;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_34[0] = '\0';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_1c = 7;
    local_20 = 0;
    FUN_10009d20(&local_30,puVar4);
    local_8._0_1_ = 0x5c;
    cVar6 = '\0';
    piVar5 = FUN_1000b740(this,local_34);
    FUN_1000a3b0(this,&local_5c,piVar5,cVar6);
    local_8._0_1_ = 0x59;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffff0000);
    local_8._0_1_ = 4;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    *(undefined4 *)(local_60 + 0x10) = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    Ordinal_6(local_54);
    local_8 = 0xffffffff;
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_58 = (char *)0x0;
  std::exception::exception((exception *)local_6c,&local_58);
  local_6c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_6c,(ThrowInfo *)&DAT_10011c24);
}



// Function: FUN_1000c4d0 at 1000c4d0

void __thiscall FUN_1000c4d0(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_54;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  int local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eba0;
  local_10 = ExceptionList;
  local_14 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = *(int **)((int)this + 4);
  if (*(char *)(piVar3[1] + 0x2d) == '\0') {
    piVar2 = (int *)piVar3[1];
    do {
      if (piVar2[3] < *param_1) {
        piVar1 = (int *)piVar2[2];
      }
      else {
        piVar1 = (int *)*piVar2;
        piVar3 = piVar2;
      }
      piVar2 = piVar1;
    } while (*(char *)((int)piVar1 + 0x2d) == '\0');
  }
  if ((piVar3 == *(int **)((int)this + 4)) || (*param_1 < piVar3[3])) {
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
    local_8 = 0;
    local_34 = *param_1;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    FUN_10009d20(local_30,local_50);
    local_8._0_1_ = 3;
    piVar2 = FUN_1000b740(this,(char *)&local_34);
    FUN_1000a4a0(this,&local_54,piVar3,piVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    local_8 = 0xffffffff;
    if (7 < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 7;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffff0000);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c600 at 1000c600

void FUN_1000c600(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  void *this;
  uint uStack_48;
  undefined4 local_34 [7];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000ebd8;
  local_10 = ExceptionList;
  uStack_48 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_48;
  puVar1 = (undefined4 *)FUN_10009da0((undefined2 *)local_34,param_3);
  local_8._0_1_ = 1;
  this = (void *)FUN_1000c4d0((void *)(param_1 + 0x14),&param_2);
  FUN_10009d20(this,puVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004b70(local_34);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000c69d at 1000c69d

undefined4 Catch_1000c69d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c67c;
}



// Function: FUN_1000c6b0 at 1000c6b0

int __fastcall FUN_1000c6b0(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000c6d5 at 1000c6d5

void __fastcall FUN_1000c6d5(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 1000c6ed

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
LAB_1000c73b:
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
        goto LAB_1000c73b;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_1000c74a at 1000c74a

undefined4 * __fastcall FUN_1000c74a(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1000c6b0((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10011078;
  uVar1 = FUN_100014a0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_10015b98 = 1;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 1000c78a

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleInit(struct ATL::_ATL_WIN_MODULE70 *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long ATL::AtlWinModuleInit(_ATL_WIN_MODULE70 *param_1)

{
  uint uVar1;
  
  if ((param_1 == (_ATL_WIN_MODULE70 *)0x0) || (*(int *)param_1 != 0x2c)) {
    uVar1 = 0x80070057;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar1 = FUN_100014a0((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar1;
}



// Function: RemoveAll at 1000c7b2

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



// Function: FUN_1000c7d1 at 1000c7d1

int __fastcall FUN_1000c7d1(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 1000c7f6

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_1000c803:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_1000c803;
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



// Function: FUN_1000c86c at 1000c86c

_ATL_WIN_MODULE70 * __fastcall FUN_1000c86c(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_1000c7d1((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_10015b98 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_1000c894 at 1000c894

void __fastcall FUN_1000c894(int *param_1)

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



// Function: FUN_1000c8d8 at 1000c8d8

int __fastcall FUN_1000c8d8(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000c8f1 at 1000c8f1

undefined4 * __fastcall FUN_1000c8f1(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1000c8d8((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10013730;
  param_1[3] = &DAT_10013730;
  uVar1 = FUN_100014a0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_10015b98 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000c932 at 1000c932

void FUN_1000c932(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 1000c956

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10015b6c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000c965

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



// Function: __alloca_probe at 1000c9c0

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



// Function: `eh_vector_constructor_iterator' at 1000ca04

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
  FUN_1000ca51();
  return;
}



// Function: FUN_1000ca51 at 1000ca51

void FUN_1000ca51(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 1000ca69

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



// Function: `eh_vector_destructor_iterator' at 1000cac7

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
  FUN_1000cb12();
  return;
}



// Function: FUN_1000cb12 at 1000cb12

void FUN_1000cb12(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 1000cb36

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
  
  local_8 = &DAT_100136c8;
  uStack_c = 0x1000cb42;
  local_20[0] = DecodePointer(DAT_10016004);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10016004);
    local_24 = DecodePointer(DAT_10016000);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10016004 = EncodePointer(local_20[0]);
    DAT_10016000 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000cbce();
  }
  return p_Var1;
}



// Function: FUN_1000cbce at 1000cbce

void FUN_1000cbce(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000cbd7

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_1000cbee at 1000cbee

void __cdecl
FUN_1000cbee(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10015b6c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 1000cc20

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



// Function: __alloca_probe_8 at 1000cc36

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



// Function: __CRT_INIT@12 at 1000cc9e

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
    if (DAT_10015cc0 < 1) {
      return 0;
    }
    DAT_10015cc0 = DAT_10015cc0 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10015ff8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10015ff4 == 2) {
      param_2 = (int *)DecodePointer(DAT_10016004);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10016000);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10016004);
            piVar8 = (int *)DecodePointer(DAT_10016000);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10016000 = (PVOID)encoded_null();
        DAT_10016004 = DAT_10016000;
      }
      DAT_10015ff4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10015ff8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10015ff8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10015ff4 == 0) {
      DAT_10015ff4 = 1;
      iVar5 = initterm_e(&DAT_1001028c,&DAT_10010294);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100101b4,&DAT_10010288);
      DAT_10015ff4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10015ff8,0);
    }
    if ((DAT_10015ffc != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10015ffc), BVar2 != 0)) {
      (*DAT_10015ffc)(param_1,2,param_3);
    }
    DAT_10015cc0 = DAT_10015cc0 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000cea8

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000cf48) */
/* WARNING: Removing unreachable block (ram,0x1000cef5) */
/* WARNING: Removing unreachable block (ram,0x1000cf75) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10015b90 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10015cc0 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10009340(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10009340(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000cfb3();
  return local_20;
}



// Function: FUN_1000cfb3 at 1000cfb3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000cfb3(void)

{
  _DAT_10015b90 = 0xffffffff;
  return;
}



// Function: entry at 1000cfbe

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000cfe2

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
  
  _DAT_10015de0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10015de4 = &stack0x00000004;
  _DAT_10015d20 = 0x10001;
  _DAT_10015cc8 = 0xc0000409;
  _DAT_10015ccc = 1;
  local_32c = DAT_10015b6c;
  local_328 = DAT_10015b70;
  _DAT_10015cd4 = unaff_retaddr;
  _DAT_10015dac = in_GS;
  _DAT_10015db0 = in_FS;
  _DAT_10015db4 = in_ES;
  _DAT_10015db8 = in_DS;
  _DAT_10015dbc = unaff_EDI;
  _DAT_10015dc0 = unaff_ESI;
  _DAT_10015dc4 = unaff_EBX;
  _DAT_10015dc8 = in_EDX;
  _DAT_10015dcc = in_ECX;
  _DAT_10015dd0 = in_EAX;
  _DAT_10015dd4 = unaff_EBP;
  DAT_10015dd8 = unaff_retaddr;
  _DAT_10015ddc = in_CS;
  _DAT_10015de8 = in_SS;
  DAT_10015d18 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10011094);
  if (DAT_10015d18 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000d0f0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10015b6c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000d135

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



// Function: __ValidateImageBase at 1000d1c0

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



// Function: __FindPESection at 1000d200

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



// Function: __IsNonwritableInCurrentImage at 1000d250

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
  
  pcStack_10 = FUN_1000cbee;
  local_14 = ExceptionList;
  local_c = DAT_10015b6c ^ 0x10013710;
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



// Function: ___security_init_cookie at 1000d324

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
  if ((DAT_10015b6c == 0xbb40e64e) || ((DAT_10015b6c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10015b6c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10015b6c == 0xbb40e64e) {
      DAT_10015b6c = 0xbb40e64f;
    }
    else if ((DAT_10015b6c & 0xffff0000) == 0) {
      DAT_10015b6c = DAT_10015b6c | (DAT_10015b6c | 0x4711) << 0x10;
    }
    DAT_10015b70 = ~DAT_10015b6c;
  }
  else {
    DAT_10015b70 = ~DAT_10015b6c;
  }
  return;
}



// Function: Unwind@1000d3e0 at 1000d3e0

void Unwind_1000d3e0(void)

{
  int unaff_EBP;
  
  FUN_1000b890(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d410 at 1000d410

void Unwind_1000d410(void)

{
  DAT_10015be8 = DAT_10015be8 & 0xfffffffe;
  return;
}



// Function: Unwind@1000d440 at 1000d440

void Unwind_1000d440(void)

{
  int unaff_EBP;
  
  FUN_10001530(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d470 at 1000d470

void Unwind_1000d470(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000d473. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d4a0 at 1000d4a0

void Unwind_1000d4a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000d4a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d4d0 at 1000d4d0

void Unwind_1000d4d0(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d500 at 1000d500

void Unwind_1000d500(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000d503. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d550 at 1000d550

void Unwind_1000d550(void)

{
  int unaff_EBP;
  
  FUN_1000b890(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d580 at 1000d580

void Unwind_1000d580(void)

{
  int unaff_EBP;
  
  FUN_10002ac0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d5b0 at 1000d5b0

void Unwind_1000d5b0(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000d5f0 at 1000d5f0

void Unwind_1000d5f0(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d620 at 1000d620

void Unwind_1000d620(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1000d660 at 1000d660

void Unwind_1000d660(void)

{
  int unaff_EBP;
  
  FUN_10002450(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d690 at 1000d690

void Unwind_1000d690(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d69b at 1000d69b

void Unwind_1000d69b(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d6c0 at 1000d6c0

void Unwind_1000d6c0(void)

{
  int unaff_EBP;
  
  FUN_10002460((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d6cb at 1000d6cb

void Unwind_1000d6cb(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d6f0 at 1000d6f0

void Unwind_1000d6f0(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d6f8 at 1000d6f8

void Unwind_1000d6f8(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d700 at 1000d700

void Unwind_1000d700(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d708 at 1000d708

void Unwind_1000d708(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d710 at 1000d710

void Unwind_1000d710(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d718 at 1000d718

void Unwind_1000d718(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d740 at 1000d740

void Unwind_1000d740(void)

{
  int unaff_EBP;
  
  FUN_1000b890(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d748 at 1000d748

void Unwind_1000d748(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1000d770 at 1000d770

void Unwind_1000d770(void)

{
  int unaff_EBP;
  
  FUN_10001150(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1000d77b at 1000d77b

void Unwind_1000d77b(void)

{
  int unaff_EBP;
  
  FUN_1000b890(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7a0 at 1000d7a0

void Unwind_1000d7a0(void)

{
  int unaff_EBP;
  
  FUN_10002b10(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7a8 at 1000d7a8

void Unwind_1000d7a8(void)

{
  int unaff_EBP;
  
  FUN_10002ac0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7d0 at 1000d7d0

void Unwind_1000d7d0(void)

{
  int unaff_EBP;
  
  FUN_100033f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d800 at 1000d800

void Unwind_1000d800(void)

{
  int unaff_EBP;
  
  FUN_10003a40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d80b at 1000d80b

void Unwind_1000d80b(void)

{
  int unaff_EBP;
  
  FUN_100033f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d830 at 1000d830

void Unwind_1000d830(void)

{
  int unaff_EBP;
  
  FUN_10001af0(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1000d860 at 1000d860

void Unwind_1000d860(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d86b at 1000d86b

void Unwind_1000d86b(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d876 at 1000d876

void Unwind_1000d876(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d881 at 1000d881

void Unwind_1000d881(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d88c at 1000d88c

void Unwind_1000d88c(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d897 at 1000d897

void Unwind_1000d897(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000d8a2 at 1000d8a2

void Unwind_1000d8a2(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@1000d8ad at 1000d8ad

void Unwind_1000d8ad(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@1000d8b8 at 1000d8b8

void Unwind_1000d8b8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d8c3 at 1000d8c3

void Unwind_1000d8c3(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d900 at 1000d900

void Unwind_1000d900(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d908 at 1000d908

void Unwind_1000d908(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d910 at 1000d910

void Unwind_1000d910(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d918 at 1000d918

void Unwind_1000d918(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d940 at 1000d940

void Unwind_1000d940(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d94b at 1000d94b

void Unwind_1000d94b(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000d956 at 1000d956

void Unwind_1000d956(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000d961 at 1000d961

void Unwind_1000d961(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d96c at 1000d96c

void Unwind_1000d96c(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000d9a0 at 1000d9a0

void Unwind_1000d9a0(void)

{
  int unaff_EBP;
  
  FUN_100035f0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d9d0 at 1000d9d0

void Unwind_1000d9d0(void)

{
  int unaff_EBP;
  
  FUN_100034d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000d9db at 1000d9db

void Unwind_1000d9db(void)

{
  int unaff_EBP;
  
  FUN_10002460((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d9e6 at 1000d9e6

void Unwind_1000d9e6(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da10 at 1000da10

void Unwind_1000da10(void)

{
  int unaff_EBP;
  
  FUN_100034d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000da1b at 1000da1b

void Unwind_1000da1b(void)

{
  int unaff_EBP;
  
  FUN_10002460((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000da26 at 1000da26

void Unwind_1000da26(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da50 at 1000da50

void Unwind_1000da50(void)

{
  FUN_10002500();
  return;
}



// Function: Unwind@1000da69 at 1000da69

void Unwind_1000da69(void)

{
  FUN_10002500();
  return;
}



// Function: Unwind@1000dac0 at 1000dac0

void Unwind_1000dac0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000daf0 at 1000daf0

void Unwind_1000daf0(void)

{
  int unaff_EBP;
  
  FUN_100034a0((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000daf8 at 1000daf8

void Unwind_1000daf8(void)

{
  int unaff_EBP;
  
  FUN_100034a0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000db20 at 1000db20

void Unwind_1000db20(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db50 at 1000db50

void Unwind_1000db50(void)

{
  int unaff_EBP;
  
  FUN_100034c0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000db5b at 1000db5b

void Unwind_1000db5b(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1000db66 at 1000db66

void Unwind_1000db66(void)

{
  int unaff_EBP;
  
  FUN_100034c0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000dba0 at 1000dba0

void Unwind_1000dba0(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x2228));
  return;
}



// Function: Unwind@1000dbab at 1000dbab

void Unwind_1000dbab(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@1000dbb6 at 1000dbb6

void Unwind_1000dbb6(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1000dbc1 at 1000dbc1

void Unwind_1000dbc1(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@1000dbcc at 1000dbcc

void Unwind_1000dbcc(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@1000dc00 at 1000dc00

void Unwind_1000dc00(void)

{
  int unaff_EBP;
  
  FUN_100035f0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000dc30 at 1000dc30

void Unwind_1000dc30(void)

{
  int unaff_EBP;
  
  FUN_100035f0((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1000dc3b at 1000dc3b

void Unwind_1000dc3b(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000dc46 at 1000dc46

void Unwind_1000dc46(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000dc51 at 1000dc51

void Unwind_1000dc51(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000dc5c at 1000dc5c

void Unwind_1000dc5c(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000dc67 at 1000dc67

void Unwind_1000dc67(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000dc72 at 1000dc72

void Unwind_1000dc72(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000dc7d at 1000dc7d

void Unwind_1000dc7d(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000dc88 at 1000dc88

void Unwind_1000dc88(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000dc93 at 1000dc93

void Unwind_1000dc93(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000dc9e at 1000dc9e

void Unwind_1000dc9e(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000dce0 at 1000dce0

void Unwind_1000dce0(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dce8 at 1000dce8

void Unwind_1000dce8(void)

{
  int unaff_EBP;
  
  FUN_10002460((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000dcf3 at 1000dcf3

void Unwind_1000dcf3(void)

{
  int unaff_EBP;
  
  FUN_100034d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000dcfe at 1000dcfe

void Unwind_1000dcfe(void)

{
  int unaff_EBP;
  
  FUN_10004830(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd30 at 1000dd30

void Unwind_1000dd30(void)

{
  int unaff_EBP;
  
  FUN_10004830(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd38 at 1000dd38

void Unwind_1000dd38(void)

{
  int unaff_EBP;
  
  FUN_100034d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000dd43 at 1000dd43

void Unwind_1000dd43(void)

{
  int unaff_EBP;
  
  FUN_10002460((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dd4e at 1000dd4e

void Unwind_1000dd4e(void)

{
  int unaff_EBP;
  
  FUN_100014d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd80 at 1000dd80

void Unwind_1000dd80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ddb0 at 1000ddb0

void Unwind_1000ddb0(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1000ddbb at 1000ddbb

void Unwind_1000ddbb(void)

{
  int unaff_EBP;
  
  FUN_100034c0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000ddf0 at 1000ddf0

void Unwind_1000ddf0(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000de20 at 1000de20

void Unwind_1000de20(void)

{
  int unaff_EBP;
  
  FUN_100033f0(*(undefined4 **)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1000de2b at 1000de2b

void Unwind_1000de2b(void)

{
  int unaff_EBP;
  
  FUN_10003a40((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000de36 at 1000de36

void Unwind_1000de36(void)

{
  int unaff_EBP;
  
  FUN_10003ac0((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000de41 at 1000de41

void Unwind_1000de41(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1000de4c at 1000de4c

void Unwind_1000de4c(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000de80 at 1000de80

void Unwind_1000de80(void)

{
  int unaff_EBP;
  
  FUN_100033f0(*(undefined4 **)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000de8b at 1000de8b

void Unwind_1000de8b(void)

{
  int unaff_EBP;
  
  FUN_10003a40((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000de96 at 1000de96

void Unwind_1000de96(void)

{
  int unaff_EBP;
  
  FUN_10003ac0((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000dea1 at 1000dea1

void Unwind_1000dea1(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000deac at 1000deac

void Unwind_1000deac(void)

{
  int unaff_EBP;
  
  FUN_10002420((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000dee0 at 1000dee0

void Unwind_1000dee0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000dee8 at 1000dee8

void Unwind_1000dee8(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000df20 at 1000df20

void Unwind_1000df20(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x488));
  return;
}



// Function: Unwind@1000df2b at 1000df2b

void Unwind_1000df2b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1000df36 at 1000df36

void Unwind_1000df36(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@1000df41 at 1000df41

void Unwind_1000df41(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x494));
  return;
}



// Function: Unwind@1000df4c at 1000df4c

void Unwind_1000df4c(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x458));
  return;
}



// Function: Unwind@1000df80 at 1000df80

void Unwind_1000df80(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000df88 at 1000df88

void Unwind_1000df88(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1000df93 at 1000df93

void Unwind_1000df93(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000df9b at 1000df9b

void Unwind_1000df9b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000dfa3 at 1000dfa3

void Unwind_1000dfa3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1000dfab at 1000dfab

void Unwind_1000dfab(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1000dfe0 at 1000dfe0

void Unwind_1000dfe0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e010 at 1000e010

void Unwind_1000e010(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@1000e01b at 1000e01b

void Unwind_1000e01b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1000e050 at 1000e050

void Unwind_1000e050(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@1000e05b at 1000e05b

void Unwind_1000e05b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@1000e066 at 1000e066

void Unwind_1000e066(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1000e0a0 at 1000e0a0

void Unwind_1000e0a0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e0d0 at 1000e0d0

void Unwind_1000e0d0(void)

{
  int unaff_EBP;
  
  FUN_10002b90((undefined4 *)(unaff_EBP + -0x44c));
  return;
}



// Function: Unwind@1000e0db at 1000e0db

void Unwind_1000e0db(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1000e110 at 1000e110

void Unwind_1000e110(void)

{
  FUN_10002ac0(0x10015bec);
  return;
}



// Function: Unwind@1000e11a at 1000e11a

void Unwind_1000e11a(void)

{
  FUN_10002b10(0x10015bec);
  return;
}



// Function: Unwind@1000e140 at 1000e140

void Unwind_1000e140(void)

{
  FUN_10002b10(0x10015bec);
  return;
}



// Function: Unwind@1000e14a at 1000e14a

void Unwind_1000e14a(void)

{
  FUN_10002ac0(0x10015bec);
  return;
}



// Function: Unwind@1000e1b0 at 1000e1b0

void Unwind_1000e1b0(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000e1e0 at 1000e1e0

void Unwind_1000e1e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001530(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e220 at 1000e220

void Unwind_1000e220(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e250 at 1000e250

void Unwind_1000e250(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000e280 at 1000e280

void Unwind_1000e280(void)

{
  int unaff_EBP;
  
  FUN_10009900(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e288 at 1000e288

void Unwind_1000e288(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e2b0 at 1000e2b0

void Unwind_1000e2b0(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000e2e0 at 1000e2e0

void Unwind_1000e2e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004b70(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e320 at 1000e320

void Unwind_1000e320(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000e350 at 1000e350

void Unwind_1000e350(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004b70(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e390 at 1000e390

void Unwind_1000e390(void)

{
  int unaff_EBP;
  
  FUN_10009900(*(int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000e398 at 1000e398

void Unwind_1000e398(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
  return;
}



// Function: Unwind@1000e3c0 at 1000e3c0

void Unwind_1000e3c0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e3c8 at 1000e3c8

void Unwind_1000e3c8(void)

{
  int unaff_EBP;
  
  FUN_10009970((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000e3d0 at 1000e3d0

void Unwind_1000e3d0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1000e400 at 1000e400

void Unwind_1000e400(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    FUN_10004b70(*(undefined4 **)(unaff_EBP + -0x40));
    return;
  }
  return;
}



// Function: Unwind@1000e419 at 1000e419

void Unwind_1000e419(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000e421 at 1000e421

void Unwind_1000e421(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e450 at 1000e450

void Unwind_1000e450(void)

{
  int unaff_EBP;
  
  FUN_10009610((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000e458 at 1000e458

void Unwind_1000e458(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e460 at 1000e460

void Unwind_1000e460(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e468 at 1000e468

void Unwind_1000e468(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e470 at 1000e470

void Unwind_1000e470(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e478 at 1000e478

void Unwind_1000e478(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000e480 at 1000e480

void Unwind_1000e480(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e488 at 1000e488

void Unwind_1000e488(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e4b0 at 1000e4b0

void Unwind_1000e4b0(void)

{
  int unaff_EBP;
  
  FUN_10009610((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000e4b8 at 1000e4b8

void Unwind_1000e4b8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e4c0 at 1000e4c0

void Unwind_1000e4c0(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e4c8 at 1000e4c8

void Unwind_1000e4c8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e4d0 at 1000e4d0

void Unwind_1000e4d0(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e4d8 at 1000e4d8

void Unwind_1000e4d8(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000e4e0 at 1000e4e0

void Unwind_1000e4e0(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e4e8 at 1000e4e8

void Unwind_1000e4e8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e510 at 1000e510

void Unwind_1000e510(void)

{
  int unaff_EBP;
  
  FUN_10009610((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1000e518 at 1000e518

void Unwind_1000e518(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e520 at 1000e520

void Unwind_1000e520(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e528 at 1000e528

void Unwind_1000e528(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e530 at 1000e530

void Unwind_1000e530(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000e538 at 1000e538

void Unwind_1000e538(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e540 at 1000e540

void Unwind_1000e540(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e548 at 1000e548

void Unwind_1000e548(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e550 at 1000e550

void Unwind_1000e550(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000e558 at 1000e558

void Unwind_1000e558(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000e560 at 1000e560

void Unwind_1000e560(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000e568 at 1000e568

void Unwind_1000e568(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000e570 at 1000e570

void Unwind_1000e570(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1000e578 at 1000e578

void Unwind_1000e578(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000e580 at 1000e580

void Unwind_1000e580(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e588 at 1000e588

void Unwind_1000e588(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e590 at 1000e590

void Unwind_1000e590(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e598 at 1000e598

void Unwind_1000e598(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1000e5a0 at 1000e5a0

void Unwind_1000e5a0(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1000e5a8 at 1000e5a8

void Unwind_1000e5a8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e5b0 at 1000e5b0

void Unwind_1000e5b0(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e5e0 at 1000e5e0

void Unwind_1000e5e0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e610 at 1000e610

void Unwind_1000e610(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e640 at 1000e640

void Unwind_1000e640(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e670 at 1000e670

void Unwind_1000e670(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000e678 at 1000e678

void Unwind_1000e678(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e680 at 1000e680

void Unwind_1000e680(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1000e688 at 1000e688

void Unwind_1000e688(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1000e690 at 1000e690

void Unwind_1000e690(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000e698 at 1000e698

void Unwind_1000e698(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000e6a0 at 1000e6a0

void Unwind_1000e6a0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000e6a8 at 1000e6a8

void Unwind_1000e6a8(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000e6e0 at 1000e6e0

void Unwind_1000e6e0(void)

{
  int unaff_EBP;
  
  FUN_10009610((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000e6e8 at 1000e6e8

void Unwind_1000e6e8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6f0 at 1000e6f0

void Unwind_1000e6f0(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6f8 at 1000e6f8

void Unwind_1000e6f8(void)

{
  int unaff_EBP;
  
  FUN_10002450((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000e700 at 1000e700

void Unwind_1000e700(void)

{
  int unaff_EBP;
  
  FUN_10003060((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000e730 at 1000e730

void Unwind_1000e730(void)

{
  FUN_10002500();
  return;
}



// Function: Unwind@1000e741 at 1000e741

void Unwind_1000e741(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e74c at 1000e74c

void Unwind_1000e74c(void)

{
  int unaff_EBP;
  
  FUN_10009900(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e770 at 1000e770

void Unwind_1000e770(void)

{
  int unaff_EBP;
  
  FUN_10009790(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e7a0 at 1000e7a0

void Unwind_1000e7a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e7a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000e7d0 at 1000e7d0

void Unwind_1000e7d0(void)

{
  int unaff_EBP;
  
  FUN_1000b6d0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e7d8 at 1000e7d8

void Unwind_1000e7d8(void)

{
  int unaff_EBP;
  
  FUN_10009790(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e800 at 1000e800

void Unwind_1000e800(void)

{
  int unaff_EBP;
  
  FUN_1000b820((void *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000e80b at 1000e80b

void Unwind_1000e80b(void)

{
  int unaff_EBP;
  
  FUN_1000b6d0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e813 at 1000e813

void Unwind_1000e813(void)

{
  int unaff_EBP;
  
  FUN_10009790(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e840 at 1000e840

void Unwind_1000e840(void)

{
  int unaff_EBP;
  
  FUN_10009790(*(int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e848 at 1000e848

void Unwind_1000e848(void)

{
  int unaff_EBP;
  
  FUN_1000b6d0(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e850 at 1000e850

void Unwind_1000e850(void)

{
  int unaff_EBP;
  
  FUN_1000b820((void *)(*(int *)(unaff_EBP + -0x5c) + 0x14));
  return;
}



// Function: Unwind@1000e85b at 1000e85b

void Unwind_1000e85b(void)

{
  int unaff_EBP;
  
  FUN_10001530((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000e863 at 1000e863

void Unwind_1000e863(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e86b at 1000e86b

void Unwind_1000e86b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e873 at 1000e873

void Unwind_1000e873(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e87b at 1000e87b

void Unwind_1000e87b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e883 at 1000e883

void Unwind_1000e883(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e88b at 1000e88b

void Unwind_1000e88b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e893 at 1000e893

void Unwind_1000e893(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e89b at 1000e89b

void Unwind_1000e89b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e8a3 at 1000e8a3

void Unwind_1000e8a3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8ab at 1000e8ab

void Unwind_1000e8ab(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8b3 at 1000e8b3

void Unwind_1000e8b3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8bb at 1000e8bb

void Unwind_1000e8bb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e8c3 at 1000e8c3

void Unwind_1000e8c3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e8cb at 1000e8cb

void Unwind_1000e8cb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e8d3 at 1000e8d3

void Unwind_1000e8d3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8db at 1000e8db

void Unwind_1000e8db(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8e3 at 1000e8e3

void Unwind_1000e8e3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e8eb at 1000e8eb

void Unwind_1000e8eb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e8f3 at 1000e8f3

void Unwind_1000e8f3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e8fb at 1000e8fb

void Unwind_1000e8fb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e903 at 1000e903

void Unwind_1000e903(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e90b at 1000e90b

void Unwind_1000e90b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e913 at 1000e913

void Unwind_1000e913(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e91b at 1000e91b

void Unwind_1000e91b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e923 at 1000e923

void Unwind_1000e923(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e92b at 1000e92b

void Unwind_1000e92b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e933 at 1000e933

void Unwind_1000e933(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e93b at 1000e93b

void Unwind_1000e93b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e943 at 1000e943

void Unwind_1000e943(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e94b at 1000e94b

void Unwind_1000e94b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e953 at 1000e953

void Unwind_1000e953(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e95b at 1000e95b

void Unwind_1000e95b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e963 at 1000e963

void Unwind_1000e963(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e96b at 1000e96b

void Unwind_1000e96b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e973 at 1000e973

void Unwind_1000e973(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e97b at 1000e97b

void Unwind_1000e97b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e983 at 1000e983

void Unwind_1000e983(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e98b at 1000e98b

void Unwind_1000e98b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e993 at 1000e993

void Unwind_1000e993(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e99b at 1000e99b

void Unwind_1000e99b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9a3 at 1000e9a3

void Unwind_1000e9a3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9ab at 1000e9ab

void Unwind_1000e9ab(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e9b3 at 1000e9b3

void Unwind_1000e9b3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e9bb at 1000e9bb

void Unwind_1000e9bb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e9c3 at 1000e9c3

void Unwind_1000e9c3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9cb at 1000e9cb

void Unwind_1000e9cb(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9d3 at 1000e9d3

void Unwind_1000e9d3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9db at 1000e9db

void Unwind_1000e9db(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e9e3 at 1000e9e3

void Unwind_1000e9e3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000e9eb at 1000e9eb

void Unwind_1000e9eb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e9f3 at 1000e9f3

void Unwind_1000e9f3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000e9fb at 1000e9fb

void Unwind_1000e9fb(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea03 at 1000ea03

void Unwind_1000ea03(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea0b at 1000ea0b

void Unwind_1000ea0b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea13 at 1000ea13

void Unwind_1000ea13(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000ea1b at 1000ea1b

void Unwind_1000ea1b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea23 at 1000ea23

void Unwind_1000ea23(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea2b at 1000ea2b

void Unwind_1000ea2b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea33 at 1000ea33

void Unwind_1000ea33(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea3b at 1000ea3b

void Unwind_1000ea3b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea43 at 1000ea43

void Unwind_1000ea43(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000ea4b at 1000ea4b

void Unwind_1000ea4b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea53 at 1000ea53

void Unwind_1000ea53(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea5b at 1000ea5b

void Unwind_1000ea5b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea63 at 1000ea63

void Unwind_1000ea63(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea6b at 1000ea6b

void Unwind_1000ea6b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea73 at 1000ea73

void Unwind_1000ea73(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000ea7b at 1000ea7b

void Unwind_1000ea7b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea83 at 1000ea83

void Unwind_1000ea83(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea8b at 1000ea8b

void Unwind_1000ea8b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea93 at 1000ea93

void Unwind_1000ea93(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000ea9b at 1000ea9b

void Unwind_1000ea9b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eaa3 at 1000eaa3

void Unwind_1000eaa3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000eaab at 1000eaab

void Unwind_1000eaab(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eab3 at 1000eab3

void Unwind_1000eab3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eabb at 1000eabb

void Unwind_1000eabb(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eac3 at 1000eac3

void Unwind_1000eac3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eacb at 1000eacb

void Unwind_1000eacb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ead3 at 1000ead3

void Unwind_1000ead3(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000eadb at 1000eadb

void Unwind_1000eadb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eae3 at 1000eae3

void Unwind_1000eae3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eaeb at 1000eaeb

void Unwind_1000eaeb(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eaf3 at 1000eaf3

void Unwind_1000eaf3(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eafb at 1000eafb

void Unwind_1000eafb(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eb03 at 1000eb03

void Unwind_1000eb03(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000eb0b at 1000eb0b

void Unwind_1000eb0b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eb13 at 1000eb13

void Unwind_1000eb13(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb1b at 1000eb1b

void Unwind_1000eb1b(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb23 at 1000eb23

void Unwind_1000eb23(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb2b at 1000eb2b

void Unwind_1000eb2b(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eb33 at 1000eb33

void Unwind_1000eb33(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eb36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000eb70 at 1000eb70

void Unwind_1000eb70(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000eb78 at 1000eb78

void Unwind_1000eb78(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eb80 at 1000eb80

void Unwind_1000eb80(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb88 at 1000eb88

void Unwind_1000eb88(void)

{
  int unaff_EBP;
  
  FUN_10009a60(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb90 at 1000eb90

void Unwind_1000eb90(void)

{
  int unaff_EBP;
  
  FUN_10009900(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000eb98 at 1000eb98

void Unwind_1000eb98(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ebd0 at 1000ebd0

void Unwind_1000ebd0(void)

{
  int unaff_EBP;
  
  FUN_10004b70((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: FUN_1000ec00 at 1000ec00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ec00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e124;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002a50(0x10015bec);
  _DAT_10015bec = ATL::CComModule::vftable;
  _DAT_10015bbc = &DAT_10015bec;
  local_8 = 0xffffffff;
  _atexit(FUN_1000f310);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f310 at 1000f310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f310(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e154;
  local_10 = ExceptionList;
  uVar1 = DAT_10015b6c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_10015bec = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_10015bf0 != 0) {
    if (DAT_10015bf8 != 0) {
      FUN_10002240(0x10015bf0);
      DAT_10015bf8 = 0;
    }
    if (DAT_10015c14 != (int *)0x0) {
      (**(code **)(*DAT_10015c14 + 8))(DAT_10015c14,uVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_10015bfc);
    DAT_10015bf0 = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f3a0 at 1000f3a0

void FUN_1000f3a0(void)

{
  Ordinal_6(DAT_10015c1c);
  return;
}



// Function: FUN_1000f3b0 at 1000f3b0

void FUN_1000f3b0(void)

{
  Ordinal_6(DAT_10015c20);
  return;
}



// Function: FUN_1000f3c0 at 1000f3c0

void FUN_1000f3c0(void)

{
  Ordinal_6(DAT_10015c24);
  return;
}



// Function: FUN_1000f3d0 at 1000f3d0

void FUN_1000f3d0(void)

{
  if (7 < DAT_100157f4) {
    operator_delete(DAT_100157e0);
  }
  DAT_100157f4 = 7;
  DAT_100157f0 = 0;
  DAT_100157e0 = (void *)((uint)DAT_100157e0 & 0xffff0000);
  return;
}



// Function: FUN_1000f410 at 1000f410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f410(void)

{
  if (7 < DAT_10015810) {
    operator_delete(DAT_100157fc);
  }
  DAT_10015810 = 7;
  _DAT_1001580c = 0;
  DAT_100157fc = (void *)((uint)DAT_100157fc & 0xffff0000);
  return;
}



// Function: FUN_1000f450 at 1000f450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f450(void)

{
  if (7 < DAT_1001582c) {
    operator_delete(DAT_10015818);
  }
  DAT_1001582c = 7;
  _DAT_10015828 = 0;
  DAT_10015818 = (void *)((uint)DAT_10015818 & 0xffff0000);
  return;
}



// Function: FUN_1000f490 at 1000f490

void FUN_1000f490(void)

{
  if (7 < DAT_10015848) {
    operator_delete(DAT_10015834);
  }
  DAT_10015848 = 7;
  DAT_10015844 = 0;
  DAT_10015834 = (void *)((uint)DAT_10015834 & 0xffff0000);
  return;
}



// Function: FUN_1000f4d0 at 1000f4d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f4d0(void)

{
  if (7 < DAT_10015618) {
    operator_delete(DAT_10015604);
  }
  DAT_10015618 = 7;
  _DAT_10015614 = 0;
  DAT_10015604 = (void *)((uint)DAT_10015604 & 0xffff0000);
  return;
}



// Function: FUN_1000f510 at 1000f510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f510(void)

{
  if (7 < DAT_10015634) {
    operator_delete(DAT_10015620);
  }
  DAT_10015634 = 7;
  _DAT_10015630 = 0;
  DAT_10015620 = (void *)((uint)DAT_10015620 & 0xffff0000);
  return;
}



// Function: FUN_1000f550 at 1000f550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f550(void)

{
  if (7 < DAT_10015650) {
    operator_delete(DAT_1001563c);
  }
  DAT_10015650 = 7;
  _DAT_1001564c = 0;
  DAT_1001563c = (void *)((uint)DAT_1001563c & 0xffff0000);
  return;
}



// Function: FUN_1000f590 at 1000f590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f590(void)

{
  if (7 < DAT_1001566c) {
    operator_delete(DAT_10015658);
  }
  DAT_1001566c = 7;
  _DAT_10015668 = 0;
  DAT_10015658 = (void *)((uint)DAT_10015658 & 0xffff0000);
  return;
}



// Function: FUN_1000f5d0 at 1000f5d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f5d0(void)

{
  if (7 < DAT_10015688) {
    operator_delete(DAT_10015674);
  }
  DAT_10015688 = 7;
  _DAT_10015684 = 0;
  DAT_10015674 = (void *)((uint)DAT_10015674 & 0xffff0000);
  return;
}



// Function: FUN_1000f610 at 1000f610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f610(void)

{
  if (7 < DAT_100156a4) {
    operator_delete(DAT_10015690);
  }
  DAT_100156a4 = 7;
  _DAT_100156a0 = 0;
  DAT_10015690 = (void *)((uint)DAT_10015690 & 0xffff0000);
  return;
}



// Function: FUN_1000f650 at 1000f650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f650(void)

{
  if (7 < DAT_100156c0) {
    operator_delete(DAT_100156ac);
  }
  DAT_100156c0 = 7;
  _DAT_100156bc = 0;
  DAT_100156ac = (void *)((uint)DAT_100156ac & 0xffff0000);
  return;
}



// Function: FUN_1000f690 at 1000f690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f690(void)

{
  if (7 < DAT_100156dc) {
    operator_delete(DAT_100156c8);
  }
  DAT_100156dc = 7;
  _DAT_100156d8 = 0;
  DAT_100156c8 = (void *)((uint)DAT_100156c8 & 0xffff0000);
  return;
}



// Function: FUN_1000f6d0 at 1000f6d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f6d0(void)

{
  if (7 < DAT_100156f8) {
    operator_delete(DAT_100156e4);
  }
  DAT_100156f8 = 7;
  _DAT_100156f4 = 0;
  DAT_100156e4 = (void *)((uint)DAT_100156e4 & 0xffff0000);
  return;
}



// Function: FUN_1000f710 at 1000f710

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f710(void)

{
  if (7 < DAT_10015714) {
    operator_delete(DAT_10015700);
  }
  DAT_10015714 = 7;
  _DAT_10015710 = 0;
  DAT_10015700 = (void *)((uint)DAT_10015700 & 0xffff0000);
  return;
}



// Function: FUN_1000f750 at 1000f750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f750(void)

{
  if (7 < DAT_10015730) {
    operator_delete(DAT_1001571c);
  }
  DAT_10015730 = 7;
  _DAT_1001572c = 0;
  DAT_1001571c = (void *)((uint)DAT_1001571c & 0xffff0000);
  return;
}



// Function: FUN_1000f790 at 1000f790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f790(void)

{
  if (7 < DAT_1001574c) {
    operator_delete(DAT_10015738);
  }
  DAT_1001574c = 7;
  _DAT_10015748 = 0;
  DAT_10015738 = (void *)((uint)DAT_10015738 & 0xffff0000);
  return;
}



// Function: FUN_1000f7d0 at 1000f7d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f7d0(void)

{
  if (7 < DAT_10015768) {
    operator_delete(DAT_10015754);
  }
  DAT_10015768 = 7;
  _DAT_10015764 = 0;
  DAT_10015754 = (void *)((uint)DAT_10015754 & 0xffff0000);
  return;
}



// Function: FUN_1000f810 at 1000f810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f810(void)

{
  if (7 < DAT_10015784) {
    operator_delete(DAT_10015770);
  }
  DAT_10015784 = 7;
  _DAT_10015780 = 0;
  DAT_10015770 = (void *)((uint)DAT_10015770 & 0xffff0000);
  return;
}



// Function: FUN_1000f850 at 1000f850

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f850(void)

{
  if (7 < DAT_100157a0) {
    operator_delete(DAT_1001578c);
  }
  DAT_100157a0 = 7;
  _DAT_1001579c = 0;
  DAT_1001578c = (void *)((uint)DAT_1001578c & 0xffff0000);
  return;
}



// Function: FUN_1000f890 at 1000f890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f890(void)

{
  if (7 < DAT_100157bc) {
    operator_delete(DAT_100157a8);
  }
  DAT_100157bc = 7;
  _DAT_100157b8 = 0;
  DAT_100157a8 = (void *)((uint)DAT_100157a8 & 0xffff0000);
  return;
}



// Function: FUN_1000f8d0 at 1000f8d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f8d0(void)

{
  if (7 < DAT_100157d8) {
    operator_delete(DAT_100157c4);
  }
  DAT_100157d8 = 7;
  _DAT_100157d4 = 0;
  DAT_100157c4 = (void *)((uint)DAT_100157c4 & 0xffff0000);
  return;
}



// Function: FUN_1000f910 at 1000f910

void FUN_1000f910(void)

{
  Ordinal_6(DAT_10015c28);
  return;
}



// Function: FUN_1000f920 at 1000f920

void FUN_1000f920(void)

{
  Ordinal_6(DAT_10015c2c);
  return;
}



// Function: FUN_1000f930 at 1000f930

void FUN_1000f930(void)

{
  Ordinal_6(DAT_10015c30);
  return;
}



// Function: FUN_1000f940 at 1000f940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f940(void)

{
  if (7 < DAT_10015934) {
    operator_delete(DAT_10015920);
  }
  DAT_10015934 = 7;
  _DAT_10015930 = 0;
  DAT_10015920 = (void *)((uint)DAT_10015920 & 0xffff0000);
  return;
}



// Function: FUN_1000f980 at 1000f980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f980(void)

{
  if (7 < DAT_10015950) {
    operator_delete(DAT_1001593c);
  }
  DAT_10015950 = 7;
  _DAT_1001594c = 0;
  DAT_1001593c = (void *)((uint)DAT_1001593c & 0xffff0000);
  return;
}



// Function: FUN_1000f9c0 at 1000f9c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f9c0(void)

{
  if (7 < DAT_1001596c) {
    operator_delete(DAT_10015958);
  }
  DAT_1001596c = 7;
  _DAT_10015968 = 0;
  DAT_10015958 = (void *)((uint)DAT_10015958 & 0xffff0000);
  return;
}



// Function: FUN_1000fa00 at 1000fa00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fa00(void)

{
  if (7 < DAT_10015988) {
    operator_delete(DAT_10015974);
  }
  DAT_10015988 = 7;
  _DAT_10015984 = 0;
  DAT_10015974 = (void *)((uint)DAT_10015974 & 0xffff0000);
  return;
}



// Function: FUN_1000fa40 at 1000fa40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fa40(void)

{
  if (7 < DAT_100159a4) {
    operator_delete(DAT_10015990);
  }
  DAT_100159a4 = 7;
  _DAT_100159a0 = 0;
  DAT_10015990 = (void *)((uint)DAT_10015990 & 0xffff0000);
  return;
}



// Function: FUN_1000fa80 at 1000fa80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fa80(void)

{
  if (7 < DAT_100159c0) {
    operator_delete(DAT_100159ac);
  }
  DAT_100159c0 = 7;
  _DAT_100159bc = 0;
  DAT_100159ac = (void *)((uint)DAT_100159ac & 0xffff0000);
  return;
}



// Function: FUN_1000fac0 at 1000fac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fac0(void)

{
  if (7 < DAT_100159dc) {
    operator_delete(DAT_100159c8);
  }
  DAT_100159dc = 7;
  _DAT_100159d8 = 0;
  DAT_100159c8 = (void *)((uint)DAT_100159c8 & 0xffff0000);
  return;
}



// Function: FUN_1000fb00 at 1000fb00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fb00(void)

{
  if (7 < DAT_100159f8) {
    operator_delete(DAT_100159e4);
  }
  DAT_100159f8 = 7;
  _DAT_100159f4 = 0;
  DAT_100159e4 = (void *)((uint)DAT_100159e4 & 0xffff0000);
  return;
}



// Function: FUN_1000fb40 at 1000fb40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fb40(void)

{
  if (7 < DAT_10015a14) {
    operator_delete(DAT_10015a00);
  }
  DAT_10015a14 = 7;
  _DAT_10015a10 = 0;
  DAT_10015a00 = (void *)((uint)DAT_10015a00 & 0xffff0000);
  return;
}



// Function: FUN_1000fb80 at 1000fb80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fb80(void)

{
  if (7 < DAT_10015a30) {
    operator_delete(DAT_10015a1c);
  }
  DAT_10015a30 = 7;
  _DAT_10015a2c = 0;
  DAT_10015a1c = (void *)((uint)DAT_10015a1c & 0xffff0000);
  return;
}



// Function: FUN_1000fbc0 at 1000fbc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fbc0(void)

{
  if (7 < DAT_10015a4c) {
    operator_delete(DAT_10015a38);
  }
  DAT_10015a4c = 7;
  _DAT_10015a48 = 0;
  DAT_10015a38 = (void *)((uint)DAT_10015a38 & 0xffff0000);
  return;
}



// Function: FUN_1000fc00 at 1000fc00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fc00(void)

{
  if (7 < DAT_10015a68) {
    operator_delete(DAT_10015a54);
  }
  DAT_10015a68 = 7;
  _DAT_10015a64 = 0;
  DAT_10015a54 = (void *)((uint)DAT_10015a54 & 0xffff0000);
  return;
}



// Function: FUN_1000fc40 at 1000fc40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fc40(void)

{
  if (7 < DAT_10015a84) {
    operator_delete(DAT_10015a70);
  }
  DAT_10015a84 = 7;
  _DAT_10015a80 = 0;
  DAT_10015a70 = (void *)((uint)DAT_10015a70 & 0xffff0000);
  return;
}



// Function: FUN_1000fc80 at 1000fc80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fc80(void)

{
  if (7 < DAT_10015aa0) {
    operator_delete(DAT_10015a8c);
  }
  DAT_10015aa0 = 7;
  _DAT_10015a9c = 0;
  DAT_10015a8c = (void *)((uint)DAT_10015a8c & 0xffff0000);
  return;
}



// Function: FUN_1000fcc0 at 1000fcc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fcc0(void)

{
  if (7 < DAT_10015abc) {
    operator_delete(DAT_10015aa8);
  }
  DAT_10015abc = 7;
  _DAT_10015ab8 = 0;
  DAT_10015aa8 = (void *)((uint)DAT_10015aa8 & 0xffff0000);
  return;
}



// Function: FUN_1000fd00 at 1000fd00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fd00(void)

{
  if (7 < DAT_10015ad8) {
    operator_delete(DAT_10015ac4);
  }
  DAT_10015ad8 = 7;
  _DAT_10015ad4 = 0;
  DAT_10015ac4 = (void *)((uint)DAT_10015ac4 & 0xffff0000);
  return;
}



// Function: FUN_1000fd40 at 1000fd40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fd40(void)

{
  if (7 < DAT_10015af4) {
    operator_delete(DAT_10015ae0);
  }
  DAT_10015af4 = 7;
  _DAT_10015af0 = 0;
  DAT_10015ae0 = (void *)((uint)DAT_10015ae0 & 0xffff0000);
  return;
}



// Function: FUN_1000fd80 at 1000fd80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fd80(void)

{
  if (7 < DAT_10015b10) {
    operator_delete(DAT_10015afc);
  }
  DAT_10015b10 = 7;
  _DAT_10015b0c = 0;
  DAT_10015afc = (void *)((uint)DAT_10015afc & 0xffff0000);
  return;
}



// Function: FUN_1000fdc0 at 1000fdc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fdc0(void)

{
  if (7 < DAT_10015b2c) {
    operator_delete(DAT_10015b18);
  }
  DAT_10015b2c = 7;
  _DAT_10015b28 = 0;
  DAT_10015b18 = (void *)((uint)DAT_10015b18 & 0xffff0000);
  return;
}



// Function: FUN_1000fe00 at 1000fe00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fe00(void)

{
  if (7 < DAT_10015b48) {
    operator_delete(DAT_10015b34);
  }
  DAT_10015b48 = 7;
  _DAT_10015b44 = 0;
  DAT_10015b34 = (void *)((uint)DAT_10015b34 & 0xffff0000);
  return;
}



// Function: FUN_1000fe40 at 1000fe40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fe40(void)

{
  if (7 < DAT_10015b64) {
    operator_delete(DAT_10015b50);
  }
  DAT_10015b64 = 7;
  _DAT_10015b60 = 0;
  DAT_10015b50 = (void *)((uint)DAT_10015b50 & 0xffff0000);
  return;
}



// Function: FUN_1000fe75 at 1000fe75

void FUN_1000fe75(void)

{
  FUN_1000c6d5(0x10015c34);
  return;
}



// Function: FUN_1000fe7f at 1000fe7f

void FUN_1000fe7f(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_10015c6c,DAT_10015c38);
  RemoveAll((undefined4 *)&DAT_10015c8c);
  return;
}



// Function: FUN_1000fe99 at 1000fe99

void FUN_1000fe99(void)

{
  FUN_1000c894((int *)&DAT_10015c98);
  return;
}



