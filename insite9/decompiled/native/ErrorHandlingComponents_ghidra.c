/*
 * Decompiled from: ErrorHandlingComponents.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001009 at 10001009

undefined4 FUN_10001009(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

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



// Function: FUN_1000104e at 1000104e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000104e(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_1000102d);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_100010ab at 100010ab

void FUN_100010ab(LPUNKNOWN param_1)

{
  HRESULT HVar1;
  
  HVar1 = CoCreateInstance((IID *)&DAT_10009428,param_1,0x17,(IID *)&DAT_10009340,&param_1[2].lpVtbl
                          );
  if (-1 < HVar1) {
    HVar1 = CoCreateInstance((IID *)&DAT_10009418,param_1,0x17,(IID *)&DAT_10009340,
                             &param_1[3].lpVtbl);
    if (-1 < HVar1) {
      (**(code **)(param_1[3].lpVtbl)->QueryInterface)(param_1[3].lpVtbl,&DAT_10009340,param_1 + 4);
    }
  }
  return;
}



// Function: _InlineIsEqualGUID at 100010f9

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



// Function: FUN_10001129 at 10001129

bool __cdecl FUN_10001129(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10001143

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



// Function: AtlCoTaskMemCAlloc at 10001165

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



// Function: FUN_10001192 at 10001192

LPVOID __cdecl FUN_10001192(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_100011c2 at 100011c2

bool __cdecl FUN_100011c2(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100011ef at 100011ef

void FUN_100011ef(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1000b0b0);
}



// Function: AtlCrtErrorCheck at 10001207

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
    if (param_1 == 0x16) goto LAB_1000122f;
    if (param_1 == 0x22) goto LAB_1000122f;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_100011ef(uVar1);
LAB_1000122f:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_1000123f at 1000123f

void __cdecl FUN_1000123f(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000125f at 1000125f

void __cdecl FUN_1000125f(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 1000127c

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



// Function: FUN_100012a5 at 100012a5

void __fastcall FUN_100012a5(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100012b7 at 100012b7

DWORD FUN_100012b7(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_100012cc at 100012cc

uint __cdecl FUN_100012cc(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100012e5 at 100012e5

void __fastcall FUN_100012e5(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 100012fa

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
                    /* WARNING: Could not recover jumptable at 0x10001343. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 10001351

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
                    /* WARNING: Could not recover jumptable at 0x100013a6. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 100013b4

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
                    /* WARNING: Could not recover jumptable at 0x100013f7. Too many branches */
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



// Function: FUN_10001406 at 10001406

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10001406(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10001434 at 10001434

undefined4 __fastcall FUN_10001434(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001438 at 10001438

void __cdecl FUN_10001438(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10001486 at 10001486

int __fastcall FUN_10001486(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 1000149d

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_1000dcd4 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1000dcd0 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_1000dcd4 = '\x01';
    }
    if (DAT_1000dcd0 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1000dcd0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 1000150d

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



// Function: Create at 10001528

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



// Function: Open at 10001590

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



// Function: SetStringValue at 100015df

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



// Function: FUN_10001616 at 10001616

LSTATUS __thiscall FUN_10001616(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10001659 at 10001659

undefined4 __fastcall FUN_10001659(undefined4 *param_1)

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



// Function: FUN_10001679 at 10001679

undefined4 * __thiscall FUN_10001679(void *this,ulong param_1)

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



// Function: FUN_100016af at 100016af

void __fastcall FUN_100016af(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100016b9 at 100016b9

undefined4 __thiscall FUN_100016b9(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10001192(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_1000123f((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10001747 at 10001747

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001747(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10001753;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1000dcf8 & 1) == 0) {
    DAT_1000dcf8 = DAT_1000dcf8 | 1;
    DAT_1000dcdc = 8;
    _DAT_1000dce4 = 0x4008;
    _DAT_1000dcec = 0x13;
    DAT_1000dcd8 = &DAT_100092ec;
    DAT_1000dce0 = &DAT_100092e8;
    _DAT_1000dce8 = &DAT_100092e4;
    _DAT_1000dcf0 = &DAT_100092e0;
    _DAT_1000dcf4 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1000dcd8)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x100017ca;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1000dcdc)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_100017d6;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_100017d6:
  *(undefined4 *)(puVar4 + -4) = 0x100017db;
  return uVar2;
}



// Function: FUN_100017ef at 100017ef

int __cdecl FUN_100017ef(ushort param_1)

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



// Function: FUN_10001825 at 10001825

undefined4 __cdecl FUN_10001825(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_100094f0)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_100094f4)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10001853 at 10001853

LPCWSTR __cdecl FUN_10001853(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10001880 at 10001880

undefined4 FUN_10001880(ushort param_1)

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



// Function: FUN_100018a6 at 100018a6

void __fastcall FUN_100018a6(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10001880(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_100018c8 at 100018c8

undefined4 __thiscall FUN_100018c8(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_100018a6((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10001659((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10001880(*pWVar2);
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



// Function: FUN_100019de at 100019de

undefined4 FUN_100019de(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10009310;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10009340);
  return 1;
}



// Function: FUN_10001a0d at 10001a0d

bool FUN_10001a0d(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10001a42 at 10001a42

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10001a42(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000dc90 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_100018c8(this,param_1), -1 < iVar1)) {
    FUN_100018a6((undefined4 *)this);
    iVar1 = FUN_100018c8(this,local_2008);
    if (-1 < iVar1) {
      FUN_100018c8(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001aa7 at 10001aa7

undefined4 FUN_10001aa7(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1000dca8;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10001ac6 at 10001ac6

undefined4 __thiscall FUN_10001ac6(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1000dcb0 = *param_3;
    DAT_1000dcb4 = param_3[1];
    DAT_1000dcb8 = param_3[2];
    DAT_1000dcbc = param_3[3];
  }
  piVar2 = DAT_1000dd34;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_1000dd34, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_1000dd34 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_1000dd34;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_1000dd38; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10001b24 at 10001b24

void FUN_10001b24(int param_1)

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



// Function: FUN_10001b6a at 10001b6a

void __fastcall FUN_10001b6a(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001b84 at 10001b84

void __fastcall FUN_10001b84(undefined4 *param_1)

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



// Function: FUN_10001bb1 at 10001bb1

void __fastcall FUN_10001bb1(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001bbe at 10001bbe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001bbe(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_100076e0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10001be8 at 10001be8

int __thiscall FUN_10001be8(void *this,undefined4 *param_1)

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



// Function: FUN_10001c1f at 10001c1f

void __fastcall FUN_10001c1f(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10001c29 at 10001c29

void __thiscall FUN_10001c29(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_100011ef(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10001c4e

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_100011ef(lVar1);
  }
  return local_8;
}



// Function: FUN_10001c73 at 10001c73

void FUN_10001c73(void)

{
  return;
}



// Function: DllCanUnloadNow at 10001c74

HRESULT DllCanUnloadNow(void)

{
                    /* 0x1c74  1  DllCanUnloadNow */
  return (uint)(DAT_1000dd04 != 0);
}



// Function: FUN_10001c80 at 10001c80

int __fastcall FUN_10001c80(int param_1)

{
  long lVar1;
  
  FUN_10001486(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1000dcac = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1000dcc0 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10001cc1 at 10001cc1

void __fastcall FUN_10001cc1(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001b24((int)piVar1);
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



// Function: FUN_10001cfa at 10001cfa

void __fastcall FUN_10001cfa(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10001b24((int)piVar1);
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



// Function: FUN_10001cff at 10001cff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001cff(int param_1)

{
  FUN_10001cc1(param_1);
  return;
}



// Function: FUN_10001d22 at 10001d22

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001d22(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 0x2c));
  Ordinal_6(*(undefined4 *)(param_1 + 0x28));
  Ordinal_6(*(undefined4 *)(param_1 + 0x10));
  return;
}



// Function: FUN_10001d5d at 10001d5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001d5d(int param_1)

{
  FUN_10001d22(param_1);
  return;
}



// Function: FUN_10001d7b at 10001d7b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001d7b(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10001d9d at 10001d9d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001d9d(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10001dbf at 10001dbf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001dbf(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001e27 at 10001e27

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001e27(int param_1)

{
  FUN_10001dbf(param_1);
  return;
}



// Function: FUN_10001e45 at 10001e45

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001e45(void *this,undefined4 param_1)

{
  FUN_10006a06((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CHelpInfoComponent>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CHelpInfoComponent>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: AtlComQIPtrAssign at 10001e80

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



// Function: Attach at 10001eb7

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



// Function: FUN_10001eff at 10001eff

void FUN_10001eff(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10001f12 at 10001f12

void FUN_10001f12(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10001f25 at 10001f25

void FUN_10001f25(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10001f3d at 10001f3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001f3d(void *this,byte param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_10001f75 at 10001f75

void FUN_10001f75(int param_1)

{
  FUN_10001f12(param_1 + -4);
  return;
}



// Function: FUN_10001f7f at 10001f7f

void FUN_10001f7f(int param_1)

{
  FUN_10001eff(param_1 + -4);
  return;
}



// Function: FUN_10001f89 at 10001f89

void FUN_10001f89(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10001f25(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10001f96 at 10001f96

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10001f96(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10001f96(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_10006c73();
  return;
}



// Function: FUN_1000207b at 1000207b

undefined4 __fastcall FUN_1000207b(int *param_1)

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
LAB_100020c0:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_100020c0;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10001b84(param_1);
  return 0;
}



// Function: FUN_100020d2 at 100020d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100020d2(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_100016b9(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001b6a(local_14);
  }
  return uVar1;
}



// Function: FUN_10002119 at 10002119

void FUN_10002119(int param_1)

{
  FUN_1000207b((int *)(param_1 + 4));
  return;
}



// Function: FUN_1000212b at 1000212b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000212b(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x1000213a;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10002305;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_100012b7();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10002198;
      FUN_1000125f(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_100022d5;
      }
    }
    else {
LAB_100022d5:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10002198:
  local_8 = 0xffffffff;
  FUN_10001b6a(&local_248);
LAB_10002305:
  FUN_10006c73();
  return;
}



// Function: FUN_1000230d at 1000230d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000230d(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002332 at 10002332

void __fastcall FUN_10002332(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_1000dd34;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_1000dd34, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_1000dd38; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10001cc1(param_1);
  return;
}



// Function: FUN_10002384 at 10002384

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10002384(void *this,wchar_t *param_1)

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
  local_8 = 0x10002390;
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
      local_18 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10001ed6,
                   (_func_void_void_ptr *)&LAB_1000102d);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10002434();
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



// Function: Catch@10002424 at 10002424

undefined * Catch_10002424(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000242e;
}



// Function: FUN_10002434 at 10002434

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002434(void)

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



// Function: FUN_100024ec at 100024ec

void FUN_100024ec(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_1000104e(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10002524 at 10002524

void __fastcall FUN_10002524(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10002534 at 10002534

void __fastcall FUN_10002534(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10001c1f(param_1);
    return;
  }
  return;
}



// Function: FUN_10002541 at 10002541

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002541(int param_1)

{
  FUN_10001bbe((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10002562 at 10002562

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10002562(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_100025b6 at 100025b6

void __fastcall FUN_100025b6(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100025cd at 100025cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_100025cd(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_10009340,&local_18);
    (**(code **)*param_1)(param_1,&DAT_10009340,local_14);
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



// Function: FUN_10002658 at 10002658

undefined4 FUN_10002658(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10001ac6(&DAT_1000dcfc,(int *)&PTR_DAT_1000d000,param_1,(undefined4 *)&DAT_10009408);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10002332(0x1000dcfc);
  }
  return 1;
}



// Function: FUN_1000269a at 1000269a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000269a(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10001406(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: InlineIsEqualUnknown at 100026d5

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



// Function: FUN_10002703 at 10002703

undefined4 FUN_10002703(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10002741 at 10002741

undefined4 FUN_10002741(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1000dcac + 8))();
  }
  else {
    (**(code **)(*DAT_1000dcac + 4))();
  }
  return 0;
}



// Function: FUN_10002760 at 10002760

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10002760(undefined4 *param_1)

{
  FUN_10006a06((int)param_1);
  *param_1 = ATL::CComObject<class_CHelpInfoComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CHelpInfoComponent>::vftable;
  (**(code **)(*DAT_1000dcac + 4))();
  return param_1;
}



// Function: AtlInternalQueryInterface at 100027a0

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
          if (pcVar1 == (code *)0x1) goto LAB_100027d4;
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
LAB_100027d4:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10002841 at 10002841

undefined4 FUN_10002841(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}



// Function: Release at 10002851

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 2;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[2];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x1c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 10002872

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009774,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000288c at 1000288c

void FUN_1000288c(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_10002896 at 10002896

void FUN_10002896(int param_1)

{
  FUN_10002841(param_1 + -4);
  return;
}



// Function: FUN_100028a0 at 100028a0

void FUN_100028a0(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100028aa at 100028aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100028aa(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CHelpInfoComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CHelpInfoComponent>::vftable;
  param_1[2] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  Ordinal_6(param_1[3]);
  return;
}



// Function: FUN_100028f1 at 100028f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_100028f1(undefined4 *param_1)

{
  FUN_10001c80((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_1000dccc = param_1;
  return param_1;
}



// Function: FUN_10002926 at 10002926

void __fastcall FUN_10002926(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10002931 at 10002931

void __fastcall FUN_10002931(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000293c at 1000293c

HRESULT __thiscall FUN_1000293c(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_10009da4,(LPUNKNOWN)0x0,1,(IID *)&DAT_100097f0,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10002988 at 10002988

undefined4 FUN_10002988(void)

{
  return 0x80004005;
}



// Function: FUN_10002990 at 10002990

void FUN_10002990(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10009800);
  return;
}



// Function: FUN_100029aa at 100029aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100029aa(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CHelpInfoComponent>::vftable;
  FUN_10001e45((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1000dcac + 4))();
  return (undefined4 *)this;
}



// Function: Release at 100029ed

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 1;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[1];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0xc))(1);
  }
  return uVar2;
}



// Function: FUN_10002a0e at 10002a0e

long FUN_10002a0e(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009774,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10002a5a at 10002a5a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002a5a(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CHelpInfoComponent>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  Ordinal_6(param_1[5]);
  return;
}



// Function: FUN_10002aa4 at 10002aa4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002aa4(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10001cc1((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002adb at 10002adb

undefined4 * __thiscall FUN_10002adb(void *this,byte param_1)

{
  FUN_100028aa((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002afa at 10002afa

undefined4 * __thiscall FUN_10002afa(void *this,byte param_1)

{
  FUN_10002a5a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002b19 at 10002b19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002b19(int *param_1)

{
  FUN_1000207b(param_1);
  FUN_10001b84(param_1);
  return;
}



// Function: FUN_10002b43 at 10002b43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002b43(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000207b(param_1 + 1);
  FUN_10002b19(param_1 + 1);
  return;
}



// Function: FUN_10002b77 at 10002b77

undefined4 FUN_10002b77(void)

{
  return 1;
}



// Function: FUN_10002b7d at 10002b7d

undefined4 FUN_10002b7d(void)

{
  return 0;
}



// Function: FUN_10002b82 at 10002b82

undefined4 * __thiscall FUN_10002b82(void *this,byte param_1)

{
  FUN_10002b43((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002ba1 at 10002ba1

undefined4 __fastcall FUN_10002ba1(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10001be8((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10002be2 at 10002be2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10002be2(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10002bee;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10001679(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10001aa7(&local_5d);
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
LAB_10002cd7:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10002d4b;
                }
                iVar3 = FUN_10001659((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_100016b9(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_10002d71;
                  goto LAB_10002d13;
                }
                local_55 = '\0';
              }
              else {
LAB_10002d13:
                if (local_55 != '\0') goto LAB_10002d4b;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_100020d2(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_10002d71;
                local_56 = '\0';
              }
              goto LAB_10002d4b;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_100020d2(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10002cd7;
            }
LAB_10002d71:
            local_5c = -0x7ff8fff2;
            goto LAB_10002c52;
          }
LAB_10002d4b:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10001853(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10002c52;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10002ba1(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_100020d2(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_10002d71;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10002de4;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10002c52;
            }
            iVar3 = FUN_100016b9(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_10002d71;
          }
          else {
            iVar3 = FUN_100016b9(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10002de4:
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
LAB_10002c52:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_10006c73();
  return;
}



// Function: FUN_10002e4f at 10002e4f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002e4f(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_10009d94), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_10009db4,(LPUNKNOWN)0x0,1,(IID *)&DAT_10009904,&local_1a8
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
          goto LAB_100030da;
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
      FUN_10001b6a(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_100030da:
  FUN_10006c73();
  return;
}



// Function: FUN_1000316d at 1000316d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000316d(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_1000212b(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10001aa7((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_1000323d at 1000323d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000323d(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_1000212b(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10001aa7(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_100033ff;
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
LAB_100033ff:
  FUN_10006c73();
  return;
}



// Function: FUN_10003407 at 10003407

int FUN_10003407(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10001129(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10002e4f((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_1000323d(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000348d at 1000348d

int FUN_1000348d(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10001129(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10002e4f((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_1000316d(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10003514 at 10003514

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10003514(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_10009340,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_100035cf;
          }
          else {
LAB_100035cf:
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



// Function: FUN_100035ff at 100035ff

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100035ff(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10003644();
  return uVar1;
}



// Function: Catch@10003634 at 10003634

undefined * Catch_10003634(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000363e;
}



// Function: FUN_10003644 at 10003644

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003644(void)

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



// Function: FUN_1000369f at 1000369f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000369f(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001bbe((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_100036d0 at 100036d0

undefined4 * __thiscall FUN_100036d0(void *this,byte param_1)

{
  FUN_1000369f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100036ef at 100036ef

undefined4 __thiscall FUN_100036ef(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10002562(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 10003746

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
    FUN_10001c29(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10003775

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
    FUN_10001c29(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100037a4

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
    FUN_10001c29(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100037d3 at 100037d3

IUnknown * __thiscall FUN_100037d3(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_100025cd(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10009964);
  }
  return pIVar2;
}



// Function: FUN_10003800 at 10003800

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003800(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10003843 at 10003843

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003843(undefined4 *param_1)

{
  FUN_1000269a(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_10003871 at 10003871

LONG FUN_10003871(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1000dcac + 4))();
  }
  return LVar1;
}



// Function: FUN_1000389b at 1000389b

LONG FUN_1000389b(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1000dcac + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 100038da

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009990,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100038f4 at 100038f4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100038f4(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_1000369f(param_1);
  return;
}



// Function: FUN_10003923 at 10003923

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003923(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10002760(puVar1);
    }
    uVar2 = FUN_10003980();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10003973 at 10003973

undefined * Catch_10003973(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000397d;
}



// Function: FUN_10003980 at 10003980

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003980(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[2] = unaff_ESI[2] + 1;
    unaff_ESI[2] = unaff_ESI[2] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x1c))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100039b0 at 100039b0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100039b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x20);
    if (this != (void *)0x0) {
      FUN_100029aa(this,param_1);
    }
    uVar1 = FUN_10003a17();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10003a0a at 10003a0a

undefined * Catch_10003a0a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003a14;
}



// Function: FUN_10003a17 at 10003a17

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003a17(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10003a41 at 10003a41

undefined4 * __thiscall FUN_10003a41(void *this,byte param_1)

{
  FUN_100038f4((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003a60 at 10003a60

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003a60(undefined4 *param_1)

{
  FUN_10003800((int)param_1);
  *param_1 = ATL::CComObject<class_CErrorAndHelpComponent>::vftable;
  (**(code **)(*DAT_1000dcac + 4))();
  return param_1;
}



// Function: Release at 10003a99

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 1;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[1];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x20))(1);
  }
  return uVar2;
}



// Function: FUN_10003aba at 10003aba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003aba(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CErrorAndHelpComponent>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10001dbf((int)param_1);
  return;
}



// Function: QueryInterface at 10003af8

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009350,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10003b12 at 10003b12

undefined4 * __thiscall FUN_10003b12(void *this,byte param_1)

{
  FUN_10003aba((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003b31 at 10003b31

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003b31(void *this,undefined4 param_1)

{
  FUN_10003800((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CErrorAndHelpComponent>::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10003b65 at 10003b65

void FUN_10003b65(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_10003b78 at 10003b78

void FUN_10003b78(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_10003b8b at 10003b8b

void FUN_10003b8b(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_2,param_3);
  return;
}



// Function: FUN_10003ba3 at 10003ba3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003ba3(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10003c09();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10003bfd at 10003bfd

undefined * Catch_10003bfd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003c07;
}



// Function: FUN_10003c09 at 10003c09

void FUN_10003c09(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  void *pvVar4;
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
  pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(void **)(unaff_EBP + -0x20) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10003c5a();
  return;
}



// Function: Catch@10003c4b at 10003c4b

undefined * Catch_10003c4b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10003c58;
}



// Function: FUN_10003c5a at 10003c5a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10003c5a(void)

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
    FUN_1000123f(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_1000123f(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_100036ef(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10003cb6;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10003cb6:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10003cee at 10003cee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003cee(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10003ba3(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001b6a(local_14);
  }
  return iVar1;
}



// Function: FUN_10003d49 at 10003d49

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003d49(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_10007e1e;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1000dc90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_100018c8(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10001747(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100040c2;
  FUN_100018a6((undefined4 *)this);
  iVar1 = FUN_100018c8(this,local_2018);
  if (iVar1 < 0) goto LAB_100040c2;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_1000409e:
    if (uVar2 != 0) {
      FUN_100012cc(uVar2);
      goto LAB_100040c2;
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
        FUN_10003fd1();
        return;
      }
      goto LAB_100040c2;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001b6a((int *)&local_2124);
      goto LAB_1000409e;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10003e6a();
      return;
    }
  }
  FUN_100018c8(this,param_3);
LAB_100040c2:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10003e5e at 10003e5e

undefined * Catch_10003e5e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10003e68;
}



// Function: FUN_10003e6a at 10003e6a

void FUN_10003e6a(void)

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
    pWVar2 = (WCHAR *)FUN_10001616(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10001c1f((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_100018c8(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_100012cc((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100040da;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10003fb6 at 10003fb6

undefined * Catch_10003fb6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10003fc3;
}



// Function: FUN_10003fd1 at 10003fd1

void FUN_10003fd1(void)

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
      FUN_10001c1f((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_100017ef(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10001c1f((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_100018c8(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_100012cc(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100040da;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100040de at 100040de

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100040de(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_10007e7d;
  local_10 = ExceptionList;
  local_14 = DAT_1000dc90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10004142:
  iVar3 = FUN_100018c8(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10004152:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_100045af:
    if (*param_1 == L'}') goto LAB_10004152;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_100018c8(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10004152;
      if (param_3 == 0) goto LAB_10004291;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10001853(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_100019de(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10001f96(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10004291;
        }
        iVar3 = FUN_100018c8(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10001a42(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_100046ae;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_1000472d;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_10004152;
    }
LAB_10004291:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_100018c8(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10004152;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10001853(param_1,L'\\');
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
          iVar3 = FUN_100018c8(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10001a42(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_100040de(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_100018c8(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000474c;
          iVar3 = FUN_100018c8(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10003d49(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_100046b3;
        }
      }
      goto LAB_10004152;
    }
    iVar3 = FUN_100018c8(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_100018c8(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10004152;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10003d49(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_100046ae;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_1000472d;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_100012cc(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_1000472d:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_10004152;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10001a42(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10001a0d(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_100019de(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10001f96(&local_2234,local_21c);
        }
        goto LAB_100045af;
      }
      bVar2 = FUN_10001a0d(local_2234);
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
            FUN_100012cc(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_1000472d;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_100046ae:
          ATL::CRegKey::Close(pCVar8);
LAB_100046b3:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_100040de(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10004142;
            goto LAB_10004152;
          }
        }
        goto LAB_100045af;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_100045af;
    }
LAB_1000474c:
    FUN_100012cc(uVar6);
    goto LAB_10004152;
  }
  goto LAB_100045af;
}



// Function: FUN_10004775 at 10004775

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10004775(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000dd3c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_10009340,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000dd3c);
          if (*piVar2 != 0) goto LAB_10004809;
        }
        else {
LAB_10004809:
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
  piVar2 = FUN_10003514((int *)&DAT_1000dd2c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_10004841 at 10004841

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004841(void *this,undefined4 param_1)

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
  local_8 = 0x10004850;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10004a86;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1000dcac + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_1000dcb0,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_1000dd58,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10004a50;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001b6a((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_100096f0,&local_224);
        if (-1 < iVar2) {
          FUN_100037d3(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1000dcac == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1000dcac + 4;
        }
        pcVar4 = FUN_100024ec;
        pvVar5 = this;
        FUN_100035ff(iVar2);
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
LAB_10004a50:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10002384(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10004a86:
  FUN_10006c73();
  return;
}



// Function: FUN_10004a8e at 10004a8e

void FUN_10004a8e(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10003407(0x1000dd2c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_1000dcc4 != (code *)0x0)) {
    (*DAT_1000dcc4)(DAT_1000dd58);
  }
  return;
}



// Function: FUN_10004abc at 10004abc

void FUN_10004abc(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1000dcc8 != (code *)0x0) && (iVar1 = (*DAT_1000dcc8)(), iVar1 < 0)) {
    return;
  }
  FUN_1000348d(0x1000dd2c,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 10004ae2

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x4ae2  2  DllGetClassObject */
  piVar1 = FUN_10004775(&DAT_1000dcfc,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: Catch@10004b4e at 10004b4e

undefined1 * Catch_10004b4e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10004b58;
}



// Function: FUN_10004ba0 at 10004ba0

void FUN_10004ba0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10003923(0,param_2,param_3);
    return;
  }
  FUN_100039b0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10004bc0 at 10004bc0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004bc0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10003a60(puVar1);
    }
    iVar2 = FUN_10004c21();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10004c11 at 10004c11

undefined * Catch_10004c11(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004c1b;
}



// Function: FUN_10004c21 at 10004c21

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004c21(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
    unaff_EDI = (**(code **)(*unaff_ESI + 0x1c))();
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    unaff_ESI[1] = unaff_ESI[1] + -1;
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x20))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10004c61 at 10004c61

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10004c61(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *param_1 = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  (**(code **)(*DAT_1000dcac + 4))();
  return param_1;
}



// Function: FUN_10004cbb at 10004cbb

undefined4 FUN_10004cbb(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: Release at 10004ccb

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 3;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[3];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x1c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 10004cec

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009a70,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004d06 at 10004d06

void FUN_10004d06(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_10004d10 at 10004d10

void FUN_10004d10(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_10004d1a at 10004d1a

void FUN_10004d1a(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10004d24 at 10004d24

void FUN_10004d24(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10004d2e at 10004d2e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004d2e(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorInfoComponent>::vftable;
  param_1[3] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10001d22((int)param_1);
  return;
}



// Function: FUN_10004d7a at 10004d7a

undefined4 * __thiscall FUN_10004d7a(void *this,byte param_1)

{
  FUN_10004d2e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004d99 at 10004d99

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10004d99(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CErrorAndHelpComponent>::vftable;
  FUN_10003b31((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1000dcac + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10004ddc at 10004ddc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004ddc(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CErrorAndHelpComponent>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10001dbf((int)(param_1 + 2));
  return;
}



// Function: FUN_10004e22 at 10004e22

long FUN_10004e22(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009350,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10004e6e at 10004e6e

undefined4 * __thiscall FUN_10004e6e(void *this,byte param_1)

{
  FUN_10004ddc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004e8d at 10004e8d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10004e8d(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined ***)this = ATL::CComContainedObject<class_CErrorInfoComponent>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CErrorInfoComponent>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CErrorInfoComponent>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  return;
}



// Function: FUN_10004ee0 at 10004ee0

void FUN_10004ee0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_10004ef3 at 10004ef3

void FUN_10004ef3(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_10004f06 at 10004f06

void FUN_10004f06(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))(*(undefined4 **)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_10004f1e at 10004f1e

void FUN_10004f1e(int param_1)

{
  FUN_10004ee0(param_1 + -4);
  return;
}



// Function: FUN_10004f28 at 10004f28

void FUN_10004f28(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004f06(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10004f32 at 10004f32

void FUN_10004f32(int param_1)

{
  FUN_10004ef3(param_1 + -8);
  return;
}



// Function: FUN_10004f3c at 10004f3c

void __cdecl FUN_10004f3c(undefined4 param_1,void *param_2)

{
  FUN_10001f3d(param_2,0);
  return;
}



// Function: FUN_10004f4b at 10004f4b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004f4b(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000dc90 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10002be2(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10005041:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10004f96:
  if ((((sVar1 == 0) || (iVar3 = FUN_100018c8(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10001825(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_100018c8(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10005033;
  if (param_2 == 0) {
    iVar3 = FUN_100040de(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10005033;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100040de(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100040de(this,local_2008,pHVar4,0,0);
LAB_10005033:
      CoTaskMemFree(local_200c);
      goto LAB_10005041;
    }
  }
  FUN_100018a6((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10004f96;
}



// Function: FUN_10005082 at 10005082

int __thiscall FUN_10005082(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10001129(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10002e4f((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10004a8e(param_1,param_2);
  return iVar5;
}



// Function: FUN_100050f1 at 100050f1

int __thiscall FUN_100050f1(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10001129(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10002e4f((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_10004abc(param_1,param_2);
  return iVar5;
}



// Function: FUN_10005160 at 10005160

undefined4 __thiscall FUN_10005160(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10004841(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_100051a0 at 100051a0

undefined4 __thiscall
FUN_100051a0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10004841(this,param_4);
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



// Function: FUN_10005241 at 10005241

void __thiscall
FUN_10005241(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10004841(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: DllRegisterServer at 10005284

void DllRegisterServer(void)

{
                    /* 0x5284  3  DllRegisterServer */
  FUN_10005082(&DAT_1000dcfc,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10005293

void DllUnregisterServer(void)

{
                    /* 0x5293  4  DllUnregisterServer */
  FUN_100050f1(&DAT_1000dcfc,1,(void *)0x0);
  return;
}



// Function: FUN_100052a2 at 100052a2

undefined4 FUN_100052a2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10005160(&PTR_DAT_1000d958,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100052c6 at 100052c6

void FUN_100052c6(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100051a0(&PTR_DAT_1000d958,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100052e6 at 100052e6

void FUN_100052e6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10005241(&PTR_DAT_1000d958,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100052f4 at 100052f4

undefined4 FUN_100052f4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10005160(&PTR_DAT_1000d974,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10005318 at 10005318

void FUN_10005318(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100051a0(&PTR_DAT_1000d974,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10005338 at 10005338

void FUN_10005338(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10005241(&PTR_DAT_1000d974,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10005346 at 10005346

undefined4 FUN_10005346(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10005160(&PTR_DAT_1000d990,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000536a at 1000536a

void FUN_1000536a(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100051a0(&PTR_DAT_1000d990,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000538a at 1000538a

void FUN_1000538a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10005241(&PTR_DAT_1000d990,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10005398 at 10005398

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005398(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10004c61(puVar1);
    }
    uVar2 = FUN_100053f5();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100053e8 at 100053e8

undefined * Catch_100053e8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100053f2;
}



// Function: FUN_100053f5 at 100053f5

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100053f5(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[3] = unaff_ESI[3] + 1;
    unaff_ESI[3] = unaff_ESI[3] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x1c))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10005425 at 10005425

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_10005425(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  uint uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x1c);
    if (this != (void *)0x0) {
      FUN_10004d99(this,param_1);
    }
    uVar1 = FUN_10005493();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10005483 at 10005483

undefined * Catch_10005483(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000548d;
}



// Function: FUN_10005493 at 10005493

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_10005493(void)

{
  uint uVar1;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    uVar1 = (**(code **)(unaff_ESI[2] + 0x1c))(unaff_ESI + 2);
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if ((uVar1 < 0x80000000) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
  return unaff_EDI;
}



// Function: FUN_100054d0 at 100054d0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100054d0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CErrorInfoComponent>::vftable;
  FUN_10004e8d((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1000dcac + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10005513 at 10005513

long FUN_10005513(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009a70,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000555f at 1000555f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000555f(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CErrorInfoComponent>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10001d22((int)(param_1 + 2));
  return;
}



// Function: FUN_100055a5 at 100055a5

undefined4 * __thiscall FUN_100055a5(void *this,byte param_1)

{
  FUN_1000555f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100055c4 at 100055c4

void __cdecl FUN_100055c4(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 4)) {
    FUN_10004f3c(param_3,param_1);
  }
  return;
}



// Function: FUN_100055e3 at 100055e3

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100055e3(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_100012b7();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_100012b7();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_100056bd();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10001c1f(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001b6a(&local_42c);
  FUN_10006c82();
  return;
}



// Function: Catch@100056a8 at 100056a8

undefined * Catch_100056a8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100056b5;
}



// Function: FUN_100056bd at 100056bd

void FUN_100056bd(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_100012b7();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10004f4b((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10001c1f((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001b6a((int *)(unaff_EBP + -0x428));
  FUN_10006c82();
  return;
}



// Function: FUN_10005747 at 10005747

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005747(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_100055e3(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001b6a(local_14);
  return uVar1;
}



// Function: FUN_10005788 at 10005788

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005788(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001b6a(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_100055e3(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001b6a(local_14);
  }
  return uVar1;
}



// Function: FUN_100057e4 at 100057e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100057e4(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_100055e3(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001b6a(local_14);
  return uVar1;
}



// Function: FUN_10005824 at 10005824

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005824(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001b6a(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_100055e3(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001b6a(local_14);
  }
  return uVar1;
}



// Function: FUN_1000587f at 1000587f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000587f(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_10003cee(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_1000dd58;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000dd58,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_100012b7();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001b6a((int *)&local_a48);
        goto LAB_10005901;
      }
      FUN_10001438(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_100011c2(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001b6a((int *)&local_a48);
          goto LAB_10005901;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003cee(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003cee(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10005824(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_10005788(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001b6a((int *)&local_a48);
  }
LAB_10005901:
  local_8 = 0xffffffff;
  FUN_10002b43(&local_a60);
  FUN_10006c73();
  return;
}



// Function: FUN_10005a82 at 10005a82

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10005a82(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_10003cee(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_1000dd58;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000dd58,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_100012b7();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001b6a((int *)&local_a48);
        goto LAB_10005afb;
      }
      FUN_10001438(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_100011c2(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001b6a((int *)&local_a48);
          goto LAB_10005afb;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003cee(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003cee(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100057e4(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10005747(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001b6a((int *)&local_a48);
  }
LAB_10005afb:
  local_8 = 0xffffffff;
  FUN_10002b43(&local_a5c);
  FUN_10006c73();
  return;
}



// Function: FUN_10005c79 at 10005c79

void FUN_10005c79(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10004bc0(0,param_2,param_3);
    return;
  }
  FUN_10005425(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005c99 at 10005c99

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005c99(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x38);
    if (this != (void *)0x0) {
      FUN_100054d0(this,param_1);
    }
    uVar1 = FUN_10005d00();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10005cf3 at 10005cf3

undefined * Catch_10005cf3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005cfd;
}



// Function: FUN_10005d00 at 10005d00

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005d00(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10005d2a at 10005d2a

void FUN_10005d2a(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000587f(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005d33 at 10005d33

void FUN_10005d33(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10005a82(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005d3c at 10005d3c

void FUN_10005d3c(int param_1)

{
  FUN_10005a82((int *)&DAT_1000dcfc,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005d54 at 10005d54

void FUN_10005d54(int param_1)

{
  FUN_10005a82((int *)&DAT_1000dcfc,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005d6c at 10005d6c

void FUN_10005d6c(int param_1)

{
  FUN_10005a82((int *)&DAT_1000dcfc,0x67,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005d84 at 10005d84

void FUN_10005d84(int param_1)

{
  FUN_10005a82((int *)&DAT_1000dcfc,0x68,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005d9c at 10005d9c

void FUN_10005d9c(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10005398(0,param_2,param_3);
    return;
  }
  FUN_10005c99(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005dbc at 10005dbc

void __fastcall FUN_10005dbc(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_100055c4((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10005df1 at 10005df1

void __fastcall FUN_10005df1(int *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_100055c4((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10005df6 at 10005df6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005df6(int param_1)

{
  FUN_10005dbc((undefined4 *)(param_1 + 0x10));
  return;
}



// Function: FUN_10005e17 at 10005e17

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005e17(int param_1)

{
  FUN_10005dbc((undefined4 *)(param_1 + 0x10));
  return;
}



// Function: FUN_10005e38 at 10005e38

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10005e38(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  (**(code **)(*DAT_1000dcac + 4))();
  return param_1;
}



// Function: FUN_10005e8b at 10005e8b

undefined4 FUN_10005e8b(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: QueryInterface at 10005ea8

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009bf8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10005ec2 at 10005ec2

void FUN_10005ec2(int param_1)

{
  FUN_10004cbb(param_1 + -4);
  return;
}



// Function: FUN_10005ecc at 10005ecc

void FUN_10005ecc(int param_1)

{
  FUN_10004cbb(param_1 + -8);
  return;
}



// Function: FUN_10005ed6 at 10005ed6

void FUN_10005ed6(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10005ee0 at 10005ee0

void FUN_10005ee0(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10005eea at 10005eea

undefined4 FUN_10005eea(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10005160(&PTR_DAT_1000dba0,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10005f0e at 10005f0e

void FUN_10005f0e(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100051a0(&PTR_DAT_1000dba0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10005f2e at 10005f2e

void FUN_10005f2e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10005241(&PTR_DAT_1000dba0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10005f3c at 10005f3c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005f3c(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorRecordComponent>::vftable;
  param_1[3] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10005dbc(param_1 + 4);
  return;
}



// Function: FUN_10005f89 at 10005f89

undefined4 * __thiscall FUN_10005f89(void *this,byte param_1)

{
  FUN_10005f3c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005fa8 at 10005fa8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10005fa8(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined ***)this = ATL::CComContainedObject<class_CErrorRecordComponent>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CErrorRecordComponent>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CErrorRecordComponent>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  return;
}



// Function: FUN_10005ff4 at 10005ff4

void FUN_10005ff4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004f06(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10005ffe at 10005ffe

void FUN_10005ffe(int param_1)

{
  FUN_10004ef3(param_1 + -4);
  return;
}



// Function: FUN_10006008 at 10006008

void FUN_10006008(int param_1)

{
  FUN_10004ee0(param_1 + -8);
  return;
}



// Function: FUN_10006012 at 10006012

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006012(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x20);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005e38(puVar1);
    }
    uVar2 = FUN_1000606f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006062 at 10006062

undefined * Catch_10006062(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000606c;
}



// Function: FUN_1000606f at 1000606f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000606f(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[3] = unaff_ESI[3] + 1;
    unaff_ESI[3] = unaff_ESI[3] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x1c))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000609f at 1000609f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000609f(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CErrorRecordComponent>::vftable;
  FUN_10005fa8((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1000dcac + 4))();
  return (undefined4 *)this;
}



// Function: FUN_100060e2 at 100060e2

undefined4 FUN_100060e2(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_100060f2 at 100060f2

long FUN_100060f2(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10009bf8,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000613e at 1000613e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000613e(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CErrorRecordComponent>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000dcac + 8))();
  FUN_10005dbc(param_1 + 6);
  return;
}



// Function: FUN_10006187 at 10006187

undefined4 * __thiscall FUN_10006187(void *this,byte param_1)

{
  FUN_1000613e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100061a6 at 100061a6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100061a6(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x28);
    if (this != (void *)0x0) {
      FUN_1000609f(this,param_1);
    }
    uVar1 = FUN_1000620d();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10006200 at 10006200

undefined * Catch_10006200(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000620a;
}



// Function: FUN_1000620d at 1000620d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000620d(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10006237 at 10006237

void FUN_10006237(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10006012(0,param_2,param_3);
    return;
  }
  FUN_100061a6(param_1,param_2,param_3);
  return;
}



// Function: FUN_10006257 at 10006257

undefined4 FUN_10006257(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x10),0x10);
  return 0;
}



// Function: FUN_10006274 at 10006274

undefined4 FUN_10006274(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x20);
  return 0;
}



// Function: FUN_10006288 at 10006288

undefined4 FUN_10006288(int param_1,void *param_2)

{
  memcpy((void *)(param_1 + 0xc),param_2,0x10);
  return 0;
}



// Function: FUN_100062a5 at 100062a5

undefined4 FUN_100062a5(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return 0;
}



// Function: FUN_100062b7 at 100062b7

int * __thiscall FUN_100062b7(void *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
    Ordinal_6(*this);
    if (param_1 != 0) {
      iVar1 = Ordinal_2(param_1);
      *(int *)this = iVar1;
      if (iVar1 != 0) {
        return (int *)this;
      }
      FUN_100011ef(0x8007000e);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: FUN_100062f4 at 100062f4

void __fastcall FUN_100062f4(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_10006311 at 10006311

undefined4 FUN_10006311(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_100062f4((int *)(param_1 + 0xc));
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_1000632a at 1000632a

undefined4 FUN_1000632a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_100062f4((int *)(param_1 + 0x24));
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_10006343 at 10006343

undefined4 FUN_10006343(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_100062f4((int *)(param_1 + 0x28));
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_1000635c at 1000635c

undefined4 FUN_1000635c(int param_1,int param_2)

{
  FUN_100062b7((void *)(param_1 + 0x24),param_2);
  return 0;
}



// Function: FUN_10006373 at 10006373

undefined4 FUN_10006373(int param_1,int param_2)

{
  FUN_100062b7((void *)(param_1 + 8),param_2);
  return 0;
}



// Function: FUN_1000638a at 1000638a

undefined4 FUN_1000638a(int param_1,int param_2)

{
  FUN_100062b7((void *)(param_1 + 0x20),param_2);
  return 0;
}



// Function: FUN_100063c6 at 100063c6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_100063c6(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_100063fe at 100063fe

undefined4 FUN_100063fe(void)

{
  return 0x80004001;
}



// Function: FUN_10006406 at 10006406

undefined4 FUN_10006406(void)

{
  return 0x80004001;
}



// Function: FUN_1000640e at 1000640e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000640e(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000641a;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x40000000) &&
     (pvVar1 = operator_new((int)param_1 << 2), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1000c148);
}



// Function: FUN_100064a1 at 100064a1

undefined4 FUN_100064a1(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0xc) + param_2 * 4);
  (**(code **)*puVar1)(puVar1,&DAT_10009d74,param_4);
  return 0;
}



// Function: FUN_100064c5 at 100064c5

undefined4 FUN_100064c5(int param_1,int *param_2)

{
  *param_2 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2) + -1;
  return 0;
}



// Function: FUN_100064e0 at 100064e0

uint __thiscall FUN_100064e0(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 8) - *this >> 2;
  if (0x3fffffff - (uVar1 >> 1) < uVar1) {
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



// Function: FUN_1000650c at 1000650c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000650c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  puVar1 = *(undefined4 **)
            (*(int *)(param_1 + 8) + -4 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2) * 4
            );
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10009d74,local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14[0] + 0x14))(local_14[0],param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_10006575 at 10006575

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10006575(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  puVar1 = *(undefined4 **)
            (*(int *)(param_1 + 8) + -4 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2) * 4
            );
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10009d74,local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14[0] + 0xc))(local_14[0],param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_100065de at 100065de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100065de(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  puVar1 = *(undefined4 **)
            (*(int *)(param_1 + 8) + -4 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2) * 4
            );
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10009d74,local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_10006647 at 10006647

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10006647(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  puVar1 = *(undefined4 **)
            (*(int *)(param_1 + 8) + -4 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2) * 4
            );
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10009d74,local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14[0] + 0x18))(local_14[0],param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_100066b0 at 100066b0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100066b0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  puVar1 = *(undefined4 **)
            (*(int *)(param_1 + 8) + -4 + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2) * 4
            );
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10009d74,local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14[0] + 0x10))(local_14[0],param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_10006719 at 10006719

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10006719(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    *param_1 = *param_2;
    *param_2 = 0;
  }
  return;
}



// Function: FUN_10006752 at 10006752

void __cdecl FUN_10006752(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_10006719(param_2,param_3);
  return;
}



// Function: FUN_10006765 at 10006765

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl
FUN_10006765(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    FUN_10006752(param_4,param_3,param_1);
    param_3 = param_3 + 1;
  }
  return param_3;
}



// Function: Catch@100067a9 at 100067a9

void Catch_100067a9(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 4)) {
    FUN_10004f3c(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: _Uninitialized_move<> at 100067cb

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > *,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   &)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &)
   
   Library: Visual Studio 2012 Release */

void __cdecl
_Uninitialized_move<>
          (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  FUN_10006765(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100067ea at 100067ea

void __thiscall FUN_100067ea(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10006806 at 10006806

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10006806(void *this,char *param_1)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  if ((char *)0x3fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)(*(int *)((int)this + 8) - *this >> 2) < param_1) {
    puVar3 = (undefined4 *)FUN_1000640e(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_100067ea(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    pvVar1 = *(void **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    if (pvVar2 != (void *)0x0) {
      FUN_100055c4(pvVar2,pvVar1,(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(undefined4 **)((int)this + 8) = puVar3 + (int)param_1;
    *(undefined4 **)((int)this + 4) = puVar3 + ((int)pvVar1 - (int)pvVar2 >> 2);
    *(undefined4 **)this = puVar3;
  }
  return;
}



// Function: Catch@1000689c at 1000689c

void Catch_1000689c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100068af at 100068af

void __thiscall FUN_100068af(void *this,int param_1)

{
  uint uVar1;
  uint extraout_EAX;
  char *pcVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = *(int *)((int)this + 4) - iVar3 >> 2;
  if (0x3fffffffU - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    uVar1 = extraout_EAX;
    iVar3 = extraout_ECX;
  }
  if ((uint)(*(int *)((int)this + 8) - iVar3 >> 2) < uVar1 + param_1) {
    pcVar2 = (char *)FUN_100064e0(this,uVar1 + param_1);
    FUN_10006806(this,pcVar2);
  }
  return;
}



// Function: FUN_100068fa at 100068fa

void __thiscall FUN_100068fa(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_100068af(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)(*this + ((int)param_1 - (int)puVar2 >> 2) * 4);
  }
  else if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_100068af(this,1);
  }
  FUN_10006752((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}



// Function: FUN_10006954 at 10006954

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_10006954(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *in_stack_00000014;
  undefined4 auStack_28 [2];
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x10006960;
  puVar3 = (undefined4 *)auStack_20;
  if (in_stack_00000014 != (int *)0x0) {
    puVar3 = auStack_28;
    auStack_28[0] = 0x10006970;
    (**(code **)(*in_stack_00000014 + 4))();
  }
  local_8 = 1;
  *(int ***)((int)puVar3 + -4) = &stack0x00000014;
  *(undefined4 *)((int)puVar3 + -8) = 0x10006986;
  FUN_100068fa((void *)(param_1 + 0xc),*(undefined4 **)((int)puVar3 + -4));
  local_8 = 0xffffffff;
  if (in_stack_00000014 != (int *)0x0) {
    iVar1 = *in_stack_00000014;
    *(int **)((int)puVar3 + -4) = in_stack_00000014;
    pcVar2 = *(code **)(iVar1 + 8);
    puVar4 = (undefined4 *)((int)puVar3 + -8);
    puVar3 = (undefined4 *)((int)puVar3 + -8);
    *puVar4 = 0x10006997;
    (*pcVar2)();
  }
  *(undefined4 *)((int)puVar3 + -4) = 0x1000699e;
  return 0;
}



// Function: FUN_100069a1 at 100069a1

undefined4 FUN_100069a1(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return 0;
}



// Function: FUN_100069b5 at 100069b5

undefined4 FUN_100069b5(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return 0;
}



// Function: FUN_100069c7 at 100069c7

undefined4 FUN_100069c7(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  return 0;
}



// Function: FUN_100069db at 100069db

undefined4 FUN_100069db(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return 0;
}



// Function: FUN_100069ed at 100069ed

undefined4 FUN_100069ed(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_100062f4((int *)(param_1 + 8));
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_10006a06 at 10006a06

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006a06(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



// Function: FUN_10006a32 at 10006a32

void __fastcall FUN_10006a32(int *param_1)

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



// Function: FUN_10006a76 at 10006a76

int __fastcall FUN_10006a76(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10006a8f at 10006a8f

undefined4 * __fastcall FUN_10006a8f(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10006a76((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1000c418;
  param_1[3] = &DAT_1000c418;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1000dcc0 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10006ad0 at 10006ad0

void __fastcall FUN_10006ad0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10006aef at 10006aef

int __fastcall FUN_10006aef(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10006b14 at 10006b14

void __fastcall FUN_10006b14(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10006ad0((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10006b2c at 10006b2c

undefined4 * __fastcall FUN_10006b2c(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10006aef((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10009de4;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1000dcc0 = 1;
  }
  return param_1;
}



// Function: __security_check_cookie at 10006b78

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1000dc90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 10006b87

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000dc90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10006bba

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000dc90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10006bf0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000dc90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10006c26

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000dc90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 10006c5f

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



// Function: FUN_10006c73 at 10006c73

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10006c73(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_10006c82 at 10006c82

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10006c82(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __ArrayUnwind at 10006c98

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



// Function: `eh_vector_destructor_iterator' at 10006cf6

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
  FUN_10006d41();
  return;
}



// Function: FUN_10006d41 at 10006d41

void FUN_10006d41(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10006d6c

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



// Function: __alloca_probe at 10006dc0

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



// Function: `eh_vector_constructor_iterator' at 10006deb

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
  FUN_10006e38();
  return;
}



// Function: FUN_10006e38 at 10006e38

void FUN_10006e38(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 10006e62

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
  
  local_8 = &DAT_1000c3b0;
  uStack_c = 0x10006e6e;
  local_20[0] = DecodePointer(DAT_1000e0cc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1000e0cc);
    local_24 = DecodePointer(DAT_1000e0c8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1000e0cc = EncodePointer(local_20[0]);
    DAT_1000e0c8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10006efa();
  }
  return p_Var1;
}



// Function: FUN_10006efa at 10006efa

void FUN_10006efa(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10006f03

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 10006f7a

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
    if (DAT_1000dd8c < 1) {
      return 0;
    }
    DAT_1000dd8c = DAT_1000dd8c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000e0c0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000e0bc == 2) {
      param_2 = (int *)DecodePointer(DAT_1000e0cc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1000e0c8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1000e0cc);
            piVar8 = (int *)DecodePointer(DAT_1000e0c8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1000e0c8 = (PVOID)encoded_null();
        DAT_1000e0cc = DAT_1000e0c8;
      }
      DAT_1000e0bc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1000e0c0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000e0c0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000e0bc == 0) {
      DAT_1000e0bc = 1;
      iVar5 = initterm_e(&DAT_100091b4,&DAT_100091bc);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100091a0,&DAT_100091b0);
      DAT_1000e0bc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1000e0c0,0);
    }
    if ((DAT_1000e0c4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1000e0c4), BVar2 != 0)) {
      (*DAT_1000e0c4)(param_1,2,param_3);
    }
    DAT_1000dd8c = DAT_1000dd8c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10007184

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10007224) */
/* WARNING: Removing unreachable block (ram,0x100071d1) */
/* WARNING: Removing unreachable block (ram,0x10007251) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1000dca0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1000dd8c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10002658(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10002658(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000728f();
  return local_20;
}



// Function: FUN_1000728f at 1000728f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000728f(void)

{
  _DAT_1000dca0 = 0xffffffff;
  return;
}



// Function: entry at 1000729a

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 100072bd

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
  
  _DAT_1000dea8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1000deac = &stack0x00000004;
  _DAT_1000dde8 = 0x10001;
  _DAT_1000dd90 = 0xc0000409;
  _DAT_1000dd94 = 1;
  local_32c = DAT_1000dc90;
  local_328 = DAT_1000dc94;
  _DAT_1000dd9c = unaff_retaddr;
  _DAT_1000de74 = in_GS;
  _DAT_1000de78 = in_FS;
  _DAT_1000de7c = in_ES;
  _DAT_1000de80 = in_DS;
  _DAT_1000de84 = unaff_EDI;
  _DAT_1000de88 = unaff_ESI;
  _DAT_1000de8c = unaff_EBX;
  _DAT_1000de90 = in_EDX;
  _DAT_1000de94 = in_ECX;
  _DAT_1000de98 = in_EAX;
  _DAT_1000de9c = unaff_EBP;
  DAT_1000dea0 = unaff_retaddr;
  _DAT_1000dea4 = in_CS;
  _DAT_1000deb0 = in_SS;
  DAT_1000dde0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10009e00);
  if (DAT_1000dde0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 100073d0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000dc90 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10007415

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



// Function: FUN_10007429 at 10007429

void __cdecl
FUN_10007429(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1000dc90,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 100074c0

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



// Function: __FindPESection at 10007500

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



// Function: __IsNonwritableInCurrentImage at 10007550

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
  
  pcStack_10 = FUN_10007429;
  local_14 = ExceptionList;
  local_c = DAT_1000dc90 ^ 0x1000c3f8;
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



// Function: ___security_init_cookie at 10007624

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
  if ((DAT_1000dc90 == 0xbb40e64e) || ((DAT_1000dc90 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1000dc90 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1000dc90 == 0xbb40e64e) {
      DAT_1000dc90 = 0xbb40e64f;
    }
    else if ((DAT_1000dc90 & 0xffff0000) == 0) {
      DAT_1000dc90 = DAT_1000dc90 | (DAT_1000dc90 | 0x4711) << 0x10;
    }
    DAT_1000dc94 = ~DAT_1000dc90;
  }
  else {
    DAT_1000dc94 = ~DAT_1000dc90;
  }
  return;
}



// Function: Unwind@100076d8 at 100076d8

void Unwind_100076d8(void)

{
  int unaff_EBP;
  
  FUN_100012a5(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100076fb at 100076fb

void Unwind_100076fb(void)

{
  DAT_1000dcf8 = DAT_1000dcf8 & 0xfffffffe;
  return;
}



// Function: Unwind@10007724 at 10007724

void Unwind_10007724(void)

{
  int unaff_EBP;
  
  FUN_10001cfa(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007747 at 10007747

void Unwind_10007747(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10007752 at 10007752

void Unwind_10007752(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1000775d at 1000775d

void Unwind_1000775d(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10007783 at 10007783

void Unwind_10007783(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100077a9 at 100077a9

void Unwind_100077a9(void)

{
  int unaff_EBP;
  
  FUN_10001d7b(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100077b1 at 100077b1

void Unwind_100077b1(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100077d7 at 100077d7

void Unwind_100077d7(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100077e2 at 100077e2

void Unwind_100077e2(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100077ed at 100077ed

void Unwind_100077ed(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100077f8 at 100077f8

void Unwind_100077f8(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007800 at 10007800

void Unwind_10007800(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007808 at 10007808

void Unwind_10007808(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000782b at 1000782b

void Unwind_1000782b(void)

{
  int unaff_EBP;
  
  FUN_10001dbf(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000784e at 1000784e

void Unwind_1000784e(void)

{
  int unaff_EBP;
  
  FUN_10001d7b(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007871 at 10007871

void Unwind_10007871(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007894 at 10007894

void Unwind_10007894(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100078b7 at 100078b7

void Unwind_100078b7(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100078ea at 100078ea

void Unwind_100078ea(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1000791d at 1000791d

void Unwind_1000791d(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007927 at 10007927

void Unwind_10007927(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000794a at 1000794a

void Unwind_1000794a(void)

{
  int unaff_EBP;
  
  FUN_10001bbe((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007970 at 10007970

void Unwind_10007970(void)

{
  FUN_10001c73();
  return;
}



// Function: Unwind@10007987 at 10007987

void Unwind_10007987(void)

{
  FUN_10001c73();
  return;
}



// Function: Unwind@100079ba at 100079ba

void Unwind_100079ba(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100079c2 at 100079c2

void Unwind_100079c2(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100079ca at 100079ca

void Unwind_100079ca(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100079d2 at 100079d2

void Unwind_100079d2(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100079da at 100079da

void Unwind_100079da(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100079e2 at 100079e2

void Unwind_100079e2(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007a05 at 10007a05

void Unwind_10007a05(void)

{
  int unaff_EBP;
  
  FUN_10001bbe((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10007a10 at 10007a10

void Unwind_10007a10(void)

{
  int unaff_EBP;
  
  FUN_10002541(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10007a36 at 10007a36

void Unwind_10007a36(void)

{
  int unaff_EBP;
  
  FUN_10001cfa(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007a3e at 10007a3e

void Unwind_10007a3e(void)

{
  int unaff_EBP;
  
  FUN_10001cff(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007a61 at 10007a61

void Unwind_10007a61(void)

{
  int unaff_EBP;
  
  FUN_10001d9d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10007a87 at 10007a87

void Unwind_10007a87(void)

{
  int unaff_EBP;
  
  FUN_10001d9d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10007a92 at 10007a92

void Unwind_10007a92(void)

{
  int unaff_EBP;
  
  FUN_10001d7b(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007a9a at 10007a9a

void Unwind_10007a9a(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10007ac0 at 10007ac0

void Unwind_10007ac0(void)

{
  int unaff_EBP;
  
  FUN_10001cff(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007ac8 at 10007ac8

void Unwind_10007ac8(void)

{
  int unaff_EBP;
  
  FUN_10001cfa(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007aeb at 10007aeb

void Unwind_10007aeb(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001b84(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007b0e at 10007b0e

void Unwind_10007b0e(void)

{
  int unaff_EBP;
  
  FUN_10002b19((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007b34 at 10007b34

void Unwind_10007b34(void)

{
  int unaff_EBP;
  
  FUN_100016af(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10007b61 at 10007b61

void Unwind_10007b61(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007b6c at 10007b6c

void Unwind_10007b6c(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007b77 at 10007b77

void Unwind_10007b77(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007b82 at 10007b82

void Unwind_10007b82(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007b8d at 10007b8d

void Unwind_10007b8d(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007b98 at 10007b98

void Unwind_10007b98(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@10007ba3 at 10007ba3

void Unwind_10007ba3(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10007bae at 10007bae

void Unwind_10007bae(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10007bb9 at 10007bb9

void Unwind_10007bb9(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007bc4 at 10007bc4

void Unwind_10007bc4(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10007bf7 at 10007bf7

void Unwind_10007bf7(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007bff at 10007bff

void Unwind_10007bff(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007c07 at 10007c07

void Unwind_10007c07(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007c0f at 10007c0f

void Unwind_10007c0f(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007c17 at 10007c17

void Unwind_10007c17(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007c3a at 10007c3a

void Unwind_10007c3a(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007c45 at 10007c45

void Unwind_10007c45(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007c50 at 10007c50

void Unwind_10007c50(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007c5b at 10007c5b

void Unwind_10007c5b(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007c66 at 10007c66

void Unwind_10007c66(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007c71 at 10007c71

void Unwind_10007c71(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007ca4 at 10007ca4

void Unwind_10007ca4(void)

{
  int unaff_EBP;
  
  FUN_100025b6((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007cc7 at 10007cc7

void Unwind_10007cc7(void)

{
  int unaff_EBP;
  
  FUN_100025b6((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007cea at 10007cea

void Unwind_10007cea(void)

{
  int unaff_EBP;
  
  FUN_10002541(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10007cf5 at 10007cf5

void Unwind_10007cf5(void)

{
  int unaff_EBP;
  
  FUN_10001bbe((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10007d1b at 10007d1b

void Unwind_10007d1b(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007d23 at 10007d23

void Unwind_10007d23(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10007d2e at 10007d2e

void Unwind_10007d2e(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007d36 at 10007d36

void Unwind_10007d36(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10007d41 at 10007d41

void Unwind_10007d41(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10007d49 at 10007d49

void Unwind_10007d49(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10007d6f at 10007d6f

void Unwind_10007d6f(void)

{
  int unaff_EBP;
  
  FUN_1000369f(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007dad at 10007dad

void Unwind_10007dad(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007dd2 at 10007dd2

void Unwind_10007dd2(void)

{
  int unaff_EBP;
  
  FUN_10002524((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007dda at 10007dda

void Unwind_10007dda(void)

{
  int unaff_EBP;
  
  FUN_10002524((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10007dfd at 10007dfd

void Unwind_10007dfd(void)

{
  int unaff_EBP;
  
  FUN_10002534((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10007e08 at 10007e08

void Unwind_10007e08(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10007e13 at 10007e13

void Unwind_10007e13(void)

{
  int unaff_EBP;
  
  FUN_10002534((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10007e46 at 10007e46

void Unwind_10007e46(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@10007e51 at 10007e51

void Unwind_10007e51(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@10007e5c at 10007e5c

void Unwind_10007e5c(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10007e67 at 10007e67

void Unwind_10007e67(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@10007e72 at 10007e72

void Unwind_10007e72(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10007ea5 at 10007ea5

void Unwind_10007ea5(void)

{
  int unaff_EBP;
  
  FUN_100025b6((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10007ec8 at 10007ec8

void Unwind_10007ec8(void)

{
  int unaff_EBP;
  
  FUN_100025b6((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@10007ed3 at 10007ed3

void Unwind_10007ed3(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007ede at 10007ede

void Unwind_10007ede(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007ee9 at 10007ee9

void Unwind_10007ee9(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007ef4 at 10007ef4

void Unwind_10007ef4(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007eff at 10007eff

void Unwind_10007eff(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007f0a at 10007f0a

void Unwind_10007f0a(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007f15 at 10007f15

void Unwind_10007f15(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007f20 at 10007f20

void Unwind_10007f20(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10007f2b at 10007f2b

void Unwind_10007f2b(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10007f36 at 10007f36

void Unwind_10007f36(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10007f69 at 10007f69

void Unwind_10007f69(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10007fa9 at 10007fa9

void Unwind_10007fa9(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10007fb4 at 10007fb4

void Unwind_10007fb4(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10007fbf at 10007fbf

void Unwind_10007fbf(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10007fca at 10007fca

void Unwind_10007fca(void)

{
  int unaff_EBP;
  
  FUN_10001d22(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10007fed at 10007fed

void Unwind_10007fed(void)

{
  int unaff_EBP;
  
  FUN_10001d22(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008010 at 10008010

void Unwind_10008010(void)

{
  int unaff_EBP;
  
  FUN_10001e27(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10008036 at 10008036

void Unwind_10008036(void)

{
  int unaff_EBP;
  
  FUN_10001e27(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10008041 at 10008041

void Unwind_10008041(void)

{
  int unaff_EBP;
  
  FUN_10001dbf(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000807f at 1000807f

void Unwind_1000807f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100080a4 at 100080a4

void Unwind_100080a4(void)

{
  int unaff_EBP;
  
  FUN_10001d5d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100080ca at 100080ca

void Unwind_100080ca(void)

{
  int unaff_EBP;
  
  FUN_10001d5d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100080d5 at 100080d5

void Unwind_100080d5(void)

{
  int unaff_EBP;
  
  FUN_10001d22(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100080f8 at 100080f8

void Unwind_100080f8(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@10008103 at 10008103

void Unwind_10008103(void)

{
  int unaff_EBP;
  
  FUN_10002534((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10008136 at 10008136

void Unwind_10008136(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008159 at 10008159

void Unwind_10008159(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001b84(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008164 at 10008164

void Unwind_10008164(void)

{
  int unaff_EBP;
  
  FUN_10002b19((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000816f at 1000816f

void Unwind_1000816f(void)

{
  int unaff_EBP;
  
  FUN_10002b43((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000817a at 1000817a

void Unwind_1000817a(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100081ad at 100081ad

void Unwind_100081ad(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001b84(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100081b8 at 100081b8

void Unwind_100081b8(void)

{
  int unaff_EBP;
  
  FUN_10002b19((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@100081c3 at 100081c3

void Unwind_100081c3(void)

{
  int unaff_EBP;
  
  FUN_10002b43((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@100081ce at 100081ce

void Unwind_100081ce(void)

{
  int unaff_EBP;
  
  FUN_10001b6a((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008201 at 10008201

void Unwind_10008201(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10008226 at 10008226

void Unwind_10008226(void)

{
  int unaff_EBP;
  
  FUN_10005df1((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000824c at 1000824c

void Unwind_1000824c(void)

{
  int unaff_EBP;
  
  FUN_10005df6(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008254 at 10008254

void Unwind_10008254(void)

{
  int unaff_EBP;
  
  FUN_10005df1((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000827a at 1000827a

void Unwind_1000827a(void)

{
  int unaff_EBP;
  
  FUN_10005df1((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10008285 at 10008285

void Unwind_10008285(void)

{
  int unaff_EBP;
  
  FUN_10005df6(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100082c3 at 100082c3

void Unwind_100082c3(void)

{
  int unaff_EBP;
  
  FUN_10005e17(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100082e9 at 100082e9

void Unwind_100082e9(void)

{
  int unaff_EBP;
  
  FUN_10005e17(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100082f4 at 100082f4

void Unwind_100082f4(void)

{
  int unaff_EBP;
  
  FUN_10005df6(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100082fc at 100082fc

void Unwind_100082fc(void)

{
  int unaff_EBP;
  
  FUN_10005df1((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10008322 at 10008322

void Unwind_10008322(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10008347 at 10008347

void Unwind_10008347(void)

{
  FUN_10001cff(0x1000dcfc);
  return;
}



// Function: Unwind@10008351 at 10008351

void Unwind_10008351(void)

{
  FUN_10001cfa(0x1000dcfc);
  return;
}



// Function: Unwind@10008376 at 10008376

void Unwind_10008376(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10008379. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000839a at 1000839a

void Unwind_1000839a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000839d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100083be at 100083be

void Unwind_100083be(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100083c6 at 100083c6

void Unwind_100083c6(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100083ce at 100083ce

void Unwind_100083ce(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100083f1 at 100083f1

void Unwind_100083f1(void)

{
  FUN_10001c73();
  return;
}



// Function: Unwind@100083ff at 100083ff

void Unwind_100083ff(void)

{
  int unaff_EBP;
  
  FUN_10001bb1(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008458 at 10008458

void Unwind_10008458(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@10008460 at 10008460

void Unwind_10008460(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@10008468 at 10008468

void Unwind_10008468(void)

{
  int unaff_EBP;
  
  FUN_10001bb1((int *)(unaff_EBP + 0x18));
  return;
}



// Function: FUN_100084cd at 100084cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100084cd(void)

{
  _DAT_1000dcfc = ATL::CComModule::vftable;
  FUN_10001cc1(0x1000dcfc);
  return;
}



// Function: FUN_100084f7 at 100084f7

void FUN_100084f7(void)

{
  FUN_10006a32((int *)&DAT_1000dd2c);
  return;
}



// Function: FUN_10008501 at 10008501

void FUN_10008501(void)

{
  FUN_10006b14(0x1000dd54);
  return;
}



