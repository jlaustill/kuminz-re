/*
 * Decompiled from: AuditDataOM.dll
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

bool __cdecl FUN_10001070(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100010a0 at 100010a0

void FUN_100010a0(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10026b40);
}



// Function: FUN_100010c0 at 100010c0

void __cdecl FUN_100010c0(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070057);
  }
}



// Function: FUN_10001180 at 10001180

void __cdecl FUN_10001180(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070057);
  }
}



// Function: FUN_10001230 at 10001230

void __cdecl FUN_10001230(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070057);
  }
}



// Function: FUN_100012f0 at 100012f0

void __cdecl FUN_100012f0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070057);
  }
}



// Function: FUN_100013a0 at 100013a0

uint __fastcall FUN_100013a0(LPCRITICAL_SECTION param_1)

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



// Function: FUN_100013d0 at 100013d0

void __fastcall FUN_100013d0(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10001400 at 10001400

DWORD FUN_10001400(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001420 at 10001420

uint __cdecl FUN_10001420(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10001440 at 10001440

void __fastcall FUN_10001440(undefined4 *param_1)

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
  if (DAT_1002fdf4 == '\0') {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_1002fdf0 = GetProcAddress(hModule,"RegDeleteKeyExW");
    }
    DAT_1002fdf4 = '\x01';
  }
  if (DAT_1002fdf0 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
    (*DAT_1002fdf0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
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
      FUN_100010c0((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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
  
  puStack_c = &LAB_1001bb6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_1002fe18 & 1) == 0) {
    DAT_1002fe18 = DAT_1002fe18 | 1;
    DAT_1002fdfc = 8;
    DAT_1002fdf8 = &DAT_100214d4;
    DAT_1002fe00 = &DAT_100214d0;
    _DAT_1002fe04 = 0x4008;
    _DAT_1002fe08 = &DAT_100214cc;
    _DAT_1002fe0c = 0x13;
    _DAT_1002fe10 = &DAT_100214c8;
    _DAT_1002fe14 = 0x11;
  }
  local_8 = 0xffffffff;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_1002fdf8)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_1002fdfc)[uVar2 * 4];
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
  
  ppuVar2 = &PTR_u_AppID_100215e8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10021618);
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
  
  local_8 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    DAT_1002fddc = *param_3;
    DAT_1002fde0 = param_3[1];
    DAT_1002fde4 = param_3[2];
    DAT_1002fde8 = param_3[3];
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
  piVar2 = DAT_1002ff88;
  if (DAT_1002ff88 < DAT_1002ff8c) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_1002ff8c);
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
  
  puStack_c = &LAB_1001bb98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_1002fdb0 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001fb0 at 10001fb0

void __cdecl FUN_10001fb0(LPVOID *param_1,IID *param_2)

{
  if (*param_1 == (LPVOID)0x0) {
    CoCreateInstance(param_2,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021618,param_1);
  }
  return;
}



// Function: FUN_10001fe0 at 10001fe0

void __cdecl FUN_10001fe0(LPVOID *param_1,IID *param_2)

{
  if (*param_1 == (LPVOID)0x0) {
    CoCreateInstance(param_2,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021628,param_1);
  }
  return;
}



// Function: FUN_10002010 at 10002010

void __cdecl FUN_10002010(LPVOID *param_1,IID *param_2)

{
  if (*param_1 == (LPVOID)0x0) {
    CoCreateInstance(param_2,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021650,param_1);
  }
  return;
}



// Function: FUN_10002040 at 10002040

void __fastcall FUN_10002040(int *param_1)

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



// Function: FUN_10002070 at 10002070

void __fastcall FUN_10002070(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bbc8;
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



// Function: FUN_100020c0 at 100020c0

void __fastcall FUN_100020c0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_100020d0 at 100020d0

void __thiscall FUN_100020d0(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_10002100 at 10002100

void FUN_10002100(void)

{
  return;
}



// Function: FUN_10002110 at 10002110

void __fastcall FUN_10002110(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bbf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1002fdb0 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: DllCanUnloadNow at 10002160

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2160  1  DllCanUnloadNow */
  return (uint)(DAT_1002ff40 != 0);
}



// Function: FUN_10002170 at 10002170

int __fastcall FUN_10002170(int param_1)

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
  DAT_1002fdd8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_1002fdc8 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_100021e0 at 100021e0

void __fastcall FUN_100021e0(int param_1)

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



// Function: FUN_10002230 at 10002230

void __fastcall FUN_10002230(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc28;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_100022b0 at 100022b0

void __fastcall FUN_100022b0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_100022d0 at 100022d0

void __thiscall FUN_100022d0(void *this,LPCWSTR param_1)

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
  
  puStack_c = &LAB_1001bc5b;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
      iVar1 = FUN_100022d0(&local_220,local_214);
      if (iVar1 != 0) goto LAB_1000233f;
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
LAB_1000233f:
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



// Function: FUN_10002460 at 10002460

undefined4 __fastcall FUN_10002460(int *param_1)

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



// Function: FUN_100024f0 at 100024f0

void __thiscall FUN_100024f0(void *this,LPCWSTR param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc98;
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



// Function: FUN_10002570 at 10002570

void FUN_10002570(int param_1)

{
  FUN_10002460((int *)(param_1 + 4));
  return;
}



// Function: FUN_10002590 at 10002590

DWORD __fastcall FUN_10002590(int param_1)

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



// Function: FUN_100025d0 at 100025d0

void FUN_100025d0(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  puStack_c = &LAB_1001bccb;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000279d;
  *param_3 = 0;
  *param_4 = 0;
  local_240 = 0;
  local_8 = 0;
  DVar3 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar3 == 0) {
    FUN_10001400();
  }
  else {
    if (DVar3 == 0x104) {
      local_8 = 0xffffffff;
      FUN_10002040(&local_240);
      goto LAB_1000279d;
    }
    pwVar4 = (wchar_t *)FUN_10001df0();
    if (param_2 != (LPCWSTR)0x0) {
      uVar5 = lstrlenW(param_2);
      uVar1 = uVar5 + DVar3;
      if (((DVar3 <= uVar1) && (uVar5 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_10001180(local_23c + DVar3,0x10e - DVar3,param_2);
        goto LAB_100026e0;
      }
LAB_1000277f:
      local_8 = 0xffffffff;
      FUN_10002040(&local_240);
      goto LAB_1000279d;
    }
LAB_100026e0:
    iVar6 = Ordinal_161(local_23c,param_4,uVar2);
    if (iVar6 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar6 = (int)pwVar4 - (int)local_23c >> 1;
      if (0x104 < iVar6 + 5U) goto LAB_1000277f;
      FUN_10001180(pwVar4,0x10e - iVar6,local_20);
      iVar6 = Ordinal_161(local_23c,param_4);
      if (iVar6 < 0) goto LAB_1000264f;
    }
    uVar7 = Ordinal_2(local_23c);
    *param_3 = uVar7;
  }
LAB_1000264f:
  local_8 = 0xffffffff;
  FUN_10002040(&local_240);
LAB_1000279d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100027c0 at 100027c0

void __fastcall FUN_100027c0(int param_1)

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
  piVar5 = DAT_1002ff88;
  if (DAT_1002ff88 < DAT_1002ff8c) {
    do {
      if (*piVar5 != 0) {
        (**(code **)(*piVar5 + 0x20))(0);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < DAT_1002ff8c);
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



// Function: FUN_100028b0 at 100028b0

DWORD __fastcall FUN_100028b0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x30),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  *(undefined1 *)(param_1 + 0x48) = 1;
  if ((int)DVar2 < 0) {
    return DVar2;
  }
  return 0;
}



// Function: FUN_100028f0 at 100028f0

wchar_t * __fastcall FUN_100028f0(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditModules::RTTI_Type_Descriptor,0);
  return L"AuditModules";
}



// Function: FUN_10002910 at 10002910

void __thiscall FUN_10002910(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_100218e0,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002960 at 10002960

void __fastcall FUN_10002960(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_100029b0 at 100029b0

void __fastcall FUN_100029b0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd09;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a00 at 10002a00

exception * __thiscall FUN_10002a00(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd39;
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



// Function: FUN_10002a60 at 10002a60

uint __cdecl FUN_10002a60(byte *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  
  if (3 < param_3) {
    do {
      if (*(int *)param_1 != *(int *)param_2) goto LAB_10002a8b;
      param_3 = param_3 - 4;
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_10002a8b:
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



// Function: FUN_10002ae0 at 10002ae0

undefined4 FUN_10002ae0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10002b00 at 10002b00

void __fastcall FUN_10002b00(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar1;
  
  pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
                    /* WARNING: Could not recover jumptable at 0x10002b2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pbVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10002b40 at 10002b40

void * __cdecl FUN_10002b40(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd99;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026d00);
}



// Function: FUN_10002bd0 at 10002bd0

exception * __thiscall FUN_10002bd0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10002c30 at 10002c30

uint __thiscall FUN_10002c30(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_10002c98:
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
      goto LAB_10002c98;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10002cc0 at 10002cc0

void __fastcall
FUN_10002cc0(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

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



// Function: FUN_10002d30 at 10002d30

void __fastcall FUN_10002d30(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10002d40 at 10002d40

wchar_t * __fastcall FUN_10002d40(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditRecords::RTTI_Type_Descriptor,0);
  return L"AuditRecords";
}



// Function: FUN_10002d60 at 10002d60

wchar_t * __fastcall FUN_10002d60(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditAdjustments::RTTI_Type_Descriptor,0);
  return L"AuditAdjustments";
}



// Function: FUN_10002d80 at 10002d80

uint __thiscall FUN_10002d80(void *this,byte *param_1,uint param_2,uint param_3)

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
        uVar3 = FUN_10002a60(pbVar1,param_1,param_3);
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



// Function: FUN_10002e30 at 10002e30

undefined4 __thiscall FUN_10002e30(void *this,int *param_1)

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
  puStack_c = &LAB_1001bd73;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
      local_20 = (uint *)FUN_1001b07c(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_10002960,FUN_10001f60);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_10002f11();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_10002f11();
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



// Function: Catch@10002f01 at 10002f01

undefined * Catch_10002f01(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002f0e;
}



// Function: FUN_10002f11 at 10002f11

undefined4 FUN_10002f11(void)

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



// Function: FUN_10003020 at 10003020

void FUN_10003020(int param_1)

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



// Function: FUN_10003080 at 10003080

void * __cdecl FUN_10003080(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd99;
  local_10 = ExceptionList;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < (char *)0xccccccd) &&
     (pvVar1 = operator_new((int)param_1 * 0x14), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026d00);
}



// Function: FUN_10003110 at 10003110

void __fastcall FUN_10003110(undefined4 *param_1)

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



// Function: FUN_10003150 at 10003150

undefined4 __thiscall FUN_10003150(void *this,undefined4 *param_1)

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



// Function: FUN_100031c0 at 100031c0

void __fastcall FUN_100031c0(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100031e0 at 100031e0

void __fastcall FUN_100031e0(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100020c0(param_1);
    return;
  }
  return;
}



// Function: FUN_100031f0 at 100031f0

void __fastcall FUN_100031f0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bdd3;
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



// Function: FUN_10003250 at 10003250

int * __thiscall FUN_10003250(void *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bdf8;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10003320 at 10003320

void __fastcall FUN_10003320(int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be28;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_100033b0 at 100033b0

void * FUN_100033b0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)0x0;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026d00);
  }
  ExceptionList = local_10;
  return pvVar1;
}



// Function: FUN_10003440 at 10003440

void __fastcall FUN_10003440(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10003460 at 10003460

bool __thiscall FUN_10003460(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be80;
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
    (**(code **)**this)(*this,&DAT_100219f8,&local_18,DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&DAT_100219f8,&local_14);
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



// Function: FUN_10003550 at 10003550

void __fastcall
FUN_10003550(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bea9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_10002cc0(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100035b0 at 100035b0

ushort __fastcall
FUN_100035b0(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

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



// Function: FUN_10003660 at 10003660

void __thiscall
FUN_10003660(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

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
      if (param_2 == 0 && param_3 == 0) goto LAB_1000379d;
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
          goto LAB_1000379d;
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
LAB_100036f9:
        param_3 = *(uint *)(_BADOFF_exref + 4);
        param_2 = *(uint *)_BADOFF_exref;
      }
    }
    else if (param_4 != 0) goto LAB_100036f9;
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
        goto LAB_1000379d;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_1000379d:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_100038a0 at 100038a0

ushort __thiscall FUN_100038a0(void *this,ushort param_1)

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
      puVar1 = (ushort *)FUN_10002b40(pcVar5);
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



// Function: FUN_10003ac0 at 10003ac0

ushort __thiscall FUN_10003ac0(void *this,ushort param_1)

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



// Function: FUN_10003b50 at 10003b50

void __thiscall FUN_10003b50(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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
          goto LAB_10003c49;
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
        goto LAB_10003c49;
      }
    }
    uVar7 = *(uint *)_BADOFF_exref;
    uVar6 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_10003c49:
  *param_1 = uVar7;
  param_1[1] = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10003ce0 at 10003ce0

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10003ce0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bea9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_10002cc0((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
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



// Function: FUN_10003d50 at 10003d50

void __thiscall FUN_10003d50(void *this,void *param_1,char *param_2,undefined4 param_3)

{
  ushort *_Dst;
  ushort *puVar1;
  ushort *puVar2;
  
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = param_3;
  if ((param_2 != (char *)0x0) && (((byte)param_3 & 6) != 6)) {
    _Dst = (ushort *)FUN_10002b40(param_2);
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



// Function: FUN_10003de0 at 10003de0

/* WARNING: Removing unreachable block (ram,0x10003e2c) */

void FUN_10003de0(int *param_1,ushort *param_2)

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
  puStack_c = &LAB_1001bee0;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  uVar9 = (undefined2)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  uVar10 = (undefined2)((DAT_1002fdb0 ^ (uint)&stack0xfffffffc) >> 0x10);
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
  FUN_10003250(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_10003f99();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) == 0x40) {
LAB_10003ed8:
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
      goto LAB_10003f0c;
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
    if (local_18 == 0) goto LAB_10003ed8;
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
LAB_10003f0c:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_10003f99();
  return;
}



// Function: Catch@10003f75 at 10003f75

undefined * Catch_10003f75(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10003f96;
}



// Function: FUN_10003f99 at 10003f99

void FUN_10003f99(void)

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



// Function: FUN_10004010 at 10004010

undefined4 FUN_10004010(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001e80(&DAT_1002ff38,(int *)&PTR_DAT_1002d000,param_1,(undefined4 *)&DAT_100214d8);
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    FUN_100027c0(0x1002ff38);
  }
  return 1;
}



// Function: FUN_10004060 at 10004060

void __fastcall FUN_10004060(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10004070 at 10004070

void __fastcall FUN_10004070(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10004080 at 10004080

HRESULT __thiscall FUN_10004080(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_100232cc,(LPUNKNOWN)0x0,1,(IID *)&DAT_10021a7c,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_100040e0 at 100040e0

undefined4 FUN_100040e0(void)

{
  return 0x80004005;
}



// Function: FUN_100040f0 at 100040f0

void FUN_100040f0(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10021a8c);
  return;
}



// Function: FUN_10004110 at 10004110

undefined4 * __thiscall FUN_10004110(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf10;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_100041b0 at 100041b0

void __fastcall FUN_100041b0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10002460(param_1);
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



// Function: FUN_10004230 at 10004230

void __fastcall FUN_10004230(undefined4 *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf73;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  piVar1 = param_1 + 1;
  FUN_10002460(piVar1);
  local_8 = 1;
  FUN_10002460(piVar1);
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



// Function: FUN_100042d0 at 100042d0

undefined4 FUN_100042d0(void)

{
  return 0x80004001;
}



// Function: FUN_100042e0 at 100042e0

undefined4 FUN_100042e0(void)

{
  return 1;
}



// Function: FUN_100042f0 at 100042f0

undefined4 FUN_100042f0(void)

{
  return 0;
}



// Function: FUN_10004300 at 10004300

undefined4 * __thiscall FUN_10004300(void *this,byte param_1)

{
  FUN_10004230((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004330 at 10004330

undefined4 FUN_10004330(int *param_1)

{
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    return 1;
  }
  return 0;
}



// Function: FUN_10004370 at 10004370

undefined4 FUN_10004370(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_100043d0 at 100043d0

undefined4 FUN_100043d0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_1002fdd8 + 4))();
    return 0;
  }
  (**(code **)(*DAT_1002fdd8 + 8))();
  return 0;
}



// Function: FUN_10004400 at 10004400

void __thiscall FUN_10004400(void *this,LPCWSTR param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001bf98;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
      local_5d = DAT_1002fdd4;
      while (WVar1 != L'\0') {
        local_68 = puVar2;
        if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (((local_64 != 0) || (pwVar3 = wcsstr(*this,L"HKCR"), pwVar3 == (wchar_t *)0x0)) ||
             (pwVar3 != *this)) {
LAB_1000452a:
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_55 == '\0') {
                local_55 = '\x01';
                goto LAB_100045a9;
              }
              iVar5 = FUN_10001870((undefined4 *)this);
              if (iVar5 == 0) {
                    /* WARNING: Load size is inaccurate */
                pWVar4 = CharNextW(*this);
                *(LPWSTR *)this = pWVar4;
                iVar5 = FUN_100018b0(&local_70,pWVar4,1);
                if (iVar5 == 0) goto LAB_10004676;
                goto LAB_1000456d;
              }
              local_55 = '\0';
            }
            else {
LAB_1000456d:
              if (local_55 != '\0') goto LAB_100045a9;
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x7b) {
              local_64 = local_64 + 1;
            }
            if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
               (local_56 == '\x01')) {
              iVar5 = FUN_100024f0(&local_70,L"\r\n\t}\r\n}\r\n");
              if (iVar5 == 0) goto LAB_10004676;
              local_56 = '\0';
            }
            goto LAB_100045a9;
          }
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          iVar5 = FUN_100024f0(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
          if (iVar5 != 0) {
            local_56 = '\x01';
            goto LAB_1000452a;
          }
LAB_10004676:
          local_5c = 0x8007000e;
          goto LAB_10004660;
        }
LAB_100045a9:
                    /* WARNING: Load size is inaccurate */
        pWVar6 = *this;
        if (*pWVar6 == L'%') {
          pWVar6 = CharNextW(pWVar6);
          *(LPCWSTR *)this = pWVar6;
          if (*pWVar6 == L'%') goto LAB_1000462d;
          pWVar6 = FUN_10001ad0(pWVar6,L'%');
          if (pWVar6 == (LPCWSTR)0x0) {
LAB_1000467f:
            local_5c = 0x80020009;
            goto LAB_10004660;
          }
                    /* WARNING: Load size is inaccurate */
          rVar7 = (int)pWVar6 - (int)*this >> 1;
          if (0x1f < (int)rVar7) {
            local_5c = 0x80004005;
            goto LAB_10004660;
          }
          FUN_10001230(local_54,0x20,*this,rVar7);
          local_78 = local_54;
          pWVar8 = (LPCWSTR)FUN_10003150((void *)(*(int *)((int)this + 4) + 4),&local_78);
          if (pWVar8 == (LPCWSTR)0x0) goto LAB_1000467f;
          iVar5 = FUN_100024f0(&local_70,pWVar8);
          if (iVar5 == 0) goto LAB_10004676;
                    /* WARNING: Load size is inaccurate */
          pWVar8 = *this;
          while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
            pWVar8 = CharNextW(*this);
            *(LPCWSTR *)this = pWVar8;
          }
        }
        else {
LAB_1000462d:
          iVar5 = FUN_100018b0(&local_70,pWVar6,1);
          if (iVar5 == 0) goto LAB_10004676;
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
LAB_10004660:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100046c0 at 100046c0

/* WARNING: Removing unreachable block (ram,0x1000471c) */
/* WARNING: Removing unreachable block (ram,0x10004769) */

void FUN_100046c0(GUID *param_1,int *param_2,int param_3)

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
  
  puStack_c = &LAB_1001c02e;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    HVar2 = CoCreateInstance((IID *)&DAT_1002328c,(LPUNKNOWN)0x0,1,(IID *)&DAT_10021b9c,&local_1a8);
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
            goto LAB_10004a30;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_194,0x40);
        local_1c8 = 0;
        local_8._0_1_ = 6;
        FUN_10001180(local_114,0x80,L"CLSID\\");
        FUN_100012f0(local_114,0x80,local_194);
        FUN_100012f0(local_114,0x80,L"\\Required Categories");
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
        FUN_10001180(local_114,0x80,L"CLSID\\");
        FUN_100012f0(local_114,0x80,local_194);
        FUN_100012f0(local_114,0x80,L"\\Implemented Categories");
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
        FUN_100022b0(&local_1b8);
        local_8._0_1_ = 6;
        FUN_100022b0(&local_1c4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10002040(&local_1c8);
      }
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
  }
LAB_10004a30:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004a70 at 10004a70

int FUN_10004a70(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1001c080;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar2 = FUN_100025d0(param_1,param_2,&local_18,&local_14);
  if (iVar2 < 0) goto LAB_10004b2c;
  iVar2 = (**(code **)(*local_14 + 0x1c))(local_14,&param_2,uVar1);
  if (iVar2 < 0) goto LAB_10004b2c;
  if (DAT_1002fdd4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_10004afe;
    pFVar3 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_10004afe;
  }
  else {
LAB_10004afe:
    pFVar3 = Ordinal_186_exref;
  }
  iVar2 = (*pFVar3)(param_2,(uint)(ushort)param_2[0xc],(uint)(ushort)param_2[0xd],
                    *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 10));
  (**(code **)(*local_14 + 0x30))(local_14,param_2);
LAB_10004b2c:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10004b70 at 10004b70

void FUN_10004b70(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1001c0d7;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = 0;
  local_220 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_14 = uVar2;
  iVar3 = FUN_100025d0(param_1,param_2,&local_228,&local_220);
  uVar1 = local_228;
  if (iVar3 < 0) goto LAB_10004c9f;
  pwVar6 = (wchar_t *)0x0;
  local_224 = (wchar_t *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(*local_220 + 0x24))(local_220,0xffffffff,0,0,0,&local_224,uVar2);
  if ((-1 < iVar3) && (local_224 != (wchar_t *)0x0)) {
    rVar4 = Ordinal_7(local_224);
    FUN_10001230(local_21c,0x104,local_224,rVar4);
    pwVar6 = local_21c;
    local_16 = 0;
    iVar3 = FUN_10001e30();
    local_21c[iVar3] = L'\0';
  }
  if (DAT_1002fdd4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_10004c7c;
    pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar5 == (FARPROC)0x0) goto LAB_10004c7c;
  }
  else {
LAB_10004c7c:
    pFVar5 = Ordinal_163_exref;
  }
  (*pFVar5)(local_220,uVar1,pwVar6);
  local_8._0_1_ = 2;
  Ordinal_6(local_224);
LAB_10004c9f:
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



// Function: FUN_10004cf0 at 10004cf0

int FUN_10004cf0(int param_1,int param_2,byte *param_3)

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
        iVar5 = FUN_100046c0((GUID *)*puVar1,piVar3,iVar6);
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
    iVar5 = FUN_10004b70(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10004d80 at 10004d80

int FUN_10004d80(int param_1,int param_2,byte *param_3)

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
        iVar5 = FUN_100046c0((GUID *)*puVar1,piVar3,iVar5);
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
    iVar5 = FUN_10004a70(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10004e10 at 10004e10

int FUN_10004e10(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
  puStack_c = &LAB_1001c5a8;
  local_10 = ExceptionList;
  uVar4 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
      iVar6 = (*(code *)puVar1[2])(puVar1[3],&DAT_100219f8,piVar2);
    }
    local_8 = 0xffffffff;
    FUN_10003440(&local_18);
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



// Function: FUN_10004f70 at 10004f70

undefined4 FUN_10004f70(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c108;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  local_8 = 0xffffffff;
  uVar1 = FUN_10004fee();
  return uVar1;
}



// Function: Catch@10004fdb at 10004fdb

undefined * Catch_10004fdb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004fe8;
}



// Function: FUN_10004fee at 10004fee

undefined4 FUN_10004fee(void)

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



// Function: FUN_10005070 at 10005070

void __fastcall FUN_10005070(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c14e;
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



// Function: FUN_100050e0 at 100050e0

void __fastcall FUN_100050e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c18e;
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



// Function: FUN_10005150 at 10005150

undefined4 * __thiscall FUN_10005150(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c1ce;
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



// Function: FUN_100051d0 at 100051d0

void FUN_100051d0(int *param_1,ushort *param_2)

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
  puStack_c = &LAB_1001c200;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffc4;
  uVar11 = (undefined2)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  uVar12 = (undefined2)((DAT_1002fdb0 ^ (uint)&stack0xfffffffc) >> 0x10);
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
LAB_10005268:
    iVar6 = 0;
    iVar5 = 0;
  }
  else {
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    if ((_Var8 < 0) || ((_Var8 < 0x100000000 && ((uint)_Var8 <= uVar3)))) goto LAB_10005268;
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    iVar6 = (uint)_Var8 - local_1c;
    iVar5 = (int)((ulonglong)_Var8 >> 0x20) - (uint)((uint)_Var8 < local_1c);
  }
  FUN_10003250(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_100053cc();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) != 0x40) {
    while( true ) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_100052f1;
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
LAB_100052f1:
    if (local_18 != 0) goto LAB_10005329;
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
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_10005329;
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
LAB_10005329:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_100053cc();
  return;
}



// Function: Catch@100053a8 at 100053a8

undefined * Catch_100053a8(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100053c9;
}



// Function: FUN_100053cc at 100053cc

void FUN_100053cc(void)

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



// Function: FUN_10005450 at 10005450

void __cdecl FUN_10005450(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      param_3[2] = param_1[2];
      param_3[3] = param_1[3];
      param_3[4] = param_1[4];
      param_1 = param_1 + 5;
      param_3 = param_3 + 5;
    } while (param_1 != param_2);
  }
  return;
}



// Function: FUN_10005490 at 10005490

void __cdecl FUN_10005490(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
    param_2[4] = param_3[4];
  }
  return;
}



// Function: FUN_10005500 at 10005500

/* WARNING: Removing unreachable block (ram,0x1000555e) */

int * __thiscall FUN_10005500(void *this,undefined4 param_1)

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
  puStack_c = &LAB_1001c260;
  local_10 = ExceptionList;
  uStack_3c = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  iVar6 = 0;
  local_18 = 0;
  local_1c = this;
  FUN_10003250(&local_24,(int *)this);
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
LAB_100055fc:
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
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_100055fc;
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
  piVar4 = (int *)FUN_100056b5();
  return piVar4;
}



// Function: Catch@10005691 at 10005691

undefined * Catch_10005691(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + -0x18) + 4) + (int)*(int **)(unaff_EBP + -0x18)),4,
             true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100056b2;
}



// Function: FUN_100056b5 at 100056b5

void FUN_100056b5(void)

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



// Function: FUN_10005740 at 10005740

undefined4 __thiscall FUN_10005740(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c2b3;
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



// Function: FUN_10005820 at 10005820

int __thiscall FUN_10005820(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x401) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100020d0(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005870 at 10005870

int __thiscall FUN_10005870(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100020d0(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100058c0 at 100058c0

/* WARNING: Removing unreachable block (ram,0x100058d2) */

int __thiscall FUN_100058c0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_100020d0(this,param_1);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005900 at 10005900

void __fastcall FUN_10005900(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10005930 at 10005930

int * __thiscall FUN_10005930(void *this,uint param_1,uint param_2)

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



// Function: FUN_100059c0 at 100059c0

int * __thiscall FUN_100059c0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10005a50 at 10005a50

void __thiscall FUN_10005a50(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2d0;
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
  FUN_100033b0((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10005b0c();
  return;
}



// Function: Catch@10005ad9 at 10005ad9

undefined * Catch_10005ad9(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100033b0((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005b03;
}



// Function: FUN_10005b0c at 10005b0c

void FUN_10005b0c(void)

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



// Function: Catch@10005b6b at 10005b6b

void Catch_10005b6b(void)

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



// Function: FUN_10005ba0 at 10005ba0

void __thiscall FUN_10005ba0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2f0;
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
  FUN_10002b40((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10005c60();
  return;
}



// Function: Catch@10005c2e at 10005c2e

undefined * Catch_10005c2e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10002b40((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005c57;
}



// Function: FUN_10005c60 at 10005c60

void FUN_10005c60(void)

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



// Function: Catch@10005cc1 at 10005cc1

void Catch_10005cc1(void)

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



// Function: FUN_10005cf0 at 10005cf0

int __thiscall FUN_10005cf0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = FUN_10003460(this,(undefined4 *)*param_1);
  if (!bVar3) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    *(undefined4 *)this = 0;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_10021e38,this);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005d50 at 10005d50

void __fastcall FUN_10005d50(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c330;
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
  FUN_10002cc0(this);
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



// Function: FUN_10005de0 at 10005de0

int * __thiscall FUN_10005de0(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x60);
  FUN_10005d50(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10005e10 at 10005e10

void __fastcall FUN_10005e10(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c370;
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
  FUN_10002cc0(this);
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



// Function: FUN_10005ea0 at 10005ea0

void __fastcall FUN_10005ea0(int param_1)

{
  if (param_1 != 0) {
    FUN_10004f70(param_1 + 4);
    return;
  }
  FUN_10004f70(0);
  return;
}



// Function: FUN_10005ed0 at 10005ed0

/* WARNING: Removing unreachable block (ram,0x10005f6d) */

basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10005ed0(void *this,uint param_1,int param_2)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this_00;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c3cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined **)this = &DAT_10021e9c;
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



// Function: FUN_10005fb0 at 10005fb0

void __fastcall FUN_10005fb0(undefined4 *param_1)

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



// Function: FUN_10006040 at 10006040

int FUN_10006040(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
  iVar2 = FUN_10004330(param_3);
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



// Function: FUN_10006130 at 10006130

LONG FUN_10006130(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1002fdd8 + 4))();
  }
  return LVar1;
}



// Function: FUN_10006160 at 10006160

LONG FUN_10006160(int *param_1)

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
    (**(code **)(*DAT_1002fdd8 + 8))();
  }
  return LVar1;
}



// Function: FUN_100061b0 at 100061b0

void FUN_100061b0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10021e6c,param_2,param_3);
  return;
}



// Function: FUN_100061d0 at 100061d0

undefined4 FUN_100061d0(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c450;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1001b07c(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    local_8 = 0xffffffff;
    uVar3 = FUN_10006266();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10006254 at 10006254

undefined * Catch_10006254(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006261;
}



// Function: FUN_10006266 at 10006266

void FUN_10006266(void)

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
  uVar4 = FUN_1001b07c(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_100062ca();
  return;
}



// Function: Catch@100062b4 at 100062b4

undefined * Catch_100062b4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_100062c1;
}



// Function: FUN_100062ca at 100062ca

bool FUN_100062ca(void)

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
    FUN_100010c0(unaff_EDI,*(rsize_t *)(unaff_EBP + -0x28),*(void **)(unaff_EBP + 8),
                 *(rsize_t *)(unaff_EBP + -0x28));
    FUN_100010c0(unaff_EBX,unaff_ESI,*(void **)(unaff_EBP + 0xc),unaff_ESI);
    iVar1 = FUN_10005740(*(void **)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x1c));
    if (iVar1 != 0) {
      unaff_EBX = (void *)0x0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      goto LAB_10006323;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
LAB_10006323:
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



// Function: FUN_10006380 at 10006380

int FUN_10006380(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c478;
  local_10 = ExceptionList;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    local_8 = 0;
    ExceptionList = &local_10;
    iVar1 = FUN_100061d0(param_2,param_3);
    ExceptionList = local_10;
    return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_10006410 at 10006410

int * __thiscall FUN_10006410(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x50);
  FUN_10005e10(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10006440 at 10006440

undefined4 * __thiscall FUN_10006440(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c4c6;
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



// Function: FUN_100064d0 at 100064d0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_100064d0(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1001c511;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2120[0] = 0;
  local_18 = uStack_2144;
  iVar1 = FUN_10001b80(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10001960(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_10006857;
  FUN_10001b20((undefined4 *)this);
  iVar1 = FUN_10001b80(this,local_2018);
  if (iVar1 < 0) goto LAB_10006857;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 < 0x14) {
    if (uVar2 == 0x13) {
      local_2124 = (void *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      uVar2 = FUN_100017b0(param_1,param_2);
      local_8 = 0xffffffff;
      FUN_10002040((int *)&local_2124);
    }
    else {
      if (uVar2 != 8) {
        if (uVar2 == 0x11) {
          local_2128 = lstrlenW(local_2018);
          if ((local_2128 & 1) == 0) {
            local_2120[0] = (int)local_2128 / 2;
            local_2120[1] = 0;
            local_8 = 5;
            FUN_100058c0(local_2120 + 1,local_2120[0]);
            local_8 = 4;
            FUN_1000661c();
            return;
          }
          goto LAB_10006857;
        }
        goto LAB_1000683b;
      }
      uVar2 = FUN_100017d0(param_1,param_2,local_2018,1);
    }
    if (uVar2 != 0) {
      FUN_10001420(uVar2);
      goto LAB_10006857;
    }
  }
  else if (uVar2 == 0x4008) {
    iVar1 = lstrlenW(local_2018);
    local_2120[1] = 0;
    local_8 = 1;
    FUN_10005870(local_2120 + 1,iVar1 + 2);
    local_8 = 0;
    FUN_10006793();
    return;
  }
LAB_1000683b:
  FUN_10001b80(this,param_3);
LAB_10006857:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10006601 at 10006601

undefined * Catch_10006601(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000660e;
}



// Function: FUN_1000661c at 1000661c

void FUN_1000661c(void)

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
      FUN_100020c0((undefined4 *)(unaff_EBP - 0x2118));
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
      FUN_100020c0((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (pvVar2 == unaff_ESI) {
      FUN_10001b80(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_10001420((uint)pvVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000686f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10006784 at 10006784

undefined * Catch_10006784(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10006791;
}



// Function: FUN_10006793 at 10006793

void FUN_10006793(void)

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
    FUN_100020c0((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_ESI) {
    FUN_10001b80(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_10001420((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000686f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10006880 at 10006880

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006880(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  
  puStack_c = &LAB_1001c577;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
LAB_10006910:
      local_2244 = 1;
      iVar4 = lstrcmpiW(param_1,L"Delete");
      local_2230 = (uint)(iVar4 == 0);
      iVar5 = lstrcmpiW(param_1,L"ForceRemove");
      if ((iVar5 != 0) && ((iVar4 == 0) == 0)) {
LAB_10006aa2:
        iVar4 = lstrcmpiW(param_1,L"NoRemove");
        if (iVar4 == 0) {
          local_2244 = 0;
          iVar4 = FUN_10001b80(local_2220,param_1);
          if (iVar4 < 0) goto LAB_10006f5f;
        }
        iVar4 = lstrcmpiW(param_1,L"Val");
        if (iVar4 == 0) {
          iVar4 = FUN_10001b80(local_2220,local_221c);
          if ((-1 < iVar4) && (iVar4 = FUN_10001b80(local_2220,param_1), -1 < iVar4)) {
            if (*param_1 != L'=') {
LAB_10006f38:
              local_8 = 0xffffffff;
              FUN_100022b0(&local_222c);
              goto LAB_10006f85;
            }
            if (param_3 != 0) {
              local_8._0_1_ = 2;
              local_2250 = local_2234;
              local_224c = 0;
              local_2248 = 0;
              iVar4 = FUN_100064d0(local_2220,&local_2250,local_221c,param_1);
              local_2250 = (HKEY)0x0;
              local_224c = 0;
              local_2248 = 0;
              if (-1 < iVar4) {
                local_8 = (uint)local_8._1_3_ << 8;
                local_224c = 0;
                goto LAB_10006a40;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100022b0(&local_2250);
              goto LAB_10006fb1;
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
                FUN_10001420(uVar7);
                local_8 = (uint)local_8._1_3_ << 8;
                ppHVar9 = &local_226c;
                goto LAB_10006f5a;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (pHVar2 != (HKEY)0x0) {
                RegCloseKey(pHVar2);
                local_226c = (HKEY)0x0;
              }
              local_2268 = 0;
            }
            iVar4 = FUN_10001d80(local_2220,param_1);
LAB_10006a80:
            if (-1 < iVar4) goto LAB_10006a8a;
          }
        }
        else {
          WVar1 = *param_1;
          pWVar6 = param_1;
          pHVar2 = local_2234;
          while (local_2234 = pHVar2, WVar1 != L'\0') {
            if (WVar1 == L'\\') {
              if (pWVar6 != (LPCWSTR)0x0) goto LAB_10006f38;
              break;
            }
            pWVar6 = CharNextW(pWVar6);
            pHVar2 = local_2234;
            WVar1 = *pWVar6;
          }
          if (param_3 == 0) {
            if (param_4 == 0) {
              local_2230 = FUN_10001700(&local_222c,pHVar2,param_1,0x20019);
              if (local_2230 == 0) goto LAB_10006d19;
            }
            else {
              local_2230 = 2;
            }
            param_4 = 1;
LAB_10006d19:
            eVar8 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
            switch(eVar8) {
            case 0:
            case 0x50:
              goto switchD_10006d41_caseD_0;
            default:
                    /* WARNING: Subroutine does not return */
              FUN_100010a0(0x80004005);
            case 0xc:
                    /* WARNING: Subroutine does not return */
              FUN_100010a0(0x8007000e);
            case 0x16:
            case 0x22:
                    /* WARNING: Subroutine does not return */
              FUN_100010a0(0x80070057);
            }
          }
          iVar4 = FUN_10001700(&local_222c,pHVar2,param_1,0x2001f);
          if (((iVar4 != 0) &&
              (iVar4 = FUN_10001700(&local_222c,pHVar2,param_1,0x20019), iVar4 != 0)) &&
             (uVar7 = FUN_10001660(&local_222c,pHVar2,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar7 != 0))
          goto LAB_10006fe0;
          iVar4 = FUN_10001b80(local_2220,param_1);
          if ((-1 < iVar4) &&
             ((*param_1 != L'=' ||
              (iVar4 = FUN_100064d0(local_2220,&local_222c,(LPCWSTR)0x0,param_1), -1 < iVar4)))) {
LAB_10006a40:
            if ((*param_1 != L'{') || (iVar4 = lstrlenW(param_1), iVar4 != 1)) goto LAB_10006a8a;
            iVar4 = FUN_10006880(local_2220,param_1,local_222c,param_3,0);
            if (-1 < iVar4) {
              iVar4 = FUN_10001b80(local_2220,param_1);
              goto LAB_10006a80;
            }
          }
        }
        goto LAB_10006f5f;
      }
      iVar4 = FUN_10001b80(local_2220,param_1);
      if (-1 < iVar4) {
        if (param_3 == 0) goto LAB_10006aa2;
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
              FUN_100022b0(&local_2240);
              goto LAB_10006f38;
            }
            break;
          }
          pWVar6 = CharNextW(pWVar6);
          WVar1 = *pWVar6;
        }
        ppuVar10 = &PTR_u_AppID_100215e8;
        do {
          iVar4 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar10);
          if (iVar4 == 0) goto LAB_100069ff;
          ppuVar10 = ppuVar10 + 1;
        } while ((int)ppuVar10 < 0x10021618);
        local_2240 = local_2234;
        local_223c = 0;
        local_2238 = 0;
        FUN_100022d0(&local_2240,param_1);
        local_2240 = (HKEY)0x0;
        local_223c = 0;
        local_2238 = 0;
LAB_100069ff:
        if (local_2230 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_10006aa2;
        }
        iVar4 = FUN_10001b80(local_2220,param_1);
        if ((-1 < iVar4) && (iVar4 = FUN_10001d80(local_2220,param_1), -1 < iVar4)) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_10006a40;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_2240;
        goto LAB_10006f5a;
      }
    }
LAB_10006f5f:
    local_8 = 0xffffffff;
    if (local_222c != (HKEY)0x0) {
      RegCloseKey(local_222c);
      local_222c = (HKEY)0x0;
    }
  }
  local_2228 = 0;
LAB_10006f85:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
switchD_10006d41_caseD_0:
  iVar4 = FUN_10001b80(local_2220,param_1);
  if (((iVar4 < 0) || (iVar4 = FUN_10001d80(local_2220,param_1), iVar4 < 0)) ||
     (((*param_1 == L'{' && (iVar4 = lstrlenW(param_1), iVar4 == 1)) &&
      (((iVar4 = FUN_10006880(local_2220,param_1,local_222c,0,param_4), iVar4 < 0 && (param_4 == 0))
       || (iVar4 = FUN_10001b80(local_2220,param_1), iVar4 < 0)))))) goto LAB_10006f5f;
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
LAB_10006fe0:
          FUN_10001420(uVar7);
LAB_10006fb1:
          local_8 = 0xffffffff;
          FUN_100022b0(&local_222c);
          goto LAB_10006f85;
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
            FUN_10001420(uVar7);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar9 = &local_2260;
LAB_10006f5a:
            FUN_100022b0(ppHVar9);
            goto LAB_10006f5f;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100022b0(&local_2260);
        }
      }
      else {
        iVar4 = FUN_10001cf0(local_21c);
        if ((iVar4 != 0) && (local_2244 != 0)) {
          FUN_100022d0(&local_222c,local_21c);
        }
      }
    }
    else if (local_2254 == 0) {
      FUN_10001420(local_2230);
      goto LAB_10006f5f;
    }
  }
LAB_10006a8a:
  if (*param_1 == L'}') goto LAB_10006f5f;
  goto LAB_10006910;
}



// Function: FUN_10007090 at 10007090

int __thiscall FUN_10007090(void *this,int *param_1,undefined4 param_2,int *param_3)

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
  puStack_c = &LAB_1001c5a8;
  local_10 = ExceptionList;
  uVar3 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002ff90);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&DAT_100219f8,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002ff90);
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
  iVar4 = FUN_10004e10((int *)&DAT_1002ff80,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: FUN_100071c0 at 100071c0

void __fastcall FUN_100071c0(int param_1)

{
  int *piVar1;
  uint3 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c614;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 0x4c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
    uVar2 = local_8._1_3_;
  }
  local_8._1_3_ = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
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



// Function: FUN_10007270 at 10007270

void __fastcall FUN_10007270(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c638;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100071c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100072c0 at 100072c0

void __fastcall FUN_100072c0(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c6ba;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 3;
  if (7 < *(uint *)(param_1 + 0x88)) {
    operator_delete(*(void **)(param_1 + 0x74));
  }
  *(undefined4 *)(param_1 + 0x88) = 7;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined2 *)(param_1 + 0x74) = 0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8._0_1_ = 1;
  if (7 < *(uint *)(param_1 + 0x60)) {
    operator_delete(*(void **)(param_1 + 0x4c));
  }
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
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



// Function: FUN_100073c0 at 100073c0

void __fastcall FUN_100073c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c6e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100072c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007410 at 10007410

void __fastcall FUN_10007410(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c797;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 6;
  Ordinal_6(*(undefined4 *)(param_1 + 0xc4),DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  piVar1 = *(int **)(param_1 + 0xc0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 4;
  if (7 < *(uint *)(param_1 + 0xb4)) {
    operator_delete(*(void **)(param_1 + 0xa0));
  }
  *(undefined4 *)(param_1 + 0xb4) = 7;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  local_8._0_1_ = 3;
  if (7 < *(uint *)(param_1 + 0x98)) {
    operator_delete(*(void **)(param_1 + 0x84));
  }
  *(undefined4 *)(param_1 + 0x98) = 7;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined2 *)(param_1 + 0x84) = 0;
  local_8._0_1_ = 2;
  if (7 < *(uint *)(param_1 + 0x7c)) {
    operator_delete(*(void **)(param_1 + 0x68));
  }
  *(undefined4 *)(param_1 + 0x7c) = 7;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x68) = 0;
  local_8._0_1_ = 1;
  if (7 < *(uint *)(param_1 + 0x60)) {
    operator_delete(*(void **)(param_1 + 0x4c));
  }
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
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



// Function: FUN_10007580 at 10007580

void __fastcall FUN_10007580(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c7c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10007410(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100075d0 at 100075d0

void __fastcall FUN_100075d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001c82c;
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



// Function: FUN_10007690 at 10007690

void __fastcall FUN_10007690(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c858;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100075d0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100076e0 at 100076e0

void __thiscall FUN_100076e0(void *this,undefined4 param_1)

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
  puStack_c = &LAB_1001c8f9;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10007953;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1002fdd8 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_1002fddc == *piVar1) && (DAT_1002fde0 == piVar1[1])) && (DAT_1002fde4 == piVar1[2]))
        && ((DAT_1002fde8 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_1002ffac,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007921;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002040((int *)&local_220);
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
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_10021958,&local_220);
        if (-1 < iVar4) {
          FUN_10005cf0(&local_224,(int *)&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_10005ea0(DAT_1002fdd8);
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
LAB_10007921:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_10002e30(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10007953:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007980 at 10007980

void __cdecl FUN_10007980(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
    param_2[4] = param_3[4];
  }
  return;
}



// Function: FUN_100079f0 at 100079f0

undefined4 * __cdecl
FUN_100079f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    FUN_10005490(param_4,param_3,param_1);
    param_3 = param_3 + 5;
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch@10007a69 at 10007a69

void Catch_10007a69(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10007a80 at 10007a80

void __fastcall FUN_10007a80(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_10007ab0 at 10007ab0

void __fastcall FUN_10007ab0(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c970;
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
  FUN_10002cc0(this);
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



// Function: FUN_10007b40 at 10007b40

int * __thiscall FUN_10007b40(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x58);
  FUN_10007ab0(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: DllGetClassObject at 10007b70

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x7b70  2  DllGetClassObject */
  iVar1 = FUN_10007090(&DAT_1002ff38,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_10007b80 at 10007b80

DWORD FUN_10007b80(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c99b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005fb0(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10007c26();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007c13 at 10007c13

undefined * Catch_10007c13(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007c20;
}



// Function: FUN_10007c26 at 10007c26

DWORD FUN_10007c26(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10007c83;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_10007c5b;
  }
  else {
LAB_10007c5b:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_10007c83;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10007c83:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10007ca0 at 10007ca0

void __fastcall FUN_10007ca0(_Container_base0 *param_1)

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



// Function: FUN_10007cd0 at 10007cd0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10007cd0(void *this,LPCWSTR param_1,int param_2)

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
  
  local_8 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_200c = (WCHAR *)0x0;
  iVar4 = FUN_10004400(this,param_1,&local_200c);
  if (iVar4 < 0) {
LAB_10007de5:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(WCHAR **)this = local_200c;
  WVar1 = *local_200c;
joined_r0x10007d1e:
  if ((WVar1 == L'\0') || (iVar4 = FUN_10001b80(this,local_2008), iVar4 < 0)) goto LAB_10007dd6;
  uVar6 = 0;
  while (iVar4 = lstrcmpiW(local_2008,(LPCWSTR)(&PTR_u_HKCR_100216d8)[uVar6 * 2]), iVar4 != 0) {
    uVar6 = uVar6 + 1;
    if (0xd < uVar6) goto LAB_10007dd6;
  }
  pHVar2 = (HKEY)(&DAT_100216dc)[uVar6 * 2];
  if (((pHVar2 == (HKEY)0x0) || (iVar4 = FUN_10001b80(this,local_2008), iVar4 < 0)) ||
     (local_2008[0] != L'{')) goto LAB_10007dd6;
  if (param_2 == 0) {
    iVar4 = FUN_10006880(this,local_2008,pHVar2,0,0);
    if (iVar4 < 0) goto LAB_10007dd6;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *this;
    iVar4 = FUN_10006880(this,local_2008,pHVar2,param_2,0);
    if (iVar4 < 0) {
      *(undefined4 *)this = uVar3;
      FUN_10006880(this,local_2008,pHVar2,0,0);
LAB_10007dd6:
      CoTaskMemFree(local_200c);
      goto LAB_10007de5;
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
      goto switchD_10007e24_caseD_b;
    }
  } while( true );
switchD_10007e24_caseD_b:
  WVar1 = *lpsz;
  goto joined_r0x10007d1e;
}



// Function: FUN_10007e70 at 10007e70

int __thiscall FUN_10007e70(void *this,int param_1,byte *param_2)

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
        iVar5 = FUN_100046c0((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10004cf0(0x1002ff80,param_1,param_2);
  if ((-1 < iVar5) && (DAT_1002fdcc != (code *)0x0)) {
    iVar5 = (*DAT_1002fdcc)(DAT_1002ffac);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_10007f10 at 10007f10

int __thiscall FUN_10007f10(void *this,int param_1,byte *param_2)

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
        iVar5 = FUN_100046c0((GUID *)*piVar4,piVar3,iVar5);
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
  if ((DAT_1002fdd0 != (code *)0x0) && (iVar5 = (*DAT_1002fdd0)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_10004d80(0x1002ff80,param_1,param_2);
  return iVar5;
}



// Function: FUN_10007fa0 at 10007fa0

void __fastcall FUN_10007fa0(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[3] = IXMLSerializationImpl<struct_CAuditData,void*>::vftable;
  *param_1 = CAuditData::vftable;
  param_1[1] = CAuditData::vftable;
  param_1[2] = CAuditData::vftable;
  param_1[3] = CAuditData::vftable;
  param_1[0x11] = 7;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  param_1[0x13] = 0;
  return;
}



// Function: FUN_10008060 at 10008060

bool __cdecl FUN_10008060(int param_1)

{
  return param_1 != 0;
}



// Function: AtlAdd<> at 10008070

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



// Function: FUN_100080a0 at 100080a0

void __fastcall FUN_100080a0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,
                          &TSimpleObject<struct_CAuditData,&struct__GUID_const_CLSID_AuditData,struct_IAuditData,&struct__GUID_const_IID_IAuditData,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                           ::RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0);
  FUN_10001fb0((LPVOID *)(iVar1 + 0x4c),(IID *)&DAT_10021568);
  return;
}



// Function: FUN_100080d0 at 100080d0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_100080d0(int param_1)

{
  int iVar1;
  uint local_38;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_1001b2bc;
  local_14 = ExceptionList;
  local_c = DAT_1002fdb0 ^ 0x10027c08;
  local_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10008190 at 10008190

void __cdecl FUN_10008190(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10021618,param_2);
  return;
}



// Function: FUN_100081b0 at 100081b0

void __fastcall FUN_100081b0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca33;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10008240 at 10008240

undefined4 * __thiscall FUN_10008240(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (-param_1 - 1U < 8) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x80070216);
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



// Function: FUN_10008290 at 10008290

void FUN_10008290(int param_1,undefined4 param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  
  ppv = (LPVOID *)(param_1 + 0x44);
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10021568,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021618,ppv),
     HVar1 < 0)) {
    return;
  }
  FUN_10008190((undefined4 *)*ppv,param_2);
  return;
}



// Function: FUN_100082d0 at 100082d0

void __fastcall FUN_100082d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100081b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008320 at 10008320

void __cdecl FUN_10008320(undefined4 *param_1,int *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ca88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_1,DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010a0(0x8007000e);
    }
  }
  *param_2 = iVar1;
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100083a0 at 100083a0

undefined4 __thiscall FUN_100083a0(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cab0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 == 3) {
    local_8 = 0;
    lVar2 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar3 = FUN_1001b07c(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)((int)this + 8) = uVar3;
    local_8 = 0xffffffff;
    uVar3 = FUN_10008424();
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



// Function: Catch@10008411 at 10008411

undefined * Catch_10008411(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000841e;
}



// Function: FUN_10008424 at 10008424

undefined4 FUN_10008424(void)

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
        FUN_100010a0(0x80004005);
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



// Function: FUN_100084f0 at 100084f0

undefined4 * __fastcall FUN_100084f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001caf3;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10008580 at 10008580

undefined4 FUN_10008580(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_100085a0 at 100085a0

bool FUN_100085a0(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_100085d0 at 100085d0

undefined4 FUN_100085d0(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_100085e0 at 100085e0

int FUN_100085e0(int *param_1)

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



// Function: FUN_10008610 at 10008610

uint FUN_10008610(int param_1,uint param_2,int *param_3,uint *param_4)

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
      FUN_100010a0(0x80004005);
    }
    return 0x80004005;
  }
  return 0x80004003;
}



// Function: FUN_100086e0 at 100086e0

void FUN_100086e0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10021f54,param_2,param_3);
  return;
}



// Function: FUN_10008700 at 10008700

undefined4 * __thiscall FUN_10008700(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cb20;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100081b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008780 at 10008780

void __fastcall FUN_10008780(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[3] = IXMLSerializationImpl<struct_CAuditModule,void*>::vftable;
  *param_1 = CAuditModule::vftable;
  param_1[1] = CAuditModule::vftable;
  param_1[2] = CAuditModule::vftable;
  param_1[3] = CAuditModule::vftable;
  param_1[0x11] = 7;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  param_1[0x18] = 7;
  param_1[0x17] = 0;
  *(undefined2 *)(param_1 + 0x13) = 0;
  param_1[0x1c] = 0;
  param_1[0x22] = 7;
  param_1[0x21] = 0;
  *(undefined2 *)(param_1 + 0x1d) = 0;
  return;
}



// Function: FUN_10008860 at 10008860

void __cdecl FUN_10008860(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = param_1;
  return;
}



// Function: FUN_10008870 at 10008870

undefined4 FUN_10008870(int param_1,undefined4 param_2)

{
  FUN_10008860(param_2,(undefined4 *)(param_1 + 0x60));
  return 0;
}



// Function: FUN_10008890 at 10008890

undefined4 FUN_10008890(int param_1,undefined4 *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cbc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x60);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000890e at 1000890e

undefined1 * Catch_1000890e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000891b;
}



// Function: FUN_10008940 at 10008940

undefined4 FUN_10008940(int param_1,short param_2)

{
  *(bool *)(param_1 + 100) = param_2 == -1;
  return 0;
}



// Function: FUN_10008960 at 10008960

undefined4 FUN_10008960(int param_1,short *param_2)

{
  byte bVar1;
  bool bVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cbe0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar2 = FUN_10008060((int)param_2);
  if (!bVar2) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  bVar1 = *(byte *)(param_1 + 100);
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100089e4 at 100089e4

undefined1 * Catch_100089e4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100089f1;
}



// Function: FUN_10008a10 at 10008a10

void __fastcall FUN_10008a10(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,
                          &TSimpleObject<struct_CAuditModule,&struct__GUID_const_CLSID_AuditModule,struct_IAuditModule,&struct__GUID_const_IID_IAuditModule,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                           ::RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0);
  FUN_10001fe0((LPVOID *)(iVar1 + 0x70),(IID *)&DAT_10021588);
  return;
}



// Function: FUN_10008a40 at 10008a40

void __cdecl FUN_10008a40(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10021628,param_2);
  return;
}



// Function: FUN_10008a60 at 10008a60

void FUN_10008a60(int param_1,undefined4 param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  
  ppv = (LPVOID *)(param_1 + 0x68);
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10021588,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021628,ppv),
     HVar1 < 0)) {
    return;
  }
  FUN_10008a40((undefined4 *)*ppv,param_2);
  return;
}



// Function: FUN_10008aa0 at 10008aa0

undefined4 FUN_10008aa0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar1 = *(int **)(param_1 + 0x68);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    (**(code **)*param_2)(param_2,&DAT_100219f8,(int *)(param_1 + 0x68));
  }
  return 0;
}



// Function: FUN_10008ae0 at 10008ae0

undefined4 FUN_10008ae0(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_10008320((undefined4 *)(param_1 + 0x28),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10008b66 at 10008b66

undefined1 * Catch_10008b66(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008b73;
}



// Function: FUN_10008b90 at 10008b90

void __fastcall FUN_10008b90(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[3] = IXMLSerializationImpl<struct_CAuditRecord,void*>::vftable;
  *param_1 = CAuditRecord::vftable;
  param_1[1] = CAuditRecord::vftable;
  param_1[2] = CAuditRecord::vftable;
  param_1[3] = CAuditRecord::vftable;
  param_1[0x11] = 7;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  param_1[0x18] = 7;
  param_1[0x17] = 0;
  *(undefined2 *)(param_1 + 0x13) = 0;
  param_1[0x1f] = 7;
  param_1[0x1e] = 0;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  param_1[0x26] = 7;
  param_1[0x25] = 0;
  *(undefined2 *)(param_1 + 0x21) = 0;
  param_1[0x2d] = 7;
  param_1[0x2c] = 0;
  *(undefined2 *)(param_1 + 0x28) = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  return;
}



// Function: FUN_10008ca0 at 10008ca0

undefined4 FUN_10008ca0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)(param_1,param_2,&param_1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return uVar1;
}



// Function: FUN_10008cd0 at 10008cd0

bool __thiscall FUN_10008cd0(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,*param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_10008d00 at 10008d00

undefined4 FUN_10008d00(int param_1,short param_2)

{
  *(bool *)(param_1 + 0xb4) = param_2 == -1;
  return 0;
}



// Function: FUN_10008d20 at 10008d20

undefined4 FUN_10008d20(int param_1,short *param_2)

{
  byte bVar1;
  bool bVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ccd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar2 = FUN_10008060((int)param_2);
  if (!bVar2) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  bVar1 = *(byte *)(param_1 + 0xb4);
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10008da7 at 10008da7

undefined1 * Catch_10008da7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008db4;
}



// Function: FUN_10008dd0 at 10008dd0

void __fastcall FUN_10008dd0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,
                          &TSimpleObject<struct_CAuditRecord,&struct__GUID_const_CLSID_AuditRecord,struct_IAuditRecord,&struct__GUID_const_IID_IAuditRecord,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                           ::RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0);
  FUN_10002010((LPVOID *)(iVar1 + 0xc0),(IID *)&DAT_100215a8);
  return;
}



// Function: FUN_10008e00 at 10008e00

void __cdecl FUN_10008e00(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10021650,param_2);
  return;
}



// Function: FUN_10008e20 at 10008e20

void FUN_10008e20(int param_1,undefined4 param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  
  ppv = (LPVOID *)(param_1 + 0xb8);
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_100215a8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021650,ppv),
     HVar1 < 0)) {
    return;
  }
  FUN_10008e00((undefined4 *)*ppv,param_2);
  return;
}



// Function: FUN_10008e60 at 10008e60

undefined4 FUN_10008e60(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ccf8;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(param_1 + 0xc0) = 0;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(param_2,uVar1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010a0(0x8007000e);
    }
  }
  local_8 = 0;
  if (iVar2 != *(int *)(param_1 + 0xbc)) {
    Ordinal_6(*(int *)(param_1 + 0xbc));
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
    else {
      iVar2 = Ordinal_2(iVar2);
      *(int *)(param_1 + 0xbc) = iVar2;
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010a0(0x8007000e);
      }
    }
  }
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10008f20 at 10008f20

undefined4 FUN_10008f20(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_10008320((undefined4 *)(param_1 + 0x44),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10008fa6 at 10008fa6

undefined1 * Catch_10008fa6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008fb3;
}



// Function: FUN_10008fd0 at 10008fd0

undefined4 FUN_10008fd0(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_10008320((undefined4 *)(param_1 + 0x60),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10009056 at 10009056

undefined1 * Catch_10009056(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10009063;
}



// Function: FUN_10009080 at 10009080

undefined4 FUN_10009080(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_10008320((undefined4 *)(param_1 + 0x7c),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10009106 at 10009106

undefined1 * Catch_10009106(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10009113;
}



// Function: FUN_10009130 at 10009130

undefined4 FUN_10009130(int param_1,int *param_2)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = FUN_10008060((int)param_2);
  if (!bVar1) {
    ExceptionList = local_10;
    return 0x80004003;
  }
  local_8 = 0;
  FUN_10008320((undefined4 *)(param_1 + 0x98),param_2);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100091b8 at 100091b8

undefined1 * Catch_100091b8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100091c5;
}



// Function: FUN_100091e0 at 100091e0

int * __thiscall FUN_100091e0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
      FUN_10005ba0(this,uVar1);
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



// Function: FUN_100092f0 at 100092f0

int * __thiscall FUN_100092f0(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_100091e0(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
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
      FUN_10005ba0(this,uVar1);
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



// Function: FUN_10009410 at 10009410

void __fastcall FUN_10009410(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[3] = IXMLSerializationImpl<struct_CAuditAdjustment,void*>::vftable;
  *param_1 = CAuditAdjustment::vftable;
  param_1[1] = CAuditAdjustment::vftable;
  param_1[2] = CAuditAdjustment::vftable;
  param_1[3] = CAuditAdjustment::vftable;
  param_1[0x11] = 7;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  param_1[0x18] = 7;
  param_1[0x17] = 0;
  *(undefined2 *)(param_1 + 0x13) = 0;
  return;
}



// Function: FUN_100094d0 at 100094d0

undefined4 __fastcall FUN_100094d0(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &TSimpleObject<struct_CAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,struct_IAuditAdjustment,&struct__GUID_const_IID_IAuditAdjustment,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                   ::RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0);
  return 0;
}



// Function: FUN_100094f0 at 100094f0

void FUN_100094f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  if (param_3 == (undefined4 *)0x0) {
    __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_3 = 0;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009540 at 10009540

void FUN_10009540(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10009560 at 10009560

void FUN_10009560(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_10009580 at 10009580

void FUN_10009580(int param_1)

{
  FUN_100095b0(param_1 + -8);
  return;
}



// Function: FUN_10009590 at 10009590

void FUN_10009590(int param_1)

{
  FUN_10009540(param_1 + -8);
  return;
}



// Function: FUN_100095a0 at 100095a0

void FUN_100095a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10009560(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_100095b0 at 100095b0

void FUN_100095b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_100095d0 at 100095d0

void FUN_100095d0(int param_1)

{
  FUN_100095b0(param_1 + -4);
  return;
}



// Function: FUN_100095e0 at 100095e0

void FUN_100095e0(int param_1)

{
  FUN_10009540(param_1 + -4);
  return;
}



// Function: FUN_100095f0 at 100095f0

void FUN_100095f0(int param_1)

{
  FUN_10009540(param_1 + -0xc);
  return;
}



// Function: FUN_10009600 at 10009600

void FUN_10009600(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10009560(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10009610 at 10009610

void FUN_10009610(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10009560(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10009620 at 10009620

void FUN_10009620(int param_1)

{
  FUN_100095b0(param_1 + -0xc);
  return;
}



// Function: FUN_10009630 at 10009630

int __cdecl FUN_10009630(int *param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *local_14;
  ushort **local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == (ushort *)0x0) {
    return -0x7fffbffd;
  }
  if (param_1 != (int *)0x0) {
    local_14 = param_3;
    uVar1 = *param_3;
    local_c = 1;
    local_8 = 1;
    local_10 = &param_3;
    param_3 = (ushort *)0xfffffffd;
    if ((((uVar1 == 0xd) || (uVar1 == 9)) || ((uVar1 & 0x6000) != 0)) &&
       (iVar2 = (**(code **)(*param_1 + 0x18))
                          (param_1,param_2,&DAT_100232bc,0x400,8,&local_14,0,0,0), -1 < iVar2)) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_2,&DAT_100232bc,0x400,4,&local_14,0,0,0);
    return iVar2;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_100096e0 at 100096e0

void __fastcall FUN_100096e0(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_100096f0 at 100096f0

undefined4 * __thiscall FUN_100096f0(void *this,byte param_1)

{
  FUN_100096e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009720 at 10009720

void * __cdecl FUN_10009720(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd99;
  local_10 = ExceptionList;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < (char *)0x40000000) &&
     (pvVar1 = operator_new((int)param_1 * 4), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026d00);
}



// Function: FUN_100097b0 at 100097b0

undefined2 * __thiscall FUN_100097b0(void *this,int param_1)

{
  int iVar1;
  
  *(undefined2 *)this = 0;
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(iVar1);
  }
  *(undefined2 *)this = 8;
  iVar1 = Ordinal_2(param_1);
  *(int *)((int)this + 8) = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_10009810 at 10009810

void __fastcall FUN_10009810(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ce10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1002fdb0 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009860 at 10009860

undefined4 * __thiscall FUN_10009860(void *this,int *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce40;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100098c0 at 100098c0

void __fastcall FUN_100098c0(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_100098e0 at 100098e0

void __cdecl FUN_100098e0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
  }
  return;
}



// Function: FUN_10009940 at 10009940

void * FUN_10009940(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 2) * 4;
  pvVar1 = memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}



// Function: FUN_10009970 at 10009970

void __thiscall FUN_10009970(void *this,char *param_1)

{
  void *pvVar1;
  int iVar2;
  char *extraout_EAX;
  char *pcVar3;
  void *pvVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar3 = param_1;
  if ((char *)0x3fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
    pcVar3 = extraout_EAX;
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)(*(int *)((int)this + 8) - *this >> 2) < pcVar3) {
    pvVar4 = FUN_10009720(pcVar3);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_10009940(*this,*(int *)((int)this + 4),pvVar4);
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)((int)this + 8) = (void *)((int)pvVar4 + (int)param_1 * 4);
    *(void **)((int)this + 4) = (void *)((int)pvVar4 + (iVar2 - (int)pvVar1 >> 2) * 4);
    *(void **)this = pvVar4;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@10009a2f at 10009a2f

void Catch_10009a2f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009a50 at 10009a50

void __fastcall FUN_10009a50(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ce8b;
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



// Function: FUN_10009ac0 at 10009ac0

undefined4 * __thiscall FUN_10009ac0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ce8b;
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



// Function: FUN_10009b40 at 10009b40

void __thiscall FUN_10009b40(void *this,int param_1)

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
    FUN_10009970(this,pcVar4);
  }
  return;
}



// Function: FUN_10009ba0 at 10009ba0

undefined4 FUN_10009ba0(int param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_34;
  int local_30;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cf50;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_8 = 1;
  CoCreateInstance((IID *)&DAT_100232dc,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100218e0,&local_1c);
  (**(code **)(*local_1c + 0x104))(local_1c,param_2,local_14,uVar1);
  local_34 = (int *)0x0;
  local_8._0_1_ = 3;
  local_30 = 0;
  (**(code **)(*local_1c + 0x34))(local_1c,&local_34);
  local_18 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_34 + 0x30))(local_34,&local_18);
  uVar2 = (**(code **)(*local_18 + 0x20))(local_18,&local_30);
  local_2c = 0;
  if (0 < local_30) {
    do {
      local_28 = (int *)0x0;
      local_8._0_1_ = 7;
      (**(code **)(*local_18 + 0x1c))(local_18,local_2c,&local_28);
      local_24 = 0;
      local_8._0_1_ = 8;
      (**(code **)(*local_28 + 0x88))(local_28,&local_24);
      local_20 = (int *)0x0;
      local_8._0_1_ = 10;
      iVar3 = Ordinal_2(&DAT_1002244c);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010a0(0x8007000e);
      }
      local_8._0_1_ = 0xb;
      (**(code **)(*(int *)(param_1 + -4) + 0x24))(param_1 + -4,iVar3,&local_20);
      local_8._0_1_ = 10;
      Ordinal_6(iVar3);
      param_2 = (int *)0x0;
      local_8._0_1_ = 0xd;
      (**(code **)*local_20)(local_20,&DAT_10021904,&param_2);
      uVar2 = (**(code **)(*param_2 + 0x20))(param_2,local_24);
      local_8._0_1_ = 10;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
      local_8._0_1_ = 8;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      local_8._0_1_ = 7;
      Ordinal_6(local_24);
      local_8 = CONCAT31(local_8._1_3_,5);
      if (local_28 != (int *)0x0) {
        (**(code **)(*local_28 + 8))(local_28);
      }
      local_2c = local_2c + 1;
    } while (local_2c < local_30);
  }
  local_8._0_1_ = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10009db0 at 10009db0

void __fastcall FUN_10009db0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10009dc0 at 10009dc0

undefined4 FUN_10009dc0(int param_1,int *param_2)

{
  *param_2 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;
  return 0;
}



// Function: FUN_10009de0 at 10009de0

undefined4 __thiscall
FUN_10009de0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_100076e0(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_10009eae;
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
LAB_10009eae:
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



// Function: FUN_10009f00 at 10009f00

undefined4 FUN_10009f00(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cf70;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_100084f0(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_10009fa3();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_10009fa3();
  return uVar2;
}



// Function: Catch@10009f8d at 10009f8d

undefined * Catch_10009f8d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009f9a;
}



// Function: FUN_10009fa3 at 10009fa3

undefined4 FUN_10009fa3(void)

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



// Function: FUN_10009fd0 at 10009fd0

void __fastcall FUN_10009fd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cf98;
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



// Function: FUN_1000a040 at 1000a040

undefined4 FUN_1000a040(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002ef5c == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002ef50,param_3);
  }
  *param_4 = DAT_1002ef5c;
  if (DAT_1002ef5c != (int *)0x0) {
    (**(code **)(*DAT_1002ef5c + 4))(DAT_1002ef5c);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000a0a0 at 1000a0a0

void FUN_1000a0a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002ef50,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000a0d0 at 1000a0d0

void FUN_1000a0d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002ef5c == (int *)0x0) || (DAT_1002ef64 == 0)) {
    FUN_100076e0(&PTR_DAT_1002ef50,param_4);
  }
  if (DAT_1002ef5c != (int *)0x0) {
    (**(code **)(*DAT_1002ef5c + 0x2c))
              (DAT_1002ef5c,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000a130 at 1000a130

int * __thiscall FUN_1000a130(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_100059c0(this,uVar2 + param_2,0xffffffff);
    FUN_100059c0(this,0,param_2);
    return (int *)this;
  }
  if (uVar2 == 0xffffffff) {
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



// Function: FUN_1000a220 at 1000a220

int * __thiscall FUN_1000a220(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_10005930(this,uVar2 + param_2,0xffffffff);
    FUN_10005930(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10005ba0(this,uVar2);
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



// Function: FUN_1000a320 at 1000a320

int * __thiscall FUN_1000a320(void *this,int *param_1,uint param_2)

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
          piVar2 = FUN_1000a130(this,(int *)this,(int)param_1 - *this,param_2);
          return piVar2;
        }
        piVar2 = FUN_1000a130(this,(int *)this,(int)param_1 - (int)this,param_2);
        return piVar2;
      }
    }
  }
  if (param_2 == 0xffffffff) {
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



// Function: FUN_1000a420 at 1000a420

int * __thiscall FUN_1000a420(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_1000a220(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10005ba0(this,param_2);
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



// Function: FUN_1000a520 at 1000a520

long __cdecl FUN_1000a520(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined *local_bc [4];
  undefined **local_ac [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  undefined4 local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  long local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d025;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_bc[0] = &DAT_10021e94;
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
  *(undefined ***)((int)local_bc + *(int *)(local_bc[0] + 4)) =
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
  FUN_10003d50(local_ac,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             &local_14);
  *(undefined ***)((int)local_bc + *(int *)(local_bc[0] + 4)) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10002cc0(local_18);
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



// Function: FUN_1000a680 at 1000a680

int __cdecl FUN_1000a680(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined *local_bc [4];
  undefined **local_ac [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  undefined4 local_1c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d025;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_bc[0] = &DAT_10021e94;
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
  *(undefined ***)((int)local_bc + *(int *)(local_bc[0] + 4)) =
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
  FUN_10003d50(local_ac,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_bc,
             &local_14);
  *(undefined ***)((int)local_bc + *(int *)(local_bc[0] + 4)) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_18 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  local_ac[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10002cc0(local_18);
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



// Function: FUN_1000a7e0 at 1000a7e0

float10 __cdecl FUN_1000a7e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined *local_c0 [4];
  undefined **local_b0 [18];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_68 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_20;
  float local_1c [2];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d0b5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c[1] = 0.0;
  local_c0[0] = &DAT_10021e94;
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
  *(undefined ***)((int)local_c0 + *(int *)(local_c0[0] + 4)) =
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
  FUN_10003d50(local_b0,param_1,(char *)*puVar1,2);
  local_8 = 4;
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator>>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c0,
             local_1c);
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_68;
  *(undefined ***)((int)local_c0 + *(int *)(local_c0[0] + 4)) =
       std::
       basic_istringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_20 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_b0;
  local_b0[0] = std::
                basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                ::vftable;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  FUN_10002cc0(local_20);
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



// Function: DllRegisterServer at 1000a940

void DllRegisterServer(void)

{
                    /* 0xa940  3  DllRegisterServer */
  FUN_10007e70(&DAT_1002ff38,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000a950

void DllUnregisterServer(void)

{
                    /* 0xa950  4  DllUnregisterServer */
  FUN_10007f10(&DAT_1002ff38,1,(byte *)0x0);
  return;
}



// Function: FUN_1000a960 at 1000a960

undefined4 FUN_1000a960(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002ef78 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002ef6c,param_3);
  }
  *param_4 = DAT_1002ef78;
  if (DAT_1002ef78 != (int *)0x0) {
    (**(code **)(*DAT_1002ef78 + 4))(DAT_1002ef78);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000a9c0 at 1000a9c0

void FUN_1000a9c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002ef6c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000a9f0 at 1000a9f0

void FUN_1000a9f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002ef78 == (int *)0x0) || (DAT_1002ef80 == 0)) {
    FUN_100076e0(&PTR_DAT_1002ef6c,param_4);
  }
  if (DAT_1002ef78 != (int *)0x0) {
    (**(code **)(*DAT_1002ef78 + 0x2c))
              (DAT_1002ef78,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000aa50 at 1000aa50

void __fastcall FUN_1000aa50(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d11b;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
             ::vftable;
  param_1[1] = IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
               ::vftable;
  local_8 = 0;
  puVar2 = (undefined4 *)param_1[2];
  if (puVar2 != (undefined4 *)param_1[3]) {
    do {
      (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,uVar1);
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)param_1[3]);
  }
  local_8 = 0xffffffff;
  if (param_1[2] != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 2));
    operator_delete((void *)param_1[2]);
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aaf0 at 1000aaf0

undefined4 FUN_1000aaf0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002ef94 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002ef88,param_3);
  }
  *param_4 = DAT_1002ef94;
  if (DAT_1002ef94 != (int *)0x0) {
    (**(code **)(*DAT_1002ef94 + 4))(DAT_1002ef94);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ab50 at 1000ab50

void FUN_1000ab50(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002ef88,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000ab80 at 1000ab80

void FUN_1000ab80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002ef94 == (int *)0x0) || (DAT_1002ef9c == 0)) {
    FUN_100076e0(&PTR_DAT_1002ef88,param_4);
  }
  if (DAT_1002ef94 != (int *)0x0) {
    (**(code **)(*DAT_1002ef94 + 0x2c))
              (DAT_1002ef94,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000abe0 at 1000abe0

int FUN_1000abe0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d0e8;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_100084f0(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_1000ac7b();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_1000ac7b();
  return iVar2;
}



// Function: Catch@1000ac69 at 1000ac69

undefined * Catch_1000ac69(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ac76;
}



// Function: FUN_1000ac7b at 1000ac7b

int FUN_1000ac7b(void)

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
    cVar1 = FUN_100080d0((int)unaff_EBX);
    if (cVar1 == '\0') {
      piVar2 = FUN_10008240((void *)(unaff_EBP + -0x14),(int)unaff_EBX);
      if (piVar2 != unaff_EBX) {
        iVar3 = FUN_100083a0(unaff_ESI,(int)piVar2,(int)piVar2,*(int **)(unaff_EBP + 8),3);
        if ((int)unaff_EBX <= iVar3) {
          iVar3 = (**(code **)*unaff_ESI)();
          if ((int)unaff_EBX <= iVar3) goto LAB_1000ad0c;
        }
        (**(code **)(*unaff_ESI + 0x1c))(1);
LAB_1000ad0c:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_10002040((int *)(unaff_EBP + -0x14));
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return iVar3;
      }
    }
    (**(code **)(*unaff_ESI + 0x1c))(1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002040((int *)(unaff_EBP + -0x14));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -0x7ff8fff2;
}



// Function: FUN_1000ad40 at 1000ad40

undefined4 FUN_1000ad40(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002efb0 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002efa4,param_3);
  }
  *param_4 = DAT_1002efb0;
  if (DAT_1002efb0 != (int *)0x0) {
    (**(code **)(*DAT_1002efb0 + 4))(DAT_1002efb0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ada0 at 1000ada0

void FUN_1000ada0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002efa4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000add0 at 1000add0

void FUN_1000add0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002efb0 == (int *)0x0) || (DAT_1002efb8 == 0)) {
    FUN_100076e0(&PTR_DAT_1002efa4,param_4);
  }
  if (DAT_1002efb0 != (int *)0x0) {
    (**(code **)(*DAT_1002efb0 + 0x2c))
              (DAT_1002efb0,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000ae30 at 1000ae30

void __fastcall FUN_1000ae30(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d11b;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
             ::vftable;
  param_1[1] = IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
               ::vftable;
  local_8 = 0;
  puVar2 = (undefined4 *)param_1[2];
  if (puVar2 != (undefined4 *)param_1[3]) {
    do {
      (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,uVar1);
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)param_1[3]);
  }
  local_8 = 0xffffffff;
  if (param_1[2] != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 2));
    operator_delete((void *)param_1[2]);
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aed0 at 1000aed0

undefined4 FUN_1000aed0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002efcc == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002efc0,param_3);
  }
  *param_4 = DAT_1002efcc;
  if (DAT_1002efcc != (int *)0x0) {
    (**(code **)(*DAT_1002efcc + 4))(DAT_1002efcc);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000af30 at 1000af30

void FUN_1000af30(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002efc0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000af60 at 1000af60

void FUN_1000af60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002efcc == (int *)0x0) || (DAT_1002efd4 == 0)) {
    FUN_100076e0(&PTR_DAT_1002efc0,param_4);
  }
  if (DAT_1002efcc != (int *)0x0) {
    (**(code **)(*DAT_1002efcc + 0x2c))
              (DAT_1002efcc,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000afd0 at 1000afd0

undefined4 FUN_1000afd0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002efe8 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002efdc,param_3);
  }
  *param_4 = DAT_1002efe8;
  if (DAT_1002efe8 != (int *)0x0) {
    (**(code **)(*DAT_1002efe8 + 4))(DAT_1002efe8);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000b030 at 1000b030

void FUN_1000b030(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002efdc,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000b060 at 1000b060

void FUN_1000b060(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002efe8 == (int *)0x0) || (DAT_1002eff0 == 0)) {
    FUN_100076e0(&PTR_DAT_1002efdc,param_4);
  }
  if (DAT_1002efe8 != (int *)0x0) {
    (**(code **)(*DAT_1002efe8 + 0x2c))
              (DAT_1002efe8,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000b0c0 at 1000b0c0

void __fastcall FUN_1000b0c0(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d11b;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
             ::vftable;
  param_1[1] = IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
               ::vftable;
  local_8 = 0;
  puVar2 = (undefined4 *)param_1[2];
  if (puVar2 != (undefined4 *)param_1[3]) {
    do {
      (**(code **)(*(int *)*puVar2 + 8))((int *)*puVar2,uVar1);
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)param_1[3]);
  }
  local_8 = 0xffffffff;
  if (param_1[2] != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 2));
    operator_delete((void *)param_1[2]);
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b160 at 1000b160

undefined4 FUN_1000b160(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002f004 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002eff8,param_3);
  }
  *param_4 = DAT_1002f004;
  if (DAT_1002f004 != (int *)0x0) {
    (**(code **)(*DAT_1002f004 + 4))(DAT_1002f004);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000b1c0 at 1000b1c0

void FUN_1000b1c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002eff8,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000b1f0 at 1000b1f0

void FUN_1000b1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002f004 == (int *)0x0) || (DAT_1002f00c == 0)) {
    FUN_100076e0(&PTR_DAT_1002eff8,param_4);
  }
  if (DAT_1002f004 != (int *)0x0) {
    (**(code **)(*DAT_1002f004 + 0x2c))
              (DAT_1002f004,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000b250 at 1000b250

undefined4 FUN_1000b250(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002f020 == (int *)0x0) {
    uVar1 = FUN_100076e0(&PTR_DAT_1002f014,param_3);
  }
  *param_4 = DAT_1002f020;
  if (DAT_1002f020 != (int *)0x0) {
    (**(code **)(*DAT_1002f020 + 4))(DAT_1002f020);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000b2b0 at 1000b2b0

void FUN_1000b2b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009de0(&PTR_DAT_1002f014,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000b2e0 at 1000b2e0

void FUN_1000b2e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002f020 == (int *)0x0) || (DAT_1002f028 == 0)) {
    FUN_100076e0(&PTR_DAT_1002f014,param_4);
  }
  if (DAT_1002f020 != (int *)0x0) {
    (**(code **)(*DAT_1002f020 + 0x2c))
              (DAT_1002f020,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000b340 at 1000b340

undefined4 * __thiscall FUN_1000b340(void *this,byte param_1)

{
  FUN_1000aa50((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b370 at 1000b370

undefined4 * __thiscall FUN_1000b370(void *this,byte param_1)

{
  FUN_1000ae30((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b3a0 at 1000b3a0

undefined4 * __thiscall FUN_1000b3a0(void *this,byte param_1)

{
  FUN_1000b0c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b3d0 at 1000b3d0

void __thiscall FUN_1000b3d0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_10009b40(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_100098e0((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(*this + ((int)param_1 - (int)puVar2 >> 2) * 4));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
    return;
  }
  if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_10009b40(this,1);
  }
  FUN_100098e0((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}



// Function: FUN_1000b450 at 1000b450

void FUN_1000b450(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
  
  puStack_c = &LAB_1001d156;
  local_10 = ExceptionList;
  uStack_444 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_444;
  ExceptionList = &local_10;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = uStack_444;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    FUN_10001400();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      FUN_10001400();
    }
    else {
      pvVar1 = LoadResource(hModule,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        FUN_10001400();
      }
      else {
        DVar2 = SizeofResource(hModule,hResInfo);
        if (DVar2 <= DVar2 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005820(&local_41c,DVar2 + 1);
          local_8 = 1;
          FUN_1000b55d();
          return;
        }
      }
    }
    FreeLibrary(hModule);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_100020c0(&local_41c);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b53e at 1000b53e

undefined * Catch_1000b53e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b54b;
}



// Function: FUN_1000b55d at 1000b55d

void FUN_1000b55d(void)

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
      FUN_10001400();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x418) + iVar1 * 2) = 0;
      FUN_10007cd0((void *)(unaff_EBP - 0x42c),*(LPCWSTR *)(unaff_EBP - 0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(unaff_ESI);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x418) != unaff_EBP - 0x414) {
    FUN_100020c0((undefined4 *)(unaff_EBP - 0x418));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000b5f0;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000b600 at 1000b600

void FUN_1000b600(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000b450(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b660 at 1000b660

undefined4 FUN_1000b660(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d188;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_1000b450(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_1000b6e0 at 1000b6e0

void FUN_1000b6e0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000b450(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b740 at 1000b740

undefined4 FUN_1000b740(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d188;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_1000b450(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_1000b7c0 at 1000b7c0

void FUN_1000b7c0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1001d1e7;
  local_10 = ExceptionList;
  uVar6 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
        FUN_100061d0(pWVar2,param_4[1]);
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
  pHVar3 = DAT_1002ffac;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1002ffac,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10001400();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002040((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10004230(&local_a5c);
        goto LAB_1000ba39;
      }
      FUN_10001550(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001070(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002040((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10004230(&local_a5c);
          goto LAB_1000ba39;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10006380(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10006380(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_1000b740(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_1000b660(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002040((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10004230(&local_a5c);
LAB_1000ba39:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ba60 at 1000ba60

undefined4 * __fastcall FUN_1000ba60(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d218;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10007fa0(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditData>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditData>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditData>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditData>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bae0 at 1000bae0

void FUN_1000bae0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_1000bb00 at 1000bb00

void FUN_1000bb00(int param_1)

{
  FUN_1000c0a0((int *)(param_1 + -4));
  return;
}



// Function: FUN_1000bb10 at 1000bb10

void FUN_1000bb10(int param_1)

{
  FUN_1000bae0(param_1 + -0xc);
  return;
}



// Function: FUN_1000bb20 at 1000bb20

void FUN_1000bb20(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_100225f0,param_2,param_3);
  return;
}



// Function: FUN_1000bb40 at 1000bb40

void FUN_1000bb40(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000bb20(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000bb50 at 1000bb50

void FUN_1000bb50(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000bb20(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000bb60 at 1000bb60

void FUN_1000bb60(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000bb20(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000bb70 at 1000bb70

undefined4 * __thiscall FUN_1000bb70(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d218;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<struct_CAuditData>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100071c0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000bc00 at 1000bc00

void FUN_1000bc00(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1001d277;
  local_10 = ExceptionList;
  uVar6 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
        FUN_100061d0(pWVar2,param_4[1]);
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
  pHVar3 = DAT_1002ffac;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1002ffac,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10001400();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002040((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10004230(&local_a5c);
        goto LAB_1000be63;
      }
      FUN_10001550(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001070(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002040((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10004230(&local_a5c);
          goto LAB_1000be63;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10006380(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10006380(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_1000b6e0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_1000b600(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002040((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10004230(&local_a5c);
LAB_1000be63:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000be80 at 1000be80

undefined4 * __thiscall FUN_1000be80(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d2b3;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditData>::vftable;
  FUN_10007fa0((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditData>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditData>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000bf20 at 1000bf20

int FUN_1000bf20(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_100225f0,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000bf90 at 1000bf90

undefined4 * __thiscall FUN_1000bf90(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d2e3;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditData>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100071c0((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c020 at 1000c020

undefined4 * __fastcall FUN_1000c020(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d308;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10008780(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditModule>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditModule>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditModule>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditModule>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c0a0 at 1000c0a0

LONG FUN_1000c0a0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_1000c0d0 at 1000c0d0

void FUN_1000c0d0(int param_1)

{
  FUN_1000c0a0((int *)(param_1 + -8));
  return;
}



// Function: FUN_1000c0e0 at 1000c0e0

void FUN_1000c0e0(int param_1)

{
  FUN_1000c0a0((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_1000c0f0 at 1000c0f0

void FUN_1000c0f0(int param_1)

{
  FUN_1000bae0(param_1 + -4);
  return;
}



// Function: FUN_1000c100 at 1000c100

void FUN_1000c100(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022730,param_2,param_3);
  return;
}



// Function: FUN_1000c120 at 1000c120

void FUN_1000c120(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c100(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000c130 at 1000c130

void FUN_1000c130(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c100(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000c140 at 1000c140

void FUN_1000c140(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c100(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000c150 at 1000c150

undefined4 * __thiscall FUN_1000c150(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d308;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<struct_CAuditModule>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100072c0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c1e0 at 1000c1e0

undefined4 * __thiscall FUN_1000c1e0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d343;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditModule>::vftable;
  FUN_10008780((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditModule>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditModule>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c280 at 1000c280

void FUN_1000c280(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_1000c2a0 at 1000c2a0

int FUN_1000c2a0(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022730,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000c310 at 1000c310

undefined4 * __thiscall FUN_1000c310(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d373;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditModule>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100072c0((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c3a0 at 1000c3a0

undefined4 * __fastcall FUN_1000c3a0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d398;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10008b90(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditRecord>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditRecord>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditRecord>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditRecord>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c420 at 1000c420

void FUN_1000c420(int param_1)

{
  FUN_1000bae0(param_1 + -8);
  return;
}



// Function: FUN_1000c430 at 1000c430

void FUN_1000c430(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022848,param_2,param_3);
  return;
}



// Function: FUN_1000c450 at 1000c450

void FUN_1000c450(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c430(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000c460 at 1000c460

void FUN_1000c460(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c430(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000c470 at 1000c470

void FUN_1000c470(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c430(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000c480 at 1000c480

undefined4 * __thiscall FUN_1000c480(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d398;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<struct_CAuditRecord>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10007410((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c510 at 1000c510

undefined4 * __thiscall FUN_1000c510(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d3d3;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditRecord>::vftable;
  FUN_10008b90((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditRecord>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditRecord>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c5b0 at 1000c5b0

int FUN_1000c5b0(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022848,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000c620 at 1000c620

undefined4 * __thiscall FUN_1000c620(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d403;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditRecord>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10007410((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c6b0 at 1000c6b0

undefined4 * __fastcall FUN_1000c6b0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d428;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10009410(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c730 at 1000c730

void FUN_1000c730(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022930,param_2,param_3);
  return;
}



// Function: FUN_1000c750 at 1000c750

void FUN_1000c750(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c730(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000c760 at 1000c760

void FUN_1000c760(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c730(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000c770 at 1000c770

void FUN_1000c770(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000c730(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000c780 at 1000c780

undefined4 * __thiscall FUN_1000c780(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d428;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<struct_CAuditAdjustment>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100075d0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c810 at 1000c810

undefined4 * __thiscall FUN_1000c810(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d463;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditAdjustment>::vftable;
  FUN_10009410((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditAdjustment>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditAdjustment>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c8b0 at 1000c8b0

int FUN_1000c8b0(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022930,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000c920 at 1000c920

undefined4 * __thiscall FUN_1000c920(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d493;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditAdjustment>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100075d0((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c9b0 at 1000c9b0

void __fastcall FUN_1000c9b0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d4d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000aa50((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ca30 at 1000ca30

void __fastcall FUN_1000ca30(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d529;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000ae30((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cab0 at 1000cab0

void __fastcall FUN_1000cab0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d579;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000b0c0((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cb30 at 1000cb30

int FUN_1000cb30(int *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001d5f2;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_10009f00(&local_1c);
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
      piVar2 = (int *)FUN_100083a0(local_1c,param_1[2],param_1[3],local_18,0);
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
        piVar2 = (int *)FUN_10006040((int)local_1c,(int *)&PTR_DAT_10021f54,(int *)&DAT_10021f6c,
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



// Function: FUN_1000cc90 at 1000cc90

void __thiscall FUN_1000cc90(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_100079f0(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000ccc0 at 1000ccc0

void __thiscall FUN_1000ccc0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100092f0(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return;
}



// Function: FUN_1000ccf0 at 1000ccf0

void FUN_1000ccf0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000b7c0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000cd00 at 1000cd00

void FUN_1000cd00(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_1000bc00(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000cd10 at 1000cd10

DWORD FUN_1000cd10(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d610;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x50);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000ba60(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000cdb7();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000cdb7();
  return DVar2;
}



// Function: Catch@1000cda4 at 1000cda4

undefined * Catch_1000cda4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000cdb1;
}



// Function: FUN_1000cdb7 at 1000cdb7

DWORD FUN_1000cdb7(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) goto LAB_1000ce43;
  InterlockedIncrement(unaff_EDI + 4);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 5),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_1000cdf4;
  }
  else {
LAB_1000cdf4:
    *(undefined1 *)(unaff_EDI + 0xb) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = FUN_10001fb0((LPVOID *)(unaff_EDI + 0x13),(IID *)&DAT_10021568);
      if (-1 < (int)unaff_ESI) {
        unaff_ESI = 0;
      }
    }
  }
  InterlockedDecrement(unaff_EDI + 4);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_1000ce43;
  }
  (**(code **)(*unaff_EDI + 0x14))(1);
LAB_1000ce43:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_1000ce60 at 1000ce60

int * FUN_1000ce60(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d63b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000be80(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000cf16();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000cf16();
  return piVar1;
}



// Function: Catch@1000cf01 at 1000cf01

undefined * Catch_1000cf01(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000cf0e;
}



// Function: FUN_1000cf16 at 1000cf16

int * FUN_1000cf16(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10002590((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)FUN_10001fb0((LPVOID *)(unaff_ESI + 0x16),(IID *)&DAT_10021568);
      if (((int)unaff_EBX <= (int)unaff_EDI) || (unaff_EDI == unaff_EBX)) {
        unaff_EDI = (int *)(**(code **)*unaff_ESI)();
        if (unaff_EDI == unaff_EBX) goto LAB_1000cf60;
      }
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000cf60:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000cf80 at 1000cf80

DWORD FUN_1000cf80(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d660;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x90);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000c020(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000d02a();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000d02a();
  return DVar2;
}



// Function: Catch@1000d017 at 1000d017

undefined * Catch_1000d017(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d024;
}



// Function: FUN_1000d02a at 1000d02a

DWORD FUN_1000d02a(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) goto LAB_1000d0b6;
  InterlockedIncrement(unaff_EDI + 4);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 5),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_1000d067;
  }
  else {
LAB_1000d067:
    *(undefined1 *)(unaff_EDI + 0xb) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = FUN_10001fe0((LPVOID *)(unaff_EDI + 0x1c),(IID *)&DAT_10021588);
      if (-1 < (int)unaff_ESI) {
        unaff_ESI = 0;
      }
    }
  }
  InterlockedDecrement(unaff_EDI + 4);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_1000d0b6;
  }
  (**(code **)(*unaff_EDI + 0x14))(1);
LAB_1000d0b6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_1000d0d0 at 1000d0d0

int * FUN_1000d0d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d68b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x9c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000c1e0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000d189();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000d189();
  return piVar1;
}



// Function: Catch@1000d174 at 1000d174

undefined * Catch_1000d174(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d181;
}



// Function: FUN_1000d189 at 1000d189

int * FUN_1000d189(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10002590((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)FUN_10001fe0((LPVOID *)(unaff_ESI + 0x1f),(IID *)&DAT_10021588);
      if (((int)unaff_EBX <= (int)unaff_EDI) || (unaff_EDI == unaff_EBX)) {
        unaff_EDI = (int *)(**(code **)*unaff_ESI)();
        if (unaff_EDI == unaff_EBX) goto LAB_1000d1d3;
      }
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000d1d3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000d1f0 at 1000d1f0

DWORD FUN_1000d1f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d6b0;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0xcc);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000c3a0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000d29a();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000d29a();
  return DVar2;
}



// Function: Catch@1000d287 at 1000d287

undefined * Catch_1000d287(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d294;
}



// Function: FUN_1000d29a at 1000d29a

DWORD FUN_1000d29a(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) goto LAB_1000d329;
  InterlockedIncrement(unaff_EDI + 4);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 5),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_1000d2d7;
  }
  else {
LAB_1000d2d7:
    *(undefined1 *)(unaff_EDI + 0xb) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = FUN_10002010((LPVOID *)(unaff_EDI + 0x30),(IID *)&DAT_100215a8);
      if (-1 < (int)unaff_ESI) {
        unaff_ESI = 0;
      }
    }
  }
  InterlockedDecrement(unaff_EDI + 4);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_1000d329;
  }
  (**(code **)(*unaff_EDI + 0x14))(1);
LAB_1000d329:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_1000d340 at 1000d340

int * FUN_1000d340(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d6db;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0xd8);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000c510(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000d3f9();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000d3f9();
  return piVar1;
}



// Function: Catch@1000d3e4 at 1000d3e4

undefined * Catch_1000d3e4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d3f1;
}



// Function: FUN_1000d3f9 at 1000d3f9

int * FUN_1000d3f9(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10002590((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)FUN_10002010((LPVOID *)(unaff_ESI + 0x33),(IID *)&DAT_100215a8);
      if (((int)unaff_EBX <= (int)unaff_EDI) || (unaff_EDI == unaff_EBX)) {
        unaff_EDI = (int *)(**(code **)*unaff_ESI)();
        if (unaff_EDI == unaff_EBX) goto LAB_1000d446;
      }
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000d446:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000d460 at 1000d460

DWORD FUN_1000d460(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d700;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x68);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000c6b0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000d507();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000d507();
  return DVar2;
}



// Function: Catch@1000d4f4 at 1000d4f4

undefined * Catch_1000d4f4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d501;
}



// Function: FUN_1000d507 at 1000d507

DWORD FUN_1000d507(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_1000d578;
  InterlockedIncrement(unaff_ESI + 4);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 5),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000d540;
  }
  else {
LAB_1000d540:
    *(undefined1 *)(unaff_ESI + 0xb) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = 0;
    }
  }
  InterlockedDecrement(unaff_ESI + 4);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_1000d578;
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_1000d578:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000d590 at 1000d590

int * FUN_1000d590(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d72b;
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
    FUN_1000c810(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000d646();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000d646();
  return piVar1;
}



// Function: Catch@1000d631 at 1000d631

undefined * Catch_1000d631(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d63e;
}



// Function: FUN_1000d646 at 1000d646

int * FUN_1000d646(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10002590((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_1000d677;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000d677:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000d690 at 1000d690

void __fastcall FUN_1000d690(undefined4 *param_1)

{
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[3] = IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
               ::vftable;
  param_1[2] = IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
               ::vftable;
  param_1[3] = IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
               ::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = CAuditModules::vftable;
  param_1[1] = CAuditModules::vftable;
  param_1[2] = CAuditModules::vftable;
  param_1[3] = CAuditModules::vftable;
  return;
}



// Function: FUN_1000d750 at 1000d750

void __thiscall FUN_1000d750(void *this,byte param_1)

{
  FUN_1000dc60((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000d760 at 1000d760

undefined4 __fastcall FUN_1000d760(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &TCollectionObject<struct_CAuditModules,&struct__GUID_const_CLSID_AuditModules,&struct__GUID_const_CLSID_AuditModule,struct_IAuditModules,struct_IAuditModule,long,unsigned_short*,&struct__GUID_const_IID_IAuditModules,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                   ::RTTI_Type_Descriptor,&CAuditModules::RTTI_Type_Descriptor,0);
  return 0;
}



// Function: FUN_1000d780 at 1000d780

void __fastcall FUN_1000d780(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d9a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000aa50((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d800 at 1000d800

void __fastcall FUN_1000d800(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000aa50((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d880 at 1000d880

void __fastcall FUN_1000d880(undefined4 *param_1)

{
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[3] = IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
               ::vftable;
  param_1[2] = IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
               ::vftable;
  param_1[3] = IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
               ::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = CAuditRecords::vftable;
  param_1[1] = CAuditRecords::vftable;
  param_1[2] = CAuditRecords::vftable;
  param_1[3] = CAuditRecords::vftable;
  return;
}



// Function: FUN_1000d940 at 1000d940

void __thiscall FUN_1000d940(void *this,byte param_1)

{
  FUN_1000dcf0((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000d950 at 1000d950

undefined4 __fastcall FUN_1000d950(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &TCollectionObject<struct_CAuditRecords,&struct__GUID_const_CLSID_AuditRecords,&struct__GUID_const_CLSID_AuditRecord,struct_IAuditRecords,struct_IAuditRecord,long,unsigned_short*,&struct__GUID_const_IID_IAuditRecords,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                   ::RTTI_Type_Descriptor,&CAuditRecords::RTTI_Type_Descriptor,0);
  return 0;
}



// Function: FUN_1000d970 at 1000d970

void __fastcall FUN_1000d970(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d8a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000ae30((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d9f0 at 1000d9f0

void __fastcall FUN_1000d9f0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d9f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000ae30((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000da70 at 1000da70

void __fastcall FUN_1000da70(undefined4 *param_1)

{
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[3] = IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
               ::vftable;
  param_1[2] = IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
               ::vftable;
  param_1[3] = IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
               ::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = CAuditAdjustments::vftable;
  param_1[1] = CAuditAdjustments::vftable;
  param_1[2] = CAuditAdjustments::vftable;
  param_1[3] = CAuditAdjustments::vftable;
  return;
}



// Function: FUN_1000db30 at 1000db30

void __thiscall FUN_1000db30(void *this,byte param_1)

{
  FUN_1000dd80((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000db40 at 1000db40

undefined4 __fastcall FUN_1000db40(undefined4 param_1)

{
  __RTDynamicCast(param_1,0,
                  &TCollectionObject<struct_CAuditAdjustments,&struct__GUID_const_CLSID_AuditAdjustments,&struct__GUID_const_CLSID_AuditAdjustment,struct_IAuditAdjustments,struct_IAuditAdjustment,long,unsigned_short*,&struct__GUID_const_IID_IAuditAdjustments,&struct__GUID_const_LIBID_AUDITDATAOMLib,101>
                   ::RTTI_Type_Descriptor,&CAuditAdjustments::RTTI_Type_Descriptor,0);
  return 0;
}



// Function: FUN_1000db60 at 1000db60

void __fastcall FUN_1000db60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d951;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000b0c0((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000dbe0 at 1000dbe0

void __fastcall FUN_1000dbe0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001da59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000b0c0((undefined4 *)(param_1 + 8));
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000dc60 at 1000dc60

void * __thiscall FUN_1000dc60(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d9a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000aa50((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000dcf0 at 1000dcf0

void * __thiscall FUN_1000dcf0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d8a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000ae30((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000dd80 at 1000dd80

void * __thiscall FUN_1000dd80(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d951;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000b0c0((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000de10 at 1000de10

void __thiscall FUN_1000de10(void *this,byte param_1)

{
  FUN_1000df30((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000de20 at 1000de20

void FUN_1000de20(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x20) + 4))(*(int **)(param_1 + 0x20));
  return;
}



// Function: FUN_1000de40 at 1000de40

void FUN_1000de40(int param_1)

{
  FUN_1000de20(param_1 + -0xc);
  return;
}



// Function: FUN_1000de50 at 1000de50

void FUN_1000de50(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ded0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000de60 at 1000de60

void __thiscall FUN_1000de60(void *this,byte param_1)

{
  FUN_1000dfc0((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000de70 at 1000de70

void FUN_1000de70(int param_1)

{
  FUN_1000de20(param_1 + -4);
  return;
}



// Function: FUN_1000de80 at 1000de80

void FUN_1000de80(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ded0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000de90 at 1000de90

void FUN_1000de90(int param_1)

{
  FUN_1000deb0(param_1 + -4);
  return;
}



// Function: FUN_1000dea0 at 1000dea0

void __thiscall FUN_1000dea0(void *this,byte param_1)

{
  FUN_1000e050((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000deb0 at 1000deb0

void FUN_1000deb0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x20) + 8))(*(int **)(param_1 + 0x20));
  return;
}



// Function: FUN_1000ded0 at 1000ded0

void FUN_1000ded0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x20))(*(undefined4 **)(param_1 + 0x20),param_2,param_3);
  return;
}



// Function: FUN_1000def0 at 1000def0

void FUN_1000def0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ded0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000df00 at 1000df00

void FUN_1000df00(int param_1)

{
  FUN_1000deb0(param_1 + -8);
  return;
}



// Function: FUN_1000df10 at 1000df10

void FUN_1000df10(int param_1)

{
  FUN_1000deb0(param_1 + -0xc);
  return;
}



// Function: FUN_1000df20 at 1000df20

void FUN_1000df20(int param_1)

{
  FUN_1000de20(param_1 + -8);
  return;
}



// Function: FUN_1000df30 at 1000df30

void * __thiscall FUN_1000df30(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000aa50((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000dfc0 at 1000dfc0

void * __thiscall FUN_1000dfc0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d9f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000ae30((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000e050 at 1000e050

void * __thiscall FUN_1000e050(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001da59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000b0c0((undefined4 *)((int)this + 8));
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x3c) != '\0') {
    *(undefined1 *)((int)this + 0x3c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000e0e0 at 1000e0e0

void __thiscall FUN_1000e0e0(void *this,char *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001da80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((char *)0xccccccc < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x14) < param_1) {
    puVar3 = (undefined4 *)FUN_10003080(param_1);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_1000cc90(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined4 **)((int)this + 8) = puVar3 + (int)param_1 * 5;
    *(undefined4 **)((int)this + 4) = puVar3 + ((iVar2 - (int)pvVar1) / 0x14) * 5;
    *(undefined4 **)this = puVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000e1c3 at 1000e1c3

void Catch_1000e1c3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000e1e0 at 1000e1e0

undefined4 * __thiscall FUN_1000e1e0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001daab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  FUN_1000a220((undefined2 *)((int)this + 0x10),(int *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000e270 at 1000e270

void __cdecl FUN_1000e270(int *param_1)

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
  puStack_c = &LAB_1001dad8;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  FUN_1000a220(local_30,param_1,0,0xffffffff);
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
  uVar3 = FUN_10002c30(local_30,0,local_20,(ushort *)L"TRUE",4);
  if (uVar3 != 0) {
    uVar3 = FUN_10002c30(local_30,0,local_20,(ushort *)L"FALSE",5);
    if (uVar3 == 0) {
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
      goto LAB_1000e3c5;
    }
    uVar3 = FUN_10002c30(local_30,0,local_20,(ushort *)&DAT_10022cc0,1);
    if (uVar3 != 0) {
      FUN_10002c30(local_30,0,local_20,(ushort *)&DAT_10022cbc,1);
      local_8 = 0xffffffff;
      FUN_10005900(local_30);
      goto LAB_1000e3c5;
    }
  }
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (ushort ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
LAB_1000e3c5:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e3f0 at 1000e3f0

undefined1 * __thiscall FUN_1000e3f0(void *this,undefined1 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001db19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_1000a130(param_1,(int *)this,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e460 at 1000e460

undefined4 * __thiscall FUN_1000e460(void *this,undefined4 *param_1)

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



// Function: FUN_1000e4e0 at 1000e4e0

void FUN_1000e4e0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001db50;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*(int *)(param_1 + 0x7c) != 0) {
    piVar4 = (int *)(param_1 + 0x6c);
    if (7 < *(uint *)(param_1 + 0x80)) {
      piVar4 = (int *)*piVar4;
    }
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    local_1c = 7;
    local_20 = 0;
    piVar3 = piVar4;
    do {
      iVar1 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 2);
    } while ((short)iVar1 != 0);
    FUN_1000a420(local_30,piVar4,(int)piVar3 - ((int)piVar4 + 2) >> 1);
    local_8 = 0;
    piVar4 = FUN_1001ac80(&local_34,local_30);
    local_8._0_1_ = 1;
    if (*piVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = Ordinal_149(*piVar4,uVar2);
      uVar5 = Ordinal_150(*piVar4,uVar5);
    }
    *param_2 = uVar5;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(local_34);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e5f0 at 1000e5f0

void __fastcall FUN_1000e5f0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_38;
  int local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001db98;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(char *)(param_1 + 0xbc) == '\0') || (*(char *)(param_1 + 200) != '\0')) goto LAB_1000e7d5;
  iVar3 = FUN_1001ad00(*(int *)(param_1 + 0xc4));
  FUN_1001ae70((undefined2 *)local_30,iVar3);
  local_8 = 0;
  FUN_1001ac80(&local_34,(undefined4 *)(param_1 + 0x30));
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = Ordinal_314(DAT_1002ff1c,local_34,0x400,0,uVar2);
  if (iVar3 == 1) {
LAB_1000e747:
    FUN_100092f0(local_30,(int *)L"CEC0",4);
  }
  else {
    iVar3 = Ordinal_314(DAT_1002ff20,local_34,0x400,0);
    if (iVar3 == 1) goto LAB_1000e747;
    iVar3 = Ordinal_314(DAT_1002ff24,local_34,0x400,0);
    if (iVar3 == 1) {
      FUN_1000ccc0(local_30,(int *)L"E510");
    }
    else {
      bVar1 = FUN_10008cd0(&DAT_1002ff28,&local_34);
      if (!bVar1) {
        bVar1 = FUN_10008cd0(&DAT_1002ff2c,&local_34);
        if (!bVar1) {
          bVar1 = FUN_10008cd0(&DAT_1002ff30,&local_34);
          if (!bVar1) {
            bVar1 = FUN_10008cd0(&DAT_1002ff34,&local_34);
            if (bVar1) {
              FUN_1000ccc0(local_30,(int *)L"DAF0");
            }
            else {
              FUN_1000ccc0(local_30,(int *)L"0000");
            }
            goto LAB_1000e756;
          }
        }
      }
      FUN_1000ccc0(local_30,(int *)L"2901");
    }
  }
LAB_1000e756:
  piVar4 = FUN_1001ac80(&local_38,local_30);
  local_8._0_1_ = 2;
  if (*(int *)(param_1 + 0xc4) != *piVar4) {
    Ordinal_6(*(int *)(param_1 + 0xc4));
    *(int *)(param_1 + 0xc4) = *piVar4;
    *piVar4 = 0;
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_38);
  *(undefined1 *)(param_1 + 200) = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_34);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
LAB_1000e7d5:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e800 at 1000e800

void FUN_1000e800(int param_1)

{
  FUN_1000bc00((int *)&DAT_1002ff38,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000e820 at 1000e820

void FUN_1000e820(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000cd10(0,param_2,param_3);
    return;
  }
  FUN_1000ce60(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000e850 at 1000e850

void FUN_1000e850(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000cf80(0,param_2,param_3);
    return;
  }
  FUN_1000d0d0(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000e880 at 1000e880

void FUN_1000e880(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000d1f0(0,param_2,param_3);
    return;
  }
  FUN_1000d340(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000e8b0 at 1000e8b0

void FUN_1000e8b0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000d460(0,param_2,param_3);
    return;
  }
  FUN_1000d590(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000e8e0 at 1000e8e0

undefined4 * __fastcall FUN_1000e8e0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dbc8;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000d690(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditModules>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e960 at 1000e960

LONG FUN_1000e960(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x20));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 8) + 0x28))(1);
  }
  return LVar1;
}



// Function: FUN_1000e9a0 at 1000e9a0

void FUN_1000e9a0(int param_1)

{
  FUN_1000e960(param_1 + -4);
  return;
}



// Function: FUN_1000e9b0 at 1000e9b0

void __thiscall FUN_1000e9b0(void *this,byte param_1)

{
  FUN_1000f390((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000e9c0 at 1000e9c0

void FUN_1000e9c0(int param_1)

{
  FUN_1000e960(param_1 + -0xc);
  return;
}



// Function: FUN_1000e9d0 at 1000e9d0

void FUN_1000e9d0(int param_1)

{
  FUN_1000f0a0(param_1 + -8);
  return;
}



// Function: FUN_1000e9e0 at 1000e9e0

void FUN_1000e9e0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022da0,param_2,param_3);
  return;
}



// Function: FUN_1000ea00 at 1000ea00

void FUN_1000ea00(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000e9e0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000ea10 at 1000ea10

void FUN_1000ea10(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000e9e0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000ea20 at 1000ea20

void FUN_1000ea20(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000e9e0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000ea30 at 1000ea30

void __fastcall FUN_1000ea30(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dc29;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditModules>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditModules>::vftable;
  local_8 = 0;
  param_1[8] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 2;
  FUN_1000aa50(param_1 + 2);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0xf) != '\0') {
    *(undefined1 *)(param_1 + 0xf) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000eae0 at 1000eae0

undefined4 * __thiscall FUN_1000eae0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dc63;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditModules>::vftable;
  FUN_1000d690((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditModules>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditModules>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditModules>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditModules>::vftable;
  *(undefined4 *)((int)this + 0x2c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000eb80 at 1000eb80

LONG FUN_1000eb80(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_1000ebb0 at 1000ebb0

int FUN_1000ebb0(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022da0,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000ec20 at 1000ec20

void __fastcall FUN_1000ec20(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dcc4;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<struct_CAuditModules>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 3;
  FUN_1000aa50(param_1 + 5);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x12) != '\0') {
    *(undefined1 *)(param_1 + 0x12) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ecc0 at 1000ecc0

undefined4 * __fastcall FUN_1000ecc0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dce8;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000d880(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditRecords>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ed40 at 1000ed40

void FUN_1000ed40(int param_1)

{
  FUN_1000e960(param_1 + -8);
  return;
}



// Function: FUN_1000ed50 at 1000ed50

void __thiscall FUN_1000ed50(void *this,byte param_1)

{
  FUN_1000f3f0((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000ed60 at 1000ed60

void FUN_1000ed60(int param_1)

{
  FUN_1000f0a0(param_1 + -4);
  return;
}



// Function: FUN_1000ed70 at 1000ed70

void FUN_1000ed70(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022e88,param_2,param_3);
  return;
}



// Function: FUN_1000ed90 at 1000ed90

void FUN_1000ed90(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000ed70(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000eda0 at 1000eda0

void FUN_1000eda0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000ed70(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000edb0 at 1000edb0

void FUN_1000edb0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000ed70(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000edc0 at 1000edc0

void __fastcall FUN_1000edc0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dd49;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditRecords>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditRecords>::vftable;
  local_8 = 0;
  param_1[8] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 2;
  FUN_1000ae30(param_1 + 2);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0xf) != '\0') {
    *(undefined1 *)(param_1 + 0xf) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ee70 at 1000ee70

undefined4 * __thiscall FUN_1000ee70(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dd83;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditRecords>::vftable;
  FUN_1000d880((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditRecords>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditRecords>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditRecords>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditRecords>::vftable;
  *(undefined4 *)((int)this + 0x2c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ef10 at 1000ef10

int FUN_1000ef10(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022e88,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000ef80 at 1000ef80

void __fastcall FUN_1000ef80(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dde4;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<struct_CAuditRecords>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 3;
  FUN_1000ae30(param_1 + 5);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x12) != '\0') {
    *(undefined1 *)(param_1 + 0x12) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f020 at 1000f020

undefined4 * __fastcall FUN_1000f020(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001de08;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000da70(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f0a0 at 1000f0a0

void FUN_1000f0a0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x20));
  return;
}



// Function: FUN_1000f0c0 at 1000f0c0

void FUN_1000f0c0(int param_1)

{
  FUN_1000f0a0(param_1 + -0xc);
  return;
}



// Function: FUN_1000f0d0 at 1000f0d0

void __thiscall FUN_1000f0d0(void *this,byte param_1)

{
  FUN_1000f450((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_1000f0e0 at 1000f0e0

void FUN_1000f0e0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10006040(param_1,(int *)&PTR_DAT_10022f70,param_2,param_3);
  return;
}



// Function: FUN_1000f100 at 1000f100

void FUN_1000f100(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000f0e0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000f110 at 1000f110

void FUN_1000f110(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000f0e0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000f120 at 1000f120

void FUN_1000f120(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_1000f0e0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000f130 at 1000f130

void __fastcall FUN_1000f130(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001de69;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[1] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[2] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  param_1[3] = ATL::CComObject<struct_CAuditAdjustments>::vftable;
  local_8 = 0;
  param_1[8] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 2;
  FUN_1000b0c0(param_1 + 2);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0xf) != '\0') {
    *(undefined1 *)(param_1 + 0xf) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f1e0 at 1000f1e0

undefined4 * __thiscall FUN_1000f1e0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dea3;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<struct_CAuditAdjustments>::vftable;
  FUN_1000da70((undefined4 *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = ATL::CComContainedObject<struct_CAuditAdjustments>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<struct_CAuditAdjustments>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<struct_CAuditAdjustments>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<struct_CAuditAdjustments>::vftable;
  *(undefined4 *)((int)this + 0x2c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1002fdd8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000f280 at 1000f280

int FUN_1000f280(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_10006040((int)(param_1 + 3),(int *)&PTR_DAT_10022f70,param_2,param_3);
  return iVar1;
}



// Function: FUN_1000f2f0 at 1000f2f0

void __fastcall FUN_1000f2f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001df04;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<struct_CAuditAdjustments>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002fdd8 + 8))(uVar1);
  local_8 = 3;
  FUN_1000b0c0(param_1 + 5);
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x12) != '\0') {
    *(undefined1 *)(param_1 + 0x12) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f390 at 1000f390

undefined4 * __thiscall FUN_1000f390(void *this,byte param_1)

{
  FUN_1000ea30((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f3c0 at 1000f3c0

undefined4 * __thiscall FUN_1000f3c0(void *this,byte param_1)

{
  FUN_1000ec20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f3f0 at 1000f3f0

undefined4 * __thiscall FUN_1000f3f0(void *this,byte param_1)

{
  FUN_1000edc0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f420 at 1000f420

undefined4 * __thiscall FUN_1000f420(void *this,byte param_1)

{
  FUN_1000ef80((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f450 at 1000f450

undefined4 * __thiscall FUN_1000f450(void *this,byte param_1)

{
  FUN_1000f130((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f480 at 1000f480

undefined4 * __thiscall FUN_1000f480(void *this,byte param_1)

{
  FUN_1000f2f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f4b0 at 1000f4b0

void __thiscall FUN_1000f4b0(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  char *pcVar3;
  void *extraout_ECX;
  char *pcVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = (*(int *)((int)this + 4) - iVar1) / 0x14;
  if (0xcccccccU - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  pcVar4 = (char *)(uVar2 + param_1);
  pcVar3 = (char *)((*(int *)((int)this + 8) - iVar1) / 0x14);
  if (pcVar3 < pcVar4) {
    if ((char *)(0xccccccc - ((uint)pcVar3 >> 1)) < pcVar3) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = pcVar3 + ((uint)pcVar3 >> 1);
    }
    if (pcVar3 < pcVar4) {
      pcVar3 = pcVar4;
    }
    FUN_1000e0e0(this,pcVar3);
  }
  return;
}



// Function: FUN_1000f530 at 1000f530

undefined2 * __cdecl FUN_1000f530(undefined2 *param_1,char param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001df39;
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
  FUN_1000a420(param_1,(int *)pwVar3,(int)pwVar2 - (int)(pwVar3 + 1) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f5c0 at 1000f5c0

undefined2 * __cdecl FUN_1000f5c0(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 local_24 [4];
  int *local_1c;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001df89;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_8 = 1;
  local_24[0] = 0;
  iVar1 = Ordinal_10(local_24,&stack0x00000008,DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    local_24[0] = 10;
    local_1c = (int *)iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(iVar1);
  }
  local_8._0_1_ = 2;
  FUN_1001ac50(8,(int)local_24,0,0x409);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  piVar2 = local_1c;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(param_1,local_1c,(int)piVar2 - ((int)local_1c + 2) >> 1);
  local_14 = 1;
  local_8._0_1_ = 1;
  Ordinal_9(local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(&stack0x00000008);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f6b0 at 1000f6b0

void __cdecl FUN_1000f6b0(int *param_1,float *param_2,type_info *param_3)

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
    bVar1 = type_info::operator==(param_3,(type_info *)(&PTR_RTTI_Type_Descriptor_1002f86c)[uVar5]);
    if (bVar1) {
      uVar6 = uVar5;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  switch(uVar6) {
  case 0:
    FUN_1000a220(param_2,param_1,0,0xffffffff);
    return;
  case 1:
    uVar2 = FUN_1000e270(param_1);
    *(undefined1 *)param_2 = uVar2;
    return;
  case 2:
    fVar4 = (float)FUN_1000a520(param_1);
    *param_2 = fVar4;
    break;
  case 3:
    fVar4 = (float)FUN_1000a680(param_1);
    *param_2 = fVar4;
    return;
  case 4:
    fVar7 = FUN_1000a7e0(param_1);
    *param_2 = (float)fVar7;
    return;
  case 5:
    if (7 < (uint)param_1[5]) {
      param_1 = (int *)*param_1;
    }
    iVar3 = Ordinal_9(param_2);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010a0(iVar3);
    }
    *(undefined2 *)param_2 = 8;
    fVar4 = (float)Ordinal_2(param_1);
    param_2[2] = fVar4;
    if ((fVar4 == 0.0) && (param_1 != (int *)0x0)) {
      *(undefined2 *)param_2 = 10;
      param_2[2] = -6.42868e-40;
                    /* WARNING: Subroutine does not return */
      FUN_100010a0(0x8007000e);
    }
  }
  return;
}



// Function: FUN_1000f7d0 at 1000f7d0

undefined2 * __cdecl FUN_1000f7d0(undefined2 *param_1,char *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f530(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f830 at 1000f830

undefined2 * __cdecl FUN_1000f830(undefined2 *param_1,undefined4 param_2)

{
  undefined2 local_30 [4];
  int local_28;
  uint uStack_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dfd1;
  local_10 = ExceptionList;
  uStack_20 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = 0;
  local_28 = Ordinal_10(local_30,param_2);
  if (local_28 < 0) {
    local_30[0] = 10;
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(local_28);
  }
  local_8 = 0;
  FUN_1000f5c0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f8d0 at 1000f8d0

void __thiscall FUN_1000f8d0(void *this,undefined2 *param_1)

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
  puStack_c = &LAB_1001e021;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_1000a420(&local_30,(int *)puVar3,(int)puVar1 - (int)puVar2 >> 1);
    local_8 = 1;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000e460(param_1,&local_30);
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
    FUN_1000a420(&local_30,(int *)puVar3,(int)puVar2 - (int)puVar1 >> 1);
    local_8 = 2;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000e460(param_1,&local_30);
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
    FUN_1000e460(param_1,&local_30);
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



// Function: FUN_1000fad0 at 1000fad0

void FUN_1000fad0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e058;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1001adc0((undefined2 *)local_30,param_2);
  local_8 = 0;
  FUN_1000e460((void *)(param_1 + 0x6c),puVar1);
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



// Function: FUN_1000fb70 at 1000fb70

undefined4 FUN_1000fb70(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420((void *)(param_1 + 0x60),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000fbb0 at 1000fbb0

undefined4 FUN_1000fbb0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420((void *)(param_1 + 0x7c),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000fbf0 at 1000fbf0

undefined4 FUN_1000fbf0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420((void *)(param_1 + 0x98),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000fc30 at 1000fc30

int FUN_1000fc30(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_1000e5f0(param_1 + -8);
  iVar1 = *(int *)(param_1 + 0xbc);
  if (iVar1 == 0) {
    *param_2 = 0;
    return iVar1;
  }
  uVar2 = Ordinal_149(iVar1);
  uVar2 = Ordinal_150(*(undefined4 *)(param_1 + 0xbc),uVar2);
  *param_2 = uVar2;
  return 0;
}



// Function: FUN_1000fc80 at 1000fc80

undefined4 FUN_1000fc80(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420((void *)(param_1 + 0x28),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000fcc0 at 1000fcc0

undefined4 FUN_1000fcc0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420((void *)(param_1 + 0x44),param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  return 0;
}



// Function: FUN_1000fd00 at 1000fd00

undefined2 * __thiscall FUN_1000fd00(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f8d0((void *)((int)this + 4),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fd60 at 1000fd60

DWORD FUN_1000fd60(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e080;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000e8e0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000fe07();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000fe07();
  return DVar2;
}



// Function: Catch@1000fdf4 at 1000fdf4

undefined * Catch_1000fdf4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000fe01;
}



// Function: FUN_1000fe07 at 1000fe07

DWORD FUN_1000fe07(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_EDI == (undefined4 *)0x0) goto LAB_1000fe79;
  InterlockedIncrement(unaff_EDI + 8);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 9),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_1000fe40;
  }
  else {
LAB_1000fe40:
    *(undefined1 *)(unaff_EDI + 0xf) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = 0;
    }
  }
  InterlockedDecrement(unaff_EDI + 8);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_1000fe79;
  }
  (**(code **)(unaff_EDI[2] + 0x28))(1);
LAB_1000fe79:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_1000fe90 at 1000fe90

int * FUN_1000fe90(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0ab;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000eae0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000ff46();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000ff46();
  return piVar1;
}



// Function: Catch@1000ff31 at 1000ff31

undefined * Catch_1000ff31(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ff3e;
}



// Function: FUN_1000ff46 at 1000ff46

int * FUN_1000ff46(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_100028b0((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_1000ff77;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000ff77:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000ff90 at 1000ff90

DWORD FUN_1000ff90(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0d0;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000ecc0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10010037();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10010037();
  return DVar2;
}



// Function: Catch@10010024 at 10010024

undefined * Catch_10010024(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10010031;
}



// Function: FUN_10010037 at 10010037

DWORD FUN_10010037(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_EDI == (undefined4 *)0x0) goto LAB_100100a9;
  InterlockedIncrement(unaff_EDI + 8);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 9),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_10010070;
  }
  else {
LAB_10010070:
    *(undefined1 *)(unaff_EDI + 0xf) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = 0;
    }
  }
  InterlockedDecrement(unaff_EDI + 8);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_100100a9;
  }
  (**(code **)(unaff_EDI[2] + 0x28))(1);
LAB_100100a9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_100100c0 at 100100c0

int * FUN_100100c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e0fb;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000ee70(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10010176();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10010176();
  return piVar1;
}



// Function: Catch@10010161 at 10010161

undefined * Catch_10010161(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001016e;
}



// Function: FUN_10010176 at 10010176

int * FUN_10010176(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_100028b0((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_100101a7;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_100101a7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100101c0 at 100101c0

DWORD FUN_100101c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e120;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000f020(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10010267();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10010267();
  return DVar2;
}



// Function: Catch@10010254 at 10010254

undefined * Catch_10010254(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10010261;
}



// Function: FUN_10010267 at 10010267

DWORD FUN_10010267(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_EDI == (undefined4 *)0x0) goto LAB_100102d9;
  InterlockedIncrement(unaff_EDI + 8);
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 9),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_100102a0;
  }
  else {
LAB_100102a0:
    *(undefined1 *)(unaff_EDI + 0xf) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = 0;
    }
  }
  InterlockedDecrement(unaff_EDI + 8);
  if (unaff_ESI == 0) {
    unaff_ESI = (**(code **)*unaff_EDI)();
    if (unaff_ESI == 0) goto LAB_100102d9;
  }
  (**(code **)(unaff_EDI[2] + 0x28))(1);
LAB_100102d9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_100102f0 at 100102f0

int * FUN_100102f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e14b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_1000f1e0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_100103a6();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_100103a6();
  return piVar1;
}



// Function: Catch@10010391 at 10010391

undefined * Catch_10010391(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001039e;
}



// Function: FUN_100103a6 at 100103a6

int * FUN_100103a6(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_100028b0((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_100103d7;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_100103d7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100103f0 at 100103f0

void __thiscall FUN_100103f0(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditData,void*>::
                                  RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_100104a0 at 100104a0

void __thiscall FUN_100104a0(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_10010550 at 10010550

void __thiscall FUN_10010550(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditModule,void*>::
                                  RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_10010600 at 10010600

void __thiscall FUN_10010600(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_100106b0 at 100106b0

void __thiscall FUN_100106b0(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditRecord,void*>::
                                  RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_10010760 at 10010760

void __thiscall FUN_10010760(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_10010810 at 10010810

void __thiscall FUN_10010810(void *this,int *param_1,int param_2)

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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar3 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar3 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                                  RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0);
  if (pTVar3 != (TypeDescriptor *)0x0) {
    FUN_1000f6b0(param_1,(float *)(*(int *)(param_2 + 4) + iVar2),(type_info *)pTVar3);
  }
  return;
}



// Function: FUN_100108c0 at 100108c0

void __thiscall FUN_100108c0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000f4b0(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10005490((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(*this + (((int)param_1 - (int)puVar2) / 0x14) * 0x14));
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x14;
    return;
  }
  if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_1000f4b0(this,1);
  }
  FUN_10007980((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x14;
  return;
}



// Function: FUN_10010950 at 10010950

void FUN_10010950(undefined4 param_1,undefined4 param_2)

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
  
  puStack_c = &LAB_1001e188;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8 = 0;
  local_40 = param_1;
  local_3c = 0;
  local_38 = param_2;
  FUN_1000a420(local_34,(int *)&DAT_10021a8c,0);
  local_18 = 0;
  local_8 = 1;
  local_6c = local_3c;
  local_70 = local_40;
  local_74 = CComErrorHandlerException::vftable;
  local_68 = local_38;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  FUN_1000a220(local_64,(int *)local_34,0,0xffffffff);
  local_48 = local_18;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_74,(ThrowInfo *)&DAT_10029740);
}



// Function: FUN_10010a20 at 10010a20

void __thiscall FUN_10010a20(void *this,undefined2 *param_1,undefined4 param_2)

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
  puStack_c = &LAB_1001e1d1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)(**(code **)((int)this + 0x1c))(local_30,param_2,local_14);
  local_8 = 1;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_1000e460(param_1,puVar1);
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



// Function: FUN_10010ad0 at 10010ad0

undefined2 * __thiscall FUN_10010ad0(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f8d0((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10010b30 at 10010b30

void FUN_10010b30(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000fd60(0,param_2,param_3);
    return;
  }
  FUN_1000fe90(param_1,param_2,param_3);
  return;
}



// Function: FUN_10010b60 at 10010b60

void FUN_10010b60(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000ff90(0,param_2,param_3);
    return;
  }
  FUN_100100c0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10010b90 at 10010b90

void FUN_10010b90(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_100101c0(0,param_2,param_3);
    return;
  }
  FUN_100102f0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10010bc0 at 10010bc0

undefined2 * __thiscall
FUN_10010bc0(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditData,void*>::
                                  RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0,uVar3,
                          uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10010d90 at 10010d90

undefined2 * __thiscall
FUN_10010d90(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditData,void*>::
                                  RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0,uVar6,
                          uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10010ff0 at 10010ff0

void FUN_10010ff0(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_100103f0(local_38,&local_30,(int)param_2);
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



// Function: FUN_10011170 at 10011170

void FUN_10011170(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_CAuditData,void*>::RTTI_Type_Descriptor,
                          &CAuditData::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_10011410 at 10011410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10011410(undefined4 param_1)

{
  uint uVar1;
  wchar_t *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  TypeDescriptor *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e2ce;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_1002fe2c & 1) == 0) {
    DAT_1002fe2c = DAT_1002fe2c | 1;
    local_8 = 0;
    DAT_1002fe1c = (undefined4 *)0x0;
    DAT_1002fe20 = (undefined4 *)0x0;
    _DAT_1002fe24 = 0;
    _atexit((_func_4879 *)&LAB_1001fbe0);
  }
  local_8 = 0xffffffff;
  if (DAT_1002fe1c != DAT_1002fe20) {
    DAT_1002fe20 = (undefined4 *)FUN_10005450(DAT_1002fe20,DAT_1002fe20,DAT_1002fe1c);
  }
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditModules::RTTI_Type_Descriptor,0,uVar1);
  local_24 = L"AuditModules";
  local_20 = 8;
  local_1c = 3;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe1c,&local_24);
  local_24 = (wchar_t *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe1c,&local_24);
  ExceptionList = local_10;
  return DAT_1002fe1c;
}



// Function: FUN_10011510 at 10011510

undefined2 * __thiscall
FUN_10011510(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar3,uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_100116e0 at 100116e0

undefined2 * __thiscall
FUN_100116e0(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar6,uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10011940 at 10011940

void FUN_10011940(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_100104a0(local_38,&local_30,(int)param_2);
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



// Function: FUN_10011ac0 at 10011ac0

void FUN_10011ac0(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                           ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_10011d60 at 10011d60

undefined2 * __thiscall
FUN_10011d60(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditModule,void*>::
                                  RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0,uVar3,
                          uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10011f30 at 10011f30

undefined2 * __thiscall
FUN_10011f30(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditModule,void*>::
                                  RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0,uVar6,
                          uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10012190 at 10012190

void FUN_10012190(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_10010550(local_38,&local_30,(int)param_2);
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



// Function: FUN_10012310 at 10012310

void FUN_10012310(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_CAuditModule,void*>::RTTI_Type_Descriptor,
                          &CAuditModule::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_100125b0 at 100125b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_100125b0(undefined4 param_1)

{
  uint uVar1;
  wchar_t *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  TypeDescriptor *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e2fe;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_1002fe40 & 1) == 0) {
    DAT_1002fe40 = DAT_1002fe40 | 1;
    local_8 = 0;
    DAT_1002fe30 = (undefined4 *)0x0;
    DAT_1002fe34 = (undefined4 *)0x0;
    _DAT_1002fe38 = 0;
    _atexit((_func_4879 *)&LAB_1001fb90);
  }
  local_8 = 0xffffffff;
  if (DAT_1002fe30 != DAT_1002fe34) {
    DAT_1002fe34 = (undefined4 *)FUN_10005450(DAT_1002fe34,DAT_1002fe34,DAT_1002fe30);
  }
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditRecords::RTTI_Type_Descriptor,0,uVar1);
  local_24 = L"AuditRecords";
  local_20 = 8;
  local_1c = 3;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe30,&local_24);
  local_24 = (wchar_t *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe30,&local_24);
  ExceptionList = local_10;
  return DAT_1002fe30;
}



// Function: FUN_100126b0 at 100126b0

undefined2 * __thiscall
FUN_100126b0(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar3,uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10012880 at 10012880

undefined2 * __thiscall
FUN_10012880(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar6,uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10012ae0 at 10012ae0

void FUN_10012ae0(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_10010600(local_38,&local_30,(int)param_2);
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



// Function: FUN_10012c60 at 10012c60

void FUN_10012c60(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                           ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_10012f00 at 10012f00

undefined2 * __thiscall
FUN_10012f00(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditRecord,void*>::
                                  RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0,uVar3,
                          uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_100130d0 at 100130d0

undefined2 * __thiscall
FUN_100130d0(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditRecord,void*>::
                                  RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0,uVar6,
                          uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10013330 at 10013330

void FUN_10013330(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_100106b0(local_38,&local_30,(int)param_2);
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



// Function: FUN_100134b0 at 100134b0

void FUN_100134b0(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_CAuditRecord,void*>::RTTI_Type_Descriptor,
                          &CAuditRecord::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_10013750 at 10013750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10013750(undefined4 param_1)

{
  uint uVar1;
  wchar_t *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  TypeDescriptor *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001e46e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_1002fe54 & 1) == 0) {
    DAT_1002fe54 = DAT_1002fe54 | 1;
    local_8 = 0;
    DAT_1002fe44 = (undefined4 *)0x0;
    DAT_1002fe48 = (undefined4 *)0x0;
    _DAT_1002fe4c = 0;
    _atexit((_func_4879 *)&LAB_1001fb40);
  }
  local_8 = 0xffffffff;
  if (DAT_1002fe44 != DAT_1002fe48) {
    DAT_1002fe48 = (undefined4 *)FUN_10005450(DAT_1002fe48,DAT_1002fe48,DAT_1002fe44);
  }
  __RTDynamicCast(param_1,0,
                  &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                   ::RTTI_Type_Descriptor,&CAuditAdjustments::RTTI_Type_Descriptor,0,uVar1);
  local_24 = L"AuditAdjustments";
  local_20 = 8;
  local_1c = 3;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe44,&local_24);
  local_24 = (wchar_t *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = &TypeDescriptor_1002dad8;
  local_14 = 0;
  FUN_100108c0(&DAT_1002fe44,&local_24);
  ExceptionList = local_10;
  return DAT_1002fe44;
}



// Function: FUN_10013850 at 10013850

undefined2 * __thiscall
FUN_10013850(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar3,uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10013a20 at 10013a20

undefined2 * __thiscall
FUN_10013a20(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,uVar6,uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_10013c80 at 10013c80

void FUN_10013c80(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_10010760(local_38,&local_30,(int)param_2);
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



// Function: FUN_10013e00 at 10013e00

void FUN_10013e00(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                           ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_100140a0 at 100140a0

undefined2 * __thiscall
FUN_100140a0(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e29e;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b4 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                                  RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0,
                          uVar3,uVar1);
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  iVar2 = (**(code **)**(undefined4 **)(iVar2 + *(int *)(param_2 + 4)))
                    (*(undefined4 **)(iVar2 + *(int *)(param_2 + 4)),&DAT_10021904,&local_14);
  if (-1 < iVar2) {
    param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
    local_8._0_1_ = 9;
    (**(code **)(*local_14 + 0x1c))(local_14,&param_2);
    FUN_100051d0((int *)&local_b4,(ushort *)param_2);
    local_8._0_1_ = 8;
    Ordinal_6(param_2);
  }
  FUN_1000fd00(&local_b4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10014270 at 10014270

undefined2 * __thiscall
FUN_10014270(void *this,undefined2 *param_1,
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
  puStack_c = &LAB_1001e52e;
  local_10 = ExceptionList;
  uVar2 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_b0 = &DAT_10021e9c;
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
  iVar3 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                                  RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0,
                          uVar6,uVar2);
  piVar5 = (int *)(iVar3 + *(int *)(param_2 + 4));
  uVar2 = 0;
  if (piVar5[1] - *piVar5 >> 2 != 0) {
    do {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
      local_8._0_1_ = 8;
      puVar1 = *(undefined4 **)(*piVar5 + uVar2 * 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021904,&local_14);
      if (-1 < iVar3) {
        param_2 = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
        local_8._0_1_ = 9;
        (**(code **)(*(int *)local_14 + 0x1c))(local_14,&param_2);
        FUN_100051d0((int *)&local_b0,(ushort *)param_2);
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
  FUN_1000fd00(&local_b0,param_1);
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



// Function: FUN_100144d0 at 100144d0

void FUN_100144d0(undefined4 *param_1,int *param_2)

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
  
  puStack_c = &LAB_1001e430;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_10021914,&local_34,local_14);
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
      FUN_100010a0(0x8007000e);
    }
  }
  iVar1 = local_3c;
  local_8._0_1_ = 3;
  (**(code **)(*piVar2 + 0xb0))(piVar2,local_3c,local_4c);
  local_8._0_1_ = 2;
  Ordinal_6(iVar1);
  FUN_1001ac50(8,(int)local_4c,0,0x409);
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar2 = local_44;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000a420(&local_30,local_44,(int)piVar2 - ((int)local_44 + 2) >> 1);
  local_8._0_1_ = 4;
  FUN_10010810(local_38,&local_30,(int)param_2);
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



// Function: FUN_10014650 at 10014650

void FUN_10014650(int *param_1,int param_2)

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
  
  puStack_c = &LAB_1001e3d0;
  local_10 = ExceptionList;
  puVar3 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_4c = 0;
  local_48 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)param_1;
  local_38 = (int *)0x0;
  local_8 = 1;
  local_e4 = &DAT_10021e9c;
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
  piVar4 = (int *)FUN_100051d0((int *)&local_e4,(ushort *)&DAT_10022fe4);
  FUN_100051d0(piVar4,puVar3);
  puVar5 = (undefined4 *)FUN_1000fd00(&local_e4,(undefined2 *)local_30);
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
      FUN_100010a0(0x8007000e);
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
                          &IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                           RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0);
  iVar1 = *(int *)(param_2 + 4);
  local_34 = 0;
  local_8._0_1_ = 10;
  (**(code **)(*local_38 + 0x88))(local_38,&local_34);
  local_3c = (int *)0x0;
  local_8._0_1_ = 0xc;
  puVar5 = *(undefined4 **)(iVar6 + iVar1);
  (**(code **)*puVar5)(puVar5,&DAT_10021904,&local_3c);
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
  FUN_10002cc0(local_48);
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



// Function: FUN_100148f0 at 100148f0

undefined2 * __cdecl FUN_100148f0(undefined2 *param_1,void *param_2)

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
  
  puStack_c = &LAB_1001e5d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = param_1;
  local_14 = 0;
  local_8 = 1;
  local_c8[0] = &DAT_10021ea4;
  local_b8[0] = &DAT_10021e9c;
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
  FUN_10003de0((int *)local_b8,(ushort *)&param_2);
  FUN_10010ad0(local_c8,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10014a80 at 10014a80

undefined2 * __cdecl FUN_10014a80(undefined2 *param_1,long param_2)

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
  puStack_c = &LAB_1001e67e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10021ea4;
  local_b4[0] = &DAT_10021e9c;
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
  FUN_10010ad0(local_c4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10014be0 at 10014be0

undefined2 * __cdecl FUN_10014be0(undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001e67e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10021ea4;
  local_b4[0] = &DAT_10021e9c;
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
  FUN_10010ad0(local_c4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10014d40 at 10014d40

undefined2 * __cdecl FUN_10014d40(undefined2 *param_1,float param_2)

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
  puStack_c = &LAB_1001e67e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_c4[0] = &DAT_10021ea4;
  local_b4[0] = &DAT_10021e9c;
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
  FUN_10010ad0(local_c4,param_1);
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
  FUN_10002cc0(local_1c);
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



// Function: FUN_10014ea0 at 10014ea0

undefined4 FUN_10014ea0(undefined4 param_1,int param_2)

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
  puStack_c = &LAB_1001e6c8;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar2,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar2 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditData,void*>::RTTI_Type_Descriptor,
                      &CAuditData::RTTI_Type_Descriptor,0);
      if ((&PTR_u_SystemName_1002da34)[iVar2 * 5] == (undefined *)0x0) break;
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditData,void*>::RTTI_Type_Descriptor,
                      &CAuditData::RTTI_Type_Descriptor,0);
      if ((&DAT_1002da3c)[iVar2 * 5] == local_18 + 1) {
        (*(code *)(&PTR_FUN_10022fec)[local_18])(local_20,&PTR_u_SystemName_1002da34 + iVar2 * 5);
      }
      iVar2 = iVar2 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10015010 at 10015010

undefined1 * Catch_10015010(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1001501d;
}



// Function: FUN_10015040 at 10015040

undefined4 FUN_10015040(undefined4 param_1,int param_2)

{
  LPCOLESTR pOVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uStack_38;
  int local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar4 = param_2;
  puStack_c = &LAB_1001e718;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar4,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar4 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_10011410(uVar2);
      if (puVar3[iVar4 * 5] == 0) break;
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_10011410(uVar2);
      if ((puVar3 + iVar4 * 5)[2] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002302c)[local_18])(local_20,puVar3 + iVar4 * 5);
      }
      iVar4 = iVar4 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100151be at 100151be

undefined1 * Catch_100151be(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100151cb;
}



// Function: FUN_100151f0 at 100151f0

undefined4 FUN_100151f0(undefined4 param_1,int param_2)

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
  puStack_c = &LAB_1001e768;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar2,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar2 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditModule,void*>::RTTI_Type_Descriptor,
                      &CAuditModule::RTTI_Type_Descriptor,0);
      if ((&PTR_DAT_1002db40)[iVar2 * 5] == (undefined *)0x0) break;
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditModule,void*>::RTTI_Type_Descriptor,
                      &CAuditModule::RTTI_Type_Descriptor,0);
      if ((&DAT_1002db48)[iVar2 * 5] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002303c)[local_18])(local_20,&PTR_DAT_1002db40 + iVar2 * 5);
      }
      iVar2 = iVar2 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10015360 at 10015360

undefined1 * Catch_10015360(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1001536d;
}



// Function: FUN_10015390 at 10015390

undefined4 FUN_10015390(undefined4 param_1,int param_2)

{
  LPCOLESTR pOVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uStack_38;
  int local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar4 = param_2;
  puStack_c = &LAB_1001e7b8;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar4,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar4 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_100125b0(uVar2);
      if (puVar3[iVar4 * 5] == 0) break;
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_100125b0(uVar2);
      if ((puVar3 + iVar4 * 5)[2] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002304c)[local_18])(local_20,puVar3 + iVar4 * 5);
      }
      iVar4 = iVar4 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1001550e at 1001550e

undefined1 * Catch_1001550e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1001551b;
}



// Function: FUN_10015540 at 10015540

undefined4 FUN_10015540(undefined4 param_1,int param_2)

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
  puStack_c = &LAB_1001e808;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar2,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar2 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditRecord,void*>::RTTI_Type_Descriptor,
                      &CAuditRecord::RTTI_Type_Descriptor,0);
      if ((&PTR_u_ToolDescription_1002dc48)[iVar2 * 5] == (undefined *)0x0) break;
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditRecord,void*>::RTTI_Type_Descriptor,
                      &CAuditRecord::RTTI_Type_Descriptor,0);
      if ((&DAT_1002dc50)[iVar2 * 5] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002305c)[local_18])
                  (local_20,&PTR_u_ToolDescription_1002dc48 + iVar2 * 5);
      }
      iVar2 = iVar2 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100156b0 at 100156b0

undefined1 * Catch_100156b0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100156bd;
}



// Function: FUN_100156e0 at 100156e0

undefined4 FUN_100156e0(undefined4 param_1,int param_2)

{
  LPCOLESTR pOVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uStack_38;
  int local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar4 = param_2;
  puStack_c = &LAB_1001e858;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar4,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar4 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_10013750(uVar2);
      if (puVar3[iVar4 * 5] == 0) break;
      uVar2 = __RTDynamicCast(param_1,0,
                              &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                               ::RTTI_Type_Descriptor,
                              &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                               ::RTTI_Type_Descriptor,0);
      puVar3 = FUN_10013750(uVar2);
      if ((puVar3 + iVar4 * 5)[2] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002306c)[local_18])(local_20,puVar3 + iVar4 * 5);
      }
      iVar4 = iVar4 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1001585e at 1001585e

undefined1 * Catch_1001585e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1001586b;
}



// Function: FUN_10015890 at 10015890

undefined4 FUN_10015890(undefined4 param_1,int param_2)

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
  puStack_c = &LAB_1001e8a8;
  local_10 = ExceptionList;
  uStack_38 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
    FUN_100010a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  FUN_10002910(&local_1c,pOVar1,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 2;
  Ordinal_6(pOVar1);
  (**(code **)(*local_1c + 0x104))(local_1c,iVar2,&param_2);
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*local_1c + 0x34))(local_1c,&local_20);
  for (local_18 = 0; iVar2 = 0, local_18 < 4; local_18 = local_18 + 1) {
    while( true ) {
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditAdjustment,void*>::RTTI_Type_Descriptor,
                      &CAuditAdjustment::RTTI_Type_Descriptor,0);
      if ((&PTR_u_Identifier_1002dd50)[iVar2 * 5] == (undefined *)0x0) break;
      __RTDynamicCast(param_1,0,
                      &IXMLSerializationImpl<struct_CAuditAdjustment,void*>::RTTI_Type_Descriptor,
                      &CAuditAdjustment::RTTI_Type_Descriptor,0);
      if ((&DAT_1002dd58)[iVar2 * 5] == local_18 + 1) {
        (*(code *)(&PTR_FUN_1002307c)[local_18])(local_20,&PTR_u_Identifier_1002dd50 + iVar2 * 5);
      }
      iVar2 = iVar2 + 1;
    }
  }
  local_8._0_1_ = 2;
  FUN_10002110(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002110((int *)&local_1c);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10015a00 at 10015a00

undefined1 * Catch_10015a00(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10015a0d;
}



// Function: FUN_10015a30 at 10015a30

void __thiscall FUN_10015a30(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 < 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_10010950(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_10015a60 at 10015a60

undefined2 * __cdecl FUN_10015a60(undefined2 *param_1,int *param_2)

{
  uint in_stack_ffffffc0;
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e8f1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)(in_stack_ffffffc0 & 0xffff0000);
  FUN_1000a220(&stack0xffffffc0,param_2,0,0xffffffff);
  local_8 = 0;
  FUN_100148f0(param_1,pvVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015af0 at 10015af0

undefined2 * __cdecl FUN_10015af0(undefined2 *param_1,long *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10014a80(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015b50 at 10015b50

undefined2 * __cdecl FUN_10015b50(undefined2 *param_1,int *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10014be0(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015bb0 at 10015bb0

undefined2 * __cdecl FUN_10015bb0(undefined2 *param_1,float *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10014d40(param_1,*param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015c10 at 10015c10

void FUN_10015c10(int *param_1,int param_2)

{
  HRESULT HVar1;
  int iVar2;
  uint uStack_54;
  ushort local_44 [8];
  undefined4 local_34 [4];
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001e9b0;
  local_10 = ExceptionList;
  uStack_54 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  FUN_100098c0(local_34);
  local_1c = (undefined4 *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_10021578,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100219f8,&local_1c);
  FUN_10015a30(local_34,HVar1);
  local_18 = (undefined4 *)0x0;
  local_8._0_1_ = 4;
  iVar2 = (**(code **)*local_1c)(local_1c,&DAT_1002242c,&local_18);
  FUN_10015a30(local_34,iVar2);
  local_24 = local_1c;
  local_1c = (undefined4 *)0x0;
  FUN_1000b3d0(param_1 + 2,&local_24);
  local_20 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)*local_18)(local_18,&DAT_1002243c,&local_20);
  FUN_10015a30(local_34,iVar2);
  local_8._0_1_ = 7;
  FUN_10009860(&param_1,local_20);
  local_8._0_1_ = 8;
  FUN_100097b0(local_44,param_2);
  local_8._0_1_ = 9;
  FUN_10009630(param_1,1,local_44);
  local_8._0_1_ = 8;
  Ordinal_9(local_44);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10009810((int *)&param_1);
  local_8 = 6;
  FUN_10015d35();
  return;
}



// Function: Catch@10015d26 at 10015d26

undefined * Catch_10015d26(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 6;
  return &DAT_10015d33;
}



// Function: FUN_10015d35 at 10015d35

undefined4 FUN_10015d35(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *(int **)(unaff_EBP + -0x14) = unaff_EBX;
  **(undefined4 **)(unaff_EBP + 0x10) = uVar1;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  piVar2 = *(int **)(unaff_EBP + -0x1c);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  piVar2 = *(int **)(unaff_EBP + -0x14);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  piVar2 = *(int **)(unaff_EBP + -0x18);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x24);
}



// Function: FUN_10015da0 at 10015da0

int FUN_10015da0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 local_30 [4];
  int local_28;
  undefined4 local_20 [3];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ea60;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098c0(local_20);
  local_30[0] = 3;
  local_28 = param_2;
  local_8 = 1;
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if ((-1 < param_2) && (param_2 < (int)puVar3 - *(int *)(param_1 + 8) >> 2)) {
    puVar3 = *(undefined4 **)(param_1 + 8);
    if (0 < param_2) {
      puVar3 = puVar3 + param_2;
    }
    FUN_10015a30(local_20,0);
  }
  if (-1 < local_14) {
    iVar2 = (*(code *)**(undefined4 **)*puVar3)((undefined4 *)*puVar3,&DAT_1002242c,param_3,uVar1);
    FUN_10015a30(local_20,iVar2);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_30);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10015eb0 at 10015eb0

void FUN_10015eb0(int *param_1,int param_2)

{
  HRESULT HVar1;
  int iVar2;
  uint uStack_54;
  ushort local_44 [8];
  undefined4 local_34 [4];
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ea30;
  local_10 = ExceptionList;
  uStack_54 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  FUN_100098c0(local_34);
  local_1c = (undefined4 *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_10021598,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100219f8,&local_1c);
  FUN_10015a30(local_34,HVar1);
  local_18 = (undefined4 *)0x0;
  local_8._0_1_ = 4;
  iVar2 = (**(code **)*local_1c)(local_1c,&DAT_100224b0,&local_18);
  FUN_10015a30(local_34,iVar2);
  local_24 = local_1c;
  local_1c = (undefined4 *)0x0;
  FUN_1000b3d0(param_1 + 2,&local_24);
  local_20 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)*local_18)(local_18,&DAT_1002243c,&local_20);
  FUN_10015a30(local_34,iVar2);
  local_8._0_1_ = 7;
  FUN_10009860(&param_1,local_20);
  local_8._0_1_ = 8;
  FUN_100097b0(local_44,param_2);
  local_8._0_1_ = 9;
  FUN_10009630(param_1,1,local_44);
  local_8._0_1_ = 8;
  Ordinal_9(local_44);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10009810((int *)&param_1);
  local_8 = 6;
  FUN_10015fd5();
  return;
}



// Function: Catch@10015fc6 at 10015fc6

undefined * Catch_10015fc6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 6;
  return &DAT_10015fd3;
}



// Function: FUN_10015fd5 at 10015fd5

undefined4 FUN_10015fd5(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *(int **)(unaff_EBP + -0x14) = unaff_EBX;
  **(undefined4 **)(unaff_EBP + 0x10) = uVar1;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  piVar2 = *(int **)(unaff_EBP + -0x1c);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  piVar2 = *(int **)(unaff_EBP + -0x14);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  piVar2 = *(int **)(unaff_EBP + -0x18);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x24);
}



// Function: FUN_10016040 at 10016040

int FUN_10016040(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 local_30 [4];
  int local_28;
  undefined4 local_20 [3];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ea60;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098c0(local_20);
  local_30[0] = 3;
  local_28 = param_2;
  local_8 = 1;
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if ((-1 < param_2) && (param_2 < (int)puVar3 - *(int *)(param_1 + 8) >> 2)) {
    puVar3 = *(undefined4 **)(param_1 + 8);
    if (0 < param_2) {
      puVar3 = puVar3 + param_2;
    }
    FUN_10015a30(local_20,0);
  }
  if (-1 < local_14) {
    iVar2 = (*(code *)**(undefined4 **)*puVar3)((undefined4 *)*puVar3,&DAT_100224b0,param_3,uVar1);
    FUN_10015a30(local_20,iVar2);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_30);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10016150 at 10016150

void FUN_10016150(int *param_1,int param_2)

{
  HRESULT HVar1;
  int iVar2;
  uint uStack_54;
  ushort local_44 [8];
  undefined4 local_34 [4];
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001eae0;
  local_10 = ExceptionList;
  uStack_54 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  FUN_100098c0(local_34);
  local_1c = (undefined4 *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_100215b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100219f8,&local_1c);
  FUN_10015a30(local_34,HVar1);
  local_18 = (undefined4 *)0x0;
  local_8._0_1_ = 4;
  iVar2 = (**(code **)*local_1c)(local_1c,&DAT_10022518,&local_18);
  FUN_10015a30(local_34,iVar2);
  local_24 = local_1c;
  local_1c = (undefined4 *)0x0;
  FUN_1000b3d0(param_1 + 2,&local_24);
  local_20 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)*local_18)(local_18,&DAT_1002243c,&local_20);
  FUN_10015a30(local_34,iVar2);
  local_8._0_1_ = 7;
  FUN_10009860(&param_1,local_20);
  local_8._0_1_ = 8;
  FUN_100097b0(local_44,param_2);
  local_8._0_1_ = 9;
  FUN_10009630(param_1,1,local_44);
  local_8._0_1_ = 8;
  Ordinal_9(local_44);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10009810((int *)&param_1);
  local_8 = 6;
  FUN_10016275();
  return;
}



// Function: Catch@10016266 at 10016266

undefined * Catch_10016266(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 6;
  return &DAT_10016273;
}



// Function: FUN_10016275 at 10016275

undefined4 FUN_10016275(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *(int **)(unaff_EBP + -0x14) = unaff_EBX;
  **(undefined4 **)(unaff_EBP + 0x10) = uVar1;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  piVar2 = *(int **)(unaff_EBP + -0x1c);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  piVar2 = *(int **)(unaff_EBP + -0x14);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  piVar2 = *(int **)(unaff_EBP + -0x18);
  if (piVar2 != unaff_EBX) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x24);
}



// Function: FUN_100162e0 at 100162e0

int FUN_100162e0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 local_30 [4];
  int local_28;
  undefined4 local_20 [3];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ea60;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100098c0(local_20);
  local_30[0] = 3;
  local_28 = param_2;
  local_8 = 1;
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if ((-1 < param_2) && (param_2 < (int)puVar3 - *(int *)(param_1 + 8) >> 2)) {
    puVar3 = *(undefined4 **)(param_1 + 8);
    if (0 < param_2) {
      puVar3 = puVar3 + param_2;
    }
    FUN_10015a30(local_20,0);
  }
  if (-1 < local_14) {
    iVar2 = (*(code *)**(undefined4 **)*puVar3)((undefined4 *)*puVar3,&DAT_10022518,param_3,uVar1);
    FUN_10015a30(local_20,iVar2);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_30);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100163f0 at 100163f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100163f0(undefined2 *param_1,undefined4 param_2,type_info *param_3)

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
  puStack_c = &LAB_1001ebd7;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_1002ff18 & 1) == 0) {
    DAT_1002ff18 = DAT_1002ff18 | 1;
    local_8 = 1;
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)
                               &std::
                                basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                ::RTTI_Type_Descriptor,(__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 2;
    _DAT_1002fe6c = 0xf;
    _DAT_1002fe68 = 0;
    DAT_1002fe58 = 0;
    FUN_1000a130(&DAT_1002fe58,(int *)local_30,0,0xffffffff);
    _DAT_1002fe74 = FUN_10015a60;
    local_8._0_1_ = 5;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_1002dbc4,
                               (__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 6;
    _DAT_1002fe8c = 0xf;
    _DAT_1002fe88 = 0;
    DAT_1002fe78 = 0;
    FUN_1000a130(&DAT_1002fe78,(int *)local_30,0,0xffffffff);
    _DAT_1002fe94 = FUN_1000f7d0;
    local_8._0_1_ = 9;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_1002dbb8,
                               (__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 10;
    _DAT_1002feac = 0xf;
    _DAT_1002fea8 = 0;
    DAT_1002fe98 = 0;
    FUN_1000a130(&DAT_1002fe98,(int *)local_30,0,0xffffffff);
    _DAT_1002feb4 = FUN_10015af0;
    local_8._0_1_ = 0xd;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_1002dad8,
                               (__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0xe;
    _DAT_1002fecc = 0xf;
    _DAT_1002fec8 = 0;
    DAT_1002feb8 = 0;
    FUN_1000a130(&DAT_1002feb8,(int *)local_30,0,0xffffffff);
    _DAT_1002fed4 = FUN_10015b50;
    local_8._0_1_ = 0x11;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&TypeDescriptor_1002f8d4,
                               (__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0x12;
    _DAT_1002feec = 0xf;
    _DAT_1002fee8 = 0;
    DAT_1002fed8 = 0;
    FUN_1000a130(&DAT_1002fed8,(int *)local_30,0,0xffffffff);
    _DAT_1002fef4 = FUN_10015bb0;
    local_8._0_1_ = 0x15;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar3 = (int *)type_info::_name_internal_method
                              ((type_info *)&ATL::CComVariant::RTTI_Type_Descriptor,
                               (__type_info_node *)&DAT_1002ffe0);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    piVar8 = piVar3;
    do {
      iVar2 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar2 != '\0');
    FUN_1000a320(local_30,piVar3,(int)piVar8 - ((int)piVar3 + 1));
    local_8._0_1_ = 0x16;
    _DAT_1002ff0c = 0xf;
    _DAT_1002ff08 = 0;
    DAT_1002fef8 = 0;
    FUN_1000a130(&DAT_1002fef8,(int *)local_30,0,0xffffffff);
    _DAT_1002ff14 = FUN_1000f830;
    local_8._0_1_ = 0x19;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    local_8._0_1_ = 1;
    _atexit((_func_4879 *)&LAB_1001fb20);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_3c = 0;
  local_38 = &DAT_1002fe58;
  while( true ) {
    pbVar4 = FUN_1000e3f0(local_38,(undefined1 *)local_30);
    local_8 = 0x1a;
    pbVar5 = (byte *)type_info::_name_internal_method(param_3,(__type_info_node *)&DAT_1002ffe0);
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
    uVar6 = FUN_10002a60(pbVar4,pbVar5,uVar6);
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
      FUN_1000a420(param_1,(int *)L"INVALID_TYPE",0xc);
LAB_10016878:
      local_8 = 0;
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FUN_10010a20(&DAT_1002fe58 + local_3c * 0x20,param_1,param_2);
  goto LAB_10016878;
}



// Function: FUN_100168c0 at 100168c0

/* WARNING: Removing unreachable block (ram,0x10016ae2) */
/* WARNING: Removing unreachable block (ram,0x10016afc) */
/* WARNING: Removing unreachable block (ram,0x10016af4) */
/* WARNING: Removing unreachable block (ram,0x10016b02) */

void __thiscall FUN_100168c0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditData,void*>::
                                  RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0,puVar6,
                          uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x10016a5d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10016bb0 at 10016bb0

/* WARNING: Removing unreachable block (ram,0x10016dd2) */
/* WARNING: Removing unreachable block (ram,0x10016dec) */
/* WARNING: Removing unreachable block (ram,0x10016de4) */
/* WARNING: Removing unreachable block (ram,0x10016df2) */

void __thiscall FUN_10016bb0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,puVar6,uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x10016d4d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10016ea0 at 10016ea0

/* WARNING: Removing unreachable block (ram,0x100170c2) */
/* WARNING: Removing unreachable block (ram,0x100170dc) */
/* WARNING: Removing unreachable block (ram,0x100170d4) */
/* WARNING: Removing unreachable block (ram,0x100170e2) */

void __thiscall FUN_10016ea0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditModule,void*>::
                                  RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0,puVar6,
                          uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x1001703d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10017190 at 10017190

/* WARNING: Removing unreachable block (ram,0x100173b2) */
/* WARNING: Removing unreachable block (ram,0x100173cc) */
/* WARNING: Removing unreachable block (ram,0x100173c4) */
/* WARNING: Removing unreachable block (ram,0x100173d2) */

void __thiscall FUN_10017190(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,puVar6,uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x1001732d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10017480 at 10017480

/* WARNING: Removing unreachable block (ram,0x100176a2) */
/* WARNING: Removing unreachable block (ram,0x100176bc) */
/* WARNING: Removing unreachable block (ram,0x100176b4) */
/* WARNING: Removing unreachable block (ram,0x100176c2) */

void __thiscall FUN_10017480(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditRecord,void*>::
                                  RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0,puVar6,
                          uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x1001761d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10017770 at 10017770

/* WARNING: Removing unreachable block (ram,0x10017992) */
/* WARNING: Removing unreachable block (ram,0x100179ac) */
/* WARNING: Removing unreachable block (ram,0x100179a4) */
/* WARNING: Removing unreachable block (ram,0x100179b2) */

void __thiscall FUN_10017770(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0,puVar6,uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x1001790d;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10017a60 at 10017a60

/* WARNING: Removing unreachable block (ram,0x10017c82) */
/* WARNING: Removing unreachable block (ram,0x10017c9c) */
/* WARNING: Removing unreachable block (ram,0x10017c94) */
/* WARNING: Removing unreachable block (ram,0x10017ca2) */

void __thiscall FUN_10017a60(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001ec89;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0;
  local_3c = param_1;
  local_d8 = &DAT_10021e9c;
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
  iVar2 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                                  RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0,
                          puVar6,uVar1);
  piVar5 = (int *)(iVar2 + param_2[1]);
  iVar2 = *piVar5;
  if (piVar5[1] - iVar2 >> 2 != 0) {
    do {
      local_34 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 (iVar2 + uVar4 * 4);
      piVar3 = (int *)FUN_100051d0((int *)&local_d8,(ushort *)&DAT_100230b0);
      piVar3 = (int *)FUN_100051d0(piVar3,puVar6);
      FUN_100051d0(piVar3,(ushort *)unaff_ESI);
      puVar6 = (ushort *)FUN_100163f0((undefined2 *)local_30,local_34,(type_info *)param_2[3]);
      local_8._0_1_ = 7;
      FUN_10003de0((int *)&local_d8,puVar6);
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
      piVar3 = (int *)FUN_100051d0((int *)unaff_ESI,(ushort *)&DAT_100230a8);
      local_d8 = (undefined *)0x10017bfd;
      piVar3 = (int *)FUN_100051d0(piVar3,(ushort *)pcVar7);
      this_00 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                FUN_100051d0(piVar3,in_stack_ffffff3c);
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                (this_00,in_stack_ffffff48);
      iVar2 = *piVar5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar5[1] - iVar2 >> 2));
  }
  FUN_1000fd00(&local_d8,local_3c);
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



// Function: FUN_10017d50 at 10017d50

void __thiscall FUN_10017d50(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditData,void*>::
                                  RTTI_Type_Descriptor,&CAuditData::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_10017f10 at 10017f10

void __thiscall FUN_10017f10(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_100180d0 at 100180d0

void __thiscall FUN_100180d0(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditModule,void*>::
                                  RTTI_Type_Descriptor,&CAuditModule::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_10018290 at 10018290

void __thiscall FUN_10018290(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_10018450 at 10018450

void __thiscall FUN_10018450(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditRecord,void*>::
                                  RTTI_Type_Descriptor,&CAuditRecord::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_10018610 at 10018610

void __thiscall FUN_10018610(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                  ::RTTI_Type_Descriptor,
                          &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                           ::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_100187d0 at 100187d0

void __thiscall FUN_100187d0(void *this,undefined2 *param_1,int param_2)

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
  puStack_c = &LAB_1001ece1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
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
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbc4);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbc4;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dbb8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),(type_info *)&TypeDescriptor_1002dad8);
  if (bVar1) {
    pTVar6 = &TypeDescriptor_1002dad8;
  }
  bVar1 = type_info::operator==
                    (*(type_info **)(param_2 + 0xc),
                     (type_info *)&ATL::CComVariant::RTTI_Type_Descriptor);
  if (bVar1) {
    pTVar6 = &ATL::CComVariant::RTTI_Type_Descriptor;
  }
  piVar2 = (int *)type_info::_name_internal_method
                            (*(type_info **)(param_2 + 0xc),(__type_info_node *)&DAT_1002ffe0);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  piVar5 = piVar2;
  do {
    iVar4 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
  } while ((char)iVar4 != '\0');
  FUN_1000a320(local_30,piVar2,(int)piVar5 - ((int)piVar2 + 1));
  local_8 = 1;
  uVar3 = FUN_10002d80(local_30,&DAT_100230d0,0,4);
  if (uVar3 != 0xffffffff) {
    pTVar6 = &TypeDescriptor_1002dbb8;
  }
  iVar4 = __RTDynamicCast(this,0,&IXMLSerializationImpl<struct_CAuditAdjustment,void*>::
                                  RTTI_Type_Descriptor,&CAuditAdjustment::RTTI_Type_Descriptor,0);
  if (pTVar6 == (TypeDescriptor *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000a420(param_1,(int *)L"InvalidType",0xb);
  }
  else {
    FUN_100163f0(param_1,*(int *)(param_2 + 4) + iVar4,(type_info *)pTVar6);
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



// Function: FUN_10018990 at 10018990

void __thiscall FUN_10018990(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_10017d50(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x10018aeb;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_10018bf0 at 10018bf0

void __thiscall FUN_10018bf0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_10017f10(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x10018d4b;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_10018e50 at 10018e50

void __thiscall FUN_10018e50(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_100180d0(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x10018fab;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_100190b0 at 100190b0

void __thiscall FUN_100190b0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_10018290(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x1001920b;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_10019310 at 10019310

void __thiscall FUN_10019310(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_10018450(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x1001946b;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_10019570 at 10019570

void __thiscall FUN_10019570(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_10018610(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x100196cb;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_100197d0 at 100197d0

void __thiscall FUN_100197d0(void *this,undefined2 *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001eda1;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_58 = param_1;
  local_f4 = &DAT_10021e9c;
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
  FUN_1000a420(&local_30,piVar3,(int)piVar2 - (int)local_50 >> 1);
  local_8._0_1_ = 7;
  FUN_100187d0(this,(undefined2 *)local_4c,(int)param_2);
  local_8._0_1_ = 8;
  puVar6 = (ushort *)0x20;
  puVar5 = (ushort *)0x22;
  piVar3 = (int *)FUN_100051d0((int *)&local_f4,(ushort *)&DAT_100230d8);
  piVar3 = (int *)FUN_10003de0(piVar3,puVar5);
  pvVar4 = (void *)FUN_100051d0(piVar3,puVar6);
  piVar3 = FUN_10005500(pvVar4,unaff_EDI);
  pvVar4 = (void *)FUN_10003de0(piVar3,unaff_ESI);
  local_f4 = (undefined *)0x1001992b;
  piVar3 = FUN_10005500(pvVar4,ppuVar7);
  FUN_10005500(piVar3,in_stack_ffffff14);
  local_8._0_1_ = 7;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000fd00(&local_f4,local_58);
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
  FUN_10002cc0(local_5c);
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



// Function: FUN_10019a30 at 10019a30

void FUN_10019a30(undefined4 param_1,int *param_2)

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
  
  puStack_c = &LAB_1001edfb;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    __RTDynamicCast(param_1,0,&IXMLSerializationImpl<struct_CAuditData,void*>::RTTI_Type_Descriptor,
                    &CAuditData::RTTI_Type_Descriptor,0);
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar5,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var8 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        __RTDynamicCast(param_1,0);
        if ((&PTR_u_SystemName_1002da34)[iVar2 * 5] == (undefined *)0x0) break;
        __RTDynamicCast(param_1,0,
                        &IXMLSerializationImpl<struct_CAuditData,void*>::RTTI_Type_Descriptor,
                        &CAuditData::RTTI_Type_Descriptor);
        if ((&DAT_1002da3c)[iVar2 * 5] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_100230e0)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar6,p_Var8);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    __RTDynamicCast(param_1,0);
    pcVar9 = endl_exref;
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar5 = (int *)FUN_100051d0(piVar5,(ushort *)pcVar9);
    pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar5,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar6,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar5 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar5;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@10019c7c at 10019c7c

undefined * Catch_10019c7c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10019c89;
}



// Function: FUN_10019cc0 at 10019cc0

void FUN_10019cc0(undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar8;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *p_Var9;
  code *pcVar10;
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
  
  puStack_c = &LAB_1001ee5b;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                             ::RTTI_Type_Descriptor,0);
    FUN_100028f0(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar6,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var9 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        uVar5 = __RTDynamicCast(param_1,0);
        puVar7 = FUN_10011410(uVar5);
        if (puVar7[iVar2 * 5] == 0) break;
        uVar5 = __RTDynamicCast(param_1,0,
                                &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                                 ::RTTI_Type_Descriptor,
                                &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                                 ::RTTI_Type_Descriptor);
        puVar7 = FUN_10011410(uVar5);
        if (puVar7[iVar2 * 5 + 2] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_100230f0)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar8,p_Var9);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    pcVar10 = endl_exref;
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditModules,struct_IAuditModules,struct_IAuditModule,&struct__GUID_const_CLSID_AuditModule,long,unsigned_short*>
                             ::RTTI_Type_Descriptor);
    FUN_100028f0(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar6 = (int *)FUN_100051d0(piVar6,(ushort *)pcVar10);
    pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar6,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar8,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar6 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar6;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@10019f20 at 10019f20

undefined * Catch_10019f20(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10019f2d;
}



// Function: FUN_10019f60 at 10019f60

void FUN_10019f60(undefined4 param_1,int *param_2)

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
  
  puStack_c = &LAB_1001eebb;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    __RTDynamicCast(param_1,0,
                    &IXMLSerializationImpl<struct_CAuditModule,void*>::RTTI_Type_Descriptor,
                    &CAuditModule::RTTI_Type_Descriptor,0);
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar5,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var8 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        __RTDynamicCast(param_1,0);
        if ((&PTR_DAT_1002db40)[iVar2 * 5] == (undefined *)0x0) break;
        __RTDynamicCast(param_1,0,
                        &IXMLSerializationImpl<struct_CAuditModule,void*>::RTTI_Type_Descriptor,
                        &CAuditModule::RTTI_Type_Descriptor);
        if ((&DAT_1002db48)[iVar2 * 5] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10023100)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar6,p_Var8);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    __RTDynamicCast(param_1,0);
    pcVar9 = endl_exref;
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar5 = (int *)FUN_100051d0(piVar5,(ushort *)pcVar9);
    pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar5,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar6,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar5 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar5;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@1001a1ac at 1001a1ac

undefined * Catch_1001a1ac(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001a1b9;
}



// Function: FUN_1001a1f0 at 1001a1f0

void FUN_1001a1f0(undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar8;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *p_Var9;
  code *pcVar10;
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
  
  puStack_c = &LAB_1001ef1b;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                             ::RTTI_Type_Descriptor,0);
    FUN_10002d40(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar6,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var9 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        uVar5 = __RTDynamicCast(param_1,0);
        puVar7 = FUN_100125b0(uVar5);
        if (puVar7[iVar2 * 5] == 0) break;
        uVar5 = __RTDynamicCast(param_1,0,
                                &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                                 ::RTTI_Type_Descriptor,
                                &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                                 ::RTTI_Type_Descriptor);
        puVar7 = FUN_100125b0(uVar5);
        if (puVar7[iVar2 * 5 + 2] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10023110)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar8,p_Var9);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    pcVar10 = endl_exref;
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditRecords,struct_IAuditRecords,struct_IAuditRecord,&struct__GUID_const_CLSID_AuditRecord,long,unsigned_short*>
                             ::RTTI_Type_Descriptor);
    FUN_10002d40(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar6 = (int *)FUN_100051d0(piVar6,(ushort *)pcVar10);
    pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar6,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar8,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar6 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar6;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@1001a450 at 1001a450

undefined * Catch_1001a450(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001a45d;
}



// Function: FUN_1001a490 at 1001a490

void FUN_1001a490(undefined4 param_1,int *param_2)

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
  
  puStack_c = &LAB_1001ef7b;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    __RTDynamicCast(param_1,0,
                    &IXMLSerializationImpl<struct_CAuditRecord,void*>::RTTI_Type_Descriptor,
                    &CAuditRecord::RTTI_Type_Descriptor,0);
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar5,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var8 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        __RTDynamicCast(param_1,0);
        if ((&PTR_u_ToolDescription_1002dc48)[iVar2 * 5] == (undefined *)0x0) break;
        __RTDynamicCast(param_1,0,
                        &IXMLSerializationImpl<struct_CAuditRecord,void*>::RTTI_Type_Descriptor,
                        &CAuditRecord::RTTI_Type_Descriptor);
        if ((&DAT_1002dc50)[iVar2 * 5] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10023120)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar6,p_Var8);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    __RTDynamicCast(param_1,0);
    pcVar9 = endl_exref;
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar5 = (int *)FUN_100051d0(piVar5,(ushort *)pcVar9);
    pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar5,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar6,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar5 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar5;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@1001a6dc at 1001a6dc

undefined * Catch_1001a6dc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001a6e9;
}



// Function: FUN_1001a720 at 1001a720

void FUN_1001a720(undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar8;
  _func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
  *p_Var9;
  code *pcVar10;
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
  
  puStack_c = &LAB_1001efdb;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                             ::RTTI_Type_Descriptor,0);
    FUN_10002d60(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar6,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var9 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        uVar5 = __RTDynamicCast(param_1,0);
        puVar7 = FUN_10013750(uVar5);
        if (puVar7[iVar2 * 5] == 0) break;
        uVar5 = __RTDynamicCast(param_1,0,
                                &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                                 ::RTTI_Type_Descriptor,
                                &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                                 ::RTTI_Type_Descriptor);
        puVar7 = FUN_10013750(uVar5);
        if (puVar7[iVar2 * 5 + 2] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10023130)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar8,p_Var9);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    pcVar10 = endl_exref;
    uVar5 = __RTDynamicCast(param_1,0,
                            &IXMLSerializationImpl<struct_IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>,void*>
                             ::RTTI_Type_Descriptor,
                            &IObjectCollectionImpl<struct_CAuditAdjustments,struct_IAuditAdjustments,struct_IAuditAdjustment,&struct__GUID_const_CLSID_AuditAdjustment,long,unsigned_short*>
                             ::RTTI_Type_Descriptor);
    FUN_10002d60(uVar5);
    piVar6 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar6 = (int *)FUN_100051d0(piVar6,(ushort *)pcVar10);
    pbVar8 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar6,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar8,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar6 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar6;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@1001a980 at 1001a980

undefined * Catch_1001a980(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001a98d;
}



// Function: FUN_1001a9c0 at 1001a9c0

void FUN_1001a9c0(undefined4 param_1,int *param_2)

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
  
  puStack_c = &LAB_1001f03b;
  local_10 = ExceptionList;
  puVar4 = (ushort *)(DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  local_14 = &stack0xffffff08;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_18 = puVar4;
  puVar3 = &stack0xffffff08;
  if ((param_2 != (int *)0x0) && (puVar3 = &stack0xffffff08, *param_2 == 0)) {
    local_8 = 0;
    Ordinal_8(local_50);
    local_8._0_1_ = 1;
    FUN_10005ed0(&stack0xffffff18,2,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    __RTDynamicCast(param_1,0,
                    &IXMLSerializationImpl<struct_CAuditAdjustment,void*>::RTTI_Type_Descriptor,
                    &CAuditAdjustment::RTTI_Type_Descriptor,0);
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b0);
    FUN_100051d0(piVar5,puVar4);
    local_40 = 0;
    while (uVar1 = local_40, local_40 < 4) {
      local_3c = 0;
      while( true ) {
        iVar2 = local_3c;
        p_Var8 = (_func_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr_basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>_ptr
                  *)0x0;
        __RTDynamicCast(param_1,0);
        if ((&PTR_u_Identifier_1002dd50)[iVar2 * 5] == (undefined *)0x0) break;
        __RTDynamicCast(param_1,0,
                        &IXMLSerializationImpl<struct_CAuditAdjustment,void*>::RTTI_Type_Descriptor,
                        &CAuditAdjustment::RTTI_Type_Descriptor);
        if ((&DAT_1002dd58)[iVar2 * 5] == uVar1 + 1) {
          puVar4 = (ushort *)(*(code *)(&PTR_FUN_10023140)[uVar1])();
          local_8._0_1_ = 3;
          FUN_10003de0((int *)&stack0xffffff18,puVar4);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10005900(local_34);
        }
        local_3c = local_3c + 1;
      }
      if (uVar1 == 0) {
        pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                 FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230b4);
        std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
                  (pbVar6,p_Var8);
      }
      param_2 = local_38;
      local_40 = uVar1 + 1;
    }
    __RTDynamicCast(param_1,0);
    pcVar9 = endl_exref;
    piVar5 = (int *)FUN_100051d0((int *)&stack0xffffff18,(ushort *)&DAT_100230a8);
    piVar5 = (int *)FUN_100051d0(piVar5,(ushort *)pcVar9);
    pbVar6 = (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_100051d0(piVar5,in_stack_ffffff1c);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              (pbVar6,in_stack_ffffff28);
    puVar7 = (undefined4 *)FUN_1000fd00(&stack0xffffff18,(undefined2 *)local_34);
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
        FUN_100010a0(0x8007000e);
      }
    }
    piVar5 = local_38;
    local_8._0_1_ = 6;
    FUN_10005900(local_34);
    local_38 = (int *)0x0;
    *param_2 = (int)piVar5;
    local_8._0_1_ = 2;
    Ordinal_6();
    local_8._0_1_ = 1;
    FUN_10005e10((int *)&stack0xffffff18);
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



// Function: Catch@1001ac0c at 1001ac0c

undefined * Catch_1001ac0c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001ac19;
}



// Function: FUN_1001ac50 at 1001ac50

void __cdecl FUN_1001ac50(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_1001ac80 at 1001ac80

int * __cdecl FUN_1001ac80(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f0e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2,DAT_1002fdb0 ^ (uint)&stack0xfffffffc,0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010a0(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001ad00 at 1001ad00

int __cdecl FUN_1001ad00(int param_1)

{
  int iVar1;
  undefined2 local_20 [4];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f118;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20[0] = 0;
  iVar1 = Ordinal_9(local_20,DAT_1002fdb0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(iVar1);
  }
  local_20[0] = 8;
  local_18 = Ordinal_2(param_1);
  if ((local_18 == 0) && (param_1 != 0)) {
    local_20[0] = 10;
    local_18 = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_100010a0(0x8007000e);
  }
  local_8 = 0;
  FUN_1001ac50(3,(int)local_20,0,0x409);
  iVar1 = local_18;
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001adc0 at 1001adc0

undefined2 * __cdecl FUN_1001adc0(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f159;
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
  FUN_1000a420(param_1,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001ae70 at 1001ae70

void __cdecl FUN_1001ae70(undefined2 *param_1,undefined4 param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t local_1a4;
  undefined1 local_1a2 [398];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f1a2;
  local_10 = ExceptionList;
  local_14 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  swprintf_s(&local_1a4,400,L"%X",param_2,local_14);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  pwVar2 = &local_1a4;
  *param_1 = 0;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_1000a420(param_1,(int *)&local_1a4,(int)pwVar2 - (int)local_1a2 >> 1);
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001af42 at 1001af42

void __fastcall FUN_1001af42(int *param_1)

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



// Function: FUN_1001af86 at 1001af86

int __fastcall FUN_1001af86(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1001af9f at 1001af9f

undefined4 * __fastcall FUN_1001af9f(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1001af86((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1002a990;
  param_1[3] = &DAT_1002a990;
  uVar1 = FUN_100013a0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_1002fdc8 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1001afe0 at 1001afe0

void __fastcall FUN_1001afe0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1001afff at 1001afff

int __fastcall FUN_1001afff(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1001b024 at 1001b024

void __fastcall FUN_1001b024(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1001afe0((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1001b03c at 1001b03c

undefined4 * __fastcall FUN_1001b03c(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1001afff((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1002330c;
  uVar1 = FUN_100013a0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_1002fdc8 = 1;
  }
  return param_1;
}



// Function: FUN_1001b07c at 1001b07c

void FUN_1001b07c(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1001b0d6

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



// Function: __security_check_cookie at 1001b128

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1002fdb0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __alloca_probe at 1001b140

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



// Function: `eh_vector_constructor_iterator' at 1001b190

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
  FUN_1001b1dd();
  return;
}



// Function: FUN_1001b1dd at 1001b1dd

void FUN_1001b1dd(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 1001b1f5

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



// Function: `eh_vector_destructor_iterator' at 1001b253

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
  FUN_1001b29e();
  return;
}



// Function: FUN_1001b29e at 1001b29e

void FUN_1001b29e(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe_16 at 1001b2f0

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



// Function: __alloca_probe_8 at 1001b306

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



// Function: __onexit at 1001b320

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
  
  local_8 = &DAT_1002a928;
  uStack_c = 0x1001b32c;
  local_20[0] = DecodePointer(DAT_10030324);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10030324);
    local_24 = DecodePointer(DAT_10030320);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10030324 = EncodePointer(local_20[0]);
    DAT_10030320 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001b3b8();
  }
  return p_Var1;
}



// Function: FUN_1001b3b8 at 1001b3b8

void FUN_1001b3b8(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001b3c1

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 1001b432

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
    if (DAT_1002ffe8 < 1) {
      return 0;
    }
    DAT_1002ffe8 = DAT_1002ffe8 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030318,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030314 == 2) {
      param_2 = (int *)DecodePointer(DAT_10030324);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10030320);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10030324);
            piVar8 = (int *)DecodePointer(DAT_10030320);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10030320 = (PVOID)encoded_null();
        DAT_10030324 = DAT_10030320;
      }
      DAT_10030314 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10030318,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030318,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030314 == 0) {
      DAT_10030314 = 1;
      iVar5 = initterm_e(&DAT_1002139c,&DAT_100213a4);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100212ac,&DAT_10021398);
      DAT_10030314 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10030318,0);
    }
    if ((DAT_1003031c != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1003031c), BVar2 != 0)) {
      (*DAT_1003031c)(param_1,2,param_3);
    }
    DAT_1002ffe8 = DAT_1002ffe8 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001b63c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001b6dc) */
/* WARNING: Removing unreachable block (ram,0x1001b689) */
/* WARNING: Removing unreachable block (ram,0x1001b709) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1002fdc0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002ffe8 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10004010(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10004010(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1001b747();
  return local_20;
}



// Function: FUN_1001b747 at 1001b747

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b747(void)

{
  _DAT_1002fdc0 = 0xffffffff;
  return;
}



// Function: entry at 1001b752

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1001b775

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
  
  _DAT_10030108 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1003010c = &stack0x00000004;
  _DAT_10030048 = 0x10001;
  _DAT_1002fff0 = 0xc0000409;
  _DAT_1002fff4 = 1;
  local_32c = DAT_1002fdb0;
  local_328 = DAT_1002fdb4;
  _DAT_1002fffc = unaff_retaddr;
  _DAT_100300d4 = in_GS;
  _DAT_100300d8 = in_FS;
  _DAT_100300dc = in_ES;
  _DAT_100300e0 = in_DS;
  _DAT_100300e4 = unaff_EDI;
  _DAT_100300e8 = unaff_ESI;
  _DAT_100300ec = unaff_EBX;
  _DAT_100300f0 = in_EDX;
  _DAT_100300f4 = in_ECX;
  _DAT_100300f8 = in_EAX;
  _DAT_100300fc = unaff_EBP;
  DAT_10030100 = unaff_retaddr;
  _DAT_10030104 = in_CS;
  _DAT_10030110 = in_SS;
  DAT_10030040 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10023328);
  if (DAT_10030040 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1001b880

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002fdb0 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1001b8c5

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



// Function: __ValidateImageBase at 1001b950

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



// Function: __FindPESection at 1001b990

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



// Function: __IsNonwritableInCurrentImage at 1001b9e0

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_1001b2bc;
  local_14 = ExceptionList;
  local_c = DAT_1002fdb0 ^ 0x1002a970;
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



// Function: ___security_init_cookie at 1001bab4

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
  if ((DAT_1002fdb0 == 0xbb40e64e) || ((DAT_1002fdb0 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1002fdb0 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1002fdb0 == 0xbb40e64e) {
      DAT_1002fdb0 = 0xbb40e64f;
    }
    else if ((DAT_1002fdb0 & 0xffff0000) == 0) {
      DAT_1002fdb0 = DAT_1002fdb0 | (DAT_1002fdb0 | 0x4711) << 0x10;
    }
    DAT_1002fdb4 = ~DAT_1002fdb0;
  }
  else {
    DAT_1002fdb4 = ~DAT_1002fdb0;
  }
  return;
}



// Function: Unwind@1001bb60 at 1001bb60

void Unwind_1001bb60(void)

{
  DAT_1002fe18 = DAT_1002fe18 & 0xfffffffe;
  return;
}



// Function: Unwind@1001bb90 at 1001bb90

void Unwind_1001bb90(void)

{
  int unaff_EBP;
  
  FUN_10001440(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bbc0 at 1001bbc0

void Unwind_1001bbc0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bbf0 at 1001bbf0

void Unwind_1001bbf0(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bc20 at 1001bc20

void Unwind_1001bc20(void)

{
  int unaff_EBP;
  
  FUN_100021e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bc50 at 1001bc50

void Unwind_1001bc50(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001bc90 at 1001bc90

void Unwind_1001bc90(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bcc0 at 1001bcc0

void Unwind_1001bcc0(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1001bd00 at 1001bd00

void Unwind_1001bd00(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bd03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd30 at 1001bd30

void Unwind_1001bd30(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bd33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd60 at 1001bd60

void Unwind_1001bd60(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bd6b at 1001bd6b

void Unwind_1001bd6b(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bd90 at 1001bd90

void Unwind_1001bd90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bd93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bdc0 at 1001bdc0

void Unwind_1001bdc0(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001bdcb at 1001bdcb

void Unwind_1001bdcb(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bdf0 at 1001bdf0

void Unwind_1001bdf0(void)

{
  int unaff_EBP;
  
  FUN_10002b00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001be20 at 1001be20

void Unwind_1001be20(void)

{
  int unaff_EBP;
  
  FUN_10002b00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001be50 at 1001be50

void Unwind_1001be50(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be58 at 1001be58

void Unwind_1001be58(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be60 at 1001be60

void Unwind_1001be60(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001be68 at 1001be68

void Unwind_1001be68(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001be70 at 1001be70

void Unwind_1001be70(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001be78 at 1001be78

void Unwind_1001be78(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bea0 at 1001bea0

void Unwind_1001bea0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bea3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bed0 at 1001bed0

void Unwind_1001bed0(void)

{
  int unaff_EBP;
  
  FUN_10003320((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bed8 at 1001bed8

void Unwind_1001bed8(void)

{
  int unaff_EBP;
  
  FUN_10002b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bf00 at 1001bf00

void Unwind_1001bf00(void)

{
  int unaff_EBP;
  
  FUN_10002230(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bf08 at 1001bf08

void Unwind_1001bf08(void)

{
  int unaff_EBP;
  
  FUN_100021e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bf30 at 1001bf30

void Unwind_1001bf30(void)

{
  int unaff_EBP;
  
  FUN_10003110(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bf60 at 1001bf60

void Unwind_1001bf60(void)

{
  int unaff_EBP;
  
  FUN_100041b0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001bf6b at 1001bf6b

void Unwind_1001bf6b(void)

{
  int unaff_EBP;
  
  FUN_10003110(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bf90 at 1001bf90

void Unwind_1001bf90(void)

{
  int unaff_EBP;
  
  FUN_100018a0(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1001bfc0 at 1001bfc0

void Unwind_1001bfc0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001bfcb at 1001bfcb

void Unwind_1001bfcb(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001bfd6 at 1001bfd6

void Unwind_1001bfd6(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001bfe1 at 1001bfe1

void Unwind_1001bfe1(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001bfec at 1001bfec

void Unwind_1001bfec(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001bff7 at 1001bff7

void Unwind_1001bff7(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1001c002 at 1001c002

void Unwind_1001c002(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@1001c00d at 1001c00d

void Unwind_1001c00d(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@1001c018 at 1001c018

void Unwind_1001c018(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001c023 at 1001c023

void Unwind_1001c023(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001c060 at 1001c060

void Unwind_1001c060(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c068 at 1001c068

void Unwind_1001c068(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c070 at 1001c070

void Unwind_1001c070(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c078 at 1001c078

void Unwind_1001c078(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c0a0 at 1001c0a0

void Unwind_1001c0a0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001c0ab at 1001c0ab

void Unwind_1001c0ab(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c0b6 at 1001c0b6

void Unwind_1001c0b6(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c0c1 at 1001c0c1

void Unwind_1001c0c1(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c0cc at 1001c0cc

void Unwind_1001c0cc(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c100 at 1001c100

void Unwind_1001c100(void)

{
  int unaff_EBP;
  
  FUN_10003440((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c130 at 1001c130

void Unwind_1001c130(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c13b at 1001c13b

void Unwind_1001c13b(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c146 at 1001c146

void Unwind_1001c146(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c170 at 1001c170

void Unwind_1001c170(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c17b at 1001c17b

void Unwind_1001c17b(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c186 at 1001c186

void Unwind_1001c186(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c1b0 at 1001c1b0

void Unwind_1001c1b0(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c1bb at 1001c1bb

void Unwind_1001c1bb(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c1c6 at 1001c1c6

void Unwind_1001c1c6(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c1f0 at 1001c1f0

void Unwind_1001c1f0(void)

{
  int unaff_EBP;
  
  FUN_10003320((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c1f8 at 1001c1f8

void Unwind_1001c1f8(void)

{
  int unaff_EBP;
  
  FUN_10002b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c220 at 1001c220

void Unwind_1001c220(void)

{
  FUN_10002100();
  return;
}



// Function: Unwind@1001c250 at 1001c250

void Unwind_1001c250(void)

{
  int unaff_EBP;
  
  FUN_10003320((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c258 at 1001c258

void Unwind_1001c258(void)

{
  int unaff_EBP;
  
  FUN_10002b00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c280 at 1001c280

void Unwind_1001c280(void)

{
  FUN_10002100();
  return;
}



// Function: Unwind@1001c299 at 1001c299

void Unwind_1001c299(void)

{
  FUN_10002100();
  return;
}



// Function: Unwind@1001c310 at 1001c310

void Unwind_1001c310(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c316. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001c31c at 1001c31c

void Unwind_1001c31c(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001c327 at 1001c327

void Unwind_1001c327(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c32a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c350 at 1001c350

void Unwind_1001c350(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c356. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001c35c at 1001c35c

void Unwind_1001c35c(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@1001c367 at 1001c367

void Unwind_1001c367(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c36a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c390 at 1001c390

void Unwind_1001c390(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001c3a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@1001c3ad at 1001c3ad

void Unwind_1001c3ad(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c3b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001c3b9 at 1001c3b9

void Unwind_1001c3b9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c3bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c3c2 at 1001c3c2

void Unwind_1001c3c2(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c3f0 at 1001c3f0

void Unwind_1001c3f0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c3f8 at 1001c3f8

void Unwind_1001c3f8(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c403 at 1001c403

void Unwind_1001c403(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c40e at 1001c40e

void Unwind_1001c40e(void)

{
  int unaff_EBP;
  
  FUN_100050e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c440 at 1001c440

void Unwind_1001c440(void)

{
  int unaff_EBP;
  
  FUN_100031c0((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c448 at 1001c448

void Unwind_1001c448(void)

{
  int unaff_EBP;
  
  FUN_100031c0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c470 at 1001c470

void Unwind_1001c470(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c4a0 at 1001c4a0

void Unwind_1001c4a0(void)

{
  int unaff_EBP;
  
  FUN_100050e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c4a8 at 1001c4a8

void Unwind_1001c4a8(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c4b3 at 1001c4b3

void Unwind_1001c4b3(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c4be at 1001c4be

void Unwind_1001c4be(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c4f0 at 1001c4f0

void Unwind_1001c4f0(void)

{
  int unaff_EBP;
  
  FUN_100031e0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1001c4fb at 1001c4fb

void Unwind_1001c4fb(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1001c506 at 1001c506

void Unwind_1001c506(void)

{
  int unaff_EBP;
  
  FUN_100031e0((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1001c540 at 1001c540

void Unwind_1001c540(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x2228));
  return;
}



// Function: Unwind@1001c54b at 1001c54b

void Unwind_1001c54b(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@1001c556 at 1001c556

void Unwind_1001c556(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1001c561 at 1001c561

void Unwind_1001c561(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@1001c56c at 1001c56c

void Unwind_1001c56c(void)

{
  int unaff_EBP;
  
  FUN_100022b0((undefined4 *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@1001c5a0 at 1001c5a0

void Unwind_1001c5a0(void)

{
  int unaff_EBP;
  
  FUN_10003440((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5d0 at 1001c5d0

void Unwind_1001c5d0(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5d8 at 1001c5d8

void Unwind_1001c5d8(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001c5e3 at 1001c5e3

void Unwind_1001c5e3(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001c5ee at 1001c5ee

void Unwind_1001c5ee(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5f6 at 1001c5f6

void Unwind_1001c5f6(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c601 at 1001c601

void Unwind_1001c601(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c60c at 1001c60c

void Unwind_1001c60c(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c630 at 1001c630

void Unwind_1001c630(void)

{
  int unaff_EBP;
  
  FUN_100071c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c660 at 1001c660

void Unwind_1001c660(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c668 at 1001c668

void Unwind_1001c668(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001c673 at 1001c673

void Unwind_1001c673(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001c67e at 1001c67e

void Unwind_1001c67e(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001c689 at 1001c689

void Unwind_1001c689(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001c694 at 1001c694

void Unwind_1001c694(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c69c at 1001c69c

void Unwind_1001c69c(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c6a7 at 1001c6a7

void Unwind_1001c6a7(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c6b2 at 1001c6b2

void Unwind_1001c6b2(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c6e0 at 1001c6e0

void Unwind_1001c6e0(void)

{
  int unaff_EBP;
  
  FUN_100072c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c710 at 1001c710

void Unwind_1001c710(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c718 at 1001c718

void Unwind_1001c718(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001c723 at 1001c723

void Unwind_1001c723(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001c72e at 1001c72e

void Unwind_1001c72e(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001c739 at 1001c739

void Unwind_1001c739(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@1001c747 at 1001c747

void Unwind_1001c747(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}



// Function: Unwind@1001c755 at 1001c755

void Unwind_1001c755(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@1001c763 at 1001c763

void Unwind_1001c763(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc4));
  return;
}



// Function: Unwind@1001c771 at 1001c771

void Unwind_1001c771(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c779 at 1001c779

void Unwind_1001c779(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c784 at 1001c784

void Unwind_1001c784(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c78f at 1001c78f

void Unwind_1001c78f(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c7c0 at 1001c7c0

void Unwind_1001c7c0(void)

{
  int unaff_EBP;
  
  FUN_10007410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c7f0 at 1001c7f0

void Unwind_1001c7f0(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c7f8 at 1001c7f8

void Unwind_1001c7f8(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001c803 at 1001c803

void Unwind_1001c803(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001c80e at 1001c80e

void Unwind_1001c80e(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c819 at 1001c819

void Unwind_1001c819(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c824 at 1001c824

void Unwind_1001c824(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c850 at 1001c850

void Unwind_1001c850(void)

{
  int unaff_EBP;
  
  FUN_100075d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c880 at 1001c880

void Unwind_1001c880(void)

{
  int unaff_EBP;
  
  FUN_10003440((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001c88b at 1001c88b

void Unwind_1001c88b(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c896 at 1001c896

void Unwind_1001c896(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001c8a1 at 1001c8a1

void Unwind_1001c8a1(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001c8ac at 1001c8ac

void Unwind_1001c8ac(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c8b7 at 1001c8b7

void Unwind_1001c8b7(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c8c2 at 1001c8c2

void Unwind_1001c8c2(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c8cd at 1001c8cd

void Unwind_1001c8cd(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c8d8 at 1001c8d8

void Unwind_1001c8d8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c8e3 at 1001c8e3

void Unwind_1001c8e3(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c8ee at 1001c8ee

void Unwind_1001c8ee(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001c950 at 1001c950

void Unwind_1001c950(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001c95c at 1001c95c

void Unwind_1001c95c(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001c967 at 1001c967

void Unwind_1001c967(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c96a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c990 at 1001c990

void Unwind_1001c990(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c9c0 at 1001c9c0

void Unwind_1001c9c0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c9c8 at 1001c9c8

void Unwind_1001c9c8(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c9d3 at 1001c9d3

void Unwind_1001c9d3(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c9de at 1001c9de

void Unwind_1001c9de(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c9e6 at 1001c9e6

void Unwind_1001c9e6(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001c9f1 at 1001c9f1

void Unwind_1001c9f1(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c9f9 at 1001c9f9

void Unwind_1001c9f9(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001ca20 at 1001ca20

void Unwind_1001ca20(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ca2b at 1001ca2b

void Unwind_1001ca2b(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ca50 at 1001ca50

void Unwind_1001ca50(void)

{
  int unaff_EBP;
  
  FUN_100081b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ca80 at 1001ca80

void Unwind_1001ca80(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001cad0 at 1001cad0

void Unwind_1001cad0(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cad8 at 1001cad8

void Unwind_1001cad8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001cae3 at 1001cae3

void Unwind_1001cae3(void)

{
  int unaff_EBP;
  
  FUN_100081b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001caeb at 1001caeb

void Unwind_1001caeb(void)

{
  int unaff_EBP;
  
  FUN_100082d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb10 at 1001cb10

void Unwind_1001cb10(void)

{
  int unaff_EBP;
  
  FUN_100082d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb18 at 1001cb18

void Unwind_1001cb18(void)

{
  int unaff_EBP;
  
  FUN_100081b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb40 at 1001cb40

void Unwind_1001cb40(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cb48 at 1001cb48

void Unwind_1001cb48(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001cb53 at 1001cb53

void Unwind_1001cb53(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001cb5e at 1001cb5e

void Unwind_1001cb5e(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb66 at 1001cb66

void Unwind_1001cb66(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001cb71 at 1001cb71

void Unwind_1001cb71(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001cb7c at 1001cb7c

void Unwind_1001cb7c(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cb84 at 1001cb84

void Unwind_1001cb84(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001cb8f at 1001cb8f

void Unwind_1001cb8f(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001cc20 at 1001cc20

void Unwind_1001cc20(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cc28 at 1001cc28

void Unwind_1001cc28(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001cc33 at 1001cc33

void Unwind_1001cc33(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001cc3e at 1001cc3e

void Unwind_1001cc3e(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cc46 at 1001cc46

void Unwind_1001cc46(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001cc51 at 1001cc51

void Unwind_1001cc51(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001cc5c at 1001cc5c

void Unwind_1001cc5c(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001cc67 at 1001cc67

void Unwind_1001cc67(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@1001cc75 at 1001cc75

void Unwind_1001cc75(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}



// Function: Unwind@1001cc83 at 1001cc83

void Unwind_1001cc83(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cc8b at 1001cc8b

void Unwind_1001cc8b(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@1001cc99 at 1001cc99

void Unwind_1001cc99(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc4));
  return;
}



// Function: Unwind@1001ccf0 at 1001ccf0

void Unwind_1001ccf0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001cda0 at 1001cda0

void Unwind_1001cda0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cda8 at 1001cda8

void Unwind_1001cda8(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001cdb3 at 1001cdb3

void Unwind_1001cdb3(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001cdbe at 1001cdbe

void Unwind_1001cdbe(void)

{
  int unaff_EBP;
  
  FUN_10005070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cdc6 at 1001cdc6

void Unwind_1001cdc6(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001cdd1 at 1001cdd1

void Unwind_1001cdd1(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1001ce00 at 1001ce00

void Unwind_1001ce00(void)

{
  int unaff_EBP;
  
  FUN_10002110(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ce08 at 1001ce08

void Unwind_1001ce08(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ce30 at 1001ce30

void Unwind_1001ce30(void)

{
  int unaff_EBP;
  
  FUN_10009db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ce38 at 1001ce38

void Unwind_1001ce38(void)

{
  int unaff_EBP;
  
  FUN_10002110(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ce80 at 1001ce80

void Unwind_1001ce80(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001ceb0 at 1001ceb0

void Unwind_1001ceb0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ceb8 at 1001ceb8

void Unwind_1001ceb8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cec0 at 1001cec0

void Unwind_1001cec0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001cec8 at 1001cec8

void Unwind_1001cec8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ced0 at 1001ced0

void Unwind_1001ced0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ced8 at 1001ced8

void Unwind_1001ced8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cee0 at 1001cee0

void Unwind_1001cee0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cee8 at 1001cee8

void Unwind_1001cee8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cef0 at 1001cef0

void Unwind_1001cef0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001cef8 at 1001cef8

void Unwind_1001cef8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001cf00 at 1001cf00

void Unwind_1001cf00(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001cf08 at 1001cf08

void Unwind_1001cf08(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001cf10 at 1001cf10

void Unwind_1001cf10(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001cf18 at 1001cf18

void Unwind_1001cf18(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001cf20 at 1001cf20

void Unwind_1001cf20(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001cf28 at 1001cf28

void Unwind_1001cf28(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001cf30 at 1001cf30

void Unwind_1001cf30(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cf38 at 1001cf38

void Unwind_1001cf38(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cf40 at 1001cf40

void Unwind_1001cf40(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001cf48 at 1001cf48

void Unwind_1001cf48(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cf90 at 1001cf90

void Unwind_1001cf90(void)

{
  int unaff_EBP;
  
  FUN_10007a80(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cfc0 at 1001cfc0

void Unwind_1001cfc0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001cfd3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1001cfda at 1001cfda

void Unwind_1001cfda(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001cfe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001cfe6 at 1001cfe6

void Unwind_1001cfe6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001cfe9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cfef at 1001cfef

void Unwind_1001cfef(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001cffa at 1001cffa

void Unwind_1001cffa(void)

{
  int unaff_EBP;
  
  FUN_10007ab0((int *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001d005 at 1001d005

void Unwind_1001d005(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d00b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 8) + -0x48));
  return;
}



// Function: Unwind@1001d011 at 1001d011

void Unwind_1001d011(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 8) + -0x48));
  return;
}



// Function: Unwind@1001d01c at 1001d01c

void Unwind_1001d01c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d01f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d050 at 1001d050

void Unwind_1001d050(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001d063. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -100));
    return;
  }
  return;
}



// Function: Unwind@1001d06a at 1001d06a

void Unwind_1001d06a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001d076 at 1001d076

void Unwind_1001d076(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d079. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d07f at 1001d07f

void Unwind_1001d07f(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001d08a at 1001d08a

void Unwind_1001d08a(void)

{
  int unaff_EBP;
  
  FUN_10007ab0((int *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001d095 at 1001d095

void Unwind_1001d095(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d09b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_istream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001d0a1 at 1001d0a1

void Unwind_1001d0a1(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001d0ac at 1001d0ac

void Unwind_1001d0ac(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001d0af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d0e0 at 1001d0e0

void Unwind_1001d0e0(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d110 at 1001d110

void Unwind_1001d110(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d140 at 1001d140

void Unwind_1001d140(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1001d14b at 1001d14b

void Unwind_1001d14b(void)

{
  int unaff_EBP;
  
  FUN_100031e0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001d180 at 1001d180

void Unwind_1001d180(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d1b0 at 1001d1b0

void Unwind_1001d1b0(void)

{
  int unaff_EBP;
  
  FUN_10003110(*(undefined4 **)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1001d1bb at 1001d1bb

void Unwind_1001d1bb(void)

{
  int unaff_EBP;
  
  FUN_100041b0((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001d1c6 at 1001d1c6

void Unwind_1001d1c6(void)

{
  int unaff_EBP;
  
  FUN_10004230((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001d1d1 at 1001d1d1

void Unwind_1001d1d1(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1001d1dc at 1001d1dc

void Unwind_1001d1dc(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001d210 at 1001d210

void Unwind_1001d210(void)

{
  int unaff_EBP;
  
  FUN_100071c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d240 at 1001d240

void Unwind_1001d240(void)

{
  int unaff_EBP;
  
  FUN_10003110(*(undefined4 **)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001d24b at 1001d24b

void Unwind_1001d24b(void)

{
  int unaff_EBP;
  
  FUN_100041b0((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001d256 at 1001d256

void Unwind_1001d256(void)

{
  int unaff_EBP;
  
  FUN_10004230((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001d261 at 1001d261

void Unwind_1001d261(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001d26c at 1001d26c

void Unwind_1001d26c(void)

{
  int unaff_EBP;
  
  FUN_10002040((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001d2a0 at 1001d2a0

void Unwind_1001d2a0(void)

{
  int unaff_EBP;
  
  FUN_100071c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d2a8 at 1001d2a8

void Unwind_1001d2a8(void)

{
  int unaff_EBP;
  
  FUN_10007270(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d2d0 at 1001d2d0

void Unwind_1001d2d0(void)

{
  int unaff_EBP;
  
  FUN_10007270(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d2db at 1001d2db

void Unwind_1001d2db(void)

{
  int unaff_EBP;
  
  FUN_100071c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d300 at 1001d300

void Unwind_1001d300(void)

{
  int unaff_EBP;
  
  FUN_100072c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d330 at 1001d330

void Unwind_1001d330(void)

{
  int unaff_EBP;
  
  FUN_100072c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d338 at 1001d338

void Unwind_1001d338(void)

{
  int unaff_EBP;
  
  FUN_100073c0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d360 at 1001d360

void Unwind_1001d360(void)

{
  int unaff_EBP;
  
  FUN_100073c0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d36b at 1001d36b

void Unwind_1001d36b(void)

{
  int unaff_EBP;
  
  FUN_100072c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d390 at 1001d390

void Unwind_1001d390(void)

{
  int unaff_EBP;
  
  FUN_10007410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d3c0 at 1001d3c0

void Unwind_1001d3c0(void)

{
  int unaff_EBP;
  
  FUN_10007410(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d3c8 at 1001d3c8

void Unwind_1001d3c8(void)

{
  int unaff_EBP;
  
  FUN_10007580(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d3f0 at 1001d3f0

void Unwind_1001d3f0(void)

{
  int unaff_EBP;
  
  FUN_10007580(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d3fb at 1001d3fb

void Unwind_1001d3fb(void)

{
  int unaff_EBP;
  
  FUN_10007410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d420 at 1001d420

void Unwind_1001d420(void)

{
  int unaff_EBP;
  
  FUN_100075d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d450 at 1001d450

void Unwind_1001d450(void)

{
  int unaff_EBP;
  
  FUN_100075d0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d458 at 1001d458

void Unwind_1001d458(void)

{
  int unaff_EBP;
  
  FUN_10007690(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d480 at 1001d480

void Unwind_1001d480(void)

{
  int unaff_EBP;
  
  FUN_10007690(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001d48b at 1001d48b

void Unwind_1001d48b(void)

{
  int unaff_EBP;
  
  FUN_100075d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d4b0 at 1001d4b0

void Unwind_1001d4b0(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d4bb at 1001d4bb

void Unwind_1001d4bb(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d4c6 at 1001d4c6

void Unwind_1001d4c6(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d4d1 at 1001d4d1

void Unwind_1001d4d1(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d500 at 1001d500

void Unwind_1001d500(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d50b at 1001d50b

void Unwind_1001d50b(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d516 at 1001d516

void Unwind_1001d516(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d521 at 1001d521

void Unwind_1001d521(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d550 at 1001d550

void Unwind_1001d550(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d55b at 1001d55b

void Unwind_1001d55b(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d566 at 1001d566

void Unwind_1001d566(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d571 at 1001d571

void Unwind_1001d571(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d5a0 at 1001d5a0

void Unwind_1001d5a0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d5a8 at 1001d5a8

void Unwind_1001d5a8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002110((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1001d5c1 at 1001d5c1

void Unwind_1001d5c1(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d5c9 at 1001d5c9

void Unwind_1001d5c9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_10002110((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1001d5e2 at 1001d5e2

void Unwind_1001d5e2(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d5ea at 1001d5ea

void Unwind_1001d5ea(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d630 at 1001d630

void Unwind_1001d630(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d680 at 1001d680

void Unwind_1001d680(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d6d0 at 1001d6d0

void Unwind_1001d6d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d720 at 1001d720

void Unwind_1001d720(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d750 at 1001d750

void Unwind_1001d750(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d758 at 1001d758

void Unwind_1001d758(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001d763 at 1001d763

void Unwind_1001d763(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d76e at 1001d76e

void Unwind_1001d76e(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((_Container_base0 *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@1001d779 at 1001d779

void Unwind_1001d779(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d784 at 1001d784

void Unwind_1001d784(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d7b0 at 1001d7b0

void Unwind_1001d7b0(void)

{
  int unaff_EBP;
  
  FUN_1000d780(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d7b8 at 1001d7b8

void Unwind_1001d7b8(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d7c0 at 1001d7c0

void Unwind_1001d7c0(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d7cb at 1001d7cb

void Unwind_1001d7cb(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d7d6 at 1001d7d6

void Unwind_1001d7d6(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d7e1 at 1001d7e1

void Unwind_1001d7e1(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d810 at 1001d810

void Unwind_1001d810(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d818 at 1001d818

void Unwind_1001d818(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001d823 at 1001d823

void Unwind_1001d823(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d82e at 1001d82e

void Unwind_1001d82e(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((_Container_base0 *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@1001d839 at 1001d839

void Unwind_1001d839(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d844 at 1001d844

void Unwind_1001d844(void)

{
  int unaff_EBP;
  
  FUN_1000ca30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d870 at 1001d870

void Unwind_1001d870(void)

{
  int unaff_EBP;
  
  FUN_1000ca30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d878 at 1001d878

void Unwind_1001d878(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d883 at 1001d883

void Unwind_1001d883(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d88e at 1001d88e

void Unwind_1001d88e(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d899 at 1001d899

void Unwind_1001d899(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d8c0 at 1001d8c0

void Unwind_1001d8c0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d8c8 at 1001d8c8

void Unwind_1001d8c8(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001d8d3 at 1001d8d3

void Unwind_1001d8d3(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d8de at 1001d8de

void Unwind_1001d8de(void)

{
  int unaff_EBP;
  
  FUN_10007ca0((_Container_base0 *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@1001d8e9 at 1001d8e9

void Unwind_1001d8e9(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d8f4 at 1001d8f4

void Unwind_1001d8f4(void)

{
  int unaff_EBP;
  
  FUN_1000cab0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d920 at 1001d920

void Unwind_1001d920(void)

{
  int unaff_EBP;
  
  FUN_1000cab0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d928 at 1001d928

void Unwind_1001d928(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d933 at 1001d933

void Unwind_1001d933(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d93e at 1001d93e

void Unwind_1001d93e(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d949 at 1001d949

void Unwind_1001d949(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d970 at 1001d970

void Unwind_1001d970(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d978 at 1001d978

void Unwind_1001d978(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d983 at 1001d983

void Unwind_1001d983(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d98e at 1001d98e

void Unwind_1001d98e(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d999 at 1001d999

void Unwind_1001d999(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d9c0 at 1001d9c0

void Unwind_1001d9c0(void)

{
  int unaff_EBP;
  
  FUN_1000d970(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d9c8 at 1001d9c8

void Unwind_1001d9c8(void)

{
  int unaff_EBP;
  
  FUN_1000ca30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d9d0 at 1001d9d0

void Unwind_1001d9d0(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001d9db at 1001d9db

void Unwind_1001d9db(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001d9e6 at 1001d9e6

void Unwind_1001d9e6(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001d9f1 at 1001d9f1

void Unwind_1001d9f1(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001da20 at 1001da20

void Unwind_1001da20(void)

{
  int unaff_EBP;
  
  FUN_1000db60(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001da28 at 1001da28

void Unwind_1001da28(void)

{
  int unaff_EBP;
  
  FUN_1000cab0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001da30 at 1001da30

void Unwind_1001da30(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001da3b at 1001da3b

void Unwind_1001da3b(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001da46 at 1001da46

void Unwind_1001da46(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001da51 at 1001da51

void Unwind_1001da51(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001daa0 at 1001daa0

void Unwind_1001daa0(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001dad0 at 1001dad0

void Unwind_1001dad0(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001db00 at 1001db00

void Unwind_1001db00(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10007a80(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001db40 at 1001db40

void Unwind_1001db40(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001db48 at 1001db48

void Unwind_1001db48(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001db80 at 1001db80

void Unwind_1001db80(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001db88 at 1001db88

void Unwind_1001db88(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001db90 at 1001db90

void Unwind_1001db90(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001dbc0 at 1001dbc0

void Unwind_1001dbc0(void)

{
  int unaff_EBP;
  
  FUN_1000d780(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dbf0 at 1001dbf0

void Unwind_1001dbf0(void)

{
  int unaff_EBP;
  
  FUN_1000d780(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dbf8 at 1001dbf8

void Unwind_1001dbf8(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dc00 at 1001dc00

void Unwind_1001dc00(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001dc0b at 1001dc0b

void Unwind_1001dc0b(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001dc16 at 1001dc16

void Unwind_1001dc16(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001dc21 at 1001dc21

void Unwind_1001dc21(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dc50 at 1001dc50

void Unwind_1001dc50(void)

{
  int unaff_EBP;
  
  FUN_1000d780(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001dc58 at 1001dc58

void Unwind_1001dc58(void)

{
  int unaff_EBP;
  
  FUN_1000d800(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001dc80 at 1001dc80

void Unwind_1001dc80(void)

{
  int unaff_EBP;
  
  FUN_1000d800(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001dc8b at 1001dc8b

void Unwind_1001dc8b(void)

{
  int unaff_EBP;
  
  FUN_1000d780(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dc93 at 1001dc93

void Unwind_1001dc93(void)

{
  int unaff_EBP;
  
  FUN_1000c9b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dc9b at 1001dc9b

void Unwind_1001dc9b(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001dca6 at 1001dca6

void Unwind_1001dca6(void)

{
  int unaff_EBP;
  
  FUN_1000aa50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001dcb1 at 1001dcb1

void Unwind_1001dcb1(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001dcbc at 1001dcbc

void Unwind_1001dcbc(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dce0 at 1001dce0

void Unwind_1001dce0(void)

{
  int unaff_EBP;
  
  FUN_1000d970(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dd10 at 1001dd10

void Unwind_1001dd10(void)

{
  int unaff_EBP;
  
  FUN_1000d970(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dd18 at 1001dd18

void Unwind_1001dd18(void)

{
  int unaff_EBP;
  
  FUN_1000ca30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dd20 at 1001dd20

void Unwind_1001dd20(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001dd2b at 1001dd2b

void Unwind_1001dd2b(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001dd36 at 1001dd36

void Unwind_1001dd36(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001dd41 at 1001dd41

void Unwind_1001dd41(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dd70 at 1001dd70

void Unwind_1001dd70(void)

{
  int unaff_EBP;
  
  FUN_1000d970(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001dd78 at 1001dd78

void Unwind_1001dd78(void)

{
  int unaff_EBP;
  
  FUN_1000d9f0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001dda0 at 1001dda0

void Unwind_1001dda0(void)

{
  int unaff_EBP;
  
  FUN_1000d9f0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001ddab at 1001ddab

void Unwind_1001ddab(void)

{
  int unaff_EBP;
  
  FUN_1000d970(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ddb3 at 1001ddb3

void Unwind_1001ddb3(void)

{
  int unaff_EBP;
  
  FUN_1000ca30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ddbb at 1001ddbb

void Unwind_1001ddbb(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001ddc6 at 1001ddc6

void Unwind_1001ddc6(void)

{
  int unaff_EBP;
  
  FUN_1000ae30((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001ddd1 at 1001ddd1

void Unwind_1001ddd1(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001dddc at 1001dddc

void Unwind_1001dddc(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001de00 at 1001de00

void Unwind_1001de00(void)

{
  int unaff_EBP;
  
  FUN_1000db60(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001de30 at 1001de30

void Unwind_1001de30(void)

{
  int unaff_EBP;
  
  FUN_1000db60(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001de38 at 1001de38

void Unwind_1001de38(void)

{
  int unaff_EBP;
  
  FUN_1000cab0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001de40 at 1001de40

void Unwind_1001de40(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001de4b at 1001de4b

void Unwind_1001de4b(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001de56 at 1001de56

void Unwind_1001de56(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001de61 at 1001de61

void Unwind_1001de61(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001de90 at 1001de90

void Unwind_1001de90(void)

{
  int unaff_EBP;
  
  FUN_1000db60(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001de98 at 1001de98

void Unwind_1001de98(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001dec0 at 1001dec0

void Unwind_1001dec0(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001decb at 1001decb

void Unwind_1001decb(void)

{
  int unaff_EBP;
  
  FUN_1000db60(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ded3 at 1001ded3

void Unwind_1001ded3(void)

{
  int unaff_EBP;
  
  FUN_1000cab0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dedb at 1001dedb

void Unwind_1001dedb(void)

{
  int unaff_EBP;
  
  FUN_100031f0(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1001dee6 at 1001dee6

void Unwind_1001dee6(void)

{
  int unaff_EBP;
  
  FUN_1000b0c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001def1 at 1001def1

void Unwind_1001def1(void)

{
  int unaff_EBP;
  
  FUN_10002070((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001defc at 1001defc

void Unwind_1001defc(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001df20 at 1001df20

void Unwind_1001df20(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001df60 at 1001df60

void Unwind_1001df60(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + 0xc);
  return;
}



// Function: Unwind@1001df68 at 1001df68

void Unwind_1001df68(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001df70 at 1001df70

void Unwind_1001df70(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001dfb0 at 1001dfb0

void Unwind_1001dfb0(void)

{
  int unaff_EBP;
  
  FUN_10002d30(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001dfb8 at 1001dfb8

void Unwind_1001dfb8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001dff0 at 1001dff0

void Unwind_1001dff0(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001dff8 at 1001dff8

void Unwind_1001dff8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@1001e011 at 1001e011

void Unwind_1001e011(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e019 at 1001e019

void Unwind_1001e019(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e050 at 1001e050

void Unwind_1001e050(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e0a0 at 1001e0a0

void Unwind_1001e0a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e0f0 at 1001e0f0

void Unwind_1001e0f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e140 at 1001e140

void Unwind_1001e140(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e170 at 1001e170

void Unwind_1001e170(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e178 at 1001e178

void Unwind_1001e178(void)

{
  int unaff_EBP;
  
  FUN_10009a50((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001e180 at 1001e180

void Unwind_1001e180(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001e1b0 at 1001e1b0

void Unwind_1001e1b0(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e1b8 at 1001e1b8

void Unwind_1001e1b8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1001e200 at 1001e200

void Unwind_1001e200(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001e213. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1001e21a at 1001e21a

void Unwind_1001e21a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001e226 at 1001e226

void Unwind_1001e226(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e229. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e22f at 1001e22f

void Unwind_1001e22f(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001e23a at 1001e23a

void Unwind_1001e23a(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001e245 at 1001e245

void Unwind_1001e245(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e24d at 1001e24d

void Unwind_1001e24d(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e255 at 1001e255

void Unwind_1001e255(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001e25d at 1001e25d

void Unwind_1001e25d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001e276 at 1001e276

void Unwind_1001e276(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e27e at 1001e27e

void Unwind_1001e27e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 0xc) + -0x48));
  return;
}



// Function: Unwind@1001e28a at 1001e28a

void Unwind_1001e28a(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 0xc) + -0x4c));
  return;
}



// Function: Unwind@1001e295 at 1001e295

void Unwind_1001e295(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e2c0 at 1001e2c0

void Unwind_1001e2c0(void)

{
  DAT_1002fe2c = DAT_1002fe2c & 0xfffffffe;
  return;
}



// Function: Unwind@1001e2f0 at 1001e2f0

void Unwind_1001e2f0(void)

{
  DAT_1002fe40 = DAT_1002fe40 & 0xfffffffe;
  return;
}



// Function: Unwind@1001e320 at 1001e320

void Unwind_1001e320(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001e328 at 1001e328

void Unwind_1001e328(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001e330 at 1001e330

void Unwind_1001e330(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x48) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x48) = *(uint *)(unaff_EBP + -0x48) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001e346. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x90));
    return;
  }
  return;
}



// Function: Unwind@1001e34d at 1001e34d

void Unwind_1001e34d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e353. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001e359 at 1001e359

void Unwind_1001e359(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e35c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001e362 at 1001e362

void Unwind_1001e362(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001e36d at 1001e36d

void Unwind_1001e36d(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@1001e378 at 1001e378

void Unwind_1001e378(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e380 at 1001e380

void Unwind_1001e380(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001e388 at 1001e388

void Unwind_1001e388(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e390 at 1001e390

void Unwind_1001e390(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001e398 at 1001e398

void Unwind_1001e398(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001e3a0 at 1001e3a0

void Unwind_1001e3a0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001e3a8 at 1001e3a8

void Unwind_1001e3a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e3ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x40) + -0x48));
  return;
}



// Function: Unwind@1001e3b4 at 1001e3b4

void Unwind_1001e3b4(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x40) + -0x4c));
  return;
}



// Function: Unwind@1001e3bf at 1001e3bf

void Unwind_1001e3bf(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e3c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001e3c8 at 1001e3c8

void Unwind_1001e3c8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001e400 at 1001e400

void Unwind_1001e400(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e408 at 1001e408

void Unwind_1001e408(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e410 at 1001e410

void Unwind_1001e410(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@1001e418 at 1001e418

void Unwind_1001e418(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001e420 at 1001e420

void Unwind_1001e420(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001e428 at 1001e428

void Unwind_1001e428(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e460 at 1001e460

void Unwind_1001e460(void)

{
  DAT_1002fe54 = DAT_1002fe54 & 0xfffffffe;
  return;
}



// Function: Unwind@1001e490 at 1001e490

void Unwind_1001e490(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001e4a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x5c));
    return;
  }
  return;
}



// Function: Unwind@1001e4aa at 1001e4aa

void Unwind_1001e4aa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e4b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001e4b6 at 1001e4b6

void Unwind_1001e4b6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e4b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e4bf at 1001e4bf

void Unwind_1001e4bf(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001e4ca at 1001e4ca

void Unwind_1001e4ca(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001e4d5 at 1001e4d5

void Unwind_1001e4d5(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e4dd at 1001e4dd

void Unwind_1001e4dd(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e4e5 at 1001e4e5

void Unwind_1001e4e5(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001e4ed at 1001e4ed

void Unwind_1001e4ed(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e4f5 at 1001e4f5

void Unwind_1001e4f5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001e50e at 1001e50e

void Unwind_1001e50e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e514. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + 0xc) + -0x48));
  return;
}



// Function: Unwind@1001e51a at 1001e51a

void Unwind_1001e51a(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + 0xc) + -0x4c));
  return;
}



// Function: Unwind@1001e525 at 1001e525

void Unwind_1001e525(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001e550 at 1001e550

void Unwind_1001e550(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001e558 at 1001e558

void Unwind_1001e558(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001e56b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -100));
    return;
  }
  return;
}



// Function: Unwind@1001e572 at 1001e572

void Unwind_1001e572(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001e57e at 1001e57e

void Unwind_1001e57e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e581. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e587 at 1001e587

void Unwind_1001e587(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001e592 at 1001e592

void Unwind_1001e592(void)

{
  int unaff_EBP;
  
  FUN_10005d50((int *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001e59d at 1001e59d

void Unwind_1001e59d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x1c));
    return;
  }
  return;
}



// Function: Unwind@1001e5b6 at 1001e5b6

void Unwind_1001e5b6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e5bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1001e5c2 at 1001e5c2

void Unwind_1001e5c2(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1001e5cd at 1001e5cd

void Unwind_1001e5cd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e5d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e600 at 1001e600

void Unwind_1001e600(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001e613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@1001e61a at 1001e61a

void Unwind_1001e61a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001e626 at 1001e626

void Unwind_1001e626(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e629. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e62f at 1001e62f

void Unwind_1001e62f(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001e63a at 1001e63a

void Unwind_1001e63a(void)

{
  int unaff_EBP;
  
  FUN_10005d50((int *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1001e645 at 1001e645

void Unwind_1001e645(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001e65e at 1001e65e

void Unwind_1001e65e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1001e66a at 1001e66a

void Unwind_1001e66a(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + -0x48));
  return;
}



// Function: Unwind@1001e675 at 1001e675

void Unwind_1001e675(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001e678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e6a0 at 1001e6a0

void Unwind_1001e6a0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e6a8 at 1001e6a8

void Unwind_1001e6a8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e6b0 at 1001e6b0

void Unwind_1001e6b0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e6b8 at 1001e6b8

void Unwind_1001e6b8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e6c0 at 1001e6c0

void Unwind_1001e6c0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e6f0 at 1001e6f0

void Unwind_1001e6f0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e6f8 at 1001e6f8

void Unwind_1001e6f8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e700 at 1001e700

void Unwind_1001e700(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e708 at 1001e708

void Unwind_1001e708(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e710 at 1001e710

void Unwind_1001e710(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e740 at 1001e740

void Unwind_1001e740(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e748 at 1001e748

void Unwind_1001e748(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e750 at 1001e750

void Unwind_1001e750(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e758 at 1001e758

void Unwind_1001e758(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e760 at 1001e760

void Unwind_1001e760(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e790 at 1001e790

void Unwind_1001e790(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e798 at 1001e798

void Unwind_1001e798(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e7a0 at 1001e7a0

void Unwind_1001e7a0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e7a8 at 1001e7a8

void Unwind_1001e7a8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e7b0 at 1001e7b0

void Unwind_1001e7b0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e7e0 at 1001e7e0

void Unwind_1001e7e0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e7e8 at 1001e7e8

void Unwind_1001e7e8(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e7f0 at 1001e7f0

void Unwind_1001e7f0(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e7f8 at 1001e7f8

void Unwind_1001e7f8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e800 at 1001e800

void Unwind_1001e800(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e830 at 1001e830

void Unwind_1001e830(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e838 at 1001e838

void Unwind_1001e838(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e840 at 1001e840

void Unwind_1001e840(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e848 at 1001e848

void Unwind_1001e848(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e850 at 1001e850

void Unwind_1001e850(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e880 at 1001e880

void Unwind_1001e880(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e888 at 1001e888

void Unwind_1001e888(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e890 at 1001e890

void Unwind_1001e890(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001e898 at 1001e898

void Unwind_1001e898(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e8a0 at 1001e8a0

void Unwind_1001e8a0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e8d0 at 1001e8d0

void Unwind_1001e8d0(void)

{
  int unaff_EBP;
  
  FUN_10005900(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e8d8 at 1001e8d8

void Unwind_1001e8d8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001e910 at 1001e910

void Unwind_1001e910(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001e950 at 1001e950

void Unwind_1001e950(void)

{
  int unaff_EBP;
  
  FUN_100096e0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e958 at 1001e958

void Unwind_1001e958(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e960 at 1001e960

void Unwind_1001e960(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e968 at 1001e968

void Unwind_1001e968(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e970 at 1001e970

void Unwind_1001e970(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e978 at 1001e978

void Unwind_1001e978(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e980 at 1001e980

void Unwind_1001e980(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e988 at 1001e988

void Unwind_1001e988(void)

{
  int unaff_EBP;
  
  FUN_10009810((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001e990 at 1001e990

void Unwind_1001e990(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1001e998 at 1001e998

void Unwind_1001e998(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001e9a0 at 1001e9a0

void Unwind_1001e9a0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e9a8 at 1001e9a8

void Unwind_1001e9a8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e9d0 at 1001e9d0

void Unwind_1001e9d0(void)

{
  int unaff_EBP;
  
  FUN_100096e0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001e9d8 at 1001e9d8

void Unwind_1001e9d8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e9e0 at 1001e9e0

void Unwind_1001e9e0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001e9e8 at 1001e9e8

void Unwind_1001e9e8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e9f0 at 1001e9f0

void Unwind_1001e9f0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001e9f8 at 1001e9f8

void Unwind_1001e9f8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ea00 at 1001ea00

void Unwind_1001ea00(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ea08 at 1001ea08

void Unwind_1001ea08(void)

{
  int unaff_EBP;
  
  FUN_10009810((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ea10 at 1001ea10

void Unwind_1001ea10(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1001ea18 at 1001ea18

void Unwind_1001ea18(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ea20 at 1001ea20

void Unwind_1001ea20(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ea28 at 1001ea28

void Unwind_1001ea28(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ea50 at 1001ea50

void Unwind_1001ea50(void)

{
  int unaff_EBP;
  
  FUN_100096e0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ea58 at 1001ea58

void Unwind_1001ea58(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001ea80 at 1001ea80

void Unwind_1001ea80(void)

{
  int unaff_EBP;
  
  FUN_100096e0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ea88 at 1001ea88

void Unwind_1001ea88(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ea90 at 1001ea90

void Unwind_1001ea90(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ea98 at 1001ea98

void Unwind_1001ea98(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001eaa0 at 1001eaa0

void Unwind_1001eaa0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001eaa8 at 1001eaa8

void Unwind_1001eaa8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001eab0 at 1001eab0

void Unwind_1001eab0(void)

{
  int unaff_EBP;
  
  FUN_10002110((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001eab8 at 1001eab8

void Unwind_1001eab8(void)

{
  int unaff_EBP;
  
  FUN_10009810((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001eac0 at 1001eac0

void Unwind_1001eac0(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1001eac8 at 1001eac8

void Unwind_1001eac8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ead0 at 1001ead0

void Unwind_1001ead0(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ead8 at 1001ead8

void Unwind_1001ead8(void)

{
  int unaff_EBP;
  
  FUN_10009db0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001eb00 at 1001eb00

void Unwind_1001eb00(void)

{
  DAT_1002ff18 = DAT_1002ff18 & 0xfffffffe;
  return;
}



// Function: Unwind@1001eb0e at 1001eb0e

void Unwind_1001eb0e(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eb16 at 1001eb16

void Unwind_1001eb16(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002fe58);
  return;
}



// Function: Unwind@1001eb20 at 1001eb20

void Unwind_1001eb20(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002fe58);
  return;
}



// Function: Unwind@1001eb2a at 1001eb2a

void Unwind_1001eb2a(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eb32 at 1001eb32

void Unwind_1001eb32(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002fe78);
  return;
}



// Function: Unwind@1001eb3c at 1001eb3c

void Unwind_1001eb3c(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002fe78);
  return;
}



// Function: Unwind@1001eb46 at 1001eb46

void Unwind_1001eb46(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eb4e at 1001eb4e

void Unwind_1001eb4e(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002fe98);
  return;
}



// Function: Unwind@1001eb58 at 1001eb58

void Unwind_1001eb58(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002fe98);
  return;
}



// Function: Unwind@1001eb62 at 1001eb62

void Unwind_1001eb62(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eb6a at 1001eb6a

void Unwind_1001eb6a(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002feb8);
  return;
}



// Function: Unwind@1001eb74 at 1001eb74

void Unwind_1001eb74(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002feb8);
  return;
}



// Function: Unwind@1001eb7e at 1001eb7e

void Unwind_1001eb7e(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eb86 at 1001eb86

void Unwind_1001eb86(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002fed8);
  return;
}



// Function: Unwind@1001eb90 at 1001eb90

void Unwind_1001eb90(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002fed8);
  return;
}



// Function: Unwind@1001eb9a at 1001eb9a

void Unwind_1001eb9a(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001eba2 at 1001eba2

void Unwind_1001eba2(void)

{
  FUN_10007a80((undefined4 *)&DAT_1002fef8);
  return;
}



// Function: Unwind@1001ebac at 1001ebac

void Unwind_1001ebac(void)

{
  FUN_10009fd0((undefined4 *)&DAT_1002fef8);
  return;
}



// Function: Unwind@1001ebb6 at 1001ebb6

void Unwind_1001ebb6(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ebbe at 1001ebbe

void Unwind_1001ebbe(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x40));
    return;
  }
  return;
}



// Function: Unwind@1001ec00 at 1001ec00

void Unwind_1001ec00(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001ec16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x84));
    return;
  }
  return;
}



// Function: Unwind@1001ec1d at 1001ec1d

void Unwind_1001ec1d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ec23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001ec29 at 1001ec29

void Unwind_1001ec29(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ec2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ec32 at 1001ec32

void Unwind_1001ec32(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001ec3d at 1001ec3d

void Unwind_1001ec3d(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001ec48 at 1001ec48

void Unwind_1001ec48(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ec50 at 1001ec50

void Unwind_1001ec50(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@1001ec69 at 1001ec69

void Unwind_1001ec69(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ec6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x30) + -0x48));
  return;
}



// Function: Unwind@1001ec75 at 1001ec75

void Unwind_1001ec75(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x30) + -0x4c));
  return;
}



// Function: Unwind@1001ec80 at 1001ec80

void Unwind_1001ec80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ec83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001ecc0 at 1001ecc0

void Unwind_1001ecc0(void)

{
  int unaff_EBP;
  
  FUN_10007a80((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ecc8 at 1001ecc8

void Unwind_1001ecc8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1001ed10 at 1001ed10

void Unwind_1001ed10(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001ed26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa0));
    return;
  }
  return;
}



// Function: Unwind@1001ed2d at 1001ed2d

void Unwind_1001ed2d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ed33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@1001ed39 at 1001ed39

void Unwind_1001ed39(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ed3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001ed42 at 1001ed42

void Unwind_1001ed42(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1001ed4d at 1001ed4d

void Unwind_1001ed4d(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@1001ed58 at 1001ed58

void Unwind_1001ed58(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ed60 at 1001ed60

void Unwind_1001ed60(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001ed68 at 1001ed68

void Unwind_1001ed68(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x54));
    return;
  }
  return;
}



// Function: Unwind@1001ed81 at 1001ed81

void Unwind_1001ed81(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ed87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x4c) + -0x48));
  return;
}



// Function: Unwind@1001ed8d at 1001ed8d

void Unwind_1001ed8d(void)

{
  int unaff_EBP;
  
  FUN_10003550((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x4c) + -0x4c));
  return;
}



// Function: Unwind@1001ed98 at 1001ed98

void Unwind_1001ed98(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ed9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001edd0 at 1001edd0

void Unwind_1001edd0(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001edd8 at 1001edd8

void Unwind_1001edd8(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001ede3 at 1001ede3

void Unwind_1001ede3(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001edeb at 1001edeb

void Unwind_1001edeb(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001edf3 at 1001edf3

void Unwind_1001edf3(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ee30 at 1001ee30

void Unwind_1001ee30(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001ee38 at 1001ee38

void Unwind_1001ee38(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001ee43 at 1001ee43

void Unwind_1001ee43(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ee4b at 1001ee4b

void Unwind_1001ee4b(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ee53 at 1001ee53

void Unwind_1001ee53(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ee90 at 1001ee90

void Unwind_1001ee90(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001ee98 at 1001ee98

void Unwind_1001ee98(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001eea3 at 1001eea3

void Unwind_1001eea3(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001eeab at 1001eeab

void Unwind_1001eeab(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001eeb3 at 1001eeb3

void Unwind_1001eeb3(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001eef0 at 1001eef0

void Unwind_1001eef0(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001eef8 at 1001eef8

void Unwind_1001eef8(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001ef03 at 1001ef03

void Unwind_1001ef03(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ef0b at 1001ef0b

void Unwind_1001ef0b(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ef13 at 1001ef13

void Unwind_1001ef13(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ef50 at 1001ef50

void Unwind_1001ef50(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001ef58 at 1001ef58

void Unwind_1001ef58(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001ef63 at 1001ef63

void Unwind_1001ef63(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ef6b at 1001ef6b

void Unwind_1001ef6b(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ef73 at 1001ef73

void Unwind_1001ef73(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001efb0 at 1001efb0

void Unwind_1001efb0(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001efb8 at 1001efb8

void Unwind_1001efb8(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001efc3 at 1001efc3

void Unwind_1001efc3(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001efcb at 1001efcb

void Unwind_1001efcb(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001efd3 at 1001efd3

void Unwind_1001efd3(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001f010 at 1001f010

void Unwind_1001f010(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1001f018 at 1001f018

void Unwind_1001f018(void)

{
  int unaff_EBP;
  
  FUN_10005e10((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001f023 at 1001f023

void Unwind_1001f023(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001f02b at 1001f02b

void Unwind_1001f02b(void)

{
  int unaff_EBP;
  
  FUN_10005900((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001f033 at 1001f033

void Unwind_1001f033(void)

{
  int unaff_EBP;
  
  FUN_10001440((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001f070 at 1001f070

void Unwind_1001f070(void)

{
  FUN_100021e0(0x1002ff38);
  return;
}



// Function: Unwind@1001f07a at 1001f07a

void Unwind_1001f07a(void)

{
  FUN_10002230(0x1002ff38);
  return;
}



// Function: Unwind@1001f0a0 at 1001f0a0

void Unwind_1001f0a0(void)

{
  FUN_10002230(0x1002ff38);
  return;
}



// Function: Unwind@1001f0aa at 1001f0aa

void Unwind_1001f0aa(void)

{
  FUN_100021e0(0x1002ff38);
  return;
}



// Function: Unwind@1001f0d0 at 1001f0d0

void Unwind_1001f0d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001440(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001f110 at 1001f110

void Unwind_1001f110(void)

{
  int unaff_EBP;
  
  FUN_10002d30(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001f140 at 1001f140

void Unwind_1001f140(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001f180 at 1001f180

void Unwind_1001f180(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1a4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1a4) = *(uint *)(unaff_EBP + -0x1a4) & 0xfffffffe;
    FUN_10005900(*(undefined4 **)(unaff_EBP + -0x1a8));
    return;
  }
  return;
}



// Function: FUN_1001f320 at 1001f320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f320(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001f084;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002170(0x1002ff38);
  _DAT_1002ff38 = ATL::CComModule::vftable;
  _DAT_1002fdec = &DAT_1002ff38;
  local_8 = 0xffffffff;
  _atexit(FUN_1001fa90);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fa20 at 1001fa20

void FUN_1001fa20(void)

{
  Ordinal_6(DAT_1002ff1c);
  return;
}



// Function: FUN_1001fa30 at 1001fa30

void FUN_1001fa30(void)

{
  Ordinal_6(DAT_1002ff20);
  return;
}



// Function: FUN_1001fa40 at 1001fa40

void FUN_1001fa40(void)

{
  Ordinal_6(DAT_1002ff24);
  return;
}



// Function: FUN_1001fa50 at 1001fa50

void FUN_1001fa50(void)

{
  Ordinal_6(DAT_1002ff28);
  return;
}



// Function: FUN_1001fa60 at 1001fa60

void FUN_1001fa60(void)

{
  Ordinal_6(DAT_1002ff2c);
  return;
}



// Function: FUN_1001fa70 at 1001fa70

void FUN_1001fa70(void)

{
  Ordinal_6(DAT_1002ff30);
  return;
}



// Function: FUN_1001fa80 at 1001fa80

void FUN_1001fa80(void)

{
  Ordinal_6(DAT_1002ff34);
  return;
}



// Function: FUN_1001fa90 at 1001fa90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fa90(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001f0b4;
  local_10 = ExceptionList;
  uVar1 = DAT_1002fdb0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_1002ff38 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_1002ff3c != 0) {
    if (DAT_1002ff44 != 0) {
      FUN_10001f00(0x1002ff3c);
      DAT_1002ff44 = 0;
    }
    if (DAT_1002ff60 != (int *)0x0) {
      (**(code **)(*DAT_1002ff60 + 8))(DAT_1002ff60,uVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1002ff48);
    DAT_1002ff3c = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001fc30 at 1001fc30

void FUN_1001fc30(void)

{
  Ordinal_6(DAT_1002ff68);
  return;
}



// Function: FUN_1001fc40 at 1001fc40

void FUN_1001fc40(void)

{
  Ordinal_6(DAT_1002ff6c);
  return;
}



// Function: FUN_1001fc50 at 1001fc50

void FUN_1001fc50(void)

{
  Ordinal_6(DAT_1002ff70);
  return;
}



// Function: FUN_1001fc60 at 1001fc60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fc60(void)

{
  if (7 < DAT_1002f914) {
    operator_delete(DAT_1002f900);
  }
  DAT_1002f914 = 7;
  _DAT_1002f910 = 0;
  DAT_1002f900 = (void *)((uint)DAT_1002f900 & 0xffff0000);
  return;
}



// Function: FUN_1001fca0 at 1001fca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fca0(void)

{
  if (7 < DAT_1002f930) {
    operator_delete(DAT_1002f91c);
  }
  DAT_1002f930 = 7;
  _DAT_1002f92c = 0;
  DAT_1002f91c = (void *)((uint)DAT_1002f91c & 0xffff0000);
  return;
}



// Function: FUN_1001fce0 at 1001fce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fce0(void)

{
  if (7 < DAT_1002f94c) {
    operator_delete(DAT_1002f938);
  }
  DAT_1002f94c = 7;
  _DAT_1002f948 = 0;
  DAT_1002f938 = (void *)((uint)DAT_1002f938 & 0xffff0000);
  return;
}



// Function: FUN_1001fd20 at 1001fd20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd20(void)

{
  if (7 < DAT_1002f968) {
    operator_delete(DAT_1002f954);
  }
  DAT_1002f968 = 7;
  _DAT_1002f964 = 0;
  DAT_1002f954 = (void *)((uint)DAT_1002f954 & 0xffff0000);
  return;
}



// Function: FUN_1001fd60 at 1001fd60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd60(void)

{
  if (7 < DAT_1002f984) {
    operator_delete(DAT_1002f970);
  }
  DAT_1002f984 = 7;
  _DAT_1002f980 = 0;
  DAT_1002f970 = (void *)((uint)DAT_1002f970 & 0xffff0000);
  return;
}



// Function: FUN_1001fda0 at 1001fda0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fda0(void)

{
  if (7 < DAT_1002f9a0) {
    operator_delete(DAT_1002f98c);
  }
  DAT_1002f9a0 = 7;
  _DAT_1002f99c = 0;
  DAT_1002f98c = (void *)((uint)DAT_1002f98c & 0xffff0000);
  return;
}



// Function: FUN_1001fde0 at 1001fde0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fde0(void)

{
  if (7 < DAT_1002f9bc) {
    operator_delete(DAT_1002f9a8);
  }
  DAT_1002f9bc = 7;
  _DAT_1002f9b8 = 0;
  DAT_1002f9a8 = (void *)((uint)DAT_1002f9a8 & 0xffff0000);
  return;
}



// Function: FUN_1001fe20 at 1001fe20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe20(void)

{
  if (7 < DAT_1002f9d8) {
    operator_delete(DAT_1002f9c4);
  }
  DAT_1002f9d8 = 7;
  _DAT_1002f9d4 = 0;
  DAT_1002f9c4 = (void *)((uint)DAT_1002f9c4 & 0xffff0000);
  return;
}



// Function: FUN_1001fe60 at 1001fe60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe60(void)

{
  if (7 < DAT_1002f9f4) {
    operator_delete(DAT_1002f9e0);
  }
  DAT_1002f9f4 = 7;
  _DAT_1002f9f0 = 0;
  DAT_1002f9e0 = (void *)((uint)DAT_1002f9e0 & 0xffff0000);
  return;
}



// Function: FUN_1001fea0 at 1001fea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fea0(void)

{
  if (7 < DAT_1002fa10) {
    operator_delete(DAT_1002f9fc);
  }
  DAT_1002fa10 = 7;
  _DAT_1002fa0c = 0;
  DAT_1002f9fc = (void *)((uint)DAT_1002f9fc & 0xffff0000);
  return;
}



// Function: FUN_1001fee0 at 1001fee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fee0(void)

{
  if (7 < DAT_1002fa2c) {
    operator_delete(DAT_1002fa18);
  }
  DAT_1002fa2c = 7;
  _DAT_1002fa28 = 0;
  DAT_1002fa18 = (void *)((uint)DAT_1002fa18 & 0xffff0000);
  return;
}



// Function: FUN_1001ff20 at 1001ff20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff20(void)

{
  if (7 < DAT_1002fa48) {
    operator_delete(DAT_1002fa34);
  }
  DAT_1002fa48 = 7;
  _DAT_1002fa44 = 0;
  DAT_1002fa34 = (void *)((uint)DAT_1002fa34 & 0xffff0000);
  return;
}



// Function: FUN_1001ff60 at 1001ff60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff60(void)

{
  if (7 < DAT_1002fa64) {
    operator_delete(DAT_1002fa50);
  }
  DAT_1002fa64 = 7;
  _DAT_1002fa60 = 0;
  DAT_1002fa50 = (void *)((uint)DAT_1002fa50 & 0xffff0000);
  return;
}



// Function: FUN_1001ffa0 at 1001ffa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ffa0(void)

{
  if (7 < DAT_1002fa80) {
    operator_delete(DAT_1002fa6c);
  }
  DAT_1002fa80 = 7;
  _DAT_1002fa7c = 0;
  DAT_1002fa6c = (void *)((uint)DAT_1002fa6c & 0xffff0000);
  return;
}



// Function: FUN_1001ffe0 at 1001ffe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ffe0(void)

{
  if (7 < DAT_1002fa9c) {
    operator_delete(DAT_1002fa88);
  }
  DAT_1002fa9c = 7;
  _DAT_1002fa98 = 0;
  DAT_1002fa88 = (void *)((uint)DAT_1002fa88 & 0xffff0000);
  return;
}



// Function: FUN_10020020 at 10020020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020020(void)

{
  if (7 < DAT_1002fab8) {
    operator_delete(DAT_1002faa4);
  }
  DAT_1002fab8 = 7;
  _DAT_1002fab4 = 0;
  DAT_1002faa4 = (void *)((uint)DAT_1002faa4 & 0xffff0000);
  return;
}



// Function: FUN_10020060 at 10020060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020060(void)

{
  if (7 < DAT_1002fad4) {
    operator_delete(DAT_1002fac0);
  }
  DAT_1002fad4 = 7;
  _DAT_1002fad0 = 0;
  DAT_1002fac0 = (void *)((uint)DAT_1002fac0 & 0xffff0000);
  return;
}



// Function: FUN_100200a0 at 100200a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200a0(void)

{
  if (7 < DAT_1002faf0) {
    operator_delete(DAT_1002fadc);
  }
  DAT_1002faf0 = 7;
  _DAT_1002faec = 0;
  DAT_1002fadc = (void *)((uint)DAT_1002fadc & 0xffff0000);
  return;
}



// Function: FUN_100200e0 at 100200e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200e0(void)

{
  if (7 < DAT_1002fb0c) {
    operator_delete(DAT_1002faf8);
  }
  DAT_1002fb0c = 7;
  _DAT_1002fb08 = 0;
  DAT_1002faf8 = (void *)((uint)DAT_1002faf8 & 0xffff0000);
  return;
}



// Function: FUN_10020120 at 10020120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020120(void)

{
  if (7 < DAT_1002fb28) {
    operator_delete(DAT_1002fb14);
  }
  DAT_1002fb28 = 7;
  _DAT_1002fb24 = 0;
  DAT_1002fb14 = (void *)((uint)DAT_1002fb14 & 0xffff0000);
  return;
}



// Function: FUN_10020160 at 10020160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020160(void)

{
  if (7 < DAT_1002fb44) {
    operator_delete(DAT_1002fb30);
  }
  DAT_1002fb44 = 7;
  _DAT_1002fb40 = 0;
  DAT_1002fb30 = (void *)((uint)DAT_1002fb30 & 0xffff0000);
  return;
}



// Function: FUN_100201a0 at 100201a0

void FUN_100201a0(void)

{
  Ordinal_6(DAT_1002ff74);
  return;
}



// Function: FUN_100201b0 at 100201b0

void FUN_100201b0(void)

{
  Ordinal_6(DAT_1002ff78);
  return;
}



// Function: FUN_100201c0 at 100201c0

void FUN_100201c0(void)

{
  Ordinal_6(DAT_1002ff7c);
  return;
}



// Function: FUN_100201d0 at 100201d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100201d0(void)

{
  if (7 < DAT_1002fb60) {
    operator_delete(DAT_1002fb4c);
  }
  DAT_1002fb60 = 7;
  _DAT_1002fb5c = 0;
  DAT_1002fb4c = (void *)((uint)DAT_1002fb4c & 0xffff0000);
  return;
}



// Function: FUN_10020210 at 10020210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020210(void)

{
  if (7 < DAT_1002fb7c) {
    operator_delete(DAT_1002fb68);
  }
  DAT_1002fb7c = 7;
  _DAT_1002fb78 = 0;
  DAT_1002fb68 = (void *)((uint)DAT_1002fb68 & 0xffff0000);
  return;
}



// Function: FUN_10020250 at 10020250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020250(void)

{
  if (7 < DAT_1002fb98) {
    operator_delete(DAT_1002fb84);
  }
  DAT_1002fb98 = 7;
  _DAT_1002fb94 = 0;
  DAT_1002fb84 = (void *)((uint)DAT_1002fb84 & 0xffff0000);
  return;
}



// Function: FUN_10020290 at 10020290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020290(void)

{
  if (7 < DAT_1002fbb4) {
    operator_delete(DAT_1002fba0);
  }
  DAT_1002fbb4 = 7;
  _DAT_1002fbb0 = 0;
  DAT_1002fba0 = (void *)((uint)DAT_1002fba0 & 0xffff0000);
  return;
}



// Function: FUN_100202d0 at 100202d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100202d0(void)

{
  if (7 < DAT_1002fbd0) {
    operator_delete(DAT_1002fbbc);
  }
  DAT_1002fbd0 = 7;
  _DAT_1002fbcc = 0;
  DAT_1002fbbc = (void *)((uint)DAT_1002fbbc & 0xffff0000);
  return;
}



// Function: FUN_10020310 at 10020310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020310(void)

{
  if (7 < DAT_1002fbec) {
    operator_delete(DAT_1002fbd8);
  }
  DAT_1002fbec = 7;
  _DAT_1002fbe8 = 0;
  DAT_1002fbd8 = (void *)((uint)DAT_1002fbd8 & 0xffff0000);
  return;
}



// Function: FUN_10020350 at 10020350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020350(void)

{
  if (7 < DAT_1002fc08) {
    operator_delete(DAT_1002fbf4);
  }
  DAT_1002fc08 = 7;
  _DAT_1002fc04 = 0;
  DAT_1002fbf4 = (void *)((uint)DAT_1002fbf4 & 0xffff0000);
  return;
}



// Function: FUN_10020390 at 10020390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020390(void)

{
  if (7 < DAT_1002fc24) {
    operator_delete(DAT_1002fc10);
  }
  DAT_1002fc24 = 7;
  _DAT_1002fc20 = 0;
  DAT_1002fc10 = (void *)((uint)DAT_1002fc10 & 0xffff0000);
  return;
}



// Function: FUN_100203d0 at 100203d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100203d0(void)

{
  if (7 < DAT_1002fc40) {
    operator_delete(DAT_1002fc2c);
  }
  DAT_1002fc40 = 7;
  _DAT_1002fc3c = 0;
  DAT_1002fc2c = (void *)((uint)DAT_1002fc2c & 0xffff0000);
  return;
}



// Function: FUN_10020410 at 10020410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020410(void)

{
  if (7 < DAT_1002fc5c) {
    operator_delete(DAT_1002fc48);
  }
  DAT_1002fc5c = 7;
  _DAT_1002fc58 = 0;
  DAT_1002fc48 = (void *)((uint)DAT_1002fc48 & 0xffff0000);
  return;
}



// Function: FUN_10020450 at 10020450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020450(void)

{
  if (7 < DAT_1002fc78) {
    operator_delete(DAT_1002fc64);
  }
  DAT_1002fc78 = 7;
  _DAT_1002fc74 = 0;
  DAT_1002fc64 = (void *)((uint)DAT_1002fc64 & 0xffff0000);
  return;
}



// Function: FUN_10020490 at 10020490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020490(void)

{
  if (7 < DAT_1002fc94) {
    operator_delete(DAT_1002fc80);
  }
  DAT_1002fc94 = 7;
  _DAT_1002fc90 = 0;
  DAT_1002fc80 = (void *)((uint)DAT_1002fc80 & 0xffff0000);
  return;
}



// Function: FUN_100204d0 at 100204d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100204d0(void)

{
  if (7 < DAT_1002fcb0) {
    operator_delete(DAT_1002fc9c);
  }
  DAT_1002fcb0 = 7;
  _DAT_1002fcac = 0;
  DAT_1002fc9c = (void *)((uint)DAT_1002fc9c & 0xffff0000);
  return;
}



// Function: FUN_10020510 at 10020510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020510(void)

{
  if (7 < DAT_1002fccc) {
    operator_delete(DAT_1002fcb8);
  }
  DAT_1002fccc = 7;
  _DAT_1002fcc8 = 0;
  DAT_1002fcb8 = (void *)((uint)DAT_1002fcb8 & 0xffff0000);
  return;
}



// Function: FUN_10020550 at 10020550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020550(void)

{
  if (7 < DAT_1002fce8) {
    operator_delete(DAT_1002fcd4);
  }
  DAT_1002fce8 = 7;
  _DAT_1002fce4 = 0;
  DAT_1002fcd4 = (void *)((uint)DAT_1002fcd4 & 0xffff0000);
  return;
}



// Function: FUN_10020590 at 10020590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020590(void)

{
  if (7 < DAT_1002fd04) {
    operator_delete(DAT_1002fcf0);
  }
  DAT_1002fd04 = 7;
  _DAT_1002fd00 = 0;
  DAT_1002fcf0 = (void *)((uint)DAT_1002fcf0 & 0xffff0000);
  return;
}



// Function: FUN_100205d0 at 100205d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100205d0(void)

{
  if (7 < DAT_1002fd20) {
    operator_delete(DAT_1002fd0c);
  }
  DAT_1002fd20 = 7;
  _DAT_1002fd1c = 0;
  DAT_1002fd0c = (void *)((uint)DAT_1002fd0c & 0xffff0000);
  return;
}



// Function: FUN_10020610 at 10020610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020610(void)

{
  if (7 < DAT_1002fd3c) {
    operator_delete(DAT_1002fd28);
  }
  DAT_1002fd3c = 7;
  _DAT_1002fd38 = 0;
  DAT_1002fd28 = (void *)((uint)DAT_1002fd28 & 0xffff0000);
  return;
}



// Function: FUN_10020650 at 10020650

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020650(void)

{
  if (7 < DAT_1002fd58) {
    operator_delete(DAT_1002fd44);
  }
  DAT_1002fd58 = 7;
  _DAT_1002fd54 = 0;
  DAT_1002fd44 = (void *)((uint)DAT_1002fd44 & 0xffff0000);
  return;
}



// Function: FUN_10020690 at 10020690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020690(void)

{
  if (7 < DAT_1002fd74) {
    operator_delete(DAT_1002fd60);
  }
  DAT_1002fd74 = 7;
  _DAT_1002fd70 = 0;
  DAT_1002fd60 = (void *)((uint)DAT_1002fd60 & 0xffff0000);
  return;
}



// Function: FUN_100206d0 at 100206d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100206d0(void)

{
  if (7 < DAT_1002fd90) {
    operator_delete(DAT_1002fd7c);
  }
  DAT_1002fd90 = 7;
  _DAT_1002fd8c = 0;
  DAT_1002fd7c = (void *)((uint)DAT_1002fd7c & 0xffff0000);
  return;
}



// Function: FUN_10020705 at 10020705

void FUN_10020705(void)

{
  FUN_1001af42((int *)&DAT_1002ff80);
  return;
}



// Function: FUN_1002070f at 1002070f

void FUN_1002070f(void)

{
  FUN_1001b024(0x1002ffa8);
  return;
}



