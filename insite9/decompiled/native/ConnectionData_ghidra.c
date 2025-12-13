/*
 * Decompiled from: ConnectionData.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001020 at 10001020

bool __cdecl FUN_10001020(byte *param_1,byte *param_2)

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



// Function: FUN_10001090 at 10001090

bool __cdecl FUN_10001090(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100010c0 at 100010c0

void FUN_100010c0(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10013348);
}



// Function: FUN_100010e0 at 100010e0

void __cdecl FUN_100010e0(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070057);
  }
}



// Function: FUN_100011a0 at 100011a0

void __cdecl FUN_100011a0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070057);
  }
}



// Function: FUN_10001250 at 10001250

void __cdecl FUN_10001250(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070057);
  }
}



// Function: FUN_10001310 at 10001310

void __cdecl FUN_10001310(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070057);
  }
}



// Function: FUN_100013c0 at 100013c0

uint __fastcall FUN_100013c0(LPCRITICAL_SECTION param_1)

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



// Function: FUN_100013f0 at 100013f0

void __fastcall FUN_100013f0(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10001410 at 10001410

DWORD FUN_10001410(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001430 at 10001430

uint __cdecl FUN_10001430(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10001450 at 10001450

void __fastcall FUN_10001450(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001460 at 10001460

int __thiscall
FUN_10001460(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,LPWSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x100014c2. Too many branches */
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



// Function: FUN_100014e0 at 100014e0

int __thiscall FUN_100014e0(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x1000152a. Too many branches */
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



// Function: FUN_10001540 at 10001540

undefined4 __fastcall FUN_10001540(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001550 at 10001550

void __cdecl FUN_10001550(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100015b0 at 100015b0

void __thiscall FUN_100015b0(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    FUN_100014e0(*(void **)((int)this + 8),*this,param_1);
    return;
  }
  if (DAT_100182e4 == '\0') {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_100182e0 = GetProcAddress(hModule,"RegDeleteKeyExW");
    }
    DAT_100182e4 = '\x01';
  }
  if (DAT_100182e0 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
    (*DAT_100182e0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    return;
  }
                    /* WARNING: Load size is inaccurate */
  RegDeleteKeyW(*this,param_1);
  return;
}



// Function: FUN_10001630 at 10001630

void __fastcall FUN_10001630(undefined4 *param_1)

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



// Function: FUN_10001660 at 10001660

void __thiscall
FUN_10001660(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
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
    iVar1 = FUN_10001460(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,param_6
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



// Function: FUN_10001700 at 10001700

void __thiscall FUN_10001700(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_1000176a:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_1000176a;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_1000177f;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_1000177f;
      }
    }
    iVar2 = 1;
  }
LAB_1000177f:
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



// Function: FUN_100017b0 at 100017b0

void __thiscall FUN_100017b0(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExW(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_100017d0 at 100017d0

LSTATUS __thiscall FUN_100017d0(void *this,LPCWSTR param_1,LPCWSTR param_2,DWORD param_3)

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



// Function: FUN_10001810 at 10001810

LSTATUS __thiscall FUN_10001810(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10001870 at 10001870

undefined4 __fastcall FUN_10001870(undefined4 *param_1)

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



// Function: FUN_100018a0 at 100018a0

void __fastcall FUN_100018a0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100018b0 at 100018b0

undefined4 __thiscall FUN_100018b0(void *this,void *param_1,int param_2)

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
      FUN_100010e0((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10001960 at 10001960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001960(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d75e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_10018308 & 1) == 0) {
    DAT_10018308 = DAT_10018308 | 1;
    DAT_100182ec = 8;
    DAT_100182e8 = &DAT_100114a4;
    DAT_100182f0 = &DAT_100114a0;
    _DAT_100182f4 = 0x4008;
    _DAT_100182f8 = &DAT_1001149c;
    _DAT_100182fc = 0x13;
    _DAT_10018300 = &DAT_10011498;
    _DAT_10018304 = 0x11;
  }
  local_8 = 0xffffffff;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_100182e8)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_100182ec)[uVar2 * 4];
      ExceptionList = local_10;
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10001a50 at 10001a50

uint __cdecl FUN_10001a50(ushort param_1)

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
    goto switchD_10001a66_caseD_30;
  default:
    uVar1 = uVar1 & 0xffffff00;
switchD_10001a66_caseD_30:
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



// Function: FUN_10001ad0 at 10001ad0

LPCWSTR __cdecl FUN_10001ad0(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10001b20 at 10001b20

void __fastcall FUN_10001b20(undefined4 *param_1)

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



// Function: FUN_10001b80 at 10001b80

undefined4 __thiscall FUN_10001b80(void *this,undefined2 *param_1)

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
  
  FUN_10001b20((undefined4 *)this);
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
      goto switchD_10001c74_caseD_9;
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
switchD_10001c74_caseD_9:
  *puVar7 = 0;
  return 0;
}



// Function: FUN_10001cf0 at 10001cf0

undefined4 FUN_10001cf0(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_100114f8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10011528);
  return 1;
}



// Function: FUN_10001d30 at 10001d30

bool FUN_10001d30(HKEY param_1)

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



// Function: FUN_10001d80 at 10001d80

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10001d80(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10001b80(this,param_1), -1 < iVar1)) {
    FUN_10001b20((undefined4 *)this);
    iVar1 = FUN_10001b80(this,local_2008);
    if (-1 < iVar1) {
      FUN_10001b80(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001df0 at 10001df0

void FUN_10001df0(void)

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



// Function: FUN_10001e30 at 10001e30

int FUN_10001e30(void)

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



// Function: FUN_10001e80 at 10001e80

undefined4 __thiscall FUN_10001e80(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_100182cc = *param_3;
    DAT_100182d0 = param_3[1];
    DAT_100182d4 = param_3[2];
    DAT_100182d8 = param_3[3];
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
  piVar2 = DAT_10018424;
  if (DAT_10018424 < DAT_10018428) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_10018428);
  }
  return 0;
}



// Function: FUN_10001f00 at 10001f00

void FUN_10001f00(int param_1)

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



// Function: FUN_10001f60 at 10001f60

void __fastcall FUN_10001f60(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d788;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_100182a0 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001fb0 at 10001fb0

void __fastcall FUN_10001fb0(int *param_1)

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



// Function: FUN_10001fe0 at 10001fe0

void __fastcall FUN_10001fe0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d7b8;
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



// Function: FUN_10002030 at 10002030

void __fastcall FUN_10002030(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10002040 at 10002040

void __thiscall FUN_10002040(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10002070 at 10002070

void FUN_10002070(void)

{
  return;
}



// Function: DllCanUnloadNow at 10002080

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2080  1  DllCanUnloadNow */
  return (uint)(DAT_100183dc != 0);
}



// Function: FUN_10002090 at 10002090

int __fastcall FUN_10002090(int param_1)

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
  DAT_100182c8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_100182b8 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10002100 at 10002100

void __fastcall FUN_10002100(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001f00(param_1 + 4);
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



// Function: FUN_10002150 at 10002150

void __fastcall FUN_10002150(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d7e8;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001f00(param_1 + 4);
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



// Function: FUN_100021d0 at 100021d0

void __fastcall FUN_100021d0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_100021f0 at 100021f0

void __thiscall FUN_100021f0(void *this,LPCWSTR param_1)

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
  
  puStack_c = &LAB_1000d81b;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = param_1;
  local_220 = (HKEY)0x0;
  local_21c = 0;
  local_218 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = FUN_10001700(&local_220,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    local_224 = 0x100;
    iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          &local_230);
    while (iVar1 == 0) {
      iVar1 = FUN_100021f0(&local_220,local_214);
      if (iVar1 != 0) goto LAB_1000225f;
      local_224 = 0x100;
      iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
    }
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
    local_21c = 0;
    FUN_100015b0(this,local_228);
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  else {
LAB_1000225f:
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



// Function: FUN_10002380 at 10002380

undefined4 __fastcall FUN_10002380(int *param_1)

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



// Function: FUN_10002410 at 10002410

void __thiscall FUN_10002410(void *this,LPCWSTR param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d858;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar1 = lstrlenW(param_1);
  FUN_100018b0(this,param_1,iVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002490 at 10002490

void FUN_10002490(int param_1)

{
  FUN_10002380((int *)(param_1 + 4));
  return;
}



// Function: FUN_100024b0 at 100024b0

void FUN_100024b0(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  puStack_c = &LAB_1000d88b;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000267d;
  *param_3 = 0;
  *param_4 = 0;
  local_240 = 0;
  local_8 = 0;
  DVar3 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar3 == 0) {
    FUN_10001410();
  }
  else {
    if (DVar3 == 0x104) {
      local_8 = 0xffffffff;
      FUN_10001fb0(&local_240);
      goto LAB_1000267d;
    }
    pwVar4 = (wchar_t *)FUN_10001df0();
    if (param_2 != (LPCWSTR)0x0) {
      uVar5 = lstrlenW(param_2);
      uVar1 = uVar5 + DVar3;
      if (((DVar3 <= uVar1) && (uVar5 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_100011a0(local_23c + DVar3,0x10e - DVar3,param_2);
        goto LAB_100025c0;
      }
LAB_1000265f:
      local_8 = 0xffffffff;
      FUN_10001fb0(&local_240);
      goto LAB_1000267d;
    }
LAB_100025c0:
    iVar6 = Ordinal_161(local_23c,param_4,uVar2);
    if (iVar6 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar6 = (int)pwVar4 - (int)local_23c >> 1;
      if (0x104 < iVar6 + 5U) goto LAB_1000265f;
      FUN_100011a0(pwVar4,0x10e - iVar6,local_20);
      iVar6 = Ordinal_161(local_23c,param_4);
      if (iVar6 < 0) goto LAB_1000252f;
    }
    uVar7 = Ordinal_2(local_23c);
    *param_3 = uVar7;
  }
LAB_1000252f:
  local_8 = 0xffffffff;
  FUN_10001fb0(&local_240);
LAB_1000267d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100026a0 at 100026a0

void __fastcall FUN_100026a0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d8c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100182a0 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100026f0 at 100026f0

void __fastcall FUN_100026f0(int param_1)

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
  piVar5 = DAT_10018424;
  if (DAT_10018424 < DAT_10018428) {
    do {
      if (*piVar5 != 0) {
        (**(code **)(*piVar5 + 0x20))(0);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < DAT_10018428);
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



// Function: FUN_100027e0 at 100027e0

void __fastcall FUN_100027e0(undefined4 *param_1)

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



// Function: FUN_10002820 at 10002820

undefined4 __thiscall FUN_10002820(void *this,undefined4 *param_1)

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



// Function: FUN_10002890 at 10002890

void __fastcall FUN_10002890(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100028b0 at 100028b0

void __fastcall FUN_100028b0(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10002030(param_1);
    return;
  }
  return;
}



// Function: FUN_100028c0 at 100028c0

void __fastcall FUN_100028c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d903;
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



// Function: FUN_10002920 at 10002920

void __fastcall FUN_10002920(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10002940 at 10002940

undefined4 FUN_10002940(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001e80(&DAT_100183d4,(int *)&PTR_DAT_10017000,param_1,(undefined4 *)&DAT_100114a8);
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    FUN_100026f0(0x100183d4);
  }
  return 1;
}



// Function: FUN_10002990 at 10002990

DWORD __fastcall FUN_10002990(int param_1)

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



// Function: FUN_100029d0 at 100029d0

void __fastcall FUN_100029d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d93e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a30 at 10002a30

void __fastcall FUN_10002a30(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10002a40 at 10002a40

void __fastcall FUN_10002a40(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10002a50 at 10002a50

HRESULT __thiscall FUN_10002a50(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10011ff0,(LPUNKNOWN)0x0,1,(IID *)&DAT_100117a8,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_10002ab0 at 10002ab0

undefined4 FUN_10002ab0(void)

{
  return 0x80004005;
}



// Function: FUN_10002ac0 at 10002ac0

void FUN_10002ac0(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_100117b8);
  return;
}



// Function: FUN_10002ae0 at 10002ae0

undefined4 * __thiscall FUN_10002ae0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d970;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 4) != 0) {
    if (*(int *)((int)this + 0xc) != 0) {
      FUN_10001f00((int)this + 4);
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



// Function: FUN_10002b80 at 10002b80

void __fastcall FUN_10002b80(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10002380(param_1);
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



// Function: FUN_10002c00 at 10002c00

void __fastcall FUN_10002c00(undefined4 *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d9d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  piVar1 = param_1 + 1;
  FUN_10002380(piVar1);
  local_8 = 1;
  FUN_10002380(piVar1);
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



// Function: FUN_10002ca0 at 10002ca0

undefined4 FUN_10002ca0(void)

{
  return 0x80004001;
}



// Function: FUN_10002cb0 at 10002cb0

undefined4 FUN_10002cb0(void)

{
  return 1;
}



// Function: FUN_10002cc0 at 10002cc0

undefined4 FUN_10002cc0(void)

{
  return 0;
}



// Function: FUN_10002cd0 at 10002cd0

undefined4 * __thiscall FUN_10002cd0(void *this,byte param_1)

{
  FUN_10002c00((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002d00 at 10002d00

void __thiscall FUN_10002d00(void *this,LPCWSTR param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1000d9f8;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
      local_5d = DAT_100182c4;
      while (WVar1 != L'\0') {
        local_68 = puVar2;
        if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (((local_64 != 0) || (pwVar3 = wcsstr(*this,L"HKCR"), pwVar3 == (wchar_t *)0x0)) ||
             (pwVar3 != *this)) {
LAB_10002e2a:
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_55 == '\0') {
                local_55 = '\x01';
                goto LAB_10002ea9;
              }
              iVar5 = FUN_10001870((undefined4 *)this);
              if (iVar5 == 0) {
                    /* WARNING: Load size is inaccurate */
                pWVar4 = CharNextW(*this);
                *(LPWSTR *)this = pWVar4;
                iVar5 = FUN_100018b0(&local_70,pWVar4,1);
                if (iVar5 == 0) goto LAB_10002f76;
                goto LAB_10002e6d;
              }
              local_55 = '\0';
            }
            else {
LAB_10002e6d:
              if (local_55 != '\0') goto LAB_10002ea9;
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x7b) {
              local_64 = local_64 + 1;
            }
            if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
               (local_56 == '\x01')) {
              iVar5 = FUN_10002410(&local_70,L"\r\n\t}\r\n}\r\n");
              if (iVar5 == 0) goto LAB_10002f76;
              local_56 = '\0';
            }
            goto LAB_10002ea9;
          }
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          iVar5 = FUN_10002410(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
          if (iVar5 != 0) {
            local_56 = '\x01';
            goto LAB_10002e2a;
          }
LAB_10002f76:
          local_5c = 0x8007000e;
          goto LAB_10002f60;
        }
LAB_10002ea9:
                    /* WARNING: Load size is inaccurate */
        pWVar6 = *this;
        if (*pWVar6 == L'%') {
          pWVar6 = CharNextW(pWVar6);
          *(LPCWSTR *)this = pWVar6;
          if (*pWVar6 == L'%') goto LAB_10002f2d;
          pWVar6 = FUN_10001ad0(pWVar6,L'%');
          if (pWVar6 == (LPCWSTR)0x0) {
LAB_10002f7f:
            local_5c = 0x80020009;
            goto LAB_10002f60;
          }
                    /* WARNING: Load size is inaccurate */
          rVar7 = (int)pWVar6 - (int)*this >> 1;
          if (0x1f < (int)rVar7) {
            local_5c = 0x80004005;
            goto LAB_10002f60;
          }
          FUN_10001250(local_54,0x20,*this,rVar7);
          local_78 = local_54;
          pWVar8 = (LPCWSTR)FUN_10002820((void *)(*(int *)((int)this + 4) + 4),&local_78);
          if (pWVar8 == (LPCWSTR)0x0) goto LAB_10002f7f;
          iVar5 = FUN_10002410(&local_70,pWVar8);
          if (iVar5 == 0) goto LAB_10002f76;
                    /* WARNING: Load size is inaccurate */
          pWVar8 = *this;
          while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
            pWVar8 = CharNextW(*this);
            *(LPCWSTR *)this = pWVar8;
          }
        }
        else {
LAB_10002f2d:
          iVar5 = FUN_100018b0(&local_70,pWVar6,1);
          if (iVar5 == 0) goto LAB_10002f76;
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
LAB_10002f60:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002fc0 at 10002fc0

/* WARNING: Removing unreachable block (ram,0x1000301c) */
/* WARNING: Removing unreachable block (ram,0x10003069) */

void FUN_10002fc0(GUID *param_1,int *param_2,int param_3)

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
  
  puStack_c = &LAB_1000da8e;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
    HVar2 = CoCreateInstance((IID *)&DAT_10011fb0,(LPUNKNOWN)0x0,1,(IID *)&DAT_100118a4,&local_1a8);
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
            goto LAB_10003330;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_194,0x40);
        local_1c8 = 0;
        local_8._0_1_ = 6;
        FUN_100011a0(local_114,0x80,L"CLSID\\");
        FUN_10001310(local_114,0x80,local_194);
        FUN_10001310(local_114,0x80,L"\\Required Categories");
        local_1c4 = 0x80000000;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = (HKEY)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8 = CONCAT31(local_8._1_3_,8);
        local_1ac = 0;
        iVar3 = FUN_10001700(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_10001630(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_100015b0(&local_1c4,local_114);
          }
        }
        FUN_100011a0(local_114,0x80,L"CLSID\\");
        FUN_10001310(local_114,0x80,local_194);
        FUN_10001310(local_114,0x80,L"\\Implemented Categories");
        iVar3 = FUN_10001700(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_10001630(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_100015b0(&local_1c4,local_114);
          }
        }
        local_8._0_1_ = 7;
        FUN_100021d0(&local_1b8);
        local_8._0_1_ = 6;
        FUN_100021d0(&local_1c4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10001fb0(&local_1c8);
      }
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
  }
LAB_10003330:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003370 at 10003370

int FUN_10003370(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1000dae0;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar2 = FUN_100024b0(param_1,param_2,&local_18,&local_14);
  if (iVar2 < 0) goto LAB_1000342c;
  iVar2 = (**(code **)(*local_14 + 0x1c))(local_14,&param_2,uVar1);
  if (iVar2 < 0) goto LAB_1000342c;
  if (DAT_100182c4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_100033fe;
    pFVar3 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_100033fe;
  }
  else {
LAB_100033fe:
    pFVar3 = Ordinal_186_exref;
  }
  iVar2 = (*pFVar3)(param_2,(uint)(ushort)param_2[0xc],(uint)(ushort)param_2[0xd],
                    *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 10));
  (**(code **)(*local_14 + 0x30))(local_14,param_2);
LAB_1000342c:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10003470 at 10003470

void FUN_10003470(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1000db37;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = 0;
  local_220 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_14 = uVar2;
  iVar3 = FUN_100024b0(param_1,param_2,&local_228,&local_220);
  uVar1 = local_228;
  if (iVar3 < 0) goto LAB_1000359f;
  pwVar6 = (wchar_t *)0x0;
  local_224 = (wchar_t *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(*local_220 + 0x24))(local_220,0xffffffff,0,0,0,&local_224,uVar2);
  if ((-1 < iVar3) && (local_224 != (wchar_t *)0x0)) {
    rVar4 = Ordinal_7(local_224);
    FUN_10001250(local_21c,0x104,local_224,rVar4);
    pwVar6 = local_21c;
    local_16 = 0;
    iVar3 = FUN_10001e30();
    local_21c[iVar3] = L'\0';
  }
  if (DAT_100182c4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_1000357c;
    pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar5 == (FARPROC)0x0) goto LAB_1000357c;
  }
  else {
LAB_1000357c:
    pFVar5 = Ordinal_163_exref;
  }
  (*pFVar5)(local_220,uVar1,pwVar6);
  local_8._0_1_ = 2;
  Ordinal_6(local_224);
LAB_1000359f:
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



// Function: FUN_100035f0 at 100035f0

int FUN_100035f0(int param_1,int param_2,byte *param_3)

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
          (bVar2 = FUN_10001020(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar6 = 1;
        iVar5 = (*(code *)puVar1[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)puVar1[7])(1);
        iVar5 = FUN_10002fc0((GUID *)*puVar1,piVar3,iVar6);
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
    iVar5 = FUN_10003470(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10003680 at 10003680

int FUN_10003680(int param_1,int param_2,byte *param_3)

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
          (bVar2 = FUN_10001020(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)puVar1[7])();
        iVar5 = FUN_10002fc0((GUID *)*puVar1,piVar3,iVar5);
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
    iVar5 = FUN_10003370(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10003710 at 10003710

int FUN_10003710(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
  puStack_c = &LAB_1000db68;
  local_10 = ExceptionList;
  uVar4 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
      iVar6 = (*(code *)puVar1[2])(puVar1[3],&DAT_10011904,piVar2);
    }
    local_8 = 0xffffffff;
    FUN_10002920(&local_18);
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



// Function: FUN_10003870 at 10003870

void __fastcall FUN_10003870(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dbae;
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



// Function: FUN_100038e0 at 100038e0

undefined4 FUN_100038e0(int *param_1)

{
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    return 1;
  }
  return 0;
}



// Function: FUN_10003920 at 10003920

undefined4 FUN_10003920(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_10003980 at 10003980

undefined4 FUN_10003980(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_100182c8 + 4))();
    return 0;
  }
  (**(code **)(*DAT_100182c8 + 8))();
  return 0;
}



// Function: FUN_100039b0 at 100039b0

undefined4 * __thiscall FUN_100039b0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dbee;
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



// Function: FUN_10003a30 at 10003a30

undefined4 __thiscall FUN_10003a30(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dc43;
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



// Function: FUN_10003b10 at 10003b10

int __thiscall FUN_10003b10(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x401) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10002040(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10003b60 at 10003b60

int __thiscall FUN_10003b60(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10002040(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10003bb0 at 10003bb0

/* WARNING: Removing unreachable block (ram,0x10003bc2) */

int __thiscall FUN_10003bb0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10002040(this,param_1);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10003bf0 at 10003bf0

void __fastcall FUN_10003bf0(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10003c20 at 10003c20

void __fastcall FUN_10003c20(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000dc9c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (7 < *(uint *)(param_1 + 0x60)) {
    operator_delete(*(void **)(param_1 + 0x4c));
  }
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  local_8 = local_8 & 0xffffff00;
  if (7 < *(uint *)(param_1 + 0x44)) {
    operator_delete(*(void **)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x44) = 7;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003ce0 at 10003ce0

void __fastcall FUN_10003ce0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dcc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003c20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003d40 at 10003d40

void __thiscall FUN_10003d40(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_100119bc,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003d90 at 10003d90

void __fastcall FUN_10003d90(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_10003de0 at 10003de0

void __fastcall FUN_10003de0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dcf9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003e30 at 10003e30

exception * __thiscall FUN_10003e30(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dd29;
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



// Function: FUN_10003e90 at 10003e90

uint __cdecl FUN_10003e90(byte *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  
  if (3 < param_3) {
    do {
      if (*(int *)param_1 != *(int *)param_2) goto LAB_10003ebb;
      param_3 = param_3 - 4;
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_10003ebb:
  iVar1 = (uint)*param_1 - (uint)*param_2;
  if (iVar1 == 0) {
    if (param_3 < 2) {
      return 0;
    }
    iVar1 = (uint)param_1[1] - (uint)param_2[1];
    if (iVar1 == 0) {
      if (param_3 < 3) {
        return 0;
      }
      iVar1 = (uint)param_1[2] - (uint)param_2[2];
      if (iVar1 == 0) {
        if (param_3 < 4) {
          return 0;
        }
        iVar1 = (uint)param_1[3] - (uint)param_2[3];
      }
    }
  }
  return iVar1 >> 0x1f | 1;
}



// Function: FUN_10003f10 at 10003f10

void __fastcall FUN_10003f10(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10003f20 at 10003f20

undefined4 FUN_10003f20(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10003f40 at 10003f40

void __fastcall FUN_10003f40(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar1;
  
  pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
                    /* WARNING: Could not recover jumptable at 0x10003f6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pbVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10003f80 at 10003f80

void * __cdecl FUN_10003f80(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dde9;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100138d0);
}



// Function: FUN_10004010 at 10004010

exception * __thiscall FUN_10004010(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dd29;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10004070 at 10004070

uint __thiscall FUN_10004070(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_100040d8:
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
      goto LAB_100040d8;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10004100 at 10004100

void __fastcall
FUN_10004100(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  ushort *puVar1;
  
  if (((byte)param_1[0x40] & 1) != 0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (param_1);
    if (puVar1 == (ushort *)0x0) {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr(param_1);
    }
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback(param_1);
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       (param_1);
    operator_delete(puVar1);
  }
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            (param_1,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            (param_1,(ushort *)0x0,(ushort *)0x0);
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



// Function: FUN_10004170 at 10004170

uint __thiscall FUN_10004170(void *this,byte *param_1,uint param_2,uint param_3)

{
  byte *_Buf;
  byte *pbVar1;
  void *pvVar2;
  uint uVar3;
  byte *_MaxCount;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar3 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar3)) {
      _MaxCount = (byte *)(uVar3 + (1 - param_3));
      pvVar2 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      _Buf = (byte *)((int)pvVar2 + param_2);
      pbVar1 = (byte *)memchr(_Buf,(int)(char)*param_1,(size_t)_MaxCount);
      while (pbVar1 != (byte *)0x0) {
        uVar3 = FUN_10003e90(pbVar1,param_1,param_3);
        if (uVar3 == 0) {
          if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)pbVar1 - (int)this;
        }
        _MaxCount = _Buf + (int)(_MaxCount + (-1 - (int)pbVar1));
        _Buf = pbVar1 + 1;
        pbVar1 = (byte *)memchr(_Buf,(int)(char)*param_1,(size_t)_MaxCount);
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_10004220 at 10004220

void __fastcall FUN_10004220(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10004230 at 10004230

undefined4 __thiscall FUN_10004230(void *this,int *param_1)

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
  puStack_c = &LAB_1000dd63;
  local_10 = ExceptionList;
  uStack_38 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
      local_20 = (uint *)FUN_1000cc6d(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_10003d90,FUN_10001f60);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_10004311();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_10004311();
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



// Function: Catch@10004301 at 10004301

undefined * Catch_10004301(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000430e;
}



// Function: FUN_10004311 at 10004311

undefined4 FUN_10004311(void)

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



// Function: FUN_10004420 at 10004420

void FUN_10004420(int param_1)

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
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10001f60);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10004480 at 10004480

int * __thiscall FUN_10004480(void *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dd88;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int **)this = param_1;
  pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  if (pbVar3 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**this + 4) + (int)*this));
    (**(code **)(*(int *)pbVar3 + 4))(uVar2);
  }
  local_8 = 0;
  bVar1 = std::ios_base::good((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if (bVar1) {
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    if (pbVar4 != (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::flush(pbVar4);
    }
  }
  bVar1 = std::ios_base::good((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  *(bool *)((int)this + 4) = bVar1;
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10004550 at 10004550

void __fastcall FUN_10004550(int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ddb8;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)*param_1);
  }
  local_8 = 0xffffffff;
  pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar3 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
    (**(code **)(*(int *)pbVar3 + 8))(uVar2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100045e0 at 100045e0

void * FUN_100045e0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dde9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)0x0;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100138d0);
  }
  ExceptionList = local_10;
  return pvVar1;
}



// Function: FUN_10004670 at 10004670

bool __thiscall FUN_10004670(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000de40;
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
    (**(code **)**this)(*this,&DAT_10011904,&local_18,DAT_100182a0 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&DAT_10011904,&local_14);
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



// Function: FUN_10004760 at 10004760

void __fastcall
FUN_10004760(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000de69;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_10004100(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100047c0 at 100047c0

ushort __fastcall
FUN_100047c0(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar1 == (ushort *)0x0) {
    return 0xffff;
  }
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr
                     (param_1);
  puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar1 <= puVar2) {
    if ((((byte)param_1[0x40] & 4) != 0) ||
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (param_1), puVar1 == (ushort *)0x0)) {
      return 0xffff;
    }
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (param_1);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       (param_1);
    if ((puVar1 <= puVar2) &&
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           (param_1), *(ushort **)(param_1 + 0x3c) <= puVar1)) {
      return 0xffff;
    }
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (param_1);
    if (*(ushort **)(param_1 + 0x3c) < puVar1) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         (param_1);
      *(ushort **)(param_1 + 0x3c) = puVar1;
    }
    puVar1 = *(ushort **)(param_1 + 0x3c);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       (param_1);
    puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       (param_1);
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
              (param_1,puVar3,puVar2,puVar1);
  }
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  return *puVar1;
}



// Function: FUN_10004870 at 10004870

void __thiscall
FUN_10004870(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  bool bVar7;
  
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar1 != (ushort *)0x0) &&
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), *(ushort **)((int)this + 0x3c) < puVar1)) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *(ushort **)((int)this + 0x3c) = puVar1;
  }
  if (((param_5 & 1) == 0) ||
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 == (ushort *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar1 == (ushort *)0x0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_100049ad;
    }
    else {
      if (param_4 == 2) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
        uVar3 = iVar2 >> 1;
        bVar7 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar2 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 == 1) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        uVar3 = (int)puVar4 - (int)puVar1 >> 1;
        bVar7 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + ((int)puVar4 - (int)puVar1 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
        iVar6 = iVar2 >> 0x1f;
        if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar2 >> 1)))))
        {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)puVar1 - (int)puVar4 >> 1) + param_2);
          goto LAB_100049ad;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
      uVar3 = iVar2 >> 1;
      bVar7 = CARRY4(param_2,uVar3);
      param_2 = param_2 + uVar3;
      param_3 = param_3 + (iVar2 >> 0x1f) + (uint)bVar7;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        uVar3 = (int)puVar4 - (int)puVar1 >> 1;
        bVar7 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + ((int)puVar4 - (int)puVar1 >> 0x1f) + (uint)bVar7;
      }
      else {
LAB_10004909:
        param_3 = *(uint *)(_BADOFF_exref + 4);
        param_2 = *(uint *)_BADOFF_exref;
      }
    }
    else if (param_4 != 0) goto LAB_10004909;
    if (-1 < (int)param_3) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
      iVar6 = iVar2 >> 0x1f;
      if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar2 >> 1))))) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   ((int)puVar1 - (int)puVar4 >> 1) + param_2);
        if (((param_5 & 2) != 0) &&
           (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                     pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 != (ushort *)0x0)) {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   epptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pbase((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,puVar5,puVar4,puVar1);
        }
        goto LAB_100049ad;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_100049ad:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10004ab0 at 10004ab0

ushort __thiscall FUN_10004ab0(void *this,ushort param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  char *pcVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  
  if ((((*(byte *)((int)this + 0x40) & 8) != 0) &&
      (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                          ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                            *)this), puVar1 != (ushort *)0x0)) &&
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 < *(ushort **)((int)this + 0x3c))) {
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar1 = *(ushort **)((int)this + 0x3c);
    puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
               puVar3,puVar1,puVar2);
  }
  if (param_1 == 0xffff) {
    return 0;
  }
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if (puVar1 != (ushort *)0x0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar2 < puVar1) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      *puVar1 = param_1;
      return param_1;
    }
  }
  if ((*(byte *)((int)this + 0x40) & 2) == 0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 == (ushort *)0x0) {
      uVar8 = 0;
    }
    else {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      uVar8 = (int)puVar2 - (int)puVar1 >> 1;
    }
    uVar4 = uVar8 >> 1;
    if (uVar4 < 0x20) {
      uVar4 = 0x20;
    }
    else if (uVar4 == 0) {
      return 0xffff;
    }
    do {
      if (uVar8 <= 0x7fffffff - uVar4) break;
      uVar4 = uVar4 >> 1;
    } while (uVar4 != 0);
    if (uVar4 != 0) {
      pcVar5 = (char *)(uVar4 + uVar8);
      puVar1 = (ushort *)FUN_10003f80(pcVar5);
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      if ((uVar8 == 0) || (memcpy(puVar1,puVar2,uVar8 * 2), uVar8 == 0)) {
        *(ushort **)((int)this + 0x3c) = puVar1;
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   puVar1,puVar1 + (int)pcVar5);
        if ((*(byte *)((int)this + 0x40) & 4) == 0) {
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,puVar1,puVar1,puVar1 + 1);
        }
        else {
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,puVar1,(ushort *)0x0,puVar1);
        }
      }
      else {
        puVar3 = puVar1 + (int)pcVar5;
        *(ushort **)((int)this + 0x3c) = puVar1 + (*(int *)((int)this + 0x3c) - (int)puVar2 >> 1);
        puVar6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        puVar6 = puVar1 + ((int)puVar6 - (int)puVar2 >> 1);
        puVar7 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 pbase((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   puVar1 + ((int)puVar7 - (int)puVar2 >> 1),puVar6,puVar3);
        if ((*(byte *)((int)this + 0x40) & 4) == 0) {
          puVar6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          puVar6 = puVar6 + 1;
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          puVar3 = puVar1 + ((int)puVar3 - (int)puVar2 >> 1);
        }
        else {
          puVar3 = (ushort *)0x0;
          puVar6 = puVar1;
        }
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   puVar1,puVar3,puVar6);
      }
      if ((*(byte *)((int)this + 0x40) & 1) != 0) {
        operator_delete(puVar2);
      }
      *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      *puVar1 = param_1;
      return param_1;
    }
  }
  return 0xffff;
}



// Function: FUN_10004cd0 at 10004cd0

ushort __thiscall FUN_10004cd0(void *this,ushort param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if (puVar1 != (ushort *)0x0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 < puVar2) {
      if (((param_1 != 0xffff) &&
          (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                    gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), param_1 != puVar1[-1])) && ((*(byte *)((int)this + 0x40) & 2) != 0)
         ) {
        return 0xffff;
      }
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,-1
                );
      if (param_1 == 0xffff) {
        return 0;
      }
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      *puVar1 = param_1;
      return param_1;
    }
  }
  return 0xffff;
}



// Function: FUN_10004d60 at 10004d60

void __thiscall FUN_10004d60(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte in_stack_00000020;
  
  uVar7 = param_4 + param_2;
  uVar6 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar1 != (ushort *)0x0) &&
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), *(ushort **)((int)this + 0x3c) < puVar1)) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *(ushort **)((int)this + 0x3c) = puVar1;
  }
  if ((uVar7 != *(uint *)_BADOFF_exref) || (uVar6 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar1 == (ushort *)0x0)) {
      if ((((in_stack_00000020 & 2) != 0) &&
          (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                    pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar1 != (ushort *)0x0)) && (-1 < (int)uVar6)) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
        iVar5 = iVar2 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= (uint)(iVar2 >> 1))))) {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)puVar1 - (int)puVar3 >> 1) + uVar7);
          goto LAB_10004e59;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
      iVar5 = iVar2 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= (uint)(iVar2 >> 1))))) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   ((int)puVar1 - (int)puVar3 >> 1) + uVar7);
        if (((in_stack_00000020 & 2) != 0) &&
           (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                     pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 != (ushort *)0x0)) {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   epptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pbase((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,puVar4,puVar3,puVar1);
        }
        goto LAB_10004e59;
      }
    }
    uVar7 = *(uint *)_BADOFF_exref;
    uVar6 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_10004e59:
  *param_1 = uVar7;
  param_1[1] = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10004ef0 at 10004ef0

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10004ef0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000de69;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_10004100((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  local_8 = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_10004f60 at 10004f60

void __thiscall FUN_10004f60(void *this,void *param_1,char *param_2,undefined4 param_3)

{
  ushort *_Dst;
  ushort *puVar1;
  ushort *puVar2;
  
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = param_3;
  if ((param_2 != (char *)0x0) && (((byte)param_3 & 6) != 6)) {
    _Dst = (ushort *)FUN_10003f80(param_2);
    memcpy(_Dst,param_1,(int)param_2 * 2);
    puVar2 = _Dst + (int)param_2;
    *(ushort **)((int)this + 0x3c) = puVar2;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                 _Dst,_Dst,puVar2);
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      puVar1 = puVar2;
      if ((*(uint *)((int)this + 0x40) & 0x10) == 0) {
        puVar1 = _Dst;
      }
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                 _Dst,puVar1,puVar2);
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      if (puVar2 == (ushort *)0x0) {
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   _Dst,(ushort *)0x0,_Dst);
      }
    }
    *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  }
  return;
}



// Function: FUN_10004ff0 at 10004ff0

/* WARNING: Removing unreachable block (ram,0x1000503c) */

void FUN_10004ff0(int *param_1,ushort *param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  int iVar5;
  __int64 _Var6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined1 local_24 [4];
  char local_20;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dea0;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  uVar9 = (undefined2)(DAT_100182a0 ^ (uint)&stack0xfffffffc);
  uVar10 = (undefined2)((DAT_100182a0 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  local_18 = 0;
  uVar1 = *(uint *)(param_2 + 8);
  _Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((_Var6 < 1) ||
     (_Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1)),
     (uint)_Var6 <= uVar1)) {
    local_1c = 0;
  }
  else {
    _Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    local_1c = (int)_Var6 - uVar1;
  }
  iVar5 = local_1c;
  FUN_10004480(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_100051a9();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) == 0x40) {
LAB_100050e8:
    if (7 < *(uint *)(param_2 + 10)) {
      param_2 = *(ushort **)param_2;
    }
    uVar7 = 0;
    uVar8 = 0;
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    _Var6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                      (pbVar4,param_2,CONCAT26(uVar10,CONCAT24(uVar9,CONCAT22(uVar8,uVar7))));
    if (((uint)_Var6 != uVar1) || (iVar5 = local_1c, (int)((ulonglong)_Var6 >> 0x20) != 0)) {
      local_18 = 4;
      goto LAB_1000511c;
    }
  }
  else {
    while (iVar5 != 0) {
      uVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar2);
      if (uVar2 == 0xffff) {
        local_18 = local_18 | 4;
        break;
      }
      iVar5 = iVar5 + -1;
      local_1c = iVar5;
    }
    if (local_18 == 0) goto LAB_100050e8;
  }
  while (iVar5 != 0) {
    uVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                      ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       (*(int *)(*param_1 + 4) + (int)param_1));
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    uVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                      (pbVar4,uVar2);
    if (uVar2 == 0xffff) {
      local_18 = local_18 | 4;
      break;
    }
    local_1c = iVar5 + -1;
    iVar5 = local_1c;
  }
LAB_1000511c:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_100051a9();
  return;
}



// Function: Catch@10005185 at 10005185

undefined * Catch_10005185(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100051a6;
}



// Function: FUN_100051a9 at 100051a9

void FUN_100051a9(void)

{
  bool bVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              (*(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                (unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                      (int)*(int **)(unaff_EBP + -0x20)));
  if (pbVar2 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                        (int)*(int **)(unaff_EBP + -0x20)));
    (**(code **)(*(int *)pbVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10005220 at 10005220

void FUN_10005220(int *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  __int64 _Var8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined1 local_24 [4];
  char local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ded0;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffc4;
  uVar11 = (undefined2)(DAT_100182a0 ^ (uint)&stack0xfffffffc);
  uVar12 = (undefined2)((DAT_100182a0 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  local_18 = 0;
  puVar2 = param_2;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  } while (uVar1 != 0);
  uVar3 = (int)puVar2 - (int)(param_2 + 1) >> 1;
  local_1c = uVar3;
  _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((_Var8 < 0) || (((int)((ulonglong)_Var8 >> 0x20) == 0 || _Var8 < 0 && ((int)_Var8 == 0)))) {
LAB_100052b8:
    iVar6 = 0;
    iVar5 = 0;
  }
  else {
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    if ((_Var8 < 0) || ((_Var8 < 0x100000000 && ((uint)_Var8 <= uVar3)))) goto LAB_100052b8;
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    iVar6 = (uint)_Var8 - local_1c;
    iVar5 = (int)((ulonglong)_Var8 >> 0x20) - (uint)((uint)_Var8 < local_1c);
  }
  FUN_10004480(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_1000541c();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) != 0x40) {
    while( true ) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_10005341;
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar1);
      if (uVar1 == 0xffff) break;
      bVar7 = iVar6 != 0;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1 + (uint)bVar7;
    }
    local_18 = local_18 | 4;
LAB_10005341:
    if (local_18 != 0) goto LAB_10005379;
  }
  uVar9 = 0;
  uVar10 = 0;
  pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  _Var8 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                    (pbVar4,param_2,CONCAT26(uVar12,CONCAT24(uVar11,CONCAT22(uVar10,uVar9))));
  if (((uint)_Var8 == local_1c) && ((int)((ulonglong)_Var8 >> 0x20) == 0)) {
    while( true ) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_10005379;
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar1);
      if (uVar1 == 0xffff) break;
      bVar7 = iVar6 != 0;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1 + (uint)bVar7;
    }
    local_18 = local_18 | 4;
  }
  else {
    local_18 = 4;
  }
LAB_10005379:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_1000541c();
  return;
}



// Function: Catch@100053f8 at 100053f8

undefined * Catch_100053f8(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005419;
}



// Function: FUN_1000541c at 1000541c

void FUN_1000541c(void)

{
  bool bVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              (*(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                (unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                      (int)*(int **)(unaff_EBP + -0x20)));
  if (pbVar2 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                        (int)*(int **)(unaff_EBP + -0x20)));
    (**(code **)(*(int *)pbVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100054a0 at 100054a0

undefined4 FUN_100054a0(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000def8;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  local_8 = 0xffffffff;
  uVar1 = FUN_1000551e();
  return uVar1;
}



// Function: Catch@1000550b at 1000550b

undefined * Catch_1000550b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005518;
}



// Function: FUN_1000551e at 1000551e

undefined4 FUN_1000551e(void)

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



// Function: FUN_100055a0 at 100055a0

/* WARNING: Removing unreachable block (ram,0x100055fe) */

int * __thiscall FUN_100055a0(void *this,undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  __int64 _Var8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uStack_3c;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_24;
  char local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000df30;
  local_10 = ExceptionList;
  uStack_3c = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  iVar6 = 0;
  local_18 = 0;
  local_1c = this;
  FUN_10004480(&local_24,(int *)this);
  local_8 = 0;
  if (local_20 == '\0') {
                    /* WARNING: Load size is inaccurate */
    std::ios_base::width((ios_base *)(*(int *)(*this + 4) + (int)this),0);
                    /* WARNING: Load size is inaccurate */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(*this + 4) + (int)this),local_18,false);
    local_8 = 3;
    bVar7 = std::uncaught_exception();
    if (!bVar7) {
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx(local_24);
    }
    local_8 = 0xffffffff;
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (local_24 + *(int *)(*(int *)local_24 + 4)));
    if (pbVar3 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
      pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (local_24 + *(int *)(*(int *)local_24 + 4)));
      (**(code **)(*(int *)pbVar3 + 8))();
    }
    ExceptionList = local_10;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  _Var8 = std::ios_base::width((ios_base *)(*(int *)(*this + 4) + (int)this));
  if (_Var8 < 2) {
    iVar5 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*this + 4) + (int)this));
    iVar6 = (int)_Var8 + -1;
    iVar5 = (int)((ulonglong)_Var8 >> 0x20) - (uint)((int)_Var8 == 0);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
                    /* WARNING: Load size is inaccurate */
  uVar2 = std::ios_base::flags((ios_base *)(*(int *)(*this + 4) + (int)this));
  if ((uVar2 & 0x1c0) == 0x40) {
LAB_1000569c:
    uVar9 = (undefined1)param_1;
    uVar10 = (undefined1)((uint)param_1 >> 8);
                    /* WARNING: Load size is inaccurate */
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*this + 4) + (int)this));
    uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                      (pbVar3,CONCAT11(uVar10,uVar9));
    if (uVar1 == 0xffff) {
      local_18 = 4;
    }
    for (; ((local_18 == 0 && (-1 < iVar5)) && ((0 < iVar5 || (iVar6 != 0)))); iVar6 = iVar6 + -1) {
                    /* WARNING: Load size is inaccurate */
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*this + 4) + (int)this));
      uVar9 = (undefined1)uVar1;
      uVar10 = (undefined1)(uVar1 >> 8);
                    /* WARNING: Load size is inaccurate */
      pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*this + 4) + (int)this));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar3,CONCAT11(uVar10,uVar9));
      if (uVar1 == 0xffff) {
        local_18 = 4;
      }
      iVar5 = iVar5 + -1 + (uint)(iVar6 != 0);
    }
  }
  else {
    while (local_18 == 0) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_1000569c;
                    /* WARNING: Load size is inaccurate */
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*this + 4) + (int)this));
      uVar9 = (undefined1)uVar1;
      uVar10 = (undefined1)(uVar1 >> 8);
                    /* WARNING: Load size is inaccurate */
      pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*this + 4) + (int)this));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar3,CONCAT11(uVar10,uVar9));
      if (uVar1 == 0xffff) {
        local_18 = 4;
      }
      bVar7 = iVar6 != 0;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1 + (uint)bVar7;
    }
  }
  local_8 = 0;
  piVar4 = (int *)FUN_10005755();
  return piVar4;
}



// Function: Catch@10005731 at 10005731

undefined * Catch_10005731(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + -0x18) + 4) + (int)*(int **)(unaff_EBP + -0x18)),4,
             true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005752;
}



// Function: FUN_10005755 at 10005755

void FUN_10005755(void)

{
  bool bVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::ios_base::width((ios_base *)(*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),0);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              (*(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                (unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                      (int)*(int **)(unaff_EBP + -0x20)));
  if (pbVar2 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                        (int)*(int **)(unaff_EBP + -0x20)));
    (**(code **)(*(int *)pbVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100057e0 at 100057e0

int * __thiscall FUN_100057e0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10005870 at 10005870

int * __thiscall FUN_10005870(void *this,uint param_1,uint param_2)

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
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar1 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1),(void *)((int)pvVar1 + param_2 + param_1),
            uVar2 - param_2);
    iVar3 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar3;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*this + iVar3) = 0;
      return (int *)this;
    }
    *(undefined1 *)((int)this + iVar3) = 0;
  }
  return (int *)this;
}



// Function: FUN_10005900 at 10005900

void __thiscall FUN_10005900(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000df50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = uVar2 + uVar1, -uVar2 - 2 < uVar1)) {
      param_1 = 0xfffffffe;
    }
  }
  local_8 = 0;
  FUN_100045e0((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_100059bc();
  return;
}



// Function: Catch@10005989 at 10005989

undefined * Catch_10005989(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100045e0((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100059b3;
}



// Function: FUN_100059bc at 100059bc

void FUN_100059bc(void)

{
  undefined4 *_Src;
  size_t _Size;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  _Size = *(size_t *)(unaff_EBP + 0xc);
  if (_Size != 0) {
    _Src = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      _Src = (undefined4 *)*unaff_ESI;
    }
    memcpy(unaff_EBX,_Src,_Size);
    _Size = *(size_t *)(unaff_EBP + 0xc);
  }
  if (0xf < (uint)unaff_ESI[5]) {
    operator_delete((void *)*unaff_ESI);
    _Size = *(size_t *)(unaff_EBP + 0xc);
  }
  *(undefined1 *)unaff_ESI = 0;
  *unaff_ESI = unaff_EBX;
  unaff_ESI[5] = unaff_EDI;
  unaff_ESI[4] = _Size;
  if (0xf < unaff_EDI) {
    unaff_ESI = unaff_EBX;
  }
  *(undefined1 *)((int)unaff_ESI + _Size) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@10005a1b at 10005a1b

void Catch_10005a1b(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10005a50 at 10005a50

void __thiscall FUN_10005a50(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000df70;
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
  FUN_10003f80((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10005b10();
  return;
}



// Function: Catch@10005ade at 10005ade

undefined * Catch_10005ade(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10003f80((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005b07;
}



// Function: FUN_10005b10 at 10005b10

void FUN_10005b10(void)

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



// Function: Catch@10005b71 at 10005b71

void Catch_10005b71(void)

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



// Function: FUN_10005ba0 at 10005ba0

int __thiscall FUN_10005ba0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = FUN_10004670(this,(undefined4 *)*param_1);
  if (!bVar3) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    *(undefined4 *)this = 0;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_10011a80,this);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005c00 at 10005c00

void __fastcall FUN_10005c00(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000dfb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)
   ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x18) +
   *(int *)(*param_1 + 4) + -0x60) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  this = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 6);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10004100(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  local_8 = 0xffffffff;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x18))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005c90 at 10005c90

int * __thiscall FUN_10005c90(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x60);
  FUN_10005c00(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10005cc0 at 10005cc0

void __fastcall FUN_10005cc0(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000dff0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)
   ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x14) +
   *(int *)(*param_1 + 4) + -0x50) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  this = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 1);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10004100(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  local_8 = 0xffffffff;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 2)
            );
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x14))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005d50 at 10005d50

/* WARNING: Removing unreachable block (ram,0x10005ded) */

basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10005d50(void *this,uint param_1,int param_2)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this_00;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e04d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined **)this = &DAT_10011aa0;
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               ((int)this + 0x50));
    local_8 = 0;
  }
  this_00 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
            ((int)this + 4);
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,this_00,
             false);
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this_00);
  uVar1 = 0;
  *(undefined ***)this_00 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(uint *)((int)this + 0x44) = uVar1;
  ExceptionList = local_10;
  return (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_10005e30 at 10005e30

int * __thiscall FUN_10005e30(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x50);
  FUN_10005cc0(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10005e60 at 10005e60

void __fastcall FUN_10005e60(int param_1)

{
  if (param_1 != 0) {
    FUN_100054a0(param_1 + 4);
    return;
  }
  FUN_100054a0(0);
  return;
}



// Function: FUN_10005e90 at 10005e90

undefined4 FUN_10005e90(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e080;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1000cc6d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    local_8 = 0xffffffff;
    uVar3 = FUN_10005f26();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10005f14 at 10005f14

undefined * Catch_10005f14(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005f21;
}



// Function: FUN_10005f26 at 10005f26

void FUN_10005f26(void)

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
  uVar4 = FUN_1000cc6d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10005f8a();
  return;
}



// Function: Catch@10005f74 at 10005f74

undefined * Catch_10005f74(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10005f81;
}



// Function: FUN_10005f8a at 10005f8a

bool FUN_10005f8a(void)

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
    FUN_100010e0(unaff_EDI,*(rsize_t *)(unaff_EBP + -0x28),*(void **)(unaff_EBP + 8),
                 *(rsize_t *)(unaff_EBP + -0x28));
    FUN_100010e0(unaff_EBX,unaff_ESI,*(void **)(unaff_EBP + 0xc),unaff_ESI);
    iVar1 = FUN_10003a30(*(void **)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x1c));
    if (iVar1 != 0) {
      unaff_EBX = (void *)0x0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      goto LAB_10005fe3;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
LAB_10005fe3:
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



// Function: FUN_10006040 at 10006040

int FUN_10006040(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e0a8;
  local_10 = ExceptionList;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    local_8 = 0;
    ExceptionList = &local_10;
    iVar1 = FUN_10005e90(param_2,param_3);
    ExceptionList = local_10;
    return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_100060d0 at 100060d0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_100060d0(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1000e0f1;
  local_10 = ExceptionList;
  uStack_2144 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2120[0] = 0;
  local_18 = uStack_2144;
  iVar1 = FUN_10001b80(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10001960(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_10006457;
  FUN_10001b20((undefined4 *)this);
  iVar1 = FUN_10001b80(this,local_2018);
  if (iVar1 < 0) goto LAB_10006457;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 < 0x14) {
    if (uVar2 == 0x13) {
      local_2124 = (void *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      uVar2 = FUN_100017b0(param_1,param_2);
      local_8 = 0xffffffff;
      FUN_10001fb0((int *)&local_2124);
    }
    else {
      if (uVar2 != 8) {
        if (uVar2 == 0x11) {
          local_2128 = lstrlenW(local_2018);
          if ((local_2128 & 1) == 0) {
            local_2120[0] = (int)local_2128 / 2;
            local_2120[1] = 0;
            local_8 = 5;
            FUN_10003bb0(local_2120 + 1,local_2120[0]);
            local_8 = 4;
            FUN_1000621c();
            return;
          }
          goto LAB_10006457;
        }
        goto LAB_1000643b;
      }
      uVar2 = FUN_100017d0(param_1,param_2,local_2018,1);
    }
    if (uVar2 != 0) {
      FUN_10001430(uVar2);
      goto LAB_10006457;
    }
  }
  else if (uVar2 == 0x4008) {
    iVar1 = lstrlenW(local_2018);
    local_2120[1] = 0;
    local_8 = 1;
    FUN_10003b60(local_2120 + 1,iVar1 + 2);
    local_8 = 0;
    FUN_10006393();
    return;
  }
LAB_1000643b:
  FUN_10001b80(this,param_3);
LAB_10006457:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10006201 at 10006201

undefined * Catch_10006201(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000620e;
}



// Function: FUN_1000621c at 1000621c

void FUN_1000621c(void)

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
      FUN_10002030((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),(int)unaff_ESI,unaff_EDI);
    if ((int)unaff_ESI < unaff_EBX) {
      do {
        pbVar3 = (byte *)(((uint)unaff_ESI >> 1) + *(int *)(unaff_EBP - 0x2118));
        uVar1 = FUN_10001a50(*(ushort *)((unaff_EBP - 0x2014) + (int)unaff_ESI * 2));
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
      FUN_10002030((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (pvVar2 == unaff_ESI) {
      FUN_10001b80(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_10001430((uint)pvVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000646f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10006384 at 10006384

undefined * Catch_10006384(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10006391;
}



// Function: FUN_10006393 at 10006393

void FUN_10006393(void)

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
    pWVar2 = (WCHAR *)FUN_10001810(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x212c),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_ESI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10002030((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_ESI) {
    FUN_10001b80(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_10001430((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000646f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10006480 at 10006480

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006480(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  
  puStack_c = &LAB_1000e157;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2234 = param_2;
  local_222c = (HKEY)0x0;
  local_2228 = 0;
  local_2224 = 0;
  local_8 = 0;
  local_2254 = param_4;
  local_2220 = this;
  iVar4 = FUN_10001b80(this,param_1);
  if (iVar4 < 0) {
    local_8 = 0xffffffff;
  }
  else {
    if (*param_1 != L'}') {
LAB_10006510:
      local_2244 = 1;
      iVar4 = lstrcmpiW(param_1,L"Delete");
      local_2230 = (uint)(iVar4 == 0);
      iVar5 = lstrcmpiW(param_1,L"ForceRemove");
      if ((iVar5 != 0) && ((iVar4 == 0) == 0)) {
LAB_100066a2:
        iVar4 = lstrcmpiW(param_1,L"NoRemove");
        if (iVar4 == 0) {
          local_2244 = 0;
          iVar4 = FUN_10001b80(local_2220,param_1);
          if (iVar4 < 0) goto LAB_10006b5f;
        }
        iVar4 = lstrcmpiW(param_1,L"Val");
        if (iVar4 == 0) {
          iVar4 = FUN_10001b80(local_2220,local_221c);
          if ((-1 < iVar4) && (iVar4 = FUN_10001b80(local_2220,param_1), -1 < iVar4)) {
            if (*param_1 != L'=') {
LAB_10006b38:
              local_8 = 0xffffffff;
              FUN_100021d0(&local_222c);
              goto LAB_10006b85;
            }
            if (param_3 != 0) {
              local_8._0_1_ = 2;
              local_2250 = local_2234;
              local_224c = 0;
              local_2248 = 0;
              iVar4 = FUN_100060d0(local_2220,&local_2250,local_221c,param_1);
              local_2250 = (HKEY)0x0;
              local_224c = 0;
              local_2248 = 0;
              if (-1 < iVar4) {
                local_8 = (uint)local_8._1_3_ << 8;
                local_224c = 0;
                goto LAB_10006640;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100021d0(&local_2250);
              goto LAB_10006bb1;
            }
            if ((param_4 == 0) && (local_2244 != 0)) {
              local_226c = (HKEY)0x0;
              local_2268 = 0;
              local_2264 = 0;
              local_8._0_1_ = 3;
              uVar7 = FUN_10001700(&local_226c,local_2234,(LPCWSTR)0x0,0x20006);
              pHVar2 = local_226c;
              if ((uVar7 != 0) ||
                 ((uVar7 = RegDeleteValueW(local_226c,local_221c), uVar7 != 0 && (uVar7 != 2)))) {
                FUN_10001430(uVar7);
                local_8 = (uint)local_8._1_3_ << 8;
                ppHVar9 = &local_226c;
                goto LAB_10006b5a;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (pHVar2 != (HKEY)0x0) {
                RegCloseKey(pHVar2);
                local_226c = (HKEY)0x0;
              }
              local_2268 = 0;
            }
            iVar4 = FUN_10001d80(local_2220,param_1);
LAB_10006680:
            if (-1 < iVar4) goto LAB_1000668a;
          }
        }
        else {
          WVar1 = *param_1;
          pWVar6 = param_1;
          pHVar2 = local_2234;
          while (local_2234 = pHVar2, WVar1 != L'\0') {
            if (WVar1 == L'\\') {
              if (pWVar6 != (LPCWSTR)0x0) goto LAB_10006b38;
              break;
            }
            pWVar6 = CharNextW(pWVar6);
            pHVar2 = local_2234;
            WVar1 = *pWVar6;
          }
          if (param_3 == 0) {
            if (param_4 == 0) {
              local_2230 = FUN_10001700(&local_222c,pHVar2,param_1,0x20019);
              if (local_2230 == 0) goto LAB_10006919;
            }
            else {
              local_2230 = 2;
            }
            param_4 = 1;
LAB_10006919:
            eVar8 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
            switch(eVar8) {
            case 0:
            case 0x50:
              goto switchD_10006941_caseD_0;
            default:
                    /* WARNING: Subroutine does not return */
              FUN_100010c0(0x80004005);
            case 0xc:
                    /* WARNING: Subroutine does not return */
              FUN_100010c0(0x8007000e);
            case 0x16:
            case 0x22:
                    /* WARNING: Subroutine does not return */
              FUN_100010c0(0x80070057);
            }
          }
          iVar4 = FUN_10001700(&local_222c,pHVar2,param_1,0x2001f);
          if (((iVar4 != 0) &&
              (iVar4 = FUN_10001700(&local_222c,pHVar2,param_1,0x20019), iVar4 != 0)) &&
             (uVar7 = FUN_10001660(&local_222c,pHVar2,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar7 != 0))
          goto LAB_10006be0;
          iVar4 = FUN_10001b80(local_2220,param_1);
          if ((-1 < iVar4) &&
             ((*param_1 != L'=' ||
              (iVar4 = FUN_100060d0(local_2220,&local_222c,(LPCWSTR)0x0,param_1), -1 < iVar4)))) {
LAB_10006640:
            if ((*param_1 != L'{') || (iVar4 = lstrlenW(param_1), iVar4 != 1)) goto LAB_1000668a;
            iVar4 = FUN_10006480(local_2220,param_1,local_222c,param_3,0);
            if (-1 < iVar4) {
              iVar4 = FUN_10001b80(local_2220,param_1);
              goto LAB_10006680;
            }
          }
        }
        goto LAB_10006b5f;
      }
      iVar4 = FUN_10001b80(local_2220,param_1);
      if (-1 < iVar4) {
        if (param_3 == 0) goto LAB_100066a2;
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
              FUN_100021d0(&local_2240);
              goto LAB_10006b38;
            }
            break;
          }
          pWVar6 = CharNextW(pWVar6);
          WVar1 = *pWVar6;
        }
        ppuVar10 = &PTR_u_AppID_100114f8;
        do {
          iVar4 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar10);
          if (iVar4 == 0) goto LAB_100065ff;
          ppuVar10 = ppuVar10 + 1;
        } while ((int)ppuVar10 < 0x10011528);
        local_2240 = local_2234;
        local_223c = 0;
        local_2238 = 0;
        FUN_100021f0(&local_2240,param_1);
        local_2240 = (HKEY)0x0;
        local_223c = 0;
        local_2238 = 0;
LAB_100065ff:
        if (local_2230 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_100066a2;
        }
        iVar4 = FUN_10001b80(local_2220,param_1);
        if ((-1 < iVar4) && (iVar4 = FUN_10001d80(local_2220,param_1), -1 < iVar4)) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_10006640;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_2240;
        goto LAB_10006b5a;
      }
    }
LAB_10006b5f:
    local_8 = 0xffffffff;
    if (local_222c != (HKEY)0x0) {
      RegCloseKey(local_222c);
      local_222c = (HKEY)0x0;
    }
  }
  local_2228 = 0;
LAB_10006b85:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
switchD_10006941_caseD_0:
  iVar4 = FUN_10001b80(local_2220,param_1);
  if (((iVar4 < 0) || (iVar4 = FUN_10001d80(local_2220,param_1), iVar4 < 0)) ||
     (((*param_1 == L'{' && (iVar4 = lstrlenW(param_1), iVar4 == 1)) &&
      (((iVar4 = FUN_10006480(local_2220,param_1,local_222c,0,param_4), iVar4 < 0 && (param_4 == 0))
       || (iVar4 = FUN_10001b80(local_2220,param_1), iVar4 < 0)))))) goto LAB_10006b5f;
  param_4 = local_2254;
  if (local_2230 != 2) {
    if (local_2230 == 0) {
      if ((local_2254 == 0) || (bVar3 = FUN_10001d30(local_222c), CONCAT31(extraout_var,bVar3) == 0)
         ) {
        bVar3 = FUN_10001d30(local_222c);
        local_2230 = CONCAT31(extraout_var_00,bVar3);
        uVar7 = 0;
        if (local_222c != (HKEY)0x0) {
          uVar7 = RegCloseKey(local_222c);
          local_222c = (HKEY)0x0;
        }
        local_2228 = 0;
        if (uVar7 != 0) {
LAB_10006be0:
          FUN_10001430(uVar7);
LAB_10006bb1:
          local_8 = 0xffffffff;
          FUN_100021d0(&local_222c);
          goto LAB_10006b85;
        }
        if ((local_2244 != 0) && (local_2230 == 0)) {
          local_8._0_1_ = 4;
          local_2260 = local_2234;
          local_225c = 0;
          local_2258 = 0;
          uVar7 = FUN_100015b0(&local_2260,local_21c);
          local_2260 = (HKEY)0x0;
          local_225c = 0;
          local_2258 = 0;
          if (uVar7 != 0) {
            FUN_10001430(uVar7);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar9 = &local_2260;
LAB_10006b5a:
            FUN_100021d0(ppHVar9);
            goto LAB_10006b5f;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100021d0(&local_2260);
        }
      }
      else {
        iVar4 = FUN_10001cf0(local_21c);
        if ((iVar4 != 0) && (local_2244 != 0)) {
          FUN_100021f0(&local_222c,local_21c);
        }
      }
    }
    else if (local_2254 == 0) {
      FUN_10001430(local_2230);
      goto LAB_10006b5f;
    }
  }
LAB_1000668a:
  if (*param_1 == L'}') goto LAB_10006b5f;
  goto LAB_10006510;
}



// Function: FUN_10006c90 at 10006c90

int __thiscall FUN_10006c90(void *this,int *param_1,undefined4 param_2,int *param_3)

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
  puStack_c = &LAB_1000db68;
  local_10 = ExceptionList;
  uVar3 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1001842c);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&DAT_10011904,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1001842c);
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
  iVar4 = FUN_10003710((int *)&DAT_1001841c,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: FUN_10006dc0 at 10006dc0

void __thiscall FUN_10006dc0(void *this,undefined4 param_1)

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
  puStack_c = &LAB_1000e1f9;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10007033;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_100182c8 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_100182cc == *piVar1) && (DAT_100182d0 == piVar1[1])) && (DAT_100182d4 == piVar1[2]))
        && ((DAT_100182d8 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_10018448,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007001;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001fb0((int *)&local_220);
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
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_10011a20,&local_220);
        if (-1 < iVar4) {
          FUN_10005ba0(&local_224,(int *)&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_10005e60(DAT_100182c8);
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
LAB_10007001:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_10004230(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10007033:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007060 at 10007060

void __fastcall FUN_10007060(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_10007090 at 10007090

void __fastcall FUN_10007090(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e250;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)
   ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x16) +
   *(int *)(*param_1 + 4) + -0x58) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  this = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 4);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10004100(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  local_8 = 0xffffffff;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x16))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007120 at 10007120

int * __thiscall FUN_10007120(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x58);
  FUN_10007090(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: DllGetClassObject at 10007150

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x7150  2  DllGetClassObject */
  iVar1 = FUN_10006c90(&DAT_100183d4,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_10007160 at 10007160

void __fastcall FUN_10007160(undefined4 *param_1)

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



// Function: FUN_100071f0 at 100071f0

int FUN_100071f0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
  iVar2 = FUN_100038e0(param_3);
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



// Function: FUN_100072e0 at 100072e0

LONG FUN_100072e0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_100182c8 + 4))();
  }
  return LVar1;
}



// Function: FUN_10007310 at 10007310

LONG FUN_10007310(int *param_1)

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
    (**(code **)(*DAT_100182c8 + 8))();
  }
  return LVar1;
}



// Function: FUN_10007360 at 10007360

void FUN_10007360(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100071f0(param_1,(int *)&PTR_DAT_10011acc,param_2,param_3);
  return;
}



// Function: FUN_10007380 at 10007380

undefined4 * __thiscall FUN_10007380(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e2e6;
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



// Function: FUN_10007410 at 10007410

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10007410(void *this,LPCWSTR param_1,int param_2)

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
  
  local_8 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  local_200c = (WCHAR *)0x0;
  iVar4 = FUN_10002d00(this,param_1,&local_200c);
  if (iVar4 < 0) {
LAB_10007525:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(WCHAR **)this = local_200c;
  WVar1 = *local_200c;
joined_r0x1000745e:
  if ((WVar1 == L'\0') || (iVar4 = FUN_10001b80(this,local_2008), iVar4 < 0)) goto LAB_10007516;
  uVar6 = 0;
  while (iVar4 = lstrcmpiW(local_2008,(LPCWSTR)(&PTR_u_HKCR_100115b8)[uVar6 * 2]), iVar4 != 0) {
    uVar6 = uVar6 + 1;
    if (0xd < uVar6) goto LAB_10007516;
  }
  pHVar2 = (HKEY)(&DAT_100115bc)[uVar6 * 2];
  if (((pHVar2 == (HKEY)0x0) || (iVar4 = FUN_10001b80(this,local_2008), iVar4 < 0)) ||
     (local_2008[0] != L'{')) goto LAB_10007516;
  if (param_2 == 0) {
    iVar4 = FUN_10006480(this,local_2008,pHVar2,0,0);
    if (iVar4 < 0) goto LAB_10007516;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *this;
    iVar4 = FUN_10006480(this,local_2008,pHVar2,param_2,0);
    if (iVar4 < 0) {
      *(undefined4 *)this = uVar3;
      FUN_10006480(this,local_2008,pHVar2,0,0);
LAB_10007516:
      CoTaskMemFree(local_200c);
      goto LAB_10007525;
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
      goto switchD_10007564_caseD_b;
    }
  } while( true );
switchD_10007564_caseD_b:
  WVar1 = *lpsz;
  goto joined_r0x1000745e;
}



// Function: FUN_100075b0 at 100075b0

int __thiscall FUN_100075b0(void *this,int param_1,byte *param_2)

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
         (bVar1 = FUN_10001020(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10002fc0((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_100035f0(0x1001841c,param_1,param_2);
  if ((-1 < iVar5) && (DAT_100182bc != (code *)0x0)) {
    iVar5 = (*DAT_100182bc)(DAT_10018448);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_10007650 at 10007650

int __thiscall FUN_10007650(void *this,int param_1,byte *param_2)

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
         (bVar1 = FUN_10001020(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10002fc0((GUID *)*piVar4,piVar3,iVar5);
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
  if ((DAT_100182c0 != (code *)0x0) && (iVar5 = (*DAT_100182c0)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_10003680(0x1001841c,param_1,param_2);
  return iVar5;
}



// Function: FUN_100076e0 at 100076e0

undefined4 __thiscall
FUN_100076e0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_10006dc0(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_100077ae;
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
LAB_100077ae:
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



// Function: FUN_10007800 at 10007800

void __fastcall FUN_10007800(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e318;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007870 at 10007870

undefined4 FUN_10007870(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10017708 == (int *)0x0) {
    uVar1 = FUN_10006dc0(&PTR_DAT_100176fc,param_3);
  }
  *param_4 = DAT_10017708;
  if (DAT_10017708 != (int *)0x0) {
    (**(code **)(*DAT_10017708 + 4))(DAT_10017708);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100078d0 at 100078d0

void FUN_100078d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100076e0(&PTR_DAT_100176fc,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007900 at 10007900

void FUN_10007900(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_10017708 == (int *)0x0) || (DAT_10017710 == 0)) {
    FUN_10006dc0(&PTR_DAT_100176fc,param_4);
  }
  if (DAT_10017708 != (int *)0x0) {
    (**(code **)(*DAT_10017708 + 0x2c))
              (DAT_10017708,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10007960 at 10007960

int * __thiscall FUN_10007960(void *this,int *param_1,uint param_2,uint param_3)

{
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
    FUN_10005870(this,uVar2 + param_2,0xffffffff);
    FUN_10005870(this,0,param_2);
    return (int *)this;
  }
  if (uVar2 == 0xffffffff) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10005900(this,uVar2);
    piVar1 = param_1;
    if (uVar2 == 0) {
      return (int *)this;
    }
  }
  else if (uVar2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined1 *)this = 0;
    return (int *)this;
  }
  if (0xf < (uint)piVar1[5]) {
    piVar1 = (int *)*piVar1;
  }
  _Dst = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    _Dst = *this;
  }
  memcpy(_Dst,(void *)((int)piVar1 + param_2),uVar2);
  *(uint *)((int)this + 0x10) = uVar2;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + uVar2) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined1 *)(*this + uVar2) = 0;
  return (int *)this;
}



// Function: FUN_10007a50 at 10007a50

int * __thiscall FUN_10007a50(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_100057e0(this,uVar2 + param_2,0xffffffff);
    FUN_100057e0(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10005a50(this,uVar2);
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



// Function: FUN_10007b50 at 10007b50

int * __thiscall FUN_10007b50(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  void *pvVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar2 = (int *)this;
    if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar3 = this;
      if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      if (param_1 < (int *)(*(int *)((int)this + 0x10) + (int)pvVar3)) {
        if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
          piVar2 = FUN_10007960(this,(int *)this,(int)param_1 - *this,param_2);
          return piVar2;
        }
        piVar2 = FUN_10007960(this,(int *)this,(int)param_1 - (int)this,param_2);
        return piVar2;
      }
    }
  }
  if (param_2 == 0xffffffff) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10005900(this,param_2);
    if (param_2 == 0) {
      return (int *)this;
    }
  }
  else if (param_2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined1 *)this = 0;
    return (int *)this;
  }
  pvVar3 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar3 = *this;
  }
  memcpy(pvVar3,param_1,param_2);
  *(uint *)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + param_2) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined1 *)(*this + param_2) = 0;
  return (int *)this;
}



// Function: FUN_10007c50 at 10007c50

int * __thiscall FUN_10007c50(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_10007a50(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10005a50(this,param_2);
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



// Function: FUN_10007d50 at 10007d50

long __cdecl FUN_10007d50(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined **local_bc [4];
  undefined **local_ac [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  undefined4 local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  long local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e3a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_bc[0] = &PTR_10011a98;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 0;
  local_1c = 1;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac,
             false);
  local_8 = 1;
  *(undefined ***)((int)local_bc + (int)local_bc[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar1 = param_1 + 4;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  FUN_10004f60(local_ac,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             &local_14);
  *(undefined ***)((int)local_bc + (int)local_bc[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10004100(local_18);
  local_8 = CONCAT31(local_8._1_3_,5);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = 0xffffffff;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10007eb0 at 10007eb0

int __cdecl FUN_10007eb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined **local_bc [4];
  undefined **local_ac [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  undefined4 local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e3a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_bc[0] = &PTR_10011a98;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 0;
  local_1c = 1;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac,
             false);
  local_8 = 1;
  *(undefined ***)((int)local_bc + (int)local_bc[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar1 = param_1 + 4;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  FUN_10004f60(local_ac,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             &local_14);
  *(undefined ***)((int)local_bc + (int)local_bc[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10004100(local_18);
  local_8 = CONCAT31(local_8._1_3_,5);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = 0xffffffff;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10008010 at 10008010

float10 __cdecl FUN_10008010(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined **local_c0 [4];
  undefined **local_b0 [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_68 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_20;
  float local_1c [2];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e435;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c[1] = 0.0;
  local_c0[0] = &PTR_10011a98;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_68);
  local_8 = 0;
  local_1c[1] = 1.4013e-45;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c0,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0,
             false);
  local_8 = 1;
  *(undefined ***)((int)local_c0 + (int)local_c0[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar1 = param_1 + 4;
  local_b0[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  FUN_10004f60(local_b0,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c0,
             local_1c);
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_68;
  *(undefined ***)((int)local_c0 + (int)local_c0[0][1]) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_20 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0;
  local_b0[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10004100(local_20);
  local_8 = CONCAT31(local_8._1_3_,5);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  local_8 = 0xffffffff;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_68);
  ExceptionList = local_10;
  return (float10)local_1c[0];
}



// Function: DllRegisterServer at 10008170

void DllRegisterServer(void)

{
                    /* 0x8170  3  DllRegisterServer */
  FUN_100075b0(&DAT_100183d4,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 10008180

void DllUnregisterServer(void)

{
                    /* 0x8180  4  DllUnregisterServer */
  FUN_10007650(&DAT_100183d4,1,(byte *)0x0);
  return;
}



// Function: FUN_10008190 at 10008190

DWORD FUN_10008190(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e46b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10007160(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10008236();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10008223 at 10008223

undefined * Catch_10008223(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008230;
}



// Function: FUN_10008236 at 10008236

DWORD FUN_10008236(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10008293;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000826b;
  }
  else {
LAB_1000826b:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_10008293;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10008293:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100082b0 at 100082b0

void __fastcall FUN_100082b0(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[3] = IXMLSerializationImpl<struct_CConnectionData,void*>::vftable;
  *param_1 = CConnectionData::vftable;
  param_1[1] = CConnectionData::vftable;
  param_1[2] = CConnectionData::vftable;
  param_1[3] = CConnectionData::vftable;
  param_1[0x11] = 7;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  param_1[0x18] = 7;
  param_1[0x17] = 0;
  *(undefined2 *)(param_1 + 0x13) = 0;
  return;
}



// Function: FUN_10008370 at 10008370

undefined4 __fastcall FUN_10008370(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &TSimpleObject<struct_CConnectionData,&struct__GUID_const_CLSID_ConnectionData,struct_IConnectionData,&struct__GUID_const_IID_IConnectionData,&struct__GUID_const_LIBID_CONNECTIONDATALib,101>
                   ::RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0);
  return 0;
}



// Function: FUN_10008390 at 10008390

undefined4 FUN_10008390(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)(param_1,param_2,&param_1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return uVar1;
}



// Function: FUN_100083c0 at 100083c0

bool __cdecl FUN_100083c0(int param_1)

{
  return param_1 != 0;
}



// Function: AtlAdd<> at 100083d0

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



// Function: FUN_10008400 at 10008400

void FUN_10008400(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  if (param_3 == (undefined4 *)0x0) {
    __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_3 = 0;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008450 at 10008450

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_10008450(int param_1)

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
  
  pcStack_10 = FUN_1000ceb0;
  local_14 = ExceptionList;
  local_c = DAT_100182a0 ^ 0x100142a8;
  local_38 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10008510 at 10008510

undefined4 * __thiscall FUN_10008510(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (-param_1 - 1U < 8) {
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x80070216);
  }
  puVar1 = (undefined4 *)malloc(param_1 + 8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
                    /* WARNING: Load size is inaccurate */
  *puVar1 = *this;
  *(undefined4 **)this = puVar1;
  return puVar1 + 2;
}



// Function: FUN_10008560 at 10008560

void __fastcall FUN_10008560(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e503;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((*(byte *)(param_1 + 0x14) & 2) != 0) {
    piVar3 = *(int **)(param_1 + 8);
    if (piVar3 != *(int **)(param_1 + 0xc)) {
      do {
        piVar1 = (int *)*piVar3;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1,uVar2);
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != *(int **)(param_1 + 0xc));
    }
    operator_delete__(*(void **)(param_1 + 8));
  }
  local_8 = 0xffffffff;
  piVar3 = *(int **)(param_1 + 4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100085f0 at 100085f0

void __cdecl FUN_100085f0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e528;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_1,DAT_100182a0 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(0x8007000e);
    }
  }
  *param_2 = iVar1;
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008670 at 10008670

undefined4 FUN_10008670(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e550;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_100083c0((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_100085f0((undefined4 *)(param_1 + 0x28),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100086f6 at 100086f6

undefined1 * Catch_100086f6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008703;
}



// Function: FUN_10008720 at 10008720

undefined4 FUN_10008720(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e570;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_100083c0((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_100085f0((undefined4 *)(param_1 + 0x44),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100087a6 at 100087a6

undefined1 * Catch_100087a6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100087b3;
}



// Function: FUN_100087d0 at 100087d0

void __fastcall FUN_100087d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e598;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10008560(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008820 at 10008820

undefined4 __thiscall FUN_10008820(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e5c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 == 3) {
    local_8 = 0;
    lVar2 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar3 = FUN_1000cc6d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)((int)this + 8) = uVar3;
    local_8 = 0xffffffff;
    uVar3 = FUN_100088a4();
    return uVar3;
  }
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  if (*(int **)((int)this + 4) != param_3) {
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 4))(param_3);
    }
    piVar1 = *(int **)((int)this + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)((int)this + 4) = param_3;
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10008891 at 10008891

undefined * Catch_10008891(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000889e;
}



// Function: FUN_100088a4 at 100088a4

undefined4 FUN_100088a4(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar2;
  
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 8);
  if (*(int *)(unaff_ESI + 8) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  piVar2 = *(int **)(unaff_EBP + 8);
  if (piVar2 != unaff_EBX) {
    do {
      if ((*(int **)(unaff_ESI + 0x10) == (int *)0x0) || (piVar2 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_100010c0(0x80004005);
      }
      piVar1 = (int *)*piVar2;
      **(int **)(unaff_ESI + 0x10) = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 4;
      piVar2 = piVar2 + 1;
    } while (piVar2 != unaff_EBX);
    piVar2 = *(int **)(unaff_EBP + 8);
  }
  *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 8) + ((int)unaff_EBX - (int)piVar2 >> 2) * 4;
  piVar2 = *(int **)(unaff_EBP + 0x10);
  if (*(int **)(unaff_ESI + 4) != piVar2) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    piVar1 = *(int **)(unaff_ESI + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(unaff_ESI + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10008970 at 10008970

undefined4 * __fastcall FUN_10008970(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e603;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 3;
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_100182c8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10008a00 at 10008a00

undefined4 FUN_10008a00(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_10008a20 at 10008a20

bool FUN_10008a20(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_10008a50 at 10008a50

undefined4 FUN_10008a50(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_10008a60 at 10008a60

int FUN_10008a60(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 6;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[6];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(1);
  }
  return iVar2;
}



// Function: FUN_10008a90 at 10008a90

uint FUN_10008a90(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = param_4;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((param_3 != (int *)0x0) && ((param_2 < 2 || (param_4 != (uint *)0x0)))) {
    if ((*(int *)(param_1 + 8) != 0) &&
       ((*(int *)(param_1 + 0xc) != 0 && (*(int *)(param_1 + 0x10) != 0)))) {
      uVar3 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
      param_4 = (uint *)(uint)(uVar3 < param_2);
      if (uVar3 <= param_2) {
        param_2 = uVar3;
      }
      if (puVar2 != (uint *)0x0) {
        *puVar2 = param_2;
      }
      while( true ) {
        if (param_2 == 0) {
          return (uint)param_4;
        }
        param_2 = param_2 - 1;
        if ((param_3 == (int *)0x0) || (*(int **)(param_1 + 0x10) == (int *)0x0)) break;
        piVar1 = (int *)**(int **)(param_1 + 0x10);
        *param_3 = (int)piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4;
        param_3 = param_3 + 1;
      }
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(0x80004005);
    }
    return 0x80004005;
  }
  return 0x80004003;
}



// Function: FUN_10008b60 at 10008b60

void FUN_10008b60(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100071f0(param_1,(int *)&PTR_DAT_10011ba0,param_2,param_3);
  return;
}



// Function: FUN_10008b80 at 10008b80

undefined4 * __thiscall FUN_10008b80(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e630;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_100182c8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10008560((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008c00 at 10008c00

undefined4 FUN_10008c00(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e650;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10008970(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_10008ca3();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_10008ca3();
  return uVar2;
}



// Function: Catch@10008c8d at 10008c8d

undefined * Catch_10008c8d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008c9a;
}



// Function: FUN_10008ca3 at 10008ca3

undefined4 FUN_10008ca3(void)

{
  int in_EAX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int *unaff_EDI;
  
  if (in_EAX != 0) {
    unaff_ESI = 0;
  }
  *unaff_EDI = in_EAX;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_10008cd0 at 10008cd0

int FUN_10008cd0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e678;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10008970(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_10008d6b();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_10008d6b();
  return iVar2;
}



// Function: Catch@10008d59 at 10008d59

undefined * Catch_10008d59(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008d66;
}



// Function: FUN_10008d6b at 10008d6b

int FUN_10008d6b(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != unaff_EBX) {
    *(int **)(unaff_EBP + -0x14) = unaff_EBX;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    cVar1 = FUN_10008450((int)unaff_EBX);
    if (cVar1 == '\0') {
      piVar2 = FUN_10008510((void *)(unaff_EBP + -0x14),(int)unaff_EBX);
      if (piVar2 != unaff_EBX) {
        iVar3 = FUN_10008820(unaff_ESI,(int)piVar2,(int)piVar2,*(int **)(unaff_EBP + 8),3);
        if ((int)unaff_EBX <= iVar3) {
          iVar3 = (**(code **)*unaff_ESI)();
          if ((int)unaff_EBX <= iVar3) goto LAB_10008dfc;
        }
        (**(code **)(*unaff_ESI + 0x1c))(1);
LAB_10008dfc:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_10001fb0((int *)(unaff_EBP + -0x14));
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return iVar3;
      }
    }
    (**(code **)(*unaff_ESI + 0x1c))(1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10001fb0((int *)(unaff_EBP + -0x14));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -0x7ff8fff2;
}



// Function: FUN_10008e30 at 10008e30

undefined4 FUN_10008e30(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10017c48 == (int *)0x0) {
    uVar1 = FUN_10006dc0(&PTR_DAT_10017c3c,param_3);
  }
  *param_4 = DAT_10017c48;
  if (DAT_10017c48 != (int *)0x0) {
    (**(code **)(*DAT_10017c48 + 4))(DAT_10017c48);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10008e90 at 10008e90

void FUN_10008e90(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100076e0(&PTR_DAT_10017c3c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008ec0 at 10008ec0

void FUN_10008ec0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_10017c48 == (int *)0x0) || (DAT_10017c50 == 0)) {
    FUN_10006dc0(&PTR_DAT_10017c3c,param_4);
  }
  if (DAT_10017c48 != (int *)0x0) {
    (**(code **)(*DAT_10017c48 + 0x2c))
              (DAT_10017c48,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10008f20 at 10008f20

void FUN_10008f20(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10008f40 at 10008f40

void FUN_10008f40(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10008f60 at 10008f60

void FUN_10008f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_10008f80 at 10008f80

void FUN_10008f80(int param_1)

{
  FUN_10008f20(param_1 + -8);
  return;
}



// Function: FUN_10008f90 at 10008f90

void FUN_10008f90(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008f60(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10008fa0 at 10008fa0

void FUN_10008fa0(int param_1)

{
  FUN_10008f20(param_1 + -0xc);
  return;
}



// Function: FUN_10008fb0 at 10008fb0

void FUN_10008fb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008f60(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10008fc0 at 10008fc0

void FUN_10008fc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008f60(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10008fd0 at 10008fd0

void FUN_10008fd0(int param_1)

{
  FUN_10008f40(param_1 + -4);
  return;
}



// Function: FUN_10008fe0 at 10008fe0

void FUN_10008fe0(int param_1)

{
  FUN_10008f40(param_1 + -8);
  return;
}



// Function: FUN_10008ff0 at 10008ff0

void FUN_10008ff0(int param_1)

{
  FUN_10008f40(param_1 + -0xc);
  return;
}



// Function: FUN_10009000 at 10009000

void FUN_10009000(int param_1)

{
  FUN_10008f20(param_1 + -4);
  return;
}



// Function: FUN_10009010 at 10009010

int FUN_10009010(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e6f2;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_10008c00(&local_1c);
    if (-1 < (int)piVar2) {
      if ((*(byte *)(param_1 + 5) & 2) == 0) {
        local_18 = (int *)param_1[1];
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 4))(local_18,uVar1);
        }
        local_8 = 3;
        uVar1 = 2;
      }
      else {
        local_18 = param_1;
        (**(code **)(*param_1 + 4))(param_1);
        uVar1 = 1;
        local_8 = 1;
      }
      local_14 = uVar1;
      piVar2 = (int *)FUN_10008820(local_1c,param_1[2],param_1[3],local_18,0);
      if ((uVar1 & 2) != 0) {
        uVar1 = uVar1 & 0xfffffffd;
        local_8 = 1;
        local_14 = uVar1;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      local_8 = 0xffffffff;
      if ((uVar1 & 1) != 0) {
        local_14 = uVar1 & 0xfffffffe;
        local_8 = 0xffffffff;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      if (-1 < (int)piVar2) {
        local_1c[4] = param_1[4];
        piVar2 = (int *)FUN_100071f0((int)local_1c,(int *)&PTR_DAT_10011ba0,(int *)&DAT_10011bb8,
                                     param_2);
        if (-1 < (int)piVar2) {
          ExceptionList = local_10;
          return (int)piVar2;
        }
      }
      param_1 = piVar2;
      piVar2 = param_1;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x1c))(1);
      }
    }
  }
  ExceptionList = local_10;
  return (int)piVar2;
}



// Function: FUN_10009170 at 10009170

void FUN_10009170(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
  
  puStack_c = &LAB_1000e726;
  local_10 = ExceptionList;
  uStack_444 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_444;
  ExceptionList = &local_10;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = uStack_444;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    FUN_10001410();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      FUN_10001410();
    }
    else {
      pvVar1 = LoadResource(hModule,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        FUN_10001410();
      }
      else {
        DVar2 = SizeofResource(hModule,hResInfo);
        if (DVar2 <= DVar2 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10003b10(&local_41c,DVar2 + 1);
          local_8 = 1;
          FUN_1000927d();
          return;
        }
      }
    }
    FreeLibrary(hModule);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10002030(&local_41c);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000925e at 1000925e

undefined * Catch_1000925e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000926b;
}



// Function: FUN_1000927d at 1000927d

void FUN_1000927d(void)

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
      FUN_10001410();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x418) + iVar1 * 2) = 0;
      FUN_10007410((void *)(unaff_EBP - 0x42c),*(LPCWSTR *)(unaff_EBP - 0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(unaff_ESI);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x418) != unaff_EBP - 0x414) {
    FUN_10002030((undefined4 *)(unaff_EBP - 0x418));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10009310;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10009320 at 10009320

void FUN_10009320(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e758;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10009170(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009380 at 10009380

undefined4 FUN_10009380(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e758;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10009170(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_10009400 at 10009400

void FUN_10009400(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e758;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10009170(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009460 at 10009460

undefined4 FUN_10009460(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e758;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10009170(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_100094e0 at 100094e0

void FUN_100094e0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1000e7b7;
  local_10 = ExceptionList;
  uVar6 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
        FUN_10005e90(pWVar2,param_4[1]);
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
  pHVar3 = DAT_10018448;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_10018448,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10001410();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001fb0((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10002c00(&local_a5c);
        goto LAB_10009759;
      }
      FUN_10001550(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001090(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001fb0((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10002c00(&local_a5c);
          goto LAB_10009759;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10006040(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10006040(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10009460(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10009380(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001fb0((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10002c00(&local_a5c);
LAB_10009759:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009780 at 10009780

void FUN_10009780(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1000e817;
  local_10 = ExceptionList;
  uVar6 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
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
        FUN_10005e90(pWVar2,param_4[1]);
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
  pHVar3 = DAT_10018448;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_10018448,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10001410();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001fb0((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10002c00(&local_a5c);
        goto LAB_100099e3;
      }
      FUN_10001550(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001090(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001fb0((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10002c00(&local_a5c);
          goto LAB_100099e3;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10006040(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10006040(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10009400(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10009320(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001fb0((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10002c00(&local_a5c);
LAB_100099e3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009a00 at 10009a00

undefined4 * __fastcall FUN_10009a00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e848;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100082b0(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CConnectionData>::vftable;
  param_1[1] = ATL::CComObject<struct_CConnectionData>::vftable;
  param_1[2] = ATL::CComObject<struct_CConnectionData>::vftable;
  param_1[3] = ATL::CComObject<struct_CConnectionData>::vftable;
  (**(code **)(*DAT_100182c8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009a80 at 10009a80

void FUN_10009a80(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_10009aa0 at 10009aa0

LONG FUN_10009aa0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_10009ad0 at 10009ad0

void FUN_10009ad0(int param_1)

{
  FUN_10009aa0((int *)(param_1 + -4));
  return;
}



// Function: FUN_10009ae0 at 10009ae0

void FUN_10009ae0(int param_1)

{
  FUN_10009aa0((int *)(param_1 + -8));
  return;
}



// Function: FUN_10009af0 at 10009af0

void FUN_10009af0(int param_1)

{
  FUN_10009aa0((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10009b00 at 10009b00

void FUN_10009b00(int param_1)

{
  FUN_10009a80(param_1 + -4);
  return;
}



// Function: FUN_10009b10 at 10009b10

void FUN_10009b10(int param_1)

{
  FUN_10009a80(param_1 + -8);
  return;
}



// Function: FUN_10009b20 at 10009b20

void FUN_10009b20(int param_1)

{
  FUN_10009a80(param_1 + -0xc);
  return;
}



// Function: FUN_10009b30 at 10009b30

void FUN_10009b30(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100071f0(param_1,(int *)&PTR_DAT_10011d18,param_2,param_3);
  return;
}



// Function: FUN_10009b50 at 10009b50

void FUN_10009b50(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009b30(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10009b60 at 10009b60

void FUN_10009b60(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009b30(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10009b70 at 10009b70

void FUN_10009b70(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009b30(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10009b80 at 10009b80

undefined4 * __thiscall FUN_10009b80(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e848;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<struct_CConnectionData>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_100182c8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10003c20((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009c10 at 10009c10

undefined4 * __thiscall FUN_10009c10(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e883;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CConnectionData>::vftable;
  FUN_100082b0((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CConnectionData>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CConnectionData>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_100182c8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009cb0 at 10009cb0

void FUN_10009cb0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10009cd0 at 10009cd0

LONG FUN_10009cd0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_10009d00 at 10009d00

int FUN_10009d00(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_100071f0((int)(param_1 + 3),(int *)&PTR_DAT_10011d18,param_2,param_3);
  return iVar1;
}



// Function: FUN_10009d70 at 10009d70

undefined4 * __thiscall FUN_10009d70(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e8b3;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<struct_CConnectionData>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_100182c8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10003c20((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009e00 at 10009e00

void FUN_10009e00(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_100094e0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009e10 at 10009e10

void FUN_10009e10(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10009780(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009e20 at 10009e20

void __cdecl FUN_10009e20(int *param_1)

{
  ushort ****ppppuVar1;
  int iVar2;
  uint uVar3;
  ushort ****ppppuVar4;
  ushort ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e8d8;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  FUN_10007a50(local_30,param_1,0,0xffffffff);
  local_8 = 0;
  ppppuVar4 = (ushort ****)local_30[0];
  if (local_1c < 8) {
    ppppuVar4 = local_30;
  }
  iVar2 = local_20 * 2;
  ppppuVar1 = (ushort ****)local_30[0];
  if (local_1c < 8) {
    ppppuVar1 = local_30;
  }
  for (; ppppuVar1 != (ushort ****)((int)ppppuVar4 + iVar2);
      ppppuVar1 = (ushort ****)((int)ppppuVar1 + 2)) {
    toupper((uint)*(ushort *)ppppuVar1);
  }
  uVar3 = FUN_10004070(local_30,0,local_20,(ushort *)L"TRUE",4);
  if (uVar3 != 0) {
    uVar3 = FUN_10004070(local_30,0,local_20,(ushort *)L"FALSE",5);
    if (uVar3 == 0) {
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
      goto LAB_10009f75;
    }
    uVar3 = FUN_10004070(local_30,0,local_20,(ushort *)&DAT_10011db8,1);
    if (uVar3 != 0) {
      FUN_10004070(local_30,0,local_20,(ushort *)&DAT_10011db4,1);
      local_8 = 0xffffffff;
      FUN_10003bf0(local_30);
      goto LAB_10009f75;
    }
  }
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
LAB_10009f75:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009fa0 at 10009fa0

undefined1 * __thiscall FUN_10009fa0(void *this,undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e919;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_10007960(param_1,(int *)this,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a010 at 1000a010

undefined4 * __thiscall FUN_1000a010(void *this,undefined4 *param_1)

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



// Function: FUN_1000a090 at 1000a090

void FUN_1000a090(int param_1)

{
  FUN_10009780((int *)&DAT_100183d4,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000a0b0 at 1000a0b0

DWORD FUN_1000a0b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e940;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x68);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10009a00(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000a157();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000a157();
  return DVar2;
}



// Function: Catch@1000a144 at 1000a144

undefined * Catch_1000a144(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a151;
}



// Function: FUN_1000a157 at 1000a157

DWORD FUN_1000a157(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_1000a1c8;
  InterlockedIncrement(unaff_ESI + 4);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 5),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000a190;
  }
  else {
LAB_1000a190:
    *(undefined1 *)(unaff_ESI + 0xb) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = 0;
    }
  }
  InterlockedDecrement(unaff_ESI + 4);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_1000a1c8;
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_1000a1c8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000a1e0 at 1000a1e0

int * FUN_1000a1e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000e96b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x74);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10009c10(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000a296();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000a296();
  return piVar1;
}



// Function: Catch@1000a281 at 1000a281

undefined * Catch_1000a281(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a28e;
}



// Function: FUN_1000a296 at 1000a296

int * FUN_1000a296(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10002990((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_1000a2c7;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000a2c7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000a2e0 at 1000a2e0

undefined2 * __cdecl FUN_1000a2e0(undefined2 *param_1,char param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000e9a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pwVar3 = L"true";
  if (param_2 == '\0') {
    pwVar3 = L"false";
  }
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  pwVar2 = pwVar3;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_10007c50(param_1,(int *)pwVar3,(int)pwVar2 - (int)(pwVar3 + 1) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a370 at 1000a370

undefined2 * __cdecl FUN_1000a370(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 local_24 [4];
  int *local_1c;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000e9f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_8 = 1;
  local_24[0] = 0;
  iVar1 = Ordinal_10(local_24,&stack0x00000008,DAT_100182a0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    local_24[0] = 10;
    local_1c = (int *)iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(iVar1);
  }
  local_8._0_1_ = 2;
  FUN_1000cb10(8,(int)local_24,0,0x409);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  piVar2 = local_1c;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007c50(param_1,local_1c,(int)piVar2 - ((int)local_1c + 2) >> 1);
  local_14 = 1;
  local_8._0_1_ = 1;
  Ordinal_9(local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(&stack0x00000008);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a460 at 1000a460

void __cdecl FUN_1000a460(int *param_1,float *param_2,type_info *param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  
  uVar5 = 0;
  uVar6 = 0xffffffff;
  do {
    if (uVar6 != 0xffffffff) break;
    bVar1 = type_info::operator==(param_3,(type_info *)(&PTR_RTTI_Type_Descriptor_10017d48)[uVar5]);
    if (bVar1) {
      uVar6 = uVar5;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  switch(uVar6) {
  case 0:
    FUN_10007a50(param_2,param_1,0,0xffffffff);
    return;
  case 1:
    uVar2 = FUN_10009e20(param_1);
    *(undefined1 *)param_2 = uVar2;
    return;
  case 2:
    fVar4 = (float)FUN_10007d50(param_1);
    *param_2 = fVar4;
    break;
  case 3:
    fVar4 = (float)FUN_10007eb0(param_1);
    *param_2 = fVar4;
    return;
  case 4:
    fVar7 = FUN_10008010(param_1);
    *param_2 = (float)fVar7;
    return;
  case 5:
    if (7 < (uint)param_1[5]) {
      param_1 = (int *)*param_1;
    }
    iVar3 = Ordinal_9(param_2);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(iVar3);
    }
    *(undefined2 *)param_2 = 8;
    fVar4 = (float)Ordinal_2(param_1);
    param_2[2] = fVar4;
    if ((fVar4 == 0.0) && (param_1 != (int *)0x0)) {
      *(undefined2 *)param_2 = 10;
      param_2[2] = -6.42868e-40;
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(0x8007000e);
    }
  }
  return;
}



// Function: FUN_1000a580 at 1000a580

undefined2 * __cdecl FUN_1000a580(undefined2 *param_1,char *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a2e0(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a5e0 at 1000a5e0

undefined2 * __cdecl FUN_1000a5e0(undefined2 *param_1,undefined4 param_2)

{
  undefined2 local_30 [4];
  int local_28;
  uint uStack_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ea41;
  local_10 = ExceptionList;
  uStack_20 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = 0;
  local_28 = Ordinal_10(local_30,param_2);
  if (local_28 < 0) {
    local_30[0] = 10;
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(local_28);
  }
  local_8 = 0;
  FUN_1000a370(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a680 at 1000a680

void __thiscall FUN_1000a680(void *this,undefined2 *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ea91;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(byte *)((int)this + 0x40) & 2) == 0) &&
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 != (ushort *)0x0)) {
    puVar1 = *(ushort **)((int)this + 0x3c);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 < puVar2) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
    }
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    local_1c = 7;
    local_20 = 0;
    FUN_10007c50(&local_30,(int *)puVar3,(int)puVar1 - (int)puVar2 >> 1);
    local_8 = 1;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a010(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  else if (((*(byte *)((int)this + 0x40) & 4) == 0) &&
          (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                    gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar1 != (ushort *)0x0)) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    local_1c = 7;
    local_20 = 0;
    FUN_10007c50(&local_30,(int *)puVar3,(int)puVar2 - (int)puVar1 >> 1);
    local_8 = 2;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a010(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  else {
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    local_8 = 3;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a010(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  local_1c = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a880 at 1000a880

undefined4 FUN_1000a880(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007c50((void *)(param_1 + 0x28),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000a8c0 at 1000a8c0

undefined4 FUN_1000a8c0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007c50((void *)(param_1 + 0x44),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000a900 at 1000a900

void FUN_1000a900(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000a0b0(0,param_2,param_3);
    return;
  }
  FUN_1000a1e0(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000a930 at 1000a930

undefined2 * __thiscall FUN_1000a930(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a680((void *)((int)this + 4),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a990 at 1000a990

void __thiscall FUN_1000a990(void *this,int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  TypeDescriptor *pTVar3;
  
  pTVar3 = (TypeDescriptor *)0x0;
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)
                     &std::
                      basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                      ::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &std::
              basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::RTTI_Type_Descriptor;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_10017dac);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_10017dac;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_10017db8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_10017db8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_100173a4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_100173a4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CConnectionData,void*>::
                                  RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000a460(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_1000aa40 at 1000aa40

void __thiscall FUN_1000aa40(void *this,undefined2 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eae1;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)(**(code **)((int)this + 0x1c))(local_30,param_2,local_14);
  local_8 = 1;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_1000a010(param_1,puVar1);
  local_8 = local_8 & 0xffffff00;
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



// Function: FUN_1000aaf0 at 1000aaf0

undefined2 * __thiscall FUN_1000aaf0(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a680((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ab50 at 1000ab50

undefined2 * __thiscall
FUN_1000ab50(void *this,undefined2 *param_1,
            basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *local_b4;
  undefined **local_b0;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_ac [56];
  undefined4 local_74;
  undefined4 local_70;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ebae;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 1;
  uVar3 = 0;
  local_18 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_b4 + *(int *)(local_b4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0);
  local_b0 = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_74 = 0;
  local_70 = 4;
  local_8 = 6;
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CConnectionData,void*>::
                                  RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0,
                          uVar3,uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_100119cc,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_10005220((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000a930(&local_b4,param_1);
  local_18 = 3;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  param_2 = local_64;
  *(undefined ***)((int)&local_b4 + *(int *)(local_b4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0;
  local_b0 = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_8._0_1_ = 0xd;
  local_8._1_3_ = 0;
  FUN_10004100(local_1c);
  local_8._0_1_ = 0xb;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ad20 at 1000ad20

undefined2 * __thiscall
FUN_1000ad20(void *this,undefined2 *param_1,
            basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined *local_b0;
  undefined **local_ac;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_a8 [56];
  undefined4 local_70;
  uint local_6c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_60 [72];
  undefined4 local_18;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ec6e;
  local_10 = ExceptionList;
  uVar2 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_60);
  local_8 = 1;
  uVar6 = 0;
  local_18 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_b0,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_b0 + *(int *)(local_b0 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac);
  local_ac = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_70 = 0;
  local_6c = 4;
  local_8 = 6;
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CConnectionData,void*>::
                                  RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0,
                          uVar6,uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_100119cc,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_10005220((int *)&local_b0,(ushort *)param_2);
        local_8._0_1_ = 8;
        Ordinal_6(param_2);
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      if (local_14 !=
          (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
        (**(code **)(*(int *)local_14 + 8))(local_14);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(piVar5[1] - *piVar5 >> 2));
  }
  FUN_1000a930(&local_b0,param_1);
  local_18 = 3;
  param_2 = local_60;
  *(undefined ***)((int)&local_b0 + *(int *)(local_b0 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac;
  local_ac = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_8._0_1_ = 0xd;
  local_8._1_3_ = 0;
  if ((local_6c & 1) != 0) {
    puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (local_14);
    if (puVar4 == (ushort *)0x0) {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 &local_ac);
    }
    else {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 &local_ac);
    }
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac
              );
    puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        &local_ac);
    operator_delete(puVar4);
  }
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
             (ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
             (ushort *)0x0,(ushort *)0x0);
  local_6c = local_6c & 0xfffffffe;
  local_70 = 0;
  local_8._0_1_ = 0xb;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_a8);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_60);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000af80 at 1000af80

void FUN_1000af80(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 local_4c [8];
  int *local_44;
  int local_3c;
  void *local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ecc0;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_100119dc,&local_34,local_14);
  Ordinal_8(local_4c);
  piVar2 = local_34;
  local_8._0_1_ = 2;
  if (*param_2 == 0) {
    local_3c = 0;
  }
  else {
    local_3c = Ordinal_2(*param_2);
    if (local_3c == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1000cb10(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007c50(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_1000a990(local_38,&local_30,(int)param_2);
  local_8._0_1_ = 2;
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_9(local_4c);
  local_8 = 0xffffffff;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b100 at 1000b100

void FUN_1000b100(int *param_1,int param_2)

{
  int iVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  ushort *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined *local_e4;
  undefined **local_e0;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_dc [56];
  undefined4 local_a4;
  undefined4 local_a0;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_94 [72];
  undefined4 local_4c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_48;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_44;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_40;
  int *local_3c;
  int *local_38;
  undefined4 local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  ushort *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000eda0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_100182a0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10011aa0;
  local_14 = puVar3;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_94);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_4c = 1;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e0,
             false);
  local_8 = 3;
  *(undefined ***)((int)&local_e4 + *(int *)(local_e4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_40 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e0;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e0);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_e0 = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_a4 = 0;
  local_a0 = 4;
  local_8._0_1_ = 7;
  piVar4 = (int *)FUN_10005220((int *)&local_e4,(ushort *)&DAT_10011dec);
  FUN_10005220(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000a930(&local_e4,(undefined2 *)local_30);
  local_8._0_1_ = 8;
  if (7 < (uint)puVar5[5]) {
    puVar5 = (undefined4 *)*puVar5;
  }
  if (puVar5 == (undefined4 *)0x0) {
    local_40 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
  }
  else {
    local_40 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               Ordinal_2(puVar5);
    if (local_40 == (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0)
    {
                    /* WARNING: Subroutine does not return */
      FUN_100010c0(0x8007000e);
    }
  }
  pbVar2 = local_40;
  local_8._0_1_ = 9;
  (**(code **)(*(int *)local_48 + 0x94))(local_48,local_40,&local_38);
  local_8._0_1_ = 8;
  Ordinal_6(pbVar2);
  local_8._0_1_ = 7;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  iVar6 = __RTDynamicCast(local_44,0,
                          &IXMLSerializationImpl<struct_CConnectionData,void*>::RTTI_Type_Descriptor
                          ,&CConnectionData::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_100119cc,&local_3c);
  (**(code **)(*local_3c + 0x20))(local_3c,local_34);
  local_8._0_1_ = 10;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8._0_1_ = 7;
  Ordinal_6(local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  local_44 = local_94;
  *(undefined ***)((int)&local_e4 + *(int *)(local_e4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e0;
  local_e0 = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_8._0_1_ = 0x10;
  FUN_10004100(local_48);
  local_8._0_1_ = 0xe;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_e0);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_dc);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_94);
  local_8 = 0xffffffff;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b3a0 at 1000b3a0

undefined2 * __cdecl FUN_1000b3a0(undefined2 *param_1,void *param_2)

{
  uint in_stack_0000001c;
  undefined *local_c8 [4];
  undefined *local_b8 [2];
  undefined **local_b0 [15];
  undefined4 local_74;
  undefined4 local_70;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_68 [72];
  undefined2 *local_20;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000ee56;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = param_1;
  local_14 = 0;
  local_8 = 1;
  local_c8[0] = &DAT_10011aa8;
  local_b8[0] = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_68);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = 2;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c8,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  local_8 = 3;
  *(undefined ***)((int)local_c8 + *(int *)(local_c8[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_b0[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_74 = 0;
  local_70 = 0;
  local_8._0_1_ = 7;
  FUN_10004ff0((int *)local_b8,(ushort *)&param_2);
  FUN_1000aaf0(local_c8,param_1);
  local_14 = 3;
  local_8 = (uint)local_8._1_3_ << 8;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_68;
  *(undefined ***)((int)local_c8 + *(int *)(local_c8[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0;
  local_b0[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 10;
  FUN_10004100(local_1c);
  local_8._0_1_ = 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  local_8._0_1_ = 1;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_68);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < in_stack_0000001c) {
    operator_delete(param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b530 at 1000b530

undefined2 * __cdecl FUN_1000b530(undefined2 *param_1,long param_2)

{
  undefined *local_c4 [4];
  undefined *local_b4 [2];
  undefined **local_ac [15];
  undefined4 local_70;
  undefined4 local_6c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eefe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10011aa8;
  local_b4[0] = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 1;
  local_14 = 2;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = 2;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_70 = 0;
  local_6c = 0;
  local_8 = 6;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b4,
             param_2);
  FUN_1000aaf0(local_c4,param_1);
  local_14 = 3;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_64;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  FUN_10004100(local_1c);
  local_8._0_1_ = 7;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b690 at 1000b690

undefined2 * __cdecl FUN_1000b690(undefined2 *param_1,int param_2)

{
  undefined *local_c4 [4];
  undefined *local_b4 [2];
  undefined **local_ac [15];
  undefined4 local_70;
  undefined4 local_6c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eefe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10011aa8;
  local_b4[0] = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 1;
  local_14 = 2;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = 2;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_70 = 0;
  local_6c = 0;
  local_8 = 6;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b4,
             param_2);
  FUN_1000aaf0(local_c4,param_1);
  local_14 = 3;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_64;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  FUN_10004100(local_1c);
  local_8._0_1_ = 7;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b7f0 at 1000b7f0

undefined2 * __cdecl FUN_1000b7f0(undefined2 *param_1,float param_2)

{
  undefined *local_c4 [4];
  undefined *local_b4 [2];
  undefined **local_ac [15];
  undefined4 local_70;
  undefined4 local_6c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000eefe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10011aa8;
  local_b4[0] = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 1;
  local_14 = 2;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = 2;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_70 = 0;
  local_6c = 0;
  local_8 = 6;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b4,
             param_2);
  FUN_1000aaf0(local_c4,param_1);
  local_14 = 3;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_64;
  *(undefined ***)((int)local_c4 + *(int *)(local_c4[0] + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  FUN_10004100(local_1c);
  local_8._0_1_ = 7;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b950 at 1000b950

undefined4 FUN_1000b950(undefined4 param_1,int param_2)

{
  LPCOLESTR pOVar1;
  int iVar2;
  uint uStack_38;
  int local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar2 = param_2;
  puStack_c = &LAB_1000ef48;
  local_10 = ExceptionList;
  uStack_38 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  if (param_2 == 0) {
    return 0x80004003;
  }
  local_1c = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  ExceptionList = &local_10;
  pOVar1 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  if (pOVar1 == (LPCOLESTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010c0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10003d40(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar2,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar2 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CConnectionData,void*>::RTTI_Type_Descriptor,
                      &CConnectionData::RTTI_Type_Descriptor,0);
      if ((&PTR_u_CustomerName_10017318)[iVar2 * 5] == (undefined *)0x0) break;
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CConnectionData,void*>::RTTI_Type_Descriptor,
                      &CConnectionData::RTTI_Type_Descriptor,0);
      if ((&DAT_10017320)[iVar2 * 5] == local_18 + 1) {
        (*(code *)(&PTR_FUN_10011df4)[local_18])(local_20,&PTR_u_CustomerName_10017318 + iVar2 * 5);
      }
      iVar2 = iVar2 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_100026a0(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100026a0((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000bac0 at 1000bac0

undefined1 * Catch_1000bac0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000bacd;
}



// Function: FUN_1000baf0 at 1000baf0

undefined2 * __cdecl FUN_1000baf0(undefined2 *param_1,int *param_2)

{
  uint in_stack_ffffffc0;
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ef91;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)(in_stack_ffffffc0 & 0xffff0000);
  FUN_10007a50(&stack0xffffffc0,param_2,0,0xffffffff);
  local_8 = 0;
  FUN_1000b3a0(param_1,pvVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bb80 at 1000bb80

undefined2 * __cdecl FUN_1000bb80(undefined2 *param_1,long *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b530(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bbe0 at 1000bbe0

undefined2 * __cdecl FUN_1000bbe0(undefined2 *param_1,int *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b690(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bc40 at 1000bc40

undefined2 * __cdecl FUN_1000bc40(undefined2 *param_1,float *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000efc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b7f0(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bca0 at 1000bca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000bca0(undefined2 *param_1,undefined4 param_2,type_info *param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  uint local_3c;
  undefined1 *local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000f0c7;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_100183d0 & 1) == 0) {
    DAT_100183d0 = DAT_100183d0 | 1;
    local_8 = 1;
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)
                               &std::
                                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                ::RTTI_Type_Descriptor,(__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 2;
    _DAT_10018324 = 0xf;
    _DAT_10018320 = 0;
    DAT_10018310 = 0;
    FUN_10007960(&DAT_10018310,(int *)local_30,0,0xffffffff);
    _DAT_1001832c = FUN_1000baf0;
    local_8._0_1_ = 5;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_10017dac,
                               (__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 6;
    _DAT_10018344 = 0xf;
    _DAT_10018340 = 0;
    DAT_10018330 = 0;
    FUN_10007960(&DAT_10018330,(int *)local_30,0,0xffffffff);
    _DAT_1001834c = FUN_1000a580;
    local_8._0_1_ = 9;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_10017db8,
                               (__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 10;
    _DAT_10018364 = 0xf;
    _DAT_10018360 = 0;
    DAT_10018350 = 0;
    FUN_10007960(&DAT_10018350,(int *)local_30,0,0xffffffff);
    _DAT_1001836c = FUN_1000bb80;
    local_8._0_1_ = 0xd;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_100173a4,
                               (__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0xe;
    _DAT_10018384 = 0xf;
    _DAT_10018380 = 0;
    DAT_10018370 = 0;
    FUN_10007960(&DAT_10018370,(int *)local_30,0,0xffffffff);
    _DAT_1001838c = FUN_1000bbe0;
    local_8._0_1_ = 0x11;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_10017dc4,
                               (__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0x12;
    _DAT_100183a4 = 0xf;
    _DAT_100183a0 = 0;
    DAT_10018390 = 0;
    FUN_10007960(&DAT_10018390,(int *)local_30,0,0xffffffff);
    _DAT_100183ac = FUN_1000bc40;
    local_8._0_1_ = 0x15;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&ATL::CComVariant::RTTI_Type_Descriptor,
                               (__type_info_node *)&DAT_1001847c);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_10007b50(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0x16;
    _DAT_100183c4 = 0xf;
    _DAT_100183c0 = 0;
    DAT_100183b0 = 0;
    FUN_10007960(&DAT_100183b0,(int *)local_30,0,0xffffffff);
    _DAT_100183cc = FUN_1000a5e0;
    local_8._0_1_ = 0x19;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    local_8._0_1_ = 1;
    _atexit((_func_4879 *)&LAB_1000fb10);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_3c = 0;
  local_38 = &DAT_10018310;
  while( true ) {
    pbVar4 = FUN_10009fa0(local_38,(undefined1 *)local_30);
    local_8 = 0x1a;
    pbVar5 = (byte *)type_info::_name_internal_method(param_3,(__type_info_node *)&DAT_1001847c);
    pbVar9 = pbVar5;
    do {
      bVar1 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 != 0);
    uVar10 = (int)pbVar9 - (int)(pbVar5 + 1);
    uVar7 = *(uint *)(pbVar4 + 0x10);
    uVar6 = uVar10;
    if (uVar7 < uVar10) {
      uVar6 = uVar7;
    }
    if (0xf < *(uint *)(pbVar4 + 0x14)) {
      pbVar4 = *(byte **)pbVar4;
    }
    uVar6 = FUN_10003e90(pbVar4,pbVar5,uVar6);
    bVar11 = uVar6 == 0;
    if (bVar11) {
      if (uVar7 < uVar10) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = (uint)(uVar7 != uVar10);
      }
      bVar11 = uVar7 == 0;
    }
    local_8 = local_8 & 0xffffff00;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    if (bVar11) break;
    local_38 = local_38 + 0x20;
    local_3c = local_3c + 1;
    if (5 < local_3c) {
      *(undefined4 *)(param_1 + 10) = 7;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 0;
      FUN_10007c50(param_1,(int *)L"INVALID_TYPE",0xc);
LAB_1000c128:
      local_8 = 0;
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FUN_1000aa40(&DAT_10018310 + local_3c * 0x20,param_1,param_2);
  goto LAB_1000c128;
}



// Function: FUN_1000c170 at 1000c170

/* WARNING: Removing unreachable block (ram,0x1000c392) */
/* WARNING: Removing unreachable block (ram,0x1000c3ac) */
/* WARNING: Removing unreachable block (ram,0x1000c3a4) */
/* WARNING: Removing unreachable block (ram,0x1000c3b2) */

void __thiscall FUN_1000c170(void *this,undefined2 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *this_00;
  uint uVar4;
  undefined **unaff_ESI;
  int *piVar5;
  ushort *puVar6;
  undefined *local_d8;
  code *pcVar7;
  ushort *in_stack_ffffff3c;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *in_stack_ffffff48;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_88 [72];
  undefined1 *local_40;
  undefined2 *local_3c;
  undefined4 local_38;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000f179;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10011aa0;
  local_14 = uVar1;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_88);
  local_8 = 1;
  puVar6 = (ushort *)0x0;
  local_38 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_d8,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c,false);
  local_8 = 2;
  *(undefined ***)((int)&local_d8 + *(int *)(local_d8 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c);
  uVar4 = 0;
  local_8 = 6;
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CConnectionData,void*>::
                                  RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0,
                          puVar6,uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_10005220((int *)&local_d8,(ushort *)&DAT_10011e58);
      piVar3 = (int *)FUN_10005220(piVar3,puVar6);
      FUN_10005220(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_1000bca0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10004ff0((int *)&local_d8,puVar6);
      local_8 = CONCAT31(local_8._1_3_,6);
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_d8 = (undefined *)*param_2;
      local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
      unaff_ESI = &local_d8;
      local_1c = 7;
      local_20 = 0;
      pcVar7 = endl_exref;
      piVar3 = (int *)FUN_10005220((int *)unaff_ESI,(ushort *)&DAT_10011e50);
      local_d8 = (undefined *)0x1000c30d;
      piVar3 = (int *)FUN_10005220(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_10005220(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000a930(&local_d8,local_3c);
  local_38 = 3;
  local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_88;
  *(undefined ***)((int)&local_d8 + *(int *)(local_d8 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_40 = &stack0xffffff2c;
  local_8._1_3_ = 0;
  local_8._0_1_ = 10;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c,(ushort *)0x0,(ushort *)0x0);
  local_8._0_1_ = 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff2c);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff30);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_88);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c460 at 1000c460

void __thiscall FUN_1000c460(void *this,undefined2 *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  TypeDescriptor *pTVar6;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000f1d1;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pTVar6 = (TypeDescriptor *)0x0;
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)
                     &std::
                      basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                      ::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &std::
              basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::RTTI_Type_Descriptor;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_10017dac);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_10017dac;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_10017db8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_10017db8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_100173a4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_100173a4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1001847c);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_10007b50(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10004170(local_30,&DAT_10011e78,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_10017db8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CConnectionData,void*>::
                                  RTTI_Type_Descriptor,&CConnectionData::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_10007c50(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_1000bca0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c620 at 1000c620

void __thiscall FUN_1000c620(void *this,undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *pvVar4;
  ushort *unaff_ESI;
  undefined4 unaff_EDI;
  ushort *puVar5;
  ushort *puVar6;
  undefined *local_f4;
  undefined **ppuVar7;
  undefined4 in_stack_ffffff14;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_a4 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_5c;
  undefined2 *local_58;
  undefined4 local_54;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_50;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000f291;
  local_10 = ExceptionList;
  local_14 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10011aa0;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_a4);
  local_8 = 1;
  local_54 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_f4,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff10,false);
  local_8 = 2;
  *(undefined ***)((int)&local_f4 + *(int *)(local_f4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_50 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff10;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff10);
  ppuVar7 = std::
            basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            ::vftable;
  local_8 = 6;
  piVar3 = (int *)*param_2;
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_50 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             ((int)piVar3 + 2);
  local_1c = 7;
  local_20 = 0;
  piVar2 = piVar3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10007c50(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_1000c460(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_10005220((int *)&local_f4,(ushort *)&DAT_10011e80);
  piVar3 = (int *)FUN_10004ff0(piVar3,puVar5);
  pvVar4 = (void *)FUN_10005220(piVar3,puVar6);
  piVar3 = FUN_100055a0(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10004ff0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x1000c77b;
  piVar3 = FUN_100055a0(pvVar4,ppuVar7);
  FUN_100055a0(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000a930(&local_f4,local_58);
  local_54 = 3;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  local_50 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_a4;
  *(undefined ***)((int)&local_f4 + *(int *)(local_f4 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_5c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff10;
  local_8._0_1_ = 0xb;
  local_8._1_3_ = 0;
  FUN_10004100(local_5c);
  local_8._0_1_ = 9;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff10);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff14);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_a4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c880 at 1000c880

void FUN_1000c880(undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  int *piVar5;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar6;
  undefined4 *puVar7;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *p_Var8;
  code *pcVar9;
  ushort *in_stack_ffffff1c;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *in_stack_ffffff28;
  undefined1 local_50 [16];
  uint local_40;
  int local_3c;
  int *local_38;
  undefined4 local_34 [7];
  ushort *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000f2eb;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_100182a0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005d50(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    __RTDynamicCast(param_1,0,
                    &IXMLSerializationImpl<struct_CConnectionData,void*>::RTTI_Type_Descriptor,
                    &CConnectionData::RTTI_Type_Descriptor,0);
    piVar5 = (int *)FUN_10005220((int *)&stack0xffffff18,(ushort *)&DAT_10011e58);
    FUN_10005220(piVar5,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var8 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        __RTDynamicCast(param_1,0);
        if ((&PTR_u_CustomerName_10017318)[iVar2 * 5] == (undefined *)0x0) break;
        __RTDynamicCast(param_1,0,
                        &IXMLSerializationImpl<struct_CConnectionData,void*>::RTTI_Type_Descriptor,
                        &CConnectionData::RTTI_Type_Descriptor);
        if ((&DAT_10017320)[iVar2 * 5] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10011e88)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10004ff0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10003bf0(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_10005220((int *)&stack0xffffff18,(ushort *)&DAT_10011e5c);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar6,p_Var8);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    __RTDynamicCast(param_1,0);
    pcVar9 = endl_exref;
    piVar5 = (int *)FUN_10005220((int *)&stack0xffffff18,(ushort *)&DAT_10011e50);
    piVar5 = (int *)FUN_10005220(piVar5,(ushort *)pcVar9);
    pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_10005220(piVar5,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar6,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000a930(&stack0xffffff18,(undefined2 *)local_34);
    local_8._0_1_ = 4;
    if (7 < (uint)puVar7[5]) {
      puVar7 = (undefined4 *)*puVar7;
    }
    if (puVar7 == (undefined4 *)0x0) {
      local_38 = (int *)0x0;
    }
    else {
      local_38 = (int *)Ordinal_2();
      if (local_38 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010c0(0x8007000e);
      }
    }
    piVar5 = local_38;
    local_8._0_1_ = 6;
    FUN_10003bf0(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar5;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005cc0((int *)&stack0xffffff18);
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_9();
    puVar3 = local_14;
  }
  local_14 = puVar3;
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie((uint)local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000cacc at 1000cacc

undefined * Catch_1000cacc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000cad9;
}



// Function: FUN_1000cb10 at 1000cb10

void __cdecl FUN_1000cb10(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_1000cb33 at 1000cb33

void __fastcall FUN_1000cb33(int *param_1)

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



// Function: FUN_1000cb77 at 1000cb77

int __fastcall FUN_1000cb77(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000cb90 at 1000cb90

undefined4 * __fastcall FUN_1000cb90(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1000cb77((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_100151a8;
  param_1[3] = &DAT_100151a8;
  uVar1 = FUN_100013c0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_100182b8 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000cbd1 at 1000cbd1

void __fastcall FUN_1000cbd1(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000cbf0 at 1000cbf0

int __fastcall FUN_1000cbf0(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000cc15 at 1000cc15

void __fastcall FUN_1000cc15(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1000cbd1((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000cc2d at 1000cc2d

undefined4 * __fastcall FUN_1000cc2d(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1000cbf0((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10012020;
  uVar1 = FUN_100013c0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_100182b8 = 1;
  }
  return param_1;
}



// Function: FUN_1000cc6d at 1000cc6d

void FUN_1000cc6d(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000ccc6

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



// Function: __security_check_cookie at 1000cd18

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100182a0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __alloca_probe at 1000cd30

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



// Function: __ArrayUnwind at 1000cd62

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



// Function: `eh_vector_destructor_iterator' at 1000cdc0

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
  FUN_1000ce0b();
  return;
}



// Function: FUN_1000ce0b at 1000ce0b

void FUN_1000ce0b(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 1000ce42

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
  FUN_1000ce8f();
  return;
}



// Function: FUN_1000ce8f at 1000ce8f

void FUN_1000ce8f(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: FUN_1000ceb0 at 1000ceb0

void __cdecl
FUN_1000ceb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_100182a0,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 1000cee0

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



// Function: __alloca_probe_8 at 1000cef6

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



// Function: __onexit at 1000cf0c

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
  
  local_8 = &DAT_10015140;
  uStack_c = 0x1000cf18;
  local_20[0] = DecodePointer(DAT_100187bc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_100187bc);
    local_24 = DecodePointer(DAT_100187b8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_100187bc = EncodePointer(local_20[0]);
    DAT_100187b8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000cfa4();
  }
  return p_Var1;
}



// Function: FUN_1000cfa4 at 1000cfa4

void FUN_1000cfa4(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000cfad

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 1000d01e

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
    if (DAT_10018484 < 1) {
      return 0;
    }
    DAT_10018484 = DAT_10018484 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100187b0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100187ac == 2) {
      param_2 = (int *)DecodePointer(DAT_100187bc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_100187b8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_100187bc);
            piVar8 = (int *)DecodePointer(DAT_100187b8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_100187b8 = (PVOID)encoded_null();
        DAT_100187bc = DAT_100187b8;
      }
      DAT_100187ac = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_100187b0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100187b0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100187ac == 0) {
      DAT_100187ac = 1;
      iVar5 = initterm_e(&DAT_1001136c,&DAT_10011374);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10011298,&DAT_10011368);
      DAT_100187ac = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_100187b0,0);
    }
    if ((DAT_100187b4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100187b4), BVar2 != 0)) {
      (*DAT_100187b4)(param_1,2,param_3);
    }
    DAT_10018484 = DAT_10018484 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000d228

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000d2c8) */
/* WARNING: Removing unreachable block (ram,0x1000d275) */
/* WARNING: Removing unreachable block (ram,0x1000d2f5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_100182b0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10018484 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10002940(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10002940(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000d333();
  return local_20;
}



// Function: FUN_1000d333 at 1000d333

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d333(void)

{
  _DAT_100182b0 = 0xffffffff;
  return;
}



// Function: entry at 1000d33e

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000d361

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
  
  _DAT_100185a0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_100185a4 = &stack0x00000004;
  _DAT_100184e0 = 0x10001;
  _DAT_10018488 = 0xc0000409;
  _DAT_1001848c = 1;
  local_32c = DAT_100182a0;
  local_328 = DAT_100182a4;
  _DAT_10018494 = unaff_retaddr;
  _DAT_1001856c = in_GS;
  _DAT_10018570 = in_FS;
  _DAT_10018574 = in_ES;
  _DAT_10018578 = in_DS;
  _DAT_1001857c = unaff_EDI;
  _DAT_10018580 = unaff_ESI;
  _DAT_10018584 = unaff_EBX;
  _DAT_10018588 = in_EDX;
  _DAT_1001858c = in_ECX;
  _DAT_10018590 = in_EAX;
  _DAT_10018594 = unaff_EBP;
  DAT_10018598 = unaff_retaddr;
  _DAT_1001859c = in_CS;
  _DAT_100185a8 = in_SS;
  DAT_100184d8 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1001203c);
  if (DAT_100184d8 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000d470

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100182a0 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000d4b5

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



// Function: __ValidateImageBase at 1000d540

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



// Function: __FindPESection at 1000d580

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



// Function: __IsNonwritableInCurrentImage at 1000d5d0

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
  
  pcStack_10 = FUN_1000ceb0;
  local_14 = ExceptionList;
  local_c = DAT_100182a0 ^ 0x10015188;
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



// Function: ___security_init_cookie at 1000d6a4

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
  if ((DAT_100182a0 == 0xbb40e64e) || ((DAT_100182a0 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_100182a0 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_100182a0 == 0xbb40e64e) {
      DAT_100182a0 = 0xbb40e64f;
    }
    else if ((DAT_100182a0 & 0xffff0000) == 0) {
      DAT_100182a0 = DAT_100182a0 | (DAT_100182a0 | 0x4711) << 0x10;
    }
    DAT_100182a4 = ~DAT_100182a0;
  }
  else {
    DAT_100182a4 = ~DAT_100182a0;
  }
  return;
}



// Function: Unwind@1000d750 at 1000d750

void Unwind_1000d750(void)

{
  DAT_10018308 = DAT_10018308 & 0xfffffffe;
  return;
}



// Function: Unwind@1000d780 at 1000d780

void Unwind_1000d780(void)

{
  int unaff_EBP;
  
  FUN_10001450(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7b0 at 1000d7b0

void Unwind_1000d7b0(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7e0 at 1000d7e0

void Unwind_1000d7e0(void)

{
  int unaff_EBP;
  
  FUN_10002100(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d810 at 1000d810

void Unwind_1000d810(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000d850 at 1000d850

void Unwind_1000d850(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d880 at 1000d880

void Unwind_1000d880(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1000d8c0 at 1000d8c0

void Unwind_1000d8c0(void)

{
  int unaff_EBP;
  
  FUN_10003f10(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d8f0 at 1000d8f0

void Unwind_1000d8f0(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d8fb at 1000d8fb

void Unwind_1000d8fb(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d920 at 1000d920

void Unwind_1000d920(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000d92b at 1000d92b

void Unwind_1000d92b(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d936 at 1000d936

void Unwind_1000d936(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d960 at 1000d960

void Unwind_1000d960(void)

{
  int unaff_EBP;
  
  FUN_10002150(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d968 at 1000d968

void Unwind_1000d968(void)

{
  int unaff_EBP;
  
  FUN_10002100(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d990 at 1000d990

void Unwind_1000d990(void)

{
  int unaff_EBP;
  
  FUN_100027e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9c0 at 1000d9c0

void Unwind_1000d9c0(void)

{
  int unaff_EBP;
  
  FUN_10002b80((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d9cb at 1000d9cb

void Unwind_1000d9cb(void)

{
  int unaff_EBP;
  
  FUN_100027e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9f0 at 1000d9f0

void Unwind_1000d9f0(void)

{
  int unaff_EBP;
  
  FUN_100018a0(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1000da20 at 1000da20

void Unwind_1000da20(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da2b at 1000da2b

void Unwind_1000da2b(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da36 at 1000da36

void Unwind_1000da36(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da41 at 1000da41

void Unwind_1000da41(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da4c at 1000da4c

void Unwind_1000da4c(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da57 at 1000da57

void Unwind_1000da57(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000da62 at 1000da62

void Unwind_1000da62(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@1000da6d at 1000da6d

void Unwind_1000da6d(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@1000da78 at 1000da78

void Unwind_1000da78(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000da83 at 1000da83

void Unwind_1000da83(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000dac0 at 1000dac0

void Unwind_1000dac0(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000dac8 at 1000dac8

void Unwind_1000dac8(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dad0 at 1000dad0

void Unwind_1000dad0(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dad8 at 1000dad8

void Unwind_1000dad8(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000db00 at 1000db00

void Unwind_1000db00(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000db0b at 1000db0b

void Unwind_1000db0b(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000db16 at 1000db16

void Unwind_1000db16(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000db21 at 1000db21

void Unwind_1000db21(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000db2c at 1000db2c

void Unwind_1000db2c(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000db60 at 1000db60

void Unwind_1000db60(void)

{
  int unaff_EBP;
  
  FUN_10002920((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000db90 at 1000db90

void Unwind_1000db90(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000db9b at 1000db9b

void Unwind_1000db9b(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dba6 at 1000dba6

void Unwind_1000dba6(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dbd0 at 1000dbd0

void Unwind_1000dbd0(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000dbdb at 1000dbdb

void Unwind_1000dbdb(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dbe6 at 1000dbe6

void Unwind_1000dbe6(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dc10 at 1000dc10

void Unwind_1000dc10(void)

{
  FUN_10002070();
  return;
}



// Function: Unwind@1000dc29 at 1000dc29

void Unwind_1000dc29(void)

{
  FUN_10002070();
  return;
}



// Function: Unwind@1000dc60 at 1000dc60

void Unwind_1000dc60(void)

{
  int unaff_EBP;
  
  FUN_100029d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dc68 at 1000dc68

void Unwind_1000dc68(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000dc73 at 1000dc73

void Unwind_1000dc73(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000dc7e at 1000dc7e

void Unwind_1000dc7e(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000dc89 at 1000dc89

void Unwind_1000dc89(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dc94 at 1000dc94

void Unwind_1000dc94(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dcc0 at 1000dcc0

void Unwind_1000dcc0(void)

{
  int unaff_EBP;
  
  FUN_10003c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dcf0 at 1000dcf0

void Unwind_1000dcf0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dcf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd20 at 1000dd20

void Unwind_1000dd20(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dd23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd50 at 1000dd50

void Unwind_1000dd50(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000dd5b at 1000dd5b

void Unwind_1000dd5b(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dd80 at 1000dd80

void Unwind_1000dd80(void)

{
  int unaff_EBP;
  
  FUN_10003f40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ddb0 at 1000ddb0

void Unwind_1000ddb0(void)

{
  int unaff_EBP;
  
  FUN_10003f40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dde0 at 1000dde0

void Unwind_1000dde0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dde3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000de10 at 1000de10

void Unwind_1000de10(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000de18 at 1000de18

void Unwind_1000de18(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000de20 at 1000de20

void Unwind_1000de20(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000de28 at 1000de28

void Unwind_1000de28(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000de30 at 1000de30

void Unwind_1000de30(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000de38 at 1000de38

void Unwind_1000de38(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000de60 at 1000de60

void Unwind_1000de60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000de63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000de90 at 1000de90

void Unwind_1000de90(void)

{
  int unaff_EBP;
  
  FUN_10004550((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000de98 at 1000de98

void Unwind_1000de98(void)

{
  int unaff_EBP;
  
  FUN_10003f40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000dec0 at 1000dec0

void Unwind_1000dec0(void)

{
  int unaff_EBP;
  
  FUN_10004550((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000dec8 at 1000dec8

void Unwind_1000dec8(void)

{
  int unaff_EBP;
  
  FUN_10003f40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000def0 at 1000def0

void Unwind_1000def0(void)

{
  int unaff_EBP;
  
  FUN_10002920((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000df20 at 1000df20

void Unwind_1000df20(void)

{
  int unaff_EBP;
  
  FUN_10004550((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000df28 at 1000df28

void Unwind_1000df28(void)

{
  int unaff_EBP;
  
  FUN_10003f40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000df90 at 1000df90

void Unwind_1000df90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000df96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000df9c at 1000df9c

void Unwind_1000df9c(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000dfa7 at 1000dfa7

void Unwind_1000dfa7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dfaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000dfd0 at 1000dfd0

void Unwind_1000dfd0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dfd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000dfdc at 1000dfdc

void Unwind_1000dfdc(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@1000dfe7 at 1000dfe7

void Unwind_1000dfe7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dfea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e010 at 1000e010

void Unwind_1000e010(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000e026. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@1000e02d at 1000e02d

void Unwind_1000e02d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e033. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1000e039 at 1000e039

void Unwind_1000e039(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e03c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000e042 at 1000e042

void Unwind_1000e042(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000e070 at 1000e070

void Unwind_1000e070(void)

{
  int unaff_EBP;
  
  FUN_10002890((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000e078 at 1000e078

void Unwind_1000e078(void)

{
  int unaff_EBP;
  
  FUN_10002890((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000e0a0 at 1000e0a0

void Unwind_1000e0a0(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000e0d0 at 1000e0d0

void Unwind_1000e0d0(void)

{
  int unaff_EBP;
  
  FUN_100028b0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000e0db at 1000e0db

void Unwind_1000e0db(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1000e0e6 at 1000e0e6

void Unwind_1000e0e6(void)

{
  int unaff_EBP;
  
  FUN_100028b0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000e120 at 1000e120

void Unwind_1000e120(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x2228));
  return;
}



// Function: Unwind@1000e12b at 1000e12b

void Unwind_1000e12b(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@1000e136 at 1000e136

void Unwind_1000e136(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1000e141 at 1000e141

void Unwind_1000e141(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@1000e14c at 1000e14c

void Unwind_1000e14c(void)

{
  int unaff_EBP;
  
  FUN_100021d0((undefined4 *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@1000e180 at 1000e180

void Unwind_1000e180(void)

{
  int unaff_EBP;
  
  FUN_10002920((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1000e18b at 1000e18b

void Unwind_1000e18b(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000e196 at 1000e196

void Unwind_1000e196(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000e1a1 at 1000e1a1

void Unwind_1000e1a1(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000e1ac at 1000e1ac

void Unwind_1000e1ac(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000e1b7 at 1000e1b7

void Unwind_1000e1b7(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000e1c2 at 1000e1c2

void Unwind_1000e1c2(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000e1cd at 1000e1cd

void Unwind_1000e1cd(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000e1d8 at 1000e1d8

void Unwind_1000e1d8(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000e1e3 at 1000e1e3

void Unwind_1000e1e3(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000e1ee at 1000e1ee

void Unwind_1000e1ee(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000e230 at 1000e230

void Unwind_1000e230(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e236. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000e23c at 1000e23c

void Unwind_1000e23c(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000e247 at 1000e247

void Unwind_1000e247(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e24a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e270 at 1000e270

void Unwind_1000e270(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000e278 at 1000e278

void Unwind_1000e278(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000e283 at 1000e283

void Unwind_1000e283(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000e28e at 1000e28e

void Unwind_1000e28e(void)

{
  int unaff_EBP;
  
  FUN_10003870(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e2c0 at 1000e2c0

void Unwind_1000e2c0(void)

{
  int unaff_EBP;
  
  FUN_10003870(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e2c8 at 1000e2c8

void Unwind_1000e2c8(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000e2d3 at 1000e2d3

void Unwind_1000e2d3(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e2de at 1000e2de

void Unwind_1000e2de(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e310 at 1000e310

void Unwind_1000e310(void)

{
  int unaff_EBP;
  
  FUN_10007060(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e340 at 1000e340

void Unwind_1000e340(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000e353. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1000e35a at 1000e35a

void Unwind_1000e35a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000e366 at 1000e366

void Unwind_1000e366(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e369. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e36f at 1000e36f

void Unwind_1000e36f(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000e37a at 1000e37a

void Unwind_1000e37a(void)

{
  int unaff_EBP;
  
  FUN_10007090((int *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1000e385 at 1000e385

void Unwind_1000e385(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e38b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 8) + -0x48));
  return;
}



// Function: Unwind@1000e391 at 1000e391

void Unwind_1000e391(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 8) + -0x48));
  return;
}



// Function: Unwind@1000e39c at 1000e39c

void Unwind_1000e39c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e39f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e3d0 at 1000e3d0

void Unwind_1000e3d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000e3e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -100));
    return;
  }
  return;
}



// Function: Unwind@1000e3ea at 1000e3ea

void Unwind_1000e3ea(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e3f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000e3f6 at 1000e3f6

void Unwind_1000e3f6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e3f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e3ff at 1000e3ff

void Unwind_1000e3ff(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000e40a at 1000e40a

void Unwind_1000e40a(void)

{
  int unaff_EBP;
  
  FUN_10007090((int *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1000e415 at 1000e415

void Unwind_1000e415(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e41b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000e421 at 1000e421

void Unwind_1000e421(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000e42c at 1000e42c

void Unwind_1000e42c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e42f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000e460 at 1000e460

void Unwind_1000e460(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000e490 at 1000e490

void Unwind_1000e490(void)

{
  int unaff_EBP;
  
  FUN_100013f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000e498 at 1000e498

void Unwind_1000e498(void)

{
  int unaff_EBP;
  
  FUN_10001fe0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000e4a3 at 1000e4a3

void Unwind_1000e4a3(void)

{
  int unaff_EBP;
  
  FUN_100028c0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000e4ae at 1000e4ae

void Unwind_1000e4ae(void)

{
  int unaff_EBP;
  
  FUN_100029d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e4b6 at 1000e4b6

void Unwind_1000e4b6(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000e4c1 at 1000e4c1

void Unwind_1000e4c1(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000e4f0 at 1000e4f0

void Unwind_1000e4f0(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e4fb at 1000e4fb

void Unwind_1000e4fb(void)

{
  int unaff_EBP;
  
  FUN_10003f10(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e520 at 1000e520

void Unwind_1000e520(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000e590 at 1000e590

void Unwind_1000e590(void)

{
  int unaff_EBP;
  
  FUN_10008560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e5e0 at 1000e5e0

void Unwind_1000e5e0(void)

{
  int unaff_EBP;
  
  FUN_10003f10(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e5e8 at 1000e5e8

void Unwind_1000e5e8(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e5f3 at 1000e5f3

void Unwind_1000e5f3(void)

{
  int unaff_EBP;
  
  FUN_10008560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e5fb at 1000e5fb

void Unwind_1000e5fb(void)

{
  int unaff_EBP;
  
  FUN_100087d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e620 at 1000e620

void Unwind_1000e620(void)

{
  int unaff_EBP;
  
  FUN_100087d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e628 at 1000e628

void Unwind_1000e628(void)

{
  int unaff_EBP;
  
  FUN_10008560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e670 at 1000e670

void Unwind_1000e670(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6a0 at 1000e6a0

void Unwind_1000e6a0(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6a8 at 1000e6a8

void Unwind_1000e6a8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100026a0((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1000e6c1 at 1000e6c1

void Unwind_1000e6c1(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6c9 at 1000e6c9

void Unwind_1000e6c9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_100026a0((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1000e6e2 at 1000e6e2

void Unwind_1000e6e2(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e6ea at 1000e6ea

void Unwind_1000e6ea(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e710 at 1000e710

void Unwind_1000e710(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1000e71b at 1000e71b

void Unwind_1000e71b(void)

{
  int unaff_EBP;
  
  FUN_100028b0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000e750 at 1000e750

void Unwind_1000e750(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e780 at 1000e780

void Unwind_1000e780(void)

{
  int unaff_EBP;
  
  FUN_100027e0(*(undefined4 **)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1000e78b at 1000e78b

void Unwind_1000e78b(void)

{
  int unaff_EBP;
  
  FUN_10002b80((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000e796 at 1000e796

void Unwind_1000e796(void)

{
  int unaff_EBP;
  
  FUN_10002c00((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000e7a1 at 1000e7a1

void Unwind_1000e7a1(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1000e7ac at 1000e7ac

void Unwind_1000e7ac(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000e7e0 at 1000e7e0

void Unwind_1000e7e0(void)

{
  int unaff_EBP;
  
  FUN_100027e0(*(undefined4 **)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000e7eb at 1000e7eb

void Unwind_1000e7eb(void)

{
  int unaff_EBP;
  
  FUN_10002b80((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000e7f6 at 1000e7f6

void Unwind_1000e7f6(void)

{
  int unaff_EBP;
  
  FUN_10002c00((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000e801 at 1000e801

void Unwind_1000e801(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000e80c at 1000e80c

void Unwind_1000e80c(void)

{
  int unaff_EBP;
  
  FUN_10001fb0((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000e840 at 1000e840

void Unwind_1000e840(void)

{
  int unaff_EBP;
  
  FUN_10003c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e870 at 1000e870

void Unwind_1000e870(void)

{
  int unaff_EBP;
  
  FUN_10003c20(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e878 at 1000e878

void Unwind_1000e878(void)

{
  int unaff_EBP;
  
  FUN_10003ce0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000e8a0 at 1000e8a0

void Unwind_1000e8a0(void)

{
  int unaff_EBP;
  
  FUN_10003ce0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000e8ab at 1000e8ab

void Unwind_1000e8ab(void)

{
  int unaff_EBP;
  
  FUN_10003c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e8d0 at 1000e8d0

void Unwind_1000e8d0(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e900 at 1000e900

void Unwind_1000e900(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10007060(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e960 at 1000e960

void Unwind_1000e960(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000e990 at 1000e990

void Unwind_1000e990(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e9d0 at 1000e9d0

void Unwind_1000e9d0(void)

{
  int unaff_EBP;
  
  FUN_10004220(unaff_EBP + 0xc);
  return;
}



// Function: Unwind@1000e9d8 at 1000e9d8

void Unwind_1000e9d8(void)

{
  int unaff_EBP;
  
  FUN_10004220(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1000e9e0 at 1000e9e0

void Unwind_1000e9e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000ea20 at 1000ea20

void Unwind_1000ea20(void)

{
  int unaff_EBP;
  
  FUN_10004220(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ea28 at 1000ea28

void Unwind_1000ea28(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000ea60 at 1000ea60

void Unwind_1000ea60(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea68 at 1000ea68

void Unwind_1000ea68(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@1000ea81 at 1000ea81

void Unwind_1000ea81(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ea89 at 1000ea89

void Unwind_1000ea89(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eac0 at 1000eac0

void Unwind_1000eac0(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000eac8 at 1000eac8

void Unwind_1000eac8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1000eb10 at 1000eb10

void Unwind_1000eb10(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000eb23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1000eb2a at 1000eb2a

void Unwind_1000eb2a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eb30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000eb36 at 1000eb36

void Unwind_1000eb36(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eb39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000eb3f at 1000eb3f

void Unwind_1000eb3f(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000eb4a at 1000eb4a

void Unwind_1000eb4a(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1000eb55 at 1000eb55

void Unwind_1000eb55(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000eb5d at 1000eb5d

void Unwind_1000eb5d(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000eb65 at 1000eb65

void Unwind_1000eb65(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000eb6d at 1000eb6d

void Unwind_1000eb6d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000eb86 at 1000eb86

void Unwind_1000eb86(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000eb8e at 1000eb8e

void Unwind_1000eb8e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eb94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 0xc) + -0x48));
  return;
}



// Function: Unwind@1000eb9a at 1000eb9a

void Unwind_1000eb9a(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 0xc) + -0x4c));
  return;
}



// Function: Unwind@1000eba5 at 1000eba5

void Unwind_1000eba5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ebd0 at 1000ebd0

void Unwind_1000ebd0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000ebe3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x5c));
    return;
  }
  return;
}



// Function: Unwind@1000ebea at 1000ebea

void Unwind_1000ebea(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ebf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1000ebf6 at 1000ebf6

void Unwind_1000ebf6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ebf9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ebff at 1000ebff

void Unwind_1000ebff(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000ec0a at 1000ec0a

void Unwind_1000ec0a(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000ec15 at 1000ec15

void Unwind_1000ec15(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ec1d at 1000ec1d

void Unwind_1000ec1d(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ec25 at 1000ec25

void Unwind_1000ec25(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000ec2d at 1000ec2d

void Unwind_1000ec2d(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ec35 at 1000ec35

void Unwind_1000ec35(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000ec4e at 1000ec4e

void Unwind_1000ec4e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ec54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 0xc) + -0x48));
  return;
}



// Function: Unwind@1000ec5a at 1000ec5a

void Unwind_1000ec5a(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 0xc) + -0x4c));
  return;
}



// Function: Unwind@1000ec65 at 1000ec65

void Unwind_1000ec65(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ec68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ec90 at 1000ec90

void Unwind_1000ec90(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ec98 at 1000ec98

void Unwind_1000ec98(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000eca0 at 1000eca0

void Unwind_1000eca0(void)

{
  int unaff_EBP;
  
  FUN_10004220(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@1000eca8 at 1000eca8

void Unwind_1000eca8(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000ecb0 at 1000ecb0

void Unwind_1000ecb0(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ecb8 at 1000ecb8

void Unwind_1000ecb8(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ecf0 at 1000ecf0

void Unwind_1000ecf0(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000ecf8 at 1000ecf8

void Unwind_1000ecf8(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000ed00 at 1000ed00

void Unwind_1000ed00(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x48) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x48) = *(uint *)(unaff_EBP + -0x48) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000ed16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x90));
    return;
  }
  return;
}



// Function: Unwind@1000ed1d at 1000ed1d

void Unwind_1000ed1d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ed23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1000ed29 at 1000ed29

void Unwind_1000ed29(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ed2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000ed32 at 1000ed32

void Unwind_1000ed32(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1000ed3d at 1000ed3d

void Unwind_1000ed3d(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@1000ed48 at 1000ed48

void Unwind_1000ed48(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ed50 at 1000ed50

void Unwind_1000ed50(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000ed58 at 1000ed58

void Unwind_1000ed58(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ed60 at 1000ed60

void Unwind_1000ed60(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000ed68 at 1000ed68

void Unwind_1000ed68(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000ed70 at 1000ed70

void Unwind_1000ed70(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000ed78 at 1000ed78

void Unwind_1000ed78(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ed7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x40) + -0x48));
  return;
}



// Function: Unwind@1000ed84 at 1000ed84

void Unwind_1000ed84(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x40) + -0x4c));
  return;
}



// Function: Unwind@1000ed8f at 1000ed8f

void Unwind_1000ed8f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ed92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000ed98 at 1000ed98

void Unwind_1000ed98(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000edd0 at 1000edd0

void Unwind_1000edd0(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000edd8 at 1000edd8

void Unwind_1000edd8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000edeb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -100));
    return;
  }
  return;
}



// Function: Unwind@1000edf2 at 1000edf2

void Unwind_1000edf2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000edf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000edfe at 1000edfe

void Unwind_1000edfe(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ee01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ee07 at 1000ee07

void Unwind_1000ee07(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1000ee12 at 1000ee12

void Unwind_1000ee12(void)

{
  int unaff_EBP;
  
  FUN_10005c00((int *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1000ee1d at 1000ee1d

void Unwind_1000ee1d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x1c));
    return;
  }
  return;
}



// Function: Unwind@1000ee36 at 1000ee36

void Unwind_1000ee36(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ee3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1000ee42 at 1000ee42

void Unwind_1000ee42(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1000ee4d at 1000ee4d

void Unwind_1000ee4d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ee50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ee80 at 1000ee80

void Unwind_1000ee80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000ee93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1000ee9a at 1000ee9a

void Unwind_1000ee9a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000eea6 at 1000eea6

void Unwind_1000eea6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eea9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000eeaf at 1000eeaf

void Unwind_1000eeaf(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1000eeba at 1000eeba

void Unwind_1000eeba(void)

{
  int unaff_EBP;
  
  FUN_10005c00((int *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1000eec5 at 1000eec5

void Unwind_1000eec5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000eede at 1000eede

void Unwind_1000eede(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1000eeea at 1000eeea

void Unwind_1000eeea(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1000eef5 at 1000eef5

void Unwind_1000eef5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000eef8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ef20 at 1000ef20

void Unwind_1000ef20(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ef28 at 1000ef28

void Unwind_1000ef28(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ef30 at 1000ef30

void Unwind_1000ef30(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000ef38 at 1000ef38

void Unwind_1000ef38(void)

{
  int unaff_EBP;
  
  FUN_10003f10((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ef40 at 1000ef40

void Unwind_1000ef40(void)

{
  int unaff_EBP;
  
  FUN_100026a0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ef70 at 1000ef70

void Unwind_1000ef70(void)

{
  int unaff_EBP;
  
  FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ef78 at 1000ef78

void Unwind_1000ef78(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000efb0 at 1000efb0

void Unwind_1000efb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000eff0 at 1000eff0

void Unwind_1000eff0(void)

{
  DAT_100183d0 = DAT_100183d0 & 0xfffffffe;
  return;
}



// Function: Unwind@1000effe at 1000effe

void Unwind_1000effe(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f006 at 1000f006

void Unwind_1000f006(void)

{
  FUN_10007060((undefined4 *)&DAT_10018310);
  return;
}



// Function: Unwind@1000f010 at 1000f010

void Unwind_1000f010(void)

{
  FUN_10007800((undefined4 *)&DAT_10018310);
  return;
}



// Function: Unwind@1000f01a at 1000f01a

void Unwind_1000f01a(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f022 at 1000f022

void Unwind_1000f022(void)

{
  FUN_10007060((undefined4 *)&DAT_10018330);
  return;
}



// Function: Unwind@1000f02c at 1000f02c

void Unwind_1000f02c(void)

{
  FUN_10007800((undefined4 *)&DAT_10018330);
  return;
}



// Function: Unwind@1000f036 at 1000f036

void Unwind_1000f036(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f03e at 1000f03e

void Unwind_1000f03e(void)

{
  FUN_10007060((undefined4 *)&DAT_10018350);
  return;
}



// Function: Unwind@1000f048 at 1000f048

void Unwind_1000f048(void)

{
  FUN_10007800((undefined4 *)&DAT_10018350);
  return;
}



// Function: Unwind@1000f052 at 1000f052

void Unwind_1000f052(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f05a at 1000f05a

void Unwind_1000f05a(void)

{
  FUN_10007060((undefined4 *)&DAT_10018370);
  return;
}



// Function: Unwind@1000f064 at 1000f064

void Unwind_1000f064(void)

{
  FUN_10007800((undefined4 *)&DAT_10018370);
  return;
}



// Function: Unwind@1000f06e at 1000f06e

void Unwind_1000f06e(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f076 at 1000f076

void Unwind_1000f076(void)

{
  FUN_10007060((undefined4 *)&DAT_10018390);
  return;
}



// Function: Unwind@1000f080 at 1000f080

void Unwind_1000f080(void)

{
  FUN_10007800((undefined4 *)&DAT_10018390);
  return;
}



// Function: Unwind@1000f08a at 1000f08a

void Unwind_1000f08a(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f092 at 1000f092

void Unwind_1000f092(void)

{
  FUN_10007060((undefined4 *)&DAT_100183b0);
  return;
}



// Function: Unwind@1000f09c at 1000f09c

void Unwind_1000f09c(void)

{
  FUN_10007800((undefined4 *)&DAT_100183b0);
  return;
}



// Function: Unwind@1000f0a6 at 1000f0a6

void Unwind_1000f0a6(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f0ae at 1000f0ae

void Unwind_1000f0ae(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x40));
    return;
  }
  return;
}



// Function: Unwind@1000f0f0 at 1000f0f0

void Unwind_1000f0f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000f106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x84));
    return;
  }
  return;
}



// Function: Unwind@1000f10d at 1000f10d

void Unwind_1000f10d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f113. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1000f119 at 1000f119

void Unwind_1000f119(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f11c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f122 at 1000f122

void Unwind_1000f122(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1000f12d at 1000f12d

void Unwind_1000f12d(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1000f138 at 1000f138

void Unwind_1000f138(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f140 at 1000f140

void Unwind_1000f140(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@1000f159 at 1000f159

void Unwind_1000f159(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f15f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x30) + -0x48));
  return;
}



// Function: Unwind@1000f165 at 1000f165

void Unwind_1000f165(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x30) + -0x4c));
  return;
}



// Function: Unwind@1000f170 at 1000f170

void Unwind_1000f170(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f173. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000f1b0 at 1000f1b0

void Unwind_1000f1b0(void)

{
  int unaff_EBP;
  
  FUN_10007060((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f1b8 at 1000f1b8

void Unwind_1000f1b8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1000f200 at 1000f200

void Unwind_1000f200(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1000f216. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa0));
    return;
  }
  return;
}



// Function: Unwind@1000f21d at 1000f21d

void Unwind_1000f21d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f223. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@1000f229 at 1000f229

void Unwind_1000f229(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f22c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000f232 at 1000f232

void Unwind_1000f232(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1000f23d at 1000f23d

void Unwind_1000f23d(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@1000f248 at 1000f248

void Unwind_1000f248(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f250 at 1000f250

void Unwind_1000f250(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000f258 at 1000f258

void Unwind_1000f258(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10003bf0(*(undefined4 **)(unaff_EBP + -0x54));
    return;
  }
  return;
}



// Function: Unwind@1000f271 at 1000f271

void Unwind_1000f271(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f277. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x4c) + -0x48));
  return;
}



// Function: Unwind@1000f27d at 1000f27d

void Unwind_1000f27d(void)

{
  int unaff_EBP;
  
  FUN_10004760((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x4c) + -0x4c));
  return;
}



// Function: Unwind@1000f288 at 1000f288

void Unwind_1000f288(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000f28b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1000f2c0 at 1000f2c0

void Unwind_1000f2c0(void)

{
  int unaff_EBP;
  
  FUN_10004220(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1000f2c8 at 1000f2c8

void Unwind_1000f2c8(void)

{
  int unaff_EBP;
  
  FUN_10005cc0((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1000f2d3 at 1000f2d3

void Unwind_1000f2d3(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f2db at 1000f2db

void Unwind_1000f2db(void)

{
  int unaff_EBP;
  
  FUN_10003bf0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f2e3 at 1000f2e3

void Unwind_1000f2e3(void)

{
  int unaff_EBP;
  
  FUN_10001450((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000f320 at 1000f320

void Unwind_1000f320(void)

{
  FUN_10002100(0x100183d4);
  return;
}



// Function: Unwind@1000f32a at 1000f32a

void Unwind_1000f32a(void)

{
  FUN_10002150(0x100183d4);
  return;
}



// Function: Unwind@1000f350 at 1000f350

void Unwind_1000f350(void)

{
  FUN_10002150(0x100183d4);
  return;
}



// Function: Unwind@1000f35a at 1000f35a

void Unwind_1000f35a(void)

{
  FUN_10002100(0x100183d4);
  return;
}



// Function: FUN_1000f380 at 1000f380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000f380(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000f334;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002090(0x100183d4);
  _DAT_100183d4 = ATL::CComModule::vftable;
  _DAT_100182dc = &DAT_100183d4;
  local_8 = 0xffffffff;
  _atexit(FUN_1000fa80);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000fa80 at 1000fa80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fa80(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000f364;
  local_10 = ExceptionList;
  uVar1 = DAT_100182a0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_100183d4 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_100183d8 != 0) {
    if (DAT_100183e0 != 0) {
      FUN_10001f00(0x100183d8);
      DAT_100183e0 = 0;
    }
    if (DAT_100183fc != (int *)0x0) {
      (**(code **)(*DAT_100183fc + 8))(DAT_100183fc,uVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_100183e4);
    DAT_100183d8 = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000fb30 at 1000fb30

void FUN_1000fb30(void)

{
  Ordinal_6(DAT_10018404);
  return;
}



// Function: FUN_1000fb40 at 1000fb40

void FUN_1000fb40(void)

{
  Ordinal_6(DAT_10018408);
  return;
}



// Function: FUN_1000fb50 at 1000fb50

void FUN_1000fb50(void)

{
  Ordinal_6(DAT_1001840c);
  return;
}



// Function: FUN_1000fb60 at 1000fb60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fb60(void)

{
  if (7 < DAT_10017e04) {
    operator_delete(DAT_10017df0);
  }
  DAT_10017e04 = 7;
  _DAT_10017e00 = 0;
  DAT_10017df0 = (void *)((uint)DAT_10017df0 & 0xffff0000);
  return;
}



// Function: FUN_1000fba0 at 1000fba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fba0(void)

{
  if (7 < DAT_10017e20) {
    operator_delete(DAT_10017e0c);
  }
  DAT_10017e20 = 7;
  _DAT_10017e1c = 0;
  DAT_10017e0c = (void *)((uint)DAT_10017e0c & 0xffff0000);
  return;
}



// Function: FUN_1000fbe0 at 1000fbe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fbe0(void)

{
  if (7 < DAT_10017e3c) {
    operator_delete(DAT_10017e28);
  }
  DAT_10017e3c = 7;
  _DAT_10017e38 = 0;
  DAT_10017e28 = (void *)((uint)DAT_10017e28 & 0xffff0000);
  return;
}



// Function: FUN_1000fc20 at 1000fc20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fc20(void)

{
  if (7 < DAT_10017e58) {
    operator_delete(DAT_10017e44);
  }
  DAT_10017e58 = 7;
  _DAT_10017e54 = 0;
  DAT_10017e44 = (void *)((uint)DAT_10017e44 & 0xffff0000);
  return;
}



// Function: FUN_1000fc60 at 1000fc60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fc60(void)

{
  if (7 < DAT_10017e74) {
    operator_delete(DAT_10017e60);
  }
  DAT_10017e74 = 7;
  _DAT_10017e70 = 0;
  DAT_10017e60 = (void *)((uint)DAT_10017e60 & 0xffff0000);
  return;
}



// Function: FUN_1000fca0 at 1000fca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fca0(void)

{
  if (7 < DAT_10017e90) {
    operator_delete(DAT_10017e7c);
  }
  DAT_10017e90 = 7;
  _DAT_10017e8c = 0;
  DAT_10017e7c = (void *)((uint)DAT_10017e7c & 0xffff0000);
  return;
}



// Function: FUN_1000fce0 at 1000fce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fce0(void)

{
  if (7 < DAT_10017eac) {
    operator_delete(DAT_10017e98);
  }
  DAT_10017eac = 7;
  _DAT_10017ea8 = 0;
  DAT_10017e98 = (void *)((uint)DAT_10017e98 & 0xffff0000);
  return;
}



// Function: FUN_1000fd20 at 1000fd20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fd20(void)

{
  if (7 < DAT_10017ec8) {
    operator_delete(DAT_10017eb4);
  }
  DAT_10017ec8 = 7;
  _DAT_10017ec4 = 0;
  DAT_10017eb4 = (void *)((uint)DAT_10017eb4 & 0xffff0000);
  return;
}



// Function: FUN_1000fd60 at 1000fd60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fd60(void)

{
  if (7 < DAT_10017ee4) {
    operator_delete(DAT_10017ed0);
  }
  DAT_10017ee4 = 7;
  _DAT_10017ee0 = 0;
  DAT_10017ed0 = (void *)((uint)DAT_10017ed0 & 0xffff0000);
  return;
}



// Function: FUN_1000fda0 at 1000fda0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fda0(void)

{
  if (7 < DAT_10017f00) {
    operator_delete(DAT_10017eec);
  }
  DAT_10017f00 = 7;
  _DAT_10017efc = 0;
  DAT_10017eec = (void *)((uint)DAT_10017eec & 0xffff0000);
  return;
}



// Function: FUN_1000fde0 at 1000fde0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fde0(void)

{
  if (7 < DAT_10017f1c) {
    operator_delete(DAT_10017f08);
  }
  DAT_10017f1c = 7;
  _DAT_10017f18 = 0;
  DAT_10017f08 = (void *)((uint)DAT_10017f08 & 0xffff0000);
  return;
}



// Function: FUN_1000fe20 at 1000fe20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fe20(void)

{
  if (7 < DAT_10017f38) {
    operator_delete(DAT_10017f24);
  }
  DAT_10017f38 = 7;
  _DAT_10017f34 = 0;
  DAT_10017f24 = (void *)((uint)DAT_10017f24 & 0xffff0000);
  return;
}



// Function: FUN_1000fe60 at 1000fe60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fe60(void)

{
  if (7 < DAT_10017f54) {
    operator_delete(DAT_10017f40);
  }
  DAT_10017f54 = 7;
  _DAT_10017f50 = 0;
  DAT_10017f40 = (void *)((uint)DAT_10017f40 & 0xffff0000);
  return;
}



// Function: FUN_1000fea0 at 1000fea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fea0(void)

{
  if (7 < DAT_10017f70) {
    operator_delete(DAT_10017f5c);
  }
  DAT_10017f70 = 7;
  _DAT_10017f6c = 0;
  DAT_10017f5c = (void *)((uint)DAT_10017f5c & 0xffff0000);
  return;
}



// Function: FUN_1000fee0 at 1000fee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fee0(void)

{
  if (7 < DAT_10017f8c) {
    operator_delete(DAT_10017f78);
  }
  DAT_10017f8c = 7;
  _DAT_10017f88 = 0;
  DAT_10017f78 = (void *)((uint)DAT_10017f78 & 0xffff0000);
  return;
}



// Function: FUN_1000ff20 at 1000ff20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ff20(void)

{
  if (7 < DAT_10017fa8) {
    operator_delete(DAT_10017f94);
  }
  DAT_10017fa8 = 7;
  _DAT_10017fa4 = 0;
  DAT_10017f94 = (void *)((uint)DAT_10017f94 & 0xffff0000);
  return;
}



// Function: FUN_1000ff60 at 1000ff60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ff60(void)

{
  if (7 < DAT_10017fc4) {
    operator_delete(DAT_10017fb0);
  }
  DAT_10017fc4 = 7;
  _DAT_10017fc0 = 0;
  DAT_10017fb0 = (void *)((uint)DAT_10017fb0 & 0xffff0000);
  return;
}



// Function: FUN_1000ffa0 at 1000ffa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ffa0(void)

{
  if (7 < DAT_10017fe0) {
    operator_delete(DAT_10017fcc);
  }
  DAT_10017fe0 = 7;
  _DAT_10017fdc = 0;
  DAT_10017fcc = (void *)((uint)DAT_10017fcc & 0xffff0000);
  return;
}



// Function: FUN_1000ffe0 at 1000ffe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ffe0(void)

{
  if (7 < DAT_10017ffc) {
    operator_delete(DAT_10017fe8);
  }
  DAT_10017ffc = 7;
  _DAT_10017ff8 = 0;
  DAT_10017fe8 = (void *)((uint)DAT_10017fe8 & 0xffff0000);
  return;
}



// Function: FUN_10010020 at 10010020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010020(void)

{
  if (7 < DAT_10018018) {
    operator_delete(DAT_10018004);
  }
  DAT_10018018 = 7;
  _DAT_10018014 = 0;
  DAT_10018004 = (void *)((uint)DAT_10018004 & 0xffff0000);
  return;
}



// Function: FUN_10010060 at 10010060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010060(void)

{
  if (7 < DAT_10018034) {
    operator_delete(DAT_10018020);
  }
  DAT_10018034 = 7;
  _DAT_10018030 = 0;
  DAT_10018020 = (void *)((uint)DAT_10018020 & 0xffff0000);
  return;
}



// Function: FUN_100100a0 at 100100a0

void FUN_100100a0(void)

{
  Ordinal_6(DAT_10018410);
  return;
}



// Function: FUN_100100b0 at 100100b0

void FUN_100100b0(void)

{
  Ordinal_6(DAT_10018414);
  return;
}



// Function: FUN_100100c0 at 100100c0

void FUN_100100c0(void)

{
  Ordinal_6(DAT_10018418);
  return;
}



// Function: FUN_100100d0 at 100100d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100100d0(void)

{
  if (7 < DAT_10018050) {
    operator_delete(DAT_1001803c);
  }
  DAT_10018050 = 7;
  _DAT_1001804c = 0;
  DAT_1001803c = (void *)((uint)DAT_1001803c & 0xffff0000);
  return;
}



// Function: FUN_10010110 at 10010110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010110(void)

{
  if (7 < DAT_1001806c) {
    operator_delete(DAT_10018058);
  }
  DAT_1001806c = 7;
  _DAT_10018068 = 0;
  DAT_10018058 = (void *)((uint)DAT_10018058 & 0xffff0000);
  return;
}



// Function: FUN_10010150 at 10010150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010150(void)

{
  if (7 < DAT_10018088) {
    operator_delete(DAT_10018074);
  }
  DAT_10018088 = 7;
  _DAT_10018084 = 0;
  DAT_10018074 = (void *)((uint)DAT_10018074 & 0xffff0000);
  return;
}



// Function: FUN_10010190 at 10010190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010190(void)

{
  if (7 < DAT_100180a4) {
    operator_delete(DAT_10018090);
  }
  DAT_100180a4 = 7;
  _DAT_100180a0 = 0;
  DAT_10018090 = (void *)((uint)DAT_10018090 & 0xffff0000);
  return;
}



// Function: FUN_100101d0 at 100101d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100101d0(void)

{
  if (7 < DAT_100180c0) {
    operator_delete(DAT_100180ac);
  }
  DAT_100180c0 = 7;
  _DAT_100180bc = 0;
  DAT_100180ac = (void *)((uint)DAT_100180ac & 0xffff0000);
  return;
}



// Function: FUN_10010210 at 10010210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010210(void)

{
  if (7 < DAT_100180dc) {
    operator_delete(DAT_100180c8);
  }
  DAT_100180dc = 7;
  _DAT_100180d8 = 0;
  DAT_100180c8 = (void *)((uint)DAT_100180c8 & 0xffff0000);
  return;
}



// Function: FUN_10010250 at 10010250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010250(void)

{
  if (7 < DAT_100180f8) {
    operator_delete(DAT_100180e4);
  }
  DAT_100180f8 = 7;
  _DAT_100180f4 = 0;
  DAT_100180e4 = (void *)((uint)DAT_100180e4 & 0xffff0000);
  return;
}



// Function: FUN_10010290 at 10010290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010290(void)

{
  if (7 < DAT_10018114) {
    operator_delete(DAT_10018100);
  }
  DAT_10018114 = 7;
  _DAT_10018110 = 0;
  DAT_10018100 = (void *)((uint)DAT_10018100 & 0xffff0000);
  return;
}



// Function: FUN_100102d0 at 100102d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100102d0(void)

{
  if (7 < DAT_10018130) {
    operator_delete(DAT_1001811c);
  }
  DAT_10018130 = 7;
  _DAT_1001812c = 0;
  DAT_1001811c = (void *)((uint)DAT_1001811c & 0xffff0000);
  return;
}



// Function: FUN_10010310 at 10010310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010310(void)

{
  if (7 < DAT_1001814c) {
    operator_delete(DAT_10018138);
  }
  DAT_1001814c = 7;
  _DAT_10018148 = 0;
  DAT_10018138 = (void *)((uint)DAT_10018138 & 0xffff0000);
  return;
}



// Function: FUN_10010350 at 10010350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010350(void)

{
  if (7 < DAT_10018168) {
    operator_delete(DAT_10018154);
  }
  DAT_10018168 = 7;
  _DAT_10018164 = 0;
  DAT_10018154 = (void *)((uint)DAT_10018154 & 0xffff0000);
  return;
}



// Function: FUN_10010390 at 10010390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010390(void)

{
  if (7 < DAT_10018184) {
    operator_delete(DAT_10018170);
  }
  DAT_10018184 = 7;
  _DAT_10018180 = 0;
  DAT_10018170 = (void *)((uint)DAT_10018170 & 0xffff0000);
  return;
}



// Function: FUN_100103d0 at 100103d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100103d0(void)

{
  if (7 < DAT_100181a0) {
    operator_delete(DAT_1001818c);
  }
  DAT_100181a0 = 7;
  _DAT_1001819c = 0;
  DAT_1001818c = (void *)((uint)DAT_1001818c & 0xffff0000);
  return;
}



// Function: FUN_10010410 at 10010410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010410(void)

{
  if (7 < DAT_100181bc) {
    operator_delete(DAT_100181a8);
  }
  DAT_100181bc = 7;
  _DAT_100181b8 = 0;
  DAT_100181a8 = (void *)((uint)DAT_100181a8 & 0xffff0000);
  return;
}



// Function: FUN_10010450 at 10010450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010450(void)

{
  if (7 < DAT_100181d8) {
    operator_delete(DAT_100181c4);
  }
  DAT_100181d8 = 7;
  _DAT_100181d4 = 0;
  DAT_100181c4 = (void *)((uint)DAT_100181c4 & 0xffff0000);
  return;
}



// Function: FUN_10010490 at 10010490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010490(void)

{
  if (7 < DAT_100181f4) {
    operator_delete(DAT_100181e0);
  }
  DAT_100181f4 = 7;
  _DAT_100181f0 = 0;
  DAT_100181e0 = (void *)((uint)DAT_100181e0 & 0xffff0000);
  return;
}



// Function: FUN_100104d0 at 100104d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100104d0(void)

{
  if (7 < DAT_10018210) {
    operator_delete(DAT_100181fc);
  }
  DAT_10018210 = 7;
  _DAT_1001820c = 0;
  DAT_100181fc = (void *)((uint)DAT_100181fc & 0xffff0000);
  return;
}



// Function: FUN_10010510 at 10010510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010510(void)

{
  if (7 < DAT_1001822c) {
    operator_delete(DAT_10018218);
  }
  DAT_1001822c = 7;
  _DAT_10018228 = 0;
  DAT_10018218 = (void *)((uint)DAT_10018218 & 0xffff0000);
  return;
}



// Function: FUN_10010550 at 10010550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010550(void)

{
  if (7 < DAT_10018248) {
    operator_delete(DAT_10018234);
  }
  DAT_10018248 = 7;
  _DAT_10018244 = 0;
  DAT_10018234 = (void *)((uint)DAT_10018234 & 0xffff0000);
  return;
}



// Function: FUN_10010590 at 10010590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010590(void)

{
  if (7 < DAT_10018264) {
    operator_delete(DAT_10018250);
  }
  DAT_10018264 = 7;
  _DAT_10018260 = 0;
  DAT_10018250 = (void *)((uint)DAT_10018250 & 0xffff0000);
  return;
}



// Function: FUN_100105d0 at 100105d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100105d0(void)

{
  if (7 < DAT_10018280) {
    operator_delete(DAT_1001826c);
  }
  DAT_10018280 = 7;
  _DAT_1001827c = 0;
  DAT_1001826c = (void *)((uint)DAT_1001826c & 0xffff0000);
  return;
}



// Function: FUN_10010605 at 10010605

void FUN_10010605(void)

{
  FUN_1000cb33((int *)&DAT_1001841c);
  return;
}



// Function: FUN_1001060f at 1001060f

void FUN_1001060f(void)

{
  FUN_1000cc15(0x10018444);
  return;
}



