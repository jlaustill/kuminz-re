/*
 * Decompiled from: ProgressControl.dll
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

void __fastcall FUN_10001070(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e49;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100010c0 at 100010c0

exception * __thiscall FUN_100010c0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e79;
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

void FUN_10001150(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100233f8);
}



// Function: FUN_10001170 at 10001170

void __cdecl FUN_10001170(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
}



// Function: FUN_10001230 at 10001230

void __cdecl FUN_10001230(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
}



// Function: FUN_100012e0 at 100012e0

void __cdecl FUN_100012e0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
}



// Function: FUN_100013a0 at 100013a0

void __cdecl FUN_100013a0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
}



// Function: FUN_10001450 at 10001450

uint __fastcall FUN_10001450(LPCRITICAL_SECTION param_1)

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



// Function: FUN_10001480 at 10001480

void __fastcall FUN_10001480(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100014a0 at 100014a0

DWORD FUN_100014a0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_100014c0 at 100014c0

uint __cdecl FUN_100014c0(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100014e0 at 100014e0

void __fastcall FUN_100014e0(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_100014f0 at 100014f0

int __thiscall
FUN_100014f0(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,LPWSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x10001552. Too many branches */
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



// Function: FUN_10001570 at 10001570

int __thiscall FUN_10001570(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x100015ba. Too many branches */
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



// Function: FUN_100015d0 at 100015d0

undefined4 __fastcall FUN_100015d0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100015e0 at 100015e0

void __cdecl FUN_100015e0(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10001640 at 10001640

void __thiscall FUN_10001640(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    FUN_10001570(*(void **)((int)this + 8),*this,param_1);
    return;
  }
  if (DAT_10029fec == '\0') {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_10029fe8 = GetProcAddress(hModule,"RegDeleteKeyExW");
    }
    DAT_10029fec = '\x01';
  }
  if (DAT_10029fe8 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
    (*DAT_10029fe8)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    return;
  }
                    /* WARNING: Load size is inaccurate */
  RegDeleteKeyW(*this,param_1);
  return;
}



// Function: FUN_100016c0 at 100016c0

void __fastcall FUN_100016c0(undefined4 *param_1)

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



// Function: FUN_100016f0 at 100016f0

void __thiscall
FUN_100016f0(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
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
    iVar1 = FUN_100014f0(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,param_6
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



// Function: FUN_10001790 at 10001790

void __thiscall FUN_10001790(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_100017fa:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_100017fa;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_1000180f;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_1000180f;
      }
    }
    iVar2 = 1;
  }
LAB_1000180f:
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



// Function: FUN_10001840 at 10001840

void __thiscall FUN_10001840(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExW(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_10001860 at 10001860

LSTATUS __thiscall FUN_10001860(void *this,LPCWSTR param_1,LPCWSTR param_2,DWORD param_3)

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



// Function: FUN_100018a0 at 100018a0

LSTATUS __thiscall FUN_100018a0(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10001900 at 10001900

undefined4 __fastcall FUN_10001900(undefined4 *param_1)

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



// Function: FUN_10001930 at 10001930

void __fastcall FUN_10001930(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10001940 at 10001940

undefined4 __thiscall FUN_10001940(void *this,void *param_1,int param_2)

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
      FUN_10001170((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_100019f0 at 100019f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100019f0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019eae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_1002a010 & 1) == 0) {
    DAT_1002a010 = DAT_1002a010 | 1;
    DAT_10029ff4 = 8;
    DAT_10029ff0 = &DAT_1001e5a4;
    DAT_10029ff8 = &DAT_1001e5a0;
    _DAT_10029ffc = 0x4008;
    _DAT_1002a000 = &DAT_1001e59c;
    _DAT_1002a004 = 0x13;
    _DAT_1002a008 = &DAT_1001e598;
    _DAT_1002a00c = 0x11;
  }
  local_8 = 0xffffffff;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_10029ff0)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_10029ff4)[uVar2 * 4];
      ExceptionList = local_10;
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10001ae0 at 10001ae0

uint __cdecl FUN_10001ae0(ushort param_1)

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
    goto switchD_10001af6_caseD_30;
  default:
    uVar1 = uVar1 & 0xffffff00;
switchD_10001af6_caseD_30:
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



// Function: FUN_10001b60 at 10001b60

LPCWSTR __cdecl FUN_10001b60(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10001bb0 at 10001bb0

void __fastcall FUN_10001bb0(undefined4 *param_1)

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



// Function: FUN_10001c10 at 10001c10

undefined4 __thiscall FUN_10001c10(void *this,undefined2 *param_1)

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
  
  FUN_10001bb0((undefined4 *)this);
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
      goto switchD_10001d04_caseD_9;
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
switchD_10001d04_caseD_9:
  *puVar7 = 0;
  return 0;
}



// Function: FUN_10001d80 at 10001d80

undefined4 FUN_10001d80(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1001e608;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1001e638);
  return 1;
}



// Function: FUN_10001dc0 at 10001dc0

bool FUN_10001dc0(HKEY param_1)

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



// Function: FUN_10001e10 at 10001e10

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10001e10(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10001c10(this,param_1), -1 < iVar1)) {
    FUN_10001bb0((undefined4 *)this);
    iVar1 = FUN_10001c10(this,local_2008);
    if (-1 < iVar1) {
      FUN_10001c10(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: DllCanUnloadNow at 10001e80

HRESULT DllCanUnloadNow(void)

{
                    /* 0x1e80  1  DllCanUnloadNow */
  return (uint)(DAT_1002a04c != 0);
}



// Function: FUN_10001e90 at 10001e90

void FUN_10001e90(void)

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



// Function: FUN_10001ed0 at 10001ed0

int FUN_10001ed0(LPCWSTR param_1)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  LPCWSTR pWVar2;
  LPWSTR pWVar3;
  
  pWVar2 = param_1;
  if (param_1 == (LPCWSTR)0x0) {
    return 0;
  }
  WVar1 = *param_1;
  lpsz = param_1;
  while (WVar1 != L'\0') {
    pWVar3 = CharNextW(lpsz);
    WVar1 = *lpsz;
    if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
      param_1 = pWVar3;
    }
    lpsz = pWVar3;
    WVar1 = *pWVar3;
  }
  return (int)param_1 - (int)pWVar2 >> 1;
}



// Function: FUN_10001f30 at 10001f30

undefined4 __thiscall FUN_10001f30(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10029fcc = *param_3;
    DAT_10029fd0 = param_3[1];
    DAT_10029fd4 = param_3[2];
    DAT_10029fd8 = param_3[3];
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
  piVar2 = DAT_1002a088;
  if (DAT_1002a088 < DAT_1002a08c) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_1002a08c);
  }
  return 0;
}



// Function: FUN_10001fb0 at 10001fb0

void FUN_10001fb0(int param_1)

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



// Function: FUN_10002010 at 10002010

void __fastcall FUN_10002010(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ed8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_10029f90 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002060 at 10002060

undefined4 * __fastcall FUN_10002060(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f08;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10018860((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[1] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x13] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x1f] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x20] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x21] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x22] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x23] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x24] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x25] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x26] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x27] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x28] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x29] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2a] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2b] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2c] = ATL::CComObject<class_CProgressCtrl>::vftable;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002160 at 10002160

void FUN_10002160(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001150(DVar1);
}



// Function: FUN_10002180 at 10002180

int __cdecl FUN_10002180(int *param_1,undefined4 param_2,ushort *param_3)

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
                          (param_1,param_2,&DAT_1002006c,0x400,8,&local_14,0,0,0), -1 < iVar2)) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_2,&DAT_1002006c,0x400,4,&local_14,0,0,0);
    return iVar2;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_10002230 at 10002230

int __thiscall FUN_10002230(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  local_10 = (**(code **)(*piVar1 + 0x14))(piVar1,0,0,1,&local_18);
  local_8 = 0;
  local_c = 0;
  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,&local_c,4,&local_8);
  if (iVar2 < 0) goto LAB_10002349;
  if (local_8 != 4) {
    iVar2 = -0x7fffbffb;
    goto LAB_10002349;
  }
  if (local_c != 0) {
    if (local_c < 2) {
      iVar2 = -0x7fffbffb;
      goto LAB_10002349;
    }
    if (0x100000 < local_c) {
      iVar2 = -0x7ff8fffb;
      goto LAB_10002349;
    }
    local_c = local_c - 2;
    iVar2 = Ordinal_150(0,local_c);
    *(int *)this = iVar2;
    if (iVar2 == 0) {
      iVar2 = -0x7ff8fff2;
      goto LAB_10002349;
    }
    iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,iVar2,local_c,&local_8);
    if (-1 < iVar2) {
      if (local_8 == local_c) {
        iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,&param_1,2,&local_8);
        if (iVar2 < 0) goto LAB_10002336;
        if ((local_8 == 2) && ((short)param_1 == 0)) {
          return iVar2;
        }
      }
      iVar2 = -0x7fffbffb;
    }
LAB_10002336:
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(undefined4 *)this = 0;
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_10002349:
  if (-1 < local_10) {
    (**(code **)(*piVar1 + 0x14))(piVar1,local_18,local_14,0,0);
  }
  return iVar2;
}



// Function: FUN_10002370 at 10002370

undefined4 FUN_10002370(int *param_1)

{
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    return 1;
  }
  return 0;
}



// Function: FUN_100023b0 at 100023b0

int FUN_100023b0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

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
  iVar2 = FUN_10002370(param_3);
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



// Function: FUN_100024a0 at 100024a0

void __fastcall FUN_100024a0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_100024b0 at 100024b0

undefined4 FUN_100024b0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xc0);
  return 0;
}



// Function: FUN_100024e0 at 100024e0

undefined4 FUN_100024e0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xc4);
  return 0;
}



// Function: FUN_10002510 at 10002510

undefined4 FUN_10002510(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xd8);
  return 0;
}



// Function: FUN_10002540 at 10002540

undefined4 FUN_10002540(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xe4);
  return 0;
}



// Function: FUN_10002570 at 10002570

undefined4 FUN_10002570(int param_1,short *param_2)

{
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  *param_2 = -(ushort)(*(int *)(param_1 + 0xd4) != 0);
  return 0;
}



// Function: FUN_100025a0 at 100025a0

undefined4 FUN_100025a0(int param_1,short *param_2)

{
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  *param_2 = -(ushort)(*(int *)(param_1 + 0xcc) != 0);
  return 0;
}



// Function: FUN_100025d0 at 100025d0

undefined4 FUN_100025d0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 200);
  return 0;
}



// Function: FUN_10002600 at 10002600

undefined4 FUN_10002600(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xd0);
  return 0;
}



// Function: FUN_10002630 at 10002630

undefined4 FUN_10002630(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xdc);
  return 0;
}



// Function: FUN_10002660 at 10002660

undefined4 FUN_10002660(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10002680 at 10002680

undefined4 __thiscall FUN_10002680(void *this,int param_1)

{
  int *piVar1;
  HGDIOBJ h;
  HGDIOBJ h_00;
  DWORD color;
  
  if ((*(byte *)((int)this + 0x44) & 4) == 0) {
    h = GetStockObject(7);
    h_00 = GetStockObject(2);
    SelectObject(*(HDC *)(param_1 + 0x14),h);
    SelectObject(*(HDC *)(param_1 + 0x14),h_00);
    piVar1 = *(int **)(param_1 + 0x18);
    Rectangle(*(HDC *)(param_1 + 0x14),*piVar1,piVar1[1],piVar1[2],piVar1[3]);
    color = GetSysColor(8);
    SetTextColor(*(HDC *)(param_1 + 0x14),color);
    SetBkMode(*(HDC *)(param_1 + 0x14),1);
    DrawTextW(*(HDC *)(param_1 + 0x14),L"ATL Composite Control",-1,*(LPRECT *)(param_1 + 0x18),0x25)
    ;
  }
  return 0;
}



// Function: FUN_10002720 at 10002720

void __fastcall FUN_10002720(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_10002770 at 10002770

uint FUN_10002770(int param_1)

{
  if (param_1 != 0) {
    return ~(*(uint *)(param_1 + -0x34) >> 7) & 1;
  }
  return ~(uRam00000048 >> 7) & 1;
}



// Function: FUN_100027a0 at 100027a0

undefined4 FUN_100027a0(int param_1)

{
  if (param_1 != 0) {
    *(uint *)(param_1 + -0x34) = *(uint *)(param_1 + -0x34) | 0x80;
    return 0;
  }
  uRam00000048 = uRam00000048 | 0x80;
  return 0;
}



// Function: FUN_100027d0 at 100027d0

undefined4 FUN_100027d0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x80;
  }
  if (param_2 != 0) {
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 1;
    return 0;
  }
  *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + -1;
  return 0;
}



// Function: FUN_10002800 at 10002800

undefined4 FUN_10002800(void)

{
  return 0;
}



// Function: FUN_10002810 at 10002810

undefined4 FUN_10002810(void)

{
  return 0;
}



// Function: FUN_10002820 at 10002820

undefined4 FUN_10002820(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  if (param_2 != 1) {
    return 0x80004005;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = *(undefined4 *)(iVar1 + 0x28);
  param_3[1] = *(undefined4 *)(iVar1 + 0x2c);
  return 0;
}



// Function: FUN_10002870 at 10002870

int FUN_10002870(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x88;
  }
  iVar1 = -0x7fffbffd;
  if ((*(uint *)(iVar2 + 0x48) & 0x100) != 0) {
    return -0x7fffbffb;
  }
  if (param_2 != (int *)0x0) {
    iVar2 = *(int *)(iVar2 + 0x50);
    *param_2 = iVar2;
    iVar1 = (-(uint)(iVar2 != 0) & 0x7fff0001) + 0x8000ffff;
  }
  return iVar1;
}



// Function: FUN_100028c0 at 100028c0

int __thiscall FUN_100028c0(void *this,int param_1)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f30;
  local_10 = ExceptionList;
  if (*(int *)((int)this + 4) == 0) {
    local_8 = 0;
    ExceptionList = &local_10;
    calloc(4,4);
    local_8 = 0xffffffff;
    iVar1 = FUN_10002929();
    return iVar1;
  }
  iVar2 = 1;
                    /* WARNING: Load size is inaccurate */
  piVar4 = *this;
  iVar1 = *(int *)((int)this + 4);
  if (piVar4 < piVar4 + iVar1) {
    do {
      if (*piVar4 == 0) {
        *piVar4 = param_1;
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
                    /* WARNING: Load size is inaccurate */
    } while (piVar4 < (int *)(*this + iVar1 * 4));
  }
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  pvVar3 = _recalloc(*this,4,iVar1 * 2);
  if (pvVar3 != (void *)0x0) {
    *(void **)this = pvVar3;
    _Size = *(int *)((int)this + 4) * 4;
    memset((void *)(_Size + (int)pvVar3),0,_Size);
                    /* WARNING: Load size is inaccurate */
    *(int *)(*this + *(int *)((int)this + 4) * 4) = param_1;
    iVar2 = *(int *)((int)this + 4);
    *(int *)((int)this + 4) = iVar1 * 2;
    ExceptionList = local_10;
    return iVar2 + 1;
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10002916 at 10002916

undefined * Catch_10002916(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002923;
}



// Function: FUN_10002929 at 10002929

int FUN_10002929(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *in_EAX;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int unaff_EBP;
  uint *unaff_ESI;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    *unaff_ESI = (uint)in_EAX;
    unaff_ESI[1] = 4;
    iVar3 = 1;
    piVar5 = (int *)*unaff_ESI;
    uVar1 = unaff_ESI[1];
    if (piVar5 < piVar5 + uVar1) {
      do {
        if (*piVar5 == 0) {
          *piVar5 = *(int *)(unaff_EBP + 8);
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        piVar5 = piVar5 + 1;
      } while (piVar5 < (int *)(*unaff_ESI + uVar1 * 4));
    }
    pvVar4 = _recalloc((void *)*unaff_ESI,4,uVar1 * 2);
    if (pvVar4 != (void *)0x0) {
      *unaff_ESI = (uint)pvVar4;
      memset((void *)(unaff_ESI[1] * 4 + (int)pvVar4),0,unaff_ESI[1] * 4);
      *(undefined4 *)(*unaff_ESI + unaff_ESI[1] * 4) = *(undefined4 *)(unaff_EBP + 8);
      uVar2 = unaff_ESI[1];
      unaff_ESI[1] = uVar1 * 2;
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar2 + 1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_100029f0 at 100029f0

undefined4 FUN_100029f0(void)

{
  return 0;
}



// Function: FUN_10002a00 at 10002a00

undefined4 FUN_10002a00(void)

{
  return 0x80004001;
}



// Function: FUN_10002a10 at 10002a10

undefined4 FUN_10002a10(int param_1)

{
  undefined4 *in_stack_00000014;
  
  if (in_stack_00000014 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  if (param_1 != 0) {
    *in_stack_00000014 = *(undefined4 *)(param_1 + -100);
    in_stack_00000014[1] = *(undefined4 *)(param_1 + -0x60);
    return 0;
  }
  *in_stack_00000014 = uRam00000028;
  in_stack_00000014[1] = uRam0000002c;
  return 0;
}



// Function: FUN_10002a60 at 10002a60

undefined4 FUN_10002a60(void)

{
  return 0x80004001;
}



// Function: FUN_10002a70 at 10002a70

undefined4 FUN_10002a70(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0;
  return 0;
}



// Function: FUN_10002a90 at 10002a90

undefined4
FUN_10002a90(undefined4 param_1,int param_2,RECT *param_3,LONG param_4,LONG param_5,
            undefined4 param_6,uint *param_7)

{
  POINT pt;
  BOOL BVar1;
  
  if (param_7 == (uint *)0x0) {
    return 0x80004003;
  }
  if (param_2 == 1) {
    pt.y = param_5;
    pt.x = param_4;
    BVar1 = PtInRect(param_3,pt);
    *param_7 = -(uint)(BVar1 != 0) & 3;
    return 0;
  }
  *param_7 = 0;
  return 0x80004005;
}



// Function: FUN_10002ae0 at 10002ae0

void FUN_10002ae0(undefined4 param_1,int param_2,RECT *param_3,RECT *param_4,undefined4 param_5,
                 uint *param_6)

{
  BOOL BVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_6 == (uint *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_2 == 1) {
    BVar1 = UnionRect(&local_18,param_3,param_4);
    *param_6 = -(uint)(BVar1 != 0) & 3;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_6 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002b60 at 10002b60

undefined4 FUN_10002b60(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int in_stack_00000018;
  undefined4 *in_stack_0000001c;
  
  if ((in_stack_00000018 == 0) || (in_stack_0000001c == (undefined4 *)0x0)) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0x80004005;
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_1 + -0x8c;
    }
    if ((param_2 == 1) && (*(int *)(in_stack_00000018 + 4) == 0)) {
      *in_stack_0000001c = *(undefined4 *)(iVar2 + 0x20);
      in_stack_0000001c[1] = *(undefined4 *)(iVar2 + 0x24);
      return 0;
    }
  }
  return uVar1;
}



// Function: FUN_10002bb0 at 10002bb0

int FUN_10002bb0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x90;
  }
  iVar1 = -0x7fffbffd;
  if ((*(uint *)(iVar2 + 0x48) & 0x100) != 0) {
    return -0x7fffbffb;
  }
  if (param_2 != (int *)0x0) {
    iVar2 = *(int *)(iVar2 + 0x50);
    *param_2 = iVar2;
    iVar1 = (-(uint)(iVar2 != 0) & 0x7fff0001) + 0x8000ffff;
  }
  return iVar1;
}



// Function: FUN_10002c00 at 10002c00

void FUN_10002c00(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f5e;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
    if ((DAT_1002a01c & 1) == 0) {
      DAT_1002a01c = DAT_1002a01c | 1;
      DAT_1002a014 = 0x18;
      DAT_1002a018 = 0xffffffff;
    }
    local_8 = 0xffffffff;
    piVar3 = &DAT_1002a014;
    uVar4 = local_14;
    iVar2 = DAT_1002a014;
    while (iVar2 != -1) {
      iVar2 = *piVar3;
      if (iVar2 == -2) {
        piVar3 = (int *)(*(code *)piVar3[1])(0);
      }
      else {
        piVar1 = (int *)(iVar2 + param_1);
        iVar2 = (**(code **)(*(int *)(iVar2 + param_1) + 0xc))(piVar1,&local_24,uVar4);
        if ((((-1 < iVar2) && (*param_2 == local_24)) && (param_2[1] == local_20)) &&
           ((param_2[2] == local_1c && (param_2[3] == local_18)))) {
          *param_3 = (int)piVar1;
          (**(code **)(*piVar1 + 4))(piVar1);
          break;
        }
        piVar3 = piVar3 + 1;
      }
      iVar2 = *piVar3;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002d20 at 10002d20

undefined4 FUN_10002d20(void)

{
  return 0;
}



// Function: FUN_10002d30 at 10002d30

undefined4 FUN_10002d30(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0xa4;
  }
  if (iVar1 == -0x84) {
    iVar1 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(iVar1 + 0x28);
    param_2[1] = *(undefined4 *)(iVar1 + 0x2c);
    return 0;
  }
  return 0x80004003;
}



// Function: FUN_10002d80 at 10002d80

undefined4 FUN_10002d80(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  if (param_2 != 1) {
    return 0x80070057;
  }
  *param_3 = 0x3642df59;
  param_3[1] = 0x48ca8f4d;
  param_3[2] = 0x71720b86;
  param_3[3] = 0xc8346448;
  return 0;
}



// Function: FUN_10002df0 at 10002df0

undefined4 FUN_10002df0(int *param_1,int *param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  if (((((*param_2 != -0x4e694d7a) || (param_2[1] != 0x101abab4)) || (param_2[2] != -0x55ff634a)) ||
      (param_2[3] != 0x71d3400)) &&
     (((*param_2 != 0 || (param_2[1] != 0)) || ((param_2[2] != 0xc0 || (param_2[3] != 0x46000000))))
     )) {
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



// Function: FUN_10002e80 at 10002e80

undefined4 FUN_10002e80(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0x9bfbbc02;
  param_2[1] = 0x101aeff1;
  param_2[2] = 0xaa00ed84;
  param_2[3] = 0x71d3400;
  return 0;
}



// Function: FUN_10002ec0 at 10002ec0

void FUN_10002ec0(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    (*(code *)**(undefined4 **)(param_1 + -0xb0))(param_1 + -0xb0,&DAT_1001edb0,param_2);
    return;
  }
  (*(code *)*puRam00000000)(0,&DAT_1001edb0,param_2);
  return;
}



// Function: FUN_10002f00 at 10002f00

int __cdecl FUN_10002f00(int param_1)

{
  if (*(short *)(param_1 + 2) == -1) {
    return param_1 + 0x10;
  }
  return param_1 + 8;
}



// Function: FUN_10002f20 at 10002f20

uint __cdecl FUN_10002f20(uint *param_1)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = *(short *)((int)param_1 + 2) != -1;
  if (bVar5) {
    psVar3 = (short *)((int)param_1 + 0x12);
    uVar4 = *param_1;
  }
  else {
    psVar3 = (short *)((int)param_1 + 0x1a);
    uVar4 = param_1[3];
  }
  if (*psVar3 == -1) {
    psVar3 = psVar3 + 2;
  }
  else {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
  }
  if (*psVar3 == -1) {
    psVar3 = psVar3 + 2;
  }
  else {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
  }
  do {
    psVar2 = psVar3;
    psVar3 = psVar2 + 1;
  } while (*psVar2 != 0);
  if ((uVar4 & 0x40) != 0) {
    if (bVar5) {
      psVar3 = psVar2 + 2;
    }
    else {
      psVar3 = psVar2 + 4;
    }
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
  }
  return (int)psVar3 + 3U & 0xfffffffc;
}



// Function: FUN_10002fc0 at 10002fc0

uint __cdecl FUN_10002fc0(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  
  if (param_2 == 0) {
    puVar1 = (ushort *)(param_1 + 0x12);
  }
  else {
    puVar1 = (ushort *)(param_1 + 0x18);
  }
  if (*puVar1 == 0xffff) {
    puVar1 = puVar1 + 2;
  }
  else {
    do {
      uVar2 = *puVar1;
      puVar1 = puVar1 + 1;
    } while (uVar2 != 0);
  }
  if (*puVar1 == 0xffff) {
    puVar1 = puVar1 + 2;
  }
  else {
    do {
      uVar2 = *puVar1;
      puVar1 = puVar1 + 1;
    } while (uVar2 != 0);
  }
  uVar2 = *puVar1;
  if ((uVar2 != 0) && (param_2 == 0)) {
    uVar2 = uVar2 - 2;
  }
  return uVar2 + 5 + (int)puVar1 & 0xfffffffc;
}



// Function: FUN_10003030 at 10003030

int __cdecl FUN_10003030(uint param_1,ushort *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 != (ushort *)0x0) {
    do {
      iVar1 = *(int *)(param_2 + 2);
      if (*param_2 == param_1) {
        if (param_2[1] == 0x378) {
          return 0;
        }
        *param_3 = (int)(param_2 + 1);
        return iVar1 + 6;
      }
      param_2 = (ushort *)((int)param_2 + iVar1 + 8);
    } while (param_2 != (ushort *)0x0);
  }
  return 0;
}



// Function: FUN_10003080 at 10003080

uint * __cdecl FUN_10003080(uint *param_1)

{
  bool bVar1;
  void *_Src;
  uint uVar2;
  void *pvVar3;
  uint *_Dst;
  errno_t eVar4;
  ushort *puVar5;
  short *psVar6;
  ushort uVar7;
  void *pvVar8;
  uint *puVar9;
  rsize_t _MaxCount;
  uint *puVar10;
  bool bVar11;
  int local_c;
  uint local_8;
  
  _Src = (void *)FUN_10002f20(param_1);
  puVar9 = (uint *)((int)_Src - (int)param_1);
  bVar11 = *(short *)((int)param_1 + 2) != -1;
  if (*(short *)((int)param_1 + 2) == -1) {
    puVar10 = param_1 + 4;
  }
  else {
    puVar10 = param_1 + 2;
  }
  uVar2 = (uint)(ushort)*puVar10;
  bVar1 = false;
  pvVar8 = _Src;
  puVar10 = puVar9;
  local_8 = uVar2;
  if (uVar2 != 0) {
    do {
      puVar5 = (ushort *)((int)pvVar8 + 0x18);
      if (bVar11) {
        puVar5 = (ushort *)((int)pvVar8 + 0x12);
      }
      if (*puVar5 == 0xffff) {
        puVar5 = puVar5 + 2;
      }
      else {
        do {
          uVar7 = *puVar5;
          puVar5 = puVar5 + 1;
        } while (uVar7 != 0);
      }
      if (*puVar5 == 0xffff) {
        puVar5 = puVar5 + 2;
      }
      else {
        do {
          uVar7 = *puVar5;
          puVar5 = puVar5 + 1;
        } while (uVar7 != 0);
      }
      uVar7 = *puVar5;
      if ((uVar7 != 0) && (bVar11)) {
        uVar7 = uVar7 - 2;
      }
      pvVar3 = (void *)(uVar7 + 5 + (int)puVar5 & 0xfffffffc);
      psVar6 = (short *)((int)pvVar8 + 0x18);
      if (bVar11) {
        psVar6 = (short *)((int)pvVar8 + 0x12);
      }
      if (*psVar6 == 0x7b) {
        bVar1 = true;
      }
      else {
        puVar10 = (uint *)((int)puVar10 + ((int)pvVar3 - (int)pvVar8));
      }
      local_8 = local_8 - 1;
      pvVar8 = pvVar3;
    } while (local_8 != 0);
    if (bVar1) {
      _Dst = (uint *)GlobalAlloc(0,(SIZE_T)puVar10);
      eVar4 = memcpy_s(_Dst,(rsize_t)puVar10,param_1,(rsize_t)puVar9);
      switch(eVar4) {
      case 0:
      case 0x50:
        param_1 = (uint *)((int)puVar10 - (int)puVar9);
        pvVar8 = (void *)((int)_Dst + (int)puVar9);
        if (param_1 <= puVar10) {
          if (*(short *)((int)_Dst + 2) == -1) {
            puVar9 = _Dst + 4;
          }
          else {
            puVar9 = _Dst + 2;
          }
          *(undefined2 *)puVar9 = 0;
          local_c = 0;
          do {
            puVar5 = (ushort *)((int)_Src + 0x18);
            if (bVar11) {
              puVar5 = (ushort *)((int)_Src + 0x12);
            }
            if (*puVar5 == 0xffff) {
              puVar5 = puVar5 + 2;
            }
            else {
              do {
                uVar7 = *puVar5;
                puVar5 = puVar5 + 1;
              } while (uVar7 != 0);
            }
            if (*puVar5 == 0xffff) {
              puVar5 = puVar5 + 2;
            }
            else {
              do {
                uVar7 = *puVar5;
                puVar5 = puVar5 + 1;
              } while (uVar7 != 0);
            }
            uVar7 = *puVar5;
            if ((uVar7 != 0) && (bVar11)) {
              uVar7 = uVar7 - 2;
            }
            pvVar3 = (void *)(uVar7 + 5 + (int)puVar5 & 0xfffffffc);
            psVar6 = (short *)((int)_Src + 0x18);
            if (bVar11) {
              psVar6 = (short *)((int)_Src + 0x12);
            }
            if (*psVar6 != 0x7b) {
              _MaxCount = (int)pvVar3 - (int)_Src;
              eVar4 = memcpy_s(pvVar8,(rsize_t)param_1,_Src,_MaxCount);
              switch(eVar4) {
              case 0:
              case 0x50:
                pvVar8 = (void *)((int)pvVar8 + _MaxCount);
                if (param_1 < (uint *)((int)param_1 - _MaxCount)) goto switchD_100031ab_caseD_1;
                psVar6 = (short *)FUN_10002f00((int)_Dst);
                *psVar6 = *psVar6 + 1;
                param_1 = (uint *)((int)param_1 - _MaxCount);
                break;
              default:
                goto switchD_100031ab_caseD_1;
              case 0xc:
                goto switchD_100031ab_caseD_c;
              case 0x16:
              case 0x22:
                goto switchD_100031ab_caseD_16;
              }
            }
            local_c = local_c + 1;
            _Src = pvVar3;
            if ((int)uVar2 <= local_c) {
              return _Dst;
            }
          } while( true );
        }
        break;
      case 0xc:
switchD_100031ab_caseD_c:
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x8007000e);
      case 0x16:
      case 0x22:
switchD_100031ab_caseD_16:
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x80070057);
      }
switchD_100031ab_caseD_1:
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x80004005);
    }
  }
  return param_1;
}



// Function: FUN_100033b0 at 100033b0

void FUN_100033b0(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nNumber;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004003);
  }
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004003);
  }
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0x58);
  nNumber = GetDeviceCaps(hdc,0x5a);
  ReleaseDC((HWND)0x0,hdc);
  iVar1 = MulDiv(iVar1,*param_1,0x9ec);
  *param_2 = iVar1;
  iVar1 = MulDiv(nNumber,param_1[1],0x9ec);
  param_2[1] = iVar1;
  return;
}



// Function: FUN_10003440 at 10003440

undefined4 FUN_10003440(int *param_1,int param_2)

{
  int *piVar1;
  LPVOID pvVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  if (param_1 == (int *)0x0) {
    return 0x80004003;
  }
  if (param_2 == 0) {
    return 0x80004003;
  }
  uVar5 = 0;
  iVar4 = 0;
  piVar1 = *(int **)(param_2 + 4);
  iVar6 = param_2;
  while (piVar1 != (int *)0x0) {
    if ((*(short *)(iVar6 + 0x20) == 0) &&
       ((((*piVar1 != 0 || (piVar1[1] != 0)) || (piVar1[2] != 0)) || (piVar1[3] != 0)))) {
      uVar5 = uVar5 + 1;
    }
    iVar4 = iVar4 + 1;
    iVar6 = param_2 + iVar4 * 0x24;
    piVar1 = *(int **)(iVar6 + 4);
  }
  if (uVar5 >> 0x1c == 0) {
    pvVar2 = CoTaskMemAlloc(uVar5 * 0x10);
  }
  else {
    pvVar2 = (LPVOID)0x0;
  }
  param_1[1] = (int)pvVar2;
  if (pvVar2 == (LPVOID)0x0) {
    return 0x8007000e;
  }
  iVar6 = 0;
  local_8 = 0;
  if (*(int *)(param_2 + 4) != 0) {
    iVar7 = 0;
    iVar4 = param_2;
    do {
      if ((*(short *)(iVar4 + 0x20) == 0) &&
         (((piVar1 = *(int **)(iVar4 + 4), *piVar1 != 0 || (piVar1[1] != 0)) ||
          ((piVar1[2] != 0 || (piVar1[3] != 0)))))) {
        iVar4 = 0;
        if (0 < iVar6) {
          piVar3 = (int *)param_1[1];
          do {
            if (((*piVar1 == *piVar3) && (piVar1[1] == piVar3[1])) &&
               ((piVar1[2] == piVar3[2] && (piVar1[3] == piVar3[3])))) goto LAB_100035a0;
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 4;
          } while (iVar4 < iVar6);
        }
        piVar3 = (int *)(param_1[1] + iVar7);
        *piVar3 = *piVar1;
        piVar3[1] = piVar1[1];
        piVar3[2] = piVar1[2];
        iVar6 = iVar6 + 1;
        piVar3[3] = piVar1[3];
        iVar7 = iVar7 + 0x10;
      }
LAB_100035a0:
      local_8 = local_8 + 1;
      iVar4 = param_2 + local_8 * 0x24;
    } while (*(int *)(iVar4 + 4) != 0);
  }
  *param_1 = iVar6;
  return 0;
}



// Function: FUN_100035d0 at 100035d0

undefined4 FUN_100035d0(int param_1)

{
  *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
  return *(undefined4 *)(param_1 + 0xbc);
}



// Function: FUN_100035f0 at 100035f0

undefined4 FUN_100035f0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0xbc);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0xbc);
  if ((*piVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 4))(1);
  }
  return uVar2;
}



// Function: FUN_10003620 at 10003620

void __fastcall FUN_10003620(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10018500(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003670 at 10003670

undefined4 * __thiscall FUN_10003670(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10018860((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x4c) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x7c) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x80) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x84) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x88) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x8c) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x90) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x94) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x98) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x9c) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0xa0) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0xa4) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0xa8) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0xac) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0xb0) = ATL::CComContainedObject<class_CProgressCtrl>::vftable;
  *(undefined4 *)((int)this + 0xbc) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003770 at 10003770

void FUN_10003770(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 4))(*(int **)(param_1 + 0xbc));
  return;
}



// Function: FUN_10003790 at 10003790

void FUN_10003790(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 8))(*(int **)(param_1 + 0xbc));
  return;
}



// Function: FUN_100037b0 at 100037b0

void FUN_100037b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xbc))(*(undefined4 **)(param_1 + 0xbc),param_2,param_3);
  return;
}



// Function: FUN_100037d0 at 100037d0

void FUN_100037d0(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (int *)0x0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  (**(code **)(*param_1 + 0xc))(param_1,local_18);
  iVar1 = (**(code **)*param_2)(param_2,local_18,&local_1c);
  if (iVar1 < 0) {
    if (iVar1 != -0x7fffbffe) goto LAB_1000384a;
  }
  else {
    iVar1 = FUN_100028c0(param_1 + 1,(int)local_1c);
    *param_3 = iVar1;
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ffbfdff) + 0x80040201;
    if (iVar1 != 0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
LAB_1000384a:
    if (-1 < iVar1) goto LAB_10003854;
  }
  *param_3 = 0;
LAB_10003854:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003890 at 10003890

int FUN_10003890(HWND param_1,LRESULT *param_2)

{
  LRESULT LVar1;
  
  if (param_2 == (LRESULT *)0x0) {
    return -0x7fffbffd;
  }
  LVar1 = SendMessageW(param_1,DAT_10029fe4,0,0);
  *param_2 = LVar1;
  return (-(uint)(LVar1 != 0) & 0x7fffbffb) + 0x80004005;
}



// Function: FUN_100038d0 at 100038d0

void * __cdecl FUN_100038d0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019fc9;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10023560);
}



// Function: FUN_10003960 at 10003960

exception * __thiscall FUN_10003960(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e79;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_100039c0 at 100039c0

void __thiscall FUN_100039c0(void *this,byte param_1)

{
  FUN_100039d0((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_100039d0 at 100039d0

void * __thiscall FUN_100039d0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10018500((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10003a30 at 10003a30

void FUN_10003a30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x90,param_2,param_3);
  return;
}



// Function: FUN_10003a40 at 10003a40

void FUN_10003a40(int param_1)

{
  FUN_10003790(param_1 + -0x84);
  return;
}



// Function: FUN_10003a50 at 10003a50

void FUN_10003a50(int param_1)

{
  FUN_10003770(param_1 + -0x7c);
  return;
}



// Function: FUN_10003a60 at 10003a60

void FUN_10003a60(int param_1)

{
  FUN_10003790(param_1 + -0xa4);
  return;
}



// Function: FUN_10003a70 at 10003a70

void FUN_10003a70(int param_1)

{
  FUN_10003770(param_1 + -0x9c);
  return;
}



// Function: FUN_10003a80 at 10003a80

void FUN_10003a80(int param_1)

{
  FUN_100035f0(param_1 + -0x8c);
  return;
}



// Function: FUN_10003a90 at 10003a90

void FUN_10003a90(int param_1)

{
  FUN_100035d0(param_1 + -0x84);
  return;
}



// Function: FUN_10003aa0 at 10003aa0

void FUN_10003aa0(int param_1)

{
  FUN_100035f0(param_1 + -0xac);
  return;
}



// Function: FUN_10003ab0 at 10003ab0

void FUN_10003ab0(int param_1)

{
  FUN_100035d0(param_1 + -0xa4);
  return;
}



// Function: FUN_10003ac0 at 10003ac0

void __thiscall FUN_10003ac0(void *this,byte param_1)

{
  FUN_10003be0((void *)((int)this + -0x4c),param_1);
  return;
}



// Function: FUN_10003ad0 at 10003ad0

void __fastcall FUN_10003ad0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f08;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[1] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x13] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x1f] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x20] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x21] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x22] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x23] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x24] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x25] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x26] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x27] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x28] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x29] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2a] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2b] = ATL::CComObject<class_CProgressCtrl>::vftable;
  param_1[0x2c] = ATL::CComObject<class_CProgressCtrl>::vftable;
  local_8 = 0;
  param_1[0x2f] = 0xc0000001;
  FUN_10004700();
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10018500((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003be0 at 10003be0

undefined4 * __thiscall FUN_10003be0(void *this,byte param_1)

{
  FUN_10003ad0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003c10 at 10003c10

void FUN_10003c10(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x94,param_2,param_3);
  return;
}



// Function: FUN_10003c20 at 10003c20

void FUN_10003c20(int param_1)

{
  FUN_10003790(param_1 + -0x88);
  return;
}



// Function: FUN_10003c30 at 10003c30

void FUN_10003c30(int param_1)

{
  FUN_10003770(param_1 + -0x80);
  return;
}



// Function: FUN_10003c40 at 10003c40

void FUN_10003c40(int param_1)

{
  FUN_10003790(param_1 + -0xa8);
  return;
}



// Function: FUN_10003c50 at 10003c50

void FUN_10003c50(int param_1)

{
  FUN_10003770(param_1 + -0xa0);
  return;
}



// Function: FUN_10003c60 at 10003c60

void FUN_10003c60(int param_1)

{
  FUN_100035f0(param_1 + -0x90);
  return;
}



// Function: FUN_10003c70 at 10003c70

void FUN_10003c70(int param_1)

{
  FUN_100035d0(param_1 + -0x88);
  return;
}



// Function: FUN_10003c80 at 10003c80

void FUN_10003c80(int param_1)

{
  FUN_100035f0(param_1 + -0xb0);
  return;
}



// Function: FUN_10003c90 at 10003c90

void FUN_10003c90(int param_1)

{
  FUN_100035d0(param_1 + -0xa8);
  return;
}



// Function: FUN_10003ca0 at 10003ca0

void FUN_10003ca0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x98,param_2,param_3);
  return;
}



// Function: FUN_10003cb0 at 10003cb0

void FUN_10003cb0(int param_1)

{
  FUN_10003790(param_1 + -0x8c);
  return;
}



// Function: FUN_10003cc0 at 10003cc0

void FUN_10003cc0(int param_1)

{
  FUN_10003770(param_1 + -0x84);
  return;
}



// Function: FUN_10003cd0 at 10003cd0

void FUN_10003cd0(int param_1)

{
  FUN_10003790(param_1 + -0xac);
  return;
}



// Function: FUN_10003ce0 at 10003ce0

void FUN_10003ce0(int param_1)

{
  FUN_10003770(param_1 + -0xa4);
  return;
}



// Function: FUN_10003cf0 at 10003cf0

void __thiscall FUN_10003cf0(void *this,byte param_1)

{
  FUN_100039d0((void *)((int)this + -0x4c),param_1);
  return;
}



// Function: FUN_10003d00 at 10003d00

void FUN_10003d00(int param_1)

{
  FUN_100035f0(param_1 + -0x94);
  return;
}



// Function: FUN_10003d10 at 10003d10

void FUN_10003d10(int param_1)

{
  FUN_100035d0(param_1 + -0x8c);
  return;
}



// Function: FUN_10003d20 at 10003d20

void FUN_10003d20(int param_1)

{
  FUN_100035d0(param_1 + -0xac);
  return;
}



// Function: FUN_10003d30 at 10003d30

void FUN_10003d30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x7c,param_2,param_3);
  return;
}



// Function: FUN_10003d40 at 10003d40

void FUN_10003d40(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x9c,param_2,param_3);
  return;
}



// Function: FUN_10003d50 at 10003d50

void FUN_10003d50(int param_1)

{
  FUN_10003790(param_1 + -0x90);
  return;
}



// Function: FUN_10003d60 at 10003d60

void FUN_10003d60(int param_1)

{
  FUN_10003770(param_1 + -0x88);
  return;
}



// Function: FUN_10003d70 at 10003d70

void FUN_10003d70(int param_1)

{
  FUN_10003790(param_1 + -0xb0);
  return;
}



// Function: FUN_10003d80 at 10003d80

void FUN_10003d80(int param_1)

{
  FUN_10003770(param_1 + -0xa8);
  return;
}



// Function: FUN_10003d90 at 10003d90

void FUN_10003d90(int param_1)

{
  FUN_100035f0(param_1 + -0x98);
  return;
}



// Function: FUN_10003da0 at 10003da0

void FUN_10003da0(int param_1)

{
  FUN_100035d0(param_1 + -0x90);
  return;
}



// Function: FUN_10003db0 at 10003db0

void FUN_10003db0(int param_1)

{
  FUN_100035d0(param_1 + -0xb0);
  return;
}



// Function: FUN_10003dc0 at 10003dc0

void FUN_10003dc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x80,param_2,param_3);
  return;
}



// Function: FUN_10003dd0 at 10003dd0

void FUN_10003dd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0xa0,param_2,param_3);
  return;
}



// Function: FUN_10003de0 at 10003de0

void FUN_10003de0(int param_1)

{
  FUN_10003790(param_1 + -0x94);
  return;
}



// Function: FUN_10003df0 at 10003df0

void FUN_10003df0(int param_1)

{
  FUN_10003770(param_1 + -0x8c);
  return;
}



// Function: FUN_10003e00 at 10003e00

void FUN_10003e00(int param_1)

{
  FUN_100035f0(param_1 + -0x7c);
  return;
}



// Function: FUN_10003e10 at 10003e10

void FUN_10003e10(int param_1)

{
  FUN_10003770(param_1 + -0xac);
  return;
}



// Function: FUN_10003e20 at 10003e20

void FUN_10003e20(int param_1)

{
  FUN_100035f0(param_1 + -0x9c);
  return;
}



// Function: FUN_10003e30 at 10003e30

void FUN_10003e30(int param_1)

{
  FUN_100035d0(param_1 + -0x94);
  return;
}



// Function: FUN_10003e40 at 10003e40

void FUN_10003e40(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x84,param_2,param_3);
  return;
}



// Function: FUN_10003e50 at 10003e50

void FUN_10003e50(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0xa4,param_2,param_3);
  return;
}



// Function: FUN_10003e60 at 10003e60

void FUN_10003e60(int param_1)

{
  FUN_10003790(param_1 + -0x98);
  return;
}



// Function: FUN_10003e70 at 10003e70

void FUN_10003e70(int param_1)

{
  FUN_10003770(param_1 + -0x90);
  return;
}



// Function: FUN_10003e80 at 10003e80

void FUN_10003e80(int param_1)

{
  FUN_100035f0(param_1 + -0x80);
  return;
}



// Function: FUN_10003e90 at 10003e90

void FUN_10003e90(int param_1)

{
  FUN_10003770(param_1 + -0xb0);
  return;
}



// Function: FUN_10003ea0 at 10003ea0

void FUN_10003ea0(int param_1)

{
  FUN_100035f0(param_1 + -0xa0);
  return;
}



// Function: FUN_10003eb0 at 10003eb0

void FUN_10003eb0(int param_1)

{
  FUN_100035d0(param_1 + -0x98);
  return;
}



// Function: FUN_10003ec0 at 10003ec0

void FUN_10003ec0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x88,param_2,param_3);
  return;
}



// Function: FUN_10003ed0 at 10003ed0

void FUN_10003ed0(int param_1)

{
  FUN_10003790(param_1 + -0x7c);
  return;
}



// Function: FUN_10003ee0 at 10003ee0

void __thiscall FUN_10003ee0(void *this,byte param_1)

{
  FUN_10003be0((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10003ef0 at 10003ef0

void FUN_10003ef0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0xa8,param_2,param_3);
  return;
}



// Function: FUN_10003f00 at 10003f00

void FUN_10003f00(int param_1)

{
  FUN_10003790(param_1 + -0x9c);
  return;
}



// Function: FUN_10003f10 at 10003f10

void FUN_10003f10(int param_1)

{
  FUN_10003770(param_1 + -0x94);
  return;
}



// Function: FUN_10003f20 at 10003f20

void FUN_10003f20(int param_1)

{
  FUN_100035f0(param_1 + -0x84);
  return;
}



// Function: FUN_10003f30 at 10003f30

void FUN_10003f30(int param_1)

{
  FUN_100035d0(param_1 + -0x7c);
  return;
}



// Function: FUN_10003f40 at 10003f40

void FUN_10003f40(int param_1)

{
  FUN_100035f0(param_1 + -0xa4);
  return;
}



// Function: FUN_10003f50 at 10003f50

void FUN_10003f50(int param_1)

{
  FUN_100035d0(param_1 + -0x9c);
  return;
}



// Function: FUN_10003f60 at 10003f60

void FUN_10003f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0x8c,param_2,param_3);
  return;
}



// Function: FUN_10003f70 at 10003f70

void FUN_10003f70(int param_1)

{
  FUN_10003790(param_1 + -0x80);
  return;
}



// Function: FUN_10003f80 at 10003f80

void FUN_10003f80(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100037b0(param_1 + -0xac,param_2,param_3);
  return;
}



// Function: FUN_10003f90 at 10003f90

void FUN_10003f90(int param_1)

{
  FUN_10003790(param_1 + -0xa0);
  return;
}



// Function: FUN_10003fa0 at 10003fa0

void FUN_10003fa0(int param_1)

{
  FUN_10003770(param_1 + -0x98);
  return;
}



// Function: FUN_10003fb0 at 10003fb0

void FUN_10003fb0(int param_1)

{
  FUN_100035f0(param_1 + -0x88);
  return;
}



// Function: FUN_10003fc0 at 10003fc0

void FUN_10003fc0(int param_1)

{
  FUN_100035d0(param_1 + -0x80);
  return;
}



// Function: FUN_10003fd0 at 10003fd0

void FUN_10003fd0(int param_1)

{
  FUN_100035f0(param_1 + -0xa8);
  return;
}



// Function: FUN_10003fe0 at 10003fe0

void FUN_10003fe0(int param_1)

{
  FUN_100035d0(param_1 + -0xa0);
  return;
}



// Function: FUN_10003ff0 at 10003ff0

void __thiscall FUN_10003ff0(void *this,RECT *param_1,RECT *param_2)

{
  BOOL BVar1;
  HRGN hRgn;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if ((param_1 != (RECT *)0x0) && (param_2 != (RECT *)0x0)) {
    *(LONG *)((int)this + 0x2c) = param_1->left;
    *(LONG *)((int)this + 0x30) = param_1->top;
    *(LONG *)((int)this + 0x34) = param_1->right;
    *(LONG *)((int)this + 0x38) = param_1->bottom;
    if (**(int **)((int)this + 0x3c) != 0) {
      hRgn = (HRGN)0x0;
      BVar1 = IntersectRect(&local_18,param_1,param_2);
      if (BVar1 != 0) {
        BVar1 = EqualRect(&local_18,param_1);
        if (BVar1 == 0) {
          OffsetRect(&local_18,-param_1->left,-param_1->top);
          hRgn = CreateRectRgnIndirect(&local_18);
        }
      }
      SetWindowRgn((HWND)**(undefined4 **)((int)this + 0x3c),hRgn,1);
      SetWindowPos((HWND)**(undefined4 **)((int)this + 0x3c),(HWND)0x0,param_1->left,param_1->top,
                   param_1->right - param_1->left,param_1->bottom - param_1->top,0x14);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100040e0 at 100040e0

undefined4 __thiscall
FUN_100040e0(void *this,int param_1,undefined4 param_2,uint *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int *param_7,undefined4 param_8)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_24;
  uint local_20;
  
  if (param_7 == (int *)0x0) {
    if ((*(byte *)((int)this + 0x44) & 2) == 0) {
      return 0x80070057;
    }
    param_7 = (int *)((int)this + 0x2c);
  }
  if (((param_1 != 1) && (param_1 != 0x10)) && (param_1 != 0x20)) {
    return 0x8004006b;
  }
  if (param_4 == 0) {
    param_5 = 0;
  }
  uVar2 = 0;
  if ((param_3 != (uint *)0x0) && (7 < *param_3)) {
    uVar2 = param_3[1] & 1;
  }
  memset(&local_40,0,0x3c);
  local_3c = param_1;
  local_38 = param_2;
  local_34 = param_4;
  local_2c = param_6;
                    /* WARNING: Load size is inaccurate */
  local_28 = param_7;
  local_24 = param_8;
  local_40 = 0x3c;
  local_30 = param_5;
  local_20 = uVar2;
  uVar1 = (**(code **)(*this + 0xc))(&local_40);
  return uVar1;
}



// Function: FUN_100041a0 at 100041a0

void __thiscall FUN_100041a0(void *this,int param_1,undefined4 *param_2)

{
  HMETAFILE hmf;
  HGLOBAL hMem;
  undefined4 *puVar1;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  HDC local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  uint local_3c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_2 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  if ((*(byte *)(param_1 + 0x10) & 0x20) == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((*(uint *)((int)this + 0x44) & 0x1000) == 0) {
    local_10 = *(int *)((int)this + 0x24);
    local_c = *(int *)((int)this + 0x28);
  }
  else {
    local_10 = *(int *)((int)this + 0x1c);
    local_c = *(int *)((int)this + 0x20);
  }
  local_20 = local_10;
  local_1c = local_c;
  if ((*(uint *)((int)this + 0x44) & 0x2000) == 0) {
    FUN_100033b0(&local_20,&local_28);
    local_10 = local_28;
    local_c = local_24;
  }
  local_18 = 0;
  local_14 = 0;
  memset(&local_64,0,0x3c);
  local_4c = &local_18;
  local_3c = *(uint *)((int)this + 0x44) >> 0xd & 1;
  local_64 = 0x3c;
  local_60 = 1;
  local_5c = 0xffffffff;
  local_58 = 0;
  local_54 = 0;
  local_44 = 1;
  local_48 = local_4c;
  local_50 = CreateMetaFileW((LPCWSTR)0x0);
  SaveDC(local_50);
  SetWindowOrgEx(local_50,0,0,(LPPOINT)0x0);
  SetWindowExtEx(local_50,local_10,local_c,(LPSIZE)0x0);
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0xc))(&local_64);
  RestoreDC(local_50,-1);
  hmf = CloseMetaFile(local_50);
  if (hmf == (HMETAFILE)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  hMem = GlobalAlloc(0x2002,0x10);
  if (hMem == (HGLOBAL)0x0) {
    DeleteMetaFile(hmf);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  puVar1 = (undefined4 *)GlobalLock(hMem);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = hmf;
    *puVar1 = 8;
    puVar1[1] = local_20;
    puVar1[2] = local_1c;
    GlobalUnlock(hMem);
    param_2[1] = hMem;
    *param_2 = 0x20;
    param_2[2] = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001150(0x80004005);
}



// Function: FUN_10004390 at 10004390

void __thiscall FUN_10004390(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if ((*(uint *)((int)this + 0x44) & 0x1000) == 0) {
    local_c = *(int *)((int)this + 0x24);
    local_8 = *(int *)((int)this + 0x28);
  }
  else {
    local_c = *(int *)((int)this + 0x1c);
    local_8 = *(int *)((int)this + 0x20);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_100033b0(&local_c,&local_c);
  }
  iVar2 = piVar1[2] - *piVar1;
  iVar3 = piVar1[3] - piVar1[1];
  *(int *)(param_1 + 0x2c) = iVar2;
  *(int *)(param_1 + 0x30) = iVar3;
  *(int *)(param_1 + 0x34) = local_c;
  *(int *)(param_1 + 0x38) = local_8;
  if ((((local_c == 0) || (local_8 == 0)) || (iVar2 == 0)) || (iVar3 == 0)) {
    *(undefined4 *)(param_1 + 0x38) = 1;
    *(undefined4 *)(param_1 + 0x34) = 1;
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 1;
  }
  else if ((iVar2 != local_c) || (iVar3 != local_8)) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



// Function: FUN_10004440 at 10004440

void __fastcall FUN_10004440(int *param_1)

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



// Function: FUN_10004470 at 10004470

void __fastcall FUN_10004470(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10004490 at 10004490

void __fastcall FUN_10004490(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100044a0 at 100044a0

void __fastcall FUN_100044a0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ff8;
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



// Function: FUN_100044f0 at 100044f0

void __fastcall FUN_100044f0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a02b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004540 at 10004540

void __fastcall FUN_10004540(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10004550 at 10004550

void __thiscall FUN_10004550(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlAdd<> at 10004580

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



// Function: FUN_100045b0 at 100045b0

undefined4 __cdecl FUN_100045b0(int *param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  if ((-param_3 - 1U <= param_5) && ((-param_3 - 1U < param_5 || (-param_2 - 1 < param_4)))) {
    return 0x80070216;
  }
  param_1[1] = param_3 + param_5 + (uint)CARRY4(param_2,param_4);
  *param_1 = param_2 + param_4;
  return 0;
}



// Function: FUN_10004600 at 10004600

int FUN_10004600(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar5 = param_2;
  piVar4 = param_1;
  uVar1 = param_1[6];
  local_28 = param_1[1];
  local_1c = param_4;
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  param_1 = (int *)0x0;
  piVar4[6] = (int)&local_28;
  local_20 = param_3;
  local_c = 0x24;
  local_8 = 1;
  local_24 = param_2;
  param_2 = uVar1;
  piVar6 = (int *)(**(code **)*piVar4)(local_28,uVar5,param_3,param_4,&param_1,0);
  piVar4[6] = param_2;
  piVar7 = piVar6;
  if (piVar6 == (int *)0x0) {
    if (uVar5 == 0x82) {
      piVar4[7] = piVar4[7] | 1;
    }
  }
  else {
    piVar7 = param_1;
    if (uVar5 < 0x3a) {
      if ((uVar5 == 0x39) || ((0x2d < uVar5 && ((uVar5 < 0x30 || (uVar5 == 0x37))))))
      goto LAB_100046c3;
    }
    else if ((uVar5 == 0x110) || ((0x131 < uVar5 && (uVar5 < 0x139)))) goto LAB_100046c3;
    piVar7 = piVar6;
    if ((*(byte *)(piVar4 + 7) & 1) == 0) {
      SetWindowLongW((HWND)piVar4[1],0,(LONG)param_1);
    }
  }
LAB_100046c3:
  if (((piVar4[7] & 1U) != 0) && (piVar4[6] == 0)) {
    iVar2 = piVar4[1];
    piVar4[7] = piVar4[7] & 0xfffffffe;
    pcVar3 = *(code **)(*piVar4 + 0xc);
    piVar4[1] = 0;
    (*pcVar3)(iVar2);
  }
  return (int)piVar7;
}



// Function: FUN_10004700 at 10004700

void FUN_10004700(void)

{
  return;
}



// Function: FUN_10004710 at 10004710

void __cdecl FUN_10004710(int *param_1,size_t param_2,void *param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
  if ((int)param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
  if (param_3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_10004778;
    pvVar1 = calloc(param_2,2);
  }
  else {
    if ((int)param_2 <= param_4) {
      free(pvVar1);
LAB_10004778:
      *param_1 = (int)param_3;
      goto LAB_1000477a;
    }
    pvVar1 = _recalloc(pvVar1,param_2,2);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x8007000e);
    }
  }
  *param_1 = (int)pvVar1;
LAB_1000477a:
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  }
  return;
}



// Function: FUN_100047b0 at 100047b0

void __cdecl FUN_100047b0(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 * 2);
  return;
}



// Function: FUN_100047d0 at 100047d0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_100047d0(int param_1)

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
  
  puStack_10 = &LAB_100193b4;
  local_14 = ExceptionList;
  local_c = DAT_10029f90 ^ 0x10023638;
  local_38 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10004890 at 10004890

undefined4 __thiscall FUN_10004890(void *this,undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (param_2 == 0) {
    return 0x80004003;
  }
  if (piVar1 == (int *)0x0) {
    return 0x80070057;
  }
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_1,&DAT_1002006c,0x400,2,&local_14,param_2,0,0);
  return uVar2;
}



// Function: FUN_100048f0 at 100048f0

int * __thiscall FUN_100048f0(void *this,int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070057);
  }
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = Ordinal_4(0,param_1);
    *(int *)this = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_10004930 at 10004930

int __thiscall FUN_10004930(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  void *local_8;
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
                    /* WARNING: Load size is inaccurate */
  iVar2 = 4;
  local_8 = this;
  if (*this != 0) {
    iVar2 = Ordinal_149(*this);
    iVar2 = iVar2 + 6;
  }
  param_1 = (int *)(iVar2 + -4);
  iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,&param_1,4,&local_8);
  if (-1 < iVar2) {
    if (param_1 == (int *)0x0) {
      return (int)param_1;
    }
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,*this,param_1,&local_8);
  }
  return iVar2;
}



// Function: FUN_100049b0 at 100049b0

void __fastcall FUN_100049b0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100049c0 at 100049c0

int __fastcall FUN_100049c0(int param_1)

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
  DAT_10029fc8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_10029fb8 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10004a30 at 10004a30

void __fastcall FUN_10004a30(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001fb0(param_1 + 4);
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



// Function: FUN_10004a80 at 10004a80

void __fastcall FUN_10004a80(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a058;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001fb0(param_1 + 4);
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



// Function: FUN_10004b00 at 10004b00

void __fastcall FUN_10004b00(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10004b20 at 10004b20

void __thiscall FUN_10004b20(void *this,LPCWSTR param_1)

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
  
  puStack_c = &LAB_1001a08b;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = param_1;
  local_220 = (HKEY)0x0;
  local_21c = 0;
  local_218 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = FUN_10001790(&local_220,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    local_224 = 0x100;
    iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          &local_230);
    while (iVar1 == 0) {
      iVar1 = FUN_10004b20(&local_220,local_214);
      if (iVar1 != 0) goto LAB_10004b8f;
      local_224 = 0x100;
      iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
    }
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
    local_21c = 0;
    FUN_10001640(this,local_228);
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  else {
LAB_10004b8f:
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



// Function: FUN_10004cb0 at 10004cb0

undefined4 __fastcall FUN_10004cb0(int *param_1)

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



// Function: FUN_10004d40 at 10004d40

void __thiscall FUN_10004d40(void *this,LPCWSTR param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a0c8;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar1 = lstrlenW(param_1);
  FUN_10001940(this,param_1,iVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004dc0 at 10004dc0

void FUN_10004dc0(int param_1)

{
  FUN_10004cb0((int *)(param_1 + 4));
  return;
}



// Function: FUN_10004de0 at 10004de0

void FUN_10004de0(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  puStack_c = &LAB_1001a0fb;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10004fad;
  *param_3 = 0;
  *param_4 = 0;
  local_240 = 0;
  local_8 = 0;
  DVar3 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar3 == 0) {
    FUN_100014a0();
  }
  else {
    if (DVar3 == 0x104) {
      local_8 = 0xffffffff;
      FUN_10004440(&local_240);
      goto LAB_10004fad;
    }
    pwVar4 = (wchar_t *)FUN_10001e90();
    if (param_2 != (LPCWSTR)0x0) {
      uVar5 = lstrlenW(param_2);
      uVar1 = uVar5 + DVar3;
      if (((DVar3 <= uVar1) && (uVar5 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_10001230(local_23c + DVar3,0x10e - DVar3,param_2);
        goto LAB_10004ef0;
      }
LAB_10004f8f:
      local_8 = 0xffffffff;
      FUN_10004440(&local_240);
      goto LAB_10004fad;
    }
LAB_10004ef0:
    iVar6 = Ordinal_161(local_23c,param_4,uVar2);
    if (iVar6 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar6 = (int)pwVar4 - (int)local_23c >> 1;
      if (0x104 < iVar6 + 5U) goto LAB_10004f8f;
      FUN_10001230(pwVar4,0x10e - iVar6,local_20);
      iVar6 = Ordinal_161(local_23c,param_4);
      if (iVar6 < 0) goto LAB_10004e5f;
    }
    uVar7 = Ordinal_2(local_23c);
    *param_3 = uVar7;
  }
LAB_10004e5f:
  local_8 = 0xffffffff;
  FUN_10004440(&local_240);
LAB_10004fad:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004fd0 at 10004fd0

void __fastcall FUN_10004fd0(int param_1)

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
  piVar5 = DAT_1002a088;
  if (DAT_1002a088 < DAT_1002a08c) {
    do {
      if (*piVar5 != 0) {
        (**(code **)(*piVar5 + 0x20))(0);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < DAT_1002a08c);
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



// Function: FUN_100050c0 at 100050c0

void __fastcall FUN_100050c0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a138;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029f90 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005110 at 10005110

undefined4 FUN_10005110(int param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  piVar1 = *(int **)(param_1 + 0xe0);
  *param_2 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// Function: FUN_10005140 at 10005140

void __thiscall FUN_10005140(void *this,undefined4 param_1,undefined4 param_2)

{
  if (this != (void *)0x0) {
    (*(code *)**(undefined4 **)((int)this + -4))((undefined4 *)((int)this + -4),param_1,param_2);
    return;
  }
  (*(code *)*puRam00000000)(0,param_1,param_2);
  return;
}



// Function: FUN_10005180 at 10005180

undefined4 __thiscall FUN_10005180(void *this,int *param_1)

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
  puStack_c = &LAB_1001a173;
  local_10 = ExceptionList;
  uStack_38 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
      local_20 = (uint *)FUN_100192db(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_10002720,FUN_10002010);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_10005261();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_10005261();
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



// Function: Catch@10005251 at 10005251

undefined * Catch_10005251(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000525e;
}



// Function: FUN_10005261 at 10005261

undefined4 FUN_10005261(void)

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



// Function: FUN_10005370 at 10005370

void FUN_10005370(int param_1)

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
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10002010);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100053d0 at 100053d0

HRESULT FUN_100053d0(undefined4 param_1,LPENUMOLEVERB *param_2)

{
  HRESULT HVar1;
  
  if (param_2 == (LPENUMOLEVERB *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = OleRegEnumVerbs((IID *)&DAT_1001e5d8,param_2);
  return HVar1;
}



// Function: FUN_10005400 at 10005400

void FUN_10005400(undefined4 param_1,DWORD param_2,LPOLESTR *param_3)

{
  OleRegGetUserType((IID *)&DAT_1001e5d8,param_2,param_3);
  return;
}



// Function: FUN_10005420 at 10005420

void FUN_10005420(undefined4 param_1,DWORD param_2,DWORD *param_3)

{
  OleRegGetMiscStatus((IID *)&DAT_1001e5d8,param_2,param_3);
  return;
}



// Function: FUN_10005440 at 10005440

void FUN_10005440(int param_1,int param_2,undefined4 param_3,uint *param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,int *param_8,undefined4 param_9)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x8c;
  }
  FUN_100040e0((void *)(iVar1 + 4),param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_10005480 at 10005480

undefined4 FUN_10005480(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_1 + -0x8c;
    }
    *param_4 = *(undefined4 *)(iVar2 + 0x18);
    if (*(int *)(iVar2 + 0x18) != 0) {
      (**(code **)(**(int **)(iVar2 + 0x18) + 4))(*(int **)(iVar2 + 0x18));
    }
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100054c0 at 100054c0

void FUN_100054c0(int param_1,RECT *param_2,RECT *param_3)

{
  if (param_1 != 0) {
    FUN_10003ff0((void *)(param_1 + -0x8c),param_2,param_3);
    return;
  }
  FUN_10003ff0((void *)0x4,param_2,param_3);
  return;
}



// Function: FUN_10005500 at 10005500

bool FUN_10005500(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x90;
  }
  local_28 = 0;
  local_1c = param_4;
  uVar1 = *(undefined4 *)(iVar3 + 100);
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  *(undefined4 **)(iVar3 + 100) = &local_28;
  local_20 = param_3;
  local_24 = param_2;
  local_c = 0x24;
  local_8 = 1;
  iVar2 = (*(code *)**(undefined4 **)(iVar3 + 0x4c))
                    (*(undefined4 *)(iVar3 + 0x50),param_2,param_3,param_4,param_5,0);
  *(undefined4 *)(iVar3 + 100) = uVar1;
  return iVar2 == 0;
}



// Function: FUN_10005590 at 10005590

undefined4 FUN_10005590(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0xe5708db4;
  param_2[1] = 0x4e45865a;
  param_2[2] = 0xc935f4a8;
  param_2[3] = 0xe97024b;
  return 0;
}



// Function: FUN_100055d0 at 100055d0

void FUN_100055d0(undefined4 param_1,int *param_2)

{
  FUN_10003440(param_2,0x1001ee20);
  return;
}



// Function: FUN_100055f0 at 100055f0

void FUN_100055f0(int param_1,int param_2,undefined4 *param_3)

{
  if (param_1 != 0) {
    FUN_100041a0((void *)(param_1 + -0xa4),param_2,param_3);
    return;
  }
  FUN_100041a0((void *)0x4,param_2,param_3);
  return;
}



// Function: FUN_10005630 at 10005630

void FUN_10005630(IDataObject *param_1,FORMATETC *param_2,DWORD param_3,IAdviseSink *param_4,
                 DWORD *param_5)

{
  IDataObjectVtbl *This;
  IDataObject *pIVar1;
  HRESULT HVar2;
  
  if (param_1 == (IDataObject *)0x0) {
    pIVar1 = (IDataObject *)0x0;
  }
  else {
    pIVar1 = param_1 + -0x2a;
  }
  if ((pIVar1[3].lpVtbl == (IDataObjectVtbl *)0x0) &&
     (HVar2 = CreateDataAdviseHolder((LPDATAADVISEHOLDER *)(pIVar1 + 3)), HVar2 != 0)) {
    return;
  }
  This = pIVar1[3].lpVtbl;
  (*((IDataAdviseHolderVtbl *)This->QueryInterface)->Advise)
            ((IDataAdviseHolder *)This,param_1,param_2,param_3,param_4,param_5);
  return;
}



// Function: FUN_10005680 at 10005680

undefined4 FUN_10005680(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0xa8;
  }
  piVar1 = *(int **)(iVar2 + 0xc);
  if (piVar1 == (int *)0x0) {
    return 0x80040004;
  }
  uVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
  return uVar3;
}



// Function: FUN_100056c0 at 100056c0

void __thiscall
FUN_100056c0(void *this,HWND param_1,int *param_2,LPCWSTR param_3,DWORD param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  HWND pHVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = &DAT_100280b8;
  }
  pHVar1 = CreateWindowExW(param_5,L"AtlAxWinLic100",param_3,param_4,*param_2,param_2[1],
                           param_2[2] - *param_2,param_2[3] - param_2[1],param_1,param_6,
                           DAT_1002a0b0,param_7);
  *(HWND *)this = pHVar1;
  return;
}



// Function: FUN_10005720 at 10005720

void __cdecl FUN_10005720(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined1 local_414 [4];
  undefined4 *local_410;
  short local_40c [2];
  int local_408;
  int local_404;
  void *local_400;
  undefined1 local_3fc [1000];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a19b;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_410 = param_2;
  *param_2 = 0;
  if ((((param_1 == (int *)0x0) ||
       (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_40c,2,&local_404,local_14), iVar1 < 0))
      || (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_414,4,&local_404), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_408,4,&local_404), iVar1 < 0))
  goto LAB_10005919;
  if (local_408 != 0) {
    FUN_100048f0(&local_400,local_408);
    pvVar2 = local_400;
    local_8 = 0;
    iVar1 = Ordinal_7(local_400);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      Ordinal_6(pvVar2);
      goto LAB_10005919;
    }
    memset(pvVar2,0,local_408 * 2 + 2);
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,pvVar2,local_408 * 2,&local_404);
    if (iVar1 < 0) {
      local_8 = 0xffffffff;
      Ordinal_6(pvVar2);
      goto LAB_10005919;
    }
    local_400 = (void *)0x0;
    *local_410 = pvVar2;
    local_8 = 0xffffffff;
    Ordinal_6(0);
  }
  if (((local_40c[0] == 0x37a) || (local_40c[0] == 0x37b)) &&
     (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_400,4,&local_404), -1 < iVar1)) {
    for (local_400 = (void *)((int)local_400 - 4); local_400 != (void *)0x0;
        local_400 = (void *)((int)local_400 - local_404)) {
      pvVar2 = local_400;
      if ((void *)0x3e7 < local_400) {
        pvVar2 = (void *)0x3e8;
      }
      (**(code **)(*param_1 + 0xc))(param_1,local_3fc,pvVar2,&local_404);
    }
  }
LAB_10005919:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005940 at 10005940

void __thiscall FUN_10005940(void *this,int param_1)

{
  *(int *)((int)this + 0x10) = param_1;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  *(undefined2 *)((int)this + param_1 * 2) = 0;
  return;
}



// Function: FUN_10005960 at 10005960

HDC FUN_10005960(HDC param_1,int param_2)

{
  int iVar1;
  HDC pHVar2;
  wchar_t *pwszDriver;
  LPCWSTR pwszDevice;
  LPCWSTR pszPort;
  DEVMODEW *pdm;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a1d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pdm = (DEVMODEW *)0x0;
  local_14 = 0;
  local_8 = 0;
  if (param_2 == 0) {
    if (param_1 != (HDC)0x0) {
      iVar1 = GetDeviceCaps(param_1,2);
      if (iVar1 != 5) {
        local_8 = 0xffffffff;
        FUN_10004440(&local_14);
        ExceptionList = local_10;
        return param_1;
      }
    }
    pdm = (DEVMODEW *)0x0;
    pszPort = (LPCWSTR)0x0;
    pwszDevice = (LPCWSTR)0x0;
    pwszDriver = L"DISPLAY";
  }
  else {
    if (*(ushort *)(param_2 + 10) != 0) {
      pdm = (DEVMODEW *)(param_2 + (uint)*(ushort *)(param_2 + 10));
    }
    pwszDriver = (wchar_t *)((uint)*(ushort *)(param_2 + 4) + param_2);
    pwszDevice = (LPCWSTR)((uint)*(ushort *)(param_2 + 6) + param_2);
    pszPort = (LPCWSTR)((uint)*(ushort *)(param_2 + 8) + param_2);
  }
  pHVar2 = CreateDCW(pwszDriver,pwszDevice,pszPort,pdm);
  ExceptionList = local_10;
  return pHVar2;
}



// Function: FUN_10005a20 at 10005a20

void __thiscall FUN_10005a20(void *this,undefined4 param_1,HDC param_2)

{
  BOOL BVar1;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  COLORREF local_10;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_1c = 0;
  local_18 = 0;
  local_20 = 0xc;
  BVar1 = SystemParametersInfoW(0x42,0xc,&local_20,0);
  if ((BVar1 != 0) && ((local_1c & 1) != 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  GetObjectW(*(HANDLE *)((int)this + 0x70),0xc,local_14);
  SetBkColor(param_2,local_10);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005ab0 at 10005ab0

undefined4 __fastcall FUN_10005ab0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  (**(code **)(*(int *)(iVar1 + 0x90) + 0x18))(iVar1 + 0x90);
  if (*(HWND *)(iVar1 + 0x50) != (HWND)0x0) {
    ShowWindow(*(HWND *)(iVar1 + 0x50),0);
  }
  return 0;
}



// Function: FUN_10005af0 at 10005af0

int FUN_10005af0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a200;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(400);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10002060(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_10005b9d();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_10005b9d();
  return iVar2;
}



// Function: Catch@10005b87 at 10005b87

undefined * Catch_10005b87(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005b94;
}



// Function: FUN_10005b9d at 10005b9d

int FUN_10005b9d(void)

{
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    unaff_ESI[0x2f] = unaff_ESI[0x2f] + 1;
    unaff_ESI[0x2f] = unaff_ESI[0x2f] + -1;
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI != 0) {
      (**(code **)unaff_ESI[1])(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10005be0 at 10005be0

void FUN_10005be0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1,(int *)&PTR_DAT_1001ebc8,param_2,param_3);
  return;
}



// Function: FUN_10005c00 at 10005c00

undefined4 * __thiscall FUN_10005c00(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a22b;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CProgressCtrl>::vftable;
  FUN_10003670((void *)((int)this + 8),param_1);
  local_8 = 0;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005c80 at 10005c80

int FUN_10005c80(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_100023b0((int)(param_1 + 2),(int *)&PTR_DAT_1001ebc8,param_2,param_3);
  return iVar1;
}



// Function: FUN_10005cf0 at 10005cf0

undefined4 * __thiscall FUN_10005cf0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a263;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CProgressCtrl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  FUN_10004700();
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10018500((int)this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005d80 at 10005d80

void __fastcall FUN_10005d80(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_10005da0 at 10005da0

void __thiscall FUN_10005da0(void *this,LPCSTR param_1,UINT param_2)

{
  size_t cbMultiByte;
  int iVar1;
  DWORD DVar2;
  size_t cchWideChar;
  bool bVar3;
  
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)this = 0;
    return;
  }
  iVar1 = lstrlenA(param_1);
  cbMultiByte = iVar1 + 1;
  FUN_10004710((int *)this,cbMultiByte,(void *)((int)this + 4),0x80);
                    /* WARNING: Load size is inaccurate */
  iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*this,cbMultiByte);
  bVar3 = iVar1 == 0;
  if (bVar3) {
    DVar2 = GetLastError();
    if (DVar2 == 0x7a) {
      cchWideChar = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,(LPWSTR)0x0,0);
      FUN_10004710((int *)this,cchWideChar,(void *)((int)this + 4),0x80);
                    /* WARNING: Load size is inaccurate */
      iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*this,cchWideChar);
      bVar3 = iVar1 == 0;
    }
    if (bVar3) {
      FUN_10002160();
    }
  }
  return;
}



// Function: FUN_10005e50 at 10005e50

int FUN_10005e50(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0x110) {
    iVar1 = (**(code **)(*param_1 + 0x10))(0x67);
    if (iVar1 < 0) {
      param_1[9] = iVar1;
      if ((char)param_1[8] != '\0') {
        EndDialog((HWND)param_1[1],-1);
      }
      return 0;
    }
  }
  iVar1 = FUN_10004600(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_10005eb0 at 10005eb0

int FUN_10005eb0(int param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  
  if ((param_2 == 0) || (*(uint *)(param_1 + 8) < param_2)) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar3 = param_2 - 1;
    if ((iVar3 < 0) || ((int)*(uint *)(param_1 + 8) <= iVar3)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(param_1 + 4) + iVar3 * 4);
    }
  }
  uVar1 = param_2 - 1;
  if (((uVar1 < param_2) && (uVar1 < *(uint *)(param_1 + 8))) &&
     (*(int *)(*(int *)(param_1 + 4) + uVar1 * 4) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 4) + uVar1 * 4) = 0;
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  iVar3 = (-(uint)bVar2 & 0x7ffbfe00) + 0x80040200;
  if ((iVar3 == 0) && (piVar4 != (int *)0x0)) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return iVar3;
}



// Function: FUN_10005f30 at 10005f30

void __fastcall FUN_10005f30(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a290;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029f90 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005f80 at 10005f80

undefined4 __thiscall FUN_10005f80(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a2b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  Ordinal_8(local_30,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  piVar1 = *(int **)((int)this + 0x18);
  uVar2 = 0x80004005;
  if (piVar1 != (int *)0x0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    uVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,0xfffffd43,&DAT_1002006c,0x400,2,&local_20,local_30,0,0);
  }
  *param_1 = local_28;
  local_8 = 0xffffffff;
  Ordinal_9(local_30);
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10006030 at 10006030

undefined4 __thiscall FUN_10006030(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a2b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  Ordinal_8(local_30,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  piVar1 = *(int **)((int)this + 0x18);
  uVar2 = 0x80004005;
  if (piVar1 != (int *)0x0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    uVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,0xfffffd3f,&DAT_1002006c,0x400,2,&local_20,local_30,0,0);
  }
  *param_1 = local_28;
  local_8 = 0xffffffff;
  Ordinal_9(local_30);
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100060e0 at 100060e0

int __thiscall FUN_100060e0(void *this,uint *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  short local_20 [4];
  short local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a2e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  Ordinal_8(local_20,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  piVar1 = *(int **)((int)this + 0x18);
  iVar2 = -0x7fffbffb;
  if (piVar1 != (int *)0x0) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,0xfffffd3b,&DAT_1002006c,0x400,2,&local_30,local_20,0,0);
    if (-1 < iVar2) {
      if (local_20[0] != 0xb) {
        local_8 = 0xffffffff;
        Ordinal_9(local_20);
        ExceptionList = local_10;
        return -0x7ffdfffb;
      }
      *param_1 = (uint)(local_18 != 0);
    }
  }
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_100061c0 at 100061c0

void __fastcall FUN_100061c0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba83;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
        piVar3 = piVar3 + 2;
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



// Function: FUN_10006250 at 10006250

void FUN_10006250(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x98,param_2,param_3);
  return;
}



// Function: FUN_10006260 at 10006260

void FUN_10006260(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x7c,param_2,param_3);
  return;
}



// Function: FUN_10006270 at 10006270

void FUN_10006270(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x9c,param_2,param_3);
  return;
}



// Function: FUN_10006280 at 10006280

void FUN_10006280(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x80,param_2,param_3);
  return;
}



// Function: FUN_10006290 at 10006290

void FUN_10006290(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0xa0,param_2,param_3);
  return;
}



// Function: FUN_100062a0 at 100062a0

void FUN_100062a0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x84,param_2,param_3);
  return;
}



// Function: FUN_100062b0 at 100062b0

void FUN_100062b0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0xa4,param_2,param_3);
  return;
}



// Function: FUN_100062c0 at 100062c0

void FUN_100062c0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x88,param_2,param_3);
  return;
}



// Function: FUN_100062d0 at 100062d0

void FUN_100062d0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0xa8,param_2,param_3);
  return;
}



// Function: FUN_100062e0 at 100062e0

void FUN_100062e0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x8c,param_2,param_3);
  return;
}



// Function: FUN_100062f0 at 100062f0

void FUN_100062f0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0xac,param_2,param_3);
  return;
}



// Function: FUN_10006300 at 10006300

void FUN_10006300(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x90,param_2,param_3);
  return;
}



// Function: FUN_10006310 at 10006310

void FUN_10006310(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005be0(param_1 + -0x94,param_2,param_3);
  return;
}



// Function: FUN_10006320 at 10006320

void __thiscall FUN_10006320(void *this,int param_1)

{
  LONG *pLVar1;
  HDC pHVar2;
  int iVar3;
  bool bVar4;
  tagPOINT local_18;
  LONG local_10;
  LONG local_c;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  bVar4 = false;
  if (*(int *)(param_1 + 0x10) == 0) {
    pHVar2 = FUN_10005960(*(HDC *)(param_1 + 0x14),*(int *)(param_1 + 0xc));
    bVar4 = pHVar2 != *(HDC *)(param_1 + 0x14);
    *(HDC *)(param_1 + 0x10) = pHVar2;
  }
  pLVar1 = *(LONG **)(param_1 + 0x18);
  local_18.x = *pLVar1;
  local_18.y = pLVar1[1];
  local_10 = pLVar1[2];
  local_c = pLVar1[3];
  iVar3 = GetDeviceCaps(*(HDC *)(param_1 + 0x14),2);
  if (iVar3 != 5) {
    LPtoDP(*(HDC *)(param_1 + 0x14),&local_18,2);
    SaveDC(*(HDC *)(param_1 + 0x14));
    SetMapMode(*(HDC *)(param_1 + 0x14),1);
    SetWindowOrgEx(*(HDC *)(param_1 + 0x14),0,0,(LPPOINT)0x0);
    SetViewportOrgEx(*(HDC *)(param_1 + 0x14),0,0,(LPPOINT)0x0);
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  *(tagPOINT **)(param_1 + 0x18) = &local_18;
  FUN_10004390(this,param_1);
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x10))(param_1);
  if (bVar4) {
    DeleteDC(*(HDC *)(param_1 + 0x10));
  }
  if (iVar3 != 5) {
    RestoreDC(*(HDC *)(param_1 + 0x14),-1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006430 at 10006430

undefined4 * __thiscall FUN_10006430(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (-param_1 - 1U < 8) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070216);
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



// Function: FUN_10006480 at 10006480

void __fastcall FUN_10006480(undefined4 *param_1)

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



// Function: FUN_100064c0 at 100064c0

undefined4 __thiscall FUN_100064c0(void *this,undefined4 *param_1)

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



// Function: FUN_10006530 at 10006530

void __fastcall FUN_10006530(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10006550 at 10006550

void __fastcall FUN_10006550(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10004540(param_1);
    return;
  }
  return;
}



// Function: FUN_10006560 at 10006560

void __fastcall FUN_10006560(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a323;
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



// Function: FUN_100065c0 at 100065c0

void __fastcall FUN_100065c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a356;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006620 at 10006620

void __fastcall FUN_10006620(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a393;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029f90 ^ (uint)&stack0xfffffffc,(int *)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006680 at 10006680

void __fastcall FUN_10006680(int *param_1)

{
  int *_Memory;
  
  if ((*param_1 != 0) && (_Memory = (int *)(*param_1 + -8), *_Memory == 0xdddd)) {
    free(_Memory);
  }
  *param_1 = 0;
  return;
}



// Function: FUN_100066b0 at 100066b0

void __fastcall FUN_100066b0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100066d0 at 100066d0

bool __thiscall FUN_100066d0(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3e0;
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
    (**(code **)**this)(*this,&PTR_1001f43c,&local_18,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&PTR_1001f43c,&local_14);
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



// Function: FUN_100067c0 at 100067c0

HRESULT __thiscall FUN_100067c0(void *this,LPSTREAM param_1)

{
  LPSTREAM This;
  HRESULT HVar1;
  int iVar2;
  LPSTREAM pIVar3;
  undefined1 local_20 [8];
  LPSTREAM local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  This = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a420;
  local_10 = ExceptionList;
  if (param_1 == (LPSTREAM)0x0) {
    return -0x7ff8ffa9;
  }
  ExceptionList = &local_10;
  HVar1 = (*param_1->lpVtbl->Write)(param_1,this,2,(ULONG *)0x0);
  if (-1 < HVar1) {
                    /* WARNING: Load size is inaccurate */
    switch(*this) {
    case 2:
    case 0xb:
    case 0x12:
      HVar1 = (*This->lpVtbl->Write)(This,(void *)((int)this + 8),2,(ULONG *)0x0);
      ExceptionList = local_10;
      return HVar1;
    case 3:
    case 4:
    case 10:
    case 0x13:
    case 0x16:
    case 0x17:
      HVar1 = (*This->lpVtbl->Write)(This,(void *)((int)this + 8),4,(ULONG *)0x0);
      ExceptionList = local_10;
      return HVar1;
    case 5:
    case 6:
    case 7:
    case 0x14:
    case 0x15:
      HVar1 = (*This->lpVtbl->Write)(This,(void *)((int)this + 8),8,(ULONG *)0x0);
      ExceptionList = local_10;
      return HVar1;
    default:
      param_1 = (LPSTREAM)0x0;
      local_8 = 2;
      Ordinal_8(local_20);
      local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
      if (*this == 8) {
        pIVar3 = *(LPSTREAM *)((int)this + 8);
      }
      else {
        iVar2 = Ordinal_12(local_20,this,1,8);
        pIVar3 = local_18;
        if (iVar2 < 0) {
          local_8 = CONCAT31(local_8._1_3_,2);
          Ordinal_9(local_20);
          local_8 = 0xffffffff;
          Ordinal_6(0);
          ExceptionList = local_10;
          return iVar2;
        }
      }
      if (pIVar3 != (LPSTREAM)0x0) {
        Ordinal_6(0);
        param_1 = pIVar3;
      }
      HVar1 = FUN_10004930(&param_1,(int *)This);
      param_1 = (LPSTREAM)0x0;
      local_8 = CONCAT31(local_8._1_3_,2);
      Ordinal_9(local_20);
      local_8 = 0xffffffff;
      Ordinal_6(0);
      break;
    case 9:
    case 0xd:
      param_1 = (LPSTREAM)0x0;
      local_8 = 1;
      if (((*(int *)((int)this + 8) == 0) ||
          (iVar2 = (**(code **)**(undefined4 **)((int)this + 8))
                             (*(undefined4 **)((int)this + 8),&DAT_1001f4ac,&param_1), -1 < iVar2))
         || (HVar1 = (**(code **)**(undefined4 **)((int)this + 8))
                               (*(undefined4 **)((int)this + 8),&DAT_1001ed80,&param_1), -1 < HVar1)
         ) {
        if (param_1 == (LPSTREAM)0x0) {
          HVar1 = WriteClassStm(This,(IID *)&DAT_1002006c);
        }
        else {
          HVar1 = OleSaveToStream((LPPERSISTSTREAM)param_1,This);
        }
      }
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&param_1);
      break;
    case 0x10:
    case 0x11:
      HVar1 = (*This->lpVtbl->Write)(This,(void *)((int)this + 8),1,(ULONG *)0x0);
      ExceptionList = local_10;
      return HVar1;
    }
  }
  ExceptionList = local_10;
  return HVar1;
}



// Function: FUN_10006a30 at 10006a30

int __thiscall FUN_10006a30(void *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_2c [8];
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a458;
  local_10 = ExceptionList;
  iVar3 = 0;
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
                    /* WARNING: Load size is inaccurate */
  local_14 = (int *)(uint)*this;
  iVar2 = 2;
  local_18 = 0;
  ExceptionList = &local_10;
  switch(local_14) {
  case (int *)0x2:
  case (int *)0xb:
  case (int *)0x12:
    iVar2 = 4;
    break;
  case (int *)0x3:
  case (int *)0x4:
  case (int *)0xa:
  case (int *)0x13:
  case (int *)0x16:
  case (int *)0x17:
    iVar2 = 6;
    break;
  case (int *)0x5:
  case (int *)0x6:
  case (int *)0x7:
  case (int *)0x14:
  case (int *)0x15:
    iVar2 = 10;
    break;
  default:
    Ordinal_8(local_2c);
    local_8 = 2;
    if ((short)local_14 == 8) {
      local_24 = *(uint *)((int)this + 8);
LAB_10006ba6:
      uVar1 = 4;
      if (local_24 != 0) {
        iVar2 = Ordinal_149(local_24);
        uVar1 = iVar2 + 6;
      }
      iVar2 = uVar1 + 2;
      local_18 = (uint)(0xfffffffd < uVar1);
    }
    else {
      iVar3 = Ordinal_12(local_2c,this,1,8);
      if (-1 < iVar3) goto LAB_10006ba6;
    }
    local_8 = 0xffffffff;
    Ordinal_9(local_2c);
    goto LAB_10006bd6;
  case (int *)0x9:
  case (int *)0xd:
    iVar2 = 0x12;
    local_1c = 0x12;
    if (*(int *)((int)this + 8) == 0) break;
    local_14 = (int *)0x0;
    local_8 = 1;
    iVar3 = (**(code **)**(undefined4 **)((int)this + 8))
                      (*(undefined4 **)((int)this + 8),&DAT_1001f4ac,&local_14,
                       DAT_10029f90 ^ (uint)&stack0xfffffffc);
    if ((iVar3 < 0) &&
       (iVar3 = (**(code **)**(undefined4 **)((int)this + 8))
                          (*(undefined4 **)((int)this + 8),&DAT_1001ed80,&local_14), iVar3 < 0)) {
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&local_14);
    }
    else {
      local_24 = 0;
      local_20 = 0;
      iVar3 = (**(code **)(*local_14 + 0x1c))(local_14,&local_24);
      if (-1 < iVar3) {
        iVar3 = FUN_100045b0(&local_1c,0x12,local_18,local_24,local_20);
        iVar2 = local_1c;
      }
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&local_14);
    }
LAB_10006bd6:
    if (iVar3 < 0) {
      ExceptionList = local_10;
      return iVar3;
    }
    break;
  case (int *)0x10:
  case (int *)0x11:
    iVar2 = 3;
  }
  *param_1 = iVar2;
  param_1[1] = local_18;
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10006c30 at 10006c30

void __cdecl
FUN_10006c30(LPSTREAM param_1,IID *param_2,undefined4 *param_3,undefined *param_4,uint param_5)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  HRESULT HVar4;
  undefined3 extraout_var;
  int iVar5;
  int *local_30;
  undefined4 local_2c;
  int *local_28;
  CLSID local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a4c0;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_14 = uVar3;
  HVar4 = ReadClassStm(param_1,&local_24);
  if (-1 < HVar4) {
    local_28 = (int *)0x0;
    local_8 = 1;
    if (param_5 == 0) {
      if (param_4 != (undefined *)0x0) {
        HVar4 = (*(code *)param_4)(&local_24,param_2,&local_28,uVar3);
      }
      if (-1 < HVar4) {
LAB_10006cec:
        if ((local_28 != (int *)0x0) ||
           (HVar4 = CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x415,param_2,&local_28), -1 < HVar4))
        {
          local_30 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,5);
          iVar5 = (**(code **)*local_28)(local_28,&DAT_1001f4ac,&local_30);
          if ((-1 < iVar5) &&
             (iVar5 = (**(code **)(*local_30 + 0x14))(local_30,param_1), piVar1 = local_28,
             -1 < iVar5)) {
            local_28 = (int *)0x0;
            *param_3 = piVar1;
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (local_30 != (int *)0x0) {
            (**(code **)(*local_30 + 8))(local_30);
          }
        }
      }
    }
    else {
      uVar3 = 0;
      local_2c = 0x80070005;
      if (param_5 != 0) {
        do {
          bVar2 = FUN_10001000((byte *)&local_24,param_4);
          if (CONCAT31(extraout_var,bVar2) != 0) goto LAB_10006cec;
          uVar3 = uVar3 + 1;
          param_4 = param_4 + 0x10;
        } while (uVar3 < param_5);
      }
    }
    local_8 = 0xffffffff;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006db0 at 10006db0

void __fastcall FUN_10006db0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10006dc0 at 10006dc0

void __fastcall FUN_10006dc0(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10006dd0 at 10006dd0

HRESULT __thiscall FUN_10006dd0(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_1002007c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f528,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_10006e30 at 10006e30

undefined4 FUN_10006e30(void)

{
  return 0x80004005;
}



// Function: FUN_10006e40 at 10006e40

void FUN_10006e40(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1001f538);
  return;
}



// Function: FUN_10006e60 at 10006e60

undefined4 * __thiscall FUN_10006e60(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a500;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 4) != 0) {
    if (*(int *)((int)this + 0xc) != 0) {
      FUN_10001fb0((int)this + 4);
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



// Function: FUN_10006f00 at 10006f00

void __fastcall FUN_10006f00(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a528;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10004cb0(param_1);
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



// Function: FUN_10006f80 at 10006f80

void __fastcall FUN_10006f80(undefined4 *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a563;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  piVar1 = param_1 + 1;
  FUN_10004cb0(piVar1);
  local_8 = 1;
  FUN_10004cb0(piVar1);
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



// Function: FUN_10007020 at 10007020

undefined4 FUN_10007020(void)

{
  return 1;
}



// Function: FUN_10007030 at 10007030

undefined4 * __thiscall FUN_10007030(void *this,byte param_1)

{
  FUN_10006f80((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007060 at 10007060

void __thiscall FUN_10007060(void *this,LPCWSTR param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001a588;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
      local_5d = DAT_10029fc4;
      while (WVar1 != L'\0') {
        local_68 = puVar2;
        if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (((local_64 != 0) || (pwVar3 = wcsstr(*this,L"HKCR"), pwVar3 == (wchar_t *)0x0)) ||
             (pwVar3 != *this)) {
LAB_1000718a:
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_55 == '\0') {
                local_55 = '\x01';
                goto LAB_10007209;
              }
              iVar5 = FUN_10001900((undefined4 *)this);
              if (iVar5 == 0) {
                    /* WARNING: Load size is inaccurate */
                pWVar4 = CharNextW(*this);
                *(LPWSTR *)this = pWVar4;
                iVar5 = FUN_10001940(&local_70,pWVar4,1);
                if (iVar5 == 0) goto LAB_100072d6;
                goto LAB_100071cd;
              }
              local_55 = '\0';
            }
            else {
LAB_100071cd:
              if (local_55 != '\0') goto LAB_10007209;
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x7b) {
              local_64 = local_64 + 1;
            }
            if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
               (local_56 == '\x01')) {
              iVar5 = FUN_10004d40(&local_70,L"\r\n\t}\r\n}\r\n");
              if (iVar5 == 0) goto LAB_100072d6;
              local_56 = '\0';
            }
            goto LAB_10007209;
          }
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          iVar5 = FUN_10004d40(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
          if (iVar5 != 0) {
            local_56 = '\x01';
            goto LAB_1000718a;
          }
LAB_100072d6:
          local_5c = 0x8007000e;
          goto LAB_100072c0;
        }
LAB_10007209:
                    /* WARNING: Load size is inaccurate */
        pWVar6 = *this;
        if (*pWVar6 == L'%') {
          pWVar6 = CharNextW(pWVar6);
          *(LPCWSTR *)this = pWVar6;
          if (*pWVar6 == L'%') goto LAB_1000728d;
          pWVar6 = FUN_10001b60(pWVar6,L'%');
          if (pWVar6 == (LPCWSTR)0x0) {
LAB_100072df:
            local_5c = 0x80020009;
            goto LAB_100072c0;
          }
                    /* WARNING: Load size is inaccurate */
          rVar7 = (int)pWVar6 - (int)*this >> 1;
          if (0x1f < (int)rVar7) {
            local_5c = 0x80004005;
            goto LAB_100072c0;
          }
          FUN_100012e0(local_54,0x20,*this,rVar7);
          local_78 = local_54;
          pWVar8 = (LPCWSTR)FUN_100064c0((void *)(*(int *)((int)this + 4) + 4),&local_78);
          if (pWVar8 == (LPCWSTR)0x0) goto LAB_100072df;
          iVar5 = FUN_10004d40(&local_70,pWVar8);
          if (iVar5 == 0) goto LAB_100072d6;
                    /* WARNING: Load size is inaccurate */
          pWVar8 = *this;
          while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
            pWVar8 = CharNextW(*this);
            *(LPCWSTR *)this = pWVar8;
          }
        }
        else {
LAB_1000728d:
          iVar5 = FUN_10001940(&local_70,pWVar6,1);
          if (iVar5 == 0) goto LAB_100072d6;
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
LAB_100072c0:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007320 at 10007320

undefined4 FUN_10007320(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001f30(&DAT_1002a044,(int *)&PTR_DAT_10028000,param_1,(undefined4 *)&DAT_1001e5b8);
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    FUN_10004fd0(0x1002a044);
  }
  return 1;
}



// Function: FUN_10007370 at 10007370

/* WARNING: Removing unreachable block (ram,0x100073cc) */
/* WARNING: Removing unreachable block (ram,0x10007419) */

void FUN_10007370(GUID *param_1,int *param_2,int param_3)

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
  
  puStack_c = &LAB_1001a61e;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
    HVar2 = CoCreateInstance((IID *)&DAT_100200ac,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f624,&local_1a8);
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
            goto LAB_100076e0;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_194,0x40);
        local_1c8 = 0;
        local_8._0_1_ = 6;
        FUN_10001230(local_114,0x80,L"CLSID\\");
        FUN_100013a0(local_114,0x80,local_194);
        FUN_100013a0(local_114,0x80,L"\\Required Categories");
        local_1c4 = 0x80000000;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = (HKEY)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8 = CONCAT31(local_8._1_3_,8);
        local_1ac = 0;
        iVar3 = FUN_10001790(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_100016c0(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_10001640(&local_1c4,local_114);
          }
        }
        FUN_10001230(local_114,0x80,L"CLSID\\");
        FUN_100013a0(local_114,0x80,local_194);
        FUN_100013a0(local_114,0x80,L"\\Implemented Categories");
        iVar3 = FUN_10001790(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_100016c0(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_10001640(&local_1c4,local_114);
          }
        }
        local_8._0_1_ = 7;
        FUN_10004b00(&local_1b8);
        local_8._0_1_ = 6;
        FUN_10004b00(&local_1c4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10004440(&local_1c8);
      }
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
  }
LAB_100076e0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007720 at 10007720

int FUN_10007720(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1001a670;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar2 = FUN_10004de0(param_1,param_2,&local_18,&local_14);
  if (iVar2 < 0) goto LAB_100077dc;
  iVar2 = (**(code **)(*local_14 + 0x1c))(local_14,&param_2,uVar1);
  if (iVar2 < 0) goto LAB_100077dc;
  if (DAT_10029fc4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_100077ae;
    pFVar3 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_100077ae;
  }
  else {
LAB_100077ae:
    pFVar3 = Ordinal_186_exref;
  }
  iVar2 = (*pFVar3)(param_2,(uint)(ushort)param_2[0xc],(uint)(ushort)param_2[0xd],
                    *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 10));
  (**(code **)(*local_14 + 0x30))(local_14,param_2);
LAB_100077dc:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10007820 at 10007820

void FUN_10007820(HMODULE param_1,LPCWSTR param_2)

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
  
  puStack_c = &LAB_1001a6c7;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = 0;
  local_220 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_14 = uVar2;
  iVar3 = FUN_10004de0(param_1,param_2,&local_228,&local_220);
  uVar1 = local_228;
  if (iVar3 < 0) goto LAB_10007952;
  pwVar6 = (wchar_t *)0x0;
  local_224 = (wchar_t *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(*local_220 + 0x24))(local_220,0xffffffff,0,0,0,&local_224,uVar2);
  if ((-1 < iVar3) && (local_224 != (wchar_t *)0x0)) {
    rVar4 = Ordinal_7(local_224);
    FUN_100012e0(local_21c,0x104,local_224,rVar4);
    local_16 = 0;
    iVar3 = FUN_10001ed0(local_21c);
    local_21c[iVar3] = L'\0';
    pwVar6 = local_21c;
  }
  if (DAT_10029fc4 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_1000792f;
    pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar5 == (FARPROC)0x0) goto LAB_1000792f;
  }
  else {
LAB_1000792f:
    pFVar5 = Ordinal_163_exref;
  }
  (*pFVar5)(local_220,uVar1,pwVar6);
  local_8._0_1_ = 2;
  Ordinal_6(local_224);
LAB_10007952:
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



// Function: FUN_100079a0 at 100079a0

int FUN_100079a0(int param_1,int param_2,byte *param_3)

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
        iVar5 = FUN_10007370((GUID *)*puVar1,piVar3,iVar6);
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
    iVar5 = FUN_10007820(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10007a30 at 10007a30

int FUN_10007a30(int param_1,int param_2,byte *param_3)

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
        iVar5 = FUN_10007370((GUID *)*puVar1,piVar3,iVar5);
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
    iVar5 = FUN_10007720(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10007ac0 at 10007ac0

int FUN_10007ac0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  puStack_c = &LAB_1001a720;
  local_10 = ExceptionList;
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  local_14 = (int *)0x0;
  param_1 = (int *)0x0;
  local_8 = 3;
  ExceptionList = &local_10;
  iVar2 = (**(code **)*piVar1)(piVar1,&DAT_1001edb0,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc)
  ;
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14 + 0x10))(local_14,param_3,&param_1);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1,param_2,param_4);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10007ba0 at 10007ba0

int FUN_10007ba0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  puStack_c = &LAB_1001a720;
  local_10 = ExceptionList;
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  local_14 = (int *)0x0;
  param_1 = (int *)0x0;
  local_8 = 3;
  ExceptionList = &local_10;
  iVar2 = (**(code **)*piVar1)(piVar1,&DAT_1001edb0,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc)
  ;
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14 + 0x10))(local_14,param_2,&param_1);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_3);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10007c80 at 10007c80

int FUN_10007c80(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
  puStack_c = &LAB_1001a748;
  local_10 = ExceptionList;
  uVar4 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
      iVar6 = (*(code *)puVar1[2])(puVar1[3],&PTR_1001f43c,piVar2);
    }
    local_8 = 0xffffffff;
    FUN_100066b0(&local_18);
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



// Function: FUN_10007de0 at 10007de0

void FUN_10007de0(int param_1,int *param_2,int param_3)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a748;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) goto LAB_10007e20;
  do {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
LAB_10007e20:
  } while ((param_2 == (int *)0x0) || (param_3 == 0));
  *param_2 = param_3;
  DVar1 = GetCurrentThreadId();
  param_2[1] = DVar1;
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  param_2[2] = *(int *)(param_1 + 0x1c);
  *(int **)(param_1 + 0x1c) = param_2;
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007e90 at 10007e90

undefined4 FUN_10007e90(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a748;
  local_10 = ExceptionList;
  uVar4 = 0;
  if (param_1 == 0) {
    return 0;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  puVar5 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar5 != (undefined4 *)0x0) {
    DVar2 = GetCurrentThreadId();
    puVar3 = (undefined4 *)0x0;
    do {
      if (puVar5[1] == DVar2) {
        if (puVar3 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0x1c) = puVar5[2];
        }
        else {
          puVar3[2] = puVar5[2];
        }
        uVar4 = *puVar5;
        break;
      }
      piVar1 = puVar5 + 2;
      puVar3 = puVar5;
      puVar5 = (undefined4 *)*piVar1;
    } while ((undefined4 *)*piVar1 != (undefined4 *)0x0);
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  ExceptionList = local_10;
  return uVar4;
}



// Function: FUN_10007f50 at 10007f50

undefined4 FUN_10007f50(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a778;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  local_8 = 0xffffffff;
  uVar1 = FUN_10007fce();
  return uVar1;
}



// Function: Catch@10007fbb at 10007fbb

undefined * Catch_10007fbb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007fc8;
}



// Function: FUN_10007fce at 10007fce

undefined4 FUN_10007fce(void)

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



// Function: FUN_10008050 at 10008050

void __fastcall FUN_10008050(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10008080 at 10008080

int * __thiscall FUN_10008080(void *this,uint param_1,uint param_2)

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



// Function: FUN_10008110 at 10008110

void __fastcall FUN_10008110(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7be;
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



// Function: FUN_10008180 at 10008180

undefined4 FUN_10008180(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_100081e0 at 100081e0

undefined4 FUN_100081e0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_10029fc8 + 4))();
    return 0;
  }
  (**(code **)(*DAT_10029fc8 + 8))();
  return 0;
}



// Function: FUN_10008210 at 10008210

undefined4 * __thiscall FUN_10008210(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7fe;
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



// Function: FUN_10008290 at 10008290

undefined * FUN_10008290(void)

{
  return FUN_10005e50;
}



// Function: FUN_100082a0 at 100082a0

void __thiscall FUN_100082a0(void *this,int *param_1,undefined4 param_2)

{
  if (*(int *)((int)this + 0x28) != -0x1010102) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  }
  FUN_10007ac0(param_1,this,param_2,(int)this + 0x28);
  return;
}



// Function: FUN_100082d0 at 100082d0

/* WARNING: Type propagation algorithm not settling */

int FUN_100082d0(int *param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined **ppuVar7;
  bool bVar8;
  undefined1 local_3c [16];
  undefined *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  undefined *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a850;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_1 == (int *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = param_1 + -0x1f;
  }
  if (param_2 == (uint *)0x0) {
    return -0x7fffbffd;
  }
  local_24 = 4;
  local_20 = 0;
  param_1 = (int *)0x0;
  local_8 = 1;
  local_18 = (undefined *)0x0;
  local_1c = 0;
  ppuVar7 = &PTR_DAT_1001ee20;
  piVar5 = local_14;
  ExceptionList = &local_10;
  do {
    uVar6 = 0;
    local_2c = (undefined *)0x0;
    local_28 = 0;
    if (*ppuVar7 != (undefined *)0x0) {
      if (ppuVar7[7] == (undefined *)0x0) {
        Ordinal_8(local_3c,uVar2);
        piVar5 = param_1;
        local_8._0_1_ = 3;
        if (ppuVar7[2] == local_18) {
LAB_1000840f:
          iVar4 = FUN_10004890(&param_1,ppuVar7[5],(int)local_3c);
          if (iVar4 < 0) {
            local_8 = CONCAT31(local_8._1_3_,1);
          }
          else {
            iVar4 = FUN_10006a30(local_3c,(int *)&local_2c);
            if (-1 < iVar4) {
              local_8 = CONCAT31(local_8._1_3_,1);
              Ordinal_9(local_3c);
              puVar3 = local_2c;
              uVar6 = local_28;
              goto LAB_10008453;
            }
            local_8 = CONCAT31(local_8._1_3_,1);
          }
        }
        else {
          if (param_1 != (int *)0x0) {
            param_1 = (int *)0x0;
            (**(code **)(*piVar5 + 8))(piVar5);
          }
          if (ppuVar7[2] == (undefined *)0x0) {
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_9(local_3c);
            goto LAB_100084a7;
          }
          iVar4 = (**(code **)*local_14)(local_14,ppuVar7[2],&param_1);
          if (-1 < iVar4) {
            local_18 = ppuVar7[2];
            goto LAB_1000840f;
          }
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        Ordinal_9(local_3c);
        break;
      }
      puVar3 = ppuVar7[7];
      if (*(short *)(ppuVar7 + 8) == 8) {
        piVar1 = (int *)((int)ppuVar7[6] + (int)piVar5);
        if ((piVar1 < ppuVar7[6]) || (piVar1 < piVar5)) {
LAB_100084a7:
          local_8 = 0xffffffff;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
          ExceptionList = local_10;
          return -0x7fffbffb;
        }
        puVar3 = (undefined *)0x4;
        if (*piVar1 != 0) {
          iVar4 = Ordinal_149(*piVar1);
          puVar3 = (undefined *)(iVar4 + 6);
        }
      }
LAB_10008453:
      if ((-local_20 - 1 < uVar6) ||
         ((-local_20 - 1 <= uVar6 && ((undefined *)(-1 - local_24) < puVar3)))) {
        iVar4 = -0x7ff8fdea;
        break;
      }
      bVar8 = CARRY4(local_24,(uint)puVar3);
      local_24 = local_24 + (int)puVar3;
      local_20 = local_20 + uVar6 + (uint)bVar8;
      piVar5 = local_14;
    }
    iVar4 = 0;
    local_1c = local_1c + 1;
    ppuVar7 = &PTR_DAT_1001ee20 + local_1c * 9;
  } while ((&PTR_DAT_1001ee24)[local_1c * 9] != (undefined *)0x0);
  *param_2 = local_24;
  param_2[1] = local_20;
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar4;
}



// Function: FUN_10008550 at 10008550

void FUN_10008550(int param_1,IAdviseSink *param_2,DWORD *param_3)

{
  IOleAdviseHolder *This;
  int iVar1;
  HRESULT HVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  if ((*(int *)(iVar1 + 0x10) == 0) &&
     (HVar2 = CreateOleAdviseHolder((LPOLEADVISEHOLDER *)(iVar1 + 0x10)), HVar2 < 0)) {
    return;
  }
  This = *(LPOLEADVISEHOLDER *)(iVar1 + 0x10);
  (*This->lpVtbl->Advise)(This,param_2,param_3);
  return;
}



// Function: FUN_10008590 at 10008590

undefined4 FUN_10008590(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x84;
  }
  piVar1 = *(int **)(iVar3 + 0x10);
  uVar2 = 0x80004005;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
  }
  return uVar2;
}



// Function: FUN_100085c0 at 100085c0

undefined4 FUN_100085c0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x84;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0;
  piVar1 = *(int **)(iVar3 + 0x10);
  uVar2 = 0x80004005;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2);
  }
  return uVar2;
}



// Function: FUN_10008610 at 10008610

undefined4 FUN_10008610(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (param_1 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = param_1 + -0x27;
  }
  iVar1 = (**(code **)*piVar3)(piVar3,&DAT_1001ed80,&param_1,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_100023b0((int)piVar3,(int *)&PTR_DAT_1001ebc8,(int *)&DAT_1001ed80,&param_1);
  }
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x10))(param_1);
  }
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100086c0 at 100086c0

undefined4 FUN_100086c0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (param_1 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = param_1 + -0x27;
  }
  iVar1 = (**(code **)*piVar3)(piVar3,&DAT_1001ed80,&param_1,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_100023b0((int)piVar3,(int *)&PTR_DAT_1001ebc8,(int *)&DAT_1001ed80,&param_1);
  }
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x20))(param_1);
  }
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10008770 at 10008770

int FUN_10008770(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  puStack_c = &LAB_1001a8a0;
  local_10 = ExceptionList;
  puVar4 = (undefined4 *)0x0;
  if (param_2 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  local_8 = 1;
  if (param_1 != 0) {
    puVar4 = (undefined4 *)(param_1 + -0x9c);
  }
  ExceptionList = &local_10;
  iVar3 = (**(code **)*puVar4)(puVar4,&DAT_1001ed80,&param_2,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  if (iVar3 < 0) {
    FUN_100023b0((int)puVar4,(int *)&PTR_DAT_1001ebc8,(int *)&DAT_1001ed80,&param_2);
  }
  piVar2 = param_2;
  iVar3 = -0x7fffbffb;
  if (param_2 != (int *)0x0) {
    param_2 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,L"Contents",0,0x10,0,&param_2);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*piVar2 + 0x14))(piVar2,param_2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  local_8 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10008880 at 10008880

int FUN_10008880(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  puStack_c = &LAB_1001a8a0;
  local_10 = ExceptionList;
  puVar4 = (undefined4 *)0x0;
  if (param_2 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  local_8 = 1;
  if (param_1 != 0) {
    puVar4 = (undefined4 *)(param_1 + -0x9c);
  }
  ExceptionList = &local_10;
  iVar3 = (**(code **)*puVar4)(puVar4,&DAT_1001ed80,&param_2,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  if (iVar3 < 0) {
    FUN_100023b0((int)puVar4,(int *)&PTR_DAT_1001ebc8,(int *)&DAT_1001ed80,&param_2);
  }
  piVar2 = param_2;
  iVar3 = -0x7fffbffb;
  if (param_2 != (int *)0x0) {
    param_2 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,PTR_u_Contents_10028e1c,0x1012,0,0,&param_2);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,param_2,param_3);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  local_8 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10008990 at 10008990

void FUN_10008990(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined2 *param_4,
                 int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_58;
  int local_54;
  undefined4 *local_50;
  void *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  undefined2 *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a930;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = param_3;
  local_3c = param_4;
  local_30 = param_5;
  if ((((param_2 != (undefined4 *)0x0) && (param_3 != (undefined4 *)0x0)) &&
      (param_4 != (undefined2 *)0x0)) && (param_5 != (int *)0x0)) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    *param_4 = 0;
    *(undefined2 *)param_5 = 0;
    if (param_1 != (undefined4 *)0x0) {
      local_48 = (int *)0x0;
      local_8 = 1;
      iVar1 = (**(code **)*param_1)(param_1,&DAT_1001ece0,&local_48,local_14);
      if (-1 < iVar1) {
        local_40 = (int *)0x0;
        local_8._0_1_ = 3;
        iVar1 = (**(code **)(*local_48 + 0x10))(local_48,0,0,&local_40);
        if (-1 < iVar1) {
          local_2c = (int *)0x0;
          local_8._0_1_ = 5;
          iVar1 = (**(code **)(*local_40 + 0x48))(local_40,&local_2c,0);
          if ((-1 < iVar1) &&
             (iVar1 = (**(code **)(*local_2c + 0x1c))(local_2c,&local_4c), -1 < iVar1)) {
            FUN_10001170(param_2,0x10,local_4c,0x10);
            *local_3c = *(undefined2 *)((int)local_4c + 0x18);
            *(undefined2 *)local_30 = *(undefined2 *)((int)local_4c + 0x1a);
            (**(code **)(*local_2c + 0x30))(local_2c,local_4c);
            local_44 = (int *)0x0;
            local_8._0_1_ = 7;
            iVar1 = (**(code **)*param_1)(param_1,&DAT_1001ee10,&local_44);
            if ((iVar1 < 0) || (local_44 == (int *)0x0)) {
              local_28 = (int *)0x0;
              local_30 = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,0xb);
              iVar1 = (**(code **)*param_1)(param_1,&DAT_1001ed90,&local_30);
              if (((-1 < iVar1) &&
                  (iVar1 = (**(code **)(*local_30 + 0xc))(local_30,local_24), -1 < iVar1)) &&
                 (iVar1 = (**(code **)(*local_2c + 0x18))(local_2c,local_24,&local_28), -1 < iVar1))
              {
                local_34 = 0;
                (**(code **)(*local_28 + 0xc))(local_28,&local_34);
                if (local_34 != 0) {
                  iVar1 = 0;
                  if (*(short *)(local_34 + 0x30) != 0) {
                    do {
                      iVar2 = (**(code **)(*local_28 + 0x24))(local_28,iVar1,&local_54);
                      if ((-1 < iVar2) && (local_54 == 3)) {
                        iVar1 = (**(code **)(*local_28 + 0x20))(local_28,iVar1,&local_58);
                        if (-1 < iVar1) {
                          local_38 = (int *)0x0;
                          local_8 = CONCAT31(local_8._1_3_,0xd);
                          iVar1 = (**(code **)(*local_28 + 0x38))(local_28,local_58,&local_38);
                          if ((-1 < iVar1) &&
                             ((**(code **)(*local_38 + 0xc))(local_38,&local_3c),
                             local_3c != (undefined2 *)0x0)) {
                            FUN_10001170(local_50,0x10,local_3c,0x10);
                            (**(code **)(*local_38 + 0x4c))(local_38,local_3c);
                          }
                          local_8 = CONCAT31(local_8._1_3_,0xb);
                          FUN_100050c0((int *)&local_38);
                        }
                        break;
                      }
                      iVar1 = iVar1 + 1;
                    } while (iVar1 < (int)(uint)*(ushort *)(local_34 + 0x30));
                  }
                  (**(code **)(*local_28 + 0x4c))(local_28,local_34);
                }
              }
              local_8._0_1_ = 9;
              FUN_100050c0((int *)&local_30);
              local_8._0_1_ = 7;
              FUN_100050c0((int *)&local_28);
            }
            else {
              (**(code **)(*local_44 + 0x10))(local_44,1,local_50);
            }
            local_8._0_1_ = 5;
            FUN_100050c0((int *)&local_44);
          }
          local_8._0_1_ = 3;
          FUN_100050c0((int *)&local_2c);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_100050c0((int *)&local_40);
      }
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&local_48);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008d00 at 10008d00

undefined4 FUN_10008d00(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0xa8;
  }
  piVar1 = *(int **)(iVar2 + 0xc);
  if (piVar1 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2);
    return uVar3;
  }
  return 0x80004005;
}



// Function: FUN_10008d50 at 10008d50

void __fastcall FUN_10008d50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a97e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008db0 at 10008db0

int __thiscall FUN_10008db0(void *this,LPMSG param_1,undefined4 *param_2)

{
  UINT UVar1;
  void *pvVar2;
  SHORT SVar3;
  LPMSG ptVar4;
  BOOL BVar5;
  HWND pHVar6;
  LRESULT LVar7;
  uint uVar8;
  LPACCEL lpAccelDst;
  uint uVar9;
  LPMSG ptVar10;
  int iVar11;
  WORD *pWVar12;
  code *pcVar13;
  tagMSG *lpMsg;
  tagMSG local_30;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  ptVar10 = param_1;
  pvVar2 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a9c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_2 = 0;
  uVar8 = param_1->message;
  if ((uVar8 < 0x100) || (0x109 < uVar8)) {
    if (uVar8 < 0x200) {
      ExceptionList = pvVar2;
      return 0;
    }
    if (0x20e < uVar8) {
      ExceptionList = pvVar2;
      return 0;
    }
  }
  ptVar4 = (LPMSG)GetFocus();
  param_1 = ptVar4;
  BVar5 = IsChild(*(HWND *)((int)this + 0x4c),(HWND)ptVar4);
  if ((BVar5 != 0) && (pHVar6 = GetParent((HWND)ptVar4), pHVar6 != *(HWND *)((int)this + 0x4c))) {
    do {
      param_1 = (LPMSG)GetParent((HWND)ptVar4);
      pHVar6 = GetParent((HWND)param_1);
      ptVar4 = param_1;
    } while (pHVar6 != *(HWND *)((int)this + 0x4c));
  }
  LVar7 = SendMessageW((HWND)ptVar4,0x37f,0,(LPARAM)ptVar10);
  if (LVar7 == 1) {
    ExceptionList = local_10;
    return 1;
  }
  uVar8 = SendMessageW(ptVar10->hwnd,0x87,0,0);
  if (ptVar10->message == 0x100) {
    switch((short)ptVar10->wParam) {
    case 3:
    case 0x1b:
    case 0x2b:
      goto switchD_10008eb7_caseD_3;
    case 9:
      if ((uVar8 & 2) == 0) {
        pHVar6 = GetWindow(*(HWND *)((int)this + 0x4c),5);
        SVar3 = GetKeyState(0x10);
        if (-1 < SVar3) {
          pHVar6 = GetNextDlgTabItem(*(HWND *)((int)this + 0x4c),pHVar6,1);
        }
        uVar8 = (int)pHVar6 - (int)param_1;
        goto LAB_10008e88;
      }
      break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
      if ((uVar8 & 1) == 0) {
        ptVar4 = (LPMSG)GetWindow(*(HWND *)((int)this + 0x4c),5);
        if ((ptVar10->wParam == 0x27) || (ptVar10->wParam == 0x28)) {
          ptVar4 = (LPMSG)GetNextDlgTabItem(*(HWND *)((int)this + 0x4c),(HWND)ptVar4,1);
        }
        if (ptVar4 == param_1) {
          ExceptionList = local_10;
          return 0;
        }
      }
    }
  }
  else if (ptVar10->message == 0x102) {
LAB_10008e88:
    if (uVar8 == 0) {
switchD_10008eb7_caseD_3:
      ExceptionList = local_10;
      return 0;
    }
  }
  UVar1 = ptVar10->message;
  if (((UVar1 == 0x106) || (UVar1 == 0x104)) || (UVar1 == 0x105)) {
    lpMsg = &local_30;
    iVar11 = (**(code **)(*(int *)((int)this + 0x7c) + 0xc))((int)this + 0x7c);
    if (-1 < iVar11) {
      if ((ushort)local_30.wParam == 0) {
        ExceptionList = local_10;
        return 0;
      }
      lpAccelDst = (LPACCEL)FUN_100192db((uint)(ushort)local_30.wParam * 6);
      if (lpAccelDst == (LPACCEL)0x0) {
        *param_2 = 0x8007000e;
        ExceptionList = local_10;
        return 1;
      }
      local_30.time = (DWORD)lpAccelDst;
      local_30.pt.x =
           CopyAcceleratorTableW((HACCEL)local_30.message,lpAccelDst,(uint)(ushort)local_30.wParam);
      param_2 = (undefined4 *)0x0;
      local_14 = (undefined4 *)0x0;
      uVar8 = (ptVar10->message != 0x106) - 1 & 0x10;
      if (local_30.pt.x < 1) {
LAB_10009035:
        operator_delete__((void *)local_30.time);
      }
      else {
        pWVar12 = &lpAccelDst->key;
        do {
          local_30.pt.y = uVar8;
          if ((((tagACCEL *)(pWVar12 + -1))->fVirt & 0xfffffffc) == uVar8) {
            uVar9 = (uint)(ushort)ptVar10->wParam;
            if (((uint)*pWVar12 == uVar9 - 0x20) || ((uint)*pWVar12 == uVar9 + 0x20)) {
              param_2 = (undefined4 *)IsDialogMessageW(*(HWND *)((int)this + 0x4c),ptVar10);
              goto LAB_10009035;
            }
          }
          local_14 = (undefined4 *)((int)local_14 + 1);
          pWVar12 = pWVar12 + 3;
        } while ((int)local_14 < local_30.pt.x);
        operator_delete__((void *)local_30.time);
      }
      goto LAB_1000906f;
    }
    pHVar6 = *(HWND *)((int)this + 0x4c);
  }
  else {
    pHVar6 = *(HWND *)((int)this + 0x4c);
    lpMsg = ptVar10;
  }
  param_2 = (undefined4 *)IsDialogMessageW(pHVar6,lpMsg);
LAB_1000906f:
  if (param_2 != (undefined4 *)0x0) {
    ptVar10 = (LPMSG)GetFocus();
    pcVar13 = IsChild_exref;
    BVar5 = IsChild(*(HWND *)((int)this + 0x4c),(HWND)ptVar10);
    *(uint *)((int)this + 0x74) = -(uint)(BVar5 != 0) & (uint)ptVar10;
    BVar5 = IsChild(*(HWND *)((int)this + 0x4c),(HWND)ptVar10);
    if ((BVar5 != 0) &&
       (pHVar6 = GetParent((HWND)ptVar10), pcVar13 = IsChild_exref,
       pHVar6 != *(HWND *)((int)this + 0x4c))) {
      do {
        ptVar10 = (LPMSG)GetParent((HWND)ptVar10);
        pHVar6 = GetParent((HWND)ptVar10);
        pcVar13 = IsChild_exref;
      } while (pHVar6 != *(HWND *)((int)this + 0x4c));
    }
    iVar11 = (*pcVar13)(*(undefined4 *)((int)this + 0x4c),ptVar10);
    if (((iVar11 != 0) &&
        (iVar11 = (*pcVar13)(*(undefined4 *)((int)this + 0x4c),param_1), iVar11 != 0)) &&
       (param_1 != ptVar10)) {
      local_14 = (undefined4 *)0x0;
      local_8 = 1;
      iVar11 = FUN_10003890((HWND)param_1,(LRESULT *)&local_14);
      if (-1 < iVar11) {
        param_1 = (LPMSG)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar11 = (**(code **)*local_14)(local_14,&DAT_1001ed30,&param_1);
        if (-1 < iVar11) {
          (*(code *)param_1->hwnd[6].unused)(param_1);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_100050c0((int *)&param_1);
      }
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&local_14);
    }
  }
  ExceptionList = local_10;
  return (int)param_2;
}



// Function: FUN_100091a0 at 100091a0

int * FUN_100091a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a9eb;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x198);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10005c00(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10009259();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10009259();
  return piVar1;
}



// Function: Catch@10009244 at 10009244

undefined * Catch_10009244(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009251;
}



// Function: FUN_10009259 at 10009259

int * FUN_10009259(void)

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



// Function: FUN_100092a0 at 100092a0

void __thiscall FUN_100092a0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa10;
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
  FUN_100038d0((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10009360();
  return;
}



// Function: Catch@1000932e at 1000932e

undefined * Catch_1000932e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100038d0((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10009357;
}



// Function: FUN_10009360 at 10009360

void FUN_10009360(void)

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



// Function: Catch@100093c1 at 100093c1

void Catch_100093c1(void)

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



// Function: FUN_100093f0 at 100093f0

undefined4 __thiscall FUN_100093f0(void *this)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_stack_00000010;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0x1;
  iVar2 = FUN_100060e0(this,(uint *)&local_14);
  if ((iVar2 < 0) || (local_14 != (int *)0x0)) {
    local_14 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ed70,&local_14,uVar1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 0x2c))
                (local_14,0xfffffffc,0,*(undefined4 *)((int)this + 0x10),0,
                 **(undefined4 **)((int)this + 0x3c),(int)this + 0x2c);
    }
    local_8 = 0xffffffff;
    if (local_14 == (int *)0x0) {
      *in_stack_00000010 = 0;
    }
    else {
      (**(code **)(*local_14 + 8))(local_14);
      *in_stack_00000010 = 0;
    }
  }
  else {
    *in_stack_00000010 = 0;
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_100094d0 at 100094d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_100094d0(int param_1,char param_2)

{
  int *piVar1;
  uint uVar2;
  HWND hWnd;
  int *piVar3;
  int iVar4;
  void *this;
  int *piVar5;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa9e;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_1002a040 & 1) == 0) {
    DAT_1002a040 = DAT_1002a040 | 1;
    _DAT_1002a030 = 0;
    _DAT_1002a034 = 0;
    _DAT_1002a038 = 0;
  }
  local_8 = 0xffffffff;
  local_18 = (int *)&DAT_1002a020;
  local_14 = 0;
  if (DAT_1002a024 != 0) {
    do {
      this = (void *)(local_18[2] + param_1);
      piVar1 = (int *)((int)this + 0x28);
      if ((*(int *)((int)this + 0x28) == -0x1010102) == (bool)param_2) {
        local_14 = -0x7fffbffb;
        hWnd = GetDlgItem(*(HWND *)(param_1 + 0x50),*local_18);
        if (hWnd == (HWND)0x0) {
          ExceptionList = local_10;
          return -0x7fffbffb;
        }
        local_8 = 2;
        piVar3 = (int *)SendMessageW(hWnd,DAT_10029fe4,0,0);
        if (piVar3 != (int *)0x0) {
          if (param_2 == '\0') {
            piVar5 = (int *)local_18[1];
            if ((((*piVar5 == 0) && (piVar5[1] == 0)) && (piVar5[2] == 0)) && (piVar5[3] == 0)) {
              iVar4 = *piVar1;
              piVar5 = (int *)((int)this + 0x14);
            }
            else {
              iVar4 = *piVar1;
            }
            local_14 = FUN_10007ba0(piVar3,piVar5,iVar4);
            *piVar1 = -0x1010102;
          }
          else {
            piVar5 = (int *)local_18[1];
            if (((*piVar5 == 0) && (piVar5[1] == 0)) && ((piVar5[2] == 0 && (piVar5[3] == 0)))) {
              iVar4 = FUN_10008990(piVar3,(undefined4 *)((int)this + 4),
                                   (undefined4 *)((int)this + 0x14),(undefined2 *)((int)this + 0x24)
                                   ,(int *)((int)this + 0x26));
              if (iVar4 < 0) {
                local_8 = 0xffffffff;
                (**(code **)(*piVar3 + 8))(piVar3,uVar2);
                ExceptionList = local_10;
                return iVar4;
              }
              local_14 = FUN_100082a0(this,piVar3,(undefined4 *)((int)this + 0x14));
            }
            else {
              if (*piVar1 != -0x1010102) {
                    /* WARNING: Subroutine does not return */
                FUN_10001150(0x80004005);
              }
              local_14 = FUN_10007ac0(piVar3,this,piVar5,piVar1);
            }
          }
        }
        local_8 = 0xffffffff;
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        if (local_14 < 0) {
          ExceptionList = local_10;
          return local_14;
        }
      }
      piVar1 = local_18 + 9;
      local_18 = local_18 + 8;
    } while (*piVar1 != 0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100096e0 at 100096e0

int __thiscall FUN_100096e0(void *this,undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aad8;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  piVar2 = (int *)SendMessageW(*this,DAT_10029fe0,0,0);
  iVar3 = (-(uint)(piVar2 != (int *)0x0) & 0x7fffbffb) + 0x80004005;
  if (-1 < iVar3) {
    iVar3 = (**(code **)*piVar2)(piVar2,param_1,param_2,uVar1);
  }
  local_8 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_100097a0 at 100097a0

void __fastcall FUN_100097a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100061c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100097f0 at 100097f0

void __thiscall FUN_100097f0(void *this,int *param_1,size_t *param_2)

{
  size_t _Size;
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001abe8;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = param_1;
  local_14 = uVar2;
  if ((param_1 != (int *)0x0) && (param_2 != (size_t *)0x0)) {
    _Size = *param_2;
    memset(param_2,0,_Size);
    *param_2 = _Size;
    local_30 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ed70,&local_30,uVar2);
    local_2c = (int *)0x0;
    local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ecf0,&local_2c);
    local_3c = (int *)0x0;
    local_8._0_1_ = 5;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001f6d4,&local_3c);
    local_34 = (int *)0x0;
    local_8._0_1_ = 7;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ee10,&local_34);
    if ((local_30 == (int *)0x0) || (local_2c == (int *)0x0)) {
      local_8._0_1_ = 5;
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
      local_8._0_1_ = 3;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      local_8 = 0xffffffff;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
    }
    else {
      (**(code **)(*local_30 + 0xc))(local_30,local_28[1]);
      if (local_28[2] != 0) {
        (**(code **)(*local_2c + 0x1c))(local_2c,1,0,local_28[2]);
      }
      local_38 = (int *)0x0;
      local_8._0_1_ = 0xd;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(*this + 8))(&DAT_1001edb0,&local_38);
      piVar1 = local_28;
      if (local_28[3] != 0) {
        local_28 = (int *)0x0;
        local_8._0_1_ = 0xf;
        if ((local_38 != (int *)0x0) &&
           (iVar3 = (**(code **)(*local_38 + 0x10))(local_38,&DAT_1001f6c4,&local_28), -1 < iVar3))
        {
          (**(code **)(*local_28 + 0x14))(local_28,piVar1[3],param_2 + 4);
        }
        local_8._0_1_ = 0xd;
        FUN_100050c0((int *)&local_28);
      }
      if (((local_34 != (int *)0x0) &&
          (iVar3 = (**(code **)(*local_34 + 0x10))(local_34,1,local_24), -1 < iVar3)) &&
         (piVar1[4] != 0)) {
        local_28 = (int *)0x0;
        local_8._0_1_ = 0x11;
        if ((local_38 != (int *)0x0) &&
           (iVar3 = (**(code **)(*local_38 + 0x10))(local_38,local_24,&local_28), -1 < iVar3)) {
          (**(code **)(*local_28 + 0x14))(local_28,piVar1[4],param_2 + 3);
        }
        local_8._0_1_ = 0xd;
        FUN_100050c0((int *)&local_28);
      }
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 0x58))(local_30,1,param_2 + 1);
      }
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 0x2c))(local_2c,param_2 + 2);
      }
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 0xc))(local_3c,param_2 + 5);
      }
      local_8._0_1_ = 7;
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
      local_8._0_1_ = 5;
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
      local_8._0_1_ = 3;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      local_8 = 0xffffffff;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009ad0 at 10009ad0

void __thiscall FUN_10009ad0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  HWND hWndParent;
  bool bVar4;
  int iVar5;
  HWND hWnd;
  BOOL BVar6;
  undefined4 local_60 [5];
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ac78;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)((int)this + 0x10) == 0) goto LAB_10009e98;
  local_38 = (int *)0x0;
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 8))(&DAT_1001ed30,&local_38,local_14);
  if ((*(uint *)((int)this + 0x44) & 1) == 0) {
    if ((*(uint *)((int)this + 0x44) & 0x40) == 0) {
      (**(code **)**(undefined4 **)((int)this + 0x10))
                (*(undefined4 **)((int)this + 0x10),&DAT_1001f704,(int)this + 4);
    }
    piVar2 = *(int **)((int)this + 4);
    piVar1 = (int *)((int)this + 4);
    if (piVar2 == (int *)0x0) {
      (**(code **)**(undefined4 **)((int)this + 0x10))
                (*(undefined4 **)((int)this + 0x10),&DAT_1001f6f4,piVar1);
      if (*piVar1 == 0) {
        (**(code **)**(undefined4 **)((int)this + 0x10))
                  (*(undefined4 **)((int)this + 0x10),&DAT_1001f6e4,piVar1);
      }
      else {
        *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 0x20;
      }
    }
    else {
      *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 0x20;
      iVar5 = (**(code **)(*piVar2 + 0x48))(piVar2);
      if (iVar5 == 0) {
        *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 0x102;
      }
      else {
        *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) & 0xfffffffd;
      }
    }
  }
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 == (int *)0x0) {
    local_8 = 0xffffffff;
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))(local_38);
    }
    goto LAB_10009e98;
  }
  *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 1;
  uVar3 = *(uint *)((int)this + 0x44);
  if ((uVar3 & 4) == 0) {
    local_48 = 0;
    if ((uVar3 & 2) != 0) {
      (**(code **)(*piVar1 + 0x3c))(piVar1,&local_48,1);
      goto LAB_10009c1e;
    }
    if ((uVar3 & 0x20) != 0) {
      (**(code **)(*piVar1 + 0x3c))(piVar1,&local_48,0);
      goto LAB_10009c1e;
    }
    iVar5 = (**(code **)(*piVar1 + 0x14))(piVar1);
    if (-1 < iVar5) {
      if (iVar5 == 0) {
        (**(code **)(**(int **)((int)this + 4) + 0x18))(*(int **)((int)this + 4));
        goto LAB_10009c1e;
      }
LAB_10009d06:
      local_8 = 0xffffffff;
      FUN_100050c0((int *)&local_38);
      goto LAB_10009e98;
    }
LAB_10009d75:
    local_8 = 0xffffffff;
    FUN_100050c0((int *)&local_38);
  }
  else {
LAB_10009c1e:
    *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 4;
    local_40 = (int *)0x0;
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_3c = (int *)0x0;
    local_8._0_1_ = 6;
    local_60[0] = 0x14;
    iVar5 = (**(code **)(**(int **)((int)this + 4) + 0xc))(*(int **)((int)this + 4),&local_4c);
    if (iVar5 == 0) {
      (**(code **)(**(int **)((int)this + 4) + 0x20))
                (*(int **)((int)this + 4),&local_40,&local_3c,local_24,local_34,local_60);
      if ((*(byte *)((int)this + 0x44) & 2) == 0) {
        if (**(int **)((int)this + 0x3c) == 0) {
                    /* WARNING: Load size is inaccurate */
          iVar5 = (**(code **)(*this + 4))(local_4c,local_24);
          if (iVar5 == 0) {
            local_8._0_1_ = 4;
            FUN_100050c0((int *)&local_3c);
            local_8 = CONCAT31(local_8._1_3_,1);
            FUN_100050c0((int *)&local_40);
            goto LAB_10009d06;
          }
        }
        else {
          ShowWindow((HWND)**(int **)((int)this + 0x3c),5);
        }
      }
      (**(code **)(*local_38 + 0x1c))(local_38,local_24,local_34);
    }
    local_44 = (int *)0x0;
    local_8._0_1_ = 8;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ed50,&local_44);
    bVar4 = false;
    if ((param_1 == -4) || (param_1 == 0)) {
      bVar4 = true;
    }
    switch(param_1) {
    case -5:
    case -4:
    case -1:
    case 0:
      if (*(int *)((int)this + 0x18) != 0) goto switchD_10009cd2_caseD_fffffffd;
LAB_10009d2c:
      if ((*(uint *)((int)this + 0x44) & 8) == 0) {
        *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) | 8;
        iVar5 = (**(code **)(**(int **)((int)this + 4) + 0x1c))(*(int **)((int)this + 4));
        if (iVar5 < 0) {
          *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) & 0xfffffff7;
          local_8._0_1_ = 6;
          FUN_100050c0((int *)&local_44);
          local_8._0_1_ = 4;
          FUN_100050c0((int *)&local_3c);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_100050c0((int *)&local_40);
          goto LAB_10009d75;
        }
        uVar3 = *(uint *)((int)this + 0x44);
        if ((uVar3 & 2) == 0) {
          if ((uVar3 & 4) != 0) {
            hWndParent = (HWND)**(undefined4 **)((int)this + 0x3c);
            if ((uVar3 & 8) == 0) {
              FUN_10009ad0(this,-4);
            }
            else {
              hWnd = GetFocus();
              BVar6 = IsChild(hWndParent,hWnd);
              if (BVar6 == 0) {
                SetFocus(hWndParent);
              }
            }
          }
        }
        else if (((uVar3 & 8) != 0) || (iVar5 = FUN_10009ad0(this,-4), -1 < iVar5)) {
          (**(code **)(**(int **)((int)this + 4) + 0x58))(*(int **)((int)this + 4),1);
        }
        if (local_44 != (int *)0x0) {
          if (local_40 != (int *)0x0) {
            (**(code **)(*local_40 + 0x20))(local_40,local_44,0);
          }
          if (local_3c != (int *)0x0) {
            (**(code **)(*local_3c + 0x20))(local_3c,local_44,0);
          }
        }
        if (local_40 != (int *)0x0) {
          (**(code **)(*local_40 + 0x1c))(local_40,0);
        }
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 0x1c))(local_3c,0);
        }
      }
      break;
    default:
switchD_10009cd2_caseD_fffffffd:
      if (bVar4) goto LAB_10009d2c;
    }
    (**(code **)(**(int **)((int)this + 0x10) + 0x18))(*(int **)((int)this + 0x10));
    local_8._0_1_ = 6;
    if (local_44 != (int *)0x0) {
      (**(code **)(*local_44 + 8))(local_44);
    }
    local_8._0_1_ = 4;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_40 != (int *)0x0) {
      (**(code **)(*local_40 + 8))(local_40);
    }
    local_8 = 0xffffffff;
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))(local_38);
    }
  }
LAB_10009e98:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009ed0 at 10009ed0

undefined4 __thiscall FUN_10009ed0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if (*(int *)((int)this + 8) != 0) {
    local_14 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 8))(&DAT_1001edf0,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    if (-1 < iVar1) {
      uVar2 = (**(code **)(**(int **)((int)this + 8) + 0x18))
                        (*(int **)((int)this + 8),local_14,0,param_1);
    }
    local_8 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10009f60 at 10009f60

int __thiscall FUN_10009f60(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  BOOL BVar3;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001acc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)this;
  if ((**(int **)((int)this + 0x3c) != 0) &&
     (piVar1 = *(int **)((int)this + 0x10), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,0,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  if ((*(byte *)((int)this + 0x44) & 4) != 0) {
    local_14 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ed30,&local_14);
    iVar2 = (**(code **)(*local_14 + 0x14))(local_14);
    if (iVar2 < 0) {
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      ExceptionList = local_10;
      return iVar2;
    }
    local_8 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  if (**(int **)((int)this + 0x3c) != 0) {
    BVar3 = IsWindow((HWND)**(int **)((int)this + 0x3c));
    if (BVar3 != 0) {
      DestroyWindow((HWND)**(undefined4 **)((int)this + 0x3c));
    }
    **(undefined4 **)((int)this + 0x3c) = 0;
  }
  if (((param_1 == 0) || (param_1 == 2)) && ((*(byte *)((int)this + 0x44) & 0x80) != 0)) {
    piVar1 = *(int **)((int)this + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1);
    }
    piVar1 = *(int **)((int)this + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1);
    }
  }
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(uint *)((int)this + 0x44) = *(uint *)((int)this + 0x44) & 0xffffffdc;
  piVar1 = *(int **)((int)this + 0x14);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 0x14) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000a0c0 at 1000a0c0

undefined4 __fastcall FUN_1000a0c0(int *param_1)

{
  int *piVar1;
  BOOL BVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001acf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1[0x11] & 4U) != 0) {
    local_14 = param_1;
    if ((param_1[0x11] & 8U) != 0) {
      local_14 = (int *)0x0;
      local_8 = 1;
      (**(code **)(*param_1 + 8))(&DAT_1001ed30,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
      if (local_14 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x80004005);
      }
      (**(code **)(*local_14 + 0x18))(local_14);
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
    param_1[0x11] = param_1[0x11] & 0xfffffffb;
    if (*(int *)param_1[0xf] != 0) {
      BVar2 = IsWindow(*(HWND *)param_1[0xf]);
      if (BVar2 != 0) {
        DestroyWindow(*(HWND *)param_1[0xf]);
      }
      *(undefined4 *)param_1[0xf] = 0;
    }
    piVar1 = (int *)param_1[1];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x2c))(piVar1);
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000a1a0 at 1000a1a0

void __fastcall FUN_1000a1a0(int param_1)

{
  int *piVar1;
  undefined4 local_54 [5];
  undefined1 local_40 [4];
  int *local_3c;
  int *local_38;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ad50;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(uint *)(param_1 + 0x44) & 8) != 0) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffff7;
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 != (int *)0x0) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0xc))(piVar1,local_40,local_14);
      if (piVar1 == (int *)0x0) {
        local_8 = 3;
        local_54[0] = 0x14;
        local_3c = piVar1;
        local_38 = piVar1;
        (**(code **)(**(int **)(param_1 + 4) + 0x20))
                  (*(int **)(param_1 + 4),&local_38,&local_3c,local_34,local_24,local_54);
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 0x20))(local_3c,0,0);
        }
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 0x20))(local_38,0,0);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 8))(local_3c);
        }
        local_8 = 0xffffffff;
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 8))(local_38);
        }
      }
      (**(code **)(**(int **)(param_1 + 4) + 0x28))(*(int **)(param_1 + 4),0);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a2b0 at 1000a2b0

undefined4 __fastcall FUN_1000a2b0(int param_1)

{
  int *piVar1;
  
  if ((*(uint *)(param_1 + 0x44) & 4) == 0) {
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(piVar1,1,0xffffffff);
    }
  }
  else {
    if (**(int **)(param_1 + 0x3c) != 0) {
      InvalidateRect((HWND)**(int **)(param_1 + 0x3c),(RECT *)0x0,1);
      return 0;
    }
    if (((*(uint *)(param_1 + 0x44) & 2) != 0) &&
       (piVar1 = *(int **)(param_1 + 4), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 100))(piVar1,0,1);
      return 0;
    }
  }
  return 0;
}



// Function: FUN_1000a310 at 1000a310

undefined4 __thiscall FUN_1000a310(void *this,undefined2 *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  void *pvVar3;
  size_t _Count;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ad99;
  local_10 = ExceptionList;
  iVar1 = *(int *)((int)this + 8);
  if (*(int *)((int)this + 4) == iVar1) {
                    /* WARNING: Load size is inaccurate */
    puVar2 = *this;
    if ((puVar2 <= param_1) && (param_1 < puVar2 + iVar1)) {
      ExceptionList = &local_10;
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x80004005);
    }
    if (iVar1 == 0) {
      _Count = 1;
    }
    else {
      _Count = *(int *)((int)this + 4) * 2;
      if ((int)_Count < 0) {
        return 0;
      }
      if (0x3fffffff < _Count) {
        return 0;
      }
    }
    ExceptionList = &local_10;
    pvVar3 = _recalloc(puVar2,_Count,2);
    if (pvVar3 == (void *)0x0) {
      ExceptionList = local_10;
      return 0;
    }
    *(size_t *)((int)this + 8) = _Count;
    *(void **)this = pvVar3;
  }
                    /* WARNING: Load size is inaccurate */
  puVar2 = (undefined2 *)(*this + *(int *)((int)this + 4) * 2);
  if (puVar2 != (undefined2 *)0x0) {
    *puVar2 = *param_1;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000a3f0 at 1000a3f0

undefined4 __thiscall FUN_1000a3f0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001adf3;
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



// Function: FUN_1000a4d0 at 1000a4d0

int __thiscall FUN_1000a4d0(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x401) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10004550(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000a520 at 1000a520

int __thiscall FUN_1000a520(void *this,int param_1)

{
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80070216);
  }
  if ((uint)(param_1 * 2) < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10004550(this,param_1 * 2);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000a570 at 1000a570

/* WARNING: Removing unreachable block (ram,0x1000a582) */

int __thiscall FUN_1000a570(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10004550(this,param_1);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000a5b0 at 1000a5b0

int __thiscall FUN_1000a5b0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = FUN_100066d0(this,(undefined4 *)*param_1);
  if (!bVar3) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    *(undefined4 *)this = 0;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_1001f724,this);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000a610 at 1000a610

int __thiscall FUN_1000a610(void *this,LPSTREAM param_1,undefined4 param_2)

{
  int iVar1;
  HRESULT HVar2;
  undefined1 local_20 [16];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ae18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (((short)param_2 != 0) && ((short)param_2 != *this)) {
    Ordinal_8(local_20,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    iVar1 = Ordinal_12(local_20,this,0,param_2);
    if (iVar1 < 0) {
      local_8 = 0xffffffff;
      Ordinal_9(local_20);
      ExceptionList = local_10;
      return iVar1;
    }
    HVar2 = FUN_100067c0(local_20,param_1);
    local_8 = 0xffffffff;
    Ordinal_9(local_20);
    ExceptionList = local_10;
    return HVar2;
  }
  HVar2 = FUN_100067c0(this,param_1);
  ExceptionList = local_10;
  return HVar2;
}



// Function: FUN_1000a6f0 at 1000a6f0

HRESULT __thiscall
FUN_1000a6f0(void *this,IStream *param_1,DWORD param_2,undefined *param_3,uint param_4)

{
  IStream *This;
  short sVar1;
  int iVar2;
  HRESULT HVar3;
  undefined **ppuVar4;
  ULARGE_INTEGER *plibNewPosition;
  DWORD DVar5;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  This = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ae48;
  local_10 = ExceptionList;
  if (param_1 == (IStream *)0x0) {
    return -0x7ff8ffa9;
  }
  ExceptionList = &local_10;
  plibNewPosition = (ULARGE_INTEGER *)this;
  local_14 = this;
  iVar2 = Ordinal_9(this,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    ExceptionList = local_10;
    return iVar2;
  }
  local_14 = (void *)0x0;
  param_1 = (IStream *)0x0;
  HVar3 = (*This->lpVtbl->Read)(This,&local_14,2,(ULONG *)&param_1);
  if ((HVar3 == 1) || ((param_1 != (IStream *)0x2 && (HVar3 == 0)))) {
    ExceptionList = local_10;
    return -0x7fffbffb;
  }
  if (HVar3 < 0) {
    ExceptionList = local_10;
    return HVar3;
  }
  sVar1 = (short)local_14;
  if (((short)param_2 != 0) && (sVar1 != (short)param_2)) {
    ExceptionList = local_10;
    return -0x7fffbffb;
  }
  *(short *)this = sVar1;
  param_1 = (IStream *)0x0;
  switch((uint)local_14 & 0xffff) {
  case 2:
  case 0xb:
  case 0x12:
    param_1 = (IStream *)0x2;
    break;
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    param_1 = (IStream *)0x4;
    break;
  case 5:
  case 6:
  case 7:
  case 0x14:
  case 0x15:
    param_1 = (IStream *)0x8;
    break;
  default:
    param_2 = 0;
    local_8 = 0;
    iVar2 = FUN_10002230(&param_2,(int *)This);
    if (iVar2 < 0) {
      (*This->lpVtbl->Seek)(This,(LARGE_INTEGER)0x1ffffffff,0,plibNewPosition);
      *(undefined2 *)this = 0;
      DVar5 = param_2;
    }
    else {
      *(undefined2 *)this = 8;
      *(DWORD *)((int)this + 8) = param_2;
      param_2 = 0;
      if ((short)local_14 != 8) {
        iVar2 = Ordinal_12(this,this,0,local_14);
      }
      DVar5 = 0;
    }
    local_8 = 0xffffffff;
    Ordinal_6(DVar5);
    ExceptionList = local_10;
    return iVar2;
  case 9:
  case 0xd:
    *(undefined4 *)((int)this + 8) = 0;
    ppuVar4 = &PTR_1001f43c;
    if (sVar1 != 0xd) {
      ppuVar4 = (undefined **)&DAT_1001ece0;
    }
    iVar2 = FUN_10006c30(This,(IID *)ppuVar4,(undefined4 *)((int)this + 8),param_3,param_4);
    if (iVar2 != -0x7ffbfeac) {
      ExceptionList = local_10;
      return iVar2;
    }
    ExceptionList = local_10;
    return 0;
  case 0x10:
  case 0x11:
    param_1 = (IStream *)0x1;
  }
  HVar3 = (*This->lpVtbl->Read)(This,(void *)((int)this + 8),(ULONG)param_1,(ULONG *)0x0);
  if (HVar3 != 1) {
    ExceptionList = local_10;
    return HVar3;
  }
  ExceptionList = local_10;
  return -0x7fffbffb;
}



// Function: FUN_1000a920 at 1000a920

void __fastcall FUN_1000a920(int param_1)

{
  if (param_1 != 0) {
    FUN_10007f50(param_1 + 4);
    return;
  }
  FUN_10007f50(0);
  return;
}



// Function: FUN_1000a950 at 1000a950

undefined4 FUN_1000a950(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ae80;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_100192db(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    local_8 = 0xffffffff;
    uVar3 = FUN_1000a9e6();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000a9d4 at 1000a9d4

undefined * Catch_1000a9d4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a9e1;
}



// Function: FUN_1000a9e6 at 1000a9e6

void FUN_1000a9e6(void)

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
  uVar4 = FUN_100192db(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_1000aa4a();
  return;
}



// Function: Catch@1000aa34 at 1000aa34

undefined * Catch_1000aa34(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_1000aa41;
}



// Function: FUN_1000aa4a at 1000aa4a

bool FUN_1000aa4a(void)

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
    FUN_10001170(unaff_EDI,*(rsize_t *)(unaff_EBP + -0x28),*(void **)(unaff_EBP + 8),
                 *(rsize_t *)(unaff_EBP + -0x28));
    FUN_10001170(unaff_EBX,unaff_ESI,*(void **)(unaff_EBP + 0xc),unaff_ESI);
    iVar1 = FUN_1000a3f0(*(void **)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x1c));
    if (iVar1 != 0) {
      unaff_EBX = (void *)0x0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      goto LAB_1000aaa3;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
LAB_1000aaa3:
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



// Function: FUN_1000ab00 at 1000ab00

int FUN_1000ab00(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aea8;
  local_10 = ExceptionList;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    local_8 = 0;
    ExceptionList = &local_10;
    iVar1 = FUN_1000a950(param_2,param_3);
    ExceptionList = local_10;
    return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_1000ab90 at 1000ab90

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_1000ab90(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1001aef1;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2120[0] = 0;
  local_18 = uStack_2144;
  iVar1 = FUN_10001c10(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_100019f0(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_1000af17;
  FUN_10001bb0((undefined4 *)this);
  iVar1 = FUN_10001c10(this,local_2018);
  if (iVar1 < 0) goto LAB_1000af17;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 < 0x14) {
    if (uVar2 == 0x13) {
      local_2124 = (void *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      uVar2 = FUN_10001840(param_1,param_2);
      local_8 = 0xffffffff;
      FUN_10004440((int *)&local_2124);
    }
    else {
      if (uVar2 != 8) {
        if (uVar2 == 0x11) {
          local_2128 = lstrlenW(local_2018);
          if ((local_2128 & 1) == 0) {
            local_2120[0] = (int)local_2128 / 2;
            local_2120[1] = 0;
            local_8 = 5;
            FUN_1000a570(local_2120 + 1,local_2120[0]);
            local_8 = 4;
            FUN_1000acdc();
            return;
          }
          goto LAB_1000af17;
        }
        goto LAB_1000aefb;
      }
      uVar2 = FUN_10001860(param_1,param_2,local_2018,1);
    }
    if (uVar2 != 0) {
      FUN_100014c0(uVar2);
      goto LAB_1000af17;
    }
  }
  else if (uVar2 == 0x4008) {
    iVar1 = lstrlenW(local_2018);
    local_2120[1] = 0;
    local_8 = 1;
    FUN_1000a520(local_2120 + 1,iVar1 + 2);
    local_8 = 0;
    FUN_1000ae53();
    return;
  }
LAB_1000aefb:
  FUN_10001c10(this,param_3);
LAB_1000af17:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000acc1 at 1000acc1

undefined * Catch_1000acc1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000acce;
}



// Function: FUN_1000acdc at 1000acdc

void FUN_1000acdc(void)

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
      FUN_10004540((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),(int)unaff_ESI,unaff_EDI);
    if ((int)unaff_ESI < unaff_EBX) {
      do {
        pbVar3 = (byte *)(((uint)unaff_ESI >> 1) + *(int *)(unaff_EBP - 0x2118));
        uVar1 = FUN_10001ae0(*(ushort *)((unaff_EBP - 0x2014) + (int)unaff_ESI * 2));
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
      FUN_10004540((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (pvVar2 == unaff_ESI) {
      FUN_10001c10(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_100014c0((uint)pvVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000af2f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000ae44 at 1000ae44

undefined * Catch_1000ae44(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000ae51;
}



// Function: FUN_1000ae53 at 1000ae53

void FUN_1000ae53(void)

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
    pWVar2 = (WCHAR *)FUN_100018a0(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x212c),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_ESI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10004540((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_ESI) {
    FUN_10001c10(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_100014c0((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000af2f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000af40 at 1000af40

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000af40(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  
  puStack_c = &LAB_1001af57;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2234 = param_2;
  local_222c = (HKEY)0x0;
  local_2228 = 0;
  local_2224 = 0;
  local_8 = 0;
  local_2254 = param_4;
  local_2220 = this;
  iVar4 = FUN_10001c10(this,param_1);
  if (iVar4 < 0) {
    local_8 = 0xffffffff;
  }
  else {
    if (*param_1 != L'}') {
LAB_1000afd0:
      local_2244 = 1;
      iVar4 = lstrcmpiW(param_1,L"Delete");
      local_2230 = (uint)(iVar4 == 0);
      iVar5 = lstrcmpiW(param_1,L"ForceRemove");
      if ((iVar5 != 0) && ((iVar4 == 0) == 0)) {
LAB_1000b162:
        iVar4 = lstrcmpiW(param_1,L"NoRemove");
        if (iVar4 == 0) {
          local_2244 = 0;
          iVar4 = FUN_10001c10(local_2220,param_1);
          if (iVar4 < 0) goto LAB_1000b61f;
        }
        iVar4 = lstrcmpiW(param_1,L"Val");
        if (iVar4 == 0) {
          iVar4 = FUN_10001c10(local_2220,local_221c);
          if ((-1 < iVar4) && (iVar4 = FUN_10001c10(local_2220,param_1), -1 < iVar4)) {
            if (*param_1 != L'=') {
LAB_1000b5f8:
              local_8 = 0xffffffff;
              FUN_10004b00(&local_222c);
              goto LAB_1000b645;
            }
            if (param_3 != 0) {
              local_8._0_1_ = 2;
              local_2250 = local_2234;
              local_224c = 0;
              local_2248 = 0;
              iVar4 = FUN_1000ab90(local_2220,&local_2250,local_221c,param_1);
              local_2250 = (HKEY)0x0;
              local_224c = 0;
              local_2248 = 0;
              if (-1 < iVar4) {
                local_8 = (uint)local_8._1_3_ << 8;
                local_224c = 0;
                goto LAB_1000b100;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_10004b00(&local_2250);
              goto LAB_1000b671;
            }
            if ((param_4 == 0) && (local_2244 != 0)) {
              local_226c = (HKEY)0x0;
              local_2268 = 0;
              local_2264 = 0;
              local_8._0_1_ = 3;
              uVar7 = FUN_10001790(&local_226c,local_2234,(LPCWSTR)0x0,0x20006);
              pHVar2 = local_226c;
              if ((uVar7 != 0) ||
                 ((uVar7 = RegDeleteValueW(local_226c,local_221c), uVar7 != 0 && (uVar7 != 2)))) {
                FUN_100014c0(uVar7);
                local_8 = (uint)local_8._1_3_ << 8;
                ppHVar9 = &local_226c;
                goto LAB_1000b61a;
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (pHVar2 != (HKEY)0x0) {
                RegCloseKey(pHVar2);
                local_226c = (HKEY)0x0;
              }
              local_2268 = 0;
            }
            iVar4 = FUN_10001e10(local_2220,param_1);
LAB_1000b140:
            if (-1 < iVar4) goto LAB_1000b14a;
          }
        }
        else {
          WVar1 = *param_1;
          pWVar6 = param_1;
          pHVar2 = local_2234;
          while (local_2234 = pHVar2, WVar1 != L'\0') {
            if (WVar1 == L'\\') {
              if (pWVar6 != (LPCWSTR)0x0) goto LAB_1000b5f8;
              break;
            }
            pWVar6 = CharNextW(pWVar6);
            pHVar2 = local_2234;
            WVar1 = *pWVar6;
          }
          if (param_3 == 0) {
            if (param_4 == 0) {
              local_2230 = FUN_10001790(&local_222c,pHVar2,param_1,0x20019);
              if (local_2230 == 0) goto LAB_1000b3d9;
            }
            else {
              local_2230 = 2;
            }
            param_4 = 1;
LAB_1000b3d9:
            eVar8 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
            switch(eVar8) {
            case 0:
            case 0x50:
              goto switchD_1000b401_caseD_0;
            default:
                    /* WARNING: Subroutine does not return */
              FUN_10001150(0x80004005);
            case 0xc:
                    /* WARNING: Subroutine does not return */
              FUN_10001150(0x8007000e);
            case 0x16:
            case 0x22:
                    /* WARNING: Subroutine does not return */
              FUN_10001150(0x80070057);
            }
          }
          iVar4 = FUN_10001790(&local_222c,pHVar2,param_1,0x2001f);
          if (((iVar4 != 0) &&
              (iVar4 = FUN_10001790(&local_222c,pHVar2,param_1,0x20019), iVar4 != 0)) &&
             (uVar7 = FUN_100016f0(&local_222c,pHVar2,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar7 != 0))
          goto LAB_1000b6a0;
          iVar4 = FUN_10001c10(local_2220,param_1);
          if ((-1 < iVar4) &&
             ((*param_1 != L'=' ||
              (iVar4 = FUN_1000ab90(local_2220,&local_222c,(LPCWSTR)0x0,param_1), -1 < iVar4)))) {
LAB_1000b100:
            if ((*param_1 != L'{') || (iVar4 = lstrlenW(param_1), iVar4 != 1)) goto LAB_1000b14a;
            iVar4 = FUN_1000af40(local_2220,param_1,local_222c,param_3,0);
            if (-1 < iVar4) {
              iVar4 = FUN_10001c10(local_2220,param_1);
              goto LAB_1000b140;
            }
          }
        }
        goto LAB_1000b61f;
      }
      iVar4 = FUN_10001c10(local_2220,param_1);
      if (-1 < iVar4) {
        if (param_3 == 0) goto LAB_1000b162;
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
              FUN_10004b00(&local_2240);
              goto LAB_1000b5f8;
            }
            break;
          }
          pWVar6 = CharNextW(pWVar6);
          WVar1 = *pWVar6;
        }
        ppuVar10 = &PTR_u_AppID_1001e608;
        do {
          iVar4 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar10);
          if (iVar4 == 0) goto LAB_1000b0bf;
          ppuVar10 = ppuVar10 + 1;
        } while ((int)ppuVar10 < 0x1001e638);
        local_2240 = local_2234;
        local_223c = 0;
        local_2238 = 0;
        FUN_10004b20(&local_2240,param_1);
        local_2240 = (HKEY)0x0;
        local_223c = 0;
        local_2238 = 0;
LAB_1000b0bf:
        if (local_2230 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_1000b162;
        }
        iVar4 = FUN_10001c10(local_2220,param_1);
        if ((-1 < iVar4) && (iVar4 = FUN_10001e10(local_2220,param_1), -1 < iVar4)) {
          local_8 = (uint)local_8._1_3_ << 8;
          local_223c = 0;
          goto LAB_1000b100;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_2240;
        goto LAB_1000b61a;
      }
    }
LAB_1000b61f:
    local_8 = 0xffffffff;
    if (local_222c != (HKEY)0x0) {
      RegCloseKey(local_222c);
      local_222c = (HKEY)0x0;
    }
  }
  local_2228 = 0;
LAB_1000b645:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
switchD_1000b401_caseD_0:
  iVar4 = FUN_10001c10(local_2220,param_1);
  if (((iVar4 < 0) || (iVar4 = FUN_10001e10(local_2220,param_1), iVar4 < 0)) ||
     (((*param_1 == L'{' && (iVar4 = lstrlenW(param_1), iVar4 == 1)) &&
      (((iVar4 = FUN_1000af40(local_2220,param_1,local_222c,0,param_4), iVar4 < 0 && (param_4 == 0))
       || (iVar4 = FUN_10001c10(local_2220,param_1), iVar4 < 0)))))) goto LAB_1000b61f;
  param_4 = local_2254;
  if (local_2230 != 2) {
    if (local_2230 == 0) {
      if ((local_2254 == 0) || (bVar3 = FUN_10001dc0(local_222c), CONCAT31(extraout_var,bVar3) == 0)
         ) {
        bVar3 = FUN_10001dc0(local_222c);
        local_2230 = CONCAT31(extraout_var_00,bVar3);
        uVar7 = 0;
        if (local_222c != (HKEY)0x0) {
          uVar7 = RegCloseKey(local_222c);
          local_222c = (HKEY)0x0;
        }
        local_2228 = 0;
        if (uVar7 != 0) {
LAB_1000b6a0:
          FUN_100014c0(uVar7);
LAB_1000b671:
          local_8 = 0xffffffff;
          FUN_10004b00(&local_222c);
          goto LAB_1000b645;
        }
        if ((local_2244 != 0) && (local_2230 == 0)) {
          local_8._0_1_ = 4;
          local_2260 = local_2234;
          local_225c = 0;
          local_2258 = 0;
          uVar7 = FUN_10001640(&local_2260,local_21c);
          local_2260 = (HKEY)0x0;
          local_225c = 0;
          local_2258 = 0;
          if (uVar7 != 0) {
            FUN_100014c0(uVar7);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar9 = &local_2260;
LAB_1000b61a:
            FUN_10004b00(ppHVar9);
            goto LAB_1000b61f;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004b00(&local_2260);
        }
      }
      else {
        iVar4 = FUN_10001d80(local_21c);
        if ((iVar4 != 0) && (local_2244 != 0)) {
          FUN_10004b20(&local_222c,local_21c);
        }
      }
    }
    else if (local_2254 == 0) {
      FUN_100014c0(local_2230);
      goto LAB_1000b61f;
    }
  }
LAB_1000b14a:
  if (*param_1 == L'}') goto LAB_1000b61f;
  goto LAB_1000afd0;
}



// Function: FUN_1000b750 at 1000b750

int __thiscall FUN_1000b750(void *this,int *param_1,undefined4 param_2,int *param_3)

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
  puStack_c = &LAB_1001a748;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002a090);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&PTR_1001f43c,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002a090);
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
  iVar4 = FUN_10007c80((int *)&DAT_1002a080,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: FUN_1000b880 at 1000b880

void __thiscall FUN_1000b880(void *this,undefined4 param_1)

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
  puStack_c = &LAB_1001aff9;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000baf3;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10029fc8 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_10029fcc == *piVar1) && (DAT_10029fd0 == piVar1[1])) && (DAT_10029fd4 == piVar1[2]))
        && ((DAT_10029fd8 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_1002a0b0,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_1000bac1;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10004440((int *)&local_220);
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
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_1001f4bc,&local_220);
        if (-1 < iVar4) {
          FUN_1000a5b0(&local_224,(int *)&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_1000a920(DAT_10029fc8);
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
LAB_1000bac1:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_10005180(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_1000baf3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000bb20 at 1000bb20

undefined4 FUN_1000bb20(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x14);
  if (*(int *)(iVar1 + 0x14) != 0) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 4))(*(int **)(iVar1 + 0x14));
  }
  return 0;
}



// Function: FUN_1000bb60 at 1000bb60

void FUN_1000bb60(int param_1,int param_2)

{
  if (param_1 != 0) {
    FUN_10009f60((void *)(param_1 + -0x80),param_2);
    return;
  }
  FUN_10009f60((void *)0x4,param_2);
  return;
}



// Function: FUN_1000bba0 at 1000bba0

uint FUN_1000bba0(int *param_1,undefined4 *param_2)

{
  SHORT SVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  tagMSG *ptVar6;
  char cVar7;
  tagMSG local_30;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b048;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = param_1 + -0x22;
  }
  puVar5 = param_2;
  ptVar6 = &local_30;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    ptVar6->hwnd = (HWND)*puVar5;
    puVar5 = puVar5 + 1;
    ptVar6 = (tagMSG *)&ptVar6->message;
  }
  local_14 = 0;
  iVar4 = FUN_10008db0(piVar3 + 1,&local_30,&local_14);
  if (iVar4 != 0) {
    ExceptionList = local_10;
    return local_14;
  }
  param_1 = (int *)0x0;
  local_8 = 1;
  puVar5 = (undefined4 *)piVar3[5];
  if (puVar5 == (undefined4 *)0x0) {
    iVar4 = -0x7fffbffb;
    param_1 = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)*puVar5)(puVar5,&DAT_1001f714,&param_1,uVar2);
  }
  if (-1 < iVar4) {
    if (param_1 == (int *)0x0) {
      iVar4 = 1;
    }
    else {
      SVar1 = GetKeyState(0x10);
      cVar7 = SVar1 < 0;
      SVar1 = GetKeyState(0x11);
      if (SVar1 < 0) {
        cVar7 = cVar7 + '\x02';
      }
      SVar1 = GetKeyState(0x12);
      if (SVar1 < 0) {
        cVar7 = cVar7 + '\x04';
      }
      iVar4 = (**(code **)(*param_1 + 0x1c))(param_1,&local_30,cVar7);
    }
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return (uint)(iVar4 != 0);
}



// Function: FUN_1000bcd0 at 1000bcd0

undefined4 FUN_1000bcd0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x8c;
  }
  if (*(int **)(iVar2 + 0x18) != param_4) {
    if (param_4 != (int *)0x0) {
      (**(code **)(*param_4 + 4))(param_4);
    }
    piVar1 = *(int **)(iVar2 + 0x18);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(iVar2 + 0x18) = param_4;
  }
  return 0;
}



// Function: FUN_1000bd20 at 1000bd20

HRESULT FUN_1000bd20(IStream *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  HRESULT HVar3;
  int iVar4;
  ushort local_38 [8];
  uint local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  ULONG local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((((param_1 == (IStream *)0x0) || (param_2 == (int *)0x0)) || (param_3 == 0)) ||
     (param_4 == (undefined4 *)0x0)) {
    HVar3 = -0x7ff8ffa9;
  }
  else {
    local_18 = 0;
    HVar3 = (*param_1->lpVtbl->Read)(param_1,&local_28,4,&local_18);
    if (-1 < HVar3) {
      if ((local_18 != 4) || (0xa00 < local_28)) {
        ExceptionList = local_10;
        return -0x7fffbffb;
      }
      local_14 = (int *)0x0;
      local_8 = 1;
      local_20 = 0;
      local_24 = 0;
      iVar4 = param_2[1];
      local_18 = 4;
      piVar1 = param_2;
      do {
        if (iVar4 == 0) {
LAB_1000bf77:
          local_8 = 0xffffffff;
          if (local_14 != (int *)0x0) {
            (**(code **)(*local_14 + 8))(local_14);
          }
          ExceptionList = local_10;
          return HVar3;
        }
        if (*piVar1 != 0) {
          if (piVar1[7] == 0) {
            Ordinal_8(local_38);
            local_8._0_1_ = 3;
            HVar3 = FUN_1000a6f0(local_38,param_1,(uint)*(ushort *)(piVar1 + 8),
                                 (undefined *)piVar1[3],piVar1[4]);
            if (-1 < HVar3) {
              if (piVar1[2] != local_20) {
                FUN_10004470((int *)&local_14);
                if (piVar1[2] == 0) {
                  local_8 = CONCAT31(local_8._1_3_,1);
                  Ordinal_9(local_38);
                  goto LAB_1000bf2d;
                }
                iVar4 = (**(code **)*param_4)(param_4,piVar1[2],&local_14);
                if (iVar4 < 0) {
                  HVar3 = -0x7fffbffb;
                  goto LAB_1000bf71;
                }
                local_20 = piVar1[2];
              }
              iVar4 = FUN_10002180(local_14,piVar1[5],local_38);
              if (-1 < iVar4) {
                local_8 = CONCAT31(local_8._1_3_,1);
                Ordinal_9(local_38);
                goto LAB_1000bee0;
              }
              HVar3 = -0x7fffbffb;
            }
LAB_1000bf71:
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_9(local_38);
            goto LAB_1000bf77;
          }
          iVar4 = piVar1[6];
          if ((short)piVar1[8] == 8) {
            local_1c = 0;
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 2;
            HVar3 = FUN_10002230(&local_1c,(int *)param_1);
            uVar2 = local_1c;
            local_1c = 0;
            *(undefined4 *)(iVar4 + param_3) = uVar2;
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_6(0);
          }
          else {
            HVar3 = (*param_1->lpVtbl->Read)
                              (param_1,(undefined4 *)(iVar4 + param_3),piVar1[7],&local_18);
            if (HVar3 < 0) goto LAB_1000befa;
            if (local_18 != piVar1[7]) {
LAB_1000bf2d:
              local_8 = 0xffffffff;
              FUN_100050c0((int *)&local_14);
              ExceptionList = local_10;
              return -0x7fffbffb;
            }
          }
          if (HVar3 < 0) {
LAB_1000befa:
            local_8 = 0xffffffff;
            FUN_100050c0((int *)&local_14);
            ExceptionList = local_10;
            return HVar3;
          }
        }
LAB_1000bee0:
        local_24 = local_24 + 1;
        iVar4 = param_2[local_24 * 9 + 1];
        piVar1 = param_2 + local_24 * 9;
      } while( true );
    }
  }
  ExceptionList = local_10;
  return HVar3;
}



// Function: FUN_1000bfc0 at 1000bfc0

HRESULT FUN_1000bfc0(LPSTREAM param_1,undefined4 param_2,int *param_3,int param_4,
                    undefined4 *param_5)

{
  int *piVar1;
  LPSTREAM This;
  HRESULT HVar2;
  int iVar3;
  undefined1 local_30 [16];
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_3;
  This = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b0e8;
  local_10 = ExceptionList;
  if ((((param_1 == (LPSTREAM)0x0) || (param_3 == (int *)0x0)) || (param_4 == 0)) ||
     (param_5 == (undefined4 *)0x0)) {
    return -0x7ff8ffa9;
  }
  local_20 = 0xa00;
  ExceptionList = &local_10;
  HVar2 = (*param_1->lpVtbl->Write)(param_1,&local_20,4,(ULONG *)0x0);
  if (HVar2 < 0) {
    ExceptionList = local_10;
    return HVar2;
  }
  param_1 = (LPSTREAM)0x0;
  local_8 = 1;
  local_18 = 0;
  local_1c = 0;
  iVar3 = piVar1[1];
  do {
    if (iVar3 == 0) {
LAB_1000c1ea:
      local_8 = 0xffffffff;
      if (param_1 != (LPSTREAM)0x0) {
        (*param_1->lpVtbl->Release)(param_1);
      }
      ExceptionList = local_10;
      return HVar2;
    }
    if (*piVar1 != 0) {
      if (piVar1[7] == 0) {
        Ordinal_8(local_30);
        local_8._0_1_ = 3;
        if (piVar1[2] == local_18) {
LAB_1000c131:
          iVar3 = FUN_10004890(&param_1,piVar1[5],(int)local_30);
          if (iVar3 < 0) {
            HVar2 = -0x7fffbffb;
            local_8 = CONCAT31(local_8._1_3_,1);
          }
          else {
            HVar2 = FUN_1000a610(local_30,This,(uint)*(ushort *)(piVar1 + 8));
            if (-1 < HVar2) {
              local_8 = CONCAT31(local_8._1_3_,1);
              Ordinal_9(local_30);
              goto LAB_1000c16b;
            }
            local_8 = CONCAT31(local_8._1_3_,1);
          }
        }
        else {
          FUN_10004470((int *)&param_1);
          if (piVar1[2] == 0) {
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_9(local_30);
            local_8 = 0xffffffff;
            FUN_100050c0((int *)&param_1);
            ExceptionList = local_10;
            return -0x7fffbffb;
          }
          iVar3 = (**(code **)*param_5)(param_5,piVar1[2],&param_1);
          if (-1 < iVar3) {
            local_18 = piVar1[2];
            goto LAB_1000c131;
          }
          HVar2 = -0x7fffbffb;
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        Ordinal_9(local_30);
        goto LAB_1000c1ea;
      }
      if ((short)piVar1[8] == 8) {
        local_14 = 0;
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 2;
        iVar3 = *(int *)(piVar1[6] + param_4);
        if (iVar3 != 0) {
          Ordinal_6(0);
          local_14 = iVar3;
        }
        HVar2 = FUN_10004930(&local_14,(int *)This);
        local_14 = 0;
        local_8 = CONCAT31(local_8._1_3_,1);
        Ordinal_6(0);
      }
      else {
        HVar2 = (*This->lpVtbl->Write)(This,(int *)(piVar1[6] + param_4),piVar1[7],(ULONG *)0x0);
      }
      if (HVar2 < 0) {
        local_8 = 0xffffffff;
        FUN_100050c0((int *)&param_1);
        ExceptionList = local_10;
        return HVar2;
      }
    }
LAB_1000c16b:
    local_1c = local_1c + 1;
    iVar3 = param_3[local_1c * 9 + 1];
    piVar1 = param_3 + local_1c * 9;
  } while( true );
}



// Function: FUN_1000c230 at 1000c230

void FUN_1000c230(int param_1,int *param_2,size_t *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0xa4;
  }
  *(int *)(iVar1 + 0xe4) = param_2[6];
  *(int *)(iVar1 + 0xc0) = param_2[7];
  FUN_100097f0((void *)(iVar1 + 4),param_2,param_3);
  return;
}



// Function: FUN_1000c270 at 1000c270

void FUN_1000c270(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10005af0(0,param_2,param_3);
    return;
  }
  FUN_100091a0(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000c2a0 at 1000c2a0

void __fastcall FUN_1000c2a0(int param_1)

{
  uint uVar1;
  HWND hWnd;
  HWND pHVar2;
  int *piVar3;
  int iVar4;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b140;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  hWnd = *(HWND *)(param_1 + 0x74);
  if (hWnd != (HWND)0x0) {
    do {
      hWnd = GetParent(hWnd);
      if (hWnd == (HWND)0x0) break;
      pHVar2 = GetParent(hWnd);
    } while (pHVar2 != *(HWND *)(param_1 + 0x4c));
    if (hWnd != *(HWND *)(param_1 + 0x74)) {
      local_8 = 1;
      piVar3 = (int *)SendMessageW(hWnd,DAT_10029fe4,0,0);
      if (-1 < (int)((-(uint)(piVar3 != (int *)0x0) & 0x7fffbffb) + 0x80004005)) {
        local_14 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar4 = (**(code **)*piVar3)(piVar3,&DAT_1001ed30,&local_14,uVar1);
        if (-1 < iVar4) {
          (**(code **)(*local_14 + 0x18))(local_14);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_14 != (int *)0x0) {
          (**(code **)(*local_14 + 8))(local_14);
        }
      }
      local_8 = 0xffffffff;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
      }
    }
  }
  *(undefined4 *)(param_1 + 0x74) = 0;
  FUN_1000a1a0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c3a0 at 1000c3a0

void __fastcall FUN_1000c3a0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b291;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xc;
  Ordinal_6(*(undefined4 *)(param_1 + 0xe8),DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 0xb;
  piVar1 = *(int **)(param_1 + 0xdc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 10;
  piVar1 = *(int **)(param_1 + 0xd8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 9;
  piVar1 = *(int **)(param_1 + 0x7c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 8;
  piVar1 = *(int **)(param_1 + 0x78);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 7;
  piVar1 = *(int **)(param_1 + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 6;
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 5;
  piVar1 = *(int **)(param_1 + 0x6c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 4;
  piVar1 = *(int **)(param_1 + 0x68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 3;
  piVar1 = *(int **)(param_1 + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 2;
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c570 at 1000c570

void __fastcall FUN_1000c570(void *param_1)

{
  int *piVar1;
  HWND hWnd;
  HWND hWnd_00;
  HWND pHVar2;
  int iVar3;
  BOOL BVar4;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b2d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  hWnd = GetFocus();
  hWnd_00 = *(HWND *)((int)param_1 + 0x74);
  if (((hWnd_00 != (HWND)0x0) && (hWnd_00 != *(HWND *)((int)param_1 + 0x4c))) && (hWnd != hWnd_00))
  {
    do {
      hWnd_00 = GetParent(hWnd_00);
      if (hWnd_00 == (HWND)0x0) break;
      pHVar2 = GetParent(hWnd_00);
    } while (pHVar2 != *(HWND *)((int)param_1 + 0x4c));
    if (hWnd_00 != *(HWND *)((int)param_1 + 0x74)) {
      local_18 = (int *)0x0;
      local_8 = 1;
      iVar3 = FUN_10003890(hWnd_00,(LRESULT *)&local_18);
      piVar1 = local_18;
      if (-1 < iVar3) {
        local_14 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar3 = (**(code **)*local_18)(local_18,&DAT_1001ed30,&local_14);
        if (-1 < iVar3) {
          (**(code **)(*local_14 + 0x18))(local_14);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_100050c0((int *)&local_14);
      }
      local_8 = 0xffffffff;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
  }
  BVar4 = IsChild(*(HWND *)((int)param_1 + 0x4c),hWnd);
  *(uint *)((int)param_1 + 0x74) = -(uint)(BVar4 != 0) & (uint)hWnd;
  FUN_100093f0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c690 at 1000c690

int __fastcall FUN_1000c690(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  iVar1 = FUN_10009ad0((void *)(iVar1 + 4),-1);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_1000c6c0 at 1000c6c0

int __fastcall FUN_1000c6c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x84;
  }
  iVar2 = FUN_10009ad0((void *)(iVar1 + 4),-5);
  if (-1 < iVar2) {
    FUN_1000a2b0(iVar1 + 4);
    iVar2 = 0;
  }
  return iVar2;
}



// Function: FUN_1000c700 at 1000c700

int __fastcall FUN_1000c700(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x84;
  }
  iVar1 = 0;
  if ((*(byte *)(iVar2 + 0x48) & 8) == 0) {
    iVar1 = FUN_10009ad0((void *)(iVar2 + 4),-4);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// Function: FUN_1000c740 at 1000c740

void __fastcall FUN_1000c740(undefined4 *param_1)

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



// Function: FUN_1000c7d0 at 1000c7d0

LONG FUN_1000c7d0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10029fc8 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000c800 at 1000c800

LONG FUN_1000c800(int *param_1)

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
    (**(code **)(*DAT_10029fc8 + 8))();
  }
  return LVar1;
}



// Function: FUN_1000c850 at 1000c850

void FUN_1000c850(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1,(int *)&PTR_DAT_1001f750,param_2,param_3);
  return;
}



// Function: FUN_1000c870 at 1000c870

undefined4 * __thiscall FUN_1000c870(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b376;
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



// Function: FUN_1000c900 at 1000c900

void FUN_1000c900(ushort param_1)

{
  ushort uVar1;
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;
  LRESULT LVar3;
  ushort *puVar4;
  undefined4 local_24c;
  undefined4 local_248;
  undefined1 *local_244;
  int local_228;
  int local_224;
  ushort *local_220;
  undefined1 *local_21c;
  undefined1 local_218 [256];
  undefined1 *local_118;
  undefined1 local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  hModule = DAT_1002a0b4;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b3b6;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_220 = (ushort *)0x1;
  hResInfo = FindResourceW(DAT_1002a0b4,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  if ((hResInfo != (HRSRC)0x0) &&
     (hResData = LoadResource(hModule,hResInfo), hResData != (HGLOBAL)0x0)) {
    puVar2 = (ushort *)LockResource(hResData);
    puVar4 = puVar2;
    while ((puVar4 != (ushort *)0x0 && (uVar1 = *puVar2, uVar1 != 0))) {
      local_228 = *(int *)(puVar2 + 2);
      puVar4 = puVar2 + 4;
      if (puVar2[1] == 0x403) {
        local_21c = local_218;
        FUN_10005da0(&local_21c,(LPCSTR)puVar4,3);
        local_8 = 0;
        LVar3 = SendDlgItemMessageW(*(HWND *)(local_224 + 4),(uint)uVar1,0x143,0,(LPARAM)local_21c);
        if (LVar3 == -1) {
          local_220 = (ushort *)0x0;
        }
        local_8 = 0xffffffff;
        if (local_21c != local_218) {
          free(local_21c);
        }
      }
      else if (puVar2[1] == 0x1234) {
        local_118 = local_114;
        local_24c = 1;
        local_248 = 0xffffffff;
        FUN_10005da0(&local_118,(LPCSTR)puVar4,3);
        local_244 = local_118;
        local_8 = 0xffffffff;
        if (local_118 != local_114) {
          free(local_118);
        }
        LVar3 = SendDlgItemMessageW(*(HWND *)(local_224 + 4),(uint)uVar1,0x40b,0,(LPARAM)&local_24c)
        ;
        if (LVar3 == -1) {
          local_220 = (ushort *)0x0;
        }
      }
      puVar2 = (ushort *)((int)puVar4 + local_228);
      puVar4 = local_220;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cb10 at 1000cb10

void FUN_1000cb10(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  HANDLE hProcess;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  piVar2 = (int *)FUN_10007e90(0x1002a0e4);
  if (piVar2 == (int *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*piVar2 + 8);
  piVar2[1] = (int)param_1;
  iVar3 = (*pcVar1)();
  if (piVar2[5] == 0) {
    pvVar4 = __AllocStdCallThunk_cmn();
    piVar2[5] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_1000cb76;
  }
  lpBaseAddress = (undefined4 *)piVar2[5];
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = piVar2;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = (iVar3 - (int)lpBaseAddress) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
LAB_1000cb76:
  pcVar1 = (code *)piVar2[5];
  SetWindowLongW(param_1,4,(LONG)pcVar1);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000cba0 at 1000cba0

/* WARNING: Removing unreachable block (ram,0x1000cc26) */

undefined4 __cdecl FUN_1000cba0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_24 [2];
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  if (param_1 != (int *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_1001edb0,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  if (local_14 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8 = 6;
    (**(code **)(*local_14 + 0x10))(local_14,&DAT_1001f6c4,&local_18);
    if (local_18 != (int *)0x0) {
      local_1c = (int *)0x0;
      local_8._0_1_ = 0xb;
      iVar1 = (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
      if (iVar1 < 0) {
        local_8._0_1_ = 6;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      else {
        iVar1 = (**(code **)(*local_1c + 0xc))(local_1c,1,local_24,0);
        while (iVar1 == 0) {
          if (local_24[0] != (int *)0x0) {
            iVar1 = 0;
            param_1 = (int *)0x0;
            local_8._0_1_ = 0x11;
            if (local_24[0] != (int *)0x0) {
              (**(code **)*local_24[0])(local_24[0],&DAT_1001f6c4,&param_1);
            }
            local_8._0_1_ = 0x12;
            if (param_1 != (int *)0x0) {
              iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2);
            }
            (**(code **)(*local_24[0] + 8))(local_24[0]);
            if (iVar1 == 1) {
              local_8._0_1_ = 0xb;
              if (param_1 != (int *)0x0) {
                (**(code **)(*param_1 + 8))(param_1);
              }
              local_8._0_1_ = 6;
              if (local_1c != (int *)0x0) {
                (**(code **)(*local_1c + 8))(local_1c);
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
              }
              local_8 = 0xffffffff;
              if (local_14 != (int *)0x0) {
                (**(code **)(*local_14 + 8))(local_14);
              }
              ExceptionList = local_10;
              return 1;
            }
            local_8._0_1_ = 0xb;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 8))(param_1);
            }
          }
          iVar1 = (**(code **)(*local_1c + 0xc))(local_1c,1,local_24,0);
        }
        local_8._0_1_ = 6;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000cdc0 at 1000cdc0

/* WARNING: Removing unreachable block (ram,0x1000ce46) */

undefined4 __cdecl FUN_1000cdc0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *local_24 [2];
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b5c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  if (param_1 != (int *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_1001edb0,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  if (local_14 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8 = 6;
    (**(code **)(*local_14 + 0x10))(local_14,&DAT_1001f6c4,&local_18);
    if (local_18 != (int *)0x0) {
      local_1c = (int *)0x0;
      local_8._0_1_ = 0xb;
      iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
      if (iVar2 < 0) {
        local_8._0_1_ = 6;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      else {
        iVar2 = (**(code **)(*local_1c + 0xc))(local_1c,1,local_24,0);
        uVar1 = param_2;
        while (iVar2 == 0) {
          if (local_24[0] != (int *)0x0) {
            param_1 = (int *)0x0;
            local_8._0_1_ = 0x11;
            (**(code **)*local_24[0])(local_24[0],&DAT_1001f6c4,&param_1);
            local_8._0_1_ = 0x12;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 0xc))(param_1,uVar1);
            }
            (**(code **)(*local_24[0] + 8))(local_24[0]);
            local_8._0_1_ = 0xb;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 8))(param_1);
            }
          }
          iVar2 = (**(code **)(*local_1c + 0xc))(local_1c,1,local_24,0);
        }
        local_8._0_1_ = 6;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000cf70 at 1000cf70

undefined4 __thiscall FUN_1000cf70(void *this)

{
  undefined4 *puVar1;
  undefined4 *in_stack_00000010;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b630;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(byte *)((int)this + 0x44) & 4) == 0) {
    *in_stack_00000010 = 0;
  }
  else {
    local_18 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&DAT_1001ed70,&local_18,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 0x2c))
                (local_18,0xfffffffc,0,*(undefined4 *)((int)this + 0x10),0,
                 **(undefined4 **)((int)this + 0x3c),(int)this + 0x2c);
    }
    puVar1 = *(undefined4 **)((int)this + 0x10);
    local_14 = (int *)0x0;
    local_8._0_1_ = 3;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_1001f714,&local_14);
    }
    local_8._0_1_ = 4;
    if (((*(byte *)((int)this + 0x44) & 4) != 0) && (local_14 != (int *)0x0)) {
      (**(code **)(*local_14 + 0x20))(local_14,1);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    local_8 = 0xffffffff;
    if (local_18 == (int *)0x0) {
      *in_stack_00000010 = 0;
    }
    else {
      (**(code **)(*local_18 + 8))(local_18);
      *in_stack_00000010 = 0;
    }
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000d090 at 1000d090

undefined4 __thiscall FUN_1000d090(void *this)

{
  undefined4 *puVar1;
  HWND hWnd;
  BOOL BVar2;
  undefined4 *in_stack_00000010;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 0x10);
  local_14 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001f714,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 2;
  if (((*(byte *)((int)this + 0x44) & 4) != 0) && (local_14 != (int *)0x0)) {
    hWnd = GetFocus();
    BVar2 = IsChild((HWND)**(undefined4 **)((int)this + 0x3c),hWnd);
    if (BVar2 == 0) {
      (**(code **)(*local_14 + 0x20))(local_14,0);
    }
  }
  *in_stack_00000010 = 0;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000d150 at 1000d150

undefined4 __thiscall FUN_1000d150(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b650;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 == 3) {
    local_8 = 0;
    lVar2 = (ulonglong)(uint)(param_2 - param_1 >> 3) * 8;
    uVar3 = FUN_100192db(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)((int)this + 8) = uVar3;
    local_8 = 0xffffffff;
    uVar3 = FUN_1000d1d4();
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



// Function: Catch@1000d1c1 at 1000d1c1

undefined * Catch_1000d1c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d1ce;
}



// Function: FUN_1000d1d4 at 1000d1d4

undefined4 FUN_1000d1d4(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar3;
  
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 8);
  if (*(int *)(unaff_ESI + 8) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  piVar3 = *(int **)(unaff_EBP + 8);
  if (piVar3 != unaff_EBX) {
    do {
      piVar1 = *(int **)(unaff_ESI + 0x10);
      if ((piVar1 == (int *)0x0) || (piVar3 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x80004005);
      }
      piVar2 = (int *)*piVar3;
      *piVar1 = (int)piVar2;
      piVar1[1] = piVar3[1];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 8;
      piVar3 = piVar3 + 2;
    } while (piVar3 != unaff_EBX);
    piVar3 = *(int **)(unaff_EBP + 8);
  }
  *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 8) + ((int)unaff_EBX - (int)piVar3 >> 3) * 8;
  piVar3 = *(int **)(unaff_EBP + 0x10);
  if (*(int **)(unaff_ESI + 4) != piVar3) {
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    piVar1 = *(int **)(unaff_ESI + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(unaff_ESI + 4) = piVar3;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_1000d2a0 at 1000d2a0

int __thiscall FUN_1000d2a0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_30;
  LPVOID local_2c;
  undefined4 local_28;
  LPVOID local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b730;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_14 = (int *)0x0;
  puVar1 = *(undefined4 **)((int)this + 0x10);
  local_20 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 7;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001f714,&local_20,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  local_8._0_1_ = 8;
  if ((local_20 == (int *)0x0) || (iVar3 = (**(code **)(*local_20 + 0x24))(local_20), iVar3 < 0)) {
    local_1c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x10);
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 8))(&PTR_1001f43c,&local_1c);
    piVar2 = local_18;
    if (local_18 != local_1c) {
      local_18 = (int *)0x0;
      if (local_1c != (int *)0x0) {
        (**(code **)*local_1c)(local_1c,&DAT_1001edc0,&local_18);
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    if (local_18 == (int *)0x0) {
      iVar3 = 0x40181;
    }
    else {
      iVar3 = (**(code **)(*local_18 + 0xc))(local_18,&local_30);
      piVar2 = local_14;
      if (-1 < iVar3) {
        if (local_14 != local_1c) {
          local_14 = (int *)0x0;
          if (local_1c != (int *)0x0) {
            (**(code **)*local_1c)(local_1c,&DAT_1001ed70,&local_14);
          }
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
        }
        if (local_14 == (int *)0x0) {
          iVar3 = 0x40181;
          CoTaskMemFree(local_2c);
        }
        else {
          local_24 = (LPVOID)0x0;
          (**(code **)(*local_14 + 0x40))(local_14,2,&local_24);
          iVar3 = FUN_10006030(this,&local_28);
          uVar4 = 0x400;
          if (-1 < iVar3) {
            uVar4 = local_28;
          }
          iVar3 = Ordinal_417(param_2,*(undefined4 *)((int)this + 0x30),
                              *(undefined4 *)((int)this + 0x2c),local_24,1,&local_1c,local_30,
                              local_2c,uVar4,0,0);
          CoTaskMemFree(local_24);
          CoTaskMemFree(local_2c);
        }
      }
    }
    local_8._0_1_ = 8;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    local_8._0_1_ = 5;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  else {
    local_8._0_1_ = 5;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_1000d4d0 at 1000d4d0

int __thiscall FUN_1000d4d0(void *this,int param_1,byte *param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int *piVar7;
  uint uVar8;
  
  if (param_1 != 1) {
    return -0x7ffbff95;
  }
  if (param_2 == (byte *)0x0) {
    return -0x7fffbffd;
  }
  uVar3 = 8;
  pbVar5 = (byte *)((int)this + 0x1c);
  pbVar6 = param_2;
  do {
    if (*(int *)pbVar6 != *(int *)pbVar5) {
      iVar4 = (uint)*pbVar6 - (uint)*pbVar5;
      if (((iVar4 == 0) && (iVar4 = (uint)pbVar6[1] - (uint)pbVar5[1], iVar4 == 0)) &&
         (iVar4 = (uint)pbVar6[2] - (uint)pbVar5[2], iVar4 == 0)) {
        iVar4 = (uint)pbVar6[3] - (uint)pbVar5[3];
      }
      uVar3 = iVar4 >> 0x1f | 1;
      goto LAB_1000d526;
    }
    uVar3 = uVar3 - 4;
    pbVar5 = pbVar5 + 4;
    pbVar6 = pbVar6 + 4;
  } while (3 < uVar3);
  uVar3 = 0;
LAB_1000d526:
  if ((*(uint *)((int)this + 0x44) & 0x200) != 0) {
    return (-(uint)(uVar3 == 0) & 0x7fffbffb) + 0x80004005;
  }
  bVar2 = false;
  piVar1 = (int *)((int)this + 0x24);
  uVar8 = 8;
  piVar7 = piVar1;
  do {
    if (*(int *)(((int)param_2 - (int)piVar1) + (int)piVar7) != *piVar7) {
      *piVar1 = *(int *)param_2;
      *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_2 + 4);
      bVar2 = true;
      break;
    }
    uVar8 = uVar8 - 4;
    piVar7 = piVar7 + 1;
  } while (3 < uVar8);
  if (((*(uint *)((int)this + 0x44) & 0x800) != 0) && (uVar3 != 0)) {
    *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)param_2;
    *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_2 + 4);
    bVar2 = true;
  }
  if (((*(uint *)((int)this + 0x44) & 0x400) != 0) && (bVar2)) {
    FUN_10009ed0(this,0);
    FUN_1000a2b0((int)this);
  }
  return 0;
}



// Function: FUN_1000d610 at 1000d610

void __fastcall FUN_1000d610(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b758;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000c3a0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d660 at 1000d660

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000d660(void *this,LPCWSTR param_1,int param_2)

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
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_200c = (WCHAR *)0x0;
  iVar4 = FUN_10007060(this,param_1,&local_200c);
  if (iVar4 < 0) {
LAB_1000d775:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(WCHAR **)this = local_200c;
  WVar1 = *local_200c;
joined_r0x1000d6ae:
  if ((WVar1 == L'\0') || (iVar4 = FUN_10001c10(this,local_2008), iVar4 < 0)) goto LAB_1000d766;
  uVar6 = 0;
  while (iVar4 = lstrcmpiW(local_2008,(LPCWSTR)(&PTR_u_HKCR_1001e6b8)[uVar6 * 2]), iVar4 != 0) {
    uVar6 = uVar6 + 1;
    if (0xd < uVar6) goto LAB_1000d766;
  }
  pHVar2 = (HKEY)(&DAT_1001e6bc)[uVar6 * 2];
  if (((pHVar2 == (HKEY)0x0) || (iVar4 = FUN_10001c10(this,local_2008), iVar4 < 0)) ||
     (local_2008[0] != L'{')) goto LAB_1000d766;
  if (param_2 == 0) {
    iVar4 = FUN_1000af40(this,local_2008,pHVar2,0,0);
    if (iVar4 < 0) goto LAB_1000d766;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *this;
    iVar4 = FUN_1000af40(this,local_2008,pHVar2,param_2,0);
    if (iVar4 < 0) {
      *(undefined4 *)this = uVar3;
      FUN_1000af40(this,local_2008,pHVar2,0,0);
LAB_1000d766:
      CoTaskMemFree(local_200c);
      goto LAB_1000d775;
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
      goto switchD_1000d7b4_caseD_b;
    }
  } while( true );
switchD_1000d7b4_caseD_b:
  WVar1 = *lpsz;
  goto joined_r0x1000d6ae;
}



// Function: DllGetClassObject at 1000d800

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0xd800  2  DllGetClassObject */
  iVar1 = FUN_1000b750(&DAT_1002a044,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_1000d810 at 1000d810

int __thiscall FUN_1000d810(void *this,int param_1,byte *param_2)

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
        iVar5 = FUN_10007370((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_100079a0(0x1002a080,param_1,param_2);
  if ((-1 < iVar5) && (DAT_10029fbc != (code *)0x0)) {
    iVar5 = (*DAT_10029fbc)(DAT_1002a0b0);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_1000d8b0 at 1000d8b0

int __thiscall FUN_1000d8b0(void *this,int param_1,byte *param_2)

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
        iVar5 = FUN_10007370((GUID *)*piVar4,piVar3,iVar5);
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
  if ((DAT_10029fc0 != (code *)0x0) && (iVar5 = (*DAT_10029fc0)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_10007a30(0x1002a080,param_1,param_2);
  return iVar5;
}



// Function: FUN_1000d940 at 1000d940

undefined4 __thiscall
FUN_1000d940(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_1000b880(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_1000da0e;
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
LAB_1000da0e:
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



// Function: FUN_1000da60 at 1000da60

void FUN_1000da60(int param_1,IStream *param_2)

{
  int iVar1;
  HRESULT HVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x7c;
  }
  if (iVar1 == -0x7c) {
    iVar1 = 0;
  }
  HVar2 = FUN_1000bd20(param_2,(int *)&PTR_DAT_1001ee20,iVar1,(undefined4 *)iVar1);
  if (-1 < HVar2) {
    *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) & 0xffffff7f;
  }
  return;
}



// Function: FUN_1000daa0 at 1000daa0

void FUN_1000daa0(int param_1,LPSTREAM param_2,int param_3)

{
  int iVar1;
  HRESULT HVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x7c;
  }
  if (iVar1 == -0x7c) {
    iVar1 = 0;
  }
  HVar2 = FUN_1000bfc0(param_2,param_3,(int *)&PTR_DAT_1001ee20,iVar1,(undefined4 *)iVar1);
  if ((param_3 != 0) && (-1 < HVar2)) {
    *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) & 0xffffff7f;
  }
  return;
}



// Function: FUN_1000daf0 at 1000daf0

undefined4 FUN_1000daf0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x84;
  }
  if (*(int **)(iVar3 + 0x14) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(iVar3 + 0x14);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(iVar3 + 0x14) = param_2;
  }
  piVar1 = *(int **)(iVar3 + 0x1c);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  puVar2 = *(undefined4 **)(iVar3 + 0x14);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,&DAT_1001ece0,(undefined4 *)(iVar3 + 0x1c));
  }
  return 0;
}



// Function: FUN_1000db60 at 1000db60

void FUN_1000db60(int param_1,int param_2,byte *param_3)

{
  if (param_1 != 0) {
    FUN_1000d4d0((void *)(param_1 + -0x80),param_2,param_3);
    return;
  }
  FUN_1000d4d0((void *)0x4,param_2,param_3);
  return;
}



// Function: FUN_1000dba0 at 1000dba0

undefined4 FUN_1000dba0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x88;
  }
  if (param_2 == 0) {
    FUN_1000c2a0(iVar1 + 4);
  }
  return 0;
}



// Function: FUN_1000dbd0 at 1000dbd0

void FUN_1000dbd0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x90;
  }
  if (*(int *)(iVar1 + 0x50) != 0) {
    FUN_100094d0(iVar1,'\0');
  }
  FUN_1000a0c0((int *)(iVar1 + 4));
  return;
}



// Function: FUN_1000dc10 at 1000dc10

void FUN_1000dc10(int param_1)

{
  if (param_1 != 0) {
    FUN_1000c2a0(param_1 + -0x8c);
    return;
  }
  FUN_1000c2a0(4);
  return;
}



// Function: FUN_1000dc40 at 1000dc40

void FUN_1000dc40(int param_1,byte *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0xa4;
  }
  if (iVar1 != -0x84) {
    FUN_1000d4d0((void *)(iVar1 + 4),1,param_2);
    return;
  }
  FUN_1000d4d0((void *)0x4,1,param_2);
  return;
}



// Function: FUN_1000dc90 at 1000dc90

undefined4 FUN_1000dc90(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10028e6c == (int *)0x0) {
    uVar1 = FUN_1000b880(&PTR_DAT_10028e60,0);
  }
  *param_2 = DAT_10028e6c;
  if (DAT_10028e6c != (int *)0x0) {
    (**(code **)(*DAT_10028e6c + 4))(DAT_10028e6c);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000dce0 at 1000dce0

DWORD FUN_1000dce0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b78b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000c740(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_1000dd86();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000dd73 at 1000dd73

undefined * Catch_1000dd73(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000dd80;
}



// Function: FUN_1000dd86 at 1000dd86

DWORD FUN_1000dd86(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_1000dde3;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000ddbb;
  }
  else {
LAB_1000ddbb:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_1000dde3;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_1000dde3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000de00 at 1000de00

int * __thiscall FUN_1000de00(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_10008080(this,uVar2 + param_2,0xffffffff);
    FUN_10008080(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_100092a0(this,uVar2);
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



// Function: FUN_1000df00 at 1000df00

int __fastcall FUN_1000df00(int param_1)

{
  DWORD DVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b8e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(code **)(param_1 + 0x20) = DefWindowProcW_exref;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  local_8 = 0x1e;
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) & 0xffffffc0;
  *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) & 0xfffffffb | 3;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  DVar1 = GetSysColor(8);
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) & 0xffffffbf;
  *(DWORD *)(param_1 + 0xd0) = DVar1;
  *(undefined4 *)(param_1 + 0xd4) = 0x400;
  *(undefined4 *)(param_1 + 0x94) = 0xcdcdcdcd;
  *(undefined4 *)(param_1 + 0xe0) = 4;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) & 0xffffffaf | 0x28;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x5c) = 1;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e0a0 at 1000e0a0

undefined4 __thiscall FUN_1000e0a0(void *this)

{
  SHORT SVar1;
  BOOL BVar2;
  HWND pHVar3;
  undefined4 *in_stack_00000010;
  UINT uCmd;
  
  FUN_1000cf70(this);
  SVar1 = GetKeyState(0x10);
  if ((((SVar1 < 0) && (SVar1 = GetKeyState(9), SVar1 < 0)) ||
      (SVar1 = GetKeyState(0x26), SVar1 < 0)) || (SVar1 = GetKeyState(0x25), SVar1 < 0)) {
    uCmd = 1;
    pHVar3 = GetWindow(*(HWND *)((int)this + 0x4c),5);
    pHVar3 = GetWindow(pHVar3,uCmd);
  }
  else {
    SVar1 = GetKeyState(9);
    if (((SVar1 < 0) || (SVar1 = GetKeyState(0x28), SVar1 < 0)) ||
       (SVar1 = GetKeyState(0x27), SVar1 < 0)) {
      pHVar3 = GetWindow(*(HWND *)((int)this + 0x4c),5);
    }
    else {
      BVar2 = IsWindow(*(HWND *)((int)this + 0x74));
      if ((BVar2 == 0) ||
         (BVar2 = IsChild(*(HWND *)((int)this + 0x4c),*(HWND *)((int)this + 0x74)), BVar2 == 0)) {
        pHVar3 = GetWindow(*(HWND *)((int)this + 0x4c),5);
        *(HWND *)((int)this + 0x74) = pHVar3;
      }
      pHVar3 = *(HWND *)((int)this + 0x74);
    }
  }
  SetFocus(pHVar3);
  *in_stack_00000010 = 1;
  return 0;
}



// Function: FUN_1000e170 at 1000e170

int __thiscall FUN_1000e170(void *this,undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  short local_20 [4];
  short local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a2e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (this == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)this + -0x84;
  }
  Ordinal_8(local_20,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  piVar1 = *(int **)(iVar3 + 0x1c);
  if (piVar1 != (int *)0x0) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,0xfffffd3b,&DAT_1002006c,0x400,2,&local_30,local_20,0,0);
    if (((-1 < iVar2) && (local_20[0] == 0xb)) && (local_18 == 0)) {
      iVar2 = FUN_1000d2a0((void *)(iVar3 + 4),param_1,param_2);
      goto LAB_1000e258;
    }
  }
  if (iVar3 == -0x84) {
    iVar3 = 0;
  }
  iVar2 = FUN_10009ad0((void *)(iVar3 + 4),-5);
  if (-1 < iVar2) {
    iVar2 = 0;
    FUN_1000a2b0(iVar3 + 4);
  }
LAB_1000e258:
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_1000e280 at 1000e280

undefined4 * __fastcall FUN_1000e280(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c023;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e310 at 1000e310

int FUN_1000e310(int *param_1)

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



// Function: FUN_1000e340 at 1000e340

bool FUN_1000e340(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_1000e370 at 1000e370

undefined4 * __thiscall FUN_1000e370(void *this,int *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b908;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000e3d0 at 1000e3d0

void FUN_1000e3d0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1,(int *)&PTR_DAT_1001f7bc,param_2,param_3);
  return;
}



// Function: FUN_1000e3f0 at 1000e3f0

undefined4 * __thiscall FUN_1000e3f0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b940;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100100e0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000e470 at 1000e470

int * __thiscall FUN_1000e470(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_1000de00(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_100092a0(this,param_2);
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



// Function: FUN_1000e570 at 1000e570

undefined4 * __fastcall FUN_1000e570(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b983;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 3;
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnections,&struct___s_GUID_const__GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct_tagCONNECTDATA,class_ATL::_Copy<struct_tagCONNECTDATA>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e600 at 1000e600

undefined4 FUN_1000e600(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_1000e620 at 1000e620

uint FUN_1000e620(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = param_4;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((param_3 != (int *)0x0) && ((param_2 < 2 || (param_4 != (uint *)0x0)))) {
    if ((*(int *)(param_1 + 8) != 0) &&
       ((*(int *)(param_1 + 0xc) != 0 && (*(int *)(param_1 + 0x10) != 0)))) {
      uVar4 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 3;
      param_4 = (uint *)(uint)(uVar4 < param_2);
      if (uVar4 <= param_2) {
        param_2 = uVar4;
      }
      if (puVar3 != (uint *)0x0) {
        *puVar3 = param_2;
      }
      while( true ) {
        if (param_2 == 0) {
          return (uint)param_4;
        }
        piVar1 = *(int **)(param_1 + 0x10);
        param_2 = param_2 - 1;
        if ((param_3 == (int *)0x0) || (piVar1 == (int *)0x0)) break;
        piVar2 = (int *)*piVar1;
        *param_3 = (int)piVar2;
        param_3[1] = piVar1[1];
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 8;
        param_3 = param_3 + 2;
      }
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x80004005);
    }
    return 0x80004005;
  }
  return 0x80004003;
}



// Function: FUN_1000e6f0 at 1000e6f0

bool FUN_1000e6f0(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 3;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 8;
  return param_2 != uVar1;
}



// Function: FUN_1000e720 at 1000e720

void FUN_1000e720(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1,(int *)&PTR_DAT_1001f44c,param_2,param_3);
  return;
}



// Function: FUN_1000e740 at 1000e740

undefined4 * __thiscall FUN_1000e740(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b9b0;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumConnections,&struct___s_GUID_const__GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct_tagCONNECTDATA,class_ATL::_Copy<struct_tagCONNECTDATA>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100061c0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000e7c0 at 1000e7c0

undefined4 FUN_1000e7c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b9d0;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000e280(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_1000e863();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_1000e863();
  return uVar2;
}



// Function: Catch@1000e84d at 1000e84d

undefined * Catch_1000e84d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e85a;
}



// Function: FUN_1000e863 at 1000e863

undefined4 FUN_1000e863(void)

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



// Function: FUN_1000e890 at 1000e890

undefined4 FUN_1000e890(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b9f0;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000e570(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_1000e933();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_1000e933();
  return uVar2;
}



// Function: Catch@1000e91d at 1000e91d

undefined * Catch_1000e91d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e92a;
}



// Function: FUN_1000e933 at 1000e933

undefined4 FUN_1000e933(void)

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



// Function: FUN_1000e960 at 1000e960

undefined4 * __thiscall FUN_1000e960(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c048;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000df00((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x24) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x28) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x2c) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x30) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x34) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x38) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x40) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x44) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x48) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined ***)((int)this + 0x4c) = ATL::CComContainedObject<class_ATL::CAxHostWindow>::vftable;
  *(undefined4 *)((int)this + 0x50) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ea10 at 1000ea10

LPWSTR __cdecl FUN_1000ea10(LPWSTR param_1,LPCWSTR param_2)

{
  LPCWSTR lpsz;
  LPWSTR pWVar1;
  
  if (param_1 != (LPWSTR)0x0) {
    do {
      if (*param_1 == L'\0') {
        return (LPWSTR)0x0;
      }
      lpsz = param_2;
      if (param_2 != (LPCWSTR)0x0) {
        do {
          if (*lpsz == L'\0') break;
          if (*param_1 == *lpsz) {
            pWVar1 = CharNextW(param_1);
            return pWVar1;
          }
          lpsz = CharNextW(lpsz);
        } while (lpsz != (LPWSTR)0x0);
      }
      param_1 = CharNextW(param_1);
    } while (param_1 != (LPWSTR)0x0);
  }
  return (LPWSTR)0x0;
}



// Function: FUN_1000ea60 at 1000ea60

void __fastcall FUN_1000ea60(undefined4 *param_1)

{
  HWND hWnd;
  int iVar1;
  WCHAR local_18 [8];
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  hWnd = GetParent((HWND)*param_1);
  iVar1 = GetClassNameW(hWnd,local_18,8);
  if (iVar1 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  lstrcmpW(local_18,L"#32770");
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000eac0 at 1000eac0

void FUN_1000eac0(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nDenominator;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004003);
  }
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004003);
  }
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0x58);
  nDenominator = GetDeviceCaps(hdc,0x5a);
  ReleaseDC((HWND)0x0,hdc);
  iVar1 = MulDiv(0x9ec,*param_1,iVar1);
  *param_2 = iVar1;
  iVar1 = MulDiv(0x9ec,param_1[1],nDenominator);
  param_2[1] = iVar1;
  return;
}



// Function: FUN_1000eb50 at 1000eb50

void __fastcall FUN_1000eb50(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 8))(piVar1);
  return;
}



// Function: FUN_1000eb70 at 1000eb70

void FUN_1000eb70(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



// Function: FUN_1000eba0 at 1000eba0

undefined4 FUN_1000eba0(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ (param_2 ^ *(uint *)(param_1 + 0x7c)) & 1;
  return 0;
}



// Function: FUN_1000ebc0 at 1000ebc0

undefined4 FUN_1000ebc0(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 1;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 1) != 0);
  return 0;
}



// Function: FUN_1000ebf0 at 1000ebf0

undefined4 FUN_1000ebf0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  return 0;
}



// Function: FUN_1000ec20 at 1000ec20

undefined4 FUN_1000ec20(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x84);
  return 0;
}



// Function: FUN_1000ec50 at 1000ec50

undefined4 FUN_1000ec50(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x88);
  return 0;
}



// Function: FUN_1000ec80 at 1000ec80

undefined4 FUN_1000ec80(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 2;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 2) != 0);
  return 0;
}



// Function: FUN_1000ecb0 at 1000ecb0

undefined4 FUN_1000ecb0(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 4;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 4) != 0);
  return 0;
}



// Function: FUN_1000ece0 at 1000ece0

undefined4 FUN_1000ece0(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 8;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 8) != 0);
  return 0;
}



// Function: FUN_1000ed10 at 1000ed10

void FUN_1000ed10(undefined4 param_1,undefined2 *param_2)

{
  *param_2 = 0;
  return;
}



// Function: FUN_1000ed20 at 1000ed20

undefined4 FUN_1000ed20(undefined4 param_1,undefined2 *param_2)

{
  if (param_2 == (undefined2 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 0;
  return 0;
}



// Function: FUN_1000ed40 at 1000ed40

undefined4 FUN_1000ed40(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x94);
  return 0;
}



// Function: FUN_1000ed70 at 1000ed70

undefined4 FUN_1000ed70(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  return 0;
}



// Function: FUN_1000ed90 at 1000ed90

undefined4 FUN_1000ed90(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x98);
  return 0;
}



// Function: FUN_1000edc0 at 1000edc0

undefined4 FUN_1000edc0(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 5 ^ *(uint *)(param_1 + 0x7c)) & 0x20;
  return 0;
}



// Function: FUN_1000ede0 at 1000ede0

undefined4 FUN_1000ede0(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 0x20;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 0x20) != 0);
  return 0;
}



// Function: FUN_1000ee10 at 1000ee10

undefined4 FUN_1000ee10(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 6 ^ *(uint *)(param_1 + 0x7c)) & 0x40;
  return 0;
}



// Function: FUN_1000ee30 at 1000ee30

undefined4 FUN_1000ee30(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = (byte)*(uint *)(param_1 + 0x7c) & 0x40;
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)((*(uint *)(param_1 + 0x7c) & 0x40) != 0);
  return 0;
}



// Function: FUN_1000ee60 at 1000ee60

undefined4 FUN_1000ee60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = Ordinal_2(*(undefined4 *)(param_1 + 0x9c));
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_1000ee90 at 1000ee90

undefined4 FUN_1000ee90(void)

{
  return 0x80004001;
}



// Function: FUN_1000eea0 at 1000eea0

undefined4 FUN_1000eea0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004005;
  }
  *param_2 = *(undefined4 *)(param_1 + -0x28);
  return 0;
}



// Function: FUN_1000eed0 at 1000eed0

undefined4 FUN_1000eed0(void)

{
  return 0x80004001;
}



// Function: FUN_1000eee0 at 1000eee0

undefined4 FUN_1000eee0(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 2;
  return 0;
}



// Function: FUN_1000eef0 at 1000eef0

undefined4 FUN_1000eef0(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffd;
  return 0;
}



// Function: FUN_1000ef00 at 1000ef00

void FUN_1000ef00(int param_1,int *param_2)

{
  BOOL BVar1;
  HWND hWnd;
  tagPOINT local_18;
  tagPOINT local_10;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_2 != (int *)0x0) {
    local_18.x = *param_2;
    local_18.y = param_2[1];
    local_10.x = param_2[2];
    local_10.y = param_2[3];
    BVar1 = ClientToScreen(*(HWND *)(param_1 + -0x28),&local_18);
    if (BVar1 != 0) {
      ClientToScreen(*(HWND *)(param_1 + -0x28),&local_10);
    }
    hWnd = GetParent(*(HWND *)(param_1 + -0x28));
    if ((hWnd != (HWND)0x0) && (BVar1 = ScreenToClient(hWnd,&local_18), BVar1 != 0)) {
      ScreenToClient(hWnd,&local_10);
    }
    MoveWindow(*(HWND *)(param_1 + -0x28),local_18.x,local_18.y,local_10.x - local_18.x,
               local_10.y - local_18.y,1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000efd0 at 1000efd0

uint FUN_1000efd0(int param_1)

{
  return ~*(uint *)(param_1 + 0x9c) & 1;
}



// Function: FUN_1000eff0 at 1000eff0

uint FUN_1000eff0(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 4) & 1;
}



// Function: FUN_1000f010 at 1000f010

undefined4 FUN_1000f010(int param_1,int param_2)

{
  if (param_2 != 0) {
    SetCapture(*(HWND *)(param_1 + -0x28));
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x10;
    return 0;
  }
  ReleaseCapture();
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xffffffef;
  return 0;
}



// Function: FUN_1000f050 at 1000f050

uint FUN_1000f050(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 5) & 1;
}



// Function: FUN_1000f070 at 1000f070

undefined4 FUN_1000f070(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x6c) =
       *(uint *)(param_1 + 0x6c) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x6c)) & 0x20;
  return 0;
}



// Function: FUN_1000f090 at 1000f090

void FUN_1000f090(int param_1,undefined4 param_2,byte param_3,undefined4 *param_4)

{
  HDC pHVar1;
  HBITMAP h;
  HGDIOBJ ho;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_4 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(char *)(param_1 + 0x30) != '\0') {
    pHVar1 = GetDC(*(HWND *)(param_1 + -0x28));
    *param_4 = pHVar1;
    if (pHVar1 != (HDC)0x0) {
      *(undefined1 *)(param_1 + 0x30) = 0;
      if ((param_3 & 1) == 0) {
        GetClientRect(*(HWND *)(param_1 + -0x28),&local_18);
        if (((param_3 & 4) != 0) && (pHVar1 = CreateCompatibleDC((HDC)*param_4), pHVar1 != (HDC)0x0)
           ) {
          h = CreateCompatibleBitmap
                        ((HDC)*param_4,local_18.right - local_18.left,local_18.bottom - local_18.top
                        );
          if (h == (HBITMAP)0x0) {
            DeleteDC(pHVar1);
          }
          else {
            ho = SelectObject(pHVar1,h);
            if (ho == (HGDIOBJ)0x0) {
              DeleteObject(h);
              DeleteDC(pHVar1);
            }
            else {
              DeleteObject(ho);
              *(undefined4 *)(param_1 + 0x2c) = *param_4;
              *param_4 = pHVar1;
            }
          }
        }
        if ((param_3 & 2) != 0) {
          FillRect((HDC)*param_4,&local_18,(HBRUSH)0x6);
        }
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f1a0 at 1000f1a0

void FUN_1000f1a0(int param_1,HDC param_2)

{
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  *(undefined1 *)(param_1 + 0x30) = 1;
  if (*(int *)(param_1 + 0x2c) != 0) {
    GetClientRect(*(HWND *)(param_1 + -0x28),&local_18);
    BitBlt(*(HDC *)(param_1 + 0x2c),local_18.left,local_18.top,local_18.right - local_18.left,
           local_18.bottom - local_18.top,param_2,0,0,0xcc0020);
    DeleteDC(param_2);
    param_2 = *(HDC *)(param_1 + 0x2c);
  }
  ReleaseDC(*(HWND *)(param_1 + -0x28),param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f230 at 1000f230

undefined4 FUN_1000f230(int param_1,RECT *param_2,BOOL param_3)

{
  InvalidateRect(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_1000f250 at 1000f250

undefined4 FUN_1000f250(int param_1,HRGN param_2,BOOL param_3)

{
  InvalidateRgn(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_1000f270 at 1000f270

undefined4 FUN_1000f270(void)

{
  return 0;
}



// Function: FUN_1000f280 at 1000f280

undefined4 FUN_1000f280(void)

{
  return 0x80004001;
}



// Function: FUN_1000f290 at 1000f290

undefined4 FUN_1000f290(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x68) =
       *(uint *)(param_1 + 0x68) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x68)) & 0x20;
  return 0;
}



// Function: FUN_1000f2b0 at 1000f2b0

void FUN_1000f2b0(void)

{
  return;
}



// Function: FUN_1000f2c0 at 1000f2c0

void FUN_1000f2c0(void)

{
  return;
}



// Function: FUN_1000f2d0 at 1000f2d0

void FUN_1000f2d0(void)

{
  return;
}



// Function: FUN_1000f2e0 at 1000f2e0

undefined4 FUN_1000f2e0(void)

{
  return 0x80004001;
}



// Function: FUN_1000f2f0 at 1000f2f0

undefined4 FUN_1000f2f0(int param_1,int param_2)

{
  *(uint *)(param_1 + 100) =
       *(uint *)(param_1 + 100) ^ (param_2 << 7 ^ *(uint *)(param_1 + 100)) & 0x80;
  return 0;
}



// Function: FUN_1000f310 at 1000f310

undefined4 FUN_1000f310(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x38;
  }
  uVar2 = 0x80004003;
  if (param_3 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)(iVar3 + 0x3c);
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
      return uVar2;
    }
    *param_3 = 0;
    uVar2 = 0x80004005;
  }
  return uVar2;
}



// Function: FUN_1000f360 at 1000f360

undefined4 __thiscall FUN_1000f360(void *this,int *param_1)

{
  int *piVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x80004003;
  }
                    /* WARNING: Load size is inaccurate */
  *param_1 = *this;
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// Function: FUN_1000f390 at 1000f390

void FUN_1000f390(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 4))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000f3b0 at 1000f3b0

void FUN_1000f3b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 8))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000f3d0 at 1000f3d0

void FUN_1000f3d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x2c))(*(undefined4 **)(param_1 + 0x2c),param_2,param_3);
  return;
}



// Function: FUN_1000f3f0 at 1000f3f0

undefined4 __fastcall FUN_1000f3f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



// Function: FUN_1000f400 at 1000f400

LRESULT FUN_1000f400(int *param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  WPARAM WVar1;
  int *piVar2;
  WPARAM wParam;
  LPARAM lParam;
  int iVar3;
  UINT UVar4;
  int local_28;
  UINT local_24;
  WPARAM local_20;
  LPARAM local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  lParam = param_4;
  wParam = param_3;
  piVar2 = param_1;
  WVar1 = param_1[6];
  local_28 = param_1[1];
  local_24 = param_2;
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  param_1 = (int *)0x0;
  piVar2[6] = (int)&local_28;
  local_c = 0x24;
  local_8 = 1;
  local_20 = param_3;
  local_1c = param_4;
  param_3 = WVar1;
  iVar3 = (**(code **)*piVar2)(local_28,param_2,wParam,param_4,&param_1,0);
  if (iVar3 == 0) {
    if (param_2 == 0x82) {
      param_2 = GetWindowLongW((HWND)piVar2[1],-4);
      param_1 = (int *)CallWindowProcW((WNDPROC)piVar2[8],(HWND)piVar2[1],0x82,wParam,lParam);
      if ((code *)piVar2[8] != DefWindowProcW_exref) {
        UVar4 = GetWindowLongW((HWND)piVar2[1],-4);
        if (UVar4 == param_2) {
          SetWindowLongW((HWND)piVar2[1],-4,piVar2[8]);
        }
      }
      piVar2[7] = piVar2[7] | 1;
    }
    else {
      param_1 = (int *)CallWindowProcW((WNDPROC)piVar2[8],(HWND)piVar2[1],param_2,wParam,lParam);
    }
  }
  if (((piVar2[7] & 1U) != 0) && (param_3 == 0)) {
    iVar3 = piVar2[1];
    piVar2[1] = 0;
    piVar2[6] = 0;
    piVar2[7] = piVar2[7] & 0xfffffffe;
    (**(code **)(*piVar2 + 0xc))(iVar3);
    return (LRESULT)param_1;
  }
  piVar2[6] = param_3;
  return (LRESULT)param_1;
}



// Function: FUN_1000f520 at 1000f520

undefined4 __thiscall FUN_1000f520(void *this,HWND param_1)

{
  int iVar1;
  void *pvVar2;
  HANDLE hProcess;
  LONG LVar3;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  if (*(int *)((int)this + 0x14) == 0) {
    pvVar2 = __AllocStdCallThunk_cmn();
    *(void **)((int)this + 0x14) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
  }
  lpBaseAddress = *(undefined4 **)((int)this + 0x14);
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = this;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = (iVar1 - (int)lpBaseAddress) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
  LVar3 = SetWindowLongW(param_1,-4,*(LONG *)((int)this + 0x14));
  if (LVar3 == 0) {
    return 0;
  }
  *(HWND *)((int)this + 4) = param_1;
  *(LONG *)((int)this + 0x20) = LVar3;
  return 1;
}



// Function: FUN_1000f5a0 at 1000f5a0

void FUN_1000f5a0(int param_1)

{
  FUN_1000f3b0(param_1 + -0x24);
  return;
}



// Function: FUN_1000f5b0 at 1000f5b0

void FUN_1000f5b0(int param_1)

{
  FUN_1000f390(param_1 + -0x1c);
  return;
}



// Function: FUN_1000f5c0 at 1000f5c0

void FUN_1000f5c0(int param_1)

{
  FUN_1000f3b0(param_1 + -8);
  return;
}



// Function: FUN_1000f5d0 at 1000f5d0

void FUN_1000f5d0(int param_1)

{
  FUN_1000f3b0(param_1 + -0x28);
  return;
}



// Function: FUN_1000f5e0 at 1000f5e0

void FUN_1000f5e0(int param_1)

{
  FUN_1000f390(param_1 + -0x20);
  return;
}



// Function: FUN_1000f5f0 at 1000f5f0

void FUN_1000f5f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x1c,param_2,param_3);
  return;
}



// Function: FUN_1000f600 at 1000f600

void FUN_1000f600(int param_1)

{
  FUN_1000f3b0(param_1 + -0xc);
  return;
}



// Function: FUN_1000f610 at 1000f610

void FUN_1000f610(int param_1)

{
  FUN_1000f390(param_1 + -4);
  return;
}



// Function: FUN_1000f620 at 1000f620

void FUN_1000f620(int param_1)

{
  FUN_1000f390(param_1 + -0x24);
  return;
}



// Function: FUN_1000f630 at 1000f630

void FUN_1000f630(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x20,param_2,param_3);
  return;
}



// Function: FUN_1000f640 at 1000f640

void FUN_1000f640(int param_1)

{
  FUN_1000f3b0(param_1 + -0x10);
  return;
}



// Function: FUN_1000f650 at 1000f650

void FUN_1000f650(int param_1)

{
  FUN_1000f390(param_1 + -8);
  return;
}



// Function: FUN_1000f660 at 1000f660

void FUN_1000f660(int param_1)

{
  FUN_1000f390(param_1 + -0x28);
  return;
}



// Function: FUN_1000f670 at 1000f670

void FUN_1000f670(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000f680 at 1000f680

void FUN_1000f680(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x24,param_2,param_3);
  return;
}



// Function: FUN_1000f690 at 1000f690

void FUN_1000f690(int param_1)

{
  FUN_1000f3b0(param_1 + -0x14);
  return;
}



// Function: FUN_1000f6a0 at 1000f6a0

void FUN_1000f6a0(int param_1)

{
  FUN_1000f390(param_1 + -0xc);
  return;
}



// Function: FUN_1000f6b0 at 1000f6b0

void FUN_1000f6b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000f6c0 at 1000f6c0

void FUN_1000f6c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x28,param_2,param_3);
  return;
}



// Function: FUN_1000f6d0 at 1000f6d0

void FUN_1000f6d0(int param_1)

{
  FUN_1000f390(param_1 + -0x10);
  return;
}



// Function: FUN_1000f6e0 at 1000f6e0

void FUN_1000f6e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000f6f0 at 1000f6f0

void FUN_1000f6f0(int param_1)

{
  FUN_1000f3b0(param_1 + -0x1c);
  return;
}



// Function: FUN_1000f700 at 1000f700

void __thiscall FUN_1000f700(void *this,byte param_1)

{
  FUN_10012260((void *)((int)this + -0x38),param_1);
  return;
}



// Function: FUN_1000f710 at 1000f710

void FUN_1000f710(int param_1)

{
  FUN_1000f390(param_1 + -0x14);
  return;
}



// Function: FUN_1000f720 at 1000f720

void FUN_1000f720(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_1000f730 at 1000f730

void FUN_1000f730(int param_1)

{
  FUN_1000f3b0(param_1 + -0x20);
  return;
}



// Function: FUN_1000f740 at 1000f740

void FUN_1000f740(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000f3d0(param_1 + -0x14,param_2,param_3);
  return;
}



// Function: FUN_1000f750 at 1000f750

void FUN_1000f750(int param_1)

{
  FUN_1000f3b0(param_1 + -4);
  return;
}



// Function: FUN_1000f760 at 1000f760

undefined4 __thiscall
FUN_1000f760(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)(short)((uint)param_3 >> 0x10) + *(int *)((int)this + 0xb8);
  *(int *)((int)this + 0xc0) = iVar3;
  iVar2 = (int)(short)param_3 + *(int *)((int)this + 0xb4);
  *(int *)((int)this + 0xbc) = iVar2;
  *(int *)((int)this + 0xac) = iVar2 - *(int *)((int)this + 0xb4);
  *(int *)((int)this + 0xb0) = iVar3 - *(int *)((int)this + 0xb8);
  FUN_1000eac0((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
  piVar1 = *(int **)((int)this + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x44))(piVar1,1,(int *)((int)this + 0xa4));
  }
  piVar1 = *(int **)((int)this + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,(int)this + 0xb4,(int)this + 0xb4);
  }
  if ((*(byte *)((int)this + 0x98) & 8) != 0) {
    (**(code **)(*(int *)((int)this + 0x2c) + 100))((int)this + 0x2c,0,1);
    *param_4 = 0;
    return 0;
  }
  *param_4 = 0;
  return 0;
}



// Function: FUN_1000f820 at 1000f820

undefined4 __thiscall
FUN_1000f820(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int *piVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  if (((((*(uint *)((int)this + 0x98) & 1) != 0) && ((*(uint *)((int)this + 0x98) & 8) != 0)) &&
      (piVar1 = *(int **)((int)this + 0x74), piVar1 != (int *)0x0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,param_1,param_2,param_3,&local_8), iVar2 != 1)) {
    return local_8;
  }
  *param_4 = 0;
  return local_8;
}



// Function: FUN_1000f870 at 1000f870

undefined4 __thiscall
FUN_1000f870(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int *piVar1;
  undefined4 local_8;
  
  local_8 = 0;
  if ((*(uint *)((int)this + 0x98) & 1) != 0) {
    if ((*(uint *)((int)this + 0x98) & 8) == 0) {
      *param_4 = 0;
      return 0;
    }
    piVar1 = *(int **)((int)this + 0x74);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(piVar1,param_1,param_2,param_3,&local_8);
      *param_4 = 0;
      return local_8;
    }
  }
  *param_4 = 0;
  return 0;
}



// Function: FUN_1000f8d0 at 1000f8d0

void __thiscall FUN_1000f8d0(void *this)

{
  HDC pHVar1;
  HBRUSH pHVar2;
  HBITMAP h;
  HDC hdc;
  HGDIOBJ h_00;
  undefined4 *in_stack_00000010;
  tagPAINTSTRUCT local_58;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x70) == 0) {
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 != (HDC)0x0) {
      GetClientRect(*(HWND *)((int)this + 4),&local_18);
      pHVar2 = CreateSolidBrush(*(COLORREF *)((int)this + 0xcc));
      if (pHVar2 != (HBRUSH)0x0) {
        FillRect(pHVar1,&local_18,pHVar2);
        DeleteObject(pHVar2);
      }
      EndPaint(*(HWND *)((int)this + 4),&local_58);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else if ((*(byte *)((int)this + 0x98) & 8) == 0) {
    *in_stack_00000010 = 0;
  }
  else {
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 != (HDC)0x0) {
      GetClientRect(*(HWND *)((int)this + 4),&local_18);
      h = CreateCompatibleBitmap
                    (pHVar1,local_18.right - local_18.left,local_18.bottom - local_18.top);
      if (h != (HBITMAP)0x0) {
        hdc = CreateCompatibleDC(pHVar1);
        if (hdc != (HDC)0x0) {
          h_00 = SelectObject(hdc,h);
          if (h_00 != (HGDIOBJ)0x0) {
            pHVar2 = CreateSolidBrush(*(COLORREF *)((int)this + 0xcc));
            if (pHVar2 != (HBRUSH)0x0) {
              FillRect(hdc,&local_18,pHVar2);
              DeleteObject(pHVar2);
              (**(code **)(**(int **)((int)this + 0x70) + 0xc))
                        (*(int **)((int)this + 0x70),1,0xffffffff,0,0,0,hdc,(int)this + 0xb4,
                         (int)this + 0xb4,0,0);
              BitBlt(pHVar1,0,0,local_18.right,local_18.bottom,hdc,0,0,0xcc0020);
            }
            SelectObject(hdc,h_00);
          }
          DeleteDC(hdc);
        }
        DeleteObject(h);
      }
      EndPaint(*(HWND *)((int)this + 4),&local_58);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000faa0 at 1000faa0

undefined4 FUN_1000faa0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004003;
  if (param_3 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)(param_1 + 0x3c);
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
      return uVar2;
    }
    *param_3 = 0;
    uVar2 = 0x80040004;
  }
  return uVar2;
}



// Function: FUN_1000fae0 at 1000fae0

void FUN_1000fae0(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  HANDLE h;
  HDC hdc;
  int iVar3;
  HWND pHVar4;
  undefined4 local_a0;
  undefined1 *local_9c;
  int local_98;
  undefined4 local_94;
  undefined2 local_90;
  ushort local_8e;
  uint local_8c;
  uint local_88;
  uint local_84;
  int *local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70 [4];
  undefined2 local_60;
  byte local_5c;
  byte local_5b;
  byte local_5a;
  byte local_59;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ba18;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_7c = param_1;
  local_80 = param_2;
  local_14 = uVar2;
  if (param_2 == (int *)0x0) goto LAB_1000fc84;
  piVar1 = (int *)(param_1 + 0x8c);
  *param_2 = 0;
  if (*piVar1 == 0) {
    local_74 = 0;
    local_8 = 0;
    h = GetStockObject(0x11);
    if ((h != (HGDIOBJ)0x0) || (h = GetStockObject(0xd), h != (HGDIOBJ)0x0)) {
      GetObjectW(h,0x5c,local_70);
      local_90 = local_60;
      local_88 = (uint)local_5b;
      local_9c = local_54;
      local_8c = (uint)local_5c;
      local_8e = (ushort)local_59;
      local_84 = (uint)local_5a;
      local_a0 = 0x20;
      local_78 = local_70[0];
      if (local_70[0] < 0) {
        local_78 = -local_70[0];
      }
      if (*(HWND *)(param_1 + -0x48) == (HWND)0x0) {
        pHVar4 = GetDesktopWindow();
        hdc = GetDC(pHVar4);
        if (hdc != (HDC)0x0) {
          iVar3 = GetDeviceCaps(hdc,0x5a);
          pHVar4 = GetDesktopWindow();
          goto LAB_1000fc28;
        }
      }
      else {
        hdc = GetDC(*(HWND *)(param_1 + -0x48));
        if (hdc != (HDC)0x0) {
          iVar3 = GetDeviceCaps(hdc,0x5a);
          pHVar4 = *(HWND *)(local_7c + -0x48);
LAB_1000fc28:
          ReleaseDC(pHVar4,hdc);
          local_98 = (local_78 * 720000) / iVar3;
          local_94 = 0;
          Ordinal_420(&local_a0,&DAT_1001fa84,piVar1);
          local_8 = 0xffffffff;
          FUN_10004440(&local_74);
          goto LAB_1000fc70;
        }
      }
    }
    FUN_100014a0();
    local_8 = 0xffffffff;
    FUN_10004440(&local_74);
  }
  else {
LAB_1000fc70:
    *local_80 = *piVar1;
    piVar1 = (int *)*piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1,uVar2);
    }
  }
LAB_1000fc84:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fcb0 at 1000fcb0

undefined4 FUN_1000fcb0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != *(int *)(param_1 + 0x9c)) {
    Ordinal_6(*(int *)(param_1 + 0x9c));
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    else {
      iVar1 = Ordinal_2(param_2);
      *(int *)(param_1 + 0x9c) = iVar1;
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x8007000e);
      }
    }
  }
  return 0;
}



// Function: FUN_1000fd00 at 1000fd00

int FUN_1000fd00(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -0x7fffbffd;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    puVar1 = *(undefined4 **)(param_1 + 0x14);
    if ((puVar1 == (undefined4 *)0x0) ||
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_1001fa94,param_2), iVar2 < 0)) {
      iVar2 = (*(code *)**(undefined4 **)(param_1 + -4))(param_1 + -4,&DAT_1001fa94,param_2);
    }
  }
  return iVar2;
}



// Function: FUN_1000fd50 at 1000fd50

undefined4 FUN_1000fd50(int param_1)

{
  int *piVar1;
  HDC hDC;
  
  hDC = GetDC(*(HWND *)(param_1 + -0x24));
  if (hDC == (HDC)0x0) {
    return 0x80004005;
  }
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1,0xffffffff,0,0,0,hDC,param_1 + 0x8c,param_1 + 0x8c,0,0);
  }
  ReleaseDC(*(HWND *)(param_1 + -0x24),hDC);
  return 0;
}



// Function: FUN_1000fdb0 at 1000fdb0

undefined4 FUN_1000fdb0(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_1001ed30,param_1 + 0x48);
  return 0;
}



// Function: FUN_1000fdf0 at 1000fdf0

undefined4 FUN_1000fdf0(int param_1)

{
  int *piVar1;
  
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffe;
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



// Function: FUN_1000fe20 at 1000fe20

undefined4 FUN_1000fe20(int param_1,undefined4 param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  if ((param_3 & 1) != 0) {
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 8;
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x38))
                      (*(undefined4 **)(param_1 + 0x38),&DAT_1001ed20,param_1 + 0x48);
    if (-1 < iVar2) goto LAB_1000fe72;
  }
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_1001ed30,param_1 + 0x48);
LAB_1000fe72:
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_1 + 0x88,param_1 + 0x88);
  }
  return 0;
}



// Function: FUN_1000fe90 at 1000fe90

undefined4 FUN_1000fe90(int param_1)

{
  int *piVar1;
  
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffe;
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



// Function: FUN_1000fec0 at 1000fec0

undefined4 FUN_1000fec0(int param_1,UINT param_2,WPARAM param_3,LPARAM param_4,LRESULT *param_5)

{
  LRESULT LVar1;
  
  LVar1 = CallWindowProcW(*(WNDPROC *)(param_1 + -0xc),*(HWND *)(param_1 + -0x28),param_2,param_3,
                          param_4);
  *param_5 = LVar1;
  return 0;
}



// Function: FUN_1000fef0 at 1000fef0

undefined4 FUN_1000fef0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0x80004003;
  }
  uVar1 = (**(code **)**(undefined4 **)(param_1 + 0x34))
                    (*(undefined4 **)(param_1 + 0x34),&DAT_1001ece0,param_2);
  return uVar1;
}



// Function: FUN_1000ff20 at 1000ff20

void __fastcall FUN_1000ff20(int param_1)

{
  int iVar1;
  LONG LVar2;
  
  if ((*(byte *)(param_1 + 200) & 0x10) == 0) {
    DestroyWindow(*(HWND *)(param_1 + 4));
  }
  else {
    GetWindowLongW(*(HWND *)(param_1 + 4),-4);
    LVar2 = SetWindowLongW(*(HWND *)(param_1 + 4),-4,*(LONG *)(param_1 + 0x20));
    if (LVar2 != 0) {
      iVar1 = *(int *)(param_1 + 4);
      *(code **)(param_1 + 0x20) = DefWindowProcW_exref;
      *(undefined4 *)(param_1 + 4) = 0;
      if (iVar1 != 0) {
        *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) & 0xffffffef;
        return;
      }
    }
  }
  return;
}



// Function: FUN_1000ff80 at 1000ff80

undefined4 FUN_1000ff80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_4 = 0;
  piVar1 = *(int **)(param_1 + 0x9c);
  uVar2 = 0x80004002;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_3,param_4);
  }
  return uVar2;
}



// Function: FUN_1000ffc0 at 1000ffc0

undefined * FUN_1000ffc0(void)

{
  return FUN_1000f400;
}



// Function: FUN_1000ffd0 at 1000ffd0

LRESULT __fastcall FUN_1000ffd0(int param_1)

{
  int iVar1;
  LRESULT LVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  LVar2 = 0;
  if (iVar1 != 0) {
    LVar2 = CallWindowProcW(*(WNDPROC *)(param_1 + 0x20),*(HWND *)(param_1 + 4),*(UINT *)(iVar1 + 4)
                            ,*(WPARAM *)(iVar1 + 8),*(LPARAM *)(iVar1 + 0xc));
  }
  return LVar2;
}



// Function: FUN_10010000 at 10010000

undefined4 * __thiscall FUN_10010000(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba50;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_8 = 1;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_1001faa4,this,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010070 at 10010070

undefined4 * __thiscall FUN_10010070(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba50;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_8 = 1;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_1001f4ac,this,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100100e0 at 100100e0

void __fastcall FUN_100100e0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba83;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10010170 at 10010170

undefined2 * __thiscall FUN_10010170(void *this,int param_1)

{
  int iVar1;
  
  *(undefined2 *)this = 0;
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001150(iVar1);
  }
  *(undefined2 *)this = 8;
  iVar1 = Ordinal_2(param_1);
  *(int *)((int)this + 8) = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_100101d0 at 100101d0

void __fastcall FUN_100101d0(IID *param_1,undefined4 param_2,LPWSTR param_3,int *param_4)

{
  WCHAR WVar1;
  uint uVar2;
  LPWSTR pWVar3;
  int iVar4;
  HRESULT HVar5;
  LPVOID *unaff_EDI;
  int *local_28;
  CLSID local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bab0;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = param_4;
  local_14 = uVar2;
  if (unaff_EDI != (LPVOID *)0x0) {
    *unaff_EDI = (LPVOID)0x0;
    *(undefined1 *)param_4 = 0;
    if ((param_3 != (LPWSTR)0x0) && (WVar1 = *param_3, WVar1 != L'\0')) {
      if (((((WVar1 == L'M') || (WVar1 == L'm')) && ((param_3[1] == L'S' || (param_3[1] == L's'))))
          && ((param_3[2] == L'H' || (param_3[2] == L'h')))) &&
         ((((param_3[3] == L'T' || (param_3[3] == L't')) &&
           ((param_3[4] == L'M' || (param_3[4] == L'm')))) &&
          (((param_3[5] == L'L' || (param_3[5] == L'l')) && (param_3[6] == L':')))))) {
        CoCreateInstance((IID *)&DAT_1001fad8,(LPUNKNOWN)0x0,1,param_1,unaff_EDI);
        *(undefined1 *)local_28 = 1;
      }
      else {
        pWVar3 = FUN_1000ea10(param_3,L":");
        if (pWVar3 == (LPWSTR)0x0) {
          iVar4 = lstrlenW(param_3);
          if (iVar4 < 0xff) {
            if (*param_3 == L'{') {
              iVar4 = CLSIDFromString(param_3,&local_24);
            }
            else {
              iVar4 = CLSIDFromProgID(param_3,&local_24);
            }
            if (-1 < iVar4) {
              iVar4 = Ordinal_7(param_2,uVar2);
              if (iVar4 == 0) {
                CoCreateInstance(&local_24,(LPUNKNOWN)0x0,1,param_1,unaff_EDI);
              }
              else {
                local_28 = (int *)0x0;
                local_8 = 1;
                HVar5 = CoGetClassObject(&local_24,1,(LPVOID)0x0,(IID *)&DAT_1001fab4,&local_28);
                if (-1 < HVar5) {
                  (**(code **)(*local_28 + 0x1c))(local_28,0,0,param_1,param_2);
                }
                local_8 = 0xffffffff;
                FUN_100050c0((int *)&local_28);
              }
            }
          }
        }
        else {
          CoCreateInstance((IID *)&DAT_1001fac4,(LPUNKNOWN)0x0,1,param_1,unaff_EDI);
          *(undefined1 *)local_28 = 1;
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100103c0 at 100103c0

void __fastcall FUN_100103c0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb21;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010440 at 10010440

undefined4 __thiscall
FUN_10010440(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bb78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 0x60);
  local_14 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed50,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 2;
  if (local_14 != (int *)0x0) {
    iVar2 = (**(code **)(*local_14 + 0x14))(local_14,param_3);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10010500 at 10010500

void __fastcall FUN_10010500(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1[0x26] & 0x40U) == 0) {
    param_1[0x26] = param_1[0x26] | 0x40;
    piVar1 = (int *)param_1[0x1c];
    local_14 = param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1,1,0,0,uVar2);
    }
    if (param_1[0x25] != -0x32323233) {
      FUN_10007ba0((int *)param_1[0x18],param_1 + 0x20,param_1[0x25]);
      param_1[0x25] = -0x32323233;
    }
    piVar1 = (int *)param_1[0x19];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x50))(piVar1,param_1[0x27]);
      (**(code **)(*(int *)param_1[0x19] + 0x18))((int *)param_1[0x19],1);
      (**(code **)(*(int *)param_1[0x19] + 0xc))((int *)param_1[0x19],0);
    }
    if (param_1[0x18] != 0) {
      local_14 = (int *)0x0;
      local_8 = 1;
      (*(code *)**(undefined4 **)param_1[0x18])((undefined4 *)param_1[0x18],&DAT_1001fae8,&local_14)
      ;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 0xc))(local_14,0);
      }
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
    piVar1 = (int *)param_1[0x1c];
    if (piVar1 != (int *)0x0) {
      param_1[0x1c] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    param_1[0x24] = 0;
    piVar1 = (int *)param_1[0x1d];
    if (piVar1 != (int *)0x0) {
      param_1[0x1d] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)param_1[0x19];
    if (piVar1 != (int *)0x0) {
      param_1[0x19] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)param_1[0x18];
    if (piVar1 != (int *)0x0) {
      param_1[0x18] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)param_1[0x1b];
    if (piVar1 != (int *)0x0) {
      param_1[0x1b] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = (int *)param_1[0x1a];
    if (piVar1 != (int *)0x0) {
      param_1[0x1a] = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    param_1[0x26] = param_1[0x26] & 0xffffffa4;
    if ((HACCEL)param_1[0x31] != (HACCEL)0x0) {
      DestroyAcceleratorTable((HACCEL)param_1[0x31]);
      param_1[0x31] = 0;
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100106a0 at 100106a0

undefined4 __thiscall FUN_100106a0(void *this)

{
  uint uVar1;
  undefined4 *puVar2;
  HWND pHVar3;
  BOOL BVar4;
  undefined4 *in_stack_00000010;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aa48;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(uint *)((int)this + 0x98) = *(uint *)((int)this + 0x98) | 0x20;
  if ((*(uint *)((int)this + 0x98) & 0x40) == 0) {
    local_14 = (int *)this;
    if ((*(int *)((int)this + 100) != 0) && ((*(uint *)((int)this + 0x98) & 2) == 0)) {
      local_14 = (int *)0x0;
      local_8 = 1;
                    /* WARNING: Load size is inaccurate */
      puVar2 = (undefined4 *)(**(code **)(*this + 0x10))(uVar1);
      (**(code **)*puVar2)(puVar2,&DAT_1001faa4,&local_14);
      if (local_14 != (int *)0x0) {
        (**(code **)(**(int **)((int)this + 100) + 0x2c))
                  (*(int **)((int)this + 100),0xfffffffc,0,local_14,0,*(undefined4 *)((int)this + 4)
                   ,(int)this + 0xb4);
      }
      local_8 = 0xffffffff;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
    if ((*(byte *)((int)this + 0x98) & 8) == 0) {
      pHVar3 = GetFocus();
      BVar4 = IsChild(*(HWND *)((int)this + 4),pHVar3);
      if (BVar4 != 0) {
        *in_stack_00000010 = 0;
        ExceptionList = local_10;
        return 0;
      }
      pHVar3 = GetWindow(*(HWND *)((int)this + 4),5);
    }
    else {
      pHVar3 = *(HWND *)((int)this + 4);
    }
    SetFocus(pHVar3);
    *in_stack_00000010 = 0;
  }
  else {
    *in_stack_00000010 = 0;
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100107b0 at 100107b0

undefined4 __thiscall
FUN_100107b0(void *this,UINT param_1,WPARAM param_2,LPARAM param_3,undefined4 *param_4)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = (int *)(**(code **)(*this + 0x10))();
  (**(code **)(*piVar1 + 4))(piVar1);
  CallWindowProcW(*(WNDPROC *)((int)this + 0x20),*(HWND *)((int)this + 4),param_1,param_2,param_3);
  FUN_10010500((int *)this);
  *param_4 = 0;
  return 0;
}



// Function: FUN_10010800 at 10010800

undefined4 FUN_10010800(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001acf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x28))
                    (param_1,param_2,param_3,param_4,&local_14,&DAT_1002006c,0,0,
                     DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10010890 at 10010890

undefined4 FUN_10010890(int param_1,int *param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0x54) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(param_1 + 0x54);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(param_1 + 0x54) = param_2;
  }
  return 0;
}



// Function: FUN_100108d0 at 100108d0

undefined4
FUN_100108d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001acf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x28))
                    (param_1,param_2,param_3,param_4,&local_14,&DAT_1002006c,0,param_5,
                     DAT_10029f90 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10010960 at 10010960

uint FUN_10010960(uint param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x34);
  param_1 = *(uint *)(param_1 + 0x80) >> 5 & 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_2,*param_3,param_3[1],param_4,param_5,&param_1);
  }
  return param_1;
}



// Function: FUN_100109b0 at 100109b0

undefined4 FUN_100109b0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return 0x80004003;
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_2 + 4,param_2 + 8);
    return uVar2;
  }
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x9c);
  return 0;
}



// Function: FUN_10010a00 at 10010a00

uint FUN_10010a00(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x34);
  param_1 = *(uint *)(param_1 + 0x80) >> 6 & 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(piVar1,param_2,param_3,param_4,param_5,param_6,&param_1);
  }
  return param_1;
}



// Function: FUN_10010a50 at 10010a50

undefined4 FUN_10010a50(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10010a70 at 10010a70

undefined4 FUN_10010a70(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10010a90 at 10010a90

undefined4 FUN_10010a90(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,-(uint)(param_2 != 0));
  }
  return uVar2;
}



// Function: FUN_10010ac0 at 10010ac0

undefined4 FUN_10010ac0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,-(uint)(param_2 != 0));
  }
  return uVar2;
}



// Function: FUN_10010af0 at 10010af0

undefined4 FUN_10010af0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,-(uint)(param_2 != 0));
  }
  return uVar2;
}



// Function: FUN_10010b20 at 10010b20

undefined4 FUN_10010b20(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x34);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x3c))
                      (piVar1,*param_2,param_2[1],param_2[2],param_2[3],param_3,
                       -(uint)(param_4 != 0));
  }
  return uVar2;
}



// Function: FUN_10010b60 at 10010b60

void FUN_10010b60(int param_1,undefined4 *param_2,GUID *param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_98;
  OLECHAR local_94 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bbab;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = *(int **)(param_1 + 0x34);
  local_98 = 1;
  local_14 = uVar2;
  if (piVar1 != (int *)0x0) {
    StringFromGUID2(param_3,local_94,0x40);
    iVar3 = Ordinal_2(local_94,uVar2);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x8007000e);
    }
    local_8 = 0;
    (**(code **)(*piVar1 + 0x40))
              (piVar1,*param_2,param_2[1],param_2[2],param_2[3],iVar3,param_4,&local_98);
    local_8 = 0xffffffff;
    Ordinal_6(iVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010c40 at 10010c40

int FUN_10010c40(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  LPVOID pvVar4;
  int iVar5;
  
  iVar5 = 1;
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  *param_2 = 0;
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 == (int *)0x0) {
    iVar3 = Ordinal_7(*(undefined4 *)(param_1 + 0xa0));
    if (iVar3 != 0) {
      iVar5 = lstrlenW(*(LPCWSTR *)(param_1 + 0xa0));
      pvVar4 = CoTaskMemAlloc((iVar5 + 1) * 2);
      if (pvVar4 == (LPVOID)0x0) {
        return -0x7ff8fff2;
      }
      bVar2 = FUN_10001120(pvVar4,iVar5 + 1,*(LPCWSTR *)(param_1 + 0xa0));
      if (!bVar2) {
        return -0x7fffbffb;
      }
      *param_2 = (int)pvVar4;
      iVar5 = 0;
    }
  }
  else {
    iVar5 = (**(code **)(*piVar1 + 0x44))(piVar1,param_2,param_3);
    if ((iVar5 < 0) || (*param_2 == 0)) {
      return 1;
    }
  }
  return iVar5;
}



// Function: FUN_10010d10 at 10010d10

int FUN_10010d10(int param_1,undefined4 param_2,int *param_3)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_3;
  pvVar1 = ExceptionList;
  puStack_c = &LAB_1001bbf8;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_3 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    param_3 = (int *)0x0;
    local_8 = 1;
    iVar4 = (**(code **)(**(int **)(param_1 + 0x34) + 0x48))
                      (*(int **)(param_1 + 0x34),param_2,&param_3,uVar3);
    if ((((iVar4 < 0) || (param_3 == (int *)0x0)) ||
        (iVar4 = (**(code **)*param_3)(param_3,&DAT_1001faf8,piVar2), iVar4 < 0)) || (*piVar2 == 0))
    {
      iVar4 = -0x7fffbfff;
    }
    local_8 = 0xffffffff;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
    ExceptionList = local_10;
    return iVar4;
  }
  ExceptionList = pvVar1;
  return -0x7fffbfff;
}



// Function: FUN_10010de0 at 10010de0

int FUN_10010de0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  *param_2 = 0;
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 == (int *)0x0) {
    *param_2 = *(int *)(param_1 + 0x30);
    piVar1 = *(int **)(param_1 + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,param_2);
    if ((iVar2 < 0) || (*param_2 == 0)) {
      return -0x7fffbffe;
    }
  }
  return iVar2;
}



// Function: FUN_10010e40 at 10010e40

int FUN_10010e40(void *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  SIZE_T cb;
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  LPVOID pvVar7;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  pvVar3 = param_1;
  pvVar2 = ExceptionList;
  puStack_c = &LAB_1001bc30;
  local_10 = ExceptionList;
  uVar4 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_4 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_4 = 0;
  if (*(int *)((int)param_1 + 0x34) != 0) {
    param_1 = (void *)0x0;
    local_8 = 0;
    piVar1 = *(int **)((int)pvVar3 + 0x34);
    if (param_3 == 0) {
      param_3 = 0;
    }
    else {
      param_3 = Ordinal_2(param_3,uVar4);
      if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x8007000e);
      }
    }
    iVar6 = param_3;
    local_8._0_1_ = 1;
    iVar5 = (**(code **)(*piVar1 + 0x50))(piVar1,param_2,param_3,&param_1);
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(iVar6);
    if ((iVar5 < 0) || (iVar6 = Ordinal_7(param_1), iVar6 == 0)) {
      iVar5 = 1;
    }
    else {
      iVar6 = Ordinal_7(param_1);
      cb = iVar6 * 2 + 2;
      pvVar7 = CoTaskMemAlloc(cb);
      *param_4 = pvVar7;
      if (pvVar7 == (LPVOID)0x0) {
        local_8 = 0xffffffff;
        Ordinal_6(param_1);
        ExceptionList = local_10;
        return -0x7ff8fff2;
      }
      FUN_10001170(pvVar7,cb,param_1,cb);
    }
    local_8 = 0xffffffff;
    Ordinal_6(param_1);
    ExceptionList = local_10;
    return iVar5;
  }
  ExceptionList = pvVar2;
  return 1;
}



// Function: FUN_10010fa0 at 10010fa0

int FUN_10010fa0(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_3;
  puStack_c = &LAB_1001bc68;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (param_3 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  iVar3 = 1;
  if (*(int *)(param_1 + 0x34) != 0) {
    param_3 = (int *)0x0;
    local_8 = 1;
    iVar3 = (**(code **)(**(int **)(param_1 + 0x34) + 0x54))
                      (*(int **)(param_1 + 0x34),param_2,&param_3,uVar2);
    if (param_3 != (int *)0x0) {
      iVar3 = (*(code *)**(undefined4 **)(param_1 + -0x24))(param_1 + -0x24,&DAT_1001edf0,piVar1);
    }
    if ((iVar3 < 0) || (*piVar1 == 0)) {
      iVar3 = 1;
    }
    local_8 = 0xffffffff;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10011070 at 10011070

undefined4 FUN_10011070(int param_1,int *param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 8) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(param_1 + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(param_1 + 8) = param_2;
  }
  return 0;
}



// Function: FUN_100110b0 at 100110b0

LRESULT __thiscall
FUN_100110b0(void *this,uint param_1,WPARAM param_2,HWND param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  HWND lParam;
  BOOL BVar3;
  HWND hWnd;
  LRESULT LVar4;
  
  lParam = param_3;
  uVar2 = param_1;
  if (param_1 < 0x3a) {
    if (param_1 == 0x39) {
      hWnd = (HWND)param_3[2].unused;
    }
    else {
      switch(param_1) {
      case 0x2b:
        hWnd = (HWND)param_3[5].unused;
        if (param_3->unused == 1) {
          BVar3 = IsWindow(hWnd);
          if (BVar3 == 0) goto switchD_100110cd_default;
          hWnd = (HWND)lParam[5].unused;
        }
        break;
      case 0x2c:
        if (param_3->unused == 1) goto switchD_100110cd_default;
        hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_3[1].unused);
        break;
      case 0x2d:
        hWnd = (HWND)param_3[3].unused;
        break;
      case 0x2e:
      case 0x2f:
        goto switchD_100110cd_caseD_2e;
      default:
        goto switchD_100110cd_default;
      }
    }
  }
  else {
    if (param_1 < 0x116) {
      if (param_1 < 0x114) {
        if (param_1 == 0x4e) {
          hWnd = (HWND)param_3->unused;
          goto LAB_1001112e;
        }
        if ((param_1 != 0x111) || (param_3 == (HWND)0x0)) goto switchD_100110cd_default;
      }
    }
    else {
      if (param_1 < 0x132) goto switchD_100110cd_default;
      if (0x138 < param_1) {
        if (param_1 != 0x210) goto switchD_100110cd_default;
        FUN_1000ffd0((int)this);
        if (1 < (param_2 & 0xffff) - 1) {
          hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_2 >> 0x10);
          goto LAB_1001112e;
        }
      }
    }
switchD_100110cd_caseD_2e:
    hWnd = lParam;
  }
LAB_1001112e:
  if (hWnd != (HWND)0x0) {
    if ((*(uint *)((int)this + 0x98) & 8) == 0) {
      LVar4 = SendMessageW(hWnd,uVar2 + 0x2000,param_2,(LPARAM)lParam);
      return LVar4;
    }
    param_1 = 0;
    if (((*(uint *)((int)this + 0x98) & 1) != 0) &&
       (piVar1 = *(int **)((int)this + 0x74), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x24))(piVar1,uVar2 + 0x2000,param_2,lParam,&param_1);
    }
    return param_1;
  }
switchD_100110cd_default:
  *param_4 = 0;
  return 1;
}



// Function: FUN_10011200 at 10011200

void __fastcall FUN_10011200(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100100e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011250 at 10011250

undefined4 __thiscall FUN_10011250(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bcc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 == 3) {
    local_8 = 0;
    lVar2 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar3 = FUN_100192db(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)((int)this + 8) = uVar3;
    local_8 = 0xffffffff;
    uVar3 = FUN_100112d4();
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



// Function: Catch@100112c1 at 100112c1

undefined * Catch_100112c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100112ce;
}



// Function: FUN_100112d4 at 100112d4

undefined4 FUN_100112d4(void)

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
        FUN_10001150(0x80004005);
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



// Function: FUN_100113a0 at 100113a0

void __fastcall FUN_100113a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd06;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011400 at 10011400

undefined4 __thiscall FUN_10011400(void *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int *in_stack_00000010;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd48;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_stack_00000010 = 0;
  if ((*(uint *)((int)this + 0xa0) & 0x4000) == 0) {
    FUN_100106a0(this);
  }
  else if ((*(int *)((int)this + 100) != 0) && ((*(byte *)((int)this + 0x98) & 1) == 0)) {
    in_stack_00000010 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    puVar2 = (undefined4 *)(**(code **)(*this + 0x10))(uVar1);
    (**(code **)*puVar2)(puVar2,&DAT_1001faa4,&stack0x00000010);
    if (in_stack_00000010 != (int *)0x0) {
      (**(code **)(**(int **)((int)this + 100) + 0x2c))
                (*(int **)((int)this + 100),0xfffffffb,0,in_stack_00000010,0,
                 *(undefined4 *)((int)this + 4),(int)this + 0xb4);
    }
    local_8 = 0xffffffff;
    if (in_stack_00000010 != (int *)0x0) {
      (**(code **)(*in_stack_00000010 + 8))(in_stack_00000010);
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100114d0 at 100114d0

undefined4 FUN_100114d0(int param_1,int *param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0x58) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(param_1 + 0x58);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(param_1 + 0x58) = param_2;
  }
  return 0;
}



// Function: FUN_10011510 at 10011510

undefined4 __thiscall FUN_10011510(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 0x60);
  uVar2 = 0;
  local_14 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&local_14,DAT_10029f90 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 2;
  if (local_14 != (int *)0x0) {
    uVar2 = (**(code **)(*local_14 + 0x14))(local_14,param_1);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100115a0 at 100115a0

undefined4 FUN_100115a0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_1;
  puStack_c = &LAB_1001bde8;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0x20] = param_2;
  puVar1 = (undefined4 *)param_1[5];
  param_1 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_1,uVar3);
  }
  local_8 = 2;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))(param_1,0xfffffd43);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  (**(code **)(piVar2[-8] + 100))(piVar2 + -8,0,0);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10011650 at 10011650

undefined4 FUN_10011650(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be38;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0x21] = param_2;
  puVar1 = (undefined4 *)param_1[5];
  param_1 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_1,uVar2);
  }
  local_8 = 2;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))(param_1,0xfffffd40);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100116f0 at 100116f0

undefined4 FUN_100116f0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be38;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0x22] = param_2;
  puVar1 = (undefined4 *)param_1[5];
  param_1 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_1,uVar2);
  }
  local_8 = 2;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))(param_1,0xfffffd3f);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10011790 at 10011790

undefined4 FUN_10011790(int param_1,short param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be88;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = (int)param_2;
  _param_2 = (int *)0x0;
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ (iVar3 * 2 ^ *(uint *)(param_1 + 0x7c)) & 2;
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_2,uVar2);
  }
  local_8 = 2;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 0x14))(_param_2,0xfffffd3b);
  }
  local_8 = 0xffffffff;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 8))(_param_2);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10011830 at 10011830

undefined4 FUN_10011830(int param_1,short param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be88;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = (int)param_2;
  _param_2 = (int *)0x0;
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ (iVar3 * 4 ^ *(uint *)(param_1 + 0x7c)) & 4;
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_2,uVar2);
  }
  local_8 = 2;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 0x14))(_param_2,0xfffffd37);
  }
  local_8 = 0xffffffff;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 8))(_param_2);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100118d0 at 100118d0

undefined4 FUN_100118d0(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar4 = param_2;
  piVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bed8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((int *)param_1[0x23] != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    }
    piVar1 = (int *)piVar3[0x23];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar3[0x23] = (int)piVar4;
  }
  puVar2 = (undefined4 *)piVar3[5];
  param_1 = (int *)0x0;
  local_8 = 1;
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,&DAT_1001ed60,&param_1);
  }
  local_8 = 2;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))(param_1,0xfffffd41);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100119a0 at 100119a0

undefined4 FUN_100119a0(int param_1,short param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be88;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = (int)param_2;
  _param_2 = (int *)0x0;
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ (iVar3 * 8 ^ *(uint *)(param_1 + 0x7c)) & 8;
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_2,uVar2);
  }
  local_8 = 2;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 0x14))(_param_2,0xfffffd3e);
  }
  local_8 = 0xffffffff;
  if (_param_2 != (int *)0x0) {
    (**(code **)(*_param_2 + 8))(_param_2);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10011a50 at 10011a50

undefined4 FUN_10011a50(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be38;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0x25] = param_2;
  puVar1 = (undefined4 *)param_1[5];
  param_1 = (int *)0x0;
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_1001ed60,&param_1,uVar2);
  }
  local_8 = 2;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))(param_1,0xffffffff);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10011af0 at 10011af0

undefined4 FUN_10011af0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x38;
  }
  if (*(int **)(iVar3 + 0x3c) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(iVar3 + 0x3c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(iVar3 + 0x3c) = param_2;
  }
  puVar2 = *(undefined4 **)(param_1 + 4);
  uVar4 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = (**(code **)*puVar2)(puVar2,&DAT_1001fb18,param_1 + 0xa4);
  }
  if ((param_2 == (int *)0x0) && (piVar1 = *(int **)(param_1 + 0xa4), piVar1 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar4;
}



// Function: FUN_10011b80 at 10011b80

int __thiscall FUN_10011b80(void *this,int *param_1,int *param_2,int *param_3)

{
  LPRECT lpRect;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bfd8;
  local_10 = ExceptionList;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  ExceptionList = &local_10;
  if (*(int **)((int)this + 0x60) != param_1) {
    (**(code **)(*param_1 + 4))(param_1,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    piVar1 = *(int **)((int)this + 0x60);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)((int)this + 0x60) = param_1;
  }
  piVar1 = (int *)((int)this + 100);
  local_14 = 0;
  (**(code **)*param_1)(param_1,&DAT_1001ed70,piVar1);
  piVar2 = (int *)*piVar1;
  if (piVar2 == (int *)0x0) goto LAB_10011fe4;
  (**(code **)(*piVar2 + 0x58))(piVar2,1,(uint *)((int)this + 0xa0));
  if ((*(uint *)((int)this + 0xa0) & 0x20000) != 0) {
                    /* WARNING: Load size is inaccurate */
    puVar4 = (undefined4 *)(**(code **)(*this + 0x10))();
    local_1c = (int *)0x0;
    local_8 = 1;
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(puVar4,&DAT_1001faa4,&local_1c);
    }
    local_8 = 2;
    (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,local_1c);
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  if ((char)param_2 == '\0') {
    puVar4 = (undefined4 *)*piVar1;
    param_2 = (int *)0x0;
    local_8 = 6;
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(puVar4,&DAT_1001ed80,&param_2);
    }
    piVar2 = param_3;
    local_8 = 7;
    if (param_2 == (int *)0x0) {
      if (param_3 != (int *)0x0) {
        FUN_10010070(&param_3,(undefined4 *)*piVar1);
        local_8._0_1_ = 8;
        if (param_3 != (int *)0x0) {
          local_14 = (**(code **)(*param_3 + 0x14))(param_3,piVar2);
        }
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_10005f30((int *)&param_3);
        goto LAB_10011d0d;
      }
    }
    else {
      if (param_3 == (int *)0x0) {
        local_14 = (**(code **)(*param_2 + 0x20))(param_2);
      }
      else {
        local_14 = (**(code **)(*param_2 + 0x14))(param_2,param_3);
      }
LAB_10011d0d:
      iVar3 = local_14;
      if (local_14 < 0) {
        if ((*(uint *)((int)this + 0xa0) & 0x20000) != 0) {
          (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,0);
        }
        *(undefined4 *)((int)this + 0xa0) = 0;
        piVar2 = (int *)*piVar1;
        if (piVar2 != (int *)0x0) {
          *piVar1 = 0;
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        piVar1 = *(int **)((int)this + 0x60);
        if (piVar1 != (int *)0x0) {
          *(undefined4 *)((int)this + 0x60) = 0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        local_8 = 0xffffffff;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        ExceptionList = local_10;
        return iVar3;
      }
    }
    local_8 = 0xffffffff;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  if ((*(uint *)((int)this + 0xa0) & 0x20000) == 0) {
                    /* WARNING: Load size is inaccurate */
    puVar4 = (undefined4 *)(**(code **)(*this + 0x10))();
    FUN_10010000(&param_2,puVar4);
    local_8 = 0xd;
    (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,param_2);
    local_8 = 0xffffffff;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  piVar2 = (int *)((int)this + 0x70);
  *(undefined4 *)((int)this + 0x90) = 0;
  local_14 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_1001ecf0,piVar2);
  if (local_14 < 0) {
    local_14 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_1001ed00,piVar2);
    if (local_14 < 0) {
      local_14 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_1001ed10,piVar2);
      if (-1 < local_14) {
        *(undefined4 *)((int)this + 0x90) = 1;
      }
    }
    else {
      *(undefined4 *)((int)this + 0x90) = 3;
    }
  }
  else {
    *(undefined4 *)((int)this + 0x90) = 7;
  }
                    /* WARNING: Load size is inaccurate */
  puVar4 = (undefined4 *)(**(code **)(*this + 0x10))();
  local_18 = (int *)0x0;
  local_8 = 0x11;
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(puVar4,&DAT_1001fb08,&local_18);
  }
  local_8 = 0x12;
  (**(code **)(*(int *)*piVar1 + 0x4c))((int *)*piVar1,local_18,(int)this + 0x9c);
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(piVar2,1,0,local_18);
  }
  (**(code **)(*(int *)*piVar1 + 0x14))((int *)*piVar1,L"AXWIN",0);
  if ((*(uint *)((int)this + 0xa0) & 0x400) == 0) {
    lpRect = (LPRECT)((int)this + 0xb4);
    GetClientRect(*(HWND *)((int)this + 4),lpRect);
    *(int *)((int)this + 0xac) = *(int *)((int)this + 0xbc) - lpRect->left;
    *(int *)((int)this + 0xb0) = *(int *)((int)this + 0xc0) - *(int *)((int)this + 0xb8);
    FUN_1000eac0((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
    (**(code **)(*(int *)*piVar1 + 0x44))((int *)*piVar1,1,(int)this + 0xa4);
    (**(code **)(*(int *)*piVar1 + 0x48))((int *)*piVar1,1,(int)this + 0xa4);
    FUN_100033b0((int *)((int)this + 0xa4),(int *)((int)this + 0xac));
                    /* WARNING: Load size is inaccurate */
    *(int *)((int)this + 0xbc) = *(int *)((int)this + 0xac) + lpRect->left;
    *(int *)((int)this + 0xc0) = *(int *)((int)this + 0xb0) + *(int *)((int)this + 0xb8);
    puVar4 = (undefined4 *)(**(code **)(*this + 0x10))();
    FUN_10010000(&param_2,puVar4);
    local_8._0_1_ = 0x13;
    local_14 = (**(code **)(*(int *)*piVar1 + 0x2c))
                         ((int *)*piVar1,0xfffffffb,0,param_2,0,*(undefined4 *)((int)this + 4),
                          lpRect);
    RedrawWindow(*(HWND *)((int)this + 4),(RECT *)0x0,(HRGN)0x0,0x507);
    local_8 = CONCAT31(local_8._1_3_,0x12);
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
LAB_10011fe4:
  local_20 = (int *)0x0;
  local_8 = 0x19;
  (**(code **)*param_1)(param_1,&DAT_1001fae8,&local_20);
  piVar1 = local_20;
  if (local_20 != (int *)0x0) {
    iVar3 = *local_20;
                    /* WARNING: Load size is inaccurate */
    uVar5 = (**(code **)(*this + 0x10))();
    (**(code **)(iVar3 + 0xc))(piVar1,uVar5);
  }
  local_8 = 0xffffffff;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10012050 at 10012050

undefined4 * __fastcall FUN_10012050(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c023;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 3;
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100120e0 at 100120e0

undefined4 FUN_100120e0(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_100120f0 at 100120f0

uint FUN_100120f0(int param_1,uint param_2,int *param_3,uint *param_4)

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
      FUN_10001150(0x80004005);
    }
    return 0x80004005;
  }
  return 0x80004003;
}



// Function: FUN_100121c0 at 100121c0

void FUN_100121c0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1,(int *)&PTR_DAT_1001fb58,param_2,param_3);
  return;
}



// Function: FUN_100121e0 at 100121e0

undefined4 * __thiscall FUN_100121e0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b940;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100100e0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012260 at 10012260

void * __thiscall FUN_10012260(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c048;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000c3a0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100122c0 at 100122c0

undefined4 FUN_100122c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c070;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10012050(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_10012363();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_10012363();
  return uVar2;
}



// Function: Catch@1001234d at 1001234d

undefined * Catch_1001234d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001235a;
}



// Function: FUN_10012363 at 10012363

undefined4 FUN_10012363(void)

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



// Function: FUN_10012390 at 10012390

undefined4 __thiscall
FUN_10012390(void *this,undefined4 param_1,uint param_2,WPARAM param_3,HWND param_4,int *param_5,
            int param_6)

{
  int *piVar1;
  int iVar2;
  LRESULT LVar3;
  int *piVar4;
  uint uVar5;
  
  piVar1 = param_5;
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x14) {
    iVar2 = *(int *)((int)this + 0x70);
    *param_5 = 1;
    if (iVar2 != 0) {
      return 1;
    }
  }
  else {
    if (param_2 == 0xf) {
      param_6 = 1;
      iVar2 = FUN_1000f8d0(this);
    }
    else if (param_2 == 5) {
      param_6 = 1;
      iVar2 = FUN_1000f760(this,5,param_3,param_4,&param_6);
    }
    else if (param_2 == 0x21) {
      param_6 = 1;
      iVar2 = FUN_10011400(this);
    }
    else {
      if (param_2 != 7) {
        if (param_2 == 8) {
          *(uint *)((int)this + 0x98) = *(uint *)((int)this + 0x98) & 0xffffffdf;
          *param_5 = 0;
        }
        goto LAB_10012484;
      }
      param_6 = 1;
      iVar2 = FUN_100106a0(this);
    }
    *piVar1 = iVar2;
    if (param_6 != 0) {
      return 1;
    }
  }
LAB_10012484:
  if (((*(uint *)((int)this + 0x98) & 8) != 0) && (param_2 - 0x200 < 0xf)) {
    param_5 = (int *)(-(uint)((*(uint *)((int)this + 0x98) & 0x10) != 0) & 3);
    if (param_5 == (int *)0x0) {
      piVar4 = *(int **)((int)this + 0x70);
      if (piVar4 == (int *)0x0) goto LAB_1001261f;
      (**(code **)(*piVar4 + 0x30))
                (piVar4,1,(int)this + 0xb4,(int)(short)param_4,(int)(short)((uint)param_4 >> 0x10),0
                 ,&param_5);
    }
    if (param_5 == (int *)0x3) {
      if (param_2 == 0x200) {
        uVar5 = 0x200;
      }
      else {
        uVar5 = param_2;
        if (param_2 != 0x202) {
          if (param_2 == 0x205) {
            uVar5 = 0x205;
          }
          else if (param_2 == 0x208) {
            uVar5 = 0x208;
          }
          else if (param_2 != 0x201) {
            if (param_2 == 0x204) {
              uVar5 = 0x204;
            }
            else if (param_2 == 0x207) {
              uVar5 = 0x207;
            }
            else if (param_2 != 0x203) {
              if (param_2 != 0x206) {
                if (param_2 == 0x209) {
                  param_6 = 1;
                  iVar2 = FUN_1000f870(this,0x209,param_3,param_4,&param_6);
                  *piVar1 = iVar2;
                  if (param_6 != 0) {
                    return 1;
                  }
                }
                goto LAB_1001261f;
              }
              uVar5 = 0x206;
            }
          }
        }
      }
      param_6 = 1;
      iVar2 = FUN_1000f870(this,uVar5,param_3,param_4,&param_6);
      *piVar1 = iVar2;
      if (param_6 != 0) {
        return 1;
      }
    }
  }
LAB_1001261f:
  if ((*(uint *)((int)this + 0x98) >> 2 & *(uint *)((int)this + 0x98) & 8) == 0) {
LAB_100127ae:
    if (param_2 == 2) {
      param_6 = 1;
      iVar2 = FUN_100107b0(this,2,param_3,(LPARAM)param_4,&param_6);
      *piVar1 = iVar2;
      if (param_6 != 0) {
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x100) {
      uVar5 = 0x100;
    }
    else if (param_2 == 0x101) {
      uVar5 = 0x101;
    }
    else {
      uVar5 = param_2;
      if (param_2 != 0x102) {
        if (param_2 == 0x103) {
          uVar5 = 0x103;
        }
        else if (param_2 == 0x104) {
          uVar5 = 0x104;
        }
        else if (param_2 != 0x105) {
          if (param_2 == 0x107) {
            uVar5 = 0x107;
          }
          else if (param_2 == 0x53) {
            uVar5 = 0x53;
          }
          else if (param_2 != 0x1f) {
            if (param_2 == 0x286) {
              param_6 = 1;
              iVar2 = FUN_1000f820(this,0x286,param_3,param_4,&param_6);
              *piVar1 = iVar2;
              if (param_6 != 0) {
                return 1;
              }
            }
            else {
              if (param_2 == 0x209) {
                uVar5 = 0x209;
                goto LAB_1001264a;
              }
              if ((param_2 < 0x281) || (0x291 < param_2)) goto LAB_100127ae;
            }
            param_6 = 1;
            iVar2 = FUN_1000f820(this,param_2,param_3,param_4,&param_6);
            *piVar1 = iVar2;
            if (param_6 != 0) {
              return 1;
            }
            goto LAB_100127ae;
          }
        }
      }
    }
LAB_1001264a:
    param_6 = 1;
    iVar2 = FUN_1000f820(this,uVar5,param_3,param_4,&param_6);
    *piVar1 = iVar2;
    if (param_6 != 0) {
      return 1;
    }
  }
  if ((*(byte *)((int)this + 200) & 8) != 0) {
    param_6 = 1;
    LVar3 = FUN_100110b0(this,param_2,param_3,param_4,&param_6);
    *piVar1 = LVar3;
    if (param_6 != 0) {
      return 1;
    }
  }
  if (param_2 == DAT_10029fe0) {
                    /* WARNING: Load size is inaccurate */
    piVar4 = (int *)(**(code **)(*this + 0x10))();
    (**(code **)(*piVar4 + 4))(piVar4);
    *piVar1 = (int)piVar4;
    return 1;
  }
  if (param_2 == DAT_10029fe4) {
    piVar4 = *(int **)((int)this + 0x60);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))(piVar4);
    }
    *piVar1 = (int)piVar4;
    return 1;
  }
  if (param_2 != 0x37f) {
    return 0;
  }
  iVar2 = FUN_10010440(this,0x37f,param_3,param_4);
  *piVar1 = iVar2;
  return 1;
}



// Function: FUN_100128a0 at 100128a0

int FUN_100128a0(int param_1,int *param_2,HWND param_3)

{
  int *this;
  HWND hWnd;
  BOOL BVar1;
  int iVar2;
  bool bVar3;
  
  this = (int *)(param_1 + -0x24);
  FUN_10010500(this);
  hWnd = *(HWND *)(param_1 + -0x20);
  if ((hWnd != (HWND)0x0) && (hWnd != param_3)) {
    RedrawWindow(hWnd,(RECT *)0x0,(HRGN)0x0,0x507);
    FUN_1000ff20((int)this);
  }
  BVar1 = IsWindow(param_3);
  if (BVar1 == 0) {
    iVar2 = 1;
  }
  else {
    bVar3 = *(HWND *)(param_1 + -0x20) != param_3;
    if (bVar3) {
      iVar2 = FUN_1000f520(this,param_3);
      *(uint *)(param_1 + 0xa4) =
           *(uint *)(param_1 + 0xa4) ^ (iVar2 << 4 ^ *(uint *)(param_1 + 0xa4)) & 0x10;
    }
    iVar2 = FUN_10011b80(this,param_2,(int *)0x1,(int *)0x0);
    if (iVar2 < 0) {
      FUN_10010500(this);
      if (*(HWND *)(param_1 + -0x20) != (HWND)0x0) {
        RedrawWindow(*(HWND *)(param_1 + -0x20),(RECT *)0x0,(HRGN)0x0,0x507);
        if (bVar3) {
          FUN_1000ff20((int)this);
        }
      }
      return iVar2;
    }
  }
  return iVar2;
}



// Function: FUN_10012960 at 10012960

int FUN_10012960(int param_1,LPWSTR param_2,HWND param_3,int *param_4,int *param_5,
                undefined4 *param_6,LPSTREAM param_7,undefined4 param_8)

{
  SIZE_T dwBytes;
  HWND hWnd;
  LPWSTR lpString;
  int *piVar1;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  DWORD DVar5;
  uint uVar6;
  HGLOBAL hMem;
  LPVOID pvVar7;
  int *this;
  HRESULT HVar8;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  piVar1 = param_5;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c0d8;
  local_10 = ExceptionList;
  if (param_5 == (int *)0x0) {
    return -0x7fffbffd;
  }
  this = (int *)(param_1 + -0x24);
  ExceptionList = &local_10;
  *param_5 = 0;
  HVar8 = 1;
  param_5 = (int *)((uint)param_5 & 0xffffff);
  local_18 = this;
  FUN_10010500(this);
  local_14 = (int *)(param_1 + -0x20);
  hWnd = (HWND)*local_14;
  if ((hWnd != (HWND)0x0) && (hWnd != param_3)) {
    RedrawWindow(hWnd,(RECT *)0x0,(HRGN)0x0,0x507);
    FUN_1000ff20((int)this);
  }
  BVar3 = IsWindow(param_3);
  piVar2 = local_14;
  if (BVar3 != 0) {
    if ((HWND)*local_14 != param_3) {
      iVar4 = FUN_1000f520(this,param_3);
      param_5 = (int *)CONCAT13(1,param_5._0_3_);
      *(uint *)(param_1 + 0xa4) =
           *(uint *)(param_1 + 0xa4) ^ (iVar4 << 4 ^ *(uint *)(param_1 + 0xa4)) & 0x10;
    }
    if (*(int *)(param_1 + 0xa8) == 0) {
      iVar4 = FUN_1000ea60(piVar2);
      if (iVar4 == 0) {
        iVar4 = 5;
      }
      else {
        iVar4 = 0xf;
      }
      DVar5 = GetSysColor(iVar4);
      *(DWORD *)(param_1 + 0xa8) = DVar5;
    }
    lpString = param_2;
    param_3 = (HWND)((uint)param_3 & 0xffffff);
    HVar8 = FUN_100101d0((IID *)&PTR_1001f43c,param_8,param_2,(int *)((int)&param_3 + 3));
    if (-1 < HVar8) {
      HVar8 = FUN_10011b80(local_18,(int *)*piVar1,(int *)0x0,param_4);
    }
    *(undefined4 *)(param_1 + 0x5c) = *param_6;
    *(undefined4 *)(param_1 + 0x60) = param_6[1];
    *(undefined4 *)(param_1 + 100) = param_6[2];
    *(undefined4 *)(param_1 + 0x68) = param_6[3];
    if (-1 < HVar8) {
      if (((int *)*piVar1 != (int *)0x0) && (param_7 != (LPSTREAM)0x0)) {
        FUN_10007ac0((int *)*piVar1,param_7,(undefined4 *)(param_1 + 0x5c),param_1 + 0x70);
      }
      if ((param_3._3_1_ != '\0') && (*piVar1 != 0)) {
        uVar6 = GetWindowLongW((HWND)*local_14,-0x10);
        if ((uVar6 & 0x300000) == 0) {
          *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 8;
        }
        else {
          uVar6 = GetWindowLongW((HWND)*local_14,-0x10);
          SetWindowLongW((HWND)*local_14,-0x10,uVar6 & 0xffcfffff);
          SetWindowPos((HWND)*local_14,(HWND)0x0,0,0,0,0,0x37);
        }
        FUN_1000e370(&param_2,(int *)*piVar1);
        local_8 = 0;
        if ((((((*lpString == L'M') || (*lpString == L'm')) &&
              ((lpString[1] == L'S' || (lpString[1] == L's')))) &&
             ((lpString[2] == L'H' || (lpString[2] == L'h')))) &&
            ((lpString[3] == L'T' || (lpString[3] == L't')))) &&
           ((((lpString[4] == L'M' || (lpString[4] == L'm')) &&
             ((lpString[5] == L'L' || (lpString[5] == L'l')))) && (lpString[6] == L':')))) {
          iVar4 = lstrlenW(lpString);
          dwBytes = iVar4 * 2 - 0xe;
          hMem = GlobalAlloc(0x42,dwBytes);
          if (hMem == (HGLOBAL)0x0) {
            HVar8 = -0x7ff8fff2;
          }
          else {
            param_7 = (LPSTREAM)0x0;
            local_8._0_1_ = 2;
            pvVar7 = GlobalLock(hMem);
            FUN_10001170(pvVar7,dwBytes,lpString + 7,dwBytes);
            GlobalUnlock(hMem);
            HVar8 = CreateStreamOnHGlobal(hMem,1,&param_7);
            if (-1 < HVar8) {
              param_3 = (HWND)0x0;
              local_8 = CONCAT31(local_8._1_3_,4);
              HVar8 = (*(code *)**(undefined4 **)param_2)(param_2,&DAT_1001ed80,&param_3);
              if (-1 < HVar8) {
                HVar8 = (**(code **)(param_3->unused + 0x14))(param_3,param_7);
              }
              local_8._0_1_ = 2;
              FUN_100050c0((int *)&param_3);
            }
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100050c0((int *)&param_7);
          }
        }
        else {
          param_3 = (HWND)0x0;
          local_8._0_1_ = 6;
          local_8._1_3_ = 0;
          (*(code *)**(undefined4 **)param_2)(param_2,&DAT_1001fb80,&param_3);
          if (param_3 != (HWND)0x0) {
            Ordinal_8(local_28);
            local_8._0_1_ = 7;
            FUN_10010170(local_38,(int)lpString);
            local_8._0_1_ = 8;
            (**(code **)(param_3->unused + 0xa4))(param_3,0xffffffff);
            (**(code **)(param_3->unused + 0xd0))
                      (param_3,local_38,local_28,local_28,local_28,local_28);
            local_8._0_1_ = 7;
            Ordinal_9(local_38);
            local_8._0_1_ = 6;
            Ordinal_9(local_28);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100050c0((int *)&param_3);
        }
        local_8 = 0xffffffff;
        FUN_100050c0((int *)&param_2);
      }
      if ((-1 < HVar8) && (*(int *)(param_1 + 0x3c) != 0)) {
        ExceptionList = local_10;
        return HVar8;
      }
    }
    piVar1 = local_18;
    FUN_10010500(local_18);
    if ((((HWND)*local_14 != (HWND)0x0) &&
        (RedrawWindow((HWND)*local_14,(RECT *)0x0,(HRGN)0x0,0x507), HVar8 < 0)) &&
       (param_5._3_1_ != '\0')) {
      FUN_1000ff20((int)piVar1);
    }
  }
  ExceptionList = local_10;
  return HVar8;
}



// Function: FUN_10012d70 at 10012d70

int FUN_10012d70(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c100;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10012050(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_10012e0c();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_10012e0c();
  return iVar2;
}



// Function: Catch@10012df9 at 10012df9

undefined * Catch_10012df9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10012e06;
}



// Function: FUN_10012e0c at 10012e0c

int FUN_10012e0c(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  int iVar2;
  
  if (unaff_ESI == (int *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return -0x7ff8fff2;
  }
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x2c);
  iVar2 = 3;
  piVar1 = (int *)(**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + -0x34) + 0x10))();
  iVar2 = FUN_10011250(unaff_ESI,unaff_EBP + -0x18,unaff_EBP + -0x14,piVar1,iVar2);
  if (-1 < iVar2) {
    iVar2 = (**(code **)*unaff_ESI)();
    if (-1 < iVar2) goto LAB_10012e72;
  }
  (**(code **)(*unaff_ESI + 0x1c))(1);
LAB_10012e72:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}



// Function: FUN_10012e90 at 10012e90

undefined4 FUN_10012e90(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10029a08 == (int *)0x0) {
    uVar1 = FUN_1000b880(&PTR_DAT_100299fc,param_3);
  }
  *param_4 = DAT_10029a08;
  if (DAT_10029a08 != (int *)0x0) {
    (**(code **)(*DAT_10029a08 + 4))(DAT_10029a08);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10012ef0 at 10012ef0

void FUN_10012ef0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000d940(&PTR_DAT_100299fc,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10012f20 at 10012f20

int FUN_10012f20(int *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001c472;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_100122c0(&local_1c);
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
      piVar2 = (int *)FUN_10011250(local_1c,param_1[2],param_1[3],local_18,0);
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
        piVar2 = (int *)FUN_100023b0((int)local_1c,(int *)&PTR_DAT_1001fb58,(int *)&DAT_1001fb70,
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



// Function: FUN_10013080 at 10013080

undefined4 * __fastcall FUN_10013080(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c169;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[10] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = DefWindowProcW_exref;
  param_1[0xb] = 0;
  local_8 = 7;
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013130 at 10013130

void __cdecl FUN_10013130(wchar_t *param_1,size_t param_2,undefined4 param_3)

{
  swprintf_s(param_1,param_2,L"ATL:%p",param_3);
  return;
}



// Function: FUN_10013150 at 10013150

undefined4 FUN_10013150(void)

{
  return 1;
}



// Function: FUN_10013160 at 10013160

void FUN_10013160(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1 + -0x24,(int *)&PTR_DAT_1001fc04,param_2,param_3);
  return;
}



// Function: FUN_10013180 at 10013180

void __fastcall FUN_10013180(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c1d9;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  local_8 = 0;
  piVar2 = param_1 + 0xb;
  param_1[10] = 0xc0000001;
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
  }
  if ((HWND)param_1[1] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[1]);
  }
  (**(code **)(*DAT_10029fc8 + 8))();
  local_8 = 1;
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  if ((void *)param_1[5] != (void *)0x0) {
    FreeStdCallThunk((void *)param_1[5]);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013250 at 10013250

undefined4 * __thiscall FUN_10013250(void *this,byte param_1)

{
  FUN_10013180((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10013280 at 10013280

void FUN_10013280(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  HANDLE hProcess;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  piVar2 = (int *)FUN_10007e90(0x1002a0e4);
  if (piVar2 == (int *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*piVar2 + 8);
  piVar2[1] = (int)param_1;
  iVar3 = (*pcVar1)();
  if (piVar2[5] == 0) {
    pvVar4 = __AllocStdCallThunk_cmn();
    piVar2[5] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_100132e6;
  }
  lpBaseAddress = (undefined4 *)piVar2[5];
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = piVar2;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = (iVar3 - (int)lpBaseAddress) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
LAB_100132e6:
  pcVar1 = (code *)piVar2[5];
  SetWindowLongW(param_1,-4,(LONG)pcVar1);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10013310 at 10013310

HWND __thiscall
FUN_10013310(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,ushort param_7,LPVOID param_8)

{
  void *pvVar1;
  HANDLE hProcess;
  HWND pHVar2;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  if (*(int *)((int)this + 0x14) == 0) {
    pvVar1 = __AllocStdCallThunk_cmn();
    *(void **)((int)this + 0x14) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      SetLastError(0xe);
      return (HWND)0x0;
    }
  }
  lpBaseAddress = *(undefined4 **)((int)this + 0x14);
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = 0;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = -0xd - (int)lpBaseAddress;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
  if (param_7 == 0) {
    return (HWND)0x0;
  }
  FUN_10007de0(0x1002a0e4,(int *)((int)this + 8),(int)this);
  if ((param_6 == (HMENU)0x0) && ((param_4 & 0x40000000) != 0)) {
    param_6 = (HMENU)this;
  }
  if (param_2 == (int *)0x0) {
    param_2 = &DAT_100280b8;
  }
  pHVar2 = CreateWindowExW(param_5,(LPCWSTR)(uint)param_7,param_3,param_4,*param_2,param_2[1],
                           param_2[2] - *param_2,param_2[3] - param_2[1],param_1,param_6,
                           DAT_1002a0b0,param_8);
  return pHVar2;
}



// Function: FUN_100133f0 at 100133f0

uint __cdecl FUN_100133f0(uint param_1,WNDCLASSEXW *param_2)

{
  uint uVar1;
  ATOM AVar2;
  
  uVar1 = param_1;
  if ((param_1 != 0) && (param_2 != (WNDCLASSEXW *)0x0)) {
    AVar2 = RegisterClassExW(param_2);
    if (AVar2 != 0) {
      param_1 = (uint)AVar2;
      FUN_1000a310((void *)(uVar1 + 0x20),(undefined2 *)&param_1);
    }
    return (uint)AVar2;
  }
  return 0;
}



// Function: FUN_10013430 at 10013430

undefined2 __cdecl FUN_10013430(int param_1,uint param_2,WNDCLASSEXW *param_3,UINT *param_4)

{
  wchar_t *pwVar1;
  LPCWSTR lpszClass;
  BOOL BVar2;
  HINSTANCE pHVar3;
  HCURSOR pHVar4;
  uint uVar5;
  int iVar6;
  tagWNDCLASSEXW *ptVar7;
  WNDCLASSEXW *pWVar8;
  tagWNDCLASSEXW local_80;
  tagWNDCLASSEXW local_50;
  LPCRITICAL_SECTION local_20;
  undefined1 local_1c;
  WNDPROC local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c208;
  local_10 = ExceptionList;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != (WNDCLASSEXW *)0x0)) &&
     (param_4 != (UINT *)0x0)) {
    if ((short)param_3[1].cbWndExtra == 0) {
      local_20 = (LPCRITICAL_SECTION)(param_2 + 4);
      local_1c = 0;
      local_8 = 0;
      ExceptionList = &local_10;
      EnterCriticalSection(local_20);
      local_1c = 1;
      if ((short)param_3[1].cbWndExtra == 0) {
        if ((LPCWSTR)param_3[1].cbSize == (LPCWSTR)0x0) {
          if (param_3[1].cbClsExtra == 0) {
            pHVar3 = *(HINSTANCE *)(param_1 + 8);
          }
          else {
            pHVar3 = (HINSTANCE)0x0;
          }
          pHVar4 = LoadCursorW(pHVar3,(LPCWSTR)param_3[1].lpfnWndProc);
          param_3->hCursor = pHVar4;
        }
        else {
          local_14 = param_3->lpszClassName;
          local_18 = param_3->lpfnWndProc;
          local_50.cbSize = 0x30;
          BVar2 = GetClassInfoExW((HINSTANCE)0x0,(LPCWSTR)param_3[1].cbSize,&local_50);
          if ((BVar2 == 0) &&
             (BVar2 = GetClassInfoExW(*(HINSTANCE *)(param_1 + 4),(LPCWSTR)param_3[1].cbSize,
                                      &local_50), BVar2 == 0)) {
            local_8 = 0xffffffff;
            FUN_100066b0(&local_20);
            ExceptionList = local_10;
            return 0;
          }
          ptVar7 = &local_50;
          pWVar8 = param_3;
          for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
            pWVar8->cbSize = ptVar7->cbSize;
            ptVar7 = (tagWNDCLASSEXW *)&ptVar7->style;
            pWVar8 = (WNDCLASSEXW *)&pWVar8->style;
          }
          param_3[1].style = (UINT)param_3->lpfnWndProc;
          param_3->lpszClassName = local_14;
          param_3->lpfnWndProc = local_18;
        }
        pHVar3 = *(HINSTANCE *)(param_1 + 4);
        param_3->style = param_3->style & 0xffffbfff;
        param_3->hInstance = pHVar3;
        if (param_3->lpszClassName == (LPCWSTR)0x0) {
          pwVar1 = (wchar_t *)((int)&param_3[1].cbWndExtra + 2);
          FUN_10013130(pwVar1,0x25,param_3);
          param_3->lpszClassName = pwVar1;
        }
        lpszClass = param_3->lpszClassName;
        pWVar8 = param_3;
        ptVar7 = &local_80;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          ptVar7->cbSize = pWVar8->cbSize;
          pWVar8 = (WNDCLASSEXW *)&pWVar8->style;
          ptVar7 = (tagWNDCLASSEXW *)&ptVar7->style;
        }
        BVar2 = GetClassInfoExW(param_3->hInstance,lpszClass,&local_80);
        *(short *)&param_3[1].cbWndExtra = (short)BVar2;
        if ((short)BVar2 == 0) {
          uVar5 = FUN_100133f0(param_2,param_3);
          *(short *)&param_3[1].cbWndExtra = (short)uVar5;
        }
      }
      local_8 = 0xffffffff;
      FUN_100066b0(&local_20);
    }
    if (param_3[1].cbSize != 0) {
      *param_4 = param_3[1].style;
    }
    ExceptionList = local_10;
    return (short)param_3[1].cbWndExtra;
  }
  return 0;
}



// Function: FUN_100135f0 at 100135f0

undefined4 * __fastcall FUN_100135f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c169;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[10] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = DefWindowProcW_exref;
  param_1[0xb] = 0;
  local_8 = 7;
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100136a0 at 100136a0

undefined4 FUN_100136a0(void)

{
  return 0;
}



// Function: FUN_100136b0 at 100136b0

undefined4 FUN_100136b0(void)

{
  return 0x800401a1;
}



// Function: FUN_100136c0 at 100136c0

undefined4 FUN_100136c0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if ((*piVar1 == 0) && ((int *)(param_1 + -0x24) != (int *)0x0)) {
    (**(code **)(*(int *)(param_1 + -0x24) + 4))(1);
  }
  return uVar2;
}



// Function: FUN_100136f0 at 100136f0

void FUN_100136f0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_100023b0(param_1 + -0x24,(int *)&PTR_DAT_1001fc90,param_2,param_3);
  return;
}



// Function: FUN_10013710 at 10013710

void __fastcall FUN_10013710(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c1d9;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  local_8 = 0;
  piVar2 = param_1 + 0xb;
  param_1[10] = 0xc0000001;
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
  }
  if ((HWND)param_1[1] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[1]);
  }
  (**(code **)(*DAT_10029fc8 + 8))();
  local_8 = 1;
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  if ((void *)param_1[5] != (void *)0x0) {
    FreeStdCallThunk((void *)param_1[5]);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100137e0 at 100137e0

undefined4 * __thiscall FUN_100137e0(void *this,byte param_1)

{
  FUN_10013710((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10013810 at 10013810

undefined4 FUN_10013810(int param_1,int *param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 8) != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = *(int **)(param_1 + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(param_1 + 8) = param_2;
  }
  return 0;
}



// Function: FUN_10013850 at 10013850

void FUN_10013850(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
  
  puStack_c = &LAB_1001c246;
  local_10 = ExceptionList;
  uStack_444 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_444;
  ExceptionList = &local_10;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = uStack_444;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    FUN_100014a0();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      FUN_100014a0();
    }
    else {
      pvVar1 = LoadResource(hModule,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        FUN_100014a0();
      }
      else {
        DVar2 = SizeofResource(hModule,hResInfo);
        if (DVar2 <= DVar2 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000a4d0(&local_41c,DVar2 + 1);
          local_8 = 1;
          FUN_1001395d();
          return;
        }
      }
    }
    FreeLibrary(hModule);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10004540(&local_41c);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1001393e at 1001393e

undefined * Catch_1001393e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1001394b;
}



// Function: FUN_1001395d at 1001395d

void FUN_1001395d(void)

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
      FUN_100014a0();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x418) + iVar1 * 2) = 0;
      FUN_1000d660((void *)(unaff_EBP - 0x42c),*(LPCWSTR *)(unaff_EBP - 0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(unaff_ESI);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x418) != unaff_EBP - 0x414) {
    FUN_10004540((undefined4 *)(unaff_EBP - 0x418));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100139f0;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10013a00 at 10013a00

void FUN_10013a00(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10013850(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013a60 at 10013a60

undefined4 FUN_10013a60(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c278;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10013850(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_10013ae0 at 10013ae0

void FUN_10013ae0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10013850(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013b40 at 10013b40

undefined4 FUN_10013b40(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c278;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_10013850(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: DllRegisterServer at 10013bc0

void DllRegisterServer(void)

{
                    /* 0x13bc0  3  DllRegisterServer */
  FUN_1000d810(&DAT_1002a044,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 10013bd0

void DllUnregisterServer(void)

{
                    /* 0x13bd0  4  DllUnregisterServer */
  FUN_1000d8b0(&DAT_1002a044,1,(byte *)0x0);
  return;
}



// Function: FUN_10013be0 at 10013be0

void FUN_10013be0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1001c2d7;
  local_10 = ExceptionList;
  uVar6 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
        FUN_1000a950(pWVar2,param_4[1]);
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
  pHVar3 = DAT_1002a0b0;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1002a0b0,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_100014a0();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10004440((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10006f80(&local_a5c);
        goto LAB_10013e59;
      }
      FUN_100015e0(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001120(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10004440((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10006f80(&local_a5c);
          goto LAB_10013e59;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_1000ab00(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_1000ab00(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10013b40(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10013a60(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10004440((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10006f80(&local_a5c);
LAB_10013e59:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013e80 at 10013e80

void FUN_10013e80(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
  
  puStack_c = &LAB_1001c337;
  local_10 = ExceptionList;
  uVar6 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
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
        FUN_1000a950(pWVar2,param_4[1]);
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
  pHVar3 = DAT_1002a0b0;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1002a0b0,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_100014a0();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10004440((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10006f80(&local_a5c);
        goto LAB_100140e3;
      }
      FUN_100015e0(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10001120(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10004440((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10006f80(&local_a5c);
          goto LAB_100140e3;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_1000ab00(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_1000ab00(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10013ae0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10013a00(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10004440((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10006f80(&local_a5c);
LAB_100140e3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10014100 at 10014100

undefined4 FUN_10014100(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c3a0;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1[0x11] == 0) {
    piVar4 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar4 = (int *)0x0;
    }
    iVar3 = FUN_1000cba0(piVar4,0xfffffe00);
    if (iVar3 == 1) {
      ExceptionList = local_10;
      return 1;
    }
  }
  piVar4 = (int *)piVar1[0x38];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4,uVar2);
    piVar1[0x38] = 0;
  }
  if (param_2 != (int *)0x0) {
    param_1 = (int *)0x0;
    local_8 = 1;
    (**(code **)*param_2)(param_2,&DAT_1001f6b4,&param_1);
    if (param_1 != (int *)0x0) {
      param_2 = (int *)0x0;
      local_8 = 4;
      (**(code **)(*param_1 + 0x50))(param_1,&param_2);
      if (param_2 != (int *)0x0) {
        (**(code **)*param_2)(param_2,&DAT_1001fa84,piVar1 + 0x38);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  piVar1[0x12] = piVar1[0x12] | 0x80;
  if (piVar1[0x11] == 0) {
    piVar4 = piVar1;
    if (piVar1 == (int *)0xfffffffc) {
      piVar4 = (int *)0x0;
    }
    FUN_1000cdc0(piVar4,0xfffffe00);
  }
  FUN_1000a2b0((int)(piVar1 + 1));
  FUN_10009ed0(piVar1 + 1,0);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10014260 at 10014260

undefined4 FUN_10014260(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe00);
    if (iVar1 == 1) {
      return 1;
    }
  }
  if ((int *)param_1[0x38] != param_2) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar2 = (int *)param_1[0x38];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    param_1[0x38] = (int)param_2;
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe00);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014310 at 10014310

undefined4 FUN_10014310(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe0b);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x30] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe0b);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014390 at 10014390

undefined4 FUN_10014390(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe09);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x31] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe09);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014410 at 10014410

undefined4 FUN_10014410(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe02);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x36] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe02);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014490 at 10014490

undefined4 FUN_10014490(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffdff);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x39] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffdff);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014510 at 10014510

undefined4 FUN_10014510(int *param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffdfe);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x35] = (int)param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffdfe);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014590 at 10014590

undefined4 FUN_10014590(int *param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffdf9);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x33] = (int)param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffdf9);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014610 at 10014610

undefined4 FUN_10014610(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe08);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x32] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe08);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014690 at 10014690

undefined4 FUN_10014690(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe07);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x34] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe07);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014710 at 10014710

undefined4 FUN_10014710(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_1000cba0(piVar2,0xfffffe01);
    if (iVar1 == 1) {
      return 1;
    }
  }
  param_1[0x12] = param_1[0x12] | 0x80;
  param_1[0x37] = param_2;
  if (param_1[0x11] == 0) {
    piVar2 = param_1;
    if (param_1 == (int *)0xfffffffc) {
      piVar2 = (int *)0x0;
    }
    FUN_1000cdc0(piVar2,0xfffffe01);
  }
  FUN_1000a2b0((int)(param_1 + 1));
  FUN_10009ed0(param_1 + 1,0);
  return 0;
}



// Function: FUN_10014790 at 10014790

undefined4 FUN_10014790(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_10029cf8 == (int *)0x0) {
    uVar1 = FUN_1000b880(&PTR_DAT_10029cec,param_3);
  }
  *param_4 = DAT_10029cf8;
  if (DAT_10029cf8 != (int *)0x0) {
    (**(code **)(*DAT_10029cf8 + 4))(DAT_10029cf8);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100147f0 at 100147f0

void FUN_100147f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000d940(&PTR_DAT_10029cec,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10014820 at 10014820

void FUN_10014820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_10029cf8 == (int *)0x0) || (DAT_10029d00 == 0)) {
    FUN_1000b880(&PTR_DAT_10029cec,param_4);
  }
  if (DAT_10029cf8 != (int *)0x0) {
    (**(code **)(*DAT_10029cf8 + 0x2c))
              (DAT_10029cf8,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10014880 at 10014880

undefined4 __thiscall
FUN_10014880(void *this,undefined4 param_1,int param_2,HDC param_3,undefined4 *param_4,
            undefined4 *param_5,int param_6)

{
  undefined4 uVar1;
  short sVar2;
  
  if (param_6 == 0) {
    if (param_2 == 0x110) {
      FUN_1000c900(0x67);
      *param_5 = 1;
      return 1;
    }
    if (param_2 == 0x136) {
      uVar1 = FUN_10005a20((void *)((int)this + -0x48),0x136,param_3);
      *param_5 = uVar1;
      return 1;
    }
    if (param_2 == 0x138) {
      uVar1 = FUN_10005a20((void *)((int)this + -0x48),0x138,param_3);
      *param_5 = uVar1;
      return 1;
    }
    if (param_2 == 7) {
      uVar1 = FUN_1000e0a0((void *)((int)this + -0x48));
      *param_5 = uVar1;
      return 1;
    }
    if (param_2 == 0x111) {
      sVar2 = (short)((uint)param_3 >> 0x10);
      if (sVar2 == 0x200) {
        *(undefined4 **)((int)this + 0x2c) = param_4;
        *param_5 = 0;
      }
      if (sVar2 == 7) {
        *(undefined4 **)((int)this + 0x2c) = param_4;
        *param_5 = 0;
      }
      if (sVar2 == 5) {
        *(undefined4 **)((int)this + 0x2c) = param_4;
        *param_5 = 0;
      }
      if (sVar2 == 4) {
        *(undefined4 **)((int)this + 0x2c) = param_4;
        *param_5 = 0;
        return 0;
      }
    }
    else if (param_2 == 0x4e) {
      if (param_4[2] == -8) {
        *(undefined4 *)((int)this + 0x2c) = *param_4;
        *param_5 = 0;
        return 0;
      }
    }
    else {
      if (param_2 == 8) {
        uVar1 = FUN_1000d090((void *)((int)this + -0x48));
        *param_5 = uVar1;
        return 1;
      }
      if (param_2 == 0x21) {
        uVar1 = FUN_1000c570((void *)((int)this + -0x48));
        *param_5 = uVar1;
        return 1;
      }
    }
  }
  return 0;
}



// Function: FUN_10014a50 at 10014a50

int FUN_10014a50(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x84;
  }
  bVar1 = FUN_100066d0((void *)(iVar3 + 0x14),param_4);
  if (bVar1) {
    if (param_2 < 1) {
      iVar2 = -0x7fffbfff;
      switch(param_2) {
      case 0:
        iVar3 = FUN_1000e170((void *)(iVar3 + 0x84),param_7,param_6);
        return iVar3;
      case -7:
        iVar2 = FUN_1000d2a0((void *)(iVar3 + 4),param_7,param_6);
        break;
      case -6:
      case -2:
        return 0;
      case -5:
        iVar3 = FUN_1000c6c0(iVar3 + 0x84);
        return iVar3;
      case -4:
        iVar3 = FUN_1000c700(iVar3 + 0x84);
        return iVar3;
      case -3:
        iVar3 = FUN_10005ab0(iVar3 + 0x84);
        return iVar3;
      case -1:
        iVar3 = FUN_1000c690(iVar3 + 0x84);
        return iVar3;
      }
      return iVar2;
    }
    FUN_1000e170((void *)(iVar3 + 0x84),param_7,param_6);
    return 0x40180;
  }
  return -0x7fff0001;
}



// Function: FUN_10014b70 at 10014b70

void FUN_10014b70(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c3d6;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    __security_check_cookie(DAT_10029f90 ^ (uint)&stack0xfffffffc ^ (uint)&stack0xfffffffc);
    return;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000e280(puVar1);
    local_8 = 0xffffffff;
    FUN_10014bfe();
    return;
  }
  local_8 = 0xffffffff;
  FUN_10014bfe();
  return;
}



// Function: Catch@10014beb at 10014beb

undefined * Catch_10014beb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014bf8;
}



// Function: FUN_10014bfe at 10014bfe

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10014bfe(void)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *unaff_EBX;
  uint unaff_EBP;
  int *piVar6;
  int unaff_EDI;
  int *piVar7;
  
  if (unaff_EBX == (int *)0x0) goto LAB_10014d11;
  if ((DAT_1002a01c & 1) == 0) {
    DAT_1002a01c = DAT_1002a01c | 1;
    *(undefined4 *)(unaff_EBP - 4) = 2;
    DAT_1002a014 = 0x18;
    DAT_1002a018 = unaff_EDI;
    *(int *)(unaff_EBP - 4) = unaff_EDI;
  }
  piVar6 = &DAT_1002a014;
  *(undefined4 *)(unaff_EBP - 0x18) = 0;
  *(undefined4 *)(unaff_EBP - 4) = 3;
  cVar2 = FUN_100047d0(4);
  if (cVar2 == '\0') {
    piVar3 = FUN_10006430((void *)(unaff_EBP - 0x18),4);
    *(int **)(unaff_EBP - 0x1c) = piVar3;
  }
  else {
    piVar3 = (int *)&stack0xfffffffc;
    *(undefined1 **)(unaff_EBP - 0x10) = &stack0xfffffffc;
    *(undefined1 **)(unaff_EBP - 0x1c) = &stack0xfffffffc;
  }
  if (piVar3 == (int *)0x0) {
    (**(code **)(*unaff_EBX + 0x1c))();
    *(int *)(unaff_EBP - 4) = unaff_EDI;
    FUN_10004440((int *)(unaff_EBP - 0x18));
    goto LAB_10014d11;
  }
  piVar7 = piVar3;
  if (DAT_1002a014 != unaff_EDI) {
    do {
      if (*piVar6 == -2) {
        piVar6 = (int *)(*(code *)piVar6[1])();
        piVar3 = *(int **)(unaff_EBP - 0x1c);
      }
      else {
        *piVar7 = *piVar6 + *(int *)(unaff_EBP + 8);
        piVar7 = piVar7 + 1;
        piVar6 = piVar6 + 1;
      }
    } while (*piVar6 != -1);
    unaff_EDI = -1;
  }
  iVar4 = FUN_10011250(unaff_EBX,(int)piVar3,(int)(piVar3 + 1),*(int **)(unaff_EBP + 8),3);
  puVar5 = (undefined4 *)*unaff_EBX;
  if (iVar4 < 0) {
LAB_10014cfb:
    (*(code *)puVar5[7])();
  }
  else {
    iVar4 = (*(code *)*puVar5)();
    if (iVar4 < 0) {
      puVar5 = (undefined4 *)*unaff_EBX;
      goto LAB_10014cfb;
    }
  }
  *(int *)(unaff_EBP - 4) = unaff_EDI;
  FUN_10004440((int *)(unaff_EBP - 0x18));
LAB_10014d11:
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x24) = 0x10014d2c;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_10014d40 at 10014d40

void FUN_10014d40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((DAT_10029a08 == (int *)0x0) || (DAT_10029a10 == 0)) {
    iVar2 = FUN_1000b880(&PTR_DAT_100299fc,param_4);
  }
  if (DAT_10029a08 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_10029a08 + 0x2c))
                      (DAT_10029a08,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  if (((iVar2 == -0x7ffdfffd) || (iVar2 == -0x7ffd7fd5)) &&
     (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if ((-1 < iVar2) && ((param_5 & 4) != 0)) {
      FUN_10011510((void *)(param_1 + -0x4c),param_2);
    }
  }
  return;
}



// Function: FUN_10014df0 at 10014df0

int FUN_10014df0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c400;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1000e570(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_10014e89();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_10014e89();
  return iVar2;
}



// Function: Catch@10014e79 at 10014e79

undefined * Catch_10014e79(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014e86;
}



// Function: FUN_10014e89 at 10014e89

int FUN_10014e89(void)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    lVar1 = (ulonglong)(uint)(*(int *)(*(int *)(unaff_EBP + 8) + 8) * 4 >> 2) * 8;
    uVar2 = FUN_100192db(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar3 = FUN_10014ee4();
    return iVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -0x7ff8fff2;
}



// Function: Catch@10014ed1 at 10014ed1

undefined * Catch_10014ed1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014ede;
}



// Function: FUN_10014ee4 at 10014ee4

int FUN_10014ee4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int unaff_EBP;
  int *unaff_ESI;
  int *piVar5;
  int unaff_EDI;
  
  piVar2 = *(int **)(unaff_EBP + -0x18);
  if (piVar2 == (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x1c))(1);
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return -0x7ff8fff2;
  }
  *(int **)(unaff_EBP + 8) = piVar2;
  piVar5 = *(int **)(unaff_EDI + 4);
  piVar4 = piVar2;
  if (piVar5 < piVar5 + *(int *)(unaff_EDI + 8)) {
    do {
      piVar2 = (int *)*piVar5;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        *piVar4 = *piVar5;
        if (*piVar5 != 0) {
          iVar3 = 1;
          piVar1 = *(int **)(unaff_EDI + 4);
          piVar2 = piVar1 + *(int *)(unaff_EDI + 8);
          if (piVar1 < piVar2) {
            do {
              if (*piVar1 == *piVar5) {
                piVar4 = *(int **)(unaff_EBP + 8);
                goto LAB_10014f63;
              }
              iVar3 = iVar3 + 1;
              piVar1 = piVar1 + 1;
            } while (piVar1 < piVar2);
            piVar4 = *(int **)(unaff_EBP + 8);
          }
        }
        iVar3 = 0;
LAB_10014f63:
        piVar4[1] = iVar3;
        piVar4 = piVar4 + 2;
        *(int **)(unaff_EBP + 8) = piVar4;
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < (int *)(*(int *)(unaff_EDI + 4) + *(int *)(unaff_EDI + 8) * 4));
    piVar2 = *(int **)(unaff_EBP + -0x18);
  }
  piVar5 = *(int **)(unaff_EBP + -0x14);
  FUN_1000d150(piVar5,(int)piVar2,(int)piVar4,(int *)0x0,2);
  iVar3 = FUN_100023b0((int)piVar5,(int *)&PTR_DAT_1001f44c,(int *)&DAT_1001f464,
                       *(undefined4 **)(unaff_EBP + 0xc));
  if (iVar3 < 0) {
    (**(code **)(*piVar5 + 0x1c))(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}



// Function: FUN_10014fd0 at 10014fd0

int FUN_10014fd0(int *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001c472;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_1000e7c0(&local_1c);
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
      piVar2 = (int *)FUN_10011250(local_1c,param_1[2],param_1[3],local_18,0);
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
        piVar2 = (int *)FUN_100023b0((int)local_1c,(int *)&PTR_DAT_1001f7bc,(int *)&DAT_1001f7d4,
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



// Function: FUN_10015130 at 10015130

int FUN_10015130(int *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001c472;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_1000e890(&local_1c);
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
      piVar2 = (int *)FUN_1000d150(local_1c,param_1[2],param_1[3],local_18,0);
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
        piVar2 = (int *)FUN_100023b0((int)local_1c,(int *)&PTR_DAT_1001f44c,(int *)&DAT_1001f464,
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



// Function: FUN_10015290 at 10015290

undefined4 * __thiscall FUN_10015290(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c49b;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)this;
  }
  FUN_1000e960((void *)((int)this + 8),param_1);
  local_8 = 0;
  (**(code **)(*DAT_10029fc8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10015310 at 10015310

undefined4 FUN_10015310(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10015320 at 10015320

int FUN_10015320(int *param_1)

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



// Function: FUN_10015350 at 10015350

int FUN_10015350(int *param_1,int *param_2,undefined4 *param_3)

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
  iVar1 = FUN_100023b0((int)(param_1 + 2),(int *)&PTR_DAT_1001fd08,param_2,param_3);
  return iVar1;
}



// Function: FUN_100153c0 at 100153c0

undefined4 * __thiscall FUN_100153c0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c4d3;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  FUN_10010500((int *)((int)this + 8));
  (**(code **)(*DAT_10029fc8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000c3a0((int)this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10015450 at 10015450

undefined4 FUN_10015450(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c4f0;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10013080(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_100154f3();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_100154f3();
  return uVar2;
}



// Function: Catch@100154dd at 100154dd

undefined * Catch_100154dd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100154ea;
}



// Function: FUN_100154f3 at 100154f3

undefined4 FUN_100154f3(void)

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



// Function: FUN_10015520 at 10015520

undefined4 FUN_10015520(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c510;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_100135f0(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_100155c3();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_100155c3();
  return uVar2;
}



// Function: Catch@100155ad at 100155ad

undefined * Catch_100155ad(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100155ba;
}



// Function: FUN_100155c3 at 100155c3

undefined4 FUN_100155c3(void)

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



// Function: FUN_100155f0 at 100155f0

void FUN_100155f0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10013be0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10015600 at 10015600

void FUN_10015600(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10013e80(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10015610 at 10015610

void FUN_10015610(int param_1)

{
  FUN_10013e80(&DAT_1002a044,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10015630 at 10015630

/* WARNING: Removing unreachable block (ram,0x100156a3) */

undefined4 __thiscall
FUN_10015630(void *this,undefined4 param_1,int param_2,HDC param_3,undefined4 *param_4,
            undefined4 *param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x110) {
    uVar1 = FUN_10016fd0((int)this + -0x4c);
  }
  else {
    if (param_2 != 5) {
      iVar2 = FUN_10014880(this,param_1,param_2,param_3,param_4,param_5,0);
      if (iVar2 != 0) {
        return 1;
      }
      return 0;
    }
    uVar1 = FUN_10017050((void *)((int)this + -0x4c),5,param_3,(ushort)param_4);
  }
  *param_5 = uVar1;
  return 1;
}



// Function: FUN_100156d0 at 100156d0

undefined2 * __thiscall FUN_100156d0(void *this,int *param_1)

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
  FUN_1000e470(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return (undefined2 *)this;
}



// Function: FUN_10015720 at 10015720

int FUN_10015720(int param_1,int *param_2,int *param_3,LPRECT param_4,LPRECT param_5,
                undefined4 *param_6)

{
  void *this;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  HACCEL pHVar4;
  HWND pHVar5;
  tagACCEL local_c;
  
  iVar1 = param_1;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if ((((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) && (param_4 != (LPRECT)0x0)) &&
     (param_5 != (LPRECT)0x0)) {
    this = (void *)(param_1 + 0x3c);
    if (*(int *)(param_1 + 0x3c) == 0) {
      iVar3 = FUN_10015450(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))(param_1 + 0x24,&DAT_1001fc34,this);
    }
    if (*(int *)(iVar1 + 0x40) == 0) {
      iVar3 = FUN_10015520(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))
                (param_1 + 0x24,&DAT_1001fc44,(void *)(iVar1 + 0x40));
    }
    iVar3 = FUN_1000f360(this,param_2);
    if ((-1 < iVar3) && (iVar3 = FUN_1000f360((void *)(iVar1 + 0x40),param_3), -1 < iVar3)) {
      GetClientRect(*(HWND *)(iVar1 + -0x28),param_4);
      GetClientRect(*(HWND *)(iVar1 + -0x28),param_5);
      if (*(int *)(iVar1 + 0x98) == 0) {
        local_c.fVirt = '\0';
        local_c.key = 0;
        local_c.cmd = 0;
        pHVar4 = CreateAcceleratorTableW(&local_c,1);
        *(HACCEL *)(iVar1 + 0x98) = pHVar4;
      }
      puVar2 = param_6;
      *param_6 = 0x14;
      param_6[1] = *(uint *)(iVar1 + 0x6c) >> 2 & 1;
      pHVar5 = GetParent(*(HWND *)(iVar1 + -0x28));
      puVar2[2] = pHVar5;
      puVar2[3] = *(undefined4 *)(iVar1 + 0x98);
      puVar2[4] = (uint)(*(int *)(iVar1 + 0x98) != 0);
    }
    return iVar3;
  }
  return -0x7fffbffd;
}



// Function: FUN_10015880 at 10015880

void __thiscall
FUN_10015880(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_10029b50 == 0) {
    DAT_10029b50 = 0;
  }
  uVar1 = FUN_10013430(0x1002a0ac,0x1002a0e4,(WNDCLASSEXW *)&DAT_10029b20,(UINT *)((int)this + 0x20)
                      );
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  FUN_10013310(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_10015900 at 10015900

void __thiscall
FUN_10015900(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_10029c90 == 0) {
    DAT_10029c90 = 0;
  }
  uVar1 = FUN_10013430(0x1002a0ac,0x1002a0e4,(WNDCLASSEXW *)&DAT_10029c60,(UINT *)((int)this + 0x20)
                      );
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  FUN_10013310(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_10015980 at 10015980

int FUN_10015980(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c53b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = operator_new(0xf4);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (this != (void *)0x0) {
      FUN_10015290(this,param_1);
    }
    local_8 = 0xffffffff;
    iVar1 = FUN_10015a2c();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10015a16 at 10015a16

undefined * Catch_10015a16(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015a23;
}



// Function: FUN_10015a2c at 10015a2c

int FUN_10015a2c(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
    unaff_ESI[1] = unaff_ESI[1] + -1;
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI != 0) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10015a70 at 10015a70

undefined4 FUN_10015a70(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  if (*(int *)(param_1 + -0x20) == 0) {
    FUN_10015880((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN Frame Window",0xcf0000,0,
                 (HMENU)0x0,(LPVOID)0x0);
  }
  *param_2 = *(undefined4 *)(param_1 + -0x20);
  return 0;
}



// Function: FUN_10015ad0 at 10015ad0

undefined4 FUN_10015ad0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004005;
  }
  if (*(int *)(param_1 + -0x20) == 0) {
    FUN_10015900((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN UI Window",0xcf0000,0,
                 (HMENU)0x0,(LPVOID)0x0);
  }
  *param_2 = *(undefined4 *)(param_1 + -0x20);
  return 0;
}



// Function: FUN_10015b30 at 10015b30

int FUN_10015b30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c5b0;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10016330();
  local_14 = (int *)0x0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  iVar2 = FUN_10015980((undefined4 *)0x0,&PTR_1001f43c,&local_14);
  if (-1 < iVar2) {
    local_1c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,5);
    (**(code **)*local_14)(local_14,&DAT_1001fdd4,&local_1c,uVar1);
    if (param_1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = Ordinal_2(param_1);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x8007000e);
      }
    }
    local_8._0_1_ = 6;
    iVar2 = (**(code **)(*local_1c + 0x28))
                      (local_1c,iVar3,param_2,param_3,&local_18,param_6,param_7,param_8);
    local_8._0_1_ = 5;
    Ordinal_6(iVar3);
    local_8._0_1_ = 3;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    if (iVar2 < 0) {
      *param_4 = 0;
    }
    else {
      *param_4 = local_14;
      local_14 = (int *)0x0;
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    if (iVar2 < 0) {
      *param_5 = 0;
    }
    else {
      *param_5 = local_18;
      local_18 = (int *)0x0;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10015c80 at 10015c80

int __thiscall
FUN_10015c80(void *this,int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c608;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  iVar3 = FUN_100096e0(this,&DAT_1001f778,&local_14);
  if (iVar3 < 0) {
                    /* WARNING: Load size is inaccurate */
    iVar3 = FUN_10015b30(param_1,*this,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    local_18 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
                    /* WARNING: Load size is inaccurate */
    iVar3 = (**(code **)(*local_14 + 0x28))
                      (local_14,param_1,*this,param_2,&local_18,param_5,param_6,param_7,uVar2);
    piVar1 = local_18;
    if (-1 < iVar3) {
      if (param_4 != (undefined4 *)0x0) {
        local_18 = (int *)0x0;
        *param_4 = piVar1;
      }
      if (param_3 != (undefined4 *)0x0) {
        iVar3 = (**(code **)*local_14)(local_14,&PTR_1001f43c,param_3);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10015d90 at 10015d90

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10015d90(HWND param_1,UINT param_2,WPARAM param_3,HWND param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  LPWSTR lpString;
  HGLOBAL hMem;
  LPVOID pvVar4;
  SIZE_T dwBytes;
  uint local_38;
  LONG local_28;
  LPWSTR local_24;
  LPSTREAM local_20;
  int *local_1c;
  LPWSTR local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c670;
  local_10 = ExceptionList;
  local_38 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_38;
  if (param_2 == 1) {
    OleInitialize((LPVOID)0x0);
    iVar3 = GetWindowTextLengthW(param_1);
    uVar1 = iVar3 * 2 + 10;
    if (uVar1 < 0x401) {
      lpString = (LPWSTR)&local_38;
      if (&stack0x00000000 != (undefined1 *)0x38) {
        local_38 = 0xcccc;
        lpString = (LPWSTR)(&stack0xffffffd0 + -uVar1);
      }
    }
    else {
      lpString = (LPWSTR)malloc(uVar1);
      if (lpString != (LPWSTR)0x0) {
        lpString[0] = L'\xdddd';
        lpString[1] = L'\0';
        lpString = lpString + 4;
      }
    }
    local_8 = 0;
    if (lpString == (LPWSTR)0x0) {
      local_8 = 0xffffffff;
      local_24 = (LPWSTR)0x0;
      local_18 = (LPWSTR)0x0;
      goto LAB_10016029;
    }
    local_24 = lpString;
    local_18 = lpString;
    GetWindowTextW(param_1,lpString,iVar3 + 1);
    SetWindowTextW(param_1,L"");
    dwBytes = 0;
    local_28 = 0;
    if ((param_4 != (HWND)0x0) && ((ushort *)param_4->unused != (ushort *)0x0)) {
      dwBytes = (SIZE_T)*(ushort *)param_4->unused;
    }
    local_20 = (IStream *)0x0;
    local_8._0_1_ = 2;
    if ((dwBytes != 0) &&
       (hMem = GlobalAlloc(0x42,dwBytes), lpString = local_18, hMem != (HGLOBAL)0x0)) {
      pvVar4 = GlobalLock(hMem);
      FUN_10001170(pvVar4,dwBytes,(void *)(param_4->unused + 2),dwBytes);
      GlobalUnlock(hMem);
      CreateStreamOnHGlobal(hMem,1,&local_20);
      lpString = local_18;
    }
    local_18 = (LPWSTR)0x0;
    local_1c = (int *)0x0;
    local_8._0_1_ = 5;
    iVar3 = FUN_10015b30((int)lpString,param_1,local_20,&local_1c,(undefined4 *)0x0,&DAT_1002006c,0,
                         0);
    if (iVar3 < 0) {
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      local_8._0_1_ = 2;
      FUN_10004440((int *)&local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_20 != (IStream *)0x0) {
        (*local_20->lpVtbl->Release)(local_20);
      }
    }
    else {
      iVar3 = (**(code **)*local_1c)(local_1c,&DAT_1001fdd4,&local_28);
      if (-1 < iVar3) {
        SetWindowLongW(param_1,-0x15,local_28);
        local_8._0_1_ = 3;
        FUN_100050c0((int *)&local_1c);
        local_8._0_1_ = 2;
        FUN_10004440((int *)&local_18);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100050c0((int *)&local_20);
        local_8 = 0xffffffff;
        FUN_10006680((int *)&local_24);
        goto LAB_10016016;
      }
      local_8._0_1_ = 3;
      FUN_100050c0((int *)&local_1c);
      local_8._0_1_ = 2;
      FUN_10004440((int *)&local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100050c0((int *)&local_20);
    }
    local_8 = 0xffffffff;
    FUN_10006680((int *)&local_24);
  }
  else {
    if (param_2 == 0x82) {
      piVar2 = (int *)GetWindowLongW(param_1,-0x15);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      OleUninitialize();
    }
    else if ((((param_2 == 0x210) && ((short)param_3 == 1)) && (param_4 != (HWND)0x0)) &&
            (uVar1 = GetWindowLongW(param_4,-0x14), (uVar1 & 0x10000) != 0)) {
      uVar1 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar1 | 0x10000);
    }
LAB_10016016:
    DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
  }
LAB_10016029:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016050 at 10016050

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10016050(HWND param_1,UINT param_2,WPARAM param_3,HWND param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  HGLOBAL hMem;
  LPVOID pvVar5;
  SIZE_T dwBytes;
  uint local_40;
  LONG local_30;
  LPWSTR local_2c;
  int local_28;
  undefined4 local_24;
  LPWSTR local_20;
  undefined4 *local_1c;
  LPSTREAM local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c6e0;
  local_10 = ExceptionList;
  local_40 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_40;
  if (param_2 == 1) {
    OleInitialize((LPVOID)0x0);
    iVar4 = GetWindowTextLengthW(param_1);
    uVar2 = iVar4 * 2 + 10;
    if (uVar2 < 0x401) {
      local_2c = (LPWSTR)&local_40;
      if (&stack0x00000000 != (undefined1 *)0x40) {
        local_40 = 0xcccc;
        local_2c = (LPWSTR)(&stack0xffffffc8 + -uVar2);
      }
    }
    else {
      local_2c = (LPWSTR)malloc(uVar2);
      if (local_2c != (LPWSTR)0x0) {
        local_2c[0] = L'\xdddd';
        local_2c[1] = L'\0';
        local_2c = local_2c + 4;
      }
    }
    local_8 = 0;
    if (local_2c == (LPWSTR)0x0) {
      local_8 = 0xffffffff;
      local_20 = (LPWSTR)0x0;
      goto LAB_10016307;
    }
    local_20 = local_2c;
    GetWindowTextW(param_1,local_2c,iVar4 + 1);
    SetWindowTextW(param_1,L"");
    dwBytes = 0;
    local_30 = 0;
    if ((param_4 != (HWND)0x0) && ((ushort *)param_4->unused != (ushort *)0x0)) {
      dwBytes = (SIZE_T)*(ushort *)param_4->unused;
    }
    local_18 = (IStream *)0x0;
    local_8._0_1_ = 2;
    if ((dwBytes != 0) && (hMem = GlobalAlloc(0x42,dwBytes), hMem != (HGLOBAL)0x0)) {
      pvVar5 = GlobalLock(hMem);
      FUN_10001170(pvVar5,dwBytes,(void *)(param_4->unused + 2),dwBytes);
      GlobalUnlock(hMem);
      CreateStreamOnHGlobal(hMem,1,&local_18);
    }
    local_24 = 0;
    local_8._0_1_ = 3;
    iVar4 = FUN_10005720((int *)local_18,&local_24);
    uVar1 = local_24;
    if (iVar4 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_18 != (IStream *)0x0) {
        (*local_18->lpVtbl->Release)(local_18);
      }
    }
    else {
      local_28 = 0;
      local_1c = (undefined4 *)0x0;
      local_8._0_1_ = 7;
      iVar4 = FUN_10015b30((int)local_2c,param_1,local_18,&local_1c,(undefined4 *)0x0,&DAT_1002006c,
                           0,local_24);
      if ((-1 < iVar4) &&
         (iVar4 = (**(code **)*local_1c)(local_1c,&DAT_1001f778,&local_30), -1 < iVar4)) {
        SetWindowLongW(param_1,-0x15,local_30);
        local_8._0_1_ = 5;
        FUN_100050c0((int *)&local_1c);
        local_8._0_1_ = 3;
        FUN_10004440(&local_28);
        local_8._0_1_ = 2;
        Ordinal_6(uVar1);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100050c0((int *)&local_18);
        local_8 = 0xffffffff;
        FUN_10006680((int *)&local_20);
        goto LAB_100162f4;
      }
      local_8._0_1_ = 5;
      FUN_100050c0((int *)&local_1c);
      local_8._0_1_ = 3;
      FUN_10004440(&local_28);
      local_8._0_1_ = 2;
      Ordinal_6(uVar1);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100050c0((int *)&local_18);
    }
    local_8 = 0xffffffff;
    FUN_10006680((int *)&local_20);
  }
  else {
    if (param_2 == 0x82) {
      piVar3 = (int *)GetWindowLongW(param_1,-0x15);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
      }
      OleUninitialize();
    }
    else if ((((param_2 == 0x210) && ((short)param_3 == 1)) && (param_4 != (HWND)0x0)) &&
            (uVar2 = GetWindowLongW(param_4,-0x14), (uVar2 & 0x10000) != 0)) {
      uVar2 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar2 | 0x10000);
    }
LAB_100162f4:
    DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
  }
LAB_10016307:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016330 at 10016330

BOOL FUN_10016330(void)

{
  ATOM AVar1;
  BOOL BVar2;
  tagWNDCLASSEXW local_4c;
  undefined *local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c718;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_1002a0e8;
  local_18 = 0;
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002a0e8);
  local_18 = 1;
  DAT_10029fe0 = RegisterWindowMessageW(L"WM_ATLGETHOST");
  DAT_10029fe4 = RegisterWindowMessageW(L"WM_ATLGETCONTROL");
  local_4c.cbSize = 0x30;
  BVar2 = GetClassInfoExW(DAT_1002a0b0,L"AtlAxWin100",&local_4c);
  if (BVar2 == 0) {
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = FUN_10015d90;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_1002a0b0;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWin100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14 = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_1000a310(&DAT_1002a104,(undefined2 *)&local_14);
      goto LAB_10016425;
    }
  }
  else {
LAB_10016425:
    memset(&local_4c,0,0x30);
    local_4c.cbSize = 0x30;
    BVar2 = GetClassInfoExW(DAT_1002a0b0,L"AtlAxWinLic100",&local_4c);
    if (BVar2 != 0) goto LAB_100164c0;
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = FUN_10016050;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_1002a0b0;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWinLic100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14 = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_1000a310(&DAT_1002a104,(undefined2 *)&local_14);
      BVar2 = 1;
      goto LAB_100164c0;
    }
  }
  BVar2 = 0;
LAB_100164c0:
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002a0e8);
  ExceptionList = local_10;
  return BVar2;
}



// Function: FUN_100164f0 at 100164f0

HWND __cdecl
FUN_100164f0(HMODULE param_1,LPCWSTR param_2,HWND param_3,DLGPROC param_4,LPARAM param_5)

{
  HRSRC hResInfo;
  HRSRC hResInfo_00;
  HGLOBAL pvVar1;
  LPCDLGTEMPLATEW pDVar2;
  LPCDLGTEMPLATEW lpTemplate;
  HWND local_c;
  DWORD local_8;
  
  FUN_10016330();
  local_c = (HWND)0x0;
  hResInfo = FindResourceW(param_1,param_2,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResInfo_00 = FindResourceW(param_1,param_2,(LPCWSTR)0xf0);
    if (hResInfo_00 != (HRSRC)0x0) {
      pvVar1 = LoadResource(param_1,hResInfo_00);
      LockResource(pvVar1);
    }
    local_8 = 0;
    pvVar1 = LoadResource(param_1,hResInfo);
    if ((pvVar1 == (HGLOBAL)0x0) ||
       (pDVar2 = (LPCDLGTEMPLATEW)LockResource(pvVar1), pDVar2 == (LPCDLGTEMPLATEW)0x0)) {
      local_8 = GetLastError();
    }
    else {
      lpTemplate = (LPCDLGTEMPLATEW)FUN_10003080((uint *)pDVar2);
      local_c = CreateDialogIndirectParamW(param_1,lpTemplate,param_3,param_4,param_5);
      if (local_c == (HWND)0x0) {
        local_8 = GetLastError();
      }
      if (lpTemplate != pDVar2) {
        pvVar1 = GlobalHandle(lpTemplate);
        GlobalFree(pvVar1);
      }
    }
    if (local_8 != 0) {
      SetLastError(local_8);
    }
    return local_c;
  }
  return (HWND)0x0;
}



// Function: FUN_100165d0 at 100165d0

undefined4 FUN_100165d0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c758;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = param_1;
  FUN_10016330();
  param_1 = (int *)0x0;
  local_8 = 1;
  FUN_100096e0(&local_14,&DAT_1001f788,&param_1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x24))(param_1,param_2,uVar1);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_10016660 at 10016660

int __fastcall FUN_10016660(void *param_1)

{
  void *lParam;
  int iVar1;
  HBRUSH pHVar2;
  void *local_8;
  
  local_8 = param_1;
  if (*(HGDIOBJ *)((int)param_1 + 0x70) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)((int)param_1 + 0x70));
    *(undefined4 *)((int)param_1 + 0x70) = 0;
  }
  iVar1 = FUN_10005f80(param_1,&local_8);
  lParam = local_8;
  if (-1 < iVar1) {
    Ordinal_421(local_8,0,&local_8);
    pHVar2 = CreateSolidBrush((COLORREF)local_8);
    *(HBRUSH *)((int)param_1 + 0x70) = pHVar2;
    EnumChildWindows(*(HWND *)((int)param_1 + 0x4c),FUN_100165d0,(LPARAM)lParam);
  }
  return iVar1;
}



// Function: FUN_100166d0 at 100166d0

void __thiscall FUN_100166d0(void *this,ushort param_1)

{
  uint uVar1;
  HWND hWnd;
  short sVar2;
  HRSRC pHVar3;
  HGLOBAL pvVar4;
  uint *puVar5;
  DWORD *pDVar6;
  DWORD *pDVar7;
  SIZE_T dwBytes;
  LPVOID pvVar8;
  DWORD DVar9;
  HWND hWndInsertAfter;
  uint *puVar10;
  DWORD DVar11;
  uint uVar12;
  HMENU pHVar13;
  ushort *local_48;
  DWORD *local_44;
  undefined4 local_3c;
  int local_38;
  HWND local_34;
  uint local_30;
  LPSTREAM local_2c;
  HWND local_28;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c7b0;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pHVar3 = FindResourceW(DAT_1002a0b4,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  local_48 = (ushort *)0x0;
  local_28 = (HWND)0x0;
  if ((pHVar3 != (HRSRC)0x0) && (pvVar4 = LoadResource(DAT_1002a0b4,pHVar3), pvVar4 != (HGLOBAL)0x0)
     ) {
    local_48 = (ushort *)LockResource(pvVar4);
  }
  pHVar3 = FindResourceW(DAT_1002a0b4,(LPCWSTR)(uint)param_1,(LPCWSTR)0x5);
  if (pHVar3 != (HRSRC)0x0) {
    pvVar4 = LoadResource(DAT_1002a0b4,pHVar3);
    if ((pvVar4 == (HGLOBAL)0x0) || (puVar5 = (uint *)LockResource(pvVar4), puVar5 == (uint *)0x0))
    {
      local_28 = (HWND)FUN_100014a0();
    }
    else {
      uVar12 = (uint)(*(short *)((int)puVar5 + 2) == -1);
      puVar10 = puVar5 + 4;
      if (*(short *)((int)puVar5 + 2) != -1) {
        puVar10 = puVar5 + 2;
      }
      uVar1 = *puVar10;
      local_30 = uVar12;
      pDVar6 = (DWORD *)FUN_10002f20(puVar5);
      local_34 = GetWindow(*(HWND *)((int)this + 4),5);
      local_38 = 0;
      if ((ushort)uVar1 != 0) {
        do {
          if (uVar12 == 0) {
            DVar11 = (DWORD)(ushort)pDVar6[4];
            pDVar7 = (DWORD *)((int)pDVar6 + 0x12);
          }
          else {
            DVar11 = pDVar6[5];
            pDVar7 = pDVar6 + 6;
          }
          if ((short)*pDVar7 == 0x7b) {
            local_28 = (HWND)0x0;
            dwBytes = FUN_10003030(DVar11,local_48,(int *)&local_28);
            local_2c = (IStream *)0x0;
            local_8 = 1;
            if (dwBytes != 0) {
              pvVar4 = GlobalAlloc(0x42,dwBytes);
              if (pvVar4 == (HGLOBAL)0x0) {
                local_28 = (HWND)0x8007000e;
                local_8 = 0xffffffff;
                if (local_2c != (IStream *)0x0) {
                  (*local_2c->lpVtbl->Release)(local_2c);
                }
                break;
              }
              pvVar8 = GlobalLock(pvVar4);
              if (pvVar8 == (LPVOID)0x0) {
                local_28 = (HWND)FUN_100014a0();
                local_8 = 0xffffffff;
                if (local_2c != (IStream *)0x0) {
                  (*local_2c->lpVtbl->Release)(local_2c);
                }
                break;
              }
              FUN_10001170(pvVar8,dwBytes,local_28,dwBytes);
              GlobalUnlock(pvVar4);
              CreateStreamOnHGlobal(pvVar4,1,&local_2c);
              uVar12 = local_30;
            }
            local_3c = 0;
            local_8 = CONCAT31(local_8._1_3_,4);
            local_28 = (HWND)FUN_10005720((int *)local_2c,&local_3c);
            if (-1 < (int)local_28) {
              local_28 = (HWND)0x0;
              FUN_10016330();
              if (uVar12 == 0) {
                local_44 = (DWORD *)((int)pDVar6 + 0x12);
                sVar2 = (short)pDVar6[2];
              }
              else {
                sVar2 = (short)pDVar6[3];
                local_44 = pDVar6 + 6;
              }
              local_24.left = (LONG)sVar2;
              if (uVar12 == 0) {
                sVar2 = *(short *)((int)pDVar6 + 10);
              }
              else {
                sVar2 = *(short *)((int)pDVar6 + 0xe);
              }
              local_24.top = (LONG)sVar2;
              if (uVar12 == 0) {
                sVar2 = (short)pDVar6[3];
              }
              else {
                sVar2 = (short)pDVar6[4];
              }
              local_24.right = sVar2 + local_24.left;
              if (uVar12 == 0) {
                sVar2 = *(short *)((int)pDVar6 + 0xe);
              }
              else {
                sVar2 = *(short *)((int)pDVar6 + 0x12);
              }
              local_24.bottom = sVar2 + local_24.top;
              MapDialogRect(*(HWND *)((int)this + 4),&local_24);
              if (uVar12 == 0) {
                pHVar13 = (HMENU)(uint)(ushort)pDVar6[4];
                DVar9 = *pDVar6;
                DVar11 = 0;
              }
              else {
                pHVar13 = (HMENU)pDVar6[5];
                DVar11 = pDVar6[1];
                DVar9 = pDVar6[2];
              }
              FUN_100056c0(&local_28,*(HWND *)((int)this + 4),&local_24.left,(LPCWSTR)0x0,
                           DVar9 | 0x10000,DVar11,pHVar13,(LPVOID)0x0);
              hWnd = local_28;
              if (local_28 == (HWND)0x0) {
                local_28 = (HWND)FUN_100014a0();
                uVar12 = local_30;
              }
              else {
                if ((local_30 != 0) && (*pDVar6 != 0)) {
                  SetWindowContextHelpId(local_28,*pDVar6);
                }
                local_28 = (HWND)FUN_10015c80(&local_28,(int)local_44,local_2c,(undefined4 *)0x0,
                                              (undefined4 *)0x0,&DAT_1002006c,0,local_3c);
                if ((int)local_28 < 0) {
                  local_8 = CONCAT31(local_8._1_3_,1);
                  Ordinal_6();
                  local_8 = 0xffffffff;
                  FUN_100050c0((int *)&local_2c);
                  break;
                }
                hWndInsertAfter = local_34;
                if ((short)local_38 == 0) {
                  hWndInsertAfter = (HWND)0x0;
                }
                SetWindowPos(hWnd,hWndInsertAfter,0,0,0,0,0x13);
                local_34 = hWnd;
                uVar12 = local_30;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_6();
            local_8 = 0xffffffff;
            if (local_2c != (IStream *)0x0) {
              (*local_2c->lpVtbl->Release)(local_2c);
            }
          }
          else if ((short)local_38 != 0) {
            local_34 = GetWindow(local_34,2);
          }
          pDVar6 = (DWORD *)FUN_10002fc0((int)pDVar6,uVar12);
          local_38 = local_38 + 1;
        } while ((ushort)local_38 < (ushort)uVar1);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016a90 at 10016a90

int __thiscall FUN_10016a90(void *this,HWND param_1)

{
  int iVar1;
  HWND pHVar2;
  int iVar3;
  
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -4;
  }
  FUN_10007de0(0x1002a0e4,(int *)(iVar1 + 0x54),iVar1 + 0x4c);
  *(undefined1 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  pHVar2 = FUN_100164f0(DAT_1002a0b4,(LPCWSTR)0x67,param_1,FUN_1000cb10,0);
  if ((*(int *)(iVar1 + 0x70) < 0) && (pHVar2 != (HWND)0x0)) {
    DestroyWindow(*(HWND *)(iVar1 + 0x50));
    SetLastError(*(DWORD *)(iVar1 + 0x70));
  }
  if (*(int *)(iVar1 + 0x50) != 0) {
    FUN_10016660((void *)(iVar1 + 4));
    ShowWindow(*(HWND *)(iVar1 + 0x50),4);
  }
  iVar1 = *(int *)(iVar1 + 0x50);
  if (iVar1 != 0) {
    if (this == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)this + -4;
    }
    FUN_100094d0(iVar3,'\x01');
  }
  return iVar1;
}



// Function: FUN_10016b50 at 10016b50

undefined4 FUN_10016b50(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_10029d40 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (3 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10016ba0 at 10016ba0

undefined4 FUN_10016ba0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xfc);
  return 0;
}



// Function: FUN_10016bd0 at 10016bd0

undefined4 FUN_10016bd0(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = *(undefined4 *)(param_1 + 0xf8);
  return 0;
}



// Function: FUN_10016c00 at 10016c00

undefined4 FUN_10016c00(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = *(byte *)(param_1 + 0x18c);
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0);
  return 0;
}



// Function: FUN_10016c30 at 10016c30

undefined4 FUN_10016c30(int param_1,short param_2)

{
  uint nCmdShow;
  HWND hWnd;
  
  *(bool *)(param_1 + 0x18c) = param_2 == -1;
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    nCmdShow = -(uint)(param_2 == -1) & 5;
    hWnd = GetDlgItem(*(HWND *)(param_1 + 0x50),0xcc);
    ShowWindow(hWnd,nCmdShow);
  }
  return 0;
}



// Function: FUN_10016c70 at 10016c70

undefined4 FUN_10016c70(int param_1,short *param_2)

{
  byte bVar1;
  
  if (param_2 == (short *)0x0) {
    return 0x80004003;
  }
  bVar1 = *(byte *)(param_1 + 0x18d);
  *param_2 = ((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0);
  return 0;
}



// Function: FUN_10016ca0 at 10016ca0

undefined4 FUN_10016ca0(int param_1,short param_2)

{
  uint nCmdShow;
  HWND hWnd;
  
  *(bool *)(param_1 + 0x18d) = param_2 == -1;
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    nCmdShow = -(uint)(param_2 == -1) & 5;
    hWnd = GetDlgItem(*(HWND *)(param_1 + 0x50),0xca);
    ShowWindow(hWnd,nCmdShow);
  }
  return 0;
}



// Function: FUN_10016ce0 at 10016ce0

void __fastcall FUN_10016ce0(undefined4 *param_1)

{
  if (0 < (int)param_1[1]) {
    free((void *)*param_1);
  }
  return;
}



// Function: FUN_10016d00 at 10016d00

void __cdecl FUN_10016d00(wchar_t *param_1,ushort param_2,uint *param_3,uint *param_4)

{
  HDC hdc;
  int nNumerator;
  HFONT h;
  uint uVar1;
  int nDenominator;
  tagSIZE local_b0;
  HGDIOBJ local_a8;
  uint *local_a4;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_a4 = param_4;
  if (param_1 != (wchar_t *)0x0) {
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      memset(&local_64,0,0x5c);
      nDenominator = 0x48;
      nNumerator = GetDeviceCaps(hdc,0x5a);
      local_64.lfHeight = MulDiv((uint)param_2,nNumerator,nDenominator);
      local_64.lfHeight = -local_64.lfHeight;
      local_64.lfWeight = 400;
      local_64.lfCharSet = '\x01';
      FUN_100012e0(local_64.lfFaceName,0x20,param_1,0xffffffff);
      h = CreateFontIndirectW(&local_64);
      if (h != (HFONT)0x0) {
        local_a8 = SelectObject(hdc,h);
        GetTextMetricsW(hdc,&local_a0);
        GetTextExtentPointW(hdc,L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",0x34,
                            &local_b0);
        SelectObject(hdc,local_a8);
        DeleteObject(h);
        *local_a4 = local_a0.tmHeight;
        param_3[1] = local_a0.tmExternalLeading + local_a0.tmHeight;
        *param_3 = (local_b0.cx + 0x1a) / 0x34;
        ReleaseDC((HWND)0x0,hdc);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      ReleaseDC((HWND)0x0,hdc);
    }
  }
  uVar1 = GetDialogBaseUnits();
  *param_3 = uVar1 & 0xffff;
  param_3[1] = uVar1 >> 0x10;
  *local_a4 = uVar1 >> 0x10;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016e70 at 10016e70

void __cdecl FUN_10016e70(int param_1)

{
  short sVar1;
  short *psVar2;
  
  if (*(short *)(param_1 + 2) == -1) {
    psVar2 = (short *)(param_1 + 0x1a);
  }
  else {
    psVar2 = (short *)(param_1 + 0x12);
  }
  if (*psVar2 == -1) {
    psVar2 = psVar2 + 2;
  }
  else {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  if (*psVar2 == -1) {
    psVar2 = psVar2 + 2;
  }
  else {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return;
}



// Function: FUN_10016ed0 at 10016ed0

void __fastcall FUN_10016ed0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c84b;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar3 = *(int **)(param_1 + 4);
  if (piVar3 < piVar3 + *(int *)(param_1 + 8)) {
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1,uVar2);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 < (int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8) * 4));
  }
  local_8 = 0xffffffff;
  if (0 < *(int *)(param_1 + 8)) {
    free(*(void **)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016f60 at 10016f60

void __fastcall FUN_10016f60(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_10016f80 at 10016f80

void __fastcall FUN_10016f80(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c878;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016ed0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016fd0 at 10016fd0

undefined4 __fastcall FUN_10016fd0(int param_1)

{
  HWND pHVar1;
  uint nCmdShow;
  
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x50),0xcd);
  *(HWND *)(param_1 + 0xe8) = pHVar1;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x50),0xca);
  *(HWND *)(param_1 + 0xec) = pHVar1;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x50),0xcb);
  *(HWND *)(param_1 + 0xf0) = pHVar1;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x50),0xcc);
  nCmdShow = -(uint)(*(char *)(param_1 + 0x18c) != '\0') & 5;
  *(HWND *)(param_1 + 0xf4) = pHVar1;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x50),0xcc);
  ShowWindow(pHVar1,nCmdShow);
  return 0;
}



// Function: FUN_10017050 at 10017050

void __thiscall FUN_10017050(void *this,undefined4 param_1,undefined4 param_2,ushort param_3)

{
  longlong lVar1;
  HDC hdc;
  HGDIOBJ h;
  HWND pHVar2;
  uint uVar3;
  int Y;
  undefined4 extraout_ECX;
  int nHeight;
  int X;
  undefined4 extraout_EDX;
  uint uVar4;
  int nWidth;
  ulonglong uVar5;
  tagRECT *lpRect;
  BOOL bRepaint;
  tagSIZE local_50;
  int local_48;
  uint local_44;
  LPWSTR local_40;
  HWND local_3c;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x50) != 0) {
    uVar4 = (uint)param_3;
    uVar3 = uVar4;
    local_44 = uVar4;
    if (*(char *)((int)this + 0x18c) != '\0') {
      local_3c = *(HWND *)((int)this + 0xf4);
      local_48 = GetWindowTextLengthW(local_3c);
      uVar3 = local_48 + 1;
      lVar1 = (ulonglong)uVar3 * 2;
      local_40 = (LPWSTR)FUN_100192db(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      GetWindowTextW(*(HWND *)((int)this + 0xf4),local_40,uVar3);
      hdc = GetDC(*(HWND *)((int)this + 0xf4));
      h = (HGDIOBJ)SendMessageW(local_3c,0x31,0,0);
      local_3c = (HWND)SelectObject(hdc,h);
      GetTextExtentPoint32W(hdc,local_40,local_48,&local_50);
      SelectObject(hdc,local_3c);
      pHVar2 = GetDlgItem(*(HWND *)((int)this + 0x50),0xcc);
      ReleaseDC(pHVar2,hdc);
      operator_delete__(local_40);
      uVar5 = FUN_100195f0(extraout_ECX,extraout_EDX);
      uVar3 = (uint)uVar5;
    }
    GetClientRect(*(HWND *)((int)this + 0xf4),&local_18);
    if (*(char *)((int)this + 0x18c) != '\0') {
      MoveWindow(*(HWND *)((int)this + 0xf4),uVar3,local_18.top,uVar4 - uVar3,local_18.bottom,0);
    }
    MoveWindow(*(HWND *)((int)this + 0xf0),0,local_18.top,uVar3 - 0x14,local_18.bottom * 2,0);
    GetClientRect(*(HWND *)((int)this + 0xec),&local_28);
    GetWindowRect(*(HWND *)((int)this + 0x50),&local_38);
    lpRect = &local_18;
    pHVar2 = GetDlgItem(*(HWND *)((int)this + 0x50),0xcd);
    GetWindowRect(pHVar2,lpRect);
    bRepaint = 0;
    nHeight = local_18.bottom - local_18.top;
    Y = local_18.top - local_38.top;
    nWidth = (uVar4 - local_28.right) + -5;
    X = local_28.right + 5;
    pHVar2 = GetDlgItem(*(HWND *)((int)this + 0x50),0xcd);
    MoveWindow(pHVar2,X,Y,nWidth,nHeight,bRepaint);
    SendMessageW(*(HWND *)((int)this + 0xf0),0xf,0,0);
    InvalidateRect(*(HWND *)((int)this + 0x50),(RECT *)0x0,1);
  }
  local_50.cx = 0x10017238;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017240 at 10017240

undefined4 FUN_10017240(int param_1,undefined4 *param_2)

{
  undefined4 local_c [2];
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x407,1,(LPARAM)local_c);
  *param_2 = local_c[0];
  return 0x80004005;
}



// Function: FUN_10017290 at 10017290

undefined4 FUN_10017290(int param_1,undefined2 param_2)

{
  undefined1 local_c [4];
  undefined2 local_8;
  
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x407,1,(LPARAM)local_c);
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x401,0,CONCAT22(local_8,param_2));
  return 0;
}



// Function: FUN_100172e0 at 100172e0

undefined4 FUN_100172e0(int param_1,undefined4 *param_2)

{
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x407,1,(LPARAM)local_c);
  *param_2 = local_8;
  return 0x80004005;
}



// Function: FUN_10017330 at 10017330

undefined4 FUN_10017330(int param_1,undefined2 param_2)

{
  undefined2 local_c [4];
  
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x407,1,(LPARAM)local_c);
  SendMessageW(*(HWND *)(param_1 + 0xe8),0x401,0,CONCAT22(param_2,local_c[0]));
  return 0;
}



// Function: FUN_10017380 at 10017380

uint __thiscall FUN_10017380(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_100173e8:
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
      goto LAB_100173e8;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10017410 at 10017410

int * __cdecl FUN_10017410(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c8b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2,DAT_10029f90 ^ (uint)&stack0xfffffffc,0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017490 at 10017490

undefined4 FUN_10017490(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c8e8;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  puVar1 = (undefined4 *)(param_1 + 0x100);
  if (7 < *(uint *)(param_1 + 0x114)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  ExceptionList = &local_10;
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = Ordinal_2(puVar1,DAT_10029f90 ^ (uint)&stack0xfffffffc);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x8007000e);
    }
  }
  local_8 = 0;
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Ordinal_149(iVar3);
    uVar2 = Ordinal_150(iVar3,uVar2);
  }
  *param_2 = uVar2;
  local_8 = 0xffffffff;
  Ordinal_6(iVar3);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10017550 at 10017550

/* WARNING: Type propagation algorithm not settling */

void FUN_10017550(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uStack_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40 [4];
  undefined4 local_30;
  int local_2c [6];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c930;
  local_10 = ExceptionList;
  uStack_60 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_48 = param_2;
  local_8 = 0;
  local_2c[1] = 0;
  local_2c[2] = 1;
  local_2c[3] = 2;
  local_2c[4] = 3;
  local_4c = 0;
  local_50 = 4;
  local_2c[5] = uStack_60;
  uVar1 = Ordinal_15(8,1,&local_50);
  piVar2 = FUN_10017410(local_2c,(undefined4 *)(param_1 + 0x11c));
  local_8._0_1_ = 1;
  local_40[0] = FUN_10016f60(piVar2);
  local_8._0_1_ = 0;
  Ordinal_6(local_2c[0]);
  piVar2 = FUN_10017410(local_2c,(undefined4 *)(param_1 + 0x138));
  local_8._0_1_ = 2;
  local_40[1] = FUN_10016f60(piVar2);
  local_8._0_1_ = 0;
  Ordinal_6(local_2c[0]);
  piVar2 = FUN_10017410(local_2c,(undefined4 *)(param_1 + 0x154));
  local_8._0_1_ = 3;
  local_40[2] = FUN_10016f60(piVar2);
  local_8._0_1_ = 0;
  Ordinal_6(local_2c[0]);
  piVar2 = FUN_10017410(local_2c,(undefined4 *)(param_1 + 0x170));
  local_8._0_1_ = 4;
  local_40[3] = FUN_10016f60(piVar2);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_2c[0]);
  local_30 = Ordinal_26(uVar1,local_2c + 1,local_40[0]);
  local_30 = Ordinal_26(uVar1,local_2c + 2,local_40[1]);
  local_30 = Ordinal_26(uVar1,local_2c + 3,local_40[2]);
  local_30 = Ordinal_26(uVar1,local_2c + 4,local_40[3]);
  local_30 = Ordinal_27(uVar1,local_48);
  for (iVar3 = 0; local_44 = iVar3, iVar3 < 4; iVar3 = iVar3 + 1) {
    Ordinal_6(local_40[iVar3]);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_2c[5] ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100176f8 at 100176f8

undefined4 Catch_100176f8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x2c) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100176d7;
}



// Function: FUN_10017730 at 10017730

void * __thiscall FUN_10017730(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c9da;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  local_8 = 0xc;
  memset(this,0,0x48);
  *(undefined4 *)((int)this + 0x3c) = param_1;
  *(undefined4 *)((int)this + 0x24) = 0x13d8;
  *(undefined4 *)((int)this + 0x28) = 0x13d8;
  *(undefined4 *)((int)this + 0x1c) = 0x13d8;
  *(undefined4 *)((int)this + 0x20) = 0x13d8;
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10017810 at 10017810

void __fastcall FUN_10017810(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ca7a;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 5;
  if (**(int **)(param_1 + 0x3c) != 0) {
    DestroyWindow((HWND)**(int **)(param_1 + 0x3c));
  }
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8._0_1_ = 3;
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 2;
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017910 at 10017910

int * __thiscall FUN_10017910(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
      FUN_100092a0(this,uVar1);
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



// Function: FUN_10017a20 at 10017a20

void * FUN_10017a20(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 1) * 2;
  pvVar1 = memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}



// Function: FUN_10017a50 at 10017a50

int * __thiscall FUN_10017a50(void *this,uint param_1,int *param_2,uint param_3,uint param_4)

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
        FUN_100092a0(this,uVar6);
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
      FUN_100047b0((void *)((int)pvVar3 + (param_1 + param_4) * 2),
                   (void *)((int)pvVar4 + param_1 * 2),*(int *)((int)this + 0x10) - param_1);
      if ((int *)this == param_2) {
        uVar2 = param_3 + param_4;
        if (param_3 <= param_1) {
          uVar2 = param_3;
        }
        if (*(uint *)((int)this + 0x14) < 8) {
          FUN_100047b0((void *)((int)this + param_1 * 2),(void *)((int)this + uVar2 * 2),param_4);
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          FUN_100047b0((void *)(*this + param_1 * 2),(void *)(*this + uVar2 * 2),param_4);
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
      FUN_10005940(this,uVar6);
    }
    return (int *)this;
  }
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  piVar5 = (int *)(*pcVar1)();
  return piVar5;
}



// Function: FUN_10017bd0 at 10017bd0

void __cdecl FUN_10017bd0(uint *param_1,wchar_t *param_2,undefined2 *param_3)

{
  LPCWSTR lpString;
  wchar_t wVar1;
  rsize_t _DstSize;
  uint uVar2;
  undefined2 *puVar3;
  wchar_t *pwVar4;
  int iVar5;
  errno_t eVar6;
  wchar_t *local_118;
  wchar_t local_114 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001caab;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == (uint *)0x0) {
switchD_10017d66_caseD_1:
                    /* WARNING: Subroutine does not return */
    FUN_10001150(0x80004005);
  }
  if (*(short *)((int)param_1 + 2) == -1) {
    uVar2 = param_1[3];
  }
  else {
    uVar2 = *param_1;
  }
  if ((uVar2 & 0x40) != 0) {
    if (param_2 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x80004005);
    }
    if (param_3 == (undefined2 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001150(0x80004005);
    }
    puVar3 = (undefined2 *)FUN_10016e70((int)param_1);
    *param_3 = *puVar3;
    local_118 = local_114;
    lpString = puVar3 + (uint)(*(short *)((int)param_1 + 2) == -1) * 2 + 1;
    if (lpString != (LPCWSTR)0x0) {
      iVar5 = lstrlenW(lpString);
      FUN_10004710((int *)&local_118,iVar5 + 1U,local_114,0x80);
      _DstSize = (iVar5 + 1U) * 2;
      eVar6 = memcpy_s(local_118,_DstSize,lpString,_DstSize);
      switch(eVar6) {
      case 0:
      case 0x50:
        goto switchD_10017d66_caseD_0;
      default:
        goto switchD_10017d66_caseD_1;
      case 0xc:
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x8007000e);
      case 0x16:
      case 0x22:
                    /* WARNING: Subroutine does not return */
        FUN_10001150(0x80070057);
      }
    }
    local_118 = (wchar_t *)0x0;
switchD_10017d66_caseD_0:
    local_8 = 0;
    FUN_100012e0(param_2,0x20,local_118,0xffffffff);
    pwVar4 = param_2;
    do {
      wVar1 = *pwVar4;
      pwVar4 = pwVar4 + 1;
    } while (wVar1 != L'\0');
    if (0x1f < (uint)((int)pwVar4 - (int)(param_2 + 1) >> 1)) {
      param_2[0x1f] = L'\0';
    }
    local_8 = 0xffffffff;
    if (local_118 != local_114) {
      free(local_118);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017df0 at 10017df0

void __thiscall FUN_10017df0(void *this,char *param_1)

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
  puStack_c = &LAB_1001cae0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar3 = param_1;
  if ((char *)0x7fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
    pcVar3 = extraout_EAX;
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)(*(int *)((int)this + 8) - *this >> 1) < pcVar3) {
    pvVar4 = FUN_100038d0(pcVar3);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_10017a20(*this,*(int *)((int)this + 4),pvVar4);
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    *(void **)((int)this + 8) = (void *)((int)pvVar4 + (int)param_1 * 2);
    *(void **)((int)this + 4) = (void *)((int)pvVar4 + (iVar2 - (int)pvVar1 >> 1) * 2);
    *(void **)this = pvVar4;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@10017ea5 at 10017ea5

void Catch_10017ea5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10017ec0 at 10017ec0

void __cdecl FUN_10017ec0(wchar_t *param_1,ushort param_2,int *param_3,char param_4)

{
  HMODULE hModule;
  HRSRC hResInfo;
  uint *puVar1;
  int iVar2;
  code *pcVar3;
  uint local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  FUN_10016d00(param_1,param_2,&local_54,&local_58);
  if (param_4 != '\0') {
    hModule = LoadLibraryW(L"COMCTL32.DLL");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
      if (hResInfo != (HRSRC)0x0) {
        puVar1 = (uint *)LoadResource(hModule,hResInfo);
        if (puVar1 != (uint *)0x0) {
          iVar2 = FUN_10017bd0(puVar1,local_48,(undefined2 *)&local_4c);
          FreeLibrary(hModule);
          if (iVar2 != 0) {
            FUN_10016d00(local_48,(ushort)local_4c,&local_60,&local_4c);
            pcVar3 = MulDiv_exref;
            iVar2 = MulDiv(*param_3,local_54,4);
            *param_3 = iVar2;
            iVar2 = MulDiv(param_3[1],local_5c,8);
            param_3[1] = iVar2;
            goto LAB_10017fa8;
          }
        }
      }
    }
  }
  pcVar3 = MulDiv_exref;
  iVar2 = MulDiv(*param_3,local_54,4);
  *param_3 = iVar2;
  iVar2 = param_3[1];
  local_4c = 8;
  local_58 = local_50;
LAB_10017fa8:
  iVar2 = (*pcVar3)(iVar2,local_58,local_4c);
  param_3[1] = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017fc0 at 10017fc0

void __fastcall FUN_10017fc0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10017ff0 at 10017ff0

void __fastcall FUN_10017ff0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cb39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(void **)(param_1 + 0x5c) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x5c));
  }
  local_8 = 0xffffffff;
  FUN_10017810(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018060 at 10018060

void __thiscall FUN_10018060(void *this,int param_1)

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
  uVar2 = *(int *)((int)this + 4) - iVar1 >> 1;
  if (0x7fffffffU - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
    param_1 = extraout_EDX;
  }
  pcVar3 = (char *)(uVar2 + param_1);
  pcVar4 = (char *)(*(int *)((int)this + 8) - iVar1 >> 1);
  if (pcVar4 < pcVar3) {
    if ((char *)(0x7fffffff - ((uint)pcVar4 >> 1)) < pcVar4) {
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = pcVar4 + ((uint)pcVar4 >> 1);
    }
    if (pcVar4 < pcVar3) {
      pcVar4 = pcVar3;
    }
    FUN_10017df0(this,pcVar4);
  }
  return;
}



// Function: FUN_100180c0 at 100180c0

undefined4 * __fastcall FUN_100180c0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cba1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10017730(param_1,param_1 + 0x13);
  param_1[0x13] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  param_1[0x1b] = 0;
  *param_1 = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  param_1[0x12] = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018160 at 10018160

void __thiscall FUN_10018160(void *this,byte param_1)

{
  FUN_10018290((void *)((int)this + -0x48),param_1);
  return;
}



// Function: FUN_10018170 at 10018170

void __fastcall FUN_10018170(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cc01;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  param_1[0x12] = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  local_8 = 0;
  DeleteObject((HGDIOBJ)param_1[0x1c]);
  local_8 = 1;
  if ((void *)param_1[0x17] != (void *)0x0) {
    FreeStdCallThunk((void *)param_1[0x17]);
  }
  local_8 = 0xffffffff;
  FUN_10017810((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018200 at 10018200

void __cdecl FUN_10018200(uint *param_1,int *param_2,char param_3)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  if (*(short *)((int)param_1 + 2) == -1) {
    *param_2 = (int)*(short *)((int)param_1 + 0x16);
    sVar1 = (short)param_1[6];
  }
  else {
    *param_2 = (int)*(short *)((int)param_1 + 0xe);
    sVar1 = (short)param_1[4];
  }
  param_2[1] = (int)sVar1;
  iVar2 = FUN_10017bd0(param_1,local_48,(undefined2 *)&local_4c);
  if (iVar2 == 0) {
    uVar4 = 0;
    pwVar3 = (wchar_t *)0x0;
  }
  else {
    pwVar3 = local_48;
    uVar4 = local_4c;
  }
  FUN_10017ec0(pwVar3,(ushort)uVar4,param_2,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018290 at 10018290

undefined4 * __thiscall FUN_10018290(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cc61;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  *(undefined ***)((int)this + 0x48) = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  local_8 = 0;
  DeleteObject(*(HGDIOBJ *)((int)this + 0x70));
  local_8 = 1;
  if (*(void **)((int)this + 0x5c) != (void *)0x0) {
    FreeStdCallThunk(*(void **)((int)this + 0x5c));
  }
  local_8 = 0xffffffff;
  FUN_10017810((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10018340 at 10018340

undefined4 * __thiscall FUN_10018340(void *this,undefined4 *param_1)

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



// Function: FUN_100183c0 at 100183c0

void __thiscall FUN_100183c0(void *this,uint param_1)

{
  void *_Dst;
  void *_Src;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  _Src = *(void **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  uVar1 = (int)_Src - *this >> 1;
  if (param_1 < uVar1) {
    _Dst = (void *)(*this + param_1 * 2);
    if (_Dst != _Src) {
      memmove(_Dst,_Src,0);
      *(void **)((int)this + 4) = _Dst;
      return;
    }
  }
  else if (uVar1 < param_1) {
    FUN_10018060(this,param_1 - uVar1);
                    /* WARNING: Load size is inaccurate */
    uVar1 = param_1 - ((int)*(undefined4 **)((int)this + 4) - *this >> 1);
    if (uVar1 != 0) {
      puVar3 = *(undefined4 **)((int)this + 4);
      for (uVar2 = uVar1 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (uVar1 = (uint)((uVar1 & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
        *(undefined2 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 2);
      }
    }
                    /* WARNING: Load size is inaccurate */
    *(uint *)((int)this + 4) =
         *(int *)((int)this + 4) + (param_1 - (*(int *)((int)this + 4) - *this >> 1)) * 2;
  }
  return;
}



// Function: FUN_10018450 at 10018450

undefined2 * __cdecl FUN_10018450(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc99;
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
  FUN_1000e470(param_1,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018500 at 10018500

void __fastcall FUN_10018500(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001cd5e;
  local_10 = ExceptionList;
  uVar2 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 3;
  _eh_vector_destructor_iterator_((void *)(param_1 + 0x11c),0x1c,4,FUN_10008050);
  local_8._0_1_ = 2;
  if (7 < *(uint *)(param_1 + 0x114)) {
    operator_delete(*(void **)(param_1 + 0x100));
  }
  *(undefined4 *)(param_1 + 0x114) = 7;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined2 *)(param_1 + 0x100) = 0;
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0xe0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10016ed0(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 4) = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  *(undefined ***)(param_1 + 0x4c) = ATL::CComCompositeControl<class_CProgressCtrl>::vftable;
  local_8 = 7;
  DeleteObject(*(HGDIOBJ *)(param_1 + 0x74));
  local_8 = 8;
  if (*(void **)(param_1 + 0x60) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x60));
  }
  local_8 = 0xffffffff;
  FUN_10017810(param_1 + 4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018630 at 10018630

void FUN_10018630(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  ushort ***pppuVar3;
  uint uVar4;
  LPCWSTR lpString;
  ushort **local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd88;
  local_10 = ExceptionList;
  local_14 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (ushort **)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_1000e470(local_30,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  lpString = (LPCWSTR)(param_1 + 0x100);
  pppuVar3 = (ushort ***)local_30[0];
  if (local_1c < 8) {
    pppuVar3 = local_30;
  }
  uVar4 = FUN_10017380(lpString,0,*(uint *)(param_1 + 0x110),(ushort *)pppuVar3,local_20);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (ushort **)((uint)local_30[0] & 0xffff0000);
  if (uVar4 != 0) {
    piVar2 = param_2;
    do {
      iVar1 = *piVar2;
      piVar2 = (int *)((int)piVar2 + 2);
    } while ((short)iVar1 != 0);
    FUN_1000e470(lpString,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
    if (*(HWND *)(param_1 + 0xf0) != (HWND)0x0) {
      if (7 < *(uint *)(param_1 + 0x114)) {
        lpString = *(LPCWSTR *)lpString;
      }
      SetWindowTextW(*(HWND *)(param_1 + 0xf0),lpString);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018760 at 10018760

undefined2 * __cdecl FUN_10018760(undefined2 *param_1,int *param_2,void *param_3)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cdc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = FUN_10017a50(param_3,0,param_2,0,0xffffffff);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_10018340(param_1,piVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100187e0 at 100187e0

undefined2 * __cdecl FUN_100187e0(undefined2 *param_1,void *param_2,undefined4 *param_3)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cdc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = FUN_10017910(param_2,param_3,0,0xffffffff);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_10018340(param_1,piVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018860 at 10018860

int __fastcall FUN_10018860(int param_1)

{
  int *piVar1;
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  FUN_100180c0((undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  local_8._1_3_ = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x114) = 7;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined2 *)(param_1 + 0x100) = 0;
  local_8._0_1_ = 6;
  _eh_vector_constructor_iterator_
            ((void *)(param_1 + 0x11c),0x1c,4,(_func_void_void_ptr *)&LAB_10017710,FUN_10008050);
  local_8 = CONCAT31(local_8._1_3_,7);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x40;
  *(undefined2 *)(param_1 + 0x18c) = 0x101;
  hModule = DAT_1002a0b4;
  hResInfo = FindResourceW(DAT_1002a0b4,(LPCWSTR)0x67,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResData = LoadResource(hModule,hResInfo);
    if (hResData != (HGLOBAL)0x0) {
      puVar2 = (uint *)LockResource(hResData);
      if (puVar2 != (uint *)0x0) {
        piVar1 = (int *)(param_1 + 0x28);
        FUN_10018200(puVar2,piVar1,'\0');
        FUN_1000eac0(piVar1,piVar1);
      }
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018990 at 10018990

undefined4 FUN_10018990(int param_1,WPARAM param_2)

{
  wchar_t *lpString;
  uint uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  wchar_t *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce88;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(WPARAM *)(param_1 + 0xfc) != param_2) {
    *(WPARAM *)(param_1 + 0xfc) = param_2;
    SendMessageW(*(HWND *)(param_1 + 0xe8),0x402,param_2,0);
    if ((*(char *)(param_1 + 0x18d) != '\0') && (*(int *)(param_1 + 0xec) != 0)) {
      local_28 = (wchar_t *)0x0;
      local_24 = 0;
      local_20 = 0;
      FUN_100183c0(&local_28,0x10);
      local_8 = 0;
      SendMessageW(*(HWND *)(param_1 + 0xe8),0x407,1,(LPARAM)local_18);
      uVar2 = FUN_100195f0(extraout_ECX,extraout_EDX);
      lpString = local_28;
      _swprintf(local_28,L"%d %%",(int)uVar2,uVar1);
      SetWindowTextW(*(HWND *)(param_1 + 0xec),lpString);
      local_8 = 0xffffffff;
      if (lpString != (wchar_t *)0x0) {
        operator_delete(lpString);
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10018a90 at 10018a90

void FUN_10018a90(int param_1,undefined4 param_2)

{
  LPCWSTR pWVar1;
  wchar_t wVar2;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  int iVar6;
  wchar_t *pwVar7;
  LPCWSTR pWVar8;
  wchar_t *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  wchar_t *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cec0;
  local_10 = ExceptionList;
  uVar3 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0xf8) = param_2;
  local_34 = (wchar_t *)0x0;
  local_30 = 0;
  local_2c = 0;
  local_14 = uVar3;
  FUN_100183c0(&local_34,0x400);
  local_8 = 0;
  iVar4 = *(int *)(param_1 + 0xf8) / 0x3c;
  iVar6 = *(int *)(param_1 + 0xf8) % 0x3c;
  if (0 < iVar4) {
    if (iVar4 == 1) {
      pwVar5 = (wchar_t *)(param_1 + 0x154);
      if (7 < *(uint *)(param_1 + 0x168)) {
        pwVar5 = *(wchar_t **)pwVar5;
      }
      iVar4 = 1;
    }
    else {
      pwVar5 = (wchar_t *)(param_1 + 0x170);
      if (7 < *(uint *)(param_1 + 0x184)) {
        pwVar5 = *(wchar_t **)pwVar5;
      }
    }
    _swprintf(local_34,pwVar5,iVar4,uVar3);
  }
  local_44 = (wchar_t *)0x0;
  local_40 = 0;
  local_3c = 0;
  FUN_100183c0(&local_44,0x80);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar6 == 1) {
    pwVar5 = (wchar_t *)(param_1 + 0x11c);
    if (7 < *(uint *)(param_1 + 0x130)) {
      pwVar5 = *(wchar_t **)pwVar5;
    }
    iVar6 = 1;
  }
  else {
    pwVar5 = (wchar_t *)(param_1 + 0x138);
    if (7 < *(uint *)(param_1 + 0x14c)) {
      pwVar5 = *(wchar_t **)pwVar5;
    }
  }
  _swprintf(local_44,pwVar5,iVar6,uVar3);
  pwVar5 = local_44;
  do {
    wVar2 = *pwVar5;
    pwVar5 = pwVar5 + 1;
  } while (wVar2 != L'\0');
  pWVar8 = local_34 + -1;
  do {
    pWVar1 = pWVar8 + 1;
    pWVar8 = pWVar8 + 1;
  } while (*pWVar1 != L'\0');
  pwVar7 = local_44;
  for (uVar3 = (uint)((int)pwVar5 - (int)local_44) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pWVar8 = *(undefined4 *)pwVar7;
    pwVar7 = pwVar7 + 2;
    pWVar8 = pWVar8 + 2;
  }
  for (uVar3 = (int)pwVar5 - (int)local_44 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)pWVar8 = (char)*pwVar7;
    pwVar7 = (wchar_t *)((int)pwVar7 + 1);
    pWVar8 = (LPCWSTR)((int)pWVar8 + 1);
  }
  if ((*(char *)(param_1 + 0x18c) != '\0') && (*(HWND *)(param_1 + 0xf4) != (HWND)0x0)) {
    SetWindowTextW(*(HWND *)(param_1 + 0xf4),local_34);
    GetClientRect(*(HWND *)(param_1 + 0x50),&local_24);
    SendMessageW(*(HWND *)(param_1 + 0x50),5,0,local_24.right);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_44 != (wchar_t *)0x0) {
    operator_delete(local_44);
  }
  local_44 = (wchar_t *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_8 = 0xffffffff;
  if (local_34 != (LPCWSTR)0x0) {
    operator_delete(local_34);
  }
  local_34 = (wchar_t *)0x0;
  local_30 = 0;
  local_2c = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018c60 at 10018c60

/* WARNING: Type propagation algorithm not settling */

void FUN_10018c60(int param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uStack_dc;
  int *local_c8 [4];
  undefined4 local_b8;
  undefined4 local_b4 [7];
  undefined4 local_98 [7];
  int local_7c [7];
  undefined4 local_60 [7];
  undefined4 local_44 [7];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001cf59;
  local_10 = ExceptionList;
  uStack_dc = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_dc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_dc;
  FUN_100156d0(local_7c,(int *)&DAT_1001ffac);
  local_8._0_1_ = 1;
  FUN_100156d0(local_98,(int *)&DAT_1001ffa8);
  local_8._0_1_ = 2;
  local_28 = 0;
  local_24 = 1;
  local_20 = 2;
  local_1c = 3;
  local_b8 = Ordinal_25(*param_2,&local_28,local_c8);
  local_b8 = Ordinal_25(*param_2,&local_24,local_c8 + 1);
  local_b8 = Ordinal_25(*param_2,&local_20,local_c8 + 2);
  local_b8 = Ordinal_25(*param_2,&local_1c,local_c8 + 3);
  puVar1 = FUN_10018450((undefined2 *)local_44,local_c8[0]);
  local_8._0_1_ = 3;
  puVar2 = (undefined4 *)FUN_10018760((undefined2 *)local_60,local_7c,puVar1);
  local_8._0_1_ = 4;
  FUN_10018340((void *)(param_1 + 0x11c),puVar2);
  local_8._0_1_ = 3;
  FUN_10008050(local_60);
  local_8._0_1_ = 2;
  FUN_10008050(local_44);
  puVar1 = FUN_10018450((undefined2 *)local_60,local_c8[1]);
  local_8._0_1_ = 5;
  puVar2 = (undefined4 *)FUN_10018760((undefined2 *)local_44,local_7c,puVar1);
  local_8._0_1_ = 6;
  FUN_10018340((void *)(param_1 + 0x138),puVar2);
  local_8._0_1_ = 5;
  FUN_10008050(local_44);
  local_8._0_1_ = 2;
  FUN_10008050(local_60);
  puVar1 = FUN_10018450((undefined2 *)local_b4,local_c8[2]);
  local_8._0_1_ = 7;
  puVar1 = FUN_10018760((undefined2 *)local_60,local_7c,puVar1);
  local_8._0_1_ = 8;
  puVar2 = (undefined4 *)FUN_100187e0((undefined2 *)local_44,puVar1,local_98);
  local_8._0_1_ = 9;
  FUN_10018340((void *)(param_1 + 0x154),puVar2);
  local_8._0_1_ = 8;
  FUN_10008050(local_44);
  local_8._0_1_ = 7;
  FUN_10008050(local_60);
  local_8._0_1_ = 2;
  FUN_10008050(local_b4);
  puVar1 = FUN_10018450((undefined2 *)local_60,local_c8[3]);
  local_8._0_1_ = 10;
  puVar1 = FUN_10018760((undefined2 *)local_44,local_7c,puVar1);
  local_8._0_1_ = 0xb;
  puVar2 = (undefined4 *)FUN_100187e0((undefined2 *)local_b4,puVar1,local_98);
  local_8._0_1_ = 0xc;
  FUN_10018340((void *)(param_1 + 0x170),puVar2);
  local_8._0_1_ = 0xb;
  FUN_10008050(local_b4);
  local_8._0_1_ = 10;
  FUN_10008050(local_44);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10008050(local_60);
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    Ordinal_6(local_c8[iVar3]);
  }
  local_8._0_1_ = 1;
  FUN_10008050(local_98);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10008050(local_7c);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10018f25 at 10018f25

undefined4 Catch_10018f25(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0xb4) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10018f01;
}



// Function: FUN_10018f40 at 10018f40

undefined4 FUN_10018f40(int param_1,int param_2)

{
  if (param_2 == -0x2bd) {
    FUN_10016660((void *)(param_1 + -0x7c));
    FUN_1000a2b0(param_1 + -0x7c);
  }
  return 0;
}



// Function: FUN_10018f67 at 10018f67

void __fastcall FUN_10018f67(int *param_1)

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



// Function: FUN_10018fab at 10018fab

int __fastcall FUN_10018fab(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10018fc4 at 10018fc4

undefined4 * __fastcall FUN_10018fc4(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10018fab((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_100267f8;
  param_1[3] = &DAT_100267f8;
  uVar1 = FUN_10001450((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_10029fb8 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 10019005

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_1002a0a8 == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_1002a0a8,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 10019031

/* Library Function - Single Match
    int __cdecl __InitializeThunkPool(void)
   
   Library: Visual Studio 2010 Release */

int __cdecl __InitializeThunkPool(void)

{
  BOOL BVar1;
  HANDLE pvVar2;
  undefined4 *lpMem;
  LONG LVar3;
  DWORD *Destination;
  DWORD DVar4;
  SIZE_T dwBytes;
  
  BVar1 = IsProcessorFeaturePresent(0xc);
  if (BVar1 == 0) {
    DAT_1002a0a8 = 1;
    return 1;
  }
  Destination = (DWORD *)((int)ProcessEnvironmentBlock + 0x34);
  DVar4 = *Destination;
  if (DVar4 == 0) {
    dwBytes = 8;
    pvVar2 = GetProcessHeap();
    lpMem = (undefined4 *)HeapAlloc(pvVar2,DVar4,dwBytes);
    if (lpMem == (undefined4 *)0x0) {
      return 0;
    }
    *lpMem = 0;
    lpMem[1] = 0;
    LVar3 = InterlockedCompareExchange((LONG *)Destination,(LONG)lpMem,0);
    if (LVar3 != 0) {
      DVar4 = 0;
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,DVar4,lpMem);
    }
    DVar4 = *Destination;
  }
  DAT_1002a0a8 = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 1001909f

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 100190b1

/* Library Function - Single Match
    void * __cdecl __AllocStdCallThunk_cmn(void)
   
   Library: Visual Studio 2010 Release */

void * __cdecl __AllocStdCallThunk_cmn(void)

{
  int iVar1;
  HANDLE hHeap;
  LPVOID pvVar2;
  PSINGLE_LIST_ENTRY p_Var3;
  PSINGLE_LIST_ENTRY p_Var4;
  DWORD dwFlags;
  SIZE_T dwBytes;
  
  if ((DAT_1002a0a8 != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_1002a0a8 == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_1002a0a8);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_1002a0a8);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_1002a0a8,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: FUN_10019154 at 10019154

int __fastcall FUN_10019154(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10019179 at 10019179

void __fastcall FUN_10019179(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10019191 at 10019191

undefined4 * __fastcall FUN_10019191(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10019154((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_100200dc;
  uVar1 = FUN_10001450((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_10029fb8 = 1;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 100191d1

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
    uVar1 = FUN_10001450((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar1;
}



// Function: RemoveAll at 100191f9

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



// Function: FUN_10019218 at 10019218

int __fastcall FUN_10019218(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 1001923d

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_1001924a:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_1001924a;
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



// Function: FUN_100192b3 at 100192b3

_ATL_WIN_MODULE70 * __fastcall FUN_100192b3(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_10019218((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_10029fb8 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_100192db at 100192db

void FUN_100192db(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 100192f2

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10029f90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 10019301

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



// Function: __alloca_probe at 10019370

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



// Function: __alloca_probe_16 at 100193e0

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



// Function: __alloca_probe_8 at 100193f6

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



// Function: `eh_vector_constructor_iterator' at 1001940c

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
  FUN_10019459();
  return;
}



// Function: FUN_10019459 at 10019459

void FUN_10019459(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 10019471

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



// Function: `eh_vector_destructor_iterator' at 100194cf

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
  FUN_1001951a();
  return;
}



// Function: FUN_1001951a at 1001951a

void FUN_1001951a(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 10019538

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
  
  local_8 = &DAT_10026790;
  uStack_c = 0x10019544;
  local_20[0] = DecodePointer(DAT_1002a458);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1002a458);
    local_24 = DecodePointer(DAT_1002a454);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1002a458 = EncodePointer(local_20[0]);
    DAT_1002a454 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100195d0();
  }
  return p_Var1;
}



// Function: FUN_100195d0 at 100195d0

void FUN_100195d0(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 100195d9

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_100195f0 at 100195f0

ulonglong __fastcall FUN_100195f0(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  if (DAT_1002a44c == 0) {
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



// Function: __CRT_INIT@12 at 100196e9

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
    if (DAT_1002a110 < 1) {
      return 0;
    }
    DAT_1002a110 = DAT_1002a110 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002a448,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002a444 == 2) {
      param_2 = (int *)DecodePointer(DAT_1002a458);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1002a454);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1002a458);
            piVar8 = (int *)DecodePointer(DAT_1002a454);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1002a454 = (PVOID)encoded_null();
        DAT_1002a458 = DAT_1002a454;
      }
      DAT_1002a444 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1002a448,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002a448,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002a444 == 0) {
      DAT_1002a444 = 1;
      iVar5 = initterm_e(&DAT_1001e468,&DAT_1001e474);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001e3e0,&DAT_1001e464);
      DAT_1002a444 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1002a448,0);
    }
    if ((DAT_1002a450 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1002a450), BVar2 != 0)) {
      (*DAT_1002a450)(param_1,2,param_3);
    }
    DAT_1002a110 = DAT_1002a110 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100198f3

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10019993) */
/* WARNING: Removing unreachable block (ram,0x10019940) */
/* WARNING: Removing unreachable block (ram,0x100199c0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10029fb0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002a110 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10007320(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10007320(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100199fe();
  return local_20;
}



// Function: FUN_100199fe at 100199fe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100199fe(void)

{
  _DAT_10029fb0 = 0xffffffff;
  return;
}



// Function: entry at 10019a09

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10019a2c

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
  
  _DAT_1002a230 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1002a234 = &stack0x00000004;
  _DAT_1002a170 = 0x10001;
  _DAT_1002a118 = 0xc0000409;
  _DAT_1002a11c = 1;
  local_32c = DAT_10029f90;
  local_328 = DAT_10029f94;
  _DAT_1002a124 = unaff_retaddr;
  _DAT_1002a1fc = in_GS;
  _DAT_1002a200 = in_FS;
  _DAT_1002a204 = in_ES;
  _DAT_1002a208 = in_DS;
  _DAT_1002a20c = unaff_EDI;
  _DAT_1002a210 = unaff_ESI;
  _DAT_1002a214 = unaff_EBX;
  _DAT_1002a218 = in_EDX;
  _DAT_1002a21c = in_ECX;
  _DAT_1002a220 = in_EAX;
  _DAT_1002a224 = unaff_EBP;
  DAT_1002a228 = unaff_retaddr;
  _DAT_1002a22c = in_CS;
  _DAT_1002a238 = in_SS;
  DAT_1002a168 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_100200f8);
  if (DAT_1002a168 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10019b40

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10029f90 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10019b85

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



// Function: __ValidateImageBase at 10019c20

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



// Function: __FindPESection at 10019c60

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



// Function: __IsNonwritableInCurrentImage at 10019cb0

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
  
  puStack_10 = &LAB_100193b4;
  local_14 = ExceptionList;
  local_c = DAT_10029f90 ^ 0x100267d8;
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



// Function: ___security_init_cookie at 10019d84

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
  if ((DAT_10029f90 == 0xbb40e64e) || ((DAT_10029f90 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10029f90 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10029f90 == 0xbb40e64e) {
      DAT_10029f90 = 0xbb40e64f;
    }
    else if ((DAT_10029f90 & 0xffff0000) == 0) {
      DAT_10029f90 = DAT_10029f90 | (DAT_10029f90 | 0x4711) << 0x10;
    }
    DAT_10029f94 = ~DAT_10029f90;
  }
  else {
    DAT_10029f94 = ~DAT_10029f90;
  }
  return;
}



// Function: Unwind@10019e40 at 10019e40

void Unwind_10019e40(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e70 at 10019e70

void Unwind_10019e70(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ea0 at 10019ea0

void Unwind_10019ea0(void)

{
  DAT_1002a010 = DAT_1002a010 & 0xfffffffe;
  return;
}



// Function: Unwind@10019ed0 at 10019ed0

void Unwind_10019ed0(void)

{
  int unaff_EBP;
  
  FUN_100014e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f00 at 10019f00

void Unwind_10019f00(void)

{
  int unaff_EBP;
  
  FUN_10018500(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f50 at 10019f50

void Unwind_10019f50(void)

{
  DAT_1002a01c = DAT_1002a01c & 0xfffffffe;
  return;
}



// Function: Unwind@10019f90 at 10019f90

void Unwind_10019f90(void)

{
  int unaff_EBP;
  
  FUN_10018500(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019fc0 at 10019fc0

void Unwind_10019fc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019fc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019ff0 at 10019ff0

void Unwind_10019ff0(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a020 at 1001a020

void Unwind_1001a020(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001a050 at 1001a050

void Unwind_1001a050(void)

{
  int unaff_EBP;
  
  FUN_10004a30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a080 at 1001a080

void Unwind_1001a080(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001a0c0 at 1001a0c0

void Unwind_1001a0c0(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a0f0 at 1001a0f0

void Unwind_1001a0f0(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@1001a130 at 1001a130

void Unwind_1001a130(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a160 at 1001a160

void Unwind_1001a160(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a16b at 1001a16b

void Unwind_1001a16b(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a190 at 1001a190

void Unwind_1001a190(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x3fc));
  return;
}



// Function: Unwind@1001a1d0 at 1001a1d0

void Unwind_1001a1d0(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a220 at 1001a220

void Unwind_1001a220(void)

{
  int unaff_EBP;
  
  FUN_10003620(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a250 at 1001a250

void Unwind_1001a250(void)

{
  int unaff_EBP;
  
  FUN_10003620(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a25b at 1001a25b

void Unwind_1001a25b(void)

{
  int unaff_EBP;
  
  FUN_10018500(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a280 at 1001a280

void Unwind_1001a280(void)

{
  int unaff_EBP;
  
  FUN_100050c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a288 at 1001a288

void Unwind_1001a288(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a2b0 at 1001a2b0

void Unwind_1001a2b0(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001a2e0 at 1001a2e0

void Unwind_1001a2e0(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001a310 at 1001a310

void Unwind_1001a310(void)

{
  int unaff_EBP;
  
  FUN_100044a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a31b at 1001a31b

void Unwind_1001a31b(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a340 at 1001a340

void Unwind_1001a340(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a34b at 1001a34b

void Unwind_1001a34b(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001a380 at 1001a380

void Unwind_1001a380(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a38b at 1001a38b

void Unwind_1001a38b(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3b0 at 1001a3b0

void Unwind_1001a3b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a3b8 at 1001a3b8

void Unwind_1001a3b8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a3c0 at 1001a3c0

void Unwind_1001a3c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3c8 at 1001a3c8

void Unwind_1001a3c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3d0 at 1001a3d0

void Unwind_1001a3d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3d8 at 1001a3d8

void Unwind_1001a3d8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a400 at 1001a400

void Unwind_1001a400(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a408 at 1001a408

void Unwind_1001a408(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a410 at 1001a410

void Unwind_1001a410(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a418 at 1001a418

void Unwind_1001a418(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001a440 at 1001a440

void Unwind_1001a440(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a448 at 1001a448

void Unwind_1001a448(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a450 at 1001a450

void Unwind_1001a450(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x28);
  return;
}



// Function: Unwind@1001a480 at 1001a480

void Unwind_1001a480(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a488 at 1001a488

void Unwind_1001a488(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a490 at 1001a490

void Unwind_1001a490(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a498 at 1001a498

void Unwind_1001a498(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a4a0 at 1001a4a0

void Unwind_1001a4a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a4a8 at 1001a4a8

void Unwind_1001a4a8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a4b0 at 1001a4b0

void Unwind_1001a4b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a4b8 at 1001a4b8

void Unwind_1001a4b8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a4f0 at 1001a4f0

void Unwind_1001a4f0(void)

{
  int unaff_EBP;
  
  FUN_10004a80(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a4f8 at 1001a4f8

void Unwind_1001a4f8(void)

{
  int unaff_EBP;
  
  FUN_10004a30(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a520 at 1001a520

void Unwind_1001a520(void)

{
  int unaff_EBP;
  
  FUN_10006480(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a550 at 1001a550

void Unwind_1001a550(void)

{
  int unaff_EBP;
  
  FUN_10006f00((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a55b at 1001a55b

void Unwind_1001a55b(void)

{
  int unaff_EBP;
  
  FUN_10006480(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a580 at 1001a580

void Unwind_1001a580(void)

{
  int unaff_EBP;
  
  FUN_10001930(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1001a5b0 at 1001a5b0

void Unwind_1001a5b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a5bb at 1001a5bb

void Unwind_1001a5bb(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a5c6 at 1001a5c6

void Unwind_1001a5c6(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a5d1 at 1001a5d1

void Unwind_1001a5d1(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a5dc at 1001a5dc

void Unwind_1001a5dc(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a5e7 at 1001a5e7

void Unwind_1001a5e7(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1001a5f2 at 1001a5f2

void Unwind_1001a5f2(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@1001a5fd at 1001a5fd

void Unwind_1001a5fd(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@1001a608 at 1001a608

void Unwind_1001a608(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a613 at 1001a613

void Unwind_1001a613(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a650 at 1001a650

void Unwind_1001a650(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a658 at 1001a658

void Unwind_1001a658(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a660 at 1001a660

void Unwind_1001a660(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a668 at 1001a668

void Unwind_1001a668(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a690 at 1001a690

void Unwind_1001a690(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001a69b at 1001a69b

void Unwind_1001a69b(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001a6a6 at 1001a6a6

void Unwind_1001a6a6(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001a6b1 at 1001a6b1

void Unwind_1001a6b1(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001a6bc at 1001a6bc

void Unwind_1001a6bc(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001a6f0 at 1001a6f0

void Unwind_1001a6f0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a6f8 at 1001a6f8

void Unwind_1001a6f8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a700 at 1001a700

void Unwind_1001a700(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a708 at 1001a708

void Unwind_1001a708(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a710 at 1001a710

void Unwind_1001a710(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a718 at 1001a718

void Unwind_1001a718(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a740 at 1001a740

void Unwind_1001a740(void)

{
  int unaff_EBP;
  
  FUN_100066b0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a770 at 1001a770

void Unwind_1001a770(void)

{
  int unaff_EBP;
  
  FUN_100066b0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a7a0 at 1001a7a0

void Unwind_1001a7a0(void)

{
  int unaff_EBP;
  
  FUN_10006560(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a7ab at 1001a7ab

void Unwind_1001a7ab(void)

{
  int unaff_EBP;
  
  FUN_100044a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a7b6 at 1001a7b6

void Unwind_1001a7b6(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a7e0 at 1001a7e0

void Unwind_1001a7e0(void)

{
  int unaff_EBP;
  
  FUN_10006560(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001a7eb at 1001a7eb

void Unwind_1001a7eb(void)

{
  int unaff_EBP;
  
  FUN_100044a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a7f6 at 1001a7f6

void Unwind_1001a7f6(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a820 at 1001a820

void Unwind_1001a820(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a828 at 1001a828

void Unwind_1001a828(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a830 at 1001a830

void Unwind_1001a830(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001a838 at 1001a838

void Unwind_1001a838(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a840 at 1001a840

void Unwind_1001a840(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a848 at 1001a848

void Unwind_1001a848(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a870 at 1001a870

void Unwind_1001a870(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a878 at 1001a878

void Unwind_1001a878(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a880 at 1001a880

void Unwind_1001a880(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a888 at 1001a888

void Unwind_1001a888(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a890 at 1001a890

void Unwind_1001a890(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a898 at 1001a898

void Unwind_1001a898(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8c0 at 1001a8c0

void Unwind_1001a8c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a8c8 at 1001a8c8

void Unwind_1001a8c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a8d0 at 1001a8d0

void Unwind_1001a8d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001a8d8 at 1001a8d8

void Unwind_1001a8d8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001a8e0 at 1001a8e0

void Unwind_1001a8e0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a8e8 at 1001a8e8

void Unwind_1001a8e8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a8f0 at 1001a8f0

void Unwind_1001a8f0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a8f8 at 1001a8f8

void Unwind_1001a8f8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a900 at 1001a900

void Unwind_1001a900(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a908 at 1001a908

void Unwind_1001a908(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a910 at 1001a910

void Unwind_1001a910(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a918 at 1001a918

void Unwind_1001a918(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a920 at 1001a920

void Unwind_1001a920(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a928 at 1001a928

void Unwind_1001a928(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a968 at 1001a968

void Unwind_1001a968(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a973 at 1001a973

void Unwind_1001a973(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001a9a0 at 1001a9a0

void Unwind_1001a9a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9a8 at 1001a9a8

void Unwind_1001a9a8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9b0 at 1001a9b0

void Unwind_1001a9b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a9b8 at 1001a9b8

void Unwind_1001a9b8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a9e0 at 1001a9e0

void Unwind_1001a9e0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aa30 at 1001aa30

void Unwind_1001aa30(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa38 at 1001aa38

void Unwind_1001aa38(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa40 at 1001aa40

void Unwind_1001aa40(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa70 at 1001aa70

void Unwind_1001aa70(void)

{
  DAT_1002a040 = DAT_1002a040 & 0xfffffffe;
  return;
}



// Function: Unwind@1001aa7e at 1001aa7e

void Unwind_1001aa7e(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aa86 at 1001aa86

void Unwind_1001aa86(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aa8e at 1001aa8e

void Unwind_1001aa8e(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aa96 at 1001aa96

void Unwind_1001aa96(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aac0 at 1001aac0

void Unwind_1001aac0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001aac8 at 1001aac8

void Unwind_1001aac8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001aad0 at 1001aad0

void Unwind_1001aad0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001ab00 at 1001ab00

void Unwind_1001ab00(void)

{
  int unaff_EBP;
  
  FUN_100061c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ab30 at 1001ab30

void Unwind_1001ab30(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ab38 at 1001ab38

void Unwind_1001ab38(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ab40 at 1001ab40

void Unwind_1001ab40(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ab48 at 1001ab48

void Unwind_1001ab48(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ab50 at 1001ab50

void Unwind_1001ab50(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ab58 at 1001ab58

void Unwind_1001ab58(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ab60 at 1001ab60

void Unwind_1001ab60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ab68 at 1001ab68

void Unwind_1001ab68(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ab70 at 1001ab70

void Unwind_1001ab70(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ab78 at 1001ab78

void Unwind_1001ab78(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ab80 at 1001ab80

void Unwind_1001ab80(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ab88 at 1001ab88

void Unwind_1001ab88(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ab90 at 1001ab90

void Unwind_1001ab90(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ab98 at 1001ab98

void Unwind_1001ab98(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001aba0 at 1001aba0

void Unwind_1001aba0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001aba8 at 1001aba8

void Unwind_1001aba8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001abb0 at 1001abb0

void Unwind_1001abb0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001abb8 at 1001abb8

void Unwind_1001abb8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001abc0 at 1001abc0

void Unwind_1001abc0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001abc8 at 1001abc8

void Unwind_1001abc8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001abd0 at 1001abd0

void Unwind_1001abd0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001abd8 at 1001abd8

void Unwind_1001abd8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001abe0 at 1001abe0

void Unwind_1001abe0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ac10 at 1001ac10

void Unwind_1001ac10(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ac18 at 1001ac18

void Unwind_1001ac18(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ac20 at 1001ac20

void Unwind_1001ac20(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ac28 at 1001ac28

void Unwind_1001ac28(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001ac30 at 1001ac30

void Unwind_1001ac30(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001ac38 at 1001ac38

void Unwind_1001ac38(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ac40 at 1001ac40

void Unwind_1001ac40(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ac48 at 1001ac48

void Unwind_1001ac48(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac50 at 1001ac50

void Unwind_1001ac50(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac58 at 1001ac58

void Unwind_1001ac58(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac60 at 1001ac60

void Unwind_1001ac60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ac68 at 1001ac68

void Unwind_1001ac68(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001ac70 at 1001ac70

void Unwind_1001ac70(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001aca0 at 1001aca0

void Unwind_1001aca0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aca8 at 1001aca8

void Unwind_1001aca8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001acb0 at 1001acb0

void Unwind_1001acb0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001acb8 at 1001acb8

void Unwind_1001acb8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ace0 at 1001ace0

void Unwind_1001ace0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ace8 at 1001ace8

void Unwind_1001ace8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001acf0 at 1001acf0

void Unwind_1001acf0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad20 at 1001ad20

void Unwind_1001ad20(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad28 at 1001ad28

void Unwind_1001ad28(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad30 at 1001ad30

void Unwind_1001ad30(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ad38 at 1001ad38

void Unwind_1001ad38(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ad40 at 1001ad40

void Unwind_1001ad40(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ad48 at 1001ad48

void Unwind_1001ad48(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad80 at 1001ad80

void Unwind_1001ad80(void)

{
  FUN_10004700();
  return;
}



// Function: Unwind@1001adc0 at 1001adc0

void Unwind_1001adc0(void)

{
  FUN_10004700();
  return;
}



// Function: Unwind@1001add9 at 1001add9

void Unwind_1001add9(void)

{
  FUN_10004700();
  return;
}



// Function: Unwind@1001ae10 at 1001ae10

void Unwind_1001ae10(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001ae40 at 1001ae40

void Unwind_1001ae40(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001ae70 at 1001ae70

void Unwind_1001ae70(void)

{
  int unaff_EBP;
  
  FUN_10006530((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ae78 at 1001ae78

void Unwind_1001ae78(void)

{
  int unaff_EBP;
  
  FUN_10006530((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001aea0 at 1001aea0

void Unwind_1001aea0(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001aed0 at 1001aed0

void Unwind_1001aed0(void)

{
  int unaff_EBP;
  
  FUN_10006550((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1001aedb at 1001aedb

void Unwind_1001aedb(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1001aee6 at 1001aee6

void Unwind_1001aee6(void)

{
  int unaff_EBP;
  
  FUN_10006550((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1001af20 at 1001af20

void Unwind_1001af20(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x2228));
  return;
}



// Function: Unwind@1001af2b at 1001af2b

void Unwind_1001af2b(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@1001af36 at 1001af36

void Unwind_1001af36(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1001af41 at 1001af41

void Unwind_1001af41(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@1001af4c at 1001af4c

void Unwind_1001af4c(void)

{
  int unaff_EBP;
  
  FUN_10004b00((undefined4 *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@1001af80 at 1001af80

void Unwind_1001af80(void)

{
  int unaff_EBP;
  
  FUN_100066b0((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001af8b at 1001af8b

void Unwind_1001af8b(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001af96 at 1001af96

void Unwind_1001af96(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001afa1 at 1001afa1

void Unwind_1001afa1(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001afac at 1001afac

void Unwind_1001afac(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001afb7 at 1001afb7

void Unwind_1001afb7(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001afc2 at 1001afc2

void Unwind_1001afc2(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001afcd at 1001afcd

void Unwind_1001afcd(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001afd8 at 1001afd8

void Unwind_1001afd8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001afe3 at 1001afe3

void Unwind_1001afe3(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001afee at 1001afee

void Unwind_1001afee(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001b030 at 1001b030

void Unwind_1001b030(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b038 at 1001b038

void Unwind_1001b038(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b040 at 1001b040

void Unwind_1001b040(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b070 at 1001b070

void Unwind_1001b070(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b078 at 1001b078

void Unwind_1001b078(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b080 at 1001b080

void Unwind_1001b080(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b088 at 1001b088

void Unwind_1001b088(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001b090 at 1001b090

void Unwind_1001b090(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b0c0 at 1001b0c0

void Unwind_1001b0c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b0c8 at 1001b0c8

void Unwind_1001b0c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b0d0 at 1001b0d0

void Unwind_1001b0d0(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b0d8 at 1001b0d8

void Unwind_1001b0d8(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001b0e0 at 1001b0e0

void Unwind_1001b0e0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b110 at 1001b110

void Unwind_1001b110(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b118 at 1001b118

void Unwind_1001b118(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b120 at 1001b120

void Unwind_1001b120(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b128 at 1001b128

void Unwind_1001b128(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b130 at 1001b130

void Unwind_1001b130(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b138 at 1001b138

void Unwind_1001b138(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b160 at 1001b160

void Unwind_1001b160(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b168 at 1001b168

void Unwind_1001b168(void)

{
  int unaff_EBP;
  
  FUN_10006620(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@1001b173 at 1001b173

void Unwind_1001b173(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1001b17e at 1001b17e

void Unwind_1001b17e(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001b189 at 1001b189

void Unwind_1001b189(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@1001b194 at 1001b194

void Unwind_1001b194(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001b19f at 1001b19f

void Unwind_1001b19f(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001b1aa at 1001b1aa

void Unwind_1001b1aa(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001b1b5 at 1001b1b5

void Unwind_1001b1b5(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001b1c0 at 1001b1c0

void Unwind_1001b1c0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@1001b1cb at 1001b1cb

void Unwind_1001b1cb(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001b1d6 at 1001b1d6

void Unwind_1001b1d6(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001b1e4 at 1001b1e4

void Unwind_1001b1e4(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001b1f2 at 1001b1f2

void Unwind_1001b1f2(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@1001b200 at 1001b200

void Unwind_1001b200(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b208 at 1001b208

void Unwind_1001b208(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b210 at 1001b210

void Unwind_1001b210(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b218 at 1001b218

void Unwind_1001b218(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b220 at 1001b220

void Unwind_1001b220(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b228 at 1001b228

void Unwind_1001b228(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b230 at 1001b230

void Unwind_1001b230(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b238 at 1001b238

void Unwind_1001b238(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b240 at 1001b240

void Unwind_1001b240(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b248 at 1001b248

void Unwind_1001b248(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b250 at 1001b250

void Unwind_1001b250(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b258 at 1001b258

void Unwind_1001b258(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b263 at 1001b263

void Unwind_1001b263(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b26b at 1001b26b

void Unwind_1001b26b(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b273 at 1001b273

void Unwind_1001b273(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b27b at 1001b27b

void Unwind_1001b27b(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b286 at 1001b286

void Unwind_1001b286(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001b2b0 at 1001b2b0

void Unwind_1001b2b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b2b8 at 1001b2b8

void Unwind_1001b2b8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b2c0 at 1001b2c0

void Unwind_1001b2c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b2c8 at 1001b2c8

void Unwind_1001b2c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b2d0 at 1001b2d0

void Unwind_1001b2d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b300 at 1001b300

void Unwind_1001b300(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b308 at 1001b308

void Unwind_1001b308(void)

{
  int unaff_EBP;
  
  FUN_100044a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b313 at 1001b313

void Unwind_1001b313(void)

{
  int unaff_EBP;
  
  FUN_10006560(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001b31e at 1001b31e

void Unwind_1001b31e(void)

{
  int unaff_EBP;
  
  FUN_10008110(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b350 at 1001b350

void Unwind_1001b350(void)

{
  int unaff_EBP;
  
  FUN_10008110(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b358 at 1001b358

void Unwind_1001b358(void)

{
  int unaff_EBP;
  
  FUN_10006560(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001b363 at 1001b363

void Unwind_1001b363(void)

{
  int unaff_EBP;
  
  FUN_100044a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001b36e at 1001b36e

void Unwind_1001b36e(void)

{
  int unaff_EBP;
  
  FUN_10001480(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3a0 at 1001b3a0

void Unwind_1001b3a0(void)

{
  int unaff_EBP;
  
  FUN_10005d80((undefined4 *)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@1001b3ab at 1001b3ab

void Unwind_1001b3ab(void)

{
  int unaff_EBP;
  
  FUN_10005d80((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001b3e0 at 1001b3e0

void Unwind_1001b3e0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3e8 at 1001b3e8

void Unwind_1001b3e8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3f0 at 1001b3f0

void Unwind_1001b3f0(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3f8 at 1001b3f8

void Unwind_1001b3f8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b400 at 1001b400

void Unwind_1001b400(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b408 at 1001b408

void Unwind_1001b408(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b410 at 1001b410

void Unwind_1001b410(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b418 at 1001b418

void Unwind_1001b418(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b420 at 1001b420

void Unwind_1001b420(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b428 at 1001b428

void Unwind_1001b428(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b430 at 1001b430

void Unwind_1001b430(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b438 at 1001b438

void Unwind_1001b438(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b440 at 1001b440

void Unwind_1001b440(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b448 at 1001b448

void Unwind_1001b448(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b450 at 1001b450

void Unwind_1001b450(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b458 at 1001b458

void Unwind_1001b458(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b460 at 1001b460

void Unwind_1001b460(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b468 at 1001b468

void Unwind_1001b468(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b470 at 1001b470

void Unwind_1001b470(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b478 at 1001b478

void Unwind_1001b478(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b480 at 1001b480

void Unwind_1001b480(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b488 at 1001b488

void Unwind_1001b488(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b490 at 1001b490

void Unwind_1001b490(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b498 at 1001b498

void Unwind_1001b498(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4a0 at 1001b4a0

void Unwind_1001b4a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4a8 at 1001b4a8

void Unwind_1001b4a8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b4b0 at 1001b4b0

void Unwind_1001b4b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b4b8 at 1001b4b8

void Unwind_1001b4b8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b4c0 at 1001b4c0

void Unwind_1001b4c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b4c8 at 1001b4c8

void Unwind_1001b4c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4d0 at 1001b4d0

void Unwind_1001b4d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b500 at 1001b500

void Unwind_1001b500(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b508 at 1001b508

void Unwind_1001b508(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b510 at 1001b510

void Unwind_1001b510(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b518 at 1001b518

void Unwind_1001b518(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b520 at 1001b520

void Unwind_1001b520(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b528 at 1001b528

void Unwind_1001b528(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b530 at 1001b530

void Unwind_1001b530(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b538 at 1001b538

void Unwind_1001b538(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b540 at 1001b540

void Unwind_1001b540(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b548 at 1001b548

void Unwind_1001b548(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b550 at 1001b550

void Unwind_1001b550(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b558 at 1001b558

void Unwind_1001b558(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b560 at 1001b560

void Unwind_1001b560(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b568 at 1001b568

void Unwind_1001b568(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b570 at 1001b570

void Unwind_1001b570(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b578 at 1001b578

void Unwind_1001b578(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b580 at 1001b580

void Unwind_1001b580(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b588 at 1001b588

void Unwind_1001b588(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b590 at 1001b590

void Unwind_1001b590(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b598 at 1001b598

void Unwind_1001b598(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5a0 at 1001b5a0

void Unwind_1001b5a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5a8 at 1001b5a8

void Unwind_1001b5a8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b5b0 at 1001b5b0

void Unwind_1001b5b0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5b8 at 1001b5b8

void Unwind_1001b5b8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b5c0 at 1001b5c0

void Unwind_1001b5c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b5f0 at 1001b5f0

void Unwind_1001b5f0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5f8 at 1001b5f8

void Unwind_1001b5f8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b600 at 1001b600

void Unwind_1001b600(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b608 at 1001b608

void Unwind_1001b608(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b610 at 1001b610

void Unwind_1001b610(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b618 at 1001b618

void Unwind_1001b618(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b620 at 1001b620

void Unwind_1001b620(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b628 at 1001b628

void Unwind_1001b628(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b670 at 1001b670

void Unwind_1001b670(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b678 at 1001b678

void Unwind_1001b678(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b680 at 1001b680

void Unwind_1001b680(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b688 at 1001b688

void Unwind_1001b688(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b690 at 1001b690

void Unwind_1001b690(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b698 at 1001b698

void Unwind_1001b698(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b6a0 at 1001b6a0

void Unwind_1001b6a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b6a8 at 1001b6a8

void Unwind_1001b6a8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b6b0 at 1001b6b0

void Unwind_1001b6b0(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b6b8 at 1001b6b8

void Unwind_1001b6b8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b6c0 at 1001b6c0

void Unwind_1001b6c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b6c8 at 1001b6c8

void Unwind_1001b6c8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b6d0 at 1001b6d0

void Unwind_1001b6d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b6d8 at 1001b6d8

void Unwind_1001b6d8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6e0 at 1001b6e0

void Unwind_1001b6e0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6e8 at 1001b6e8

void Unwind_1001b6e8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6f0 at 1001b6f0

void Unwind_1001b6f0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6f8 at 1001b6f8

void Unwind_1001b6f8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b700 at 1001b700

void Unwind_1001b700(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b708 at 1001b708

void Unwind_1001b708(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b710 at 1001b710

void Unwind_1001b710(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b718 at 1001b718

void Unwind_1001b718(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b720 at 1001b720

void Unwind_1001b720(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b728 at 1001b728

void Unwind_1001b728(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b750 at 1001b750

void Unwind_1001b750(void)

{
  int unaff_EBP;
  
  FUN_1000c3a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b780 at 1001b780

void Unwind_1001b780(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b7b0 at 1001b7b0

void Unwind_1001b7b0(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001b7bb at 1001b7bb

void Unwind_1001b7bb(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b7c6 at 1001b7c6

void Unwind_1001b7c6(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b7ce at 1001b7ce

void Unwind_1001b7ce(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b7d6 at 1001b7d6

void Unwind_1001b7d6(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b7de at 1001b7de

void Unwind_1001b7de(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b7e6 at 1001b7e6

void Unwind_1001b7e6(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b7f1 at 1001b7f1

void Unwind_1001b7f1(void)

{
  int unaff_EBP;
  
  FUN_10006620(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@1001b7fc at 1001b7fc

void Unwind_1001b7fc(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b804 at 1001b804

void Unwind_1001b804(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1001b80f at 1001b80f

void Unwind_1001b80f(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b817 at 1001b817

void Unwind_1001b817(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001b822 at 1001b822

void Unwind_1001b822(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b82a at 1001b82a

void Unwind_1001b82a(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@1001b835 at 1001b835

void Unwind_1001b835(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b83d at 1001b83d

void Unwind_1001b83d(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001b848 at 1001b848

void Unwind_1001b848(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b850 at 1001b850

void Unwind_1001b850(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001b85b at 1001b85b

void Unwind_1001b85b(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b863 at 1001b863

void Unwind_1001b863(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001b86e at 1001b86e

void Unwind_1001b86e(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b876 at 1001b876

void Unwind_1001b876(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001b881 at 1001b881

void Unwind_1001b881(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b889 at 1001b889

void Unwind_1001b889(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@1001b894 at 1001b894

void Unwind_1001b894(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b89c at 1001b89c

void Unwind_1001b89c(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001b8a7 at 1001b8a7

void Unwind_1001b8a7(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b8af at 1001b8af

void Unwind_1001b8af(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001b8bd at 1001b8bd

void Unwind_1001b8bd(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b8c5 at 1001b8c5

void Unwind_1001b8c5(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001b8d3 at 1001b8d3

void Unwind_1001b8d3(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@1001b900 at 1001b900

void Unwind_1001b900(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b930 at 1001b930

void Unwind_1001b930(void)

{
  int unaff_EBP;
  
  FUN_10011200(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b938 at 1001b938

void Unwind_1001b938(void)

{
  int unaff_EBP;
  
  FUN_100100e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b960 at 1001b960

void Unwind_1001b960(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b968 at 1001b968

void Unwind_1001b968(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001b973 at 1001b973

void Unwind_1001b973(void)

{
  int unaff_EBP;
  
  FUN_100061c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b97b at 1001b97b

void Unwind_1001b97b(void)

{
  int unaff_EBP;
  
  FUN_100097a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b9a0 at 1001b9a0

void Unwind_1001b9a0(void)

{
  int unaff_EBP;
  
  FUN_100097a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b9a8 at 1001b9a8

void Unwind_1001b9a8(void)

{
  int unaff_EBP;
  
  FUN_100061c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ba10 at 1001ba10

void Unwind_1001ba10(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001ba40 at 1001ba40

void Unwind_1001ba40(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ba48 at 1001ba48

void Unwind_1001ba48(void)

{
  int unaff_EBP;
  
  FUN_100050c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ba70 at 1001ba70

void Unwind_1001ba70(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ba7b at 1001ba7b

void Unwind_1001ba7b(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001baa0 at 1001baa0

void Unwind_1001baa0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001baa8 at 1001baa8

void Unwind_1001baa8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bae0 at 1001bae0

void Unwind_1001bae0(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bae8 at 1001bae8

void Unwind_1001bae8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001baf3 at 1001baf3

void Unwind_1001baf3(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bafb at 1001bafb

void Unwind_1001bafb(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb03 at 1001bb03

void Unwind_1001bb03(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb0b at 1001bb0b

void Unwind_1001bb0b(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001bb16 at 1001bb16

void Unwind_1001bb16(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001bb40 at 1001bb40

void Unwind_1001bb40(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb48 at 1001bb48

void Unwind_1001bb48(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb50 at 1001bb50

void Unwind_1001bb50(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb58 at 1001bb58

void Unwind_1001bb58(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb60 at 1001bb60

void Unwind_1001bb60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb68 at 1001bb68

void Unwind_1001bb68(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb70 at 1001bb70

void Unwind_1001bb70(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bba0 at 1001bba0

void Unwind_1001bba0(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001bbe0 at 1001bbe0

void Unwind_1001bbe0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bbe8 at 1001bbe8

void Unwind_1001bbe8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bbf0 at 1001bbf0

void Unwind_1001bbf0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bc20 at 1001bc20

void Unwind_1001bc20(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bc28 at 1001bc28

void Unwind_1001bc28(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bc50 at 1001bc50

void Unwind_1001bc50(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bc58 at 1001bc58

void Unwind_1001bc58(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bc60 at 1001bc60

void Unwind_1001bc60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bc90 at 1001bc90

void Unwind_1001bc90(void)

{
  int unaff_EBP;
  
  FUN_100100e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bce0 at 1001bce0

void Unwind_1001bce0(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bce8 at 1001bce8

void Unwind_1001bce8(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bcf0 at 1001bcf0

void Unwind_1001bcf0(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001bcfb at 1001bcfb

void Unwind_1001bcfb(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001bd30 at 1001bd30

void Unwind_1001bd30(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001bd38 at 1001bd38

void Unwind_1001bd38(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001bd40 at 1001bd40

void Unwind_1001bd40(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001bd70 at 1001bd70

void Unwind_1001bd70(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd78 at 1001bd78

void Unwind_1001bd78(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd80 at 1001bd80

void Unwind_1001bd80(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd88 at 1001bd88

void Unwind_1001bd88(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bd90 at 1001bd90

void Unwind_1001bd90(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bdc0 at 1001bdc0

void Unwind_1001bdc0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bdc8 at 1001bdc8

void Unwind_1001bdc8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bdd0 at 1001bdd0

void Unwind_1001bdd0(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bdd8 at 1001bdd8

void Unwind_1001bdd8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bde0 at 1001bde0

void Unwind_1001bde0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be10 at 1001be10

void Unwind_1001be10(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be18 at 1001be18

void Unwind_1001be18(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be20 at 1001be20

void Unwind_1001be20(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be28 at 1001be28

void Unwind_1001be28(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be30 at 1001be30

void Unwind_1001be30(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001be60 at 1001be60

void Unwind_1001be60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001be68 at 1001be68

void Unwind_1001be68(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001be70 at 1001be70

void Unwind_1001be70(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001be78 at 1001be78

void Unwind_1001be78(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001be80 at 1001be80

void Unwind_1001be80(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001beb0 at 1001beb0

void Unwind_1001beb0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001beb8 at 1001beb8

void Unwind_1001beb8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bec0 at 1001bec0

void Unwind_1001bec0(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bec8 at 1001bec8

void Unwind_1001bec8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bed0 at 1001bed0

void Unwind_1001bed0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bf00 at 1001bf00

void Unwind_1001bf00(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf08 at 1001bf08

void Unwind_1001bf08(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf10 at 1001bf10

void Unwind_1001bf10(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf18 at 1001bf18

void Unwind_1001bf18(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf20 at 1001bf20

void Unwind_1001bf20(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf28 at 1001bf28

void Unwind_1001bf28(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf30 at 1001bf30

void Unwind_1001bf30(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf38 at 1001bf38

void Unwind_1001bf38(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf40 at 1001bf40

void Unwind_1001bf40(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001bf48 at 1001bf48

void Unwind_1001bf48(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf50 at 1001bf50

void Unwind_1001bf50(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf58 at 1001bf58

void Unwind_1001bf58(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf60 at 1001bf60

void Unwind_1001bf60(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf68 at 1001bf68

void Unwind_1001bf68(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf70 at 1001bf70

void Unwind_1001bf70(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf78 at 1001bf78

void Unwind_1001bf78(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bf80 at 1001bf80

void Unwind_1001bf80(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bf88 at 1001bf88

void Unwind_1001bf88(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bf90 at 1001bf90

void Unwind_1001bf90(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bf98 at 1001bf98

void Unwind_1001bf98(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bfa0 at 1001bfa0

void Unwind_1001bfa0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bfa8 at 1001bfa8

void Unwind_1001bfa8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001bfb0 at 1001bfb0

void Unwind_1001bfb0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bfb8 at 1001bfb8

void Unwind_1001bfb8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bfc0 at 1001bfc0

void Unwind_1001bfc0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bfc8 at 1001bfc8

void Unwind_1001bfc8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bfd0 at 1001bfd0

void Unwind_1001bfd0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c000 at 1001c000

void Unwind_1001c000(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c008 at 1001c008

void Unwind_1001c008(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c013 at 1001c013

void Unwind_1001c013(void)

{
  int unaff_EBP;
  
  FUN_100100e0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c01b at 1001c01b

void Unwind_1001c01b(void)

{
  int unaff_EBP;
  
  FUN_10011200(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c040 at 1001c040

void Unwind_1001c040(void)

{
  int unaff_EBP;
  
  FUN_1000c3a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c090 at 1001c090

void Unwind_1001c090(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c098 at 1001c098

void Unwind_1001c098(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001c0a0 at 1001c0a0

void Unwind_1001c0a0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001c0a8 at 1001c0a8

void Unwind_1001c0a8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c0b0 at 1001c0b0

void Unwind_1001c0b0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c0b8 at 1001c0b8

void Unwind_1001c0b8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c0c0 at 1001c0c0

void Unwind_1001c0c0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c0c8 at 1001c0c8

void Unwind_1001c0c8(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001c0d0 at 1001c0d0

void Unwind_1001c0d0(void)

{
  int unaff_EBP;
  
  FUN_100049b0(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001c120 at 1001c120

void Unwind_1001c120(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001c12b at 1001c12b

void Unwind_1001c12b(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c136 at 1001c136

void Unwind_1001c136(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c13e at 1001c13e

void Unwind_1001c13e(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c146 at 1001c146

void Unwind_1001c146(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c14e at 1001c14e

void Unwind_1001c14e(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c156 at 1001c156

void Unwind_1001c156(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001c161 at 1001c161

void Unwind_1001c161(void)

{
  int unaff_EBP;
  
  FUN_100103c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c190 at 1001c190

void Unwind_1001c190(void)

{
  int unaff_EBP;
  
  FUN_100103c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c198 at 1001c198

void Unwind_1001c198(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c1a0 at 1001c1a0

void Unwind_1001c1a0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001c1ab at 1001c1ab

void Unwind_1001c1ab(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c1b3 at 1001c1b3

void Unwind_1001c1b3(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c1bb at 1001c1bb

void Unwind_1001c1bb(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c1c3 at 1001c1c3

void Unwind_1001c1c3(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c1ce at 1001c1ce

void Unwind_1001c1ce(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001c200 at 1001c200

void Unwind_1001c200(void)

{
  int unaff_EBP;
  
  FUN_100066b0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c230 at 1001c230

void Unwind_1001c230(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1001c23b at 1001c23b

void Unwind_1001c23b(void)

{
  int unaff_EBP;
  
  FUN_10006550((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001c270 at 1001c270

void Unwind_1001c270(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c2a0 at 1001c2a0

void Unwind_1001c2a0(void)

{
  int unaff_EBP;
  
  FUN_10006480(*(undefined4 **)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1001c2ab at 1001c2ab

void Unwind_1001c2ab(void)

{
  int unaff_EBP;
  
  FUN_10006f00((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001c2b6 at 1001c2b6

void Unwind_1001c2b6(void)

{
  int unaff_EBP;
  
  FUN_10006f80((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001c2c1 at 1001c2c1

void Unwind_1001c2c1(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@1001c2cc at 1001c2cc

void Unwind_1001c2cc(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001c300 at 1001c300

void Unwind_1001c300(void)

{
  int unaff_EBP;
  
  FUN_10006480(*(undefined4 **)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001c30b at 1001c30b

void Unwind_1001c30b(void)

{
  int unaff_EBP;
  
  FUN_10006f00((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001c316 at 1001c316

void Unwind_1001c316(void)

{
  int unaff_EBP;
  
  FUN_10006f80((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001c321 at 1001c321

void Unwind_1001c321(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001c32c at 1001c32c

void Unwind_1001c32c(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001c360 at 1001c360

void Unwind_1001c360(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c368 at 1001c368

void Unwind_1001c368(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c370 at 1001c370

void Unwind_1001c370(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c378 at 1001c378

void Unwind_1001c378(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c380 at 1001c380

void Unwind_1001c380(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c388 at 1001c388

void Unwind_1001c388(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c390 at 1001c390

void Unwind_1001c390(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c398 at 1001c398

void Unwind_1001c398(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c3c0 at 1001c3c0

void Unwind_1001c3c0(void)

{
  DAT_1002a01c = DAT_1002a01c & 0xfffffffe;
  return;
}



// Function: Unwind@1001c3ce at 1001c3ce

void Unwind_1001c3ce(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c420 at 1001c420

void Unwind_1001c420(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c428 at 1001c428

void Unwind_1001c428(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100050c0((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1001c441 at 1001c441

void Unwind_1001c441(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c449 at 1001c449

void Unwind_1001c449(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_100050c0((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@1001c462 at 1001c462

void Unwind_1001c462(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c46a at 1001c46a

void Unwind_1001c46a(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c490 at 1001c490

void Unwind_1001c490(void)

{
  int unaff_EBP;
  
  FUN_1000d610(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c4c0 at 1001c4c0

void Unwind_1001c4c0(void)

{
  int unaff_EBP;
  
  FUN_1000d610(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c4cb at 1001c4cb

void Unwind_1001c4cb(void)

{
  int unaff_EBP;
  
  FUN_1000c3a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c530 at 1001c530

void Unwind_1001c530(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c560 at 1001c560

void Unwind_1001c560(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c568 at 1001c568

void Unwind_1001c568(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c570 at 1001c570

void Unwind_1001c570(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c578 at 1001c578

void Unwind_1001c578(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c580 at 1001c580

void Unwind_1001c580(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c588 at 1001c588

void Unwind_1001c588(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c590 at 1001c590

void Unwind_1001c590(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c598 at 1001c598

void Unwind_1001c598(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c5a0 at 1001c5a0

void Unwind_1001c5a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5a8 at 1001c5a8

void Unwind_1001c5a8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5d0 at 1001c5d0

void Unwind_1001c5d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5d8 at 1001c5d8

void Unwind_1001c5d8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5e0 at 1001c5e0

void Unwind_1001c5e0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5e8 at 1001c5e8

void Unwind_1001c5e8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5f0 at 1001c5f0

void Unwind_1001c5f0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5f8 at 1001c5f8

void Unwind_1001c5f8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c600 at 1001c600

void Unwind_1001c600(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c630 at 1001c630

void Unwind_1001c630(void)

{
  int unaff_EBP;
  
  FUN_10006680((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c638 at 1001c638

void Unwind_1001c638(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c640 at 1001c640

void Unwind_1001c640(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c648 at 1001c648

void Unwind_1001c648(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c650 at 1001c650

void Unwind_1001c650(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c658 at 1001c658

void Unwind_1001c658(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c660 at 1001c660

void Unwind_1001c660(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c668 at 1001c668

void Unwind_1001c668(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c6a0 at 1001c6a0

void Unwind_1001c6a0(void)

{
  int unaff_EBP;
  
  FUN_10006680((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c6a8 at 1001c6a8

void Unwind_1001c6a8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c6b0 at 1001c6b0

void Unwind_1001c6b0(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c6b8 at 1001c6b8

void Unwind_1001c6b8(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c6c0 at 1001c6c0

void Unwind_1001c6c0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c6c8 at 1001c6c8

void Unwind_1001c6c8(void)

{
  int unaff_EBP;
  
  FUN_10004440((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c6d0 at 1001c6d0

void Unwind_1001c6d0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c6d8 at 1001c6d8

void Unwind_1001c6d8(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c710 at 1001c710

void Unwind_1001c710(void)

{
  int unaff_EBP;
  
  FUN_100066b0((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c740 at 1001c740

void Unwind_1001c740(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c748 at 1001c748

void Unwind_1001c748(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c750 at 1001c750

void Unwind_1001c750(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c780 at 1001c780

void Unwind_1001c780(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c788 at 1001c788

void Unwind_1001c788(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c790 at 1001c790

void Unwind_1001c790(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c798 at 1001c798

void Unwind_1001c798(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c7a0 at 1001c7a0

void Unwind_1001c7a0(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c7a8 at 1001c7a8

void Unwind_1001c7a8(void)

{
  int unaff_EBP;
  
  FUN_10004490((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c7e0 at 1001c7e0

void Unwind_1001c7e0(void)

{
  FUN_10004a30(0x1002a044);
  return;
}



// Function: Unwind@1001c7ea at 1001c7ea

void Unwind_1001c7ea(void)

{
  FUN_10004a80(0x1002a044);
  return;
}



// Function: Unwind@1001c810 at 1001c810

void Unwind_1001c810(void)

{
  FUN_10004a80(0x1002a044);
  return;
}



// Function: Unwind@1001c81a at 1001c81a

void Unwind_1001c81a(void)

{
  FUN_10004a30(0x1002a044);
  return;
}



// Function: Unwind@1001c840 at 1001c840

void Unwind_1001c840(void)

{
  int unaff_EBP;
  
  FUN_10016ce0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c870 at 1001c870

void Unwind_1001c870(void)

{
  int unaff_EBP;
  
  FUN_10016ed0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c8a0 at 1001c8a0

void Unwind_1001c8a0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100014e0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c8e0 at 1001c8e0

void Unwind_1001c8e0(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c910 at 1001c910

void Unwind_1001c910(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c918 at 1001c918

void Unwind_1001c918(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c920 at 1001c920

void Unwind_1001c920(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c928 at 1001c928

void Unwind_1001c928(void)

{
  int unaff_EBP;
  
  FUN_100014e0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c960 at 1001c960

void Unwind_1001c960(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c968 at 1001c968

void Unwind_1001c968(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c973 at 1001c973

void Unwind_1001c973(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c97b at 1001c97b

void Unwind_1001c97b(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001c986 at 1001c986

void Unwind_1001c986(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c98e at 1001c98e

void Unwind_1001c98e(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001c999 at 1001c999

void Unwind_1001c999(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c9a1 at 1001c9a1

void Unwind_1001c9a1(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001c9ac at 1001c9ac

void Unwind_1001c9ac(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c9b4 at 1001c9b4

void Unwind_1001c9b4(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1001c9bf at 1001c9bf

void Unwind_1001c9bf(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c9c7 at 1001c9c7

void Unwind_1001c9c7(void)

{
  int unaff_EBP;
  
  FUN_100050c0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c9cf at 1001c9cf

void Unwind_1001c9cf(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001ca00 at 1001ca00

void Unwind_1001ca00(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ca0b at 1001ca0b

void Unwind_1001ca0b(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001ca16 at 1001ca16

void Unwind_1001ca16(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001ca21 at 1001ca21

void Unwind_1001ca21(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001ca2c at 1001ca2c

void Unwind_1001ca2c(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1001ca37 at 1001ca37

void Unwind_1001ca37(void)

{
  int unaff_EBP;
  
  FUN_10005f30((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001ca42 at 1001ca42

void Unwind_1001ca42(void)

{
  int unaff_EBP;
  
  FUN_100050c0(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca4a at 1001ca4a

void Unwind_1001ca4a(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca52 at 1001ca52

void Unwind_1001ca52(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca5a at 1001ca5a

void Unwind_1001ca5a(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca62 at 1001ca62

void Unwind_1001ca62(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca6a at 1001ca6a

void Unwind_1001ca6a(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ca72 at 1001ca72

void Unwind_1001ca72(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001caa0 at 1001caa0

void Unwind_1001caa0(void)

{
  int unaff_EBP;
  
  FUN_10005d80((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001cb00 at 1001cb00

void Unwind_1001cb00(void)

{
  int unaff_EBP;
  
  FUN_10017810(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb08 at 1001cb08

void Unwind_1001cb08(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10) + 0x48);
  return;
}



// Function: Unwind@1001cb13 at 1001cb13

void Unwind_1001cb13(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cb1b at 1001cb1b

void Unwind_1001cb1b(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cb23 at 1001cb23

void Unwind_1001cb23(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@1001cb2e at 1001cb2e

void Unwind_1001cb2e(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001cb60 at 1001cb60

void Unwind_1001cb60(void)

{
  int unaff_EBP;
  
  FUN_10017810(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb68 at 1001cb68

void Unwind_1001cb68(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  return;
}



// Function: Unwind@1001cb73 at 1001cb73

void Unwind_1001cb73(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@1001cb7e at 1001cb7e

void Unwind_1001cb7e(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cb86 at 1001cb86

void Unwind_1001cb86(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cb8e at 1001cb8e

void Unwind_1001cb8e(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10) + 0x48);
  return;
}



// Function: Unwind@1001cb99 at 1001cb99

void Unwind_1001cb99(void)

{
  int unaff_EBP;
  
  FUN_10017ff0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cbc0 at 1001cbc0

void Unwind_1001cbc0(void)

{
  int unaff_EBP;
  
  FUN_10017ff0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cbc8 at 1001cbc8

void Unwind_1001cbc8(void)

{
  int unaff_EBP;
  
  FUN_10017810(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cbd0 at 1001cbd0

void Unwind_1001cbd0(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10) + 0x48);
  return;
}



// Function: Unwind@1001cbdb at 1001cbdb

void Unwind_1001cbdb(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cbe3 at 1001cbe3

void Unwind_1001cbe3(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cbeb at 1001cbeb

void Unwind_1001cbeb(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@1001cbf6 at 1001cbf6

void Unwind_1001cbf6(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001cc20 at 1001cc20

void Unwind_1001cc20(void)

{
  int unaff_EBP;
  
  FUN_10017ff0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cc28 at 1001cc28

void Unwind_1001cc28(void)

{
  int unaff_EBP;
  
  FUN_10017810(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cc30 at 1001cc30

void Unwind_1001cc30(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x10) + 0x48);
  return;
}



// Function: Unwind@1001cc3b at 1001cc3b

void Unwind_1001cc3b(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cc43 at 1001cc43

void Unwind_1001cc43(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cc4b at 1001cc4b

void Unwind_1001cc4b(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@1001cc56 at 1001cc56

void Unwind_1001cc56(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001cc80 at 1001cc80

void Unwind_1001cc80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10008050(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ccc0 at 1001ccc0

void Unwind_1001ccc0(void)

{
  int unaff_EBP;
  
  FUN_10018170((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001cccb at 1001cccb

void Unwind_1001cccb(void)

{
  int unaff_EBP;
  
  FUN_10016f80(*(int *)(unaff_EBP + -0x10) + 0xb0);
  return;
}



// Function: Unwind@1001ccd9 at 1001ccd9

void Unwind_1001ccd9(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xe0));
  return;
}



// Function: Unwind@1001cce7 at 1001cce7

void Unwind_1001cce7(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x100));
  return;
}



// Function: Unwind@1001ccf5 at 1001ccf5

void Unwind_1001ccf5(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x10) + 0x11c),0x1c,4,FUN_10008050)
  ;
  return;
}



// Function: Unwind@1001cd0d at 1001cd0d

void Unwind_1001cd0d(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cd15 at 1001cd15

void Unwind_1001cd15(void)

{
  int unaff_EBP;
  
  FUN_10016ed0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cd1d at 1001cd1d

void Unwind_1001cd1d(void)

{
  int unaff_EBP;
  
  FUN_10017ff0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cd25 at 1001cd25

void Unwind_1001cd25(void)

{
  int unaff_EBP;
  
  FUN_10017810(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cd2d at 1001cd2d

void Unwind_1001cd2d(void)

{
  int unaff_EBP;
  
  FUN_100113a0(*(int *)(unaff_EBP + -0x14) + 0x48);
  return;
}



// Function: Unwind@1001cd38 at 1001cd38

void Unwind_1001cd38(void)

{
  int unaff_EBP;
  
  FUN_10008d50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cd40 at 1001cd40

void Unwind_1001cd40(void)

{
  int unaff_EBP;
  
  FUN_100065c0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cd48 at 1001cd48

void Unwind_1001cd48(void)

{
  int unaff_EBP;
  
  FUN_100044f0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001cd53 at 1001cd53

void Unwind_1001cd53(void)

{
  int unaff_EBP;
  
  FUN_100024a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001cd80 at 1001cd80

void Unwind_1001cd80(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001cdb0 at 1001cdb0

void Unwind_1001cdb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10008050(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001cdf0 at 1001cdf0

void Unwind_1001cdf0(void)

{
  int unaff_EBP;
  
  FUN_10018170((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001cdfb at 1001cdfb

void Unwind_1001cdfb(void)

{
  int unaff_EBP;
  
  FUN_10016ce0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001ce06 at 1001ce06

void Unwind_1001ce06(void)

{
  int unaff_EBP;
  
  FUN_10016ed0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ce0e at 1001ce0e

void Unwind_1001ce0e(void)

{
  int unaff_EBP;
  
  FUN_10016f80(*(int *)(unaff_EBP + -0x10) + 0xb0);
  return;
}



// Function: Unwind@1001ce1c at 1001ce1c

void Unwind_1001ce1c(void)

{
  int unaff_EBP;
  
  FUN_10004490(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ce24 at 1001ce24

void Unwind_1001ce24(void)

{
  int unaff_EBP;
  
  FUN_100050c0((int *)(*(int *)(unaff_EBP + -0x10) + 0xe0));
  return;
}



// Function: Unwind@1001ce32 at 1001ce32

void Unwind_1001ce32(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x100));
  return;
}



// Function: Unwind@1001ce40 at 1001ce40

void Unwind_1001ce40(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(*(int *)(unaff_EBP + -0x10) + 0x11c),0x1c,4,FUN_10008050)
  ;
  return;
}



// Function: Unwind@1001ce80 at 1001ce80

void Unwind_1001ce80(void)

{
  int unaff_EBP;
  
  FUN_10017fc0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ceb0 at 1001ceb0

void Unwind_1001ceb0(void)

{
  int unaff_EBP;
  
  FUN_10017fc0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ceb8 at 1001ceb8

void Unwind_1001ceb8(void)

{
  int unaff_EBP;
  
  FUN_10017fc0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001cef0 at 1001cef0

void Unwind_1001cef0(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001cef8 at 1001cef8

void Unwind_1001cef8(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001cf03 at 1001cf03

void Unwind_1001cf03(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001cf0b at 1001cf0b

void Unwind_1001cf0b(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001cf13 at 1001cf13

void Unwind_1001cf13(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001cf1b at 1001cf1b

void Unwind_1001cf1b(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001cf23 at 1001cf23

void Unwind_1001cf23(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@1001cf2e at 1001cf2e

void Unwind_1001cf2e(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001cf36 at 1001cf36

void Unwind_1001cf36(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001cf3e at 1001cf3e

void Unwind_1001cf3e(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001cf46 at 1001cf46

void Unwind_1001cf46(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001cf4e at 1001cf4e

void Unwind_1001cf4e(void)

{
  int unaff_EBP;
  
  FUN_10008050((undefined4 *)(unaff_EBP + -0xb0));
  return;
}



// Function: FUN_1001d010 at 1001d010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d010(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c7f4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100049c0(0x1002a044);
  DAT_1002a044 = ATL::CComModule::vftable;
  _DAT_10029fdc = &DAT_1002a044;
  local_8 = 0xffffffff;
  _atexit(FUN_1001d3f0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001d3f0 at 1001d3f0

void FUN_1001d3f0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c824;
  local_10 = ExceptionList;
  uVar1 = DAT_10029f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_1002a044 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_1002a048 != 0) {
    if (DAT_1002a050 != 0) {
      FUN_10001fb0(0x1002a048);
      DAT_1002a050 = 0;
    }
    if (DAT_1002a06c != (int *)0x0) {
      (**(code **)(*DAT_1002a06c + 8))(DAT_1002a06c,uVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1002a054);
    DAT_1002a048 = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001d480 at 1001d480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d480(void)

{
  if (7 < DAT_1002805c) {
    operator_delete(DAT_10028048);
  }
  DAT_1002805c = 7;
  _DAT_10028058 = 0;
  DAT_10028048 = (void *)((uint)DAT_10028048 & 0xffff0000);
  return;
}



// Function: FUN_1001d4c0 at 1001d4c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d4c0(void)

{
  if (7 < DAT_10028078) {
    operator_delete(DAT_10028064);
  }
  DAT_10028078 = 7;
  _DAT_10028074 = 0;
  DAT_10028064 = (void *)((uint)DAT_10028064 & 0xffff0000);
  return;
}



// Function: FUN_1001d500 at 1001d500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d500(void)

{
  if (7 < DAT_10028094) {
    operator_delete(DAT_10028080);
  }
  DAT_10028094 = 7;
  _DAT_10028090 = 0;
  DAT_10028080 = (void *)((uint)DAT_10028080 & 0xffff0000);
  return;
}



// Function: FUN_1001d540 at 1001d540

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d540(void)

{
  if (7 < DAT_100280b0) {
    operator_delete(DAT_1002809c);
  }
  DAT_100280b0 = 7;
  _DAT_100280ac = 0;
  DAT_1002809c = (void *)((uint)DAT_1002809c & 0xffff0000);
  return;
}



// Function: FUN_1001d580 at 1001d580

void FUN_1001d580(void)

{
  Ordinal_6(DAT_1002a074);
  return;
}



// Function: FUN_1001d590 at 1001d590

void FUN_1001d590(void)

{
  Ordinal_6(DAT_1002a078);
  return;
}



// Function: FUN_1001d5a0 at 1001d5a0

void FUN_1001d5a0(void)

{
  Ordinal_6(DAT_1002a07c);
  return;
}



// Function: FUN_1001d5b0 at 1001d5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d5b0(void)

{
  if (7 < DAT_10029d58) {
    operator_delete(DAT_10029d44);
  }
  DAT_10029d58 = 7;
  _DAT_10029d54 = 0;
  DAT_10029d44 = (void *)((uint)DAT_10029d44 & 0xffff0000);
  return;
}



// Function: FUN_1001d5f0 at 1001d5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d5f0(void)

{
  if (7 < DAT_10029d74) {
    operator_delete(DAT_10029d60);
  }
  DAT_10029d74 = 7;
  _DAT_10029d70 = 0;
  DAT_10029d60 = (void *)((uint)DAT_10029d60 & 0xffff0000);
  return;
}



// Function: FUN_1001d630 at 1001d630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d630(void)

{
  if (7 < DAT_10029d90) {
    operator_delete(DAT_10029d7c);
  }
  DAT_10029d90 = 7;
  _DAT_10029d8c = 0;
  DAT_10029d7c = (void *)((uint)DAT_10029d7c & 0xffff0000);
  return;
}



// Function: FUN_1001d670 at 1001d670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d670(void)

{
  if (7 < DAT_10029dac) {
    operator_delete(DAT_10029d98);
  }
  DAT_10029dac = 7;
  _DAT_10029da8 = 0;
  DAT_10029d98 = (void *)((uint)DAT_10029d98 & 0xffff0000);
  return;
}



// Function: FUN_1001d6b0 at 1001d6b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d6b0(void)

{
  if (7 < DAT_10029dc8) {
    operator_delete(DAT_10029db4);
  }
  DAT_10029dc8 = 7;
  _DAT_10029dc4 = 0;
  DAT_10029db4 = (void *)((uint)DAT_10029db4 & 0xffff0000);
  return;
}



// Function: FUN_1001d6f0 at 1001d6f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d6f0(void)

{
  if (7 < DAT_10029de4) {
    operator_delete(DAT_10029dd0);
  }
  DAT_10029de4 = 7;
  _DAT_10029de0 = 0;
  DAT_10029dd0 = (void *)((uint)DAT_10029dd0 & 0xffff0000);
  return;
}



// Function: FUN_1001d730 at 1001d730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d730(void)

{
  if (7 < DAT_10029e00) {
    operator_delete(DAT_10029dec);
  }
  DAT_10029e00 = 7;
  _DAT_10029dfc = 0;
  DAT_10029dec = (void *)((uint)DAT_10029dec & 0xffff0000);
  return;
}



// Function: FUN_1001d770 at 1001d770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d770(void)

{
  if (7 < DAT_10029e1c) {
    operator_delete(DAT_10029e08);
  }
  DAT_10029e1c = 7;
  _DAT_10029e18 = 0;
  DAT_10029e08 = (void *)((uint)DAT_10029e08 & 0xffff0000);
  return;
}



// Function: FUN_1001d7b0 at 1001d7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d7b0(void)

{
  if (7 < DAT_10029e38) {
    operator_delete(DAT_10029e24);
  }
  DAT_10029e38 = 7;
  _DAT_10029e34 = 0;
  DAT_10029e24 = (void *)((uint)DAT_10029e24 & 0xffff0000);
  return;
}



// Function: FUN_1001d7f0 at 1001d7f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d7f0(void)

{
  if (7 < DAT_10029e54) {
    operator_delete(DAT_10029e40);
  }
  DAT_10029e54 = 7;
  _DAT_10029e50 = 0;
  DAT_10029e40 = (void *)((uint)DAT_10029e40 & 0xffff0000);
  return;
}



// Function: FUN_1001d830 at 1001d830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d830(void)

{
  if (7 < DAT_10029e70) {
    operator_delete(DAT_10029e5c);
  }
  DAT_10029e70 = 7;
  _DAT_10029e6c = 0;
  DAT_10029e5c = (void *)((uint)DAT_10029e5c & 0xffff0000);
  return;
}



// Function: FUN_1001d870 at 1001d870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d870(void)

{
  if (7 < DAT_10029e8c) {
    operator_delete(DAT_10029e78);
  }
  DAT_10029e8c = 7;
  _DAT_10029e88 = 0;
  DAT_10029e78 = (void *)((uint)DAT_10029e78 & 0xffff0000);
  return;
}



// Function: FUN_1001d8b0 at 1001d8b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d8b0(void)

{
  if (7 < DAT_10029ea8) {
    operator_delete(DAT_10029e94);
  }
  DAT_10029ea8 = 7;
  _DAT_10029ea4 = 0;
  DAT_10029e94 = (void *)((uint)DAT_10029e94 & 0xffff0000);
  return;
}



// Function: FUN_1001d8f0 at 1001d8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d8f0(void)

{
  if (7 < DAT_10029ec4) {
    operator_delete(DAT_10029eb0);
  }
  DAT_10029ec4 = 7;
  _DAT_10029ec0 = 0;
  DAT_10029eb0 = (void *)((uint)DAT_10029eb0 & 0xffff0000);
  return;
}



// Function: FUN_1001d930 at 1001d930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d930(void)

{
  if (7 < DAT_10029ee0) {
    operator_delete(DAT_10029ecc);
  }
  DAT_10029ee0 = 7;
  _DAT_10029edc = 0;
  DAT_10029ecc = (void *)((uint)DAT_10029ecc & 0xffff0000);
  return;
}



// Function: FUN_1001d970 at 1001d970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d970(void)

{
  if (7 < DAT_10029efc) {
    operator_delete(DAT_10029ee8);
  }
  DAT_10029efc = 7;
  _DAT_10029ef8 = 0;
  DAT_10029ee8 = (void *)((uint)DAT_10029ee8 & 0xffff0000);
  return;
}



// Function: FUN_1001d9b0 at 1001d9b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d9b0(void)

{
  if (7 < DAT_10029f18) {
    operator_delete(DAT_10029f04);
  }
  DAT_10029f18 = 7;
  _DAT_10029f14 = 0;
  DAT_10029f04 = (void *)((uint)DAT_10029f04 & 0xffff0000);
  return;
}



// Function: FUN_1001d9f0 at 1001d9f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d9f0(void)

{
  if (7 < DAT_10029f34) {
    operator_delete(DAT_10029f20);
  }
  DAT_10029f34 = 7;
  _DAT_10029f30 = 0;
  DAT_10029f20 = (void *)((uint)DAT_10029f20 & 0xffff0000);
  return;
}



// Function: FUN_1001da30 at 1001da30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001da30(void)

{
  if (7 < DAT_10029f50) {
    operator_delete(DAT_10029f3c);
  }
  DAT_10029f50 = 7;
  _DAT_10029f4c = 0;
  DAT_10029f3c = (void *)((uint)DAT_10029f3c & 0xffff0000);
  return;
}



// Function: FUN_1001da70 at 1001da70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001da70(void)

{
  if (7 < DAT_10029f6c) {
    operator_delete(DAT_10029f58);
  }
  DAT_10029f6c = 7;
  _DAT_10029f68 = 0;
  DAT_10029f58 = (void *)((uint)DAT_10029f58 & 0xffff0000);
  return;
}



// Function: FUN_1001dab0 at 1001dab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dab0(void)

{
  if (7 < DAT_10029f88) {
    operator_delete(DAT_10029f74);
  }
  DAT_10029f88 = 7;
  _DAT_10029f84 = 0;
  DAT_10029f74 = (void *)((uint)DAT_10029f74 & 0xffff0000);
  return;
}



// Function: FUN_1001dae5 at 1001dae5

void FUN_1001dae5(void)

{
  FUN_10018f67((int *)&DAT_1002a080);
  return;
}



// Function: FUN_1001daef at 1001daef

void FUN_1001daef(void)

{
  FUN_10019179(0x1002a0ac);
  return;
}



// Function: FUN_1001daf9 at 1001daf9

void FUN_1001daf9(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_1002a0e4,DAT_1002a0b0);
  RemoveAll((undefined4 *)&DAT_1002a104);
  return;
}



