/*
 * Decompiled from: ImmobilizerInstallation.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void FUN_10001000(IRpcStubBuffer *param_1)

{
  NdrCStdStubBuffer2_Release(param_1,(IPSFactoryBuffer *)&DAT_100344f0);
  return;
}



// Function: FUN_10001020 at 10001020

undefined4 __cdecl FUN_10001020(int *param_1,int *param_2)

{
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    return 1;
  }
  return 0;
}



// Function: FUN_10001060 at 10001060

bool __cdecl FUN_10001060(byte *param_1,byte *param_2)

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



// Function: FUN_100010d0 at 100010d0

void __fastcall FUN_100010d0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019409;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001120 at 10001120

exception * __thiscall FUN_10001120(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019439;
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



// Function: FUN_10001180 at 10001180

void __cdecl FUN_10001180(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 * 2);
  return;
}



// Function: FUN_100011a0 at 100011a0

void FUN_100011a0(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1002a5e8);
}



// Function: FUN_100011c0 at 100011c0

uint __fastcall FUN_100011c0(LPCRITICAL_SECTION param_1)

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



// Function: FUN_100011f0 at 100011f0

void __fastcall FUN_100011f0(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10001210 at 10001210

void __fastcall FUN_10001210(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001220 at 10001220

undefined4 __fastcall FUN_10001220(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001230 at 10001230

int FUN_10001230(LPCWSTR param_1)

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



// Function: FUN_10001290 at 10001290

undefined4 __thiscall FUN_10001290(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10034514 = *param_3;
    DAT_10034518 = param_3[1];
    DAT_1003451c = param_3[2];
    DAT_10034520 = param_3[3];
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
  piVar2 = DAT_10034944;
  if (DAT_10034944 < DAT_10034948) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_10034948);
  }
  return 0;
}



// Function: FUN_10001310 at 10001310

void __fastcall FUN_10001310(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x2c);
  if (piVar3 != (int *)0x0) {
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      piVar2 = (int *)piVar3[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar3[4] = 0;
      (*(code *)piVar3[8])(0);
      piVar3 = piVar3 + 9;
      iVar1 = *piVar3;
    }
  }
  piVar3 = DAT_10034944;
  if (DAT_10034944 < DAT_10034948) {
    do {
      if (*piVar3 != 0) {
        (**(code **)(*piVar3 + 0x20))(0);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 < DAT_10034948);
  }
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar3 = *(int **)(param_1 + 0x28);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_100013b0 at 100013b0

undefined4 FUN_100013b0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001290(&DAT_1003455c,(int *)&PTR_DAT_10031160,param_1,(undefined4 *)&DAT_10028320);
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    FUN_10001310(0x1003455c);
  }
  return 1;
}



// Function: DllCanUnloadNow at 10001400

HRESULT DllCanUnloadNow(void)

{
                    /* 0x1400  1  DllCanUnloadNow */
  return (uint)(DAT_10034564 != 0);
}



// Function: FUN_10001420 at 10001420

void __fastcall FUN_10001420(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019468;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_100344b0 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001470 at 10001470

undefined4 * __fastcall FUN_10001470(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}



// Function: FUN_10001480 at 10001480

undefined4 * __fastcall FUN_10001480(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100194e8;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10012bc0((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0xe] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0xf] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x19] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x1a] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2a] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2c] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2d] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x47] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  (**(code **)(*DAT_10034510 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001530 at 10001530

void __cdecl FUN_10001530(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

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



// Function: FUN_100015f0 at 100015f0

void __cdecl FUN_100015f0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

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



// Function: FUN_100016b0 at 100016b0

uint __cdecl FUN_100016b0(HMODULE param_1,HRSRC param_2,uint param_3)

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



// Function: FUN_10001720 at 10001720

DWORD FUN_10001720(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001740 at 10001740

int * __thiscall FUN_10001740(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: Attach at 10001770

/* Library Function - Single Match
    public: void __thiscall ATL::CComBSTR::Attach(wchar_t *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall ATL::CComBSTR::Attach(CComBSTR *this,wchar_t *param_1)

{
  if (*(wchar_t **)this != param_1) {
    Ordinal_6(*(wchar_t **)this);
    *(wchar_t **)this = param_1;
  }
  return;
}



// Function: FUN_10001790 at 10001790

void __fastcall FUN_10001790(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100017b0 at 100017b0

void __thiscall FUN_100017b0(void *this,undefined4 param_1,undefined4 param_2)

{
  if (this != (void *)0x0) {
    Ordinal_58((int)this + 4,param_1,param_2);
    return;
  }
  Ordinal_58(0,param_1,param_2);
  return;
}



// Function: FUN_100017f0 at 100017f0

void __thiscall FUN_100017f0(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_1000185a:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_1000185a;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_1000186f;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_1000186f;
      }
    }
    iVar2 = 1;
  }
LAB_1000186f:
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



// Function: FUN_100018a0 at 100018a0

LSTATUS __thiscall FUN_100018a0(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

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



// Function: FUN_10001920 at 10001920

void __fastcall FUN_10001920(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_10001970 at 10001970

uint __cdecl FUN_10001970(uint *param_1)

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



// Function: FUN_10001a10 at 10001a10

uint __cdecl FUN_10001a10(int param_1,int param_2)

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



// Function: FUN_10001a80 at 10001a80

int __cdecl FUN_10001a80(uint param_1,ushort *param_2,int *param_3)

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



// Function: FUN_10001ad0 at 10001ad0

int FUN_10001ad0(undefined4 param_1,int param_2)

{
  return (uint)(param_2 == 0) * 2 + -0x7fffbfff;
}



// Function: FUN_10001af0 at 10001af0

undefined4 FUN_10001af0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x68;
  }
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar2 + 0x6c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar2 + 0x6c) = 0;
      return 0;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x6c) != 0) {
      return 0x8000ffff;
    }
    *(int **)(iVar2 + 0x6c) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
  }
  return 0;
}



// Function: FUN_10001b50 at 10001b50

undefined4 FUN_10001b50(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019490;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_1 + -0x68;
  }
  if (param_3 != 0) {
    ExceptionList = &local_10;
    if ((*(int *)(iVar5 + 0x70) != 0) && (*(int *)(iVar5 + 0x74) != 0)) {
      uVar4 = 0;
      if (*(int *)(iVar5 + 0x74) != 0) {
        do {
          piVar1 = *(int **)(*(int *)(iVar5 + 0x70) + uVar4 * 4);
          (**(code **)(*piVar1 + 8))(piVar1);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(iVar5 + 0x74));
      }
      operator_delete__(*(void **)(iVar5 + 0x70));
    }
    *(undefined4 *)(iVar5 + 0x70) = 0;
    local_8 = 0;
    pvVar2 = operator_new__(-(uint)((int)((ulonglong)param_2 * 4 >> 0x20) != 0) |
                            (uint)((ulonglong)param_2 * 4));
    *(void **)(iVar5 + 0x70) = pvVar2;
    local_8 = 0xffffffff;
    uVar3 = FUN_10001c23();
    return uVar3;
  }
  return 0x80004003;
}



// Function: Catch@10001c10 at 10001c10

undefined * Catch_10001c10(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10001c1d;
}



// Function: FUN_10001c23 at 10001c23

undefined4 FUN_10001c23(void)

{
  int *piVar1;
  uint unaff_EBX;
  int unaff_EBP;
  uint uVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x70) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  uVar2 = 0;
  if (unaff_EBX != 0) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EBP + 0x10) + uVar2 * 4);
      (**(code **)(*piVar1 + 4))(piVar1);
      *(undefined4 *)(*(int *)(unaff_EDI + 0x70) + uVar2 * 4) =
           *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + uVar2 * 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < unaff_EBX);
  }
  *(uint *)(unaff_EDI + 0x74) = unaff_EBX;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10001c80 at 10001c80

undefined4 FUN_10001c80(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x68;
  }
  if (*(HWND *)(iVar1 + 0x40) == (HWND)0x0) {
    return 0x8000ffff;
  }
  ShowWindow(*(HWND *)(iVar1 + 0x40),param_2);
  return 0;
}



// Function: FUN_10001cc0 at 10001cc0

undefined4 FUN_10001cc0(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x68;
  }
  if (*(HWND *)(iVar1 + 0x40) == (HWND)0x0) {
    return 0x8000ffff;
  }
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  MoveWindow(*(HWND *)(iVar1 + 0x40),*param_2,param_2[1],param_2[2] - *param_2,
             param_2[3] - param_2[1],1);
  return 0;
}



// Function: FUN_10001d20 at 10001d20

bool FUN_10001d20(int param_1)

{
  if (param_1 != 0) {
    return *(int *)(param_1 + 0x28) == 0;
  }
  return iRam00000090 == 0;
}



// Function: FUN_10001d60 at 10001d60

undefined4 FUN_10001d60(void)

{
  return 0;
}



// Function: FUN_10001d70 at 10001d70

bool FUN_10001d70(int param_1,LPMSG param_2)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x68;
  }
  uVar1 = param_2->message;
  if (((uVar1 < 0x100) || (0x109 < uVar1)) && ((uVar1 < 0x200 || (0x20d < uVar1)))) {
    return true;
  }
  BVar2 = IsDialogMessageW(*(HWND *)(iVar3 + 0x40),param_2);
  return (bool)('\x01' - (BVar2 != 0));
}



// Function: FUN_10001dc0 at 10001dc0

void __cdecl FUN_10001dc0(wchar_t *param_1,ushort param_2,uint *param_3,uint *param_4)

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
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
      FUN_100015f0(local_64.lfFaceName,0x20,param_1,0xffffffff);
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



// Function: FUN_10001f30 at 10001f30

void FUN_10001f30(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_100349a0);
    InterlockedExchange(&DAT_1003496c,param_1);
    DAT_10034968 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_100349a0);
  }
  return;
}



// Function: FUN_10001f70 at 10001f70

void __cdecl FUN_10001f70(int param_1)

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



// Function: FUN_10001fd0 at 10001fd0

undefined4 FUN_10001fd0(void)

{
  return DAT_1003496c;
}



// Function: FUN_10001fe0 at 10001fe0

uint __thiscall FUN_10001fe0(void *this,ushort *param_1,uint param_2,uint param_3)

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
LAB_10002064:
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
            if (uVar6 == 0) goto LAB_10002064;
          }
          if ((-(uint)(*puVar3 < *puVar5) & 0xfffffffe) == 0xffffffff) goto LAB_10002064;
        }
        puVar3 = (ushort *)FUN_10001470((undefined4 *)this);
        if (puVar7 == puVar3) break;
        puVar7 = puVar7 + -1;
      } while( true );
    }
    uVar6 = 0xffffffff;
  }
  return uVar6;
}



// Function: FUN_100020c0 at 100020c0

undefined4 FUN_100020c0(int param_1)

{
  *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
  return *(undefined4 *)(param_1 + 0x130);
}



// Function: FUN_100020e0 at 100020e0

undefined4 FUN_100020e0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x130);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0x130);
  if ((*piVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 4))(1);
  }
  return uVar2;
}



// Function: FUN_10002110 at 10002110

undefined4 * __fastcall FUN_10002110(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019548;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000c090(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  param_1[0x11] = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  param_1[0x13] = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  (**(code **)(*DAT_10034510 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002190 at 10002190

undefined4 __fastcall FUN_10002190(int param_1)

{
  BOOL BVar1;
  
  if ((DAT_1003496c != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) {
    BVar1 = FreeLibrary(DAT_1003496c);
    if (BVar1 != 1) {
      return 0x80004005;
    }
  }
  return 0;
}



// Function: FUN_100021c0 at 100021c0

undefined2 __fastcall FUN_100021c0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_10026088 + (uVar1 & 0xffff) * 2);
}



// Function: FUN_100021e0 at 100021e0

undefined4 FUN_100021e0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10002200 at 10002200

void FUN_10002200(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x50));
  return;
}



// Function: FUN_10002220 at 10002220

LONG FUN_10002220(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x50));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_10002250 at 10002250

void __fastcall FUN_10002250(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100194b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10012d20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100022a0 at 100022a0

undefined4 * __thiscall FUN_100022a0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100194e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10012bc0((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 4) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x38) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x3c) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 100) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x68) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0xa8) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0xb0) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0xb4) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x11c) =
       ATL::CComContainedObject<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined4 *)((int)this + 0x130) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002350 at 10002350

void FUN_10002350(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x130) + 4))(*(int **)(param_1 + 0x130));
  return;
}



// Function: FUN_10002370 at 10002370

void FUN_10002370(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x130) + 8))(*(int **)(param_1 + 0x130));
  return;
}



// Function: FUN_10002390 at 10002390

void FUN_10002390(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x130))(*(undefined4 **)(param_1 + 0x130),param_2,param_3)
  ;
  return;
}



// Function: FUN_100023b0 at 100023b0

void FUN_100023b0(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  HANDLE hProcess;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  piVar2 = (int *)Ordinal_44(&DAT_1003499c);
  if (piVar2 == (int *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*piVar2 + 8);
  piVar2[1] = (int)param_1;
  iVar3 = (*pcVar1)();
  if (piVar2[5] == 0) {
    pvVar4 = __AllocStdCallThunk_cmn();
    piVar2[5] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_10002417;
  }
  lpBaseAddress = (undefined4 *)piVar2[5];
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = piVar2;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = (iVar3 - (int)lpBaseAddress) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
LAB_10002417:
  pcVar1 = (code *)piVar2[5];
  SetWindowLongW(param_1,4,(LONG)pcVar1);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10002440 at 10002440

undefined4 __thiscall FUN_10002440(void *this,undefined4 param_1,undefined4 param_2,int param_3)

{
  if (*(int *)((int)this + 0x14) != 0) {
    if (*(int *)((int)this + 8) != 0) {
      *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)((int)this + 0x24);
      *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)((int)this + 0x28);
    }
    if (*(int *)((int)this + 4) != 0) {
      *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)((int)this + 0x2c);
      *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)((int)this + 0x30);
    }
    if (*(int *)((int)this + 0xc) != 0) {
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)((int)this + 0x34);
      *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)((int)this + 0x38);
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)((int)this + 0x3c);
      *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)((int)this + 0x40);
    }
  }
  return 0;
}



// Function: FUN_100024a0 at 100024a0

void * __cdecl FUN_100024a0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019519;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1002a6f8);
}



// Function: FUN_10002530 at 10002530

exception * __thiscall FUN_10002530(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019439;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10002590 at 10002590

void __fastcall FUN_10002590(int *param_1)

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



// Function: FUN_100025c0 at 100025c0

uint __thiscall FUN_100025c0(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_10002628:
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
      goto LAB_10002628;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10002650 at 10002650

void __fastcall FUN_10002650(int param_1)

{
  LPRECT lpRect;
  HWND hWnd;
  int iVar1;
  int iVar2;
  
  iVar2 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar2 + 0x40);
  lpRect = (LPRECT)(param_1 + 0x44);
  GetClientRect(hWnd,lpRect);
  InvalidateRect(hWnd,lpRect,1);
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x58);
  lpRect->left = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x54);
  *(int *)(param_1 + 0x48) = iVar2 - iVar1;
  UpdateWindow(hWnd);
  return;
}



// Function: FUN_100026a0 at 100026a0

void FUN_100026a0(void)

{
  return;
}



// Function: FUN_100026b0 at 100026b0

void __fastcall FUN_100026b0(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_100026c0 at 100026c0

undefined4 * __thiscall FUN_100026c0(void *this,byte param_1)

{
  *(undefined ***)this = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100026f0 at 100026f0

void FUN_100026f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002390(param_1 + -0x68,param_2,param_3);
  return;
}



// Function: FUN_10002700 at 10002700

void __thiscall FUN_10002700(void *this,byte param_1)

{
  FUN_100027d0((void *)((int)this + -0x3c),param_1);
  return;
}



// Function: FUN_10002710 at 10002710

void __fastcall FUN_10002710(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100194e8;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0xe] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0xf] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x19] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x1a] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2a] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2c] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x2d] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x47] = ATL::CComObject<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 0;
  param_1[0x4c] = 0xc0000001;
  (**(code **)(*DAT_10034510 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10012d20((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100027d0 at 100027d0

undefined4 * __thiscall FUN_100027d0(void *this,byte param_1)

{
  FUN_10002710((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002800 at 10002800

void __thiscall FUN_10002800(void *this,byte param_1)

{
  FUN_10002810((void *)((int)this + -0x38),param_1);
  return;
}



// Function: FUN_10002810 at 10002810

void * __thiscall FUN_10002810(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100194e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10012d20((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002870 at 10002870

void FUN_10002870(int param_1)

{
  FUN_10002350(param_1 + -0xb0);
  return;
}



// Function: FUN_10002880 at 10002880

void __thiscall FUN_10002880(void *this,byte param_1)

{
  FUN_10002810((void *)((int)this + -0x3c),param_1);
  return;
}



// Function: FUN_10002890 at 10002890

void FUN_10002890(int param_1)

{
  FUN_100020e0(param_1 + -100);
  return;
}



// Function: FUN_100028a0 at 100028a0

void __thiscall FUN_100028a0(void *this,byte param_1)

{
  FUN_100027d0((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_100028b0 at 100028b0

void __thiscall FUN_100028b0(void *this,byte param_1)

{
  FUN_100027d0((void *)((int)this + -0x11c),param_1);
  return;
}



// Function: FUN_100028c0 at 100028c0

void FUN_100028c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002390(param_1 + -0xb0,param_2,param_3);
  return;
}



// Function: FUN_100028d0 at 100028d0

void FUN_100028d0(int param_1)

{
  FUN_100020e0(param_1 + -0x68);
  return;
}



// Function: FUN_100028e0 at 100028e0

void FUN_100028e0(int param_1)

{
  FUN_10002220(param_1 + -0xc);
  return;
}



// Function: FUN_100028f0 at 100028f0

void FUN_100028f0(int param_1)

{
  FUN_10002370(param_1 + -100);
  return;
}



// Function: FUN_10002900 at 10002900

void __thiscall FUN_10002900(void *this,byte param_1)

{
  FUN_10002810((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10002910 at 10002910

void __thiscall FUN_10002910(void *this,byte param_1)

{
  FUN_10002810((void *)((int)this + -0x11c),param_1);
  return;
}



// Function: FUN_10002920 at 10002920

void FUN_10002920(int param_1)

{
  FUN_10002220(param_1 + -0x4c);
  return;
}



// Function: FUN_10002930 at 10002930

void __thiscall FUN_10002930(void *this,byte param_1)

{
  FUN_100027d0((void *)((int)this + -0x68),param_1);
  return;
}



// Function: FUN_10002940 at 10002940

void FUN_10002940(int param_1)

{
  FUN_100020c0(param_1 + -100);
  return;
}



// Function: FUN_10002950 at 10002950

void FUN_10002950(int param_1)

{
  FUN_10002370(param_1 + -0x68);
  return;
}



// Function: FUN_10002960 at 10002960

void __thiscall FUN_10002960(void *this,byte param_1)

{
  FUN_10002970((void *)((int)this + -0x10),param_1);
  return;
}



// Function: FUN_10002970 at 10002970

undefined4 * __thiscall FUN_10002970(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019548;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0xc) =
       ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x10) =
       ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x44) =
       ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x4c) =
       ATL::CComObject<class_CImmobilizerInstallationLogicImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x50) = 0xc0000001;
  (**(code **)(*DAT_10034510 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000bf40((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002a10 at 10002a10

void FUN_10002a10(int param_1)

{
  FUN_100020c0(param_1 + -0x68);
  return;
}



// Function: FUN_10002a20 at 10002a20

void __thiscall FUN_10002a20(void *this,byte param_1)

{
  FUN_10002810((void *)((int)this + -0x68),param_1);
  return;
}



// Function: FUN_10002a30 at 10002a30

void FUN_10002a30(int param_1)

{
  FUN_10002200(param_1 + -0xc);
  return;
}



// Function: FUN_10002a40 at 10002a40

void FUN_10002a40(int param_1)

{
  FUN_10002350(param_1 + -100);
  return;
}



// Function: FUN_10002a50 at 10002a50

void FUN_10002a50(int param_1)

{
  FUN_100020e0(param_1 + -0xb0);
  return;
}



// Function: FUN_10002a60 at 10002a60

void FUN_10002a60(int param_1)

{
  FUN_10002200(param_1 + -0x4c);
  return;
}



// Function: FUN_10002a70 at 10002a70

void FUN_10002a70(int param_1)

{
  FUN_10002350(param_1 + -0x68);
  return;
}



// Function: FUN_10002a80 at 10002a80

void FUN_10002a80(int param_1)

{
  FUN_10002370(param_1 + -0xb0);
  return;
}



// Function: FUN_10002a90 at 10002a90

void FUN_10002a90(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002390(param_1 + -100,param_2,param_3);
  return;
}



// Function: FUN_10002aa0 at 10002aa0

void __thiscall FUN_10002aa0(void *this,byte param_1)

{
  FUN_100027d0((void *)((int)this + -0x38),param_1);
  return;
}



// Function: FUN_10002ab0 at 10002ab0

void FUN_10002ab0(int param_1)

{
  FUN_100020c0(param_1 + -0xb0);
  return;
}



// Function: FUN_10002ac0 at 10002ac0

void __fastcall FUN_10002ac0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019578;
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



// Function: FUN_10002b10 at 10002b10

int FUN_10002b10(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
      goto LAB_10002bd3;
    }
    else if ((uVar5 == 0x110) || ((0x131 < uVar5 && (uVar5 < 0x139)))) goto LAB_10002bd3;
    piVar7 = piVar6;
    if ((*(byte *)(piVar4 + 7) & 1) == 0) {
      SetWindowLongW((HWND)piVar4[1],0,(LONG)param_1);
    }
  }
LAB_10002bd3:
  if (((piVar4[7] & 1U) != 0) && (piVar4[6] == 0)) {
    iVar2 = piVar4[1];
    piVar4[7] = piVar4[7] & 0xfffffffe;
    pcVar3 = *(code **)(*piVar4 + 0xc);
    piVar4[1] = 0;
    (*pcVar3)(iVar2);
  }
  return (int)piVar7;
}



// Function: FUN_10002c10 at 10002c10

void __cdecl FUN_10002c10(int *param_1,size_t param_2,void *param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
  if ((int)param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
  if (param_3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_10002c78;
    pvVar1 = calloc(param_2,2);
  }
  else {
    if ((int)param_2 <= param_4) {
      free(pvVar1);
LAB_10002c78:
      *param_1 = (int)param_3;
      goto LAB_10002c7a;
    }
    pvVar1 = _recalloc(pvVar1,param_2,2);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  *param_1 = (int)pvVar1;
LAB_10002c7a:
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  }
  return;
}



// Function: FUN_10002cb0 at 10002cb0

int * __thiscall FUN_10002cb0(void *this,int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80070057);
  }
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = Ordinal_4(0,param_1);
    *(int *)this = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_10002cf0 at 10002cf0

void __thiscall FUN_10002cf0(void *this,GUID *param_1)

{
  int iVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  iVar1 = Ordinal_2(local_88);
  *(int *)this = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002d50 at 10002d50

int __thiscall FUN_10002d50(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  iVar2 = Ordinal_7(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
                    /* WARNING: Load size is inaccurate */
  param_1 = (undefined4 *)0x0;
  iVar2 = Ordinal_313(*this,uVar1,&param_1);
  if (-1 < iVar2) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(undefined4 **)this = param_1;
  }
  return iVar2;
}



// Function: FUN_10002da0 at 10002da0

undefined4 __thiscall FUN_10002da0(void *this,void *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 == (void *)0x0) || ((*this != 0 && (param_2 == 0)))) {
    return 0;
  }
  if ((int)param_2 < 0) {
    return 0x80070057;
  }
  iVar1 = Ordinal_7(*this);
  if (-iVar1 - 1U < param_2) {
    return 0x80070216;
  }
  iVar4 = param_2 + iVar1;
  if (iVar4 < 0) {
    return 0x80070216;
  }
  if (-1 < iVar1) {
    pvVar2 = (void *)Ordinal_4(0,iVar4);
    if (pvVar2 == (void *)0x0) {
      return 0x8007000e;
    }
                    /* WARNING: Load size is inaccurate */
    iVar3 = Ordinal_7(*this);
    if (iVar3 != 0) {
                    /* WARNING: Load size is inaccurate */
      FUN_10001530(pvVar2,iVar4 * 2,*this,iVar1 * 2);
    }
    FUN_10001530((void *)((int)pvVar2 + iVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar2 + iVar4 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar2;
    return 0;
  }
  return 0x80070216;
}



// Function: FUN_10002ed0 at 10002ed0

int __fastcall FUN_10002ed0(int param_1)

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
  DAT_10034510 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_10034504 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10002f40 at 10002f40

void __fastcall FUN_10002f40(int param_1)

{
  int *piVar1;
  
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



// Function: FUN_10002f90 at 10002f90

void __fastcall FUN_10002f90(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100195a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4),DAT_100344b0 ^ (uint)&stack0xfffffffc);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003010 at 10003010

void __fastcall FUN_10003010(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10003030 at 10003030

undefined4 * __thiscall FUN_10003030(void *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100195db;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
      FUN_100191e0(0x8007000e);
    }
  }
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_100191e0(0x8007000e);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100030e0 at 100030e0

undefined4 __thiscall FUN_100030e0(void *this,int *param_1)

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
  puStack_c = &LAB_10019613;
  local_10 = ExceptionList;
  uStack_38 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
      local_20 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_10001920,FUN_10001420);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_100031c1();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_100031c1();
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



// Function: Catch@100031b1 at 100031b1

undefined * Catch_100031b1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100031be;
}



// Function: FUN_100031c1 at 100031c1

undefined4 FUN_100031c1(void)

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



// Function: FUN_100032d0 at 100032d0

void FUN_100032d0(int param_1)

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
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10001420);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10003330 at 10003330

void __cdecl FUN_10003330(int *param_1,undefined4 *param_2)

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
  puStack_c = &LAB_1001963b;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_410 = param_2;
  *param_2 = 0;
  if ((((param_1 == (int *)0x0) ||
       (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_40c,2,&local_404,local_14), iVar1 < 0))
      || (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_414,4,&local_404), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_408,4,&local_404), iVar1 < 0))
  goto LAB_10003529;
  if (local_408 != 0) {
    FUN_10002cb0(&local_400,local_408);
    pvVar2 = local_400;
    local_8 = 0;
    iVar1 = Ordinal_7(local_400);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      Ordinal_6(pvVar2);
      goto LAB_10003529;
    }
    memset(pvVar2,0,local_408 * 2 + 2);
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,pvVar2,local_408 * 2,&local_404);
    if (iVar1 < 0) {
      local_8 = 0xffffffff;
      Ordinal_6(pvVar2);
      goto LAB_10003529;
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
LAB_10003529:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003550 at 10003550

undefined4 __thiscall FUN_10003550(void *this,int param_1)

{
  if (param_1 == 1) {
    return *(undefined4 *)((int)this + 0x30);
  }
  if (param_1 != 2) {
    return 0;
  }
  return *(undefined4 *)((int)this + 0x34);
}



// Function: FUN_10003570 at 10003570

undefined4 FUN_10003570(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x68;
  }
  if (*(HWND *)(iVar2 + 0x40) != (HWND)0x0) {
    BVar1 = IsWindow(*(HWND *)(iVar2 + 0x40));
    if (BVar1 != 0) {
      DestroyWindow(*(HWND *)(iVar2 + 0x40));
    }
    *(undefined4 *)(iVar2 + 0x40) = 0;
  }
  return 0;
}



// Function: FUN_100035b0 at 100035b0

undefined4 FUN_100035b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10026760,param_1 + 4);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_100035e0 at 100035e0

uint __thiscall FUN_100035e0(void *this,ushort *param_1,uint param_2,uint param_3)

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
          if (iVar5 == 0) goto LAB_1000363c;
        }
        if (puVar2 == (ushort *)0x0) break;
        puVar6 = puVar2;
        puVar8 = param_1;
        uVar3 = param_3;
        if (param_3 == 0) {
LAB_10003665:
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
          if (uVar3 == 0) goto LAB_10003665;
        }
        if ((-(uint)(*puVar6 < *puVar8) & 0xfffffffe) == 0xffffffff) goto LAB_10003665;
        iVar5 = (int)puVar2 - (int)puVar1;
        puVar1 = puVar2 + 1;
      }
    }
LAB_1000363c:
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_100036a0 at 100036a0

int __thiscall FUN_100036a0(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  Ordinal_43(&DAT_1003499c,(int)this + 8,this);
  *(undefined1 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  iVar1 = Ordinal_37(DAT_1003496c,0x65,param_1,FUN_100023b0,param_2);
  if ((*(int *)((int)this + 0x24) < 0) && (iVar1 != 0)) {
    DestroyWindow(*(HWND *)((int)this + 4));
    SetLastError(*(DWORD *)((int)this + 0x24));
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10003710 at 10003710

void __thiscall
FUN_10003710(void *this,HWND param_1,int *param_2,LPCWSTR param_3,DWORD param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  HWND pHVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = &DAT_1003198c;
  }
  pHVar1 = CreateWindowExW(param_5,L"AtlAxWinLic100",param_3,param_4,*param_2,param_2[1],
                           param_2[2] - *param_2,param_2[3] - param_2[1],param_1,param_6,
                           DAT_10034968,param_7);
  *(HWND *)this = pHVar1;
  return;
}



// Function: FUN_10003770 at 10003770

void __fastcall FUN_10003770(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003790 at 10003790

int FUN_10003790(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019670;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x15c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10001480(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_1000383d();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_1000383d();
  return iVar2;
}



// Function: Catch@10003827 at 10003827

undefined * Catch_10003827(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003834;
}



// Function: FUN_1000383d at 1000383d

int FUN_1000383d(void)

{
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI != 0) {
      (**(code **)unaff_ESI[1])(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10003880 at 10003880

DWORD FUN_10003880(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019690;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x70);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10002110(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10003927();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10003927();
  return DVar2;
}



// Function: Catch@10003914 at 10003914

undefined * Catch_10003914(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003921;
}



// Function: FUN_10003927 at 10003927

DWORD FUN_10003927(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (unaff_EDI == (undefined4 *)0x0) goto LAB_1000397e;
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 0x15),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_10003956;
  }
  else {
LAB_10003956:
    *(undefined1 *)(unaff_EDI + 0x1b) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = (**(code **)*unaff_EDI)();
      if (unaff_ESI == 0) goto LAB_1000397e;
    }
  }
  (**(code **)unaff_EDI[4])(1);
LAB_1000397e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_100039a0 at 100039a0

void FUN_100039a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_100263a8,param_2,param_3);
  return;
}



// Function: FUN_100039c0 at 100039c0

undefined4 * __thiscall FUN_100039c0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100196bb;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CImmobilizerInstallationPageImpl>::vftable;
  FUN_100022a0((void *)((int)this + 8),param_1);
  local_8 = 0;
  (**(code **)(*DAT_10034510 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003a40 at 10003a40

undefined4 FUN_10003a40(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10003a50 at 10003a50

int FUN_10003a50(int *param_1)

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



// Function: FUN_10003a80 at 10003a80

undefined4 FUN_10003a80(int *param_1,int *param_2,undefined4 *param_3)

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
  uVar1 = Ordinal_32(param_1 + 2,&PTR_DAT_100263a8,param_2,param_3);
  return uVar1;
}



// Function: FUN_10003af0 at 10003af0

void FUN_10003af0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10026584,param_2,param_3);
  return;
}



// Function: FUN_10003b10 at 10003b10

undefined4 * __thiscall FUN_10003b10(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100196f3;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_10034510 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10012d20((int)this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003ba0 at 10003ba0

void __thiscall FUN_10003ba0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019710;
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
  FUN_100024a0((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10003c60();
  return;
}



// Function: Catch@10003c2e at 10003c2e

undefined * Catch_10003c2e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100024a0((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10003c57;
}



// Function: FUN_10003c60 at 10003c60

void FUN_10003c60(void)

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



// Function: Catch@10003cc1 at 10003cc1

void Catch_10003cc1(void)

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



// Function: FUN_10003cf0 at 10003cf0

int FUN_10003cf0(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0x110) {
    iVar1 = (**(code **)(*param_1 + 0x10))(0x65);
    if (iVar1 < 0) {
      param_1[9] = iVar1;
      if ((char)param_1[8] != '\0') {
        EndDialog((HWND)param_1[1],-1);
      }
      return 0;
    }
  }
  iVar1 = FUN_10002b10(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_10003d50 at 10003d50

void __thiscall FUN_10003d50(void *this)

{
  LPRECT lpRect;
  HWND hWnd;
  HWND hWnd_00;
  int iVar1;
  int iVar2;
  HDC hDC;
  undefined4 *in_stack_00000010;
  tagPAINTSTRUCT local_48;
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  iVar2 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar2 + 0x40);
  hDC = GetDC(hWnd);
  BeginPaint(hWnd,&local_48);
  if (((*(int *)((int)this + 0x1c) != 0) && (*(int *)((int)this + 0x18) != 0)) ||
     (*(int *)((int)this + 0x20) != 0)) {
    iVar2 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                    RTTI_Type_Descriptor,
                            &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
    hWnd_00 = *(HWND *)(iVar2 + 0x40);
    lpRect = (LPRECT)((int)this + 0x44);
    GetClientRect(hWnd_00,lpRect);
    InvalidateRect(hWnd_00,lpRect,1);
    iVar2 = *(int *)((int)this + 0x50);
    iVar1 = *(int *)((int)this + 0x58);
    lpRect->left = *(int *)((int)this + 0x4c) - *(int *)((int)this + 0x54);
    *(int *)((int)this + 0x48) = iVar2 - iVar1;
    UpdateWindow(hWnd_00);
    DrawFrameControl(hDC,lpRect,3,8);
    *(undefined4 *)((int)this + 0x1c) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
  }
  EndPaint(hWnd,&local_48);
  ReleaseDC(hWnd,hDC);
  *in_stack_00000010 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003e50 at 10003e50

void __fastcall FUN_10003e50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019743;
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



// Function: FUN_10003eb0 at 10003eb0

void __fastcall FUN_10003eb0(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_10003ed0 at 10003ed0

void FUN_10003ed0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100039a0(param_1 + -0x68,param_2,param_3);
  return;
}



// Function: FUN_10003ee0 at 10003ee0

void FUN_10003ee0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100039a0(param_1 + -0xb0,param_2,param_3);
  return;
}



// Function: FUN_10003ef0 at 10003ef0

void FUN_10003ef0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100039a0(param_1 + -100,param_2,param_3);
  return;
}



// Function: FUN_10003f00 at 10003f00

void FUN_10003f00(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003af0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10003f10 at 10003f10

void FUN_10003f10(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003af0(param_1 + -0x4c,param_2,param_3);
  return;
}



// Function: FUN_10003f20 at 10003f20

void __fastcall FUN_10003f20(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10003f40 at 10003f40

bool __thiscall FUN_10003f40(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019790;
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
    (**(code **)**this)(*this,&DAT_100283cc,&local_18,DAT_100344b0 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&DAT_100283cc,&local_14);
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



// Function: FUN_10004030 at 10004030

int FUN_10004030(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100197d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  iVar2 = Ordinal_61(&local_14,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar2) {
    if (param_4 != (int *)0x0) {
      iVar2 = *param_4;
      while (iVar2 != 0) {
        (**(code **)(*local_14 + 0xc))(local_14,iVar2,param_4[1]);
        piVar1 = param_4 + 2;
        param_4 = param_4 + 2;
        iVar2 = *piVar1;
      }
    }
    iVar2 = (**(code **)(*param_1 + 0x14))(local_14);
    if (-1 < iVar2) {
      iVar2 = Ordinal_23(DAT_10034968,param_2,param_3,0,local_14);
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10004100 at 10004100

void __fastcall FUN_10004100(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10004110 at 10004110

void __fastcall FUN_10004110(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10004120 at 10004120

HRESULT __thiscall FUN_10004120(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_100283bc,(LPUNKNOWN)0x0,1,(IID *)&DAT_100267f8,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_10004180 at 10004180

undefined4 FUN_10004180(void)

{
  return 0x80004005;
}



// Function: FUN_10004190 at 10004190

void FUN_10004190(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10026808);
  return;
}



// Function: FUN_100041b0 at 100041b0

undefined4 * __thiscall FUN_100041b0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019810;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 4) != 0) {
    if (*(int *)((int)this + 0xc) != 0) {
      Ordinal_64((undefined4 *)((int)this + 4),uVar2);
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    piVar1 = *(int **)((int)this + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
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



// Function: FUN_10004250 at 10004250

int FUN_10004250(int param_1,uint param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019858;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = Ordinal_56(param_1,param_2,&local_18,&local_14,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14 + 0x1c))(local_14,&param_1), -1 < iVar1)) {
    param_2 = param_2 & 0xffffff;
    iVar1 = Ordinal_68((int)&param_2 + 3);
    if (iVar1 < 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      goto LAB_10004361;
    }
    if (((param_2._3_1_ != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser"), pFVar2 == (FARPROC)0x0)) {
      pFVar2 = Ordinal_186_exref;
    }
    iVar1 = (*pFVar2)(param_1,(uint)*(ushort *)(param_1 + 0x18),(uint)*(ushort *)(param_1 + 0x1a),
                      *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
    (**(code **)(*local_14 + 0x30))(local_14,param_1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_10004361:
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10004380 at 10004380

void FUN_10004380(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  rsize_t rVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  wchar_t *pwVar4;
  undefined4 local_22c;
  wchar_t *local_228;
  int *local_224;
  char local_21d;
  wchar_t local_21c [259];
  undefined2 local_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100198c2;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_22c = 0;
  local_224 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = Ordinal_56(param_1,param_2,&local_22c,&local_224,local_14);
  if (-1 < iVar1) {
    pwVar4 = (wchar_t *)0x0;
    local_228 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar1 = (**(code **)(*local_224 + 0x24))(local_224,0xffffffff,0,0,0,&local_228);
    if ((-1 < iVar1) && (local_228 != (wchar_t *)0x0)) {
      rVar2 = Ordinal_7(local_228);
      FUN_100015f0(local_21c,0x104,local_228,rVar2);
      local_16 = 0;
      iVar1 = FUN_10001230(local_21c);
      local_21c[iVar1] = L'\0';
      pwVar4 = local_21c;
    }
    local_21d = '\0';
    iVar1 = Ordinal_68(&local_21d);
    if (iVar1 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_224 != (int *)0x0) {
        (**(code **)(*local_224 + 8))(local_224);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10004533;
    }
    if (local_21d == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule == (HMODULE)0x0) goto LAB_100044df;
      pFVar3 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      if (pFVar3 == (FARPROC)0x0) goto LAB_100044df;
    }
    else {
LAB_100044df:
      pFVar3 = Ordinal_163_exref;
    }
    (*pFVar3)(local_224,local_22c,pwVar4);
    local_8._0_1_ = 2;
    Ordinal_6(local_228);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_224 != (int *)0x0) {
    (**(code **)(*local_224 + 8))(local_224);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_22c);
LAB_10004533:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004560 at 10004560

int FUN_10004560(int param_1,int param_2,byte *param_3)

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
          (bVar2 = FUN_10001060(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
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
    iVar5 = FUN_10004380(*(undefined4 *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_100045f0 at 100045f0

int FUN_100045f0(int param_1,int param_2,byte *param_3)

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
          (bVar2 = FUN_10001060(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
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
    iVar5 = FUN_10004250(*(int *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_10004680 at 10004680

int __thiscall FUN_10004680(void *this,int *param_1,undefined4 param_2,int *param_3)

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
  puStack_c = &LAB_100198f8;
  local_10 = ExceptionList;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1003494c);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&DAT_100283cc,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1003494c);
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
  iVar4 = Ordinal_15(&DAT_1003493c,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: DllGetClassObject at 100047b0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x47b0  2  DllGetClassObject */
  iVar1 = FUN_10004680(&DAT_1003455c,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_100047c0 at 100047c0

void __fastcall FUN_100047c0(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_100047f0 at 100047f0

int * __thiscall FUN_100047f0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10004880 at 10004880

void __fastcall FUN_10004880(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001993e;
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



// Function: FUN_100048f0 at 100048f0

undefined4 FUN_100048f0(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_10004950 at 10004950

undefined4 FUN_10004950(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_10034510 + 4))();
    return 0;
  }
  (**(code **)(*DAT_10034510 + 8))();
  return 0;
}



// Function: FUN_10004980 at 10004980

undefined4 * __thiscall FUN_10004980(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001997e;
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



// Function: FUN_10004a00 at 10004a00

undefined * FUN_10004a00(void)

{
  return FUN_10003cf0;
}



// Function: FUN_10004a10 at 10004a10

undefined4 FUN_10004a10(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = param_1 + -0x1a;
  }
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  iVar1 = FUN_100036a0(piVar2 + 0xf,param_2,0);
  piVar2[0x10] = iVar1;
  (**(code **)(*param_1 + 0x24))(param_1,param_3);
  param_1[4] = param_3[2] - *param_3;
  param_1[5] = param_3[3] - param_3[1];
  return 0;
}



// Function: FUN_10004a70 at 10004a70

void __thiscall FUN_10004a70(void *this,LPCWSTR param_1)

{
  LPCWSTR *ppWVar1;
  int iVar2;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  HKEY local_434;
  undefined4 local_430;
  undefined4 local_42c;
  uint local_428;
  BYTE local_424 [520];
  BYTE local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100199b3;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_434 = (HKEY)0x0;
  local_430 = 0;
  local_42c = 0;
  local_8 = 1;
  local_21c[0] = '\0';
  local_21c[1] = '\0';
  memset(local_21c + 2,0,0x206);
  local_424[0] = '\0';
  local_424[1] = '\0';
  memset(local_424 + 2,0,0x206);
  local_428 = 0x208;
  ppWVar1 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar1 = &param_1;
  }
  iVar2 = FUN_100017f0(&local_434,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_100018a0(&local_434,L"XMLResource",local_21c,&local_428);
    local_428 = 0x208;
  }
  FUN_100018a0(&local_434,L"FriendlyName",local_424,&local_428);
  if ((iVar2 == 0) && (local_428 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(local_21c,in_stack_00000020);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_434 != (HKEY)0x0) {
    RegCloseKey(local_434);
    local_434 = (HKEY)0x0;
  }
  local_430 = 0;
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  param_1 = (LPCWSTR)((uint)param_1 & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004c10 at 10004c10

DWORD FUN_10004c10(int param_1,undefined4 param_2,undefined4 *param_3)

{
  DWORD DVar1;
  
  if (param_1 == 0) {
    DVar1 = FUN_10003880(0,param_2,param_3);
    return DVar1;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  return 0x80040110;
}



// Function: FUN_10004c50 at 10004c50

void __fastcall FUN_10004c50(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100199e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004ca0 at 10004ca0

int * FUN_10004ca0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019a1b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x164);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_100039c0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10004d59();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10004d59();
  return piVar1;
}



// Function: Catch@10004d44 at 10004d44

undefined * Catch_10004d44(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004d51;
}



// Function: FUN_10004d59 at 10004d59

int * FUN_10004d59(void)

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



// Function: FUN_10004da0 at 10004da0

int __thiscall FUN_10004da0(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  puStack_c = &LAB_10019a58;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  if (param_2 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  param_2 = (int *)0x0;
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  iVar3 = Ordinal_48(*this,&param_2,uVar2);
  if (-1 < iVar3) {
    iVar3 = (**(code **)*param_2)(param_2,param_1,piVar1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10004e50 at 10004e50

undefined4 __thiscall FUN_10004e50(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_10003f40(this,(undefined4 *)*param_1);
  if (!bVar1) {
    uVar2 = Ordinal_31(this,*param_1,&DAT_100268b8);
    return uVar2;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004e90 at 10004e90

int FUN_10004e90(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019a88;
  local_10 = ExceptionList;
  if (param_2 == 0) {
    return -0x7ff8ffa9;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar1 = FUN_10004030(param_1,param_2,param_3,param_4);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10004f10 at 10004f10

void FUN_10004f10(int *param_1,ushort param_2,undefined4 param_3,int *param_4)

{
  FUN_10004030(param_1,(uint)param_2,param_3,param_4);
  return;
}



// Function: FUN_10004f30 at 10004f30

void __fastcall FUN_10004f30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019abb;
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



// Function: FUN_10004fa0 at 10004fa0

undefined4 * __thiscall FUN_10004fa0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019abb;
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



// Function: FUN_10005020 at 10005020

void FUN_10005020(undefined4 param_1)

{
  FUN_10004030((int *)&DAT_1003455c,0x66,param_1,(int *)0x0);
  return;
}



// Function: FUN_10005040 at 10005040

void FUN_10005040(undefined4 param_1)

{
  FUN_10004030((int *)&DAT_1003455c,0x67,param_1,(int *)0x0);
  return;
}



// Function: FUN_10005060 at 10005060

void __thiscall FUN_10005060(void *this,undefined4 param_1)

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
  puStack_c = &LAB_10019b59;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_100052d3;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)DAT_10034510 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_10034514 == *piVar1) && (DAT_10034518 == piVar1[1])) && (DAT_1003451c == piVar1[2]))
        && ((DAT_10034520 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_10034968,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_100052a1;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002590((int *)&local_220);
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
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_100267a8,&local_220);
        if (-1 < iVar4) {
          FUN_10004e50(&local_224,&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_100017b0(DAT_10034510,FUN_100032d0,this);
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
LAB_100052a1:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_100030e0(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_100052d3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005300 at 10005300

undefined4 FUN_10005300(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x30);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_100283cc,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10005340 at 10005340

undefined4 FUN_10005340(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x34);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_100283cc,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10005380 at 10005380

undefined4 FUN_10005380(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x38);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_100265d0,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_100053c0 at 100053c0

undefined4 FUN_100053c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x3c);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10026750,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10005400 at 10005400

void __cdecl FUN_10005400(uint *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_10019b9b;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == (uint *)0x0) {
switchD_10005596_caseD_1:
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x80004005);
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
      FUN_100011a0(0x80004005);
    }
    if (param_3 == (undefined2 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x80004005);
    }
    puVar3 = (undefined2 *)FUN_10001f70((int)param_1);
    *param_3 = *puVar3;
    local_118 = local_114;
    lpString = puVar3 + (uint)(*(short *)((int)param_1 + 2) == -1) * 2 + 1;
    if (lpString != (LPCWSTR)0x0) {
      iVar5 = lstrlenW(lpString);
      FUN_10002c10((int *)&local_118,iVar5 + 1U,local_114,0x80);
      _DstSize = (iVar5 + 1U) * 2;
      eVar6 = memcpy_s(local_118,_DstSize,lpString,_DstSize);
      switch(eVar6) {
      case 0:
      case 0x50:
        goto switchD_10005596_caseD_0;
      default:
        goto switchD_10005596_caseD_1;
      case 0xc:
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      case 0x16:
      case 0x22:
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x80070057);
      }
    }
    local_118 = (wchar_t *)0x0;
switchD_10005596_caseD_0:
    local_8 = 0;
    FUN_100015f0(param_2,0x20,local_118,0xffffffff);
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



// Function: FUN_10005620 at 10005620

undefined4 FUN_10005620(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 8);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_100283cc,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10005660 at 10005660

void FUN_10005660(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10003790(0,param_2,param_3);
    return;
  }
  FUN_10004ca0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005690 at 10005690

void __fastcall FUN_10005690(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019be0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_100056e0 at 100056e0

int * __thiscall FUN_100056e0(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_100047f0(this,uVar2 + param_2,0xffffffff);
    FUN_100047f0(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10003ba0(this,uVar2);
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



// Function: FUN_100057e0 at 100057e0

int * __thiscall FUN_100057e0(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_100056e0(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10003ba0(this,param_2);
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



// Function: FUN_100058e0 at 100058e0

int * __thiscall
FUN_100058e0(void *this,uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

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
      FUN_10003ba0(this,uVar7);
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
          FUN_10001180((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),
                       param_2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001180((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
          FUN_10001180((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
        FUN_10001180((void *)((int)pvVar5 + (param_1 + param_5) * 2),
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
      FUN_10001180((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),param_5);
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
    FUN_10001180(pvVar5,pvVar4,uVar2);
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



// Function: FUN_10005c10 at 10005c10

LPVOID FUN_10005c10(uint param_1)

{
  HMODULE pHVar1;
  HRSRC pHVar2;
  ushort *puVar3;
  LPVOID pvVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pHVar1 = DAT_1003496c;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019c28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pHVar2 = FindResourceW(DAT_1003496c,(LPCWSTR)((param_1 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if ((pHVar2 != (HRSRC)0x0) &&
     (puVar3 = (ushort *)FUN_100016b0(pHVar1,pHVar2,param_1), puVar3 != (ushort *)0x0)) {
    local_8 = 2;
    pvVar4 = CoTaskMemAlloc((*puVar3 + 1) * 2);
    if (pvVar4 != (LPVOID)0x0) {
      FUN_10001530(pvVar4,(uint)*puVar3 * 2 + 2,puVar3 + 1,(uint)*puVar3 * 2);
      *(undefined2 *)((int)pvVar4 + (uint)*puVar3 * 2) = 0;
    }
    local_8 = 0xffffffff;
    CoTaskMemFree((LPVOID)0x0);
    ExceptionList = local_10;
    return pvVar4;
  }
  ExceptionList = local_10;
  return (LPVOID)0x0;
}



// Function: FUN_10005d00 at 10005d00

void __fastcall FUN_10005d00(undefined4 *param_1)

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



// Function: FUN_10005d90 at 10005d90

LONG FUN_10005d90(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10034510 + 4))();
  }
  return LVar1;
}



// Function: FUN_10005dc0 at 10005dc0

LONG FUN_10005dc0(int *param_1)

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
    (**(code **)(*DAT_10034510 + 8))();
  }
  return LVar1;
}



// Function: FUN_10005e10 at 10005e10

void FUN_10005e10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_100268ec,param_2,param_3);
  return;
}



// Function: FUN_10005e30 at 10005e30

undefined4 * __thiscall FUN_10005e30(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019cc6;
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



// Function: FUN_10005ec0 at 10005ec0

int * __thiscall FUN_10005ec0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
      FUN_10003ba0(this,uVar1);
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



// Function: FUN_10005fd0 at 10005fd0

int * __thiscall FUN_10005fd0(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_10005ec0(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
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
      FUN_10003ba0(this,uVar1);
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



// Function: FUN_100060f0 at 100060f0

int * __thiscall FUN_100060f0(void *this,uint param_1,int *param_2,int *param_3,uint param_4)

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
        piVar1 = FUN_100058e0(this,param_1,(uint)param_2,(int *)this,(int)param_3 - (int)pvVar2 >> 1
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
      FUN_10003ba0(this,uVar6);
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
      FUN_10001180((void *)((int)pvVar2 + (param_1 + (int)piVar4) * 2),
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



// Function: FUN_100062e0 at 100062e0

void __fastcall FUN_100062e0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      operator_delete(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}



// Function: FUN_10006320 at 10006320

int __thiscall FUN_10006320(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10001060(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = (*(code *)piVar4[1])(1);
        if (iVar5 < 0) {
          return iVar5;
        }
        uVar3 = (*(code *)piVar4[7])(1);
        iVar5 = Ordinal_49(*piVar4,uVar3);
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
  iVar5 = FUN_10004560(0x1003493c,param_1,param_2);
  if ((-1 < iVar5) && (DAT_10034508 != (code *)0x0)) {
    iVar5 = (*DAT_10034508)(DAT_10034968);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_100063c0 at 100063c0

int __thiscall FUN_100063c0(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10001060(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        uVar3 = (*(code *)piVar4[7])(0);
        iVar5 = Ordinal_49(*piVar4,uVar3);
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
  if ((DAT_1003450c != (code *)0x0) && (iVar5 = (*DAT_1003450c)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_100045f0(0x1003493c,param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 10006460

void DllRegisterServer(void)

{
                    /* 0x6460  3  DllRegisterServer */
  FUN_10006320(&DAT_1003455c,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 10006470

void DllUnregisterServer(void)

{
                    /* 0x6470  4  DllUnregisterServer */
  FUN_100063c0(&DAT_1003455c,1,(byte *)0x0);
  return;
}



// Function: FUN_10006480 at 10006480

undefined4 __thiscall
FUN_10006480(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_10005060(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_1000654e;
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
LAB_1000654e:
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



// Function: FUN_100065a0 at 100065a0

int FUN_100065a0(LPCWSTR param_1,LPCWSTR param_2)

{
  LPCWSTR pWVar1;
  LPCWSTR lpString;
  uint uVar2;
  int iVar3;
  int local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019d58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == (LPCWSTR)0x0) {
    local_14 = (LPCWSTR)0x0;
  }
  else {
    local_14 = param_1 + -0x34;
  }
  local_18 = 0;
  local_8 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    param_1 = (LPCWSTR)0x0;
  }
  else {
    param_1 = (LPCWSTR)Ordinal_2(param_2,DAT_100344b0 ^ (uint)&stack0xfffffffc);
    if (param_1 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  pWVar1 = param_1;
  local_8._0_1_ = 1;
  lpString = (LPCWSTR)FUN_10005c10(*(uint *)(local_14 + 0x42));
  local_8._0_1_ = 4;
  param_2 = lpString;
  if (lpString == (LPCWSTR)0x0) {
    local_8._0_1_ = 1;
    CoTaskMemFree((LPVOID)0x0);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(pWVar1);
    ExceptionList = local_10;
    return -0x7ff8fff2;
  }
  uVar2 = lstrlenW(L"\\");
  iVar3 = FUN_10002da0(&param_1,&DAT_10026924,uVar2);
  if (iVar3 < 0) {
    local_8._0_1_ = 1;
    CoTaskMemFree(lpString);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(param_1);
    ExceptionList = local_10;
    return iVar3;
  }
  uVar2 = lstrlenW(lpString);
  iVar3 = FUN_10002da0(&param_1,lpString,uVar2);
  pWVar1 = param_1;
  if (iVar3 < 0) {
    local_8._0_1_ = 1;
    CoTaskMemFree(lpString);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(param_1);
    local_8 = 0xffffffff;
    FUN_10002590(&local_18);
    ExceptionList = local_10;
    return iVar3;
  }
  WinHelpW(*(HWND *)(local_14 + 0x20),param_1,8,0);
  local_8._0_1_ = 1;
  CoTaskMemFree(lpString);
  param_2 = (LPCWSTR)0x0;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(pWVar1);
  local_8 = 0xffffffff;
  FUN_10002590(&local_18);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10006770 at 10006770

void FUN_10006770(LPCWSTR param_1)

{
  short sVar1;
  LPCWSTR *ppWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  HKEY local_22c;
  undefined4 local_228;
  undefined4 local_224;
  uint local_220;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10019d93;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_22c = (HKEY)0x0;
  local_228 = 0;
  local_224 = 0;
  local_8 = 1;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_220 = 0x208;
  ppWVar2 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar2 = &param_1;
  }
  iVar3 = FUN_100017f0(&local_22c,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_22c,L"ResourceDLL",(LPBYTE)&local_21c,&local_220);
    if ((LVar4 == 0) && (local_220 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(in_stack_00000020,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (local_22c != (HKEY)0x0) {
    RegCloseKey(local_22c);
    local_22c = (HKEY)0x0;
  }
  local_228 = 0;
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  param_1 = (LPCWSTR)((uint)param_1 & 0xffff0000);
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100068d0 at 100068d0

void __cdecl FUN_100068d0(wchar_t *param_1,ushort param_2,int *param_3,char param_4)

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
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  FUN_10001dc0(param_1,param_2,&local_54,&local_58);
  if (param_4 != '\0') {
    hModule = LoadLibraryW(L"COMCTL32.DLL");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
      if (hResInfo != (HRSRC)0x0) {
        puVar1 = (uint *)LoadResource(hModule,hResInfo);
        if (puVar1 != (uint *)0x0) {
          iVar2 = FUN_10005400(puVar1,local_48,(undefined2 *)&local_4c);
          FreeLibrary(hModule);
          if (iVar2 != 0) {
            FUN_10001dc0(local_48,(ushort)local_4c,&local_60,&local_4c);
            pcVar3 = MulDiv_exref;
            iVar2 = MulDiv(*param_3,local_54,4);
            *param_3 = iVar2;
            iVar2 = MulDiv(param_3[1],local_5c,8);
            param_3[1] = iVar2;
            goto LAB_100069b8;
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
LAB_100069b8:
  iVar2 = (*pcVar3)(iVar2,local_58,local_4c);
  param_3[1] = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100069d0 at 100069d0

undefined4 FUN_100069d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_100325e0 == (int *)0x0) {
    uVar1 = FUN_10005060(&PTR_DAT_100325d4,param_3);
  }
  *param_4 = DAT_100325e0;
  if (DAT_100325e0 != (int *)0x0) {
    (**(code **)(*DAT_100325e0 + 4))(DAT_100325e0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006a30 at 10006a30

void FUN_10006a30(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006480(&PTR_DAT_100325d4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006a60 at 10006a60

void FUN_10006a60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_100325e0 == (int *)0x0) || (DAT_100325e8 == 0)) {
    FUN_10005060(&PTR_DAT_100325d4,param_4);
  }
  if (DAT_100325e0 != (int *)0x0) {
    (**(code **)(*DAT_100325e0 + 0x2c))
              (DAT_100325e0,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10006ac0 at 10006ac0

undefined4 FUN_10006ac0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_100325fc == (int *)0x0) {
    uVar1 = FUN_10005060(&PTR_DAT_100325f0,param_3);
  }
  *param_4 = DAT_100325fc;
  if (DAT_100325fc != (int *)0x0) {
    (**(code **)(*DAT_100325fc + 4))(DAT_100325fc);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006b20 at 10006b20

void FUN_10006b20(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006480(&PTR_DAT_100325f0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006b50 at 10006b50

void FUN_10006b50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_100325fc == (int *)0x0) || (DAT_10032604 == 0)) {
    FUN_10005060(&PTR_DAT_100325f0,param_4);
  }
  if (DAT_100325fc != (int *)0x0) {
    (**(code **)(*DAT_100325fc + 0x2c))
              (DAT_100325fc,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10006bb0 at 10006bb0

DWORD FUN_10006bb0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019dcb;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005d00(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10006c56();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006c43 at 10006c43

undefined * Catch_10006c43(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006c50;
}



// Function: FUN_10006c56 at 10006c56

DWORD FUN_10006c56(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10006cb3;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_10006c8b;
  }
  else {
LAB_10006c8b:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_10006cb3;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10006cb3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10006cd0 at 10006cd0

void __thiscall FUN_10006cd0(void *this,uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100060f0(this,param_1,param_2,param_3,(int)piVar2 - ((int)param_3 + 2) >> 1);
  return;
}



// Function: FUN_10006d10 at 10006d10

int __thiscall
FUN_10006d10(void *this,undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,
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
  
  puStack_c = &LAB_10019e28;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  iVar3 = FUN_10004da0(this,&DAT_10026914,(int *)&local_14);
  if (iVar3 < 0) {
                    /* WARNING: Load size is inaccurate */
    iVar3 = Ordinal_60(param_1,*this,param_2,param_3,param_4,param_5,param_6,param_7);
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
      if (param_3 != 0) {
        iVar3 = (**(code **)*local_14)(local_14,&DAT_100283cc,param_3);
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



// Function: FUN_10006e30 at 10006e30

undefined4 * __thiscall FUN_10006e30(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019e5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  FUN_100056e0((undefined2 *)((int)this + 0x10),(int *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10006ec0 at 10006ec0

void __fastcall FUN_10006ec0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  BOOL BVar4;
  tagPOINT local_a4;
  tagPOINT local_9c;
  tagPOINT local_94;
  tagPOINT local_8c;
  tagPOINT local_84;
  tagPOINT local_7c;
  HDWP local_74;
  int *local_70;
  HWND local_6c;
  tagRECT local_68;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  iVar3 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  local_6c = *(HWND *)(iVar3 + 0x40);
  local_48.left = 0;
  local_48.top = 0;
  local_48.right = 0;
  local_48.bottom = 0;
  GetClientRect(local_6c,&local_48);
  piVar1 = (int *)**(int **)(param_1 + 0x5c);
  local_70 = piVar1;
  local_74 = BeginDeferWindowPos(*(int *)(param_1 + 0x60));
  if (piVar1 != *(int **)(param_1 + 0x5c)) {
    do {
      puVar2 = (undefined4 *)local_70[2];
      if (puVar2 != (undefined4 *)0x0) {
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        BVar4 = GetWindowRect((HWND)*puVar2,&local_28);
        if (BVar4 != 0) {
          local_8c.y = local_28.top;
          local_94.x = local_28.left;
          local_8c.x = local_28.right;
          local_94.y = local_28.bottom;
          ScreenToClient((HWND)*puVar2,&local_8c);
          ScreenToClient((HWND)*puVar2,&local_94);
          local_28.top = local_8c.y;
          local_28.left = local_94.x;
          local_28.right = local_8c.x;
          local_28.bottom = local_94.y;
          local_68.left = 0;
          local_68.top = 0;
          local_68.right = 0;
          local_68.bottom = 0;
          GetWindowRect(local_6c,&local_68);
          if ((HWND)puVar2[0xb] == (HWND)0x0) {
            local_18.left = ((local_48.right - local_48.left) * puVar2[3]) / 100 + puVar2[5];
            local_18.top = ((local_48.bottom - local_48.top) * puVar2[4]) / 100 + puVar2[6];
          }
          else {
            local_38.left = 0;
            local_38.top = 0;
            local_38.right = 0;
            local_38.bottom = 0;
            GetWindowRect((HWND)puVar2[0xb],&local_38);
            local_84.y = local_38.top;
            local_7c.x = local_38.right;
            local_84.x = local_38.left;
            local_7c.y = local_38.bottom;
            ScreenToClient(local_6c,&local_84);
            ScreenToClient(local_6c,&local_7c);
            local_38.right = local_7c.x;
            local_18.left = puVar2[5];
            local_38.top = local_84.y;
            local_38.bottom = local_7c.y;
            local_18.top = local_7c.y;
            local_38.left = local_84.x;
          }
          if ((HWND)puVar2[0xc] == (HWND)0x0) {
            local_18.right = ((local_48.right - local_48.left) * puVar2[7]) / 100 + puVar2[9];
            local_18.bottom = ((local_48.bottom - local_48.top) * puVar2[8]) / 100 + puVar2[10];
          }
          else {
            local_58.left = 0;
            local_58.top = 0;
            local_58.right = 0;
            local_58.bottom = 0;
            GetWindowRect((HWND)puVar2[0xc],&local_58);
            local_a4.y = local_58.top;
            local_9c.x = local_58.right;
            local_a4.x = local_58.left;
            local_9c.y = local_58.bottom;
            ScreenToClient(local_6c,&local_a4);
            ScreenToClient(local_6c,&local_9c);
            local_58.left = local_a4.x;
            local_58.top = local_a4.y;
            local_58.right = local_9c.x;
            local_58.bottom = local_9c.y;
            local_18.right = local_9c.x;
            local_18.bottom = local_a4.y;
          }
          BVar4 = EqualRect(&local_18,&local_28);
          if (BVar4 == 0) {
            iVar3 = puVar2[1];
            if (iVar3 != 0) {
              MoveWindow((HWND)*puVar2,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar2,&local_18,1);
              UpdateWindow(local_6c);
            }
            if (puVar2[2] == 0) {
              if (iVar3 == 0) {
                DeferWindowPos(local_74,(HWND)*puVar2,(HWND)0x0,local_18.left,local_18.top,
                               local_18.right - local_18.left,local_18.bottom - local_18.top,0x14);
              }
            }
            else {
              MoveWindow((HWND)*puVar2,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar2,&local_18,1);
              UpdateWindow(local_6c);
            }
          }
        }
      }
      local_70 = (int *)*local_70;
    } while (local_70 != (int *)*(int *)(param_1 + 0x5c));
  }
  EndDeferWindowPos(local_74);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007270 at 10007270

void __thiscall FUN_10007270(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_2 == (int *)**this) && (param_3 == *this)) {
    FUN_100062e0((int *)this);
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
    return;
  }
  if (param_2 != param_3) {
    do {
      piVar1 = (int *)*param_2;
                    /* WARNING: Load size is inaccurate */
      if (param_2 != *this) {
        *(int **)param_2[1] = piVar1;
        *(int *)(*param_2 + 4) = param_2[1];
        operator_delete(param_2);
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
      }
      param_2 = piVar1;
    } while (piVar1 != param_3);
  }
  *param_1 = (int)param_3;
  return;
}



// Function: FUN_100072e0 at 100072e0

void __fastcall FUN_100072e0(undefined4 *param_1)

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



// Function: FUN_10007330 at 10007330

undefined2 * __thiscall FUN_10007330(void *this,int *param_1)

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
  FUN_100057e0(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return (undefined2 *)this;
}



// Function: FUN_10007380 at 10007380

void FUN_10007380(void *param_1)

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
  
  puStack_c = &LAB_10019f96;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_238,(int *)L"{4C6A0279-C735-4563-A2B6-0969B383DB77}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_244,L"ResourceDLL",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10007530 at 10007530

void __thiscall FUN_10007530(void *this,int *param_1,void *param_2)

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
  
  puStack_c = &LAB_10019e90;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = (int *)0x0;
  local_30[0] = (int **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x14))(local_30,local_14);
  if (iVar1 == 0) {
    bVar5 = local_20 == (int *)0x0;
    if (bVar5) goto LAB_10007593;
  }
  else {
LAB_10007593:
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x10))(local_30);
    if (iVar1 == 0) {
      bVar5 = local_20 == (int *)0x0;
      if (!bVar5) goto LAB_100075c3;
    }
    FUN_100056e0(param_2,param_1,0,0xffffffff);
    if (iVar1 != 0) goto LAB_1000767e;
    bVar5 = local_20 == (int *)0x0;
  }
LAB_100075c3:
  if (!bVar5) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_100056e0(local_4c,param_1,0,0xffffffff);
    local_50[0] = 0x5f;
    local_50[1] = 0;
    uVar2 = FUN_10001fe0(local_4c,local_50,0xffffffff,1);
    local_50[0] = 0x2e;
    local_50[1] = 0;
    uVar3 = FUN_10001fe0(local_4c,local_50,0xffffffff,1);
    if ((uVar2 != 0xffffffff) && ((int *)((uVar3 - uVar2) + -1) == local_20)) {
      pppiVar4 = (int ***)local_30[0];
      if (local_1c < 8) {
        pppiVar4 = local_30;
      }
      FUN_10006cd0(local_4c,uVar2 + 1,local_20,(int *)pppiVar4);
    }
    FUN_100056e0(param_2,(int *)local_4c,0,0xffffffff);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
LAB_1000767e:
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



// Function: FUN_100076d0 at 100076d0

void FUN_100076d0(void *param_1)

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
  
  puStack_c = &LAB_10019fe1;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_100057e0(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005ec0(&local_238,&local_254,0,0xffffffff);
  FUN_10005fd0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_10005fd0(&local_238,(int *)L"{4C6A0279-C735-4563-A2B6-0969B383DB77}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_264,L"LanguageExt",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10007910 at 10007910

void FUN_10007910(void *param_1)

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
  
  puStack_c = &LAB_10019fe1;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_100057e0(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005ec0(&local_238,&local_254,0,0xffffffff);
  FUN_10005fd0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_10005fd0(&local_238,(int *)L"{4C6A0279-C735-4563-A2B6-0969B383DB77}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_264,L"ResourceDLL",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10007b50 at 10007b50

void __thiscall FUN_10007b50(void *this,undefined4 param_1)

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
  
  puStack_c = &LAB_1001a056;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_440,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_440,(int *)L"{4C6A0279-C735-4563-A2B6-0969B383DB77}",0x26);
  pWVar1 = local_440;
  if (local_42c < 8) {
    pWVar1 = (LPCWSTR)&local_440;
  }
  iVar2 = FUN_100017f0(&local_450,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_100018a0(&local_450,L"XMLResource",local_21c,&local_444);
    local_444 = 0x208;
  }
  FUN_100018a0(&local_450,L"FriendlyName",local_424,&local_444);
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



// Function: FUN_10007d40 at 10007d40

void FUN_10007d40(void *param_1)

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
  
  puStack_c = &LAB_10019f96;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_238,(int *)L"{4C6A0279-C735-4563-A2B6-0969B383DB77}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_244,L"BaseName",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10007ef0 at 10007ef0

void FUN_10007ef0(void *param_1,ushort *param_2,undefined4 *param_3)

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
  for (uVar3 = FUN_100035e0(param_1,puVar7,0,(int)puVar5 - (int)(puVar7 + 1) >> 1);
      uVar3 != 0xffffffff;
      uVar3 = FUN_100035e0(param_1,puVar5,param_3[4] + uVar3,(int)puVar7 - (int)(puVar5 + 1) >> 1))
  {
    piVar4 = FUN_10001470(param_3);
    piVar6 = piVar4;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar2 != 0);
    FUN_100060f0(param_1,uVar3,*(int **)(param_2 + 8),piVar4,(int)piVar6 - ((int)piVar4 + 2) >> 1);
    puVar5 = (ushort *)FUN_10001470((undefined4 *)param_2);
    puVar7 = puVar5;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != 0);
  }
  return;
}



// Function: FUN_10007fb0 at 10007fb0

void __cdecl FUN_10007fb0(uint *param_1,int *param_2,char param_3)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  iVar2 = FUN_10005400(param_1,local_48,(undefined2 *)&local_4c);
  if (iVar2 == 0) {
    uVar4 = 0;
    pwVar3 = (wchar_t *)0x0;
  }
  else {
    pwVar3 = local_48;
    uVar4 = local_4c;
  }
  FUN_100068d0(pwVar3,(ushort)uVar4,param_2,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008040 at 10008040

/* WARNING: Removing unreachable block (ram,0x1000838c) */

void __thiscall FUN_10008040(void *this,void *param_1)

{
  short sVar1;
  int iVar2;
  HMODULE pHVar3;
  int ****ppppiVar4;
  LPCWSTR ***ppppWVar5;
  int ****ppppiVar6;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  uint uStack_12c;
  LPCWSTR **pppWStack_128;
  undefined2 local_10c [8];
  undefined4 local_fc;
  undefined4 local_f8;
  LPCWSTR **pppWStack_f0;
  uint uStack_ec;
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
  
  puStack_c = &LAB_10019f1f;
  local_10 = ExceptionList;
  uStack_ec = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_8._1_3_ = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8._0_1_ = 3;
  pppWStack_f0 = (LPCWSTR **)local_30;
  local_f8 = 7;
  local_fc = 0;
  local_10c[0] = 0;
  local_14 = uStack_ec;
  FUN_100056e0(local_10c,(int *)&param_1,0,0xffffffff);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar2 = (**(code **)(*this + 0x40))();
  ppppWVar5 = (LPCWSTR ***)local_30[0];
  if (local_1c < 8) {
    ppppWVar5 = local_30;
  }
  pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
  if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*this + 0x28))();
    ppppWVar5 = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      ppppWVar5 = local_30;
    }
    pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
    if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (**(code **)(*this + 0x14))();
                    /* WARNING: Load size is inaccurate */
      if (((iVar2 != 0) || (local_3c == 0)) &&
         ((iVar2 = (**(code **)(*this + 0x10))(), iVar2 != 0 || (local_3c == 0)))) {
        FUN_100057e0(local_4c,(int *)&DAT_1002604c,2);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68._2_2_ << 0x10);
      FUN_100057e0(&local_68,(int *)&DAT_10026978,1);
      local_8._0_1_ = 5;
      ppppiVar6 = (int ****)local_4c[0];
      if (local_38 < 8) {
        ppppiVar6 = local_4c;
      }
      ppppiVar4 = ppppiVar6;
      do {
        sVar1 = *(short *)ppppiVar4;
        ppppiVar4 = (int ****)((int)ppppiVar4 + 2);
      } while (sVar1 != 0);
      FUN_10005fd0(&local_68,(int *)ppppiVar6,(int)ppppiVar4 - ((int)ppppiVar6 + 2) >> 1);
      FUN_10005fd0(&local_68,(int *)&DAT_10026974,1);
      local_a0 = (void *)((uint)local_a0._2_2_ << 0x10);
      local_8c = 7;
      local_90 = 0;
      FUN_100057e0(&local_a0,(int *)L"_EN.",4);
      local_8._0_1_ = 6;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(*this + 0x38))();
      local_8._0_1_ = 5;
      if (7 < local_8c) {
        operator_delete(local_a0);
      }
      local_a0 = (void *)((uint)local_a0 & 0xffff0000);
      local_8c = 7;
      local_90 = 0;
      local_70 = 7;
      local_74 = 0;
      local_84 = (void *)((uint)local_84._2_2_ << 0x10);
      pppWStack_128 = (LPCWSTR **)0x1000827c;
      FUN_100057e0(&local_84,(int *)L"_en.",4);
      local_8._0_1_ = 7;
                    /* WARNING: Load size is inaccurate */
      pppWStack_128 = (LPCWSTR **)local_30;
      uStack_12c = 0x10008295;
      (**(code **)(*this + 0x38))();
      local_8._0_1_ = 5;
      if (7 < local_70) {
        operator_delete(local_84);
      }
      local_70 = 7;
      local_74 = 0;
      local_84 = (void *)((uint)local_84 & 0xffff0000);
      ppppWVar5 = (LPCWSTR ***)local_30[0];
      if (local_1c < 8) {
        ppppWVar5 = local_30;
      }
      pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (7 < local_54) {
        operator_delete(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68 & 0xffff0000);
      if (pHVar3 == (HMODULE)0x0) {
        GetLastError();
        goto LAB_1000830f;
      }
    }
  }
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x20))();
  *(undefined4 *)((int)this + 4) = 1;
LAB_1000830f:
  local_8._0_1_ = 8;
  uStack_12c = uStack_12c & 0xffff0000;
  FUN_100056e0(&uStack_12c,(int *)&param_1,0,0xffffffff);
                    /* WARNING: Load size is inaccurate */
  local_8._0_1_ = 8;
  (**(code **)(*this + 0x44))();
  local_8._0_1_ = 2;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  param_1 = (void *)((uint)param_1 & 0xffff0000);
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008460 at 10008460

void FUN_10008460(void *param_1)

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
  
  puStack_c = &LAB_10019f96;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_238,(int *)L"(DF3A576B-CA42-4d23-B78B-6603E9D88CC1)",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_244,L"ResourceDLL",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10008610 at 10008610

void __thiscall FUN_10008610(void *this,int *param_1,undefined4 param_2)

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
  puStack_c = &LAB_10019f58;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
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



// Function: FUN_100086e0 at 100086e0

void FUN_100086e0(void *param_1)

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
  
  puStack_c = &LAB_10019f96;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\",
               0x36);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_238,(int *)L"Locale",6);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_244,L"LanguageExt",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10008890 at 10008890

void FUN_10008890(void *param_1)

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
  
  puStack_c = &LAB_10019fe1;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_100057e0(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005ec0(&local_238,&local_254,0,0xffffffff);
  FUN_10005fd0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_10005fd0(&local_238,(int *)L"(DF3A576B-CA42-4d23-B78B-6603E9D88CC1)",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_264,L"LanguageExt",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10008ad0 at 10008ad0

void __fastcall FUN_10008ad0(int *param_1)

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
  
  puStack_c = &LAB_1001a018;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  iVar3 = (**(code **)(*param_1 + 0x10))(local_30,local_14);
  if ((iVar3 != 0) || (local_20 == 0)) {
    FUN_100057e0(local_30,(int *)&DAT_1002604c,2);
  }
  uVar7 = 0;
  if (PTR_DAT_100310d8 != (undefined *)0x0) {
    ppuVar4 = &PTR_DAT_100310d8;
    do {
      puVar2 = (ushort *)*ppuVar4;
      puVar5 = puVar2;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
      } while (uVar1 != 0);
      uVar6 = FUN_100025c0(local_30,0,local_20,puVar2,(int)puVar5 - (int)(puVar2 + 1) >> 1);
      if (uVar6 == 0) break;
      uVar7 = uVar7 + 1;
      ppuVar4 = &PTR_DAT_100310d8 + (uVar7 & 0xffff);
    } while ((&PTR_DAT_100310d8)[uVar7 & 0xffff] != (undefined *)0x0);
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



// Function: FUN_10008be0 at 10008be0

void FUN_10008be0(void *param_1)

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
  
  puStack_c = &LAB_10019fe1;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_100057e0(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005ec0(&local_238,&local_254,0,0xffffffff);
  FUN_10005fd0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_10005fd0(&local_238,(int *)L"(DF3A576B-CA42-4d23-B78B-6603E9D88CC1)",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_264,L"ResourceDLL",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_10008e20 at 10008e20

void __thiscall FUN_10008e20(void *this,undefined4 param_1)

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
  
  puStack_c = &LAB_1001a056;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_440,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_440,(int *)L"(DF3A576B-CA42-4d23-B78B-6603E9D88CC1)",0x26);
  pWVar1 = local_440;
  if (local_42c < 8) {
    pWVar1 = (LPCWSTR)&local_440;
  }
  iVar2 = FUN_100017f0(&local_450,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_100018a0(&local_450,L"XMLResource",local_21c,&local_444);
    local_444 = 0x208;
  }
  FUN_100018a0(&local_450,L"FriendlyName",local_424,&local_444);
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



// Function: FUN_10009010 at 10009010

void FUN_10009010(void *param_1)

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
  
  puStack_c = &LAB_10019f96;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10005fd0(&local_238,(int *)L"(DF3A576B-CA42-4d23-B78B-6603E9D88CC1)",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_100017f0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_100018a0(&local_244,L"BaseName",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_100057e0(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
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



// Function: FUN_100091c0 at 100091c0

void __thiscall
FUN_100091c0(void *this,undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  HWND hWnd;
  int iVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 0x40);
  if ((param_2 != 4) && (param_2 != 3)) {
    if (*(int *)((int)this + 0x18) != 0) {
      FUN_10002650((int)this);
      InvalidateRect(hWnd,(RECT *)((int)this + 0x44),1);
      *(undefined4 *)((int)this + 0x20) = 1;
    }
    FUN_10006ec0((int)this);
    FUN_10006ec0((int)this);
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0xb4;
  }
  GetWindowRect(*(HWND *)(iVar1 + 0x40),&local_18);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0xb4;
  }
  InvalidateRect(*(HWND *)(iVar1 + 0x40),&local_18,1);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0xb4;
  }
  UpdateWindow(*(HWND *)(iVar1 + 0x40));
  *param_4 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100092b0 at 100092b0

void __thiscall FUN_100092b0(void *this,void *param_1)

{
  int *piVar1;
  uint uStack_84;
  int *local_74;
  int local_70;
  undefined4 local_6c [7];
  ushort local_50 [14];
  ushort local_34 [14];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a0b8;
  local_10 = ExceptionList;
  uStack_84 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_84;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_84;
  __RTDynamicCast(this,0,&CContextSensitiveHelpProvider<class_CImmobilizerInstallationPageImpl>::
                          RTTI_Type_Descriptor,
                  &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  FUN_10002cf0(&local_74,(GUID *)&DAT_10028330);
  local_8._0_1_ = 1;
  FUN_10016a90((undefined2 *)local_6c,local_74);
  local_8._0_1_ = 2;
  FUN_10007330(local_34,(int *)&DAT_10026808);
  local_8._0_1_ = 3;
  FUN_10007330(local_50,(int *)&DAT_10026b3c);
  local_8._0_1_ = 4;
  FUN_100169d0(local_6c,local_50,(undefined4 *)local_34);
  local_8._0_1_ = 3;
  FUN_100047c0((undefined4 *)local_50);
  local_8._0_1_ = 2;
  FUN_100047c0((undefined4 *)local_34);
  FUN_10007330(local_50,(int *)&DAT_10026808);
  local_8._0_1_ = 5;
  FUN_10007330(local_34,(int *)&DAT_10026b38);
  local_8._0_1_ = 6;
  FUN_100169d0(local_6c,local_34,(undefined4 *)local_50);
  local_8._0_1_ = 5;
  FUN_100047c0((undefined4 *)local_34);
  local_8._0_1_ = 2;
  FUN_100047c0((undefined4 *)local_50);
  piVar1 = FUN_10016930(&local_70,local_6c);
  local_8._0_1_ = 7;
  FUN_10001740(param_1,piVar1);
  local_8._0_1_ = 2;
  Ordinal_6(local_70);
  local_8._0_1_ = 1;
  FUN_100047c0(local_6c);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_74);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10009426 at 10009426

undefined4 Catch_10009426(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009406;
}



// Function: FUN_10009440 at 10009440

undefined4 * __thiscall
FUN_10009440(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a0eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 8) = param_2;
  piVar2 = param_4;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100057e0((undefined2 *)((int)this + 0x10),param_4,(int)piVar2 - ((int)param_4 + 2) >> 1);
  *(undefined4 *)((int)this + 0x2c) = param_5;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100094e0 at 100094e0

void __thiscall FUN_100094e0(void *this,ushort param_1)

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
  uint *puVar10;
  ushort uVar11;
  DWORD DVar12;
  uint uVar13;
  HMENU pHVar14;
  ushort *local_44;
  HWND local_38;
  undefined4 local_34;
  uint local_30;
  LPSTREAM local_2c;
  HWND local_28;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a140;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pHVar3 = FindResourceW(DAT_1003496c,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  local_44 = (ushort *)0x0;
  local_28 = (HWND)0x0;
  if ((pHVar3 != (HRSRC)0x0) && (pvVar4 = LoadResource(DAT_1003496c,pHVar3), pvVar4 != (HGLOBAL)0x0)
     ) {
    local_44 = (ushort *)LockResource(pvVar4);
  }
  pHVar3 = FindResourceW(DAT_1003496c,(LPCWSTR)(uint)param_1,(LPCWSTR)0x5);
  if (pHVar3 != (HRSRC)0x0) {
    pvVar4 = LoadResource(DAT_1003496c,pHVar3);
    if ((pvVar4 == (HGLOBAL)0x0) || (puVar5 = (uint *)LockResource(pvVar4), puVar5 == (uint *)0x0))
    {
      local_28 = (HWND)FUN_10001720();
    }
    else {
      uVar13 = (uint)(*(short *)((int)puVar5 + 2) == -1);
      puVar10 = puVar5 + 4;
      if (*(short *)((int)puVar5 + 2) != -1) {
        puVar10 = puVar5 + 2;
      }
      uVar1 = *puVar10;
      local_30 = uVar13;
      pDVar6 = (DWORD *)FUN_10001970(puVar5);
      local_38 = GetWindow(*(HWND *)((int)this + 4),5);
      uVar11 = 0;
      if ((ushort)uVar1 != 0) {
        do {
          if (uVar13 == 0) {
            DVar12 = (DWORD)(ushort)pDVar6[4];
            pDVar7 = (DWORD *)((int)pDVar6 + 0x12);
          }
          else {
            DVar12 = pDVar6[5];
            pDVar7 = pDVar6 + 6;
          }
          if ((short)*pDVar7 == 0x7b) {
            local_28 = (HWND)0x0;
            dwBytes = FUN_10001a80(DVar12,local_44,(int *)&local_28);
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
                local_28 = (HWND)FUN_10001720();
                local_8 = 0xffffffff;
                if (local_2c != (IStream *)0x0) {
                  (*local_2c->lpVtbl->Release)(local_2c);
                }
                break;
              }
              FUN_10001530(pvVar8,dwBytes,local_28,dwBytes);
              GlobalUnlock(pvVar4);
              CreateStreamOnHGlobal(pvVar4,1,&local_2c);
              uVar13 = local_30;
            }
            local_34 = 0;
            local_8 = CONCAT31(local_8._1_3_,4);
            local_28 = (HWND)FUN_10003330((int *)local_2c,&local_34);
            if (-1 < (int)local_28) {
              local_28 = (HWND)0x0;
              Ordinal_42();
              if (uVar13 == 0) {
                sVar2 = (short)pDVar6[2];
                pDVar7 = (DWORD *)((int)pDVar6 + 0x12);
              }
              else {
                sVar2 = (short)pDVar6[3];
                pDVar7 = pDVar6 + 6;
              }
              local_24.left = (LONG)sVar2;
              if (uVar13 == 0) {
                sVar2 = *(short *)((int)pDVar6 + 10);
              }
              else {
                sVar2 = *(short *)((int)pDVar6 + 0xe);
              }
              local_24.top = (LONG)sVar2;
              if (uVar13 == 0) {
                sVar2 = (short)pDVar6[3];
              }
              else {
                sVar2 = (short)pDVar6[4];
              }
              local_24.right = sVar2 + local_24.left;
              if (uVar13 == 0) {
                sVar2 = *(short *)((int)pDVar6 + 0xe);
              }
              else {
                sVar2 = *(short *)((int)pDVar6 + 0x12);
              }
              local_24.bottom = sVar2 + local_24.top;
              MapDialogRect(*(HWND *)((int)this + 4),&local_24);
              if (uVar13 == 0) {
                pHVar14 = (HMENU)(uint)(ushort)pDVar6[4];
                DVar9 = *pDVar6;
                DVar12 = 0;
              }
              else {
                pHVar14 = (HMENU)pDVar6[5];
                DVar12 = pDVar6[1];
                DVar9 = pDVar6[2];
              }
              FUN_10003710(&local_28,*(HWND *)((int)this + 4),&local_24.left,(LPCWSTR)0x0,
                           DVar9 | 0x10000,DVar12,pHVar14,(LPVOID)0x0);
              hWnd = local_28;
              if (local_28 == (HWND)0x0) {
                local_28 = (HWND)FUN_10001720();
                uVar13 = local_30;
              }
              else {
                if ((local_30 != 0) && (*pDVar6 != 0)) {
                  SetWindowContextHelpId(local_28,*pDVar6);
                }
                local_28 = (HWND)FUN_10006d10(&local_28,pDVar7,local_2c,0,(undefined4 *)0x0,
                                              &DAT_100283ac,0,local_34);
                if ((int)local_28 < 0) {
                  local_8 = CONCAT31(local_8._1_3_,1);
                  Ordinal_6();
                  local_8 = 0xffffffff;
                  FUN_10016c40((int *)&local_2c);
                  break;
                }
                if (uVar11 == 0) {
                  local_38 = (HWND)0x0;
                }
                SetWindowPos(hWnd,local_38,0,0,0,0,0x13);
                local_38 = hWnd;
                uVar13 = local_30;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_6();
            local_8 = 0xffffffff;
            if (local_2c != (IStream *)0x0) {
              (*local_2c->lpVtbl->Release)(local_2c);
            }
          }
          else if (uVar11 != 0) {
            local_38 = GetWindow(local_38,2);
          }
          pDVar6 = (DWORD *)FUN_10001a10((int)pDVar6,uVar13);
          uVar11 = uVar11 + 1;
        } while (uVar11 < (ushort)uVar1);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100098a0 at 100098a0

undefined4 FUN_100098a0(int param_1,undefined4 *param_2)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint *puVar1;
  LPVOID pvVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x68;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  hResInfo = FindResourceW(DAT_1003496c,(LPCWSTR)0x65,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResData = LoadResource(DAT_1003496c,hResInfo);
    if (hResData != (HGLOBAL)0x0) {
      puVar1 = (uint *)LockResource(hResData);
      if (puVar1 != (uint *)0x0) {
        FUN_10007fb0(puVar1,(int *)(param_1 + 0x10),'\x01');
        *param_2 = 0x1c;
        pvVar2 = FUN_10005c10(*(uint *)(iVar3 + 0x80));
        param_2[1] = pvVar2;
        param_2[2] = *(int *)(param_1 + 0x10);
        param_2[3] = *(undefined4 *)(param_1 + 0x14);
        pvVar2 = FUN_10005c10(*(uint *)(iVar3 + 0x84));
        param_2[5] = pvVar2;
        pvVar2 = FUN_10005c10(*(uint *)(iVar3 + 0x88));
        param_2[4] = pvVar2;
        param_2[6] = *(undefined4 *)(iVar3 + 0x8c);
        return 0;
      }
    }
  }
  return 0x8000ffff;
}



// Function: FUN_10009970 at 10009970

void __fastcall FUN_10009970(int *param_1)

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
  
  puStack_c = &LAB_1001a1a6;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
        FUN_100057e0(local_4c,(int *)&DAT_1002604c,2);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68._2_2_ << 0x10);
      FUN_100057e0(&local_68,(int *)&DAT_10026978,1);
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
      FUN_10005fd0(&local_68,(int *)ppppiVar6,(int)ppppiVar4 - ((int)ppppiVar6 + 2) >> 1);
      FUN_10005fd0(&local_68,(int *)&DAT_10026974,1);
      local_84 = (void *)((uint)local_84._2_2_ << 0x10);
      local_70 = 7;
      local_74 = 0;
      FUN_100057e0(&local_84,(int *)L"_EN.",4);
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
      FUN_100057e0(&local_a0,(int *)L"_en.",4);
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
        FUN_100056e0(local_30,(int *)local_bc,0,0xffffffff);
        FUN_10005fd0(local_30,(int *)L"Res_",4);
        FUN_10005ec0(local_30,local_4c,0,0xffffffff);
        FUN_10005fd0(local_30,(int *)L".dll",4);
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
          goto LAB_10009ca4;
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x20))(pHVar3);
  param_1[1] = 1;
LAB_10009ca4:
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



// Function: FUN_10009d60 at 10009d60

undefined4 __thiscall FUN_10009d60(void *this)

{
  int *this_00;
  int *piVar1;
  undefined4 *in_stack_00000010;
  void *local_8;
  
  piVar1 = (int *)**(int **)((int)this + 0x5c);
  this_00 = (int *)((int)this + 0x5c);
  local_8 = this;
  if (piVar1 != *(int **)((int)this + 0x5c)) {
    do {
      operator_delete((void *)piVar1[2]);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*this_00);
  }
  FUN_10007270(this_00,(int *)&local_8,*(int **)*this_00,(int *)*this_00);
  *in_stack_00000010 = 0;
  return 0;
}



// Function: FUN_10009db0 at 10009db0

undefined4 __thiscall FUN_10009db0(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_30;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a1e0;
  local_10 = ExceptionList;
  uStack_30 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 2;
  puVar1 = (undefined4 *)((int)this + 0x10);
  iVar2 = Ordinal_7(*puVar1);
  if (iVar2 == 0) {
    FUN_100092b0(this,puVar1);
  }
  FUN_10002d50(param_1,puVar1);
                    /* WARNING: Load size is inaccurate */
  uVar3 = (**(code **)(*this + 0x10))(&local_18);
  iVar2 = Ordinal_7(local_18);
  if (iVar2 != 0) {
    uVar4 = lstrlenW(L"-");
    FUN_10002da0(param_1,&DAT_10026b58,uVar4);
    FUN_10002d50(param_1,&local_18);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  ExceptionList = local_10;
  return uVar3;
}



// Function: Catch@10009e8e at 10009e8e

undefined4 Catch_10009e8e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009e77;
}



// Function: FUN_10009ea0 at 10009ea0

undefined4 __thiscall
FUN_10009ea0(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  undefined4 uVar1;
  
  if (param_6 == 0) {
    if (param_2 == 0xf) {
      param_6 = 1;
      uVar1 = FUN_10003d50(this);
      *param_5 = uVar1;
      if (param_6 != 0) {
        return 1;
      }
    }
    else if (param_2 == 5) {
      param_6 = 1;
      uVar1 = FUN_100091c0(this,5,param_3,param_4,&param_6);
      *param_5 = uVar1;
      if (param_6 != 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 0x24) {
        uVar1 = FUN_10002440(this,0x24,param_3,param_4);
        *param_5 = uVar1;
        return 1;
      }
      if (param_2 == 2) {
        param_6 = 1;
        uVar1 = FUN_10009d60(this);
        *param_5 = uVar1;
        if (param_6 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}



// Function: FUN_10009f70 at 10009f70

undefined4 __thiscall
FUN_10009f70(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = 1;
  if (param_6 != 0) {
    return 0;
  }
  iVar1 = FUN_10009ea0((void *)((int)this + 0x78),param_1,param_2,param_3,param_4,param_5,0);
  if (iVar1 == 0) {
    if (param_2 == 0x110) {
      local_8 = 1;
      uVar2 = FUN_10016490((undefined4 *)((int)this + -0x3c));
    }
    else if (param_2 == 0x53) {
      local_8 = 1;
      uVar2 = (**(code **)(*(int *)((int)this + 0xe0) + 4))(0x53,param_3,param_4,&local_8);
    }
    else {
      if (param_2 != 0x111) {
        return 0;
      }
      if ((short)param_3 == 0x66) {
        if ((short)((uint)param_3 >> 0x10) != 0) {
          return 0;
        }
        local_8 = 1;
        uVar2 = FUN_10010680((int)this + -0x3c);
      }
      else {
        if (param_3 != 0x67) {
          return 0;
        }
        local_8 = 1;
        uVar2 = FUN_10015210((int)this + -0x3c);
      }
    }
    *param_5 = uVar2;
    if (local_8 == 0) {
      return 0;
    }
  }
  return 1;
}



// Function: FUN_1000a090 at 1000a090

void __thiscall FUN_1000a090(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 < 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_1000ce30(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_1000a0c0 at 1000a0c0

void __thiscall
FUN_1000a0c0(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  FUN_10009f70((void *)((int)this + -0x78),param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000a0d0 at 1000a0d0

undefined4 __fastcall FUN_1000a0d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uStack_4c;
  undefined **local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_24;
  int local_20 [3];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a240;
  local_10 = ExceptionList;
  uStack_4c = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4c;
  ExceptionList = &local_10;
  local_24 = 0xffffffff;
  local_38 = 0;
  local_34 = 0;
  local_3c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_30 = 0x80004005;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_8._1_3_ = 0;
  local_8 = 7;
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    local_14 = (undefined1 *)&uStack_4c;
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10026788,local_20);
                    /* WARNING: Subroutine does not return */
    FUN_1000a090(&local_3c,iVar2);
  }
  local_8._0_1_ = 5;
  FUN_10016c40(local_20 + 2);
  local_8._0_1_ = 3;
  FUN_10016c40(local_20 + 1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10016c40(local_20);
  ExceptionList = local_10;
  return local_24;
}



// Function: Catch@1000a24c at 1000a24c

undefined4 Catch_1000a24c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a229;
}



// Function: FUN_1000a260 at 1000a260

void FUN_1000a260(void)

{
  HRESULT HVar1;
  uint uStack_3c;
  undefined **local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  LPVOID local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a280;
  local_10 = ExceptionList;
  uStack_3c = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_28 = 0;
  local_24 = 0;
  local_2c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_20 = 0;
  local_18 = (LPVOID)0x0;
  local_8 = 4;
  HVar1 = CoCreateInstance((IID *)&DAT_10026168,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10026770,&local_18);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_2c,HVar1);
}



// Function: Catch@1000a33f at 1000a33f

undefined1 * Catch_1000a33f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &LAB_1000a34c;
}



// Function: FUN_1000a380 at 1000a380

uint __cdecl FUN_1000a380(uint param_1)

{
  HMODULE hModule;
  HRSRC pHVar1;
  uint uVar2;
  int local_8;
  
  uVar2 = 0;
  hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10034964,0);
  local_8 = 1;
  while ((hModule != (HMODULE)0x0 && (uVar2 == 0))) {
    pHVar1 = FindResourceW(hModule,(LPCWSTR)((param_1 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
    if (pHVar1 != (HRSRC)0x0) {
      uVar2 = FUN_100016b0(hModule,pHVar1,param_1);
    }
    hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10034964,local_8);
    local_8 = local_8 + 1;
  }
  return uVar2;
}



// Function: FUN_1000a3f0 at 1000a3f0

undefined4 * __thiscall FUN_1000a3f0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  iVar2 = Ordinal_7(uVar1);
  if (iVar2 != 0) {
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)0x0;
    iVar2 = Ordinal_313(*this,uVar1,&param_1);
    if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(iVar2);
    }
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(undefined4 **)this = param_1;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a440 at 1000a440

void __fastcall FUN_1000a440(undefined4 *param_1)

{
  facet *pfVar1;
  
  if ((facet *)*param_1 != (facet *)0x0) {
    pfVar1 = std::locale::facet::_Decref((facet *)*param_1);
    if (pfVar1 != (facet *)0x0) {
      (*(code *)**(undefined4 **)pfVar1)(1);
    }
  }
  return;
}



// Function: FUN_1000a460 at 1000a460

bool __thiscall FUN_1000a460(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,*param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_1000a490 at 1000a490

void __thiscall FUN_1000a490(void *this,uint *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
                    /* WARNING: Load size is inaccurate */
  iVar5 = 0;
  puVar1 = (uint *)(**(code **)(*this + 0xc))();
  if (((((((puVar1[7] != 0 || puVar1[6] != 0) || puVar1[5] != 0) || puVar1[4] != 0) ||
        puVar1[3] != 0) || puVar1[2] != 0) || puVar1[1] != 0) || *puVar1 != 0) {
    uVar4 = *puVar1;
    puVar2 = puVar1;
    do {
      if ((uVar4 == param_2) || ((puVar2[5] <= param_2 && (param_2 <= puVar2[6])))) break;
      iVar5 = iVar5 + 1;
      uVar4 = puVar1[iVar5 * 8];
      puVar2 = puVar1 + iVar5 * 8;
    } while (((((((puVar1[iVar5 * 8 + 7] != 0 || puVar1[iVar5 * 8 + 6] != 0) ||
                 puVar1[iVar5 * 8 + 5] != 0) || puVar2[4] != 0) || puVar2[3] != 0) || puVar2[2] != 0
              ) || puVar2[1] != 0) || uVar4 != 0);
  }
  puVar1 = puVar1 + iVar5 * 8;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



// Function: FUN_1000a510 at 1000a510

void __fastcall FUN_1000a510(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1000a51c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x34) + 0x14))();
  return;
}



// Function: FUN_1000a520 at 1000a520

undefined4 FUN_1000a520(void)

{
  return 0x8b75;
}



// Function: FUN_1000a530 at 1000a530

undefined * FUN_1000a530(void)

{
  return &DAT_10027670;
}



// Function: FUN_1000a540 at 1000a540

void __thiscall FUN_1000a540(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 4);
  }
  *(undefined4 *)((int)this + 4) = *puVar1;
  *(undefined4 *)((int)this + 8) = puVar1[1];
  *(undefined ***)this = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return;
}



// Function: FUN_1000a570 at 1000a570

undefined4 FUN_1000a570(void)

{
  return 0;
}



// Function: Reset_back at 1000a580

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall std::basic_filebuf<unsigned short,struct std::char_traits<unsigned
   short> >::_Reset_back(void)
    private: void __thiscall std::basic_filebuf<wchar_t,struct std::char_traits<wchar_t>
   >::_Reset_back(void)
   
   Library: Visual Studio 2010 Release */

void __fastcall Reset_back(int param_1)

{
  undefined4 uVar1;
  
  if (**(int **)(param_1 + 0x10) == param_1 + 0x48) {
    uVar1 = *(undefined4 *)(param_1 + 0x40);
    **(int **)(param_1 + 0x10) = *(int *)(param_1 + 0x3c);
    **(undefined4 **)(param_1 + 0x20) = uVar1;
    **(undefined4 **)(param_1 + 0x30) = 0;
  }
  return;
}



// Function: FUN_1000a5b0 at 1000a5b0

void __fastcall FUN_1000a5b0(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1000a5c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_1000a5d0 at 1000a5d0

facet * __cdecl FUN_1000a5d0(locale *param_1)

{
  int iVar1;
  code *pcVar2;
  _Locimp *p_Var3;
  uint uVar4;
  facet *pfVar5;
  bad_cast local_28 [12];
  _Lockit local_1c [4];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a312;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_1c,0);
  pcVar2 = id_exref;
  local_8 = 0;
  local_14 = DAT_10034590;
  if (*(int *)id_exref == 0) {
    std::_Lockit::_Lockit(local_18,0);
    if (*(int *)pcVar2 == 0) {
      *(int *)_Id_cnt_exref = *(int *)_Id_cnt_exref + 1;
      *(undefined4 *)pcVar2 = *(undefined4 *)_Id_cnt_exref;
    }
    local_8 = local_8 & 0xffffff00;
    std::_Lockit::~_Lockit(local_18);
  }
  uVar4 = *(uint *)pcVar2;
  iVar1 = *(int *)param_1;
  if (uVar4 < *(uint *)(iVar1 + 0xc)) {
    pfVar5 = *(facet **)(*(int *)(iVar1 + 8) + uVar4 * 4);
    if (pfVar5 == (facet *)0x0) goto LAB_1000a662;
LAB_1000a681:
    if (pfVar5 != (facet *)0x0) goto LAB_1000a6d7;
  }
  else {
    pfVar5 = (facet *)0x0;
LAB_1000a662:
    if (*(char *)(iVar1 + 0x14) == '\0') goto LAB_1000a681;
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar4 < *(uint *)(p_Var3 + 0xc)) {
      pfVar5 = *(facet **)(*(int *)(p_Var3 + 8) + uVar4 * 4);
      goto LAB_1000a681;
    }
  }
  pfVar5 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar4 = std::ctype<wchar_t>::_Getcat(&local_14,param_1);
    pfVar5 = local_14;
    if (uVar4 == 0xffffffff) {
      std::bad_cast::bad_cast(local_28,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_1002b66c);
    }
    DAT_10034590 = local_14;
    std::locale::facet::_Incref(local_14);
    Facet_Register(pfVar5);
  }
LAB_1000a6d7:
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_1c);
  ExceptionList = local_10;
  return pfVar5;
}



// Function: FUN_1000a700 at 1000a700

void __fastcall FUN_1000a700(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000a710 at 1000a710

facet * __cdecl FUN_1000a710(locale *param_1)

{
  int iVar1;
  code *pcVar2;
  _Locimp *p_Var3;
  uint uVar4;
  facet *pfVar5;
  bad_cast local_28 [12];
  _Lockit local_1c [4];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a312;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_1c,0);
  pcVar2 = id_exref;
  local_8 = 0;
  local_14 = DAT_10034594;
  if (*(int *)id_exref == 0) {
    std::_Lockit::_Lockit(local_18,0);
    if (*(int *)pcVar2 == 0) {
      *(int *)_Id_cnt_exref = *(int *)_Id_cnt_exref + 1;
      *(undefined4 *)pcVar2 = *(undefined4 *)_Id_cnt_exref;
    }
    local_8 = local_8 & 0xffffff00;
    std::_Lockit::~_Lockit(local_18);
  }
  uVar4 = *(uint *)pcVar2;
  iVar1 = *(int *)param_1;
  if (uVar4 < *(uint *)(iVar1 + 0xc)) {
    pfVar5 = *(facet **)(*(int *)(iVar1 + 8) + uVar4 * 4);
    if (pfVar5 == (facet *)0x0) goto LAB_1000a7a2;
LAB_1000a7c1:
    if (pfVar5 != (facet *)0x0) goto LAB_1000a817;
  }
  else {
    pfVar5 = (facet *)0x0;
LAB_1000a7a2:
    if (*(char *)(iVar1 + 0x14) == '\0') goto LAB_1000a7c1;
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar4 < *(uint *)(p_Var3 + 0xc)) {
      pfVar5 = *(facet **)(*(int *)(p_Var3 + 8) + uVar4 * 4);
      goto LAB_1000a7c1;
    }
  }
  pfVar5 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar4 = std::codecvt<wchar_t,char,int>::_Getcat(&local_14,param_1);
    pfVar5 = local_14;
    if (uVar4 == 0xffffffff) {
      std::bad_cast::bad_cast(local_28,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_1002b66c);
    }
    DAT_10034594 = local_14;
    std::locale::facet::_Incref(local_14);
    Facet_Register(pfVar5);
  }
LAB_1000a817:
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_1c);
  ExceptionList = local_10;
  return pfVar5;
}



// Function: FUN_1000a840 at 1000a840

undefined4 * __thiscall FUN_1000a840(void *this,byte param_1)

{
  *(undefined ***)this =
       CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a870 at 1000a870

int * __thiscall FUN_1000a870(void *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
    Ordinal_6(*this);
    if (param_1 == 0) {
      *(undefined4 *)this = 0;
    }
    else {
      iVar1 = Ordinal_2(param_1);
      *(int *)this = iVar1;
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_1000a8b0 at 1000a8b0

void __fastcall FUN_1000a8b0(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_1000a8d0 at 1000a8d0

bool __thiscall FUN_1000a8d0(void *this,HMODULE param_1,uint param_2)

{
  HRSRC pHVar1;
  undefined2 *puVar2;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 != (HRSRC)0x0) {
    puVar2 = (undefined2 *)FUN_100016b0(param_1,pHVar1,param_2);
    if (puVar2 != (undefined2 *)0x0) {
      iVar3 = Ordinal_4(puVar2 + 1,*puVar2);
      *(int *)this = iVar3;
      return iVar3 != 0;
    }
  }
  *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
  return *this != 0;
}



// Function: FUN_1000a950 at 1000a950

bool __thiscall FUN_1000a950(void *this,uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  puVar1 = (undefined2 *)FUN_1000a380(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    iVar2 = Ordinal_4(puVar1 + 1,*puVar1);
    *(int *)this = iVar2;
    return iVar2 != 0;
  }
  *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
  return *this != 0;
}



// Function: FUN_1000a9a0 at 1000a9a0

void __fastcall FUN_1000a9a0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_1000a9b0 at 1000a9b0

undefined2 * __thiscall FUN_1000a9b0(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(iVar1);
  }
  *(undefined2 *)this = 8;
  iVar1 = *param_1;
  if (iVar1 != 0) {
    uVar2 = Ordinal_149(iVar1);
    iVar1 = Ordinal_150(*param_1,uVar2);
  }
  *(int *)((int)this + 8) = iVar1;
  if ((iVar1 == 0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_1000aa20 at 1000aa20

void __fastcall FUN_1000aa20(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a343;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aaa0 at 1000aaa0

void __fastcall FUN_1000aaa0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a343;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ab20 at 1000ab20

void __fastcall FUN_1000ab20(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a343;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aba0 at 1000aba0

undefined4 * __thiscall FUN_1000aba0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a373;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ac30 at 1000ac30

undefined4 * __thiscall FUN_1000ac30(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a373;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000acc0 at 1000acc0

undefined4 * __thiscall FUN_1000acc0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a373;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ad50 at 1000ad50

undefined4 __cdecl FUN_1000ad50(wchar_t param_1,FILE *param_2)

{
  wint_t wVar1;
  undefined2 extraout_var;
  
  wVar1 = fputwc(param_1,param_2);
  return CONCAT31((int3)(CONCAT22(extraout_var,wVar1) >> 8),wVar1 != 0xffff);
}



// Function: FUN_1000ad80 at 1000ad80

void __fastcall FUN_1000ad80(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000ad90 at 1000ad90

void __fastcall FUN_1000ad90(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000ada0 at 1000ada0

short __fastcall FUN_1000ada0(int *param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  
  psVar1 = *(short **)param_1[8];
  if ((psVar1 != (short *)0x0) && (psVar1 < psVar1 + *(int *)param_1[0xc])) {
    return *psVar1;
  }
  sVar2 = (**(code **)(*param_1 + 0x1c))();
  sVar3 = -1;
  if (sVar2 != -1) {
    (**(code **)(*param_1 + 0x10))(sVar2);
    sVar3 = sVar2;
  }
  return sVar3;
}



// Function: FUN_1000adf0 at 1000adf0

undefined4 __fastcall FUN_1000adf0(int *param_1)

{
  short sVar1;
  int iVar2;
  
  if (param_1[0x15] != 0) {
    sVar1 = (**(code **)(*param_1 + 0xc))(0xffff);
    if (sVar1 != -1) {
      iVar2 = fflush((FILE *)param_1[0x15]);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}



// Function: Set_back at 1000ae30

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall std::basic_filebuf<unsigned short,struct std::char_traits<unsigned
   short> >::_Set_back(void)
    private: void __thiscall std::basic_filebuf<wchar_t,struct std::char_traits<wchar_t>
   >::_Set_back(void)
   
   Library: Visual Studio 2010 Release */

void __fastcall Set_back(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x10);
  iVar1 = param_1 + 0x48;
  if (iVar2 != iVar1) {
    *(int *)(param_1 + 0x3c) = iVar2;
    *(int *)(param_1 + 0x40) = **(int **)(param_1 + 0x20) + **(int **)(param_1 + 0x30) * 2;
  }
  **(int **)(param_1 + 0x10) = iVar1;
  **(int **)(param_1 + 0x20) = iVar1;
  **(int **)(param_1 + 0x30) = (param_1 - iVar1) + 0x4a >> 1;
  return;
}



// Function: FUN_1000ae70 at 1000ae70

uint __thiscall FUN_1000ae70(void *this,ushort param_1)

{
  uint uVar1;
  wint_t wVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if (((uVar1 != 0) && (**(uint **)((int)this + 0x10) < uVar1)) &&
     ((param_1 == 0xffff || (*(ushort *)(uVar1 - 2) == param_1)))) {
    **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) + 1;
    **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + -2;
    if (param_1 != 0xffff) {
      return (uint)param_1;
    }
    return 0;
  }
  if ((*(FILE **)((int)this + 0x54) != (FILE *)0x0) && (param_1 != 0xffff)) {
    if (*(int *)((int)this + 0x44) == 0) {
      wVar2 = ungetwc(param_1,*(FILE **)((int)this + 0x54));
      uVar3 = extraout_var;
      if (wVar2 != 0xffff) goto LAB_1000aefd;
    }
    if ((ushort *)**(int **)((int)this + 0x20) != (ushort *)((int)this + 0x48)) {
      *(ushort *)((int)this + 0x48) = param_1;
      Set_back((int)this);
      uVar3 = extraout_var_00;
LAB_1000aefd:
      return CONCAT22(uVar3,param_1);
    }
  }
  return 0xffff;
}



// Function: FUN_1000af20 at 1000af20

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000af20(void *this,char *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(FILE **)((int)this + 0x54) != (FILE *)0x0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      iVar2 = 4;
    }
    else {
      iVar2 = 0;
    }
    iVar2 = setvbuf(*(FILE **)((int)this + 0x54),param_1,iVar2,param_2 * 2);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)((int)this + 0x54);
      *(undefined1 *)((int)this + 0x50) = 1;
      *(undefined1 *)((int)this + 0x4a) = 0;
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *(undefined4 *)((int)this + 0x54) = uVar1;
      *(undefined4 *)((int)this + 0x4c) = DAT_1003458c;
      *(undefined4 *)((int)this + 0x44) = 0;
      return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
    }
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_1000af90 at 1000af90

void __thiscall FUN_1000af90(void *this,locale *param_1)

{
  bool bVar1;
  facet *this_00;
  
  this_00 = FUN_1000a710(param_1);
  bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this_00);
  if (bVar1) {
    *(undefined4 *)((int)this + 0x44) = 0;
    return;
  }
  *(facet **)((int)this + 0x44) = this_00;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  return;
}



// Function: FUN_1000afd0 at 1000afd0

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000afd0(void *this,wchar_t *param_1,int param_2,facet *param_3)

{
  bool bVar1;
  _iobuf *p_Var2;
  locale *plVar3;
  facet *pfVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a398;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)((int)this + 0x54) == 0) {
    p_Var2 = std::_Fiopen(param_1,param_2,(int)param_3);
    if (p_Var2 != (_iobuf *)0x0) {
      *(undefined1 *)((int)this + 0x50) = 1;
      *(undefined1 *)((int)this + 0x4a) = 0;
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *(_iobuf **)((int)this + 0x54) = p_Var2;
      *(undefined4 *)((int)this + 0x4c) = DAT_1003458c;
      *(undefined4 *)((int)this + 0x44) = 0;
      plVar3 = (locale *)
               std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::getloc
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      local_8 = 0;
      pfVar4 = FUN_1000a710(plVar3);
      bVar1 = std::codecvt_base::always_noconv((codecvt_base *)pfVar4);
      if (bVar1) {
        *(undefined4 *)((int)this + 0x44) = 0;
      }
      else {
        *(facet **)((int)this + 0x44) = pfVar4;
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      }
      local_8 = 0xffffffff;
      if (param_3 != (facet *)0x0) {
        pfVar4 = std::locale::facet::_Decref(param_3);
        if (pfVar4 != (facet *)0x0) {
          (*(code *)**(undefined4 **)pfVar4)(1);
        }
      }
      ExceptionList = local_10;
      return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
    }
  }
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_1000b0d0 at 1000b0d0

void __fastcall FUN_1000b0d0(int *param_1)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3c8;
  local_10 = ExceptionList;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = std::uncaught_exception();
  if (!bVar2) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(uVar3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b150 at 1000b150

void __thiscall FUN_1000b150(void *this,int param_1,size_t param_2,char param_3)

{
  if (param_2 == 1) {
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    *(char *)((int)this + param_1) = param_3;
    return;
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  memset((void *)((int)this + param_1),(int)param_3,param_2);
  return;
}



// Function: FUN_1000b190 at 1000b190

void * FUN_1000b190(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019519;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)0x0;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1002a6f8);
  }
  ExceptionList = local_10;
  return pvVar1;
}



// Function: FUN_1000b220 at 1000b220

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_1000b220(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  uint *puVar4;
  bool bVar5;
  ushort uVar6;
  wchar_t wVar7;
  char *pcVar8;
  locale *plVar9;
  facet *this_00;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar10;
  uint uStack_48;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a410;
  local_10 = ExceptionList;
  uStack_48 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = 0;
  pcVar8 = param_2;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  local_30 = (int)pcVar8 - (int)(param_2 + 1);
  local_2c = 0;
  iVar2 = *(int *)(*(int *)param_1 + 4);
  uVar3 = *(uint *)(param_1 + iVar2 + 0x20);
  local_24 = *(int *)(param_1 + iVar2 + 0x24);
  if ((local_24 < 0) ||
     ((local_24 < 1 && (((uVar3 == 0 || (local_24 < 0)) || ((local_24 < 1 && (uVar3 <= local_30)))))
      ))) {
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = uVar3 - local_30;
    local_24 = local_24 - (uint)(uVar3 < local_30);
  }
  puVar4 = &uStack_48;
  if (*(int **)(param_1 + iVar2 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + iVar2 + 0x38) + 4))();
    puVar4 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar4;
  local_8 = 0;
  if ((*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) == 0) &&
     (*(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
       (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c) !=
      (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush
              (*(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
                (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c));
  }
  local_8 = 1;
  if (*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) != 0) {
    local_18 = 4;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (param_1 + *(int *)(*(int *)param_1 + 4)),4,false);
    local_8 = 5;
    bVar5 = std::uncaught_exception();
    if (!bVar5) {
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(param_1);
    }
    local_8 = 0xffffffff;
    if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  plVar9 = (locale *)std::ios_base::getloc((ios_base *)(param_1 + *(int *)(*(int *)param_1 + 4)));
  local_8._0_1_ = 3;
  this_00 = FUN_1000a5d0(plVar9);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000a440(&local_1c);
  if ((*(uint *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x14) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_1000b382;
      uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
      if (uVar6 == 0xffff) break;
      bVar5 = local_28 != 0;
      local_28 = local_28 + -1;
      local_24 = local_24 + -1 + (uint)bVar5;
    }
    local_18 = local_18 | 4;
  }
LAB_1000b382:
  do {
    if (local_18 != 0) goto LAB_1000b426;
    if ((local_2c < 0) || ((local_2c < 1 && (local_30 == 0)))) break;
    this = *(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
            (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38);
    wVar7 = std::ctype<wchar_t>::widen((ctype<wchar_t> *)this_00,*param_2);
    uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc(this,wVar7);
    if (uVar6 == 0xffff) {
      local_18 = 4;
    }
    bVar5 = local_30 != 0;
    local_30 = local_30 - 1;
    local_2c = local_2c + -1 + (uint)bVar5;
    param_2 = param_2 + 1;
  } while( true );
LAB_1000b3f6:
  if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_1000b426;
  uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                     *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
  if (uVar6 == 0xffff) {
    local_18 = local_18 | 4;
LAB_1000b426:
    iVar2 = *(int *)(*(int *)param_1 + 4);
    *(undefined4 *)(param_1 + iVar2 + 0x20) = 0;
    *(undefined4 *)(param_1 + iVar2 + 0x24) = 0;
    local_8 = 1;
    pbVar10 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)FUN_1000b470();
    return pbVar10;
  }
  bVar5 = local_28 != 0;
  local_28 = local_28 + -1;
  local_24 = local_24 + -1 + (uint)bVar5;
  goto LAB_1000b3f6;
}



// Function: Catch@1000b44c at 1000b44c

undefined * Catch_1000b44c(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b46d;
}



// Function: FUN_1000b470 at 1000b470

void FUN_1000b470(void)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x34);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000b4d0 at 1000b4d0

void FUN_1000b4d0(int *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  ushort uVar5;
  wchar_t *pwVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  __int64 _Var11;
  undefined2 uVar12;
  undefined2 uVar13;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a448;
  local_10 = ExceptionList;
  uVar12 = (undefined2)(DAT_100344b0 ^ (uint)&stack0xfffffffc);
  uVar13 = (undefined2)((DAT_100344b0 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  bVar10 = false;
  pwVar6 = param_2;
  do {
    wVar1 = *pwVar6;
    pwVar6 = pwVar6 + 1;
  } while (wVar1 != L'\0');
  uVar7 = (int)pwVar6 - (int)(param_2 + 1) >> 1;
  iVar2 = *(int *)(*param_1 + 4);
  uVar3 = *(uint *)(iVar2 + 0x20 + (int)param_1);
  local_20 = *(int *)(iVar2 + 0x24 + (int)param_1);
  if (((local_20 < 0) || (((local_20 < 1 && (uVar3 == 0)) || (local_20 < 0)))) ||
     ((local_20 < 1 && (uVar3 <= uVar7)))) {
    iVar8 = 0;
    local_20 = 0;
  }
  else {
    iVar8 = uVar3 - uVar7;
    local_20 = local_20 - (uint)(uVar3 < uVar7);
  }
  piVar4 = *(int **)(iVar2 + 0x38 + (int)param_1);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
              (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this);
  }
  local_8 = 1;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
    FUN_1000b6c3();
    return;
  }
  local_8 = 2;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_20 < 0) || ((local_20 < 1 && (iVar8 == 0)))) goto LAB_1000b600;
      uVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar5 == 0xffff) break;
      bVar9 = iVar8 != 0;
      iVar8 = iVar8 + -1;
      local_20 = local_20 + -1 + (uint)bVar9;
    }
    bVar10 = true;
LAB_1000b600:
    if (bVar10) goto LAB_1000b630;
  }
  _Var11 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                     (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                       (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                      (ulonglong)CONCAT22(uVar13,uVar12) << 0x20);
  if (((uint)_Var11 == uVar7) && ((int)((ulonglong)_Var11 >> 0x20) == 0)) {
    while ((-1 < local_20 &&
           (((0 < local_20 || (iVar8 != 0)) &&
            (uVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                               (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                                 (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                                *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1)),
            uVar5 != 0xffff))))) {
      bVar10 = iVar8 != 0;
      iVar8 = iVar8 + -1;
      local_20 = local_20 + -1 + (uint)bVar10;
    }
  }
LAB_1000b630:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 1;
  FUN_1000b6c3();
  return;
}



// Function: Catch@1000b69f at 1000b69f

undefined * Catch_1000b69f(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b6c0;
}



// Function: FUN_1000b6c3 at 1000b6c3

void FUN_1000b6c3(void)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  bVar1 = std::uncaught_exception();
  this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x28);
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000b730 at 1000b730

HRESULT __fastcall FUN_1000b730(void *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  uint local_38 [2];
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a490;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000a490(param_1,local_38,*(uint *)((int)param_1 + 0x14));
  if (local_30 == 0) {
    HVar3 = CoCreateInstance((IID *)&DAT_10027640,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10027770,
                             (LPVOID *)((int)param_1 + 8));
    if (-1 < HVar3) {
      puVar4 = *(undefined4 **)((int)param_1 + 8);
      HVar3 = (**(code **)*puVar4)(puVar4,&DAT_100277ac,(int)param_1 + 0x10,uVar2);
      ExceptionList = local_10;
      return HVar3;
    }
  }
  else {
    local_14 = (int *)0x0;
    local_8 = 1;
    HVar3 = CoCreateInstance((IID *)&DAT_10027650,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10027790,&local_14
                            );
    if (-1 < HVar3) {
      (**(code **)*local_14)(local_14,&DAT_100277ac,(int)param_1 + 0x10);
      (**(code **)*local_14)(local_14,&DAT_10027770,(int)param_1 + 8);
      puVar4 = (undefined4 *)((int)param_1 + 4);
      HVar3 = (**(code **)*local_14)(local_14,&DAT_100277bc,puVar4);
      if (-1 < HVar3) {
        local_18 = 0;
        local_8._0_1_ = 2;
        FUN_1000a950(&local_18,local_30);
        uVar1 = local_18;
        (**(code **)(*(int *)*puVar4 + 0x10))((int *)*puVar4,local_18);
        (**(code **)(*(int *)*puVar4 + 0x18))((int *)*puVar4,local_28);
        (**(code **)(*(int *)*puVar4 + 0x20))((int *)*puVar4,local_2c);
        local_8 = CONCAT31(local_8._1_3_,1);
        Ordinal_6(uVar1);
      }
    }
    local_8 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  ExceptionList = local_10;
  return HVar3;
}



// Function: FUN_1000b8a0 at 1000b8a0

void __fastcall FUN_1000b8a0(int param_1)

{
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4c8;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0xce38368b;
  local_34 = 0x46c12bd3;
  local_30 = 0x7c4a4ab3;
  local_2c = 0x9a7e3936;
  local_28 = 0;
  local_4c = 0;
  local_48 = 0;
  local_50 = 0;
  local_54 = 0;
  local_18 = 0;
  local_3c = 0;
  local_40 = 0;
  local_24 = 0;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  local_44 = (int *)0x0;
  local_8 = 1;
  (**(code **)**(undefined4 **)(param_1 + 8))
            (*(undefined4 **)(param_1 + 8),&DAT_100283cc,&local_44,local_14);
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))
            (*(int **)(param_1 + 0xc),&local_40,0,&local_54,local_44,0);
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))(local_44);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b9a0 at 1000b9a0

void __fastcall FUN_1000b9a0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a516;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ba20 at 1000ba20

void __fastcall FUN_1000ba20(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a343;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000baa0 at 1000baa0

undefined4 * __thiscall FUN_1000baa0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a373;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000bb30 at 1000bb30

int * __thiscall FUN_1000bb30(void *this,uint param_1,uint param_2)

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



// Function: FUN_1000bbc0 at 1000bbc0

void __thiscall FUN_1000bbc0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a540;
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
  FUN_1000b190((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_1000bc7c();
  return;
}



// Function: Catch@1000bc49 at 1000bc49

undefined * Catch_1000bc49(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_1000b190((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000bc73;
}



// Function: FUN_1000bc7c at 1000bc7c

void FUN_1000bc7c(void)

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



// Function: Catch@1000bcdb at 1000bcdb

void Catch_1000bcdb(void)

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



// Function: FUN_1000bd10 at 1000bd10

void __fastcall FUN_1000bd10(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a5b7;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandler::vftable;
  local_8 = 3;
  if (7 < (uint)param_1[0xb]) {
    operator_delete((void *)param_1[6]);
  }
  param_1[0xb] = 7;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8._0_1_ = 1;
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bdf0 at 1000bdf0

void __fastcall FUN_1000bdf0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(piVar1,0);
  }
  (**(code **)**(undefined4 **)(param_1 + 0xc))
            (*(undefined4 **)(param_1 + 0xc),&DAT_10027770,piVar1);
  Ordinal_201(0,*piVar1);
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    Ordinal_30((int *)(param_1 + 0xc),0);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    Ordinal_30(param_1 + 0x10,0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_30((int *)(param_1 + 4),0);
  }
  return;
}



// Function: FUN_1000be70 at 1000be70

HRESULT __fastcall FUN_1000be70(int param_1)

{
  int *piVar1;
  int iVar2;
  HRESULT HVar3;
  LPVOID *ppv;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(piVar1,0);
  }
  iVar2 = Ordinal_200(0,piVar1);
  if (iVar2 == 1) {
    HVar3 = CoCreateInstance((IID *)&DAT_10027660,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10027780,
                             (LPVOID *)(param_1 + 0xc));
    return HVar3;
  }
  ppv = (LPVOID *)(param_1 + 0xc);
  if (*ppv != (LPVOID)0x0) {
    Ordinal_30(ppv,0);
  }
  iVar2 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_10027780,ppv);
  if (iVar2 < 0) {
    if (*piVar1 != 0) {
      Ordinal_30(piVar1,0);
    }
    iVar2 = CoCreateInstance((IID *)&DAT_10027660,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10027780,ppv);
  }
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0);
  }
  return iVar2;
}



// Function: FUN_1000bf10 at 1000bf10

undefined4 * __thiscall FUN_1000bf10(void *this,byte param_1)

{
  FUN_1000bd10((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bf40 at 1000bf40

void __fastcall FUN_1000bf40(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a637;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000bd10((undefined4 *)(param_1 + 0x10));
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x6c) != '\0') {
    *(undefined1 *)(param_1 + 0x6c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x54));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bff0 at 1000bff0

void __fastcall FUN_1000bff0(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_1000c020 at 1000c020

undefined4 FUN_1000c020(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_30(param_1 + 4,0);
  }
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(param_1 + 8,0);
  }
  return 1;
}



// Function: FUN_1000c060 at 1000c060

void __thiscall FUN_1000c060(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  FUN_1000be70((int)this);
  FUN_1000b730(this);
  FUN_1000b8a0((int)this);
  return;
}



// Function: FUN_1000c090 at 1000c090

undefined4 * __fastcall FUN_1000c090(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a70e;
  local_10 = ExceptionList;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  piVar1 = param_1 + 1;
  *param_1 = CComECMPropertyPageHelperImpl<class_CImmobilizerInstallationLogicImpl>::vftable;
  *piVar1 = 0;
  piVar2 = param_1 + 2;
  *piVar2 = 0;
  local_8 = 6;
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0,uVar3);
  }
  if (*piVar2 != 0) {
    Ordinal_30(piVar2,0,uVar3);
  }
  param_1[4] = CComErrorHandler::vftable;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xf] = 7;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[0x12] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c1a0 at 1000c1a0

int * __thiscall FUN_1000c1a0(void *this,uint param_1,char param_2)

{
  uint uVar1;
  int extraout_EAX;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 0x10);
  if (-iVar2 - 1U <= param_1) {
    std::_Xlength_error("string too long");
    iVar2 = extraout_EAX;
  }
  if (param_1 != 0) {
    uVar1 = iVar2 + param_1;
    if (uVar1 == 0xffffffff) {
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_1000bbc0(this,uVar1);
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined1 *)this = 0;
      return (int *)this;
    }
    FUN_1000b150(this,*(int *)((int)this + 0x10),param_1,param_2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*this + uVar1) = 0;
      return (int *)this;
    }
    *(undefined1 *)((int)this + uVar1) = 0;
  }
  return (int *)this;
}



// Function: FUN_1000c250 at 1000c250

void __fastcall FUN_1000c250(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  int iVar1;
  char *****pppppcVar2;
  char *pcVar3;
  wchar_t *local_3c;
  char *local_38;
  wchar_t local_34;
  wchar_t local_32;
  char ****local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a738;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((**(int **)(param_1 + 0x20) == 0) ||
     (**(uint **)(param_1 + 0x20) + **(int **)(param_1 + 0x30) * 2 <= **(uint **)(param_1 + 0x20)))
  {
    if (*(int *)(param_1 + 0x54) != 0) {
      if ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)**(int **)(param_1 + 0x10)
          == param_1 + 0x48) {
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  (param_1,*(wchar_t **)(param_1 + 0x3c),*(wchar_t **)(param_1 + 0x40),
                   *(wchar_t **)(param_1 + 0x40));
      }
      if (*(int *)(param_1 + 0x44) == 0) {
        fgetwc(*(FILE **)(param_1 + 0x54));
      }
      else {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
        local_8 = 0;
        iVar1 = fgetc(*(FILE **)(param_1 + 0x54));
        if (iVar1 != -1) {
          do {
            FUN_1000c1a0(local_30,1,(char)iVar1);
            pppppcVar2 = (char *****)local_30[0];
            if (local_1c < 0x10) {
              pppppcVar2 = local_30;
            }
            iVar1 = std::codecvt<wchar_t,char,int>::in
                              (*(codecvt<wchar_t,char,int> **)(param_1 + 0x44),
                               (int *)(param_1 + 0x4c),(char *)pppppcVar2,
                               (char *)((int)pppppcVar2 + local_20),&local_38,&local_34,&local_32,
                               &local_3c);
            if (iVar1 < 0) break;
            if (iVar1 < 2) {
              if (local_3c != &local_34) {
                pppppcVar2 = (char *****)local_30[0];
                if (local_1c < 0x10) {
                  pppppcVar2 = local_30;
                }
                for (pcVar3 = (char *)((int)pppppcVar2 + (local_20 - (int)local_38));
                    0 < (int)pcVar3; pcVar3 = pcVar3 + -1) {
                  ungetc((int)local_38[(int)(pcVar3 + -1)],*(FILE **)(param_1 + 0x54));
                }
LAB_1000c431:
                local_8 = 0xffffffff;
                FUN_1000bff0(local_30);
                goto LAB_1000c3e2;
              }
              pppppcVar2 = (char *****)local_30[0];
              if (local_1c < 0x10) {
                pppppcVar2 = local_30;
              }
              FUN_1000bb30(local_30,0,(int)local_38 - (int)pppppcVar2);
            }
            else {
              if (iVar1 != 3) break;
              if (1 < local_20) {
                pppppcVar2 = (char *****)local_30[0];
                if (local_1c < 0x10) {
                  pppppcVar2 = local_30;
                }
                memcpy_s(&local_34,2,pppppcVar2,2);
                goto LAB_1000c431;
              }
            }
            iVar1 = fgetc(*(FILE **)(param_1 + 0x54));
          } while (iVar1 != -1);
        }
        local_8 = 0xffffffff;
        FUN_1000bff0(local_30);
      }
    }
  }
  else {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Gninc(param_1);
  }
LAB_1000c3e2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c450 at 1000c450

void __fastcall FUN_1000c450(int *param_1)

{
  short sVar1;
  int iVar2;
  char ****ppppcVar3;
  size_t sVar4;
  size_t _Count;
  char *local_34;
  char ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a768;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((param_1[0x11] != 0) && (*(char *)((int)param_1 + 0x4a) != '\0')) &&
     (sVar1 = (**(code **)(*param_1 + 0xc))(0xffff,local_14), sVar1 != -1)) {
    local_1c = 0xf;
    local_30 = (char ***)0x0;
    local_2c = 0;
    local_20 = 8;
    local_28 = 0;
    local_8 = 0;
    while( true ) {
      ppppcVar3 = (char ****)local_30;
      if (local_1c < 0x10) {
        ppppcVar3 = &local_30;
      }
      iVar2 = std::codecvt<wchar_t,char,int>::unshift
                        ((codecvt<wchar_t,char,int> *)param_1[0x11],param_1 + 0x13,(char *)ppppcVar3
                         ,(char *)((int)ppppcVar3 + local_20),&local_34);
      if (iVar2 != 0) break;
      *(undefined1 *)((int)param_1 + 0x4a) = 0;
LAB_1000c51f:
      ppppcVar3 = (char ****)local_30;
      if (local_1c < 0x10) {
        ppppcVar3 = &local_30;
      }
      _Count = (int)local_34 - (int)ppppcVar3;
      if (_Count != 0) {
        ppppcVar3 = (char ****)local_30;
        if (local_1c < 0x10) {
          ppppcVar3 = &local_30;
        }
        sVar4 = fwrite(ppppcVar3,1,_Count,(FILE *)param_1[0x15]);
        if (_Count != sVar4) goto LAB_1000c509;
      }
      if (*(char *)((int)param_1 + 0x4a) == '\0') goto LAB_1000c576;
      if (_Count == 0) {
        FUN_1000c1a0(&local_30,8,'\0');
      }
    }
    if (iVar2 == 1) goto LAB_1000c51f;
    if (iVar2 != 3) {
LAB_1000c509:
      local_8 = 0xffffffff;
      FUN_1000bff0(&local_30);
      goto LAB_1000c587;
    }
LAB_1000c576:
    local_8 = 0xffffffff;
    FUN_1000bff0(&local_30);
  }
LAB_1000c587:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c5b0 at 1000c5b0

void __fastcall FUN_1000c5b0(int *param_1)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  LPCWSTR lpLibFileName;
  HMODULE hLibModule;
  errno_t eVar5;
  int iVar6;
  undefined2 *puVar7;
  wchar_t *pwVar8;
  LPCWSTR **lpString;
  uint local_60;
  uint local_5c;
  int local_4c;
  uint local_44;
  wchar_t *local_40;
  int *local_3c;
  char local_35;
  wchar_t *local_34;
  LPCWSTR *local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001a7b0;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar8 = (wchar_t *)0x0;
  local_35 = '\0';
  local_34 = (wchar_t *)0x0;
  local_8 = 0;
  local_3c = param_1;
  local_14 = uVar2;
  FUN_1000a490(param_1,&local_60,param_1[5]);
  if (local_5c == 0) {
    if (local_44 != 0) {
      FUN_1000a950(&local_34,local_44);
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (LPCWSTR *)((uint)local_30[0] & 0xffff0000);
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*param_1 + 8))(local_30);
      uVar3 = lstrlenW(L"_");
      FUN_10002da0(&local_34,&DAT_10026978,uVar3);
      if (local_20 == 0) {
        FUN_100057e0(local_30,(int *)&DAT_1002799c,2);
      }
      lpString = (LPCWSTR **)local_30[0];
      if (local_1c < 8) {
        lpString = local_30;
      }
      uVar3 = lstrlenW((LPCWSTR)lpString);
      FUN_10002da0(&local_34,lpString,uVar3);
      uVar3 = lstrlenW(L".dll");
      FUN_10002da0(&local_34,L".dll",uVar3);
      pwVar8 = local_34;
      piVar4 = FUN_10003030(&local_40,(int)local_34);
      local_8._0_1_ = 2;
      if ((undefined4 *)*piVar4 == (undefined4 *)0x0) {
        lpLibFileName = (LPCWSTR)0x0;
      }
      else {
        lpLibFileName = *(LPCWSTR *)*piVar4;
      }
      hLibModule = LoadLibraryW(lpLibFileName);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_100072e0(&local_40);
      if (hLibModule != (HMODULE)0x0) {
        local_35 = FUN_1000a8d0(&local_34,hLibModule,local_3c[5] - local_4c);
        FreeLibrary(hLibModule);
        pwVar8 = local_34;
      }
      local_8 = local_8 & 0xffffff00;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (LPCWSTR *)((uint)local_30[0] & 0xffff0000);
      param_1 = local_3c;
      pwVar1 = local_34;
      if (local_35 != '\0') goto LAB_1000c839;
    }
    local_40 = (wchar_t *)operator_new__(0x40);
    if (pwVar8 != 
        L"<ErrorInfo><Description>No description has been defined or could be loaded for error identifier "
       ) {
      Ordinal_6(pwVar8,uVar2);
      local_34 = (wchar_t *)
                 Ordinal_2(
                          L"<ErrorInfo><Description>No description has been defined or could be loaded for error identifier "
                          );
      if (local_34 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
    }
    if (local_40 != (wchar_t *)0x0) {
      eVar5 = _ltow_s(param_1[5],local_40,0x20,10);
      if (eVar5 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x80070057);
      }
      if (eVar5 == 0) {
        local_3c = (int *)0x0;
      }
      else {
        local_3c = (int *)Ordinal_4(0,eVar5);
        if (local_3c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100011a0(0x8007000e);
        }
      }
      piVar4 = local_3c;
      local_8._0_1_ = 3;
      FUN_1000a3f0(&local_34,&local_3c);
      local_8 = (uint)local_8._1_3_ << 8;
      Ordinal_6(piVar4);
    }
    uVar2 = lstrlenW(L".");
    iVar6 = FUN_10002da0(&local_34,&DAT_10026974,uVar2);
    if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(iVar6);
    }
    uVar2 = lstrlenW(L"</Description></ErrorInfo>");
    iVar6 = FUN_10002da0(&local_34,L"</Description></ErrorInfo>",uVar2);
    if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(iVar6);
    }
    operator_delete__(local_40);
    pwVar8 = local_34;
    pwVar1 = local_34;
  }
  else {
    Ordinal_6(0,uVar2);
    local_34 = (wchar_t *)0x0;
    puVar7 = (undefined2 *)FUN_1000a380(local_5c);
    pwVar1 = pwVar8;
    if (puVar7 != (undefined2 *)0x0) {
      pwVar8 = (wchar_t *)Ordinal_4(puVar7 + 1,*puVar7);
      pwVar1 = pwVar8;
    }
  }
LAB_1000c839:
  local_34 = pwVar1;
  (**(code **)(*(int *)param_1[4] + 0x14))((int *)param_1[4],pwVar8);
  local_8 = 0xffffffff;
  Ordinal_6(pwVar8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c870 at 1000c870

void __thiscall FUN_1000c870(void *this,wchar_t param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  int iVar3;
  char ****ppppcVar4;
  size_t sVar5;
  size_t _Count;
  wchar_t *local_3c;
  char *local_38;
  undefined4 local_34;
  char ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a738;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != L'\xffff') {
    uVar1 = **(uint **)((int)this + 0x24);
    if ((uVar1 == 0) || (uVar1 + **(int **)((int)this + 0x34) * 2 <= uVar1)) {
      if (*(int *)((int)this + 0x54) != 0) {
        if (**(int **)((int)this + 0x10) == (int)this + 0x48) {
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     *(wchar_t **)((int)this + 0x3c),*(wchar_t **)((int)this + 0x40),
                     *(wchar_t **)((int)this + 0x40));
        }
        if (*(int *)((int)this + 0x44) != 0) {
          local_1c = 0xf;
          local_34 = (uint)(ushort)param_1;
          local_30 = (char ***)0x0;
          local_2c = 0;
          local_20 = 8;
          local_28 = 0;
          local_8 = 0;
LAB_1000c96b:
          ppppcVar4 = (char ****)local_30;
          if (local_1c < 0x10) {
            ppppcVar4 = &local_30;
          }
          iVar3 = std::codecvt<wchar_t,char,int>::out
                            (*(codecvt<wchar_t,char,int> **)((int)this + 0x44),
                             (int *)((int)this + 0x4c),(wchar_t *)&local_34,
                             (wchar_t *)((int)&local_34 + 2),&local_3c,(char *)ppppcVar4,
                             (char *)((int)ppppcVar4 + local_20),&local_38);
          if (iVar3 < 0) goto LAB_1000ca5b;
          if (iVar3 < 2) {
            ppppcVar4 = (char ****)local_30;
            if (local_1c < 0x10) {
              ppppcVar4 = &local_30;
            }
            _Count = (int)local_38 - (int)ppppcVar4;
            if (_Count != 0) {
              ppppcVar4 = (char ****)local_30;
              if (local_1c < 0x10) {
                ppppcVar4 = &local_30;
              }
              sVar5 = fwrite(ppppcVar4,1,_Count,*(FILE **)((int)this + 0x54));
              if (_Count != sVar5) goto LAB_1000ca5b;
            }
            *(undefined1 *)((int)this + 0x4a) = 1;
            if (local_3c == (wchar_t *)&local_34) goto code_r0x1000c9ed;
            local_8 = 0xffffffff;
            FUN_1000bff0(&local_30);
          }
          else {
            if (iVar3 != 3) goto LAB_1000ca5b;
            FUN_1000ad50((wchar_t)local_34,*(FILE **)((int)this + 0x54));
            local_8 = 0xffffffff;
            FUN_1000bff0(&local_30);
          }
          goto LAB_1000ca6f;
        }
        fputwc(param_1,*(FILE **)((int)this + 0x54));
      }
    }
    else {
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *pwVar2 = param_1;
    }
  }
LAB_1000ca6f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
code_r0x1000c9ed:
  if (_Count == 0) {
    if (0x1f < local_20) {
LAB_1000ca5b:
      local_8 = 0xffffffff;
      FUN_1000bff0(&local_30);
      goto LAB_1000ca6f;
    }
    FUN_1000c1a0(&local_30,8,'\0');
  }
  goto LAB_1000c96b;
}



// Function: FUN_1000ca90 at 1000ca90

void __thiscall FUN_1000ca90(void *this,undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar4 = param_2;
  iVar3 = param_3;
  if (((**(int **)((int)this + 0x20) == (int)this + 0x48) && (param_4 == 1)) &&
     (*(int *)((int)this + 0x44) == 0)) {
    uVar4 = param_2 - 2;
    iVar3 = param_3 + -1 + (uint)(1 < param_2);
  }
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_1000c450((int *)this), cVar2 != '\0')) &&
      (((uVar4 == 0 && iVar3 == 0 && (param_4 == 1)) ||
       (iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(param_4,iVar3),unaff_EDI),
       iVar3 == 0)))) &&
     (iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&param_2), iVar3 == 0)) {
    Reset_back((int)this);
    param_1[2] = param_2;
    uVar1 = *(undefined4 *)((int)this + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = param_3;
    param_1[4] = uVar1;
    return;
  }
  uVar1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(_BADOFF_exref + 4);
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000cb60 at 1000cb60

void __thiscall
FUN_1000cb60(void *this,undefined4 *param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_4;
  local_8 = param_5;
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_1000c450((int *)this), cVar2 != '\0')) &&
      (iVar3 = fsetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar3 == 0)) &&
     (((param_2 == 0 && param_3 == 0 ||
       (iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(1,param_3),unaff_EDI), iVar3 == 0))
      && (iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar3 == 0)))) {
    *(int *)((int)this + 0x4c) = param_6;
    Reset_back((int)this);
    param_1[2] = local_c;
    uVar1 = *(undefined4 *)((int)this + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[4] = uVar1;
    param_1[3] = local_8;
    return;
  }
  uVar1 = *(undefined4 *)(_BADOFF_exref + 4);
  *param_1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = uVar1;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}



// Function: FUN_1000cc40 at 1000cc40

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __fastcall
FUN_1000cc40(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    cVar2 = FUN_1000c450((int *)param_1);
    pbVar4 = param_1;
    if (cVar2 == '\0') {
      pbVar4 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
    }
    iVar3 = fclose(*(FILE **)(param_1 + 0x54));
    if (iVar3 == 0) goto LAB_1000cc6c;
  }
  pbVar4 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
LAB_1000cc6c:
  param_1[0x50] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  param_1[0x4a] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init(param_1);
  *(undefined4 *)(param_1 + 0x54) = 0;
  uVar1 = DAT_1003458c;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return pbVar4;
}



// Function: FUN_1000cc90 at 1000cc90

void __fastcall FUN_1000cc90(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = param_1 + 6;
  if (param_1[0x1b] != 0) {
    cVar1 = FUN_1000c450(param_1 + 6);
    if (cVar1 == '\0') {
      piVar3 = (int *)0x0;
    }
    iVar2 = fclose((FILE *)param_1[0x1b]);
    if (iVar2 == 0) goto LAB_1000ccbf;
  }
  piVar3 = (int *)0x0;
LAB_1000ccbf:
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 6));
  param_1[0x1b] = 0;
  param_1[0x19] = DAT_1003458c;
  param_1[0x17] = 0;
  if (piVar3 == (int *)0x0) {
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(*param_1 + 4) + (int)param_1),2,false);
  }
  return;
}



// Function: FUN_1000cd00 at 1000cd00

void __fastcall FUN_1000cd00(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8 = 0;
  if ((*(int *)(param_1 + 0x54) != 0) &&
     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)**(int **)(param_1 + 0x10) ==
      param_1 + 0x48)) {
    uVar1 = *(undefined4 *)(param_1 + 0x40);
    **(int **)(param_1 + 0x10) = *(int *)(param_1 + 0x3c);
    **(undefined4 **)(param_1 + 0x20) = uVar1;
    **(undefined4 **)(param_1 + 0x30) = 0;
  }
  if (param_1[0x50] != (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0) {
    FUN_1000cc40(param_1);
  }
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cd90 at 1000cd90

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000cd90(void *this,byte param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8 = 0;
  if ((*(int *)((int)this + 0x54) != 0) && (**(int **)((int)this + 0x10) == (int)this + 0x48)) {
    uVar1 = *(undefined4 *)((int)this + 0x40);
    **(int **)((int)this + 0x10) = *(int *)((int)this + 0x3c);
    **(undefined4 **)((int)this + 0x20) = uVar1;
    **(undefined4 **)((int)this + 0x30) = 0;
  }
  if (*(char *)((int)this + 0x50) != '\0') {
    FUN_1000cc40((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  }
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



// Function: FUN_1000ce30 at 1000ce30

void FUN_1000ce30(undefined4 param_1,undefined4 param_2)

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
  
  puStack_c = &LAB_1001a828;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8 = 0;
  local_40 = param_1;
  local_3c = 0;
  local_38 = param_2;
  FUN_100057e0(local_34,(int *)&DAT_10026808,0);
  local_18 = 0;
  local_8 = 1;
  local_6c = local_3c;
  local_70 = local_40;
  local_74 = CComErrorHandlerException::vftable;
  local_68 = local_38;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  FUN_100056e0(local_64,(int *)local_34,0,0xffffffff);
  local_48 = local_18;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_74,(ThrowInfo *)&DAT_1002b4c0);
}



// Function: FUN_1000cf00 at 1000cf00

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000cf00(void *this,int param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a896;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    *(undefined **)this = &DAT_100279b4;
    *(undefined ***)((int)this + 0x10) = &PTR_100279ac;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
    local_8 = 1;
  }
  this_00 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18);
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,this_00);
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this_00);
  local_8 = CONCAT31(local_8._1_3_,3);
  *(undefined ***)this_00 = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  *(undefined1 *)((int)this + 0x68) = 0;
  *(undefined1 *)((int)this + 0x62) = 0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init(this_00);
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 100) = DAT_1003458c;
  *(undefined4 *)((int)this + 0x5c) = 0;
  ExceptionList = local_10;
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_1000cfe0 at 1000cfe0

void __fastcall FUN_1000cfe0(int param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  undefined4 uVar1;
  uint3 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a8e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x70) + 4) + -0x70 + param_1) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x58);
  *(undefined ***)this = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  if ((*(int *)(param_1 + -4) != 0) && (**(int **)(param_1 + -0x48) == param_1 + -0x10)) {
    uVar1 = *(undefined4 *)(param_1 + -0x18);
    **(int **)(param_1 + -0x48) = *(int *)(param_1 + -0x1c);
    **(undefined4 **)(param_1 + -0x38) = uVar1;
    **(undefined4 **)(param_1 + -0x28) = 0;
  }
  if (*(char *)(param_1 + -8) != '\0') {
    FUN_1000cc40(this);
    uVar2 = local_8._1_3_;
  }
  local_8._1_3_ = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  local_8 = 0xffffffff;
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d090 at 1000d090

void __fastcall FUN_1000d090(int param_1)

{
  ios_base *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a909;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (ios_base *)(param_1 + 0x70);
  FUN_1000cfe0((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d100 at 1000d100

ios_base * __thiscall FUN_1000d100(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a939;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000cfe0((int)this);
  *(code **)this = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)this = _vftable__exref;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    operator_delete((ios_base *)((int)this + -0x70));
  }
  ExceptionList = local_10;
  return (ios_base *)((int)this + -0x70);
}



// Function: FUN_1000d180 at 1000d180

void __thiscall
FUN_1000d180(void *this,long param_1,long param_2,undefined4 param_3,wchar_t *param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  int iVar6;
  LPWSTR lpDateStr;
  int *piVar7;
  char *unaff_EDI;
  wchar_t *pwVar8;
  wchar_t *in_stack_fffffd14;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd20;
  wchar_t *in_stack_fffffd24;
  wchar_t *in_stack_fffffd30;
  wchar_t *in_stack_fffffd3c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd48;
  wchar_t *in_stack_fffffd4c;
  int in_stack_fffffd58;
  wchar_t *in_stack_fffffd5c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd68;
  wchar_t *in_stack_fffffd6c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd78;
  wchar_t *in_stack_fffffd7c;
  int in_stack_fffffd80;
  code *pcVar9;
  code *local_27c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd88;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd8c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd90;
  HKEY local_230;
  undefined4 local_22c;
  undefined4 local_228;
  ios_base *local_224;
  uint local_220;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a9a5;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_224 = (ios_base *)param_3;
  FUN_1000cf00(&stack0xfffffd14,1);
  local_8 = 0;
  if (*(int *)((int)this + 0x28) == 0) {
    local_230 = (HKEY)0x0;
    local_22c = 0;
    local_228 = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_100017f0(&local_230,(HKEY)0x80000002,
                 L"Software\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths\\",0x2001f);
    local_220 = 0x208;
    FUN_100018a0(&local_230,L"ErrorLog",(LPBYTE)&local_21c,&local_220);
    psVar3 = (short *)&local_21c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_100057e0((void *)((int)this + 0x18),&local_21c,(int)psVar3 - ((int)&local_21c + 2) >> 1);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_230 != (HKEY)0x0) {
      RegCloseKey(local_230);
      local_230 = (HKEY)0x0;
    }
    local_22c = 0;
    if (*(int *)((int)this + 0x28) != 0) goto LAB_1000d2d7;
    local_8 = 0xffffffff;
    FUN_1000cfe0((int)&local_27c);
  }
  else {
LAB_1000d2d7:
    pwVar8 = (wchar_t *)((int)this + 0x18);
    if (7 < *(uint *)((int)this + 0x2c)) {
      pwVar8 = *(wchar_t **)pwVar8;
    }
    pbVar4 = FUN_1000afd0(&stack0xfffffd2c,pwVar8,10,(facet *)0x40);
    if (pbVar4 == (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0) {
      std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
                ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 (&stack0xfffffd14 + *(int *)(in_stack_fffffd14 + 2)),2,false);
    }
    else {
      std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::clear
                ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 (&stack0xfffffd14 + *(int *)(in_stack_fffffd14 + 2)),0,false);
    }
    if (in_stack_fffffd80 != 0) {
      pwVar8 = L" Error Log Entry:";
      pbVar5 = FUN_1000b220((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
                            &stack0xfffffd24,&DAT_10027aa4);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0((int *)pbVar5,pwVar8);
      pbVar5 = FUN_1000b220(pbVar5,unaff_EDI);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0((int *)pbVar5,in_stack_fffffd14);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd20);
      iVar6 = GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
      lVar2 = (ulonglong)(iVar6 + 1) * 2;
      lpDateStr = (LPWSTR)operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2
                                        );
      GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,lpDateStr,iVar6);
      piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,L"On ");
      piVar7 = (int *)FUN_1000b4d0(piVar7,in_stack_fffffd24);
      FUN_1000b4d0(piVar7,in_stack_fffffd30);
      operator_delete__(lpDateStr);
      iVar6 = GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
      lVar2 = (ulonglong)(iVar6 + 1) * 2;
      pwVar8 = (wchar_t *)
               operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
      GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,pwVar8,iVar6);
      piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,pwVar8);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0(piVar7,in_stack_fffffd3c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd48);
      operator_delete__(pwVar8);
      piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,L"In file ");
      piVar7 = (int *)FUN_1000b4d0(piVar7,param_4);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0(piVar7,in_stack_fffffd4c);
      pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                         (pbVar5,in_stack_fffffd58);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0((int *)pbVar5,in_stack_fffffd5c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd68);
      pwVar8 = (wchar_t *)operator_new__(0x20);
      _ltow_s(param_1,pwVar8,0x10,0x10);
      piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,L"The HRESULT was: 0x");
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0(piVar7,in_stack_fffffd6c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd78);
      _ltow_s(param_2,pwVar8,0x10,0x10);
      piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,L"The result of the expression was: 0x");
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_1000b4d0(piVar7,in_stack_fffffd7c);
      local_27c = (code *)0x1000d58d;
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd88);
      local_27c = (code *)0x1000d593;
      operator_delete__(pwVar8);
      if (*(int *)((int)this + 8) != 0) {
        local_220 = 0;
        local_8._0_1_ = 4;
        local_27c = *(code **)((int)this + 8);
        (**(code **)(*(int *)local_27c + 0x14))();
        pcVar9 = endl_exref;
        piVar7 = (int *)FUN_1000b4d0((int *)&stack0xfffffd24,L"Description of error: ");
        pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 FUN_1000b4d0(piVar7,(wchar_t *)pcVar9);
        pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                           (pbVar5,in_stack_fffffd8c);
        std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                  (pbVar5,in_stack_fffffd90);
        local_8 = (uint)local_8._1_3_ << 8;
        Ordinal_6();
      }
      FUN_1000cc90((int *)&stack0xfffffd14);
      local_8 = 0xffffffff;
      FUN_1000cfe0((int)&local_27c);
      local_224 = (ios_base *)&local_27c;
      local_8 = 0xffffffff;
      local_27c = (code *)0x1000d653;
      std::ios_base::_Ios_base_dtor(local_224);
      goto LAB_1000d658;
    }
    local_8 = 0xffffffff;
    FUN_1000cfe0((int)&local_27c);
  }
  local_8 = 0xffffffff;
  local_224 = (ios_base *)&local_27c;
  local_27c = _vftable__exref;
  std::ios_base::_Ios_base_dtor(local_224);
LAB_1000d658:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d680 at 1000d680

void FUN_1000d680(undefined4 param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa11;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar1 = false;
  while (!bVar1) {
    iVar3 = FUN_10001020((int *)PTR_DAT_100331d4,param_2);
    if (iVar3 != 0) goto LAB_1000d6f3;
    bVar1 = true;
  }
  local_8 = 0xffffffff;
LAB_1000d6f3:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000d711 at 1000d711

undefined * Catch_1000d711(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x68);
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d7a3;
}



// Function: Catch@1000d7a8 at 1000d7a8

undefined * Catch_1000d7a8(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x60) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar4 = *(undefined4 *)(unaff_EBP + -0x48);
  }
  else {
    uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0x60) + 4);
    *(undefined4 *)(unaff_EBP + -0x48) = uVar4;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar6 = 0x6d;
  pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),uVar4,uVar4,uVar2,(int *)pcVar5,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d86c;
}



// Function: Catch@1000d871 at 1000d871

undefined * Catch_1000d871(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 5;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar5 = 0x6d;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar2,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  std::exception::~exception((exception *)(unaff_EBP + -0x74));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d946;
}



// Function: Catch@1000d94b at 1000d94b

undefined4 Catch_1000d94b(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar5 = 0x6d;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar2,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000d6f0;
}



// Function: FUN_1000da10 at 1000da10

void FUN_1000da10(void)

{
  __security_check_cookie(DAT_100344b0 ^ (uint)&stack0xfffffffc ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000da68 at 1000da68

void FUN_1000da68(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x54) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000da91;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000da97 at 1000da97

undefined1 * Catch_1000da97(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x70);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000db25;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@1000db2a at 1000db2a

undefined1 * Catch_1000db2a(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar1 = *(undefined4 *)(unaff_EBP + -0x48);
    this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
    uVar6 = 0x8a;
    pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar4 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),uVar1,uVar1,uVar4,(int *)pcVar5,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar3 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar3 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000dbf4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x6c) + 4));
}



// Function: Catch@1000dbf9 at 1000dbf9

undefined4 Catch_1000dbf9(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 6;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      uVar3 = FUN_1000da68();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  uVar5 = 0x8a;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000dcec;
}



// Function: Catch@1000dcf1 at 1000dcf1

undefined * Catch_1000dcf1(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  uVar7 = 0x8a;
  pcVar6 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_1000da68;
}



// Function: FUN_1000dde0 at 1000dde0

void FUN_1000dde0(int param_1)

{
  int iVar1;
  uint uStack_90;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aaf9;
  local_10 = ExceptionList;
  uStack_90 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_8 = 1;
  local_18 = uStack_90;
  iVar1 = FUN_1000c020(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_58,iVar1);
}



// Function: FUN_1000de44 at 1000de44

void FUN_1000de44(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x54) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000de6d;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000de73 at 1000de73

undefined1 * Catch_1000de73(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x70);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000df04;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@1000df09 at 1000df09

undefined1 * Catch_1000df09(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
    uVar5 = 0xa9;
    pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
                 *(undefined4 *)(unaff_EBP + -0x48),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000dfcc;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x6c) + 4));
}



// Function: Catch@1000dfd1 at 1000dfd1

undefined4 Catch_1000dfd1(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 6;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      uVar3 = FUN_1000de44();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  uVar5 = 0xa9;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000e0c4;
}



// Function: Catch@1000e0c9 at 1000e0c9

undefined * Catch_1000e0c9(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0x10);
  uVar7 = 0xa9;
  pcVar6 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_1000de44;
}



// Function: FUN_1000e1b0 at 1000e1b0

void FUN_1000e1b0(int param_1,int *param_2)

{
  int *piVar1;
  uint uStack_9c;
  int local_64;
  int local_60;
  int local_5c;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_44 [11];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab74;
  local_10 = ExceptionList;
  uStack_9c = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_9c;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  *param_2 = 0;
  local_64 = -1;
  local_60 = -1;
  local_18 = uStack_9c;
  FUN_10017330(local_44,*(undefined4 **)(param_1 + -0x44));
  local_8._0_1_ = 2;
  piVar1 = DAT_10032934;
  if (DAT_10032948 < 8) {
    piVar1 = (int *)&DAT_10032934;
  }
  FUN_100175e0(local_44,piVar1,&local_64);
  piVar1 = DAT_10032950;
  if (DAT_10032964 < 8) {
    piVar1 = (int *)&DAT_10032950;
  }
  FUN_100175e0(local_44,piVar1,&local_60);
  if (local_64 == 1) {
    if (local_60 != 1) {
      *param_2 = 3;
    }
  }
  else {
    *param_2 = 2 - (uint)(local_60 != 1);
  }
  local_4c = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10016d80(local_44);
  if (local_4c < 0) {
    *param_2 = 1;
  }
  local_8 = 0xffffffff;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000e2d8 at 1000e2d8

undefined * Catch_1000e2d8(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x7c);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x78),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x78) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_1000e369;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@1000e36e at 1000e36e

undefined * Catch_1000e36e(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x78),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x68) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x78) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar1 = *(undefined4 *)(unaff_EBP + -0x48);
    this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
    uVar6 = 0xe9;
    pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar4 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),uVar1,uVar1,uVar4,(int *)pcVar5,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar3 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar3 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_1000e438;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x68) + 4));
}



// Function: Catch@1000e43d at 1000e43d

undefined * Catch_1000e43d(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x78),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined ***)(unaff_EBP + -0x78) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  uVar5 = 0xe9;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0x88));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000e532;
}



// Function: Catch@1000e537 at 1000e537

undefined4 Catch_1000e537(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x78),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x78) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  uVar6 = 0xe9;
  pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar5,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000e29c;
}



// Function: FUN_1000e620 at 1000e620

void FUN_1000e620(int param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uStack_a0;
  undefined4 local_80 [2];
  int local_78;
  undefined **local_74;
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_44 [11];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abfc;
  local_10 = ExceptionList;
  uStack_a0 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a0;
  ExceptionList = &local_10;
  local_78 = param_1;
  local_70 = 0;
  local_6c = 0;
  local_74 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_68 = 0x80004005;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_18 = uStack_a0;
  FUN_10017330(local_44,*(undefined4 **)(param_1 + -0x44));
  local_8._0_1_ = 3;
  piVar1 = DAT_100329a4;
  if (DAT_100329b8 < 8) {
    piVar1 = (int *)&DAT_100329a4;
  }
  FUN_10017a30(local_44,piVar1,local_80);
  *param_2 = local_80[0];
  local_68 = 0;
  local_8._0_1_ = 2;
  FUN_10016d80(local_44);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100047c0((undefined4 *)local_64);
  local_8 = 0xffffffff;
  local_74 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e6de at 1000e6de

void FUN_1000e6de(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x70) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000e707;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000e70d at 1000e70d

undefined1 * Catch_1000e70d(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x80);
  this = (int *)(*(int *)(unaff_EBP + -0x74) + -0x3c);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000e79b;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x70),*(int *)(iVar1 + 4));
}



// Function: Catch@1000e7a0 at 1000e7a0

undefined1 * Catch_1000e7a0(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x78) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar1 = *(undefined4 *)(unaff_EBP + -100);
    this = (int *)(*(int *)(unaff_EBP + -0x74) + -0x3c);
    uVar6 = 0x113;
    pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar4 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),uVar1,uVar1,uVar4,(int *)pcVar5,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar3 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar3 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_1000e86a;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x70),*(int *)(*(int *)(unaff_EBP + -0x78) + 4));
}



// Function: Catch@1000e86f at 1000e86f

undefined4 Catch_1000e86f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 8;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x6c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x6c) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x68));
      uVar3 = FUN_1000e6de();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x74) + -0x3c);
  uVar5 = 0x113;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  std::exception::~exception((exception *)(unaff_EBP + -0x8c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000e961;
}



// Function: Catch@1000e966 at 1000e966

undefined * Catch_1000e966(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x6c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x6c) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x68));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x74) + -0x3c);
  uVar7 = 0x113;
  pcVar6 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_1000e6de;
}



// Function: FUN_1000ea50 at 1000ea50

void FUN_1000ea50(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uStack_bc;
  undefined4 local_a0 [17];
  int local_5c;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac87;
  local_10 = ExceptionList;
  uStack_bc = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_bc;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_8 = 0;
  local_18 = uStack_bc;
  FUN_10017330(local_a0,*(undefined4 **)(param_1 + -0x44));
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  puVar1 = DAT_1003296c;
  if (DAT_10032980 < 8) {
    puVar1 = &DAT_1003296c;
  }
  FUN_10016c90(local_a0,puVar1);
  piVar2 = DAT_10032988;
  if (DAT_1003299c < 8) {
    piVar2 = (int *)&DAT_10032988;
  }
  FUN_100175e0(local_a0,piVar2,param_2);
  local_4c = 0;
  local_8 = 0;
  FUN_10016d80(local_a0);
  local_8 = 0xffffffff;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000eb4a at 1000eb4a

undefined * Catch_1000eb4a(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x70);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return &DAT_1000ebdb;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@1000ebe0 at 1000ebe0

undefined * Catch_1000ebe0(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar1 = *(undefined4 *)(unaff_EBP + -0x48);
    this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
    uVar6 = 0x13b;
    pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar4 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),uVar1,uVar1,uVar4,(int *)pcVar5,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar3 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar3 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return &DAT_1000eca7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x6c) + 4));
}



// Function: Catch@1000ecac at 1000ecac

undefined * Catch_1000ecac(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  uVar5 = 0x13b;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0xa8));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000eda1;
}



// Function: Catch@1000eda6 at 1000eda6

undefined4 Catch_1000eda6(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + -0x3c);
  uVar6 = 0x13b;
  pcVar5 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar5,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000eb0a;
}



// Function: FUN_1000ee90 at 1000ee90

void FUN_1000ee90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uStack_b4;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined **local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad18;
  local_10 = ExceptionList;
  uStack_b4 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_b4;
  ExceptionList = &local_10;
  local_68 = param_1;
  local_78 = param_2;
  local_60 = 0;
  local_5c = 0;
  local_64 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_58 = 0x80004005;
  local_70 = 0xffffffff;
  local_74 = 0xffffffff;
  local_4c = 0;
  local_94 = 2;
  local_90 = 0;
  local_6c = 0;
  local_50 = 0;
  local_8 = 2;
  local_18 = uStack_b4;
  local_6c = Ordinal_15(0xc,1,&local_94);
  if (local_6c == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000a090(&local_64,-0x7ff8fff2);
  }
  iVar1 = Ordinal_23(local_6c,&local_50);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_64,iVar1);
}



// Function: FUN_1000f086 at 1000f086

void FUN_1000f086(void)

{
  undefined4 uVar1;
  uint unaff_EBP;
  undefined4 uStack00000008;
  
  if (*(int *)(unaff_EBP - 0x54) < 0) {
    uVar1 = Ordinal_24(*(undefined4 *)(unaff_EBP - 0x68));
    *(undefined4 *)(unaff_EBP - 0x54) = uVar1;
  }
  *(undefined1 *)(unaff_EBP - 4) = 0;
  Ordinal_6(*(undefined4 *)(unaff_EBP - 0x48));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x60) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack00000008 = 0x1000f0d2;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000f0d8 at 1000f0d8

undefined1 * Catch_1000f0d8(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x94);
  this = (int *)(*(int *)(unaff_EBP + -100) + -0x3c);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x88),unaff_EBP + -0x60);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x88) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return &LAB_1000f16f;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x60),*(int *)(iVar1 + 4));
}



// Function: Catch@1000f174 at 1000f174

undefined1 * Catch_1000f174(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x88),unaff_EBP + -0x60);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x78) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x88) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -100) + -0x3c);
    uVar5 = 0x1ab;
    pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x54),
                 *(undefined4 *)(unaff_EBP + -0x54),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return &LAB_1000f240;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x60),*(int *)(*(int *)(unaff_EBP + -0x78) + 4));
}



// Function: Catch@1000f245 at 1000f245

undefined4 Catch_1000f245(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 8;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x88),unaff_EBP + -0x60);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined ***)(unaff_EBP + -0x88) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x5c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x5c) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x58));
      uVar3 = FUN_1000f086();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -100) + -0x3c);
  uVar5 = 0x1ab;
  pcVar4 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  std::exception::~exception((exception *)(unaff_EBP + -0xa0));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000f33f;
}



// Function: Catch@1000f344 at 1000f344

undefined * Catch_1000f344(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  char extraout_DL;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x88),unaff_EBP + -0x60);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x88) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x5c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x5c) = 1;
      iVar3 = FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x58));
      pcVar6 = (char *)(iVar3 + 0x131000f0);
      LOCK();
      *pcVar6 = *pcVar6 + extraout_DL;
      UNLOCK();
      LOCK();
      *pcVar6 = *pcVar6 + extraout_DL;
      UNLOCK();
      LOCK();
      *pcVar6 = *pcVar6 + extraout_DL;
      UNLOCK();
      pcVar6 = (char *)((uint)pcVar6 | 0xf0);
      *pcVar6 = *pcVar6 + extraout_DL;
      *pcVar6 = *pcVar6 + extraout_DL;
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -100) + -0x3c);
  uVar7 = 0x1ab;
  pcVar6 = "ImmobilizerInstallationLogicImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return FUN_1000f086;
}



// Function: FUN_1000f450 at 1000f450

undefined4 * __thiscall FUN_1000f450(void *this,undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad5b;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this =
       TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 2;
  iVar2 = (**(code **)*param_1)(param_1,&DAT_100277d4,(undefined4 *)((int)this + 4),uVar1);
  if (iVar2 < 0) {
    FUN_1000ce30(iVar2,0);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000f500 at 1000f500

undefined4 * __thiscall
FUN_1000f500(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  piVar5 = param_1;
  puStack_c = &LAB_1001adcb;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  *(undefined ***)this =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_14 = 0;
  uStack_7 = 0;
  local_8 = 3;
  puVar4 = param_2;
  local_18 = piVar1;
  if (param_2[4] == 0) {
    iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,&local_14,uVar2);
    if (-1 < iVar3) goto LAB_1000f5ce;
    puVar4 = (undefined4 *)FUN_1000ce30(iVar3,0);
  }
  piVar5 = FUN_10016930((int *)&param_2,puVar4);
  local_8 = 4;
  if (local_14 != *piVar5) {
    Ordinal_6(local_14);
    local_14 = *piVar5;
    *piVar5 = 0;
  }
  local_8 = 3;
  Ordinal_6(param_2);
  piVar5 = param_1;
LAB_1000f5ce:
  local_18 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  iVar3 = (**(code **)(*piVar5 + 0x24))(piVar5,&local_18);
  if (iVar3 < 0) {
    FUN_1000ce30(iVar3,0);
  }
  iVar3 = (**(code **)(*local_18 + 0x24))(local_18,local_14,piVar1);
  if (iVar3 < 0) {
    FUN_1000ce30(iVar3,0);
  }
  if (param_3[4] != 0) {
    piVar5 = FUN_10016930((int *)&param_1,param_3);
    _local_8 = CONCAT31(uStack_7,7);
    iVar3 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,*piVar5);
    if (iVar3 < 0) {
      FUN_1000ce30(iVar3,0);
    }
    _local_8 = CONCAT31(uStack_7,6);
    Ordinal_6(param_1);
  }
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  _local_8 = CONCAT31(uStack_7,2);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000f6c0 at 1000f6c0

undefined2 * __thiscall FUN_1000f6c0(void *this,undefined2 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ae19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x1c))
                    (*(int **)((int)this + 4),&local_14,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_1000ce30(iVar1,0);
  }
  FUN_10016a90(param_1,local_14);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f780 at 1000f780

void __thiscall FUN_1000f780(void *this,undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ae50;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar2 = FUN_10016930((int *)&param_1,param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x24))(*(int **)((int)this + 4),*piVar2,uVar1);
  if (iVar3 < 0) {
    FUN_1000ce30(iVar3,0);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000f830 at 1000f830

undefined4 * __thiscall FUN_1000f830(void *this,undefined4 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aebc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 3;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))
                    (*(int **)((int)this + 4),&local_14,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_1000ce30(iVar1,0);
  }
  param_1[1] = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  *param_1 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f900 at 1000f900

undefined4 * __thiscall FUN_1000f900(void *this,undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001af4c;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 3;
  uStack_7 = 0;
  piVar2 = FUN_10016930((int *)&param_2,param_2);
  _local_8 = CONCAT31(uStack_7,4);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x30))
                    (*(int **)((int)this + 4),*piVar2,1,&local_18,uVar1);
  if (iVar3 < 0) {
    FUN_1000ce30(iVar3,0);
  }
  local_8 = 3;
  Ordinal_6(param_2);
  local_14 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  if (local_18 != (int *)0x0) {
    iVar3 = (**(code **)*local_18)(local_18,&DAT_100277f4,&local_14);
    if (iVar3 < 0) {
      FUN_1000ce30(iVar3,0);
    }
  }
  param_2 = param_1 + 1;
  *param_2 = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  uStack_7 = (undefined3)((uint)_local_8 >> 8);
  local_8 = 3;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  _local_8 = CONCAT31(uStack_7,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fa40 at 1000fa40

undefined4 * __thiscall FUN_1000fa40(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined **local_2c;
  undefined1 local_28;
  undefined4 local_24;
  int local_20;
  void *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001afbb;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_28 = 0;
  local_24 = 0;
  local_2c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_20 = -0x7fffbffb;
  local_14 = 0;
  uStack_7 = 0;
  local_8 = 3;
  puVar3 = param_2;
  local_1c = this;
  local_18 = piVar1;
  if (param_2[4] == 0) {
    local_20 = (**(code **)(*param_1 + 0x1c))(param_1,&local_14,uVar2);
    if (-1 < local_20) goto LAB_1000fb0e;
    local_28 = 1;
    puVar3 = (undefined4 *)FUN_1000ce30(local_20,local_24);
  }
  piVar4 = FUN_10016930((int *)&param_2,puVar3);
  local_8 = 4;
  if (local_14 != *piVar4) {
    Ordinal_6(local_14);
    local_14 = *piVar4;
    *piVar4 = 0;
  }
  local_8 = 3;
  Ordinal_6(param_2);
LAB_1000fb0e:
  local_18 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  local_20 = (**(code **)(*param_1 + 0x28))(param_1,&local_18);
  if (local_20 < 0) {
    local_28 = 1;
    FUN_1000ce30(local_20,local_24);
  }
  local_3c = (uint)local_3c._2_2_ << 0x10;
  FUN_1000a9b0(&local_3c,&local_14);
  _local_8 = CONCAT31(uStack_7,7);
  local_20 = (**(code **)(*local_18 + 0x1c))(local_18,local_3c,local_38,local_34,local_30,piVar1);
  if (local_20 < 0) {
    local_28 = 1;
    FUN_1000ce30(local_20,local_24);
  }
  local_8 = 6;
  Ordinal_9(&local_3c);
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  _local_8 = CONCAT31(uStack_7,2);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000fbf0 at 1000fbf0

undefined4 __fastcall FUN_1000fbf0(int param_1)

{
  int iVar1;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001afe8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x2c))
                    (*(int **)(param_1 + 4),&local_14,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_1000ce30(iVar1,0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000fc80 at 1000fc80

undefined4 * __thiscall
FUN_1000fc80(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 param_3,
            undefined4 *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b041;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_18[1] = 1;
  local_8 = 2;
  piVar2 = FUN_10016930(local_18,param_2);
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x34))
                    (*(int **)((int)this + 4),*piVar2,param_3,*param_4,param_4[1],param_4[2],
                     param_4[3],param_1,uVar1);
  if (iVar3 < 0) {
    FUN_1000ce30(iVar3,0);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(local_18[0]);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fd70 at 1000fd70

undefined4 * __thiscall FUN_1000fd70(void *this,int param_1,undefined4 *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b0dd;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CECMParameterReader::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined ***)((int)this + 8) =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_8 = 0xc;
  if (*(int *)((int)this + 0xc) != param_1) {
    Ordinal_30((int)this + 0xc,param_1,uVar1);
  }
  if (param_2[4] != 0) {
    FUN_1000f780((void *)((int)this + 8),param_2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000fe60 at 1000fe60

void __fastcall FUN_1000fe60(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int local_3c;
  int *local_38;
  int *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b18d;
  local_10 = ExceptionList;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CECMParameterReader::vftable;
  local_8 = 5;
  piVar1 = (int *)param_1[1];
  local_34 = param_1 + 1;
  piVar5 = local_34;
  local_38 = param_1;
  local_14 = uVar3;
  if (piVar1 != (int *)0x0) {
    puVar4 = (undefined4 *)FUN_1000f6c0(param_1 + 2,(undefined2 *)local_30);
    local_8._0_1_ = 6;
    piVar5 = FUN_10016930(&local_3c,puVar4);
    local_8._0_1_ = 7;
    (**(code **)(*piVar1 + 0x28))(piVar1,*piVar5);
    local_8._0_1_ = 6;
    Ordinal_6(local_3c);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    piVar5 = local_34;
  }
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_34 = param_1 + 7;
  local_8._0_1_ = 4;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
  }
  local_34 = param_1 + 6;
  local_8._0_1_ = 3;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_34 = param_1 + 5;
  local_8._0_1_ = 2;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_34 = param_1 + 4;
  local_8._0_1_ = 1;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_34 = param_1 + 2;
  *local_34 = (int)TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
                   ::vftable;
  local_8._0_1_ = 0xc;
  piVar1 = param_1 + 3;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar2 = (int *)*piVar1;
  local_34 = piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)*piVar5;
  local_38 = piVar5;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010000 at 10010000

undefined4 * __thiscall FUN_10010000(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined **local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b1f9;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  puVar3 = FUN_1000f900((void *)((int)this + 8),&local_1c,param_2);
  piVar1 = local_18;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = puVar3 + 1;
  }
  *param_1 = 0;
  *param_1 = *puVar3;
  *puVar3 = 0;
  local_14 = 1;
  local_1c = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100100c0 at 100100c0

undefined4 __thiscall FUN_100100c0(void *this,undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b251;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10010000(this,&param_2,param_2);
  local_8 = 1;
  Ordinal_8(param_1,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,param_1);
  if (iVar2 != 0) {
    FUN_1000ce30(iVar2,0);
  }
  local_8 = 0;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10010180 at 10010180

undefined4 __cdecl FUN_10010180(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  undefined4 local_34 [8];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b291;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_1000fd70(local_34,param_2,param_4);
  local_8 = 1;
  FUN_100100c0(local_34,param_1,param_3);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_1000fe60(local_34);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10010200 at 10010200

void FUN_10010200(int param_1,undefined2 *param_2)

{
  int iVar1;
  uint uStack_c8;
  undefined **local_60;
  undefined1 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 *local_44;
  undefined4 local_40 [2];
  undefined4 local_38;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b348;
  local_10 = ExceptionList;
  uStack_c8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_c8;
  local_44 = param_2;
  local_38 = 0;
  local_18 = uStack_c8;
  if (param_2 == (undefined2 *)0x0) {
    local_14 = (undefined1 *)&uStack_c8;
    __security_check_cookie(uStack_c8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_5c = 0;
  local_58 = 0;
  local_60 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_54 = 0;
  ExceptionList = &local_10;
  *param_2 = 0;
  local_40[0] = 0;
  local_8 = 3;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + -0x44))
                    (*(undefined4 **)(param_1 + -0x44),&DAT_100277e4,local_40);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_60,iVar1);
}



// Function: Catch@100104f3 at 100104f3

undefined * Catch_100104f3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100104c4;
}



// Function: FUN_10010500 at 10010500

undefined4 * __thiscall
FUN_10010500(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3c4;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  FUN_1000fc80(this,&local_18,param_2,1,param_3);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_18 != (int *)0x0) {
    (**(code **)*local_18)(local_18,&DAT_100277f4,&local_14,uVar1);
  }
  param_1[1] = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100105e0 at 100105e0

undefined4 * __thiscall FUN_100105e0(void *this,byte param_1)

{
  FUN_1000fe60((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010610 at 10010610

void __fastcall FUN_10010610(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1001061f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0xa4) + 0x14))();
  return;
}



// Function: FUN_10010630 at 10010630

undefined4 FUN_10010630(void)

{
  return 0x8ba7;
}



// Function: FUN_10010640 at 10010640

undefined * FUN_10010640(void)

{
  return &DAT_10028058;
}



// Function: FUN_10010650 at 10010650

undefined * FUN_10010650(void)

{
  return &DAT_10027f98;
}



// Function: FUN_10010660 at 10010660

void FUN_10010660(void)

{
  return;
}



// Function: FUN_10010670 at 10010670

void __fastcall FUN_10010670(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_10010680 at 10010680

void __fastcall FUN_10010680(int param_1)

{
  int local_8;
  
  local_8 = param_1;
  (**(code **)(*(int *)(param_1 + 0x11c) + 4))(0x53,0,0,&local_8);
  return;
}



// Function: FUN_100106b0 at 100106b0

undefined4 FUN_100106b0(void)

{
  return 0x80004001;
}



// Function: FUN_100106c0 at 100106c0

void __fastcall FUN_100106c0(undefined4 *param_1)

{
  *param_1 = CComErrorDisplay<class_CImmobilizerInstallationPageImpl>::vftable;
  return;
}



// Function: FUN_100106d0 at 100106d0

void __fastcall FUN_100106d0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x68;
  }
  if (*(int *)(iVar3 + 0x6c) != 0) {
    (**(code **)(**(int **)(iVar3 + 0x6c) + 8))(*(int **)(iVar3 + 0x6c));
  }
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar3 + 0x70) + uVar2 * 4);
      (**(code **)(*piVar1 + 8))(piVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0xc));
  }
  operator_delete__(*(void **)(iVar3 + 0x70));
  return;
}



// Function: FUN_10010720 at 10010720

undefined4 * __thiscall FUN_10010720(void *this,byte param_1)

{
  *(undefined ***)this = CComErrorDisplay<class_CImmobilizerInstallationPageImpl>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010750 at 10010750

void __fastcall FUN_10010750(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100107a0 at 100107a0

void __fastcall FUN_100107a0(int param_1)

{
  if ((*(byte *)(param_1 + 0x40) & 1) != 0) {
    operator_delete((void *)**(undefined4 **)(param_1 + 0x10));
  }
  **(undefined4 **)(param_1 + 0x10) = 0;
  **(undefined4 **)(param_1 + 0x20) = 0;
  **(undefined4 **)(param_1 + 0x30) = 0;
  **(undefined4 **)(param_1 + 0x14) = 0;
  **(undefined4 **)(param_1 + 0x24) = 0;
  **(undefined4 **)(param_1 + 0x34) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



// Function: FUN_10010800 at 10010800

void __thiscall FUN_10010800(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)this = param_1;
    return;
  }
  *(int *)this = param_1;
  return;
}



// Function: FUN_10010830 at 10010830

int * __thiscall FUN_10010830(void *this,int *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b418;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1,uVar2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10010890 at 10010890

void FUN_10010890(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_100265c0,param_2);
  return;
}



// Function: FUN_100108b0 at 100108b0

void FUN_100108b0(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10028160,param_2);
  return;
}



// Function: FUN_100108d0 at 100108d0

undefined4 * __thiscall FUN_100108d0(void *this,char param_1,LPCWSTR param_2,char param_3)

{
  HCURSOR pHVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  pHVar1 = LoadCursorW((HINSTANCE)((param_3 != '\0') - 1 & DAT_1003496c),param_2);
  *(HCURSOR *)this = pHVar1;
  if ((param_1 != '\0') && (*(char *)((int)this + 8) == '\0')) {
    pHVar1 = SetCursor(pHVar1);
    *(HCURSOR *)((int)this + 4) = pHVar1;
    *(undefined1 *)((int)this + 8) = 1;
  }
  return (undefined4 *)this;
}



// Function: FUN_10010920 at 10010920

void __fastcall FUN_10010920(int param_1)

{
  if (*(char *)(param_1 + 8) != '\0') {
    SetCursor(*(HCURSOR *)(param_1 + 4));
    *(undefined1 *)(param_1 + 8) = 0;
  }
  return;
}



// Function: FUN_10010940 at 10010940

undefined4 FUN_10010940(int *param_1)

{
  int iVar1;
  
  if ((undefined *)*param_1 != &DAT_10026808) {
    Ordinal_6((undefined *)*param_1);
    iVar1 = Ordinal_2(&DAT_10026808);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  return 0;
}



// Function: FUN_10010980 at 10010980

void __fastcall FUN_10010980(undefined4 *param_1)

{
  BOOL BVar1;
  
  if ((HGDIOBJ)*param_1 != (HGDIOBJ)0x0) {
    BVar1 = DeleteObject((HGDIOBJ)*param_1);
    if (BVar1 != 0) {
      *param_1 = 0;
    }
  }
  return;
}



// Function: FUN_100109a0 at 100109a0

void __fastcall FUN_100109a0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  FUN_100107a0((int)param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010a00 at 10010a00

undefined4 __fastcall FUN_10010a00(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)**(int **)(param_1 + 0x20);
  if (puVar1 == (undefined2 *)0x0) {
    return 0xffff;
  }
  if (puVar1 < puVar1 + **(int **)(param_1 + 0x30)) {
    return CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1);
  }
  if ((((*(byte *)(param_1 + 0x40) & 4) == 0) &&
      (puVar2 = (undefined2 *)**(undefined4 **)(param_1 + 0x24), puVar2 != (undefined2 *)0x0)) &&
     ((puVar1 < puVar2 || (puVar1 < *(undefined2 **)(param_1 + 0x3c))))) {
    if (*(undefined2 **)(param_1 + 0x3c) < puVar2) {
      *(undefined2 **)(param_1 + 0x3c) = puVar2;
    }
    **(int **)(param_1 + 0x30) = *(int *)(param_1 + 0x3c) - **(int **)(param_1 + 0x20) >> 1;
    return CONCAT22((short)((uint)**(undefined4 **)(param_1 + 0x20) >> 0x10),
                    *(undefined2 *)**(undefined4 **)(param_1 + 0x20));
  }
  return 0xffff;
}



// Function: FUN_10010a70 at 10010a70

void __thiscall
FUN_10010a70(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  uVar2 = **(uint **)((int)this + 0x24);
  if ((uVar2 != 0) && (*(uint *)((int)this + 0x3c) < uVar2)) {
    *(uint *)((int)this + 0x3c) = uVar2;
  }
  if (((param_5 & 1) == 0) || (iVar5 = **(int **)((int)this + 0x20), iVar5 == 0)) {
    if (((param_5 & 2) == 0) || (uVar2 = **(uint **)((int)this + 0x24), uVar2 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_10010c21;
    }
    else {
      if (param_4 == 2) {
        iVar5 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        uVar3 = iVar5 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar5 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 == 1) {
        iVar5 = uVar2 - **(int **)((int)this + 0x10);
        uVar3 = iVar5 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar5 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        iVar5 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar1 = iVar5 >> 0x1f;
        if (((int)param_3 <= iVar1) && (((int)param_3 < iVar1 || (param_2 <= (uint)(iVar5 >> 1)))))
        {
          iVar5 = ((int)(**(int **)((int)this + 0x10) - uVar2) >> 1) + param_2;
          **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar5;
          **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar5 * 2;
          goto LAB_10010c21;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar6 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        iVar1 = iVar5 - **(int **)((int)this + 0x10);
        uVar2 = iVar1 >> 1;
        bVar6 = CARRY4(param_2,uVar2);
        param_2 = param_2 + uVar2;
        param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
      }
      else {
LAB_10010ae5:
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else if (param_4 != 0) goto LAB_10010ae5;
    if (-1 < (int)param_3) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar4 = iVar1 >> 0x1f;
      if (((int)param_3 <= iVar4) && (((int)param_3 < iVar4 || (param_2 <= (uint)(iVar1 >> 1))))) {
        iVar5 = (**(int **)((int)this + 0x10) - iVar5 >> 1) + param_2;
        **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar5;
        **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar5 * 2;
        if ((param_5 & 2) != 0) {
          iVar5 = **(int **)((int)this + 0x24);
          if (iVar5 != 0) {
            iVar1 = **(int **)((int)this + 0x34);
            iVar4 = **(int **)((int)this + 0x20);
            **(int **)((int)this + 0x24) = iVar4;
            **(int **)((int)this + 0x34) = (iVar5 + iVar1 * 2) - iVar4 >> 1;
          }
        }
        goto LAB_10010c21;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_10010c21:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10010c40 at 10010c40

void __thiscall FUN_10010c40(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_stack_00000020;
  
  uVar8 = param_4 + param_2;
  uVar1 = **(uint **)((int)this + 0x24);
  uVar6 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  if ((uVar1 != 0) && (*(uint *)((int)this + 0x3c) < uVar1)) {
    *(uint *)((int)this + 0x3c) = uVar1;
  }
  uVar1 = *(uint *)_BADOFF_exref;
  uVar2 = *(uint *)(_BADOFF_exref + 4);
  if ((uVar8 != uVar1) || (uVar7 = uVar6, uVar9 = uVar8, uVar6 != uVar2)) {
    uVar7 = uVar2;
    uVar9 = uVar1;
    if (((in_stack_00000020 & 1) == 0) || (**(int **)((int)this + 0x20) == 0)) {
      if ((((in_stack_00000020 & 2) != 0) && (**(int **)((int)this + 0x24) != 0)) &&
         (-1 < (int)uVar6)) {
        iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar5 = iVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
          iVar4 = (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x24) >> 1) + uVar8;
          **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar4;
          **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar4 * 2;
          uVar7 = uVar6;
          uVar9 = uVar8;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar5 = iVar4 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
        iVar4 = (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x20) >> 1) + uVar8;
        **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar4;
        **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar4 * 2;
        uVar7 = uVar6;
        uVar9 = uVar8;
        if ((in_stack_00000020 & 2) != 0) {
          iVar4 = **(int **)((int)this + 0x24);
          if (iVar4 != 0) {
            iVar5 = **(int **)((int)this + 0x34);
            iVar3 = **(int **)((int)this + 0x20);
            **(int **)((int)this + 0x24) = iVar3;
            **(int **)((int)this + 0x34) = (iVar4 + iVar5 * 2) - iVar3 >> 1;
          }
        }
      }
    }
  }
  *param_1 = uVar9;
  param_1[1] = uVar7;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10010d80 at 10010d80

void __fastcall FUN_10010d80(int *param_1)

{
  LONG LVar1;
  
  if (*param_1 + -0xc != DAT_100319ac) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
  }
  return;
}



// Function: FUN_10010db0 at 10010db0

undefined4 __thiscall FUN_10010db0(void *this,int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b440;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_100319b0;
    return 1;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new__(param_1 * 2 + 0xe);
  local_8 = 0xffffffff;
  uVar1 = FUN_10010e25();
  return uVar1;
}



// Function: Catch@10010e0f at 10010e0f

undefined * Catch_10010e0f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10010e1c;
}



// Function: FUN_10010e25 at 10010e25

undefined4 FUN_10010e25(void)

{
  undefined4 *in_EAX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (in_EAX == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0;
  }
  *in_EAX = 1;
  *(undefined2 *)((int)in_EAX + unaff_ESI * 2 + 0xc) = 0;
  in_EAX[1] = unaff_ESI;
  in_EAX[2] = unaff_ESI;
  *unaff_EDI = in_EAX + 3;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}



// Function: FUN_10010e70 at 10010e70

short __thiscall FUN_10010e70(void *this,short param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if ((uVar1 != 0) && (**(uint **)((int)this + 0x10) < uVar1)) {
    if ((param_1 == -1) ||
       ((param_1 == *(short *)(uVar1 - 2) || ((*(byte *)((int)this + 0x40) & 2) == 0)))) {
      **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) + 1;
      **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + -2;
      if (param_1 != -1) {
        *(short *)**(undefined4 **)((int)this + 0x20) = param_1;
        return param_1;
      }
      return 0;
    }
  }
  return -1;
}



// Function: FUN_10010ee0 at 10010ee0

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10010ee0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a7e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  FUN_100107a0((int)this);
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



// Function: FUN_10010f50 at 10010f50

void __fastcall FUN_10010f50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b476;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010fb0 at 10010fb0

undefined4 * __fastcall FUN_10010fb0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b4d1;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CContextSensitiveHelpProvider<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_8 = 4;
  if ((undefined *)param_1[4] != &DAT_10026808) {
    Ordinal_6((undefined *)param_1[4],uVar1);
    iVar2 = Ordinal_2(&DAT_10026808);
    param_1[4] = iVar2;
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  param_1[1] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10011060 at 10011060

void __fastcall FUN_10011060(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b521;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CContextSensitiveHelpProvider<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 1;
  Ordinal_6(param_1[4],uVar2);
  local_8 = local_8 & 0xffffff00;
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100110f0 at 100110f0

undefined4 * __thiscall FUN_100110f0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b521;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       CContextSensitiveHelpProvider<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 1;
  Ordinal_6(*(undefined4 *)((int)this + 0x10),uVar2);
  local_8 = local_8 & 0xffffff00;
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011190 at 10011190

void __fastcall FUN_10011190(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_100111a0 at 100111a0

void __cdecl FUN_100111a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
  }
  return;
}



// Function: FUN_10011200 at 10011200

int * __thiscall FUN_10011200(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    uVar1 = Ordinal_149(iVar2);
    iVar2 = Ordinal_150(*param_1,uVar1);
  }
  *(int *)this = iVar2;
  if ((*param_1 != 0) && (iVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_100011a0(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_10011240 at 10011240

void __fastcall FUN_10011240(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b5c7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  }
  local_8._0_1_ = 2;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  FUN_100106d0(param_1 + 4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011300 at 10011300

void __fastcall FUN_10011300(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b600;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100344b0 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011350 at 10011350

void __thiscall FUN_10011350(void *this,ushort *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_100035e0(this,param_1,param_2,*puVar1);
  return;
}



// Function: FUN_10011370 at 10011370

undefined4 * __thiscall FUN_10011370(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b630;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_8 = 1;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10026798,this,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100113e0 at 100113e0

int __thiscall FUN_100113e0(void *this,int param_1)

{
  LONG *lpAddend;
  uint _Size;
  void *_Src;
  int iVar1;
  int iVar2;
  LONG LVar3;
  
                    /* WARNING: Load size is inaccurate */
  _Src = *this;
  lpAddend = (LONG *)((int)_Src + -0xc);
  if ((1 < *(int *)((int)_Src + -0xc)) || (*(int *)((int)_Src + -4) < param_1)) {
    iVar1 = *(int *)((int)_Src + -8);
    if (param_1 < iVar1) {
      param_1 = iVar1;
    }
    iVar2 = FUN_10010db0(this,param_1);
    if (iVar2 == 0) {
      return 0;
    }
    _Size = iVar1 * 2 + 2;
    if (_Size <= param_1 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
      memcpy(*this,_Src,_Size);
    }
                    /* WARNING: Load size is inaccurate */
    *(int *)(*this + -8) = iVar1;
    if (lpAddend != DAT_100319ac) {
      LVar3 = InterlockedDecrement(lpAddend);
      if (LVar3 < 1) {
        operator_delete__(lpAddend);
      }
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10011470 at 10011470

wchar_t __thiscall FUN_10011470(void *this,wchar_t param_1)

{
  void *pvVar1;
  int iVar2;
  void *_Src;
  wchar_t *pwVar3;
  uint uVar4;
  char *pcVar5;
  void *_Dst;
  uint uVar6;
  
  if ((*(byte *)((int)this + 0x40) & 8) != 0) {
    uVar6 = **(uint **)((int)this + 0x24);
    if ((uVar6 != 0) && (uVar4 = *(uint *)((int)this + 0x3c), uVar6 < uVar4)) {
      iVar2 = **(int **)((int)this + 0x34);
      **(uint **)((int)this + 0x24) = uVar4;
      **(int **)((int)this + 0x34) = (int)((uVar6 + iVar2 * 2) - uVar4) >> 1;
    }
  }
  if (param_1 == L'\xffff') {
    return L'\0';
  }
  uVar6 = **(uint **)((int)this + 0x24);
  if ((uVar6 != 0) && (uVar6 < uVar6 + **(int **)((int)this + 0x34) * 2)) {
    pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *pwVar3 = param_1;
    return param_1;
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return L'\xffff';
  }
  if (uVar6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (int)((**(int **)((int)this + 0x34) * 2 - **(int **)((int)this + 0x10)) + uVar6) >> 1;
  }
  uVar4 = uVar6 >> 1;
  if (uVar4 < 0x20) {
    uVar4 = 0x20;
  }
  else if (uVar4 == 0) {
    return L'\xffff';
  }
  do {
    if (uVar6 <= 0x7fffffff - uVar4) break;
    uVar4 = uVar4 >> 1;
  } while (uVar4 != 0);
  if (uVar4 == 0) {
    return L'\xffff';
  }
  pcVar5 = (char *)(uVar4 + uVar6);
  _Dst = FUN_100024a0(pcVar5);
  _Src = (void *)**(undefined4 **)((int)this + 0x10);
  if ((uVar6 == 0) || (memcpy(_Dst,_Src,uVar6 * 2), uVar6 == 0)) {
    *(void **)((int)this + 0x3c) = _Dst;
    **(undefined4 **)((int)this + 0x14) = _Dst;
    **(undefined4 **)((int)this + 0x24) = _Dst;
    **(int **)((int)this + 0x34) = (int)pcVar5 * 2 >> 1;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = _Dst;
      **(undefined4 **)((int)this + 0x30) = 1;
    }
    else {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = 0;
      **(int **)((int)this + 0x30) = (int)_Dst >> 1;
    }
  }
  else {
    *(void **)((int)this + 0x3c) =
         (void *)((int)_Dst + (*(int *)((int)this + 0x3c) - (int)_Src >> 1) * 2);
    pvVar1 = (void *)((int)_Dst + (**(int **)((int)this + 0x24) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x14) =
         (int)((int)_Dst + (**(int **)((int)this + 0x14) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x24) = (int)pvVar1;
    **(int **)((int)this + 0x34) = ((int)pcVar5 * 2 - (int)pvVar1) + (int)_Dst >> 1;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      iVar2 = **(int **)((int)this + 0x24);
      pvVar1 = (void *)((int)_Dst + (**(int **)((int)this + 0x20) - (int)_Src >> 1) * 2);
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(int **)((int)this + 0x20) = (int)pvVar1;
      **(int **)((int)this + 0x30) = (iVar2 - (int)pvVar1) + 2 >> 1;
    }
    else {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = 0;
      **(int **)((int)this + 0x30) = (int)_Dst >> 1;
    }
  }
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *pwVar3 = param_1;
  return param_1;
}



// Function: FUN_10011690 at 10011690

void __fastcall FUN_10011690(int *param_1)

{
  uint _Size;
  void *_Src;
  LONG LVar1;
  int iVar2;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0xc)) {
    if ((int)_Src + -0xc != DAT_100319ac) {
      LVar1 = InterlockedDecrement((LONG *)((int)_Src + -0xc));
      if (LVar1 < 1) {
        operator_delete__((void *)(*param_1 + -0xc));
      }
      *param_1 = (int)PTR_DAT_100319b0;
    }
    iVar2 = FUN_10010db0(param_1,*(int *)((int)_Src + -8));
    if (iVar2 != 0) {
      _Size = *(int *)((int)_Src + -8) * 2 + 2;
      if (_Size <= *(int *)(*param_1 + -4) * 2 + 2U) {
        memcpy((void *)*param_1,_Src,_Size);
      }
    }
  }
  return;
}



// Function: FUN_10011700 at 10011700

void __fastcall FUN_10011700(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b66e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011760 at 10011760

undefined4 __fastcall FUN_10011760(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b6d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = 0;
  iVar2 = __RTDynamicCast(param_1,0,
                          &CComErrorDisplay<class_CImmobilizerInstallationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0,
                          DAT_100344b0 ^ (uint)&stack0xfffffffc);
  local_14 = (int *)(**(code **)(*(int *)(iVar2 + 100) + 0x4c))(2);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  if (local_14 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    (**(code **)*local_14)(local_14,&DAT_10028170,&local_18);
    if (local_14 != (int *)0x0) {
      Ordinal_30(&local_14,0);
    }
    if (local_18 != (int *)0x0) {
      local_1c = (int *)0x0;
      local_8._0_1_ = 5;
      (**(code **)(*local_18 + 0x20))(local_18,&local_1c);
      (**(code **)*local_1c)(local_1c,&DAT_10028180,&local_20);
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  uVar1 = local_20;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10011890 at 10011890

undefined4 * __thiscall
FUN_10011890(void *this,char *param_1,undefined4 param_2,undefined4 *param_3)

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
  puStack_c = &LAB_1001b709;
  local_10 = ExceptionList;
  uStack_34 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0xc);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    local_8 = 1;
    *puVar1 = param_1;
    puVar1[1] = param_2;
    FUN_100111a0((int)this + 9,puVar1 + 2,param_3);
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_24,&param_1);
  local_24[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_24,(ThrowInfo *)&DAT_1002a6f8);
}



// Function: Catch@10011913 at 10011913

void Catch_10011913(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10011960 at 10011960

void __fastcall FUN_10011960(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b756;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100119c0 at 100119c0

undefined4 * __fastcall FUN_100119c0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b7d7;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 + 1 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = param_1 + -0x19;
  }
  puVar3[0x1b] = 0;
  puVar3[0x1e] = 0;
  puVar3[0x1f] = 0;
  puVar3[0x20] = 0;
  puVar3[0x21] = 0;
  puVar3[0x22] = 0;
  puVar3[0x23] = 0;
  puVar3[0x1c] = 0;
  puVar3[0x1d] = 0;
  puVar3[0x24] = 0;
  puVar3[0x10] = 0;
  *param_1 = CComECMPropertyPageImpl<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[1] = CComECMPropertyPageImpl<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  piVar1 = param_1 + 0xe;
  *piVar1 = 0;
  param_1[0xf] = 0;
  local_8 = 8;
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0,uVar2);
  }
  param_1[0x10] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10011aa0 at 10011aa0

undefined4 FUN_10011aa0(undefined4 param_1,undefined2 *param_2)

{
  if (param_2 == (undefined2 *)0x0) {
    return 0x80070057;
  }
  *param_2 = 0;
  return 0;
}



// Function: FUN_10011ac0 at 10011ac0

void FUN_10011ac0(int *param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
  if ((-1 < iVar1) && (*param_2 == 0)) {
    (**(code **)(*param_1 + 0x28))(param_1,param_2);
  }
  return;
}



// Function: FUN_10011af0 at 10011af0

undefined4 FUN_10011af0(void)

{
  return 0x80004001;
}



// Function: FUN_10011b00 at 10011b00

void __thiscall FUN_10011b00(void *this,byte param_1)

{
  FUN_10011b10((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10011b10 at 10011b10

void * __thiscall FUN_10011b10(void *this,byte param_1)

{
  FUN_10011240((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10011b40 at 10011b40

undefined4 FUN_10011b40(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    Ordinal_30(param_1 + 0x38,0);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    Ordinal_30(param_1 + 0x30,0);
  }
  return 0;
}



// Function: FUN_10011b80 at 10011b80

void __fastcall FUN_10011b80(int *param_1)

{
  ios_base *piVar1;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b829;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (ios_base *)(param_1 + 0x14);
  *(undefined ***)(piVar1 + *(int *)(*param_1 + 4) + -0x50) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 1);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_100107a0((int)this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  *(code **)(piVar1 + *(int *)(*param_1 + 4) + -0x50) = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011c30 at 10011c30

undefined4 __thiscall FUN_10011c30(void *this,int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uStack_30;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b870;
  local_10 = ExceptionList;
  uStack_30 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_1c = 1;
  puVar1 = &uStack_30;
  if (param_1 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8 = 3;
    iVar2 = FUN_10011760(this);
    FUN_10010800(&local_18,iVar2);
    if (local_18 != (int *)0x0) {
      local_1c = (**(code **)(*local_18 + 0xc))(local_18,param_1);
      if (local_18 != (int *)0x0) {
        Ordinal_30(&local_18,0);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10016c40((int *)&local_18);
    local_8 = 0;
    puVar1 = (uint *)local_14;
    if (param_1 != (int *)0x0) {
      Ordinal_30(&param_1,0);
      puVar1 = (uint *)local_14;
    }
  }
  local_14 = (undefined1 *)puVar1;
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return local_1c;
}



// Function: Catch@10011cfc at 10011cfc

undefined * Catch_10011cfc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10011d12;
}



// Function: Catch@10011d14 at 10011d14

undefined4 Catch_10011d14(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011cbd;
}



// Function: FUN_10011d30 at 10011d30

int __thiscall FUN_10011d30(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  LONG *lpAddend;
  LPCWSTR pWVar1;
  void *_Src;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  LONG LVar7;
  wchar_t *_Dst;
  int iVar8;
  wchar_t *pwVar9;
  int iVar10;
  int local_10;
  LPCWSTR local_c;
  
  if ((param_1 != (LPCWSTR)0x0) && (iVar3 = lstrlenW(param_1), iVar3 != 0)) {
    if (param_2 == (LPCWSTR)0x0) {
      local_c = param_2;
    }
    else {
      local_c = (LPCWSTR)lstrlenW(param_2);
    }
                    /* WARNING: Load size is inaccurate */
    pwVar9 = *this;
    pWVar1 = pwVar9 + *(int *)(pwVar9 + -4);
    local_10 = 0;
    if (pwVar9 < pWVar1) {
      do {
        pwVar4 = wcsstr(pwVar9,param_1);
        while (pwVar4 != (wchar_t *)0x0) {
          local_10 = local_10 + 1;
          pwVar9 = pwVar4 + iVar3;
          pwVar4 = wcsstr(pwVar9,param_1);
        }
        iVar5 = lstrlenW(pwVar9);
        pwVar9 = pwVar9 + iVar5 + 1;
      } while (pwVar9 < pWVar1);
      if (0 < local_10) {
        FUN_10011690((int *)this);
                    /* WARNING: Load size is inaccurate */
        _Src = *this;
        iVar5 = *(int *)((int)_Src + -8);
        iVar10 = ((int)local_c - iVar3) * local_10 + iVar5;
        if ((*(int *)((int)_Src + -4) < iVar10) || (1 < *(int *)((int)_Src + -0xc))) {
          lpAddend = (LONG *)((int)_Src + -0xc);
          iVar6 = FUN_10010db0(this,iVar10);
          if (iVar6 == 0) {
            return -1;
          }
          uVar2 = *(int *)((int)_Src + -8) * 2;
          if (uVar2 <= iVar10 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
            memcpy(*this,_Src,uVar2);
          }
          if ((lpAddend != DAT_100319ac) && (LVar7 = InterlockedDecrement(lpAddend), LVar7 < 1)) {
            operator_delete__(lpAddend);
          }
        }
                    /* WARNING: Load size is inaccurate */
        pwVar4 = *this;
        pwVar9 = pwVar4 + *(int *)(pwVar4 + -4);
        for (; pwVar4 < pwVar9; pwVar4 = pwVar4 + iVar6 + 1) {
          _Dst = wcsstr(pwVar4,param_1);
          while (_Dst != (wchar_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            iVar6 = (int)_Dst - *this >> 1;
            iVar8 = (iVar5 - iVar6) - iVar3;
            iVar6 = *(int *)(*this + -4) - iVar6;
            uVar2 = iVar8 * 2;
            if (uVar2 <= (iVar6 - (int)local_c) * 2 + 2U) {
              memmove(_Dst + (int)local_c,_Dst + iVar3,uVar2);
            }
            if ((uint)((int)local_c * 2) <= iVar6 * 2 + 2U) {
              memcpy(_Dst,param_2,(int)local_c * 2);
            }
            pwVar4 = _Dst + (int)local_c;
            iVar5 = (int)local_c + (iVar5 - iVar3);
            pwVar4[iVar8] = L'\0';
            _Dst = wcsstr(pwVar4,param_1);
          }
          iVar6 = lstrlenW(pwVar4);
        }
                    /* WARNING: Load size is inaccurate */
        *(int *)(*this + -8) = iVar10;
      }
    }
    return local_10;
  }
  return 0;
}



// Function: FUN_10011f50 at 10011f50

/* WARNING: Removing unreachable block (ram,0x10011ffe) */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10011f50(void *this,uint param_1,int param_2)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b8d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_1002829c;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    local_8 = 1;
  }
  this_00 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,this_00,false);
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this_00);
  uVar1 = 0;
  *(undefined ***)this_00 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
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
  return (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10012040 at 10012040

void __thiscall FUN_10012040(void *this,int param_1,void *param_2)

{
  uint _Size;
  LONG LVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  iVar2 = *this;
  if ((1 < *(int *)(iVar2 + -0xc)) || (*(int *)(iVar2 + -4) < param_1)) {
    if (iVar2 + -0xc != DAT_100319ac) {
      LVar1 = InterlockedDecrement((LONG *)(iVar2 + -0xc));
      if (LVar1 < 1) {
                    /* WARNING: Load size is inaccurate */
        operator_delete__((void *)(*this + -0xc));
      }
      *(undefined **)this = PTR_DAT_100319b0;
    }
    iVar2 = FUN_10010db0(this,param_1);
    if (iVar2 == 0) {
      return;
    }
  }
  _Size = param_1 * 2;
  if (_Size <= _Size + 2) {
                    /* WARNING: Load size is inaccurate */
    memcpy(*this,param_2,_Size);
  }
                    /* WARNING: Load size is inaccurate */
  *(int *)(*this + -8) = param_1;
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return;
}



// Function: FUN_100120d0 at 100120d0

int * __thiscall FUN_100120d0(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x50);
  FUN_10011b80(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10012100 at 10012100

/* WARNING: Removing unreachable block (ram,0x1001216d) */
/* WARNING: Removing unreachable block (ram,0x10012188) */

undefined4 __thiscall FUN_10012100(void *this,int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b940;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  if (param_1 == 0) {
    local_8 = 3;
    Ordinal_200(0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else if (param_1 != 0) {
    Ordinal_30(&local_14);
  }
  piVar2 = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  uVar1 = FUN_10011c30(this,piVar2);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_100121f0 at 100121f0

void __thiscall FUN_100121f0(void *this,LPCWSTR param_1)

{
  uint uVar1;
  void **ppvVar2;
  uint uVar3;
  undefined2 *puVar4;
  LPCWSTR pWVar5;
  int iVar6;
  HWND hDlg;
  BOOL BVar7;
  LONG LVar8;
  int iVar9;
  LPCWSTR pWVar10;
  undefined4 local_38;
  int local_34;
  int local_30;
  LPCWSTR local_2c;
  undefined4 *local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b970;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  iVar6 = *(int *)param_1;
  ppvVar2 = &local_10;
  local_18 = (undefined4 *)this;
  pWVar10 = param_1;
  local_10 = ExceptionList;
  do {
    ExceptionList = ppvVar2;
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return;
    }
    local_14 = (LPCWSTR)0x0;
    local_8 = 1;
    iVar6 = *(int *)pWVar10;
    iVar9 = -0x7fffbffb;
    param_1 = (LPCWSTR)PTR_DAT_100319b0;
    if (((iVar6 == 0x1f5) || (iVar6 == 0x192)) || (iVar6 == 0x193)) {
LAB_100122a6:
      iVar9 = 0;
    }
    else {
      uVar1 = *(uint *)(pWVar10 + 4);
      Ordinal_6(0,uVar3);
      local_14 = (LPCWSTR)0x0;
      puVar4 = (undefined2 *)FUN_1000a380(uVar1);
      if (puVar4 == (undefined2 *)0x0) {
        local_14 = (LPCWSTR)0x0;
      }
      else {
        pWVar5 = (LPCWSTR)Ordinal_4(puVar4 + 1,*puVar4);
        local_14 = pWVar5;
        if (pWVar5 != (LPCWSTR)0x0) {
          iVar6 = lstrlenW(pWVar5);
          FUN_10012040(&param_1,iVar6,pWVar5);
          goto LAB_100122a6;
        }
      }
    }
    hDlg = (HWND)*local_18;
    if (*(int *)pWVar10 == 100) {
LAB_100123f4:
      SetWindowTextW(hDlg,param_1);
    }
    else {
      hDlg = GetDlgItem(hDlg,*(int *)(pWVar10 + 2));
      if (((-1 < iVar9) && (BVar7 = IsWindow((HWND)*local_18), BVar7 != 0)) &&
         (BVar7 = IsWindow(hDlg), BVar7 != 0)) {
        iVar6 = *(int *)pWVar10;
        if ((iVar6 == 200) || (iVar6 == 300)) {
          FUN_10011d30(&param_1,L"\\r\\n",L"\r\n");
          goto LAB_100123f4;
        }
        if (iVar6 == 500) {
          local_30 = *(int *)(pWVar10 + 8);
          local_34 = *(int *)(pWVar10 + 10);
          local_38 = 7;
          local_2c = param_1;
          SendMessageW(hDlg,0x1061,*(WPARAM *)(pWVar10 + 6),(LPARAM)&local_38);
        }
        else if (iVar6 == 0x1f5) {
          SendMessageW(hDlg,0x101e,*(WPARAM *)(pWVar10 + 6),(uint)(ushort)pWVar10[8]);
        }
        else if (iVar6 == 400) {
          SendMessageW(hDlg,0x143,0,(LPARAM)param_1);
        }
        else if (iVar6 == 0x191) {
          SendMessageW(hDlg,0x14a,*(WPARAM *)(pWVar10 + 6),(LPARAM)param_1);
        }
        else if (iVar6 == 0x192) {
          SendMessageW(hDlg,0x14e,*(WPARAM *)(pWVar10 + 6),0);
        }
        else if (iVar6 == 0x193) {
          SendMessageW(hDlg,0x151,*(WPARAM *)(pWVar10 + 6),*(LPARAM *)(pWVar10 + 8));
        }
      }
    }
    pWVar10 = pWVar10 + 0xc;
    local_8 = local_8 & 0xffffff00;
    if (param_1 + -6 != DAT_100319ac) {
      pWVar5 = param_1 + -6;
      LVar8 = InterlockedDecrement((LONG *)pWVar5);
      if (LVar8 < 1) {
        operator_delete__(pWVar5);
      }
    }
    local_8 = 0xffffffff;
    Ordinal_6(local_14);
    iVar6 = *(int *)pWVar10;
    ppvVar2 = (void **)ExceptionList;
  } while( true );
}



// Function: FUN_10012460 at 10012460

void __fastcall FUN_10012460(int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      operator_delete(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  local_8 = 0xffffffff;
  operator_delete((void *)*param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100124e0 at 100124e0

void __thiscall
FUN_100124e0(void *this,HWND param_1,int param_2,int param_3,int param_4,int param_5,HWND param_6,
            HWND param_7)

{
  wchar_t wVar1;
  char *pcVar2;
  HWND hWnd;
  int iVar3;
  LPWSTR pWVar4;
  undefined4 *puVar5;
  undefined4 *extraout_EAX;
  LONG LVar6;
  wchar_t *pwVar7;
  int extraout_ECX;
  int iVar8;
  bool bVar9;
  tagPOINT local_7c;
  tagPOINT local_74;
  int local_6c;
  HWND local_68;
  HWND local_64;
  int local_60;
  int local_5c;
  HWND__ local_58;
  tagPOINT local_54;
  HWND local_4c;
  LPWSTR local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b9d3;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58.unused = (int)param_1;
  local_64 = param_6;
  local_68 = param_7;
  iVar3 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0,local_14);
  local_4c = *(HWND *)(iVar3 + 0x40);
  local_6c = 0;
  local_48 = (LPWSTR)PTR_DAT_100319b0;
  local_8 = 0;
  pWVar4 = (LPWSTR)FUN_100113e0(&local_48,0x104);
  if (pWVar4 != (LPWSTR)0x0) {
    local_48[-0xffffffff00000004] = L'Ą';
    local_48[-0xffffffff00000003] = L'\0';
    local_48[0x104] = L'\0';
    pWVar4 = local_48;
  }
  GetClassNameW(param_1,pWVar4,0x104);
  FUN_10011690((int *)&local_48);
  pWVar4 = local_48;
  iVar3 = lstrlenW(local_48);
  *(int *)(pWVar4 + -4) = iVar3;
  pWVar4[iVar3] = L'\0';
  FUN_10011690((int *)&local_48);
  pWVar4 = local_48;
  CharUpperW(local_48);
  hWnd = local_4c;
  pwVar7 = L"LISTBOX";
  do {
    wVar1 = *pWVar4;
    bVar9 = (ushort)wVar1 < (ushort)*pwVar7;
    if (wVar1 != *pwVar7) {
LAB_100125d7:
      iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_100125dc;
    }
    if (wVar1 == L'\0') break;
    wVar1 = pWVar4[1];
    bVar9 = (ushort)wVar1 < (ushort)pwVar7[1];
    if (wVar1 != pwVar7[1]) goto LAB_100125d7;
    pWVar4 = pWVar4 + 2;
    pwVar7 = pwVar7 + 2;
  } while (wVar1 != L'\0');
  iVar3 = 0;
LAB_100125dc:
  if (iVar3 == 0) {
    local_6c = 1;
  }
  local_44.left = 0;
  local_44.top = 0;
  local_44.right = 0;
  local_44.bottom = 0;
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  GetClientRect(local_4c,&local_44);
  GetWindowRect(param_1,&local_34);
  local_74.y = local_34.top;
  local_74.x = local_34.right;
  local_7c.x = local_34.left;
  local_7c.y = local_34.bottom;
  ScreenToClient(hWnd,&local_74);
  ScreenToClient(local_4c,&local_7c);
  local_34.bottom = local_7c.y;
  local_34.right = local_74.x;
  local_34.top = local_74.y;
  local_34.left = local_7c.x;
  if ((param_4 == DAT_1003330c) && (param_5 == DAT_10033310)) {
    param_4 = param_2;
    param_5 = param_3;
  }
  if (local_64 == (HWND)0x0) {
    local_60 = local_7c.x - ((local_44.right - local_44.left) * param_2) / 100;
    local_5c = local_74.y - ((local_44.bottom - local_44.top) * param_3) / 100;
  }
  else {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(local_64,&local_24);
    local_54.x = local_24.left;
    local_54.y = local_24.top;
    ScreenToClient(local_4c,&local_54);
    local_60 = local_54.x;
    local_5c = 0;
  }
  if (local_68 == (HWND)0x0) {
    iVar3 = local_34.bottom - ((local_44.bottom - local_44.top) * param_5) / 100;
    iVar8 = local_34.right - ((local_44.right - local_44.left) * param_4) / 100;
  }
  else {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(local_68,&local_24);
    local_54.x = local_24.right;
    local_54.y = local_24.bottom;
    ScreenToClient(local_4c,&local_54);
    iVar3 = 0;
    iVar8 = 0;
  }
  local_4c = (HWND)operator_new(0x34);
  if (local_4c == (HWND)0x0) {
    local_58.unused = 0;
  }
  else {
    local_24.bottom = param_5;
    local_54.x = param_2;
    local_54.y = param_3;
    *local_4c = (HWND__)local_58.unused;
    ((int *)local_4c)[1] = local_6c;
    ((int *)local_4c)[3] = param_2;
    ((int *)local_4c)[4] = param_3;
    ((int *)local_4c)[5] = local_60;
    ((int *)local_4c)[7] = param_4;
    ((int *)local_4c)[6] = local_5c;
    ((int *)local_4c)[8] = param_5;
    ((int *)local_4c)[2] = 0;
    ((int *)local_4c)[9] = iVar8;
    ((int *)local_4c)[10] = iVar3;
    ((int *)local_4c)[0xb] = (int)local_64;
    ((int *)local_4c)[0xc] = (int)local_68;
    local_58.unused = (int)local_4c;
  }
  local_8 = local_8 & 0xffffff00;
  pcVar2 = *(char **)((int)this + 0x5c);
  puVar5 = FUN_10011890((void *)((int)this + 0x5c),pcVar2,*(undefined4 *)(pcVar2 + 4),&local_58);
  iVar3 = *(int *)((int)this + 0x60);
  if (iVar3 == 0x3ffffffe) {
    std::_Xlength_error("list<T> too long");
    puVar5 = extraout_EAX;
    iVar3 = extraout_ECX;
  }
  *(int *)((int)this + 0x60) = iVar3 + 1;
  *(undefined4 **)(pcVar2 + 4) = puVar5;
  *(undefined4 **)puVar5[1] = puVar5;
  local_8 = 0xffffffff;
  if (local_48 + -6 != DAT_100319ac) {
    pWVar4 = local_48 + -6;
    LVar6 = InterlockedDecrement((LONG *)pWVar4);
    if (LVar6 < 1) {
      operator_delete__(pWVar4);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012890 at 10012890

undefined4 * __thiscall FUN_10012890(void *this,undefined4 *param_1)

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



// Function: FUN_10012910 at 10012910

undefined4 * __fastcall FUN_10012910(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined **local_28 [3];
  int *local_1c;
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ba1c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = param_1 + 0x17;
  *param_1 = CResizingDialog<class_CImmobilizerInstallationPageImpl>::vftable;
  param_1[0x18] = 0;
  local_1c = piVar1;
  local_18 = param_1;
  pvVar2 = operator_new(0xc);
  if (pvVar2 != (void *)0x0) {
    *piVar1 = (int)pvVar2;
    *(void **)pvVar2 = pvVar2;
    *(int *)(*piVar1 + 4) = *piVar1;
    local_8 = 2;
    param_1[5] = 1;
    param_1[2] = 1;
    param_1[1] = 0;
    param_1[3] = 0;
    param_1[6] = 0;
    param_1[7] = 1;
    param_1[8] = 0;
    local_14 = (char *)GetSystemMetrics(0x14);
    iVar3 = GetSystemMetrics(2);
    param_1[0x15] = iVar3;
    param_1[0x16] = local_14;
    param_1[4] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_1002a6f8);
}



// Function: FUN_100129f0 at 100129f0

void __fastcall FUN_100129f0(undefined4 *param_1)

{
  int *this;
  int *piVar1;
  int *piVar2;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba53;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CResizingDialog<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 0;
  piVar2 = *(int **)param_1[0x17];
  this = param_1 + 0x17;
  local_14 = param_1;
  if (piVar2 != (int *)param_1[0x17]) {
    do {
      operator_delete((void *)piVar2[2]);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*this);
  }
  FUN_10007270(this,(int *)&local_18,*(int **)*this,(int *)*this);
  local_8 = 1;
  piVar2 = (int *)*this;
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*this + 4) = *this;
  param_1[0x18] = 0;
  local_18 = this;
  if (piVar1 != (int *)*this) {
    do {
      piVar2 = (int *)*piVar1;
      operator_delete(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)*this);
  }
  local_8 = 0xffffffff;
  operator_delete((void *)*this);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012ac0 at 10012ac0

void __thiscall
FUN_10012ac0(void *this,HWND param_1,HWND param_2,int param_3,int param_4,HWND param_5,int param_6,
            int param_7)

{
  HWND hDlg;
  HWND pHVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  HWND pHVar5;
  HWND local_18;
  int local_14;
  HWND local_8;
  
  local_18 = (HWND)0x0;
  local_14 = 0;
  local_8 = (HWND)0x0;
  iVar3 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  iVar2 = DAT_10033310;
  pHVar1 = DAT_1003330c;
  hDlg = *(HWND *)(iVar3 + 0x40);
  if (param_4 == 0) {
    pHVar4 = (HWND)0x0;
    pHVar5 = param_2;
  }
  else {
    pHVar4 = param_2;
    pHVar5 = pHVar1;
    param_3 = iVar2;
    if ((param_4 != 1) && (pHVar4 = (HWND)0x0, pHVar5 = (HWND)0x0, param_3 = 0, param_4 == 2)) {
      pHVar4 = GetDlgItem(hDlg,(int)param_2);
      pHVar5 = pHVar1;
      param_3 = iVar2;
    }
  }
  if (param_7 == 0) {
    local_8 = (HWND)0x0;
    local_18 = param_5;
    local_14 = param_6;
  }
  else if (param_7 == 1) {
    local_8 = param_5;
    local_18 = DAT_1003330c;
    local_14 = DAT_10033310;
  }
  else if (param_7 == 2) {
    local_18 = DAT_1003330c;
    local_14 = DAT_10033310;
    local_8 = GetDlgItem(hDlg,(int)param_5);
  }
  FUN_100124e0(this,param_1,(int)pHVar5,param_3,(int)local_18,local_14,pHVar4,local_8);
  return;
}



// Function: FUN_10012bc0 at 10012bc0

int __fastcall FUN_10012bc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001bb8b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined ***)(param_1 + 4) = CComErrorHandler::vftable;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x30) = 7;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  *(undefined ***)(param_1 + 0x38) =
       CComErrorDisplay<class_CImmobilizerInstallationPageImpl>::vftable;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  uStack_7 = 0;
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  local_8 = 0xf;
  FUN_100119c0((undefined4 *)(param_1 + 100));
  local_8 = 0x10;
  *(undefined4 *)(param_1 + 0xac) = 0;
  FUN_10012910((undefined4 *)(param_1 + 0xb4));
  local_8 = 0x11;
  FUN_10010fb0((undefined4 *)(param_1 + 0x11c));
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  _local_8 = CONCAT31(uStack_7,0x14);
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  FUN_10018190((undefined4 *)(param_1 + 0x144));
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10012d20 at 10012d20

void __fastcall FUN_10012d20(int param_1)

{
  int *piVar1;
  BOOL BVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bca5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 0x154);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  }
  local_8._0_1_ = 8;
  piVar1 = *(int **)(param_1 + 0x150);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 7;
  FUN_10017dc0((undefined4 *)(param_1 + 0x144));
  local_8._0_1_ = 6;
  if (*(HGDIOBJ *)(param_1 + 0x138) != (HGDIOBJ)0x0) {
    BVar2 = DeleteObject(*(HGDIOBJ *)(param_1 + 0x138));
    if (BVar2 != 0) {
      *(undefined4 *)(param_1 + 0x138) = 0;
    }
  }
  local_8._0_1_ = 5;
  if (*(HGDIOBJ *)(param_1 + 0x134) != (HGDIOBJ)0x0) {
    BVar2 = DeleteObject(*(HGDIOBJ *)(param_1 + 0x134));
    if (BVar2 != 0) {
      *(undefined4 *)(param_1 + 0x134) = 0;
    }
  }
  *(undefined ***)(param_1 + 0x11c) =
       CContextSensitiveHelpProvider<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8._0_1_ = 0xe;
  Ordinal_6(*(undefined4 *)(param_1 + 300));
  local_8._0_1_ = 0xd;
  piVar1 = *(int **)(param_1 + 0x128);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 4;
  piVar1 = *(int **)(param_1 + 0x124);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 3;
  FUN_100129f0((undefined4 *)(param_1 + 0xb4));
  local_8._0_1_ = 2;
  FUN_10011240(param_1 + 100);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(void **)(param_1 + 0x50) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x50));
  }
  *(undefined ***)(param_1 + 0x38) =
       CComErrorDisplay<class_CImmobilizerInstallationPageImpl>::vftable;
  local_8 = 0xffffffff;
  FUN_1000bd10((undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012ea0 at 10012ea0

void __thiscall FUN_10012ea0(void *this,undefined2 *param_1)

{
  uint uVar1;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bcf1;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(uint *)((int)this + 0x40) & 2) == 0) && (**(uint **)((int)this + 0x24) != 0)) {
    uVar1 = **(uint **)((int)this + 0x24);
    if (uVar1 <= *(uint *)((int)this + 0x3c)) {
      uVar1 = *(uint *)((int)this + 0x3c);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    FUN_100057e0(&local_30,(int *)**(undefined4 **)((int)this + 0x14),
                 (int)(uVar1 - (int)**(undefined4 **)((int)this + 0x14)) >> 1);
    local_8 = 1;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_10012890(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  else {
    if (((*(uint *)((int)this + 0x40) & 4) != 0) || (**(int **)((int)this + 0x20) == 0)) {
      local_1c = 7;
      local_20 = 0;
      local_30 = (void *)((uint)local_30._2_2_ << 0x10);
      local_8 = 3;
      *(undefined4 *)(param_1 + 10) = 7;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 0;
      FUN_10012890(param_1,&local_30);
      local_8 = local_8 & 0xffffff00;
      if (7 < local_1c) {
        operator_delete(local_30);
      }
      local_30 = (void *)((uint)local_30 & 0xffff0000);
      goto LAB_10013025;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    FUN_100057e0(&local_30,(int *)**(undefined4 **)((int)this + 0x10),
                 (**(int **)((int)this + 0x20) + **(int **)((int)this + 0x30) * 2) -
                 (int)**(undefined4 **)((int)this + 0x10) >> 1);
    local_8 = 2;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_10012890(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
      local_30 = (void *)((uint)local_30 & 0xffff0000);
      goto LAB_10013025;
    }
  }
  local_30 = (void *)((uint)local_30 & 0xffff0000);
LAB_10013025:
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013050 at 10013050

void FUN_10013050(undefined2 *param_1,uint param_2)

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
  
  puStack_c = &LAB_1001bd49;
  local_10 = ExceptionList;
  uStack_54 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_3c = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_18 = uStack_54;
  bVar2 = FUN_1000a950(&local_3c,param_2);
  piVar1 = local_3c;
  if (!bVar2) {
    local_35 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_35,(ThrowInfo *)&DAT_1002d238);
  }
  puVar3 = (undefined4 *)FUN_10007330(local_34,local_3c);
  local_8._0_1_ = 3;
  FUN_10012890(param_1,puVar3);
  local_8._0_1_ = 2;
  FUN_100047c0(local_34);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(piVar1);
  local_8 = 0;
  FUN_10013115();
  return;
}



// Function: Catch@10013105 at 10013105

undefined * Catch_10013105(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10013112;
}



// Function: FUN_10013115 at 10013115

void FUN_10013115(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1001312f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10013140 at 10013140

undefined2 * __cdecl FUN_10013140(undefined2 *param_1,int *param_2)

{
  ushort *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd89;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100056e0(param_1,param_2,0,0xffffffff);
  local_8 = 0;
  puVar1 = DAT_100332f0;
  if (DAT_10033304 < 8) {
    puVar1 = (ushort *)&DAT_100332f0;
  }
  uVar2 = FUN_100035e0(param_1,puVar1,0,DAT_10033300);
  while (uVar2 != 0xffffffff) {
    FUN_100058e0(param_1,uVar2,DAT_10033300,&DAT_1003329c,0,0xffffffff);
    uVar2 = FUN_10011350(param_1,(ushort *)&DAT_100332f0,0);
  }
  puVar1 = DAT_100332d4;
  if (DAT_100332e8 < 8) {
    puVar1 = (ushort *)&DAT_100332d4;
  }
  uVar2 = FUN_100035e0(param_1,puVar1,0,DAT_100332e4);
  while (uVar2 != 0xffffffff) {
    FUN_100058e0(param_1,uVar2,DAT_100332e4,&DAT_100332b8,0,0xffffffff);
    uVar2 = FUN_10011350(param_1,(ushort *)&DAT_100332d4,0);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013250 at 10013250

void __fastcall FUN_10013250(int param_1)

{
  void *this;
  HWND pHVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  int iVar5;
  HWND pHVar6;
  int iVar7;
  
  iVar4 = DAT_100345ac;
  pHVar3 = DAT_100345a8;
  iVar2 = DAT_10033320;
  pHVar1 = DAT_1003331c;
  iVar7 = 0x69;
  this = (void *)(param_1 + 0xb4);
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_100345ac;
  pHVar3 = DAT_100345a8;
  iVar2 = DAT_10033320;
  pHVar1 = DAT_1003331c;
  iVar7 = 0x68;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_100345ac;
  pHVar3 = DAT_100345a8;
  iVar2 = DAT_10033320;
  pHVar1 = DAT_1003331c;
  iVar7 = 0x6b;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_10033320;
  pHVar3 = DAT_1003331c;
  iVar2 = DAT_10033310;
  pHVar1 = DAT_1003330c;
  iVar7 = 0x6a;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_100345ac;
  pHVar3 = DAT_100345a8;
  iVar2 = DAT_10033320;
  pHVar1 = DAT_1003331c;
  iVar7 = 0x6f;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_10033340;
  pHVar3 = DAT_1003333c;
  iVar2 = DAT_10033310;
  pHVar1 = DAT_1003330c;
  iVar7 = 0x66;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_10033360;
  pHVar3 = DAT_1003335c;
  iVar2 = DAT_10033310;
  pHVar1 = DAT_1003330c;
  iVar7 = 0x67;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  iVar4 = DAT_100345ac;
  pHVar3 = DAT_100345a8;
  iVar2 = DAT_10033320;
  pHVar1 = DAT_1003331c;
  iVar7 = 0x72;
  iVar5 = __RTDynamicCast(this,0,&CResizingDialog<class_CImmobilizerInstallationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CImmobilizerInstallationPageImpl::RTTI_Type_Descriptor,0);
  pHVar6 = GetDlgItem(*(HWND *)(iVar5 + 0x40),iVar7);
  FUN_10012ac0(this,pHVar6,pHVar3,iVar4,0,pHVar1,iVar2,0);
  return;
}



// Function: FUN_100135e0 at 100135e0

undefined2 * __thiscall FUN_100135e0(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bdc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10012ea0((void *)((int)this + 4),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013640 at 10013640

/* WARNING: Removing unreachable block (ram,0x100137ce) */
/* WARNING: Removing unreachable block (ram,0x100137e1) */
/* WARNING: Removing unreachable block (ram,0x100137f4) */
/* WARNING: Removing unreachable block (ram,0x1001380a) */

undefined4 __fastcall FUN_10013640(int param_1)

{
  int iVar1;
  uint uStack_48;
  undefined **local_38;
  undefined1 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [2];
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be68;
  local_10 = ExceptionList;
  uStack_48 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  local_1c = 0;
  local_18 = 0;
  local_28 = 0;
  local_24[0] = 0;
  local_34 = 0;
  local_30 = 0;
  local_38 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_2c = 0x80004005;
  if (*(int *)(param_1 + 0xc) != 0) {
    local_8 = 9;
    ExceptionList = &local_10;
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                      (*(undefined4 **)(param_1 + 0xc),&DAT_10027dc4,local_24);
                    /* WARNING: Subroutine does not return */
    FUN_1000a090(&local_38,iVar1);
  }
  return 0x80004005;
}



// Function: Catch@100137a9 at 100137a9

undefined * Catch_100137a9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 8;
  return &DAT_100137b6;
}



// Function: FUN_10013830 at 10013830

void __fastcall FUN_10013830(int param_1)

{
  int iVar1;
  uint uStack_50;
  undefined **local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bec8;
  local_10 = ExceptionList;
  uStack_50 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_50;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = 0;
  local_30 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_24 = 0;
  local_1c[0] = 0;
  local_8 = 3;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x94))
                    (*(undefined4 **)(param_1 + 0x94),&DAT_10026788,local_1c);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_30,iVar1);
}



// Function: Catch@1001396e at 1001396e

undefined1 * Catch_1001396e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_1001397b;
}



// Function: FUN_100139a0 at 100139a0

void FUN_100139a0(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  wchar_t *unaff_EDI;
  int local_cc [38];
  undefined1 *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bf0b;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10011f50(local_cc,2,1);
  local_8 = 0;
  __RTDynamicCast(param_1,0);
  piVar2 = (int *)FUN_1000b4d0(local_cc,param_2);
  FUN_1000b4d0(piVar2,unaff_EDI);
  iVar3 = __RTDynamicCast();
  piVar2 = (int *)FUN_100135e0(local_cc,(undefined2 *)local_30);
  local_8._0_1_ = 1;
  if (7 < (uint)piVar2[5]) {
    piVar2 = (int *)*piVar2;
  }
  piVar4 = piVar2;
  do {
    iVar1 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 2);
  } while ((short)iVar1 != 0);
  local_34 = &stack0xffffff18;
  FUN_100057e0(&stack0xffffff18,piVar2,(int)piVar4 - ((int)piVar2 + 2) >> 1);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)(iVar3 + 0xa8) + 0x3c))();
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_8 = 0xffffffff;
  FUN_10011b80(local_cc);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013b00 at 10013b00

void __fastcall FUN_10013b00(int *param_1)

{
  int iVar1;
  uint uStack_40;
  undefined **local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf60;
  local_10 = ExceptionList;
  uStack_40 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = 0;
  local_30 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_24 = 0x80004005;
  local_1c[0] = 0;
  local_8 = 2;
  iVar1 = (**(code **)(*param_1 + 8))(local_1c);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_30,iVar1);
}



// Function: Catch@10013bff at 10013bff

undefined1 * Catch_10013bff(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10013bd1;
}



// Function: FUN_10013c10 at 10013c10

void FUN_10013c10(undefined4 param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bfc1;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar1 = false;
  while (!bVar1) {
    iVar3 = FUN_10001020((int *)PTR_DAT_10033b10,param_2);
    if (iVar3 != 0) goto LAB_10013c83;
    bVar1 = true;
  }
  local_8 = 0xffffffff;
LAB_10013c83:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10013ca1 at 10013ca1

undefined * Catch_10013ca1(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x68);
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10013d33;
}



// Function: Catch@10013d38 at 10013d38

undefined * Catch_10013d38(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x60) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar4 = *(undefined4 *)(unaff_EBP + -0x48);
  }
  else {
    uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0x60) + 4);
    *(undefined4 *)(unaff_EBP + -0x48) = uVar4;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar6 = 0x85;
  pcVar5 = "ImmobilizerInstallationPageImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),uVar4,uVar4,uVar2,(int *)pcVar5,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10013dff;
}



// Function: Catch@10013e04 at 10013e04

undefined * Catch_10013e04(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 5;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar5 = 0x85;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar2,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  std::exception::~exception((exception *)(unaff_EBP + -0x74));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10013edc;
}



// Function: Catch@10013ee1 at 10013ee1

undefined4 Catch_10013ee1(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_100331c8,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x80004005;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined ***)(unaff_EBP + -0x58) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar5 = 0x85;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar2 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar2,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10013c80;
}



// Function: FUN_10013fb0 at 10013fb0

void FUN_10013fb0(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  uint uStack_90;
  undefined **local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c039;
  local_10 = ExceptionList;
  uStack_90 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_4c = param_1;
  local_58 = 0;
  local_54 = 0;
  local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_50 = 0x80004005;
  local_8 = 1;
  local_18 = uStack_90;
  iVar1 = FUN_100139a0(param_1,param_2);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_5c,iVar1);
}



// Function: FUN_10014031 at 10014031

void FUN_10014031(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x4c) < 0) {
    FUN_10012100((void *)(*(int *)(unaff_EBP - 0x48) + -0x2c),0);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x58) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1001406d;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10014073 at 10014073

undefined1 * Catch_10014073(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x70);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_10014104;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
}



// Function: Catch@10014109 at 10014109

undefined1 * Catch_10014109(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
    uVar5 = 0xa7;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
                 *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_100141cc;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -0x6c) + 4));
}



// Function: Catch@100141d1 at 100141d1

undefined4 Catch_100141d1(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 6;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      uVar3 = FUN_10014031();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  uVar5 = 0xa7;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100142c4;
}



// Function: Catch@100142c9 at 100142c9

undefined * Catch_100142c9(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  uVar7 = 0xa7;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_10014031;
}



// Function: FUN_100143b0 at 100143b0

void FUN_100143b0(int param_1)

{
  int iVar1;
  uint uStack_90;
  undefined **local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c0a9;
  local_10 = ExceptionList;
  uStack_90 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_4c = param_1;
  local_58 = 0;
  local_54 = 0;
  local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_50 = 0x80004005;
  local_8 = 1;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  local_18 = uStack_90;
  iVar1 = FUN_10011b40(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_5c,iVar1);
}



// Function: FUN_1001441a at 1001441a

void FUN_1001441a(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x4c) < 0) {
    FUN_10012100((void *)(*(int *)(unaff_EBP - 0x48) + -0x2c),0);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x58) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10014456;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1001445c at 1001445c

undefined1 * Catch_1001445c(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x70);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_100144ed;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
}



// Function: Catch@100144f2 at 100144f2

undefined1 * Catch_100144f2(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x6c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
    uVar5 = 0xcb;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
                 *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_100145b5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -0x6c) + 4));
}



// Function: Catch@100145ba at 100145ba

undefined4 Catch_100145ba(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 6;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      uVar3 = FUN_1001441a();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  uVar5 = 0xcb;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100146ad;
}



// Function: Catch@100146b2 at 100146b2

undefined * Catch_100146b2(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x68),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x68) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x60);
  uVar7 = 0xcb;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_1001441a;
}



// Function: FUN_100147a0 at 100147a0

void __fastcall FUN_100147a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[-0x2e] + 0x4c))(1);
  if (param_1[2] != iVar1) {
    Ordinal_30(param_1 + 2,iVar1);
  }
  iVar1 = (**(code **)(param_1[-0x2e] + 0x4c))(2);
  if (param_1[3] != iVar1) {
    Ordinal_30(param_1 + 3,iVar1);
  }
  FUN_10013b00(param_1);
  return;
}



// Function: FUN_10014810 at 10014810

void __fastcall FUN_10014810(int param_1)

{
  int iVar1;
  uint uStack_98;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c12c;
  local_10 = ExceptionList;
  uStack_98 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_64 = 0;
  local_60 = 0;
  local_8 = 3;
  local_5c = param_1;
  local_18 = uStack_98;
  FUN_1000a950(&local_64,0x8d);
  FUN_1000a950(&local_60,0x8e);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x154) + 0x404))
                    (*(int **)(param_1 + 0x154),0,0,local_64);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_58,iVar1);
}



// Function: Catch@1001490a at 1001490a

undefined * Catch_1001490a(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x78);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_1001499b;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@100149a0 at 100149a0

undefined * Catch_100149a0(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -100) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
    uVar5 = 0x305;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
                 *(undefined4 *)(unaff_EBP + -0x48),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10014a63;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -100) + 4));
}



// Function: Catch@10014a68 at 10014a68

undefined4 Catch_10014a68(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  int *this;
  undefined4 uStack0000000c;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP - 4) = 8;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP - 0x74),unaff_EBP - 0x54);
    *(undefined1 *)(unaff_EBP - 4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    *(undefined ***)(unaff_EBP - 0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP - 0x50) == '\0') {
      *(undefined1 *)(unaff_EBP - 0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP - 0x4c));
      *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
      *(undefined ***)(unaff_EBP - 0x54) =
           CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
      ExceptionList = *(void **)(unaff_EBP - 0xc);
      uStack0000000c = 0x10014906;
      uVar3 = __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP - 0x58) + 4);
  uVar5 = 0x305;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP - 0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP - 0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP - 0x34);
  if (*(uint *)(unaff_EBP - 0x20) < 8) {
    iVar2 = unaff_EBP - 0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP - 0x40),*(long *)(unaff_EBP - 0x3c),iVar2,
               *(wchar_t **)(unaff_EBP - 0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10004f30((undefined4 *)(unaff_EBP - 0x44));
  *(undefined1 *)(unaff_EBP - 4) = 4;
  std::exception::~exception((exception *)(unaff_EBP - 0x84));
  *(undefined4 *)(unaff_EBP - 4) = 0;
  return 0x10014b5a;
}



// Function: Catch@10014b5f at 10014b5f

undefined1 * Catch_10014b5f(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined1 *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
  uVar7 = 0x305;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_100148e0;
}



// Function: FUN_10014c40 at 10014c40

void __fastcall FUN_10014c40(int param_1)

{
  int iVar1;
  uint uStack_a8;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c1d0;
  local_10 = ExceptionList;
  uStack_a8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a8;
  ExceptionList = &local_10;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_64 = 0;
  local_60 = 0;
  local_8 = 4;
  local_5c = param_1;
  local_18 = uStack_a8;
  FUN_1000a950(&local_64,0x8f);
  FUN_1000a950(&local_60,0x90);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x154) + 0x2f0))(*(int **)(param_1 + 0x154),1);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_58,iVar1);
}



// Function: Catch@10014ebb at 10014ebb

undefined * Catch_10014ebb(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x88);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x84),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined ***)(unaff_EBP + -0x84) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10014f55;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@10014f5a at 10014f5a

undefined * Catch_10014f5a(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x84),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x74) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined ***)(unaff_EBP + -0x84) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
    uVar5 = 0x344;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
                 *(undefined4 *)(unaff_EBP + -0x48),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10015023;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x74) + 4));
}



// Function: Catch@10015028 at 10015028

undefined4 Catch_10015028(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  int *this;
  undefined4 uStack0000000c;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP - 4) = 9;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP - 0x84),unaff_EBP - 0x54);
    *(undefined1 *)(unaff_EBP - 4) = 10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP - 4) = 9;
    *(undefined ***)(unaff_EBP - 0x84) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP - 0x50) == '\0') {
      *(undefined1 *)(unaff_EBP - 0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP - 0x4c));
      *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
      *(undefined ***)(unaff_EBP - 0x54) =
           CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
      ExceptionList = *(void **)(unaff_EBP - 0xc);
      uStack0000000c = 0x10014eb7;
      uVar3 = __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP - 0x58) + 4);
  uVar5 = 0x344;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP - 0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP - 4) = 0xb;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP - 0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP - 0x34);
  if (*(uint *)(unaff_EBP - 0x20) < 8) {
    iVar2 = unaff_EBP - 0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP - 0x40),*(long *)(unaff_EBP - 0x3c),iVar2,
               *(wchar_t **)(unaff_EBP - 0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP - 4) = 9;
  FUN_10004f30((undefined4 *)(unaff_EBP - 0x44));
  *(undefined1 *)(unaff_EBP - 4) = 5;
  std::exception::~exception((exception *)(unaff_EBP - 0x94));
  *(undefined4 *)(unaff_EBP - 4) = 0;
  return 0x10015120;
}



// Function: Catch@10015125 at 10015125

undefined1 * Catch_10015125(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x84),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined ***)(unaff_EBP + -0x84) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined1 *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 4);
  uVar7 = 0x344;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10014e91;
}



// Function: FUN_10015210 at 10015210

/* WARNING: Removing unreachable block (ram,0x10015379) */
/* WARNING: Removing unreachable block (ram,0x1001537d) */
/* WARNING: Removing unreachable block (ram,0x10015388) */

void __fastcall FUN_10015210(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  UINT UVar3;
  int local_88;
  LPCWSTR *local_80 [5];
  uint local_6c;
  undefined4 local_64 [4];
  undefined1 local_54 [32];
  LPCWSTR *local_34 [5];
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c26f;
  local_10 = ExceptionList;
  local_18 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xffffff40;
  ExceptionList = &local_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_88 = 0;
  FUN_10013050((undefined2 *)local_80,0x84);
  local_8._0_1_ = 2;
  puVar1 = (undefined4 *)FUN_10013140((undefined2 *)local_64,(int *)local_80);
  local_8._0_1_ = 3;
  FUN_10012890(local_80,puVar1);
  local_8._0_1_ = 2;
  FUN_100047c0(local_64);
  FUN_10013050((undefined2 *)local_34,0x79);
  local_8._0_1_ = 4;
  if (local_20 < 8) {
    local_34[0] = (LPCWSTR *)local_34;
  }
  if (local_6c < 8) {
    local_80[0] = (LPCWSTR *)local_80;
  }
  iVar2 = MessageBoxW(*(HWND *)(param_1 + 0x40),(LPCWSTR)local_80[0],(LPCWSTR)local_34[0],0x34);
  if (iVar2 == 6) {
    FUN_100108d0(local_54,'\x01',(LPCWSTR)0x7f02,'\x01');
    local_8 = CONCAT31(local_8._1_3_,5);
    local_88 = (**(code **)(**(int **)(param_1 + 0x150) + 0x20))();
    if (local_88 < 0) {
      local_88 = (**(code **)(**(int **)(param_1 + 0x150) + 0x24))();
      FUN_100181f0(param_1 + 0x144);
      UVar3 = 0x80;
    }
    else {
      FUN_100181f0(param_1 + 0x144);
      UVar3 = 0x89;
    }
    FUN_10017fc0((void *)(param_1 + 0x144),UVar3);
    local_8._0_1_ = 4;
    FUN_10010920((int)local_54);
  }
  local_8._0_1_ = 2;
  FUN_100047c0(local_34);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100047c0(local_80);
  local_8 = 0;
  if (local_88 < 0) {
    FUN_10012100((void *)(param_1 + 0x38),0);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100153f3 at 100153f3

undefined * Catch_100153f3(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0xa0);
  this = (int *)(*(int *)(unaff_EBP + -0x80) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x90);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return FUN_10015487;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x90),*(int *)(iVar1 + 4));
}



// Function: FUN_10015487 at 10015487

void FUN_10015487(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x84) < 0) {
    FUN_10012100((void *)(*(int *)(unaff_EBP - 0x80) + 0x38),0);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x90) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100154c8;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100154ce at 100154ce

undefined1 * Catch_100154ce(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *this;
  char *pcVar5;
  undefined4 uVar6;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x90);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x9c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    uVar1 = *(undefined4 *)(unaff_EBP + -0x84);
    this = (int *)(*(int *)(unaff_EBP + -0x80) + 4);
    uVar6 = 0x234;
    pcVar5 = "ImmobilizerInstallationPageImpl.cpp";
    uVar4 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),uVar1,uVar1,uVar4,(int *)pcVar5,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar3 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar3 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_100155a7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x90),*(int *)(*(int *)(unaff_EBP + -0x9c) + 4));
}



// Function: Catch@100155ac at 100155ac

undefined4 Catch_100155ac(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 10;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x90);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x84) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x8c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x8c) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x88));
      uVar3 = FUN_10015487();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x80) + 4);
  uVar5 = 0x234;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  std::exception::~exception((exception *)(unaff_EBP + -0xac));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100156ad;
}



// Function: Catch@100156b2 at 100156b2

undefined * Catch_100156b2(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x54),unaff_EBP + -0x90);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x54) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x84) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x8c) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x8c) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x88));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x80) + 4);
  uVar7 = 0x234;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_10015487;
}



// Function: FUN_100157b0 at 100157b0

void __fastcall FUN_100157b0(int param_1)

{
  HWND pHVar1;
  int iVar2;
  uint uStack_98;
  undefined4 local_5c;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001c2fc;
  local_10 = ExceptionList;
  uStack_98 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0x80004005;
  local_8 = 1;
  uStack_7 = 0;
  local_18 = uStack_98;
  Ordinal_42();
  local_5c = 0;
  _local_8 = CONCAT31(uStack_7,3);
  if (*(int *)(param_1 + 0x154) != 0) {
    Ordinal_30((int *)(param_1 + 0x154),0);
  }
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x40),0x72);
  iVar2 = Ordinal_47(pHVar1,&local_5c);
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_58,iVar2);
}



// Function: Catch@10015a22 at 10015a22

undefined * Catch_10015a22(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x78);
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10015ab3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
}



// Function: Catch@10015ab8 at 10015ab8

undefined * Catch_10015ab8(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -100) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
    uVar5 = 0x2dd;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
                 *(undefined4 *)(unaff_EBP + -0x48),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10015b7e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -100) + 4));
}



// Function: Catch@10015b83 at 10015b83

undefined4 Catch_10015b83(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_EBP;
  int *this;
  undefined4 uStack0000000c;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP - 4) = 8;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP - 0x74),unaff_EBP - 0x54);
    *(undefined1 *)(unaff_EBP - 4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    *(undefined ***)(unaff_EBP - 0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP - 0x50) == '\0') {
      *(undefined1 *)(unaff_EBP - 0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP - 0x4c));
      *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
      *(undefined ***)(unaff_EBP - 0x54) =
           CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
      ExceptionList = *(void **)(unaff_EBP - 0xc);
      uStack0000000c = 0x10015a1e;
      uVar3 = __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP - 0x5c) + 4);
  uVar5 = 0x2dd;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP - 0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP - 0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP - 0x34);
  if (*(uint *)(unaff_EBP - 0x20) < 8) {
    iVar2 = unaff_EBP - 0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP - 0x40),*(long *)(unaff_EBP - 0x3c),iVar2,
               *(wchar_t **)(unaff_EBP - 0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10004f30((undefined4 *)(unaff_EBP - 0x44));
  *(undefined1 *)(unaff_EBP - 4) = 4;
  std::exception::~exception((exception *)(unaff_EBP - 0x84));
  *(undefined4 *)(unaff_EBP - 4) = 0;
  return 0x10015c77;
}



// Function: Catch@10015c7c at 10015c7c

undefined1 * Catch_10015c7c(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x74),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x74) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined1 *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x5c) + 4);
  uVar7 = 0x2dd;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_100159f8;
}



// Function: FUN_10015d60 at 10015d60

void __thiscall FUN_10015d60(void *this,undefined4 param_1)

{
  LPCWSTR pWVar1;
  HDC pHVar2;
  HFONT pHVar3;
  HWND pHVar4;
  uint uVar5;
  HICON wParam;
  HFONT wParam_00;
  int iVar6;
  int iVar7;
  uint uStack_c8;
  undefined4 local_60;
  undefined **local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  void *local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c38d;
  local_10 = ExceptionList;
  uStack_c8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_c8;
  ExceptionList = &local_10;
  local_60 = *(undefined4 *)((int)this + 0x40);
                    /* WARNING: Load size is inaccurate */
  local_4c = this;
  local_18 = uStack_c8;
  pWVar1 = (LPCWSTR)(**(code **)(*this + 0x10))();
  FUN_100121f0(&local_60,pWVar1);
  iVar7 = 0x48;
  iVar6 = 0x5a;
  pHVar2 = GetDC((HWND)0x0);
  iVar6 = GetDeviceCaps(pHVar2,iVar6);
  iVar6 = MulDiv(0xc,iVar6,iVar7);
  pWVar1 = DAT_10033650;
  if (DAT_10033664 < 8) {
    pWVar1 = (LPCWSTR)&DAT_10033650;
  }
  pHVar3 = CreateFontW(-iVar6,0,0,0,700,0,0,0,1,0,0,0,0,pWVar1);
  *(HFONT *)((int)this + 0x134) = pHVar3;
  pHVar4 = GetDlgItem(*(HWND *)((int)this + 0x40),0x69);
  SendMessageW(pHVar4,0x30,(WPARAM)pHVar3,1);
  iVar7 = 0x48;
  iVar6 = 0x5a;
  pHVar2 = GetDC((HWND)0x0);
  iVar6 = GetDeviceCaps(pHVar2,iVar6);
  iVar6 = MulDiv(8,iVar6,iVar7);
  local_8 = 0;
  pWVar1 = DAT_10033650;
  if (DAT_10033664 < 8) {
    pWVar1 = (LPCWSTR)&DAT_10033650;
  }
  pHVar3 = CreateFontW(-iVar6,0,0,0,700,0,0,0,1,0,0,0,0,pWVar1);
  pHVar4 = GetDlgItem(*(HWND *)((int)this + 0x40),0x70);
  SendMessageW(pHVar4,0x30,(WPARAM)pHVar3,1);
  pHVar4 = GetDlgItem(*(HWND *)((int)this + 0x40),0x6f);
  *(HWND *)((int)this + 0x148) = pHVar4;
  pHVar4 = GetDlgItem(*(HWND *)((int)this + 0x40),0x6b);
  *(HWND *)((int)this + 0x140) = pHVar4;
  uVar5 = GetWindowLongW(pHVar4,-0x10);
  if (uVar5 != (uVar5 | 7)) {
    SetWindowLongW(*(HWND *)((int)this + 0x140),-0x10,uVar5 | 7);
  }
  pHVar4 = GetDlgItem(*(HWND *)((int)this + 0x40),0x6a);
  *(HWND *)((int)this + 0x13c) = pHVar4;
  uVar5 = GetWindowLongW(pHVar4,-0x10);
  if (uVar5 != (uVar5 | 3)) {
    SetWindowLongW(*(HWND *)((int)this + 0x13c),-0x10,uVar5 | 3);
  }
  wParam = LoadIconW(DAT_1003496c,(LPCWSTR)0x6c);
  SendMessageW(*(HWND *)((int)this + 0x13c),0x170,(WPARAM)wParam,0);
  FUN_100157b0((int)this);
  switch(param_1) {
  case 0:
    local_58 = 0;
    local_54 = 0;
    local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    local_50 = 0;
    local_60 = 0;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
    iVar6 = (**(code **)(**(int **)((int)this + 0x150) + 0x2c))
                      (*(int **)((int)this + 0x150),&local_60);
                    /* WARNING: Subroutine does not return */
    FUN_1000a090(&local_5c,iVar6);
  case 1:
    FUN_100181f0((int)this + 0x144);
    FUN_10017fc0((void *)((int)this + 0x144),0x7d);
    pHVar4 = *(HWND *)((int)this + 0x40);
    break;
  case 2:
    FUN_100181f0((int)this + 0x144);
    FUN_10017fc0((void *)((int)this + 0x144),0x8a);
    pHVar4 = *(HWND *)((int)this + 0x40);
    break;
  case 3:
    FUN_100181f0((int)this + 0x144);
    FUN_10017fc0((void *)((int)this + 0x144),0x8b);
    pHVar4 = *(HWND *)((int)this + 0x40);
    break;
  default:
    goto switchD_10015f32_default;
  }
  pHVar4 = GetDlgItem(pHVar4,0x67);
  EnableWindow(pHVar4,0);
switchD_10015f32_default:
  iVar7 = 0x48;
  iVar6 = 0x5a;
  pHVar2 = GetDC((HWND)0x0);
  iVar6 = GetDeviceCaps(pHVar2,iVar6);
  iVar6 = MulDiv(8,iVar6,iVar7);
  pWVar1 = DAT_10033650;
  if (DAT_10033664 < 8) {
    pWVar1 = (LPCWSTR)&DAT_10033650;
  }
  wParam_00 = CreateFontW(-iVar6,0,0,0,0,0,0,0,1,0,0,0,0,pWVar1);
  *(HFONT *)((int)this + 0x138) = wParam_00;
  SendMessageW(*(HWND *)((int)this + 0x148),0x30,(WPARAM)wParam_00,1);
  local_8 = 0xffffffff;
  if (pHVar3 != (HFONT)0x0) {
    DeleteObject(pHVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10015f82 at 10015f82

undefined * Catch_10015f82(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x68);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x78),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x78) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return FUN_10016010;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
}



// Function: FUN_10016010 at 10016010

void FUN_10016010(void)

{
  int iVar1;
  HWND pHVar2;
  HDC hdc;
  HFONT wParam;
  BOOL BVar3;
  LPCWSTR pszFaceName;
  uint unaff_EBP;
  bool bVar4;
  undefined4 uStack0000000c;
  int iVar5;
  int nDenominator;
  
  iVar1 = *(int *)(unaff_EBP - 0x48);
  if (-1 < *(int *)(unaff_EBP - 0x4c)) {
    if (*(short *)(unaff_EBP - 0x5c) == 0) {
      pHVar2 = GetDlgItem(*(HWND *)(iVar1 + 0x40),0x67);
      EnableWindow(pHVar2,0);
      FUN_100181f0(iVar1 + 0x144);
      FUN_10017fc0((void *)(iVar1 + 0x144),0x8c);
    }
    else {
      FUN_100181f0(iVar1 + 0x144);
      FUN_10017fc0((void *)(iVar1 + 0x144),0x87);
      bVar4 = *(int *)(iVar1 + 0x158) != 3;
      if (bVar4) {
        pHVar2 = GetDlgItem(*(HWND *)(iVar1 + 0x40),0x67);
      }
      else {
        pHVar2 = GetDlgItem(*(HWND *)(iVar1 + 0x40),0x67);
      }
      EnableWindow(pHVar2,(uint)bVar4);
    }
    FUN_10014c40(iVar1);
  }
  *(undefined1 *)(unaff_EBP - 4) = 0;
  *(undefined ***)(unaff_EBP - 0x58) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  nDenominator = 0x48;
  iVar5 = 0x5a;
  hdc = GetDC((HWND)0x0);
  iVar5 = GetDeviceCaps(hdc,iVar5);
  iVar5 = MulDiv(8,iVar5,nDenominator);
  pszFaceName = DAT_10033650;
  if (DAT_10033664 < 8) {
    pszFaceName = (LPCWSTR)&DAT_10033650;
  }
  wParam = CreateFontW(-iVar5,0,0,0,0,0,0,0,1,0,0,0,0,pszFaceName);
  *(HFONT *)(iVar1 + 0x138) = wParam;
  SendMessageW(*(HWND *)(iVar1 + 0x148),0x30,(WPARAM)wParam,1);
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(HGDIOBJ *)(unaff_EBP - 0x60) != (HGDIOBJ)0x0) {
    BVar3 = DeleteObject(*(HGDIOBJ *)(unaff_EBP - 0x60));
    if (BVar3 != 0) {
      *(undefined4 *)(unaff_EBP - 0x60) = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10016476;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1001605f at 1001605f

undefined1 * Catch_1001605f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x98),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -100) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x98) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
    uVar5 = 0x14b;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
                 *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    return &LAB_1001612b;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -100) + 4));
}



// Function: Catch@10016130 at 10016130

undefined4 Catch_10016130(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x88),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined ***)(unaff_EBP + -0x88) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      uVar3 = FUN_10016010();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
  uVar5 = 0x14b;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0xb4));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10016228;
}



// Function: Catch@1001622d at 1001622d

undefined * Catch_1001622d(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  HWND hWnd;
  HDC hdc;
  HFONT wParam;
  BOOL BVar4;
  undefined *puVar5;
  LPCWSTR *pszFaceName;
  uint unaff_EBP;
  int unaff_ESI;
  int *this;
  code *unaff_EDI;
  undefined4 uStack00000004;
  int nDenominator;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP - 0xa8),unaff_EBP - 0x58);
    *(undefined1 *)(unaff_EBP - 4) = 10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP - 4) = 3;
    *(undefined ***)(unaff_EBP - 0xa8) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP - 0x54) == '\0') {
      *(undefined1 *)(unaff_EBP - 0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP - 0x50));
      FUN_100181f0(unaff_ESI + 0x144);
      FUN_10017fc0((void *)(unaff_ESI + 0x144),0x87);
      bVar1 = *(int *)(unaff_ESI + 0x158) != 3;
      if (bVar1) {
        hWnd = (HWND)(*unaff_EDI)(*(undefined4 *)(unaff_ESI + 0x40),0x67);
      }
      else {
        hWnd = (HWND)(*unaff_EDI)(*(undefined4 *)(unaff_ESI + 0x40),0x67);
      }
      EnableWindow(hWnd,(uint)bVar1);
      FUN_10014c40(unaff_ESI);
      *(undefined1 *)(unaff_EBP - 4) = 0;
      *(undefined ***)(unaff_EBP - 0x58) =
           CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
      nDenominator = 0x48;
      iVar2 = 0x5a;
      hdc = GetDC((HWND)0x0);
      iVar2 = GetDeviceCaps(hdc,iVar2);
      iVar2 = MulDiv(8,iVar2,nDenominator);
      pszFaceName = (LPCWSTR *)DAT_10033650;
      if (DAT_10033664 < 8) {
        pszFaceName = &DAT_10033650;
      }
      wParam = CreateFontW(-iVar2,0,0,0,0,0,0,0,1,0,0,0,0,(LPCWSTR)pszFaceName);
      *(HFONT *)(unaff_ESI + 0x138) = wParam;
      SendMessageW(*(HWND *)(unaff_ESI + 0x148),0x30,(WPARAM)wParam,1);
      *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
      if (*(HGDIOBJ *)(unaff_EBP - 0x60) != (HGDIOBJ)0x0) {
        BVar4 = DeleteObject(*(HGDIOBJ *)(unaff_EBP - 0x60));
        if (BVar4 != 0) {
          *(undefined4 *)(unaff_EBP - 0x60) = 0;
        }
      }
      ExceptionList = *(void **)(unaff_EBP - 0xc);
      uStack00000004 = 0x10016476;
      puVar5 = (undefined *)__security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP - 0x48) + 4);
  uVar7 = 0x14b;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP - 0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP - 4) = 0xb;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP - 0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP - 0x34);
  if (*(uint *)(unaff_EBP - 0x20) < 8) {
    iVar2 = unaff_EBP - 0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP - 0x40),*(long *)(unaff_EBP - 0x3c),iVar2,
               *(wchar_t **)(unaff_EBP - 0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP - 4) = 3;
  FUN_10004f30((undefined4 *)(unaff_EBP - 0x44));
  *(undefined4 *)(unaff_EBP - 4) = 1;
  return FUN_10016010;
}



// Function: FUN_10016490 at 10016490

void __fastcall FUN_10016490(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puStack_98;
  undefined1 local_64 [8];
  undefined **local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001c414;
  local_10 = ExceptionList;
  puStack_98 = (undefined1 *)(DAT_100344b0 ^ (uint)&stack0xfffffffc);
  local_14 = (undefined1 *)&puStack_98;
  ExceptionList = &local_10;
  local_58 = 0;
  local_54 = 0;
  local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_50 = 0x80004005;
  local_8 = 1;
  uStack_7 = 0;
  puVar3 = param_1;
  local_4c = param_1;
  local_18 = puStack_98;
  FUN_10010830(&stack0xffffff64,param_1 + 0x25);
  _local_8 = CONCAT31(uStack_7,1);
  uVar1 = FUN_10016b40(puVar3);
  param_1[0x56] = uVar1;
  puStack_98 = (undefined1 *)0x10016510;
  FUN_10013250((int)param_1);
  puStack_98 = local_64;
  iVar2 = (**(code **)(*(int *)param_1[0x54] + 0x1c))();
                    /* WARNING: Subroutine does not return */
  FUN_1000a090(&local_5c,iVar2);
}



// Function: Catch@1001655b at 1001655b

undefined * Catch_1001655b(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x74);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
  FUN_1000c060(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000c5b0(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000d180(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000bdf0((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000a540((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return FUN_100165ec;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
}



// Function: FUN_100165ec at 100165ec

void FUN_100165ec(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x4c) < 0) {
    FUN_10015d60(*(void **)(unaff_EBP - 0x48),1);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x58) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10016629;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1001662f at 1001662f

undefined1 * Catch_1001662f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
    this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
    uVar5 = 0xfc;
    pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
    uVar3 = (**(code **)(*this + 4))();
    FUN_10009440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
                 *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(int *)pcVar4,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
    FUN_1000c5b0(this);
    iVar2 = *(int *)(unaff_EBP + -0x34);
    if (*(uint *)(unaff_EBP + -0x20) < 8) {
      iVar2 = unaff_EBP + -0x34;
    }
    FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
                 *(wchar_t **)(unaff_EBP + -0x18));
    FUN_1000bdf0((int)this);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &LAB_100166f2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a090((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -0x5c) + 4));
}



// Function: Catch@100166f7 at 100166f7

undefined4 Catch_100166f7(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  bVar1 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_1000a540((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      uVar3 = FUN_100165ec();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
  uVar5 = 0xfc;
  pcVar4 = "ImmobilizerInstallationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0x84));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100167e9;
}



// Function: Catch@100167ee at 100167ee

undefined * Catch_100167ee(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000a540((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_1000ce30(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + 4);
  uVar7 = 0xfc;
  pcVar6 = "ImmobilizerInstallationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10009440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_1000c060(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000c5b0(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_1000d180(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000bdf0((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_100165ec;
}



// Function: FUN_100168d0 at 100168d0

void __cdecl FUN_100168d0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10016900 at 10016900

void __fastcall FUN_10016900(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}



// Function: FUN_10016930 at 10016930

int * __cdecl FUN_10016930(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c459;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2,DAT_100344b0 ^ (uint)&stack0xfffffffc,0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100011a0(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100169b0 at 100169b0

void __cdecl FUN_100169b0(wchar_t *param_1)

{
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(wchar_t **)param_1;
  }
  _wtol(param_1);
  return;
}



// Function: FUN_100169d0 at 100169d0

void __cdecl FUN_100169d0(void *param_1,ushort *param_2,undefined4 *param_3)

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
  for (uVar3 = FUN_100035e0(param_1,puVar7,0,(int)puVar5 - (int)(puVar7 + 1) >> 1);
      uVar3 != 0xffffffff;
      uVar3 = FUN_100035e0(param_1,puVar5,param_3[4] + uVar3,(int)puVar7 - (int)(puVar5 + 1) >> 1))
  {
    piVar4 = FUN_10001470(param_3);
    piVar6 = piVar4;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar2 != 0);
    FUN_100060f0(param_1,uVar3,*(int **)(param_2 + 8),piVar4,(int)piVar6 - ((int)piVar4 + 2) >> 1);
    puVar5 = (ushort *)FUN_10001470((undefined4 *)param_2);
    puVar7 = puVar5;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != 0);
  }
  return;
}



// Function: FUN_10016a90 at 10016a90

undefined2 * __cdecl FUN_10016a90(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c499;
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
  FUN_100057e0(param_1,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016b40 at 10016b40

void FUN_10016b40(undefined4 *param_1)

{
  uint3 uVar1;
  uint *puVar2;
  uint uStack_54;
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c4e8;
  local_10 = ExceptionList;
  uStack_54 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  puVar2 = &uStack_54;
  if (param_1 != (undefined4 *)0x0) {
    FUN_1000f450(&local_28,param_1);
    uVar1 = local_8._1_3_;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_24 != (int *)0x0) {
      local_30 = 7;
      local_34 = 0;
      local_44[0] = 0;
      local_8._0_1_ = 3;
      local_8._1_3_ = uVar1;
      FUN_1000fa40(&local_20,local_24,(undefined4 *)local_44);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_100047c0((undefined4 *)local_44);
      if (local_1c != 0) {
        local_18 = FUN_1000fbf0((int)&local_20);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_1000aaa0(&local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_1000aa20(&local_28);
    puVar2 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar2;
  local_8 = 0;
  FUN_10016c03();
  return;
}



// Function: Catch@10016bf1 at 10016bf1

undefined * Catch_10016bf1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10016bfe;
}



// Function: FUN_10016c03 at 10016c03

void FUN_10016c03(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 8);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10016c30 at 10016c30

void __fastcall FUN_10016c30(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10016c40 at 10016c40

void __fastcall FUN_10016c40(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c518;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100344b0 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016c90 at 10016c90

void __thiscall FUN_10016c90(void *this,undefined4 param_1)

{
  undefined2 *puStack0000000c;
  undefined2 local_28 [10];
  uint uStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c548;
  local_10 = ExceptionList;
  uStack_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack0000000c = local_28;
  local_28[0] = 3;
                    /* WARNING: Load size is inaccurate */
  local_8 = 0xffffffff;
  (**(code **)(*this + 4))(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016d00 at 10016d00

void __thiscall FUN_10016d00(void *this,undefined4 param_1,int param_2,undefined2 *param_3)

{
  undefined2 local_2c [8];
  undefined2 *puStack_1c;
  uint uStack_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001c580;
  local_10 = ExceptionList;
  uStack_18 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  puStack_1c = param_3;
  param_3 = local_2c;
  local_2c[0] = 0;
  FUN_1000a9b0(local_2c,&param_2);
                    /* WARNING: Load size is inaccurate */
  local_8 = local_8 & 0xffffff00;
  (**(code **)(*this + 4))(param_1);
  local_8 = 0xffffffff;
  Ordinal_6(param_2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016d80 at 10016d80

void __fastcall FUN_10016d80(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c633;
  local_10 = ExceptionList;
  uVar3 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ECMParameter2::vftable;
  local_8._0_1_ = 5;
  local_8._1_3_ = 0;
  piVar1 = (int *)param_1[10];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
  }
  local_8._0_1_ = 4;
  piVar1 = (int *)param_1[9];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 3;
  piVar1 = (int *)param_1[8];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 2;
  piVar1 = (int *)param_1[7];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 1;
  Ordinal_6(param_1[6]);
  param_1[4] = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
               ::vftable;
  local_8._0_1_ = 0xb;
  piVar1 = param_1 + 5;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = (int *)*piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1[2] = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
               ::vftable;
  local_8 = 0xd;
  piVar1 = param_1 + 3;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)*piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016ed0 at 10016ed0

undefined4 * __thiscall FUN_10016ed0(void *this,byte param_1)

{
  FUN_10016d80((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016f00 at 10016f00

undefined4 __thiscall FUN_10016f00(void *this,undefined4 param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c671;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  Ordinal_8(param_1,DAT_100344b0 ^ (uint)&stack0xfffffffc);
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),param_1);
    if (iVar1 < 0) {
      FUN_1000ce30(iVar1,0);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016fb0 at 10016fb0

void __thiscall FUN_10016fb0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *this_00;
  wchar_t *pwVar3;
  undefined4 uVar4;
  int **local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  undefined **local_38;
  int *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c738;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(**(int **)((int)this + 0x1c) + 0x28))
                    (*(int **)((int)this + 0x1c),&local_40,local_14);
  if (-1 < iVar2) {
    this_00 = FUN_1000f830((void *)((int)this + 0x10),&local_38);
    local_8._0_1_ = 3;
    pwVar3 = FUN_1000f6c0(this_00,(undefined2 *)local_30);
    local_8._0_1_ = 4;
    uVar4 = FUN_100169b0(pwVar3);
    local_8._0_1_ = 3;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    piVar1 = local_34;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    local_38 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
               ::vftable;
    local_8._0_1_ = 5;
    if (local_34 != (int *)0x0) {
      local_34 = (int *)0x0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    local_4c = &local_34;
    local_8._0_1_ = 2;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
    local_3c = (int *)0x0;
    local_8._0_1_ = 8;
    iVar2 = (**(code **)(*local_40 + 0x24))(local_40,uVar4,&local_3c);
    if (-1 < iVar2) {
      local_34 = (int *)0x0;
      local_8._0_1_ = 10;
      iVar2 = (**(code **)(*local_3c + 0x38))(local_3c,&local_34);
      if (-1 < iVar2) {
        local_44 = (int *)0x0;
        local_8._0_1_ = 0xc;
        iVar2 = (**(code **)(*local_34 + 0x20))(local_34,0,&local_44);
        if (-1 < iVar2) {
          local_48 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xe);
          iVar2 = (**(code **)(*local_44 + 0x30))(local_44,0,&local_48);
          if (-1 < iVar2) {
            iVar2 = (**(code **)(*local_48 + 0x40))(local_48,&local_4c);
            if (-1 < iVar2) {
              if ((local_4c == (int **)0x4) || (local_4c == (int **)0x5)) {
                *(undefined1 *)((int)this + 4) = 0;
              }
              else {
                *(undefined1 *)((int)this + 4) = 1;
              }
            }
          }
          local_8._0_1_ = 0xc;
          if (local_48 != (int *)0x0) {
            (**(code **)(*local_48 + 8))(local_48);
          }
        }
        local_8._0_1_ = 10;
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 8))(local_44);
        }
      }
      local_8._0_1_ = 8;
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
    }
    local_8._0_1_ = 2;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100171c0 at 100171c0

undefined2 * __thiscall FUN_100171c0(void *this,undefined2 *param_1)

{
  uint uVar1;
  undefined1 local_34 [8];
  int *local_2c;
  undefined **local_24;
  undefined1 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c789;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_18 = 0x80004005;
  local_8 = 1;
  FUN_10016f00(this,local_34);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = FUN_100168d0(8,(int)local_34,0,0x409);
  if (local_18 < 0) {
    local_20 = 1;
    FUN_1000ce30(local_18,0);
  }
  FUN_10016a90(param_1,local_2c);
  local_14 = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_9(local_34,uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017280 at 10017280

undefined4 __fastcall FUN_10017280(void *param_1)

{
  uint uVar1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined **local_20;
  undefined1 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001c7c0;
  local_10 = ExceptionList;
  uVar1 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_1c = 0;
  local_20 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_14 = 0x80004005;
  local_8 = 0;
  FUN_10016f00(param_1,local_30);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_14 = FUN_100168d0(3,(int)local_30,0,0x409);
  if (local_14 < 0) {
    local_1c = 1;
    FUN_1000ce30(local_14,0);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_30,uVar1);
  ExceptionList = local_10;
  return local_28;
}



// Function: FUN_10017330 at 10017330

void __thiscall FUN_10017330(void *this,undefined4 *param_1)

{
  int **ppiVar1;
  undefined4 *puVar2;
  wchar_t *pwVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_60;
  undefined4 local_50;
  uint local_4c;
  undefined **local_44;
  int *local_40;
  undefined **local_3c;
  int *local_38;
  int **local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c8b8;
  local_10 = ExceptionList;
  local_14 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ECMParameter2::vftable;
  *(undefined1 *)((int)this + 4) = 0;
  FUN_1000f450((void *)((int)this + 8),param_1);
  local_38 = (int *)((int)this + 0x14);
  *local_38 = 0;
  *(undefined ***)((int)this + 0x10) =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  *local_38 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  piVar5 = (int *)((int)this + 0x1c);
  *piVar5 = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  local_34 = (int **)((int)this + 0x28);
  *local_34 = (int *)0x0;
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_8._1_3_ = 0;
  local_4c = 7;
  local_50 = 0;
  local_60 = (void *)((uint)local_60._2_2_ << 0x10);
  local_8._0_1_ = 0xe;
  puVar2 = FUN_1000f500(&local_3c,*(int **)((int)this + 0xc),&local_60,&local_30);
  local_8._0_1_ = 0xf;
  if (puVar2 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = puVar2 + 1;
  }
  if (*(int *)((int)this + 0x14) != *piVar4) {
    Ordinal_30();
  }
  piVar4 = local_38;
  local_3c = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 0x10;
  if (local_38 != (int *)0x0) {
    local_38 = (int *)0x0;
    (**(code **)(*piVar4 + 8))();
  }
  local_34 = &local_38;
  local_8._0_1_ = 0xe;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  local_8._0_1_ = 0xd;
  if (7 < local_4c) {
    operator_delete(local_60);
  }
  local_4c = 7;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffff0000);
  local_8._0_1_ = 0xc;
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  (**(code **)**(undefined4 **)((int)this + 0xc))();
  (**(code **)(*(int *)*piVar5 + 0x24))();
  local_38 = *(int **)((int)this + 0x20);
  puVar2 = FUN_1000f830((void *)((int)this + 0x10),&local_44);
  local_8._0_1_ = 0x12;
  pwVar3 = FUN_1000f6c0(puVar2,(undefined2 *)&local_30);
  local_8._0_1_ = 0x13;
  local_34 = (int **)(*local_38 + 0x24);
  FUN_100169b0(pwVar3);
  (*(code *)*local_34)();
  local_8._0_1_ = 0x12;
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  piVar4 = local_40;
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  local_44 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 0x14;
  if (local_40 != (int *)0x0) {
    local_40 = (int *)0x0;
    (**(code **)(*piVar4 + 8))();
  }
  local_34 = &local_40;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))();
  }
  (**(code **)**(undefined4 **)((int)this + 0x28))();
  piVar5 = (int *)*piVar5;
  local_34 = (int **)&stack0xffffff5c;
  local_38 = (int *)&stack0xffffff5c;
  piVar4 = (int *)&stack0xffffff5c;
  ppiVar1 = (int **)&stack0xffffff5c;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))(piVar5);
    piVar4 = local_38;
    ppiVar1 = local_34;
  }
  local_34 = ppiVar1;
  local_38 = piVar4;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),0xc);
  FUN_10016fb0(this,piVar5);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100175e0 at 100175e0

void __thiscall FUN_100175e0(void *this,int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined **local_38;
  int *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c900;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
  local_8 = 0;
  puVar4 = FUN_1000f900((void *)((int)this + 0x10),&local_38,local_30);
  local_8._0_1_ = 1;
  uVar5 = FUN_10017280(puVar4);
  piVar3 = local_34;
  *param_2 = uVar5;
  local_38 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 2;
  if (local_34 != (int *)0x0) {
    local_34 = (int *)0x0;
    (**(code **)(*piVar3 + 8))(piVar3,uVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
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



// Function: FUN_100176f0 at 100176f0

void __thiscall FUN_100176f0(void *this,int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_58;
  undefined **local_54;
  int *local_50;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c960;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
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
  FUN_100057e0(local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
  local_8 = 0;
  puVar4 = FUN_1000f900((void *)((int)this + 0x10),&local_54,local_30);
  local_8._0_1_ = 1;
  puVar4 = (undefined4 *)FUN_100171c0(puVar4,(undefined2 *)local_4c);
  local_8._0_1_ = 2;
  piVar3 = FUN_10016930(&local_58,puVar4);
  local_8._0_1_ = 3;
  if (*param_2 != *piVar3) {
    Ordinal_6(*param_2,uVar2);
    *param_2 = *piVar3;
    *piVar3 = 0;
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_58);
  local_8._0_1_ = 1;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  piVar3 = local_50;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_54 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 4;
  if (local_50 != (int *)0x0) {
    local_50 = (int *)0x0;
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))(local_50);
  }
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



// Function: FUN_10017860 at 10017860

void __fastcall FUN_10017860(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c9a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100176f0(param_1,(int *)PTR_DAT_10033fac,param_1 + 6);
  local_14 = 0;
  local_8 = 0;
  FUN_100176f0(param_1,(int *)PTR_DAT_10033fb0,&local_14);
  iVar3 = local_14;
  iVar1 = Ordinal_314();
  if (iVar1 != 1) {
    if (iVar3 != 0) {
      uVar2 = Ordinal_149(iVar3);
      iVar3 = Ordinal_150(iVar3,uVar2);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
    }
    local_8 = local_8 & 0xffffff00;
    (**(code **)(*param_1 + 0xc))(PTR_DAT_10033fac);
  }
  local_8 = 0xffffffff;
  Ordinal_6();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017940 at 10017940

void __fastcall FUN_10017940(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001c9d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_8 = 0;
  FUN_100176f0(param_1,(int *)PTR_DAT_10033fb0,&local_14);
  iVar1 = Ordinal_314();
  if (iVar1 != 1) {
    iVar1 = Ordinal_7();
    if (iVar1 != 0) {
      iVar1 = param_1[6];
      if (iVar1 != 0) {
        uVar2 = Ordinal_149(iVar1);
        iVar1 = Ordinal_150(param_1[6],uVar2);
      }
      if ((param_1[6] != 0) && (iVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_100011a0(0x8007000e);
      }
      local_8 = local_8 & 0xffffff00;
      (**(code **)(*param_1 + 0xc))(PTR_DAT_10033fac);
    }
  }
  local_8 = 0xffffffff;
  Ordinal_6();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017a30 at 10017a30

void __thiscall FUN_10017a30(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int **ppiVar5;
  uint uStack_5c;
  undefined1 local_4c [8];
  undefined4 local_44;
  undefined4 local_3c;
  int *local_38;
  wchar_t local_34 [14];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ca08;
  local_10 = ExceptionList;
  uStack_5c = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_5c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_5c;
  if (*(char *)((int)this + 4) == '\0') {
    local_38 = (int *)0x0;
    local_8._1_3_ = 0;
    local_8._0_1_ = 2;
    local_14 = (undefined1 *)&uStack_5c;
    FUN_10007330(local_34,param_1);
    local_8._0_1_ = 3;
    piVar1 = *(int **)((int)this + 0x24);
    iVar2 = *piVar1;
    ppiVar5 = &local_38;
    uVar4 = 1;
    uVar3 = FUN_100169b0(local_34);
    (**(code **)(iVar2 + 0x2c))(piVar1,uVar3,uVar4,ppiVar5);
    local_8._0_1_ = 2;
    FUN_100047c0((undefined4 *)local_34);
    (**(code **)(*local_38 + 0x30))(local_38,local_4c);
    FUN_100168d0(3,(int)local_4c,0,0x409);
    *param_2 = local_44;
    local_3c = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10016c40((int *)&local_38);
    local_8 = 0xffffffff;
    FUN_10017b27();
    return;
  }
  FUN_100175e0(this,param_1,param_2);
  local_8 = 0xffffffff;
  FUN_10017b27();
  return;
}



// Function: Catch@10017b10 at 10017b10

undefined * Catch_10017b10(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x38) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10017b24;
}



// Function: FUN_10017b27 at 10017b27

void FUN_10017b27(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10017b41;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10017b50 at 10017b50

void __thiscall FUN_10017b50(void *this,int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char in_stack_00000018;
  undefined **local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ca50;
  local_10 = ExceptionList;
  uVar2 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = uVar2;
  if (in_stack_00000018 != '\0') {
    FUN_10017860((int *)this);
  }
  local_30 = (void *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  piVar3 = param_1;
  do {
    iVar1 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 2);
  } while ((short)iVar1 != 0);
  FUN_100057e0(&local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
  local_8._0_1_ = 1;
  FUN_10010500((void *)((int)this + 0x10),&local_38,&local_30,(undefined4 *)&stack0x00000008);
  piVar3 = local_34;
  local_38 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 2;
  if (local_34 != (int *)0x0) {
    local_34 = (int *)0x0;
    (**(code **)(*piVar3 + 8))(piVar3,uVar2);
  }
  local_8._0_1_ = 1;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_1c) {
    operator_delete(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffff0000);
  if (in_stack_00000018 != '\0') {
    FUN_10017940((int *)this);
  }
  local_8 = 0xffffffff;
  Ordinal_9(&stack0x00000008);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017c80 at 10017c80

int __thiscall FUN_10017c80(void *this,int param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  uint _Size;
  int iVar2;
  
  iVar1 = param_1 + param_3;
  iVar2 = 1;
  if ((iVar1 < param_1) || (iVar1 < param_3)) {
    return 0;
  }
  if ((iVar1 != 0) && (iVar2 = FUN_10010db0(this,iVar1), iVar2 != 0)) {
    _Size = param_1 * 2;
    if (_Size <= iVar1 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
      memcpy(*this,param_2,_Size);
    }
    if ((uint)(param_3 * 2) <= (iVar1 - param_1) * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
      memcpy((void *)(*this + _Size),param_4,param_3 * 2);
      return iVar2;
    }
  }
  return iVar2;
}



// Function: FUN_10017d20 at 10017d20

void __thiscall FUN_10017d20(void *this,int param_1,void *param_2)

{
  LONG *lpAddend;
  void *pvVar1;
  int iVar2;
  LONG LVar3;
  
  if (param_1 != 0) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    lpAddend = (LONG *)((int)pvVar1 + -0xc);
    if ((*(int *)((int)pvVar1 + -0xc) < 2) &&
       (*(int *)((int)pvVar1 + -8) + param_1 <= *(int *)((int)pvVar1 + -4))) {
      if ((uint)(param_1 * 2) <= *(int *)((int)pvVar1 + -4) * 2 + 2U) {
        memcpy((void *)((int)pvVar1 + *(int *)((int)pvVar1 + -8) * 2),param_2,param_1 * 2);
      }
                    /* WARNING: Load size is inaccurate */
      *(int *)(*this + -8) = *(int *)(*this + -8) + param_1;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + *(int *)(*this + -8) * 2) = 0;
      return;
    }
    iVar2 = FUN_10017c80(this,*(int *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
    if (((iVar2 != 0) && (lpAddend != DAT_100319ac)) &&
       (LVar3 = InterlockedDecrement(lpAddend), LVar3 < 1)) {
      operator_delete__(lpAddend);
    }
  }
  return;
}



// Function: FUN_10017dc0 at 10017dc0

void __fastcall FUN_10017dc0(undefined4 *param_1)

{
  LONG LVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca8b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CStatusBox::vftable;
  local_8 = 0xffffffff;
  if (param_1[2] + -0xc != DAT_100319ac) {
    LVar1 = InterlockedDecrement((LONG *)(param_1[2] + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(param_1[2] + -0xc));
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017e40 at 10017e40

undefined4 * __thiscall FUN_10017e40(void *this,byte param_1)

{
  LONG LVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca8b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CStatusBox::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 8) + -0xc != DAT_100319ac) {
    LVar1 = InterlockedDecrement((LONG *)(*(int *)((int)this + 8) + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*(int *)((int)this + 8) + -0xc));
    }
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10017ed0 at 10017ed0

void __thiscall FUN_10017ed0(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR lpBuffer;
  int iVar2;
  int cchBufferMax;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_100344b0 ^ (uint)&stack0xfffffffc;
  iVar1 = LoadStringW(DAT_1003496c,param_1,local_208,0x100);
  if (iVar1 == 0) {
    local_208[0] = L'\0';
  }
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      cchBufferMax = iVar1 + 0x100;
      lpBuffer = (LPWSTR)FUN_100113e0(this,iVar1 + 0xff);
      if (lpBuffer == (LPWSTR)0x0) break;
      iVar2 = LoadStringW(DAT_1003496c,param_1,lpBuffer,cchBufferMax);
      if (iVar2 == 0) {
        *lpBuffer = L'\0';
      }
      iVar1 = cchBufferMax;
    } while (cchBufferMax - iVar2 < 2);
    FUN_10011690((int *)this);
                    /* WARNING: Load size is inaccurate */
    iVar1 = lstrlenW(*this);
                    /* WARNING: Load size is inaccurate */
    *(int *)(*this + -8) = iVar1;
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)(*this + iVar1 * 2) = 0;
  }
  else {
    iVar1 = lstrlenW(local_208);
    FUN_10012040(this,iVar1,local_208);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017fc0 at 10017fc0

undefined4 __thiscall FUN_10017fc0(void *this,UINT param_1)

{
  LONG *lpAddend;
  undefined *puVar1;
  int iVar2;
  LRESULT LVar3;
  LRESULT LVar4;
  LONG LVar5;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cab8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = PTR_DAT_100319b0;
  local_8 = 0;
  FUN_10017ed0(&local_14,param_1);
  iVar2 = lstrlenW(L"\r\n");
  FUN_10017d20(&local_14,iVar2,&DAT_100282b0);
  puVar1 = local_14;
  FUN_10017d20((void *)((int)this + 8),*(int *)(local_14 + -8),local_14);
  SetWindowTextW(*(HWND *)((int)this + 4),*(LPCWSTR *)((int)this + 8));
  LVar3 = SendMessageW(*(HWND *)((int)this + 4),0xba,0,0);
  LVar4 = SendMessageW(*(HWND *)((int)this + 4),0xce,0,0);
  SendMessageW(*(HWND *)((int)this + 4),0xb6,0,LVar3 - LVar4);
  local_8 = 0xffffffff;
  if (puVar1 + -0xc != DAT_100319ac) {
    lpAddend = (LONG *)(puVar1 + -0xc);
    LVar5 = InterlockedDecrement(lpAddend);
    if (LVar5 < 1) {
      operator_delete__(lpAddend);
    }
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_100180c0 at 100180c0

undefined4 * __thiscall FUN_100180c0(void *this,LPCWSTR param_1)

{
  uint _Size;
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_100319b0;
  if (param_1 != (LPCWSTR)0x0) {
    if ((uint)param_1 >> 0x10 == 0) {
      FUN_10017ed0(this,(uint)param_1 & 0xffff);
      return (undefined4 *)this;
    }
    iVar1 = lstrlenW(param_1);
    if (((iVar1 != 0) && (iVar2 = FUN_10010db0(this,iVar1), iVar2 != 0)) &&
       (_Size = iVar1 * 2, _Size <= _Size + 2)) {
                    /* WARNING: Load size is inaccurate */
      memcpy(*this,param_1,_Size);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10018130 at 10018130

void __fastcall FUN_10018130(int *param_1)

{
  LONG LVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + -8) != 0) {
    if (*(int *)(iVar2 + -0xc) < 0) {
      iVar2 = lstrlenW(L"");
      FUN_10012040(param_1,iVar2,&DAT_10026808);
    }
    else if (iVar2 + -0xc != DAT_100319ac) {
      LVar1 = InterlockedDecrement((LONG *)(iVar2 + -0xc));
      if (LVar1 < 1) {
        operator_delete__((void *)(*param_1 + -0xc));
      }
      *param_1 = (int)PTR_DAT_100319b0;
      return;
    }
  }
  return;
}



// Function: FUN_10018190 at 10018190

undefined4 * __fastcall FUN_10018190(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ca8b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0;
  *param_1 = CStatusBox::vftable;
  FUN_100180c0(param_1 + 2,L"");
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100181f0 at 100181f0

void __fastcall FUN_100181f0(int param_1)

{
  LRESULT LVar1;
  LRESULT LVar2;
  
  FUN_10018130((int *)(param_1 + 8));
  SetWindowTextW(*(HWND *)(param_1 + 4),*(LPCWSTR *)(param_1 + 8));
  LVar1 = SendMessageW(*(HWND *)(param_1 + 4),0xba,0,0);
  LVar2 = SendMessageW(*(HWND *)(param_1 + 4),0xce,0,0);
  SendMessageW(*(HWND *)(param_1 + 4),0xb6,0,LVar1 - LVar2);
  return;
}



// Function: __security_check_cookie at 100182a6

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100344b0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 100182b5

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



// Function: `eh_vector_constructor_iterator' at 1001833e

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
  FUN_1001838b();
  return;
}



// Function: FUN_1001838b at 1001838b

void FUN_1001838b(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 100183a3

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



// Function: `eh_vector_destructor_iterator' at 10018401

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
  FUN_1001844c();
  return;
}



// Function: FUN_1001844c at 1001844c

void FUN_1001844c(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 10018464

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
  
  local_8 = &DAT_1002e3c0;
  uStack_c = 0x10018470;
  local_20[0] = DecodePointer(DAT_100349e8);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_100349e8);
    local_24 = DecodePointer(DAT_100349e4);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_100349e8 = EncodePointer(local_20[0]);
    DAT_100349e4 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100184fc();
  }
  return p_Var1;
}



// Function: FUN_100184fc at 100184fc

void FUN_100184fc(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10018505

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_100185db at 100185db

void __cdecl
FUN_100185db(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_100344b0,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10018600

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



// Function: __alloca_probe_8 at 10018616

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



// Function: __CRT_INIT@12 at 1001867a

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
    if (DAT_1003460c < 1) {
      return 0;
    }
    DAT_1003460c = DAT_1003460c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100349d8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100349d4 == 2) {
      param_2 = (int *)DecodePointer(DAT_100349e8);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_100349e4);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_100349e8);
            piVar8 = (int *)DecodePointer(DAT_100349e4);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_100349e4 = (PVOID)encoded_null();
        DAT_100349e8 = DAT_100349e4;
      }
      DAT_100349d4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_100349d8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100349d8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100349d4 == 0) {
      DAT_100349d4 = 1;
      iVar5 = initterm_e(&DAT_10025948,&DAT_10025954);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10025464,&DAT_10025944);
      DAT_100349d4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_100349d8,0);
    }
    if ((DAT_100349e0 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100349e0), BVar2 != 0)) {
      (*DAT_100349e0)(param_1,2,param_3);
    }
    DAT_1003460c = DAT_1003460c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10018884

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10018924) */
/* WARNING: Removing unreachable block (ram,0x100188d1) */
/* WARNING: Removing unreachable block (ram,0x10018951) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_100344d0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1003460c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_100013b0(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_100013b0(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1001898f();
  return local_20;
}



// Function: FUN_1001898f at 1001898f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001898f(void)

{
  _DAT_100344d0 = 0xffffffff;
  return;
}



// Function: entry at 1001899a

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 100189bd

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
  
  _DAT_10034728 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1003472c = &stack0x00000004;
  _DAT_10034668 = 0x10001;
  _DAT_10034610 = 0xc0000409;
  _DAT_10034614 = 1;
  local_32c = DAT_100344b0;
  local_328 = DAT_100344b4;
  _DAT_1003461c = unaff_retaddr;
  _DAT_100346f4 = in_GS;
  _DAT_100346f8 = in_FS;
  _DAT_100346fc = in_ES;
  _DAT_10034700 = in_DS;
  _DAT_10034704 = unaff_EDI;
  _DAT_10034708 = unaff_ESI;
  _DAT_1003470c = unaff_EBX;
  _DAT_10034710 = in_EDX;
  _DAT_10034714 = in_ECX;
  _DAT_10034718 = in_EAX;
  _DAT_1003471c = unaff_EBP;
  DAT_10034720 = unaff_retaddr;
  _DAT_10034724 = in_CS;
  _DAT_10034730 = in_SS;
  DAT_10034660 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_100283e8);
  if (DAT_10034660 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10018ad0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100344b0 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10018b15

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



// Function: __alloca_probe at 10018b60

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



// Function: __ValidateImageBase at 10018bf0

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



// Function: __FindPESection at 10018c30

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



// Function: __IsNonwritableInCurrentImage at 10018c80

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
  
  pcStack_10 = FUN_100185db;
  local_14 = ExceptionList;
  local_c = DAT_100344b0 ^ 0x1002e408;
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



// Function: ___security_init_cookie at 10018d54

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
  if ((DAT_100344b0 == 0xbb40e64e) || ((DAT_100344b0 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_100344b0 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_100344b0 == 0xbb40e64e) {
      DAT_100344b0 = 0xbb40e64f;
    }
    else if ((DAT_100344b0 & 0xffff0000) == 0) {
      DAT_100344b0 = DAT_100344b0 | (DAT_100344b0 | 0x4711) << 0x10;
    }
    DAT_100344b4 = ~DAT_100344b0;
  }
  else {
    DAT_100344b4 = ~DAT_100344b0;
  }
  return;
}



// Function: FUN_10018e02 at 10018e02

void __fastcall FUN_10018e02(int *param_1)

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



// Function: FUN_10018e46 at 10018e46

int __fastcall FUN_10018e46(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10018e5f at 10018e5f

undefined4 * __fastcall FUN_10018e5f(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10018e46((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1002e488;
  param_1[3] = &DAT_1002e488;
  uVar1 = FUN_100011c0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_10034504 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10018ea0 at 10018ea0

void __fastcall FUN_10018ea0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10018ebf at 10018ebf

int __fastcall FUN_10018ebf(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10018ee4 at 10018ee4

void __fastcall FUN_10018ee4(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10018ea0((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 10018efc

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
LAB_10018f4a:
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
        goto LAB_10018f4a;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_10018f59 at 10018f59

undefined4 * __fastcall FUN_10018f59(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10018ebf((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10028410;
  uVar1 = FUN_100011c0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_10034504 = 1;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 10018f99

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
    uVar1 = FUN_100011c0((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar1;
}



// Function: FUN_10018fc1 at 10018fc1

int __fastcall FUN_10018fc1(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 10018fe6

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_10018ff3:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_10018ff3;
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
      FUN_10016900((undefined4 *)(param_1 + 0x20));
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      *(undefined4 *)param_1 = 0;
    }
    lVar2 = 0;
  }
  return lVar2;
}



// Function: FUN_1001905c at 1001905c

_ATL_WIN_MODULE70 * __fastcall FUN_1001905c(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_10018fc1((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_10034504 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 10019084

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_100349c8 == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_100349c8,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 100190b0

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
    DAT_100349c8 = 1;
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
  DAT_100349c8 = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 1001911e

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 10019130

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
  
  if ((DAT_100349c8 != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_100349c8 == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_100349c8);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_100349c8);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_100349c8,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: FUN_100191e0 at 100191e0

void FUN_100191e0(undefined4 param_1)

{
  (*(code *)PTR_FUN_100344d8)(param_1,0);
  return;
}



// Function: FUN_10019230 at 10019230

void FUN_10019230(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__10028420;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1002e424);
}



// Function: _com_error at 10019270

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10028420;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 100192b0

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10028420;
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



// Function: FUN_100192f1 at 100192f1

void __fastcall FUN_100192f1(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: Facet_Register at 10019307

/* Library Function - Multiple Matches With Same Base Name
    private: static void __cdecl std::locale::facet::_Facet_Register(class std::locale::facet *)
    void __cdecl std::_Facet_Register(class std::_Facet_base *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __cdecl Facet_Register(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = DAT_100349cc;
    puVar1[1] = param_1;
  }
  DAT_100349cc = puVar1;
  return;
}



// Function: FUN_10019331 at 10019331

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10019331(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  FUN_100193b8(4);
  std::_Lockit::_Lockit((_Lockit *)(unaff_EBP + -0x10),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (puVar1 = DAT_100349cc, DAT_100349cc != (undefined4 *)0x0) {
    DAT_100349cc = (undefined4 *)*DAT_100349cc;
    FUN_100192f1((int)puVar1);
    operator_delete(puVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_100193b8 at 100193b8

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */

void __cdecl FUN_100193b8(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100344b0 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100193eb

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



// Function: Unwind@10019400 at 10019400

void Unwind_10019400(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019403. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019430 at 10019430

void Unwind_10019430(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019433. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019460 at 10019460

void Unwind_10019460(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194b0 at 100194b0

void Unwind_100194b0(void)

{
  int unaff_EBP;
  
  FUN_10012d20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194e0 at 100194e0

void Unwind_100194e0(void)

{
  int unaff_EBP;
  
  FUN_10012d20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019510 at 10019510

void Unwind_10019510(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019513. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019540 at 10019540

void Unwind_10019540(void)

{
  int unaff_EBP;
  
  FUN_1000bf40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019570 at 10019570

void Unwind_10019570(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195a0 at 100195a0

void Unwind_100195a0(void)

{
  int unaff_EBP;
  
  FUN_10002f40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195d0 at 100195d0

void Unwind_100195d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019600 at 10019600

void Unwind_10019600(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001960b at 1001960b

void Unwind_1001960b(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019630 at 10019630

void Unwind_10019630(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x3fc));
  return;
}



// Function: Unwind@100196b0 at 100196b0

void Unwind_100196b0(void)

{
  int unaff_EBP;
  
  FUN_10002250(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100196e0 at 100196e0

void Unwind_100196e0(void)

{
  int unaff_EBP;
  
  FUN_10002250(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100196eb at 100196eb

void Unwind_100196eb(void)

{
  int unaff_EBP;
  
  FUN_10012d20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019730 at 10019730

void Unwind_10019730(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001973b at 1001973b

void Unwind_1001973b(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019760 at 10019760

void Unwind_10019760(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019768 at 10019768

void Unwind_10019768(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019770 at 10019770

void Unwind_10019770(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019778 at 10019778

void Unwind_10019778(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019780 at 10019780

void Unwind_10019780(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019788 at 10019788

void Unwind_10019788(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100197b0 at 100197b0

void Unwind_100197b0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197b8 at 100197b8

void Unwind_100197b8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197c0 at 100197c0

void Unwind_100197c0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197c8 at 100197c8

void Unwind_100197c8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197d0 at 100197d0

void Unwind_100197d0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019800 at 10019800

void Unwind_10019800(void)

{
  int unaff_EBP;
  
  FUN_10002f90(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019808 at 10019808

void Unwind_10019808(void)

{
  int unaff_EBP;
  
  FUN_10002f40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019830 at 10019830

void Unwind_10019830(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019838 at 10019838

void Unwind_10019838(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019840 at 10019840

void Unwind_10019840(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019848 at 10019848

void Unwind_10019848(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019850 at 10019850

void Unwind_10019850(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019880 at 10019880

void Unwind_10019880(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001988b at 1001988b

void Unwind_1001988b(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019896 at 10019896

void Unwind_10019896(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100198a1 at 100198a1

void Unwind_100198a1(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100198ac at 100198ac

void Unwind_100198ac(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100198b7 at 100198b7

void Unwind_100198b7(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100198f0 at 100198f0

void Unwind_100198f0(void)

{
  int unaff_EBP;
  
  FUN_10003f20((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019920 at 10019920

void Unwind_10019920(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001992b at 1001992b

void Unwind_1001992b(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019936 at 10019936

void Unwind_10019936(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019960 at 10019960

void Unwind_10019960(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001996b at 1001996b

void Unwind_1001996b(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019976 at 10019976

void Unwind_10019976(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100199a0 at 100199a0

void Unwind_100199a0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100199a8 at 100199a8

void Unwind_100199a8(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@100199e0 at 100199e0

void Unwind_100199e0(void)

{
  int unaff_EBP;
  
  FUN_10003770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019a10 at 10019a10

void Unwind_10019a10(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019a40 at 10019a40

void Unwind_10019a40(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019a48 at 10019a48

void Unwind_10019a48(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019a50 at 10019a50

void Unwind_10019a50(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019a80 at 10019a80

void Unwind_10019a80(void)

{
  int unaff_EBP;
  
  FUN_10002590((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019ab0 at 10019ab0

void Unwind_10019ab0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019ae0 at 10019ae0

void Unwind_10019ae0(void)

{
  int unaff_EBP;
  
  FUN_10003f20((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10019aeb at 10019aeb

void Unwind_10019aeb(void)

{
  int unaff_EBP;
  
  FUN_10002590((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019af6 at 10019af6

void Unwind_10019af6(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019b01 at 10019b01

void Unwind_10019b01(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019b0c at 10019b0c

void Unwind_10019b0c(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b17 at 10019b17

void Unwind_10019b17(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b22 at 10019b22

void Unwind_10019b22(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019b2d at 10019b2d

void Unwind_10019b2d(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019b38 at 10019b38

void Unwind_10019b38(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019b43 at 10019b43

void Unwind_10019b43(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b4e at 10019b4e

void Unwind_10019b4e(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019b90 at 10019b90

void Unwind_10019b90(void)

{
  int unaff_EBP;
  
  FUN_10003eb0((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10019bd0 at 10019bd0

void Unwind_10019bd0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019bd8 at 10019bd8

void Unwind_10019bd8(void)

{
  int unaff_EBP;
  
  FUN_10003770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c00 at 10019c00

void Unwind_10019c00(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019c08 at 10019c08

void Unwind_10019c08(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019c10 at 10019c10

void Unwind_10019c10(void)

{
  int unaff_EBP;
  
  FUN_10005690((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019c18 at 10019c18

void Unwind_10019c18(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019c20 at 10019c20

void Unwind_10019c20(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019c50 at 10019c50

void Unwind_10019c50(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019c58 at 10019c58

void Unwind_10019c58(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019c63 at 10019c63

void Unwind_10019c63(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019c6e at 10019c6e

void Unwind_10019c6e(void)

{
  int unaff_EBP;
  
  FUN_10004880(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ca0 at 10019ca0

void Unwind_10019ca0(void)

{
  int unaff_EBP;
  
  FUN_10004880(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ca8 at 10019ca8

void Unwind_10019ca8(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019cb3 at 10019cb3

void Unwind_10019cb3(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019cbe at 10019cbe

void Unwind_10019cbe(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019cf0 at 10019cf0

void Unwind_10019cf0(void)

{
  int unaff_EBP;
  
  FUN_10002590((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019cf8 at 10019cf8

void Unwind_10019cf8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019d00 at 10019d00

void Unwind_10019d00(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d08 at 10019d08

void Unwind_10019d08(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d10 at 10019d10

void Unwind_10019d10(void)

{
  int unaff_EBP;
  
  FUN_10005690((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d18 at 10019d18

void Unwind_10019d18(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d20 at 10019d20

void Unwind_10019d20(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d28 at 10019d28

void Unwind_10019d28(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d30 at 10019d30

void Unwind_10019d30(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d38 at 10019d38

void Unwind_10019d38(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d40 at 10019d40

void Unwind_10019d40(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d48 at 10019d48

void Unwind_10019d48(void)

{
  int unaff_EBP;
  
  FUN_10004c50((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d50 at 10019d50

void Unwind_10019d50(void)

{
  int unaff_EBP;
  
  FUN_10003770((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019d80 at 10019d80

void Unwind_10019d80(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019d88 at 10019d88

void Unwind_10019d88(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019dc0 at 10019dc0

void Unwind_10019dc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019df0 at 10019df0

void Unwind_10019df0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019df8 at 10019df8

void Unwind_10019df8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e00 at 10019e00

void Unwind_10019e00(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e08 at 10019e08

void Unwind_10019e08(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e10 at 10019e10

void Unwind_10019e10(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e18 at 10019e18

void Unwind_10019e18(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e20 at 10019e20

void Unwind_10019e20(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e50 at 10019e50

void Unwind_10019e50(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019e80 at 10019e80

void Unwind_10019e80(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019e88 at 10019e88

void Unwind_10019e88(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019ec0 at 10019ec0

void Unwind_10019ec0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019ec8 at 10019ec8

void Unwind_10019ec8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019ed0 at 10019ed0

void Unwind_10019ed0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@10019edb at 10019edb

void Unwind_10019edb(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019ee3 at 10019ee3

void Unwind_10019ee3(void)

{
  int unaff_EBP;
  
  FUN_100047c0(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10019eee at 10019eee

void Unwind_10019eee(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019ef6 at 10019ef6

void Unwind_10019ef6(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10019f01 at 10019f01

void Unwind_10019f01(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019f09 at 10019f09

void Unwind_10019f09(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10019f14 at 10019f14

void Unwind_10019f14(void)

{
  int unaff_EBP;
  
  FUN_100047c0(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10019f50 at 10019f50

void Unwind_10019f50(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019f80 at 10019f80

void Unwind_10019f80(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10019f8b at 10019f8b

void Unwind_10019f8b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10019fc0 at 10019fc0

void Unwind_10019fc0(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@10019fcb at 10019fcb

void Unwind_10019fcb(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10019fd6 at 10019fd6

void Unwind_10019fd6(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001a010 at 1001a010

void Unwind_1001a010(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a040 at 1001a040

void Unwind_1001a040(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x44c));
  return;
}



// Function: Unwind@1001a04b at 1001a04b

void Unwind_1001a04b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1001a080 at 1001a080

void Unwind_1001a080(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001a088 at 1001a088

void Unwind_1001a088(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001a090 at 1001a090

void Unwind_1001a090(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a098 at 1001a098

void Unwind_1001a098(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a0a0 at 1001a0a0

void Unwind_1001a0a0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a0a8 at 1001a0a8

void Unwind_1001a0a8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a0b0 at 1001a0b0

void Unwind_1001a0b0(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001a0e0 at 1001a0e0

void Unwind_1001a0e0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001a110 at 1001a110

void Unwind_1001a110(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a118 at 1001a118

void Unwind_1001a118(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a120 at 1001a120

void Unwind_1001a120(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a128 at 1001a128

void Unwind_1001a128(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a130 at 1001a130

void Unwind_1001a130(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a138 at 1001a138

void Unwind_1001a138(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a170 at 1001a170

void Unwind_1001a170(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a178 at 1001a178

void Unwind_1001a178(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001a183 at 1001a183

void Unwind_1001a183(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001a18b at 1001a18b

void Unwind_1001a18b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a193 at 1001a193

void Unwind_1001a193(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001a19b at 1001a19b

void Unwind_1001a19b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001a1d0 at 1001a1d0

void Unwind_1001a1d0(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a1d8 at 1001a1d8

void Unwind_1001a1d8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a200 at 1001a200

void Unwind_1001a200(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001a208 at 1001a208

void Unwind_1001a208(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a210 at 1001a210

void Unwind_1001a210(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a218 at 1001a218

void Unwind_1001a218(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a220 at 1001a220

void Unwind_1001a220(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a228 at 1001a228

void Unwind_1001a228(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a230 at 1001a230

void Unwind_1001a230(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a238 at 1001a238

void Unwind_1001a238(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a260 at 1001a260

void Unwind_1001a260(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a268 at 1001a268

void Unwind_1001a268(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a270 at 1001a270

void Unwind_1001a270(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a278 at 1001a278

void Unwind_1001a278(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2a0 at 1001a2a0

void Unwind_1001a2a0(void)

{
  FUN_10002f40(0x1003455c);
  return;
}



// Function: Unwind@1001a2aa at 1001a2aa

void Unwind_1001a2aa(void)

{
  FUN_10002f90(0x1003455c);
  return;
}



// Function: Unwind@1001a2d0 at 1001a2d0

void Unwind_1001a2d0(void)

{
  FUN_10002f90(0x1003455c);
  return;
}



// Function: Unwind@1001a2da at 1001a2da

void Unwind_1001a2da(void)

{
  FUN_10002f40(0x1003455c);
  return;
}



// Function: Unwind@1001a300 at 1001a300

void Unwind_1001a300(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a303. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a309 at 1001a309

void Unwind_1001a309(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a330 at 1001a330

void Unwind_1001a330(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a33b at 1001a33b

void Unwind_1001a33b(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a360 at 1001a360

void Unwind_1001a360(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a36b at 1001a36b

void Unwind_1001a36b(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a390 at 1001a390

void Unwind_1001a390(void)

{
  int unaff_EBP;
  
  FUN_1000a440((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a3c0 at 1001a3c0

void Unwind_1001a3c0(void)

{
  int unaff_EBP;
  
  FUN_1000a5b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3f0 at 1001a3f0

void Unwind_1001a3f0(void)

{
  int unaff_EBP;
  
  FUN_1000a5b0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a3f8 at 1001a3f8

void Unwind_1001a3f8(void)

{
  int unaff_EBP;
  
  FUN_1000b0d0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a400 at 1001a400

void Unwind_1001a400(void)

{
  int unaff_EBP;
  
  FUN_1000a440((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a408 at 1001a408

void Unwind_1001a408(void)

{
  int unaff_EBP;
  
  FUN_1000a5b0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a430 at 1001a430

void Unwind_1001a430(void)

{
  int unaff_EBP;
  
  FUN_1000a5b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a438 at 1001a438

void Unwind_1001a438(void)

{
  int unaff_EBP;
  
  FUN_1000b0d0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a440 at 1001a440

void Unwind_1001a440(void)

{
  int unaff_EBP;
  
  FUN_1000a5b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a470 at 1001a470

void Unwind_1001a470(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a478 at 1001a478

void Unwind_1001a478(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a480 at 1001a480

void Unwind_1001a480(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a488 at 1001a488

void Unwind_1001a488(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a4b0 at 1001a4b0

void Unwind_1001a4b0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a4b8 at 1001a4b8

void Unwind_1001a4b8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a4c0 at 1001a4c0

void Unwind_1001a4c0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a4f0 at 1001a4f0

void Unwind_1001a4f0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a4fb at 1001a4fb

void Unwind_1001a4fb(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001a506 at 1001a506

void Unwind_1001a506(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a50e at 1001a50e

void Unwind_1001a50e(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a560 at 1001a560

void Unwind_1001a560(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a56b at 1001a56b

void Unwind_1001a56b(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001a576 at 1001a576

void Unwind_1001a576(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001a581 at 1001a581

void Unwind_1001a581(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001a58c at 1001a58c

void Unwind_1001a58c(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001a597 at 1001a597

void Unwind_1001a597(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a59f at 1001a59f

void Unwind_1001a59f(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5a7 at 1001a5a7

void Unwind_1001a5a7(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5af at 1001a5af

void Unwind_1001a5af(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5e0 at 1001a5e0

void Unwind_1001a5e0(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 0x50);
  return;
}



// Function: Unwind@1001a5eb at 1001a5eb

void Unwind_1001a5eb(void)

{
  int unaff_EBP;
  
  FUN_1000b9a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5f3 at 1001a5f3

void Unwind_1001a5f3(void)

{
  int unaff_EBP;
  
  FUN_1000bd10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001a5fe at 1001a5fe

void Unwind_1001a5fe(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a609 at 1001a609

void Unwind_1001a609(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001a614 at 1001a614

void Unwind_1001a614(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a61c at 1001a61c

void Unwind_1001a61c(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a624 at 1001a624

void Unwind_1001a624(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a62f at 1001a62f

void Unwind_1001a62f(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a660 at 1001a660

void Unwind_1001a660(void)

{
  int unaff_EBP;
  
  FUN_100011f0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a668 at 1001a668

void Unwind_1001a668(void)

{
  int unaff_EBP;
  
  FUN_10002ac0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a673 at 1001a673

void Unwind_1001a673(void)

{
  int unaff_EBP;
  
  FUN_10003e50(*(int *)(unaff_EBP + -0x10) + 0x50);
  return;
}



// Function: Unwind@1001a67e at 1001a67e

void Unwind_1001a67e(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a686 at 1001a686

void Unwind_1001a686(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a691 at 1001a691

void Unwind_1001a691(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a699 at 1001a699

void Unwind_1001a699(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001a6a4 at 1001a6a4

void Unwind_1001a6a4(void)

{
  int unaff_EBP;
  
  FUN_1000b9a0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a6ac at 1001a6ac

void Unwind_1001a6ac(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a6b4 at 1001a6b4

void Unwind_1001a6b4(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a6bf at 1001a6bf

void Unwind_1001a6bf(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a6c7 at 1001a6c7

void Unwind_1001a6c7(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@1001a6d2 at 1001a6d2

void Unwind_1001a6d2(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a6da at 1001a6da

void Unwind_1001a6da(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  return;
}



// Function: Unwind@1001a6e5 at 1001a6e5

void Unwind_1001a6e5(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a6ed at 1001a6ed

void Unwind_1001a6ed(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 0x10));
  return;
}



// Function: Unwind@1001a6f8 at 1001a6f8

void Unwind_1001a6f8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x18));
  return;
}



// Function: Unwind@1001a703 at 1001a703

void Unwind_1001a703(void)

{
  int unaff_EBP;
  
  FUN_1000bd10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001a730 at 1001a730

void Unwind_1001a730(void)

{
  int unaff_EBP;
  
  FUN_1000bff0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a760 at 1001a760

void Unwind_1001a760(void)

{
  int unaff_EBP;
  
  FUN_1000bff0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a790 at 1001a790

void Unwind_1001a790(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a798 at 1001a798

void Unwind_1001a798(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a7a0 at 1001a7a0

void Unwind_1001a7a0(void)

{
  int unaff_EBP;
  
  FUN_100072e0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001a7a8 at 1001a7a8

void Unwind_1001a7a8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001a7e0 at 1001a7e0

void Unwind_1001a7e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a7e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a810 at 1001a810

void Unwind_1001a810(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a818 at 1001a818

void Unwind_1001a818(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a820 at 1001a820

void Unwind_1001a820(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001a850 at 1001a850

void Unwind_1001a850(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a853. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a859 at 1001a859

void Unwind_1001a859(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001a86f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x70));
    return;
  }
  return;
}



// Function: Unwind@1001a876 at 1001a876

void Unwind_1001a876(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a87c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001a882 at 1001a882

void Unwind_1001a882(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a885. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a88b at 1001a88b

void Unwind_1001a88b(void)

{
  int unaff_EBP;
  
  FUN_1000cd00((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001a8c0 at 1001a8c0

void Unwind_1001a8c0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a8c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001a8cc at 1001a8cc

void Unwind_1001a8cc(void)

{
  int unaff_EBP;
  
  FUN_1000cd00((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001a8d7 at 1001a8d7

void Unwind_1001a8d7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a8da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a900 at 1001a900

void Unwind_1001a900(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a903. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a930 at 1001a930

void Unwind_1001a930(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a933. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  FUN_1000d090(unaff_EBP + -0x2e8);
  return;
}



// Function: Unwind@1001a96b at 1001a96b

void Unwind_1001a96b(void)

{
  int unaff_EBP;
  
  FUN_10003010((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@1001a976 at 1001a976

void Unwind_1001a976(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a97c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001a982 at 1001a982

void Unwind_1001a982(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001a98e at 1001a98e

void Unwind_1001a98e(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001a999 at 1001a999

void Unwind_1001a999(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a99f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001a9d0 at 1001a9d0

void Unwind_1001a9d0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a9d8 at 1001a9d8

void Unwind_1001a9d8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a9e0 at 1001a9e0

void Unwind_1001a9e0(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a9e8 at 1001a9e8

void Unwind_1001a9e8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a9eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001a9f1 at 1001a9f1

void Unwind_1001a9f1(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a9f9 at 1001a9f9

void Unwind_1001a9f9(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aa01 at 1001aa01

void Unwind_1001aa01(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001aa09 at 1001aa09

void Unwind_1001aa09(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aa40 at 1001aa40

void Unwind_1001aa40(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001aa48 at 1001aa48

void Unwind_1001aa48(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aa50 at 1001aa50

void Unwind_1001aa50(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aa58 at 1001aa58

void Unwind_1001aa58(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aa60 at 1001aa60

void Unwind_1001aa60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001aa63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001aa69 at 1001aa69

void Unwind_1001aa69(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aa71 at 1001aa71

void Unwind_1001aa71(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aa79 at 1001aa79

void Unwind_1001aa79(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aa81 at 1001aa81

void Unwind_1001aa81(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aab0 at 1001aab0

void Unwind_1001aab0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001aab8 at 1001aab8

void Unwind_1001aab8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aac0 at 1001aac0

void Unwind_1001aac0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aac8 at 1001aac8

void Unwind_1001aac8(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aad0 at 1001aad0

void Unwind_1001aad0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001aad3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001aad9 at 1001aad9

void Unwind_1001aad9(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aae1 at 1001aae1

void Unwind_1001aae1(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aae9 at 1001aae9

void Unwind_1001aae9(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001aaf1 at 1001aaf1

void Unwind_1001aaf1(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ab20 at 1001ab20

void Unwind_1001ab20(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001ab28 at 1001ab28

void Unwind_1001ab28(void)

{
  int unaff_EBP;
  
  FUN_10016d80((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ab30 at 1001ab30

void Unwind_1001ab30(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001ab38 at 1001ab38

void Unwind_1001ab38(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001ab40 at 1001ab40

void Unwind_1001ab40(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ab48 at 1001ab48

void Unwind_1001ab48(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ab4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001ab54 at 1001ab54

void Unwind_1001ab54(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001ab5c at 1001ab5c

void Unwind_1001ab5c(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ab64 at 1001ab64

void Unwind_1001ab64(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001ab6c at 1001ab6c

void Unwind_1001ab6c(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001aba0 at 1001aba0

void Unwind_1001aba0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001aba8 at 1001aba8

void Unwind_1001aba8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001abb0 at 1001abb0

void Unwind_1001abb0(void)

{
  int unaff_EBP;
  
  FUN_10016d80((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001abb8 at 1001abb8

void Unwind_1001abb8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001abc0 at 1001abc0

void Unwind_1001abc0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001abc8 at 1001abc8

void Unwind_1001abc8(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001abd0 at 1001abd0

void Unwind_1001abd0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001abd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001abdc at 1001abdc

void Unwind_1001abdc(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001abe4 at 1001abe4

void Unwind_1001abe4(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001abec at 1001abec

void Unwind_1001abec(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001abf4 at 1001abf4

void Unwind_1001abf4(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ac30 at 1001ac30

void Unwind_1001ac30(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001ac38 at 1001ac38

void Unwind_1001ac38(void)

{
  int unaff_EBP;
  
  FUN_10016d80((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001ac43 at 1001ac43

void Unwind_1001ac43(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ac4b at 1001ac4b

void Unwind_1001ac4b(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ac53 at 1001ac53

void Unwind_1001ac53(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ac5b at 1001ac5b

void Unwind_1001ac5b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ac61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001ac67 at 1001ac67

void Unwind_1001ac67(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ac6f at 1001ac6f

void Unwind_1001ac6f(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ac77 at 1001ac77

void Unwind_1001ac77(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ac7f at 1001ac7f

void Unwind_1001ac7f(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001acb0 at 1001acb0

void Unwind_1001acb0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001acb8 at 1001acb8

void Unwind_1001acb8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001acc0 at 1001acc0

void Unwind_1001acc0(void)

{
  int unaff_EBP;
  
  FUN_10016d80((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001acc8 at 1001acc8

void Unwind_1001acc8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001acd3 at 1001acd3

void Unwind_1001acd3(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001acde at 1001acde

void Unwind_1001acde(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ace6 at 1001ace6

void Unwind_1001ace6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001acec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001acf2 at 1001acf2

void Unwind_1001acf2(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001acfd at 1001acfd

void Unwind_1001acfd(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ad05 at 1001ad05

void Unwind_1001ad05(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001ad10 at 1001ad10

void Unwind_1001ad10(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001ad40 at 1001ad40

void Unwind_1001ad40(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad48 at 1001ad48

void Unwind_1001ad48(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ad53 at 1001ad53

void Unwind_1001ad53(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ad80 at 1001ad80

void Unwind_1001ad80(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad88 at 1001ad88

void Unwind_1001ad88(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001ad93 at 1001ad93

void Unwind_1001ad93(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ad9b at 1001ad9b

void Unwind_1001ad9b(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ada3 at 1001ada3

void Unwind_1001ada3(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001adab at 1001adab

void Unwind_1001adab(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001adb3 at 1001adb3

void Unwind_1001adb3(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001adbb at 1001adbb

void Unwind_1001adbb(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001adc3 at 1001adc3

void Unwind_1001adc3(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001adf0 at 1001adf0

void Unwind_1001adf0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001adf8 at 1001adf8

void Unwind_1001adf8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae00 at 1001ae00

void Unwind_1001ae00(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ae40 at 1001ae40

void Unwind_1001ae40(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ae48 at 1001ae48

void Unwind_1001ae48(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ae70 at 1001ae70

void Unwind_1001ae70(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ae78 at 1001ae78

void Unwind_1001ae78(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae80 at 1001ae80

void Unwind_1001ae80(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae88 at 1001ae88

void Unwind_1001ae88(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ae90 at 1001ae90

void Unwind_1001ae90(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@1001ae9b at 1001ae9b

void Unwind_1001ae9b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000aaa0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001aeb4 at 1001aeb4

void Unwind_1001aeb4(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aee0 at 1001aee0

void Unwind_1001aee0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001aee8 at 1001aee8

void Unwind_1001aee8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aef0 at 1001aef0

void Unwind_1001aef0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aef8 at 1001aef8

void Unwind_1001aef8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001af00 at 1001af00

void Unwind_1001af00(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af08 at 1001af08

void Unwind_1001af08(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af10 at 1001af10

void Unwind_1001af10(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001af18 at 1001af18

void Unwind_1001af18(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@1001af23 at 1001af23

void Unwind_1001af23(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_1000ab20(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001af3c at 1001af3c

void Unwind_1001af3c(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af44 at 1001af44

void Unwind_1001af44(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001af70 at 1001af70

void Unwind_1001af70(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001af78 at 1001af78

void Unwind_1001af78(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001af83 at 1001af83

void Unwind_1001af83(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001af8b at 1001af8b

void Unwind_1001af8b(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af93 at 1001af93

void Unwind_1001af93(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001af9b at 1001af9b

void Unwind_1001af9b(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afa3 at 1001afa3

void Unwind_1001afa3(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afab at 1001afab

void Unwind_1001afab(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001afb3 at 1001afb3

void Unwind_1001afb3(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afe0 at 1001afe0

void Unwind_1001afe0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b010 at 1001b010

void Unwind_1001b010(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b018 at 1001b018

void Unwind_1001b018(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10016c40(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b031 at 1001b031

void Unwind_1001b031(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b039 at 1001b039

void Unwind_1001b039(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b060 at 1001b060

void Unwind_1001b060(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b068 at 1001b068

void Unwind_1001b068(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001b073 at 1001b073

void Unwind_1001b073(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b07b at 1001b07b

void Unwind_1001b07b(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b086 at 1001b086

void Unwind_1001b086(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001b091 at 1001b091

void Unwind_1001b091(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b099 at 1001b099

void Unwind_1001b099(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b0a4 at 1001b0a4

void Unwind_1001b0a4(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0ac at 1001b0ac

void Unwind_1001b0ac(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1001b0b7 at 1001b0b7

void Unwind_1001b0b7(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0bf at 1001b0bf

void Unwind_1001b0bf(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001b0ca at 1001b0ca

void Unwind_1001b0ca(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0d2 at 1001b0d2

void Unwind_1001b0d2(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001b100 at 1001b100

void Unwind_1001b100(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x34) + 4));
  return;
}



// Function: Unwind@1001b10b at 1001b10b

void Unwind_1001b10b(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(*(int *)(unaff_EBP + -0x34) + 8));
  return;
}



// Function: Unwind@1001b116 at 1001b116

void Unwind_1001b116(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x34) + 0x10));
  return;
}



// Function: Unwind@1001b121 at 1001b121

void Unwind_1001b121(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x34) + 0x14));
  return;
}



// Function: Unwind@1001b12c at 1001b12c

void Unwind_1001b12c(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x34) + 0x18));
  return;
}



// Function: Unwind@1001b137 at 1001b137

void Unwind_1001b137(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x34) + 0x1c));
  return;
}



// Function: Unwind@1001b142 at 1001b142

void Unwind_1001b142(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b14a at 1001b14a

void Unwind_1001b14a(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b152 at 1001b152

void Unwind_1001b152(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b15a at 1001b15a

void Unwind_1001b15a(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b162 at 1001b162

void Unwind_1001b162(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b16a at 1001b16a

void Unwind_1001b16a(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b172 at 1001b172

void Unwind_1001b172(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@1001b17d at 1001b17d

void Unwind_1001b17d(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b185 at 1001b185

void Unwind_1001b185(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b1c0 at 1001b1c0

void Unwind_1001b1c0(void)

{
  int unaff_EBP;
  
  FUN_1000ab20((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b1c8 at 1001b1c8

void Unwind_1001b1c8(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b1d0 at 1001b1d0

void Unwind_1001b1d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10016c40(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b1e9 at 1001b1e9

void Unwind_1001b1e9(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b1f1 at 1001b1f1

void Unwind_1001b1f1(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b220 at 1001b220

void Unwind_1001b220(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b228 at 1001b228

void Unwind_1001b228(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000a9a0(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b241 at 1001b241

void Unwind_1001b241(void)

{
  int unaff_EBP;
  
  FUN_1000a700((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b249 at 1001b249

void Unwind_1001b249(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b270 at 1001b270

void Unwind_1001b270(void)

{
  int unaff_EBP;
  
  FUN_1000fe60((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b278 at 1001b278

void Unwind_1001b278(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000a9a0(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b2b0 at 1001b2b0

void Unwind_1001b2b0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001b2b8 at 1001b2b8

void Unwind_1001b2b8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b2c0 at 1001b2c0

void Unwind_1001b2c0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b2c8 at 1001b2c8

void Unwind_1001b2c8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b2d0 at 1001b2d0

void Unwind_1001b2d0(void)

{
  int unaff_EBP;
  
  FUN_1000aa20((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b2d8 at 1001b2d8

void Unwind_1001b2d8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b2e0 at 1001b2e0

void Unwind_1001b2e0(void)

{
  int unaff_EBP;
  
  FUN_1000aaa0((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001b2e8 at 1001b2e8

void Unwind_1001b2e8(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001b2f3 at 1001b2f3

void Unwind_1001b2f3(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b2fb at 1001b2fb

void Unwind_1001b2fb(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b303 at 1001b303

void Unwind_1001b303(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001b30e at 1001b30e

void Unwind_1001b30e(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + -0x7c);
  return;
}



// Function: Unwind@1001b316 at 1001b316

void Unwind_1001b316(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_10001210((undefined4 *)(unaff_EBP + -0x44));
    return;
  }
  return;
}



// Function: Unwind@1001b32f at 1001b32f

void Unwind_1001b32f(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffd;
    FUN_10001210((undefined4 *)(unaff_EBP + -0x44));
    return;
  }
  return;
}



// Function: Unwind@1001b370 at 1001b370

void Unwind_1001b370(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b378 at 1001b378

void Unwind_1001b378(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b380 at 1001b380

void Unwind_1001b380(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b388 at 1001b388

void Unwind_1001b388(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b390 at 1001b390

void Unwind_1001b390(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@1001b39b at 1001b39b

void Unwind_1001b39b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_1000ab20(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b3b4 at 1001b3b4

void Unwind_1001b3b4(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b3bc at 1001b3bc

void Unwind_1001b3bc(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3e0 at 1001b3e0

void Unwind_1001b3e0(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b410 at 1001b410

void Unwind_1001b410(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b460 at 1001b460

void Unwind_1001b460(void)

{
  int unaff_EBP;
  
  FUN_10010750(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b46b at 1001b46b

void Unwind_1001b46b(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b4a0 at 1001b4a0

void Unwind_1001b4a0(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b4a8 at 1001b4a8

void Unwind_1001b4a8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001b4b3 at 1001b4b3

void Unwind_1001b4b3(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b4bb at 1001b4bb

void Unwind_1001b4bb(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b4c6 at 1001b4c6

void Unwind_1001b4c6(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b4f0 at 1001b4f0

void Unwind_1001b4f0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001b4fb at 1001b4fb

void Unwind_1001b4fb(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b506 at 1001b506

void Unwind_1001b506(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b511 at 1001b511

void Unwind_1001b511(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b519 at 1001b519

void Unwind_1001b519(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b540 at 1001b540

void Unwind_1001b540(void)

{
  FUN_10010660();
  return;
}



// Function: Unwind@1001b570 at 1001b570

void Unwind_1001b570(void)

{
  int unaff_EBP;
  
  FUN_100106d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001b57b at 1001b57b

void Unwind_1001b57b(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001b586 at 1001b586

void Unwind_1001b586(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001b591 at 1001b591

void Unwind_1001b591(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001b59c at 1001b59c

void Unwind_1001b59c(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001b5a7 at 1001b5a7

void Unwind_1001b5a7(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5af at 1001b5af

void Unwind_1001b5af(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5b7 at 1001b5b7

void Unwind_1001b5b7(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5bf at 1001b5bf

void Unwind_1001b5bf(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5f0 at 1001b5f0

void Unwind_1001b5f0(void)

{
  int unaff_EBP;
  
  FUN_10016c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b5f8 at 1001b5f8

void Unwind_1001b5f8(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b620 at 1001b620

void Unwind_1001b620(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b628 at 1001b628

void Unwind_1001b628(void)

{
  int unaff_EBP;
  
  FUN_10016c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b650 at 1001b650

void Unwind_1001b650(void)

{
  int unaff_EBP;
  
  FUN_10010f50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b658 at 1001b658

void Unwind_1001b658(void)

{
  int unaff_EBP;
  
  FUN_10010750(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b663 at 1001b663

void Unwind_1001b663(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b690 at 1001b690

void Unwind_1001b690(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b698 at 1001b698

void Unwind_1001b698(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b6a0 at 1001b6a0

void Unwind_1001b6a0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6a8 at 1001b6a8

void Unwind_1001b6a8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6b0 at 1001b6b0

void Unwind_1001b6b0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6b8 at 1001b6b8

void Unwind_1001b6b8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6c0 at 1001b6c0

void Unwind_1001b6c0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6c8 at 1001b6c8

void Unwind_1001b6c8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6d0 at 1001b6d0

void Unwind_1001b6d0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b700 at 1001b700

void Unwind_1001b700(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b703. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b730 at 1001b730

void Unwind_1001b730(void)

{
  int unaff_EBP;
  
  FUN_10011700(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b738 at 1001b738

void Unwind_1001b738(void)

{
  int unaff_EBP;
  
  FUN_10010f50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b740 at 1001b740

void Unwind_1001b740(void)

{
  int unaff_EBP;
  
  FUN_10010750(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b74b at 1001b74b

void Unwind_1001b74b(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b780 at 1001b780

void Unwind_1001b780(void)

{
  int unaff_EBP;
  
  FUN_100106d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001b78b at 1001b78b

void Unwind_1001b78b(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b793 at 1001b793

void Unwind_1001b793(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001b79e at 1001b79e

void Unwind_1001b79e(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b7a6 at 1001b7a6

void Unwind_1001b7a6(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001b7b1 at 1001b7b1

void Unwind_1001b7b1(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b7b9 at 1001b7b9

void Unwind_1001b7b9(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001b7c4 at 1001b7c4

void Unwind_1001b7c4(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b7cc at 1001b7cc

void Unwind_1001b7cc(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001b800 at 1001b800

void Unwind_1001b800(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001b80c at 1001b80c

void Unwind_1001b80c(void)

{
  int unaff_EBP;
  
  FUN_100109a0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@1001b817 at 1001b817

void Unwind_1001b817(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b81a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b820 at 1001b820

void Unwind_1001b820(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b823. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b850 at 1001b850

void Unwind_1001b850(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b858 at 1001b858

void Unwind_1001b858(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b860 at 1001b860

void Unwind_1001b860(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b868 at 1001b868

void Unwind_1001b868(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b890 at 1001b890

void Unwind_1001b890(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b893. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b899 at 1001b899

void Unwind_1001b899(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001b8af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@1001b8b6 at 1001b8b6

void Unwind_1001b8b6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b8bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001b8c2 at 1001b8c2

void Unwind_1001b8c2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b8c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b8cb at 1001b8cb

void Unwind_1001b8cb(void)

{
  int unaff_EBP;
  
  FUN_100109a0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b900 at 1001b900

void Unwind_1001b900(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b908 at 1001b908

void Unwind_1001b908(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b910 at 1001b910

void Unwind_1001b910(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b918 at 1001b918

void Unwind_1001b918(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b920 at 1001b920

void Unwind_1001b920(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b928 at 1001b928

void Unwind_1001b928(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b930 at 1001b930

void Unwind_1001b930(void)

{
  int unaff_EBP;
  
  FUN_10016c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b938 at 1001b938

void Unwind_1001b938(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b960 at 1001b960

void Unwind_1001b960(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b968 at 1001b968

void Unwind_1001b968(void)

{
  int unaff_EBP;
  
  FUN_10010d80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b990 at 1001b990

void Unwind_1001b990(void)

{
  int unaff_EBP;
  
  FUN_10011190(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b9c0 at 1001b9c0

void Unwind_1001b9c0(void)

{
  int unaff_EBP;
  
  FUN_10010d80((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001b9c8 at 1001b9c8

void Unwind_1001b9c8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001ba00 at 1001ba00

void Unwind_1001ba00(void)

{
  int unaff_EBP;
  
  FUN_10011190(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba08 at 1001ba08

void Unwind_1001ba08(void)

{
  int unaff_EBP;
  
  FUN_10012460((int *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}



// Function: Unwind@1001ba13 at 1001ba13

void Unwind_1001ba13(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001ba16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ba40 at 1001ba40

void Unwind_1001ba40(void)

{
  int unaff_EBP;
  
  FUN_10012460((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1001ba4b at 1001ba4b

void Unwind_1001ba4b(void)

{
  int unaff_EBP;
  
  FUN_10011190(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ba70 at 1001ba70

void Unwind_1001ba70(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba78 at 1001ba78

void Unwind_1001ba78(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001ba83 at 1001ba83

void Unwind_1001ba83(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba8b at 1001ba8b

void Unwind_1001ba8b(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001ba96 at 1001ba96

void Unwind_1001ba96(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba9e at 1001ba9e

void Unwind_1001ba9e(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001baa9 at 1001baa9

void Unwind_1001baa9(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bab1 at 1001bab1

void Unwind_1001bab1(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



// Function: Unwind@1001babc at 1001babc

void Unwind_1001babc(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001bac7 at 1001bac7

void Unwind_1001bac7(void)

{
  int unaff_EBP;
  
  FUN_1000bd10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001bad2 at 1001bad2

void Unwind_1001bad2(void)

{
  int unaff_EBP;
  
  FUN_100106c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001badd at 1001badd

void Unwind_1001badd(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001bae8 at 1001bae8

void Unwind_1001bae8(void)

{
  int unaff_EBP;
  
  FUN_10010750(*(int *)(unaff_EBP + -0x18) + 8);
  return;
}



// Function: Unwind@1001baf3 at 1001baf3

void Unwind_1001baf3(void)

{
  int unaff_EBP;
  
  FUN_10010f50(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bafb at 1001bafb

void Unwind_1001bafb(void)

{
  int unaff_EBP;
  
  FUN_10011700(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bb03 at 1001bb03

void Unwind_1001bb03(void)

{
  int unaff_EBP;
  
  FUN_10011960(*(int *)(unaff_EBP + -0x10) + 0x3c);
  return;
}



// Function: Unwind@1001bb0e at 1001bb0e

void Unwind_1001bb0e(void)

{
  int unaff_EBP;
  
  FUN_10011240(*(int *)(unaff_EBP + -0x10) + 100);
  return;
}



// Function: Unwind@1001bb19 at 1001bb19

void Unwind_1001bb19(void)

{
  int unaff_EBP;
  
  FUN_100129f0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xb4));
  return;
}



// Function: Unwind@1001bb27 at 1001bb27

void Unwind_1001bb27(void)

{
  int unaff_EBP;
  
  FUN_10011060((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}



// Function: Unwind@1001bb35 at 1001bb35

void Unwind_1001bb35(void)

{
  int unaff_EBP;
  
  FUN_10010980((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x134));
  return;
}



// Function: Unwind@1001bb43 at 1001bb43

void Unwind_1001bb43(void)

{
  int unaff_EBP;
  
  FUN_10010980((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x138));
  return;
}



// Function: Unwind@1001bb51 at 1001bb51

void Unwind_1001bb51(void)

{
  int unaff_EBP;
  
  FUN_10017dc0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144));
  return;
}



// Function: Unwind@1001bb5f at 1001bb5f

void Unwind_1001bb5f(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bb67 at 1001bb67

void Unwind_1001bb67(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x150));
  return;
}



// Function: Unwind@1001bb75 at 1001bb75

void Unwind_1001bb75(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bb7d at 1001bb7d

void Unwind_1001bb7d(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x154));
  return;
}



// Function: Unwind@1001bbb0 at 1001bbb0

void Unwind_1001bbb0(void)

{
  int unaff_EBP;
  
  FUN_1000bd10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001bbbb at 1001bbbb

void Unwind_1001bbbb(void)

{
  int unaff_EBP;
  
  FUN_100106c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001bbc6 at 1001bbc6

void Unwind_1001bbc6(void)

{
  int unaff_EBP;
  
  FUN_10011960(*(int *)(unaff_EBP + -0x10) + 0x3c);
  return;
}



// Function: Unwind@1001bbd1 at 1001bbd1

void Unwind_1001bbd1(void)

{
  int unaff_EBP;
  
  FUN_10011240(*(int *)(unaff_EBP + -0x10) + 100);
  return;
}



// Function: Unwind@1001bbdc at 1001bbdc

void Unwind_1001bbdc(void)

{
  int unaff_EBP;
  
  FUN_100129f0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xb4));
  return;
}



// Function: Unwind@1001bbea at 1001bbea

void Unwind_1001bbea(void)

{
  int unaff_EBP;
  
  FUN_10011060((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}



// Function: Unwind@1001bbf8 at 1001bbf8

void Unwind_1001bbf8(void)

{
  int unaff_EBP;
  
  FUN_10010980((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x134));
  return;
}



// Function: Unwind@1001bc06 at 1001bc06

void Unwind_1001bc06(void)

{
  int unaff_EBP;
  
  FUN_10010980((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x138));
  return;
}



// Function: Unwind@1001bc14 at 1001bc14

void Unwind_1001bc14(void)

{
  int unaff_EBP;
  
  FUN_10017dc0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144));
  return;
}



// Function: Unwind@1001bc22 at 1001bc22

void Unwind_1001bc22(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x150));
  return;
}



// Function: Unwind@1001bc30 at 1001bc30

void Unwind_1001bc30(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x154));
  return;
}



// Function: Unwind@1001bc3e at 1001bc3e

void Unwind_1001bc3e(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bc46 at 1001bc46

void Unwind_1001bc46(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bc4e at 1001bc4e

void Unwind_1001bc4e(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001bc59 at 1001bc59

void Unwind_1001bc59(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001bc64 at 1001bc64

void Unwind_1001bc64(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



// Function: Unwind@1001bc6f at 1001bc6f

void Unwind_1001bc6f(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc77 at 1001bc77

void Unwind_1001bc77(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc7f at 1001bc7f

void Unwind_1001bc7f(void)

{
  int unaff_EBP;
  
  FUN_10011700(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc87 at 1001bc87

void Unwind_1001bc87(void)

{
  int unaff_EBP;
  
  FUN_10010f50(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc8f at 1001bc8f

void Unwind_1001bc8f(void)

{
  int unaff_EBP;
  
  FUN_10010750(*(int *)(unaff_EBP + -0x18) + 8);
  return;
}



// Function: Unwind@1001bc9a at 1001bc9a

void Unwind_1001bc9a(void)

{
  int unaff_EBP;
  
  FUN_10010670((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  return;
}



// Function: Unwind@1001bcc0 at 1001bcc0

void Unwind_1001bcc0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bcc8 at 1001bcc8

void Unwind_1001bcc8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1001bce1 at 1001bce1

void Unwind_1001bce1(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bce9 at 1001bce9

void Unwind_1001bce9(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bd20 at 1001bd20

void Unwind_1001bd20(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + -0x40));
    return;
  }
  return;
}



// Function: Unwind@1001bd39 at 1001bd39

void Unwind_1001bd39(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001bd41 at 1001bd41

void Unwind_1001bd41(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001bd70 at 1001bd70

void Unwind_1001bd70(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001bdb0 at 1001bdb0

void Unwind_1001bdb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001bdf0 at 1001bdf0

void Unwind_1001bdf0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bdf8 at 1001bdf8

void Unwind_1001bdf8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001be00 at 1001be00

void Unwind_1001be00(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be08 at 1001be08

void Unwind_1001be08(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be10 at 1001be10

void Unwind_1001be10(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001be18 at 1001be18

void Unwind_1001be18(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001be20 at 1001be20

void Unwind_1001be20(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001be28 at 1001be28

void Unwind_1001be28(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001be30 at 1001be30

void Unwind_1001be30(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001be38 at 1001be38

void Unwind_1001be38(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be40 at 1001be40

void Unwind_1001be40(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be48 at 1001be48

void Unwind_1001be48(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001be50 at 1001be50

void Unwind_1001be50(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001be58 at 1001be58

void Unwind_1001be58(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be60 at 1001be60

void Unwind_1001be60(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001be90 at 1001be90

void Unwind_1001be90(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001be98 at 1001be98

void Unwind_1001be98(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bea0 at 1001bea0

void Unwind_1001bea0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bea8 at 1001bea8

void Unwind_1001bea8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001beb0 at 1001beb0

void Unwind_1001beb0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001beb8 at 1001beb8

void Unwind_1001beb8(void)

{
  int unaff_EBP;
  
  FUN_10011300((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bec0 at 1001bec0

void Unwind_1001bec0(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001bef0 at 1001bef0

void Unwind_1001bef0(void)

{
  int unaff_EBP;
  
  FUN_10011b80((int *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1001befb at 1001befb

void Unwind_1001befb(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bf03 at 1001bf03

void Unwind_1001bf03(void)

{
  int unaff_EBP;
  
  FUN_100047c0(*(undefined4 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001bf40 at 1001bf40

void Unwind_1001bf40(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bf48 at 1001bf48

void Unwind_1001bf48(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bf50 at 1001bf50

void Unwind_1001bf50(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bf58 at 1001bf58

void Unwind_1001bf58(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bf80 at 1001bf80

void Unwind_1001bf80(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001bf88 at 1001bf88

void Unwind_1001bf88(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001bf90 at 1001bf90

void Unwind_1001bf90(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001bf98 at 1001bf98

void Unwind_1001bf98(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bf9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001bfa1 at 1001bfa1

void Unwind_1001bfa1(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001bfa9 at 1001bfa9

void Unwind_1001bfa9(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001bfb1 at 1001bfb1

void Unwind_1001bfb1(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001bfb9 at 1001bfb9

void Unwind_1001bfb9(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001bff0 at 1001bff0

void Unwind_1001bff0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001bff8 at 1001bff8

void Unwind_1001bff8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c000 at 1001c000

void Unwind_1001c000(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c008 at 1001c008

void Unwind_1001c008(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c010 at 1001c010

void Unwind_1001c010(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c013. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001c019 at 1001c019

void Unwind_1001c019(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c021 at 1001c021

void Unwind_1001c021(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c029 at 1001c029

void Unwind_1001c029(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c031 at 1001c031

void Unwind_1001c031(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c060 at 1001c060

void Unwind_1001c060(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c068 at 1001c068

void Unwind_1001c068(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c070 at 1001c070

void Unwind_1001c070(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c078 at 1001c078

void Unwind_1001c078(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c080 at 1001c080

void Unwind_1001c080(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c083. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001c089 at 1001c089

void Unwind_1001c089(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c091 at 1001c091

void Unwind_1001c091(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c099 at 1001c099

void Unwind_1001c099(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c0a1 at 1001c0a1

void Unwind_1001c0a1(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c0d0 at 1001c0d0

void Unwind_1001c0d0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c0d8 at 1001c0d8

void Unwind_1001c0d8(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001c0e0 at 1001c0e0

void Unwind_1001c0e0(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001c0e8 at 1001c0e8

void Unwind_1001c0e8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c0f0 at 1001c0f0

void Unwind_1001c0f0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c0f8 at 1001c0f8

void Unwind_1001c0f8(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c100 at 1001c100

void Unwind_1001c100(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c10c at 1001c10c

void Unwind_1001c10c(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c114 at 1001c114

void Unwind_1001c114(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c11c at 1001c11c

void Unwind_1001c11c(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c124 at 1001c124

void Unwind_1001c124(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c160 at 1001c160

void Unwind_1001c160(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c168 at 1001c168

void Unwind_1001c168(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001c170 at 1001c170

void Unwind_1001c170(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001c178 at 1001c178

void Unwind_1001c178(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001c180 at 1001c180

void Unwind_1001c180(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c18b at 1001c18b

void Unwind_1001c18b(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c196 at 1001c196

void Unwind_1001c196(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c19e at 1001c19e

void Unwind_1001c19e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001c1aa at 1001c1aa

void Unwind_1001c1aa(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c1b5 at 1001c1b5

void Unwind_1001c1b5(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c1bd at 1001c1bd

void Unwind_1001c1bd(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c1c8 at 1001c1c8

void Unwind_1001c1c8(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c200 at 1001c200

void Unwind_1001c200(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001c20b at 1001c20b

void Unwind_1001c20b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001c213 at 1001c213

void Unwind_1001c213(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001c21b at 1001c21b

void Unwind_1001c21b(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c223 at 1001c223

void Unwind_1001c223(void)

{
  int unaff_EBP;
  
  FUN_10010920(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@1001c22b at 1001c22b

void Unwind_1001c22b(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c233 at 1001c233

void Unwind_1001c233(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c23b at 1001c23b

void Unwind_1001c23b(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c243 at 1001c243

void Unwind_1001c243(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c249. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001c24f at 1001c24f

void Unwind_1001c24f(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c257 at 1001c257

void Unwind_1001c257(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c25f at 1001c25f

void Unwind_1001c25f(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c267 at 1001c267

void Unwind_1001c267(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c2a0 at 1001c2a0

void Unwind_1001c2a0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c2a8 at 1001c2a8

void Unwind_1001c2a8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c2b0 at 1001c2b0

void Unwind_1001c2b0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c2b8 at 1001c2b8

void Unwind_1001c2b8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c2c0 at 1001c2c0

void Unwind_1001c2c0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c2c8 at 1001c2c8

void Unwind_1001c2c8(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c2d0 at 1001c2d0

void Unwind_1001c2d0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c2d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c2dc at 1001c2dc

void Unwind_1001c2dc(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c2e4 at 1001c2e4

void Unwind_1001c2e4(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c2ec at 1001c2ec

void Unwind_1001c2ec(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001c2f4 at 1001c2f4

void Unwind_1001c2f4(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c330 at 1001c330

void Unwind_1001c330(void)

{
  int unaff_EBP;
  
  FUN_10010980((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001c338 at 1001c338

void Unwind_1001c338(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c340 at 1001c340

void Unwind_1001c340(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001c348 at 1001c348

void Unwind_1001c348(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001c353 at 1001c353

void Unwind_1001c353(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c35b at 1001c35b

void Unwind_1001c35b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c361. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1001c367 at 1001c367

void Unwind_1001c367(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001c372 at 1001c372

void Unwind_1001c372(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c37a at 1001c37a

void Unwind_1001c37a(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001c385 at 1001c385

void Unwind_1001c385(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c3c0 at 1001c3c0

void Unwind_1001c3c0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c3c8 at 1001c3c8

void Unwind_1001c3c8(void)

{
  int unaff_EBP;
  
  FUN_10016c40(*(int **)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001c3d0 at 1001c3d0

void Unwind_1001c3d0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c3d8 at 1001c3d8

void Unwind_1001c3d8(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c3e0 at 1001c3e0

void Unwind_1001c3e0(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c3e8 at 1001c3e8

void Unwind_1001c3e8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c3ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c3f4 at 1001c3f4

void Unwind_1001c3f4(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c3fc at 1001c3fc

void Unwind_1001c3fc(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c404 at 1001c404

void Unwind_1001c404(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c40c at 1001c40c

void Unwind_1001c40c(void)

{
  int unaff_EBP;
  
  FUN_10004f30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c440 at 1001c440

void Unwind_1001c440(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001210(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c480 at 1001c480

void Unwind_1001c480(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c4c0 at 1001c4c0

void Unwind_1001c4c0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c4c8 at 1001c4c8

void Unwind_1001c4c8(void)

{
  int unaff_EBP;
  
  FUN_1000aa20((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c4d0 at 1001c4d0

void Unwind_1001c4d0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c4d8 at 1001c4d8

void Unwind_1001c4d8(void)

{
  int unaff_EBP;
  
  FUN_1000aaa0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c4e0 at 1001c4e0

void Unwind_1001c4e0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c510 at 1001c510

void Unwind_1001c510(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c540 at 1001c540

void Unwind_1001c540(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c570 at 1001c570

void Unwind_1001c570(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c578 at 1001c578

void Unwind_1001c578(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001c5a0 at 1001c5a0

void Unwind_1001c5a0(void)

{
  int unaff_EBP;
  
  FUN_1000aa20((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001c5ab at 1001c5ab

void Unwind_1001c5ab(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001c5b6 at 1001c5b6

void Unwind_1001c5b6(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001c5c1 at 1001c5c1

void Unwind_1001c5c1(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001c5cc at 1001c5cc

void Unwind_1001c5cc(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@1001c5d7 at 1001c5d7

void Unwind_1001c5d7(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001c5e2 at 1001c5e2

void Unwind_1001c5e2(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001c5ed at 1001c5ed

void Unwind_1001c5ed(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5f5 at 1001c5f5

void Unwind_1001c5f5(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c5fd at 1001c5fd

void Unwind_1001c5fd(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c605 at 1001c605

void Unwind_1001c605(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c60d at 1001c60d

void Unwind_1001c60d(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c618 at 1001c618

void Unwind_1001c618(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c620 at 1001c620

void Unwind_1001c620(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001c62b at 1001c62b

void Unwind_1001c62b(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c650 at 1001c650

void Unwind_1001c650(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c658 at 1001c658

void Unwind_1001c658(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000a9a0(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c690 at 1001c690

void Unwind_1001c690(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c698 at 1001c698

void Unwind_1001c698(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c6a0 at 1001c6a0

void Unwind_1001c6a0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c6a8 at 1001c6a8

void Unwind_1001c6a8(void)

{
  int unaff_EBP;
  
  FUN_1000aaa0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c6b0 at 1001c6b0

void Unwind_1001c6b0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c6b8 at 1001c6b8

void Unwind_1001c6b8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c6c0 at 1001c6c0

void Unwind_1001c6c0(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001c6c8 at 1001c6c8

void Unwind_1001c6c8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c6d0 at 1001c6d0

void Unwind_1001c6d0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c6d8 at 1001c6d8

void Unwind_1001c6d8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c6e0 at 1001c6e0

void Unwind_1001c6e0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c6e8 at 1001c6e8

void Unwind_1001c6e8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c6f0 at 1001c6f0

void Unwind_1001c6f0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c6f8 at 1001c6f8

void Unwind_1001c6f8(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c700 at 1001c700

void Unwind_1001c700(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c708 at 1001c708

void Unwind_1001c708(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c710 at 1001c710

void Unwind_1001c710(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c718 at 1001c718

void Unwind_1001c718(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c720 at 1001c720

void Unwind_1001c720(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c728 at 1001c728

void Unwind_1001c728(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c730 at 1001c730

void Unwind_1001c730(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c760 at 1001c760

void Unwind_1001c760(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c768 at 1001c768

void Unwind_1001c768(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1001c770 at 1001c770

void Unwind_1001c770(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100047c0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c7b0 at 1001c7b0

void Unwind_1001c7b0(void)

{
  int unaff_EBP;
  
  FUN_100026b0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c7b8 at 1001c7b8

void Unwind_1001c7b8(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001c7e0 at 1001c7e0

void Unwind_1001c7e0(void)

{
  int unaff_EBP;
  
  FUN_1000aa20((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 8));
  return;
}



// Function: Unwind@1001c7eb at 1001c7eb

void Unwind_1001c7eb(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c7f3 at 1001c7f3

void Unwind_1001c7f3(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@1001c7fe at 1001c7fe

void Unwind_1001c7fe(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 0x10));
  return;
}



// Function: Unwind@1001c809 at 1001c809

void Unwind_1001c809(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(*(int *)(unaff_EBP + -0x60) + 0x18));
  return;
}



// Function: Unwind@1001c814 at 1001c814

void Unwind_1001c814(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c81c at 1001c81c

void Unwind_1001c81c(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x60) + 0x1c));
  return;
}



// Function: Unwind@1001c827 at 1001c827

void Unwind_1001c827(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c82f at 1001c82f

void Unwind_1001c82f(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x60) + 0x20));
  return;
}



// Function: Unwind@1001c83a at 1001c83a

void Unwind_1001c83a(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c842 at 1001c842

void Unwind_1001c842(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x60) + 0x24));
  return;
}



// Function: Unwind@1001c84d at 1001c84d

void Unwind_1001c84d(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c855 at 1001c855

void Unwind_1001c855(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(*(int *)(unaff_EBP + -0x60) + 0x28));
  return;
}



// Function: Unwind@1001c860 at 1001c860

void Unwind_1001c860(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c868 at 1001c868

void Unwind_1001c868(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001c870 at 1001c870

void Unwind_1001c870(void)

{
  int unaff_EBP;
  
  FUN_1000ba20((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c878 at 1001c878

void Unwind_1001c878(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c880 at 1001c880

void Unwind_1001c880(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c888 at 1001c888

void Unwind_1001c888(void)

{
  int unaff_EBP;
  
  FUN_1000aaa0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c890 at 1001c890

void Unwind_1001c890(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c898 at 1001c898

void Unwind_1001c898(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001c8a0 at 1001c8a0

void Unwind_1001c8a0(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c8a8 at 1001c8a8

void Unwind_1001c8a8(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c8b0 at 1001c8b0

void Unwind_1001c8b0(void)

{
  int unaff_EBP;
  
  FUN_10016c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c8e0 at 1001c8e0

void Unwind_1001c8e0(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c8e8 at 1001c8e8

void Unwind_1001c8e8(void)

{
  int unaff_EBP;
  
  FUN_1000ab20((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c8f0 at 1001c8f0

void Unwind_1001c8f0(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001c8f8 at 1001c8f8

void Unwind_1001c8f8(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c930 at 1001c930

void Unwind_1001c930(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c938 at 1001c938

void Unwind_1001c938(void)

{
  int unaff_EBP;
  
  FUN_1000ab20((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001c940 at 1001c940

void Unwind_1001c940(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001c948 at 1001c948

void Unwind_1001c948(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c950 at 1001c950

void Unwind_1001c950(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001c958 at 1001c958

void Unwind_1001c958(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c990 at 1001c990

void Unwind_1001c990(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c998 at 1001c998

void Unwind_1001c998(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c9c0 at 1001c9c0

void Unwind_1001c9c0(void)

{
  int unaff_EBP;
  
  FUN_10001210((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c9c8 at 1001c9c8

void Unwind_1001c9c8(void)

{
  int unaff_EBP;
  
  FUN_10001210(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c9f0 at 1001c9f0

void Unwind_1001c9f0(void)

{
  int unaff_EBP;
  
  FUN_10016c30((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001c9f8 at 1001c9f8

void Unwind_1001c9f8(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ca00 at 1001ca00

void Unwind_1001ca00(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ca30 at 1001ca30

void Unwind_1001ca30(void)

{
  int unaff_EBP;
  
  FUN_1000a9a0(unaff_EBP + 0xc);
  return;
}



// Function: Unwind@1001ca38 at 1001ca38

void Unwind_1001ca38(void)

{
  int unaff_EBP;
  
  FUN_100047c0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ca40 at 1001ca40

void Unwind_1001ca40(void)

{
  int unaff_EBP;
  
  FUN_10016c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ca48 at 1001ca48

void Unwind_1001ca48(void)

{
  int unaff_EBP;
  
  FUN_10016c30(*(int **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ca80 at 1001ca80

void Unwind_1001ca80(void)

{
  int unaff_EBP;
  
  FUN_10010d80((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001cab0 at 1001cab0

void Unwind_1001cab0(void)

{
  int unaff_EBP;
  
  FUN_10010d80((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cad3 at 1001cad3

void Unwind_1001cad3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001cad6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1001d530 at 1001d530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d530(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a2b4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002ed0(0x1003455c);
  _DAT_1003455c = ATL::CComModule::vftable;
  _DAT_10034524 = &DAT_1003455c;
  local_8 = 0xffffffff;
  _atexit(FUN_1001f4a0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f410 at 1001f410

void FUN_1001f410(void)

{
  Ordinal_6(DAT_10034530);
  return;
}



// Function: FUN_1001f420 at 1001f420

void FUN_1001f420(void)

{
  Ordinal_6(DAT_10034534);
  return;
}



// Function: FUN_1001f430 at 1001f430

void FUN_1001f430(void)

{
  Ordinal_6(DAT_10034538);
  return;
}



// Function: FUN_1001f440 at 1001f440

void FUN_1001f440(void)

{
  Ordinal_6(DAT_1003453c);
  return;
}



// Function: FUN_1001f450 at 1001f450

void FUN_1001f450(void)

{
  Ordinal_6(DAT_10034540);
  return;
}



// Function: FUN_1001f460 at 1001f460

void FUN_1001f460(void)

{
  Ordinal_6(DAT_10034544);
  return;
}



// Function: FUN_1001f470 at 1001f470

void FUN_1001f470(void)

{
  Ordinal_6(DAT_10034548);
  return;
}



// Function: FUN_1001f480 at 1001f480

void FUN_1001f480(void)

{
  Ordinal_6(DAT_1003454c);
  return;
}



// Function: FUN_1001f490 at 1001f490

void FUN_1001f490(void)

{
  Ordinal_6(DAT_10034550);
  return;
}



// Function: FUN_1001f4a0 at 1001f4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f4a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2e4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_1003455c = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_10034560 != 0) {
    if (DAT_10034568 != 0) {
      Ordinal_64(&DAT_10034560,DAT_100344b0 ^ (uint)&stack0xfffffffc);
      DAT_10034568 = 0;
    }
    if (DAT_10034584 != (int *)0x0) {
      (**(code **)(*DAT_10034584 + 8))(DAT_10034584);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1003456c);
    DAT_10034560 = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f530 at 1001f530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f530(void)

{
  if (7 < DAT_100311e0) {
    operator_delete(DAT_100311cc);
  }
  DAT_100311e0 = 7;
  _DAT_100311dc = 0;
  DAT_100311cc = (void *)((uint)DAT_100311cc & 0xffff0000);
  return;
}



// Function: FUN_1001f570 at 1001f570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f570(void)

{
  if (7 < DAT_100311fc) {
    operator_delete(DAT_100311e8);
  }
  DAT_100311fc = 7;
  _DAT_100311f8 = 0;
  DAT_100311e8 = (void *)((uint)DAT_100311e8 & 0xffff0000);
  return;
}



// Function: FUN_1001f5b0 at 1001f5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f5b0(void)

{
  if (7 < DAT_10031218) {
    operator_delete(DAT_10031204);
  }
  DAT_10031218 = 7;
  _DAT_10031214 = 0;
  DAT_10031204 = (void *)((uint)DAT_10031204 & 0xffff0000);
  return;
}



// Function: FUN_1001f5f0 at 1001f5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f5f0(void)

{
  if (7 < DAT_10031234) {
    operator_delete(DAT_10031220);
  }
  DAT_10031234 = 7;
  _DAT_10031230 = 0;
  DAT_10031220 = (void *)((uint)DAT_10031220 & 0xffff0000);
  return;
}



// Function: FUN_1001f630 at 1001f630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f630(void)

{
  if (7 < DAT_100312d8) {
    operator_delete(DAT_100312c4);
  }
  DAT_100312d8 = 7;
  _DAT_100312d4 = 0;
  DAT_100312c4 = (void *)((uint)DAT_100312c4 & 0xffff0000);
  return;
}



// Function: FUN_1001f670 at 1001f670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f670(void)

{
  if (7 < DAT_100312f4) {
    operator_delete(DAT_100312e0);
  }
  DAT_100312f4 = 7;
  _DAT_100312f0 = 0;
  DAT_100312e0 = (void *)((uint)DAT_100312e0 & 0xffff0000);
  return;
}



// Function: FUN_1001f6b0 at 1001f6b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f6b0(void)

{
  if (7 < DAT_10031310) {
    operator_delete(DAT_100312fc);
  }
  DAT_10031310 = 7;
  _DAT_1003130c = 0;
  DAT_100312fc = (void *)((uint)DAT_100312fc & 0xffff0000);
  return;
}



// Function: FUN_1001f6f0 at 1001f6f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f6f0(void)

{
  if (7 < DAT_1003132c) {
    operator_delete(DAT_10031318);
  }
  DAT_1003132c = 7;
  _DAT_10031328 = 0;
  DAT_10031318 = (void *)((uint)DAT_10031318 & 0xffff0000);
  return;
}



// Function: FUN_1001f730 at 1001f730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f730(void)

{
  if (7 < DAT_10031348) {
    operator_delete(DAT_10031334);
  }
  DAT_10031348 = 7;
  _DAT_10031344 = 0;
  DAT_10031334 = (void *)((uint)DAT_10031334 & 0xffff0000);
  return;
}



// Function: FUN_1001f770 at 1001f770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f770(void)

{
  if (7 < DAT_10031364) {
    operator_delete(DAT_10031350);
  }
  DAT_10031364 = 7;
  _DAT_10031360 = 0;
  DAT_10031350 = (void *)((uint)DAT_10031350 & 0xffff0000);
  return;
}



// Function: FUN_1001f7b0 at 1001f7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f7b0(void)

{
  if (7 < DAT_10031380) {
    operator_delete(DAT_1003136c);
  }
  DAT_10031380 = 7;
  _DAT_1003137c = 0;
  DAT_1003136c = (void *)((uint)DAT_1003136c & 0xffff0000);
  return;
}



// Function: FUN_1001f7f0 at 1001f7f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f7f0(void)

{
  if (7 < DAT_1003139c) {
    operator_delete(DAT_10031388);
  }
  DAT_1003139c = 7;
  _DAT_10031398 = 0;
  DAT_10031388 = (void *)((uint)DAT_10031388 & 0xffff0000);
  return;
}



// Function: FUN_1001f830 at 1001f830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f830(void)

{
  if (7 < DAT_100313b8) {
    operator_delete(DAT_100313a4);
  }
  DAT_100313b8 = 7;
  _DAT_100313b4 = 0;
  DAT_100313a4 = (void *)((uint)DAT_100313a4 & 0xffff0000);
  return;
}



// Function: FUN_1001f870 at 1001f870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f870(void)

{
  if (7 < DAT_100313d4) {
    operator_delete(DAT_100313c0);
  }
  DAT_100313d4 = 7;
  _DAT_100313d0 = 0;
  DAT_100313c0 = (void *)((uint)DAT_100313c0 & 0xffff0000);
  return;
}



// Function: FUN_1001f8b0 at 1001f8b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f8b0(void)

{
  if (7 < DAT_100313f0) {
    operator_delete(DAT_100313dc);
  }
  DAT_100313f0 = 7;
  _DAT_100313ec = 0;
  DAT_100313dc = (void *)((uint)DAT_100313dc & 0xffff0000);
  return;
}



// Function: FUN_1001f8f0 at 1001f8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f8f0(void)

{
  if (7 < DAT_1003140c) {
    operator_delete(DAT_100313f8);
  }
  DAT_1003140c = 7;
  _DAT_10031408 = 0;
  DAT_100313f8 = (void *)((uint)DAT_100313f8 & 0xffff0000);
  return;
}



// Function: FUN_1001f930 at 1001f930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f930(void)

{
  if (7 < DAT_10031428) {
    operator_delete(DAT_10031414);
  }
  DAT_10031428 = 7;
  _DAT_10031424 = 0;
  DAT_10031414 = (void *)((uint)DAT_10031414 & 0xffff0000);
  return;
}



// Function: FUN_1001f970 at 1001f970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f970(void)

{
  if (7 < DAT_10031444) {
    operator_delete(DAT_10031430);
  }
  DAT_10031444 = 7;
  _DAT_10031440 = 0;
  DAT_10031430 = (void *)((uint)DAT_10031430 & 0xffff0000);
  return;
}



// Function: FUN_1001f9b0 at 1001f9b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f9b0(void)

{
  if (7 < DAT_10031460) {
    operator_delete(DAT_1003144c);
  }
  DAT_10031460 = 7;
  _DAT_1003145c = 0;
  DAT_1003144c = (void *)((uint)DAT_1003144c & 0xffff0000);
  return;
}



// Function: FUN_1001f9f0 at 1001f9f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f9f0(void)

{
  if (7 < DAT_1003147c) {
    operator_delete(DAT_10031468);
  }
  DAT_1003147c = 7;
  _DAT_10031478 = 0;
  DAT_10031468 = (void *)((uint)DAT_10031468 & 0xffff0000);
  return;
}



// Function: FUN_1001fa30 at 1001fa30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fa30(void)

{
  if (7 < DAT_10031498) {
    operator_delete(DAT_10031484);
  }
  DAT_10031498 = 7;
  _DAT_10031494 = 0;
  DAT_10031484 = (void *)((uint)DAT_10031484 & 0xffff0000);
  return;
}



// Function: FUN_1001fa70 at 1001fa70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fa70(void)

{
  if (7 < DAT_100314b4) {
    operator_delete(DAT_100314a0);
  }
  DAT_100314b4 = 7;
  _DAT_100314b0 = 0;
  DAT_100314a0 = (void *)((uint)DAT_100314a0 & 0xffff0000);
  return;
}



// Function: FUN_1001fab0 at 1001fab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fab0(void)

{
  if (7 < DAT_100314d0) {
    operator_delete(DAT_100314bc);
  }
  DAT_100314d0 = 7;
  _DAT_100314cc = 0;
  DAT_100314bc = (void *)((uint)DAT_100314bc & 0xffff0000);
  return;
}



// Function: FUN_1001faf0 at 1001faf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001faf0(void)

{
  if (7 < DAT_100314ec) {
    operator_delete(DAT_100314d8);
  }
  DAT_100314ec = 7;
  _DAT_100314e8 = 0;
  DAT_100314d8 = (void *)((uint)DAT_100314d8 & 0xffff0000);
  return;
}



// Function: FUN_1001fb30 at 1001fb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fb30(void)

{
  if (7 < DAT_10031508) {
    operator_delete(DAT_100314f4);
  }
  DAT_10031508 = 7;
  _DAT_10031504 = 0;
  DAT_100314f4 = (void *)((uint)DAT_100314f4 & 0xffff0000);
  return;
}



// Function: FUN_1001fb70 at 1001fb70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fb70(void)

{
  if (7 < DAT_10031524) {
    operator_delete(DAT_10031510);
  }
  DAT_10031524 = 7;
  _DAT_10031520 = 0;
  DAT_10031510 = (void *)((uint)DAT_10031510 & 0xffff0000);
  return;
}



// Function: FUN_1001fbb0 at 1001fbb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fbb0(void)

{
  if (7 < DAT_10031540) {
    operator_delete(DAT_1003152c);
  }
  DAT_10031540 = 7;
  _DAT_1003153c = 0;
  DAT_1003152c = (void *)((uint)DAT_1003152c & 0xffff0000);
  return;
}



// Function: FUN_1001fbf0 at 1001fbf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fbf0(void)

{
  if (7 < DAT_1003155c) {
    operator_delete(DAT_10031548);
  }
  DAT_1003155c = 7;
  _DAT_10031558 = 0;
  DAT_10031548 = (void *)((uint)DAT_10031548 & 0xffff0000);
  return;
}



// Function: FUN_1001fc30 at 1001fc30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fc30(void)

{
  if (7 < DAT_10031578) {
    operator_delete(DAT_10031564);
  }
  DAT_10031578 = 7;
  _DAT_10031574 = 0;
  DAT_10031564 = (void *)((uint)DAT_10031564 & 0xffff0000);
  return;
}



// Function: FUN_1001fc70 at 1001fc70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fc70(void)

{
  if (7 < DAT_10031594) {
    operator_delete(DAT_10031580);
  }
  DAT_10031594 = 7;
  _DAT_10031590 = 0;
  DAT_10031580 = (void *)((uint)DAT_10031580 & 0xffff0000);
  return;
}



// Function: FUN_1001fcb0 at 1001fcb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fcb0(void)

{
  if (7 < DAT_100315b0) {
    operator_delete(DAT_1003159c);
  }
  DAT_100315b0 = 7;
  _DAT_100315ac = 0;
  DAT_1003159c = (void *)((uint)DAT_1003159c & 0xffff0000);
  return;
}



// Function: FUN_1001fcf0 at 1001fcf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fcf0(void)

{
  if (7 < DAT_100315cc) {
    operator_delete(DAT_100315b8);
  }
  DAT_100315cc = 7;
  _DAT_100315c8 = 0;
  DAT_100315b8 = (void *)((uint)DAT_100315b8 & 0xffff0000);
  return;
}



// Function: FUN_1001fd30 at 1001fd30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd30(void)

{
  if (7 < DAT_100315e8) {
    operator_delete(DAT_100315d4);
  }
  DAT_100315e8 = 7;
  _DAT_100315e4 = 0;
  DAT_100315d4 = (void *)((uint)DAT_100315d4 & 0xffff0000);
  return;
}



// Function: FUN_1001fd70 at 1001fd70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd70(void)

{
  if (7 < DAT_10031604) {
    operator_delete(DAT_100315f0);
  }
  DAT_10031604 = 7;
  _DAT_10031600 = 0;
  DAT_100315f0 = (void *)((uint)DAT_100315f0 & 0xffff0000);
  return;
}



// Function: FUN_1001fdb0 at 1001fdb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fdb0(void)

{
  if (7 < DAT_10031620) {
    operator_delete(DAT_1003160c);
  }
  DAT_10031620 = 7;
  _DAT_1003161c = 0;
  DAT_1003160c = (void *)((uint)DAT_1003160c & 0xffff0000);
  return;
}



// Function: FUN_1001fdf0 at 1001fdf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fdf0(void)

{
  if (7 < DAT_1003163c) {
    operator_delete(DAT_10031628);
  }
  DAT_1003163c = 7;
  _DAT_10031638 = 0;
  DAT_10031628 = (void *)((uint)DAT_10031628 & 0xffff0000);
  return;
}



// Function: FUN_1001fe30 at 1001fe30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe30(void)

{
  if (7 < DAT_10031658) {
    operator_delete(DAT_10031644);
  }
  DAT_10031658 = 7;
  _DAT_10031654 = 0;
  DAT_10031644 = (void *)((uint)DAT_10031644 & 0xffff0000);
  return;
}



// Function: FUN_1001fe70 at 1001fe70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe70(void)

{
  if (7 < DAT_10031674) {
    operator_delete(DAT_10031660);
  }
  DAT_10031674 = 7;
  _DAT_10031670 = 0;
  DAT_10031660 = (void *)((uint)DAT_10031660 & 0xffff0000);
  return;
}



// Function: FUN_1001feb0 at 1001feb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001feb0(void)

{
  if (7 < DAT_10031690) {
    operator_delete(DAT_1003167c);
  }
  DAT_10031690 = 7;
  _DAT_1003168c = 0;
  DAT_1003167c = (void *)((uint)DAT_1003167c & 0xffff0000);
  return;
}



// Function: FUN_1001fef0 at 1001fef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fef0(void)

{
  if (7 < DAT_100316ac) {
    operator_delete(DAT_10031698);
  }
  DAT_100316ac = 7;
  _DAT_100316a8 = 0;
  DAT_10031698 = (void *)((uint)DAT_10031698 & 0xffff0000);
  return;
}



// Function: FUN_1001ff30 at 1001ff30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff30(void)

{
  if (7 < DAT_100316c8) {
    operator_delete(DAT_100316b4);
  }
  DAT_100316c8 = 7;
  _DAT_100316c4 = 0;
  DAT_100316b4 = (void *)((uint)DAT_100316b4 & 0xffff0000);
  return;
}



// Function: FUN_1001ff70 at 1001ff70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff70(void)

{
  if (7 < DAT_100316e4) {
    operator_delete(DAT_100316d0);
  }
  DAT_100316e4 = 7;
  _DAT_100316e0 = 0;
  DAT_100316d0 = (void *)((uint)DAT_100316d0 & 0xffff0000);
  return;
}



// Function: FUN_1001ffb0 at 1001ffb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ffb0(void)

{
  if (7 < DAT_10031700) {
    operator_delete(DAT_100316ec);
  }
  DAT_10031700 = 7;
  _DAT_100316fc = 0;
  DAT_100316ec = (void *)((uint)DAT_100316ec & 0xffff0000);
  return;
}



// Function: FUN_1001fff0 at 1001fff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fff0(void)

{
  if (7 < DAT_1003171c) {
    operator_delete(DAT_10031708);
  }
  DAT_1003171c = 7;
  _DAT_10031718 = 0;
  DAT_10031708 = (void *)((uint)DAT_10031708 & 0xffff0000);
  return;
}



// Function: FUN_10020030 at 10020030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020030(void)

{
  if (7 < DAT_10031738) {
    operator_delete(DAT_10031724);
  }
  DAT_10031738 = 7;
  _DAT_10031734 = 0;
  DAT_10031724 = (void *)((uint)DAT_10031724 & 0xffff0000);
  return;
}



// Function: FUN_10020070 at 10020070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020070(void)

{
  if (7 < DAT_10031754) {
    operator_delete(DAT_10031740);
  }
  DAT_10031754 = 7;
  _DAT_10031750 = 0;
  DAT_10031740 = (void *)((uint)DAT_10031740 & 0xffff0000);
  return;
}



// Function: FUN_100200b0 at 100200b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200b0(void)

{
  if (7 < DAT_10031770) {
    operator_delete(DAT_1003175c);
  }
  DAT_10031770 = 7;
  _DAT_1003176c = 0;
  DAT_1003175c = (void *)((uint)DAT_1003175c & 0xffff0000);
  return;
}



// Function: FUN_100200f0 at 100200f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200f0(void)

{
  if (7 < DAT_1003178c) {
    operator_delete(DAT_10031778);
  }
  DAT_1003178c = 7;
  _DAT_10031788 = 0;
  DAT_10031778 = (void *)((uint)DAT_10031778 & 0xffff0000);
  return;
}



// Function: FUN_10020130 at 10020130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020130(void)

{
  if (7 < DAT_100317a8) {
    operator_delete(DAT_10031794);
  }
  DAT_100317a8 = 7;
  _DAT_100317a4 = 0;
  DAT_10031794 = (void *)((uint)DAT_10031794 & 0xffff0000);
  return;
}



// Function: FUN_10020170 at 10020170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020170(void)

{
  if (7 < DAT_100317c4) {
    operator_delete(DAT_100317b0);
  }
  DAT_100317c4 = 7;
  _DAT_100317c0 = 0;
  DAT_100317b0 = (void *)((uint)DAT_100317b0 & 0xffff0000);
  return;
}



// Function: FUN_100201b0 at 100201b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100201b0(void)

{
  if (7 < DAT_100317e0) {
    operator_delete(DAT_100317cc);
  }
  DAT_100317e0 = 7;
  _DAT_100317dc = 0;
  DAT_100317cc = (void *)((uint)DAT_100317cc & 0xffff0000);
  return;
}



// Function: FUN_100201f0 at 100201f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100201f0(void)

{
  if (7 < DAT_100317fc) {
    operator_delete(DAT_100317e8);
  }
  DAT_100317fc = 7;
  _DAT_100317f8 = 0;
  DAT_100317e8 = (void *)((uint)DAT_100317e8 & 0xffff0000);
  return;
}



// Function: FUN_10020230 at 10020230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020230(void)

{
  if (7 < DAT_10031818) {
    operator_delete(DAT_10031804);
  }
  DAT_10031818 = 7;
  _DAT_10031814 = 0;
  DAT_10031804 = (void *)((uint)DAT_10031804 & 0xffff0000);
  return;
}



// Function: FUN_10020270 at 10020270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020270(void)

{
  if (7 < DAT_10031834) {
    operator_delete(DAT_10031820);
  }
  DAT_10031834 = 7;
  _DAT_10031830 = 0;
  DAT_10031820 = (void *)((uint)DAT_10031820 & 0xffff0000);
  return;
}



// Function: FUN_100202b0 at 100202b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100202b0(void)

{
  if (7 < DAT_10031850) {
    operator_delete(DAT_1003183c);
  }
  DAT_10031850 = 7;
  _DAT_1003184c = 0;
  DAT_1003183c = (void *)((uint)DAT_1003183c & 0xffff0000);
  return;
}



// Function: FUN_100202f0 at 100202f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100202f0(void)

{
  if (7 < DAT_1003186c) {
    operator_delete(DAT_10031858);
  }
  DAT_1003186c = 7;
  _DAT_10031868 = 0;
  DAT_10031858 = (void *)((uint)DAT_10031858 & 0xffff0000);
  return;
}



// Function: FUN_10020330 at 10020330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020330(void)

{
  if (7 < DAT_10031888) {
    operator_delete(DAT_10031874);
  }
  DAT_10031888 = 7;
  _DAT_10031884 = 0;
  DAT_10031874 = (void *)((uint)DAT_10031874 & 0xffff0000);
  return;
}



// Function: FUN_10020370 at 10020370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020370(void)

{
  if (7 < DAT_100318a4) {
    operator_delete(DAT_10031890);
  }
  DAT_100318a4 = 7;
  _DAT_100318a0 = 0;
  DAT_10031890 = (void *)((uint)DAT_10031890 & 0xffff0000);
  return;
}



// Function: FUN_100203b0 at 100203b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100203b0(void)

{
  if (7 < DAT_100318c0) {
    operator_delete(DAT_100318ac);
  }
  DAT_100318c0 = 7;
  _DAT_100318bc = 0;
  DAT_100318ac = (void *)((uint)DAT_100318ac & 0xffff0000);
  return;
}



// Function: FUN_100203f0 at 100203f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100203f0(void)

{
  if (7 < DAT_100318dc) {
    operator_delete(DAT_100318c8);
  }
  DAT_100318dc = 7;
  _DAT_100318d8 = 0;
  DAT_100318c8 = (void *)((uint)DAT_100318c8 & 0xffff0000);
  return;
}



// Function: FUN_10020430 at 10020430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020430(void)

{
  if (7 < DAT_100318f8) {
    operator_delete(DAT_100318e4);
  }
  DAT_100318f8 = 7;
  _DAT_100318f4 = 0;
  DAT_100318e4 = (void *)((uint)DAT_100318e4 & 0xffff0000);
  return;
}



// Function: FUN_10020470 at 10020470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020470(void)

{
  if (7 < DAT_10031914) {
    operator_delete(DAT_10031900);
  }
  DAT_10031914 = 7;
  _DAT_10031910 = 0;
  DAT_10031900 = (void *)((uint)DAT_10031900 & 0xffff0000);
  return;
}



// Function: FUN_100204b0 at 100204b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100204b0(void)

{
  if (7 < DAT_10031930) {
    operator_delete(DAT_1003191c);
  }
  DAT_10031930 = 7;
  _DAT_1003192c = 0;
  DAT_1003191c = (void *)((uint)DAT_1003191c & 0xffff0000);
  return;
}



// Function: FUN_100204f0 at 100204f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100204f0(void)

{
  if (7 < DAT_1003194c) {
    operator_delete(DAT_10031938);
  }
  DAT_1003194c = 7;
  _DAT_10031948 = 0;
  DAT_10031938 = (void *)((uint)DAT_10031938 & 0xffff0000);
  return;
}



// Function: FUN_10020530 at 10020530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020530(void)

{
  if (7 < DAT_10031968) {
    operator_delete(DAT_10031954);
  }
  DAT_10031968 = 7;
  _DAT_10031964 = 0;
  DAT_10031954 = (void *)((uint)DAT_10031954 & 0xffff0000);
  return;
}



// Function: FUN_10020570 at 10020570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020570(void)

{
  if (7 < DAT_10031984) {
    operator_delete(DAT_10031970);
  }
  DAT_10031984 = 7;
  _DAT_10031980 = 0;
  DAT_10031970 = (void *)((uint)DAT_10031970 & 0xffff0000);
  return;
}



// Function: FUN_100205b0 at 100205b0

void FUN_100205b0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10034554;
  if (DAT_10034554 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10034554 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10034554 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020600 at 10020600

void FUN_10020600(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10034558;
  if (DAT_10034558 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10034558 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10034558 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020650 at 10020650

void FUN_10020650(void)

{
  Ordinal_6(DAT_10034598);
  return;
}



// Function: FUN_10020660 at 10020660

void FUN_10020660(void)

{
  Ordinal_6(DAT_1003459c);
  return;
}



// Function: FUN_10020670 at 10020670

void FUN_10020670(void)

{
  Ordinal_6(DAT_100345a0);
  return;
}



// Function: FUN_10020680 at 10020680

void FUN_10020680(void)

{
  Ordinal_6(DAT_100345a4);
  return;
}



// Function: FUN_10020690 at 10020690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020690(void)

{
  if (7 < DAT_100326a8) {
    operator_delete(DAT_10032694);
  }
  DAT_100326a8 = 7;
  _DAT_100326a4 = 0;
  DAT_10032694 = (void *)((uint)DAT_10032694 & 0xffff0000);
  return;
}



// Function: FUN_100206d0 at 100206d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100206d0(void)

{
  if (7 < DAT_100326c4) {
    operator_delete(DAT_100326b0);
  }
  DAT_100326c4 = 7;
  _DAT_100326c0 = 0;
  DAT_100326b0 = (void *)((uint)DAT_100326b0 & 0xffff0000);
  return;
}



// Function: FUN_10020710 at 10020710

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020710(void)

{
  if (7 < DAT_100326e0) {
    operator_delete(DAT_100326cc);
  }
  DAT_100326e0 = 7;
  _DAT_100326dc = 0;
  DAT_100326cc = (void *)((uint)DAT_100326cc & 0xffff0000);
  return;
}



// Function: FUN_10020750 at 10020750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020750(void)

{
  if (7 < DAT_100326fc) {
    operator_delete(DAT_100326e8);
  }
  DAT_100326fc = 7;
  _DAT_100326f8 = 0;
  DAT_100326e8 = (void *)((uint)DAT_100326e8 & 0xffff0000);
  return;
}



// Function: FUN_10020790 at 10020790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020790(void)

{
  if (7 < DAT_10032718) {
    operator_delete(DAT_10032704);
  }
  DAT_10032718 = 7;
  _DAT_10032714 = 0;
  DAT_10032704 = (void *)((uint)DAT_10032704 & 0xffff0000);
  return;
}



// Function: FUN_100207d0 at 100207d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100207d0(void)

{
  if (7 < DAT_10032734) {
    operator_delete(DAT_10032720);
  }
  DAT_10032734 = 7;
  _DAT_10032730 = 0;
  DAT_10032720 = (void *)((uint)DAT_10032720 & 0xffff0000);
  return;
}



// Function: FUN_10020810 at 10020810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020810(void)

{
  if (7 < DAT_10032750) {
    operator_delete(DAT_1003273c);
  }
  DAT_10032750 = 7;
  _DAT_1003274c = 0;
  DAT_1003273c = (void *)((uint)DAT_1003273c & 0xffff0000);
  return;
}



// Function: FUN_10020850 at 10020850

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020850(void)

{
  if (7 < DAT_1003276c) {
    operator_delete(DAT_10032758);
  }
  DAT_1003276c = 7;
  _DAT_10032768 = 0;
  DAT_10032758 = (void *)((uint)DAT_10032758 & 0xffff0000);
  return;
}



// Function: FUN_10020890 at 10020890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020890(void)

{
  if (7 < DAT_10032788) {
    operator_delete(DAT_10032774);
  }
  DAT_10032788 = 7;
  _DAT_10032784 = 0;
  DAT_10032774 = (void *)((uint)DAT_10032774 & 0xffff0000);
  return;
}



// Function: FUN_100208d0 at 100208d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100208d0(void)

{
  if (7 < DAT_100327a4) {
    operator_delete(DAT_10032790);
  }
  DAT_100327a4 = 7;
  _DAT_100327a0 = 0;
  DAT_10032790 = (void *)((uint)DAT_10032790 & 0xffff0000);
  return;
}



// Function: FUN_10020910 at 10020910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020910(void)

{
  if (7 < DAT_100327c0) {
    operator_delete(DAT_100327ac);
  }
  DAT_100327c0 = 7;
  _DAT_100327bc = 0;
  DAT_100327ac = (void *)((uint)DAT_100327ac & 0xffff0000);
  return;
}



// Function: FUN_10020950 at 10020950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020950(void)

{
  if (7 < DAT_100327dc) {
    operator_delete(DAT_100327c8);
  }
  DAT_100327dc = 7;
  _DAT_100327d8 = 0;
  DAT_100327c8 = (void *)((uint)DAT_100327c8 & 0xffff0000);
  return;
}



// Function: FUN_10020990 at 10020990

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020990(void)

{
  if (7 < DAT_100327f8) {
    operator_delete(DAT_100327e4);
  }
  DAT_100327f8 = 7;
  _DAT_100327f4 = 0;
  DAT_100327e4 = (void *)((uint)DAT_100327e4 & 0xffff0000);
  return;
}



// Function: FUN_100209d0 at 100209d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100209d0(void)

{
  if (7 < DAT_10032814) {
    operator_delete(DAT_10032800);
  }
  DAT_10032814 = 7;
  _DAT_10032810 = 0;
  DAT_10032800 = (void *)((uint)DAT_10032800 & 0xffff0000);
  return;
}



// Function: FUN_10020a10 at 10020a10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020a10(void)

{
  if (7 < DAT_10032830) {
    operator_delete(DAT_1003281c);
  }
  DAT_10032830 = 7;
  _DAT_1003282c = 0;
  DAT_1003281c = (void *)((uint)DAT_1003281c & 0xffff0000);
  return;
}



// Function: FUN_10020a50 at 10020a50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020a50(void)

{
  if (7 < DAT_1003284c) {
    operator_delete(DAT_10032838);
  }
  DAT_1003284c = 7;
  _DAT_10032848 = 0;
  DAT_10032838 = (void *)((uint)DAT_10032838 & 0xffff0000);
  return;
}



// Function: FUN_10020a90 at 10020a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020a90(void)

{
  if (7 < DAT_10032868) {
    operator_delete(DAT_10032854);
  }
  DAT_10032868 = 7;
  _DAT_10032864 = 0;
  DAT_10032854 = (void *)((uint)DAT_10032854 & 0xffff0000);
  return;
}



// Function: FUN_10020ad0 at 10020ad0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020ad0(void)

{
  if (7 < DAT_10032884) {
    operator_delete(DAT_10032870);
  }
  DAT_10032884 = 7;
  _DAT_10032880 = 0;
  DAT_10032870 = (void *)((uint)DAT_10032870 & 0xffff0000);
  return;
}



// Function: FUN_10020b10 at 10020b10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020b10(void)

{
  if (7 < DAT_100328a0) {
    operator_delete(DAT_1003288c);
  }
  DAT_100328a0 = 7;
  _DAT_1003289c = 0;
  DAT_1003288c = (void *)((uint)DAT_1003288c & 0xffff0000);
  return;
}



// Function: FUN_10020b50 at 10020b50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020b50(void)

{
  if (7 < DAT_100328bc) {
    operator_delete(DAT_100328a8);
  }
  DAT_100328bc = 7;
  _DAT_100328b8 = 0;
  DAT_100328a8 = (void *)((uint)DAT_100328a8 & 0xffff0000);
  return;
}



// Function: FUN_10020b90 at 10020b90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020b90(void)

{
  if (7 < DAT_100328d8) {
    operator_delete(DAT_100328c4);
  }
  DAT_100328d8 = 7;
  _DAT_100328d4 = 0;
  DAT_100328c4 = (void *)((uint)DAT_100328c4 & 0xffff0000);
  return;
}



// Function: FUN_10020bd0 at 10020bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020bd0(void)

{
  if (7 < DAT_100328f4) {
    operator_delete(DAT_100328e0);
  }
  DAT_100328f4 = 7;
  _DAT_100328f0 = 0;
  DAT_100328e0 = (void *)((uint)DAT_100328e0 & 0xffff0000);
  return;
}



// Function: FUN_10020c10 at 10020c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020c10(void)

{
  if (7 < DAT_10032910) {
    operator_delete(DAT_100328fc);
  }
  DAT_10032910 = 7;
  _DAT_1003290c = 0;
  DAT_100328fc = (void *)((uint)DAT_100328fc & 0xffff0000);
  return;
}



// Function: FUN_10020c50 at 10020c50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020c50(void)

{
  if (7 < DAT_1003292c) {
    operator_delete(DAT_10032918);
  }
  DAT_1003292c = 7;
  _DAT_10032928 = 0;
  DAT_10032918 = (void *)((uint)DAT_10032918 & 0xffff0000);
  return;
}



// Function: FUN_10020c90 at 10020c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020c90(void)

{
  if (7 < DAT_10032948) {
    operator_delete(DAT_10032934);
  }
  DAT_10032948 = 7;
  _DAT_10032944 = 0;
  DAT_10032934 = (void *)((uint)DAT_10032934 & 0xffff0000);
  return;
}



// Function: FUN_10020cd0 at 10020cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020cd0(void)

{
  if (7 < DAT_10032964) {
    operator_delete(DAT_10032950);
  }
  DAT_10032964 = 7;
  _DAT_10032960 = 0;
  DAT_10032950 = (void *)((uint)DAT_10032950 & 0xffff0000);
  return;
}



// Function: FUN_10020d10 at 10020d10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d10(void)

{
  if (7 < DAT_10032980) {
    operator_delete(DAT_1003296c);
  }
  DAT_10032980 = 7;
  _DAT_1003297c = 0;
  DAT_1003296c = (void *)((uint)DAT_1003296c & 0xffff0000);
  return;
}



// Function: FUN_10020d50 at 10020d50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d50(void)

{
  if (7 < DAT_1003299c) {
    operator_delete(DAT_10032988);
  }
  DAT_1003299c = 7;
  _DAT_10032998 = 0;
  DAT_10032988 = (void *)((uint)DAT_10032988 & 0xffff0000);
  return;
}



// Function: FUN_10020d90 at 10020d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d90(void)

{
  if (7 < DAT_100329b8) {
    operator_delete(DAT_100329a4);
  }
  DAT_100329b8 = 7;
  _DAT_100329b4 = 0;
  DAT_100329a4 = (void *)((uint)DAT_100329a4 & 0xffff0000);
  return;
}



// Function: FUN_10020dd0 at 10020dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020dd0(void)

{
  if (7 < DAT_100329d4) {
    operator_delete(DAT_100329c0);
  }
  DAT_100329d4 = 7;
  _DAT_100329d0 = 0;
  DAT_100329c0 = (void *)((uint)DAT_100329c0 & 0xffff0000);
  return;
}



// Function: FUN_10020e10 at 10020e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020e10(void)

{
  if (7 < DAT_100329f0) {
    operator_delete(DAT_100329dc);
  }
  DAT_100329f0 = 7;
  _DAT_100329ec = 0;
  DAT_100329dc = (void *)((uint)DAT_100329dc & 0xffff0000);
  return;
}



// Function: FUN_10020e50 at 10020e50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020e50(void)

{
  if (7 < DAT_10032a0c) {
    operator_delete(DAT_100329f8);
  }
  DAT_10032a0c = 7;
  _DAT_10032a08 = 0;
  DAT_100329f8 = (void *)((uint)DAT_100329f8 & 0xffff0000);
  return;
}



// Function: FUN_10020e90 at 10020e90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020e90(void)

{
  if (7 < DAT_10032a28) {
    operator_delete(DAT_10032a14);
  }
  DAT_10032a28 = 7;
  _DAT_10032a24 = 0;
  DAT_10032a14 = (void *)((uint)DAT_10032a14 & 0xffff0000);
  return;
}



// Function: FUN_10020ed0 at 10020ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020ed0(void)

{
  if (7 < DAT_10032a44) {
    operator_delete(DAT_10032a30);
  }
  DAT_10032a44 = 7;
  _DAT_10032a40 = 0;
  DAT_10032a30 = (void *)((uint)DAT_10032a30 & 0xffff0000);
  return;
}



// Function: FUN_10020f10 at 10020f10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020f10(void)

{
  if (7 < DAT_10032a60) {
    operator_delete(DAT_10032a4c);
  }
  DAT_10032a60 = 7;
  _DAT_10032a5c = 0;
  DAT_10032a4c = (void *)((uint)DAT_10032a4c & 0xffff0000);
  return;
}



// Function: FUN_10020f50 at 10020f50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020f50(void)

{
  if (7 < DAT_10032a7c) {
    operator_delete(DAT_10032a68);
  }
  DAT_10032a7c = 7;
  _DAT_10032a78 = 0;
  DAT_10032a68 = (void *)((uint)DAT_10032a68 & 0xffff0000);
  return;
}



// Function: FUN_10020f90 at 10020f90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020f90(void)

{
  if (7 < DAT_10032a98) {
    operator_delete(DAT_10032a84);
  }
  DAT_10032a98 = 7;
  _DAT_10032a94 = 0;
  DAT_10032a84 = (void *)((uint)DAT_10032a84 & 0xffff0000);
  return;
}



// Function: FUN_10020fd0 at 10020fd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020fd0(void)

{
  if (7 < DAT_10032ab4) {
    operator_delete(DAT_10032aa0);
  }
  DAT_10032ab4 = 7;
  _DAT_10032ab0 = 0;
  DAT_10032aa0 = (void *)((uint)DAT_10032aa0 & 0xffff0000);
  return;
}



// Function: FUN_10021010 at 10021010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021010(void)

{
  if (7 < DAT_10032ad0) {
    operator_delete(DAT_10032abc);
  }
  DAT_10032ad0 = 7;
  _DAT_10032acc = 0;
  DAT_10032abc = (void *)((uint)DAT_10032abc & 0xffff0000);
  return;
}



// Function: FUN_10021050 at 10021050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021050(void)

{
  if (7 < DAT_10032aec) {
    operator_delete(DAT_10032ad8);
  }
  DAT_10032aec = 7;
  _DAT_10032ae8 = 0;
  DAT_10032ad8 = (void *)((uint)DAT_10032ad8 & 0xffff0000);
  return;
}



// Function: FUN_10021090 at 10021090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021090(void)

{
  if (7 < DAT_10032b08) {
    operator_delete(DAT_10032af4);
  }
  DAT_10032b08 = 7;
  _DAT_10032b04 = 0;
  DAT_10032af4 = (void *)((uint)DAT_10032af4 & 0xffff0000);
  return;
}



// Function: FUN_100210d0 at 100210d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100210d0(void)

{
  if (7 < DAT_10032b24) {
    operator_delete(DAT_10032b10);
  }
  DAT_10032b24 = 7;
  _DAT_10032b20 = 0;
  DAT_10032b10 = (void *)((uint)DAT_10032b10 & 0xffff0000);
  return;
}



// Function: FUN_10021110 at 10021110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021110(void)

{
  if (7 < DAT_10032b40) {
    operator_delete(DAT_10032b2c);
  }
  DAT_10032b40 = 7;
  _DAT_10032b3c = 0;
  DAT_10032b2c = (void *)((uint)DAT_10032b2c & 0xffff0000);
  return;
}



// Function: FUN_10021150 at 10021150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021150(void)

{
  if (7 < DAT_10032b5c) {
    operator_delete(DAT_10032b48);
  }
  DAT_10032b5c = 7;
  _DAT_10032b58 = 0;
  DAT_10032b48 = (void *)((uint)DAT_10032b48 & 0xffff0000);
  return;
}



// Function: FUN_10021190 at 10021190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021190(void)

{
  if (7 < DAT_10032b78) {
    operator_delete(DAT_10032b64);
  }
  DAT_10032b78 = 7;
  _DAT_10032b74 = 0;
  DAT_10032b64 = (void *)((uint)DAT_10032b64 & 0xffff0000);
  return;
}



// Function: FUN_100211d0 at 100211d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100211d0(void)

{
  if (7 < DAT_10032b94) {
    operator_delete(DAT_10032b80);
  }
  DAT_10032b94 = 7;
  _DAT_10032b90 = 0;
  DAT_10032b80 = (void *)((uint)DAT_10032b80 & 0xffff0000);
  return;
}



// Function: FUN_10021210 at 10021210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021210(void)

{
  if (7 < DAT_10032bb0) {
    operator_delete(DAT_10032b9c);
  }
  DAT_10032bb0 = 7;
  _DAT_10032bac = 0;
  DAT_10032b9c = (void *)((uint)DAT_10032b9c & 0xffff0000);
  return;
}



// Function: FUN_10021250 at 10021250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021250(void)

{
  if (7 < DAT_10032bcc) {
    operator_delete(DAT_10032bb8);
  }
  DAT_10032bcc = 7;
  _DAT_10032bc8 = 0;
  DAT_10032bb8 = (void *)((uint)DAT_10032bb8 & 0xffff0000);
  return;
}



// Function: FUN_10021290 at 10021290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021290(void)

{
  if (7 < DAT_10032be8) {
    operator_delete(DAT_10032bd4);
  }
  DAT_10032be8 = 7;
  _DAT_10032be4 = 0;
  DAT_10032bd4 = (void *)((uint)DAT_10032bd4 & 0xffff0000);
  return;
}



// Function: FUN_100212d0 at 100212d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100212d0(void)

{
  if (7 < DAT_10032c04) {
    operator_delete(DAT_10032bf0);
  }
  DAT_10032c04 = 7;
  _DAT_10032c00 = 0;
  DAT_10032bf0 = (void *)((uint)DAT_10032bf0 & 0xffff0000);
  return;
}



// Function: FUN_10021310 at 10021310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021310(void)

{
  if (7 < DAT_10032c20) {
    operator_delete(DAT_10032c0c);
  }
  DAT_10032c20 = 7;
  _DAT_10032c1c = 0;
  DAT_10032c0c = (void *)((uint)DAT_10032c0c & 0xffff0000);
  return;
}



// Function: FUN_10021350 at 10021350

void FUN_10021350(void)

{
  Ordinal_6(DAT_100345b0);
  return;
}



// Function: FUN_10021360 at 10021360

void FUN_10021360(void)

{
  Ordinal_6(DAT_100345b4);
  return;
}



// Function: FUN_10021370 at 10021370

void FUN_10021370(void)

{
  Ordinal_6(DAT_100345b8);
  return;
}



// Function: FUN_10021380 at 10021380

void FUN_10021380(void)

{
  Ordinal_6(DAT_100345bc);
  return;
}



// Function: FUN_10021390 at 10021390

void FUN_10021390(void)

{
  Ordinal_6(DAT_100345c0);
  return;
}



// Function: FUN_100213a0 at 100213a0

void FUN_100213a0(void)

{
  Ordinal_6(DAT_100345c4);
  return;
}



// Function: FUN_100213b0 at 100213b0

void FUN_100213b0(void)

{
  Ordinal_6(DAT_100345c8);
  return;
}



// Function: FUN_100213c0 at 100213c0

void FUN_100213c0(void)

{
  Ordinal_6(DAT_100345cc);
  return;
}



// Function: FUN_100213d0 at 100213d0

void FUN_100213d0(void)

{
  Ordinal_6(DAT_100345d0);
  return;
}



// Function: FUN_100213e0 at 100213e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100213e0(void)

{
  if (7 < DAT_100332b0) {
    operator_delete(DAT_1003329c);
  }
  DAT_100332b0 = 7;
  _DAT_100332ac = 0;
  DAT_1003329c = (void *)((uint)DAT_1003329c & 0xffff0000);
  return;
}



// Function: FUN_10021420 at 10021420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021420(void)

{
  if (7 < DAT_100332cc) {
    operator_delete(DAT_100332b8);
  }
  DAT_100332cc = 7;
  _DAT_100332c8 = 0;
  DAT_100332b8 = (void *)((uint)DAT_100332b8 & 0xffff0000);
  return;
}



// Function: FUN_10021460 at 10021460

void FUN_10021460(void)

{
  if (7 < DAT_100332e8) {
    operator_delete(DAT_100332d4);
  }
  DAT_100332e8 = 7;
  DAT_100332e4 = 0;
  DAT_100332d4 = (void *)((uint)DAT_100332d4 & 0xffff0000);
  return;
}



// Function: FUN_100214a0 at 100214a0

void FUN_100214a0(void)

{
  if (7 < DAT_10033304) {
    operator_delete(DAT_100332f0);
  }
  DAT_10033304 = 7;
  DAT_10033300 = 0;
  DAT_100332f0 = (void *)((uint)DAT_100332f0 & 0xffff0000);
  return;
}



// Function: FUN_100214e0 at 100214e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100214e0(void)

{
  if (7 < DAT_100333a8) {
    operator_delete(DAT_10033394);
  }
  DAT_100333a8 = 7;
  _DAT_100333a4 = 0;
  DAT_10033394 = (void *)((uint)DAT_10033394 & 0xffff0000);
  return;
}



// Function: FUN_10021520 at 10021520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021520(void)

{
  if (7 < DAT_100333c4) {
    operator_delete(DAT_100333b0);
  }
  DAT_100333c4 = 7;
  _DAT_100333c0 = 0;
  DAT_100333b0 = (void *)((uint)DAT_100333b0 & 0xffff0000);
  return;
}



// Function: FUN_10021560 at 10021560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021560(void)

{
  if (7 < DAT_100333e0) {
    operator_delete(DAT_100333cc);
  }
  DAT_100333e0 = 7;
  _DAT_100333dc = 0;
  DAT_100333cc = (void *)((uint)DAT_100333cc & 0xffff0000);
  return;
}



// Function: FUN_100215a0 at 100215a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100215a0(void)

{
  if (7 < DAT_100333fc) {
    operator_delete(DAT_100333e8);
  }
  DAT_100333fc = 7;
  _DAT_100333f8 = 0;
  DAT_100333e8 = (void *)((uint)DAT_100333e8 & 0xffff0000);
  return;
}



// Function: FUN_100215e0 at 100215e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100215e0(void)

{
  if (7 < DAT_10033418) {
    operator_delete(DAT_10033404);
  }
  DAT_10033418 = 7;
  _DAT_10033414 = 0;
  DAT_10033404 = (void *)((uint)DAT_10033404 & 0xffff0000);
  return;
}



// Function: FUN_10021620 at 10021620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021620(void)

{
  if (7 < DAT_10033434) {
    operator_delete(DAT_10033420);
  }
  DAT_10033434 = 7;
  _DAT_10033430 = 0;
  DAT_10033420 = (void *)((uint)DAT_10033420 & 0xffff0000);
  return;
}



// Function: FUN_10021660 at 10021660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021660(void)

{
  if (7 < DAT_10033450) {
    operator_delete(DAT_1003343c);
  }
  DAT_10033450 = 7;
  _DAT_1003344c = 0;
  DAT_1003343c = (void *)((uint)DAT_1003343c & 0xffff0000);
  return;
}



// Function: FUN_100216a0 at 100216a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100216a0(void)

{
  if (7 < DAT_1003346c) {
    operator_delete(DAT_10033458);
  }
  DAT_1003346c = 7;
  _DAT_10033468 = 0;
  DAT_10033458 = (void *)((uint)DAT_10033458 & 0xffff0000);
  return;
}



// Function: FUN_100216e0 at 100216e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100216e0(void)

{
  if (7 < DAT_10033488) {
    operator_delete(DAT_10033474);
  }
  DAT_10033488 = 7;
  _DAT_10033484 = 0;
  DAT_10033474 = (void *)((uint)DAT_10033474 & 0xffff0000);
  return;
}



// Function: FUN_10021720 at 10021720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021720(void)

{
  if (7 < DAT_100334a4) {
    operator_delete(DAT_10033490);
  }
  DAT_100334a4 = 7;
  _DAT_100334a0 = 0;
  DAT_10033490 = (void *)((uint)DAT_10033490 & 0xffff0000);
  return;
}



// Function: FUN_10021760 at 10021760

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021760(void)

{
  if (7 < DAT_100334c0) {
    operator_delete(DAT_100334ac);
  }
  DAT_100334c0 = 7;
  _DAT_100334bc = 0;
  DAT_100334ac = (void *)((uint)DAT_100334ac & 0xffff0000);
  return;
}



// Function: FUN_100217a0 at 100217a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100217a0(void)

{
  if (7 < DAT_100334dc) {
    operator_delete(DAT_100334c8);
  }
  DAT_100334dc = 7;
  _DAT_100334d8 = 0;
  DAT_100334c8 = (void *)((uint)DAT_100334c8 & 0xffff0000);
  return;
}



// Function: FUN_100217e0 at 100217e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100217e0(void)

{
  if (7 < DAT_100334f8) {
    operator_delete(DAT_100334e4);
  }
  DAT_100334f8 = 7;
  _DAT_100334f4 = 0;
  DAT_100334e4 = (void *)((uint)DAT_100334e4 & 0xffff0000);
  return;
}



// Function: FUN_10021820 at 10021820

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021820(void)

{
  if (7 < DAT_10033514) {
    operator_delete(DAT_10033500);
  }
  DAT_10033514 = 7;
  _DAT_10033510 = 0;
  DAT_10033500 = (void *)((uint)DAT_10033500 & 0xffff0000);
  return;
}



// Function: FUN_10021860 at 10021860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021860(void)

{
  if (7 < DAT_10033530) {
    operator_delete(DAT_1003351c);
  }
  DAT_10033530 = 7;
  _DAT_1003352c = 0;
  DAT_1003351c = (void *)((uint)DAT_1003351c & 0xffff0000);
  return;
}



// Function: FUN_100218a0 at 100218a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100218a0(void)

{
  if (7 < DAT_1003354c) {
    operator_delete(DAT_10033538);
  }
  DAT_1003354c = 7;
  _DAT_10033548 = 0;
  DAT_10033538 = (void *)((uint)DAT_10033538 & 0xffff0000);
  return;
}



// Function: FUN_100218e0 at 100218e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100218e0(void)

{
  if (7 < DAT_10033568) {
    operator_delete(DAT_10033554);
  }
  DAT_10033568 = 7;
  _DAT_10033564 = 0;
  DAT_10033554 = (void *)((uint)DAT_10033554 & 0xffff0000);
  return;
}



// Function: FUN_10021920 at 10021920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021920(void)

{
  if (7 < DAT_10033584) {
    operator_delete(DAT_10033570);
  }
  DAT_10033584 = 7;
  _DAT_10033580 = 0;
  DAT_10033570 = (void *)((uint)DAT_10033570 & 0xffff0000);
  return;
}



// Function: FUN_10021960 at 10021960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021960(void)

{
  if (7 < DAT_100335a0) {
    operator_delete(DAT_1003358c);
  }
  DAT_100335a0 = 7;
  _DAT_1003359c = 0;
  DAT_1003358c = (void *)((uint)DAT_1003358c & 0xffff0000);
  return;
}



// Function: FUN_100219a0 at 100219a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100219a0(void)

{
  if (7 < DAT_100335bc) {
    operator_delete(DAT_100335a8);
  }
  DAT_100335bc = 7;
  _DAT_100335b8 = 0;
  DAT_100335a8 = (void *)((uint)DAT_100335a8 & 0xffff0000);
  return;
}



// Function: FUN_100219e0 at 100219e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100219e0(void)

{
  if (7 < DAT_100335d8) {
    operator_delete(DAT_100335c4);
  }
  DAT_100335d8 = 7;
  _DAT_100335d4 = 0;
  DAT_100335c4 = (void *)((uint)DAT_100335c4 & 0xffff0000);
  return;
}



// Function: FUN_10021a20 at 10021a20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021a20(void)

{
  if (7 < DAT_100335f4) {
    operator_delete(DAT_100335e0);
  }
  DAT_100335f4 = 7;
  _DAT_100335f0 = 0;
  DAT_100335e0 = (void *)((uint)DAT_100335e0 & 0xffff0000);
  return;
}



// Function: FUN_10021a60 at 10021a60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021a60(void)

{
  if (7 < DAT_10033610) {
    operator_delete(DAT_100335fc);
  }
  DAT_10033610 = 7;
  _DAT_1003360c = 0;
  DAT_100335fc = (void *)((uint)DAT_100335fc & 0xffff0000);
  return;
}



// Function: FUN_10021aa0 at 10021aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021aa0(void)

{
  if (7 < DAT_1003362c) {
    operator_delete(DAT_10033618);
  }
  DAT_1003362c = 7;
  _DAT_10033628 = 0;
  DAT_10033618 = (void *)((uint)DAT_10033618 & 0xffff0000);
  return;
}



// Function: FUN_10021ae0 at 10021ae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ae0(void)

{
  if (7 < DAT_10033648) {
    operator_delete(DAT_10033634);
  }
  DAT_10033648 = 7;
  _DAT_10033644 = 0;
  DAT_10033634 = (void *)((uint)DAT_10033634 & 0xffff0000);
  return;
}



// Function: FUN_10021b20 at 10021b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021b20(void)

{
  if (7 < DAT_10033664) {
    operator_delete(DAT_10033650);
  }
  DAT_10033664 = 7;
  _DAT_10033660 = 0;
  DAT_10033650 = (void *)((uint)DAT_10033650 & 0xffff0000);
  return;
}



// Function: FUN_10021b60 at 10021b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021b60(void)

{
  if (7 < DAT_10033680) {
    operator_delete(DAT_1003366c);
  }
  DAT_10033680 = 7;
  _DAT_1003367c = 0;
  DAT_1003366c = (void *)((uint)DAT_1003366c & 0xffff0000);
  return;
}



// Function: FUN_10021ba0 at 10021ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ba0(void)

{
  if (7 < DAT_1003369c) {
    operator_delete(DAT_10033688);
  }
  DAT_1003369c = 7;
  _DAT_10033698 = 0;
  DAT_10033688 = (void *)((uint)DAT_10033688 & 0xffff0000);
  return;
}



// Function: FUN_10021be0 at 10021be0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021be0(void)

{
  if (7 < DAT_100336b8) {
    operator_delete(DAT_100336a4);
  }
  DAT_100336b8 = 7;
  _DAT_100336b4 = 0;
  DAT_100336a4 = (void *)((uint)DAT_100336a4 & 0xffff0000);
  return;
}



// Function: FUN_10021c20 at 10021c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021c20(void)

{
  if (7 < DAT_100336d4) {
    operator_delete(DAT_100336c0);
  }
  DAT_100336d4 = 7;
  _DAT_100336d0 = 0;
  DAT_100336c0 = (void *)((uint)DAT_100336c0 & 0xffff0000);
  return;
}



// Function: FUN_10021c60 at 10021c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021c60(void)

{
  if (7 < DAT_100336f0) {
    operator_delete(DAT_100336dc);
  }
  DAT_100336f0 = 7;
  _DAT_100336ec = 0;
  DAT_100336dc = (void *)((uint)DAT_100336dc & 0xffff0000);
  return;
}



// Function: FUN_10021ca0 at 10021ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ca0(void)

{
  if (7 < DAT_1003370c) {
    operator_delete(DAT_100336f8);
  }
  DAT_1003370c = 7;
  _DAT_10033708 = 0;
  DAT_100336f8 = (void *)((uint)DAT_100336f8 & 0xffff0000);
  return;
}



// Function: FUN_10021ce0 at 10021ce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ce0(void)

{
  if (7 < DAT_10033728) {
    operator_delete(DAT_10033714);
  }
  DAT_10033728 = 7;
  _DAT_10033724 = 0;
  DAT_10033714 = (void *)((uint)DAT_10033714 & 0xffff0000);
  return;
}



// Function: FUN_10021d20 at 10021d20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021d20(void)

{
  if (7 < DAT_10033744) {
    operator_delete(DAT_10033730);
  }
  DAT_10033744 = 7;
  _DAT_10033740 = 0;
  DAT_10033730 = (void *)((uint)DAT_10033730 & 0xffff0000);
  return;
}



// Function: FUN_10021d60 at 10021d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021d60(void)

{
  if (7 < DAT_10033760) {
    operator_delete(DAT_1003374c);
  }
  DAT_10033760 = 7;
  _DAT_1003375c = 0;
  DAT_1003374c = (void *)((uint)DAT_1003374c & 0xffff0000);
  return;
}



// Function: FUN_10021da0 at 10021da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021da0(void)

{
  if (7 < DAT_1003377c) {
    operator_delete(DAT_10033768);
  }
  DAT_1003377c = 7;
  _DAT_10033778 = 0;
  DAT_10033768 = (void *)((uint)DAT_10033768 & 0xffff0000);
  return;
}



// Function: FUN_10021de0 at 10021de0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021de0(void)

{
  if (7 < DAT_10033798) {
    operator_delete(DAT_10033784);
  }
  DAT_10033798 = 7;
  _DAT_10033794 = 0;
  DAT_10033784 = (void *)((uint)DAT_10033784 & 0xffff0000);
  return;
}



// Function: FUN_10021e20 at 10021e20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021e20(void)

{
  if (7 < DAT_100337b4) {
    operator_delete(DAT_100337a0);
  }
  DAT_100337b4 = 7;
  _DAT_100337b0 = 0;
  DAT_100337a0 = (void *)((uint)DAT_100337a0 & 0xffff0000);
  return;
}



// Function: FUN_10021e60 at 10021e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021e60(void)

{
  if (7 < DAT_100337d0) {
    operator_delete(DAT_100337bc);
  }
  DAT_100337d0 = 7;
  _DAT_100337cc = 0;
  DAT_100337bc = (void *)((uint)DAT_100337bc & 0xffff0000);
  return;
}



// Function: FUN_10021ea0 at 10021ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ea0(void)

{
  if (7 < DAT_100337ec) {
    operator_delete(DAT_100337d8);
  }
  DAT_100337ec = 7;
  _DAT_100337e8 = 0;
  DAT_100337d8 = (void *)((uint)DAT_100337d8 & 0xffff0000);
  return;
}



// Function: FUN_10021ee0 at 10021ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ee0(void)

{
  if (7 < DAT_10033808) {
    operator_delete(DAT_100337f4);
  }
  DAT_10033808 = 7;
  _DAT_10033804 = 0;
  DAT_100337f4 = (void *)((uint)DAT_100337f4 & 0xffff0000);
  return;
}



// Function: FUN_10021f20 at 10021f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021f20(void)

{
  if (7 < DAT_10033824) {
    operator_delete(DAT_10033810);
  }
  DAT_10033824 = 7;
  _DAT_10033820 = 0;
  DAT_10033810 = (void *)((uint)DAT_10033810 & 0xffff0000);
  return;
}



// Function: FUN_10021f60 at 10021f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021f60(void)

{
  if (7 < DAT_10033840) {
    operator_delete(DAT_1003382c);
  }
  DAT_10033840 = 7;
  _DAT_1003383c = 0;
  DAT_1003382c = (void *)((uint)DAT_1003382c & 0xffff0000);
  return;
}



// Function: FUN_10021fa0 at 10021fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021fa0(void)

{
  if (7 < DAT_1003385c) {
    operator_delete(DAT_10033848);
  }
  DAT_1003385c = 7;
  _DAT_10033858 = 0;
  DAT_10033848 = (void *)((uint)DAT_10033848 & 0xffff0000);
  return;
}



// Function: FUN_10021fe0 at 10021fe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021fe0(void)

{
  if (7 < DAT_10033878) {
    operator_delete(DAT_10033864);
  }
  DAT_10033878 = 7;
  _DAT_10033874 = 0;
  DAT_10033864 = (void *)((uint)DAT_10033864 & 0xffff0000);
  return;
}



// Function: FUN_10022020 at 10022020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022020(void)

{
  if (7 < DAT_10033894) {
    operator_delete(DAT_10033880);
  }
  DAT_10033894 = 7;
  _DAT_10033890 = 0;
  DAT_10033880 = (void *)((uint)DAT_10033880 & 0xffff0000);
  return;
}



// Function: FUN_10022060 at 10022060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022060(void)

{
  if (7 < DAT_100338b0) {
    operator_delete(DAT_1003389c);
  }
  DAT_100338b0 = 7;
  _DAT_100338ac = 0;
  DAT_1003389c = (void *)((uint)DAT_1003389c & 0xffff0000);
  return;
}



// Function: FUN_100220a0 at 100220a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100220a0(void)

{
  if (7 < DAT_100338cc) {
    operator_delete(DAT_100338b8);
  }
  DAT_100338cc = 7;
  _DAT_100338c8 = 0;
  DAT_100338b8 = (void *)((uint)DAT_100338b8 & 0xffff0000);
  return;
}



// Function: FUN_100220e0 at 100220e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100220e0(void)

{
  if (7 < DAT_100338e8) {
    operator_delete(DAT_100338d4);
  }
  DAT_100338e8 = 7;
  _DAT_100338e4 = 0;
  DAT_100338d4 = (void *)((uint)DAT_100338d4 & 0xffff0000);
  return;
}



// Function: FUN_10022120 at 10022120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022120(void)

{
  if (7 < DAT_10033904) {
    operator_delete(DAT_100338f0);
  }
  DAT_10033904 = 7;
  _DAT_10033900 = 0;
  DAT_100338f0 = (void *)((uint)DAT_100338f0 & 0xffff0000);
  return;
}



// Function: FUN_10022160 at 10022160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022160(void)

{
  if (7 < DAT_10033920) {
    operator_delete(DAT_1003390c);
  }
  DAT_10033920 = 7;
  _DAT_1003391c = 0;
  DAT_1003390c = (void *)((uint)DAT_1003390c & 0xffff0000);
  return;
}



// Function: FUN_100221a0 at 100221a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100221a0(void)

{
  if (7 < DAT_1003393c) {
    operator_delete(DAT_10033928);
  }
  DAT_1003393c = 7;
  _DAT_10033938 = 0;
  DAT_10033928 = (void *)((uint)DAT_10033928 & 0xffff0000);
  return;
}



// Function: FUN_100221e0 at 100221e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100221e0(void)

{
  if (7 < DAT_10033958) {
    operator_delete(DAT_10033944);
  }
  DAT_10033958 = 7;
  _DAT_10033954 = 0;
  DAT_10033944 = (void *)((uint)DAT_10033944 & 0xffff0000);
  return;
}



// Function: FUN_10022220 at 10022220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022220(void)

{
  if (7 < DAT_10033974) {
    operator_delete(DAT_10033960);
  }
  DAT_10033974 = 7;
  _DAT_10033970 = 0;
  DAT_10033960 = (void *)((uint)DAT_10033960 & 0xffff0000);
  return;
}



// Function: FUN_10022260 at 10022260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022260(void)

{
  if (7 < DAT_10033990) {
    operator_delete(DAT_1003397c);
  }
  DAT_10033990 = 7;
  _DAT_1003398c = 0;
  DAT_1003397c = (void *)((uint)DAT_1003397c & 0xffff0000);
  return;
}



// Function: FUN_100222a0 at 100222a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100222a0(void)

{
  if (7 < DAT_100339ac) {
    operator_delete(DAT_10033998);
  }
  DAT_100339ac = 7;
  _DAT_100339a8 = 0;
  DAT_10033998 = (void *)((uint)DAT_10033998 & 0xffff0000);
  return;
}



// Function: FUN_100222e0 at 100222e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100222e0(void)

{
  if (7 < DAT_100339c8) {
    operator_delete(DAT_100339b4);
  }
  DAT_100339c8 = 7;
  _DAT_100339c4 = 0;
  DAT_100339b4 = (void *)((uint)DAT_100339b4 & 0xffff0000);
  return;
}



// Function: FUN_10022320 at 10022320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022320(void)

{
  if (7 < DAT_100339e4) {
    operator_delete(DAT_100339d0);
  }
  DAT_100339e4 = 7;
  _DAT_100339e0 = 0;
  DAT_100339d0 = (void *)((uint)DAT_100339d0 & 0xffff0000);
  return;
}



// Function: FUN_10022360 at 10022360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022360(void)

{
  if (7 < DAT_10033a00) {
    operator_delete(DAT_100339ec);
  }
  DAT_10033a00 = 7;
  _DAT_100339fc = 0;
  DAT_100339ec = (void *)((uint)DAT_100339ec & 0xffff0000);
  return;
}



// Function: FUN_100223a0 at 100223a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100223a0(void)

{
  if (7 < DAT_10033a1c) {
    operator_delete(DAT_10033a08);
  }
  DAT_10033a1c = 7;
  _DAT_10033a18 = 0;
  DAT_10033a08 = (void *)((uint)DAT_10033a08 & 0xffff0000);
  return;
}



// Function: FUN_100223e0 at 100223e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100223e0(void)

{
  if (7 < DAT_10033a38) {
    operator_delete(DAT_10033a24);
  }
  DAT_10033a38 = 7;
  _DAT_10033a34 = 0;
  DAT_10033a24 = (void *)((uint)DAT_10033a24 & 0xffff0000);
  return;
}



// Function: FUN_10022420 at 10022420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022420(void)

{
  if (7 < DAT_10033a54) {
    operator_delete(DAT_10033a40);
  }
  DAT_10033a54 = 7;
  _DAT_10033a50 = 0;
  DAT_10033a40 = (void *)((uint)DAT_10033a40 & 0xffff0000);
  return;
}



// Function: FUN_10022460 at 10022460

void FUN_10022460(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_100345d4;
  if (DAT_100345d4 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_100345d4 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_100345d4 = (int *)0x0;
  }
  return;
}



// Function: FUN_100224b0 at 100224b0

void FUN_100224b0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_100345d8;
  if (DAT_100345d8 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_100345d8 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_100345d8 = (int *)0x0;
  }
  return;
}



// Function: FUN_10022500 at 10022500

void FUN_10022500(void)

{
  Ordinal_6(DAT_100345dc);
  return;
}



// Function: FUN_10022510 at 10022510

void FUN_10022510(void)

{
  Ordinal_6(DAT_100345e0);
  return;
}



// Function: FUN_10022520 at 10022520

void FUN_10022520(void)

{
  Ordinal_6(DAT_100345e4);
  return;
}



// Function: FUN_10022530 at 10022530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022530(void)

{
  if (7 < DAT_10033b28) {
    operator_delete(DAT_10033b14);
  }
  DAT_10033b28 = 7;
  _DAT_10033b24 = 0;
  DAT_10033b14 = (void *)((uint)DAT_10033b14 & 0xffff0000);
  return;
}



// Function: FUN_10022570 at 10022570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022570(void)

{
  if (7 < DAT_10033b44) {
    operator_delete(DAT_10033b30);
  }
  DAT_10033b44 = 7;
  _DAT_10033b40 = 0;
  DAT_10033b30 = (void *)((uint)DAT_10033b30 & 0xffff0000);
  return;
}



// Function: FUN_100225b0 at 100225b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100225b0(void)

{
  if (7 < DAT_10033b60) {
    operator_delete(DAT_10033b4c);
  }
  DAT_10033b60 = 7;
  _DAT_10033b5c = 0;
  DAT_10033b4c = (void *)((uint)DAT_10033b4c & 0xffff0000);
  return;
}



// Function: FUN_100225f0 at 100225f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100225f0(void)

{
  if (7 < DAT_10033b7c) {
    operator_delete(DAT_10033b68);
  }
  DAT_10033b7c = 7;
  _DAT_10033b78 = 0;
  DAT_10033b68 = (void *)((uint)DAT_10033b68 & 0xffff0000);
  return;
}



// Function: FUN_10022630 at 10022630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022630(void)

{
  if (7 < DAT_10033b98) {
    operator_delete(DAT_10033b84);
  }
  DAT_10033b98 = 7;
  _DAT_10033b94 = 0;
  DAT_10033b84 = (void *)((uint)DAT_10033b84 & 0xffff0000);
  return;
}



// Function: FUN_10022670 at 10022670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022670(void)

{
  if (7 < DAT_10033bb4) {
    operator_delete(DAT_10033ba0);
  }
  DAT_10033bb4 = 7;
  _DAT_10033bb0 = 0;
  DAT_10033ba0 = (void *)((uint)DAT_10033ba0 & 0xffff0000);
  return;
}



// Function: FUN_100226b0 at 100226b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100226b0(void)

{
  if (7 < DAT_10033bd0) {
    operator_delete(DAT_10033bbc);
  }
  DAT_10033bd0 = 7;
  _DAT_10033bcc = 0;
  DAT_10033bbc = (void *)((uint)DAT_10033bbc & 0xffff0000);
  return;
}



// Function: FUN_100226f0 at 100226f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100226f0(void)

{
  if (7 < DAT_10033bec) {
    operator_delete(DAT_10033bd8);
  }
  DAT_10033bec = 7;
  _DAT_10033be8 = 0;
  DAT_10033bd8 = (void *)((uint)DAT_10033bd8 & 0xffff0000);
  return;
}



// Function: FUN_10022730 at 10022730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022730(void)

{
  if (7 < DAT_10033c08) {
    operator_delete(DAT_10033bf4);
  }
  DAT_10033c08 = 7;
  _DAT_10033c04 = 0;
  DAT_10033bf4 = (void *)((uint)DAT_10033bf4 & 0xffff0000);
  return;
}



// Function: FUN_10022770 at 10022770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022770(void)

{
  if (7 < DAT_10033c24) {
    operator_delete(DAT_10033c10);
  }
  DAT_10033c24 = 7;
  _DAT_10033c20 = 0;
  DAT_10033c10 = (void *)((uint)DAT_10033c10 & 0xffff0000);
  return;
}



// Function: FUN_100227b0 at 100227b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100227b0(void)

{
  if (7 < DAT_10033c40) {
    operator_delete(DAT_10033c2c);
  }
  DAT_10033c40 = 7;
  _DAT_10033c3c = 0;
  DAT_10033c2c = (void *)((uint)DAT_10033c2c & 0xffff0000);
  return;
}



// Function: FUN_100227f0 at 100227f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100227f0(void)

{
  if (7 < DAT_10033c5c) {
    operator_delete(DAT_10033c48);
  }
  DAT_10033c5c = 7;
  _DAT_10033c58 = 0;
  DAT_10033c48 = (void *)((uint)DAT_10033c48 & 0xffff0000);
  return;
}



// Function: FUN_10022830 at 10022830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022830(void)

{
  if (7 < DAT_10033c78) {
    operator_delete(DAT_10033c64);
  }
  DAT_10033c78 = 7;
  _DAT_10033c74 = 0;
  DAT_10033c64 = (void *)((uint)DAT_10033c64 & 0xffff0000);
  return;
}



// Function: FUN_10022870 at 10022870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022870(void)

{
  if (7 < DAT_10033c94) {
    operator_delete(DAT_10033c80);
  }
  DAT_10033c94 = 7;
  _DAT_10033c90 = 0;
  DAT_10033c80 = (void *)((uint)DAT_10033c80 & 0xffff0000);
  return;
}



// Function: FUN_100228b0 at 100228b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100228b0(void)

{
  if (7 < DAT_10033cb0) {
    operator_delete(DAT_10033c9c);
  }
  DAT_10033cb0 = 7;
  _DAT_10033cac = 0;
  DAT_10033c9c = (void *)((uint)DAT_10033c9c & 0xffff0000);
  return;
}



// Function: FUN_100228f0 at 100228f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100228f0(void)

{
  if (7 < DAT_10033ccc) {
    operator_delete(DAT_10033cb8);
  }
  DAT_10033ccc = 7;
  _DAT_10033cc8 = 0;
  DAT_10033cb8 = (void *)((uint)DAT_10033cb8 & 0xffff0000);
  return;
}



// Function: FUN_10022930 at 10022930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022930(void)

{
  if (7 < DAT_10033ce8) {
    operator_delete(DAT_10033cd4);
  }
  DAT_10033ce8 = 7;
  _DAT_10033ce4 = 0;
  DAT_10033cd4 = (void *)((uint)DAT_10033cd4 & 0xffff0000);
  return;
}



// Function: FUN_10022970 at 10022970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022970(void)

{
  if (7 < DAT_10033d04) {
    operator_delete(DAT_10033cf0);
  }
  DAT_10033d04 = 7;
  _DAT_10033d00 = 0;
  DAT_10033cf0 = (void *)((uint)DAT_10033cf0 & 0xffff0000);
  return;
}



// Function: FUN_100229b0 at 100229b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100229b0(void)

{
  if (7 < DAT_10033d20) {
    operator_delete(DAT_10033d0c);
  }
  DAT_10033d20 = 7;
  _DAT_10033d1c = 0;
  DAT_10033d0c = (void *)((uint)DAT_10033d0c & 0xffff0000);
  return;
}



// Function: FUN_100229f0 at 100229f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100229f0(void)

{
  if (7 < DAT_10033d3c) {
    operator_delete(DAT_10033d28);
  }
  DAT_10033d3c = 7;
  _DAT_10033d38 = 0;
  DAT_10033d28 = (void *)((uint)DAT_10033d28 & 0xffff0000);
  return;
}



// Function: FUN_10022a30 at 10022a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022a30(void)

{
  if (7 < DAT_10033d58) {
    operator_delete(DAT_10033d44);
  }
  DAT_10033d58 = 7;
  _DAT_10033d54 = 0;
  DAT_10033d44 = (void *)((uint)DAT_10033d44 & 0xffff0000);
  return;
}



// Function: FUN_10022a70 at 10022a70

void FUN_10022a70(void)

{
  Ordinal_6(DAT_100345e8);
  return;
}



// Function: FUN_10022a80 at 10022a80

void FUN_10022a80(void)

{
  Ordinal_6(DAT_100345ec);
  return;
}



// Function: FUN_10022a90 at 10022a90

void FUN_10022a90(void)

{
  Ordinal_6(DAT_100345f0);
  return;
}



// Function: FUN_10022aa0 at 10022aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022aa0(void)

{
  if (7 < DAT_10033d74) {
    operator_delete(DAT_10033d60);
  }
  DAT_10033d74 = 7;
  _DAT_10033d70 = 0;
  DAT_10033d60 = (void *)((uint)DAT_10033d60 & 0xffff0000);
  return;
}



// Function: FUN_10022ae0 at 10022ae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ae0(void)

{
  if (7 < DAT_10033d90) {
    operator_delete(DAT_10033d7c);
  }
  DAT_10033d90 = 7;
  _DAT_10033d8c = 0;
  DAT_10033d7c = (void *)((uint)DAT_10033d7c & 0xffff0000);
  return;
}



// Function: FUN_10022b20 at 10022b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022b20(void)

{
  if (7 < DAT_10033dac) {
    operator_delete(DAT_10033d98);
  }
  DAT_10033dac = 7;
  _DAT_10033da8 = 0;
  DAT_10033d98 = (void *)((uint)DAT_10033d98 & 0xffff0000);
  return;
}



// Function: FUN_10022b60 at 10022b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022b60(void)

{
  if (7 < DAT_10033dc8) {
    operator_delete(DAT_10033db4);
  }
  DAT_10033dc8 = 7;
  _DAT_10033dc4 = 0;
  DAT_10033db4 = (void *)((uint)DAT_10033db4 & 0xffff0000);
  return;
}



// Function: FUN_10022ba0 at 10022ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ba0(void)

{
  if (7 < DAT_10033de4) {
    operator_delete(DAT_10033dd0);
  }
  DAT_10033de4 = 7;
  _DAT_10033de0 = 0;
  DAT_10033dd0 = (void *)((uint)DAT_10033dd0 & 0xffff0000);
  return;
}



// Function: FUN_10022be0 at 10022be0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022be0(void)

{
  if (7 < DAT_10033e00) {
    operator_delete(DAT_10033dec);
  }
  DAT_10033e00 = 7;
  _DAT_10033dfc = 0;
  DAT_10033dec = (void *)((uint)DAT_10033dec & 0xffff0000);
  return;
}



// Function: FUN_10022c20 at 10022c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022c20(void)

{
  if (7 < DAT_10033e1c) {
    operator_delete(DAT_10033e08);
  }
  DAT_10033e1c = 7;
  _DAT_10033e18 = 0;
  DAT_10033e08 = (void *)((uint)DAT_10033e08 & 0xffff0000);
  return;
}



// Function: FUN_10022c60 at 10022c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022c60(void)

{
  if (7 < DAT_10033e38) {
    operator_delete(DAT_10033e24);
  }
  DAT_10033e38 = 7;
  _DAT_10033e34 = 0;
  DAT_10033e24 = (void *)((uint)DAT_10033e24 & 0xffff0000);
  return;
}



// Function: FUN_10022ca0 at 10022ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ca0(void)

{
  if (7 < DAT_10033e54) {
    operator_delete(DAT_10033e40);
  }
  DAT_10033e54 = 7;
  _DAT_10033e50 = 0;
  DAT_10033e40 = (void *)((uint)DAT_10033e40 & 0xffff0000);
  return;
}



// Function: FUN_10022ce0 at 10022ce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ce0(void)

{
  if (7 < DAT_10033e70) {
    operator_delete(DAT_10033e5c);
  }
  DAT_10033e70 = 7;
  _DAT_10033e6c = 0;
  DAT_10033e5c = (void *)((uint)DAT_10033e5c & 0xffff0000);
  return;
}



// Function: FUN_10022d20 at 10022d20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022d20(void)

{
  if (7 < DAT_10033e8c) {
    operator_delete(DAT_10033e78);
  }
  DAT_10033e8c = 7;
  _DAT_10033e88 = 0;
  DAT_10033e78 = (void *)((uint)DAT_10033e78 & 0xffff0000);
  return;
}



// Function: FUN_10022d60 at 10022d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022d60(void)

{
  if (7 < DAT_10033ea8) {
    operator_delete(DAT_10033e94);
  }
  DAT_10033ea8 = 7;
  _DAT_10033ea4 = 0;
  DAT_10033e94 = (void *)((uint)DAT_10033e94 & 0xffff0000);
  return;
}



// Function: FUN_10022da0 at 10022da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022da0(void)

{
  if (7 < DAT_10033ec4) {
    operator_delete(DAT_10033eb0);
  }
  DAT_10033ec4 = 7;
  _DAT_10033ec0 = 0;
  DAT_10033eb0 = (void *)((uint)DAT_10033eb0 & 0xffff0000);
  return;
}



// Function: FUN_10022de0 at 10022de0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022de0(void)

{
  if (7 < DAT_10033ee0) {
    operator_delete(DAT_10033ecc);
  }
  DAT_10033ee0 = 7;
  _DAT_10033edc = 0;
  DAT_10033ecc = (void *)((uint)DAT_10033ecc & 0xffff0000);
  return;
}



// Function: FUN_10022e20 at 10022e20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022e20(void)

{
  if (7 < DAT_10033efc) {
    operator_delete(DAT_10033ee8);
  }
  DAT_10033efc = 7;
  _DAT_10033ef8 = 0;
  DAT_10033ee8 = (void *)((uint)DAT_10033ee8 & 0xffff0000);
  return;
}



// Function: FUN_10022e60 at 10022e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022e60(void)

{
  if (7 < DAT_10033f18) {
    operator_delete(DAT_10033f04);
  }
  DAT_10033f18 = 7;
  _DAT_10033f14 = 0;
  DAT_10033f04 = (void *)((uint)DAT_10033f04 & 0xffff0000);
  return;
}



// Function: FUN_10022ea0 at 10022ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ea0(void)

{
  if (7 < DAT_10033f34) {
    operator_delete(DAT_10033f20);
  }
  DAT_10033f34 = 7;
  _DAT_10033f30 = 0;
  DAT_10033f20 = (void *)((uint)DAT_10033f20 & 0xffff0000);
  return;
}



// Function: FUN_10022ee0 at 10022ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022ee0(void)

{
  if (7 < DAT_10033f50) {
    operator_delete(DAT_10033f3c);
  }
  DAT_10033f50 = 7;
  _DAT_10033f4c = 0;
  DAT_10033f3c = (void *)((uint)DAT_10033f3c & 0xffff0000);
  return;
}



// Function: FUN_10022f20 at 10022f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022f20(void)

{
  if (7 < DAT_10033f6c) {
    operator_delete(DAT_10033f58);
  }
  DAT_10033f6c = 7;
  _DAT_10033f68 = 0;
  DAT_10033f58 = (void *)((uint)DAT_10033f58 & 0xffff0000);
  return;
}



// Function: FUN_10022f60 at 10022f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022f60(void)

{
  if (7 < DAT_10033f88) {
    operator_delete(DAT_10033f74);
  }
  DAT_10033f88 = 7;
  _DAT_10033f84 = 0;
  DAT_10033f74 = (void *)((uint)DAT_10033f74 & 0xffff0000);
  return;
}



// Function: FUN_10022fa0 at 10022fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022fa0(void)

{
  if (7 < DAT_10033fa4) {
    operator_delete(DAT_10033f90);
  }
  DAT_10033fa4 = 7;
  _DAT_10033fa0 = 0;
  DAT_10033f90 = (void *)((uint)DAT_10033f90 & 0xffff0000);
  return;
}



// Function: FUN_10022fe0 at 10022fe0

void FUN_10022fe0(void)

{
  Ordinal_6(DAT_100345f4);
  return;
}



// Function: FUN_10022ff0 at 10022ff0

void FUN_10022ff0(void)

{
  Ordinal_6(DAT_100345f8);
  return;
}



// Function: FUN_10023000 at 10023000

void FUN_10023000(void)

{
  Ordinal_6(DAT_100345fc);
  return;
}



// Function: FUN_10023010 at 10023010

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023010(void)

{
  if (7 < DAT_10033fc8) {
    operator_delete(DAT_10033fb4);
  }
  DAT_10033fc8 = 7;
  _DAT_10033fc4 = 0;
  DAT_10033fb4 = (void *)((uint)DAT_10033fb4 & 0xffff0000);
  return;
}



// Function: FUN_10023050 at 10023050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023050(void)

{
  if (7 < DAT_10033fe4) {
    operator_delete(DAT_10033fd0);
  }
  DAT_10033fe4 = 7;
  _DAT_10033fe0 = 0;
  DAT_10033fd0 = (void *)((uint)DAT_10033fd0 & 0xffff0000);
  return;
}



// Function: FUN_10023090 at 10023090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023090(void)

{
  if (7 < DAT_10034000) {
    operator_delete(DAT_10033fec);
  }
  DAT_10034000 = 7;
  _DAT_10033ffc = 0;
  DAT_10033fec = (void *)((uint)DAT_10033fec & 0xffff0000);
  return;
}



// Function: FUN_100230d0 at 100230d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100230d0(void)

{
  if (7 < DAT_1003401c) {
    operator_delete(DAT_10034008);
  }
  DAT_1003401c = 7;
  _DAT_10034018 = 0;
  DAT_10034008 = (void *)((uint)DAT_10034008 & 0xffff0000);
  return;
}



// Function: FUN_10023110 at 10023110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023110(void)

{
  if (7 < DAT_10034038) {
    operator_delete(DAT_10034024);
  }
  DAT_10034038 = 7;
  _DAT_10034034 = 0;
  DAT_10034024 = (void *)((uint)DAT_10034024 & 0xffff0000);
  return;
}



// Function: FUN_10023150 at 10023150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023150(void)

{
  if (7 < DAT_10034054) {
    operator_delete(DAT_10034040);
  }
  DAT_10034054 = 7;
  _DAT_10034050 = 0;
  DAT_10034040 = (void *)((uint)DAT_10034040 & 0xffff0000);
  return;
}



// Function: FUN_10023190 at 10023190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023190(void)

{
  if (7 < DAT_10034070) {
    operator_delete(DAT_1003405c);
  }
  DAT_10034070 = 7;
  _DAT_1003406c = 0;
  DAT_1003405c = (void *)((uint)DAT_1003405c & 0xffff0000);
  return;
}



// Function: FUN_100231d0 at 100231d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100231d0(void)

{
  if (7 < DAT_1003408c) {
    operator_delete(DAT_10034078);
  }
  DAT_1003408c = 7;
  _DAT_10034088 = 0;
  DAT_10034078 = (void *)((uint)DAT_10034078 & 0xffff0000);
  return;
}



// Function: FUN_10023210 at 10023210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023210(void)

{
  if (7 < DAT_100340a8) {
    operator_delete(DAT_10034094);
  }
  DAT_100340a8 = 7;
  _DAT_100340a4 = 0;
  DAT_10034094 = (void *)((uint)DAT_10034094 & 0xffff0000);
  return;
}



// Function: FUN_10023250 at 10023250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023250(void)

{
  if (7 < DAT_100340c4) {
    operator_delete(DAT_100340b0);
  }
  DAT_100340c4 = 7;
  _DAT_100340c0 = 0;
  DAT_100340b0 = (void *)((uint)DAT_100340b0 & 0xffff0000);
  return;
}



// Function: FUN_10023290 at 10023290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023290(void)

{
  if (7 < DAT_100340e0) {
    operator_delete(DAT_100340cc);
  }
  DAT_100340e0 = 7;
  _DAT_100340dc = 0;
  DAT_100340cc = (void *)((uint)DAT_100340cc & 0xffff0000);
  return;
}



// Function: FUN_100232d0 at 100232d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100232d0(void)

{
  if (7 < DAT_100340fc) {
    operator_delete(DAT_100340e8);
  }
  DAT_100340fc = 7;
  _DAT_100340f8 = 0;
  DAT_100340e8 = (void *)((uint)DAT_100340e8 & 0xffff0000);
  return;
}



// Function: FUN_10023310 at 10023310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023310(void)

{
  if (7 < DAT_10034118) {
    operator_delete(DAT_10034104);
  }
  DAT_10034118 = 7;
  _DAT_10034114 = 0;
  DAT_10034104 = (void *)((uint)DAT_10034104 & 0xffff0000);
  return;
}



// Function: FUN_10023350 at 10023350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023350(void)

{
  if (7 < DAT_10034134) {
    operator_delete(DAT_10034120);
  }
  DAT_10034134 = 7;
  _DAT_10034130 = 0;
  DAT_10034120 = (void *)((uint)DAT_10034120 & 0xffff0000);
  return;
}



// Function: FUN_10023390 at 10023390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023390(void)

{
  if (7 < DAT_10034150) {
    operator_delete(DAT_1003413c);
  }
  DAT_10034150 = 7;
  _DAT_1003414c = 0;
  DAT_1003413c = (void *)((uint)DAT_1003413c & 0xffff0000);
  return;
}



// Function: FUN_100233d0 at 100233d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100233d0(void)

{
  if (7 < DAT_1003416c) {
    operator_delete(DAT_10034158);
  }
  DAT_1003416c = 7;
  _DAT_10034168 = 0;
  DAT_10034158 = (void *)((uint)DAT_10034158 & 0xffff0000);
  return;
}



// Function: FUN_10023410 at 10023410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023410(void)

{
  if (7 < DAT_10034188) {
    operator_delete(DAT_10034174);
  }
  DAT_10034188 = 7;
  _DAT_10034184 = 0;
  DAT_10034174 = (void *)((uint)DAT_10034174 & 0xffff0000);
  return;
}



// Function: FUN_10023450 at 10023450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023450(void)

{
  if (7 < DAT_100341a4) {
    operator_delete(DAT_10034190);
  }
  DAT_100341a4 = 7;
  _DAT_100341a0 = 0;
  DAT_10034190 = (void *)((uint)DAT_10034190 & 0xffff0000);
  return;
}



// Function: FUN_10023490 at 10023490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023490(void)

{
  if (7 < DAT_100341c0) {
    operator_delete(DAT_100341ac);
  }
  DAT_100341c0 = 7;
  _DAT_100341bc = 0;
  DAT_100341ac = (void *)((uint)DAT_100341ac & 0xffff0000);
  return;
}



// Function: FUN_100234d0 at 100234d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100234d0(void)

{
  if (7 < DAT_100341dc) {
    operator_delete(DAT_100341c8);
  }
  DAT_100341dc = 7;
  _DAT_100341d8 = 0;
  DAT_100341c8 = (void *)((uint)DAT_100341c8 & 0xffff0000);
  return;
}



// Function: FUN_10023510 at 10023510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023510(void)

{
  if (7 < DAT_100341f8) {
    operator_delete(DAT_100341e4);
  }
  DAT_100341f8 = 7;
  _DAT_100341f4 = 0;
  DAT_100341e4 = (void *)((uint)DAT_100341e4 & 0xffff0000);
  return;
}



// Function: FUN_10023550 at 10023550

void FUN_10023550(void)

{
  Ordinal_6(DAT_10034600);
  return;
}



// Function: FUN_10023560 at 10023560

void FUN_10023560(void)

{
  Ordinal_6(DAT_10034604);
  return;
}



// Function: FUN_10023570 at 10023570

void FUN_10023570(void)

{
  Ordinal_6(DAT_10034608);
  return;
}



// Function: FUN_10023580 at 10023580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023580(void)

{
  if (7 < DAT_10034230) {
    operator_delete(DAT_1003421c);
  }
  DAT_10034230 = 7;
  _DAT_1003422c = 0;
  DAT_1003421c = (void *)((uint)DAT_1003421c & 0xffff0000);
  return;
}



// Function: FUN_100235c0 at 100235c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100235c0(void)

{
  if (7 < DAT_1003424c) {
    operator_delete(DAT_10034238);
  }
  DAT_1003424c = 7;
  _DAT_10034248 = 0;
  DAT_10034238 = (void *)((uint)DAT_10034238 & 0xffff0000);
  return;
}



// Function: FUN_10023600 at 10023600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023600(void)

{
  if (7 < DAT_10034268) {
    operator_delete(DAT_10034254);
  }
  DAT_10034268 = 7;
  _DAT_10034264 = 0;
  DAT_10034254 = (void *)((uint)DAT_10034254 & 0xffff0000);
  return;
}



// Function: FUN_10023640 at 10023640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023640(void)

{
  if (7 < DAT_10034284) {
    operator_delete(DAT_10034270);
  }
  DAT_10034284 = 7;
  _DAT_10034280 = 0;
  DAT_10034270 = (void *)((uint)DAT_10034270 & 0xffff0000);
  return;
}



// Function: FUN_10023680 at 10023680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023680(void)

{
  if (7 < DAT_100342a0) {
    operator_delete(DAT_1003428c);
  }
  DAT_100342a0 = 7;
  _DAT_1003429c = 0;
  DAT_1003428c = (void *)((uint)DAT_1003428c & 0xffff0000);
  return;
}



// Function: FUN_100236c0 at 100236c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100236c0(void)

{
  if (7 < DAT_100342bc) {
    operator_delete(DAT_100342a8);
  }
  DAT_100342bc = 7;
  _DAT_100342b8 = 0;
  DAT_100342a8 = (void *)((uint)DAT_100342a8 & 0xffff0000);
  return;
}



// Function: FUN_10023700 at 10023700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023700(void)

{
  if (7 < DAT_100342d8) {
    operator_delete(DAT_100342c4);
  }
  DAT_100342d8 = 7;
  _DAT_100342d4 = 0;
  DAT_100342c4 = (void *)((uint)DAT_100342c4 & 0xffff0000);
  return;
}



// Function: FUN_10023740 at 10023740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023740(void)

{
  if (7 < DAT_100342f4) {
    operator_delete(DAT_100342e0);
  }
  DAT_100342f4 = 7;
  _DAT_100342f0 = 0;
  DAT_100342e0 = (void *)((uint)DAT_100342e0 & 0xffff0000);
  return;
}



// Function: FUN_10023780 at 10023780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023780(void)

{
  if (7 < DAT_10034310) {
    operator_delete(DAT_100342fc);
  }
  DAT_10034310 = 7;
  _DAT_1003430c = 0;
  DAT_100342fc = (void *)((uint)DAT_100342fc & 0xffff0000);
  return;
}



// Function: FUN_100237c0 at 100237c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100237c0(void)

{
  if (7 < DAT_1003432c) {
    operator_delete(DAT_10034318);
  }
  DAT_1003432c = 7;
  _DAT_10034328 = 0;
  DAT_10034318 = (void *)((uint)DAT_10034318 & 0xffff0000);
  return;
}



// Function: FUN_10023800 at 10023800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023800(void)

{
  if (7 < DAT_10034348) {
    operator_delete(DAT_10034334);
  }
  DAT_10034348 = 7;
  _DAT_10034344 = 0;
  DAT_10034334 = (void *)((uint)DAT_10034334 & 0xffff0000);
  return;
}



// Function: FUN_10023840 at 10023840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023840(void)

{
  if (7 < DAT_10034364) {
    operator_delete(DAT_10034350);
  }
  DAT_10034364 = 7;
  _DAT_10034360 = 0;
  DAT_10034350 = (void *)((uint)DAT_10034350 & 0xffff0000);
  return;
}



// Function: FUN_10023880 at 10023880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023880(void)

{
  if (7 < DAT_10034380) {
    operator_delete(DAT_1003436c);
  }
  DAT_10034380 = 7;
  _DAT_1003437c = 0;
  DAT_1003436c = (void *)((uint)DAT_1003436c & 0xffff0000);
  return;
}



// Function: FUN_100238c0 at 100238c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100238c0(void)

{
  if (7 < DAT_1003439c) {
    operator_delete(DAT_10034388);
  }
  DAT_1003439c = 7;
  _DAT_10034398 = 0;
  DAT_10034388 = (void *)((uint)DAT_10034388 & 0xffff0000);
  return;
}



// Function: FUN_10023900 at 10023900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023900(void)

{
  if (7 < DAT_100343b8) {
    operator_delete(DAT_100343a4);
  }
  DAT_100343b8 = 7;
  _DAT_100343b4 = 0;
  DAT_100343a4 = (void *)((uint)DAT_100343a4 & 0xffff0000);
  return;
}



// Function: FUN_10023940 at 10023940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023940(void)

{
  if (7 < DAT_100343d4) {
    operator_delete(DAT_100343c0);
  }
  DAT_100343d4 = 7;
  _DAT_100343d0 = 0;
  DAT_100343c0 = (void *)((uint)DAT_100343c0 & 0xffff0000);
  return;
}



// Function: FUN_10023980 at 10023980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023980(void)

{
  if (7 < DAT_100343f0) {
    operator_delete(DAT_100343dc);
  }
  DAT_100343f0 = 7;
  _DAT_100343ec = 0;
  DAT_100343dc = (void *)((uint)DAT_100343dc & 0xffff0000);
  return;
}



// Function: FUN_100239c0 at 100239c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100239c0(void)

{
  if (7 < DAT_1003440c) {
    operator_delete(DAT_100343f8);
  }
  DAT_1003440c = 7;
  _DAT_10034408 = 0;
  DAT_100343f8 = (void *)((uint)DAT_100343f8 & 0xffff0000);
  return;
}



// Function: FUN_10023a00 at 10023a00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023a00(void)

{
  if (7 < DAT_10034428) {
    operator_delete(DAT_10034414);
  }
  DAT_10034428 = 7;
  _DAT_10034424 = 0;
  DAT_10034414 = (void *)((uint)DAT_10034414 & 0xffff0000);
  return;
}



// Function: FUN_10023a40 at 10023a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023a40(void)

{
  if (7 < DAT_10034444) {
    operator_delete(DAT_10034430);
  }
  DAT_10034444 = 7;
  _DAT_10034440 = 0;
  DAT_10034430 = (void *)((uint)DAT_10034430 & 0xffff0000);
  return;
}



// Function: FUN_10023a80 at 10023a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023a80(void)

{
  if (7 < DAT_10034460) {
    operator_delete(DAT_1003444c);
  }
  DAT_10034460 = 7;
  _DAT_1003445c = 0;
  DAT_1003444c = (void *)((uint)DAT_1003444c & 0xffff0000);
  return;
}



// Function: FUN_10023ab5 at 10023ab5

void FUN_10023ab5(void)

{
  FUN_10018e02((int *)&DAT_1003493c);
  return;
}



// Function: FUN_10023abf at 10023abf

void FUN_10023abf(void)

{
  FUN_10018ee4(0x10034964);
  return;
}



// Function: FUN_10023ac9 at 10023ac9

void FUN_10023ac9(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_1003499c,DAT_10034968);
  FUN_10016900((undefined4 *)&DAT_100349bc);
  return;
}



// Function: FUN_10023af0 at 10023af0

void FUN_10023af0(void)

{
  Ordinal_9(&DAT_100344e0);
  return;
}



// Function: FUN_10023afc at 10023afc

void FUN_10023afc(void)

{
  FUN_10019331();
  return;
}



// Function: FUN_10024000 at 10024000

undefined4 FUN_10024000(byte *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  int local_18;
  int local_10;
  int local_8;
  
  local_8 = -1;
  iVar2 = 0x10;
  bVar5 = false;
  bVar6 = true;
  local_10 = 0;
  pbVar3 = param_1;
  pbVar4 = PTR_DAT_10031028;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar6 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar6);
  if (!bVar6) {
    local_10 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
  }
  if (local_10 < 1) {
    if (local_10 != 0) goto LAB_1002405a;
    local_8 = 1;
LAB_100240a5:
    *param_2 = local_8;
    uVar1 = 1;
  }
  else {
    local_8 = 1;
LAB_1002405a:
    local_8 = local_8 + 1;
    if (local_8 < 2) {
      iVar2 = 0x10;
      bVar5 = false;
      bVar6 = true;
      local_18 = 0;
      pbVar3 = *(byte **)((&PTR_DAT_10025e80)[local_8] + 4);
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *param_1 < *pbVar3;
        bVar6 = *param_1 == *pbVar3;
        param_1 = param_1 + 1;
        pbVar3 = pbVar3 + 1;
      } while (bVar6);
      if (!bVar6) {
        local_18 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      }
      if (local_18 == 0) goto LAB_100240a5;
    }
    uVar1 = 0;
  }
  return uVar1;
}



