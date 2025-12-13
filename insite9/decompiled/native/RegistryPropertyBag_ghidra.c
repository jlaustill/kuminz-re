/*
 * Decompiled from: RegistryPropertyBag.dll
 * Using Ghidra 11.4.1
 */

// Function: _InlineIsEqualGUID at 10001000

/* Library Function - Single Match
    _InlineIsEqualGUID
   
   Library: Visual Studio 2010 Release */

undefined4 __cdecl _InlineIsEqualGUID(int *param_1,int *param_2)

{
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    return 1;
  }
  return 0;
}



// Function: FUN_10001030 at 10001030

bool __cdecl FUN_10001030(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_1000106f at 1000106f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_1000106f(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: AtlMultiply<unsigned_long> at 100010a7

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

long __cdecl ATL::AtlMultiply<unsigned_long>(ulong *param_1,ulong param_2,ulong param_3)

{
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    return -0x7ff8fdea;
  }
  *param_1 = (ulong)((ulonglong)param_2 * (ulonglong)param_3);
  return 0;
}



// Function: AtlCoTaskMemCAlloc at 100010c9

/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

void * __cdecl ATL::AtlCoTaskMemCAlloc(ulong param_1,ulong param_2)

{
  long lVar1;
  LPVOID pvVar2;
  ulong local_8;
  
  local_8 = 0;
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    return (void *)0x0;
  }
  pvVar2 = CoTaskMemAlloc(local_8);
  return pvVar2;
}



// Function: FUN_100010f6 at 100010f6

LPVOID __cdecl FUN_100010f6(LPVOID param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  LPVOID pvVar2;
  ulong local_8;
  
  local_8 = 0;
  lVar1 = ATL::AtlMultiply<unsigned_long>(&local_8,param_2,param_3);
  if (lVar1 < 0) {
    return (LPVOID)0x0;
  }
  pvVar2 = CoTaskMemRealloc(param_1,local_8);
  return pvVar2;
}



// Function: FUN_10001126 at 10001126

bool __cdecl FUN_10001126(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10001153 at 10001153

void FUN_10001153(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100098e4);
}



// Function: AtlCrtErrorCheck at 1000116b

/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return param_1;
  }
  if (param_1 == 0xc) {
    uVar1 = 0x8007000e;
  }
  else {
    if (param_1 == 0x16) goto LAB_10001193;
    if (param_1 == 0x22) goto LAB_10001193;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_10001153(uVar1);
LAB_10001193:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_100011a3 at 100011a3

void __cdecl FUN_100011a3(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100011c3 at 100011c3

void __cdecl FUN_100011c3(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 100011e0

/* Library Function - Single Match
    public: long __thiscall ATL::CComCriticalSection::Init(void)
   
   Library: Visual Studio 2010 Release */

long __thiscall ATL::CComCriticalSection::Init(CComCriticalSection *this)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this,0);
  if ((BVar1 == 0) && (DVar2 = GetLastError(), 0 < (int)DVar2)) {
    DVar2 = DVar2 & 0xffff | 0x80070000;
  }
  return DVar2;
}



// Function: FUN_10001209 at 10001209

void __fastcall FUN_10001209(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000121b at 1000121b

DWORD FUN_1000121b(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001230 at 10001230

uint __cdecl FUN_10001230(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10001246 at 10001246

void __fastcall FUN_10001246(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 1000124f

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegOpenKeyExA(struct HKEY__ *,char const
   *,unsigned long,unsigned long,struct HKEY__ * *)
    public: long __thiscall ATL::CAtlTransactionManager::RegOpenKeyExW(struct HKEY__ *,wchar_t const
   *,unsigned long,unsigned long,struct HKEY__ * *)
   
   Library: Visual Studio 2010 Release */

LSTATUS FID_conflict_RegOpenKeyExA
                  (HKEY hKey,LPCSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    if (in_ECX[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x10001298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegOpenKeyExW(hKey,(LPCWSTR)lpSubKey,ulOptions,samDesired,phkResult);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedW"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,ulOptions,samDesired,phkResult,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FID_conflict:RegCreateKeyExW at 100012a6

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegCreateKeyExA(struct HKEY__ *,char const
   *,unsigned long,char *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES * const,struct
   HKEY__ * *,unsigned long *)
    public: long __thiscall ATL::CAtlTransactionManager::RegCreateKeyExW(struct HKEY__ *,wchar_t
   const *,unsigned long,wchar_t *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES *
   const,struct HKEY__ * *,unsigned long *)
   
   Library: Visual Studio 2010 Release */

LSTATUS FID_conflict_RegCreateKeyExW
                  (HKEY hKey,LPCWSTR lpSubKey,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,
                  REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,
                  LPDWORD lpdwDisposition)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    if (in_ECX[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x100012fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegCreateKeyExW(hKey,lpSubKey,Reserved,lpClass,dwOptions,samDesired,
                              lpSecurityAttributes,phkResult,lpdwDisposition);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedW"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,Reserved,lpClass,dwOptions,samDesired,lpSecurityAttributes,
                        phkResult,lpdwDisposition,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FID_conflict:RegDeleteKeyA at 10001309

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegDeleteKeyA(struct HKEY__ *,char const *)
    public: long __thiscall ATL::CAtlTransactionManager::RegDeleteKeyW(struct HKEY__ *,wchar_t const
   *)
   
   Library: Visual Studio 2010 Release */

LSTATUS FID_conflict_RegDeleteKeyA(HKEY hKey,LPCSTR lpSubKey)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    if (in_ECX[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x1000134c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyW(hKey,(LPCWSTR)lpSubKey);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,0,0,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000135b at 1000135b

undefined4 __fastcall FUN_1000135b(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1000135f at 1000135f

void __cdecl FUN_1000135f(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    psVar1 = param_1;
    if (param_2 != 1) {
      do {
        psVar1 = param_1;
        if (*param_3 == 0) break;
        *param_1 = *param_3;
        psVar1 = param_1 + 1;
        if ((*param_3 == 0x27) && (uVar2 = uVar2 + 1, uVar2 < param_2 - 1U)) {
          *psVar1 = 0x27;
          psVar1 = param_1 + 2;
        }
        param_3 = param_3 + 1;
        uVar2 = uVar2 + 1;
        param_1 = psVar1;
      } while (uVar2 < param_2 - 1U);
    }
    *psVar1 = 0;
  }
  return;
}



// Function: FUN_100013ad at 100013ad

int __fastcall FUN_100013ad(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: FUN_100013c4 at 100013c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_100013c4(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: DllCanUnloadNow at 100013f2

HRESULT DllCanUnloadNow(void)

{
                    /* 0x13f2  1  DllCanUnloadNow */
  return (uint)(DAT_1000c7e4 != 0);
}



// Function: DeleteSubKey at 100013fe

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_1000c744 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1000c740 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_1000c744 = '\x01';
    }
    if (DAT_1000c740 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1000c740)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 1000146e

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Library: Visual Studio 2010 Release */

long __thiscall ATL::CRegKey::Close(CRegKey *this)

{
  long lVar1;
  
  lVar1 = 0;
  if (*(HKEY *)this != (HKEY)0x0) {
    lVar1 = RegCloseKey(*(HKEY *)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return lVar1;
}



// Function: Create at 10001489

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::Create(struct HKEY__ *,char const *,char *,unsigned
   long,unsigned long,struct _SECURITY_ATTRIBUTES *,unsigned long *)
    public: long __thiscall ATL::CRegKey::Create(struct HKEY__ *,wchar_t const *,wchar_t *,unsigned
   long,unsigned long,struct _SECURITY_ATTRIBUTES *,unsigned long *)
   
   Library: Visual Studio 2010 Release */

void __thiscall
Create(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
      LPSECURITY_ATTRIBUTES param_6,undefined4 *param_7)

{
  int iVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(int *)((int)this + 8) == 0) {
    iVar1 = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,
                            (LPDWORD)&param_6);
  }
  else {
    iVar1 = FID_conflict_RegCreateKeyExW
                      (param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,(LPDWORD)&param_6)
    ;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_6;
  }
  if (iVar1 == 0) {
    ATL::CRegKey::Close((CRegKey *)this);
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_5 & 0x300;
  }
  return;
}



// Function: Open at 100014f1

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::Open(struct HKEY__ *,char const *,unsigned long)
    public: long __thiscall ATL::CRegKey::Open(struct HKEY__ *,wchar_t const *,unsigned long)
   
   Library: Visual Studio 2010 Release */

void __thiscall Open(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int iVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(int *)((int)this + 8) == 0) {
    iVar1 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    iVar1 = FID_conflict_RegOpenKeyExA(param_1,(LPCSTR)param_2,0,param_3,&local_8);
  }
  if (iVar1 == 0) {
    ATL::CRegKey::Close((CRegKey *)this);
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_3 & 0x300;
  }
  return;
}



// Function: SetStringValue at 10001540

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::SetStringValue(wchar_t const *,wchar_t const *,unsigned
   long)
   
   Library: Visual Studio 2010 Release */

long __thiscall
ATL::CRegKey::SetStringValue(CRegKey *this,wchar_t *param_1,wchar_t *param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    lVar2 = 0xd;
  }
  else {
    iVar1 = lstrlenW(param_2);
    lVar2 = RegSetValueExW(*(HKEY *)this,param_1,0,param_3,(BYTE *)param_2,iVar1 * 2 + 2);
  }
  return lVar2;
}



// Function: FUN_10001577 at 10001577

LSTATUS __thiscall FUN_10001577(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  int iVar1;
  LSTATUS LVar2;
  LPCWSTR lpString;
  DWORD cbData;
  
  if (param_2 == (LPCWSTR)0x0) {
    LVar2 = 0xd;
  }
  else {
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
  }
  return LVar2;
}



// Function: FUN_100015ba at 100015ba

undefined4 __fastcall FUN_100015ba(undefined4 *param_1)

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



// Function: FUN_100015da at 100015da

undefined4 * __thiscall FUN_100015da(void *this,ulong param_1)

{
  undefined2 *puVar1;
  
  if ((int)param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 4) = param_1;
  puVar1 = (undefined2 *)ATL::AtlCoTaskMemCAlloc(param_1,2);
  *(undefined2 **)((int)this + 8) = puVar1;
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_10001610 at 10001610

void __fastcall FUN_10001610(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_1000161a at 1000161a

undefined4 __thiscall FUN_1000161a(void *this,void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  LPVOID pvVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
  if ((*this < iVar1) && (param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      do {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        uVar3 = *(int *)((int)this + 4) * 2;
        *(ulong *)((int)this + 4) = uVar3;
      } while ((int)uVar3 <= iVar1);
      pvVar4 = FUN_100010f6(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100011a3((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_100016a8 at 100016a8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100016a8(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x100016b4;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1000c768 & 1) == 0) {
    DAT_1000c768 = DAT_1000c768 | 1;
    DAT_1000c74c = 8;
    _DAT_1000c754 = 0x4008;
    _DAT_1000c75c = 0x13;
    DAT_1000c748 = &DAT_10008384;
    DAT_1000c750 = &DAT_10008380;
    _DAT_1000c758 = &DAT_1000837c;
    _DAT_1000c760 = &DAT_10008378;
    _DAT_1000c764 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1000c748)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x1000172b;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1000c74c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10001737;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10001737:
  *(undefined4 *)(puVar4 + -4) = 0x1000173c;
  return uVar2;
}



// Function: FUN_10001750 at 10001750

int __cdecl FUN_10001750(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0x2f < uVar1) {
    if (uVar1 < 0x3a) {
      return uVar1 - 0x30;
    }
    if (0x40 < uVar1) {
      if (uVar1 < 0x47) {
        return uVar1 - 0x37;
      }
      if (uVar1 - 0x61 < 6) {
        return uVar1 - 0x57;
      }
    }
  }
  return (uint)(byte)(param_1 >> 8) << 8;
}



// Function: FUN_10001786 at 10001786

undefined4 __cdecl FUN_10001786(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10008488)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000848c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_100017b4 at 100017b4

LPCWSTR __cdecl FUN_100017b4(LPCWSTR param_1,WCHAR param_2)

{
  LPCWSTR pWVar1;
  
  pWVar1 = param_1;
  if (param_1 != (LPCWSTR)0x0) {
    for (; (pWVar1 = (LPCWSTR)0x0, *param_1 != L'\0' && (pWVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextW(param_1)) {
    }
  }
  return pWVar1;
}



// Function: FUN_100017e1 at 100017e1

undefined4 FUN_100017e1(ushort param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 9) || (((10 < param_1 && (param_1 != 0xd)) && (param_1 != 0x20)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// Function: FUN_10001807 at 10001807

void __fastcall FUN_10001807(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_100017e1(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10001829 at 10001829

undefined4 __thiscall FUN_10001829(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10001807((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  WVar1 = **this;
  if (WVar1 == L'\0') {
    uVar3 = 0x80020009;
  }
  else {
    puVar7 = param_1;
    if (WVar1 == L'\'') {
      pWVar4 = CharNextW(*this);
      *(LPWSTR *)this = pWVar4;
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_100015ba((undefined4 *)this), iVar5 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == L'\'') {
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
        }
                    /* WARNING: Load size is inaccurate */
        pWVar2 = *this;
        pWVar4 = CharNextW(pWVar2);
        *(LPWSTR *)this = pWVar4;
        iVar5 = (int)pWVar4 - (int)pWVar2 >> 1;
        if (param_1 + 0x1000 <= puVar7 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar6 = (int)pWVar2 - (int)puVar7;
          do {
            *puVar7 = *(undefined2 *)(iVar6 + (int)puVar7);
            puVar7 = puVar7 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
                    /* WARNING: Load size is inaccurate */
        pWVar4 = *this;
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == 0) {
        return 0x80020009;
      }
      *puVar7 = 0;
                    /* WARNING: Load size is inaccurate */
      pWVar4 = CharNextW(*this);
      *(LPWSTR *)this = pWVar4;
    }
    else {
      do {
                    /* WARNING: Load size is inaccurate */
        pWVar2 = *this;
        iVar5 = FUN_100017e1(*pWVar2);
        if (iVar5 != 0) break;
        pWVar4 = CharNextW(pWVar2);
        *(LPWSTR *)this = pWVar4;
        iVar5 = (int)pWVar4 - (int)pWVar2 >> 1;
        if (param_1 + 0x1000 <= puVar7 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar6 = (int)pWVar2 - (int)puVar7;
          do {
            *puVar7 = *(undefined2 *)(iVar6 + (int)puVar7);
            puVar7 = puVar7 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
                    /* WARNING: Load size is inaccurate */
      } while (**this != 0);
      *puVar7 = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_1000193f at 1000193f

undefined4 FUN_1000193f(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_100083d8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10008408);
  return 1;
}



// Function: FUN_1000196e at 1000196e

bool FUN_1000196e(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_100019a3 at 100019a3

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100019a3(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000c700 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10001829(this,param_1), -1 < iVar1)) {
    FUN_10001807((undefined4 *)this);
    iVar1 = FUN_10001829(this,local_2008);
    if (-1 < iVar1) {
      FUN_10001829(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001a08 at 10001a08

void __fastcall FUN_10001a08(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10001a1d at 10001a1d

undefined4 FUN_10001a1d(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1000c724;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10001a3c at 10001a3c

undefined4 __thiscall FUN_10001a3c(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1000c72c = *param_3;
    DAT_1000c730 = param_3[1];
    DAT_1000c734 = param_3[2];
    DAT_1000c738 = param_3[3];
  }
  piVar2 = DAT_1000c884;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_1000c884, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_1000c884 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_1000c884;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_1000c888; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10001a9a at 10001a9a

void FUN_10001a9a(int param_1)

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



// Function: FID_conflict:_Inside at 10001b04

/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Inside(unsigned short const *)
    public: bool __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Inside(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

uint __thiscall FID_conflict__Inside(void *this,undefined4 *param_1)

{
  undefined4 *in_EAX;
  void *pvVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    in_EAX = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      in_EAX = *this;
    }
    if (in_EAX <= param_1) {
      pvVar1 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar1 = *this;
      }
      in_EAX = (undefined4 *)((int)pvVar1 + *(int *)((int)this + 0x10) * 2);
      if (param_1 < in_EAX) {
        return CONCAT31((int3)((uint)in_EAX >> 8),1);
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}



// Function: FUN_10001b40 at 10001b40

void __fastcall FUN_10001b40(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001b5a at 10001b5a

void __fastcall FUN_10001b5a(undefined4 *param_1)

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



// Function: FUN_10001b87 at 10001b87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001b87(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001b93;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x80000000) &&
     (pvVar1 = operator_new((int)param_1 * 2), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10009970);
}



// Function: FUN_10001c18 at 10001c18

void __fastcall FUN_10001c18(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001c25 at 10001c25

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001c25(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_10007164;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10001c4f at 10001c4f

int __thiscall FUN_10001c4f(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
                    /* WARNING: Load size is inaccurate */
      iVar1 = lstrcmpiW(*(LPCWSTR *)(*this + iVar2 * 4),(LPCWSTR)*param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  return -1;
}



// Function: FUN_10001c86 at 10001c86

void __fastcall FUN_10001c86(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10001c90 at 10001c90

void __thiscall FUN_10001c90(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_10001153(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10001cb5

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_10001153(lVar1);
  }
  return local_8;
}



// Function: FUN_10001cda at 10001cda

void FUN_10001cda(void)

{
  return;
}



// Function: FUN_10001cdb at 10001cdb

int __fastcall FUN_10001cdb(int param_1)

{
  long lVar1;
  
  FUN_100013ad(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1000c728 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1000c718 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10001d1c at 10001d1c

void __fastcall FUN_10001d1c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001a9a((int)piVar1);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar2 = *(int **)(param_1 + 0x28);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *piVar1 = 0;
  }
  return;
}



// Function: FUN_10001d55 at 10001d55

void __fastcall FUN_10001d55(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001a9a((int)piVar1);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar2 = *(int **)(param_1 + 0x28);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *piVar1 = 0;
  }
  return;
}



// Function: FUN_10001d5a at 10001d5a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001d5a(int param_1)

{
  FUN_10001d1c(param_1);
  return;
}



// Function: FUN_10001d78 at 10001d78

LSTATUS __fastcall FUN_10001d78(undefined4 *param_1)

{
  LSTATUS LVar1;
  
  LVar1 = 0;
  if ((HKEY)*param_1 != (HKEY)0x0) {
    LVar1 = RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return LVar1;
}



// Function: FUN_10001d7d at 10001d7d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10001d7d(void *this,LPCWSTR param_1)

{
  int iVar1;
  LSTATUS LVar2;
  _FILETIME local_230;
  LPCWSTR local_228;
  HKEY local_224;
  undefined4 local_220;
  undefined4 local_21c;
  DWORD local_218;
  WCHAR local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x220;
  local_228 = param_1;
  local_224 = (HKEY)0x0;
  local_220 = 0;
  local_21c = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = Open(&local_224,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    do {
      local_218 = 0x100;
      LVar2 = RegEnumKeyExW(local_224,0,local_214,&local_218,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
      if (LVar2 != 0) {
        ATL::CRegKey::Close((CRegKey *)&local_224);
        DeleteSubKey(this,local_228);
        break;
      }
      iVar1 = FUN_10001d7d(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_100066e7();
  return;
}



// Function: FUN_10001e62 at 10001e62

undefined4 __fastcall FUN_10001e62(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = param_1[2];
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      if ((iVar4 < 0) || (iVar2 <= iVar4)) {
LAB_10001ea7:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_10001ea7;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10001b5a(param_1);
  return 0;
}



// Function: FUN_10001eb9 at 10001eb9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10001eb9(void *this,LPCWSTR param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  uVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    local_14[0] = 0;
    local_8 = 0;
    iVar2 = lstrlenW(param_1);
    uVar1 = FUN_1000161a(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
  }
  return uVar1;
}



// Function: FUN_10001f00 at 10001f00

void FUN_10001f00(int param_1)

{
  FUN_10001e62((int *)(param_1 + 4));
  return;
}



// Function: FUN_10001f15 at 10001f15

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10001f15(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  DWORD DVar2;
  LPCWSTR lpsz;
  uint uVar3;
  int iVar4;
  errno_t eVar5;
  undefined4 uVar6;
  LPCWSTR pWVar7;
  LPCWSTR pWVar8;
  int local_248;
  LPCWSTR local_244;
  LPCWSTR local_240;
  WCHAR local_23c [270];
  wchar_t local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x240;
  local_8 = 0x10001f24;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_100020ef;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000121b();
  }
  else if (DVar2 != 0x104) {
    pWVar7 = (LPCWSTR)0x0;
    lpsz = local_23c;
    local_240 = lpsz;
    if (local_23c[0] != L'\0') {
      do {
        pWVar8 = lpsz;
        if ((local_23c[0] != L'.') && (pWVar8 = pWVar7, local_23c[0] == L'\\')) {
          pWVar8 = (LPCWSTR)0x0;
        }
        lpsz = CharNextW(lpsz);
        local_23c[0] = *lpsz;
        pWVar7 = pWVar8;
      } while (local_23c[0] != L'\0');
      local_240 = lpsz;
      if (pWVar8 != (LPCWSTR)0x0) {
        local_240 = pWVar8;
      }
    }
    if (local_244 != (LPCWSTR)0x0) {
      uVar3 = lstrlenW(local_244);
      uVar1 = uVar3 + DVar2;
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10001f82;
      FUN_100011c3(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_100020bf;
      }
    }
    else {
LAB_100020bf:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10001f82:
  local_8 = 0xffffffff;
  FUN_10001b40(&local_248);
LAB_100020ef:
  FUN_100066e7();
  return;
}



// Function: FUN_100020f7 at 100020f7

void __fastcall FUN_100020f7(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_1000c884;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_1000c884, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_1000c888; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10001d1c(param_1);
  return;
}



// Function: FID_conflict:_Tidy at 10002149

/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Tidy(bool,unsigned int)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Tidy(bool,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall FID_conflict__Tidy(void *this,char param_1,int param_2)

{
  void *_Src;
  
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    _Src = *this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2 * 2);
    }
    operator_delete(_Src);
  }
  *(int *)((int)this + 0x10) = param_2;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)((int)this + param_2 * 2) = 0;
  return;
}



// Function: FUN_10002192 at 10002192

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10002192(void *this,byte param_1)

{
  int *piVar1;
  
  if ((param_1 & 2) == 0) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    piVar1 = (int *)this;
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    piVar1 = (int *)((int)this + -4);
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001ae3);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_100021ef at 100021ef

void __fastcall FUN_100021ef(undefined4 *param_1)

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



// Function: FUN_100021f4 at 100021f4

void __fastcall FUN_100021f4(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10002204 at 10002204

void __fastcall FUN_10002204(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10001c86(param_1);
    return;
  }
  return;
}



// Function: FUN_10002211 at 10002211

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002211(int param_1)

{
  FUN_10001c25((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10002232 at 10002232

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10002232(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_3;
  }
  return;
}



// Function: FUN_10002286 at 10002286

void __fastcall FUN_10002286(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000229d at 1000229d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000229d(undefined4 *param_1)

{
  FUN_10001cdb((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_1000c73c = param_1;
  return param_1;
}



// Function: FUN_100022d2 at 100022d2

void __fastcall FUN_100022d2(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100022dd at 100022dd

void __fastcall FUN_100022dd(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100022e8 at 100022e8

HRESULT __thiscall FUN_100022e8(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  HVar1 = 0;
  if (param_1 == (undefined4 *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    ppv = (LPVOID *)((int)this + 0x28);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_10008b98,(LPUNKNOWN)0x0,1,(IID *)&DAT_100086a0,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10002334 at 10002334

undefined4 FUN_10002334(void)

{
  return 0x80004005;
}



// Function: FUN_1000233c at 1000233c

void FUN_1000233c(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_100086b0);
  return;
}



// Function: FUN_10002356 at 10002356

undefined4 FUN_10002356(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001a3c(&DAT_1000c7dc,(int *)&PTR_DAT_1000c000,param_1,(undefined4 *)&DAT_10008398);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100020f7(0x1000c7dc);
  }
  return 1;
}



// Function: FUN_10002398 at 10002398

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002398(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10001d1c((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100023cf at 100023cf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100023cf(int *param_1)

{
  FUN_10001e62(param_1);
  FUN_10001b5a(param_1);
  return;
}



// Function: FUN_100023f9 at 100023f9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100023f9(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_10001e62(param_1 + 1);
  FUN_100023cf(param_1 + 1);
  return;
}



// Function: FUN_1000242d at 1000242d

undefined4 FUN_1000242d(void)

{
  return 0x80004001;
}



// Function: FUN_10002435 at 10002435

undefined4 FUN_10002435(void)

{
  return 1;
}



// Function: FUN_1000243b at 1000243b

undefined4 FUN_1000243b(void)

{
  return 0;
}



// Function: FUN_10002440 at 10002440

undefined4 * __thiscall FUN_10002440(void *this,byte param_1)

{
  FUN_100023f9((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000245f at 1000245f

undefined4 __fastcall FUN_1000245f(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10001c4f((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  if (iVar2 == -1) {
    uVar3 = 0;
  }
  else {
    if ((iVar2 < 0) || (*(int *)(param_1 + 0xc) <= iVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + iVar2 * 4);
  }
  return uVar3;
}



// Function: FUN_100024a0 at 100024a0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100024a0(void *this,LPCWSTR param_1,int *param_2)

{
  WCHAR WVar1;
  LPVOID pvVar2;
  int iVar3;
  wchar_t *pwVar4;
  LPWSTR pWVar5;
  LPCWSTR pWVar6;
  rsize_t _MaxCount;
  errno_t eVar7;
  LPCWSTR pWVar8;
  undefined4 local_70;
  undefined4 local_6c;
  LPVOID local_68;
  int local_64;
  char local_5d;
  int local_5c;
  char local_56;
  char local_55;
  wchar_t local_54 [38];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x100024ac;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_100015da(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10001a1d(&local_5d);
      if (-1 < local_5c) {
        local_64 = 0;
        local_56 = '\0';
        local_55 = '\0';
        WVar1 = *param_1;
        while (WVar1 != L'\0') {
          if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (((local_64 != 0) || (pwVar4 = wcsstr(*this,L"HKCR"), pwVar4 == (wchar_t *)0x0)) ||
               (pwVar4 != *this)) {
LAB_10002595:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10002609;
                }
                iVar3 = FUN_100015ba((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_1000161a(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_1000262f;
                  goto LAB_100025d1;
                }
                local_55 = '\0';
              }
              else {
LAB_100025d1:
                if (local_55 != '\0') goto LAB_10002609;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10001eb9(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_1000262f;
                local_56 = '\0';
              }
              goto LAB_10002609;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10001eb9(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10002595;
            }
LAB_1000262f:
            local_5c = -0x7ff8fff2;
            goto LAB_10002510;
          }
LAB_10002609:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_100017b4(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10002510;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_1000245f(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10001eb9(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_1000262f;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_100026a2;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10002510;
            }
            iVar3 = FUN_1000161a(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_1000262f;
          }
          else {
            iVar3 = FUN_1000161a(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_100026a2:
                    /* WARNING: Load size is inaccurate */
          pWVar5 = CharNextW(*this);
          *(LPWSTR *)this = pWVar5;
          WVar1 = *pWVar5;
        }
        pvVar2 = local_68;
        if (-1 < local_5c) {
          local_68 = (LPVOID)0x0;
          local_70 = 0;
          local_6c = 0;
          *param_2 = (int)pvVar2;
        }
      }
LAB_10002510:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_100066e7();
  return;
}



// Function: ~basic_string<> at 1000270d

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::~basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(void)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::~basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(void)
   
   Library: Visual Studio 2010 Release */

void __fastcall ~basic_string<>(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10002717 at 10002717

undefined4 * __thiscall FUN_10002717(void *this,uint param_1,uint param_2)

{
  uint extraout_EAX;
  uint uVar1;
  int iVar2;
  uint extraout_ECX;
  void *pvVar3;
  void *pvVar4;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar1 = extraout_EAX;
    param_1 = extraout_ECX;
  }
  uVar1 = uVar1 - param_1;
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  if (param_2 != 0) {
    pvVar4 = this;
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar3 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1 * 2),(void *)((int)pvVar3 + (param_1 + param_2) * 2),
            (uVar1 - param_2) * 2);
    iVar2 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar2;
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    *(undefined2 *)((int)pvVar3 + iVar2 * 2) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_10002798 at 10002798

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002798(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  HRESULT HVar3;
  errno_t eVar4;
  LSTATUS LVar5;
  int local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  HKEY local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  GUID *local_1b0;
  int *local_1ac;
  int *local_1a8;
  undefined4 local_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  OLECHAR local_194 [64];
  wchar_t local_114 [134];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1bc;
  local_1b0 = param_1;
  local_1a8 = (int *)0x0;
  local_8 = 1;
  if (((param_2 != (int *)0x0) &&
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_10008b88), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_10008ba8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000879c,&local_1a8
                              ), -1 < HVar3)) {
    iVar2 = *param_2;
    local_1ac = param_2;
    while (iVar2 != 0) {
      puVar1 = (undefined4 *)local_1ac[1];
      local_1a4 = *puVar1;
      uStack_1a0 = puVar1[1];
      uStack_19c = puVar1[2];
      uStack_198 = puVar1[3];
      if (param_3 == 0) {
        if (*local_1ac == 1) {
          (**(code **)(*local_1a8 + 0x18))();
        }
        else {
          (**(code **)(*local_1a8 + 0x20))(local_1a8,local_1b0,1,&local_1a4);
        }
      }
      else {
        if (*local_1ac == 1) {
          iVar2 = (**(code **)(*local_1a8 + 0x14))();
        }
        else {
          iVar2 = (**(code **)(*local_1a8 + 0x1c))(local_1a8);
        }
        if (iVar2 < 0) {
          local_8 = 0xffffffff;
          if (local_1a8 != (int *)0x0) {
            (**(code **)(*local_1a8 + 8))(local_1a8);
          }
          goto LAB_10002a23;
        }
      }
      local_1ac = local_1ac + 2;
      iVar2 = *local_1ac;
    }
    if (param_3 == 0) {
      StringFromGUID2(local_1b0,local_194,0x40);
      local_1cc = 0;
      local_8._0_1_ = 6;
      eVar4 = wcscpy_s(local_114,0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Required Categories");
      ATL::AtlCrtErrorCheck(eVar4);
      local_1c8 = 0x80000000;
      local_1c4 = 0;
      local_1c0 = 0;
      local_1bc = (HKEY)0x0;
      local_1b8 = 0;
      local_1b4 = 0;
      local_8 = CONCAT31(local_8._1_3_,8);
      local_1ac = (int *)0x0;
      iVar2 = Open(&local_1bc,(HKEY)0x80000000,local_114,0x20019);
      if (iVar2 == 0) {
        local_1b0 = (GUID *)RegQueryInfoKeyW(local_1bc,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (LPDWORD)&local_1ac,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (PFILETIME)0x0);
        ATL::CRegKey::Close((CRegKey *)&local_1bc);
        if ((local_1b0 == (GUID *)0x0) && (local_1ac == (int *)0x0)) {
          DeleteSubKey(&local_1c8,local_114);
        }
      }
      eVar4 = wcscpy_s(local_114,0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Implemented Categories");
      ATL::AtlCrtErrorCheck(eVar4);
      iVar2 = Open(&local_1bc,(HKEY)0x80000000,local_114,0x20019);
      if (iVar2 == 0) {
        LVar5 = RegQueryInfoKeyW(local_1bc,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&local_1ac
                                 ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(PFILETIME)0x0);
        ATL::CRegKey::Close((CRegKey *)&local_1bc);
        if ((LVar5 == 0) && (local_1ac == (int *)0x0)) {
          DeleteSubKey(&local_1c8,local_114);
        }
      }
      local_8._0_1_ = 7;
      ATL::CRegKey::Close((CRegKey *)&local_1bc);
      local_8._0_1_ = 6;
      ATL::CRegKey::Close((CRegKey *)&local_1c8);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10001b40(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10002a23:
  FUN_100066e7();
  return;
}



// Function: FUN_10002ab6 at 10002ab6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10002ab6(HMODULE param_1,LPCWSTR param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  undefined4 local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_18 = 0;
  local_14[0] = (int *)0x0;
  local_8 = 2;
  iVar1 = FUN_10001f15(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10001a1d((undefined1 *)((int)&param_2 + 3));
    if (-1 < iVar1) {
      if (((param_2._3_1_ != '\x01') ||
          (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
         (pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser"), pFVar2 == (FARPROC)0x0)) {
        pFVar2 = Ordinal_186_exref;
      }
      iVar1 = (*pFVar2)(param_1,(uint)(ushort)param_1[6].unused,
                        (uint)*(ushort *)((int)&param_1[6].unused + 2),param_1[4].unused,
                        param_1[5].unused);
      (**(code **)(*local_14[0] + 0x30))(local_14[0],param_1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  return iVar1;
}



// Function: FUN_10002b86 at 10002b86

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002b86(HMODULE param_1,LPCWSTR param_2)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  int iVar2;
  rsize_t _MaxCount;
  errno_t eVar3;
  LPWSTR pWVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  WCHAR *pWVar6;
  LPCWSTR pWVar7;
  undefined4 local_22c;
  int *local_228;
  wchar_t *local_224;
  char local_21d;
  WCHAR local_21c [259];
  undefined2 local_16;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_22c = 0;
  local_228 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = FUN_10001f15(param_1,param_2,&local_22c,&local_228);
  if (-1 < iVar2) {
    pWVar6 = (WCHAR *)0x0;
    local_224 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar2 = (**(code **)(*local_228 + 0x24))(local_228,0xffffffff,0,0,0,&local_224);
    if ((-1 < iVar2) && (local_224 != (wchar_t *)0x0)) {
      _MaxCount = Ordinal_7(local_224);
      eVar3 = wcsncpy_s(local_21c,0x104,local_224,_MaxCount);
      ATL::AtlCrtErrorCheck(eVar3);
      pWVar7 = local_21c;
      local_16 = 0;
      lpsz = pWVar7;
      while (local_21c[0] != L'\0') {
        pWVar4 = CharNextW(lpsz);
        WVar1 = *lpsz;
        if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
          pWVar7 = pWVar4;
        }
        lpsz = pWVar4;
        local_21c[0] = *pWVar4;
      }
      local_21c[(int)pWVar7 - (int)local_21c >> 1] = L'\0';
      pWVar6 = local_21c;
    }
    local_21d = '\0';
    iVar2 = FUN_10001a1d(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10002d48;
    }
    if (((local_21d != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser"), pFVar5 == (FARPROC)0x0)) {
      pFVar5 = Ordinal_163_exref;
    }
    (*pFVar5)(local_228,local_22c,pWVar6);
    local_8._0_1_ = 2;
    Ordinal_6(local_224);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_228 != (int *)0x0) {
    (**(code **)(*local_228 + 8))(local_228);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_22c);
LAB_10002d48:
  FUN_100066e7();
  return;
}



// Function: FUN_10002d50 at 10002d50

int FUN_10002d50(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    param_1 = -0x7ff8ffa9;
  }
  else {
    piVar6 = *(int **)(param_1 + 8);
    param_1 = 0;
    if (piVar6 < *(int **)(iVar2 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar6;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar3 = FUN_10001030(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10002798((GUID *)*puVar1,piVar5,iVar7);
          if (param_1 < 0) {
            return param_1;
          }
        }
        piVar6 = piVar6 + 1;
      } while (piVar6 < *(int **)(iVar2 + 0xc));
      if (param_1 < 0) {
        return param_1;
      }
    }
    if (param_2 != 0) {
      param_1 = FUN_10002b86(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10002dd6 at 10002dd6

int FUN_10002dd6(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    param_1 = -0x7ff8ffa9;
  }
  else {
    param_1 = 0;
    piVar5 = *(int **)(iVar2 + 8);
    if (piVar5 < *(int **)(iVar2 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar3 = FUN_10001030(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10002798((GUID *)*puVar1,piVar4,iVar6);
          if (iVar6 < 0) {
            return iVar6;
          }
          param_1 = (*(code *)puVar1[1])(0);
          if (param_1 < 0) {
            return param_1;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(iVar2 + 0xc));
      if (param_1 < 0) {
        return param_1;
      }
    }
    if (param_2 != 0) {
      param_1 = FUN_10002ab6(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10002e5d at 10002e5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10002e5d(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar3;
  
  if (param_4 == (int *)0x0) {
    param_1 = (int *)0x80004003;
  }
  else {
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      param_1 = (int *)0x80070057;
    }
    else if (*param_1 == 0) {
      param_1 = (int *)0x8000ffff;
    }
    else {
      for (piVar3 = (int *)param_1[2]; piVar3 < (int *)param_1[3]; piVar3 = piVar3 + 1) {
        puVar1 = (undefined4 *)*piVar3;
        if (((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) &&
           (iVar2 = _InlineIsEqualGUID(param_2,(int *)*puVar1), iVar2 != 0)) {
          piVar3 = puVar1 + 4;
          if (*piVar3 == 0) {
            lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
            EnterCriticalSection(lpCriticalSection);
            param_1 = (int *)0x0;
            if (*piVar3 == 0) {
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_100087fc,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10002f18;
          }
          else {
LAB_10002f18:
            param_1 = (int *)(*(code *)**(undefined4 **)*piVar3)
                                       ((undefined4 *)*piVar3,param_3,param_4);
          }
          if (*param_4 != 0) {
            return param_1;
          }
          if (param_1 != (int *)0x0) {
            return param_1;
          }
          break;
        }
      }
      param_1 = (int *)0x80040111;
    }
  }
  return param_1;
}



// Function: FUN_10002f48 at 10002f48

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10002f48(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_100013c4(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: InlineIsEqualUnknown at 10002f83

/* Library Function - Single Match
    int __stdcall ATL::InlineIsEqualUnknown(struct _GUID const &)
   
   Library: Visual Studio 2010 Release */

int ATL::InlineIsEqualUnknown(_GUID *param_1)

{
  int iVar1;
  
  if ((((param_1->Data1 == 0) &&
       (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar1 == 0)) &&
      (*(int *)param_1->Data4 == 0xc0)) && (*(int *)(param_1->Data4 + 4) == 0x46000000)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10002fb1 at 10002fb1

undefined4 FUN_10002fb1(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 != 0) && (iVar2 = ATL::InlineIsEqualUnknown(param_3), iVar2 == 0)) {
      return 0x80040110;
    }
    uVar1 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
  }
  return uVar1;
}



// Function: FUN_10002fef at 10002fef

undefined4 FUN_10002fef(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1000c728 + 8))();
  }
  else {
    (**(code **)(*DAT_1000c728 + 4))();
  }
  return 0;
}



// Function: FUN_1000300e at 1000300e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000300e(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001c25((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_1000303f at 1000303f

undefined4 * __thiscall FUN_1000303f(void *this,byte param_1)

{
  FUN_1000300e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000305e at 1000305e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000305e(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 0x30),'\x01',0);
  FUN_10001c25((LPCRITICAL_SECTION)(param_1 + 0x14));
  return;
}



// Function: FUN_1000309b at 1000309b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000309b(int param_1)

{
  FUN_1000305e(param_1);
  return;
}



// Function: FUN_100030b9 at 100030b9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100030b9(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = 0x7ffffffe, uVar1 <= 0x7ffffffe - uVar2)) {
      param_1 = uVar2 + uVar1;
    }
  }
  FUN_10001b87((char *)(param_1 + 1));
  FUN_1000314e();
  return;
}



// Function: Catch@10003120 at 10003120

undefined * Catch_10003120(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001b87((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10003148;
}



// Function: FUN_1000314e at 1000314e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000314e(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 != 0) {
    puVar2 = unaff_ESI;
    if (7 < (uint)unaff_ESI[5]) {
      puVar2 = (undefined4 *)*unaff_ESI;
    }
    memcpy(*(void **)(unaff_EBP + -0x18),puVar2,iVar1 * 2);
  }
  FID_conflict__Tidy(unaff_ESI,'\x01',0);
  puVar2 = *(undefined4 **)(unaff_EBP + -0x18);
  *unaff_ESI = puVar2;
  unaff_ESI[5] = unaff_EDI;
  unaff_ESI[4] = iVar1;
  if (unaff_EDI < 8) {
    puVar2 = unaff_ESI;
  }
  *(undefined2 *)((int)puVar2 + iVar1 * 2) = 0;
  return;
}



// Function: Catch@1000319c at 1000319c

void Catch_1000319c(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100031b1 at 100031b1

undefined4 __thiscall FUN_100031b1(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10002232(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 10003208

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2010 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,2);
  if (uVar1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10001c90(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10003237

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2010 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,2);
  if (uVar1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10001c90(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10003266

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2010 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  if (uVar1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10001c90(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10003295 at 10003295

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10003295(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_100013c4((void *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 7;
  *(undefined2 *)(param_1 + 0x30) = 0;
  return param_1;
}



// Function: FUN_100032db at 100032db

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100032db(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_10006598(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10003341();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10003335 at 10003335

undefined * Catch_10003335(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000333f;
}



// Function: FUN_10003341 at 10003341

void FUN_10003341(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
  iVar3 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
  uVar1 = iVar3 * 2 + 2;
  *(uint *)(unaff_EBP + -0x2c) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = unaff_ESI;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar2 = (ulonglong)uVar1 * 2;
  uVar4 = FUN_10006598(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10003392();
  return;
}



// Function: Catch@10003383 at 10003383

undefined * Catch_10003383(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10003390;
}



// Function: FUN_10003392 at 10003392

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10003392(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_EBP;
  void *unaff_ESI;
  
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  pvVar1 = *(void **)(unaff_EBP + -0x20);
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  if ((*(void **)(unaff_EBP + -0x14) != unaff_ESI) && (pvVar1 != unaff_ESI)) {
    FUN_100011a3(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_100011a3(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_100031b1(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_100033ee;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_100033ee:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10003426 at 10003426

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003426(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_14[0] = 0;
    local_8 = 0;
    iVar1 = FUN_100032db(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
  }
  return iVar1;
}



// Function: FUN_10003481 at 10003481

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003481(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_2144;
  wchar_t *local_2128;
  CRegKey *local_2124;
  wchar_t *local_2120;
  undefined4 local_211c [65];
  WCHAR local_2018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000767e;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1000c700 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_10001829(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_100016a8(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100037fa;
  FUN_10001807((undefined4 *)this);
  iVar1 = FUN_10001829(this,local_2018);
  if (iVar1 < 0) goto LAB_100037fa;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_100037d6:
    if (uVar2 != 0) {
      FUN_10001230(uVar2);
      goto LAB_100037fa;
    }
  }
  else {
    if (uVar2 == 0x11) {
      local_2120 = (wchar_t *)lstrlenW(local_2018);
      if (((uint)local_2120 & 1) == 0) {
        local_211c[0] = 0;
        local_8 = 5;
        Allocate(local_211c,(int)local_2120 / 2);
        local_8 = 4;
        FUN_10003709();
        return;
      }
      goto LAB_100037fa;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001b40((int *)&local_2124);
      goto LAB_100037d6;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_100035a2();
      return;
    }
  }
  FUN_10001829(this,param_3);
LAB_100037fa:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10003596 at 10003596

undefined * Catch_10003596(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100035a0;
}



// Function: FUN_100035a2 at 100035a2

void FUN_100035a2(void)

{
  WCHAR WVar1;
  LPWSTR lpsz;
  LPCWSTR lpsz_00;
  WCHAR *pWVar2;
  uint unaff_EBP;
  WCHAR *unaff_EDI;
  undefined4 uStack0000000c;
  
  pWVar2 = *(WCHAR **)(unaff_EBP - 0x2118);
  if (pWVar2 == unaff_EDI) {
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
    *pWVar2 = L'\0';
    pWVar2[1] = L'\0';
    pWVar2 = (WCHAR *)FUN_10001577(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10001c86((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10001829(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10001230((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10003812;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100036ee at 100036ee

undefined * Catch_100036ee(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_100036fb;
}



// Function: FUN_10003709 at 10003709

void FUN_10003709(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  size_t unaff_EBX;
  uint unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  undefined4 uStack0000000c;
  
  if (*(uint *)(unaff_EBP - 0x2118) == unaff_EDI) {
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_10001c86((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10001750(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
        *pbVar1 = *pbVar1 | (char)iVar2 << (4U - (char)((unaff_EDI & 1) << 2) & 0x1f);
        unaff_EDI = unaff_EDI + 1;
      } while ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c));
      unaff_EDI = 0;
      unaff_ESI = *(undefined4 **)(unaff_EBP - 0x2120);
    }
    uVar3 = RegSetValueExW((HKEY)*unaff_ESI,*(LPCWSTR *)(unaff_EBP - 0x2124),unaff_EDI,3,
                           *(BYTE **)(unaff_EBP - 0x2118),unaff_EBX);
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_10001c86((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10001829(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10001230(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10003812;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10003816 at 10003816

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003816(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  LPCWSTR pWVar5;
  uint uVar6;
  errno_t eVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  CRegKey *pCVar8;
  HKEY local_2268;
  undefined4 local_2264;
  undefined4 local_2260;
  HKEY local_225c;
  undefined4 local_2258;
  undefined4 local_2254;
  HKEY local_2250;
  undefined4 local_224c;
  undefined4 local_2248;
  HKEY local_2244;
  undefined4 local_2240;
  undefined4 local_223c;
  int local_2238;
  HKEY local_2234;
  undefined4 local_2230;
  undefined4 local_222c;
  HKEY local_2228;
  uint local_2224;
  void *local_2220;
  wchar_t local_221c [4096];
  wchar_t local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar1 = param_4;
  puStack_c = &LAB_100076dd;
  local_10 = ExceptionList;
  local_14 = DAT_1000c700 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000387a:
  iVar3 = FUN_10001829(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000388a:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10003ce7:
    if (*param_1 == L'}') goto LAB_1000388a;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10001829(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000388a;
      if (param_3 == 0) goto LAB_100039c9;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_100017b4(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_1000193f(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10001d7d(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_100039c9;
        }
        iVar3 = FUN_10001829(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_100019a3(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_10003de6;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_10003e65;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000388a;
    }
LAB_100039c9:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_10001829(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000388a;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_100017b4(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        if (param_3 == 0) {
          if (iVar1 == 0) {
            local_2224 = Open(&local_2234,local_2228,param_1,0x20019);
          }
          else {
            local_2224 = 2;
          }
          param_4 = iVar1;
          if (local_2224 != 0) {
            param_4 = 1;
          }
          eVar7 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
          ATL::AtlCrtErrorCheck(eVar7);
          iVar3 = FUN_10001829(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_100019a3(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10003816(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10001829(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_10003e84;
          iVar3 = FUN_10001829(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10003481(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10003deb;
        }
      }
      goto LAB_1000388a;
    }
    iVar3 = FUN_10001829(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10001829(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000388a;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10003481(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_10003de6;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_10003e65;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10001230(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_10003e65:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000388a;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_100019a3(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_1000196e(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_1000193f(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10001d7d(&local_2234,local_21c);
        }
        goto LAB_10003ce7;
      }
      bVar2 = FUN_1000196e(local_2234);
      local_2224 = CONCAT31(extraout_var_00,bVar2);
      uVar6 = ATL::CRegKey::Close((CRegKey *)&local_2234);
      if (uVar6 == 0) {
        if ((local_2238 != 0) && (local_2224 == 0)) {
          local_8._0_1_ = 4;
          local_2250 = local_2228;
          local_224c = 0;
          local_2248 = 0;
          uVar6 = DeleteSubKey(&local_2250,local_21c);
          local_2250 = (HKEY)0x0;
          local_224c = 0;
          local_2248 = 0;
          if (uVar6 != 0) {
            FUN_10001230(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_10003e65;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_10003de6:
          ATL::CRegKey::Close(pCVar8);
LAB_10003deb:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10003816(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000387a;
            goto LAB_1000388a;
          }
        }
        goto LAB_10003ce7;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_10003ce7;
    }
LAB_10003e84:
    FUN_10001230(uVar6);
    goto LAB_1000388a;
  }
  goto LAB_10003ce7;
}



// Function: FUN_10003ead at 10003ead

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10003ead(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *local_14;
  
  *param_3 = 0;
  puVar3 = *(undefined4 **)((int)this + 0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    for (; (int *)*puVar3 != (int *)0x0; puVar3 = puVar3 + 9) {
      if ((puVar3[2] != 0) && (iVar1 = _InlineIsEqualGUID(param_1,(int *)*puVar3), iVar1 != 0)) {
        piVar2 = puVar3 + 4;
        if (*piVar2 == 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000c88c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_100087fc,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000c88c);
          if (*piVar2 != 0) goto LAB_10003f41;
        }
        else {
LAB_10003f41:
          local_14 = (int *)(*(code *)**(undefined4 **)*piVar2)
                                      ((undefined4 *)*piVar2,param_2,param_3);
        }
        if (*param_3 != 0) {
          return local_14;
        }
        if (local_14 != (int *)0x0) {
          return local_14;
        }
        break;
      }
    }
  }
  piVar2 = FUN_10002e5d((int *)&DAT_1000c87c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_10003f79 at 10003f79

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003f79(undefined4 *param_1)

{
  FUN_10002f48(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: AtlInternalQueryInterface at 10003fa7

/* Library Function - Single Match
    long __stdcall ATL::AtlInternalQueryInterface(void *,struct ATL::_ATL_INTMAP_ENTRY const
   *,struct _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlInternalQueryInterface
               (void *param_1,_ATL_INTMAP_ENTRY *param_2,_GUID *param_3,void **param_4)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_ATL_INTMAP_ENTRY *)0x0)) {
    lVar2 = -0x7ff8ffa9;
  }
  else if (param_4 == (void **)0x0) {
    lVar2 = -0x7fffbffd;
  }
  else {
    *param_4 = (void *)0x0;
    iVar3 = InlineIsEqualUnknown(param_3);
    if (iVar3 == 0) {
      for (; pcVar1 = *(code **)(param_2 + 8), pcVar1 != (code *)0x0; param_2 = param_2 + 0xc) {
        piVar4 = *(int **)param_2;
        if ((piVar4 == (int *)0x0) ||
           (iVar3 = _InlineIsEqualGUID(piVar4,(int *)param_3), iVar3 != 0)) {
          if (pcVar1 == (code *)0x1) goto LAB_10003fdb;
          iVar3 = (*pcVar1)(param_1,param_3,param_4,*(undefined4 *)(param_2 + 4));
          if (iVar3 == 0) {
            return 0;
          }
          if ((piVar4 != (int *)0x0) && (iVar3 < 0)) {
            return iVar3;
          }
        }
      }
      lVar2 = -0x7fffbffe;
    }
    else {
LAB_10003fdb:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10004048 at 10004048

LONG FUN_10004048(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1000c728 + 4))();
  }
  return LVar1;
}



// Function: FUN_10004072 at 10004072

LONG FUN_10004072(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1000c728 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 100040b1

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10008844,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100040cb at 100040cb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100040cb(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_1000300e(param_1);
  return;
}



// Function: FUN_100040fa at 100040fa

undefined4 * __thiscall FUN_100040fa(void *this,byte param_1)

{
  FUN_100040cb((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004119 at 10004119

bool __thiscall FUN_10004119(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_100030b9(this,param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      *(undefined2 *)this = 0;
    }
  }
  else {
    uVar1 = *(uint *)((int)this + 0x10);
    if (param_1 < *(uint *)((int)this + 0x10)) {
      uVar1 = param_1;
    }
    FID_conflict__Tidy(this,'\x01',uVar1);
  }
  return param_1 != 0;
}



// Function: FUN_10004183 at 10004183

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10004183(undefined4 *param_1)

{
  FUN_10003295((int)param_1);
  *param_1 = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  (**(code **)(*DAT_1000c728 + 4))();
  return param_1;
}



// Function: AtlComQIPtrAssign at 100041d1

/* Library Function - Single Match
    struct IUnknown * __stdcall ATL::AtlComQIPtrAssign(struct IUnknown * *,struct IUnknown *,struct
   _GUID const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

IUnknown * ATL::AtlComQIPtrAssign(IUnknown **param_1,IUnknown *param_2,_GUID *param_3)

{
  IUnknown *pIVar1;
  
  if (param_1 == (IUnknown **)0x0) {
    pIVar1 = (IUnknown *)0x0;
  }
  else {
    pIVar1 = *param_1;
    *param_1 = (IUnknown *)0x0;
    if (param_2 != (IUnknown *)0x0) {
      (*param_2->lpVtbl->QueryInterface)(param_2,param_3,param_1);
    }
    if (pIVar1 != (IUnknown *)0x0) {
      (*pIVar1->lpVtbl->Release)(pIVar1);
    }
    pIVar1 = *param_1;
  }
  return pIVar1;
}



// Function: Attach at 10004208

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



// Function: FUN_10004227 at 10004227

undefined4 FUN_10004227(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



// Function: FUN_10004262 at 10004262

void FUN_10004262(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: Release at 10004276

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_100042a3 at 100042a3

void FUN_100042a3(int param_1)

{
  Release((int *)(param_1 + -8));
  return;
}



// Function: FUN_100042ad at 100042ad

void FUN_100042ad(int param_1)

{
  Release((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_100042b7 at 100042b7

void FUN_100042b7(int param_1)

{
  FUN_10004262(param_1 + -4);
  return;
}



// Function: FUN_100042c1 at 100042c1

void FUN_100042c1(int param_1)

{
  FUN_10004262(param_1 + -8);
  return;
}



// Function: FUN_100042cb at 100042cb

void FUN_100042cb(int param_1)

{
  FUN_10004262(param_1 + -0xc);
  return;
}



// Function: FUN_100042d5 at 100042d5

void FUN_100042d5(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_100042df at 100042df

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100042df(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10004304 at 10004304

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10004304(void *this,wchar_t *param_1)

{
  ushort uVar1;
  uint uVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  CComBSTR *this_00;
  int local_24;
  undefined4 *local_20;
  uint *local_1c;
  uint *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pwVar3 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x10004310;
  local_20 = (undefined4 *)this;
  iVar5 = (**(code **)(*(int *)param_1 + 0xc))(param_1,&local_24);
  if (-1 < iVar5) {
    local_1c = (uint *)0x0;
    uVar1 = *(ushort *)(local_24 + 0x2c);
    *(uint *)((int)this + 0x18) = (uint)uVar1;
    *(undefined4 *)((int)this + 0x14) = 0;
    if (uVar1 != 0) {
      local_8 = 0;
      uVar2 = *(uint *)((int)this + 0x18);
      uVar8 = -(uint)((int)((ulonglong)uVar2 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar2 * 0xc);
      local_18 = (uint *)FUN_10006598(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10004239,
                   (_func_void_void_ptr *)&LAB_10001ae3);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_100043b4();
      return uVar7;
    }
    local_18 = (uint *)0x0;
    if (0 < *(int *)((int)this + 0x18)) {
      this_00 = (CComBSTR *)0x0;
      do {
        iVar5 = (**(code **)(*(int *)pwVar3 + 0x14))(pwVar3,local_18,&local_20);
        if (-1 < iVar5) {
          param_1 = (wchar_t *)0x0;
          local_8 = 3;
          iVar5 = (**(code **)(*(int *)pwVar3 + 0x30))(pwVar3,*local_20,&param_1,0,0,0);
          pwVar4 = param_1;
          if (-1 < iVar5) {
            param_1 = (wchar_t *)0x0;
            ATL::CComBSTR::Attach(this_00,pwVar4);
            uVar7 = Ordinal_7(*(undefined4 *)this_00);
            *(undefined4 *)(this_00 + 4) = uVar7;
            *(undefined4 *)(this_00 + 8) = *local_20;
          }
          (**(code **)(*(int *)pwVar3 + 0x50))(pwVar3,local_20);
          local_8 = 0xffffffff;
          Ordinal_6(param_1);
        }
        local_18 = (uint *)((int)local_18 + 1);
        this_00 = this_00 + 0xc;
      } while ((int)local_18 < *(int *)((int)this + 0x18));
    }
    *(uint **)((int)this + 0x14) = local_1c;
    (**(code **)(*(int *)pwVar3 + 0x4c))(pwVar3,local_24);
  }
  return 0;
}



// Function: Catch@100043a4 at 100043a4

undefined * Catch_100043a4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100043ae;
}



// Function: FUN_100043b4 at 100043b4

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100043b4(void)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  CComBSTR *this;
  
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    (**(code **)(*unaff_EBX + 0x4c))();
    uVar2 = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (0 < *(int *)(unaff_ESI + 0x18)) {
      this = *(CComBSTR **)(unaff_EBP + -0x18);
      do {
        iVar3 = (**(code **)(*unaff_EBX + 0x14))();
        if (-1 < iVar3) {
          *(undefined4 *)(unaff_EBP + 8) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          iVar3 = (**(code **)(*unaff_EBX + 0x30))();
          if (-1 < iVar3) {
            pwVar1 = *(wchar_t **)(unaff_EBP + 8);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            ATL::CComBSTR::Attach(this,pwVar1);
            uVar2 = Ordinal_7(*(undefined4 *)this);
            *(undefined4 *)(this + 4) = uVar2;
            *(undefined4 *)(this + 8) = **(undefined4 **)(unaff_EBP + -0x1c);
          }
          (**(code **)(*unaff_EBX + 0x50))();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        this = this + 0xc;
      } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_ESI + 0x18));
    }
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
    (**(code **)(*unaff_EBX + 0x4c))();
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000446c at 1000446c

void FUN_1000446c(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10002192(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: QueryInterface at 1000449f

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100088d4,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100044b9 at 100044b9

void FUN_100044b9(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100044c3 at 100044c3

void FUN_100044c3(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_100044cd at 100044cd

void FUN_100044cd(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_100044d7 at 100044d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_100044d7(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (param_1 == (undefined4 *)0x0) {
      return true;
    }
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_18 = (int *)0x0;
    local_14[0] = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
                    /* WARNING: Load size is inaccurate */
    (**(code **)**this)(*this,&DAT_100087fc,&local_18);
    (**(code **)*param_1)(param_1,&DAT_100087fc,local_14);
    bVar1 = local_18 == local_14[0];
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8 = 0xffffffff;
    if (local_18 == (int *)0x0) {
      return bVar1;
    }
    (**(code **)(*local_18 + 8))(local_18);
    return bVar1;
  }
  return false;
}



// Function: FUN_10004562 at 10004562

int __fastcall FUN_10004562(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10004566 at 10004566

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004566(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_100045ab();
  return uVar1;
}



// Function: Catch@1000459b at 1000459b

undefined * Catch_1000459b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100045a5;
}



// Function: FUN_100045ab at 100045ab

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100045ab(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI == (undefined4 *)0x0) {
    *(undefined4 *)(unaff_EBP + 8) = 0x8007000e;
  }
  else {
    *unaff_ESI = *(undefined4 *)(unaff_EBP + 0xc);
    unaff_ESI[1] = *(undefined4 *)(unaff_EBP + 0x10);
    lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 0xc);
    *(LPCRITICAL_SECTION *)(unaff_EBP + -0x1c) = lpCriticalSection;
    *(undefined1 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    EnterCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x18) = 1;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    unaff_ESI[2] = *(undefined4 *)(unaff_EDI + 8);
    *(undefined4 **)(unaff_EDI + 8) = unaff_ESI;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    LeaveCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x18) = 0;
  }
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10004606 at 10004606

IUnknown * __thiscall FUN_10004606(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_100044d7(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10008960);
  }
  return pIVar2;
}



// Function: FUN_10004633 at 10004633

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004633(void *this,undefined4 param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  DWORD DVar3;
  code *pcVar4;
  void *pvVar5;
  int *local_230;
  int *local_22c;
  int *local_228;
  int *local_224;
  int local_220;
  WCHAR local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x22c;
  local_8 = 0x10004642;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10004878;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1000c728 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_1000c72c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_1000c8a8,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10004842;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001b40((int *)&local_224);
    }
    if (-1 < local_220) {
      local_228 = (int *)0x0;
      local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
      local_220 = (**(code **)(*local_230 + 0x18))(local_230,*this,&local_228);
      if (-1 < local_220) {
        local_22c = local_228;
        if (local_228 != (int *)0x0) {
          (**(code **)(*local_228 + 4))(local_228);
        }
        local_224 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        iVar2 = (**(code **)*local_228)(local_228,&DAT_10008950,&local_224);
        if (-1 < iVar2) {
          FUN_10004606(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1000c728 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1000c728 + 4;
        }
        pcVar4 = FUN_1000446c;
        pvVar5 = this;
        FUN_10004566(iVar2);
        local_8._0_1_ = 5;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224,pcVar4,pvVar5);
        }
        local_8._0_1_ = 3;
        if (local_22c != (int *)0x0) {
          (**(code **)(*local_22c + 8))(local_22c);
        }
      }
      (**(code **)(*local_230 + 8))(local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
    }
  }
  else {
    local_220 = 0;
  }
LAB_10004842:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10004304(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10004878:
  FUN_100066e7();
  return;
}



// Function: FUN_10004880 at 10004880

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004880(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CRegPropertyBagImpl>::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_1000c728 + 8))();
  FUN_1000305e((int)param_1);
  return;
}



// Function: FUN_100048d3 at 100048d3

undefined4 * __thiscall FUN_100048d3(void *this,byte param_1)

{
  FUN_10004880((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100048f2 at 100048f2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100048f2(void *this,undefined4 param_1)

{
  FUN_10003295((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CRegPropertyBagImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CRegPropertyBagImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CRegPropertyBagImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CRegPropertyBagImpl>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000493b at 1000493b

void FUN_1000493b(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_1000494e at 1000494e

void FUN_1000494e(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10004961 at 10004961

void FUN_10004961(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_10004979 at 10004979

undefined4 __fastcall FUN_10004979(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000497d at 1000497d

void FUN_1000497d(int param_1)

{
  FUN_1000494e(param_1 + -4);
  return;
}



// Function: FUN_10004987 at 10004987

void FUN_10004987(int param_1)

{
  FUN_1000494e(param_1 + -8);
  return;
}



// Function: FUN_10004991 at 10004991

void FUN_10004991(int param_1)

{
  FUN_1000494e(param_1 + -0xc);
  return;
}



// Function: FUN_1000499b at 1000499b

void FUN_1000499b(int param_1)

{
  FUN_1000493b(param_1 + -4);
  return;
}



// Function: FUN_100049a5 at 100049a5

void FUN_100049a5(int param_1)

{
  FUN_1000493b(param_1 + -8);
  return;
}



// Function: FUN_100049af at 100049af

void FUN_100049af(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004961(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100049b9 at 100049b9

void FUN_100049b9(int param_1)

{
  FUN_1000493b(param_1 + -0xc);
  return;
}



// Function: FUN_100049c3 at 100049c3

void FUN_100049c3(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004961(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_100049cd at 100049cd

void FUN_100049cd(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004961(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_100049d7 at 100049d7

void FUN_100049d7(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10002d50(0x1000c87c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_1000c71c != (code *)0x0)) {
    (*DAT_1000c71c)(DAT_1000c8a8);
  }
  return;
}



// Function: FUN_10004a05 at 10004a05

void FUN_10004a05(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1000c720 != (code *)0x0) && (iVar1 = (*DAT_1000c720)(), iVar1 < 0)) {
    return;
  }
  FUN_10002dd6(0x1000c87c,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 10004a2b

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x4a2b  2  DllGetClassObject */
  piVar1 = FUN_10003ead(&DAT_1000c7dc,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_10004a39 at 10004a39

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004a39(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000c700 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_100024a0(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10004b2f:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10004a84:
  if ((((sVar1 == 0) || (iVar3 = FUN_10001829(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10001786(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10001829(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10004b21;
  if (param_2 == 0) {
    iVar3 = FUN_10003816(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10004b21;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10003816(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10003816(this,local_2008,pHVar4,0,0);
LAB_10004b21:
      CoTaskMemFree(local_200c);
      goto LAB_10004b2f;
    }
  }
  FUN_10001807((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10004a84;
}



// Function: Catch@10004bce at 10004bce

undefined1 * Catch_10004bce(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10004bd8;
}



// Function: FUN_10004c20 at 10004c20

int __thiscall FUN_10004c20(void *this,int param_1,void *param_2)

{
  bool bVar1;
  void *pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pvVar2 = (void *)*piVar4, pvVar2 != (void *)0x0)) {
    do {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10001030(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10002798((GUID *)*piVar4,piVar3,iVar6);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 9;
      pvVar2 = (void *)*piVar4;
    } while (pvVar2 != (void *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = FUN_100049d7(param_1,param_2);
  return iVar5;
}



// Function: FUN_10004c8f at 10004c8f

int __thiscall FUN_10004c8f(void *this,int param_1,void *param_2)

{
  bool bVar1;
  void *pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pvVar2 = (void *)*piVar4, pvVar2 != (void *)0x0)) {
    do {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10001030(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10002798((GUID *)*piVar4,piVar3,iVar5);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = (*(code *)piVar4[1])(0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 9;
      pvVar2 = (void *)*piVar4;
    } while (pvVar2 != (void *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = FUN_10004a05(param_1,param_2);
  return iVar5;
}



// Function: FUN_10004cfe at 10004cfe

undefined4 * __thiscall FUN_10004cfe(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint extraout_EAX;
  uint uVar2;
  void *pvVar3;
  void *extraout_ECX;
  uint uVar4;
  
  uVar4 = param_1[4];
  uVar2 = param_2;
  pvVar3 = this;
  if (uVar4 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    pvVar3 = extraout_ECX;
  }
  uVar4 = uVar4 - uVar2;
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_10002717(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10002717(this,0,param_2);
  }
  else {
    bVar1 = FUN_10004119(pvVar3,uVar4,'\0');
    if (bVar1) {
      if (7 < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      memcpy(pvVar3,(void *)((int)param_1 + param_2 * 2),uVar4 * 2);
      *(uint *)((int)this + 0x10) = uVar4;
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      *(undefined2 *)(uVar4 * 2 + (int)pvVar3) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10004d9a at 10004d9a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004d9a(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x4c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10004183(puVar1);
    }
    iVar2 = FUN_10004dfe();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10004dee at 10004dee

undefined * Catch_10004dee(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004df8;
}



// Function: FUN_10004dfe at 10004dfe

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004dfe(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 4;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10001a08((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x14))(1);
  }
  return unaff_EBX;
}



// Function: FUN_10004e4a at 10004e4a

undefined4 __thiscall FUN_10004e4a(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10004633(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10004e8a at 10004e8a

undefined4 __thiscall
FUN_10004e8a(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10004633(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar2 = lstrlenW((LPCWSTR)*param_2);
      iVar5 = *(int *)((int)this + 0x18) + -1;
      if (-1 < iVar5) {
        iVar4 = iVar5 * 0xc;
        do {
          iVar3 = *(int *)((int)this + 0x14);
          if ((iVar2 == *(int *)(iVar4 + 4 + iVar3)) &&
             (iVar3 = memcmp(*(void **)(iVar3 + iVar4),(void *)*param_2,
                             *(int *)(iVar3 + 4 + iVar4) * 2), iVar3 == 0)) {
            *param_5 = *(undefined4 *)(iVar5 * 0xc + 8 + *(int *)((int)this + 0x14));
            return 0;
          }
          iVar4 = iVar4 + -0xc;
          iVar5 = iVar5 + -1;
        } while (-1 < iVar5);
      }
    }
    uVar1 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                      (*(int **)((int)this + 0xc),param_2,param_3,param_5);
  }
  return uVar1;
}



// Function: FUN_10004f2b at 10004f2b

void __thiscall
FUN_10004f2b(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10004633(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FID_conflict:assign at 10004f6e

/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned short
   const *,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

undefined4 * __thiscall FID_conflict_assign(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  
  uVar2 = FID_conflict__Inside(this,param_1);
  if ((char)uVar2 == '\0') {
    bVar1 = FUN_10004119(this,param_2,'\0');
    if (bVar1) {
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      memcpy(pvVar3,param_1,param_2 * 2);
      *(uint *)((int)this + 0x10) = param_2;
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      *(undefined2 *)(param_2 * 2 + (int)pvVar3) = 0;
    }
  }
  else {
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    this = FUN_10004cfe(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004fec at 10004fec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10004fec(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CRegPropertyBagImpl>::vftable;
  FUN_100048f2((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_1000c728 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000502f at 1000502f

void FUN_1000502f(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 10005043

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_10005070 at 10005070

long FUN_10005070(int *param_1,_GUID *param_2,void **param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_3 == (void **)0x0) {
    lVar2 = -0x7fffbffd;
  }
  else {
    *param_3 = (void *)0x0;
    iVar1 = ATL::InlineIsEqualUnknown(param_2);
    if (iVar1 == 0) {
      lVar2 = ATL::AtlInternalQueryInterface
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100088d4,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_100050bc at 100050bc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100050bc(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CRegPropertyBagImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000c728 + 8))();
  FUN_1000305e((int)(param_1 + 3));
  return;
}



// Function: FUN_10005102 at 10005102

undefined4 * __thiscall FUN_10005102(void *this,byte param_1)

{
  FUN_100050bc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: DllRegisterServer at 10005121

void DllRegisterServer(void)

{
                    /* 0x5121  3  DllRegisterServer */
  FUN_10004c20(&DAT_1000c7dc,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10005130

void DllUnregisterServer(void)

{
                    /* 0x5130  4  DllUnregisterServer */
  FUN_10004c8f(&DAT_1000c7dc,1,(void *)0x0);
  return;
}



// Function: FUN_1000513f at 1000513f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000513f(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HRSRC hResInfo;
  int local_42c;
  DWORD local_428;
  HGLOBAL local_424;
  HMODULE local_420;
  undefined1 *local_41c;
  undefined1 auStack_418 [1040];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x424;
  local_42c = 0;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_420 = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_420 == (HMODULE)0x0) {
    FUN_1000121b();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000121b();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10005219();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10001c86(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001b40(&local_42c);
  FUN_100066f6();
  return;
}



// Function: Catch@10005204 at 10005204

undefined * Catch_10005204(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005211;
}



// Function: FUN_10005219 at 10005219

void FUN_10005219(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000121b();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10004a39((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10001c86((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001b40((int *)(unaff_EBP + -0x428));
  FUN_100066f6();
  return;
}



// Function: FUN_100052a3 at 100052a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100052a3(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000513f(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001b40(local_14);
  return uVar1;
}



// Function: FUN_100052e4 at 100052e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100052e4(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000513f(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
  }
  return uVar1;
}



// Function: FUN_10005340 at 10005340

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005340(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000513f(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001b40(local_14);
  return uVar1;
}



// Function: FUN_10005380 at 10005380

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005380(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000513f(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001b40(local_14);
  }
  return uVar1;
}



// Function: FUN_100053db at 100053db

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100053db(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  HMODULE pHVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  HMODULE pHVar5;
  WCHAR *pWVar6;
  undefined **local_a60;
  undefined4 local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  LPCWSTR local_a4c;
  undefined4 *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa50;
  local_a4c = param_2;
  local_a48 = &local_a5c;
  local_a60 = ATL::CRegObject::vftable;
  local_a5c = 0;
  local_a58 = 0;
  local_a54 = 0;
  local_8 = 2;
  if (param_4 != (undefined4 *)0x0) {
    for (; (LPCWSTR)*param_4 != (LPCWSTR)0x0; param_4 = param_4 + 2) {
      FUN_10003426(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_1000c8a8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000c8a8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000121b();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001b40((int *)&local_a48);
        goto LAB_1000545d;
      }
      FUN_1000135f(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10001126(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001b40((int *)&local_a48);
          goto LAB_1000545d;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003426(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003426(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10005380(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_100052e4(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001b40((int *)&local_a48);
  }
LAB_1000545d:
  local_8 = 0xffffffff;
  FUN_100023f9(&local_a60);
  FUN_100066e7();
  return;
}



// Function: FUN_100055de at 100055de

undefined4 FUN_100055de(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10004e4a(&PTR_DAT_1000c538,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10005602 at 10005602

void FUN_10005602(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10004e8a(&PTR_DAT_1000c538,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10005622 at 10005622

void FUN_10005622(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10004f2b(&PTR_DAT_1000c538,param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,
               param_8,param_9);
  return;
}



// Function: FUN_10005652 at 10005652

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10005652(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  HMODULE pHVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  HMODULE pHVar5;
  WCHAR *pWVar6;
  undefined **local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  undefined4 *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa4c;
  local_a48 = &local_a58;
  local_a5c = ATL::CRegObject::vftable;
  local_a58 = 0;
  local_a54 = 0;
  local_a50 = 0;
  local_8 = 2;
  if (param_4 != (undefined4 *)0x0) {
    for (; (LPCWSTR)*param_4 != (LPCWSTR)0x0; param_4 = param_4 + 2) {
      FUN_10003426(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_1000c8a8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000c8a8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000121b();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001b40((int *)&local_a48);
        goto LAB_100056cb;
      }
      FUN_1000135f(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10001126(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001b40((int *)&local_a48);
          goto LAB_100056cb;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003426(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003426(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10005340(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100052a3(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001b40((int *)&local_a48);
  }
LAB_100056cb:
  local_8 = 0xffffffff;
  FUN_100023f9(&local_a5c);
  FUN_100066e7();
  return;
}



// Function: FUN_10005849 at 10005849

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10005849(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x58);
    if (this != (void *)0x0) {
      FUN_10004fec(this,param_1);
    }
    iVar1 = FUN_100058b7();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@100058a7 at 100058a7

undefined * Catch_100058a7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100058b1;
}



// Function: FUN_100058b7 at 100058b7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100058b7(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10001a08((int)(unaff_ESI + 7));
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
  return unaff_EDI;
}



// Function: FUN_100058f9 at 100058f9

void FUN_100058f9(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_100053db(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005902 at 10005902

void FUN_10005902(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10005652(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000590b at 1000590b

undefined2 * __thiscall FUN_1000590b(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_1000593d at 1000593d

void FUN_1000593d(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10004d9a(0,param_2,param_3);
    return;
  }
  FUN_10005849(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000595d at 1000595d

void FUN_1000595d(int param_1)

{
  FUN_10005652((int *)&DAT_1000c7dc,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005975 at 10005975

undefined4 FUN_10005975(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1000c554 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_100059a1 at 100059a1

undefined4 * __thiscall FUN_100059a1(void *this,int *param_1)

{
  int *piVar1;
  
  *(int **)this = param_1;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return (undefined4 *)this;
}



// Function: FUN_100059c7 at 100059c7

void __fastcall FUN_100059c7(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x100059da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_100059de at 100059de

void __fastcall FUN_100059de(int param_1)

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



// Function: FUN_10005a1b at 10005a1b

uint FUN_10005a1b(byte param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  if ((param_1 & 2) == 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  return uVar1;
}



// Function: FUN_10005a47 at 10005a47

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10005a47(void *this,int *param_1)

{
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *this_00;
  
  FUN_100059a1(this,param_1);
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this_00 = *(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                 (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this_00 != (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0)) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::flush(this_00);
  }
  *(bool *)((int)this + 4) = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0;
  return this;
}



// Function: FUN_10005a9f at 10005a9f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005a9f(int *param_1)

{
  bool bVar1;
  
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)*param_1);
  }
  FUN_100059c7(param_1);
  return;
}



// Function: FUN_10005ad7 at 10005ad7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall
FUN_10005ad7(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  *(undefined ***)param_1 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_100059de((int)param_1);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(param_1);
  return;
}



// Function: FUN_10005b09 at 10005b09

undefined4 __fastcall FUN_10005b09(int param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x20);
  puVar2 = (undefined2 *)*piVar1;
  if (puVar2 == (undefined2 *)0x0) {
    return 0xffff;
  }
  if (puVar2 < puVar2 + **(int **)(param_1 + 0x30)) {
    uVar4 = CONCAT22((short)((uint)piVar1 >> 0x10),*puVar2);
  }
  else if ((((*(byte *)(param_1 + 0x40) & 4) == 0) &&
           (puVar3 = (undefined2 *)**(undefined4 **)(param_1 + 0x24), puVar3 != (undefined2 *)0x0))
          && ((puVar2 < puVar3 || (puVar2 < *(undefined2 **)(param_1 + 0x3c))))) {
    if (*(undefined2 **)(param_1 + 0x3c) < puVar3) {
      *(undefined2 **)(param_1 + 0x3c) = puVar3;
    }
    **(int **)(param_1 + 0x30) = *(int *)(param_1 + 0x3c) - *piVar1 >> 1;
    uVar4 = CONCAT22((short)((uint)**(undefined4 **)(param_1 + 0x20) >> 0x10),
                     *(undefined2 *)**(undefined4 **)(param_1 + 0x20));
  }
  else {
    uVar4 = 0xffff;
  }
  return uVar4;
}



// Function: FUN_10005b6d at 10005b6d

short __thiscall FUN_10005b6d(void *this,short param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if (((uVar1 == 0) || (uVar1 <= **(uint **)((int)this + 0x10))) ||
     ((param_1 != -1 &&
      ((param_1 != *(short *)(uVar1 - 2) && ((*(byte *)((int)this + 0x40) & 2) != 0)))))) {
    param_1 = -1;
  }
  else {
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,-1);
    if (param_1 == -1) {
      param_1 = 0;
    }
    else {
      *(short *)**(undefined4 **)((int)this + 0x20) = param_1;
    }
  }
  return param_1;
}



// Function: FUN_10005bca at 10005bca

void __thiscall
FUN_10005bca(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  uVar2 = **(uint **)((int)this + 0x24);
  if ((uVar2 != 0) && (*(uint *)((int)this + 0x3c) < uVar2)) {
    *(uint *)((int)this + 0x3c) = uVar2;
  }
  if (((param_5 & 1) == 0) || (iVar3 = **(int **)((int)this + 0x20), iVar3 == 0)) {
    if (((param_5 & 2) == 0) || (uVar2 = **(uint **)((int)this + 0x24), uVar2 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_10005d56;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_10005ce6:
        bVar5 = CARRY4(param_2,iVar3 >> 1);
        param_2 = param_2 + (iVar3 >> 1);
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar5;
      }
      else {
        if (param_4 == 1) {
          iVar3 = uVar2 - **(int **)((int)this + 0x10);
          goto LAB_10005ce6;
        }
        if (param_4 != 0) {
          param_2 = *(uint *)_BADOFF_exref;
          param_3 = *(uint *)(_BADOFF_exref + 4);
        }
      }
      if (-1 < (int)param_3) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar1 = iVar3 >> 0x1f;
        if (((int)param_3 <= iVar1) && (((int)param_3 < iVar1 || (param_2 <= (uint)(iVar3 >> 1)))))
        {
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)(**(int **)((int)this + 0x10) - uVar2) >> 1) + param_2);
          goto LAB_10005d56;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c);
LAB_10005c15:
      iVar1 = iVar1 - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar5 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar5;
    }
    else if (param_4 == 1) {
      iVar1 = iVar3;
      if ((param_5 & 2) == 0) goto LAB_10005c15;
LAB_10005c2f:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10005c2f;
    if (-1 < (int)param_3) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar4 = iVar1 >> 0x1f;
      if (((int)param_3 <= iVar4) && (((int)param_3 < iVar4 || (param_2 <= (uint)(iVar1 >> 1))))) {
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   (**(int **)((int)this + 0x10) - iVar3 >> 1) + param_2);
        if ((param_5 & 2) != 0) {
          iVar3 = **(int **)((int)this + 0x24);
          if (iVar3 != 0) {
            iVar1 = **(int **)((int)this + 0x34);
            iVar4 = **(int **)((int)this + 0x20);
            **(int **)((int)this + 0x24) = iVar4;
            **(int **)((int)this + 0x34) = (iVar3 + iVar1 * 2) - iVar4 >> 1;
          }
        }
        goto LAB_10005d56;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_10005d56:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10005d70 at 10005d70

void __thiscall FUN_10005d70(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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
      if ((((in_stack_00000020 & 2) != 0) && (uVar1 = **(uint **)((int)this + 0x24), uVar1 != 0)) &&
         (-1 < (int)uVar6)) {
        iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar5 = iVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)(**(int **)((int)this + 0x10) - uVar1) >> 1) + uVar8);
          uVar7 = uVar6;
          uVar9 = uVar8;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar5 = iVar4 >> 0x1f;
      if ((((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) &&
         (std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,(**(int **)((int)this + 0x10) - **(int **)((int)this + 0x20) >> 1) + uVar8
                    ), uVar7 = uVar6, uVar9 = uVar8, (in_stack_00000020 & 2) != 0)) {
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
  *param_1 = uVar9;
  param_1[1] = uVar7;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10005e88 at 10005e88

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10005e88(void *this,byte param_1)

{
  FUN_10005ad7((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_10005ea7 at 10005ea7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10005ea7(int *param_1,wchar_t *param_2)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  size_t sVar4;
  bool bVar5;
  __int64 _Var6;
  undefined2 in_stack_ffffffc8;
  undefined2 in_stack_ffffffca;
  undefined1 local_28 [4];
  char local_24;
  int local_20;
  int local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x10005eb3;
  local_18 = 0;
  sVar4 = wcslen(param_2);
  uVar1 = *(uint *)(*(int *)(*param_1 + 4) + 0x20 + (int)param_1);
  local_1c = *(int *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1);
  if ((local_1c < 0) ||
     ((((local_1c < 1 && (uVar1 == 0)) || (local_1c < 0)) || ((local_1c < 1 && (uVar1 <= sVar4))))))
  {
    local_20 = 0;
    local_1c = 0;
  }
  else {
    local_20 = uVar1 - sVar4;
    local_1c = local_1c - (uint)(uVar1 < sVar4);
  }
  FUN_10005a47(local_28,param_1);
  local_8 = 0;
  if (local_24 == '\0') {
    local_18 = 4;
    FUN_1000600c();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_10005f64;
      uVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(ushort *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar3 == 0xffff) break;
      bVar5 = local_20 != 0;
      local_20 = local_20 + -1;
      local_1c = local_1c + -1 + (uint)bVar5;
    }
    local_18 = local_18 | 4;
LAB_10005f64:
    if (local_18 != 0) goto LAB_10005f8d;
  }
  _Var6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                    (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                      (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),(ushort *)param_2,
                     (ulonglong)CONCAT22(in_stack_ffffffca,in_stack_ffffffc8) << 0x20);
  if (((size_t)_Var6 == sVar4) && ((int)((ulonglong)_Var6 >> 0x20) == 0)) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_10005f8d;
      uVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(ushort *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar3 == 0xffff) break;
      bVar5 = local_20 != 0;
      local_20 = local_20 + -1;
      local_1c = local_1c + -1 + (uint)bVar5;
    }
    local_18 = local_18 | 4;
  }
  else {
    local_18 = 4;
  }
LAB_10005f8d:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_1000600c();
  return;
}



// Function: Catch@10005feb at 10005feb

undefined * Catch_10005feb(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10006009;
}



// Function: FUN_1000600c at 1000600c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000600c(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10005a9f((int *)(unaff_EBP + -0x24));
  return;
}



// Function: FUN_10006032 at 10006032

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006032(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_10005ad7((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (param_1 + -0x4c));
  *(code **)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) = _vftable__exref;
  return;
}



// Function: FUN_10006077 at 10006077

ushort __thiscall FUN_10006077(void *this,ushort param_1)

{
  char *pcVar1;
  void *pvVar2;
  byte bVar3;
  int iVar4;
  void *_Src;
  ushort *puVar5;
  void *_Dst;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  
  if ((*(byte *)((int)this + 0x40) & 8) != 0) {
    uVar8 = **(uint **)((int)this + 0x24);
    if ((uVar8 != 0) && (uVar7 = *(uint *)((int)this + 0x3c), uVar8 < uVar7)) {
      iVar4 = **(int **)((int)this + 0x34);
      **(uint **)((int)this + 0x24) = uVar7;
      **(int **)((int)this + 0x34) = (int)((uVar8 + iVar4 * 2) - uVar7) >> 1;
    }
  }
  if (param_1 == 0xffff) {
    return 0;
  }
  uVar8 = **(uint **)((int)this + 0x24);
  if ((uVar8 != 0) && (uVar8 < uVar8 + **(int **)((int)this + 0x34) * 2)) {
    puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *puVar5 = param_1;
    return param_1;
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return 0xffff;
  }
  if (uVar8 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (int)((**(int **)((int)this + 0x34) * 2 - **(int **)((int)this + 0x10)) + uVar8) >> 1;
  }
  uVar7 = uVar8 >> 1;
  if (uVar7 < 0x20) {
    uVar7 = 0x20;
  }
  else if (uVar7 == 0) {
    return 0xffff;
  }
  do {
    if (uVar8 <= 0x7fffffff - uVar7) break;
    uVar7 = uVar7 >> 1;
  } while (uVar7 != 0);
  if (uVar7 == 0) {
    return 0xffff;
  }
  pcVar1 = (char *)(uVar7 + uVar8);
  _Dst = FUN_10001b87(pcVar1);
  _Src = (void *)**(undefined4 **)((int)this + 0x10);
  if ((uVar8 == 0) || (memcpy(_Dst,_Src,uVar8 * 2), uVar8 == 0)) {
    *(void **)((int)this + 0x3c) = _Dst;
    **(undefined4 **)((int)this + 0x14) = _Dst;
    **(undefined4 **)((int)this + 0x24) = _Dst;
    **(int **)((int)this + 0x34) = (int)pcVar1 * 2 >> 1;
    bVar3 = *(byte *)((int)this + 0x40);
    **(undefined4 **)((int)this + 0x10) = _Dst;
    puVar6 = *(undefined4 **)((int)this + 0x20);
    if ((bVar3 & 4) == 0) {
      *puVar6 = _Dst;
      **(undefined4 **)((int)this + 0x30) = 1;
      goto LAB_1000621e;
    }
  }
  else {
    *(void **)((int)this + 0x3c) =
         (void *)((int)_Dst + (*(int *)((int)this + 0x3c) - (int)_Src >> 1) * 2);
    pvVar2 = (void *)((int)_Dst + (**(int **)((int)this + 0x24) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x14) =
         (int)((int)_Dst + (**(int **)((int)this + 0x14) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x24) = (int)pvVar2;
    **(int **)((int)this + 0x34) = ((int)pcVar1 * 2 - (int)pvVar2) + (int)_Dst >> 1;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      iVar4 = **(int **)((int)this + 0x24);
      pvVar2 = (void *)((int)_Dst + (**(int **)((int)this + 0x20) - (int)_Src >> 1) * 2);
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(int **)((int)this + 0x20) = (int)pvVar2;
      **(int **)((int)this + 0x30) = (iVar4 - (int)pvVar2) + 2 >> 1;
      goto LAB_1000621e;
    }
    **(undefined4 **)((int)this + 0x10) = _Dst;
    puVar6 = *(undefined4 **)((int)this + 0x20);
  }
  *puVar6 = 0;
  **(int **)((int)this + 0x30) = (int)_Dst >> 1;
LAB_1000621e:
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  *puVar5 = param_1;
  return param_1;
}



// Function: FUN_10006248 at 10006248

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10006248(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  uVar1 = FUN_10005a1b(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_10006288 at 10006288

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006288(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x50);
  FUN_10006032((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}



// Function: FUN_100062c1 at 100062c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_100062c1(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_10008aa8;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
  }
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             ((int)this + 4),false);
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_10006248((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               ((int)this + 4),param_1 | 2);
  return (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_1000633f at 1000633f

void * __thiscall FUN_1000633f(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x50);
  FUN_10006288((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10006361 at 10006361

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10006361(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  wchar_t *in_stack_ffffff48;
  wchar_t *in_stack_ffffff54;
  int local_a8 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_8 = 0x10006370;
  FUN_100062c1(local_a8,2,1);
  local_8 = 0;
  piVar1 = (int *)FUN_10005ea7(local_a8,L"* AddIn Property Bag: Read ");
  piVar1 = (int *)FUN_10005ea7(piVar1,in_stack_ffffff48);
  FUN_10005ea7(piVar1,in_stack_ffffff54);
  local_8 = 0xffffffff;
  local_a8[1] = 0x100063cc;
  FUN_10006288((int)local_a8);
  return (uint)(param_3 != 0) * 2 + -0x7fffbffd;
}



// Function: FUN_100063d6 at 100063d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100063d6(void)

{
  int *piVar1;
  wchar_t *in_stack_ffffff48;
  wchar_t *in_stack_ffffff54;
  int local_a8 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_8 = 0x100063e5;
  FUN_100062c1(local_a8,2,1);
  local_8 = 0;
  piVar1 = (int *)FUN_10005ea7(local_a8,L"* AddIn Property Bag: Write ");
  piVar1 = (int *)FUN_10005ea7(piVar1,in_stack_ffffff48);
  FUN_10005ea7(piVar1,in_stack_ffffff54);
  local_8 = 0xffffffff;
  local_a8[1] = 0x10006432;
  FUN_10006288((int)local_a8);
  return 0;
}



// Function: FUN_1000643c at 1000643c

undefined4 FUN_1000643c(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FID_conflict_assign((void *)(param_1 + 0x2c),(undefined4 *)param_2,sVar1);
  return 0;
}



// Function: FUN_1000645e at 1000645e

void __fastcall FUN_1000645e(int *param_1)

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



// Function: FUN_100064a2 at 100064a2

int __fastcall FUN_100064a2(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100064bb at 100064bb

undefined4 * __fastcall FUN_100064bb(undefined4 *param_1)

{
  long lVar1;
  
  FUN_100064a2((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1000a788;
  param_1[3] = &DAT_1000a788;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1000c718 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_100064fc at 100064fc

void __fastcall FUN_100064fc(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000651b at 1000651b

int __fastcall FUN_1000651b(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10006540 at 10006540

void __fastcall FUN_10006540(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_100064fc((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10006558 at 10006558

undefined4 * __fastcall FUN_10006558(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000651b((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10008bd8;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1000c718 = 1;
  }
  return param_1;
}



// Function: FUN_10006598 at 10006598

void FUN_10006598(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 100065ec

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1000c700) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 100065fb

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000c700 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000662e

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000c700 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10006664

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3_GS
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3_GS(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000c700 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000669a

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3_catch_GS
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3_catch_GS(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000c700 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100066d3

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



// Function: FUN_100066e7 at 100066e7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100066e7(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_100066f6 at 100066f6

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100066f6(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10006705

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



// Function: __alloca_probe at 10006770

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



// Function: __ArrayUnwind at 100067ae

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



// Function: `eh_vector_destructor_iterator' at 1000680c

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
  FUN_10006857();
  return;
}



// Function: FUN_10006857 at 10006857

void FUN_10006857(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 10006876

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
  FUN_100068c3();
  return;
}



// Function: FUN_100068c3 at 100068c3

void FUN_100068c3(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 100068db

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
  
  local_8 = &DAT_1000a720;
  uStack_c = 0x100068e7;
  local_20[0] = DecodePointer(DAT_1000cc1c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1000cc1c);
    local_24 = DecodePointer(DAT_1000cc18);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1000cc1c = EncodePointer(local_20[0]);
    DAT_1000cc18 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10006973();
  }
  return p_Var1;
}



// Function: FUN_10006973 at 10006973

void FUN_10006973(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000697c

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 100069e1

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
    if (DAT_1000c8dc < 1) {
      return 0;
    }
    DAT_1000c8dc = DAT_1000c8dc + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000cc10,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000cc0c == 2) {
      param_2 = (int *)DecodePointer(DAT_1000cc1c);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1000cc18);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1000cc1c);
            piVar8 = (int *)DecodePointer(DAT_1000cc18);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1000cc18 = (PVOID)encoded_null();
        DAT_1000cc1c = DAT_1000cc18;
      }
      DAT_1000cc0c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1000cc10,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000cc10,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000cc0c == 0) {
      DAT_1000cc0c = 1;
      iVar5 = initterm_e(&DAT_10008248,&DAT_10008250);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10008214,&DAT_10008244);
      DAT_1000cc0c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1000cc10,0);
    }
    if ((DAT_1000cc14 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1000cc14), BVar2 != 0)) {
      (*DAT_1000cc14)(param_1,2,param_3);
    }
    DAT_1000c8dc = DAT_1000c8dc + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10006beb

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10006c8b) */
/* WARNING: Removing unreachable block (ram,0x10006c38) */
/* WARNING: Removing unreachable block (ram,0x10006cb8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1000c710 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1000c8dc == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10002356(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10002356(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10006cf6();
  return local_20;
}



// Function: FUN_10006cf6 at 10006cf6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006cf6(void)

{
  _DAT_1000c710 = 0xffffffff;
  return;
}



// Function: entry at 10006d01

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10006d24

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
  
  _DAT_1000c9f8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1000c9fc = &stack0x00000004;
  _DAT_1000c938 = 0x10001;
  _DAT_1000c8e0 = 0xc0000409;
  _DAT_1000c8e4 = 1;
  local_32c = DAT_1000c700;
  local_328 = DAT_1000c704;
  _DAT_1000c8ec = unaff_retaddr;
  _DAT_1000c9c4 = in_GS;
  _DAT_1000c9c8 = in_FS;
  _DAT_1000c9cc = in_ES;
  _DAT_1000c9d0 = in_DS;
  _DAT_1000c9d4 = unaff_EDI;
  _DAT_1000c9d8 = unaff_ESI;
  _DAT_1000c9dc = unaff_EBX;
  _DAT_1000c9e0 = in_EDX;
  _DAT_1000c9e4 = in_ECX;
  _DAT_1000c9e8 = in_EAX;
  _DAT_1000c9ec = unaff_EBP;
  DAT_1000c9f0 = unaff_retaddr;
  _DAT_1000c9f4 = in_CS;
  _DAT_1000ca00 = in_SS;
  DAT_1000c930 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10008bf4);
  if (DAT_1000c930 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10006e30

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000c700 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10006e75

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



// Function: FUN_10006e89 at 10006e89

void __cdecl
FUN_10006e89(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1000c700,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 10006f20

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



// Function: __FindPESection at 10006f60

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



// Function: __IsNonwritableInCurrentImage at 10006fb0

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
  
  pcStack_10 = FUN_10006e89;
  local_14 = ExceptionList;
  local_c = DAT_1000c700 ^ 0x1000a768;
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



// Function: ___security_init_cookie at 10007084

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
  if ((DAT_1000c700 == 0xbb40e64e) || ((DAT_1000c700 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1000c700 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1000c700 == 0xbb40e64e) {
      DAT_1000c700 = 0xbb40e64f;
    }
    else if ((DAT_1000c700 & 0xffff0000) == 0) {
      DAT_1000c700 = DAT_1000c700 | (DAT_1000c700 | 0x4711) << 0x10;
    }
    DAT_1000c704 = ~DAT_1000c700;
  }
  else {
    DAT_1000c704 = ~DAT_1000c700;
  }
  return;
}



// Function: Unwind@10007138 at 10007138

void Unwind_10007138(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000713b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000715c at 1000715c

void Unwind_1000715c(void)

{
  int unaff_EBP;
  
  FUN_10001209(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000717f at 1000717f

void Unwind_1000717f(void)

{
  DAT_1000c768 = DAT_1000c768 & 0xfffffffe;
  return;
}



// Function: Unwind@100071a8 at 100071a8

void Unwind_100071a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100071ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100071cc at 100071cc

void Unwind_100071cc(void)

{
  int unaff_EBP;
  
  FUN_10001d55(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100071ef at 100071ef

void Unwind_100071ef(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007222 at 10007222

void Unwind_10007222(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10007255 at 10007255

void Unwind_10007255(void)

{
  int unaff_EBP;
  
  FUN_10001c25((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000727b at 1000727b

void Unwind_1000727b(void)

{
  FUN_10001cda();
  return;
}



// Function: Unwind@10007292 at 10007292

void Unwind_10007292(void)

{
  FUN_10001cda();
  return;
}



// Function: Unwind@100072c5 at 100072c5

void Unwind_100072c5(void)

{
  int unaff_EBP;
  
  FUN_10001d55(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100072cd at 100072cd

void Unwind_100072cd(void)

{
  int unaff_EBP;
  
  FUN_10001d5a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100072f0 at 100072f0

void Unwind_100072f0(void)

{
  int unaff_EBP;
  
  FUN_10001d5a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100072f8 at 100072f8

void Unwind_100072f8(void)

{
  int unaff_EBP;
  
  FUN_10001d55(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000731b at 1000731b

void Unwind_1000731b(void)

{
  int unaff_EBP;
  
  FUN_100021ef(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000733e at 1000733e

void Unwind_1000733e(void)

{
  int unaff_EBP;
  
  FUN_100023cf((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007364 at 10007364

void Unwind_10007364(void)

{
  int unaff_EBP;
  
  FUN_10001610(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10007391 at 10007391

void Unwind_10007391(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000739c at 1000739c

void Unwind_1000739c(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100073a7 at 100073a7

void Unwind_100073a7(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100073b2 at 100073b2

void Unwind_100073b2(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100073bd at 100073bd

void Unwind_100073bd(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100073c8 at 100073c8

void Unwind_100073c8(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@100073d3 at 100073d3

void Unwind_100073d3(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@100073de at 100073de

void Unwind_100073de(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@100073e9 at 100073e9

void Unwind_100073e9(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100073f4 at 100073f4

void Unwind_100073f4(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007427 at 10007427

void Unwind_10007427(void)

{
  int unaff_EBP;
  
  FUN_10001246((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000742f at 1000742f

void Unwind_1000742f(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007437 at 10007437

void Unwind_10007437(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000743f at 1000743f

void Unwind_1000743f(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007447 at 10007447

void Unwind_10007447(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000746a at 1000746a

void Unwind_1000746a(void)

{
  int unaff_EBP;
  
  FUN_10001246((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007475 at 10007475

void Unwind_10007475(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007480 at 10007480

void Unwind_10007480(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000748b at 1000748b

void Unwind_1000748b(void)

{
  int unaff_EBP;
  
  FUN_10001246((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007496 at 10007496

void Unwind_10007496(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100074a1 at 100074a1

void Unwind_100074a1(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100074d4 at 100074d4

void Unwind_100074d4(void)

{
  int unaff_EBP;
  
  FUN_10002286((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100074f7 at 100074f7

void Unwind_100074f7(void)

{
  int unaff_EBP;
  
  FUN_10001c25((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10007502 at 10007502

void Unwind_10007502(void)

{
  int unaff_EBP;
  
  FUN_10002211(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10007528 at 10007528

void Unwind_10007528(void)

{
  int unaff_EBP;
  
  FUN_10002211(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10007533 at 10007533

void Unwind_10007533(void)

{
  int unaff_EBP;
  
  FUN_10001c25((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007559 at 10007559

void Unwind_10007559(void)

{
  int unaff_EBP;
  
  FUN_10002211(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10007564 at 10007564

void Unwind_10007564(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000756f at 1000756f

void Unwind_1000756f(void)

{
  int unaff_EBP;
  
  FUN_10001c25((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007595 at 10007595

void Unwind_10007595(void)

{
  int unaff_EBP;
  
  FUN_1000305e(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100075d3 at 100075d3

void Unwind_100075d3(void)

{
  int unaff_EBP;
  
  FUN_10001c25((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100075de at 100075de

void Unwind_100075de(void)

{
  int unaff_EBP;
  
  FUN_10002211(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@100075e9 at 100075e9

void Unwind_100075e9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000760f at 1000760f

void Unwind_1000760f(void)

{
  int unaff_EBP;
  
  FUN_100021f4((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007617 at 10007617

void Unwind_10007617(void)

{
  int unaff_EBP;
  
  FUN_100021f4((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000763a at 1000763a

void Unwind_1000763a(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000765d at 1000765d

void Unwind_1000765d(void)

{
  int unaff_EBP;
  
  FUN_10002204((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10007668 at 10007668

void Unwind_10007668(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10007673 at 10007673

void Unwind_10007673(void)

{
  int unaff_EBP;
  
  FUN_10002204((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@100076a6 at 100076a6

void Unwind_100076a6(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@100076b1 at 100076b1

void Unwind_100076b1(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@100076bc at 100076bc

void Unwind_100076bc(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@100076c7 at 100076c7

void Unwind_100076c7(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@100076d2 at 100076d2

void Unwind_100076d2(void)

{
  int unaff_EBP;
  
  FUN_10001d78((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10007705 at 10007705

void Unwind_10007705(void)

{
  int unaff_EBP;
  
  FUN_10002286((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10007728 at 10007728

void Unwind_10007728(void)

{
  int unaff_EBP;
  
  FUN_1000300e(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000774b at 1000774b

void Unwind_1000774b(void)

{
  int unaff_EBP;
  
  FUN_10001246(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000776e at 1000776e

void Unwind_1000776e(void)

{
  int unaff_EBP;
  
  FUN_10001c18(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007791 at 10007791

void Unwind_10007791(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000779b at 1000779b

void Unwind_1000779b(void)

{
  int unaff_EBP;
  
  FUN_10001246((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100077be at 100077be

void Unwind_100077be(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100077c6 at 100077c6

void Unwind_100077c6(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100077ce at 100077ce

void Unwind_100077ce(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100077d6 at 100077d6

void Unwind_100077d6(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100077de at 100077de

void Unwind_100077de(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100077e6 at 100077e6

void Unwind_100077e6(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007809 at 10007809

void Unwind_10007809(void)

{
  int unaff_EBP;
  
  FUN_10002286((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000782c at 1000782c

void Unwind_1000782c(void)

{
  int unaff_EBP;
  
  FUN_10002286((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@10007837 at 10007837

void Unwind_10007837(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007842 at 10007842

void Unwind_10007842(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000784d at 1000784d

void Unwind_1000784d(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007858 at 10007858

void Unwind_10007858(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007863 at 10007863

void Unwind_10007863(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000786e at 1000786e

void Unwind_1000786e(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007879 at 10007879

void Unwind_10007879(void)

{
  int unaff_EBP;
  
  FUN_100042df((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007884 at 10007884

void Unwind_10007884(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000788f at 1000788f

void Unwind_1000788f(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000789a at 1000789a

void Unwind_1000789a(void)

{
  int unaff_EBP;
  
  FUN_10001c18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100078cd at 100078cd

void Unwind_100078cd(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000790d at 1000790d

void Unwind_1000790d(void)

{
  int unaff_EBP;
  
  FUN_1000309b(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10007933 at 10007933

void Unwind_10007933(void)

{
  int unaff_EBP;
  
  FUN_1000309b(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000793e at 1000793e

void Unwind_1000793e(void)

{
  int unaff_EBP;
  
  FUN_1000305e(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007961 at 10007961

void Unwind_10007961(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000796c at 1000796c

void Unwind_1000796c(void)

{
  int unaff_EBP;
  
  FUN_10002204((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000799f at 1000799f

void Unwind_1000799f(void)

{
  int unaff_EBP;
  
  FUN_100021ef(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100079aa at 100079aa

void Unwind_100079aa(void)

{
  int unaff_EBP;
  
  FUN_100023cf((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@100079b5 at 100079b5

void Unwind_100079b5(void)

{
  int unaff_EBP;
  
  FUN_100023f9((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@100079c0 at 100079c0

void Unwind_100079c0(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100079f3 at 100079f3

void Unwind_100079f3(void)

{
  int unaff_EBP;
  
  FUN_100021ef(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100079fe at 100079fe

void Unwind_100079fe(void)

{
  int unaff_EBP;
  
  FUN_100023cf((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10007a09 at 10007a09

void Unwind_10007a09(void)

{
  int unaff_EBP;
  
  FUN_100023f9((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10007a14 at 10007a14

void Unwind_10007a14(void)

{
  int unaff_EBP;
  
  FUN_10001b40((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10007a47 at 10007a47

void Unwind_10007a47(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007a6c at 10007a6c

void Unwind_10007a6c(void)

{
  FUN_10001d5a(0x1000c7dc);
  return;
}



// Function: Unwind@10007a76 at 10007a76

void Unwind_10007a76(void)

{
  FUN_10001d55(0x1000c7dc);
  return;
}



// Function: Unwind@10007a9b at 10007a9b

void Unwind_10007a9b(void)

{
  int unaff_EBP;
  
  FUN_100059c7(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007abe at 10007abe

void Unwind_10007abe(void)

{
  int unaff_EBP;
  
  FUN_10005a9f((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10007ae1 at 10007ae1

void Unwind_10007ae1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10007ae7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10007aed at 10007aed

void Unwind_10007aed(void)

{
  int unaff_EBP;
  
  FUN_10005ad7((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10007b13 at 10007b13

void Unwind_10007b13(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10007b16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007b37 at 10007b37

void Unwind_10007b37(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10007b3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007b5b at 10007b5b

void Unwind_10007b5b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10007b5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10007b64 at 10007b64

void Unwind_10007b64(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10007b7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@10007b81 at 10007b81

void Unwind_10007b81(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10007b87. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@10007b8d at 10007b8d

void Unwind_10007b8d(void)

{
  int unaff_EBP;
  
  FUN_10005ad7((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10007bb3 at 10007bb3

void Unwind_10007bb3(void)

{
  int unaff_EBP;
  
  FUN_10006288(unaff_EBP + -0xa4);
  return;
}



// Function: FUN_10007cf6 at 10007cf6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10007cf6(void)

{
  _DAT_1000c7dc = ATL::CComModule::vftable;
  FUN_10001d1c(0x1000c7dc);
  return;
}



// Function: FUN_10007d20 at 10007d20

void FUN_10007d20(void)

{
  FID_conflict__Tidy(&DAT_1000c76c,'\x01',0);
  return;
}



// Function: FUN_10007d2f at 10007d2f

void FUN_10007d2f(void)

{
  FID_conflict__Tidy(&DAT_1000c788,'\x01',0);
  return;
}



// Function: FUN_10007d3e at 10007d3e

void FUN_10007d3e(void)

{
  FID_conflict__Tidy(&DAT_1000c7a4,'\x01',0);
  return;
}



// Function: FUN_10007d4d at 10007d4d

void FUN_10007d4d(void)

{
  FID_conflict__Tidy(&DAT_1000c7c0,'\x01',0);
  return;
}



// Function: FUN_10007d5c at 10007d5c

void FUN_10007d5c(void)

{
  FID_conflict__Tidy(&DAT_1000c80c,'\x01',0);
  return;
}



// Function: FUN_10007d6b at 10007d6b

void FUN_10007d6b(void)

{
  FID_conflict__Tidy(&DAT_1000c828,'\x01',0);
  return;
}



// Function: FUN_10007d7a at 10007d7a

void FUN_10007d7a(void)

{
  FID_conflict__Tidy(&DAT_1000c844,'\x01',0);
  return;
}



// Function: FUN_10007d89 at 10007d89

void FUN_10007d89(void)

{
  FID_conflict__Tidy(&DAT_1000c860,'\x01',0);
  return;
}



// Function: FUN_10007d98 at 10007d98

void FUN_10007d98(void)

{
  FUN_1000645e((int *)&DAT_1000c87c);
  return;
}



// Function: FUN_10007da2 at 10007da2

void FUN_10007da2(void)

{
  FUN_10006540(0x1000c8a4);
  return;
}



